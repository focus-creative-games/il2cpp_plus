#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"

#include "RuntimeHelpers.h"

#include "icalls_monoaot/System.Private.CoreLib/System.Runtime.CompilerServices/RuntimeHelpers.h"
#include "vm/Field.h"

namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Runtime
{
namespace CompilerServices
{
    const char* runtime_helpers_get_field_data(FieldInfo* field, size_t* dataSize)
    {
        return il2cpp::vm::Field::GetData(field, dataSize);
    }

    void runtime_helpers_initialize_array_icall(RuntimeArray* array, RuntimeField* fldHandle)
    {
        icalls::System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeHelpers::InitializeArray(array, (intptr_t)fldHandle);
    }

    void* runtime_helpers_get_span_data_from_icall(RuntimeField* fldHandle, Il2CppType* targetTypeHandle, int32_t* count)
    {
        return icalls::System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeHelpers::GetSpanDataFrom(fldHandle, targetTypeHandle, count);
    }
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
