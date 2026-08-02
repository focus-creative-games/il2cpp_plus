#include "utils/StringUtils.h"
#include "vm/AppContext.h"
#include "vm/Class.h"
#include "vm/Method.h"
#include "vm/Runtime.h"
#include "vm/Type.h"

namespace il2cpp
{
namespace vm
{
    void AppContext::SetupAppContextSwitches(const std::string& icuDataFilePath)
    {
#if MONO_NET8_BCL
        if (!il2cpp_defaults.app_context_class)
            return; // Probably was stripped

        const MethodInfo* setupMethod = Class::GetMethodFromName(il2cpp_defaults.app_context_class, "Setup", 3);

        IL2CPP_ASSERT(setupMethod);
        IL2CPP_ASSERT(!Method::IsInstance(setupMethod));
        IL2CPP_ASSERT(Type::GetType(Method::GetReturnType(setupMethod)) == IL2CPP_TYPE_VOID);
        IL2CPP_ASSERT(Type::GetType(Method::GetParam(setupMethod, 0)) == IL2CPP_TYPE_PTR);
        IL2CPP_ASSERT(Type::GetType(Method::GetParam(setupMethod, 1)) == IL2CPP_TYPE_PTR);
        IL2CPP_ASSERT(Type::GetType(Method::GetParam(setupMethod, 2)) == IL2CPP_TYPE_I4);

        std::vector<UTF16String> nativeStrings;

    #if IL2CPP_SYSTEM_GLOBALIZATION_INVARIANT
        nativeStrings.push_back(utils::StringUtils::Utf8ToUtf16("System.Globalization.Invariant"));
        nativeStrings.push_back(utils::StringUtils::Utf8ToUtf16("true"));
    #else
        if (icuDataFilePath.length() > 0)
        {
            nativeStrings.push_back(utils::StringUtils::Utf8ToUtf16("ICU_DAT_FILE_PATH"));
            nativeStrings.push_back(utils::StringUtils::Utf8ToUtf16(icuDataFilePath));
        }
    #endif // !IL2CPP_SYSTEM_GLOBALIZATION_INVARIANT

        IL2CPP_ASSERT(sizeof(nativeStrings.size()) % 2 == 0);
        int32_t argCount = (int32_t)(nativeStrings.size() / 2);

        std::vector<const Il2CppChar*> names(argCount);
        std::vector<const Il2CppChar*> values(argCount);
        for (int i = 0; i < argCount; ++i)
        {
            names[i] = nativeStrings[i * 2].c_str();
            values[i] = nativeStrings[i * 2 + 1].c_str();
        }

        void* args[3] = {
            names.data(),
            values.data(),
            &argCount
        };

        Il2CppException* exc = NULL;
        vm::Runtime::Invoke(setupMethod, NULL, args, &exc);

        // Not sure what we would do here if we got an exception
        IL2CPP_ASSERT(exc == NULL);
#endif
    }
}
}
