/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_ATU_HAL_H__
#define __RSE_COMMS_ATU_HAL_H__

#ifndef RSE_XIP
#define RSE_COMMS_ATU_REGION_MIN        0
#else
#define RSE_COMMS_ATU_REGION_MIN        2
#endif /* !RSE_XIP */

#define RSE_COMMS_ATU_REGION_MAX        15
/* There must be at least one region */
#define RSE_COMMS_ATU_REGION_AM         (RSE_COMMS_ATU_REGION_MAX - \
                                         RSE_COMMS_ATU_REGION_MIN + 1)
#define RSE_COMMS_ATU_PAGE_SIZE         0x2000
#define RSE_COMMS_ATU_REGION_SIZE       (RSE_COMMS_ATU_PAGE_SIZE * 8)

#endif /* __RSE_COMMS_HAL_H__ */
