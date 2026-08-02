#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
    /* METHOD MAPPING
        Method: T& modreq(System.Runtime.InteropServices.InAttribute) System.ReadOnlySpan`1::get_Item(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_read_only_span_1_get_item(T* thisPtr, int32_t index, int32_t length)
    {
        IL2CPP_ARRAY_BOUNDS_CHECK(index, length);
        return &thisPtr[index];
    }
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
