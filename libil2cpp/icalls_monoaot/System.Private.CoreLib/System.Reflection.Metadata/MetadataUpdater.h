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
namespace Metadata
{
    class LIBIL2CPP_CODEGEN_API MetadataUpdater
    {
    public:
        static int32_t ApplyUpdateEnabled(int32_t justComponentCheck);
        static Il2CppString* GetApplyUpdateCapabilities();
        static void ApplyUpdate_internal(intptr_t base_assm, uint8_t* dmeta_bytes, int32_t dmeta_length, uint8_t* dil_bytes, int32_t dil_length, uint8_t* dpdb_bytes, int32_t dpdb_length);
    };
} // namespace Metadata
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
