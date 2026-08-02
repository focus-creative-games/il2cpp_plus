#pragma once

#include "il2cpp-object-internals.h"
#include "il2cpp-class-internals.h"
#include "mono-structs.h"

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
    class LIBIL2CPP_CODEGEN_API GC
    {
    public:
        static Il2CppArray* AllocPinnedArray(Il2CppReflectionType* t, int32_t length);
        static int32_t GetCollectionCount(int32_t generation);
        static int32_t GetGeneration(Il2CppObject* obj);
        static int32_t GetMaxGeneration();
        static int64_t GetAllocatedBytesForCurrentThread();
        static int64_t GetTotalAllocatedBytes(bool precise);
        static int64_t GetTotalMemory(bool forceFullCollection);
        static Il2CppObject* get_ephemeron_tombstone();
        static void AddPressure(uint64_t bytesAllocated);
        static void InternalCollect(int32_t generation);
        static void RemovePressure(uint64_t bytesRemoved);
        static void WaitForPendingFinalizers();
        static void _GetGCMemoryInfo(int64_t* highMemoryLoadThresholdBytes, int64_t* memoryLoadBytes, int64_t* totalAvailableMemoryBytes, int64_t* totalCommittedBytes, int64_t* heapSizeBytes, int64_t* fragmentedBytes);
        static void _ReRegisterForFinalize(Il2CppObject* o);
        static void _SuppressFinalize(Il2CppObject* o);
        static void register_ephemeron_array(Il2CppArray* array);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
