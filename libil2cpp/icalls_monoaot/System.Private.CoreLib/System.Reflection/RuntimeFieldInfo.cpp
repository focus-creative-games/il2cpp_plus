#include "il2cpp-config.h"
#include "RuntimeFieldInfo.h"

#include "gc/GarbageCollector.h"
#include "utils/StringUtils.h"
#include "vm-utils/BlobReader.h"
#include "vm/Class.h"
#include "vm/Field.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include <il2cpp-object-internals.h>

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
    int32_t RuntimeFieldInfo::GetFieldOffset(Il2CppReflectionField* thisPtr)
    {
        return thisPtr->field->offset - sizeof(Il2CppObject);
    }

    int32_t RuntimeFieldInfo::get_metadata_token(Il2CppReflectionField* monoField)
    {
        return vm::Reflection::GetMetadataToken((Il2CppObject*)monoField);
    }

    Il2CppObject* RuntimeFieldInfo::GetRawConstantValue(Il2CppReflectionField* thisPtr)
    {
        ::FieldInfo* fieldInfo = thisPtr->field;

        if (!(fieldInfo->type->attrs & FIELD_ATTRIBUTE_HAS_DEFAULT))
            vm::Exception::Raise(vm::Exception::GetInvalidOperationException(NULL));

        const Il2CppType* type = NULL;
        const char* data = vm::Class::GetFieldDefaultValue(fieldInfo, &type);

        switch (type->type)
        {
            case IL2CPP_TYPE_U1:
            case IL2CPP_TYPE_I1:
            case IL2CPP_TYPE_BOOLEAN:
            case IL2CPP_TYPE_U2:
            case IL2CPP_TYPE_I2:
            case IL2CPP_TYPE_CHAR:
            case IL2CPP_TYPE_U4:
            case IL2CPP_TYPE_I4:
            case IL2CPP_TYPE_R4:
            case IL2CPP_TYPE_U8:
            case IL2CPP_TYPE_I8:
            case IL2CPP_TYPE_R8:
            {
                Il2CppObject* obj = vm::Object::New(vm::Class::FromIl2CppType(type));
                utils::BlobReader::GetConstantValueFromBlob(fieldInfo->parent->image, type->type, data, vm::Object::GetRawData(obj));
                return obj;
            }
            case IL2CPP_TYPE_SZARRAY:
            case IL2CPP_TYPE_STRING:
            case IL2CPP_TYPE_CLASS:
            case IL2CPP_TYPE_OBJECT:
            case IL2CPP_TYPE_GENERICINST:
            {
                Il2CppObject* obj = NULL;
                utils::BlobReader::GetConstantValueFromBlob(fieldInfo->parent->image, type->type, data, &obj);
                return obj;
            }
            default:
                vm::Exception::Raise(vm::Exception::GetInvalidOperationException(utils::StringUtils::Printf("Attempting to get raw constant value for field of type %d", type).c_str()));
        }

        return NULL;
    }

    Il2CppObject* RuntimeFieldInfo::GetValueInternal(Il2CppReflectionField* thisPtr, Il2CppObject* obj)
    {
        return vm::Field::GetValueObject(thisPtr->field, obj);
    }

    Il2CppReflectionType* RuntimeFieldInfo::GetParentType(Il2CppReflectionField* thisPtr, bool declaring)
    {
        Il2CppClass *parent;

        parent = declaring ? thisPtr->field->parent : thisPtr->klass;

        return il2cpp::vm::Reflection::GetTypeObject(&parent->byval_arg);
    }

    Il2CppObject* RuntimeFieldInfo::ResolveType(Il2CppReflectionField* thisPtr)
    {
        // This icall should not be called, since the runtime should always initialize the
        // type field of Il2CppReflectionField to a non-null value.
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeFieldInfo::ResolveType);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    Il2CppArray* RuntimeFieldInfo::GetTypeModifiers(Il2CppReflectionField* thisPtr, bool optional, int32_t genericArgumentPosition)
    {
        NOT_SUPPORTED_IL2CPP(RuntimeFieldInfo::GetTypeModifiers, "This icall is not supported by il2cpp.");
        return NULL;
    }

    void RuntimeFieldInfo::SetValueInternal(Il2CppReflectionField* fi, Il2CppObject* obj, Il2CppObject* value)
    {
        ::FieldInfo* fieldInfo = fi->field;
        Il2CppClass* fieldType = vm::Class::FromIl2CppType(fieldInfo->type);
        vm::Class::Init(fieldType);

        uint8_t* fieldAddress;

        if (fieldInfo->type->attrs & FIELD_ATTRIBUTE_STATIC)
        {
            if (fieldInfo->offset == THREAD_STATIC_FIELD_OFFSET)
            {
                IL2CPP_NOT_IMPLEMENTED(Field::StaticSetValue);
            }

            vm::Runtime::ClassInit(fieldInfo->parent);
            fieldAddress = static_cast<uint8_t*>(fieldInfo->parent->static_fields) + fieldInfo->offset;
        }
        else
        {
            IL2CPP_ASSERT(obj);
            fieldAddress = reinterpret_cast<uint8_t*>(obj) + fieldInfo->offset;
        }

        if (fieldType->byval_arg.valuetype)
        {
            uint32_t fieldSize = vm::Class::GetInstanceSize(fieldType) - sizeof(Il2CppObject);

            if (value != NULL)
                memcpy(fieldAddress, vm::Object::GetRawData(value), fieldSize);
            else
                // Setting value type to null is defined to zero it out
                memset(fieldAddress, 0, fieldSize);

            il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)fieldAddress, fieldSize);
        }
        else
        {
            memcpy(fieldAddress, &value, sizeof(Il2CppObject*));
            il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)fieldAddress);
        }
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
