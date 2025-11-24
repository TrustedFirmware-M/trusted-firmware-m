/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "tfm_boot_measurement.h"

char boot_measurement_sw_type[BOOT_MEASUREMENT_SLOT_RT_2 + 1][SW_TYPE_LEN] = {
    [BOOT_MEASUREMENT_SLOT_BL2] = "BL2",
    [BOOT_MEASUREMENT_SLOT_RT_0] = "RT_0",
    [BOOT_MEASUREMENT_SLOT_RT_1] = "RT_1",
    [BOOT_MEASUREMENT_SLOT_RT_2] = "RT_2",
};
