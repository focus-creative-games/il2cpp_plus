#pragma once

#include "il2cpp-metadata.h"

// This file contains the structures specifying how we store converted metadata.
// These structures have 3 constraints:
// 1. These structures will be stored in an external file, and as such must not contain any pointers.
//    All references to other metadata should occur via an index into a corresponding table.
// 2. These structures are assumed to be const. Either const structures in the binary or mapped as
//    readonly memory from an external file. Do not add any 'calculated' fields which will be written to at runtime.
// 3. These structures should be optimized for size. Other structures are used at runtime which can
//    be larger to store cached information

// The serialized size of some indexes may be one, two, or four bytes, dependending on how many elements the index needs
// to represent. In general, we use the smallest possible representation of an index to minimize the size of the
// serialized metadata. The structs in this file, and the indexes they contain, represent the *deserialized* form.
// The serialized size is known only at runtime, so it can't be expressed statically here.

// Values for EncodedMethodIndex:

// Encoded index (1 bit)
// MethodDef - 0
// MethodSpec - 1
// We use the top 3 bits to indicate what table to index into
// Type              Binary            Hex
// Il2CppClass       001               0x20000000
// Il2CppType        010               0x40000000
// MethodInfo        011               0x60000000
// FieldInfo         100               0x80000000
// StringLiteral     101               0xA0000000
// MethodRef         110               0xC0000000
// FieldRVA          111               0xE0000000

typedef uint32_t EncodedMethodIndex;

enum Il2CppMetadataUsage
{
    kIl2CppMetadataUsageInvalid,
    kIl2CppMetadataUsageTypeInfo,
    kIl2CppMetadataUsageIl2CppType,
    kIl2CppMetadataUsageMethodDef,
    kIl2CppMetadataUsageFieldInfo,
    kIl2CppMetadataUsageStringLiteral,
    kIl2CppMetadataUsageMethodRef,
    kIl2CppMetadataUsageFieldRva
};

enum Il2CppInvalidMetadataUsageToken
{
    kIl2CppInvalidMetadataUsageNoData = 0,
    kIl2CppInvalidMetadataUsageAmbiguousMethod = 1,
};

#ifdef __cplusplus
static inline Il2CppMetadataUsage GetEncodedIndexType(EncodedMethodIndex index)
{
    return (Il2CppMetadataUsage)((index & 0xE0000000) >> 29);
}

static inline uint32_t GetDecodedMethodIndex(EncodedMethodIndex index)
{
    return (index & 0x1FFFFFFEU) >> 1;
}

#endif

typedef struct Il2CppInterfaceOffsetPair
{
    TypeIndex interfaceTypeIndex;
    int32_t offset;
} Il2CppInterfaceOffsetPair;

typedef struct Il2CppTypeDefinition
{
    StringIndex nameIndex;
    StringIndex namespaceIndex;
    TypeIndex byvalTypeIndex;

    TypeIndex declaringTypeIndex;
    TypeIndex parentIndex;

    GenericContainerIndex genericContainerIndex;

    uint32_t flags;

    FieldIndex fieldStart;
    MethodIndex methodStart;
    EventIndex eventStart;
    PropertyIndex propertyStart;
    NestedTypeIndex nestedTypesStart;
    InterfacesIndex interfacesStart;
    VTableIndex vtableStart;
    InterfacesIndex interfaceOffsetsStart;

    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;

    // bitfield to portably encode boolean values as single bits
    // 01 - valuetype;
    // 02 - enumtype;
    // 03 - has_finalize;
    // 04 - has_cctor;
    // 05 - is_blittable;
    // 06 - is_import_or_windows_runtime;
    // 07-10 - One of nine possible PackingSize values (0, 1, 2, 4, 8, 16, 32, 64, or 128)
    // 11 - PackingSize is default
    // 12 - ClassSize is default
    // 13-16 - One of nine possible PackingSize values (0, 1, 2, 4, 8, 16, 32, 64, or 128) - the specified packing size (even for explicit layouts)
    uint32_t bitfield;
    uint32_t token;
} Il2CppTypeDefinition;

typedef struct Il2CppFieldDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    uint32_t token;
} Il2CppFieldDefinition;

typedef struct Il2CppFieldDefaultValue
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppFieldDefaultValue;

typedef struct Il2CppFieldMarshaledSize
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    int32_t size;
} Il2CppFieldMarshaledSize;

typedef struct Il2CppFieldRef
{
    TypeIndex typeIndex;
    FieldIndex fieldIndex; // local offset into type fields
} Il2CppFieldRef;

typedef struct Il2CppParameterDefinition
{
    StringIndex nameIndex;
    uint32_t token;
    TypeIndex typeIndex;
} Il2CppParameterDefinition;

typedef struct Il2CppParameterDefaultValue
{
    ParameterIndex parameterIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppParameterDefaultValue;

typedef struct Il2CppMethodDefinition
{
    StringIndex nameIndex;
    TypeDefinitionIndex declaringType;
    TypeIndex returnType;
    uint32_t returnParameterToken;
    ParameterIndex parameterStart;
    GenericContainerIndex genericContainerIndex;
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint16_t parameterCount;
} Il2CppMethodDefinition;

typedef struct Il2CppEventDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    MethodIndex add;
    MethodIndex remove;
    MethodIndex raise;
    uint32_t token;
} Il2CppEventDefinition;

typedef struct Il2CppPropertyDefinition
{
    StringIndex nameIndex;
    MethodIndex get;
    MethodIndex set;
    uint32_t attrs;
    uint32_t token;
} Il2CppPropertyDefinition;

typedef struct Il2CppStringLiteral
{
    StringLiteralIndex dataIndex;
} Il2CppStringLiteral;

typedef struct Il2CppAssemblyNameDefinition
{
    StringIndex nameIndex;
    StringIndex cultureIndex;
    StringIndex publicKeyIndex;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[PUBLIC_KEY_BYTE_LENGTH];
} Il2CppAssemblyNameDefinition;

typedef struct Il2CppImageDefinition
{
    StringIndex nameIndex;
    AssemblyIndex assemblyIndex;

    TypeDefinitionIndex typeStart;
    uint32_t typeCount;

    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;

    MethodIndex entryPointIndex;
    uint32_t token;

    CustomAttributeIndex customAttributeStart;
    uint32_t customAttributeCount;
} Il2CppImageDefinition;

typedef struct Il2CppAssemblyDefinition
{
    ImageIndex imageIndex;
    uint32_t token;
    uint32_t moduleToken;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    Il2CppAssemblyNameDefinition aname;
} Il2CppAssemblyDefinition;

typedef struct Il2CppCustomAttributeDataRange
{
    uint32_t token;
    uint32_t startOffset;
} Il2CppCustomAttributeDataRange;

typedef struct Il2CppMetadataRange
{
    int32_t start;
    int32_t length;
} Il2CppMetadataRange;

typedef struct Il2CppGenericContainer
{
    /* index of the generic type definition or the generic method definition corresponding to this container */
    int32_t ownerIndex; // either index into Il2CppClass metadata array or Il2CppMethodDefinition array
    int32_t type_argc;
    /* If true, we're a generic method, otherwise a generic type definition. */
    int32_t is_method;
    /* Our type parameters. */
    GenericParameterIndex genericParameterStart;
} Il2CppGenericContainer;

typedef struct Il2CppGenericParameter
{
    GenericContainerIndex ownerIndex;  /* Type or method this parameter was defined in. */
    StringIndex nameIndex;
    GenericParameterConstraintIndex constraintsStart;
    int16_t constraintsCount;
    uint16_t num;
    uint16_t flags;
} Il2CppGenericParameter;


typedef struct Il2CppWindowsRuntimeTypeNamePair
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
} Il2CppWindowsRuntimeTypeNamePair;

typedef struct Il2CppSectionMetadata
{
    int32_t offset;
    int32_t size;
    int32_t count;
} Il2CppSectionMetadata;

#pragma pack(push, p1,4)
typedef struct Il2CppGlobalMetadataHeader
{
    uint32_t sanity;
    int32_t version;

    Il2CppSectionMetadata stringLiterals; // string data for managed code
    Il2CppSectionMetadata stringLiteralData;
    Il2CppSectionMetadata strings; // string data for metadata
    Il2CppSectionMetadata events; // Il2CppEventDefinition
    Il2CppSectionMetadata properties; // Il2CppPropertyDefinition
    Il2CppSectionMetadata methods; // Il2CppMethodDefinition
    Il2CppSectionMetadata parameterDefaultValues; // Il2CppParameterDefaultValue
    Il2CppSectionMetadata fieldDefaultValues; // Il2CppFieldDefaultValue
    Il2CppSectionMetadata fieldAndParameterDefaultValueData; // uint8_t
    Il2CppSectionMetadata fieldMarshaledSizes; // Il2CppFieldMarshaledSize
    Il2CppSectionMetadata parameters; // Il2CppParameterDefinition
    Il2CppSectionMetadata fields; // Il2CppFieldDefinition
    Il2CppSectionMetadata genericParameters; // Il2CppGenericParameter
    Il2CppSectionMetadata genericParameterConstraints; // TypeIndex
    Il2CppSectionMetadata genericContainers; // Il2CppGenericContainer
    Il2CppSectionMetadata nestedTypes; // TypeDefinitionIndex
    Il2CppSectionMetadata interfaces; // TypeIndex
    Il2CppSectionMetadata vtableMethods; // EncodedMethodIndex
    Il2CppSectionMetadata interfaceOffsets; // Il2CppInterfaceOffsetPair
    Il2CppSectionMetadata typeDefinitions; // Il2CppTypeDefinition
    Il2CppSectionMetadata images; // Il2CppImageDefinition
    Il2CppSectionMetadata assemblies; // Il2CppAssemblyDefinition
    Il2CppSectionMetadata fieldRefs; // Il2CppFieldRef
    Il2CppSectionMetadata referencedAssemblies; // int32_t
    Il2CppSectionMetadata attributeData;
    Il2CppSectionMetadata attributeDataRanges;
    Il2CppSectionMetadata unresolvedIndirectCallParameterTypes; // TypeIndex
    Il2CppSectionMetadata unresolvedIndirectCallParameterRanges; // Il2CppMetadataRange
    Il2CppSectionMetadata windowsRuntimeTypeNames; // Il2CppWindowsRuntimeTypeNamePair
    Il2CppSectionMetadata windowsRuntimeStrings; // const char*
    Il2CppSectionMetadata exportedTypeDefinitions; // TypeDefinitionIndex
} Il2CppGlobalMetadataHeader;
#pragma pack(pop, p1)
