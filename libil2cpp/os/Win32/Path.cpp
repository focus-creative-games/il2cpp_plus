#include "il2cpp-config.h"

#if IL2CPP_TARGET_WINDOWS

#include "WindowsHeaders.h"
#undef GetTempPath

#include "os/Environment.h"
#include "os/Path.h"
#include "utils/PathUtils.h"
#include "utils/StringUtils.h"
#include "WindowsHelpers.h"
#include <string>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

namespace il2cpp
{
namespace os
{
    std::string Path::GetExecutablePath()
    {
        wchar_t buffer[MAX_PATH];
        GetModuleFileNameW(nullptr, buffer, MAX_PATH);
        return utils::StringUtils::Utf16ToUtf8(buffer);
    }

    std::string Path::GetApplicationFolder()
    {
        wchar_t buffer[MAX_PATH];
        GetModuleFileNameW(reinterpret_cast<HMODULE>(&__ImageBase), buffer, MAX_PATH);
        return utils::PathUtils::DirectoryName(utils::StringUtils::Utf16ToUtf8(buffer));
    }

    std::string Path::GetTempPath()
    {
#if IL2CPP_TARGET_GAMECORE_XBOX
        return "T:\\";
#else
        WCHAR tempPath[MAX_PATH + 1];
        ::GetTempPathW(sizeof(tempPath) / sizeof(tempPath[0]), tempPath);
#if !IL2CPP_TARGET_WINDOWS_GAMES
        ::GetLongPathNameW(tempPath, tempPath, sizeof(tempPath) / sizeof(tempPath[0]));
#endif // !IL2CPP_TARGET_WINDOWS_GAMES

        return utils::StringUtils::Utf16ToUtf8(tempPath);
#endif
    }

    bool Path::IsAbsolute(const std::string& path)
    {
        if (path[0] != '\0' && path[1] != '\0')
        {
            if (path[1] == ':' && path[2] != '\0' && (path[2] == '\\' || path[2] == '/'))
                return true;
            /* UNC paths */
            else if (path[0] == '\\' && path[1] == '\\' && path[2] != '\0')
                return true;
        }

        return false;
    }
}
}
#endif
