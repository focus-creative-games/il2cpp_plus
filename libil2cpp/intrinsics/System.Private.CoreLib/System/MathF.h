#pragma once
#include "il2cpp-config.h"
#include "il2cpp-intrinsics-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include <cmath>
namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
    /* METHOD MAPPING
        Method: System.Single System.MathF::FusedMultiplyAdd(System.Single,System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_fused_multiply_add(float x, float y, float z)
    {
        return fmaf(x, y, z);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Abs(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_abs(float x)
    {
        return fabsf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Max(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_max(float x, float y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_max);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::MaxMagnitude(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_max_magnitude(float x, float y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_max_magnitude);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Min(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_min(float x, float y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_min);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::MinMagnitude(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_min_magnitude(float x, float y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_min_magnitude);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Round(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_round(float x)
    {
        return bankers_roundf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Truncate(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_truncate(float x)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_truncate);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Acos(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_acos(float x)
    {
        return acosf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Acosh(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_acosh(float x)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_acosh);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Asin(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_asin(float x)
    {
        return asinf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Asinh(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_asinh(float x)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_asinh);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Atan(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_atan(float x)
    {
        return atanf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Atan2(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_atan2(float y, float x)
    {
        return atan2f(y, x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Atanh(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_atanh(float x)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_atanh);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Cbrt(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_cbrt(float x)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_cbrt);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Ceiling(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_ceiling(float x)
    {
        return ceilf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Cos(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_cos(float x)
    {
        return cosf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Cosh(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_cosh(float x)
    {
        return coshf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Exp(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_exp(float x)
    {
        return expf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Floor(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_floor(float x)
    {
        return floorf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Log(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_log(float x)
    {
        return logf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Log2(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_log2(float x)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_log2);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Log10(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_log10(float x)
    {
        return log10f(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Pow(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_mathf_pow(float x, float y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_mathf_pow);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Sin(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_sin(float x)
    {
        return sinf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Sinh(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_sinh(float x)
    {
        return sinhf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Sqrt(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_sqrt(float x)
    {
        return sqrtf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Tan(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_tan(float x)
    {
        return tanf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::Tanh(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_tanh(float x)
    {
        return tanhf(x);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::FMod(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_f_mod(float x, float y)
    {
        return fmodf(x, y);
    }

    /* METHOD MAPPING
        Method: System.Single System.MathF::ModF(System.Single,System.Single*)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_mathf_modf(float x, float* intptr)
    {
        return modff(x, intptr);
    }
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
