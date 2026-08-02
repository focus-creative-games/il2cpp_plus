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
namespace Sse2
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse2/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
        // HAND EDITED: Added implementation
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.Intrinsics.X86.Sse2/X64::StoreNonTemporal(System.Int64*,System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic__x64_store_non_temporal(int64_t* address, int64_t value)
    {
        // HAND EDITED: Added implementation
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        _mm_stream_si64(
            INTRINSIC_CAST(int64_t*, long long*, address),
            value
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
#endif
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.Intrinsics.X86.Sse2/X64::StoreNonTemporal(System.UInt64*,System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic__x64_store_non_temporal(uint64_t* address, uint64_t value)
    {
        // HAND EDITED: Added implementation
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        _mm_stream_si64(
            INTRINSIC_CAST(uint64_t*, long long*, address),
            INTRINSIC_CAST(uint64_t, int64_t, value)
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.X86.Sse2/X64::ConvertToInt64(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_to_int64_593F6(TArg1 arg1)
    {
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_cvtsd_si64(
                INTRINSIC_CAST(TArg1, __m128d, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.X86.Sse2/X64::ConvertToInt64(System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_to_int64_55B13(TArg1 arg1)
    {
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_cvtsi128_si64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.X86.Sse2/X64::ConvertToInt64WithTruncation(System.Runtime.Intrinsics.Vector128`1<System.Double>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_to_int64_with_truncation(TArg1 arg1)
    {
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_cvttsd_si64(
                INTRINSIC_CAST(TArg1, __m128d, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Double> System.Runtime.Intrinsics.X86.Sse2/X64::ConvertScalarToVector128Double(System.Runtime.Intrinsics.Vector128`1<System.Double>,System.Int64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_convert_scalar_to_vector128_double(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128d, TRet, _mm_cvtsi64_sd(
                INTRINSIC_CAST(TArg1, __m128d, arg1),
                INTRINSIC_CAST(TArg2, int64_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse2/X64::ConvertScalarToVector128Int64(System.Int64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_scalar_to_vector128_int64(TArg1 arg1)
    {
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtsi64_si128(
                INTRINSIC_CAST(TArg1, int64_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.X86.Sse2/X64::ConvertScalarToVector128UInt64(System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_scalar_to_vector128_u_int64(TArg1 arg1)
    {
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cvtsi64_si128(
                INTRINSIC_CAST(TArg1, int64_t, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Sse2/X64::ConvertToUInt64(System.Runtime.Intrinsics.Vector128`1<System.UInt64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_to_u_int64(TArg1 arg1)
    {
#if IL2CPP_SSE2_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_cvtsi128_si64(
                INTRINSIC_CAST(TArg1, __m128i, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Sse2
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
