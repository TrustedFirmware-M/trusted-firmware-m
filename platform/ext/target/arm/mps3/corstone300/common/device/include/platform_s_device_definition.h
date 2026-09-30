/*
 * Copyright (c) 2019-2023 Arm Limited. All rights reserved.
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

#include "ppc_sse300_drv.h"
extern struct ppc_sse300_dev_t PPC_SSE300_MAIN0_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_MAIN_EXP0_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_MAIN_EXP1_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_MAIN_EXP2_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_MAIN_EXP3_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_PERIPH0_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_PERIPH1_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_PERIPH_EXP0_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_PERIPH_EXP1_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_PERIPH_EXP2_DEV_S;
extern struct ppc_sse300_dev_t PPC_SSE300_PERIPH_EXP3_DEV_S;

/* System counters */
#include "syscounter_armv8-m_cntrl_drv.h"
extern struct syscounter_armv8_m_cntrl_dev_t SYSCOUNTER_CNTRL_ARMV8_M_DEV_S;

#define SYSCOUNTER_CNTRL_ARMV8_M_DEV    SYSCOUNTER_CNTRL_ARMV8_M_DEV_S

/* System timers */
#include "systimer_armv8-m_drv.h"
extern struct systimer_armv8_m_dev_t SYSTIMER0_ARMV8_M_DEV_S;
extern struct systimer_armv8_m_dev_t SYSTIMER1_ARMV8_M_DEV_S;

/* ARM MPC SIE 300 driver structures */
#include "mpc_sie_drv.h"
extern struct mpc_sie_dev_t MPC_SRAM_DEV_S;
extern struct mpc_sie_dev_t MPC_QSPI_DEV_S;
extern struct mpc_sie_dev_t MPC_ISRAM0_DEV_S;
extern struct mpc_sie_dev_t MPC_ISRAM1_DEV_S;
extern struct mpc_sie_dev_t MPC_DDR4_DEV_S;

/* TGU driver structure */
#include "tgu_armv8_m_drv.h"
extern struct tgu_armv8_m_dev_t TGU_ARMV8_M_ITCM_DEV_S;
extern struct tgu_armv8_m_dev_t TGU_ARMV8_M_DTCM_DEV_S;

#ifdef __cplusplus
}
#endif

#endif  /* __PLATFORM_S_DEVICE_DEFINITION_H__ */
