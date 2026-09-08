/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <cmsis.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#include <device.h>
#include <lib/mmio.h>
#include <lib/utils_def.h>
#include <platform_region.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <sau_armv8m_drv.h>

#define DT_DRV_COMPAT arm_armv8m_sau

#ifndef SAU_PLAT_BUILTIN
#define SAU_PLAT_BUILTIN()
#endif

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) <= 1,
	     "only one sau compatible node is supported");

#define _SAU_CTRL		U(0x00)
#define _SAU_TYPE		U(0x04)
#define _SAU_RNR		U(0x08)
#define _SAU_RBAR		U(0x0C)
#define _SAU_RLAR		U(0x10)
#define _SAU_SFSR		U(0x14)
#define _SAU_SFAR		U(0x18)

/* CTRL bitfield */
#define _CTRL_ENABLE_SHIFT	0
#define _CTRL_ENABLE_MASK	BIT(0)
#define _CTRL_ALLNS_SHIFT	1
#define _CTRL_ALLNS_MASK	BIT(1)

/* TYPE bitfield */
#define _TYPE_SREGION_SHIFT	0
#define _TYPE_SREGION_MASK	GENMASK_32(7,0)

/* RNR bitfield */
#define _RNR_SREGION_SHIFT	0
#define _RNR_SREGION_MASK	GENMASK_32(7,0)

/* RBAR bitfield */
#define _RBAR_BADDR_SHIFT	5
#define _RBAR_BADDR_MASK	GENMASK_32(31,5)

/* RLAR bitfield */
#define _RLAR_ENABLE_SHIFT	0
#define _RLAR_ENABLE_MASK	BIT(0)
#define _RLAR_NSC_SHIFT		1
#define _RLAR_NSC_MASK		BIT(1)
#define _RLAR_LADDR_SHIFT	5
#define _RLAR_LADDR_MASK	GENMASK_32(31,5)
#define _RLAR_ATTRS_MASK	(_RLAR_NSC_MASK | _RLAR_ENABLE_MASK)

/* if needed Peripheral region must be defined in soc header file */
#ifndef PERIPH_BASE_NS
#warning "Peripheral NS base region not defined"
#define PERIPH_BASE_NS
#endif
#ifndef PERIPH_SIZE
#warning "Peripheral NS size region not defined"
#define PERIPH_SIZE
#endif

#define for_each_sau_region(rgt, rg, nr, idx)	\
	for (rg = ((struct sau_region *)rgt);	\
	     idx >= 0 && idx < (nr);		\
	     idx++, rg = rg + 1)

struct arm_sau_config {
	uintptr_t base;
	const struct sau_region *regions;
	const int n_regions;
};

struct arm_sau_data {
	uint32_t hw_n_regions;
};

static void arm_sau_set_region(const struct device *dev)
{
	const struct arm_sau_config *drv_cfg = dev_get_config(dev);
	struct sau_region *rg;
	int32_t idx = 0;

	/* Disable SAU */
	TZ_SAU_Disable();

	for_each_sau_region(drv_cfg->regions, rg, drv_cfg->n_regions, idx) {
		uint32_t limit_cfg = rg->limit & _RLAR_LADDR_MASK;

		limit_cfg |= _FLD_PREP(_RLAR_NSC, _FLD_GET(DT_MEM_ARM_SAU_NSC, rg->mem_attr));
		limit_cfg |= _RLAR_ENABLE_MASK;

		io_write32(drv_cfg->base + _SAU_RNR, idx);
		io_write32(drv_cfg->base + _SAU_RBAR, rg->base & _RBAR_BADDR_MASK);
		io_write32(drv_cfg->base + _SAU_RLAR, limit_cfg);
	}

	/* Force memory writes before continuing */
	__DSB();
	/* Flush and refill pipeline with updated permissions */
	__ISB();

	/* Enable SAU */
	TZ_SAU_Enable();
}

static void arm_sau_get_hwconfig(const struct device *dev)
{
	const struct arm_sau_config *drv_cfg = dev_get_config(dev);
	struct arm_sau_data *drv_data = dev_get_data(dev);

	drv_data->hw_n_regions = _FLD_GET(_TYPE_SREGION, io_read32(drv_cfg->base + _SAU_TYPE));
}

static int __maybe_unused arm_sau_init(const struct device *dev)
{
	const struct arm_sau_config *drv_cfg = dev_get_config(dev);
	struct arm_sau_data *drv_data = dev_get_data(dev);

	arm_sau_get_hwconfig(dev);

	if (drv_cfg->n_regions > drv_data->hw_n_regions)
		return -ENOTSUP;

	arm_sau_set_region(dev);

	return 0;
}

#ifdef CONFIG_PM_DEVICE
static int arm_sau_pm_action(const struct device *dev,
			     enum pm_device_action action, uint32_t pm_hint)
{
	if (PM_HINT_IS_STATE(pm_hint, CONTEXT) && (action == PM_DEVICE_ACTION_RESUME))
		arm_sau_set_region(dev);

	return 0;
}
#endif

#define SAU_MR_MEM_ATTR(_mr_node_id)								\
	DT_MEM_ARCH_ATTR_GET(DT_PROP_OR(_mr_node_id, tfm_memory_attr, 0))

#define DT_SAU_REGION(_node_id, _prop, _idx)							\
	SAU_REGION(DT_MEMORY_REGION_ADDR_BY_IDX(_node_id, _idx),				\
		   DT_MEMORY_REGION_ADDR_BY_IDX(_node_id, _idx) +				\
		   DT_MEMORY_REGION_SIZE_BY_IDX(_node_id, _idx) - 1,				\
		   SAU_MR_MEM_ATTR(DT_MEMORY_REGION_BY_IDX(_node_id, _idx)))

#define DT_INST_SAU_MEMORY_REGION(inst)								\
	COND_CODE_1(DT_INST_MEMORY_REGION_HAS(inst),						\
		    (DT_INST_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP(inst, DT_SAU_REGION, (,))),	\
		    ())

#define ARM_SAU_INIT(n)										\
												\
static const struct sau_region sau_dt_regions_##n[] = {						\
	SAU_PLAT_BUILTIN()									\
	DT_INST_SAU_MEMORY_REGION(n)								\
};												\
												\
static const struct arm_sau_config cfg_##n = {							\
	.base = DT_INST_REG_ADDR(n),								\
	.regions = sau_dt_regions_##n,								\
	.n_regions = ARRAY_SIZE(sau_dt_regions_##n),						\
};												\
												\
static struct arm_sau_data data_##n = {};							\
												\
PM_DEVICE_DT_INST_DEFINE(n, arm_sau_pm_action, PM_DEVICE_F_NONE);				\
												\
DEVICE_DT_INST_DEFINE(n, &arm_sau_init,								\
		      PM_DEVICE_DT_INST_GET(n),							\
		      &data_##n,								\
		      &cfg_##n,									\
		      ARCH, 1,									\
		      NULL);

DT_INST_FOREACH_STATUS_OKAY(ARM_SAU_INIT)
