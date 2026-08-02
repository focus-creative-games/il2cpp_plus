#include "il2cpp-config.h"
#include "Marshal.h"

#include "gc/GarbageCollector.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-tabledefs.h"
#include "metadata/FieldLayout.h"
#include "os/Atomic.h"
#include "os/MarshalStringAlloc.h"
#include "utils/MarshalingUtils.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/CCW.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Field.h"
#include "vm/Image.h"
#include "vm/LastError.h"
#include "vm/MarshalAlloc.h"
#include "vm/Object.h"
#include "vm/PlatformInvoke.h"
#include "vm/RCW.h"
#include "vm/String.h"
#include "vm/Type.h"
#include <algorithm>
#include <deque>
#include <string>

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
    static size_t RoundUpToMultiple(size_t numToRound, size_t multiple)
    {
        if (multiple == 0)
            return numToRound;

        size_t remainder = numToRound % multiple;
        if (remainder == 0)
            return numToRound;
        return numToRound + multiple - remainder;
    }

    int32_t Marshal::GetLastPInvokeError()
    {
        return static_cast<int32_t>(il2cpp::vm::LastError::GetLastError());
    }

    int32_t Marshal::SizeOfHelper(Il2CppQCallTypeHandle t, bool throwIfNotMarshalable)
    {
        Il2CppType* type = t;

        if (type == NULL)
            vm::Exception::Raise(vm::Exception::GetArgumentNullException("t"));

        Il2CppClass* typeInfo = vm::Class::FromIl2CppType(type);

        if (typeInfo->native_size != -1)
        {
            // SizeOf "cannot" get size of enums and strings
            if (!typeInfo->enumtype && type->type != IL2CPP_TYPE_STRING)
                return typeInfo->native_size;
        }

        // If we get to here, type does not have a native size
        // So let's figure what kind of exception to throw

        if (throwIfNotMarshalable)
        {
            if (typeInfo->generic_class != NULL || typeInfo->is_generic)
                vm::Exception::Raise(vm::Exception::GetArgumentException("t", "The t parameter is a generic type."));

            std::string exceptionMessage = utils::StringUtils::Printf("Type \'%s\' cannot be marshaled as an unmanaged structure; no meaningful size or offset can be computed.",
                vm::Type::GetName(type, IL2CPP_TYPE_NAME_FORMAT_FULL_NAME).c_str());

            vm::Exception::Raise(vm::Exception::GetArgumentException(NULL, exceptionMessage.c_str()));
        }
        return 0;
    }

    intptr_t Marshal::GetFunctionPointerForDelegateInternal(Il2CppDelegate* d)
    {
        return vm::PlatformInvoke::MarshalDelegate(d);
    }

    intptr_t Marshal::OffsetOf(Il2CppReflectionType* t, Il2CppString* fieldName)
    {
        std::string fieldNameToFind = utils::StringUtils::Utf16ToUtf8(fieldName->chars);
        Il2CppClass* type = il2cpp::vm::Class::FromIl2CppType(t->type);

        FieldInfo* field = vm::Class::GetFieldFromName(type, fieldNameToFind.c_str());
        if (field == NULL || (vm::Field::GetFlags(field) & FIELD_ATTRIBUTE_STATIC))
        {
            std::string message;
            message = "Field '" + fieldNameToFind + "' is not a marshaled member of the type '" + type->name + "'";
            vm::Exception::Raise(vm::Exception::GetArgumentException("fieldName", message.c_str()));
        }

        // Order the base classes so the most base class is first.
        std::deque<Il2CppClass*> inheritanceHierarchy;
        while (type)
        {
            inheritanceHierarchy.push_front(type);
            type = type->parent;
        }

        bool fieldFound = false;

        size_t offset = 0;
        FieldInfo* previousField = NULL;
        for (std::deque<Il2CppClass*>::iterator it = inheritanceHierarchy.begin(); it < inheritanceHierarchy.end(); ++it)
        {
            type = *it;
            void* iter = NULL;
            int layout = vm::Class::GetFlags(type) & TYPE_ATTRIBUTE_LAYOUT_MASK;
            bool layoutIsExplicit = layout == TYPE_ATTRIBUTE_EXPLICIT_LAYOUT;

            while ((field = vm::Class::GetFields(type, &iter)))
            {
                if (vm::Field::GetFlags(field) & FIELD_ATTRIBUTE_STATIC)
                    continue;

                if (layoutIsExplicit)
                {
                    offset = field->offset - sizeof(Il2CppObject);
                }
                else if (previousField != NULL) // Determine how much the previous field added to the offset.
                {
                    if (!vm::Type::IsStruct(previousField->type))
                    {
                        size_t managedOffset = field->offset - previousField->offset;
                        if (managedOffset != 0) // overlapping fields have a zero offset
                        {
                            offset += vm::Class::GetFieldMarshaledSize(previousField);
                        }
                    }
                    else
                    {
                        offset += vm::Class::FromIl2CppType(previousField->type)->native_size;
                    }

                    if (offset != 0)
                    {
                        int marshaledFieldAlignment = vm::Class::GetFieldMarshaledAlignment(field);
                        offset = RoundUpToMultiple(offset, type->packingSize == 0 ? marshaledFieldAlignment : std::min((int)type->packingSize, marshaledFieldAlignment));
                    }
                }
                else
                {
                    // If this is the first field, it might have a non-zero offset, as it could be in a type
                    // with an explicit layout. So calculate it offset based on the distance it is from the
                    // end of the object header.
                    offset = field->offset - sizeof(Il2CppObject);
                }

                previousField = field;

                if (fieldNameToFind == vm::Field::GetName(field))
                {
                    fieldFound = true;
                    break;
                }
            }

            if (fieldFound)
                break;
        }

        return static_cast<intptr_t>(offset);
    }

    void Marshal::DestroyStructure(intptr_t ptr, Il2CppReflectionType* structureType)
    {
        if (ptr == 0)
            vm::Exception::Raise(vm::Exception::GetArgumentNullException("ptr"));

        if (structureType == NULL)
            vm::Exception::Raise(vm::Exception::GetArgumentNullException("structureType"));

        Il2CppClass* type = vm::Class::FromIl2CppType(structureType->type);

        // If cleanup function exists, it will call it and return true
        // In that case, we're done.
        if (utils::MarshalingUtils::MarshalFreeStruct(reinterpret_cast<void*>(ptr), type->interopData))
            return;

        if (type->is_generic || type->generic_class != NULL)
        {
            vm::Exception::Raise(vm::Exception::GetArgumentException("structureType", "The specified type must not be a generic type definition."));
        }

        // Enums are blittable, but they don't have layout information, therefore Marshal.DestroyStructure is supposed to throw
        if (!type->enumtype)
        {
            // Char and Boolean are not blittable, but they should not raise this exception, as we can call DestroyStructure on them without problems.
            if (type->is_blittable || structureType->type->type == IL2CPP_TYPE_CHAR || structureType->type->type == IL2CPP_TYPE_BOOLEAN)
                return;
        }

        // If we got this far, throw an exception
        vm::Exception::Raise(vm::Exception::GetArgumentException("structureType", "The specified type must be blittable or have layout information."));
    }

    void Marshal::GetDelegateForFunctionPointerInternal(Il2CppQCallTypeHandle t, intptr_t ptr, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* delegateType = il2cpp::vm::Class::FromIl2CppType(t);
        res = (Il2CppObject*)vm::PlatformInvoke::MarshalFunctionPointerToDelegate(reinterpret_cast<void*>(ptr), delegateType);
    }

    void Marshal::PrelinkInternal(Il2CppObject* m)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(Marshal::PrelinkInternal);
        IL2CPP_UNREACHABLE;
    }

    void Marshal::PtrToStructureInternal(intptr_t ptr, Il2CppObject* structure, bool allowValueClasses)
    {
        Il2CppClass* type = vm::Object::GetClass(structure);

        if (!allowValueClasses && vm::Class::IsValuetype(type))
            vm::Exception::Raise(vm::Exception::GetArgumentException("structure", "The specified structure must be an instance of a formattable class."));

        if (type->interopData != NULL && type->interopData->pinvokeMarshalFromNativeFunction != NULL)
        {
            if (vm::Class::IsValuetype(type))
                utils::MarshalingUtils::MarshalStructFromNative(reinterpret_cast<void*>(ptr), vm::Object::GetRawData(structure), type->interopData);
            else
                utils::MarshalingUtils::MarshalStructFromNative(reinterpret_cast<void*>(ptr), structure, type->interopData);

            return;
        }

        // If there's no custom marshal function, it means it's either a primitive, or invalid argument
        if (type->native_size != -1)
        {
            // PtrToStructure is supposed to throw on enums
            if (!vm::Class::IsEnum(type))
            {
                memcpy(vm::Object::GetRawData(structure), reinterpret_cast<void*>(ptr), type->native_size);
                return;
            }
        }

        // If we got this far, throw an exception
        if (vm::Class::IsInflated(type) || vm::Class::IsGeneric(type))
            vm::Exception::Raise(vm::Exception::GetArgumentException("structure", "The specified object must not be an instance of a generic type."));

        vm::Exception::Raise(vm::Exception::GetArgumentException("structure", "The specified structure must be blittable or have layout information."));
    }

    void Marshal::SetLastPInvokeError(int32_t error)
    {
        return il2cpp::vm::LastError::SetLastError(static_cast<uint32_t>(error));
    }

    void Marshal::StructureToPtr(Il2CppObject* structure, intptr_t ptr, bool fDeleteOld)
    {
        if (structure == NULL)
            vm::Exception::Raise(vm::Exception::GetArgumentNullException("structure"));

        if (ptr == 0)
            vm::Exception::Raise(vm::Exception::GetArgumentNullException("ptr"));

        Il2CppClass* type = structure->klass;

        if (type->interopData != NULL && type->interopData->pinvokeMarshalToNativeFunction != NULL)
        {
            if (fDeleteOld)
                utils::MarshalingUtils::MarshalFreeStruct(reinterpret_cast<void*>(ptr), type->interopData);

            void* objectPtr = (type->byval_arg.type == IL2CPP_TYPE_CLASS) ? structure : vm::Object::GetRawData(structure);
            utils::MarshalingUtils::MarshalStructToNative(objectPtr, reinterpret_cast<void*>(ptr), type->interopData);
            return;
        }

        // If there's no custom marshal function, it means it's either a primitive, or invalid argument

        if (type->native_size != -1)
        {
            // StructureToPtr is supposed to throw on strings and enums
            if (!type->enumtype && type->byval_arg.type != IL2CPP_TYPE_STRING)
            {
                memcpy(reinterpret_cast<void*>(ptr), vm::Object::GetRawData(structure), type->native_size);
                return;
            }
        }

        // If we got this far, throw an exception
        Il2CppException* exception;

        if (type->generic_class != NULL || type->is_generic)
        {
            exception = vm::Exception::GetArgumentException("structure", "The specified object must not be an instance of a generic type.");
        }
        else
        {
            exception = vm::Exception::GetArgumentException("structure", "The specified structure must be blittable or have layout information.");
        }

        vm::Exception::Raise(exception);
    }
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
