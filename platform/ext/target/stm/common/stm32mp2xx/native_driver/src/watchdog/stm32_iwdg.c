/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <stdint.h>
#include <string.h>
#include <lib/delay.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/timeout.h>
#include <clk.h>
#include <debug.h>
#include <device.h>
#include <irq.h>
#include <reset.h>
#include <watchdog.h>

/* IWDG registers offsets */
#define _IWDG_KR		U(0x00)
#define _IWDG_PR		U(0x04)
#define _IWDG_RLR		U(0x08)
#define _IWDG_SR		U(0x0C)
#define _IWDG_WINR		U(0x10)
#define _IWDG_EWCR		U(0x14)
#define _IWDG_ICR		U(0x18)
#define _IWDG_HWCFGR		U(0x3F0)
#define _IWDG_VERR		U(0x3F4)

/* Bit definition for _IWDG_KR register */
#define _KR_KEY_MASK		GENMASK(15, 0)
#define _KR_KEY_SHIFT		0

/* Bit definition for _IWDG_PR register */
#define _PR_PR_MASK		GENMASK(3, 0)
#define _PR_PR_SHIFT		0

/* Bit definition for _IWDG_RLR register */
#define _RLR_RL_MASK		GENMASK(11, 0)
#define _RLR_RL_SHIFT		0

/* Bit definition for _IWDG_SR register */
#define _SR_PVU_MASK		BIT(0)
#define _SR_PVU_SHIFT		0
#define _SR_RVU_MASK		BIT(1)
#define _SR_RVU_SHIFT		1
#define _SR_WVU_MASK		BIT(2)
#define _SR_WVU_SHIFT		2
#define _SR_EWU_MASK		BIT(3)
#define _SR_EWU_SHIFT		3
#define _SR_ONF_MASK		BIT(8)
#define _SR_ONF_SHIFT		8
#define _SR_EWIF_MASK		BIT(15)
#define _SR_EWIF_SHIFT		15

#define _SR_UPDATE_MASK		(_SR_PVU_MASK | _SR_RVU_MASK | _SR_WVU_MASK | _SR_EWU_MASK)

/* Bit definition for _IWDG_EWCR register */
#define _EWCR_EWIT_MASK		GENMASK(11, 0)
#define _EWCR_EWIT_SHIFT	0
#define _EWCR_EWIE_MASK		BIT(15)
#define _EWCR_EWIE_SHIFT	15

/* Bit definition for _IWDG_ICR register */
#define _ICR_EWIC_MASK		BIT(15)
#define _ICR_EWIC_SHIFT		15

/* IWDG_KR register value */
#define KR_WPROT_KEY		U(0x0000)
#define KR_ACCESS_KEY		U(0x5555)
#define KR_RELOAD_KEY		U(0xAAAA)
#define KR_START_KEY		U(0xCCCC)

/* IWDG_PR register values */
#define PR_POW_MIN		2
#define PR_MIN			BIT(PR_POW_MIN)

/* IWDG_RLR register values */
#define RLR_MIN			0x2		/* min value recommended */
#define RLR_MAX			_RLR_RL_MASK	/* max value of reload register */

#define IWDG_TIMEOUT_US		100000U

/* Define default early timeout delay to 10 sec before timeout */
#define IWDG_ETIMEOUT_MSEC	(10 * MSEC_PER_SEC)

struct stm32_iwdg_config {
	uintptr_t base;
	const struct device *pclk_dev;
	const clk_subsys_t pclk_subsys;
	const struct device *kclk_dev;
	const clk_subsys_t kclk_subsys;
	const struct reset_control rst_ctl;
	const struct irq_spec *int_early;
};


/** struct stm32_iwdg_variant - The structure that defines variants driver data
 *
 * @max_prescaler: maximum prescaler of iwdg hardware block.
 * @has_onf: true if iwdg has ONF bit to report if iwdg is activated
 */
struct stm32_iwdg_variant {
	uint32_t max_prescaler;
	bool has_onf;
};

/** struct stm32_iwdg_data - The structure that defines a stm32 watchdog data
 *
 * @variant: constants that differ depending on the iwdg version
 * @pclk_dev: clock device input for iwdg peripheral
 * @kclk_dev: clock device input for iwdg prescaler
 * @rate: clock rate enter in iwdg hardware block
 * @min_timeout: The watchdog devices minimum timeout value (in ms).
 * @max_timeout: The watchdog devices maximum timeout value (in ms).
 * @max_hw_timeout: maximum hardware timeout value (in ms).
 * @hw_timeout: hardware timeout defined (in ms)
 * @timeout: The watchdog devices timeout value (in ms)
 * @sw_count_req: software counter request used with early interrupt to extend watchdog capability
 * @sw_count: Software counter current;
 */
struct stm32_iwdg_data {
	const struct stm32_iwdg_variant *variant;
	struct clk *pclk_dev;
	struct clk *kclk_dev;
	uint32_t rate;
	uint32_t min_timeout;
	uint32_t max_timeout;
	uint32_t max_hw_timeout;
	uint32_t hw_timeout;
	uint32_t timeout;
	uint32_t sw_count_req;
	uint32_t sw_count;
};

static bool _iwdg_is_enabled(const struct device *dev)
{
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);
	uint32_t rlr, sr;
	int err;

	if (drv_data->variant->has_onf) {
		return !!(io_read32(drv_cfg->base + _IWDG_SR) & _SR_ONF_MASK);
	} else {
		/*
		 * Workaround for old versions without IWDG_SR_ONF bit:
		 * - write in IWDG_RLR_OFFSET
		 * - wait for sync
		 * - if sync succeeds, then iwdg is running
		 */
		io_write32(drv_cfg->base + _IWDG_KR, KR_ACCESS_KEY);
		rlr = io_read32(drv_cfg->base + _IWDG_RLR);
		io_write32(drv_cfg->base + _IWDG_RLR, rlr);

		err = mmio_read32_poll_timeout(drv_cfg->base + _IWDG_SR,
					       sr, !(sr & _SR_RVU_MASK),
					       IWDG_TIMEOUT_US);

		io_write32(drv_cfg->base + _IWDG_KR, KR_WPROT_KEY);

		if (!err)
			return true;
	}

	return false;
}

static bool _iwdg_timeout_available(const struct device *dev, uint32_t timeout)
{
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);

	if (timeout > drv_data->max_timeout ||
	    timeout < drv_data->min_timeout ||
	    (timeout > drv_data->max_hw_timeout && !drv_cfg->int_early)) {
		WMSG("[%s] init timeout not available\n", dev->name);
		return false;
	}

	return true;
}

static int _iwdg_configure_timeout(const struct device *dev, uint32_t timeout)
{
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);
	uint32_t interval;

	if (!_iwdg_timeout_available(dev, timeout))
		return -EINVAL;

	drv_data->timeout = timeout;

	if (timeout < drv_data->max_hw_timeout - IWDG_ETIMEOUT_MSEC) {
		drv_data->hw_timeout = timeout;
		drv_data->sw_count_req = 0;
	} else {
		/* use early interrupt with sw counter */
		interval = drv_data->max_hw_timeout - IWDG_ETIMEOUT_MSEC;
		drv_data->sw_count_req = (timeout - IWDG_ETIMEOUT_MSEC) / interval;

		drv_data->hw_timeout = (timeout - IWDG_ETIMEOUT_MSEC);
		drv_data->hw_timeout /= (drv_data->sw_count_req + 1);
		drv_data->hw_timeout += IWDG_ETIMEOUT_MSEC;
	}

	drv_data->sw_count = drv_data->sw_count_req;

	return 0;
}

static int _iwdg_clk_enable(const struct device *dev)
{
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);
	int err;

	err = clk_enable(drv_data->pclk_dev);
	if (err)
		return err;

	err = clk_enable(drv_data->kclk_dev);
	if (err)
		clk_disable(drv_data->pclk_dev);

	return err;
}

static void _iwdg_clk_disable(const struct device *dev)
{
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);
	uint32_t ewcr;

	/* IRQ interfaces are mainly clocked by pclk */
	ewcr = io_read32(drv_cfg->base + _IWDG_EWCR);
	if (!(ewcr & _EWCR_EWIE_MASK))
		clk_disable(drv_data->pclk_dev);

	clk_disable(drv_data->kclk_dev);
}

static int _iwdg_start(const struct device *dev)
{
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);
	uint32_t ticks, presc, pr, rlr, sr, ewcr = 0;
	int err;

	if (!_iwdg_timeout_available(dev, drv_data->timeout))
		return -EINVAL;

	io_write32(drv_cfg->base + _IWDG_KR, KR_START_KEY);

	if (drv_cfg->int_early)
		interrupt_disable(drv_cfg->int_early);

	ticks = div_round_closest(drv_data->hw_timeout * drv_data->rate, MSEC_PER_SEC);
	presc = div_round_up(ticks, RLR_MAX + 1);

	/* The prescaler is align on power of 2 and start at 2 ^ PR_SHIFT. */
	presc = roundup_pow_of_two(presc);
	pr = presc <= (1 << PR_POW_MIN) ? 0 : ilog2(presc) - PR_POW_MIN;
	rlr = (ticks / BIT(pr + PR_POW_MIN)) - 1;

	if (drv_data->sw_count) {
		io_setbits32(drv_cfg->base + _IWDG_ICR, _ICR_EWIC_MASK);
		ticks = div_round_closest(IWDG_ETIMEOUT_MSEC * drv_data->rate, MSEC_PER_SEC);
		ewcr = (ticks / BIT(pr + PR_POW_MIN)) - 1;
		ewcr |= _EWCR_EWIE_MASK;
	}

	/* enable write access */
	io_write32(drv_cfg->base + _IWDG_KR, KR_ACCESS_KEY);

	/* set prescaler & reload registers & early watchdog if needed */
	io_write32(drv_cfg->base + _IWDG_PR, pr);
	io_write32(drv_cfg->base + _IWDG_RLR, rlr);
	io_write32(drv_cfg->base + _IWDG_EWCR, ewcr);

	if (drv_data->sw_count)
		interrupt_enable(drv_cfg->int_early);

	/* reload watchdog */
	io_write32(drv_cfg->base + _IWDG_KR, KR_RELOAD_KEY);

	/* wait for the registers to be updated (max 100ms) */
	err = mmio_read32_poll_timeout(drv_cfg->base + _IWDG_SR, sr,
				       !(sr & _SR_UPDATE_MASK),
				       IWDG_TIMEOUT_US);

	io_write32(drv_cfg->base + _IWDG_KR, KR_WPROT_KEY);

	return err;
}

static int stm32_iwdg_status(const struct device *dev)
{
	int ret;

	ret = _iwdg_clk_enable(dev);
	if (ret)
		return ret;

	ret = (_iwdg_is_enabled(dev) ? WATCHDOG_ENABLED : WATCHDOG_DISABLED);

	_iwdg_clk_disable(dev);

	return ret;
}

static int stm32_iwdg_start(const struct device *dev)
{
	int err;

	err = _iwdg_clk_enable(dev);
	if (err)
		return err;

	if (!_iwdg_is_enabled(dev))
		err = _iwdg_start(dev);

	_iwdg_clk_disable(dev);

	return err;
}

static int stm32_iwdg_stop(const struct device *dev)
{
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	int err;

	if (!drv_cfg->rst_ctl.dev)
		return -ENOTSUP;

	err = reset_control_reset(&drv_cfg->rst_ctl);
	if (err)
		return err;

	return 0;
}

static int stm32_iwdg_setup(const struct device *dev,
			    const struct watchdog_timeout_cfg *cfg)
{
	int err = 0;

	err = _iwdg_configure_timeout(dev, cfg->timeout);
	if (err)
		return err;

	err = _iwdg_clk_enable(dev);
	if (err)
		return err;

	if (_iwdg_is_enabled(dev))
		err = _iwdg_start(dev);

	_iwdg_clk_disable(dev);

	return err;
}

static int stm32_iwdg_ping(const struct device *dev)
{
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);
	int err;

	err = _iwdg_clk_enable(dev);
	if (err)
		return err;

	drv_data->sw_count = drv_data->sw_count_req;
	io_write32(drv_cfg->base + _IWDG_KR, KR_RELOAD_KEY);

	_iwdg_clk_disable(dev);

	return 0;
}

uint32_t stm32_iwdg_get_timeout(const struct device *dev)
{
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);

	return drv_data->timeout;
}

static const struct watchdog_driver_api __maybe_unused stm32_iwdg_api = {
	.setup = stm32_iwdg_setup,
	.status = stm32_iwdg_status,
	.get_timeout = stm32_iwdg_get_timeout,
	.start = stm32_iwdg_start,
	.stop = stm32_iwdg_stop,
	.ping = stm32_iwdg_ping,
};

static irqreturn_t stm32_iwdg_isr(void *data)
{
	const struct device *dev = data;
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);

	if (_iwdg_clk_enable(dev))
		return IRQ_NONE;

	/* Check for spurious interrupt */
	if (!_FLD_GET(_SR_EWIF, io_read32(drv_cfg->base + _IWDG_SR))) {
		_iwdg_clk_disable(dev);
		return IRQ_NONE;
	}

	/* Acknowledge the early watchdog interrupt */
	io_write32(drv_cfg->base + _IWDG_ICR, _ICR_EWIC_MASK);

	if (drv_data->sw_count > 0) {
		drv_data->sw_count--;
		io_write32(drv_cfg->base + _IWDG_KR, KR_RELOAD_KEY);
	} else {
		WMSG("[%s] software timeout elapsed, letting watchdog expire\n", dev->name);
	}

	_iwdg_clk_disable(dev);

	return IRQ_HANDLED;
}

static int __maybe_unused stm32_iwdg_init(const struct device *dev)
{
	const struct stm32_iwdg_config *drv_cfg = dev_get_config(dev);
	struct stm32_iwdg_data *drv_data = dev_get_data(dev);
	int err;

	drv_data->pclk_dev = clk_get(drv_cfg->pclk_dev, drv_cfg->pclk_subsys);
	drv_data->kclk_dev = clk_get(drv_cfg->kclk_dev, drv_cfg->kclk_subsys);

	if (!drv_data->pclk_dev || !drv_data->kclk_dev)
		return -ENODEV;

	err = _iwdg_clk_enable(dev);
	if (err)
		return err;

	if (drv_cfg->rst_ctl.dev) {
		err = reset_control_reset(&drv_cfg->rst_ctl);
		if (err)
			goto out;
	}

	drv_data->rate = clk_get_rate(drv_data->kclk_dev);

	drv_data->min_timeout = div_round_up((RLR_MIN + 1) * PR_MIN * MSEC_PER_SEC, drv_data->rate);
	drv_data->max_hw_timeout = div_round_up((RLR_MAX + 1) * drv_data->variant->max_prescaler
						* MSEC_PER_SEC, drv_data->rate);
	drv_data->max_timeout = drv_data->max_hw_timeout;

	if (drv_cfg->int_early) {
		err = interrupt_request(drv_cfg->int_early, (void *)dev,
					stm32_iwdg_isr, IRQF_NO_AUTOEN);
		if (err)
			goto out;

		drv_data->max_timeout = UINT32_MAX;
	}

	if (drv_data->timeout && _iwdg_configure_timeout(dev, drv_data->timeout))
		drv_data->timeout = 0;

	/* if active, reload with new timeout defined in dt */
	if (!drv_cfg->rst_ctl.dev && _iwdg_is_enabled(dev) && drv_data->timeout)
		err = _iwdg_start(dev);

out:
	_iwdg_clk_disable(dev);
	return err;
}

#define STM32_IWDG_INIT(n, _variant)							\
											\
DT_INST_IRQS_SPEC_DEFINE(n)								\
											\
static const struct stm32_iwdg_config stm32_iwdg_cfg_##n = {				\
	.base = DT_INST_REG_ADDR(n),							\
	.pclk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR_BY_NAME(n, pclk)),	        \
	.pclk_subsys = (clk_subsys_t)DT_INST_CLOCKS_CELL_BY_NAME(n, pclk, bits),	\
	.kclk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR_BY_NAME(n, kclk)),	        \
	.kclk_subsys = (clk_subsys_t)DT_INST_CLOCKS_CELL_BY_NAME(n, kclk, bits),	\
	.rst_ctl = DT_INST_RESET_CONTROL_GET(n),					\
	.int_early = DT_INST_IRQS_SPEC_GET(n),						\
};											\
											\
static struct stm32_iwdg_data stm32_iwdg_data_##n = {					\
	.variant = _variant,								\
	.timeout = DT_INST_PROP_OR(n, timeout_sec, 0) * MSEC_PER_SEC,			\
};											\
											\
DEVICE_DT_INST_DEFINE(n,								\
		 &stm32_iwdg_init, NULL,						\
		 &stm32_iwdg_data_##n,							\
		 &stm32_iwdg_cfg_##n,							\
		 CORE, 2,								\
		 &stm32_iwdg_api);

static __unused struct stm32_iwdg_variant variant_stm32mp13 = {
	.max_prescaler = 1024,
	.has_onf = true,
};

#define DT_DRV_COMPAT st_stm32mp13_iwdg
DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_IWDG_INIT, &variant_stm32mp13)
