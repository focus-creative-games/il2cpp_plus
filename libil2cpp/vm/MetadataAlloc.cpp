#include "il2cpp-config.h"
#include "MetadataAlloc.h"
#include "il2cpp-class-internals.h"
#include "utils/MemoryPool.h"
#include "il2cpp-runtime-stats.h"

#if IL2CPP_SANITIZE_ADDRESS
#include "utils/MemoryPoolAddressSanitizer.h"
#endif
namespace il2cpp
{
namespace vm
{
#if IL2CPP_SANITIZE_ADDRESS
    typedef utils::MemoryPoolAddressSanitizer MemoryPoolType;
#else
    typedef utils::MemoryPool MemoryPoolType;
#endif

// we allocate these dynamically on runtime initialization
// because the pool uses standard allocators, and we want to give embedding
// client the chance to install their own allocator callbacks
    static MemoryPoolType* s_MetadataMemoryPool;
    static MemoryPoolType* s_GenericClassMemoryPool;
    static MemoryPoolType* s_GenericMethodMemoryPool;

// This initial size (256k/512k) allows us enough room to initialize metadata
// an empty Unity project and have a bit of room leftover.
    const size_t kInitialRegionSize = IL2CPP_SIZEOF_VOID_P * 64 * 1024;

    void MetadataAllocInitialize()
    {
#if IL2CPP_SANITIZE_ADDRESS
        s_MetadataMemoryPool = new utils::MemoryPoolAddressSanitizer(kInitialRegionSize);
        s_GenericClassMemoryPool = new utils::MemoryPoolAddressSanitizer();
        s_GenericMethodMemoryPool = new utils::MemoryPoolAddressSanitizer();
#else
        s_MetadataMemoryPool = new utils::MemoryPool(kInitialRegionSize);
        // these can use the default smaller initial pool size
        s_GenericClassMemoryPool = new utils::MemoryPool();
        s_GenericMethodMemoryPool = new utils::MemoryPool();
#endif
    }

    void MetadataAllocCleanup()
    {
        delete s_MetadataMemoryPool;
        s_MetadataMemoryPool = NULL;
        delete s_GenericClassMemoryPool;
        s_GenericClassMemoryPool = NULL;
        delete s_GenericMethodMemoryPool;
        s_GenericMethodMemoryPool = NULL;
    }

    void* MetadataMalloc(size_t size, Il2CppMemStat label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        mem_stats_add_on_label(label, size);
#endif 
        return s_MetadataMemoryPool->Malloc(size);
    }

    void* MetadataCalloc(size_t count, size_t size, Il2CppMemStat label)
    {
#if IL2CPP_ENABLE_MEM_STATS
        mem_stats_add_on_label(label, size * count);
#endif 
        return s_MetadataMemoryPool->Calloc(count, size);
    }

    Il2CppGenericClass* MetadataAllocGenericClass()
    {
#if IL2CPP_ENABLE_MEM_STATS
        size_t size = sizeof(Il2CppGenericClass);
        il2cpp_mem_stats.meta.generic_class_size += size;
        ++il2cpp_mem_stats.meta.generic_class_count;
#endif

        return (Il2CppGenericClass*)s_GenericClassMemoryPool->Calloc(1, sizeof(Il2CppGenericClass));
    }

    Il2CppGenericMethod* MetadataAllocGenericMethod()
    {
#if IL2CPP_ENABLE_MEM_STATS
        size_t size = sizeof(Il2CppGenericMethod);
        il2cpp_mem_stats.meta.generic_method_size += size;
        ++il2cpp_mem_stats.meta.generic_method_count;
#endif
        return (Il2CppGenericMethod*)s_GenericMethodMemoryPool->Calloc(1, sizeof(Il2CppGenericMethod));
    }

#if IL2CPP_ENABLE_MEM_STATS
    std::size_t mem_stats_get_metadata_free() {
        return s_MetadataMemoryPool->FreeSize() + s_GenericClassMemoryPool->FreeSize() + s_GenericMethodMemoryPool->FreeSize();
    }
#endif 

    std::size_t MetadataTotalMemSize() {
        std::size_t total = s_MetadataMemoryPool->TotalSize() + s_GenericClassMemoryPool->TotalSize() + s_GenericMethodMemoryPool->TotalSize();
        return total;
    }
}
}
