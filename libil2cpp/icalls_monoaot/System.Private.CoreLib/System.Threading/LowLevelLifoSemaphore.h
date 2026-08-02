#pragma once

#include "il2cpp-object-internals.h"
#include "il2cpp-class-internals.h"
#include "mono-structs.h"

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
    class LIBIL2CPP_CODEGEN_API LowLevelLifoSemaphore
    {
    public:
        static intptr_t InitInternal();
        static void DeleteInternal(intptr_t semaphore);
        static int32_t TimedWaitInternal(intptr_t semaphore, int32_t timeoutMs);
        static void ReleaseInternal(intptr_t semaphore, int32_t count);
    };
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
