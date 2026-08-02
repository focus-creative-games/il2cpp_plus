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
namespace Sse
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
#if IL2CPP_SSE_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.X86.Sse/X64::ConvertToInt64(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_to_int64(TArg1 arg1)
    {
#if IL2CPP_SSE_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_cvtss_si64(
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.X86.Sse/X64::ConvertToInt64WithTruncation(System.Runtime.Intrinsics.Vector128`1<System.Single>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_convert_to_int64_with_truncation(TArg1 arg1)
    {
#if IL2CPP_SSE_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_cvttss_si64(
                INTRINSIC_CAST(TArg1, __m128, arg1)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Single> System.Runtime.Intrinsics.X86.Sse/X64::ConvertScalarToVector128Single(System.Runtime.Intrinsics.Vector128`1<System.Single>,System.Int64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_convert_scalar_to_vector128_single(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128, TRet, _mm_cvtsi64_ss(
                INTRINSIC_CAST(TArg1, __m128, arg1),
                INTRINSIC_CAST(TArg2, int64_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Sse
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
