#include "il2cpp-config.h"
#include "Environment.h"

#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "os/CrashHelpers.h"
#include "os/Environment.h"
#include "os/Memory.h"
#include "os/Time.h"
#include "utils/Environment.h"
#include "utils/Exception.h"
#include "utils/Logging.h"
#include "utils/PathUtils.h"
#include "utils/StringUtils.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Domain.h"
#include "vm/Exception.h"
#include "vm/Runtime.h"
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
    int32_t Environment::GetProcessorCount()
    {
        return il2cpp::os::Environment::GetProcessorCount();
    }

    int32_t Environment::get_ExitCode()
    {
        return vm::Runtime::GetExitCode();
    }

    int32_t Environment::get_TickCount()
    {
        return (int32_t)il2cpp::os::Time::GetTicksMillisecondsMonotonic();
    }

    int64_t Environment::get_TickCount64()
    {
        return il2cpp::os::Time::GetTicksMillisecondsMonotonic();
    }

    Il2CppArray* Environment::GetCommandLineArgs()
    {
        Il2CppArray *res;
        int i;
        int num_main_args = utils::Environment::GetNumMainArgs();
        const std::vector<UTF16String>& mainArgs = utils::Environment::GetMainArgs();

        Il2CppClass *klass = il2cpp::vm::Class::GetArrayClass(il2cpp_defaults.string_class, 1);
        res = (Il2CppArray*)il2cpp::vm::Array::NewSpecific(klass, num_main_args);

        for (i = 0; i < num_main_args; ++i)
            il2cpp_array_setref(res, i, il2cpp::vm::String::NewUtf16(mainArgs[i].c_str(), static_cast<int>(mainArgs[i].length())));

        return res;
    }

    void Environment::Exit(int32_t exitCode)
    {
        set_ExitCode(exitCode);
        il2cpp::vm::Runtime::Shutdown();
        il2cpp::os::Environment::Exit(exitCode);
    }

    void Environment::FailFast(Il2CppString* message, Il2CppException* exception, Il2CppString* errorSource)
    {
        bool messageWritten = false;
        if (message != NULL)
        {
            std::string messageUtf8 = il2cpp::utils::StringUtils::Utf16ToUtf8(message->chars, message->length);
            if (!messageUtf8.empty())
            {
                il2cpp::utils::Logging::Write(messageUtf8.c_str());
                messageWritten = true;
            }
        }

        if (!messageWritten)
            il2cpp::utils::Logging::Write("Managed code called FailFast without specifying a reason.");

        if (exception != NULL)
        {
            std::string exceptionMessage = utils::Exception::FormatException(exception);
            il2cpp::utils::Logging::Write(exceptionMessage.c_str());
        }

        il2cpp::os::CrashHelpers::Crash();
    }

    void Environment::set_ExitCode(int32_t value)
    {
        vm::Runtime::SetExitCode(value);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
