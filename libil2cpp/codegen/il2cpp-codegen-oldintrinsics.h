#if !MONO_NET8_BCL
#pragma once

#include "il2cpp-config.h"

#include "il2cpp-codegen-metadata.h"
#include "il2cpp-object-internals.h"
#include "vm-utils/VmThreadUtils.h"

#include <cmath>

// NativeArray macros
#define IL2CPP_NATIVEARRAY_GET_ITEM(TElementType, TTField, TIndex) \
    *(reinterpret_cast<TElementType*>(TTField) + TIndex)

#define IL2CPP_NATIVEARRAY_SET_ITEM(TElementType, TTField, TIndex, TValue) \
   *(reinterpret_cast<TElementType*>(TTField) + TIndex) = TValue;

#define IL2CPP_NATIVEARRAY_GET_LENGTH(TLengthField) \
   (TLengthField)

Type_t* il2cpp_codegen_object_get_type(RuntimeObject* obj);

inline int32_t il2cpp_codegen_array_get_rank(RuntimeArray* array)
{
    return array->klass->rank;
}

inline int32_t il2cpp_codegen_array_get_length(RuntimeArray* array)
{
    return (int32_t)array->max_length;
}

inline int32_t il2cpp_codegen_array_get_element_size(RuntimeArray* array)
{
    return (int32_t)array->klass->element_size;
}

inline int32_t il2cpp_codegen_abs(int32_t value)
{
    return abs(value);
}

inline int64_t il2cpp_codegen_abs(int64_t value)
{
    return llabs(value);
}

inline bool il2cpp_codegen_object_reference_equals(const RuntimeObject *obj1, const RuntimeObject *obj2)
{
    return obj1 == obj2;
}

intptr_t il2cpp_codegen_get_com_interface_for_object(Il2CppObject* object, Type_t* type);

inline bool il2cpp_codegen_platform_disable_libc_pinvoke()
{
    return IL2CPP_PLATFORM_DISABLE_LIBC_PINVOKE;
}

inline bool il2cpp_codegen_platform_is_osx_or_ios()
{
    return IL2CPP_TARGET_OSX != 0 || IL2CPP_TARGET_IOS != 0;
}

inline bool il2cpp_codegen_platform_is_freebsd()
{
    // we don't currently support FreeBSD
    return false;
}

inline bool il2cpp_codegen_platform_is_uwp()
{
    return IL2CPP_TARGET_WINRT != 0;
}

MethodBase_t* il2cpp_codegen_get_method_object(const RuntimeMethod* method);

Type_t* il2cpp_codegen_get_type(String_t* typeName, const RuntimeMethod* callingMethod);
Type_t* il2cpp_codegen_get_type(String_t* typeName, bool throwOnError, const RuntimeMethod* callingMethod);
Type_t* il2cpp_codegen_get_type(String_t* typeName, bool throwOnError, bool ignoreCase, const RuntimeMethod* callingMethod);

intptr_t il2cpp_codegen_com_get_iunknown_for_object(RuntimeObject* obj);

RuntimeObject* il2cpp_codegen_com_get_object_for_iunknown(intptr_t pUnk);

Assembly_t* il2cpp_codegen_get_executing_assembly(const RuntimeMethod* method);

inline void GetGenericValueImpl(RuntimeArray* thisPtr, int32_t pos, void* value)
{
    // GetGenericValueImpl is only called from the class libs internally and T is never a field
    IL2CPP_ASSERT_STACK_PTR(value);
    memcpy(value, il2cpp_array_addr_with_size(thisPtr, thisPtr->klass->element_size, pos), thisPtr->klass->element_size);
}

void SetGenericValueImpl(RuntimeArray* thisPtr, int32_t pos, void* value);

template<typename T>
inline T il2cpp_unsafe_read_unaligned(void* location)
{
    T result;
#if IL2CPP_TARGET_ARMV7 || IL2CPP_TARGET_JAVASCRIPT
    memcpy(&result, location, sizeof(T));
#else
    result = *((T*)location);
#endif
    return result;
}

template<typename T>
inline void il2cpp_unsafe_write_unaligned(void* location, T value)
{
#if IL2CPP_TARGET_ARMV7 || IL2CPP_TARGET_JAVASCRIPT
    memcpy(location, &value, sizeof(T));
#else
    *((T*)location) = value;
#endif
}

inline void il2cpp_unsafe_skip_init(void* value)
{
    // does nothing as we are skipping initialization
}

template<typename T>
inline T il2cpp_unsafe_read(void* location)
{
    return *((T*)location);
}

template<typename T>
inline void il2cpp_unsafe_write(void* location, T value)
{
    *((T*)location) = value;
}

template<typename T, typename TOffset>
inline T* il2cpp_unsafe_add_byte_offset(void* source, TOffset offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) + offset);
}

template<typename T, typename TOffset>
inline T* il2cpp_unsafe_add(void* source, TOffset offset, size_t elementSize)
{
    return il2cpp_unsafe_add_byte_offset<T>(source, offset * elementSize);
}

template<typename T, typename TOffset>
inline T* il2cpp_unsafe_subtract_byte_offset(void* source, TOffset offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) - offset);
}

template<typename T, typename TOffset>
inline T* il2cpp_unsafe_subtract(void* source, TOffset offset, size_t elementSize)
{
    return il2cpp_unsafe_subtract_byte_offset<T>(source, offset * elementSize);
}

template<typename T>
inline T il2cpp_unsafe_as(void* source)
{
    return reinterpret_cast<T>(source);
}

template<typename T>
inline T* il2cpp_unsafe_as_ref(void* source)
{
    return reinterpret_cast<T*>(source);
}

inline void* il2cpp_unsafe_as_pointer(void* source)
{
    return source;
}

template<typename T>
inline T* il2cpp_unsafe_null_ref()
{
    return reinterpret_cast<T*>(NULL);
}

inline bool il2cpp_unsafe_are_same(void* left, void* right)
{
    return left == right;
}

inline bool il2cpp_unsafe_is_addr_gt(void* left, void* right)
{
    return left > right;
}

inline bool il2cpp_unsafe_is_addr_lt(void* left, void* right)
{
    return left < right;
}

inline bool il2cpp_unsafe_is_null_ref(void* source)
{
    return source == NULL;
}

template<typename T>
inline int32_t il2cpp_unsafe_sizeof()
{
    return sizeof(T);
}

inline intptr_t il2cpp_unsafe_byte_offset(void* origin, void* target)
{
    return reinterpret_cast<uint8_t*>(target) - reinterpret_cast<uint8_t*>(origin);
}

template<typename T>
inline void* il2cpp_codegen_unsafe_cast(T* ptr)
{
    return reinterpret_cast<void*>(ptr);
}

bool il2cpp_codegen_is_unmanaged(const RuntimeMethod* method);

inline void il2cpp_codegen_runtime_helpers_initialize_array(RuntimeArray* array, const Il2CppFieldRvaData& rvaData)
{
    IL2CPP_ASSERT(array);
    IL2CPP_ASSERT(array->klass->element_class->byval_arg.valuetype && !array->klass->element_class->has_references);

    memcpy(il2cpp_array_addr_with_size(array, 0, 0), rvaData.data, rvaData.size);
}

#endif
