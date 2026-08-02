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
    class LIBIL2CPP_CODEGEN_API RuntimeParameterInfo
    {
    public:
        static int32_t GetMetadataToken(Il2CppObject* thisPtr);
        static Il2CppArray* GetTypeModifiers(Il2CppObject* type, Il2CppObject* member, int32_t position, bool optional, int32_t genericArgumentPosition);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
