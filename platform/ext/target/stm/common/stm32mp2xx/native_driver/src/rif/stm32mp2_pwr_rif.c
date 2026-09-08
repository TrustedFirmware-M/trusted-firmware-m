/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_pwr_rif

#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#include <debug.h>
#include <device.h>
#include <firewall.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <pm/device.h>
#include <pm/pm.h>

#include <stm32_rif.h>
#include <stm32mp2_pwr_regs.h>

#define SEMAPHORE_IS_AVAILABLE(cid_cfgr, my_id)				\
	(_FLD_GET(_WIOCIDCFGR_CFEN, cid_cfgr) &&			\
	 _FLD_GET(_WIOCIDCFGR_SEMEN, cid_cfgr) &&			\
	 ((_FLD_GET(_WIOCIDCFGR_SEMWLC, cid_cfgr)) & BIT(my_id)))

/* RIF miscellaneous */
#define PWR_RIF_RES			U(13)
#define PWR_RIF_FIRST_WIO_ID		U(7)
#define RCID_X_OFFSET(_id)		(U(0x4) * (_id))
#define WIOCID_X_OFFSET(_id)		(U(0x8) * ((_id) - PWR_RIF_FIRST_WIO_ID))
#define WIOSEM_X_OFFSET(_id)		(U(0x8) * ((_id) - PWR_RIF_FIRST_WIO_ID))

#define MY_CID RIF_CID2

struct stm32mp2_pwr_rif_config {
	uintptr_t base;
	const struct rifprot_controller *rif_ctl;
};

/*
 * There are two kinds of local resources in the PWR:
 *  - non-shareable resources (R0 to R6), that can be statically assigned
 *    to only one master.
 *  - shareable wake-up I/O resources (WIO1 to WIO6) that can be statically
 *    assigned to one master, or shared between different masters with
 *    semaphore protection
 */
static __unused
int stm32mp2_pwr_rif_acquire_sem(const struct rifprot_controller *ctl,
				 uint32_t id)
{
	uint32_t semcr;

	if (id < PWR_RIF_FIRST_WIO_ID)
		return 0;

	io_setbits32(ctl->rbase->sem + WIOSEM_X_OFFSET(id), _WIOSEMCR_MUTEX_MASK);

	semcr = io_read32(ctl->rbase->sem + WIOSEM_X_OFFSET(id));
	if (semcr != (_WIOSEMCR_MUTEX_MASK | _FLD_PREP(_WIOSEMCR_SCID, MY_CID)))
		return -EPERM;

	return 0;
}

static __unused
int stm32mp2_pwr_rif_release_sem(const struct rifprot_controller *ctl,
				 uint32_t id)
{
	uint32_t semcr;

	if (id < PWR_RIF_FIRST_WIO_ID)
		return 0;

	semcr = io_read32(ctl->rbase->sem + WIOSEM_X_OFFSET(id));
	/* if no semaphore */
	if (!(semcr & _WIOSEMCR_MUTEX_MASK))
		return 0;

	/* if semaphore taken but not my cid */
	if (semcr != (_WIOSEMCR_MUTEX_MASK | _FLD_PREP(_WIOSEMCR_SCID, MY_CID)))
		return -EPERM;

	io_clrbits32(ctl->rbase->sem + WIOSEM_X_OFFSET(id), _WIOSEMCR_MUTEX_MASK);

	return 0;
}

static __unused
int stm32mp2_pwr_rif_master_set_conf(const struct rifprot_controller *ctl,
				     struct rifprot_config *cfg)
{
	const struct stm32mp2_pwr_rif_config *dev_cfg = dev_get_config(ctl->dev);
	uintptr_t base = dev_cfg->base;
	struct rif_base *rif_regs = (struct rif_base *)ctl->rbase;
	uint32_t cid_offset, shift = cfg->id;
	struct rif_base rbase_r = {
		.sec = base + _PWR_RSECCFGR,
		.priv = base + _PWR_RPRIVCFGR,
		.cid = base + _PWR_RCIDCFGR,
		.sem = 0,
	};

	if (cfg->id < PWR_RIF_FIRST_WIO_ID) {
		rif_regs = &rbase_r;
		cid_offset = RCID_X_OFFSET(cfg->id);
	} else {
		shift = cfg->id - PWR_RIF_FIRST_WIO_ID;
		cid_offset = WIOCID_X_OFFSET(cfg->id);
	}

	/* disable filtering before write sec and priv cfgr */
	io_clrbits32(rif_regs->cid + cid_offset, _RCIDCFGR_CFEN_MASK);

	io_clrsetbits32(rif_regs->sec, BIT(shift), cfg->sec << shift);
	io_clrsetbits32(rif_regs->priv, BIT(shift), cfg->priv << shift);

	io_write32(rif_regs->cid + cid_offset, cfg->cid_attr);

	if (rif_regs->sem && SEMAPHORE_IS_AVAILABLE(cfg->cid_attr, MY_CID))
		return stm32_rifprot_acquire_sem(ctl, cfg->id);

	return 0;
}

static __unused
int stm32mp2_pwr_rif_set_conf(const struct rifprot_controller *ctl,
			      struct rifprot_config *cfg)
{
	uint32_t shift = cfg->id - PWR_RIF_FIRST_WIO_ID;
	bool write_cfg = false;
	uint32_t cidcfgr;
	int err = 0;

	/*
	 * if not TDCID
	 * write SECCFGR0 & PRIVCFGR0 if:
	 *  - shareable wake-up I/O resources (WIO1 to WIO6)
	 *  - SEM_EN=1 && SEMWLC=MY_CID && acquire semaphore
	 *  - SEM_EN=0 && SCID=MY_CID
	 */
	if (cfg->id < PWR_RIF_FIRST_WIO_ID)
		return -EPERM;

	cidcfgr = io_read32(ctl->rbase->cid + WIOCID_X_OFFSET(cfg->id));

	if (ctl->rbase->sem &&
	    SEMAPHORE_IS_AVAILABLE(cidcfgr, MY_CID)) {
		err = stm32_rifprot_acquire_sem(ctl, cfg->id);
		if (!err)
			write_cfg = true;
	} else if (!_FLD_GET(_WIOCIDCFGR_SEMEN, cidcfgr) &&
		   (_FLD_GET(_WIOCIDCFGR_SCID, cidcfgr) == MY_CID)) {
		write_cfg = true;
	}

	if (write_cfg) {
		io_clrsetbits32(ctl->rbase->sec, BIT(shift), cfg->sec << shift);
		io_clrsetbits32(ctl->rbase->priv, BIT(shift), cfg->priv << shift);
	}

	return err;
}

static int stm32mp2_pwr_rif_firewall_set_conf(const struct firewall_spec *spec)
{
	const struct stm32mp2_pwr_rif_config *dev_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_set_conf(dev_cfg->rif_ctl, &rifprot_cfg);
}

static int stm32mp2_pwr_rif_firewall_release_conf(const struct firewall_spec *spec)
{
	const struct stm32mp2_pwr_rif_config *dev_cfg = dev_get_config(spec->dev);
	struct rifprot_config rifprot_cfg = RIFPROT_CFG(spec->args[0]);

	return stm32_rifprot_release_conf(dev_cfg->rif_ctl, rifprot_cfg.id);
}

static const struct firewall_controller_api stm32mp2_pwr_rif_firewall_api = {
	.set_conf = stm32mp2_pwr_rif_firewall_set_conf,
	.release_conf = stm32mp2_pwr_rif_firewall_release_conf,
};

static int stm32mp2_pwr_rif_init(const struct device *dev)
{
	const struct stm32mp2_pwr_rif_config *dev_cfg = dev_get_config(dev);

	return stm32_rifprot_init(dev_cfg->rif_ctl);
}

#ifdef CONFIG_PM_DEVICE
static int stm32mp2_pwr_rif_pm_action(const struct device *dev,
				      enum pm_device_action action,
				      uint32_t pm_hint)
{
	const struct stm32mp2_pwr_rif_config *dev_cfg = dev_get_config(dev);

	if (!PM_HINT_IS_STATE(pm_hint, CONTEXT))
		return 0;

	if (action == PM_DEVICE_ACTION_RESUME)
		if (dev_cfg->rif_ctl)
			return stm32_rifprot_init(dev_cfg->rif_ctl);

	return 0;
}
#endif

#define PWR_RIF_SET_CONF_FUNC							\
	COND_CODE_1(IS_ENABLED(STM32_M33TDCID),					\
		    (stm32mp2_pwr_rif_master_set_conf),				\
		    (stm32mp2_pwr_rif_set_conf))

#define STM32MP2_PWR_RIF_INIT(n)						\
										\
static __unused const struct rif_base rbase_##n = {				\
	.sec = DT_REG_ADDR(DT_INST_PARENT(n)) + _PWR_WIOSECCFGR,		\
	.priv = DT_REG_ADDR(DT_INST_PARENT(n)) + _PWR_WIOPRIVCFGR,		\
	.cid = DT_REG_ADDR(DT_INST_PARENT(n)) + _PWR_WIOCIDCFGR,		\
	.sem = DT_REG_ADDR(DT_INST_PARENT(n)) + _PWR_WIOSEMCR,			\
};										\
										\
static __unused struct rif_ops rops_##n = {					\
	.set_conf = PWR_RIF_SET_CONF_FUNC,					\
	.acquire_sem = stm32mp2_pwr_rif_acquire_sem,				\
	.release_sem = stm32mp2_pwr_rif_release_sem,				\
};										\
										\
DT_INST_RIFPROT_CTRL_DEFINE(n, &rbase_##n, &rops_##n, PWR_RIF_RES);		\
										\
static const struct stm32mp2_pwr_rif_config pwr_rif_cfg_##n = {			\
	.base = DT_REG_ADDR(DT_INST_PARENT(n)),					\
	.rif_ctl = DT_INST_RIFPROT_CTRL_GET(n),					\
};										\
										\
PM_DEVICE_DT_INST_DEFINE(n, stm32mp2_pwr_rif_pm_action, PM_DEVICE_F_NONE);	\
										\
DEVICE_DT_INST_DEFINE(n, &stm32mp2_pwr_rif_init,				\
		      PM_DEVICE_DT_INST_GET(n),					\
		      NULL, &pwr_rif_cfg_##n,					\
		      STM32MP2_PWR_RIF_LVL, STM32MP2_PWR_RIF_PRIO,		\
		      &stm32mp2_pwr_rif_firewall_api);

DT_INST_FOREACH_STATUS_OKAY(STM32MP2_PWR_RIF_INIT)
