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
namespace X86Base
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.X86Base/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
#if IL2CPP_X86BASE_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.X86Base/X64::BitScanForward(System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline uint64_t il2cpp_intrinsic__x64_bit_scan_forward(uint64_t value)
    {
#if IL2CPP_X86BASE_X64_IS_SUPPORTED
    #if defined(_MSC_VER)
        unsigned long index;
        unsigned char result = _BitScanForward64(&index, value);
        return result ? index : 0;
    #elif defined(__GNUC__) || defined(__clang__)
        return value ? __builtin_ctzll(value) : 0;
    #else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
    #endif
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.X86Base/X64::BitScanReverse(System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline uint64_t il2cpp_intrinsic__x64_bit_scan_reverse(uint64_t value)
    {
#if IL2CPP_X86BASE_X64_IS_SUPPORTED
    #if defined(_MSC_VER)
        unsigned long index;
        unsigned char result = _BitScanReverse64(&index, value);
        return result ? index : 0;
    #elif defined(__GNUC__) || defined(__clang__)
        // For BSR, we need 63 - __builtin_clzll(value) for equivalent behavior
        return value ? (63 - __builtin_clzll(value)) : 0;
    #else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
    #endif
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.ValueTuple`2<System.UInt64,System.UInt64> System.Runtime.Intrinsics.X86.X86Base/X64::DivRem(System.UInt64,System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x64_div_rem(TArg1 lower, TArg2 upper, TArg3 divisor)
    {
        il2cpp_codegen_raise_not_supported_exception();
        return {};
    }

    /* METHOD MAPPING
        Method: System.ValueTuple`2<System.Int64,System.Int64> System.Runtime.Intrinsics.X86.X86Base/X64::DivRem(System.UInt64,System.Int64,System.Int64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x64_div_rem_signed(TArg1 lower, TArg2 upper, TArg3 divisor)
    {
        il2cpp_codegen_raise_not_supported_exception();
        return {};
    }
} // namespace X86Base
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
