/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_peripherals_def.h"
#include "tfm_utils.h"
#include "tfm_hal_device_header.h"
#include <stdint.h>
#include <stddef.h>

/* Allowed named MMIO of this platform */
static const uintptr_t partition_named_mmio_list[] = {
    (uintptr_t)TFM_PERIPHERAL_TIMER0,
    (uintptr_t)TFM_PERIPHERAL_STD_UART,
};

void get_partition_named_mmio_list(const uintptr_t** list, size_t* length) {
    *list = partition_named_mmio_list;
    *length = ARRAY_SIZE(partition_named_mmio_list);
}
