/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#include <errno.h>
#include <stdint.h>
#include <lib/mmio.h>
#include <lib/utils_def.h>
#include <device.h>
#include <pm/device.h>
#include <pm/pm.h>

#include <syscon.h>

#define _DT_INIT_REGS_ELEM_SZ		2

struct stm32_syscfg_config {
	uintptr_t reg_base;
	const uint32_t *reg_init;
	const int reg_init_sz;
};

struct stm32_syscfg_variant {
	uint32_t max_offset;
};

struct stm32_syscfg_data {
	const struct stm32_syscfg_variant *variant;
};

static bool _reg_is_available(const struct device *dev, uint32_t offset)
{
	struct stm32_syscfg_data *drv_data = dev_get_data(dev);

	if (offset > drv_data->variant->max_offset)
		return false;

	return true;
}

static int stm32_syscfg_read(const struct device *dev, uint16_t off,
			     uint32_t *val)
{
	const struct stm32_syscfg_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->reg_base;

	if (!_reg_is_available(dev, off))
		return -EINVAL;

	*val = mmio_read_32(base + off);

	return 0;
}

static int stm32_syscfg_write(const struct device *dev, uint16_t off,
			      uint32_t val)
{
	const struct stm32_syscfg_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->reg_base;

	if (!_reg_is_available(dev, off))
		return -EINVAL;

	mmio_write_32(base + off, val);

	return 0;
}

static int stm32_syscfg_clrsetbits(const struct device *dev, uint16_t off,
				   uint32_t clr, uint32_t set)
{
	const struct stm32_syscfg_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->reg_base;

	if (!_reg_is_available(dev, off))
		return -EINVAL;

	mmio_clrsetbits_32(base + off, clr, set);

	return 0;
}

static int stm32_syscfg_clrbits(const struct device *dev, uint16_t off,
				uint32_t clr)
{
	const struct stm32_syscfg_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->reg_base;

	if (!_reg_is_available(dev, off))
		return -EINVAL;

	mmio_clrbits_32(base + off, clr);

	return 0;
}

static int stm32_syscfg_setbits(const struct device *dev, uint16_t off,
				uint32_t set)
{
	const struct stm32_syscfg_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->reg_base;

	if (!_reg_is_available(dev, off))
		return -EINVAL;

	mmio_setbits_32(base + off, set);

	return 0;
}

static int stm32_syscfg_init_register(const struct device *dev)
{
	const struct stm32_syscfg_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->reg_base;
	uint32_t offset, value;
	int i;

	for (i = 0; i < drv_cfg->reg_init_sz; i += _DT_INIT_REGS_ELEM_SZ) {
		offset = drv_cfg->reg_init[i];
		value = drv_cfg->reg_init[i + 1];

		if (!_reg_is_available(dev, offset))
			return -EINVAL;

		mmio_write_32(base + offset, value);
	}

	return 0;
}

#ifdef CONFIG_PM_DEVICE
static int stm32_syscfg_pm_action(const struct device *dev,
				  enum pm_device_action action, uint32_t pm_hint)
{
	if (action == PM_DEVICE_ACTION_RESUME && PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return stm32_syscfg_init_register(dev);

	return 0;
}
#endif

static const struct syscon_driver_api stm32_syscfg_com_api = {
	.read = stm32_syscfg_read,
	.write = stm32_syscfg_write,
	.clrsetbits = stm32_syscfg_clrsetbits,
	.clrbits = stm32_syscfg_clrbits,
	.setbits = stm32_syscfg_setbits,
};

static int __maybe_unused stm32_syscfg_init(const struct device *dev)
{
	return stm32_syscfg_init_register(dev);
}

#define STM32_SYSCFG_INIT(n, _variant)							\
											\
BUILD_ASSERT(DT_INST_PROP_LEN_OR(n, st_reg_init, 0) % _DT_INIT_REGS_ELEM_SZ == 0,	\
	     "bad st_reg_init array size");						\
											\
static uint32_t init_regs_##n[] =							\
	DT_INST_PROP_OR(n, st_reg_init, {});						\
											\
static const struct stm32_syscfg_config stm32_syscfg_cfg_##n = {			\
	.reg_base = DT_INST_REG_ADDR(n),						\
	.reg_init = init_regs_##n,							\
	.reg_init_sz = ARRAY_SIZE(init_regs_##n),					\
};											\
											\
static struct stm32_syscfg_data stm32_syscfg_data_##n = {				\
	.variant = _variant,								\
};											\
											\
PM_DEVICE_DT_INST_DEFINE(n, stm32_syscfg_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n,								\
		      &stm32_syscfg_init,						\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &stm32_syscfg_data_##n,						\
		      &stm32_syscfg_cfg_##n,						\
		      PRE_CORE, 0,							\
		      &stm32_syscfg_com_api);

static __unused struct stm32_syscfg_variant variant_stm32mp21 = {
	.max_offset = 0x5400U,
};

static __unused struct stm32_syscfg_variant variant_stm32mp25 = {
	.max_offset = 0x6104U,
};

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp21_syscfg

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_SYSCFG_INIT, &variant_stm32mp21)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp25_syscfg

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_SYSCFG_INIT, &variant_stm32mp25)
