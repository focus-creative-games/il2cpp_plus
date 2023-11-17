#include "il2cpp-config.h"
#include "MetadataCache.h"
#include "GlobalMetadata.h"

#include <map>
#include <limits>
#include "il2cpp-tabledefs.h"
#include "il2cpp-runtime-stats.h"
#include "gc/GarbageCollector.h"
#include "metadata/ArrayMetadata.h"
#include "metadata/GenericMetadata.h"
#include "metadata/GenericMethod.h"
#include "os/Atomic.h"
#include "os/Mutex.h"
#include "utils/CallOnce.h"
#include "utils/Collections.h"
#include "utils/Il2CppHashSet.h"
#include "utils/Memory.h"
#include "utils/PathUtils.h"
#include "vm/Assembly.h"
#include "vm/Class.h"
#include "vm/ClassInlines.h"
#include "vm/GenericClass.h"
#include "vm/MetadataAlloc.h"
#include "vm/MetadataLoader.h"
#include "vm/MetadataLock.h"
#include "vm/Method.h"
#include "vm/Object.h"
#include "vm/Runtime.h"
#include "vm/String.h"
#include "vm/Type.h"
#include "vm-utils/MethodDefinitionKey.h"
#include "vm-utils/NativeSymbol.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"

#include "hybridclr/metadata/Assembly.h"
#include "hybridclr/metadata/MetadataModule.h"

typedef Il2CppReaderWriterLockedHashMap<Il2CppClass*, Il2CppClass*> PointerTypeMap;

typedef Il2CppHashSet<const Il2CppGenericMethod*, il2cpp::metadata::Il2CppGenericMethodHash, il2cpp::metadata::Il2CppGenericMethodCompare> Il2CppGenericMethodSet;
typedef Il2CppGenericMethodSet::const_iterator Il2CppGenericMethodSetIter;
static Il2CppGenericMethodSet s_GenericMethodSet;

struct Il2CppMetadataCache
{
    il2cpp::os::FastReaderReaderWriterLock m_CacheLock;
    PointerTypeMap m_PointerTypes;
};

static Il2CppMetadataCache s_MetadataCache;
static int32_t s_ImagesCount = 0;
static Il2CppImage* s_ImagesTable = NULL;
static int32_t s_AssembliesCount = 0;
static Il2CppAssembly* s_AssembliesTable = NULL;


typedef Il2CppReaderWriterLockedHashSet<const Il2CppGenericInst*, il2cpp::metadata::Il2CppGenericInstHash, il2cpp::metadata::Il2CppGenericInstCompare> Il2CppGenericInstSet;
static Il2CppGenericInstSet s_GenericInstSet;

typedef il2cpp::vm::Il2CppMethodTableMap::const_iterator Il2CppMethodTableMapIter;
static il2cpp::vm::Il2CppMethodTableMap s_MethodTableMap;

typedef il2cpp::vm::Il2CppUnresolvedSignatureMap::const_iterator Il2CppUnresolvedSignatureMapIter;
static il2cpp::vm::Il2CppUnresolvedSignatureMap *s_pUnresolvedSignatureMap;

typedef Il2CppHashMap<FieldInfo*, int32_t, il2cpp::utils::PointerHash<FieldInfo> > Il2CppThreadLocalStaticOffsetHashMap;
typedef Il2CppThreadLocalStaticOffsetHashMap::iterator Il2CppThreadLocalStaticOffsetHashMapIter;
static Il2CppThreadLocalStaticOffsetHashMap s_ThreadLocalStaticOffsetMap;

static const Il2CppCodeRegistration * s_Il2CppCodeRegistration;
static const Il2CppMetadataRegistration* s_MetadataCache_Il2CppMetadataRegistration;
static const Il2CppCodeGenOptions* s_Il2CppCodeGenOptions;

static il2cpp::vm::WindowsRuntimeTypeNameToClassMap s_WindowsRuntimeTypeNameToClassMap;
static il2cpp::vm::ClassToWindowsRuntimeTypeNameMap s_ClassToWindowsRuntimeTypeNameMap;

struct InteropDataToTypeConverter
{
    inline const Il2CppType* operator()(const Il2CppInteropData& interopData) const
    {
        return interopData.type;
    }
};

typedef il2cpp::utils::collections::ArrayValueMap<const Il2CppType*, Il2CppInteropData, InteropDataToTypeConverter, il2cpp::metadata::Il2CppTypeLess, il2cpp::metadata::Il2CppTypeEqualityComparer> InteropDataMap;
static InteropDataMap s_InteropData;

struct WindowsRuntimeFactoryTableEntryToTypeConverter
{
    inline const Il2CppType* operator()(const Il2CppWindowsRuntimeFactoryTableEntry& entry) const
    {
        return entry.type;
    }
};

typedef il2cpp::utils::collections::ArrayValueMap<const Il2CppType*, Il2CppWindowsRuntimeFactoryTableEntry, WindowsRuntimeFactoryTableEntryToTypeConverter, il2cpp::metadata::Il2CppTypeLess, il2cpp::metadata::Il2CppTypeEqualityComparer> WindowsRuntimeFactoryTable;
static WindowsRuntimeFactoryTable s_WindowsRuntimeFactories;

template<typename K, typename V>
struct PairToKeyConverter
{
    inline const K& operator()(const std::pair<K, V>& pair) const
    {
        return pair.first;
    }
};

typedef il2cpp::utils::collections::ArrayValueMap<const Il2CppGuid*, std::pair<const Il2CppGuid*, Il2CppClass*>, PairToKeyConverter<const Il2CppGuid*, Il2CppClass*> > GuidToClassMap;
static GuidToClassMap s_GuidToNonImportClassMap;

static il2cpp::utils::dynamic_array<Il2CppAssembly*> s_cliAssemblies;

void il2cpp::vm::MetadataCache::Register(const Il2CppCodeRegistration* const codeRegistration, const Il2CppMetadataRegistration* const metadataRegistration, const Il2CppCodeGenOptions* const codeGenOptions)
{
    il2cpp::vm::GlobalMetadata::Register(codeRegistration, metadataRegistration, codeGenOptions);

    s_Il2CppCodeRegistration = codeRegistration;
    s_MetadataCache_Il2CppMetadataRegistration = metadataRegistration;
    s_Il2CppCodeGenOptions = codeGenOptions;
}

Il2CppClass* il2cpp::vm::MetadataCache::GetTypeInfoFromTypeIndex(const Il2CppImage *image, TypeIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeIndex(index);
}

const MethodInfo* il2cpp::vm::MetadataCache::GetMethodInfoFromMethodDefinitionIndex(const Il2CppImage *image, MethodIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodDefinitionIndex(index);
}

const MethodInfo* il2cpp::vm::MetadataCache::GetAssemblyEntryPoint(const Il2CppImage* image)
{
    return il2cpp::vm::GlobalMetadata::GetAssemblyEntryPoint(image);
}

Il2CppMetadataTypeHandle il2cpp::vm::MetadataCache::GetAssemblyTypeHandle(const Il2CppImage* image, AssemblyTypeIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetAssemblyTypeHandle(image, index);
}

Il2CppMetadataTypeHandle il2cpp::vm::MetadataCache::GetAssemblyExportedTypeHandle(const Il2CppImage* image, AssemblyExportedTypeIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetAssemblyExportedTypeHandle(image, index);
}

const MethodInfo* il2cpp::vm::MetadataCache::GetMethodInfoFromMethodHandle(Il2CppMetadataMethodDefinitionHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetMethodInfoFromMethodHandle(handle);
}

bool il2cpp::vm::MetadataCache::Initialize()
{
    if (!il2cpp::vm::GlobalMetadata::Initialize(&s_ImagesCount, &s_AssembliesCount))
    {
        return false;
    }

    il2cpp::metadata::GenericMetadata::RegisterGenericClasses(s_MetadataCache_Il2CppMetadataRegistration->genericClasses, s_MetadataCache_Il2CppMetadataRegistration->genericClassesCount);
    il2cpp::metadata::GenericMetadata::SetMaximumRuntimeGenericDepth(s_Il2CppCodeGenOptions->maximumRuntimeGenericDepth);
    il2cpp::metadata::GenericMetadata::SetGenericVirtualIterations(s_Il2CppCodeGenOptions->recursiveGenericIterations);

    s_GenericInstSet.Resize(s_MetadataCache_Il2CppMetadataRegistration->genericInstsCount);
    for (int32_t i = 0; i < s_MetadataCache_Il2CppMetadataRegistration->genericInstsCount; i++)
    {
        bool inserted = s_GenericInstSet.Add(s_MetadataCache_Il2CppMetadataRegistration->genericInsts[i]);
        IL2CPP_ASSERT(inserted);
    }

    s_InteropData.assign_external(s_Il2CppCodeRegistration->interopData, s_Il2CppCodeRegistration->interopDataCount);
    s_WindowsRuntimeFactories.assign_external(s_Il2CppCodeRegistration->windowsRuntimeFactoryTable, s_Il2CppCodeRegistration->windowsRuntimeFactoryCount);

    // Pre-allocate these arrays so we don't need to lock when reading later.
    // These arrays hold the runtime metadata representation for metadata explicitly
    // referenced during conversion. There is a corresponding table of same size
    // in the converted metadata, giving a description of runtime metadata to construct.
    s_ImagesTable = (Il2CppImage*)IL2CPP_CALLOC(s_ImagesCount, sizeof(Il2CppImage));
    s_AssembliesTable = (Il2CppAssembly*)IL2CPP_CALLOC(s_AssembliesCount, sizeof(Il2CppAssembly));

    // setup all the Il2CppImages. There are not many and it avoid locks later on
    for (int32_t imageIndex = 0; imageIndex < s_ImagesCount; imageIndex++)
    {
        Il2CppImage* image = s_ImagesTable + imageIndex;

        AssemblyIndex imageAssemblyIndex;
        il2cpp::vm::GlobalMetadata::BuildIl2CppImage(image, imageIndex, &imageAssemblyIndex);

        image->assembly = const_cast<Il2CppAssembly*>(GetAssemblyFromIndex(imageAssemblyIndex));

        std::string nameNoExt = il2cpp::utils::PathUtils::PathNoExtension(image->name);
        image->nameNoExt = (char*)IL2CPP_CALLOC(nameNoExt.size() + 1, sizeof(char));
        strcpy(const_cast<char*>(image->nameNoExt), nameNoExt.c_str());

        for (uint32_t codeGenModuleIndex = 0; codeGenModuleIndex < s_Il2CppCodeRegistration->codeGenModulesCount; ++codeGenModuleIndex)
        {
            if (strcmp(image->name, s_Il2CppCodeRegistration->codeGenModules[codeGenModuleIndex]->moduleName) == 0)
                image->codeGenModule = s_Il2CppCodeRegistration->codeGenModules[codeGenModuleIndex];
        }
        IL2CPP_ASSERT(image->codeGenModule);
        image->dynamic = false;
    }

    // setup all the Il2CppAssemblies.
    for (int32_t assemblyIndex = 0; assemblyIndex < s_ImagesCount; assemblyIndex++)
    {
        Il2CppAssembly* assembly = s_AssembliesTable + assemblyIndex;

        ImageIndex assemblyImageIndex;
        il2cpp::vm::GlobalMetadata::BuildIl2CppAssembly(assembly, assemblyIndex, &assemblyImageIndex);

        assembly->image = il2cpp::vm::MetadataCache::GetImageFromIndex(assemblyImageIndex);

        Assembly::Register(assembly);
    }

    InitializeUnresolvedSignatureTable();

#if IL2CPP_ENABLE_NATIVE_STACKTRACES
    std::vector<MethodDefinitionKey> managedMethods;
    il2cpp::vm::GlobalMetadata::GetAllManagedMethods(managedMethods);
    il2cpp::utils::NativeSymbol::RegisterMethods(managedMethods);
#endif
    return true;
}

void il2cpp::vm::MetadataCache::ExecuteEagerStaticClassConstructors()
{
    for (int32_t i = 0; i < s_AssembliesCount; i++)
    {
        const Il2CppImage* image = s_AssembliesTable[i].image;
        if (image->codeGenModule->staticConstructorTypeIndices != NULL)
        {
            TypeDefinitionIndex* indexPointer = image->codeGenModule->staticConstructorTypeIndices;
            while (*indexPointer) // 0 terminated
            {
                Il2CppMetadataTypeHandle handle = GetTypeHandleFromIndex(image, *indexPointer);
                Il2CppClass* klass = GlobalMetadata::GetTypeInfoFromHandle(handle);
                Runtime::ClassInit(klass);
                indexPointer++;
            }
        }
    }
}

typedef void(*Il2CppModuleInitializerMethodPointer)(const MethodInfo*);

void il2cpp::vm::MetadataCache::ExecuteModuleInitializers()
{
    for (int32_t i = 0; i < s_AssembliesCount; i++)
    {
        const Il2CppImage* image = s_AssembliesTable[i].image;
        if (image->codeGenModule->moduleInitializer != NULL)
        {
            Il2CppModuleInitializerMethodPointer moduleInitializer = (Il2CppModuleInitializerMethodPointer)image->codeGenModule->moduleInitializer;
            moduleInitializer(NULL);
        }
    }
}

void ClearGenericMethodTable()
{
    s_MethodTableMap.clear();
}

void ClearWindowsRuntimeTypeNamesTables()
{
    s_ClassToWindowsRuntimeTypeNameMap.clear();
}

void il2cpp::vm::MetadataCache::InitializeGuidToClassTable()
{
    Il2CppInteropData* interopData = s_Il2CppCodeRegistration->interopData;
    uint32_t interopDataCount = s_Il2CppCodeRegistration->interopDataCount;
    std::vector<std::pair<const Il2CppGuid*, Il2CppClass*> > guidToNonImportClassMap;
    guidToNonImportClassMap.reserve(interopDataCount);

    for (uint32_t i = 0; i < interopDataCount; i++)
    {
        // It's important to check for non-import types because type projections will have identical GUIDs (e.g. IEnumerable<T> and IIterable<T>)
        if (interopData[i].guid != NULL)
        {
            Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(interopData[i].type);
            if (!klass->is_import_or_windows_runtime)
                guidToNonImportClassMap.push_back(std::make_pair(interopData[i].guid, klass));
        }
    }

    s_GuidToNonImportClassMap.assign(guidToNonImportClassMap);
}

// this is called later in the intialization cycle with more systems setup like GC
void il2cpp::vm::MetadataCache::InitializeGCSafe()
{
    il2cpp::vm::GlobalMetadata::InitializeStringLiteralTable();
    il2cpp::vm::GlobalMetadata::InitializeGenericMethodTable(s_MethodTableMap);
    il2cpp::vm::GlobalMetadata::InitializeWindowsRuntimeTypeNamesTables(s_WindowsRuntimeTypeNameToClassMap, s_ClassToWindowsRuntimeTypeNameMap);
    InitializeGuidToClassTable();
}

void ClearImageNames()
{
    for (int32_t imageIndex = 0; imageIndex < s_ImagesCount; imageIndex++)
    {
        Il2CppImage* image = s_ImagesTable + imageIndex;
        IL2CPP_FREE((void*)image->nameNoExt);
    }
}

void il2cpp::vm::MetadataCache::Clear()
{
    ClearGenericMethodTable();
    ClearWindowsRuntimeTypeNamesTables();

    delete s_pUnresolvedSignatureMap;

    Assembly::ClearAllAssemblies();

    ClearImageNames();

    IL2CPP_FREE(s_ImagesTable);
    s_ImagesTable = NULL;
    s_ImagesCount = 0;

    IL2CPP_FREE(s_AssembliesTable);
    s_AssembliesTable = NULL;
    s_AssembliesCount = 0;

    s_GenericMethodSet.clear();

    metadata::ArrayMetadata::Clear();

    s_GenericInstSet.Clear();

    s_Il2CppCodeRegistration = NULL;
    s_Il2CppCodeGenOptions = NULL;

    il2cpp::metadata::GenericMetadata::Clear();
    il2cpp::metadata::GenericMethod::ClearStatics();

    il2cpp::vm::GlobalMetadata::Clear();
}

void il2cpp::vm::MetadataCache::InitializeUnresolvedSignatureTable()
{
    s_pUnresolvedSignatureMap = new Il2CppUnresolvedSignatureMap();
    il2cpp::vm::GlobalMetadata::InitializeUnresolvedSignatureTable(*s_pUnresolvedSignatureMap);
}

Il2CppClass* il2cpp::vm::MetadataCache::GetGenericInstanceType(Il2CppClass* genericTypeDefinition, const Il2CppType** genericArgumentTypes, uint32_t genericArgumentCount)
{
    const Il2CppGenericInst* inst = il2cpp::vm::MetadataCache::GetGenericInst(genericArgumentTypes, genericArgumentCount);
    Il2CppGenericClass* genericClass = il2cpp::metadata::GenericMetadata::GetGenericClass(genericTypeDefinition, inst);
    return il2cpp::vm::GenericClass::GetClass(genericClass);
}

const MethodInfo* il2cpp::vm::MetadataCache::GetGenericInstanceMethod(const MethodInfo* genericMethodDefinition, const Il2CppType** genericArgumentTypes, uint32_t genericArgumentCount)
{
    Il2CppGenericContext context = { NULL, GetGenericInst(genericArgumentTypes, genericArgumentCount) };
    return il2cpp::vm::GlobalMetadata::GetGenericInstanceMethod(genericMethodDefinition, &context);
}

const Il2CppGenericContext* il2cpp::vm::MetadataCache::GetMethodGenericContext(const MethodInfo* method)
{
    if (!method->is_inflated)
    {
        IL2CPP_NOT_IMPLEMENTED(Image::GetMethodGenericContext);
        return NULL;
    }

    return &method->genericMethod->context;
}

const MethodInfo* il2cpp::vm::MetadataCache::GetGenericMethodDefinition(const MethodInfo* method)
{
    if (!method->is_inflated)
    {
        IL2CPP_NOT_IMPLEMENTED(Image::GetGenericMethodDefinition);
        return NULL;
    }

    return method->genericMethod->methodDefinition;
}

Il2CppClass* il2cpp::vm::MetadataCache::GetPointerType(Il2CppClass* type)
{
    Il2CppClass* pointerClass;
    if (s_MetadataCache.m_PointerTypes.TryGet(type, &pointerClass))
        return pointerClass;
    return NULL;
}

Il2CppClass* il2cpp::vm::MetadataCache::GetWindowsRuntimeClass(const char* fullName)
{
    WindowsRuntimeTypeNameToClassMap::iterator it = s_WindowsRuntimeTypeNameToClassMap.find(fullName);
    if (it != s_WindowsRuntimeTypeNameToClassMap.end())
        return it->second;

    return NULL;
}

const char* il2cpp::vm::MetadataCache::GetWindowsRuntimeClassName(const Il2CppClass* klass)
{
    ClassToWindowsRuntimeTypeNameMap::iterator it = s_ClassToWindowsRuntimeTypeNameMap.find(klass);
    if (it != s_ClassToWindowsRuntimeTypeNameMap.end())
        return it->second;

    return NULL;
}

Il2CppMethodPointer il2cpp::vm::MetadataCache::GetWindowsRuntimeFactoryCreationFunction(const char* fullName)
{
    Il2CppClass* klass = GetWindowsRuntimeClass(fullName);
    if (klass == NULL)
        return NULL;

    WindowsRuntimeFactoryTable::iterator factoryEntry = s_WindowsRuntimeFactories.find_first(&klass->byval_arg);
    if (factoryEntry == s_WindowsRuntimeFactories.end())
        return NULL;

    return factoryEntry->createFactoryFunction;
}

Il2CppClass* il2cpp::vm::MetadataCache::GetClassForGuid(const Il2CppGuid* guid)
{
    IL2CPP_ASSERT(guid != NULL);

    GuidToClassMap::iterator it = s_GuidToNonImportClassMap.find_first(guid);
    if (it != s_GuidToNonImportClassMap.end())
        return it->second;

    return NULL;
}

void il2cpp::vm::MetadataCache::AddPointerTypeLocked(Il2CppClass* type, Il2CppClass* pointerType, const il2cpp::os::FastAutoLock& lock)
{
    // This method must be called while holding the g_MetadataLock to ensure that we don't insert the same pointer type twice
    // And WalkPointerTypes assumes this

    IL2CPP_ASSERT(lock.IsLock(&g_MetadataLock));
    s_MetadataCache.m_PointerTypes.Add(type, pointerType);
}

const Il2CppGenericInst* il2cpp::vm::MetadataCache::GetGenericInst(const Il2CppType* const* types, uint32_t typeCount)
{
    // temporary inst to lookup a permanent one that may already exist
    Il2CppGenericInst inst;
    inst.type_argc = typeCount;
    inst.type_argv = (const Il2CppType**)types;

    const Il2CppGenericInst* foundInst;
    if (s_GenericInstSet.TryGet(&inst, &foundInst))
        return foundInst;

    il2cpp::os::FastAutoLock lock(&g_MetadataLock);

    // Check if instance was added while we were blocked on g_MetadataLock
    if (s_GenericInstSet.TryGet(&inst, &foundInst))
        return foundInst;

    Il2CppGenericInst* newInst = NULL;
    newInst  = (Il2CppGenericInst*)MetadataMalloc(sizeof(Il2CppGenericInst));
    newInst->type_argc = typeCount;
    newInst->type_argv = (const Il2CppType**)MetadataMalloc(newInst->type_argc * sizeof(Il2CppType*));

    int index = 0;
    const Il2CppType* const* typesEnd = types + typeCount;
    for (const Il2CppType* const* iter = types; iter != typesEnd; ++iter, ++index)
        newInst->type_argv[index] = *iter;

    // Do this while still holding the g_MetadataLock to prevent the same instance from being added twice
    bool added = s_GenericInstSet.Add(newInst);
    IL2CPP_ASSERT(added);
    ++il2cpp_runtime_stats.generic_instance_count;

    return newInst;
}

static baselib::ReentrantLock s_GenericMethodMutex;
const Il2CppGenericMethod* il2cpp::vm::MetadataCache::GetGenericMethod(const MethodInfo* methodDefinition, const Il2CppGenericInst* classInst, const Il2CppGenericInst* methodInst)
{
    Il2CppGenericMethod method = { 0 };
    method.methodDefinition = methodDefinition;
    method.context.class_inst = classInst;
    method.context.method_inst = methodInst;

    il2cpp::os::FastAutoLock lock(&s_GenericMethodMutex);
    Il2CppGenericMethodSet::const_iterator iter = s_GenericMethodSet.find(&method);
    if (iter != s_GenericMethodSet.end())
        return *iter;

    Il2CppGenericMethod* newMethod = MetadataAllocGenericMethod();
    newMethod->methodDefinition = methodDefinition;
    newMethod->context.class_inst = classInst;
    newMethod->context.method_inst = methodInst;

    s_GenericMethodSet.insert(newMethod);

    return newMethod;
}

static bool IsShareableEnum(const Il2CppType* type)
{
    // Base case for recursion - we've found an enum.
    if (il2cpp::vm::Type::IsEnum(type))
        return true;

    if (il2cpp::vm::Type::IsGenericInstance(type))
    {
        // Recursive case - look "inside" the generic instance type to see if this is a nested enum.
        Il2CppClass* definition = il2cpp::vm::GenericClass::GetTypeDefinition(type->data.generic_class);
        return IsShareableEnum(il2cpp::vm::Class::GetType(definition));
    }

    // Base case for recurion - this is not an enum or a generic instance type.
    return false;
}

static il2cpp::vm::GenericParameterRestriction IsReferenceTypeGenericConstraint(const Il2CppType* constraint)
{
    // This must match GenericSharingAnalsyis.GetGenericParameterConstraintRestriction()

    if (constraint->type == IL2CPP_TYPE_VAR || constraint->type == IL2CPP_TYPE_MVAR)
        return il2cpp::vm::GenericParameterRestrictionNone;
    if (il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(constraint, &il2cpp_defaults.enum_class->byval_arg))
        return il2cpp::vm::GenericParameterRestrictionValueType;
    if (il2cpp::metadata::Il2CppTypeEqualityComparer::AreEqual(constraint, &il2cpp_defaults.value_type_class->byval_arg))
        return il2cpp::vm::GenericParameterRestrictionNone; // Not a valid constraint, so consider it unconstrained
    else if (il2cpp::vm::Class::IsInterface(il2cpp::vm::Class::FromIl2CppType(constraint)))
        return il2cpp::vm::GenericParameterRestrictionNone; // Interfaces constraints can be satisfied by reference or value types

    // Any other type constraint e.g. T : SomeType, SomeType must be a reference type
    return il2cpp::vm::GenericParameterRestrictionReferenceType;
}

il2cpp::vm::GenericParameterRestriction il2cpp::vm::MetadataCache::IsReferenceTypeGenericParameter(Il2CppMetadataGenericParameterHandle genericParameter)
{
    uint16_t flags = il2cpp::vm::GlobalMetadata::GetGenericParameterFlags(genericParameter);
    if ((flags & IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_REFERENCE_TYPE_CONSTRAINT) != 0)
        return GenericParameterRestrictionReferenceType;
    if ((flags & IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NOT_NULLABLE_VALUE_TYPE_CONSTRAINT) != 0)
        return GenericParameterRestrictionValueType; // Must be a value type

    uint32_t count = il2cpp::vm::GlobalMetadata::GetGenericConstraintCount(genericParameter);
    for (uint32_t constraintIndex = 0; constraintIndex < count; ++constraintIndex)
    {
        const Il2CppType* constraint = il2cpp::vm::GlobalMetadata::GetGenericParameterConstraintFromIndex(genericParameter, constraintIndex);
        GenericParameterRestriction restriction = IsReferenceTypeGenericConstraint(constraint);
        if (restriction != GenericParameterRestrictionNone)
            return restriction;
    }

    return GenericParameterRestrictionNone;
}

static const Il2CppGenericInst* GetFullySharedInst(Il2CppMetadataGenericContainerHandle genericContainer, const Il2CppGenericInst* inst)
{
    if (inst == NULL || !il2cpp::vm::Runtime::IsFullGenericSharingEnabled())
        return NULL;

    const Il2CppType** types = (const Il2CppType**)alloca(inst->type_argc * sizeof(Il2CppType*));
    for (uint32_t i = 0; i < inst->type_argc; ++i)
    {
        const Il2CppType* type;
        switch (il2cpp::vm::MetadataCache::IsReferenceTypeGenericParameter(il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndex(genericContainer, i)))
        {
            case il2cpp::vm::GenericParameterRestrictionValueType:
                type = &il2cpp_defaults.il2cpp_fully_shared_struct_type->byval_arg;
                break;
            case il2cpp::vm::GenericParameterRestrictionReferenceType:
                type = &il2cpp_defaults.object_class->byval_arg;
                break;
            default:
                type = &il2cpp_defaults.il2cpp_fully_shared_type->byval_arg;
                break;
        }

        types[i] = type;
    }

    const Il2CppGenericInst* sharedInst = il2cpp::vm::MetadataCache::GetGenericInst(types, inst->type_argc);

    return sharedInst;
}

// this logic must match the C# logic in GenericSharingAnalysis.GetSharedTypeForGenericParameter
static const Il2CppGenericInst* GetSharedInst(const Il2CppGenericInst* inst)
{
    if (inst == NULL)
        return NULL;

    const Il2CppType** types = (const Il2CppType**)alloca(inst->type_argc * sizeof(Il2CppType*));
    for (uint32_t i = 0; i < inst->type_argc; ++i)
    {
        if (il2cpp::vm::Type::IsReference(inst->type_argv[i]))
            types[i] = &il2cpp_defaults.object_class->byval_arg;
        else
        {
            const Il2CppType* type = inst->type_argv[i];
            if (s_Il2CppCodeGenOptions->enablePrimitiveValueTypeGenericSharing)
            {
                if (IsShareableEnum(type))
                {
                    const Il2CppType* underlyingType = il2cpp::vm::Type::GetUnderlyingType(type);
                    switch (underlyingType->type)
                    {
                        case IL2CPP_TYPE_I1:
                            type = &il2cpp_defaults.sbyte_shared_enum->byval_arg;
                            break;
                        case IL2CPP_TYPE_I2:
                            type = &il2cpp_defaults.int16_shared_enum->byval_arg;
                            break;
                        case IL2CPP_TYPE_I4:
                            type = &il2cpp_defaults.int32_shared_enum->byval_arg;
                            break;
                        case IL2CPP_TYPE_I8:
                            type = &il2cpp_defaults.int64_shared_enum->byval_arg;
                            break;
                        case IL2CPP_TYPE_U1:
                            type = &il2cpp_defaults.byte_shared_enum->byval_arg;
                            break;
                        case IL2CPP_TYPE_U2:
                            type = &il2cpp_defaults.uint16_shared_enum->byval_arg;
                            break;
                        case IL2CPP_TYPE_U4:
                            type = &il2cpp_defaults.uint32_shared_enum->byval_arg;
                            break;
                        case IL2CPP_TYPE_U8:
                            type = &il2cpp_defaults.uint64_shared_enum->byval_arg;
                            break;
                        default:
                            IL2CPP_ASSERT(0 && "Invalid enum underlying type");
                            break;
                    }
                }
            }

            if (il2cpp::vm::Type::IsGenericInstance(type))
            {
                const Il2CppGenericInst* sharedInst = GetSharedInst(type->data.generic_class->context.class_inst);
                Il2CppGenericClass* gklass = il2cpp::metadata::GenericMetadata::GetGenericClass(type->data.generic_class->type, sharedInst);
                Il2CppClass* klass = il2cpp::vm::GenericClass::GetClass(gklass);
                type = &klass->byval_arg;
            }
            types[i] = type;
        }
    }

    const Il2CppGenericInst* sharedInst = il2cpp::vm::MetadataCache::GetGenericInst(types, inst->type_argc);

    return sharedInst;
}

static il2cpp::vm::Il2CppGenericMethodPointers MakeGenericMethodPointers(const Il2CppGenericMethodIndices* methodIndicies, bool isFullyShared)
{
    IL2CPP_ASSERT(methodIndicies->methodIndex >= 0 && methodIndicies->invokerIndex >= 0);
    if (static_cast<uint32_t>(methodIndicies->methodIndex) < s_Il2CppCodeRegistration->genericMethodPointersCount && static_cast<uint32_t>(methodIndicies->invokerIndex) < s_Il2CppCodeRegistration->invokerPointersCount)
    {
        Il2CppMethodPointer virtualMethod;
        Il2CppMethodPointer method;
        method = s_Il2CppCodeRegistration->genericMethodPointers[methodIndicies->methodIndex];
        if (methodIndicies->adjustorThunkIndex != -1)
        {
            virtualMethod = s_Il2CppCodeRegistration->genericAdjustorThunks[methodIndicies->adjustorThunkIndex];
        }
        else
        {
            virtualMethod = method;
        }
        return { method, virtualMethod, s_Il2CppCodeRegistration->invokerPointers[methodIndicies->invokerIndex], isFullyShared };
    }
    return { NULL, NULL, NULL, false };
}

il2cpp::vm::Il2CppGenericMethodPointers il2cpp::vm::MetadataCache::GetGenericMethodPointers(const MethodInfo* methodDefinition, const Il2CppGenericContext* context)
{
    Il2CppGenericMethod method = { 0 };
    method.methodDefinition = const_cast<MethodInfo*>(methodDefinition);
    method.context.class_inst = context->class_inst;
    method.context.method_inst = context->method_inst;

    Il2CppMethodTableMapIter iter = s_MethodTableMap.find(&method);
    if (iter != s_MethodTableMap.end())
        return MakeGenericMethodPointers(iter->second, false);

    // get the shared version if it exists
    method.context.class_inst = GetSharedInst(context->class_inst);
    method.context.method_inst = GetSharedInst(context->method_inst);

    iter = s_MethodTableMap.find(&method);
    if (iter != s_MethodTableMap.end())
        return MakeGenericMethodPointers(iter->second, false);

    // get the fully shared version if it exists
    method.context.class_inst = GetFullySharedInst(methodDefinition->klass->genericContainerHandle, context->class_inst);
    method.context.method_inst = GetFullySharedInst(methodDefinition->genericContainerHandle, context->method_inst);

    iter = s_MethodTableMap.find(&method);
    if (iter != s_MethodTableMap.end())
        return MakeGenericMethodPointers(iter->second, true);

    return { NULL, NULL, NULL };
}

const Il2CppType* il2cpp::vm::MetadataCache::GetIl2CppTypeFromIndex(const Il2CppImage* image, TypeIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetIl2CppTypeFromIndex(index);
}

const Il2CppType* il2cpp::vm::MetadataCache::GetTypeFromRgctxDefinition(const Il2CppRGCTXDefinition* rgctxDef)
{
    return il2cpp::vm::GlobalMetadata::GetTypeFromRgctxDefinition(rgctxDef);
}

const Il2CppGenericMethod* il2cpp::vm::MetadataCache::GetGenericMethodFromRgctxDefinition(const Il2CppRGCTXDefinition* rgctxDef)
{
    return il2cpp::vm::GlobalMetadata::GetGenericMethodFromRgctxDefinition(rgctxDef);
}

std::pair<const Il2CppType*, const MethodInfo*> il2cpp::vm::MetadataCache::GetConstrainedCallFromRgctxDefinition(const Il2CppRGCTXDefinition* rgctxDef)
{
    return il2cpp::vm::GlobalMetadata::GetConstrainedCallFromRgctxDefinition(rgctxDef);
}

const MethodInfo* il2cpp::vm::MetadataCache::GetMethodInfoFromVTableSlot(const Il2CppClass* klass, int32_t vTableSlot)
{
    return il2cpp::vm::GlobalMetadata::GetMethodInfoFromVTableSlot(klass, vTableSlot);
}

static int CompareIl2CppTokenAdjustorThunkPair(const void* pkey, const void* pelem)
{
    return (int)(((Il2CppTokenAdjustorThunkPair*)pkey)->token - ((Il2CppTokenAdjustorThunkPair*)pelem)->token);
}

Il2CppMethodPointer il2cpp::vm::MetadataCache::GetAdjustorThunk(const Il2CppImage* image, uint32_t token)
{
    if (hybridclr::metadata::IsInterpreterIndex(image->token))
    {
        return hybridclr::metadata::MetadataModule::GetAdjustorThunk(image, token);
    }
    if (image->codeGenModule->adjustorThunkCount == 0)
        return NULL;

    Il2CppTokenAdjustorThunkPair key;
    memset(&key, 0, sizeof(Il2CppTokenAdjustorThunkPair));
    key.token = token;

    const Il2CppTokenAdjustorThunkPair* result = (const Il2CppTokenAdjustorThunkPair*)bsearch(&key, image->codeGenModule->adjustorThunks,
        image->codeGenModule->adjustorThunkCount, sizeof(Il2CppTokenAdjustorThunkPair), CompareIl2CppTokenAdjustorThunkPair);

    if (result == NULL)
        return NULL;

    return result->adjustorThunk;
}

Il2CppMethodPointer il2cpp::vm::MetadataCache::GetMethodPointer(const Il2CppImage* image, uint32_t token)
{
    uint32_t rid = GetTokenRowId(token);
    uint32_t table =  GetTokenType(token);
    if (rid == 0)
        return NULL;

    if (hybridclr::metadata::IsInterpreterImage(image))
    {
        return hybridclr::metadata::MetadataModule::GetMethodPointer(image, token);
    }

    IL2CPP_ASSERT(rid <= image->codeGenModule->methodPointerCount);

    return image->codeGenModule->methodPointers[rid - 1];
}

InvokerMethod il2cpp::vm::MetadataCache::GetMethodInvoker(const Il2CppImage* image, uint32_t token)
{
    uint32_t rid = GetTokenRowId(token);
    uint32_t table = GetTokenType(token);
    if (rid == 0)
        return Runtime::GetMissingMethodInvoker();
    if (hybridclr::metadata::IsInterpreterImage(image))
    {
        return hybridclr::metadata::MetadataModule::GetMethodInvoker(image, token);
    }
    int32_t index = image->codeGenModule->invokerIndices[rid - 1];

    if (index == kMethodIndexInvalid)
        return Runtime::GetMissingMethodInvoker();

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) < s_Il2CppCodeRegistration->invokerPointersCount);
    return s_Il2CppCodeRegistration->invokerPointers[index];
}

const Il2CppInteropData* il2cpp::vm::MetadataCache::GetInteropDataForType(const Il2CppType* type)
{
    IL2CPP_ASSERT(type != NULL);
    InteropDataMap::iterator interopData = s_InteropData.find_first(type);
    if (interopData == s_InteropData.end())
        return NULL;

    return interopData;
}

static bool MatchTokens(Il2CppTokenIndexMethodTuple key, Il2CppTokenIndexMethodTuple element)
{
    return key.token < element.token;
}

static bool GenericInstancesMatch(const MethodInfo* method, const MethodInfo* matchingMethod)
{
    if (method->genericMethod->context.class_inst != NULL && matchingMethod->genericMethod->context.class_inst != NULL)
    {
        if (!il2cpp::metadata::Il2CppGenericInstCompare::AreEqual(method->genericMethod->context.class_inst, matchingMethod->genericMethod->context.class_inst))
            return false;
    }

    if (method->genericMethod->context.method_inst != NULL && matchingMethod->genericMethod->context.method_inst != NULL)
    {
        if (!il2cpp::metadata::Il2CppGenericInstCompare::AreEqual(method->genericMethod->context.method_inst, matchingMethod->genericMethod->context.method_inst))
            return false;
    }

    return true;
}

Il2CppMethodPointer il2cpp::vm::MetadataCache::GetReversePInvokeWrapper(const Il2CppImage* image, const MethodInfo* method)
{
    if (hybridclr::metadata::IsInterpreterImage(image))
    {
        return hybridclr::metadata::MetadataModule::GetReversePInvokeWrapper(image, method);
    }
    if (image->codeGenModule->reversePInvokeWrapperCount == 0)
        return NULL;

    // For each image (i.e. assembly), the reverse pinvoke wrapper indices are in an array sorted by
    // metadata token. Each entry also might have the method metadata pointer, which is used to further
    // find methods that have a matching metadata token.

    Il2CppTokenIndexMethodTuple key;
    memset(&key, 0, sizeof(Il2CppTokenIndexMethodTuple));
    key.token = method->token;

    // Binary search for a range which matches the metadata token.
    auto begin = image->codeGenModule->reversePInvokeWrapperIndices;
    auto end = image->codeGenModule->reversePInvokeWrapperIndices + image->codeGenModule->reversePInvokeWrapperCount;
    auto matchingRange = std::equal_range(begin, end, key, &MatchTokens);

    int32_t index = -1;
    auto numberOfMatches = std::distance(matchingRange.first, matchingRange.second);
    if (numberOfMatches == 1)
    {
        if (method->genericMethod == NULL)
        {
            // We found one non-generic method.
            index = matchingRange.first->index;
        }
        else
        {
            // We found one generic method - let's make sure the class and method generic instances match. This reverse p/invoke
            // wrapper might be for a different inflated generic instance.
            const MethodInfo* possibleMatch = il2cpp::metadata::GenericMethod::GetMethod(il2cpp::vm::GlobalMetadata::GetGenericMethodFromTokenMethodTuple(matchingRange.first));
            if (possibleMatch->genericMethod != NULL && GenericInstancesMatch(method, possibleMatch))
                index = matchingRange.first->index;
        }
    }
    else if (numberOfMatches > 1)
    {
        // Multiple generic instance methods share the same token, since it is from the generic method definition.
        // To find the proper method, look for the one with a matching method metadata pointer.
        const Il2CppTokenIndexMethodTuple* currentMatch = matchingRange.first;
        const Il2CppTokenIndexMethodTuple* lastMatch = matchingRange.second;
        while (currentMatch != lastMatch)
        {
            // First, check the method metadata, and use it if it has been initialized.
            // If not, let's fall back to the generic method.
            const MethodInfo* possibleMatch = (const MethodInfo*)*currentMatch->method;
            if (!il2cpp::vm::GlobalMetadata::IsRuntimeMetadataInitialized(possibleMatch))
                possibleMatch = il2cpp::metadata::GenericMethod::GetMethod(il2cpp::vm::GlobalMetadata::GetGenericMethodFromTokenMethodTuple(currentMatch));
            if (possibleMatch == method)
            {
                index = currentMatch->index;
                break;
            }
            currentMatch++;
        }
    }

    if (index == -1)
        return NULL;

    IL2CPP_ASSERT(index >= 0 && static_cast<uint32_t>(index) < s_Il2CppCodeRegistration->reversePInvokeWrapperCount);
    return s_Il2CppCodeRegistration->reversePInvokeWrappers[index];
}

static const Il2CppType* GetReducedType(const Il2CppType* type)
{
    if (type->byref)
        return &il2cpp_defaults.object_class->byval_arg;

    if (il2cpp::vm::Type::IsEnum(type))
        type = il2cpp::vm::Type::GetUnderlyingType(type);

    switch (type->type)
    {
        case IL2CPP_TYPE_BOOLEAN:
            return &il2cpp_defaults.byte_class->byval_arg;
        case IL2CPP_TYPE_CHAR:
            return &il2cpp_defaults.uint16_class->byval_arg;
        case IL2CPP_TYPE_BYREF:
        case IL2CPP_TYPE_CLASS:
        case IL2CPP_TYPE_OBJECT:
        case IL2CPP_TYPE_STRING:
        case IL2CPP_TYPE_ARRAY:
        case IL2CPP_TYPE_SZARRAY:
            return &il2cpp_defaults.object_class->byval_arg;
        case IL2CPP_TYPE_GENERICINST:
            if (il2cpp::vm::Type::GenericInstIsValuetype(type))
            {
                // We can't inflate a generic instance that contains generic arguments
                if (il2cpp::metadata::GenericMetadata::ContainsGenericParameters(type))
                    return type;

                const Il2CppGenericInst* sharedInst = GetSharedInst(type->data.generic_class->context.class_inst);
                Il2CppGenericClass* gklass = il2cpp::metadata::GenericMetadata::GetGenericClass(type->data.generic_class->type, sharedInst);
                Il2CppClass* klass = il2cpp::vm::GenericClass::GetClass(gklass);
                return &klass->byval_arg;
            }

            return &il2cpp_defaults.object_class->byval_arg;
        default:
            return type;
    }
}

il2cpp::vm::Il2CppUnresolvedCallStubs il2cpp::vm::MetadataCache::GetUnresovledCallStubs(const MethodInfo* method)
{
    il2cpp::vm::Il2CppUnresolvedCallStubs stubs;
    stubs.stubsFound = false;

    il2cpp::metadata::Il2CppSignature signature;
    signature.Count = method->parameters_count + 1;
    signature.Types = (const Il2CppType**)alloca(signature.Count * sizeof(Il2CppType*));

    signature.Types[0] = GetReducedType(method->return_type);
    for (int i = 0; i < method->parameters_count; ++i)
        signature.Types[i + 1] = GetReducedType(method->parameters[i]);

    Il2CppUnresolvedSignatureMapIter it = s_pUnresolvedSignatureMap->find(signature);
    if (it != s_pUnresolvedSignatureMap->end())
    {
        if (il2cpp::vm::Method::IsInstance(method))
        {
            stubs.methodPointer = s_Il2CppCodeRegistration->unresolvedInstanceCallPointers[it->second];
            stubs.virtualMethodPointer = s_Il2CppCodeRegistration->unresolvedVirtualCallPointers[it->second];
            stubs.stubsFound = true;
        }
        else
        {
            stubs.methodPointer = s_Il2CppCodeRegistration->unresolvedStaticCallPointers[it->second];
            stubs.virtualMethodPointer = stubs.methodPointer;
            stubs.stubsFound = true;
        }
    }
    else
    {
        const MethodInfo* entryPointNotFoundMethod = il2cpp::vm::Method::GetEntryPointNotFoundMethodInfo();
        stubs.methodPointer = entryPointNotFoundMethod->methodPointer;
        stubs.virtualMethodPointer = entryPointNotFoundMethod->methodPointer;
    }

    return stubs;
}

const Il2CppAssembly* il2cpp::vm::MetadataCache::GetAssemblyFromIndex(AssemblyIndex index)
{
    if (index == kGenericContainerIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index <= s_AssembliesCount);
    return s_AssembliesTable + index;
}

const Il2CppAssembly* il2cpp::vm::MetadataCache::GetAssemblyByName(const char* nameToFind)
{
    const char* assemblyName = hybridclr::GetAssemblyNameFromPath(nameToFind);

    il2cpp::utils::VmStringUtils::CaseInsensitiveComparer comparer;

    for (int i = 0; i < s_AssembliesCount; i++)
    {
        const Il2CppAssembly* assembly = s_AssembliesTable + i;

        if (comparer(assembly->aname.name, assemblyName) || comparer(assembly->image->name, assemblyName))
            return assembly;
    }

    il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

    for (auto assembly : s_cliAssemblies)
    {
        if (comparer(assembly->aname.name, assemblyName) || comparer(assembly->image->name, assemblyName))
            return assembly;
    }

    return nullptr;
}

void il2cpp::vm::MetadataCache::RegisterInterpreterAssembly(Il2CppAssembly* assembly)
{
    il2cpp::vm::Assembly::Register(assembly);
    s_cliAssemblies.push_back(assembly);
}

const Il2CppAssembly* il2cpp::vm::MetadataCache::LoadAssemblyFromBytes(const char* assemblyBytes, size_t length)
{
    il2cpp::os::FastAutoLock lock(&il2cpp::vm::g_MetadataLock);

    Il2CppAssembly* newAssembly = hybridclr::metadata::Assembly::LoadFromBytes(assemblyBytes, length, true);
    // avoid register placeholder assembly twicely.
    for (Il2CppAssembly* ass : s_cliAssemblies)
    {
        if (ass == newAssembly)
        {
            il2cpp::vm::Assembly::InvalidateAssemblyList();
            return ass;
        }
    }
    RegisterInterpreterAssembly(newAssembly);
    return newAssembly;
}

const Il2CppGenericMethod* il2cpp::vm::MetadataCache::FindGenericMethod(std::function<bool(const Il2CppGenericMethod*)> predic)
{
    for (auto e : s_MethodTableMap)
    {
        if (predic(e.first))
        {
            return e.first;
        }
    }
    return nullptr;
}

void il2cpp::vm::MetadataCache::FixThreadLocalStaticOffsetForFieldLocked(FieldInfo* field, int32_t offset, const il2cpp::os::FastAutoLock& lock)
{
    s_ThreadLocalStaticOffsetMap[field] = offset;
}

Il2CppImage* il2cpp::vm::MetadataCache::GetImageFromIndex(ImageIndex index)
{
    if (index == kGenericContainerIndexInvalid)
        return NULL;

    IL2CPP_ASSERT(index <= s_ImagesCount);
    return s_ImagesTable + index;
}

Il2CppClass* il2cpp::vm::MetadataCache::GetTypeInfoFromType(const Il2CppType* type)
{
    if (type == NULL)
        return NULL;

    return il2cpp::vm::GlobalMetadata::GetTypeInfoFromType(type);
}

Il2CppClass* il2cpp::vm::MetadataCache::GetTypeInfoFromHandle(Il2CppMetadataTypeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetTypeInfoFromHandle(handle);
}

Il2CppMetadataGenericContainerHandle il2cpp::vm::MetadataCache::GetGenericContainerFromGenericClass(const Il2CppImage* image, const Il2CppGenericClass* genericClass)
{
    return il2cpp::vm::GlobalMetadata::GetGenericContainerFromGenericClass(genericClass);
}

Il2CppMetadataGenericContainerHandle il2cpp::vm::MetadataCache::GetGenericContainerFromMethod(Il2CppMetadataMethodDefinitionHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetGenericContainerFromMethod(handle);
}

Il2CppMetadataGenericParameterHandle il2cpp::vm::MetadataCache::GetGenericParameterFromType(const Il2CppType* type)
{
    return il2cpp::vm::GlobalMetadata::GetGenericParameterFromType(type);
}

Il2CppClass* il2cpp::vm::MetadataCache::GetContainerDeclaringType(Il2CppMetadataGenericContainerHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetContainerDeclaringType(handle);
}

Il2CppClass* il2cpp::vm::MetadataCache::GetParameterDeclaringType(Il2CppMetadataGenericParameterHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetParameterDeclaringType(handle);
}

Il2CppMetadataGenericParameterHandle il2cpp::vm::MetadataCache::GetGenericParameterFromIndex(Il2CppMetadataGenericContainerHandle handle, GenericContainerParameterIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetGenericParameterFromIndex(handle, index);
}

const Il2CppType* il2cpp::vm::MetadataCache::GetGenericParameterConstraintFromIndex(Il2CppMetadataGenericParameterHandle handle, GenericParameterConstraintIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetGenericParameterConstraintFromIndex(handle, index);
}

Il2CppClass* il2cpp::vm::MetadataCache::GetNestedTypeFromOffset(const Il2CppClass* klass, TypeNestedTypeIndex offset)
{
    return il2cpp::vm::GlobalMetadata::GetNestedTypeFromOffset(klass, offset);
}

const Il2CppType* il2cpp::vm::MetadataCache::GetInterfaceFromOffset(const Il2CppClass* klass, TypeInterfaceIndex offset)
{
    return il2cpp::vm::GlobalMetadata::GetInterfaceFromOffset(klass, offset);
}

Il2CppInterfaceOffsetInfo il2cpp::vm::MetadataCache::GetInterfaceOffsetInfo(const Il2CppClass* klass, TypeInterfaceOffsetIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetInterfaceOffsetInfo(klass, index);
}

static int CompareIl2CppTokenRangePair(const void* pkey, const void* pelem)
{
    return (int)(((Il2CppTokenRangePair*)pkey)->token - ((Il2CppTokenRangePair*)pelem)->token);
}

il2cpp::vm::RGCTXCollection il2cpp::vm::MetadataCache::GetRGCTXs(const Il2CppImage* image, uint32_t token)
{
    RGCTXCollection collection = { 0, NULL };
    if (image->codeGenModule->rgctxRangesCount == 0)
        return collection;

    Il2CppTokenRangePair key;
    memset(&key, 0, sizeof(Il2CppTokenRangePair));
    key.token = token;

    const Il2CppTokenRangePair* res = (const Il2CppTokenRangePair*)bsearch(&key, image->codeGenModule->rgctxRanges, image->codeGenModule->rgctxRangesCount, sizeof(Il2CppTokenRangePair), CompareIl2CppTokenRangePair);

    if (res == NULL)
        return collection;

    collection.count = res->range.length;
    collection.items = image->codeGenModule->rgctxs + res->range.start;

    return collection;
}

const uint8_t* il2cpp::vm::MetadataCache::GetFieldDefaultValue(const FieldInfo* field, const Il2CppType** type)
{
    return il2cpp::vm::GlobalMetadata::GetFieldDefaultValue(field, type);
}

const uint8_t* il2cpp::vm::MetadataCache::GetParameterDefaultValue(const MethodInfo* method, int32_t parameterPosition, const Il2CppType** type, bool* isExplicitySetNullDefaultValue)
{
    return il2cpp::vm::GlobalMetadata::GetParameterDefaultValue(method, parameterPosition, type, isExplicitySetNullDefaultValue);
}

int il2cpp::vm::MetadataCache::GetFieldMarshaledSizeForField(const FieldInfo* field)
{
    return il2cpp::vm::GlobalMetadata::GetFieldMarshaledSizeForField(field);
}

int32_t il2cpp::vm::MetadataCache::GetFieldOffsetFromIndexLocked(const Il2CppClass* klass, int32_t fieldIndexInType, FieldInfo* field, const il2cpp::os::FastAutoLock& lock)
{
    int32_t offset = il2cpp::vm::GlobalMetadata::GetFieldOffset(klass, fieldIndexInType, field);
    if (offset < 0)
    {
        AddThreadLocalStaticOffsetForFieldLocked(field, offset & ~THREAD_LOCAL_STATIC_MASK, lock);
        return THREAD_STATIC_FIELD_OFFSET;
    }
    return offset;
}

void il2cpp::vm::MetadataCache::AddThreadLocalStaticOffsetForFieldLocked(FieldInfo* field, int32_t offset, const il2cpp::os::FastAutoLock& lock)
{
    s_ThreadLocalStaticOffsetMap.add(field, offset);
}

int32_t il2cpp::vm::MetadataCache::GetThreadLocalStaticOffsetForField(FieldInfo* field)
{
    IL2CPP_ASSERT(field->offset == THREAD_STATIC_FIELD_OFFSET);

    il2cpp::os::FastAutoLock lock(&g_MetadataLock);
    Il2CppThreadLocalStaticOffsetHashMapIter iter = s_ThreadLocalStaticOffsetMap.find(field);
    IL2CPP_ASSERT(iter != s_ThreadLocalStaticOffsetMap.end());
    return iter->second;
}

Il2CppMetadataCustomAttributeHandle il2cpp::vm::MetadataCache::GetCustomAttributeTypeToken(const Il2CppImage* image, uint32_t token)
{
    return il2cpp::vm::GlobalMetadata::GetCustomAttributeTypeToken(image, token);
}

il2cpp::metadata::CustomAttributeDataReader  il2cpp::vm::MetadataCache::GetCustomAttributeDataReader(const Il2CppImage* image, uint32_t token)
{
    return il2cpp::vm::GlobalMetadata::GetCustomAttributeDataReader(image, token);
}

il2cpp::metadata::CustomAttributeDataReader  il2cpp::vm::MetadataCache::GetCustomAttributeDataReader(Il2CppMetadataCustomAttributeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetCustomAttributeDataReader(handle);
}

const Il2CppAssembly* il2cpp::vm::MetadataCache::GetReferencedAssembly(const Il2CppAssembly* assembly, int32_t referencedAssemblyTableIndex)
{
    return il2cpp::vm::GlobalMetadata::GetReferencedAssembly(assembly, referencedAssemblyTableIndex, s_AssembliesTable, s_AssembliesCount);
}

void il2cpp::vm::MetadataCache::InitializeAllMethodMetadata()
{
    il2cpp::vm::GlobalMetadata::InitializeAllMethodMetadata();
}

void* il2cpp::vm::MetadataCache::InitializeRuntimeMetadata(uintptr_t* metadataPointer)
{
    return il2cpp::vm::GlobalMetadata::InitializeRuntimeMetadata(metadataPointer, true);
}

void il2cpp::vm::MetadataCache::WalkPointerTypes(WalkTypesCallback callback, void* context)
{
    os::FastAutoLock lock(&g_MetadataLock);

    for (PointerTypeMap::iterator it = s_MetadataCache.m_PointerTypes.UnlockedBegin(); it != s_MetadataCache.m_PointerTypes.UnlockedEnd(); it++)
    {
        callback(it->second, context);
    }
}

Il2CppMetadataTypeHandle il2cpp::vm::MetadataCache::GetTypeHandleFromIndex(const Il2CppImage* image, TypeDefinitionIndex typeIndex)
{
    return il2cpp::vm::GlobalMetadata::GetTypeHandleFromIndex(typeIndex);
}

Il2CppMetadataTypeHandle il2cpp::vm::MetadataCache::GetTypeHandleFromType(const Il2CppType* type)
{
    return il2cpp::vm::GlobalMetadata::GetTypeHandleFromType(type);
}

bool il2cpp::vm::MetadataCache::TypeIsNested(Il2CppMetadataTypeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::TypeIsNested(handle);
}

bool il2cpp::vm::MetadataCache::TypeIsValueType(Il2CppMetadataTypeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::TypeIsValueType(handle);
}

bool il2cpp::vm::MetadataCache::StructLayoutPackIsDefault(Il2CppMetadataTypeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::StructLayoutPackIsDefault(handle);
}

int32_t il2cpp::vm::MetadataCache::StructLayoutPack(Il2CppMetadataTypeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::StructLayoutPack(handle);
}

bool il2cpp::vm::MetadataCache::StructLayoutSizeIsDefault(Il2CppMetadataTypeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::StructLayoutSizeIsDefault(handle);
}

std::pair<const char*, const char*> il2cpp::vm::MetadataCache::GetTypeNamespaceAndName(Il2CppMetadataTypeHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetTypeNamespaceAndName(handle);
}

Il2CppMetadataTypeHandle il2cpp::vm::MetadataCache::GetNestedTypes(Il2CppClass *klass, void* *iter)
{
    return GetNestedTypes(
        klass->typeMetadataHandle,
        iter
    );
}

Il2CppMetadataTypeHandle il2cpp::vm::MetadataCache::GetNestedTypes(Il2CppMetadataTypeHandle handle, void** iter)
{
    return il2cpp::vm::GlobalMetadata::GetNestedTypes(handle, iter);
}

Il2CppMetadataFieldInfo il2cpp::vm::MetadataCache::GetFieldInfo(const Il2CppClass* klass, TypeFieldIndex fieldIndex)
{
    return il2cpp::vm::GlobalMetadata::GetFieldInfo(klass, fieldIndex);
}

Il2CppMetadataMethodInfo il2cpp::vm::MetadataCache::GetMethodInfo(const Il2CppClass* klass, TypeMethodIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetMethodInfo(klass, index);
}

Il2CppMetadataParameterInfo il2cpp::vm::MetadataCache::GetParameterInfo(const Il2CppClass* klass, Il2CppMetadataMethodDefinitionHandle handle, MethodParameterIndex paramIndex)
{
    return il2cpp::vm::GlobalMetadata::GetParameterInfo(klass, handle, paramIndex);
}

Il2CppMetadataPropertyInfo il2cpp::vm::MetadataCache::GetPropertyInfo(const Il2CppClass* klass, TypePropertyIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetPropertyInfo(klass, index);
}

Il2CppMetadataEventInfo il2cpp::vm::MetadataCache::GetEventInfo(const Il2CppClass* klass, TypeEventIndex index)
{
    return il2cpp::vm::GlobalMetadata::GetEventInfo(klass, index);
}

uint32_t il2cpp::vm::MetadataCache::GetGenericContainerCount(Il2CppMetadataGenericContainerHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetGenericContainerCount(handle);
}

void il2cpp::vm::MetadataCache::MakeGenericArgType(Il2CppMetadataGenericContainerHandle containerHandle, Il2CppMetadataGenericParameterHandle paramHandle, Il2CppType* arg)
{
    return il2cpp::vm::GlobalMetadata::MakeGenericArgType(containerHandle, paramHandle, arg);
}

bool il2cpp::vm::MetadataCache::GetGenericContainerIsMethod(Il2CppMetadataGenericContainerHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetGenericContainerIsMethod(handle);
}

int16_t il2cpp::vm::MetadataCache::GetGenericConstraintCount(Il2CppMetadataGenericParameterHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetGenericConstraintCount(handle);
}

const char* il2cpp::vm::MetadataCache::GetGenericParameterName(Il2CppMetadataGenericParameterHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetGenericParameterName(handle);
}

Il2CppGenericParameterInfo il2cpp::vm::MetadataCache::GetGenericParameterInfo(Il2CppMetadataGenericParameterHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetGenericParameterInfo(handle);
}

uint16_t il2cpp::vm::MetadataCache::GetGenericParameterFlags(Il2CppMetadataGenericParameterHandle handle)
{
    return il2cpp::vm::GlobalMetadata::GetGenericParameterFlags(handle);
}

const MethodInfo* il2cpp::vm::MetadataCache::GetMethodInfoFromCatchPoint(const Il2CppImage* image, const Il2CppCatchPoint* cp)
{
    return il2cpp::vm::GlobalMetadata::GetMethodInfoFromCatchPoint(cp);
}

const MethodInfo* il2cpp::vm::MetadataCache::GetMethodInfoFromSequencePoint(const Il2CppImage* image, const Il2CppSequencePoint* seqPoint)
{
    return il2cpp::vm::GlobalMetadata::GetMethodInfoFromSequencePoint(seqPoint);
}

Il2CppClass* il2cpp::vm::MetadataCache::GetTypeInfoFromTypeSourcePair(const Il2CppImage* image, const Il2CppTypeSourceFilePair* pair)
{
    return il2cpp::vm::GlobalMetadata::GetTypeInfoFromTypeSourcePair(pair);
}
