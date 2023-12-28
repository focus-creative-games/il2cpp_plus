#pragma once
#include "utils/NonCopyable.h"

namespace il2cpp
{
namespace os
{
    class FastReaderReaderWriterLockImpl;

    // Use this class if the work done in the shared lock is "fast" - on the order of taking a lock
    class FastReaderReaderWriterLock
    {
    public:
        FastReaderReaderWriterLock();
        ~FastReaderReaderWriterLock();

        void LockExclusive();
        void LockShared();
        void ReleaseExclusive();
        void ReleaseShared();

        FastReaderReaderWriterLockImpl* GetImpl();

    private:
        FastReaderReaderWriterLockImpl* m_Impl;
    };

    struct FastReaderReaderWriterAutoSharedLock : public il2cpp::utils::NonCopyable
    {
        FastReaderReaderWriterAutoSharedLock(FastReaderReaderWriterLock* lock)
            : m_Lock(lock)
        {
#if !IL2CPP_SLIM_CLASS
            m_Lock->LockShared();
#endif
        }

#if !IL2CPP_SLIM_CLASS
        ~FastReaderReaderWriterAutoSharedLock()
        {
            m_Lock->ReleaseShared();
        }
#endif

    private:
        FastReaderReaderWriterLock* m_Lock;
    };

    struct FastReaderReaderWriterAutoExclusiveLock : public il2cpp::utils::NonCopyable
    {
        FastReaderReaderWriterAutoExclusiveLock(FastReaderReaderWriterLock* lock)
            : m_Lock(lock)
        {
#if !IL2CPP_SLIM_CLASS
            m_Lock->LockExclusive();
#endif
        }

#if !IL2CPP_SLIM_CLASS
        ~FastReaderReaderWriterAutoExclusiveLock()
        {
            m_Lock->ReleaseExclusive();
        }
#endif
    private:
        FastReaderReaderWriterLock* m_Lock;
    };
}
}
