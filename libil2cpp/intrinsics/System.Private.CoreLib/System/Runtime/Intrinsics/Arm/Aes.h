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
        Method: System.Boolean System.Runtime.Intrinsics.Arm.Aes::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_aes_get_is_supported()
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.Arm.Aes::Decrypt(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_decrypt(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint8x16_t, TRet, vaesdq_u8(
                INTRINSIC_CAST(TArg1, uint8x16_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x16_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.Arm.Aes::Encrypt(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_encrypt(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint8x16_t, TRet, vaeseq_u8(
                INTRINSIC_CAST(TArg1, uint8x16_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x16_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.Arm.Aes::InverseMixColumns(System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_aes_inverse_mix_columns(TArg1 arg1)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint8x16_t, TRet, vaesimcq_u8(
                INTRINSIC_CAST(TArg1, uint8x16_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.Arm.Aes::MixColumns(System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_aes_mix_columns(TArg1 arg1)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint8x16_t, TRet, vaesmcq_u8(
                INTRINSIC_CAST(TArg1, uint8x16_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.Arm.Aes::PolynomialMultiplyWideningLower(System.Runtime.Intrinsics.Vector64`1<System.Int64>,System.Runtime.Intrinsics.Vector64`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_polynomial_multiply_widening_lower_6784B(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            poly128_t, TRet, vmull_p64(
                INTRINSIC_CAST(TArg1, poly64_t, arg1),
                INTRINSIC_CAST(TArg2, poly64_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.Arm.Aes::PolynomialMultiplyWideningUpper(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_polynomial_multiply_widening_upper_6C932(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            poly128_t, TRet, vmull_high_p64(
                INTRINSIC_CAST(TArg1, poly64x2_t, arg1),
                INTRINSIC_CAST(TArg2, poly64x2_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.Arm.Aes::PolynomialMultiplyWideningLower(System.Runtime.Intrinsics.Vector64`1<System.UInt64>,System.Runtime.Intrinsics.Vector64`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_polynomial_multiply_widening_lower_DFC12(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            poly128_t, TRet, vmull_p64(
                INTRINSIC_CAST(TArg1, poly64_t, arg1),
                INTRINSIC_CAST(TArg2, poly64_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.Arm.Aes::PolynomialMultiplyWideningUpper(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_polynomial_multiply_widening_upper_638EB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_AES_IS_SUPPORTED
        return INTRINSIC_CAST(
            poly128_t, TRet, vmull_high_p64(
                INTRINSIC_CAST(TArg1, poly64x2_t, arg1),
                INTRINSIC_CAST(TArg2, poly64x2_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Arm
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
