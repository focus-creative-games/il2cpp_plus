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
    class LIBIL2CPP_CODEGEN_API MonoMethodInfo
    {
    public:
        static int32_t get_method_attributes(intptr_t handle);
        static Il2CppArray* get_parameter_info(intptr_t handle, Il2CppReflectionMethod* member);
        static Il2CppObject* get_retval_marshal(intptr_t handle);
        static void get_method_info(intptr_t handle, Il2CppMonoMethodInfo* info);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
