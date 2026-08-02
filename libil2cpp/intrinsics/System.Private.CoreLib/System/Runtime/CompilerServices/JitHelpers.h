#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "JitHelpersVariations.h"

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
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.JitHelpers::EnumEquals(T,T)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline bool il2cpp_intrinsic_jit_helpers_enum_equals(T x, T y)
    {
        return x == y;
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.CompilerServices.JitHelpers::EnumCompareTo(T,T)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline int32_t il2cpp_intrinsic_jit_helpers_enum_compare_to(T x, T y)
    {
        return (int32_t)(x - y);
    }
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
