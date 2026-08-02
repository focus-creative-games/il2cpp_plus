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
namespace InteropServices
{
    class LIBIL2CPP_CODEGEN_API Marshal
    {
    public:
        static int32_t GetLastPInvokeError();
        static int32_t SizeOfHelper(Il2CppQCallTypeHandle t, bool throwIfNotMarshalable);
        static intptr_t GetFunctionPointerForDelegateInternal(Il2CppDelegate* d);
        static intptr_t OffsetOf(Il2CppReflectionType* t, Il2CppString* fieldName);
        static void DestroyStructure(intptr_t ptr, Il2CppReflectionType* structureType);
        static void GetDelegateForFunctionPointerInternal(Il2CppQCallTypeHandle t, intptr_t ptr, Il2CppObjectHandleOnStack res);
        static void PrelinkInternal(Il2CppObject* m);
        static void PtrToStructureInternal(intptr_t ptr, Il2CppObject* structure, bool allowValueClasses);
        static void SetLastPInvokeError(int32_t error);
        static void StructureToPtr(Il2CppObject* structure, intptr_t ptr, bool fDeleteOld);
    };
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
