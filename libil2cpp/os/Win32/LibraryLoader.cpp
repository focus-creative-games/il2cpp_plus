#include "il2cpp-config.h"

#if IL2CPP_TARGET_WINDOWS

#include "il2cpp-runtime-metadata.h"
#include "os/LibraryLoader.h"
#include "os/Image.h"
#include "utils/Memory.h"
#include "utils/StringUtils.h"

#include "WindowsHelpers.h"
#include "Evntprov.h"

#define WINNT // All functions in Evntrace.h are under this define.. Why? I have no idea!
#include "Evntrace.h"

#if IL2CPP_TARGET_WINDOWS_GAMES
#include "os/WindowsGames/Win32ApiWindowsGamesEmulation.h"
#endif

#include <bcrypt.h>

namespace il2cpp
{
namespace os
{
    const HardcodedPInvokeDependencyFunction kAdvapiFunctions[] =
    {
        HARDCODED_DEPENDENCY_FUNCTION(EnumerateTraceGuidsEx),
        HARDCODED_DEPENDENCY_FUNCTION(EventActivityIdControl),
        HARDCODED_DEPENDENCY_FUNCTION(EventRegister),
        HARDCODED_DEPENDENCY_FUNCTION(EventSetInformation),
        HARDCODED_DEPENDENCY_FUNCTION(EventUnregister),
        HARDCODED_DEPENDENCY_FUNCTION(EventWrite),
        HARDCODED_DEPENDENCY_FUNCTION(EventWriteEx),
        HARDCODED_DEPENDENCY_FUNCTION(EventWriteString),
        HARDCODED_DEPENDENCY_FUNCTION(EventWriteTransfer),
    };

    const HardcodedPInvokeDependencyFunction kKernel32Functions[] =
    {
        HARDCODED_DEPENDENCY_FUNCTION(FormatMessageW),
        HARDCODED_DEPENDENCY_FUNCTION(GetCurrentProcessId),
        HARDCODED_DEPENDENCY_FUNCTION(GetDynamicTimeZoneInformation),
        HARDCODED_DEPENDENCY_FUNCTION(GetNativeSystemInfo),
        HARDCODED_DEPENDENCY_FUNCTION(GetTimeZoneInformation),
        HARDCODED_DEPENDENCY_FUNCTION(GetFullPathNameW),
        HARDCODED_DEPENDENCY_FUNCTION(GetFileAttributesExW),
        HARDCODED_DEPENDENCY_FUNCTION(CreateDirectoryW),
        HARDCODED_DEPENDENCY_FUNCTION(CloseHandle),
        HARDCODED_DEPENDENCY_FUNCTION(CreateFileW),
        HARDCODED_DEPENDENCY_FUNCTION(DeleteFileW),
        HARDCODED_DEPENDENCY_FUNCTION(FindFirstFileExW),
        HARDCODED_DEPENDENCY_FUNCTION(FindNextFileW),
        HARDCODED_DEPENDENCY_FUNCTION(MoveFileExW),
        HARDCODED_DEPENDENCY_FUNCTION(MultiByteToWideChar),
        HARDCODED_DEPENDENCY_FUNCTION(RemoveDirectoryW),
        HARDCODED_DEPENDENCY_FUNCTION(ReplaceFileW),
        HARDCODED_DEPENDENCY_FUNCTION(SetFileAttributesW),
        HARDCODED_DEPENDENCY_FUNCTION(SetFileInformationByHandle),
        HARDCODED_DEPENDENCY_FUNCTION(GetFileInformationByHandleEx),
        HARDCODED_DEPENDENCY_FUNCTION(CopyFile2),
        HARDCODED_DEPENDENCY_FUNCTION(SetThreadErrorMode),
        HARDCODED_DEPENDENCY_FUNCTION(GetCurrentThread),
        HARDCODED_DEPENDENCY_FUNCTION(GetThreadDescription),
        HARDCODED_DEPENDENCY_FUNCTION(CopyFileExW),
        HARDCODED_DEPENDENCY_FUNCTION(DeleteVolumeMountPointW),
        HARDCODED_DEPENDENCY_FUNCTION(GetLogicalDrives),
        HARDCODED_DEPENDENCY_FUNCTION(LocalAlloc),
        HARDCODED_DEPENDENCY_FUNCTION(LocalReAlloc),
        HARDCODED_DEPENDENCY_FUNCTION(LocalFree),
        HARDCODED_DEPENDENCY_FUNCTION(GetTempPathW),
#if IL2CPP_TARGET_WINDOWS_GAMES
        HARDCODED_DEPENDENCY_FUNCTION_BY_NAME("GetTempPath2W", GetTempPathW)
#endif
    };

    const HardcodedPInvokeDependencyFunction kBCryptFunctions[] =
    {
        HARDCODED_DEPENDENCY_FUNCTION(BCryptGenRandom),
    };

    const HardcodedPInvokeDependencyFunction kiphlpapiFunctions[] =
    {
        HARDCODED_DEPENDENCY_FUNCTION(GetNetworkParams),
        HARDCODED_DEPENDENCY_FUNCTION(GetAdaptersAddresses),
        HARDCODED_DEPENDENCY_FUNCTION(GetIfEntry),
    };

#if !IL2CPP_TARGET_WINDOWS_GAMES
    const HardcodedPInvokeDependencyFunction kTimezoneFunctions[] =
    {
        HARDCODED_DEPENDENCY_FUNCTION(EnumDynamicTimeZoneInformation),
        HARDCODED_DEPENDENCY_FUNCTION(GetDynamicTimeZoneInformation),
        HARDCODED_DEPENDENCY_FUNCTION(GetDynamicTimeZoneInformationEffectiveYears),
        HARDCODED_DEPENDENCY_FUNCTION(GetTimeZoneInformationForYear),
    };

    const HardcodedPInvokeDependencyFunction kWinTypesFunctions[] =
    {
        HARDCODED_DEPENDENCY_FUNCTION(RoGetBufferMarshaler)
    };
#else
    const HardcodedPInvokeDependencyFunction kUser32Functions[] =
    {
        HARDCODED_DEPENDENCY_FUNCTION(LoadStringW)
    };
#endif

// All these come without ".dll" extension!
    const HardcodedPInvokeDependencyLibrary kHardcodedPInvokeDependencies[] =
    {
        HARDCODED_DEPENDENCY_LIBRARY(L"kernel32", kKernel32Functions),
        HARDCODED_DEPENDENCY_LIBRARY(L"bcrypt", kBCryptFunctions),
#if !IL2CPP_TARGET_WINDOWS_GAMES
        HARDCODED_DEPENDENCY_LIBRARY(L"advapi32", kAdvapiFunctions),
        HARDCODED_DEPENDENCY_LIBRARY(L"api-ms-win-core-timezone-l1-1-0", kTimezoneFunctions),
        HARDCODED_DEPENDENCY_LIBRARY(L"iphlpapi", kiphlpapiFunctions),
        HARDCODED_DEPENDENCY_LIBRARY(L"wintypes", kWinTypesFunctions)
#else
        HARDCODED_DEPENDENCY_LIBRARY(L"user32", kUser32Functions)
#endif
    };

    const HardcodedPInvokeDependencyLibrary* LibraryLoader::HardcodedPInvokeDependencies = kHardcodedPInvokeDependencies;
    const size_t LibraryLoader::HardcodedPInvokeDependenciesCount = ARRAYSIZE(kHardcodedPInvokeDependencies);

    Baselib_DynamicLibrary_Handle LibraryLoader::ProbeForLibrary(const Il2CppNativeChar* libraryName, const size_t libraryNameLength, std::string& detailedError)
    {
        Baselib_DynamicLibrary_Handle handle = TryOpeningLibrary(libraryName, detailedError);

        if (handle == Baselib_DynamicLibrary_Handle_Invalid)
        {
            if (libraryNameLength > 4 && _wcsnicmp(libraryName + libraryNameLength - 4, L".dll", 4) != 0)
            {
                Il2CppNativeChar* libaryNameWithExt = (Il2CppNativeChar*)IL2CPP_MALLOC((libraryNameLength + 5) * sizeof(Il2CppNativeChar));
                memcpy(libaryNameWithExt, libraryName, libraryNameLength * sizeof(Il2CppNativeChar));
                wcscpy(libaryNameWithExt + libraryNameLength, L".dll");
                detailedError.clear();
                handle = TryOpeningLibrary(libaryNameWithExt, detailedError);
                IL2CPP_FREE(libaryNameWithExt);
            }
        }

        return handle;
    }

    Baselib_DynamicLibrary_Handle LibraryLoader::OpenProgramHandle(Baselib_ErrorState& errorState, bool& needsClosing)
    {
        needsClosing = false;
        return Baselib_DynamicLibrary_FromNativeHandle(reinterpret_cast<uint64_t>(Image::GetImageBase()), Baselib_DynamicLibrary_WinApiHMODULE, &errorState);
    }

    bool LibraryLoader::EntryNameMatches(const il2cpp::utils::StringView<char>& hardcodedEntryPoint, const il2cpp::utils::StringView<char>& entryPoint)
    {
        // Handle windows mapping generic to unicode methods. e.g. MoveFileEx -> MoveFileExW
        if (hardcodedEntryPoint.Length() == entryPoint.Length() || (hardcodedEntryPoint.Length() - 1 == entryPoint.Length() && hardcodedEntryPoint[hardcodedEntryPoint.Length() - 1] == 'W'))
        {
            return strncmp(hardcodedEntryPoint.Str(), entryPoint.Str(), entryPoint.Length()) == 0;
        }

        return false;
    }
}
}

#endif
