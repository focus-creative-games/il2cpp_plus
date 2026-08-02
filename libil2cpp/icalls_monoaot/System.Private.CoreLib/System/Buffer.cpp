#include "il2cpp-config.h"
#include "Buffer.h"

#include "vm/Class.h"
#include "vm/Type.h"

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
    void Buffer::BulkMoveWithWriteBarrier(uint8_t* dmem, uint8_t* smem, intptr_t len, Il2CppType* type_handle)
    {
        size_t elemSize = 0;

        if (!il2cpp::vm::Type::IsValueType(type_handle))
        {
            elemSize = sizeof(void*);
        }
        else
        {
            Il2CppClass* klass = il2cpp::vm::Class::FromIl2CppType(type_handle);
            elemSize = vm::Class::GetInstanceSize(klass) - sizeof(Il2CppObject);
        }

        size_t byteLength = len * elemSize;
        memmove(dmem, smem, byteLength);

        gc::GarbageCollector::SetWriteBarrier((void**)dmem, byteLength);
    }

    void Buffer::__Memmove(uint8_t* dest, uint8_t* src, intptr_t len)
    {
        memmove(dest, src, len);
    }

    void Buffer::__ZeroMemory(void* b, intptr_t byteLength)
    {
        memset(b, 0, byteLength);
    }
} // namespace System
} // namespace CoreLib
} // namespace Private
} // namespace System
} // namespace icalls
} // namespace il2cpp
