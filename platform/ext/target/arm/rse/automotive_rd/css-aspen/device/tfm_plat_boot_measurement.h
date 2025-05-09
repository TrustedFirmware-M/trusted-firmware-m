/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __BOOT_MEASUREMENT_H__
#define __BOOT_MEASUREMENT_H__

enum boot_measurement_slot_t {
    BOOT_MEASUREMENT_SLOT_BL1_2 = 0,
    BOOT_MEASUREMENT_SLOT_BL2,
    BOOT_MEASUREMENT_SLOT_RT_0,
    BOOT_MEASUREMENT_SLOT_RESERVED, /* Unused */
    BOOT_MEASUREMENT_SLOT_AP_BL2,
    BOOT_MEASUREMENT_SLOT_SI_CL0,
    BOOT_MEASUREMENT_SLOT_CM_ROTPK_0,
    BOOT_MEASUREMENT_SLOT_CM_ROTPK_1,
    BOOT_MEASUREMENT_SLOT_CM_ROTPK_2,
    BOOT_MEASUREMENT_SLOT_CM_ROTPK_3,
    BOOT_MEASUREMENT_SLOT_DM_ROTPK_0,
    BOOT_MEASUREMENT_SLOT_DM_ROTPK_1,
    BOOT_MEASUREMENT_SLOT_DM_ROTPK_2,
    BOOT_MEASUREMENT_SLOT_DM_ROTPK_3,
    BOOT_MEASUREMENT_SLOT_MAX = 32,
    BOOT_MEASUREMENT_SLOT_MAX_THEORETICAL = 63  /* Slot index is stored in
                                                 * 6 bits in the shared
                                                 * memory area.
                                                 */
};

/* Default size for `sw_type` string borrowed from definition
   in `boot_measurement_metadata` */
extern char boot_measurement_sw_type[BOOT_MEASUREMENT_SLOT_DM_ROTPK_3 + 1][10];

#endif /* __BOOT_MEASUREMENT_H__ */
