#include "il2cpp-config.h"
#include "GC.h"

#include "gc/GarbageCollector.h"
#include "il2cpp-class-internals.h"
#include "vm/Array.h"
#include "vm/Domain.h"
#include "vm/Exception.h"
#include "vm/Object.h"

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
    Il2CppArray* GC::AllocPinnedArray(Il2CppReflectionType* t, int32_t length)
    {
        return il2cpp::vm::Array::NewSpecific(il2cpp::vm::Class::FromIl2CppType(t->type), length);
    }

    int32_t GC::GetCollectionCount(int32_t generation)
    {
        return il2cpp::gc::GarbageCollector::GetCollectionCount(generation);
    }

    int32_t GC::GetGeneration(Il2CppObject* obj)
    {
        return il2cpp::gc::GarbageCollector::GetGeneration(obj);
    }

    int32_t GC::GetMaxGeneration()
    {
        return il2cpp::gc::GarbageCollector::GetMaxGeneration();
    }

    int64_t GC::GetAllocatedBytesForCurrentThread()
    {
        return 0;
    }

    int64_t GC::GetTotalAllocatedBytes(bool precise)
    {
        return 0;
    }

    int64_t GC::GetTotalMemory(bool forceFullCollection)
    {
        if (forceFullCollection)
            il2cpp::gc::GarbageCollector::Collect(il2cpp::gc::GarbageCollector::GetMaxGeneration());

        return il2cpp::gc::GarbageCollector::GetUsedHeapSize();
    }

    Il2CppObject* GC::get_ephemeron_tombstone()
    {
        return il2cpp::vm::Domain::GetCurrent()->ephemeron_tombstone;
    }

    void GC::AddPressure(uint64_t bytesAllocated)
    {
    }

    void GC::InternalCollect(int32_t generation)
    {
        il2cpp::gc::GarbageCollector::Collect(generation);
    }

    void GC::RemovePressure(uint64_t bytesRemoved)
    {
    }

    void GC::WaitForPendingFinalizers()
    {
        il2cpp::gc::GarbageCollector::WaitForPendingFinalizers();
    }

    void GC::_GetGCMemoryInfo(int64_t* highMemoryLoadThresholdBytes, int64_t* memoryLoadBytes, int64_t* totalAvailableMemoryBytes, int64_t* totalCommittedBytes, int64_t* heapSizeBytes, int64_t* fragmentedBytes)
    {
        highMemoryLoadThresholdBytes = 0;
        memoryLoadBytes = 0;
        totalAvailableMemoryBytes = 0;
        totalCommittedBytes = 0;
        heapSizeBytes = 0;
        fragmentedBytes = 0;
    }

    void GC::_ReRegisterForFinalize(Il2CppObject* o)
    {
        if (o == NULL)
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentNullException("obj"));

        il2cpp::gc::GarbageCollector::RegisterFinalizer(o);
    }

    void GC::_SuppressFinalize(Il2CppObject* o)
    {
        if (o == NULL)
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentNullException("obj"));

        il2cpp::gc::GarbageCollector::SuppressFinalizer(o);
    }

    void GC::register_ephemeron_array(Il2CppArray* array)
    {
        il2cpp::gc::GarbageCollector::EphemeronArrayAdd((Il2CppObject*)array);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
