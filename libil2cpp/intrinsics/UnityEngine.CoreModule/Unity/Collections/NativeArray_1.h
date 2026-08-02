#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"

// // NativeArray macros
// #define IL2CPP_NATIVEARRAY_GET_ITEM(TElementType, TTField, TIndex) \
//     *(reinterpret_cast<TElementType*>(TTField) + TIndex)

// #define IL2CPP_NATIVEARRAY_SET_ITEM(TElementType, TTField, TIndex, TValue) \
//    *(reinterpret_cast<TElementType*>(TTField) + TIndex) = TValue;

// #define IL2CPP_NATIVEARRAY_GET_LENGTH(TLengthField) \
//    (TLengthField)

namespace il2cpp
{
namespace intrinsics
{
namespace UnityEngine_CoreModule
{
namespace Unity
{
namespace Collections
{
    /* METHOD MAPPING
        Method: System.Int32 Unity.Collections.NativeArray`1::get_Length()
        AssemblyName: UnityEngine.CoreModule
    */
    inline int32_t il2cpp_intrinsic_native_array_1_get_length(int32_t length)
    {
        return length;
    }

    /* METHOD MAPPING
        Method: System.Void Unity.Collections.NativeArray`1::set_Item(System.Int32,T)
        AssemblyName: UnityEngine.CoreModule
    */
    template<typename T>
    inline void il2cpp_intrinsic_native_array_1_set_item(void* buffer, int32_t index, T value)
    {
        *(reinterpret_cast<T*>(buffer) + index) = value;
    }

    /* METHOD MAPPING
        Method: T Unity.Collections.NativeArray`1::get_Item(System.Int32)
        AssemblyName: UnityEngine.CoreModule
    */
    template<typename T>
    inline T il2cpp_intrinsic_native_array_1_get_item(void* buffer, int32_t index)
    {
        return *(reinterpret_cast<T*>(buffer) + index);
    }
} // namespace Collections
} // namespace Unity
} // namespace UnityEngine_CoreModule
} // namespace intrinsics
} // namespace il2cpp
