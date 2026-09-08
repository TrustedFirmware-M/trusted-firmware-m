/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

/**
 * @file
 * STM32 SoC specific helpers for pinctrl driver
 */

#ifndef _STM32_COMMON_PINCTRL_SOC_H_
#define _STM32_COMMON_PINCTRL_SOC_H_

#include <devicetree.h>
#include <lib/utils_def.h>

#include <dt-bindings/pinctrl/stm32-pinfunc.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @cond INTERNAL_HIDDEN */

/** Type for STM32 pin. */
typedef struct pinctrl_soc_pin {
	/** Pinmux settings (port, pin and function). */
	uint32_t pinmux;
	/** Pin configuration (bias, drive and slew rate). */
	uint32_t pincfg;
} pinctrl_soc_pin_t;

/**
 * @brief Utility macro to initialize pinmux field in #pinctrl_pin_t.
 *
 * @param node_id Node identifier.
 */
#define Z_PINCTRL_STM32_PINMUX_INIT(node_id, prop, idx) DT_PROP_BY_IDX(node_id, prop, idx)

/**
 * @brief Utility macro to initialize fields in #pinctrl_pin_t.
 *
 * Pin muxing is defined by dt-bindings header
 */

/**
 * @brief PIN configuration bitfield
 *
 * Pin configuration is coded with the following
 * fields
 *    GPIO Mode           [ 4 : 5 ] see pinmux func (alternate|analog)
 *    GPIO Output type    [ 6 ]
 *    GPIO Speed          [ 7 : 8 ]
 *    GPIO PUPD config    [ 9 : 10 ]
 *    GPIO Output data    [ 11 ]
 *
 */
#define _PINCFG_MODE_MASK	GENMASK(5, 4)
#define _PINCFG_MODE_SHIFT	4
#define _PINCFG_OTYPE_MASK	BIT(6)
#define _PINCFG_OTYPE_SHIFT	6
#define _PINCFG_OSPEED_MASK	GENMASK(8, 7)
#define _PINCFG_OSPEED_SHIFT	7
#define _PINCFG_PUPD_MASK	GENMASK(10, 9)
#define _PINCFG_PUPD_SHIFT	9
#define _PINCFG_OD_MASK		BIT(11)
#define _PINCFG_OD_SHIFT	9

#define _PINCFG_MODE_OUTPUT		_FLD_PREP(_PINCFG_MODE, 0x1)
#define _PINCFG_OTYPE_PUSH_PULL		_FLD_PREP(_PINCFG_OTYPE, 0x0)
#define _PINCFG_OTYPE_OPEN_DRAIN	_FLD_PREP(_PINCFG_OTYPE, 0x1)
#define _PINCFG_PUPD_NO_PULL		_FLD_PREP(_PINCFG_PUPD, 0x0)
#define _PINCFG_PUPD_PULL_UP		_FLD_PREP(_PINCFG_PUPD, 0x1)
#define _PINCFG_PUPD_PULL_DOWN		_FLD_PREP(_PINCFG_PUPD, 0x2)
#define _PINCFG_OD_OUTPUT_LOW		_FLD_PREP(_PINCFG_OD, 0x0)
#define _PINCFG_OD_OUTPUT_HIGH		_FLD_PREP(_PINCFG_OD, 0x1)

#define _PINCTRL_STM32_PINCFG_MODE(node_id)			\
	((_PINCFG_MODE_OUTPUT * DT_PROP(node_id, output_low)) |	\
	 (_PINCFG_MODE_OUTPUT * DT_PROP(node_id, output_high)))

#define _PINCTRL_STM32_PINCFG_OTYPE(node_id)				  \
	((_PINCFG_OTYPE_PUSH_PULL * DT_PROP(node_id, drive_push_pull)) |  \
	 (_PINCFG_OTYPE_OPEN_DRAIN * DT_PROP(node_id, drive_open_drain)))

#define _PINCTRL_STM32_PINCFG_OSPEED(node_id) \
	(_FLD_PREP(_PINCFG_OSPEED, DT_PROP_OR(node_id, slew_rate, (0U))))

#define _PINCTRL_STM32_PINCFG_PUPD(node_id)                           \
	((_PINCFG_PUPD_NO_PULL * DT_PROP(node_id, bias_disable)) |    \
	 (_PINCFG_PUPD_PULL_UP * DT_PROP(node_id, bias_pull_up)) |    \
	 (_PINCFG_PUPD_PULL_DOWN * DT_PROP(node_id, bias_pull_down)))

#define _PINCTRL_STM32_PINCFG_OD(node_id)			  \
	((_PINCFG_OD_OUTPUT_LOW * DT_PROP(node_id, output_low)) | \
	 (_PINCFG_OD_OUTPUT_HIGH * DT_PROP(node_id, output_high)))

#define Z_PINCTRL_STM32_PINCFG_INIT(node_id)		\
	(_PINCTRL_STM32_PINCFG_MODE(node_id) |		\
	 _PINCTRL_STM32_PINCFG_OTYPE(node_id) |		\
	 _PINCTRL_STM32_PINCFG_OSPEED(node_id) |	\
	 _PINCTRL_STM32_PINCFG_PUPD(node_id) |		\
	 _PINCTRL_STM32_PINCFG_OD(node_id))

/**
 * @brief Utility macro to initialize each pin.
 *
 * @param node_id Node identifier.
 * @param state_prop State property name.
 * @param idx State property entry index.
 */
#define Z_PINCTRL_STATE_PIN_INIT(node_id, state_prop, idx)			\
	{ .pinmux = Z_PINCTRL_STM32_PINMUX_INIT(node_id, state_prop, idx),	\
	  .pincfg = Z_PINCTRL_STM32_PINCFG_INIT(node_id)},

/**
 * @brief Utility macro to initialize group pins contained in a given property.
 *
 * @param node_id Node identifier.
 * @param prop Property name describing state pins.
 */
#define Z_PINCTRL_STATE_GROUP_INIT(node_id, prop, idx)			\
	DT_FOREACH_CHILD_VARGS(DT_PHANDLE_BY_IDX(node_id, prop, idx),	\
				DT_FOREACH_PROP_ELEM, pinmux,		\
				Z_PINCTRL_STATE_PIN_INIT)

#define Z_PINCTRL_STATE_PINS_INIT(node_id, prop)			\
	{ DT_FOREACH_PROP_ELEM_SEP(node_id, prop,			\
				   Z_PINCTRL_STATE_GROUP_INIT,		\
				   ()) }

/** @endcond */

#ifdef __cplusplus
}
#endif

#endif /* _STM32_COMMON_PINCTRL_SOC_H_ */
