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
namespace Arm
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.Arm.Sha1::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_sha1_get_is_supported()
    {
#if IL2CPP_ARM_SHA1_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Sha1::HashUpdateChoose(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector64`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sha1_hash_update_choose(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_SHA1_IS_SUPPORTED
    return INTRINSIC_CAST(
        uint32x4_t, TRet, vsha1cq_u32(
            INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
            vget_lane_u32(INTRINSIC_CAST(TArg2, uint32x2_t, arg2), 0),
            INTRINSIC_CAST(TArg3, uint32x4_t, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Sha1::HashUpdateMajority(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector64`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sha1_hash_update_majority(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_SHA1_IS_SUPPORTED
    return INTRINSIC_CAST(
        uint32x4_t, TRet, vsha1mq_u32(
            INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
            vget_lane_u32(INTRINSIC_CAST(TArg2, uint32x2_t, arg2), 0),
            INTRINSIC_CAST(TArg3, uint32x4_t, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Sha1::HashUpdateParity(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector64`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sha1_hash_update_parity(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_SHA1_IS_SUPPORTED
    return INTRINSIC_CAST(
        uint32x4_t, TRet, vsha1pq_u32(
            INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
            vget_lane_u32(INTRINSIC_CAST(TArg2, uint32x2_t, arg2), 0),
            INTRINSIC_CAST(TArg3, uint32x4_t, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Sha1::ScheduleUpdate0(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_sha1_schedule_update0(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_SHA1_IS_SUPPORTED
    return INTRINSIC_CAST(
        uint32x4_t, TRet, vsha1su0q_u32(
            INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
            INTRINSIC_CAST(TArg2, uint32x4_t, arg2),
            INTRINSIC_CAST(TArg3, uint32x4_t, arg3)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Sha1::ScheduleUpdate1(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_sha1_schedule_update1(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_SHA1_IS_SUPPORTED
    return INTRINSIC_CAST(
        uint32x4_t, TRet, vsha1su1q_u32(
            INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
            INTRINSIC_CAST(TArg2, uint32x4_t, arg2)
        ));
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.UInt32> System.Runtime.Intrinsics.Arm.Sha1::FixedRotate(System.Runtime.Intrinsics.Vector64`1<System.UInt32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1>
    inline TRet il2cpp_intrinsic_sha1_fixed_rotate(TArg1 arg1)
    {
#if IL2CPP_ARM_SHA1_IS_SUPPORTED
    uint32x2_t ret = {};
    ret = vset_lane_u32(vsha1h_u32(
            vget_lane_u32(INTRINSIC_CAST(TArg1, uint32x2_t, arg1), 0)
        ), ret, 0); 
    return INTRINSIC_CAST(
        uint32x2_t, TRet, ret);
#else
    il2cpp_codegen_raise_platform_not_supported_exception(NULL);
    return {};
#endif
    }
} // namespace Arm
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
