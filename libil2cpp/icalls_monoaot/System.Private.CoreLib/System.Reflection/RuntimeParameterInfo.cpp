#include "il2cpp-config.h"
#include "RuntimeParameterInfo.h"

#include "vm/Exception.h"
#include "vm/Reflection.h"

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
namespace System
{
namespace Reflection
{
    int32_t RuntimeParameterInfo::GetMetadataToken(Il2CppObject* thisPtr)
    {
        return vm::Reflection::GetMetadataToken(thisPtr);
    }

    Il2CppArray* RuntimeParameterInfo::GetTypeModifiers(Il2CppObject* type, Il2CppObject* member, int32_t position, bool optional, int32_t genericArgumentPosition)
    {
        NOT_SUPPORTED_IL2CPP(RuntimeParameterInfo::GetTypeModifiers, "This icall is not supported by il2cpp.");
        return NULL;
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
