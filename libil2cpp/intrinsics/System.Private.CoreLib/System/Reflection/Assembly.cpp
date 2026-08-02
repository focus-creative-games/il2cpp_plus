#include "Assembly.h"
#include "vm/Exception.h"
#include "vm/Reflection.h"
#include "icalls_monoaot/System.Private.CoreLib/System.Runtime.Loader/AssemblyLoadContext.h"

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
    Assembly_t* il2cpp_intrinsic_assembly_get_executing_assembly(const RuntimeMethod* method)
    {
        return (Assembly_t*)il2cpp::vm::Reflection::GetAssemblyObject(method->klass->image->assembly);
    }

    Assembly_t* il2cpp_intrinsic_assembly_load_file(String_t* path)
    {
        return (Assembly_t*)il2cpp::icalls::System::Private::CoreLib::System::Runtime::Loader::AssemblyLoadContext::InternalLoadFile(0, (Il2CppString*)path, nullptr);
    }
} // namespace Reflection
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
