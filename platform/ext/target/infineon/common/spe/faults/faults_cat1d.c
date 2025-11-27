/*
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "cmsis.h"
#include "cy_sysfault.h"
#include "exception_info.h"
#include "faults.h"
#include "faults_dump.h"
#include "ifx_utils.h"
#include "ifx_tfm_log_shim.h"
#include "utilities.h"

void c_m33syscpuss_interrupt_msc_IRQn_Handler(void)
{
    /* Print fault message and block execution */
    ERROR_RAW("Platform Exception: MSC fault!!!\n");

    /* Clear all causes of MSC interrupt */
    CPUSS->INTR_MSC = 0;

    tfm_core_panic();
}

/* IAR Specific */
#if defined(__ICCARM__)
#pragma required = c_m33syscpuss_interrupt_msc_IRQn_Handler
EXCEPTION_INFO_IAR_REQUIRED
#endif /* defined(__ICCARM__) */
__attribute__((naked)) void m33syscpuss_interrupt_msc_IRQn_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        c_m33syscpuss_interrupt_msc_IRQn_Handler           \n"
        "B         .                                                  \n"
    );
}

void c_m33syscpuss_interrupts_fault_0_IRQn_Handler(void)
{
    Cy_SysFault_ClearInterrupt(FAULT_STRUCT0);
    Cy_SysFault_ClearStatus(FAULT_STRUCT0);

    tfm_core_panic();
}

#if defined(__ICCARM__)
#pragma required = c_m33syscpuss_interrupts_fault_0_IRQn_Handler
EXCEPTION_INFO_IAR_REQUIRED
#endif /* defined(__ICCARM__) */
__attribute__((naked)) void m33syscpuss_interrupts_fault_0_IRQn_Handler(void)
{
    EXCEPTION_INFO();

    __ASM volatile(
        "BL        c_m33syscpuss_interrupts_fault_0_IRQn_Handler           \n"
        "B         .                                                       \n"
    );
}

FIH_RET_TYPE(enum tfm_plat_err_t) ifx_faults_platform_interrupt_enable(void)
{
    /* Set fault and secure violations priority to less than half of max priority
     * (with AIRCR.PRIS set) to prevent Non-secure from pre-empting faults
     * that may indicate corruption of Secure state. */
    NVIC_SetPriority(m33syscpuss_interrupt_msc_IRQn, 0);
    NVIC_SetPriority(m33syscpuss_interrupts_fault_0_IRQn, 0);

#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that fault interrupt has the highest priority */
    if (NVIC_GetPriority(m33syscpuss_interrupt_msc_IRQn) != 0U) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }

    /* Verify that fault interrupt has the highest priority */
    if (NVIC_GetPriority(m33syscpuss_interrupts_fault_0_IRQn) != 0U) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }
#endif /* TFM_FIH_PROFILE_ON */

    /* Enables needed interrupts */
    NVIC_EnableIRQ(m33syscpuss_interrupt_msc_IRQn);
    NVIC_EnableIRQ(m33syscpuss_interrupts_fault_0_IRQn);

#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    /* Verify that needed interrupts have been enabled */
    if ((NVIC_GetEnableIRQ(m33syscpuss_interrupt_msc_IRQn) == 0U) ||
        (NVIC_GetEnableIRQ(m33syscpuss_interrupts_fault_0_IRQn) == 0U)) {
        FIH_RET(TFM_PLAT_ERR_SYSTEM_ERR);
    }
#endif /* TFM_FIH_PROFILE_ON */

    FIH_RET(TFM_PLAT_ERR_SUCCESS);
}

#ifdef IFX_FAULTS_INFO_DUMP
void ifx_faults_dump(void)
{
    while (true) {
        cy_en_SysFault_source_t fault_source = Cy_SysFault_GetErrorSource(FAULT_STRUCT0);
        if ((uint8_t)fault_source == CY_SYSFAULT_NO_FAULT) {
            break;
        }

        ERROR_RAW("Platform Exception: 0x%08x\n", fault_source);

        switch (fault_source) {
            case PERI_0_PERI_MS0_PPC_VIO:
            case PERI_0_PERI_MS1_PPC_VIO:
            case PERI_1_PERI_MS0_PPC_VIO:
            case PERI_1_PERI_MS1_PPC_VIO: {
                ifx_faults_dump_peri_msx_ppc_vio_fault(FAULT_STRUCT0);
                break;
            }

            case PERI_0_PERI_PPC_PC_MASK_VIO:
            case PERI_1_PERI_PPC_PC_MASK_VIO: {
                ifx_faults_dump_peri_ppc_pc_mask_vio_fault(FAULT_STRUCT0);
                break;
            }

            case PERI_0_PERI_GP1_TIMEOUT_VIO:
            case PERI_0_PERI_GP2_TIMEOUT_VIO:
            case PERI_0_PERI_GP3_TIMEOUT_VIO:
            case PERI_0_PERI_GP4_TIMEOUT_VIO:
            case PERI_0_PERI_GP5_TIMEOUT_VIO:
            case PERI_1_PERI_GP1_TIMEOUT_VIO:
            case PERI_1_PERI_GP2_TIMEOUT_VIO:
            case PERI_1_PERI_GP3_TIMEOUT_VIO:
            case PERI_1_PERI_GP4_TIMEOUT_VIO: {
                ifx_faults_dump_peri_gpx_timeout_vio_fault(FAULT_STRUCT0);
                break;
            }

            case PERI_0_PERI_GP0_AHB_VIO:
            case PERI_0_PERI_GP1_AHB_VIO:
            case PERI_0_PERI_GP2_AHB_VIO:
            case PERI_0_PERI_GP3_AHB_VIO:
            case PERI_0_PERI_GP4_AHB_VIO:
            case PERI_0_PERI_GP5_AHB_VIO:
            case PERI_1_PERI_GP0_AHB_VIO:
            case PERI_1_PERI_GP1_AHB_VIO:
            case PERI_1_PERI_GP2_AHB_VIO:
            case PERI_1_PERI_GP3_AHB_VIO:
            case PERI_1_PERI_GP4_AHB_VIO: {
                ifx_faults_dump_peri_gpx_ahb_vio_fault(FAULT_STRUCT0);
                break;
            }

            case M33SYSCPUSS_RAMC0_MPC_FAULT_MMIO:
            case M33SYSCPUSS_RAMC1_MPC_FAULT_MMIO:
            case M33SYSCPUSS_RRAMC_HOST_IF_MPC_FAULT:
            case SMIF_0_FAULT_MXSMIF_TOP:
            case SMIF_1_FAULT_MXSMIF_TOP:
            case SOCMEM_SOCMEM_MPC: {
                ifx_faults_dump_mpc_fault(FAULT_STRUCT0);
                break;
            }

            default: {
                ifx_faults_dump_default_fault(FAULT_STRUCT0);
            }
        }

        Cy_SysFault_ClearStatus(FAULT_STRUCT0);
    }
}
#endif /* IFX_FAULTS_INFO_DUMP */
