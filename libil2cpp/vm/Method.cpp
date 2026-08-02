#include "il2cpp-config.h"
#include "vm/Method.h"
#include "il2cpp-tabledefs.h"
#include "il2cpp-class-internals.h"
#include "vm/Class.h"
#include "vm/MetadataCache.h"
#include "vm/Object.h"
#include "vm/Method.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/Type.h"

namespace il2cpp
{
namespace vm
{
    const Il2CppType* Method::GetReturnType(const MethodInfo* method)
    {
        return method->return_type;
    }

    Il2CppClass *Method::GetDeclaringType(const MethodInfo* method)
    {
        return method->klass;
    }

    const char* Method::GetName(const MethodInfo *method)
    {
        return method->name;
    }

    std::string Method::GetNameWithGenericTypes(const MethodInfo* method)
    {
        std::string str;

        str += method->name;

        if (method->is_inflated && method->genericMethod->context.method_inst)
        {
            const Il2CppGenericInst *inst = method->genericMethod->context.method_inst;

            str += '<';

            for (unsigned int i = 0; i < inst->type_argc; ++i)
            {
                str += Type::GetName(inst->type_argv[i], IL2CPP_TYPE_NAME_FORMAT_FULL_NAME);
                if (i < inst->type_argc - 1)
                    str += ",";
            }

            str += '>';
        }

        return str;
    }

    bool Method::IsGeneric(const MethodInfo *method)
    {
        return method->is_generic;
    }

    bool Method::IsInflated(const MethodInfo *method)
    {
        return method->is_inflated;
    }

    bool Method::IsGenericInstance(const MethodInfo *method)
    {
        return method->is_inflated && !method->is_generic;
    }

    bool Method::IsGenericInstanceMethod(const MethodInfo *method)
    {
        return method->is_inflated && !method->is_generic && method->genericMethod->context.method_inst;
    }

    bool Method::IsDefaultInterfaceMethodOnGenericInstance(const MethodInfo* method)
    {
        return method->methodPointer && Class::IsInterface(method->klass) && Class::IsInflated(method->klass) && !method->klass->is_import_or_windows_runtime;
    }

    bool Method::IsInstance(const MethodInfo *method)
    {
        return !(method->flags & METHOD_ATTRIBUTE_STATIC);
    }

    bool Method::IsStatic(const MethodInfo *method)
    {
        return method->flags & METHOD_ATTRIBUTE_STATIC;
    }

    bool Method::IsVirtual(const MethodInfo *method)
    {
        return method->flags & METHOD_ATTRIBUTE_VIRTUAL;
    }

    uint32_t Method::GetParamCount(const MethodInfo *method)
    {
        return method->parameters_count;
    }

    uint16_t Method::GetGenericParamCount(const MethodInfo *method)
    {
        if (IsGeneric(method) && method->genericContainerHandle != NULL)
            return MetadataCache::GetGenericContainerCount(method->genericContainerHandle);
        return 0;
    }

    const Il2CppType* Method::GetParam(const MethodInfo *method, uint32_t index)
    {
        if (index < method->parameters_count)
            return method->parameters[index];
        else
            return NULL;
    }

    const char* Method::GetParamName(const MethodInfo *method, uint32_t index)
    {
        IL2CPP_ASSERT(method != NULL && "Method::GetParamName cannot be invoked with a NULL MethodInfo.");

        if (index >= method->parameters_count)
            return NULL;

        if (method->is_inflated)
        {
            method = il2cpp::vm::MetadataCache::GetGenericMethodDefinition(method);
        }

        // we construct some 'pseudo' methods for things like arrays
        if (!method->methodMetadataHandle)
            return NULL;

        Il2CppMetadataParameterInfo paramInfo = MetadataCache::GetParameterInfo(method->klass, method->methodMetadataHandle, index);

        return paramInfo.name;
    }

    Il2CppClass* Method::GetClass(const MethodInfo *method)
    {
        return method->klass;
    }

    bool Method::HasAttribute(const MethodInfo *method, Il2CppClass *attr_class)
    {
        return Reflection::HasAttribute(method, attr_class);
    }

    uint32_t Method::GetImplementationFlags(const MethodInfo *method)
    {
        return method->iflags;
    }

    uint32_t Method::GetFlags(const MethodInfo *method)
    {
        return method->flags;
    }

    uint32_t Method::GetToken(const MethodInfo *method)
    {
        return method->token;
    }

// From ECMA-335, I.10.2 Overloading
// Methods and properties can be overloaded by:
//  * Number of parameters
//  * Type of any parameter
//  * Calling convention <------ not stored in our metadata yet
//  * Custom modifiers   <------ not supported by il2cpp
//  * Whether a parameter is passed by value or by reference
    static bool AreParametersSame(const Il2CppType** params1, const Il2CppType** params2, int count)
    {
        for (int i = 0; i < count; i++)
        {
            const Il2CppType* param1 = params1[i];
            const Il2CppType* param2 = params2[i];

            if (param1->byref != param2->byref)
            {
                return false;
            }

            if (Class::FromIl2CppType(param1) != Class::FromIl2CppType(param2))
            {
                return false;
            }
        }

        return true;
    }

    static int CompareParameters(const Il2CppType** params1, const Il2CppType** params2, int count)
    {
        for (int i = 0; i < count; i++)
        {
            const Il2CppType* param1 = params1[i];
            const Il2CppType* param2 = params2[i];

            if (param1->byref == param2->byref)
            {
                return Class::FromIl2CppType(param1) < Class::FromIl2CppType(param2);
            }

            return param1->byref < param2->byref;
        }

        return true;
    }

    bool Method::IsSameOverloadSignature(const MethodInfo* method1, const MethodInfo* method2)
    {
        if (method1->parameters_count != method2->parameters_count)
        {
            return false;
        }

        return AreParametersSame(method1->parameters, method2->parameters, method1->parameters_count);
    }

    bool Method::IsSameOverloadSignature(const PropertyInfo* property1, const PropertyInfo* property2)
    {
        uint8_t parameterCount1, parameterCount2;
        const Il2CppType** parameters1;
        const Il2CppType** parameters2;

        if (property1->get != NULL)
        {
            parameterCount1 = property1->get->parameters_count;
            parameters1 = property1->get->parameters;
        }
        else
        {
            // In set method, value is the last parameter, so we just don't care about it
            parameterCount1 = property1->set->parameters_count - 1;
            parameters1 = property1->set->parameters;
        }

        if (property2->get != NULL)
        {
            parameterCount2 = property2->get->parameters_count;
            parameters2 = property2->get->parameters;
        }
        else
        {
            parameterCount2 = property2->set->parameters_count - 1;
            parameters2 = property2->set->parameters;
        }

        if (parameterCount1 != parameterCount2)
        {
            return false;
        }

        return AreParametersSame(parameters1, parameters2, parameterCount1);
    }

    int Method::CompareOverloadSignature(const PropertyInfo* property1, const PropertyInfo* property2)
    {
        uint8_t parameterCount1, parameterCount2;
        const Il2CppType** parameters1;
        const Il2CppType** parameters2;

        if (property1->get != NULL)
        {
            parameterCount1 = property1->get->parameters_count;
            parameters1 = property1->get->parameters;
        }
        else
        {
            // In set method, value is the last parameter, so we just don't care about it
            parameterCount1 = property1->set->parameters_count - 1;
            parameters1 = property1->set->parameters;
        }

        if (property2->get != NULL)
        {
            parameterCount2 = property2->get->parameters_count;
            parameters2 = property2->get->parameters;
        }
        else
        {
            parameterCount2 = property2->set->parameters_count - 1;
            parameters2 = property2->set->parameters;
        }

        if (parameterCount1 == parameterCount2)
        {
            return CompareParameters(parameters1, parameters2, parameterCount1);
        }

        return parameterCount1 < parameterCount2;
    }

    const char* Method::GetParameterDefaultValue(const MethodInfo* method, int32_t parameterPosition, const Il2CppType** type, bool* isExplicitlySetNullDefaultValue)
    {
        return reinterpret_cast<const char*>(MetadataCache::GetParameterDefaultValue(method, parameterPosition, type, isExplicitlySetNullDefaultValue));
    }

    uint32_t Method::GetParameterToken(const MethodInfo* method, int32_t index)
    {
        if (index >= method->parameters_count)
            return 0;

        if (method->is_inflated)
        {
            method = il2cpp::vm::MetadataCache::GetGenericMethodDefinition(method);
        }

        // we construct some 'pseudo' methods for things like arrays
        if (!method->methodMetadataHandle)
            return 0;

        // We are looking at the return parameter, which is not stored as a parameter, but the method has its token
        if (index == -1)
        {
            return MetadataCache::GetReturnParameterToken(method->methodMetadataHandle);
        }

        Il2CppMetadataParameterInfo paramInfo = MetadataCache::GetParameterInfo(method->klass, method->methodMetadataHandle, index);

        return paramInfo.token;
    }

    std::string Method::GetFullName(const MethodInfo* method)
    {
        if (IsAmbiguousMethodInfo(method))
            return method->name;
        if (IsEntryPointNotFoundMethodInfo(method))
            return method->name;

        std::string str;
        str += Type::GetName(&method->klass->byval_arg, IL2CPP_TYPE_NAME_FORMAT_FULL_NAME);
        str += "::";
        str += Method::GetNameWithGenericTypes(method);

        return str;
    }

    static void AmbiguousImplementationMethod()
    {
        il2cpp::vm::Runtime::RaiseAmbiguousImplementationException(NULL, NULL);
    }

    static void AmbiguousImplementationMethodInvoker(Il2CppMethodPointer ptr, const MethodInfo* method, void* obj, void** args, void* ret)
    {
        il2cpp::vm::Runtime::RaiseAmbiguousImplementationException(method, NULL);
    }

    static void EntryPointNotFoundImplementationMethod()
    {
        il2cpp::vm::Runtime::RaiseEntryPointNotFoundException(NULL, NULL);
    }

    static void EntryPointNotFoundMethodInvoker(Il2CppMethodPointer ptr, const MethodInfo* method, void* obj, void** args, void* ret)
    {
        il2cpp::vm::Runtime::RaiseEntryPointNotFoundException(method, NULL);
    }

    static Il2CppClass ambiguousMethodClass =
    {
        NULL,                                                   // image
        NULL,                                                   // gc_desc
        "AmbiguousImplementationMethodStubClass",               // name
        ""                                                      // namespaze
    };

    static Il2CppClass entryPointNotFoundClass =
    {
        NULL,                                                   // image
        NULL,                                                   // gc_desc
        "EntryPointNotFoundMethodStubClass",                    // name
        ""                                                      // namespaze
    };

    static MethodInfo ambiguousMethodInfo =
    {
        AmbiguousImplementationMethod,                          // method_ptr
        AmbiguousImplementationMethod,                          // virtual_method_ptr
        AmbiguousImplementationMethodInvoker,                   // invoker_method
        "AmbiguousImplementationMethodStub",                    // name
        &ambiguousMethodClass,                                  // klass
        NULL,                                                   // return_type
        NULL,                                                   // parameters
        NULL,                                                   // methodMetadataHandle
        NULL,                                                   // generic_method
        0,                                                      // token
        METHOD_ATTRIBUTE_ABSTRACT,                              // flags
    };

    static MethodInfo staticAmbiguousMethodInfo =
    {
        AmbiguousImplementationMethod,                          // method_ptr
        AmbiguousImplementationMethod,                          // virtual_method_ptr
        AmbiguousImplementationMethodInvoker,                   // invoker_method
        "AmbiguousImplementationMethodStub",                    // name
        &ambiguousMethodClass,                                  // klass
        NULL,                                                   // return_type
        NULL,                                                   // parameters
        NULL,                                                   // methodMetadataHandle
        NULL,                                                   // generic_method
        0,                                                      // token
        METHOD_ATTRIBUTE_ABSTRACT | METHOD_ATTRIBUTE_STATIC,    // flags
    };

    static MethodInfo entryPointNotFoundMethodInfo =
    {
        EntryPointNotFoundImplementationMethod,                 // method_ptr
        EntryPointNotFoundImplementationMethod,                 // virtual_method_ptr
        EntryPointNotFoundMethodInvoker,                        // invoker_method
        "EntryPointNotFoundMethodStub",                         // name
        &entryPointNotFoundClass,                               // klass
        NULL,                                                   // return_type
        NULL,                                                   // parameters
        NULL,                                                   // methodMetadataHandle
        NULL,                                                   // generic_method
        0,                                                      // token
        METHOD_ATTRIBUTE_ABSTRACT,                              // flags
    };

    static MethodInfo staticEntryPointerNotFoundMethodInfo =
    {
        EntryPointNotFoundImplementationMethod,                 // method_ptr
        EntryPointNotFoundImplementationMethod,                 // virtual_method_ptr
        EntryPointNotFoundMethodInvoker,                        // invoker_method
        "EntryPointNotFoundMethodStub",                         // name
        &entryPointNotFoundClass,                               // klass
        NULL,                                                   // return_type
        NULL,                                                   // parameters
        NULL,                                                   // methodMetadataHandle
        NULL,                                                   // generic_method
        0,                                                      // token
        METHOD_ATTRIBUTE_ABSTRACT | METHOD_ATTRIBUTE_STATIC,    // flags
    };

    const MethodInfo* Method::GetAmbiguousMethodInfo()
    {
        IL2CPP_ASSERT(ambiguousMethodInfo.methodPointer == AmbiguousImplementationMethod);
        IL2CPP_ASSERT(ambiguousMethodInfo.virtualMethodPointer == AmbiguousImplementationMethod);
        IL2CPP_ASSERT(ambiguousMethodInfo.invoker_method == AmbiguousImplementationMethodInvoker);
        IL2CPP_ASSERT(ambiguousMethodInfo.klass == &ambiguousMethodClass);
        IL2CPP_ASSERT(ambiguousMethodInfo.flags == METHOD_ATTRIBUTE_ABSTRACT);

        // GenericMethod::GetMethod relies on ambiguousMethodInfo being a singleton
        return &ambiguousMethodInfo;
    }

    const MethodInfo* Method::GetStaticAmbiguousMethodInfo()
    {
        IL2CPP_ASSERT(staticAmbiguousMethodInfo.methodPointer == AmbiguousImplementationMethod);
        IL2CPP_ASSERT(staticAmbiguousMethodInfo.virtualMethodPointer == AmbiguousImplementationMethod);
        IL2CPP_ASSERT(staticAmbiguousMethodInfo.invoker_method == AmbiguousImplementationMethodInvoker);
        IL2CPP_ASSERT(staticAmbiguousMethodInfo.klass == &ambiguousMethodClass);
        IL2CPP_ASSERT(staticAmbiguousMethodInfo.flags == (METHOD_ATTRIBUTE_ABSTRACT | METHOD_ATTRIBUTE_STATIC));

        // GenericMethod::GetMethod relies on staticAmbiguousMethodInfo being a singleton
        return &staticAmbiguousMethodInfo;
    }

    const MethodInfo* Method::GetEntryPointNotFoundMethodInfo()
    {
        IL2CPP_ASSERT(entryPointNotFoundMethodInfo.methodPointer == EntryPointNotFoundImplementationMethod);
        IL2CPP_ASSERT(entryPointNotFoundMethodInfo.virtualMethodPointer == EntryPointNotFoundImplementationMethod);
        IL2CPP_ASSERT(entryPointNotFoundMethodInfo.invoker_method == EntryPointNotFoundMethodInvoker);
        IL2CPP_ASSERT(entryPointNotFoundMethodInfo.klass == &entryPointNotFoundClass);
        IL2CPP_ASSERT(entryPointNotFoundMethodInfo.flags == METHOD_ATTRIBUTE_ABSTRACT);

        return &entryPointNotFoundMethodInfo;
    }

    const MethodInfo* Method::GetStaticEntryPointNotFoundMethodInfo()
    {
        IL2CPP_ASSERT(staticEntryPointerNotFoundMethodInfo.methodPointer == EntryPointNotFoundImplementationMethod);
        IL2CPP_ASSERT(staticEntryPointerNotFoundMethodInfo.virtualMethodPointer == EntryPointNotFoundImplementationMethod);
        IL2CPP_ASSERT(staticEntryPointerNotFoundMethodInfo.invoker_method == EntryPointNotFoundMethodInvoker);
        IL2CPP_ASSERT(staticEntryPointerNotFoundMethodInfo.klass == &entryPointNotFoundClass);
        IL2CPP_ASSERT(staticEntryPointerNotFoundMethodInfo.flags == (METHOD_ATTRIBUTE_ABSTRACT | METHOD_ATTRIBUTE_STATIC));

        return &staticEntryPointerNotFoundMethodInfo;
    }

    const MethodInfo* Method::GetEntryPointNotFoundMethodInfoForMethod(const MethodInfo* method)
    {
        if (Method::IsStatic(method))
            return Method::GetStaticEntryPointNotFoundMethodInfo();
        else
            return Method::GetEntryPointNotFoundMethodInfo();
    }

    bool Method::IsAmbiguousMethodInfo(const MethodInfo* method)
    {
        return IsAmbiguousMethodClass(method->klass);
    }

    bool Method::IsAmbiguousMethodClass(const Il2CppClass* klass)
    {
        return klass == &ambiguousMethodClass;
    }

    bool Method::IsEntryPointNotFoundMethodInfo(const MethodInfo* method)
    {
        return IsEntryPointNotFoundMethodClass(method->klass);
    }

    bool Method::IsEntryPointNotFoundMethodClass(const Il2CppClass* klass)
    {
        return klass == &entryPointNotFoundClass;
    }

    bool Method::HasFullGenericSharingSignature(const MethodInfo* method)
    {
        return method->has_full_generic_sharing_signature;
    }

    bool Method::RequiresAdjustorThunk(const MethodInfo* method)
    {
        return Method::IsInstance(method) && Class::IsValuetype(method->klass);
    }
} /* namespace vm */
} /* namespace il2cpp */
