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
    class LIBIL2CPP_CODEGEN_API Monitor
    {
    public:
        static bool Monitor_wait(Il2CppObject* obj, int32_t ms, bool allowInterruption);
        static int64_t get_LockContentionCount();
        static void Enter(Il2CppObject* obj);
        static void InternalExit(Il2CppObject* obj);
        static void Monitor_pulse(Il2CppObject* obj);
        static void Monitor_pulse_all(Il2CppObject* obj);
        static void try_enter_with_atomic_var(Il2CppObject* obj, int32_t millisecondsTimeout, bool allowInterruption, bool* lockTaken);
    };
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
