/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#define DT_DRV_COMPAT arm_v8m_nvic

#include <stdint.h>

#include <cmsis.h>
#include <device.h>
#include <lib/utils_def.h>
#include <lib/mmio.h>
#include <inttypes.h>
#include <debug.h>
#include <irq.h>

#define _NVIC_INTERNAL_NIRQS			16
#define _NVIC_IRQ_PER_BANK			32

#define _NVIC_SPEC_NARGS			U(2)
#define _NVIC_SPEC_ARG_IRQ			U(0)
#define _NVIC_SPEC_ARG_PRIORITY			U(1)

#define NVIC_SPEC_GET_NARGS(ispec)		((ispec)->nargs)
#define NVIC_SPEC_GET_IRQ(ispec)		((ispec)->args[_NVIC_SPEC_ARG_IRQ])
#define NVIC_SPEC_GET_PRIORITY(ispec)		((ispec)->args[_NVIC_SPEC_ARG_PRIORITY])

struct arm_nvic_config {
	uint32_t prio_mask;
	uint32_t n_irqs;
};

struct arm_nvic_data {
	uint32_t hw_n_irqs;
	struct irq_handler **irq_hdl_tbl;
};

void arm_nvic_isr(void)
{
	const struct device *dev = DEVICE_DT_INST_GET(0);
	struct arm_nvic_data *dev_data = dev_get_data(dev);
	uint32_t ipsr = __get_IPSR();
	struct irq_handler *irq_hdl;
	uint32_t ext_irq_num;

	if (ipsr < _NVIC_INTERNAL_NIRQS) {
		EMSG("%s: internal irq: %u\r\n", __func__, ipsr);
		return;
	}

	ext_irq_num = ipsr - _NVIC_INTERNAL_NIRQS;
	irq_hdl = dev_data->irq_hdl_tbl[ext_irq_num];

	if (!irq_hdl || !irq_hdl->callback) {
		EMSG("%s: spurious irq: %u\r\n", __func__, ext_irq_num);
		return;
	}

	irq_hdl->callback(irq_hdl->data);
}

static int arm_nvic_interrupt_request(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	const struct arm_nvic_config *dev_cfg = dev_get_config(dev);
	struct arm_nvic_data *dev_data = dev_get_data(dev);
	uint32_t irq, priority;

	if (NVIC_SPEC_GET_NARGS(spec) != _NVIC_SPEC_NARGS)
		return -EINVAL;

	irq = NVIC_SPEC_GET_IRQ(spec);
	if (irq >= dev_cfg->n_irqs)
		return -ENOTSUP;

	priority = NVIC_SPEC_GET_PRIORITY(spec);
	if (priority & ~(dev_cfg->prio_mask))
		return -ENOTSUP;

	spec->irq_hdl->irq = irq;
	dev_data->irq_hdl_tbl[irq] = spec->irq_hdl;

	NVIC_SetPriority(irq, priority);

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
	NVIC_ClearTargetState(irq);
#endif

	return 0;
}

static int arm_nvic_interrupt_enable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	const struct arm_nvic_config *dev_cfg = dev_get_config(dev);
	uint32_t irq;

	if (NVIC_SPEC_GET_NARGS(spec) != _NVIC_SPEC_NARGS)
		return -EINVAL;

	irq = NVIC_SPEC_GET_IRQ(spec);
	if (irq >= dev_cfg->n_irqs)
		return -ENOTSUP;

	NVIC_EnableIRQ(irq);
	if (!NVIC_GetEnableIRQ(irq))
		return -EIO;

	return 0;
}

static int arm_nvic_interrupt_disable(const struct irq_spec *spec)
{
	const struct device *dev = IRQ_SPEC_DEV(spec);
	const struct arm_nvic_config *dev_cfg = dev_get_config(dev);
	uint32_t irq;

	if (NVIC_SPEC_GET_NARGS(spec) != _NVIC_SPEC_NARGS)
		return -EINVAL;

	irq = NVIC_SPEC_GET_IRQ(spec);
	if (irq >= dev_cfg->n_irqs)
		return -ENOTSUP;

	NVIC_DisableIRQ(irq);

	return 0;
}

static const struct interrupt_controller_api __maybe_unused arm_nvic_interrupt_api = {
	.request = arm_nvic_interrupt_request,
	.enable = arm_nvic_interrupt_enable,
	.disable = arm_nvic_interrupt_disable,
};

static void arm_nvic_enable_fault_handlers(void)
{
	/* Explicitly set secure fault priority to the highest */
	NVIC_SetPriority(SecureFault_IRQn, 0);

	/* lower priority than SERC */
	NVIC_SetPriority(BusFault_IRQn, 2);

	/* Enables BUS, MEM, USG and Secure faults */
	SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
		| SCB_SHCSR_BUSFAULTENA_Msk
		| SCB_SHCSR_MEMFAULTENA_Msk
		| SCB_SHCSR_SECUREFAULTENA_Msk;
}

static __maybe_unused void arm_nvic_interrupt_target_state(const struct device *dev)
{
	struct arm_nvic_data *dev_data = dev_get_data(dev);
	uint32_t nb_itns = div_round_up(dev_data->hw_n_irqs, _NVIC_IRQ_PER_BANK);

	/* Target every interrupt to NS */
	for (uint32_t i = 0; i < nb_itns; i++)
		NVIC->ITNS[i] = UINT32_MAX;
}

static __maybe_unused int arm_nvic_init(const struct device *dev)
{
	const struct arm_nvic_config *dev_cfg = dev_get_config(dev);
	struct arm_nvic_data *dev_data = dev_get_data(dev);

	/* To obtain the external IRQ number */
	dev_data->hw_n_irqs = _NVIC_IRQ_PER_BANK;
	dev_data->hw_n_irqs *= (_FLD2VAL(SCnSCB_ICTR_INTLINESNUM, SCnSCB->ICTR) + 1);

	if (dev_cfg->n_irqs > dev_data->hw_n_irqs)
		return -EINVAL;

	arm_nvic_enable_fault_handlers();

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
	/* if cmse extension and secure */
	arm_nvic_interrupt_target_state(dev);
#endif

	__enable_irq();

	return 0;
}

#define _NVIC_IRQ_TBL_NAME(inst) \
	_CONCAT(DEVICE_DT_NAME_GET(DT_DRV_INST(inst)), _irq_hdl_tbl)

#define _NVIC_IRQ_HDL_TBL_DEFINE(inst, n_irqs) \
	static struct irq_handler *_NVIC_IRQ_TBL_NAME(inst)[n_irqs];

#define ARM_NVIC_INIT(n)							\
										\
_NVIC_IRQ_HDL_TBL_DEFINE(n, DT_INST_PROP(n, arm_num_irqs))			\
										\
static const struct arm_nvic_config nvic_cfg_##n = {				\
	.prio_mask = BIT(DT_INST_PROP(n, arm_num_irq_priority_bits)) - 1,	\
	.n_irqs = DT_INST_PROP(n, arm_num_irqs),				\
};										\
										\
static struct arm_nvic_data nvic_data_##n = {					\
	.irq_hdl_tbl = _NVIC_IRQ_TBL_NAME(n),					\
};										\
										\
DEVICE_DT_INST_DEFINE(n, &arm_nvic_init, NULL,					\
		      &nvic_data_##n, &nvic_cfg_##n,				\
		      PRE_CORE, 0,						\
		      &arm_nvic_interrupt_api);

DT_INST_FOREACH_STATUS_OKAY(ARM_NVIC_INIT)
