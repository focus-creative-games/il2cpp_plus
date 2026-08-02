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
    typedef enum
    {
        PInfo_Attributes = 1,
        PInfo_GetMethod = 1 << 1,
        PInfo_SetMethod = 1 << 2,
        PInfo_ReflectedType = 1 << 3,
        PInfo_DeclaringType = 1 << 4,
        PInfo_Name = 1 << 5
    } PInfo;

    class LIBIL2CPP_CODEGEN_API RuntimePropertyInfo
    {
    public:
        static int32_t get_metadata_token(Il2CppObject* monoProperty);
        static Il2CppObject* get_default_value(Il2CppObject* prop);
        static Il2CppObject* internal_from_handle_type(intptr_t event_handle, intptr_t type_handle);
        static Il2CppArray* GetTypeModifiers(Il2CppObject* prop, bool optional, int32_t genericArgumentPosition);
        static void get_property_info(Il2CppReflectionProperty* prop, Il2CppMonoPropertyInfo* info, int32_t req_info);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
