#include "il2cpp-config.h"
#include "Finally.h"
#include "vm/Exception.h"
#include "vm/Thread.h"

NORETURN void il2cpp::utils::RethrowException(Il2CppException* exception)
{
    vm::Exception::Rethrow(exception);
}

NORETURN void il2cpp::utils::ThrowNativeThreadAbortException()
{
    vm::Thread::ThrowNativeThreadAbortException();
}
