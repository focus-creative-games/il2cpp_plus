#include "il2cpp-config.h"

#include "os/Console.h"

#include <stdio.h>
#include <stdarg.h>

#if !IL2CPP_USE_PLATFORM_SPECIFIC_PRINTF

IL2CPP_EXTERN_C void il2cpp_console_printf_error(const char* format, ...)
{
    va_list va;
    va_start(va, format);
    vfprintf(stderr, format, va);
    va_end(va);
}

#endif
