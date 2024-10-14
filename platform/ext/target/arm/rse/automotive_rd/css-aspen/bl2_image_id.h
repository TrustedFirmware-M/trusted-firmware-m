/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file bl2_image_id.h
 * \brief This file contains the IDs of firmware images loaded by BL2.
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
#define RSE_FIRMWARE_AP_BL2_ID       2
#define RSE_FIRMWARE_SI_CL0_ID       3
/* Number of firmware loaded by BL2 */
#define RSE_FIRMWARE_COUNT           4

#endif /* __BL2_IMAGE_ID_H__ */
