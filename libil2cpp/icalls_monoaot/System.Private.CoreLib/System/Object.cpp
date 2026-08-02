#include "il2cpp-config.h"
#include "Object.h"

#include "vm/Object.h"

namespace il2cpp
{
namespace icalls
{
namespace System
{
namespace Private
{
namespace CoreLib
{
namespace System
{
    Il2CppObject* Object::MemberwiseClone(Il2CppObject* thisPtr)
    {
        return il2cpp::vm::Object::Clone(thisPtr);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
