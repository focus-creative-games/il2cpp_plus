#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace Interop
{
    /* METHOD MAPPING
        Method: System.Boolean Interop/Sys::LowLevelMonitor_TimedWait(System.IntPtr,System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    bool il2cpp_intrinsic_sys_low_level_monitor_timed_wait(intptr_t monitor, int32_t timeoutMilliseconds);

    /* METHOD MAPPING
        Method: System.IntPtr Interop/Sys::LowLevelMonitor_Create()
        AssemblyName: System.Private.CoreLib
    */
    intptr_t il2cpp_intrinsic_sys_low_level_monitor_create();

    /* METHOD MAPPING
        Method: System.Void Interop/Sys::LowLevelMonitor_Acquire(System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    void il2cpp_intrinsic_sys_low_level_monitor_acquire(intptr_t monitor);

    /* METHOD MAPPING
        Method: System.Void Interop/Sys::LowLevelMonitor_Destroy(System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    void il2cpp_intrinsic_sys_low_level_monitor_destroy(intptr_t monitor);

    /* METHOD MAPPING
        Method: System.Void Interop/Sys::LowLevelMonitor_Release(System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    void il2cpp_intrinsic_sys_low_level_monitor_release(intptr_t monitor);

    /* METHOD MAPPING
        Method: System.Void Interop/Sys::LowLevelMonitor_Signal_Release(System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    void il2cpp_intrinsic_sys_low_level_monitor_signal_release(intptr_t monitor);

    /* METHOD MAPPING
        Method: System.Void Interop/Sys::LowLevelMonitor_Wait(System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    void il2cpp_intrinsic_sys_low_level_monitor_wait(intptr_t monitor);
} // namespace Interop
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
