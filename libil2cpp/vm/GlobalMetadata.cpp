#include "GlobalMetadata.h"

#include "il2cpp-config.h"


#include <map>
#include <limits>
#include <il2cpp-runtime-metadata.h>
#include "il2cpp-class-internals.h"
#include "il2cpp-tabledefs.h"
#include "il2cpp-runtime-stats.h"
#include "gc/GarbageCollector.h"
#include "metadata/ArrayMetadata.h"
#include "metadata/CustomAttributeDataReader.h"
#include "metadata/CustomAttributeCreator.h"
#include "metadata/GenericMetadata.h"
#include "metadata/GenericMethod.h"
#include "metadata/Il2CppTypeCompare.h"
#include "metadata/Il2CppTypeHash.h"
#include "metadata/Il2CppGenericContextCompare.h"
#include "metadata/Il2CppGenericContextHash.h"
#include "metadata/Il2CppGenericInstCompare.h"
#include "metadata/Il2CppGenericInstHash.h"
#include "metadata/Il2CppGenericMethodCompare.h"
#include "metadata/Il2CppGenericMethodHash.h"
#include "metadata/Il2CppSignature.h"
#include "os/Atomic.h"
#include "os/Mutex.h"
#include "utils/CallOnce.h"
#include "utils/Collections.h"
#include "utils/HashUtils.h"
#include "utils/Il2CppHashMap.h"
#include "utils/Il2CppHashSet.h"
#include "utils/InitOnce.h"
#include "utils/Memory.h"
#include "utils/MemoryRead.h"
#include "utils/StringUtils.h"
#include "utils/PathUtils.h"
#include "vm/Assembly.h"
#include "vm/Class.h"
#include "vm/ClassInlines.h"
#include "vm/GenericClass.h"
#include "vm/MetadataAlloc.h"
#include "vm/MetadataLoader.h"
#include "vm/MetadataLock.h"
#include "vm/Exception.h"
#include "vm/Method.h"
#include "vm/Object.h"
#include "vm/String.h"
#include "vm/Type.h"
#include "vm-utils/MethodDefinitionKey.h"
#include "vm-utils/NativeSymbol.h"
#include "vm-utils/VmStringUtils.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"

#include "GlobalMetadataFileInternals.h"
#include "MetadataDeserialization.h"

typedef struct Il2CppImageGlobalMetadata
{
    TypeDefinitionIndex typeStart;
    TypeDefinitionIndex exportedTypeStart;
    CustomAttributeIndex customAttributeStart;
    MethodIndex entryPointIndex;
    const Il2CppImage* image;
} Il2CppImageGlobalMetadata;

static int32_t s_MetadataImagesCount = 0;
static Il2CppImageGlobalMetadata* s_MetadataImagesTable = NULL;
static SerializedIndexSizes s_SerializedIndexSizes;

static TypeDefinitionIndex GetIndexForTypeDefinitionInternal(const Il2CppMetadataTypeHandle typeHandle);
static Il2CppClass* GetTypeInfoFromTypeDefinitionIndex(TypeDefinitionIndex index);
static Il2CppClass* FromTypeDefinition(TypeDefinitionIndex index);
static GenericParameterIndex GetIndexForGenericParameter(Il2CppMetadataGenericParameterHandle handle);
static Il2CppMetadataGenericParameterHandle GetGenericParameterFromIndexInternal(GenericParameterIndex index);
static Il2CppMetadataGenericContainerHandle GetGenericContainerFromIndex(GenericContainerIndex index);
static Il2CppMetadataTypeHandle GetTypeHandle(TypeDefinitionIndex index);
static const Il2CppImage* GetImageForTypeDefinitionIndex(TypeDefinitionIndex index);

static void* s_GlobalMetadata;
static const Il2CppGlobalMetadataHeader* s_GlobalMetadataHeader;

static const MethodInfo** s_MethodInfoDefinitionTable = NULL;

static Il2CppString** s_StringLiteralTable = NULL;

static il2cpp::utils::OnceFlag s_CustomAttributesOnceFlag;
static int s_CustomAttributesCount;

static const Il2CppCodeRegistration * s_GlobalMetadata_CodeRegistration;
static const Il2CppMetadataRegistration * s_Il2CppMetadataRegistration;

static Il2CppClass** s_TypeInfoTable = NULL;
static Il2CppClass** s_TypeInfoDefinitionTable = NULL;

static const int kBitIsValueType = 1;
static const int kBitIsEnum = 2;
static const int kBitHasFinalizer = 3;
static const int kBitHasStaticConstructor = 4;
static const int kBitIsBlittable = 5;
static const int kBitIsImportOrWindowsRuntime = 6;
static const int kPackingSize = 7;     // This uses 4 bits from bit 7 to bit 10
static const int kPackingSizeIsDefault = 11;
static const int kClassSizeIsDefault = 12;
static const int kSpecifiedPackingSize = 13; // This uses 4 bits from bit 13 to bit 16
static const int kBitIsByRefLike = 17;

template<typename T>
static T MetadataOffset(const void* metadata, size_t sectionOffset, size_t itemIndex)
{
    return reinterpret_cast<T>(reinterpret_cast<uint8_t*>(const_cast<void*>(metadata)) + sectionOffset) + itemIndex;
}

static const char* GetStringFromIndex(StringIndex index)
{
    IL2CPP_ASSERT(index <= s_GlobalMetadataHeader->strings.size);
    return MetadataOffset<const char*>(s_GlobalMetadata, s_GlobalMetadataHeader->strings.offset, index);
}

static const char* GetWindowsRuntimeStringFromIndex(StringIndex index)
{
    IL2CPP_ASSERT(index <= s_GlobalMetadataHeader->windowsRuntimeStrings.size);
    return MetadataOffset<const char*>(s_GlobalMetadata, s_GlobalMetadataHeader->windowsRuntimeStrings.offset, index);
}

static const Il2CppMetadataMethodDefinitionHandle GetMethodDefinitionFromIndex(MethodIndex index)
{
    const auto numMethods = s_GlobalMetadataHeader->methods.count;
    const auto serializedSize = s_GlobalMetadataHeader->methods.size / numMethods;
    IL2CPP_ASSERT(index >= 0 && index < numMethods);
    const auto* methods = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->methods.offset;
    const auto* method = methods + index * serializedSize;
    return reinterpret_cast<Il2CppMetadataMethodDefinitionHandle>(method);
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodDefinitionIndex(MethodIndex index)
{
    IL2CPP_ASSERT(index >= 0 && index < s_GlobalMetadataHeader->methods.count);

    return utils::InitOnce(&s_MethodInfoDefinitionTable[index], &g_MetadataLock, [index](il2cpp::os::FastAutoLock& _)
    {
        const Il2CppMetadataMethodDefinitionHandle handle = GetMethodDefinitionFromIndex(index);
        const Il2CppMethodDefinition methodDefinition = DeserializeMethodDefinition(handle, s_SerializedIndexSizes);
        Il2CppClass* typeInfo = GetTypeInfoFromTypeDefinitionIndex(methodDefinition.declaringType);
        il2cpp::vm::Class::SetupMethods(typeInfo);
        const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(typeInfo->typeMetadataHandle, s_SerializedIndexSizes);
        return typeInfo->methods[index - typeDefinition.methodStart];
    });
}

static const Il2CppEventDefinition GetEventDefinitionFromIndex(const Il2CppImage* image, const EventIndex index)
{
    const auto numEvents = s_GlobalMetadataHeader->events.count;
    const auto serializedSize = s_GlobalMetadataHeader->events.size / numEvents;
    IL2CPP_ASSERT(index >= 0 && index < numEvents);
    const auto* events = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->events.offset;
    return DeserializeEventDefinition(events + index * serializedSize, s_SerializedIndexSizes);
}

static const Il2CppPropertyDefinition* GetPropertyDefinitionFromIndex(const Il2CppImage* image, PropertyIndex index)
{
    IL2CPP_ASSERT(
        index >= 0
        && index <= s_GlobalMetadataHeader->properties.size / static_cast<int32_t>(sizeof(Il2CppPropertyDefinition))
    );
    const Il2CppPropertyDefinition* properties = (const Il2CppPropertyDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->properties.offset);
    return properties + index;
}

static const Il2CppParameterDefinition GetParameterDefinitionFromIndex(const Il2CppImage* image, const ParameterIndex index)
{
    const auto numParameters = s_GlobalMetadataHeader->parameters.count;
    const auto parameterSize = s_GlobalMetadataHeader->parameters.size / numParameters;
    IL2CPP_ASSERT(index >= 0 && index < numParameters);
    const auto* parameters = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->parameters.offset;
    return DeserializeParameterDefinition(parameters + index * parameterSize, s_SerializedIndexSizes);
}

static Il2CppGenericMethod BuildGenericMethodFromIndex(GenericMethodIndex index)
{
    IL2CPP_ASSERT(index < s_Il2CppMetadataRegistration->methodSpecsCount);

    const Il2CppMethodSpec* methodSpec = s_Il2CppMetadataRegistration->methodSpecs + index;
    Il2CppGenericMethodKey key = il2cpp::vm::GlobalMetadata::BuildGenericMethodFromMethodSpec(methodSpec);

    Il2CppGenericMethod gmethod = { 0 };
    gmethod.methodDefinition = il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodHandle(key.methodDefinitionHandle);
    gmethod.context = key.context;
    return gmethod;
}

Il2CppGenericMethodKey il2cpp::vm::GlobalMetadata::BuildGenericMethodFromMethodSpec(const Il2CppMethodSpec* methodSpec)
{
    const Il2CppMetadataMethodDefinitionHandle handle = GetMethodDefinitionFromIndex(methodSpec->methodDefinitionIndex);
    const Il2CppGenericInst* classInst = NULL;
    const Il2CppGenericInst* methodInst = NULL;
    if (methodSpec->classIndexIndex != -1)
    {
        IL2CPP_ASSERT(methodSpec->classIndexIndex < s_Il2CppMetadataRegistration->genericInstsCount);
        classInst = s_Il2CppMetadataRegistration->genericInsts[methodSpec->classIndexIndex];
    }
    if (methodSpec->methodIndexIndex != -1)
    {
        IL2CPP_ASSERT(methodSpec->methodIndexIndex < s_Il2CppMetadataRegistration->genericInstsCount);
        methodInst = s_Il2CppMetadataRegistration->genericInsts[methodSpec->methodIndexIndex];
    }

    Il2CppGenericMethodKey key = { 0 };
    key.methodDefinitionHandle = handle;
    key.context.class_inst = classInst;
    key.context.method_inst = methodInst;
    return key;
}

static const MethodInfo* GetMethodInfoFromEncodedIndex(EncodedMethodIndex methodIndex)
{
    Il2CppMetadataUsage usage = GetEncodedIndexType(methodIndex);

    uint32_t index = GetDecodedMethodIndex(methodIndex);

    switch (GetEncodedIndexType(methodIndex))
    {
        case kIl2CppMetadataUsageMethodRef:
            return il2cpp::metadata::GenericMethod::GetMethod(BuildGenericMethodFromIndex(index));
        case kIl2CppMetadataUsageMethodDef:
            return il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodDefinitionIndex(index);
        case kIl2CppMetadataUsageInvalid:
        {
            switch (index)
            {
                case kIl2CppInvalidMetadataUsageNoData:
                    return NULL;
                case kIl2CppInvalidMetadataUsageAmbiguousMethod:
                    return il2cpp::vm::Method::GetAmbiguousMethodInfo();
                default:
                    IL2CPP_ASSERT(0);
                    break;
            }
        }
        default:
            IL2CPP_ASSERT(0);
            break;
    }

    return NULL;
}

static Il2CppString* GetStringLiteralFromIndex(StringLiteralIndex index)
{
    if (index == kStringLiteralIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(
        index >= 0
        && index + 1 < s_GlobalMetadataHeader->stringLiterals.size / static_cast<int32_t>(sizeof(Il2CppStringLiteral))
        && "Invalid string literal index "
    );

    if (s_StringLiteralTable[index])
        return s_StringLiteralTable[index];

    const Il2CppStringLiteral* stringLiteral = (const Il2CppStringLiteral*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->stringLiterals.offset) + index;
    const Il2CppStringLiteral* nextLiteral = stringLiteral + 1;
    const auto* startOfDataTable = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->stringLiteralData.offset;
    const auto* startOfStringData = startOfDataTable + stringLiteral->dataIndex;
    const auto* startOfNextString = startOfDataTable + nextLiteral->dataIndex;
    const auto stringLength = static_cast<uint32_t>(startOfNextString - startOfStringData);
    Il2CppString* newString = il2cpp::vm::String::NewLen(startOfStringData, stringLength);
    Il2CppString* prevString = il2cpp::os::Atomic::CompareExchangePointer<Il2CppString>(s_StringLiteralTable + index, newString, NULL);
    if (prevString == NULL)
    {
        il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)s_StringLiteralTable + index);
        return newString;
    }
    return prevString;
}

static FieldInfo* GetFieldInfoFromIndex(EncodedMethodIndex index)
{
    const auto numFieldRefs = s_GlobalMetadataHeader->fieldRefs.count;
    IL2CPP_ASSERT(s_GlobalMetadataHeader->fieldRefs.size >= 0 && index < static_cast<uint32_t>(numFieldRefs));

    const auto fieldRefSize = s_GlobalMetadataHeader->fieldRefs.size / numFieldRefs;
    const auto* fieldRefs = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->fieldRefs.offset;
    const auto fieldRef = DeserializeFieldRef(fieldRefs + index * fieldRefSize, s_SerializedIndexSizes);
    const Il2CppClass* typeInfo = il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeIndex(fieldRef.typeIndex);
    return typeInfo->fields + fieldRef.fieldIndex;
}

void il2cpp::vm::GlobalMetadata::Register(const Il2CppCodeRegistration* const codeRegistration, const Il2CppMetadataRegistration* const metadataRegistration, const Il2CppCodeGenOptions* const codeGenOptions)
{
    s_GlobalMetadata_CodeRegistration = codeRegistration;
    s_Il2CppMetadataRegistration = metadataRegistration;
}

typedef void (*Il2CppTypeUpdater)(Il2CppType*);

static void InitializeTypeHandle(Il2CppType* type)
{
    type->data.typeHandle = il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(type->data.__klassIndex);
}

static void ClearTypeHandle(Il2CppType* type)
{
    type->data.__klassIndex = GetIndexForTypeDefinitionInternal(type->data.typeHandle);
}

static void InitializeGenericParameterHandle(Il2CppType* type)
{
    type->data.genericParameterHandle = GetGenericParameterFromIndexInternal(type->data.__genericParameterIndex);
}

static void ClearGenericParameterHandle(Il2CppType* type)
{
    type->data.__genericParameterIndex = GetIndexForGenericParameter(reinterpret_cast<Il2CppMetadataGenericParameterHandle>(type->data.genericParameterHandle));
}

static void ProcessIl2CppTypeDefinitions(Il2CppTypeUpdater updateTypeDef, Il2CppTypeUpdater updateGenericParam)
{
    for (int32_t i = 0; i < s_Il2CppMetadataRegistration->typesCount; i++)
    {
        const Il2CppType* type = s_Il2CppMetadataRegistration->types[i];
        switch (type->type)
        {
            case IL2CPP_TYPE_VOID:
            case IL2CPP_TYPE_BOOLEAN:
            case IL2CPP_TYPE_CHAR:
            case IL2CPP_TYPE_I1:
            case IL2CPP_TYPE_U1:
            case IL2CPP_TYPE_I2:
            case IL2CPP_TYPE_U2:
            case IL2CPP_TYPE_I4:
            case IL2CPP_TYPE_U4:
            case IL2CPP_TYPE_I8:
            case IL2CPP_TYPE_U8:
            case IL2CPP_TYPE_R4:
            case IL2CPP_TYPE_R8:
            case IL2CPP_TYPE_STRING:
            case IL2CPP_TYPE_VALUETYPE:
            case IL2CPP_TYPE_CLASS:
            case IL2CPP_TYPE_I:
            case IL2CPP_TYPE_U:
            case IL2CPP_TYPE_OBJECT:
            case IL2CPP_TYPE_TYPEDBYREF:
                // The Il2Cpp conversion process writes these types in a writeable section
                // So we can const_cast them here safely
                updateTypeDef(const_cast<Il2CppType*>(type));
                break;
            case IL2CPP_TYPE_VAR:
            case IL2CPP_TYPE_MVAR:
                updateGenericParam(const_cast<Il2CppType*>(type));
                break;
            default:
                // Nothing do to
                break;
        }
    }
}

bool il2cpp::vm::GlobalMetadata::Initialize(int32_t* imagesCount, int32_t* assembliesCount)
{
    s_GlobalMetadata = vm::MetadataLoader::LoadMetadataFile("global-metadata.dat");
    if (!s_GlobalMetadata)
        return false;

    s_GlobalMetadataHeader = (const Il2CppGlobalMetadataHeader*)s_GlobalMetadata;
    IL2CPP_ASSERT(s_GlobalMetadataHeader->sanity == 0xFAB11BAF);
    IL2CPP_ASSERT(s_GlobalMetadataHeader->version == 39);
    IL2CPP_ASSERT(s_GlobalMetadataHeader->stringLiterals.offset == sizeof(Il2CppGlobalMetadataHeader));

    s_MetadataImagesCount = *imagesCount = s_GlobalMetadataHeader->images.count;
    *assembliesCount = s_GlobalMetadataHeader->assemblies.count;

    s_SerializedIndexSizes = SerializedIndexSizes {
        GetIndexSize(s_Il2CppMetadataRegistration->typesCount),
        GetIndexSize(s_GlobalMetadataHeader->typeDefinitions.count),
        GetIndexSize(s_GlobalMetadataHeader->genericContainers.count),
        GetIndexSize(s_GlobalMetadataHeader->parameters.count),
    };

    // Pre-allocate these arrays so we don't need to lock when reading later.
    // These arrays hold the runtime metadata representation for metadata explicitly
    // referenced during conversion. There is a corresponding table of same size
    // in the converted metadata, giving a description of runtime metadata to construct.
    s_MetadataImagesTable = (Il2CppImageGlobalMetadata*)IL2CPP_CALLOC(s_MetadataImagesCount, sizeof(Il2CppImageGlobalMetadata));
    s_TypeInfoTable = (Il2CppClass**)IL2CPP_CALLOC(s_Il2CppMetadataRegistration->typesCount, sizeof(Il2CppClass*));
    s_TypeInfoDefinitionTable = (Il2CppClass**)IL2CPP_CALLOC(s_GlobalMetadataHeader->typeDefinitions.count, sizeof(Il2CppClass*));
    s_MethodInfoDefinitionTable = (const MethodInfo**)IL2CPP_CALLOC(s_GlobalMetadataHeader->methods.count, sizeof(MethodInfo*));

    ProcessIl2CppTypeDefinitions(InitializeTypeHandle, InitializeGenericParameterHandle);

    return true;
}

void il2cpp::vm::GlobalMetadata::InitializeAllMethodMetadata()
{
    for (size_t i = 0; i < s_Il2CppMetadataRegistration->metadataUsagesCount; i++)
    {
        uintptr_t* metadataPointer = reinterpret_cast<uintptr_t*>(s_Il2CppMetadataRegistration->metadataUsages[i]);
        Il2CppMetadataUsage usage = GetEncodedIndexType(static_cast<uint32_t>(*metadataPointer));
        switch (usage)
        {
            case kIl2CppMetadataUsageTypeInfo:
            case kIl2CppMetadataUsageMethodDef:
            case kIl2CppMetadataUsageMethodRef:
                InitializeRuntimeMetadata(metadataPointer, false);
                break;
            default:
                break;
        }
    }
}

// This method can be called from multiple threads, so it does have a data race. However, each
// thread is reading from the same read-only metadata, so each thread will set the same values.
// Therefore, we can safely ignore thread sanitizer issues in this method.
void* il2cpp::vm::GlobalMetadata::InitializeRuntimeMetadata(uintptr_t* metadataPointer, bool throwOnError) IL2CPP_DISABLE_TSAN
{
    // This must be the only read of *metadataPointer
    // This code has no locks and we need to ensure that we only read metadataPointer once
    // so we don't read it once as an encoded token and once as an initialized pointer
    uintptr_t metadataValue = (uintptr_t)os::Atomic::ReadPtrVal((intptr_t*)metadataPointer);

    if (IsRuntimeMetadataInitialized(metadataValue))
        return (void*)metadataValue;

    uint32_t encodedToken = static_cast<uint32_t>(metadataValue);
    Il2CppMetadataUsage usage = GetEncodedIndexType(encodedToken);
    uint32_t decodedIndex = GetDecodedMethodIndex(encodedToken);

    void* initialized = NULL;

    switch (usage)
    {
        case kIl2CppMetadataUsageTypeInfo:
            initialized = (void*)il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeIndex(decodedIndex, throwOnError);
            break;
        case kIl2CppMetadataUsageIl2CppType:
            initialized = (void*)il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(decodedIndex);
            break;
        case kIl2CppMetadataUsageMethodDef:
        case kIl2CppMetadataUsageMethodRef:
            initialized = (void*)GetMethodInfoFromEncodedIndex(encodedToken);
            break;
        case kIl2CppMetadataUsageFieldInfo:
            initialized = (void*)GetFieldInfoFromIndex(decodedIndex);
            break;
        case kIl2CppMetadataUsageStringLiteral:
            initialized = (void*)GetStringLiteralFromIndex(decodedIndex);
            break;
        case kIl2CppMetadataUsageFieldRva:
            const Il2CppType* unused;
            initialized = (void*)GetFieldDefaultValue(GetFieldInfoFromIndex(decodedIndex), &unused);
            {
                const size_t MappedFieldDataAlignment = 8; // Should match System.Reflection.Metadata.ManagedPEBuilder.MappedFieldDataAlignment
                IL2CPP_ASSERT(((uintptr_t)initialized % MappedFieldDataAlignment) == 0);
            }
            break;
        case kIl2CppMetadataUsageInvalid:
            break;
        default:
            IL2CPP_NOT_IMPLEMENTED(il2cpp::vm::GlobalMetadata::InitializeMethodMetadata);
            break;
    }

    IL2CPP_ASSERT(IsRuntimeMetadataInitialized(initialized) && "ERROR: The low bit of the metadata item is still set, alignment issue");

    if (initialized != NULL)
    {
        // Set the metadata pointer last, with a barrier, so it is the last item written
        il2cpp::os::Atomic::PublishPointer((void**)metadataPointer, initialized);
    }

    return initialized;
}

void il2cpp::vm::GlobalMetadata::InitializeStringLiteralTable()
{
    s_StringLiteralTable = (Il2CppString**)il2cpp::gc::GarbageCollector::AllocateFixed(s_GlobalMetadataHeader->stringLiterals.size / sizeof(Il2CppStringLiteral) * sizeof(Il2CppString*), NULL);
}

void il2cpp::vm::GlobalMetadata::InitializeWindowsRuntimeTypeNamesTables(WindowsRuntimeTypeNameToClassMap& windowsRuntimeTypeNameToClassMap, ClassToWindowsRuntimeTypeNameMap& classToWindowsRuntimeTypeNameMap)
{
    const auto typeCount = s_GlobalMetadataHeader->windowsRuntimeTypeNames.count;
    const auto* windowsRuntimeTypeNames = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->windowsRuntimeTypeNames.offset;

    windowsRuntimeTypeNameToClassMap.resize(typeCount / 2 + 1);
    classToWindowsRuntimeTypeNameMap.resize(typeCount);

    for (int32_t i = 0; i < typeCount; i++)
    {
        const auto typeNamePairSize = s_GlobalMetadataHeader->windowsRuntimeTypeNames.size / typeCount;
        const auto* structPtr = windowsRuntimeTypeNames + typeNamePairSize * i;
        Il2CppWindowsRuntimeTypeNamePair typeNamePair = DeserializeWindowsRuntimeTypeNamePair(structPtr, s_SerializedIndexSizes);
        const char* name = GetWindowsRuntimeStringFromIndex(typeNamePair.nameIndex);
        const Il2CppType* type = GetIl2CppTypeFromIndex(typeNamePair.typeIndex);
        Il2CppClass* klass = Class::FromIl2CppType(type);

        if (!Class::IsNullable(klass))
        {
            // Don't add nullable types to name -> klass map because IReference`1<T> and Nullable`1<T>
            // share windows runtime type names, and that would cause a collision.
            windowsRuntimeTypeNameToClassMap.insert(std::make_pair(name, klass));
        }

        classToWindowsRuntimeTypeNameMap.insert(std::make_pair(klass, name));
    }
}

void il2cpp::vm::GlobalMetadata::InitializeUnresolvedSignatureTable(Il2CppUnresolvedSignatureMap& unresolvedSignatureMap)
{
    unresolvedSignatureMap.resize(s_GlobalMetadata_CodeRegistration->unresolvedIndirectCallCount);
    const auto* paramTypes = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->unresolvedIndirectCallParameterTypes.offset;
    const auto typeIndexSize = s_SerializedIndexSizes.typeIndex;

    for (uint32_t i = 0; i < s_GlobalMetadata_CodeRegistration->unresolvedIndirectCallCount; ++i)
    {
        const Il2CppMetadataRange* range = MetadataOffset<Il2CppMetadataRange*>(s_GlobalMetadata, s_GlobalMetadataHeader->unresolvedIndirectCallParameterRanges.offset, i);
        il2cpp::metadata::Il2CppSignature signature;
        signature.Count = range->length;
        signature.Types = (const Il2CppType**)MetadataMalloc(range->length * sizeof(Il2CppType*));

        for (int j = 0; j < range->length; ++j)
        {
            const auto* indexPtr = paramTypes + typeIndexSize * (range->start + j);
            const auto typeIndex = DeserializeIndex<TypeIndex>(indexPtr, typeIndexSize);
            const Il2CppType* type = GetIl2CppTypeFromIndex(typeIndex);
            signature.Types[j] = type;
        }

        unresolvedSignatureMap.insert(std::make_pair(signature, i));
    }
}

void il2cpp::vm::GlobalMetadata::InitializeGenericMethodTable(Il2CppMethodTableMap& methodTableMap)
{
    methodTableMap.resize(s_Il2CppMetadataRegistration->genericMethodTableCount);

    for (int32_t i = 0; i < s_Il2CppMetadataRegistration->genericMethodTableCount; i++)
    {
        const Il2CppGenericMethodFunctionsDefinitions* genericMethodIndices = s_Il2CppMetadataRegistration->genericMethodTable + i;
        const Il2CppMethodSpec* methodSpec = s_Il2CppMetadataRegistration->methodSpecs + (genericMethodIndices->genericMethodIndex);
        methodTableMap.insert(std::make_pair(metadata::Il2CppMethodSpecOrGenericMethod(methodSpec), &genericMethodIndices->indices));
    }
}

static void ClearStringLiteralTable()
{
    il2cpp::gc::GarbageCollector::FreeFixed(s_StringLiteralTable);
    s_StringLiteralTable = NULL;
}

static void FreeAndNull(void** pointer)
{
    IL2CPP_FREE(*pointer);
    *pointer = NULL;
}

void il2cpp::vm::GlobalMetadata::Clear()
{
    ClearStringLiteralTable();

    FreeAndNull((void**)&s_MethodInfoDefinitionTable);
    FreeAndNull((void**)&s_TypeInfoTable);
    FreeAndNull((void**)&s_MetadataImagesTable);

    for (int32_t i = 0; i < s_GlobalMetadataHeader->typeDefinitions.count; i++)
    {
        if (s_TypeInfoDefinitionTable[i] != NULL)
            IL2CPP_FREE(s_TypeInfoDefinitionTable[i]);
    }

    FreeAndNull((void**)&s_TypeInfoDefinitionTable);

    ProcessIl2CppTypeDefinitions(ClearTypeHandle, ClearGenericParameterHandle);

    vm::MetadataLoader::UnloadMetadataFile(s_GlobalMetadata);
    s_GlobalMetadataHeader = NULL;
    s_GlobalMetadata = NULL;

    s_GlobalMetadata_CodeRegistration = NULL;
    s_Il2CppMetadataRegistration = NULL;
}

void il2cpp::vm::GlobalMetadata::BuildIl2CppImage(Il2CppImage* image, ImageIndex imageIndex, AssemblyIndex* imageAssemblyIndex)
{
    const auto numImages = s_GlobalMetadataHeader->images.count;
    const auto* imagesDefinitions = (const char*)s_GlobalMetadata + s_GlobalMetadataHeader->images.offset;
    const auto serializedSize = s_GlobalMetadataHeader->images.size / numImages;

    const Il2CppImageDefinition imageDefinition = DeserializeImageDefinition(imagesDefinitions + serializedSize * imageIndex, s_SerializedIndexSizes);

    image->name = GetStringFromIndex(imageDefinition.nameIndex);

    *imageAssemblyIndex = imageDefinition.assemblyIndex;
    image->typeCount = imageDefinition.typeCount;
    image->exportedTypeCount = imageDefinition.exportedTypeCount;
    image->token = imageDefinition.token;
    image->customAttributeCount = imageDefinition.customAttributeCount;

    Il2CppImageGlobalMetadata* metadataImage = s_MetadataImagesTable + imageIndex;
    metadataImage->typeStart = imageDefinition.typeStart;
    metadataImage->customAttributeStart = imageDefinition.customAttributeStart;
    metadataImage->entryPointIndex = imageDefinition.entryPointIndex;
    metadataImage->exportedTypeStart = imageDefinition.exportedTypeStart;
    metadataImage->image = image;

    image->metadataHandle = reinterpret_cast<Il2CppMetadataImageHandle>(metadataImage);
}

void il2cpp::vm::GlobalMetadata::BuildIl2CppAssembly(Il2CppAssembly* assembly, AssemblyIndex assemblyIndex, ImageIndex* assemblyImageIndex)
{
    const Il2CppAssemblyDefinition* assemblyDefinitions = (const Il2CppAssemblyDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->assemblies.offset);
    const Il2CppAssemblyDefinition* assemblyDefinition = assemblyDefinitions + assemblyIndex;

    assembly->token = assemblyDefinition->token;
    assembly->referencedAssemblyStart = assemblyDefinition->referencedAssemblyStart;
    assembly->referencedAssemblyCount = assemblyDefinition->referencedAssemblyCount;

    Il2CppAssemblyName* assemblyName = &assembly->aname;
    const Il2CppAssemblyNameDefinition* assemblyNameDefinition = &assemblyDefinition->aname;

    assemblyName->name = GetStringFromIndex(assemblyNameDefinition->nameIndex);
    assemblyName->culture = GetStringFromIndex(assemblyNameDefinition->cultureIndex);
    assemblyName->public_key = (const uint8_t*)GetStringFromIndex(assemblyNameDefinition->publicKeyIndex);
    assemblyName->hash_alg = assemblyNameDefinition->hash_alg;
    assemblyName->hash_len = assemblyNameDefinition->hash_len;
    assemblyName->flags = assemblyNameDefinition->flags;
    assemblyName->major = assemblyNameDefinition->major;
    assemblyName->minor = assemblyNameDefinition->minor;
    assemblyName->build = assemblyNameDefinition->build;
    assemblyName->revision = assemblyNameDefinition->revision;
    memcpy(assemblyName->public_key_token, assemblyNameDefinition->public_key_token, sizeof(assemblyNameDefinition->public_key_token));

    *assemblyImageIndex = assemblyDefinition->imageIndex;
}

static const Il2CppImageGlobalMetadata* GetImageMetadata(const Il2CppImage* image)
{
    return reinterpret_cast<const Il2CppImageGlobalMetadata*>(image->metadataHandle);
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetAssemblyEntryPoint(const Il2CppImage* image)
{
    const Il2CppImageGlobalMetadata* imageMetadata = GetImageMetadata(image);

    if (imageMetadata == NULL || imageMetadata->entryPointIndex == -1)
        return NULL;

    return GetMethodInfoFromMethodDefinitionIndex(imageMetadata->entryPointIndex);
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetAssemblyTypeHandle(const Il2CppImage* image, AssemblyTypeIndex index)
{
    const Il2CppImageGlobalMetadata* imageMetadata = GetImageMetadata(image);

    IL2CPP_ASSERT(index >= 0 && index < static_cast<AssemblyTypeIndex>(image->typeCount));
    TypeDefinitionIndex typeDefinitionIndex = imageMetadata->typeStart + index;
    return GetTypeHandleFromIndex(typeDefinitionIndex);
}

const Il2CppAssembly* il2cpp::vm::GlobalMetadata::GetReferencedAssembly(const Il2CppAssembly* assembly, int32_t referencedAssemblyTableIndex, const Il2CppAssembly assembliesTable[], int assembliesCount)
{
    IL2CPP_ASSERT(referencedAssemblyTableIndex < assembly->referencedAssemblyCount);

    referencedAssemblyTableIndex = assembly->referencedAssemblyStart + referencedAssemblyTableIndex;

    IL2CPP_ASSERT(
        referencedAssemblyTableIndex >= 0
        && referencedAssemblyTableIndex <= s_GlobalMetadataHeader->referencedAssemblies.size / static_cast<int32_t>(sizeof(int32_t))
    );
    const int32_t* referenceAssemblyIndicies = (const int32_t*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->referencedAssemblies.offset);
    return assembliesTable + referenceAssemblyIndicies[referencedAssemblyTableIndex];
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetAssemblyExportedTypeHandle(const Il2CppImage* image, AssemblyExportedTypeIndex index)
{
    if (index == kTypeDefinitionIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index >= 0 && index < static_cast<AssemblyExportedTypeIndex>(image->exportedTypeCount));

    const Il2CppImageGlobalMetadata* imageMetadata = GetImageMetadata(image);

    int32_t exportedTypeIndex = imageMetadata->exportedTypeStart + index;

    IL2CPP_ASSERT(
        exportedTypeIndex >= 0
        && exportedTypeIndex < s_GlobalMetadataHeader->exportedTypeDefinitions.size / static_cast<int32_t>(sizeof(TypeDefinitionIndex))
    );
    TypeDefinitionIndex* exportedTypes = (TypeDefinitionIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->exportedTypeDefinitions.offset);
    TypeDefinitionIndex typeDefinitionIndex =  *(exportedTypes + exportedTypeIndex);

    return GetTypeHandleFromIndex(typeDefinitionIndex);
}

static TypeDefinitionIndex GetIndexForTypeDefinitionInternal(const Il2CppMetadataTypeHandle typeHandle)
{
    IL2CPP_ASSERT(typeHandle);
    const auto numTypeDefinitions = s_GlobalMetadataHeader->typeDefinitions.count;
    const auto typeDefinitionSize = s_GlobalMetadataHeader->typeDefinitions.size / numTypeDefinitions;
    const auto* typeDefinitions = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->typeDefinitions.offset;
    const auto* typeDefinition = reinterpret_cast<const char*>(typeHandle);

    IL2CPP_ASSERT(
        typeDefinition >= typeDefinitions
        && typeDefinition < typeDefinitions + s_GlobalMetadataHeader->typeDefinitions.size
    );

    ptrdiff_t index = (typeDefinition - typeDefinitions) / typeDefinitionSize;
    IL2CPP_ASSERT(index < numTypeDefinitions);
    return static_cast<TypeDefinitionIndex>(index);
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeDefinitionIndex(TypeDefinitionIndex index)
{
    if (index == kTypeIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index >= 0 && index < s_GlobalMetadataHeader->typeDefinitions.count);

    return utils::InitOnce(&s_TypeInfoDefinitionTable[index], &il2cpp::vm::g_MetadataLock, [index](il2cpp::os::FastAutoLock& _) { return FromTypeDefinition(index); });
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle(Il2CppMetadataTypeHandle handle)
{
    return GetTypeInfoFromTypeDefinitionIndex(GetIndexForTypeDefinitionInternal(handle));
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle_OnlyCached(Il2CppMetadataTypeHandle handle)
{
    TypeDefinitionIndex index = GetIndexForTypeDefinitionInternal(handle);
    return s_TypeInfoDefinitionTable[index];
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromType(const Il2CppType* type)
{
    return GetTypeInfoFromHandle(type->data.typeHandle);
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetInterfaceFromOffset(const Il2CppClass* klass, const TypeInterfaceIndex offset)
{
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(offset >= 0 && offset < typeDefinition.interfaces_count);

    const InterfacesIndex index = typeDefinition.interfacesStart + offset;
    const auto typeIndexSize = s_SerializedIndexSizes.typeIndex;
    const auto numInterfaces = s_GlobalMetadataHeader->interfaces.size / typeIndexSize;

    IL2CPP_ASSERT(index >= 0 && index < numInterfaces);
    const auto* interfaceIndices = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->interfaces.offset;

    return GetIl2CppTypeFromIndex(DeserializeIndex<TypeIndex>(interfaceIndices + index * typeIndexSize, typeIndexSize));
}

Il2CppInterfaceOffsetInfo il2cpp::vm::GlobalMetadata::GetInterfaceOffsetInfo(const Il2CppClass* klass, const TypeInterfaceOffsetIndex index)
{
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(index >= 0 && index < typeDefinition.interface_offsets_count);

    const auto relativeIndex = index + typeDefinition.interfaceOffsetsStart;
    const auto numInterfaceOffsets = s_GlobalMetadataHeader->interfaceOffsets.count;
    const auto interfaceOffsetSize = s_GlobalMetadataHeader->interfaceOffsets.size / numInterfaceOffsets;
    IL2CPP_ASSERT(relativeIndex >= 0 && relativeIndex < numInterfaceOffsets);
    const auto* interfaceOffsets = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->interfaceOffsets.offset;
    const Il2CppInterfaceOffsetPair interfaceOffset = DeserializeInterfaceOffsetPair(
        interfaceOffsets + relativeIndex * interfaceOffsetSize,
        s_SerializedIndexSizes
    );

    return
        {
            GetIl2CppTypeFromIndex(interfaceOffset.interfaceTypeIndex),
            interfaceOffset.offset
        };
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(TypeDefinitionIndex typeIndex)
{
    if (typeIndex == kTypeDefinitionIndexInvalid)
        return NULL;

    return GetTypeHandle(typeIndex);
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetTypeHandleFromType(const Il2CppType* type)
{
    IL2CPP_ASSERT(type->type == IL2CPP_TYPE_CLASS || type->type == IL2CPP_TYPE_VALUETYPE);
    return type->data.typeHandle;
}

bool il2cpp::vm::GlobalMetadata::TypeIsNested(Il2CppMetadataTypeHandle handle)
{
    const auto typeDefinition = DeserializeTypeDefinition(handle, s_SerializedIndexSizes);
    return typeDefinition.declaringTypeIndex != kTypeIndexInvalid;
}

bool il2cpp::vm::GlobalMetadata::TypeIsValueType(Il2CppMetadataTypeHandle handle)
{
    const auto typeDefinition = DeserializeTypeDefinition(handle, s_SerializedIndexSizes);
    return (typeDefinition.bitfield >> (kBitIsValueType - 1)) & 0x1;
}

bool il2cpp::vm::GlobalMetadata::StructLayoutPackIsDefault(Il2CppMetadataTypeHandle handle)
{
    const auto typeDefinition = DeserializeTypeDefinition(handle, s_SerializedIndexSizes);
    return (typeDefinition.bitfield >> (kPackingSizeIsDefault - 1)) & 0x1;
}

bool il2cpp::vm::GlobalMetadata::StructLayoutSizeIsDefault(Il2CppMetadataTypeHandle handle)
{
    const auto typeDefinition = DeserializeTypeDefinition(handle, s_SerializedIndexSizes);
    return (typeDefinition.bitfield >> (kClassSizeIsDefault - 1)) & 0x1;
}

std::pair<const char*, const char*> il2cpp::vm::GlobalMetadata::GetTypeNamespaceAndName(Il2CppMetadataTypeHandle handle)
{
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(handle, s_SerializedIndexSizes);
    return std::make_pair
        (
        GetStringFromIndex(typeDefinition.namespaceIndex),
        GetStringFromIndex(typeDefinition.nameIndex)
        );
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetNestedTypeFromOffset(const Il2CppClass* klass, TypeNestedTypeIndex offset)
{
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(offset >= 0 && offset < typeDefinition.nested_type_count);

    NestedTypeIndex index = typeDefinition.nestedTypesStart + offset;

    IL2CPP_ASSERT(
        index >= 0
        && index <= s_GlobalMetadataHeader->nestedTypes.size / static_cast<int32_t>(sizeof(TypeDefinitionIndex))
    );

    const TypeDefinitionIndex* nestedTypeIndices = (const TypeDefinitionIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->nestedTypes.offset);

    return GetTypeInfoFromTypeDefinitionIndex(nestedTypeIndices[index]);
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetNestedTypes(Il2CppMetadataTypeHandle handle, void** iter)
{
    if (!iter)
        return NULL;

    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(handle, s_SerializedIndexSizes);

    const TypeDefinitionIndex* nestedTypeIndices = (const TypeDefinitionIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->nestedTypes.offset);

    if (!*iter)
    {
        if (typeDefinition.nested_type_count == 0)
            return NULL;

        *iter = (void*)(nestedTypeIndices + typeDefinition.nestedTypesStart);
        return GetTypeHandleFromIndex(nestedTypeIndices[typeDefinition.nestedTypesStart]);
    }

    TypeDefinitionIndex* nestedTypeAddress = (TypeDefinitionIndex*)*iter;
    nestedTypeAddress++;
    ptrdiff_t index = nestedTypeAddress - nestedTypeIndices;

    if (index < typeDefinition.nestedTypesStart + typeDefinition.nested_type_count)
    {
        *iter = nestedTypeAddress;
        return GetTypeHandleFromIndex(*nestedTypeAddress);
    }

    return NULL;
}

static void InitializeCustomAttributesCaches(void* param)
{
    s_CustomAttributesCount = 0;
    for (int i = 0; i < s_MetadataImagesCount; i++)
    {
        s_CustomAttributesCount += s_MetadataImagesTable[i].image->customAttributeCount;
    }
}

static int CompareTokens(const void* pkey, const void* pelem)
{
    return (int)(((Il2CppCustomAttributeDataRange*)pkey)->token - ((Il2CppCustomAttributeDataRange*)pelem)->token);
}

static const Il2CppImageGlobalMetadata* GetImageForCustomAttributeIndex(CustomAttributeIndex index)
{
    for (int32_t imageIndex = 0; imageIndex < s_MetadataImagesCount; imageIndex++)
    {
        const Il2CppImageGlobalMetadata* imageMetadta = s_MetadataImagesTable + imageIndex;
        IL2CPP_ASSERT(index >= 0);
        if (
            index >= imageMetadta->customAttributeStart
            && index < (imageMetadta->customAttributeStart + static_cast<CustomAttributeIndex>(imageMetadta->image->customAttributeCount))
        )
            return imageMetadta;
    }

    IL2CPP_ASSERT(0 && "Failed to find owning image for custom attribute index");
    return NULL;
}

static CustomAttributeIndex GetCustomAttributeIndex(const Il2CppCustomAttributeDataRange* attrDataRange)
{
    if (attrDataRange == NULL)
        return kCustomAttributeIndexInvalid;

    const Il2CppCustomAttributeDataRange* attributeTypeRangeStart = MetadataOffset<const Il2CppCustomAttributeDataRange*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeDataRanges.offset, 0);

    CustomAttributeIndex index = (CustomAttributeIndex)(attrDataRange - attributeTypeRangeStart);

    IL2CPP_ASSERT(index >= 0 && index < (CustomAttributeIndex)(s_GlobalMetadataHeader->attributeDataRanges.size / sizeof(Il2CppCustomAttributeDataRange)));

    return index;
}

static const Il2CppImage* GetCustomAttributeImageFromHandle(Il2CppMetadataCustomAttributeHandle handle)
{
    if (handle == NULL)
        return NULL;

    const Il2CppCustomAttributeDataRange *dataRange = reinterpret_cast<const Il2CppCustomAttributeDataRange*>(handle);

    CustomAttributeIndex index = GetCustomAttributeIndex(dataRange);
    const Il2CppImageGlobalMetadata* imageMetadata = GetImageForCustomAttributeIndex(index);
    if (imageMetadata == NULL)
        return NULL;

    return imageMetadata->image;
}

static CustomAttributeIndex GetCustomAttributeIndex(const Il2CppImage* image, uint32_t token)
{
    const Il2CppCustomAttributeDataRange* attrDataRange = reinterpret_cast<const Il2CppCustomAttributeDataRange*>(il2cpp::vm::GlobalMetadata::GetCustomAttributeTypeToken(image, token));
    return GetCustomAttributeIndex(attrDataRange);
}

Il2CppMetadataCustomAttributeHandle il2cpp::vm::GlobalMetadata::GetCustomAttributeTypeToken(const Il2CppImage* image, uint32_t token)
{
    const Il2CppCustomAttributeDataRange* attributeTypeRange = MetadataOffset<const Il2CppCustomAttributeDataRange*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeDataRanges.offset, 0);

    Il2CppCustomAttributeDataRange key = {0};
    key.token = token;

    const Il2CppImageGlobalMetadata* imageMetadata = GetImageMetadata(image);
    const Il2CppCustomAttributeDataRange* res = (const Il2CppCustomAttributeDataRange*)bsearch(&key, attributeTypeRange + imageMetadata->customAttributeStart, image->customAttributeCount, sizeof(Il2CppCustomAttributeDataRange), CompareTokens);
    return reinterpret_cast<Il2CppMetadataCustomAttributeHandle>(res);
}

static il2cpp::metadata::CustomAttributeDataReader CreateCustomAttributeDataReader(Il2CppMetadataCustomAttributeHandle handle, const Il2CppImage* image)
{
    if (handle == NULL)
        return il2cpp::metadata::CustomAttributeDataReader::Empty();

    Il2CppCustomAttributeDataRange* range = (Il2CppCustomAttributeDataRange*)handle;
    const Il2CppCustomAttributeDataRange* next = range + 1;

    void* start = MetadataOffset<uint8_t*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeData.offset, range->startOffset);
    void* end = MetadataOffset<uint8_t*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeData.offset, next->startOffset);

    return il2cpp::metadata::CustomAttributeDataReader(image, start, end);
}

il2cpp::metadata::CustomAttributeDataReader il2cpp::vm::GlobalMetadata::GetCustomAttributeDataReader(const Il2CppImage* image, uint32_t token)
{
    return CreateCustomAttributeDataReader(GetCustomAttributeTypeToken(image, token), image);
}

il2cpp::metadata::CustomAttributeDataReader il2cpp::vm::GlobalMetadata::GetCustomAttributeDataReader(Il2CppMetadataCustomAttributeHandle handle)
{
    return CreateCustomAttributeDataReader(handle, GetCustomAttributeImageFromHandle(handle));
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromVTableSlot(const Il2CppClass* klass, int32_t vTableSlot)
{
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    uint32_t index = typeDefinition.vtableStart + vTableSlot;
    IL2CPP_ASSERT(index >= 0 && index <= s_GlobalMetadataHeader->vtableMethods.size / sizeof(EncodedMethodIndex));
    const EncodedMethodIndex* vTableMethodReferences = (const EncodedMethodIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->vtableMethods.offset);
    EncodedMethodIndex vTableMethodReference = vTableMethodReferences[index];
    return GetMethodInfoFromEncodedIndex(vTableMethodReference);
}

static int CompareFieldDefaultValues(const void* pkey, const void* pelem)
{
    const auto element = DeserializeFieldDefaultValue(static_cast<const char*>(pelem), s_SerializedIndexSizes);
    return (int)(((Il2CppFieldDefaultValue*)pkey)->fieldIndex - element.fieldIndex);
}

static const uint8_t* GetFieldDefaultValueEntry(const FieldInfo* field)
{
    Il2CppClass* parent = field->parent;
    FieldIndex fieldIndex = (FieldIndex)(field - parent->fields);

    if (il2cpp::vm::Type::IsGenericInstance(&parent->byval_arg))
        parent = il2cpp::vm::GenericClass::GetTypeDefinition(parent->generic_class);

    const Il2CppTypeDefinition parentTypeDefinition = DeserializeTypeDefinition(parent->typeMetadataHandle, s_SerializedIndexSizes);
    fieldIndex += parentTypeDefinition.fieldStart;

    Il2CppFieldDefaultValue key;
    key.fieldIndex = fieldIndex;

    const auto *start = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->fieldDefaultValues.offset;
    const auto numFieldDefaultValues = s_GlobalMetadataHeader->fieldDefaultValues.count;
    const auto serializedObjectSize = s_GlobalMetadataHeader->fieldDefaultValues.size / numFieldDefaultValues;
    const auto* res = static_cast<const uint8_t*>(
        bsearch(&key, start, numFieldDefaultValues, serializedObjectSize, CompareFieldDefaultValues)
    );
    return res;
}

static const uint8_t* GetFieldOrParameterDefalutValue(uint32_t index)
{
    if (index == kDefaultValueIndexNull)
        return NULL;

    IL2CPP_ASSERT(index >= 0 && index <= s_GlobalMetadataHeader->fieldAndParameterDefaultValueData.size / sizeof(uint8_t));
    const uint8_t* defaultValuesData =  (const uint8_t*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->fieldAndParameterDefaultValueData.offset);
    return defaultValuesData + index;
}

const uint8_t* il2cpp::vm::GlobalMetadata::GetFieldDefaultValue(const FieldInfo* field, const Il2CppType** type)
{
    const auto* ptr = GetFieldDefaultValueEntry(field);

    if (ptr != NULL)
    {
        const Il2CppFieldDefaultValue entry = DeserializeFieldDefaultValue(reinterpret_cast<const char*>(ptr), s_SerializedIndexSizes);
        *type = GetIl2CppTypeFromIndex(entry.typeIndex);
        return GetFieldOrParameterDefalutValue(entry.dataIndex);
    }

    return NULL;
}

static int CompareParameterDefaultValues(const void* pkey, const void* pelem)
{
    const auto element = DeserializeParameterDefaultValue(static_cast<const char*>(pelem), s_SerializedIndexSizes);
    return (int)(((Il2CppParameterDefaultValue*)pkey)->parameterIndex - element.parameterIndex);
}

static const uint8_t* GetParameterDefaultValueEntry(const MethodInfo* method, const int32_t parameterPosition)
{
    if (il2cpp::vm::Method::IsGenericInstance(method))
        method = il2cpp::vm::MetadataCache::GetGenericMethodDefinition(method);

    IL2CPP_ASSERT(!il2cpp::vm::Method::IsGenericInstance(method));

    if (method->methodMetadataHandle == NULL)
        return NULL;

    const Il2CppMethodDefinition methodDefinition = DeserializeMethodDefinition(method->methodMetadataHandle, s_SerializedIndexSizes);
    ParameterIndex parameterIndex = methodDefinition.parameterStart + parameterPosition;
    Il2CppParameterDefaultValue key;
    key.parameterIndex = parameterIndex;

    const auto *start = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->parameterDefaultValues.offset;
    const auto numParamDefaultValues = s_GlobalMetadataHeader->parameterDefaultValues.count;
    const auto serializedObjectSize = s_GlobalMetadataHeader->parameterDefaultValues.size / numParamDefaultValues;
    const auto* res = static_cast<const uint8_t*>(
        bsearch(&key, start, numParamDefaultValues, serializedObjectSize, CompareParameterDefaultValues)
    );
    return res;
}

const uint8_t* il2cpp::vm::GlobalMetadata::GetParameterDefaultValue(const MethodInfo* method, int32_t parameterPosition, const Il2CppType** type, bool* isExplicitySetNullDefaultValue)
{
    *isExplicitySetNullDefaultValue = false;
    const auto* ptr = GetParameterDefaultValueEntry(method, parameterPosition);

    if (ptr != NULL)
    {
        const Il2CppParameterDefaultValue entry = DeserializeParameterDefaultValue(reinterpret_cast<const char*>(ptr), s_SerializedIndexSizes);
        *type = GetIl2CppTypeFromIndex(entry.typeIndex);
        *isExplicitySetNullDefaultValue = entry.dataIndex == kDefaultValueIndexNull;
        return GetFieldOrParameterDefalutValue(entry.dataIndex);
    }

    return NULL;
}

static TypeDefinitionIndex GetIndexForTypeDefinition(const Il2CppClass* klass)
{
    return GetIndexForTypeDefinitionInternal(klass->typeMetadataHandle);
}

uint32_t il2cpp::vm::GlobalMetadata::GetFieldOffset(const Il2CppClass* klass, int32_t fieldIndexInType, FieldInfo* field)
{
    const auto typeDefIndex = GetIndexForTypeDefinition(klass);
    IL2CPP_ASSERT(typeDefIndex <= s_Il2CppMetadataRegistration->typeDefinitionsSizesCount);
    int32_t offset = s_Il2CppMetadataRegistration->fieldOffsets[typeDefIndex][fieldIndexInType];
    return offset;
}

static int CompareFieldMarshaledSize(const void* pkey, const void* pelem)
{
    const auto element = DeserializeFieldMarshaledSize(static_cast<const char*>(pelem), s_SerializedIndexSizes);
    return (int)(((Il2CppFieldMarshaledSize*)pkey)->fieldIndex - element.fieldIndex);
}

int il2cpp::vm::GlobalMetadata::GetFieldMarshaledSizeForField(const FieldInfo* field)
{
    Il2CppClass* parent = field->parent;
    size_t fieldIndex = (field - parent->fields);

    if (il2cpp::vm::Type::IsGenericInstance(&parent->byval_arg))
        parent = il2cpp::vm::GenericClass::GetTypeDefinition(parent->generic_class);

    const Il2CppTypeDefinition parentTypeDefinition = DeserializeTypeDefinition(parent->typeMetadataHandle, s_SerializedIndexSizes);
    fieldIndex += parentTypeDefinition.fieldStart;

    const auto *start = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->fieldMarshaledSizes.offset;

    Il2CppFieldMarshaledSize key;
    key.fieldIndex = (FieldIndex)fieldIndex;
    const auto numFieldMarshaledSizes = s_GlobalMetadataHeader->fieldMarshaledSizes.count;
    const auto serializedObjectSize = s_GlobalMetadataHeader->fieldMarshaledSizes.size / numFieldMarshaledSizes;
    const auto* res = static_cast<const char*>(
        bsearch(&key, start, numFieldMarshaledSizes, serializedObjectSize, CompareFieldMarshaledSize)
    );

    if (res != NULL)
        return DeserializeFieldMarshaledSize(res, s_SerializedIndexSizes).size;
    return -1;
}

static const Il2CppFieldDefinition GetFieldDefinitionFromIndex(const Il2CppImage* image, FieldIndex index)
{
    const auto numFields = s_GlobalMetadataHeader->fields.count;
    const auto fieldSize = s_GlobalMetadataHeader->fields.size / numFields;
    IL2CPP_ASSERT(index >= 0 && index < numFields);
    const auto* fields = (const char*)s_GlobalMetadata + s_GlobalMetadataHeader->fields.offset;
    return DeserializeFieldDefinition(fields + index * fieldSize, s_SerializedIndexSizes);
}

Il2CppMetadataFieldInfo il2cpp::vm::GlobalMetadata::GetFieldInfo(const Il2CppClass* klass, TypeFieldIndex fieldIndex)
{
    IL2CPP_ASSERT(klass->typeMetadataHandle != NULL);
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(fieldIndex >= 0 && fieldIndex < typeDefinition.field_count);
    IL2CPP_ASSERT(typeDefinition.fieldStart != kFieldIndexInvalid);

    const Il2CppFieldDefinition fieldDefinition = GetFieldDefinitionFromIndex(klass->image, typeDefinition.fieldStart + fieldIndex);

    return {
            GetIl2CppTypeFromIndex(fieldDefinition.typeIndex),
            GetStringFromIndex(fieldDefinition.nameIndex),
            fieldDefinition.token
    };
}

Il2CppMetadataMethodInfo il2cpp::vm::GlobalMetadata::GetMethodInfo(const Il2CppClass* klass, TypeMethodIndex index)
{
    const uint16_t kFlagIsUnmanagedCallersOnly = 0x8000;

    IL2CPP_ASSERT(klass->typeMetadataHandle != NULL);
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(index >= 0 && index < typeDefinition.method_count);
    IL2CPP_ASSERT(typeDefinition.methodStart != kMethodIndexInvalid);

    const Il2CppMetadataMethodDefinitionHandle handle = GetMethodDefinitionFromIndex(typeDefinition.methodStart + index);
    const Il2CppMethodDefinition methodDefinition = DeserializeMethodDefinition(handle, s_SerializedIndexSizes);

    return {
            handle,
            GetStringFromIndex(methodDefinition.nameIndex),
            GetIl2CppTypeFromIndex(methodDefinition.returnType),
            methodDefinition.token,
            methodDefinition.flags,
            (uint16_t)(methodDefinition.iflags & ~kFlagIsUnmanagedCallersOnly),
            methodDefinition.slot,
            methodDefinition.parameterCount,
            (bool)(methodDefinition.iflags & kFlagIsUnmanagedCallersOnly),
    };
}

Il2CppMetadataParameterInfo il2cpp::vm::GlobalMetadata::GetParameterInfo(const Il2CppClass* klass, const Il2CppMetadataMethodDefinitionHandle handle, const MethodParameterIndex paramIndex)
{
    IL2CPP_ASSERT(handle != NULL);

    const Il2CppMethodDefinition methodDefinition = DeserializeMethodDefinition(handle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(paramIndex >= 0 && paramIndex < methodDefinition.parameterCount);

    const Il2CppParameterDefinition parameterDefinition = GetParameterDefinitionFromIndex(klass->image, methodDefinition.parameterStart + paramIndex);

    return {
            GetStringFromIndex(parameterDefinition.nameIndex),
            parameterDefinition.token,
            GetIl2CppTypeFromIndex(parameterDefinition.typeIndex),
    };
}

Il2CppMetadataPropertyInfo il2cpp::vm::GlobalMetadata::GetPropertyInfo(const Il2CppClass* klass, TypePropertyIndex index)
{
    IL2CPP_ASSERT(klass->typeMetadataHandle != NULL);
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(index >= 0 && index < typeDefinition.property_count);
    IL2CPP_ASSERT(typeDefinition.propertyStart != kPropertyIndexInvalid);

    const Il2CppPropertyDefinition* propertyDefinition = GetPropertyDefinitionFromIndex(klass->image, typeDefinition.propertyStart + index);

    return {
            GetStringFromIndex(propertyDefinition->nameIndex),
            propertyDefinition->get != kMethodIndexInvalid ? klass->methods[propertyDefinition->get] : NULL,
            propertyDefinition->set != kMethodIndexInvalid ? klass->methods[propertyDefinition->set] : NULL,
            propertyDefinition->attrs,
            propertyDefinition->token,
    };
}

Il2CppMetadataEventInfo il2cpp::vm::GlobalMetadata::GetEventInfo(const Il2CppClass* klass, TypeEventIndex index)
{
    IL2CPP_ASSERT(klass->typeMetadataHandle != NULL);
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(klass->typeMetadataHandle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(index >= 0 && index < typeDefinition.event_count);

    const Il2CppEventDefinition eventDefinition = GetEventDefinitionFromIndex(klass->image, typeDefinition.eventStart + index);

    return {
            GetStringFromIndex(eventDefinition.nameIndex),
            GetIl2CppTypeFromIndex(eventDefinition.typeIndex),
            eventDefinition.add != kMethodIndexInvalid ? klass->methods[eventDefinition.add] : NULL,
            eventDefinition.remove != kMethodIndexInvalid ? klass->methods[eventDefinition.remove] : NULL,
            eventDefinition.raise != kMethodIndexInvalid ? klass->methods[eventDefinition.raise] : NULL,
            eventDefinition.token,
    };
}

uint32_t il2cpp::vm::GlobalMetadata::GetReturnParameterToken(Il2CppMetadataMethodDefinitionHandle handle)
{
    IL2CPP_ASSERT(handle != NULL);

    const Il2CppMethodDefinition methodDefinition = DeserializeMethodDefinition(handle, s_SerializedIndexSizes);
    return methodDefinition.returnParameterToken;
}

static const Il2CppGenericContainer* GetGenericContainerFromIndexInternal(GenericContainerIndex index)
{
    if (index == kGenericContainerIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(
        index >= 0
        && index <= s_GlobalMetadataHeader->genericContainers.size / static_cast<int32_t>(sizeof(Il2CppGenericContainer))
    );
    const Il2CppGenericContainer* genericContainers = (const Il2CppGenericContainer*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericContainers.offset);
    return genericContainers + index;
}

static Il2CppMetadataGenericContainerHandle GetGenericContainerFromIndex(GenericContainerIndex index)
{
    const Il2CppGenericContainer* container = GetGenericContainerFromIndexInternal(index);
    return reinterpret_cast<Il2CppMetadataGenericContainerHandle>(container);
}

Il2CppMetadataGenericContainerHandle il2cpp::vm::GlobalMetadata::GetGenericContainerFromGenericClass(const Il2CppGenericClass* genericClass)
{
    const Il2CppTypeDefinition genericType = DeserializeTypeDefinition(GetTypeHandleFromType(genericClass->type), s_SerializedIndexSizes);
    return GetGenericContainerFromIndex(genericType.genericContainerIndex);
}

Il2CppMetadataGenericContainerHandle il2cpp::vm::GlobalMetadata::GetGenericContainerFromMethod(Il2CppMetadataMethodDefinitionHandle handle)
{
    const Il2CppMethodDefinition methodDefinition = DeserializeMethodDefinition(handle, s_SerializedIndexSizes);
    return GetGenericContainerFromIndex(methodDefinition.genericContainerIndex);
}

Il2CppGenericMethod il2cpp::vm::GlobalMetadata::BuildGenericMethodFromTokenMethodTuple(const Il2CppTokenIndexMethodTuple* tuple)
{
    return BuildGenericMethodFromIndex(tuple->__genericMethodIndex);
}

static Il2CppMetadataGenericParameterHandle GetGenericParameterFromIndexInternal(GenericParameterIndex index)
{
    if (index == kGenericParameterIndexInvalid)
        return NULL;

    const auto numGenericParameters = s_GlobalMetadataHeader->genericParameters.count;

    IL2CPP_ASSERT(
        index >= 0
        && index < numGenericParameters
    );
    const auto* genericParameters = (const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericParameters.offset;
    const auto serializedSize = s_GlobalMetadataHeader->genericParameters.size / numGenericParameters;
    return reinterpret_cast<Il2CppMetadataGenericParameterHandle>(genericParameters + index * serializedSize);
}

Il2CppMetadataGenericParameterHandle il2cpp::vm::GlobalMetadata::GetGenericParameterFromType(const Il2CppType* type)
{
    IL2CPP_ASSERT(type->type == IL2CPP_TYPE_VAR || type->type == IL2CPP_TYPE_MVAR);
    return type->data.genericParameterHandle;
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetContainerDeclaringType(Il2CppMetadataGenericContainerHandle handle)
{
    const Il2CppGenericContainer* genericContainer = reinterpret_cast<const Il2CppGenericContainer*>(handle);

    if (genericContainer->is_method)
        return GetMethodInfoFromMethodDefinitionIndex(genericContainer->ownerIndex)->klass;

    return GetTypeInfoFromTypeDefinitionIndex(genericContainer->ownerIndex);
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetParameterDeclaringType(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter genericParameter = DeserializeGenericParameter(handle, s_SerializedIndexSizes);

    const Il2CppGenericContainer* genericContainer =  GetGenericContainerFromIndexInternal(genericParameter.ownerIndex);

    if (genericContainer->is_method)
        return GetMethodInfoFromMethodDefinitionIndex(genericContainer->ownerIndex)->klass;

    return GetTypeInfoFromTypeDefinitionIndex(genericContainer->ownerIndex);
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetParameterDeclaringMethod(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter genericParameter = DeserializeGenericParameter(handle, s_SerializedIndexSizes);

    const Il2CppGenericContainer* genericContainer =  GetGenericContainerFromIndexInternal(genericParameter.ownerIndex);

    if (genericContainer->is_method)
        return GetMethodInfoFromMethodDefinitionIndex(genericContainer->ownerIndex);

    return NULL;
}

Il2CppMetadataGenericParameterHandle il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndex(Il2CppMetadataGenericContainerHandle handle, GenericContainerParameterIndex index)
{
    const Il2CppGenericContainer* genericContainer = reinterpret_cast<const Il2CppGenericContainer*>(handle);

    IL2CPP_ASSERT(index >= 0 && index < genericContainer->type_argc);

    return GetGenericParameterFromIndexInternal(genericContainer->genericParameterStart + index);
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetGenericParameterConstraintFromIndex(Il2CppMetadataGenericParameterHandle handle, const GenericParameterConstraintIndex index)
{
    const Il2CppGenericParameter genericParameter = DeserializeGenericParameter(handle, s_SerializedIndexSizes);

    IL2CPP_ASSERT(index >= 0 && index < genericParameter.constraintsCount);

    const auto relativeIndex = genericParameter.constraintsStart + index;
    const auto typeIndexSize = s_SerializedIndexSizes.typeIndex;
    const auto numGenericParameterConstraints = s_GlobalMetadataHeader->genericParameterConstraints.size / typeIndexSize;

    IL2CPP_ASSERT(relativeIndex >= 0 && relativeIndex < numGenericParameterConstraints);
    const auto* constraintIndices = (const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericParameterConstraints.offset;

    return GetIl2CppTypeFromIndex(
        DeserializeIndex<TypeIndex>(constraintIndices + relativeIndex * typeIndexSize, typeIndexSize)
    );
}

static GenericParameterIndex GetIndexForGenericParameter(Il2CppMetadataGenericParameterHandle handle)
{
    const auto numGenericParameters = s_GlobalMetadataHeader->genericParameters.count;
    const auto serializedSize = s_GlobalMetadataHeader->genericParameters.size / numGenericParameters;
    const auto* genericParameter = reinterpret_cast<const char*>(handle);
    const auto* genericParameters = (const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericParameters.offset;

    IL2CPP_ASSERT(
        genericParameter >= genericParameters
        && genericParameter < genericParameters + s_GlobalMetadataHeader->genericParameters.size
    );

    ptrdiff_t index = (genericParameter - genericParameters) / serializedSize;
    IL2CPP_ASSERT(index < numGenericParameters);
    return static_cast<GenericParameterIndex>(index);
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetGenericInstanceMethod(const MethodInfo* genericMethodDefinition, const Il2CppGenericContext* context)
{
    const MethodInfo* method = genericMethodDefinition;
    const Il2CppGenericInst* classInst = context->class_inst;
    const Il2CppGenericInst* methodInst = context->method_inst;
    if (genericMethodDefinition->is_inflated)
    {
        IL2CPP_ASSERT(genericMethodDefinition->klass->generic_class);
        classInst = genericMethodDefinition->klass->generic_class->context.class_inst;
        method = genericMethodDefinition->genericMethod->methodDefinition;
    }

    return il2cpp::metadata::GenericMethod::GetMethod(method, classInst, methodInst);
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetTypeFromRgctxDefinition(const Il2CppRGCTXDefinition* rgctxDef)
{
    IL2CPP_ASSERT(rgctxDef->type == IL2CPP_RGCTX_DATA_TYPE || rgctxDef->type == IL2CPP_RGCTX_DATA_CLASS);
    return GetIl2CppTypeFromIndex(((const Il2CppRGCTXDefinitionData*)rgctxDef->data)->__typeIndex);
}

Il2CppGenericMethod il2cpp::vm::GlobalMetadata::BuildGenericMethodFromRgctxDefinition(const Il2CppRGCTXDefinition* rgctxDef)
{
    IL2CPP_ASSERT(rgctxDef->type == IL2CPP_RGCTX_DATA_METHOD);
    return BuildGenericMethodFromIndex(((const Il2CppRGCTXDefinitionData*)rgctxDef->data)->__methodIndex);
}

std::pair<const Il2CppType*, const MethodInfo*> il2cpp::vm::GlobalMetadata::GetConstrainedCallFromRgctxDefinition(const Il2CppRGCTXDefinition* rgctxDef)
{
    IL2CPP_ASSERT(rgctxDef->type == IL2CPP_RGCTX_DATA_CONSTRAINED);

    const Il2CppRGCTXConstrainedData* constrainedData = (const Il2CppRGCTXConstrainedData*)rgctxDef->data;

    const Il2CppType* type = GetIl2CppTypeFromIndex(constrainedData->__typeIndex);
    const MethodInfo* method = GetMethodInfoFromEncodedIndex(constrainedData->__encodedMethodIndex);
    return std::make_pair(type, method);
}

enum PackingSize
{
    Zero,
    One,
    Two,
    Four,
    Eight,
    Sixteen,
    ThirtyTwo,
    SixtyFour,
    OneHundredTwentyEight
};

static uint8_t ConvertPackingSizeEnumToValue(PackingSize packingSize)
{
    switch (packingSize)
    {
        case Zero:
            return 0;
        case One:
            return 1;
        case Two:
            return 2;
        case Four:
            return 4;
        case Eight:
            return 8;
        case Sixteen:
            return 16;
        case ThirtyTwo:
            return 32;
        case SixtyFour:
            return 64;
        case OneHundredTwentyEight:
            return 128;
        default:
            Assert(0 && "Invalid packing size!");
            return 0;
    }
}

int32_t il2cpp::vm::GlobalMetadata::StructLayoutPack(Il2CppMetadataTypeHandle handle)
{
    const Il2CppTypeDefinition typeDefinition = DeserializeTypeDefinition(handle, s_SerializedIndexSizes);
    return ConvertPackingSizeEnumToValue(static_cast<PackingSize>((typeDefinition.bitfield >> (kSpecifiedPackingSize - 1)) & 0xF));
}

static const Il2CppImage* GetImageForTypeDefinitionIndex(TypeDefinitionIndex index)
{
    for (int32_t imageIndex = 0; imageIndex < s_MetadataImagesCount; imageIndex++)
    {
        const Il2CppImageGlobalMetadata* imageMetadata = s_MetadataImagesTable + imageIndex;
        IL2CPP_ASSERT(index >= 0);
        if (
            index >= imageMetadata->typeStart
            && index < (imageMetadata->typeStart + static_cast<TypeDefinitionIndex>(imageMetadata->image->typeCount))
        )
            return imageMetadata->image;
    }

    IL2CPP_ASSERT(0 && "Failed to find owning image for type definition index");
    return NULL;
}

Il2CppMetadataTypeHandle GetTypeHandle(TypeDefinitionIndex index)
{
    const auto numTypeDefinitions = s_GlobalMetadataHeader->typeDefinitions.count;
    IL2CPP_ASSERT(index >= 0 && index < numTypeDefinitions);
    const auto typeDefinitionSize = s_GlobalMetadataHeader->typeDefinitions.size / numTypeDefinitions;
    const auto* typeDefinitions = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->typeDefinitions.offset;
    return reinterpret_cast<const Il2CppMetadataTypeHandle>(typeDefinitions + index * typeDefinitionSize);
}

static Il2CppClass* FromTypeDefinition(TypeDefinitionIndex index)
{
    const auto typeHandle = GetTypeHandle(index);
    const auto typeDefinition = DeserializeTypeDefinition(typeHandle, s_SerializedIndexSizes);
    const Il2CppTypeDefinitionSizes* typeDefinitionSizes = s_Il2CppMetadataRegistration->typeDefinitionsSizes[index];
    Il2CppClass* typeInfo = (Il2CppClass*)IL2CPP_CALLOC(1, sizeof(Il2CppClass) + (sizeof(VirtualInvokeData) * typeDefinition.vtable_count));
    typeInfo->klass = typeInfo;
    typeInfo->image = GetImageForTypeDefinitionIndex(index);
    typeInfo->name = GetStringFromIndex(typeDefinition.nameIndex);
    typeInfo->namespaze = GetStringFromIndex(typeDefinition.namespaceIndex);
    typeInfo->byval_arg = *il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition.byvalTypeIndex);
    typeInfo->this_arg = typeInfo->byval_arg;
    typeInfo->this_arg.byref = true;
    typeInfo->this_arg.valuetype = 0;
    typeInfo->typeMetadataHandle = typeHandle;
    typeInfo->genericContainerHandle = GetGenericContainerFromIndex(typeDefinition.genericContainerIndex);
    typeInfo->instance_size = typeDefinitionSizes->instance_size;
    typeInfo->actualSize = typeDefinitionSizes->instance_size;     // actualySize is instance_size for compiler generated values
    typeInfo->native_size = typeDefinitionSizes->native_size;
    typeInfo->static_fields_size = typeDefinitionSizes->static_fields_size;
    typeInfo->thread_static_fields_size = typeDefinitionSizes->thread_static_fields_size;
    typeInfo->thread_static_fields_offset = -1;
    typeInfo->flags = typeDefinition.flags;
    typeInfo->enumtype = (typeDefinition.bitfield >> (kBitIsEnum - 1)) & 0x1;
    typeInfo->is_generic = typeDefinition.genericContainerIndex != kGenericContainerIndexInvalid;     // generic if we have a generic container
    typeInfo->has_finalize = (typeDefinition.bitfield >> (kBitHasFinalizer - 1)) & 0x1;
    typeInfo->has_cctor = (typeDefinition.bitfield >> (kBitHasStaticConstructor - 1)) & 0x1;
    typeInfo->cctor_finished_or_no_cctor = !typeInfo->has_cctor;
    typeInfo->is_blittable = (typeDefinition.bitfield >> (kBitIsBlittable - 1)) & 0x1;
    typeInfo->is_import_or_windows_runtime = (typeDefinition.bitfield >> (kBitIsImportOrWindowsRuntime - 1)) & 0x1;
    typeInfo->packingSize = ConvertPackingSizeEnumToValue(static_cast<PackingSize>((typeDefinition.bitfield >> (kPackingSize - 1)) & 0xF));
    typeInfo->is_byref_like = (typeDefinition.bitfield >> (kBitIsByRefLike - 1)) & 0x1;
    typeInfo->method_count = typeDefinition.method_count;
    typeInfo->property_count = typeDefinition.property_count;
    typeInfo->field_count = typeDefinition.field_count;
    typeInfo->event_count = typeDefinition.event_count;
    typeInfo->nested_type_count = typeDefinition.nested_type_count;
    typeInfo->vtable_count = typeDefinition.vtable_count;
    typeInfo->interfaces_count = typeDefinition.interfaces_count;
    typeInfo->interface_offsets_count = typeDefinition.interface_offsets_count;
    typeInfo->token = typeDefinition.token;
    typeInfo->interopData = il2cpp::vm::MetadataCache::GetInteropDataForType(&typeInfo->byval_arg);

    if (typeDefinition.parentIndex != kTypeIndexInvalid)
        typeInfo->parent = il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition.parentIndex));

    if (typeDefinition.declaringTypeIndex != kTypeIndexInvalid)
        typeInfo->declaringType = il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition.declaringTypeIndex));

    typeInfo->castClass = typeInfo->element_class = typeInfo;
    if (typeInfo->enumtype)
    {
        typeInfo->castClass = typeInfo->element_class = il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition.parentIndex));
        typeInfo->parent = il2cpp_defaults.enum_class;
    }

    return typeInfo;
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(TypeIndex index)
{
    if (index == kTypeIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index < s_Il2CppMetadataRegistration->typesCount && "Invalid type index ");

    return s_Il2CppMetadataRegistration->types[index];
}

uint32_t il2cpp::vm::GlobalMetadata::GetGenericContainerCount(Il2CppMetadataGenericContainerHandle handle)
{
    const Il2CppGenericContainer* container = reinterpret_cast<const Il2CppGenericContainer*>(handle);
    return container != NULL ? container->type_argc : 0;
}

void il2cpp::vm::GlobalMetadata::MakeGenericArgType(Il2CppMetadataGenericContainerHandle containerHandle, Il2CppMetadataGenericParameterHandle paramHandle, Il2CppType* arg)
{
    const Il2CppGenericContainer* container = reinterpret_cast<const Il2CppGenericContainer*>(containerHandle);

    arg->type = container->is_method ? IL2CPP_TYPE_MVAR : IL2CPP_TYPE_VAR;
    arg->data.genericParameterHandle = paramHandle;
}

bool il2cpp::vm::GlobalMetadata::GetGenericContainerIsMethod(Il2CppMetadataGenericContainerHandle handle)
{
    const Il2CppGenericContainer* container = reinterpret_cast<const Il2CppGenericContainer*>(handle);
    IL2CPP_ASSERT(container != NULL);
    return container != NULL ? container->is_method : false;
}

int16_t il2cpp::vm::GlobalMetadata::GetGenericConstraintCount(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter genericParameter = DeserializeGenericParameter(handle, s_SerializedIndexSizes);
    return genericParameter.constraintsCount;
}

const char* il2cpp::vm::GlobalMetadata::GetGenericParameterName(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter genericParameter = DeserializeGenericParameter(handle, s_SerializedIndexSizes);
    return GetStringFromIndex(genericParameter.nameIndex);
}

Il2CppGenericParameterInfo il2cpp::vm::GlobalMetadata::GetGenericParameterInfo(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter genericParameter = DeserializeGenericParameter(handle, s_SerializedIndexSizes);

    return {
            reinterpret_cast<Il2CppMetadataGenericContainerHandle>(GetGenericContainerFromIndexInternal(genericParameter.ownerIndex)),
            GetStringFromIndex(genericParameter.nameIndex),
            genericParameter.num,
            genericParameter.flags
    };
}

uint16_t il2cpp::vm::GlobalMetadata::GetGenericParameterFlags(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter genericParameter = DeserializeGenericParameter(handle, s_SerializedIndexSizes);
    return genericParameter.flags;
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromCatchPoint(const Il2CppCatchPoint* cp)
{
    return GetMethodInfoFromMethodDefinitionIndex(cp->__methodDefinitionIndex);
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromSequencePoint(const Il2CppSequencePoint* seqPoint)
{
    return GetMethodInfoFromMethodDefinitionIndex(seqPoint->__methodDefinitionIndex);
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeSourcePair(const Il2CppTypeSourceFilePair* pair)
{
    return GetTypeInfoFromTypeDefinitionIndex(pair->__klassIndex);
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeIndex(TypeIndex index, bool throwOnError)
{
    if (index == kTypeIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index < s_Il2CppMetadataRegistration->typesCount && "Invalid type index ");

    return utils::InitOnce(&s_TypeInfoTable[index], &g_MetadataLock, [index, throwOnError](il2cpp::os::FastAutoLock& _)
    {
        const Il2CppType* type = s_Il2CppMetadataRegistration->types[index];

        Il2CppClass *klass = Class::FromIl2CppType(type, throwOnError);
        if (klass != NULL)
            ClassInlines::InitFromCodegenSlow(klass, throwOnError);
        return klass;
    });
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodHandle(Il2CppMetadataMethodDefinitionHandle handle)
{
    const auto* methods = static_cast<const char*>(s_GlobalMetadata) + s_GlobalMetadataHeader->methods.offset;
    const auto* method = reinterpret_cast<const char*>(handle);
    const auto numMethods = s_GlobalMetadataHeader->methods.count;
    const auto serializedSize = s_GlobalMetadataHeader->methods.size / numMethods;

    const MethodIndex index = static_cast<MethodIndex>((method - methods) / serializedSize);

    IL2CPP_ASSERT(index >= 0 && index < numMethods);

    return GetMethodInfoFromMethodDefinitionIndex(index);
}

#if IL2CPP_ENABLE_NATIVE_STACKTRACES
void il2cpp::vm::GlobalMetadata::GetAllManagedMethods(std::vector<MethodDefinitionKey>& managedMethods)
{
    size_t methodDefinitionsCount = s_GlobalMetadataHeader->methods.count;
    managedMethods.reserve(methodDefinitionsCount + s_Il2CppMetadataRegistration->genericMethodTableCount);

    for (int32_t i = 0; i < s_MetadataImagesCount; i++)
    {
        const Il2CppImageGlobalMetadata* image = s_MetadataImagesTable + i;

        for (size_t j = 0; j < image->image->typeCount; j++)
        {
            const Il2CppTypeDefinition type = DeserializeTypeDefinition(GetTypeHandle(image->typeStart + static_cast<int32_t>(j)), s_SerializedIndexSizes);

            for (uint16_t u = 0; u < type.method_count; u++)
            {
                const Il2CppMetadataMethodDefinitionHandle handle = GetMethodDefinitionFromIndex(type.methodStart + u);
                const Il2CppMethodDefinition methodDefinition = DeserializeMethodDefinition(handle, s_SerializedIndexSizes);
                MethodDefinitionKey currentMethodList;
                currentMethodList.methodHandle = handle;
                currentMethodList.method = il2cpp::vm::MetadataCache::GetMethodPointer(image->image, methodDefinition.token);
                if (currentMethodList.method)
                    managedMethods.push_back(currentMethodList);
            }
        }
    }

    for (int32_t i = 0; i < s_Il2CppMetadataRegistration->genericMethodTableCount; i++)
    {
        const Il2CppGenericMethodFunctionsDefinitions* genericMethodIndices = s_Il2CppMetadataRegistration->genericMethodTable + i;

        MethodDefinitionKey currentMethodList;

        GenericMethodIndex genericMethodIndex = genericMethodIndices->genericMethodIndex;

        IL2CPP_ASSERT(genericMethodIndex < s_Il2CppMetadataRegistration->methodSpecsCount);
        const Il2CppMethodSpec* methodSpec = s_Il2CppMetadataRegistration->methodSpecs + genericMethodIndex;
        currentMethodList.methodHandle = GetMethodDefinitionFromIndex(methodSpec->methodDefinitionIndex);

        IL2CPP_ASSERT(genericMethodIndices->indices.methodIndex < static_cast<int32_t>(s_GlobalMetadata_CodeRegistration->genericMethodPointersCount));
        currentMethodList.method = s_GlobalMetadata_CodeRegistration->genericMethodPointers[genericMethodIndices->indices.methodIndex];

        managedMethods.push_back(currentMethodList);
    }
}

#endif
