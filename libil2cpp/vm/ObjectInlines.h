#pragma once

#include "il2cpp-config.h"

struct Il2CppObject;

namespace il2cpp
{
namespace vm
{
    class ObjectInlines
    {
    public:
        static void* GetRawData(Il2CppObject* obj)
        {
            return obj + 1;
        }
    };
}
}
