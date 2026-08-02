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
    class LIBIL2CPP_CODEGEN_API Thread
    {
    public:
        static bool JoinInternal(Il2CppThread* thread, int32_t millisecondsTimeout);
        static bool YieldInternal();
        static Il2CppObject* GetCurrentThread();
        static int32_t GetState(Il2CppThread* thread);
        static uint64_t GetCurrentOSThreadId();
        static void ClrState(Il2CppThread* thread, int32_t clr);
        static void FreeInternal(Il2CppThread* thisPtr);
        static void InitInternal(Il2CppThread* thread);
        static void InterruptInternal(Il2CppThread* thread);
        static void SetName_icall(Il2CppThread* thread, Il2CppChar* name, int32_t nameLength);
        static void SetPriority(Il2CppThread* thread, int32_t priority);
        static void SetState(Il2CppThread* thread, int32_t set);
        static void StartInternal(Il2CppThread* runtimeThread, int32_t stackSize);
    };
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
