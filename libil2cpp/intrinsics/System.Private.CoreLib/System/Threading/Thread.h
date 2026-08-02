#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
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
    /* METHOD MAPPING
        Method: System.Threading.ApartmentState System.Threading.Thread::GetApartmentState()
        AssemblyName: System.Private.CoreLib
    */
    int32_t il2cpp_intrinsic_thread_get_apartment_state(RuntimeObject* thisPtr);

    /* METHOD MAPPING
        Method: System.Boolean System.Threading.Thread::SetApartmentState(System.Threading.ApartmentState,System.Boolean)
        AssemblyName: System.Private.CoreLib
    */
    bool il2cpp_intrinsic_thread_set_apartment_state(RuntimeObject* thisPtr, int32_t state, bool throwOnError);

    /* METHOD MAPPING
        Method: System.Void System.Threading.Thread::SpinWait_nop()
        AssemblyName: System.Private.CoreLib
    */
    IL2CPP_NO_INLINE void il2cpp_intrinsic_thread_spin_wait_nop();

    /* METHOD MAPPING
        Method: System.Void System.Threading.Thread::SleepInternal(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    void il2cpp_intrinsic_thread_sleep_internal(int32_t millisecondsTimeout);
} // namespace Threading
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
