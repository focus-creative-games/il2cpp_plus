#pragma once

#include <string>

namespace il2cpp
{
namespace vm
{
    class AppContext
    {
    public:
        static void SetupAppContextSwitches(const std::string& icuDataPath);
    };
}
}
