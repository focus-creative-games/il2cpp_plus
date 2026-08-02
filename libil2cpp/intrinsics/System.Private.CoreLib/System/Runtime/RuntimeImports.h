#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
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
    /* METHOD MAPPING
        Method: System.Void* System.Runtime.RuntimeImports::memmove(System.Byte*,System.Byte*,System.UIntPtr)
        AssemblyName: System.Private.CoreLib
    */
    inline void* il2cpp_intrinsic_runtime_imports_memmove(uint8_t* dmem, uint8_t* smem, uintptr_t size)
    {
        return memmove(dmem, smem, size);
    }

    /* METHOD MAPPING
        Method: System.Void* System.Runtime.RuntimeImports::memset(System.Byte*,System.Int32,System.UIntPtr)
        AssemblyName: System.Private.CoreLib
    */
    inline void* il2cpp_intrinsic_runtime_imports_memset(uint8_t* mem, int32_t value, uintptr_t size)
    {
        return memset(mem, value, size);
    }
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
