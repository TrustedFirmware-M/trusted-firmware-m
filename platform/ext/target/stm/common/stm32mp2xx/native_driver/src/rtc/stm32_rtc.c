/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_rtc

#include <stdint.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <inttypes.h>
#include <debug.h>
#include <errno.h>

#include <device.h>
#include <stm32_rif.h>
#include <clk.h>

/* RTC offset register */
#define _RTC_ICSR		U(0x0C)
#define _RTC_PRER		U(0x10)
#define _RTC_CR			U(0x18)
#define _RTC_PRIVCFGR		U(0x1C)
#define _RTC_SECCFGR		U(0x20)
#define _RTC_WPR		U(0x24)
#define _RTC_CIDCFGR		U(0x80)

/* _RTC_ICSR register fields */
#define _ICSR_INITS_MASK	BIT(4)
#define _ICSR_INITS_SHIFT	4
#define _ICSR_RSF_MASK		BIT(5)
#define _ICSR_RSF_SHIFT		5
#define _ICSR_INITF_MASK	BIT(6)
#define _ICSR_INITF_SHIFT	6
#define _ICSR_INIT_MASK		BIT(7)
#define _ICSR_INIT_SHIFT	7

/* _RTC_PRER register fields */
#define _PRER_PREDIV_S_MASK	GENMASK_32(14, 0)
#define _PRER_PREDIV_S_SHIFT	0
#define _PRER_PREDIV_A_MASK	GENMASK_32(22, 16)
#define _PRER_PREDIV_A_SHIFT	16

/* _RTC_CR register fields */
#define _CR_FMT_MASK		BIT(6)
#define _CR_FMT_SHIFT		6

#define _CID_X_OFFSET(_id)	(U(0x4) * (_id))
// CIDCFGR register bitfields
#define _CIDCFGR_CFEN_MASK	BIT(0)
#define _CIDCFGR_CFEN_SHIFT	0
#define _CIDCFGR_SCID_MASK	GENMASK_32(6, 4)
#define _CIDCFGR_SCID_SHIFT	4

/* RIF miscellaneous */
#define RTC_PRIV_SEC_ID_SHIFT	GENMASK_32(5, 4)
#define RTC_SECCFGR_SHIFT	U(9)

#define RTC_RIF_RES		U(6)

/* _RTC_WPR register value */
#define WPR_KEY1		U(0xCA)
#define WPR_KEY2		U(0x53)
#define WPR_KEY_LOCK		U(0xFF)

#define RTC_TIMEOUT_US		U(100000)

struct stm32_rtc_config {
	uintptr_t base;
	const struct rifprot_controller *rif_ctl;
	const struct device *pclk_dev;
	const clk_subsys_t pclk_subsys;
	const struct device *rtc_clk_dev;
	const clk_subsys_t rtc_clk_subsys;
};

struct stm32_rtc_data {
	struct clk *rtc_clk;
	struct clk *pclk;
};

/*
 * the devicetree provide a configuration per resource (no general
 * configuration), so each resource protection is managed individually
 * and the global SEC & PRIV configuration are not take account.
 */
static int stm32_rtc_rif_set_conf(const struct rifprot_controller *ctl,
				  struct rifprot_config *cfg)
{
	uint32_t shift = cfg->id;

	if (!IS_ENABLED(STM32_M33TDCID))
		return 0;

	if (BIT(cfg->id) & RTC_PRIV_SEC_ID_SHIFT)
		shift += RTC_SECCFGR_SHIFT;

	/* disable filtering befor write sec and priv cfgr */
	io_clrbits32(ctl->rbase->cid + _CID_X_OFFSET(cfg->id), _CIDCFGR_CFEN_MASK);

	io_clrsetbits32(ctl->rbase->sec, BIT(shift), cfg->sec << shift);
	io_clrsetbits32(ctl->rbase->priv, BIT(shift), cfg->priv << shift);

	io_write32(ctl->rbase->cid + _CID_X_OFFSET(cfg->id), cfg->cid_attr);

	return 0;
}

static int _stm32_rtc_rif_deinit(const struct rifprot_controller *ctl)
{
	struct rifprot_config *rcfg_elem, rcfg_deinit = {
		.sec = false, .priv = false,
		.lock = false, .cid_attr = 0x0
	};
	int err, i = 0;

	for_each_rifprot_cfg(ctl->rifprot_cfg, rcfg_elem, ctl->nrifprot, i) {
		rcfg_deinit.id = i;
		err = stm32_rifprot_set_conf(ctl, &rcfg_deinit);
		if (err)
			return err;
	}

	return 0;
}

static int _stm32_rtc_compute_pres_field(const struct device *dev,
					 uint32_t *presc_a, uint32_t *presc_s)
{
	uint32_t pred_a_max = _FLD_GET(_PRER_PREDIV_A, _PRER_PREDIV_A_MASK);
	uint32_t pred_s_max = _FLD_GET(_PRER_PREDIV_S, _PRER_PREDIV_S_MASK);
	struct stm32_rtc_data *drv_data = dev_get_data(dev);
	unsigned long rate = clk_get_rate(drv_data->rtc_clk);
	uint32_t pred_a, pred_s;

	if (rate > (pred_a_max + 1) * (pred_s_max + 1))
		return -EINVAL;

	/*
	 * Compute the prescaler values whom divides the clock in order to get a
	 * 1 Hz output
	 */
	for (pred_a = 0, pred_s = 0; pred_a <= pred_a_max; pred_a++) {
		pred_s = (rate / (pred_a + 1)) - 1;
		if (pred_s <= pred_s_max &&
		    ((pred_s + 1) * (pred_a + 1)) == rate)
			break;
	}

	/*
	 * Can't find a 1Hz, so give priority to RTC power consumption
	 * by choosing the higher possible value for prediv_a
	 */
	if (pred_s > pred_s_max || pred_a > pred_a_max) {
		pred_a = pred_a_max;
		pred_s = (rate / (pred_a + 1)) - 1;
		DMSG("rtc_ck is %s\n", (rate < ((pred_a + 1) * (pred_s + 1))) ? "fast" : "slow");
	}

	*presc_a = _FLD_PREP(_PRER_PREDIV_A, pred_a);
	*presc_s = _FLD_PREP(_PRER_PREDIV_S, pred_s);

	return 0;
}

static void _stm32_rtc_write_unprotect(const struct device *dev)
{
	const struct stm32_rtc_config *cfg = dev_get_config(dev);

	io_write32(cfg->base + _RTC_WPR, WPR_KEY1);
	io_write32(cfg->base + _RTC_WPR, WPR_KEY2);
}

static void _stm32_rtc_write_protect(const struct device *dev)
{
	const struct stm32_rtc_config *cfg = dev_get_config(dev);

	io_write32(cfg->base + _RTC_WPR, WPR_KEY_LOCK);
}

static int _stm32_rtc_enter_init_mode(const struct device *dev)
{
	const struct stm32_rtc_config *cfg = dev_get_config(dev);
	uint32_t icsr = io_read32(cfg->base + _RTC_ICSR);

	/* Calendar registers update is allowed */
	if (_FLD_GET(_ICSR_INITF, icsr))
		return 0;

	io_setbits32(cfg->base + _RTC_ICSR, _ICSR_INIT_MASK);

	return mmio_read32_poll_timeout(cfg->base + _RTC_ICSR, icsr,
					(icsr & _ICSR_INITF_MASK),
					RTC_TIMEOUT_US);
}

static int _stm32_rtc_exit_init_mode(const struct device *dev)
{
	const struct stm32_rtc_config *cfg = dev_get_config(dev);
	uint32_t icsr;

	io_clrbits32(cfg->base + _RTC_ICSR, _ICSR_INIT_MASK);
	io_clrbits32(cfg->base + _RTC_ICSR, _ICSR_RSF_MASK);

	return mmio_read32_poll_timeout(cfg->base + _RTC_ICSR, icsr,
					(icsr & _ICSR_RSF_MASK),
					RTC_TIMEOUT_US);
}

/*
 * _stm32_rtc_is_initialized
 *
 * Return true if calendar has been initialized or false
 */
static bool _stm32_rtc_is_initialized(const struct device *dev)
{
	const struct stm32_rtc_config *cfg = dev_get_config(dev);
	uint32_t icsr = io_read32(cfg->base + _RTC_ICSR);

	return !!_FLD_GET(_ICSR_INITS, icsr);
}

/*
 * All rtc services are delegated to non secure word.
 * So this function initialize calendar if not yet done.
 */
static int _stm32_rtc_init(const struct device *dev)
{
	const struct stm32_rtc_config *cfg = dev_get_config(dev);
	uint32_t prediv_a, prediv_s;
	int err;

	/*
	 * RTC_WPR register may be protected by rif configuration.
	 * deinit rif before unprotect.
	 */
	err = _stm32_rtc_rif_deinit(cfg->rif_ctl);
	if (err) {
		EMSG("[%s] rif deinit err: %d\n", dev->name, err);
		return err;
	}

	_stm32_rtc_write_unprotect(dev);

	if (_stm32_rtc_is_initialized(dev)) {
		err = 0;
		goto out;
	}

	err = _stm32_rtc_compute_pres_field(dev, &prediv_a, &prediv_s);
	if (err) {
		EMSG("[%s] prescaler err: %d\n", dev->name, err);
		goto out;
	}

	err = _stm32_rtc_enter_init_mode(dev);
	if (err) {
		EMSG("[%s] enter init err: %d\n", dev->name, err);
		goto out;
	}

	io_write32(cfg->base + _RTC_PRER, prediv_s);
	io_write32(cfg->base + _RTC_PRER, prediv_a | prediv_s);

	/* Force 24h time format */
	io_clrbits32(cfg->base + _RTC_CR, _CR_FMT_MASK);

	err = _stm32_rtc_exit_init_mode(dev);
	if (err)
		EMSG("[%s] exit init err: %d\n", dev->name, err);

out:
	_stm32_rtc_write_protect(dev);
	err = stm32_rifprot_init(cfg->rif_ctl);

	return err;
}

static int stm32_rtc_init(const struct device *dev)
{
	const struct stm32_rtc_config *cfg = dev_get_config(dev);
	struct stm32_rtc_data *drv_data = dev_get_data(dev);
	int err;

	if (!cfg)
		return -ENODEV;

	drv_data->rtc_clk = clk_get(cfg->rtc_clk_dev, cfg->rtc_clk_subsys);
	drv_data->pclk = clk_get(cfg->pclk_dev, cfg->pclk_subsys);

	if (!drv_data->rtc_clk || !drv_data->pclk)
		return -ENODEV;

	/* Unbalanced clock enable: keep RTC running */
	err = clk_enable(drv_data->rtc_clk);
	if (err)
		return err;

	err = clk_enable(drv_data->pclk);
	if (err)
		return err;

	err = _stm32_rtc_init(dev);

	clk_disable(drv_data->pclk);

	return err;
}

#define STM32_RTC_INIT(n)								\
											\
static const struct rif_base rbase_##n = {						\
	.sec = DT_INST_REG_ADDR(n) + _RTC_SECCFGR,					\
	.priv = DT_INST_REG_ADDR(n) + _RTC_PRIVCFGR,					\
	.cid = DT_INST_REG_ADDR(n) + _RTC_CIDCFGR,					\
	.sem = 0,									\
};											\
											\
struct rif_ops rops_##n = {								\
	.set_conf = stm32_rtc_rif_set_conf,						\
};											\
											\
DT_INST_RIFPROT_CTRL_DEFINE(n, &rbase_##n, &rops_##n, RTC_RIF_RES);			\
											\
static const struct stm32_rtc_config rtc_cfg_##n = {					\
	.base = DT_INST_REG_ADDR(n),							\
	.rif_ctl = DT_INST_RIFPROT_CTRL_GET(n),						\
	.pclk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR_BY_NAME(n, pclk)),		\
	.pclk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL_BY_NAME(n, pclk, bits),	\
	.rtc_clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR_BY_NAME(n, rtc_ck)),		\
	.rtc_clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL_BY_NAME(n, rtc_ck, bits),	\
};											\
											\
static struct stm32_rtc_data rtc_data_##n = {};						\
											\
DEVICE_DT_INST_DEFINE(n, &stm32_rtc_init, NULL,						\
		      &rtc_data_##n,							\
		      &rtc_cfg_##n,							\
		      CORE, 10, NULL);

DT_INST_FOREACH_STATUS_OKAY(STM32_RTC_INIT)
