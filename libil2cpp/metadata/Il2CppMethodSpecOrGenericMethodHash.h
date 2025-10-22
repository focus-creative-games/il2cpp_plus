#pragma once

#include <stddef.h>

struct Il2CppMethodSpecOrGenericMethod;

namespace il2cpp
{
namespace metadata
{
    struct Il2CppMethodSpecOrGenericMethodHash
    {
    public:
        size_t operator()(Il2CppMethodSpecOrGenericMethod method) const;
        static size_t Hash(Il2CppMethodSpecOrGenericMethod method);
    };
} /* namespace metadata */
} /* namespace il2cpp */
