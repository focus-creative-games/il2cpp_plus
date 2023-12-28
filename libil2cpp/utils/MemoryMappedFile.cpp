#include "il2cpp-config.h"

#if !RUNTIME_TINY

#include "MemoryMappedFile.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"
#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID
#include "os/Posix/FileHandle.h"
#include "os/Android/GenericMemoryMappedFile.h"
#include "os/Debug.h"
#endif

namespace il2cpp
{
namespace utils
{
    static baselib::ReentrantLock s_Mutex;
    static std::map<void*, os::FileHandle*> s_MappedAddressToMappedFileObject;
    static std::map<void*, int64_t> s_MappedAddressToMappedLength;

// These are 2 fallback functions, used when we can't memory map files inside Apk
#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID
    void* MapGeneric(os::FileHandle* file, int64_t length, int64_t offset, int32_t access)
    {
        os::FastAutoLock lock(&s_Mutex);

        int64_t unused = 0;
        os::MemoryMappedFileError error = os::NO_MEMORY_MAPPED_FILE_ERROR;
        os::FileHandle* mappedFileHandle = os::GenericMemoryMappedFile::Create(file, NULL, 0, &unused, (os::MemoryMappedFileAccess)access, 0, &error);
        if (error != 0)
            return NULL;

        int64_t actualOffset = offset;
        void* address = os::GenericMemoryMappedFile::View(mappedFileHandle, &length, offset, (os::MemoryMappedFileAccess)access, &actualOffset, &error);

        if (address != NULL)
        {
            address = (uint8_t*)address + (offset - actualOffset);
            if (os::GenericMemoryMappedFile::OwnsDuplicatedFileHandle(mappedFileHandle))
                s_MappedAddressToMappedFileObject[address] = mappedFileHandle;
            s_MappedAddressToMappedLength[address] = length;
        }

        if (address != NULL)
        {
            utils::Logging::Write("[ERROR] Compressed file in Apk can't be memory-mapped! Setup noCompress in aaptOptions for less memory usage!");
        }

        return address;
    }

    bool UnmapGeneric(void* address, int64_t length)
    {
        os::FastAutoLock lock(&s_Mutex);

        if (length == 0)
        {
            std::map<void*, int64_t>::iterator entry = s_MappedAddressToMappedLength.find(address);
            if (entry != s_MappedAddressToMappedLength.end())
            {
                length = entry->second;
                s_MappedAddressToMappedLength.erase(entry);
            }
        }

        bool success = os::GenericMemoryMappedFile::UnmapView(address, length);
        if (!success)
            return false;

        std::map<void*, os::FileHandle*>::iterator entry = s_MappedAddressToMappedFileObject.find(address);
        if (entry != s_MappedAddressToMappedFileObject.end())
        {
            bool result = os::GenericMemoryMappedFile::Close(entry->second);
            s_MappedAddressToMappedFileObject.erase(entry);
            return result;
        }

        return true;
    }
#endif

    void* MemoryMappedFile::Map(os::FileHandle* file)
    {
        return Map(file, 0, 0);
    }

    bool MemoryMappedFile::Unmap(void* address)
    {
        return Unmap(address, 0);
    }

    void* MemoryMappedFile::Map(os::FileHandle* file, int64_t length, int64_t offset)
    {
        return Map(file, length, offset, os::MMAP_FILE_ACCESS_READ);
    }

    void* MemoryMappedFile::Map(os::FileHandle* file, int64_t length, int64_t offset, int32_t access)
    {
        os::FastAutoLock lock(&s_Mutex);

        int64_t unused = 0;
        os::MemoryMappedFileError error = os::NO_MEMORY_MAPPED_FILE_ERROR;
        os::FileHandle* mappedFileHandle = os::MemoryMappedFile::Create(file, NULL, 0, &unused, (os::MemoryMappedFileAccess)access, 0, &error);
        if (error != 0)
#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID
            return MapGeneric(file, length, offset, access);
#else
            return NULL;
#endif

        int64_t actualOffset = offset;
        void* address = os::MemoryMappedFile::View(mappedFileHandle, &length, offset, (os::MemoryMappedFileAccess)access, &actualOffset, &error);

        if (address != NULL)
        {
            address = (uint8_t*)address + (offset - actualOffset);
#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID
            address = (uint8_t*)address + file->fdOffset;
            length -= file->fdOffset;
#endif            
            if (os::MemoryMappedFile::OwnsDuplicatedFileHandle(mappedFileHandle))
                s_MappedAddressToMappedFileObject[address] = mappedFileHandle;
            s_MappedAddressToMappedLength[address] = length;
        }

        return address;
    }

    bool MemoryMappedFile::Unmap(void* address, int64_t length)
    {
        os::FastAutoLock lock(&s_Mutex);

        if (length == 0)
        {
            std::map<void*, int64_t>::iterator entry = s_MappedAddressToMappedLength.find(address);
            if (entry != s_MappedAddressToMappedLength.end())
            {
                length = entry->second;
                s_MappedAddressToMappedLength.erase(entry);
            }
        }

        bool success = os::MemoryMappedFile::UnmapView(address, length);
        if (!success)
#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID
            return UnmapGeneric(address, length);
#else
            return false;
#endif

        std::map<void*, os::FileHandle*>::iterator entry = s_MappedAddressToMappedFileObject.find(address);
        if (entry != s_MappedAddressToMappedFileObject.end())
        {
            bool result = os::MemoryMappedFile::Close(entry->second);
            s_MappedAddressToMappedFileObject.erase(entry);
            return result;
        }

        return true;
    }

    int64_t MemoryMappedFile::MapSize(void* address) {
        os::FastAutoLock lock(&s_Mutex);
        std::map<void*, int64_t>::iterator entry = s_MappedAddressToMappedLength.find(address);
        if (entry != s_MappedAddressToMappedLength.end())
        {
            return entry->second;
        }

        return 0;
    }
}
}

#endif
