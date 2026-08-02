#include "il2cpp-config.h"
#include "vm/Class.h"
#include "vm/Reflection.h"

#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Reflection.h"
#include <stddef.h>

#include "FieldInfo.h"

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
    Il2CppReflectionField* FieldInfo::internal_from_handle_type(intptr_t field_handle, intptr_t type_handle)
    {
        ::FieldInfo* fieldInfo = (::FieldInfo*)field_handle;
        Il2CppType* il2cppType = (Il2CppType*)type_handle;

        if (il2cppType == NULL)
            return vm::Reflection::GetFieldObject(fieldInfo->parent, fieldInfo);

        Il2CppClass* originalClass = vm::Class::FromIl2CppType(il2cppType);

        for (Il2CppClass* k = originalClass; k; k = k->parent)
        {
            if (k == fieldInfo->parent)
                return vm::Reflection::GetFieldObject(originalClass, fieldInfo);
        }

        return NULL;
    }

    Il2CppObject* FieldInfo::get_marshal_info(Il2CppReflectionField* thisPtr)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(FieldInfo::get_marshal_info, "We currently don't store marshal information in metadata");
        return NULL;
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
