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
namespace Bmi2
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Bmi2/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
#if IL2CPP_BMI2_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi2/X64::MultiplyNoFlags(System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_multiply_no_flags_30896(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_X64_IS_SUPPORTED
        // HAND EDITED: This C# method is nonsensense as the intrinsic needs a pointer for the third argument.
        // Upstream behavior is odd it is either _mulx_u64(b, b, &c) or simply 0.  May need to revisit this later.
        uint64_t arg3;
        _mulx_u64(
            INTRINSIC_CAST(TArg1, uint64_t, arg1),
            INTRINSIC_CAST(TArg2, uint64_t, arg2),
            reinterpret_cast<unsigned long long*>(&arg3)
        );
        return arg3;
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi2/X64::MultiplyNoFlags(System.UInt64,System.UInt64,System.UInt64*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x64_multiply_no_flags_C19A6(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_BMI2_X64_IS_SUPPORTED
        // HAND EDITED: Arg3 and the return need to be swapped
        uint64_t ret;
        *arg3 = _mulx_u64(
            INTRINSIC_CAST(TArg1, uint64_t, arg1),
            INTRINSIC_CAST(TArg2, uint64_t, arg2),
            reinterpret_cast<unsigned long long*>(&ret)
        );
        return INTRINSIC_CAST(
            uint64_t, TRet, ret
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi2/X64::ParallelBitDeposit(System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_parallel_bit_deposit(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint64_t, TRet, _pdep_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1),
                INTRINSIC_CAST(TArg2, uint64_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi2/X64::ParallelBitExtract(System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_parallel_bit_extract(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint64_t, TRet, _pext_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1),
                INTRINSIC_CAST(TArg2, uint64_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi2/X64::ZeroHighBits(System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_zero_high_bits(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI2_X64_IS_SUPPORTED
        // HAND EDITED: Use a static cast on the second argument.
        return INTRINSIC_CAST(
            uint64_t, TRet, _bzhi_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1),
                static_cast<uint32_t>(arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Bmi2
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
