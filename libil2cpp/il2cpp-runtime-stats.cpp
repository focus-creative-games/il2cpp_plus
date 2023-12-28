#include "il2cpp-runtime-stats.h"

Il2CppRuntimeStats il2cpp_runtime_stats = {{ 0 }};

#if IL2CPP_ENABLE_MEM_STATS
Il2CppMemStats il2cpp_mem_stats = {{ 0 }};

const char* g_Il2CppMemLabelName[IL2CPP_MEM_LABLE_COUNT] = {
    "IL2CPP_MEM_META_POOL               ", //metadata_pool
    "IL2CPP_MEM_HASH_TABLE              ",// hash used
    "IL2CPP_MEM_FromTypeDefinition      ",
    "IL2CPP_MEM_GLOBAL_METADATA         ",
    "IL2CPP_MEM_MEMORY_MAP              ",
    "IL2CPP_MEM_GC_HANDLE               ",
    "IL2CPP_MEM_Cryptography            ",
    "IL2CPP_MEM_il2cpp_alloc            ",
    "IL2CPP_MEM_IMAGE                   ",
    "IL2CPP_MEM_STRING                  ",
    "IL2CPP_MEM_MonoGenericParameterInfo",
    "IL2CPP_MEM_GatherMetadata          ",
    "IL2CPP_MEM_THREAD                  ",
    "IL2CPP_MEM_DYNAMIC_ARRAY           ",
    "IL2CPP_MEM_MonoAssemblyName        ",
    "IL2CPP_MEM_RCW                     ",
    "IL2CPP_MEM_GPtrArray               ",
    "IL2CPP_MEM_MonoMethodSignature     ",
    "IL2CPP_MEM_MonoMethodHeader        ",
    "IL2CPP_MEM_METADATA_CACHE          ",
    "IL2CPP_MEM_CustomAttributesCache   ",
    "IL2CPP_MEM_DomainData              ",
    "IL2CPP_MEM_FindHandle              ",
    "IL2CPP_MEM_OS_ALLOCATOR            ",
    "IL2CPP_MEM_WeakReference           ",
    "IL2CPP_MEM_ActivationFactory       ",
    "IL2CPP_MEM_ManagedObject           ",
    "IL2CPP_MEM_CpuUsageState           ",
    "IL2CPP_MEM_Socket                  ",
    "IL2CPP_MEM_CustomAttribute         ",
    "IL2CPP_MEM_GC                      ",
    "IL2CPP_MEM_MonoDebugLocalsInfo     ",
    "IL2CPP_MEM_DEBUGGER                ",           
};

std::map<void*, size_t>& GetAllocMap() 
{
	static std::map<void*, size_t> sAllocMap;
	return sAllocMap;
}

std::map<void*, size_t>& GetHashAllocMap()
{
	static std::map<void*, size_t> sHashAllocMap;
	return sHashAllocMap;
}

void mem_stats_add_on_label(Il2CppMemStat label, std::size_t s)
{
	il2cpp_mem_stats.meta.sizes[label] += s;
}

#endif //IL2CPP_ENABLE_MEM_STATS
