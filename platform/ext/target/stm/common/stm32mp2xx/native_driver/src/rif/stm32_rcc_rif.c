/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_rcc_rif

#include <stdint.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <errno.h>

#include <device.h>
#include <pm/pm.h>
#include <pm/device.h>
#include <pm/pm.h>

#include <stm32mp2_clk.h>
#include <stm32_rif.h>
#include <firewall.h>

/* RCC offset register */
#define _RCC_SECCFGR0				U(0x0)
#define _RCC_PRIVCFGR0				U(0x10)
#define _RCC_R0CIDCFGR				U(0x30)
#define _RCC_R0SEMCR				U(0x34)
#define _RCC_RCFGLOCKR0				U(0x20)

/* rif miscellaneous */
#define RCC_NB_RIF_RES			U(114)

struct stm32_rcc_rif_config {
	const struct rifprot_controller *rif_ctl;
};

static int stm32_rcc_rif_firewall_set_conf(const struct firewall_spec *spec)
{
	const struct stm32_rcc_rif_config *dev_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_set_conf(dev_cfg->rif_ctl, &rifprot_cfg);
}

static int stm32_rcc_rif_firewall_release_conf(const struct firewall_spec *spec)
{
	const struct stm32_rcc_rif_config *dev_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_release_conf(dev_cfg->rif_ctl, rifprot_cfg.id);
}

static int stm32_rcc_rif_firewall_acquire_access(const struct firewall_spec *spec)
{
	const struct stm32_rcc_rif_config *dev_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_acquire_sem(dev_cfg->rif_ctl, rifprot_cfg.id);
}

static int stm32_rcc_rif_firewall_release_access(const struct firewall_spec *spec)
{
	const struct stm32_rcc_rif_config *dev_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_release_sem(dev_cfg->rif_ctl, rifprot_cfg.id);
}

static int stm32_rcc_rif_firewall_check_access(const struct firewall_spec *spec)
{
	const struct stm32_rcc_rif_config *dev_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_check_access(dev_cfg->rif_ctl, rifprot_cfg.id);
}

static const struct firewall_controller_api stm32_rcc_rif_firewall_api = {
	.set_conf = stm32_rcc_rif_firewall_set_conf,
	.release_conf = stm32_rcc_rif_firewall_release_conf,
	.acquire_access = stm32_rcc_rif_firewall_acquire_access,
	.release_access = stm32_rcc_rif_firewall_release_access,
	.check_access = stm32_rcc_rif_firewall_check_access,
};

static int stm32_rcc_rif_init(const struct device *dev)
{
	const struct stm32_rcc_rif_config *dev_cfg = dev_get_config(dev);

	return stm32_rifprot_init(dev_cfg->rif_ctl);
}

#ifdef CONFIG_PM_DEVICE
static int stm32_rcc_rif_pm_action(const struct device *dev,
				  enum pm_device_action action, uint32_t pm_hint)
{
	if (!PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return 0;

	if (action == PM_DEVICE_ACTION_RESUME)
		return stm32_rcc_rif_init(dev);

	return 0;
}
#endif

#define _STM32_RCC_RIF_INIT(n, level, priority)					\
										\
BUILD_ASSERT(DT_INST_PROP_LEN_OR(n, st_protreg, 1) <= RCC_NB_RIF_RES,		\
	     "number of rif ressource not supported");				\
										\
static __unused const struct rif_base rbase_##n = {				\
	.sec = DT_REG_ADDR(DT_INST_PARENT(n)) + _RCC_SECCFGR0,			\
	.priv = DT_REG_ADDR(DT_INST_PARENT(n)) + _RCC_PRIVCFGR0,		\
	.cid = DT_REG_ADDR(DT_INST_PARENT(n)) + _RCC_R0CIDCFGR,			\
	.sem = DT_REG_ADDR(DT_INST_PARENT(n)) + _RCC_R0SEMCR,			\
	.lock = DT_REG_ADDR(DT_INST_PARENT(n)) + _RCC_RCFGLOCKR0,		\
};										\
										\
DT_INST_RIFPROT_CTRL_DEFINE(n, &rbase_##n, NULL, RCC_NB_RIF_RES);		\
										\
static const struct stm32_rcc_rif_config rcc_rif_cfg_##n = {			\
	.rif_ctl = DT_INST_RIFPROT_CTRL_GET(n),					\
};										\
										\
PM_DEVICE_DT_INST_DEFINE(n, stm32_rcc_rif_pm_action, PM_DEVICE_F_NONE);		\
										\
DEVICE_DT_INST_DEFINE(n, &stm32_rcc_rif_init,					\
		      PM_DEVICE_DT_INST_GET(n),					\
		      NULL, &rcc_rif_cfg_##n,					\
		      level, priority,						\
		      &stm32_rcc_rif_firewall_api);

/*
 * In M33tdcid the rif access are set in last step for ns.
 * This allows rif aware IP to be initialized before.
 * In A35tdcid the delegate and semaphore could be take just after clock init.
 */
#if (IS_ENABLED(STM32_M33TDCID))
#define STM32_RCC_RIF_INIT(n) _STM32_RCC_RIF_INIT(n, REST, 0)
#else
#define STM32_RCC_RIF_INIT(n) _STM32_RCC_RIF_INIT(n, INITLEVEL_RCC, PRIORITY_RCC + 1)
#endif

DT_INST_FOREACH_STATUS_OKAY(STM32_RCC_RIF_INIT)

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) <= 1,
	     "only one rcc rif compatible node is supported");
