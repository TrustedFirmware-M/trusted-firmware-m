/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _ENDIAN_H_
#define _ENDIAN_H_

#include <stdint.h>
#include "cmsis_compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline uint16_t bswap_16(uint16_t in)
{
    return __REVSH((in));
}

static inline uint32_t bswap_32(uint32_t in)
{
    return __REV((in));
}

static inline uint64_t bswap_64(uint64_t in)
{
    return __REV(in >> 32) | (uint64_t)__REV(0xFFFFFFFF & in) << 32;
}

/* LE to BE */
#define htobe16(x)  __REVSH((x))
#define htobe32(x)  __REV((x))
#define htobe64(x)  bswap_64((x))

/* BE to LE */
#define be16toh(x)  __REVSH((x))
#define be32toh(x)  __REV((x))
#define be64toh(x)  bswap_64((x))

#ifdef __cplusplus
}
#endif

#endif /*_ENDIAN_H_*/
