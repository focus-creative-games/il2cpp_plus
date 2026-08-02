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
        Method: System.Boolean System.Runtime.Intrinsics.X86.Pclmulqdq::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_pclmulqdq_get_is_supported()
    {
#ifdef IL2CPP_PCLMULQDQ_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int64> System.Runtime.Intrinsics.X86.Pclmulqdq::CarrylessMultiply(System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Runtime.Intrinsics.Vector128`1<System.Int64>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_pclmulqdq_carryless_multiply_D2B9C(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_PCLMULQDQ_IS_SUPPORTED
    switch(arg3)
    {
        case 0:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    0
                )
            );
        }
        case 1:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    1
                )
            );
        }
        case 2:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    2
                )
            );
        }
        case 3:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    3
                )
            );
        }
        case 4:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    4
                )
            );
        }
        case 5:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    5
                )
            );
        }
        case 6:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    6
                )
            );
        }
        case 7:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    7
                )
            );
        }
        case 8:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    8
                )
            );
        }
        case 9:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    9
                )
            );
        }
        case 10:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    10
                )
            );
        }
        case 11:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    11
                )
            );
        }
        case 12:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    12
                )
            );
        }
        case 13:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    13
                )
            );
        }
        case 14:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    14
                )
            );
        }
        case 15:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    15
                )
            );
        }
        case 16:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    16
                )
            );
        }
        case 17:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    17
                )
            );
        }
        case 18:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    18
                )
            );
        }
        case 19:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    19
                )
            );
        }
        case 20:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    20
                )
            );
        }
        case 21:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    21
                )
            );
        }
        case 22:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    22
                )
            );
        }
        case 23:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    23
                )
            );
        }
        case 24:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    24
                )
            );
        }
        case 25:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    25
                )
            );
        }
        case 26:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    26
                )
            );
        }
        case 27:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    27
                )
            );
        }
        case 28:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    28
                )
            );
        }
        case 29:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    29
                )
            );
        }
        case 30:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    30
                )
            );
        }
        case 31:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    31
                )
            );
        }
        case 32:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    32
                )
            );
        }
        case 33:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    33
                )
            );
        }
        case 34:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    34
                )
            );
        }
        case 35:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    35
                )
            );
        }
        case 36:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    36
                )
            );
        }
        case 37:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    37
                )
            );
        }
        case 38:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    38
                )
            );
        }
        case 39:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    39
                )
            );
        }
        case 40:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    40
                )
            );
        }
        case 41:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    41
                )
            );
        }
        case 42:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    42
                )
            );
        }
        case 43:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    43
                )
            );
        }
        case 44:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    44
                )
            );
        }
        case 45:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    45
                )
            );
        }
        case 46:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    46
                )
            );
        }
        case 47:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    47
                )
            );
        }
        case 48:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    48
                )
            );
        }
        case 49:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    49
                )
            );
        }
        case 50:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    50
                )
            );
        }
        case 51:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    51
                )
            );
        }
        case 52:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    52
                )
            );
        }
        case 53:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    53
                )
            );
        }
        case 54:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    54
                )
            );
        }
        case 55:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    55
                )
            );
        }
        case 56:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    56
                )
            );
        }
        case 57:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    57
                )
            );
        }
        case 58:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    58
                )
            );
        }
        case 59:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    59
                )
            );
        }
        case 60:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    60
                )
            );
        }
        case 61:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    61
                )
            );
        }
        case 62:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    62
                )
            );
        }
        case 63:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    63
                )
            );
        }
        case 64:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    64
                )
            );
        }
        case 65:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    65
                )
            );
        }
        case 66:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    66
                )
            );
        }
        case 67:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    67
                )
            );
        }
        case 68:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    68
                )
            );
        }
        case 69:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    69
                )
            );
        }
        case 70:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    70
                )
            );
        }
        case 71:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    71
                )
            );
        }
        case 72:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    72
                )
            );
        }
        case 73:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    73
                )
            );
        }
        case 74:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    74
                )
            );
        }
        case 75:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    75
                )
            );
        }
        case 76:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    76
                )
            );
        }
        case 77:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    77
                )
            );
        }
        case 78:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    78
                )
            );
        }
        case 79:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    79
                )
            );
        }
        case 80:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    80
                )
            );
        }
        case 81:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    81
                )
            );
        }
        case 82:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    82
                )
            );
        }
        case 83:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    83
                )
            );
        }
        case 84:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    84
                )
            );
        }
        case 85:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    85
                )
            );
        }
        case 86:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    86
                )
            );
        }
        case 87:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    87
                )
            );
        }
        case 88:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    88
                )
            );
        }
        case 89:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    89
                )
            );
        }
        case 90:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    90
                )
            );
        }
        case 91:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    91
                )
            );
        }
        case 92:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    92
                )
            );
        }
        case 93:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    93
                )
            );
        }
        case 94:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    94
                )
            );
        }
        case 95:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    95
                )
            );
        }
        case 96:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    96
                )
            );
        }
        case 97:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    97
                )
            );
        }
        case 98:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    98
                )
            );
        }
        case 99:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    99
                )
            );
        }
        case 100:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    100
                )
            );
        }
        case 101:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    101
                )
            );
        }
        case 102:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    102
                )
            );
        }
        case 103:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    103
                )
            );
        }
        case 104:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    104
                )
            );
        }
        case 105:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    105
                )
            );
        }
        case 106:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    106
                )
            );
        }
        case 107:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    107
                )
            );
        }
        case 108:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    108
                )
            );
        }
        case 109:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    109
                )
            );
        }
        case 110:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    110
                )
            );
        }
        case 111:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    111
                )
            );
        }
        case 112:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    112
                )
            );
        }
        case 113:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    113
                )
            );
        }
        case 114:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    114
                )
            );
        }
        case 115:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    115
                )
            );
        }
        case 116:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    116
                )
            );
        }
        case 117:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    117
                )
            );
        }
        case 118:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    118
                )
            );
        }
        case 119:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    119
                )
            );
        }
        case 120:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    120
                )
            );
        }
        case 121:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    121
                )
            );
        }
        case 122:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    122
                )
            );
        }
        case 123:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    123
                )
            );
        }
        case 124:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    124
                )
            );
        }
        case 125:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    125
                )
            );
        }
        case 126:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    126
                )
            );
        }
        case 127:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    127
                )
            );
        }
        case 128:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    128
                )
            );
        }
        case 129:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    129
                )
            );
        }
        case 130:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    130
                )
            );
        }
        case 131:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    131
                )
            );
        }
        case 132:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    132
                )
            );
        }
        case 133:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    133
                )
            );
        }
        case 134:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    134
                )
            );
        }
        case 135:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    135
                )
            );
        }
        case 136:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    136
                )
            );
        }
        case 137:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    137
                )
            );
        }
        case 138:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    138
                )
            );
        }
        case 139:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    139
                )
            );
        }
        case 140:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    140
                )
            );
        }
        case 141:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    141
                )
            );
        }
        case 142:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    142
                )
            );
        }
        case 143:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    143
                )
            );
        }
        case 144:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    144
                )
            );
        }
        case 145:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    145
                )
            );
        }
        case 146:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    146
                )
            );
        }
        case 147:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    147
                )
            );
        }
        case 148:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    148
                )
            );
        }
        case 149:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    149
                )
            );
        }
        case 150:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    150
                )
            );
        }
        case 151:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    151
                )
            );
        }
        case 152:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    152
                )
            );
        }
        case 153:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    153
                )
            );
        }
        case 154:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    154
                )
            );
        }
        case 155:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    155
                )
            );
        }
        case 156:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    156
                )
            );
        }
        case 157:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    157
                )
            );
        }
        case 158:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    158
                )
            );
        }
        case 159:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    159
                )
            );
        }
        case 160:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    160
                )
            );
        }
        case 161:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    161
                )
            );
        }
        case 162:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    162
                )
            );
        }
        case 163:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    163
                )
            );
        }
        case 164:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    164
                )
            );
        }
        case 165:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    165
                )
            );
        }
        case 166:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    166
                )
            );
        }
        case 167:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    167
                )
            );
        }
        case 168:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    168
                )
            );
        }
        case 169:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    169
                )
            );
        }
        case 170:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    170
                )
            );
        }
        case 171:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    171
                )
            );
        }
        case 172:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    172
                )
            );
        }
        case 173:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    173
                )
            );
        }
        case 174:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    174
                )
            );
        }
        case 175:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    175
                )
            );
        }
        case 176:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    176
                )
            );
        }
        case 177:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    177
                )
            );
        }
        case 178:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    178
                )
            );
        }
        case 179:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    179
                )
            );
        }
        case 180:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    180
                )
            );
        }
        case 181:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    181
                )
            );
        }
        case 182:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    182
                )
            );
        }
        case 183:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    183
                )
            );
        }
        case 184:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    184
                )
            );
        }
        case 185:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    185
                )
            );
        }
        case 186:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    186
                )
            );
        }
        case 187:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    187
                )
            );
        }
        case 188:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    188
                )
            );
        }
        case 189:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    189
                )
            );
        }
        case 190:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    190
                )
            );
        }
        case 191:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    191
                )
            );
        }
        case 192:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    192
                )
            );
        }
        case 193:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    193
                )
            );
        }
        case 194:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    194
                )
            );
        }
        case 195:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    195
                )
            );
        }
        case 196:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    196
                )
            );
        }
        case 197:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    197
                )
            );
        }
        case 198:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    198
                )
            );
        }
        case 199:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    199
                )
            );
        }
        case 200:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    200
                )
            );
        }
        case 201:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    201
                )
            );
        }
        case 202:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    202
                )
            );
        }
        case 203:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    203
                )
            );
        }
        case 204:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    204
                )
            );
        }
        case 205:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    205
                )
            );
        }
        case 206:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    206
                )
            );
        }
        case 207:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    207
                )
            );
        }
        case 208:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    208
                )
            );
        }
        case 209:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    209
                )
            );
        }
        case 210:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    210
                )
            );
        }
        case 211:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    211
                )
            );
        }
        case 212:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    212
                )
            );
        }
        case 213:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    213
                )
            );
        }
        case 214:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    214
                )
            );
        }
        case 215:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    215
                )
            );
        }
        case 216:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    216
                )
            );
        }
        case 217:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    217
                )
            );
        }
        case 218:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    218
                )
            );
        }
        case 219:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    219
                )
            );
        }
        case 220:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    220
                )
            );
        }
        case 221:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    221
                )
            );
        }
        case 222:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    222
                )
            );
        }
        case 223:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    223
                )
            );
        }
        case 224:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    224
                )
            );
        }
        case 225:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    225
                )
            );
        }
        case 226:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    226
                )
            );
        }
        case 227:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    227
                )
            );
        }
        case 228:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    228
                )
            );
        }
        case 229:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    229
                )
            );
        }
        case 230:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    230
                )
            );
        }
        case 231:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    231
                )
            );
        }
        case 232:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    232
                )
            );
        }
        case 233:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    233
                )
            );
        }
        case 234:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    234
                )
            );
        }
        case 235:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    235
                )
            );
        }
        case 236:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    236
                )
            );
        }
        case 237:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    237
                )
            );
        }
        case 238:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    238
                )
            );
        }
        case 239:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    239
                )
            );
        }
        case 240:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    240
                )
            );
        }
        case 241:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    241
                )
            );
        }
        case 242:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    242
                )
            );
        }
        case 243:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    243
                )
            );
        }
        case 244:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    244
                )
            );
        }
        case 245:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    245
                )
            );
        }
        case 246:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    246
                )
            );
        }
        case 247:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    247
                )
            );
        }
        case 248:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    248
                )
            );
        }
        case 249:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    249
                )
            );
        }
        case 250:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    250
                )
            );
        }
        case 251:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    251
                )
            );
        }
        case 252:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    252
                )
            );
        }
        case 253:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    253
                )
            );
        }
        case 254:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    254
                )
            );
        }
        case 255:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
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
    inline TRet il2cpp_intrinsic_pclmulqdq_carryless_multiply_D2B9C(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_PCLMULQDQ_IS_SUPPORTED
    if (TArg3Value < 0 || TArg3Value > 255)
        il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

    return INTRINSIC_CAST(
        __m128i, TRet, _mm_clmulepi64_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1),
            INTRINSIC_CAST(TArg2, __m128i, arg2),
            TArg3Value
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt64> System.Runtime.Intrinsics.X86.Pclmulqdq::CarrylessMultiply(System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Runtime.Intrinsics.Vector128`1<System.UInt64>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [2]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_pclmulqdq_carryless_multiply_B8B89(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_PCLMULQDQ_IS_SUPPORTED
    switch(arg3)
    {
        case 0:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    0
                )
            );
        }
        case 1:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    1
                )
            );
        }
        case 2:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    2
                )
            );
        }
        case 3:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    3
                )
            );
        }
        case 4:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    4
                )
            );
        }
        case 5:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    5
                )
            );
        }
        case 6:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    6
                )
            );
        }
        case 7:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    7
                )
            );
        }
        case 8:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    8
                )
            );
        }
        case 9:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    9
                )
            );
        }
        case 10:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    10
                )
            );
        }
        case 11:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    11
                )
            );
        }
        case 12:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    12
                )
            );
        }
        case 13:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    13
                )
            );
        }
        case 14:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    14
                )
            );
        }
        case 15:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    15
                )
            );
        }
        case 16:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    16
                )
            );
        }
        case 17:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    17
                )
            );
        }
        case 18:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    18
                )
            );
        }
        case 19:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    19
                )
            );
        }
        case 20:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    20
                )
            );
        }
        case 21:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    21
                )
            );
        }
        case 22:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    22
                )
            );
        }
        case 23:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    23
                )
            );
        }
        case 24:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    24
                )
            );
        }
        case 25:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    25
                )
            );
        }
        case 26:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    26
                )
            );
        }
        case 27:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    27
                )
            );
        }
        case 28:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    28
                )
            );
        }
        case 29:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    29
                )
            );
        }
        case 30:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    30
                )
            );
        }
        case 31:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    31
                )
            );
        }
        case 32:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    32
                )
            );
        }
        case 33:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    33
                )
            );
        }
        case 34:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    34
                )
            );
        }
        case 35:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    35
                )
            );
        }
        case 36:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    36
                )
            );
        }
        case 37:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    37
                )
            );
        }
        case 38:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    38
                )
            );
        }
        case 39:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    39
                )
            );
        }
        case 40:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    40
                )
            );
        }
        case 41:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    41
                )
            );
        }
        case 42:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    42
                )
            );
        }
        case 43:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    43
                )
            );
        }
        case 44:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    44
                )
            );
        }
        case 45:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    45
                )
            );
        }
        case 46:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    46
                )
            );
        }
        case 47:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    47
                )
            );
        }
        case 48:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    48
                )
            );
        }
        case 49:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    49
                )
            );
        }
        case 50:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    50
                )
            );
        }
        case 51:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    51
                )
            );
        }
        case 52:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    52
                )
            );
        }
        case 53:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    53
                )
            );
        }
        case 54:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    54
                )
            );
        }
        case 55:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    55
                )
            );
        }
        case 56:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    56
                )
            );
        }
        case 57:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    57
                )
            );
        }
        case 58:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    58
                )
            );
        }
        case 59:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    59
                )
            );
        }
        case 60:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    60
                )
            );
        }
        case 61:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    61
                )
            );
        }
        case 62:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    62
                )
            );
        }
        case 63:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    63
                )
            );
        }
        case 64:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    64
                )
            );
        }
        case 65:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    65
                )
            );
        }
        case 66:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    66
                )
            );
        }
        case 67:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    67
                )
            );
        }
        case 68:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    68
                )
            );
        }
        case 69:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    69
                )
            );
        }
        case 70:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    70
                )
            );
        }
        case 71:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    71
                )
            );
        }
        case 72:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    72
                )
            );
        }
        case 73:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    73
                )
            );
        }
        case 74:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    74
                )
            );
        }
        case 75:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    75
                )
            );
        }
        case 76:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    76
                )
            );
        }
        case 77:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    77
                )
            );
        }
        case 78:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    78
                )
            );
        }
        case 79:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    79
                )
            );
        }
        case 80:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    80
                )
            );
        }
        case 81:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    81
                )
            );
        }
        case 82:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    82
                )
            );
        }
        case 83:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    83
                )
            );
        }
        case 84:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    84
                )
            );
        }
        case 85:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    85
                )
            );
        }
        case 86:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    86
                )
            );
        }
        case 87:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    87
                )
            );
        }
        case 88:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    88
                )
            );
        }
        case 89:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    89
                )
            );
        }
        case 90:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    90
                )
            );
        }
        case 91:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    91
                )
            );
        }
        case 92:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    92
                )
            );
        }
        case 93:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    93
                )
            );
        }
        case 94:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    94
                )
            );
        }
        case 95:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    95
                )
            );
        }
        case 96:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    96
                )
            );
        }
        case 97:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    97
                )
            );
        }
        case 98:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    98
                )
            );
        }
        case 99:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    99
                )
            );
        }
        case 100:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    100
                )
            );
        }
        case 101:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    101
                )
            );
        }
        case 102:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    102
                )
            );
        }
        case 103:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    103
                )
            );
        }
        case 104:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    104
                )
            );
        }
        case 105:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    105
                )
            );
        }
        case 106:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    106
                )
            );
        }
        case 107:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    107
                )
            );
        }
        case 108:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    108
                )
            );
        }
        case 109:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    109
                )
            );
        }
        case 110:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    110
                )
            );
        }
        case 111:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    111
                )
            );
        }
        case 112:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    112
                )
            );
        }
        case 113:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    113
                )
            );
        }
        case 114:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    114
                )
            );
        }
        case 115:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    115
                )
            );
        }
        case 116:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    116
                )
            );
        }
        case 117:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    117
                )
            );
        }
        case 118:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    118
                )
            );
        }
        case 119:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    119
                )
            );
        }
        case 120:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    120
                )
            );
        }
        case 121:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    121
                )
            );
        }
        case 122:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    122
                )
            );
        }
        case 123:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    123
                )
            );
        }
        case 124:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    124
                )
            );
        }
        case 125:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    125
                )
            );
        }
        case 126:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    126
                )
            );
        }
        case 127:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    127
                )
            );
        }
        case 128:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    128
                )
            );
        }
        case 129:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    129
                )
            );
        }
        case 130:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    130
                )
            );
        }
        case 131:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    131
                )
            );
        }
        case 132:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    132
                )
            );
        }
        case 133:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    133
                )
            );
        }
        case 134:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    134
                )
            );
        }
        case 135:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    135
                )
            );
        }
        case 136:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    136
                )
            );
        }
        case 137:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    137
                )
            );
        }
        case 138:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    138
                )
            );
        }
        case 139:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    139
                )
            );
        }
        case 140:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    140
                )
            );
        }
        case 141:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    141
                )
            );
        }
        case 142:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    142
                )
            );
        }
        case 143:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    143
                )
            );
        }
        case 144:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    144
                )
            );
        }
        case 145:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    145
                )
            );
        }
        case 146:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    146
                )
            );
        }
        case 147:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    147
                )
            );
        }
        case 148:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    148
                )
            );
        }
        case 149:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    149
                )
            );
        }
        case 150:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    150
                )
            );
        }
        case 151:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    151
                )
            );
        }
        case 152:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    152
                )
            );
        }
        case 153:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    153
                )
            );
        }
        case 154:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    154
                )
            );
        }
        case 155:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    155
                )
            );
        }
        case 156:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    156
                )
            );
        }
        case 157:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    157
                )
            );
        }
        case 158:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    158
                )
            );
        }
        case 159:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    159
                )
            );
        }
        case 160:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    160
                )
            );
        }
        case 161:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    161
                )
            );
        }
        case 162:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    162
                )
            );
        }
        case 163:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    163
                )
            );
        }
        case 164:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    164
                )
            );
        }
        case 165:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    165
                )
            );
        }
        case 166:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    166
                )
            );
        }
        case 167:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    167
                )
            );
        }
        case 168:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    168
                )
            );
        }
        case 169:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    169
                )
            );
        }
        case 170:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    170
                )
            );
        }
        case 171:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    171
                )
            );
        }
        case 172:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    172
                )
            );
        }
        case 173:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    173
                )
            );
        }
        case 174:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    174
                )
            );
        }
        case 175:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    175
                )
            );
        }
        case 176:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    176
                )
            );
        }
        case 177:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    177
                )
            );
        }
        case 178:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    178
                )
            );
        }
        case 179:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    179
                )
            );
        }
        case 180:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    180
                )
            );
        }
        case 181:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    181
                )
            );
        }
        case 182:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    182
                )
            );
        }
        case 183:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    183
                )
            );
        }
        case 184:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    184
                )
            );
        }
        case 185:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    185
                )
            );
        }
        case 186:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    186
                )
            );
        }
        case 187:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    187
                )
            );
        }
        case 188:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    188
                )
            );
        }
        case 189:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    189
                )
            );
        }
        case 190:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    190
                )
            );
        }
        case 191:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    191
                )
            );
        }
        case 192:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    192
                )
            );
        }
        case 193:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    193
                )
            );
        }
        case 194:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    194
                )
            );
        }
        case 195:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    195
                )
            );
        }
        case 196:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    196
                )
            );
        }
        case 197:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    197
                )
            );
        }
        case 198:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    198
                )
            );
        }
        case 199:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    199
                )
            );
        }
        case 200:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    200
                )
            );
        }
        case 201:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    201
                )
            );
        }
        case 202:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    202
                )
            );
        }
        case 203:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    203
                )
            );
        }
        case 204:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    204
                )
            );
        }
        case 205:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    205
                )
            );
        }
        case 206:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    206
                )
            );
        }
        case 207:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    207
                )
            );
        }
        case 208:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    208
                )
            );
        }
        case 209:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    209
                )
            );
        }
        case 210:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    210
                )
            );
        }
        case 211:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    211
                )
            );
        }
        case 212:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    212
                )
            );
        }
        case 213:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    213
                )
            );
        }
        case 214:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    214
                )
            );
        }
        case 215:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    215
                )
            );
        }
        case 216:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    216
                )
            );
        }
        case 217:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    217
                )
            );
        }
        case 218:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    218
                )
            );
        }
        case 219:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    219
                )
            );
        }
        case 220:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    220
                )
            );
        }
        case 221:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    221
                )
            );
        }
        case 222:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    222
                )
            );
        }
        case 223:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    223
                )
            );
        }
        case 224:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    224
                )
            );
        }
        case 225:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    225
                )
            );
        }
        case 226:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    226
                )
            );
        }
        case 227:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    227
                )
            );
        }
        case 228:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    228
                )
            );
        }
        case 229:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    229
                )
            );
        }
        case 230:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    230
                )
            );
        }
        case 231:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    231
                )
            );
        }
        case 232:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    232
                )
            );
        }
        case 233:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    233
                )
            );
        }
        case 234:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    234
                )
            );
        }
        case 235:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    235
                )
            );
        }
        case 236:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    236
                )
            );
        }
        case 237:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    237
                )
            );
        }
        case 238:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    238
                )
            );
        }
        case 239:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    239
                )
            );
        }
        case 240:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    240
                )
            );
        }
        case 241:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    241
                )
            );
        }
        case 242:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    242
                )
            );
        }
        case 243:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    243
                )
            );
        }
        case 244:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    244
                )
            );
        }
        case 245:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    245
                )
            );
        }
        case 246:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    246
                )
            );
        }
        case 247:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    247
                )
            );
        }
        case 248:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    248
                )
            );
        }
        case 249:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    249
                )
            );
        }
        case 250:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    250
                )
            );
        }
        case 251:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    251
                )
            );
        }
        case 252:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    252
                )
            );
        }
        case 253:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    253
                )
            );
        }
        case 254:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
                    INTRINSIC_CAST(TArg1, __m128i, arg1),
                    INTRINSIC_CAST(TArg2, __m128i, arg2),
                    254
                )
            );
        }
        case 255:
        {
            return INTRINSIC_CAST(
                __m128i, TRet, _mm_clmulepi64_si128(
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
    inline TRet il2cpp_intrinsic_pclmulqdq_carryless_multiply_B8B89(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_PCLMULQDQ_IS_SUPPORTED
    if (TArg3Value < 0 || TArg3Value > 255)
        il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

    return INTRINSIC_CAST(
        __m128i, TRet, _mm_clmulepi64_si128(
            INTRINSIC_CAST(TArg1, __m128i, arg1),
            INTRINSIC_CAST(TArg2, __m128i, arg2),
            TArg3Value
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
