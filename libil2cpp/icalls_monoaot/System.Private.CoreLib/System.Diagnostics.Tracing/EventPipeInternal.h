#pragma once

#include "il2cpp-object-internals.h"
#include "il2cpp-class-internals.h"
#include "mono-structs.h"

namespace il2cpp
{
namespace icalls
{
namespace System
{
namespace Private
{
namespace CoreLib
{
namespace System
{
namespace Diagnostics
{
namespace Tracing
{
    class LIBIL2CPP_CODEGEN_API EventPipeInternal
    {
    public:
        static bool GetNextEvent(uint64_t sessionID, Il2CppEventPipeEventInstanceData* pInstance);
        static bool GetSessionInfo(uint64_t sessionID, Il2CppEventPipeSessionInfo* pSessionInfo);
        static bool SignalSession(uint64_t sessionID);
        static bool WaitForSessionSignal(uint64_t sessionID, int32_t timeoutMs);
        static int32_t EventActivityIdControl(uint32_t controlCode, Il2CppGuid* activityId);
        static intptr_t CreateProvider(Il2CppString* providerName, intptr_t callbackFunc, intptr_t callbackContext);
        static intptr_t DefineEvent(intptr_t provHandle, uint32_t eventID, int64_t keywords, uint32_t eventVersion, uint32_t level, uint8_t* pMetadata, uint32_t metadataLength);
        static intptr_t GetProvider(Il2CppChar* providerName);
        static uint64_t Enable(Il2CppChar* outputFile, int32_t format, uint32_t circularBufferSizeInMB, Il2CppEventPipeProviderConfigurationNative* providers, uint32_t numProviders);
        static uint64_t GetRuntimeCounterValue(int32_t counterID);
        static void DeleteProvider(intptr_t provHandle);
        static void Disable(uint64_t sessionID);
        static void WriteEventData(intptr_t eventHandle, Il2CppEventData* pEventData, uint32_t dataCount, Il2CppGuid* activityId, Il2CppGuid* relatedActivityId);
    };
} // namespace Tracing
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
