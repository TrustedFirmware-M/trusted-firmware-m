/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __DEVICE_CFG_H__
#define __DEVICE_CFG_H__

/**
 * \file device_cfg.h
 * \brief
 * This is the device configuration file with only used peripherals
 * defined and configured via the secure and/or non-secure base address.
 */

#include "host_device_cfg.h"
#ifdef RSE_HAS_EXPANSION_PERIPHERALS
#include "rse_expansion_device_cfg.h"
#endif /* RSE_HAS_EXPANSION_PERIPHERALS */

#ifdef RSE_DEBUG_UART
/* ARM UART CMSDK */
#define DEFAULT_UART_CONTROL 0
#define DEFAULT_UART_BAUDRATE  115200
#define UART0_CMSDK_S
#define UART0_CMSDK_NS
#endif /* RSE_DEBUG_UART */

/* ARM Memory Protection Controller (MPC) */
#define MPC_VM0_S
#define MPC_VM1_S
#ifdef RSE_XIP
#define MPC_SIC_S
#endif /* RSE_XIP */

/* ARM Peripheral Protection Controllers (PPC) */
#define PPC_RSE_S
#define PPC_RSE_MAIN0_S
#define PPC_RSE_MAIN_EXP0_S
#define PPC_RSE_MAIN_EXP1_S
#define PPC_RSE_MAIN_EXP2_S
#define PPC_RSE_MAIN_EXP3_S
#define PPC_RSE_PERIPH0_S
#define PPC_RSE_PERIPH1_S
#define PPC_RSE_PERIPH_EXP0_S
#define PPC_RSE_PERIPH_EXP1_S
#define PPC_RSE_PERIPH_EXP2_S
#define PPC_RSE_PERIPH_EXP3_S

/* ARM ATU */
#define ATU_S

#ifdef RSE_XIP
/* ARM SIC */
#define SIC_S
#endif

/* ARM TRAM */
#define TRAM_S

/* ARM Integrity Checker */
#define INTEGRITY_CHECKER_S

/** System Counter Armv8-M */
#define SYSCOUNTER_CNTRL_ARMV8_M_S
#define SYSCOUNTER_CNTRL_ARMV8_M_DEV    SYSCOUNTER_CNTRL_ARMV8_M_DEV_S

/**
 * Arbitrary scaling values for test purposes
 */
#define SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_INT           1u
#define SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_FRACT         0u
#define SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_INT           1u
#define SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_FRACT         0u

/* Arm GPIO */
#define GPIO0_S
#define GPIO1_S

/* System Timer Armv8-M */
#define SYSTIMER0_ARMV8_M_S

#define SYSTIMER0_ARMV8M_DEFAULT_FREQ_HZ    (32000000ul)

/* Arm KMU */
#define KMU_S

/* Arm SAM */
#define SAM_S

/* Arm LCM */
#define LCM_S

/* Arm DCSU */
#ifdef RSE_ENABLE_DCSU_PROVISIONING_COMMS
#define DCSU_S
#endif /* RSE_ENABLE_DCSU_PROVISIONING_COMMS */

/* DMA350 defines */
#define DMA350_DMA0_S
#define DMA350_DMA0_CHANNEL_COUNT 4
#define DMA350_DMA0_CH0_S
#define DMA350_DMA0_CH1_S
#define DMA350_DMA0_CH2_S
#define DMA350_DMA0_CH3_S

#endif  /* __DEVICE_CFG_H__ */
