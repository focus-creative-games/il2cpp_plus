#include "il2cpp-config.h"
#include "RuntimeGPtrArrayHandle.h"

#include "mono-structs.h"
#include "utils/Memory.h"

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
namespace Mono
{
    void RuntimeGPtrArrayHandle::GPtrArrayFree(MonoGPtrArray* value)
    {
        IL2CPP_ASSERT(value != NULL);
        free_gptr_array((MonoGPtrArray*)value);
    }
} // namespace Mono
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
