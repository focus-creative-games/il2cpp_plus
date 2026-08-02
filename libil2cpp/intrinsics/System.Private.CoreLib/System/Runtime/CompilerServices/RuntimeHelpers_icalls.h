#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
#include "RuntimeHelpers.h"

// This file implements "intrinsics" for some System.Runtime.CompilerServices.RuntimeHelpers method
// These methods are sometimes replaces replaced with true intrinsics - where the field/type loads
// are done at runtime (these intrinsics are in RuntimeHelpers.h)
// But our intrinsic remap doesn't handle something sometimes being an intrinsic and sometimes not
// so we handle this with overloads of the intrinsics that just redirect back to the icall

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
    const char* runtime_helpers_get_field_data(FieldInfo* field, size_t* dataSize);
    void runtime_helpers_initialize_array_icall(RuntimeArray* array, RuntimeField* fldHandle);
    void* runtime_helpers_get_span_data_from_icall(RuntimeField* fldHandle, Il2CppType* targetTypeHandle, int32_t* count);

    template<typename TReadOnlySpan>
    inline TReadOnlySpan il2cpp_intrinsic_runtime_helpers_create_span(const char* data, size_t size, size_t elementSize)
    {
#if IL2CPP_BYTE_ORDER != IL2CPP_LITTLE_ENDIAN
        // The data is encoded little endian, if bit endian support is needed a byte swap will be needed
        IL2CPP_NOT_IMPLEMENTED_INTRINSIC(il2cpp_intrinsic_runtime_helpers_create_span)
#endif
        struct SpanData
        {
            const char* reference;
            int32_t length;
        };

        static_assert(sizeof(SpanData) == sizeof(TReadOnlySpan), "Mismatch in SpanData layout");

        SpanData d = {};
        d.reference = data;
        d.length = (int)(size / elementSize);

        TReadOnlySpan span;
        memcpy(&span, &d, sizeof(TReadOnlySpan));
        return span;
    }

    template<typename TReadOnlySpan, typename TRuntimeFieldHandle>
    inline TReadOnlySpan il2cpp_intrinsic_runtime_helpers_create_span(TRuntimeFieldHandle fldHandle, size_t elementSize)
    {
        RuntimeField* field = *reinterpret_cast<RuntimeField**>(&fldHandle);
        size_t size;
        const char* data = runtime_helpers_get_field_data(field, &size);
        return il2cpp_intrinsic_runtime_helpers_create_span<TReadOnlySpan>(data, size, elementSize);
    }

    template<typename TRuntimeFieldHandle>
    void il2cpp_intrinsic_runtime_helpers_initialize_array(RuntimeArray* array, TRuntimeFieldHandle fldHandle)
    {
        RuntimeField* field = *reinterpret_cast<RuntimeField**>(&fldHandle);
        runtime_helpers_initialize_array_icall(array, field);
    }

    template<typename TRuntimeFieldHandle, typename TRuntimeTypeHandle>
    void* il2cpp_intrinsic_runtime_helpers_get_span_data_from(TRuntimeFieldHandle fldHandle, TRuntimeTypeHandle targetTypeHandle, int32_t* count)
    {
        RuntimeField* field = *reinterpret_cast<RuntimeField**>(&fldHandle);
        Il2CppType* targetType = *reinterpret_cast<Il2CppType**>(&targetTypeHandle);
        return runtime_helpers_get_span_data_from_icall(field, targetType, count);
    }
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
