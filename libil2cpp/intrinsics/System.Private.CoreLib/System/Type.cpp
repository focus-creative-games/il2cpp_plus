#include "Type.h"
#include "vm/Class.h"
#include "vm/Method.h"
#include "vm-utils/ImageStackCrawlMark.h"
#include "vm/Runtime.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
    static Type_t* InvokeRuntimeTypeGet(String_t* typeName, bool throwOnError, bool ignoreCase, const RuntimeMethod* callingMethod)
    {
        // IL2CPP doesn't use the stack mark parameter, so we'll re-purpose it pass in the calling image
        ImageStackCrawlMark imageStackMark(il2cpp::vm::Class::GetImage(il2cpp::vm::Method::GetClass(callingMethod)));

        IL2CPP_ASSERT(il2cpp_defaults.runtime_type_get_type_method);
        IL2CPP_ASSERT(!il2cpp::vm::Method::IsInstance(il2cpp_defaults.runtime_type_get_type_method));

        void* params[] = {typeName, &throwOnError, &ignoreCase, &imageStackMark };

        IL2CPP_ASSERT(il2cpp::vm::Method::GetParamCount(il2cpp_defaults.runtime_type_get_type_method) == 4);
        IL2CPP_ASSERT(il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 0)) == il2cpp_defaults.string_class);
        IL2CPP_ASSERT(il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 1)) == il2cpp_defaults.boolean_class);
        IL2CPP_ASSERT(il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 2)) == il2cpp_defaults.boolean_class);
        IL2CPP_ASSERT(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 3)->byref);

        return (Type_t*)il2cpp::vm::Runtime::InvokeWithThrow(il2cpp_defaults.runtime_type_get_type_method, NULL, params);
    }

    Type_t* il2cpp_intrinsic_type_get_type(String_t* typeName, const RuntimeMethod* callingMethod)
    {
        return InvokeRuntimeTypeGet(typeName, false, false, callingMethod);
    }

    Type_t* il2cpp_intrinsic_type_get_type(String_t* typeName, bool throwOnError, const RuntimeMethod* callingMethod)
    {
        return InvokeRuntimeTypeGet(typeName, throwOnError, false, callingMethod);
    }

    Type_t* il2cpp_intrinsic_type_get_type(String_t* typeName, bool throwOnError, bool ignoreCase, const RuntimeMethod* callingMethod)
    {
        return InvokeRuntimeTypeGet(typeName, throwOnError, ignoreCase, callingMethod);
    }
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
