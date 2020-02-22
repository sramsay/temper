
#if __COVERITY__
#if !defined(COVERITY_COMPAT_f7d41afe550542f7c525a437cfc2a76c)
#define COVERITY_COMPAT_f7d41afe550542f7c525a437cfc2a76c

/*
  Copyright (c) 2018, Synopsys, Inc. All rights reserved worldwide.
  The information contained in this file is the proprietary and confidential
  information of Synopsys, Inc. and its licensors, and is supplied subject to,
  and may be used only by Synopsys customers in accordance with the terms and
  conditions of a previously executed license agreement between Synopsys and
  that customer.
*/


/* DO NOT MODIFY THE CONTENTS OF THIS FILE */


#if defined(__cplusplus)
extern "C" {
#endif

/*
  This shouldn't happen in practice. However, some of our test cases don't
  predefine these appropriately, so we default to something sensible.
*/
#if !defined(__clang_major__) && !defined(__clang_minor__)
#define __clang_major__ 3
#define __clang_minor__ 4
#endif

/*
  When compiling with optimizations enabled, the GNU C library (glibc) string.h
  header file provides implementations for some C standard library functions
  such as strcmp() via function-like macro definitions.  These macro definitions
  prevent analysis from using Coverity provided models and from recognizing some
  kinds of defects.  Other compiler configurations use Coverity's #nodef
  facility to suppress these macros, but #nodef is not currently supported with
  the Clang based frontend.  Defining __NO_STRING_INLINES prevents string.h from
  defining these macros.
*/
#define __NO_STRING_INLINES


/*
  Mac OS X and GNU C library (glibc) standard headers provide implementations of
  some C standard library functions via function-like macro definitions when
  _FORTIFY_SOURCE is defined as a number larger than 0.  By default, Mac OS X
  feature headers define _FORTIFY_SOURCE as 2 for Mac OS X 10.5 and above.
  These macro definitions prevent analysis from using Coverity provided models
  and from recognizing some kinds of defects.  Other compiler configurations use
  Coverity's #nodef facility to suppress these macros, but #nodef is not
  currently supported with the Clang based frontend.  Defining _FORTIFY_SOURCE
  as 0 prevents these macros from being defined.
*/
#define _FORTIFY_SOURCE 0

/*
  Determine whether we are actually configuring an Apple Clang build.
  Apple Clang versions 2.1 and earlier did not define the
  __apple_build_version__ macro.  This heuristic would fail for LLVM Clang
  releases earlier than 2.2, which are not supported.
*/
#if defined(__apple_build_version__)
#define __coverity_assume_xcode__ 1
#else // defined(__apple_build_version__)
#define __coverity_assume_xcode__ ((__clang_major__ < 2) || \
    ((__clang_major__ == 2) && (__clang_minor__ <= 1)))
#endif // !defined(__apple_build_version)


/*************************************
 *********** APPLE CLANG *************
 *************************************/

/*
  Apple's Clang distribution does not retain the values of the LLVM Clang
  distribution for the __clang_major__ and __clang_minor__ predefined macros.
  Rather, they are defined to match Apple's version branding.  For example, the
  distribution of Clang provided with Xcode 4.1 defines these macros as '2' and
  '1' respectively despite the distribution having derived from the LLVM Clang
  3.0 release which sets them to '3' and '0' respectively.  This header file
  depends on the ability to detect the version of Clang to emulate based on
  predefined macros.  Recent versions of Apple's Clang distribution predefine
  the __apple_build_version__ macro which enables recognition of Apple's
  distribution.  __coverity_clang_major__ and __coverity_clang_minor__ are
  set based on the presence of __apple_build_version__ and mapped values for
  the __clang_major__ and __clang_minor__ macros.
*/
#if __coverity_assume_xcode__
    /* Apple's Clang distribution */
    #if __clang_major__ >= 10
         /* Assume derivation from LLVM Clang 6.0 */
        #define __coverity_clang_major__ 6
        #define __coverity_clang_minor__ 0
    #elif __clang_major__ >= 9
        /* Assume derivation from LLVM Clang 4.0 */
        #define __coverity_clang_major__ 4
        #define __coverity_clang_minor__ 0
    #elif __clang_major__ >= 8
        /* Assume derivation from LLVM Clang 3.8 */
        #define __coverity_clang_major__ 3
        #define __coverity_clang_minor__ 8
    #elif __clang_major__ >= 7
        #if __clang_minor__ >= 3
            /* Assume derivation from LLVM Clang 3.8 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 8
        #else
            /* Assume derivation from LLVM Clang 3.7 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 7
        #endif
    #elif __clang_major__ >= 6
        #if __clang_minor__ >= 3
            /* Assume derivation from LLVM Clang 3.6 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 6
        #else
            /* Assume derivation from LLVM Clang 3.5 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 5
        #endif
    #elif __clang_major__ >= 5
        #if __clang_minor__ >= 1
            /* Assume derivation from LLVM Clang 3.4 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 4
        #else
            /* Assume derivation from LLVM Clang 3.3 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 3
        #endif
    #elif __clang_major__ >= 4
        #if __clang_minor__ >= 2
            /* Assume derivation from LLVM Clang 3.2 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 2
        #else
            /* Assume derivation from LLVM Clang 3.1 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 1
        #endif
    #elif __clang_major__ >= 3
        #if __clang_minor__ >= 1
            /* Assume derivation from LLVM Clang 3.1 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 1
        #else
            /* Assume derivation from LLVM Clang 3.0 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 0
        #endif
    #else
        #if (__clang_major__ >= 2) || \
            ((__clang_major__ == 1) && (__clang_minor__ > 7))
            /* Assume Apple Clang version 2.1 derived from LLVM Clang 3.0 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 0
        #else
            /* Assume Apple Clang version 1.7 derived from LLVM Clang 2.9 */
            #define __coverity_clang_major__ 2
            #define __coverity_clang_minor__ 9
        #endif
    #endif
#else /* } { */
    /* Assume LLVM Clang distribution */
    #define __coverity_clang_major__ __clang_major__
    #define __coverity_clang_minor__ __clang_minor__
#endif /* } */

/* Encode a version pair as a single integer. */
#define __cov_encode_ver(maj, min) ((maj) * 100 + (min))

/*
 * Compare two version pairs. Roughly equivalent to:
 * (version 0) op (version 1)
 * where `op` is a relational operator.
 */
#define __cov_compare_versions(maj0, min0, maj1, min1, op) \
    ((__cov_encode_ver(maj1, min1) - __cov_encode_ver(maj0, min0)) op 0)

/*
 * Compare the given version against the coverity compatibility
 * version with the given relational operator.
 */
#define __cov_comp_clang_compat_ver(maj, min, op) \
    (__cov_compare_versions( \
        maj, min, \
        __coverity_clang_major__, __coverity_clang_minor__, \
        op \
    ))

/*
 * Compare the given version against the native version with the given
 * relational operator.
 */
#define __cov_comp_clang_native_ver(maj, min, op) \
    (__cov_compare_versions( \
        maj, min, \
        __clang_major__, __clang_minor__, \
        op \
    ))

#define __cov_clang_version_lt(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), <)
#define __cov_clang_version_gt(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), >)
#define __cov_clang_version_le(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), <=)
#define __cov_clang_version_ge(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), >=)

#define __cov_xcode_version_lt(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), <))
#define __cov_xcode_version_gt(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), >))
#define __cov_xcode_version_le(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), <=))
#define __cov_xcode_version_ge(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), >=))

/*
 * These types are used for builtins whose prototypes
 * depend on the C++ bool or size_t constructs, which
 * aren't normally available in C.
 */
#define __cov_compat_bool __typeof(1==1)
#define __cov_compat_size_t __typeof(sizeof(0))
#define __cov_compat_wchar_t __typeof(L'\0')

/*
  The following builtins were never present in any LLVM Clang release, but
  did appear briefly in the LLVM Clang source code.  They are added here
  for compatibility with other Clang releases such as for the PS4.
*/
/* Removed in revision 110771 { */
extern signed int __attribute__((vector_size(32)))
__coverity__builtin_ia32_si256_si(
    signed int __attribute__((vector_size(16))));
#define __builtin_ia32_si256_si(P1) \
    __coverity__builtin_ia32_si256_si((P1))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_ps256_ps(
    float __attribute__((vector_size(16))));
#define __builtin_ia32_ps256_ps(P1) \
    __coverity__builtin_ia32_ps256_ps((P1))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_pd256_pd(
    double __attribute__((vector_size(16))));
#define __builtin_ia32_pd256_pd(P1) \
    __coverity__builtin_ia32_pd256_pd((P1))

extern signed int __attribute__((vector_size(16)))
__coverity__builtin_ia32_si_si256(
    signed int __attribute__((vector_size(32))));
#define __builtin_ia32_si_si256(P1) \
    __coverity__builtin_ia32_si_si256((P1))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_ps_ps256(
    float __attribute__((vector_size(32))));
#define __builtin_ia32_ps_ps256(P1) \
    __coverity__builtin_ia32_ps_ps256((P1))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_pd_pd256(
    double __attribute__((vector_size(32))));
#define __builtin_ia32_pd_pd256(P1) \
    __coverity__builtin_ia32_pd_pd256((P1))
/* } Removed in revision 110771 */


/*************************************
 ************* CLANG 3.0 *************
 *************************************/

/*
 * This was removed in revision 131300 in clang 3.0, but
 * some vendors still include it.
 */
#if __cov_clang_version_le(3,0) /* { */

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_loaddqu(const char *);
#define __builtin_ia32_loaddqu(P1) \
    __coverity__builtin_ia32_loaddqu((P1))

#endif /* } clang <= 3.0 */

/* The following builtins were present in Clang 2.9, but removed in Clang 3.0 */
#if __cov_clang_version_lt(3, 0) /* { */

/* Removed in revision 131300 { */

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_loadups(const float *);
#define __builtin_ia32_loadups(P1) \
    __coverity__builtin_ia32_loadups((P1))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_loadupd(const double *);
#define __builtin_ia32_loadupd(P1) \
    __coverity__builtin_ia32_loadupd((P1))

/* } Removed in revision 131300 */

#endif /* } clang < 3.0 */


/*************************************
 ************* CLANG 3.1 *************
 *************************************/

/* The following builtins were present in Clang 3.0, but removed in Clang 3.1 */
#if __cov_clang_version_le(3, 0) /* { */

/* Removed in revision 154579 { */
#define __atomic_compare_exchange_strong(P1, P2, P3, P4, P5) \
    __c11_atomic_compare_exchange_strong((P1), (P2), (P3), (P4), (P5))

#define __atomic_compare_exchange_weak(P1, P2, P3, P4, P5) \
    __c11_atomic_compare_exchange_weak((P1), (P2), (P3), (P4), (P5))
/* } Removed in revision 154579 */

/* Removed in revision 148919 { */
extern long long __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_loaddqu256(const char *p);
#define __builtin_ia32_loaddqu256(P1) \
    __coverity__builtin_ia32_loaddqu256((P1))

extern double __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_loadupd256(const double *p);
#define __builtin_ia32_loadupd256(P1) \
    __coverity__builtin_ia32_loadupd256((P1))

extern float __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_loadups256(const float *p);
#define __builtin_ia32_loadups256(P1) \
    __coverity__builtin_ia32_loadups256((P1))
/* } Removed in revision 148919 */

/* Removed in revision 146969 { */
extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpeqb128(
    char __attribute__((vector_size(16))) p1,
    char __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpeqb128(P1, P2) \
    __coverity__builtin_ia32_pcmpeqb128((P1), (P2))

extern signed int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpeqd128(
    signed int __attribute__((vector_size(16))) p1,
    signed int __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpeqd128(P1, P2) \
    __coverity__builtin_ia32_pcmpeqd128((P1), (P2))

extern signed short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpeqw128(
    signed short __attribute__((vector_size(16))) p1,
    signed short __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpeqw128(P1, P2) \
    __coverity__builtin_ia32_pcmpeqw128((P1), (P2))

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpgtb128(
    char __attribute__((vector_size(16))) p1,
    char __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpgtb128(P1,P2) \
    __coverity__builtin_ia32_pcmpgtb128((P1), (P2))

extern signed int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpgtd128(
    signed int __attribute__((vector_size(16))) p1,
    signed int __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpgtd128(P1, P2) \
    __coverity__builtin_ia32_pcmpgtd128((P1), (P2))

extern signed short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpgtw128(
    signed short __attribute__((vector_size(16))) p1,
    signed short __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpgtw128(P1, P2) \
    __coverity__builtin_ia32_pcmpgtw128((P1), (P2))

extern long long __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_pcmpeqq(
    long long __attribute__((__vector_size__(16))) p1,
    long long __attribute__((__vector_size__(16))) p2);
#define __builtin_ia32_pcmpeqq(P1, P2) \
    __coverity__builtin_ia32_pcmpeqq((P1), (P2))

extern long long __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_pcmpgtq(
    long long __attribute__((__vector_size__(16))) p1,
    long long __attribute__((__vector_size__(16))) p2);
#define __builtin_ia32_pcmpgtq(P1, P2) \
    __coverity__builtin_ia32_pcmpgtq((P1), (P2))
/* } Removed in revision 146969 */

/* Removed in revision 144073 { */
extern int
__coverity__builtin_ia32_pcmpestria128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestria128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestria128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestric128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestric128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestric128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestrio128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestrio128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestrio128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestris128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestris128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestris128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestriz128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestriz128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestriz128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistria128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistria128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistria128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistric128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistric128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistric128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistrio128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistrio128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistrio128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistris128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistris128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistris128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistriz128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistriz128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistriz128((P1), (P2), (P3), (P4), (P5))

/* } Removed in revision 144073 */

/* Removed in revision 149233 { */
extern float __attribute__((vector_size(8)))
__coverity__builtin_ia32_pfrsqrtit1(
    float __attribute__((vector_size(8))) p1,
    float __attribute__((vector_size(8))) p2);
#define __builtin_ia32_pfrsqrtit1(P1, P2) \
    __coverity__builtin_ia32_pfrsqrtit1((P1), (P2))
/* } Removed in revision 149233 */

/* Removed in revision 150056 { */
extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_vpermilpd(
    double __attribute__((vector_size(16))) p1,
    char c);
#define __builtin_ia32_vpermilpd(P1, P2) \
    __coverity__builtin_ia32_vpermilpd((P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_vpermilps(
    float __attribute__((vector_size(16))) p1,
    char c);
#define __builtin_ia32_vpermilps(P1, P2) \
    __coverity__builtin_ia32_vpermilps((P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_vpermilpd256(
    double __attribute__((vector_size(32))) p1,
    char c);
#define __builtin_ia32_vpermilpd256(P1, P2) \
    __coverity__builtin_ia32_vpermilpd256((P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_vpermilps256(
    float __attribute__((vector_size(32))) p1,
    char c);
#define __builtin_ia32_vpermilps256(P1, P2) \
    __coverity__builtin_ia32_vpermilps256((P1), (P2))
/* } Removed in revision 150056 */

/* The final argument to these was changed to be a constexpr some time between
 * release 3.0 and 3.1, but smmintrin.h prior to 3.1 uses a const function
 * parameter.
 * { */

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    const int);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    const int);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    const int);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

/* } Changed to take a constexpr arg. */

#endif /* } clang <= 3.0 */

/*
 * Clang 3.0 and earlier do not diagnose calls to the following builtins that
 * pass non-constant expressions where constant expressions are required.
 * Clang 3.1 and later do.  The following compatibility signatures are present
 * to enable compilation of Clang 3.0 provided headers.
 */
#if __cov_clang_version_le(3, 0) /* { */

// Signature: "V4dV4dIi"
extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_roundpd256(
    double __attribute__((vector_size(32))) p0,
    int p1);
#define __builtin_ia32_roundpd256(P0, P1) \
    __coverity___builtin_ia32_roundpd256((P0), (P1))

// Signature: "V8fV8fIi"
extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_roundps256(
    float __attribute__((vector_size(32))) p0,
    int p1);
#define __builtin_ia32_roundps256(P0, P1) \
    __coverity___builtin_ia32_roundps256((P0), (P1))

// Signature: "V4dV4dV4dIc"
extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_pd256(
    double __attribute__((vector_size(32))) p0,
    double __attribute__((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_vperm2f128_pd256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_pd256((P0), (P1), (P2))

// Signature: "V8fV8fV8fIc"
extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_ps256(
    float __attribute__((vector_size(32))) p0,
    float __attribute__((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_vperm2f128_ps256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_ps256((P0), (P1), (P2))

// Signature: "V8iV8iV8iIc"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_si256(
    long long __attribute__((vector_size(32))) p0,
    long long __attribute__((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_vperm2f128_si256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_si256((P0), (P1), (P2))

#endif /* } clang <= 3.0 */


/*************************************
 ************* CLANG 3.2 *************
 *************************************/

/* The following builtins were present in Clang 3.1, but removed in Clang 3.2 */
#if __cov_clang_version_le(3,1) /* { */

/* Removed in revision 156630 { */
extern long long
__coverity__builtin_A2_addpsat(long long p1, long long p2);
#define __builtin_A2_addpsat(P1, P2) \
    __coverity__builtin_A2_addpsat((P1), (P2))

extern long long
__coverity__builtin_A2_addsp(int p1, long long p2);
#define __builtin_A2_addsp(P1, P2) \
    __coverity__builtin_A2_addsp((P1), (P2))

extern long long
__coverity__builtin_A2_maxp(long long p1, long long p2);
#define __builtin_A2_maxp(P1, P2) \
    __coverity__builtin_A2_maxp((P1), (P2))

extern long long
__coverity__builtin_A2_maxup(long long p1, long long p2);
#define __builtin_A2_maxup(P1, P2) \
    __coverity__builtin_A2_maxup((P1), (P2))

extern int
__coverity__builtin_M2_vradduh(long long p1, long long p2);
#define __builtin_M2_vradduh(P1, P2) \
    __coverity__builtin_M2_vradduh((P1), (P2))

extern long long
__coverity__builtin_M2_vrcmpys_acc_s1(long long p1, long long p2, int p3);
#define __builtin_M2_vrcmpys_acc_s1(P1, P2, P3) \
    __coverity__builtin_M2_vrcmpys_acc_s1((P1), (P2), (P3))

extern long long
__coverity__builtin_M2_vrcmpys_s1(long long p1, int p2);
#define __builtin_M2_vrcmpys_s1(P1, P2) \
    __coverity__builtin_M2_vrcmpys_s1((P1), (P2))

extern int
__coverity__builtin_M2_vrcmpys_s1rp(long long p1, int p2);
#define __builtin_M2_vrcmpys_s1rp(P1, P2) \
    __coverity__builtin_M2_vrcmpys_s1rp((P1), (P2))
/* } Removed in revision 156630 */

/* Removed in revision 155924 { */
extern void
__coverity__builtin_ia32_storelv4si(
    signed int __attribute__((vector_size(8))) *p1,
    signed long long __attribute__((vector_size(16))) p2);
#define __builtin_ia32_storelv4si(P1, P2) \
    __coverity__builtin_ia32_storelv4si((P1), (P2))
/* } Removed in revision 155924 */

#endif /* } clang <= 3.1 */


/* No builtins present in Clang 3.2 were removed in Clang 3.3 */

/*************************************
 ************* CLANG 3.4 *************
 *************************************/

/* The following builtins were present in Clang 3.3, but removed in Clang 3.4 */
#if __cov_clang_version_le(3, 3) /* { */

/* Modified in revision 188609. The argument was changed from V2LLiC* to
 * V2LLi.
 * { */

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vbroadcastsi256(
    const long long int __attribute__((vector_size(16))) *);
#define __builtin_ia32_vbroadcastsi256(P1) \
    __coverity__builtin_ia32_vbroadcastsi256((P1))

/* } Modified in revision 188609. */

#endif /* } clang <= 3.3 */

/*************************************
 *** APPLE/LLVM divergent section ****
 *************************************/

// For Clang versions above LLVM Clang 3.4, we must treat Apple Clang derivatives
// of those versions separately, because Apple Clang uses hybridized versions of the
// LLVM Clang compiler.  Once Apple Clang and LLVM Clang have their own headers
// (bug 83552), each builtin definition should only appear once in each header.

// While most of the definitions below are contingent on Apple Clang versions,
// some of them are contingent on LLVM Clang versions if referring to older
// LLVM Clang versions that are used with those particular builtin signatures
// earlier in this header file.

#if __coverity_assume_xcode__


/*************************************
 ******** APPLE CLANG 6.0-6.2 ********
 *************************************/

// builtin signatures required for emulating Apple Clang 6.0
#if __cov_xcode_version_le(6, 0) /* { */

extern float __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_vbroadcastss(float const *__a);
#define __builtin_ia32_vbroadcastss(P1) \
    __coverity__builtin_ia32_vbroadcastss((P1))

extern float __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastss256(float const *__a);
#define __builtin_ia32_vbroadcastss256(P1) \
    __coverity__builtin_ia32_vbroadcastss256((P1))

extern double __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastsd256(double const *__a);
#define __builtin_ia32_vbroadcastsd256(P1) \
    __coverity__builtin_ia32_vbroadcastsd256((P1))
#endif /* } xcode <= 6.0 */


/* The following builtins were present in Apple Clang 5, but their signatures
   were changed in Apple Clang 6.3.  These signatures are required for emulating
   pre-6.3 Apple Clang. */
#if __cov_xcode_version_le(6, 2) /* { */

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_b(P1, P2) \
    __coverity__builtin_msa_sld_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_d(P1, P2) \
    __coverity__builtin_msa_sld_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_h(P1, P2) \
    __coverity__builtin_msa_sld_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_w(P1, P2) \
    __coverity__builtin_msa_sld_w((P1), (P2))

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_b(P1, P2) \
    __coverity__builtin_msa_sldi_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_d(P1, P2) \
    __coverity__builtin_msa_sldi_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_h(P1, P2) \
    __coverity__builtin_msa_sldi_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_w(P1, P2) \
    __coverity__builtin_msa_sldi_w((P1), (P2))

extern float __attribute__((__vector_size__(8)))
__coverity__builtin_neon_vcvt_f32_f64(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_neon_vcvt_f32_f64(P1, P2) \
    __coverity__builtin_neon_vcvt_f32_f64((P1), (P2))

#endif /* } xcode <= 6.2 */


/*************************************
 ****** APPLE CLANG 6.3 & 6.4 ********
 *************************************/

// No builtins present in Apple Clang 6.2 were removed in Apple Clang 6.3 or 6.4

/* These builtins had parameters added in Apple Clang 6.4.  The definitions
   that follow emulate the versions that existed in 6.3 and earlier. */
#if __cov_xcode_version_le(6, 3) /* { */

extern double __coverity__builtin_amdgpu_div_fmas(double __a, double __b, double __C);
#define __builtin_amdgpu_div_fmas(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmas((P1), (P2), (P3))

extern float __coverity__builtin_amdgpu_div_fmasf(float __a, float __b, float __C);
#define __builtin_amdgpu_div_fmasf(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmasf((P1), (P2), (P3))

extern double __coverity__nvvm_add_rm_d(double __a);
#define __nvvm_add_rm_d(P1) __coverity__nvvm_add_rm_d((P1))

extern float __coverity__nvvm_add_rm_f(float __a);
#define __nvvm_add_rm_f(P1) __coverity__nvvm_add_rm_f((P1))

extern float __coverity__nvvm_add_rm_ftz_f(float __a);
#define __nvvm_add_rm_ftz_f(P1) __coverity__nvvm_add_rm_ftz_f((P1))

extern double __coverity__nvvm_add_rn_d(double __a);
#define __nvvm_add_rn_d(P1) __coverity__nvvm_add_rn_d((P1))

extern float __coverity__nvvm_add_rn_f(float __a);
#define __nvvm_add_rn_f(P1) __coverity__nvvm_add_rn_f((P1))

extern float __coverity__nvvm_add_rn_ftz_f(float __a);
#define __nvvm_add_rn_ftz_f(P1) __coverity__nvvm_add_rn_ftz_f((P1))

extern double __coverity__nvvm_add_rp_d(double __a);
#define __nvvm_add_rp_d(P1) __coverity__nvvm_add_rp_d((P1))

extern float __coverity__nvvm_add_rp_f(float __a);
#define __nvvm_add_rp_f(P1) __coverity__nvvm_add_rp_f((P1))

extern float __coverity__nvvm_add_rp_ftz_f(float __a);
#define __nvvm_add_rp_ftz_f(P1) __coverity__nvvm_add_rp_ftz_f((P1))

extern double __coverity__nvvm_add_rz_d(double __a);
#define __nvvm_add_rz_d(P1) __coverity__nvvm_add_rz_d((P1))

extern float __coverity__nvvm_add_rz_f(float __a);
#define __nvvm_add_rz_f(P1) __coverity__nvvm_add_rz_f((P1))

extern float __coverity__nvvm_add_rz_ftz_f(float __a);
#define __nvvm_add_rz_ftz_f(P1) __coverity__nvvm_add_rz_ftz_f((P1))

extern int __coverity__nvvm_sad_i(int __a, int __b);
#define __nvvm_add_sad_i(P1, P2) __coverity__nvvm_sad_i((P1), (P2))

extern unsigned int __coverity__nvvm_sad_ui(unsigned int __a, unsigned int __b);
#define __nvvm_add_sad_ui(P1, P2) __coverity__nvvm_sad_ui((P1), (P2))

/* The following definitions all changed in the last parameter from int to
 * const-reducing char in LLVM Clang 3.6.  These are all prototypes with that
 * last int.  Note that the first three also changed from 3.0 to 3.1., so
 * we can only define these for between LLVM Clang 3.1 and 3.5 (inclusive). */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) /* { */
extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) } */

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_dppd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dppd(P1, P2, P3) \
    __coverity__builtin_ia32_dppd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_dpps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dpps(P1, P2, P3) \
    __coverity__builtin_ia32_dpps((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_dpps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_dpps256(P1, P2, P3) \
    __coverity__builtin_ia32_dpps256((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_insertps128(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_insertps128(P1, P2, P3) \
    __coverity__builtin_ia32_insertps128((P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_mpsadbw128(
    char __attribute__((vector_size(16))),
    char __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_mpsadbw128(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw128((P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity__builtin_ia32_mpsadbw256(
    char __attribute__((vector_size(32))),
    char __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_mpsadbw256(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* } xcode <= 6.3 */


/*************************************
 ********* APPLE CLANG 7.0 ***********
 *************************************/

/* The following builtins were present in Apple Clang 6.4, but removed
   in Apple Clang 7.0.  They're required to emulate pre-7.0 Apple Clang. */
#if __cov_xcode_version_lt(7, 0) /* { */


/* This changed in Apple Clang 5.1 but was removed in Apple Clang 7.0.
 * The pre-5.1 signature is defined further above, in common code that maps
 * the older definitions to pre-LLVM Clang 3.4.  This is the signature of the
 * intrinsic from Apple Clang 5.1 to 6.4. */
#if __cov_xcode_version_ge(5, 1) /* { */

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vbroadcastsi256(
    const long long int __attribute__((vector_size(16))));
#define __builtin_ia32_vbroadcastsi256(P1) \
    __coverity__builtin_ia32_vbroadcastsi256((P1))

#endif /* } xcode >= 5.1 */

/* The next eight also changed from Apple Clang 6.3 to 6.4, so we define
 * define these to emulate the 6.4 versions in Apple Clang version 7.0 */
#if __cov_xcode_version_ge(6, 4) /* { */

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* } xcode >= 6.4 */

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pslldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pslldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_psrldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_psrldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

/* These builtins had parameters changed in Apple Clang 7.0.  The definitions
   that follow emulate the pre-7.0 versions. */

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignd512_mask(
    int __attribute__((vector_size(64))),
    int __attribute__((vector_size(64))),
    unsigned char,
    int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignd512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignq512_mask(
    long long int __attribute__((vector_size(64))),
    long long int __attribute__((vector_size(64))),
    unsigned char,
    long long int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignq512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignq512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __coverity__ldrexd(long long int*);
#define __ldrexd(P1) __coverity__ldrexd(P1)

#endif /* } xcode < 7.0 */

/* The extract and insert builtins were included in Apple Clang 7.0,
   even though they weren't included in LLVM Clang 3.7. */
#if __cov_xcode_version_le(7,1) /* { */
extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_extract128i256(
    long long int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_extract128i256(P1, P2) \
    __coverity__builtin_ia32_extract128i256((P1), (P2))

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_insert128i256(
    long long int __attribute__((vector_size(32))),
    long long int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_insert128i256(P1, P2, P3) \
    __coverity__builtin_ia32_insert128i256((P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_pd256(
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_pd256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_pd256((P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_ps256(
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_ps256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_ps256((P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_si256(
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_si256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_si256((P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_pd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_pd256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_pd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_ps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_ps256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_ps256((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_si256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_si256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_si256((P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubpd512_mask(
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    unsigned char,
    int);
#define __builtin_ia32_vfmsubpd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubpd512_mask((P1), (P2), (P3), (P4), (P5))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubps512_mask(
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    unsigned short,
    int);
#define __builtin_ia32_vfmsubps512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubps512_mask((P1), (P2), (P3), (P4), (P5))

#endif /* } xcode <= 7.1 */

#else  // __coverity_assume_xcode__


// These are the LLVM Clang (non-Apple) definitions

/*************************************
 ************* CLANG 3.5 *************
 *************************************/

/* The following builtins were present in Clang 3.4, but removed in Clang 3.5 */
#if __cov_clang_version_le(3, 4) /* { */

extern float __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_vbroadcastss(float const *__a);
#define __builtin_ia32_vbroadcastss(P1) \
    __coverity__builtin_ia32_vbroadcastss((P1))

extern float __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastss256(float const *__a);
#define __builtin_ia32_vbroadcastss256(P1) \
    __coverity__builtin_ia32_vbroadcastss256((P1))

extern double __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastsd256(double const *__a);
#define __builtin_ia32_vbroadcastsd256(P1) \
    __coverity__builtin_ia32_vbroadcastsd256((P1))

/* The following builtins were present in Clang 3.4, but their signatures were
   changed in Clang 3.5.  These are the 3.4 signatures. */

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_b(P1, P2) \
    __coverity__builtin_msa_sld_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_d(P1, P2) \
    __coverity__builtin_msa_sld_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_h(P1, P2) \
    __coverity__builtin_msa_sld_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_w(P1, P2) \
    __coverity__builtin_msa_sld_w((P1), (P2))

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_b(P1, P2) \
    __coverity__builtin_msa_sldi_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_d(P1, P2) \
    __coverity__builtin_msa_sldi_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_h(P1, P2) \
    __coverity__builtin_msa_sldi_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_w(P1, P2) \
    __coverity__builtin_msa_sldi_w((P1), (P2))

extern float __attribute__((__vector_size__(8)))
__coverity__builtin_neon_vcvt_f32_f64(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_neon_vcvt_f32_f64(P1, P2) \
    __coverity__builtin_neon_vcvt_f32_f64((P1), (P2))

#endif /* } clang <= 3.4 */


/*************************************
 ************* CLANG 3.6 *************
 *************************************/

/* No builtins present in Clang 3.5 were removed in Clang 3.6 */
#if __cov_clang_version_le(3, 5) /* { */
/* These builtins had parameters added in Clang 3.6.  The definitions
   that follow emulate the 3.5 versions. */

extern double __coverity__builtin_amdgpu_div_fmas(double __a, double __b, double __C);
#define __builtin_amdgpu_div_fmas(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmas((P1), (P2), (P3))

extern float __coverity__builtin_amdgpu_div_fmasf(float __a, float __b, float __C);
#define __builtin_amdgpu_div_fmasf(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmasf((P1), (P2), (P3))

extern double __coverity__nvvm_add_rm_d(double __a);
#define __nvvm_add_rm_d(P1) __coverity__nvvm_add_rm_d((P1))

extern float __coverity__nvvm_add_rm_f(float __a);
#define __nvvm_add_rm_f(P1) __coverity__nvvm_add_rm_f((P1))

extern float __coverity__nvvm_add_rm_ftz_f(float __a);
#define __nvvm_add_rm_ftz_f(P1) __coverity__nvvm_add_rm_ftz_f((P1))

extern double __coverity__nvvm_add_rn_d(double __a);
#define __nvvm_add_rn_d(P1) __coverity__nvvm_add_rn_d((P1))

extern float __coverity__nvvm_add_rn_f(float __a);
#define __nvvm_add_rn_f(P1) __coverity__nvvm_add_rn_f((P1))

extern float __coverity__nvvm_add_rn_ftz_f(float __a);
#define __nvvm_add_rn_ftz_f(P1) __coverity__nvvm_add_rn_ftz_f((P1))

extern double __coverity__nvvm_add_rp_d(double __a);
#define __nvvm_add_rp_d(P1) __coverity__nvvm_add_rp_d((P1))

extern float __coverity__nvvm_add_rp_f(float __a);
#define __nvvm_add_rp_f(P1) __coverity__nvvm_add_rp_f((P1))

extern float __coverity__nvvm_add_rp_ftz_f(float __a);
#define __nvvm_add_rp_ftz_f(P1) __coverity__nvvm_add_rp_ftz_f((P1))

extern double __coverity__nvvm_add_rz_d(double __a);
#define __nvvm_add_rz_d(P1) __coverity__nvvm_add_rz_d((P1))

extern float __coverity__nvvm_add_rz_f(float __a);
#define __nvvm_add_rz_f(P1) __coverity__nvvm_add_rz_f((P1))

extern float __coverity__nvvm_add_rz_ftz_f(float __a);
#define __nvvm_add_rz_ftz_f(P1) __coverity__nvvm_add_rz_ftz_f((P1))

extern int __coverity__nvvm_sad_i(int __a, int __b);
#define __nvvm_add_sad_i(P1, P2) __coverity__nvvm_sad_i((P1), (P2))

extern unsigned int __coverity__nvvm_sad_ui(unsigned int __a, unsigned int __b);
#define __nvvm_add_sad_ui(P1, P2) __coverity__nvvm_sad_ui((P1), (P2))

/* The following definitions all changed in the last parameter from int to
 * const-reducing char in 3.6.  These are all prototypes with that last int.
 * Note that the first three also changed from 3.0 to 3.1., so we can
 * only define these for between 3.1 and 3.5 (inclusive). */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) /* { */
extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) } */

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_dppd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dppd(P1, P2, P3) \
    __coverity__builtin_ia32_dppd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_dpps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dpps(P1, P2, P3) \
    __coverity__builtin_ia32_dpps((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_dpps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_dpps256(P1, P2, P3) \
    __coverity__builtin_ia32_dpps256((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_insertps128(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_insertps128(P1, P2, P3) \
    __coverity__builtin_ia32_insertps128((P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_mpsadbw128(
    char __attribute__((vector_size(16))),
    char __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_mpsadbw128(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw128((P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity__builtin_ia32_mpsadbw256(
    char __attribute__((vector_size(32))),
    char __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_mpsadbw256(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* } clang <= 3.5 */

/*************************************
 ************* CLANG 3.7 *************
 *************************************/

#if __cov_clang_version_le(3, 6) /* { */

/* The following builtins were present in Clang 3.6, but removed in Clang 3.7 */

/* This changed in 3.4 but was removed in 3.7.  The pre-3.4 signature is defined above.
 * This is the signature of the unfortunate identity-crisis-stricken intrinsic from 3.4 to 3.6. */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 4) /* { */

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vbroadcastsi256(
    const long long int __attribute__((vector_size(16))));
#define __builtin_ia32_vbroadcastsi256(P1) \
    __coverity__builtin_ia32_vbroadcastsi256((P1))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 4) } */

/* Note that the next eight also changed from 3.5 to 3.6, so we can
 * only define these for 3.6. */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ == 6) /* { */

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ == 6) } */

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_extract128i256(
    long long int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_extract128i256(P1, P2) \
    __coverity__builtin_ia32_extract128i256((P1), (P2))

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_insert128i256(
    long long int __attribute__((vector_size(32))),
    long long int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_insert128i256(P1, P2, P3) \
    __coverity__builtin_ia32_insert128i256((P1), (P2), (P3))

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pslldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pslldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_psrldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_psrldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_pd256(
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_pd256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_pd256((P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_ps256(
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_ps256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_ps256((P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_si256(
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_si256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_si256((P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_pd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_pd256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_pd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_ps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_ps256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_ps256((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_si256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_si256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_si256((P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubpd512_mask(
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    unsigned char,
    int);
#define __builtin_ia32_vfmsubpd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubpd512_mask((P1), (P2), (P3), (P4), (P5))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubps512_mask(
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    unsigned short,
    int);
#define __builtin_ia32_vfmsubps512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubps512_mask((P1), (P2), (P3), (P4), (P5))

/* These builtins had parameters changed in Clang 3.7.  The definitions
   that follow emulate the 3.6 versions. */

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignd512_mask(
    int __attribute__((vector_size(64))),
    int __attribute__((vector_size(64))),
    unsigned char,
    int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignd512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignq512_mask(
    long long int __attribute__((vector_size(64))),
    long long int __attribute__((vector_size(64))),
    unsigned char,
    long long int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignq512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignq512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __coverity__ldrexd(long long int*);
#define __ldrexd(P1) __coverity__ldrexd(P1)

#endif /* } clang <= 3.6 */

#endif // __coverity_assume_xcode__

/*************************************
 ***** LLVM 3.7 & APPLE CLANG 7.0 ****
 *************************************/

/* These are a set of 55 prototypes that differ in LLVM 3.7 / Apple Clang 7.0 from their
   predecessor only by requiring an int parameter to reduce to a constant at compile time.
   We thus must define the non-constant-reducing prototypes for emulating earlier versions.
   Rather than quote these 55 prototypes twice, we just make the #if statement bigger.
   Note these were generated by the simple proto_generator.awk script. */

#if (!__coverity_assume_xcode__ && __cov_clang_version_le(3, 6)) || \
    __cov_xcode_version_lt(7, 0) /* { */

extern unsigned char
__coverity__builtin_ia32_cmppd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    const int __c,
    unsigned char __d,
    int __e);
#define __builtin_ia32_cmppd512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_cmppd512_mask((P0), (P1), (P2), (P3), (P4))

extern unsigned short
__coverity__builtin_ia32_cmpps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    const int __c,
    unsigned short __d,
    int __e);
#define __builtin_ia32_cmpps512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_cmpps512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtdq2ps512_mask(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtdq2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtdq2ps512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtpd2dq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvtpd2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtpd2dq512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtpd2ps512_mask(
    double __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvtpd2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtpd2ps512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtpd2udq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvtpd2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtpd2udq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtps2dq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtps2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtps2dq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtps2udq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtps2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtps2udq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvttpd2dq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvttpd2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttpd2dq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvttpd2udq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvttpd2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttpd2udq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvttps2dq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvttps2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttps2dq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvttps2udq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvttps2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttps2udq512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtudq2ps512_mask(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtudq2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtudq2ps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_gatherdiv16sf(
    float __attribute__((vector_size(32))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16sf(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv16sf((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_gatherdiv16si(
    int __attribute__((vector_size(32))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16si(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv16si((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_gatherdiv8df(
    double __attribute__((vector_size(64))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv8df((P0), (P1), (P2), (P3), (P4))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_gatherdiv8di(
    long long int __attribute__((vector_size(64))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfqpd(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfqps(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfqps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv16sf(
    float __attribute__((vector_size(64))) __a,
    const void *__b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16sf(P0, P1, P2, P3) \
    __coverity__builtin_ia32_gathersiv16sf((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv16si(
    int __attribute__((vector_size(64))) __a,
    const void *__b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16si(P0, P1, P2, P3) \
    __coverity__builtin_ia32_gathersiv16si((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv8df(
    double __attribute__((vector_size(64))) __a,
    const void *__b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gathersiv8df((P0), (P1), (P2), (P3), (P4))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv8di(
    long long int __attribute__((vector_size(64))) __a,
    const void *__b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gathersiv8di((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_maxpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxpd512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_maxpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_maxps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_maxps512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_maxps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_minpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minpd512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_minpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_minps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_minps512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_minps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_rcp28pd_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_rcp28pd_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rcp28pd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_rcp28ps_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_rcp28ps_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rcp28ps_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_rndscalepd_mask(
    double __attribute__((vector_size(64))) __a,
    const int __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rndscalepd_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_rndscalepd_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_rndscaleps_mask(
    float __attribute__((vector_size(64))) __a,
    const int __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_rndscaleps_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_rndscaleps_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_rsqrt28pd_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_rsqrt28pd_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rsqrt28pd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_rsqrt28ps_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_rsqrt28ps_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rsqrt28ps_mask((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_ia32_scatterdiv16sf(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16sf(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterdiv16si(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16si(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterdiv8df(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterdiv8di(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    long long int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfqpd(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfqps(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfqps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv16sf(
    void *__a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16sf(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv16si(
    void *__a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16si(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv8df(
    void *__a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv8di(
    void *__a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    long long int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv8di((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_sqrtpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_sqrtpd512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_sqrtpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_sqrtps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_sqrtps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_sqrtps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_vcvtph2ps512_mask(
    short __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_vcvtph2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_vcvtph2ps512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_vcvtps2ph512_mask(
    float __attribute__((vector_size(64))) __a,
    const int __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vcvtps2ph512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_vcvtps2ph512_mask((P0), (P1), (P2), (P3))

#endif /* } clang <= 3.6 || xcode < 7.0 */

/*************************************
 ************ Clang 3.8 **************
 *************************************/

#if (__cov_clang_version_lt(3, 8)) /* { */

/* These prototypes were removed in clang 3.8. { */

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastb128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastb128(P0) \
    __coverity___builtin_ia32_pbroadcastb128((P0))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastb256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastb256(P0) \
    __coverity___builtin_ia32_pbroadcastb256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastd128(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastd128(P0) \
    __coverity___builtin_ia32_pbroadcastd128((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastd256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastd256(P0) \
    __coverity___builtin_ia32_pbroadcastd256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastq128(
    long long __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastq128(P0) \
    __coverity___builtin_ia32_pbroadcastq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastq256(
    long long __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastq256(P0) \
    __coverity___builtin_ia32_pbroadcastq256((P0))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastw128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastw128(P0) \
    __coverity___builtin_ia32_pbroadcastw128((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastw256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastw256(P0) \
    __coverity___builtin_ia32_pbroadcastw256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbd128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbd128(P0) \
    __coverity___builtin_ia32_pmovsxbd128((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbq128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbq128(P0) \
    __coverity___builtin_ia32_pmovsxbq128((P0))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbw128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbw128(P0) \
    __coverity___builtin_ia32_pmovsxbw128((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxdq128(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxdq128(P0) \
    __coverity___builtin_ia32_pmovsxdq128((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwd128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwd128(P0) \
    __coverity___builtin_ia32_pmovsxwd128((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwq128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwq128(P0) \
    __coverity___builtin_ia32_pmovsxwq128((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14sd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14sd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14ss_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14ss_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28sd_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28sd_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28ss_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28ss_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14sd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14sd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14ss_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14ss_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28sd_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28sd_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28ss_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28ss_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastsd_pd256(
    double __attribute__((vector_size(16))) __a);
#define __builtin_ia32_vbroadcastsd_pd256(P0) \
    __coverity___builtin_ia32_vbroadcastsd_pd256((P0))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vbroadcastss_ps(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_vbroadcastss_ps(P0) \
    __coverity___builtin_ia32_vbroadcastss_ps((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastss_ps256(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_vbroadcastss_ps256(P0) \
    __coverity___builtin_ia32_vbroadcastss_ps256((P0))

extern signed char __attribute__((vector_size(8)))
__coverity___builtin_neon_vcvt_f16_v(
    signed char __attribute__((vector_size(16))) __a,
    int __b);
#define __builtin_neon_vcvt_f16_v(P0, P1) \
    __coverity___builtin_neon_vcvt_f16_v((P0), (P1))

/* } These builtins were modified in clang 3.8. { */

#ifdef __arm__
extern void
__coverity___builtin_arm_mcr(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_mcr(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_mcr((P0), (P1), (P2), (P3), (P4), (P5))

extern void
__coverity___builtin_arm_mcr2(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_mcr2(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_mcr2((P0), (P1), (P2), (P3), (P4), (P5))

extern void
__coverity___builtin_arm_mcrr(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_arm_mcrr2(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr2(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr2((P0), (P1), (P2), (P3), (P4))

extern unsigned int
__coverity___builtin_arm_mrc(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e);
#define __builtin_arm_mrc(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mrc((P0), (P1), (P2), (P3), (P4))

extern unsigned int
__coverity___builtin_arm_mrc2(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e);
#define __builtin_arm_mrc2(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mrc2((P0), (P1), (P2), (P3), (P4))

#endif /* __arm__ */

/*
 * These builtins were modified between 3.6 and 3.7 as well as between
 * 3.7 and 3.8.
 */
#if __cov_clang_version_ge(3, 7) /* { */

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_alignd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    char __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_alignd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_alignd512_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_alignq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    char __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_alignq512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_alignq512_mask((P0), (P1), (P2), (P3), (P4))

#endif /* } clang >= 3.7 */

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_extractf32x4_mask(
    float __attribute__((vector_size(64))) __a,
    const char __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_extractf32x4_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_extractf32x4_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_extractf64x4_mask(
    double __attribute__((vector_size(64))) __a,
    const char __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_extractf64x4_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_extractf64x4_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_d(
    int __attribute__((vector_size(16))) __a,
    const int __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_d(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_d((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_d256(
    int __attribute__((vector_size(32))) __a,
    const int __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_d256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_d256((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_pd(
    double __attribute__((vector_size(16))) __a,
    const double __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_pd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_pd((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_pd256(
    double __attribute__((vector_size(32))) __a,
    const double __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_pd256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_pd256((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_ps(
    float __attribute__((vector_size(16))) __a,
    const float __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_ps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_ps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_ps256(
    float __attribute__((vector_size(32))) __a,
    const float __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_ps256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_ps256((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_q(
    long long __attribute__((vector_size(16))) __a,
    const long long __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_q(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_q((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_q256(
    long long __attribute__((vector_size(32))) __a,
    const long long __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_q256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_q256((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_d(
    int __attribute__((vector_size(16))) __a,
    const int __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_d(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_d((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_d256(
    int __attribute__((vector_size(16))) __a,
    const int __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_d256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_d256((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_pd(
    double __attribute__((vector_size(16))) __a,
    const double __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_pd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_pd((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherq_pd256(
    double __attribute__((vector_size(32))) __a,
    const double __attribute__((vector_size(32)))*__b,
    long long __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherq_pd256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_pd256((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_ps(
    float __attribute__((vector_size(16))) __a,
    const float __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_ps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_ps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_ps256(
    float __attribute__((vector_size(16))) __a,
    const float __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_ps256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_ps256((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_q(
    long long __attribute__((vector_size(16))) __a,
    const long long __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_q(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_q((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherq_q256(
    long long __attribute__((vector_size(32))) __a,
    const long long __attribute__((vector_size(32)))*__b,
    long long __attribute__((vector_size(32))) __c,
    long long __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherq_q256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_q256((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_maskloadpd(
    const double __attribute__((vector_size(16)))*__a,
    double __attribute__((vector_size(16))) __b);
#define __builtin_ia32_maskloadpd(P0, P1) \
    __coverity___builtin_ia32_maskloadpd((P0), (P1))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_maskloadpd256(
    const double __attribute__((vector_size(32)))*__a,
    double __attribute__((vector_size(32))) __b);
#define __builtin_ia32_maskloadpd256(P0, P1) \
    __coverity___builtin_ia32_maskloadpd256((P0), (P1))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_maskloadps(
    const float __attribute__((vector_size(16)))*__a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_maskloadps(P0, P1) \
    __coverity___builtin_ia32_maskloadps((P0), (P1))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_maskloadps256(
    const float __attribute__((vector_size(32)))*__a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_maskloadps256(P0, P1) \
    __coverity___builtin_ia32_maskloadps256((P0), (P1))

extern void
__coverity___builtin_ia32_maskstorepd(
    double __attribute__((vector_size(16)))*__a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c);
#define __builtin_ia32_maskstorepd(P0, P1, P2) \
    __coverity___builtin_ia32_maskstorepd((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_maskstorepd256(
    double __attribute__((vector_size(32)))*__a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c);
#define __builtin_ia32_maskstorepd256(P0, P1, P2) \
    __coverity___builtin_ia32_maskstorepd256((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_maskstoreps(
    float __attribute__((vector_size(16)))*__a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c);
#define __builtin_ia32_maskstoreps(P0, P1, P2) \
    __coverity___builtin_ia32_maskstoreps((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_maskstoreps256(
    float __attribute__((vector_size(32)))*__a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c);
#define __builtin_ia32_maskstoreps256(P0, P1, P2) \
    __coverity___builtin_ia32_maskstoreps256((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_movntdqa(
    long long __attribute__((vector_size(16)))*__a);
#define __builtin_ia32_movntdqa(P0) \
    __coverity___builtin_ia32_movntdqa((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_movntdqa256(
    long long __attribute__((vector_size(32)))*__a);
#define __builtin_ia32_movntdqa256(P0) \
    __coverity___builtin_ia32_movntdqa256((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarsf256(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_permvarsf256(P0, P1) \
    __coverity___builtin_ia32_permvarsf256((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundpd(
    double __attribute__((vector_size(16))) __a,
    int __b);
#define __builtin_ia32_roundpd(P0, P1) \
    __coverity___builtin_ia32_roundpd((P0), (P1))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundps(
    float __attribute__((vector_size(16))) __a,
    int __b);
#define __builtin_ia32_roundps(P0, P1) \
    __coverity___builtin_ia32_roundps((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundsd(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    int __c);
#define __builtin_ia32_roundsd(P0, P1, P2) \
    __coverity___builtin_ia32_roundsd((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundss(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    int __c);
#define __builtin_ia32_roundss(P0, P1, P2) \
    __coverity___builtin_ia32_roundss((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_neon_vcvt_f32_f16(
    signed char __attribute__((vector_size(8))) __a,
    int __b);
#define __builtin_neon_vcvt_f32_f16(P0, P1) \
    __coverity___builtin_neon_vcvt_f32_f16((P0), (P1))

extern long
__coverity___builtin_ptx_read_clock64();
#define __builtin_ptx_read_clock64() \
    __coverity___builtin_ptx_read_clock64()

extern int
__coverity___builtin_signbit(
    double __a);
#define __builtin_signbit(P0) \
    __coverity___builtin_signbit((P0))

/* } */
#endif /* } clang < 3.8 */

/*************************************
 *************** NEON ****************
 *************************************/

/*
 * Loosen up the error checking on some of the arm neon intrinsics, native clang
 * has restrictions on the possible values of the constant integral parameter
 * to the neon intrinsics but some clang versions have headers that seem to
 * contradict the list of allowed values.
 */
#if defined(__ARM_NEON__) || defined(__AARCH_FEATURE_ADVSIMD) /* { */
/* Define primitive types used in the neon builtin API */
typedef signed char             __cov_int8_t;
typedef unsigned char           __cov_uint8_t;
typedef short int               __cov_int16_t;
typedef unsigned short int      __cov_uint16_t;
typedef float __cov_float32_t;

#ifdef __aarch64__
typedef __fp16 __cov_float16_t;
typedef double __cov_float64_t;
#else
typedef __cov_uint16_t __cov_float16_t;
#endif

#ifdef __aarch64__
typedef __cov_uint8_t __cov_poly8_t;
typedef __cov_uint16_t __cov_poly16_t;
#else
typedef __cov_int8_t __cov_poly8_t;
typedef __cov_int16_t __cov_poly16_t;
#endif

/* Define neon intrinsic vector types built from primitive types */
typedef __attribute__((neon_vector_type(8)))  __cov_int8_t    __cov_neon_int8x8_t;
typedef __attribute__((neon_vector_type(16))) __cov_int8_t    __cov_neon_int8x16_t;
typedef __attribute__((neon_vector_type(4)))  __cov_float16_t __cov_neon_float16x4_t;
typedef __attribute__((neon_vector_type(2)))  __cov_float32_t __cov_neon_float32x2_t;
typedef __attribute__((neon_vector_type(4)))  __cov_float32_t __cov_neon_float32x4_t;

__cov_neon_float32x2_t
__coverity__builtin_neon_vabd_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vabd_v(P1, P2, P3) \
    __coverity__builtin_neon_vabd_v((P1), (P2), (P3));


__cov_neon_float32x4_t
__coverity__builtin_neon_vabdq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vabdq_v(P1, P2, P3) \
    __coverity__builtin_neon_vabdq_v((P1), (P2), (P3));

__cov_neon_int8x8_t
__coverity__builtin_neon_vabs_v(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vabs_v(P1, P2) \
    __coverity__builtin_neon_vabs_v((P1), (P2));

__cov_neon_int8x16_t
__coverity__builtin_neon_vabsq_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vabsq_v(P1, P2) \
    __coverity__builtin_neon_vabsq_v((P1), (P2));


__cov_neon_int8x8_t
__coverity__builtin_neon_vbsl_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vbsl_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vbsl_v((P1), (P2), (P3), (P4));

__cov_neon_float32x4_t
__coverity__builtin_neon_vbslq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vbslq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vbslq_v((P1), (P2), (P3), (P4));

__cov_neon_float16x4_t
__coverity__builtin_neon_vcvt_f16_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vcvt_f16_v(P1, P2) \
    __coverity__builtin_neon_vcvt_f16_v((P1), (P2));

__cov_neon_float32x4_t
__coverity__builtin_neon_vcvt_f32_f16(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vcvt_f32_f16(P1, P2) \
    __coverity__builtin_neon_vcvt_f32_f16((P1), (P2));

__cov_neon_float32x2_t
__coverity__builtin_neon_vfma_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vfma_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vfma_v((P1), (P2), (P3), (P4))

__cov_neon_float32x4_t
__coverity__builtin_neon_vfmaq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vfmaq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vfmaq_v((P1), (P2), (P3), (P4))

__cov_neon_float32x2_t
__coverity__builtin_neon_vmax_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vmax_v(P1, P2, P3) \
    __coverity__builtin_neon_vmax_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vmaxq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vmaxq_v(P1, P2, P3) \
    __coverity__builtin_neon_vmaxq_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vmin_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vmin_v(P1, P2, P3) \
    __coverity__builtin_neon_vmin_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vminq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vminq_v(P1, P2, P3) \
    __coverity__builtin_neon_vminq_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vpadd_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vpadd_v(P1, P2, P3) \
    __coverity__builtin_neon_vpadd_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vpmax_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vpmax_v(P1, P2, P3) \
    __coverity__builtin_neon_vpmax_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vpmin_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vpmin_v(P1, P2, P3) \
    __coverity__builtin_neon_vpmin_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrecpe_v(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrecpe_v(P1, P2) \
    __coverity__builtin_neon_vrecpe_v((P1), (P2))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrecpeq_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrecpeq_v(P1, P2) \
    __coverity__builtin_neon_vrecpeq_v((P1), (P2))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrecps_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrecps_v(P1, P2, P3) \
    __coverity__builtin_neon_vrecps_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrecpsq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrecpsq_v(P1, P2, P3) \
    __coverity__builtin_neon_vrecpsq_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrsqrte_v(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrsqrte_v(P1, P2) \
    __coverity__builtin_neon_vrsqrte_v((P1), (P2))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrsqrteq_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrsqrteq_v(P1, P2) \
    __coverity__builtin_neon_vrsqrteq_v((P1), (P2))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrsqrts_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrsqrts_v(P1, P2, P3) \
    __coverity__builtin_neon_vrsqrts_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrsqrtsq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrsqrtsq_v(P1, P2, P3) \
    __coverity__builtin_neon_vrsqrtsq_v((P1), (P2), (P3))

void
__coverity__builtin_neon_vtrn_v(
    void *,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vtrn_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vtrn_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vtrnq_v(
    void *, __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vtrnq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vtrnq_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vuzp_v(
    void *,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vuzp_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vuzp_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vuzpq_v(
    void *,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vuzpq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vuzpq_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vzip_v(void *, __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vzip_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vzip_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vzipq_v(
    void *,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vzipq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vzipq_v((P1), (P2), (P3), (P4))

#endif /* } defined(__ARM_NEON__) || defined(__AARCH_FEATURE_ADVSIMD) */

/*************************************
 ************ Clang 3.9 **************
 *************************************/

#if (__cov_clang_version_lt(3, 9)) /* { */
/* These intrinsics were removed in clang 3.9. { */
/* Some but not all of these intrinsics were removed in Xcode 8.0. { */

/* clang < 3.9 || Xcode < 8.0 */
#if !(__cov_xcode_version_ge(8, 0)) /* { */
extern double
__coverity___builtin_HEXAGON_F2_dfadd(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfadd(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfadd((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dffixupd(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dffixupd(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dffixupd((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dffixupn(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dffixupn(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dffixupn((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dffixupr(
    double __a);
#define __builtin_HEXAGON_F2_dffixupr(P0) \
    __coverity___builtin_HEXAGON_F2_dffixupr((P0))

extern double
__coverity___builtin_HEXAGON_F2_dffma(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffma(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffma((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dffma_lib(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffma_lib(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffma_lib((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dffma_sc(
    double __a,
    double __b,
    double __c,
    int __d);
#define __builtin_HEXAGON_F2_dffma_sc(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_F2_dffma_sc((P0), (P1), (P2), (P3))

extern double
__coverity___builtin_HEXAGON_F2_dffms(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffms(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffms((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dffms_lib(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffms_lib(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffms_lib((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dfmax(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfmax(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfmax((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dfmin(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfmin(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfmin((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dfmpy(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfmpy(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfmpy((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dfsub(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfsub(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfsub((P0), (P1))

extern __cov_compat_bool
__coverity___builtin_amdgpu_class(
    double __a,
    int __b);
#define __builtin_amdgpu_class(P0, P1) \
    __coverity___builtin_amdgpu_class((P0), (P1))

extern __cov_compat_bool
__coverity___builtin_amdgpu_classf(
    float __a,
    int __b);
#define __builtin_amdgpu_classf(P0, P1) \
    __coverity___builtin_amdgpu_classf((P0), (P1))

extern double
__coverity___builtin_amdgpu_div_fixup(
    double __a,
    double __b,
    double __c);
#define __builtin_amdgpu_div_fixup(P0, P1, P2) \
    __coverity___builtin_amdgpu_div_fixup((P0), (P1), (P2))

extern float
__coverity___builtin_amdgpu_div_fixupf(
    float __a,
    float __b,
    float __c);
#define __builtin_amdgpu_div_fixupf(P0, P1, P2) \
    __coverity___builtin_amdgpu_div_fixupf((P0), (P1), (P2))

extern double
__coverity___builtin_amdgpu_div_scale(
    double __a,
    double __b,
    __cov_compat_bool __c,
    __cov_compat_bool* __d);
#define __builtin_amdgpu_div_scale(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_scale((P0), (P1), (P2), (P3))

extern float
__coverity___builtin_amdgpu_div_scalef(
    float __a,
    float __b,
    __cov_compat_bool __c,
    __cov_compat_bool* __d);
#define __builtin_amdgpu_div_scalef(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_scalef((P0), (P1), (P2), (P3))

extern double
__coverity___builtin_amdgpu_ldexp(
    double __a,
    int __b);
#define __builtin_amdgpu_ldexp(P0, P1) \
    __coverity___builtin_amdgpu_ldexp((P0), (P1))

extern float
__coverity___builtin_amdgpu_ldexpf(
    float __a,
    int __b);
#define __builtin_amdgpu_ldexpf(P0, P1) \
    __coverity___builtin_amdgpu_ldexpf((P0), (P1))

extern double
__coverity___builtin_amdgpu_rcp(
    double __a);
#define __builtin_amdgpu_rcp(P0) \
    __coverity___builtin_amdgpu_rcp((P0))

extern float
__coverity___builtin_amdgpu_rcpf(
    float __a);
#define __builtin_amdgpu_rcpf(P0) \
    __coverity___builtin_amdgpu_rcpf((P0))

extern double
__coverity___builtin_amdgpu_rsq(
    double __a);
#define __builtin_amdgpu_rsq(P0) \
    __coverity___builtin_amdgpu_rsq((P0))

extern double
__coverity___builtin_amdgpu_rsq_clamped(
    double __a);
#define __builtin_amdgpu_rsq_clamped(P0) \
    __coverity___builtin_amdgpu_rsq_clamped((P0))

extern float
__coverity___builtin_amdgpu_rsq_clampedf(
    float __a);
#define __builtin_amdgpu_rsq_clampedf(P0) \
    __coverity___builtin_amdgpu_rsq_clampedf((P0))

extern float
__coverity___builtin_amdgpu_rsqf(
    float __a);
#define __builtin_amdgpu_rsqf(P0) \
    __coverity___builtin_amdgpu_rsqf((P0))

extern double
__coverity___builtin_amdgpu_trig_preop(
    double __a,
    int __b);
#define __builtin_amdgpu_trig_preop(P0, P1) \
    __coverity___builtin_amdgpu_trig_preop((P0), (P1))

extern float
__coverity___builtin_amdgpu_trig_preopf(
    float __a,
    int __b);
#define __builtin_amdgpu_trig_preopf(P0, P1) \
    __coverity___builtin_amdgpu_trig_preopf((P0), (P1))

#endif /* } clang < 3.9 || Xcode < 8.0 */

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_addsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_addsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_addss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_addss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addss_round((P0), (P1), (P2), (P3), (P4))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmb_128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmb_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmb_128_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmb_256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    unsigned int __c);
#define __builtin_ia32_blendmb_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmb_256_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmb_512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    unsigned long long __c);
#define __builtin_ia32_blendmb_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmb_512_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmd_128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmd_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmd_128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmd_256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmd_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmd_256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmd_512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmd_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmd_512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmpd_128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmpd_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmpd_128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmpd_256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmpd_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmpd_256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmpd_512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmpd_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmpd_512_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmps_128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmps_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmps_128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmps_256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmps_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmps_256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmps_512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmps_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmps_512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmq_128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmq_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmq_128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmq_256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmq_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmq_256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmq_512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmq_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmq_512_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmw_128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmw_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmw_128_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmw_256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmw_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmw_256_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmw_512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    unsigned int __c);
#define __builtin_ia32_blendmw_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmw_512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2pd(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtdq2pd(P0) \
    __coverity___builtin_ia32_cvtdq2pd((P0))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2pd256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtdq2pd256(P0) \
    __coverity___builtin_ia32_cvtdq2pd256((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtps2pd(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtps2pd(P0) \
    __coverity___builtin_ia32_cvtps2pd((P0))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtps2pd256(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtps2pd256(P0) \
    __coverity___builtin_ia32_cvtps2pd256((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_divsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_divsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_divss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_divss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divss_round((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxss_round((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_minsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_minss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minss_round((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_movntdq(
    long long __attribute__((vector_size(16)))* __a,
    long long __attribute__((vector_size(16))) __b);
#define __builtin_ia32_movntdq(P0, P1) \
    __coverity___builtin_ia32_movntdq((P0), (P1))

extern void
__coverity___builtin_ia32_movntdq256(
    long long __attribute__((vector_size(32)))* __a,
    long long __attribute__((vector_size(32))) __b);
#define __builtin_ia32_movntdq256(P0, P1) \
    __coverity___builtin_ia32_movntdq256((P0), (P1))

extern void
__coverity___builtin_ia32_movntpd(
    double* __a,
    double __attribute__((vector_size(16))) __b);
#define __builtin_ia32_movntpd(P0, P1) \
    __coverity___builtin_ia32_movntpd((P0), (P1))

extern void
__coverity___builtin_ia32_movntpd256(
    double* __a,
    double __attribute__((vector_size(32))) __b);
#define __builtin_ia32_movntpd256(P0, P1) \
    __coverity___builtin_ia32_movntpd256((P0), (P1))

extern void
__coverity___builtin_ia32_movntps(
    float* __a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_movntps(P0, P1) \
    __coverity___builtin_ia32_movntps((P0), (P1))

extern void
__coverity___builtin_ia32_movntps256(
    float* __a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_movntps256(P0, P1) \
    __coverity___builtin_ia32_movntps256((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_mulsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_mulss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulss_round((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pandd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandnd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandnd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandnd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pandnd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandnq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandnq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandnq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pandq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbd256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbd256(P0) \
    __coverity___builtin_ia32_pmovsxbd256((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbq256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbq256(P0) \
    __coverity___builtin_ia32_pmovsxbq256((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbw256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbw256(P0) \
    __coverity___builtin_ia32_pmovsxbw256((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxdq256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxdq256(P0) \
    __coverity___builtin_ia32_pmovsxdq256((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwd256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwd256(P0) \
    __coverity___builtin_ia32_pmovsxwd256((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwq256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwq256(P0) \
    __coverity___builtin_ia32_pmovsxwq256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbd128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbd128(P0) \
    __coverity___builtin_ia32_pmovzxbd128((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbd256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbd256(P0) \
    __coverity___builtin_ia32_pmovzxbd256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbq128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbq128(P0) \
    __coverity___builtin_ia32_pmovzxbq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbq256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbq256(P0) \
    __coverity___builtin_ia32_pmovzxbq256((P0))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbw128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbw128(P0) \
    __coverity___builtin_ia32_pmovzxbw128((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbw256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbw256(P0) \
    __coverity___builtin_ia32_pmovzxbw256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxdq128(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxdq128(P0) \
    __coverity___builtin_ia32_pmovzxdq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxdq256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxdq256(P0) \
    __coverity___builtin_ia32_pmovzxdq256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwd128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwd128(P0) \
    __coverity___builtin_ia32_pmovzxwd128((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwd256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwd256(P0) \
    __coverity___builtin_ia32_pmovzxwd256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwq128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwq128(P0) \
    __coverity___builtin_ia32_pmovzxwq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwq256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwq256(P0) \
    __coverity___builtin_ia32_pmovzxwq256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulld128(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b);
#define __builtin_ia32_pmulld128(P0, P1) \
    __coverity___builtin_ia32_pmulld128((P0), (P1))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pord128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pord128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pord128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pord256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pord256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pord256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pord512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pord512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pord512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_porq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_porq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_porq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_porq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_porq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_porq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_porq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_porq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_porq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pslldqi256(
    long long __attribute__((vector_size(32))) __a,
    const int __b);
#define __builtin_ia32_pslldqi256(P0, P1) \
    __coverity___builtin_ia32_pslldqi256((P0), (P1))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrldqi256(
    long long __attribute__((vector_size(32))) __a,
    const int __b);
#define __builtin_ia32_psrldqi256(P0, P1) \
    __coverity___builtin_ia32_psrldqi256((P0), (P1))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpckhbw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_punpckhbw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhbw128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpckhbw256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_punpckhbw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhbw256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpckhbw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_punpckhbw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhbw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpckhwd128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_punpckhwd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhwd128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpckhwd256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_punpckhwd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhwd256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpckhwd512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_punpckhwd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhwd512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpcklbw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_punpcklbw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklbw128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpcklbw256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_punpcklbw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklbw256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpcklbw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_punpcklbw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklbw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpcklwd128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_punpcklwd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklwd128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpcklwd256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_punpcklwd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklwd256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpcklwd512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_punpcklwd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklwd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pxord128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pxord128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxord128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pxord256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pxord256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxord256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pxord512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pxord512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxord512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pxorq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pxorq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxorq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pxorq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pxorq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxorq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pxorq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pxorq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxorq512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14sd(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14sd(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14sd((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14ss(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14ss(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14ss((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28sd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28sd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28sd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28ss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28ss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28ss_round((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14sd(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14sd(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14sd((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14ss(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14ss(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14ss((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28sd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28sd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28sd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28ss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28ss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28ss_round((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_storedqu(
    char* __a,
    char __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storedqu(P0, P1) \
    __coverity___builtin_ia32_storedqu((P0), (P1))

extern void
__coverity___builtin_ia32_storedqu256(
    char* __a,
    char __attribute__((vector_size(32))) __b);
#define __builtin_ia32_storedqu256(P0, P1) \
    __coverity___builtin_ia32_storedqu256((P0), (P1))

extern void
__coverity___builtin_ia32_storeupd(
    double* __a,
    double __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storeupd(P0, P1) \
    __coverity___builtin_ia32_storeupd((P0), (P1))

extern void
__coverity___builtin_ia32_storeupd256(
    double* __a,
    double __attribute__((vector_size(32))) __b);
#define __builtin_ia32_storeupd256(P0, P1) \
    __coverity___builtin_ia32_storeupd256((P0), (P1))

extern void
__coverity___builtin_ia32_storeups(
    float* __a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storeups(P0, P1) \
    __coverity___builtin_ia32_storeups((P0), (P1))

extern void
__coverity___builtin_ia32_storeups256(
    float* __a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_storeups256(P0, P1) \
    __coverity___builtin_ia32_storeups256((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_subsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_subsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_subss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_subss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subss_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vcvtph2ps512(
    short __attribute__((vector_size(32))) __a);
#define __builtin_ia32_vcvtph2ps512(P0) \
    __coverity___builtin_ia32_vcvtph2ps512((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vcvtps2ph512(
    float __attribute__((vector_size(64))) __a,
    const int __b);
#define __builtin_ia32_vcvtps2ph512(P0, P1) \
    __coverity___builtin_ia32_vcvtps2ph512((P0), (P1))

/* clang < 3.9 || Xcode < 8.0 */
#if !(__cov_xcode_version_ge(8, 0)) /* { */
extern signed char __attribute__((vector_size(8)))
__coverity___builtin_neon_vfms_v(
    signed char __attribute__((vector_size(8))) __a,
    signed char __attribute__((vector_size(8))) __b,
    signed char __attribute__((vector_size(8))) __c,
    int __d);
#define __builtin_neon_vfms_v(P0, P1, P2, P3) \
    __coverity___builtin_neon_vfms_v((P0), (P1), (P2), (P3))

extern signed char __attribute__((vector_size(16)))
__coverity___builtin_neon_vfmsq_v(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b,
    signed char __attribute__((vector_size(16))) __c,
    int __d);
#define __builtin_neon_vfmsq_v(P0, P1, P2, P3) \
    __coverity___builtin_neon_vfmsq_v((P0), (P1), (P2), (P3))

extern void
__coverity___builtin_ptx_bar_sync(
    int __a);
#define __builtin_ptx_bar_sync(P0) \
    __coverity___builtin_ptx_bar_sync((P0))

extern int
__coverity___builtin_ptx_read_clock();
#define __builtin_ptx_read_clock() \
    __coverity___builtin_ptx_read_clock()

extern int
__coverity___builtin_ptx_read_ctaid_w();
#define __builtin_ptx_read_ctaid_w() \
    __coverity___builtin_ptx_read_ctaid_w()

extern int
__coverity___builtin_ptx_read_ctaid_x();
#define __builtin_ptx_read_ctaid_x() \
    __coverity___builtin_ptx_read_ctaid_x()

extern int
__coverity___builtin_ptx_read_ctaid_y();
#define __builtin_ptx_read_ctaid_y() \
    __coverity___builtin_ptx_read_ctaid_y()

extern int
__coverity___builtin_ptx_read_ctaid_z();
#define __builtin_ptx_read_ctaid_z() \
    __coverity___builtin_ptx_read_ctaid_z()

extern int
__coverity___builtin_ptx_read_gridid();
#define __builtin_ptx_read_gridid() \
    __coverity___builtin_ptx_read_gridid()

extern int
__coverity___builtin_ptx_read_laneid();
#define __builtin_ptx_read_laneid() \
    __coverity___builtin_ptx_read_laneid()

extern int
__coverity___builtin_ptx_read_lanemask_eq();
#define __builtin_ptx_read_lanemask_eq() \
    __coverity___builtin_ptx_read_lanemask_eq()

extern int
__coverity___builtin_ptx_read_lanemask_ge();
#define __builtin_ptx_read_lanemask_ge() \
    __coverity___builtin_ptx_read_lanemask_ge()

extern int
__coverity___builtin_ptx_read_lanemask_gt();
#define __builtin_ptx_read_lanemask_gt() \
    __coverity___builtin_ptx_read_lanemask_gt()

extern int
__coverity___builtin_ptx_read_lanemask_le();
#define __builtin_ptx_read_lanemask_le() \
    __coverity___builtin_ptx_read_lanemask_le()

extern int
__coverity___builtin_ptx_read_lanemask_lt();
#define __builtin_ptx_read_lanemask_lt() \
    __coverity___builtin_ptx_read_lanemask_lt()

extern int
__coverity___builtin_ptx_read_nctaid_w();
#define __builtin_ptx_read_nctaid_w() \
    __coverity___builtin_ptx_read_nctaid_w()

extern int
__coverity___builtin_ptx_read_nctaid_x();
#define __builtin_ptx_read_nctaid_x() \
    __coverity___builtin_ptx_read_nctaid_x()

extern int
__coverity___builtin_ptx_read_nctaid_y();
#define __builtin_ptx_read_nctaid_y() \
    __coverity___builtin_ptx_read_nctaid_y()

extern int
__coverity___builtin_ptx_read_nctaid_z();
#define __builtin_ptx_read_nctaid_z() \
    __coverity___builtin_ptx_read_nctaid_z()

extern int
__coverity___builtin_ptx_read_nsmid();
#define __builtin_ptx_read_nsmid() \
    __coverity___builtin_ptx_read_nsmid()

extern int
__coverity___builtin_ptx_read_ntid_w();
#define __builtin_ptx_read_ntid_w() \
    __coverity___builtin_ptx_read_ntid_w()

extern int
__coverity___builtin_ptx_read_ntid_x();
#define __builtin_ptx_read_ntid_x() \
    __coverity___builtin_ptx_read_ntid_x()

extern int
__coverity___builtin_ptx_read_ntid_y();
#define __builtin_ptx_read_ntid_y() \
    __coverity___builtin_ptx_read_ntid_y()

extern int
__coverity___builtin_ptx_read_ntid_z();
#define __builtin_ptx_read_ntid_z() \
    __coverity___builtin_ptx_read_ntid_z()

extern int
__coverity___builtin_ptx_read_nwarpid();
#define __builtin_ptx_read_nwarpid() \
    __coverity___builtin_ptx_read_nwarpid()

extern int
__coverity___builtin_ptx_read_pm0();
#define __builtin_ptx_read_pm0() \
    __coverity___builtin_ptx_read_pm0()

extern int
__coverity___builtin_ptx_read_pm1();
#define __builtin_ptx_read_pm1() \
    __coverity___builtin_ptx_read_pm1()

extern int
__coverity___builtin_ptx_read_pm2();
#define __builtin_ptx_read_pm2() \
    __coverity___builtin_ptx_read_pm2()

extern int
__coverity___builtin_ptx_read_pm3();
#define __builtin_ptx_read_pm3() \
    __coverity___builtin_ptx_read_pm3()

extern int
__coverity___builtin_ptx_read_smid();
#define __builtin_ptx_read_smid() \
    __coverity___builtin_ptx_read_smid()

extern int
__coverity___builtin_ptx_read_tid_w();
#define __builtin_ptx_read_tid_w() \
    __coverity___builtin_ptx_read_tid_w()

extern int
__coverity___builtin_ptx_read_tid_x();
#define __builtin_ptx_read_tid_x() \
    __coverity___builtin_ptx_read_tid_x()

extern int
__coverity___builtin_ptx_read_tid_y();
#define __builtin_ptx_read_tid_y() \
    __coverity___builtin_ptx_read_tid_y()

extern int
__coverity___builtin_ptx_read_tid_z();
#define __builtin_ptx_read_tid_z() \
    __coverity___builtin_ptx_read_tid_z()

extern int
__coverity___builtin_ptx_read_warpid();
#define __builtin_ptx_read_warpid() \
    __coverity___builtin_ptx_read_warpid()

extern __cov_compat_size_t
__coverity___builtin_wasm_memory_size();
#define __builtin_wasm_memory_size() \
    __coverity___builtin_wasm_memory_size()

extern void
__coverity___nvvm_bar0();
#define __nvvm_bar0() \
    __coverity___nvvm_bar0()

/* } These prototypes were changed by clang 3.9. { */

extern void
__coverity___builtin_arm_cdp(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_cdp(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_cdp((P0), (P1), (P2), (P3), (P4), (P5))

extern void
__coverity___builtin_arm_cdp2(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_cdp2(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_cdp2((P0), (P1), (P2), (P3), (P4), (P5))

extern long long*
__coverity___builtin_circ_ldd(
    long long* __a,
    long long* __b,
    int __c,
    int __d);
#define __builtin_circ_ldd(P0, P1, P2, P3) \
    __coverity___builtin_circ_ldd((P0), (P1), (P2), (P3))

#endif /* } clang < 3.9 || Xcode < 8.0 */

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadapd512_mask(
    const void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loadapd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadapd512_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadaps512_mask(
    const void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loadaps512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadaps512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_loaddqudi512_mask(
    const void* __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loaddqudi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loaddqudi512_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_loaddqusi512_mask(
    const void* __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loaddqusi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loaddqusi512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadupd512_mask(
    const void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loadupd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadupd512_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadups512_mask(
    const void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loadups512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadups512_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_palignr128(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    const char __c);
#define __builtin_ia32_palignr128(P0, P1, P2) \
    __coverity___builtin_ia32_palignr128((P0), (P1), (P2))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_palignr256(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_palignr256(P0, P1, P2) \
    __coverity___builtin_ia32_palignr256((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeapd512_mask(
    void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storeapd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeapd512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeaps512_mask(
    void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storeaps512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeaps512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storedqudi512_mask(
    void* __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storedqudi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storedqudi512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storedqusi512_mask(
    void* __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storedqusi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storedqusi512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeupd512_mask(
    void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storeupd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeupd512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeups512_mask(
    void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storeups512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeups512_mask((P0), (P1), (P2))

/* } These prototypes were modified in clang 3.6 and removed in clang 3.9. { */
#if (!__coverity_assume_xcode__ && __cov_clang_version_gt(3, 5)) || \
    (__cov_xcode_version_gt(6, 3) && __cov_xcode_version_lt(8, 0))

extern double
__coverity___builtin_amdgpu_div_fmas(
    double __a,
    double __b,
    double __c,
    __cov_compat_bool __d);
#define __builtin_amdgpu_div_fmas(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_fmas((P0), (P1), (P2), (P3))

extern float
__coverity___builtin_amdgpu_div_fmasf(
    float __a,
    float __b,
    float __c,
    __cov_compat_bool __d);
#define __builtin_amdgpu_div_fmasf(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_fmasf((P0), (P1), (P2), (P3))

#endif /* } Clang > 3.5 || 6.3 < xcode < 8.0 */

/* } These builtins were modified in clang 3.8 and again in clang 3.9. { */
#if (__cov_clang_version_ge(3, 8)) && (!__cov_xcode_version_ge(8, 0))
extern void
__coverity___builtin_arm_mcrr(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_arm_mcrr2(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr2(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr2((P0), (P1), (P2), (P3), (P4))
#endif /* } Clang >= 3.8 && !(xcode >= 8.0) */

/* } These builtins were modified in clang 3.7 and again in clang 3.9. { */
#if (!__coverity_assume_xcode__ && __cov_clang_version_gt(3, 6)) || \
    __cov_xcode_version_ge(7, 0) /* { */

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherdiv16sf(
    float __attribute__((vector_size(32))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv16sf((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherdiv16si(
    int __attribute__((vector_size(32))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv16si((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_gatherdiv8df(
    double __attribute__((vector_size(64))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv8df((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_gatherdiv8di(
    long long __attribute__((vector_size(64))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfqpd(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfqps(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfqps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv16sf(
    float __attribute__((vector_size(64))) __a,
    const void* __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16sf(P0, P1, P2, P3) \
    __coverity___builtin_ia32_gathersiv16sf((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv16si(
    int __attribute__((vector_size(64))) __a,
    const void* __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16si(P0, P1, P2, P3) \
    __coverity___builtin_ia32_gathersiv16si((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv8df(
    double __attribute__((vector_size(64))) __a,
    const void* __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gathersiv8df((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv8di(
    long long __attribute__((vector_size(64))) __a,
    const void* __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gathersiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv16sf(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv16si(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv2df(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv2df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv2df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv2di(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv2di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv2di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4df(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4di(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    long long __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4sf(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4si(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8df(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8di(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    long long __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8sf(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8si(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfqpd(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfqps(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfqps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv16sf(
    void* __a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv16si(
    void* __a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv2df(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv2df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv2df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv2di(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv2di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv2di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4df(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4di(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4sf(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4si(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8df(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8di(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    long long __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8sf(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8si(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8si((P0), (P1), (P2), (P3), (P4))

#endif /* } */

/* } This builtin was modified in clang 3.8 and removed in clang 3.9 { */
#if (__cov_clang_version_ge(3, 8)) && (!__cov_xcode_version_ge(8, 0)) /* { */
extern long long
__coverity___builtin_ptx_read_clock64();
#define __builtin_ptx_read_clock64() \
    __coverity___builtin_ptx_read_clock64()
#endif /* } Clang >= 3.8 && !(xcode >= 8.0) */
#endif /* } clang < 3.9 */


/*************************************
 ************ Clang 4.0 **************
 *************************************/

#if (__cov_clang_version_lt(4, 0)) /* { */

#if !(__cov_xcode_version_gt(8, 1)) /* { */
extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaddubsw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaddubsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddubsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaddubsw256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaddubsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddubsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaddwd128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaddwd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddwd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaddwd256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaddwd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddwd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulhrsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulhrsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhrsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulhrsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulhrsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhrsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulhuw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulhuw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhuw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulhuw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulhuw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhuw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulhw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulhw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulhw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulhw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhw256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_addpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_addpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_addpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_addpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_addps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_addps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_addps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_addps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2pd128_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtdq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2pd256_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtdq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtudq2pd128_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtudq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtudq2pd256_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtudq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_divpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_divpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_divpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_divpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_divps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_divps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_divps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_divps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_maxpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_maxpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_maxpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_maxps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_maxps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_maxps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_minpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_minpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_minpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_minpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_minps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_minps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_minps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_minps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_mulpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_mulpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_mulpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_mulps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_mulps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_mulps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulps256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pabsd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pabsd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxsd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxsd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxud128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxud128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxud128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxud256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxud256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxud256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminsd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pminsd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminud128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminud128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminud128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminud256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pminud256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminud256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_sqrtpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtpd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtpd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_sqrtpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtpd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtpd256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_sqrtps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtps128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtps128_mask((P0), (P1), (P2))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_sqrtps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtps256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_subpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_subpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_subpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_subpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_subps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_subps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_subps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_subps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subps256_mask((P0), (P1), (P2), (P3))

#endif /* } !(xcode > 8.1) */

/* Removed in Clang 4.0 */
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_paddq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_psubq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __w,
    unsigned short __u);
#define __builtin_ia32_paddd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __w,
    unsigned short __u);
#define __builtin_ia32_psubd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmuldq512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_pmuldq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuldq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmuludq512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_pmuludq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuludq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulld512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __w,
    unsigned short __u);
#define __builtin_ia32_pmulld512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulld512_mask((P0), (P1), (P2), (P3))


extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_cvtdq2pd512_mask(
    int __attribute__ ((vector_size(32))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtdq2pd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2pd512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_cvtudq2pd512_mask(
    int __attribute__ ((vector_size(32))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtudq2pd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2pd512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddb512_mask(
    char __attribute__ ((vector_size(64))) __a,
    char __attribute__ ((vector_size(64))) __b,
    char __attribute__ ((vector_size(64))) __c,
    unsigned long long __u);
#define __builtin_ia32_paddb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddb512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubb512_mask(
    char __attribute__ ((vector_size(64))) __a,
    char __attribute__ ((vector_size(64))) __b,
    char __attribute__ ((vector_size(64))) __c,
    unsigned long long __u);
#define __builtin_ia32_psubb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubb512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddw512_mask(
    short __attribute__ ((vector_size(64))) __a,
    short __attribute__ ((vector_size(64))) __b,
    short __attribute__ ((vector_size(64))) __c,
    unsigned int __u);
#define __builtin_ia32_paddw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubw512_mask(
    short __attribute__ ((vector_size(64))) __a,
    short __attribute__ ((vector_size(64))) __b,
    short __attribute__ ((vector_size(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psubw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmullw512_mask(
    short __attribute__ ((vector_size(64))) __a,
    short __attribute__ ((vector_size(64))) __b,
    short __attribute__ ((vector_size(64))) __c,
    unsigned int __u);
#define __builtin_ia32_pmullw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pshufb512_mask(
    char __attribute__ ((vector_size(64))) __a,
    char __attribute__ ((vector_size(64))) __b,
    char __attribute__ ((vector_size(64))) __c,
    unsigned long long __u);
#define __builtin_ia32_pshufb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pshufb512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmullq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullq512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_xorpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_xorpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_xorps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_xorps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorps512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_orpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_orpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_orps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_orps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orps512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_andpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_andpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_andps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_andps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_andnps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_andnps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnps512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_andnpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_andnpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnpd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_paddd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_paddq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psubd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psubq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmuldq256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuldq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuldq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmuldq128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuldq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuldq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmuludq256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuludq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuludq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmuludq128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuludq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuludq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulld256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulld256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulld256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulld128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulld128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulld128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_paddb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_paddw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_psubb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psubw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_paddb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_psubb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmullw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmullw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmullw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    unsigned short __u);
#define __builtin_ia32_pabsb128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsb128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    unsigned int __u);
#define __builtin_ia32_pabsb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsb256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pabsw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsw128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    unsigned short __u);
#define __builtin_ia32_pabsw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsw256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packssdw128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packssdw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packssdw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packssdw256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __M);
#define __builtin_ia32_packssdw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packssdw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packsswb128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packsswb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packsswb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packsswb256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __M);
#define __builtin_ia32_packsswb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packsswb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packusdw128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packusdw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packusdw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packusdw256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __M);
#define __builtin_ia32_packusdw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packusdw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packuswb128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packuswb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packuswb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packuswb256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __M);
#define __builtin_ia32_packuswb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packuswb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_paddsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_paddsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_paddsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddusb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_paddusb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddusb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_paddusb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddusw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddusw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddusw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_paddusw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pavgb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pavgb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pavgb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pavgb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pavgw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pavgw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pavgw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pavgw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pmaxsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxub128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxub128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxub128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxub256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pmaxub256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxub256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxuw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxuw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxuw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxuw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pminsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pminsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pminsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminub128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pminub128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminub128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminub256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pminub256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminub256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminuw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminuw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminuw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pminuw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pshufb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pshufb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pshufb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pshufb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pshufb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pshufb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_psubsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_psubsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psubsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubusb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_psubusb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubusb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_psubusb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubusw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubusw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubusw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psubusw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmullq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmullq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullq128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_andnpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andnpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_andnpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andnpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_andnps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andnps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_andnps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andnps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnps128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_andpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_andpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_andps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_andps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andps128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_xorpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_xorpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_xorpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_xorpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_xorps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_xorps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_xorps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_xorps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorps128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_orpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_orpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_orpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_orpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_orps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_orps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_orps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_orps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orps128_mask((P0), (P1), (P2), (P3))

void __coverity___builtin_ia32_fxsave64(void *p);
#define __builtin_ia32_fxsave64(P0) \
    __coverity___builtin_ia32_fxsave64((P0))

void __coverity___builtin_ia32_fxsave(void *p);
#define __builtin_ia32_fxsave(P0) \
    __coverity___builtin_ia32_fxsave((P0))

void __coverity___builtin_ia32_fxrstor64(void *p);
#define __builtin_ia32_fxrstor64(P0) \
    __coverity___builtin_ia32_fxrstor64((P0))

void __coverity___builtin_ia32_fxrstor(void *p);
#define __builtin_ia32_fxrstor(P0) \
    __coverity___builtin_ia32_fxrstor((P0))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxbd512_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovsxbd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxbq512_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxdq512_mask(
    int __attribute__ ((vector_size(32))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxdq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxdq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxwd512_mask(
    short __attribute__ ((vector_size(32))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovsxwd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxwq512_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxbd512_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovzxbd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxbq512_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxdq512_mask(
    int __attribute__ ((vector_size(32))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxdq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxdq512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbd128_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbd256_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbq128_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbq256_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxdq128_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxdq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxdq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxdq256_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxdq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxdq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwd128_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwd256_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwq128_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwq256_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbd128_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbd256_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbq128_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbq256_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxdq128_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxdq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxdq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxdq256_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxdq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxdq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwd128_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwd256_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwq128_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwq256_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pslld128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pslld128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pslld128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pslld256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pslld256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pslld256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psllq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllv2di_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv2di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv2di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllv4di_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv4di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv4di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllv4si_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv4si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv4si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllv8si_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv8si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv8si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlv2di_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv2di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv2di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlv4di_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv4di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv4di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlv4si_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv4si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv4si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlv8si_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv8si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv8si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrld128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrld128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrld128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrld256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrld256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrld256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrav4si_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav4si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav4si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrav8si_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav8si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav8si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxwd512_mask(
    short __attribute__ ((vector_size(32))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovzxwd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxwq512_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pslld512_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_pslld512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pslld512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllq512_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psllq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllv16si_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psllv16si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv16si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllv8di_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv8di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv8di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrad512_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrad512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrad512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psraq512_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psraq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrav16si_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrav16si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav16si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrav8di_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav8di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav8di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrld512_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrld512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrld512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlq512_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlv16si_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrlv16si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv16si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlv8di_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv8di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv8di_mask((P0), (P1), (P2), (P3))

extern double __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_vpermilvarpd512_mask(
    double __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    double __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_vpermilvarps512_mask(
    float __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    float __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_vpermilvarps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarps512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psravq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psravq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psravq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psravq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psravq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psravq256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermilvarpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermilvarpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermilvarps_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vpermilvarps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarps256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrad128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrad128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrad128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrad256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrad256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrad256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psraq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psraq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psraq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psraq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxbw512_mask(
    char __attribute__ ((vector_size(32))) __a,
    short __attribute__((__vector_size__(64))) __b,
    unsigned int __u);
#define __builtin_ia32_pmovsxbw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbw512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxbw512_mask(
    char __attribute__ ((vector_size(32))) __a,
    short __attribute__((__vector_size__(64))) __b,
    unsigned int __u);
#define __builtin_ia32_pmovzxbw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbw512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllv32hi_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((__vector_size__(64))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psllv32hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv32hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllw512_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psllw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlv32hi_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((__vector_size__(64))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psrlv32hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv32hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrav32hi_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((__vector_size__(64))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psrav32hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav32hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psraw512_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psraw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlw512_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psrlw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbw128_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbw128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbw256_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__ ((vector_size(32))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovsxbw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbw256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbw128_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbw128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbw256_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__ ((vector_size(32))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovzxbw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbw256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllv16hi_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psllv16hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv16hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllv8hi_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv8hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv8hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psllw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlv16hi_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psrlv16hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv16hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlv8hi_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv8hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv8hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrav16hi_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psrav16hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav16hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrav8hi_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav8hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav8hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psraw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psraw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psraw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psraw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psrlw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlw256_mask((P0), (P1), (P2), (P3))

#endif /* } clang < 4.0 */


/*************************************
 ************ Clang 5.0 **************
 *************************************/

#if (__cov_clang_version_lt(5, 0)) /* { */

/* Signatures changed in Clang 5.0 { */

/* Clang 5.0 introduced a new 'N' type signature that specifies an 'int'
 * type for LP64 targets and a 'long' type for LLP64 targets.  The signatures
 * of a number of builtins were changed to use the new 'N' type signature in
 * place of 'L' and therefore show up in audits of changed builtin functions.
 * In practice, there is little impact to callers (the change was made to
 * maintain consistent behavior for Microsoft extensions on LP64 and LLP64
 * targets).  Compatibility signatures are therefore not defined here.  This
 * change was made in r305875:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=305875
 * The signatures of the following builtins were impacted:
 *   _BitScanForward
 *   _BitScanForward64
 *   _BitScanReverse
 *   _BitScanReverse64
 *   _InterlockedAnd
 *   _InterlockedCompareExchange
 *   _InterlockedDecrement
 *   _InterlockedExchange
 *   _InterlockedExchangeAdd
 *   _InterlockedExchangeSub
 *   _InterlockedIncrement
 *   _InterlockedOr
 *   _InterlockedXor
 *   __exception_code
 *   __readfsdword
 *   _byteswap_ulong
 *   _exception_code
 *   _lrotl
 *   _lrotr
 */

/* The signatures of a number of builtins were altered to reflect a requirement
 * that one of the operands is an integral constant expression.  Prior to this
 * change invocations that passed a non-constant expression were not rejected
 * with an error message, but triggered assertion failures later.  Since these
 * builtins effectively required callers to adhere to the new signatures,
 * compatibility signatures are not defined here.  These changes were made in
 * r305401 and r297584:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=305401
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=297584
 * The signatures of the following builtins were impacted:
 *   __builtin_altivec_vcfsx
 *   __builtin_altivec_vcfux
 *   __builtin_altivec_vctsxs
 *   __builtin_altivec_vctuxs
 *   __builtin_ia32_gather3div2df
 *   __builtin_ia32_gather3div2di
 *   __builtin_ia32_gather3div4df
 *   __builtin_ia32_gather3div4di
 *   __builtin_ia32_gather3div4sf
 *   __builtin_ia32_gather3div4si
 *   __builtin_ia32_gather3div8sf
 *   __builtin_ia32_gather3div8si
 *   __builtin_ia32_gather3siv2df
 *   __builtin_ia32_gather3siv2di
 *   __builtin_ia32_gather3siv4df
 *   __builtin_ia32_gather3siv4di
 *   __builtin_ia32_gather3siv4sf
 *   __builtin_ia32_gather3siv4si
 *   __builtin_ia32_gather3siv8sf
 *   __builtin_ia32_gather3siv8si
 */

/* The signature of __builtin_arm_usat was corrected to mark the first parameter
 * as 'int' rather than 'unsigned int'.  This signature change does not break
 * existing callers, so no compatibility signature is defined here.  This change
 * was made in r302131:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=302131
 */

/* The signature of __builtin_coro_end was changed to return 'bool' instead of
 * 'void'.  This signature change does not break existing callers, so no
 * compatibility signature is defined here.  This change was made in r297224:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=297224
 */

/* The signature of __builtin_wasm_grow_memory was changed to return 'size_t'
 * instead of 'void'.  This signature change does not break existing callers,
 * so no compatibility signature is defined here.  This change was made in
 * r292324:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=292324
 */

/* } Changed in Clang 5.0 */

/* These prototypes were removed in Clang 5.0 { */

/* These builtins were removed in r292329:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=292329
 * { */

// Signature: "V8fV4fV8fUc"
extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcastf32x4_256_mask(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf32x4_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x4_256_mask((P0), (P1), (P2))

// Signature: "V16fV4fV16fUs"
extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf32x4_512(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcastf32x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x4_512((P0), (P1), (P2))

// Signature: "V16fV8fV16fUs"
extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf32x8_512_mask(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcastf32x8_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x8_512_mask((P0), (P1), (P2))

// Signature: "V4dV2dV4dUc"
extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcastf64x2_256_mask(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf64x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf64x2_256_mask((P0), (P1), (P2))

// Signature: "V8dV2dV8dUc"
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf64x2_512_mask(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf64x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf64x2_512_mask((P0), (P1), (P2))

// Signature: "V8dV4dV8dUc"
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf64x4_512(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf64x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf64x4_512((P0), (P1), (P2))

// Signature: "V8iV4iV8iUc"
extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcasti32x4_256_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti32x4_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x4_256_mask((P0), (P1), (P2))

// Signature: "V16iV4iV16iUs"
extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti32x4_512(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcasti32x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x4_512((P0), (P1), (P2))

// Signature: "V16iV8iV16iUs"
extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti32x8_512_mask(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcasti32x8_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x8_512_mask((P0), (P1), (P2))

// Signature: "V4LLiV2LLiV4LLiUc"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcasti64x2_256_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti64x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti64x2_256_mask((P0), (P1), (P2))

// Signature: "V8LLiV2LLiV8LLiUc"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti64x2_512_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti64x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti64x2_512_mask((P0), (P1), (P2))

// Signature: "V8LLiV4LLiV8LLiUc"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti64x4_512(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti64x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti64x4_512((P0), (P1), (P2))

/* } */

/* These builtins were removed in r300326:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=300326
 * { */

#if (__cov_clang_version_ge(3, 8)) /* { */

/* The signatures of __builtin_ia32_movntdqa and __builtin_ia32_movntdqa256 were
 * previously changed in Clang 3.8.  For Clang versions older than 3.8,
 * compatibility signatures have already been declared.  The signatures declared
 * here correspond to Clang 3.8-4.0.
 */

// Signature: "V2LLiV2LLiC*"
extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_movntdqa(
    const long long __attribute__ ((vector_size(16))) *p0);
#define __builtin_ia32_movntdqa(P0) \
    __coverity___builtin_ia32_movntdqa((P0))

// The signature of __builtin_ia32_movntdqa256 chaanged in Clang 3.8, so for
// Clang versions older than that, a compatibility signature has already been
// declared.
// Signature: "V4LLiV4LLiC*"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_movntdqa256(
    const long long __attribute__((vector_size(32))) *p0);
#define __builtin_ia32_movntdqa256(P0) \
    __coverity___builtin_ia32_movntdqa256((P0))

#endif /* } clang >= 3.8 */

// Signature: "V8LLiV8LLi*"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_movntdqa512(
    long long __attribute__ ((vector_size(64))) *p0);
#define __builtin_ia32_movntdqa512(P0) \
    __coverity___builtin_ia32_movntdqa512((P0))

/* } */

/* These builtins were removed in r295291:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=295291
 * { */

// Signature: "V32sV16iV16iV32sUi"
extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_packssdw512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short __attribute__ ((vector_size(64))) p2,
    unsigned int p3);
#define __builtin_ia32_packssdw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packssdw512_mask((P0), (P1), (P2), (P3))

// Signature: "V64cV32sV32sV64cULLi"
extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_packsswb512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    char __attribute__ ((vector_size(64))) p2,
    unsigned long long p3);
#define __builtin_ia32_packsswb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packsswb512_mask((P0), (P1), (P2), (P3))

// Signature: "V32sV16iV16iV32sUi"
extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_packusdw512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short __attribute__ ((vector_size(64))) p2,
    unsigned int p3);
#define __builtin_ia32_packusdw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packusdw512_mask((P0), (P1), (P2), (P3))

// Signature: "V64cV32sV32sV64cULLi"
extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_packuswb512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    char __attribute__ ((vector_size(64))) p2,
    unsigned long long p3);
#define __builtin_ia32_packuswb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packuswb512_mask((P0), (P1), (P2), (P3))

/* } */

/* These builtins were removed in r295570:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=295570
 * { */

// Signature: "V2LLiV2LLiV2LLiV2LLi"
extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpcmov(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    long long __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vpcmov(P0, P1, P2) \
    __coverity___builtin_ia32_vpcmov((P0), (P1), (P2))

// Signature: "V4LLiV4LLiV4LLiV4LLi"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpcmov_256(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    long long __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vpcmov_256(P0, P1, P2) \
    __coverity___builtin_ia32_vpcmov_256((P0), (P1), (P2))

/* } */

/* These builtins were removed in r292694:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=292694
 * { */

// Signature: "ii"
extern int __coverity___nvvm_abs_i(int p0);
#define __nvvm_abs_i(P0) \
    __coverity___nvvm_abs_i((P0))

// Signature: "LLiLLi"
extern long long __coverity___nvvm_abs_ll(long long p0);
#define __nvvm_abs_ll(P0) \
    __coverity___nvvm_abs_ll((P0))

// Signature: "UiUi"
extern unsigned int __coverity___nvvm_brev32(unsigned int p0);
#define __nvvm_brev32(P0) \
    __coverity___nvvm_brev32((P0))

// Signature: "ULLiULLi"
extern unsigned long long __coverity___nvvm_brev64(unsigned long long p0);
#define __nvvm_brev64(P0) \
    __coverity___nvvm_brev64((P0))

// Signature: "ii"
extern int __coverity___nvvm_clz_i(int p0);
#define __nvvm_clz_i(P0) \
    __coverity___nvvm_clz_i((P0))

// Signature: "iLLi"
extern int __coverity___nvvm_clz_ll(long long p0);
#define __nvvm_clz_ll(P0) \
    __coverity___nvvm_clz_ll((P0))

// Signature: "fUs"
extern float __coverity___nvvm_h2f(unsigned short p0);
#define __nvvm_h2f(P0) \
    __coverity___nvvm_h2f((P0))

// Signature: "iii"
extern int __coverity___nvvm_max_i(int p0, int p1);
#define __nvvm_max_i(P0, P1) \
    __coverity___nvvm_max_i((P0), (P1))

// Signature: "LLiLLiLLi"
extern long long __coverity___nvvm_max_ll(long long p0, long long p1);
#define __nvvm_max_ll(P0, P1) \
    __coverity___nvvm_max_ll((P0), (P1))

// Signature: "UiUiUi"
extern unsigned int __coverity___nvvm_max_ui(unsigned int p0, unsigned int p1);
#define __nvvm_max_ui(P0, P1) \
    __coverity___nvvm_max_ui((P0), (P1))

// Signature: "ULLiULLiULLi"
extern unsigned long long __coverity___nvvm_max_ull(
    unsigned long long p0,
    unsigned long long p1);
#define __nvvm_max_ull(P0, P1) \
    __coverity___nvvm_max_ull((P0), (P1))

// Signature: "iii"
extern int __coverity___nvvm_min_i(int p0, int p1);
#define __nvvm_min_i(P0, P1) \
    __coverity___nvvm_min_i((P0), (P1))

// Signature: "LLiLLiLLi"
extern long long __coverity___nvvm_min_ll(long long p0, long long p1);
#define __nvvm_min_ll(P0, P1) \
    __coverity___nvvm_min_ll((P0), (P1))

// Signature: "UiUiUi"
extern unsigned int __coverity___nvvm_min_ui(unsigned int p0, unsigned int p1);
#define __nvvm_min_ui(P0, P1) \
    __coverity___nvvm_min_ui((P0), (P1))

// Signature: "ULLiULLiULLi"
extern unsigned long long __coverity___nvvm_min_ull(
    unsigned long long p0,
    unsigned long long p1);
#define __nvvm_min_ull(P0, P1) \
    __coverity___nvvm_min_ull((P0), (P1))

// Signature: "ii"
extern int __coverity___nvvm_popc_i(int p0);
#define __nvvm_popc_i(P0) \
    __coverity___nvvm_popc_i((P0))

// Signature: "iLLi"
extern int __coverity___nvvm_popc_ll(long long p0);
#define __nvvm_popc_ll(P0) \
    __coverity___nvvm_popc_ll((P0))

/* } */

/* } Removed in Clang 5.0 */

#endif /* } clang < 5.0 */


/* Clang 5.0.1 removed __builtin_ia32_pbroadcastq512_mem_mask due to deficient
 * backend support for 32-bit targets.  Support may be re-introduced at some
 * point in the future.  In the meantime, the following compatibility signature
 * is provided for all prior Clang versions (including Clang 5.0.0).
 * This builtin was removed in r313392:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=313392
 * { */

// Signature: "V8LLiLLiV8LLiUc"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pbroadcastq512_mem_mask(
    long long p0,
    long long __attribute__((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq512_mem_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq512_mem_mask((P0), (P1), (P2))

/* } */


/*************************************
 ************ Clang 6.0 **************
 *************************************/

#if (__cov_clang_version_lt(6, 0)) /* { */

/* Signatures changed in Clang 6.0 { */

/* The signature of __builtin_ia32_clflushopt was corrected to declare the first
 * parameter as 'const void*' rather than 'char*'.  This change was made in
 * r315470:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=315470
 * { */

// Signature: vvC*
void __coverity___builtin_ia32_clflushopt(const void *p0);
#define __builtin_ia32_clflushopt(P0) \
    __coverity___builtin_ia32_clflushopt((P0))

/* } */

/* The signatures of get_kernel_preferred_work_group_size_multiple and
 * get_kernel_work_group_size were corrected to return 'unsigned int' rather
 * than 'int'.  This signature change does not break existing callers, so no
 * compatibility signature is defined here.  This change was made in r309678:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=309678
 */

/* } Changed in Clang 6.0 */

/* These prototypes were removed in Clang 6.0 { */

/* These builtins were removed in r320609:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=320609
 * { */

// Signature: ii
int
__coverity___builtin_SI_to_SXTHI_asrh(
    int p0);
#define __builtin_SI_to_SXTHI_asrh(P0) \
    __coverity___builtin_SI_to_SXTHI_asrh((P0))

// Signature: V16iV16iLLii
int __attribute__ ((vector_size(64)))
__coverity___builtin_HEXAGON_V6_vlutb(
    int __attribute__ ((vector_size(64))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb((P0), (P1), (P2))

// Signature: V32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_128B(
    int __attribute__ ((vector_size(128))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb_128B(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb_128B((P0), (P1), (P2))

// Signature: V16iV16iV16iLLii
int __attribute__ ((vector_size(64)))
__coverity___builtin_HEXAGON_V6_vlutb_acc(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_acc(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_acc((P0), (P1), (P2), (P3))

// Signature: V32iV32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_acc_128B(
    int __attribute__ ((vector_size(128))) p0,
    int __attribute__ ((vector_size(128))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_acc_128B(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_acc_128B((P0), (P1), (P2), (P3))

// Signature: V32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_dv(
    int __attribute__ ((vector_size(128))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb_dv(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv((P0), (P1), (P2))

// Signature: V64iV64iLLii
int __attribute__ ((vector_size(256)))
__coverity___builtin_HEXAGON_V6_vlutb_dv_128B(
    int __attribute__ ((vector_size(256))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb_dv_128B(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv_128B((P0), (P1), (P2))

// Signature: V32iV32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_dv_acc(
    int __attribute__ ((vector_size(128))) p0,
    int __attribute__ ((vector_size(128))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_dv_acc(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv_acc((P0), (P1), (P2), (P3))

// Signature: V64iV64iV64iLLii
int __attribute__ ((vector_size(256)))
__coverity___builtin_HEXAGON_V6_vlutb_dv_acc_128B(
    int __attribute__ ((vector_size(256))) p0,
    int __attribute__ ((vector_size(256))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_dv_acc_128B(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv_acc_128B((P0), (P1), (P2), (P3))

/* } */

/* These builtins were removed in r312135:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=312135
 * { */

// Signature: V8fV4fV8fUc
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcastf32x2_256_mask(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf32x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x2_256_mask((P0), (P1), (P2))

// Signature: V16fV4fV16fUs
float __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcastf32x2_512_mask(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcastf32x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x2_512_mask((P0), (P1), (P2))

// Signature: V4iV4iV4iUc
int __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_broadcasti32x2_128_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti32x2_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x2_128_mask((P0), (P1), (P2))

// Signature: V8iV4iV8iUc
int __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcasti32x2_256_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti32x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x2_256_mask((P0), (P1), (P2))

// Signature: V16iV4iV16iUs
int __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcasti32x2_512_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcasti32x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x2_512_mask((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317456:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317456
 * { */

// Signature: V2LLiUc
long long __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_broadcastmb128(
    unsigned char p0);
#define __builtin_ia32_broadcastmb128(P0) \
    __coverity___builtin_ia32_broadcastmb128((P0))

// Signature: V4LLiUc
long long __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcastmb256(
    unsigned char p0);
#define __builtin_ia32_broadcastmb256(P0) \
    __coverity___builtin_ia32_broadcastmb256((P0))

// Signature: V8LLiUc
long long __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcastmb512(
    unsigned char p0);
#define __builtin_ia32_broadcastmb512(P0) \
    __coverity___builtin_ia32_broadcastmb512((P0))

// Signature: V4iUs
int __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_broadcastmw128(
    unsigned short p0);
#define __builtin_ia32_broadcastmw128(P0) \
    __coverity___builtin_ia32_broadcastmw128((P0))

// Signature: V8iUs
int __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcastmw256(
    unsigned short p0);
#define __builtin_ia32_broadcastmw256(P0) \
    __coverity___builtin_ia32_broadcastmw256((P0))

// Signature: V16iUs
int __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcastmw512(
    unsigned short p0);
#define __builtin_ia32_broadcastmw512(P0) \
    __coverity___builtin_ia32_broadcastmw512((P0))

/* } */

/* These builtins were removed in r313011:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=313011
 * { */

// Signature: V16cV16cV16c
char __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pavgb128(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1);
#define __builtin_ia32_pavgb128(P0, P1) \
    __coverity___builtin_ia32_pavgb128((P0), (P1))

// Signature: V32cV32cV32c
char __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pavgb256(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1);
#define __builtin_ia32_pavgb256(P0, P1) \
    __coverity___builtin_ia32_pavgb256((P0), (P1))

// Signature: V64cV64cV64cV64cULLi
char __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pavgb512_mask(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    char __attribute__ ((vector_size(64))) p2,
    unsigned long long p3);
#define __builtin_ia32_pavgb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgb512_mask((P0), (P1), (P2), (P3))

// Signature: V8sV8sV8s
short __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pavgw128(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1);
#define __builtin_ia32_pavgw128(P0, P1) \
    __coverity___builtin_ia32_pavgw128((P0), (P1))

// Signature: V16sV16sV16s
short __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pavgw256(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1);
#define __builtin_ia32_pavgw256(P0, P1) \
    __coverity___builtin_ia32_pavgw256((P0), (P1))

// Signature: V32sV32sV32sV32sUi
short __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pavgw512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    short __attribute__ ((vector_size(64))) p2,
    unsigned int p3);
#define __builtin_ia32_pavgw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgw512_mask((P0), (P1), (P2), (P3))

/* } */

/* These builtins were removed in r313624:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=313624
 * { */

// Signature: V16ccV16cUs
char __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastb128_gpr_mask(
    char p0,
    char __attribute__ ((vector_size(16))) p1,
    unsigned short p2);
#define __builtin_ia32_pbroadcastb128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastb128_gpr_mask((P0), (P1), (P2))

// Signature: V32ccV32cUi
char __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastb256_gpr_mask(
    char p0,
    char __attribute__ ((vector_size(32))) p1,
    unsigned int p2);
#define __builtin_ia32_pbroadcastb256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastb256_gpr_mask((P0), (P1), (P2))

// Signature: V64ccV64cULLi
char __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastb512_gpr_mask(
    char p0,
    char __attribute__ ((vector_size(64))) p1,
    unsigned long long p2);
#define __builtin_ia32_pbroadcastb512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastb512_gpr_mask((P0), (P1), (P2))

// Signature: V4iiV4iUc
int __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastd128_gpr_mask(
    int p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastd128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastd128_gpr_mask((P0), (P1), (P2))

// Signature: V8iiV8iUc
int __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastd256_gpr_mask(
    int p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastd256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastd256_gpr_mask((P0), (P1), (P2))

// Signature: V16iiV16iUs
int __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastd512_gpr_mask(
    int p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_pbroadcastd512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastd512_gpr_mask((P0), (P1), (P2))

// Signature: V8ssV8sUc
short __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastw128_gpr_mask(
    short p0,
    short __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastw128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastw128_gpr_mask((P0), (P1), (P2))

// Signature: V16shV16sUs
short __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastw256_gpr_mask(
    short p0,
    short __attribute__ ((vector_size(32))) p1,
    unsigned short p2);
#define __builtin_ia32_pbroadcastw256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastw256_gpr_mask((P0), (P1), (P2))

// Signature: V32shV32sUi
short __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastw512_gpr_mask(
    short p0,
    short __attribute__ ((vector_size(64))) p1,
    unsigned int p2);
#define __builtin_ia32_pbroadcastw512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastw512_gpr_mask((P0), (P1), (P2))

// Signature: V2LLiULLiV2LLiUc
long long __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastq128_gpr_mask(
    unsigned long long p0,
    long long __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq128_gpr_mask((P0), (P1), (P2))

// Signature: V4LLiULLiV4LLiUc
long long __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastq256_gpr_mask(
    unsigned long long p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq256_gpr_mask((P0), (P1), (P2))

// Signature: V8LLiLLiV8LLiUc
long long __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastq512_gpr_mask(
    long long p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq512_gpr_mask((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317506:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317506
 * { */

// Signature: sV16cV16cs
short
__coverity___builtin_ia32_pcmpeqb128_mask(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    short p2);
#define __builtin_ia32_pcmpeqb128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqb128_mask((P0), (P1), (P2))

// Signature: iV32cV32ci
int
__coverity___builtin_ia32_pcmpeqb256_mask(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    int p2);
#define __builtin_ia32_pcmpeqb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqb256_mask((P0), (P1), (P2))

// Signature: LLiV64cV64cLLi
long long
__coverity___builtin_ia32_pcmpeqb512_mask(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    long long p2);
#define __builtin_ia32_pcmpeqb512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqb512_mask((P0), (P1), (P2))

// Signature: cV4iV4ic
char
__coverity___builtin_ia32_pcmpeqd128_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpeqd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqd128_mask((P0), (P1), (P2))

// Signature: cV8iV8ic
char
__coverity___builtin_ia32_pcmpeqd256_mask(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpeqd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqd256_mask((P0), (P1), (P2))

// Signature: sV16iV16is
short
__coverity___builtin_ia32_pcmpeqd512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short p2);
#define __builtin_ia32_pcmpeqd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqd512_mask((P0), (P1), (P2))

// Signature: cV2LLiV2LLic
char
__coverity___builtin_ia32_pcmpeqq128_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpeqq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqq128_mask((P0), (P1), (P2))

// Signature: cV4LLiV4LLic
char
__coverity___builtin_ia32_pcmpeqq256_mask(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpeqq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqq256_mask((P0), (P1), (P2))

// Signature: cV8LLiV8LLic
char
__coverity___builtin_ia32_pcmpeqq512_mask(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    char p2);
#define __builtin_ia32_pcmpeqq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqq512_mask((P0), (P1), (P2))

// Signature: cV8sV8sc
char
__coverity___builtin_ia32_pcmpeqw128_mask(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpeqw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqw128_mask((P0), (P1), (P2))

// Signature: sV16sV16ss
short
__coverity___builtin_ia32_pcmpeqw256_mask(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    short p2);
#define __builtin_ia32_pcmpeqw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqw256_mask((P0), (P1), (P2))

// Signature: iV32sV32si
int
__coverity___builtin_ia32_pcmpeqw512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    int p2);
#define __builtin_ia32_pcmpeqw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqw512_mask((P0), (P1), (P2))

// Signature: sV16cV16cs
short
__coverity___builtin_ia32_pcmpgtb128_mask(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    short p2);
#define __builtin_ia32_pcmpgtb128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtb128_mask((P0), (P1), (P2))

// Signature: iV32cV32ci
int
__coverity___builtin_ia32_pcmpgtb256_mask(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    int p2);
#define __builtin_ia32_pcmpgtb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtb256_mask((P0), (P1), (P2))

// Signature: LLiV64cV64cLLi
long long
__coverity___builtin_ia32_pcmpgtb512_mask(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    long long p2);
#define __builtin_ia32_pcmpgtb512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtb512_mask((P0), (P1), (P2))

// Signature: cV4iV4ic
char
__coverity___builtin_ia32_pcmpgtd128_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpgtd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtd128_mask((P0), (P1), (P2))

// Signature: cV8iV8ic
char
__coverity___builtin_ia32_pcmpgtd256_mask(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpgtd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtd256_mask((P0), (P1), (P2))

// Signature: sV16iV16is
short
__coverity___builtin_ia32_pcmpgtd512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short p2);
#define __builtin_ia32_pcmpgtd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtd512_mask((P0), (P1), (P2))

// Signature: cV2LLiV2LLic
char
__coverity___builtin_ia32_pcmpgtq128_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpgtq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtq128_mask((P0), (P1), (P2))

// Signature: cV4LLiV4LLic
char
__coverity___builtin_ia32_pcmpgtq256_mask(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpgtq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtq256_mask((P0), (P1), (P2))

// Signature: cV8LLiV8LLic
char
__coverity___builtin_ia32_pcmpgtq512_mask(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    char p2);
#define __builtin_ia32_pcmpgtq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtq512_mask((P0), (P1), (P2))

// Signature: cV8sV8sc
char
__coverity___builtin_ia32_pcmpgtw128_mask(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpgtw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtw128_mask((P0), (P1), (P2))

// Signature: sV16sV16ss
short
__coverity___builtin_ia32_pcmpgtw256_mask(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    short p2);
#define __builtin_ia32_pcmpgtw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtw256_mask((P0), (P1), (P2))

// Signature: iV32sV32si
int
__coverity___builtin_ia32_pcmpgtw512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    int p2);
#define __builtin_ia32_pcmpgtw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtw512_mask((P0), (P1), (P2))

/* } */

/* These builtins were removed in r318035:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=318035
 * { */

// Signature: UsV16cV16cUs
unsigned short
__coverity___builtin_ia32_ptestmb128(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestmb128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmb128((P0), (P1), (P2))

// Signature: UiV32cV32cUi
unsigned int
__coverity___builtin_ia32_ptestmb256(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestmb256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmb256((P0), (P1), (P2))

// Signature: ULLiV64cV64cULLi
unsigned long long
__coverity___builtin_ia32_ptestmb512(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    unsigned long long p2);
#define __builtin_ia32_ptestmb512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmb512((P0), (P1), (P2))

// Signature: UcV4iV4iUc
unsigned char
__coverity___builtin_ia32_ptestmd128(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmd128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmd128((P0), (P1), (P2))

// Signature: UcV8iV8iUc
unsigned char
__coverity___builtin_ia32_ptestmd256(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmd256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmd256((P0), (P1), (P2))

// Signature: UsV16iV16iUs
unsigned short
__coverity___builtin_ia32_ptestmd512(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestmd512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmd512((P0), (P1), (P2))

// Signature: UcV2LLiV2LLiUc
unsigned char
__coverity___builtin_ia32_ptestmq128(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmq128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmq128((P0), (P1), (P2))

// Signature: UcV4LLiV4LLiUc
unsigned char
__coverity___builtin_ia32_ptestmq256(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmq256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmq256((P0), (P1), (P2))

// Signature: UcV8LLiV8LLiUc
unsigned char
__coverity___builtin_ia32_ptestmq512(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmq512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmq512((P0), (P1), (P2))

// Signature: UcV8sV8sUc
unsigned char
__coverity___builtin_ia32_ptestmw128(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmw128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmw128((P0), (P1), (P2))

// Signature: UsV16sV16sUs
unsigned short
__coverity___builtin_ia32_ptestmw256(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestmw256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmw256((P0), (P1), (P2))

// Signature: UiV32sV32sUi
unsigned int
__coverity___builtin_ia32_ptestmw512(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestmw512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmw512((P0), (P1), (P2))

// Signature: UsV16cV16cUs
unsigned short
__coverity___builtin_ia32_ptestnmb128(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestnmb128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmb128((P0), (P1), (P2))

// Signature: UiV32cV32cUi
unsigned int
__coverity___builtin_ia32_ptestnmb256(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestnmb256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmb256((P0), (P1), (P2))

// Signature: ULLiV64cV64cULLi
unsigned long long
__coverity___builtin_ia32_ptestnmb512(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    unsigned long long p2);
#define __builtin_ia32_ptestnmb512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmb512((P0), (P1), (P2))

// Signature: UcV4iV4iUc
unsigned char
__coverity___builtin_ia32_ptestnmd128(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmd128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmd128((P0), (P1), (P2))

// Signature: UcV8iV8iUc
unsigned char
__coverity___builtin_ia32_ptestnmd256(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmd256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmd256((P0), (P1), (P2))

// Signature: UsV16iV16iUs
unsigned short
__coverity___builtin_ia32_ptestnmd512(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestnmd512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmd512((P0), (P1), (P2))

// Signature: UcV2LLiV2LLiUc
unsigned char
__coverity___builtin_ia32_ptestnmq128(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmq128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmq128((P0), (P1), (P2))

// Signature: UcV4LLiV4LLiUc
unsigned char
__coverity___builtin_ia32_ptestnmq256(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmq256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmq256((P0), (P1), (P2))

// Signature: UcV8LLiV8LLiUc
unsigned char
__coverity___builtin_ia32_ptestnmq512(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmq512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmq512((P0), (P1), (P2))

// Signature: UcV8sV8sUc
unsigned char
__coverity___builtin_ia32_ptestnmw128(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmw128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmw128((P0), (P1), (P2))

// Signature: UsV16sV16sUs
unsigned short
__coverity___builtin_ia32_ptestnmw256(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestnmw256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmw256((P0), (P1), (P2))

// Signature: UiV32sV32sUi
unsigned int
__coverity___builtin_ia32_ptestnmw512(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestnmw512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmw512((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317873:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317873
 * { */

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubaddpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddpd((P0), (P1), (P2))

// Signature: V4dV4dV4dV4d
double __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddpd256(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(32))) p1,
    double __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubaddpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddpd256((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubaddps(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddps((P0), (P1), (P2))

// Signature: V8fV8fV8fV8f
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddps256(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(32))) p1,
    float __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubaddps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddps256((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubpd((P0), (P1), (P2))

// Signature: V4dV4dV4dV4d
double __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubpd256(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(32))) p1,
    double __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubpd256((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubps(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubps((P0), (P1), (P2))

// Signature: V8fV8fV8fV8f
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubps256(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(32))) p1,
    float __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubps256((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddpd((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddps(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddps((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubpd((P0), (P1), (P2))

// Signature: V4dV4dV4dV4d
double __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfnmsubpd256(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(32))) p1,
    double __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfnmsubpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubpd256((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubps(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubps((P0), (P1), (P2))

// Signature: V8fV8fV8fV8f
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfnmsubps256(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(32))) p1,
    float __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfnmsubps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubps256((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317766:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317766
 * { */

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddss(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddss(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddss((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddsd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddsd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddsd((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubsd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubsd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubsd((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubss(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubss(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubss((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubsd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubsd(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubsd((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubss(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubss(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubss((P0), (P1), (P2))

/* } */

/* } Removed in Clang 6.0 */

#endif /* } clang < 6.0 */

// XCode 10 - No changes from Clang 6


/*************************************
 ************ Clang 7.0 **************
 *************************************/

#if (__cov_clang_version_lt(7, 0)) /* { */

/* Signatures changed in Clang 7.0 { */

extern unsigned char*
__coverity___builtin_amdgcn_dispatch_ptr();
#define __builtin_amdgcn_dispatch_ptr() \
    __coverity___builtin_amdgcn_dispatch_ptr()

extern unsigned char*
__coverity___builtin_amdgcn_implicitarg_ptr();
#define __builtin_amdgcn_implicitarg_ptr() \
    __coverity___builtin_amdgcn_implicitarg_ptr()

extern unsigned char*
__coverity___builtin_amdgcn_kernarg_segment_ptr();
#define __builtin_amdgcn_kernarg_segment_ptr() \
    __coverity___builtin_amdgcn_kernarg_segment_ptr()

extern char*
__coverity___builtin_brev_ldb(
    char* __a,
    char* __b,
    int __c);
#define __builtin_brev_ldb(P0, P1, P2) \
    __coverity___builtin_brev_ldb((P0), (P1), (P2))

extern long long*
__coverity___builtin_brev_ldd(
    long long* __a,
    long long* __b,
    int __c);
#define __builtin_brev_ldd(P0, P1, P2) \
    __coverity___builtin_brev_ldd((P0), (P1), (P2))

extern short*
__coverity___builtin_brev_ldh(
    short* __a,
    short* __b,
    int __c);
#define __builtin_brev_ldh(P0, P1, P2) \
    __coverity___builtin_brev_ldh((P0), (P1), (P2))

extern unsigned char*
__coverity___builtin_brev_ldub(
    unsigned char* __a,
    unsigned char* __b,
    int __c);
#define __builtin_brev_ldub(P0, P1, P2) \
    __coverity___builtin_brev_ldub((P0), (P1), (P2))

extern unsigned short*
__coverity___builtin_brev_lduh(
    unsigned short* __a,
    unsigned short* __b,
    int __c);
#define __builtin_brev_lduh(P0, P1, P2) \
    __coverity___builtin_brev_lduh((P0), (P1), (P2))

extern int*
__coverity___builtin_brev_ldw(
    int* __a,
    int* __b,
    int __c);
#define __builtin_brev_ldw(P0, P1, P2) \
    __coverity___builtin_brev_ldw((P0), (P1), (P2))

extern char*
__coverity___builtin_brev_stb(
    char* __a,
    int __b,
    int __c);
#define __builtin_brev_stb(P0, P1, P2) \
    __coverity___builtin_brev_stb((P0), (P1), (P2))

extern long long*
__coverity___builtin_brev_std(
    long long* __a,
    long long __b,
    int __c);
#define __builtin_brev_std(P0, P1, P2) \
    __coverity___builtin_brev_std((P0), (P1), (P2))

extern short*
__coverity___builtin_brev_sth(
    short* __a,
    int __b,
    int __c);
#define __builtin_brev_sth(P0, P1, P2) \
    __coverity___builtin_brev_sth((P0), (P1), (P2))

extern short*
__coverity___builtin_brev_sthhi(
    short* __a,
    int __b,
    int __c);
#define __builtin_brev_sthhi(P0, P1, P2) \
    __coverity___builtin_brev_sthhi((P0), (P1), (P2))

extern int*
__coverity___builtin_brev_stw(
    int* __a,
    int __b,
    int __c);
#define __builtin_brev_stw(P0, P1, P2) \
    __coverity___builtin_brev_stw((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloaddf128_mask(
    double __attribute__((vector_size(16)))* __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddf128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddf128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloaddf256_mask(
    double __attribute__((vector_size(32)))* __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddf256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddf256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloaddi128_mask(
    long long __attribute__((vector_size(16)))* __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddi128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddi128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloaddi256_mask(
    long long __attribute__((vector_size(32)))* __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddi256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddi256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloadsf128_mask(
    float __attribute__((vector_size(16)))* __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsf128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsf128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloadsf256_mask(
    float __attribute__((vector_size(32)))* __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsf256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsf256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloadsi128_mask(
    int __attribute__((vector_size(16)))* __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsi128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsi128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloadsi256_mask(
    int __attribute__((vector_size(32)))* __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsi256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsi256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_getmantpd128_mask(
    double __attribute__((vector_size(16))) __a,
    int __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_getmantpd256_mask(
    double __attribute__((vector_size(32))) __a,
    int __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_getmantpd512_mask(
    double __attribute__((vector_size(64))) __a,
    int __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_getmantpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_getmantpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_getmantps128_mask(
    float __attribute__((vector_size(16))) __a,
    int __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_getmantps256_mask(
    float __attribute__((vector_size(32))) __a,
    int __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_getmantps512_mask(
    float __attribute__((vector_size(64))) __a,
    int __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_getmantps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_getmantps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadsd128_mask(
    double __attribute__((vector_size(64)))* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loadsd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadsd128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadss128_mask(
    float __attribute__((vector_size(64)))* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loadss128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadss128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_permti256(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_permti256(P0, P1, P2) \
    __coverity___builtin_ia32_permti256((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storesd128_mask(
    double __attribute__((vector_size(64)))* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storesd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storesd128_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storess128_mask(
    float __attribute__((vector_size(64)))* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storess128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storess128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_pd256(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_vperm2f128_pd256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_pd256((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_ps256(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_vperm2f128_ps256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_ps256((P0), (P1), (P2))

// Modified in Clang 3. Modified again in Clang 7
// Extra check to make sure we use the right version
#if (__cov_clang_version_gt(3,0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_si256(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_vperm2f128_si256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_si256((P0), (P1), (P2))
#endif

/* } Changed in Clang 7.0 */

/* Removed in Clang 7.0 { */
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_addpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_addpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_addps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_addps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addps512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2ps(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtdq2ps(P0) \
    __coverity___builtin_ia32_cvtdq2ps((P0))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2ps128_mask(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtdq2ps128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2ps128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2ps256(
    int __attribute__((vector_size(32))) __a);
#define __builtin_ia32_cvtdq2ps256(P0) \
    __coverity___builtin_ia32_cvtdq2ps256((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2ps256_mask(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtdq2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2ps256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtpd2dq256_mask(
    double __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtpd2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtpd2dq256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtpd2ps256_mask(
    double __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtpd2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtpd2ps256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtps2dq128_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2dq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2dq128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtps2dq256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2dq256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtps2pd128_mask(
    float __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtps2pd256_mask(
    float __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtqq2pd128_mask(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtqq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtqq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtqq2pd256_mask(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtqq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtqq2pd256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvttpd2dq256_mask(
    double __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvttpd2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvttpd2dq256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvttps2dq128_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvttps2dq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvttps2dq128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvttps2dq256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvttps2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvttps2dq256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtudq2ps128_mask(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtudq2ps128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2ps128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtudq2ps256_mask(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtudq2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2ps256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtuqq2pd128_mask(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtuqq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtuqq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtuqq2pd256_mask(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtuqq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtuqq2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtusi2sd32(
    double __attribute__((vector_size(16))) __a,
    unsigned int __b);
#define __builtin_ia32_cvtusi2sd32(P0, P1) \
    __coverity___builtin_ia32_cvtusi2sd32((P0), (P1))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_dbpsadbw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    const int __c,
    short __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_dbpsadbw128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_dbpsadbw128_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_dbpsadbw256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    const int __c,
    short __attribute__((vector_size(32))) __d,
    unsigned short __e);
#define __builtin_ia32_dbpsadbw256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_dbpsadbw256_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_dbpsadbw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    const int __c,
    short __attribute__((vector_size(64))) __d,
    unsigned int __e);
#define __builtin_ia32_dbpsadbw512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_dbpsadbw512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_divpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_divpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_divps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_divps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divps512_mask((P0), (P1), (P2), (P3), (P4))

// Modified in 3.7 and XCode 7. Removed in Clang 7
// Extra check to make sure we use the right version
#if ( __cov_clang_version_ge(3, 7) || __cov_xcode_version_ge(7, 0))
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_maxpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_maxps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_maxps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_minpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_minps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_minps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minps512_mask((P0), (P1), (P2), (P3), (P4))
#endif

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_mulpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_mulpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_mulps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_mulps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulps512_mask((P0), (P1), (P2), (P3), (P4))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    unsigned long long __c);
#define __builtin_ia32_pabsb512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsb512_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_pabsd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsd512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_pabsq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_pabsq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_pabsq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsq512_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    unsigned int __c);
#define __builtin_ia32_pabsw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsw512_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_palignr512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    const int __c,
    char __attribute__((vector_size(64))) __d,
    unsigned long long __e);
#define __builtin_ia32_palignr512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_palignr512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvardf256_mask(
    double __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardf256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardf256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvardf512_mask(
    double __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardf512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardf512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvardi256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardi256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvardi512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardi512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_permvarhi128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_permvarhi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarhi128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarhi256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarhi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarhi256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarhi512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_permvarhi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarhi512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_permvarqi128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarqi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarqi128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarqi256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_permvarqi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarqi256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarqi512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_permvarqi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarqi512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarsf256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvarsf256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsf256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarsf512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarsf512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsf512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarsi256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvarsi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsi256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarsi512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarsi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsi512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaddubsw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmaddubsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddubsw512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaddwd512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pmaddwd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddwd512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pmaxsb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsb512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pmaxsd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxsq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxsq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxsq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmaxsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxub512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pmaxub512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxub512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxud512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pmaxud512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxud512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxuq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxuq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxuq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxuq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxuq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxuq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxuw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmaxuw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pminsb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsb512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pminsd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pminsq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pminsq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pminsq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pminsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminub512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pminub512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminub512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminud512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pminud512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminud512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminuq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pminuq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminuq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pminuq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminuq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pminuq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminuw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pminuw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuw512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovqd256_mask(
    long long __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_pmovqd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovqd256_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovwb256_mask(
    short __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(16))) __b,
    unsigned short __c);
#define __builtin_ia32_pmovwb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovwb256_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulhrsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmulhrsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhrsw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulhuw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmulhuw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhuw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulhw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmulhw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhw512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prold128_mask(
    int __attribute__((vector_size(16))) __a,
    const int __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prold128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prold128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prold256_mask(
    int __attribute__((vector_size(32))) __a,
    const int __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prold256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prold256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prold512_mask(
    int __attribute__((vector_size(64))) __a,
    const int __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prold512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prold512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prolq128_mask(
    long long __attribute__((vector_size(16))) __a,
    const int __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prolq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prolq256_mask(
    long long __attribute__((vector_size(32))) __a,
    const int __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prolq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prolq512_mask(
    long long __attribute__((vector_size(64))) __a,
    const int __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prolq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prolvd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prolvd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prolvd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prolvd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prolvq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prolvq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prolvq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prord128_mask(
    int __attribute__((vector_size(16))) __a,
    const int __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prord128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prord128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prord256_mask(
    int __attribute__((vector_size(32))) __a,
    const int __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prord256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prord256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prord512_mask(
    int __attribute__((vector_size(64))) __a,
    int __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prord512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prord512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prorq128_mask(
    long long __attribute__((vector_size(16))) __a,
    const int __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prorq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prorq256_mask(
    long long __attribute__((vector_size(32))) __a,
    const int __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prorq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prorq512_mask(
    long long __attribute__((vector_size(64))) __a,
    int __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prorq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prorvd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prorvd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prorvd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prorvd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prorvq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prorvq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prorvq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvq512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_f32x4_256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    const int __c,
    float __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_f32x4_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f32x4_256_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_f32x4_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    const int __c,
    float __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_shuf_f32x4_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f32x4_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_f64x2_256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    const int __c,
    double __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_f64x2_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f64x2_256_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_f64x2_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    const int __c,
    double __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_f64x2_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f64x2_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_i32x4_256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const int __c,
    int __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_i32x4_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i32x4_256_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_i32x4_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    const int __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_shuf_i32x4_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i32x4_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_i64x2_256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const int __c,
    long long __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_i64x2_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i64x2_256_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_i64x2_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    const int __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_i64x2_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i64x2_mask((P0), (P1), (P2), (P3), (P4))

// Modified in Version 3.7 and Xcode 7. Removed in Clang 7
// Extra check to ensure we use the right version
#if ( __cov_clang_version_ge(3, 7) || __cov_xcode_version_ge(7, 0))
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_sqrtpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_sqrtpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_sqrtpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_sqrtps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_sqrtps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_sqrtps512_mask((P0), (P1), (P2), (P3))
#endif

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_subpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_subpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_subps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_subps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastf128_pd256(
    const double __attribute__((vector_size(16)))* __a);
#define __builtin_ia32_vbroadcastf128_pd256(P0) \
    __coverity___builtin_ia32_vbroadcastf128_pd256((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastf128_ps256(
    const float __attribute__((vector_size(16)))* __a);
#define __builtin_ia32_vbroadcastf128_ps256(P0) \
    __coverity___builtin_ia32_vbroadcastf128_ps256((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddpd128_maskz(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd128_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddpd256_maskz(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd256_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddps128_maskz(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps128_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddps256_maskz(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps256_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubpd128_maskz(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd128_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubpd256_maskz(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd256_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubps128_maskz(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps128_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubps256_maskz(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps256_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddpd256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddps256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubpd256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubps256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmaddpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddpd256(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c);
#define __builtin_ia32_vfnmaddpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddpd256((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmaddpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmaddpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmaddpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmaddps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddps256(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c);
#define __builtin_ia32_vfnmaddps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddps256((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmaddps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_vfnmaddps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmaddps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubpd512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubpd512_mask3(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubpd512_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubpd512_mask3((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_vfnmsubps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubps512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubps512_mask3(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_vfnmsubps512_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubps512_mask3((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubsd3_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubsd3_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubsd3_mask3((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubss3_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubss3_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubss3_mask3((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusd128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusd256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusd512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusds128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusds128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusds256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusds256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusds512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusds512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusds512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusds512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssd128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssd256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssd512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssds128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssds128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssds256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssds256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssds512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssds512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssds512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssds512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2vard128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2vard128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2vard128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2vard256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2vard256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2vard256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2vard512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2vard512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2vard512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varhi128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varhi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varhi128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varhi256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2varhi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varhi256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varhi512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermi2varhi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varhi512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varpd128_mask(
    double __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varpd256_mask(
    double __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varpd512_mask(
    double __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varps128_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varps256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varps512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2varps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varps512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varq512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varqi128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2varqi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varqi128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varqi256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermi2varqi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varqi256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varqi512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_vpermi2varqi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varqi512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2vard128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2vard128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2vard256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2vard256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2vard512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2vard512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2vard512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2vard512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard512_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varhi128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varhi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varhi128_maskz(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varhi128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi128_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varhi256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varhi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varhi256_maskz(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varhi256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi256_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varhi512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varhi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varhi512_maskz(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varhi512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi512_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varpd128_mask(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varpd128_maskz(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd128_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varpd256_mask(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varpd256_maskz(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd256_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varpd512_mask(
    long long __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varpd512_maskz(
    long long __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd512_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varps128_mask(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varps128_maskz(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps128_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varps256_mask(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varps256_maskz(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps256_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varps512_mask(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varps512_maskz(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varps512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps512_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varq128_maskz(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq128_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varq256_maskz(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq256_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varq512_maskz(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq512_maskz((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varqi128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varqi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varqi128_maskz(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varqi128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi128_maskz((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varqi256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varqi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varqi256_maskz(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varqi256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi256_maskz((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varqi512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_vpermt2varqi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varqi512_maskz(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_vpermt2varqi512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vplzcntd_128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntd_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntd_128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vplzcntd_256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntd_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntd_256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vplzcntd_512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_vplzcntd_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntd_512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vplzcntq_128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntq_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntq_128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vplzcntq_256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntq_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntq_256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vplzcntq_512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntq_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntq_512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52huq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52huq128_maskz(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq128_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52huq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52huq256_maskz(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq256_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52huq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52huq512_maskz(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq512_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52luq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52luq128_maskz(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq128_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52luq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52luq256_maskz(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq256_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52luq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52luq512_maskz(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    const int __c,
    int __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldd128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldd128_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const int __c,
    int __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldd256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldd256_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    const int __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshldd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldd512_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    const int __c,
    long long __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldq128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldq128_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const int __c,
    long long __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldq256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldq256_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    const int __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldq512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldq512_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    const int __c,
    short __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldw128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldw128_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldw256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    const int __c,
    short __attribute__((vector_size(32))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshldw256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldw256_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    const int __c,
    short __attribute__((vector_size(64))) __d,
    unsigned int __e);
#define __builtin_ia32_vpshldw512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldw512_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    const int __c,
    int __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdd128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdd128_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const int __c,
    int __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdd256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdd256_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    const int __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshrdd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdd512_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    const int __c,
    long long __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdq128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdq128_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const int __c,
    long long __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdq256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdq256_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    const int __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdq512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdq512_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    const int __c,
    short __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdw128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdw128_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdw256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    const int __c,
    short __attribute__((vector_size(32))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshrdw256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdw256_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    const int __c,
    short __attribute__((vector_size(64))) __d,
    unsigned int __e);
#define __builtin_ia32_vpshrdw512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdw512_mask((P0), (P1), (P2), (P3), (P4))

extern double
__coverity___nvvm_atom_add_g_d(
    volatile double* __a,
    double __b);
#define __nvvm_atom_add_g_d(P0, P1) \
    __coverity___nvvm_atom_add_g_d((P0), (P1))

extern float
__coverity___nvvm_atom_add_g_f(
    volatile float* __a,
    float __b);
#define __nvvm_atom_add_g_f(P0, P1) \
    __coverity___nvvm_atom_add_g_f((P0), (P1))

extern int
__coverity___nvvm_atom_add_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_add_g_i(P0, P1) \
    __coverity___nvvm_atom_add_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_add_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_add_g_l(P0, P1) \
    __coverity___nvvm_atom_add_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_add_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_add_g_ll(P0, P1) \
    __coverity___nvvm_atom_add_g_ll((P0), (P1))

extern double
__coverity___nvvm_atom_add_s_d(
    volatile double* __a,
    double __b);
#define __nvvm_atom_add_s_d(P0, P1) \
    __coverity___nvvm_atom_add_s_d((P0), (P1))

extern float
__coverity___nvvm_atom_add_s_f(
    volatile float* __a,
    float __b);
#define __nvvm_atom_add_s_f(P0, P1) \
    __coverity___nvvm_atom_add_s_f((P0), (P1))

extern int
__coverity___nvvm_atom_add_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_add_s_i(P0, P1) \
    __coverity___nvvm_atom_add_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_add_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_add_s_l(P0, P1) \
    __coverity___nvvm_atom_add_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_add_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_add_s_ll(P0, P1) \
    __coverity___nvvm_atom_add_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_and_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_and_g_i(P0, P1) \
    __coverity___nvvm_atom_and_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_and_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_and_g_l(P0, P1) \
    __coverity___nvvm_atom_and_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_and_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_and_g_ll(P0, P1) \
    __coverity___nvvm_atom_and_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_and_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_and_s_i(P0, P1) \
    __coverity___nvvm_atom_and_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_and_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_and_s_l(P0, P1) \
    __coverity___nvvm_atom_and_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_and_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_and_s_ll(P0, P1) \
    __coverity___nvvm_atom_and_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_cas_g_i(
    volatile int* __a,
    int __b,
    int __c);
#define __nvvm_atom_cas_g_i(P0, P1, P2) \
    __coverity___nvvm_atom_cas_g_i((P0), (P1), (P2))

extern long
__coverity___nvvm_atom_cas_g_l(
    volatile long* __a,
    long __b,
    long __c);
#define __nvvm_atom_cas_g_l(P0, P1, P2) \
    __coverity___nvvm_atom_cas_g_l((P0), (P1), (P2))

extern long long
__coverity___nvvm_atom_cas_g_ll(
    volatile long long* __a,
    long long __b,
    long long __c);
#define __nvvm_atom_cas_g_ll(P0, P1, P2) \
    __coverity___nvvm_atom_cas_g_ll((P0), (P1), (P2))

extern int
__coverity___nvvm_atom_cas_s_i(
    volatile int* __a,
    int __b,
    int __c);
#define __nvvm_atom_cas_s_i(P0, P1, P2) \
    __coverity___nvvm_atom_cas_s_i((P0), (P1), (P2))

extern long
__coverity___nvvm_atom_cas_s_l(
    volatile long* __a,
    long __b,
    long __c);
#define __nvvm_atom_cas_s_l(P0, P1, P2) \
    __coverity___nvvm_atom_cas_s_l((P0), (P1), (P2))

extern long long
__coverity___nvvm_atom_cas_s_ll(
    volatile long long* __a,
    long long __b,
    long long __c);
#define __nvvm_atom_cas_s_ll(P0, P1, P2) \
    __coverity___nvvm_atom_cas_s_ll((P0), (P1), (P2))

extern unsigned int
__coverity___nvvm_atom_dec_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_dec_g_ui(P0, P1) \
    __coverity___nvvm_atom_dec_g_ui((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_dec_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_dec_s_ui(P0, P1) \
    __coverity___nvvm_atom_dec_s_ui((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_inc_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_inc_g_ui(P0, P1) \
    __coverity___nvvm_atom_inc_g_ui((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_inc_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_inc_s_ui(P0, P1) \
    __coverity___nvvm_atom_inc_s_ui((P0), (P1))

extern int
__coverity___nvvm_atom_max_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_max_g_i(P0, P1) \
    __coverity___nvvm_atom_max_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_max_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_max_g_l(P0, P1) \
    __coverity___nvvm_atom_max_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_max_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_max_g_ll(P0, P1) \
    __coverity___nvvm_atom_max_g_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_max_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_max_g_ui(P0, P1) \
    __coverity___nvvm_atom_max_g_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_max_g_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_max_g_ul(P0, P1) \
    __coverity___nvvm_atom_max_g_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_max_g_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_max_g_ull(P0, P1) \
    __coverity___nvvm_atom_max_g_ull((P0), (P1))

extern int
__coverity___nvvm_atom_max_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_max_s_i(P0, P1) \
    __coverity___nvvm_atom_max_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_max_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_max_s_l(P0, P1) \
    __coverity___nvvm_atom_max_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_max_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_max_s_ll(P0, P1) \
    __coverity___nvvm_atom_max_s_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_max_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_max_s_ui(P0, P1) \
    __coverity___nvvm_atom_max_s_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_max_s_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_max_s_ul(P0, P1) \
    __coverity___nvvm_atom_max_s_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_max_s_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_max_s_ull(P0, P1) \
    __coverity___nvvm_atom_max_s_ull((P0), (P1))

extern int
__coverity___nvvm_atom_min_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_min_g_i(P0, P1) \
    __coverity___nvvm_atom_min_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_min_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_min_g_l(P0, P1) \
    __coverity___nvvm_atom_min_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_min_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_min_g_ll(P0, P1) \
    __coverity___nvvm_atom_min_g_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_min_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_min_g_ui(P0, P1) \
    __coverity___nvvm_atom_min_g_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_min_g_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_min_g_ul(P0, P1) \
    __coverity___nvvm_atom_min_g_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_min_g_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_min_g_ull(P0, P1) \
    __coverity___nvvm_atom_min_g_ull((P0), (P1))

extern int
__coverity___nvvm_atom_min_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_min_s_i(P0, P1) \
    __coverity___nvvm_atom_min_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_min_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_min_s_l(P0, P1) \
    __coverity___nvvm_atom_min_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_min_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_min_s_ll(P0, P1) \
    __coverity___nvvm_atom_min_s_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_min_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_min_s_ui(P0, P1) \
    __coverity___nvvm_atom_min_s_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_min_s_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_min_s_ul(P0, P1) \
    __coverity___nvvm_atom_min_s_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_min_s_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_min_s_ull(P0, P1) \
    __coverity___nvvm_atom_min_s_ull((P0), (P1))

extern int
__coverity___nvvm_atom_or_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_or_g_i(P0, P1) \
    __coverity___nvvm_atom_or_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_or_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_or_g_l(P0, P1) \
    __coverity___nvvm_atom_or_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_or_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_or_g_ll(P0, P1) \
    __coverity___nvvm_atom_or_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_or_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_or_s_i(P0, P1) \
    __coverity___nvvm_atom_or_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_or_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_or_s_l(P0, P1) \
    __coverity___nvvm_atom_or_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_or_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_or_s_ll(P0, P1) \
    __coverity___nvvm_atom_or_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_sub_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_sub_g_i(P0, P1) \
    __coverity___nvvm_atom_sub_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_sub_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_sub_g_l(P0, P1) \
    __coverity___nvvm_atom_sub_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_sub_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_sub_g_ll(P0, P1) \
    __coverity___nvvm_atom_sub_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_sub_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_sub_s_i(P0, P1) \
    __coverity___nvvm_atom_sub_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_sub_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_sub_s_l(P0, P1) \
    __coverity___nvvm_atom_sub_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_sub_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_sub_s_ll(P0, P1) \
    __coverity___nvvm_atom_sub_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xchg_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xchg_g_i(P0, P1) \
    __coverity___nvvm_atom_xchg_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_xchg_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xchg_g_l(P0, P1) \
    __coverity___nvvm_atom_xchg_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xchg_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xchg_g_ll(P0, P1) \
    __coverity___nvvm_atom_xchg_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xchg_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xchg_s_i(P0, P1) \
    __coverity___nvvm_atom_xchg_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_xchg_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xchg_s_l(P0, P1) \
    __coverity___nvvm_atom_xchg_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xchg_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xchg_s_ll(P0, P1) \
    __coverity___nvvm_atom_xchg_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xor_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xor_g_i(P0, P1) \
    __coverity___nvvm_atom_xor_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_xor_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xor_g_l(P0, P1) \
    __coverity___nvvm_atom_xor_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xor_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xor_g_ll(P0, P1) \
    __coverity___nvvm_atom_xor_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xor_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xor_s_i(P0, P1) \
    __coverity___nvvm_atom_xor_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_xor_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xor_s_l(P0, P1) \
    __coverity___nvvm_atom_xor_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xor_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xor_s_ll(P0, P1) \
    __coverity___nvvm_atom_xor_s_ll((P0), (P1))

/* } Removed in Clang 7.0 */
#endif // clang < 7.0

// XCode 10 - No changes from Clang 6

#if defined(__cplusplus)
} /* extern "C" */
#endif

#endif /* COVERITY_COMPAT_f7d41afe550542f7c525a437cfc2a76c */
#endif /* __COVERITY__ */
