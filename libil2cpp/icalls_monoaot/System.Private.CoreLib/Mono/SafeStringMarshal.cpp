#include "il2cpp-config.h"
#include "SafeStringMarshal.h"
#include "utils/StringUtils.h"


#include "utils/Memory.h"
#include "utils/StringUtils.h"

namespace il2cpp
{
namespace icalls
{
namespace System
{
namespace Private
{
namespace CoreLib
{
namespace Mono
{
    intptr_t SafeStringMarshal::StringToUtf8_icall(Il2CppString** str)
    {
        std::string strobj = il2cpp::utils::StringUtils::Utf16ToUtf8((*str)->chars, (*str)->length);
        char* cstr = il2cpp::utils::StringUtils::StringDuplicate(strobj.c_str());
        return reinterpret_cast<intptr_t>(cstr);
    }

    void SafeStringMarshal::GFree(intptr_t ptr)
    {
        IL2CPP_FREE((char*)ptr);
    }
} // namespace Mono
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
