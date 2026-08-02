#include "il2cpp-config.h"
#include "RuntimeType.h"

#include "RuntimeTypeHandle.h"
#include "Type.h"
#include "il2cpp-api.h"
#include "il2cpp-runtime-metadata.h"
#include "il2cpp-tabledefs.h"
#include "metadata/GenericMetadata.h"
#include "mono-structs.h"
#include "utils/Functional.h"
#include "utils/Il2CppHashSet.h"
#include "utils/StringUtils.h"
#include "utils/dynamic_array.h"
#include "vm-utils/VmStringUtils.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/ClassInlines.h"
#include "vm/Field.h"
#include "vm/GenericClass.h"
#include "vm/MetadataCache.h"
#include "vm/Method.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/String.h"
#include "vm/Type.h"
#include <set>
#include <vector>

#include "RuntimeTypeHandle.h"

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
    struct Il2CppEventInfoHash
    {
        size_t operator()(const EventInfo* eventInfo) const
        {
            return il2cpp::utils::StringUtils::Hash(eventInfo->name);
        }
    };

    struct Il2CppEventInfoCompare
    {
        bool operator()(const EventInfo* event1, const EventInfo* event2) const
        {
            // You can't overload events
            return strcmp(event1->name, event2->name) == 0;
        }
    };

    typedef Il2CppHashMap<const EventInfo*, Il2CppClass*, Il2CppEventInfoHash, Il2CppEventInfoCompare> EventMap;

    struct PropertyPair
    {
        const PropertyInfo* property;
        Il2CppClass* originalType;

        PropertyPair(const PropertyInfo* property, Il2CppClass* originalType) : property(property), originalType(originalType)
        {
        }
    };

    typedef std::vector<PropertyPair> PropertyPairVector;

    static inline bool IsPublic(const FieldInfo* field)
    {
        return (field->type->attrs & FIELD_ATTRIBUTE_FIELD_ACCESS_MASK) == FIELD_ATTRIBUTE_PUBLIC;
    }

    static inline bool IsPrivate(const FieldInfo* field)
    {
        return (field->type->attrs & FIELD_ATTRIBUTE_FIELD_ACCESS_MASK) == FIELD_ATTRIBUTE_PRIVATE;
    }

    static inline bool IsStatic(const FieldInfo* field)
    {
        return (field->type->attrs & FIELD_ATTRIBUTE_STATIC) != 0;
    }

    static inline bool IsPublic(const PropertyInfo* property)
    {
        if (property->get != NULL && (property->get->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PUBLIC)
            return true;

        if (property->set != NULL && (property->set->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PUBLIC)
            return true;

        return false;
    }

    static inline bool IsPrivate(const PropertyInfo* property)
    {
        if (property->get != NULL && (property->get->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) != METHOD_ATTRIBUTE_PRIVATE)
            return false;

        if (property->set != NULL && (property->set->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) != METHOD_ATTRIBUTE_PRIVATE)
            return false;

        return true;
    }

    static inline bool IsStatic(const PropertyInfo* property)
    {
        if (property->get != NULL)
            return (property->get->flags & METHOD_ATTRIBUTE_STATIC) != 0;

        if (property->set != NULL)
            return (property->set->flags & METHOD_ATTRIBUTE_STATIC) != 0;

        return false;
    }

    static inline bool IsPublic(const MethodInfo* method)
    {
        return (method->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PUBLIC;
    }

    static inline bool IsPrivate(const MethodInfo* method)
    {
        return (method->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PRIVATE;
    }

    static inline bool IsStatic(const MethodInfo* method)
    {
        return (method->flags & METHOD_ATTRIBUTE_STATIC) != 0;
    }

    // From MSDN: An event is considered public to reflection if it has at least one method or accessor that is public.
    static inline bool IsPublic(const EventInfo* event)
    {
        if (event->add != NULL && (event->add->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PUBLIC)
            return true;

        if (event->remove != NULL && (event->remove->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PUBLIC)
            return true;

        if (event->raise != NULL && (event->raise->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PUBLIC)
            return true;

        return false;
    }

    static inline bool IsPrivate(const EventInfo* event)
    {
        if (event->add != NULL && (event->add->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) != METHOD_ATTRIBUTE_PRIVATE)
            return false;

        if (event->remove != NULL && (event->remove->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) != METHOD_ATTRIBUTE_PRIVATE)
            return false;

        if (event->raise != NULL && (event->raise->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) != METHOD_ATTRIBUTE_PRIVATE)
            return false;

        return true;
    }

    static inline bool IsStatic(const EventInfo* event)
    {
        if (event->add != NULL)
            return (event->add->flags & METHOD_ATTRIBUTE_STATIC) != 0;

        if (event->remove != NULL)
            return (event->remove->flags & METHOD_ATTRIBUTE_STATIC) != 0;

        if (event->raise != NULL)
            return (event->raise->flags & METHOD_ATTRIBUTE_STATIC) != 0;

        return false;
    }

    template<typename MemberInfo, typename NameFilter>
    static bool CheckMemberMatch(const MemberInfo* member, const Il2CppClass* type, const Il2CppClass* originalType, int32_t bindingFlags, const NameFilter& nameFilter)
    {
        uint32_t accessBindingFlag = IsPublic(member) ? BFLAGS_Public : BFLAGS_NonPublic;

        if ((bindingFlags & accessBindingFlag) == 0)
            return false;

        if (type != originalType && IsPrivate(member)) // Private members are not part of derived class
            return false;

        if (IsStatic(member))
        {
            if ((bindingFlags & BFLAGS_Static) == 0)
                return false;

            if ((bindingFlags & BFLAGS_FlattenHierarchy) == 0 && type != originalType)
                return false;
        }
        else if ((bindingFlags & BFLAGS_Instance) == 0)
        {
            return false;
        }

        if (!nameFilter(member->name))
            return false;

        return true;
    }

    template<typename NameFilter>
    static inline void CollectTypeEvents(Il2CppClass* type, Il2CppClass* const originalType, int32_t bindingFlags, EventMap& events, const NameFilter& nameFilter)
    {
        void* iter = NULL;
        while (const EventInfo* event = vm::Class::GetEvents(type, &iter))
        {
            if (CheckMemberMatch(event, type, originalType, bindingFlags, nameFilter))
            {
                if (events.find(event) != events.end())
                    continue;

                events[event] = originalType;
            }
        }
    }

    static inline bool ValidBindingFlagsForGetMember(uint32_t bindingFlags)
    {
        return (bindingFlags & BFLAGS_Static) != 0 || (bindingFlags & BFLAGS_Instance) != 0;
    }

    template<typename NameFilter>
    static inline EventMap GetEventsImpl(Il2CppReflectionType* type, int listType, Il2CppReflectionType* reflectedType, const NameFilter& nameFilter)
    {
        EventMap events;

        if (type->type->byref)
            return events;

        Il2CppClass* typeInfo = vm::Class::FromIl2CppType(type->type);

        CollectTypeEvents(typeInfo, typeInfo, BFLAGS_MatchAll, events, nameFilter);

        Il2CppClass* const originalType = typeInfo;
        typeInfo = vm::Class::GetParent(typeInfo);

        while (typeInfo != NULL)
        {
            CollectTypeEvents(typeInfo, originalType, BFLAGS_MatchAll, events, nameFilter);
            typeInfo = vm::Class::GetParent(typeInfo);
        }

        return events;
    }

    static EventMap GetEventsByName(Il2CppReflectionType* _this, const char* name, int listType, Il2CppReflectionType* reflectedType)
    {
        if (name == NULL)
            return GetEventsImpl(_this, listType, reflectedType, utils::functional::TrueFilter());

        if (listType == MLISTTYPE_CaseInsensitive)
        {
            return GetEventsImpl(_this, listType, reflectedType, utils::functional::Filter<const char*, utils::VmStringUtils::CaseInsensitiveComparer>(name));
        }

        return GetEventsImpl(_this, listType, reflectedType, utils::functional::Filter<const char*, utils::VmStringUtils::CaseSensitiveComparer>(name));
    }

    static bool PropertyEqual(const PropertyInfo* prop1, const PropertyInfo* prop2)
    {
        // Name check is not enough, property can be overloaded
        if (strcmp(prop1->name, prop2->name) != 0)
            return false;

        return vm::Method::IsSameOverloadSignature(prop1, prop2);
    }

    static bool PropertyPairVectorContains(const PropertyPairVector& properties, const PropertyInfo* property)
    {
        for (PropertyPairVector::const_iterator it = properties.begin(), end = properties.end(); it != end; ++it)
            if (PropertyEqual(it->property, property))
                return true;

        return false;
    }

    template<typename NameFilter>
    static void CollectTypeProperties(Il2CppClass* type, uint32_t bindingFlags, const NameFilter& nameFilter, Il2CppClass* const originalType, PropertyPairVector& properties)
    {
        void* iter = NULL;
        while (const PropertyInfo* property = vm::Class::GetProperties(type, &iter))
        {
            if (CheckMemberMatch(property, type, originalType, bindingFlags, nameFilter))
            {
                if (PropertyPairVectorContains(properties, property))
                    continue;

                properties.push_back(PropertyPair(property, originalType));
            }
        }
    }

    template<typename NameFilter>
    static PropertyPairVector GetPropertiesByNameImpl(const Il2CppType* type, uint32_t bindingFlags, const NameFilter& nameFilter)
    {
        PropertyPairVector properties;
        Il2CppClass* typeInfo = vm::Class::FromIl2CppType(type);
        Il2CppClass* const originalTypeInfo = typeInfo;

        properties.reserve(typeInfo->property_count);
        CollectTypeProperties(typeInfo, bindingFlags, nameFilter, originalTypeInfo, properties);

        if ((bindingFlags & BFLAGS_DeclaredOnly) == 0)
        {
            for (typeInfo = typeInfo->parent; typeInfo != NULL; typeInfo = typeInfo->parent)
            {
                CollectTypeProperties(typeInfo, bindingFlags, nameFilter, originalTypeInfo, properties);
            }
        }

        return properties;
    }

    static PropertyPairVector GetPropertiesByName(Il2CppReflectionType* _this, const char* name, uint32_t bindingFlags, bool ignoreCase, Il2CppReflectionType* type)
    {
        if (type->type->byref || !ValidBindingFlagsForGetMember(bindingFlags))
            return PropertyPairVector();

        if (name != NULL)
        {
            if (ignoreCase)
            {
                return GetPropertiesByNameImpl(type->type, bindingFlags, utils::functional::Filter<const char*, utils::VmStringUtils::CaseInsensitiveComparer>(name));
            }

            return GetPropertiesByNameImpl(type->type, bindingFlags, utils::functional::Filter<const char*, utils::VmStringUtils::CaseSensitiveComparer>(name));
        }

        return GetPropertiesByNameImpl(type->type, bindingFlags, utils::functional::TrueFilter());
    }

    template<typename NameFilter>
    static inline void CollectTypeFields(Il2CppClass* type, const Il2CppClass* const originalType, int32_t bindingFlags, std::vector<FieldInfo*>& fields, const NameFilter& nameFilter)
    {
        void* iterator = NULL;
        FieldInfo* field = NULL;
        while ((field = vm::Class::GetFields(type, &iterator)) != NULL)
        {
            if (CheckMemberMatch(field, type, originalType, bindingFlags, nameFilter))
                fields.push_back(field);
        }
    }

    template<typename NameFilter>
    static inline std::vector<FieldInfo*> GetFieldsImpl(Il2CppReflectionType* _this, int bindingFlags, Il2CppReflectionType* reflectedType, const NameFilter& nameFilter)
    {
        std::vector<FieldInfo*> fields;

        if (reflectedType->type->byref || !ValidBindingFlagsForGetMember(bindingFlags))
            return fields;

        Il2CppClass* typeInfo = vm::Class::FromIl2CppType(reflectedType->type);
        Il2CppClass* const originalType = typeInfo;

        CollectTypeFields(typeInfo, typeInfo, bindingFlags, fields, nameFilter);

        if ((bindingFlags & BFLAGS_DeclaredOnly) == 0)
        {
            typeInfo = typeInfo->parent;

            while (typeInfo != NULL)
            {
                CollectTypeFields(typeInfo, originalType, bindingFlags, fields, nameFilter);
                typeInfo = typeInfo->parent;
            }
        }

        return fields;
    }

    static std::vector<FieldInfo*> GetFieldsByName(Il2CppReflectionType* _this, const char* name, int bindingFlags, Il2CppReflectionType* reflectedType)
    {
        if (name == NULL)
            return GetFieldsImpl(_this, bindingFlags, reflectedType, utils::functional::TrueFilter());

        if (bindingFlags & BFLAGS_IgnoreCase)
        {
            return GetFieldsImpl(_this, bindingFlags, reflectedType, utils::functional::Filter<const char*, utils::VmStringUtils::CaseInsensitiveComparer>(name));
        }

        return GetFieldsImpl(_this, bindingFlags, reflectedType, utils::functional::Filter<const char*, utils::VmStringUtils::CaseSensitiveComparer>(name));
    }

    template<typename NameFilter>
    void CollectTypeMethods(Il2CppClass* type, const Il2CppClass* originalType, uint32_t bindingFlags, const NameFilter& nameFilter, std::vector<const MethodInfo*>& methods, bool(&filledSlots)[65535])
    {
        void* iter = NULL;
        while (const MethodInfo* method = vm::Class::GetMethods(type, &iter))
        {
            if ((method->flags & METHOD_ATTRIBUTE_RT_SPECIAL_NAME) != 0 && (strcmp(method->name, ".ctor") == 0 || strcmp(method->name, ".cctor") == 0))
                continue;

            if (CheckMemberMatch(method, type, originalType, bindingFlags, nameFilter))
            {
                if ((method->flags & METHOD_ATTRIBUTE_VIRTUAL) != 0)
                {
                    if (filledSlots[method->slot])
                        continue;

                    filledSlots[method->slot] = true;
                }

                methods.push_back(method);
            }
        }
    }

    template<typename NameFilter>
    static std::vector<const MethodInfo*> GetMethodsByNameImpl(const Il2CppType* type, uint32_t bindingFlags, const NameFilter& nameFilter)
    {
        std::vector<const MethodInfo*> methods;
        bool filledSlots[65535] = { 0 };

        Il2CppClass* typeInfo = vm::Class::FromIl2CppType(type);
        Il2CppClass* const originalTypeInfo = typeInfo;

        CollectTypeMethods(typeInfo, typeInfo, bindingFlags, nameFilter, methods, filledSlots);

        if ((bindingFlags & BFLAGS_DeclaredOnly) == 0)
        {
            for (typeInfo = vm::Class::GetParent(typeInfo); typeInfo != NULL; typeInfo = vm::Class::GetParent(typeInfo))
            {
                CollectTypeMethods(typeInfo, originalTypeInfo, bindingFlags, nameFilter, methods, filledSlots);
            }
        }

        return methods;
    }

    static  std::vector<const MethodInfo*> GetMethodsByName(Il2CppReflectionType* _this, const char* name, int32_t bindingFlags, int listType, Il2CppReflectionType* type)
    {
        if (type->type->byref || !ValidBindingFlagsForGetMember(bindingFlags))
            return std::vector<const MethodInfo*>();

        if (name != NULL)
        {
            if (bindingFlags & BFLAGS_IgnoreCase || listType == MLISTTYPE_CaseInsensitive)
            {
                return GetMethodsByNameImpl(type->type, bindingFlags, utils::functional::Filter<const char*, utils::VmStringUtils::CaseInsensitiveComparer>(name));
            }

            return GetMethodsByNameImpl(type->type, bindingFlags, utils::functional::Filter<const char*, utils::VmStringUtils::CaseSensitiveComparer>(name));
        }

        return GetMethodsByNameImpl(type->type, bindingFlags, utils::functional::TrueFilter());
    }

    static inline bool CheckNestedTypeMatch(Il2CppClass* nestedType, int32_t bindingFlags)
    {
        uint32_t accessFlag = (nestedType->flags & TYPE_ATTRIBUTE_VISIBILITY_MASK) == TYPE_ATTRIBUTE_NESTED_PUBLIC ? BFLAGS_Public : BFLAGS_NonPublic;
        return (accessFlag & bindingFlags) != 0;
    }

    template<typename NameFilter>
    static std::vector<const Il2CppType*> GetNestedTypesImpl(Il2CppReflectionType* type, int32_t bindingFlags, const NameFilter& nameFilter)
    {
        bool validBindingFlags = (bindingFlags & BFLAGS_NonPublic) != 0 || (bindingFlags & BFLAGS_Public) != 0;

        std::vector<const Il2CppType*> nestedTypes;

        if (type->type->byref || !validBindingFlags)
            return nestedTypes;

        Il2CppClass* typeInfo = vm::Class::FromIl2CppType(type->type);

        // nested types are always generic type definitions, even for inflated types. As such we only store/retrieve them on
        // type definitions and generic type definitions. If we are a generic instance, use our generic type definition instead.
        if (typeInfo->generic_class)
            typeInfo = vm::GenericClass::GetTypeDefinition(typeInfo->generic_class);


        nestedTypes.reserve(typeInfo->nested_type_count);

        void* iter = NULL;
        while (Il2CppClass* nestedType = vm::Class::GetNestedTypes(typeInfo, &iter))
        {
            if (CheckNestedTypeMatch(nestedType, bindingFlags) && nameFilter(nestedType->name))
                nestedTypes.push_back(vm::Class::GetType(nestedType));
        }

        return nestedTypes;
    }

    static std::vector<const Il2CppType*> GetNestedTypesByName(Il2CppReflectionType* type, const char* name, int32_t bindingFlags)
    {
        if (name == NULL)
            return GetNestedTypesImpl(type, bindingFlags, utils::functional::TrueFilter());

        if (bindingFlags & BFLAGS_IgnoreCase)
            return GetNestedTypesImpl(type, bindingFlags, utils::functional::Filter<const char*, utils::VmStringUtils::CaseInsensitiveComparer>(name));

        return GetNestedTypesImpl(type, bindingFlags, utils::functional::Filter<const char*, utils::VmStringUtils::CaseSensitiveComparer>(name));
    }

    static std::string FormatExceptionMessageForNonConstructableGenericType(const Il2CppType* type, const Il2CppType** genericArguments, int genericArgumentCount)
    {
        std::string message;
        message += "Failed to construct generic type '";
        message += il2cpp::vm::Type::GetName(type, IL2CPP_TYPE_NAME_FORMAT_FULL_NAME);
        message += "' with generic arguments [";
        for (int i = 0; i < genericArgumentCount; i++)
        {
            if (i != 0)
                message += ", ";
            message += il2cpp::vm::Type::GetName(genericArguments[i], IL2CPP_TYPE_NAME_FORMAT_FULL_NAME);
        }
        message += "] at runtime.";

        return message;
    }

    bool RuntimeType::IsUnmanagedFunctionPointerInternal(Il2CppQCallTypeHandle type)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeType::IsUnmanagedFunctionPointerInternal);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    uint8_t RuntimeType::GetCallingConventionFromFunctionPointerInternal(Il2CppQCallTypeHandle type)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeType::GetCallingConventionFromFunctionPointerInternal);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    int32_t RuntimeType::GetGenericParameterPosition(Il2CppQCallTypeHandle type)
    {
        if (il2cpp::vm::Type::IsGenericParameter(type))
            return vm::Type::GetGenericParameterInfo(type).num;
        return -1;
    }

    intptr_t RuntimeType::FunctionPointerReturnAndParameterTypes(Il2CppQCallTypeHandle type)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeType::FunctionPointerReturnAndParameterTypes);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    intptr_t RuntimeType::GetConstructors_native(Il2CppQCallTypeHandle type, int32_t bindingAttr)
    {
        if (type->byref)
            return reinterpret_cast<intptr_t>(empty_gptr_array());

        VoidPtrArray res_array;
        res_array.reserve(4);

        Il2CppClass* startklass, * klass;
        const MethodInfo* method;
        int match;
        void* iter = NULL;

        klass = startklass = vm::Class::FromIl2CppType(type);

        iter = NULL;
        while ((method = vm::Class::GetMethods(klass, &iter)))
        {
            match = 0;
            if (method->name[0] != '.')
                continue;
            if (strcmp(method->name, ".ctor") && strcmp(method->name, ".cctor"))
                continue;
            if ((method->flags & METHOD_ATTRIBUTE_MEMBER_ACCESS_MASK) == METHOD_ATTRIBUTE_PUBLIC)
            {
                if (bindingAttr & BFLAGS_Public)
                    match++;
            }
            else
            {
                if (bindingAttr & BFLAGS_NonPublic)
                    match++;
            }
            if (!match)
                continue;
            match = 0;
            if (method->flags & METHOD_ATTRIBUTE_STATIC)
            {
                if (bindingAttr & BFLAGS_Static)
                    if ((bindingAttr & BFLAGS_FlattenHierarchy) || (klass == startklass))
                        match++;
            }
            else
            {
                if (bindingAttr & BFLAGS_Instance)
                    match++;
            }

            if (!match)
                continue;

            res_array.push_back((void*)method);
        }

        return reinterpret_cast<intptr_t>(void_ptr_array_to_gptr_array(res_array));
    }

    intptr_t RuntimeType::GetEvents_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t listType)
    {
        if (type->byref)
            return reinterpret_cast<intptr_t>(empty_gptr_array());

        const char *utf8_name = reinterpret_cast<const char*>(name);

        EventMap events = GetEventsByName(type, utf8_name, listType, type);

        MonoGPtrArray* res_array = gptr_array_of_size(events.size());

        int i = 0;
        for (EventMap::const_iterator iter = events.begin(); iter != events.end(); iter++)
        {
            res_array->pdata[i] = const_cast<EventInfo*>(iter->first.key);
            i++;
        }

        return reinterpret_cast<intptr_t>(res_array);
    }

    intptr_t RuntimeType::GetFields_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t bindingAttr, int32_t listType)
    {
        if (type->byref)
            return reinterpret_cast<intptr_t>(empty_gptr_array());

        const char *utf8_name = reinterpret_cast<const char*>(name);
        std::vector<FieldInfo*> fields = GetFieldsByName(type, utf8_name, bindingAttr, type);

        return reinterpret_cast<intptr_t>(void_ptr_array_to_gptr_array(fields));
    }

    intptr_t RuntimeType::GetMethodsByName_native(Il2CppQCallTypeHandle type, intptr_t namePtr, int32_t bindingAttr, int32_t listType)
    {
        if (type->byref)
            return reinterpret_cast<intptr_t>(empty_gptr_array());

        const char *utf8_name = reinterpret_cast<const char*>(namePtr);
        std::vector<const MethodInfo*> methods = GetMethodsByName(type, utf8_name, bindingAttr, listType, type);

        return reinterpret_cast<intptr_t>(void_ptr_array_to_gptr_array(methods));
    }

    intptr_t RuntimeType::GetNestedTypes_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t bindingAttr, int32_t listType)
    {
        if (type->byref)
            return reinterpret_cast<intptr_t>(empty_gptr_array());

        const char *utf8_name = reinterpret_cast<const char*>(name);
        std::vector<const Il2CppType*> nestedTypes = GetNestedTypesByName(type, utf8_name, bindingAttr);

        return reinterpret_cast<intptr_t>(void_ptr_array_to_gptr_array(nestedTypes));
    }

    intptr_t RuntimeType::GetPropertiesByName_native(Il2CppQCallTypeHandle type, intptr_t name, int32_t bindingAttr, int32_t listType)
    {
        if (type->byref)
            return reinterpret_cast<intptr_t>(empty_gptr_array());

        bool ignoreCase = listType == MLISTTYPE_CaseInsensitive;

        const char *utf8_name = reinterpret_cast<const char*>(name);
        PropertyPairVector properties = GetPropertiesByName(type, utf8_name, bindingAttr, ignoreCase, type);

        MonoGPtrArray* res_array = gptr_array_of_size(properties.size());

        for (unsigned int i = 0; i < properties.size(); i++)
            res_array->pdata[i] = const_cast<PropertyInfo*>(properties[i].property);

        return reinterpret_cast<intptr_t>(res_array);
    }

    Il2CppObject* RuntimeType::CreateInstanceInternal(Il2CppQCallTypeHandle type)
    {
        Il2CppClass* typeInfo = vm::Class::FromIl2CppType(type);

        if (typeInfo == NULL || il2cpp::vm::Class::IsNullable(typeInfo))
            return NULL;

        il2cpp::vm::Class::Init(typeInfo);

        // You could think "hey, shouldn't we call the constructor here?" but we don't because this path is only hit for value
        // types, and they cannot have default constructors.  for reference types with constructors, the c# side of CreateInstance()
        // actually takes care of its own business by using reflection to create the object and invoke the constructor.
        return il2cpp_object_new(typeInfo);
    }

    Il2CppObject* RuntimeType::GetCorrespondingInflatedMethod(Il2CppQCallTypeHandle type, Il2CppObject* generic)
    {
        NOT_SUPPORTED_IL2CPP(MonoType::GetCorrespondingInflatedMethod, "This icall is only used by System.Reflection.Emit.TypeBuilder.");
        return 0;
    }

    Il2CppArray* RuntimeType::GetFunctionPointerTypeModifiers(Il2CppQCallTypeHandle type, int32_t position, bool optional)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(RuntimeType::GetFunctionPointerTypeModifiers);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    void RuntimeType::AllocateValueType(Il2CppQCallTypeHandle type, Il2CppObject* value, Il2CppObjectHandleOnStack res)
    {
        // If the source value null allocate a new empty object
        // Otherwise we make a copy of the source value - this is basically a boxing operation
        IL2CPP_ASSERT(il2cpp::vm::Type::IsValueType(type));

        Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
        if (il2cpp::vm::Class::IsNullable(klass))
        {
            res = vm::Object::NewBoxedNullable(klass);
            if (value != NULL)
                vm::Object::NullableInit(reinterpret_cast<uint8_t*>(vm::Object::GetRawData(res)), value, klass);
        }
        else
        {
            if (value == nullptr)
                res = vm::Object::New(klass);
            else
                res = vm::Object::Box(klass, il2cpp::vm::Object::GetRawData(value));
        }
    }

    void RuntimeType::GetDeclaringMethod(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        const MethodInfo* declaringMethod = vm::Type::GetDeclaringMethod(type);
        res = declaringMethod == NULL ? (Il2CppObject*)NULL : (Il2CppObject*)il2cpp::vm::Reflection::GetMethodObject(declaringMethod, NULL);
    }

    void RuntimeType::GetDeclaringType(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* declaringClass = vm::Type::GetDeclaringType(type);
        Il2CppObject* declaringType = declaringClass ? (Il2CppObject*)il2cpp::vm::Reflection::GetTypeObject(declaringClass) : NULL;
        res = declaringType;
    }

    void RuntimeType::GetGenericArgumentsInternal(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res, bool runtimeArray)
    {
        res = vm::Type::GetGenericArgumentsInternal(type, runtimeArray);
    }

    void RuntimeType::GetInterfaceMapData(Il2CppQCallTypeHandle t, Il2CppQCallTypeHandle iface, Il2CppArray** targets, Il2CppArray** methods)
    {
        Il2CppClass* klass = il2cpp_class_from_il2cpp_type(t);
        Il2CppClass* iklass = il2cpp_class_from_il2cpp_type(iface);

        void* iter = NULL;

        int32_t numberOfMethods = (int32_t)vm::Class::GetNumMethods(iklass);
        int32_t numberOfVirtualMethods = 0;
        for (int i = 0; i < numberOfMethods; ++i)
        {
            const MethodInfo* method = il2cpp_class_get_methods(iklass, &iter);
            if (method->flags & METHOD_ATTRIBUTE_VIRTUAL)
                numberOfVirtualMethods++;
        }


        *targets = il2cpp_array_new(il2cpp_defaults.method_info_class, numberOfVirtualMethods);
        *methods = il2cpp_array_new(il2cpp_defaults.method_info_class, numberOfVirtualMethods);

        if (numberOfVirtualMethods == 0)
            return;

        vm::Class::Init(klass);
        const VirtualInvokeData* invokeDataStart;

        // So this part is tricky. GetInterfaceInvokeDataFromVTable takes an object pointer in order to support
        // COM peculiarities, like being able to return invoke data for an interface only if native side implements it
        // So here we create a fake object of the class we want to query and pass that to GetInterfaceInvokeDataFromVTable
        // It is safe because the only fields GetInterfaceInvokeDataFromVTable accesses are the klass and identity fields
        if (!klass->is_import_or_windows_runtime)
        {
            Il2CppObject fakeObject = {};
            fakeObject.klass = klass;
            invokeDataStart = &vm::ClassInlines::GetInterfaceInvokeDataFromVTable(&fakeObject, iklass, 0);
        }
        else
        {
            Il2CppComObject fakeComObject;
            memset(&fakeComObject, 0, sizeof(fakeComObject));
            fakeComObject.klass = klass;

            // This makes GetInterfaceInvokeDataFromVTable believe that the COM object is dead,
            // thus making it skip asking native side whether a particular interface is supported
            fakeComObject.identity = NULL;

            invokeDataStart = &vm::ClassInlines::GetInterfaceInvokeDataFromVTable(&fakeComObject, iklass, 0);
        }

        iter = NULL;
        int virtualMethodIndex = 0;
        for (int i = 0; i < numberOfMethods; ++i)
        {
            const MethodInfo* method = il2cpp_class_get_methods(iklass, &iter);
            if (method->flags & METHOD_ATTRIBUTE_VIRTUAL)
            {
                Il2CppReflectionMethod* member = il2cpp_method_get_object(method, iklass);
                il2cpp_array_setref(*methods, virtualMethodIndex, member);

                const MethodInfo* targetMethod = invokeDataStart[i].method;

                if (vm::Method::IsAmbiguousMethodInfo(targetMethod) || vm::Method::IsEntryPointNotFoundMethodInfo(targetMethod))
                {
                    // Method is an ambiguous default interface method (more than one DIM matched)
                    // Or there is no valid method in this slot
                    member = NULL;
                }
                else if (vm::Class::IsInterface(targetMethod->klass))
                {
                    // We found a default interface method
                    if (targetMethod->flags & METHOD_ATTRIBUTE_ABSTRACT)
                    {
                        // The method was re-abstracted
                        member = NULL;
                    }
                    else
                    {
                        // Normal DIM case
                        member = il2cpp_method_get_object(targetMethod, targetMethod->klass);
                    }
                }
                else
                {
                    // Normal interface implementation
                    member = il2cpp_method_get_object(targetMethod, klass);
                }
                il2cpp_array_setref(*targets, virtualMethodIndex, member);
                virtualMethodIndex++;
            }
        }
    }

    void RuntimeType::GetInterfaces(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* klass = vm::Class::FromIl2CppType(type);
        typedef std::set<Il2CppClass*> InterfaceVector;
        InterfaceVector itfs;

        Il2CppClass* currentType = klass;
        while (currentType != NULL)
        {
            void* iter = NULL;
            while (Il2CppClass* itf = vm::Class::GetInterfaces(currentType, &iter))
                itfs.insert(itf);

            currentType = vm::Class::GetParent(currentType);
        }

        Il2CppArray* arr = vm::Array::New(il2cpp_defaults.systemtype_class, (il2cpp_array_size_t)itfs.size());
        int i = 0;
        for (InterfaceVector::const_iterator iter = itfs.begin(); iter != itfs.end(); ++iter, ++i)
            il2cpp_array_setref(arr, i, vm::Reflection::GetTypeObject(&(*iter)->byval_arg));

        res = arr;
    }

    void RuntimeType::GetName(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        const char* name = vm::Class::GetName(vm::Class::FromIl2CppType(type));
        if (type->byref)
        {
            size_t len = strlen(name);
            std::string refName;
            refName.reserve(len + 1);
            refName.append(name, len),
            refName.append("&", 1);
            res = vm::String::NewLen(refName.c_str(), (uint32_t)refName.size());
        }
        else
        {
            res = vm::String::New(name);
        }
    }

    void RuntimeType::GetNamespace(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* klass = vm::Class::FromIl2CppType(type);
        while (klass->declaringType)
            klass = klass->declaringType;

        const char* ns = vm::Class::GetNamespace(klass);
        if (ns[0] == '\0')
            res = (Il2CppObject*)NULL;
        else
            res = (Il2CppObject*)vm::String::New(ns);
    }

    void RuntimeType::GetPacking(Il2CppQCallTypeHandle type, int32_t* packing, int32_t* size)
    {
        const Il2CppType* runtimeType = vm::Type::IsGenericInstance(type) ? vm::Type::GetGenericTypeDefinition(type) : type;
        Il2CppMetadataTypeHandle handle = il2cpp::vm::MetadataCache::GetTypeHandleFromType(runtimeType);

        if (vm::MetadataCache::StructLayoutPackIsDefault(handle))
            *packing = 8;
        else
            *packing = vm::MetadataCache::StructLayoutPack(handle);

        if (vm::MetadataCache::StructLayoutSizeIsDefault(handle))
            *size = 0;
        else
            *size = vm::Class::FromIl2CppType(runtimeType)->native_size;
    }

    void RuntimeType::MakeGenericType(Il2CppReflectionType* gt, Il2CppArray* genericArgumentTypes, Il2CppObjectHandleOnStack res)
    {
        const Il2CppType* genericTypeDefinitionType = gt->type;
        Il2CppClass* genericTypeDefinitionClass = vm::Class::FromIl2CppType(genericTypeDefinitionType);
        IL2CPP_ASSERT(vm::Class::IsGeneric(genericTypeDefinitionClass));

        uint32_t arrayLength = vm::Array::GetLength(genericArgumentTypes);
        const Il2CppType** genericArguments = (const Il2CppType**)alloca(arrayLength * sizeof(Il2CppType*));

        for (uint32_t i = 0; i < arrayLength; i++)
        {
            Il2CppReflectionType* genericArgumentType = il2cpp_array_get(genericArgumentTypes, Il2CppReflectionType*, i);
            genericArguments[i] = genericArgumentType->type;
        }

        const Il2CppGenericInst* inst = vm::MetadataCache::GetGenericInst(genericArguments, arrayLength);
        Il2CppGenericClass* genericClass = metadata::GenericMetadata::GetGenericClass(genericTypeDefinitionClass, inst);
        Il2CppClass* genericInstanceTypeClass = vm::GenericClass::GetClass(genericClass);

        if (!genericInstanceTypeClass)
        {
            vm::Exception::Raise(vm::Exception::GetNotSupportedException(FormatExceptionMessageForNonConstructableGenericType(genericTypeDefinitionType, genericArguments, arrayLength).c_str()));
            res = nullptr;
        }
        else
        {
            res = (Il2CppObject*)vm::Reflection::GetTypeObject(&genericInstanceTypeClass->byval_arg);
        }
    }

    void RuntimeType::getFullName(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res, bool full_name, bool assembly_qualified)
    {
        Il2CppTypeNameFormat format;

        if (full_name)
            format = assembly_qualified ?
                IL2CPP_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED :
                IL2CPP_TYPE_NAME_FORMAT_FULL_NAME;
        else
            format = IL2CPP_TYPE_NAME_FORMAT_REFLECTION;

        std::string name(vm::Type::GetName(type, format));
        if (name.empty())
        {
            res = nullptr;
        }
        else if (full_name && (type->type == IL2CPP_TYPE_VAR || type->type == IL2CPP_TYPE_MVAR))
        {
            res = nullptr;
        }
        else
        {
            res = (Il2CppObject*)il2cpp::vm::String::NewWrapper(name.c_str());
        }
    }

    void validate_make_array_type_inputs(Il2CppReflectionType* type, int32_t rank)
    {
        // Per MSDN: http://msdn.microsoft.com/en-us/library/w0ykk2sw(v=vs.110).aspx
        if (rank > 32)
        {
            std::string message;
            message = vm::Type::GetName(type->type, IL2CPP_TYPE_NAME_FORMAT_FULL_NAME) + " with rank " + utils::StringUtils::Printf("%d", rank) + " has too many dimensions.";
            il2cpp_raise_exception(vm::Exception::GetTypeLoadException(message.c_str()));
        }

        if (type->type->byref)
        {
            std::string message;
            message = "Could not create array type '" + vm::Type::GetName(type->type, IL2CPP_TYPE_NAME_FORMAT_FULL_NAME) + "'.";
            il2cpp_raise_exception(vm::Exception::GetTypeLoadException(message.c_str()));
        }

        const Il2CppClass* klass = vm::Class::FromIl2CppType(type->type);

        if (klass == il2cpp_defaults.typed_reference_class)
        {
            std::string message;
            message + "Could not create array type '" + klass->namespaze + "." + klass->name + "[]'.";
            il2cpp_raise_exception(vm::Exception::GetTypeLoadException(message.c_str()));
        }
    }

    void RuntimeType::make_array_type(Il2CppQCallTypeHandle type, int32_t rank, Il2CppObjectHandleOnStack res)
    {
        validate_make_array_type_inputs(type, rank);

        Il2CppClass* arrayClass;

        Il2CppClass* klass = il2cpp_class_from_il2cpp_type(type);
        if (rank == 0) //single dimentional array
            arrayClass = il2cpp_array_class_get(klass, 1);
        else
            arrayClass = il2cpp_bounded_array_class_get(klass, rank, true);

        res = (Il2CppObject*)(arrayClass != NULL ? vm::Reflection::GetTypeObject(&arrayClass->byval_arg) : NULL);
    }

    void RuntimeType::make_byref_type(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type);
        res = (Il2CppObject*)il2cpp::vm::Reflection::GetTypeObject(il2cpp::vm::Class::GetByrefType(klass));
    }

    void RuntimeType::make_pointer_type(Il2CppQCallTypeHandle type, Il2CppObjectHandleOnStack res)
    {
        Il2CppClass* pointerClass = il2cpp::vm::Class::GetPtrClass(type);
        res = (Il2CppObject*)il2cpp::vm::Reflection::GetTypeObject(pointerClass);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
