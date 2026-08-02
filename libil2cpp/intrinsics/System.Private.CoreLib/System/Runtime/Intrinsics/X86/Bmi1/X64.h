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
namespace Bmi1
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Bmi1/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi1/X64::AndNot(System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_and_not(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint64_t, TRet, _andn_u64(
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
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi1/X64::BitFieldExtract(System.UInt64,System.Byte,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x64_bit_field_extract_1D8CC(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        // HAND EDITED: The second and third arguments do not need casting.
        return INTRINSIC_CAST(
            uint64_t, TRet, _bextr_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1),
                arg2,
                arg3
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi1/X64::BitFieldExtract(System.UInt64,System.UInt16)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_bit_field_extract_75577(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        // HAND EDITED: The second argument does not need casting.
        return INTRINSIC_CAST(
            uint64_t, TRet, _bextr2_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1),
                arg2
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi1/X64::ExtractLowestSetBit(System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_extract_lowest_set_bit(TArg1 arg1)
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint64_t, TRet, _blsi_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi1/X64::GetMaskUpToLowestSetBit(System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_get_mask_up_to_lowest_set_bit(TArg1 arg1)
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint64_t, TRet, _blsmsk_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi1/X64::ResetLowestSetBit(System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_reset_lowest_set_bit(TArg1 arg1)
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint64_t, TRet, _blsr_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Bmi1/X64::TrailingZeroCount(System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_trailing_zero_count(TArg1 arg1)
    {
#if IL2CPP_BMI1_X64_IS_SUPPORTED
        // HAND EDITED: The summary tag listed _mm_tzcnt_64 as the intrinisc, but that is incorrect.
        return INTRINSIC_CAST(
            int64_t, TRet, _tzcnt_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Bmi1
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
