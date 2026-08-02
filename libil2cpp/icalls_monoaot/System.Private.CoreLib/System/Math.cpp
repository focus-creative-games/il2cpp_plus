#include "il2cpp-config.h"
#include "Math.h"

#include "vm/Exception.h"
#include <cmath>
#include <float.h>
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
    static bool IsInteger(double value)
    {
        double unused;
        return std::modf(value, &unused) == 0.0;
    }

    // Use this function to test for odd integers instead of converting a
    // double to int64_t then ANDing with 1 (or modulo). In C++, double to integer
    // conversions are truncated but the behavior is undefined if the truncated
    // value cannot be represented in the destination type. This means that huge
    // doubles may not be handled correctly.
    static bool IsOddInteger(double value)
    {
        return std::fmod(value, 2.0) == std::copysign(1.0, value);
    }

    double Math::Acos(double d)
    {
        return acos(d);
    }

    double Math::Acosh(double d)
    {
        return acosh(d);
    }

    double Math::Asin(double d)
    {
        return asin(d);
    }

    double Math::Asinh(double d)
    {
        return asinh(d);
    }

    double Math::Atan(double d)
    {
        return atan(d);
    }

    double Math::Atan2(double y, double x)
    {
        return atan2(y, x);
    }

    double Math::Atanh(double d)
    {
        return atanh(d);
    }

    double Math::Cbrt(double d)
    {
        return cbrt(d);
    }

    double Math::Ceiling(double a)
    {
        return ceil(a);
    }

    double Math::Cos(double d)
    {
        return cos(d);
    }

    double Math::Cosh(double value)
    {
        return cosh(value);
    }

    double Math::Exp(double d)
    {
        return exp(d);
    }

    double Math::Floor(double d)
    {
        return floor(d);
    }

    double Math::FusedMultiplyAdd(double x, double y, double z)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(Math::FusedMultiplyAdd);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    double Math::Log(double d)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(Math::Log, "Determin what value of NAN to use");

        if (d == 0)
            return -HUGE_VAL;
        else if (d < 0)
            return std::numeric_limits<double>::signaling_NaN();
        //return NAN;

        return log(d);
    }

    double Math::Log10(double d)
    {
        return log10(d);
    }

    double Math::Log2(double x)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(Math::Log2);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    double Math::ModF(double x, double* d)
    {
        return modf(x, d);
    }

    double Math::Pow(double val, double exp)
    {
        if (std::isnan(val))
            return val;
        if (std::isnan(exp))
            return exp;

        if (val > -1 && val < 1 && exp == -std::numeric_limits<double>::infinity())
            return std::numeric_limits<double>::infinity();

        if (val > -1 && val < 1 && exp == std::numeric_limits<double>::infinity())
            return 0.0;

        if ((val < -1 || val > 1) && exp == -std::numeric_limits<double>::infinity())
            return 0.0;

        if ((val < -1 || val > 1) && exp == std::numeric_limits<double>::infinity())
            return std::numeric_limits<double>::infinity();

        if (val == -std::numeric_limits<double>::infinity())
        {
            if (exp < 0)
                return 0.0;

            if (exp > 0)
            {
                return IsOddInteger(exp) ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
            }

            return 1.0;
        }

        if (val < 0)
        {
            if (!IsInteger(exp) || exp == std::numeric_limits<double>::infinity() || exp == -std::numeric_limits<double>::infinity())
                return std::numeric_limits<double>::quiet_NaN();
        }

        double res = pow(val, exp);
        if (std::isnan(res))
            return 1.0;

        if (res == -0.0)
            return 0.0;

        return res;
    }

    double Math::Sin(double a)
    {
        return sin(a);
    }

    double Math::Sinh(double value)
    {
        return sinh(value);
    }

    double Math::Sqrt(double d)
    {
        return sqrt(d);
    }

    double Math::Tan(double a)
    {
        return tan(a);
    }

    double Math::Tanh(double value)
    {
        return tanh(value);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
