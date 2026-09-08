/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <errno.h>
#include <inttypes.h>

#include <stm32mp_ddr_debug.h>
#include <lib/delay.h>
#include <stm32mp_ddr.h>
#include <stm32mp2_ddr_helpers.h>
#include <stm32mp2_ddr_regs.h>
#include <lib/mmio.h>
#ifdef STM32MP21xxxx
#include <stm32mp21_rcc.h>
#else
#include <stm32mp25_rcc.h>
#endif
#include <stm32mp2_pwr.h>

#include <ddrphy_phyinit.h>

#define DDRDBG_FRAC_PLL_LOCK	U(0x10)

#define DDRCTL_REG(x, y, z)					\
	{							\
		.offset = offsetof(struct stm32mp_ddrctl, x),	\
		.par_offset = offsetof(struct y, x),		\
		.qd = z						\
	}

/*
 * PARAMETERS: value get from device tree :
 *             size / order need to be aligned with binding
 *             modification NOT ALLOWED !!!
 */
#define DDRCTL_REG_REG_SIZE	48	/* st,ctl-reg */
#define DDRCTL_REG_TIMING_SIZE	20	/* st,ctl-timing */
#define DDRCTL_REG_MAP_SIZE	12	/* st,ctl-map */
#define DDRCTL_REG_PERF_SIZE	21	/* st,ctl-perf */

#define DDRPHY_REG_REG_SIZE	0	/* st,phy-reg */
#define	DDRPHY_REG_TIMING_SIZE	0	/* st,phy-timing */

#define DDRCTL_REG_REG(x, z)	DDRCTL_REG(x, stm32mp2_ddrctrl_reg, z)
static const struct stm32mp_ddr_reg_desc ddr_reg[DDRCTL_REG_REG_SIZE] = {
	DDRCTL_REG_REG(mstr, true),
	DDRCTL_REG_REG(mrctrl0, false),
	DDRCTL_REG_REG(mrctrl1, false),
	DDRCTL_REG_REG(mrctrl2, false),
	DDRCTL_REG_REG(derateen, true),
	DDRCTL_REG_REG(derateint, false),
	DDRCTL_REG_REG(deratectl, false),
	DDRCTL_REG_REG(pwrctl, false),
	DDRCTL_REG_REG(pwrtmg, true),
	DDRCTL_REG_REG(hwlpctl, true),
	DDRCTL_REG_REG(rfshctl0, false),
	DDRCTL_REG_REG(rfshctl1, false),
	DDRCTL_REG_REG(rfshctl3, true),
	DDRCTL_REG_REG(crcparctl0, false),
	DDRCTL_REG_REG(crcparctl1, false),
	DDRCTL_REG_REG(init0, true),
	DDRCTL_REG_REG(init1, false),
	DDRCTL_REG_REG(init2, false),
	DDRCTL_REG_REG(init3, true),
	DDRCTL_REG_REG(init4, true),
	DDRCTL_REG_REG(init5, false),
	DDRCTL_REG_REG(init6, true),
	DDRCTL_REG_REG(init7, true),
	DDRCTL_REG_REG(dimmctl, false),
	DDRCTL_REG_REG(rankctl, true),
	DDRCTL_REG_REG(rankctl1, true),
	DDRCTL_REG_REG(zqctl0, true),
	DDRCTL_REG_REG(zqctl1, false),
	DDRCTL_REG_REG(zqctl2, false),
	DDRCTL_REG_REG(dfitmg0, true),
	DDRCTL_REG_REG(dfitmg1, true),
	DDRCTL_REG_REG(dfilpcfg0, false),
	DDRCTL_REG_REG(dfilpcfg1, false),
	DDRCTL_REG_REG(dfiupd0, true),
	DDRCTL_REG_REG(dfiupd1, false),
	DDRCTL_REG_REG(dfiupd2, false),
	DDRCTL_REG_REG(dfimisc, true),
	DDRCTL_REG_REG(dfitmg2, true),
	DDRCTL_REG_REG(dfitmg3, false),
	DDRCTL_REG_REG(dbictl, true),
	DDRCTL_REG_REG(dfiphymstr, false),
	DDRCTL_REG_REG(dbg0, false),
	DDRCTL_REG_REG(dbg1, false),
	DDRCTL_REG_REG(dbgcmd, false),
	DDRCTL_REG_REG(swctl, false), /* forced qd value */
	DDRCTL_REG_REG(swctlstatic, false),
	DDRCTL_REG_REG(poisoncfg, false),
	DDRCTL_REG_REG(pccfg, false),
};

#define DDRCTL_REG_TIMING(x, z)	DDRCTL_REG(x, stm32mp2_ddrctrl_timing, z)
static const struct stm32mp_ddr_reg_desc ddr_timing[DDRCTL_REG_TIMING_SIZE] = {
	DDRCTL_REG_TIMING(rfshtmg, false),
	DDRCTL_REG_TIMING(rfshtmg1, false),
	DDRCTL_REG_TIMING(dramtmg0, true),
	DDRCTL_REG_TIMING(dramtmg1, true),
	DDRCTL_REG_TIMING(dramtmg2, true),
	DDRCTL_REG_TIMING(dramtmg3, true),
	DDRCTL_REG_TIMING(dramtmg4, true),
	DDRCTL_REG_TIMING(dramtmg5, true),
	DDRCTL_REG_TIMING(dramtmg6, true),
	DDRCTL_REG_TIMING(dramtmg7, true),
	DDRCTL_REG_TIMING(dramtmg8, true),
	DDRCTL_REG_TIMING(dramtmg9, true),
	DDRCTL_REG_TIMING(dramtmg10, true),
	DDRCTL_REG_TIMING(dramtmg11, true),
	DDRCTL_REG_TIMING(dramtmg12, true),
	DDRCTL_REG_TIMING(dramtmg13, true),
	DDRCTL_REG_TIMING(dramtmg14, true),
	DDRCTL_REG_TIMING(dramtmg15, true),
	DDRCTL_REG_TIMING(odtcfg, true),
	DDRCTL_REG_TIMING(odtmap, false),
};

#define DDRCTL_REG_MAP(x)	DDRCTL_REG(x, stm32mp2_ddrctrl_map, false)
static const struct stm32mp_ddr_reg_desc ddr_map[DDRCTL_REG_MAP_SIZE] = {
	DDRCTL_REG_MAP(addrmap0),
	DDRCTL_REG_MAP(addrmap1),
	DDRCTL_REG_MAP(addrmap2),
	DDRCTL_REG_MAP(addrmap3),
	DDRCTL_REG_MAP(addrmap4),
	DDRCTL_REG_MAP(addrmap5),
	DDRCTL_REG_MAP(addrmap6),
	DDRCTL_REG_MAP(addrmap7),
	DDRCTL_REG_MAP(addrmap8),
	DDRCTL_REG_MAP(addrmap9),
	DDRCTL_REG_MAP(addrmap10),
	DDRCTL_REG_MAP(addrmap11),
};

#define DDRCTL_REG_PERF(x, z)	DDRCTL_REG(x, stm32mp2_ddrctrl_perf, z)
static const struct stm32mp_ddr_reg_desc ddr_perf[DDRCTL_REG_PERF_SIZE] = {
	DDRCTL_REG_PERF(sched, true),
	DDRCTL_REG_PERF(sched1, false),
	DDRCTL_REG_PERF(perfhpr1, true),
	DDRCTL_REG_PERF(perflpr1, true),
	DDRCTL_REG_PERF(perfwr1, true),
	DDRCTL_REG_PERF(sched3, false),
	DDRCTL_REG_PERF(sched4, false),
	DDRCTL_REG_PERF(pcfgr_0, false),
	DDRCTL_REG_PERF(pcfgw_0, false),
	DDRCTL_REG_PERF(pctrl_0, false),
	DDRCTL_REG_PERF(pcfgqos0_0, true),
	DDRCTL_REG_PERF(pcfgqos1_0, true),
	DDRCTL_REG_PERF(pcfgwqos0_0, true),
	DDRCTL_REG_PERF(pcfgwqos1_0, true),
	DDRCTL_REG_PERF(pcfgr_1, false),
	DDRCTL_REG_PERF(pcfgw_1, false),
	DDRCTL_REG_PERF(pctrl_1, false),
	DDRCTL_REG_PERF(pcfgqos0_1, true),
	DDRCTL_REG_PERF(pcfgqos1_1, true),
	DDRCTL_REG_PERF(pcfgwqos0_1, true),
	DDRCTL_REG_PERF(pcfgwqos1_1, true),
};

static const struct stm32mp_ddr_reg_desc ddrphy_reg[DDRPHY_REG_REG_SIZE] = {};

static const struct stm32mp_ddr_reg_desc ddrphy_timing[DDRPHY_REG_TIMING_SIZE] = {};

/*
 * REGISTERS ARRAY: used to parse device tree and interactive mode
 */
static const struct stm32mp_ddr_reg_info ddr_registers[REG_TYPE_NB] __unused = {
	[REG_REG] = {
		.name = "static",
		.desc = ddr_reg,
		.size = DDRCTL_REG_REG_SIZE,
		.base = DDR_BASE
	},
	[REG_TIMING] = {
		.name = "timing",
		.desc = ddr_timing,
		.size = DDRCTL_REG_TIMING_SIZE,
		.base = DDR_BASE
	},
	[REG_PERF] = {
		.name = "perf",
		.desc = ddr_perf,
		.size = DDRCTL_REG_PERF_SIZE,
		.base = DDR_BASE
	},
	[REG_MAP] = {
		.name = "map",
		.desc = ddr_map,
		.size = DDRCTL_REG_MAP_SIZE,
		.base = DDR_BASE
	},
	[REGPHY_REG] = {
		.name = "static",
		.desc = ddrphy_reg,
		.size = DDRPHY_REG_REG_SIZE,
		.base = DDRPHY_BASE
	},
	[REGPHY_TIMING] = {
		.name = "timing",
		.desc = ddrphy_timing,
		.size = DDRPHY_REG_TIMING_SIZE,
		.base = DDRPHY_BASE
	},
};

static void ddr_reset(struct stm32mp_ddr_priv *priv)
{
	udelay(DDR_DELAY_1US);

	mmio_setbits_32(priv->rcc + RCC_DDRITFCFGR, RCC_DDRITFCFGR_DDRRST);
	mmio_write_32(priv->rcc + RCC_DDRPHYCAPBCFGR,
		      RCC_DDRPHYCAPBCFGR_DDRPHYCAPBEN | RCC_DDRPHYCAPBCFGR_DDRPHYCAPBLPEN |
		      RCC_DDRPHYCAPBCFGR_DDRPHYCAPBRST);
	mmio_write_32(priv->rcc + RCC_DDRCAPBCFGR,
		      RCC_DDRCAPBCFGR_DDRCAPBEN | RCC_DDRCAPBCFGR_DDRCAPBLPEN |
		      RCC_DDRCAPBCFGR_DDRCAPBRST);
	mmio_write_32(priv->rcc + RCC_DDRCFGR,
		      RCC_DDRCFGR_DDRCFGEN | RCC_DDRCFGR_DDRCFGLPEN | RCC_DDRCFGR_DDRCFGRST);

	udelay(DDR_DELAY_1US);

	mmio_setbits_32(priv->rcc + RCC_DDRITFCFGR, RCC_DDRITFCFGR_DDRRST);
	mmio_write_32(priv->rcc + RCC_DDRPHYCAPBCFGR,
		      RCC_DDRPHYCAPBCFGR_DDRPHYCAPBEN | RCC_DDRPHYCAPBCFGR_DDRPHYCAPBLPEN);
	mmio_write_32(priv->rcc + RCC_DDRCAPBCFGR,
		      RCC_DDRCAPBCFGR_DDRCAPBEN | RCC_DDRCAPBCFGR_DDRCAPBLPEN);
	mmio_write_32(priv->rcc + RCC_DDRCFGR, RCC_DDRCFGR_DDRCFGEN | RCC_DDRCFGR_DDRCFGLPEN);

	udelay(DDR_DELAY_1US);
}

static void ddr_sysconf_configuration(struct stm32mp_ddr_priv *priv,
				      const struct stm32mp_ddr_config *config)
{
	mmio_write_32(stm32_ddrdbg_get_base() + DDRDBG_LP_DISABLE,
		      _DDRDBG_LP_DISABLE_LPI_XPI_DISABLE | _DDRDBG_LP_DISABLE_LPI_DDRC_DISABLE);

	mmio_write_32(stm32_ddrdbg_get_base() + DDRDBG_BYPASS_PCLKEN,
		      (uint32_t)config->uib.pllbypass);

	mmio_write_32(priv->rcc + RCC_DDRPHYCCFGR, RCC_DDRPHYCCFGR_DDRPHYCEN);
	mmio_setbits_32(priv->rcc + RCC_DDRITFCFGR, RCC_DDRITFCFGR_DDRRST);

	udelay(DDR_DELAY_1US);
}

static void set_dfi_init_complete_en(struct stm32mp_ddrctl *ctl, bool phy_init_done)
{
	/*
	 * Manage quasi-dynamic registers modification
	 * dfimisc.dfi_init_complete_en : Group 3
	 */
	stm32mp_ddr_set_qd3_update_conditions(ctl);

	udelay(DDR_DELAY_1US);

	if (phy_init_done) {
		/* Indicates to controller that PHY has completed initialization */
		mmio_setbits_32((uintptr_t)&ctl->dfimisc, DDRCTRL_DFIMISC_DFI_INIT_COMPLETE_EN);
	} else {
		/* PHY not initialized yet, wait for completion */
		mmio_clrbits_32((uintptr_t)&ctl->dfimisc, DDRCTRL_DFIMISC_DFI_INIT_COMPLETE_EN);
	}

	udelay(DDR_DELAY_1US);

	stm32mp_ddr_unset_qd3_update_conditions(ctl);

}

static void disable_refresh(struct stm32mp_ddrctl *ctl)
{
	mmio_setbits_32((uintptr_t)&ctl->rfshctl3, DDRCTRL_RFSHCTL3_DIS_AUTO_REFRESH);

	stm32mp_ddr_wait_refresh_update_done_ack(ctl);

	udelay(DDR_DELAY_1US);

	mmio_clrbits_32((uintptr_t)&ctl->pwrctl,
			DDRCTRL_PWRCTL_POWERDOWN_EN | DDRCTRL_PWRCTL_SELFREF_EN);

	udelay(DDR_DELAY_1US);

	set_dfi_init_complete_en(ctl, false);
}

static void restore_refresh(struct stm32mp_ddrctl *ctl, uint32_t rfshctl3, uint32_t pwrctl)
{
	if ((rfshctl3 & DDRCTRL_RFSHCTL3_DIS_AUTO_REFRESH) == 0U) {
		mmio_clrbits_32((uintptr_t)&ctl->rfshctl3, DDRCTRL_RFSHCTL3_DIS_AUTO_REFRESH);

		stm32mp_ddr_wait_refresh_update_done_ack(ctl);

		udelay(DDR_DELAY_1US);
	}

	/* Always disable PWRCTL.SELFREF_SW on LPDDR4 */
#if !STM32MP_LPDDR4_TYPE
	if ((pwrctl & DDRCTRL_PWRCTL_SELFREF_SW) != 0U)
#endif /* !STM32MP_LPDDR4_TYPE */
	{
		mmio_clrbits_32((uintptr_t)&ctl->pwrctl, DDRCTRL_PWRCTL_SELFREF_SW);

		udelay(DDR_DELAY_1US);
	}

	if ((pwrctl & DDRCTRL_PWRCTL_POWERDOWN_EN) != 0U) {
		mmio_setbits_32((uintptr_t)&ctl->pwrctl, DDRCTRL_PWRCTL_POWERDOWN_EN);

		udelay(DDR_DELAY_1US);
	}

	if ((pwrctl & DDRCTRL_PWRCTL_SELFREF_EN) != 0U) {
		mmio_setbits_32((uintptr_t)&ctl->pwrctl, DDRCTRL_PWRCTL_SELFREF_EN);

		udelay(DDR_DELAY_1US);
	}

	set_dfi_init_complete_en(ctl, true);
}

void stm32mp2_ddr_init(struct stm32mp_ddr_priv *priv,
		       const struct stm32mp_ddr_config *config)
{
	int ret;
	enum ddr_type ddr_type;
	bool cid_filtering = is_ddr_cid_filtering_enabled();

	if ((config->c_reg.mstr & DDRCTRL_MSTR_DDR3) != 0U) {
		ddr_type = STM32MP_DDR3;
	} else if ((config->c_reg.mstr & DDRCTRL_MSTR_DDR4) != 0U) {
		ddr_type = STM32MP_DDR4;
	} else if ((config->c_reg.mstr & DDRCTRL_MSTR_LPDDR4) != 0U) {
		ddr_type = STM32MP_LPDDR4;
	} else {
		DDR_ERROR("DDR type not supported\n");
		panic();
	}

	DDR_VERBOSE("name = %s\n", config->info.name);
	DDR_VERBOSE("speed = %u kHz\n", config->info.speed);
	/*
	 * This driver is used in BL2 with minimal printf implementation.
	 * Long long formatters such as %llx are not supported in this case.
	 * To avoid using 64bit format specifier, the size is printed in two 32bit values.
	 */
	DDR_VERBOSE("size  = 0x%zx 0x%zx\n",
		    (uint32_t)(config->info.size >> 32),
		    (uint32_t)(config->info.size & 0xFFFFFFFF));

	if (stm32mp_board_ddr_power_init(ddr_type) != 0) {
		DDR_ERROR("DDR power init failed\n");
		panic();
	}

	ddr_reset(priv);

	ddr_sysconf_configuration(priv, config);

	stm32mp_ddr_set_reg(priv, REG_REG, &config->c_reg, ddr_registers);
	stm32mp_ddr_set_reg(priv, REG_TIMING, &config->c_timing, ddr_registers);
	stm32mp_ddr_set_reg(priv, REG_MAP, &config->c_map, ddr_registers);
	stm32mp_ddr_set_reg(priv, REG_PERF, &config->c_perf, ddr_registers);

	DDR_VERBOSE("disable DDR PHY retention\n");
	if (cid_filtering) {
		ddr_disable_cid_filtering();
	}
	stm32_pwr_ddr_retention_set(priv->pwr, false);
	if (cid_filtering) {
		ddr_enable_cid_filtering();
	}

	udelay(DDR_DELAY_1US);

	/* DDR core and PHY reset de-assert */
	mmio_clrbits_32(priv->rcc + RCC_DDRITFCFGR, RCC_DDRITFCFGR_DDRRST);

	udelay(DDR_DELAY_1US);

	disable_refresh(priv->ctl);

	/* Initialize DDR including training */
	ret = ddrphy_phyinit_sequence(config);
	if (ret != 0) {
		DDR_ERROR("DDR PHY init: Error %d\n", ret);
		panic();
	}

	ddr_activate_controller(priv->ctl);

	restore_refresh(priv->ctl, config->c_reg.rfshctl3, config->c_reg.pwrctl);

	stm32mp_ddr_enable_axi_port(priv->ctl);
}
