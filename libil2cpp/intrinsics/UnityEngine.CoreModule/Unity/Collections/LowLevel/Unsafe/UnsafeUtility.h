#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
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
namespace LowLevel
{
namespace Unsafe
{
    /* METHOD MAPPING
        Method: System.Boolean Unity.Collections.LowLevel.Unsafe.UnsafeUtility::IsUnmanaged()
        AssemblyName: UnityEngine.CoreModule
    */
    inline bool il2cpp_intrinsic_unsafe_utility_is_unmanaged(const RuntimeMethod* method)
    {
        return !il2cpp_codegen_is_reference_or_contains_references(method);
    }

    /* METHOD MAPPING
        Method: System.Void* Unity.Collections.LowLevel.Unsafe.UnsafeUtility::AddressOf(T&)
        AssemblyName: UnityEngine.CoreModule
    */
    template<typename T>
    inline void* il2cpp_intrinsic_unsafe_utility_address_of(T* output)
    {
        return reinterpret_cast<void*>(output);
    }
} // namespace Unsafe
} // namespace LowLevel
} // namespace Collections
} // namespace Unity
} // namespace UnityEngine_CoreModule
} // namespace intrinsics
} // namespace il2cpp
