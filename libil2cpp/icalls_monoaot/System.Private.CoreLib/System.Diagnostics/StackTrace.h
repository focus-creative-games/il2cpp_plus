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
namespace Diagnostics
{
    class LIBIL2CPP_CODEGEN_API StackTrace
    {
    public:
        static void GetTrace(Il2CppObjectHandleOnStack ex, Il2CppObjectHandleOnStack res, int32_t skipFrames, bool needFileInfo);
    };
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
