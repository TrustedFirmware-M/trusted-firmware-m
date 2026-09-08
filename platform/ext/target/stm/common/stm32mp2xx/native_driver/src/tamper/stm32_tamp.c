/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <clk.h>
#include <debug.h>
#include <device.h>
#include <entropy.h>
#include <errno.h>
#include <gpio.h>
#include <inttypes.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <stdbool.h>
#include <stdint.h>
#include <stm32_rif.h>
#include <stm32_tamp.h>
#include <string.h>
#include <uart_stdout.h>
#include <tfm_platform_system.h>
#include <irq.h>

#include <dt-bindings/tamp/st,stm32-tamp.h>

/* TAMP offset register */
#define _TAMP_CR1			U(0x00)
#define _TAMP_CR2			U(0x04)
#define _TAMP_CR3			U(0x08)
#define _TAMP_FLTCR			U(0x0C)
#define _TAMP_ATCR1			U(0x10)
#define _TAMP_ATSEEDR			U(0x14)
#define _TAMP_ATOR			U(0x18)
#define _TAMP_ATCR2			U(0x1C)
#define _TAMP_SECCFGR			U(0x20)
#define _TAMP_PRIVCFGR			U(0x24)
#define _TAMP_IER			U(0x2C)
#define _TAMP_SR			U(0x30)
#define _TAMP_SCR			U(0x3C)
#define _TAMP_OR			U(0x50)
#define _TAMP_BKPRIFR1			U(0x70)
#define _TAMP_BKPRIFR2			U(0x74)
#define _TAMP_BKPRIFR3			U(0x78)
#define _TAMP_RxCIDCFGR(x)		(U(0x80) + (0x4 * (x)))
#define _TAMP_BKPxR(x)			(U(0x100) + (0x4 * (x)))
#define _TAMP_HWCFGR1			U(0x3F0)

/*_TAMP_CR1 bit fields */
#define _CR1_ETAMP_MASK			GENMASK_32(7, 0)
#define _CR1_ETAMP_SHIFT		0
#define _CR1_ITAMP_MASK			GENMASK_32(31, 16)
#define _CR1_ITAMP_SHIFT		16

/*_TAMP_CR2 bit fields */
#define _CR2_ETAMP_POM_MASK		GENMASK_32(7, 0)
#define _CR2_ETAMP_POM_SHIFT		0
#define _CR2_ETAMP_MSK_MASK		GENMASK_32(18, 16)
#define _CR2_ETAMP_MSK_SHIFT		16
#define _CR2_ETAMP_BKBLOCK_MASK		BIT(22)
#define _CR2_ETAMP_BKBLOCK_SHIFT	22
#define _CR2_ETAMP_BKERASE_MASK		BIT(23)
#define _CR2_ETAMP_BKERASE_SHIFT	23
#define _CR2_ETAMP_TRG_MASK		GENMASK_32(31, 24)
#define _CR2_ETAMP_TRG_SHIFT		24

/* _TAMP_CR3 bit fields */
#define _CR3_ETAMP_POM_MASK		GENMASK_32(7, 0)
#define _CR3_ETAMP_POM_SHIFT		0
#define _CR3_ITAMP_POM_MASK		GENMASK_32(31, 16)
#define _CR3_ITAMP_POM_SHIFT		16

/* _TAMP_FLTCR bit fields */
#define _FLTCR_TAMPFREQ_MASK		GENMASK_32(2, 0)
#define _FLTCR_TAMPFREQ_SHIFT		0
#define _FLTCR_TAMPFLT_MASK		GENMASK_32(4, 3)
#define _FLTCR_TAMPFLT_SHIFT		3
#define _FLTCR_TAMPPRCH_MASK		GENMASK_32(6, 5)
#define _FLTCR_TAMPPRCH_SHIFT		5
#define _FLTCR_TAMPPUDIS_MASK		BIT(7)
#define _FLTCR_TAMPPUDIS_SHIFT		7

/* _TAMP_ATCR1 bit fields */
#define _ATCR1_ETAMP_AM_MASK		GENMASK_32(7, 0)
#define _ATCR1_ETAMP_AM_SHIFT		0
#define _ATCR1_ATCKSEL_MASK		GENMASK_32(19, 16)
#define _ATCR1_ATCKSEL_SHIFT		16
#define _ATCR1_ATPER_MASK		GENMASK_32(26, 24)
#define _ATCR1_ATPER_SHIFT		24
#define _ATCR1_ATOSHARE_MASK		BIT(30)
#define _ATCR1_ATOSHARE_SHIFT		30
#define _ATCR1_FLTEN_MASK		BIT(31)
#define _ATCR1_FLTEN_SHIFT		31

/* _TAMP_ATSEEDR bit fields */
#define _ATSEEDR_SEED_MASK		GENMASK_32(31, 0)
#define _ATSEEDR_SEED_SHIFT		0

/* _TAMP_ATOR bit fields */
#define _ATOR_PRNG_MASK			GENMASK_32(7, 0)
#define _ATOR_PRNG_SHIFT		0
#define _ATOR_SEEDF_MASK		BIT(14)
#define _ATOR_SEEDF_SHIFT		14
#define _ATOR_INITS_MASK		BIT(14)
#define _ATOR_INITS_SHIFT		14

/* _TAMP_ATCR2 bit fields */
#define _ATCR2_ATOSEL_COMMON_MASK	GENMASK_32(31, 8)
#define _ATCR2_ATOSEL_COMMON_SHIFT	8
#define _ATCR2_ATOSEL_BITS		3

#define _ATCR2_ATOSELX_SHIFT(id) \
	(((id) - 1) * _ATCR2_ATOSEL_BITS + _ATCR2_ATOSEL_COMMON_SHIFT)
#define _ATCR2_ATOSELX_MASK(id)	\
	(GENMASK_32(2, 0) << _ATCR2_ATOSELX_SHIFT(id))

#define _ATCR2_ATOSEL_OUT_PREP(id, id_out) \
	((((id_out) - 1) << _ATCR2_ATOSELX_SHIFT(id)) & (_ATCR2_ATOSELX_MASK(id)))

#define _ATCR2_ATOSEL_OUT_GET(id, val) \
	(((val) & _ATCR2_ATOSELX_MASK(id)) >> _ATCR2_ATOSELX_SHIFT(id))

/* _TAMP_SECCFGR bit fields */
#define _SECCFGR_BKPRWSEC_MASK		GENMASK_32(7, 0)
#define _SECCFGR_BKPRWSEC_SHIFT		0
#define _SECCFGR_CNT2SEC_MASK		BIT(14)
#define _SECCFGR_CNT2SEC_SHIFT		14
#define _SECCFGR_CNT1SEC_MASK		BIT(15)
#define _SECCFGR_CNT1SEC_SHIFT		15
#define _SECCFGR_BKPWSEC_MASK		GENMASK_32(23, 16)
#define _SECCFGR_BKPWSEC_SHIFT		16
#define _SECCFGR_BHKLOCK_MASK		BIT(30)
#define _SECCFGR_BHKLOCK_SHIFT		30
#define _SECCFGR_TAMPSEC_MASK		BIT(31)
#define _SECCFGR_TAMPSEC_SHIFT		31

/* _TAMP_PRIVCFGR bit fields */
#define _PRIVCFG_CNT2PRIV_MASK		BIT(14)
#define _PRIVCFG_CNT2PRIV_SHIFT		14
#define _PRIVCFG_CNT1PRIV_MASK		BIT(15)
#define _PRIVCFG_CNT1PRIV_SHIFT		15
#define _PRIVCFG_BKPRWPRIV_MASK		BIT(29)
#define _PRIVCFG_BKPRWPRIV_SHIFT	29
#define _PRIVCFG_BKPWPRIV_MASK		BIT(30)
#define _PRIVCFG_BKPWPRIV_SHIFT		30
#define _PRIVCFG_TAMPPRIV_MASK		BIT(31)
#define _PRIVCFG_TAMPPRIV_SHIFT		31

/* _TAMP_IER bit fields */
#define _IER_ETAMP_IE_MASK		GENMASK_32(7, 0)
#define _IER_ETAMP_IE_SHIFT		0
#define _IER_ITAMP_IE_MASK		GENMASK_32(31, 16)
#define _IER_ITAMP_IE_SHIFT		16

/* _TAMP_SR bit fields */
#define _SR_ETAMP_F_MASK		GENMASK_32(7, 0)
#define _SR_ETAMP_F_SHIFT		0
#define _SR_ITAMP_F_MASK		GENMASK_32(31, 16)
#define _SR_ITAMP_F_SHIFT		16
#define _SR_TAMP_MASK			_SR_ETAMP_F_MASK | _SR_ITAMP_F_MASK

/* _TAMP_SCR bit fields */
#define _SCR_ETAMP_F_MASK		GENMASK_32(7, 0)
#define _SCR_ETAMP_F_SHIFT		0
#define _SCR_ITAMP_F_MASK		GENMASK_32(31, 16)
#define _SCR_ITAMP_F_SHIFT		16

/* _TAMP_OR register bitfields */
#define _OR_IN1RMP_MASK			BIT(0)
#define _OR_IN1RMP_SHIFT		0
#define _OR_IN3RMP_MASK			BIT(1)
#define _OR_IN3RMP_SHIFT		1
#define _OR_IN5RMP_MASK			BIT(2)
#define _OR_IN5RMP_SHIFT		2
#define _OR_BSDIS_MASK			BIT(3)
#define _OR_BSDIS_SHIFT			3

#define _OR_INRMP_STM32MP25_MASK	_OR_IN1RMP_MASK | \
					_OR_IN3RMP_MASK | \
					_OR_IN5RMP_MASK
#define _OR_INRMP_STM32MP25_NB		3

#define _OR_INRMP_STM32MP21_MASK	_OR_IN1RMP_MASK
#define _OR_INRMP_STM32MP21_NB		1

/* _TAMP_BKPRIFR3 bit fields */
#define _BKPRIFR3_BKPWRIF1_MASK		GENMASK_32(7, 0)
#define _BKPRIFR3_BKPWRIF1_SHIFT	0
#define _BKPRIFR3_BKPWRIF2_MASK		GENMASK_32(23, 16)
#define _BKPRIFR3_BKPWRIF2_SHIFT	16

/* CIDCFGR register bitfields */
#define _CIDCFGR_CFEN_MASK		BIT(0)
#define _CIDCFGR_CFEN_SHIFT		0
#define _CIDCFGR_SCID_MASK		GENMASK_32(6, 4)
#define _CIDCFGR_SCID_SHIFT		4

/* _TAMP_HWCFGR1 register bitfields */
#define _HWCFGR1_BKPREG_MASK		GENMASK_32(7, 0)
#define _HWCFGR1_BKPREG_SHIFT		0
#define _HWCFGR1_TAMPER_MASK		GENMASK_32(11, 8)
#define _HWCFGR1_TAMPER_SHIFT		8
#define _HWCFGR1_ACTIVE_MASK		GENMASK_32(15, 12)
#define _HWCFGR1_ACTIVE_SHIFT		12
#define _HWCFGR1_INTERN_MASK		GENMASK_32(31, 16)
#define _HWCFGR1_INTERN_SHIFT		16

/* RIF miscellaneous */
#define _CID_X_OFFSET(_id)		(U(0x4) * (_id))
#define TAMP_RIF_RES			U(3)
#define MAX_DT_BKP_ZONES		7
#define BKP_ZONE_LEN			0
#define MP2_BKP_ZONE_LEN		7

#define MAX_EXT_TAMPER			16

#define SZ_SEED				128
#define SEED_WORDS			(SZ_SEED / (sizeof(uint32_t) * CHAR_BIT))
#define SEED_TIMEOUT_US			1000

#define ITAMP_BIT(id)			BIT((id) - 1)
#define ETAMP_BIT(id)			BIT((id) - 1)

#define MUX_CONF(pin) \
	(_FLD_GET(_TAMP_RMP_F_VAL, (pin)) << _FLD_GET(_TAMP_RMP_F_BIT, (pin)))

enum stm32_tamper_status {
	NOT_INITIALIZED = 0,
	NOT_VALID,
	INITIALIZED,
};

/* tamper data information used by internal and external */
struct stm32_tamper_data {
	uint32_t id;
	uint32_t id_out;
	uint8_t mode;
	uint8_t status;
	bool trig_on;
	const struct gpio_dt_spec gpio_in;
	const struct gpio_dt_spec gpio_out;
};

struct stm32_tamp_variant {
	int (*pre_init_fn)(const struct device *dev);
	int (*init_bkpr_fn)(const struct device *dev);
	uint32_t or_inrmp_mask;
	uint8_t *mux_pin;
	uint8_t n_mux_pin;
};

struct stm32_tamp_config {
	uintptr_t base;
	const struct device *pclk_dev;
	const clk_subsys_t pclk_subsys;
	const struct device *rtc_clk_dev;
	const clk_subsys_t rtc_clk_subsys;
	const struct irq_spec *int_spec;
	const struct rifprot_controller *rif_ctl;
	const uint32_t bkp_zones[MAX_DT_BKP_ZONES];
	const uint32_t passive_precharge;
	const uint32_t passive_nb_sample;
	const uint32_t passive_sample_clk_div;
	const uint32_t active_filter;
	const uint32_t active_clk_div;
};

struct stm32_tamp_data {
	const struct stm32_tamp_variant *variant;
	struct stm32_tamper_data *int_tamper;
	struct stm32_tamper_data *ext_tamper;
	uint8_t n_int_tamper;
	uint8_t n_ext_tamper;
	uint32_t rtc_rate;
	uint8_t hw_nb_bkp_reg;
	uint8_t hw_nb_ext_tamper;
	uint16_t hw_int_tamper_mask;
	bool hw_has_active_tamper;
};

/*
 * specific function to setup a resource:
 *  - no standard id
 */
static __unused int stm32_tamp_rif_set_conf(const struct rifprot_controller *ctl,
					    struct rifprot_config *cfg)
{
	uint32_t seccfgr, privcfgr, sec_mask, priv_mask;

	if (!IS_ENABLED(STM32_M33TDCID))
		return 0;

	/* disable filtering befor write sec and priv cfgr */
	io_clrbits32(ctl->rbase->cid + _CID_X_OFFSET(cfg->id), _CIDCFGR_CFEN_MASK);

	switch (cfg->id) {
	case 0:
		sec_mask = _SECCFGR_TAMPSEC_MASK;
		seccfgr = _FLD_PREP(_SECCFGR_TAMPSEC, cfg->sec);
		priv_mask = _PRIVCFG_TAMPPRIV_MASK;
		privcfgr = _FLD_PREP(_PRIVCFG_TAMPPRIV, cfg->priv);
		break;
	case 1:
		sec_mask = _SECCFGR_CNT1SEC_MASK;
		seccfgr = _FLD_PREP(_SECCFGR_CNT1SEC, cfg->sec);
		priv_mask = _PRIVCFG_CNT1PRIV_MASK | _PRIVCFG_BKPRWPRIV_MASK;
		privcfgr = _FLD_PREP(_PRIVCFG_CNT1PRIV, cfg->priv) |
			_PRIVCFG_BKPRWPRIV_MASK;
		break;
	case 2:
		sec_mask = _SECCFGR_CNT2SEC_MASK;
		seccfgr = _FLD_PREP(_SECCFGR_CNT2SEC, cfg->sec);
		priv_mask = _PRIVCFG_CNT2PRIV_MASK | _PRIVCFG_BKPWPRIV_MASK;
		privcfgr = _FLD_PREP(_PRIVCFG_CNT2PRIV, cfg->priv) |
			_PRIVCFG_BKPWPRIV_MASK;
		break;

	default:
		return -EINVAL;
	}

	io_clrsetbits32(ctl->rbase->sec, sec_mask, seccfgr);
	io_clrsetbits32(ctl->rbase->priv, priv_mask, privcfgr);

	io_write32(ctl->rbase->cid + _CID_X_OFFSET(cfg->id), cfg->cid_attr);

	return 0;
}

static __unused int _stm32mp2_tamp_init_bkpr(const struct device *dev)
{
	const struct stm32_tamp_config *cfg = dev_get_config(dev);
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint32_t bkp_zone1, bkp_zone2;
	uint32_t bkp_zone1_rif1, bkp_zone2_rif1, bkp_zone3_rif1, bkp_zone3_rif0;
	uint8_t bkp_limit;

	bkp_zone1_rif1 = cfg->bkp_zones[0];
	bkp_zone1 = bkp_zone1_rif1 + cfg->bkp_zones[1];
	bkp_zone2_rif1 = bkp_zone1 + cfg->bkp_zones[2];
	bkp_zone2 = bkp_zone2_rif1 + cfg->bkp_zones[3];
	bkp_zone3_rif1 = bkp_zone2 + cfg->bkp_zones[4];
	bkp_zone3_rif0 = bkp_zone3_rif1 + cfg->bkp_zones[5];
	bkp_limit = bkp_zone3_rif0 + cfg->bkp_zones[6];

	if (bkp_limit > dev_data->hw_nb_bkp_reg)
		return -EINVAL;

	io_clrsetbits32(cfg->base + _TAMP_SECCFGR,
			_SECCFGR_BKPRWSEC_MASK | _SECCFGR_BKPWSEC_MASK,
			_FLD_PREP(_SECCFGR_BKPRWSEC, bkp_zone1) |
			_FLD_PREP(_SECCFGR_BKPWSEC, bkp_zone2));

	io_write32(cfg->base + _TAMP_BKPRIFR1, bkp_zone1_rif1);
	io_write32(cfg->base + _TAMP_BKPRIFR2, bkp_zone2_rif1);
	io_write32(cfg->base + _TAMP_BKPRIFR3, bkp_zone3_rif1 |
		   _FLD_PREP(_BKPRIFR3_BKPWRIF2, bkp_zone3_rif0));

	return 0;
}

void stm32_tamp_bkpreg_zone1_rif1(const struct device *dev, bool cpu2_grant_access)
{
	const struct stm32_tamp_config *cfg = dev_get_config(dev);
	uint32_t bkp_zone1_rif1;

	/*
	 * For cpu2_grant_access=true, remove the protection Zone1-RIF1,
	 * with TAMP_BKPRIFR1 = 0 and the first backup registers are in
	 * the protection Zone1-RIF2 accessible by R2CID secure
	 * else restore the default bkpreg protection zone with the value found
	 * in device tree
	 */
	if (cpu2_grant_access)
		bkp_zone1_rif1 = 0;
	else
		bkp_zone1_rif1 = cfg->bkp_zones[0];

	io_write32(cfg->base + _TAMP_BKPRIFR1, bkp_zone1_rif1);
}

int stm32_tamp_bkpreg_write(const struct device *dev, unsigned int reg_id,
			    uint32_t value)
{
	const struct stm32_tamp_config *cfg = dev_get_config(dev);
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint32_t reg_val = 0;

	if (!cfg || !dev_data)
		return -ENODEV;

	if (reg_id > dev_data->hw_nb_bkp_reg)
		return -EINVAL;

	io_write32(cfg->base + _TAMP_BKPxR(reg_id), value);
	reg_val = io_read32(cfg->base + _TAMP_BKPxR(reg_id));
	if (reg_val != value)
		return -EACCES;

	return 0;
}

int stm32_tamp_bkpreg_read(const struct device *dev, unsigned int reg_id,
			   uint32_t *value)
{
	const struct stm32_tamp_config *cfg = dev_get_config(dev);
	struct stm32_tamp_data *dev_data = dev_get_data(dev);

	if (!cfg || !dev_data)
		return -ENODEV;

	if (reg_id > dev_data->hw_nb_bkp_reg)
		return -EINVAL;

	*value = io_read32(cfg->base + _TAMP_BKPxR(reg_id));

	return 0;
}

#if defined(CONFIG_STM32MP25X_REVY)
/*
 * Errata: This errata avoid a corteA stuck after reset.
 * When restarting after M33 TDCID, the ROM code read the bkpr11 and if it's valide
 * jump in stop2 mode.
 * To avoid this, M33 bl2 must clear the bkpr11 register before wakeup the cortexA.
 *
 * Warning:
 * The three TAMP_R0CIDCFGR.CFEN, TAMP_R1CIDCFGR.CFEN, TAMP_R2CIDCFGR.CFEN bits could
 * be set after initialization sequence to protect backup registers with CID filtering.
 * It is not allowed to configure some of the bits to 1 and some others to 0
 * (in this case the protection would behave as if all these bits were 1).
 */
#define CLEAR_PATTERN 0x55

static __unused int _stm32mp25_bkpr11_errata(const struct device *dev)
{
	const struct stm32_tamp_config *cfg = dev_get_config(dev);
	uint32_t r0cid_cfgr, r1cid_cfgr, r2cid_cfgr;
	bool protected;
	int err;

	r0cid_cfgr = io_read32(cfg->base + _TAMP_RxCIDCFGR(0));
	r1cid_cfgr = io_read32(cfg->base + _TAMP_RxCIDCFGR(1));
	r2cid_cfgr = io_read32(cfg->base + _TAMP_RxCIDCFGR(2));
	protected = !!((r0cid_cfgr | r1cid_cfgr | r2cid_cfgr) & _CIDCFGR_CFEN_MASK);

	if (protected) {
		io_write32(cfg->base + _TAMP_RxCIDCFGR(0), r0cid_cfgr & ~_CIDCFGR_CFEN_MASK);
		io_write32(cfg->base + _TAMP_RxCIDCFGR(1), r1cid_cfgr & ~_CIDCFGR_CFEN_MASK);
		io_write32(cfg->base + _TAMP_RxCIDCFGR(2), r2cid_cfgr & ~_CIDCFGR_CFEN_MASK);
	}

	err = stm32_tamp_bkpreg_write(dev, 11, CLEAR_PATTERN);
	if (err)
		EMSG("[%s] errata: issue not fixed\n", dev->name);

	if (protected) {
		io_write32(cfg->base + _TAMP_RxCIDCFGR(0), r0cid_cfgr);
		io_write32(cfg->base + _TAMP_RxCIDCFGR(1), r1cid_cfgr);
		io_write32(cfg->base + _TAMP_RxCIDCFGR(2), r2cid_cfgr);
	}

	return err;
}
#endif /* defined(CONFIG_STM32MP25X_REVY) */

#define TAMP_LOG(str)								\
	do {									\
		stdio_output_string((const char *)str, strlen(str));		\
	} while (0);

static __unused irqreturn_t stm32_tamper_isr(void *data)
{
	const struct device *dev = data;
	const struct stm32_tamp_config *dev_cfg = dev_get_config(dev);
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint32_t tamper_mask, sr;
	char tmp[60];

	sr = io_read32(dev_cfg->base + _TAMP_SR);
	tamper_mask = _FLD_PREP(_SR_ITAMP_F, dev_data->hw_int_tamper_mask);
	tamper_mask |= _FLD_PREP(_SR_ETAMP_F, GENMASK_32(dev_data->hw_nb_ext_tamper - 1, 0));

	if ((sr | tamper_mask) != tamper_mask) {
		snprintf(tmp, sizeof(tmp), "[INF] [%s] spurious detection: 0x%x\n", dev->name, sr);
		TAMP_LOG(tmp);
		panic();
	}

	while (sr) {
		uint32_t shift = __builtin_ctz(sr);
		uint32_t scr = BIT(shift);
		uint32_t t_id = shift + 1;

		t_id -= _FLD_GET(_SR_ITAMP_F, scr) ? _SR_ITAMP_F_SHIFT : 0;

		snprintf(tmp, sizeof(tmp), "[INF] [%s] %s tamper detection (id: %d)\r\n",
			 dev->name,
			 _FLD_GET(_SR_ITAMP_F, scr) ? "internal" : "external", t_id);

		TAMP_LOG(tmp);

		/* clear tamper exception */
		io_write32(dev_cfg->base + _TAMP_SCR, scr);
		sr = io_read32(dev_cfg->base + _TAMP_SR);
	}

	tfm_platform_hal_system_reset();

	return IRQ_HANDLED;
}

static int stm32_tamper_passive_conf(const struct device *dev)
{
	const struct stm32_tamp_config *dev_cfg = dev_get_config(dev);
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint32_t conf = 0;

	if (dev_cfg->passive_precharge)
		conf |= _FLD_PREP(_FLTCR_TAMPPRCH, ilog2(dev_cfg->passive_precharge));
	else
		conf |= _FLTCR_TAMPPUDIS_MASK;

	conf |= _FLD_PREP(_FLTCR_TAMPFLT, ilog2(dev_cfg->passive_nb_sample));

	/* 2^X = rtc_clk_rate / passive_sample_clk_div */
	conf |= _FLD_PREP(_FLTCR_TAMPFREQ,
			  ilog2(dev_data->rtc_rate / dev_cfg->passive_sample_clk_div));

	return conf;
}

static int stm32_tamper_active_conf(const struct device *dev)
{
	const struct stm32_tamp_config *dev_cfg = dev_get_config(dev);
	uint32_t conf;

	conf = _FLD_PREP(_ATCR1_ATCKSEL, ilog2(dev_cfg->active_clk_div));

	if (dev_cfg->active_filter)
		conf |= _ATCR1_FLTEN_MASK;

	return conf;
}

static int stm32_tamper_atper_conf(const struct device *dev, uint32_t nb_output)
{
	uint32_t conf = 0;

	switch (nb_output) {
	case 0 ... 1:
		conf = 0;
		break;
	case 2:
		conf = 1;
		break;
	case 3 ... 4:
		conf = 2;
		break;
	default:
		conf = 3;
		break;
	}

	return conf;
}

static int stm32_tamper_set_seed(const struct device *dev)
{
	const struct stm32_tamp_config *dev_cfg = dev_get_config(dev);
	uint32_t i, ator, err, rnd = 0;

	for (i = 0; i < SEED_WORDS; i++) {
		/* use system entropy */
		err = entropy_get_entropy(NULL, (uint8_t *)&rnd, sizeof(uint32_t));
		if (err)
			return err;

		io_write32(dev_cfg->base + _TAMP_ATSEEDR, rnd);
	}

	return mmio_read32_poll_timeout(dev_cfg->base + _TAMP_ATOR,
					ator, !(ator & _ATOR_SEEDF_MASK), SEED_TIMEOUT_US);
}

static bool stm32_tamper_int_is_valid(const struct device *dev,
				      struct stm32_tamper_data *etamp_data)
{
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint8_t id = etamp_data->id;

	if (!id)
		return false;

	return !!(ITAMP_BIT(id) && dev_data->hw_int_tamper_mask);
}

static bool stm32_tamper_ext_gpio_valid(const struct device *dev, const struct gpio_dt_spec *gpio)
{
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint32_t or_rmp_mask = dev_data->variant->or_inrmp_mask;
	uint8_t rmp_bit = gpio->pin & _TAMP_RMP_F_BIT_MASK;
	uint32_t mux_pin;

	if (gpio->port == NULL)
		return false;

	if (gpio->pin == _TAMP_NOMUX)
		return true;

	/* return false:
	 * - if rmp_bit is not valid
	 * - if mux conf have been defined differently
	 */
	if ((BIT(rmp_bit) | or_rmp_mask) != or_rmp_mask)
		return false;

	mux_pin = dev_data->variant->mux_pin[rmp_bit];
	if (!_FLD_GET(_TAMP_RMP_F_MUX, mux_pin))
		dev_data->variant->mux_pin[rmp_bit] = gpio->pin;
	else if (mux_pin != gpio->pin)
		return false;

	return true;
}

static bool stm32_tamper_ext_is_valid(const struct device *dev,
				      struct stm32_tamper_data *etamp_data)
{
	struct stm32_tamp_data *dev_data = dev_get_data(dev);

	if (!etamp_data->id || (etamp_data->id > dev_data->hw_nb_ext_tamper))
		return false;

	if (!stm32_tamper_ext_gpio_valid(dev, &etamp_data->gpio_in))
		return false;

	if (etamp_data->id_out != UINT32_MAX) {
		if (!etamp_data->id_out || (etamp_data->id_out > dev_data->hw_nb_ext_tamper))
			return false;

		if (!stm32_tamper_ext_gpio_valid(dev, &etamp_data->gpio_out))
			return false;
	}

	return true;
}

static int stm32_tamper_init(const struct device *dev)
{
	const struct stm32_tamp_config *dev_cfg = dev_get_config(dev);
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint32_t i, nb_etamp_active = 0;
	uint32_t atcr1 = 0;
	uint32_t atcr2 = 0;
	uint32_t fltcr = 0;
	uint32_t cr1 = 0;
	uint32_t cr2 = 0;
	uint32_t cr3 = 0;
	uint32_t ier = 0;
	uint32_t or = 0;
	int err;

	fltcr = stm32_tamper_passive_conf(dev);
	atcr1 = stm32_tamper_active_conf(dev);

	/* internal tamper */
	for (i = 0; i < dev_data->n_int_tamper; i++) {
		uint32_t id_in = dev_data->ext_tamper[i].id;

		if (!stm32_tamper_int_is_valid(dev, &dev_data->int_tamper[i])) {
			EMSG("[%s] internal tamper conf not valid (id: %d)\n", dev->name, id_in);
			dev_data->int_tamper[i].status = NOT_VALID;
			continue;
		}

		cr1 |= _FLD_PREP(_CR1_ITAMP, ITAMP_BIT(id_in));
		ier |= _FLD_PREP(_IER_ITAMP_IE, ITAMP_BIT(id_in));

		if (dev_data->int_tamper[i].mode & TAMPER_POTENTIAL_MODE)
			cr3 |= _FLD_PREP(_CR3_ITAMP_POM, ITAMP_BIT(id_in));

		dev_data->int_tamper[i].status = INITIALIZED;
	}

	/*
	 * external tamper
	 * set by default ATOSHARE: Each active tamper input TAMP_INi is compared
	 * with TAMPOUTSELi defined by ATOSELi bits
	 */
	atcr1 |= _ATCR1_ATOSHARE_MASK;

	for (i = 0; i < dev_data->n_ext_tamper; i++) {
		uint32_t id_in = dev_data->ext_tamper[i].id;
		uint32_t id_out = dev_data->ext_tamper[i].id_out;

		if (!stm32_tamper_ext_is_valid(dev, &dev_data->ext_tamper[i])) {
			EMSG("[%s] external tamper conf not valid (id: %d)\n", dev->name, id_in);
			dev_data->ext_tamper[i].status = NOT_VALID;
			continue;
		}

		cr1 |= _FLD_PREP(_CR1_ETAMP, ETAMP_BIT(id_in));

		if (dev_data->ext_tamper[i].trig_on)
			cr2 |= _FLD_PREP(_CR2_ETAMP_TRG, ETAMP_BIT(id_in));

		if (dev_data->ext_tamper[i].mode & TAMPER_POTENTIAL_MODE)
			cr2 |= _FLD_PREP(_CR2_ETAMP_POM, ETAMP_BIT(id_in));

		/* active mode */
		if (id_out != UINT32_MAX) {

			atcr1 |= _FLD_PREP(_ATCR1_ETAMP_AM, ETAMP_BIT(id_in));
			atcr2 |= _ATCR2_ATOSEL_OUT_PREP(id_in, id_out);

			nb_etamp_active++;
		}

		or |= MUX_CONF(dev_data->ext_tamper[i].gpio_in.pin) &
			dev_data->variant->or_inrmp_mask;
		ier |= _FLD_PREP(_IER_ETAMP_IE, ETAMP_BIT(id_in));

		dev_data->ext_tamper[i].status = INITIALIZED;
	}

	/* set atper follow number of ext tamper active (output) */
	atcr1 |= _FLD_PREP(_ATCR1_ATPER, stm32_tamper_atper_conf(dev, nb_etamp_active));

	/*
	 * all the needed tampers write must be enabled in the same write access
	 */
	io_write32(dev_cfg->base + _TAMP_FLTCR, fltcr);

	/* Active configuration applied only if not already done. */
	if (!_FLD_GET(_ATOR_INITS, io_read32(dev_cfg->base + _TAMP_ATOR))) {
		io_write32(dev_cfg->base + _TAMP_ATCR1, atcr1);
		io_write32(dev_cfg->base + _TAMP_ATCR2, atcr2);
	}

	io_write32(dev_cfg->base + _TAMP_CR2, cr2);
	io_write32(dev_cfg->base + _TAMP_CR3, cr3);

	if (nb_etamp_active) {
		err = stm32_tamper_set_seed(dev);
		if (err) {
			EMSG("[%s] seed conf fail: %d\n", dev->name, err);
			return err;
		}
	}

	io_write32(dev_cfg->base + _TAMP_OR, or);

	io_write32(dev_cfg->base + _TAMP_CR1, cr1);

	err = interrupt_request(dev_cfg->int_spec, (void *)dev, stm32_tamper_isr, IRQF_NONE);
	if (err) {
		EMSG("%s: interrupt request failed:%d\r\n", dev->name, err);
		return err;
	}

	/* Enable interrupts. */
	io_write32(dev_cfg->base + _TAMP_IER, ier);

	return 0;
}

static void stm32_tamp_get_hwconfig(const struct device *dev)
{
	const struct stm32_tamp_config *dev_cfg = dev_get_config(dev);
	struct stm32_tamp_data *dev_data = dev_get_data(dev);
	uint32_t regval;

	regval = io_read32(dev_cfg->base + _TAMP_HWCFGR1);

	dev_data->hw_int_tamper_mask = _FLD_GET(_HWCFGR1_INTERN, regval);
	dev_data->hw_has_active_tamper = !!_FLD_GET(_HWCFGR1_ACTIVE, regval);
	dev_data->hw_nb_bkp_reg = _FLD_GET(_HWCFGR1_BKPREG, regval);
	dev_data->hw_nb_ext_tamper = _FLD_GET(_HWCFGR1_TAMPER, regval);

	if (dev_data->hw_nb_ext_tamper == 0)
		dev_data->hw_nb_ext_tamper = MAX_EXT_TAMPER;
}

static __unused int stm32_tamp_init(const struct device *dev)
{
	const struct stm32_tamp_config *cfg = dev_get_config(dev);
	struct stm32_tamp_data *data = dev_get_data(dev);
	struct clk *rtc_clk = NULL, *pclk;
	int err;

	if (!cfg)
		return -ENODEV;

	pclk = clk_get(cfg->pclk_dev, cfg->pclk_subsys);

	if (!pclk)
		return -ENODEV;

	err = clk_enable(pclk);
	if (err)
		return err;

	stm32_tamp_get_hwconfig(dev);

	if (data->variant->pre_init_fn) {
		err = data->variant->pre_init_fn(dev);
		if (err)
			goto out;
	}

	if (data->variant->init_bkpr_fn) {
		err = data->variant->init_bkpr_fn(dev);
		if (err)
			goto out;
	}

	if (cfg->rif_ctl) {
		err = stm32_rifprot_init(cfg->rif_ctl);
		if (err)
			goto out;
	}

	if (IS_ENABLED(STM32_SEC)) {
		/*
		 * rtc clock is needed for tamper, this clock must be initialized
		 * only one time while tfm boot (not available while mcuboot)
		 */
		rtc_clk = clk_get(cfg->rtc_clk_dev, cfg->rtc_clk_subsys);
		if (!rtc_clk) {
			err = -EINVAL;
			goto out;
		}

		err = clk_enable(rtc_clk);
		if (err)
			goto out;

		data->rtc_rate = clk_get_rate(rtc_clk);
		if (!data->rtc_rate)
			goto out;

		err = stm32_tamper_init(dev);
	}

out:
	if (err) {
		EMSG("[%s]critical error: %d\n", dev->name, err);
		if (rtc_clk)
			clk_disable(rtc_clk);

		clk_disable(pclk);
		panic();
	}

	return err;
}

#define _STM32_EXT_TAMPER_ELEM(node_id)								\
{												\
	.status = NOT_INITIALIZED,								\
	.id = DT_PROP_BY_IDX(node_id, st_tamp_id, 0),						\
	.id_out = DT_PROP_BY_IDX_OR(node_id, st_tamp_id, 1, UINT32_MAX),			\
	.mode = DT_PROP(node_id, st_tamp_mode),							\
	.gpio_in = GPIO_DT_SPEC_GET_BY_IDX(node_id, tamper_gpios, 0),				\
	.gpio_out = GPIO_DT_SPEC_GET_BY_IDX_OR(node_id, tamper_gpios, 1, {.port = NULL}),	\
	.trig_on = DT_PROP_OR(node_id, st_trig_on, false),					\
}

#define STM32_EXT_TAMPER_ELEM(node_id)								\
	COND_CODE_1(DT_NODE_HAS_COMPAT(node_id, st_stm32_tamp_external),			\
		    (_STM32_EXT_TAMPER_ELEM(node_id),), ())

#define STM32_EXT_TAMPER_DEFINE(inst)								\
static struct stm32_tamper_data _ext_tamper_data_##inst[] = {					\
	DT_INST_FOREACH_CHILD_STATUS_OKAY(inst, STM32_EXT_TAMPER_ELEM)				\
};

#define VALUE_2X(i, _) UTIL_X2(i)

#define _STM32_INT_TAMP_ELEM(idx, inst)								\
{												\
	.status = NOT_INITIALIZED,								\
	.id = DT_INST_PROP_BY_IDX(inst, st_tamp_internal_tampers, idx),				\
	.mode = DT_INST_PROP_BY_IDX(inst, st_tamp_internal_tampers, UTIL_INC(idx)),		\
}

#define STM32_INT_TAMP_ELEM(idx, inst)								\
	COND_CODE_1(DT_INST_PROP_HAS_IDX(inst, st_tamp_internal_tampers, idx),			\
		    (_STM32_INT_TAMP_ELEM(idx, inst),), ())

#define STM32_INT_TAMPER_DEFINE(inst)								\
static struct stm32_tamper_data _int_tamper_data_##inst[] = {					\
	FOR_EACH_FIXED_ARG(STM32_INT_TAMP_ELEM, (), inst,					\
			   LISTIFY(DT_INST_PROP_LEN_OR(inst, st_tamp_internal_tampers, 0),	\
				   VALUE_2X, (,)))						\
};

#define STM32_TAMP_INIT(n, name, _variant, bkp_zone_len)					\
												\
BUILD_ASSERT(DT_INST_PROP_LEN_OR(n, st_backup_zones, 0) == (bkp_zone_len),			\
	    "Incorrect bkp zone property");							\
												\
STM32_EXT_TAMPER_DEFINE(n)									\
STM32_INT_TAMPER_DEFINE(n)									\
DT_INST_IRQS_SPEC_DEFINE(n)									\
												\
static __unused const struct rif_base _##name##_rbase##n = {					\
	.sec = DT_INST_REG_ADDR(n) + _TAMP_SECCFGR,						\
	.priv = DT_INST_REG_ADDR(n) + _TAMP_PRIVCFGR,						\
	.cid = DT_INST_REG_ADDR(n) + _TAMP_RxCIDCFGR(0),					\
	.sem = 0,										\
};												\
												\
struct __unused rif_ops _##name##_rops##n = {							\
	.set_conf = stm32_tamp_rif_set_conf,							\
};												\
												\
DT_INST_RIFPROT_CTRL_DEFINE(n, &_##name##_rbase##n,						\
			    &_##name##_rops##n, TAMP_RIF_RES);					\
												\
static const struct stm32_tamp_config _##name##_cfg##n = {					\
	.base = DT_INST_REG_ADDR(n),								\
	.pclk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR_BY_NAME(n, pclk)),			\
	.pclk_subsys = (clk_subsys_t)DT_INST_CLOCKS_CELL_BY_NAME(n, pclk, bits),		\
	.rtc_clk_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR_BY_NAME(n, rtc_ck)),			\
	.rtc_clk_subsys = (clk_subsys_t)DT_INST_CLOCKS_CELL_BY_NAME(n, rtc_ck, bits),		\
	.int_spec = DT_INST_IRQS_SPEC_GET(n),							\
	.rif_ctl = DT_INST_RIFPROT_CTRL_GET(n),							\
	.bkp_zones = DT_INST_PROP_OR(n, st_backup_zones, {}),					\
	.passive_precharge = DT_INST_PROP_OR(n, st_tamp_passive_precharge, 0),			\
	.passive_nb_sample = DT_INST_PROP_OR(n, st_tamp_passive_nb_sample, 0),			\
	.passive_sample_clk_div = DT_INST_PROP_OR(n, st_tamp_passive_sample_clk_div, 32768),	\
	.active_filter = DT_INST_PROP_OR(n, st_tamp_active_filter, 0),				\
	.active_clk_div = DT_INST_PROP_OR(n, st_tamp_active_clk_div, 1),			\
};												\
												\
static struct stm32_tamp_data _##name##_data##n = {						\
	.variant = _variant,									\
	.int_tamper = _int_tamper_data_##n,							\
	.ext_tamper = _ext_tamper_data_##n,							\
	.n_int_tamper = ARRAY_SIZE(_int_tamper_data_##n),					\
	.n_ext_tamper = ARRAY_SIZE(_ext_tamper_data_##n),					\
};												\
												\
DEVICE_DT_INST_DEFINE(n, &stm32_tamp_init, NULL,						\
		      &_##name##_data##n, &_##name##_cfg##n,					\
		      CORE, 10, NULL);

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT		st_stm32_tamp

static __maybe_unused const struct stm32_tamp_variant stm32_variant = {};

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_TAMP_INIT, DT_DRV_COMPAT,
				  &stm32_variant, BKP_ZONE_LEN)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT		st_stm32mp21_tamp

static uint8_t stm32mp21_mux_pin[_OR_INRMP_STM32MP21_NB];

static __unused const struct stm32_tamp_variant stm32mp21_variant = {
	.init_bkpr_fn = &_stm32mp2_tamp_init_bkpr,
	.or_inrmp_mask = _OR_INRMP_STM32MP21_MASK,
	.mux_pin = stm32mp21_mux_pin,
	.n_mux_pin = ARRAY_SIZE(stm32mp21_mux_pin),
};

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_TAMP_INIT, DT_DRV_COMPAT,
				  &stm32mp21_variant, MP2_BKP_ZONE_LEN)

#undef DT_DRV_COMPAT
#define DT_DRV_COMPAT		st_stm32mp25_tamp

static uint8_t stm32mp25_mux_pin[_OR_INRMP_STM32MP25_NB];

static __unused const struct stm32_tamp_variant stm32mp25_variant = {
#if defined(STM32_BL2) && defined(CONFIG_STM32MP25X_REVY)
	.pre_init_fn = &_stm32mp25_bkpr11_errata,
#endif
	.init_bkpr_fn = &_stm32mp2_tamp_init_bkpr,
	.or_inrmp_mask = _OR_INRMP_STM32MP25_MASK,
	.mux_pin = stm32mp25_mux_pin,
	.n_mux_pin = ARRAY_SIZE(stm32mp25_mux_pin),
};

DT_INST_FOREACH_STATUS_OKAY_VARGS(STM32_TAMP_INIT, DT_DRV_COMPAT,
				  &stm32mp25_variant, MP2_BKP_ZONE_LEN)
