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
 * \file device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 * definitions from device_cfg.h.
 * This file is meant to be used as a helper for baremetal
 * applications and/or as an example of how to configure the generic
 * driver structures.
 */

#include "device_definition.h"
#include "platform_base_address.h"
#include "tfm_plat_defs.h"

/* Arm ATU driver structures */
#ifdef ATU_S
static const struct atu_dev_cfg_t ATU_DEV_CFG_S = {
    .base = ATU_BASE_S};
struct atu_dev_t ATU_DEV_S = {&ATU_DEV_CFG_S};
#endif

/* Arm SIC driver structures */
#ifdef SIC_S
static const struct sic_dev_cfg_t SIC_DEV_CFG_S = {
    .base = SIC_BASE_S};
struct sic_dev_t SIC_DEV_S = {&SIC_DEV_CFG_S};
#endif

/* Arm TRAM driver structures */
#ifdef TRAM_S
static const struct tram_dev_cfg_t TRAM_DEV_CFG_S = {
    .base = TRAM_BASE_S};
struct tram_dev_t TRAM_DEV_S = {&TRAM_DEV_CFG_S};
#endif

/* UART CMSDK driver structures */
#ifdef UART0_CMSDK_S
static const struct uart_cmsdk_dev_cfg_t UART0_CMSDK_DEV_CFG_S = {
    .base = RSE_DEBUG_UART0_BASE_S,
    .default_baudrate = DEFAULT_UART_BAUDRATE
};
static struct uart_cmsdk_dev_data_t UART0_CMSDK_DEV_DATA_S = {
    .state = 0,
    .system_clk = 0,
    .baudrate = 0
};
struct uart_cmsdk_dev_t UART0_CMSDK_DEV_S = {
    &(UART0_CMSDK_DEV_CFG_S),
    &(UART0_CMSDK_DEV_DATA_S)
};
#endif
#ifdef UART0_CMSDK_NS
static const struct uart_cmsdk_dev_cfg_t UART0_CMSDK_DEV_CFG_NS = {
    .base = RSE_DEBUG_UART0_BASE_NS,
    .default_baudrate = DEFAULT_UART_BAUDRATE
};
static struct uart_cmsdk_dev_data_t UART0_CMSDK_DEV_DATA_NS = {
    .state = 0,
    .system_clk = 0,
    .baudrate = 0
};
struct uart_cmsdk_dev_t UART0_CMSDK_DEV_NS = {
    &(UART0_CMSDK_DEV_CFG_NS),
    &(UART0_CMSDK_DEV_DATA_NS)
};
#endif

/* RSE PPC driver structures */
#ifdef PPC_RSE_S
static const struct ppc_int_regs_t PPC_INT_REGS = {
    .status = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->secppcintstat,
    .clear = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->secppcintclr,
    .enable = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->secppcinten };
#endif

#ifdef PPC_RSE_MAIN0_S
static const struct ppc_dev_cfg_t PPC_RSE_MAIN0_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainnsppc0,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainspppc0,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->mainnspppc0,
    .int_bit_mask = MAIN_PPC0_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_MAIN0_DEV_S = {
    &PPC_RSE_MAIN0_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_MAIN_EXP0_S
static const struct ppc_dev_cfg_t PPC_RSE_MAIN_EXP0_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainnsppcexp0,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainspppcexp0,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->mainnspppcexp0,
    .int_bit_mask = MAIN_PPCEXP0_INT_POS_MASK,};
struct ppc_dev_t PPC_RSE_MAIN_EXP0_DEV_S = {
    &PPC_RSE_MAIN_EXP0_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_MAIN_EXP1_S
static const struct ppc_dev_cfg_t PPC_RSE_MAIN_EXP1_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainnsppcexp1,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainspppcexp1,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->mainnspppcexp1,
    .int_bit_mask = MAIN_PPCEXP1_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_MAIN_EXP1_DEV_S = {
    &PPC_RSE_MAIN_EXP1_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_MAIN_EXP2_S
static const struct ppc_dev_cfg_t PPC_RSE_MAIN_EXP2_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainnsppcexp2,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainspppcexp2,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->mainnspppcexp2,
    .int_bit_mask = MAIN_PPCEXP2_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_MAIN_EXP2_DEV_S = {
    &PPC_RSE_MAIN_EXP2_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_MAIN_EXP3_S
static const struct ppc_dev_cfg_t PPC_RSE_MAIN_EXP3_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainnsppcexp3,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->mainspppcexp3,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->mainnspppcexp3,
    .int_bit_mask = MAIN_PPCEXP3_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_MAIN_EXP3_DEV_S = {
    &PPC_RSE_MAIN_EXP3_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_PERIPH0_S
static const struct ppc_dev_cfg_t PPC_RSE_PERIPH0_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphnsppc0,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphspppc0,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->periphnspppc0,
    .int_bit_mask = PERIPH_PPC0_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_PERIPH0_DEV_S = {
    &PPC_RSE_PERIPH0_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_PERIPH1_S
static const struct ppc_dev_cfg_t PPC_RSE_PERIPH1_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphnsppc1,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphspppc1,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->periphnspppc1,
    .int_bit_mask = PERIPH_PPC1_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_PERIPH1_DEV_S = {
    &PPC_RSE_PERIPH1_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_PERIPH_EXP0_S
static const struct ppc_dev_cfg_t PPC_RSE_PERIPH_EXP0_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphnsppcexp0,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphspppcexp0,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->periphnspppcexp0,
    .int_bit_mask = PERIPH_PPCEXP0_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_PERIPH_EXP0_DEV_S = {
    &PPC_RSE_PERIPH_EXP0_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_PERIPH_EXP1_S
static const struct ppc_dev_cfg_t PPC_RSE_PERIPH_EXP1_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphnsppcexp1,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphspppcexp1,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->periphnspppcexp1,
    .int_bit_mask = PERIPH_PPCEXP1_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_PERIPH_EXP1_DEV_S = {
    &PPC_RSE_PERIPH_EXP1_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_PERIPH_EXP2_S
static const struct ppc_dev_cfg_t PPC_RSE_PERIPH_EXP2_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphnsppcexp2,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphspppcexp2,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->periphnspppcexp2,
    .int_bit_mask = PERIPH_PPCEXP2_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_PERIPH_EXP2_DEV_S = {
    &PPC_RSE_PERIPH_EXP2_CFG_S,
    &PPC_INT_REGS};
#endif

#ifdef PPC_RSE_PERIPH_EXP3_S
static const struct ppc_dev_cfg_t PPC_RSE_PERIPH_EXP3_CFG_S = {
    .p_ns_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphnsppcexp3,
    .p_sp_ppc = &((struct rse_sacfg_t*)RSE_SACFG_BASE_S)->periphspppcexp3,
    .p_nsp_ppc = &((struct rse_nsacfg_t*)RSE_NSACFG_BASE_NS)->periphnspppcexp3,
    .int_bit_mask = PERIPH_PPCEXP3_INT_POS_MASK};
struct ppc_dev_t PPC_RSE_PERIPH_EXP3_DEV_S = {
    &PPC_RSE_PERIPH_EXP3_CFG_S,
    &PPC_INT_REGS};
#endif

/* System counters */
#ifdef SYSCOUNTER_CNTRL_ARMV8_M_S

#if SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_INT > \
    SYSCOUNTER_ARMV8_M_SCALE_VAL_INT_MAX
#error SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_INT is invalid.
#endif
#if SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_FRACT > \
    SYSCOUNTER_ARMV8_M_SCALE_VAL_FRACT_MAX
#error SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_FRACT is invalid.
#endif
#if SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_INT > \
    SYSCOUNTER_ARMV8_M_SCALE_VAL_INT_MAX
#error SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_INT is invalid.
#endif
#if SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_FRACT > \
    SYSCOUNTER_ARMV8_M_SCALE_VAL_FRACT_MAX
#error SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_FRACT is invalid.
#endif

static const struct syscounter_armv8_m_cntrl_dev_cfg_t
SYSCOUNTER_CNTRL_ARMV8_M_DEV_CFG_S = {
    .base = SYSCNTR_CNTRL_BASE_S,
    .scale0.integer  = SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_INT,
    .scale0.fixed_point_fraction = SYSCOUNTER_ARMV8_M_DEFAULT_SCALE0_FRACT,
    .scale1.integer  = SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_INT,
    .scale1.fixed_point_fraction = SYSCOUNTER_ARMV8_M_DEFAULT_SCALE1_FRACT
};
static struct syscounter_armv8_m_cntrl_dev_data_t
SYSCOUNTER_CNTRL_ARMV8_M_DEV_DATA_S = {
    .is_initialized = false
};
struct syscounter_armv8_m_cntrl_dev_t SYSCOUNTER_CNTRL_ARMV8_M_DEV_S = {
    &(SYSCOUNTER_CNTRL_ARMV8_M_DEV_CFG_S),
    &(SYSCOUNTER_CNTRL_ARMV8_M_DEV_DATA_S)
};
#endif

#ifdef SYSCOUNTER_READ_ARMV8_M_S
static const struct syscounter_armv8_m_read_dev_cfg_t
SYSCOUNTER_READ_ARMV8_M_DEV_CFG_S = {
    .base = SYSCNTR_READ_BASE_S,
};
struct syscounter_armv8_m_read_dev_t SYSCOUNTER_READ_ARMV8_M_DEV_S = {
    &(SYSCOUNTER_READ_ARMV8_M_DEV_CFG_S),
};
#endif

/* System timers */
#ifdef SYSTIMER0_ARMV8_M_S
static const struct systimer_armv8_m_dev_cfg_t SYSTIMER0_ARMV8_M_DEV_CFG_S
#ifdef TFM_PARTITION_SLIH_TEST
    TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_SLIH_TEST", "APP-ROT")
#elif defined(TFM_PARTITION_FLIH_TEST)
    TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_FLIH_TEST", "APP-ROT")
#endif
    = {
    .base = SYSTIMER0_ARMV8_M_BASE_S,
    .default_freq_hz = SYSTIMER0_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t SYSTIMER0_ARMV8_M_DEV_DATA_S
#ifdef TFM_PARTITION_SLIH_TEST
    TFM_LINK_SET_RW_IN_PARTITION_SECTION("TFM_SP_SLIH_TEST", "APP-ROT")
#elif defined(TFM_PARTITION_FLIH_TEST)
    TFM_LINK_SET_RW_IN_PARTITION_SECTION("TFM_SP_FLIH_TEST", "APP-ROT")
#endif
    = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER0_ARMV8_M_DEV_S
#ifdef TFM_PARTITION_SLIH_TEST
    TFM_LINK_SET_RW_IN_PARTITION_SECTION("TFM_SP_SLIH_TEST", "APP-ROT")
#elif defined(TFM_PARTITION_FLIH_TEST)
    TFM_LINK_SET_RW_IN_PARTITION_SECTION("TFM_SP_FLIH_TEST", "APP-ROT")
#endif
    = {
    &(SYSTIMER0_ARMV8_M_DEV_CFG_S),
    &(SYSTIMER0_ARMV8_M_DEV_DATA_S)
};
#endif

#ifdef SYSTIMER0_ARMV8_M_NS
static const struct systimer_armv8_m_dev_cfg_t
SYSTIMER0_ARMV8_M_DEV_CFG_NS = {
    .base = SYSTIMER0_ARMV8_M_BASE_NS,
    .default_freq_hz = SYSTIMER0_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t
SYSTIMER0_ARMV8_M_DEV_DATA_NS = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER0_ARMV8_M_DEV_NS = {
    &(SYSTIMER0_ARMV8_M_DEV_CFG_NS),
    &(SYSTIMER0_ARMV8_M_DEV_DATA_NS)
};
#endif

#ifdef SYSTIMER1_ARMV8_M_S
static const struct systimer_armv8_m_dev_cfg_t
SYSTIMER1_ARMV8_M_DEV_CFG_S = {
    .base = SYSTIMER1_ARMV8_M_BASE_S,
    .default_freq_hz = SYSTIMER1_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t
SYSTIMER1_ARMV8_M_DEV_DATA_S = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER1_ARMV8_M_DEV_S = {
    &(SYSTIMER1_ARMV8_M_DEV_CFG_S),
    &(SYSTIMER1_ARMV8_M_DEV_DATA_S)
};
#endif

#ifdef SYSTIMER1_ARMV8_M_NS
static const struct systimer_armv8_m_dev_cfg_t
SYSTIMER1_ARMV8_M_DEV_CFG_NS = {
    .base = SYSTIMER1_ARMV8_M_BASE_NS,
    .default_freq_hz = SYSTIMER1_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t
SYSTIMER1_ARMV8_M_DEV_DATA_NS = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER1_ARMV8_M_DEV_NS = {
    &(SYSTIMER1_ARMV8_M_DEV_CFG_NS),
    &(SYSTIMER1_ARMV8_M_DEV_DATA_NS)
};
#endif

#ifdef SYSTIMER2_ARMV8_M_S
static const struct systimer_armv8_m_dev_cfg_t
SYSTIMER2_ARMV8_M_DEV_CFG_S = {
    .base = SYSTIMER2_ARMV8_M_BASE_S,
    .default_freq_hz = SYSTIMER2_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t
SYSTIMER2_ARMV8_M_DEV_DATA_S = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER2_ARMV8_M_DEV_S = {
    &(SYSTIMER2_ARMV8_M_DEV_CFG_S),
    &(SYSTIMER2_ARMV8_M_DEV_DATA_S)
};
#endif

#ifdef SYSTIMER2_ARMV8_M_NS
static const struct systimer_armv8_m_dev_cfg_t
SYSTIMER2_ARMV8_M_DEV_CFG_NS = {
    .base = SYSTIMER2_ARMV8_M_BASE_NS,
    .default_freq_hz = SYSTIMER2_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t
SYSTIMER2_ARMV8_M_DEV_DATA_NS = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER2_ARMV8_M_DEV_NS = {
    &(SYSTIMER2_ARMV8_M_DEV_CFG_NS),
    &(SYSTIMER2_ARMV8_M_DEV_DATA_NS)
};
#endif

#ifdef SYSTIMER3_ARMV8_M_S
static const struct systimer_armv8_m_dev_cfg_t
SYSTIMER3_ARMV8_M_DEV_CFG_S = {
    .base = SYSTIMER3_ARMV8_M_BASE_S,
    .default_freq_hz = SYSTIMER3_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t
SYSTIMER3_ARMV8_M_DEV_DATA_S = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER3_ARMV8_M_DEV_S = {
    &(SYSTIMER3_ARMV8_M_DEV_CFG_S),
    &(SYSTIMER3_ARMV8_M_DEV_DATA_S)
};
#endif

#ifdef SYSTIMER3_ARMV8_M_NS
static const struct systimer_armv8_m_dev_cfg_t
SYSTIMER3_ARMV8_M_DEV_CFG_NS = {
    .base = SYSTIMER3_ARMV8_M_BASE_NS,
    .default_freq_hz = SYSTIMER3_ARMV8M_DEFAULT_FREQ_HZ
};
static struct systimer_armv8_m_dev_data_t
SYSTIMER3_ARMV8_M_DEV_DATA_NS = {
    .is_initialized = false
};
struct systimer_armv8_m_dev_t SYSTIMER3_ARMV8_M_DEV_NS = {
    &(SYSTIMER3_ARMV8_M_DEV_CFG_NS),
    &(SYSTIMER3_ARMV8_M_DEV_DATA_NS)
};
#endif

/* System Watchdogs */
#ifdef SYSWDOG_ARMV8_M_S
static const struct syswdog_armv8_m_dev_cfg_t
SYSWDOG_ARMV8_M_DEV_CFG_S = {
    .base = SYSWDOG_ARMV8_M_CNTRL_BASE_S
};
struct syswdog_armv8_m_dev_t SYSWDOG_ARMV8_M_DEV_S = {
    &(SYSWDOG_ARMV8_M_DEV_CFG_S)
};
#endif

#ifdef SYSWDOG_ARMV8_M_NS
static const struct syswdog_armv8_m_dev_cfg_t
SYSWDOG_ARMV8_M_DEV_CFG_NS = {
    .base = SYSWDOG_ARMV8_M_CNTRL_BASE_NS
};
struct syswdog_armv8_m_dev_t SYSWDOG_ARMV8_M_DEV_NS = {
    &(SYSWDOG_ARMV8_M_DEV_CFG_NS)
};
#endif

/* ARM MPC RSE driver structures */
#ifdef MPC_VM0_S
/* Ranges controlled by this VM0_MPC */
static const struct mpc_sie_memory_range_t MPC_VM0_RANGE_S = {
    .base         = MPC_VM0_RANGE_BASE_S,
    .limit        = MPC_VM0_RANGE_LIMIT_S,
    .range_offset = 0,
    .attr         = MPC_SIE_SEC_ATTR_SECURE
};

static const struct mpc_sie_memory_range_t MPC_VM0_RANGE_NS = {
    .base         = MPC_VM0_RANGE_BASE_NS,
    .limit        = MPC_VM0_RANGE_LIMIT_NS,
    .range_offset = 0,
    .attr         = MPC_SIE_SEC_ATTR_NONSECURE
};

#define MPC_VM0_RANGE_LIST_LEN  2u
static const struct mpc_sie_memory_range_t*
    MPC_VM0_RANGE_LIST[MPC_VM0_RANGE_LIST_LEN] = {
        &MPC_VM0_RANGE_S,
        &MPC_VM0_RANGE_NS
    };

static const struct mpc_sie_dev_cfg_t MPC_VM0_DEV_CFG_S = {
    .base = MPC_VM0_BASE_S,
    .range_list = MPC_VM0_RANGE_LIST,
    .nbr_of_ranges = MPC_VM0_RANGE_LIST_LEN};
static struct mpc_sie_dev_data_t MPC_VM0_DEV_DATA_S = {
    .is_initialized = false };
struct mpc_sie_dev_t MPC_VM0_DEV_S = {
    &(MPC_VM0_DEV_CFG_S),
    &(MPC_VM0_DEV_DATA_S)};
#endif

#ifdef MPC_VM1_S
/* Ranges controlled by this VM1_MPC */
static const struct mpc_sie_memory_range_t MPC_VM1_RANGE_S = {
    .base         = MPC_VM1_RANGE_BASE_S,
    .limit        = MPC_VM1_RANGE_LIMIT_S,
    .range_offset = 0,
    .attr         = MPC_SIE_SEC_ATTR_SECURE
};

static const struct mpc_sie_memory_range_t MPC_VM1_RANGE_NS = {
    .base         = MPC_VM1_RANGE_BASE_NS,
    .limit        = MPC_VM1_RANGE_LIMIT_NS,
    .range_offset = 0,
    .attr         = MPC_SIE_SEC_ATTR_NONSECURE
};

#define MPC_VM1_RANGE_LIST_LEN  2u
static const struct mpc_sie_memory_range_t*
    MPC_VM1_RANGE_LIST[MPC_VM1_RANGE_LIST_LEN] = {
        &MPC_VM1_RANGE_S,
        &MPC_VM1_RANGE_NS
    };

static const struct mpc_sie_dev_cfg_t MPC_VM1_DEV_CFG_S = {
    .base = MPC_VM1_BASE_S,
    .range_list = MPC_VM1_RANGE_LIST,
    .nbr_of_ranges = MPC_VM1_RANGE_LIST_LEN};
static struct mpc_sie_dev_data_t MPC_VM1_DEV_DATA_S = {
    .is_initialized = false };
struct mpc_sie_dev_t MPC_VM1_DEV_S = {
    &(MPC_VM1_DEV_CFG_S),
    &(MPC_VM1_DEV_DATA_S)};
#endif

#ifdef MPC_SIC_S
/* Ranges controlled by this SIC_MPC */
static const struct mpc_sie_memory_range_t MPC_SIC_RANGE_S = {
    .base         = MPC_SIC_RANGE_BASE_S,
    .limit        = MPC_SIC_RANGE_LIMIT_S,
    .range_offset = 0,
    .attr         = MPC_SIE_SEC_ATTR_SECURE
};

static const struct mpc_sie_memory_range_t MPC_SIC_RANGE_NS = {
    .base         = MPC_SIC_RANGE_BASE_NS,
    .limit        = MPC_SIC_RANGE_LIMIT_NS,
    .range_offset = 0,
    .attr         = MPC_SIE_SEC_ATTR_NONSECURE
};

#define MPC_SIC_RANGE_LIST_LEN  2u
static const struct mpc_sie_memory_range_t*
    MPC_SIC_RANGE_LIST[MPC_SIC_RANGE_LIST_LEN] = {
        &MPC_SIC_RANGE_S,
        &MPC_SIC_RANGE_NS
    };

static const struct mpc_sie_dev_cfg_t MPC_SIC_DEV_CFG_S = {
    .base = MPC_SIC_BASE_S,
    .range_list = MPC_SIC_RANGE_LIST,
    .nbr_of_ranges = MPC_SIC_RANGE_LIST_LEN};
static struct mpc_sie_dev_data_t MPC_SIC_DEV_DATA_S = {
    .is_initialized = false };
struct mpc_sie_dev_t MPC_SIC_DEV_S = {
    &(MPC_SIC_DEV_CFG_S),
    &(MPC_SIC_DEV_DATA_S)};
#endif

#ifdef KMU_S
static struct kmu_dev_cfg_t KMU_DEV_CFG_S = {
    .base = KMU_BASE_S
};
struct kmu_dev_t KMU_DEV_S = {
    .cfg = &(KMU_DEV_CFG_S)
};
#endif

#ifdef SAM_S
static const struct sam_dev_cfg_t SAM_DEV_CFG_S = {
    .base = SAM_BASE_S,
};
struct sam_dev_t SAM_DEV_S = {
    .cfg = &SAM_DEV_CFG_S,
    .event_handlers = {0},
};
#endif

#ifdef LCM_S
static struct lcm_dev_cfg_t LCM_DEV_CFG_S = {
    .base = LCM_BASE_S
};
struct lcm_dev_t LCM_DEV_S = {
    .cfg = &(LCM_DEV_CFG_S)
};
#endif

#ifdef INTEGRITY_CHECKER_S
static struct integrity_checker_dev_cfg_t INTEGRITY_CHECKER_DEV_CFG_S = {
    .base = INTEGRITY_CHECKER_BASE_S,
    .remap_cpusel = 0,
    .remap_regions = {
        {ITCM_BASE_S, ITCM_SIZE, ITCM_CPU0_BASE_S, 0x01000000},
        {ITCM_BASE_NS, ITCM_SIZE, ITCM_CPU0_BASE_NS, 0x01000000},
        {DTCM_BASE_S, DTCM_SIZE, DTCM_CPU0_BASE_S, 0x01000000},
        {DTCM_BASE_NS, DTCM_SIZE, DTCM_CPU0_BASE_NS, 0x01000000},
    }
};
struct integrity_checker_dev_t INTEGRITY_CHECKER_DEV_S = {
    .cfg = &(INTEGRITY_CHECKER_DEV_CFG_S)
};
#endif

#ifdef DCSU_S
static struct dcsu_dev_cfg_t DCSU_DEV_CFG_S = {
    .base = DCSU_BASE_S
};
struct dcsu_dev_t DCSU_DEV_S = {
    .cfg = &(DCSU_DEV_CFG_S),
    .rx_buf = NULL,
    .rx_buf_len = 0,
    .rx_buf_offset = 0,
    .handler = NULL,
};
#endif

#ifdef DMA350_DMA0_S
static const struct dma350_dev_cfg_t DMA350_DMA0_DEV_CFG_S = {
    .dma_sec_cfg =   (DMASECCFG_TypeDef*)   (DMA_350_BASE_S + 0x0UL),
    .dma_sec_ctrl =  (DMASECCTRL_TypeDef*)  (DMA_350_BASE_S + 0x100UL),
    .dma_nsec_ctrl = (DMANSECCTRL_TypeDef*) (DMA_350_BASE_S + 0x200UL),
    .dma_info =      (DMAINFO_TypeDef*)     (DMA_350_BASE_S + 0xF00UL)
};
static struct dma350_dev_data_t DMA350_DMA0_DEV_DATA_S = {
    .state = 0
};
struct dma350_dev_t DMA350_DMA0_DEV_S = {
    &(DMA350_DMA0_DEV_CFG_S),
    &(DMA350_DMA0_DEV_DATA_S)
};
#endif

#ifdef DMA350_DMA0_CH0_S
struct dma350_ch_dev_t DMA350_DMA0_CH0_DEV_S = {
    .cfg = {.ch_base = (DMACH_TypeDef*) (DMA_350_BASE_S + 0x1000UL),
            .channel = 0},
    .data = {0}
};
#endif

#ifdef DMA350_DMA0_CH1_S
struct dma350_ch_dev_t DMA350_DMA0_CH1_DEV_S = {
    .cfg = {.ch_base = (DMACH_TypeDef*) (DMA_350_BASE_S + 0x1100UL),
            .channel = 1},
    .data = {0}
};
#endif

#ifdef DMA350_DMA0_CH2_S
struct dma350_ch_dev_t DMA350_DMA0_CH2_DEV_S = {
    .cfg = {.ch_base = (DMACH_TypeDef*) (DMA_350_BASE_S + 0x1200UL),
            .channel = 2},
    .data = {0}
};
#endif

#ifdef DMA350_DMA0_CH3_S
struct dma350_ch_dev_t DMA350_DMA0_CH3_DEV_S = {
    .cfg = {.ch_base = (DMACH_TypeDef*) (DMA_350_BASE_S + 0x1300UL),
            .channel = 3},
    .data = {0}
};
#endif

#ifdef GPIO0_S
pl061_regblk_t *const GPIO0_DEV_S = (pl061_regblk_t *) GPIO0_BASE_S;
#endif

#ifdef GPIO1_S
pl061_regblk_t *const GPIO1_DEV_S = (pl061_regblk_t *) GPIO1_BASE_S;
#endif

#ifdef GPIO0_NS
pl061_regblk_t *const GPIO0_DEV_NS = (pl061_regblk_t *) GPIO0_BASE_NS;
#endif

#ifdef GPIO1_NS
pl061_regblk_t *const GPIO1_DEV_NS = (pl061_regblk_t *) GPIO1_BASE_NS;
#endif

/* Legacy MHUv2 support for TC2 */
#if PLAT_MHU_VERSION == 2

#ifdef MHU0_S
struct mhu_v2_x_dev_t MHU0_SENDER_DEV_S = {
    2,
    MHU0_SENDER_BASE_S,
    MHU_V2_X_SENDER_FRAME,
};
struct mhu_v2_x_dev_t MHU0_RECEIVER_DEV_S = {
    2,
    MHU0_RECEIVER_BASE_S,
    MHU_V2_X_RECEIVER_FRAME,
};
#endif

#ifdef MHU1_S
struct mhu_v2_x_dev_t MHU1_SENDER_DEV_S = {
    2,
    MHU1_SENDER_BASE_S,
    MHU_V2_X_SENDER_FRAME,
};
struct mhu_v2_x_dev_t MHU1_RECEIVER_DEV_S = {
    2,
    MHU1_RECEIVER_BASE_S,
    MHU_V2_X_RECEIVER_FRAME,
};
#endif

#ifdef MHU2_S
struct mhu_v2_x_dev_t MHU2_SENDER_DEV_S = {
    2,
    MHU2_SENDER_BASE_S,
    MHU_V2_X_SENDER_FRAME,
};
struct mhu_v2_x_dev_t MHU2_RECEIVER_DEV_S = {
    2,
    MHU2_RECEIVER_BASE_S,
    MHU_V2_X_RECEIVER_FRAME,
};
#endif

#else /* PLAT_MHU_VERSION == 2 */

#ifdef MHU0_S
struct mhu_v3_x_dev_t MHU0_SENDER_DEV_S = {
    3,
    MHU0_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU0_RECEIVER_DEV_S = {
    3,
    MHU0_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU1_S
struct mhu_v3_x_dev_t MHU1_SENDER_DEV_S = {
    3,
    MHU1_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU1_RECEIVER_DEV_S = {
    3,
    MHU1_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU2_S
struct mhu_v3_x_dev_t MHU2_SENDER_DEV_S = {
    3,
    MHU2_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU2_RECEIVER_DEV_S = {
    3,
    MHU2_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU3_S
struct mhu_v3_x_dev_t MHU3_SENDER_DEV_S = {
    3,
    MHU3_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU3_RECEIVER_DEV_S = {
    3,
    MHU3_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU4_S
struct mhu_v3_x_dev_t MHU4_SENDER_DEV_S = {
    3,
    MHU4_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU4_RECEIVER_DEV_S = {
    3,
    MHU4_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU5_S
struct mhu_v3_x_dev_t MHU5_SENDER_DEV_S = {
    3,
    MHU5_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU5_RECEIVER_DEV_S = {
    3,
    MHU5_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU6_S
struct mhu_v3_x_dev_t MHU6_SENDER_DEV_S = {
    3,
    MHU6_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU6_RECEIVER_DEV_S = {
    3,
    MHU6_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU7_S
struct mhu_v3_x_dev_t MHU7_SENDER_DEV_S = {
    3,
    MHU7_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU7_RECEIVER_DEV_S = {
    3,
    MHU7_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#ifdef MHU8_S
struct mhu_v3_x_dev_t MHU8_SENDER_DEV_S = {
    3,
    MHU8_SENDER_BASE_S,
    MHU_V3_X_PBX_FRAME,
};
struct mhu_v3_x_dev_t MHU8_RECEIVER_DEV_S = {
    3,
    MHU8_RECEIVER_BASE_S,
    MHU_V3_X_MBX_FRAME,
};
#endif

#endif /* PLAT_MHU_VERSION == 2 */
