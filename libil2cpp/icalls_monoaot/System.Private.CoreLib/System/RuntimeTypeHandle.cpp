#include "il2cpp-config.h"
#include "RuntimeTypeHandle.h"

#include "Type.h"
#include "il2cpp-api.h"
#include "il2cpp-object-internals.h"
#include "mono-structs.h"
#include "utils/StringUtils.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/GenericClass.h"
#include "vm/Image.h"
#include "vm/MetadataCache.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm-utils/ImageStackCrawlMark.h"

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
    bool RuntimeTypeHandle::HasInstantiation(Il2CppQCallTypeHandle type)
    {
        if (type->byref)
            return false;

        Il2CppClass* klass = vm::Class::FromIl2CppType(type);

        return vm::Class::IsGeneric(klass) || vm::Class::IsInflated(klass);
    }

    bool RuntimeTypeHandle::HasReferences(Il2CppQCallTypeHandle type)
    {
        return vm::Class::FromIl2CppType(type)->has_references;
    }

    bool RuntimeTypeHandle::IsByRefLike(Il2CppQCallTypeHandle type)
    {
        Il2CppClass* klass = vm::Class::FromIl2CppType(type);
        return klass->is_byref_like;
    }

    bool RuntimeTypeHandle::IsComObject(Il2CppQCallTypeHandle type)
    {
        return false; // il2cpp does not support COM objects, so this is always false
    }

    bool RuntimeTypeHandle::IsGenericTypeDefinition(Il2CppQCallTypeHandle type)
    {
        Il2CppClass* klass;

        IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(MonoType::get_IsGenericTypeDefinition, "Check for custom Type implementations");
        //if (!IS_MONOTYPE (type))
        //  return FALSE;

        if (type->byref)
            return false;

        klass = vm::Class::FromIl2CppType(type);

        return vm::Class::IsGeneric(klass);
    }

    bool RuntimeTypeHandle::IsInstanceOfType(Il2CppQCallTypeHandle type, Il2CppObject* o)
    {
        if (type->byref)
            return false;

        Il2CppClass* klass = vm::Class::FromIl2CppType(type);
        return il2cpp::vm::Object::IsInst(o, klass) != NULL;
    }

    static bool is_generic_parameter(Il2CppType* type)
    {
        return !type->byref && (type->type == IL2CPP_TYPE_VAR || type->type == IL2CPP_TYPE_MVAR);
    }

    bool RuntimeTypeHandle::is_subclass_of(Il2CppQCallTypeHandle childType, Il2CppQCallTypeHandle baseType)
    {
        bool result = false;
        Il2CppClass *childClass;
        Il2CppClass *baseClass;

        childClass = vm::Class::FromIl2CppType(childType);
        baseClass = vm::Class::FromIl2CppType(baseType);

        if (childType->byref)
            return !baseType->byref && baseClass == il2cpp_defaults.object_class;

        if (baseType->byref)
            return false;

        /* .NET IsSubclassOf is not reflexive */
        if ((Il2CppReflectionType*)childType == (Il2CppReflectionType*)baseType)
            return false;

        if (is_generic_parameter(childType))
        {
            /* slow path: walk the type hierarchy looking at base types
             * until we see baseType.  If the current type is not a gparam,
             * break out of the loop and use is_subclass_of.
             */
            Il2CppClass *c = vm::Class::GenericParamGetBaseType(childClass);

            result = false;
            while (c != NULL)
            {
                if (c == baseClass)
                {
                    result = true;
                    break;
                }
                if (!is_generic_parameter(&c->byval_arg))
                {
                    result = vm::Class::IsSubclassOf(c, baseClass, false);
                    break;
                }
                else
                    c = vm::Class::GenericParamGetBaseType(c);
            }
        }
        else
        {
            result = vm::Class::IsSubclassOf(childClass, baseClass, false);
        }

        return result;
    }

    bool RuntimeTypeHandle::type_is_assignable_from(Il2CppQCallTypeHandle a, Il2CppQCallTypeHandle b)
    {
        return vm::Class::IsAssignableFrom(a, b);
    }

    int32_t RuntimeTypeHandle::GetArrayRank(Il2CppQCallTypeHandle type)
    {
        if (type->type != IL2CPP_TYPE_ARRAY && type->type != IL2CPP_TYPE_SZARRAY)
            IL2CPP_ASSERT("Type must be an array type");

        Il2CppClass* klass = vm::Class::FromIl2CppType(type);
        return klass->rank;
    }

    int32_t RuntimeTypeHandle::GetMetadataToken(Il2CppQCallTypeHandle type)
    {
        return vm::Class::FromIl2CppType(type)->token;
    }

    intptr_t RuntimeTypeHandle::GetGenericParameterInfo(Il2CppQCallTypeHandle type)
    {
        intptr_t retVal = 0;

        const Il2CppType *thisType = type;
        if ((thisType->type == IL2CPP_TYPE_VAR) || (thisType->type == IL2CPP_TYPE_MVAR))
        {
            Il2CppMetadataGenericParameterHandle param = il2cpp::vm::MetadataCache::GetGenericParameterFromType(thisType);
            if (param)
            {
                retVal = reinterpret_cast<intptr_t>(vm::Class::GetOrCreateMonoGenericParameterInfo(param));
            }
        }

        return retVal;
    }

    uint8_t RuntimeTypeHandle::GetCorElementType(Il2CppQCallTypeHandle type)
    {
        if (type->byref)
            return IL2CPP_TYPE_BYREF;
        else
            return (uint8_t)type->type;
    }

    int32_t RuntimeTypeHandle::GetAttributes(Il2CppQCallTypeHandle type)
    {
        Il2CppClass* klass = vm::Class::FromSystemType(type);

        return klass->flags;
    }

    void RuntimeTypeHandle::GetAssembly(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        res = (Il2CppObject*)vm::Reflection::GetAssemblyObject(vm::Image::GetAssembly(vm::Class::GetImage(vm::Class::FromIl2CppType(type))));
    }

    void RuntimeTypeHandle::GetBaseType(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* klass = vm::Class::FromIl2CppType(type);

        Il2CppReflectionType* retVal = klass->parent ? il2cpp::vm::Reflection::GetTypeObject(&klass->parent->byval_arg) : NULL;
        res = reinterpret_cast<Il2CppObject*>(retVal);
    }

    void RuntimeTypeHandle::GetElementType(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* klass;
        Il2CppReflectionType* retVal = NULL;

        klass = vm::Class::FromIl2CppType(type);

        // GetElementType should only return a type for:
        // Array Pointer PassedByRef
        if (type->byref)
            retVal = il2cpp::vm::Reflection::GetTypeObject(&klass->byval_arg);
        else if (klass->element_class && IL2CPP_CLASS_IS_ARRAY(klass))
            retVal = il2cpp::vm::Reflection::GetTypeObject(&klass->element_class->byval_arg);
        else if (klass->element_class && type->type == IL2CPP_TYPE_PTR)
            retVal = il2cpp::vm::Reflection::GetTypeObject(&klass->element_class->byval_arg);

        res = reinterpret_cast<Il2CppObject*>(retVal);
    }

    void RuntimeTypeHandle::GetGenericTypeDefinition_impl(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* klass;

        if (type->byref)
        {
            res = nullptr;
            return;
        }

        klass = vm::Class::FromIl2CppType(type);
        if (vm::Class::IsGeneric(klass))
        {
            res = (Il2CppObject*)(Il2CppReflectionType*)type;
        }

        if (klass->generic_class)
        {
            Il2CppClass* generic_class = vm::GenericClass::GetTypeDefinition(klass->generic_class);
            res = (Il2CppObject*)vm::Reflection::GetTypeObject(&generic_class->byval_arg);
            return;
        }

        res = nullptr;
    }

    void RuntimeTypeHandle::GetModule(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        res = (Il2CppObject*)vm::Reflection::GetModuleObject(vm::Class::GetImage(vm::Class::FromIl2CppType(type)));
    }

    void RuntimeTypeHandle::internal_from_name(const char* name, int32_t* stackMark, Il2CppObjectHandleOnStack res, bool throwOnError, bool ignoreCase)
    {
        std::string str = name;

        const Il2CppImage* callingImage = ImageStackCrawlMark::GetImageFromStackMark(stackMark);

        il2cpp::vm::TypeNameParseInfo info;
        il2cpp::vm::TypeNameParser parser(str, info, false);

        if (!parser.Parse())
        {
            res = nullptr;
            vm::Exception::Raise(vm::Exception::GetArgumentException("typeName", (std::string("Invalid type name: ") + str).c_str()));
            return;
        }

        vm::TypeSearchFlags searchFlags = vm::kTypeSearchFlagNone;

        if (throwOnError)
            searchFlags = static_cast<vm::TypeSearchFlags>(searchFlags | vm::kTypeSearchFlagThrowOnError);

        if (ignoreCase)
            searchFlags = static_cast<vm::TypeSearchFlags>(searchFlags | vm::kTypeSearchFlagIgnoreCase);

        const Il2CppType* type = vm::Class::il2cpp_type_from_type_info(info, searchFlags, callingImage);

        res = (Il2CppObject*)(type ? il2cpp::vm::Reflection::GetTypeObject(type) : nullptr);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
