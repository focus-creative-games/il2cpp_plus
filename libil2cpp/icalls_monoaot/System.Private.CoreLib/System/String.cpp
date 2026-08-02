#include "il2cpp-config.h"
#include "String.h"

#include "il2cpp-api.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Exception.h"
#include "vm/String.h"
#include <memory>

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
    Il2CppString* String::FastAllocateString(int32_t length)
    {
        return vm::String::NewSize(length);
    }

    Il2CppString* String::InternalIntern(Il2CppString* str)
    {
        return il2cpp_string_intern(str);
    }

    Il2CppString* String::InternalIsInterned(Il2CppString* str)
    {
        return il2cpp_string_is_interned(str);
    }

    void String::ctor(Il2CppString* thisPtr, Il2CppChar* value)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, Il2CppChar* value, int32_t startIndex, int32_t length)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, Il2CppChar c, int32_t count)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, Il2CppArray* value)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, Il2CppArray* value, int32_t startIndex, int32_t length)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, void* value)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, int8_t* value)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, int8_t* value, int32_t startIndex, int32_t length)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }

    void String::ctor(Il2CppString* thisPtr, int8_t* value, int32_t startIndex, int32_t length, Il2CppObject* enc)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(String::ctor);
        IL2CPP_UNREACHABLE;
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
