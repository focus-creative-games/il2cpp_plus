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
    class LIBIL2CPP_CODEGEN_API NativeRuntimeEventSource
    {
    public:
        static void LogContentionLockCreated(intptr_t LockID, intptr_t AssociatedObjectID, uint16_t ClrInstanceID);
        static void LogContentionStart(uint8_t ContentionFlags, uint16_t ClrInstanceID, intptr_t LockID, intptr_t AssociatedObjectID, uint64_t LockOwnerThreadID);
        static void LogContentionStop(uint8_t ContentionFlags, uint16_t ClrInstanceID, double DurationNs);
        static void LogThreadPoolIODequeue(intptr_t NativeOverlapped, intptr_t Overlapped, uint16_t ClrInstanceID);
        static void LogThreadPoolIOEnqueue(intptr_t NativeOverlapped, intptr_t Overlapped, bool MultiDequeues, uint16_t ClrInstanceID);
        static void LogThreadPoolIOPack(intptr_t NativeOverlapped, intptr_t Overlapped, uint16_t ClrInstanceID);
        static void LogThreadPoolMinMaxThreads(uint16_t MinWorkerThreads, uint16_t MaxWorkerThreads, uint16_t MinIOCompletionThreads, uint16_t MaxIOCompletionThreads, uint16_t ClrInstanceID);
        static void LogThreadPoolWorkerThreadAdjustmentAdjustment(double AverageThroughput, uint32_t NewWorkerThreadCount, uint32_t Reason, uint16_t ClrInstanceID);
        static void LogThreadPoolWorkerThreadAdjustmentSample(double Throughput, uint16_t ClrInstanceID);
        static void LogThreadPoolWorkerThreadAdjustmentStats(double Duration, double Throughput, double ThreadPoolWorkerThreadWait, double ThroughputWave, double ThroughputErrorEstimate, double AverageThroughputErrorEstimate, double ThroughputRatio, double Confidence, double NewControlSetting, uint16_t NewThreadWaveMagnitude, uint16_t ClrInstanceID);
        static void LogThreadPoolWorkerThreadStart(uint32_t ActiveWorkerThreadCount, uint32_t RetiredWorkerThreadCount, uint16_t ClrInstanceID);
        static void LogThreadPoolWorkerThreadStop(uint32_t ActiveWorkerThreadCount, uint32_t RetiredWorkerThreadCount, uint16_t ClrInstanceID);
        static void LogThreadPoolWorkerThreadWait(uint32_t ActiveWorkerThreadCount, uint32_t RetiredWorkerThreadCount, uint16_t ClrInstanceID);
        static void LogThreadPoolWorkingThreadCount(uint32_t Count, uint16_t ClrInstanceID);
    };
} // namespace Tracing
} // namespace Diagnostics
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
