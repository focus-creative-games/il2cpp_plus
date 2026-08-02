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
namespace Runtime
{
namespace InteropServices
{
    class LIBIL2CPP_CODEGEN_API NativeLibrary
    {
    public:
        static intptr_t GetSymbol(intptr_t handle, Il2CppString* symbolName, bool throwOnError);
        static intptr_t LoadByName(Il2CppString* libraryName, Il2CppReflectionAssembly* callingAssembly, bool hasDllImportSearchPathFlag, uint32_t dllImportSearchPathFlag, bool throwOnError);
        static intptr_t LoadFromPath(Il2CppString* libraryName, bool throwOnError);
        static void FreeLib(intptr_t handle);
    };
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
