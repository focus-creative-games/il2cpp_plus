#include "Kernel32.h"
#include "os/LastError.h"
#include "os/Time.h"
#include "os/Win32/WindowsHeaders.h"
#include "vm/Exception.h"
#include "vm/Thread.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace Interop
{
    static void StoreLastErrorAndCheckForAPC()
    {
        // Save the last error code for the current thread. We do this because the call to
        // CheckCurrentThreadForUserAPCAndHandle may wipe out the last error code, but our
        // callers want the error code from the previous OS call.
        uint32_t lastError = os::LastError::GetLastError();

        // Handle any queued APCs.
        vm::Thread::CheckCurrentThreadForUserAPCAndHandle();

        // Restore last error code for the current thread. Note that if CheckCurrentThreadForUserAPCAndHandle
        // executes an APC that throws an exception, we won't get here, and that's okay.
        os::LastError::SetLastError(lastError);
    }

    bool il2cpp_intrinsic_interop_kernel32_get_queued_completion_status(intptr_t completionPort, uint32_t* numberOfBytesTransferred, uintptr_t* completionKey, intptr_t* overlapped, int32_t milliseconds)
    {
#if IL2CPP_TARGET_WINDOWS
        const int32_t numEntries = 1;
        OVERLAPPED_ENTRY completionPortEntries[numEntries];
        int32_t numEntriesRemoved;

        bool result = il2cpp_intrinsic_interop_kernel32_get_queued_completion_status_ex(completionPort, completionPortEntries, numEntries, &numEntriesRemoved, milliseconds, false);

        if (result)
        {
            IL2CPP_ASSERT(numEntriesRemoved == numEntries);

            if (numberOfBytesTransferred != nullptr)
                *numberOfBytesTransferred = completionPortEntries[0].dwNumberOfBytesTransferred;

            if (completionKey != nullptr)
                *completionKey = completionPortEntries[0].lpCompletionKey;

            if (overlapped != nullptr)
                *overlapped = (intptr_t)completionPortEntries[0].lpOverlapped;
        }

        return result;
#else
        NOT_SUPPORTED_IL2CPP(il2cpp_intrinsic_interop_kernel32_get_queued_completion_status, "This method should only be called on Windows");
        return false;
#endif
    }

    bool il2cpp_intrinsic_interop_kernel32_get_queued_completion_status_ex(intptr_t completionPort, void* completionPortEntries, int32_t count, int32_t* numEntriesRemoved, int32_t milliseconds, bool alertable)
    {
#if IL2CPP_TARGET_WINDOWS
        bool result;

        uint32_t remainingWaitTimeMS = milliseconds;
        while (true)
        {
            uint32_t waitStartTime = (uint32_t)os::Time::GetTicksMillisecondsMonotonic();

            // Always set alertable to true. This is a workaround for the BCL not using alertable calls for IO completion ports.
            // We require alertable calls in order to shutdown the runtime correctly.
            result = ::GetQueuedCompletionStatusEx((HANDLE)completionPort, (LPOVERLAPPED_ENTRY)completionPortEntries, count, (PULONG)numEntriesRemoved, remainingWaitTimeMS, true);

            // Was this thread interrupted by an APC?
            uint32_t lastError = os::LastError::GetLastError();
            if (lastError == WAIT_IO_COMPLETION)
            {
                StoreLastErrorAndCheckForAPC();

                // If the caller passed in alertable=false, loop until we get a result that is not WAIT_IO_COMPLETION.
                if (!alertable)
                {
                    if (milliseconds != INFINITE)
                    {
                        uint32_t haveWaitedTimeMS = (uint32_t)os::Time::GetTicksMillisecondsMonotonic() - waitStartTime;
                        if (haveWaitedTimeMS >= remainingWaitTimeMS)
                            remainingWaitTimeMS = 0;
                        else
                            remainingWaitTimeMS -= haveWaitedTimeMS;
                    }
                    continue;
                }
            }

            break;
        }

        return result;
#else
        NOT_SUPPORTED_IL2CPP(il2cpp_intrinsic_interop_kernel32_get_queued_completion_status_ex, "This method should only be called on Windows");
        return false;
#endif
    }

    uint32_t il2cpp_intrinsic_interop_kernel32_wait_for_multiple_objects_ex(uint32_t count, intptr_t handles, bool waitAll, uint32_t milliseconds, bool alertable)
    {
#if IL2CPP_TARGET_WINDOWS
        uint32_t result;

        uint32_t remainingWaitTimeMS = milliseconds;
        while (true)
        {
            uint32_t waitStartTime = (uint32_t)os::Time::GetTicksMillisecondsMonotonic();

            // Always set alertable to true. This is a workaround for the BCL not using alertable calls for .NET ThreadPool workers.
            // We require alertable calls in order to shutdown the runtime correctly.
            result = ::WaitForMultipleObjectsEx(count, (HANDLE*)handles, waitAll, remainingWaitTimeMS, true);

            // Was this thread interrupted by an APC?
            if (result == WAIT_IO_COMPLETION)
            {
                StoreLastErrorAndCheckForAPC();

                // If the caller passed in alertable=false, loop until we get a result that is not WAIT_IO_COMPLETION.
                if (!alertable)
                {
                    if (milliseconds != INFINITE)
                    {
                        uint32_t haveWaitedTimeMS = (uint32_t)os::Time::GetTicksMillisecondsMonotonic() - waitStartTime;
                        if (haveWaitedTimeMS >= remainingWaitTimeMS)
                            remainingWaitTimeMS = 0;
                        else
                            remainingWaitTimeMS -= haveWaitedTimeMS;
                    }
                    continue;
                }
            }

            break;
        }

        return result;
#else
        NOT_SUPPORTED_IL2CPP(il2cpp_intrinsic_interop_kernel32_wait_for_multiple_objects_ex, "This method should only be called on Windows");
        return 0;
#endif
    }
} // namespace Interop
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
