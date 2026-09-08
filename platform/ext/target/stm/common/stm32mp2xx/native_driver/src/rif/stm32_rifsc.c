/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_rifsc

#include <cmsis.h>
#include <stdint.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <errno.h>

#include <device.h>
#include <pm/device.h>
#include <pm/pm.h>
#include <stm32_rif.h>
#include <stm32_rifsc.h>
#include <firewall.h>

#include <dt-bindings/rif/stm32mp2-rifsc.h>
#include <dt-bindings/rif/stm32mp21-rifsc.h>
#include <dt-bindings/rif/stm32mp25-rifsc.h>

/* RIFSC offset register */
#define _RIFSC_RISC_CR			U(0x00)
#define _RIFSC_SECCFGR0			U(0x10)
#define _RIFSC_PRIVCFGR0		U(0x30)
#define _RIFSC_RCFGLOCKR0		U(0x50)
#define _RIFSC_PER0_CIDCFGR		U(0x100)
#define _RIFSC_PER0_SEMCR		U(0x104)

#define _RIFSC_RIMC_CR			U(0xC00)
#define _RIFSC_RIMC_ATTR0		U(0xC10)

#define _RIFSC_HWCFGR3			U(0xFE8)
#define _RIFSC_HWCFGR2			U(0xFEC)
#define _RIFSC_HWCFGR1			U(0xFF0)
#define _RIFSC_VERR			U(0xFF4)

/* RIFSC_RISC_CR register fields */
#define _RIFSC_RISC_CR_GLOCK		BIT(0)

/* RIFSC_RIMC_CR register fields */
#define _RIFSC_RIMC_CR_GLOCK		BIT(0)

/* RIFSC_RISC_PERX_CIDCFG register fields */
#define _RIFSC_RISC_CIDCFGR_CFEN_MASK		BIT(0)
#define _RIFSC_RISC_CIDCFGR_CFEN_SHIFT		0
#define _RIFSC_RISC_CIDCFGR_SEM_EN_MASK		BIT(1)
#define _RIFSC_RISC_CIDCFGR_SEM_EN_SHIFT	1
#define _RIFSC_RISC_CIDCFGR_SCID_MASK		GENMASK_32(6, 4)
#define _RIFSC_RISC_CIDCFGR_SCID_SHIFT		4
#define _RIFSC_RISC_CIDCFGR_SEMWLC_MASK		GENMASK_32(23, 16)
#define _RIFSC_RISC_CIDCFGR_SEMWLC_SHIFT	16

/* RIFSC_RIMC_ATTRx register fields*/
#define _RIFSC_RIMC_CIDSEL_MASK		BIT(2)
#define _RIFSC_RIMC_CIDSEL_SHIFT	2
#define _RIFSC_RIMC_MCID_MASK		GENMASK_32(6, 4)
#define _RIFSC_RIMC_MCID_SHIFT		4
#define _RIFSC_RIMC_MSEC_MASK		BIT(8)
#define _RIFSC_RIMC_MPRIV_MASK		BIT(9)

/* RIFSC_HWCFGR2 register fields */
#define _RIFSC_HWCFGR2_CFG1_MASK	GENMASK_32(15, 0)
#define _RIFSC_HWCFGR2_CFG1_SHIFT	0
#define _RIFSC_HWCFGR2_CFG2_MASK	GENMASK_32(23, 16)
#define _RIFSC_HWCFGR2_CFG2_SHIFT	16
#define _RIFSC_HWCFGR2_CFG3_MASK	GENMASK_32(31, 24)
#define _RIFSC_HWCFGR2_CFG3_SHIFT	24

/* RIFSC_HWCFGR1 register fields */
#define _RIFSC_HWCFGR1_CFG1_MASK	GENMASK_32(3, 0)
#define _RIFSC_HWCFGR1_CFG1_SHIFT	0
#define _RIFSC_HWCFGR1_CFG2_MASK	GENMASK_32(7, 4)
#define _RIFSC_HWCFGR1_CFG2_SHIFT	4
#define _RIFSC_HWCFGR1_CFG3_MASK	GENMASK_32(11, 8)
#define _RIFSC_HWCFGR1_CFG3_SHIFT	8
#define _RIFSC_HWCFGR1_CFG4_MASK	GENMASK_32(15, 12)
#define _RIFSC_HWCFGR1_CFG4_SHIFT	12
#define _RIFSC_HWCFGR1_CFG5_MASK	GENMASK_32(19, 16)
#define _RIFSC_HWCFGR1_CFG5_SHIFT	16
#define _RIFSC_HWCFGR1_CFG6_MASK	GENMASK_32(23, 20)
#define _RIFSC_HWCFGR1_CFG6_SHIFT	20

/* RIFSC_VERR register fields */
#define _RIFSC_VERR_MINREV_MASK		GENMASK_32(3, 0)
#define _RIFSC_VERR_MINREV_SHIFT	0
#define _RIFSC_VERR_MAJREV_MASK		GENMASK_32(7, 4)
#define _RIFSC_VERR_MAJREV_SHIFT	4

/* Periph id per register */
#define _PERIPH_IDS_PER_REG		32
#define _OFST_PERX_CIDCFGR		U(0x8)
#define _OFST_PERX_PRIVCFGR		U(0x4)
#define _OFST_PERX_SECCFGR		U(0x4)

/* max entries */
#define MAX_RIMU	16
#define MAX_RISUP	128

/* RIF miscellaneous */
/* Compartiment IDs */
#define RIF_CID0			0x0
#define RIF_CID1			0x1
#define RIF_CID2			0x2
#define STM32MP25_RIFSC_ENTRIES		178

#define NO_INHERITANCE			UINT32_MAX

struct rimu_cfg {
	uint32_t id;
	uint32_t attr;
};

struct stm32_rifsc_variant {
	const uint32_t *rimu_inheritance;
	uint32_t n_inheritance;
};

struct stm32_rifsc_config {
	uintptr_t base;
	const struct rifprot_controller *risup_ctl;
	const struct rimu_cfg *rimu;
	const int nrimu;
	const bool errata_ahbrisab;
	const int glock;
};

struct rifsc_driver_data {
	const struct stm32_rifsc_variant *variant;
	uint8_t nb_rimu;
	uint8_t nb_risup;
	uint8_t nb_risal;
	bool rif_en;
	bool sec_en;
	bool priv_en;
};

/* RIMU to RISUP inheritance table, per SoC variant: index = rimu_id, value = risup_id */
static const __unused uint32_t stm32mp25_rimu_risup[] = {
	[0] = NO_INHERITANCE,
	[1] = STM32MP25_RIFSC_SDMMC1_ID,
	[2] = STM32MP25_RIFSC_SDMMC2_ID,
	[3] = STM32MP25_RIFSC_SDMMC3_ID,
	[4] = STM32MP25_RIFSC_USB3DR_ID,
	[5] = STM32MP25_RIFSC_USBH_ID,
	[6] = STM32MP25_RIFSC_ETH1_ID,
	[7] = STM32MP25_RIFSC_ETH2_ID,
	[8] = STM32MP25_RIFSC_PCIE_ID,
	[9] = STM32MP25_RIFSC_GPU_ID,
	[10] = STM32MP25_RIFSC_DCMIPP_ID,
	[11] = NO_INHERITANCE,
	[12] = NO_INHERITANCE,
	[13] = NO_INHERITANCE,
	[14] = STM32MP25_RIFSC_VDEC_ID,
	[15] = STM32MP25_RIFSC_VENC_ID,
};

static const __unused uint32_t stm32mp21_rimu_risup[] = {
	[0] = NO_INHERITANCE,
	[1] = STM32MP21_RIFSC_SDMMC1_ID,
	[2] = STM32MP21_RIFSC_SDMMC2_ID,
	[3] = STM32MP21_RIFSC_SDMMC3_ID,
	[4] = STM32MP21_RIFSC_OTG_HS_ID,
	[5] = STM32MP21_RIFSC_USBH_ID,
	[6] = STM32MP21_RIFSC_ETH1_ID,
	[7] = STM32MP21_RIFSC_ETH2_ID,
	[10] = STM32MP21_RIFSC_DCMIPP_ID,
	[11] = NO_INHERITANCE,
	[12] = NO_INHERITANCE,
};

/*
 * Errata: When CID filtering is enabled on one of RISAB 3/4/5 instances, we
 * forbid the use of CID0 for any initiator on the bus to handle spurious CID0
 * transactions on these RAMs.
 */
static int stm32_rimu_errata_ahbrisab(const struct device *dev,
				      struct rifsc_driver_data *drv_data,
				      const struct rimu_cfg *rimu)
{
	const struct stm32_rifsc_config *dev_cfg = dev_get_config(dev);
	const struct rifprot_config *risup = NULL;
	uint32_t risup_id, risup_cidcfgr, j;

	if (!dev_cfg->errata_ahbrisab)
		return 0;

	if (rimu->id >= drv_data->variant->n_inheritance)
		return -ENOTSUP;

	risup_id = drv_data->variant->rimu_inheritance[rimu->id];

	if (_FLD_GET(RIFSC_RIMC_MODE, rimu->attr) == RIF_CIDSEL_M) {
		/* No inheritance mode for this RIMU */
		if (_FLD_GET(RIFSC_RIMC_MCID, rimu->attr) == RIF_CID0) {
			EMSG("A CID should be set for RIMU %u", rimu->id);
			return -EPERM;
		}
	} else {
		/* Handle RIMU with no inheritance mode */
		if (risup_id == NO_INHERITANCE) {
			EMSG("RIMU%u cannot be set in inheritance mode", rimu->id);
			return -EPERM;
		}

		for (j = 0; j < drv_data->nb_risup; j++) {
			if (risup_id == dev_cfg->risup_ctl->rifprot_cfg[j].id) {
				risup = &dev_cfg->risup_ctl->rifprot_cfg[j];
				break;
			}
		}

		if (!risup)
			return -EINVAL;

		risup_cidcfgr = io_read32(dev_cfg->base + _RIFSC_PER0_CIDCFGR +
					  _OFST_PERX_CIDCFGR * risup->id);

		/*
		 * Errata: When CID filtering is enabled on one of RISAB 3/4/5
		 * instances, we forbid the use of CID0 for any initiator on the
		 * bus to handle spurious CID0 transactions on these RAMs.
		 */
		if (!(risup_cidcfgr & _RIFSC_RISC_CIDCFGR_CFEN_MASK) ||
		    (!(risup_cidcfgr & _RIFSC_RISC_CIDCFGR_SEM_EN_MASK) &&
		     _FLD_GET(_RIFSC_RISC_CIDCFGR_SCID, risup_cidcfgr) == RIF_CID0) ||
		    (risup_cidcfgr & _RIFSC_RISC_CIDCFGR_SEM_EN_MASK &&
		     risup_cidcfgr & BIT(_RIFSC_RISC_CIDCFGR_SEMWLC_SHIFT))) {
			EMSG("RIMU%u in inheritance mode with CID0", rimu->id);
			return -EPERM;
		}
	}

	return 0;
}

static int stm32_rimu_cfg(const struct device *dev, const struct rimu_cfg *rimu)
{
	const struct stm32_rifsc_config *dev_cfg = dev_get_config(dev);
	struct rifsc_driver_data *drv_data = dev_get_data(dev);
	uintptr_t offset;
	int err;

	if (!rimu || rimu->id >= drv_data->nb_rimu)
		return -EINVAL;

	offset =  _RIFSC_RIMC_ATTR0 + (sizeof(uint32_t) * rimu->id);

	err = stm32_rimu_errata_ahbrisab(dev, drv_data, rimu);
	if (err)
		return err;

	if (drv_data->rif_en)
		io_write32(dev_cfg->base + offset, rimu->attr);

	return 0;
}

static int stm32_rimu_setup(const struct device *dev)
{
	const struct stm32_rifsc_config *dev_cfg = dev_get_config(dev);
	struct rifsc_driver_data *drv_data = dev_get_data(dev);
	int i = 0;
	int err = 0;

	for (i = 0; i < dev_cfg->nrimu && i < drv_data->nb_rimu; i++) {
		const struct rimu_cfg *rimu = dev_cfg->rimu + i;

		err = stm32_rimu_cfg(dev, rimu);
		if (err) {
			EMSG("rimu cfg(%d/%d) error\n", i + 1, dev_cfg->nrimu);
			return err;
		}
	}

	return 0;
}

static int stm32_rifsc_glock(const struct device *dev)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(dev);
	const int glock_conf = rifsc_cfg->glock;

	/* Setting global lock on RIMU configuration */
	if (glock_conf & RIFSC_RIMU_GLOCK) {
		io_setbits32(rifsc_cfg->base + _RIFSC_RIMC_CR, _RIFSC_RIMC_CR_GLOCK);

		if (!(io_read32(rifsc_cfg->base + _RIFSC_RIMC_CR) & _RIFSC_RIMC_CR_GLOCK))
			return -EPERM;

	}

	/* Setting global lock on RISUP configuration */
	if (glock_conf & RIFSC_RISUP_GLOCK) {
		io_setbits32(rifsc_cfg->base + _RIFSC_RISC_CR, _RIFSC_RISC_CR_GLOCK);

		if (!(io_read32(rifsc_cfg->base + _RIFSC_RISC_CR) & _RIFSC_RISC_CR_GLOCK))
			return -EPERM;
	}

	return 0;
}

static void stm32_rifsc_set_drvdata(const struct device *dev)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(dev);
	struct rifsc_driver_data *rifsc_drvdata = dev_get_data(dev);
	uint32_t regval = 0;

	regval = io_read32(rifsc_cfg->base + _RIFSC_HWCFGR1);
	rifsc_drvdata->rif_en = _FLD_GET(_RIFSC_HWCFGR1_CFG1, regval) != 0;
	rifsc_drvdata->sec_en = _FLD_GET(_RIFSC_HWCFGR1_CFG2, regval) != 0;
	rifsc_drvdata->priv_en = _FLD_GET(_RIFSC_HWCFGR1_CFG3, regval) != 0;

	regval = io_read32(rifsc_cfg->base + _RIFSC_HWCFGR2);
	rifsc_drvdata->nb_risup = _FLD_GET(_RIFSC_HWCFGR2_CFG1, regval);
	rifsc_drvdata->nb_rimu = _FLD_GET(_RIFSC_HWCFGR2_CFG2, regval);
	rifsc_drvdata->nb_risal = _FLD_GET(_RIFSC_HWCFGR2_CFG3, regval);

	regval = io_read8(rifsc_cfg->base + _RIFSC_VERR);

	DMSG("RIFSC version %"PRIu32".%"PRIu32"\n",
	     _FLD_GET(_RIFSC_VERR_MAJREV, regval),
	     _FLD_GET(_RIFSC_VERR_MINREV, regval));

	DMSG("HW cap: enabled[rif:sec:priv]:[%s:%s:%s] nb[risup|rimu|risal]:[%"PRIu8",%"PRIu8",%"PRIu8"]\n",
	     rifsc_drvdata->rif_en ? "true" : "false",
	     rifsc_drvdata->sec_en ? "true" : "false",
	     rifsc_drvdata->priv_en ? "true" : "false",
	     rifsc_drvdata->nb_risup,
	     rifsc_drvdata->nb_rimu,
	     rifsc_drvdata->nb_risal);
}

static int stm32_rifsc_set_risup_config(const struct rifprot_controller *ctl,
					struct rifprot_config *cfg)
{
	uintptr_t offset = SEC_PRIV_X_OFFSET(cfg->id);
	uint32_t shift = SEC_PRIV_X_SHIFT(cfg->id);
	uint32_t lockr = 0;

	if (ctl->rbase->lock)
		lockr = io_read32(ctl->rbase->lock + offset);

	stm32_rifprot_release_sem(ctl, cfg->id);

	/* Bypass configuration if IP is locked */
	if (!(lockr & BIT(shift))) {
		/* disable filtering before write sec and priv cfgr */
		if (IS_ENABLED(STM32_M33TDCID))
			io_clrbits32(ctl->rbase->cid + CID_SEM_X_OFFSET(cfg->id),
				     _RIFSC_RISC_CIDCFGR_CFEN_MASK);

		io_clrsetbits32(ctl->rbase->sec + offset, BIT(shift), cfg->sec << shift);
		io_clrsetbits32(ctl->rbase->priv + offset, BIT(shift), cfg->priv << shift);

		if (IS_ENABLED(STM32_M33TDCID))
			io_write32(ctl->rbase->cid + CID_SEM_X_OFFSET(cfg->id), cfg->cid_attr);
	}

	if (ctl->rbase->lock)
		io_clrsetbits32(ctl->rbase->lock + offset, BIT(shift),
				cfg->lock << shift);

	return 0;
}

static int stm32_rifsc_firewall_set_conf(const struct firewall_spec *spec)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_set_conf(rifsc_cfg->risup_ctl, &rifprot_cfg);
}

static int stm32_rifsc_firewall_release_conf(const struct firewall_spec *spec)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_release_conf(rifsc_cfg->risup_ctl, rifprot_cfg.id);
}

static int stm32_rifsc_firewall_check_access(const struct firewall_spec *spec)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_check_access(rifsc_cfg->risup_ctl, rifprot_cfg.id);
}

static int stm32_rifsc_firewall_acquire_sem(const struct firewall_spec *spec)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_acquire_sem(rifsc_cfg->risup_ctl, rifprot_cfg.id);
}

static int stm32_rifsc_firewall_release_sem(const struct firewall_spec *spec)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_release_sem(rifsc_cfg->risup_ctl, rifprot_cfg.id);
}

static const struct firewall_controller_api __maybe_unused stm32_rifsc_firewall_api = {
	.set_conf = stm32_rifsc_firewall_set_conf,
	.release_conf = stm32_rifsc_firewall_release_conf,
	.check_access = stm32_rifsc_firewall_check_access,
	.acquire_access = stm32_rifsc_firewall_acquire_sem,
	.release_access = stm32_rifsc_firewall_release_sem,
};

static int __maybe_unused stm32_rifsc_init(const struct device *dev)
{
	const struct stm32_rifsc_config *rifsc_cfg = dev_get_config(dev);
	struct rifsc_driver_data *rifsc_data = dev_get_data(dev);
	int err;

	if (!rifsc_cfg || !rifsc_data)
		return -ENODEV;

	stm32_rifsc_set_drvdata(dev);

	if (rifsc_cfg->risup_ctl->nrifprot >= rifsc_data->nb_risup)
		return -EINVAL;

	err = stm32_rifprot_init(rifsc_cfg->risup_ctl);
	if (err) {
		panic();
		return err;
	}

	err = stm32_rimu_setup(dev);
	if (err) {
		panic();
		return err;
	}

	/* Lock RIMU and RISUP configuration */
	return stm32_rifsc_glock(dev);
}

#ifdef CONFIG_PM_DEVICE
static int stm32_rifsc_pm_action(const struct device *dev,
				 enum pm_device_action action, uint32_t pm_hint)
{
	if (action == PM_DEVICE_ACTION_RESUME && PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return stm32_rifsc_init(dev);

	return 0;
}
#endif

static const __unused struct stm32_rifsc_variant stm32mp21_variant = {
	.rimu_inheritance = stm32mp21_rimu_risup,
	.n_inheritance = ARRAY_SIZE(stm32mp21_rimu_risup),
};

static const __unused struct stm32_rifsc_variant stm32mp25_variant = {
	.rimu_inheritance = stm32mp25_rimu_risup,
	.n_inheritance = ARRAY_SIZE(stm32mp25_rimu_risup),
};

#define STM32_RIMU(_node_id, _prop, _idx)					\
	{									\
		.id = RIFPROT_FLD(RIFSC_RIMC_M_ID, _node_id, _prop, _idx),	\
		.attr = RIFPROT_FLD(RIFSC_RIMC_ATTRx, _node_id, _prop, _idx),	\
	}

#define STM32_RIFSC_INIT(n, name, _variant)						\
											\
static const struct rimu_cfg rimu_cfg_##name####n[] = {					\
	COND_CODE_1(DT_INST_NODE_HAS_PROP(n, st_rimu),					\
		    (DT_INST_FOREACH_PROP_ELEM_SEP(n, st_rimu, STM32_RIMU, (,))),	\
		    ())									\
};											\
											\
static const __unused struct rif_base rbase_##name####n = {				\
	.sec = DT_INST_REG_ADDR(n) + _RIFSC_SECCFGR0,					\
	.priv = DT_INST_REG_ADDR(n) + _RIFSC_PRIVCFGR0,					\
	.cid = DT_INST_REG_ADDR(n) + _RIFSC_PER0_CIDCFGR,				\
	.sem = DT_INST_REG_ADDR(n) + _RIFSC_PER0_SEMCR,					\
	.lock = DT_INST_REG_ADDR(n) + _RIFSC_RCFGLOCKR0,				\
};											\
											\
static __unused struct rif_ops rops_##name####n = {					\
	.set_conf = stm32_rifsc_set_risup_config,					\
};											\
											\
DT_INST_RIFPROT_CTRL_DEFINE(n, &rbase_##name####n, &rops_##name####n, MAX_RISUP);	\
											\
static const struct stm32_rifsc_config stm32_rifsc_cfg_##name####n = {			\
	.base = DT_INST_REG_ADDR(n),							\
	.rimu = rimu_cfg_##name####n,							\
	.nrimu = ARRAY_SIZE(rimu_cfg_##name####n),					\
	.risup_ctl = DT_INST_RIFPROT_CTRL_GET(n),					\
	.errata_ahbrisab = DT_INST_PROP_OR(n, st_errata_ahbrisab, false),		\
	.glock = DT_INST_PROP_OR(n, st_glocked, 0),					\
};											\
											\
static struct rifsc_driver_data stm32_rifsc_data_##name####n = {			\
	.variant = &_variant,								\
};											\
											\
PM_DEVICE_DT_INST_DEFINE(n, stm32_rifsc_pm_action, PM_DEVICE_F_NONE);			\
											\
DEVICE_DT_INST_DEFINE(n, &stm32_rifsc_init,						\
		      PM_DEVICE_DT_INST_GET(n),						\
		      &stm32_rifsc_data_##name####n,					\
		      &stm32_rifsc_cfg_##name####n,					\
		      PRE_CORE, 0,							\
		      &stm32_rifsc_firewall_api);

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp21_rifsc
DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_RIFSC_INIT, DT_DRV_COMPAT, stm32mp21_variant)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT st_stm32mp25_rifsc
DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_RIFSC_INIT, DT_DRV_COMPAT, stm32mp25_variant)
