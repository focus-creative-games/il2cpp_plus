#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
#include "RuntimeHelpers_icalls.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Runtime
{
namespace CompilerServices
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.RuntimeHelpers::IsBitwiseEquatable()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_runtime_helpers_is_bitwise_equatable()
    {
        IL2CPP_NOT_IMPLEMENTED_INTRINSIC_OPTIONAL_FIXME(il2cpp_intrinsic_runtime_helpers_is_bitwise_equatable);
        // TODO: This should be implemented with a conversion time check
        return false;
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.RuntimeHelpers::ObjectHasComponentSize(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_runtime_helpers_object_has_component_size(RuntimeObject* obj)
    {
        switch (obj->klass->byval_arg.type)
        {
            case IL2CPP_TYPE_STRING:
            case IL2CPP_TYPE_ARRAY:
            case IL2CPP_TYPE_SZARRAY:
                return true;
            default:
                return false;
        }
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.CompilerServices.RuntimeHelpers::get_OffsetToStringData()
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_runtime_helpers_get_offset_to_string_data()
    {
        return offsetof(RuntimeString, chars);
    }

    /* METHOD MAPPING
        Method: System.Byte& System.Runtime.CompilerServices.RuntimeHelpers::GetRawData(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    inline uint8_t* il2cpp_intrinsic_runtime_helpers_get_raw_data(RuntimeObject* obj)
    {
        return il2cpp_codegen_get_raw_data<uint8_t>(obj);
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.RuntimeHelpers::IsReferenceOrContainsReferences()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_runtime_helpers_is_reference_or_contains_references(const RuntimeMethod* method)
    {
        return il2cpp_codegen_is_reference_or_contains_references(method);
    }

    /* METHOD MAPPING
        Method: System.ReadOnlySpan`1<T> System.Runtime.CompilerServices.RuntimeHelpers::CreateSpan(System.RuntimeFieldHandle)
        AssemblyName: System.Private.CoreLib
    */
    template<typename TReadOnlySpan, typename TRuntimeFieldHandle>
    inline TReadOnlySpan il2cpp_intrinsic_runtime_helpers_create_span(const Il2CppFieldRvaData& rvaData, size_t elementSize)
    {
        return il2cpp_intrinsic_runtime_helpers_create_span<TReadOnlySpan>(rvaData.data, rvaData.size, elementSize);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray(System.Array,System.RuntimeFieldHandle)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_runtime_helpers_initialize_array(RuntimeArray* array, const Il2CppFieldRvaData& rvaData)
    {
        IL2CPP_ASSERT(array);
        IL2CPP_ASSERT(il2cpp_codegen_class_is_value_type(array->klass->element_class) && !array->klass->element_class->has_references);

        memcpy(il2cpp_array_addr_with_size(array, 0, 0), rvaData.data, rvaData.size);
    }

    /* METHOD MAPPING
        Method: System.Void* System.Runtime.CompilerServices.RuntimeHelpers::GetSpanDataFrom(System.RuntimeFieldHandle,System.RuntimeTypeHandle,System.Int32&)
        AssemblyName: System.Private.CoreLib
    */
    inline void* il2cpp_intrinsic_runtime_helpers_get_span_data_from(const Il2CppFieldRvaData& rvaData, size_t elementSize, int32_t* count)
    {
        IL2CPP_ASSERT(rvaData.size % elementSize == 0);

        *count = (int32_t)(rvaData.size / elementSize);
        return (void*)rvaData.data;
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.RuntimeHelpers::ObjectHasReferences(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_runtime_helpers_object_has_references(RuntimeObject* obj)
    {
        NullCheck(obj);
        return obj->klass->has_references;
    }
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
