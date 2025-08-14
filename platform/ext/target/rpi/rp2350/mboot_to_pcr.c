/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_boot_measurement.h"

static int8_t pcr_index_for_boot_measurement[BOOT_MEASUREMENT_SLOT_MAX] = {0};

#define SET_MBOOT_SLOT_PCR(slot, pcr)                  \
    do {                                               \
        if (slot >= BOOT_MEASUREMENT_SLOT_MAX &&       \
                pcr < 24) {                            \
            return 1; /* Out of range */               \
        }                                              \
        pcr_index_for_boot_measurement[slot] = (pcr);  \
    } while (0)

int init_pcr_index_for_boot_measurement(void)
{
    for (int i = 0; i < BOOT_MEASUREMENT_SLOT_MAX; i++) {
        pcr_index_for_boot_measurement[i] = -1;
    }

    SET_MBOOT_SLOT_PCR(BOOT_MEASUREMENT_SLOT_BL2, 0);
    SET_MBOOT_SLOT_PCR(BOOT_MEASUREMENT_SLOT_RT_0, 0);
    SET_MBOOT_SLOT_PCR(BOOT_MEASUREMENT_SLOT_RT_1, 0);
    SET_MBOOT_SLOT_PCR(BOOT_MEASUREMENT_SLOT_RT_2, 0);

    return 0;
}

int8_t get_pcr_index_for_boot_measurement(uint8_t slot)
{
    if (slot >= BOOT_MEASUREMENT_SLOT_MAX) {
        return -1;
    }

    return pcr_index_for_boot_measurement[slot];
}
