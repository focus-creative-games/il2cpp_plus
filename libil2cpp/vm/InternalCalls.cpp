#include "il2cpp-config.h"
#include "vm/InternalCalls.h"
#include "vm/Runtime.h"

#include <map>
#include <string>

typedef std::map<std::string, Il2CppMethodPointer> ICallMap;
static ICallMap s_InternalCalls;

namespace il2cpp
{
namespace vm
{
    void InternalCalls::Add(const char* name, Il2CppMethodPointer method)
    {
        //ICallMap::iterator res = s_InternalCalls.find(name);

        // TODO: Don't assert right now because Unity adds some icalls multiple times.
        //if (res != icalls.end())
        //  IL2CPP_ASSERT(0 && "Adding internal call twice!");

        IL2CPP_ASSERT(method);

        s_InternalCalls[name] = method;

#if IL2CPP_ENABLE_MEM_STATS
        il2cpp_mem_stats.interal_calls_total = s_InternalCalls.size();
#endif
    }

    Il2CppMethodPointer InternalCalls::Resolve(const char* name)
    {
        // Try to find the whole name first, then search using just type::method
        // if parameters were passed
        // ex: First, System.Foo::Bar(System.Int32)
        // Then, System.Foo::Bar
        ICallMap::iterator res = s_InternalCalls.find(name);

        if (res != s_InternalCalls.end())
        {
#if IL2CPP_ENABLE_MEM_STATS
            ++il2cpp_mem_stats.interal_calls_resolved;
#endif
            return res->second;
        }

        std::string shortName(name);
        size_t index = shortName.find('(');

        if (index != std::string::npos)
        {
            shortName = shortName.substr(0, index);
            res = s_InternalCalls.find(shortName);

            if (res != s_InternalCalls.end())
            {
#if IL2CPP_ENABLE_MEM_STATS
                ++il2cpp_mem_stats.interal_calls_resolved;
#endif
                return res->second;
            }
        }

        return NULL;
    }
#if IL2CPP_ENABLE_MEM_STATS
    size_t InternalCalls::GetInternalCallsCount() {
        return s_InternalCalls.size();
    }
#endif //#if IL2CPP_ENABLE_MEM_STATS
} /* namespace vm */
} /* namespace il2cpp */
