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
    class LIBIL2CPP_CODEGEN_API FieldInfo
    {
    public:
        static Il2CppReflectionField* internal_from_handle_type(intptr_t field_handle, intptr_t type_handle);
        static Il2CppObject* get_marshal_info(Il2CppReflectionField* thisPtr);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
