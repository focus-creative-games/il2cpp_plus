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
namespace Reflection
{
    class LIBIL2CPP_CODEGEN_API RuntimeFieldInfo
    {
    public:
        static int32_t GetFieldOffset(Il2CppReflectionField* thisPtr);
        static int32_t get_metadata_token(Il2CppReflectionField* monoField);
        static Il2CppObject* GetRawConstantValue(Il2CppReflectionField* thisPtr);
        static Il2CppObject* GetValueInternal(Il2CppReflectionField* thisPtr, Il2CppObject* obj);
        static Il2CppReflectionType* GetParentType(Il2CppReflectionField* thisPtr, bool declaring);
        static Il2CppObject* ResolveType(Il2CppReflectionField* thisPtr);
        static Il2CppArray* GetTypeModifiers(Il2CppReflectionField* thisPtr, bool optional, int32_t genericArgumentPosition);
        static void SetValueInternal(Il2CppReflectionField* fi, Il2CppObject* obj, Il2CppObject* value);
    };
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
