#include "il2cpp-config.h"
#include "GCHandle.h"
#include "gc/GCHandle.h"
#include "vm/Exception.h"

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
namespace Runtime
{
namespace InteropServices
{
    intptr_t GCHandle::InternalAlloc(Il2CppObject* value, int32_t type)
    {
        if (type == gc::HANDLE_WEAK_TRACK || type == gc::HANDLE_WEAK)
        {
            auto expected = gc::GCHandle::NewWeakref(value, type == gc::HANDLE_WEAK_TRACK);
            vm::Exception::RaiseIfError(expected.GetError());
            return reinterpret_cast<intptr_t>(expected.Get());
        }
        else
        {
            return reinterpret_cast<intptr_t>(gc::GCHandle::New(value, type == gc::HANDLE_PINNED));
        }
    }

    Il2CppObject* GCHandle::InternalGet(intptr_t handle)
    {
        return gc::GCHandle::GetTarget(reinterpret_cast<Il2CppGCHandle>(handle));
    }

    void GCHandle::InternalFree(intptr_t handle)
    {
        gc::GCHandle::Free(reinterpret_cast<Il2CppGCHandle>(handle));
    }

    void GCHandle::InternalSet(intptr_t handle, Il2CppObject* value)
    {
        gc::GCHandle::SetTarget(reinterpret_cast<Il2CppGCHandle>(handle), value);
    }
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
