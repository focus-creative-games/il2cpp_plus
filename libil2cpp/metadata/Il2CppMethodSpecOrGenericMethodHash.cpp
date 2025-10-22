#include "metadata/Il2CppGenericMethodHash.h"
#include "metadata/Il2CppMethodSpecOrGenericMethod.h"
#include "metadata/Il2CppMethodSpecOrGenericMethodHash.h"

namespace il2cpp
{
namespace metadata
{
    size_t Il2CppMethodSpecOrGenericMethodHash::operator()(Il2CppMethodSpecOrGenericMethod method) const
    {
        return Hash(method);
    }

    size_t Il2CppMethodSpecOrGenericMethodHash::Hash(Il2CppMethodSpecOrGenericMethod method)
    {
        return Il2CppGenericMethodHash::Hash(method.BuildGenericMethodKey());
    }
} /* namespace metadata */
} /* namespace il2cpp */
