#include "ObjectHeader.h"
#include "vm/Monitor.h"

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
    bool il2cpp_intrinsic_object_header_has_owner(RuntimeObject* obj)
    {
        return il2cpp::vm::Monitor::IsAcquired(obj);
    }

    bool il2cpp_intrinsic_object_header_is_entered(RuntimeObject* obj)
    {
        return il2cpp::vm::Monitor::IsOwnedByCurrentThread(obj);
    }
} // namespace Threading
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
