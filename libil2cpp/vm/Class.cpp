#include "il2cpp-config.h"
#include "mono-structs.h"
#include <algorithm>
#include "gc/GCHandle.h"
#include "metadata/ArrayMetadata.h"
#include "metadata/GenericMetadata.h"
#include "metadata/GenericMethod.h"
#include "metadata/FieldLayout.h"
#include "metadata/Il2CppTypeCompare.h"
#include "os/Atomic.h"
#include "os/Mutex.h"
#include "utils/Memory.h"
#include "utils/StringUtils.h"
#include "vm/Assembly.h"
#include "vm/Class.h"
#include "vm/ClassInlines.h"
#include "vm/Exception.h"
#include "vm/Field.h"
#include "vm/GenericClass.h"
#include "vm/GenericContainer.h"
#include "vm/Method.h"
#include "vm/Image.h"
#include "vm/MetadataAlloc.h"
#include "vm/MetadataCache.h"
#include "vm/MetadataLock.h"
#include "vm/Method.h"
#include "vm/Property.h"
#include "vm/Runtime.h"
#include "vm/Reflection.h"
#include "vm/Thread.h"
#include "vm/Type.h"
#include "vm/Object.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "il2cpp-runtime-stats.h"
#include "il2cpp-tabledefs.h"
#include "gc/GarbageCollector.h"
#include "utils/Il2CppHashMap.h"
#include "utils/StringUtils.h"
#include "utils/HashUtils.h"
#include <string>
#include <memory.h>
#include <algorithm>
#include <limits>
#include <stdarg.h>

#include <set>
#include "hybridclr/metadata/MetadataUtil.h"
#include "hybridclr/interpreter/Engine.h"
#include "hybridclr/interpreter/Interpreter.h"
#include "hybridclr/interpreter/InterpreterModule.h"

namespace il2cpp
{
namespace vm
{
    const int Class::IgnoreNumberOfArguments = -1;

    static il2cpp::utils::dynamic_array<Il2CppClass*> s_staticFieldData;
    static int32_t s_FinalizerSlot = -1;
    static int32_t s_GetHashCodeSlot = -1;
    static Il2CppClass* s_EmptyClassList[] = {NULL};

    static void SetupGCDescriptor(Il2CppClass* klass, const il2cpp::os::FastAutoLock& lock);
    static void GetBitmapNoInit(Il2CppClass* klass, size_t* bitmap, size_t& maxSetBit, size_t parentOffset, const il2cpp::os::FastAutoLock* lockPtr);
    static Il2CppClass* ResolveGenericInstanceType(Il2CppClass*, const il2cpp::vm::TypeNameParseInfo&, TypeSearchFlags searchFlags);
    static void SetupVTable(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock);

    Il2CppClass* Class::FromIl2CppType(const Il2CppType* type, bool throwOnError)
    {
        Il2CppClass* defaultClass = FromIl2CppTypeEnum(type->type);
        if (defaultClass != NULL)
            return defaultClass;

        switch (type->type)
        {
            case IL2CPP_TYPE_ARRAY:
            {
                Il2CppClass* elementClass = FromIl2CppType(type->data.array->etype, throwOnError);
                return Class::GetBoundedArrayClass(elementClass, type->data.array->rank, true);
            }
            case IL2CPP_TYPE_PTR:
                return Class::GetPtrClass(type->data.type);
            case IL2CPP_TYPE_FNPTR:
                return il2cpp_defaults.int_class;
            case IL2CPP_TYPE_SZARRAY:
            {
                Il2CppClass* elementClass = FromIl2CppType(type->data.type, throwOnError);
                return Class::GetArrayClass(elementClass, 1);
            }
            case IL2CPP_TYPE_CLASS:
            case IL2CPP_TYPE_VALUETYPE:
                return Type::GetClass(type);
            case IL2CPP_TYPE_GENERICINST:
                return GenericClass::GetClass(type->data.generic_class, throwOnError);
            case IL2CPP_TYPE_VAR:
                return Class::FromGenericParameter(Type::GetGenericParameterHandle(type));
            case IL2CPP_TYPE_MVAR:
                return Class::FromGenericParameter(Type::GetGenericParameterHandle(type));
            default:
                IL2CPP_NOT_IMPLEMENTED(Class::FromIl2CppType);
        }

        return NULL;
    }

    Il2CppClass* Class::FromIl2CppTypeEnum(Il2CppTypeEnum type)
    {
#define RETURN_DEFAULT_TYPE(fieldName) do { IL2CPP_ASSERT(il2cpp_defaults.fieldName); return il2cpp_defaults.fieldName; } while (false)

        switch (type)
        {
            case IL2CPP_TYPE_OBJECT:
                RETURN_DEFAULT_TYPE(object_class);
            case IL2CPP_TYPE_VOID:
                RETURN_DEFAULT_TYPE(void_class);
            case IL2CPP_TYPE_BOOLEAN:
                RETURN_DEFAULT_TYPE(boolean_class);
            case IL2CPP_TYPE_CHAR:
                RETURN_DEFAULT_TYPE(char_class);
            case IL2CPP_TYPE_I1:
                RETURN_DEFAULT_TYPE(sbyte_class);
            case IL2CPP_TYPE_U1:
                RETURN_DEFAULT_TYPE(byte_class);
            case IL2CPP_TYPE_I2:
                RETURN_DEFAULT_TYPE(int16_class);
            case IL2CPP_TYPE_U2:
                RETURN_DEFAULT_TYPE(uint16_class);
            case IL2CPP_TYPE_I4:
                RETURN_DEFAULT_TYPE(int32_class);
            case IL2CPP_TYPE_U4:
                RETURN_DEFAULT_TYPE(uint32_class);
            case IL2CPP_TYPE_I:
                RETURN_DEFAULT_TYPE(int_class);
            case IL2CPP_TYPE_U:
                RETURN_DEFAULT_TYPE(uint_class);
            case IL2CPP_TYPE_I8:
                RETURN_DEFAULT_TYPE(int64_class);
            case IL2CPP_TYPE_U8:
                RETURN_DEFAULT_TYPE(uint64_class);
            case IL2CPP_TYPE_R4:
                RETURN_DEFAULT_TYPE(single_class);
            case IL2CPP_TYPE_R8:
                RETURN_DEFAULT_TYPE(double_class);
            case IL2CPP_TYPE_STRING:
                RETURN_DEFAULT_TYPE(string_class);
            case IL2CPP_TYPE_TYPEDBYREF:
                RETURN_DEFAULT_TYPE(typed_reference_class);

            case IL2CPP_TYPE_IL2CPP_TYPE_INDEX:
                RETURN_DEFAULT_TYPE(systemtype_class);
            default:
                break;
        }

        return NULL;

#undef RETURN_DEFAULT_TYPE
    }

    Il2CppClass* Class::FromSystemType(Il2CppReflectionType *type)
    {
        Il2CppClass *klass = Class::FromIl2CppType(type->type);
        Class::Init(klass);
        return klass;
    }

    static void SetupInterfacesLocked(Il2CppClass* klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->generic_class)
        {
            Il2CppClass* genericTypeDefinition = GenericClass::GetTypeDefinition(klass->generic_class);
            Il2CppGenericContext* context = &klass->generic_class->context;

            if (genericTypeDefinition->interfaces_count > 0 && klass->implementedInterfaces == NULL)
            {
                IL2CPP_ASSERT(genericTypeDefinition->interfaces_count == klass->interfaces_count);
                klass->implementedInterfaces = (Il2CppClass**)MetadataCalloc(genericTypeDefinition->interfaces_count, sizeof(Il2CppClass*));
                for (uint16_t i = 0; i < genericTypeDefinition->interfaces_count; i++)
                    klass->implementedInterfaces[i] = Class::FromIl2CppType(il2cpp::metadata::GenericMetadata::InflateIfNeeded(MetadataCache::GetInterfaceFromOffset(genericTypeDefinition, i), context, false));
            }
        }
        else if (klass->rank > 0)
        {
            if (klass->implementedInterfaces == NULL)
                il2cpp::metadata::ArrayMetadata::SetupArrayInterfaces(klass, lock);
        }
        else
        {
            if (klass->interfaces_count > 0 && klass->implementedInterfaces == NULL)
            {
                klass->implementedInterfaces = (Il2CppClass**)MetadataCalloc(klass->interfaces_count, sizeof(Il2CppClass*));
                for (uint16_t i = 0; i < klass->interfaces_count; i++)
                    klass->implementedInterfaces[i] = Class::FromIl2CppType(MetadataCache::GetInterfaceFromOffset(klass, i));
            }
        }

        if (klass->implementedInterfaces == NULL)
        {
            IL2CPP_ASSERT(klass->interfaces_count == 0);
            klass->implementedInterfaces = s_EmptyClassList;
        }
    }

    typedef Il2CppHashMap<Il2CppMetadataGenericParameterHandle, Il2CppClass*, utils::PassThroughHash<Il2CppMetadataGenericParameterHandle> > GenericParameterMap;
    static GenericParameterMap s_GenericParameterMap;

    Il2CppClass* Class::FromGenericParameter(Il2CppMetadataGenericParameterHandle param)
    {
        il2cpp::os::FastAutoLock lock(&g_MetadataLock);

        GenericParameterMap::const_iterator iter = s_GenericParameterMap.find(param);
        if (iter != s_GenericParameterMap.end())
            return iter->second;

        Il2CppClass* klass = (Il2CppClass*)MetadataCalloc(1, sizeof(Il2CppClass));
        klass->klass = klass;

        Il2CppGenericParameterInfo paramInfo = MetadataCache::GetGenericParameterInfo(param);

        IL2CPP_ASSERT(paramInfo.containerHandle != NULL);

        klass->name = paramInfo.name;
        klass->namespaze = "";

        klass->image = GenericContainer::GetDeclaringType(paramInfo.containerHandle)->image;

        klass->initialized = true;
        UpdateInitializedAndNoError(klass);

        klass->parent = il2cpp_defaults.object_class;
        klass->castClass = klass->element_class = klass;

        klass->flags = TYPE_ATTRIBUTE_PUBLIC;

        bool containerIsMethod = MetadataCache::GetGenericContainerIsMethod(paramInfo.containerHandle);

        MetadataCache::MakeGenericArgType(paramInfo.containerHandle, param, &klass->byval_arg);
        MetadataCache::MakeGenericArgType(paramInfo.containerHandle, param, &klass->this_arg);
        klass->this_arg.byref = true;

        klass->instance_size = sizeof(void*);
        klass->stack_slot_size = sizeof(void*);
        klass->thread_static_fields_size = -1;
        klass->native_size = -1;
        klass->size_inited = true;
        klass->typeHierarchyDepth = 1;

        s_GenericParameterMap.insert(std::make_pair(param, klass));

        return klass;
    }

    Il2CppClass* Class::GetElementClass(Il2CppClass *klass)
    {
        return klass->element_class;
    }

    const Il2CppType* Class::GetEnumBaseType(Il2CppClass *klass)
    {
        if (klass->element_class == klass)
            /* SRE or broken types */
            return NULL;
        else
            return &klass->element_class->byval_arg;
    }

    const EventInfo* Class::GetEvents(Il2CppClass *klass, void* *iter)
    {
        if (!iter)
            return NULL;

        if (!*iter)
        {
            Class::SetupEvents(klass);
            if (klass->event_count == 0)
                return NULL;

            *iter = const_cast<EventInfo*>(klass->events);
            return klass->events;
        }

        const EventInfo* eventInfo = (const EventInfo*)*iter;
        eventInfo++;
        if (eventInfo < klass->events + klass->event_count)
        {
            *iter = const_cast<EventInfo*>(eventInfo);
            return eventInfo;
        }

        return NULL;
    }

    FieldInfo* Class::GetFields(Il2CppClass *klass, void* *iter)
    {
        if (!iter)
            return NULL;

        if (!*iter)
        {
            Class::SetupFields(klass);
            if (klass->field_count == 0)
                return NULL;

            *iter = klass->fields;
            return klass->fields;
        }

        FieldInfo* fieldAddress = (FieldInfo*)*iter;
        fieldAddress++;
        if (fieldAddress < klass->fields + klass->field_count)
        {
            *iter = fieldAddress;
            return fieldAddress;
        }

        return NULL;
    }

    FieldInfo* Class::GetFieldFromName(Il2CppClass *klass, const char* name)
    {
        while (klass)
        {
            void* iter = NULL;
            FieldInfo* field;
            while ((field = GetFields(klass, &iter)))
            {
                if (strcmp(name, Field::GetName(field)) != 0)
                    continue;

                return field;
            }

            klass = klass->parent;
        }

        return NULL;
    }

    const MethodInfo* Class::GetFinalizer(Il2CppClass *klass)
    {
        if (!klass->initialized)
            Class::Init(klass);

        if (!klass->has_finalize)
            return NULL;

#if IL2CPP_TINY
        IL2CPP_ASSERT(0 && "System.Object does not have a finalizer in the Tiny mscorlib, so we don't have a finalizer slot.");
#endif
        return klass->vtable[s_FinalizerSlot].method;
    }

    int32_t Class::GetInstanceSize(const Il2CppClass *klass)
    {
        IL2CPP_ASSERT(klass->size_inited);
        return klass->instance_size;
    }

    Il2CppClass* Class::GetInterfaces(Il2CppClass *klass, void* *iter)
    {
        if (!iter)
            return NULL;

        if (!*iter)
        {
            Class::SetupInterfaces(klass);
            if (klass->interfaces_count == 0)
                return NULL;

            *iter = &klass->implementedInterfaces[0];
            return klass->implementedInterfaces[0];
        }

        Il2CppClass** interfaceAddress = (Il2CppClass**)*iter;
        interfaceAddress++;
        if (interfaceAddress < &klass->implementedInterfaces[klass->interfaces_count])
        {
            *iter = interfaceAddress;
            return *interfaceAddress;
        }

        return NULL;
    }

    const MethodInfo* Class::GetMethods(Il2CppClass *klass, void* *iter)
    {
        if (!iter)
            return NULL;

        if (!*iter)
        {
            Class::SetupMethods(klass);
            if (klass->method_count == 0)
                return NULL;

            *iter = &klass->methods[0];
            return klass->methods[0];
        }

        const MethodInfo** methodAddress = (const MethodInfo**)*iter;
        methodAddress++;
        if (methodAddress < &klass->methods[klass->method_count])
        {
            *iter = methodAddress;
            return *methodAddress;
        }

        return NULL;
    }

    const MethodInfo* Class::GetMethodFromName(Il2CppClass *klass, const char* name, int argsCount)
    {
        return GetMethodFromNameFlags(klass, name, argsCount, 0);
    }

    const MethodInfo* Class::GetMethodFromNameFlags(Il2CppClass *klass, const char* name, int argsCount, int32_t flags)
    {
        return GetMethodFromNameFlagsAndSig(klass, name, argsCount, flags, NULL);
    }

    const MethodInfo* Class::GetMethodFromNameFlagsAndSig(Il2CppClass *klass, const char* name, int argsCount, int32_t flags, const Il2CppType** argTypes)
    {
        Class::Init(klass);

        while (klass != NULL)
        {
            void* iter = NULL;
            while (const MethodInfo* method = Class::GetMethods(klass, &iter))
            {
                if (method->name[0] == name[0] &&
                    (argsCount == IgnoreNumberOfArguments || method->parameters_count == argsCount) &&
                    ((method->flags & flags) == flags) &&
                    !strcmp(name, method->name))
                {
                    bool allArgTypeMatch = true;
                    if (argTypes != NULL && argsCount != IgnoreNumberOfArguments)
                    {
                        for (int i = 0; allArgTypeMatch && i < argsCount; i++)
                        {
                            allArgTypeMatch = metadata::Il2CppTypeEqualityComparer::AreEqual(method->parameters[i], argTypes[i]);
                        }
                    }

                    if (allArgTypeMatch)
                        return method;
                }
            }

            klass = klass->parent;
        }

        return NULL;
    }

    const MethodInfo* Class::GetGenericInstanceMethodFromDefintion(Il2CppClass* genericInstanceClass, const MethodInfo* methodDefinition)
    {
        IL2CPP_ASSERT(Class::IsInflated(genericInstanceClass));
        IL2CPP_ASSERT(metadata::Il2CppTypeEqualityComparer::AreEqual(genericInstanceClass->generic_class->type, &methodDefinition->klass->byval_arg));

        ptrdiff_t index = methodDefinition - methodDefinition->klass->methods[0];

        IL2CPP_ASSERT(index >= 0 && index < methodDefinition->klass->method_count);
        IL2CPP_ASSERT(index < genericInstanceClass->method_count);

        const MethodInfo* genericClassMethod = genericInstanceClass->methods[index];

        IL2CPP_ASSERT(genericClassMethod->genericMethod->methodDefinition == methodDefinition);

        return genericClassMethod;
    }

    const char* Class::GetName(Il2CppClass *klass)
    {
        return klass->name;
    }

    const char* Class::GetNamespace(Il2CppClass *klass)
    {
        return klass->namespaze;
    }

    Il2CppClass* Class::GetNestedTypes(Il2CppClass *klass, void* *iter)
    {
        if (!iter)
            return NULL;

        if (klass->generic_class)
        {
            IL2CPP_ASSERT(0 && "Class::GetNestedTypes should only be called on non-generic types and generic type definitions");
            return NULL;
        }

        if (!*iter)
        {
            Class::SetupNestedTypes(klass);
            if (klass->nested_type_count == 0)
                return NULL;

            *iter = &klass->nestedTypes[0];
            return klass->nestedTypes[0];
        }

        Il2CppClass** nestedTypeAddress = (Il2CppClass**)*iter;
        nestedTypeAddress++;
        if (nestedTypeAddress < &klass->nestedTypes[klass->nested_type_count])
        {
            *iter = nestedTypeAddress;
            return *nestedTypeAddress;
        }

        return NULL;
    }

    size_t Class::GetNumMethods(const Il2CppClass* klass)
    {
        return klass->method_count;
    }

    size_t Class::GetNumProperties(const Il2CppClass* klass)
    {
        return klass->property_count;
    }

    size_t Class::GetNumFields(const Il2CppClass* klass)
    {
        return klass->field_count;
    }

    Il2CppClass* Class::GetParent(Il2CppClass *klass)
    {
        return klass->parent;
    }

    const PropertyInfo* Class::GetProperties(Il2CppClass *klass, void* *iter)
    {
        if (!iter)
            return NULL;

        if (!*iter)
        {
            Class::SetupProperties(klass);
            if (klass->property_count == 0)
                return NULL;

            *iter = const_cast<PropertyInfo*>(klass->properties);
            return klass->properties;
        }

        const PropertyInfo* property = (const PropertyInfo*)*iter;
        property++;
        if (property < klass->properties + klass->property_count)
        {
            *iter = const_cast<PropertyInfo*>(property);
            return property;
        }

        return NULL;
    }

    const PropertyInfo* Class::GetPropertyFromName(Il2CppClass *klass, const char* name)
    {
        while (klass)
        {
            void* iter = NULL;
            while (const PropertyInfo* prop = GetProperties(klass, &iter))
            {
                if (strcmp(name, Property::GetName(prop)) != 0)
                    continue;

                return prop;
            }

            klass = klass->parent;
        }

        return NULL;
    }

    int32_t Class::GetValueSize(Il2CppClass *klass, uint32_t *align)
    {
        int32_t size;

        if (!klass->size_init_pending)
            SetupFields(klass);

        IL2CPP_ASSERT(klass->byval_arg.valuetype);

        if (!klass->size_inited)
        {
            // If the size of a value type is not intialized, we cannot continue.
            // This might mean this is a recursively defined struct, where one value type
            // has a field of anotehr value type, which in turn has the first as a field.
            // The runtime should throw a type load exception in this case.
            std::string message;
            message += "Could not load type '";
            if (strlen(klass->namespaze) != 0)
            {
                message += klass->namespaze;
                message += ":";
            }
            message += klass->name;
            message += "'";
            Class::SetClassInitializationError(klass, il2cpp::vm::Exception::GetTypeLoadException(message.c_str()));

            size = 1;
        }
        else
        {
            size = Class::GetInstanceSize(klass) - sizeof(Il2CppObject);
        }

        if (align)
            *align = klass->minimumAlignment;

        return size;
    }

    bool Class::HasParent(Il2CppClass *klass, Il2CppClass *parent)
    {
        Class::SetupTypeHierarchy(klass);
        Class::SetupTypeHierarchy(parent);

        return ClassInlines::HasParentUnsafe(klass, parent);
    }

    bool Class::IsAssignableFrom(Il2CppClass *klass, Il2CppClass *oklass)
    {
        // Cast to original class - fast path
        if (klass == oklass)
            return true;

        Class::Init(klass);
        Class::Init(oklass);

        // Following checks are always going to fail for interfaces
        if (!IsInterface(klass))
        {
            // Array
            if (klass->rank)
            {
                if (oklass->rank != klass->rank)
                    return false;

                if (Class::IsValuetype(oklass->castClass))
                {
                    // Full array covariance is defined only for reference types.
                    // For value types, array element reduced types must match
                    return klass->castClass == oklass->castClass;
                }

                return Class::IsAssignableFrom(klass->castClass, oklass->castClass);
            }
            // System.Object
            else if (klass == il2cpp_defaults.object_class)
            {
                return true;
            }
            // Left is System.Nullable<>
            else if (Class::IsNullable(klass))
            {
                if (Class::IsNullable(oklass))
                    IL2CPP_NOT_IMPLEMENTED(Class::IsAssignableFrom);
                Il2CppClass* nullableArg = Class::GetNullableArgument(klass);
                return Class::IsAssignableFrom(nullableArg, oklass);
            }

            if (klass->parent == il2cpp_defaults.multicastdelegate_class && klass->generic_class != NULL)
            {
                if (IsGenericClassAssignableFrom(klass, oklass, oklass))
                    return true;
            }

            return ClassInlines::HasParentUnsafe(oklass, klass);
        }

        if (klass->generic_class != NULL)
        {
            // checking for simple reference equality is not enough in this case because generic interface might have covariant and/or contravariant parameters
            for (Il2CppClass* iter = oklass; iter != NULL; iter = iter->parent)
            {
                if (IsGenericClassAssignableFrom(klass, iter, oklass))
                    return true;

                for (uint16_t i = 0; i < iter->interfaces_count; ++i)
                {
                    if (IsGenericClassAssignableFrom(klass, iter->implementedInterfaces[i], oklass))
                        return true;
                }

                for (uint16_t i = 0; i < iter->interface_offsets_count; ++i)
                {
                    if (IsGenericClassAssignableFrom(klass, iter->interfaceOffsets[i].interfaceType, oklass))
                        return true;
                }
            }
        }
        else
        {
            for (Il2CppClass* iter = oklass; iter != NULL; iter = iter->parent)
            {
                for (uint16_t i = 0; i < iter->interfaces_count; ++i)
                {
                    if (iter->implementedInterfaces[i] == klass)
                        return true;
                }

                // Check the interfaces we may have grafted on to the type (e.g IList,
                // ICollection, IEnumerable for array types).
                for (uint16_t i = 0; i < iter->interface_offsets_count; ++i)
                {
                    if (iter->interfaceOffsets[i].interfaceType == klass)
                        return true;
                }
            }
        }

        return false;
    }

    bool Class::IsAssignableFrom(Il2CppReflectionType * type, Il2CppReflectionType * c)
    {
        Il2CppClass *klass;
        Il2CppClass *klassc;

        klass = FromIl2CppType(type->type);
        klassc = FromIl2CppType(c->type);

        if (type->type->byref && !c->type->byref)
            return false;

        return IsAssignableFrom(klass, klassc);
    }

    bool Class::IsGeneric(const Il2CppClass *klass)
    {
        return klass->is_generic;
    }

    bool Class::IsInflated(const Il2CppClass *klass)
    {
        return klass->generic_class != NULL;
    }

    bool Class::IsGenericTypeDefinition(const Il2CppClass* klass)
    {
        return IsGeneric(klass) && !IsInflated(klass);
    }

    bool Class::IsSubclassOf(Il2CppClass *klass, Il2CppClass *klassc, bool check_interfaces)
    {
        Class::SetupTypeHierarchy(klass);
        Class::SetupTypeHierarchy(klassc);
        Class::SetupInterfaces(klass);

        if (check_interfaces && IsInterface(klassc) && !IsInterface(klass))
        {
            Il2CppClass *oklass = klass;

            while (oklass)
            {
                Class::SetupInterfaces(oklass);
                // TODO: we probably need to implement a faster check here
                for (uint16_t i = 0; i < oklass->interfaces_count; i++)
                {
                    if (oklass->implementedInterfaces[i] == klassc)
                        return true;
                }

                oklass = oklass->parent;
            }
        }
        else if (check_interfaces && IsInterface(klassc) && IsInterface(klass))
        {
            // TODO: we probably need to implement a faster check here
            for (uint16_t i = 0; i < klass->interfaces_count; i++)
            {
                if (klass->implementedInterfaces[i] == klassc)
                    return true;
            }
        }
        else
        {
            if (!IsInterface(klass) && ClassInlines::HasParentUnsafe(klass, klassc))
                return true;
        }

        /*
         * MS.NET thinks interfaces are a subclass of Object, so we think it as
         * well.
         */
        if (klassc == il2cpp_defaults.object_class)
            return true;

        return false;
    }

    enum FieldLayoutKind
    {
        FIELD_LAYOUT_INSTANCE,
        FIELD_LAYOUT_STATIC,
        FIELD_LAYOUT_THREADSTATIC,
    };

    static void SetupFieldOffsetsLocked(FieldLayoutKind fieldLayoutKind, Il2CppClass* klass, size_t size, const std::vector<size_t>& fieldOffsets, const il2cpp::os::FastAutoLock& lock)
    {
        IL2CPP_ASSERT(size < std::numeric_limits<uint32_t>::max());
        if (fieldLayoutKind == FIELD_LAYOUT_INSTANCE)
            klass->instance_size = static_cast<uint32_t>(size);
        if (fieldLayoutKind == FIELD_LAYOUT_STATIC)
            klass->static_fields_size = static_cast<uint32_t>(size);
        if (fieldLayoutKind == FIELD_LAYOUT_THREADSTATIC)
            klass->thread_static_fields_size = static_cast<uint32_t>(size);

        if (!(klass->flags & TYPE_ATTRIBUTE_EXPLICIT_LAYOUT))
        {
            size_t fieldIndex = 0;
            for (uint16_t i = 0; i < klass->field_count; i++)
            {
                FieldInfo* field = klass->fields + i;
                if (fieldLayoutKind == FIELD_LAYOUT_INSTANCE && field->type->attrs & FIELD_ATTRIBUTE_STATIC)
                    continue;
                if (fieldLayoutKind == FIELD_LAYOUT_STATIC && !Field::IsNormalStatic(field))
                    continue;
                if (fieldLayoutKind == FIELD_LAYOUT_THREADSTATIC && !Field::IsThreadStatic(field))
                    continue;

                if (fieldLayoutKind == FIELD_LAYOUT_THREADSTATIC)
                {
                    field->offset = THREAD_STATIC_FIELD_OFFSET;
                    MetadataCache::AddThreadLocalStaticOffsetForFieldLocked(field, static_cast<int32_t>(fieldOffsets[fieldIndex]), lock);
                    fieldIndex++;
                    continue;
                }

                field->offset = static_cast<int32_t>(fieldOffsets[fieldIndex]);
                fieldIndex++;
            }
        }
    }

    static void ValidateFieldOffsets(FieldLayoutKind fieldLayoutKind, Il2CppClass* klass, size_t size, const std::vector<size_t>& fieldOffsets)
    {
        if (fieldLayoutKind == FIELD_LAYOUT_INSTANCE && klass->parent && !(klass->flags & TYPE_ATTRIBUTE_EXPLICIT_LAYOUT))
            IL2CPP_ASSERT(klass->instance_size == size);
        if (fieldLayoutKind == FIELD_LAYOUT_STATIC)
            IL2CPP_ASSERT(klass->static_fields_size == size);
        if (fieldLayoutKind == FIELD_LAYOUT_THREADSTATIC)
            IL2CPP_ASSERT(klass->thread_static_fields_size == size);

        if (!(klass->flags & TYPE_ATTRIBUTE_EXPLICIT_LAYOUT))
        {
            size_t fieldIndex = 0;
            for (uint16_t i = 0; i < klass->field_count; i++)
            {
                FieldInfo* field = klass->fields + i;
                if (fieldLayoutKind == FIELD_LAYOUT_INSTANCE && field->type->attrs & FIELD_ATTRIBUTE_STATIC)
                    continue;
                if (fieldLayoutKind == FIELD_LAYOUT_STATIC && !Field::IsNormalStatic(field))
                    continue;
                if (fieldLayoutKind == FIELD_LAYOUT_THREADSTATIC && !Field::IsThreadStatic(field))
                    continue;

                if (fieldLayoutKind == FIELD_LAYOUT_THREADSTATIC)
                {
                    IL2CPP_ASSERT(fieldOffsets[fieldIndex] == -1);
                    fieldIndex++;
                    continue;
                }

                IL2CPP_ASSERT(field->offset == fieldOffsets[fieldIndex]);
                fieldIndex++;
            }
        }
    }

    static size_t UpdateInstanceSizeForGenericClass(Il2CppClass* klass, size_t instanceSize)
    {
        // need to set this in case there are no fields in a generic instance type
        if (klass->generic_class)
        {
            const Il2CppClass* genericTypeDef = il2cpp::vm::MetadataCache::GetTypeInfoFromType(klass->generic_class->type);
            // If the generic class has an instance size, it was explictly set
            if (genericTypeDef->instance_size > 0 && genericTypeDef->instance_size > instanceSize)
                instanceSize = genericTypeDef->instance_size;

            klass->instance_size = static_cast<uint32_t>(instanceSize);
        }

        return instanceSize;
    }

    static void LayoutFieldsLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (Class::IsGeneric(klass))
            return;

        size_t instanceSize = 0;
        size_t actualSize = 0;
        if (klass->parent)
        {
            IL2CPP_ASSERT(klass->parent->size_inited);
            klass->has_references |= klass->parent->has_references;
            instanceSize = klass->parent->instance_size;
            actualSize = klass->parent->actualSize;
            if (klass->byval_arg.valuetype)
                klass->minimumAlignment = 1;
            else
                klass->minimumAlignment = klass->parent->minimumAlignment;
        }
        else
        {
            actualSize = instanceSize = sizeof(Il2CppObject);
            klass->minimumAlignment = sizeof(Il2CppObject*);
        }

        if (klass->field_count)
        {
            for (uint16_t i = 0; i < klass->field_count; i++)
            {
                FieldInfo* field = klass->fields + i;
                if (!Field::IsInstance(field))
                    continue;

                const Il2CppType* ftype = Type::GetUnderlyingType(field->type);
                if (Type::IsReference(ftype) || (Type::IsStruct(ftype) && Class::HasReferences(Class::FromIl2CppType(ftype))))
                    klass->has_references = true;
            }

            il2cpp::metadata::FieldLayout::FieldLayoutData layoutData;
            il2cpp::metadata::FieldLayout::FieldLayoutData staticLayoutData;
            il2cpp::metadata::FieldLayout::FieldLayoutData threadStaticLayoutData;

            // If a type has references, ignore any packing
            // All reference types must be aligned on a pointer sized boundary
            // And if it has references, it not blittable, and we can layout the type anyway we want
            uint8_t packingSize = klass->packingSize;
            if (klass->has_references)
                packingSize = 0;

            il2cpp::metadata::FieldLayout::LayoutInstanceFields(klass, instanceSize, actualSize, klass->minimumAlignment, packingSize, layoutData);

            instanceSize = layoutData.classSize;

            // This is a value type with no instance fields, but at least one static field.
            if (klass->byval_arg.valuetype && layoutData.FieldOffsets.size() == 0)
            {
                instanceSize = IL2CPP_SIZEOF_STRUCT_WITH_NO_INSTANCE_FIELDS + sizeof(Il2CppObject);
                klass->actualSize = IL2CPP_SIZEOF_STRUCT_WITH_NO_INSTANCE_FIELDS + sizeof(Il2CppObject);
            }

            instanceSize = UpdateInstanceSizeForGenericClass(klass, instanceSize);

            klass->size_inited = true;

            il2cpp::metadata::FieldLayout::LayoutStaticFields(klass, staticLayoutData);
            il2cpp::metadata::FieldLayout::LayoutThreadStaticFields(klass, threadStaticLayoutData);

            klass->minimumAlignment = layoutData.minimumAlignment;
            if (klass->generic_class != NULL || MetadataCache::StructLayoutSizeIsDefault(klass->typeMetadataHandle))
                klass->actualSize = static_cast<uint32_t>(layoutData.actualClassSize);
            else
                klass->actualSize = klass->instance_size;

            if (klass->image == il2cpp_defaults.corlib && !strcmp("Ephemeron", klass->name))
            {
                klass->has_references = false;
            }

            size_t staticSize = staticLayoutData.classSize;
            size_t threadStaticSize = threadStaticLayoutData.classSize;

            if (klass->generic_class)
            {
                SetupFieldOffsetsLocked(FIELD_LAYOUT_INSTANCE, klass, instanceSize, layoutData.FieldOffsets, lock);
                SetupFieldOffsetsLocked(FIELD_LAYOUT_STATIC, klass, staticSize, staticLayoutData.FieldOffsets, lock);
                SetupFieldOffsetsLocked(FIELD_LAYOUT_THREADSTATIC, klass, threadStaticSize, threadStaticLayoutData.FieldOffsets, lock);
            }
            else
            {
#if IL2CPP_ENABLE_VALIDATE_FIELD_LAYOUT
                ValidateFieldOffsets(FIELD_LAYOUT_INSTANCE, klass, instanceSize, layoutData.FieldOffsets);
                ValidateFieldOffsets(FIELD_LAYOUT_STATIC, klass, staticSize, staticLayoutData.FieldOffsets);
                ValidateFieldOffsets(FIELD_LAYOUT_THREADSTATIC, klass, threadStaticSize, threadStaticLayoutData.FieldOffsets);
#endif
            }
        }
        else
        {
            // need to set this in case there are no fields in a generic instance type
            instanceSize = UpdateInstanceSizeForGenericClass(klass, instanceSize);

            // Always set the actual size, as a derived class without fields could end up
            // with the wrong actual size (i.e. sizeof may be incorrect), if the last
            // field of the base class doesn't go to an alignment boundary and the compiler ABI
            // uses that extra space (as clang does).
            klass->actualSize = static_cast<uint32_t>(actualSize);
        }

        if (klass->static_fields_size)
        {
            klass->static_fields = il2cpp::gc::GarbageCollector::AllocateFixed(klass->static_fields_size, NULL);
            s_staticFieldData.push_back(klass);

            il2cpp_runtime_stats.class_static_data_size += klass->static_fields_size;
        }
        if (klass->thread_static_fields_size)
            klass->thread_static_fields_offset = il2cpp::vm::Thread::AllocThreadStaticData(klass->thread_static_fields_size);

        if (Class::IsValuetype(klass))
            klass->stack_slot_size = klass->instance_size - sizeof(Il2CppObject);
        else
            klass->stack_slot_size = sizeof(void*);
    }

    static void SetupFieldsFromDefinitionLocked(Il2CppClass* klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->field_count == 0)
        {
            klass->fields = NULL;
            return;
        }

        FieldInfo* fields = (FieldInfo*)MetadataCalloc(klass->field_count, sizeof(FieldInfo));
        FieldInfo* newField = fields;

        FieldIndex end = klass->field_count;
        for (FieldIndex fieldIndex = 0; fieldIndex < end; ++fieldIndex)
        {
            Il2CppMetadataFieldInfo fieldInfo = MetadataCache::GetFieldInfo(klass, fieldIndex);

            newField->type = fieldInfo.type;
            newField->name = fieldInfo.name;
            newField->parent = klass;
            newField->offset = MetadataCache::GetFieldOffsetFromIndexLocked(klass, fieldIndex, newField, lock);
            newField->token = fieldInfo.token;

            newField++;
        }

        klass->fields = fields;
    }

// passing lock to ensure we have acquired it. We can add asserts later
    void SetupFieldsLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->size_inited)
            return;

        klass->size_init_pending = true;

        if (klass->parent && !klass->parent->size_inited)
            SetupFieldsLocked(klass->parent, lock);

        if (klass->generic_class)
        {
            // for generic instance types, they just inflate the fields of their generic type definition
            // initialize the generic type's fields and delegate to the generic logic
            SetupFieldsLocked(GenericClass::GetTypeDefinition(klass->generic_class), lock);
            GenericClass::SetupFields(klass);
        }
        else
        {
            SetupFieldsFromDefinitionLocked(klass, lock);
        }

        if (!Class::IsGeneric(klass))
            LayoutFieldsLocked(klass, lock);

        klass->size_init_pending = false;

        klass->size_inited = true;
    }

    void Class::SetupFields(Il2CppClass *klass)
    {
        if (!klass->size_inited)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            SetupFieldsLocked(klass, lock);
        }
    }

// passing lock to ensure we have acquired it. We can add asserts later
    void SetupMethodsLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if ((!klass->method_count && !klass->rank) || klass->methods)
            return;

        if (klass->generic_class)
        {
            Class::InitLocked(GenericClass::GetTypeDefinition(klass->generic_class), lock);
            GenericClass::SetupMethods(klass);
        }
        else if (klass->rank)
        {
            Class::InitLocked(klass->element_class, lock);
            SetupVTable(klass, lock);
        }
        else
        {
            if (klass->method_count == 0)
            {
                klass->methods = NULL;
                return;
            }

            klass->methods = (const MethodInfo**)MetadataCalloc(klass->method_count, sizeof(MethodInfo*));
            MethodInfo* methods = (MethodInfo*)MetadataCalloc(klass->method_count, sizeof(MethodInfo));
            MethodInfo* newMethod = methods;

            MethodIndex end = klass->method_count;

            for (MethodIndex index = 0; index < end; ++index)
            {
                Il2CppMetadataMethodInfo methodInfo = MetadataCache::GetMethodInfo(klass, index);

                newMethod->name = methodInfo.name;

                newMethod->methodPointer = MetadataCache::GetMethodPointer(klass->image, methodInfo.token);

                if (klass->byval_arg.valuetype)
                {
                    Il2CppMethodPointer adjustorThunk = MetadataCache::GetAdjustorThunk(klass->image, methodInfo.token);
                    if (adjustorThunk != NULL)
                        newMethod->virtualMethodPointer = adjustorThunk;
                }
                // We did not find an adjustor thunk, or maybe did not need to look for one. Let's get the real method pointer.
                if (newMethod->virtualMethodPointer == NULL)
                    newMethod->virtualMethodPointer = newMethod->methodPointer;

                newMethod->methodPointerCallByInterp = newMethod->methodPointer;
                newMethod->virtualMethodPointerCallByInterp = newMethod->virtualMethodPointer;
                newMethod->initInterpCallMethodPointer = true;
                newMethod->klass = klass;
                newMethod->return_type = methodInfo.return_type;

                newMethod->parameters_count = (uint8_t)methodInfo.parameterCount;

                const Il2CppType** parameters = (const Il2CppType**)MetadataCalloc(methodInfo.parameterCount, sizeof(Il2CppType*));
                for (uint16_t paramIndex = 0; paramIndex < methodInfo.parameterCount; ++paramIndex)
                {
                    Il2CppMetadataParameterInfo paramInfo = MetadataCache::GetParameterInfo(klass, methodInfo.handle, paramIndex);
                    parameters[paramIndex] = paramInfo.type;
                }
                newMethod->parameters = parameters;

                newMethod->flags = methodInfo.flags;
                newMethod->iflags = methodInfo.iflags;
                newMethod->slot = methodInfo.slot;
                newMethod->is_inflated = false;
                newMethod->token = methodInfo.token;
                newMethod->methodMetadataHandle = methodInfo.handle;
                newMethod->genericContainerHandle = MetadataCache::GetGenericContainerFromMethod(methodInfo.handle);
                if (newMethod->genericContainerHandle)
                    newMethod->is_generic = true;
                newMethod->has_full_generic_sharing_signature = false;

                if (newMethod->virtualMethodPointer)
                {
                    newMethod->invoker_method = MetadataCache::GetMethodInvoker(klass->image, methodInfo.token);
                }
                else
                {
                    newMethod->invoker_method = Runtime::GetMissingMethodInvoker();
                    il2cpp::vm::Il2CppUnresolvedCallStubs stubs = MetadataCache::GetUnresovledCallStubs(newMethod);
                    newMethod->methodPointer = stubs.methodPointer;
                    newMethod->virtualMethodPointer = stubs.virtualMethodPointer;
                }

                newMethod->isInterpterImpl = hybridclr::interpreter::InterpreterModule::IsImplementsByInterpreter(newMethod);

                klass->methods[index] = newMethod;

                newMethod++;
            }
        }
    }

    void Class::SetupMethods(Il2CppClass *klass)
    {
        if (klass->method_count || klass->rank)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            SetupMethodsLocked(klass, lock);
        }
    }

    void SetupNestedTypesLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->generic_class || klass->nestedTypes)
            return;

        if (klass->nested_type_count > 0)
        {
            klass->nestedTypes = (Il2CppClass**)MetadataCalloc(klass->nested_type_count, sizeof(Il2CppClass*));
            for (uint16_t i = 0; i < klass->nested_type_count; i++)
                klass->nestedTypes[i] = MetadataCache::GetNestedTypeFromOffset(klass, i);
        }
    }

    void Class::SetupNestedTypes(Il2CppClass *klass)
    {
        if (klass->generic_class || klass->nestedTypes)
            return;

        if (klass->nested_type_count)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            SetupNestedTypesLocked(klass, lock);
        }
    }

    static void SetupVTable(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->is_vtable_initialized)
            return;

        if (klass->generic_class)
        {
            Il2CppClass* genericTypeDefinition = GenericClass::GetTypeDefinition(klass->generic_class);
            Il2CppGenericContext* context = &klass->generic_class->context;
            if (genericTypeDefinition->interface_offsets_count > 0 && klass->interfaceOffsets == NULL)
            {
                klass->interface_offsets_count = genericTypeDefinition->interface_offsets_count;
                klass->interfaceOffsets = (Il2CppRuntimeInterfaceOffsetPair*)MetadataCalloc(genericTypeDefinition->interface_offsets_count, sizeof(Il2CppRuntimeInterfaceOffsetPair));
                for (uint16_t i = 0; i < genericTypeDefinition->interface_offsets_count; i++)
                {
                    Il2CppInterfaceOffsetInfo interfaceOffset = MetadataCache::GetInterfaceOffsetInfo(genericTypeDefinition, i);
                    klass->interfaceOffsets[i].offset = interfaceOffset.offset;
                    klass->interfaceOffsets[i].interfaceType = Class::FromIl2CppType(il2cpp::metadata::GenericMetadata::InflateIfNeeded(interfaceOffset.interfaceType, context, false));
                }
            }

            if (genericTypeDefinition->vtable_count > 0)
            {
                klass->vtable_count = genericTypeDefinition->vtable_count;
                for (uint16_t i = 0; i < genericTypeDefinition->vtable_count; i++)
                {
                    const MethodInfo* method = MetadataCache::GetMethodInfoFromVTableSlot(genericTypeDefinition, i);

                    if (method && method->klass)
                    {
                        if (method && method->is_inflated)
                        {
                            const Il2CppGenericMethod* genericMethod = il2cpp::metadata::GenericMetadata::Inflate(method->genericMethod, context);
                            method = il2cpp::metadata::GenericMethod::GetMethod(genericMethod);
                        }
                        if (method && method->klass && Class::IsGeneric(method->klass))
                        {
                            method = il2cpp::metadata::GenericMethod::GetMethod(method, context->class_inst, NULL);
                        }
                    }

                    klass->vtable[i].method = method;
                    if (method != NULL)
                    {
                        // For default interface methods on generic interfaces we need to ensure that their rgctx's are initalized
                        if (method->klass != NULL && method->klass != klass && Method::IsDefaultInterfaceMethodOnGenericInstance(method))
                            Class::InitLocked(method->klass, lock);

                        if (method->virtualMethodPointer)
                            klass->vtable[i].methodPtr = method->virtualMethodPointer;
                        else if (method->is_inflated && !method->is_generic && !method->genericMethod->context.method_inst)
                            klass->vtable[i].methodPtr = MetadataCache::GetUnresovledCallStubs(method).virtualMethodPointer;
                        else
                            klass->vtable[i].methodPtr = il2cpp::vm::Method::GetEntryPointNotFoundMethodInfo()->methodPointer;
                    }
                    else
                    {
                        klass->vtable[i].method = il2cpp::vm::Method::GetEntryPointNotFoundMethodInfo();
                        klass->vtable[i].methodPtr = il2cpp::vm::Method::GetEntryPointNotFoundMethodInfo()->methodPointer;
                    }
                }
            }
        }
        else if (klass->rank)
        {
            Class::InitLocked(klass->element_class, lock);
            il2cpp::metadata::ArrayMetadata::SetupArrayVTable(klass, lock);
        }
        else
        {
            if (klass->interface_offsets_count > 0 && klass->interfaceOffsets == NULL)
            {
                klass->interfaceOffsets = (Il2CppRuntimeInterfaceOffsetPair*)MetadataCalloc(klass->interface_offsets_count, sizeof(Il2CppRuntimeInterfaceOffsetPair));
                for (uint16_t i = 0; i < klass->interface_offsets_count; i++)
                {
                    Il2CppInterfaceOffsetInfo interfaceOffset = MetadataCache::GetInterfaceOffsetInfo(klass, i);
                    klass->interfaceOffsets[i].offset = interfaceOffset.offset;
                    klass->interfaceOffsets[i].interfaceType = Class::FromIl2CppType(interfaceOffset.interfaceType);
                }
            }

            if (klass->vtable_count > 0)
            {
                for (uint16_t i = 0; i < klass->vtable_count; i++)
                {
                    const MethodInfo* method = MetadataCache::GetMethodInfoFromVTableSlot(klass, i);
                    klass->vtable[i].method = method;

                    if (method != NULL)
                    {
                        if (method->virtualMethodPointer)
                            klass->vtable[i].methodPtr = method->virtualMethodPointer;
                        else
                            klass->vtable[i].methodPtr = il2cpp::vm::Method::GetEntryPointNotFoundMethodInfo()->methodPointer;
                    }
                    else
                    {
                        klass->vtable[i].method = il2cpp::vm::Method::GetEntryPointNotFoundMethodInfo();
                        klass->vtable[i].methodPtr = il2cpp::vm::Method::GetEntryPointNotFoundMethodInfo()->methodPointer;
                    }
                }
            }
        }

        klass->is_vtable_initialized = 1;
    }

    static void SetupEventsLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->generic_class)
        {
            Class::InitLocked(GenericClass::GetTypeDefinition(klass->generic_class), lock);
            GenericClass::SetupEvents(klass);
        }
        else if (klass->rank > 0)
        {
            // do nothing, arrays have no events
            IL2CPP_ASSERT(klass->event_count == 0);
        }
        else if (klass->event_count != 0)
        {
            // we need methods initialized since we reference them via index below
            SetupMethodsLocked(klass, lock);

            EventInfo* events = (EventInfo*)MetadataCalloc(klass->event_count, sizeof(EventInfo));
            EventInfo* newEvent = events;

            EventIndex end = klass->event_count;

            for (EventIndex eventIndex = 0; eventIndex < end; ++eventIndex)
            {
                Il2CppMetadataEventInfo eventInfo = MetadataCache::GetEventInfo(klass, eventIndex);

                newEvent->eventType = eventInfo.type;
                newEvent->name = eventInfo.name;
                newEvent->parent = klass;
                newEvent->add = eventInfo.add;
                newEvent->remove = eventInfo.remove;
                newEvent->raise = eventInfo.raise;
                newEvent->token = eventInfo.token;

                newEvent++;
            }

            klass->events = events;
        }
    }

    void Class::SetupEvents(Il2CppClass *klass)
    {
        if (!klass->events && klass->event_count)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            SetupEventsLocked(klass, lock);
        }
    }

    static void SetupPropertiesLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->generic_class)
        {
            Class::InitLocked(GenericClass::GetTypeDefinition(klass->generic_class), lock);
            GenericClass::SetupProperties(klass);
        }
        else if (klass->property_count != 0)
        {
            // we need methods initialized since we reference them via index below
            SetupMethodsLocked(klass, lock);

            PropertyInfo* properties = (PropertyInfo*)MetadataCalloc(klass->property_count, sizeof(PropertyInfo));
            PropertyInfo* newProperty = properties;

            PropertyIndex end = klass->property_count;

            for (PropertyIndex propertyIndex = 0; propertyIndex < end; ++propertyIndex)
            {
                Il2CppMetadataPropertyInfo propertyInfo = MetadataCache::GetPropertyInfo(klass, propertyIndex);

                newProperty->name = propertyInfo.name;
                newProperty->parent = klass;
                newProperty->get = propertyInfo.get;
                newProperty->set = propertyInfo.set;
                newProperty->attrs = propertyInfo.attrs;
                newProperty->token = propertyInfo.token;

                newProperty++;
            }

            klass->properties = properties;
        }
    }

    void Class::SetupProperties(Il2CppClass *klass)
    {
        if (!klass->properties && klass->property_count)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            SetupPropertiesLocked(klass, lock);
        }
    }

    static void SetupTypeHierarchyLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->typeHierarchy != NULL)
            return;

        if (klass->parent && !klass->parent->typeHierarchy)
            SetupTypeHierarchyLocked(klass->parent, lock);
        if (klass->parent)
            klass->typeHierarchyDepth = klass->parent->typeHierarchyDepth + 1;
        else
            klass->typeHierarchyDepth = 1;

        klass->typeHierarchy = (Il2CppClass**)MetadataCalloc(klass->typeHierarchyDepth, sizeof(Il2CppClass*));

        if (klass->parent)
        {
            klass->typeHierarchy[klass->typeHierarchyDepth - 1] = klass;
            memcpy(klass->typeHierarchy, klass->parent->typeHierarchy, klass->parent->typeHierarchyDepth * sizeof(void*));
        }
        else
        {
            klass->typeHierarchy[0] = klass;
        }
    }

    void Class::SetupTypeHierarchy(Il2CppClass *klass)
    {
        if (klass->typeHierarchy == NULL)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            SetupTypeHierarchyLocked(klass, lock);
        }
    }

    void Class::SetupInterfaces(Il2CppClass *klass)
    {
        if (klass->implementedInterfaces == NULL)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            SetupInterfacesLocked(klass, lock);
        }
    }

    static void SetupBlittableForGenericInstanceType(Il2CppClass *klass)
    {
        for (int i = 0; i < klass->field_count; i++)
            if (Field::IsInstance(&klass->fields[i]) && !Class::FromIl2CppType(klass->fields[i].type)->is_blittable)
                return;

        klass->is_blittable = true;
    }

    bool Class::InitLocked(Il2CppClass *klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->initialized)
            return true;
        if (klass->init_pending)
            return true;
        if (klass->initializationExceptionGCHandle)
            return false;

        if (klass->generic_class && (klass->flags & TYPE_ATTRIBUTE_EXPLICIT_LAYOUT))
        {
            std::string message;
            message += "Could not load type '";
            message += klass->namespaze;
            message += ":";
            message += klass->name;
            message += "' because generic types cannot have explicit layout.";
            Class::SetClassInitializationError(klass, il2cpp::vm::Exception::GetTypeLoadException(message.c_str()));
            return false;
        }

        IL2CPP_NOT_IMPLEMENTED_NO_ASSERT(Class::Init, "Audit and compare to mono version");

        klass->init_pending = true;

        klass->genericRecursionDepth++;

        if (klass->generic_class)
        {
            Il2CppClass* genericTypeDefinition = GenericClass::GetTypeDefinition(klass->generic_class);
            InitLocked(genericTypeDefinition, lock);
            klass->is_blittable = genericTypeDefinition->is_blittable;
        }

        if (klass->byval_arg.type == IL2CPP_TYPE_ARRAY || klass->byval_arg.type == IL2CPP_TYPE_SZARRAY)
        {
            Il2CppClass *element_class = klass->element_class;
            if (!element_class->initialized)
                InitLocked(element_class, lock);
        }

        SetupInterfacesLocked(klass, lock);

        if (klass->parent && !klass->parent->initialized)
            InitLocked(klass->parent, lock);

        SetupMethodsLocked(klass, lock);
        SetupTypeHierarchyLocked(klass, lock);
        SetupVTable(klass, lock);
        if (!klass->size_inited)
            SetupFieldsLocked(klass, lock);

        // If this is generic instance class and it's generic type definition is not blittable,
        // check each field to see if all fields are blittable, in which case the generic instance is blittable
        if (!klass->is_blittable && klass->generic_class)
            SetupBlittableForGenericInstanceType(klass);

        if (klass->initializationExceptionGCHandle)
        {
            klass->init_pending = false;
            return false;
        }

        SetupEventsLocked(klass, lock);
        SetupPropertiesLocked(klass, lock);
        SetupNestedTypesLocked(klass, lock);

        if (klass == il2cpp_defaults.object_class)
        {
            for (uint16_t slot = 0; slot < klass->vtable_count; slot++)
            {
                const MethodInfo* vmethod = klass->vtable[slot].method;
                if (!strcmp(vmethod->name, "GetHashCode"))
                    s_GetHashCodeSlot = slot;
                else if (!strcmp(vmethod->name, "Finalize"))
                    s_FinalizerSlot = slot;
            }
#if !IL2CPP_TINY
            IL2CPP_ASSERT(s_FinalizerSlot > 0);
            IL2CPP_ASSERT(s_GetHashCodeSlot > 0);
#endif
        }

        bool canBeInstantiated = !Class::IsGeneric(klass) && !il2cpp::metadata::GenericMetadata::ContainsGenericParameters(klass);

        if (canBeInstantiated)
        {
            SetupGCDescriptor(klass, lock);

            if (klass->generic_class)
            {
                // This should be kept last.  InflateRGCTXLocked may need initialized data from the class we are initializing
                if (klass->genericRecursionDepth < il2cpp::metadata::GenericMetadata::GetMaximumRuntimeGenericDepth() || il2cpp::vm::Runtime::IsLazyRGCTXInflationEnabled())
                    klass->rgctx_data = il2cpp::metadata::GenericMetadata::InflateRGCTXLocked(klass->image, klass->token, &klass->generic_class->context, lock);
            }
        }

        klass->initialized = true;
        Class::UpdateInitializedAndNoError(klass);
        klass->init_pending = false;

        ++il2cpp_runtime_stats.initialized_class_count;

        return true;
    }

    bool Class::InitSizeAndFieldLayoutLocked(Il2CppClass* klass, const il2cpp::os::FastAutoLock& lock)
    {
        if (klass->size_inited)
            return true;
        if (klass->size_init_pending)
            return true;
        if (klass->initializationExceptionGCHandle)
            return false;

        if (!Class::IsGeneric(klass))
            SetupFieldsLocked(klass, lock);

        return true;
    }

    void Class::Init(Il2CppClass *klass)
    {
        IL2CPP_ASSERT(klass);

        if (!klass->initialized)
        {
            il2cpp::os::FastAutoLock lock(&g_MetadataLock);
            IL2CPP_ASSERT(!klass->init_pending);
            InitLocked(klass, lock);
        }
    }

    void Class::SetClassInitializationError(Il2CppClass *klass, Il2CppException* error)
    {
        klass->initializationExceptionGCHandle = gc::GCHandle::New(error, false);
        UpdateInitializedAndNoError(klass);
    }

    void Class::UpdateInitializedAndNoError(Il2CppClass *klass)
    {
        klass->initialized_and_no_error = klass->initialized && !klass->initializationExceptionGCHandle;
    }

    Il2CppClass* Class::FromName(const Il2CppImage* image, const char* namespaze, const char *name)
    {
        return Image::ClassFromName(image, namespaze, name);
    }

    Il2CppClass* Class::GetArrayClass(Il2CppClass *element_class, uint32_t rank)
    {
        return GetBoundedArrayClass(element_class, rank, false);
    }

    Il2CppClass* Class::GetBoundedArrayClass(Il2CppClass *eclass, uint32_t rank, bool bounded)
    {
        return il2cpp::metadata::ArrayMetadata::GetBoundedArrayClass(eclass, rank, bounded);
    }

    Il2CppClass* Class::GetInflatedGenericInstanceClass(Il2CppClass* klass, const Il2CppType** types, uint32_t typeCount)
    {
        return GetInflatedGenericInstanceClass(klass, MetadataCache::GetGenericInst(types, typeCount));
    }

    Il2CppClass* Class::GetInflatedGenericInstanceClass(Il2CppClass* klass, const Il2CppGenericInst* genericInst)
    {
        IL2CPP_ASSERT(Class::IsGeneric(klass));

        Il2CppGenericClass* gclass = il2cpp::metadata::GenericMetadata::GetGenericClass(klass, genericInst);
        return GenericClass::GetClass(gclass);
    }

    Il2CppClass* Class::InflateGenericClass(Il2CppClass* klass, Il2CppGenericContext *context)
    {
        const Il2CppType* inflated = InflateGenericType(&klass->byval_arg, context);

        return FromIl2CppType(inflated);
    }

    const Il2CppType* Class::InflateGenericType(const Il2CppType* type, Il2CppGenericContext* context)
    {
        return il2cpp::metadata::GenericMetadata::InflateIfNeeded(type, context, true);
    }

    bool Class::HasDefaultConstructor(Il2CppClass* klass)
    {
        const char ctorName[] = ".ctor";
        void* iter = NULL;
        while (const MethodInfo* method = Class::GetMethods(klass, &iter))
        {
            if (strncmp(method->name, ctorName, utils::StringUtils::LiteralLength(ctorName)) == 0 && method->parameters_count == 0)
                return true;
        }

        return false;
    }

    int Class::GetArrayElementSize(const Il2CppClass *klass)
    {
        const Il2CppType *type = &klass->byval_arg;

    handle_enum:
        switch (type->type)
        {
            case IL2CPP_TYPE_I1:
            case IL2CPP_TYPE_U1:
            case IL2CPP_TYPE_BOOLEAN:
                return 1;

            case IL2CPP_TYPE_I2:
            case IL2CPP_TYPE_U2:
            case IL2CPP_TYPE_CHAR:
                return 2;

            case IL2CPP_TYPE_I4:
            case IL2CPP_TYPE_U4:
            case IL2CPP_TYPE_R4:
                return 4;

            case IL2CPP_TYPE_I:
            case IL2CPP_TYPE_U:
            case IL2CPP_TYPE_PTR:
            case IL2CPP_TYPE_CLASS:
            case IL2CPP_TYPE_STRING:
            case IL2CPP_TYPE_OBJECT:
            case IL2CPP_TYPE_SZARRAY:
            case IL2CPP_TYPE_ARRAY:
            case IL2CPP_TYPE_VAR:
            case IL2CPP_TYPE_MVAR:
                return sizeof(Il2CppObject*);

            case IL2CPP_TYPE_I8:
            case IL2CPP_TYPE_U8:
            case IL2CPP_TYPE_R8:
                return 8;

            case IL2CPP_TYPE_VALUETYPE:
                if (Type::IsEnum(type))
                {
                    type = Class::GetEnumBaseType(Type::GetClass(type));
                    klass = klass->element_class;
                    goto handle_enum;
                }
                return Class::GetInstanceSize(klass) - sizeof(Il2CppObject);

            case IL2CPP_TYPE_GENERICINST:
                type = &GenericClass::GetTypeDefinition(type->data.generic_class)->byval_arg;
                goto handle_enum;

            case IL2CPP_TYPE_VOID:
                return 0;

            default:
                // g_error ("unknown type 0x%02x in mono_class_array_element_size", type->type);
                IL2CPP_NOT_IMPLEMENTED_NO_ASSERT(Class::GetArrayElementSize, "Should throw a nice error");
        }

        return -1;
    }

    const Il2CppType* Class::GetType(Il2CppClass *klass, const TypeNameParseInfo &info)
    {
        // Attempt to resolve a generic type definition.
        if (Class::IsGeneric(klass))
            klass = ResolveGenericInstanceType(klass, info, kTypeSearchFlagNone);

        bool bounded = false;

        std::vector<int32_t>::const_iterator it = info.modifiers().begin();

        if (info.is_bounded())
        {
            bounded = false;
        }

        while (it != info.modifiers().end())
        {
            if (*it == 0)
            {
                // byref is always the last modifier, so we can return here.
                return &klass->this_arg;
            }

            if (*it == -1)
            {
                klass = Class::GetPtrClass(klass);
            }
            else if (*it == -2)
            {
                bounded = true;
            }
            else
            {
                klass = Class::GetBoundedArrayClass(klass, *it, bounded);
            }

            ++it;
        }

        if (klass == NULL)
            return NULL;

        return &klass->byval_arg;
    }

    bool Class::HasAttribute(Il2CppClass *klass, Il2CppClass *attr_class)
    {
        return Reflection::HasAttribute(klass, attr_class);
    }

    const Il2CppImage* Class::GetImage(Il2CppClass *klass)
    {
        return klass->image;
    }

    Il2CppMetadataGenericContainerHandle Class::GetGenericContainer(Il2CppClass *klass)
    {
        return klass->genericContainerHandle;
    }

    const MethodInfo* Class::GetCCtor(Il2CppClass *klass)
    {
        if (!klass->has_cctor)
            return NULL;

        return GetMethodFromNameFlags(klass, ".cctor", IgnoreNumberOfArguments, METHOD_ATTRIBUTE_SPECIAL_NAME);
    }

    const char* Class::GetFieldDefaultValue(const FieldInfo *field, const Il2CppType** type)
    {
        return reinterpret_cast<const char*>(MetadataCache::GetFieldDefaultValue(field, type));
    }

    int Class::GetFieldMarshaledSize(const FieldInfo *field)
    {
        int marshaledFieldSize = MetadataCache::GetFieldMarshaledSizeForField(field);
        if (marshaledFieldSize != -1)
            return marshaledFieldSize;

        if (field->type->type == IL2CPP_TYPE_BOOLEAN)
            return 4;
        if (field->type->type == IL2CPP_TYPE_CHAR)
            return 1;

        size_t size = il2cpp::metadata::FieldLayout::GetTypeSizeAndAlignment(field->type).size;
        IL2CPP_ASSERT(size < static_cast<size_t>(std::numeric_limits<int>::max()));
        return static_cast<int>(size);
    }

    int Class::GetFieldMarshaledAlignment(const FieldInfo *field)
    {
        if (MetadataCache::GetFieldMarshaledSizeForField(field) == 0)
        {
            // We have no marshaled field size, so ignore marshaled alignment for this field.
            return 0;
        }

        if (field->type->type == IL2CPP_TYPE_BOOLEAN)
            return 4;
        if (field->type->type == IL2CPP_TYPE_CHAR)
            return 1;

        uint8_t alignment = il2cpp::metadata::FieldLayout::GetTypeSizeAndAlignment(field->type).alignment;
        return static_cast<int>(alignment);
    }

    Il2CppClass* Class::GetPtrClass(const Il2CppType* type)
    {
        return GetPtrClass(Class::FromIl2CppType(type));
    }

    Il2CppClass* Class::GetPtrClass(Il2CppClass* elementClass)
    {
        // Check if the pointer class was created before taking the g_MetadataLock
        Il2CppClass* pointerClass = MetadataCache::GetPointerType(elementClass);
        if (pointerClass)
            return pointerClass;

        il2cpp::os::FastAutoLock lock(&g_MetadataLock);

        // Check if the pointer class was created while we were waiting for the g_MetadataLock
        pointerClass = MetadataCache::GetPointerType(elementClass);
        if (pointerClass)
            return pointerClass;

        pointerClass = (Il2CppClass*)MetadataCalloc(1, sizeof(Il2CppClass));
        pointerClass->klass = pointerClass;

        pointerClass->namespaze = elementClass->namespaze;
        pointerClass->name = il2cpp::utils::StringUtils::StringDuplicate(il2cpp::utils::StringUtils::Printf("%s*", elementClass->name).c_str());

        pointerClass->image = elementClass->image;
        pointerClass->initialized = true;
        pointerClass->flags = TYPE_ATTRIBUTE_CLASS | (elementClass->flags & TYPE_ATTRIBUTE_VISIBILITY_MASK);
        pointerClass->instance_size = sizeof(void*);
        pointerClass->stack_slot_size = sizeof(void*);
        pointerClass->size_inited = true;

        pointerClass->this_arg.type = pointerClass->byval_arg.type = IL2CPP_TYPE_PTR;
        pointerClass->this_arg.data.type = pointerClass->byval_arg.data.type = &elementClass->byval_arg;
        pointerClass->this_arg.byref = true;

        pointerClass->parent = NULL;
        pointerClass->typeHierarchyDepth = 1;
        pointerClass->castClass = pointerClass->element_class = elementClass;

        MetadataCache::AddPointerTypeLocked(elementClass, pointerClass, lock);

        return pointerClass;
    }

    bool Class::HasReferences(Il2CppClass *klass)
    {
        if (!klass->size_inited)
        {
            SetupFields(klass);

            if (!klass->size_inited)
            {
                abort();
                /* Be conservative */
                return true;
            }
        }

        return klass->has_references;
    }

    const il2cpp::utils::dynamic_array<Il2CppClass*>& Class::GetStaticFieldData()
    {
        return s_staticFieldData;
    }

    const size_t kWordSize = (8 * sizeof(size_t));

    static inline void set_bit(size_t* bitmap, size_t index)
    {
        bitmap[index / kWordSize] |= (size_t)1 << (index % kWordSize);
    }

    size_t Class::GetBitmapSize(const Il2CppClass* klass)
    {
        size_t maxBits = klass->instance_size / sizeof(void*);
        size_t maxWords = 1 + (maxBits / sizeof(size_t));
        return sizeof(size_t) * maxWords;
    }

    void Class::GetBitmap(Il2CppClass* klass, size_t* bitmap, size_t& maxSetBit)
    {
        Class::Init(klass);
        return il2cpp::vm::GetBitmapNoInit(klass, bitmap, maxSetBit, 0, NULL);
    }

    const char *Class::GetAssemblyName(const Il2CppClass *klass)
    {
        return klass->image->name;
    }

    const char *Class::GetAssemblyNameNoExtension(const Il2CppClass *klass)
    {
        return klass->image->nameNoExt;
    }

    void GetBitmapNoInit(Il2CppClass* klass, size_t* bitmap, size_t& maxSetBit, size_t parentOffset, const il2cpp::os::FastAutoLock* lockPtr)
    {
        Il2CppClass* currentClass = klass;

        while (currentClass)
        {
            for (uint16_t index = 0; index < currentClass->field_count; index++)
            {
                FieldInfo* field = currentClass->fields + index;
                if (field->type->attrs & (FIELD_ATTRIBUTE_STATIC | FIELD_ATTRIBUTE_HAS_FIELD_RVA))
                    continue;

                IL2CPP_ASSERT(!field->type->byref);

                size_t offset = parentOffset + field->offset;

                const Il2CppType* type = Type::GetUnderlyingType(field->type);

                switch (type->type)
                {
                    case IL2CPP_TYPE_I1:
                    case IL2CPP_TYPE_U1:
                    case IL2CPP_TYPE_BOOLEAN:
                    case IL2CPP_TYPE_I2:
                    case IL2CPP_TYPE_U2:
                    case IL2CPP_TYPE_CHAR:
                    case IL2CPP_TYPE_I4:
                    case IL2CPP_TYPE_U4:
                    case IL2CPP_TYPE_I8:
                    case IL2CPP_TYPE_U8:
                    case IL2CPP_TYPE_I:
                    case IL2CPP_TYPE_U:
                    case IL2CPP_TYPE_R4:
                    case IL2CPP_TYPE_R8:
                    case IL2CPP_TYPE_PTR:
                    case IL2CPP_TYPE_FNPTR:
                        break;
                    case IL2CPP_TYPE_STRING:
                    case IL2CPP_TYPE_SZARRAY:
                    case IL2CPP_TYPE_CLASS:
                    case IL2CPP_TYPE_OBJECT:
                    case IL2CPP_TYPE_ARRAY:
                    case IL2CPP_TYPE_VAR:
                    case IL2CPP_TYPE_MVAR:
                        IL2CPP_ASSERT(0 == (offset % sizeof(void*)));
                        set_bit(bitmap, offset / sizeof(void*));
                        maxSetBit = std::max(maxSetBit, offset / sizeof(void*));
                        break;
                    case IL2CPP_TYPE_GENERICINST:
                        if (!Type::GenericInstIsValuetype(type))
                        {
                            IL2CPP_ASSERT(0 == (offset % sizeof(void*)));
                            set_bit(bitmap, offset / sizeof(void*));
                            maxSetBit = std::max(maxSetBit, offset / sizeof(void*));
                            break;
                        }
                        else
                        {
                            /* fall through */
                        }
                    case IL2CPP_TYPE_VALUETYPE:
                    {
                        Il2CppClass* fieldClass = Class::FromIl2CppType(field->type);
                        if (lockPtr == NULL)
                            Class::Init(fieldClass);
                        else
                            Class::InitLocked(fieldClass, *lockPtr);
                        if (fieldClass->has_references)
                            GetBitmapNoInit(fieldClass, bitmap, maxSetBit, offset - sizeof(Il2CppObject) /* nested field offset includes padding for boxed structure. Remove for struct fields */, lockPtr);
                        break;
                    }
                    default:
                        IL2CPP_NOT_IMPLEMENTED(Class::GetClassBitmap);
                        break;
                }
            }

            currentClass = currentClass->parent;
        }
    }

    void SetupGCDescriptor(Il2CppClass* klass, const il2cpp::os::FastAutoLock& lock)
    {
        const size_t kMaxAllocaSize = 1024;
        size_t bitmapSize = Class::GetBitmapSize(klass);
        size_t* bitmap = NULL;
        std::vector<size_t> buffer(0);

        if (bitmapSize > kMaxAllocaSize)
        {
            buffer.resize(bitmapSize / sizeof(size_t));
            bitmap = (size_t*)&buffer[0];
        }
        else
        {
            bitmap = (size_t*)alloca(bitmapSize);
        }

        memset(bitmap, 0, bitmapSize);
        size_t maxSetBit = 0;
        GetBitmapNoInit(klass, bitmap, maxSetBit, 0, &lock);

        if (klass == il2cpp_defaults.string_class)
            klass->gc_desc = il2cpp::gc::GarbageCollector::MakeDescriptorForString();
        else if (klass->rank)
            klass->gc_desc = il2cpp::gc::GarbageCollector::MakeDescriptorForArray();
        else
            klass->gc_desc = il2cpp::gc::GarbageCollector::MakeDescriptorForObject(bitmap, (int)maxSetBit + 1);
    }

#define CHECK_IF_NULL(v)    \
    if ( (v) == NULL && (searchFlags & kTypeSearchFlagThrowOnError) != 0 ) \
        Exception::Raise (Exception::GetTypeLoadException (info)); \
    if ( (v) == NULL ) \
        return NULL;

    static Il2CppClass * resolve_generic_instance_internal(const il2cpp::vm::TypeNameParseInfo &info, Il2CppClass *generic_class, const Il2CppType** generic_arguments, TypeSearchFlags searchFlags)
    {
        Il2CppClass *klass = NULL;

        Il2CppMetadataGenericContainerHandle containerHandle = Class::GetGenericContainer(generic_class);
        uint32_t type_argc = MetadataCache::GetGenericContainerCount(containerHandle);
        if (type_argc != info.type_arguments().size())
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetArgumentException("name", "The number of generic arguments provided doesn't equal the arity of the generic type definition."));

        if (info.assembly_name().name.empty())
        {
            const Il2CppImage* image = Image::GetExecutingImage();
            klass = MetadataCache::GetGenericInstanceType(generic_class, generic_arguments, type_argc);

            if (klass == NULL && image != Image::GetCorlib())
            {
                // Try mscorlib
                image = (Il2CppImage*)Image::GetCorlib();
                klass = MetadataCache::GetGenericInstanceType(generic_class, generic_arguments, type_argc);
            }
        }
        else
        {
            const Il2CppAssembly *assembly = Assembly::Load(info.assembly_name().name.c_str());

            CHECK_IF_NULL(assembly);

            Il2CppImage *image = (Il2CppImage*)Assembly::GetImage(assembly);

            CHECK_IF_NULL(image);

            klass = MetadataCache::GetGenericInstanceType(generic_class, generic_arguments, type_argc);
        }

        return klass;
    }

    static Il2CppClass* ResolveGenericInstanceType(Il2CppClass* klass, const TypeNameParseInfo& info, TypeSearchFlags searchFlags)
    {
        if (info.has_generic_arguments())
        {
            const Il2CppType** generic_arguments = (const Il2CppType**)alloca(info.type_arguments().size() * sizeof(const Il2CppType*));

            int i = 0;
            std::vector<TypeNameParseInfo>::const_iterator it = info.type_arguments().begin();
            while (it != info.type_arguments().end())
            {
                const Il2CppType * generic_argument = Class::il2cpp_type_from_type_info(*it, searchFlags);

                CHECK_IF_NULL(generic_argument);

                generic_arguments[i] = generic_argument;

                ++it;
                ++i;
            }

            klass = resolve_generic_instance_internal(info, klass, generic_arguments, searchFlags);

            CHECK_IF_NULL(klass);
        }

        if (klass != NULL)
            Class::Init(klass);

        return klass;
    }

    static Il2CppClass* resolve_parse_info_internal(const TypeNameParseInfo& info, TypeSearchFlags searchFlags)
    {
        Il2CppClass *klass = NULL;

        if (info.assembly_name().name.empty())
        {
            const Il2CppImage* image;
            bool dontUseExecutingImage = searchFlags & kTypeSearchFlagDontUseExecutingImage;
            if (dontUseExecutingImage)
            {
                image = Image::GetCorlib();
            }
            else
            {
                image = Image::GetExecutingImage();
            }

            klass = Image::FromTypeNameParseInfo(image, info, searchFlags & kTypeSearchFlagIgnoreCase);
            if (klass)
            {
                return klass;
            }
            hybridclr::interpreter::MachineState& state = hybridclr::interpreter::InterpreterModule::GetCurrentThreadMachineState();
            const hybridclr::interpreter::InterpFrame* frame = state.GetTopFrame();
            if (frame)
            {
                const Il2CppImage* interpImage = frame->method->method->klass->image;
                if (interpImage != image)
                {
                    klass = Image::FromTypeNameParseInfo(interpImage, info, searchFlags & kTypeSearchFlagIgnoreCase);
                    if (klass)
                    {
                        return klass;
                    }
                }
            }
            const  Il2CppImage* interpImage = state.GetTopExecutingImage();
            if (interpImage)
            {
                klass = Image::FromTypeNameParseInfo(interpImage, info, searchFlags & kTypeSearchFlagIgnoreCase);
                if (klass)
                {
                    return klass;
                }
            }

            // First, try mscorlib            if (klass == NULL && image != Image::GetCorlib())
            klass = Image::FromTypeNameParseInfo(Image::GetCorlib(), info, searchFlags & kTypeSearchFlagIgnoreCase);
            if (klass)
            {
                return klass;
            }

            // If we did not find it, now look in all loaded assemblies, except the ones we have tried already.
            if (!dontUseExecutingImage)
            {
                for (auto assembly : *Assembly::GetAllAssemblies())
                {
                    auto currentImage = Assembly::GetImage(assembly);
                    if (currentImage != Image::GetCorlib() && currentImage != image)
                    {
                        klass = Image::FromTypeNameParseInfo(currentImage, info, searchFlags & kTypeSearchFlagIgnoreCase);
                        if (klass)
                            return klass;
                    }
                }
            }
        }
        else
        {
            const Il2CppAssembly *assembly = Assembly::Load(info.assembly_name().name.c_str());

            CHECK_IF_NULL(assembly);

            Il2CppImage *image = (Il2CppImage*)Assembly::GetImage(assembly);

            CHECK_IF_NULL(image);

            klass = Image::FromTypeNameParseInfo(image, info, searchFlags & kTypeSearchFlagIgnoreCase);
        }

        return klass;
    }

    const Il2CppType* Class::il2cpp_type_from_type_info(const TypeNameParseInfo& info, TypeSearchFlags searchFlags)
    {
        Il2CppClass *klass = resolve_parse_info_internal(info, searchFlags);

        CHECK_IF_NULL(klass);

        klass = ResolveGenericInstanceType(klass, info, searchFlags);

        CHECK_IF_NULL(klass);

        const Il2CppType *type = Class::GetType(klass, info);

        CHECK_IF_NULL(type);

        return type;
    }

    Il2CppClass* Class::GetDeclaringType(Il2CppClass* klass)
    {
        return klass->declaringType;
    }

    const MethodInfo* Class::GetVirtualMethod(Il2CppClass *klass, const MethodInfo *virtualMethod)
    {
        IL2CPP_ASSERT(klass->is_vtable_initialized);

        if ((virtualMethod->flags & METHOD_ATTRIBUTE_FINAL) || !(virtualMethod->flags & METHOD_ATTRIBUTE_VIRTUAL))
            return virtualMethod;

        Il2CppClass* methodDeclaringType = virtualMethod->klass;
        const MethodInfo* vtableSlotMethod;
        if (Class::IsInterface(methodDeclaringType))
        {
            const VirtualInvokeData* invokeData = ClassInlines::GetInterfaceInvokeDataFromVTable(klass, methodDeclaringType, virtualMethod->slot);
            if (invokeData == NULL)
                return NULL;
            vtableSlotMethod = invokeData->method;
        }
        else
        {
            IL2CPP_ASSERT(virtualMethod->slot < klass->vtable_count);
            vtableSlotMethod = klass->vtable[virtualMethod->slot].method;
        }

        if (Method::IsGenericInstanceMethod(virtualMethod))
            return il2cpp::metadata::GenericMethod::GetGenericVirtualMethod(vtableSlotMethod, virtualMethod);
        return vtableSlotMethod;
    }

    static bool is_generic_argument(Il2CppType* type)
    {
        return type->type == IL2CPP_TYPE_VAR || type->type == IL2CPP_TYPE_MVAR;
    }

    Il2CppClass* Class::GenericParamGetBaseType(Il2CppClass* klass)
    {
        Il2CppType* type = &klass->byval_arg;
        IL2CPP_ASSERT(is_generic_argument(type));

        Il2CppMetadataGenericParameterHandle gparam = type->data.genericParameterHandle;

        Il2CppClass** constraints = GetOrCreateMonoGenericParameterInfo(gparam)->constraints;

        Il2CppClass* base_class = il2cpp_defaults.object_class;

        if (constraints)
        {
            for (int i = 0; constraints[i]; ++i)
            {
                Il2CppClass* constraint = constraints[i];

                if (IsInterface(constraint))
                    continue;

                Il2CppType* constraint_type = &constraint->byval_arg;
                if (is_generic_argument(constraint_type))
                {
                    Il2CppMetadataGenericParameterHandle constraint_param = constraint_type->data.genericParameterHandle;
                    Il2CppGenericParameterInfo constraint_info = MetadataCache::GetGenericParameterInfo(constraint_param);
                    if ((constraint_info.flags & IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_REFERENCE_TYPE_CONSTRAINT) == 0 &&
                        (constraint_info.flags & IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NOT_NULLABLE_VALUE_TYPE_CONSTRAINT) == 0)
                        continue;
                }

                base_class = constraint;
            }
        }

        if (base_class == il2cpp_defaults.object_class)
        {
            Il2CppGenericParameterInfo gparamInfo = MetadataCache::GetGenericParameterInfo(gparam);
            if ((gparamInfo.flags & IL2CPP_GENERIC_PARAMETER_ATTRIBUTE_NOT_NULLABLE_VALUE_TYPE_CONSTRAINT) != 0)
                base_class = il2cpp_defaults.value_type_class;
        }

        return base_class;
    }

    MonoGenericParameterInfo* Class::GetOrCreateMonoGenericParameterInfo(Il2CppMetadataGenericParameterHandle parameterHandle)
    {
        Il2CppGenericParameterInfo paramInfo = il2cpp::vm::MetadataCache::GetGenericParameterInfo(parameterHandle);

        MonoGenericParameterInfo *monoParam = (MonoGenericParameterInfo*)il2cpp::vm::Reflection::GetMonoGenericParameterInfo(parameterHandle);
        if (monoParam == NULL)
        {
            monoParam = (MonoGenericParameterInfo*)IL2CPP_MALLOC(sizeof(MonoGenericParameterInfo));
            monoParam->flags = paramInfo.flags;
            monoParam->token = paramInfo.num;
            monoParam->name = paramInfo.name;
            monoParam->pklass = NULL;
            if (paramInfo.containerHandle)
                monoParam->pklass = il2cpp::vm::MetadataCache::GetContainerDeclaringType(paramInfo.containerHandle);

            int16_t constraintsCount = il2cpp::vm::MetadataCache::GetGenericConstraintCount(parameterHandle);
            monoParam->constraints = (Il2CppClass**)IL2CPP_MALLOC(sizeof(Il2CppClass*) * (constraintsCount + 1));
            for (int i = 0; i < constraintsCount; ++i)
            {
                const Il2CppType *constraintType = il2cpp::vm::MetadataCache::GetGenericParameterConstraintFromIndex(parameterHandle, i);
                monoParam->constraints[i] = il2cpp::vm::Class::FromIl2CppType(constraintType);
            }

            monoParam->constraints[constraintsCount] = NULL;

            il2cpp::vm::Reflection::SetMonoGenericParameterInfo(parameterHandle, monoParam);
        }

        return monoParam;
    }
} /* namespace vm */
} /* namespace il2cpp */
