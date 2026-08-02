#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
#include "vm/Array.h"
#include "vm-utils/VmThreadUtils.h"
#include "ArrayVariations.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
    /* METHOD MAPPING
        Method: System.Int32 System.Array::get_Length()
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_array_get_length(RuntimeArray* array)
    {
        return (int32_t)array->max_length;
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Array::get_Rank()
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_array_get_rank(RuntimeArray* array)
    {
        return array->klass->rank;
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Array::GetElementSize()
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_array_get_element_size(RuntimeArray* array)
    {
        return (int32_t)array->klass->element_size;
    }

    /* METHOD MAPPING
        Method: System.Void System.Array::GetGenericValueImpl(System.Int32,T&)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_array_get_generic_value_impl(RuntimeArray* thisPtr, int32_t pos, void* value)
    {
        // GetGenericValueImpl is only called from the class libs internally and T is never a field
        IL2CPP_ASSERT_STACK_PTR(value);
        memcpy(value, il2cpp_array_addr_with_size(thisPtr, thisPtr->klass->element_size, pos), thisPtr->klass->element_size);
    }

    /* METHOD MAPPING
        Method: System.Void System.Array::GetGenericValue_icall(System.Runtime.CompilerServices.ObjectHandleOnStack,System.Int32,T&)
        AssemblyName: System.Private.CoreLib
    */
    template<typename THandleOnStack, typename TValue>
    inline void il2cpp_intrinsic_array_get_generic_value_icall(THandleOnStack self, int32_t pos, TValue* value)
    {
        il2cpp_codegen_get_generic_value_icall(self, pos, value);
    }

    /* METHOD MAPPING
        Method: System.Void System.Array::SetGenericValueImpl(System.Int32,T&)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_array_set_generic_value_impl(RuntimeArray* thisPtr, int32_t pos, void* value)
    {
        il2cpp_array_setrefwithsize(thisPtr, thisPtr->klass->element_size, pos, value);
    }

    /* METHOD MAPPING
        Method: System.Void System.Array::SetGenericValue_icall(System.Runtime.CompilerServices.ObjectHandleOnStack,System.Int32,T&)
        AssemblyName: System.Private.CoreLib
    */
    template<typename THandleOnStack, typename TValue>
    inline void il2cpp_intrinsic_array_set_generic_value_icall(THandleOnStack arr, int32_t pos, TValue* value)
    {
        il2cpp_codegen_set_generic_value_icall(arr, pos, value);
    }
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
