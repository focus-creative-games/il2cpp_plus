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
    class LIBIL2CPP_CODEGEN_API RuntimeMethodInfo
    {
    public:
        static bool get_IsGenericMethod(Il2CppObject* thisPtr);
        static bool get_IsGenericMethodDefinition(Il2CppObject* thisPtr);
        static int32_t get_metadata_token(Il2CppObject* method);
        static Il2CppObject* InternalInvoke(Il2CppReflectionMethod* method, Il2CppObject* thisPtr, intptr_t* args, Il2CppException** exc);
        static Il2CppReflectionMethod* GetMethodFromHandleInternalType_native(intptr_t method_handle, intptr_t type_handle, bool genericCheck);
        static Il2CppObject* GetMethodBodyInternal(intptr_t handle);
        static Il2CppReflectionMethod* GetGenericMethodDefinition_impl(Il2CppReflectionMethod* thisPtr);
        static Il2CppReflectionMethod* MakeGenericMethod_impl(Il2CppReflectionMethod* thisPtr, Il2CppArray* types);
        static Il2CppReflectionMethod* get_base_method(Il2CppReflectionMethod* method, bool definition);
        static Il2CppString* get_name(Il2CppReflectionMethod* reflectionMethod);
        static Il2CppArray* GetGenericArguments(Il2CppReflectionMethod* thisPtr);
        static void GetPInvoke(Il2CppObject* thisPtr, int32_t* flags, Il2CppString** entryPoint, Il2CppString** dllName);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
