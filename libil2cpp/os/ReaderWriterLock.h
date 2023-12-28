#pragma once
#include "utils/NonCopyable.h"

namespace il2cpp
{
namespace os
{
    class ReaderWriterLockImpl;

    class ReaderWriterLock
    {
    public:
        ReaderWriterLock();
        ~ReaderWriterLock();

        void LockExclusive();
        void LockShared();
        void ReleaseExclusive();
        void ReleaseShared();

        ReaderWriterLockImpl* GetImpl();

    private:
        ReaderWriterLockImpl* m_Impl;
    };

    struct ReaderWriterAutoSharedLock : public il2cpp::utils::NonCopyable
    {
        ReaderWriterAutoSharedLock(ReaderWriterLock* lock)
            : m_Lock(lock)
        {
#if !IL2CPP_SLIM_CLASS
            m_Lock->LockShared();
#endif
        }
#if !IL2CPP_SLIM_CLASS
        ~ReaderWriterAutoSharedLock()
        {
            m_Lock->ReleaseShared();
        }
#endif
    private:
        ReaderWriterLock* m_Lock;
    };

    struct ReaderWriterAutoExclusiveLock : public il2cpp::utils::NonCopyable
    {
        ReaderWriterAutoExclusiveLock(ReaderWriterLock* lock)
            : m_Lock(lock)
        {
#if !IL2CPP_SLIM_CLASS
            m_Lock->LockExclusive();
#endif
        }

#if !IL2CPP_SLIM_CLASS
        ~ReaderWriterAutoExclusiveLock()
        {
            m_Lock->ReleaseExclusive();
        }
#endif
    private:
        ReaderWriterLock* m_Lock;
    };
}
}
