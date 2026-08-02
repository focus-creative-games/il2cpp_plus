#include "il2cpp-config.h"

#if IL2CPP_TARGET_IOS

#include "os/Console.h"

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#include <stdio.h>
#include <stdarg.h>

IL2CPP_EXTERN_C void il2cpp_console_printf_error(const char* format, ...)
{
    va_list va;
    va_start(va, format);
    const int BUFFER_SIZE = 1024;
    char msg[BUFFER_SIZE];
    vsnprintf(msg, BUFFER_SIZE, format, va);
    msg[BUFFER_SIZE - 1] = '\0';
    NSLog(@"%s", msg);
    va_end(va);
}

#endif
