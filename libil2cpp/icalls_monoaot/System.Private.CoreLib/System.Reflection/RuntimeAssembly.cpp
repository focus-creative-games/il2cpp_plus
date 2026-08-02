#include "il2cpp-config.h"
#include "RuntimeAssembly.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Object.h"
#include "vm/Image.h"
#include "vm/Reflection.h"

#include "os/File.h"
#include "os/Mutex.h"
#include "os/Path.h"
#include "utils/MemoryMappedFile.h"
#include "utils/PathUtils.h"
#include "utils/Runtime.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Assembly.h"
#include "vm/AssemblyName.h"
#include "vm/Exception.h"
#include "vm/Image.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/String.h"
#include <algorithm>
#include <vector>

namespace il2cpp
{
namespace icalls
{
namespace System
{
namespace Private
{
namespace CoreLib
{
namespace System
{
namespace Reflection
{
    static os::Mutex* s_ResourceDataMutex = nullptr;

    void RuntimeAssembly::AllocateStaticData()
    {
        s_ResourceDataMutex = new os::Mutex();
    }

    void RuntimeAssembly::FreeStaticData()
    {
        delete s_ResourceDataMutex;
        s_ResourceDataMutex = nullptr;
    }

    static void* LoadResourceFile(Il2CppReflectionAssembly* assembly)
    {
        std::string resourcesDirectory = utils::PathUtils::Combine(utils::Runtime::GetDataDir(), utils::StringView<char>("Resources"));

        std::string resourceFileName(assembly->assembly->image->name);
        resourceFileName += "-resources.dat";

        std::string resourceFilePath = utils::PathUtils::Combine(resourcesDirectory, resourceFileName);

        int error = 0;
        os::FileHandle* handle = os::File::Open(resourceFilePath, kFileModeOpen, kFileAccessRead, kFileShareRead, kFileOptionsNone, &error);
        if (error != 0)
            return NULL;

        void* fileBuffer = utils::MemoryMappedFile::Map(handle);

        os::File::Close(handle, &error);
        if (error != 0)
        {
            utils::MemoryMappedFile::Unmap(fileBuffer);
            fileBuffer = NULL;
            return NULL;
        }

        return fileBuffer;
    }

    static void* LoadResourceData(Il2CppReflectionAssembly* assembly, vm::EmbeddedResourceRecord record)
    {
        os::AutoLock lock(s_ResourceDataMutex);

        void* resourceData = vm::Image::GetCachedResourceData(record.image, record.name);
        if (resourceData != NULL)
            return resourceData;

        void* fileBuffer = vm::Image::GetCachedMemoryMappedResourceFile(assembly);
        if (fileBuffer == NULL)
        {
            fileBuffer = LoadResourceFile(assembly);
            if (fileBuffer == NULL)
                return NULL;

            vm::Image::CacheMemoryMappedResourceFile(assembly, fileBuffer);
        }

        resourceData = (uint8_t*)fileBuffer + record.offset;

        vm::Image::CacheResourceData(record, resourceData);

        return resourceData;
    }

    static int ReadFromBuffer(uint8_t* buffer, int offset, int size, void* output)
    {
        memcpy(output, buffer + offset, size);

        return size;
    }

    static std::vector<vm::EmbeddedResourceRecord> GetResourceRecords(Il2CppReflectionAssembly* assembly)
    {
        std::vector<vm::EmbeddedResourceRecord> resourceRecords;

        void* fileBuffer = vm::Image::GetCachedMemoryMappedResourceFile(assembly);
        if (fileBuffer == NULL)
        {
            fileBuffer = LoadResourceFile(assembly);
            if (fileBuffer == NULL)
                return resourceRecords;

            vm::Image::CacheMemoryMappedResourceFile(assembly, fileBuffer);
        }

        int32_t resourceRecordsSize = 0;
        uint32_t bytesRead = ReadFromBuffer((uint8_t*)fileBuffer, 0, sizeof(int32_t), &resourceRecordsSize);

        int32_t currentResourceDataOffset = bytesRead + resourceRecordsSize;

        int32_t numberOfResources = 0;
        bytesRead += ReadFromBuffer((uint8_t*)fileBuffer, bytesRead, sizeof(int32_t), &numberOfResources);
        for (int resourceIndex = 0; resourceIndex < numberOfResources; ++resourceIndex)
        {
            uint32_t resourceDataSize = 0;
            bytesRead += ReadFromBuffer((uint8_t*)fileBuffer, bytesRead, sizeof(int32_t), &resourceDataSize);

            int32_t resourceNameSize = 0;
            bytesRead += ReadFromBuffer((uint8_t*)fileBuffer, bytesRead, sizeof(int32_t), &resourceNameSize);

            std::vector<char> resourceName(resourceNameSize);
            bytesRead += ReadFromBuffer((uint8_t*)fileBuffer, bytesRead, resourceNameSize, &resourceName[0]);

            resourceRecords.push_back(vm::EmbeddedResourceRecord(assembly->assembly->image, std::string(resourceName.begin(), resourceName.end()), currentResourceDataOffset, resourceDataSize));

            currentResourceDataOffset += resourceDataSize;
        }

        return resourceRecords;
    }

    class ResourceNameMatcher
    {
    public:
        ResourceNameMatcher(const std::string& resourceNameToFind) : needle(resourceNameToFind)
        {}

        bool operator()(const vm::EmbeddedResourceRecord& data) const
        {
            return data.name == needle;
        }

    private:
        std::string needle;
    };


    bool RuntimeAssembly::GetManifestResourceInfoInternal(Il2CppQCallAssembly assembly, Il2CppString* name, Il2CppManifestResourceInfo* info)
    {
        std::vector<vm::EmbeddedResourceRecord> resourceRecords = GetResourceRecords(assembly);
        if (std::find_if(resourceRecords.begin(), resourceRecords.end(), ResourceNameMatcher(utils::StringUtils::Utf16ToUtf8(name->chars))) != resourceRecords.end())
        {
            info->location = IL2CPP_RESOURCE_LOCATION_EMBEDDED | IL2CPP_RESOURCE_LOCATION_IN_MANIFEST;

            IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(Assembly::GetManifestResourceInfoInternal, "We have not yet implemented file or assembly resources.");

            return true;
        }

        return false;
    }

    intptr_t RuntimeAssembly::GetManifestResourceInternal(Il2CppQCallAssembly assembly, Il2CppString* name, int32_t* size, Il2CppObjectHandleOnStack module)
    {
        std::vector<vm::EmbeddedResourceRecord> resourceRecords = GetResourceRecords(assembly);
        std::vector<vm::EmbeddedResourceRecord>::iterator resource = std::find_if(resourceRecords.begin(), resourceRecords.end(), ResourceNameMatcher(utils::StringUtils::Utf16ToUtf8(name->chars)));
        if (resource != resourceRecords.end())
        {
            module = (Il2CppObject*)vm::Reflection::GetModuleObject(assembly->image);
            *size = resource->size;
            intptr_t result;
            result = (intptr_t)LoadResourceData(assembly, *resource);
            return result;
        }

        return 0;
    }

    intptr_t RuntimeAssembly::InternalGetReferencedAssemblies(Il2CppReflectionAssembly* assembly)
    {
        VoidPtrArray assemblyPointers;
        vm::AssemblyNameVector referencedAssemblies;
        vm::Assembly::GetReferencedAssemblies(assembly->assembly, &referencedAssemblies);
        for (vm::AssemblyNameVector::const_iterator aname = referencedAssemblies.begin(); aname != referencedAssemblies.end(); ++aname)
        {
            Il2CppMonoAssemblyName* monoAssemblyName = (Il2CppMonoAssemblyName*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppMonoAssemblyName));
            il2cpp::vm::AssemblyName::FillNativeAssemblyName(*(*aname), monoAssemblyName, true);
            assemblyPointers.push_back(monoAssemblyName);
        }

        return reinterpret_cast<intptr_t>(void_ptr_array_to_gptr_array(assemblyPointers));
    }

    void RuntimeAssembly::GetEntryPoint(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res)
    {
        const MethodInfo* method = vm::Image::GetEntryPoint(assembly->image);
        if (method == NULL)
            res = nullptr;
        else
            res = (Il2CppObject*)vm::Reflection::GetMethodObject(method, NULL);
    }

    void RuntimeAssembly::GetExportedTypes(Il2CppQCallAssembly assembly_h, Il2CppObjectHandleOnStack res)
    {
        res = vm::Image::GetTypes(assembly_h->image, true);
    }

    static std::string GetAssemblyPath(const Il2CppAssembly* assembly)
    {
        std::string executableDirectory = os::Path::GetApplicationFolder();
        std::replace(executableDirectory.begin(), executableDirectory.end(), '\\', '/');
        return utils::StringUtils::Printf("%s/%s.dll", executableDirectory.c_str(), assembly->aname.name);
    }

    enum AssemblyInfoKind
    {
        Location = 1,
        CodeBase = 2,
        FullName = 3,
        ImageRuntimeVersion = 4
    };

    void RuntimeAssembly::GetInfo(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res, int32_t kind)
    {
        switch (kind)
        {
            case Location:
                res = vm::String::New(GetAssemblyPath(assembly).c_str());
                break;
            case CodeBase:
                res = vm::String::New(utils::StringUtils::Printf("file://%s", GetAssemblyPath(assembly).c_str()).c_str());
                break;
            case FullName:
                res = vm::String::New(vm::AssemblyName::AssemblyNameToString(assembly->aname).c_str());
                break;
            case ImageRuntimeVersion:
                res = vm::String::New(vm::Runtime::GetFrameworkVersion());
                break;
        }
    }

    void RuntimeAssembly::GetManifestModuleInternal(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res)
    {
        NOT_SUPPORTED_IL2CPP(Assembly::GetManifestModuleInternal, "This icall is not supported by il2cpp.");
    }

    void RuntimeAssembly::GetManifestResourceNames(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res)
    {
        std::vector<vm::EmbeddedResourceRecord> resourceRecords = GetResourceRecords(assembly);

        IL2CPP_ASSERT(resourceRecords.size() <= static_cast<size_t>(std::numeric_limits<il2cpp_array_size_t>::max()));
        Il2CppArray* resourceNameArray = vm::Array::New(il2cpp_defaults.string_class, static_cast<il2cpp_array_size_t>(resourceRecords.size()));
        for (size_t i = 0; i < resourceRecords.size(); ++i)
            il2cpp_array_setref(resourceNameArray, i, vm::String::New(resourceRecords[i].name.c_str()));

        res = resourceNameArray;
    }

    void RuntimeAssembly::GetModulesInternal(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res)
    {
        Il2CppArray* arr = vm::Array::New(il2cpp_defaults.module_class, 1);
        il2cpp_array_setref(arr, 0, vm::Reflection::GetModuleObject(vm::Assembly::GetImage(assembly)));
        res = arr;
    }

    void RuntimeAssembly::GetTopLevelForwardedTypes(Il2CppQCallAssembly assembly_h, Il2CppObjectHandleOnStack res)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeAssembly::GetTopLevelForwardedTypes);
        IL2CPP_UNREACHABLE;
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
