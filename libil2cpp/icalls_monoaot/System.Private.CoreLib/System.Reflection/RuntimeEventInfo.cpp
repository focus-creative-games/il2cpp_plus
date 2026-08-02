#include "il2cpp-config.h"
#include "RuntimeEventInfo.h"

#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/Reflection.h"
#include "vm/String.h"

namespace il2cpp
{
namespace icalls
{
namespace System
{
namespace Private
{
namespace CoreLib
{
namespace System
{
namespace Reflection
{
    int32_t RuntimeEventInfo::get_metadata_token(Il2CppObject* monoEvent)
    {
        return vm::Reflection::GetMetadataToken(monoEvent);
    }

    Il2CppReflectionEvent *RuntimeEventInfo::internal_from_handle_type(const EventInfo* event_handle, const Il2CppType* type_handle)
    {
        Il2CppClass* klass = vm::Class::FromIl2CppType(type_handle);
        return vm::Reflection::GetEventObject(klass, event_handle);
    }

    void RuntimeEventInfo::get_event_info(Il2CppReflectionMonoEvent* ev, Il2CppReflectionMonoEventInfo* info)
    {
        info->declaringType = vm::Reflection::GetTypeObject(&ev->eventInfo->parent->byval_arg);
        info->reflectedType = ev->reflectedType;
        info->name = vm::String::New(ev->eventInfo->name);

        Il2CppClass* reflectedTypeInfo = vm::Class::FromIl2CppType(ev->reflectedType->type);
        info->addMethod = ev->eventInfo->add != NULL ? vm::Reflection::GetMethodObject(ev->eventInfo->add, reflectedTypeInfo) : NULL;
        info->removeMethod = ev->eventInfo->remove != NULL ? vm::Reflection::GetMethodObject(ev->eventInfo->remove, reflectedTypeInfo) : NULL;
        info->raiseMethod = ev->eventInfo->raise != NULL ? vm::Reflection::GetMethodObject(ev->eventInfo->raise, reflectedTypeInfo) : NULL;
        info->eventAttributes = ev->eventInfo->eventType->attrs;
        info->otherMethods = vm::Array::NewCached(il2cpp_defaults.method_info_class, 0); // Empty for now
    }
} // namespace Reflection
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
