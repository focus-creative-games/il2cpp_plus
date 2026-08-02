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
    class LIBIL2CPP_CODEGEN_API Enum
    {
    public:
        static uint8_t InternalGetCorElementType(Il2CppQCallTypeHandle enumType);
        static void GetEnumValuesAndNames(Il2CppQCallTypeHandle enumType, Il2CppArray** values, Il2CppArray** names);
        static void InternalBoxEnum(Il2CppQCallTypeHandle enumType, Il2CppObjectHandleOnStack res, int64_t value);
        static void InternalGetUnderlyingType(Il2CppQCallTypeHandle enumType, Il2CppObjectHandleOnStack res);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
