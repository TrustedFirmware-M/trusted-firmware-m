/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_S_PERIPHERALS_DEF_H
#define IFX_S_PERIPHERALS_DEF_H

#include "cy_device.h"
#include "mxs22.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_FPU_S_TEST_IRQ          ioss_interrupts_gpio_1_IRQn

/* SFLASH is Non-Secure for this device */
#define IFX_SFLASH                  IFX_NS_ADDRESS_ALIAS_T(SFLASH_Type*, SFLASH)

/* LCS is stored in EFUSE. Whole EFUSE block is divided into several PPC
 * regions which have different protection settings. Cy_SysLib_GetDeviceLCS
 * reads EFUSE->BOOTROW which is part of PROT_EFUSE_CTL3 PPC region
 * (which is configured as Non-Secure), thus NS alias is used for EFUSE here. */
#define IFX_LCS_BASE                IFX_NS_ADDRESS_ALIAS_T(EFUSE_Type*, EFUSE)

/* Fault structure and IRQ used by TF-M for fault reporting */
#define IFX_TFM_FAULT_STRUCT        FAULT_STRUCT0
#define IFX_TFM_FAULT_IRQ           cpuss_interrupts_fault_0_IRQn

/* MSC interrupt used by TF-M for secure interrupt target state setup */
#define IFX_TFM_MSC_IRQ             cpuss_interrupt_msc_IRQn

#ifdef __cplusplus
}
#endif

#endif /* IFX_S_PERIPHERALS_DEF_H */
