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
        Method: System.Boolean System.Runtime.Intrinsics.Arm.Crc32::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_crc32_get_is_supported()
    {
#if IL2CPP_ARM_CRC32_IS_SUPPORTED
        return true;
#else
        return false;
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.Arm.Crc32::ComputeCrc32(System.UInt32,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_crc32_compute_crc32_669B5(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_CRC32_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32_t, TRet, __crc32b(
                INTRINSIC_CAST(TArg1, uint32_t, arg1),
                INTRINSIC_CAST(TArg2, uint8_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.Arm.Crc32::ComputeCrc32(System.UInt32,System.UInt16)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_crc32_compute_crc32_A0386(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_CRC32_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32_t, TRet, __crc32h(
                INTRINSIC_CAST(TArg1, uint32_t, arg1),
                INTRINSIC_CAST(TArg2, uint16_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.Arm.Crc32::ComputeCrc32(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_crc32_compute_crc32_022FE(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_CRC32_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32_t, TRet, __crc32w(
                INTRINSIC_CAST(TArg1, uint32_t, arg1),
                INTRINSIC_CAST(TArg2, uint32_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.Arm.Crc32::ComputeCrc32C(System.UInt32,System.Byte)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_crc32_compute_crc32c_669B5(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_CRC32_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32_t, TRet, __crc32cb(
                INTRINSIC_CAST(TArg1, uint32_t, arg1),
                INTRINSIC_CAST(TArg2, uint8_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.Arm.Crc32::ComputeCrc32C(System.UInt32,System.UInt16)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_crc32_compute_crc32c_A0386(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_CRC32_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32_t, TRet, __crc32ch(
                INTRINSIC_CAST(TArg1, uint32_t, arg1),
                INTRINSIC_CAST(TArg2, uint16_t, arg2)
            )
        );
#else
        il2cpp_codegen_raise_platform_not_supported_exception(NULL);
        return {};
#endif
    }

    /* METHOD MAPPING
        Method: System.UInt32 System.Runtime.Intrinsics.Arm.Crc32::ComputeCrc32C(System.UInt32,System.UInt32)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TRet, typename TArg1, typename TArg2>
    inline TRet il2cpp_intrinsic_crc32_compute_crc32c_022FE(TArg1 arg1, TArg2 arg2)
    {
#if IL2CPP_ARM_CRC32_IS_SUPPORTED
        return INTRINSIC_CAST(
            uint32_t, TRet, __crc32cw(
                INTRINSIC_CAST(TArg1, uint32_t, arg1),
                INTRINSIC_CAST(TArg2, uint32_t, arg2)
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
