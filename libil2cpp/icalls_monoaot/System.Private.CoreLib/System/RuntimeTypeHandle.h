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
    class LIBIL2CPP_CODEGEN_API RuntimeTypeHandle
    {
    public:
        static bool HasInstantiation(Il2CppQCallTypeHandle type);
        static bool HasReferences(Il2CppQCallTypeHandle type);
        static bool IsByRefLike(Il2CppQCallTypeHandle type);
        static bool IsComObject(Il2CppQCallTypeHandle type);
        static bool IsGenericTypeDefinition(Il2CppQCallTypeHandle type);
        static bool IsInstanceOfType(Il2CppQCallTypeHandle type, Il2CppObject* o);
        static bool is_subclass_of(Il2CppQCallTypeHandle childType, Il2CppQCallTypeHandle baseType);
        static bool type_is_assignable_from(Il2CppQCallTypeHandle a, Il2CppQCallTypeHandle b);
        static int32_t GetArrayRank(Il2CppQCallTypeHandle type);
        static int32_t GetMetadataToken(Il2CppQCallTypeHandle type);
        static intptr_t GetGenericParameterInfo(Il2CppQCallTypeHandle type);
        static uint8_t GetCorElementType(Il2CppQCallTypeHandle type);
        static int32_t GetAttributes(Il2CppQCallTypeHandle type);
        static void GetAssembly(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetBaseType(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetElementType(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetGenericTypeDefinition_impl(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetModule(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void internal_from_name(const char* name, int32_t* stackMark, Il2CppObjectHandleOnStack res, bool throwOnError, bool ignoreCase);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
