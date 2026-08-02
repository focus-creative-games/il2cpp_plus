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
    class LIBIL2CPP_CODEGEN_API RuntimeMethodHandle
    {
    public:
        static intptr_t GetFunctionPointer(intptr_t m);
        static void ReboxFromNullable(Il2CppObject* src, Il2CppObjectHandleOnStack res);
        static void ReboxToNullable(Il2CppObject* src, Il2CppQCallTypeHandle destNullableType, Il2CppObjectHandleOnStack res);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
