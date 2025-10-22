#pragma once

struct Il2CppMethodSpecOrGenericMethod;

namespace il2cpp
{
namespace metadata
{
    struct Il2CppMethodSpecOrGenericMethodCompare
    {
        bool operator()(Il2CppMethodSpecOrGenericMethod m1, Il2CppMethodSpecOrGenericMethod m2) const;
        static bool Equals(Il2CppMethodSpecOrGenericMethod m1, Il2CppMethodSpecOrGenericMethod m2);
    };
}  /* namespace metadata */
} /* namespace il2cpp */
