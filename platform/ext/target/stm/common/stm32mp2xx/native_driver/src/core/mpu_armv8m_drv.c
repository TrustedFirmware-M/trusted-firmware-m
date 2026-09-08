/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <cmsis.h>
#include <errno.h>

#include <device.h>
#include <lib/mmio.h>
#include <lib/utils_def.h>
#include <mpu_armv8m_drv.h>
#include <platform_region.h>
#include <pm/device.h>
#include <pm/pm.h>

#define DT_DRV_COMPAT arm_armv8m_mpu

#ifndef MPU_PLAT_BUILTIN
#define MPU_PLAT_BUILTIN()
#endif

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) <= 1,
	     "only one mpu compatible node is supported");

#define _MPU_TYPE		U(0x00)
#define _MPU_CTRL		U(0x04)
#define _MPU_RNR		U(0x08)
#define _MPU_RBAR		U(0x0C)
#define _MPU_RLAR		U(0x10)
#define _MPU_RBAR_A		U(0x14)
#define _MPU_RLAR_A		U(0x18)
#define _MPU_MAIR0		U(0x30)
#define _MPU_MAIR1		U(0x34)

/* the armv8-m mpu implements at most 16 regions */
#define _MPU_MAX_REGIONS	16

/* TYPE bitfield */
#define _TYPE_SEPARATE_SHIFT	0
#define _TYPE_SEPARATE_MASK	BIT(0)
#define _TYPE_DREGION_SHIFT	8
#define _TYPE_DREGION_MASK	GENMASK_32(15, 8)

/* CTRL bitfield */
#define _CTRL_ENABLE_SHIFT	0
#define _CTRL_ENABLE_MASK	BIT(0)
#define _CTRL_HFNMIENA_SHIFT	1
#define _CTRL_HFNMIENA_MASK	BIT(1)
#define _CTRL_PRIVDEFENA_SHIFT	2
#define _CTRL_PRIVDEFENA_MASK	BIT(2)

#define _PRIV_DEFAULT_DISABLE	0
#define _PRIV_DEFAULT_ENABLE	1
#define _HARDFAULT_NMI_DISABLE	0
#define _HARDFAULT_NMI_ENABLE	1

/* RNR bitfield */
#define _RNR_REGION_SHIFT	0
#define _RNR_REGION_MASK	GENMASK_32(7, 0)

/* RBAR bitfield */
#define _RBAR_XN_SHIFT		0
#define _RBAR_XN_MASK		BIT(0)
#define _RBAR_AP_SHIFT		1
#define _RBAR_AP_MASK		GENMASK_32(2, 1)
#define _RBAR_SH_SHIFT		3
#define _RBAR_SH_MASK		GENMASK_32(4, 3)
#define _RBAR_BASE_SHIFT	5
#define _RBAR_BASE_MASK		GENMASK_32(31, 5)

/* RLAR bitfield */
#define _RLAR_EN_SHIFT		0
#define _RLAR_EN_MASK		BIT(0)
#define _RLAR_ATTRINDX_SHIFT	1
#define _RLAR_ATTRINDX_MASK	GENMASK_32(3, 1)
#define _RLAR_LIMIT_SHIFT	5
#define _RLAR_LIMIT_MASK	GENMASK_32(31, 5)

struct arm_mpu_config {
	uintptr_t base;
	const struct mpu_region *regions;
	const int n_regions;
};

struct arm_mpu_data {
	uint32_t hw_n_regions;
};

static void arm_mpu_enable(const struct device *dev,
			   uint32_t privdef_en, uint32_t hfnmi_en)
{
	const struct arm_mpu_config *drv_cfg = dev_get_config(dev);
	uint32_t ctrl = _CTRL_ENABLE_MASK;

	/* Set pre-defined MAIR_ATTRS for memory */
	io_write32(drv_cfg->base + _MPU_MAIR0, MPU_MAIR_ATTRS);

	ctrl |= _FLD_PREP(_CTRL_PRIVDEFENA, privdef_en);
	ctrl |= _FLD_PREP(_CTRL_HFNMIENA, hfnmi_en);

	io_write32(drv_cfg->base + _MPU_CTRL, ctrl);

	__DSB();
	__ISB();
}

static void __maybe_unused arm_mpu_disable(const struct device *dev)
{
	const struct arm_mpu_config *drv_cfg = dev_get_config(dev);

	/* Reset all fields as enable does full setup */
	io_write32(drv_cfg->base + _MPU_CTRL, 0);
	__DSB();
	__ISB();
}

static int arm_mpu_region_enable(const struct device *dev, uint32_t region_nr)
{
	const struct arm_mpu_config *drv_cfg = dev_get_config(dev);
	uint32_t attr = drv_cfg->regions[region_nr].mem_attr;
	uint32_t base_cfg, limit_cfg;
	uint32_t ctrl_before;

	if ((drv_cfg->regions[region_nr].base & ~_RBAR_BASE_MASK) != 0)
		return -EINVAL;

	if ((drv_cfg->regions[region_nr].limit & ~_RLAR_LIMIT_MASK) != 0x1F)
		return -EINVAL;

	base_cfg = drv_cfg->regions[region_nr].base & _RBAR_BASE_MASK;
	base_cfg |= _FLD_PREP(_RBAR_SH, _FLD_GET(DT_MEM_ARM_MPU_SH, attr));
	base_cfg |= _FLD_PREP(_RBAR_AP, _FLD_GET(DT_MEM_ARM_MPU_AP, attr));
	base_cfg |= _FLD_PREP(_RBAR_XN, _FLD_GET(DT_MEM_ARM_MPU_XN, attr));

	limit_cfg = drv_cfg->regions[region_nr].limit & _RLAR_LIMIT_MASK;
	limit_cfg |= _FLD_PREP(_RLAR_ATTRINDX, _FLD_GET(DT_MEM_ARM_MPU_MAIR_IDX, attr));
	limit_cfg |= _RLAR_EN_MASK;

	ctrl_before = io_read32(drv_cfg->base + _MPU_CTRL);
	io_write32(drv_cfg->base + _MPU_CTRL, 0);

	io_write32(drv_cfg->base + _MPU_RNR, _FLD_PREP(_RNR_REGION, region_nr));
	io_write32(drv_cfg->base + _MPU_RBAR, base_cfg);
	io_write32(drv_cfg->base + _MPU_RLAR, limit_cfg);

	io_write32(drv_cfg->base + _MPU_CTRL, ctrl_before);

	/* Enable MPU before the next instruction */
	__DSB();
	__ISB();

	return 0;
}

static void arm_mpu_region_disable(const struct device *dev, uint32_t region_nr)
{
	const struct arm_mpu_config *drv_cfg = dev_get_config(dev);
	uint32_t ctrl_before;

	ctrl_before = io_read32(drv_cfg->base + _MPU_CTRL);
	io_write32(drv_cfg->base + _MPU_CTRL, 0);

	io_write32(drv_cfg->base + _MPU_RNR, _FLD_PREP(_RNR_REGION, region_nr));
	io_write32(drv_cfg->base + _MPU_RBAR, 0);
	io_write32(drv_cfg->base + _MPU_RLAR, 0);

	io_write32(drv_cfg->base + _MPU_CTRL, ctrl_before);
	__DSB();
	__ISB();
}

static void arm_mpu_clean_all(const struct device *dev)
{
	struct arm_mpu_data *drv_data = dev_get_data(dev);
	int i;

	for (i = 0; i < drv_data->hw_n_regions; i++) {
		arm_mpu_region_disable(dev, i);
	}
}

static int arm_mpu_set_region(const struct device *dev)
{
	const struct arm_mpu_config *drv_cfg = dev_get_config(dev);
	int i;

	arm_mpu_clean_all(dev);

	for (i = 0; i < drv_cfg->n_regions; i++) {
		if (arm_mpu_region_enable(dev, i))
			return -EINVAL;
	}

	arm_mpu_enable(dev, _PRIV_DEFAULT_ENABLE, _HARDFAULT_NMI_ENABLE);

	return 0;
}

static void arm_mpu_get_hwconfig(const struct device *dev)
{
	const struct arm_mpu_config *drv_cfg = dev_get_config(dev);
	struct arm_mpu_data *drv_data = dev_get_data(dev);

	drv_data->hw_n_regions = _FLD_GET(_TYPE_DREGION, io_read32(drv_cfg->base + _MPU_TYPE));
}

static int __maybe_unused arm_mpu_init(const struct device *dev)
{
	const struct arm_mpu_config *drv_cfg = dev_get_config(dev);
	struct arm_mpu_data *drv_data = dev_get_data(dev);

	arm_mpu_get_hwconfig(dev);

	if (drv_cfg->n_regions > drv_data->hw_n_regions)
		return -ENOTSUP;

	return arm_mpu_set_region(dev);
}

#ifdef CONFIG_PM_DEVICE
static int arm_mpu_pm_action(const struct device *dev,
			     enum pm_device_action action, uint32_t pm_hint)
{
	if (PM_HINT_IS_STATE(pm_hint, CONTEXT) && (action == PM_DEVICE_ACTION_RESUME))
		return arm_mpu_set_region(dev);

	return 0;
}
#endif

#define MPU_MR_HAS_MEM_ATTR(_mr_node_id)							\
	DT_NODE_HAS_PROP(_mr_node_id, tfm_memory_attr)

#define MPU_MR_MEM_ATTR(_mr_node_id)								\
	DT_MEM_ARCH_ATTR_GET(DT_PROP(_mr_node_id, tfm_memory_attr))

/* RLAR holds the address of the last byte of the region */
#define DT_MPU_REGION(_node_id, _prop, _idx)							\
	MPU_REGION(DT_MEMORY_REGION_ADDR_BY_IDX(_node_id, _idx),				\
		   DT_MEMORY_REGION_ADDR_BY_IDX(_node_id, _idx) +				\
		   DT_MEMORY_REGION_SIZE_BY_IDX(_node_id, _idx) - 1,				\
		   MPU_MR_MEM_ATTR(DT_MEMORY_REGION_BY_IDX(_node_id, _idx)))

#define DT_INST_MPU_MEMORY_REGION(inst)								\
	COND_CODE_1(DT_INST_MEMORY_REGION_HAS(inst),						\
		    (DT_INST_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP(inst, DT_MPU_REGION, (,))),	\
		    ())

/*
 * build assert if:
 * - mpu memory region (enabled) lacks a tfm,memory-attr property
 * - number region > _MPU_MAX_REGIONS
 */
#define BUILD_ASSERT_MEM_ATTR(_node_id, _prop, _idx)						\
	BUILD_ASSERT(MPU_MR_HAS_MEM_ATTR(DT_MEMORY_REGION_BY_IDX(_node_id, _idx)),		\
		     "mpu memory-region "							\
		     DT_NODE_PATH(DT_MEMORY_REGION_BY_IDX(_node_id, _idx))			\
		     " has no 'tfm,memory-attr' property");

#define BUILD_ASSERT_MPU_MEMORY_REGION(inst)							\
	COND_CODE_1(DT_INST_MEMORY_REGION_HAS(inst),						\
		    (DT_INST_FOREACH_MEMORY_REGION_STATUS_OKAY(inst, BUILD_ASSERT_MEM_ATTR)),	\
		    ())										\
	BUILD_ASSERT(ARRAY_SIZE(mpu_regions_##inst) <= _MPU_MAX_REGIONS,			\
		     "too many mpu regions defined for " DT_NODE_PATH(DT_DRV_INST(inst)));

#define ARM_MPU_INIT(n)										\
												\
static const struct mpu_region mpu_regions_##n[] = {						\
	MPU_PLAT_BUILTIN()									\
	DT_INST_MPU_MEMORY_REGION(n)								\
};												\
												\
static const struct arm_mpu_config cfg_##n = {							\
	.base = DT_INST_REG_ADDR(n),								\
	.regions = mpu_regions_##n,								\
	.n_regions = ARRAY_SIZE(mpu_regions_##n),						\
};												\
												\
static struct arm_mpu_data data_##n = {};							\
												\
BUILD_ASSERT_MPU_MEMORY_REGION(n)								\
												\
PM_DEVICE_DT_INST_DEFINE(n, arm_mpu_pm_action, PM_DEVICE_F_NONE);				\
												\
DEVICE_DT_INST_DEFINE(n, &arm_mpu_init,								\
		      PM_DEVICE_DT_INST_GET(n),							\
		      &data_##n,								\
		      &cfg_##n,									\
		      ARCH, 1,									\
		      NULL);

DT_INST_FOREACH_STATUS_OKAY(ARM_MPU_INIT)
