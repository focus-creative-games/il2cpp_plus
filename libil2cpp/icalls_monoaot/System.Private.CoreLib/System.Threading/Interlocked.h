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
    class LIBIL2CPP_CODEGEN_API Interlocked
    {
    public:
        static int32_t Add(int32_t* location1, int32_t value);
        static int32_t CompareExchange(int32_t* location1, int32_t value, int32_t comparand);
        static int32_t Decrement(int32_t* location);
        static int32_t Exchange(int32_t* location1, int32_t value);
        static int32_t Increment(int32_t* location);
        static int64_t Add(int64_t* location1, int64_t value);
        static int64_t CompareExchange(int64_t* location1, int64_t value, int64_t comparand);
        static int64_t Decrement(int64_t* location);
        static int64_t Exchange(int64_t* location1, int64_t value);
        static int64_t Increment(int64_t* location);
        static int64_t Read(int64_t* location);
        static void CompareExchange(Il2CppObject** location1, Il2CppObject** value, Il2CppObject** comparand, Il2CppObject** result);
        static void Exchange(Il2CppObject** location1, Il2CppObject** value, Il2CppObject** result);
        static void MemoryBarrierProcessWide();
    };
} // namespace Threading
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
