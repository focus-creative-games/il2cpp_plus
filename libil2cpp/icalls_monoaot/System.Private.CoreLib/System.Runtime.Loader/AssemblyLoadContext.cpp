#include "il2cpp-config.h"
#include "AssemblyLoadContext.h"

#include "gc/GCHandle.h"
#include "vm/Array.h"
#include "vm/Exception.h"
#include "vm/MetadataCache.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "utils/PathUtils.h"
#include "utils/StringUtils.h"
#include <string>

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
    static Il2CppAssemblyLoadContext* s_defaultAlc;

    intptr_t AssemblyLoadContext::GetLoadContextForAssembly(Il2CppReflectionAssembly* rtAsm)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(AssemblyLoadContext::GetLoadContextForAssembly, "Support Non-Default ALC");
        if (s_defaultAlc)
            return reinterpret_cast<intptr_t>(s_defaultAlc->gchandle);
        return 0;
    }

    intptr_t AssemblyLoadContext::InternalInitializeNativeALC(intptr_t thisHandlePtr, intptr_t name, bool representsTPALoadContext, bool isCollectible)
    {
        Il2CppAssemblyLoadContext *alc = NULL;

        if (representsTPALoadContext /* Mono treats this parameter as indicating the 'default' ALC */)
        {
            alc = (Il2CppAssemblyLoadContext*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppAssemblyLoadContext));
            alc->gchandle = reinterpret_cast<Il2CppGCHandle>(thisHandlePtr);
            Il2CppReflectionAssemblyLoadContext* alcObject = reinterpret_cast<Il2CppReflectionAssemblyLoadContext*>(gc::GCHandle::GetTarget(alc->gchandle));
            alcObject->native_alc = alc;

            s_defaultAlc = alc;
        }
        else
        {
            // TODO: handle non-default ALC creation
            IL2CPP_NOT_IMPLEMENTED_ICALL(AssemblyLoadContext::InternalInitializeNativeALC);
            IL2CPP_UNREACHABLE;
        }

        return (intptr_t)alc;
    }

    Il2CppReflectionAssembly* AssemblyLoadContext::InternalLoadFile(intptr_t nativeAssemblyLoadContext, Il2CppString* assemblyFile, int32_t* stackMark)
    {
        // Our implementation is going to behave a bit different.  We can't actually load any assembly.  If we didn't know about the assembly at conversion time,
        // then we won't be able to do anything.
        // On the other hand, if the name of the assembly matches the name of an assembly that we converted, then lets return the assembly that we know about.
        std::string utf8Path = utils::StringUtils::Utf16ToUtf8(utils::StringUtils::GetChars(assemblyFile));
        std::string fileName = utils::PathUtils::BasenameNoExtension(utf8Path);

        const Il2CppAssembly* foundAssembly = vm::MetadataCache::GetAssemblyByName(fileName.c_str());

        if (!foundAssembly)
        {
            vm::Exception::Raise(vm::Exception::GetFileLoadException(fileName.c_str()));
            IL2CPP_UNREACHABLE;
        }

        return vm::Reflection::GetAssemblyObject(foundAssembly);
    }

    Il2CppReflectionAssembly* AssemblyLoadContext::InternalLoadFromStream(intptr_t nativeAssemblyLoadContext, intptr_t assm, int32_t assmLength, intptr_t symbols, int32_t symbolsLength)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(AssemblyLoadContext::InternalLoadFromStream);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    Il2CppArray* AssemblyLoadContext::InternalGetLoadedAssemblies()
    {
        vm::AssemblyVector* assemblies = vm::Assembly::GetAllAssemblies();

        int c = 0;
        Il2CppArray *res = vm::Array::New(il2cpp_defaults.assembly_class, (il2cpp_array_size_t)assemblies->size());
        for (vm::AssemblyVector::const_iterator assembly = assemblies->begin(); assembly != assemblies->end(); ++assembly)
            il2cpp_array_setref(res, c++, vm::Reflection::GetAssemblyObject(*assembly));

        return res;
    }

    void AssemblyLoadContext::PrepareForAssemblyLoadContextRelease(intptr_t nativeAssemblyLoadContext, intptr_t assemblyLoadContextStrong)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(AssemblyLoadContext::PrepareForAssemblyLoadContextRelease);
        IL2CPP_UNREACHABLE;
    }

    void AssemblyLoadContext::FreeStaticData()
    {
        if (s_defaultAlc)
        {
            IL2CPP_FREE(s_defaultAlc);
            s_defaultAlc = nullptr;;
        }
    }
} // namespace Loader
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
