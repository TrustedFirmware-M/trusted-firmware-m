/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <errno.h>

#include <stm32mp_ddr_debug.h>
#include <lib/delay.h>
#include <lib/timeout.h>
#include <stm32mp_ddr.h>
#include <stm32mp2_ddr.h>
#include <stm32mp2_ddr_helpers.h>
#include <stm32mp2_ddr_regs.h>
#include <lib/mmio.h>
#ifdef STM32MP21xxxx
#include <stm32mp21_rcc.h>
#else
#include <stm32mp25_rcc.h>
#endif
#include <stm32mp2_pwr.h>

/* HW idle period (unit: Multiples of 32 DFI clock cycles) */
#define HW_IDLE_PERIOD			0x3U

static enum stm32mp2_ddr_sr_mode saved_ddr_sr_mode;
static uint32_t saved_sem_mutex;

static void set_qd1_qd3_update_conditions(struct stm32mp_ddrctl *ctl)
{
	mmio_setbits_32((uintptr_t)&ctl->dbg1, DDRCTRL_DBG1_DIS_DQ);

	stm32mp_ddr_set_qd3_update_conditions(ctl);
}

static void unset_qd1_qd3_update_conditions(struct stm32mp_ddrctl *ctl)
{
	stm32mp_ddr_unset_qd3_update_conditions(ctl);

	mmio_clrbits_32((uintptr_t)&ctl->dbg1, DDRCTRL_DBG1_DIS_DQ);
}

static void wait_dfi_init_complete(struct stm32mp_ddrctl *ctl)
{
	uint64_t timeout;
	uint32_t dfistat;

	timeout = timeout_init_us(DDR_TIMEOUT_US_1S);
	do {
		dfistat = mmio_read_32((uintptr_t)&ctl->dfistat);
		DDR_VERBOSE("[0x%" PRIxPTR "] dfistat = 0x%" PRIx32 "\n",
			    (uintptr_t)&ctl->dfistat, dfistat);

		if (timeout_elapsed(timeout)) {
			panic();
		}
	} while ((dfistat & DDRCTRL_DFISTAT_DFI_INIT_COMPLETE) == 0U);

	DDR_VERBOSE("[0x%" PRIxPTR "] dfistat = 0x%" PRIx32 "\n",
		    (uintptr_t)&ctl->dfistat, dfistat);
}

void ddr_activate_controller(struct stm32mp_ddrctl *ctl)
{
	/*
	 * Manage quasi-dynamic registers modification
	 * dfimisc.dfi_frequency : Group 1
	 * dfimisc.dfi_init_complete_en and dfimisc.dfi_init_start : Group 3
	 */
	set_qd1_qd3_update_conditions(ctl);

	mmio_clrbits_32((uintptr_t)&ctl->dfimisc, DDRCTRL_DFIMISC_DFI_FREQUENCY);
	mmio_setbits_32((uintptr_t)&ctl->dfimisc, DDRCTRL_DFIMISC_DFI_INIT_START);
	mmio_clrbits_32((uintptr_t)&ctl->dfimisc, DDRCTRL_DFIMISC_DFI_INIT_START);

	wait_dfi_init_complete(ctl);

	udelay(DDR_DELAY_1US);

	mmio_setbits_32((uintptr_t)&ctl->dfimisc, DDRCTRL_DFIMISC_DFI_INIT_COMPLETE_EN);

	udelay(DDR_DELAY_1US);

	unset_qd1_qd3_update_conditions(ctl);
}

bool is_ddr_cid_filtering_enabled(void)
{
	return (mmio_read_32(stm32mp_rcc_base() + RCC_R104CIDCFGR) & RCC_RxCIDCFGR_CFEN) ==
	       RCC_RxCIDCFGR_CFEN;
}

void ddr_enable_cid_filtering(void)
{
	mmio_setbits_32(stm32mp_rcc_base() + RCC_R104CIDCFGR, RCC_RxCIDCFGR_CFEN);
	if (saved_sem_mutex != 0U) {
		mmio_setbits_32(stm32mp_rcc_base() + RCC_R104SEMCR, RCC_RxSEMCR_SEM_MUTEX);
	}
}

void ddr_disable_cid_filtering(void)
{
	saved_sem_mutex = mmio_read_32(stm32mp_rcc_base() + RCC_R104SEMCR) & RCC_RxSEMCR_SEM_MUTEX;
	mmio_clrbits_32(stm32mp_rcc_base() + RCC_R104CIDCFGR, RCC_RxCIDCFGR_CFEN);
}

static int sr_ssr_set(void)
{
	uintptr_t ddrctrl_base = stm32mp_ddrctrl_base();

	/*
	 * Disable Clock disable with LP modes
	 * (used in RUN mode for LPDDR2 with specific timing).
	*/
	mmio_clrbits_32(ddrctrl_base + DDRCTRL_PWRCTL, DDRCTRL_PWRCTL_EN_DFI_DRAM_CLK_DISABLE);

	/* Disable automatic Self-Refresh mode */
	mmio_clrbits_32(ddrctrl_base + DDRCTRL_PWRCTL, DDRCTRL_PWRCTL_SELFREF_EN);

	mmio_write_32(stm32_ddrdbg_get_base() + DDRDBG_LP_DISABLE,
		      _DDRDBG_LP_DISABLE_LPI_XPI_DISABLE | _DDRDBG_LP_DISABLE_LPI_DDRC_DISABLE);

	return 0;
}

static int sr_hsr_set(void)
{
	uintptr_t ddrctrl_base = stm32mp_ddrctrl_base();

	mmio_clrsetbits_32(stm32mp_rcc_base() + RCC_DDRITFCFGR,
			   _RCC_DDRITFCFGR_DDRCKMOD_MASK, _RCC_DDRITFCFGR_DDRCKMOD_HSR);

	/*
	 * manage quasi-dynamic registers modification
	 * hwlpctl.hw_lp_en : Group 2
	 */
	if (stm32mp_ddr_sw_selfref_entry((struct stm32mp_ddrctl *)ddrctrl_base) != 0) {
		panic();
	}
	stm32mp_ddr_start_sw_done((struct stm32mp_ddrctl *)ddrctrl_base);

	mmio_write_32(ddrctrl_base + DDRCTRL_HWLPCTL,
		      DDRCTRL_HWLPCTL_HW_LP_EN | DDRCTRL_HWLPCTL_HW_LP_EXIT_IDLE_EN |
		      (HW_IDLE_PERIOD << DDRCTRL_HWLPCTL_HW_LP_IDLE_X32_SHIFT));

	stm32mp_ddr_wait_sw_done_ack((struct stm32mp_ddrctl *)ddrctrl_base);
	stm32mp_ddr_sw_selfref_exit((struct stm32mp_ddrctl *)ddrctrl_base);

	return 0;
}

static int sr_asr_set(void)
{
	mmio_write_32(stm32_ddrdbg_get_base() + DDRDBG_LP_DISABLE, 0U);

	return 0;
}

enum stm32mp2_ddr_sr_mode ddr_read_sr_mode(void)
{
	uint32_t pwrctl = mmio_read_32(stm32mp_ddrctrl_base() + DDRCTRL_PWRCTL);
	enum stm32mp2_ddr_sr_mode mode = DDR_SR_MODE_INVALID;

	switch (pwrctl & (DDRCTRL_PWRCTL_EN_DFI_DRAM_CLK_DISABLE |
			  DDRCTRL_PWRCTL_SELFREF_EN)) {
	case 0U:
		mode = DDR_SSR_MODE;
		break;
	case DDRCTRL_PWRCTL_EN_DFI_DRAM_CLK_DISABLE:
		mode = DDR_HSR_MODE;
		break;
	case DDRCTRL_PWRCTL_EN_DFI_DRAM_CLK_DISABLE | DDRCTRL_PWRCTL_SELFREF_EN:
		mode = DDR_ASR_MODE;
		break;
	default:
		break;
	}

	return mode;
}

void ddr_set_sr_mode(enum stm32mp2_ddr_sr_mode mode)
{
	int ret = -EINVAL;

	if (mode == saved_ddr_sr_mode) {
		return;
	}

	switch (mode) {
	case DDR_SSR_MODE:
		ret = sr_ssr_set();
		break;
	case DDR_HSR_MODE:
		ret = sr_hsr_set();
		break;
	case DDR_ASR_MODE:
		ret = sr_asr_set();
		break;
	default:
		break;
	}

	if (ret != 0) {
		DDR_ERROR("Unknown Self Refresh mode\n");
		panic();
	}

	saved_ddr_sr_mode = mode;
}
