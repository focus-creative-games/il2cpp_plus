#include "il2cpp-config.h"
#include "Monitor.h"

#include "il2cpp-object-internals.h"
#include "vm/Exception.h"
#include "vm/Monitor.h"

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
    bool Monitor::Monitor_wait(Il2CppObject* obj, int32_t ms, bool allowInterruption)
    {
        IL2CPP_CHECK_ARG_NULL(obj);
        return il2cpp::vm::Monitor::TryWait(obj, ms);
    }

    int64_t Monitor::get_LockContentionCount()
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(Monitor::get_LockContentionCount);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    void Monitor::Enter(Il2CppObject* obj)
    {
        IL2CPP_CHECK_ARG_NULL(obj);
        il2cpp::vm::Monitor::Enter(obj);
    }

    void Monitor::InternalExit(Il2CppObject* obj)
    {
        IL2CPP_CHECK_ARG_NULL(obj);
        il2cpp::vm::Monitor::Exit(obj);
    }

    void Monitor::Monitor_pulse(Il2CppObject* obj)
    {
        IL2CPP_CHECK_ARG_NULL(obj);
        il2cpp::vm::Monitor::Pulse(obj);
    }

    void Monitor::Monitor_pulse_all(Il2CppObject* obj)
    {
        IL2CPP_CHECK_ARG_NULL(obj);
        il2cpp::vm::Monitor::PulseAll(obj);
    }

    void Monitor::try_enter_with_atomic_var(Il2CppObject* obj, int32_t millisecondsTimeout, bool allowInterruption, bool* lockTaken)
    {
        if (*lockTaken)
            vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException("lockTaken", "lockTaken must be false"));

        *lockTaken = il2cpp::vm::Monitor::TryEnter(obj, millisecondsTimeout);
    }
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
