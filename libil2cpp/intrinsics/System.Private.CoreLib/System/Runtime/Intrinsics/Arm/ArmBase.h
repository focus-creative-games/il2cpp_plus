#pragma once
#include "il2cpp-config.h"
#include "il2cpp-intrinsics-config.h"

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
namespace Intrinsics
{
namespace Arm
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.Arm.ArmBase::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_arm_base_get_is_supported()
    {
#if IL2CPP_ARMBASE_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Arm.ArmBase::LeadingZeroCount(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_arm_base_leading_zero_count(int32_t value)
    {
#if IL2CPP_ARMBASE_IS_SUPPORTED
#  if defined(_MSC_VER)
        return _CountLeadingZeros(value);
#  else
        return __builtin_clz(value);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Arm.ArmBase::LeadingZeroCount(System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_arm_base_leading_zero_count(uint32_t value)
    {
#if IL2CPP_ARMBASE_IS_SUPPORTED
#  if defined(_MSC_VER)
        return _CountLeadingZeros(value);
#  else
        return __builtin_clz(value);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Arm.ArmBase::ReverseElementBits(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_arm_base_reverse_element_bits(int32_t value)
    {
#if IL2CPP_ARMBASE_IS_SUPPORTED
#  if defined(_MSC_VER)
        return __rbit(value);
#  else
        return __builtin_bitreverse32(value);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.Arm.ArmBase::ReverseElementBits(System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline uint32_t il2cpp_intrinsic_arm_base_reverse_element_bits(uint32_t value)
    {
#if IL2CPP_ARMBASE_IS_SUPPORTED
#  if defined(_MSC_VER)
        return __rbit(value);
#  else
        return __builtin_bitreverse32(value);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.Intrinsics.Arm.ArmBase::Yield()
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_arm_base_yield()
    {
#if IL2CPP_ARMBASE_IS_SUPPORTED
#  if defined(_MSC_VER)
        // Use ARM YIELD instruction via MSVC intrinsic
        __yield();
#  else
        // Use ARM YIELD instruction via inline assembly
        __asm__ volatile("yield" ::: "memory");
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
#endif
    }
} // namespace Arm
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
