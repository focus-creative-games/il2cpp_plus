#include "il2cpp-config.h"
#include "RuntimeMethodHandle.h"

#include "gc/GarbageCollector.h"
#include "vm/Exception.h"
#include "vm/MetadataCache.h"
#include "vm/Method.h"
#include "vm/Object.h"
#include "vm/Runtime.h"

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
    intptr_t RuntimeMethodHandle::GetFunctionPointer(intptr_t m)
    {
        MethodInfo* method = reinterpret_cast<MethodInfo*>(m);
        if (method->is_unmanaged_callers_only)
            return reinterpret_cast<intptr_t>(il2cpp::vm::MetadataCache::GetReversePInvokeWrapper(method->klass->image, method));
        return reinterpret_cast<intptr_t>(method);
    }

    void RuntimeMethodHandle::ReboxFromNullable(Il2CppObject* src, Il2CppObjectHandleOnStack res)
    {
        if (src == NULL)
        {
            res = nullptr;
            return;
        }

        Il2CppClass* nullableClass = il2cpp::vm::Object::GetClass(src);
        if (!il2cpp::vm::Class::IsNullable(nullableClass))
        {
            res = src;
            return;
        }

        res = il2cpp::vm::Object::Box(nullableClass, reinterpret_cast<uint8_t*>(vm::Object::GetRawData(src)));
    }

    void RuntimeMethodHandle::ReboxToNullable(Il2CppObject* src, Il2CppQCallTypeHandle destNullableType, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* nullableClass = il2cpp::vm::Class::FromIl2CppType(destNullableType);
        Il2CppObject* boxed = il2cpp::vm::Object::NewBoxedNullable(nullableClass);

        if (src != NULL)
            vm::Object::NullableInit(reinterpret_cast<uint8_t*>(vm::Object::GetRawData(boxed)), src, nullableClass);

        res = boxed;
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
