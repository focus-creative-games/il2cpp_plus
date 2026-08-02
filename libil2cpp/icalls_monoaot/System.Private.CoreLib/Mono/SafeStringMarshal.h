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
namespace Mono
{
    class LIBIL2CPP_CODEGEN_API SafeStringMarshal
    {
    public:
        static intptr_t StringToUtf8_icall(Il2CppString** str);
        static void GFree(intptr_t ptr);
    };
} // namespace Mono
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
