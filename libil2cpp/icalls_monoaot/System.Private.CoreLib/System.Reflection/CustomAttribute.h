#pragma once

#include "il2cpp-object-internals.h"
#include "il2cpp-class-internals.h"
#include "mono-structs.h"

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
namespace Reflection
{
    class LIBIL2CPP_CODEGEN_API CustomAttribute
    {
    public:
        static Il2CppArray* GetCustomAttributesInternal(Il2CppObject* obj, Il2CppReflectionType* attributeType, bool pseudoAttrs);
        static bool IsDefinedInternal(Il2CppObject* obj, Il2CppReflectionType* attributeType);
        static Il2CppArray* GetCustomAttributesDataInternal(Il2CppObject* obj);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
