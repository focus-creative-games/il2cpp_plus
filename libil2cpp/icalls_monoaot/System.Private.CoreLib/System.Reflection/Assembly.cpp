#include "il2cpp-config.h"
#include "Assembly.h"
#include "vm/Image.h"
#include "vm/Reflection.h"

#include "il2cpp-class-internals.h"
#include "mono-structs.h"
#include "os/File.h"
#include "os/Mutex.h"
#include "os/Path.h"
#include "utils/Memory.h"
#include "utils/MemoryMappedFile.h"
#include "utils/PathUtils.h"
#include "utils/Runtime.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Assembly.h"
#include "vm/AssemblyName.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Field.h"
#include "vm/Image.h"
#include "vm/MetadataCache.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/String.h"
#include "vm/Type.h"
#include <algorithm>
#include <limits>
#include <stddef.h>
#include <vector>

using namespace il2cpp::vm;

#define CHECK_IF_NULL(v) if( (v) == NULL) { \
    if (throwOnError) Exception::Raise(assembly ? Exception::GetTypeLoadException(assembly->assembly, info) : Exception::GetTypeLoadException(info)); \
    return NULL; \
}

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
    Il2CppReflectionAssembly* Assembly::GetCallingAssembly()
    {
        return vm::Reflection::GetAssemblyObject(vm::Image::GetCallingImage()->assembly);
    }

    Il2CppReflectionAssembly* Assembly::GetEntryAssemblyNative()
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(Assembly::GetEntryAssemblyNative, "In the case of Unity this is always NULL. For a normal exe this is the assembly with Main.");
        return NULL;
    }

    Il2CppReflectionAssembly* Assembly::InternalLoad(Il2CppString* assemblyName, int32_t* stackMark, intptr_t ptrLoadContextBinder)
    {
        il2cpp::vm::TypeNameParseInfo info;
        std::string name = il2cpp::utils::StringUtils::Utf16ToUtf8(assemblyName->chars);
        il2cpp::vm::TypeNameParser parser(name, info, false);

        if (!parser.ParseAssembly())
            return NULL;

        //assemblyRef might have been a fullname like System, CultureInfo=bla, Version=4.0, PublicKeyToken=23423423423423
        //we ignore all that info except the name. (mono ignores the keytoken, and I'm quite sure it also ignores the version).
        //il2cpp does not pack multiple assemblies with the same name, and even if that one is not the exact one that is asked for,
        //it's more useful to return it than not to. (like cases where you want to Deserialize a BinaryFormatter blob that was serialized
        //on 4.0)
        const Il2CppAssembly* assembly = vm::Assembly::GetLoadedAssembly(info.assembly_name().name.c_str());

        if (assembly != NULL)
            return vm::Reflection::GetAssemblyObject(assembly);

        return NULL;
    }

    Il2CppReflectionAssembly* Assembly::GetExecutingAssembly(int32_t* stackMark)
    {
        return vm::Reflection::GetAssemblyObject(vm::Image::GetExecutingImage()->assembly);
    }

    Il2CppReflectionType* Assembly::InternalGetType(Il2CppReflectionAssembly* assembly, Il2CppObject* module, Il2CppString* name, bool throwOnError, bool ignoreCase)
    {
        std::string str = utils::StringUtils::Utf16ToUtf8(utils::StringUtils::GetChars(name));

        il2cpp::vm::TypeNameParseInfo info;
        il2cpp::vm::TypeNameParser parser(str, info, false);

        if (!parser.Parse())
        {
            if (throwOnError)
                vm::Exception::Raise(vm::Exception::GetTypeLoadException());
            else
                return NULL;
        }

        CHECK_IF_NULL(assembly);

        Il2CppImage *image = (Il2CppImage*)vm::Assembly::GetImage(assembly->assembly);

        CHECK_IF_NULL(image);

        Il2CppClass *klass = vm::Image::FromTypeNameParseInfo(image, info, ignoreCase);

        CHECK_IF_NULL(klass);

        il2cpp::vm::Class::Init(klass);

        const Il2CppType *type = vm::Class::GetType(klass, info);

        CHECK_IF_NULL(type);

        return il2cpp::vm::Reflection::GetTypeObject(type);
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
