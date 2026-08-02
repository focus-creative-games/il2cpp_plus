#include "Thread.h"
#include "il2cpp-object-internals.h"
#include "codegen/il2cpp-codegen.h"
#include "vm/Class.h"
#include "vm/Method.h"
#include "vm/Thread.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Threading
{
    // This is a work around for the Mono BCL implementing Thread apartments as a no-op
    int32_t il2cpp_intrinsic_thread_get_apartment_state(RuntimeObject* thisPtr)
    {
        return static_cast<uint8_t>(il2cpp::vm::Thread::GetApartmentState(reinterpret_cast<Il2CppThread*>(thisPtr)));
    }

    bool il2cpp_intrinsic_thread_set_apartment_state(RuntimeObject* thisPtr, int32_t state, bool throwOnError)
    {
        return il2cpp::vm::Thread::SetApartmentState(reinterpret_cast<Il2CppThread*>(thisPtr), static_cast<il2cpp::vm::ThreadApartmentState>(state), throwOnError);
    }

    IL2CPP_DISABLE_OPTIMIZATIONS
    IL2CPP_NO_INLINE void il2cpp_intrinsic_thread_spin_wait_nop()
    {
        // Mono calls this as in intrinsic to do a spin wait
        // The JIT will emit a NOP opcode
        // We'll just do a non-inlined call to a function that does nothing
    }

    IL2CPP_ENABLE_OPTIMIZATIONS

    void il2cpp_intrinsic_thread_sleep_internal(int32_t millisecondsTimeout)
    {
        const MethodInfo* sleepInternalMethod = il2cpp_defaults.thread_sleep_internal_method;
        IL2CPP_ASSERT(sleepInternalMethod);
        IL2CPP_ASSERT(sleepInternalMethod->parameters[0]->type == IL2CPP_TYPE_I4);
        IL2CPP_ASSERT(!il2cpp::vm::Method::IsInstance(sleepInternalMethod));

#if IL2CPP_TARGET_WINDOWS
        // This is a hack to work around the Mono Win32 BCL not updating the thread state when sleeping
        Il2CppThread* thread = il2cpp::vm::Thread::Current();
        il2cpp::vm::Thread::SetState(thread, il2cpp::vm::kThreadStateWaitSleepJoin);
        il2cpp::os::Thread::Sleep(millisecondsTimeout, true);
        il2cpp::vm::Thread::ClrState(thread, il2cpp::vm::kThreadStateWaitSleepJoin);
#else
        // This is a hack to allow Thread.Sleep(0) to be interuptable
        // The BCL will call UninterruptableSleep0() which we don't want to make interuptable
        // Calling os::ThreadSleep(0, true) will have the side effect of checking for APC's
        if (millisecondsTimeout == 0)
            il2cpp::os::Thread::Sleep(0, true);

        auto sleepFunctionPtr = (void (*)(int32_t, MethodInfo*))sleepInternalMethod->methodPointer;
        sleepFunctionPtr(millisecondsTimeout, NULL);
#endif
    }
} // namespace Threading
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
