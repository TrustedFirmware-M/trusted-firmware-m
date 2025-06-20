/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __STAGING_CONFIG_H__
#define __STAGING_CONFIG_H__

#include "flash_layout.h"
#include "host_base_address.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSE_GPT_SUPPORT
#define HOST_FIP_MAX_SIZE       (HOST_FLASH0_SIZE/2)
#define HOST_FLASH_FIP_A_OFFSET (0)
#else
#define HOST_FIP_MAX_SIZE       (FLASH_FIP_MAX_SIZE)
#define HOST_FLASH_FIP_A_OFFSET (FLASH_FIP_A_OFFSET)
#define HOST_FLASH_FIP_B_OFFSET (FLASH_FIP_B_OFFSET)
#endif

/* Logical source address - FIP_A */
#define HOST_FLASH_FIP_A_BASE_S             (HOST_FLASH_FIP_BASE_S + 0 * HOST_FIP_MAX_SIZE)
/* Physical source address - FIP_A */
#define HOST_FLASH_FIP_A_BASE_S_PHYSICAL    (HOST_FLASH0_BASE + HOST_FLASH_FIP_A_OFFSET)
/* Logical staging address - FIP_A */
#define STAGING_AREA_FIP_A_BASE_S           (HOST_FLASH_FIP_BASE_S + 1 * HOST_FIP_MAX_SIZE)
/* Physical staging address - FIP_A */
#define STAGING_AREA_FIP_A_BASE_S_PHYSICAL  (HOST_STAGING_MEM_BASE)

#ifndef RSE_GPT_SUPPORT
/* Logical source address - FIP_B */
#define HOST_FLASH_FIP_B_BASE_S             (HOST_FLASH_FIP_BASE_S + 2 * HOST_FIP_MAX_SIZE)
/* Physical source address - FIP_B */
#define HOST_FLASH_FIP_B_BASE_S_PHYSICAL    (HOST_FLASH0_BASE + HOST_FLASH_FIP_B_OFFSET)
/* Logical staging address - FIP_B */
#define STAGING_AREA_FIP_B_BASE_S           (HOST_FLASH_FIP_BASE_S + 3 * HOST_FIP_MAX_SIZE)
/* Physical staging address - FIP_B */
#define STAGING_AREA_FIP_B_BASE_S_PHYSICAL  (HOST_STAGING_MEM_BASE + HOST_FIP_MAX_SIZE)
#endif /* !RSE_GPT_SUPPORT */

#ifdef __cplusplus
}
#endif

#endif /* __STAGING_CONFIG_H__ */
