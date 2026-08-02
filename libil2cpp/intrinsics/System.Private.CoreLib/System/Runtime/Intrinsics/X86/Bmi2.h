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
namespace X86
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Bmi2::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_bmi2_get_is_supported()
    {
#if IL2CPP_BMI2_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi2::MultiplyNoFlags(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_bmi2_multiply_no_flags_022FE(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_IS_SUPPORTED
        // HAND EDITED: This C# method is nonsensense as the intrinsic needs a pointer for the third argument.
        // In managed the return value is the high part of the multiplication.
#  if (defined(__clang__) && (__clang_major__ >= 17) ) || defined(_MSC_VER) || !(defined(__x86_64__) || defined(_M_X64))
        unsigned int arg3;
        _mulx_u32 (arg1, arg2, &arg3);
        return arg3;
#  else // Clang 16 does not have _mulx_u32 for x86
        unsigned long long __res = (unsigned long long) arg1 * (unsigned long long) arg2;
        return (unsigned int) (__res >> 32);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi2::MultiplyNoFlags(System.UInt32,System.UInt32,System.UInt32*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_bmi2_multiply_no_flags_92F55(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_BMI2_IS_SUPPORTED
#  if (defined(__clang__) && (__clang_major__ >= 17) ) || defined(_MSC_VER) || !(defined(__x86_64__) || defined(_M_X64))
        // HAND EDITED: Arg3 and the return need to be swapped
        unsigned int ret;
        *arg3 = _mulx_u32(
            INTRINSIC_CAST(TArg1, unsigned int, arg1),
            INTRINSIC_CAST(TArg2, unsigned int, arg2),
            &ret
        );
        return INTRINSIC_CAST(
            unsigned int, TRet, ret
        );
#  else // Clang 16 does not have _mulx_u32 for x86
        unsigned long long __res = (unsigned long long) arg1 * (unsigned long long) arg2;
        *arg3 = (unsigned int) __res;
        return (unsigned int) (__res >> 32);
#  endif
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi2::ParallelBitDeposit(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_bmi2_parallel_bit_deposit(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _pdep_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1),
                INTRINSIC_CAST(TArg2, unsigned int, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi2::ParallelBitExtract(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_bmi2_parallel_bit_extract(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _pext_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1),
                INTRINSIC_CAST(TArg2, unsigned int, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi2::ZeroHighBits(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_bmi2_zero_high_bits(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _bzhi_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1),
                INTRINSIC_CAST(TArg2, unsigned int, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
