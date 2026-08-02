#pragma once
#include "il2cpp-config.h"

#include "codegen/il2cpp-codegen-metadata.h"
#include "codegen/il2cpp-codegen.h"
namespace il2cpp
{
namespace intrinsics
{
namespace System_Private_CoreLib
{
namespace System
{
namespace Runtime
{
namespace CompilerServices
{
    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.Unsafe::AreSame(T&,T&)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_unsafe_are_same(void* left, void* right)
    {
        return left == right;
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.Unsafe::IsAddressGreaterThan(T&,T&)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_unsafe_is_address_greater_than(void* left, void* right)
    {
        return left > right;
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.Unsafe::IsAddressLessThan(T&,T&)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_unsafe_is_address_less_than(void* left, void* right)
    {
        return left < right;
    }

    /* METHOD MAPPING
        Method: System.Boolean System.Runtime.CompilerServices.Unsafe::IsNullRef(T&)
        AssemblyName: System.Private.CoreLib
    */
    inline bool il2cpp_intrinsic_unsafe_is_null_ref(void* source)
    {
        return source == NULL;
    }

    /* METHOD MAPPING
        Method: System.Int32 System.Runtime.CompilerServices.Unsafe::SizeOf()
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline int32_t il2cpp_intrinsic_unsafe_size_of()
    {
        return sizeof(T);
    }

    /* METHOD MAPPING
        Method: System.IntPtr System.Runtime.CompilerServices.Unsafe::ByteOffset(T&,T&)
        AssemblyName: System.Private.CoreLib
    */
    inline intptr_t il2cpp_intrinsic_unsafe_byte_offset(void* origin, void* target)
    {
        return reinterpret_cast<uint8_t*>(target) - reinterpret_cast<uint8_t*>(origin);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::Copy(System.Void*,T&)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_copy_from_t(void* destination, void* source, uint32_t byteCount)
    {
        memcpy(destination, source, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::Copy(T&,System.Void*)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_copy_to_t(void* destination, void* source, uint32_t byteCount)
    {
        memcpy(destination, source, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::CopyBlock(System.Byte&,System.Byte&,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_copy_block(uint8_t* destination, uint8_t* source, uint32_t byteCount)
    {
        memcpy(destination, source, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::CopyBlock(System.Void*,System.Void*,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_copy_block(void* destination, void* source, uint32_t byteCount)
    {
        memcpy(destination, source, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::CopyBlockUnaligned(System.Byte&,System.Byte&,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_copy_block_unaligned(uint8_t* destination, uint8_t* source, uint32_t byteCount)
    {
        memcpy(destination, source, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::CopyBlockUnaligned(System.Void*,System.Void*,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_copy_block_unaligned(void* destination, void* source, uint32_t byteCount)
    {
        memcpy(destination, source, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::SkipInit(T&)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_skip_init(void* value)
    {
        // does nothing as we are skipping initialization
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::Write(System.Void*,T)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline void il2cpp_intrinsic_unsafe_write(void* destination, T value)
    {
        *((T*)destination) = value;
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::WriteUnaligned(System.Void*,T)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline void il2cpp_intrinsic_unsafe_write_unaligned(void* destination, T value)
    {
#if IL2CPP_TARGET_ARMV7 || IL2CPP_TARGET_JAVASCRIPT
        memcpy(destination, &value, sizeof(T));
#else
        *((T*)destination) = value;
#endif
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::WriteUnaligned(System.Byte&,T)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline void il2cpp_intrinsic_unsafe_write_unaligned(uint8_t* destination, T value)
    {
        il2cpp_intrinsic_unsafe_write_unaligned<T>((void*)destination, value);
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::AddByteOffset(T&,System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_add_byte_offset(T* source, intptr_t byteOffset)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) + byteOffset);
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::AddByteOffset(T&,System.UIntPtr)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_add_byte_offset(T* source, uintptr_t byteOffset)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) + byteOffset);
    }

    /* METHOD MAPPING
        Method: System.Void* System.Runtime.CompilerServices.Unsafe::Add(System.Void*,System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline void* il2cpp_intrinsic_unsafe_add(void* source, int32_t elementOffset, size_t elementSize)
    {
        return reinterpret_cast<void*>(reinterpret_cast<uint8_t*>(source) + (elementOffset * elementSize));
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::Add(T&,System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_add_int32(T* source, int32_t elementOffset, size_t elementSize)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) + (elementOffset * elementSize));
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::Add(T&,System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_add_intptr(T* source, intptr_t elementOffset, size_t elementSize)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) + (elementOffset * elementSize));
    }

    /* METHOD MAPPING
        Method: System.Void* System.Runtime.CompilerServices.Unsafe::AsPointer(T&)
        AssemblyName: System.Private.CoreLib
    */
    inline void* il2cpp_intrinsic_unsafe_as_pointer(void* value)
    {
        return value;
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::SubtractByteOffset(T&,System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_subtract_byte_offset(void* source, intptr_t byteOffset)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) - byteOffset);
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::SubtractByteOffset(T&,System.UIntPtr)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_subtract_byte_offset(void* source, uintptr_t byteOffset)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) - byteOffset);
    }

    /* METHOD MAPPING
        Method: System.Void* System.Runtime.CompilerServices.Unsafe::Subtract(System.Void*,System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline void* il2cpp_intrinsic_unsafe_subtract(void* source, int32_t elementOffset, size_t elementSize)
    {
        return reinterpret_cast<void*>(reinterpret_cast<uint8_t*>(source) - (elementOffset * elementSize));
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::Subtract(T&,System.Int32)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_subtract_int32(T* source, int32_t elementOffset, size_t elementSize)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) - (elementOffset * elementSize));
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::Subtract(T&,System.IntPtr)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_subtract_intptr(void* source, intptr_t elementOffset, size_t elementSize)
    {
        return reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(source) - (elementOffset * elementSize));
    }

    /* METHOD MAPPING
        Method: T System.Runtime.CompilerServices.Unsafe::As(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T il2cpp_intrinsic_unsafe_as(RuntimeObject* o)
    {
        return reinterpret_cast<T>(o);
    }

    /* METHOD MAPPING
        Method: T System.Runtime.CompilerServices.Unsafe::Read(System.Void*)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T il2cpp_intrinsic_unsafe_read(void* source)
    {
        return *((T*)source);
    }

    /* METHOD MAPPING
        Method: T System.Runtime.CompilerServices.Unsafe::ReadUnaligned(System.Void*)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T il2cpp_intrinsic_unsafe_read_unaligned(void* source)
    {
        T result;
#if IL2CPP_TARGET_ARMV7 || IL2CPP_TARGET_JAVASCRIPT
        memcpy(&result, source, sizeof(T));
#else
        result = *((T*)source);
#endif
        return result;
    }

    /* METHOD MAPPING
        Method: T System.Runtime.CompilerServices.Unsafe::ReadUnaligned(System.Byte&)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T il2cpp_intrinsic_unsafe_read_unaligned(uint8_t* source)
    {
        return il2cpp_intrinsic_unsafe_read_unaligned<T>((void*)source);
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::AsRef(System.Void*)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_as_ref(void* source)
    {
        return reinterpret_cast<T*>(source);
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::AsRef(T&)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_as_ref_t(void* source)
    {
        return reinterpret_cast<T*>(source);
    }

    /* METHOD MAPPING
        Method: TTo& System.Runtime.CompilerServices.Unsafe::As(TFrom&)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_as(void* source)
    {
        return reinterpret_cast<T*>(source);
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::NullRef()
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_null_ref()
    {
        return reinterpret_cast<T*>(NULL);
    }

    /* METHOD MAPPING
        Method: T& System.Runtime.CompilerServices.Unsafe::Unbox(System.Object)
        AssemblyName: System.Private.CoreLib
    */
    template<typename T>
    inline T* il2cpp_intrinsic_unsafe_unbox(RuntimeObject* box, RuntimeClass* klass)
    {
        return reinterpret_cast<T*>(UnBox(box, klass));
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::InitBlock(System.Byte&,System.Byte,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_init_block(uint8_t* startAddress, uint8_t value, uint32_t byteCount)
    {
        memset(startAddress, value, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::InitBlock(System.Void*,System.Byte,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_init_block(void* startAddress, uint8_t value, uint32_t byteCount)
    {
        memset(startAddress, value, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::InitBlockUnaligned(System.Byte&,System.Byte,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_init_block_unaligned(uint8_t* startAddress, uint8_t value, uint32_t byteCount)
    {
        memset(startAddress, value, byteCount);
    }

    /* METHOD MAPPING
        Method: System.Void System.Runtime.CompilerServices.Unsafe::InitBlockUnaligned(System.Void*,System.Byte,System.UInt32)
        AssemblyName: System.Private.CoreLib
    */
    inline void il2cpp_intrinsic_unsafe_init_block_unaligned(void* startAddress, uint8_t value, uint32_t byteCount)
    {
        memset(startAddress, value, byteCount);
    }

    /* METHOD MAPPING
        Method: TTo System.Runtime.CompilerServices.Unsafe::BitCast(TFrom)
        AssemblyName: System.Private.CoreLib
        EmitTemplateParams: true
    */
    template<typename TTo, typename TFrom>
    inline TTo il2cpp_intrinsic_unsafe_bit_cast(const TFrom& from)
    {
        if (sizeof(TFrom) != sizeof(TTo))
            il2cpp_codegen_raise_not_supported_exception();

        TTo to;
        il2cpp_codegen_memcpy(&to, &from, sizeof(TFrom));
        return to;
    }
} // namespace CompilerServices
} // namespace Runtime
} // namespace System
} // namespace System_Private_CoreLib
} // namespace intrinsics
} // namespace il2cpp
