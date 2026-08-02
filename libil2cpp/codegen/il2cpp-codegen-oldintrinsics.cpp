#if !MONO_NET8_BCL
#include "il2cpp-codegen.h"
#include "il2cpp-codegen-oldintrinsics.h"
#include "vm/Class.h"
#include "vm/Object.h"
#include "vm/CCW.h"
#include "vm/RCW.h"
#include "vm/Method.h"
#include "vm-utils/ImageStackCrawlMark.h"
#include "vm/Runtime.h"
#include "vm/Reflection.h"

Type_t* il2cpp_codegen_object_get_type(RuntimeObject* obj)
{
    return il2cpp_codegen_type_get_object(il2cpp::vm::Class::GetType(il2cpp::vm::Object::GetClass(obj)));
}

intptr_t il2cpp_codegen_get_com_interface_for_object(Il2CppObject* object, Type_t* type)
{
    return reinterpret_cast<intptr_t>(il2cpp::vm::CCW::GetCCW(object, reinterpret_cast<Il2CppReflectionType*>(type)));
}

MethodBase_t* il2cpp_codegen_get_method_object(const RuntimeMethod* method)
{
    if (method->is_inflated)
        method = il2cpp_codegen_get_generic_method_definition(method);
    return il2cpp_codegen_get_method_object_internal(method, method->klass);
}

static Type_t* InvokeRuntimeTypeGet(String_t* typeName, bool throwOnError, bool ignoreCase, const RuntimeMethod* callingMethod)
{
    // IL2CPP doesn't use the stack mark parameter, so we'll re-purpose it pass in the calling image
    ImageStackCrawlMark imageStackMark(il2cpp::vm::Class::GetImage(il2cpp::vm::Method::GetClass(callingMethod)));

    IL2CPP_ASSERT(il2cpp_defaults.runtime_type_get_type_method);
    IL2CPP_ASSERT(!il2cpp::vm::Method::IsInstance(il2cpp_defaults.runtime_type_get_type_method));

    bool reflectionOnly = false;
    void* params[] = {typeName, &throwOnError, &ignoreCase, &reflectionOnly, &imageStackMark };

    IL2CPP_ASSERT(il2cpp::vm::Method::GetParamCount(il2cpp_defaults.runtime_type_get_type_method) == 5);
    IL2CPP_ASSERT(il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 0)) == il2cpp_defaults.string_class);
    IL2CPP_ASSERT(il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 1)) == il2cpp_defaults.boolean_class);
    IL2CPP_ASSERT(il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 2)) == il2cpp_defaults.boolean_class);
    IL2CPP_ASSERT(il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 3)) == il2cpp_defaults.boolean_class);
    IL2CPP_ASSERT(il2cpp::vm::Method::GetParam(il2cpp_defaults.runtime_type_get_type_method, 4)->byref);

    return (Type_t*)il2cpp::vm::Runtime::InvokeWithThrow(il2cpp_defaults.runtime_type_get_type_method, NULL, params);
}

Type_t* il2cpp_codegen_get_type(String_t* typeName, const RuntimeMethod* callingMethod)
{
    return InvokeRuntimeTypeGet(typeName, false, false, callingMethod);
}

Type_t* il2cpp_codegen_get_type(String_t* typeName, bool throwOnError, const RuntimeMethod* callingMethod)
{
    return InvokeRuntimeTypeGet(typeName, throwOnError, false, callingMethod);
}

Type_t* il2cpp_codegen_get_type(String_t* typeName, bool throwOnError, bool ignoreCase, const RuntimeMethod* callingMethod)
{
    return InvokeRuntimeTypeGet(typeName, throwOnError, ignoreCase, callingMethod);
}

intptr_t il2cpp_codegen_com_get_iunknown_for_object(RuntimeObject* obj)
{
    return reinterpret_cast<intptr_t>(il2cpp_codegen_com_get_or_create_ccw_internal(obj, Il2CppIUnknown::IID));
}

RuntimeObject* il2cpp_codegen_com_get_object_for_iunknown(intptr_t pUnk)
{
    if (pUnk == 0)
        return NULL;

    return il2cpp::vm::RCW::GetOrCreateFromIUnknown(reinterpret_cast<Il2CppIUnknown*>(pUnk), il2cpp_defaults.il2cpp_com_object_class);
}

Assembly_t* il2cpp_codegen_get_executing_assembly(const RuntimeMethod* method)
{
    return (Assembly_t*)il2cpp::vm::Reflection::GetAssemblyObject(method->klass->image->assembly);
}

void SetGenericValueImpl(RuntimeArray* thisPtr, int32_t pos, void* value)
{
    il2cpp_array_setrefwithsize(thisPtr, thisPtr->klass->element_size, pos, value);
}

bool il2cpp_codegen_is_unmanaged(const RuntimeMethod* method)
{
    return !il2cpp_codegen_is_reference_or_contains_references(method);
}

#endif
