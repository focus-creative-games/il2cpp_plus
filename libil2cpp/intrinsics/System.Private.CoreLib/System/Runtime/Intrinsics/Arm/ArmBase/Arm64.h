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
namespace ArmBase
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.Arm.ArmBase/Arm64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_arm64_get_is_supported()
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::LeadingSignCount(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_arm64_leading_sign_count(int32_t value)
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
    #if defined(_MSC_VER)
        return _CountLeadingSigns(value);
    #else
        int32_t result;
        __asm__ ("cls %w0, %w1" : "=r"(result) : "r"(value));
        return result;
    #endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::LeadingSignCount(System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_arm64_leading_sign_count(int64_t value)
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
#  if defined(_MSC_VER)
        return _CountLeadingSigns64(value);
#  else
        int32_t result;
        __asm__ ("cls %x0, %x1" : "=r"(result) : "r"(value));
        return result;
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::LeadingZeroCount(System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_arm64_leading_zero_count(int64_t value)
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
#  if defined(_MSC_VER)
        return _CountLeadingZeros64(value);
#  else
        int32_t result;
        __asm__ ("clz %x0, %x1" : "=r"(result) : "r"(value));
        return result;
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::LeadingZeroCount(System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_arm64_leading_zero_count(uint64_t value)
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
#  if defined(_MSC_VER)
        return _CountLeadingZeros64(value);
#  else
        int32_t result;
        __asm__ ("clz %x0, %x1" : "=r"(result) : "r"(value));
        return result;
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::MultiplyHigh(System.Int64,System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline int64_t il2cpp_intrinsic_arm64_multiply_high(int64_t left, int64_t right)
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
#  if defined(_MSC_VER)
        return __mulh(left, right);
#  else
        int64_t high;
        __asm__ ("smulh %0, %1, %2" : "=r"(high) : "r"(left), "r"(right));
        return high;
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::ReverseElementBits(System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline int64_t il2cpp_intrinsic_arm64_reverse_element_bits(int64_t value)
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
#  if defined(_MSC_VER)
        // Use the ARM RBIT intrinsic on each 32-bit half
        uint32_t low = (uint32_t)value;
        uint32_t high = (uint32_t)(value >> 32);

        // Reverse bits in each 32-bit chunk and swap their positions
        return ((int64_t)__rbit(low) << 32) | __rbit(high);
#  else
        return __builtin_bitreverse64(value);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::MultiplyHigh(System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline uint64_t il2cpp_intrinsic_arm64_multiply_high(uint64_t left, uint64_t right)
    {
#if IL2CPP_ARMBASE_IS_SUPPORTED
    #if defined(_MSC_VER)
        return __umulh(left, right);
    #else
        uint64_t high;
        __asm__ ("umulh %0, %1, %2" : "=r"(high) : "r"(left), "r"(right));
        return high;
    #endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.Arm.ArmBase/Arm64::ReverseElementBits(System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline uint64_t il2cpp_intrinsic_arm64_reverse_element_bits(uint64_t value)
    {
#if IL2CPP_ARMBASE_ARM64_IS_SUPPORTED
#  if defined(_MSC_VER)
        // Use the ARM RBIT intrinsic on each 32-bit half
        uint32_t low = (uint32_t)value;
        uint32_t high = (uint32_t)(value >> 32);

        // Reverse bits in each 32-bit chunk and swap their positions
        return ((int64_t)__rbit(low) << 32) | __rbit(high);
#  else
        return __builtin_bitreverse64(value);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace ArmBase
} // namespace Arm
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
