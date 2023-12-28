#pragma once

#include "il2cpp-config.h"
#include "il2cpp-runtime-stats.h"

struct Il2CppGenericClass;
struct Il2CppGenericMethod;

namespace il2cpp
{
namespace vm
{
    void MetadataAllocInitialize();
    void MetadataAllocCleanup();

    // These allocators assume the g_MetadataLock lock is held
    //[WL] Calloc will memset allocated memroy to zero, Malloc will not!
    void* MetadataMalloc(size_t size, Il2CppMemStat label);
    void* MetadataCalloc(size_t count, size_t size, Il2CppMemStat label);

// These metadata structures have their own locks, since they do lightweight initialization
    Il2CppGenericClass* MetadataAllocGenericClass();
    Il2CppGenericMethod* MetadataAllocGenericMethod();

    std::size_t MetadataTotalMemSize();

#if IL2CPP_ENABLE_MEM_STATS
    std::size_t mem_stats_get_metadata_free();
#endif //IL2CPP_ENABLE_MEM_STATS

} // namespace vm
} // namespace il2cpp
