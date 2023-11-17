#include "il2cpp-config.h"
#include "il2cpp-runtime-stats.h"
#include "os/Mutex.h"
#include "vm/Class.h"
#include "vm/GenericClass.h"
#include "vm/Image.h"
#include "vm/Runtime.h"
#include "vm/Type.h"
#include "metadata/GenericMetadata.h"
#include "metadata/GenericMethod.h"
#include "metadata/Il2CppGenericClassHash.h"
#include "metadata/Il2CppGenericClassCompare.h"
#include "metadata/Il2CppGenericInstCompare.h"
#include "metadata/Il2CppGenericInstHash.h"
#include "metadata/Il2CppTypeCompare.h"
#include "metadata/Il2CppTypeHash.h"
#include "utils/Memory.h"
#include "utils/Il2CppHashMap.h"
#include "utils/Il2CppHashSet.h"
#include "utils/StringUtils.h"
#include "vm/MetadataAlloc.h"
#include "vm/MetadataCache.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-tabledefs.h"
#include <vector>

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"

#include "hybridclr/metadata/MetadataUtil.h"

using namespace il2cpp::vm;
using il2cpp::metadata::GenericMethod;
using il2cpp::os::FastAutoLock;
using il2cpp::utils::StringUtils;

using std::vector;
using std::pair;

namespace il2cpp
{
namespace metadata
{
    const Il2CppType** GenericMetadata::InflateParameters(const Il2CppType** parameters, uint8_t parameterCount, const Il2CppGenericContext* context, bool inflateMethodVars)
    {
        const Il2CppType** inflatedParameters = (const Il2CppType**)MetadataCalloc(parameterCount, sizeof(Il2CppType*));

        for (uint8_t j = 0; j < parameterCount; j++)
        {
            inflatedParameters[j] = InflateIfNeeded(parameters[j], context, inflateMethodVars);
        }

        return inflatedParameters;
    }

    static const Il2CppType* InflateGenericParameterIfNeeded(const Il2CppType* type, const Il2CppGenericInst* inst)
    {
        IL2CPP_ASSERT(inst);

        Il2CppGenericParameterInfo gp = Type::GetGenericParameterInfo(type);
        IL2CPP_ASSERT(gp.num < inst->type_argc);

        const Il2CppType* genericArgument = inst->type_argv[gp.num];
        if (genericArgument->attrs == type->attrs && genericArgument->byref == type->byref)
            return genericArgument;

        Il2CppType* inflatedType = (Il2CppType*)MetadataMalloc(sizeof(Il2CppType));
        memcpy(inflatedType,  genericArgument, sizeof(Il2CppType));
        inflatedType->byref = type->byref;
        inflatedType->attrs = type->attrs;

        ++il2cpp_runtime_stats.inflated_type_count;

        return inflatedType;
    }

    const Il2CppType* GenericMetadata::InflateIfNeeded(const Il2CppType* type, const Il2CppGenericContext* context, bool inflateMethodVars)
    {
        switch (type->type)
        {
            case IL2CPP_TYPE_VAR:
                return InflateGenericParameterIfNeeded(type, context->class_inst);
            case IL2CPP_TYPE_MVAR:
            {
                if (context->method_inst)
                    return InflateGenericParameterIfNeeded(type, context->method_inst);
                return type;
            }
            case IL2CPP_TYPE_ARRAY:
            {
                const Il2CppType* inflatedElementType = InflateIfNeeded(type->data.array->etype, context, inflateMethodVars);
                if (!Il2CppTypeEqualityComparer::AreEqual(inflatedElementType, type->data.array->etype))
                {
                    Il2CppType* inflatedType = (Il2CppType*)MetadataMalloc(sizeof(Il2CppType));
                    memcpy(inflatedType, type, sizeof(Il2CppType));

                    Il2CppArrayType* arrayType = (Il2CppArrayType*)MetadataMalloc(sizeof(Il2CppArrayType));
                    memcpy(arrayType, type->data.array, sizeof(Il2CppArrayType));
                    arrayType->etype = inflatedElementType;
                    inflatedType->data.array = arrayType;

                    ++il2cpp_runtime_stats.inflated_type_count;

                    return inflatedType;
                }
                return type;
            }
            case IL2CPP_TYPE_PTR:
            case IL2CPP_TYPE_SZARRAY:
            {
                const Il2CppType* inflatedElementType = InflateIfNeeded(type->data.type, context, inflateMethodVars);
                if (!Il2CppTypeEqualityComparer::AreEqual(inflatedElementType, type->data.type))
                {
                    Il2CppType* arrayType = (Il2CppType*)MetadataMalloc(sizeof(Il2CppType));
                    memcpy(arrayType, type, sizeof(Il2CppType));
                    arrayType->data.type = inflatedElementType;

                    ++il2cpp_runtime_stats.inflated_type_count;

                    return arrayType;
                }
                return type;
            }
            case IL2CPP_TYPE_GENERICINST:
            {
                const Il2CppGenericInst* inst = type->data.generic_class->context.class_inst;
                if (inst == NULL)
                    return NULL; // This is a generic type that was too deeply nested to generate

                const Il2CppGenericInst* inflatedInst = GetInflatedGenericIntance(inst, context, inflateMethodVars);
                Il2CppGenericClass* genericClass = GenericMetadata::GetGenericClass(type->data.generic_class->type, inflatedInst);
                if (genericClass != type->data.generic_class)
                {
                    Il2CppType* genericType = (Il2CppType*)MetadataMalloc(sizeof(Il2CppType));
                    memcpy(genericType, type, sizeof(Il2CppType));
                    genericType->data.generic_class = genericClass;

                    ++il2cpp_runtime_stats.inflated_type_count;

                    return genericType;
                }

                return type;
            }
            default:
                return type;
        }
    }

    static baselib::ReentrantLock s_GenericClassMutex;
    typedef Il2CppHashSet<Il2CppGenericClass*, Il2CppGenericClassHash, Il2CppGenericClassCompare> Il2CppGenericClassSet;
    static Il2CppGenericClassSet s_GenericClassSet;


    Il2CppGenericClass* GenericMetadata::GetGenericClass(const Il2CppClass* genericTypeDefinition, const Il2CppGenericInst* inst)
    {
        return GetGenericClass(&genericTypeDefinition->byval_arg, inst);
    }

    Il2CppGenericClass* GenericMetadata::GetGenericClass(const Il2CppType* genericTypeDefinition, const Il2CppGenericInst* inst)
    {
        // Assert that the element type is a non-inflated generic type defintion
        IL2CPP_ASSERT(genericTypeDefinition->type == IL2CPP_TYPE_CLASS || genericTypeDefinition->type == IL2CPP_TYPE_VALUETYPE);

        // temporary inst to lookup a permanent one that may already exist
        Il2CppGenericClass genericClass = { 0 };
        genericClass.type = genericTypeDefinition;
        genericClass.context.class_inst = inst;

        FastAutoLock lock(&s_GenericClassMutex);
        Il2CppGenericClassSet::const_iterator iter = s_GenericClassSet.find(&genericClass);
        if (iter != s_GenericClassSet.end())
            return *iter;

        Il2CppGenericClass* newClass = MetadataAllocGenericClass();
        newClass->type = genericTypeDefinition;
        newClass->context.class_inst = inst;

        s_GenericClassSet.insert(newClass);

        ++il2cpp_runtime_stats.generic_class_count;

        return newClass;
    }

    const MethodInfo* GenericMetadata::Inflate(const MethodInfo* methodDefinition, const Il2CppGenericContext* context)
    {
        return GenericMethod::GetMethod(methodDefinition, context->class_inst, context->method_inst);
    }

    static int RecursiveGenericDepthFor(const Il2CppGenericInst* inst);

    static int RecursiveGenericDepthFor(Il2CppGenericClass* genericClass)
    {
        int classInstDepth = RecursiveGenericDepthFor(genericClass->context.class_inst);
        int methodInstDepth = RecursiveGenericDepthFor(genericClass->context.method_inst);
        return std::max(classInstDepth, methodInstDepth);
    }

    static int RecursiveGenericDepthFor(const Il2CppGenericInst* inst)
    {
        if (inst == NULL)
            return 0;

        int maximumDepth = 0;
        for (size_t i = 0; i < inst->type_argc; i++)
        {
            if (inst->type_argv[i]->type == IL2CPP_TYPE_GENERICINST)
            {
                maximumDepth = std::max(maximumDepth, RecursiveGenericDepthFor(inst->type_argv[i]->data.generic_class));
            }
        }

        return maximumDepth + 1;
    }

    const Il2CppGenericMethod* GenericMetadata::Inflate(const Il2CppGenericMethod* genericMethod, const Il2CppGenericContext* context)
    {
        const Il2CppGenericInst* classInst = GetInflatedGenericIntance(genericMethod->context.class_inst, context, true);
        const Il2CppGenericInst* methodInst = GetInflatedGenericIntance(genericMethod->context.method_inst, context, true);

        // We have cases where we could infinitely recurse, inflating generics at runtime. This will lead to a stack overflow.
        // As we do for code generation, let's cut this off at an arbitrary level. If something tries to execute code at this
        // level, a crash will happen. We'll assume that this code won't actually be executed though.
        int maximumRuntimeGenericDepth = GetMaximumRuntimeGenericDepth();
        if (!il2cpp::vm::Runtime::IsLazyRGCTXInflationEnabled() && (RecursiveGenericDepthFor(classInst) > maximumRuntimeGenericDepth || RecursiveGenericDepthFor(methodInst) > maximumRuntimeGenericDepth))
            return NULL;

        return MetadataCache::GetGenericMethod(genericMethod->methodDefinition, classInst, methodInst);
    }

    const Il2CppGenericInst* GenericMetadata::GetInflatedGenericIntance(const Il2CppGenericInst* inst, const Il2CppGenericContext* context, bool inflateMethodVars)
    {
        if (inst == NULL)
            return NULL;

        const Il2CppType** inflatedArgs = (const Il2CppType**)alloca(inst->type_argc * sizeof(Il2CppType*));
        for (size_t i = 0; i < inst->type_argc; i++)
            inflatedArgs[i] = InflateIfNeeded(inst->type_argv[i], context, inflateMethodVars);
        return MetadataCache::GetGenericInst(inflatedArgs, inst->type_argc);
    }

    static void ConstrainedCallsToGenericInterfaceMethodsOnStructsAreNotSupported()
    {
        vm::Exception::Raise(vm::Exception::GetNotSupportedException("Cannot make a constrained call to a default interface method from a value type"));
    }

    static void ConstrainedCallsToGenericInterfaceMethodsOnStructsAreNotSupportedInvoker(Il2CppMethodPointer ptr, const MethodInfo* method, void* obj, void** args, void* ret)
    {
        ConstrainedCallsToGenericInterfaceMethodsOnStructsAreNotSupported();
    }

    Il2CppRGCTXData* GenericMetadata::InflateRGCTXLocked(const Il2CppImage* image, uint32_t token, const Il2CppGenericContext* context, const FastAutoLock& lock)
    {
        // This method assumes that it has the g_MetadataLock
        if (hybridclr::metadata::IsInterpreterImage(image))
        {
            return nullptr;
        }

        RGCTXCollection collection = MetadataCache::GetRGCTXs(image, token);
        if (collection.count == 0)
            return NULL;

        Il2CppRGCTXData* dataValues = (Il2CppRGCTXData*)MetadataCalloc(collection.count, sizeof(Il2CppRGCTXData));
        for (RGCTXIndex rgctxIndex = 0; rgctxIndex < collection.count; rgctxIndex++)
        {
            const Il2CppRGCTXDefinition* definitionData = collection.items + rgctxIndex;
            switch (definitionData->type)
            {
                case IL2CPP_RGCTX_DATA_TYPE:
                    dataValues[rgctxIndex].type = GenericMetadata::InflateIfNeeded(MetadataCache::GetTypeFromRgctxDefinition(definitionData), context, true);
                    break;
                case IL2CPP_RGCTX_DATA_CLASS:
                    dataValues[rgctxIndex].klass = Class::FromIl2CppType(GenericMetadata::InflateIfNeeded(MetadataCache::GetTypeFromRgctxDefinition(definitionData), context, true));
                    Class::InitSizeAndFieldLayoutLocked(dataValues[rgctxIndex].klass, lock);
                    break;
                case IL2CPP_RGCTX_DATA_METHOD:
                    dataValues[rgctxIndex].method = GenericMethod::GetMethod(Inflate(MetadataCache::GetGenericMethodFromRgctxDefinition(definitionData), context));
                    break;
                case IL2CPP_RGCTX_DATA_CONSTRAINED:
                {
                    const Il2CppType* type;
                    const MethodInfo* method;
                    std::tie(type, method) = MetadataCache::GetConstrainedCallFromRgctxDefinition(definitionData);

                    const Il2CppType* inflatedType = GenericMetadata::InflateIfNeeded(type, context, true);
                    if (method->is_inflated)
                        method = GenericMethod::GetMethod(Inflate(method->genericMethod, context));

                    if (inflatedType->valuetype)
                    {
                        Il2CppClass* inflatedClass = Class::FromIl2CppType(inflatedType);
                        Class::InitLocked(inflatedClass, lock);
                        Class::InitLocked(method->klass, lock);
                        method = Class::GetVirtualMethod(inflatedClass, method);
                    }

                    dataValues[rgctxIndex].method = method;
                }
                break;
                default:
                    IL2CPP_ASSERT(0);
            }
        }

        return dataValues;
    }

// temporary while we generate generics
    void GenericMetadata::RegisterGenericClasses(Il2CppGenericClass* const * genericClasses, int32_t genericClassesCount)
    {
        s_GenericClassSet.resize(genericClassesCount / 2 + 1);

        // don't lock, this should only be called from startup and temporarily
        for (int32_t i = 0; i < genericClassesCount; i++)
        {
            if (genericClasses[i]->type != NULL)
                s_GenericClassSet.insert(genericClasses[i]);
        }
    }

    bool GenericMetadata::ContainsGenericParameters(const Il2CppClass* klass)
    {
        if (!klass->generic_class)
            return false;

        return ContainsGenericParameters(klass->generic_class->context.class_inst);
    }

    bool GenericMetadata::ContainsGenericParameters(const MethodInfo* method)
    {
        if (!method->is_inflated)
            return false;

        if (ContainsGenericParameters(method->genericMethod->context.method_inst))
            return true;
        if (method->genericMethod->context.class_inst == NULL)
            return false;
        return ContainsGenericParameters(method->genericMethod->context.class_inst);
    }

    bool GenericMetadata::ContainsGenericParameters(const Il2CppGenericInst* inst)
    {
        for (uint32_t i = 0; i < inst->type_argc; i++)
        {
            if (ContainsGenericParameters(inst->type_argv[i]))
                return true;
        }

        return false;
    }

    bool GenericMetadata::ContainsGenericParameters(const Il2CppType* type)
    {
        switch (type->type)
        {
            case IL2CPP_TYPE_VAR:
            case IL2CPP_TYPE_MVAR:
                return true;
            case IL2CPP_TYPE_GENERICINST:
                return ContainsGenericParameters(type->data.generic_class->context.class_inst);
            case IL2CPP_TYPE_ARRAY:
                return ContainsGenericParameters(type->data.array->etype);
            case IL2CPP_TYPE_SZARRAY:
            case IL2CPP_TYPE_PTR:
            case IL2CPP_TYPE_BYREF:
                return ContainsGenericParameters(type->data.type);
            default:
                return false;
        }

        return false;
    }

    void GenericMetadata::WalkAllGenericClasses(GenericClassWalkCallback callback, void* context)
    {
        FastAutoLock lock(&s_GenericClassMutex);

        for (Il2CppGenericClassSet::iterator it = s_GenericClassSet.begin(); it != s_GenericClassSet.end(); it++)
        {
            if ((*it).key->cached_class != NULL)
                callback((*it).key->cached_class, context);
        }
    }

    void GenericMetadata::Clear()
    {
        for (Il2CppGenericClassSet::iterator genericClass = s_GenericClassSet.begin(); genericClass != s_GenericClassSet.end(); genericClass++)
            (*genericClass).key->cached_class = NULL;
        s_GenericClassSet.clear();
    }

    static int s_MaximumRuntimeGenericDepth;
    static int s_GenericVirtualIterations;

    int GenericMetadata::GetMaximumRuntimeGenericDepth()
    {
        return s_MaximumRuntimeGenericDepth;
    }

    void GenericMetadata::SetMaximumRuntimeGenericDepth(int depth)
    {
        s_MaximumRuntimeGenericDepth = depth;
    }

    int GenericMetadata::GetGenericVirtualIterations()
    {
        return s_GenericVirtualIterations;
    }

    void GenericMetadata::SetGenericVirtualIterations(int iterations)
    {
        s_GenericVirtualIterations = iterations;
    }
} /* namespace vm */
} /* namespace il2cpp */
