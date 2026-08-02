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
namespace Diagnostics
{
    class LIBIL2CPP_CODEGEN_API StackFrame
    {
    public:
        static bool GetFrameInfo(int32_t skipFrames, bool needFileInfo, Il2CppObjectHandleOnStack out_method, Il2CppObjectHandleOnStack out_file, int32_t* ilOffset, int32_t* nativeOffset, int32_t* line, int32_t* column);
    };
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
