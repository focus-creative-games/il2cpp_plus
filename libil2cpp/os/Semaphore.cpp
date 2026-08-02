#include "os/c-api/il2cpp-config-platforms.h"
#include "os/Semaphore.h"

#if IL2CPP_SUPPORT_THREADS

#include "os/Atomic.h"
#if IL2CPP_TARGET_WINDOWS || IL2CPP_TARGET_POSIX
#include "os/Generic/SemaphoreImpl.h"
#else
#include "os/SemaphoreImpl.h"
#endif

#endif

namespace il2cpp
{
namespace os
{
#if !IL2CPP_SUPPORT_THREADS

    class SemaphoreImpl
    {
    private:
        int32_t m_Count;
        int32_t m_MaximumValue;

    public:

        SemaphoreImpl(int32_t initialValue, int32_t maximumValue) :
            m_Count(initialValue) , m_MaximumValue(maximumValue)
        {
        }

        bool Post(int32_t releaseCount, int32_t* previousCount, bool lifo)
        {
            if (previousCount)
                *previousCount = m_Count;

            // Make sure we stay within range. Account for 32bit overflow.
            if (static_cast<uint64_t>(m_Count) + releaseCount > m_MaximumValue)
                return false;

            m_Count += releaseCount;
            return true;
        }

        WaitStatus Wait(bool interruptible)
        {
            return Wait(-1, interruptible);
        }

        WaitStatus Wait(uint32_t ms, bool interruptible)
        {
            if (m_Count > 0)
            {
                m_Count--;
                return kWaitStatusSuccess;
            }

            // If we have an infinite timeout we should assume that the caller won't check for kWaitStatusTimeout
            // since this should only return when the semaphore is signaled, but that will never happen
            // So throwing WaitAbandoned is out best option
            if (ms == UINT32_MAX)
                return kWaitStatusAbandoned;

            return kWaitStatusTimeout;
        }

        void* GetOSHandle()
        {
            return NULL;
        }
    };
#endif

    Semaphore::Semaphore(int32_t initialValue, int32_t maximumValue)
        : m_Semaphore(new SemaphoreImpl(initialValue, maximumValue))
    {
    }

    Semaphore::~Semaphore()
    {
        delete m_Semaphore;
    }

    bool Semaphore::Post(int32_t releaseCount, int32_t* previousCount)
    {
        return m_Semaphore->Post(releaseCount, previousCount, false);
    }

    bool Semaphore::PostLifo(int32_t releaseCount, int32_t* previousCount)
    {
        return m_Semaphore->Post(releaseCount, previousCount, true);
    }

    WaitStatus Semaphore::Wait(bool interruptible)
    {
        return m_Semaphore->Wait(interruptible);
    }

    WaitStatus Semaphore::Wait(uint32_t ms, bool interruptible)
    {
        return m_Semaphore->Wait(ms, interruptible);
    }

    void* Semaphore::GetOSHandle()
    {
        return m_Semaphore->GetOSHandle();
    }
}
}
