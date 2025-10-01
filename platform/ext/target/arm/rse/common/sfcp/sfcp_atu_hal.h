/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_ATU_HAL_H__
#define __SFCP_ATU_HAL_H__

#ifndef RSE_XIP
#define SFCP_ATU_REGION_MIN 0
#else
#define SFCP_ATU_REGION_MIN 2
#endif /* !RSE_XIP */

#define SFCP_ATU_REGION_MAX 15
/* There must be at least one region */
#define SFCP_ATU_REGION_AM (SFCP_ATU_REGION_MAX - SFCP_ATU_REGION_MIN + 1)
#define SFCP_ATU_PAGE_SIZE 0x2000
#define SFCP_ATU_REGION_SIZE (SFCP_ATU_PAGE_SIZE * 8)

#endif /* __SFCP_HAL_H__ */
