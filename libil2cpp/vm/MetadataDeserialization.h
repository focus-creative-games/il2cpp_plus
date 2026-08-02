#pragma once

#include "GlobalMetadataFileInternals.h"
#include "utils/MemoryRead.h"

// Keep the logic in this file in sync with Unity.IL2CPP/Metadata.Dat/Serialization/*.cs

struct SerializedIndexSizes
{
    int typeIndex = 0;
    int genericParameterIndex = 0;
    int genericContainerIndex = 0;
    int typeDefinitionIndex = 0;
    int parameterIndex = 0;
    int interfacesIndex = 0;
    int eventIndex = 0;
    int propertyIndex = 0;
    int nestedTypeIndex = 0;
    int fieldIndex = 0;
    int defaultValueDataIndex = 0;
    int methodIndex = 0;
};

int GetIndexSize(const int numberOfElements);

template<typename T>
T ReadIndex(const char*& ptr, const int serializedSize)
{
    using namespace il2cpp::utils;

    if (serializedSize == 1)
    {
        const auto value = Read<uint8_t>(ptr);
        return static_cast<T>(value == UINT8_MAX ? -1 : value);
    }
    else if (serializedSize == 2)
    {
        const auto value = Read<uint16_t>(ptr);
        return static_cast<T>(value == UINT16_MAX ? -1 : value);
    }
    else
    {
        const auto value = Read<uint32_t>(ptr);
        return static_cast<T>(value == UINT32_MAX ? -1 : value);
    }
}

template<typename T>
inline T DeserializeIndex(const char* ptr, const int serializedSize)
{
    return ReadIndex<T>(ptr, serializedSize);
}

Il2CppEventDefinition DeserializeEventDefinition(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppMethodDefinition DeserializeMethodDefinition(
    const Il2CppMetadataMethodDefinitionHandle handle,
    const SerializedIndexSizes& sizes
);
Il2CppParameterDefaultValue DeserializeParameterDefaultValue(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppFieldDefaultValue DeserializeFieldDefaultValue(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppFieldMarshaledSize DeserializeFieldMarshaledSize(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppParameterDefinition DeserializeParameterDefinition(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppFieldDefinition DeserializeFieldDefinition(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppInterfaceOffsetPair DeserializeInterfaceOffsetPair(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppTypeDefinition DeserializeTypeDefinition(const Il2CppMetadataTypeHandle handle, const SerializedIndexSizes& sizes);
Il2CppGenericParameter DeserializeGenericParameter(const Il2CppMetadataGenericParameterHandle handle, const SerializedIndexSizes& sizes);
Il2CppGenericContainer DeserializeGenericContainer(const Il2CppMetadataGenericContainerHandle ptr, const SerializedIndexSizes& sizes);
Il2CppImageDefinition DeserializeImageDefinition(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppWindowsRuntimeTypeNamePair DeserializeWindowsRuntimeTypeNamePair(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppInlineArrayLength DeserializeInlineArrayLength(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppFieldRef DeserializeFieldRef(const char* ptr, const SerializedIndexSizes& sizes);
Il2CppPropertyDefinition DeserializePropertyDefinition(const char* ptr, const SerializedIndexSizes& sizes);
