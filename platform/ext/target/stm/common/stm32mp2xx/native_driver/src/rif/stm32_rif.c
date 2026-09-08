/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <stdint.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <errno.h>

#include <device.h>
#include <stm32_rif.h>

#include <dt-bindings/rif/stm32mp25-rif.h>

#if (!IS_ENABLED(STM32_NSEC))

// CIDCFGR register bitfields
#define _CIDCFGR_CFEN_MASK	BIT(0)
#define _CIDCFGR_CFEN_SHIFT	0
#define _CIDCFGR_SEMEN_MASK	BIT(1)
#define _CIDCFGR_SEMEN_SHIFT	1
#define _CIDCFGR_SCID_MASK	GENMASK_32(6, 4)
#define _CIDCFGR_SCID_SHIFT	4
#define _CIDCFGR_SEMWLC_MASK	GENMASK_32(23, 16)
#define _CIDCFGR_SEMWLC_SHIFT	16

#define SEMAPHORE_IS_AVAILABLE(cid_cfgr, my_id)			\
	(_FLD_GET(_CIDCFGR_CFEN, cid_cfgr) &&			\
	 _FLD_GET(_CIDCFGR_SEMEN, cid_cfgr) &&			\
	 ((_FLD_GET(_CIDCFGR_SEMWLC, cid_cfgr)) & BIT(my_id)))

// SEMCR register bitfields
#define _SEMCR_MUTEX_MASK	BIT(0)
#define _SEMCR_MUTEX_SHIFT	0
#define _SEMCR_SCID_MASK	GENMASK_32(6, 4)
#define _SEMCR_SCID_SHIFT	U(4)

#define MY_CID RIF_CID2

static int _rifprot_semaphore_acquire(const struct rifprot_controller *ctl,
				      uint32_t id)
{
	uint32_t semcr;

	io_setbits32(ctl->rbase->sem + CID_SEM_X_OFFSET(id), _SEMCR_MUTEX_MASK);

	semcr = io_read32(ctl->rbase->sem + CID_SEM_X_OFFSET(id));
	if (semcr != (_SEMCR_MUTEX_MASK | _FLD_PREP(_SEMCR_SCID, MY_CID)))
		return -EPERM;

	return 0;
}

static int _rifprot_semaphore_release(const struct rifprot_controller *ctl,
				      uint32_t id)
{
	uint32_t semcr;

	semcr = io_read32(ctl->rbase->sem + CID_SEM_X_OFFSET(id));
	/* if no semaphore */
	if (!(semcr & _SEMCR_MUTEX_MASK))
		return 0;

	/* if semaphore taken but not my cid */
	if (semcr != (_SEMCR_MUTEX_MASK | _FLD_PREP(_SEMCR_SCID, MY_CID)))
		return -EPERM;

	io_clrbits32(ctl->rbase->sem + CID_SEM_X_OFFSET(id), _SEMCR_MUTEX_MASK);

	return 0;
}

static int _rifprot_release_conf(const struct rifprot_controller *ctl, uint32_t id)
{
	struct rifprot_config *rcfg_elem;
	int i;

	for_each_rifprot_cfg(ctl->rifprot_cfg, rcfg_elem, ctl->nrifprot, i) {
		if (rcfg_elem->id == id)
			return stm32_rifprot_set_conf(ctl, rcfg_elem);
	}

	return -ENOTSUP;
}

/*
 * check only cid filtering access,
 * this part of software is considerate secure and priv.
 */
static int _rifprot_check_access(const struct rifprot_controller *ctl, uint32_t id)
{
	uint32_t cidcfgr, semcr;

	cidcfgr = io_read32(ctl->rbase->cid + CID_SEM_X_OFFSET(id));
	if (ctl->rbase->sem)
		semcr = io_read32(ctl->rbase->sem + CID_SEM_X_OFFSET(id));

	/* filtering on cid disabled */
	if (!_FLD_GET(_CIDCFGR_CFEN, cidcfgr))
		return 0;

	/* semaphore enabled and it's my cid */
	if (ctl->rbase->sem &&
	    _FLD_GET(_CIDCFGR_SEMEN, cidcfgr) &&
	    semcr == (_SEMCR_MUTEX_MASK | _FLD_PREP(_SEMCR_SCID, MY_CID)))
		return 0;

	/* filtering enabled on my cid */
	if (_FLD_GET(_CIDCFGR_SCID, cidcfgr) == MY_CID)
		return 0;

	return -EPERM;
}

#if (IS_ENABLED(STM32_M33TDCID))
static int _rifprot_set_conf(const struct rifprot_controller *ctl,
			     struct rifprot_config *cfg)
{
	uintptr_t offset = SEC_PRIV_X_OFFSET(cfg->id);
	uint32_t shift = SEC_PRIV_X_SHIFT(cfg->id);
	uint32_t lockr = 0;
	bool sem_release = false;
	int err = 0;

	if (ctl->rbase->lock)
		lockr = io_read32(ctl->rbase->lock + offset);

	stm32_rifprot_release_sem(ctl, cfg->id);

	/* Bypass configuration if IP is locked */
	if (!(lockr & BIT(shift))) {
		/* disable filtering before write sec and priv cfgr */
		io_clrbits32(ctl->rbase->cid + CID_SEM_X_OFFSET(cfg->id), _CIDCFGR_CFEN_MASK);

		io_clrsetbits32(ctl->rbase->sec + offset, BIT(shift), cfg->sec << shift);
		io_clrsetbits32(ctl->rbase->priv + offset, BIT(shift), cfg->priv << shift);

		io_write32(ctl->rbase->cid + CID_SEM_X_OFFSET(cfg->id), cfg->cid_attr);
	}

	if (ctl->rbase->sem &&
	    SEMAPHORE_IS_AVAILABLE(cfg->cid_attr, MY_CID)) {
		err = stm32_rifprot_acquire_sem(ctl, cfg->id);
		if (err)
			return err;
		sem_release = true;
	}

	if (ctl->rbase->lock)
		io_clrsetbits32(ctl->rbase->lock + offset, BIT(shift),
				cfg->lock << shift);

	/* release semaphore if shared resource/not reserved for my CID */
	if (sem_release &&
	    ((_FLD_GET(_CIDCFGR_SEMWLC, cfg->cid_attr)) != BIT(MY_CID))) {
		err = stm32_rifprot_release_sem(ctl, cfg->id);
	}

	return 0;
}
#else

static int _rifprot_set_conf(const struct rifprot_controller *ctl,
			     struct rifprot_config *cfg)
{
	uintptr_t offset = SEC_PRIV_X_OFFSET(cfg->id);
	uint32_t shift = SEC_PRIV_X_SHIFT(cfg->id);
	bool write_cfg = false;
	bool sem_release = false;
	uint32_t cidcfgr;
	int err = 0;

	/*
	 * if not TDCID
	 * write SECCFGR0 & PRIVCFGR0 if:
	 *  - SEM_EN=1 && SEMWLC=MY_CID && acquire semaphore
	 *  - SEM_EN=0 && SCID=MY_CID
	 */

	cidcfgr = io_read32(ctl->rbase->cid + CID_SEM_X_OFFSET(cfg->id));

	if (ctl->rbase->sem &&
	    SEMAPHORE_IS_AVAILABLE(cidcfgr, MY_CID)) {
		err = stm32_rifprot_acquire_sem(ctl, cfg->id);
		if (!err) {
			write_cfg = true;
			sem_release = true;
		}
	} else if (!_FLD_GET(_CIDCFGR_SEMEN, cidcfgr) &&
		   (_FLD_GET(_CIDCFGR_SCID, cidcfgr) == MY_CID)) {
		write_cfg = true;
	}

	if (write_cfg) {
		io_clrsetbits32(ctl->rbase->sec + offset, BIT(shift),
				cfg->sec << shift);
		io_clrsetbits32(ctl->rbase->priv + offset, BIT(shift),
				cfg->priv << shift);
		if (ctl->rbase->lock)
			io_clrsetbits32(ctl->rbase->lock + offset, BIT(shift),
					cfg->lock << shift);
	}

	/* release semaphore if shared resource/not reserved for my CID */
	if (sem_release &&
	    ((_FLD_GET(_CIDCFGR_SEMWLC, cidcfgr)) != BIT(MY_CID))) {
		err = stm32_rifprot_release_sem(ctl, cfg->id);
	}

	return err;
}
#endif

int stm32_rifprot_acquire_sem(const struct rifprot_controller *ctl, uint32_t id)
{
	if (!ctl)
		return -ENODEV;

	if (id >= ctl->nperipherals)
		return -EINVAL;

	if (ctl->ops && ctl->ops->acquire_sem)
		return ctl->ops->acquire_sem(ctl, id);

	return _rifprot_semaphore_acquire(ctl, id);
}

int stm32_rifprot_release_sem(const struct rifprot_controller *ctl, uint32_t id)
{
	if (!ctl)
		return -ENODEV;

	if (id >= ctl->nperipherals)
		return -EINVAL;

	if (ctl->ops && ctl->ops->release_sem)
		return ctl->ops->release_sem(ctl, id);

	return _rifprot_semaphore_release(ctl, id);
}

int stm32_rifprot_check_access(const struct rifprot_controller *ctl, uint32_t id)
{
	if (!ctl)
		return -ENODEV;

	if (id >= ctl->nperipherals)
		return -EINVAL;

	if (ctl->ops && ctl->ops->check_access)
		return ctl->ops->check_access(ctl, id);

	return _rifprot_check_access(ctl, id);
}

int stm32_rifprot_release_conf(const struct rifprot_controller *ctl, uint32_t id)
{
	if (!ctl)
		return -ENODEV;

	if (id >= ctl->nperipherals)
		return -EINVAL;

	if (ctl->ops && ctl->ops->release_conf)
		return ctl->ops->release_conf(ctl, id);

	return _rifprot_release_conf(ctl, id);
}

int stm32_rifprot_set_conf(const struct rifprot_controller *ctl,
			   struct rifprot_config *cfg)
{
	if (!ctl || !cfg)
		return -ENODEV;

	if (cfg->id >= ctl->nperipherals)
		return -EINVAL;

	if (ctl->ops && ctl->ops->set_conf)
		return ctl->ops->set_conf(ctl, cfg);

	return _rifprot_set_conf(ctl, cfg);
}

static int _rifprot_init(const struct rifprot_controller *ctl)
{
	struct rifprot_config *rcfg_elem;
	int err, i = 0;

	for_each_rifprot_cfg(ctl->rifprot_cfg, rcfg_elem, ctl->nrifprot, i) {
		err = stm32_rifprot_set_conf(ctl, rcfg_elem);
		if (err) {
			EMSG("rifprot id:%d setup fail\n", rcfg_elem->id);
			return err;
		}
	}

	return 0;
}

int stm32_rifprot_init(const struct rifprot_controller *ctl)
{
	if (!ctl)
		return 0;

	if (!ctl->dev)
		return -ENODEV;

	if (ctl->ops && ctl->ops->init)
		return ctl->ops->init(ctl);

	return _rifprot_init(ctl);
}
#endif
