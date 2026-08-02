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
        Method: System.Boolean Interop/Kernel32::GetQueuedCompletionStatus(System.IntPtr,System.UInt32&,System.UIntPtr&,System.IntPtr&,System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    bool il2cpp_intrinsic_interop_kernel32_get_queued_completion_status(intptr_t completionPort, uint32_t* numberOfBytesTransferred, uintptr_t* completionKey, intptr_t* overlapped, int32_t milliseconds);

    /* METHOD MAPPING
        Method: System.Boolean Interop/Kernel32::GetQueuedCompletionStatusEx(System.IntPtr,Interop/Kernel32/OVERLAPPED_ENTRY*,System.Int32,System.Int32&,System.Int32,System.Boolean)
        AssemblyName: System.Private.CoreLib
    */
    bool il2cpp_intrinsic_interop_kernel32_get_queued_completion_status_ex(intptr_t completionPort, void* completionPortEntries, int32_t count, int32_t* numEntriesRemoved, int32_t milliseconds, bool alertable);

    /* METHOD MAPPING
        Method: System.UInt32 Interop/Kernel32::WaitForMultipleObjectsEx(System.UInt32,System.IntPtr,Interop/BOOL,System.UInt32,Interop/BOOL)
        AssemblyName: System.Private.CoreLib
    */
    uint32_t il2cpp_intrinsic_interop_kernel32_wait_for_multiple_objects_ex(uint32_t count, intptr_t handles, bool waitAll, uint32_t milliseconds, bool alertable);
} // namespace Interop
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
