#include "il2cpp-config.h"
#include "Array.h"

#include "gc/GarbageCollector.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "utils/Exception.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Object.h"
#include "vm/Type.h"
#include "metadata/ArrayMetadata.h"
#include <memory>
#include <vector>

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
    // Copied from CoreCLR: https://github.com/dotnet/runtime/blob/402aa8584ed18792d6bc6ed1869f7c31b38f8139/src/coreclr/vm/invokeutil.cpp#L31
    const uint32_t PT_Primitive = 0x01000000;

    static const uint32_t primitive_conversions[] = {
        0x00,                   // IL2CPP_TYPE_END
        0x00,                   // IL2CPP_TYPE_VOID
        PT_Primitive | 0x0004,  // IL2CPP_TYPE_BOOLEAN
        PT_Primitive | 0x3F88,  // IL2CPP_TYPE_CHAR (W = U2, CHAR, I4, U4, I8, U8, R4, R8)
        PT_Primitive | 0x3550,  // IL2CPP_TYPE_I1   (W = I1, I2, I4, I8, R4, R8)
        PT_Primitive | 0x3FE8,  // IL2CPP_TYPE_U1   (W = CHAR, U1, I2, U2, I4, U4, I8, U8, R4, R8)
        PT_Primitive | 0x3540,  // IL2CPP_TYPE_I2   (W = I2, I4, I8, R4, R8)
        PT_Primitive | 0x3F88,  // IL2CPP_TYPE_U2   (W = U2, CHAR, I4, U4, I8, U8, R4, R8)
        PT_Primitive | 0x3500,  // IL2CPP_TYPE_I4   (W = I4, I8, R4, R8)
        PT_Primitive | 0x3E00,  // IL2CPP_TYPE_U4   (W = U4, I8, R4, R8)
        PT_Primitive | 0x3400,  // IL2CPP_TYPE_I8   (W = I8, R4, R8)
        PT_Primitive | 0x3800,  // IL2CPP_TYPE_U8   (W = U8, R4, R8)
        PT_Primitive | 0x3000,  // IL2CPP_TYPE_R4   (W = R4, R8)
        PT_Primitive | 0x2000,  // IL2CPP_TYPE_R8   (W = R8)
    };

    // Copied from CoreCLR: https://github.com/dotnet/runtime/blob/402aa8584ed18792d6bc6ed1869f7c31b38f8139/src/coreclr/vm/invokeutil.h#L119
    static bool can_primitive_widen(Il2CppTypeEnum src_type, Il2CppTypeEnum dest_type)
    {
        if (dest_type > IL2CPP_TYPE_R8 || src_type > IL2CPP_TYPE_R8)
        {
            return (IL2CPP_TYPE_I == dest_type && IL2CPP_TYPE_I == src_type) || (IL2CPP_TYPE_U == dest_type && IL2CPP_TYPE_U == src_type);
        }
        return ((1 << dest_type) & primitive_conversions[src_type]) != 0;
    }

    static void ThrowNoWidening()
    {
        vm::Exception::Raise(vm::Exception::GetArgumentException("value", "not a widening conversion"));
    }

    static void ThrowInvalidCast(const Il2CppClass* a, const Il2CppClass* b)
    {
        vm::Exception::Raise(vm::Exception::GetInvalidCastException(utils::Exception::FormatInvalidCastException(b, a).c_str()));
    }

    union WidenedValueUnion
    {
        int64_t i64;
        uint64_t u64;
        double r64;
    };

    WidenedValueUnion ExtractWidenedValue(Il2CppTypeEnum type, void* value)
    {
        WidenedValueUnion extractedValue = { 0 };
        switch (type)
        {
            case IL2CPP_TYPE_U1:
                extractedValue.u64 = *(uint8_t*)value;
                break;
            case IL2CPP_TYPE_CHAR:
                extractedValue.u64 = *(Il2CppChar*)value;
                break;
            case IL2CPP_TYPE_U2:
                extractedValue.u64 = *(uint16_t*)value;
                break;
            case IL2CPP_TYPE_U4:
                extractedValue.u64 = *(uint32_t*)value;
                break;
            case IL2CPP_TYPE_U8:
                extractedValue.u64 = *(uint64_t*)value;
                break;
            case IL2CPP_TYPE_I1:
                extractedValue.i64 = *(int8_t*)value;
                break;
            case IL2CPP_TYPE_I2:
                extractedValue.i64 = *(int16_t*)value;
                break;
            case IL2CPP_TYPE_I4:
                extractedValue.i64 = *(int32_t*)value;
                break;
            case IL2CPP_TYPE_I8:
                extractedValue.i64 = *(int64_t*)value;
                break;
            case IL2CPP_TYPE_R4:
                extractedValue.r64 = *(float*)value;
                break;
            case IL2CPP_TYPE_R8:
                extractedValue.r64 = *(double*)value;
                break;
            default:
                IL2CPP_ASSERT(0);
                break;
        }

        return extractedValue;
    }

    static void CheckWideningConversion(size_t elementSize, size_t valueSize, size_t extra = 0)
    {
        if (elementSize < valueSize + (extra))
            ThrowNoWidening();
    }

    template<typename T>
    static void AssignUnsigned(WidenedValueUnion value, void* elementAddress, Il2CppTypeEnum valueType, size_t elementSize, size_t valueSize, bool strictSigns)
    {
        switch (valueType)
        {
            case IL2CPP_TYPE_U1:
            case IL2CPP_TYPE_U2:
            case IL2CPP_TYPE_U4:
            case IL2CPP_TYPE_U8:
            case IL2CPP_TYPE_CHAR:
                CheckWideningConversion(elementSize, valueSize);
                *(T*)elementAddress = (T)value.u64;
                break;
            /* You can't assign a signed value to an unsigned array. */
            case IL2CPP_TYPE_I1:
            case IL2CPP_TYPE_I2:
            case IL2CPP_TYPE_I4:
            case IL2CPP_TYPE_I8:
                if (strictSigns)
                    ThrowNoWidening();
                CheckWideningConversion(elementSize, valueSize, 1);
                *(T*)elementAddress = (T)value.i64;
                break;
            /* You can't assign a floating point number to an integer array. */
            case IL2CPP_TYPE_R4:
            case IL2CPP_TYPE_R8:
                ThrowNoWidening();
                break;
            default:
                IL2CPP_ASSERT(0);
                break;
        }
    }

    template<typename T>
    static void AssignSigned(WidenedValueUnion value, void* elementAddress, Il2CppTypeEnum valueType, size_t elementSize, size_t valueSize, bool strictSigns)
    {
        switch (valueType)
        {
            /* You can assign an unsigned value to a signed array if the array's
                element size is larger than the value size. */
            case IL2CPP_TYPE_U1:
            case IL2CPP_TYPE_U2:
            case IL2CPP_TYPE_U4:
            case IL2CPP_TYPE_U8:
            case IL2CPP_TYPE_CHAR:
                CheckWideningConversion(elementSize, valueSize, strictSigns ? 1 : 0);
                *(T*)elementAddress = (T)value.u64;
                break;
            case IL2CPP_TYPE_I1:
            case IL2CPP_TYPE_I2:
            case IL2CPP_TYPE_I4:
            case IL2CPP_TYPE_I8:
                CheckWideningConversion(elementSize, valueSize);
                *(T*)elementAddress = (T)value.i64;
                break;
            /* You can't assign a floating point number to an integer array. */
            case IL2CPP_TYPE_R4:
            case IL2CPP_TYPE_R8:
                ThrowNoWidening();
                break;
            default:
                IL2CPP_ASSERT(0);
                break;
        }
    }

    template<typename T>
    static void AssignReal(WidenedValueUnion value, void* elementAddress, Il2CppTypeEnum valueType, size_t elementSize, size_t valueSize)
    {
        switch (valueType)
        {
            /* All integers fit into the floating point value range. No need to check size. */
            case IL2CPP_TYPE_U1:
            case IL2CPP_TYPE_U2:
            case IL2CPP_TYPE_U4:
            case IL2CPP_TYPE_U8:
            case IL2CPP_TYPE_CHAR:
                *(T*)elementAddress = (T)value.u64;
                break;
            case IL2CPP_TYPE_I1:
            case IL2CPP_TYPE_I2:
            case IL2CPP_TYPE_I4:
            case IL2CPP_TYPE_I8:
                *(T*)elementAddress = (T)value.i64;
                break;
            case IL2CPP_TYPE_R4:
            case IL2CPP_TYPE_R8:
                CheckWideningConversion(elementSize, valueSize);
                *(T*)elementAddress = (T)value.r64;
                break;
            default:
                IL2CPP_ASSERT(0);
                break;
        }
    }

    bool Array::CanChangePrimitive(Il2CppObjectHandleOnStack srcType, Il2CppObjectHandleOnStack dstType, bool reliable)
    {
        Il2CppClass* srcClass = vm::Class::FromIl2CppType(((Il2CppReflectionType*)srcType)->type);
        Il2CppClass* dstClass = vm::Class::FromIl2CppType(((Il2CppReflectionType*)dstType)->type);

        Il2CppClass* srcReducedClass = metadata::ArrayMetadata::GetArrayVarianceReducedType(srcClass);
        Il2CppClass* dstReducedClass = metadata::ArrayMetadata::GetArrayVarianceReducedType(dstClass);

        if (srcReducedClass == dstReducedClass)
            return true;

        if (reliable)
            return false;

        return can_primitive_widen(vm::Class::GetType(srcClass)->type, vm::Class::GetType(dstClass)->type);
    }

    bool Array::FastCopy(Il2CppObjectHandleOnStack source, int32_t source_idx, Il2CppObjectHandleOnStack dest, int32_t dest_idx, int32_t length)
    {
        int element_size;
        Il2CppClass *src_class;
        Il2CppClass *dest_class;
        int i;

        if (source->klass->rank != dest->klass->rank)
            return false;

        if (((Il2CppArray*)source)->bounds || ((Il2CppArray*)dest)->bounds)
            return false;

        // Our max array length is il2cpp_array_size_t, which is currently int32_t,
        // so Array::GetLength will never return more than 2^31 - 1
        // Therefore, casting sum to uint32_t is safe even if it overflows - it if does,
        // the comparison will succeed and this function will return false
        if ((static_cast<uint32_t>(dest_idx + length) > il2cpp::vm::Array::GetLength((Il2CppArray*)dest)) ||
            (static_cast<uint32_t>(source_idx + length) > il2cpp::vm::Array::GetLength((Il2CppArray*)source)))
            return false;

        src_class = source->klass->element_class;
        dest_class = dest->klass->element_class;

        // object[] -> valuetype[]
        if (src_class == il2cpp_defaults.object_class && dest_class->byval_arg.valuetype)
        {
            for (i = source_idx; i < source_idx + length; ++i)
            {
                Il2CppObject *elem = il2cpp_array_get((Il2CppArray*)source, Il2CppObject*, i);
                if (elem && !vm::Object::IsInst(elem, dest_class))
                    return false;
            }

            element_size = il2cpp_array_element_size(dest->klass);
            void *baseAddr = il2cpp_array_addr_with_size((Il2CppArray*)dest, element_size, dest_idx);

            size_t byte_len = (size_t)length * element_size;
            memset(baseAddr, 0, byte_len);

            for (i = 0; i < length; ++i)
            {
                Il2CppObject *elem = il2cpp_array_get((Il2CppArray*)source, Il2CppObject*, source_idx + (size_t)i);

                if (!elem)
                    vm::Exception::Raise(vm::Exception::GetInvalidCastException("At least one element in the source array could not be cast down to the destination array type."));

                memcpy(il2cpp_array_addr_with_size((Il2CppArray*)dest, element_size, dest_idx + (size_t)i), vm::Object::GetRawData(elem), element_size);
            }
            gc::GarbageCollector::SetWriteBarrier((void**)baseAddr, byte_len);

            return true;
        }

        if (src_class != dest_class)
        {
            if (vm::Class::IsValuetype(dest_class) || vm::Class::IsEnum(dest_class) || vm::Class::IsValuetype(src_class) || vm::Class::IsEnum(src_class))
                return false;

            // object[] -> reftype[]
            if (vm::Class::IsSubclassOf(dest_class, src_class, false))
            {
                for (i = source_idx; i < source_idx + length; ++i)
                {
                    Il2CppObject *elem = il2cpp_array_get((Il2CppArray*)source, Il2CppObject*, i);
                    if (elem && !vm::Object::IsInst(elem, dest_class))
                        vm::Exception::Raise(vm::Exception::GetInvalidCastException("At least one element in the source array could not be cast down to the destination array type."));
                }
            }
            else if (!vm::Class::IsSubclassOf(src_class, dest_class, false))
                return false;

            // derivedtype[] -> basetype[]
            IL2CPP_ASSERT(vm::Type::IsReference(&src_class->byval_arg));
            IL2CPP_ASSERT(vm::Type::IsReference(&dest_class->byval_arg));
        }

        element_size = il2cpp_array_element_size(dest->klass);

        IL2CPP_ASSERT(element_size == il2cpp_array_element_size(source->klass));

        size_t byte_len = (size_t)length * element_size;

        memmove(
            il2cpp_array_addr_with_size((Il2CppArray*)dest, element_size, dest_idx),
            il2cpp_array_addr_with_size((Il2CppArray*)source, element_size, source_idx),
            byte_len);

        gc::GarbageCollector::SetWriteBarrier((void**)il2cpp_array_addr_with_size((Il2CppArray*)dest, element_size, dest_idx), byte_len);

        return true;
    }

    bool Array::IsValueOfElementTypeInternal(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack obj)
    {
        return vm::Object::GetClass(arr)->element_class == vm::Object::GetClass(obj);
    }

    int32_t Array::GetLengthInternal(Il2CppObjectHandleOnStack arr, int32_t dimension)
    {
        Il2CppArray* thisPtr = (Il2CppArray*)arr;

        int32_t rank = thisPtr->klass->rank;
        il2cpp_array_size_t length;

        if ((dimension < 0) || (dimension >= rank))
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetIndexOutOfRangeException());

        if (thisPtr->bounds == NULL)
            length = thisPtr->max_length;
        else
            length = thisPtr->bounds[dimension].length;

#ifdef IL2CPP_BIG_ARRAYS
        if (length > G_MAXINT32)
            mono_raise_exception(mono_get_exception_overflow());
#endif
        return ARRAY_LENGTH_AS_INT32(length);
    }

    int32_t Array::GetLowerBoundInternal(Il2CppObjectHandleOnStack arr, int32_t dimension)
    {
        Il2CppArray* thisPtr = (Il2CppArray*)arr;

        int32_t rank = thisPtr->klass->rank;

        if ((dimension < 0) || (dimension >= rank))
            vm::Exception::Raise(vm::Exception::GetIndexOutOfRangeException());

        if (thisPtr->bounds == NULL)
            return false;

        return thisPtr->bounds[dimension].lower_bound;
    }

    uint8_t Array::GetCorElementTypeOfElementTypeInternal(Il2CppObjectHandleOnStack arr)
    {
        return vm::Class::GetType(vm::Object::GetClass(arr)->element_class)->type;
    }

    void Array::GetValueImpl(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack res, int32_t pos)
    {
        Il2CppClass* typeInfo = arr->klass;
        void **ea;

        ea = (void**)il2cpp_array_addr_with_size((Il2CppArray*)arr, pos, typeInfo->element_size);

        if (typeInfo->element_class->byval_arg.valuetype)
            res = il2cpp::vm::Object::Box(typeInfo->element_class, ea);
        else
            res = (Il2CppObject*)*ea;
    }

    void Array::InitializeInternal(Il2CppObjectHandleOnStack arr)
    {
        Il2CppClass* elementClass = arr->klass->element_class;
        if (!vm::Class::IsValuetype(elementClass))
            return;

        const MethodInfo* ctor = vm::Class::GetMethodFromName(elementClass, ".ctor", 0);
        if (!ctor)
            return;

        Il2CppArray* array = (Il2CppArray*)arr;

        size_t elementSize = elementClass->instance_size - sizeof(Il2CppObject);

        typedef void(*default_ctor_sig)(void*, MethodInfo*);
        default_ctor_sig default_ctor = (default_ctor_sig)ctor->methodPointer;

        uint32_t arrayLength = il2cpp::vm::Array::GetLength(array);
        for (uint32_t i = 0; i < arrayLength; i++)
        {
            void* elementPtr = (void*)il2cpp_array_addr_with_size(array, i, elementSize);
            default_ctor(elementPtr, NULL);
        }
    }

    void Array::InternalCreate(Il2CppArray** result, intptr_t elementType, int32_t rank, int32_t* lengths, int32_t* lowerBounds)
    {
        Il2CppClass* elementClass = vm::Class::FromIl2CppType((Il2CppType*)elementType);

        bool isSzArray = rank == 1 && (lowerBounds == NULL || lowerBounds[0] == 0);
        Il2CppClass* arrrayClass = vm::Class::GetBoundedArrayClass(elementClass, rank, !isSzArray);

        il2cpp_array_size_t* arrayLengths = (il2cpp_array_size_t*)alloca(sizeof(il2cpp_array_size_t) * rank);
        il2cpp_array_size_t* arrayBounds = lowerBounds ? (il2cpp_array_size_t*)alloca(sizeof(il2cpp_array_size_t) * rank) : NULL;
        for (int32_t i = 0; i < rank; i++)
        {
            arrayLengths[i] = lengths[i];
            if (lowerBounds)
                arrayBounds[i] = lowerBounds[i];
        }

        *result = il2cpp::vm::Array::NewFull(arrrayClass, arrayLengths, arrayBounds);
    }

    static void ArraySetValueImpl(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack value, int32_t pos, bool strictEnums, bool strictSigns)
    {
        Il2CppClass* typeInfo = arr->klass;
        Il2CppClass* elementClass = vm::Class::GetElementClass(typeInfo);

        int elementSize = vm::Class::GetArrayElementSize(elementClass);
        void* elementAddress = il2cpp_array_addr_with_size((Il2CppArray*)arr, elementSize, pos);

        if (vm::Class::IsNullable(elementClass))
        {
            vm::Object::NullableInit((uint8_t*)elementAddress, value, elementClass);
            return;
        }

        if ((Il2CppObject*)value == NULL)
        {
            memset(elementAddress, 0, elementSize);
            return;
        }

        if (!vm::Class::IsValuetype(elementClass))
        {
            if (!vm::Object::IsInst(value, elementClass))
                vm::Exception::Raise(vm::Exception::GetInvalidCastException(utils::Exception::FormatInvalidCastException(arr->klass->element_class, value->klass).c_str()));
            il2cpp_array_setref((Il2CppArray*)arr, pos, value);
            return;
        }

        if (vm::Object::IsInst(value, elementClass))
        {
            memcpy(elementAddress, vm::Object::GetRawData(value), elementSize);
            gc::GarbageCollector::SetWriteBarrier((void**)elementAddress, elementSize);
            return;
        }

        Il2CppClass* valueClass = vm::Object::GetClass(value);

        if (!vm::Class::IsValuetype(valueClass))
            ThrowInvalidCast(elementClass, valueClass);

        if (strictEnums && vm::Class::IsEnum(elementClass) && !vm::Class::IsEnum(valueClass))
            ThrowInvalidCast(elementClass, valueClass);

        Il2CppTypeEnum elementType = vm::Class::IsEnum(elementClass) ? vm::Class::GetEnumBaseType(elementClass)->type : elementClass->byval_arg.type;
        Il2CppTypeEnum valueType = vm::Class::IsEnum(valueClass) ? vm::Class::GetEnumBaseType(valueClass)->type : valueClass->byval_arg.type;

        if (elementType == IL2CPP_TYPE_BOOLEAN)
        {
            switch (valueType)
            {
                case IL2CPP_TYPE_BOOLEAN:
                    break;
                case IL2CPP_TYPE_CHAR:
                case IL2CPP_TYPE_U1:
                case IL2CPP_TYPE_U2:
                case IL2CPP_TYPE_U4:
                case IL2CPP_TYPE_U8:
                case IL2CPP_TYPE_I1:
                case IL2CPP_TYPE_I2:
                case IL2CPP_TYPE_I4:
                case IL2CPP_TYPE_I8:
                case IL2CPP_TYPE_R4:
                case IL2CPP_TYPE_R8:
                    ThrowNoWidening();
                default:
                    ThrowInvalidCast(elementClass, valueClass);
            }
        }

        WidenedValueUnion widenedValue = ExtractWidenedValue(valueType, vm::Object::GetRawData(value));

        int valueSize = vm::Class::GetInstanceSize(valueClass) - sizeof(Il2CppObject);

        switch (elementType)
        {
            case IL2CPP_TYPE_U1:
                AssignUnsigned<uint8_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_CHAR:
                AssignUnsigned<Il2CppChar>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_U2:
                AssignUnsigned<uint16_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_U4:
                AssignUnsigned<uint32_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_U8:
                AssignUnsigned<uint64_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_I1:
                AssignSigned<int8_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_I2:
                AssignSigned<int16_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_I4:
                AssignSigned<int32_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_I8:
                AssignSigned<int64_t>(widenedValue, elementAddress, valueType, elementSize, valueSize, strictSigns);
                break;
            case IL2CPP_TYPE_R4:
                AssignReal<float>(widenedValue, elementAddress, valueType, elementSize, valueSize);
                break;
            case IL2CPP_TYPE_R8:
                AssignReal<double>(widenedValue, elementAddress, valueType, elementSize, valueSize);
                break;
            default:
                ThrowInvalidCast(elementClass, valueClass);
                break;
        }
    }

    void Array::SetValueImpl(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack value, int32_t pos)
    {
        ArraySetValueImpl(arr, value, pos, true, true);
    }

    void Array::SetValueRelaxedImpl(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack value, int32_t pos)
    {
        ArraySetValueImpl(arr, value, pos, false, false);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
