#include "il2cpp-config.h"
#include "StackFrame.h"

#include "gc/GarbageCollector.h"
#include "vm/Method.h"
#include "vm/Reflection.h"
#include "vm/StackTrace.h"
#include "vm/String.h"

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
    static bool IsCalledFromSystemDiagnosticsStackTrace(const vm::StackFrames& stack)
    {
        for (vm::StackFrames::const_iterator frame = stack.begin(); frame != stack.end(); ++frame)
        {
            if (vm::Method::GetClass(frame->method) == il2cpp_defaults.stack_frame_class)
                return true;
            if (vm::Method::GetClass(frame->method) == il2cpp_defaults.mono_stack_frame_class)
                return true;
        }

        return false;
    }

    static bool FrameNeedsSkipped(const Il2CppStackFrameInfo& frame)
    {
        return vm::Method::GetClass(frame.method) == il2cpp_defaults.stack_frame_class ||
            vm::Method::GetClass(frame.method) == il2cpp_defaults.stack_trace_class ||
            vm::Method::GetClass(frame.method) == il2cpp_defaults.mono_stack_frame_class;
    }

    bool StackFrame::GetFrameInfo(int32_t skipFrames, bool needFileInfo, Il2CppObjectHandleOnStack out_method, Il2CppObjectHandleOnStack out_file, int32_t* ilOffset, int32_t* nativeOffset, int32_t* line, int32_t* column)
    {
        // This should match StackFrame.SystemDiagnosticsStackDepth
        const int kSkippedFramesFromCorlibStackFrameMethods = 3;

        // This should match the constant in StackTrace.InitializeForCurrentThread
        const int kSkippedFramesFromCorlibStackTraceMethods = 2;

        const vm::StackFrames& stack = *vm::StackTrace::GetCachedStackFrames(skipFrames);

        // Always ignore the skipped frames from System.Diagnostics.StackFrame, as we know we are always called from it.
        // These frames might be inlined or optimized away by the C++ compiler, so we will inspect the actual stack
        // frames later to see if we need to add skipped frames back in for System.Diagnostics.StackFrame.
        skipFrames -= kSkippedFramesFromCorlibStackFrameMethods;

        // Sometimes ignore the skipped frames from System.Diagnostics.StackTrace, as we may or may not be called from it.
        // These frames might be inlined or optimized away by the C++ compiler, so we will inspect the actual stack
        // frames later to see if we need to add skipped frames back in for System.Diagnostics.StackTrace.
        if (IsCalledFromSystemDiagnosticsStackTrace(stack))
            skipFrames -= kSkippedFramesFromCorlibStackTraceMethods;

        // Now look in the actual stack trace to see if anything we ignored above is really there. We don't know what the C++
        // compile will do with these frames, so we need to inspect each frame and check.
        for (vm::StackFrames::const_iterator frame = stack.begin(); frame != stack.end(); ++frame)
        {
            if (FrameNeedsSkipped(*frame))
                skipFrames++;
        }

        // Finally, find the location in the stack we actually want to use by offsetting from the end of the stack the number of
        // frames we skipped, and offsetting it by one more to account for this icall itself.
        int64_t index = stack.size() - skipFrames - 1;
        if (static_cast<uint64_t>(index) >= stack.size() || index < 0)
            return false;

        const Il2CppStackFrameInfo& info = stack[static_cast<size_t>(index)];

        out_method = (Il2CppObject*)vm::Reflection::GetMethodObject(info.method, info.method->klass);

        if (info.filePath != NULL && strlen(info.filePath) != 0)
        {
            *line = info.sourceCodeLineNumber;
            *ilOffset = info.ilOffset;
            out_file = il2cpp::vm::String::New(info.filePath);
        }

        return true;
    }
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
