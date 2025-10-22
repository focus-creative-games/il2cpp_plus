#include "il2cpp-config.h"

#if IL2CPP_TARGET_ANDROID

#include "utils/StringUtils.h"

#include <jni.h>
#include <android/log.h>

namespace il2cpp
{
namespace os
{
namespace ConsoleExtension
{
    void Write(const char* buffer, int count)
    {
        __android_log_print(ANDROID_LOG_INFO, "IL2CPP", "%.*s", count, buffer);
    }
}
}
}

#endif
