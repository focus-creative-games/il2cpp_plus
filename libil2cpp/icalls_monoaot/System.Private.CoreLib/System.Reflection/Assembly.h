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
    class LIBIL2CPP_CODEGEN_API Assembly
    {
    public:
        static Il2CppReflectionAssembly* GetCallingAssembly();
        static Il2CppReflectionAssembly* GetEntryAssemblyNative();
        static Il2CppReflectionAssembly* InternalLoad(Il2CppString* assemblyName, int32_t* stackMark, intptr_t ptrLoadContextBinder);
        static Il2CppReflectionAssembly* GetExecutingAssembly(int32_t* stackMark);
        static Il2CppReflectionType* InternalGetType(Il2CppReflectionAssembly* assembly, Il2CppObject* module, Il2CppString* name, bool throwOnError, bool ignoreCase);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
