#pragma once
#include "il2cpp-config.h"
#include "il2cpp-intrinsics-config.h"

#include "codegen/il2cpp-codegen-metadata.h"

#include "intrinsics/System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse.h"

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
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.Intrinsics.Vector128`1::get_IsSupported()
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_vector128_1_get_is_supported()
    {
        IL2CPP_NOT_IMPLEMENTED_INTRINSIC_OPTIONAL_FIXME(il2cpp_intrinsic_vector128_1_get_is_supported);
        return true;
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<T> System.Runtime.Intrinsics.Vector128`1<System.Single>::op_Addition(System.Runtime.Intrinsics.Vector128`1<T>,System.Runtime.Intrinsics.Vector128`1<T>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ProvideFallbackMethod: true
    */
    template<typename TRet, typename TArg1, typename TArg2, TRet(*TFallbackMethod)(TArg1, TArg2, const RuntimeMethod*) = NULL>
    inline TRet il2cpp_intrinsic_vector128_1_op_addition_float(TRet arg1, TRet arg2, const RuntimeMethod* method = NULL)
    {
#if IL2CPP_SSE_IS_SUPPORTED
        return il2cpp::intrinsics::System_Private_CoreLib::System::Runtime::Intrinsics::X86::il2cpp_intrinsic_sse_add<TRet, TArg1, TArg2>(arg1, arg2);
#else
        return TFallbackMethod(arg1, arg2, /*(RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&*/ method /*)*/);
#endif
    }

    /* METHOD MAPPING
        Method: System.Runtime.Intrinsics.Vector128`1<T> System.Runtime.Intrinsics.Vector128`1<System.Int32>::op_Addition(System.Runtime.Intrinsics.Vector128`1<T>,System.Runtime.Intrinsics.Vector128`1<T>)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
        ProvideFallbackMethod: true
    */
    template<typename TRet, typename TArg1, typename TArg2, TRet(*TFallbackMethod)(TArg1, TArg2, const RuntimeMethod*)>
    inline TRet il2cpp_intrinsic_vector128_1_op_addition_int(TRet arg1, TRet arg2, const RuntimeMethod* method)
    {
#if IL2CPP_SSE2_IS_SUPPORTED
        return INTRINSIC_CAST(
            __m128i, TRet, _mm_add_epi32(
                INTRINSIC_CAST(TArg1, __m128i, arg1),
                INTRINSIC_CAST(TArg2, __m128i, arg2)
            )
        );
#else
        return TFallbackMethod(arg1, arg2,  method);

#endif
    }
} // namespace Intrinsics
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
