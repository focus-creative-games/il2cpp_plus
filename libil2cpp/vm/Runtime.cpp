#include "il2cpp-config.h"
#include "metadata/GenericMethod.h"
#include "os/CrashHelpers.h"
#include "os/Environment.h"
#include "os/File.h"
#include "os/Image.h"
#include "os/Initialize.h"
#include "os/LibraryLoader.h"
#include "os/Locale.h"
#include "os/MemoryMappedFile.h"
#include "os/Mutex.h"
#include "os/Path.h"
#include "os/SynchronizationContext.h"
#include "os/Thread.h"
#include "os/Socket.h"
#include "os/c-api/Allocator.h"
#include "metadata/GenericMetadata.h"
#include "vm/Array.h"
#include "vm/Assembly.h"
#include "vm/ClassLibraryPAL.h"
#include "vm/COMEntryPoints.h"
#include "vm/Class.h"
#include "vm/Domain.h"
#include "vm/Exception.h"
#include "vm/Field.h"
#include "gc/GCHandle.h"
#include "vm/Image.h"
#include "vm/LastError.h"
#include "vm/MetadataAlloc.h"
#include "vm/MetadataCache.h"
#include "vm/MetadataLock.h"
#include "vm/Method.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/Thread.h"
#include "vm/Type.h"
#include "vm/StackTrace.h"
#include "vm/String.h"
#include "vm/Object.h"
#include "vm-utils/Debugger.h"
#include "vm-utils/DebugSymbolReader.h"
#include "vm/Profiler.h"
#include "utils/Logging.h"
#include <string>
#include <map>
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "il2cpp-tabledefs.h"
#include "gc/GarbageCollector.h"
#include "gc/WriteBarrier.h"
#include "vm/InternalCalls.h"
#include "utils/Collections.h"
#include "utils/Memory.h"
#include "utils/StringUtils.h"
#include "utils/PathUtils.h"
#include "utils/Runtime.h"
#include "utils/Environment.h"
#include "mono/ThreadPool/threadpool-ms.h"
#include "mono/ThreadPool/threadpool-ms-io.h"
//#include "icalls/mscorlib/System.Reflection/Assembly.h"

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"

#include "hybridclr/Runtime.h"
#include "hybridclr/Il2CppCompatibleDef.h"

Il2CppDefaults il2cpp_defaults;
bool g_il2cpp_is_fully_initialized = false;
static bool shutting_down = false;

MetadataInitializerCleanupFunc g_ClearMethodMetadataInitializedFlags = NULL;

static baselib::ReentrantLock s_InitLock;
static int32_t s_RuntimeInitCount;

typedef void (*CodegenRegistrationFunction) ();
extern CodegenRegistrationFunction g_CodegenRegistration;

namespace il2cpp
{
namespace vm
{
    baselib::ReentrantLock g_MetadataLock;

    static int32_t exitcode = 0;
    static std::string s_ConfigDir;
    static const char *s_FrameworkVersion = 0;
    static const char *s_BundledMachineConfig = 0;
    static Il2CppRuntimeUnhandledExceptionPolicy s_UnhandledExceptionPolicy = IL2CPP_UNHANDLED_POLICY_CURRENT;
    static const void* s_UnitytlsInterface = NULL;

#define DEFAULTS_INIT(field, ns, n) do { il2cpp_defaults.field = Class::FromName (il2cpp_defaults.corlib, ns, n);\
    IL2CPP_ASSERT(il2cpp_defaults.field); } while (0)

#define DEFAULTS_INIT_TYPE(field, ns, n, nativetype) do { DEFAULTS_INIT(field, ns, n); \
    IL2CPP_ASSERT(il2cpp_defaults.field->instance_size == sizeof(nativetype) + (il2cpp_defaults.field->byval_arg.valuetype ? sizeof(Il2CppObject) : 0)); } while (0)

#define DEFAULTS_INIT_OPTIONAL(field, ns, n) do { il2cpp_defaults.field = Class::FromName (il2cpp_defaults.corlib, ns, n); } while (0)

#define DEFAULTS_INIT_TYPE_OPTIONAL(field, ns, n, nativetype) do { DEFAULTS_INIT_OPTIONAL(field, ns, n); \
    if (il2cpp_defaults.field != NULL) \
        IL2CPP_ASSERT(il2cpp_defaults.field->instance_size == sizeof(nativetype) + (il2cpp_defaults.field->byval_arg.valuetype ? sizeof(Il2CppObject) : 0)); } while (0)

#define DEFAULTS_GEN_INIT(field, ns, n) do { il2cpp_defaults.field = Class::FromName (il2cpp_defaults.corlib_gen, ns, n);\
    IL2CPP_ASSERT(il2cpp_defaults.field); } while (0)

#define DEFAULTS_GEN_INIT_TYPE(field, ns, n, nativetype) do { DEFAULTS_GEN_INIT(field, ns, n); \
    IL2CPP_ASSERT(il2cpp_defaults.field->instance_size == sizeof(nativetype) + (il2cpp_defaults.field->byval_arg.valuetype ? sizeof(Il2CppObject) : 0)); } while (0)

#define DEFAULTS_GEN_INIT_OPTIONAL(field, ns, n) do { il2cpp_defaults.field = Class::FromName (il2cpp_defaults.corlib_gen, ns, n); } while (0)

    char* basepath(const char* path)
    {
        std::string original_path(path);
        size_t position_of_last_separator = original_path.find_last_of(IL2CPP_DIR_SEPARATOR);

        return il2cpp::utils::StringUtils::StringDuplicate(original_path.substr(position_of_last_separator + 1).c_str());
    }

    static const char *framework_version_for(const char *runtime_version)
    {
        IL2CPP_ASSERT(runtime_version && "Invalid runtime version");

        IL2CPP_ASSERT((strstr(runtime_version, "v4.0") == runtime_version) && "Invalid runtime version");
        return "4.0";
    }

    static void SanityChecks()
    {
#if IL2CPP_ENABLE_INTERLOCKED_64_REQUIRED_ALIGNMENT
        IL2CPP_ASSERT(ALIGN_OF(int64_t) == 8);
#endif
    }

    static inline void InitializeStringEmpty()
    {
        Class::Init(il2cpp_defaults.string_class);
        FieldInfo* stringEmptyField = Class::GetFieldFromName(il2cpp_defaults.string_class, "Empty");
        Field::StaticSetValue(stringEmptyField, String::Empty());
    }

    static void SetConfigStr(const std::string& executablePath);

    bool Runtime::Init(const char* domainName)
    {
        os::FastAutoLock lock(&s_InitLock);

        IL2CPP_ASSERT(s_RuntimeInitCount >= 0);
        if (s_RuntimeInitCount++ > 0)
            return true;

        SanityChecks();

        os::Initialize();
        os::Locale::Initialize();
        MetadataAllocInitialize();

        // NOTE(gab): the runtime_version needs to change once we
        // will support multiple runtimes.
        // For now we default to the one used by unity and don't
        // allow the callers to change it.
        s_FrameworkVersion = framework_version_for("v4.0.30319");

        os::Image::Initialize();
        os::Thread::Init();

#if IL2CPP_HAS_OS_SYNCHRONIZATION_CONTEXT
        // Has to happen after Thread::Init() due to it needing a COM apartment on Windows
        il2cpp::os::SynchronizationContext::Initialize();
#endif

        // This should be filled in by generated code.
        IL2CPP_ASSERT(g_CodegenRegistration != NULL);
        g_CodegenRegistration();

        if (!MetadataCache::Initialize())
        {
            s_RuntimeInitCount--;
            return false;
        }

        Assembly::Initialize();
        gc::GarbageCollector::Initialize();

        // Thread needs GC initialized
        Thread::Initialize();

        register_allocator(il2cpp::utils::Memory::Malloc, il2cpp::utils::Memory::Free);

        memset(&il2cpp_defaults, 0, sizeof(Il2CppDefaults));

        const Il2CppAssembly* assembly = Assembly::Load("mscorlib.dll");
        const Il2CppAssembly* assembly2 = Assembly::Load("__Generated");

        // It is not possible to use DEFAULTS_INIT_TYPE for managed types for which we have a native struct, if the
        // native struct does not map the complete managed type.
        // Which is the case for: Il2CppThread, Il2CppAppDomain, Il2CppCultureInfo, Il2CppReflectionProperty,
        // Il2CppDateTimeFormatInfo, Il2CppNumberFormatInfo

        il2cpp_defaults.corlib = Assembly::GetImage(assembly);
        il2cpp_defaults.corlib_gen = Assembly::GetImage(assembly2);
        DEFAULTS_INIT(object_class, "System", "Object");
        DEFAULTS_INIT(void_class, "System", "Void");
        DEFAULTS_INIT_TYPE(boolean_class, "System", "Boolean", bool);
        DEFAULTS_INIT_TYPE(byte_class, "System", "Byte", uint8_t);
        DEFAULTS_INIT_TYPE(sbyte_class, "System", "SByte", int8_t);
        DEFAULTS_INIT_TYPE(int16_class, "System", "Int16", int16_t);
        DEFAULTS_INIT_TYPE(uint16_class, "System", "UInt16", uint16_t);
        DEFAULTS_INIT_TYPE(int32_class, "System", "Int32", int32_t);
        DEFAULTS_INIT_TYPE(uint32_class, "System", "UInt32", uint32_t);
        DEFAULTS_INIT(uint_class, "System", "UIntPtr");
        DEFAULTS_INIT_TYPE(int_class, "System", "IntPtr", intptr_t);
        DEFAULTS_INIT_TYPE(int64_class, "System", "Int64", int64_t);
        DEFAULTS_INIT_TYPE(uint64_class, "System", "UInt64", uint64_t);
        DEFAULTS_INIT_TYPE(single_class, "System", "Single", float);
        DEFAULTS_INIT_TYPE(double_class, "System", "Double", double);
        DEFAULTS_INIT_TYPE(char_class, "System", "Char", Il2CppChar);
        DEFAULTS_INIT(string_class, "System", "String");
        DEFAULTS_INIT(enum_class, "System", "Enum");
        DEFAULTS_INIT(array_class, "System", "Array");
        DEFAULTS_INIT(value_type_class, "System", "ValueType");
#if !IL2CPP_TINY
        DEFAULTS_INIT_TYPE(delegate_class, "System", "Delegate", Il2CppDelegate);
        DEFAULTS_INIT_TYPE(multicastdelegate_class, "System", "MulticastDelegate", Il2CppMulticastDelegate);
        DEFAULTS_INIT(asyncresult_class, "System.Runtime.Remoting.Messaging", "AsyncResult");
        DEFAULTS_INIT_TYPE(async_call_class, "System", "MonoAsyncCall", Il2CppAsyncCall);
        DEFAULTS_INIT(manualresetevent_class, "System.Threading", "ManualResetEvent");
#endif // !IL2CPP_TINY
        //DEFAULTS_INIT(typehandle_class, "System", "RuntimeTypeHandle");
        //DEFAULTS_INIT(methodhandle_class, "System", "RuntimeMethodHandle");
        //DEFAULTS_INIT(fieldhandle_class, "System", "RuntimeFieldHandle");
        DEFAULTS_INIT(systemtype_class, "System", "Type");
#if !IL2CPP_TINY
        DEFAULTS_INIT_TYPE(monotype_class, "System", "MonoType", Il2CppReflectionMonoType);
#endif
        //DEFAULTS_INIT(exception_class, "System", "Exception");
        //DEFAULTS_INIT(threadabortexcepXtion_class, "System.Threading", "ThreadAbortException");
        DEFAULTS_INIT_TYPE(thread_class, "System.Threading", "Thread", Il2CppThread);
        DEFAULTS_INIT_TYPE(internal_thread_class, "System.Threading", "InternalThread", Il2CppInternalThread);
        DEFAULTS_INIT_TYPE(runtimetype_class, "System", "RuntimeType", Il2CppReflectionRuntimeType);
#if !IL2CPP_TINY
        DEFAULTS_INIT(appdomain_class, "System", "AppDomain");
        DEFAULTS_INIT(appdomain_setup_class, "System", "AppDomainSetup");
        DEFAULTS_INIT(member_info_class, "System.Reflection", "MemberInfo");
        DEFAULTS_INIT(field_info_class, "System.Reflection", "FieldInfo");
        DEFAULTS_INIT(method_info_class, "System.Reflection", "MethodInfo");
        DEFAULTS_INIT(property_info_class, "System.Reflection", "PropertyInfo");
        DEFAULTS_INIT_TYPE(event_info_class, "System.Reflection", "EventInfo", Il2CppReflectionEvent);
        DEFAULTS_INIT_TYPE(stringbuilder_class, "System.Text", "StringBuilder", Il2CppStringBuilder);
        DEFAULTS_INIT_TYPE(stack_frame_class, "System.Diagnostics", "StackFrame", Il2CppStackFrame);
        DEFAULTS_INIT(stack_trace_class, "System.Diagnostics", "StackTrace");
        DEFAULTS_INIT_TYPE(typed_reference_class, "System", "TypedReference", Il2CppTypedRef);
#endif
        DEFAULTS_INIT(generic_ilist_class, "System.Collections.Generic", "IList`1");
        DEFAULTS_INIT(generic_icollection_class, "System.Collections.Generic", "ICollection`1");
        DEFAULTS_INIT(generic_ienumerable_class, "System.Collections.Generic", "IEnumerable`1");
        DEFAULTS_INIT(generic_ireadonlylist_class, "System.Collections.Generic", "IReadOnlyList`1");
        DEFAULTS_INIT(generic_ireadonlycollection_class, "System.Collections.Generic", "IReadOnlyCollection`1");
        DEFAULTS_INIT(generic_nullable_class, "System", "Nullable`1");
#if !IL2CPP_TINY
        DEFAULTS_INIT(version, "System", "Version");
        DEFAULTS_INIT(culture_info, "System.Globalization", "CultureInfo");
        DEFAULTS_INIT_TYPE(assembly_class, "System.Reflection", "RuntimeAssembly", Il2CppReflectionAssembly);
        DEFAULTS_INIT_TYPE_OPTIONAL(assembly_name_class, "System.Reflection", "AssemblyName", Il2CppReflectionAssemblyName);
        DEFAULTS_INIT_TYPE(parameter_info_class, "System.Reflection", "RuntimeParameterInfo", Il2CppReflectionParameter);
        DEFAULTS_INIT_TYPE(module_class, "System.Reflection", "RuntimeModule", Il2CppReflectionModule);
        DEFAULTS_INIT_TYPE(exception_class, "System", "Exception", Il2CppException);
        DEFAULTS_INIT_TYPE(system_exception_class, "System", "SystemException", Il2CppSystemException);
        DEFAULTS_INIT_TYPE(argument_exception_class, "System", "ArgumentException", Il2CppArgumentException);
        DEFAULTS_INIT_TYPE(marshalbyrefobject_class, "System", "MarshalByRefObject", Il2CppMarshalByRefObject);
        DEFAULTS_GEN_INIT_TYPE(il2cpp_com_object_class, "System", "__Il2CppComObject", Il2CppComObject);
        DEFAULTS_INIT_TYPE(safe_handle_class, "System.Runtime.InteropServices", "SafeHandle", Il2CppSafeHandle);
        DEFAULTS_INIT_TYPE(sort_key_class, "System.Globalization", "SortKey", Il2CppSortKey);
        DEFAULTS_INIT(dbnull_class, "System", "DBNull");
        DEFAULTS_INIT_TYPE_OPTIONAL(error_wrapper_class, "System.Runtime.InteropServices", "ErrorWrapper", Il2CppErrorWrapper);
        DEFAULTS_INIT(missing_class, "System.Reflection", "Missing");
        DEFAULTS_INIT(attribute_class, "System", "Attribute");
        DEFAULTS_INIT_OPTIONAL(customattribute_data_class, "System.Reflection", "CustomAttributeData");
        DEFAULTS_INIT_OPTIONAL(customattribute_typed_argument_class, "System.Reflection", "CustomAttributeTypedArgument");
        DEFAULTS_INIT_OPTIONAL(customattribute_named_argument_class, "System.Reflection", "CustomAttributeNamedArgument");
        DEFAULTS_INIT(key_value_pair_class, "System.Collections.Generic", "KeyValuePair`2");
        DEFAULTS_INIT(system_guid_class, "System", "Guid");
#endif // !IL2CPP_TINY

#if !IL2CPP_TINY
        DEFAULTS_INIT(threadpool_wait_callback_class, "System.Threading", "_ThreadPoolWaitCallback");
        DEFAULTS_INIT(mono_method_message_class, "System.Runtime.Remoting.Messaging", "MonoMethodMessage");

        il2cpp_defaults.threadpool_perform_wait_callback_method = (MethodInfo*)vm::Class::GetMethodFromName(
            il2cpp_defaults.threadpool_wait_callback_class, "PerformWaitCallback", 0);
#endif

        DEFAULTS_INIT_OPTIONAL(sbyte_shared_enum, "System", "SByteEnum");
        DEFAULTS_INIT_OPTIONAL(int16_shared_enum, "System", "Int16Enum");
        DEFAULTS_INIT_OPTIONAL(int32_shared_enum, "System", "Int32Enum");
        DEFAULTS_INIT_OPTIONAL(int64_shared_enum, "System", "Int64Enum");

        DEFAULTS_INIT_OPTIONAL(byte_shared_enum, "System", "ByteEnum");
        DEFAULTS_INIT_OPTIONAL(uint16_shared_enum, "System", "UInt16Enum");
        DEFAULTS_INIT_OPTIONAL(uint32_shared_enum, "System", "UInt32Enum");
        DEFAULTS_INIT_OPTIONAL(uint64_shared_enum, "System", "UInt64Enum");

        DEFAULTS_GEN_INIT_OPTIONAL(il2cpp_fully_shared_type, "Unity.IL2CPP.Metadata", "__Il2CppFullySharedGenericType");
        DEFAULTS_GEN_INIT_OPTIONAL(il2cpp_fully_shared_struct_type, "Unity.IL2CPP.Metadata", "__Il2CppFullySharedGenericStructType");

        ClassLibraryPAL::Initialize();

        // Reflection needs GC initialized
        Reflection::Initialize();

        Image::InitNestedTypes(il2cpp_defaults.corlib);

        const Il2CppAssembly* systemDll = Assembly::Load("System");
        if (systemDll != NULL)
            il2cpp_defaults.system_uri_class = Class::FromName(Assembly::GetImage(systemDll), "System", "Uri");

        // This will only exist if there was at least 1 winmd file present during conversion
        const Il2CppAssembly* windowsRuntimeMetadataAssembly = Assembly::Load("WindowsRuntimeMetadata");
        if (windowsRuntimeMetadataAssembly != NULL)
        {
            const Il2CppImage* windowsRuntimeMetadataImage = Assembly::GetImage(windowsRuntimeMetadataAssembly);
            il2cpp_defaults.ireference_class = Class::FromName(windowsRuntimeMetadataImage, "Windows.Foundation", "IReference`1");
            il2cpp_defaults.ireferencearray_class = Class::FromName(windowsRuntimeMetadataImage, "Windows.Foundation", "IReferenceArray`1");
            il2cpp_defaults.ikey_value_pair_class = Class::FromName(windowsRuntimeMetadataImage, "Windows.Foundation.Collections", "IKeyValuePair`2");
            il2cpp_defaults.ikey_value_pair_class = Class::FromName(windowsRuntimeMetadataImage, "Windows.Foundation.Collections", "IKeyValuePair`2");
            il2cpp_defaults.windows_foundation_uri_class = Class::FromName(windowsRuntimeMetadataImage, "Windows.Foundation", "Uri");
            il2cpp_defaults.windows_foundation_iuri_runtime_class_class = Class::FromName(windowsRuntimeMetadataImage, "Windows.Foundation", "IUriRuntimeClass");
        }

        Class::Init(il2cpp_defaults.string_class);

        os::Socket::Startup();

#if IL2CPP_MONO_DEBUGGER
        il2cpp::utils::Debugger::Init();
#endif

        Il2CppDomain* domain = Domain::GetCurrent();

        Il2CppThread* mainThread = Thread::Attach(domain);
        Thread::SetMain(mainThread);

#if !IL2CPP_TINY
        Il2CppAppDomainSetup* setup = (Il2CppAppDomainSetup*)Object::NewPinned(il2cpp_defaults.appdomain_setup_class);

        Il2CppAppDomain* ad = (Il2CppAppDomain*)Object::NewPinned(il2cpp_defaults.appdomain_class);
        gc::WriteBarrier::GenericStore(&ad->data, domain);
        gc::WriteBarrier::GenericStore(&domain->domain, ad);
        gc::WriteBarrier::GenericStore(&domain->setup, setup);
#endif

        domain->domain_id = 1; // Only have a single domain ATM.

        domain->friendly_name = basepath(domainName);

        LastError::InitializeLastErrorThreadStatic();

        gc::GarbageCollector::InitializeFinalizer();

        MetadataCache::InitializeGCSafe();

        String::InitializeEmptyString(il2cpp_defaults.string_class);
        InitializeStringEmpty();

        g_il2cpp_is_fully_initialized = true;

        // Force binary serialization in Mono to use reflection instead of code generation.
    #undef SetEnvironmentVariable // Get rid of windows.h #define.
        os::Environment::SetEnvironmentVariable("MONO_REFLECTION_SERIALIZER", "yes");
        os::Environment::SetEnvironmentVariable("MONO_XMLSERIALIZER_THS", "no");

#if !IL2CPP_TINY
        Domain::ContextInit(domain);
        Domain::ContextSet(domain->default_context);
#endif

        VerifyApiVersion();

#if IL2CPP_MONO_DEBUGGER
        il2cpp::utils::Debugger::Start();
#endif

        std::string executablePath = os::Path::GetExecutablePath();
        SetConfigStr(executablePath);

        if (utils::Environment::GetNumMainArgs() == 0)
        {
            // If main args were never set, we default to 1 arg that is the executable path
            const char* mainArgs[] = { executablePath.c_str() };
            utils::Environment::SetMainArgs(mainArgs, 1);
        }

        vm::MetadataCache::ExecuteEagerStaticClassConstructors();
        vm::MetadataCache::ExecuteModuleInitializers();

#if !IL2CPP_TINY && !IL2CPP_MONO_DEBUGGER
        il2cpp::utils::DebugSymbolReader::LoadDebugSymbols();
#endif

        hybridclr::Runtime::Initialize();
        return true;
    }

    static Il2CppObject* GetEventArgsEmptyField()
    {
        Il2CppClass* eventArgsKlass = Class::FromName(il2cpp_defaults.corlib, "System", "EventArgs");
        if (eventArgsKlass != NULL)
        {
            Class::Init(eventArgsKlass);
            FieldInfo* emptyField = vm::Class::GetFieldFromName(eventArgsKlass, "Empty");
            if (emptyField != NULL)
            {
                Il2CppObject* emptyValue;
                vm::Field::StaticGetValue(emptyField, &emptyValue);

                return emptyValue;
            }
        }

        return NULL;
    }

    static void FireProcessExitEvent()
    {
        FieldInfo* processExitField = vm::Class::GetFieldFromName(il2cpp_defaults.appdomain_class, "ProcessExit");
        if (processExitField != NULL) // The field might have been stripped, just ignore it.
        {
            Il2CppAppDomain* appDomain = vm::Domain::GetCurrent()->domain;
            Il2CppDelegate* processExitDelegate;
            vm::Field::GetValue((Il2CppObject*)appDomain, processExitField, &processExitDelegate);
            if (processExitDelegate == NULL) // Don't call the delegate if no one is listening to it.
                return;

            void* args[2];
            args[0] = appDomain;
            args[1] = GetEventArgsEmptyField();
            Il2CppException* unusedException;
            Runtime::DelegateInvoke(processExitDelegate, args, &unusedException);
        }
    }

    void Runtime::Shutdown()
    {
        os::FastAutoLock lock(&s_InitLock);

        IL2CPP_ASSERT(s_RuntimeInitCount > 0);
        if (--s_RuntimeInitCount > 0)
            return;

        FireProcessExitEvent();

        shutting_down = true;

#if IL2CPP_ENABLE_PROFILER
        il2cpp::vm::Profiler::Shutdown();
#endif
#if IL2CPP_MONO_DEBUGGER
        il2cpp::utils::Debugger::RuntimeShutdownEnd();
#endif

#if IL2CPP_SUPPORT_THREADS
        threadpool_ms_cleanup();
#endif

        // Tries to abort all threads
        // Threads at alertable waits may not have existing when this return
        Thread::AbortAllThreads();

        os::Socket::Cleanup();
        String::CleanupEmptyString();

        il2cpp::gc::GarbageCollector::UninitializeFinalizers();

        // after the gc cleanup so the finalizer thread can unregister itself
        Thread::Uninitialize();

#if IL2CPP_HAS_OS_SYNCHRONIZATION_CONTEXT
        // Has to happen before os::Thread::Shutdown() due to it needing a COM apartment on Windows
        il2cpp::os::SynchronizationContext::Shutdown();
#endif

        os::Thread::Shutdown();

#if IL2CPP_ENABLE_RELOAD
        MetadataCache::Clear();
#endif

        // We need to do this after thread shut down because it is freeing GC fixed memory
        il2cpp::gc::GarbageCollector::UninitializeGC();

        // This needs to happen after no managed code can run anymore, including GC finalizers
        os::LibraryLoader::CleanupLoadedLibraries();

        vm::Image::ClearCachedResourceData();
        MetadataAllocCleanup();

        vm::COMEntryPoints::FreeCachedData();

        os::Locale::UnInitialize();
        os::Uninitialize();

        Reflection::ClearStatics();

#if IL2CPP_ENABLE_RELOAD
        if (g_ClearMethodMetadataInitializedFlags != NULL)
            g_ClearMethodMetadataInitializedFlags();
#endif
    }

    bool Runtime::IsShuttingDown()
    {
        return shutting_down;
    }

    void Runtime::SetConfigDir(const char *path)
    {
        s_ConfigDir = path;
    }

    static void SetConfigStr(const std::string& executablePath)
    {
#if !IL2CPP_TINY
        Il2CppDomain* domain = vm::Domain::GetCurrent();
        std::string configFileName = utils::PathUtils::Basename(executablePath);
        configFileName.append(".config");
        std::string appBase = utils::PathUtils::DirectoryName(executablePath);
        IL2CPP_OBJECT_SETREF(domain->setup, application_base, vm::String::New(appBase.c_str()));
        IL2CPP_OBJECT_SETREF(domain->setup, configuration_file, vm::String::New(configFileName.c_str()));
#endif
    }

    void Runtime::SetConfigUtf16(const Il2CppChar* executablePath)
    {
        IL2CPP_ASSERT(executablePath);

        std::string exePathUtf8 = il2cpp::utils::StringUtils::Utf16ToUtf8(executablePath);
        SetConfigStr(exePathUtf8);
    }

    void Runtime::SetConfig(const char* executablePath)
    {
        IL2CPP_ASSERT(executablePath);
        std::string executablePathStr(executablePath);
        SetConfigStr(executablePathStr);
    }

    void Runtime::SetUnityTlsInterface(const void* unitytlsInterface)
    {
        s_UnitytlsInterface = unitytlsInterface;
    }

    const char *Runtime::GetFrameworkVersion()
    {
        return s_FrameworkVersion;
    }

    std::string Runtime::GetConfigDir()
    {
        if (s_ConfigDir.size() > 0)
            return s_ConfigDir;

        return utils::PathUtils::Combine(utils::Runtime::GetDataDir(), utils::StringView<char>("etc"));
    }

    const void* Runtime::GetUnityTlsInterface()
    {
        return s_UnitytlsInterface;
    }

    const MethodInfo* Runtime::GetDelegateInvoke(Il2CppClass* klass)
    {
        const MethodInfo* invoke = Class::GetMethodFromName(klass, "Invoke", -1);
        IL2CPP_ASSERT(invoke);
        return invoke;
    }

    Il2CppObject* Runtime::DelegateInvoke(Il2CppDelegate *delegate, void **params, Il2CppException **exc)
    {
        const MethodInfo* invoke = GetDelegateInvoke(delegate->object.klass);
        return Invoke(invoke, delegate, params, exc);
    }

    Il2CppObject* Runtime::Invoke(const MethodInfo *method, void *obj, void **params, Il2CppException **exc)
    {
        if (exc)
            il2cpp::gc::WriteBarrier::GenericStoreNull(exc);

        // we wrap invoker call in try/catch here, rather than emitting a try/catch
        // in every invoke call as that blows up the code size.
        try
        {
            if ((method->flags & METHOD_ATTRIBUTE_STATIC) && method->klass && !method->klass->cctor_finished_or_no_cctor)
                ClassInit(method->klass);

            return InvokeWithThrow(method, obj, params);
        }
        catch (Il2CppExceptionWrapper& ex)
        {
            if (exc)
                il2cpp::gc::WriteBarrier::GenericStore(exc, ex.ex);
            return NULL;
        }
    }

    Il2CppObject* Runtime::InvokeWithThrow(const MethodInfo *method, void *obj, void **params)
    {
        hybridclr::InitAndGetInterpreterDirectlyCallMethodPointer(method);
        if (method->return_type->type == IL2CPP_TYPE_VOID)
        {
            method->invoker_method(method->methodPointer, method, obj, params, NULL);
            return NULL;
        }
        else
        {
            if (method->return_type->valuetype)
            {
                Il2CppClass* returnType = Class::FromIl2CppType(method->return_type);
                Class::Init(returnType);
                void* returnValue = alloca(returnType->instance_size - sizeof(Il2CppObject));
                method->invoker_method(method->methodPointer, method, obj, params, returnValue);
                return Object::Box(returnType, returnValue);
            }
            else
            {
                // Note that here method->return_type might be a reference type or it might be
                // a value type returned by reference.
                void* returnValue = NULL;
                method->invoker_method(method->methodPointer, method, obj, params, &returnValue);
                if (method->return_type->byref)
                {
                    // We cannot use method->return_type->valuetype here, because that will be
                    // false for methods that return by reference. Instead, get the class for the
                    // type, which discards the byref flag.
                    Il2CppClass* returnType = Class::FromIl2CppType(method->return_type);
                    if (vm::Class::IsValuetype(returnType))
                        return Object::Box(returnType, returnValue);
                    return *(Il2CppObject**)returnValue;
                }

                return (Il2CppObject*)returnValue;
            }
        }
    }

    Il2CppObject* Runtime::InvokeArray(const MethodInfo *method, void *obj, Il2CppArray *params, Il2CppException **exc)
    {
        if (params == NULL)
            return InvokeConvertArgs(method, obj, NULL, 0, exc);

        // TO DO: when changing GC to one that moves managed objects around, mark params array local variable as pinned!
        return InvokeConvertArgs(method, obj, reinterpret_cast<Il2CppObject**>(Array::GetFirstElementAddress(params)), Array::GetLength(params), exc);
    }

    void Runtime::ObjectInit(Il2CppObject *object)
    {
        ObjectInitException(object, NULL);
    }

    void Runtime::ObjectInitException(Il2CppObject *object, Il2CppException **exc)
    {
        const MethodInfo *method = NULL;
        Il2CppClass *klass = object->klass;

        method = Class::GetMethodFromName(klass, ".ctor", 0);
        IL2CPP_ASSERT(method != NULL && "ObjectInit; no default constructor for object is found");

        if (method->klass->byval_arg.valuetype)
            object = (Il2CppObject*)Object::Unbox(object);
        Invoke(method, object, NULL, exc);
    }

    void Runtime::SetUnhandledExceptionPolicy(Il2CppRuntimeUnhandledExceptionPolicy value)
    {
        s_UnhandledExceptionPolicy = value;
    }

    Il2CppRuntimeUnhandledExceptionPolicy Runtime::GetUnhandledExceptionPolicy()
    {
        return s_UnhandledExceptionPolicy;
    }

    void Runtime::UnhandledException(Il2CppException* exc)
    {
        Il2CppDomain *currentDomain = Domain::GetCurrent();
        Il2CppDomain *rootDomain = Domain::GetRoot();
        FieldInfo *field;
        Il2CppObject *current_appdomain_delegate = NULL;
        Il2CppObject *root_appdomain_delegate = NULL;

        field = Class::GetFieldFromName(il2cpp_defaults.appdomain_class, "UnhandledException");
        IL2CPP_ASSERT(field);

        Il2CppObject* excObject = (Il2CppObject*)exc;

        if (excObject->klass != il2cpp_defaults.threadabortexception_class)
        {
            //bool abort_process = (Thread::Current () == Thread::Main ()) ||
            //  (Runtime::GetUnhandledExceptionPolicy () == IL2CPP_UNHANDLED_POLICY_CURRENT);

            Field::GetValue((Il2CppObject*)rootDomain->domain, field, &root_appdomain_delegate);

            IL2CPP_NOT_IMPLEMENTED_NO_ASSERT(Runtime::UnhandledException, "We don't have runtime version info yet");
            //if (currentDomain != rootDomain && (mono_framework_version () >= 2)) {
            //  Field::GetValue ((Il2CppObject*)currentDomain->domain, field, &current_appdomain_delegate);
            //}
            //else
            //{
            //  current_appdomain_delegate = NULL;
            //}

            ///* set exitcode only if we will abort the process */
            //if (abort_process)
            //  mono_environment_exitcode_set (1);
            //if ((current_appdomain_delegate == NULL) && (root_appdomain_delegate == NULL)
            //{
            //  mono_print_unhandled_exception (exc);
            //}
            //else
            {
                if (root_appdomain_delegate)
                {
                    CallUnhandledExceptionDelegate(rootDomain, (Il2CppDelegate*)root_appdomain_delegate, exc);
                }
                if (current_appdomain_delegate)
                {
                    CallUnhandledExceptionDelegate(currentDomain, (Il2CppDelegate*)current_appdomain_delegate, exc);
                }
            }
        }
    }

    static inline Il2CppObject* InvokeConvertThis(const MethodInfo* method, void* thisArg, void** convertedParameters, Il2CppException** exception)
    {
        Il2CppClass* thisType = method->klass;

        // If it's not a constructor, just invoke directly
        if (strcmp(method->name, ".ctor") != 0 || method->klass == il2cpp_defaults.string_class)
        {
            void* obj = thisArg;
            if (Class::IsNullable(method->klass))
            {
                Il2CppObject* nullable;

                /* Convert the unboxed vtype into a Nullable structure */
                nullable = Object::New(method->klass);

                Il2CppObject* boxed = Object::Box(method->klass->castClass, obj);
                Object::NullableInit((uint8_t*)Object::Unbox(nullable), boxed, method->klass);
                obj = Object::Unbox(nullable);
            }

            return Runtime::Invoke(method, obj, convertedParameters, exception);
        }

        // If it is a construction, we need to construct a return value and allocate object if needed
        Il2CppObject* instance;

        if (thisArg == NULL)
        {
            if (Class::IsNullable(thisType))
            {
                // in the case of a Nullable constructor we can just return a boxed value type
                IL2CPP_ASSERT(convertedParameters);
                instance = Object::Box(thisType->castClass, convertedParameters[0]);
            }
            else
            {
                thisArg = instance = Object::New(thisType);
                Runtime::Invoke(method, thisType->byval_arg.valuetype ? Object::Unbox((Il2CppObject*)thisArg) : thisArg, convertedParameters, exception);
            }
        }
        else
        {
            // thisArg is pointer to data in case of a value type
            // We need to invoke the constructor first, passing point to the value
            // Since the constructor may modify the value, we need to box the result
            // AFTER the constructor was invoked
            Runtime::Invoke(method, thisArg, convertedParameters, exception);
            instance = Object::Box(thisType, thisArg);
        }

        return instance;
    }

    Il2CppObject* Runtime::InvokeConvertArgs(const MethodInfo *method, void* thisArg, Il2CppObject** parameters, int paramCount, Il2CppException** exception)
    {
        void** convertedParameters = NULL;
        bool hasByRefNullables = false;

        // Convert parameters if they are not null
        if (parameters != NULL)
        {
            convertedParameters = (void**)alloca(sizeof(void*) * paramCount);

            for (int i = 0; i < paramCount; i++)
            {
                bool passedByReference = method->parameters[i]->byref;
                Il2CppClass* parameterType = Class::FromIl2CppType(method->parameters[i]);
                Class::Init(parameterType);

                if (Class::IsValuetype(parameterType))
                {
                    if (Class::IsNullable(parameterType))
                    {
                        // Since we don't really store boxed nullables, we need to create a new one.
                        void* nullableStorage = alloca(parameterType->instance_size - sizeof(Il2CppObject));
                        Object::UnboxNullable(parameters[i], parameterType, nullableStorage);
                        convertedParameters[i] = nullableStorage;
                        hasByRefNullables |= passedByReference;
                    }
                    else if (passedByReference)
                    {
                        // If value type is passed by reference, just pass pointer to value directly
                        // If null was passed in, create a new boxed value type in its place
                        if (parameters[i] == NULL)
                            gc::WriteBarrier::GenericStore(parameters + i, Object::New(parameterType));

                        convertedParameters[i] = Object::Unbox(parameters[i]);
                    }
                    else if (parameters[i] == NULL) // If value type is passed by value, we need to pass pointer to its value
                    {
                        // If null was passed in, allocate a new value with default value
                        uint32_t valueSize = parameterType->instance_size - sizeof(Il2CppObject);
                        convertedParameters[i] = alloca(valueSize);
                        memset(convertedParameters[i], 0, valueSize);
                    }
                    else
                    {
                        // Otherwise, pass the original
                        convertedParameters[i] = Object::Unbox(parameters[i]);
                    }
                }
                else if (passedByReference)
                {
                    convertedParameters[i] = &parameters[i]; // Reference type passed by reference
                }
                else if (parameterType->byval_arg.type == IL2CPP_TYPE_PTR)
                {
                    if (parameters[i] != NULL)
                    {
                        IL2CPP_ASSERT(parameters[i]->klass == il2cpp_defaults.int_class);
                        convertedParameters[i] = reinterpret_cast<void*>(*static_cast<intptr_t*>(Object::Unbox(parameters[i])));
                    }
                    else
                    {
                        convertedParameters[i] = NULL;
                    }
                }
                else
                {
                    convertedParameters[i] = parameters[i]; // Reference type passed by value
                }
            }
        }

        Il2CppObject* result = InvokeConvertThis(method, thisArg, convertedParameters, exception);

        if (hasByRefNullables)
        {
            // We need to copy by reference nullables back to original argument array
            for (int i = 0; i < paramCount; i++)
            {
                if (!method->parameters[i]->byref)
                    continue;

                Il2CppClass* parameterType = Class::FromIl2CppType(method->parameters[i]);

                if (Class::IsNullable(parameterType))
                    gc::WriteBarrier::GenericStore(parameters + i, Object::Box(parameterType, convertedParameters[i]));
            }
        }

        if (method->return_type->type == IL2CPP_TYPE_PTR)
        {
            static Il2CppClass* pointerClass = Class::FromName(il2cpp_defaults.corlib, "System.Reflection", "Pointer");
            Il2CppReflectionPointer* pointer = reinterpret_cast<Il2CppReflectionPointer*>(Object::New(pointerClass));
            pointer->data = result;
            IL2CPP_OBJECT_SETREF(pointer, type, Reflection::GetTypeObject(method->return_type));
            result = reinterpret_cast<Il2CppObject*>(pointer);
        }

        return result;
    }

    void Runtime::CallUnhandledExceptionDelegate(Il2CppDomain* domain, Il2CppDelegate* delegate, Il2CppException* exc)
    {
        Il2CppException *e = NULL;
        void* pa[2];

        pa[0] = domain->domain;
        pa[1] = CreateUnhandledExceptionEventArgs(exc);
        DelegateInvoke(delegate, pa, &e);

        // A managed exception occurred during the unhandled exception handler.
        // We can't do much else here other than try to abort the process.
        if (e != NULL)
            utils::Runtime::Abort();
    }

    static baselib::ReentrantLock s_TypeInitializationLock;

// We currently call Runtime::ClassInit in 4 places:
// 1. Just after we allocate storage for a new object (Object::NewAllocSpecific)
// 2. Just before reading any static field
// 3. Just before calling any static method
// 4. Just before calling class instance constructor from a derived class instance constructor
    void Runtime::ClassInit(Il2CppClass *klass)
    {
        // Nothing to do if class has no static constructor or already ran.
        if (klass->cctor_finished_or_no_cctor)
            return;

        s_TypeInitializationLock.Acquire();

        // See if some thread ran it while we acquired the lock.
        if (os::Atomic::CompareExchange(&klass->cctor_finished_or_no_cctor, 1, 1) == 1)
        {
            s_TypeInitializationLock.Release();
            return;
        }

        // See if some other thread got there first and already started running the constructor.
        if (os::Atomic::CompareExchange(&klass->cctor_started, 1, 1) == 1)
        {
            s_TypeInitializationLock.Release();

            // May have been us and we got here through recursion.
            os::Thread::ThreadId currentThread = os::Thread::CurrentThreadId();
            if (os::Atomic::CompareExchangePointer((size_t**)&klass->cctor_thread, (size_t*)currentThread, (size_t*)currentThread) == (size_t*)currentThread)
                return;

            // Wait for other thread to finish executing the constructor.
            while (os::Atomic::CompareExchange(&klass->cctor_finished_or_no_cctor, 1, 1) != 1 && os::Atomic::CompareExchange(&klass->initializationExceptionGCHandle, 0, 0) == 0)
            {
                os::Thread::Sleep(1);
            }
        }
        else
        {
            // Let others know we have started executing the constructor.
            os::Atomic::ExchangePointer((size_t**)&klass->cctor_thread, (size_t*)os::Thread::CurrentThreadId());
            os::Atomic::Exchange(&klass->cctor_started, 1);

            s_TypeInitializationLock.Release();

            // Run it.
            Il2CppException* exception = NULL;
            const MethodInfo* cctor = Class::GetCCtor(klass);
            if (cctor != NULL)
            {
                vm::Runtime::Invoke(cctor, NULL, NULL, &exception);
            }

            os::Atomic::ExchangePointer((size_t**)&klass->cctor_thread, (size_t*)0);

            // Deal with exceptions.
            if (exception == NULL)
            {
                // Let other threads know we finished.
                os::Atomic::Exchange(&klass->cctor_finished_or_no_cctor, 1);
            }
            else
            {
                const Il2CppType *type = Class::GetType(klass);
                std::string n = il2cpp::utils::StringUtils::Printf("The type initializer for '%s' threw an exception.", Type::GetName(type, IL2CPP_TYPE_NAME_FORMAT_IL).c_str());
                Class::SetClassInitializationError(klass, Exception::GetTypeInitializationException(n.c_str(), exception));
            }
        }

        if (klass->initializationExceptionGCHandle)
        {
            il2cpp::vm::Exception::Raise((Il2CppException*)gc::GCHandle::GetTarget(klass->initializationExceptionGCHandle));
        }
    }

    struct ConstCharCompare
    {
        bool operator()(char const *a, char const *b) const
        {
            return strcmp(a, b) < 0;
        }
    };

    Il2CppObject* Runtime::CreateUnhandledExceptionEventArgs(Il2CppException *exc)
    {
        Il2CppClass *klass;
        void* args[2];
        const MethodInfo *method = NULL;
        bool is_terminating = true;
        Il2CppObject *obj;

        klass = Class::FromName(il2cpp_defaults.corlib, "System", "UnhandledExceptionEventArgs");
        IL2CPP_ASSERT(klass);

        Class::Init(klass);

        /* UnhandledExceptionEventArgs only has 1 public ctor with 2 args */
        method = Class::GetMethodFromNameFlags(klass, ".ctor", 2, METHOD_ATTRIBUTE_PUBLIC);
        IL2CPP_ASSERT(method);

        args[0] = exc;
        args[1] = &is_terminating;

        obj = Object::New(klass);
        Runtime::Invoke(method, obj, args, NULL);

        return obj;
    }

    const char *Runtime::GetBundledMachineConfig()
    {
        return s_BundledMachineConfig;
    }

    void Runtime::RegisterBundledMachineConfig(const char *config_xml)
    {
        s_BundledMachineConfig = config_xml;
    }

    void Runtime::VerifyApiVersion()
    {
#if !IL2CPP_TINY
#if IL2CPP_DEBUG
        Il2CppClass *klass = Class::FromName(il2cpp_defaults.corlib, "System", "Environment");
        Class::Init(klass);
        FieldInfo *field = Class::GetFieldFromName(klass, "mono_corlib_version");
        Il2CppString* value;
        Field::StaticGetValue(field, &value);

        std::string version = il2cpp::utils::StringUtils::Utf16ToUtf8(value->chars);
        IL2CPP_ASSERT(version == "1A5E0066-58DC-428A-B21C-0AD6CDAE2789");
#endif
#endif
    }

    int32_t Runtime::GetExitCode()
    {
        return exitcode;
    }

    void Runtime::SetExitCode(int32_t value)
    {
        exitcode = value;
    }

    static void MissingMethodInvoker(Il2CppMethodPointer ptr, const MethodInfo* method, void* obj, void** args, void* ret)
    {
        Runtime::RaiseExecutionEngineException(method, false);
    }

    InvokerMethod Runtime::GetMissingMethodInvoker()
    {
        return MissingMethodInvoker;
    }

    void Runtime::AlwaysRaiseExecutionEngineException(const MethodInfo* method)
    {
        RaiseExecutionEngineException(method, false);
    }

    void Runtime::AlwaysRaiseExecutionEngineExceptionOnVirtualCall(const MethodInfo* method)
    {
        RaiseExecutionEngineException(method, true);
    }

    void Runtime::RaiseExecutionEngineException(const MethodInfo* method, bool virtualCall)
    {
        if (Method::GetClass(method))
            RaiseExecutionEngineException(method, Method::GetFullName(method).c_str(), virtualCall);
        else
            RaiseExecutionEngineException(method, Method::GetNameWithGenericTypes(method).c_str(), virtualCall);
    }

    void Runtime::RaiseAmbiguousImplementationException(const MethodInfo* method)
    {
        if (method != NULL && !Method::IsAmbiguousMethodInfo(method))
            Exception::Raise(Exception::GetAmbiguousImplementationException(utils::StringUtils::Printf("Attempting to call default interface method for '%s' with ambiguous implementations", Method::GetFullName(method).c_str()).c_str()));
        else
            Exception::Raise(Exception::GetAmbiguousImplementationException("Attempting to call default interface method with ambiguous implementations"));
    }

    void Runtime::RaiseExecutionEngineException(const MethodInfo* method, const char* methodFullName, bool virtualCall)
    {
        if (method->flags & METHOD_ATTRIBUTE_ABSTRACT)
        {
            // Default Interface Method support will throw EntryPointNotFoundExceptions if an abstract interface method is accessed
            Exception::Raise(Exception::GetEntryPointNotFoundException(utils::StringUtils::Printf("Attempting to call abstract method '%s'", methodFullName).c_str()));
        }
        else
        {
            std::string help = "";
            if (virtualCall && (method->flags & METHOD_ATTRIBUTE_VIRTUAL) && method->is_inflated)
                help = utils::StringUtils::Printf("  Consider increasing the --generic-virtual-method-iterations=%d argument", metadata::GenericMetadata::GetGenericVirtualIterations());
            Exception::Raise(Exception::GetExecutionEngineException(utils::StringUtils::Printf("Attempting to call method '%s' for which no ahead of time (AOT) code was generated.%s", methodFullName, help.c_str()).c_str()));
        }
    }

#if IL2CPP_TINY
    void Runtime::FailFast(const std::string& message)
    {
        if (!message.empty())
        {
            il2cpp::utils::Logging::Write(message.c_str());
        }
        else
        {
            il2cpp::utils::Logging::Write("No error message was provided. Hopefully the stack trace can provide some information.");
        }

        const char* managedStackTrace = vm::StackTrace::GetStackTrace();
        if (managedStackTrace != NULL && strlen(managedStackTrace) != 0)
        {
            std::string managedStackTraceMessage = std::string("Managed stack trace:\n") + managedStackTrace;
            il2cpp::utils::Logging::Write(managedStackTraceMessage.c_str());
        }
        else
        {
            il2cpp::utils::Logging::Write("No managed stack trace exists. Make sure this is a development build to enable managed stack traces.");
        }

        il2cpp::os::CrashHelpers::Crash();
    }

#endif
} /* namespace vm */
} /* namespace il2cpp */
