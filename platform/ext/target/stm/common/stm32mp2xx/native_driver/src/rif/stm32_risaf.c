/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_risaf

#include <device.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>

#include <debug.h>

#include <boot/tfm_boot_status.h>
#include <lib/delay.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/timeout.h>
#include <lib/utils_def.h>
#include <cmsis.h>
#include <clk.h>

#include <entropy.h>
#include <firewall.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <string.h>
#include <strings.h>

#include <dt-bindings/rif/stm32mp2-risaf.h>

extern int boot_add_data_to_shared_area(uint8_t major_type,
					uint16_t minor_type,
					size_t size,
					const uint8_t *data);

/* ID Registers */
#define _RISAF_SR			0x04U
#define _RISAF_KEYR			0x30U
#define _RISAF_REG_CFGR			0x40U
#define _RISAF_REG_STARTR		0x44U
#define _RISAF_REG_ENDR			0x48U
#define _RISAF_REG_CIDCFGR		0x4CU
#define _RISAF_SUBREG_CFGR		0x50U
#define _RISAF_SUBREG_STARTR		0x54U
#define _RISAF_SUBREG_ENDR		0x58U
#define _RISAF_SUBREG_NESTR		0x5CU
#define _RISAF_REGX_OFFSET(x)		(0x40 * (x - 1))
#define _RISAF_SUBREGX_OFFSET(x, y)	((0x40 * (x - 1)) + (0x10 * (y)))

/* RISAF MCE extension registers */
#define _RISAF_XCR			U(0x1C00)
#define _RISAF_XSR			U(0x1C04)
#define _RISAF_MKEYR			U(0x1E00)

#define _RISAF_HWCFGR			0xFF0U
#define _RISAF_VERR			0xFF4U

/* _RISAF_SR register fields */
#define _RISAF_SR_KEYVALID_SHIFT	U(0)
#define _RISAF_SR_KEYVALID		BIT(_RISAF_SR_KEYVALID_SHIFT)
#define _RISAF_SR_KEYRDY_SHIFT		U(1)
#define _RISAF_SR_KEYRDY		BIT(_RISAF_SR_KEYRDY_SHIFT)
#define _RISAF_SR_ENCDIS_SHIFT		U(2)
#define _RISAF_SR_ENCDIS		BIT(_RISAF_SR_ENCDIS_SHIFT)

/* _RISAF_REG_CFGR(n) register fields */
#define _RISAF_REG_CFGR_BREN_SHIFT	U(0)
#define _RISAF_REG_CFGR_BREN		BIT(_RISAF_REG_CFGR_BREN_SHIFT)
#define _RISAF_REG_CFGR_SEC_SHIFT	U(8)
#define _RISAF_REG_CFGR_SEC		BIT(_RISAF_REG_CFGR_SEC_SHIFT)
#define _RISAF_REG_CFGR_ENC_SHIFT	U(14)
#define _RISAF_REG_CFGR_ENC		GENMASK_32(15, 14)
#define _RISAF_REG_CFGR_PRIVC_SHIFT	U(16)
#define _RISAF_REG_CFGR_PRIVC_MASK	GENMASK_32(23, 16)
#define _RISAF_REG_CFGR_ALL_MASK	(_RISAF_REG_CFGR_BREN | \
					 _RISAF_REG_CFGR_SEC | \
					 _RISAF_REG_CFGR_ENC | \
					 _RISAF_REG_CFGR_PRIVC_MASK)

/* _RISAF_REGx_STARTR register fields */
#define _RISAF_REGx_STARTR_BADDSTART_MASK	GENMASK(31, 12)
#define _RISAF_REGx_STARTR_BADDSTART_SHIFT	12

/* _RISAF_REGx_ENDR register fields */
#define _RISAF_REGx_ENDR_BADDEND_MASK		GENMASK(31, 12)
#define _RISAF_REGx_ENDR_BADDEND_SHIFT		12

/* _RISAF_REG_CIDCFGR(n) register fields */
#define _RISAF_REG_CIDCFGR_RDENC_SHIFT	U(0)
#define _RISAF_REG_CIDCFGR_RDENC_MASK	GENMASK_32(7, 0)
#define _RISAF_REG_CIDCFGR_WRENC_SHIFT	U(16)
#define _RISAF_REG_CIDCFGR_WRENC_MASK	GENMASK_32(23, 16)
#define _RISAF_REG_CIDCFGR_ALL_MASK	(_RISAF_REG_CIDCFGR_RDENC_MASK | \
					 _RISAF_REG_CIDCFGR_WRENC_MASK)

#define _RISAF_HWCFGR_CFG1_MASK		GENMASK_32(7, 0)
#define _RISAF_HWCFGR_CFG1_SHIFT	0
#define _RISAF_HWCFGR_CFG2_MASK		GENMASK_32(15, 8)
#define _RISAF_HWCFGR_CFG2_SHIFT	8
#define _RISAF_HWCFGR_CFG3_MASK		GENMASK_32(23, 16)
#define _RISAF_HWCFGR_CFG3_SHIFT	16
#define _RISAF_HWCFGR_CFG4_MASK		GENMASK_32(31, 24)
#define _RISAF_HWCFGR_CFG4_SHIFT	24

/* _RISAF_SUBREG_CFGR(n, m) register fields */
#define _RISAF_SUBREG_CFGR_SREN_SHIFT	U(0)
#define _RISAF_SUBREG_CFGR_SREN		BIT(_RISAF_SUBREG_CFGR_SREN_SHIFT)
#define _RISAF_SUBREG_CFGR_RLOCK_SHIFT	U(1)
#define _RISAF_SUBREG_CFGR_RLOCK	BIT(_RISAF_SUBREG_CFGR_RLOCK_SHIFT)
#define _RISAF_SUBREG_CFGR_SRCID_SHIFT	U(4)
#define _RISAF_SUBREG_CFGR_SRCID	GENMASK_32(6, 4)
#define _RISAF_SUBREG_CFGR_SEC_SHIFT	U(8)
#define _RISAF_SUBREG_CFGR_SEC		BIT(_RISAF_SUBREG_CFGR_SEC_SHIFT)
#define _RISAF_SUBREG_CFGR_PRIV_SHIFT	U(9)
#define _RISAF_SUBREG_CFGR_PRIV		BIT(_RISAF_SUBREG_CFGR_PRIV_SHIFT)
#define _RISAF_SUBREG_CFGR_RDEN_SHIFT	U(12)
#define _RISAF_SUBREG_CFGR_RDEN		BIT(_RISAF_SUBREG_CFGR_RDEN_SHIFT)
#define _RISAF_SUBREG_CFGR_WREN_SHIFT	U(13)
#define _RISAF_SUBREG_CFGR_WREN		BIT(_RISAF_SUBREG_CFGR_WREN_SHIFT)
#define _RISAF_SUBREG_CFGR_ALL_MASK	(_RISAF_SUBREG_CFGR_SREN | \
					 _RISAF_SUBREG_CFGR_RLOCK | \
					 _RISAF_SUBREG_CFGR_SRCID | \
					 _RISAF_SUBREG_CFGR_SEC | \
					 _RISAF_SUBREG_CFGR_PRIV | \
					 _RISAF_SUBREG_CFGR_RDEN | \
					 _RISAF_SUBREG_CFGR_WREN)

/* _RISAF_SUBREG_NESTR(n, m) register fields */
#define _RISAF_SUBREG_NESTR_DCEN_SHIFT	U(2)
#define _RISAF_SUBREG_NESTR_DCEN	BIT(_RISAF_SUBREG_NESTR_DCEN_SHIFT)
#define _RISAF_SUBREG_NESTR_DCCID_SHIFT	U(4)
#define _RISAF_SUBREG_NESTR_DCCID	GENMASK_32(6, 4)
#define _RISAF_SUBREG_NESTR_ALL_MASK	(_RISAF_SUBREG_NESTR_DCEN | \
					 _RISAF_SUBREG_NESTR_DCCID)

/* RISAF MCE extension register field description */
/* _RISAF_XCR register fields */
#define _RISAF_XCR_XLOCK		BIT(0)
#define _RISAF_XCR_MKLOCK		BIT(1)
#define _RISAF_XCR_CIPHERSEL_SHIFT	4
#define _RISAF_XCR_CIPHERSEL_MASK	GENMASK_32(5, 4)
#define _RISAF_XCR_CIPHERSEL_AES128	1U
#define _RISAF_XCR_CIPHERSEL_AES256	3U
/* _RISAF_XSR register fields */
#define _RISAF_XSR_MKVALID		BIT(0)

#define _RISAF_GET_REGION_CFG(cfg)					\
	((_FLD_GET(DT_RISAF_EN, cfg) << _RISAF_REG_CFGR_BREN_SHIFT) |	\
	 (_FLD_GET(DT_RISAF_SEC, cfg) << _RISAF_REG_CFGR_SEC_SHIFT) |	\
	 (_FLD_GET(DT_RISAF_ENC, cfg) << _RISAF_REG_CFGR_ENC_SHIFT) |	\
	 (_FLD_GET(DT_RISAF_PRIV, cfg) << _RISAF_REG_CFGR_PRIVC_SHIFT))

#define _RISAF_GET_REGION_CID_CFG(cfg)						\
	((_FLD_GET(DT_RISAF_WRITE, cfg) << _RISAF_REG_CIDCFGR_WRENC_SHIFT) |	\
	 (_FLD_GET(DT_RISAF_READ, cfg) << _RISAF_REG_CIDCFGR_RDENC_SHIFT))

#define _RISAF_GET_SUBREGION_CFG(cfg)							\
	((_FLD_GET(DT_RISAF_SUB_EN, cfg) << _RISAF_SUBREG_CFGR_SREN_SHIFT) |		\
	 (_FLD_GET(DT_RISAF_SUB_RLOCK, cfg) << _RISAF_SUBREG_CFGR_RLOCK_SHIFT) |	\
	 (_FLD_GET(DT_RISAF_SUB_SRCID, cfg) << _RISAF_SUBREG_CFGR_SRCID_SHIFT) |	\
	 (_FLD_GET(DT_RISAF_SUB_SEC, cfg) << _RISAF_SUBREG_CFGR_SEC_SHIFT) |		\
	 (_FLD_GET(DT_RISAF_SUB_PRIV, cfg) << _RISAF_SUBREG_CFGR_PRIV_SHIFT) |		\
	 (_FLD_GET(DT_RISAF_SUB_RDEN, cfg) << _RISAF_SUBREG_CFGR_RDEN_SHIFT) |		\
	 (_FLD_GET(DT_RISAF_SUB_WREN, cfg) <<  _RISAF_SUBREG_CFGR_WREN_SHIFT))

#define _RISAF_GET_SUBREGION_NEST_CFG(cfg)						\
	((_FLD_GET(DT_RISAF_SUB_DCEN, cfg) << _RISAF_SUBREG_NESTR_DCEN_SHIFT) |		\
	 (_FLD_GET(DT_RISAF_SUB_DCCID, cfg) << _RISAF_SUBREG_NESTR_DCCID_SHIFT))

#define _RISAF_TIMEOUT_1MS_IN_US	USEC_PER_MSEC
#define _RISAF_TIMEOUT_100MS_IN_US	USEC_PER_MSEC * 100U
#define _RISAF_TIMEOUT_STEP_10US	10U
#define _RISAF_TIMEOUT_STEP_100US	100U

#define _RISAF_MAX_SUBREGIONS	   2U

#define BITS_PER_BYTES	8

#define _RISAF_ACCESS_CTRL_ARGS		U(2)
#define _RISAF_ACCESS_CTRL_ARG_REGION	U(0)
#define _RISAF_ACCESS_CTRL_ARG_PROTREG	U(1)

enum risaf_key_size {
	RISAF_NO_KEY = 0,
	RISAF_KEY_128BITS = 128,
	RISAF_KEY_256BITS = 256,
	RISAF_MAX_KEY_SZ = 256,
};

struct risaf_region {
	uint32_t id;
	uint32_t cfg;
	uint32_t cid_cfg;
	uint32_t start_addr;
	uint32_t end_addr;
	uint32_t enc_mode;
};

struct risaf_subregion {
	uint32_t id;
	uint32_t cfg;
	uint32_t nest_cfg;
	uint32_t start_addr;
	uint32_t end_addr;
};

struct risaf_dt_region {
	uint32_t st_protreg;
	uint32_t start_addr;
	uint32_t end_addr;
	const struct risaf_dt_region *dt_regions;
	const int ndt_regions;
};

struct stm32_risaf_variant {
	bool has_enc;
	int (*default_encryption_fn)(const struct device *dev, uint8_t *key);
	int (*mce_encryption_fn)(const struct device *dev, uint8_t *key);
	uint32_t max_key_sz;
};

struct stm32_risaf_config {
	uintptr_t base;
	const struct device *clk_dev;
	const clk_subsys_t clk_subsys;
	const struct risaf_dt_region *dt_regions;
	const int ndt_regions;
/*    const struct device *entropy_dev;*/
	const uint32_t st_mce_keysize;
	const struct firewall_spec *firewall_ctrls;
	const int n_firewall_ctrls;
};

struct stm32_risaf_data {
	const struct stm32_risaf_variant *variant;
	uint8_t hw_nregions;
	uint8_t hw_nsubregions;
	uint8_t hw_granularity;
	uint8_t hw_naddr_bits;
};

#define for_each_dt_region(_dt_region_tbl, _dt_region, _n_dt_region, _i)		\
	for (_i = 0, _dt_region = (_dt_region_tbl);					\
	     _i < (_n_dt_region);							\
	     _i++, _dt_region++)

#define find_dt_region(_dt_region_tbl, _dt_region, _n_dt_region, _i, _cond)		\
({											\
	const struct risaf_dt_region *__ret = NULL;					\
											\
	if ((_n_dt_region) && (_dt_region_tbl)) {					\
		for_each_dt_region(_dt_region_tbl, _dt_region, _n_dt_region, _i) {	\
			if (_cond) {							\
				__ret = _dt_region;					\
				break;							\
			}								\
		}									\
	}										\
	__ret;										\
})

static void stm32_risaf_enable_region(const struct device *dev, uint8_t region_id)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uintptr_t base;

	base = drv_cfg->base + _RISAF_REGX_OFFSET(region_id);
	mmio_setbits_32(base + _RISAF_REG_CFGR, _RISAF_REG_CFGR_BREN);

	(void)mmio_read_32(base + _RISAF_REG_CFGR);
}

static void stm32_risaf_disable_region(const struct device *dev, uint8_t region_id)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uintptr_t base;

	/* Associated subregions are automatically disabled */
	base = drv_cfg->base + _RISAF_REGX_OFFSET(region_id);
	mmio_write_32(base + _RISAF_REG_CFGR, 0);

	(void)mmio_read_32(base + _RISAF_REG_CFGR);
}

static void stm32_risaf_write_cfg(const struct device *dev, uint8_t region_id,
				      const struct risaf_region *region)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->base + _RISAF_REGX_OFFSET(region_id);

	mmio_write_32(base + _RISAF_REG_CFGR, 0);
	(void)mmio_read_32(base + _RISAF_REG_CFGR);

	mmio_write_32(base + _RISAF_REG_STARTR, region->start_addr);
	mmio_write_32(base + _RISAF_REG_ENDR, region->end_addr);
	mmio_write_32(base + _RISAF_REG_CIDCFGR, region->cid_cfg);
	mmio_write_32(base + _RISAF_REG_CFGR, region->cfg & ~_RISAF_REG_CFGR_BREN);

	(void)mmio_read_32(base + _RISAF_REG_CFGR);
}

static void stm32_risaf_write_subcfg(const struct device *dev, uint8_t region_id,
					 uint8_t sub_id, const struct risaf_subregion *subregion)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->base + _RISAF_SUBREGX_OFFSET(region_id, sub_id);

	mmio_write_32(base + _RISAF_SUBREG_NESTR, 0);
	(void)mmio_read_32(base + _RISAF_SUBREG_NESTR);
	mmio_write_32(base + _RISAF_SUBREG_CFGR, 0);
	(void)mmio_read_32(base + _RISAF_SUBREG_CFGR);

	mmio_write_32(base + _RISAF_SUBREG_STARTR, subregion->start_addr);
	mmio_write_32(base + _RISAF_SUBREG_ENDR, subregion->end_addr);
	mmio_write_32(base + _RISAF_SUBREG_CFGR, subregion->cfg);
	mmio_write_32(base + _RISAF_SUBREG_NESTR, subregion->nest_cfg);

	(void)mmio_read_32(base + _RISAF_SUBREG_CFGR);
}

static void stm32_risaf_read_cfg(const struct device *dev, uint8_t region_id,
				 struct risaf_region *region, uint32_t ecc_mode)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->base + _RISAF_REGX_OFFSET(region_id);

	region->id = region_id;
	region->start_addr = mmio_read_32(base + _RISAF_REG_STARTR);
	region->end_addr = mmio_read_32(base + _RISAF_REG_ENDR);
	region->cid_cfg = mmio_read_32(base + _RISAF_REG_CIDCFGR);
	region->cfg = mmio_read_32(base + _RISAF_REG_CFGR);
	region->enc_mode = ecc_mode;
}

static void stm32_risaf_read_subcfg(const struct device *dev, uint8_t region_id, uint8_t sub_id,
				    struct risaf_subregion *subregion)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->base + _RISAF_SUBREGX_OFFSET(region_id, sub_id);

	subregion->id = sub_id;
	subregion->start_addr = mmio_read_32(base + _RISAF_SUBREG_STARTR);
	subregion->end_addr = mmio_read_32(base + _RISAF_SUBREG_ENDR);
	subregion->nest_cfg = mmio_read_32(base + _RISAF_SUBREG_NESTR);
	subregion->cfg = mmio_read_32(base + _RISAF_SUBREG_CFGR);
}

static bool stm32_risaf_region_is_enabled(const struct device *dev, uint8_t region_id)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uintptr_t base = drv_cfg->base + _RISAF_REGX_OFFSET(region_id);

	return (mmio_read_32(base + _RISAF_REG_CFGR) & _RISAF_REG_CFGR_BREN) != 0;
}

/* The copy is done in max_region */
static void stm32_risaf_tmp_copy(const struct device *dev, uint8_t region_id)
{
	struct stm32_risaf_data *drv_data = dev_get_data(dev);
	struct risaf_subregion tmp_subregion[_RISAF_MAX_SUBREGIONS];
	struct risaf_region tmp_region;
	int i;

	stm32_risaf_read_cfg(dev, region_id, &tmp_region, 0);
	stm32_risaf_write_cfg(dev, drv_data->hw_nregions, &tmp_region);

	for (i = 0; i < _RISAF_MAX_SUBREGIONS; i++) {
		stm32_risaf_read_subcfg(dev, region_id, i, &tmp_subregion[i]);
		stm32_risaf_write_subcfg(dev, drv_data->hw_nregions, i, &tmp_subregion[i]);
	}

	stm32_risaf_enable_region(dev, drv_data->hw_nregions);
}

static void stm32_risaf_dt_to_region(const struct risaf_dt_region *dt_region,
				     struct risaf_region *region)
{
	region->id = _FLD_GET(DT_RISAF_ID, dt_region->st_protreg);
	region->cfg = _RISAF_GET_REGION_CFG(dt_region->st_protreg);
	region->cid_cfg = _RISAF_GET_REGION_CID_CFG(dt_region->st_protreg);
	region->start_addr = dt_region->start_addr;
	region->end_addr = dt_region->end_addr;
	region->enc_mode = _FLD_GET(DT_RISAF_ENC, dt_region->st_protreg);
}

static void stm32_risaf_dt_to_subregion(const struct risaf_dt_region *dt_region,
					struct risaf_subregion *subregion)
{
	const struct risaf_dt_region *dt_subregion;
	int i;

	for_each_dt_region(dt_region->dt_regions, dt_subregion, dt_region->ndt_regions, i) {
		subregion[i].id = _FLD_GET(DT_RISAF_SUB_ID, dt_subregion->st_protreg);
		subregion[i].cfg = _RISAF_GET_SUBREGION_CFG(dt_subregion->st_protreg);
		subregion[i].nest_cfg = _RISAF_GET_SUBREGION_NEST_CFG(dt_subregion->st_protreg);
		subregion[i].start_addr = dt_subregion->start_addr;
		subregion[i].end_addr = dt_subregion->end_addr;
	}
}

static int stm32_risaf_setup_region_cfg(const struct device *dev,
					struct risaf_region *region,
					struct risaf_subregion *subregion, uint8_t nb_sub)
{
	struct stm32_risaf_data *drv_data = dev_get_data(dev);
	bool tmp_copy;
	int i;

	/*
	 * The last region is reserved like temporary region, to
	 * allow On-the-fly update:
	 * - copy the region to temporary.
	 * - update the region without activate the region
	 * - update the subregion if needed
	 * - activate the region if set
	 * - disable the temporary region
	 */
	if (region->id >= drv_data->hw_nregions)
		return -EINVAL;

	tmp_copy = stm32_risaf_region_is_enabled(dev, region->id);
	if (tmp_copy)
		stm32_risaf_tmp_copy(dev, region->id);

	stm32_risaf_write_cfg(dev, region->id, region);

	for (i = 0; i < nb_sub; i++)
		stm32_risaf_write_subcfg(dev, region->id, subregion[i].id, &subregion[i]);

	/* enable the region at the end of procedure */
	if (region->cfg & _RISAF_REG_CFGR_BREN)
		stm32_risaf_enable_region(dev, region->id);

	if (tmp_copy)
		stm32_risaf_disable_region(dev, drv_data->hw_nregions);

	return 0;
}

static void stm32_risaf_get_hwconfig(const struct device *dev)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	struct stm32_risaf_data *drv_data = dev_get_data(dev);
	uint32_t regval;
	uint8_t hw_generic2;

	regval = io_read32(drv_cfg->base + _RISAF_HWCFGR);

	/* hw_nregions take account the base0, which is not configurable */
	drv_data->hw_nregions = _FLD_GET(_RISAF_HWCFGR_CFG1, regval) - 1;
	/*
	 * hw_nsubregions reflects the total number of subregions A and B.
	 * Here again base0 is included, so decrement the read value.
	 * Convert it to the number of subregions per region.
	 */
	hw_generic2 = _FLD_GET(_RISAF_HWCFGR_CFG2, regval) - 1;
	drv_data->hw_nsubregions = (hw_generic2 * 2) / drv_data->hw_nregions;
	drv_data->hw_granularity = _FLD_GET(_RISAF_HWCFGR_CFG3, regval);
	drv_data->hw_naddr_bits = _FLD_GET(_RISAF_HWCFGR_CFG4, regval);
}

static bool stm32_risaf_region_need_encryption_key(const struct device *dev)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	struct stm32_risaf_data *drv_data = dev_get_data(dev);
	const struct stm32_risaf_variant *variant = drv_data->variant;
	uint32_t status = mmio_read_32(drv_cfg->base + _RISAF_SR);

	if ((!variant->default_encryption_fn) ||
	    ((status & _RISAF_SR_KEYVALID) && (status & _RISAF_SR_KEYRDY) &&
	   !(status & _RISAF_SR_ENCDIS)))
		return false;

	return true;
}

static bool stm32_risaf_region_need_mce_encryption_key(const struct device *dev)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	struct stm32_risaf_data *drv_data = dev_get_data(dev);
	const struct stm32_risaf_variant *variant = drv_data->variant;
	uint32_t status = mmio_read_32(drv_cfg->base + _RISAF_XSR);

	if ((!variant->mce_encryption_fn) ||
	    ((status & _RISAF_XSR_MKVALID) && !(status & _RISAF_SR_ENCDIS)))
		return false;

	return true;
}

static __unused int stm32_risaf_install_encryption_key(const struct device *dev, uint8_t *key)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uint32_t key_size = RISAF_KEY_128BITS;
	uint64_t sr;
	uint32_t i;
	int err;

	if (!stm32_risaf_region_need_encryption_key(dev))
		return 0;

	for (i = 0U; i < key_size / BITS_PER_BYTES; i += sizeof(uint32_t)) {
		uint32_t key_val = 0U;

		memcpy(&key_val, key + i, sizeof(uint32_t));
		mmio_write_32(drv_cfg->base + _RISAF_KEYR + i, key_val);
	}

	err = mmio_read32_poll_timeout(drv_cfg->base + _RISAF_SR,
				       sr,
				       (sr & (_RISAF_SR_KEYVALID | _RISAF_SR_KEYRDY)),
				       _RISAF_TIMEOUT_1MS_IN_US);
	if (err)
		EMSG("[%s] Timeout waiting encryption key expension\n", dev->name);

	return err;
}

static __unused int stm32_risaf_install_mce_encryption_key(const struct device *dev, uint8_t *mkey)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	uint32_t key_size = drv_cfg->st_mce_keysize;
	uint64_t xsr;
	uint32_t i;
	int err;

	if (!stm32_risaf_region_need_mce_encryption_key(dev))
		return 0;

	if (key_size == RISAF_KEY_128BITS)
		mmio_write_32(drv_cfg->base + _RISAF_XCR,
			      _RISAF_XCR_CIPHERSEL_AES128 << _RISAF_XCR_CIPHERSEL_SHIFT);
	else if (key_size == RISAF_KEY_256BITS)
		mmio_write_32(drv_cfg->base + _RISAF_XCR,
			      _RISAF_XCR_CIPHERSEL_AES256 << _RISAF_XCR_CIPHERSEL_SHIFT);
	else
		return -EINVAL;

	for (i = 0U; i < key_size / BITS_PER_BYTES; i += sizeof(uint32_t)) {
		uint32_t key_val = 0U;

		memcpy(&key_val, mkey + i, sizeof(uint32_t));
		mmio_write_32(drv_cfg->base + _RISAF_MKEYR + i, key_val);
	}

	err = mmio_read32_poll_timeout(drv_cfg->base + _RISAF_XSR,
				       xsr,
				       (xsr & _RISAF_XSR_MKVALID),
				       _RISAF_TIMEOUT_100MS_IN_US);

	if (err)
		EMSG("[%s] Timeout waiting mce encryption key expension\n", dev->name);

	return err;
}

static __unused int stm32_risaf_encryption_check(const struct device *dev)
{
	struct stm32_risaf_data *drv_data = dev_get_data(dev);
	bool result = false;

	if (drv_data->variant->default_encryption_fn)
		result |= stm32_risaf_region_need_encryption_key(dev);

	if (drv_data->variant->mce_encryption_fn)
		result |= stm32_risaf_region_need_mce_encryption_key(dev);

	if (result)
		return -EINVAL;

	return 0;
}

/*
 *  @brief get a dt_region which has been defined in initial device tree
 *
 *  @param dev
 *  @param reg_id region id
 *  @param sub_id check if subregion id exist if id is different of UINT32_MAX
 *
 * @return the dt_region ptr or NULL if no entry found.
 */
static const struct risaf_dt_region *stm32_risaf_get_dt_region(const struct device *dev,
							       uint32_t reg_id, uint32_t sub_id)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	const struct risaf_dt_region *dt_region_reg = NULL;
	const struct risaf_dt_region *dt_region_sub = NULL;
	uint32_t i;

	if (!find_dt_region(drv_cfg->dt_regions, dt_region_reg,
			    drv_cfg->ndt_regions, i,
			    (_FLD_GET(DT_RISAF_ID, dt_region_reg->st_protreg) == reg_id)))
		return NULL;

	if (sub_id == UINT32_MAX)
		return dt_region_reg;

	return find_dt_region(dt_region_reg->dt_regions, dt_region_sub,
			      dt_region_reg->ndt_regions, i,
			      (_FLD_GET(DT_RISAF_SUB_ID, dt_region_sub->st_protreg) == sub_id));
}

static int stm32_risaf_firewall_setup(const struct firewall_spec *spec, bool set_conf)
{
	struct risaf_subregion subregion_cfg[_RISAF_MAX_SUBREGIONS];
	uint32_t region, protreg, region_id, sub_id, ecc_mode;
	const struct risaf_dt_region *dt_region;
	struct risaf_region region_cfg;
	bool is_subregion;
	int i;

	if (spec->nargs != _RISAF_ACCESS_CTRL_ARGS)
		return -EINVAL;

	region = spec->args[_RISAF_ACCESS_CTRL_ARG_REGION];
	region_id = _FLD_GET(DT_RISAFREGION_BASE, region);
	is_subregion = !!_FLD_GET(DT_RISAFREGION_SUB, region);
	protreg = spec->args[_RISAF_ACCESS_CTRL_ARG_PROTREG];

	/* check if firewall region has been defined in initial dt */
	sub_id = is_subregion ? _FLD_GET(DT_RISAF_SUB_ID, protreg) : UINT32_MAX;

	dt_region = stm32_risaf_get_dt_region(spec->dev, region_id, sub_id);
	if (!dt_region)
		return -EINVAL;

	/* read all current configuration of regions and subregion */
	ecc_mode = _FLD_GET(DT_RISAF_ENC, dt_region->st_protreg);
	stm32_risaf_read_cfg(spec->dev, region_id, &region_cfg, ecc_mode);

	for (i = 0; i < _RISAF_MAX_SUBREGIONS; i++)
		stm32_risaf_read_subcfg(spec->dev, region_id, i, &subregion_cfg[i]);

	/* release the access rights to dt value or set to firewall request value */
	protreg = set_conf ? protreg : dt_region->st_protreg;
	if (is_subregion) {
		subregion_cfg[sub_id].cfg = _RISAF_GET_SUBREGION_CFG(protreg);
		subregion_cfg[sub_id].nest_cfg = _RISAF_GET_SUBREGION_NEST_CFG(protreg);
	} else {
		region_cfg.cfg = _RISAF_GET_REGION_CFG(protreg);
		region_cfg.cid_cfg = _RISAF_GET_REGION_CID_CFG(protreg);
	}

	/* write the new configuration */
	return stm32_risaf_setup_region_cfg(spec->dev, &region_cfg,
					    subregion_cfg, _RISAF_MAX_SUBREGIONS);
}

static int stm32_risaf_firewall_set_conf(const struct firewall_spec *spec)
{
	return stm32_risaf_firewall_setup(spec, true);
}

static int stm32_risaf_firewall_release_conf(const struct firewall_spec *spec)
{
	return stm32_risaf_firewall_setup(spec, false);
}

static const struct firewall_controller_api __maybe_unused stm32_risaf_firewall_api = {
	.set_conf = stm32_risaf_firewall_set_conf,
	.release_conf = stm32_risaf_firewall_release_conf,
};

static int stm32_risaf_init(const struct device *dev)
{
	const struct stm32_risaf_config *drv_cfg = dev_get_config(dev);
	struct stm32_risaf_data *drv_data = dev_get_data(dev);
	const struct risaf_dt_region *dt_region;
	struct firewall_spec *firewall;
	struct clk *clk;
	int i, err;

	clk = clk_get(drv_cfg->clk_dev, drv_cfg->clk_subsys);
	if (!clk)
		return -ENODEV;

	/* set firewall access right needed to setup risaf ip block */
	for_each_firewall(drv_cfg->firewall_ctrls, firewall, drv_cfg->n_firewall_ctrls, i) {
		err = firewall_set_configuration(firewall);
		if (err != 0) {
			EMSG("[%s] fail to set firewall conf %d\n", dev->name, i);
			goto out_access;
		}
	}

	err = clk_enable(clk);
	if (err)
		goto out_access;

	stm32_risaf_get_hwconfig(dev);

	if (drv_cfg->ndt_regions > drv_data->hw_nregions) {
		err = -EINVAL;
		goto out;
	}

	for_each_dt_region(drv_cfg->dt_regions, dt_region, drv_cfg->ndt_regions, i) {
		if (dt_region->ndt_regions > drv_data->hw_nsubregions) {
			err = -EINVAL;
			goto out;
		}
	}

	for_each_dt_region(drv_cfg->dt_regions, dt_region, drv_cfg->ndt_regions, i) {
		struct risaf_subregion subregion[_RISAF_MAX_SUBREGIONS];
		struct risaf_region region;

		stm32_risaf_dt_to_region(dt_region, &region);
		stm32_risaf_dt_to_subregion(dt_region, subregion);
		err = stm32_risaf_setup_region_cfg(dev, &region, subregion, dt_region->ndt_regions);
		if (err)
			break;
	}

out:
	clk_disable(clk);
	if (err)
		panic();

out_access:
	/* release firewall access right */
	for_each_firewall(drv_cfg->firewall_ctrls, firewall, drv_cfg->n_firewall_ctrls, i) {
		err = firewall_release_configuration(firewall);
		if (err)
			EMSG("[%s] release firewall[%d] err:%d\n", dev->name, i, err);
	}

	return err;
}

#ifdef CONFIG_PM_DEVICE
static int stm32_risaf_pm_action(const struct device *dev,
				 enum pm_device_action action, uint32_t pm_hint)
{
	if (action == PM_DEVICE_ACTION_RESUME && PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return stm32_risaf_init(dev);

	return 0;
}
#endif

static __unused const struct stm32_risaf_variant stm32mp25_variant = {
	.has_enc = false,
	.default_encryption_fn = NULL,
	.mce_encryption_fn = NULL,
	.max_key_sz = RISAF_NO_KEY,
};

#define _RISAF_REGION_NAME(_node)							\
	_CONCAT(DEVICE_DT_NAME_GET(_node), _risaf_dt_regions)

#define _RISAF_REGIONS_GET(_node)							\
	COND_CODE_1(DT_NODE_HAS_PROP(_node, memory_region),				\
		    (_RISAF_REGION_NAME(_node)), (NULL))

#define _RISAF_REGION_NUM(_node)							\
	DT_PROP_LEN_OR(_node, memory_region, 0)

#define _RISAF_ADDR(_mr_node, _mem_region, _root_node)					\
	(_mem_region - DT_PROP_BY_IDX(_root_node, st_mem_map, 1))

#define _RISAF_REG_ADDR(_mr_node, _root_node)						\
	_RISAF_ADDR(_mr_node, DT_REG_ADDR(_mr_node), _root_node)

#define _RISAF_END_ADDR(_mr_node, _root_node)						\
	(_RISAF_ADDR(_mr_node, DT_REG_ADDR(_mr_node), _root_node) +			\
	 DT_REG_SIZE(_mr_node) - 1)

#define _RISAF_PROTREG(_mr_node) DT_PROP_BY_IDX(_mr_node, st_protreg, 0)

#define __RISAF_MR_ELEM(_mr_node, _root_node)						\
	{										\
		.start_addr = _RISAF_REG_ADDR(_mr_node, _root_node),			\
		.end_addr = _RISAF_END_ADDR(_mr_node, _root_node),			\
		.st_protreg = _RISAF_PROTREG(_mr_node),					\
		.dt_regions = _RISAF_REGIONS_GET(_mr_node),				\
		.ndt_regions = _RISAF_REGION_NUM(_mr_node),				\
	}

#define _RISAF_MR_ELEM(_node, _prop, _idx, _root_node)					\
	__RISAF_MR_ELEM(DT_PHANDLE_BY_IDX(_node, _prop, _idx), _root_node)

#define __RISAF_REGIONS_DEFINE(_node, _root_node)					\
	COND_CODE_1(DT_NODE_HAS_PROP(_node, memory_region),				\
	(static __unused const struct risaf_dt_region _RISAF_REGION_NAME(_node)[] = {	\
		DT_FOREACH_PROP_ELEM_SEP_VARGS(_node, memory_region, _RISAF_MR_ELEM,	\
					       (,), _root_node)				\
	 };), ())

#define _RISAF_SUB_REGIONS_DEFINE(_node, _prop, _idx, _root_node)			\
	__RISAF_REGIONS_DEFINE(DT_PHANDLE_BY_IDX(_node, _prop, _idx), _root_node)

#define _RISAF_REGIONS_DEFINE(_node, _root_node)					\
	DT_FOREACH_PROP_ELEM_VARGS(_node, memory_region,				\
				   _RISAF_SUB_REGIONS_DEFINE, _root_node)		\
	__RISAF_REGIONS_DEFINE(_node, _root_node)

#define _INST_RISAF_REGIONS_DEFINE(inst)						\
	_RISAF_REGIONS_DEFINE(DT_DRV_INST(inst), DT_DRV_INST(inst))

#define STM32_RISAF_INIT(n, name, _variant)						\
											\
_INST_RISAF_REGIONS_DEFINE(n)								\
											\
DT_INST_ACCESS_CTRLS_DEFINE(n);								\
											\
static const struct stm32_risaf_config stm32_risaf_cfg_##name####n = {			\
	.base = DT_INST_REG_ADDR(n),							\
	.clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(n)),				\
	.clk_subsys = (clk_subsys_t) DT_INST_CLOCKS_CELL(n, bits),			\
	.dt_regions = _RISAF_REGIONS_GET(DT_DRV_INST(n)),				\
	.ndt_regions = _RISAF_REGION_NUM(DT_DRV_INST(n)),				\
	.firewall_ctrls = DT_INST_ACCESS_CTRLS_GET(n),					\
	.n_firewall_ctrls = DT_INST_ACCESS_CTRLS_NUM(n),				\
	.st_mce_keysize = DT_INST_PROP_OR(n, st_mce_keysize_bits,			\
					  RISAF_KEY_128BITS)				\
};											\
											\
static struct stm32_risaf_data stm32_risaf_data_##name####n = {				\
	.variant = &_variant,								\
};											\
											\
PM_DEVICE_DT_INST_DEFINE(n, stm32_risaf_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n, &stm32_risaf_init,						\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &stm32_risaf_data_##name####n,					\
		      &stm32_risaf_cfg_##name####n,					\
		      CORE, 30,								\
		      &stm32_risaf_firewall_api);

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_RISAF_INIT, DT_DRV_COMPAT, stm32mp25_variant)
