/*
 * Copyright (c) 2024, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef  __QSORT_H__
#define  __QSORT_H__

#include <stddef.h>
#include <stdint.h>

#define CMP_TRILEAN(a, b) \
	(__extension__({ \
		__typeof__(a) _a = (a); \
		__typeof__(b) _b = (b); \
		\
		_a > _b ? 1 : _a < _b ? -1 : 0; \
	}))

void qsort_int(int *aa, size_t n);
void qsort_uint(unsigned int *aa, size_t n);
void qsort_long(long int *aa, size_t n);
void qsort_ul(unsigned long int *aa, size_t n);
void qsort_ll(long long *aa, size_t n);
void qsort_ull(unsigned long long int *aa, size_t n);
void qsort_s8(int8_t *aa, size_t n);
void qsort_u8(uint8_t *aa, size_t n);
void qsort_s16(int16_t *aa, size_t n);
void qsort_u16(uint16_t *aa, size_t n);
void qsort_s32(int32_t *aa, size_t n);
void qsort_u32(uint32_t *aa, size_t n);
void qsort_s64(int64_t *aa, size_t n);
void qsort_u64(uint64_t *aa, size_t n);

#endif   /* ----- #ifndef __QSORT_H__  ----- */
