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
namespace Emit
{
    class LIBIL2CPP_CODEGEN_API RuntimeModuleBuilder
    {
    public:
        static int32_t getMethodToken(Il2CppObject* mb, Il2CppObject* method, Il2CppArray* opt_param_types);
        static int32_t getToken(Il2CppObject* mb, Il2CppObject* obj, bool create_open_instance);
        static int32_t getUSIndex(Il2CppObject* mb, Il2CppString* str);
        static void RegisterToken(Il2CppObject* thisPtr, Il2CppObject* obj, int32_t token);
        static void basic_init(Il2CppObject* ab);
        static void set_wrappers_type(Il2CppObject* mb, Il2CppObject* ab);
    };
} // namespace Emit
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
