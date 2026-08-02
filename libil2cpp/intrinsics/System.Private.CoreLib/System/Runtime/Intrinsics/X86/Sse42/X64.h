#pragma once
#include "il2cpp-config.h"
#include "il2cpp-intrinsics-config.h"

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
namespace X86
{
namespace Sse42
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Sse42/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
#if IL2CPP_SSE42_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Sse42/X64::Crc32(System.UInt64,System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic__x64_crc32(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_SSE42_X64_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint64_t, TRet, _mm_crc32_u64(
                INTRINSIC_CAST(TArg1, uint64_t, arg1),
                INTRINSIC_CAST(TArg2, uint64_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }
} // namespace Sse42
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
