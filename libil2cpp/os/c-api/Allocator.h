#pragma once

#include <stddef.h>
#include <stdint.h>

typedef void* (*allocate_func)(size_t size);
typedef void (*free_func)(void* memory);

#if defined(__cplusplus)
extern "C"
{
#endif

void register_allocator(allocate_func allocator, free_func release);
void free_memory(void* memory);

#if defined(__cplusplus)
}
#endif

#if defined(__cplusplus)
#include <string>
#include <vector>

class Allocator
{
public:
    static void* Allocate(size_t size);
    static void Free(void* memory);
    static char* CopyToAllocatedStringBuffer(const std::string& input);
    static char* CopyToAllocatedStringBuffer(const char* input);
    static void CopyStringVectorToNullTerminatedArray(const std::vector<std::string>& input, void*** output);
    static void CopyDataVectorToNullTerminatedArray(const std::vector<void*>& input, void*** output, int32_t elementSize);
};

#endif
