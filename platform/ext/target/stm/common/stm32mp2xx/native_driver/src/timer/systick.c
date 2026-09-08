/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#define DT_DRV_COMPAT arm_armv8m_systick

#include <errno.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <device.h>
#include <clk.h>
#include <systick.h>
#include <pm/device.h>

#define SYST_CTRL	0x0
#define SYST_LOAD	0x4
#define SYST_VAL	0x8
#define SYST_CALIB	0xc

#define SYST_CTRL_EN		BIT(0)
#define SYST_CTRL_CLKSOURCE	BIT(2)

#define COUNTER_MAX SysTick_LOAD_RELOAD_Msk
#define CYC_PER_TICK (SystemCoreClock / cfg->tick_hz)

#define _SYST_DEVICE DEVICE_GET(DEVICE_DT_DEV_ID(DT_DRV_INST(0)))

static uint64_t ticks = 0U;

uint64_t _systick_get_tick(void);

struct systick_config {
	uintptr_t base;
	const struct device *clk_dev;
	clk_subsys_t clk_subsys;
	uintptr_t tick_hz;
};

struct systick_data {
	uint32_t systick_val;
};

/*
 * calcul the next ticks value (current ticks + us timeout)
 */
uint64_t timeout_init_us(uint64_t us)
{
	const struct device *dev = _SYST_DEVICE;
	const struct systick_config *cfg = dev_get_config(dev);

	if (!cfg || !device_is_ready(dev))
		return 0;

	ticks = _systick_get_tick();
	return ticks + div_round_up(us * cfg->tick_hz, 1000000);
}

bool timeout_elapsed(uint64_t timeout)
{
	const struct device *dev = _SYST_DEVICE;
	const struct systick_config *cfg = dev_get_config(dev);

	if (!cfg || !device_is_ready(dev))
		return false;

	return _systick_get_tick() > timeout;
}

void udelay(unsigned long us)
{
	const struct device *dev = _SYST_DEVICE;
	const struct systick_config *cfg = dev_get_config(dev);
	uint64_t delayticks;

	if (!cfg || !device_is_ready(dev))
		return;

	delayticks = timeout_init_us(us);
	while (_systick_get_tick() < delayticks);
}

/*
 * With 64bits, the ticks can't be roll while product lifecycle,
 * even if tick resolution is 1us
 */
uint64_t _systick_get_tick(void)
{
	const struct systick_config *cfg = dev_get_config(_SYST_DEVICE);
	static uint32_t t1 = 0U, tdelta = 0U;
	uint32_t t2;

	if (!CYC_PER_TICK)
		goto out;

	t2 = mmio_read_32(cfg->base + SYST_VAL);

	if (t2 <= t1)
		tdelta += t1 - t2;
	else
		tdelta += t1 + mmio_read_32(cfg->base + SYST_LOAD) - t2;

	if (tdelta > CYC_PER_TICK){
		ticks += tdelta / CYC_PER_TICK;
		tdelta = tdelta % CYC_PER_TICK;
	}

	t1 = t2;
out:
	return ticks;
}

void _systick_enable(const struct systick_config *cfg)
{
	mmio_setbits_32(cfg->base + SYST_CTRL, SYST_CTRL_EN);
}

void _systick_disable(const struct systick_config *cfg)
{
	mmio_clrbits_32(cfg->base + SYST_CTRL, SYST_CTRL_EN);
}

static int systick_init_with_val(const struct device *dev, uint32_t val)
{
	const struct systick_config *cfg = dev_get_config(dev);
	struct clk *clk;

	if (!cfg)
		return -ENODEV;

	clk = clk_get(cfg->clk_dev, cfg->clk_subsys);
	if (!cfg->tick_hz || !clk)
		return -EINVAL;

	SystemCoreClock = clk_get_rate(clk);
	if (SystemCoreClock == 0UL)
		return -EINVAL;

	mmio_write_32(cfg->base + SYST_LOAD, COUNTER_MAX);
	/* Load the SysTick Counter Value */
	mmio_write_32(cfg->base + SYST_VAL, val);
	mmio_write_32(cfg->base + SYST_CTRL, SYST_CTRL_CLKSOURCE);

	_systick_enable(cfg);

	return 0;
}

static int systick_init(const struct device *dev)
{
	return systick_init_with_val(dev, 0);
}

#ifdef CONFIG_PM_DEVICE
static int systick_pm_suspend(const struct device *dev)
{
	const struct systick_config *cfg = dev_get_config(dev);
	struct systick_data *drv_data = dev_get_data(dev);

	_systick_disable(cfg);
	drv_data->systick_val = mmio_read_32(cfg->base + SYST_VAL);

	return 0;
}

static int systick_pm_resume(const struct device *dev)
{
	const struct systick_data *drv_data = dev_get_data(dev);

	return systick_init_with_val(dev, drv_data->systick_val);
}

static int systick_pm_action(const struct device *dev,
			       enum pm_device_action action, uint32_t pm_hint)
{
	if (action == PM_DEVICE_ACTION_SUSPEND) {
		return systick_pm_suspend(dev);
	} else {
		return systick_pm_resume(dev);
	}
}
#endif

struct systick_data data = { .systick_val = 0 };

const struct systick_config systick_cfg = {
	.base = DT_REG_ADDR(DT_DRV_INST(0)),
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(0)),
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(0, bits),
	.tick_hz = DT_INST_PROP(0, clock_frequency),
};

PM_DEVICE_DT_INST_DEFINE(0, systick_pm_action, PM_DEVICE_F_NONE);

DEVICE_DT_INST_DEFINE(0,
		      &systick_init, PM_DEVICE_DT_INST_GET(0),
		      &data,
		      &systick_cfg,
		      PRE_CORE, 10,
		      NULL);
