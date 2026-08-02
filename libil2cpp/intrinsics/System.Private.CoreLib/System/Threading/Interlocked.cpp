#include "Interlocked.h"
#include "vm/Thread.h"
#include "os/Atomic.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Threading
{
    void il2cpp_intrinsic_interlocked_memory_barrier()
    {
        il2cpp::vm::Thread::FullMemoryBarrier();
    }

    void il2cpp_intrinsic_interlocked_read_memory_barrier()
    {
        il2cpp::os::Atomic::ReadMemoryBarrier();
    }
} // namespace Threading
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
