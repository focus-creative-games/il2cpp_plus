#include "os/c-api/il2cpp-config-platforms.h"


#include "os/Console.h"
#include "os/File.h"
#include "utils/StringUtils.h"

extern "C"
{
#if IL2CPP_TINY
    void STDCALL UnityPalConsoleWrite(const char* message, bool newline)
    {
        il2cpp::os::FileHandle* fileHandle = il2cpp::os::File::GetStdOutput();
        int unused;
        if (message == NULL)
        {
            il2cpp::os::File::Write(fileHandle, "", 0, &unused);
        }
        else
        {
            std::string formattedMessage = il2cpp::utils::StringUtils::Printf("%s%s", message, newline ? il2cpp::os::Console::NewLine() : "");
            il2cpp::os::File::Write(fileHandle, formattedMessage.c_str(), (int)formattedMessage.size(), &unused);
        }
    }

#endif
}
