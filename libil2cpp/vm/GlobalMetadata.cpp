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
#include "utils/Memory.h"
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

#include "hybridclr/metadata/MetadataUtil.h"
#include "hybridclr/metadata/MetadataModule.h"


static int32_t s_MetadataImagesCount = 0;
static Il2CppImageGlobalMetadata* s_MetadataImagesTable = NULL;

static TypeDefinitionIndex GetIndexForTypeDefinitionInternal(const Il2CppTypeDefinition* typeDefinition);
static GenericParameterIndex GetIndexForGenericParameter(Il2CppMetadataGenericParameterHandle handle);
static const MethodInfo* GetMethodInfoFromEncodedIndex(EncodedMethodIndex methodIndex);

static void* s_GlobalMetadata;
static const Il2CppGlobalMetadataHeader* s_GlobalMetadataHeader;
static const Il2CppGenericMethod** s_GenericMethodTable = NULL;

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

const char* il2cpp::vm::GlobalMetadata::GetStringFromIndex(StringIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetStringFromEncodeIndex(index);
    }
    IL2CPP_ASSERT(index <= s_GlobalMetadataHeader->stringSize);
    return MetadataOffset<const char*>(s_GlobalMetadata, s_GlobalMetadataHeader->stringOffset, index);
}

static const char* GetWindowsRuntimeStringFromIndex(StringIndex index)
{
    IL2CPP_ASSERT(index <= s_GlobalMetadataHeader->windowsRuntimeStringsSize);
    return MetadataOffset<const char*>(s_GlobalMetadata, s_GlobalMetadataHeader->windowsRuntimeStringsOffset, index);
}

const Il2CppMethodDefinition* il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(MethodIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetMethodDefinitionFromIndex(index);
    }
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->methodsSize / sizeof(Il2CppMethodDefinition));
    return MetadataOffset<const Il2CppMethodDefinition*>(s_GlobalMetadata, s_GlobalMetadataHeader->methodsOffset, index);
}


MethodIndex il2cpp::vm::GlobalMetadata::GetMethodIndexFromDefinition(const Il2CppMethodDefinition* methodDef)
{
    if (hybridclr::metadata::IsInterpreterMethod(methodDef))
    {
        return hybridclr::metadata::MetadataModule::GetImage(methodDef)->GetMethodIndexFromDefinition(methodDef);
    }
    return (MethodIndex)(methodDef - MetadataOffset<const Il2CppMethodDefinition*>(s_GlobalMetadata, s_GlobalMetadataHeader->methodsOffset, 0));
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodDefinitionIndex(MethodIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetMethodInfoFromMethodDefinitionIndex(index);
    }
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->methodsSize / sizeof(Il2CppMethodDefinition));

    if (!s_MethodInfoDefinitionTable[index])
    {
        const Il2CppMethodDefinition* methodDefinition = il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromIndex(index);
        Il2CppClass* typeInfo = il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeDefinitionIndex(methodDefinition->declaringType);
        il2cpp::vm::Class::SetupMethods(typeInfo);
        const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(typeInfo->typeMetadataHandle);
        s_MethodInfoDefinitionTable[index] = typeInfo->methods[index - typeDefinition->methodStart];
    }

    return s_MethodInfoDefinitionTable[index];
}

static const Il2CppEventDefinition* GetEventDefinitionFromIndex(const Il2CppImage* image, EventIndex index)
{
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->eventsSize / sizeof(Il2CppEventDefinition));
    const Il2CppEventDefinition* events = (const Il2CppEventDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->eventsOffset);
    return events + index;
}

static const Il2CppPropertyDefinition* GetPropertyDefinitionFromIndex(const Il2CppImage* image, PropertyIndex index)
{
    if (hybridclr::metadata::IsInterpreterImage(image))
    {
        return hybridclr::metadata::MetadataModule::GetImage(image)->GetPropertyDefinitionFromIndex(hybridclr::metadata::DecodeMetadataIndex(index));
    }
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->propertiesSize / sizeof(Il2CppPropertyDefinition));
    const Il2CppPropertyDefinition* properties = (const Il2CppPropertyDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->propertiesOffset);
    return properties + index;
}

const Il2CppParameterDefinition* il2cpp::vm::GlobalMetadata::GetParameterDefinitionFromIndex(const Il2CppClass* klass, ParameterIndex index)
{
    if (hybridclr::metadata::IsInterpreterType(klass))
    {
        return hybridclr::metadata::MetadataModule::GetParameterDefinitionFromIndex(klass->image, index);
    }
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->parametersSize / sizeof(Il2CppParameterDefinition));    const Il2CppParameterDefinition* parameters = (const Il2CppParameterDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->parametersOffset);
    return parameters + index;
}


const Il2CppParameterDefinition* il2cpp::vm::GlobalMetadata::GetParameterDefinitionFromIndex(const Il2CppMethodDefinition* methodDef, ParameterIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(methodDef->nameIndex))
    {
        return hybridclr::metadata::MetadataModule::GetParameterDefinitionFromIndex(hybridclr::metadata::MetadataModule::GetImage(methodDef)->GetIl2CppImage(), index);
    }
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->parametersSize / sizeof(Il2CppParameterDefinition));
    const Il2CppParameterDefinition* parameters = (const Il2CppParameterDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->parametersOffset);
    return parameters + index;
}

static const Il2CppMethodDefinition* GetMethodDefinitionFromEncodedIndex(EncodedMethodIndex methodIndex)
{
    const MethodInfo* method = GetMethodInfoFromEncodedIndex(methodIndex);
    if (!method)
    {
        return nullptr;
    }
    if (method->is_inflated)
    {
        method = method->genericMethod->methodDefinition;
    }
    return (const Il2CppMethodDefinition *)method->methodMetadataHandle;
}

uint8_t il2cpp::vm::GlobalMetadata::ConvertPackingSizeEnumToValue(PackingSize packingSize)
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

il2cpp::vm::PackingSize il2cpp::vm::GlobalMetadata::ConvertPackingSizeToEnum(uint8_t packingSize)
{
    switch (packingSize)
    {
    case 0:
        return PackingSize::Zero;
    case 1:
        return PackingSize::One;
    case 2:
        return PackingSize::Two;
    case 4:
        return PackingSize::Four;
    case 8:
        return PackingSize::Eight;
    case 16:
        return PackingSize::Sixteen;
    case 32:
        return PackingSize::ThirtyTwo;
    case 64:
        return PackingSize::SixtyFour;
    case 128:
        return OneHundredTwentyEight;
    default:
        Assert(0 && "Invalid packing size!");
        return PackingSize::Zero;
    }
}

static const Il2CppGenericMethod* GetGenericMethodFromIndex(GenericMethodIndex index)
{
    IL2CPP_ASSERT(index < s_Il2CppMetadataRegistration->methodSpecsCount);
    if (s_GenericMethodTable[index])
        return s_GenericMethodTable[index];

    const Il2CppMethodSpec* methodSpec = s_Il2CppMetadataRegistration->methodSpecs + index;
    const MethodInfo* methodDefinition = il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodDefinitionIndex(methodSpec->methodDefinitionIndex);
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
    s_GenericMethodTable[index] = il2cpp::vm::MetadataCache::GetGenericMethod(methodDefinition, classInst, methodInst);

    return s_GenericMethodTable[index];
}

static const MethodInfo* GetMethodInfoFromEncodedIndex(EncodedMethodIndex methodIndex)
{
    Il2CppMetadataUsage usage = GetEncodedIndexType(methodIndex);

    uint32_t index = GetDecodedMethodIndex(methodIndex);

    switch (GetEncodedIndexType(methodIndex))
    {
        case kIl2CppMetadataUsageMethodRef:
            return il2cpp::metadata::GenericMethod::GetMethod(GetGenericMethodFromIndex(index));
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

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) < s_GlobalMetadataHeader->stringLiteralSize / sizeof(Il2CppStringLiteral) && "Invalid string literal index ");

    if (s_StringLiteralTable[index])
        return s_StringLiteralTable[index];

    const Il2CppStringLiteral* stringLiteral = (const Il2CppStringLiteral*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->stringLiteralOffset) + index;
    Il2CppString* newString = il2cpp::vm::String::NewLen((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->stringLiteralDataOffset + stringLiteral->dataIndex, stringLiteral->length);
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
    IL2CPP_ASSERT(s_GlobalMetadataHeader->fieldRefsSize >= 0 && index <= static_cast<uint32_t>(s_GlobalMetadataHeader->fieldRefsSize / sizeof(Il2CppFieldRef)));

    const Il2CppFieldRef* fieldRef = MetadataOffset<const Il2CppFieldRef*>(s_GlobalMetadata, s_GlobalMetadataHeader->fieldRefsOffset, index);
    const Il2CppClass* typeInfo = il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeIndex(fieldRef->typeIndex);
    return typeInfo->fields + fieldRef->fieldIndex;
}

void il2cpp::vm::GlobalMetadata::Register(const Il2CppCodeRegistration* const codeRegistration, const Il2CppMetadataRegistration* const metadataRegistration, const Il2CppCodeGenOptions* const codeGenOptions)
{
    s_GlobalMetadata_CodeRegistration = codeRegistration;
    s_Il2CppMetadataRegistration = metadataRegistration;
}

typedef void (*Il2CppTypeUpdater)(Il2CppType*);

void il2cpp::vm::GlobalMetadata::InitializeTypeHandle(Il2CppType* type)
{
    type->data.typeHandle = il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(type->data.__klassIndex);
}

static void ClearTypeHandle(Il2CppType* type)
{
    type->data.__klassIndex = GetIndexForTypeDefinitionInternal(reinterpret_cast<const Il2CppTypeDefinition*>(type->data.typeHandle));
}

static void InitializeGenericParameterHandle(Il2CppType* type)
{
    type->data.genericParameterHandle = il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndexInternal(type->data.__genericParameterIndex);
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
    IL2CPP_ASSERT(s_GlobalMetadataHeader->version == 29);
    IL2CPP_ASSERT(s_GlobalMetadataHeader->stringLiteralOffset == sizeof(Il2CppGlobalMetadataHeader));

    s_MetadataImagesCount = *imagesCount = s_GlobalMetadataHeader->imagesSize / sizeof(Il2CppImageDefinition);
    *assembliesCount = s_GlobalMetadataHeader->assembliesSize / sizeof(Il2CppAssemblyDefinition);

    // Pre-allocate these arrays so we don't need to lock when reading later.
    // These arrays hold the runtime metadata representation for metadata explicitly
    // referenced during conversion. There is a corresponding table of same size
    // in the converted metadata, giving a description of runtime metadata to construct.
    s_MetadataImagesTable = (Il2CppImageGlobalMetadata*)IL2CPP_CALLOC(s_MetadataImagesCount, sizeof(Il2CppImageGlobalMetadata));
    s_TypeInfoTable = (Il2CppClass**)IL2CPP_CALLOC(s_Il2CppMetadataRegistration->typesCount, sizeof(Il2CppClass*));
    s_TypeInfoDefinitionTable = (Il2CppClass**)IL2CPP_CALLOC(s_GlobalMetadataHeader->typeDefinitionsSize / sizeof(Il2CppTypeDefinition), sizeof(Il2CppClass*));
    s_MethodInfoDefinitionTable = (const MethodInfo**)IL2CPP_CALLOC(s_GlobalMetadataHeader->methodsSize / sizeof(Il2CppMethodDefinition), sizeof(MethodInfo*));
    s_GenericMethodTable = (const Il2CppGenericMethod**)IL2CPP_CALLOC(s_Il2CppMetadataRegistration->methodSpecsCount, sizeof(Il2CppGenericMethod*));

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

    il2cpp::os::Atomic::ExchangePointer((void**)metadataPointer, initialized);

    return initialized;
}

void il2cpp::vm::GlobalMetadata::InitializeStringLiteralTable()
{
    s_StringLiteralTable = (Il2CppString**)il2cpp::gc::GarbageCollector::AllocateFixed(s_GlobalMetadataHeader->stringLiteralSize / sizeof(Il2CppStringLiteral) * sizeof(Il2CppString*), NULL);
}

void il2cpp::vm::GlobalMetadata::InitializeWindowsRuntimeTypeNamesTables(WindowsRuntimeTypeNameToClassMap& windowsRuntimeTypeNameToClassMap, ClassToWindowsRuntimeTypeNameMap& classToWindowsRuntimeTypeNameMap)
{
    int32_t typeCount = s_GlobalMetadataHeader->windowsRuntimeTypeNamesSize / sizeof(Il2CppWindowsRuntimeTypeNamePair);
    const Il2CppWindowsRuntimeTypeNamePair* windowsRuntimeTypeNames = MetadataOffset<Il2CppWindowsRuntimeTypeNamePair*>(s_GlobalMetadata, s_GlobalMetadataHeader->windowsRuntimeTypeNamesOffset, 0);

    windowsRuntimeTypeNameToClassMap.resize(typeCount / 2 + 1);
    classToWindowsRuntimeTypeNameMap.resize(typeCount);

    for (int32_t i = 0; i < typeCount; i++)
    {
        Il2CppWindowsRuntimeTypeNamePair typeNamePair = windowsRuntimeTypeNames[i];
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

    for (uint32_t i = 0; i < s_GlobalMetadata_CodeRegistration->unresolvedIndirectCallCount; ++i)
    {
        const Il2CppMetadataRange* range = MetadataOffset<Il2CppMetadataRange*>(s_GlobalMetadata, s_GlobalMetadataHeader->unresolvedIndirectCallParameterRangesOffset, i);
        il2cpp::metadata::Il2CppSignature signature;
        signature.Count = range->length;
        signature.Types = (const Il2CppType**)MetadataMalloc(range->length * sizeof(Il2CppType*));

        for (int j = 0; j < range->length; ++j)
        {
            TypeIndex typeIndex = *MetadataOffset<TypeIndex*>(s_GlobalMetadata, s_GlobalMetadataHeader->unresolvedIndirectCallParameterTypesOffset, range->start + j);
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
        const Il2CppGenericMethod* genericMethod = GetGenericMethodFromIndex(genericMethodIndices->genericMethodIndex);
        methodTableMap.insert(std::make_pair(genericMethod, &genericMethodIndices->indices));
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
    FreeAndNull((void**)&s_GenericMethodTable);
    FreeAndNull((void**)&s_TypeInfoTable);
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
    const Il2CppImageDefinition* imagesDefinitions = (const Il2CppImageDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->imagesOffset);

    const Il2CppImageDefinition* imageDefinition = imagesDefinitions + imageIndex;

    image->name = GetStringFromIndex(imageDefinition->nameIndex);

    *imageAssemblyIndex = imageDefinition->assemblyIndex;
    image->typeCount = imageDefinition->typeCount;
    image->exportedTypeCount = imageDefinition->exportedTypeCount;
    image->token = imageDefinition->token;
    image->customAttributeCount = imageDefinition->customAttributeCount;

    Il2CppImageGlobalMetadata* metadataImage = s_MetadataImagesTable + imageIndex;
    metadataImage->typeStart = imageDefinition->typeStart;
    metadataImage->customAttributeStart = imageDefinition->customAttributeStart;
    metadataImage->entryPointIndex = imageDefinition->entryPointIndex;
    metadataImage->exportedTypeStart = imageDefinition->exportedTypeStart;
    metadataImage->image = image;

    image->metadataHandle = reinterpret_cast<Il2CppMetadataImageHandle>(metadataImage);
}

void il2cpp::vm::GlobalMetadata::BuildIl2CppAssembly(Il2CppAssembly* assembly, AssemblyIndex assemblyIndex, ImageIndex* assemblyImageIndex)
{
    const Il2CppAssemblyDefinition* assemblyDefinitions = (const Il2CppAssemblyDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->assembliesOffset);
    const Il2CppAssemblyDefinition* assemblyDefinition = assemblyDefinitions + assemblyIndex;

    assembly->token = assemblyDefinition->token;
    assembly->referencedAssemblyStart = assemblyDefinition->referencedAssemblyStart;
    assembly->referencedAssemblyCount = assemblyDefinition->referencedAssemblyCount;

    Il2CppAssemblyName* assemblyName = &assembly->aname;
    const Il2CppAssemblyNameDefinition* assemblyNameDefinition = &assemblyDefinition->aname;

    Il2CppImage* image = il2cpp::vm::MetadataCache::GetImageFromIndex(assemblyDefinition->imageIndex);
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
    if (hybridclr::metadata::IsInterpreterIndex(image->token))
    {
        return hybridclr::metadata::MetadataModule::GetAssemblyTypeHandleFromRawIndex(image, index);
    }

    const Il2CppImageGlobalMetadata* imageMetadata = GetImageMetadata(image);

    IL2CPP_ASSERT(index >= 0 && index < static_cast<AssemblyTypeIndex>(image->typeCount));
    TypeDefinitionIndex typeDefintionIndex = imageMetadata->typeStart + index;
    return GetTypeHandleFromIndex(typeDefintionIndex);
}

const Il2CppAssembly* il2cpp::vm::GlobalMetadata::GetReferencedAssembly(const Il2CppAssembly* assembly, int32_t referencedAssemblyTableIndex, const Il2CppAssembly assembliesTable[], int assembliesCount)
{
    IL2CPP_ASSERT(referencedAssemblyTableIndex < assembly->referencedAssemblyCount);
    if (hybridclr::metadata::IsInterpreterImage(assembly->image))
    {
        return hybridclr::metadata::MetadataModule::GetImage(assembly->image)->GetReferencedAssembly(referencedAssemblyTableIndex, assembliesTable, assembliesCount);
    }

    referencedAssemblyTableIndex = assembly->referencedAssemblyStart + referencedAssemblyTableIndex;

    IL2CPP_ASSERT(referencedAssemblyTableIndex >= 0 && static_cast<uint32_t>(referencedAssemblyTableIndex) <= s_GlobalMetadataHeader->referencedAssembliesSize / sizeof(int32_t));
    const int32_t* referenceAssemblyIndicies = (const int32_t*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->referencedAssembliesOffset);
    return assembliesTable + referenceAssemblyIndicies[referencedAssemblyTableIndex];
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetAssemblyExportedTypeHandle(const Il2CppImage* image, AssemblyExportedTypeIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetAssemblyExportedTypeHandleFromEncodeIndex(index);
    }

    if (index == kTypeDefinitionIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index >= 0 && index < static_cast<AssemblyExportedTypeIndex>(image->exportedTypeCount));

    const Il2CppImageGlobalMetadata* imageMetadata = GetImageMetadata(image);

    int32_t exportedTypeIndex = imageMetadata->exportedTypeStart + index;

    IL2CPP_ASSERT(exportedTypeIndex >= 0 && static_cast<uint32_t>(exportedTypeIndex) < s_GlobalMetadataHeader->exportedTypeDefinitionsSize / sizeof(TypeDefinitionIndex));
    TypeDefinitionIndex* exportedTypes = (TypeDefinitionIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->exportedTypeDefinitionsOffset);
    TypeDefinitionIndex typeDefintionIndex =  *(exportedTypes + exportedTypeIndex);

    return GetTypeHandleFromIndex(typeDefintionIndex);
}

static const Il2CppTypeDefinition* GetTypeDefinitionForIndex(TypeDefinitionIndex index)
{
    if (index == kTypeDefinitionIndexInvalid)
        return NULL;
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return (const Il2CppTypeDefinition*)hybridclr::metadata::MetadataModule::GetAssemblyTypeHandleFromEncodeIndex(index);
    }

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) < s_GlobalMetadataHeader->typeDefinitionsSize / sizeof(Il2CppTypeDefinition));
    const Il2CppTypeDefinition* typeDefinitions = (const Il2CppTypeDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->typeDefinitionsOffset);
    return typeDefinitions + index;
}

static TypeDefinitionIndex GetIndexForTypeDefinitionInternal(const Il2CppTypeDefinition* typeDefinition)
{
    IL2CPP_ASSERT(typeDefinition);
    if (hybridclr::metadata::IsInterpreterType(typeDefinition))
    {
        return static_cast<TypeDefinitionIndex>(hybridclr::metadata::MetadataModule::GetTypeEncodeIndex(typeDefinition));
    }

    const Il2CppTypeDefinition* typeDefinitions = (const Il2CppTypeDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->typeDefinitionsOffset);

    IL2CPP_ASSERT(typeDefinition >= typeDefinitions && typeDefinition < typeDefinitions + s_GlobalMetadataHeader->typeDefinitionsSize / sizeof(Il2CppTypeDefinition));

    ptrdiff_t index = typeDefinition - typeDefinitions;
    IL2CPP_ASSERT(index <= std::numeric_limits<TypeDefinitionIndex>::max());
    return static_cast<TypeDefinitionIndex>(index);
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeDefinitionIndex(TypeDefinitionIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetTypeInfoFromTypeDefinitionEncodeIndex(index);
    }
    if (index == kTypeIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) < s_GlobalMetadataHeader->typeDefinitionsSize / sizeof(Il2CppTypeDefinition));

    if (!s_TypeInfoDefinitionTable[index])
    {
        // we need to use the metadata lock, since we may need to retrieve other Il2CppClass's when setting. Our parent may be a generic instance for example
        il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);
        // double checked locking
        if (!s_TypeInfoDefinitionTable[index])
            s_TypeInfoDefinitionTable[index] = FromTypeDefinition(index);
    }

    return s_TypeInfoDefinitionTable[index];
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle(Il2CppMetadataTypeHandle handle)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(handle);
    return GetTypeInfoFromTypeDefinitionIndex(GetIndexForTypeDefinitionInternal(typeDefinition));
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetTypeInfoFromType(const Il2CppType* type)
{
    return GetTypeInfoFromHandle(type->data.typeHandle);
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetInterfaceFromOffset(const Il2CppClass* klass, TypeInterfaceIndex offset)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);

    return GetInterfaceFromOffset(typeDefinition, offset);
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetInterfaceFromOffset(const Il2CppTypeDefinition* typeDefinition, TypeInterfaceIndex offset)
{
    IL2CPP_ASSERT(offset >= 0 && offset < typeDefinition->interfaces_count);
    if (hybridclr::metadata::IsInterpreterType(typeDefinition))
    {
        return hybridclr::metadata::MetadataModule::GetInterfaceFromOffset(typeDefinition, offset);
    }

    InterfacesIndex index = typeDefinition->interfacesStart + offset;

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->interfacesSize / sizeof(TypeIndex));
    const TypeIndex* interfaceIndices = (const TypeIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->interfacesOffset);

    return GetIl2CppTypeFromIndex(interfaceIndices[index]);
}

Il2CppInterfaceOffsetInfo il2cpp::vm::GlobalMetadata::GetInterfaceOffsetInfo(const Il2CppClass* klass, TypeInterfaceOffsetIndex index)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);
    return GetInterfaceOffsetInfo(typeDefinition, index);
}

Il2CppInterfaceOffsetInfo il2cpp::vm::GlobalMetadata::GetInterfaceOffsetInfo(const Il2CppTypeDefinition* typeDefine, TypeInterfaceOffsetIndex index)
{
    IL2CPP_ASSERT(index >= 0 && index < typeDefine->interface_offsets_count);

    if (hybridclr::metadata::IsInterpreterType(typeDefine))
    {
        return hybridclr::metadata::MetadataModule::GetInterfaceOffsetInfo(typeDefine, index);
    }

    index = index + typeDefine->interfaceOffsetsStart;
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->interfaceOffsetsSize / sizeof(Il2CppInterfaceOffsetPair));
    const Il2CppInterfaceOffsetPair* interfaceOffsets = (const Il2CppInterfaceOffsetPair*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->interfaceOffsetsOffset);

    return
        {
            GetIl2CppTypeFromIndex(interfaceOffsets[index].interfaceTypeIndex),
            interfaceOffsets[index].offset
        };
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(TypeDefinitionIndex typeIndex)
{
    return reinterpret_cast<Il2CppMetadataTypeHandle>(GetTypeDefinitionForIndex(typeIndex));
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetTypeHandleFromType(const Il2CppType* type)
{
    IL2CPP_ASSERT(type->type == IL2CPP_TYPE_CLASS || type->type == IL2CPP_TYPE_VALUETYPE);
    return type->data.typeHandle;
}

bool il2cpp::vm::GlobalMetadata::TypeIsNested(Il2CppMetadataTypeHandle handle)
{
    return reinterpret_cast<const Il2CppTypeDefinition*>(handle)->declaringTypeIndex != kTypeIndexInvalid;
}

bool il2cpp::vm::GlobalMetadata::TypeIsValueType(Il2CppMetadataTypeHandle handle)
{
    return (reinterpret_cast<const Il2CppTypeDefinition*>(handle)->bitfield >> (kBitIsValueType - 1)) & 0x1;
}

bool il2cpp::vm::GlobalMetadata::StructLayoutPackIsDefault(Il2CppMetadataTypeHandle handle)
{
    return (reinterpret_cast<const Il2CppTypeDefinition*>(handle)->bitfield >> (kPackingSizeIsDefault - 1)) & 0x1;
}

bool il2cpp::vm::GlobalMetadata::StructLayoutSizeIsDefault(Il2CppMetadataTypeHandle handle)
{
    return (reinterpret_cast<const Il2CppTypeDefinition*>(handle)->bitfield >> (kClassSizeIsDefault - 1)) & 0x1;
}

std::pair<const char*, const char*> il2cpp::vm::GlobalMetadata::GetTypeNamespaceAndName(Il2CppMetadataTypeHandle handle)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(handle);
    return std::make_pair
        (
        GetStringFromIndex(typeDefinition->namespaceIndex),
        GetStringFromIndex(typeDefinition->nameIndex)
        );
}

Il2CppClass* il2cpp::vm::GlobalMetadata::GetNestedTypeFromOffset(const Il2CppClass* klass, TypeNestedTypeIndex offset)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);

    IL2CPP_ASSERT(offset >= 0 && offset < typeDefinition->nested_type_count);

    if (hybridclr::metadata::IsInterpreterType(klass))
    {
        return hybridclr::metadata::MetadataModule::GetNestedTypeFromOffset(klass, offset);
    }

    NestedTypeIndex index = typeDefinition->nestedTypesStart + offset;

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->nestedTypesSize / sizeof(TypeDefinitionIndex));

    const TypeDefinitionIndex* nestedTypeIndices = (const TypeDefinitionIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->nestedTypesOffset);

    return GetTypeInfoFromTypeDefinitionIndex(nestedTypeIndices[index]);
}

Il2CppMetadataTypeHandle il2cpp::vm::GlobalMetadata::GetNestedTypes(Il2CppMetadataTypeHandle handle, void** iter)
{
    if (!iter)
        return NULL;

    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(handle);
    if (hybridclr::metadata::IsInterpreterType(typeDefinition))
    {
        return hybridclr::metadata::MetadataModule::GetNestedTypes(handle, iter);
    }

    const TypeDefinitionIndex* nestedTypeIndices = (const TypeDefinitionIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->nestedTypesOffset);

    if (!*iter)
    {
        if (typeDefinition->nested_type_count == 0)
            return NULL;

        *iter = (void*)(nestedTypeIndices + typeDefinition->nestedTypesStart);
        return GetTypeHandleFromIndex(nestedTypeIndices[typeDefinition->nestedTypesStart]);
    }

    TypeDefinitionIndex* nestedTypeAddress = (TypeDefinitionIndex*)*iter;
    nestedTypeAddress++;
    ptrdiff_t index = nestedTypeAddress - nestedTypeIndices;

    if (index < typeDefinition->nestedTypesStart + typeDefinition->nested_type_count)
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
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return reinterpret_cast<const Il2CppImageGlobalMetadata*>(hybridclr::metadata::MetadataModule::GetImageByEncodedIndex(index)->GetIl2CppImage()->metadataHandle);
    }

    for (int32_t imageIndex = 0; imageIndex < s_MetadataImagesCount; imageIndex++)
    {
        const Il2CppImageGlobalMetadata* imageMetadta = s_MetadataImagesTable + imageIndex;
        IL2CPP_ASSERT(index >= 0);
        if (index >= imageMetadta->customAttributeStart && static_cast<uint32_t>(index) < (imageMetadta->customAttributeStart + imageMetadta->image->customAttributeCount))
            return imageMetadta;
    }

    IL2CPP_ASSERT(0 && "Failed to find owning image for custom attribute index");
    return NULL;
}

static CustomAttributeIndex GetCustomAttributeIndex(const Il2CppCustomAttributeDataRange* attrDataRange)
{
    if (attrDataRange == NULL)
        return kCustomAttributeIndexInvalid;

    if (hybridclr::metadata::IsInterpreterIndex(GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(*attrDataRange)))
    {
        return hybridclr::metadata::MetadataModule::GetImage(hybridclr::metadata::DecodeImageIndex(GET_CUSTOM_ATTRIBUTE_TYPE_RANGE_START(*attrDataRange)))
            ->GetCustomAttributeIndex(attrDataRange->token);
    }

    const Il2CppCustomAttributeDataRange* attributeTypeRangeStart = MetadataOffset<const Il2CppCustomAttributeDataRange*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeDataRangeOffset, 0);
    CustomAttributeIndex index = (CustomAttributeIndex)(attrDataRange - attributeTypeRangeStart);

    IL2CPP_ASSERT(index >= 0 && index < (CustomAttributeIndex)(s_GlobalMetadataHeader->attributeDataRangeSize / sizeof(Il2CppCustomAttributeDataRange)));

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
    if (hybridclr::metadata::IsInterpreterImage(image))
    {
        return hybridclr::metadata::MetadataModule::GetImage(image)->GetCustomAttributeTypeToken(token);
    }
    const Il2CppCustomAttributeDataRange* attributeTypeRange = MetadataOffset<const Il2CppCustomAttributeDataRange*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeDataRangeOffset, 0);
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

    if (hybridclr::metadata::IsInterpreterImage(image))
    {
        return hybridclr::metadata::MetadataModule::GetImage(image)->CreateCustomAttributeDataReader(handle);
    }
    Il2CppCustomAttributeDataRange* range = (Il2CppCustomAttributeDataRange*)handle;
    const Il2CppCustomAttributeDataRange* next = range + 1;

    void* start = MetadataOffset<uint8_t*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeDataOffset, range->startOffset);
    void* end = MetadataOffset<uint8_t*>(s_GlobalMetadata, s_GlobalMetadataHeader->attributeDataOffset, next->startOffset);

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

const Il2CppMethodDefinition* il2cpp::vm::GlobalMetadata::GetMethodDefinitionFromVTableSlot(const Il2CppTypeDefinition* typeDefinition, int32_t vTableSlot)
{
    if (hybridclr::metadata::IsInterpreterType(typeDefinition))
    {
        return hybridclr::metadata::MetadataModule::GetMethodDefinitionFromVTableSlot(typeDefinition, vTableSlot);
    }

    uint32_t index = typeDefinition->vtableStart + vTableSlot;
    IL2CPP_ASSERT(index >= 0 && index <= s_GlobalMetadataHeader->vtableMethodsSize / sizeof(EncodedMethodIndex));
    const EncodedMethodIndex* vTableMethodReferences = (const EncodedMethodIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->vtableMethodsOffset);
    EncodedMethodIndex vTableMethodReference = vTableMethodReferences[index];

    if (vTableMethodReference == 0)
    {
        return nullptr;
    }

    IL2CPP_ASSERT(vTableMethodReference != 0);

    return GetMethodDefinitionFromEncodedIndex(vTableMethodReference);
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromVTableSlot(const Il2CppClass* klass, int32_t vTableSlot)
{
    if (hybridclr::metadata::IsInterpreterType(klass))
    {
        return hybridclr::metadata::MetadataModule::GetMethodInfoFromVTableSlot(klass, vTableSlot);
    }
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);

    uint32_t index = typeDefinition->vtableStart + vTableSlot;
    IL2CPP_ASSERT(index >= 0 && index <= s_GlobalMetadataHeader->vtableMethodsSize / sizeof(EncodedMethodIndex));
    const EncodedMethodIndex* vTableMethodReferences = (const EncodedMethodIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->vtableMethodsOffset);
    EncodedMethodIndex vTableMethodReference = vTableMethodReferences[index];
    return GetMethodInfoFromEncodedIndex(vTableMethodReference);
}

static int CompareFieldDefaultValues(const void* pkey, const void* pelem)
{
    return (int)(((Il2CppFieldDefaultValue*)pkey)->fieldIndex - ((Il2CppFieldDefaultValue*)pelem)->fieldIndex);
}

static const Il2CppFieldDefaultValue* GetFieldDefaultValueEntry(const FieldInfo* field)
{
    Il2CppClass* parent = field->parent;
    FieldIndex fieldIndex = (FieldIndex)(field - parent->fields);

    if (il2cpp::vm::Type::IsGenericInstance(&parent->byval_arg))
        parent = il2cpp::vm::GenericClass::GetTypeDefinition(parent->generic_class);

    fieldIndex += reinterpret_cast<const Il2CppTypeDefinition*>(parent->typeMetadataHandle)->fieldStart;

    if (hybridclr::metadata::IsInterpreterIndex((uint32_t)fieldIndex))
    {
        return hybridclr::metadata::MetadataModule::GetFieldDefaultValueEntry((uint32_t)fieldIndex);
    }

    Il2CppFieldDefaultValue key;
    key.fieldIndex = fieldIndex;

    const Il2CppFieldDefaultValue* start = (const Il2CppFieldDefaultValue*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->fieldDefaultValuesOffset);
    const Il2CppFieldDefaultValue* res = (const Il2CppFieldDefaultValue*)bsearch(&key, start, s_GlobalMetadataHeader->fieldDefaultValuesSize / sizeof(Il2CppFieldDefaultValue), sizeof(Il2CppFieldDefaultValue), CompareFieldDefaultValues);
    return res;
}

static const uint8_t* GetFieldOrParameterDefalutValue(uint32_t index)
{
    if (index == kDefaultValueIndexNull)
        return NULL;
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetFieldOrParameterDefalutValue(index);
    }

    IL2CPP_ASSERT(index >= 0 && index <= s_GlobalMetadataHeader->fieldAndParameterDefaultValueDataSize / sizeof(uint8_t));
    const uint8_t* defaultValuesData =  (const uint8_t*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->fieldAndParameterDefaultValueDataOffset);
    return defaultValuesData + index;
}

const uint8_t* il2cpp::vm::GlobalMetadata::GetFieldDefaultValue(const FieldInfo* field, const Il2CppType** type)
{
    const Il2CppFieldDefaultValue* entry = GetFieldDefaultValueEntry(field);

    if (entry != NULL)
    {
        *type = GetIl2CppTypeFromIndex(entry->typeIndex);
        return GetFieldOrParameterDefalutValue(entry->dataIndex);
    }

    return NULL;
}

static int CompareParameterDefaultValues(const void* pkey, const void* pelem)
{
    return (int)(((Il2CppParameterDefaultValue*)pkey)->parameterIndex - ((Il2CppParameterDefaultValue*)pelem)->parameterIndex);
}

static const Il2CppParameterDefaultValue * GetParameterDefaultValueEntry(const MethodInfo* method, int32_t parameterPosition)
{
    if (il2cpp::vm::Method::IsGenericInstance(method))
        method = il2cpp::vm::MetadataCache::GetGenericMethodDefinition(method);

    IL2CPP_ASSERT(!il2cpp::vm::Method::IsGenericInstance(method));

    const Il2CppMethodDefinition* methodDefinition = reinterpret_cast<const Il2CppMethodDefinition*>(method->methodMetadataHandle);
    if (methodDefinition == NULL)
        return NULL;

    ParameterIndex parameterIndex = methodDefinition->parameterStart + parameterPosition;
    if (hybridclr::metadata::IsInterpreterMethod(method))
    {
        return hybridclr::metadata::MetadataModule::GetImage(method->klass)
            ->GetParameterDefaultValueEntryByRawIndex(parameterIndex);
    }
    Il2CppParameterDefaultValue key;
    key.parameterIndex = parameterIndex;

    const Il2CppParameterDefaultValue* start = (const Il2CppParameterDefaultValue*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->parameterDefaultValuesOffset);
    const Il2CppParameterDefaultValue* res = (const Il2CppParameterDefaultValue*)bsearch(&key, start, s_GlobalMetadataHeader->parameterDefaultValuesSize / sizeof(Il2CppParameterDefaultValue), sizeof(Il2CppParameterDefaultValue), CompareParameterDefaultValues);
    return res;
}

const uint8_t* il2cpp::vm::GlobalMetadata::GetParameterDefaultValue(const MethodInfo* method, int32_t parameterPosition, const Il2CppType** type, bool* isExplicitySetNullDefaultValue)
{
    *isExplicitySetNullDefaultValue = false;
    const Il2CppParameterDefaultValue* parameterDefaultValue = GetParameterDefaultValueEntry(method, parameterPosition);

    if (parameterDefaultValue != NULL)
    {
        *type = GetIl2CppTypeFromIndex(parameterDefaultValue->typeIndex);
        *isExplicitySetNullDefaultValue = parameterDefaultValue->dataIndex == kDefaultValueIndexNull;
        return GetFieldOrParameterDefalutValue(parameterDefaultValue->dataIndex);
    }

    return NULL;
}

TypeDefinitionIndex il2cpp::vm::GlobalMetadata::GetIndexForTypeDefinition(const Il2CppClass* klass)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);
    return GetIndexForTypeDefinitionInternal(typeDefinition);
}

uint32_t il2cpp::vm::GlobalMetadata::GetFieldOffset(const Il2CppClass* klass, int32_t fieldIndexInType, FieldInfo* field)
{
    if (hybridclr::metadata::IsInterpreterType(klass))
    {
        return hybridclr::metadata::MetadataModule::GetFieldOffset(klass, fieldIndexInType, field);
    }
    uint32_t typeIndex = GetIndexForTypeDefinition(klass);
    IL2CPP_ASSERT(typeIndex <= static_cast<uint32_t>(s_Il2CppMetadataRegistration->typeDefinitionsSizesCount));
    int32_t offset = s_Il2CppMetadataRegistration->fieldOffsets[typeIndex][fieldIndexInType];
    return offset;
}

int il2cpp::vm::GlobalMetadata::GetFieldMarshaledSizeForField(const FieldInfo* field)
{
    Il2CppClass* parent = field->parent;
    size_t fieldIndex = (field - parent->fields);
    fieldIndex += reinterpret_cast<const Il2CppTypeDefinition*>(parent->typeMetadataHandle)->fieldStart;

    const Il2CppFieldMarshaledSize *start = (const Il2CppFieldMarshaledSize*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->fieldMarshaledSizesOffset);
    const Il2CppFieldMarshaledSize *entry = start;
    while (entry < start + s_GlobalMetadataHeader->fieldMarshaledSizesSize / sizeof(Il2CppFieldMarshaledSize))
    {
        if (fieldIndex == entry->fieldIndex)
            return entry->size;
        entry++;
    }

    return -1;
}

static const Il2CppFieldDefinition* GetFieldDefinitionFromIndex(FieldIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetFieldDefinitionFromEncodeIndex(index);
    }
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->fieldsSize / sizeof(Il2CppFieldDefinition));    const Il2CppFieldDefinition* fields = (const Il2CppFieldDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->fieldsOffset);
    return fields + index;
}

const Il2CppFieldDefinition* il2cpp::vm::GlobalMetadata::GetFieldDefinitionFromTypeDefAndFieldIndex(const Il2CppTypeDefinition* typeDef, FieldIndex index)
{
    return GetFieldDefinitionFromIndex(typeDef->fieldStart + index);
}

Il2CppMetadataFieldInfo il2cpp::vm::GlobalMetadata::GetFieldInfo(const Il2CppClass* klass, TypeFieldIndex fieldIndex)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);

    IL2CPP_ASSERT(typeDefinition != NULL);
    IL2CPP_ASSERT(fieldIndex >= 0 && fieldIndex < typeDefinition->field_count);
    IL2CPP_ASSERT(typeDefinition->fieldStart != kFieldIndexInvalid);

    const Il2CppFieldDefinition* fieldDefinition = GetFieldDefinitionFromIndex(typeDefinition->fieldStart + fieldIndex);

    return {
            GetIl2CppTypeFromIndex(fieldDefinition->typeIndex),
            GetStringFromIndex(fieldDefinition->nameIndex),
            fieldDefinition->token
    };
}

Il2CppMetadataMethodInfo il2cpp::vm::GlobalMetadata::GetMethodInfo(const Il2CppClass* klass, TypeMethodIndex index)
{
    const Il2CppTypeDefinition* typeDefinition = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);

    IL2CPP_ASSERT(typeDefinition != NULL);
    IL2CPP_ASSERT(index >= 0 && index < typeDefinition->method_count);
    IL2CPP_ASSERT(typeDefinition->methodStart != kMethodIndexInvalid);

    const Il2CppMethodDefinition* methodDefinition = GetMethodDefinitionFromIndex(typeDefinition->methodStart + index);

    return {
            reinterpret_cast<Il2CppMetadataMethodDefinitionHandle>(methodDefinition),
            GetStringFromIndex(methodDefinition->nameIndex),
            GetIl2CppTypeFromIndex(methodDefinition->returnType),
            methodDefinition->token,
            methodDefinition->flags,
            methodDefinition->iflags,
            methodDefinition->slot,
            methodDefinition->parameterCount,
    };
}

Il2CppMetadataParameterInfo il2cpp::vm::GlobalMetadata::GetParameterInfo(const Il2CppClass* klass, Il2CppMetadataMethodDefinitionHandle handle, MethodParameterIndex paramIndex)
{
    const Il2CppMethodDefinition* methodDefinition = reinterpret_cast<const Il2CppMethodDefinition*>(handle);

    IL2CPP_ASSERT(methodDefinition != NULL);
    IL2CPP_ASSERT(paramIndex >= 0 && paramIndex < methodDefinition->parameterCount);

    const Il2CppParameterDefinition* parameterDefinition = GetParameterDefinitionFromIndex(klass, methodDefinition->parameterStart + paramIndex);

    return {
            GetStringFromIndex(parameterDefinition->nameIndex),
            parameterDefinition->token,
            GetIl2CppTypeFromIndex(parameterDefinition->typeIndex),
    };
}

Il2CppMetadataPropertyInfo il2cpp::vm::GlobalMetadata::GetPropertyInfo(const Il2CppClass* klass, TypePropertyIndex index)
{
    if (hybridclr::metadata::IsInterpreterType(klass))
    {
        return hybridclr::metadata::MetadataModule::GetImage(klass)->GetPropertyInfo(klass, index);
    }
    const Il2CppTypeDefinition* typeDefintion = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);

    IL2CPP_ASSERT(typeDefintion != NULL);
    IL2CPP_ASSERT(index >= 0 && index < typeDefintion->property_count);
    IL2CPP_ASSERT(typeDefintion->propertyStart != kPropertyIndexInvalid);

    const Il2CppPropertyDefinition* propertyDefintion = GetPropertyDefinitionFromIndex(klass->image, typeDefintion->propertyStart + index);

    return {
            GetStringFromIndex(propertyDefintion->nameIndex),
            propertyDefintion->get != kMethodIndexInvalid ? klass->methods[propertyDefintion->get] : NULL,
            propertyDefintion->set != kMethodIndexInvalid ? klass->methods[propertyDefintion->set] : NULL,
            propertyDefintion->attrs,
            propertyDefintion->token,
    };
}

Il2CppMetadataEventInfo il2cpp::vm::GlobalMetadata::GetEventInfo(const Il2CppClass* klass, TypeEventIndex index)
{
    if (hybridclr::metadata::IsInterpreterType(klass))
    {
        return hybridclr::metadata::MetadataModule::GetImage(klass)->GetEventInfo(klass, index);
    }
    const Il2CppTypeDefinition* typeDefintion = reinterpret_cast<const Il2CppTypeDefinition*>(klass->typeMetadataHandle);

    IL2CPP_ASSERT(typeDefintion != NULL);
    IL2CPP_ASSERT(index >= 0 && index < typeDefintion->event_count);

    const Il2CppEventDefinition* eventDefintion = GetEventDefinitionFromIndex(klass->image, typeDefintion->eventStart + index);

    return {
            GetStringFromIndex(eventDefintion->nameIndex),
            GetIl2CppTypeFromIndex(eventDefintion->typeIndex),
            eventDefintion->add != kMethodIndexInvalid ? klass->methods[eventDefintion->add] : NULL,
            eventDefintion->remove != kMethodIndexInvalid ? klass->methods[eventDefintion->remove] : NULL,
            eventDefintion->raise != kMethodIndexInvalid ? klass->methods[eventDefintion->raise] : NULL,
            eventDefintion->token,
    };
}

static const Il2CppGenericContainer* GetGenericContainerFromIndexInternal(GenericContainerIndex index)
{
    if (index == kGenericContainerIndexInvalid)
        return NULL;

    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetGenericContainerFromEncodeIndex(index);
    }
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->genericContainersSize / sizeof(Il2CppGenericContainer));    const Il2CppGenericContainer* genericContainers = (const Il2CppGenericContainer*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericContainersOffset);
    return genericContainers + index;
}

Il2CppMetadataGenericContainerHandle il2cpp::vm::GlobalMetadata::GetGenericContainerFromIndex(GenericContainerIndex index)
{
    const Il2CppGenericContainer* container = GetGenericContainerFromIndexInternal(index);
    return reinterpret_cast<Il2CppMetadataGenericContainerHandle>(container);
}

Il2CppMetadataGenericContainerHandle il2cpp::vm::GlobalMetadata::GetGenericContainerFromGenericClass(const Il2CppGenericClass* genericClass)
{
    const Il2CppTypeDefinition* genericType = reinterpret_cast<const Il2CppTypeDefinition*>(GetTypeHandleFromType(genericClass->type));
    return GetGenericContainerFromIndex(genericType->genericContainerIndex);
}

Il2CppMetadataGenericContainerHandle il2cpp::vm::GlobalMetadata::GetGenericContainerFromMethod(Il2CppMetadataMethodDefinitionHandle handle)
{
    const Il2CppMethodDefinition* methodDefinition = reinterpret_cast<const Il2CppMethodDefinition*>(handle);
    return GetGenericContainerFromIndex(methodDefinition->genericContainerIndex);
}

const Il2CppGenericMethod* il2cpp::vm::GlobalMetadata::GetGenericMethodFromTokenMethodTuple(const Il2CppTokenIndexMethodTuple* tuple)
{
    return GetGenericMethodFromIndex(tuple->__genericMethodIndex);
}

Il2CppMetadataGenericParameterHandle il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndexInternal(GenericParameterIndex index)
{
    if (index == kGenericParameterIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->genericParametersSize / sizeof(Il2CppGenericParameter));
    const Il2CppGenericParameter* genericParameters = (const Il2CppGenericParameter*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericParametersOffset);
    return reinterpret_cast<Il2CppMetadataGenericParameterHandle>(genericParameters + index);
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
    const Il2CppGenericParameter* genericParameter = reinterpret_cast<const Il2CppGenericParameter*>(handle);

    const Il2CppGenericContainer* genericContainer =  GetGenericContainerFromIndexInternal(genericParameter->ownerIndex);

    if (genericContainer->is_method)
        return GetMethodInfoFromMethodDefinitionIndex(genericContainer->ownerIndex)->klass;

    return GetTypeInfoFromTypeDefinitionIndex(genericContainer->ownerIndex);
}

Il2CppMetadataGenericParameterHandle il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndex(Il2CppMetadataGenericContainerHandle handle, GenericContainerParameterIndex index)
{
    const Il2CppGenericContainer* genericContainer = reinterpret_cast<const Il2CppGenericContainer*>(handle);

    IL2CPP_ASSERT(index >= 0 && index < genericContainer->type_argc);

    if (hybridclr::metadata::IsInterpreterIndex(genericContainer->ownerIndex))
    {
        return (Il2CppMetadataGenericParameterHandle)hybridclr::metadata::MetadataModule::GetImage(hybridclr::metadata::DecodeImageIndex(genericContainer->ownerIndex))->GetGenericParameterByRawIndex(genericContainer, index);
    }

    return GetGenericParameterFromIndexInternal(genericContainer->genericParameterStart + index);
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetGenericParameterConstraintFromIndex(Il2CppMetadataGenericParameterHandle handle, GenericParameterConstraintIndex index)
{
    const Il2CppGenericParameter* genericParameter = reinterpret_cast<const Il2CppGenericParameter*>(handle);

    IL2CPP_ASSERT(index >= 0 && index < genericParameter->constraintsCount);

    index = genericParameter->constraintsStart + index;

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->genericParameterConstraintsSize / sizeof(TypeIndex));
    const TypeIndex* constraintIndices = (const TypeIndex*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericParameterConstraintsOffset);

    return GetIl2CppTypeFromIndex(constraintIndices[index]);
}

static GenericParameterIndex GetIndexForGenericParameter(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter* genericParameter = reinterpret_cast<const Il2CppGenericParameter*>(handle);
    const Il2CppGenericParameter* genericParameters = (const Il2CppGenericParameter*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->genericParametersOffset);

    IL2CPP_ASSERT(genericParameter >= genericParameters && genericParameter < genericParameters + s_GlobalMetadataHeader->genericParametersSize / sizeof(Il2CppGenericParameter));

    ptrdiff_t index = genericParameter - genericParameters;
    IL2CPP_ASSERT(index <= std::numeric_limits<GenericParameterIndex>::max());
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

const Il2CppGenericMethod* il2cpp::vm::GlobalMetadata::GetGenericMethodFromRgctxDefinition(const Il2CppRGCTXDefinition* rgctxDef)
{
    IL2CPP_ASSERT(rgctxDef->type == IL2CPP_RGCTX_DATA_METHOD);
    return GetGenericMethodFromIndex(((const Il2CppRGCTXDefinitionData*)rgctxDef->data)->__methodIndex);
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
    return ConvertPackingSizeEnumToValue(static_cast<PackingSize>((reinterpret_cast<const Il2CppTypeDefinition*>(handle)->bitfield >> (kSpecifiedPackingSize - 1)) & 0xF));
}

static const Il2CppImage* GetImageForTypeDefinitionIndex(TypeDefinitionIndex index)
{
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetImage(hybridclr::metadata::DecodeImageIndex(index))->GetIl2CppImage();
    }
    for (int32_t imageIndex = 0; imageIndex < s_MetadataImagesCount; imageIndex++)
    {
        const Il2CppImageGlobalMetadata* imageMetadata = s_MetadataImagesTable + imageIndex;
        IL2CPP_ASSERT(index >= 0);
        if (index >= imageMetadata->typeStart && static_cast<uint32_t>(index) < (imageMetadata->typeStart + imageMetadata->image->typeCount))
            return imageMetadata->image;
    }

    IL2CPP_ASSERT(0 && "Failed to find owning image for type defintion index");
    return NULL;
}

Il2CppClass* il2cpp::vm::GlobalMetadata::FromTypeDefinition(TypeDefinitionIndex index)
{
    const Il2CppTypeDefinition* typeDefinition;
    const Il2CppTypeDefinitionSizes* typeDefinitionSizes;
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        typeDefinition = (const Il2CppTypeDefinition *)hybridclr::metadata::MetadataModule::GetAssemblyTypeHandleFromEncodeIndex(index);
        typeDefinitionSizes = hybridclr::metadata::MetadataModule::GetTypeDefinitionSizesFromEncodeIndex(index);
    }
    else
    {
    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) < s_GlobalMetadataHeader->typeDefinitionsSize / sizeof(Il2CppTypeDefinition));
    const Il2CppTypeDefinition* typeDefinitions = (const Il2CppTypeDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->typeDefinitionsOffset);
        typeDefinition = typeDefinitions + index;
        typeDefinitionSizes = s_Il2CppMetadataRegistration->typeDefinitionsSizes[index];
    }
    Il2CppClass* typeInfo = (Il2CppClass*)IL2CPP_CALLOC(1, sizeof(Il2CppClass) + (sizeof(VirtualInvokeData) * typeDefinition->vtable_count));
    typeInfo->klass = typeInfo;
    typeInfo->image = GetImageForTypeDefinitionIndex(index);
    typeInfo->name = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->nameIndex);
    typeInfo->namespaze = il2cpp::vm::GlobalMetadata::GetStringFromIndex(typeDefinition->namespaceIndex);
    typeInfo->byval_arg = *il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition->byvalTypeIndex);
    typeInfo->this_arg = typeInfo->byval_arg;
    typeInfo->this_arg.byref = true;
    typeInfo->this_arg.valuetype = 0;
    typeInfo->typeMetadataHandle = reinterpret_cast<const Il2CppMetadataTypeHandle>(typeDefinition);
    typeInfo->genericContainerHandle = GetGenericContainerFromIndex(typeDefinition->genericContainerIndex);
    typeInfo->instance_size = typeDefinitionSizes->instance_size;
    typeInfo->actualSize = typeDefinitionSizes->instance_size;     // actualySize is instance_size for compiler generated values
    typeInfo->native_size = typeDefinitionSizes->native_size;
    typeInfo->static_fields_size = typeDefinitionSizes->static_fields_size;
    typeInfo->thread_static_fields_size = typeDefinitionSizes->thread_static_fields_size;
    typeInfo->thread_static_fields_offset = -1;
    typeInfo->flags = typeDefinition->flags;
    typeInfo->enumtype = (typeDefinition->bitfield >> (kBitIsEnum - 1)) & 0x1;
    typeInfo->is_generic = typeDefinition->genericContainerIndex != kGenericContainerIndexInvalid;     // generic if we have a generic container
    typeInfo->has_finalize = (typeDefinition->bitfield >> (kBitHasFinalizer - 1)) & 0x1;
    typeInfo->has_cctor = (typeDefinition->bitfield >> (kBitHasStaticConstructor - 1)) & 0x1;
    typeInfo->cctor_finished_or_no_cctor = !typeInfo->has_cctor;
    typeInfo->is_blittable = (typeDefinition->bitfield >> (kBitIsBlittable - 1)) & 0x1;
    typeInfo->is_import_or_windows_runtime = (typeDefinition->bitfield >> (kBitIsImportOrWindowsRuntime - 1)) & 0x1;
    typeInfo->packingSize = ConvertPackingSizeEnumToValue(static_cast<PackingSize>((typeDefinition->bitfield >> (kPackingSize - 1)) & 0xF));
    typeInfo->is_byref_like = (typeDefinition->bitfield >> (kBitIsByRefLike - 1)) & 0x1;
    typeInfo->method_count = typeDefinition->method_count;
    typeInfo->property_count = typeDefinition->property_count;
    typeInfo->field_count = typeDefinition->field_count;
    typeInfo->event_count = typeDefinition->event_count;
    typeInfo->nested_type_count = typeDefinition->nested_type_count;
    typeInfo->vtable_count = typeDefinition->vtable_count;
    typeInfo->interfaces_count = typeDefinition->interfaces_count;
    typeInfo->interface_offsets_count = typeDefinition->interface_offsets_count;
    typeInfo->token = typeDefinition->token;
    typeInfo->interopData = il2cpp::vm::MetadataCache::GetInteropDataForType(&typeInfo->byval_arg);

    if (typeDefinition->parentIndex != kTypeIndexInvalid)
        typeInfo->parent = il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition->parentIndex));

    if (typeDefinition->declaringTypeIndex != kTypeIndexInvalid)
        typeInfo->declaringType = il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition->declaringTypeIndex));

    typeInfo->castClass = typeInfo->element_class = typeInfo;
    if (typeInfo->enumtype)
        typeInfo->castClass = typeInfo->element_class = il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(typeDefinition->elementTypeIndex));

    return typeInfo;
}

const Il2CppType* il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(TypeIndex index)
{
    if (index == kTypeIndexInvalid)
        return NULL;
    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        return hybridclr::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(index);
    }
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
    const Il2CppGenericParameter* genericParameter = reinterpret_cast<const Il2CppGenericParameter*>(handle);
    return genericParameter->constraintsCount;
}

const char* il2cpp::vm::GlobalMetadata::GetGenericParameterName(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter* genericParameter = reinterpret_cast<const Il2CppGenericParameter*>(handle);
    return GetStringFromIndex(genericParameter->nameIndex);
}

Il2CppGenericParameterInfo il2cpp::vm::GlobalMetadata::GetGenericParameterInfo(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter* genericParameter = reinterpret_cast<const Il2CppGenericParameter*>(handle);

    return {
            reinterpret_cast<Il2CppMetadataGenericContainerHandle>(GetGenericContainerFromIndexInternal(genericParameter->ownerIndex)),
            GetStringFromIndex(genericParameter->nameIndex),
            genericParameter->num,
            genericParameter->flags
    };
}

uint16_t il2cpp::vm::GlobalMetadata::GetGenericParameterFlags(Il2CppMetadataGenericParameterHandle handle)
{
    const Il2CppGenericParameter* genericParameter = reinterpret_cast<const Il2CppGenericParameter*>(handle);
    return genericParameter->flags;
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

    if (hybridclr::metadata::IsInterpreterIndex(index))
    {
        Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(hybridclr::metadata::MetadataModule::GetIl2CppTypeFromEncodeIndex(index));
        ClassInlines::InitFromCodegen(klass);
        return klass;
    }

    IL2CPP_ASSERT(index < s_Il2CppMetadataRegistration->typesCount && "Invalid type index ");

    if (s_TypeInfoTable[index])
        return s_TypeInfoTable[index];

    const Il2CppType* type = s_Il2CppMetadataRegistration->types[index];

    Il2CppClass *klass = Class::FromIl2CppType(type, throwOnError);
    if (klass != NULL)
    {
        s_TypeInfoTable[index] = ClassInlines::InitFromCodegenSlow(klass, throwOnError);
    }
    return s_TypeInfoTable[index];
}

const MethodInfo* il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodHandle(Il2CppMetadataMethodDefinitionHandle handle)
{
    const Il2CppMethodDefinition* methodDefinition = reinterpret_cast<const Il2CppMethodDefinition*>(handle);
    if (hybridclr::metadata::IsInterpreterIndex(methodDefinition->nameIndex))
    {
        return hybridclr::metadata::MetadataModule::GetMethodInfoFromMethodDefinition(methodDefinition);
    }
    const Il2CppMethodDefinition* methods = (const Il2CppMethodDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->methodsOffset);

    const MethodIndex index = static_cast<MethodIndex>(methodDefinition - methods);

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) <= s_GlobalMetadataHeader->methodsSize / sizeof(Il2CppMethodDefinition));

    return GetMethodInfoFromMethodDefinitionIndex(index);
}

#if IL2CPP_ENABLE_NATIVE_STACKTRACES
void il2cpp::vm::GlobalMetadata::GetAllManagedMethods(std::vector<MethodDefinitionKey>& managedMethods)
{
    size_t methodDefinitionsCount = s_GlobalMetadataHeader->methodsSize / sizeof(Il2CppMethodDefinition);
    managedMethods.reserve(methodDefinitionsCount + s_Il2CppMetadataRegistration->genericMethodTableCount);

    const Il2CppTypeDefinition* typeDefinitions = (const Il2CppTypeDefinition*)((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->typeDefinitionsOffset);
    for (int32_t i = 0; i < s_MetadataImagesCount; i++)
    {
        const Il2CppImageGlobalMetadata* image = s_MetadataImagesTable + i;

        for (size_t j = 0; j < image->image->typeCount; j++)
        {
            const Il2CppTypeDefinition* type = typeDefinitions + image->typeStart + j;

            for (uint16_t u = 0; u < type->method_count; u++)
            {
                const Il2CppMethodDefinition* methodDefinition = GetMethodDefinitionFromIndex(type->methodStart + u);
                MethodDefinitionKey currentMethodList;
                currentMethodList.methodHandle = reinterpret_cast<Il2CppMetadataMethodDefinitionHandle>(methodDefinition);
                currentMethodList.method = il2cpp::vm::MetadataCache::GetMethodPointer(image->image, methodDefinition->token);
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
        const Il2CppMethodDefinition* methodDefinition = GetMethodDefinitionFromIndex(methodSpec->methodDefinitionIndex);
        currentMethodList.methodHandle = reinterpret_cast<Il2CppMetadataMethodDefinitionHandle>(methodDefinition);

        IL2CPP_ASSERT(genericMethodIndices->indices.methodIndex < static_cast<int32_t>(s_GlobalMetadata_CodeRegistration->genericMethodPointersCount));
        currentMethodList.method = s_GlobalMetadata_CodeRegistration->genericMethodPointers[genericMethodIndices->indices.methodIndex];

        managedMethods.push_back(currentMethodList);
    }
}

#endif
