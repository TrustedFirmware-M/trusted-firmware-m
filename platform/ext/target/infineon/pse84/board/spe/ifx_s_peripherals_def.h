/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_S_PERIPHERALS_DEF_H
#define IFX_S_PERIPHERALS_DEF_H

#include "cy_device.h"
#include "cy_tcpwm_counter.h"
#include "cy_scb_uart.h"
#include "cycfg_peripherals.h"
#include "mxs22.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IFX_TFM_PS_SMIF_MEMORY_CONFIG      ifx_smif_0_memory_config
extern struct ifx_driver_smif_mem_t        ifx_smif_0_memory_config;

#define TFM_FPU_S_TEST_IRQ          ioss_interrupts_gpio_1_IRQn

/* RRAMC0 is Non-Secure for PSE84 */
#define IFX_RRAMC0                  IFX_NS_ADDRESS_ALIAS_T(RRAMC_Type*, RRAMC0)

/* SMIF is Non-Secure for PSE84 */
#define IFX_SMIF_HW                 IFX_NS_ADDRESS_ALIAS_T(SMIF_Type*, \
                                                           CYBSP_SMIF_CORE_0_XSPI_FLASH_HW)

/* Non-Secure alias for NS SFLASH on PSE84 */
#define IFX_NON_SECURE_SFLASH_BASE  IFX_NS_ADDRESS_ALIAS_T(NON_SECURE_SFLASH_Type*, \
                                                           NON_SECURE_SFLASH_BASE)

/* LCS is stored in SRSS block. Whole SRSS block is divided into several PPC
 * regions which have different protection settings. Cy_SysLib_GetDeviceLCS
 * reads SRSS->DECODED_LCS_DATA which is part of PROT_PERI0_SRSS_GENERAL2
 * PPC region (which is configured as Non-Secure), thus NS alias is used for
 * SRSS here. */
#define IFX_LCS_BASE                IFX_NS_ADDRESS_ALIAS_T(SRSS_Type*, SRSS)

/* Fault structure and IRQ used by TF-M for fault reporting */
#define IFX_TFM_FAULT_STRUCT        FAULT_STRUCT0
#define IFX_TFM_FAULT_IRQ           m33syscpuss_interrupts_fault_0_IRQn

/* MSC interrupt used by TF-M for secure interrupt target state setup */
#define IFX_TFM_MSC_IRQ             m33syscpuss_interrupt_msc_IRQn

#ifdef __cplusplus
}
#endif

#endif /* IFX_S_PERIPHERALS_DEF_H */
