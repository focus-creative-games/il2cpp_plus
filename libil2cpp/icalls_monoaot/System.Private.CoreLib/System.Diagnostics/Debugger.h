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
    class LIBIL2CPP_CODEGEN_API Debugger
    {
    public:
        static bool IsAttached_internal();
        static bool IsLogging();
        static void Log_icall(int32_t level, Il2CppString** category, Il2CppString** message);
    };
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
