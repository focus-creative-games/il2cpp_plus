#include "il2cpp-config.h"

#if IL2CPP_THREADS_PTHREAD && !IL2CPP_TARGET_DARWIN

#include <pthread.h>

#include "os/Thread.h"

namespace il2cpp
{
namespace os
{
    bool Thread::GetCurrentThreadStackBounds(void** low, void** high)
    {
#if IL2CPP_TARGET_LINUX

        pthread_attr_t attr;
        size_t stacksize = 0;
        pthread_t self = pthread_self();
        int ret = pthread_getattr_np(self, &attr);
        if (ret != 0)
            return false;

        ret = pthread_attr_getstack(&attr, low, &stacksize);
        *high = (void*)((uintptr_t)*low - stacksize);

        pthread_attr_destroy(&attr);

        return ret != 0;;
#else
        return false;
#endif
    }
}
}

#endif
