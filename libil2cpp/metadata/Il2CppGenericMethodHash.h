#pragma once

#include <stddef.h>
#include "il2cpp-runtime-metadata.h"

namespace il2cpp
{
namespace metadata
{
    struct Il2CppGenericMethodHash
    {
    public:
        size_t operator()(const Il2CppGenericMethod* method) const;
        static size_t Hash(const Il2CppGenericMethod* method);
        static size_t Hash(const Il2CppGenericMethodKey& method);
    };
} /* namespace metadata */
} /* namespace il2cpp */
