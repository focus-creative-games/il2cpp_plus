#pragma once

#include "utils/KeyWrapper.h"

struct Il2CppGenericInst;

namespace il2cpp
{
namespace metadata
{
    class Il2CppGenericInstCompare
    {
    public:
        bool operator()(const Il2CppGenericInst* left, const Il2CppGenericInst* right) const;
        static bool Compare(const Il2CppGenericInst* left, const Il2CppGenericInst* right);
        static bool AreEqual(const Il2CppGenericInst* left, const Il2CppGenericInst* right);
    };
} /* namespace vm */
} /* namespace il2cpp */
