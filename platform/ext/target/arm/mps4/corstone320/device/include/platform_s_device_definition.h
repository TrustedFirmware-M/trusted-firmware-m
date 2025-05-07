/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * \file platform_s_device_definition.h
 * \brief Definitions for peripherals used on the
 * secure side of application.
 */

#ifndef __PLATFORM_S_DEVICE_DEFINITION_H__
#define __PLATFORM_S_DEVICE_DEFINITION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "device_cfg.h"

/* ======= Defines peripheral configuration structures ======= */

/* UART CMSDK driver structures */
#include "uart_cmsdk_drv.h"
extern struct uart_cmsdk_dev_t UART0_CMSDK_DEV_NS;

/* ARM PPC driver structures */

#include "ppc_corstone320_drv.h"
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_MAIN0_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_MAIN_EXP0_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_MAIN_EXP1_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_MAIN_EXP2_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_MAIN_EXP3_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_PERIPH0_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_PERIPH1_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_PERIPH_EXP0_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_PERIPH_EXP1_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_PERIPH_EXP2_DEV_S;
extern struct ppc_corstone320_dev_t PPC_CORSTONE320_PERIPH_EXP3_DEV_S;

/* System counters */
#include "syscounter_armv8-m_cntrl_drv.h"
extern struct syscounter_armv8_m_cntrl_dev_t SYSCOUNTER_CNTRL_ARMV8_M_DEV_S;

#define SYSCOUNTER_CNTRL_ARMV8_M_DEV    SYSCOUNTER_CNTRL_ARMV8_M_DEV_S

/* System timers */
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER0_ARMV8_M_DEV_S;

/* ARM MPC SIE 300 driver structures */
#include "mpc_sie_drv.h"
extern struct mpc_sie_dev_t MPC_QSPI_DEV_S;
extern struct mpc_sie_dev_t MPC_ISRAM0_DEV_S;
extern struct mpc_sie_dev_t MPC_ISRAM1_DEV_S;
extern struct mpc_sie_dev_t MPC_ISRAM2_DEV_S;
extern struct mpc_sie_dev_t MPC_ISRAM3_DEV_S;
extern struct mpc_sie_dev_t MPC_DDR4_DEV_S;

/* DMA350 driver structures */
#include "dma350_drv.h"
extern struct dma350_dev_t DMA350_DMA0_DEV_S;
#define DMA350_DMA0_DEV             DMA350_DMA0_DEV_S
#define DMA350_TRIGIN_NUMBER        (8u)

#ifdef PLATFORM_SVC_HANDLERS
/* Required for DMA350 checker layer even if some channels are configured NS by
 * default
 */
#include "dma350_ch_drv.h"
extern struct dma350_ch_dev_t DMA350_DMA0_CH0_DEV_S;
extern struct dma350_ch_dev_t DMA350_DMA0_CH1_DEV_S;

#include "dma350_lib.h"
extern const struct dma350_remap_list_t dma350_address_remap;
#endif /* PLATFORM_SVC_HANDLERS */

/* TGU driver structure */
#include "tgu_armv8_m_drv.h"
extern struct tgu_armv8_m_dev_t TGU_ARMV8_M_ITCM_DEV_S;
extern struct tgu_armv8_m_dev_t TGU_ARMV8_M_DTCM_DEV_S;

#include "ethosu_device.h"
extern struct ethosu_device NPU0_S;

/* LCM driver structure */
#include "lcm_drv.h"
extern struct lcm_dev_t LCM_DEV_S;

/* KMU driver structure */
#include "kmu_drv.h"
extern struct kmu_dev_t KMU_DEV_S;

/* SAM driver structure */
#include "sam_drv.h"
extern struct sam_dev_t SAM_DEV_S;

/* Watchdog driver structure */
#include "arm_watchdog_drv.h"
extern struct arm_watchdog_dev_t SLOWCLK_WATCHDOG_DEV_S;

#ifdef __cplusplus
}
#endif

#endif  /* __PLATFORM_S_DEVICE_DEFINITION_H__ */
