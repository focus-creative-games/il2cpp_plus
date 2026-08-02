#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"

// The Mono System.Private.Corelib tries to access the object header/monitor in managed code
// il2cpp has a different implementation of the object header/monitor so we need to override these methods

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Threading
{
    /* METHOD MAPPING
        Method: System.Boolean System.Threading.ObjectHeader::HasOwner(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    bool il2cpp_intrinsic_object_header_has_owner(RuntimeObject* obj);

    /* METHOD MAPPING
        Method: System.Boolean System.Threading.ObjectHeader::IsEntered(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    bool il2cpp_intrinsic_object_header_is_entered(RuntimeObject* obj);

    /* METHOD MAPPING
        Method: System.Boolean System.Threading.ObjectHeader::TryEnterFast(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_object_header_try_enter_fast(RuntimeObject* o)
    {
        IL2CPP_NOT_IMPLEMENTED_INTRINSIC_OPTIONAL_FIXME(il2cpp_intrinsic_object_header_try_enter_fast);
        return false;
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Threading.ObjectHeader::TryExitChecked(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_object_header_try_exit_checked(RuntimeObject* obj)
    {
        IL2CPP_NOT_IMPLEMENTED_INTRINSIC_OPTIONAL_FIXME(il2cpp_intrinsic_object_header_try_exit_checked);
        return false;
    }
} // namespace Threading
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
