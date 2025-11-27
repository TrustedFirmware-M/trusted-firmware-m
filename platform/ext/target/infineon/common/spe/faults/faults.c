/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "cmsis.h"
#include "cy_sysfault.h"
#include "cyip_fault.h"
#include "exception_info.h"
#include "faults.h"
#include "ifx_utils.h"
#include "ifx_tfm_log_shim.h"
#include "protection_regions_cfg.h"
#include "utilities.h"

/* Enables BUS, MEM, USG and Secure faults */
#define SCB_SHCSR_ENABLED_FAULTS    (SCB_SHCSR_USGFAULTENA_Msk | \
                                     SCB_SHCSR_BUSFAULTENA_Msk | \
                                     SCB_SHCSR_MEMFAULTENA_Msk | \
                                     SCB_SHCSR_SECUREFAULTENA_Msk)

#ifdef TFM_FIH_PROFILE_ON
/* IMPROVEMENT: Cy_SysFault_GetMaskByIdx should be moved to PDL (DRIVERS-19403) */
static bool Cy_SysFault_GetMaskByIdx(const FAULT_STRUCT_Type *base, cy_en_SysFault_source_t idx)
{
    uint32_t mask = 0;

    CY_ASSERT_L3(idx < CY_SYSFAULT_NO_FAULT);
/* Fixes coverity negative_shift warning by making idx unsigned */
    uint32_t uint_idx = (uint32_t)idx;
    switch(((cy_en_SysFault_Set_t)(uint_idx / 32UL)))
    {
        case CY_SYSFAULT_SET0:
        {
            mask = (FAULT_MASK0(base) & (1UL << uint_idx)) >> uint_idx;
        }
        break;

        case CY_SYSFAULT_SET1:
        {
            mask = (FAULT_MASK1(base) & (1UL << (uint_idx - 32U))) >> (uint_idx - 32U);
        }
        break;

        case CY_SYSFAULT_SET2:
        {
            mask = (FAULT_MASK2(base) & (1UL << (uint_idx - 64U))) >> (uint_idx - 64U);
        }
        break;

        default:
        {
            CY_ASSERT_L3(0);
        }
        break;
    }

    return mask != 0U;
}
#endif /* TFM_FIH_PROFILE_ON */

FIH_RET_TYPE(enum tfm_plat_err_t) ifx_faults_cfg(void)
{
    /* Enable Fault interrupts for secure violation sources */
    for (uint32_t idx = 0UL; idx < ifx_fault_sources_fault_struct0_count; idx++) {
        Cy_SysFault_SetMaskByIdx(FAULT_STRUCT0, ifx_fault_sources_fault_struct0[idx]);
    }

#ifdef IFX_FAULTS_INFO_DUMP
    cy_en_SysFault_source_t fault_source = Cy_SysFault_GetErrorSource(FAULT_STRUCT0);
    if ((uint8_t)fault_source != CY_SYSFAULT_NO_FAULT) {
        /* Dump faults captured before reset */
        ERROR_RAW("========================================\n"
                  "Platform Exceptions captured on reset...\n");
        /* ifx_faults_dump() logs each Pending Fault and clears the Fault STATUS for each */
        ifx_faults_dump();
        ERROR_RAW("========================================\n");
    }
#else
    while ((uint8_t)Cy_SysFault_GetErrorSource(FAULT_STRUCT0) != CY_SYSFAULT_NO_FAULT) {
        Cy_SysFault_ClearStatus(FAULT_STRUCT0);
    }
#endif

    /* Set UsageFault priority to the highest, that is not already set in SPM initialize */
    NVIC_SetPriority(UsageFault_IRQn, 0);

    /* Config fault handlers for Secure violations from
     * corresponding IPs outside CM33 core (MPC, PPC, MSC) */
    cy_stc_SysFault_t        ifx_fault_cfg;
    cy_en_SysFault_status_t  sys_fault_status;

    /* Enable Fault structure for interrupt handling */
    Cy_SysFault_ClearInterrupt(FAULT_STRUCT0);
    Cy_SysFault_ClearStatus(FAULT_STRUCT0);
    Cy_SysFault_SetInterruptMask(FAULT_STRUCT0);

    /* TF-M fault IRQs dumps (optionally) information about fault and calls tfm_core_panic */
    ifx_fault_cfg.ResetEnable   = false;
    ifx_fault_cfg.OutputEnable  = false;
    ifx_fault_cfg.TriggerEnable = false;
    sys_fault_status = Cy_SysFault_Init(FAULT_STRUCT0, &ifx_fault_cfg);
    if (sys_fault_status != CY_SYSFAULT_SUCCESS) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that Fault interrupts for secure violation sources ware enabled */
    for (uint32_t idx = 0UL; idx < ifx_fault_sources_fault_struct0_count; idx++) {
        if (Cy_SysFault_GetMaskByIdx(FAULT_STRUCT0,
                                     ifx_fault_sources_fault_struct0[idx]) == false) {
            FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
        }
    }

    /* Verify that UsageFault_IRQn has the highest priority */
    if (NVIC_GetPriority(UsageFault_IRQn) != 0U) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

    /* Verify that SecureFault has the highest priority */
    if (NVIC_GetPriority(SecureFault_IRQn) != 0U) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

    /* Verify that MemoryManagement fault (MPU) has the highest priority */
    if (NVIC_GetPriority(MemoryManagement_IRQn) != 0U) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

    /* Verify that BusFault has the highest priority */
    if (NVIC_GetPriority(BusFault_IRQn) != 0U) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

    /* Verify that Fault structure for interrupt handling ware enabled */
    if ((Cy_SysFault_GetInterruptStatus(FAULT_STRUCT0) != 0U) ||
        (FAULT_STATUS(FAULT_STRUCT0) != 0U) ||
        (Cy_SysFault_GetInterruptMask(FAULT_STRUCT0) != FAULT_STRUCT_INTR_MASK_FAULT_Msk)) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

    /* Verify faults configuration */
    uint32_t expected_cfg = (_VAL2FLD(FAULT_STRUCT_CTL_TR_EN, ifx_fault_cfg.TriggerEnable) |
                             _VAL2FLD(FAULT_STRUCT_CTL_OUT_EN, ifx_fault_cfg.OutputEnable) |
                             _VAL2FLD(FAULT_STRUCT_CTL_RESET_REQ_EN, ifx_fault_cfg.ResetEnable));

    if ((FAULT_CTL(FAULT_STRUCT0) & expected_cfg) != expected_cfg) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }
#endif /* TFM_FIH_PROFILE_ON */

    FIH_RET(TFM_PLAT_ERR_SUCCESS);
}

/*----------------- Enabling Fault interrupts ----------------*/
FIH_RET_TYPE(enum tfm_plat_err_t) ifx_faults_interrupt_enable(void)
{
    IFX_FIH_DECLARE(enum tfm_plat_err_t, fih_plat_err, TFM_PLAT_ERR_SYSTEM_ERR);

    /* Enables needed fault handlers */
    SCB->SHCSR |= SCB_SHCSR_ENABLED_FAULTS;

#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that needed fault handlers have been enabled */
    if ((SCB->SHCSR & SCB_SHCSR_ENABLED_FAULTS) != SCB_SHCSR_ENABLED_FAULTS) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }
#endif /* TFM_FIH_PROFILE_ON */

    FIH_CALL(ifx_faults_platform_interrupt_enable, fih_plat_err);
    if (FIH_NOT_EQ(fih_plat_err, TFM_PLAT_ERR_SUCCESS)) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

    FIH_RET(TFM_PLAT_ERR_SUCCESS);
}

void tfm_hal_platform_exception_info(void)
{
#ifdef IFX_FAULTS_INFO_DUMP
    ifx_faults_dump();

#ifdef IFX_MSC_TFM_CORE_BUS_MASTER_ID
    /* Check fault attributes to get proper Protection Context */
    uint32_t protection_context = Cy_Ms_Ctl_GetSavedPC(IFX_MSC_TFM_CORE_BUS_MASTER_ID);
    IFX_UNUSED(protection_context);
    ERROR_RAW("Saved Protection Context: 0x%08x\n", protection_context);
#endif /* IFX_MSC_TFM_CORE_BUS_MASTER_ID */
#endif /* IFX_FAULTS_INFO_DUMP */
}
