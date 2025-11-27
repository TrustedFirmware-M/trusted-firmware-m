/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "target_cfg.h"
#include "cmsis.h"
#include "protection_regions_cfg.h"

/* To write into AIRCR register, 0x5FA value must be write to the VECTKEY field,
 * otherwise the processor ignores the write.
 */
#define SCB_AIRCR_WRITE_MASK    ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos))

FIH_RET_TYPE(enum tfm_plat_err_t) ifx_system_reset_cfg(void)
{
    uint32_t reg_value = SCB->AIRCR;

    /* Clear SCB_AIRCR_VECTKEY value */
    reg_value &= ~(uint32_t)(SCB_AIRCR_VECTKEY_Msk);

    /* Enable system reset request only to the secure world */
    reg_value |= (uint32_t)(SCB_AIRCR_WRITE_MASK | SCB_AIRCR_SYSRESETREQS_Msk);

    SCB->AIRCR = reg_value;

#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that system reset request is enabled to the secure world only */
    if ((SCB->AIRCR & SCB_AIRCR_SYSRESETREQS_Msk) != SCB_AIRCR_SYSRESETREQS_Msk) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }
#endif /* TFM_FIH_PROFILE_ON */

    FIH_RET(TFM_PLAT_ERR_SUCCESS);
}

enum tfm_plat_err_t ifx_init_debug(void)
{
#if !defined(DAUTH_CHIP_DEFAULT)
    #error "Debug features are set during provisioning."
#endif
    return TFM_PLAT_ERR_SUCCESS;
}

FIH_RET_TYPE(enum tfm_plat_err_t) ifx_nvic_interrupt_target_state_cfg(void)
{
    const uint32_t itns_amount = sizeof(NVIC->ITNS)/sizeof(NVIC->ITNS[0]);
#ifdef CONFIG_TFM_USE_TRUSTZONE
    /* Target every interrupt to NS; unimplemented interrupts will be WI */
    for (uint32_t idx = 0UL; idx < itns_amount; idx++) {
        NVIC->ITNS[idx] = 0xFFFFFFFFU;
    }

    /* Mask interrupts as secure from corresponding list */
    for (uint32_t idx = 0UL; idx < ifx_secure_interrupts_config_count; idx++) {
        (void)NVIC_ClearTargetState(ifx_secure_interrupts_config[idx]);
    }

#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that interrupts ware marked as secure */
    for (uint32_t idx = 0UL; idx < ifx_secure_interrupts_config_count; idx++) {
        if (NVIC_GetTargetState(ifx_secure_interrupts_config[idx]) != 0U) {
            FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
        }
    }
#endif /* TFM_FIH_PROFILE_ON */
#else
    /* If CM33 NSPE is not present then there are no non-secure interrupts */
    /* Target every interrupt to S; unimplemented interrupts will be WI */
    for (uint32_t idx = 0UL; idx < itns_amount; idx++) {
        /* Target every interrupt to S; unimplemented interrupts will be WI */
        NVIC->ITNS[idx] = 0x0;
    }

#if TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that interrupts ware marked as secure */
    for (uint32_t idx = 0UL; idx < itns_amount; idx++) {
        if (NVIC->ITNS[idx] != 0) {
            FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
        }
    }
#endif /* TFM_FIH_PROFILE_ON */
#endif /* CONFIG_TFM_USE_TRUSTZONE */

    FIH_RET(TFM_PLAT_ERR_SUCCESS);
}

enum tfm_plat_err_t ifx_init_system_control_block(void)
{
    /* Make Deep Sleep Control accessible to SPE only */
    SCB->SCR = (SCB->SCR & ~(SCB_SCR_SLEEPDEEPS_Msk)) |
               _VAL2FLD(SCB_SCR_SLEEPDEEPS, 1);

    return TFM_PLAT_ERR_SUCCESS;
}
