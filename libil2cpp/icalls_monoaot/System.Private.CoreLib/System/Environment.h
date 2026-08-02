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
    class LIBIL2CPP_CODEGEN_API Environment
    {
    public:
        static int32_t GetProcessorCount();
        static int32_t get_ExitCode();
        static int32_t get_TickCount();
        static int64_t get_TickCount64();
        static Il2CppArray* GetCommandLineArgs();
        static void Exit(int32_t exitCode);
        static void FailFast(Il2CppString* message, Il2CppException* exception, Il2CppString* errorSource);
        static void set_ExitCode(int32_t value);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
