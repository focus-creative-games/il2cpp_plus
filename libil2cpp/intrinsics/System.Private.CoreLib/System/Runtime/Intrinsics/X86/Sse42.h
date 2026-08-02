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
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse42::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_sse42_get_is_supported()
    {
#if IL2CPP_SSE42_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse42::CompareGreaterThan(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse42_compare_greater_than(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE42_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_cmpgt_epi64(
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
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Sse42::Crc32(System.UInt32,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse42_crc32_669B5(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE42_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _mm_crc32_u8(
                INTRINSIC_CAST(TArg1, unsigned int, arg1),
                INTRINSIC_CAST(TArg2, unsigned char, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Sse42::Crc32(System.UInt32,System.UInt16)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse42_crc32_A0386(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE42_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _mm_crc32_u16(
                INTRINSIC_CAST(TArg1, unsigned int, arg1),
                INTRINSIC_CAST(TArg2, unsigned short, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Sse42::Crc32(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sse42_crc32_022FE(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE42_IS_SUPPORTED
        return INTRINSIC_CAST(
            unsigned int, TRet, _mm_crc32_u32(
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
