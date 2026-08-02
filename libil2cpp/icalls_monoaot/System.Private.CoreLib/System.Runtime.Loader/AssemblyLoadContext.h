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
namespace Loader
{
    class LIBIL2CPP_CODEGEN_API AssemblyLoadContext
    {
    public:
        static intptr_t GetLoadContextForAssembly(Il2CppReflectionAssembly* rtAsm);
        static intptr_t InternalInitializeNativeALC(intptr_t thisHandlePtr, intptr_t name, bool representsTPALoadContext, bool isCollectible);
        static Il2CppReflectionAssembly* InternalLoadFile(intptr_t nativeAssemblyLoadContext, Il2CppString* assemblyFile, int32_t* stackMark);
        static Il2CppReflectionAssembly* InternalLoadFromStream(intptr_t nativeAssemblyLoadContext, intptr_t assm, int32_t assmLength, intptr_t symbols, int32_t symbolsLength);
        static Il2CppArray* InternalGetLoadedAssemblies();
        static void PrepareForAssemblyLoadContextRelease(intptr_t nativeAssemblyLoadContext, intptr_t assemblyLoadContextStrong);
        static void FreeStaticData();
    };
} // namespace Loader
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
