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

/**
 * \file device_definition.h
 * \brief The structure definitions in this file are exported based on the
 * peripheral definitions from device_cfg.h.
 * This file is meant to be used as a helper for baremetal
 * applications and/or as an example of how to configure the generic
 * driver structures.
 */

#ifndef __DEVICE_DEFINITION_H__
#define __DEVICE_DEFINITION_H__

#include "device_cfg.h"
#include "host_device_definition.h"
#ifdef RSE_HAS_EXPANSION_PERIPHERALS
#include "rse_expansion_device_definition.h"
#endif /* RSE_HAS_EXPANSION_PERIPHERALS */

#ifdef __cplusplus
extern "C" {
#endif

/* ======= Defines peripheral configuration structures ======= */
/* ATU driver structures */
#ifdef ATU_S
#include "atu_rse_drv.h"
extern struct atu_dev_t ATU_DEV_S;
#endif

/* SIC driver structures */
#ifdef SIC_S
#include "sic_drv.h"
extern struct sic_dev_t SIC_DEV_S;
#endif

/* TRAM driver structures */
#ifdef TRAM_S
#include "tram_drv.h"
extern struct tram_dev_t TRAM_DEV_S;
#endif

/* UART CMSDK driver structures */
#ifdef UART0_CMSDK_S
#include "uart_cmsdk_drv.h"
extern struct uart_cmsdk_dev_t UART0_CMSDK_DEV_S;
#endif
#ifdef UART0_CMSDK_NS
#include "uart_cmsdk_drv.h"
extern struct uart_cmsdk_dev_t UART0_CMSDK_DEV_NS;
#endif

/* ARM PPC driver structures */
#ifdef PPC_RSE_S
#include "ppc_drv.h"
#endif

#ifdef PPC_RSE_MAIN0_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_MAIN0_DEV_S;
#endif

#ifdef PPC_RSE_MAIN_EXP0_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_MAIN_EXP0_DEV_S;
#endif

#ifdef PPC_RSE_MAIN_EXP1_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_MAIN_EXP1_DEV_S;
#endif

#ifdef PPC_RSE_MAIN_EXP2_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_MAIN_EXP2_DEV_S;
#endif

#ifdef PPC_RSE_MAIN_EXP3_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_MAIN_EXP3_DEV_S;
#endif

#ifdef PPC_RSE_PERIPH0_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_PERIPH0_DEV_S;
#endif

#ifdef PPC_RSE_PERIPH1_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_PERIPH1_DEV_S;
#endif

#ifdef PPC_RSE_PERIPH_EXP0_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_PERIPH_EXP0_DEV_S;
#endif

#ifdef PPC_RSE_PERIPH_EXP1_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_PERIPH_EXP1_DEV_S;
#endif

#ifdef PPC_RSE_PERIPH_EXP2_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_PERIPH_EXP2_DEV_S;
#endif

#ifdef PPC_RSE_PERIPH_EXP3_S
#include "ppc_drv.h"
extern struct ppc_dev_t PPC_RSE_PERIPH_EXP3_DEV_S;
#endif

/* System counters */
#ifdef SYSCOUNTER_CNTRL_ARMV8_M_S
#include "syscounter_armv8-m_cntrl_drv.h"
extern struct syscounter_armv8_m_cntrl_dev_t SYSCOUNTER_CNTRL_ARMV8_M_DEV_S;
#endif

#ifdef SYSCOUNTER_READ_ARMV8_M_S
#include "syscounter_armv8-m_read_drv.h"
extern struct syscounter_armv8_m_read_dev_t SYSCOUNTER_READ_ARMV8_M_DEV_S;
#endif

/* System timers */
#ifdef SYSTIMER0_ARMV8_M_S
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER0_ARMV8_M_DEV_S;
#endif
#ifdef SYSTIMER0_ARMV8_M_NS
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER0_ARMV8_M_DEV_NS;
#endif

#ifdef SYSTIMER1_ARMV8_M_S
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER1_ARMV8_M_DEV_S;
#endif
#ifdef SYSTIMER1_ARMV8_M_NS
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER1_ARMV8_M_DEV_NS;
#endif

#ifdef SYSTIMER2_ARMV8_M_S
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER2_ARMV8_M_DEV_S;
#endif
#ifdef SYSTIMER2_ARMV8_M_NS
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER2_ARMV8_M_DEV_NS;
#endif

#ifdef SYSTIMER3_ARMV8_M_S
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER3_ARMV8_M_DEV_S;
#endif
#ifdef SYSTIMER3_ARMV8_M_NS
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER3_ARMV8_M_DEV_NS;
#endif

/* System Watchdogs */
#ifdef SYSWDOG_ARMV8_M_S
#include "syswdog_armv8-m_drv.h"
extern struct syswdog_armv8_m_dev_t SYSWDOG_ARMV8_M_DEV_S;
#endif
#ifdef SYSWDOG_ARMV8_M_NS
#include "syswdog_armv8-m_drv.h"
extern struct syswdog_armv8_m_dev_t SYSWDOG_ARMV8_M_DEV_NS;
#endif

/* ARM MPC SIE 300 driver structures */
#ifdef MPC_VM0_S
#include "mpc_sie_drv.h"
extern struct mpc_sie_dev_t MPC_VM0_DEV_S;
#endif

#ifdef MPC_VM1_S
#include "mpc_sie_drv.h"
extern struct mpc_sie_dev_t MPC_VM1_DEV_S;
#endif

#ifdef MPC_SIC_S
#include "mpc_sie_drv.h"
extern struct mpc_sie_dev_t MPC_SIC_DEV_S;
#endif

#ifdef KMU_S
#include "kmu_drv.h"
extern struct kmu_dev_t KMU_DEV_S;
#endif

#ifdef SAM_S
#include "sam_drv.h"
extern struct sam_dev_t SAM_DEV_S;
#endif

#ifdef LCM_S
#include "lcm_drv.h"
extern struct lcm_dev_t LCM_DEV_S;
#endif

#ifdef INTEGRITY_CHECKER_S
#include "integrity_checker_drv.h"
extern struct integrity_checker_dev_t INTEGRITY_CHECKER_DEV_S;
#endif

#ifdef DCSU_S
#include "dcsu_drv.h"
extern struct dcsu_dev_t DCSU_DEV_S;
#endif

#ifdef DMA350_DMA0_S
#include "dma350_drv.h"
#include "dma350_ch_drv.h"
extern struct dma350_dev_t DMA350_DMA0_DEV_S;
#endif

#ifdef DMA350_DMA0_CH0_S
extern struct dma350_ch_dev_t DMA350_DMA0_CH0_DEV_S;
#endif

#ifdef DMA350_DMA0_CH1_S
extern struct dma350_ch_dev_t DMA350_DMA0_CH1_DEV_S;
#endif

#ifdef DMA350_DMA0_CH2_S
extern struct dma350_ch_dev_t DMA350_DMA0_CH2_DEV_S;
#endif

#ifdef DMA350_DMA0_CH3_S
extern struct dma350_ch_dev_t DMA350_DMA0_CH3_DEV_S;
#endif

#ifdef GPIO0_S
#include "gpio_pl061_drv.h"
extern pl061_regblk_t *const GPIO0_DEV_S;
#endif

#ifdef GPIO1_S
#include "gpio_pl061_drv.h"
extern pl061_regblk_t *const GPIO1_DEV_S;
#endif

#ifdef GPIO0_NS
#include "gpio_pl061_drv.h"
extern pl061_regblk_t *const GPIO0_DEV_NS;
#endif

#ifdef GPIO1_NS
#include "gpio_pl061_drv.h"
extern pl061_regblk_t *const GPIO1_DEV_NS;
#endif

/* Legacy MHUv2 support for TC2 */
#if PLAT_MHU_VERSION == 2

#ifdef MHU0_S
#include "mhu_v2_x.h"
extern struct mhu_v2_x_dev_t MHU0_SENDER_DEV_S;
extern struct mhu_v2_x_dev_t MHU0_RECEIVER_DEV_S;
#endif

#ifdef MHU1_S
#include "mhu_v2_x.h"
extern struct mhu_v2_x_dev_t MHU1_SENDER_DEV_S;
extern struct mhu_v2_x_dev_t MHU1_RECEIVER_DEV_S;
#endif

#ifdef MHU2_S
#include "mhu_v2_x.h"
extern struct mhu_v2_x_dev_t MHU2_SENDER_DEV_S;
extern struct mhu_v2_x_dev_t MHU2_RECEIVER_DEV_S;
#endif

#else /* PLAT_MHU_VERSION == 2 */

#ifdef MHU0_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU0_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU0_RECEIVER_DEV_S;
#endif

#ifdef MHU1_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU1_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU1_RECEIVER_DEV_S;
#endif

#ifdef MHU2_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU2_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU2_RECEIVER_DEV_S;
#endif

#ifdef MHU3_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU3_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU3_RECEIVER_DEV_S;
#endif

#ifdef MHU4_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU4_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU4_RECEIVER_DEV_S;
#endif

#ifdef MHU5_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU5_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU5_RECEIVER_DEV_S;
#endif

#ifdef MHU6_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU6_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU6_RECEIVER_DEV_S;
#endif

#ifdef MHU7_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU7_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU7_RECEIVER_DEV_S;
#endif

#ifdef MHU8_S
#include "mhu_v3_x.h"
extern struct mhu_v3_x_dev_t MHU8_SENDER_DEV_S;
extern struct mhu_v3_x_dev_t MHU8_RECEIVER_DEV_S;
#endif

#endif /* PLAT_MHU_VERSION == 2 */

#ifdef __cplusplus
}
#endif

#endif  /* __DEVICE_DEFINITION_H__ */
