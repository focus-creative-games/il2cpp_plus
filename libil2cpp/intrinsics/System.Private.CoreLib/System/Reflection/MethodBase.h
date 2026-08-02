#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Reflection
{
    /* METHOD MAPPING
        Method: System.Reflection.MethodBase System.Reflection.MethodBase::GetCurrentMethod()
        AssemblyName: System.Private.CoreLib
    */
    inline MethodBase_t* il2cpp_intrinsic_method_base_get_current_method(const RuntimeMethod* method)
    {
        if (method->is_inflated)
            method = il2cpp_codegen_get_generic_method_definition(method);
        return il2cpp_codegen_get_method_object_internal(method, method->klass);
    }
} // namespace Reflection
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
