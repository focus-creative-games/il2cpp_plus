#pragma once

#include "il2cpp-config.h"

#include "il2cpp-codegen-metadata.h"
#include "il2cpp-codegen-oldintrinsics.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "il2cpp-pinvoke-support.h"
#include "il2cpp-tabledefs.h"
#if !MONO_NET8_BCL
#include "icalls/mscorlib/System.Threading/Interlocked.h"
#endif
#include "vm-utils/VmThreadUtils.h"
#include "vm-utils/Debugger.h"
#include "vm-utils/Finally.h"

#include "vm/Array.h"
#include "vm/ClassInlines.h"
#include "vm/ObjectInlines.h"
#include "vm/ScopedThreadAttacher.h"
#include "vm/Il2CppHStringReference.h"
#include "vm/String.h"

#include "utils/ExceptionSupportStack.h"
#include "utils/Output.h"

#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <limits>
#include <type_traits>

#if IL2CPP_USE_SSE2_FP_CASTS
#include "xmmintrin.h"
#endif

#if IL2CPP_USE_SATURATING_FP_CAST_INTRINSICS
#include <intrin.h>
#endif

struct Il2CppStringBuilder;
typedef Il2CppStringBuilder RuntimeStringBuilder;

#ifdef _MSC_VER
#define IL2CPP_DISABLE_OPTIMIZATIONS __pragma(optimize("", off))
#define IL2CPP_ENABLE_OPTIMIZATIONS __pragma(optimize("", on))
#elif IL2CPP_TARGET_LINUX || IL2CPP_TARGET_QNX
#define IL2CPP_DISABLE_OPTIMIZATIONS
#define IL2CPP_ENABLE_OPTIMIZATIONS
#else
#define IL2CPP_DISABLE_OPTIMIZATIONS __attribute__ ((optnone))
#define IL2CPP_ENABLE_OPTIMIZATIONS
#endif

template<typename T>
using no_infer = typename std::common_type<T>::type;

#if IL2CPP_ENABLE_WRITE_BARRIERS
void Il2CppCodeGenWriteBarrier(void** targetAddress, void* object);
void Il2CppCodeGenWriteBarrierForType(const Il2CppType* type, void** targetAddress, void* object);
void Il2CppCodeGenWriteBarrierForClass(Il2CppClass* klass, void** targetAddress, void* object);
#else
inline void Il2CppCodeGenWriteBarrier(void** targetAddress, void* object) {}
inline void Il2CppCodeGenWriteBarrierForType(const Il2CppType* type, void** targetAddress, void* object) {}
inline void Il2CppCodeGenWriteBarrierForClass(Il2CppClass* klass, void** targetAddress, void* object) {}
#endif

template<typename TD, typename TS>
inline void* il2cpp_codegen_memcpy_with_write_barrier(TD dest, TS src, size_t count, Il2CppClass* klass)
{
    void* result = memcpy((void*)dest, (void*)src, count);
    Il2CppCodeGenWriteBarrierForClass(klass, (void**)dest, (void*)src);
    return result;
}

inline void* il2cpp_codegen_memcpy(void* dest, const void* src, size_t count)
{
    return memcpy(dest, src, count);
}

inline void* il2cpp_codegen_memcpy(intptr_t dest, const void* src, size_t count)
{
    return memcpy((void*)dest, src, count);
}

inline void* il2cpp_codegen_memcpy(uintptr_t dest, const void* src, size_t count)
{
    return memcpy((void*)dest, src, count);
}

inline void* il2cpp_codegen_memcpy(void* dest, intptr_t src, size_t count)
{
    return memcpy(dest, (void*)src, count);
}

inline void* il2cpp_codegen_memcpy(intptr_t dest, intptr_t src, size_t count)
{
    return memcpy((void*)dest, (void*)src, count);
}

inline void* il2cpp_codegen_memcpy(uintptr_t dest, intptr_t src, size_t count)
{
    return memcpy((void*)dest, (void*)src, count);
}

inline void* il2cpp_codegen_memcpy(void* dest, uintptr_t src, size_t count)
{
    return memcpy(dest, (void*)src, count);
}

inline void* il2cpp_codegen_memcpy(intptr_t dest, uintptr_t src, size_t count)
{
    return memcpy((void*)dest, (void*)src, count);
}

inline void* il2cpp_codegen_memcpy(uintptr_t dest, uintptr_t src, size_t count)
{
    return memcpy((void*)dest, (void*)src, count);
}

inline void il2cpp_codegen_memset(void* ptr, int value, size_t num)
{
    memset(ptr, value, num);
}

inline void il2cpp_codegen_memset(intptr_t ptr, int value, size_t num)
{
    memset((void*)ptr, value, num);
}

inline void il2cpp_codegen_memset(uintptr_t ptr, int value, size_t num)
{
    memset((void*)ptr, value, num);
}

inline void il2cpp_codegen_initobj(void* value, size_t size)
{
    memset(value, 0, size);
}

inline void il2cpp_codegen_initobj(intptr_t value, size_t size)
{
    memset((void*)value, 0, size);
}

inline void il2cpp_codegen_initobj(uintptr_t value, size_t size)
{
    memset((void*)value, 0, size);
}

template<typename TOutput, typename TFloat>
struct ConvFloatingPoint
{
    inline static TOutput Conv(TFloat value)
    {
#if IL2CPP_EMULATE_X86_FP_UNSIGNED_OVERFLOW
        // In release builds and on ARM, a cast from a floating point to
        // integer value will use the min or max value if the cast is out
        // of range (instead of overflowing like x86/x64 debug builds).
        // So first do a cast to the output type (which is signed in
        // .NET - the value stack does not have unsigned types) to try to
        // get the value into a range that will actually be cast the way .NET does.
        if (value < 0 && std::is_unsigned<TOutput>::value)
        {
            // Conversion for a negative to an unsigned value of the same size is UB in C++
            // The memcpy ensures that the optimizer doesn't optimize this out
            auto t = (typename std::make_signed<TOutput>::type)value;
            TOutput output;
            memcpy(&output, &t, sizeof(TOutput));
            return output;
        }
#endif
        // All casts to <int32 are done as if they are cast to int32 followed by a cast to actual type
        if (sizeof(TOutput) < sizeof(int32_t))
            return (TOutput)(int32_t)value;
        return (TOutput)value;
    }
};


#if IL2CPP_USE_SSE2_FP_CASTS

template<typename TOutput>
struct ConvFloatingPoint<TOutput, float>
{
    inline static TOutput Conv(float value)
    {
        return (TOutput)_mm_cvttss_si32(_mm_set_ss(value));
    }
};

template<typename TOutput>
struct ConvFloatingPoint<TOutput, double>
{
    inline static int32_t Conv(double value)
    {
        return (TOutput)_mm_cvttsd_si32(_mm_set_sd(value));
    }
};

template<>
struct ConvFloatingPoint<int64_t, float>
{
    inline static int64_t Conv(float value)
    {
        return _mm_cvttss_si64(_mm_set_ss(value));
    }
};

template<>
struct ConvFloatingPoint<uint64_t, float>
{
    inline static uint64_t Conv(float value)
    {
        return (uint64_t)_mm_cvttss_si64(_mm_set_ss(value));
    }
};

template<>
struct ConvFloatingPoint<uint32_t, float>
{
    inline static uint32_t Conv(float value)
    {
        return (uint32_t)_mm_cvttss_si64(_mm_set_ss(value));
    }
};

template<>
struct ConvFloatingPoint<int64_t, double>
{
    inline static int64_t Conv(double value)
    {
        return _mm_cvttsd_si64(_mm_set_sd(value));
    }
};

template<>
struct ConvFloatingPoint<uint64_t, double>
{
    inline static uint64_t Conv(double value)
    {
        return (uint64_t)_mm_cvttsd_si64(_mm_set_sd(value));
    }
};

template<>
struct ConvFloatingPoint<uint32_t, double>
{
    inline static uint32_t Conv(double value)
    {
        return (uint32_t)_mm_cvttsd_si64(_mm_set_sd(value));
    }
};

#endif // IL2CPP_USE_SSE2_FP_CASTS

#if IL2CPP_USE_SATURATING_FP_CAST_INTRINSICS

template<typename TOutput>
struct ConvFloatingPoint<TOutput, float>
{
    inline static TOutput Conv(float value)
    {
        return (TOutput)_cvt_ftoi_sat(value);
    }
};

template<typename TOutput>
struct ConvFloatingPoint<TOutput, double>
{
    inline static TOutput Conv(double value)
    {
        return (TOutput)_cvt_dtoi_sat(value);
    }
};

template<>
struct ConvFloatingPoint<uint32_t, float>
{
    inline static uint32_t Conv(float value)
    {
        return _cvt_ftoui_sat(value);
    }
};

template<>
struct ConvFloatingPoint<uint32_t, double>
{
    inline static uint32_t Conv(double value)
    {
        return _cvt_dtoui_sat(value);
    }
};

template<>
struct ConvFloatingPoint<int64_t, float>
{
    inline static int64_t Conv(float value)
    {
        return _cvt_ftoll_sat(value);
    }
};

template<>
struct ConvFloatingPoint<int64_t, double>
{
    inline static int64_t Conv(double value)
    {
        return _cvt_dtoll_sat(value);
    }
};

template<>
struct ConvFloatingPoint<uint64_t, float>
{
    inline static uint64_t Conv(float value)
    {
        return _cvt_ftoull_sat(value);
    }
};

template<>
struct ConvFloatingPoint<uint64_t, double>
{
    inline static uint64_t Conv(double value)
    {
        return _cvt_dtoull_sat(value);
    }
};

#endif // IL2CPP_USE_SATURATING_FP_CAST_INTRINSICS

template<bool, class T, class U>
struct pick_first;

template<class T, class U>
struct pick_first<true, T, U>
{
    typedef T type;
};

template<class T, class U>
struct pick_first<false, T, U>
{
    typedef U type;
};

template<class T, class U>
struct pick_bigger
{
    typedef typename pick_first<(sizeof(T) >= sizeof(U)), T, U>::type type;
};

template<typename T, typename U>
inline typename pick_bigger<T, U>::type il2cpp_codegen_multiply(T left, U right)
{
    return left * right;
}

template<typename T, typename U>
inline typename pick_bigger<T, U>::type il2cpp_codegen_add(T left, U right)
{
    return left + right;
}

template<typename T, typename U>
inline typename pick_bigger<T, U>::type il2cpp_codegen_subtract(T left, U right)
{
    return left - right;
}

template<typename T>
inline bool il2cpp_codegen_enum_has_flag(T enumValue, T flag)
{
    return (enumValue & flag) == flag;
}

NORETURN void il2cpp_codegen_raise_exception(Exception_t* ex, const RuntimeMethod* lastManagedFrame = NULL);

inline bool il2cpp_codegen_is_little_endian()
{
#if IL2CPP_BYTE_ORDER == IL2CPP_LITTLE_ENDIAN
    return true;
#else
    return false;
#endif
}

NORETURN void il2cpp_codegen_raise_index_out_of_range_exception(const RuntimeMethod* method);
NORETURN void il2cpp_codegen_raise_invalid_unmanaged_callers_usage(const RuntimeMethod* method, const char* msg);
NORETURN void il2cpp_codegen_raise_abstract_method_load_exception(const RuntimeMethod* method, const RuntimeClass* klass);
NORETURN void il2cpp_codegen_raise_platform_not_supported_exception(const RuntimeMethod* method);
NORETURN void il2cpp_codegen_raise_argument_out_of_range_exception(const RuntimeMethod* method);
NORETURN void il2cpp_codegen_raise_invalid_offset_type_load_exception(const uint8_t* utf8Name, size_t nameLength, size_t invalidFieldOffset);

inline void il2cpp_codegen_check_ldftn_constrained(const void* method, const RuntimeClass* klass)
{
    if (((const MethodInfo*)method)->flags & METHOD_ATTRIBUTE_ABSTRACT)
        il2cpp_codegen_raise_abstract_method_load_exception((const MethodInfo*)method, klass);
}

NORETURN void il2cpp_codegen_raise_overflow_exception(const RuntimeMethod* method);

template<typename T>
constexpr bool il2cpp_codegen_is_floating_point_type()
{
    return std::is_same<T, float>::value || std::is_same<T, double>::value;
}

template<typename TDest, typename TSource, typename TILStackType, bool checkOverflow, bool treatInputAsUnsigned, bool destIsFloatingPoint, bool sourceIsFloatingPoint>
class ConvImpl
{
    static TDest Conv(TSource srcValue, const RuntimeMethod* method);
};

template<typename TDest, typename TSource, typename TILStackType, bool checkOverflow, bool treatInputAsUnsigned>
struct ConvImpl<TDest, TSource, TILStackType, checkOverflow, treatInputAsUnsigned, false, false>
{
    // Integer type to integer type
    static TDest Conv(TSource srcValue, const RuntimeMethod* method)
    {
        IL2CPP_ASSERT(!il2cpp_codegen_is_floating_point_type<TDest>() && !il2cpp_codegen_is_floating_point_type<TSource>());
        TILStackType ilStackValue = (TILStackType)srcValue;

        if (checkOverflow)
        {
            typedef typename pick_bigger<TDest, TILStackType>::type CompType;

            if (!treatInputAsUnsigned && !std::is_unsigned<TDest>::value)
            {
                if ((CompType)ilStackValue > (CompType)std::numeric_limits<TDest>::max())
                    il2cpp_codegen_raise_overflow_exception(method);
                if ((CompType)ilStackValue < (CompType)std::numeric_limits<TDest>::min())
                    il2cpp_codegen_raise_overflow_exception(method);
            }
            if (treatInputAsUnsigned || std::is_unsigned<TDest>::value)
            {
                if ((typename std::make_unsigned<TILStackType>::type)ilStackValue > (typename std::make_unsigned<TDest>::type) std::numeric_limits<TDest>::max())
                    il2cpp_codegen_raise_overflow_exception(method);
                if (!treatInputAsUnsigned && ilStackValue < 0)
                    il2cpp_codegen_raise_overflow_exception(method);
            }
        }

        if (std::is_unsigned<TDest>::value)
            return (TDest)(typename std::make_unsigned<TILStackType>::type)ilStackValue;

    #if __cplusplus < 202022L
        // Prior to C++ 20 conversion of integer types to smaller types is undefined behavior
        // In most implementations it works as expected, except the optimizer is allowed to optimize it out
        if (sizeof(TDest) >= sizeof(TILStackType))
            return (TDest)ilStackValue;
        constexpr TILStackType mask = (TILStackType)std::numeric_limits<typename std::make_unsigned<TDest>::type>::max();
        return (TDest)(ilStackValue & mask);
    #else
        return (TDest)ilStackValue;
    #endif
    }
};

template<typename TDest, typename TSource, typename TILStackType, bool checkOverflow, bool treatInputAsUnsigned>
struct ConvImpl<TDest, TSource, TILStackType, checkOverflow, treatInputAsUnsigned, false, true>
{
    // Floating point type to integer type
    static TDest Conv(TSource srcValue, const RuntimeMethod* method)
    {
        IL2CPP_ASSERT(!il2cpp_codegen_is_floating_point_type<TDest>() && il2cpp_codegen_is_floating_point_type<TSource>());
        TILStackType ilStackValue = (TILStackType)srcValue;

        if (checkOverflow)
        {
            if (ilStackValue > (TILStackType)std::numeric_limits<TDest>::max())
                il2cpp_codegen_raise_overflow_exception(method);
            if (std::is_signed<TDest>::value && ilStackValue < (TILStackType)std::numeric_limits<TDest>::min())
                il2cpp_codegen_raise_overflow_exception(method);
            if (std::is_unsigned<TDest>::value && ilStackValue < 0)
                il2cpp_codegen_raise_overflow_exception(method);
        }

        return ConvFloatingPoint<TDest, TSource>::Conv(ilStackValue);
    }
};

template<typename TDest, typename TSource, typename TILStackType, bool checkOverflow, bool treatInputAsUnsigned>
struct ConvImpl<TDest, TSource, TILStackType, checkOverflow, treatInputAsUnsigned, true, false>
{
    // Integer type to floating point type
    static TDest Conv(TSource srcValue, const RuntimeMethod * method)
    {
        IL2CPP_ASSERT(il2cpp_codegen_is_floating_point_type<TDest>() && !il2cpp_codegen_is_floating_point_type<TSource>());
        TILStackType ilStackValue = (TILStackType)srcValue;
        if (treatInputAsUnsigned)
            return (TDest)(typename std::make_unsigned<TILStackType>::type)ilStackValue;
        return (TDest)ilStackValue;
    }
};

template<typename TDest, typename TSource, typename TILStackType, bool checkOverflow, bool treatInputAsUnsigned>
struct ConvImpl<TDest, TSource, TILStackType, checkOverflow, treatInputAsUnsigned, true, true>
{
    // Floating point to floating point type
    static TDest Conv(TSource srcValue, const RuntimeMethod* method)
    {
        IL2CPP_ASSERT(il2cpp_codegen_is_floating_point_type<TDest>() && il2cpp_codegen_is_floating_point_type<TSource>());
        return (TDest)srcValue;
    }
};

template<typename TDest, typename TSource, typename TILStackType, bool checkOverflow, bool treatInputAsUnsigned>
TDest il2cpp_codegen_conv(TSource srcValue, const RuntimeMethod* method)
{
    return ConvImpl<TDest, TSource, TILStackType, checkOverflow, treatInputAsUnsigned, il2cpp_codegen_is_floating_point_type<TDest>(), il2cpp_codegen_is_floating_point_type<TSource>()>::Conv(srcValue, method);
}

REAL_NORETURN IL2CPP_NO_INLINE void il2cpp_codegen_no_return();

NORETURN void il2cpp_codegen_rethrow_exception(Exception_t *ex);

NORETURN void il2cpp_codegen_raise_exception(il2cpp_hresult_t hresult, bool defaultToCOMException);

// Exception support macros

#define IL2CPP_PUSH_ACTIVE_EXCEPTION(Exception) \
    __active_exceptions.push(Exception)

#define IL2CPP_POP_ACTIVE_EXCEPTION(ExcType) \
    (ExcType)__active_exceptions.pop()

#define IL2CPP_GET_ACTIVE_EXCEPTION(ExcType) \
    (ExcType)__active_exceptions.top()

#define IL2CPP_RAISE_NULL_REFERENCE_EXCEPTION() \
    do {\
        il2cpp_codegen_raise_null_reference_exception();\
        il2cpp_codegen_no_return();\
    } while (0)

#define IL2CPP_RAISE_MANAGED_EXCEPTION(ex, lastManagedFrame) \
    do {\
        il2cpp_codegen_raise_exception((Exception_t*)ex, (RuntimeMethod*)lastManagedFrame);\
        il2cpp_codegen_no_return();\
    } while (0)

#define IL2CPP_RETHROW_MANAGED_EXCEPTION(ex) \
    do {\
        il2cpp_codegen_rethrow_exception((Exception_t*)ex);\
        il2cpp_codegen_no_return();\
    } while (0)


#if IL2CPP_ENABLE_PROFILER

void il2cpp_codegen_profiler_method_enter(const RuntimeMethod* method);

void il2cpp_codegen_profiler_method_exit(const RuntimeMethod* method);

#endif

struct ProfilerMethodSentry
{
    ProfilerMethodSentry(const RuntimeMethod* method)
#if IL2CPP_ENABLE_PROFILER
        : m_method(method)
#endif
    {
#if IL2CPP_ENABLE_PROFILER
        il2cpp_codegen_profiler_method_enter(m_method);
#endif
    }

    ~ProfilerMethodSentry()
    {
#if IL2CPP_ENABLE_PROFILER
        il2cpp_codegen_profiler_method_exit(m_method);
#endif
    }

private:
    const RuntimeMethod* m_method;
};

void il2cpp_codegen_stacktrace_push_frame(Il2CppStackFrameInfo& frame);

void il2cpp_codegen_stacktrace_pop_frame();

uint32_t il2cpp_codegen_sizeof(RuntimeClass* klass);

struct StackTraceSentry
{
    StackTraceSentry(const RuntimeMethod* method) : m_method(method)
    {
        Il2CppStackFrameInfo frame_info = { 0 };

        frame_info.method = method;

        il2cpp_codegen_stacktrace_push_frame(frame_info);
    }

    ~StackTraceSentry()
    {
        il2cpp_codegen_stacktrace_pop_frame();
    }

private:
    const RuntimeMethod* m_method;
};

#define IL2CPP_FAKE_BOX_SENTRY (MonitorData*)UINTPTR_MAX

template<typename T>
struct Il2CppFakeBox : RuntimeObject
{
    T m_Value;

    Il2CppFakeBox(RuntimeClass* boxedType, const T& value)
    {
        klass = boxedType;
        monitor = IL2CPP_FAKE_BOX_SENTRY;
        m_Value = value;
    }
};

struct Il2CppFakeBoxBuffer : RuntimeObject
{
    char m_Value[];

    Il2CppFakeBoxBuffer(RuntimeClass* boxedType, void* value)
    {
        klass = boxedType;
        monitor = IL2CPP_FAKE_BOX_SENTRY;
        memcpy(&m_Value, value, il2cpp_codegen_sizeof(boxedType));
    }

    static uint32_t SizeNeededFor(RuntimeClass* boxedType)
    {
        return sizeof(Il2CppFakeBoxBuffer) + il2cpp_codegen_sizeof(boxedType);
    }
};


inline bool il2cpp_codegen_is_fake_boxed_object(RuntimeObject* object)
{
    return object->monitor == IL2CPP_FAKE_BOX_SENTRY;
}

// TODO: This file should contain all the functions and type declarations needed for the generated code.
// Hopefully, we stop including everything in the generated code and know exactly what dependencies we have.
// Note that all parameter and return types should match the generated types not the runtime types.

void il2cpp_codegen_register(const Il2CppCodeRegistration* const codeRegistration, const Il2CppMetadataRegistration* const metadataRegistration, const Il2CppCodeGenOptions* const codeGenOptions);

typedef void (*MetadataInitializerCleanupFunc)();
void il2cpp_codegen_register_metadata_initialized_cleanup(MetadataInitializerCleanupFunc cleanup);

// type registration

void* il2cpp_codegen_get_thread_static_data(RuntimeClass* klass);

String_t* il2cpp_codegen_string_new_wrapper(const char* str);

String_t* il2cpp_codegen_string_new_utf16(const il2cpp::utils::StringView<Il2CppChar>& str);

Type_t* il2cpp_codegen_type_get_object(const RuntimeType* type);

void il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found(const RuntimeMethod* method);

void il2cpp_codegen_raise_execution_engine_exception(const RuntimeMethod* method);
void il2cpp_codegen_raise_execution_engine_exception_missing_virtual(const RuntimeMethod* method);

NORETURN void il2cpp_codegen_raise_out_of_memory_exception();

NORETURN void il2cpp_codegen_raise_null_reference_exception();

NORETURN void il2cpp_codegen_raise_divide_by_zero_exception();

NORETURN void il2cpp_codegen_raise_index_out_of_range_exception();

NORETURN void il2cpp_codegen_raise_not_supported_exception();

Exception_t* il2cpp_codegen_get_argument_exception(const char* param, const char* msg);

Exception_t* il2cpp_codegen_get_argument_null_exception(const char* param);

Exception_t* il2cpp_codegen_get_overflow_exception();

Exception_t* il2cpp_codegen_get_not_supported_exception(const char* msg);

Exception_t* il2cpp_codegen_get_array_type_mismatch_exception();

Exception_t* il2cpp_codegen_get_invalid_cast_exception(const char* msg);

Exception_t* il2cpp_codegen_get_invalid_operation_exception(const char* msg);

Exception_t* il2cpp_codegen_get_marshal_directive_exception(const char* msg);

Exception_t* il2cpp_codegen_get_marshal_directive_exception(const char* msg, const RuntimeType* type);

// format string will require first instance as a field and second instance as a type or this will break
Exception_t* il2cpp_codegen_get_marshal_directive_exception(const char* msg, const RuntimeField* field, const RuntimeType* type);

Exception_t* il2cpp_codegen_get_missing_method_exception(const char* msg);

Exception_t* il2cpp_codegen_get_maximum_nested_generics_exception();

Exception_t* il2cpp_codegen_get_engine_execution_exception(const char* msg);

Exception_t* il2cpp_codegen_get_index_out_of_range_exception();

Exception_t* il2cpp_codegen_get_exception(il2cpp_hresult_t hresult, bool defaultToCOMException);

inline RuntimeClass* il2cpp_codegen_object_class(RuntimeObject* obj)
{
    return obj->klass;
}

// OpCode.IsInst

RuntimeObject* IsInst(RuntimeObject *obj, RuntimeClass* targetType);

inline RuntimeObject* IsInstSealed(RuntimeObject *obj, RuntimeClass* targetType)
{
#if IL2CPP_DEBUG
    IL2CPP_ASSERT((targetType->flags & TYPE_ATTRIBUTE_SEALED) != 0);
    IL2CPP_ASSERT((targetType->flags & TYPE_ATTRIBUTE_INTERFACE) == 0);
#endif
    if (!obj)
        return NULL;

    // optimized version to compare sealed classes
    return (obj->klass == targetType ? obj : NULL);
}

inline RuntimeObject* IsInstClass(RuntimeObject *obj, RuntimeClass* targetType)
{
#if IL2CPP_DEBUG
    IL2CPP_ASSERT((targetType->flags & TYPE_ATTRIBUTE_INTERFACE) == 0);
#endif
    if (!obj)
        return NULL;

    // optimized version to compare classes
    return il2cpp::vm::ClassInlines::HasParentUnsafe(obj->klass, targetType) ? obj : NULL;
}

// OpCode.Castclass

NORETURN void RaiseInvalidCastException(RuntimeClass* sourceType, RuntimeClass* targetType);
NORETURN void RaiseInvalidCastException(RuntimeObject* obj, RuntimeClass* targetType);

inline RuntimeObject* Castclass(RuntimeObject *obj, RuntimeClass* targetType)
{
    if (!obj)
        return NULL;

    RuntimeObject* result = IsInst(obj, targetType);
    if (result)
        return result;

    RaiseInvalidCastException(obj, targetType);
    return NULL;
}

inline RuntimeObject* CastclassSealed(RuntimeObject *obj, RuntimeClass* targetType)
{
    if (!obj)
        return NULL;

    RuntimeObject* result = IsInstSealed(obj, targetType);
    if (result)
        return result;

    RaiseInvalidCastException(obj, targetType);
    return NULL;
}

inline RuntimeObject* CastclassClass(RuntimeObject *obj, RuntimeClass* targetType)
{
    if (!obj)
        return NULL;

    RuntimeObject* result = IsInstClass(obj, targetType);
    if (result)
        return result;

    RaiseInvalidCastException(obj, targetType);
    return NULL;
}

inline void NullCheck(void* this_ptr)
{
    if (this_ptr != NULL)
        return;

    il2cpp_codegen_raise_null_reference_exception();
}

// OpCode.Box

RuntimeObject* Box(RuntimeClass* type, void* data);

// OpCode.UnBox

template<typename T>
inline T* il2cpp_codegen_get_raw_data(Il2CppObject* obj)
{
    return reinterpret_cast<T*>(il2cpp::vm::ObjectInlines::GetRawData(obj));
}

inline void* UnBox(RuntimeObject* obj)
{
    NullCheck(obj);
    return il2cpp_codegen_get_raw_data<void>(obj);
}

inline void* UnBox(RuntimeObject* obj, RuntimeClass* expectedBoxedClass)
{
    NullCheck(obj);

    if (obj->klass->element_class == expectedBoxedClass->element_class)
        return il2cpp_codegen_get_raw_data<void>(obj);

    RaiseInvalidCastException(obj, expectedBoxedClass);
    return NULL;
}

void UnBoxNullable_internal(RuntimeObject* obj, RuntimeClass* nullableClass, void* storage);

inline void UnBoxNullable(RuntimeObject* obj, RuntimeClass* nullableClass, void* storage)
{
    // We only need to do type checks if obj is not null
    // Unboxing null nullable is perfectly valid and returns an instance that has no value
    if (obj != NULL)
    {
        if (obj->klass != nullableClass->element_class)
            RaiseInvalidCastException(obj, nullableClass->element_class);
    }

    UnBoxNullable_internal(obj, nullableClass, storage);
}

// Implements OpCode.UnBox_Any at runtime, obj may be any type, even a reference type
// unboxStorage must always be a buffer large enough to store the unboxed result
// It always returns a pointer to a data buffer - either a pointer to a value type or a pointer to a reference type
void* UnBox_Any(RuntimeObject* obj, RuntimeClass* expectedBoxedClass, void* unboxStorage);

// objBuffer is a pointer to the obj - either a pointer to a value type or a pointer to a reference type
bool il2cpp_codegen_would_box_to_non_null(RuntimeClass* klass, void* objBuffer);

// objBuffer is a pointer to the obj - either a pointer to a value type or a pointer to a reference type
RuntimeObject* il2cpp_codegen_isinst_runtime(RuntimeClass* fromClass, RuntimeClass* toClass, void* objBuffer);
RuntimeObject* il2cpp_codegen_isinst_runtime_sealed(RuntimeClass* fromClass, RuntimeClass* toClass, void* objBuffer);
RuntimeObject* il2cpp_codegen_isinst_runtime_class(RuntimeClass* fromClass, RuntimeClass* toClass, void* objBuffer);

// objBuffer is a pointer to the obj - either a pointer to a value type or a pointer to a reference type
bool il2cpp_codegen_isinst_runtime_check(RuntimeClass* fromClass, RuntimeClass* toClass, void* objBuffer);
bool il2cpp_codegen_isinst_runtime_check_sealed(RuntimeClass* fromClass, RuntimeClass* toClass, void* objBuffer);
bool il2cpp_codegen_isinst_runtime_check_class(RuntimeClass* fromClass, RuntimeClass* toClass, void* objBuffer);

inline RuntimeClass* il2cpp_codegen_object_get_class(RuntimeObject* object)
{
    NullCheck(object);
    return object->klass;
}

RuntimeClass* il2cpp_codegen_object_get_class_constrained(void* objectBuffer, RuntimeClass* klass);

void il2cpp_codegen_box_unbox_change_class(void* from, void* to, size_t size, RuntimeClass* fromClass, RuntimeClass* toClass);

inline void il2cpp_codegen_box_unbox(void* from, void* to, size_t size, RuntimeClass* fromClass, RuntimeClass* toClass)
{
    IL2CPP_ASSERT_STACK_PTR(to); // This method doesn't do any write barriers - in current usage to is always on the stack

    if (fromClass != toClass)
        il2cpp_codegen_box_unbox_change_class(from, to, size, fromClass, toClass);
    else
        il2cpp_codegen_memcpy(to, from, size);
}

int32_t il2cpp_codgen_class_get_instance_size(RuntimeClass* klass);

inline uint32_t il2cpp_codegen_sizeof(RuntimeClass* klass)
{
    IL2CPP_ASSERT(klass->size_inited);
    return klass->stack_slot_size;
}

inline bool il2cpp_codegen_method_is_virtual(RuntimeMethod* method)
{
    return method->slot != kInvalidIl2CppMethodSlot;
}

inline bool il2cpp_codegen_object_is_of_sealed_type(RuntimeObject* obj)
{
    IL2CPP_ASSERT(obj);
    return (obj->klass->flags & TYPE_ATTRIBUTE_SEALED) != 0;
}

bool il2cpp_codegen_method_is_generic_instance_method(RuntimeMethod* method);

RuntimeClass* il2cpp_codegen_method_get_declaring_type(const RuntimeMethod* method);

bool il2cpp_codegen_method_is_interface_method(RuntimeMethod* method);

inline uint16_t il2cpp_codegen_method_get_slot(const RuntimeMethod* method)
{
    return method->slot;
}

IL2CPP_FORCE_INLINE const VirtualInvokeData& il2cpp_codegen_get_virtual_invoke_data(Il2CppMethodSlot slot, const RuntimeClass* klass)
{
    Assert(slot != kInvalidIl2CppMethodSlot && "il2cpp_codegen_get_virtual_invoke_data got called on a non-virtual method");
    return klass->vtable[slot];
}

IL2CPP_FORCE_INLINE const VirtualInvokeData& il2cpp_codegen_get_virtual_invoke_data(Il2CppMethodSlot slot, const RuntimeObject* obj)
{
    return il2cpp_codegen_get_virtual_invoke_data(slot, obj->klass);
}

IL2CPP_FORCE_INLINE const VirtualInvokeData& il2cpp_codegen_get_interface_invoke_data(Il2CppMethodSlot slot, RuntimeObject* obj, const RuntimeClass* declaringInterface)
{
    Assert(slot != kInvalidIl2CppMethodSlot && "il2cpp_codegen_get_interface_invoke_data got called on a non-virtual method");
    return il2cpp::vm::ClassInlines::GetInterfaceInvokeDataFromVTable(obj, declaringInterface, slot);
}

IL2CPP_FORCE_INLINE const VirtualInvokeData& il2cpp_codegen_get_interface_invoke_data(Il2CppMethodSlot slot, const RuntimeClass* klass, const RuntimeClass* declaringInterface)
{
    Assert(slot != kInvalidIl2CppMethodSlot && "il2cpp_codegen_get_interface_invoke_data got called on a non-virtual method");
    return il2cpp::vm::ClassInlines::GetInterfaceInvokeDataFromVTable(klass, declaringInterface, slot);
}

const RuntimeMethod* il2cpp_codegen_get_generic_virtual_method_internal(const RuntimeMethod* methodDefinition, const RuntimeMethod* inflatedMethod);

IL2CPP_FORCE_INLINE const RuntimeMethod* il2cpp_codegen_get_generic_virtual_method(const RuntimeMethod* method, const RuntimeClass* klass)
{
    uint16_t slot = method->slot;
    const RuntimeMethod* methodDefinition = klass->vtable[slot].method;
    return il2cpp_codegen_get_generic_virtual_method_internal(methodDefinition, method);
}

IL2CPP_FORCE_INLINE const RuntimeMethod* il2cpp_codegen_get_generic_virtual_method(const RuntimeMethod* method, const RuntimeObject* obj)
{
    return il2cpp_codegen_get_generic_virtual_method(method, obj->klass);
}

IL2CPP_FORCE_INLINE void il2cpp_codegen_get_generic_virtual_invoke_data(const RuntimeMethod* method, const RuntimeClass* klass, VirtualInvokeData* invokeData)
{
    invokeData->method = il2cpp_codegen_get_generic_virtual_method(method, klass);
    invokeData->methodPtr = invokeData->method->virtualMethodPointer;
    IL2CPP_ASSERT(invokeData->method);
}

IL2CPP_FORCE_INLINE void il2cpp_codegen_get_generic_virtual_invoke_data(const RuntimeMethod* method, const RuntimeObject* obj, VirtualInvokeData* invokeData)
{
    return il2cpp_codegen_get_generic_virtual_invoke_data(method, obj->klass, invokeData);
}

IL2CPP_FORCE_INLINE const RuntimeMethod* il2cpp_codegen_get_generic_interface_method(const RuntimeMethod* method, const RuntimeClass* klass)
{
    const RuntimeMethod* methodDefinition = il2cpp::vm::ClassInlines::GetInterfaceInvokeDataFromVTable(klass, method->klass, method->slot).method;
    return il2cpp_codegen_get_generic_virtual_method_internal(methodDefinition, method);
}

IL2CPP_FORCE_INLINE const RuntimeMethod* il2cpp_codegen_get_generic_interface_method(const RuntimeMethod* method, RuntimeObject* obj)
{
    const RuntimeMethod* methodDefinition = il2cpp::vm::ClassInlines::GetInterfaceInvokeDataFromVTable(obj, method->klass, method->slot).method;
    return il2cpp_codegen_get_generic_virtual_method_internal(methodDefinition, method);
}

IL2CPP_FORCE_INLINE void il2cpp_codegen_get_generic_interface_invoke_data(const RuntimeMethod* method, const RuntimeClass* klass, VirtualInvokeData* invokeData)
{
    invokeData->method = il2cpp_codegen_get_generic_interface_method(method, klass);
    invokeData->methodPtr = invokeData->method->virtualMethodPointer;
    IL2CPP_ASSERT(invokeData->method);
}

IL2CPP_FORCE_INLINE void il2cpp_codegen_get_generic_interface_invoke_data(const RuntimeMethod* method, RuntimeObject* obj, VirtualInvokeData* invokeData)
{
    invokeData->method = il2cpp_codegen_get_generic_interface_method(method, obj);
    invokeData->methodPtr = invokeData->method->virtualMethodPointer;
    IL2CPP_ASSERT(invokeData->method);
}

inline RuntimeClass* InitializedTypeInfo(RuntimeClass* klass)
{
    return il2cpp::vm::ClassInlines::InitFromCodegen(klass);
}

RuntimeClass* il2cpp_codegen_class_from_type_internal(const RuntimeType* type);

inline RuntimeClass* il2cpp_codegen_class_from_type(const RuntimeType *type)
{
    return InitializedTypeInfo(il2cpp_codegen_class_from_type_internal(type));
}

inline const RuntimeType* il2cpp_codegen_type_from_class(RuntimeClass *klass)
{
    return &klass->byval_arg;
}

void* InterlockedExchangeImplRef(void** location, void* value);

void* InterlockedCompareExchangeImpl(void** location, void* value, void* comparand);

template<typename T>
inline T InterlockedCompareExchangeImpl(T* location, T value, T comparand)
{
    return (T)InterlockedCompareExchangeImpl((void**)location, value, comparand);
}

template<typename T>
inline T InterlockedExchangeImpl(T* location, T value)
{
    return (T)InterlockedExchangeImplRef((void**)location, value);
}

void il2cpp_codegen_memory_barrier();

RuntimeArray* SZArrayNew(RuntimeClass* arrayType, uint32_t length);

RuntimeArray* GenArrayNew(RuntimeClass* arrayType, il2cpp_array_size_t* dimensions);

// Performance optimization as detailed here: http://blogs.msdn.com/b/clrcodegeneration/archive/2009/08/13/array-bounds-check-elimination-in-the-clr.aspx
// Since array size is a signed int32_t, a single unsigned check can be performed to determine if index is less than array size.
// Negative indices will map to a unsigned number greater than or equal to 2^31 which is larger than allowed for a valid array.
#define IL2CPP_ARRAY_BOUNDS_CHECK(index, length) \
    do { \
        if (((uint32_t)(index)) >= ((uint32_t)length)) il2cpp_codegen_raise_index_out_of_range_exception(); \
    } while (0)

bool il2cpp_codegen_class_is_assignable_from(RuntimeClass *klass, RuntimeClass *oklass);

RuntimeObject* il2cpp_codegen_object_new(RuntimeClass *klass);

Il2CppMethodPointer il2cpp_codegen_resolve_icall(const char* name);

Il2CppMethodPointer il2cpp_codegen_resolve(const PInvokeArguments& pinvokeArgs);

template<typename FunctionPointerType, size_t dynamicLibraryLength, size_t entryPointLength>
inline FunctionPointerType il2cpp_codegen_resolve_pinvoke(const Il2CppNativeChar(&nativeDynamicLibrary)[dynamicLibraryLength], const char(&entryPoint)[entryPointLength],
    Il2CppCallConvention callingConvention, Il2CppCharSet charSet, int parameterSize, bool isNoMangle)
{
    const PInvokeArguments pinvokeArgs =
    {
        il2cpp::utils::StringView<Il2CppNativeChar>(nativeDynamicLibrary),
        il2cpp::utils::StringView<char>(entryPoint),
        callingConvention,
        charSet,
        parameterSize,
        isNoMangle
    };

    return reinterpret_cast<FunctionPointerType>(il2cpp_codegen_resolve(pinvokeArgs));
}

void* il2cpp_codegen_marshal_allocate(size_t size);

template<typename T>
inline T* il2cpp_codegen_marshal_allocate_array(size_t length)
{
    return static_cast<T*>(il2cpp_codegen_marshal_allocate((il2cpp_array_size_t)(sizeof(T) * length)));
}

template<typename T>
inline T* il2cpp_codegen_marshal_allocate()
{
    return static_cast<T*>(il2cpp_codegen_marshal_allocate(sizeof(T)));
}

char* il2cpp_codegen_marshal_string(String_t* string);

void il2cpp_codegen_marshal_string_fixed(String_t* string, char* buffer, int numberOfCharacters);

Il2CppChar* il2cpp_codegen_marshal_wstring(String_t* string);

void il2cpp_codegen_marshal_wstring_fixed(String_t* string, Il2CppChar* buffer, int numberOfCharacters);

Il2CppChar* il2cpp_codegen_marshal_bstring(String_t* string);

String_t* il2cpp_codegen_marshal_string_result(const char* value);

String_t* il2cpp_codegen_marshal_wstring_result(const Il2CppChar* value);

String_t* il2cpp_codegen_marshal_bstring_result(const Il2CppChar* value);

void il2cpp_codegen_marshal_free_bstring(Il2CppChar* value);

char* il2cpp_codegen_marshal_empty_string_builder(StringBuilder_t* stringBuilder);

char* il2cpp_codegen_marshal_string_builder(StringBuilder_t* stringBuilder);

Il2CppChar* il2cpp_codegen_marshal_empty_wstring_builder(StringBuilder_t* stringBuilder);

Il2CppChar* il2cpp_codegen_marshal_wstring_builder(StringBuilder_t* stringBuilder);

void il2cpp_codegen_marshal_string_builder_result(StringBuilder_t* stringBuilder, char* buffer);

void il2cpp_codegen_marshal_wstring_builder_result(StringBuilder_t* stringBuilder, Il2CppChar* buffer);

Il2CppHString il2cpp_codegen_create_hstring(String_t* str);

String_t* il2cpp_codegen_marshal_hstring_result(Il2CppHString hstring);

void il2cpp_codegen_marshal_free_hstring(Il2CppHString hstring);

void il2cpp_codegen_marshal_type_to_native(Type_t* type, Il2CppWindowsRuntimeTypeName& nativeType);

const Il2CppType* il2cpp_codegen_marshal_type_from_native_internal(Il2CppWindowsRuntimeTypeName& nativeType);

inline Type_t* il2cpp_codegen_marshal_type_from_native(Il2CppWindowsRuntimeTypeName& nativeType)
{
    const Il2CppType* type = il2cpp_codegen_marshal_type_from_native_internal(nativeType);
    if (type == NULL)
        return NULL;

    return il2cpp_codegen_type_get_object(type);
}

void il2cpp_codegen_delete_native_type(Il2CppWindowsRuntimeTypeName& nativeType);

void il2cpp_codegen_marshal_free(void* ptr);

Il2CppMethodPointer il2cpp_codegen_marshal_delegate(MulticastDelegate_t* d);

Il2CppDelegate* il2cpp_codegen_marshal_function_ptr_to_delegate_internal(void* functionPtr, Il2CppClass* delegateType);

bool il2cpp_codegen_is_marshalled_delegate(MulticastDelegate_t* d);

inline void* il2cpp_codegen_get_reverse_pinvoke_function_ptr(const MulticastDelegate_t* d)
{
    return ((Il2CppDelegate*)d)->delegate_trampoline;
}

template<typename T>
inline T* il2cpp_codegen_marshal_function_ptr_to_delegate(Il2CppMethodPointer functionPtr, RuntimeClass* delegateType)
{
    return (T*)il2cpp_codegen_marshal_function_ptr_to_delegate_internal(reinterpret_cast<void*>(functionPtr), delegateType);
}

void il2cpp_codegen_marshal_store_last_error();

template<typename R, typename S>
inline R il2cpp_codegen_cast_struct(const S& s)
{
    static_assert(sizeof(S) == sizeof(R), "Types with different sizes passed to il2cpp_codegen_cast_struct");
    R r;
    il2cpp_codegen_memcpy(&r, &s, sizeof(R));
    return r;
}

#if _DEBUG

void il2cpp_codegen_marshal_allocate_push_allocation_frame();

void il2cpp_codegen_marshal_allocate_pop_allocation_frame();

bool il2cpp_codegen_marshal_allocate_has_unfreed_allocations();

void il2cpp_codegen_marshal_allocate_clear_all_tracked_allocations();

struct ScopedMarshallingAllocationFrame
{
    ScopedMarshallingAllocationFrame()
    {
        il2cpp_codegen_marshal_allocate_push_allocation_frame();
    }

    ~ScopedMarshallingAllocationFrame()
    {
        il2cpp_codegen_marshal_allocate_pop_allocation_frame();
    }
};

struct ScopedMarshallingAllocationCheck
{
    ~ScopedMarshallingAllocationCheck()
    {
        if (il2cpp_codegen_marshal_allocate_has_unfreed_allocations())
            il2cpp_codegen_raise_exception(il2cpp_codegen_get_invalid_operation_exception("Error in marshaling allocation. Some memory has been leaked."));
    }

private:
    ScopedMarshallingAllocationFrame m_AllocationFrame;
};

struct ScopedMarshalingAllocationClearer
{
    ~ScopedMarshalingAllocationClearer()
    {
        il2cpp_codegen_marshal_allocate_clear_all_tracked_allocations();
    }

private:
    ScopedMarshallingAllocationFrame m_AllocationFrame;
};

#endif

inline void DivideByZeroCheck(int64_t denominator)
{
    if (denominator != 0)
        return;

    il2cpp_codegen_raise_divide_by_zero_exception();
}

bool MethodIsStatic(const RuntimeMethod* method);

bool MethodHasParameters(const RuntimeMethod* method);

void il2cpp_codegen_runtime_class_init(RuntimeClass* klass);

inline void il2cpp_codegen_runtime_class_init_inline(RuntimeClass* klass)
{
    if (!klass->cctor_finished_or_no_cctor)
        il2cpp_codegen_runtime_class_init(klass);
}

// generic sharing
inline RuntimeClass* il2cpp_rgctx_data(const Il2CppRGCTXData* rgctxVar, int32_t index)
{
    return InitializedTypeInfo(rgctxVar[index].klass);
}

inline RuntimeClass* il2cpp_rgctx_data_no_init(const Il2CppRGCTXData* rgctxVar, int32_t index)
{
    return rgctxVar[index].klass;
}

inline const Il2CppType* il2cpp_rgctx_type(const Il2CppRGCTXData* rgctxVar, int32_t index)
{
    return rgctxVar[index].type;
}

inline const MethodInfo* il2cpp_rgctx_method(const Il2CppRGCTXData* rgctxVar, int32_t index)
{
    return rgctxVar[index].method;
}

inline FieldInfo* il2cpp_rgctx_field(RuntimeClass* klass, int32_t index)
{
    return klass->fields + index;
}

inline bool il2cpp_rgctx_is_initialized(const RuntimeMethod* method)
{
    IL2CPP_ASSERT(method->is_inflated);
    return method->rgctx_data != NULL;
}

inline void il2cpp_rgctx_method_init(const RuntimeMethod* method)
{
    il2cpp::vm::ClassInlines::InitRgcxFromCodegen(method);
}

inline uintptr_t il2cpp_array_calc_byte_offset(RuntimeArray* runtimeArray, il2cpp_array_size_t index)
{
    return runtimeArray->klass->element_size * index;
}

inline void ArrayElementTypeCheck(RuntimeArray* array, void* value)
{
    if (value != NULL && IsInst((RuntimeObject*)value, array->klass->element_class) == NULL)
        il2cpp_codegen_raise_exception(il2cpp_codegen_get_array_type_mismatch_exception());
}

inline const RuntimeMethod* GetVirtualMethodInfo(RuntimeObject* pThis, Il2CppMethodSlot slot)
{
    if (!pThis)
        il2cpp_codegen_raise_null_reference_exception();

    return pThis->klass->vtable[slot].method;
}

inline const RuntimeMethod* GetVirtualMethodInfo(RuntimeClass* klass, Il2CppMethodSlot slot)
{
    return klass->vtable[slot].method;
}

inline const RuntimeMethod* GetInterfaceMethodInfo(RuntimeObject* pThis, Il2CppMethodSlot slot, RuntimeClass* declaringInterface)
{
    if (!pThis)
        il2cpp_codegen_raise_null_reference_exception();

    return il2cpp::vm::ClassInlines::GetInterfaceInvokeDataFromVTable(pThis, declaringInterface, slot).method;
}

inline const RuntimeMethod* GetInterfaceMethodInfo(const RuntimeClass* klass, Il2CppMethodSlot slot, RuntimeClass* declaringInterface)
{
    return il2cpp::vm::ClassInlines::GetInterfaceInvokeDataFromVTable(klass, declaringInterface, slot).method;
}

void il2cpp_codegen_initialize_runtime_metadata(uintptr_t* metadataPointer);

void* il2cpp_codegen_initialize_runtime_metadata_inline(uintptr_t* metadataPointer);

inline bool il2cpp_codegen_type_is_value_type(const RuntimeType* type)
{
    return type->valuetype;
}

inline bool il2cpp_codegen_class_is_value_type(RuntimeClass* type)
{
    return il2cpp_codegen_type_is_value_type(&type->byval_arg);
}

inline bool il2cpp_codegen_class_is_enum(RuntimeClass* type)
{
    return type->enumtype;
}

inline bool il2cpp_codegen_class_is_byref_like(RuntimeClass* type)
{
    return type->is_byref_like;
}

bool il2cpp_codegen_class_is_nullable(RuntimeClass* type);
bool il2cpp_codegen_class_is_primitive(RuntimeClass* type);

inline bool il2cpp_codegen_type_implements_virtual_method(RuntimeClass* type, const RuntimeMethod* method)
{
    IL2CPP_ASSERT(il2cpp_codegen_class_is_value_type(type));
    return method->klass == type;
}

MethodBase_t* il2cpp_codegen_get_method_object_internal(const RuntimeMethod* method, RuntimeClass* refclass);

const RuntimeClass* il2cpp_codegen_get_generic_type_definition(const RuntimeClass* klass);
const RuntimeMethod* il2cpp_codegen_get_generic_method_definition(const RuntimeMethod* method);
const RuntimeMethod* il2cpp_codegen_get_generic_instance_method_from_method_definition(RuntimeClass* genericInstanceClass, const RuntimeMethod* methodDefinition);

// Atomic

void* il2cpp_codegen_atomic_compare_exchange_pointer(void** dest, void* exchange, void* comparand);

// COM

void il2cpp_codegen_com_marshal_variant(RuntimeObject* obj, Il2CppVariant* variant);

RuntimeObject* il2cpp_codegen_com_marshal_variant_result(const Il2CppVariant* variant);

void il2cpp_codegen_com_destroy_variant(Il2CppVariant* variant);

Il2CppSafeArray* il2cpp_codegen_com_marshal_safe_array(Il2CppChar type, RuntimeArray* managedArray);

RuntimeArray* il2cpp_codegen_com_marshal_safe_array_result(Il2CppChar variantType, RuntimeClass* type, Il2CppSafeArray* safeArray);

Il2CppSafeArray* il2cpp_codegen_com_marshal_safe_array_bstring(RuntimeArray* managedArray);

RuntimeArray* il2cpp_codegen_com_marshal_safe_array_bstring_result(RuntimeClass* type, Il2CppSafeArray* safeArray);

void il2cpp_codegen_com_destroy_safe_array(Il2CppSafeArray* safeArray);

void il2cpp_codegen_com_create_instance(const Il2CppGuid& clsid, Il2CppIUnknown** identity);

void il2cpp_codegen_com_register_rcw(Il2CppComObject* rcw);

RuntimeObject* il2cpp_codegen_com_get_or_create_rcw_from_iunknown_internal(Il2CppIUnknown* unknown, RuntimeClass* fallbackClass);

template<typename T>
inline T* il2cpp_codegen_com_get_or_create_rcw_from_iunknown(Il2CppIUnknown* unknown, RuntimeClass* fallbackClass)
{
    return static_cast<T*>(il2cpp_codegen_com_get_or_create_rcw_from_iunknown_internal(unknown, fallbackClass));
}

RuntimeObject* il2cpp_codegen_com_get_or_create_rcw_from_iinspectable_internal(Il2CppIInspectable* unknown, RuntimeClass* fallbackClass);

template<typename T>
inline T* il2cpp_codegen_com_get_or_create_rcw_from_iinspectable(Il2CppIInspectable* unknown, RuntimeClass* fallbackClass)
{
    return static_cast<T*>(il2cpp_codegen_com_get_or_create_rcw_from_iinspectable_internal(unknown, fallbackClass));
}

RuntimeObject* il2cpp_codegen_com_get_or_create_rcw_for_sealed_class_internal(Il2CppIUnknown* unknown, RuntimeClass* objectClass);

template<typename T>
inline T* il2cpp_codegen_com_get_or_create_rcw_for_sealed_class(Il2CppIUnknown* unknown, RuntimeClass* objectClass)
{
    return static_cast<T*>(il2cpp_codegen_com_get_or_create_rcw_for_sealed_class_internal(unknown, objectClass));
}

Il2CppIUnknown* il2cpp_codegen_com_query_interface_internal(Il2CppComObject* rcw, const Il2CppGuid& guid);
Il2CppIUnknown* il2cpp_codegen_com_query_interface_no_throw_internal(Il2CppComObject* rcw, const Il2CppGuid& guid);
void il2cpp_codegen_com_cache_queried_interface(Il2CppComObject* rcw, const Il2CppGuid& guid, Il2CppIUnknown* queriedInterface);

template<typename T>
inline T* il2cpp_codegen_com_query_interface(Il2CppComObject* rcw)
{
    return static_cast<T*>(il2cpp_codegen_com_query_interface_internal(rcw, T::IID));
}

template<typename T>
inline T* il2cpp_codegen_com_query_interface_no_throw(Il2CppComObject* rcw)
{
    return static_cast<T*>(il2cpp_codegen_com_query_interface_no_throw_internal(rcw, T::IID));
}

void il2cpp_codegen_il2cpp_com_object_cleanup(Il2CppComObject* rcw);

Il2CppIUnknown* il2cpp_codegen_com_get_or_create_ccw_internal(RuntimeObject* obj, const Il2CppGuid& iid);

template<typename InterfaceType>
inline InterfaceType* il2cpp_codegen_com_get_or_create_ccw(RuntimeObject* obj)
{
    return static_cast<InterfaceType*>(il2cpp_codegen_com_get_or_create_ccw_internal(obj, InterfaceType::IID));
}

Il2CppObject* il2cpp_codegen_com_unpack_ccw(Il2CppIUnknown* obj);

inline void il2cpp_codegen_com_raise_exception_if_failed(il2cpp_hresult_t hr, bool defaultToCOMException)
{
    // Copied from il2cpp::vm::Exception::RaiseIfFailed to keep inlined
    if (IL2CPP_HR_FAILED(hr))
        il2cpp_codegen_raise_exception(hr, defaultToCOMException);
}

inline RuntimeException* il2cpp_codegen_com_get_exception(il2cpp_hresult_t hr, bool defaultToCOMException)
{
    return (RuntimeException*)il2cpp_codegen_get_exception(hr, defaultToCOMException);
}

il2cpp_hresult_t il2cpp_codegen_com_handle_invalid_iproperty_conversion(const char* fromType, const char* toType);

il2cpp_hresult_t il2cpp_codegen_com_handle_invalid_iproperty_conversion(RuntimeObject* value, const char* fromType, const char* toType);

il2cpp_hresult_t il2cpp_codegen_com_handle_invalid_ipropertyarray_conversion(const char* fromArrayType, const char* fromElementType, const char* toElementType, il2cpp_array_size_t index);

il2cpp_hresult_t il2cpp_codegen_com_handle_invalid_ipropertyarray_conversion(RuntimeObject* value, const char* fromArrayType, const char* fromElementType, const char* toElementType, il2cpp_array_size_t index);

void il2cpp_codegen_store_exception_info(RuntimeException* ex, String_t* exceptionString);

Il2CppIActivationFactory* il2cpp_codegen_windows_runtime_get_activation_factory(const il2cpp::utils::StringView<Il2CppNativeChar>& runtimeClassName);

// delegate

Il2CppAsyncResult* il2cpp_codegen_delegate_begin_invoke(RuntimeDelegate* delegate, void** params, RuntimeDelegate* asyncCallback, RuntimeObject* state);

RuntimeObject* il2cpp_codegen_delegate_end_invoke(Il2CppAsyncResult* asyncResult, void **out_args);

void il2cpp_codegen_set_closed_delegate_invoke(RuntimeObject* delegate, RuntimeObject* target, void* methodPtr);

inline const Il2CppGenericInst* il2cpp_codegen_get_generic_class_inst(RuntimeClass* genericClass)
{
    IL2CPP_ASSERT(genericClass->generic_class);
    return genericClass->generic_class->context.class_inst;
}

RuntimeClass* il2cpp_codegen_get_generic_argument(RuntimeClass* klass, uint32_t argNum);

// Inflate a generic class from an existing generic instance
RuntimeClass* il2cpp_codegen_inflate_generic_class(RuntimeClass* genericClassDefinition, const Il2CppGenericInst* genericInst);

// Inflate a generic class from types
RuntimeClass* il2cpp_codegen_inflate_generic_class(RuntimeClass* genericClassDefinition, const RuntimeType*, /*const RuntimeType*, const RuntimeType* */ ...);

inline void* il2cpp_codegen_static_fields_for(RuntimeClass* klass)
{
    return klass->static_fields;
}

void il2cpp_codegen_assert_field_size(RuntimeField* field, size_t size);

void* il2cpp_codegen_get_instance_field_data_pointer(void* instance, RuntimeField* field);
inline void* il2cpp_codegen_get_instance_field_data_pointer(intptr_t instance, RuntimeField* field)
{
    return il2cpp_codegen_get_instance_field_data_pointer((void*)instance, field);
}

inline void* il2cpp_codegen_get_instance_field_data_pointer(uintptr_t instance, RuntimeField* field)
{
    return il2cpp_codegen_get_instance_field_data_pointer((void*)instance, field);
}

void il2cpp_codegen_write_instance_field_data(void* instance, RuntimeField* field, void* data, uint32_t size);
inline void il2cpp_codegen_write_instance_field_data(intptr_t instance, RuntimeField* field, void* data, uint32_t size)
{
    il2cpp_codegen_write_instance_field_data((void*)instance, field, data, size);
}

inline void il2cpp_codegen_write_instance_field_data(uintptr_t instance, RuntimeField* field, void* data, uint32_t size)
{
    il2cpp_codegen_write_instance_field_data((void*)instance, field, data, size);
}

void* il2cpp_codegen_get_static_field_data_pointer(RuntimeField* field);
void il2cpp_codegen_write_static_field_data(RuntimeField* field, void* data, uint32_t size);
void* il2cpp_codegen_get_thread_static_field_data_pointer(RuntimeField* field);
void il2cpp_codegen_write_thread_static_field_data(RuntimeField* field, void* data, uint32_t size);

template<typename T>
void il2cpp_codegen_write_instance_field_data(void* instance, RuntimeField* field, no_infer<T> data)
{
    il2cpp_codegen_assert_field_size(field, sizeof(T));

    void* fieldPointer = il2cpp_codegen_get_instance_field_data_pointer(instance, field);
    *(T*)fieldPointer = data;
    Il2CppCodeGenWriteBarrierForType(field->type, (void**)fieldPointer, NULL);
}

template<typename T>
inline void il2cpp_codegen_write_instance_field_data(intptr_t instance, RuntimeField* field, no_infer<T> data)
{
    il2cpp_codegen_write_instance_field_data<T>((void*)instance, field, data);
}

template<typename T>
inline void il2cpp_codegen_write_instance_field_data(uintptr_t instance, RuntimeField* field, no_infer<T> data)
{
    il2cpp_codegen_write_instance_field_data<T>((void*)instance, field, data);
}

template<typename T>
void il2cpp_codegen_write_static_field_data(RuntimeField* field, no_infer<T> data)
{
    il2cpp_codegen_assert_field_size(field, sizeof(T));

    void* fieldPointer = il2cpp_codegen_get_static_field_data_pointer(field);
    *(T*)fieldPointer = data;
    Il2CppCodeGenWriteBarrierForType(field->type, (void**)fieldPointer, NULL);
}

template<typename T>
void il2cpp_codegen_write_thread_static_field_data(RuntimeField* field, no_infer<T> data)
{
    il2cpp_codegen_assert_field_size(field, sizeof(T));

    void* fieldPointer = il2cpp_codegen_get_thread_static_field_data_pointer(field);
    *(T*)fieldPointer = data;
    Il2CppCodeGenWriteBarrierForType(field->type, (void**)fieldPointer, NULL);
}

inline Il2CppMethodPointer il2cpp_codegen_get_method_pointer(const RuntimeMethod* method)
{
    return method->virtualMethodPointer;
}

inline Il2CppMethodPointer il2cpp_codegen_get_direct_method_pointer(const RuntimeMethod* method)
{
    return method->methodPointer;
}

inline const RuntimeType* il2cpp_codegen_method_return_type(const RuntimeMethod* method)
{
    return method->return_type;
}

inline int il2cpp_codegen_method_parameter_count(const RuntimeMethod* method)
{
    return method->parameters_count;
}

inline const RuntimeType* il2cpp_codegen_method_parameter_type(const RuntimeMethod* method, int parameterIndex)
{
    IL2CPP_ASSERT(parameterIndex >= 0 && parameterIndex < method->parameters_count);
    return method->parameters[parameterIndex];
}

inline bool il2cpp_codegen_is_import_or_windows_runtime(const RuntimeObject *object)
{
    return object->klass->is_import_or_windows_runtime;
}

NORETURN void il2cpp_codegen_raise_profile_exception(const RuntimeMethod* method);

void il2cpp_codegen_array_unsafe_mov(RuntimeClass * destClass, void* dest, RuntimeClass * srcClass, void* src);
NORETURN void il2cpp_codegen_array_unsafe_mov_type_exception(const RuntimeType * destType, const RuntimeType* srcType);

template<typename T>
T il2cpp_codegen_read_to_aligned_value(void* src)
{
    T value;
    memcpy(&value, src, sizeof(T));
    return value;
}

template<typename TDest>
inline void il2cpp_codegen_array_unsafe_mov_primitive(const RuntimeType * destType, TDest* dest, const RuntimeType* srcType, void* src)
{
    switch (srcType->type)
    {
        case IL2CPP_TYPE_BOOLEAN:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<bool>(src);
            break;
        case IL2CPP_TYPE_I1:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<int8_t>(src);
            break;
        case IL2CPP_TYPE_U1:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<uint8_t>(src);
            break;
        case IL2CPP_TYPE_I2:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<int16_t>(src);
            break;
        case IL2CPP_TYPE_CHAR:
        case IL2CPP_TYPE_U2:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<uint16_t>(src);
            break;
        case IL2CPP_TYPE_I4:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<int32_t>(src);
            break;
        case IL2CPP_TYPE_U4:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<uint32_t>(src);
            break;
        case IL2CPP_TYPE_I8:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<int64_t>(src);
            break;
        case IL2CPP_TYPE_U8:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<uint64_t>(src);
            break;
        case IL2CPP_TYPE_I:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<intptr_t>(src);
            break;
        case IL2CPP_TYPE_U:
            *dest = (TDest)il2cpp_codegen_read_to_aligned_value<uintptr_t>(src);
            break;
        default:
            il2cpp_codegen_array_unsafe_mov_type_exception(destType, srcType);
    }
}

template<typename TDest, bool checkOverflow, bool inputUnsigned>
TDest il2cpp_codegen_conv(const RuntimeClass* srcType, void* src, const RuntimeMethod* method)
{
    switch (srcType->castClass->byval_arg.type)
    {
        case IL2CPP_TYPE_BOOLEAN:
        case IL2CPP_TYPE_I1:
            return il2cpp_codegen_conv<TDest, int8_t, int32_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<int8_t>(src), method);
        case IL2CPP_TYPE_U1:
            return il2cpp_codegen_conv<TDest, uint8_t, int32_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<uint8_t>(src), method);
        case IL2CPP_TYPE_I2:
            return il2cpp_codegen_conv<TDest, int16_t, int32_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<int16_t>(src), method);
        case IL2CPP_TYPE_CHAR:
        case IL2CPP_TYPE_U2:
            return il2cpp_codegen_conv<TDest, uint16_t, int32_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<uint16_t>(src), method);
        case IL2CPP_TYPE_I4:
            return il2cpp_codegen_conv<TDest, int32_t, int32_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<int32_t>(src), method);
        case IL2CPP_TYPE_U4:
            return il2cpp_codegen_conv<TDest, uint32_t, int32_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<uint32_t>(src), method);
        case IL2CPP_TYPE_I8:
            return il2cpp_codegen_conv<TDest, int64_t, int64_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<int64_t>(src), method);
        case IL2CPP_TYPE_U8:
            return il2cpp_codegen_conv<TDest, uint64_t, int64_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<uint64_t>(src), method);
        case IL2CPP_TYPE_I:
        case IL2CPP_TYPE_PTR:
        case IL2CPP_TYPE_OBJECT:
            return il2cpp_codegen_conv<TDest, intptr_t, intptr_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<intptr_t>(src), method);
        case IL2CPP_TYPE_U:
            return il2cpp_codegen_conv<TDest, uintptr_t, intptr_t, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<uintptr_t>(src), method);
        case IL2CPP_TYPE_R4:
            return il2cpp_codegen_conv<TDest, float, float, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<float>(src), method);
        case IL2CPP_TYPE_R8:
            return il2cpp_codegen_conv<TDest, double, double, checkOverflow, inputUnsigned>(il2cpp_codegen_read_to_aligned_value<double>(src), method);
        default:
            IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_invalid_operation_exception("Unsupported conv opcode"), method);
    }
    return 0;
}

struct Il2CppConstrainedCallData
{
    const RuntimeMethod* method;
    void* thisPtr;
};

// objBuffer is a pointer to the obj, either a pointer to a struct's data or a pointer to a reference type pointer
Il2CppMethodPointer il2cpp_codegen_get_runtime_constrained_call_data(RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* objBuffer, Il2CppConstrainedCallData* data, void* boxBuffer);

Il2CppMethodPointer il2cpp_codegen_get_runtime_static_constrained_call_data(RuntimeClass* type, const RuntimeMethod* constrainedMethod, const RuntimeMethod** resolvedMethod);

inline Il2CppMethodPointer il2cpp_codegen_get_runtime_static_constrained_call_data(const RuntimeMethod* constrainedMethod)
{
    il2cpp_codegen_runtime_class_init_inline(constrainedMethod->klass);
    return constrainedMethod->methodPointer;
}

inline void il2cpp_codegen_by_reference_constructor(Il2CppByReference* byReference, void* value)
{
    IL2CPP_ASSERT_STACK_PTR(byReference);
    byReference->value = (intptr_t)value;
}

inline intptr_t il2cpp_codegen_by_reference_get_value(Il2CppByReference* byReference)
{
    return byReference->value;
}

#define IL2CPP_BY_REFERENCE_GET_VALUE(TReturnType, byReference) (TReturnType*)il2cpp_codegen_by_reference_get_value(byReference)

bool il2cpp_codegen_is_reference_or_contains_references(const RuntimeMethod* method);

// Can't move to il2cpp-codegen-intrinsics.h because it needs `IL2CPP_ARRAY_BOUNDS_CHECK`
#if !MONO_NET8_BCL
template<typename T>
inline T* il2cpp_span_get_item(T* refPtrValue, int32_t index, int32_t length)
{
    IL2CPP_ARRAY_BOUNDS_CHECK(index, length);
    return &refPtrValue[index];
}

template<typename T>
inline T* il2cpp_unsafe_unbox(RuntimeObject* obj, RuntimeClass* klass)
{
    return reinterpret_cast<T*>(UnBox(obj, klass));
}

#endif

template<typename T>
inline void il2cpp_unsafe_copy_from_ptr(T* dest, void* src)
{
    *dest = *reinterpret_cast<T*>(src);
}

template<typename T>
inline void il2cpp_unsafe_copy_to_ptr(void* dest, T* src)
{
    *reinterpret_cast<T*>(dest) = *src;
}

inline void il2cpp_unsafe_copy_block(void* dest, void* src, size_t size)
{
    memcpy(dest, src, size);
}

#if IL2CPP_COMPILER_MSVC
#define DEFAULT_CALL STDCALL
#else
#define DEFAULT_CALL
#endif

#if defined(__ARMCC_VERSION)
inline double bankers_round(double x)
{
    return __builtin_round(x);
}

inline float bankers_roundf(float x)
{
    return __builtin_roundf(x);
}

#else
inline double bankers_round(double x)
{
    double integerPart;
    if (x >= 0.0)
    {
        if (modf(x, &integerPart) == 0.5)
            return (int64_t)integerPart % 2 == 0 ? integerPart : integerPart + 1.0;
        return floor(x + 0.5);
    }
    else
    {
        if (modf(x, &integerPart) == -0.5)
            return (int64_t)integerPart % 2 == 0 ? integerPart : integerPart - 1.0;
        return ceil(x - 0.5);
    }
}

inline float bankers_roundf(float x)
{
    double integerPart;
    if (x >= 0.0f)
    {
        if (modf(x, &integerPart) == 0.5)
            return (int64_t)integerPart % 2 == 0 ? (float)integerPart : (float)integerPart + 1.0f;
        return floorf(x + 0.5f);
    }
    else
    {
        if (modf(x, &integerPart) == -0.5)
            return (int64_t)integerPart % 2 == 0 ? (float)integerPart : (float)integerPart - 1.0f;
        return ceilf(x - 0.5f);
    }
}

#endif

// returns true if overflow occurs
inline bool il2cpp_codegen_check_mul_overflow_i64(int64_t a, int64_t b, int64_t imin, int64_t imax)
{
    // TODO: use a better algorithm without division
    uint64_t ua = (uint64_t)llabs(a);
    uint64_t ub = (uint64_t)llabs(b);

    uint64_t c;
    if ((a > 0 && b > 0) || (a <= 0 && b <= 0))
        c = (uint64_t)llabs(imax);
    else
        c = (uint64_t)llabs(imin);

    return ua != 0 && ub > c / ua;
}

inline bool il2cpp_codegen_check_mul_oveflow_u64(uint64_t a, uint64_t b)
{
    return b != 0 && (a * b) / b != a;
}

inline int32_t il2cpp_codegen_abs(uint32_t value)
{
    return abs(static_cast<int32_t>(value));
}

inline int64_t il2cpp_codegen_abs(uint64_t value)
{
    return llabs(static_cast<int64_t>(value));
}

void il2cpp_codegen_memory_barrier();
void il2cpp_codegen_read_memory_barrier();

template<typename T>
inline T VolatileRead(T* location)
{
    T result = *location;
    il2cpp_codegen_memory_barrier();
    return result;
}

template<typename T, typename U>
inline void VolatileWrite(T** location, U* value)
{
    il2cpp_codegen_memory_barrier();
    *location = value;
    Il2CppCodeGenWriteBarrier((void**)location, value);
}

template<typename T, typename U>
inline void VolatileWrite(T* location, U value)
{
    il2cpp_codegen_memory_barrier();
    *location = value;
}

inline void il2cpp_codegen_write_to_stdout(const char* str)
{
    il2cpp::utils::Output::WriteToStdout(str);
}

inline void il2cpp_codegen_write_to_stderr(const char* str)
{
    il2cpp::utils::Output::WriteToStderr(str);
}

REAL_NORETURN void il2cpp_codegen_abort();

inline bool il2cpp_codegen_check_add_overflow(int64_t left, int64_t right)
{
    return (right >= 0 && left > kIl2CppInt64Max - right) ||
        (left < 0 && right < kIl2CppInt64Min - left);
}

inline bool il2cpp_codegen_check_sub_overflow(int64_t left, int64_t right)
{
    return (right >= 0 && left < kIl2CppInt64Min + right) ||
        (right < 0 && left > kIl2CppInt64Max + right);
}

inline void il2cpp_codegen_register_debugger_data(const Il2CppDebuggerMetadataRegistration *data)
{
#if IL2CPP_MONO_DEBUGGER
    il2cpp::utils::Debugger::RegisterMetadata(data);
#endif
}

inline void il2cpp_codegen_check_sequence_point(Il2CppSequencePointExecutionContext* executionContext, Il2CppSequencePoint* seqPoint)
{
#if IL2CPP_MONO_DEBUGGER
    il2cpp::utils::Debugger::CheckSequencePoint(executionContext, seqPoint);
#endif
}

inline void il2cpp_codegen_check_sequence_point_entry(Il2CppSequencePointExecutionContext* executionContext, Il2CppSequencePoint* seqPoint)
{
#if IL2CPP_MONO_DEBUGGER
    il2cpp::utils::Debugger::CheckSequencePointEntry(executionContext, seqPoint);
#endif
}

inline void il2cpp_codegen_check_sequence_point_exit(Il2CppSequencePointExecutionContext* executionContext, Il2CppSequencePoint* seqPoint)
{
#if IL2CPP_MONO_DEBUGGER
    il2cpp::utils::Debugger::CheckSequencePointExit(executionContext, seqPoint);
#endif
}

inline void il2cpp_codegen_check_pause_point()
{
#if IL2CPP_MONO_DEBUGGER
    il2cpp::utils::Debugger::CheckPausePoint();
#endif
}

class MethodExitSequencePointChecker
{
private:
    Il2CppSequencePoint* m_seqPoint;
    Il2CppSequencePointExecutionContext* m_seqPointStorage;

public:
    MethodExitSequencePointChecker(Il2CppSequencePointExecutionContext* seqPointStorage, Il2CppSequencePoint* seqPoint) :
        m_seqPointStorage(seqPointStorage), m_seqPoint(seqPoint)
    {
    }

    ~MethodExitSequencePointChecker()
    {
#if IL2CPP_MONO_DEBUGGER
        il2cpp_codegen_check_sequence_point_exit(m_seqPointStorage, m_seqPoint);
#endif
    }
};

#ifdef _MSC_VER
#define IL2CPP_DISABLE_OPTIMIZATIONS __pragma(optimize("", off))
#define IL2CPP_ENABLE_OPTIMIZATIONS __pragma(optimize("", on))
#elif IL2CPP_TARGET_LINUX || IL2CPP_TARGET_QNX
#define IL2CPP_DISABLE_OPTIMIZATIONS
#define IL2CPP_ENABLE_OPTIMIZATIONS
#else
#define IL2CPP_DISABLE_OPTIMIZATIONS __attribute__ ((optnone))
#define IL2CPP_ENABLE_OPTIMIZATIONS
#endif

// Array Unsafe
#define IL2CPP_ARRAY_UNSAFE_LOAD(TArray, TIndex) \
    (TArray)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(TIndex))

#ifdef GC_H
#error It looks like this codegen only header ends up including gc.h from the boehm gc. We should not expose boehmgc to generated code
#endif
#ifdef MONO_CONFIG_H_WAS_INCLUDED
#error It looks like this codegen only header ends up including headers from libmono. We should not expose those to generated code
#endif

template<typename THandleOnStack>
Il2CppObjectHandleOnStack& ToIl2CppObjectHandleOnStack(THandleOnStack& handle)
{
    static_assert(sizeof(THandleOnStack) == sizeof(Il2CppObjectHandleOnStack), "sizeof(Il2CppObjectHandleOnStack) does not match classlib size");
    return (Il2CppObjectHandleOnStack&)handle;
}

template<typename THandleOnStack, typename TValue>
void il2cpp_codegen_get_generic_value_icall(THandleOnStack handle, int index, TValue* value)
{
    RuntimeArray* arr = (RuntimeArray*)ToIl2CppObjectHandleOnStack(handle);

    IL2CPP_ASSERT_STACK_PTR(value);
    IL2CPP_ASSERT(sizeof(TValue) == arr->klass->element_size);

    *value = il2cpp_array_get(arr, TValue, index);
}

template<typename THandleOnStack>
void il2cpp_codegen_get_generic_value_icall(THandleOnStack handle, int index, void* value, size_t elementSize)
{
    RuntimeArray* arr = (RuntimeArray*)ToIl2CppObjectHandleOnStack(handle);

    IL2CPP_ASSERT_STACK_PTR(value);
    IL2CPP_ASSERT(elementSize == arr->klass->element_size);

    memcpy(value, il2cpp_array_addr_with_size(arr, elementSize, index), elementSize);
}

template<typename THandleOnStack, typename TValue>
void il2cpp_codegen_set_generic_value_icall(THandleOnStack handle, int index, TValue* value)
{
    RuntimeArray* arr = (RuntimeArray*)ToIl2CppObjectHandleOnStack(handle);

    IL2CPP_ASSERT(sizeof(TValue) == arr->klass->element_size);

    il2cpp_array_set(arr, TValue, index, *value);
}

template<typename THandleOnStack, typename TValue>
void il2cpp_codegen_set_generic_value_icall_with_barrier(THandleOnStack handle, int index, TValue* value)
{
    RuntimeArray* arr = (RuntimeArray*)ToIl2CppObjectHandleOnStack(handle);
    IL2CPP_ASSERT(sizeof(TValue) == arr->klass->element_size);

    il2cpp_array_setrefwithsize(arr, sizeof(TValue), index, value);
}

template<typename THandleOnStack>
void il2cpp_codegen_set_generic_value_icall(THandleOnStack handle, int index, void* value, size_t elementSize)
{
    RuntimeArray* arr = (RuntimeArray*)ToIl2CppObjectHandleOnStack(handle);

    IL2CPP_ASSERT(elementSize == arr->klass->element_size);

    void *dest = il2cpp_array_addr_with_size(arr, elementSize, index);
    memcpy(dest, value, elementSize);
    il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)dest, elementSize);
}

template<typename T>
inline void il2cpp_codegen_stind(T* dest, T source)
{
    memcpy(dest, &source, sizeof(T));
}

template<typename TStorage, typename TSource>
inline TStorage il2cpp_codegen_ldind(const TSource* source)
{
    TSource dest;
    memcpy(&dest, source, sizeof(TSource));
    return (TStorage)dest;
}
