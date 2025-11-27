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

/* Target specific configuration */
#ifndef IFX_SMIF_0_MEMORY_CONFIG
#if defined(IFX_PSVP_PSE84_EPC2) || defined(IFX_PSVP_PSE84_EPC4)
#define IFX_SMIF_0_MEMORY_CONFIG           S25HS512T_SMIF0_SlaveSlot_0
#elif defined(TARGET_APP_KIT_PSOCE84_EVK)
#define IFX_SMIF_0_MEMORY_CONFIG           S25FS128S_SMIF0_SlaveSlot_1
#elif defined(TARGET_APP_KIT_PSE84_EVAL_EPC2) || defined(TARGET_APP_KIT_PSE84_EVAL_EPC4)
#define IFX_SMIF_0_MEMORY_CONFIG           S25FS128S_SMIF0_SlaveSlot_1
#else
/* S25HS512T is used on PSVP */
#define IFX_SMIF_0_MEMORY_CONFIG           S25HS512T_SMIF0_SlaveSlot_0
#endif
#endif /* IFX_SMIF_0_MEMORY_CONFIG */

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

#ifdef __cplusplus
}
#endif

#endif /* IFX_S_PERIPHERALS_DEF_H */
