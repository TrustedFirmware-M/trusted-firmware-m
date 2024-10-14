/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __IMAGE_SIZE_DEFS_H__
#define __IMAGE_SIZE_DEFS_H__

/* BL2 */
#define SIZE_DEF_BL2_IMAGE          (0x20000) /* 128 KB */

/* Secure Firmware */
#define SIZE_DEF_S_IMAGE            (0x40000) /* 256 KB */

/* Non-Secure Firmware */
#define SIZE_DEF_NS_IMAGE           (0x0)     /* 0 KB */

/* Host Firmware */
#define SIZE_DEF_AP_BL2_IMAGE       (0x80000) /* 512 KB */
#define SIZE_DEF_SI_CL0_IMAGE       (0x100000)/* 1024 KB */

#endif /* __IMAGE_SIZE_DEFS_H__ */
