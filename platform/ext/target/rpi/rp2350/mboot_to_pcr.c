/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>

#include "tfm_boot_measurement.h"
#include "tfm_utils.h"

/*
 * ID here is set to measured boot slot value to uniqely
 * identify event log entries.
 */
static const event_log_metadata_t tfm_event_log_metadata[] = {
    { BOOT_MEASUREMENT_SLOT_BL2, "TFM_BL2", 0 },
    { BOOT_MEASUREMENT_SLOT_RT_0, "TFM_RT_0", 0 },
    { BOOT_MEASUREMENT_SLOT_RT_1, "TFM_RT_1", 0 },
    { BOOT_MEASUREMENT_SLOT_RT_2, "TFM_RT_2", 0 },
};

int8_t get_pcr_index_for_boot_measurement(uint8_t slot)
{
    if (slot >= BOOT_MEASUREMENT_SLOT_MAX) {
        return -1;
    }

    for (int i = 0; i < ARRAY_SIZE(tfm_event_log_metadata); i++) {
        if (tfm_event_log_metadata[i].id == slot) {
            return tfm_event_log_metadata[i].pcr;
        }
    }

    return -1;
}

int get_event_log_metadata_for_measurement_slot(uint8_t slot, event_log_metadata_t *event_log_metadata)
{
    if (slot >= BOOT_MEASUREMENT_SLOT_MAX) {
        return -1;
    }

    for (int i = 0; i < ARRAY_SIZE(tfm_event_log_metadata); i++) {
        if (tfm_event_log_metadata[i].id == slot) {
            memcpy(event_log_metadata, &tfm_event_log_metadata[slot], sizeof(event_log_metadata_t));
        }
    }

    return 0;
}
