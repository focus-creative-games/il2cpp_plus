#include "os/Assert.h"

#if IL2CPP_DEBUG

#if IL2CPP_USE_GENERIC_ASSERT

#include "os/Console.h"

void il2cpp_assert(const char* assertion, const char* file, unsigned int line)
{
    il2cpp_console_printf_error("Assertion failed: %s, file %s, line %u\n", assertion, file, line);
    abort();
}

#endif // IL2CPP_USE_GENERIC_ASSERT

#endif // IL2CPP_DEBUG
