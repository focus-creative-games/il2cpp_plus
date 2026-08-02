#include "Object.h"
#include "codegen/il2cpp-codegen.h"
#include "vm/Class.h"
#include "vm/Object.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
    Type_t* il2cpp_intrinsic_object_get_type(Il2CppObject* obj)
    {
        return il2cpp_codegen_type_get_object(il2cpp::vm::Class::GetType(il2cpp::vm::Object::GetClass(obj)));
    }
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
