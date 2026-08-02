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
    class LIBIL2CPP_CODEGEN_API Array
    {
    public:
        static bool CanChangePrimitive(Il2CppObjectHandleOnStack srcType, Il2CppObjectHandleOnStack dstType, bool reliable);
        static bool FastCopy(Il2CppObjectHandleOnStack source, int32_t source_idx, Il2CppObjectHandleOnStack dest, int32_t dest_idx, int32_t length);
        static bool IsValueOfElementTypeInternal(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack obj);
        static int32_t GetLengthInternal(Il2CppObjectHandleOnStack arr, int32_t dimension);
        static int32_t GetLowerBoundInternal(Il2CppObjectHandleOnStack arr, int32_t dimension);
        static uint8_t GetCorElementTypeOfElementTypeInternal(Il2CppObjectHandleOnStack arr);
        static void GetValueImpl(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack res, int32_t pos);
        static void InitializeInternal(Il2CppObjectHandleOnStack arr);
        static void InternalCreate(Il2CppArray** result, intptr_t elementType, int32_t rank, int32_t* lengths, int32_t* lowerBounds);
        static void SetValueImpl(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack value, int32_t pos);
        static void SetValueRelaxedImpl(Il2CppObjectHandleOnStack arr, Il2CppObjectHandleOnStack value, int32_t pos);
    };
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
