#include "il2cpp-config.h"
#include "icalls/mscorlib/System.Security.Principal/WindowsIdentity.h"
#include "vm/String.h"
#include "vm/Exception.h"

namespace il2cpp
{
namespace icalls
{
namespace mscorlib
{
namespace System
{
namespace Security
{
namespace Principal
{
    intptr_t WindowsIdentity::GetCurrentToken()
    {
        return 0;
    }

    intptr_t WindowsIdentity::GetUserToken(Il2CppString* username)
    {
        NOT_SUPPORTED_IL2CPP(WindowsIdentity::GetUserToken, "This icall is not supported by il2cpp.");

        return 0;
    }

    Il2CppString* WindowsIdentity::GetTokenName(intptr_t token)
    {
        return vm::String::Empty();
    }

    Il2CppArray* WindowsIdentity::_GetRoles(intptr_t token)
    {
        NOT_SUPPORTED_IL2CPP(WindowsIdentity::_GetRoles, "This icall is not supported by il2cpp.");

        return 0;
    }
} /* namespace Principal */
} /* namespace Security */
} /* namespace System */
} /* namespace mscorlib */
} /* namespace icalls */
} /* namespace il2cpp */
