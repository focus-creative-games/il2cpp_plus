#pragma once
#include "il2cpp-config.h"
#include "intrinsics/IntrinsicsUtility.h"
#include "string.h"

template<typename FromT, typename ToT>
inline ToT il2cpp_intrinsic_cast(FromT fromVar)
{
    return il2cpp_codegen_cast_struct<ToT, FromT>(fromVar);
}

template<>
inline bool il2cpp_intrinsic_cast<int, bool>(int from)
{
    return from != 0;
}

template<>
inline int il2cpp_intrinsic_cast<uint8_t, int>(uint8_t from)
{
    return from;
}

template<>
inline uint8_t il2cpp_intrinsic_cast<int, uint8_t>(int from)
{
    return from;
}

template<>
inline int il2cpp_intrinsic_cast<int8_t, int>(int8_t from)
{
    return from;
}

template<>
inline uint16_t il2cpp_intrinsic_cast<int, uint16_t>(int from)
{
    return from;
}

template<>
inline int il2cpp_intrinsic_cast<int16_t, int>(int16_t from)
{
    return from;
}

template<>
inline int il2cpp_intrinsic_cast<uint16_t, int>(uint16_t from)
{
    return from;
}

#define INTRINSIC_CAST(fromType, toType, fromVar) \
    (il2cpp_intrinsic_cast<fromType, toType>(fromVar))
