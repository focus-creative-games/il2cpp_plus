#pragma once

#include <string>
#include "il2cpp-class-internals.h"
#include "os/Mutex.h"

struct MethodInfo;
struct Il2CppGenericMethod;
struct Il2CppGenericContext;
struct Il2CppGenericInst;

namespace il2cpp
{
namespace metadata
{
    class GenericMethod
    {
    public:
        // exported

    public:
        //internal

        static const MethodInfo* GetGenericVirtualMethod(const MethodInfo* vtableSlotMethod, const MethodInfo* genericVirtualMethod);
        static const MethodInfo* GetMethod(const MethodInfo* methodDefinition, const Il2CppGenericInst* classInst, const Il2CppGenericInst* methodInst);
        static const MethodInfo* GetMethod(const Il2CppGenericMethod& gmethod, Il2CppRGCTXInitMode rgctxInitMode = IL2CPP_RGCTX_INIT_MODE_DEFAULT);
        static MethodInfo* AllocateNewMethodInfo(const MethodInfo* methodDefinition, const Il2CppGenericInst* classInst, const Il2CppGenericInst* methodInst);
        static bool IsGenericAmbiguousMethodInfo(const MethodInfo* method);
        static bool IsGenericEntryPointNotFoundMethod(const MethodInfo* method);

        static const Il2CppGenericContext* GetContext(const Il2CppGenericMethod* gmethod);
        static std::string GetFullName(const Il2CppGenericMethod* gmethod);

        static void ClearStatics();
        static const Il2CppRGCTXData* InflateRGCTX(const MethodInfo* method, Il2CppException** exc);

        static void AcquireMetadataLocks();
        static void ReleaseMetadataLocks();

    private:
        static const MethodInfo* CreateMethodLocked(const Il2CppGenericMethod& gmethod, Il2CppRGCTXInitMode rgctxInitMode);
        static const Il2CppRGCTXData* InflateRGCTXLocked(const Il2CppGenericMethod& gmethod, const il2cpp::os::FastAutoLock& lock, Il2CppException** exc);
    };
} /* namespace vm */
} /* namespace il2cpp */
