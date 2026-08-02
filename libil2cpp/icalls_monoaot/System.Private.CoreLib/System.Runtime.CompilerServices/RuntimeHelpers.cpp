#include "il2cpp-config.h"
#include "RuntimeHelpers.h"

#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "il2cpp-tabledefs.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Field.h"
#include "vm/Object.h"
#include "vm/Runtime.h"
#include "vm/Type.h"
#include "utils/HashUtils.h"
#include <memory>

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
namespace CompilerServices
{
    bool RuntimeHelpers::SufficientExecutionStack()
    {
        return true;
    }

    int32_t RuntimeHelpers::InternalGetHashCode(Il2CppObject* o)
    {
        return (int32_t)utils::HashUtils::AlignedPointerHash(o);
    }

    int32_t RuntimeHelpers::InternalTryGetHashCode(Il2CppObject* o)
    {
        return (int32_t)utils::HashUtils::AlignedPointerHash(o);
    }

    void* RuntimeHelpers::GetSpanDataFrom(FieldInfo* fldHandle, Il2CppType* targetTypeHandle, int32_t* count)
    {
#if IL2CPP_BYTE_ORDER != IL2CPP_LITTLE_ENDIAN
        // The data is encoded little endian, if bit endian support is needed a byte swap will be needed
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeHelpers::GetSpanDataFrom)
#endif
        Il2CppClass* klass = vm::Class::FromIl2CppType(targetTypeHandle);

        size_t dataSize;
        const char* data = vm::Field::GetData(fldHandle, &dataSize);
        int32_t classSize = vm::Class::GetValueSize(klass, NULL);

        *count = static_cast<int32_t>(dataSize / classSize);
        return (void*)data;
    }

    Il2CppObject* RuntimeHelpers::GetObjectValue(Il2CppObject* obj)
    {
        if (obj == NULL || !vm::Class::IsValuetype(obj->klass))
            return obj;
        else
            return vm::Object::Clone(obj);
    }

    Il2CppObject* RuntimeHelpers::GetUninitializedObjectInternal(intptr_t type)
    {
        Il2CppClass* klass = vm::Class::FromIl2CppType(reinterpret_cast<const Il2CppType*>(type));
        return vm::Object::New(klass);
    }

    void RuntimeHelpers::InitializeArray(Il2CppArray* array, intptr_t fldHandle)
    {
        FieldInfo* field_handle = (FieldInfo*)fldHandle;
        Il2CppClass *klass = array->klass;
        uint32_t size = vm::Array::GetElementSize(klass);
        const Il2CppType *type = vm::Type::GetUnderlyingType(&klass->element_class->byval_arg);

        const char *field_data;

        if (vm::Type::IsReference(type) || (type->type == IL2CPP_TYPE_VALUETYPE && (!vm::Type::GetClass(type) || vm::Type::GetClass(type)->has_references)))
        {
            Il2CppException *exc = vm::Exception::GetArgumentException("array",
                "Cannot initialize array containing references");
            vm::Exception::Raise(exc);
        }

        if (!(field_handle->type->attrs & FIELD_ATTRIBUTE_HAS_FIELD_RVA))
        {
            Il2CppException *exc = vm::Exception::GetArgumentException("field_handle", "Field doesn't have an RVA");
            vm::Exception::Raise(exc);
        }

        size *= ARRAY_LENGTH_AS_INT32(array->max_length);
        size_t fieldDataSize;
        field_data = vm::Field::GetData(field_handle, &fieldDataSize);

        IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(RuntimeHelpers::InitializeArray, "Check type size");
        //int align;
        //if (size > mono_type_size (field_handle->type, &align)) {
        //  MonoException *exc = mono_get_exception_argument("field_handle",
        //      "Field not large enough to fill array");
        //  mono_raise_exception (exc);
        //}

        IL2CPP_NOT_IMPLEMENTED_ICALL_NO_ASSERT(RuntimeHelpers::InitializeArray, "Ignoring Endianess");
        memcpy(il2cpp_array_addr(array, char, 0), field_data, size);
    }

    void RuntimeHelpers::PrepareMethod(intptr_t method, intptr_t* instantiations, int32_t ninst)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeHelpers::PrepareMethod);
        IL2CPP_UNREACHABLE;
    }

    void RuntimeHelpers::RunClassConstructor(intptr_t typeIntPtr)
    {
        const Il2CppType* type = reinterpret_cast<const Il2CppType*>(typeIntPtr);
        IL2CPP_CHECK_ARG_NULL(type);

        Il2CppClass* klass = vm::Class::FromIl2CppType(type);
        //MONO_CHECK_ARG(handle, klass);

        il2cpp::vm::Runtime::ClassInit(klass);
    }

    void RuntimeHelpers::RunModuleConstructor(intptr_t module)
    {
        NOT_SUPPORTED_IL2CPP(RuntimeHelpers::RunModuleConstructor, "This icall is not supported by il2cpp.");
    }
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
