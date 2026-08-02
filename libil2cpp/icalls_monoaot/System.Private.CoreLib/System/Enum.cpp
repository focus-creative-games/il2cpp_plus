#include "il2cpp-config.h"
#include "Enum.h"

#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "vm/Class.h"
#include "vm/Enum.h"
#include "vm/Exception.h"
#include "vm/Object.h"
#include "vm/Reflection.h"

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
    uint8_t Enum::InternalGetCorElementType(Il2CppQCallTypeHandle enumType)
    {
        const Il2CppType* etype;
        etype = vm::Class::GetEnumBaseType(vm::Class::FromIl2CppType(enumType));
        return etype->type;
    }

    void Enum::GetEnumValuesAndNames(Il2CppQCallTypeHandle enumType, Il2CppArray** values, Il2CppArray** names)
    {
        vm::Enum::GetEnumValuesAndNames(vm::Class::FromIl2CppType(enumType), values, names);
    }

    void Enum::InternalBoxEnum(Il2CppQCallTypeHandle enumType, Il2CppObjectHandleOnStack res, int64_t value)
    {
        res = vm::Object::Box(vm::Class::FromIl2CppType(enumType), &value);
    }

    void Enum::InternalGetUnderlyingType(Il2CppQCallTypeHandle enumType, Il2CppObjectHandleOnStack res)
    {
        const Il2CppType* etype;

        etype = vm::Class::GetEnumBaseType(vm::Class::FromIl2CppType(enumType));
        if (!etype)
            /* MS throws this for typebuilders */
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException("Type must be a type provided by the runtime.", "enumType"));

        res = reinterpret_cast<Il2CppObject*>(il2cpp::vm::Reflection::GetTypeObject(etype));
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
