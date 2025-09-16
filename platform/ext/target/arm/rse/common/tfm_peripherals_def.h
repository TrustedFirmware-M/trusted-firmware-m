/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2020-2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PERIPHERALS_DEF_H__
#define __TFM_PERIPHERALS_DEF_H__

#include "platform_irq.h"
#include "common_target_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Quantized default IRQ priority, the value is:
 * (Number of configurable priority) / 4: (1UL << __NVIC_PRIO_BITS) / 4
 */
#define DEFAULT_IRQ_PRIORITY    (1UL << (__NVIC_PRIO_BITS - 2))

#define TFM_TIMER0_IRQ           (TIMER0_IRQn)
#define TFM_DMA0_COMBINED_S_IRQ  (DMA_Combined_S_IRQn)

extern struct platform_data_t tfm_peripheral_std_uart;
extern struct platform_data_t tfm_peripheral_timer0;
extern struct platform_data_t tfm_peripheral_dma0_ch0;

#define TFM_PERIPHERAL_STD_UART  (&tfm_peripheral_std_uart)
#define TFM_PERIPHERAL_TIMER0    (&tfm_peripheral_timer0)
#define TFM_PERIPHERAL_DMA0_CH0  (&tfm_peripheral_dma0_ch0)

/* AP to RSE MHU receiver interrupt */
#define MAILBOX_IRQ   CMU_MHU0_Receiver_IRQn    /* AP_MONITOR  */
#define MAILBOX_IRQ_1 CMU_MHU1_Receiver_IRQn    /* AP_NS */
#define MAILBOX_IRQ_2 CMU_MHU2_Receiver_IRQn    /* AP_S */

/* Append RSE-specific static MPU regions to the standard ones in
 * tfm_hal_isolation_v8m.c.
 */
#define PLATFORM_STATIC_MPU_REGIONS \
    /* Keep ROM as no-execute, and prevent unpriv from accessing */ \
    { \
        ARM_MPU_RBAR(ROM_BASE_S, \
                     ARM_MPU_SH_NON, \
                     ARM_MPU_READ_ONLY, \
                     ARM_MPU_PRIVILEGED, \
                     ARM_MPU_EXECUTE_NEVER), \
        ARM_MPU_RLAR_PXN(ROM_BASE_S + ROM_SIZE - 1, \
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER, \
                         0), \
    }, \
    /* Mark ITCM as privileged, read-only, execute-ok */ \
    { \
        ARM_MPU_RBAR(ITCM_BASE_NS, \
                     ARM_MPU_SH_NON, \
                     ARM_MPU_READ_ONLY, \
                     ARM_MPU_PRIVILEGED, \
                     ARM_MPU_EXECUTE_OK), \
        ARM_MPU_RLAR_PXN(ITCM_BASE_NS + ITCM_SIZE - 1, \
                         ARM_MPU_PRIVILEGE_EXECUTE_OK, \
                         0), \
    }, \
    { \
        ARM_MPU_RBAR(ITCM_BASE_S, \
                     ARM_MPU_SH_NON, \
                     ARM_MPU_READ_ONLY, \
                     ARM_MPU_PRIVILEGED, \
                     ARM_MPU_EXECUTE_OK), \
        ARM_MPU_RLAR_PXN(ITCM_BASE_S + ITCM_SIZE - 1, \
                         ARM_MPU_PRIVILEGE_EXECUTE_OK, \
                         0), \
    }, \
    /* Mark DTCM as privileged, read-write, execute-never */ \
    { \
        ARM_MPU_RBAR(DTCM_BASE_NS, \
                     ARM_MPU_SH_NON, \
                     ARM_MPU_READ_WRITE, \
                     ARM_MPU_PRIVILEGED, \
                     ARM_MPU_EXECUTE_NEVER), \
        ARM_MPU_RLAR_PXN(DTCM_BASE_NS + DTCM_SIZE - 1, \
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER, \
                         0), \
    }, \
    { \
        ARM_MPU_RBAR(DTCM_BASE_S, \
                     ARM_MPU_SH_NON, \
                     ARM_MPU_READ_WRITE, \
                     ARM_MPU_PRIVILEGED, \
                     ARM_MPU_EXECUTE_NEVER), \
        ARM_MPU_RLAR_PXN(DTCM_BASE_S + DTCM_SIZE - 1, \
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER, \
                         0), \
    }, \
    /* Mark ATU RSE mapping region as device memory to prevent */ \
    /* the CPU caching accesses to system memory map */ \
    { \
        ARM_MPU_RBAR(HOST_ACCESS_BASE_NS, \
                     ARM_MPU_SH_NON, \
                     ARM_MPU_READ_WRITE, \
                     ARM_MPU_UNPRIVILEGED, \
                     ARM_MPU_EXECUTE_NEVER), \
        ARM_MPU_RLAR_PXN(HOST_ACCESS_LIMIT_S, \
                         ARM_MPU_PRIVILEGE_EXECUTE_NEVER, \
                         2 /* Device memory attribute */), \
    },

#define ADAC_REQUEST_IRQ SDC_IRQn

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PERIPHERALS_DEF_H__ */
