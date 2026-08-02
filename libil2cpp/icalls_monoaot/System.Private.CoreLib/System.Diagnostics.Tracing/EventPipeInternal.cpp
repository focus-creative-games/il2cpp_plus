#include "il2cpp-config.h"
#include "EventPipeInternal.h"

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
    bool EventPipeInternal::GetNextEvent(uint64_t sessionID, Il2CppEventPipeEventInstanceData* pInstance)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::GetNextEvent);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    bool EventPipeInternal::GetSessionInfo(uint64_t sessionID, Il2CppEventPipeSessionInfo* pSessionInfo)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::GetSessionInfo);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    bool EventPipeInternal::SignalSession(uint64_t sessionID)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::SignalSession);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    bool EventPipeInternal::WaitForSessionSignal(uint64_t sessionID, int32_t timeoutMs)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::WaitForSessionSignal);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    int32_t EventPipeInternal::EventActivityIdControl(uint32_t controlCode, Il2CppGuid* activityId)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::EventActivityIdControl);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    intptr_t EventPipeInternal::CreateProvider(Il2CppString* providerName, intptr_t callbackFunc, intptr_t callbackContext)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::CreateProvider);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    intptr_t EventPipeInternal::DefineEvent(intptr_t provHandle, uint32_t eventID, int64_t keywords, uint32_t eventVersion, uint32_t level, uint8_t* pMetadata, uint32_t metadataLength)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::DefineEvent);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    intptr_t EventPipeInternal::GetProvider(Il2CppChar* providerName)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::GetProvider);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    uint64_t EventPipeInternal::Enable(Il2CppChar* outputFile, int32_t format, uint32_t circularBufferSizeInMB, Il2CppEventPipeProviderConfigurationNative* providers, uint32_t numProviders)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::Enable);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    uint64_t EventPipeInternal::GetRuntimeCounterValue(int32_t counterID)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::GetRuntimeCounterValue);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    void EventPipeInternal::DeleteProvider(intptr_t provHandle)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::DeleteProvider);
        IL2CPP_UNREACHABLE;
    }

    void EventPipeInternal::Disable(uint64_t sessionID)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::Disable);
        IL2CPP_UNREACHABLE;
    }

    void EventPipeInternal::WriteEventData(intptr_t eventHandle, Il2CppEventData* pEventData, uint32_t dataCount, Il2CppGuid* activityId, Il2CppGuid* relatedActivityId)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(EventPipeInternal::WriteEventData);
        IL2CPP_UNREACHABLE;
    }
} // namespace Tracing
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
