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
        Method: System.Boolean System.Runtime.Intrinsics.X86.Aes::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_aes_get_is_supported()
    {
#ifdef IL2CPP_AES_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Aes::Decrypt(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_decrypt(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_AES_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128i, TRet, _mm_aesdec_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1),
            INTRINSIC_CAST(TArg2, __m128i, arg2)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Aes::DecryptLast(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_decrypt_last(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_AES_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128i, TRet, _mm_aesdeclast_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1),
            INTRINSIC_CAST(TArg2, __m128i, arg2)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Aes::Encrypt(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_encrypt(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_AES_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128i, TRet, _mm_aesenc_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1),
            INTRINSIC_CAST(TArg2, __m128i, arg2)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Aes::EncryptLast(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_encrypt_last(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_AES_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128i, TRet, _mm_aesenclast_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1),
            INTRINSIC_CAST(TArg2, __m128i, arg2)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Aes::InverseMixColumns(System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_aes_inverse_mix_columns(TArg1 arg1)
    {
#if IL2CPP_AES_IS_SUPPORTED
    return INTRINSIC_CAST(
        __m128i, TRet, _mm_aesimc_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Byte> System.Runtime.Intrinsics.X86.Aes::KeygenAssist(System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [1]
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_aes_keygen_assist(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_AES_IS_SUPPORTED
    switch(arg2)
    {
        case 0:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    0
                )
            );
        }
        case 1:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    1
                )
            );
        }
        case 2:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    2
                )
            );
        }
        case 3:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    3
                )
            );
        }
        case 4:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    4
                )
            );
        }
        case 5:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    5
                )
            );
        }
        case 6:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    6
                )
            );
        }
        case 7:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    7
                )
            );
        }
        case 8:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    8
                )
            );
        }
        case 9:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    9
                )
            );
        }
        case 10:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    10
                )
            );
        }
        case 11:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    11
                )
            );
        }
        case 12:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    12
                )
            );
        }
        case 13:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    13
                )
            );
        }
        case 14:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    14
                )
            );
        }
        case 15:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    15
                )
            );
        }
        case 16:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    16
                )
            );
        }
        case 17:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    17
                )
            );
        }
        case 18:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    18
                )
            );
        }
        case 19:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    19
                )
            );
        }
        case 20:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    20
                )
            );
        }
        case 21:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    21
                )
            );
        }
        case 22:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    22
                )
            );
        }
        case 23:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    23
                )
            );
        }
        case 24:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    24
                )
            );
        }
        case 25:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    25
                )
            );
        }
        case 26:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    26
                )
            );
        }
        case 27:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    27
                )
            );
        }
        case 28:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    28
                )
            );
        }
        case 29:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    29
                )
            );
        }
        case 30:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    30
                )
            );
        }
        case 31:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    31
                )
            );
        }
        case 32:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    32
                )
            );
        }
        case 33:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    33
                )
            );
        }
        case 34:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    34
                )
            );
        }
        case 35:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    35
                )
            );
        }
        case 36:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    36
                )
            );
        }
        case 37:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    37
                )
            );
        }
        case 38:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    38
                )
            );
        }
        case 39:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    39
                )
            );
        }
        case 40:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    40
                )
            );
        }
        case 41:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    41
                )
            );
        }
        case 42:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    42
                )
            );
        }
        case 43:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    43
                )
            );
        }
        case 44:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    44
                )
            );
        }
        case 45:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    45
                )
            );
        }
        case 46:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    46
                )
            );
        }
        case 47:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    47
                )
            );
        }
        case 48:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    48
                )
            );
        }
        case 49:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    49
                )
            );
        }
        case 50:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    50
                )
            );
        }
        case 51:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    51
                )
            );
        }
        case 52:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    52
                )
            );
        }
        case 53:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    53
                )
            );
        }
        case 54:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    54
                )
            );
        }
        case 55:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    55
                )
            );
        }
        case 56:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    56
                )
            );
        }
        case 57:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    57
                )
            );
        }
        case 58:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    58
                )
            );
        }
        case 59:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    59
                )
            );
        }
        case 60:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    60
                )
            );
        }
        case 61:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    61
                )
            );
        }
        case 62:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    62
                )
            );
        }
        case 63:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    63
                )
            );
        }
        case 64:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    64
                )
            );
        }
        case 65:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    65
                )
            );
        }
        case 66:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    66
                )
            );
        }
        case 67:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    67
                )
            );
        }
        case 68:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    68
                )
            );
        }
        case 69:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    69
                )
            );
        }
        case 70:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    70
                )
            );
        }
        case 71:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    71
                )
            );
        }
        case 72:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    72
                )
            );
        }
        case 73:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    73
                )
            );
        }
        case 74:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    74
                )
            );
        }
        case 75:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    75
                )
            );
        }
        case 76:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    76
                )
            );
        }
        case 77:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    77
                )
            );
        }
        case 78:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    78
                )
            );
        }
        case 79:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    79
                )
            );
        }
        case 80:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    80
                )
            );
        }
        case 81:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    81
                )
            );
        }
        case 82:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    82
                )
            );
        }
        case 83:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    83
                )
            );
        }
        case 84:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    84
                )
            );
        }
        case 85:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    85
                )
            );
        }
        case 86:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    86
                )
            );
        }
        case 87:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    87
                )
            );
        }
        case 88:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    88
                )
            );
        }
        case 89:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    89
                )
            );
        }
        case 90:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    90
                )
            );
        }
        case 91:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    91
                )
            );
        }
        case 92:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    92
                )
            );
        }
        case 93:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    93
                )
            );
        }
        case 94:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    94
                )
            );
        }
        case 95:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    95
                )
            );
        }
        case 96:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    96
                )
            );
        }
        case 97:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    97
                )
            );
        }
        case 98:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    98
                )
            );
        }
        case 99:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    99
                )
            );
        }
        case 100:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    100
                )
            );
        }
        case 101:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    101
                )
            );
        }
        case 102:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    102
                )
            );
        }
        case 103:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    103
                )
            );
        }
        case 104:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    104
                )
            );
        }
        case 105:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    105
                )
            );
        }
        case 106:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    106
                )
            );
        }
        case 107:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    107
                )
            );
        }
        case 108:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    108
                )
            );
        }
        case 109:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    109
                )
            );
        }
        case 110:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    110
                )
            );
        }
        case 111:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    111
                )
            );
        }
        case 112:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    112
                )
            );
        }
        case 113:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    113
                )
            );
        }
        case 114:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    114
                )
            );
        }
        case 115:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    115
                )
            );
        }
        case 116:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    116
                )
            );
        }
        case 117:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    117
                )
            );
        }
        case 118:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    118
                )
            );
        }
        case 119:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    119
                )
            );
        }
        case 120:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    120
                )
            );
        }
        case 121:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    121
                )
            );
        }
        case 122:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    122
                )
            );
        }
        case 123:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    123
                )
            );
        }
        case 124:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    124
                )
            );
        }
        case 125:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    125
                )
            );
        }
        case 126:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    126
                )
            );
        }
        case 127:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    127
                )
            );
        }
        case 128:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    128
                )
            );
        }
        case 129:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    129
                )
            );
        }
        case 130:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    130
                )
            );
        }
        case 131:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    131
                )
            );
        }
        case 132:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    132
                )
            );
        }
        case 133:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    133
                )
            );
        }
        case 134:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    134
                )
            );
        }
        case 135:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    135
                )
            );
        }
        case 136:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    136
                )
            );
        }
        case 137:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    137
                )
            );
        }
        case 138:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    138
                )
            );
        }
        case 139:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    139
                )
            );
        }
        case 140:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    140
                )
            );
        }
        case 141:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    141
                )
            );
        }
        case 142:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    142
                )
            );
        }
        case 143:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    143
                )
            );
        }
        case 144:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    144
                )
            );
        }
        case 145:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    145
                )
            );
        }
        case 146:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    146
                )
            );
        }
        case 147:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    147
                )
            );
        }
        case 148:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    148
                )
            );
        }
        case 149:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    149
                )
            );
        }
        case 150:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    150
                )
            );
        }
        case 151:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    151
                )
            );
        }
        case 152:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    152
                )
            );
        }
        case 153:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    153
                )
            );
        }
        case 154:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    154
                )
            );
        }
        case 155:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    155
                )
            );
        }
        case 156:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    156
                )
            );
        }
        case 157:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    157
                )
            );
        }
        case 158:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    158
                )
            );
        }
        case 159:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    159
                )
            );
        }
        case 160:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    160
                )
            );
        }
        case 161:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    161
                )
            );
        }
        case 162:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    162
                )
            );
        }
        case 163:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    163
                )
            );
        }
        case 164:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    164
                )
            );
        }
        case 165:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    165
                )
            );
        }
        case 166:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    166
                )
            );
        }
        case 167:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    167
                )
            );
        }
        case 168:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    168
                )
            );
        }
        case 169:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    169
                )
            );
        }
        case 170:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    170
                )
            );
        }
        case 171:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    171
                )
            );
        }
        case 172:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    172
                )
            );
        }
        case 173:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    173
                )
            );
        }
        case 174:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    174
                )
            );
        }
        case 175:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    175
                )
            );
        }
        case 176:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    176
                )
            );
        }
        case 177:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    177
                )
            );
        }
        case 178:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    178
                )
            );
        }
        case 179:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    179
                )
            );
        }
        case 180:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    180
                )
            );
        }
        case 181:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    181
                )
            );
        }
        case 182:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    182
                )
            );
        }
        case 183:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    183
                )
            );
        }
        case 184:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    184
                )
            );
        }
        case 185:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    185
                )
            );
        }
        case 186:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    186
                )
            );
        }
        case 187:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    187
                )
            );
        }
        case 188:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    188
                )
            );
        }
        case 189:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    189
                )
            );
        }
        case 190:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    190
                )
            );
        }
        case 191:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    191
                )
            );
        }
        case 192:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    192
                )
            );
        }
        case 193:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    193
                )
            );
        }
        case 194:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    194
                )
            );
        }
        case 195:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    195
                )
            );
        }
        case 196:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    196
                )
            );
        }
        case 197:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    197
                )
            );
        }
        case 198:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    198
                )
            );
        }
        case 199:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    199
                )
            );
        }
        case 200:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    200
                )
            );
        }
        case 201:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    201
                )
            );
        }
        case 202:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    202
                )
            );
        }
        case 203:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    203
                )
            );
        }
        case 204:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    204
                )
            );
        }
        case 205:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    205
                )
            );
        }
        case 206:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    206
                )
            );
        }
        case 207:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    207
                )
            );
        }
        case 208:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    208
                )
            );
        }
        case 209:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    209
                )
            );
        }
        case 210:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    210
                )
            );
        }
        case 211:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    211
                )
            );
        }
        case 212:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    212
                )
            );
        }
        case 213:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    213
                )
            );
        }
        case 214:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    214
                )
            );
        }
        case 215:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    215
                )
            );
        }
        case 216:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    216
                )
            );
        }
        case 217:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    217
                )
            );
        }
        case 218:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    218
                )
            );
        }
        case 219:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    219
                )
            );
        }
        case 220:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    220
                )
            );
        }
        case 221:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    221
                )
            );
        }
        case 222:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    222
                )
            );
        }
        case 223:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    223
                )
            );
        }
        case 224:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    224
                )
            );
        }
        case 225:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    225
                )
            );
        }
        case 226:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    226
                )
            );
        }
        case 227:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    227
                )
            );
        }
        case 228:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    228
                )
            );
        }
        case 229:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    229
                )
            );
        }
        case 230:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    230
                )
            );
        }
        case 231:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    231
                )
            );
        }
        case 232:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    232
                )
            );
        }
        case 233:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    233
                )
            );
        }
        case 234:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    234
                )
            );
        }
        case 235:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    235
                )
            );
        }
        case 236:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    236
                )
            );
        }
        case 237:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    237
                )
            );
        }
        case 238:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    238
                )
            );
        }
        case 239:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    239
                )
            );
        }
        case 240:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    240
                )
            );
        }
        case 241:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    241
                )
            );
        }
        case 242:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    242
                )
            );
        }
        case 243:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    243
                )
            );
        }
        case 244:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    244
                )
            );
        }
        case 245:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    245
                )
            );
        }
        case 246:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    246
                )
            );
        }
        case 247:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    247
                )
            );
        }
        case 248:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    248
                )
            );
        }
        case 249:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    249
                )
            );
        }
        case 250:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    250
                )
            );
        }
        case 251:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    251
                )
            );
        }
        case 252:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    252
                )
            );
        }
        case 253:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    253
                )
            );
        }
        case 254:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    254
                )
            );
        }
        case 255:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_aeskeygenassist_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
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
    template<typename TRet, typename TArg1, typename TArg2, int TArg2Value>
    inline TRet il2cpp_intrinsic_aes_keygen_assist(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_AES_IS_SUPPORTED
    if (TArg2Value < 0 || TArg2Value > 255)
        il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

    return INTRINSIC_CAST(
        __m128i, TRet, _mm_aeskeygenassist_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1),
            TArg2Value
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
