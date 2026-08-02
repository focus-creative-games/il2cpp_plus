#include "il2cpp-config.h"
#include "Stream.h"

#include "vm/Class.h"
#include "vm/Object.h"

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
namespace IO
{
    static VTableIndex s_BeginReadVTableIndex;
    static VTableIndex s_EndReadVTableIndex;
    static VTableIndex s_BeginWriteVTableIndex;
    static VTableIndex s_EndWriteVTableIndex;
    static const MethodInfo* s_BeginReadMethod;
    static const MethodInfo* s_EndReadMethod;
    static const MethodInfo* s_BeginWriteMethod;
    static const MethodInfo* s_EndWriteMethod;

    static void AssertBeginEndMethodsLookCorrect(const MethodInfo* beginMethod, const MethodInfo* endMethod, const Il2CppClass* endReturnType)
    {
        if (beginMethod != NULL)
        {
            IL2CPP_ASSERT(vm::Class::FromIl2CppType(beginMethod->parameters[0]) == vm::Class::GetArrayClass(il2cpp_defaults.byte_class, 1));
            IL2CPP_ASSERT(vm::Class::FromIl2CppType(beginMethod->parameters[1]) == il2cpp_defaults.int32_class);
            IL2CPP_ASSERT(vm::Class::FromIl2CppType(beginMethod->parameters[2]) == il2cpp_defaults.int32_class);
            IL2CPP_ASSERT(vm::Class::IsSubclassOf(vm::Class::FromIl2CppType(beginMethod->parameters[3]), il2cpp_defaults.multicastdelegate_class, false));
            IL2CPP_ASSERT(vm::Class::FromIl2CppType(beginMethod->parameters[4]) == il2cpp_defaults.object_class);
        }
        if (endMethod != NULL)
        {
            IL2CPP_ASSERT(vm::Class::FromIl2CppType(endMethod->return_type) == endReturnType);
        }
    }

    static std::tuple<const MethodInfo*, VTableIndex> SetupVTableMethod(Il2CppClass* streamClass, const char* methodName, int parameterCount)
    {
        const MethodInfo* method = vm::Class::GetMethodFromName(streamClass, methodName, parameterCount);
        VTableIndex vTableIndex = method ? vm::Class::VTableIndexForMethod(streamClass, method) : kInvalidIl2CppMethodSlot;

        IL2CPP_ASSERT(method == NULL || vTableIndex != kInvalidIl2CppMethodSlot);

        if (vTableIndex == kInvalidIl2CppMethodSlot)
        {
            // Method was stripped - return something so the icall won't crash if it ends up being called
            // This would crash if Stream has no virtual methods - but in that case the icall won't be called
            return { NULL, 0 };
        }
        return { method, vTableIndex };
    }

    void Stream::Init(Il2CppClass* streamClass)
    {
        if (streamClass == NULL)
            return;

        vm::Class::Init(streamClass);
        std::tie(s_BeginReadMethod, s_BeginReadVTableIndex) = SetupVTableMethod(streamClass, "BeginRead", 5);
        std::tie(s_EndReadMethod, s_EndReadVTableIndex) = SetupVTableMethod(streamClass, "EndRead", 1);
        std::tie(s_BeginWriteMethod, s_BeginWriteVTableIndex) = SetupVTableMethod(streamClass, "BeginWrite", 5);
        std::tie(s_EndWriteMethod, s_EndWriteVTableIndex) = SetupVTableMethod(streamClass, "EndWrite", 1);

        AssertBeginEndMethodsLookCorrect(s_BeginReadMethod, s_EndReadMethod, il2cpp_defaults.int32_class);
        AssertBeginEndMethodsLookCorrect(s_BeginWriteMethod, s_EndWriteMethod, il2cpp_defaults.void_class);
    }

    bool Stream::HasOverriddenBeginEndRead(Il2CppObject* thisPtr)
    {
        IL2CPP_ASSERT(thisPtr);
        IL2CPP_ASSERT(vm::Object::IsInst(thisPtr, il2cpp_defaults.stream_class));

        VirtualInvokeData* vtable = vm::Object::GetClass(thisPtr)->vtable;
        return vtable[s_BeginReadVTableIndex].method != s_BeginReadMethod || vtable[s_EndReadVTableIndex].method != s_EndReadMethod;
    }

    bool Stream::HasOverriddenBeginEndWrite(Il2CppObject* thisPtr)
    {
        IL2CPP_ASSERT(thisPtr);
        IL2CPP_ASSERT(vm::Object::IsInst(thisPtr, il2cpp_defaults.stream_class));

        VirtualInvokeData* vtable = vm::Object::GetClass(thisPtr)->vtable;
        return vtable[s_BeginWriteVTableIndex].method != s_BeginWriteMethod || vtable[s_EndWriteVTableIndex].method != s_EndWriteMethod;
    }
} // namespace IO
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
