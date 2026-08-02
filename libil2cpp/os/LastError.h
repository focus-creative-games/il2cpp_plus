#pragma once

namespace il2cpp
{
namespace os
{
    class LastError
    {
    public:
        static uint32_t GetLastError();
        static void SetLastError(uint32_t error);
    };
} /* namespace os */
} /* namespace il2cpp*/
