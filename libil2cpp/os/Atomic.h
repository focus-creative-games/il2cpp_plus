#pragma once

#include "c-api/il2cpp-config-platforms.h"

#include <stdint.h>
#include "utils/NonCopyable.h"

#include "Baselib.h"
#include "C/Baselib_Atomic_TypeSafe.h"

namespace il2cpp
{
namespace os
{
    class Atomic : public il2cpp::utils::NonCopyable
    {
    public:
        // All 32bit atomics must be performed on 4-byte aligned addresses. All 64bit atomics must be
        // performed on 8-byte aligned addresses.

        // Add and Add64 return the *result* of the addition, not the old value! (i.e. they work like
        // InterlockedAdd and __sync_add_and_fetch).

        static inline void FullMemoryBarrier()
        {
            Baselib_atomic_thread_fence_seq_cst();
        }

        static inline int32_t Add(int32_t* location1, int32_t value)
        {
            return Baselib_atomic_fetch_add_32_seq_cst(location1, value) + value;
        }

        static inline uint32_t Add(uint32_t* location1, uint32_t value)
        {
            return (uint32_t)Add((int32_t*)location1, (int32_t)value);
        }

#if IL2CPP_ENABLE_INTERLOCKED_64_REQUIRED_ALIGNMENT
        static inline int64_t Add64(int64_t* location1, int64_t value)
        {
            return Baselib_atomic_fetch_add_64_seq_cst(location1, value) + value;
        }

#endif

        template<typename T>
        static inline T* CompareExchangePointer(T** dest, T* newValue, T* oldValue)
        {
            Baselib_atomic_compare_exchange_strong_ptr_seq_cst_seq_cst((intptr_t*)dest, (intptr_t*)&oldValue, (intptr_t)newValue);
            return static_cast<T*>(oldValue);
        }

        template<typename T>
        static inline T* ExchangePointer(T** dest, T* newValue)
        {
            return (T*)Baselib_atomic_exchange_ptr_seq_cst((intptr_t*)dest, (intptr_t)newValue);
        }

        static inline int64_t Read64(int64_t* addr)
        {
            return Baselib_atomic_fetch_add_64_seq_cst(addr, 0);
        }

        static inline uint64_t Read64(uint64_t* addr)
        {
            return (uint64_t)Read64((int64_t*)addr);
        }

        static inline int32_t LoadRelaxed(const int32_t* addr)
        {
            return Baselib_atomic_load_32_relaxed(addr);
        }

        template<typename T>
        static inline T* LoadPointerRelaxed(const T* const * addr)
        {
            return (T*)Baselib_atomic_load_ptr_relaxed((const intptr_t*)addr);
        }

        template<typename T>
        static inline T* ReadPointer(T** pointer)
        {
        #if IL2CPP_SIZEOF_VOID_P == 4
            return reinterpret_cast<T*>(Add(reinterpret_cast<int32_t*>(pointer), 0));
        #else
            return reinterpret_cast<T*>(Read64(reinterpret_cast<int64_t*>(pointer)));
        #endif
        }

        static inline int32_t Increment(int32_t* value)
        {
            return Baselib_atomic_fetch_add_32_seq_cst(value, 1) + 1;
        }

        static inline uint32_t Increment(uint32_t* value)
        {
            return (uint32_t)Increment((int32_t*)value);
        }

#if IL2CPP_ENABLE_INTERLOCKED_64_REQUIRED_ALIGNMENT
        static inline int64_t Increment64(int64_t* value)
        {
            return Baselib_atomic_fetch_add_64_seq_cst(value, 1) + 1;
        }

        static inline uint64_t Increment64(uint64_t* value)
        {
            return (uint64_t)Increment64((int64_t*)value);
        }

#endif

        static inline int32_t Decrement(int32_t* value)
        {
            return Baselib_atomic_fetch_add_32_seq_cst(value, -1) - 1;
        }

        static inline uint32_t Decrement(uint32_t* value)
        {
            return (uint32_t)Decrement((int32_t*)value);
        }

#if IL2CPP_ENABLE_INTERLOCKED_64_REQUIRED_ALIGNMENT
        static inline int64_t Decrement64(int64_t* value)
        {
            return Baselib_atomic_fetch_add_64_seq_cst(value, -1) - 1;
        }

        static inline uint64_t Decrement64(uint64_t* value)
        {
            return (uint64_t)Decrement64((int64_t*)value);
        }

#endif

        static inline int32_t CompareExchange(int32_t* dest, int32_t exchange, int32_t comparand)
        {
            Baselib_atomic_compare_exchange_strong_32_seq_cst_seq_cst(dest, &comparand, exchange);
            return comparand;
        }

        static inline uint32_t CompareExchange(uint32_t* value, uint32_t newValue, uint32_t oldValue)
        {
            return (uint32_t)CompareExchange((int32_t*)value, newValue, oldValue);
        }

        static inline int64_t CompareExchange64(int64_t* dest, int64_t exchange, int64_t comparand)
        {
            Baselib_atomic_compare_exchange_strong_64_seq_cst_seq_cst(dest, &comparand, exchange);
            return comparand;
        }

        static inline uint64_t CompareExchange64(uint64_t* value, uint64_t newValue, uint64_t oldValue)
        {
            return (uint64_t)CompareExchange64((int64_t*)value, newValue, oldValue);
        }

        static inline int32_t Exchange(int32_t* dest, int32_t exchange)
        {
            return Baselib_atomic_exchange_32_seq_cst(dest, exchange);
        }

        static inline uint32_t Exchange(uint32_t* value, uint32_t newValue)
        {
            return (uint32_t)Exchange((int32_t*)value, newValue);
        }

#if IL2CPP_ENABLE_INTERLOCKED_64_REQUIRED_ALIGNMENT
        static inline int64_t Exchange64(int64_t* dest, int64_t exchange)
        {
            return Baselib_atomic_exchange_64_seq_cst(dest, exchange);
        }

        static inline uint64_t Exchange64(uint64_t* value, uint64_t newValue)
        {
            return (uint64_t)Exchange64((int64_t*)value, newValue);
        }

#endif
        static inline intptr_t ReadPtrVal(intptr_t* addr)
        {
            return Baselib_atomic_fetch_add_ptr_seq_cst(addr, 0);
        }
    };
}
}
