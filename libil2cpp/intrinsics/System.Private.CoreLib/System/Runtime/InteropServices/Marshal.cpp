#include "Marshal.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "vm/CCW.h"
#include "vm/COM.h"
#include "vm/RCW.h"
#include "vm/Exception.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Runtime
{
namespace InteropServices
{
#if IL2CPP_SUPPORTS_COM_INTEROP
    static void ThrowIfComNotSupported()
    {
    }

#else
    NORETURN static void ThrowIfComNotSupported()
    {
        vm::Exception::Raise(vm::Exception::GetPlatformNotSupportedException("No COM support"));
    }

#endif

    intptr_t il2cpp_intrinsic_marshal_get_com_interface_for_object(RuntimeObject* o, Type_t* T)
    {
        ThrowIfComNotSupported();

        return reinterpret_cast<intptr_t>(il2cpp::vm::CCW::GetCCW(o, reinterpret_cast<Il2CppReflectionType*>(T)));
    }

    RuntimeObject* il2cpp_intrinsic_marshal_get_object_for_i_unknown(intptr_t pUnk)
    {
        ThrowIfComNotSupported();

        if (pUnk == 0)
            return NULL;

        return il2cpp::vm::RCW::GetOrCreateFromIUnknown(reinterpret_cast<Il2CppIUnknown*>(pUnk), il2cpp_defaults.il2cpp_com_object_class);
    }

    int32_t il2cpp_intrinsic_marshal_release_com_object(RuntimeObject* co)
    {
        ThrowIfComNotSupported();

        // There's a check in mscorlib before calling this internal icall, so assert instead of full check is OK here.
        IL2CPP_ASSERT(co->klass->is_import_or_windows_runtime);

        int32_t newRefCount = os::Atomic::Decrement(&static_cast<Il2CppComObject*>(co)->refCount);
        if (newRefCount == 0)
        {
            // We can't really release the COM object directly, because it might have additional
            // fields that cache different interfaces. So let's just call its finalizer here.
            // In order to deal with the fact that this may get called from different threads
            // at the same time, we (atomically) register a NULL finalizer, and if another finalizer
            // was already registered, we call it. If there was no finalizer registered, it means
            // that we lost the race and we should just carry on.
            gc::GarbageCollector::FinalizerCallback oldFinalizer = gc::GarbageCollector::RegisterFinalizerWithCallback(co, NULL);
            if (oldFinalizer != NULL)
                oldFinalizer(co, NULL);
        }

        return newRefCount;
    }
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
