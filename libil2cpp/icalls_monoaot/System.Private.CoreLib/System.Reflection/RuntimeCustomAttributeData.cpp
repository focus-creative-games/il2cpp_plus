#include "il2cpp-config.h"
#include "RuntimeCustomAttributeData.h"

#include "gc/GarbageCollector.h"
#include "gc/WriteBarrier.h"
#include "metadata/CustomAttributeDataReader.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/Exception.h"
#include "vm/MetadataCache.h"

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
    static Il2CppObject* GetBoxedValue(Il2CppClass* klass, void* data)
    {
        if (il2cpp::vm::Class::IsEnum(klass))
        {
            Il2CppClass* enumBaseType = il2cpp::vm::Class::FromIl2CppType(il2cpp::vm::Class::GetEnumBaseType(klass));
            return vm::Object::Box(enumBaseType, (void*)data);
        }

        return vm::Object::Box(klass, (void*)data);
    }

    static void SetCustomAttributeTypeArgument(Il2CppCustomAttributeTypedArgument& arg, const il2cpp::metadata::CustomAttributeArgument& inArg)
    {
        arg.type = il2cpp::vm::Reflection::GetTypeObject(inArg.klass);

        if (il2cpp::vm::Class::IsValuetype(inArg.klass))
        {
            arg.value = GetBoxedValue(inArg.klass, (void*)&inArg.data);
        }
        else
        {
            Il2CppObject* obj = reinterpret_cast<Il2CppObject*>(inArg.data.obj);
            if (obj != NULL && vm::Class::IsArray(vm::Object::GetClass(obj)))
            {
                // All array values need be returned as a ReadOnlyCollection<CustomAttributeTypedArgument>
                Il2CppArray* arr = reinterpret_cast<Il2CppArray*>(obj);
                uint32_t length = vm::Array::GetLength(arr);
                Il2CppArray* newArray = il2cpp::vm::Array::New(il2cpp_defaults.customattribute_typed_argument_class, length);

                Il2CppClass* elementClass = vm::Object::GetClass(obj)->element_class;
                Il2CppReflectionType* arrayElementReflectionType = il2cpp::vm::Reflection::GetTypeObject(elementClass);

                for (uint32_t i = 0; i < length; i++)
                {
                    Il2CppObject* elementValue;
                    Il2CppReflectionType* elementType;
                    if (vm::Class::IsValuetype(elementClass))
                    {
                        elementValue = GetBoxedValue(elementClass, il2cpp_array_addr_with_size(arr, i, elementClass->instance_size - sizeof(Il2CppObject)));
                        elementType = arrayElementReflectionType;
                    }
                    else
                    {
                        elementValue = il2cpp_array_get(arr, Il2CppObject*, i);
                        elementType = elementValue == NULL || vm::Object::GetClass(elementValue) == elementClass ? arrayElementReflectionType : il2cpp::vm::Reflection::GetTypeObject(vm::Object::GetClass(elementValue));
                    }

                    Il2CppCustomAttributeTypedArgument& element = *(Il2CppCustomAttributeTypedArgument*)il2cpp_array_addr(newArray, Il2CppCustomAttributeTypedArgument, i);
                    gc::WriteBarrier::GenericStore(&element.value, elementValue);
                    gc::WriteBarrier::GenericStore(&element.type, elementType);
                }

                if (il2cpp_defaults.generic_readonlycollection_class)
                {
                    const Il2CppType* genericType = vm::Class::GetType(il2cpp_defaults.customattribute_typed_argument_class);
                    Il2CppClass* instClass = il2cpp::vm::Class::GetInflatedGenericInstanceClass(il2cpp_defaults.generic_readonlycollection_class, il2cpp::vm::MetadataCache::GetGenericInst(&genericType, 1));
                    Il2CppReadOnlyCollection* readOnlyCollection = (Il2CppReadOnlyCollection*)il2cpp::vm::Object::New(instClass);
                    gc::WriteBarrier::GenericStore(&readOnlyCollection->list, newArray);
                    arg.value = reinterpret_cast<Il2CppObject*>(readOnlyCollection);
                }
                else
                {
                    arg.value = newArray;
                }
            }
            else
            {
                arg.value = obj;
            }
        }
    }

    class Visitor : public il2cpp::metadata::CustomAttributeReaderVisitor
    {
        Il2CppClass* attrClass;
        Il2CppArray** ctorArgs;
        Il2CppArray** namedArgs;
        uint32_t fieldCount;

    public:

        Visitor(Il2CppClass* attrClass, Il2CppArray** ctorArgs, Il2CppArray** namedArgs) : attrClass(attrClass), ctorArgs(ctorArgs), namedArgs(namedArgs), fieldCount(0)
        {
        }

        virtual void VisitArgumentSizes(uint32_t argumentCount, uint32_t fieldCount, uint32_t propertyCount)
        {
            *ctorArgs = argumentCount > 0 ? il2cpp::vm::Array::New(il2cpp_defaults.object_class, argumentCount) : NULL;
            il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)ctorArgs);

            *namedArgs = fieldCount + propertyCount > 0 ? il2cpp::vm::Array::New(il2cpp_defaults.customattribute_named_argument_class, fieldCount + propertyCount) : NULL;
            il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)namedArgs);

            this->fieldCount = fieldCount;
        }

        virtual void VisitArgument(const il2cpp::metadata::CustomAttributeArgument& argument, uint32_t index)
        {
            Il2CppCustomAttributeTypedArgument arg;
            SetCustomAttributeTypeArgument(arg, argument);
            il2cpp_array_setref(*ctorArgs, index, il2cpp::vm::Object::Box(il2cpp_defaults.customattribute_typed_argument_class, &arg));
        }

        void CreateNamedArgument(const il2cpp::metadata::CustomAttributeArgument& argument, Il2CppObject* metadataObject, uint32_t index)
        {
            Il2CppCustomAttributeNamedArgument arg;
            SetCustomAttributeTypeArgument(arg.value, argument);
            arg.memberInfo = metadataObject;
            il2cpp_array_setref(*namedArgs, index, il2cpp::vm::Object::Box(il2cpp_defaults.customattribute_named_argument_class, &arg));
        }

        virtual void VisitField(const il2cpp::metadata::CustomAttributeFieldArgument& field, uint32_t index)
        {
            CreateNamedArgument(field.arg, (Il2CppObject*)vm::Reflection::GetFieldObject(attrClass, const_cast<FieldInfo*>(field.field)), index);
        }

        virtual void VisitProperty(const il2cpp::metadata::CustomAttributePropertyArgument& prop, uint32_t index)
        {
            CreateNamedArgument(prop.arg, (Il2CppObject*)vm::Reflection::GetPropertyObject(attrClass, const_cast<PropertyInfo*>(prop.prop)), index + fieldCount);
        }
    };

    void RuntimeCustomAttributeData::ResolveArgumentsInternal(Il2CppObject* ctor, Il2CppReflectionAssembly* assembly, intptr_t data, uint32_t data_length, Il2CppArray** ctorArgs, Il2CppArray** namedArgs)
    {
        const MethodInfo* ctorMethod = ((Il2CppReflectionMethod*)ctor)->method;
        const Il2CppImage* image = ((Il2CppReflectionAssembly*)assembly)->assembly->image;

        Visitor visitor(ctor->klass, ctorArgs, namedArgs);
        Il2CppException* exc;
        il2cpp::metadata::CustomAttributeDataReader::VisitCustomAttributeData(image, ctorMethod, (const void*)data, data_length, &visitor, &exc);

        if (exc != NULL)
            vm::Exception::Raise(exc);
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
