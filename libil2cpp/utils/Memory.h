#pragma once

#include "il2cpp-config.h"
#include "il2cpp-runtime-stats.h"

namespace il2cpp
{
namespace utils
{
    struct LIBIL2CPP_CODEGEN_API Memory
    {
        static void SetMemoryCallbacks(Il2CppMemoryCallbacks* callbacks);

        // for Allocator only
        static void* Malloc(size_t size);
        static void Free(void* memory);

        static void* Malloc(size_t size, Il2CppMemLabel label);
        static void* AlignedMalloc(size_t size, size_t alignment, Il2CppMemLabel label);
        static void Free(void* memory, Il2CppMemLabel label);
        static void AlignedFree(void* memory, Il2CppMemLabel label);
        static void* Calloc(size_t count, size_t size, Il2CppMemLabel label);
        static void* Realloc(void* memory, size_t newSize, Il2CppMemLabel label);
        static void* AlignedRealloc(void* memory, size_t newSize, size_t alignment, Il2CppMemLabel label);
    };
} /* namespace utils */
} /* namespace il2cpp */

#define IL2CPP_MALLOC(size,lable) il2cpp::utils::Memory::Malloc(size,lable)
#define IL2CPP_MALLOC_ALIGNED(size, alignment,lable) il2cpp::utils::Memory::AlignedMalloc(size, alignment,lable)
#define IL2CPP_MALLOC_ZERO(size,lable) il2cpp::utils::Memory::Calloc(1,size,lable)
#define IL2CPP_FREE(memory,lable) il2cpp::utils::Memory::Free(memory,lable)
#define IL2CPP_FREE_ALIGNED(memory,lable) il2cpp::utils::Memory::AlignedFree(memory,lable)
#define IL2CPP_CALLOC(count, size,lable) il2cpp::utils::Memory::Calloc(count,size,lable)
#define IL2CPP_REALLOC(memory, newSize,lable) il2cpp::utils::Memory::Realloc(memory,newSize,lable)
#define IL2CPP_REALLOC_ALIGNED(memory, newSize, alignment,lable) il2cpp::utils::Memory::AlignedRealloc(memory, newSize, alignment,lable)

#if IL2CPP_TARGET_JAVASCRIPT
    #define HASH_MALLOC(size,lable) IL2CPP_MALLOC(size,lable)
    #define HASH_FREE(memory,lable) IL2CPP_FREE(memory,lable)
    #define HASH_REALLOC(memory, newSize,lable) IL2CPP_REALLOC(memory, newSize,lable)
#else
    #define HASH_MALLOC(size,lable) malloc(size)
    #define HASH_FREE(memory,lable) free(memory)
    #define HASH_REALLOC(memory, newSize,lable) realloc(memory, newSize)
#endif 

// allocator for il2cppHashSet/map
// IL2CPP_MALLOC can only be used on webgl platform, because globel hashset/map objects will be constructed before unity engine MemoryAllocator initializing.
template<class T>
class libc_allocator_with_realloc_il2cpp {
public:
    typedef T value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;

    libc_allocator_with_realloc_il2cpp() {}
    libc_allocator_with_realloc_il2cpp(const libc_allocator_with_realloc_il2cpp&) {}
    ~libc_allocator_with_realloc_il2cpp() {}

    pointer address(reference r) const { return &r; }
    const_pointer address(const_reference r) const { return &r; }

    pointer allocate(size_type n, const_pointer = 0) {
        il2cpp_runtime_stats.hashtable_mem += n * sizeof(value_type);
#if IL2CPP_ENABLE_MEM_STATS
        auto size = n * sizeof(value_type);
        void* ret = HASH_MALLOC(size, IL2CPP_MEM_HASH_TABLE);
        if (ret) {
            il2cpp_mem_stats.hash_table += size;

            auto& hashAllocMap = GetHashAllocMap();
            hashAllocMap[ret] = size;
        }
        return static_cast<pointer>(ret);
#else
        return static_cast<pointer>(HASH_MALLOC(n * sizeof(value_type), IL2CPP_MEM_HASH_TABLE));
#endif
    }
    void deallocate(pointer p, size_type n) {
        il2cpp_runtime_stats.hashtable_mem -= n * sizeof(value_type);
#if IL2CPP_ENABLE_MEM_STATS
        void* ptr = static_cast<void*>(p);
        if (ptr) {
            auto& hashAllocMap = GetHashAllocMap();
            auto it = hashAllocMap.find(ptr);
            if (it != hashAllocMap.end()) {
                il2cpp_mem_stats.hash_table -= it->second;
                hashAllocMap.erase(it);
            }
        }
#endif
        HASH_FREE(p, IL2CPP_MEM_HASH_TABLE);
    }
    pointer reallocate(pointer p, size_type n) {

        IL2CPP_NOT_IMPLEMENTED(libc_allocator_with_realloc_il2cpp::reallocate);
#if IL2CPP_ENABLE_MEM_STATS
        auto newSize = n * sizeof(value_type);
        void* ret = HASH_REALLOC(static_cast<void*>(p), newSize, IL2CPP_MEM_HASH_TABLE);
        void* ptr = static_cast<void*>(p);
        auto& hashAllocMap = GetHashAllocMap();
        if (ptr) {
            auto it = hashAllocMap.find(ptr);
            if (it != hashAllocMap.end()) {
                il2cpp_mem_stats.hash_table -= it->second;
                hashAllocMap.erase(it);
            }
        }
        if (ret) {
            il2cpp_mem_stats.hash_table += newSize;
            hashAllocMap[ret] = newSize;
        }
        return static_cast<pointer>(ret);
#else
        // p points to a storage array whose objects have already been destroyed
        // cast to void* to prevent compiler warnings about calling realloc() on
        // an object which cannot be relocated in memory
        return static_cast<pointer>(HASH_REALLOC(static_cast<void*>(p), n * sizeof(value_type) , IL2CPP_MEM_HASH_TABLE));
#endif
    }

    size_type max_size() const {
        return static_cast<size_type>(-1) / sizeof(value_type);
    }

    void construct(pointer p, const value_type& val) {
        new(p) value_type(val);
    }
    void destroy(pointer p) { p->~value_type(); }

    template <class U>
    libc_allocator_with_realloc_il2cpp(const libc_allocator_with_realloc_il2cpp<U>&) {}

    template<class U>
    struct rebind {
        typedef libc_allocator_with_realloc_il2cpp<U> other;
    };
};

// libc_allocator_with_realloc_il2cpp<void> specialization.
template<>
class libc_allocator_with_realloc_il2cpp<void> {
public:
    typedef void value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef void* pointer;
    typedef const void* const_pointer;

    template<class U>
    struct rebind {
        typedef libc_allocator_with_realloc_il2cpp<U> other;
    };
};

template<class T>
inline bool operator==(const libc_allocator_with_realloc_il2cpp<T>&,
    const libc_allocator_with_realloc_il2cpp<T>&) {
    return true;
}

template<class T>
inline bool operator!=(const libc_allocator_with_realloc_il2cpp<T>&,
    const libc_allocator_with_realloc_il2cpp<T>&) {
    return false;
}

#undef HASH_MALLOC
#undef HASH_FREE
#undef HASH_REALLOC