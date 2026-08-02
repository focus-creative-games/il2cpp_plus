#include "il2cpp-config.h"
#include "StackTrace.h"

#include "gc/WriteBarrier.h"
#include "vm/Array.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm-utils/DebugSymbolReader.h"

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
    void StackTrace::GetTrace(Il2CppObjectHandleOnStack ex, Il2CppObjectHandleOnStack res, int32_t skipFrames, bool needFileInfo)
    {
        Il2CppException* exception = (Il2CppException*)(Il2CppObject*)ex;

        /* Exception is not thrown yet */
        if (exception->trace_ips == NULL)
        {
            res = vm::Array::New(il2cpp_defaults.mono_stack_frame_class, 0);
            return;
        }

        int len = vm::Array::GetLength(exception->trace_ips);
        Il2CppArray* stackFrames = vm::Array::New(il2cpp_defaults.mono_stack_frame_class, len > skipFrames ? len - skipFrames : 0);

        for (int i = skipFrames; i < len; i++)
        {
            Il2CppMonoStackFrame* stackFrame = NULL;

            if (utils::DebugSymbolReader::DebugSymbolsAvailable())
            {
                stackFrame = il2cpp_array_get(exception->trace_ips, Il2CppMonoStackFrame*, i);
            }
            else
            {
                stackFrame = (Il2CppMonoStackFrame*)vm::Object::New(il2cpp_defaults.mono_stack_frame_class);
                MethodInfo* method = il2cpp_array_get(exception->trace_ips, MethodInfo*, i);

                IL2CPP_OBJECT_SETREF(stackFrame, method, vm::Reflection::GetMethodObject(method, NULL));
            }

            il2cpp_array_setref(stackFrames, i, stackFrame);
        }

        res = stackFrames;
    }
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
