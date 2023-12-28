#include "il2cpp-config.h"

#if ENABLE_HMI_MODE && IL2CPP_TARGET_ANDROID
#include "os/File.h"
#include "os/MemoryMappedFile.h"
#include "os/Mutex.h"
#include "utils/dynamic_array.h"
#include "utils/Memory.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"

namespace il2cpp
{
namespace os
{
    class GenericMemoryMappedFile
    {
    public:
        static FileHandle* Create(FileHandle* file, const char* mapName, int32_t mode, int64_t *capacity, MemoryMappedFileAccess access, int32_t options, MemoryMappedFileError* error);
        static MemoryMappedFile::MemoryMappedFileHandle View(FileHandle* mappedFileHandle, int64_t* length, int64_t offset, MemoryMappedFileAccess access, int64_t* actualOffset, MemoryMappedFileError* error);
        static void Flush(MemoryMappedFile::MemoryMappedFileHandle memoryMappedFileData, int64_t length);
        static bool UnmapView(MemoryMappedFile::MemoryMappedFileHandle memoryMappedFileData, int64_t length);
        static bool Close(FileHandle* file);
        static void ConfigureHandleInheritability(FileHandle* file, bool inheritability);
        static bool OwnsDuplicatedFileHandle(FileHandle* file);
    };
}
}
#endif
