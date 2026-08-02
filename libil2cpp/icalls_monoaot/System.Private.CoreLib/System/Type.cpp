#include "il2cpp-config.h"
#include "Type.h"

#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "vm/Type.h"
#include <metadata/GenericMetadata.h>
#include <utils/StringUtils.h>

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
    Il2CppReflectionType* Type::internal_from_handle(intptr_t handle)
    {
        return vm::Type::GetTypeFromHandle(handle);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
