#include "il2cpp-config.h"
#include "gc/WriteBarrier.h"
#include "os/MarshalStringAlloc.h"
#include "os/WindowsRuntime.h"
#include "metadata/GenericMetadata.h"
#include "vm/Array.h"
#include "vm/AssemblyName.h"
#include "vm/Class.h"
#include "vm/CCW.h"
#include "vm/Exception.h"
#include "vm/Object.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/StackTrace.h"
#include "vm/String.h"
#include "vm/Type.h"
#include "Image.h"
#include "../utils/StringUtils.h"
#include "../utils/StringViewUtils.h"
#include "il2cpp-tabledefs.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "vm-utils/Debugger.h"
#include "vm-utils/VmStringUtils.h"
#include "vm-utils/DebugSymbolReader.h"

namespace il2cpp
{
namespace vm
{
    void Exception::PrepareExceptionForThrow(Il2CppException* ex, MethodInfo* lastManagedFrame)
    {
#if !IL2CPP_TINY

#if IL2CPP_MONO_DEBUGGER
        il2cpp::utils::Debugger::HandleException(ex);
#endif

        if (ex->trace_ips == NULL)
        {
            // Only write the stack trace if there is not one already in the exception.
            // When we exit managed try/finally and try/catch blocks with an exception, this method is
            // called with the original exception which already has the proper stack trace.
            // Getting the stack trace again here will lose the frames between the original throw
            // and the finally or catch block.
            const StackFrames& frames = *StackTrace::GetStackFrames();

            Il2CppArray* ips = NULL;
            Il2CppArray* raw_ips = NULL;
            size_t numberOfFrames = frames.size();
            if (numberOfFrames == 0 && lastManagedFrame != NULL)
            {
                // We didn't get any call stack. If we have one frame from codegen, use it.
                if (utils::DebugSymbolReader::DebugSymbolsAvailable())
                {
                    Il2CppStackFrame *stackFrame = (Il2CppStackFrame*)vm::Object::New(il2cpp_defaults.stack_frame_class);
                    IL2CPP_OBJECT_SETREF(stackFrame, method, vm::Reflection::GetMethodObject(lastManagedFrame, NULL));

                    ips = Array::New(il2cpp_defaults.stack_frame_class, 1);
                    il2cpp_array_setref(ips, 0, stackFrame);
                }
                else
                {
                    ips = Array::New(il2cpp_defaults.int_class, 1);
                    il2cpp_array_set(ips, const MethodInfo*, 0, lastManagedFrame);
                }
            }
            else
            {
                size_t i = numberOfFrames - 1;
                if (utils::DebugSymbolReader::DebugSymbolsAvailable())
                {
                    ips = Array::New(il2cpp_defaults.stack_frame_class, numberOfFrames);
                }
                else
                {
                    ips = Array::New(il2cpp_defaults.int_class, numberOfFrames);
                }

                raw_ips = Array::New(il2cpp_defaults.int_class, numberOfFrames);
                for (size_t frame = 0; frame != frames.size() && i >= 0; ++frame, --i)
                {
                    const Il2CppStackFrameInfo& stackFrameInfo = frames[frame];

                    if (utils::DebugSymbolReader::DebugSymbolsAvailable())
                    {
                        Il2CppStackFrame *stackFrame = (Il2CppStackFrame*)vm::Object::New(il2cpp_defaults.stack_frame_class);

                        IL2CPP_OBJECT_SETREF(stackFrame, method, vm::Reflection::GetMethodObject(stackFrameInfo.method, NULL));
                        stackFrame->line = stackFrameInfo.sourceCodeLineNumber;
                        stackFrame->il_offset = stackFrameInfo.ilOffset;
                        if (stackFrameInfo.filePath != NULL && strlen(stackFrameInfo.filePath) != 0)
                            IL2CPP_OBJECT_SETREF(stackFrame, filename, il2cpp::vm::String::New(stackFrameInfo.filePath));

                        il2cpp_array_setref(ips, i, stackFrame);
                    }
                    else
                    {
                        il2cpp_array_set(ips, const MethodInfo*, i, stackFrameInfo.method);
                    }
                    il2cpp_array_set(raw_ips, uintptr_t, i, stackFrameInfo.raw_ip);
                }
            }

            IL2CPP_ASSERT(ips != NULL);
            IL2CPP_OBJECT_SETREF(ex, trace_ips, ips);
            IL2CPP_OBJECT_SETREF(ex, native_trace_ips, raw_ips);
        }
#endif // !IL2CPP_TINY
    }

    NORETURN void Exception::Raise(Il2CppException* ex, MethodInfo* lastManagedFrame)
    {
        PrepareExceptionForThrow(ex, lastManagedFrame);
        throw Il2CppExceptionWrapper(ex);
    }

    NORETURN void Exception::Rethrow(Il2CppException* ex)
    {
        throw Il2CppExceptionWrapper(ex);
    }

    NORETURN void Exception::RaiseOutOfMemoryException()
    {
        RaiseOutOfMemoryException(utils::StringView<Il2CppChar>::Empty());
    }

    NORETURN void Exception::RaiseOutOfMemoryException(const utils::StringView<Il2CppChar>& msg)
    {
        Raise(GetOutOfMemoryException(msg));
    }

    NORETURN void Exception::RaiseNullReferenceException()
    {
        RaiseNullReferenceException(utils::StringView<Il2CppChar>::Empty());
    }

    NORETURN void Exception::RaiseNullReferenceException(const utils::StringView<Il2CppChar>& msg)
    {
        Raise(GetNullReferenceException(msg));
    }

    NORETURN void Exception::RaiseDivideByZeroException()
    {
        Raise(GetDivideByZeroException());
    }

    NORETURN void Exception::RaiseIndexOutOfRangeException()
    {
        Raise(GetIndexOutOfRangeException());
    }

    NORETURN void Exception::RaiseOverflowException()
    {
        Raise(GetOverflowException());
    }

    NORETURN void Exception::RaiseArgumentOutOfRangeException(const char* msg)
    {
        Raise(GetArgumentOutOfRangeException(msg));
    }

    static NORETURN void RaiseFromIl2CppError(const utils::Il2CppError& error)
    {
        utils::Il2CppErrorCode errorCode = error.GetErrorCode();
        if (errorCode == utils::NotSupported)
            Exception::Raise(Exception::GetNotSupportedException(error.GetErrorMessage().c_str()));
        if (errorCode == utils::ComError)
            Exception::Raise(error.GetHr(), false);
        if (errorCode == utils::UnauthorizedAccess)
            Exception::Raise(Exception::GetUnauthorizedAccessException(error.GetErrorMessage().c_str()));

        Exception::Raise(Exception::GetSystemException());
    }

    void Exception::RaiseIfError(const utils::Il2CppError& error)
    {
        if (error.GetErrorCode() != utils::NoError)
            RaiseFromIl2CppError(error);
    }

    inline static Il2CppException* TryGetExceptionFromRestrictedErrorInfo(Il2CppIRestrictedErrorInfo* errorInfo)
    {
        Il2CppILanguageExceptionErrorInfo* languageExceptionInfo;
        il2cpp_hresult_t hr = errorInfo->QueryInterface(Il2CppILanguageExceptionErrorInfo::IID, reinterpret_cast<void**>(&languageExceptionInfo));
        if (IL2CPP_HR_SUCCEEDED(hr))
        {
            Il2CppIUnknown* languageException;
            hr = languageExceptionInfo->GetLanguageException(&languageException);
            languageExceptionInfo->Release();

            if (IL2CPP_HR_SUCCEEDED(hr) && languageException != NULL) // It can succeed and return null exception if there's no exception info
            {
                Il2CppIManagedObjectHolder* managedObjectHolder;
                hr = languageException->QueryInterface(Il2CppIManagedObjectHolder::IID, reinterpret_cast<void**>(&managedObjectHolder));
                languageException->Release();

                if (IL2CPP_HR_SUCCEEDED(hr))
                {
                    Il2CppException* exception = reinterpret_cast<Il2CppException*>(managedObjectHolder->GetManagedObject());
                    managedObjectHolder->Release();

                    // TODO: set restricted error info instead of releaseing it here
                    errorInfo->Release();
                    return exception;
                }
            }
        }

        return NULL;
    }

    inline static UTF16String GetMessageFromRestrictedErrorInfo(Il2CppIRestrictedErrorInfo* errorInfo)
    {
        UTF16String result;
        il2cpp_hresult_t error;
        Il2CppChar* bstrDescription;
        Il2CppChar* bstrRestrictedDescription;
        Il2CppChar* bstrCapabilitySid;

        il2cpp_hresult_t hr = errorInfo->GetErrorDetails(&bstrDescription, &error, &bstrRestrictedDescription, &bstrCapabilitySid);
        if (IL2CPP_HR_SUCCEEDED(hr))
        {
            int descriptionLength = 0;
            int restrictedDescriptionLength = 0;

            if (bstrDescription != NULL)
                os::MarshalStringAlloc::GetBStringLength(bstrDescription, &descriptionLength);

            if (bstrRestrictedDescription != NULL)
                os::MarshalStringAlloc::GetBStringLength(bstrRestrictedDescription, &restrictedDescriptionLength);

            result.append(bstrDescription, descriptionLength);
            if (restrictedDescriptionLength > 0)
            {
                result.append(kIl2CppNewLine);
                result.append(bstrRestrictedDescription, restrictedDescriptionLength);
            }

            if (bstrDescription != NULL)
                os::MarshalStringAlloc::FreeBString(bstrDescription);

            if (bstrRestrictedDescription != NULL)
                os::MarshalStringAlloc::FreeBString(bstrRestrictedDescription);

            if (bstrCapabilitySid != NULL)
                os::MarshalStringAlloc::FreeBString(bstrCapabilitySid);
        }

        return result;
    }

// When doing COM interop, any unrecognized hresult gets turned into a COMException
// When doing Windows Runtime interop, any unrecognized hresult gets turned into a System.Exception
// Go figure.
    Il2CppException* Exception::Get(il2cpp_hresult_t hresult, bool defaultToCOMException)
    {
        UTF16String message;

        Il2CppIRestrictedErrorInfo* errorInfo = os::WindowsRuntime::GetRestrictedErrorInfo();
        if (errorInfo != NULL)
        {
            // First, try retrieving the original exception from restricted error info
            Il2CppException* exception = TryGetExceptionFromRestrictedErrorInfo(errorInfo);
            if (exception != NULL)
                return exception;

            // If we got here, restricted error info contained no existing managed exception
            message = GetMessageFromRestrictedErrorInfo(errorInfo);

            // To do: instead of releasing it here, store it on the exception that we're about to return
            errorInfo->Release();
        }

        switch (hresult)
        {
            case IL2CPP_E_NOTIMPL:
                return FromNameMsg(Image::GetCorlib(), "System", "NotImplementedException", STRING_TO_STRINGVIEW(message));

            case IL2CPP_E_NOINTERFACE:
                return GetInvalidCastException(STRING_TO_STRINGVIEW(message));

            case IL2CPP_E_POINTER:
                return GetNullReferenceException(STRING_TO_STRINGVIEW(message));

            case IL2CPP_COR_E_OPERATIONCANCELED:
                return FromNameMsg(Image::GetCorlib(), "System", "OperationCanceledException", STRING_TO_STRINGVIEW(message));

            case IL2CPP_E_ACCESS_DENIED:
                return GetUnauthorizedAccessException(STRING_TO_STRINGVIEW(message));

            case IL2CPP_E_OUTOFMEMORY:
                return GetOutOfMemoryException(STRING_TO_STRINGVIEW(message));

            case IL2CPP_E_INVALIDARG:
                return GetArgumentException(utils::StringView<Il2CppChar>::Empty(), STRING_TO_STRINGVIEW(message));

            case IL2CPP_COR_E_OBJECTDISPOSED:
            case IL2CPP_RO_E_CLOSED:
                return FromNameMsg(Image::GetCorlib(), "System", "ObjectDisposedException", STRING_TO_STRINGVIEW(message), hresult);

            case IL2CPP_E_FAIL:
            {
                if (message.empty())
                    message = utils::StringUtils::Utf8ToUtf16("Unspecified error");

                return FromNameMsg(Image::GetCorlib(), "System.Runtime.InteropServices", "COMException", STRING_TO_STRINGVIEW(message), hresult);
            }

            case IL2CPP_COR_E_PLATFORMNOTSUPPORTED:
            {
                if (message.empty())
                    message = utils::StringUtils::Utf8ToUtf16("Operation is not supported on this platform.");

                return GetPlatformNotSupportedException(STRING_TO_STRINGVIEW(message));
            }

            case IL2CPP_E_FILE_NOT_FOUND:
                return GetFileNotFoundException(STRING_TO_STRINGVIEW(message));

            default:
                return defaultToCOMException
                    ? Exception::FromNameMsg(vm::Image::GetCorlib(), "System.Runtime.InteropServices", "COMException", STRING_TO_STRINGVIEW(message), hresult)
                    : Exception::FromNameMsg(vm::Image::GetCorlib(), "System", "Exception", STRING_TO_STRINGVIEW(message), hresult);
        }
    }

    NORETURN void Exception::Raise(il2cpp_hresult_t hresult, bool defaultToCOMException)
    {
        Raise(Get(hresult, defaultToCOMException));
    }

    Il2CppException* Exception::FromNameMsg(const Il2CppImage* image, const char *name_space, const char *name, const char *msg)
    {
        UTF16String utf16Msg;

        if (msg != NULL)
            utf16Msg = utils::StringUtils::Utf8ToUtf16(msg);

        return FromNameMsg(image, name_space, name, STRING_TO_STRINGVIEW(utf16Msg));
    }

    Il2CppException* Exception::FromNameMsg(const Il2CppImage* image, const char* name_space, const char* name, const utils::StringView<Il2CppChar>& msg)
    {
        Il2CppClass* exceptionClass = Class::FromName(image, name_space, name);
        Il2CppException* ex = (Il2CppException*)Object::New(exceptionClass);
        Runtime::ObjectInit((Il2CppObject*)ex);

        if (msg.Length() > 0)
            IL2CPP_OBJECT_SETREF(ex, message, String::NewUtf16(msg));

        return ex;
    }

    Il2CppException* Exception::FromNameMsg(const Il2CppImage* image, const char *name_space, const char* name, const utils::StringView<Il2CppChar>& msg, il2cpp_hresult_t hresult)
    {
        Il2CppException* ex = FromNameMsg(image, name_space, name, msg);
        ex->hresult = hresult;
        return ex;
    }

    Il2CppException * Exception::GetArgumentException(const char *arg, const char *msg)
    {
        Il2CppException* ex = FromNameMsg(Image::GetCorlib(), "System", "ArgumentException", msg);

        if (arg)
        {
            Il2CppArgumentException *argex = (Il2CppArgumentException*)ex;
            IL2CPP_OBJECT_SETREF(argex, argName, String::New(arg));
        }

        return ex;
    }

    Il2CppException* Exception::GetArgumentException(const utils::StringView<Il2CppChar>& arg, const utils::StringView<Il2CppChar>& msg)
    {
        Il2CppException* ex = FromNameMsg(Image::GetCorlib(), "System", "ArgumentException", msg);

        if (arg.Length() > 0)
        {
            Il2CppArgumentException *argex = (Il2CppArgumentException*)ex;
            IL2CPP_OBJECT_SETREF(argex, argName, String::NewUtf16(arg));
        }

        return ex;
    }

    Il2CppException * Exception::GetArgumentNullException(const char *arg)
    {
        Il2CppException* ex = FromNameMsg(Image::GetCorlib(), "System", "ArgumentNullException", NULL);

        if (arg)
        {
            Il2CppArgumentException *argex = (Il2CppArgumentException*)ex;
            IL2CPP_OBJECT_SETREF(argex, argName, String::New(arg));
        }

        return ex;
    }

    Il2CppException * Exception::GetArgumentOutOfRangeException(const char *arg)
    {
        Il2CppException* ex = FromNameMsg(Image::GetCorlib(), "System", "ArgumentOutOfRangeException", NULL);

        if (arg)
        {
            Il2CppArgumentException *argex = (Il2CppArgumentException*)ex;
            IL2CPP_OBJECT_SETREF(argex, argName, String::New(arg));
        }

        return ex;
    }

    Il2CppException * Exception::GetTypeInitializationException(const char *msg, Il2CppException* innerException)
    {
        Il2CppException* ex = FromNameMsg(Image::GetCorlib(), "System", "TypeInitializationException", msg);

        if (innerException != NULL)
            IL2CPP_OBJECT_SETREF(ex, inner_ex, innerException);

        return ex;
    }

    Il2CppException* Exception::GetInvalidCastException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "InvalidCastException", msg);
    }

    Il2CppException* Exception::GetInvalidCastException(const utils::StringView<Il2CppChar>& msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "InvalidCastException", msg);
    }

    Il2CppException* Exception::GetIndexOutOfRangeException()
    {
        return GetIndexOutOfRangeException(utils::StringView<Il2CppChar>::Empty());
    }

    Il2CppException* Exception::GetIndexOutOfRangeException(const utils::StringView<Il2CppChar>& msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "IndexOutOfRangeException", msg);
    }

    Il2CppException* Exception::GetNullReferenceException(const utils::StringView<Il2CppChar>& msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "NullReferenceException", msg);
    }

    Il2CppException* Exception::GetTypeLoadException()
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "TypeLoadException", NULL);
    }

    Il2CppException* Exception::GetTypeLoadException(const TypeNameParseInfo& info)
    {
        std::string assemblyNameStr;
        const TypeNameParseInfo::AssemblyName& assemblyName = info.assembly_name();

        if (!assemblyName.name.empty())
        {
            utils::VmStringUtils::CaseInsensitiveComparer comparer;
            if (comparer(assemblyName.name, "WindowsRuntimeMetadata"))
                return GetTypeLoadExceptionForWindowsRuntimeType(STRING_TO_STRINGVIEW(info.ns()), STRING_TO_STRINGVIEW(info.name()));

            assemblyNameStr += assemblyName.name;
            assemblyNameStr += ", Version=";

            const size_t bufferSize = 16;
            char buffer[bufferSize];
            snprintf(buffer, bufferSize, "%d.", assemblyName.major);
            assemblyNameStr += buffer;
            snprintf(buffer, bufferSize, "%d.", assemblyName.minor);
            assemblyNameStr += buffer;
            snprintf(buffer, bufferSize, "%d.", assemblyName.build);
            assemblyNameStr += buffer;
            snprintf(buffer, bufferSize, "%d", assemblyName.revision);
            assemblyNameStr += buffer;

            if (!assemblyName.culture.empty())
            {
                assemblyNameStr += ", Culture=";
                assemblyNameStr += assemblyName.culture;
                assemblyNameStr += ", PublicKeyToken=";
            }
            else
            {
                assemblyNameStr += ", Culture=neutral, PublicKeyToken=";
            }

            assemblyNameStr += assemblyName.public_key_token[0] ? assemblyName.public_key_token : "null";
        }

        return GetTypeLoadException(STRING_TO_STRINGVIEW(info.ns()), STRING_TO_STRINGVIEW(info.name()), STRING_TO_STRINGVIEW(assemblyNameStr));
    }

    Il2CppException* Exception::GetTypeLoadException(const utils::StringView<char>& namespaze, const utils::StringView<char>& typeName, const utils::StringView<char>& assemblyName)
    {
        std::string exceptionMessage = "Could not load type '";

        if (!namespaze.IsEmpty())
        {
            exceptionMessage.append(namespaze.Str(), namespaze.Length());
            exceptionMessage.push_back('.');
        }

        exceptionMessage.append(typeName.Str(), typeName.Length());
        exceptionMessage += "' from assembly '";

        if (assemblyName.IsEmpty())
        {
            exceptionMessage += AssemblyName::AssemblyNameToString(Image::GetAssembly(Image::GetCorlib())->aname);
        }
        else
        {
            exceptionMessage.append(assemblyName.Str(), assemblyName.Length());
        }

        exceptionMessage += "'.";
        return Exception::GetTypeLoadException(exceptionMessage.c_str());
    }

    Il2CppException* Exception::GetTypeLoadExceptionForWindowsRuntimeType(const utils::StringView<char>& namespaze, const utils::StringView<char>& typeName)
    {
        std::string typeLoadExceptionMessage = "Could not find Windows Runtime type '";

        if (namespaze.Length() != 0)
        {
            typeLoadExceptionMessage.append(namespaze.Str(), namespaze.Length());
            typeLoadExceptionMessage.push_back('.');
        }

        typeLoadExceptionMessage.append(typeName.Str(), typeName.Length());
        typeLoadExceptionMessage += "'.";

        Il2CppException* typeLoadException = Exception::GetTypeLoadException(typeLoadExceptionMessage.c_str());

        // If there's no '.' in neither typeName and namespace specified, it means there is no namespace specified
        // Therefore exception information should contain inner exception saying format is not recognized
        if (namespaze.Length() == 0 && typeName.Find('.') == utils::StringView<char>::NPos())
        {
            const char kInnerExceptionMessage[] = "The provided identity format is not recognized. (Exception from HRESULT: 0x80132003)";
            Il2CppException* innerException = Exception::GetArgumentException("", kInnerExceptionMessage);
            innerException->hresult = 0x80132003;
            IL2CPP_OBJECT_SETREF(typeLoadException, inner_ex, innerException);
        }

        return typeLoadException;
    }

    Il2CppException* Exception::GetOutOfMemoryException(const utils::StringView<Il2CppChar>& msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "OutOfMemoryException", msg);
    }

    Il2CppException* Exception::GetOverflowException()
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "OverflowException", NULL);
    }

    Il2CppException* Exception::GetOverflowException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "OverflowException", msg);
    }

    Il2CppException* Exception::GetFormatException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "FormatException", msg);
    }

    Il2CppException* Exception::GetSystemException()
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "SystemException", NULL);
    }

    Il2CppException* Exception::GetNotSupportedException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "NotSupportedException", msg);
    }

    Il2CppException* Exception::GetArrayTypeMismatchException()
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "ArrayTypeMismatchException", NULL);
    }

    Il2CppException* Exception::GetTypeLoadException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "TypeLoadException", msg);
    }

    Il2CppException* Exception::GetEntryPointNotFoundException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "EntryPointNotFoundException", msg);
    }

    Il2CppException* Exception::GetAmbiguousImplementationException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System.Runtime", "AmbiguousImplementationException", msg);
    }

    Il2CppException* Exception::GetDllNotFoundException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "DllNotFoundException", msg);
    }

    Il2CppException * Exception::GetInvalidOperationException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "InvalidOperationException", msg);
    }

    Il2CppException* Exception::GetThreadInterruptedException()
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System.Threading", "ThreadInterruptedException", NULL);
    }

    Il2CppException* Exception::GetThreadAbortException()
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System.Threading", "ThreadAbortException", NULL);
    }

    Il2CppException* Exception::GetThreadStateException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System.Threading", "ThreadStateException", msg);
    }

    Il2CppException* Exception::GetSynchronizationLockException(const char* msg)
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System.Threading", "SynchronizationLockException", msg);
    }

    Il2CppException * Exception::GetMissingMethodException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "MissingMethodException", msg);
    }

    Il2CppException * Exception::GetMarshalDirectiveException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System.Runtime.InteropServices", "MarshalDirectiveException", msg);
    }

    Il2CppException * Exception::GetTargetException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System.Reflection", "TargetException", msg);
    }

    Il2CppException* Exception::GetMethodAccessException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "MethodAccessException", msg);
    }

    Il2CppException * Exception::GetExecutionEngineException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "ExecutionEngineException", msg);
    }

    Il2CppException* Exception::GetUnauthorizedAccessException(const utils::StringView<Il2CppChar>& msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "UnauthorizedAccessException", msg);
    }

    Il2CppException* Exception::GetUnauthorizedAccessException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "UnauthorizedAccessException", msg);
    }

    Il2CppException * Exception::GetMaximumNestedGenericsException()
    {
        int currentLimit = metadata::GenericMetadata::GetMaximumRuntimeGenericDepth();
        return GetNotSupportedException(utils::StringUtils::Printf(MAXIMUM_NESTED_GENERICS_EXCEPTION_MESSAGE, currentLimit).c_str());
    }

    Il2CppException* Exception::GetDivideByZeroException()
    {
        return FromNameMsg(vm::Image::GetCorlib(), "System", "DivideByZeroException", NULL);
    }

    Il2CppException* Exception::GetPlatformNotSupportedException(const utils::StringView<Il2CppChar>& msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "PlatformNotSupportedException", msg);
    }

    Il2CppException* Exception::GetFileLoadException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System.IO", "FileLoadException", msg);
    }

    Il2CppException* Exception::GetFileNotFoundException(const utils::StringView<Il2CppChar>& msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System.IO", "FileNotFoundException", msg);
    }

    Il2CppException* Exception::GetStackOverflowException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "StackOverflowException", msg);
    }

    Il2CppException* Exception::GetBadImageFormatException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "BadImageFormatException", msg);
    }

    Il2CppException* Exception::GetMissingFieldException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System", "MissingFieldException", msg);
    }

    Il2CppException* Exception::GetCustomAttributeFormatException(const char* msg)
    {
        return FromNameMsg(Image::GetCorlib(), "System.Reflection", "CustomAttributeFormatException", msg);
    }
    void Exception::StoreExceptionInfo(Il2CppException* ex, Il2CppString* exceptionString)
    {
        // To do: try retrieving IRestrictedErrorInfo here
        os::WindowsRuntime::OriginateLanguageException(ex->hresult, ex, exceptionString, CCW::GetOrCreate);
    }
} /* namespace vm */
} /* namespace il2cpp */
