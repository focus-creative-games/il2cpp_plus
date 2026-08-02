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
    class LIBIL2CPP_CODEGEN_API Buffer
    {
    public:
        static void BulkMoveWithWriteBarrier(uint8_t* dmem, uint8_t* smem, intptr_t len, Il2CppType* type_handle);
        static void __Memmove(uint8_t* dest, uint8_t* src, intptr_t len);
        static void __ZeroMemory(void* b, intptr_t byteLength);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
