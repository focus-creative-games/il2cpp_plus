#pragma once

#include "il2cpp-config.h"

namespace il2cpp
{
namespace vm
{
    class LIBIL2CPP_CODEGEN_API InternalCalls
    {
    public:
        static void Init();
        static void Add(const char* name, Il2CppMethodPointer method);
        static Il2CppMethodPointer Resolve(const char* name);

#if IL2CPP_ENABLE_MEM_STATS
        static size_t GetInternalCallsCount();
#endif 
    };
} /* namespace vm */
} /* namespace il2cpp */
