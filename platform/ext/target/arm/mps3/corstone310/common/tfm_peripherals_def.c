/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_peripherals_def.h"
#include "tfm_utils.h"
#include "tfm_hal_device_header.h"

/* Allowed named MMIO of this platform */
const uintptr_t partition_named_mmio_list[] = {
    (uintptr_t)TFM_PERIPHERAL_TIMER0,
    (uintptr_t)TFM_PERIPHERAL_STD_UART,
#ifdef PSA_API_TEST_IPC
    (uintptr_t)FF_TEST_UART_REGION,
    (uintptr_t)FF_TEST_WATCHDOG_REGION,
    (uintptr_t)FF_TEST_NVMEM_REGION,
    (uintptr_t)FF_TEST_SERVER_PARTITION_MMIO,
    (uintptr_t)FF_TEST_DRIVER_PARTITION_MMIO,
#endif
#ifdef CORSTONE310_FVP
    (uintptr_t)TFM_PERIPHERAL_DMA0_CH0,
    (uintptr_t)TFM_PERIPHERAL_DMA0_CH1
#endif
};

void get_partition_named_mmio_list(const uintptr_t** list, size_t* length) {
    *list = partition_named_mmio_list;
    *length = ARRAY_SIZE(partition_named_mmio_list);
}
