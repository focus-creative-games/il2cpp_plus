#include "il2cpp-config.h"
#include "MathF.h"

#include <cmath>
#include <limits>

namespace il2cpp
{
namespace icalls
{
namespace System
{
namespace Private
{
namespace CoreLib
{
namespace System
{
    static bool IsInteger(float value)
    {
        double unused;
        return std::modf(value, &unused) == 0.0;
    }

    // Use this function to test for odd integers instead of converting a
    // double to int64_t then ANDing with 1 (or modulo). In C++, double to integer
    // conversions are truncated but the behavior is undefined if the truncated
    // value cannot be represented in the destination type. This means that huge
    // doubles may not be handled correctly.
    static bool IsOddInteger(float value)
    {
        return std::fmod(value, 2.0) == std::copysign(1.0, value);
    }

    float MathF::Acos(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Acos);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Acosh(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Acosh);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Asin(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Asin);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Asinh(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Asinh);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Atan(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Atan);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Atan2(float y, float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Atan2);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Atanh(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Atanh);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Cbrt(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Cbrt);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Ceiling(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Ceiling);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Cos(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Cos);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Cosh(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Cosh);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Exp(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Exp);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Floor(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Floor);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::FusedMultiplyAdd(float x, float y, float z)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::FusedMultiplyAdd);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Log(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Log);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Log10(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Log10);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Log2(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Log2);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::ModF(float x, float* intptr)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::ModF);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Pow(float val, float exp)
    {
        if (std::isnan(val))
            return val;
        if (std::isnan(exp))
            return exp;

        if (val > -1 && val < 1 && exp == -std::numeric_limits<float>::infinity())
            return std::numeric_limits<float>::infinity();

        if (val > -1 && val < 1 && exp == std::numeric_limits<float>::infinity())
            return 0.0;

        if ((val < -1 || val > 1) && exp == -std::numeric_limits<float>::infinity())
            return 0.0;

        if ((val < -1 || val > 1) && exp == std::numeric_limits<float>::infinity())
            return std::numeric_limits<float>::infinity();

        if (val == -std::numeric_limits<float>::infinity())
        {
            if (exp < 0)
                return 0.0;

            if (exp > 0)
            {
                return IsOddInteger(exp) ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
            }

            return 1.0;
        }

        if (val < 0)
        {
            if (!IsInteger(exp) || exp == std::numeric_limits<float>::infinity() || exp == -std::numeric_limits<float>::infinity())
                return std::numeric_limits<float>::quiet_NaN();
        }

        float res = pow(val, exp);
        if (std::isnan(res))
            return 1.0;

        if (res == -0.0)
            return 0.0;

        return res;
    }

    float MathF::Sin(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Sin);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Sinh(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Sinh);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Sqrt(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Sqrt);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Tan(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Tan);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    float MathF::Tanh(float x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(MathF::Tanh);
        IL2CPP_UNREACHABLE;
        return 0;
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
