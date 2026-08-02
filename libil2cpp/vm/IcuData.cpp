#include "vm/IcuData.h"

#include "os/Directory.h"
#include "os/File.h"
#include "os/Path.h"
#include "utils/MemoryMappedFile.h"
#include "utils/Runtime.h"
#include "utils/PathUtils.h"

 #if IL2CPP_TARGET_JAVASCRIPT
#define SYSTEM_GLOBALIZATION_LOAD_ICU_DATA mono_wasm_load_icu_data
#else
// The wasi entry point is always exported, uses that for all non-web platforms
#define SYSTEM_GLOBALIZATION_LOAD_ICU_DATA mono_wasi_load_icu_data
#endif

extern "C" int32_t CDECL SYSTEM_GLOBALIZATION_LOAD_ICU_DATA(const void* pData);

namespace il2cpp
{
namespace vm
{
    static os::FileHandle* s_icuDataFile;
    static void* s_icuData;

    std::string IcuData::LoadIcuData()
    {
        std::string icuDataFileName;

#if IL2CPP_STATIC_ICU && !IL2CPP_SYSTEM_GLOBALIZATION_INVARIANT
        int error;
        auto appDir = os::Path::GetApplicationFolder();
        auto files = os::Directory::GetFileSystemEntries(appDir, utils::PathUtils::Combine(appDir, utils::StringView<char>("icudt*.dat")), 0, 0, &error);

        if (files.size() == 0 || error != 0)
        {
            auto dataDirectory = utils::Runtime::GetDataDir();
            files = os::Directory::GetFileSystemEntries(dataDirectory, utils::PathUtils::Combine(dataDirectory, utils::StringView<char>("icudt*.dat")), 0, 0, &error);
        }

        if (files.size() > 0)
        {
            icuDataFileName = *files.begin();

            int32_t loaded = 0;

            int error;
            s_icuDataFile = os::File::Open(icuDataFileName, kFileModeOpen, kFileAccessRead, kFileShareNone, 0, &error);
            IL2CPP_ASSERT(s_icuDataFile != NULL && error == 0 && "Failed to load ICU data file");
            if (s_icuDataFile && error == 0)
            {
                s_icuData = utils::MemoryMappedFile::Map(s_icuDataFile);
                IL2CPP_ASSERT(s_icuData && "Failed to map ICU data file");
                if (s_icuData)
                {
                    loaded = SYSTEM_GLOBALIZATION_LOAD_ICU_DATA(s_icuData);
                    IL2CPP_ASSERT(loaded && "System.Native.Globalization failed to load the map ICU data");
                }
            }
        }
#endif
        return icuDataFileName;
    }

    void IcuData::FreeIcuData()
    {
        if (s_icuData)
        {
            bool unmapped = utils::MemoryMappedFile::Unmap(s_icuData);
            IL2CPP_ASSERT(unmapped);
            s_icuData = nullptr;
        }

        if (s_icuDataFile != nullptr)
        {
            int error = 0;
            bool closed = os::File::Close(s_icuDataFile, &error);
            IL2CPP_ASSERT(closed && error == 0);
            s_icuDataFile = nullptr;
        }
    }
}
}
