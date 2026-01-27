/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "faults.h"
#include "ifx_fih.h"
#include "ifx_boot_shared_data.h"
#include "tfm_hal_platform.h"
#include "region_defs.h"
#include "cmsis.h"
#include "target_cfg.h"
#include "uart_stdout.h"
#include "coverity_check.h"
#ifdef TEST_S_FPU
#include "ifx_fpu_s.h"
#endif /* TEST_S_FPU */

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_platform_init(void)
{
    enum tfm_plat_err_t plat_err = TFM_PLAT_ERR_SYSTEM_ERR;
    IFX_FIH_DECLARE(enum tfm_plat_err_t, fih_plat_err, TFM_PLAT_ERR_SYSTEM_ERR);

#ifdef BOOT_DATA_AVAILABLE
    /* Mock boot shared data if it is not present */
    ifx_mock_boot_shared_data_if_not_present();
#endif /* BOOT_DATA_AVAILABLE */

    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_20_7, "Cannot wrap with parentheses due to Fault injection architecture and define FIH_RET_TYPE")
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_10_4, "Cannot change types due to Fault injection architecture")
    FIH_CALL(ifx_system_reset_cfg, fih_plat_err);
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change not equal logic due to Fault injection architecture and define FIH_NOT_EQ")
    if (FIH_NOT_EQ(fih_plat_err, TFM_PLAT_ERR_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    plat_err = ifx_init_debug();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    FIH_CALL(ifx_nvic_interrupt_target_state_cfg, fih_plat_err);
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change not equal logic due to Fault injection architecture and define FIH_NOT_EQ")
    if (FIH_NOT_EQ(fih_plat_err, TFM_PLAT_ERR_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

    __enable_irq();

#if IFX_UART_ENABLED
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_2_2, "Parameters can be changed by user and this code will make effect")
    stdio_init();
#endif

    FIH_CALL(ifx_faults_interrupt_enable, fih_plat_err);
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_10_1, "Cannot change not equal logic due to Fault injection architecture and define FIH_NOT_EQ")
    if (FIH_NOT_EQ(fih_plat_err, TFM_PLAT_ERR_SUCCESS)) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_10_4)
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_20_7)

    plat_err = ifx_init_system_control_block();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(TFM_HAL_ERROR_GENERIC);
    }

#ifdef TEST_S_FPU
    tfm_test_s_fpu_init();
#endif /* TEST_S_FPU */

    FIH_RET(TFM_HAL_SUCCESS);
}

#ifdef TFM_PARTITION_NS_AGENT_MAILBOX
uint32_t tfm_hal_get_ns_VTOR_off_core(void)
{
    return IFX_OFF_CORE_NSPE_BOOT_ADDR;
}
#endif /* TFM_PARTITION_NS_AGENT_MAILBOX */

#ifdef TFM_PARTITION_NS_AGENT_TZ
uint32_t tfm_hal_get_ns_VTOR(void)
{
    return IFX_CM33_NS_CODE_START;
}

uint32_t tfm_hal_get_ns_MSP(void)
{
    return *((uint32_t *)IFX_CM33_NS_CODE_START);
}

uint32_t tfm_hal_get_ns_entry_point(void)
{
    return *((uint32_t *)(IFX_CM33_NS_CODE_START + 4U));
}
#endif /* TFM_PARTITION_NS_AGENT_TZ */
