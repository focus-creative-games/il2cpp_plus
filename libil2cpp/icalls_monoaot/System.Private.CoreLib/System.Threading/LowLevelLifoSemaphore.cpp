#include "il2cpp-config.h"
#include "LowLevelLifoSemaphore.h"

#include "Baselib.h"
#include "Cpp/Semaphore.h"

#include "os/Semaphore.h"

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
    intptr_t LowLevelLifoSemaphore::InitInternal()
    {
        // Semaphore count is from System.Threading.PortableThreadPool.MaxPossibleThreadCount (short.MaxValue)
        os::Semaphore* s = new os::Semaphore(0, INT16_MAX);
        return reinterpret_cast<intptr_t>(s);
    }

    void LowLevelLifoSemaphore::DeleteInternal(intptr_t semaphore)
    {
        os::Semaphore* s = reinterpret_cast<os::Semaphore*>(semaphore);
        delete s;
    }

    int32_t LowLevelLifoSemaphore::TimedWaitInternal(intptr_t semaphore, int32_t timeoutMs)
    {
        os::Semaphore* s = reinterpret_cast<os::Semaphore*>(semaphore);
        return (s->Wait(timeoutMs, true) == kWaitStatusSuccess) ? 1 : 0;
    }

    void LowLevelLifoSemaphore::ReleaseInternal(intptr_t semaphore, int32_t count)
    {
        os::Semaphore* s = reinterpret_cast<os::Semaphore*>(semaphore);
        s->PostLifo(count, NULL);
    }
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
