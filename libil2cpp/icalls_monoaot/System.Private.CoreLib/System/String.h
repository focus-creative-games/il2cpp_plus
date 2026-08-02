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
    class LIBIL2CPP_CODEGEN_API String
    {
    public:
        static Il2CppString* FastAllocateString(int32_t length);
        static Il2CppString* InternalIntern(Il2CppString* str);
        static Il2CppString* InternalIsInterned(Il2CppString* str);
        static void ctor(Il2CppString* thisPtr, Il2CppChar* value);
        static void ctor(Il2CppString* thisPtr, Il2CppChar* value, int32_t startIndex, int32_t length);
        static void ctor(Il2CppString* thisPtr, Il2CppChar c, int32_t count);
        static void ctor(Il2CppString* thisPtr, Il2CppArray* value);
        static void ctor(Il2CppString* thisPtr, Il2CppArray* value, int32_t startIndex, int32_t length);
        static void ctor(Il2CppString* thisPtr, void* value);
        static void ctor(Il2CppString* thisPtr, int8_t* value);
        static void ctor(Il2CppString* thisPtr, int8_t* value, int32_t startIndex, int32_t length);
        static void ctor(Il2CppString* thisPtr, int8_t* value, int32_t startIndex, int32_t length, Il2CppObject* enc);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
