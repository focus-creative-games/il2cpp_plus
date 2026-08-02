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
namespace Sse41
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse41/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Int64 System.Runtime.Intrinsics.X86.Sse41/X64::Extract(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [1]
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_extract_C8D87(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        // HAND EDITED:  Only care about the bottom bit.
        switch (arg2 & 0x1)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int64_t, TRet, _mm_extract_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int64_t, TRet, _mm_extract_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        1
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
    inline TRet il2cpp_intrinsic__x64_extract_C8D87(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        if (TArg2Value < 0 || TArg2Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        // HAND EDITED:  Only care about the bottom bit.
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_extract_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                TArg2Value & 0x1
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Sse41/X64::Insert(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Int64,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x64_insert_92D9D(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        // HAND EDITED:  Only care about the bottom bit.
        switch (arg3 & 0x1)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int64_t, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int64_t, arg2),
                        1
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
    inline TRet il2cpp_intrinsic__x64_insert_92D9D(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
        // HAND EDITED:  Only care about the bottom bit.
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_insert_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, int64_t, arg2),
                TArg3Value & 0x1
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.X86.Sse41/X64::Insert(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.UInt64,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x64_insert_0627A(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        // HAND EDITED:  Only care about the bottom bit.
        switch (arg3 & 0x1)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int64_t, arg2),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    __m128i, TRet, _mm_insert_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        INTRINSIC_CAST(TArg2, int64_t, arg2),
                        1
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
    inline TRet il2cpp_intrinsic__x64_insert_0627A(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        if (TArg3Value < 0 || TArg3Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        // HAND EDITED:  Only care about the bottom bit.
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_insert_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, int64_t, arg2),
                TArg3Value & 0x1
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Sse41/X64::Extract(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [1]
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_extract_05C33(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        // HAND EDITED:  Only care about the bottom bit.
        switch (arg2 & 0x1)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int64_t, TRet, _mm_extract_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int64_t, TRet, _mm_extract_epi64(
                        INTRINSIC_CAST(TArg1, __m128i, arg1),
                        1
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
    inline TRet il2cpp_intrinsic__x64_extract_05C33(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE41_X64_IS_SUPPORTED
        if (TArg2Value < 0 || TArg2Value > 255)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        // HAND EDITED:  Only care about the bottom bit.
        return INTRINSIC_CAST(
            int64_t, TRet, _mm_extract_epi64(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                TArg2Value & 0x1
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Sse41
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
