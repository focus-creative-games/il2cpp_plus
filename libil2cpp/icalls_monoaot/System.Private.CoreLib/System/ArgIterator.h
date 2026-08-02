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
    class LIBIL2CPP_CODEGEN_API ArgIterator
    {
    public:
        static intptr_t IntGetNextArgType(Il2CppArgIterator* thisPtr);
        static void IntGetNextArg(Il2CppArgIterator* thisPtr, void* res);
        static void IntGetNextArgWithType(Il2CppArgIterator* thisPtr, void* res, intptr_t rth);
        static void Setup(Il2CppArgIterator* thisPtr, intptr_t argsp, intptr_t start);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
