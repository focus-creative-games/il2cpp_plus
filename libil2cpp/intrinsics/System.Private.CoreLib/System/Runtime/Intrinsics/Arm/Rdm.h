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
        Method: System.Boolean System.Runtime.Intrinsics.Arm.Rdm::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_rdm_get_is_supported()
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndAddSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_add_saturate_high_E0525(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int16x8_t, TRet, vqrdmlahq_s16(
                INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                INTRINSIC_CAST(TArg3, int16x8_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_subtract_saturate_high_E0525(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int16x8_t, TRet, vqrdmlshq_s16(
                INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                INTRINSIC_CAST(TArg3, int16x8_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_1B104(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        7
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_1B104(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 7)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x8_t, TRet, vqrdmlahq_laneq_s16(
                INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_914FE(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlahq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_914FE(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x8_t, TRet, vqrdmlahq_lane_s16(
                INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_1B104(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        7
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_1B104(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 7)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x8_t, TRet, vqrdmlshq_laneq_s16(
                INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_914FE(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x8_t, TRet, vqrdmlshq_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_914FE(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x8_t, TRet, vqrdmlshq_lane_s16(
                INTRINSIC_CAST(TArg1, int16x8_t, arg1),
                INTRINSIC_CAST(TArg2, int16x8_t, arg2),
                INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndAddSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_add_saturate_high_5D9DC(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int32x4_t, TRet, vqrdmlahq_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                INTRINSIC_CAST(TArg3, int32x4_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_subtract_saturate_high_5D9DC(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int32x4_t, TRet, vqrdmlshq_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                INTRINSIC_CAST(TArg3, int32x4_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_66727(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlahq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlahq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlahq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlahq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_66727(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x4_t, TRet, vqrdmlahq_laneq_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_3FCFA(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlahq_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlahq_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_3FCFA(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x4_t, TRet, vqrdmlahq_lane_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                INTRINSIC_CAST(TArg3, int32x2_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_66727(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlshq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlshq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlshq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlshq_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_66727(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x4_t, TRet, vqrdmlshq_laneq_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_3FCFA(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlshq_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x4_t, TRet, vqrdmlshq_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_3FCFA(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x4_t, TRet, vqrdmlshq_lane_s32(
                INTRINSIC_CAST(TArg1, int32x4_t, arg1),
                INTRINSIC_CAST(TArg2, int32x4_t, arg2),
                INTRINSIC_CAST(TArg3, int32x2_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndAddSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_add_saturate_high_DCEFC(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int16x4_t, TRet, vqrdmlah_s16(
                INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                INTRINSIC_CAST(TArg3, int16x4_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_subtract_saturate_high_DCEFC(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int16x4_t, TRet, vqrdmlsh_s16(
                INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                INTRINSIC_CAST(TArg3, int16x4_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_ED3D5(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        7
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_ED3D5(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 7)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x4_t, TRet, vqrdmlah_laneq_s16(
                INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_0BE95(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlah_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_0BE95(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x4_t, TRet, vqrdmlah_lane_s16(
                INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector128`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_ED3D5(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        3
                    )
                );
            }
            case 4:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        4
                    )
                );
            }
            case 5:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        5
                    )
                );
            }
            case 6:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        6
                    )
                );
            }
            case 7:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_laneq_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                        7
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_ED3D5(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 7)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x4_t, TRet, vqrdmlsh_laneq_s16(
                INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                INTRINSIC_CAST(TArg3, int16x8_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int16> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Runtime.Intrinsics.Vector64`1<System.Int16>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_0BE95(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int16x4_t, TRet, vqrdmlsh_lane_s16(
                        INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                        INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                        INTRINSIC_CAST(TArg3, int16x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_0BE95(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int16x4_t, TRet, vqrdmlsh_lane_s16(
                INTRINSIC_CAST(TArg1, int16x4_t, arg1),
                INTRINSIC_CAST(TArg2, int16x4_t, arg2),
                INTRINSIC_CAST(TArg3, int16x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndAddSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_add_saturate_high_455B4(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int32x2_t, TRet, vqrdmlah_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                INTRINSIC_CAST(TArg3, int32x2_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_and_subtract_saturate_high_455B4(TArg1 arg1, TArg2 arg2, TArg3 arg3)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        return INTRINSIC_CAST(
            int32x2_t, TRet, vqrdmlsh_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                INTRINSIC_CAST(TArg3, int32x2_t, arg3)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_D7D1B(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlah_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlah_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlah_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlah_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_D7D1B(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x2_t, TRet, vqrdmlah_laneq_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndAddSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_ABB38(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlah_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlah_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_add_saturate_high_ABB38(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x2_t, TRet, vqrdmlah_lane_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                INTRINSIC_CAST(TArg3, int32x2_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector128`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_D7D1B(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlsh_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlsh_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        1
                    )
                );
            }
            case 2:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlsh_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                        2
                    )
                );
            }
            case 3:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlsh_laneq_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x4_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_D7D1B(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 3)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x2_t, TRet, vqrdmlsh_laneq_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                INTRINSIC_CAST(TArg3, int32x4_t, arg3),
                TArg4Value
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector64`1<System.Int32> System.Runtime.Intrinsics.Arm.Rdm::MultiplyRoundedDoublingBySelectedScalarAndSubtractSaturateHigh(System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Runtime.Intrinsics.Vector64`1<System.Int32>,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ConstArgumentsExpected: [3]
    */
    template<typename TRet, typename TArg1, typename TArg2, typename TArg3, typename TArg4>
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_ABB38(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        switch (arg4)
        {
            case 0:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlsh_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
                        0
                    )
                );
            }
            case 1:
            {
                return INTRINSIC_CAST(
                    int32x2_t, TRet, vqrdmlsh_lane_s32(
                        INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                        INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                        INTRINSIC_CAST(TArg3, int32x2_t, arg3),
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
    inline TRet il2cpp_intrinsic_rdm_multiply_rounded_doubling_by_selected_scalar_and_subtract_saturate_high_ABB38(TArg1 arg1, TArg2 arg2, TArg3 arg3, TArg4 arg4)
    {
#if IL2CPP_ARM_RDM_IS_SUPPORTED
        if (TArg4Value < 0 || TArg4Value > 1)
            il2cpp_codegen_raise_argument_out_of_range_exception(NULL);

        return INTRINSIC_CAST(
            int32x2_t, TRet, vqrdmlsh_lane_s32(
                INTRINSIC_CAST(TArg1, int32x2_t, arg1),
                INTRINSIC_CAST(TArg2, int32x2_t, arg2),
                INTRINSIC_CAST(TArg3, int32x2_t, arg3),
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
