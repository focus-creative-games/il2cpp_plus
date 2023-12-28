#pragma once

#include <atomic>
#include <map>

#include <stdint.h>

struct Il2CppRuntimeStats
{
    std::atomic<uint64_t> new_object_count;
    std::atomic<uint64_t> initialized_class_count;
    // uint64_t generic_vtable_count;
    // uint64_t used_class_count;
    std::atomic<uint64_t> method_count;
    // uint64_t class_vtable_size;
    std::atomic<uint64_t> class_static_data_size;
    std::atomic<uint64_t> generic_instance_count;
    std::atomic<uint64_t> generic_class_count;
    std::atomic<uint64_t> inflated_method_count;
    std::atomic<uint64_t> inflated_type_count;
    // uint64_t delegate_creations;
    // uint64_t minor_gc_count;
    // uint64_t major_gc_count;
    // uint64_t minor_gc_time_usecs;
    // uint64_t major_gc_time_usecs;
    std::atomic<uint64_t> hashtable_mem;
    std::atomic<uint64_t> global_metadata_file_size;
    bool enabled;
};

extern Il2CppRuntimeStats il2cpp_runtime_stats;


typedef enum
{
    IL2CPP_MSTAT_TYPE,
    IL2CPP_MSTAT_CLASS,
    IL2CPP_MSTAT_METHOD,
    IL2CPP_MSTAT_FIELD,
    IL2CPP_MSTAT_EVENT,
    IL2CPP_MSTAT_PROPERTY,
    IL2CPP_MSTAT_GENERIC_INST,
    IL2CPP_MSTAT_INTERFACE,
    IL2CPP_MSTAT_RGCTX,

    IL2CPP_MSTAT_COUNT
} Il2CppMemStat;

typedef enum {
    IL2CPP_MEM_META_POOL, //metadata_pool
    IL2CPP_MEM_HASH_TABLE,// hash used
    IL2CPP_MEM_FromTypeDefinition,
    IL2CPP_MEM_GLOBAL_METADATA,
    IL2CPP_MEM_MEMORY_MAP,
    IL2CPP_MEM_GC_HANDLE,
    IL2CPP_MEM_Cryptography,
    IL2CPP_MEM_il2cpp_alloc,
    IL2CPP_MEM_IMAGE,
    IL2CPP_MEM_STRING,
    IL2CPP_MEM_MonoGenericParameterInfo,
    IL2CPP_MEM_GatherMetadata,
    IL2CPP_MEM_THREAD,
    IL2CPP_MEM_DYNAMIC_ARRAY,
    IL2CPP_MEM_MonoAssemblyName,
    IL2CPP_MEM_RCW,
    IL2CPP_MEM_GPtrArray,
    IL2CPP_MEM_MonoMethodSignature,
    IL2CPP_MEM_MonoMethodHeader,
    IL2CPP_MEM_METADATA_CACHE,
    IL2CPP_MEM_CustomAttributesCache,
    IL2CPP_MEM_DomainData,
    IL2CPP_MEM_FindHandle,
    IL2CPP_MEM_OS_ALLOCATOR,
    IL2CPP_MEM_WeakReference,
    IL2CPP_MEM_ActivationFactory,
    IL2CPP_MEM_ManagedObject,
    IL2CPP_MEM_CpuUsageState,
    IL2CPP_MEM_Socket,
    IL2CPP_MEM_CustomAttribute,
    IL2CPP_MEM_GC,
    IL2CPP_MEM_MonoDebugLocalsInfo,
    IL2CPP_MEM_DEBUGGER,
    IL2CPP_MEM_LABLE_COUNT,
} Il2CppMemLabel;

#if IL2CPP_ENABLE_MEM_STATS

//don't use std::atomic because assuming it's proteced by g_MetadataLock
struct Il2CppMetaMemStats {

    std::size_t meta_total; // total usage through MetadataAlloc
    std::size_t meta_wasted;  // wasted mem in MetadataAlloc pools
    std::size_t meta_region_count;

    std::size_t generic_class_count;
    std::size_t generic_class_size;

    std::size_t generic_method_count;
    std::size_t generic_method_size;

    std::size_t sizes[IL2CPP_MSTAT_COUNT];
};

struct Il2CppMemStats {
    //typedef std::atomic<uint64_t> size_t;

    std::size_t il2cpp_malloc;// total usage from IL2CPP_MALLOC

    Il2CppMetaMemStats meta;

    std::size_t hash_table;  //Note: only add malloc and realloc, no free

    //Other --------------

    std::size_t classFromTypeDef_count;

    std::size_t globalMetadataMapfile; //global-metadata.dat map file size

    std::size_t interal_calls_total; // s_InternalCalls count
    std::size_t interal_calls_resolved;// s_InternalCalls resolved

    std::size_t lableSizes[IL2CPP_MEM_LABLE_COUNT];
};

extern Il2CppMemStats il2cpp_mem_stats;
extern const char* g_Il2CppMemLabelName[IL2CPP_MEM_LABLE_COUNT];

// use static object to avoid globel variable init order issue.
std::map<void*, size_t>& GetAllocMap();
std::map<void*, size_t>& GetHashAllocMap();

void mem_stats_add_on_label(Il2CppMemStat label, std::size_t s);

#endif //IL2CPP_ENABLE_MEM_STATS