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
    class LIBIL2CPP_CODEGEN_API RuntimeAssembly
    {
    public:
        static void AllocateStaticData();
        static void FreeStaticData();
        static bool GetManifestResourceInfoInternal(Il2CppQCallAssembly assembly, Il2CppString* name, Il2CppManifestResourceInfo* info);
        static intptr_t GetManifestResourceInternal(Il2CppQCallAssembly assembly, Il2CppString* name, int32_t* size, Il2CppObjectHandleOnStack module);
        static intptr_t InternalGetReferencedAssemblies(Il2CppReflectionAssembly* assembly);
        static void GetEntryPoint(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res);
        static void GetExportedTypes(Il2CppQCallAssembly assembly_h, Il2CppObjectHandleOnStack res);
        static void GetInfo(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res, int32_t kind);
        static void GetManifestModuleInternal(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res);
        static void GetManifestResourceNames(Il2CppQCallAssembly assembly_h, Il2CppObjectHandleOnStack res);
        static void GetModulesInternal(Il2CppQCallAssembly assembly, Il2CppObjectHandleOnStack res);
        static void GetTopLevelForwardedTypes(Il2CppQCallAssembly assembly_h, Il2CppObjectHandleOnStack res);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
