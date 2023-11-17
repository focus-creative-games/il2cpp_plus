#pragma once

#include <stdint.h>
#include "il2cpp-config.h"
#include "il2cpp-object-internals.h"

struct Il2CppObject;
struct Il2CppDelegate;
struct Il2CppReflectionType;
struct Il2CppReflectionMethod;
struct Il2CppReflectionField;
struct Il2CppArray;
struct Il2CppException;
struct Il2CppReflectionModule;
struct Il2CppAssembly;
struct Il2CppAssemblyName;
struct Il2CppAppDomain;

namespace il2cpp
{
namespace icalls
{
namespace mscorlib
{
namespace System
{
    class LIBIL2CPP_CODEGEN_API TypedReference
    {
    public:
        static Il2CppObject* InternalToObject(Il2CppTypedRef* value);
        static void InternalMakeTypedReference(Il2CppTypedRef* res, Il2CppObject* target, Il2CppArray* flds, Il2CppReflectionRuntimeType* lastFieldType);
    };
} /* namespace System */
} /* namespace mscorlib */
} /* namespace icalls */
} /* namespace il2cpp */
