#pragma once

#include <string>

namespace il2cpp
{
namespace vm
{
    class IcuData
    {
    public:
        static std::string LoadIcuData();
        static void FreeIcuData();
    };
}
}
