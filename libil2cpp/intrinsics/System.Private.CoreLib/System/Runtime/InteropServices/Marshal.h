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
namespace Runtime
{
namespace InteropServices
{
    /* METHOD MAPPING
        Method: System.IntPtr System.Runtime.InteropServices.Marshal::GetComInterfaceForObject(System.Object,System.Type)
        AssemblyName: System.Private.CoreLib
    */
    intptr_t il2cpp_intrinsic_marshal_get_com_interface_for_object(RuntimeObject* o, Type_t* T);

    /* METHOD MAPPING
        Method: System.IntPtr System.Runtime.InteropServices.Marshal::GetIUnknownForObject(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    inline intptr_t il2cpp_intrinsic_marshal_get_i_unknown_for_object(RuntimeObject* o)
    {
        return reinterpret_cast<intptr_t>(il2cpp_codegen_com_get_or_create_ccw_internal(o, Il2CppIUnknown::IID));
    }

    /* METHOD MAPPING
        Method: System.Object System.Runtime.InteropServices.Marshal::GetObjectForIUnknown(System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    RuntimeObject* il2cpp_intrinsic_marshal_get_object_for_i_unknown(intptr_t pUnk);

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.InteropServices.Marshal::ReleaseComObject(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    int32_t il2cpp_intrinsic_marshal_release_com_object(RuntimeObject* co);
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
