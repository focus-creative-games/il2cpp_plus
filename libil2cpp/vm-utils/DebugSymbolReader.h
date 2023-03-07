#pragma once

#include <cstdint>

namespace il2cpp
{
namespace utils
{
    struct SourceLocation
    {
        const char* filePath;
        uint32_t lineNumber;
    };

    class DebugSymbolReader
    {
    public:
        static bool LoadDebugSymbols();
        static bool GetSourceLocation(void* nativeInsturctionPointer, SourceLocation& sourceLocation);
        static bool AddStackFrames(void* nativeInsturctionPointer, std::vector<Il2CppStackFrameInfo>* stackFrames);
        static bool DebugSymbolsAvailable();
    };
} /* namespace utils */
} /* namespace il2cpp */
