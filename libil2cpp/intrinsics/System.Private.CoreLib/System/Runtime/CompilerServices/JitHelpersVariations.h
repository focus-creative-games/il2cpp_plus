#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Runtime
{
namespace CompilerServices
{
    // Full generic sharing variation of JitHelpers.EnumEquals
    inline bool il2cpp_intrinsic_jit_helpers_enum_equals(void* x, void* y, size_t elementSize)
    {
        return memcmp(x, y, elementSize) == 0;
    }

    // Full generic sharing variation of JitHelpers.EnumCompareTo
    inline int32_t il2cpp_intrinsic_jit_helpers_enum_compare_to(void* x, void* y, size_t elementSize)
    {
        return memcmp(x, y, elementSize);
    }
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
