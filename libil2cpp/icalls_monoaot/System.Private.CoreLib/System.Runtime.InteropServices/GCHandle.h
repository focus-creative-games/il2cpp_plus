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
namespace Runtime
{
namespace InteropServices
{
    class LIBIL2CPP_CODEGEN_API GCHandle
    {
    public:
        static intptr_t InternalAlloc(Il2CppObject* value, int32_t type);
        static Il2CppObject* InternalGet(intptr_t handle);
        static void InternalFree(intptr_t handle);
        static void InternalSet(intptr_t handle, Il2CppObject* value);
    };
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
