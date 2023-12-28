#include "il2cpp-config.h"
#include "os/Memory.h"
#include "utils/Memory.h"
#include "il2cpp-runtime-stats.h"

#include <cstdlib>

namespace il2cpp
{
namespace utils
{
    struct MonoMemoryCallbacks
    {
        int version;
        void *(*malloc_func)(size_t size);
        void *(*realloc_func)(void *mem, size_t count);
        void(*free_func)(void *mem);
        void *(*calloc_func)(size_t count, size_t size);
    };

    extern "C"
    {
        int32_t mono_set_allocator_vtable(MonoMemoryCallbacks* callbacks);
    }

    static MonoMemoryCallbacks s_MonoCallbacks =
    {
        1, //MONO_ALLOCATOR_VTABLE_VERSION
        NULL,
        NULL,
        NULL,
        NULL
    };

    static Il2CppMemoryCallbacks s_Callbacks =
    {
        malloc,
        os::Memory::AlignedAlloc,
        free,
        os::Memory::AlignedFree,
        calloc,
        realloc,
        os::Memory::AlignedReAlloc
    };

    void Memory::SetMemoryCallbacks(Il2CppMemoryCallbacks* callbacks)
    {
        memcpy(&s_Callbacks, callbacks, sizeof(Il2CppMemoryCallbacks));

#if IL2CPP_MONO_DEBUGGER
        // The debugger uses Mono code, so we need to remap the callbacks
        // for Mono allocations and frees to the same ones IL2CPP is using.
        s_MonoCallbacks.malloc_func = callbacks->malloc_func;
        s_MonoCallbacks.realloc_func = callbacks->realloc_func;
        s_MonoCallbacks.free_func = callbacks->free_func;
        s_MonoCallbacks.calloc_func = callbacks->calloc_func;
        int32_t installed = mono_set_allocator_vtable(&s_MonoCallbacks);
        IL2CPP_ASSERT(installed != 0);
        NO_UNUSED_WARNING(installed);
#endif
    }

    void* Memory::Malloc(size_t size)
    {
        return Malloc(size, IL2CPP_MEM_OS_ALLOCATOR);
    }

    void Memory::Free(void* memory){
        return Free(memory, IL2CPP_MEM_OS_ALLOCATOR);
    }

    void* Memory::Malloc(size_t size, Il2CppMemLabel label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        void* ret = s_Callbacks.malloc_func(size);
        if (ret) {
            il2cpp_mem_stats.il2cpp_malloc += size;
            il2cpp_mem_stats.lableSizes[label] += size;

            auto& sAllocMap = GetAllocMap();
            sAllocMap[ret] = size;
        }
        return ret;
#else
        return s_Callbacks.malloc_func(size);
#endif
    }

    void* Memory::AlignedMalloc(size_t size, size_t alignment, Il2CppMemLabel label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        void* ret = s_Callbacks.aligned_malloc_func(size, alignment);
        if (ret) {
            il2cpp_mem_stats.il2cpp_malloc += size;
            il2cpp_mem_stats.lableSizes[label] += size;
            auto& sAllocMap = GetAllocMap();
            sAllocMap[ret] = size;
        }
        return ret;
#else
        return s_Callbacks.aligned_malloc_func(size, alignment);
#endif
    }

    void Memory::Free(void* memory, Il2CppMemLabel label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        if (memory) {
            auto& sAllocMap = GetAllocMap();
            auto it = sAllocMap.find(memory);
            if (it != sAllocMap.end()) {
                il2cpp_mem_stats.il2cpp_malloc -= it->second;
                il2cpp_mem_stats.lableSizes[label] -= it->second;
                sAllocMap.erase(it);
            }
        }
#endif
        return s_Callbacks.free_func(memory);
    }

    void Memory::AlignedFree(void* memory, Il2CppMemLabel label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        if (memory) {
            auto& sAllocMap = GetAllocMap();
            auto it = sAllocMap.find(memory);
            if (it != sAllocMap.end()) {
                il2cpp_mem_stats.il2cpp_malloc -= it->second;
                il2cpp_mem_stats.lableSizes[label] -= it->second;
                sAllocMap.erase(it);
            }
        }
#endif
        return s_Callbacks.aligned_free_func(memory);
    }

    void* Memory::Calloc(size_t count, size_t size, Il2CppMemLabel label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        void* ret = s_Callbacks.calloc_func(count, size);
        if (ret) {
            il2cpp_mem_stats.il2cpp_malloc += size * count;
            il2cpp_mem_stats.lableSizes[label] += size * count;
            auto& sAllocMap = GetAllocMap();
            sAllocMap[ret] = size * count;
        }
        return ret;
#else
        return s_Callbacks.calloc_func(count, size);
#endif
    }

    void* Memory::Realloc(void* memory, size_t newSize, Il2CppMemLabel label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        void* ret = s_Callbacks.realloc_func(memory, newSize);
        auto& sAllocMap = GetAllocMap();
        if (memory) {
            auto it = sAllocMap.find(memory);
            if (it != sAllocMap.end()) {
                il2cpp_mem_stats.il2cpp_malloc -= it->second;
                il2cpp_mem_stats.lableSizes[label] -= it->second;
                sAllocMap.erase(it);
            }
        }
        if (ret) {
            il2cpp_mem_stats.il2cpp_malloc += newSize;
            il2cpp_mem_stats.lableSizes[label] += newSize;
            sAllocMap[ret] = newSize;
        }
        return ret;
#else
        return s_Callbacks.realloc_func(memory, newSize);
#endif
    }

    void* Memory::AlignedRealloc(void* memory, size_t newSize, size_t alignment, Il2CppMemLabel label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        void* ret = s_Callbacks.aligned_realloc_func(memory, newSize, alignment);
        auto& sAllocMap = GetAllocMap();
        if (memory) {
            auto it = sAllocMap.find(memory);
            if (it != sAllocMap.end()) {
                il2cpp_mem_stats.il2cpp_malloc -= it->second;
                il2cpp_mem_stats.lableSizes[label] -= it->second;
                sAllocMap.erase(it);
            }
        }
        if (ret) {
            il2cpp_mem_stats.il2cpp_malloc += newSize;
            il2cpp_mem_stats.lableSizes[label] += newSize;
            sAllocMap[ret] = newSize;
        }
        return ret;
#else
        return s_Callbacks.aligned_realloc_func(memory, newSize, alignment);
#endif
    }
} /* namespace utils */
} /* namespace il2cpp */
