#include "metadata/Il2CppMethodSpecOrGenericMethod.h"
#include "metadata/Il2CppMethodSpecOrGenericMethodCompare.h"
#include "vm/GlobalMetadata.h"

namespace il2cpp
{
namespace metadata
{
    bool Il2CppMethodSpecOrGenericMethodCompare::operator()(Il2CppMethodSpecOrGenericMethod m1, Il2CppMethodSpecOrGenericMethod m2) const
    {
        return Equals(m1, m2);
    }

    bool Il2CppMethodSpecOrGenericMethodCompare::Equals(Il2CppMethodSpecOrGenericMethod m1, Il2CppMethodSpecOrGenericMethod m2)
    {
        return Il2CppGenericMethodCompare::Equals(m1.BuildGenericMethodKey(), m2.BuildGenericMethodKey());
    }
} /* namespace vm */
} /* namespace il2cpp */
