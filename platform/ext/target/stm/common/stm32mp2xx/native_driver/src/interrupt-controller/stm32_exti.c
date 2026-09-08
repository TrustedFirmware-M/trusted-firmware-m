/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp1_exti

#include <stdint.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <errno.h>
#include <cmsis.h>

#include <device.h>
#include <irq.h>
#include <stm32_rif.h>
#include <dt-bindings/interrupt-controller/st,irq.h>

/* EXTI offset register */
#define _EXTI_RTSR(n)				U(0x000 + (n) * 0x20)
#define _EXTI_FTSR(n)				U(0x004 + (n) * 0x20)
#define _EXTI_RPR(n)				U(0x00C + (n) * 0x20)
#define _EXTI_FPR(n)				U(0x010 + (n) * 0x20)
#define _EXTI_SECCFGR				U(0x014)
#define _EXTI_PRIVCFGR				U(0x018)
#define _EXTI_C2IMR(n)				U(0x0C0 + (n) * 0x10)
#define _EXTI_ENCIDCFGR				U(0x180)
#define _EXTI_CMCIDCFGR				U(0x300)
#define _EXTI_TRG(n)				U(0x3EC - (n) * 4) /* HWCFGR2..4 */
#define _EXTI_HWCFGR1				U(0x3F0)

// _CIDCFGR register bitfields
#define _CIDCFGR_CFEN_MASK			BIT(0)
#define _CIDCFGR_CFEN_SHIFT			0
#define _CIDCFGR_SCID_MASK			GENMASK_32(6, 4)
#define _CIDCFGR_SCID_SHIFT			4

/* _HWCFGR1 bit fields */
#define _HWCFGR1_NBEVENTS_MASK			GENMASK_32(7, 0)
#define _HWCFGR1_NBEVENTS_SHIFT			0U
#define _HWCFGR1_NBCPUS_MASK			GENMASK_32(11, 8)
#define _HWCFGR1_NBCPUS_SHIFT			8U
#define _HWCFGR1_CPUEVENT_MASK			GENMASK_32(15, 12)
#define _HWCFGR1_CPUEVENT_SHIFT			12U
#define _HWCFGR1_NBIOPORT_MASK			GENMASK_32(23, 16)
#define _HWCFGR1_NBIOPORT_SHIFT			16U
#define _HWCFGR1_CIDWIDTH_MASK			GENMASK_32(27, 24)
#define _HWCFGR1_CIDWIDTH_SHIFT			24U

/* RIF miscellaneous */
#define _EXTI_SEC_PRIV_X_OFFSET(_id)		(U(0x20) * ((_id) / _PERIPH_IDS_PER_REG))
#define _EXTI_SEC_PRIV_X_SHIFT(_id)		((_id) % _PERIPH_IDS_PER_REG)
#define _EXTI_CID_X_OFFSET(_id)			(U(0x4) * (_id))
#define _EXTI_CMCID_X_OFFSET(_proc)		(U(0x4) * (_proc))

#define _EXTI_RIF_RES				U(85)
#define _EXTI_MAX_CPU				3U
#define _EXTI_BANK_NR				3U
#define _EXTI_LINES_PER_BANK			32U

#define _EXTI_SPEC_NARGS			U(2)
#define _EXTI_SPEC_ARG_IRQ			U(0)
#define _EXTI_SPEC_ARG_TYPE			U(1)

#define EXTI_SPEC_GET_NARGS(ispec)		((ispec)->nargs)
#define EXTI_SPEC_GET_IRQ(ispec)		((ispec)->args[_EXTI_SPEC_ARG_IRQ])
#define EXTI_SPEC_GET_TYPE(ispec)		((ispec)->args[_EXTI_SPEC_ARG_TYPE])

#define MY_CID RIF_CID2

struct stm32_exti_map {
	const struct irq_spec *ispec_parent;
	const struct irq_spec *ispec_client;
};

struct stm32_exti_config {
	uintptr_t base;
	const struct rifprot_controller *rif_ctl;
	uint32_t proc_cid[_EXTI_MAX_CPU];
	uint32_t n_lines;
	const struct irq_spec *int_spec;
};

struct stm32_exti_data {
	uint8_t hw_nbcpus;
	uint8_t hw_nbevents;
	uint32_t event_trg[_EXTI_BANK_NR];
	struct stm32_exti_map *lines_map;
};

/*
 * specific function for:
 *  - no standard offset on priv
 *  - init sequence with processor filtering
 */
static inline bool _context_is_priv(void)
{
	if (__get_IPSR() != 0U)
		return true;

	return ((__get_CONTROL() & CONTROL_nPRIV_Msk) == 0U);
}

static __unused
int stm32_exti_rif_set_conf(const struct rifprot_controller *ctl,
			    struct rifprot_config *cfg)
{
	const struct stm32_exti_data *dev_data = dev_get_data(ctl->dev);
	uintptr_t offset = _EXTI_SEC_PRIV_X_OFFSET(cfg->id);
	uint32_t shift = _EXTI_SEC_PRIV_X_SHIFT(cfg->id);
	int err;

	if (cfg->id > dev_data->hw_nbevents)
		return -EINVAL;

	if (IS_ENABLED(STM32_M33TDCID) && IS_ENABLED(STM32_SEC)) {
		/* disable filtering before write sec and priv cfgr */
		io_clrbits32(ctl->rbase->cid + _EXTI_CID_X_OFFSET(cfg->id), _CIDCFGR_CFEN_MASK);
	} else {
		err = stm32_rifprot_check_access(ctl, cfg->id);
		if (err)
			return err;
	}

	io_clrsetbits32(ctl->rbase->sec + offset, BIT(shift),
			cfg->sec << shift);
	io_clrsetbits32(ctl->rbase->priv + offset, BIT(shift),
			cfg->priv << shift);

	io_write32(ctl->rbase->cid + _EXTI_CID_X_OFFSET(cfg->id), cfg->cid_attr);

	return 0;
}

static __unused
int stm32_exti_rif_tdcid_init(const struct rifprot_controller *ctl)
{
	const struct stm32_exti_config *dev_cfg = dev_get_config(ctl->dev);
	struct stm32_exti_data *dev_data = dev_get_data(ctl->dev);
	uintptr_t cmcidcfgr_base = dev_cfg->base + _EXTI_CMCIDCFGR;
	struct rifprot_config *rcfg_elem;
	int err, i = 0;

	/* disable cmcidcfgr */
	for (i = 0; i < dev_data->hw_nbcpus; i++)
		io_clrbits32(cmcidcfgr_base + _EXTI_CMCID_X_OFFSET(i),
			     _CIDCFGR_CFEN_MASK);

	for_each_rifprot_cfg(ctl->rifprot_cfg, rcfg_elem, ctl->nrifprot, i) {
		err = stm32_rifprot_set_conf(ctl, rcfg_elem);
		if (err) {
			EMSG("%s: rifprot id:%d setup fail\n", ctl->dev->name, rcfg_elem->id);
			return err;
		}
	}

	/* enable and set processor filtering cmcidcfgr */
	for (i = 0; i < dev_data->hw_nbcpus; i++)
		if (dev_cfg->proc_cid[i])
			io_write32(cmcidcfgr_base + _EXTI_CID_X_OFFSET(i),
				   _FLD_PREP(_CIDCFGR_SCID, dev_cfg->proc_cid[i]) |
				   _CIDCFGR_CFEN_MASK);

	return 0;
}

static __unused
int stm32_exti_rif_check_access(const struct rifprot_controller *ctl, uint32_t exti_line)
{
	uintptr_t offset = _EXTI_SEC_PRIV_X_OFFSET(exti_line);
	uint32_t shift = _EXTI_SEC_PRIV_X_SHIFT(exti_line);
	uint32_t cid_cfgr;
	bool sec, priv;

	sec = !!(io_read32(ctl->rbase->sec + offset) & shift);
	priv = !!(io_read32(ctl->rbase->priv + offset) & shift);

	if (IS_ENABLED(STM32_NSEC) && sec)
		return -EPERM;

	if (priv && !_context_is_priv())
		return -EPERM;

	cid_cfgr = io_read32(ctl->rbase->cid + _EXTI_CID_X_OFFSET(exti_line));

	/* filtering not enabled  or mycid */
	if (!_FLD_GET(_CIDCFGR_CFEN, cid_cfgr) ||
	    (_FLD_GET(_CIDCFGR_SCID, cid_cfgr) == MY_CID))
		return 0;

	return -EPERM;
}

static int stm32_exti_get_hwconfig(const struct device *dev)
{
	const struct stm32_exti_config *dev_cfg = dev_get_config(dev);
	struct stm32_exti_data *dev_data = dev_get_data(dev);
	uint32_t i, regval;

	regval = io_read32(dev_cfg->base + _EXTI_HWCFGR1);
	dev_data->hw_nbcpus = _FLD_GET(_HWCFGR1_NBCPUS, regval) + 1;
	dev_data->hw_nbevents = _FLD_GET(_HWCFGR1_NBEVENTS, regval) + 1;

	if (dev_cfg->n_lines > dev_data->hw_nbevents)
		return -EINVAL;

	for (i = 0; i < div_round_up(dev_data->hw_nbevents, _EXTI_LINES_PER_BANK); i++)
		dev_data->event_trg[i] = io_read32(dev_cfg->base + _EXTI_TRG(i));

	return 0;
}

static bool _exti_is_configurable(const struct device *dev, uint32_t exti_line)
{
	struct stm32_exti_data *dev_data = dev_get_data(dev);
	uint8_t bank = exti_line / _EXTI_LINES_PER_BANK;
	uint32_t mask = BIT(exti_line % _EXTI_LINES_PER_BANK);

	return !!(dev_data->event_trg[bank] & mask);
}

static int _exti_set_type(const struct device *dev, uint32_t exti_line, uint32_t type)
{
	const struct stm32_exti_config *dev_cfg = dev_get_config(dev);
	uint8_t bank = exti_line / _EXTI_LINES_PER_BANK;
	uint32_t mask = BIT(exti_line % _EXTI_LINES_PER_BANK);
	uint32_t rtsr = 0, ftsr = 0;

	switch (type) {
	case IRQ_TYPE_EDGE_RISING:
		rtsr |= mask;
		break;
	case IRQ_TYPE_EDGE_FALLING:
		ftsr |= mask;
		break;
	case IRQ_TYPE_EDGE_BOTH:
		rtsr |= mask;
		ftsr |= mask;
		break;
	default:
		return -EINVAL;
	}

	io_clrsetbits32(dev_cfg->base + _EXTI_RTSR(bank), mask, rtsr);
	io_clrsetbits32(dev_cfg->base + _EXTI_FTSR(bank), mask, ftsr);

	return 0;
}

static void _exti_clear(const struct device *dev, uint32_t exti_line)
{
	const struct stm32_exti_config *dev_cfg = dev_get_config(dev);
	uint8_t bank = exti_line / _EXTI_LINES_PER_BANK;
	uint32_t mask = BIT(exti_line % _EXTI_LINES_PER_BANK);

	io_setbits32(dev_cfg->base + _EXTI_RPR(bank), mask);
	io_setbits32(dev_cfg->base + _EXTI_FPR(bank), mask);
}

static void _exti_mask(const struct device *dev, uint32_t exti_line)
{
	const struct stm32_exti_config *dev_cfg = dev_get_config(dev);
	uint8_t bank = exti_line / _EXTI_LINES_PER_BANK;
	uint32_t mask = BIT(exti_line % _EXTI_LINES_PER_BANK);

	io_clrbits32(dev_cfg->base + _EXTI_C2IMR(bank), mask);
}

static void _exti_unmask(const struct device *dev, uint32_t exti_line)
{
	const struct stm32_exti_config *dev_cfg = dev_get_config(dev);
	uint8_t bank = exti_line / _EXTI_LINES_PER_BANK;
	uint32_t mask = BIT(exti_line % _EXTI_LINES_PER_BANK);

	io_setbits32(dev_cfg->base + _EXTI_C2IMR(bank), mask);
}

static irqreturn_t stm32_exti_isr(void *data)
{
	struct stm32_exti_map *line_desc = data;
	struct irq_handler *irq_hdl;
	const struct device *dev;

	if (!line_desc || !line_desc->ispec_client || !line_desc->ispec_client->irq_hdl)
		return IRQ_NONE;

	dev = line_desc->ispec_client->dev;
	irq_hdl = line_desc->ispec_client->irq_hdl;

	if (!irq_hdl->callback) {
		EMSG("%s: spurious irq: %d\r\n", dev->name, irq_hdl->irq);
		return IRQ_NONE;
	}

	irq_hdl->callback(irq_hdl->data);

	if (_exti_is_configurable(dev, irq_hdl->irq))
		_exti_clear(dev, irq_hdl->irq);

	return IRQ_HANDLED;
}

static int stm32_exti_interrupt_request(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	const struct stm32_exti_config *dev_cfg = dev_get_config(dev);
	struct stm32_exti_data *dev_data = dev_get_data(dev);
	struct stm32_exti_map *line_desc;
	uint32_t irq, type;
	int err;

	if (EXTI_SPEC_GET_NARGS(spec) != _EXTI_SPEC_NARGS)
		return -EINVAL;

	irq = EXTI_SPEC_GET_IRQ(spec);
	if (irq > dev_data->hw_nbevents)
		return -ENOTSUP;

	type = EXTI_SPEC_GET_TYPE(spec);

	line_desc = &dev_data->lines_map[irq];
	if (!(line_desc->ispec_parent))
		return -ENOENT;

	err = stm32_rifprot_check_access(dev_cfg->rif_ctl, irq);
	if (err)
		return err;

	err = interrupt_request(line_desc->ispec_parent, (void *)line_desc,
				stm32_exti_isr, IRQF_NO_AUTOEN);
	if (err)
		return err;

	if (_exti_is_configurable(dev, irq)) {
		err = _exti_set_type(dev, irq, type);
		if (err)
			return err;
	}

	line_desc->ispec_client = spec;
	spec->irq_hdl->irq = irq;

	return 0;
}

static int stm32_exti_interrupt_mask(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	uint32_t irq = spec->irq_hdl->irq;

	_exti_mask(dev, irq);

	return 0;
}

static int stm32_exti_interrupt_unmask(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	uint32_t irq = spec->irq_hdl->irq;

	_exti_unmask(dev, irq);

	return 0;
}

static int stm32_exti_interrupt_enable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	struct stm32_exti_data *dev_data = dev_get_data(dev);
	struct stm32_exti_map *line_desc;
	uint32_t irq = spec->irq_hdl->irq;

	line_desc = &dev_data->lines_map[irq];

	if (!line_desc || !line_desc->ispec_parent)
		return -ENOENT;

	_exti_unmask(dev, irq);

	return interrupt_enable(line_desc->ispec_parent);
}

static int stm32_exti_interrupt_disable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	struct stm32_exti_data *dev_data = dev_get_data(dev);
	struct stm32_exti_map *line_desc;
	uint32_t irq = spec->irq_hdl->irq;

	line_desc = &dev_data->lines_map[irq];

	if (!line_desc || !line_desc->ispec_parent)
		return -ENOENT;

	_exti_mask(dev, irq);

	return interrupt_disable(line_desc->ispec_parent);
}

static const struct interrupt_controller_api __maybe_unused stm32_exti_interrupt_api = {
	.request = stm32_exti_interrupt_request,
	.enable = stm32_exti_interrupt_enable,
	.disable = stm32_exti_interrupt_disable,
	.mask = stm32_exti_interrupt_mask,
	.unmask = stm32_exti_interrupt_unmask,
};

static __unused int stm32_exti_init(const struct device *dev)
{
	const struct stm32_exti_config *dev_cfg = dev_get_config(dev);
	struct stm32_exti_data *dev_data = dev_get_data(dev);
	int err;

	if (!dev_cfg)
		return -ENODEV;

	err = stm32_exti_get_hwconfig(dev);
	if (err)
		return err;

	if (dev_cfg->n_lines > dev_data->hw_nbevents)
		return -EINVAL;

	return stm32_rifprot_init(dev_cfg->rif_ctl);
}

#define VALUE_2X(i, _) UTIL_X2(i)

#if (IS_ENABLED(STM32_M33TDCID) && IS_ENABLED(STM32_SEC))
#define _EXTI_RIF_INIT_FUNC		stm32_exti_rif_tdcid_init
#else
#define _EXTI_RIF_INIT_FUNC		NULL
#endif

/*
 * Macro to evaluate st,proccid property
 *
 * transform st,proccid = <PROC1 RIF_CID1>, <PROC2 RIF_CID2>;
 * in proc_cid [] = { [PROC1] = RIF_CID1, [PROC2] = RIF_CID2, }
 */

#define CID_INIT(idx, inst)								\
	COND_CODE_1(DT_INST_PROP_HAS_IDX(inst, st_proccid, idx),			\
		    ([UTIL_DEC(DT_INST_PROP_BY_IDX(inst, st_proccid, idx))] =		\
		     DT_INST_PROP_BY_IDX(inst, st_proccid, UTIL_INC(idx)),),		\
		     ())

#define PROC_CID_INIT(inst)								\
	FOR_EACH_FIXED_ARG(CID_INIT, (), inst,						\
			   LISTIFY(DT_INST_PROP_LEN_OR(inst, st_proccid, 0),		\
				   VALUE_2X, (,)))

/*
 * Macro to create a map table by exti line define in DT
 *
 * struct stm32_exti_map lines_map [] = {
 *   [line_range_idx0_start] = { ispec_parent = <> , ispec_client = <> },
 *   [line_range_idx1_start] = { ispec_parent = <> , ispec_client = <> },
 * };
 */
#define _EXTI_IRQ_NESTED_TBL_NAME(inst)							\
	_CONCAT(DEVICE_DT_NAME_GET(DT_DRV_INST(inst)), _irq_nested_tbl)

#define _NESTED_ELEM(i, node_id, prop, idx)						\
	[DT_PROP_BY_IDX(node_id, line_ranges, UTIL_X2(idx)) + (i)] = {			\
		.ispec_parent = DT_IRQS_SPEC_GET_BY_IDX(node_id, idx),			\
		.ispec_client = NULL,							\
	}

#define _NESTED_ELEM_RANGE(node_id, prop, idx)						\
	LISTIFY(DT_PROP_BY_IDX(node_id, line_ranges, UTIL_INC(UTIL_X2(idx))),		\
		_NESTED_ELEM, (,), node_id, prop, idx)

#define _EXTI_IRQ_NESTED_TBL_DEFINE(inst, n_irqs)					\
static struct stm32_exti_map _EXTI_IRQ_NESTED_TBL_NAME(inst)[n_irqs] = {		\
	DT_INST_FOREACH_PROP_ELEM_SEP(inst, interrupts, _NESTED_ELEM_RANGE, (,))	\
};

#define STM32_EXTI_INIT(n)								\
											\
DT_INST_IRQS_SPEC_DEFINE(n)								\
_EXTI_IRQ_NESTED_TBL_DEFINE(n, DT_INST_PROP(n, num_lines))				\
											\
static __unused const struct rif_base rbase_##n = {					\
	.sec = DT_INST_REG_ADDR(n) + _EXTI_SECCFGR,					\
	.priv = DT_INST_REG_ADDR(n) + _EXTI_PRIVCFGR,					\
	.cid = DT_INST_REG_ADDR(n) + _EXTI_ENCIDCFGR,					\
};											\
											\
static __unused struct rif_ops rops_##n = {						\
	.set_conf = stm32_exti_rif_set_conf,						\
	.init = _EXTI_RIF_INIT_FUNC,							\
	.check_access = stm32_exti_rif_check_access,					\
};											\
											\
DT_INST_RIFPROT_CTRL_DEFINE(n, &rbase_##n, &rops_##n, _EXTI_RIF_RES);			\
											\
static const struct stm32_exti_config exti_cfg_##n = {					\
	.base = DT_INST_REG_ADDR(n),							\
	.int_spec = DT_INST_IRQS_SPEC_GET(n),						\
	.n_lines = DT_INST_PROP(n, num_lines),						\
	.rif_ctl = DT_INST_RIFPROT_CTRL_GET(n),						\
	.proc_cid = {PROC_CID_INIT(n)},							\
};											\
											\
static struct stm32_exti_data exti_data_##n = {						\
	.lines_map = _EXTI_IRQ_NESTED_TBL_NAME(n),					\
};											\
											\
DEVICE_DT_INST_DEFINE(n, &stm32_exti_init, NULL,					\
		      &exti_data_##n, &exti_cfg_##n,					\
		      PRE_CORE, 7, &stm32_exti_interrupt_api);

DT_INST_FOREACH_STATUS_OKAY(STM32_EXTI_INIT)
