#include "il2cpp-config.h"
#include "RuntimeFieldHandle.h"

#include "vm/Exception.h"
#include "vm/Field.h"
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
    Il2CppObject* RuntimeFieldHandle::GetValueDirect(Il2CppReflectionField* field, Il2CppObject* fieldType, Il2CppTypedRef* pTypedRef, Il2CppObject* contextType)
    {
        NOT_SUPPORTED_IL2CPP(RuntimeFieldHandle::GetValueDirect, "This icall is not supported by il2cpp.");
        return NULL;
    }

    void RuntimeFieldHandle::SetValueDirect(Il2CppReflectionField* field, Il2CppObject* fieldType, Il2CppTypedRef* pTypedRef, Il2CppObject* value, Il2CppObject* contextType)
    {
        IL2CPP_ASSERT(field);
        IL2CPP_ASSERT(pTypedRef);
        IL2CPP_ASSERT(value);

        FieldInfo* f = field->field;
        if (!vm::Type::IsStruct(&f->parent->byval_arg))
        {
            std::string errorMessage = "The type ";
            errorMessage += vm::Type::GetName(&f->parent->byval_arg, IL2CPP_TYPE_NAME_FORMAT_FULL_NAME);
            errorMessage += " is not struct";
            vm::Exception::Raise(vm::Exception::GetNotSupportedException(errorMessage.c_str()));
            return;
        }

        if (vm::Type::IsReference(f->type))
            vm::Field::SetValueRaw(f->type, (uint8_t*)pTypedRef->value + f->offset - sizeof(Il2CppObject), value, false);
        else
            vm::Field::SetValueRaw(f->type, (uint8_t*)pTypedRef->value + f->offset - sizeof(Il2CppObject), vm::Object::GetRawData(value), false);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
