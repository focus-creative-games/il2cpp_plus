#pragma once
#include "il2cpp-config.h"

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
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse3::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_sse3_get_is_supported()
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.Byte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_7E353(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse3::AddSubtract(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse3_add_subtract_EDABB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_addsub_pd(
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
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse3::HorizontalAdd(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse3_horizontal_add_EDABB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_hadd_pd(
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
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse3::HorizontalSubtract(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse3_horizontal_subtract_EDABB(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_hsub_pd(
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
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse3::LoadAndDuplicateToVector128(System.Double*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_and_duplicate_to_vector128(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_loaddup_pd(
                INTRINSIC_CAST(TArg1, double const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse3::MoveAndDuplicate(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_move_and_duplicate(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_movedup_pd(
                INTRINSIC_CAST(TArg1, __m128d, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.Int16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_2CA79(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.Int32*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_BD4B5(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.Int64*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_5325A(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.SByte> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.SByte*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_5399E(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse3::AddSubtract(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse3_add_subtract_A51C1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_addsub_ps(
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
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse3::HorizontalAdd(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse3_horizontal_add_A51C1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_hadd_ps(
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
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse3::HorizontalSubtract(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse3_horizontal_subtract_A51C1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_hsub_ps(
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
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse3::MoveHighAndDuplicate(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_move_high_and_duplicate(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_movehdup_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse3::MoveLowAndDuplicate(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_move_low_and_duplicate(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_moveldup_ps(
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt16> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.UInt16*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_FA329(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.UInt32*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_BE5D7(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.X86.Sse3::LoadDquVector128(System.UInt64*)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sse3_load_dqu_vector128_F87C4(TArg1 arg1)
    {
#if IL2CPP_SSE3_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_lddqu_si128(
                INTRINSIC_CAST(TArg1, __m128i const*, arg1)
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
