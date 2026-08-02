#include "il2cpp-config.h"
#include "Interlocked.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"
#include "gc/GarbageCollector.h"
#include "os/Atomic.h"
#include "vm/Exception.h"
#include <ctype.h>

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
namespace Threading
{
    int32_t Interlocked::Add(int32_t* location1, int32_t value)
    {
        return il2cpp::os::Atomic::Add(location1, value);
    }

    int32_t Interlocked::CompareExchange(int32_t* location1, int32_t value, int32_t comparand)
    {
        return il2cpp::os::Atomic::CompareExchange(location1, value, comparand);
    }

    int32_t Interlocked::Decrement(int32_t* location)
    {
        return il2cpp::os::Atomic::Decrement(location);
    }

    int32_t Interlocked::Exchange(int32_t* location1, int32_t value)
    {
        return il2cpp::os::Atomic::Exchange(location1, value);
    }

    int32_t Interlocked::Increment(int32_t* location)
    {
        return il2cpp::os::Atomic::Increment(location);
    }

    int64_t Interlocked::Add(int64_t* location1, int64_t value)
    {
        return il2cpp::os::Atomic::Add64(location1, value);
    }

    int64_t Interlocked::CompareExchange(int64_t* location1, int64_t value, int64_t comparand)
    {
        return il2cpp::os::Atomic::CompareExchange64(location1, value, comparand);
    }

    int64_t Interlocked::Decrement(int64_t* location)
    {
        return il2cpp::os::Atomic::Decrement64(location);
    }

    int64_t Interlocked::Exchange(int64_t* location1, int64_t value)
    {
        return il2cpp::os::Atomic::Exchange64(location1, value);
    }

    int64_t Interlocked::Increment(int64_t* location)
    {
        return il2cpp::os::Atomic::Increment64(location);
    }

    int64_t Interlocked::Read(int64_t* location)
    {
        return il2cpp::os::Atomic::Read64(location);
    }

    void Interlocked::CompareExchange(Il2CppObject** location1, Il2CppObject** value, Il2CppObject** comparand, Il2CppObject** result)
    {
        *result = il2cpp::os::Atomic::CompareExchangePointer(location1, *value, *comparand);
        il2cpp::gc::GarbageCollector::SetWriteBarrier(reinterpret_cast<void**>(location1));
    }

    void Interlocked::Exchange(Il2CppObject** location1, Il2CppObject** value, Il2CppObject** result)
    {
        *result = il2cpp::os::Atomic::ExchangePointer(location1, *value);
        il2cpp::gc::GarbageCollector::SetWriteBarrier(reinterpret_cast<void**>(location1));
    }

    void Interlocked::MemoryBarrierProcessWide()
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(Interlocked::MemoryBarrierProcessWide);
        IL2CPP_UNREACHABLE;
    }
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
