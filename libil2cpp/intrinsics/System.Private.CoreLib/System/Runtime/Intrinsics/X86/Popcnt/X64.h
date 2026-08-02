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
namespace Intrinsics
{
namespace X86
{
namespace Popcnt
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Popcnt/X64::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic__x64_get_is_supported()
    {
#ifdef IL2CPP_POPCNT_X64_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt64 System.Runtime.Intrinsics.X86.Popcnt/X64::PopCount(System.UInt64)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic__x64_pop_count(TArg1 arg1)
    {
// HAND EDITED: Changed the types from __int64 to int64_t and unsigned __int64 to uint64_t
#if IL2CPP_POPCNT_X64_IS_SUPPORTED
    return INTRINSIC_CAST(
        int64_t, TRet, _mm_popcnt_u64(
            INTRINSIC_CAST(TArg1, uint64_t, arg1)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }
} // namespace Popcnt
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
