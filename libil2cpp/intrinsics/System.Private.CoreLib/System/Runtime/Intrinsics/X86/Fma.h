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
        Method: System.Boolean System.Runtime.Intrinsics.X86.Fma::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_fma_get_is_supported()
    {
#if IL2CPP_FMA_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAdd(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fmadd_pd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAddNegated(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_negated_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fnmadd_pd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAddNegatedScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_negated_scalar_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fnmadd_sd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAddScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_scalar_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fmadd_sd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAddSubtract(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_subtract_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fmaddsub_pd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtract(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fmsub_pd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractAdd(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_add_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fmsubadd_pd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractNegated(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_negated_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fnmsub_pd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractNegatedScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_negated_scalar_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fnmsub_sd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_scalar_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128d, TRet, _mm_fmsub_sd(
            INTRINSIC_CAST(TArg1, __m128d, arg1),
            INTRINSIC_CAST(TArg2, __m128d, arg2),
            INTRINSIC_CAST(TArg3, __m128d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAdd(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fmadd_ps(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAddNegated(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_negated_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fnmadd_ps(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAddNegatedScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_negated_scalar_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fnmadd_ss(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAddScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_scalar_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fmadd_ss(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAddSubtract(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_subtract_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fmaddsub_ps(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtract(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fmsub_ps(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractAdd(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_add_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fmsubadd_ps(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractNegated(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_negated_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fnmsub_ps(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractNegatedScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_negated_scalar_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fnmsub_ss(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_scalar_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128, TRet, _mm_fmsub_ss(
            INTRINSIC_CAST(TArg1, __m128, arg1),
            INTRINSIC_CAST(TArg2, __m128, arg2),
            INTRINSIC_CAST(TArg3, __m128, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAdd(System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_E650E(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256d, TRet, _mm256_fmadd_pd(
            INTRINSIC_CAST(TArg1, __m256d, arg1),
            INTRINSIC_CAST(TArg2, __m256d, arg2),
            INTRINSIC_CAST(TArg3, __m256d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAddNegated(System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_negated_E650E(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256d, TRet, _mm256_fnmadd_pd(
            INTRINSIC_CAST(TArg1, __m256d, arg1),
            INTRINSIC_CAST(TArg2, __m256d, arg2),
            INTRINSIC_CAST(TArg3, __m256d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplyAddSubtract(System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_subtract_E650E(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256d, TRet, _mm256_fmaddsub_pd(
            INTRINSIC_CAST(TArg1, __m256d, arg1),
            INTRINSIC_CAST(TArg2, __m256d, arg2),
            INTRINSIC_CAST(TArg3, __m256d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtract(System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_E650E(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256d, TRet, _mm256_fmsub_pd(
            INTRINSIC_CAST(TArg1, __m256d, arg1),
            INTRINSIC_CAST(TArg2, __m256d, arg2),
            INTRINSIC_CAST(TArg3, __m256d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractAdd(System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_add_E650E(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256d, TRet, _mm256_fmsubadd_pd(
            INTRINSIC_CAST(TArg1, __m256d, arg1),
            INTRINSIC_CAST(TArg2, __m256d, arg2),
            INTRINSIC_CAST(TArg3, __m256d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Double> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractNegated(System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>,System.Runtime.Intrinsics.Vector256`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_negated_E650E(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256d, TRet, _mm256_fnmsub_pd(
            INTRINSIC_CAST(TArg1, __m256d, arg1),
            INTRINSIC_CAST(TArg2, __m256d, arg2),
            INTRINSIC_CAST(TArg3, __m256d, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAdd(System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_BAF09(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256, TRet, _mm256_fmadd_ps(
            INTRINSIC_CAST(TArg1, __m256, arg1),
            INTRINSIC_CAST(TArg2, __m256, arg2),
            INTRINSIC_CAST(TArg3, __m256, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAddNegated(System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_negated_BAF09(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256, TRet, _mm256_fnmadd_ps(
            INTRINSIC_CAST(TArg1, __m256, arg1),
            INTRINSIC_CAST(TArg2, __m256, arg2),
            INTRINSIC_CAST(TArg3, __m256, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplyAddSubtract(System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_add_subtract_BAF09(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256, TRet, _mm256_fmaddsub_ps(
            INTRINSIC_CAST(TArg1, __m256, arg1),
            INTRINSIC_CAST(TArg2, __m256, arg2),
            INTRINSIC_CAST(TArg3, __m256, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtract(System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_BAF09(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256, TRet, _mm256_fmsub_ps(
            INTRINSIC_CAST(TArg1, __m256, arg1),
            INTRINSIC_CAST(TArg2, __m256, arg2),
            INTRINSIC_CAST(TArg3, __m256, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractAdd(System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_add_BAF09(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256, TRet, _mm256_fmsubadd_ps(
            INTRINSIC_CAST(TArg1, __m256, arg1),
            INTRINSIC_CAST(TArg2, __m256, arg2),
            INTRINSIC_CAST(TArg3, __m256, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector256`1<System.Single> System.Runtime.Intrinsics.X86.Fma::MultiplySubtractNegated(System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>,System.Runtime.Intrinsics.Vector256`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_fma_multiply_subtract_negated_BAF09(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_FMA_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m256, TRet, _mm256_fnmsub_ps(
            INTRINSIC_CAST(TArg1, __m256, arg1),
            INTRINSIC_CAST(TArg2, __m256, arg2),
            INTRINSIC_CAST(TArg3, __m256, arg3)
        ));
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
