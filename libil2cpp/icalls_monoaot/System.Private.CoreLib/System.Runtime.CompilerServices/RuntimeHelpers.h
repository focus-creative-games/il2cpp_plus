#pragma once

#include "il2cpp-object-internals.h"
#include "il2cpp-class-internals.h"
#include "mono-structs.h"

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
    class LIBIL2CPP_CODEGEN_API RuntimeHelpers
    {
    public:
        static bool SufficientExecutionStack();
        static int32_t InternalGetHashCode(Il2CppObject* o);
        static int32_t InternalTryGetHashCode(Il2CppObject* o);
        static void* GetSpanDataFrom(FieldInfo* fldHandle, Il2CppType* targetTypeHandle, int32_t* count);
        static Il2CppObject* GetObjectValue(Il2CppObject* obj);
        static Il2CppObject* GetUninitializedObjectInternal(intptr_t type);
        static void InitializeArray(Il2CppArray* array, intptr_t fldHandle);
        static void PrepareMethod(intptr_t method, intptr_t* instantiations, int32_t ninst);
        static void RunClassConstructor(intptr_t type);
        static void RunModuleConstructor(intptr_t module);
    };
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
