#pragma once
#if IL2CPP_THREADS_WIN32 && !RUNTIME_TINY

#include <stdint.h>
#include "utils/NonCopyable.h"

#include "WindowsHeaders.h"

class FastMutexImpl;

namespace il2cpp
{
namespace os
{
    class ConditionVariableImpl : public il2cpp::utils::NonCopyable
    {
    public:
        ConditionVariableImpl();
        ~ConditionVariableImpl();

        int Wait(FastMutexImpl* lock);
        int TimedWait(FastMutexImpl* lock, uint32_t timeout_ms);
        void Broadcast();
        void Signal();

    private:
        CONDITION_VARIABLE m_ConditionVariable;
    };
}
}

#endif
