/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_boot_measurement.h"
#include "string.h"

static int8_t pcr_index_for_boot_measurement[BOOT_MEASUREMENT_SLOT_MAX] = {0};

static const event_log_metadata_t tfm_event_log_metadata[] = {
    { BOOT_MEASUREMENT_SLOT_BL2, "TFM_BL2", 0 },
    { BOOT_MEASUREMENT_SLOT_RT_0, "TFM_RT_0", 0 },
    { BOOT_MEASUREMENT_SLOT_RT_1, "TFM_RT_1", 0 },
    { BOOT_MEASUREMENT_SLOT_RT_2, "TFM_RT_2", 0 },
};

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

int get_event_log_metadata_for_measurement_slot(uint8_t slot, event_log_metadata_t *event_log_metadata)
{
    size_t metadata_arr_size = sizeof(tfm_event_log_metadata)/sizeof(tfm_event_log_metadata[0]);

    if (slot > (metadata_arr_size - 1)) {
        return -1;
    }

    memcpy(event_log_metadata, &tfm_event_log_metadata[slot], sizeof(event_log_metadata_t));

    return 0;
}
