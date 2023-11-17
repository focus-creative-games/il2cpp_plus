#include "il2cpp-config.h"
#include <memory>

#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "il2cpp-tabledefs.h"
#include "il2cpp-runtime-stats.h"
#include "gc/gc_wrapper.h"
#include "gc/GarbageCollector.h"
#include "metadata/GenericMethod.h"
#include "metadata/Il2CppTypeCompare.h"
#include "utils/StringUtils.h"
#include "vm-utils/VmThreadUtils.h"
#include "vm/Array.h"
#include "vm/Class.h"
#include "vm/ClassInlines.h"
#include "vm/Exception.h"
#include "vm/Field.h"
#include "vm/MetadataCache.h"
#include "vm/Method.h"
#include "vm/Object.h"
#include "vm/Profiler.h"
#include "vm/RCW.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "vm/String.h"
#include "vm/Thread.h"
#include "vm/Type.h"

#if IL2CPP_GC_BOEHM
#define ALLOC_PTRFREE(obj, vt, size) do { (obj) = (Il2CppObject*)GC_MALLOC_ATOMIC ((size)); (obj)->klass = (vt); (obj)->monitor = NULL;} while (0)
#define ALLOC_OBJECT(obj, vt, size) do { (obj) = (Il2CppObject*)GC_MALLOC ((size)); (obj)->klass = (vt);} while (0)
#ifdef GC_GCJ_SUPPORT
#define ALLOC_TYPED(dest, size, type) do { (dest) = (Il2CppObject*)GC_gcj_malloc ((size),(type)); } while (0)
#else
#define GC_NO_DESCRIPTOR (NULL)
#define ALLOC_TYPED(dest, size, type) do { (dest) = GC_MALLOC ((size)); *(void**)dest = (type);} while (0)
#endif
#else
#ifdef HAVE_SGEN_GC
#define GC_NO_DESCRIPTOR (NULL)
#define ALLOC_PTRFREE(obj, vt, size) do { (obj) = mono_gc_alloc_obj (vt, size);} while (0)
#define ALLOC_OBJECT(obj, vt, size) do { (obj) = mono_gc_alloc_obj (vt, size);} while (0)
#define ALLOC_TYPED(dest, size, type) do { (dest) = mono_gc_alloc_obj (type, size);} while (0)
#else
#define ALLOC_PTRFREE(obj, vt, size) do { (obj) = (Il2CppObject*)malloc ((size)); (obj)->klass = (vt); (obj)->monitor = NULL;} while (0)
#define ALLOC_OBJECT(obj, vt, size) do { (obj) = (Il2CppObject*)calloc (1, (size)); (obj)->klass = (vt);} while (0)
#define ALLOC_TYPED(dest, size, type) do { (dest) = (Il2CppObject*)(calloc (1, (size))); *(void**)dest = (type);} while (0)
#endif
#endif

namespace il2cpp
{
namespace vm
{
    Il2CppObject * Object::Allocate(size_t size, Il2CppClass *typeInfo)
    {
        IL2CPP_ASSERT(typeInfo->initialized);
        Il2CppObject *o;
        ALLOC_OBJECT(o, typeInfo, size);

        ++il2cpp_runtime_stats.new_object_count;

        return o;
    }

    Il2CppObject * Object::AllocatePtrFree(size_t size, Il2CppClass *typeInfo)
    {
        IL2CPP_ASSERT(typeInfo->initialized);
        Il2CppObject *o;
        ALLOC_PTRFREE(o, typeInfo, size);

        ++il2cpp_runtime_stats.new_object_count;

        return o;
    }

    Il2CppObject * Object::AllocateSpec(size_t size, Il2CppClass *typeInfo)
    {
        IL2CPP_ASSERT(typeInfo->initialized);
        Il2CppObject *o;
        ALLOC_TYPED(o, size, typeInfo);

        ++il2cpp_runtime_stats.new_object_count;

        return o;
    }

    Il2CppObject* Object::Box(Il2CppClass *typeInfo, void* val)
    {
        if (!typeInfo->byval_arg.valuetype)
            return *(Il2CppObject**)val;

        bool isNullable = Class::IsNullable(typeInfo);

        if (isNullable)
        {
            /* From ECMA-335, I.8.2.4 Boxing and unboxing of values:

                All value types have an operation called box. Boxing a value of any value type produces its boxed value;
                i.e., a value of the corresponding boxed type containing a bitwise copy of the original value. If the
                value type is a nullable type defined as an instantiation of the value type System.Nullable<T> the result
                is a null reference or bitwise copy of its Value property of type T, depending on its HasValue property
                (false and true, respectively).
            */
            if (!NullableHasValue(typeInfo, val))
                return NULL;
        }

        Il2CppObject* obj = Object::New(typeInfo);

        size_t size = Class::GetInstanceSize(typeInfo);

        // At this point we know we have a value type and we need to adjust the
        // copy size by the size of Il2CppObject
        size = size - sizeof(Il2CppObject);

        uint8_t* valueStart = static_cast<uint8_t*>(val);
        if (isNullable)
        {
            IL2CPP_ASSERT(metadata::Il2CppTypeEqualityComparer::AreEqual(typeInfo->fields[1].type, &Class::GetNullableArgument(typeInfo)->byval_arg));
            // Shift the valueStart right past the bool for nullable
            int32_t nullableShift = typeInfo->fields[1].offset - sizeof(Il2CppObject);
            valueStart += nullableShift;

            // the size needs to be further adjusted to be smaller
            size -= nullableShift;
        }

        memcpy(((char*)obj) + sizeof(Il2CppObject), valueStart, size);
        gc::GarbageCollector::SetWriteBarrier((void**)(((char*)obj) + sizeof(Il2CppObject)), size);
        return obj;
    }

    Il2CppObject* Object::Clone(Il2CppObject *obj)
    {
        Il2CppObject *o;
        int size;
        IL2CPP_NOT_IMPLEMENTED_NO_ASSERT(Object::Clone, "Finish implementation");

        if (obj->klass->rank)
        {
            return Array::Clone((Il2CppArray*)obj);
        }

        size = obj->klass->instance_size;
        o = Allocate(size, obj->klass);
        /* do not copy the sync state */
        memcpy((char*)o + sizeof(Il2CppObject), (char*)obj + sizeof(Il2CppObject), size - sizeof(Il2CppObject));

        gc::GarbageCollector::SetWriteBarrier((void**)(((char*)o) + sizeof(Il2CppObject)), size);

//#ifdef HAVE_SGEN_GC
//  if (obj->vtable->klass->has_references)
//      mono_gc_wbarrier_object (o);
//#endif

        if (obj->klass->has_finalize)
            il2cpp::gc::GarbageCollector::RegisterFinalizerForNewObject(o);

#if IL2CPP_ENABLE_PROFILER
        if (Profiler::ProfileAllocations())
            Profiler::Allocation(o, obj->klass);
#endif

        return o;
    }

    Il2CppClass* Object::GetClass(Il2CppObject* obj)
    {
        return obj->klass;
    }

#if IL2CPP_SIZEOF_VOID_P == 8
    const int kObjectAlignmentShift = 3;
#elif IL2CPP_SIZEOF_VOID_P == 4
    const int kObjectAlignmentShift = 2;
#else
#error Invalid architecture size
#endif

    int32_t Object::GetHash(Il2CppObject* obj)
    {
        // shift away unused bits due to alignment, then use Knuth's multiplicative hash
        return (((uint32_t)(intptr_t)(obj)) >> kObjectAlignmentShift) * 2654435761u;
    }

    uint32_t Object::GetSize(Il2CppObject* obj)
    {
        Il2CppClass* klass = GetClass(obj);
        if (klass == il2cpp_defaults.string_class)
        {
            return sizeof(Il2CppString) + 2 * utils::StringUtils::GetLength((Il2CppString*)obj) + 2;
        }
        else if (obj->klass->rank)
        {
            Il2CppArray *array = (Il2CppArray*)obj;
            size_t size = kIl2CppSizeOfArray + Array::GetElementSize(klass) * Array::GetLength(array);
            if (array->bounds)
            {
                size += 3;
                size &= ~3;
                size += sizeof(Il2CppArrayBounds) * obj->klass->rank;
            }
            return (uint32_t)size;
        }
        else
        {
            return Class::GetInstanceSize(klass);
        }
    }

    const MethodInfo* Object::GetVirtualMethod(Il2CppObject *obj, const MethodInfo *virtualMethod)
    {
        if ((virtualMethod->flags & METHOD_ATTRIBUTE_FINAL) || !(virtualMethod->flags & METHOD_ATTRIBUTE_VIRTUAL))
            return virtualMethod;

        Il2CppClass* methodDeclaringType = virtualMethod->klass;
        const MethodInfo* vtableSlotMethod;
        if (Class::IsInterface(methodDeclaringType))
        {
            vtableSlotMethod = ClassInlines::GetInterfaceInvokeDataFromVTable(obj, methodDeclaringType, virtualMethod->slot).method;
        }
        else
        {
            IL2CPP_ASSERT(virtualMethod->slot < obj->klass->vtable_count);
            vtableSlotMethod = obj->klass->vtable[virtualMethod->slot].method;
        }

        if (Method::IsGenericInstanceMethod(virtualMethod))
            return il2cpp::metadata::GenericMethod::GetGenericVirtualMethod(vtableSlotMethod, virtualMethod);
        return vtableSlotMethod;
    }

    Il2CppObject* Object::IsInst(Il2CppObject *obj, Il2CppClass *klass)
    {
        if (!obj)
            return NULL;

        Il2CppClass* objClass = Object::GetClass(obj);
        if (Class::IsAssignableFrom(klass, objClass))
            return obj;

        if (!objClass->is_import_or_windows_runtime)
            return NULL;

        // check if klass has an interface id
        if (Class::IsInterface(klass) && klass->interopData != NULL)
        {
            const Il2CppGuid* iid = klass->interopData->guid;
            if (iid != NULL)
            {
                Il2CppIUnknown* unknown = RCW::QueryInterfaceNoAddRef<false>(static_cast<Il2CppComObject*>(obj), *iid);
                if (unknown)
                    return static_cast<Il2CppComObject*>(obj);
            }
        }

        return (klass == il2cpp_defaults.object_class) ? obj : NULL;
    }

    Il2CppObject* Object::New(Il2CppClass *klass)
    {
        // same as NewAllocSpecific as we only support a single domain
        return NewAllocSpecific(klass);
    }

    Il2CppObject* Object::NewPinned(Il2CppClass *klass)
    {
#if (IL2CPP_GC_BOEHM || IL2CPP_GC_NULL)
        return New(klass);
#else
        IL2CPP_NOT_IMPLEMENTED(Object::NewPinned);
#endif
    }

    Il2CppObject * Object::NewAllocSpecific(Il2CppClass *klass)
    {
        Il2CppObject *o = NULL;

        IL2CPP_NOT_IMPLEMENTED_NO_ASSERT(Object::NewAllocSpecific, "We really shouldn't need this initialization");
        Class::Init(klass);

        if (Class::IsNullable(klass))
            klass = il2cpp::vm::Class::GetNullableArgument(klass);

        if (!klass->has_references)
        {
            o = NewPtrFree(klass);
        }
#if IL2CPP_HAS_GC_DESCRIPTORS
        else if (klass->gc_desc != GC_NO_DESCRIPTOR)
        {
            o = AllocateSpec(klass->instance_size, klass);
        }
#endif
        else
        {
            o = Allocate(klass->instance_size, klass);
        }
        if (klass->has_finalize)
            il2cpp::gc::GarbageCollector::RegisterFinalizerForNewObject(o);

#if IL2CPP_ENABLE_PROFILER
        if (Profiler::ProfileAllocations())
            Profiler::Allocation(o, klass);
#endif

        Runtime::ClassInit(klass);
        return o;
    }

    Il2CppObject* Object::NewPtrFree(Il2CppClass *klass)
    {
        Il2CppObject *obj = {0};

        IL2CPP_ASSERT(klass->initialized);
        IL2CPP_ASSERT(!klass->has_references);

        ALLOC_PTRFREE(obj, klass, klass->instance_size);
#if NEED_TO_ZERO_PTRFREE
        /* an inline memset is much faster for the common vcase of small objects
         * note we assume the allocated size is a multiple of sizeof (void*).
         */
        if (klass->instance_size < 128)
        {
            void* *p, *end;
            end = (void**)((char*)obj + klass->instance_size);
            p = (void**)((char*)obj + sizeof(Il2CppObject));
            while (p < end)
            {
                *p = NULL;
                ++p;
            }
        }
        else
        {
            memset((char*)obj + sizeof(Il2CppObject), 0, klass->instance_size - sizeof(Il2CppObject));
        }
#endif

        ++il2cpp_runtime_stats.new_object_count;

        return obj;
    }

    void* Object::Unbox(Il2CppObject* obj)
    {
        void* val = (void*)(((char*)obj) + sizeof(Il2CppObject));
        return val;
    }

    void Object::UnboxNullable(Il2CppObject* obj, Il2CppClass* nullableClass, void* storage)
    {
        // We assume storage is on the stack, if not we'll need a write barrier
        // ==={{ wolong.  may storage in heap
        // IL2CPP_ASSERT_STACK_PTR(storage);
        // ===}} wolong

        // After the assert above, we can safely call this method, because the GC will find storage as a root,
        // since it is on the stack.
        UnboxNullableGCUnsafe(obj, nullableClass, storage);
    }

    void Object::UnboxNullableWithWriteBarrier(Il2CppObject* obj, Il2CppClass* nullableClass, void* storage)
    {
        uint32_t valueSize = UnboxNullableGCUnsafe(obj, nullableClass, storage);
        il2cpp::gc::GarbageCollector::SetWriteBarrier((void**)storage, valueSize);
    }

    // Hey! You probably don't want to call this method. Call Object::UnboxNullable  or
    // Object::UnboxNullableWithWriteBarrier instead.
    //
    //
    // Ok - still here? If you call this method and storage is not on the stack, you need to set a
    // GC write barrier for the pointer at storage with a length that is the number of bytes, which
    // this method returns. That's what UnboxNullableWithWriteBarrier. Use it!
    uint32_t Object::UnboxNullableGCUnsafe(Il2CppObject* obj, Il2CppClass* nullableClass, void* storage)
    {
        IL2CPP_ASSERT(Class::IsNullable(nullableClass));
        IL2CPP_ASSERT(nullableClass->field_count == 2);
        IL2CPP_ASSERT(metadata::Il2CppTypeEqualityComparer::AreEqual(nullableClass->fields[0].type, &il2cpp_defaults.boolean_class->byval_arg));
        IL2CPP_ASSERT(obj == NULL || metadata::Il2CppTypeEqualityComparer::AreEqual(nullableClass->fields[1].type, &obj->klass->byval_arg));

        void* valueField = Field::GetInstanceFieldDataPointer(storage, &nullableClass->fields[1]);
        uint32_t valueSize = Class::GetNullableArgument(nullableClass)->instance_size - sizeof(Il2CppObject);

        if (obj == NULL)
        {
            memset(valueField, 0, valueSize);
            *(static_cast<uint8_t*>(storage)) = false;
        }
        else
        {
            memcpy(valueField, Unbox(obj), valueSize);
            *(static_cast<uint8_t*>(storage)) = true;
        }

        return valueSize;
    }

    void Object::NullableInit(uint8_t* buf, Il2CppObject* value, Il2CppClass* klass)
    {
        Il2CppClass *parameterClass = klass->castClass;

        IL2CPP_ASSERT(Class::FromIl2CppType(klass->fields[0].type) == il2cpp_defaults.boolean_class);
        IL2CPP_ASSERT(Class::FromIl2CppType(klass->fields[1].type) == parameterClass);

        *(uint8_t*)(buf + klass->fields[0].offset - sizeof(Il2CppObject)) = value ? 1 : 0;
        if (value)
            memcpy(buf + klass->fields[1].offset - sizeof(Il2CppObject), Object::Unbox(value), Class::GetValueSize(parameterClass, NULL));
        else
            memset(buf + klass->fields[1].offset - sizeof(Il2CppObject), 0, Class::GetValueSize(parameterClass, NULL));
    }
} /* namespace vm */
} /* namespace il2cpp */
