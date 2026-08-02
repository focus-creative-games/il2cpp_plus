#pragma once

#include "utils/Expected.h"
#include "utils/Il2CppError.h"

#include <stdint.h>

struct Il2CppObject;

namespace il2cpp
{
namespace gc
{
    enum GCHandleType
    {
        HANDLE_WEAK,
        HANDLE_WEAK_TRACK,
        HANDLE_NORMAL,
        HANDLE_PINNED,
        HANDLE_TYPE_MAX
    };

    const Il2CppGCHandle kEmptyGCHandle = (Il2CppGCHandle)0;

    class LIBIL2CPP_CODEGEN_API GCHandle
    {
    public:
        // external
        static Il2CppGCHandle New(Il2CppObject *obj, bool pinned);
        static utils::Expected<Il2CppGCHandle> NewWeakref(Il2CppObject *obj, bool track_resurrection);
        static Il2CppObject* GetTarget(Il2CppGCHandle gchandle);
        static void SetTarget(Il2CppGCHandle gchandle, Il2CppObject* value);
#if !MONO_NET8_BCL
        static GCHandleType GetHandleType(Il2CppGCHandle gcHandle);
#endif
        static void Free(Il2CppGCHandle gchandle);
    public:
        //internal
#if !MONO_NET8_BCL
        static utils::Expected<Il2CppGCHandle> GetTargetHandle(Il2CppObject * obj, Il2CppGCHandle handle, int32_t type);
#endif
        typedef void(*WalkGCHandleTargetsCallback)(Il2CppObject* obj, void* context);
        static void WalkStrongGCHandleTargets(WalkGCHandleTargetsCallback callback, void* context);

        static void AcquireMetadataLocks();
        static void ReleaseMetadataLocks();
    };
} /* gc */
} /* il2cpp */
