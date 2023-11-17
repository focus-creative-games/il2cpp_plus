#include "il2cpp-config.h"
#include "os/WindowsRuntime.h"
#include "utils/Expected.h"
#include "utils/Il2CppError.h"

#if IL2CPP_USE_GENERIC_WINDOWSRUNTIME

namespace il2cpp
{
namespace os
{
    il2cpp_hresult_t WindowsRuntime::GetActivationFactory(Il2CppHString className, Il2CppIActivationFactory** activationFactory)
    {
        NO_UNUSED_WARNING(className);
        NO_UNUSED_WARNING(activationFactory);
        IL2CPP_ASSERT(className != NULL);
        IL2CPP_ASSERT(activationFactory != NULL);
        return IL2CPP_REGDB_E_CLASSNOTREG;
    }

    il2cpp_hresult_t WindowsRuntime::CreateHStringReference(const utils::StringView<Il2CppNativeChar>& str, Il2CppHStringHeader* header, Il2CppHString* hstring)
    {
        NO_UNUSED_WARNING(str);
        NO_UNUSED_WARNING(header);
        NO_UNUSED_WARNING(hstring);
        IL2CPP_ASSERT(header != NULL);
        IL2CPP_ASSERT(hstring != NULL);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

    il2cpp_hresult_t WindowsRuntime::CreateHString(const utils::StringView<Il2CppChar>& str, Il2CppHString* hstring)
    {
        NO_UNUSED_WARNING(str);
        NO_UNUSED_WARNING(hstring);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

#if !IL2CPP_TARGET_WINDOWS // Il2CppChar and Il2CppNativeChar are the same on Windows
    il2cpp_hresult_t WindowsRuntime::CreateHString(const utils::StringView<Il2CppNativeChar>& str, Il2CppHString* hstring)
    {
        NO_UNUSED_WARNING(str);
        NO_UNUSED_WARNING(hstring);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

#endif

    il2cpp_hresult_t WindowsRuntime::DuplicateHString(Il2CppHString hstring, Il2CppHString* duplicated)
    {
        NO_UNUSED_WARNING(hstring);
        NO_UNUSED_WARNING(duplicated);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

    il2cpp_hresult_t WindowsRuntime::DeleteHString(Il2CppHString hstring)
    {
        NO_UNUSED_WARNING(hstring);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

    utils::Expected<const Il2CppChar*> WindowsRuntime::GetHStringBuffer(Il2CppHString hstring, uint32_t* length)
    {
        NO_UNUSED_WARNING(hstring);
        NO_UNUSED_WARNING(length);
        return utils::Il2CppError(utils::ComError, IL2CPP_COR_E_PLATFORMNOTSUPPORTED);
    }

    utils::Expected<const Il2CppNativeChar*> WindowsRuntime::GetNativeHStringBuffer(Il2CppHString hstring, uint32_t* length)
    {
        NO_UNUSED_WARNING(hstring);
        NO_UNUSED_WARNING(length);
        return utils::Il2CppError(utils::ComError, IL2CPP_COR_E_PLATFORMNOTSUPPORTED);
    }

    utils::Expected<il2cpp_hresult_t> WindowsRuntime::PreallocateHStringBuffer(uint32_t length, Il2CppNativeChar** mutableBuffer, void** bufferHandle)
    {
        NO_UNUSED_WARNING(length);
        NO_UNUSED_WARNING(mutableBuffer);
        NO_UNUSED_WARNING(bufferHandle);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

    utils::Expected<il2cpp_hresult_t> WindowsRuntime::PromoteHStringBuffer(void* bufferHandle, Il2CppHString* hstring)
    {
        NO_UNUSED_WARNING(bufferHandle);
        NO_UNUSED_WARNING(hstring);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

    utils::Expected<il2cpp_hresult_t> WindowsRuntime::DeleteHStringBuffer(void* bufferHandle)
    {
        NO_UNUSED_WARNING(bufferHandle);
        return IL2CPP_COR_E_PLATFORMNOTSUPPORTED;
    }

    Il2CppIRestrictedErrorInfo* WindowsRuntime::GetRestrictedErrorInfo()
    {
        return NULL;
    }

    void WindowsRuntime::OriginateLanguageException(il2cpp_hresult_t hresult, Il2CppException* ex, Il2CppString* exceptionString, GetOrCreateFunc createCCWCallback)
    {
        NO_UNUSED_WARNING(ex);
        NO_UNUSED_WARNING(exceptionString);
        NO_UNUSED_WARNING(createCCWCallback);
    }

    void WindowsRuntime::EnableErrorReporting()
    {
    }
}
}

#endif
