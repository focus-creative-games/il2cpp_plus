#pragma once
/*************************************************************************************************************************************
 * SSE and AVX macros should be defined based on compiler flags for gcc and clang:                                                  **
 * https://stackoverflow.com/questions/28939652/how-to-detect-sse-sse2-avx-avx2-avx-512-avx-128-fma-kcvi-availability-at-compile    **
 *                                                                                                                                  **
 * MSVC macros are defined as follows:                                                                                              **
 * _M_IX86_FP:  0 (no SSE)                                                                                                          **
 *              1 (SSE)                                                                                                             **
 *              2 (SSE2) | (AVX)/(AVX2)...  Only __AVX__ style macros will be predefined based on which /arch flag is used.         **
 * https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170                                               **
 *                                                                                                                                  **
 * ARM/NEON intrisics:                                                                                                              **
 * https://developer.arm.com/documentation/102467/0201/Program-conventions?lang=en                                                  **
 *                                                                                                                                  **
 * MSVC NEON intrinsics:                                                                                                            **
 * https://learn.microsoft.com/en-us/cpp/intrinsics/arm64-intrinsics?view=msvc-170                                                  **
 * https://learn.microsoft.com/en-us/cpp/build/reference/arch-arm64?view=msvc-170                                                   **
 ************************************************************************************************************************************/

/// ARM Intrisic support - ADVANCED SIMD (NEON)
#if defined(__ARM_NEON__) || defined(__ARM_NEON)
#  include <arm_neon.h>
#  include <arm_acle.h>
#  define IL2CPP_NEON_IS_SUPPORTED 1
#  define IL2CPP_ARMBASE_IS_SUPPORTED 1
#  define IL2CPP_ADVSIMD_IS_SUPPORTED 1
#  define IL2CPP_ARM_DP_IS_SUPPORTED 1
#  define IL2CPP_ARM_RDM_IS_SUPPORTED 1
#  define IL2CPP_ARM_SHA1_IS_SUPPORTED 1
#  define IL2CPP_ARM_SHA256_IS_SUPPORTED 1

#  ifdef __ARM_FEATURE_AES
#    define IL2CPP_ARM_AES_IS_SUPPORTED __ARM_FEATURE_AES
#  endif

#if defined(__aarch64__)
#    define IL2CPP_NEON64_IS_SUPPORTED 1
#    define IL2CPP_ADVSIMD_ARM64_IS_SUPPORTED 1
#   endif

#  ifdef __ARM_FEATURE_CRC32
#    define IL2CPP_ARM_CRC32_IS_SUPPORTED __ARM_FEATURE_CRC32
#  endif
#endif //__ARM_NEON__

// MSVC specific macro check
#if defined(_MSC_VER)
/// ARM64 Intrisic support MSVC Specific
#  ifdef _M_ARM64
#    include <arm_neon.h>
#    define IL2CPP_NEON_IS_SUPPORTED 1
#    define IL2CPP_ADVSIMD_IS_SUPPORTED 1
#    define IL2CPP_ARM_RDM_IS_SUPPORTED 1
#    define IL2CPP_ARM_SHA1_IS_SUPPORTED 1
#    define IL2CPP_ARM_SHA256_IS_SUPPORTED 1

#    include <arm64_neon.h>
#    define IL2CPP_NEON64_IS_SUPPORTED 1
#    define IL2CPP_ARMBASE_IS_SUPPORTED 1
#    define IL2CPP_ARMBASE_ARM64_IS_SUPPORTED 1
#    define IL2CPP_ADVSIMD_ARM64_IS_SUPPORTED 1

#  ifdef __ARM_FEATURE_CRC32
#    define IL2CPP_ARM_CRC32_IS_SUPPORTED __ARM_FEATURE_CRC32
#  endif

#    ifdef __ARM_FEATURE_AES
#        define IL2CPP_ARM_AES_IS_SUPPORTED __ARM_FEATURE_AES
#    endif


#  endif

// To reduce complexity for now, immitrin.h will be used for all MSVC stuff that's not NEON based
// SSE2 and SSE are set if _M_IX86_FP is 2. SSE 1 and 2 are automatically set if M_AMD64 or M_X64 is defined
#  if (defined(_M_AMD64) || defined(_M_X64))
#    ifndef IL2CPP_X86BASE_IS_SUPPORTED
#      define IL2CPP_X86BASE_IS_SUPPORTED 1 //base instructions
#    endif
#    ifndef IL2CPP_X86BASE_X64_IS_SUPPORTED
#      define IL2CPP_X86BASE_X64_IS_SUPPORTED 1 //base 64-bit instructions
#    endif
#    include <intrin.h>
#    include <immintrin.h>
#    ifndef IL2CPP_SSE_IS_SUPPORTED
#      define IL2CPP_SSE_IS_SUPPORTED 1
#      define IL2CPP_SSE_X64_IS_SUPPORTED 1
#    endif
#    ifndef IL2CPP_SSE2_IS_SUPPORTED
#      define IL2CPP_SSE2_IS_SUPPORTED 1
#      define IL2CPP_SSE2_X64_IS_SUPPORTED 1   // emmintrin.h checks for _M_X64 || (_M_ARM64 && USE_SOFT_INTRINSICS)
#    endif
#    ifndef IL2CPP_SSE3_IS_SUPPORTED
#      define IL2CPP_SSE3_IS_SUPPORTED 1
#      define IL2CPP_SSE3_X64_IS_SUPPORTED 1
#    endif
#    ifndef IL2CPP_SSSE3_IS_SUPPORTED
#      define IL2CPP_SSSE3_IS_SUPPORTED 1
#      define IL2CPP_SSSE3_X64_IS_SUPPORTED 1
#    endif
#    ifndef IL2CPP_SSE41_IS_SUPPORTED
#      define IL2CPP_SSE41_IS_SUPPORTED 1
#      define IL2CPP_SSE41_X64_IS_SUPPORTED 1
#    endif
#    ifndef IL2CPP_SSE42_IS_SUPPORTED
#      define IL2CPP_SSE42_IS_SUPPORTED 1
#      define IL2CPP_SSE42_X64_IS_SUPPORTED 1
#    endif
#    ifdef IL2CPP_AVX2_IS_SUPPORTED          // LZCNT and BMI are implied if AVX is supported on Windows
#      ifndef IL2CPP_LZCNT_IS_SUPPORTED
#        define IL2CPP_LZCNT_IS_SUPPORTED 1
#        define IL2CPP_LZCNT_X64_IS_SUPPORTED 1
#      endif
#    endif
#    ifdef _INCLUDED_WMM                 // This section should be re-written when we update unity to allow option selection
#      ifndef IL2CPP_AES_IS_SUPPORTED
#        define IL2CPP_AES_IS_SUPPORTED 1
#      endif
#      ifndef IL2CPP_PCLMULQDQ_IS_SUPPORTED
#        define IL2CPP_PCLMULQDQ_IS_SUPPORTED 1
#      endif
#    endif
#    ifdef _INCLUDED_NMM                 //if you include <nmmintrin.h> or <intrin.h>, you can assume that the compiler supports the POPCNT. We will have to update this to add a define check when we hook it up for user option selection
#      ifndef IL2CPP_POPCNT_IS_SUPPORTED
#        define IL2CPP_POPCNT_IS_SUPPORTED 1
#        define IL2CPP_POPCNT_X64_IS_SUPPORTED 1
#      endif
#    endif
#    ifdef _X86INTRIN_H
#      ifdef __AVX__
#         ifndef IL2CPP_FMA_IS_SUPPORTED
#           define IL2CPP_FMA_IS_SUPPORTED 1
#         endif
#      endif
#    endif
#  elif _M_IX86_FP == 2
#    include <intrin.h>
#    include <immintrin.h>
#    ifndef IL2CPP_X86BASE_IS_SUPPORTED
#      define IL2CPP_X86BASE_IS_SUPPORTED 1 //base instructions
#    endif
#    ifndef IL2CPP_X86BASE_X64_IS_SUPPORTED
#      define IL2CPP_X86BASE_X64_IS_SUPPORTED 1 //base 64-bit instructions
#    endif
#    ifndef IL2CPP_SSE_IS_SUPPORTED
#      define IL2CPP_SSE_IS_SUPPORTED 1
#    endif
#    ifndef IL2CPP_SSE2_IS_SUPPORTED
#      define IL2CPP_SSE2_IS_SUPPORTED 1
#      define IL2CPP_SSE2_X64_IS_SUPPORTED 1   // emmintrin.h checks for _M_X64 || (_M_ARM64 && USE_SOFT_INTRINSICS)
#    endif
// only SSE1 is set if _M_IX86_FP is 1
#  elif _M_IX86_FP == 1
#    include <immintrin.h>
#    ifndef IL2CPP_X86BASE_IS_SUPPORTED
#      define IL2CPP_X86BASE_IS_SUPPORTED 1 //base instructions
#    endif
#    ifndef IL2CPP_X86BASE_X64_IS_SUPPORTED
#      define IL2CPP_X86BASE_X64_IS_SUPPORTED 1 //base 64-bit instructions
#    endif
#    ifndef IL2CPP_SSE_IS_SUPPORTED
#      define IL2CPP_SSE_IS_SUPPORTED 1
#    endif
#  endif
#endif  // _MSC_VER

/// For now, to reduce complexity SSE Intrinsic includes and AVX includes will catch all with immintrin.h, which is part of GCC library
#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__) || defined(__SSE4_1__) || defined(__SSE4_2__) || defined(__AVX__) || defined(__AVX2__)
#  include <immintrin.h>
#  ifndef IL2CPP_X86BASE_IS_SUPPORTED
#    define IL2CPP_X86BASE_IS_SUPPORTED 1 //base instructions
#  endif
#  ifndef IL2CPP_X86BASE_X64_IS_SUPPORTED
#    define IL2CPP_X86BASE_X64_IS_SUPPORTED 1 //base 64-bit instructions
#  endif
#endif // __AVX__ || __AVX2__

/// SSE Intrisic support
#ifdef __SSE__
#  ifndef IL2CPP_SSE_IS_SUPPORTED
#    define IL2CPP_SSE_IS_SUPPORTED 1
#  endif
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_SSE_X64_IS_SUPPORTED 1
#  endif
#endif //__SSE__

/// SSE2 Intrisic support
#ifdef __SSE2__
#  ifndef IL2CPP_SSE2_IS_SUPPORTED
#    define IL2CPP_SSE2_IS_SUPPORTED 1
#  endif
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_SSE2_X64_IS_SUPPORTED 1
#  endif
#endif //__SSE2__

/// SSE3 Intrisic support
#ifdef __SSE3__
#  ifndef IL2CPP_SSE3_IS_SUPPORTED
#    define IL2CPP_SSE3_IS_SUPPORTED 1
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_SSE3_X64_IS_SUPPORTED 1
#  endif
#  endif
#endif //__SSE3__

/// SSSE3 Intrisic support
#ifdef __SSSE3__
#  ifndef IL2CPP_SSSE3_IS_SUPPORTED
#    define IL2CPP_SSSE3_IS_SUPPORTED 1
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_SSSE3_X64_IS_SUPPORTED 1
#  endif
#  endif
#endif //__SSSE3__

#ifdef __SSE4_1__
#  ifndef IL2CPP_SSE41_IS_SUPPORTED
#    define IL2CPP_SSE41_IS_SUPPORTED 1
#  endif
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_SSE41_X64_IS_SUPPORTED 1
#  endif
#endif //__SSE4_1__

#ifdef __SSE4_2__
#  ifndef IL2CPP_SSE42_IS_SUPPORTED
#    define IL2CPP_SSE42_IS_SUPPORTED 1
#  endif
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_SSE42_X64_IS_SUPPORTED 1
#  endif
#endif //__SSE4_2__

/// AVX Intrisic support
#ifdef __AVX__
#  ifndef IL2CPP_AVX_IS_SUPPORTED
#    define IL2CPP_AVX_IS_SUPPORTED 1
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_AVX_X64_IS_SUPPORTED 1
#  endif
#  endif
/// FMA intrinsic support
#  ifdef __FMA__
#    ifndef IL2CPP_FMA_IS_SUPPORTED
#     define IL2CPP_FMA_IS_SUPPORTED 1
#    endif
#  endif
#endif //__AVX__

/// AVX2 Intrisic support
#ifdef __AVX2__
#  ifndef IL2CPP_AVX2_IS_SUPPORTED
#    define IL2CPP_AVX2_IS_SUPPORTED 1
#    define IL2CPP_BMI1_IS_SUPPORTED 1
#    define IL2CPP_BMI2_IS_SUPPORTED 1
#  endif
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_M_X64)
#    define IL2CPP_AVX2_X64_IS_SUPPORTED 1
#    define IL2CPP_BMI1_X64_IS_SUPPORTED 1
#    define IL2CPP_BMI2_X64_IS_SUPPORTED 1
#  endif
#endif //__AVX2__


#ifndef IL2CPP_X86BASE_IS_SUPPORTED
    #define IL2CPP_X86BASE_IS_SUPPORTED 0
#endif
#ifndef IL2CPP_X86BASE_X64_IS_SUPPORTED
    #define IL2CPP_X86BASE_X64_IS_SUPPORTED 0
#endif

// LZCNT macro only defined under -mlzcnt on GCC/Clang, or if /arch:AVX2 is used on MSVC (see the msvc section at the top of the file)
#ifdef __LZCNT__
#  ifndef IL2CPP_LZCNT_IS_SUPPORTED
#    define IL2CPP_LZCNT_IS_SUPPORTED 1
#    define IL2CPP_LZCNT_X64_IS_SUPPORTED 1
#  endif
#endif //__LZCNT__

// AES macro only defined under -maes on GCC/Clang, or if wmmintrin.h is included. See msvc section to follow _INCLUDED_WMM
#ifdef __AES__
#  ifndef IL2CPP_AES_IS_SUPPORTED
#    define IL2CPP_AES_IS_SUPPORTED 1
#  endif
#endif // __AES__

// Pclmulqdq macro is only defined under -mpclmul on gcc/clang, or if wmmintrin.h is included. See msvc section to follow _INCLUDED_WMM
#ifdef __PCLMUL__
#  ifndef IL2CPP_PCLMULQDQ_IS_SUPPORTED
#    define IL2CPP_PCLMULQDQ_IS_SUPPORTED 1
#  endif
#endif //__PCLMUL__
