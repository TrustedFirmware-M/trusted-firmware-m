/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PLATFORM_DCU_H__
#define __PLATFORM_DCU_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Bits 0-31 of 128 are assigned to RSE */
#define PLAT_RSE_DCU_LOCK0_VALUE        0xFFFFFFFF

/* Platform specific bit values - default lock everything */
#define PLAT_NOT_RSE_DCU_LOCK1_VALUE    0xFFFFFFFF
#define PLAT_NOT_RSE_DCU_LOCK2_VALUE    0xFFFFFFFF
#define PLAT_NOT_RSE_DCU_LOCK3_VALUE    0xFFFFFFFF

/* Mask of negated bits in DCU */
#define DCU_NEG_MASK_REG0 0xAAAAAAAA
#define DCU_NEG_MASK_REG1 0x00000000
#define DCU_NEG_MASK_REG2 0x00000000
#define DCU_NEG_MASK_REG3 0x00000000

#define DCU_RSE_DEBUG_MASK_REG0 0xFFFFFFFF
#define DCU_RSE_DEBUG_MASK_REG1 0x00000000
#define DCU_RSE_DEBUG_MASK_REG2 0x00000000
#define DCU_RSE_DEBUG_MASK_REG3 0x00000000

#ifdef __cplusplus
}
#endif

#endif /* __PLATFORM_DCU_H__ */
