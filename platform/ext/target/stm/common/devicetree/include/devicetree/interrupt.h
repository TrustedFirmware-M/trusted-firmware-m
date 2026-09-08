/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef INCLUDE_DEVICETREE_INTERRUPT_H_
#define INCLUDE_DEVICETREE_INTERRUPT_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup devicetree-interrupt-controller Devicetree Interrupt Controller API
 * @ingroup devicetree
 * @{
 */

/**
 * @brief Get the number of interrupt sources for the node
 *
 * @param node_id node identifier
 * @return Number of interrupt specifiers in the node's "interrupts" property.
 */
#define DT_NUM_IRQS(node_id) \
	DT_PROP_LEN_OR(node_id, interrupts, 0)

/**
 * @brief Get an interrupt specifier's interrupt controller by index
 *
 * @code{.dts}
 *     gpio0: gpio0 {
 *             interrupt-controller;
 *             #interrupt-cells = <2>;
 *     };
 *
 *     foo: foo {
 *             interrupt-parent = <&gpio0>;
 *             interrupts = <1 1>, <2 2>;
 *     };
 *
 *     bar: bar {
 *             interrupts-extended = <&gpio0 3 3>, <&pic0 4>;
 *     };
 *
 *     pic0: pic0 {
 *             interrupt-controller;
 *             #interrupt-cells = <1>;
 *
 *             qux: qux {
 *                     interrupts = <5>, <6>;
 *                     interrupt-names = "int1", "int2";
 *             };
 *     };
 * @endcode
 *
 * Example usage:
 *
 *     DT_IRQ_INTC_BY_IDX(DT_NODELABEL(foo), 0) // &gpio0
 *     DT_IRQ_INTC_BY_IDX(DT_NODELABEL(foo), 1) // &gpio0
 *     DT_IRQ_INTC_BY_IDX(DT_NODELABEL(bar), 0) // &gpio0
 *     DT_IRQ_INTC_BY_IDX(DT_NODELABEL(bar), 1) // &pic0
 *     DT_IRQ_INTC_BY_IDX(DT_NODELABEL(qux), 0) // &pic0
 *     DT_IRQ_INTC_BY_IDX(DT_NODELABEL(qux), 1) // &pic0
 *
 * @param node_id node identifier
 * @param idx interrupt specifier's index
 * @return node_id of interrupt specifier's interrupt controller
 */
#define DT_IRQ_INTC_BY_IDX(node_id, idx) \
	DT_PHANDLE_BY_IDX(node_id, interrupts, idx)

/**
 * @brief Get an interrupt specifier's interrupt controller
 * @note Equivalent to DT_IRQ_INTC_BY_IDX(node_id, 0)
 *
 * @param node_id node identifier
 * @return node_id of interrupt specifier's interrupt controller
 * @see DT_IRQ_INTC_BY_IDX()
 */
#define DT_IRQ_INTC(node_id) \
	DT_IRQ_INTC_BY_IDX(node_id, 0)

/**
 * @brief Get an interrupt specifier's interrupt controller by name
 *
 * @code{.dts}
 *     gpio0: gpio0 {
 *             interrupt-controller;
 *             #interrupt-cells = <2>;
 *     };
 *
 *     foo: foo {
 *             interrupt-parent = <&gpio0>;
 *             interrupts = <1 1>, <2 2>;
 *             interrupt-names = "int1", "int2";
 *     };
 *
 *     bar: bar {
 *             interrupts-extended = <&gpio0 3 3>, <&pic0 4>;
 *             interrupt-names = "int1", "int2";
 *     };
 *
 *     pic0: pic0 {
 *             interrupt-controller;
 *             #interrupt-cells = <1>;
 *
 *             qux: qux {
 *                     interrupts = <5>, <6>;
 *                     interrupt-names = "int1", "int2";
 *             };
 *     };
 * @endcode
 *
 * Example usage:
 *
 *     DT_IRQ_INTC_BY_NAME(DT_NODELABEL(foo), int1) // &gpio0
 *     DT_IRQ_INTC_BY_NAME(DT_NODELABEL(foo), int2) // &gpio0
 *     DT_IRQ_INTC_BY_NAME(DT_NODELABEL(bar), int1) // &gpio0
 *     DT_IRQ_INTC_BY_NAME(DT_NODELABEL(bar), int2) // &pic0
 *     DT_IRQ_INTC_BY_NAME(DT_NODELABEL(qux), int1) // &pic0
 *     DT_IRQ_INTC_BY_NAME(DT_NODELABEL(qux), int2) // &pic0
 *
 * @param node_id node identifier
 * @param name interrupt specifier's name
 * @return node_id of interrupt specifier's interrupt controller
 */
#define DT_IRQ_INTC_BY_NAME(node_id, name) \
	DT_PHANDLE_BY_NAME(node_id, interrupts, name)

/**
 * @brief Is @p idx a valid interrupt index?
 *
 * @param node_id node identifier
 * @param idx index to check
 * @return 1 if the idx is valid for the interrupt property
 *         0 otherwise.
 */
#define DT_IRQ_HAS_IDX(node_id, idx) \
	DT_PROP_HAS_IDX(node_id, interrupts, idx)

/**
 * @brief Does an interrupts property have a named cell specifier at an index?
 * @param node_id node identifier
 * @param idx index to check
 * @param cell named cell value whose existence to check
 * @return 1 if the named cell exists in the interrupt specifier at index idx
 *         0 otherwise.
 */
#define DT_IRQ_HAS_CELL_AT_IDX(node_id, idx, cell) \
	DT_PHA_HAS_CELL_AT_IDX(node_id, interrupts, idx, cell)

/**
 * @brief Equivalent to DT_IRQ_HAS_CELL_AT_IDX(node_id, 0, cell)
 * @param node_id node identifier
 * @param cell named cell value whose existence to check
 * @return 1 if the named cell exists in the interrupt specifier at index 0
 *         0 otherwise.
 */
#define DT_IRQ_HAS_CELL(node_id, cell) \
	DT_IRQ_HAS_CELL_AT_IDX(node_id, 0, cell)

/**
 * @brief Does an interrupts property have a named specifier value at an index?
 * @param node_id node identifier
 * @param name lowercase-and-underscores interrupt specifier name
 * @return 1 if "name" is a valid named specifier
 *         0 otherwise.
 */
#define DT_IRQ_HAS_NAME(node_id, name) \
	DT_PROP_HAS_NAME(node_id, interrupts, name)

/**
 * @brief Get a value within an interrupt specifier at an index
 *
 * Example devicetree fragment:
 *
 * @code{.dts}
 *     my-serial: serial@abcd1234 {
 *             interrupts = < 33 0 >, < 34 1 >;
 *     };
 * @endcode
 *
 * Assuming the node's interrupt domain has "#interrupt-cells = <2>;" and
 * the individual cells in each interrupt specifier are named "irq" and
 * "priority" by the node's binding, here are some examples:
 *
 *     #define SERIAL DT_NODELABEL(my_serial)
 *
 *     Example usage                       Value
 *     -------------                       -----
 *     DT_IRQ_CELL_BY_IDX(SERIAL, 0, irq)          33
 *     DT_IRQ_CELL_BY_IDX(SERIAL, 0, priority)      0
 *     DT_IRQ_CELL_BY_IDX(SERIAL, 1, irq,          34
 *     DT_IRQ_CELL_BY_IDX(SERIAL, 1, priority)      1
 *
 * @param node_id node identifier
 * @param idx logical index into the interrupt specifier array
 * @param cell cell name specifier
 * @return the named value at the specifier given by the index
 */
#define DT_IRQ_CELL_BY_IDX(node_id, idx, cell) \
	DT_PHA_BY_IDX(node_id, interrupts, idx, cell)

/**
 * @brief Get an interrupt specifier's value
 * Equivalent to DT_IRQ_CELL_BY_IDX(node_id, 0, cell).
 * @param node_id node identifier
 * @param cell cell name specifier
 * @return the named value at that index
 */
#define DT_IRQ_CELL(node_id, cell) \
	DT_IRQ_CELL_BY_IDX(node_id, 0, cell)

/**
 * @brief Get a interrupt specifier's cell value by name
 *
 * @param node_id node identifier for a node with a interrupts property
 * @param name lowercase-and-underscores name of a interrupts element
 *             as defined by the node's interrupt-names property
 * @param cell lowercase-and-underscores cell name
 * @return the cell value in the specifier at the named element
 * @see DT_PHA_BY_NAME()
 */
#define DT_IRQ_CELL_BY_NAME(node_id, name, cell) \
	DT_PHA_BY_NAME(node_id, interrupts, name, cell)

/**
 * @brief Get a node's (only) irq number at index
 *
 * Equivalent to DT_IRQ_CELL_BY_IDX(node_id, 0, irq).
 * This is provided as a convenience for the common case where a node
 * generates exactly one interrupt, and the IRQ number is in a cell named `irq`.
 *
 * @param node_id node identifier
 * @param idx logical index into the interrupt specifier array
 * @return the interrupt number for the node's only interrupt
 */
#define DT_IRQN_BY_IDX(node_id, idx) \
	DT_IRQ_CELL_BY_IDX(node_id, 0, irq)

/**
 * @brief Get a node's (only) irq number
 *
 * Equivalent to DT_IRQ_CELL(node_id, irq). This is provided as a convenience
 * for the common case where a node generates exactly one interrupt,
 * and the IRQ number is in a cell named `irq`.
 *
 * @param node_id node identifier
 * @return the interrupt number for the node's only interrupt
 */
#define DT_IRQN(node_id) \
	DT_IRQN_BY_IDX(node_id, 0)

/**
 * @brief Get a `DT_DRV_COMPAT`'s number of interrupts
 *
 * @param inst instance number
 * @return number of interrupts
 */
#define DT_INST_NUM_IRQS(inst) \
	DT_NUM_IRQS(DT_DRV_INST(inst))

/**
 * @brief Get a `DT_DRV_COMPAT` interrupt specifier's interrupt controller by index
 * @param inst instance number
 * @param idx interrupt specifier's index
 * @return node_id of interrupt specifier's interrupt controller
 */
#define DT_INST_IRQ_INTC_BY_IDX(inst, idx) \
	DT_IRQ_INTC_BY_IDX(DT_DRV_INST(inst), idx)

/**
 * @brief Get a `DT_DRV_COMPAT` interrupt specifier's interrupt controller
 * @note Equivalent to DT_INST_IRQ_INTC_BY_IDX(node_id, 0)
 * @param inst instance number
 * @return node_id of interrupt specifier's interrupt controller
 * @see DT_INST_IRQ_INTC_BY_IDX()
 */
#define DT_INST_IRQ_INTC(inst) \
	DT_INST_IRQ_INTC_BY_IDX(inst, 0)

/**
 * @brief Get a `DT_DRV_COMPAT` interrupt specifier's interrupt controller by name
 * @param inst instance number
 * @param name interrupt specifier's name
 * @return node_id of interrupt specifier's interrupt controller
 */
#define DT_INST_IRQ_INTC_BY_NAME(inst, name) \
	DT_IRQ_INTC_BY_NAME(DT_DRV_INST(inst), name)

/**
 * @brief is index valid for interrupt property on a `DT_DRV_COMPAT` instance?
 * @param inst instance number
 * @param idx logical index into the interrupt specifier array
 * @return 1 if the @p idx is valid for the interrupt property
 *         0 otherwise.
 */
#define DT_INST_IRQ_HAS_IDX(inst, idx) \
	DT_IRQ_HAS_IDX(DT_DRV_INST(inst), idx)

/**
 * @brief Does a `DT_DRV_COMPAT` instance have an interrupt named cell specifier?
 * @param inst instance number
 * @param idx index to check
 * @param cell named cell value whose existence to check
 * @return 1 if the named @p cell exists in the interrupt specifier at index
 *         @p idx 0 otherwise.
 */
#define DT_INST_IRQ_HAS_CELL_AT_IDX(inst, idx, cell) \
	DT_IRQ_HAS_CELL_AT_IDX(DT_DRV_INST(inst), idx, cell)

/**
 * @brief Does a `DT_DRV_COMPAT` instance have an interrupt value?
 * @param inst instance number
 * @param cell named cell value whose existence to check
 * @return 1 if the named @p cell exists in the interrupt specifier at index 0
 *         0 otherwise.
 */
#define DT_INST_IRQ_HAS_CELL(inst, cell) \
	DT_INST_IRQ_HAS_CELL_AT_IDX(inst, 0, cell)

/**
 * @brief Does a `DT_DRV_COMPAT` instance have an interrupt value?
 * @param inst instance number
 * @param name lowercase-and-underscores interrupt specifier name
 * @return 1 if @p name is a valid named specifier
 */
#define DT_INST_IRQ_HAS_NAME(inst, name) \
	DT_IRQ_HAS_NAME(DT_DRV_INST(inst), name)

/**
 * @brief Get a DT_DRV_COMPAT instance's interrupt specifier's cell value at an index
 * @param inst DT_DRV_COMPAT instance number
 * @param idx logical index into interrupt property
 * @param cell lowercase-and-underscores cell name
 * @return the cell value at index "idx"
 * @see DT_IRQ_CELL_BY_IDX()
 */
#define DT_INST_IRQ_CELL_BY_IDX(inst, idx, cell) \
	DT_IRQ_CELL_BY_IDX(DT_DRV_INST(inst), idx, cell)

/**
 * @brief Get a `DT_DRV_COMPAT` interrupt specifier's value
 * @param inst instance number
 * @param cell cell name specifier
 * @return the named value at that index
 */
#define DT_INST_IRQ_CELL(inst, cell) \
	DT_INST_IRQ_CELL_BY_IDX(inst, 0, cell)

/**
 * @brief Get a DT_DRV_COMPAT instance's interrupt specifier's cell value by name
 * @param inst DT_DRV_COMPAT instance number
 * @param name lowercase-and-underscores name of a interrupts element
 *             as defined by the node's interrupt-names property
 * @param cell lowercase-and-underscores cell name
 * @return the cell value in the specifier at the named element
 * @see DT_IRQ_CELL_BY_NAME()
 */
#define DT_INST_IRQ_CELL_BY_NAME(inst, name, cell) \
	DT_IRQ_CELL_BY_NAME(DT_DRV_INST(inst), name, cell)

/**
 * @brief Get a `DT_DRV_COMPAT`'s irq number at index
 * @param inst instance number
 * @param idx logical index into the interrupt specifier array
 * @return the interrupt number for the node's idx-th interrupt
 */
#define DT_INST_IRQN_BY_IDX(inst, idx) \
	DT_IRQN_BY_IDX(DT_DRV_INST(inst), idx)

/**
 * @brief Get a `DT_DRV_COMPAT`'s (only) irq number
 * @param inst instance number
 * @return the interrupt number for the node's only interrupt
 */
#define DT_INST_IRQN(inst) \
	DT_INST_IRQN_BY_IDX(inst, 0)

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif  /* INCLUDE_DEVICETREE_INTERRUPT_H_ */
