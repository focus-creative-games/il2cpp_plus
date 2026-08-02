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
    class LIBIL2CPP_CODEGEN_API RuntimeEventInfo
    {
    public:
        static int32_t get_metadata_token(Il2CppObject* monoEvent);
        static Il2CppReflectionEvent* internal_from_handle_type(const EventInfo* event_handle, const Il2CppType* type_handle);
        static void get_event_info(Il2CppReflectionMonoEvent* ev, Il2CppReflectionMonoEventInfo* info);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
