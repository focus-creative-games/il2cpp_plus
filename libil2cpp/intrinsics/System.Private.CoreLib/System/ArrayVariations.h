#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
#include "vm/Array.h"
#include "vm-utils/VmThreadUtils.h"

/*
    This file is here to handle a special case.  Some of the array intrinsics have a 1 to many mapping.
    The intrinsics that are registered with internalized mapping are in `Array.h`
    This file contains variations that are not registered.  The conversion code will call these
    variations instead of the registered one in certain situations.

    Because these are not registered intrinsics, they need to be in a file that does not contain registered intrinsics.
    This ensures that the non-registered intrinsics are not dropped by InternalizedGenerator when regenerating the intrinsics.
*/

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
    template<typename THandleOnStack>
    inline void il2cpp_intrinsic_array_get_generic_value_icall(THandleOnStack self, int32_t pos, void* value, size_t elementSize)
    {
        il2cpp_codegen_get_generic_value_icall(self, pos, value, elementSize);
    }

    template<typename THandleOnStack>
    inline void il2cpp_intrinsic_array_set_generic_value_icall(THandleOnStack arr, int32_t pos, void* value, size_t elementSize)
    {
        il2cpp_codegen_set_generic_value_icall(arr, pos, value, elementSize);
    }

    template<typename THandleOnStack, typename TValue>
    inline void il2cpp_intrinsic_array_set_generic_value_icall_with_barrier(THandleOnStack arr, int32_t pos, TValue* value)
    {
        il2cpp_codegen_set_generic_value_icall_with_barrier(arr, pos, value);
    }
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
