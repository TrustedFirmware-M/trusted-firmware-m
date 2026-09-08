/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef INCLUDE_IRQ_H_
#define INCLUDE_IRQ_H_

#include <errno.h>
#include <stdint.h>
#include <lib/utils_def.h>

#include <device.h>

enum irqreturn {
	IRQ_NONE,
	IRQ_HANDLED,
};

typedef enum irqreturn irqreturn_t;

/*
 * IRQ flags used only for interrupt controller
 *
 * IRQF_NO_AUTOEN	Don't enable IRQ automatically when users request it.
 *			Users will enable it explicitly by interrupt_enable().
 */
#define IRQF_NONE		0x00000000
#define IRQF_NO_AUTOEN		0x00000001

typedef irqreturn_t (*irq_handler_t)(void *data);

/**
 * struct irq_handler - Irq handler reference.
 *
 * @handler:	Irq handler function.
 * @data:	Private data pass to irq handler.
 * @irq:	Irq number.
 */
struct irq_handler {
	irq_handler_t callback;
	uint32_t flags;
	void *data;
	uint32_t irq;
};

/**
 * struct irq_spec - Specification on interrupt request reference.
 *
 * @dev:	Reference on an interrupt controller.
 * @handler:	Handler structure.
 * @args:	Such data pointed is opaque and relevant only to
 *		the interrupt controller driver instance being used.
 * @nargs:	Number of arguments.
 */
struct irq_spec {
	const struct device *dev;
	struct irq_handler *irq_hdl;
	uint32_t nargs;
	const uint32_t *args;
};

#define IRQ_SPEC_DEV(spec)	((spec)->dev)

typedef int (*interrupt_controller_req_t)(const struct irq_spec *spec);
typedef int (*interrupt_controller_enable_t)(const struct irq_spec *spec);
typedef int (*interrupt_controller_disable_t)(const struct irq_spec *spec);
typedef int (*interrupt_controller_mask_t)(const struct irq_spec *spec);
typedef int (*interrupt_controller_unmask_t)(const struct irq_spec *spec);

/**
 * struct interrupt_controller_api - Interrupt controller api
 *
 * @request:	Callback used to request and register an interrupt handler
 *              on interrupt controller device.
 * @enable:	Callback used to enable an interrupt.
 * @disable:	Callback used to disable an interrupt.
 * @mask:	Callback used to mask an interrupt.
 * @unmask:	Callback used to unmask an interrupt.
 */
struct interrupt_controller_api {
	interrupt_controller_req_t	request;
	interrupt_controller_enable_t	enable;
	interrupt_controller_disable_t	disable;
	interrupt_controller_mask_t	mask;
	interrupt_controller_unmask_t	unmask;
};

/**
 * @brief request and register an interrupt handler on interrupt controller device
 *
 * On success, the interrupt handler is register on interrupt controller.
 *
 * @param spec Reference on interrupt specification.
 * @param data Reference on private data pass to interrupt handler.
 * @param cb Callback handler function.
 * @param flags Interrupt flags.
 * @return 0 on success, negative errno on failure.
 */
int interrupt_request(const struct irq_spec *i_spec, void *data, irq_handler_t cb, uint32_t flags);

/**
 * @brief enable an interrupt.
 *
 * On success, the interrupt is enabled.
 *
 * @param spec reference on interrupt specification.
 * @return 0 on success, negative errno on failure.
 */
int interrupt_enable(const struct irq_spec *spec);

/**
 * @brief disable an interrupt.
 *
 * On success, the interrupt is disabled.
 *
 * @param spec reference on interrupt specification.
 * @return 0 on success, negative errno on failure.
 */
int interrupt_disable(const struct irq_spec *spec);

/**
 * @brief mask an interrupt.
 *
 * On success, the interrupt is masked.
 *
 * @param spec reference on interrupt specification.
 * @return 0 on success, negative errno on failure.
 */
int interrupt_mask(const struct irq_spec *spec);

/**
 * @brief unmask an interrupt.
 *
 * On success, the interrupt is unmasked.
 *
 * @param spec reference on interrupt specification.
 * @return 0 on success, negative errno on failure.
 */
int interrupt_unmask(const struct irq_spec *spec);

/* Internal macros that shouldn't be used directly */
#define _IRQ_SPEC_NAME(node_id) \
	_CONCAT(_irq_spec, DEVICE_DT_NAME_GET(node_id))

#define _IRQ_SPEC_ARGS_NAME(node_id, idx) \
	_CONCAT(_CONCAT(_IRQ_SPEC_NAME(node_id), _args_), idx)

#define _IRQ_SPEC_IRQ_HDL_NAME(node_id, idx) \
	_CONCAT(_CONCAT(_IRQ_SPEC_NAME(node_id), _irq_hdl_), idx)

#define _IRQ_CTRL_PHA_ARRAY_BY_IDX(node_id, idx) \
	DT_FOREACH_PHA_CELL_BY_IDX_SEP(node_id, interrupts, idx, DT_PHA_BY_IDX, (,))

#define _IRQ_CTRL_PHA_ARRAY_LEN_BY_IDX(node_id, idx) \
	DT_PHA_NUM_CELLS_BY_IDX(node_id, interrupts, idx)

#define _IRQ_CTRL_SPEC_ITEM(idx, node_id)						\
	{										\
		.dev = DEVICE_DT_GET(DT_IRQ_INTC_BY_IDX(node_id, idx)),			\
		.irq_hdl = &_IRQ_SPEC_IRQ_HDL_NAME(node_id, idx),			\
		.args = _IRQ_SPEC_ARGS_NAME(node_id, idx),				\
		.nargs = _IRQ_CTRL_PHA_ARRAY_LEN_BY_IDX(node_id, idx),			\
	}

#define _IRQ_CTRL_IRQ_HDL_DEFINE(idx, node_id)						\
	COND_CODE_1(DT_PROP_HAS_IDX(node_id, interrupts, idx),				\
	(static struct irq_handler _IRQ_SPEC_IRQ_HDL_NAME(node_id, idx) = {		\
		.callback = NULL,							\
		.data = NULL,								\
		.irq = UINT32_MAX,							\
	 }), ())

#define _IRQ_CTRL_ARGS_DEFINE(idx, node_id)						\
	COND_CODE_1(DT_PROP_HAS_IDX(node_id, interrupts, idx),				\
	(static const uint32_t _IRQ_SPEC_ARGS_NAME(node_id, idx)[] = {			\
		_IRQ_CTRL_PHA_ARRAY_BY_IDX(node_id, idx)				\
	 }), ())

#define _IRQS_CTRL_IRQ_HDL_DEFINE(node_id) \
	LISTIFY(DT_NUM_IRQS(node_id), _IRQ_CTRL_IRQ_HDL_DEFINE, (;), node_id);

#define _IRQS_CTRL_ARGS_DEFINE(node_id) \
	LISTIFY(DT_NUM_IRQS(node_id), _IRQ_CTRL_ARGS_DEFINE, (;), node_id);

#define _IRQS_CTRL_SPEC_DEFNE(node_id)							\
	COND_CODE_1(DT_NODE_HAS_PROP(node_id, interrupts),				\
	(static const struct irq_spec _IRQ_SPEC_NAME(node_id)[] =			\
	 {										\
		LISTIFY(DT_NUM_IRQS(node_id),						\
			_IRQ_CTRL_SPEC_ITEM,						\
			(,), node_id)							\
	 };),())

/*
 * Macros to define and get all references of interrupt property
 */
#define DT_IRQS_SPEC_DEFINE(node_id)							\
	_IRQS_CTRL_IRQ_HDL_DEFINE(node_id)						\
	_IRQS_CTRL_ARGS_DEFINE(node_id)							\
	_IRQS_CTRL_SPEC_DEFNE(node_id)

#define DT_INST_IRQS_SPEC_DEFINE(inst) \
	DT_IRQS_SPEC_DEFINE(DT_DRV_INST(inst))

#define DT_IRQS_SPEC_GET_BY_IDX(node_id, idx)						\
	COND_CODE_1(DT_NODE_HAS_PROP(node_id, interrupts),				\
		    (&_IRQ_SPEC_NAME(node_id)[idx]), (NULL))

#define DT_IRQS_SPEC_GET(node_id)							\
	DT_IRQS_SPEC_GET_BY_IDX(node_id, 0)

#define DT_INST_IRQS_SPEC_GET_BY_IDX(inst, idx)						\
	DT_IRQS_SPEC_GET_BY_IDX(DT_DRV_INST(inst), idx)

#define DT_INST_IRQS_SPEC_GET(inst) \
	DT_INST_IRQS_SPEC_GET_BY_IDX(inst, 0)

#define DT_IRQS_ELEM_IDX_BY_NAME(node_id, name)						\
	DT_PHA_ELEM_IDX_BY_NAME(node_id, interrupts, name)

#define DT_IRQS_SPEC_GET_BY_NAME(node_id, name)						\
	DT_IRQS_SPEC_GET_BY_IDX(node_id, DT_IRQS_ELEM_IDX_BY_NAME(node_id, name))

#define DT_INST_IRQS_SPEC_GET_BY_NAME(inst, name)					\
	DT_IRQS_SPEC_GET_BY_NAME(DT_DRV_INST(inst), name)

#endif /* INCLUDE_IRQ_H_ */
