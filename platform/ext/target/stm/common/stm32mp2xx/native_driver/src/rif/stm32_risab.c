/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_risab

#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <lib/mmio.h>
#include <lib/utils_def.h>
#include <debug.h>
#include <device.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <clk.h>

#include <dt-bindings/rif/stm32mp25-rif.h>
#include <dt-bindings/rif/stm32mp25-risab.h>

#define _RISAB_CR			U(0x0)
#define _RISAB_IASR			U(0x8)
#define _RISAB_IACR			U(0xC)
#define _RISAB_RCFGLOCKR		U(0x10)
#define _RISAB_IAESR			U(0x20)
#define _RISAB_IADDR			U(0x24)
#define _RISAB_PGy_SECCFGR(y)		(U(0x100) + (0x4 * (y)))
#define _RISAB_PGy_PRIVCFGR(y)		(U(0x200) + (0x4 * (y)))
#define _RISAB_RISAB_PGy_C2PRIVCFGR(y)	(U(0x600) + (0x4 * (y)))
#define _RISAB_CIDxPRIVCFGR(x)		(U(0x800) + (0x20 * (x)))
#define _RISAB_CIDxRDCFGR(x)		(U(0x808) + (0x20 * (x)))
#define _RISAB_CIDxWRCFGR(x)		(U(0x810) + (0x20 * (x)))
#define _RISAB_PGy_CIDCFGR(y)		(U(0xA00) + (0x4 * (y)))
#define _RISAB_HWCFGR3			U(0xFE8)
#define _RISAB_HWCFGR2			U(0xFEC)
#define _RISAB_HWCFGR1			U(0xFF0)
#define _RISAB_VERR			U(0xFF4)
#define _RISAB_IPIDR			U(0xFF8)
#define _RISAB_SIDR			U(0xFFC)

/* CR bitfield */
#define _RISAB_CR_GLOCK			BIT(0)
#define _RISAB_CR_SRWIAD		BIT(31)

/* IACR bitfield */
#define _RISAB_IACR_CAEF_MASK		BIT(0)
#define _RISAB_IACR_CAEF_SHIFT		0
#define _RISAB_IACR_IAEF_MASK		BIT(1)
#define _RISAB_IACR_IAEF_SHIFT		1
#define _RISAB_IACR_MASK		_RISAB_IACR_CAEF_MASK | \
					_RISAB_IACR_IAEF_MASK

/* PG_SECCFGR bitfields */
#define _RISAB_PG_SECCFGR_MASK		GENMASK_32(7, 0)

/* PG_PRIVCFGR bitfields */
#define _RISAB_PG_PRIVCFGR_MASK		GENMASK_32(7, 0)

/* PG_CIDCFGR bitfields */
#define _RISAB_PG_CIDCFGR_CFEN		BIT(0)
#define _RISAB_PG_CIDCFGR_DCEN		BIT(2)
#define _RISAB_PG_CIDCFGR_DDCID_MASK	GENMASK_32(6, 4)
#define _RISAB_PG_CIDCFGR_DDCID_SHIFT	4
#define _RISAB_PG_CIDCFGR_CONF_MASK	(_RISAB_PG_CIDCFGR_CFEN | \
					 _RISAB_PG_CIDCFGR_DCEN | \
					 _RISAB_PG_CIDCFGR_DDCID_MASK)

/* HWCFGR1 bitfield */
#define _RISAB_HWCFGR1_CFG4_MASK	GENMASK_32(15, 12)
#define _RISAB_HWCFGR1_CFG4_SHIFT	12
#define _RISAB_HWCFGR1_CFG5_MASK	GENMASK_32(19, 16)
#define _RISAB_HWCFGR1_CFG5_SHIFT	16
#define _RISAB_HWCFGR1_CFG6_MASK	GENMASK_32(23, 20)
#define _RISAB_HWCFGR1_CFG6_SHIFT	20
#define _RISAB_HWCFGR1_CFG7_MASK	GENMASK_32(27, 24)
#define _RISAB_HWCFGR1_CFG7_SHIFT	24

#define _RISAB_MAX_PAGES		32
#define _RISAB_MAX_CID			7

struct risab_region {
	uint8_t	id;
	uint32_t sec_cfg;
	uint32_t priv_cfg;
	uint32_t cid_cfg;
	uint32_t first_page;
	uint32_t last_page;
};

struct risab_dt_region {
	uint32_t st_protreg;
	uintptr_t base;
	size_t size;
};

struct risab_memory_area {
	uintptr_t base;
	size_t size;
};

struct stm32_risab_config {
	uintptr_t base;
	const struct risab_memory_area *risab_marea;
	const int n_risab_marea;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct risab_dt_region *dt_regions;
	const int ndt_regions;
	const bool st_srwiad;
	const bool errata_ahbrisab;
	const bool st_glock;
};

/*
 * hw_xx: hardware information
 * page_configured: bitmap of pages configured
 */
struct stm32_risab_data {
	uint32_t hw_mm_sz;
	uint8_t hw_n_pages;
	uint8_t hw_n_blocks;
	uint16_t hw_block_sz;
	uint32_t page_configured;
	uint32_t plist[_RISAB_MAX_CID];
	uint32_t rlist[_RISAB_MAX_CID];
	uint32_t wlist[_RISAB_MAX_CID];
};

static void stm32_risab_set_list(const struct device *dev, uint32_t cid_bf,
				 uint32_t *list, uint32_t pages_mask)
{
	uint8_t cid;

	for (cid = 0; cid < _RISAB_MAX_CID && cid_bf != 0; cid++) {
		if (cid_bf & BIT(0))
			list[cid] |= pages_mask;

		cid_bf >>= 1;
	}
}

static int stm32_risab_dt_to_region(const struct device *dev,
				    uint8_t idx, struct risab_region *region)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	struct stm32_risab_data *drv_data = dev_get_data(dev);
	const struct risab_dt_region *dt_region = &(drv_cfg->dt_regions[idx]);
	uint32_t page_sz = drv_data->hw_block_sz * drv_data->hw_n_blocks;
	const struct risab_memory_area *m_area = drv_cfg->risab_marea;
	uint32_t offset_start = 0;
	uint32_t offset_end = 0;
	uint32_t region_pages;
	uint8_t dccid;
	int i;

	memset(region, 0, sizeof(struct risab_region));

	for (i = 0; i < drv_cfg->n_risab_marea; i++, m_area++) {
		offset_start = dt_region->base - m_area->base;
		offset_end = dt_region->base + dt_region->size - m_area->base;

		if (offset_start >= 0 && offset_end <= m_area->size)
			break;
	}

	if (drv_cfg->n_risab_marea == 0 || i >= drv_cfg->n_risab_marea) {
		EMSG("[%s] region[0x%x:0x%x] is out bound of memory area ranges\n",
		     dev->name, dt_region->base, dt_region->base + dt_region->size);
		return -EINVAL;
	}

	if (offset_start % page_sz || offset_end % page_sz) {
		EMSG("[%s] region not aligned on page size\n", dev->name);
		return -ENOTSUP;
	}

	region->first_page = offset_start / page_sz;
	region->last_page = (offset_end - 1) / page_sz;
	region_pages = GENMASK_32(region->last_page, region->first_page);

	if (region_pages & drv_data->page_configured) {
		EMSG("[%s] region overlap detected\n", dev->name);
		return -EINVAL;
	}

	if (_FLD_GET(DT_RISAB_SEC, dt_region->st_protreg))
		region->sec_cfg = _RISAB_PG_PRIVCFGR_MASK;

	if (_FLD_GET(DT_RISAB_DPRIV, dt_region->st_protreg))
		region->priv_cfg = _RISAB_PG_PRIVCFGR_MASK;

	if (_FLD_GET(DT_RISAB_CFEN, dt_region->st_protreg))
		region->cid_cfg = _RISAB_PG_CIDCFGR_CFEN;

	if (_FLD_GET(DT_RISAB_DCEN, dt_region->st_protreg))
		region->cid_cfg |= _RISAB_PG_CIDCFGR_DCEN;

	dccid = _FLD_GET(DT_RISAB_DCCID, dt_region->st_protreg);
	if (dccid)
		region->cid_cfg |= _FLD_PREP(_RISAB_PG_CIDCFGR_DDCID, dccid);

	region->id = idx;

	drv_data->page_configured |= region_pages;

	return 0;
}

static void stm32_risab_set_priv_cfg(const struct device *dev,
				     struct risab_region *region)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	uint32_t i;

	/* set all priv of region pages */
	for (i = region->first_page; i<= region->last_page; i++)
		io_clrsetbits32(drv_cfg->base + _RISAB_PGy_PRIVCFGR(i),
				_RISAB_PG_PRIVCFGR_MASK, region->priv_cfg);
}

static void stm32_risab_set_cid_cfg(const struct device *dev,
				    struct risab_region *region)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	uint32_t i;

	/*
	 * When TDCID, TFM should be the one to set the CID filtering
	 * configuration. Clearing previous configuration prevents
	 * undesired events during the only legitimate configuration.
	 */
	for (i = region->first_page; i<= region->last_page; i++)
		io_write32(drv_cfg->base + _RISAB_PGy_CIDCFGR(i), region->cid_cfg);
}

static void stm32_risab_set_sec_cfg(const struct device *dev,
				    struct risab_region *region)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	uint32_t i;

	for (i = region->first_page; i<= region->last_page; i++)
		io_clrsetbits32(drv_cfg->base + _RISAB_PGy_SECCFGR(i),
				_RISAB_PG_SECCFGR_MASK, region->sec_cfg);
}

static void stm32_risab_set_cid_x_cfg(const struct device *dev)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	struct stm32_risab_data *drv_data = dev_get_data(dev);
	uint8_t cid;

	for (cid = 0; cid < _RISAB_MAX_CID; cid++) {
		io_write32(drv_cfg->base + _RISAB_CIDxRDCFGR(cid),
			   drv_data->rlist[cid]);
		io_write32(drv_cfg->base + _RISAB_CIDxWRCFGR(cid),
			   drv_data->wlist[cid]);
		io_write32(drv_cfg->base + _RISAB_CIDxPRIVCFGR(cid),
			   drv_data->plist[cid]);
	}
}

static bool stm32_risab_access_granted(const struct device *dev,
				       struct risab_region *region)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	uint32_t cid_cfg = io_read32(drv_cfg->base +
				     _RISAB_PGy_CIDCFGR(region->first_page));

	/* No CID filtering */
	if (!(cid_cfg & _RISAB_PG_CIDCFGR_CFEN))
		return true;

	/* Trusted CID access */
	if (IS_ENABLED(STM32_M33TDCID) &&
	    (cid_cfg & _RISAB_PG_CIDCFGR_CFEN &&
	     !(cid_cfg & _RISAB_PG_CIDCFGR_DCEN)))
		return true;

	/* Delegated CID access check */
	if (cid_cfg & _RISAB_PG_CIDCFGR_CFEN &&
	    cid_cfg & _RISAB_PG_CIDCFGR_DCEN &&
	    ((cid_cfg & _RISAB_PG_CIDCFGR_DDCID_MASK) >>
	     _RISAB_PG_CIDCFGR_DDCID_SHIFT) == RIF_CID2)
		return true;

	return false;
}

static int stm32_risab_region_cfg(const struct device *dev, uint8_t idx)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	struct stm32_risab_data *drv_data = dev_get_data(dev);
	const struct risab_dt_region *dt_region = &(drv_cfg->dt_regions[idx]);
	struct risab_region region;
	uint32_t region_pages;
	uint8_t cid_bf;
	int err;

	err = stm32_risab_dt_to_region(dev, idx, &region);
	if (err)
		return err;

	stm32_risab_set_priv_cfg(dev, &region);

	if (!stm32_risab_access_granted(dev, &region))
		return 0;

	/*
	 * This sequence will generate an IAC if the CID filtering
	 * configuration is inconsistent with these desired rights
	 * to apply. Start by default setting security configuration
	 * for all blocks.
	 */
	stm32_risab_set_sec_cfg(dev, &region);

	/* pages mask to set on compartiment X priv/read/write registers */
	region_pages = GENMASK_32(region.last_page, region.first_page);

	cid_bf = _FLD_GET(DT_RISAB_PLIST, dt_region->st_protreg);
	stm32_risab_set_list(dev, cid_bf, drv_data->plist, region_pages);

	cid_bf = _FLD_GET(DT_RISAB_READ_LIST, dt_region->st_protreg);
	stm32_risab_set_list(dev, cid_bf, drv_data->rlist, region_pages);

	cid_bf = _FLD_GET(DT_RISAB_WRITE_LIST, dt_region->st_protreg);
	stm32_risab_set_list(dev, cid_bf, drv_data->wlist, region_pages);

	if (drv_cfg->errata_ahbrisab) {
		drv_data->rlist[RIF_CID0] |= region_pages;
		drv_data->wlist[RIF_CID0] |= region_pages;
	}

	/* update cid read/write/priv cfg */
	stm32_risab_set_cid_x_cfg(dev);

	/* Enable RIF configuration or not */
	stm32_risab_set_cid_cfg(dev, &region);

	return 0;
}

static void stm32_risab_clear_sec_priv(const struct device *dev)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	struct stm32_risab_data *drv_data = dev_get_data(dev);
	uint8_t i;

	for (i = 0; i < drv_data->hw_n_pages; i++) {
		io_clrbits32(drv_cfg->base + _RISAB_PGy_SECCFGR(i),
			     _RISAB_PG_SECCFGR_MASK);
		io_clrbits32(drv_cfg->base + _RISAB_PGy_PRIVCFGR(i),
			     _RISAB_PG_PRIVCFGR_MASK);
	}
}

static void stm32_risab_get_hwconfig(const struct device *dev)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	struct stm32_risab_data *drv_data = dev_get_data(dev);
	uint32_t regval;

	drv_data->hw_mm_sz = io_read32(drv_cfg->base + _RISAB_HWCFGR2);

	regval =  io_read32(drv_cfg->base + _RISAB_HWCFGR1);
	/* cfg[7..4] is on power of two */
	drv_data->hw_n_pages = 1 << _FLD_GET(_RISAB_HWCFGR1_CFG7, regval);
	drv_data->hw_n_blocks = 1 << _FLD_GET(_RISAB_HWCFGR1_CFG6, regval);
	drv_data->hw_block_sz = 1 << _FLD_GET(_RISAB_HWCFGR1_CFG5, regval);
}

static void __maybe_unused stm32_risab_deinit_data(const struct device *dev)
{
	struct stm32_risab_data *drv_data = dev_get_data(dev);

	memset(drv_data, 0, sizeof(struct stm32_risab_data));
}

static int __maybe_unused stm32_risab_init(const struct device *dev)
{
	const struct stm32_risab_config *drv_cfg = dev_get_config(dev);
	struct stm32_risab_data *drv_data = dev_get_data(dev);
	struct clk *clk;
	int i, err;

	clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (!clk)
		return -ENODEV;

	err = clk_enable(clk);
	if (err)
		return err;

	stm32_risab_get_hwconfig(dev);

	if (drv_data->hw_n_pages > _RISAB_MAX_PAGES) {
		DMSG("need to increase driver page bitmap\n");
		return -ENOTSUP;
	}

	if (IS_ENABLED(STM32_M33TDCID)) {
		io_setbits32(drv_cfg->base + _RISAB_IACR, _RISAB_IACR_MASK);
		if (drv_cfg->st_srwiad)
			io_setbits32(drv_cfg->base + _RISAB_CR,
				     _RISAB_CR_SRWIAD);
		else
			io_clrbits32(drv_cfg->base + _RISAB_CR,
				     _RISAB_CR_SRWIAD);
	}

	stm32_risab_clear_sec_priv(dev);

	for(i = 0; i < drv_cfg->ndt_regions; i++) {
		err = stm32_risab_region_cfg(dev, i);
		if (err)
			return err;
	}

        if (IS_ENABLED(STM32_M33TDCID)) {
		if (drv_cfg->st_glock) {
			DMSG("GLOCK Set\n");
			io_setbits32(drv_cfg->base + _RISAB_CR, _RISAB_CR_GLOCK);
                }
        }

	clk_disable(clk);

	return err;
}

#ifdef CONFIG_PM_DEVICE
static __unused int stm32_risab_pm_action(const struct device *dev,
					  enum pm_device_action action, uint32_t pm_hint)
{
	int err = 0;

	if (!PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return 0;

	if (action == PM_DEVICE_ACTION_SUSPEND)
		stm32_risab_deinit_data(dev);
	else
		err = stm32_risab_init(dev);

	return err;
}
#endif

#define RISAB_MR_DT_PROTREG(_node_id, _prop, _idx)			\
	DT_PROP_BY_IDX(DT_PHANDLE_BY_IDX(_node_id, _prop, _idx), st_protreg, 0)

#define RISAB_REGION(_node_id, _prop, _idx)					\
	{									\
		.base = DT_REG_ADDR(DT_PHANDLE_BY_IDX(_node_id, _prop, _idx)),	\
		.size = DT_REG_SIZE(DT_PHANDLE_BY_IDX(_node_id, _prop, _idx)),	\
		.st_protreg = RISAB_MR_DT_PROTREG(_node_id, _prop, _idx),	\
	},

#define RISAB_MAREA(_node_id, _idx)						\
	{									\
		.base = DT_RANGES_PARENT_BUS_ADDRESS_BY_IDX(_node_id, _idx),	\
		.size = DT_RANGES_LENGTH_BY_IDX(_node_id, _idx),		\
	},

#define STM32_RISAB_INIT(n)							\
										\
static const struct risab_dt_region risab_dt_regions_##n[] = {			\
	DT_INST_FOREACH_PROP_ELEM_SEP(n, memory_region, RISAB_REGION, ())	\
};										\
										\
static const struct risab_memory_area risab_marea_##n[] = {			\
	DT_INST_FOREACH_RANGE(n, RISAB_MAREA)					\
};										\
										\
static const struct stm32_risab_config stm32_risab_cfg_##n = {			\
	.base = DT_INST_REG_ADDR_BY_NAME(n, risab),				\
	.risab_marea = risab_marea_##n,						\
	.n_risab_marea = DT_INST_NUM_RANGES(n),					\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),			\
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(n, bits),		\
	.dt_regions = risab_dt_regions_##n,					\
	.ndt_regions = ARRAY_SIZE(risab_dt_regions_##n),			\
	.st_srwiad = DT_INST_PROP_OR(n, st_srwiad, false),			\
	.errata_ahbrisab = DT_INST_PROP_OR(n, st_errata_ahbrisab, false),	\
	.st_glock = DT_INST_PROP_OR(n, st_glock, false),			\
};										\
										\
PM_DEVICE_DT_INST_DEFINE(n, stm32_risab_pm_action, PM_DEVICE_F_NONE);		\
										\
static struct stm32_risab_data stm32_risab_data_##n = {};			\
										\
DEVICE_DT_INST_DEFINE(n, &stm32_risab_init,					\
		      PM_DEVICE_DT_INST_GET(n),					\
		      &stm32_risab_data_##n,					\
		      &stm32_risab_cfg_##n,					\
		      CORE, 4,							\
		      NULL);

DT_INST_FOREACH_STATUS_OKAY(STM32_RISAB_INIT)
