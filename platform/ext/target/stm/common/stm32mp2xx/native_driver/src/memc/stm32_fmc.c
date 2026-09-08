/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_fmc2_ebi

#include <stdint.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <lib/timeout.h>
#include <inttypes.h>
#include <debug.h>
#include <errno.h>

#include <device.h>
#include <clk.h>
#include <reset.h>
#include <pinctrl.h>

#include <stm32_rif.h>

#include <pm/device.h>
#include <pm/pm.h>

/* FMC offset register */
#define _FMC_CFGR			U(0x020)
#define _FMC_SECCFGR			U(0x300)
#define _FMC_PRIVCFGR			U(0x304)
#define _FMC_PERX_CIDCFGR		U(0x30C)
#define _FMC_PERX_SEMCR			U(0x310)

/*
 * CFGR register bitfields
 */
#define _FMC_CFGR_CLKDIV_MASK		GENMASK_32(19, 16)
#define _FMC_CFGR_CLKDIV_SHIFT		U(16)
#define _FMC_CFGR_CCLKEN		BIT(20)
#define _FMC_CFGR_ENABLE		BIT(31)

/* RIF miscellaneous */
#define FMC_RIF_RES			U(6)

struct stm32_fmc_config {
	uintptr_t base;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct rifprot_controller *rif_ctl;
	const struct pinctrl_dev_config *pctrl_cfg;
	uint32_t clk_period_ns;
	bool cclken;
};

struct stm32_fmc_data {
	struct clk *clk;
};

static bool is_fmc_controller_secure(const struct device *dev, uint8_t ctl)
{
	const struct stm32_fmc_config *cfg = dev_get_config(dev);

	return io_read32(cfg->base + _FMC_SECCFGR) & BIT(ctl);
}

static int stm32_fmc_setup(const struct device *dev)
{
	const struct stm32_fmc_config *cfg = dev_get_config(dev);
	struct stm32_fmc_data *data = dev_get_data(dev);
	unsigned long hclk, hclkp, timing;
	uint32_t clk_div;
	int err;

	/* Check controller 0 access */
	if (!is_fmc_controller_secure(dev, 0)) {
		DMSG("Controller 0 non-secure, FMC not enabled\n");
		return 0;
	}

	/*
	 * the semaphore of resource 0 is acquired while set_conf if
	 * semwl=mycid and semaphore mode and filtering enabled
	 */

	err = pinctrl_apply_state_optional(cfg->pctrl_cfg,
					   PINCTRL_STATE_DEFAULT);
	if (err != 0)
		return err;

	if (cfg->cclken) {
		if (cfg->clk_period_ns == 0)
			return -EINVAL;

		hclk = clk_get_rate(data->clk);
		if (!hclk)
			return -EINVAL;

		hclkp = NSEC_PER_SEC / (hclk / 1000);
		timing = div_round_up(cfg->clk_period_ns * 1000, hclkp);
		clk_div = 1 << _FMC_CFGR_CLKDIV_SHIFT;

		if (timing > 1) {
			timing--;
			if (timing > _FLD_GET(_FMC_CFGR_CLKDIV, _FMC_CFGR_CLKDIV_MASK))
				clk_div = _FMC_CFGR_CLKDIV_MASK;
			else
				clk_div = _FLD_PREP(_FMC_CFGR_CLKDIV, timing);
		}

		io_clrsetbits32(cfg->base + _FMC_CFGR,
				_FMC_CFGR_CLKDIV_MASK | _FMC_CFGR_CCLKEN,
				clk_div | _FMC_CFGR_CCLKEN);
	}

	/* Set the FMC enable BIT */
	io_setbits32(cfg->base + _FMC_CFGR, _FMC_CFGR_ENABLE);

	return 0;
}

static __unused int stm32_fmc_init(const struct device *dev)
{
	const struct stm32_fmc_config *cfg = dev_get_config(dev);
	struct stm32_fmc_data *data = dev_get_data(dev);
	int err;

	if (!cfg || !data)
		return -ENODEV;

	data->clk = clk_get(cfg->clk_dev, cfg->clk_subsys);
	if (!data->clk)
		return -ENODEV;

	err = clk_enable(data->clk);
	if (err)
		return err;

	err = stm32_rifprot_init(cfg->rif_ctl);
	if (err)
		goto err;

	err = stm32_fmc_setup(dev);

err:
	clk_disable(data->clk);
	return err;
}

#ifdef CONFIG_PM_DEVICE
static __unused int stm32_fmc_pm_action(const struct device *dev,
					enum pm_device_action action,
					uint32_t pm_hint)
{
	const struct stm32_fmc_config *cfg = dev_get_config(dev);

	if (action == PM_DEVICE_ACTION_SUSPEND) {
		/* Check controller 0 access */
		if (!is_fmc_controller_secure(dev, 0)) {
			return 0;
		}

		return pinctrl_apply_state_optional(cfg->pctrl_cfg,
						    PINCTRL_STATE_SLEEP);
	}

	if (!PM_HINT_IS_STATE(pm_hint, CONTEXT)) {
		/* Check controller 0 access */
		if (!is_fmc_controller_secure(dev, 0)) {
			return 0;
		}

		return pinctrl_apply_state_optional(cfg->pctrl_cfg,
						    PINCTRL_STATE_DEFAULT);
	}

	return stm32_fmc_init(dev);
}
#endif

#define STM32_FMC_INIT(n)								\
											\
static __unused const struct rif_base rbase_##n = {					\
	.sec = DT_INST_REG_ADDR(n) + _FMC_SECCFGR,					\
	.priv = DT_INST_REG_ADDR(n) + _FMC_PRIVCFGR,					\
	.cid = DT_INST_REG_ADDR(n) + _FMC_PERX_CIDCFGR,					\
	.sem = DT_INST_REG_ADDR(n) + _FMC_PERX_SEMCR,					\
};											\
											\
DT_INST_RIFPROT_CTRL_DEFINE(n, &rbase_##n, NULL, FMC_RIF_RES);				\
PINCTRL_DT_INST_DEFINE(n);								\
											\
static const struct stm32_fmc_config fmc_cfg_##n = {					\
	.base = DT_INST_REG_ADDR(n),							\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),				\
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(n, bits),			\
	.rif_ctl = DT_INST_RIFPROT_CTRL_GET(n),						\
	.pctrl_cfg = PINCTRL_DT_INST_DEV_CONFIG_GET(n),					\
	.cclken = DT_INST_PROP_OR(n, st_fmc2_ebi_cs_cclk_enable, false),		\
	.clk_period_ns = DT_INST_PROP_OR(n, st_fmc2_ebi_cs_clk_period_ns, 0),		\
};											\
											\
static struct stm32_fmc_data fmc_data_##n = {};						\
											\
PM_DEVICE_DT_INST_DEFINE(n, stm32_fmc_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n, &stm32_fmc_init,						\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &fmc_data_##n, &fmc_cfg_##n,					\
		      CORE, 10, NULL);

DT_INST_FOREACH_STATUS_OKAY(STM32_FMC_INIT)
