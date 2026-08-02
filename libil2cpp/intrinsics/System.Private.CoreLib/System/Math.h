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
        Method: System.Double System.Math::FusedMultiplyAdd(System.Double,System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_fused_multiply_add(double x, double y, double z)
    {
        return fma(x, y, z);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Abs(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_abs(double value)
    {
        return fabs(value);
    }

    /* METHOD MAPPING
        Method: System.Single System.Math::Abs(System.Single)
        AssemblyName: System.Private.CoreLib
    */
    inline float il2cpp_intrinsic_math_abs(float value)
    {
        return fabsf(value);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Max(System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_max(double val1, double val2)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_max);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.Math::Max(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_math_max(float val1, float val2)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_max);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::MaxMagnitude(System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_max_magnitude(double x, double y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_max_magnitude);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Min(System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_min(double val1, double val2)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_min);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Single System.Math::Min(System.Single,System.Single)
        AssemblyName: System.Private.CoreLib
    */
    // inline float il2cpp_intrinsic_math_min(float val1, float val2)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_min);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::MinMagnitude(System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_min_magnitude(double x, double y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_min_magnitude);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Round(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_round(double a)
    {
        return bankers_round(a);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Truncate(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_truncate(double d)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_truncate);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Acos(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_acos(double d)
    {
        return acos(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Acosh(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_acosh(double d)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_acosh);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Asin(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_asin(double d)
    {
        return asin(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Asinh(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_asinh(double d)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_asinh);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Atan(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_atan(double d)
    {
        return atan(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Atan2(System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_atan2(double y, double x)
    {
        return atan2(y, x);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Atanh(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_atanh(double d)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_atanh);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Cbrt(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_cbrt(double d)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_cbrt);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Ceiling(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_ceiling(double a)
    {
        return ceil(a);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Cos(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_cos(double d)
    {
        return cos(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Cosh(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_cosh(double value)
    {
        return cosh(value);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Exp(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_exp(double d)
    {
        return exp(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Floor(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_floor(double d)
    {
        return floor(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Log(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_log(double d)
    {
        return log(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Log2(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_log2(double x)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_log2);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Log10(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_log10(double d)
    {
        return log10(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Pow(System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_pow(double x, double y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_pow);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::Sin(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_sin(double a)
    {
        return sin(a);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Sinh(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_sinh(double value)
    {
        return sinh(value);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Sqrt(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_sqrt(double d)
    {
        return sqrt(d);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Tan(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_tan(double a)
    {
        return tan(a);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::Tanh(System.Double)
        AssemblyName: System.Private.CoreLib
    */
    inline double il2cpp_intrinsic_math_tanh(double value)
    {
        return tanh(value);
    }

    /* METHOD MAPPING
        Method: System.Double System.Math::FMod(System.Double,System.Double)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_f_mod(double x, double y)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_f_mod);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Double System.Math::ModF(System.Double,System.Double*)
        AssemblyName: System.Private.CoreLib
    */
    // inline double il2cpp_intrinsic_math_mod_f(double x, double* intptr)
    // {
    //     IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_math_mod_f);
    //     IL2CPP_UNREACHABLE;
    //     return {};
    // }

    /* METHOD MAPPING
        Method: System.Int64 System.Math::Abs(System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline int64_t il2cpp_intrinsic_math_abs(int64_t value)
    {
        return llabs(value);
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Math::Abs(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_math_abs(int32_t value)
    {
        return abs(static_cast<int32_t>(value));
    }
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
