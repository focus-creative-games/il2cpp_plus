#include "il2cpp-config.h"
#include "MarshalAlloc.h"
#include "os/MarshalAlloc.h"
#include "os/ThreadLocalValue.h"
#include "vm/Exception.h"
#include <deque>

#include "Baselib.h"
#include "Cpp/ReentrantLock.h"

namespace il2cpp
{
namespace vm
{
#if _DEBUG

    struct TrackedAllocation
    {
        TrackedAllocation(void* ptr, size_t size) : ptr(ptr), size(size)
        {
        }

        void* ptr;
        size_t size;
    };

    static os::ThreadLocalValue s_Allocations;

    static baselib::ReentrantLock s_AllocationStorageMutex;
    static std::deque<std::vector<std::vector<TrackedAllocation> > > s_AllocationStorage;

    std::vector<TrackedAllocation>::iterator FindTrackedAllocation(std::vector<TrackedAllocation>& allocations, void* ptr)
    {
        for (auto iter = allocations.begin(); iter != allocations.end(); ++iter)
        {
            if (iter->ptr == ptr)
                return iter;
        }

        return allocations.end();
    }

    static std::vector<std::vector<TrackedAllocation> >& GetAllocationsForCurrentThread()
    {
        std::vector<std::vector<TrackedAllocation> >* ptr = NULL;
        s_Allocations.GetValue(reinterpret_cast<void**>(&ptr));
        if (ptr == NULL)
        {
            os::FastAutoLock lock(&s_AllocationStorageMutex);
            s_AllocationStorage.push_back(std::vector<std::vector<TrackedAllocation> >());
            ptr = &s_AllocationStorage.back();
            // Reserve some frames to prevent allocations when pushing a frame
            ptr->reserve(4);
            s_Allocations.SetValue(ptr);
        }

        return *ptr;
    }

    static std::vector<TrackedAllocation>* GetAllocationsForCurrentFrame()
    {
        std::vector<std::vector<TrackedAllocation> >& currentThreadAllocations = GetAllocationsForCurrentThread();
        if (currentThreadAllocations.size() > 0)
            return &currentThreadAllocations.back();

        return NULL;
    }

#endif

    void* MarshalAlloc::Allocate(size_t size)
    {
        void* ptr = os::MarshalAlloc::Allocate(size);

#if _DEBUG
        std::vector<TrackedAllocation>* allocations = GetAllocationsForCurrentFrame();
        if (allocations != NULL)
            allocations->emplace_back(TrackedAllocation(ptr, size));
#endif

        return ptr;
    }

    void* MarshalAlloc::ReAlloc(void* ptr, size_t size)
    {
        void* realloced = os::MarshalAlloc::ReAlloc(ptr, size);

#if _DEBUG
        std::vector<TrackedAllocation>* allocations = GetAllocationsForCurrentFrame();
        if (allocations != NULL && ptr != realloced && ptr != NULL)
        {
            auto found = FindTrackedAllocation(*allocations, ptr);
            IL2CPP_ASSERT(found != allocations->end() && "Invalid call to MarshalAlloc::ReAlloc. The pointer is not in the allocation list.");

            if (found != allocations->end())
                allocations->erase(found);
        }
#endif

        return realloced;
    }

    void MarshalAlloc::Free(void* ptr)
    {
#if _DEBUG
        std::vector<TrackedAllocation>* allocations = GetAllocationsForCurrentFrame();
        if (allocations != NULL)
        {
            auto found = FindTrackedAllocation(*allocations, ptr);
            if (found != allocations->end()) // It might not be necessarily allocated by us, e.g. we might be freeing memory that's returned from native P/Invoke call
                allocations->erase(found);
        }
#endif

        os::MarshalAlloc::Free(ptr);
    }

    void* MarshalAlloc::AllocateHGlobal(size_t size)
    {
        return os::MarshalAlloc::AllocateHGlobal(size);
    }

    void* MarshalAlloc::ReAllocHGlobal(void* ptr, size_t size)
    {
        return os::MarshalAlloc::ReAllocHGlobal(ptr, size);
    }

    void MarshalAlloc::FreeHGlobal(void* ptr)
    {
        os::MarshalAlloc::FreeHGlobal(ptr);
    }

#if _DEBUG

    void MarshalAlloc::PushAllocationFrame()
    {
        // Push an empty std::vector to track the allocation frame
        // This may not allocate but initializes an empty slot
        GetAllocationsForCurrentThread().emplace_back();
    }

    void MarshalAlloc::PopAllocationFrame()
    {
        GetAllocationsForCurrentThread().pop_back();
    }

    bool MarshalAlloc::HasUnfreedAllocations()
    {
        std::vector<TrackedAllocation>* allocations = GetAllocationsForCurrentFrame();
        return allocations != NULL && allocations->size() > 0;
    }

    void MarshalAlloc::ClearAllTrackedAllocations()
    {
        std::vector<TrackedAllocation>* allocations = GetAllocationsForCurrentFrame();
        if (allocations != NULL)
            allocations->clear();
    }

#endif
} /* namespace vm */
} /* namespace il2cpp */
