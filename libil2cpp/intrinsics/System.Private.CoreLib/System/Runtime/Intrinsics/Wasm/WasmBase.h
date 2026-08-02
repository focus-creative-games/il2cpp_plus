#pragma once
#include "il2cpp-config.h"
#include "codegen/il2cpp-codegen.h"
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
namespace Intrinsics
{
namespace Wasm
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.Wasm.WasmBase::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_wasm_base_get_is_supported()
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::LeadingZeroCount(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_leading_zero_count(int32_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_clz(static_cast<uint32_t>(value));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::LeadingZeroCount(System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_leading_zero_count(uint32_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_clz(value);
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::LeadingZeroCount(System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_leading_zero_count(int64_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_clzll(static_cast<uint64_t>(value));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::LeadingZeroCount(System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_leading_zero_count(uint64_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_clzll(value);
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::TrailingZeroCount(System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_trailing_zero_count(int32_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_ctz(static_cast<uint32_t>(value));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::TrailingZeroCount(System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_trailing_zero_count(uint32_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_ctz(value);
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::TrailingZeroCount(System.Int64)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_trailing_zero_count(int64_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_ctzll(static_cast<uint64_t>(value));
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.Intrinsics.Wasm.WasmBase::TrailingZeroCount(System.UInt64)
        AssemblyName: System.Private.CoreLib
    */
    inline int32_t il2cpp_intrinsic_wasm_base_trailing_zero_count(uint64_t value)
    {
#if IL2CPP_PLATFORM_JAVASCRIPT
        return __built_ctzll(value);
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Wasm
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
