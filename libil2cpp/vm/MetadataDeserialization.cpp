#include "MetadataDeserialization.h"

// Keep the logic in this file in sync with Unity.IL2CPP/Metadata.Dat/Serialization/*.cs

using namespace il2cpp::utils;

int GetIndexSize(const int numberOfElements)
{
    if (numberOfElements <= UINT8_MAX)
    {
        return 1;
    }
    else if (numberOfElements <= UINT16_MAX)
    {
        return 2;
    }
    else
    {
        return 4;
    }
}

Il2CppEventDefinition DeserializeEventDefinition(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppEventDefinition {
            Read<StringIndex>(ptr), // nameIndex
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
            Read<MethodIndex>(ptr), // add
            Read<MethodIndex>(ptr), // remove
            Read<MethodIndex>(ptr), // raise
            Read<uint32_t>(ptr), // token
    };
}

Il2CppMethodDefinition DeserializeMethodDefinition(const Il2CppMetadataMethodDefinitionHandle handle, const SerializedIndexSizes& sizes)
{
    const auto* ptr = reinterpret_cast<const char*>(handle);
    return Il2CppMethodDefinition {
            Read<StringIndex>(ptr), // nameIndex
            ReadIndex<TypeDefinitionIndex>(ptr, sizes.typeDefinitionIndex), // declaringType
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // returnType
            Read<uint32_t>(ptr), // returnParameterToken
            ReadIndex<ParameterIndex>(ptr, sizes.parameterIndex), // parameterStart
            ReadIndex<GenericContainerIndex>(ptr, sizes.genericContainerIndex), // genericContainerIndex
            Read<uint32_t>(ptr), // token
            Read<uint16_t>(ptr), // flags
            Read<uint16_t>(ptr), // iflags
            Read<uint16_t>(ptr), // slot
            Read<uint16_t>(ptr), // parameterCount
    };
}

Il2CppParameterDefaultValue DeserializeParameterDefaultValue(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppParameterDefaultValue {
            ReadIndex<ParameterIndex>(ptr, sizes.parameterIndex), // parameterIndex
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
            Read<DefaultValueDataIndex>(ptr), // dataIndex
    };
}

Il2CppFieldDefaultValue DeserializeFieldDefaultValue(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppFieldDefaultValue {
            Read<FieldIndex>(ptr), // fieldIndex
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
            Read<DefaultValueDataIndex>(ptr), // dataIndex
    };
}

Il2CppFieldMarshaledSize DeserializeFieldMarshaledSize(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppFieldMarshaledSize {
            Read<FieldIndex>(ptr), // fieldIndex
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
            Read<int32_t>(ptr), // size
    };
}

Il2CppParameterDefinition DeserializeParameterDefinition(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppParameterDefinition {
            Read<StringIndex>(ptr), // nameIndex
            Read<uint32_t>(ptr), // token
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
    };
}

Il2CppFieldDefinition DeserializeFieldDefinition(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppFieldDefinition {
            Read<StringIndex>(ptr), // nameIndex
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
            Read<uint32_t>(ptr), // token
    };
}

Il2CppInterfaceOffsetPair DeserializeInterfaceOffsetPair(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppInterfaceOffsetPair {
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // interfaceTypeIndex
            Read<int32_t>(ptr), // offset
    };
}

Il2CppTypeDefinition DeserializeTypeDefinition(const Il2CppMetadataTypeHandle handle, const SerializedIndexSizes& sizes)
{
    const auto* ptr = reinterpret_cast<const char*>(handle);
    const auto typeIndexSize = sizes.typeIndex;

    return Il2CppTypeDefinition {
            Read<StringIndex>(ptr), // nameIndex
            Read<StringIndex>(ptr), // namespaceIndex
            ReadIndex<TypeIndex>(ptr, typeIndexSize), // byvalTypeIndex

            ReadIndex<TypeIndex>(ptr, typeIndexSize), // declaringTypeIndex
            ReadIndex<TypeIndex>(ptr, typeIndexSize), // parentIndex

            ReadIndex<GenericContainerIndex>(ptr, sizes.genericContainerIndex), // genericContainerIndex

            Read<uint32_t>(ptr), // flags

            Read<FieldIndex>(ptr), // fieldStart
            Read<MethodIndex>(ptr), // methodStart
            Read<EventIndex>(ptr), // eventStart
            Read<PropertyIndex>(ptr), // propertyStart
            Read<NestedTypeIndex>(ptr), // nestedTypesStart
            Read<InterfacesIndex>(ptr), // interfacesStart
            Read<VTableIndex>(ptr), // vtableStart
            Read<InterfacesIndex>(ptr), // interfaceOffsetsStart

            Read<uint16_t>(ptr), // method_count
            Read<uint16_t>(ptr), // property_count
            Read<uint16_t>(ptr), // field_count
            Read<uint16_t>(ptr), // event_count
            Read<uint16_t>(ptr), // nested_type_count
            Read<uint16_t>(ptr), // vtable_count
            Read<uint16_t>(ptr), // interfaces_count
            Read<uint16_t>(ptr), // interface_offsets_count

            Read<uint32_t>(ptr), // bitfield
            Read<uint32_t>(ptr), // token
    };
}

Il2CppFieldRef DeserializeFieldRef(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppFieldRef {
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
            Read<FieldIndex>(ptr), // fieldIndex
    };
}

Il2CppImageDefinition DeserializeImageDefinition(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppImageDefinition {
            Read<StringIndex>(ptr), // nameIndex
            Read<AssemblyIndex>(ptr), // assemblyIndex

            ReadIndex<TypeDefinitionIndex>(ptr, sizes.typeDefinitionIndex), // typeStart
            Read<uint32_t>(ptr), // typeCount

            ReadIndex<TypeDefinitionIndex>(ptr, sizes.typeDefinitionIndex), // exportedTypeStart
            Read<uint32_t>(ptr), // exportedTypeCount

            Read<MethodIndex>(ptr), // entryPointIndex
            Read<uint32_t>(ptr), // token

            Read<CustomAttributeIndex>(ptr), // customAttributeStart
            Read<uint32_t>(ptr), // customAttributeCount
    };
}

Il2CppGenericParameter DeserializeGenericParameter(const Il2CppMetadataGenericParameterHandle handle, const SerializedIndexSizes& sizes)
{
    const auto* ptr = reinterpret_cast<const char*>(handle);

    return Il2CppGenericParameter {
            ReadIndex<GenericContainerIndex>(ptr, sizes.genericContainerIndex), // ownerIndex
            Read<StringIndex>(ptr), // nameIndex
            Read<GenericParameterConstraintIndex>(ptr), // constraintsStart
            Read<int16_t>(ptr), // constraintsCount
            Read<uint16_t>(ptr), // num
            Read<uint16_t>(ptr), // flags
    };
}

Il2CppWindowsRuntimeTypeNamePair DeserializeWindowsRuntimeTypeNamePair(const char* ptr, const SerializedIndexSizes& sizes)
{
    return Il2CppWindowsRuntimeTypeNamePair {
            Read<StringIndex>(ptr), // nameIndex
            ReadIndex<TypeIndex>(ptr, sizes.typeIndex), // typeIndex
    };
}
