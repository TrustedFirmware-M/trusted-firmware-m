/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "cmsis.h"
#include "cy_sysfault.h"
#include "faults.h"
#include "faults_dump.h"
#include "ifx_utils.h"
#include "tfm_peripherals_def.h"
#include "tfm_log.h"

#ifdef IFX_FAULTS_INFO_DUMP
void ifx_faults_dump(void)
{
    while (true) {
        cy_en_SysFault_source_t fault_source = Cy_SysFault_GetErrorSource(IFX_TFM_FAULT_STRUCT);
        if ((uint8_t)fault_source == CY_SYSFAULT_NO_FAULT) {
            break;
        }

        ERROR_RAW("Platform Exception: 0x%08x\n", (uint32_t)fault_source);

        switch (fault_source) {
            case PERI_PERI_MS0_PPC_VIO:
            case PERI_PERI_MS1_PPC_VIO: {
                ifx_faults_dump_peri_msx_ppc_vio_fault(IFX_TFM_FAULT_STRUCT);
                break;
            }

            case PERI_PERI_PPC_PC_MASK_VIO: {
                ifx_faults_dump_peri_ppc_pc_mask_vio_fault(IFX_TFM_FAULT_STRUCT);
                break;
            }

            case PERI_PERI_GP1_TIMEOUT_VIO:
            case PERI_PERI_GP2_TIMEOUT_VIO:
            case PERI_PERI_GP3_TIMEOUT_VIO:
            case PERI_PERI_GP4_TIMEOUT_VIO:
            case PERI_PERI_GP5_TIMEOUT_VIO: {
                ifx_faults_dump_peri_gpx_timeout_vio_fault(IFX_TFM_FAULT_STRUCT);
                break;
            }

            case PERI_PERI_GP0_AHB_VIO:
            case PERI_PERI_GP1_AHB_VIO:
            case PERI_PERI_GP2_AHB_VIO:
            case PERI_PERI_GP3_AHB_VIO:
            case PERI_PERI_GP4_AHB_VIO:
            case PERI_PERI_GP5_AHB_VIO: {
                ifx_faults_dump_peri_gpx_ahb_vio_fault(IFX_TFM_FAULT_STRUCT);
                break;
            }

            case CPUSS_RAMC0_MPC_FAULT_MMIO:
#if defined(CPUSS_RAMC1_PRESENT) && (CPUSS_RAMC1_PRESENT != 0)
            case CPUSS_RAMC1_MPC_FAULT_MMIO:
#endif
            case CPUSS_PROMC_MPC_FAULT_MMIO:
            case CPUSS_FLASHC_MPC_FAULT: {
                ifx_faults_dump_mpc_fault(IFX_TFM_FAULT_STRUCT);
                break;
            }

            default: {
                ifx_faults_dump_default_fault(IFX_TFM_FAULT_STRUCT);
                break;
            }
        }

        Cy_SysFault_ClearStatus(IFX_TFM_FAULT_STRUCT);
    }
}
#endif /* IFX_FAULTS_INFO_DUMP */
