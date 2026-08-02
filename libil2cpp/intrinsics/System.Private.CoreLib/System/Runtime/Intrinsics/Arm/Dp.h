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
        Method: System.Boolean System.Runtime.Intrinsics.Arm.Dp::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_dp_get_is_supported()
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Dp::DotProduct(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_dp_dot_product_4895B(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        return INTRINSIC_CAST(
            int32x4_t, TRet, vdotq_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                INTRINSIC_CAST(TArg3, int8x16_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_3F6C6(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vdotq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vdotq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vdotq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vdotq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_3F6C6(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x4_t, TRet, vdotq_laneq_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Runtime.Intrinsics.Vector64`1<System.SByte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_7A9A2(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vdotq_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vdotq_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x8_t, arg3),
                        1
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_7A9A2(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x4_t, TRet, vdotq_lane_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int8x16_t, arg2),
                INTRINSIC_CAST(TArg3, int8x8_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Dp::DotProduct(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_dp_dot_product_74979(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32x4_t, TRet, vdotq_u32(
                INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                INTRINSIC_CAST(TArg3, uint8x16_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_80C63(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    uint32x4_t, TRet, vdotq_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    uint32x4_t, TRet, vdotq_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    uint32x4_t, TRet, vdotq_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    uint32x4_t, TRet, vdotq_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_80C63(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            uint32x4_t, TRet, vdotq_laneq_u32(
                INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.UInt32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector128`1<System.UInt32>,System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Runtime.Intrinsics.Vector64`1<System.Byte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_C03ED(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    uint32x4_t, TRet, vdotq_lane_u32(
                        INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    uint32x4_t, TRet, vdotq_lane_u32(
                        INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x8_t, arg3),
                        1
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_C03ED(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            uint32x4_t, TRet, vdotq_lane_u32(
                INTRINSIC_CAST(TArg1, uint32x4_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x16_t, arg2),
                INTRINSIC_CAST(TArg3, uint8x8_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Dp::DotProduct(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.SByte>,System.Runtime.Intrinsics.Vector64`1<System.SByte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_dp_dot_product_35B50(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        return INTRINSIC_CAST(
            int32x2_t, TRet, vdot_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                INTRINSIC_CAST(TArg3, int8x8_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.SByte>,System.Runtime.Intrinsics.Vector128`1<System.SByte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_08E0E(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vdot_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vdot_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vdot_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vdot_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_08E0E(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x2_t, TRet, vdot_laneq_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                INTRINSIC_CAST(TArg3, int8x16_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.SByte>,System.Runtime.Intrinsics.Vector64`1<System.SByte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_98D12(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vdot_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vdot_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int8x8_t, arg3),
                        1
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_98D12(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x2_t, TRet, vdot_lane_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int8x8_t, arg2),
                INTRINSIC_CAST(TArg3, int8x8_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.UInt32> System.Runtime.Intrinsics.Arm.Dp::DotProduct(System.Runtime.Intrinsics.Vector64`1<System.UInt32>,System.Runtime.Intrinsics.Vector64`1<System.Byte>,System.Runtime.Intrinsics.Vector64`1<System.Byte>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_dp_dot_product_0E9F1(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32x2_t, TRet, vdot_u32(
                INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                INTRINSIC_CAST(TArg3, uint8x8_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.UInt32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector64`1<System.UInt32>,System.Runtime.Intrinsics.Vector64`1<System.Byte>,System.Runtime.Intrinsics.Vector128`1<System.Byte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_0EF15(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    uint32x2_t, TRet, vdot_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    uint32x2_t, TRet, vdot_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    uint32x2_t, TRet, vdot_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    uint32x2_t, TRet, vdot_laneq_u32(
                        INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                        3
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_0EF15(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            uint32x2_t, TRet, vdot_laneq_u32(
                INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                INTRINSIC_CAST(TArg3, uint8x16_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.UInt32> System.Runtime.Intrinsics.Arm.Dp::DotProductBySelectedQuadruplet(System.Runtime.Intrinsics.Vector64`1<System.UInt32>,System.Runtime.Intrinsics.Vector64`1<System.Byte>,System.Runtime.Intrinsics.Vector64`1<System.Byte>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_769AF(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    uint32x2_t, TRet, vdot_lane_u32(
                        INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    uint32x2_t, TRet, vdot_lane_u32(
                        INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                        INTRINSIC_CAST(TArg3, uint8x8_t, arg3),
                        1
                    )
                );
            }
            default:
                il2cpp_codegen_raise_argument_out_of_range_exception(NULL);
                break;
        }
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4, int TArg4Value>
    inline TRet il2cpp_intrinsic_dp_dot_product_by_selected_quadruplet_769AF(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_DP_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            uint32x2_t, TRet, vdot_lane_u32(
                INTRINSIC_CAST(TArg1, uint32x2_t, arg1),
                INTRINSIC_CAST(TArg2, uint8x8_t, arg2),
                INTRINSIC_CAST(TArg3, uint8x8_t, arg3),
                TArg4Value
            )
        );
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
