#include "il2cpp-config.h"
#include "NativeLibrary.h"
#include "os/LibraryLoader.h"
#include "vm/Exception.h"
#include "vm-utils/VmStringUtils.h"
#include "utils/StringUtils.h"

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
namespace Runtime
{
namespace InteropServices
{
    intptr_t NativeLibrary::GetSymbol(intptr_t handle, Il2CppString* symbolName, bool throwOnError)
    {
        Baselib_ErrorState errorState = Baselib_ErrorState_Create();
        // the handle type below is a hack and needs to be handled in platform specific code.
        Baselib_DynamicLibrary_Handle baselibHandle = Baselib_DynamicLibrary_FromNativeHandle(handle, (Baselib_DynamicLibrary_NativeHandleType)1, &errorState);

        DECLARE_IL2CPP_STRING_AS_STRING_VIEW_OF_NATIVE_CHARS(symbolNameNative, symbolName);
        auto symbolNameUtf8 = il2cpp::utils::StringUtils::NativeStringToUtf8(symbolNameNative.Str());

        auto hardCodedFunc = os::LibraryLoader::GetHardcodedPInvokeDependencyFunctionPointer(baselibHandle, symbolNameUtf8, CHARSET_NOT_SPECIFIED);
        if (hardCodedFunc)
            return (intptr_t)hardCodedFunc;

        std::string detailedGetFunctionError;
        auto function = os::LibraryLoader::GetFunctionPointer(baselibHandle, symbolNameUtf8.c_str(), detailedGetFunctionError);
        if (throwOnError && function == NULL)
        {
            std::string message;
            message += "Unable to find an entry point named '";
            message += il2cpp::utils::StringUtils::NativeStringToUtf8(symbolNameNative.Str());
            //message += "' in '";
            //message += il2cpp::utils::StringUtils::NativeStringToUtf8(pinvokeArgs.moduleName.Str());
            message += "'. Tried the following entry points: ";
            message += detailedGetFunctionError;
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetEntryPointNotFoundException(message.c_str()));
        }

        return (intptr_t)function;
    }

    intptr_t NativeLibrary::LoadByName(Il2CppString* libraryName, Il2CppReflectionAssembly* callingAssembly, bool hasDllImportSearchPathFlag, uint32_t dllImportSearchPathFlag, bool throwOnError)
    {
        IL2CPP_NOT_IMPLEMENTED_ICALL(NativeLibrary::LoadByName);
        IL2CPP_UNREACHABLE;
        return 0;
    }

    intptr_t NativeLibrary::LoadFromPath(Il2CppString* libraryName, bool throwOnError)
    {
        // TODO: check os::LibraryLoader::GetHardcodedPInvokeDependencyFunctionPointer first
        DECLARE_IL2CPP_STRING_AS_STRING_VIEW_OF_NATIVE_CHARS(libraryNameNative, libraryName);

        Baselib_DynamicLibrary_Handle dynamicLibrary = Baselib_DynamicLibrary_Handle_Invalid;
        std::string detailedLoadError;
        if (utils::VmStringUtils::CaseSensitiveEquals(il2cpp::utils::StringUtils::NativeStringToUtf8(libraryNameNative.Str()).c_str(), "__InternalDynamic"))
            dynamicLibrary = os::LibraryLoader::LoadDynamicLibrary(il2cpp::utils::StringView<Il2CppNativeChar>::Empty(), detailedLoadError);
        else
            dynamicLibrary = os::LibraryLoader::LoadDynamicLibrary(libraryNameNative, detailedLoadError);

        if (throwOnError && dynamicLibrary == Baselib_DynamicLibrary_Handle_Invalid)
        {
            std::string message;
            message += "Unable to load DLL '";
            message += il2cpp::utils::StringUtils::NativeStringToUtf8(libraryNameNative.Str());
            message += "'. Tried the load the following dynamic libraries: ";
            message += detailedLoadError;
            il2cpp::vm::Exception::Raise(il2cpp::vm::Exception::GetDllNotFoundException(message.c_str()));
        }

        return dynamicLibrary.handle;
    }

    void NativeLibrary::FreeLib(intptr_t handle)
    {
        Baselib_ErrorState errorState = Baselib_ErrorState_Create();
        // the handle type below is a hack and needs to be handled in platform specific code.
        Baselib_DynamicLibrary_Handle baselibHandle = Baselib_DynamicLibrary_FromNativeHandle(handle, (Baselib_DynamicLibrary_NativeHandleType)1, &errorState);

        Baselib_DynamicLibrary_Close(baselibHandle);
    }
} // namespace InteropServices
} // namespace Runtime
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
