/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2024, STMicroelectronics - All Rights Reserved
 */

#include <stdlib.h>
#include <stdint.h>
#include <qsort.h>

static int qsort_cmp_int(const void *a, const void *b)
{
	const int *ia = a;
	const int *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_uint(const void *a, const void *b)
{
	const unsigned int *ia = a;
	const unsigned int *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_long(const void *a, const void *b)
{
	const long int *ia = a;
	const long int *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_ul(const void *a, const void *b)
{
	const unsigned long int *ia = a;
	const unsigned long int *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_ll(const void *a, const void *b)
{
	const long long int *ia = a;
	const long long int *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_ull(const void *a, const void *b)
{
	const unsigned long long int *ia = a;
	const unsigned long long int *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_s8(const void *a, const void *b)
{
	const int8_t *ia = a;
	const int8_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_u8(const void *a, const void *b)
{
	const uint8_t *ia = a;
	const uint8_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_s16(const void *a, const void *b)
{
	const int16_t *ia = a;
	const int16_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_u16(const void *a, const void *b)
{
	const uint16_t *ia = a;
	const uint16_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_s32(const void *a, const void *b)
{
	const int32_t *ia = a;
	const int32_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_u32(const void *a, const void *b)
{
	const uint32_t *ia = a;
	const uint32_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_s64(const void *a, const void *b)
{
	const int64_t *ia = a;
	const int64_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

static int qsort_cmp_u64(const void *a, const void *b)
{
	const uint64_t *ia = a;
	const uint64_t *ib = b;

	return CMP_TRILEAN(*ia, *ib);
}

void qsort_int(int *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_int);
}

void qsort_uint(unsigned int *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_uint);
}

void qsort_long(long int *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_long);
}

void qsort_ul(unsigned long int *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_ul);
}

void qsort_ll(long long *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_ll);
}

void qsort_ull(unsigned long long int *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_ull);
}

void qsort_s8(int8_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_s8);
}

void qsort_u8(uint8_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_u8);
}

void qsort_s16(int16_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_s16);
}

void qsort_u16(uint16_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_u16);
}

void qsort_s32(int32_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_s32);
}

void qsort_u32(uint32_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_u32);
}

void qsort_s64(int64_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_s64);
}

void qsort_u64(uint64_t *aa, size_t n)
{
	qsort(aa, n, sizeof(*aa), qsort_cmp_u64);
}
