#include "il2cpp-config.h"
#include "CustomAttribute.h"

#include "metadata/CustomAttributeDataReader.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
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
namespace Reflection
{
    Il2CppArray* CustomAttribute::GetCustomAttributesInternal(Il2CppObject* obj, Il2CppReflectionType* attributeType, bool pseudoAttrs)
    {
        IL2CPP_ASSERT(pseudoAttrs == false && "System.Reflection.GetCustomAttributesInternal with pseudoAttrs == true has not been implemented yet");

        Il2CppClass* attributeClass = attributeType != NULL ? vm::Class::FromIl2CppType(attributeType->type) : NULL;

        Il2CppArray* result = il2cpp::vm::Reflection::GetCustomAttrsInfo(obj, attributeClass);

        if (!result)
            return il2cpp::vm::Array::New(il2cpp_defaults.attribute_class, 0);

        return result;
    }

    bool CustomAttribute::IsDefinedInternal(Il2CppObject* obj, Il2CppReflectionType* attributeType)
    {
        return il2cpp::vm::Reflection::HasAttribute(obj, vm::Class::FromIl2CppType(attributeType->type));
    }

    static Il2CppObject* CreateCustomAttributeData(const Il2CppAssembly* assembly, const il2cpp::metadata::LazyCustomAttributeData& data)
    {
        static const MethodInfo* runtimeCustomAttributeDataConstructor;
        if (!runtimeCustomAttributeDataConstructor)
        {
            runtimeCustomAttributeDataConstructor = vm::Class::GetMethodFromName(il2cpp_defaults.runtime_customattribute_data_class, ".ctor", 4);
            if (runtimeCustomAttributeDataConstructor == NULL)
                IL2CPP_NOT_IMPLEMENTED_ICALL(CustomAttribute::GetCustomAttributesDataInternal);
        }

        Il2CppObject* customAttributeData = vm::Object::New(il2cpp_defaults.runtime_customattribute_data_class);
        void* params[] =
        {
            vm::Reflection::GetMethodObject(data.ctor, data.ctor->klass),
            vm::Reflection::GetAssemblyObject(assembly),
            (void*)&data.dataStart,
            (void*)&data.dataLength
        };
        vm::Runtime::Invoke(runtimeCustomAttributeDataConstructor, customAttributeData, params, NULL);
        return customAttributeData;
    }

    Il2CppArray* CustomAttribute::GetCustomAttributesDataInternal(Il2CppObject* obj)
    {
        metadata::CustomAttributeDataReader reader = il2cpp::vm::Reflection::GetCustomAttrsDataReader(obj);

        uint32_t count = reader.GetCount();

        Il2CppArray* result = il2cpp::vm::Array::New(il2cpp_defaults.runtime_customattribute_data_class, reader.GetCount());

        if (count == 0)
            return result;

        uint32_t i = 0;

        bool hasError = false;
        il2cpp::metadata::LazyCustomAttributeData data;
        Il2CppException* exc = NULL;
        il2cpp::metadata::CustomAttributeDataIterator iter = reader.GetDataIterator();
        while (reader.ReadLazyCustomAttributeData(&data, &iter, &exc))
        {
            IL2CPP_ASSERT(i < reader.GetCount());
            Il2CppObject* attributeData = CreateCustomAttributeData(obj->klass->image->assembly, data);
            il2cpp_array_setref(result, i, attributeData);
            i++;
        }

        if (exc != NULL)
            vm::Exception::Raise(exc);

        return result;
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
