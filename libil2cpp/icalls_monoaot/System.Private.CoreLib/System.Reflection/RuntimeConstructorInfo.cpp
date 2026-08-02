#include "il2cpp-config.h"
#include "RuntimeConstructorInfo.h"

#include "vm/Reflection.h"
#include "RuntimeMethodInfo.h"


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
    int32_t RuntimeConstructorInfo::get_metadata_token(Il2CppObject* method)
    {
        return vm::Reflection::GetMetadataToken(method);
    }

    Il2CppObject* RuntimeConstructorInfo::InternalInvoke(Il2CppReflectionMethod* thisPtr, Il2CppObject* obj, intptr_t* args, Il2CppException** exc)
    {
        return RuntimeMethodInfo::InternalInvoke(thisPtr, obj, args, exc);
    }

    void RuntimeConstructorInfo::InvokeClassConstructor(Il2CppQCallTypeHandle type)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeConstructorInfo::InvokeClassConstructor);
        IL2CPP_UNREACHABLE;
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
