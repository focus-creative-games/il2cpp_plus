#pragma once

#include "il2cpp-runtime-metadata.h"

namespace il2cpp
{
namespace metadata
{
    class Il2CppMethodSpecOrGenericMethod
    {
    public:
        Il2CppMethodSpecOrGenericMethod() : storage(0) {}
        Il2CppMethodSpecOrGenericMethod(const Il2CppGenericMethod* gmethod);
        Il2CppMethodSpecOrGenericMethod(const Il2CppMethodSpec* methodSpec);
        Il2CppGenericMethodKey BuildGenericMethodKey() const;

    private:
        uintptr_t storage;
    };
}
}
