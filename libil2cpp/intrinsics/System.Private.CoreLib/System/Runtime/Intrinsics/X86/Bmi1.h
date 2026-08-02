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
        Method: System.Boolean System.Runtime.Intrinsics.X86.Bmi1::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_bmi1_get_is_supported()
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi1::AndNot(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_bmi1_and_not(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _andn_u32(
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
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi1::BitFieldExtract(System.UInt32,System.Byte,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_bmi1_bit_field_extract_DFE1A(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        // HAND EDITED: The second and third arguments do not need casting.
        return INTRINSIC_CAST(
            unsigned int, TRet, _bextr_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1),
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
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi1::BitFieldExtract(System.UInt32,System.UInt16)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_bmi1_bit_field_extract_A0386(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        // HAND EDITED: The second argument does not need casting.
        return INTRINSIC_CAST(
            unsigned int, TRet, _bextr2_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1),
                arg2
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi1::ExtractLowestSetBit(System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_bmi1_extract_lowest_set_bit(TArg1 arg1)
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _blsi_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi1::GetMaskUpToLowestSetBit(System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_bmi1_get_mask_up_to_lowest_set_bit(TArg1 arg1)
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _blsmsk_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi1::ResetLowestSetBit(System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_bmi1_reset_lowest_set_bit(TArg1 arg1)
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _blsr_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Bmi1::TrailingZeroCount(System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_bmi1_trailing_zero_count(TArg1 arg1)
    {
#if IL2CPP_BMI1_IS_SUPPORTED
        // HAND EDITED: The summary tag listed _mm_tzcnt_32 as the intrinisc, but that is incorrect.
        return INTRINSIC_CAST(
            int, TRet, _tzcnt_u32(
                INTRINSIC_CAST(TArg1, unsigned int, arg1)
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
