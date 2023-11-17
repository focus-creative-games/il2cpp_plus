#include "il2cpp-config.h"
#include <vector>
#include <map>
#include <limits>
#include "os/Mutex.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Image.h"
#include "vm/MetadataCache.h"
#include "vm/Reflection.h"
#include "vm/StackTrace.h"
#include "vm/Type.h"
#include "utils/HashUtils.h"
#include "utils/Il2CppHashMap.h"
#include "utils/MemoryMappedFile.h"
#include "utils/StringUtils.h"
#include "vm-utils/VmStringUtils.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"

#include "os/Atomic.h"
#include "hybridclr/metadata/Image.h"

struct NamespaceAndNamePairHash
{
    size_t operator()(const std::pair<const char*, const char*>& pair) const
    {
        return il2cpp::utils::HashUtils::Combine(il2cpp::utils::StringUtils::Hash(pair.first), il2cpp::utils::StringUtils::Hash(pair.second));
    }
};

struct NamespaceAndNamePairEquals
{
    bool operator()(const std::pair<const char*, const char*>& p1, const std::pair<const char*, const char*>& p2) const
    {
        return !strcmp(p1.first, p2.first) && !strcmp(p1.second, p2.second);
    }
};

struct NamespaceAndNamePairLess
{
    bool operator()(const std::pair<const char*, const char*>& p1, const std::pair<const char*, const char*>& p2) const
    {
        int namespaceCompare = strcmp(p1.first, p2.first);

        if (namespaceCompare < 0)
            return true;

        if (namespaceCompare > 0)
            return false;

        return strcmp(p1.second, p2.second) < 0;
    }
};

struct Il2CppNameToTypeHandleHashTable : public Il2CppHashMap<std::pair<const char*, const char*>, Il2CppMetadataTypeHandle, NamespaceAndNamePairHash, NamespaceAndNamePairEquals>
{
    typedef Il2CppHashMap<std::pair<const char*, const char*>, Il2CppMetadataTypeHandle, NamespaceAndNamePairHash, NamespaceAndNamePairEquals> Base;
    Il2CppNameToTypeHandleHashTable() : Base()
    {
    }
};

namespace il2cpp
{
namespace vm
{
    const Il2CppAssembly* Image::GetAssembly(const Il2CppImage* image)
    {
        return image->assembly;
    }

    typedef il2cpp::vm::StackFrames::const_reverse_iterator StackReverseIterator;

    static bool IsSystemType(Il2CppClass* klass)
    {
        return strcmp(klass->namespaze, "System") == 0 && strcmp(klass->name, "Type") == 0;
    }

    static bool IsSystemReflectionAssembly(Il2CppClass* klass)
    {
        return strcmp(klass->namespaze, "System.Reflection") == 0 && strcmp(klass->name, "Assembly") == 0;
    }

    static StackReverseIterator GetNextImageFromStack(StackReverseIterator first, StackReverseIterator last)
    {
        for (StackReverseIterator it = first; it != last; it++)
        {
            Il2CppClass* klass = it->method->klass;
            if (klass->image != NULL && !IsSystemType(klass) && !IsSystemReflectionAssembly(klass))
            {
                return it;
            }
        }

        return last;
    }

    const Il2CppImage* Image::GetExecutingImage()
    {
        const il2cpp::vm::StackFrames& stack = *StackTrace::GetStackFrames();
        StackReverseIterator imageIt = GetNextImageFromStack(stack.rbegin(), stack.rend());

        if (imageIt != stack.rend())
        {
            return imageIt->method->klass->image;
        }

        // Fallback to corlib if no image is found
        return const_cast<Il2CppImage*>(Image::GetCorlib());
    }

    const Il2CppImage* Image::GetCallingImage()
    {
        const il2cpp::vm::StackFrames& stack = *StackTrace::GetStackFrames();
        StackReverseIterator imageIt = GetNextImageFromStack(stack.rbegin(), stack.rend());

        if (imageIt != stack.rend())
        {
            imageIt = GetNextImageFromStack(++imageIt, stack.rend());

            if (imageIt != stack.rend())
            {
                return imageIt->method->klass->image;
            }
        }

        // Fallback to corlib if no image is found
        return const_cast<Il2CppImage*>(Image::GetCorlib());
    }

    const char * Image::GetName(const Il2CppImage* image)
    {
        return image->name;
    }

    const char * Image::GetFileName(const Il2CppImage* image)
    {
        return image->name;
    }

    const MethodInfo* Image::GetEntryPoint(const Il2CppImage* image)
    {
        return MetadataCache::GetAssemblyEntryPoint(image);
    }

    Il2CppImage* Image::GetCorlib()
    {
        return il2cpp_defaults.corlib;
    }

    static baselib::ReentrantLock s_ClassFromNameMutex;

    static void AddNestedTypesToNametoClassHashTable(Il2CppNameToTypeHandleHashTable* hashTable, const char* namespaze, const std::string& parentName, Il2CppMetadataTypeHandle handle)
    {
        std::pair<const char*, const char*> namespaceAndName = MetadataCache::GetTypeNamespaceAndName(handle);

        std::string name = parentName + "/" + namespaceAndName.second;
        char* pName = (char*)IL2CPP_CALLOC(name.size() + 1, sizeof(char));
        strcpy(pName, name.c_str());

        hashTable->insert(std::make_pair(std::make_pair(namespaze, (const char*)pName), handle));

        void* iter = NULL;
        while (Il2CppMetadataTypeHandle nestedClass = MetadataCache::GetNestedTypes(handle, &iter))
            AddNestedTypesToNametoClassHashTable(hashTable, namespaze, name, nestedClass);
    }

    static void AddNestedTypesToNametoClassHashTable(const Il2CppImage* image, Il2CppMetadataTypeHandle handle)
    {
        std::pair<const char*, const char*> namespaceAndName = MetadataCache::GetTypeNamespaceAndName(handle);

        void* iter = NULL;
        while (Il2CppMetadataTypeHandle nestedClass = MetadataCache::GetNestedTypes(handle, &iter))
        {
            AddNestedTypesToNametoClassHashTable(image->nameToClassHashTable, namespaceAndName.first, namespaceAndName.second, nestedClass);
        }
    }

// This must be called when the s_ClassFromNameMutex is held.
    static void AddTypeToNametoClassHashTable(const Il2CppImage* image, Il2CppMetadataTypeHandle typeHandle)
    {
        if (typeHandle == NULL)
            return;

        // don't add nested types
        if (MetadataCache::TypeIsNested(typeHandle))
            return;

        if (image != il2cpp_defaults.corlib)
            AddNestedTypesToNametoClassHashTable(image, typeHandle);

        image->nameToClassHashTable->insert(std::make_pair(MetadataCache::GetTypeNamespaceAndName(typeHandle), typeHandle));
    }

    void Image::InitNestedTypes(const Il2CppImage* image)
    {
        for (uint32_t index = 0; index < image->typeCount; index++)
        {
            Il2CppMetadataTypeHandle handle = MetadataCache::GetAssemblyTypeHandle(image, index);

            // don't add nested types
            if (MetadataCache::TypeIsNested(handle))
                return;

            AddNestedTypesToNametoClassHashTable(image, handle);
        }

        for (uint32_t index = 0; index < image->exportedTypeCount; index++)
        {
            Il2CppMetadataTypeHandle handle = MetadataCache::GetAssemblyExportedTypeHandle(image, index);

            // don't add nested types
            if (MetadataCache::TypeIsNested(handle))
                return;

            AddNestedTypesToNametoClassHashTable(image, handle);
        }
    }

    static void InitImageNameToTypeHandleHashTable(const Il2CppImage* image)
    {
        os::FastAutoLock lock(&s_ClassFromNameMutex);
        if (!image->nameToClassHashTable)
        {
            image->nameToClassHashTable = new Il2CppNameToTypeHandleHashTable();
            for (uint32_t index = 0; index < image->typeCount; index++)
            {
                AddTypeToNametoClassHashTable(image, MetadataCache::GetAssemblyTypeHandle(image, index));
            }

            for (uint32_t index = 0; index < image->exportedTypeCount; index++)
            {
                AddTypeToNametoClassHashTable(image, MetadataCache::GetAssemblyExportedTypeHandle(image, index));
            }
        }
    }

    Il2CppClass* Image::ClassFromName(const Il2CppImage* image, const char* namespaze, const char* name)
    {
        if (!image->nameToClassHashTable)
        {
            InitImageNameToTypeHandleHashTable(image);
        }

        Il2CppNameToTypeHandleHashTable::const_iterator iter = image->nameToClassHashTable->find(std::make_pair(namespaze, name));
        if (iter != image->nameToClassHashTable->end())
            return MetadataCache::GetTypeInfoFromHandle(iter->second);

        return NULL;
    }


    Il2CppMetadataTypeHandle Image::TypeHandleFromName(const Il2CppImage* image, const char* namespaze, const char* name)
    {
        if (!image->nameToClassHashTable)
        {
            InitImageNameToTypeHandleHashTable(image);
        }

        Il2CppNameToTypeHandleHashTable::const_iterator iter = image->nameToClassHashTable->find(std::make_pair(namespaze, name));
        if (iter != image->nameToClassHashTable->end())
            return iter->second;

        return NULL;
    }

    static bool IsExported(const Il2CppClass* type)
    {
        if ((type->flags & TYPE_ATTRIBUTE_VISIBILITY_MASK) == TYPE_ATTRIBUTE_PUBLIC)
        {
            return true;
        }

        if ((type->flags & TYPE_ATTRIBUTE_VISIBILITY_MASK) == TYPE_ATTRIBUTE_NESTED_PUBLIC)
        {
            IL2CPP_ASSERT(type->declaringType);
            return IsExported(type->declaringType);
        }

        return false;
    }

    void Image::GetTypes(const Il2CppImage* image, bool exportedOnly, TypeVector* target)
    {
        uint32_t typeCount = Image::GetNumTypes(image);
        target->reserve(typeCount);

        for (uint32_t sourceIndex = 0; sourceIndex < typeCount; sourceIndex++)
        {
            const Il2CppClass* type = Image::GetType(image, sourceIndex);
            if (strcmp(type->name, "<Module>") == 0)
            {
                continue;
            }
            if (exportedOnly && !IsExported(type))
            {
                continue;
            }

            target->push_back(type);
        }
    }

    Il2CppArray* Image::GetTypes(const Il2CppImage* image, bool exportedOnly)
    {
        TypeVector types;
        GetTypes(image, exportedOnly, &types);
        Il2CppArray* result = Array::New(il2cpp_defaults.monotype_class, (il2cpp_array_size_t)types.size());
        size_t index = 0;
        for (vm::TypeVector::const_iterator type = types.begin(); type != types.end(); ++type)
        {
            Il2CppReflectionType* reflectionType = Reflection::GetTypeObject(&(*type)->byval_arg);
            il2cpp_array_setref(result, index, reflectionType);
            index++;
        }

        return result;
    }

    uint32_t Image::GetNumTypes(const Il2CppImage* image)
    {
        return image->typeCount;
    }

    const Il2CppClass* Image::GetType(const Il2CppImage* image, AssemblyTypeIndex index)
    {
        IL2CPP_ASSERT(index <= std::numeric_limits<AssemblyTypeIndex>::max());
        return MetadataCache::GetTypeInfoFromHandle(MetadataCache::GetAssemblyTypeHandle(image, index));
    }

    static bool StringsMatch(const char* left, const char* right, bool ignoreCase)
    {
        if (!ignoreCase)
        {
            return strcmp(left, right) == 0;
        }
        else
        {
            utils::VmStringUtils::CaseInsensitiveComparer comparer;
            return comparer(left, right);
        }
    }

    static bool ClassMatches(Il2CppMetadataTypeHandle typeHandle, const char* namespaze, bool ignoreCase, const char* name)
    {
        if (MetadataCache::TypeIsNested(typeHandle))
            return false;

        std::pair<const char*, const char*> namespaceAndName = MetadataCache::GetTypeNamespaceAndName(typeHandle);
        return StringsMatch(name, namespaceAndName.second, ignoreCase) && StringsMatch(namespaze, namespaceAndName.first, ignoreCase);
    }

    static Il2CppClass* FindClassMatching(const Il2CppImage* image, const char* namespaze, const char *name, bool ignoreCase)
    {
        for (uint32_t i = 0; i < image->typeCount; i++)
        {
            Il2CppMetadataTypeHandle typeHandle = MetadataCache::GetAssemblyTypeHandle(image, i);
            if (ClassMatches(typeHandle, namespaze, ignoreCase, name))
                return MetadataCache::GetTypeInfoFromHandle(typeHandle);
        }

        return NULL;
    }

    static Il2CppClass* FindExportedClassMatching(const Il2CppImage* image, const char* namespaze, const char *name, bool ignoreCase)
    {
        for (uint32_t i = 0; i < image->exportedTypeCount; i++)
        {
            Il2CppMetadataTypeHandle typeHandle = MetadataCache::GetAssemblyExportedTypeHandle(image, i);
            if (ClassMatches(typeHandle, namespaze, ignoreCase, name))
                return MetadataCache::GetTypeInfoFromHandle(typeHandle);
        }

        return NULL;
    }

    static Il2CppClass* FindNestedType(Il2CppClass* klass, const char* name, bool ignoreCase)
    {
        void* iter = NULL;
        while (Il2CppClass* nestedType = Class::GetNestedTypes(klass, &iter))
        {
            if (StringsMatch(name, nestedType->name, ignoreCase))
                return nestedType;
        }

        return NULL;
    }

    Il2CppClass* Image::FromTypeNameParseInfo(const Il2CppImage* image, const TypeNameParseInfo &info, bool ignoreCase)
    {
        const char* ns = info.ns().c_str();
        const char* name = info.name().c_str();
        Il2CppClass *parent_class = FindClassMatching(image, ns, name, ignoreCase);

        if (parent_class == NULL)
        {
            parent_class = FindExportedClassMatching(image, ns, name, ignoreCase);
            if (parent_class == NULL)
                return NULL;
        }

        std::vector<std::string>::const_iterator it = info.nested().begin();

        while (it != info.nested().end())
        {
            parent_class = FindNestedType(parent_class, (*it).c_str(), ignoreCase);

            if (parent_class == NULL)
                return NULL;

            ++it;
        }

        return parent_class;
    }

    static baselib::ReentrantLock s_Mutex;
    static std::vector<Image::EmbeddedResourceData> s_CachedResourceData;
    static std::map<Il2CppReflectionAssembly*, void*> s_CachedMemoryMappedResourceFiles;

    void Image::CacheMemoryMappedResourceFile(Il2CppReflectionAssembly* assembly, void* memoryMappedFile)
    {
        os::FastAutoLock lock(&s_Mutex);
        s_CachedMemoryMappedResourceFiles[assembly] = memoryMappedFile;
    }

    void* Image::GetCachedMemoryMappedResourceFile(Il2CppReflectionAssembly* assembly)
    {
        os::FastAutoLock lock(&s_Mutex);
        std::map<Il2CppReflectionAssembly*, void*>::iterator entry = s_CachedMemoryMappedResourceFiles.find(assembly);
        if (entry != s_CachedMemoryMappedResourceFiles.end())
            return entry->second;

        return NULL;
    }

    void Image::CacheResourceData(EmbeddedResourceRecord record, void* data)
    {
        os::FastAutoLock lock(&s_Mutex);
        s_CachedResourceData.push_back(EmbeddedResourceData(record, data));
    }

    void* Image::GetCachedResourceData(const Il2CppImage* image, const std::string& name)
    {
        os::FastAutoLock lock(&s_Mutex);
        for (std::vector<EmbeddedResourceData>::iterator it = s_CachedResourceData.begin(); it != s_CachedResourceData.end(); ++it)
        {
            if (it->record.image == image && it->record.name == name)
                return it->data;
        }

        return NULL;
    }

    void Image::ClearCachedResourceData()
    {
        os::FastAutoLock lock(&s_Mutex);
        for (std::map<Il2CppReflectionAssembly*, void*>::iterator i = s_CachedMemoryMappedResourceFiles.begin(); i != s_CachedMemoryMappedResourceFiles.end(); ++i)
            utils::MemoryMappedFile::Unmap(i->second);

        s_CachedMemoryMappedResourceFiles.clear();
        s_CachedResourceData.clear();
    }
} /* namespace vm */
} /* namespace il2cpp */
