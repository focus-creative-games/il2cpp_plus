#include "il2cpp-config.h"
#include "TypedReference.h"

#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Object.h"
#include "vm/Type.h"

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
    Il2CppObject* TypedReference::InternalToObject(Il2CppTypedRef* value)
    {
        Il2CppObject* result = NULL;
        if (vm::Type::IsReference(value->type))
        {
            Il2CppObject** obj = (Il2CppObject**)value->value;
            return *obj;
        }

        result = vm::Object::Box(value->klass, value->value);
        return result;
    }

    void TypedReference::InternalMakeTypedReference(Il2CppTypedRef* result, Il2CppObject* target, Il2CppArray* flds, Il2CppObject* lastFieldType)
    {
        memset(result, 0, sizeof(Il2CppTypedRef));

        IL2CPP_ASSERT(flds);

        uint32_t fieldsArrayLength = vm::Array::GetLength(flds);

        Il2CppClass* klass = target->vtable->klass;

        uint8_t* value = NULL;
        const Il2CppType *ftype = NULL;
        for (uint32_t i = 0; i < fieldsArrayLength; ++i)
        {
            FieldInfo* f = il2cpp_array_get(flds, FieldInfo*, i);
            if (f == NULL)
            {
                vm::Exception::Raise(vm::Exception::GetArgumentNullException("field"));
                return;
            }

            if (i == 0)
                value = (uint8_t*)target + f->offset;
            else
                value += f->offset - sizeof(Il2CppObject);

            klass = vm::Class::FromIl2CppType(f->type);
            ftype = f->type;
        }

        result->type = ftype;
        result->klass = vm::Class::FromIl2CppType(ftype);
        result->value = value;
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
