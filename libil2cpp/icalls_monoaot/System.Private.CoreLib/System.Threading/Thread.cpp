#include "il2cpp-config.h"
#include "Thread.h"

#include "gc/GarbageCollector.h"
#include "il2cpp-class-internals.h"
#include "os/Atomic.h"
#include "os/Mutex.h"
#include "os/Semaphore.h"
#include "os/Thread.h"
#include "utils/Memory.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Domain.h"
#include "vm/Exception.h"
#include "vm/Object.h"
#include "vm/Runtime.h"
#include "vm/StackTrace.h"
#include "vm/String.h"
#include "vm/Thread.h"
#include <memory>

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
    struct StartData
    {
        Il2CppThread* m_Thread;
        Il2CppDomain* m_Domain;
        const MethodInfo* m_StartCallback;
        il2cpp::os::Semaphore* m_Semaphore;
    };

    static void ThreadStart(void* arg)
    {
        StartData* startData = (StartData*)arg;

        startData->m_Semaphore->Wait();

        {
            gc::GarbageCollector::RegisterThread();

            il2cpp::vm::StackTrace::InitializeStackTracesForCurrentThread();

            bool attachSuccessful = false;
            try
            {
                il2cpp::vm::Thread::InitializeManagedThread(startData->m_Thread, startData->m_Domain);
                il2cpp::vm::Thread::SetState(startData->m_Thread, vm::kThreadStateRunning);

                attachSuccessful = true;

                Il2CppException* exc = NULL;
                il2cpp::vm::Runtime::Invoke(startData->m_StartCallback, startData->m_Thread, NULL, &exc);

                if (exc)
                    vm::Runtime::UnhandledException(exc);
            }
            catch (Il2CppNativeThreadAbortException&)
            {
                // Nothing to do. We've successfully aborted the thread.
                il2cpp::vm::Thread::SetState(startData->m_Thread, vm::kThreadStateAborted);
            }

            il2cpp::vm::Thread::ClrState(startData->m_Thread, vm::kThreadStateRunning);
            il2cpp::vm::Thread::SetState(startData->m_Thread, vm::kThreadStateStopped);
            if (attachSuccessful)
                il2cpp::vm::Thread::UninitializeManagedThread(startData->m_Thread);

            il2cpp::vm::StackTrace::CleanupStackTracesForCurrentThread();
        }

        delete startData->m_Semaphore;
        gc::GarbageCollector::FreeFixed(startData);
    }

    bool Thread::JoinInternal(Il2CppThread* thread, int32_t millisecondsTimeout)
    {
        // Throw ThreadStateException if thread has not been started yet.
        if (il2cpp::vm::Thread::GetState(thread) & vm::kThreadStateUnstarted)
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetThreadStateException("Thread has not been started."));

        // Mark current thread as blocked.
        Il2CppThread* currentThread = il2cpp::vm::Thread::Current();
        SetState(currentThread, vm::kThreadStateWaitSleepJoin);

        // Join with other thread.
        il2cpp::os::Thread* osThread = (il2cpp::os::Thread*)thread->handle;
        IL2CPP_ASSERT(osThread != NULL);
        il2cpp::os::WaitStatus status = osThread->Join(millisecondsTimeout);

        // Unblock current thread.
        ClrState(currentThread, vm::kThreadStateWaitSleepJoin);

        if (status == kWaitStatusSuccess)
            return true;

        return false;
    }

    bool Thread::YieldInternal()
    {
        return vm::Thread::YieldInternal();
    }

    Il2CppObject* Thread::GetCurrentThread()
    {
        return (Il2CppObject*)vm::Thread::Current();
    }

    int32_t Thread::GetState(Il2CppThread* thread)
    {
        // There is a chance that the managed thread object can be used from code (like a
        // finalizer) after it has been destroyed. In that case, the objects that
        // the runtime uses to track this thread may have been freed. Try to check for
        // that case here and return early.
        if (thread->longlived == NULL)
            return vm::kThreadStateStopped;

        return vm::Thread::GetState(thread);
    }

    uint64_t Thread::GetCurrentOSThreadId()
    {
        return (uint64_t)((il2cpp::os::Thread*)vm::Thread::Current()->native_handle)->CurrentThreadId();
    }

    void Thread::ClrState(Il2CppThread* thread, int32_t clr)
    {
        il2cpp::vm::Thread::ClrState(thread, (il2cpp::vm::ThreadState)clr);
    }

    void Thread::FreeInternal(Il2CppThread* thisPtr)
    {
        delete thisPtr->longlived->synch_cs;
        thisPtr->longlived->synch_cs = NULL;

        IL2CPP_FREE(thisPtr->longlived);
        thisPtr->longlived = NULL;

        IL2CPP_FREE(thisPtr->name.chars);
        thisPtr->name.chars = NULL;

        delete reinterpret_cast<il2cpp::os::Thread*>(thisPtr->handle);
        thisPtr->handle = NULL;
    }

    void Thread::InitInternal(Il2CppThread* thread)
    {
        // The os::Thread object is deallocated in the InternalThread::Thread_free_internal icall, which
        // is called from the managed thread finalizer.
        vm::Thread::SetupInternalManagedThread(thread, new os::Thread());
        thread->state = vm::kThreadStateUnstarted;
    }

    void Thread::InterruptInternal(Il2CppThread* thread)
    {
        il2cpp::vm::Thread::RequestInterrupt(thread);
    }

    void Thread::SetName_icall(Il2CppThread* thread, Il2CppChar* name, int32_t nameLength)
    {
        il2cpp::os::FastAutoLock lock(thread->longlived->synch_cs);

        // Throw if already set.
        if (thread->name.length != 0)
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetInvalidOperationException("Thread name can only be set once."));

        // Store name.
        thread->name.length = nameLength;
        thread->name.chars = il2cpp::utils::StringUtils::StringDuplicate(name, thread->name.length);

        // Hand over to OS layer, if thread has been started already.
        if (thread->handle)
        {
            std::string utf8Name = il2cpp::utils::StringUtils::Utf16ToUtf8(thread->name.chars);
            thread->handle->SetName(utf8Name.c_str());
        }
    }

    void Thread::SetPriority(Il2CppThread* thread, int32_t priority)
    {
        vm::Thread::SetPriority(thread, priority);
    }

    void Thread::SetState(Il2CppThread* thread, int32_t set)
    {
        il2cpp::vm::Thread::SetState(thread, (il2cpp::vm::ThreadState)set);
    }

    void Thread::StartInternal(Il2CppThread* runtimeThread, int32_t stackSize)
    {
        IL2CPP_ASSERT(runtimeThread->longlived->synch_cs != NULL);
        il2cpp::os::FastAutoLock lock(runtimeThread->longlived->synch_cs);

        if (il2cpp::vm::Thread::GetState(runtimeThread) & vm::kThreadStateAborted)
            return;

        if (il2cpp::vm::Thread::GetState(runtimeThread) & vm::kThreadStateRunning)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetThreadStateException("Thread has already been started."));
            return;
        }

        // use fixed GC memory since we are storing managed object pointers
        StartData* startData = (StartData*)gc::GarbageCollector::AllocateFixed(sizeof(StartData), NULL);

        startData->m_Thread = runtimeThread;
        gc::GarbageCollector::SetWriteBarrier((void**)&startData->m_Thread);
        startData->m_Domain = vm::Domain::GetCurrent();
        startData->m_StartCallback = il2cpp::vm::Class::GetMethodFromName(runtimeThread->obj.klass, "StartCallback", 0);
        IL2CPP_ASSERT(startData->m_StartCallback);
        startData->m_Semaphore = new il2cpp::os::Semaphore(0);

        il2cpp::os::Thread* thread = runtimeThread->handle;
        thread->SetStackSize(stackSize);
        thread->SetExplicitApartment(static_cast<il2cpp::os::ApartmentState>(runtimeThread->apartment_state));
        il2cpp::os::ErrorCode status = thread->Run(&ThreadStart, startData);
        if (status != il2cpp::os::kErrorCodeSuccess)
        {
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetThreadStateException(utils::StringUtils::Printf("Failed to start thread. Error code: %d", status).c_str()));
            return;
        }

        runtimeThread->state &= ~vm::kThreadStateUnstarted;
        runtimeThread->tid = thread->Id();
        if (!runtimeThread->managed_id)
            runtimeThread->managed_id = il2cpp::vm::Thread::GetNewManagedId();

        startData->m_Semaphore->Post(1, NULL);
    }
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
