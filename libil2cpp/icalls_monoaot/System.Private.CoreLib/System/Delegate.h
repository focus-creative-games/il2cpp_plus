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
    class LIBIL2CPP_CODEGEN_API Delegate
    {
    public:
        static Il2CppDelegate* CreateDelegate_internal(Il2CppQCallTypeHandle type, Il2CppObject* target, Il2CppReflectionMethod* info, bool throwOnBindFailure);
        static Il2CppMulticastDelegate* AllocDelegateLike_internal(Il2CppDelegate* d);
        static Il2CppReflectionMethod* GetVirtualMethod_internal(Il2CppDelegate* thisPtr);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
