/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __BL2_IMAGE_ID_H__
#define __BL2_IMAGE_ID_H__

/*
 * ID of firmware images loaded by BL2
 * Images are loaded by BL2 in reverse order of ID
 * Cannot use enum as this is included in linker files.
 */
/* RSE firmware */
#define RSE_FIRMWARE_SECURE_ID       0
#define RSE_FIRMWARE_NON_SECURE_ID   1
/* Host Firmware */
#define RSE_FIRMWARE_AP_BL1_ID       2
#define RSE_FIRMWARE_LCP_ID          3
#define RSE_FIRMWARE_MCP_ID          4
#define RSE_FIRMWARE_SCP_ID          5
/* Number of firmware loaded by BL2 */
#ifdef TFM_S_REG_TEST
#define RSE_FIRMWARE_COUNT           (RSE_FIRMWARE_NON_SECURE_ID + 1)
#else
#define RSE_FIRMWARE_COUNT           6
#endif

#endif /* __BL2_IMAGE_ID_H__ */
