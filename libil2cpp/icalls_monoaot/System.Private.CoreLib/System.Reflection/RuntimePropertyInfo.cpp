#include "il2cpp-config.h"
#include "RuntimePropertyInfo.h"

#include "gc/WriteBarrier.h"
#include "vm/Class.h"
#include "vm/Reflection.h"
#include "vm/String.h"

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
    int32_t RuntimePropertyInfo::get_metadata_token(Il2CppObject* monoProperty)
    {
        return vm::Reflection::GetMetadataToken(monoProperty);
    }

    Il2CppObject* RuntimePropertyInfo::get_default_value(Il2CppObject* prop)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimePropertyInfo::get_default_value);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    Il2CppObject* RuntimePropertyInfo::internal_from_handle_type(intptr_t event_handle, intptr_t type_handle)
    {
        Il2CppClass *klass;

        IL2CPP_ASSERT(event_handle);

        ::PropertyInfo *handle = (::PropertyInfo*)event_handle;
        Il2CppType *type = (Il2CppType*)type_handle;

        if (!type)
        {
            klass = handle->parent;
        }
        else
        {
            klass = vm::Class::FromIl2CppType(type);

            bool found = klass == handle->parent || il2cpp::vm::Class::HasParent(klass, handle->parent);
            if (!found)
                /* Managed code will throw an exception */
                return NULL;
        }

        Il2CppReflectionProperty *result = il2cpp::vm::Reflection::GetPropertyObject(klass, handle);
        return (Il2CppObject*)result;
    }

    Il2CppArray* RuntimePropertyInfo::GetTypeModifiers(Il2CppObject* prop, bool optional, int32_t genericArgumentPosition)
    {
        NOT_SUPPORTED_IL2CPP(MonoPropertyInfo::GetTypeModifiers, "This icall is not supported by il2cpp.");

        return 0;
    }

    void RuntimePropertyInfo::get_property_info(Il2CppReflectionProperty* prop, Il2CppMonoPropertyInfo* info, int32_t req_info)
    {
        if ((req_info & PInfo_ReflectedType) != 0)
            IL2CPP_STRUCT_SETREF(info, parent, vm::Reflection::GetTypeObject(&prop->klass->byval_arg));
        else if ((req_info & PInfo_DeclaringType) != 0)
            IL2CPP_STRUCT_SETREF(info, declaringType, vm::Reflection::GetTypeObject(&prop->property->parent->byval_arg));

        if ((req_info & PInfo_Name) != 0)
            IL2CPP_STRUCT_SETREF(info, name, vm::String::New(prop->property->name));

        if ((req_info & PInfo_Attributes) != 0)
            info->attrs = prop->property->attrs;

        if ((req_info & PInfo_GetMethod) != 0)
            IL2CPP_STRUCT_SETREF(info, get, prop->property->get ?
                vm::Reflection::GetMethodObject(prop->property->get, prop->klass) : NULL);

        if ((req_info & PInfo_SetMethod) != 0)
            IL2CPP_STRUCT_SETREF(info, set, prop->property->set ?
                vm::Reflection::GetMethodObject(prop->property->set, prop->klass) : NULL);
        /*
         * There may be other methods defined for properties, though, it seems they are not exposed
         * in the reflection API
         */
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
