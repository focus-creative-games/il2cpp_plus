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
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_sse41_get_is_supported()
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int16(System.Byte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int16(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepu8_epi16(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int16(System.SByte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int16_5399E(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepi8_epi16(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.Byte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepu8_epi32(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.Int16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32_2CA79(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepi16_epi32(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.SByte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32_5399E(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepi8_epi32(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.UInt16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32_FA329(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepu16_epi32(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Byte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepu8_epi64(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Int16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_2CA79(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepi16_epi64(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Int32*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_BD4B5(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepi32_epi64(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.SByte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_5399E(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepi8_epi64(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.UInt16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_FA329(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepu16_epi64(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.UInt32*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_BE5D7(TArg1 arg1)
    {
        // Hand edited: added implementation, fixed METHOD MAPPING, fixed unique function name
#if IL2CPP_SSE41_IS_SUPPORTED
        __m128i vArg1;
        std::memcpy(&vArg1, arg1, sizeof(vArg1));
        return INTRINSIC_CAST(__m128i, TRet, _mm_cvtepu32_epi64(vArg1));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundCurrentDirection(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_current_direction_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_CUR_DIRECTION
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundCurrentDirectionScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_current_direction_scalar_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_sd requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_CUR_DIRECTION
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundCurrentDirectionScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_current_direction_scalar_EDABB(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                _MM_FROUND_CUR_DIRECTION
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToNearestInteger(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_nearest_integer_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, return parameter
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToNearestIntegerScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_nearest_integer_scalar_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_sd requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToNearestIntegerScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_nearest_integer_scalar_EDABB(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToNegativeInfinity(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_negative_infinity_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, return parameter
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToNegativeInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_negative_infinity_scalar_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, __mm_round_sd requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToNegativeInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_negative_infinity_scalar_EDABB(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToPositiveInfinity(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_positive_infinity_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, return parameter
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToPositiveInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_positive_infinity_scalar_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_sd requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToPositiveInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_positive_infinity_scalar_EDABB(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToZero(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_zero_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToZeroScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_zero_scalar_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, return parameter, __mm_round_sd requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::RoundToZeroScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_zero_scalar_EDABB(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_round_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundCurrentDirection(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_current_direction_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_CUR_DIRECTION
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundCurrentDirectionScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_current_direction_scalar_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_ss requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_CUR_DIRECTION
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundCurrentDirectionScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_current_direction_scalar_A51C1(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                _MM_FROUND_CUR_DIRECTION
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToNearestInteger(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_nearest_integer_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToNearestIntegerScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_nearest_integer_scalar_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_ss requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToNearestIntegerScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_nearest_integer_scalar_A51C1(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToNegativeInfinity(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_negative_infinity_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToNegativeInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_negative_infinity_scalar_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_ss requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToNegativeInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_negative_infinity_scalar_A51C1(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToPositiveInfinity(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_positive_infinity_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToPositiveInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_positive_infinity_scalar_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_ss requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToPositiveInfinityScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_positive_infinity_scalar_A51C1(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToZero(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_zero_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToZeroScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_round_to_zero_scalar_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_round_ss requires 3 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg1, __m128, arg1),
                _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::RoundToZeroScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_round_to_zero_scalar_A51C1(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Fixed intrinsic parameters
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_round_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::CeilingScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_ceiling_scalar_593F6(TArg1 arg1)
    {
        //HAND EDITED: Fixed intrinsic parameters, __mm_ceil_sd requires 2 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_ceil_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg1, __m128d, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::FloorScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_floor_scalar_593F6(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_floor_sd requires 2 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_floor_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg1, __m128d, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::CeilingScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_ceiling_scalar_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_ceil_ss takes two parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_ceil_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::FloorScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_floor_scalar_65DAE(TArg1 arg1)
    {
        // HAND EDITED: Fixed intrinsic parameters, _mm_floor_ss takes 2 parameters, made upper and value the same
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_floor_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::Blend(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_AEBBD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: Added a bit mask and removed cases 8-255. The least 3 significant bits are what matters: https://www.felixcloutier.com/x86/blendps
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3 & 0x7)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_blend_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        7
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_blend_AEBBD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: Added a bit mask as the least 3 significant bits are what matters: https://www.felixcloutier.com/x86/blendps
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128, TRet, _mm_blend_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                TArg3Value & 0x7
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::Blend(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_A3CAA(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: Added bit mask and removed cases 4-255, least 2 significant bits are what matter: https://www.felixcloutier.com/x86/blendpd
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3 & 0x3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_blend_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_blend_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_blend_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_blend_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_blend_A3CAA(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: Added bit mask to TArg3Value, least 2 significant bits are what matter: https://www.felixcloutier.com/x86/blendpd
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128d, TRet, _mm_blend_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                TArg3Value & 0x3
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.X86.Sse41::Insert(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.UInt32,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_insert_1E961(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: Added bit mask and removed cases 4-255, least 2 significant bits are what matter: https://www.felixcloutier.com/x86/pinsrb:pinsrd:pinsrq
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3 & 0x3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_insert_1E961(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: Added bit mask to TArg3Value, least 2 significant bits are what matter
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128i, TRet, _mm_insert_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, int, arg2),
                TArg3Value & 0x3
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Byte System.Runtime.Intrinsics.X86.Sse41::Extract(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [1]
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_extract_B90AA(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Removed cases 16-255 and added bit mask to arg2, least 4 significant bits are what matter
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg2 & 0xF)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        15
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, int TArg2Value>
    inline TRet il2cpp_intrinsic_sse41_extract_B90AA(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Bitmasked TArg2Value with 0xF as the 4 least significant bits are what matter
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg2Value < 0 || TArg2Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int, TRet, _mm_extract_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                TArg2Value & 0xF
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.X86.Sse41::Extract(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [1]
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_extract_CFA53(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Removed cases 4-15 and bitmasked with 0x3 as the 2 least significant bits are what matter
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg2 & 0x3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, int TArg2Value>
    inline TRet il2cpp_intrinsic_sse41_extract_CFA53(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED: Bitmasked TArg2Value with 0x3 as the 2 least significant bits are what matter
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg2Value < 0 || TArg2Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int, TRet, _mm_extract_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                TArg2Value & 0x3
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.SByte> System.Runtime.Intrinsics.X86.Sse41::Insert(System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.SByte,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_insert_325DD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3 & 0xF)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        15
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_insert_325DD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED:
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128i, TRet, _mm_insert_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, int, arg2),
                TArg3Value & 0xF
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Sse41::Insert(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Byte,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_insert_2DED8(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: Removed cases 16-255 and bitmasked with 0xF as the 4 least significant bits are what matter
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3 & 0xF)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        15
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_insert_2DED8(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED: bitmasked TArg3Value with 0xF as the 4 least significant bits are what matter
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128i, TRet, _mm_insert_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, int, arg2),
                TArg3Value & 0xF
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::Insert(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Int32,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_insert_DC4B6(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED:
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3 & 0x3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int, arg2),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_insert_DC4B6(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        // HAND EDITED:
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128i, TRet, _mm_insert_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, int, arg2),
                TArg3Value & 0x3
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Single System.Runtime.Intrinsics.X86.Sse41::Extract(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [1]
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_extract_7D4DE(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED:
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg2 & 0x3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, int TArg2Value>
    inline TRet il2cpp_intrinsic_sse41_extract_7D4DE(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED:
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg2Value < 0 || TArg2Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int, TRet, _mm_extract_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                TArg2Value & 0x3
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Sse41::Extract(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [1]
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_extract_2AC76(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED:
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg2 & 0x3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int, TRet, _mm_extract_epi32(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, int TArg2Value>
    inline TRet il2cpp_intrinsic_sse41_extract_2AC76(TArg1 arg1, TArg2 arg2)
    {
        // HAND EDITED:
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg2Value < 0 || TArg2Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int, TRet, _mm_extract_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                TArg2Value & 0x3
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_9571C(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_B23C8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_DBCD4(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_6C932(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_FF0D8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_899B1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_A1D32(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestC(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testc_638EB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_9571C(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_B23C8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_DBCD4(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_6C932(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_FF0D8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_899B1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_A1D32(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestNotZAndNotC(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_test_not_z_and_notc_638EB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testnzc_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_9571C(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_B23C8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_DBCD4(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_6C932(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_FF0D8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_899B1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_A1D32(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41::TestZ(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_testz_638EB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            int, TRet, _mm_testz_si128(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_1BA1A(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.Byte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_7E353(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_552DF(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_blendv_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                INTRINSIC_CAST(TArg3, __m128d, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::Ceiling(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_ceiling_593F6(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_ceil_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::CeilingScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_ceiling_scalar_EDABB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_ceil_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::DotProduct(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_dot_product_A3CAA(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        15
                    )
                );
            }
            case 16:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        16
                    )
                );
            }
            case 17:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        17
                    )
                );
            }
            case 18:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        18
                    )
                );
            }
            case 19:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        19
                    )
                );
            }
            case 20:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        20
                    )
                );
            }
            case 21:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        21
                    )
                );
            }
            case 22:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        22
                    )
                );
            }
            case 23:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        23
                    )
                );
            }
            case 24:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        24
                    )
                );
            }
            case 25:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        25
                    )
                );
            }
            case 26:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        26
                    )
                );
            }
            case 27:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        27
                    )
                );
            }
            case 28:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        28
                    )
                );
            }
            case 29:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        29
                    )
                );
            }
            case 30:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        30
                    )
                );
            }
            case 31:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        31
                    )
                );
            }
            case 32:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        32
                    )
                );
            }
            case 33:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        33
                    )
                );
            }
            case 34:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        34
                    )
                );
            }
            case 35:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        35
                    )
                );
            }
            case 36:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        36
                    )
                );
            }
            case 37:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        37
                    )
                );
            }
            case 38:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        38
                    )
                );
            }
            case 39:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        39
                    )
                );
            }
            case 40:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        40
                    )
                );
            }
            case 41:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        41
                    )
                );
            }
            case 42:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        42
                    )
                );
            }
            case 43:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        43
                    )
                );
            }
            case 44:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        44
                    )
                );
            }
            case 45:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        45
                    )
                );
            }
            case 46:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        46
                    )
                );
            }
            case 47:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        47
                    )
                );
            }
            case 48:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        48
                    )
                );
            }
            case 49:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        49
                    )
                );
            }
            case 50:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        50
                    )
                );
            }
            case 51:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        51
                    )
                );
            }
            case 52:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        52
                    )
                );
            }
            case 53:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        53
                    )
                );
            }
            case 54:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        54
                    )
                );
            }
            case 55:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        55
                    )
                );
            }
            case 56:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        56
                    )
                );
            }
            case 57:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        57
                    )
                );
            }
            case 58:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        58
                    )
                );
            }
            case 59:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        59
                    )
                );
            }
            case 60:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        60
                    )
                );
            }
            case 61:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        61
                    )
                );
            }
            case 62:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        62
                    )
                );
            }
            case 63:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        63
                    )
                );
            }
            case 64:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        64
                    )
                );
            }
            case 65:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        65
                    )
                );
            }
            case 66:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        66
                    )
                );
            }
            case 67:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        67
                    )
                );
            }
            case 68:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        68
                    )
                );
            }
            case 69:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        69
                    )
                );
            }
            case 70:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        70
                    )
                );
            }
            case 71:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        71
                    )
                );
            }
            case 72:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        72
                    )
                );
            }
            case 73:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        73
                    )
                );
            }
            case 74:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        74
                    )
                );
            }
            case 75:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        75
                    )
                );
            }
            case 76:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        76
                    )
                );
            }
            case 77:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        77
                    )
                );
            }
            case 78:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        78
                    )
                );
            }
            case 79:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        79
                    )
                );
            }
            case 80:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        80
                    )
                );
            }
            case 81:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        81
                    )
                );
            }
            case 82:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        82
                    )
                );
            }
            case 83:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        83
                    )
                );
            }
            case 84:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        84
                    )
                );
            }
            case 85:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        85
                    )
                );
            }
            case 86:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        86
                    )
                );
            }
            case 87:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        87
                    )
                );
            }
            case 88:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        88
                    )
                );
            }
            case 89:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        89
                    )
                );
            }
            case 90:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        90
                    )
                );
            }
            case 91:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        91
                    )
                );
            }
            case 92:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        92
                    )
                );
            }
            case 93:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        93
                    )
                );
            }
            case 94:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        94
                    )
                );
            }
            case 95:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        95
                    )
                );
            }
            case 96:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        96
                    )
                );
            }
            case 97:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        97
                    )
                );
            }
            case 98:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        98
                    )
                );
            }
            case 99:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        99
                    )
                );
            }
            case 100:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        100
                    )
                );
            }
            case 101:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        101
                    )
                );
            }
            case 102:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        102
                    )
                );
            }
            case 103:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        103
                    )
                );
            }
            case 104:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        104
                    )
                );
            }
            case 105:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        105
                    )
                );
            }
            case 106:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        106
                    )
                );
            }
            case 107:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        107
                    )
                );
            }
            case 108:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        108
                    )
                );
            }
            case 109:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        109
                    )
                );
            }
            case 110:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        110
                    )
                );
            }
            case 111:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        111
                    )
                );
            }
            case 112:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        112
                    )
                );
            }
            case 113:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        113
                    )
                );
            }
            case 114:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        114
                    )
                );
            }
            case 115:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        115
                    )
                );
            }
            case 116:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        116
                    )
                );
            }
            case 117:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        117
                    )
                );
            }
            case 118:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        118
                    )
                );
            }
            case 119:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        119
                    )
                );
            }
            case 120:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        120
                    )
                );
            }
            case 121:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        121
                    )
                );
            }
            case 122:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        122
                    )
                );
            }
            case 123:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        123
                    )
                );
            }
            case 124:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        124
                    )
                );
            }
            case 125:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        125
                    )
                );
            }
            case 126:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        126
                    )
                );
            }
            case 127:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        127
                    )
                );
            }
            case 128:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        128
                    )
                );
            }
            case 129:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        129
                    )
                );
            }
            case 130:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        130
                    )
                );
            }
            case 131:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        131
                    )
                );
            }
            case 132:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        132
                    )
                );
            }
            case 133:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        133
                    )
                );
            }
            case 134:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        134
                    )
                );
            }
            case 135:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        135
                    )
                );
            }
            case 136:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        136
                    )
                );
            }
            case 137:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        137
                    )
                );
            }
            case 138:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        138
                    )
                );
            }
            case 139:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        139
                    )
                );
            }
            case 140:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        140
                    )
                );
            }
            case 141:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        141
                    )
                );
            }
            case 142:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        142
                    )
                );
            }
            case 143:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        143
                    )
                );
            }
            case 144:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        144
                    )
                );
            }
            case 145:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        145
                    )
                );
            }
            case 146:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        146
                    )
                );
            }
            case 147:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        147
                    )
                );
            }
            case 148:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        148
                    )
                );
            }
            case 149:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        149
                    )
                );
            }
            case 150:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        150
                    )
                );
            }
            case 151:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        151
                    )
                );
            }
            case 152:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        152
                    )
                );
            }
            case 153:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        153
                    )
                );
            }
            case 154:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        154
                    )
                );
            }
            case 155:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        155
                    )
                );
            }
            case 156:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        156
                    )
                );
            }
            case 157:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        157
                    )
                );
            }
            case 158:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        158
                    )
                );
            }
            case 159:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        159
                    )
                );
            }
            case 160:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        160
                    )
                );
            }
            case 161:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        161
                    )
                );
            }
            case 162:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        162
                    )
                );
            }
            case 163:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        163
                    )
                );
            }
            case 164:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        164
                    )
                );
            }
            case 165:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        165
                    )
                );
            }
            case 166:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        166
                    )
                );
            }
            case 167:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        167
                    )
                );
            }
            case 168:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        168
                    )
                );
            }
            case 169:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        169
                    )
                );
            }
            case 170:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        170
                    )
                );
            }
            case 171:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        171
                    )
                );
            }
            case 172:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        172
                    )
                );
            }
            case 173:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        173
                    )
                );
            }
            case 174:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        174
                    )
                );
            }
            case 175:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        175
                    )
                );
            }
            case 176:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        176
                    )
                );
            }
            case 177:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        177
                    )
                );
            }
            case 178:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        178
                    )
                );
            }
            case 179:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        179
                    )
                );
            }
            case 180:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        180
                    )
                );
            }
            case 181:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        181
                    )
                );
            }
            case 182:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        182
                    )
                );
            }
            case 183:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        183
                    )
                );
            }
            case 184:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        184
                    )
                );
            }
            case 185:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        185
                    )
                );
            }
            case 186:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        186
                    )
                );
            }
            case 187:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        187
                    )
                );
            }
            case 188:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        188
                    )
                );
            }
            case 189:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        189
                    )
                );
            }
            case 190:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        190
                    )
                );
            }
            case 191:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        191
                    )
                );
            }
            case 192:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        192
                    )
                );
            }
            case 193:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        193
                    )
                );
            }
            case 194:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        194
                    )
                );
            }
            case 195:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        195
                    )
                );
            }
            case 196:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        196
                    )
                );
            }
            case 197:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        197
                    )
                );
            }
            case 198:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        198
                    )
                );
            }
            case 199:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        199
                    )
                );
            }
            case 200:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        200
                    )
                );
            }
            case 201:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        201
                    )
                );
            }
            case 202:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        202
                    )
                );
            }
            case 203:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        203
                    )
                );
            }
            case 204:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        204
                    )
                );
            }
            case 205:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        205
                    )
                );
            }
            case 206:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        206
                    )
                );
            }
            case 207:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        207
                    )
                );
            }
            case 208:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        208
                    )
                );
            }
            case 209:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        209
                    )
                );
            }
            case 210:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        210
                    )
                );
            }
            case 211:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        211
                    )
                );
            }
            case 212:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        212
                    )
                );
            }
            case 213:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        213
                    )
                );
            }
            case 214:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        214
                    )
                );
            }
            case 215:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        215
                    )
                );
            }
            case 216:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        216
                    )
                );
            }
            case 217:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        217
                    )
                );
            }
            case 218:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        218
                    )
                );
            }
            case 219:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        219
                    )
                );
            }
            case 220:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        220
                    )
                );
            }
            case 221:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        221
                    )
                );
            }
            case 222:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        222
                    )
                );
            }
            case 223:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        223
                    )
                );
            }
            case 224:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        224
                    )
                );
            }
            case 225:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        225
                    )
                );
            }
            case 226:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        226
                    )
                );
            }
            case 227:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        227
                    )
                );
            }
            case 228:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        228
                    )
                );
            }
            case 229:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        229
                    )
                );
            }
            case 230:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        230
                    )
                );
            }
            case 231:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        231
                    )
                );
            }
            case 232:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        232
                    )
                );
            }
            case 233:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        233
                    )
                );
            }
            case 234:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        234
                    )
                );
            }
            case 235:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        235
                    )
                );
            }
            case 236:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        236
                    )
                );
            }
            case 237:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        237
                    )
                );
            }
            case 238:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        238
                    )
                );
            }
            case 239:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        239
                    )
                );
            }
            case 240:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        240
                    )
                );
            }
            case 241:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        241
                    )
                );
            }
            case 242:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        242
                    )
                );
            }
            case 243:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        243
                    )
                );
            }
            case 244:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        244
                    )
                );
            }
            case 245:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        245
                    )
                );
            }
            case 246:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        246
                    )
                );
            }
            case 247:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        247
                    )
                );
            }
            case 248:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        248
                    )
                );
            }
            case 249:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        249
                    )
                );
            }
            case 250:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        250
                    )
                );
            }
            case 251:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        251
                    )
                );
            }
            case 252:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        252
                    )
                );
            }
            case 253:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        253
                    )
                );
            }
            case 254:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        254
                    )
                );
            }
            case 255:
            {
                return INTRINSIC_CAST(
                    __m128d, TRet, _mm_dp_pd(
                        INTRINSIC_CAST(TArg1, __m128d, arg1),
                        INTRINSIC_CAST(TArg2, __m128d, arg2),
                        255
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_dot_product_A3CAA(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128d, TRet, _mm_dp_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2),
                TArg3Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::Floor(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_floor_593F6(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_floor_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse41::FloorScalar(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_floor_scalar_EDABB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_floor_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, __m128d, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse41::Blend(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_22FB7(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        15
                    )
                );
            }
            case 16:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        16
                    )
                );
            }
            case 17:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        17
                    )
                );
            }
            case 18:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        18
                    )
                );
            }
            case 19:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        19
                    )
                );
            }
            case 20:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        20
                    )
                );
            }
            case 21:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        21
                    )
                );
            }
            case 22:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        22
                    )
                );
            }
            case 23:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        23
                    )
                );
            }
            case 24:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        24
                    )
                );
            }
            case 25:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        25
                    )
                );
            }
            case 26:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        26
                    )
                );
            }
            case 27:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        27
                    )
                );
            }
            case 28:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        28
                    )
                );
            }
            case 29:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        29
                    )
                );
            }
            case 30:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        30
                    )
                );
            }
            case 31:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        31
                    )
                );
            }
            case 32:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        32
                    )
                );
            }
            case 33:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        33
                    )
                );
            }
            case 34:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        34
                    )
                );
            }
            case 35:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        35
                    )
                );
            }
            case 36:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        36
                    )
                );
            }
            case 37:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        37
                    )
                );
            }
            case 38:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        38
                    )
                );
            }
            case 39:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        39
                    )
                );
            }
            case 40:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        40
                    )
                );
            }
            case 41:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        41
                    )
                );
            }
            case 42:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        42
                    )
                );
            }
            case 43:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        43
                    )
                );
            }
            case 44:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        44
                    )
                );
            }
            case 45:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        45
                    )
                );
            }
            case 46:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        46
                    )
                );
            }
            case 47:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        47
                    )
                );
            }
            case 48:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        48
                    )
                );
            }
            case 49:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        49
                    )
                );
            }
            case 50:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        50
                    )
                );
            }
            case 51:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        51
                    )
                );
            }
            case 52:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        52
                    )
                );
            }
            case 53:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        53
                    )
                );
            }
            case 54:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        54
                    )
                );
            }
            case 55:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        55
                    )
                );
            }
            case 56:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        56
                    )
                );
            }
            case 57:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        57
                    )
                );
            }
            case 58:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        58
                    )
                );
            }
            case 59:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        59
                    )
                );
            }
            case 60:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        60
                    )
                );
            }
            case 61:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        61
                    )
                );
            }
            case 62:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        62
                    )
                );
            }
            case 63:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        63
                    )
                );
            }
            case 64:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        64
                    )
                );
            }
            case 65:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        65
                    )
                );
            }
            case 66:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        66
                    )
                );
            }
            case 67:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        67
                    )
                );
            }
            case 68:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        68
                    )
                );
            }
            case 69:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        69
                    )
                );
            }
            case 70:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        70
                    )
                );
            }
            case 71:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        71
                    )
                );
            }
            case 72:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        72
                    )
                );
            }
            case 73:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        73
                    )
                );
            }
            case 74:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        74
                    )
                );
            }
            case 75:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        75
                    )
                );
            }
            case 76:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        76
                    )
                );
            }
            case 77:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        77
                    )
                );
            }
            case 78:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        78
                    )
                );
            }
            case 79:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        79
                    )
                );
            }
            case 80:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        80
                    )
                );
            }
            case 81:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        81
                    )
                );
            }
            case 82:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        82
                    )
                );
            }
            case 83:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        83
                    )
                );
            }
            case 84:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        84
                    )
                );
            }
            case 85:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        85
                    )
                );
            }
            case 86:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        86
                    )
                );
            }
            case 87:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        87
                    )
                );
            }
            case 88:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        88
                    )
                );
            }
            case 89:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        89
                    )
                );
            }
            case 90:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        90
                    )
                );
            }
            case 91:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        91
                    )
                );
            }
            case 92:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        92
                    )
                );
            }
            case 93:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        93
                    )
                );
            }
            case 94:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        94
                    )
                );
            }
            case 95:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        95
                    )
                );
            }
            case 96:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        96
                    )
                );
            }
            case 97:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        97
                    )
                );
            }
            case 98:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        98
                    )
                );
            }
            case 99:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        99
                    )
                );
            }
            case 100:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        100
                    )
                );
            }
            case 101:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        101
                    )
                );
            }
            case 102:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        102
                    )
                );
            }
            case 103:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        103
                    )
                );
            }
            case 104:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        104
                    )
                );
            }
            case 105:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        105
                    )
                );
            }
            case 106:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        106
                    )
                );
            }
            case 107:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        107
                    )
                );
            }
            case 108:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        108
                    )
                );
            }
            case 109:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        109
                    )
                );
            }
            case 110:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        110
                    )
                );
            }
            case 111:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        111
                    )
                );
            }
            case 112:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        112
                    )
                );
            }
            case 113:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        113
                    )
                );
            }
            case 114:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        114
                    )
                );
            }
            case 115:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        115
                    )
                );
            }
            case 116:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        116
                    )
                );
            }
            case 117:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        117
                    )
                );
            }
            case 118:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        118
                    )
                );
            }
            case 119:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        119
                    )
                );
            }
            case 120:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        120
                    )
                );
            }
            case 121:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        121
                    )
                );
            }
            case 122:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        122
                    )
                );
            }
            case 123:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        123
                    )
                );
            }
            case 124:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        124
                    )
                );
            }
            case 125:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        125
                    )
                );
            }
            case 126:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        126
                    )
                );
            }
            case 127:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        127
                    )
                );
            }
            case 128:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        128
                    )
                );
            }
            case 129:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        129
                    )
                );
            }
            case 130:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        130
                    )
                );
            }
            case 131:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        131
                    )
                );
            }
            case 132:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        132
                    )
                );
            }
            case 133:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        133
                    )
                );
            }
            case 134:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        134
                    )
                );
            }
            case 135:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        135
                    )
                );
            }
            case 136:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        136
                    )
                );
            }
            case 137:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        137
                    )
                );
            }
            case 138:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        138
                    )
                );
            }
            case 139:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        139
                    )
                );
            }
            case 140:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        140
                    )
                );
            }
            case 141:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        141
                    )
                );
            }
            case 142:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        142
                    )
                );
            }
            case 143:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        143
                    )
                );
            }
            case 144:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        144
                    )
                );
            }
            case 145:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        145
                    )
                );
            }
            case 146:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        146
                    )
                );
            }
            case 147:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        147
                    )
                );
            }
            case 148:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        148
                    )
                );
            }
            case 149:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        149
                    )
                );
            }
            case 150:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        150
                    )
                );
            }
            case 151:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        151
                    )
                );
            }
            case 152:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        152
                    )
                );
            }
            case 153:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        153
                    )
                );
            }
            case 154:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        154
                    )
                );
            }
            case 155:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        155
                    )
                );
            }
            case 156:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        156
                    )
                );
            }
            case 157:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        157
                    )
                );
            }
            case 158:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        158
                    )
                );
            }
            case 159:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        159
                    )
                );
            }
            case 160:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        160
                    )
                );
            }
            case 161:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        161
                    )
                );
            }
            case 162:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        162
                    )
                );
            }
            case 163:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        163
                    )
                );
            }
            case 164:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        164
                    )
                );
            }
            case 165:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        165
                    )
                );
            }
            case 166:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        166
                    )
                );
            }
            case 167:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        167
                    )
                );
            }
            case 168:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        168
                    )
                );
            }
            case 169:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        169
                    )
                );
            }
            case 170:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        170
                    )
                );
            }
            case 171:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        171
                    )
                );
            }
            case 172:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        172
                    )
                );
            }
            case 173:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        173
                    )
                );
            }
            case 174:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        174
                    )
                );
            }
            case 175:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        175
                    )
                );
            }
            case 176:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        176
                    )
                );
            }
            case 177:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        177
                    )
                );
            }
            case 178:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        178
                    )
                );
            }
            case 179:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        179
                    )
                );
            }
            case 180:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        180
                    )
                );
            }
            case 181:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        181
                    )
                );
            }
            case 182:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        182
                    )
                );
            }
            case 183:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        183
                    )
                );
            }
            case 184:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        184
                    )
                );
            }
            case 185:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        185
                    )
                );
            }
            case 186:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        186
                    )
                );
            }
            case 187:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        187
                    )
                );
            }
            case 188:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        188
                    )
                );
            }
            case 189:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        189
                    )
                );
            }
            case 190:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        190
                    )
                );
            }
            case 191:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        191
                    )
                );
            }
            case 192:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        192
                    )
                );
            }
            case 193:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        193
                    )
                );
            }
            case 194:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        194
                    )
                );
            }
            case 195:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        195
                    )
                );
            }
            case 196:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        196
                    )
                );
            }
            case 197:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        197
                    )
                );
            }
            case 198:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        198
                    )
                );
            }
            case 199:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        199
                    )
                );
            }
            case 200:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        200
                    )
                );
            }
            case 201:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        201
                    )
                );
            }
            case 202:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        202
                    )
                );
            }
            case 203:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        203
                    )
                );
            }
            case 204:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        204
                    )
                );
            }
            case 205:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        205
                    )
                );
            }
            case 206:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        206
                    )
                );
            }
            case 207:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        207
                    )
                );
            }
            case 208:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        208
                    )
                );
            }
            case 209:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        209
                    )
                );
            }
            case 210:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        210
                    )
                );
            }
            case 211:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        211
                    )
                );
            }
            case 212:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        212
                    )
                );
            }
            case 213:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        213
                    )
                );
            }
            case 214:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        214
                    )
                );
            }
            case 215:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        215
                    )
                );
            }
            case 216:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        216
                    )
                );
            }
            case 217:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        217
                    )
                );
            }
            case 218:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        218
                    )
                );
            }
            case 219:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        219
                    )
                );
            }
            case 220:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        220
                    )
                );
            }
            case 221:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        221
                    )
                );
            }
            case 222:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        222
                    )
                );
            }
            case 223:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        223
                    )
                );
            }
            case 224:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        224
                    )
                );
            }
            case 225:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        225
                    )
                );
            }
            case 226:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        226
                    )
                );
            }
            case 227:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        227
                    )
                );
            }
            case 228:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        228
                    )
                );
            }
            case 229:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        229
                    )
                );
            }
            case 230:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        230
                    )
                );
            }
            case 231:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        231
                    )
                );
            }
            case 232:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        232
                    )
                );
            }
            case 233:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        233
                    )
                );
            }
            case 234:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        234
                    )
                );
            }
            case 235:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        235
                    )
                );
            }
            case 236:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        236
                    )
                );
            }
            case 237:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        237
                    )
                );
            }
            case 238:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        238
                    )
                );
            }
            case 239:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        239
                    )
                );
            }
            case 240:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        240
                    )
                );
            }
            case 241:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        241
                    )
                );
            }
            case 242:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        242
                    )
                );
            }
            case 243:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        243
                    )
                );
            }
            case 244:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        244
                    )
                );
            }
            case 245:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        245
                    )
                );
            }
            case 246:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        246
                    )
                );
            }
            case 247:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        247
                    )
                );
            }
            case 248:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        248
                    )
                );
            }
            case 249:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        249
                    )
                );
            }
            case 250:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        250
                    )
                );
            }
            case 251:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        251
                    )
                );
            }
            case 252:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        252
                    )
                );
            }
            case 253:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        253
                    )
                );
            }
            case 254:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        254
                    )
                );
            }
            case 255:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        255
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_blend_22FB7(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blend_epi16(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                TArg3Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_E0525(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int16(System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int16_FB916(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepu8_epi16(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int16(System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int16_02242(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepi8_epi16(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.Int16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_2CA79(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_5D9DC(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32_FB916(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepu8_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32_2A842(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepi16_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32_02242(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepi8_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int32(System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int32_D0359(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepu16_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.Int32*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_BD4B5(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::Max(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_max_DBCD4(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_max_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::Min(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_min_DBCD4(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_min_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse41::MultiplyLow(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_multiply_low_DBCD4(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_mullo_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_AD1C8(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::CompareEqual(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_compare_equal_6C932(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cmpeq_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_FB916(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepu8_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_2A842(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepi16_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_F7B07(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepi32_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_02242(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepi8_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_D0359(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepu16_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::ConvertToVector128Int64(System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_convert_to_vector128_int64_40038(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtepu32_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.Int64*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_5325A(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41::Multiply(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_multiply(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_mul_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.SByte> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_63324(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.SByte> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.SByte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_5399E(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.SByte> System.Runtime.Intrinsics.X86.Sse41::Max(System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_max_FF0D8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_max_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.SByte> System.Runtime.Intrinsics.X86.Sse41::Min(System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_min_FF0D8(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_min_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_76B70(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_blendv_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                INTRINSIC_CAST(TArg3, __m128, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::Ceiling(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_ceiling_65DAE(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_ceil_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::CeilingScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_ceiling_scalar_A51C1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_ceil_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::DotProduct(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_dot_product_AEBBD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        15
                    )
                );
            }
            case 16:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        16
                    )
                );
            }
            case 17:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        17
                    )
                );
            }
            case 18:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        18
                    )
                );
            }
            case 19:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        19
                    )
                );
            }
            case 20:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        20
                    )
                );
            }
            case 21:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        21
                    )
                );
            }
            case 22:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        22
                    )
                );
            }
            case 23:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        23
                    )
                );
            }
            case 24:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        24
                    )
                );
            }
            case 25:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        25
                    )
                );
            }
            case 26:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        26
                    )
                );
            }
            case 27:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        27
                    )
                );
            }
            case 28:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        28
                    )
                );
            }
            case 29:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        29
                    )
                );
            }
            case 30:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        30
                    )
                );
            }
            case 31:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        31
                    )
                );
            }
            case 32:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        32
                    )
                );
            }
            case 33:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        33
                    )
                );
            }
            case 34:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        34
                    )
                );
            }
            case 35:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        35
                    )
                );
            }
            case 36:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        36
                    )
                );
            }
            case 37:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        37
                    )
                );
            }
            case 38:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        38
                    )
                );
            }
            case 39:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        39
                    )
                );
            }
            case 40:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        40
                    )
                );
            }
            case 41:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        41
                    )
                );
            }
            case 42:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        42
                    )
                );
            }
            case 43:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        43
                    )
                );
            }
            case 44:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        44
                    )
                );
            }
            case 45:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        45
                    )
                );
            }
            case 46:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        46
                    )
                );
            }
            case 47:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        47
                    )
                );
            }
            case 48:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        48
                    )
                );
            }
            case 49:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        49
                    )
                );
            }
            case 50:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        50
                    )
                );
            }
            case 51:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        51
                    )
                );
            }
            case 52:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        52
                    )
                );
            }
            case 53:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        53
                    )
                );
            }
            case 54:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        54
                    )
                );
            }
            case 55:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        55
                    )
                );
            }
            case 56:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        56
                    )
                );
            }
            case 57:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        57
                    )
                );
            }
            case 58:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        58
                    )
                );
            }
            case 59:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        59
                    )
                );
            }
            case 60:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        60
                    )
                );
            }
            case 61:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        61
                    )
                );
            }
            case 62:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        62
                    )
                );
            }
            case 63:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        63
                    )
                );
            }
            case 64:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        64
                    )
                );
            }
            case 65:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        65
                    )
                );
            }
            case 66:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        66
                    )
                );
            }
            case 67:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        67
                    )
                );
            }
            case 68:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        68
                    )
                );
            }
            case 69:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        69
                    )
                );
            }
            case 70:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        70
                    )
                );
            }
            case 71:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        71
                    )
                );
            }
            case 72:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        72
                    )
                );
            }
            case 73:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        73
                    )
                );
            }
            case 74:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        74
                    )
                );
            }
            case 75:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        75
                    )
                );
            }
            case 76:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        76
                    )
                );
            }
            case 77:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        77
                    )
                );
            }
            case 78:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        78
                    )
                );
            }
            case 79:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        79
                    )
                );
            }
            case 80:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        80
                    )
                );
            }
            case 81:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        81
                    )
                );
            }
            case 82:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        82
                    )
                );
            }
            case 83:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        83
                    )
                );
            }
            case 84:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        84
                    )
                );
            }
            case 85:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        85
                    )
                );
            }
            case 86:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        86
                    )
                );
            }
            case 87:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        87
                    )
                );
            }
            case 88:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        88
                    )
                );
            }
            case 89:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        89
                    )
                );
            }
            case 90:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        90
                    )
                );
            }
            case 91:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        91
                    )
                );
            }
            case 92:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        92
                    )
                );
            }
            case 93:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        93
                    )
                );
            }
            case 94:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        94
                    )
                );
            }
            case 95:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        95
                    )
                );
            }
            case 96:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        96
                    )
                );
            }
            case 97:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        97
                    )
                );
            }
            case 98:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        98
                    )
                );
            }
            case 99:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        99
                    )
                );
            }
            case 100:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        100
                    )
                );
            }
            case 101:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        101
                    )
                );
            }
            case 102:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        102
                    )
                );
            }
            case 103:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        103
                    )
                );
            }
            case 104:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        104
                    )
                );
            }
            case 105:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        105
                    )
                );
            }
            case 106:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        106
                    )
                );
            }
            case 107:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        107
                    )
                );
            }
            case 108:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        108
                    )
                );
            }
            case 109:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        109
                    )
                );
            }
            case 110:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        110
                    )
                );
            }
            case 111:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        111
                    )
                );
            }
            case 112:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        112
                    )
                );
            }
            case 113:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        113
                    )
                );
            }
            case 114:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        114
                    )
                );
            }
            case 115:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        115
                    )
                );
            }
            case 116:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        116
                    )
                );
            }
            case 117:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        117
                    )
                );
            }
            case 118:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        118
                    )
                );
            }
            case 119:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        119
                    )
                );
            }
            case 120:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        120
                    )
                );
            }
            case 121:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        121
                    )
                );
            }
            case 122:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        122
                    )
                );
            }
            case 123:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        123
                    )
                );
            }
            case 124:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        124
                    )
                );
            }
            case 125:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        125
                    )
                );
            }
            case 126:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        126
                    )
                );
            }
            case 127:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        127
                    )
                );
            }
            case 128:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        128
                    )
                );
            }
            case 129:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        129
                    )
                );
            }
            case 130:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        130
                    )
                );
            }
            case 131:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        131
                    )
                );
            }
            case 132:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        132
                    )
                );
            }
            case 133:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        133
                    )
                );
            }
            case 134:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        134
                    )
                );
            }
            case 135:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        135
                    )
                );
            }
            case 136:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        136
                    )
                );
            }
            case 137:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        137
                    )
                );
            }
            case 138:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        138
                    )
                );
            }
            case 139:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        139
                    )
                );
            }
            case 140:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        140
                    )
                );
            }
            case 141:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        141
                    )
                );
            }
            case 142:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        142
                    )
                );
            }
            case 143:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        143
                    )
                );
            }
            case 144:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        144
                    )
                );
            }
            case 145:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        145
                    )
                );
            }
            case 146:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        146
                    )
                );
            }
            case 147:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        147
                    )
                );
            }
            case 148:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        148
                    )
                );
            }
            case 149:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        149
                    )
                );
            }
            case 150:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        150
                    )
                );
            }
            case 151:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        151
                    )
                );
            }
            case 152:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        152
                    )
                );
            }
            case 153:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        153
                    )
                );
            }
            case 154:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        154
                    )
                );
            }
            case 155:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        155
                    )
                );
            }
            case 156:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        156
                    )
                );
            }
            case 157:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        157
                    )
                );
            }
            case 158:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        158
                    )
                );
            }
            case 159:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        159
                    )
                );
            }
            case 160:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        160
                    )
                );
            }
            case 161:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        161
                    )
                );
            }
            case 162:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        162
                    )
                );
            }
            case 163:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        163
                    )
                );
            }
            case 164:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        164
                    )
                );
            }
            case 165:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        165
                    )
                );
            }
            case 166:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        166
                    )
                );
            }
            case 167:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        167
                    )
                );
            }
            case 168:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        168
                    )
                );
            }
            case 169:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        169
                    )
                );
            }
            case 170:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        170
                    )
                );
            }
            case 171:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        171
                    )
                );
            }
            case 172:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        172
                    )
                );
            }
            case 173:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        173
                    )
                );
            }
            case 174:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        174
                    )
                );
            }
            case 175:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        175
                    )
                );
            }
            case 176:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        176
                    )
                );
            }
            case 177:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        177
                    )
                );
            }
            case 178:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        178
                    )
                );
            }
            case 179:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        179
                    )
                );
            }
            case 180:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        180
                    )
                );
            }
            case 181:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        181
                    )
                );
            }
            case 182:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        182
                    )
                );
            }
            case 183:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        183
                    )
                );
            }
            case 184:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        184
                    )
                );
            }
            case 185:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        185
                    )
                );
            }
            case 186:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        186
                    )
                );
            }
            case 187:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        187
                    )
                );
            }
            case 188:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        188
                    )
                );
            }
            case 189:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        189
                    )
                );
            }
            case 190:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        190
                    )
                );
            }
            case 191:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        191
                    )
                );
            }
            case 192:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        192
                    )
                );
            }
            case 193:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        193
                    )
                );
            }
            case 194:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        194
                    )
                );
            }
            case 195:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        195
                    )
                );
            }
            case 196:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        196
                    )
                );
            }
            case 197:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        197
                    )
                );
            }
            case 198:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        198
                    )
                );
            }
            case 199:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        199
                    )
                );
            }
            case 200:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        200
                    )
                );
            }
            case 201:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        201
                    )
                );
            }
            case 202:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        202
                    )
                );
            }
            case 203:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        203
                    )
                );
            }
            case 204:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        204
                    )
                );
            }
            case 205:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        205
                    )
                );
            }
            case 206:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        206
                    )
                );
            }
            case 207:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        207
                    )
                );
            }
            case 208:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        208
                    )
                );
            }
            case 209:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        209
                    )
                );
            }
            case 210:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        210
                    )
                );
            }
            case 211:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        211
                    )
                );
            }
            case 212:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        212
                    )
                );
            }
            case 213:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        213
                    )
                );
            }
            case 214:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        214
                    )
                );
            }
            case 215:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        215
                    )
                );
            }
            case 216:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        216
                    )
                );
            }
            case 217:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        217
                    )
                );
            }
            case 218:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        218
                    )
                );
            }
            case 219:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        219
                    )
                );
            }
            case 220:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        220
                    )
                );
            }
            case 221:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        221
                    )
                );
            }
            case 222:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        222
                    )
                );
            }
            case 223:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        223
                    )
                );
            }
            case 224:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        224
                    )
                );
            }
            case 225:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        225
                    )
                );
            }
            case 226:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        226
                    )
                );
            }
            case 227:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        227
                    )
                );
            }
            case 228:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        228
                    )
                );
            }
            case 229:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        229
                    )
                );
            }
            case 230:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        230
                    )
                );
            }
            case 231:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        231
                    )
                );
            }
            case 232:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        232
                    )
                );
            }
            case 233:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        233
                    )
                );
            }
            case 234:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        234
                    )
                );
            }
            case 235:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        235
                    )
                );
            }
            case 236:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        236
                    )
                );
            }
            case 237:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        237
                    )
                );
            }
            case 238:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        238
                    )
                );
            }
            case 239:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        239
                    )
                );
            }
            case 240:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        240
                    )
                );
            }
            case 241:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        241
                    )
                );
            }
            case 242:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        242
                    )
                );
            }
            case 243:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        243
                    )
                );
            }
            case 244:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        244
                    )
                );
            }
            case 245:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        245
                    )
                );
            }
            case 246:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        246
                    )
                );
            }
            case 247:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        247
                    )
                );
            }
            case 248:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        248
                    )
                );
            }
            case 249:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        249
                    )
                );
            }
            case 250:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        250
                    )
                );
            }
            case 251:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        251
                    )
                );
            }
            case 252:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        252
                    )
                );
            }
            case 253:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        253
                    )
                );
            }
            case 254:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        254
                    )
                );
            }
            case 255:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_dp_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        255
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_dot_product_AEBBD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128, TRet, _mm_dp_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                TArg3Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::Floor(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_floor_65DAE(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_floor_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::FloorScalar(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_floor_scalar_A51C1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_floor_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse41::Insert(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_insert_AEBBD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        15
                    )
                );
            }
            case 16:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        16
                    )
                );
            }
            case 17:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        17
                    )
                );
            }
            case 18:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        18
                    )
                );
            }
            case 19:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        19
                    )
                );
            }
            case 20:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        20
                    )
                );
            }
            case 21:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        21
                    )
                );
            }
            case 22:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        22
                    )
                );
            }
            case 23:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        23
                    )
                );
            }
            case 24:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        24
                    )
                );
            }
            case 25:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        25
                    )
                );
            }
            case 26:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        26
                    )
                );
            }
            case 27:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        27
                    )
                );
            }
            case 28:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        28
                    )
                );
            }
            case 29:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        29
                    )
                );
            }
            case 30:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        30
                    )
                );
            }
            case 31:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        31
                    )
                );
            }
            case 32:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        32
                    )
                );
            }
            case 33:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        33
                    )
                );
            }
            case 34:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        34
                    )
                );
            }
            case 35:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        35
                    )
                );
            }
            case 36:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        36
                    )
                );
            }
            case 37:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        37
                    )
                );
            }
            case 38:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        38
                    )
                );
            }
            case 39:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        39
                    )
                );
            }
            case 40:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        40
                    )
                );
            }
            case 41:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        41
                    )
                );
            }
            case 42:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        42
                    )
                );
            }
            case 43:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        43
                    )
                );
            }
            case 44:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        44
                    )
                );
            }
            case 45:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        45
                    )
                );
            }
            case 46:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        46
                    )
                );
            }
            case 47:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        47
                    )
                );
            }
            case 48:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        48
                    )
                );
            }
            case 49:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        49
                    )
                );
            }
            case 50:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        50
                    )
                );
            }
            case 51:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        51
                    )
                );
            }
            case 52:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        52
                    )
                );
            }
            case 53:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        53
                    )
                );
            }
            case 54:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        54
                    )
                );
            }
            case 55:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        55
                    )
                );
            }
            case 56:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        56
                    )
                );
            }
            case 57:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        57
                    )
                );
            }
            case 58:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        58
                    )
                );
            }
            case 59:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        59
                    )
                );
            }
            case 60:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        60
                    )
                );
            }
            case 61:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        61
                    )
                );
            }
            case 62:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        62
                    )
                );
            }
            case 63:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        63
                    )
                );
            }
            case 64:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        64
                    )
                );
            }
            case 65:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        65
                    )
                );
            }
            case 66:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        66
                    )
                );
            }
            case 67:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        67
                    )
                );
            }
            case 68:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        68
                    )
                );
            }
            case 69:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        69
                    )
                );
            }
            case 70:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        70
                    )
                );
            }
            case 71:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        71
                    )
                );
            }
            case 72:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        72
                    )
                );
            }
            case 73:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        73
                    )
                );
            }
            case 74:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        74
                    )
                );
            }
            case 75:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        75
                    )
                );
            }
            case 76:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        76
                    )
                );
            }
            case 77:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        77
                    )
                );
            }
            case 78:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        78
                    )
                );
            }
            case 79:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        79
                    )
                );
            }
            case 80:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        80
                    )
                );
            }
            case 81:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        81
                    )
                );
            }
            case 82:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        82
                    )
                );
            }
            case 83:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        83
                    )
                );
            }
            case 84:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        84
                    )
                );
            }
            case 85:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        85
                    )
                );
            }
            case 86:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        86
                    )
                );
            }
            case 87:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        87
                    )
                );
            }
            case 88:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        88
                    )
                );
            }
            case 89:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        89
                    )
                );
            }
            case 90:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        90
                    )
                );
            }
            case 91:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        91
                    )
                );
            }
            case 92:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        92
                    )
                );
            }
            case 93:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        93
                    )
                );
            }
            case 94:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        94
                    )
                );
            }
            case 95:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        95
                    )
                );
            }
            case 96:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        96
                    )
                );
            }
            case 97:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        97
                    )
                );
            }
            case 98:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        98
                    )
                );
            }
            case 99:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        99
                    )
                );
            }
            case 100:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        100
                    )
                );
            }
            case 101:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        101
                    )
                );
            }
            case 102:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        102
                    )
                );
            }
            case 103:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        103
                    )
                );
            }
            case 104:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        104
                    )
                );
            }
            case 105:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        105
                    )
                );
            }
            case 106:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        106
                    )
                );
            }
            case 107:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        107
                    )
                );
            }
            case 108:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        108
                    )
                );
            }
            case 109:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        109
                    )
                );
            }
            case 110:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        110
                    )
                );
            }
            case 111:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        111
                    )
                );
            }
            case 112:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        112
                    )
                );
            }
            case 113:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        113
                    )
                );
            }
            case 114:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        114
                    )
                );
            }
            case 115:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        115
                    )
                );
            }
            case 116:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        116
                    )
                );
            }
            case 117:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        117
                    )
                );
            }
            case 118:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        118
                    )
                );
            }
            case 119:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        119
                    )
                );
            }
            case 120:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        120
                    )
                );
            }
            case 121:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        121
                    )
                );
            }
            case 122:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        122
                    )
                );
            }
            case 123:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        123
                    )
                );
            }
            case 124:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        124
                    )
                );
            }
            case 125:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        125
                    )
                );
            }
            case 126:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        126
                    )
                );
            }
            case 127:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        127
                    )
                );
            }
            case 128:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        128
                    )
                );
            }
            case 129:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        129
                    )
                );
            }
            case 130:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        130
                    )
                );
            }
            case 131:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        131
                    )
                );
            }
            case 132:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        132
                    )
                );
            }
            case 133:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        133
                    )
                );
            }
            case 134:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        134
                    )
                );
            }
            case 135:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        135
                    )
                );
            }
            case 136:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        136
                    )
                );
            }
            case 137:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        137
                    )
                );
            }
            case 138:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        138
                    )
                );
            }
            case 139:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        139
                    )
                );
            }
            case 140:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        140
                    )
                );
            }
            case 141:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        141
                    )
                );
            }
            case 142:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        142
                    )
                );
            }
            case 143:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        143
                    )
                );
            }
            case 144:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        144
                    )
                );
            }
            case 145:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        145
                    )
                );
            }
            case 146:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        146
                    )
                );
            }
            case 147:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        147
                    )
                );
            }
            case 148:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        148
                    )
                );
            }
            case 149:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        149
                    )
                );
            }
            case 150:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        150
                    )
                );
            }
            case 151:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        151
                    )
                );
            }
            case 152:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        152
                    )
                );
            }
            case 153:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        153
                    )
                );
            }
            case 154:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        154
                    )
                );
            }
            case 155:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        155
                    )
                );
            }
            case 156:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        156
                    )
                );
            }
            case 157:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        157
                    )
                );
            }
            case 158:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        158
                    )
                );
            }
            case 159:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        159
                    )
                );
            }
            case 160:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        160
                    )
                );
            }
            case 161:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        161
                    )
                );
            }
            case 162:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        162
                    )
                );
            }
            case 163:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        163
                    )
                );
            }
            case 164:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        164
                    )
                );
            }
            case 165:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        165
                    )
                );
            }
            case 166:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        166
                    )
                );
            }
            case 167:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        167
                    )
                );
            }
            case 168:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        168
                    )
                );
            }
            case 169:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        169
                    )
                );
            }
            case 170:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        170
                    )
                );
            }
            case 171:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        171
                    )
                );
            }
            case 172:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        172
                    )
                );
            }
            case 173:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        173
                    )
                );
            }
            case 174:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        174
                    )
                );
            }
            case 175:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        175
                    )
                );
            }
            case 176:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        176
                    )
                );
            }
            case 177:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        177
                    )
                );
            }
            case 178:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        178
                    )
                );
            }
            case 179:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        179
                    )
                );
            }
            case 180:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        180
                    )
                );
            }
            case 181:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        181
                    )
                );
            }
            case 182:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        182
                    )
                );
            }
            case 183:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        183
                    )
                );
            }
            case 184:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        184
                    )
                );
            }
            case 185:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        185
                    )
                );
            }
            case 186:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        186
                    )
                );
            }
            case 187:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        187
                    )
                );
            }
            case 188:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        188
                    )
                );
            }
            case 189:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        189
                    )
                );
            }
            case 190:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        190
                    )
                );
            }
            case 191:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        191
                    )
                );
            }
            case 192:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        192
                    )
                );
            }
            case 193:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        193
                    )
                );
            }
            case 194:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        194
                    )
                );
            }
            case 195:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        195
                    )
                );
            }
            case 196:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        196
                    )
                );
            }
            case 197:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        197
                    )
                );
            }
            case 198:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        198
                    )
                );
            }
            case 199:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        199
                    )
                );
            }
            case 200:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        200
                    )
                );
            }
            case 201:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        201
                    )
                );
            }
            case 202:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        202
                    )
                );
            }
            case 203:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        203
                    )
                );
            }
            case 204:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        204
                    )
                );
            }
            case 205:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        205
                    )
                );
            }
            case 206:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        206
                    )
                );
            }
            case 207:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        207
                    )
                );
            }
            case 208:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        208
                    )
                );
            }
            case 209:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        209
                    )
                );
            }
            case 210:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        210
                    )
                );
            }
            case 211:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        211
                    )
                );
            }
            case 212:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        212
                    )
                );
            }
            case 213:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        213
                    )
                );
            }
            case 214:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        214
                    )
                );
            }
            case 215:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        215
                    )
                );
            }
            case 216:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        216
                    )
                );
            }
            case 217:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        217
                    )
                );
            }
            case 218:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        218
                    )
                );
            }
            case 219:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        219
                    )
                );
            }
            case 220:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        220
                    )
                );
            }
            case 221:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        221
                    )
                );
            }
            case 222:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        222
                    )
                );
            }
            case 223:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        223
                    )
                );
            }
            case 224:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        224
                    )
                );
            }
            case 225:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        225
                    )
                );
            }
            case 226:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        226
                    )
                );
            }
            case 227:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        227
                    )
                );
            }
            case 228:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        228
                    )
                );
            }
            case 229:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        229
                    )
                );
            }
            case 230:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        230
                    )
                );
            }
            case 231:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        231
                    )
                );
            }
            case 232:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        232
                    )
                );
            }
            case 233:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        233
                    )
                );
            }
            case 234:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        234
                    )
                );
            }
            case 235:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        235
                    )
                );
            }
            case 236:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        236
                    )
                );
            }
            case 237:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        237
                    )
                );
            }
            case 238:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        238
                    )
                );
            }
            case 239:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        239
                    )
                );
            }
            case 240:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        240
                    )
                );
            }
            case 241:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        241
                    )
                );
            }
            case 242:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        242
                    )
                );
            }
            case 243:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        243
                    )
                );
            }
            case 244:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        244
                    )
                );
            }
            case 245:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        245
                    )
                );
            }
            case 246:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        246
                    )
                );
            }
            case 247:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        247
                    )
                );
            }
            case 248:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        248
                    )
                );
            }
            case 249:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        249
                    )
                );
            }
            case 250:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        250
                    )
                );
            }
            case 251:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        251
                    )
                );
            }
            case 252:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        252
                    )
                );
            }
            case 253:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        253
                    )
                );
            }
            case 254:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        254
                    )
                );
            }
            case 255:
            {
                return INTRINSIC_CAST(
                    __m128, TRet, _mm_insert_ps(
                        INTRINSIC_CAST(TArg1, __m128, arg1),
                        INTRINSIC_CAST(TArg2, __m128, arg2),
                        255
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_insert_AEBBD(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128, TRet, _mm_insert_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, __m128, arg2),
                TArg3Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::Blend(System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_F657F(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        15
                    )
                );
            }
            case 16:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        16
                    )
                );
            }
            case 17:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        17
                    )
                );
            }
            case 18:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        18
                    )
                );
            }
            case 19:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        19
                    )
                );
            }
            case 20:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        20
                    )
                );
            }
            case 21:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        21
                    )
                );
            }
            case 22:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        22
                    )
                );
            }
            case 23:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        23
                    )
                );
            }
            case 24:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        24
                    )
                );
            }
            case 25:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        25
                    )
                );
            }
            case 26:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        26
                    )
                );
            }
            case 27:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        27
                    )
                );
            }
            case 28:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        28
                    )
                );
            }
            case 29:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        29
                    )
                );
            }
            case 30:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        30
                    )
                );
            }
            case 31:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        31
                    )
                );
            }
            case 32:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        32
                    )
                );
            }
            case 33:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        33
                    )
                );
            }
            case 34:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        34
                    )
                );
            }
            case 35:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        35
                    )
                );
            }
            case 36:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        36
                    )
                );
            }
            case 37:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        37
                    )
                );
            }
            case 38:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        38
                    )
                );
            }
            case 39:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        39
                    )
                );
            }
            case 40:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        40
                    )
                );
            }
            case 41:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        41
                    )
                );
            }
            case 42:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        42
                    )
                );
            }
            case 43:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        43
                    )
                );
            }
            case 44:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        44
                    )
                );
            }
            case 45:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        45
                    )
                );
            }
            case 46:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        46
                    )
                );
            }
            case 47:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        47
                    )
                );
            }
            case 48:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        48
                    )
                );
            }
            case 49:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        49
                    )
                );
            }
            case 50:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        50
                    )
                );
            }
            case 51:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        51
                    )
                );
            }
            case 52:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        52
                    )
                );
            }
            case 53:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        53
                    )
                );
            }
            case 54:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        54
                    )
                );
            }
            case 55:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        55
                    )
                );
            }
            case 56:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        56
                    )
                );
            }
            case 57:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        57
                    )
                );
            }
            case 58:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        58
                    )
                );
            }
            case 59:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        59
                    )
                );
            }
            case 60:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        60
                    )
                );
            }
            case 61:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        61
                    )
                );
            }
            case 62:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        62
                    )
                );
            }
            case 63:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        63
                    )
                );
            }
            case 64:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        64
                    )
                );
            }
            case 65:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        65
                    )
                );
            }
            case 66:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        66
                    )
                );
            }
            case 67:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        67
                    )
                );
            }
            case 68:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        68
                    )
                );
            }
            case 69:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        69
                    )
                );
            }
            case 70:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        70
                    )
                );
            }
            case 71:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        71
                    )
                );
            }
            case 72:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        72
                    )
                );
            }
            case 73:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        73
                    )
                );
            }
            case 74:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        74
                    )
                );
            }
            case 75:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        75
                    )
                );
            }
            case 76:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        76
                    )
                );
            }
            case 77:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        77
                    )
                );
            }
            case 78:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        78
                    )
                );
            }
            case 79:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        79
                    )
                );
            }
            case 80:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        80
                    )
                );
            }
            case 81:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        81
                    )
                );
            }
            case 82:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        82
                    )
                );
            }
            case 83:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        83
                    )
                );
            }
            case 84:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        84
                    )
                );
            }
            case 85:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        85
                    )
                );
            }
            case 86:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        86
                    )
                );
            }
            case 87:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        87
                    )
                );
            }
            case 88:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        88
                    )
                );
            }
            case 89:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        89
                    )
                );
            }
            case 90:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        90
                    )
                );
            }
            case 91:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        91
                    )
                );
            }
            case 92:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        92
                    )
                );
            }
            case 93:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        93
                    )
                );
            }
            case 94:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        94
                    )
                );
            }
            case 95:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        95
                    )
                );
            }
            case 96:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        96
                    )
                );
            }
            case 97:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        97
                    )
                );
            }
            case 98:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        98
                    )
                );
            }
            case 99:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        99
                    )
                );
            }
            case 100:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        100
                    )
                );
            }
            case 101:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        101
                    )
                );
            }
            case 102:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        102
                    )
                );
            }
            case 103:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        103
                    )
                );
            }
            case 104:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        104
                    )
                );
            }
            case 105:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        105
                    )
                );
            }
            case 106:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        106
                    )
                );
            }
            case 107:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        107
                    )
                );
            }
            case 108:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        108
                    )
                );
            }
            case 109:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        109
                    )
                );
            }
            case 110:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        110
                    )
                );
            }
            case 111:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        111
                    )
                );
            }
            case 112:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        112
                    )
                );
            }
            case 113:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        113
                    )
                );
            }
            case 114:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        114
                    )
                );
            }
            case 115:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        115
                    )
                );
            }
            case 116:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        116
                    )
                );
            }
            case 117:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        117
                    )
                );
            }
            case 118:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        118
                    )
                );
            }
            case 119:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        119
                    )
                );
            }
            case 120:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        120
                    )
                );
            }
            case 121:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        121
                    )
                );
            }
            case 122:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        122
                    )
                );
            }
            case 123:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        123
                    )
                );
            }
            case 124:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        124
                    )
                );
            }
            case 125:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        125
                    )
                );
            }
            case 126:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        126
                    )
                );
            }
            case 127:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        127
                    )
                );
            }
            case 128:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        128
                    )
                );
            }
            case 129:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        129
                    )
                );
            }
            case 130:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        130
                    )
                );
            }
            case 131:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        131
                    )
                );
            }
            case 132:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        132
                    )
                );
            }
            case 133:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        133
                    )
                );
            }
            case 134:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        134
                    )
                );
            }
            case 135:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        135
                    )
                );
            }
            case 136:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        136
                    )
                );
            }
            case 137:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        137
                    )
                );
            }
            case 138:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        138
                    )
                );
            }
            case 139:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        139
                    )
                );
            }
            case 140:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        140
                    )
                );
            }
            case 141:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        141
                    )
                );
            }
            case 142:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        142
                    )
                );
            }
            case 143:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        143
                    )
                );
            }
            case 144:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        144
                    )
                );
            }
            case 145:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        145
                    )
                );
            }
            case 146:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        146
                    )
                );
            }
            case 147:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        147
                    )
                );
            }
            case 148:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        148
                    )
                );
            }
            case 149:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        149
                    )
                );
            }
            case 150:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        150
                    )
                );
            }
            case 151:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        151
                    )
                );
            }
            case 152:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        152
                    )
                );
            }
            case 153:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        153
                    )
                );
            }
            case 154:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        154
                    )
                );
            }
            case 155:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        155
                    )
                );
            }
            case 156:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        156
                    )
                );
            }
            case 157:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        157
                    )
                );
            }
            case 158:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        158
                    )
                );
            }
            case 159:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        159
                    )
                );
            }
            case 160:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        160
                    )
                );
            }
            case 161:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        161
                    )
                );
            }
            case 162:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        162
                    )
                );
            }
            case 163:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        163
                    )
                );
            }
            case 164:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        164
                    )
                );
            }
            case 165:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        165
                    )
                );
            }
            case 166:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        166
                    )
                );
            }
            case 167:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        167
                    )
                );
            }
            case 168:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        168
                    )
                );
            }
            case 169:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        169
                    )
                );
            }
            case 170:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        170
                    )
                );
            }
            case 171:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        171
                    )
                );
            }
            case 172:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        172
                    )
                );
            }
            case 173:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        173
                    )
                );
            }
            case 174:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        174
                    )
                );
            }
            case 175:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        175
                    )
                );
            }
            case 176:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        176
                    )
                );
            }
            case 177:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        177
                    )
                );
            }
            case 178:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        178
                    )
                );
            }
            case 179:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        179
                    )
                );
            }
            case 180:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        180
                    )
                );
            }
            case 181:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        181
                    )
                );
            }
            case 182:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        182
                    )
                );
            }
            case 183:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        183
                    )
                );
            }
            case 184:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        184
                    )
                );
            }
            case 185:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        185
                    )
                );
            }
            case 186:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        186
                    )
                );
            }
            case 187:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        187
                    )
                );
            }
            case 188:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        188
                    )
                );
            }
            case 189:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        189
                    )
                );
            }
            case 190:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        190
                    )
                );
            }
            case 191:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        191
                    )
                );
            }
            case 192:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        192
                    )
                );
            }
            case 193:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        193
                    )
                );
            }
            case 194:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        194
                    )
                );
            }
            case 195:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        195
                    )
                );
            }
            case 196:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        196
                    )
                );
            }
            case 197:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        197
                    )
                );
            }
            case 198:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        198
                    )
                );
            }
            case 199:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        199
                    )
                );
            }
            case 200:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        200
                    )
                );
            }
            case 201:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        201
                    )
                );
            }
            case 202:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        202
                    )
                );
            }
            case 203:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        203
                    )
                );
            }
            case 204:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        204
                    )
                );
            }
            case 205:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        205
                    )
                );
            }
            case 206:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        206
                    )
                );
            }
            case 207:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        207
                    )
                );
            }
            case 208:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        208
                    )
                );
            }
            case 209:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        209
                    )
                );
            }
            case 210:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        210
                    )
                );
            }
            case 211:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        211
                    )
                );
            }
            case 212:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        212
                    )
                );
            }
            case 213:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        213
                    )
                );
            }
            case 214:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        214
                    )
                );
            }
            case 215:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        215
                    )
                );
            }
            case 216:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        216
                    )
                );
            }
            case 217:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        217
                    )
                );
            }
            case 218:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        218
                    )
                );
            }
            case 219:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        219
                    )
                );
            }
            case 220:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        220
                    )
                );
            }
            case 221:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        221
                    )
                );
            }
            case 222:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        222
                    )
                );
            }
            case 223:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        223
                    )
                );
            }
            case 224:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        224
                    )
                );
            }
            case 225:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        225
                    )
                );
            }
            case 226:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        226
                    )
                );
            }
            case 227:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        227
                    )
                );
            }
            case 228:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        228
                    )
                );
            }
            case 229:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        229
                    )
                );
            }
            case 230:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        230
                    )
                );
            }
            case 231:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        231
                    )
                );
            }
            case 232:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        232
                    )
                );
            }
            case 233:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        233
                    )
                );
            }
            case 234:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        234
                    )
                );
            }
            case 235:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        235
                    )
                );
            }
            case 236:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        236
                    )
                );
            }
            case 237:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        237
                    )
                );
            }
            case 238:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        238
                    )
                );
            }
            case 239:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        239
                    )
                );
            }
            case 240:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        240
                    )
                );
            }
            case 241:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        241
                    )
                );
            }
            case 242:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        242
                    )
                );
            }
            case 243:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        243
                    )
                );
            }
            case 244:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        244
                    )
                );
            }
            case 245:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        245
                    )
                );
            }
            case 246:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        246
                    )
                );
            }
            case 247:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        247
                    )
                );
            }
            case 248:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        248
                    )
                );
            }
            case 249:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        249
                    )
                );
            }
            case 250:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        250
                    )
                );
            }
            case 251:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        251
                    )
                );
            }
            case 252:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        252
                    )
                );
            }
            case 253:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        253
                    )
                );
            }
            case 254:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        254
                    )
                );
            }
            case 255:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_blend_epi16(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        255
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_blend_F657F(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blend_epi16(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                TArg3Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_9C376(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.UInt16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_FA329(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::Max(System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_max_899B1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_max_epu16(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::Min(System.Runtime.Intrinsics.Vector128`1<System.UInt16>,System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_min_899B1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_min_epu16(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::MinHorizontal(System.Runtime.Intrinsics.Vector128`1<System.UInt16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_min_horizontal(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_minpos_epu16(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::MultipleSumAbsoluteDifferences(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_multiple_sum_absolute_differences(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        switch (arg3)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        7
                    )
                );
            }
            case 8:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        8
                    )
                );
            }
            case 9:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        9
                    )
                );
            }
            case 10:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        10
                    )
                );
            }
            case 11:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        11
                    )
                );
            }
            case 12:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        12
                    )
                );
            }
            case 13:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        13
                    )
                );
            }
            case 14:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        14
                    )
                );
            }
            case 15:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        15
                    )
                );
            }
            case 16:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        16
                    )
                );
            }
            case 17:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        17
                    )
                );
            }
            case 18:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        18
                    )
                );
            }
            case 19:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        19
                    )
                );
            }
            case 20:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        20
                    )
                );
            }
            case 21:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        21
                    )
                );
            }
            case 22:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        22
                    )
                );
            }
            case 23:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        23
                    )
                );
            }
            case 24:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        24
                    )
                );
            }
            case 25:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        25
                    )
                );
            }
            case 26:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        26
                    )
                );
            }
            case 27:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        27
                    )
                );
            }
            case 28:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        28
                    )
                );
            }
            case 29:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        29
                    )
                );
            }
            case 30:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        30
                    )
                );
            }
            case 31:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        31
                    )
                );
            }
            case 32:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        32
                    )
                );
            }
            case 33:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        33
                    )
                );
            }
            case 34:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        34
                    )
                );
            }
            case 35:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        35
                    )
                );
            }
            case 36:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        36
                    )
                );
            }
            case 37:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        37
                    )
                );
            }
            case 38:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        38
                    )
                );
            }
            case 39:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        39
                    )
                );
            }
            case 40:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        40
                    )
                );
            }
            case 41:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        41
                    )
                );
            }
            case 42:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        42
                    )
                );
            }
            case 43:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        43
                    )
                );
            }
            case 44:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        44
                    )
                );
            }
            case 45:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        45
                    )
                );
            }
            case 46:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        46
                    )
                );
            }
            case 47:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        47
                    )
                );
            }
            case 48:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        48
                    )
                );
            }
            case 49:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        49
                    )
                );
            }
            case 50:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        50
                    )
                );
            }
            case 51:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        51
                    )
                );
            }
            case 52:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        52
                    )
                );
            }
            case 53:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        53
                    )
                );
            }
            case 54:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        54
                    )
                );
            }
            case 55:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        55
                    )
                );
            }
            case 56:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        56
                    )
                );
            }
            case 57:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        57
                    )
                );
            }
            case 58:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        58
                    )
                );
            }
            case 59:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        59
                    )
                );
            }
            case 60:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        60
                    )
                );
            }
            case 61:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        61
                    )
                );
            }
            case 62:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        62
                    )
                );
            }
            case 63:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        63
                    )
                );
            }
            case 64:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        64
                    )
                );
            }
            case 65:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        65
                    )
                );
            }
            case 66:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        66
                    )
                );
            }
            case 67:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        67
                    )
                );
            }
            case 68:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        68
                    )
                );
            }
            case 69:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        69
                    )
                );
            }
            case 70:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        70
                    )
                );
            }
            case 71:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        71
                    )
                );
            }
            case 72:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        72
                    )
                );
            }
            case 73:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        73
                    )
                );
            }
            case 74:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        74
                    )
                );
            }
            case 75:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        75
                    )
                );
            }
            case 76:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        76
                    )
                );
            }
            case 77:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        77
                    )
                );
            }
            case 78:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        78
                    )
                );
            }
            case 79:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        79
                    )
                );
            }
            case 80:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        80
                    )
                );
            }
            case 81:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        81
                    )
                );
            }
            case 82:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        82
                    )
                );
            }
            case 83:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        83
                    )
                );
            }
            case 84:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        84
                    )
                );
            }
            case 85:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        85
                    )
                );
            }
            case 86:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        86
                    )
                );
            }
            case 87:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        87
                    )
                );
            }
            case 88:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        88
                    )
                );
            }
            case 89:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        89
                    )
                );
            }
            case 90:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        90
                    )
                );
            }
            case 91:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        91
                    )
                );
            }
            case 92:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        92
                    )
                );
            }
            case 93:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        93
                    )
                );
            }
            case 94:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        94
                    )
                );
            }
            case 95:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        95
                    )
                );
            }
            case 96:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        96
                    )
                );
            }
            case 97:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        97
                    )
                );
            }
            case 98:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        98
                    )
                );
            }
            case 99:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        99
                    )
                );
            }
            case 100:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        100
                    )
                );
            }
            case 101:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        101
                    )
                );
            }
            case 102:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        102
                    )
                );
            }
            case 103:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        103
                    )
                );
            }
            case 104:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        104
                    )
                );
            }
            case 105:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        105
                    )
                );
            }
            case 106:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        106
                    )
                );
            }
            case 107:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        107
                    )
                );
            }
            case 108:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        108
                    )
                );
            }
            case 109:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        109
                    )
                );
            }
            case 110:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        110
                    )
                );
            }
            case 111:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        111
                    )
                );
            }
            case 112:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        112
                    )
                );
            }
            case 113:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        113
                    )
                );
            }
            case 114:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        114
                    )
                );
            }
            case 115:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        115
                    )
                );
            }
            case 116:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        116
                    )
                );
            }
            case 117:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        117
                    )
                );
            }
            case 118:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        118
                    )
                );
            }
            case 119:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        119
                    )
                );
            }
            case 120:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        120
                    )
                );
            }
            case 121:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        121
                    )
                );
            }
            case 122:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        122
                    )
                );
            }
            case 123:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        123
                    )
                );
            }
            case 124:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        124
                    )
                );
            }
            case 125:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        125
                    )
                );
            }
            case 126:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        126
                    )
                );
            }
            case 127:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        127
                    )
                );
            }
            case 128:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        128
                    )
                );
            }
            case 129:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        129
                    )
                );
            }
            case 130:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        130
                    )
                );
            }
            case 131:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        131
                    )
                );
            }
            case 132:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        132
                    )
                );
            }
            case 133:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        133
                    )
                );
            }
            case 134:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        134
                    )
                );
            }
            case 135:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        135
                    )
                );
            }
            case 136:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        136
                    )
                );
            }
            case 137:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        137
                    )
                );
            }
            case 138:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        138
                    )
                );
            }
            case 139:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        139
                    )
                );
            }
            case 140:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        140
                    )
                );
            }
            case 141:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        141
                    )
                );
            }
            case 142:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        142
                    )
                );
            }
            case 143:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        143
                    )
                );
            }
            case 144:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        144
                    )
                );
            }
            case 145:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        145
                    )
                );
            }
            case 146:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        146
                    )
                );
            }
            case 147:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        147
                    )
                );
            }
            case 148:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        148
                    )
                );
            }
            case 149:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        149
                    )
                );
            }
            case 150:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        150
                    )
                );
            }
            case 151:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        151
                    )
                );
            }
            case 152:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        152
                    )
                );
            }
            case 153:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        153
                    )
                );
            }
            case 154:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        154
                    )
                );
            }
            case 155:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        155
                    )
                );
            }
            case 156:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        156
                    )
                );
            }
            case 157:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        157
                    )
                );
            }
            case 158:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        158
                    )
                );
            }
            case 159:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        159
                    )
                );
            }
            case 160:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        160
                    )
                );
            }
            case 161:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        161
                    )
                );
            }
            case 162:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        162
                    )
                );
            }
            case 163:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        163
                    )
                );
            }
            case 164:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        164
                    )
                );
            }
            case 165:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        165
                    )
                );
            }
            case 166:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        166
                    )
                );
            }
            case 167:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        167
                    )
                );
            }
            case 168:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        168
                    )
                );
            }
            case 169:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        169
                    )
                );
            }
            case 170:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        170
                    )
                );
            }
            case 171:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        171
                    )
                );
            }
            case 172:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        172
                    )
                );
            }
            case 173:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        173
                    )
                );
            }
            case 174:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        174
                    )
                );
            }
            case 175:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        175
                    )
                );
            }
            case 176:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        176
                    )
                );
            }
            case 177:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        177
                    )
                );
            }
            case 178:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        178
                    )
                );
            }
            case 179:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        179
                    )
                );
            }
            case 180:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        180
                    )
                );
            }
            case 181:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        181
                    )
                );
            }
            case 182:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        182
                    )
                );
            }
            case 183:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        183
                    )
                );
            }
            case 184:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        184
                    )
                );
            }
            case 185:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        185
                    )
                );
            }
            case 186:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        186
                    )
                );
            }
            case 187:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        187
                    )
                );
            }
            case 188:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        188
                    )
                );
            }
            case 189:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        189
                    )
                );
            }
            case 190:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        190
                    )
                );
            }
            case 191:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        191
                    )
                );
            }
            case 192:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        192
                    )
                );
            }
            case 193:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        193
                    )
                );
            }
            case 194:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        194
                    )
                );
            }
            case 195:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        195
                    )
                );
            }
            case 196:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        196
                    )
                );
            }
            case 197:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        197
                    )
                );
            }
            case 198:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        198
                    )
                );
            }
            case 199:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        199
                    )
                );
            }
            case 200:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        200
                    )
                );
            }
            case 201:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        201
                    )
                );
            }
            case 202:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        202
                    )
                );
            }
            case 203:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        203
                    )
                );
            }
            case 204:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        204
                    )
                );
            }
            case 205:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        205
                    )
                );
            }
            case 206:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        206
                    )
                );
            }
            case 207:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        207
                    )
                );
            }
            case 208:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        208
                    )
                );
            }
            case 209:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        209
                    )
                );
            }
            case 210:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        210
                    )
                );
            }
            case 211:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        211
                    )
                );
            }
            case 212:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        212
                    )
                );
            }
            case 213:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        213
                    )
                );
            }
            case 214:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        214
                    )
                );
            }
            case 215:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        215
                    )
                );
            }
            case 216:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        216
                    )
                );
            }
            case 217:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        217
                    )
                );
            }
            case 218:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        218
                    )
                );
            }
            case 219:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        219
                    )
                );
            }
            case 220:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        220
                    )
                );
            }
            case 221:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        221
                    )
                );
            }
            case 222:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        222
                    )
                );
            }
            case 223:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        223
                    )
                );
            }
            case 224:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        224
                    )
                );
            }
            case 225:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        225
                    )
                );
            }
            case 226:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        226
                    )
                );
            }
            case 227:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        227
                    )
                );
            }
            case 228:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        228
                    )
                );
            }
            case 229:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        229
                    )
                );
            }
            case 230:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        230
                    )
                );
            }
            case 231:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        231
                    )
                );
            }
            case 232:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        232
                    )
                );
            }
            case 233:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        233
                    )
                );
            }
            case 234:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        234
                    )
                );
            }
            case 235:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        235
                    )
                );
            }
            case 236:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        236
                    )
                );
            }
            case 237:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        237
                    )
                );
            }
            case 238:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        238
                    )
                );
            }
            case 239:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        239
                    )
                );
            }
            case 240:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        240
                    )
                );
            }
            case 241:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        241
                    )
                );
            }
            case 242:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        242
                    )
                );
            }
            case 243:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        243
                    )
                );
            }
            case 244:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        244
                    )
                );
            }
            case 245:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        245
                    )
                );
            }
            case 246:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        246
                    )
                );
            }
            case 247:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        247
                    )
                );
            }
            case 248:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        248
                    )
                );
            }
            case 249:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        249
                    )
                );
            }
            case 250:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        250
                    )
                );
            }
            case 251:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        251
                    )
                );
            }
            case 252:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        252
                    )
                );
            }
            case 253:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        253
                    )
                );
            }
            case 254:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        254
                    )
                );
            }
            case 255:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_mpsadbw_epu8(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, __m128i, arg2),
                        255
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, int TArg3Value>
    inline TRet il2cpp_intrinsic_sse41_multiple_sum_absolute_differences(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            __m128i, TRet, _mm_mpsadbw_epu8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                TArg3Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse41::PackUnsignedSaturate(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_pack_unsigned_saturate(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_packus_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_AE6FA(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.UInt32*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_BE5D7(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.X86.Sse41::Max(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_max_A1D32(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_max_epu32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.X86.Sse41::Min(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_min_A1D32(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_min_epu32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.X86.Sse41::MultiplyLow(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_multiply_low_A1D32(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_mullo_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.X86.Sse41::BlendVariable(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sse41_blend_variable_3C446(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_blendv_epi8(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2),
                INTRINSIC_CAST(TArg3, __m128i, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.X86.Sse41::CompareEqual(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse41_compare_equal_638EB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cmpeq_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.X86.Sse41::LoadAlignedVector128NonTemporal(System.UInt64*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse41_load_aligned_vector128_non_temporal_F87C4(TArg1 arg1)
    {
#if IL2CPP_SSE41_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_stream_load_si128(
                INTRINSIC_CAST(TArg1, const __m128i*, arg1)
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
