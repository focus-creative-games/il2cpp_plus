#include "il2cpp-config.h"
#include "il2cpp-class-internals.h"
#include "Il2CppGenericInstCompare.h"
#include "Il2CppTypeCompare.h"

namespace il2cpp
{
namespace metadata
{
    bool Il2CppGenericInstCompare::operator()(const Il2CppGenericInst* left, const Il2CppGenericInst* right) const
    {
        return Compare(left, right);
    }

    bool Il2CppGenericInstCompare::Compare(const Il2CppGenericInst* t1, const Il2CppGenericInst* t2)
    {
        if (t1)
        {
            return t2 && AreEqual(t1, t2);
        }
        else
        {
            return !t2;
        }
    }

    bool Il2CppGenericInstCompare::AreEqual(const Il2CppGenericInst* t1, const Il2CppGenericInst* t2)
    {
        if (t1 == t2)
        {
            return true;
        }
        if (t1->type_argc != t2->type_argc)
            return false;

        for (size_t i = 0; i < t1->type_argc; ++i)
        {
            if (!Il2CppTypeEqualityComparer::AreEqual(t1->type_argv[i], t2->type_argv[i]))
                return false;
        }

        return true;
    }
} /* namespace vm */
} /* namespace il2cpp */
