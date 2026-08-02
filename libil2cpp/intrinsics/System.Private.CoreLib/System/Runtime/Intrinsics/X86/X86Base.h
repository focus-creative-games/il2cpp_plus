#pragma once
#include "il2cpp-config.h"
#include "il2cpp-intrinsics-config.h"

#include "codegen/il2cpp-codegen-metadata.h"

#if defined(__GNUC__) || defined(__clang__)
// Utility for this class only that provides access to CPUID instruction
#include <cpuid.h>
#endif

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
        Method: System.Boolean System.Runtime.Intrinsics.X86.X86Base::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x86_base_get_is_supported()
    {
#if IL2CPP_X86BASE_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.X86Base::BitScanForward(System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x86_base_bit_scan_forward(TArg1 arg1)
    {
#if IL2CPP_X86BASE_IS_SUPPORTED
    #if defined(_MSC_VER)
        unsigned long index;
        unsigned char result = _BitScanForward(&index, INTRINSIC_CAST(TArg1, unsigned long, arg1));
        return INTRINSIC_CAST(unsigned long, TRet, result ? index : 0);
    #elif defined(__GNUC__) || defined(__clang__)
        unsigned int value = INTRINSIC_CAST(TArg1, unsigned int, arg1);
        return value ? INTRINSIC_CAST(unsigned int, TRet, __builtin_ctz(value)) : 0;
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
        Method: System.UInt32 System.Runtime.Intrinsics.X86.X86Base::BitScanReverse(System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x86_base_bit_scan_reverse(TArg1 arg1)
    {
#if IL2CPP_X86BASE_IS_SUPPORTED
    #if defined(_MSC_VER)
        unsigned long index;
        unsigned char result = _BitScanReverse(&index, INTRINSIC_CAST(TArg1, unsigned long, arg1));
        return INTRINSIC_CAST(unsigned long, TRet, result ? index : 0);
    #elif defined(__GNUC__) || defined(__clang__)
        unsigned int value = INTRINSIC_CAST(TArg1, unsigned int, arg1);
        // For BSR, we need 31 - __builtin_clz(value) for equivalent behavior
        return value ? INTRINSIC_CAST(unsigned int, TRet, 31 - __builtin_clz(value)) : 0;
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
        Method: System.ValueTuple`2<System.Int32,System.Int32> System.Runtime.Intrinsics.X86.X86Base::DivRem(System.UInt32,System.Int32,System.Int32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x86_base_div_rem_CE0F6(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        il2cpp_codegen_raise_not_supported_exception();
        return {};
    }

    /* METHOD MAPPING
        Method: System.ValueTuple`2<System.UInt32,System.UInt32> System.Runtime.Intrinsics.X86.X86Base::DivRem(System.UInt32,System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x86_base_div_rem_30543(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
        il2cpp_codegen_raise_not_supported_exception();
        return {};
    }

    /* METHOD MAPPING
        Method: System.ValueTuple`2<System.IntPtr,System.IntPtr> System.Runtime.Intrinsics.X86.X86Base::DivRem(System.UIntPtr,System.IntPtr,System.IntPtr)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x86_base_div_rem(TArg1 lower, TArg2 upper, TArg3 divisor)
    {
        il2cpp_codegen_raise_not_supported_exception();
        return {};
    }

    /* METHOD MAPPING
        Method: System.ValueTuple`2<System.UIntPtr,System.UIntPtr> System.Runtime.Intrinsics.X86.X86Base::DivRem(System.UIntPtr,System.UIntPtr,System.UIntPtr)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet,typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic__x86_base_div_rem_HANDHASH(TArg1 lower, TArg2 upper, TArg3 divisor)
    {
        il2cpp_codegen_raise_not_supported_exception();
        return {};
    }

    /* METHOD MAPPING
        Method: System.ValueTuple`4<System.Int32,System.Int32,System.Int32,System.Int32> System.Runtime.Intrinsics.X86.X86Base::CpuId(System.Int32,System.Int32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x86_base_cpu_id(TArg1 functionId, TArg2 subFunctionId)
    {
    #if IL2CPP_X86BASE_IS_SUPPORTED
        #if defined(_MSC_VER)
            // MSVC implementation
            int cpuInfo[4];
            __cpuidex(cpuInfo,
                    INTRINSIC_CAST(TArg1, int, functionId),
                    INTRINSIC_CAST(TArg2, int, subFunctionId));

            TRet result = {};
            memcpy(
                &result, cpuInfo, sizeof(cpuInfo)
            );
            return result;
        #elif defined(__GNUC__) || defined(__clang__)
            // GCC/Clang implementation

            unsigned int eax, ebx, ecx, edx;

            // Use the standard __get_cpuid function and handle the subfunction in ecx
            ecx = INTRINSIC_CAST(TArg2, unsigned int, subFunctionId);
            __get_cpuid(
                INTRINSIC_CAST(TArg1, unsigned int, functionId),
                &eax, &ebx, &ecx, &edx);

            int cpuInfo[4] = {(int)eax, (int)ebx, (int)ecx, (int)edx};
            TRet result = {};
            memcpy(
                &result, cpuInfo, sizeof(cpuInfo)
            );
            return result;
        #else
            il2cpp_codegen_raise_not_supported_exception();
            return {};
        #endif
    #else
        il2cpp_codegen_raise_not_supported_exception();
        return {};
    #endif
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.Intrinsics.X86.X86Base::Pause()
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic__x86_base_pause()
    {
        #if IL2CPP_X86BASE_IS_SUPPORTED
            #if defined(_MSC_VER)
                _mm_pause();
            #elif defined(__GNUC__) || defined(__clang__)
                __builtin_ia32_pause();
            #else
                il2cpp_codegen_raise_not_supported_exception();
                return;
            #endif
        #else
            il2cpp_codegen_raise_not_supported_exception();
            return;
        #endif
    }
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
