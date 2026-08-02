#pragma once

#include "il2cpp-object-internals.h"
#include "il2cpp-class-internals.h"
#include "mono-structs.h"

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
    class LIBIL2CPP_CODEGEN_API RuntimeConstructorInfo
    {
    public:
        static int32_t get_metadata_token(Il2CppObject* method);
        static Il2CppObject* InternalInvoke(Il2CppReflectionMethod* thisPtr, Il2CppObject* obj, intptr_t* args, Il2CppException** exc);
        static void InvokeClassConstructor(Il2CppQCallTypeHandle type);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
