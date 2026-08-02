#include "il2cpp-config.h"
#include "ValueType.h"

#include "gc/WriteBarrier.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "il2cpp-tabledefs.h"
#include "utils/HashUtils.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Field.h"
#include "vm/Object.h"
#include "vm/String.h"
#include <memory>

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
    bool ValueType::InternalEquals(Il2CppObject* thisPtr, Il2CppObject* that, Il2CppArray** fields)
    {
        Il2CppClass *klass;
        Il2CppObject **values = NULL;
        Il2CppObject *o;
        FieldInfo* field;
        void* iter;
        int count = 0;

        IL2CPP_CHECK_ARG_NULL(that);

        if (thisPtr->klass != that->klass)
            return false;

        klass = vm::Object::GetClass(thisPtr);

        if (klass->enumtype && vm::Class::GetEnumBaseType(klass)->type == IL2CPP_TYPE_I4)
            return *(int32_t*)vm::Object::GetRawData(thisPtr) == *(int32_t*)vm::Object::GetRawData(that);

        /*
         * Do the comparison for fields of primitive type and return a result if
         * possible. Otherwise, return the remaining fields in an array to the
         * managed side. This way, we can avoid costly reflection operations in
         * managed code.
         */
        *fields = NULL;
        iter = NULL;
        while ((field = vm::Class::GetFields(klass, &iter)))
        {
            if (field->type->attrs & FIELD_ATTRIBUTE_STATIC)
                continue;
            if (vm::Field::IsDeleted(field))
                continue;
            /* FIXME: Add more types */

            switch (field->type->type)
            {
                case IL2CPP_TYPE_I1:
                case IL2CPP_TYPE_U1:
                case IL2CPP_TYPE_BOOLEAN:
                    if (*((uint8_t*)thisPtr + field->offset) != *((uint8_t*)that + field->offset))
                        return false;
                    break;
                case IL2CPP_TYPE_I2:
                case IL2CPP_TYPE_U2:
                case IL2CPP_TYPE_CHAR:
                    if (*(int16_t*)((uint8_t*)thisPtr + field->offset) != *(int16_t*)((uint8_t*)that + field->offset))
                        return false;
                    break;
                case IL2CPP_TYPE_I4:
                case IL2CPP_TYPE_U4:
                    if (*(int32_t*)((uint8_t*)thisPtr + field->offset) != *(int32_t*)((uint8_t*)that + field->offset))
                        return false;
                    break;
                case IL2CPP_TYPE_I8:
                case IL2CPP_TYPE_U8:
                    if (*(int64_t*)((uint8_t*)thisPtr + field->offset) != *(int64_t*)((uint8_t*)that + field->offset))
                        return false;
                    break;
                case IL2CPP_TYPE_R4:
                    if (*(float*)((uint8_t*)thisPtr + field->offset) != *(float*)((uint8_t*)that + field->offset))
                        return false;
                    break;
                case IL2CPP_TYPE_R8:
                    if (*(double*)((uint8_t*)thisPtr + field->offset) != *(double*)((uint8_t*)that + field->offset))
                        return false;
                    break;
                case IL2CPP_TYPE_PTR:
                    if (*(void**)((uint8_t*)thisPtr + field->offset) != *(void**)((uint8_t*)that + field->offset))
                        return false;
                    break;
                case IL2CPP_TYPE_STRING:
                    Il2CppString *s1, *s2;
                    uint32_t s1len, s2len;
                    s1 = *(Il2CppString**)((uint8_t*)thisPtr + field->offset);
                    s2 = *(Il2CppString**)((uint8_t*)that + field->offset);
                    if (s1 == s2)
                        break;
                    if ((s1 == NULL) || (s2 == NULL))
                        return false;
                    s1len = utils::StringUtils::GetLength(s1);
                    s2len = utils::StringUtils::GetLength(s2);
                    if (s1len != s2len)
                        return false;

                    if (memcmp(utils::StringUtils::GetChars(s1), utils::StringUtils::GetChars(s2), s1len * sizeof(Il2CppChar)) != 0)
                        return false;
                    break;
                default:
                    if (!values)
                        values = (Il2CppObject**)alloca(sizeof(Il2CppObject*) * (vm::Class::GetNumFields(klass) * 2));
                    o = vm::Field::GetValueObject(field, thisPtr);
                    values[count++] = o;
                    o = vm::Field::GetValueObject(field, that);
                    values[count++] = o;
            }

            if (klass->enumtype)
                /* enums only have one non-static field */
                break;
        }

        if (values)
        {
            int i;
            il2cpp::gc::WriteBarrier::GenericStore(fields, vm::Array::New(il2cpp_defaults.object_class, count));
            for (i = 0; i < count; ++i)
                il2cpp_array_setref(*fields, i, values[i]);
            return false;
        }
        else
        {
            return true;
        }
    }

    int32_t ValueType::InternalGetHashCode(Il2CppObject* o, Il2CppArray** fields)
    {
        Il2CppObject **values = NULL;
        int count = 0;
        FieldInfo* field = NULL;
        void* iter = NULL;

        Il2CppClass* klass = vm::Object::GetClass(o);
        int32_t result = (int32_t)il2cpp::utils::HashUtils::AlignedPointerHash(klass);

        if (vm::Class::GetNumFields(klass) == 0)
            return result;

        /*
         * Compute the starting value of the hashcode for fields of primitive
         * types, and return the remaining fields in an array to the managed side.
         * This way, we can avoid costly reflection operations in managed code.
         */
        iter = NULL;
        while ((field = vm::Class::GetFields(klass, &iter)))
        {
            if (field->type->attrs & FIELD_ATTRIBUTE_STATIC)
                continue;
            if (vm::Field::IsDeleted(field))
                continue;
            /* FIXME: Add more types */
            switch (field->type->type)
            {
                case IL2CPP_TYPE_I4:
                    result ^= *(int32_t*)((uint8_t*)o + field->offset);
                    break;
                case IL2CPP_TYPE_STRING:
                {
                    Il2CppString *s;
                    s = *(Il2CppString**)((uint8_t*)o + field->offset);
                    if (s != NULL)
                        result ^= vm::String::GetHash(s);
                    break;
                }
                case IL2CPP_TYPE_PTR:
                    result ^= il2cpp::utils::HashUtils::AlignedPointerHash(*(void**)((uint8_t*)o + field->offset));
                    break;
                default:
                    if (!values)
                        values = (Il2CppObject**)alloca(sizeof(Il2CppObject*) * vm::Class::GetNumFields(klass));
                    Il2CppObject* val = vm::Field::GetValueObject(field, o);
                    values[count++] = val;
            }
        }

        if (values)
        {
            int i;
            il2cpp::gc::WriteBarrier::GenericStore(fields, vm::Array::New(il2cpp_defaults.object_class, count));
            for (i = 0; i < count; ++i)
                il2cpp_array_setref(*fields, i, values[i]);
        }
        else
        {
            *fields = NULL;
        }

        return result;
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
