/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "common_target_cfg.h"
#include "tfm_hal_platform.h"
#include "tfm_peripherals_def.h"
#include "uart_stdout.h"
#include "device_definition.h"
#include "rse_clocks.h"
#include "rse_sam_config.h"
#ifdef TFM_PARTITION_PROTECTED_STORAGE
#include "host_base_address.h"
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
#define RSE_ATU_REGION_PS_SLOT  16
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

extern const struct memory_region_limits memory_regions;

enum tfm_hal_status_t tfm_hal_platform_init(void)
{
    enum tfm_plat_err_t plat_err = TFM_PLAT_ERR_SYSTEM_ERR;
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    enum atu_error_t err;
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

    if (rse_clock_config() != 0) {
        return TFM_HAL_ERROR_GENERIC;
    }
    SystemCoreClockUpdate();

    plat_err = enable_fault_handlers();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = system_reset_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = init_debug();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    __enable_irq();
    stdio_init();

    plat_err = rse_sam_init(RSE_SAM_INIT_SETUP_FULL);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = nvic_interrupt_target_state_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = nvic_interrupt_enable();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

    plat_err = dma_init_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_HAL_ERROR_GENERIC;
    }

#ifdef TFM_PARTITION_PROTECTED_STORAGE
    /* Initialize PS region */
    err = atu_initialize_region(&ATU_DEV_S,
                                RSE_ATU_REGION_PS_SLOT,
                                HOST_ACCESS_PS_BASE_S,
                                HOST_FLASH0_PS_BASE,
                                HOST_FLASH0_PS_SIZE);
    if (err != ATU_ERR_NONE) {
        return TFM_HAL_ERROR_GENERIC;
    }
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

    return TFM_HAL_SUCCESS;
}

uint32_t tfm_hal_get_ns_VTOR(void)
{
#ifndef TFM_LOAD_NS_IMAGE
    /* If an NS image hasn't been set up, then just return 0 */
    return 0;
#endif

    return memory_regions.non_secure_code_start;
}

uint32_t tfm_hal_get_ns_MSP(void)
{
#ifndef TFM_LOAD_NS_IMAGE
    /* If an NS image hasn't been set up, then just return 0 */
    return 0;
#endif

    return *((uint32_t *)memory_regions.non_secure_code_start);
}

uint32_t tfm_hal_get_ns_entry_point(void)
{
#ifndef TFM_LOAD_NS_IMAGE
    /* If an NS image hasn't been set up, then just return 0 */
    return 0;
#endif

    return *((uint32_t *)(memory_regions.non_secure_code_start + 4));
}
