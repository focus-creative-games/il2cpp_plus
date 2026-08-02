#include "ClassInlines.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Method.h"
#include "vm/RCW.h"
#include "vm/Runtime.h"
#include "gc/GCHandle.h"
#include "metadata/GenericMethod.h"

namespace il2cpp
{
namespace vm
{
    Il2CppClass* ClassInlines::InitFromCodegenSlow(Il2CppClass *klass)
    {
        Class::Init(klass);

        if (klass->initializationExceptionGCHandle)
            il2cpp::vm::Exception::Raise((Il2CppException*)gc::GCHandle::GetTarget(klass->initializationExceptionGCHandle));

        return klass;
    }

    const MethodInfo* ClassInlines::InitRgctxFromCodegenSlow(const MethodInfo* method)
    {
        Il2CppException* exc = NULL;
        il2cpp::metadata::GenericMethod::InflateRGCTX(method, &exc);
        if (exc)
            il2cpp::vm::Exception::Raise(exc);

        return method;
    }

    NORETURN static void RaiseExceptionForNotFoundInterface(const Il2CppClass* klass, const Il2CppClass* itf, Il2CppMethodSlot slot)
    {
        if (il2cpp::vm::Method::IsAmbiguousMethodClass(itf))
        {
            il2cpp::vm::Runtime::RaiseAmbiguousImplementationException(NULL, klass);
        }
        else if (il2cpp::vm::Method::IsEntryPointNotFoundMethodClass(itf))
        {
            il2cpp::vm::Runtime::RaiseEntryPointNotFoundException(NULL, klass);
        }
        else
        {
            std::string message;
            message = "Attempt to access method '" + Type::GetName(&itf->byval_arg, IL2CPP_TYPE_NAME_FORMAT_IL) + "." + Method::GetName(itf->methods[slot])
                + "' on type '" + Type::GetName(&klass->byval_arg, IL2CPP_TYPE_NAME_FORMAT_IL) + "' failed.";
            Exception::Raise(il2cpp::vm::Exception::GetMethodAccessException(message.c_str()));
        }
    }

    const VirtualInvokeData* ClassInlines::GetInterfaceInvokeDataFromVTableSlowPathMaybeNull(const Il2CppClass* klass, const Il2CppClass* itf, Il2CppMethodSlot slot)
    {
        if (itf->generic_class != NULL)
        {
            for (uint16_t i = 0; i < klass->interface_offsets_count; ++i)
            {
                const Il2CppRuntimeInterfaceOffsetPair* pair = klass->interfaceOffsets + i;
                if (Class::IsGenericClassAssignableFromVariance(itf, pair->interfaceType, klass))
                {
                    IL2CPP_ASSERT(pair->offset + slot < klass->vtable_count);
                    return &klass->vtable[pair->offset + slot];
                }
            }
        }

        return NULL;
    }

    const VirtualInvokeData& ClassInlines::GetInterfaceInvokeDataFromVTableSlowPath(const Il2CppClass* klass, const Il2CppClass* itf, Il2CppMethodSlot slot)
    {
        const VirtualInvokeData* data = GetInterfaceInvokeDataFromVTableSlowPathMaybeNull(klass, itf, slot);
        if (data)
            return *data;

        RaiseExceptionForNotFoundInterface(klass, itf, slot);
        IL2CPP_UNREACHABLE;
    }

    const VirtualInvokeData& ClassInlines::GetInterfaceInvokeDataFromVTableSlowPath(Il2CppObject* obj, const Il2CppClass* itf, Il2CppMethodSlot slot)
    {
        const Il2CppClass* klass = obj->klass;
        const VirtualInvokeData* data;

        data = GetInterfaceInvokeDataFromVTableSlowPathMaybeNull(klass, itf, slot);
        if (data)
            return *data;

        if (klass->is_import_or_windows_runtime)
        {
            Il2CppComObject* rcw = static_cast<Il2CppComObject*>(obj);

            // It might be null if it's called on a dead (already released) or fake object
            if (rcw->identity != NULL)
            {
                const VirtualInvokeData* invokeData = RCW::GetComInterfaceInvokeData(rcw, itf, slot);
                if (invokeData != NULL)
                {
                    // Nothing will be referencing these types directly, so we need to initialize them here
                    Class::Init(invokeData->method->klass);
                    return *invokeData;
                }
            }
        }

        RaiseExceptionForNotFoundInterface(klass, itf, slot);
        IL2CPP_UNREACHABLE;
    }
}
}
