#include "il2cpp-config.h"
#include "os/Memory.h"

#if IL2CPP_TARGET_WINDOWS

#include "WindowsHeaders.h"

namespace il2cpp
{
namespace os
{
namespace Memory
{
    void* AlignedAlloc(size_t size, size_t alignment)
    {
        return _aligned_malloc(size, alignment);
    }

    void* AlignedReAlloc(void* memory, size_t newSize, size_t alignment)
    {
        return _aligned_realloc(memory, newSize, alignment);
    }

    void AlignedFree(void* memory)
    {
        return _aligned_free(memory);
    }

    int32_t GetPageSize()
    {
        static int32_t pageSize = 0;
        if (pageSize == 0)
        {
            SYSTEM_INFO si;
            GetSystemInfo(&si);
            pageSize = si.dwPageSize;
        }

        return pageSize;
    }
}
}
}

#endif
