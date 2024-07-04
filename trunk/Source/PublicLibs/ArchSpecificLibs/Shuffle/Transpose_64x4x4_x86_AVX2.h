/* Transpose_64x4x4_x86_AVX2.h
 * 
 *  Author          : Alexander J. Yee
 *  Date Created    : 08/30/2015
 *  Last Modified   : 03/10/2024
 * 
 */

#pragma once
#ifndef ymp_Transpose_64x4x4_x86_AVX2_H
#define ymp_Transpose_64x4x4_x86_AVX2_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <immintrin.h>
#include "PublicLibs/CompilerSettings.h"
namespace ymp{
namespace SIMD{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
YM_FORCE_INLINE void transpose_i64x4x4_x86_AVX2(__m256i& r0, __m256i& r1, __m256i& r2, __m256i& r3){
    __m256i a0, a1, a2, a3;
    a0 = _mm256_permute2x128_si256(r0, r2, 32);
    a1 = _mm256_permute2x128_si256(r0, r2, 49);
    a2 = _mm256_permute2x128_si256(r1, r3, 32);
    a3 = _mm256_permute2x128_si256(r1, r3, 49);
    r0 = _mm256_unpacklo_epi64(a0, a2);
    r1 = _mm256_unpackhi_epi64(a0, a2);
    r2 = _mm256_unpacklo_epi64(a1, a3);
    r3 = _mm256_unpackhi_epi64(a1, a3);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif
