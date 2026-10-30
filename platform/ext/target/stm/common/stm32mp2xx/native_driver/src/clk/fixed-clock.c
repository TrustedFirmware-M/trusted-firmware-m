/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#define DT_DRV_COMPAT fixed_clock

#include <clk.h>
#include <device.h>
#include <stdint.h>

struct fixed_clock_config {
	unsigned long rate;
};

struct fixed_clock_data {
	struct clk clk;
};

static unsigned long fixed_clock_get_rate(struct clk *clk,
					  unsigned long parent_rate __unused)
{
	const struct fixed_clock_config *drv_cfg = dev_get_config(clk->dev);

	return drv_cfg->rate;
}

static const struct clk_ops fixed_clock_ops = {
	.get_rate = fixed_clock_get_rate,
};

static struct clk *fixed_clock_get(const struct device *dev,
				   clk_subsys_t sys __unused)
{
	struct fixed_clock_data *drv_data = dev_get_data(dev);

	return &drv_data->clk;
}

static const struct clk_controller_api fixed_clock_api = {
	.get = fixed_clock_get,
};

static int fixed_clock_init(const struct device *dev)
{
	struct fixed_clock_data *drv_data = dev_get_data(dev);
	struct clk *clk = &drv_data->clk;

	clk->dev = dev;
	clk->ops = &fixed_clock_ops;
#if !CLK_MINIMAL_SZ
	clk->name = dev->name;
#endif

	return clk_register(clk);
}

#define FIXED_CLOCK_INIT(n)							\
										\
static const struct fixed_clock_config fixed_clock_cfg_##n = {			\
	.rate = DT_INST_PROP(n, clock_frequency),				\
};										\
										\
static struct fixed_clock_data fixed_clock_data_##n;				\
										\
DEVICE_DT_INST_DEFINE(n,							\
		      &fixed_clock_init,					\
		      NULL,							\
		      &fixed_clock_data_##n,					\
		      &fixed_clock_cfg_##n,					\
		      PRE_CORE, 4,						\
		      &fixed_clock_api);

DT_INST_FOREACH_STATUS_OKAY(FIXED_CLOCK_INIT)
