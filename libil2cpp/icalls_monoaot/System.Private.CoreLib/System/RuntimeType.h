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
    enum
    {
        BFLAGS_IgnoreCase = 1,
        BFLAGS_DeclaredOnly = 2,
        BFLAGS_Instance = 4,
        BFLAGS_Static = 8,
        BFLAGS_Public = 0x10,
        BFLAGS_NonPublic = 0x20,
        BFLAGS_FlattenHierarchy = 0x40,
        BFLAGS_InvokeMethod = 0x100,
        BFLAGS_CreateInstance = 0x200,
        BFLAGS_GetField = 0x400,
        BFLAGS_SetField = 0x800,
        BFLAGS_GetProperty = 0x1000,
        BFLAGS_SetProperty = 0x2000,
        BFLAGS_ExactBinding = 0x10000,
        BFLAGS_SuppressChangeType = 0x20000,
        BFLAGS_OptionalParamBinding = 0x40000,
        BFLAGS_MatchAll = 0xFFFFF
    };

    enum
    {
        MLISTTYPE_All = 0,
        MLISTTYPE_CaseSensitive = 1,
        MLISTTYPE_CaseInsensitive = 2,
        MLISTTYPE_HandleToInfo = 3
    };

    class LIBIL2CPP_CODEGEN_API RuntimeType
    {
    public:
        static bool IsUnmanagedFunctionPointerInternal(Il2CppQCallTypeHandle type);
        static uint8_t GetCallingConventionFromFunctionPointerInternal(Il2CppQCallTypeHandle type);
        static int32_t GetGenericParameterPosition(Il2CppQCallTypeHandle type);
        static intptr_t FunctionPointerReturnAndParameterTypes(Il2CppQCallTypeHandle type);
        static intptr_t GetConstructors_native(Il2CppQCallTypeHandle type, int32_t bindingAttr);
        static intptr_t GetEvents_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t listType);
        static intptr_t GetFields_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t bindingAttr, int32_t listType);
        static intptr_t GetMethodsByName_native(Il2CppQCallTypeHandle type, intptr_t namePtr, int32_t bindingAttr, int32_t listType);
        static intptr_t GetNestedTypes_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t bindingAttr, int32_t listType);
        static intptr_t GetPropertiesByName_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t bindingAttr, int32_t listType);
        static Il2CppObject* CreateInstanceInternal(Il2CppQCallTypeHandle type);
        static Il2CppObject* GetCorrespondingInflatedMethod(Il2CppQCallTypeHandle type, Il2CppObject* generic);
        static Il2CppArray* GetFunctionPointerTypeModifiers(Il2CppQCallTypeHandle type, int32_t position, bool optional);
        static void AllocateValueType(Il2CppQCallTypeHandle type, Il2CppObject* value, Il2CppObjectHandleOnStack res);
        static void GetDeclaringMethod(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetDeclaringType(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetGenericArgumentsInternal(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res, bool runtimeArray);
        static void GetInterfaceMapData(Il2CppQCallTypeHandle t, Il2CppQCallTypeHandle iface, Il2CppArray** targets, Il2CppArray** methods);
        static void GetInterfaces(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetName(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetNamespace(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void GetPacking(Il2CppQCallTypeHandle type, int32_t* packing, int32_t* size);
        static void MakeGenericType(Il2CppReflectionType* gt, Il2CppArray* types, Il2CppObjectHandleOnStack res);
        static void getFullName(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res, bool full_name, bool assembly_qualified);
        static void make_array_type(Il2CppQCallTypeHandle type, int32_t rank, Il2CppObjectHandleOnStack res);
        static void make_byref_type(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
        static void make_pointer_type(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
