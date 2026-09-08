/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT st_stm32mp25_pwr_intc

#include <cmsis.h>
#include <stdint.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <errno.h>

#include <device.h>
#include <stm32mp2_pwr_regs.h>
#include <irq.h>
#include <dt-bindings/interrupt-controller/st,irq.h>

#define _PWR_NB_WAKEUPPINS			U(6)

#define _PWR_INTC_SPEC_NARGS			U(2)
#define _PWR_INTC_SPEC_ARG_IRQ			U(0)
#define _PWR_INTC_SPEC_ARG_TYPE			U(1)

#define PWR_INTC_SPEC_GET_NARGS(ispec)		((ispec)->nargs)
#define PWR_INTC_SPEC_GET_IRQ(ispec)		((ispec)->args[_PWR_INTC_SPEC_ARG_IRQ])
#define PWR_INTC_SPEC_GET_TYPE(ispec)		((ispec)->args[_PWR_INTC_SPEC_ARG_TYPE])

struct stm32mp2_pwr_intc_config {
	uintptr_t base;
	uint32_t n_wkup;
	const struct irq_spec *int_spec;
};

struct stm32mp2_pwr_intc_data {
	struct irq_handler **irq_hdl_tbl;
};

static void _stm32mp2_pwr_intc_wkup_enable(const struct device *dev, uint32_t irq)
{
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	uint32_t base = dev_cfg->base;

	/* Clear flag before enable to avoid false interrupt */
	io_setbits32(PWR_WKUPCR_X_ADDR(base, irq), _WKUPCR_WKUPC_MASK);
	io_setbits32(PWR_WKUPCR_X_ADDR(base, irq), _WKUPCR_WKUPENCPU2_MASK);
}

static void _stm32mp2_pwr_intc_wkup_disable(const struct device *dev, uint32_t irq)
{
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	uint32_t base = dev_cfg->base;

	io_clrbits32(PWR_WKUPCR_X_ADDR(base, irq), _WKUPCR_WKUPENCPU2_MASK);
}

static int _stm32mp2_pwr_intc_wkup_config(const struct device *dev, uint32_t irq, uint32_t type)
{
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	uint32_t wkupcr_addr = PWR_WKUPCR_X_ADDR(dev_cfg->base, irq);
	uint32_t wkupcr = 0, en;

	en = io_read32(wkupcr_addr);
	en = _FLD_GET(_WKUPCR_WKUPENCPU2, en);

	if (type != IRQ_TYPE_EDGE_RISING && type != IRQ_TYPE_EDGE_FALLING)
		return -ENOTSUP;

	if (type == IRQ_TYPE_EDGE_FALLING)
		wkupcr = _WKUPCR_WKUPP_MASK;

	/*
	 * TODO: set pull up config like gpio config
	 */
	wkupcr |= _FLD_PREP(_WKUPCR_WKUPPUPD, _WKUPCR_WKUPPUPD_PULL_UP);

	if (en)
		_stm32mp2_pwr_intc_wkup_disable(dev, irq);

	io_clrsetbits32(wkupcr_addr, _WKUPCR_WKUPP_MASK | _WKUPCR_WKUPPUPD_MASK, wkupcr);

	if (en)
		_stm32mp2_pwr_intc_wkup_enable(dev, irq);

	return 0;
}

static int stm32mp2_pwr_intc_interrupt_request(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	struct stm32mp2_pwr_intc_data *dev_data = dev_get_data(dev);
	uint32_t irq, type;
	int err;

	if (PWR_INTC_SPEC_GET_NARGS(spec) != _PWR_INTC_SPEC_NARGS)
		return -EINVAL;

	irq = PWR_INTC_SPEC_GET_IRQ(spec);
	if (irq >= dev_cfg->n_wkup)
		return -ENOTSUP;

	type = PWR_INTC_SPEC_GET_TYPE(spec);

	err = _stm32mp2_pwr_intc_wkup_config(dev, irq, type);
	if (err)
		return err;

	spec->irq_hdl->irq = irq;
	dev_data->irq_hdl_tbl[irq] = spec->irq_hdl;

	return 0;
}

static int stm32mp2_pwr_intc_interrupt_enable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	uint32_t irq = spec->irq_hdl->irq;

	if (irq >= dev_cfg->n_wkup)
		return -ENOTSUP;

	_stm32mp2_pwr_intc_wkup_enable(dev, irq);

	return 0;
}

static int stm32mp2_pwr_intc_interrupt_disable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	uint32_t irq = spec->irq_hdl->irq;

	if (irq >= dev_cfg->n_wkup)
		return -ENOTSUP;

	_stm32mp2_pwr_intc_wkup_disable(dev, irq);

	return 0;
}

static const struct interrupt_controller_api __maybe_unused stm32mp2_pwr_interrupt_api = {
	.request = stm32mp2_pwr_intc_interrupt_request,
	.enable = stm32mp2_pwr_intc_interrupt_enable,
	.disable = stm32mp2_pwr_intc_interrupt_disable,
};

static irqreturn_t stm32mp2_pwr_intc_isr(void *data)
{
	const struct device *dev = data;
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	struct stm32mp2_pwr_intc_data *dev_data = dev_get_data(dev);
	irqreturn_t irq_ret = IRQ_NONE;
	uint32_t i;

	for (i = 0; i < dev_cfg->n_wkup; i++) {
		uint32_t wkupcr_addr = PWR_WKUPCR_X_ADDR(dev_cfg->base, i);

		if (io_read32(wkupcr_addr) & _WKUPCR_WKUPF_MASK) {
			struct irq_handler *irq_hdl = dev_data->irq_hdl_tbl[i];

			if (!irq_hdl || !irq_hdl->callback) {
				EMSG("%s: spurious irq: %d\r\n", __func__, i);
				continue;
			}

			irq_hdl->callback(irq_hdl->data);

			/* Ack the interrupt */
			io_setbits32(wkupcr_addr, _WKUPCR_WKUPC_MASK);
			irq_ret = IRQ_HANDLED;
		}
	}

	return irq_ret;
}

static __unused int stm32mp2_pwr_intc_init(const struct device *dev)
{
	const struct stm32mp2_pwr_intc_config *dev_cfg = dev_get_config(dev);
	int err;

	if (!dev_cfg->int_spec)
		return -EINVAL;

	err = interrupt_request(dev_cfg->int_spec, (void *)dev, stm32mp2_pwr_intc_isr, IRQF_NONE);
	if (err) {
		EMSG("%s: interrupt request failed: %d\r\n", dev->name, err);
		return err;
	}

	return 0;
}

#define _PWR_INTC_IRQ_TBL_NAME(inst) \
	_CONCAT(DEVICE_DT_NAME_GET(DT_DRV_INST(inst)), _irq_hdl_tbl)

#define _PWR_INTC_IRQ_HDL_TBL_DEFINE(inst, n_irqs) \
	static struct irq_handler *_PWR_INTC_IRQ_TBL_NAME(inst)[n_irqs];

#define STM32MP2_PWR_INTC(n)							\
										\
DT_INST_IRQS_SPEC_DEFINE(n)							\
_PWR_INTC_IRQ_HDL_TBL_DEFINE(n, _PWR_NB_WAKEUPPINS)				\
										\
static const struct stm32mp2_pwr_intc_config pwr_intc_cfg_##n = {		\
	.base = DT_REG_ADDR(DT_INST_PARENT(n)),					\
	.n_wkup = _PWR_NB_WAKEUPPINS,						\
	.int_spec = DT_INST_IRQS_SPEC_GET(n),					\
};										\
										\
static struct stm32mp2_pwr_intc_data pwr_intc_data_##n = {			\
	.irq_hdl_tbl = _PWR_INTC_IRQ_TBL_NAME(n),				\
};										\
										\
DEVICE_DT_INST_DEFINE(n, &stm32mp2_pwr_intc_init, NULL,				\
		      &pwr_intc_data_##n, &pwr_intc_cfg_##n,			\
		      STM32MP2_PWR_INTC_LVL, STM32MP2_PWR_INTC_PRIO,		\
		      &stm32mp2_pwr_interrupt_api);

DT_INST_FOREACH_STATUS_OKAY(STM32MP2_PWR_INTC)
