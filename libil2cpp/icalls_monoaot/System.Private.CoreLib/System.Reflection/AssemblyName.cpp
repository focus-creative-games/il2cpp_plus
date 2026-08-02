#include "il2cpp-config.h"
#include "AssemblyName.h"
#include "vm/AssemblyName.h"
#include "vm/Reflection.h"

#include "il2cpp-object-internals.h"
#include "mono-structs.h"
#include "utils/StringUtils.h"
#include "utils/sha1.h"
#include "vm-utils/VmStringUtils.h"
#include "vm/Array.h"
#include "vm/AssemblyName.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/String.h"
#include "vm/Type.h"

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
    Il2CppMonoAssemblyName* AssemblyName::GetNativeName(intptr_t assemblyPtr)
    {
        Il2CppAssembly *assembly = (Il2CppAssembly*)assemblyPtr;

        Il2CppMonoAssemblyName *aname = (Il2CppMonoAssemblyName*)il2cpp::vm::Reflection::GetMonoAssemblyName(assembly);
        if (aname)
        {
            return aname;
        }
        else
        {
            aname = (Il2CppMonoAssemblyName*)IL2CPP_MALLOC_ZERO(sizeof(Il2CppMonoAssemblyName));
            il2cpp::vm::AssemblyName::FillNativeAssemblyName(assembly->aname, aname, false);

            il2cpp::vm::Reflection::SetMonoAssemblyName(assembly, aname);
            return aname;
        }
    }

    void AssemblyName::FreeAssemblyName(Il2CppMonoAssemblyName* name, bool freeStruct)
    {
        if (name->name) IL2CPP_FREE(const_cast<char*>(name->name));
        if (name->culture) IL2CPP_FREE(const_cast<char*>(name->culture));
        if (name->public_key) IL2CPP_FREE(const_cast<uint8_t*>(name->public_key));
        if (freeStruct)
            IL2CPP_FREE(name);
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
