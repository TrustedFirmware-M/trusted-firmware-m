/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __FLASH_LAYOUT_COMMON_H__
#define __FLASH_LAYOUT_COMMON_H__

#include "rse_memory_sizes.h"

#define SIC_PAGE_SIZE 1024
#define SIC_HASH_SIZE 32

#ifndef FLASH_SIC_TABLE_SIZE
#ifdef RSE_XIP
#define FLASH_SIC_TABLE_SIZE (((FLASH_MAX_PARTITION_SIZE + SIC_PAGE_SIZE - 1) / SIC_PAGE_SIZE) * SIC_HASH_SIZE) + \
                             BL2_HEADER_SIZE
#else
#define FLASH_SIC_TABLE_SIZE 0
#endif /* RSE_XIP */
#endif /* !FLASH_SIC_TABLE_SIZE */

/* Image load addresses used by imgtool.py. These must be secure addresses as
 * BL2 does the loading and runs as secure.
 */
#ifdef RSE_XIP
#define S_IMAGE_LOAD_ADDRESS            (VM0_BASE_S)
#define NS_IMAGE_LOAD_ADDRESS           (VM0_BASE_S + FLASH_SIC_TABLE_SIZE)
#else
#define S_IMAGE_LOAD_ADDRESS            (VM1_BASE_S + VM1_SIZE - \
                                         PERSISTENT_DATA_SIZE - \
                                         RSE_OTP_EMULATION_SRAM_SIZE - \
                                         FLASH_S_PARTITION_SIZE)
#define NS_IMAGE_LOAD_ADDRESS           (S_IMAGE_LOAD_ADDRESS - \
                                         FLASH_NS_PARTITION_SIZE)
#endif

#endif /* __FLASH_LAYOUT_COMMON_H__ */
