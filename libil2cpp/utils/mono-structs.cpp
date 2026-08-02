#include "mono-structs.h"
#include "os/c-api/il2cpp-config-platforms.h"
#include "os/c-api/Allocator.h"

static const MonoGPtrArray g_empty_gptr_array = { NULL, 0 };

template<typename T>
static size_t align_up_to(size_t size)
{
    // assumes alignof(T) is a power of 2
    return (size + alignof(T) - 1) & ~(alignof(T) - 1);
}

MonoGPtrArray* gptr_array_of_size(size_t size)
{
    // Assumes that a zero sized array will never be written to
    if (size == 0) return const_cast<MonoGPtrArray*>(empty_gptr_array());

    // Allocate a single buffer large enough to hold both the MonoGPtrArray and the array of pointers
    uint8_t* buffer = (uint8_t*)IL2CPP_MALLOC(align_up_to<void*>(sizeof(MonoGPtrArray)) + sizeof(void*) * size);
    MonoGPtrArray* pRetVal = (MonoGPtrArray*)buffer;
    pRetVal->len = (unsigned int)size;
    pRetVal->pdata = (void**)(buffer + align_up_to<void*>(sizeof(MonoGPtrArray)));

    return pRetVal;
}

const MonoGPtrArray* empty_gptr_array()
{
    return &g_empty_gptr_array;
}

void free_gptr_array(const MonoGPtrArray *pArray)
{
    if (!pArray || pArray == &g_empty_gptr_array)
        return;

    IL2CPP_FREE((void*)pArray);
}
