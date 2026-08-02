#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "il2cpp-intrinsics-config.h"

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
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.X86.Lzcnt::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_lzcnt_get_is_supported()
    {
        #ifdef IL2CPP_LZCNT_IS_SUPPORTED
        return true;
        #else
        return false;
        #endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.X86.Lzcnt::LeadingZeroCount(System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_lzcnt_leading_zero_count(TArg1 arg1)
    {
#if IL2CPP_LZCNT_IS_SUPPORTED
    return INTRINSIC_CAST(
        unsigned int, TRet, _lzcnt_u32(
            INTRINSIC_CAST(TArg1, unsigned int, arg1)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }
} // namespace X86
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
