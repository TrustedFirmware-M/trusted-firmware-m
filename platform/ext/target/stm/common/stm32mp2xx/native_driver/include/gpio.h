/*
 * Copyright (c) 2019-2020 Nordic Semiconductor ASA
 * Copyright (c) 2019 Piotr Mienkowski
 * Copyright (c) 2017 ARM Ltd
 * Copyright (c) 2015-2016 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @ingroup gpio_interface
 * @brief Main header file for GPIO driver API.
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_GPIO_H_
#define ZEPHYR_INCLUDE_DRIVERS_GPIO_H_
#include <errno.h>
#include <lib/utils_def.h>

#include <device.h>
#include <devicetree.h>
#include <devicetree/gpio.h>
#include <dt-bindings/gpio/gpio.h>

/**
 * @brief Interfaces for General Purpose Input/Output (GPIO)
 *        controllers.
 * @defgroup gpio_interface GPIO
 * @since 1.0
 * @version 1.0.0
 * @ingroup io_interfaces
 * @{
 *
 * @defgroup gpio_interface_ext Device-specific GPIO API extensions
 *
 * @{
 * @}
 */

/**
 * @name GPIO input/output configuration flags
 * @{
 */

/** Enables pin as input. */
#define GPIO_INPUT              BIT(16)

/** Enables pin as output, no change to the output state. */
#define GPIO_OUTPUT             BIT(17)

/** Disables pin for both input and output. */
#define GPIO_DISCONNECTED	0

/** @cond INTERNAL_HIDDEN */

/* Initializes output to a low state. */
#define GPIO_OUTPUT_INIT_LOW    BIT(18)

/* Initializes output to a high state. */
#define GPIO_OUTPUT_INIT_HIGH   BIT(19)

/* Initializes output based on logic level */
#define GPIO_OUTPUT_INIT_LOGICAL BIT(20)

/** @endcond */

/** Configures GPIO pin as output and initializes it to a low state. */
#define GPIO_OUTPUT_LOW         (GPIO_OUTPUT | GPIO_OUTPUT_INIT_LOW)
/** Configures GPIO pin as output and initializes it to a high state. */
#define GPIO_OUTPUT_HIGH        (GPIO_OUTPUT | GPIO_OUTPUT_INIT_HIGH)
/** Configures GPIO pin as output and initializes it to a logic 0. */
#define GPIO_OUTPUT_INACTIVE    (GPIO_OUTPUT |			\
				 GPIO_OUTPUT_INIT_LOW |		\
				 GPIO_OUTPUT_INIT_LOGICAL)
/** Configures GPIO pin as output and initializes it to a logic 1. */
#define GPIO_OUTPUT_ACTIVE      (GPIO_OUTPUT |			\
				 GPIO_OUTPUT_INIT_HIGH |	\
				 GPIO_OUTPUT_INIT_LOGICAL)

/** @} */

/**
 * @name GPIO interrupt configuration flags
 * The `GPIO_INT_*` flags are used to specify how input GPIO pins will trigger
 * interrupts. The interrupts can be sensitive to pin physical or logical level.
 * Interrupts sensitive to pin logical level take into account GPIO_ACTIVE_LOW
 * flag. If a pin was configured as Active Low, physical level low will be
 * considered as logical level 1 (an active state), physical level high will
 * be considered as logical level 0 (an inactive state).
 * The GPIO controller should reset the interrupt status, such as clearing the
 * pending bit, etc, when configuring the interrupt triggering properties.
 * Applications should use the `GPIO_INT_MODE_ENABLE_ONLY` and
 * `GPIO_INT_MODE_DISABLE_ONLY` flags to enable and disable interrupts on the
 * pin without changing any GPIO settings.
 * @{
 */

/** Disables GPIO pin interrupt. */
#define GPIO_INT_DISABLE               BIT(21)

/** @cond INTERNAL_HIDDEN */

/* Enables GPIO pin interrupt. */
#define GPIO_INT_ENABLE                BIT(22)

/* GPIO interrupt is sensitive to logical levels.
 *
 * This is a component flag that should be combined with other
 * `GPIO_INT_*` flags to produce a meaningful configuration.
 */
#define GPIO_INT_LEVELS_LOGICAL        BIT(23)

/* GPIO interrupt is edge sensitive.
 *
 * Note: by default interrupts are level sensitive.
 *
 * This is a component flag that should be combined with other
 * `GPIO_INT_*` flags to produce a meaningful configuration.
 */
#define GPIO_INT_EDGE                  BIT(24)

/* Trigger detection when input state is (or transitions to) physical low or
 * logical 0 level.
 *
 * This is a component flag that should be combined with other
 * `GPIO_INT_*` flags to produce a meaningful configuration.
 */
#define GPIO_INT_LOW_0                 BIT(25)

/* Trigger detection on input state is (or transitions to) physical high or
 * logical 1 level.
 *
 * This is a component flag that should be combined with other
 * `GPIO_INT_*` flags to produce a meaningful configuration.
 */
#define GPIO_INT_HIGH_1                BIT(26)

#ifdef CONFIG_GPIO_ENABLE_DISABLE_INTERRUPT
/* Disable/Enable interrupt functionality without changing other interrupt
 * related register, such as clearing the pending register.
 *
 * This is a component flag that should be combined with `GPIO_INT_ENABLE` or
 * `GPIO_INT_DISABLE` flags to produce a meaningful configuration.
 */
#define GPIO_INT_ENABLE_DISABLE_ONLY   BIT(27)
#endif /* CONFIG_GPIO_ENABLE_DISABLE_INTERRUPT */

#define GPIO_INT_MASK                  (GPIO_INT_DISABLE | \
					GPIO_INT_ENABLE | \
					GPIO_INT_LEVELS_LOGICAL | \
					GPIO_INT_EDGE | \
					GPIO_INT_LOW_0 | \
					GPIO_INT_HIGH_1)

/** @endcond */

/** Configures GPIO interrupt to be triggered on pin rising edge and enables it.
 */
#define GPIO_INT_EDGE_RISING           (GPIO_INT_ENABLE | \
					GPIO_INT_EDGE | \
					GPIO_INT_HIGH_1)

/** Configures GPIO interrupt to be triggered on pin falling edge and enables
 * it.
 */
#define GPIO_INT_EDGE_FALLING          (GPIO_INT_ENABLE | \
					GPIO_INT_EDGE | \
					GPIO_INT_LOW_0)

/** Configures GPIO interrupt to be triggered on pin rising or falling edge and
 * enables it.
 */
#define GPIO_INT_EDGE_BOTH             (GPIO_INT_ENABLE | \
					GPIO_INT_EDGE | \
					GPIO_INT_LOW_0 | \
					GPIO_INT_HIGH_1)

/** Configures GPIO interrupt to be triggered on pin physical level low and
 * enables it.
 */
#define GPIO_INT_LEVEL_LOW             (GPIO_INT_ENABLE | \
					GPIO_INT_LOW_0)

/** Configures GPIO interrupt to be triggered on pin physical level high and
 * enables it.
 */
#define GPIO_INT_LEVEL_HIGH            (GPIO_INT_ENABLE | \
					GPIO_INT_HIGH_1)

/** Configures GPIO interrupt to be triggered on pin state change to logical
 * level 0 and enables it.
 */
#define GPIO_INT_EDGE_TO_INACTIVE      (GPIO_INT_ENABLE | \
					GPIO_INT_LEVELS_LOGICAL | \
					GPIO_INT_EDGE | \
					GPIO_INT_LOW_0)

/** Configures GPIO interrupt to be triggered on pin state change to logical
 * level 1 and enables it.
 */
#define GPIO_INT_EDGE_TO_ACTIVE        (GPIO_INT_ENABLE | \
					GPIO_INT_LEVELS_LOGICAL | \
					GPIO_INT_EDGE | \
					GPIO_INT_HIGH_1)

/** Configures GPIO interrupt to be triggered on pin logical level 0 and enables
 * it.
 */
#define GPIO_INT_LEVEL_INACTIVE        (GPIO_INT_ENABLE | \
					GPIO_INT_LEVELS_LOGICAL | \
					GPIO_INT_LOW_0)

/** Configures GPIO interrupt to be triggered on pin logical level 1 and enables
 * it.
 */
#define GPIO_INT_LEVEL_ACTIVE          (GPIO_INT_ENABLE | \
					GPIO_INT_LEVELS_LOGICAL | \
					GPIO_INT_HIGH_1)

/** @} */

/** @cond INTERNAL_HIDDEN */
#define GPIO_DIR_MASK		(GPIO_INPUT | GPIO_OUTPUT)
/** @endcond */

/**
 * @brief Identifies a set of pins associated with a port.
 *
 * The pin with index n is present in the set if and only if the bit
 * identified by (1U << n) is set.
 */
typedef uint32_t gpio_port_pins_t;

/**
 * @brief Provides values for a set of pins associated with a port.
 *
 * The value for a pin with index n is high (physical mode) or active
 * (logical mode) if and only if the bit identified by (1U << n) is set.
 * Otherwise the value for the pin is low (physical mode) or inactive
 * (logical mode).
 *
 * Values of this type are often paired with a `gpio_port_pins_t` value
 * that specifies which encoded pin values are valid for the operation.
 */
typedef uint32_t gpio_port_value_t;

/**
 * @brief Provides a type to hold a GPIO pin index.
 *
 * This reduced-size type is sufficient to record a pin number,
 * e.g. from a devicetree GPIOS property.
 */
typedef uint8_t gpio_pin_t;

/**
 * @brief Provides a type to hold GPIO devicetree flags.
 *
 * All GPIO flags that can be expressed in devicetree fit in the low 16
 * bits of the full flags field, so use a reduced-size type to record
 * that part of a GPIOS property.
 *
 * The lower 8 bits are used for standard flags. The upper 8 bits are reserved
 * for SoC specific flags.
 */
typedef uint16_t gpio_dt_flags_t;

/**
 * @brief Provides a type to hold GPIO configuration flags.
 *
 * This type is sufficient to hold all flags used to control GPIO
 * configuration, whether pin or interrupt.
 */
typedef uint32_t gpio_flags_t;

/**
 * @brief Container for GPIO pin information specified in devicetree
 *
 * This type contains a pointer to a GPIO device, pin number for a pin
 * controlled by that device, and the subset of pin configuration
 * flags which may be given in devicetree.
 *
 * @see GPIO_DT_SPEC_GET_BY_IDX
 * @see GPIO_DT_SPEC_GET_BY_IDX_OR
 * @see GPIO_DT_SPEC_GET
 * @see GPIO_DT_SPEC_GET_OR
 */
struct gpio_dt_spec {
	/** GPIO device controlling the pin */
	const struct device *port;
	/** The pin's number on the device */
	gpio_pin_t pin;
	/** The pin's configuration flags as specified in devicetree */
	gpio_dt_flags_t dt_flags;
};

/**
 * @brief Static initializer for a @p gpio_dt_spec
 *
 * This returns a static initializer for a @p gpio_dt_spec structure given a
 * devicetree node identifier, a property specifying a GPIO and an index.
 *
 * Example devicetree fragment:
 *
 *	n: node {
 *		foo-gpios = <&gpio0 1 GPIO_ACTIVE_LOW>,
 *			    <&gpio1 2 GPIO_ACTIVE_LOW>;
 *	}
 *
 * Example usage:
 *
 *	const struct gpio_dt_spec spec = GPIO_DT_SPEC_GET_BY_IDX(DT_NODELABEL(n),
 *								 foo_gpios, 1);
 *	// Initializes 'spec' to:
 *	// {
 *	//         .port = DEVICE_DT_GET(DT_NODELABEL(gpio1)),
 *	//         .pin = 2,
 *	//         .dt_flags = GPIO_ACTIVE_LOW
 *	// }
 *
 * The 'gpio' field must still be checked for readiness, e.g. using
 * device_is_ready(). It is an error to use this macro unless the node
 * exists, has the given property, and that property specifies a GPIO
 * controller, pin number, and flags as shown above.
 *
 * @param node_id devicetree node identifier
 * @param prop lowercase-and-underscores property name
 * @param idx logical index into "prop"
 * @return static initializer for a struct gpio_dt_spec for the property
 */
#define GPIO_DT_SPEC_GET_BY_IDX(node_id, prop, idx)			       \
	{								       \
		.port = DEVICE_DT_GET(DT_GPIO_CTLR_BY_IDX(node_id, prop, idx)),\
		.pin = DT_GPIO_PIN_BY_IDX(node_id, prop, idx),		       \
		.dt_flags = DT_GPIO_FLAGS_BY_IDX(node_id, prop, idx),	       \
	}

/**
 * @brief Like GPIO_DT_SPEC_GET_BY_IDX(), with a fallback to a default value
 *
 * If the devicetree node identifier 'node_id' refers to a node with a
 * property 'prop', and the index @p idx is valid for that property,
 * this expands to <tt>GPIO_DT_SPEC_GET_BY_IDX(node_id, prop, idx)</tt>. The @p
 * default_value parameter is not expanded in this case.
 *
 * Otherwise, this expands to @p default_value.
 *
 * @param node_id devicetree node identifier
 * @param prop lowercase-and-underscores property name
 * @param idx logical index into "prop"
 * @param default_value fallback value to expand to
 * @return static initializer for a struct gpio_dt_spec for the property,
 *         or default_value if the node or property do not exist
 */
#define GPIO_DT_SPEC_GET_BY_IDX_OR(node_id, prop, idx, default_value)	\
	COND_CODE_1(DT_PROP_HAS_IDX(node_id, prop, idx),		\
		    (GPIO_DT_SPEC_GET_BY_IDX(node_id, prop, idx)),	\
		    (default_value))

/**
 * @brief Equivalent to GPIO_DT_SPEC_GET_BY_IDX(node_id, prop, 0).
 *
 * @param node_id devicetree node identifier
 * @param prop lowercase-and-underscores property name
 * @return static initializer for a struct gpio_dt_spec for the property
 * @see GPIO_DT_SPEC_GET_BY_IDX()
 */
#define GPIO_DT_SPEC_GET(node_id, prop) \
	GPIO_DT_SPEC_GET_BY_IDX(node_id, prop, 0)

/**
 * @brief Equivalent to
 *        GPIO_DT_SPEC_GET_BY_IDX_OR(node_id, prop, 0, default_value).
 *
 * @param node_id devicetree node identifier
 * @param prop lowercase-and-underscores property name
 * @param default_value fallback value to expand to
 * @return static initializer for a struct gpio_dt_spec for the property
 * @see GPIO_DT_SPEC_GET_BY_IDX_OR()
 */
#define GPIO_DT_SPEC_GET_OR(node_id, prop, default_value) \
	GPIO_DT_SPEC_GET_BY_IDX_OR(node_id, prop, 0, default_value)

/**
 * @brief Static initializer for a @p gpio_dt_spec from a DT_DRV_COMPAT
 * instance's GPIO property at an index.
 *
 * @param inst DT_DRV_COMPAT instance number
 * @param prop lowercase-and-underscores property name
 * @param idx logical index into "prop"
 * @return static initializer for a struct gpio_dt_spec for the property
 * @see GPIO_DT_SPEC_GET_BY_IDX()
 */
#define GPIO_DT_SPEC_INST_GET_BY_IDX(inst, prop, idx) \
	GPIO_DT_SPEC_GET_BY_IDX(DT_DRV_INST(inst), prop, idx)

/**
 * @brief Static initializer for a @p gpio_dt_spec from a DT_DRV_COMPAT
 *        instance's GPIO property at an index, with fallback
 *
 * @param inst DT_DRV_COMPAT instance number
 * @param prop lowercase-and-underscores property name
 * @param idx logical index into "prop"
 * @param default_value fallback value to expand to
 * @return static initializer for a struct gpio_dt_spec for the property
 * @see GPIO_DT_SPEC_GET_BY_IDX()
 */
#define GPIO_DT_SPEC_INST_GET_BY_IDX_OR(inst, prop, idx, default_value)		\
	COND_CODE_1(DT_PROP_HAS_IDX(DT_DRV_INST(inst), prop, idx),		\
		    (GPIO_DT_SPEC_GET_BY_IDX(DT_DRV_INST(inst), prop, idx)),	\
		    (default_value))

/**
 * @brief Equivalent to GPIO_DT_SPEC_INST_GET_BY_IDX(inst, prop, 0).
 *
 * @param inst DT_DRV_COMPAT instance number
 * @param prop lowercase-and-underscores property name
 * @return static initializer for a struct gpio_dt_spec for the property
 * @see GPIO_DT_SPEC_INST_GET_BY_IDX()
 */
#define GPIO_DT_SPEC_INST_GET(inst, prop) \
	GPIO_DT_SPEC_INST_GET_BY_IDX(inst, prop, 0)

/**
 * @brief Equivalent to
 *        GPIO_DT_SPEC_INST_GET_BY_IDX_OR(inst, prop, 0, default_value).
 *
 * @param inst DT_DRV_COMPAT instance number
 * @param prop lowercase-and-underscores property name
 * @param default_value fallback value to expand to
 * @return static initializer for a struct gpio_dt_spec for the property
 * @see GPIO_DT_SPEC_INST_GET_BY_IDX()
 */
#define GPIO_DT_SPEC_INST_GET_OR(inst, prop, default_value) \
	GPIO_DT_SPEC_INST_GET_BY_IDX_OR(inst, prop, 0, default_value)

/*
 * @cond INTERNAL_HIDDEN
 */

/**
 * Auxiliary conditional macro that generates a bitmask for the range
 * from @p "prop" array defined by the (off_idx, sz_idx) pair,
 * or 0 if the range does not exist.
 *
 * @param node_id devicetree node identifier
 * @param prop lowercase-and-underscores array property name
 * @param off_idx logical index of bitmask offset value into "prop" array
 * @param sz_idx logical index of bitmask size value into "prop" array
 */
#define Z_GPIO_GEN_BITMASK_COND(node_id, prop, off_idx, sz_idx)		     \
	COND_CODE_1(DT_PROP_HAS_IDX(node_id, prop, off_idx),		     \
		(COND_CODE_0(DT_PROP_BY_IDX(node_id, prop, sz_idx),	     \
			(0),						     \
			(GENMASK64(DT_PROP_BY_IDX(node_id, prop, off_idx) +  \
				DT_PROP_BY_IDX(node_id, prop, sz_idx) - 1,   \
				DT_PROP_BY_IDX(node_id, prop, off_idx))))    \
		), (0))

/**
 * A helper conditional macro returning generated bitmask for one element
 * from @p "gpio-reserved-ranges"
 *
 * @param odd_it the value of an odd sequential iterator
 * @param node_id devicetree node identifier
 */
#define Z_GPIO_GEN_RESERVED_RANGES_COND(odd_it, node_id)		      \
	COND_CODE_1(DT_PROP_HAS_IDX(node_id, gpio_reserved_ranges, odd_it),   \
		(Z_GPIO_GEN_BITMASK_COND(node_id,			      \
			gpio_reserved_ranges,				      \
			GET_ARG_N(odd_it, Z_SPARSE_LIST_EVEN_NUMBERS),	      \
			odd_it)),					      \
		(0))

/**
 * @endcond
 */

/**
 * @brief Makes a bitmask of reserved GPIOs from DT @p "gpio-reserved-ranges"
 *        property and @p "ngpios" argument
 *
 * This macro returns the value as a bitmask of the @p "gpio-reserved-ranges"
 * property. This property defines the disabled (or 'reserved') GPIOs in the
 * range @p 0...ngpios-1 and is specified as an array of value's pairs that
 * define the start offset and size of the reserved ranges.
 *
 * For example, setting "gpio-reserved-ranges = <3 2>, <10 1>;"
 * means that GPIO offsets 3, 4 and 10 cannot be used even if @p ngpios = <18>.
 *
 * The implementation constraint is inherited from common DT limitations:
 * a maximum of 64 pairs can be used (with result limited to bitsize
 * of gpio_port_pins_t type).
 *
 * NB: Due to the nature of C macros, some incorrect tuple definitions
 *    (for example, overlapping or out of range) will produce undefined results.
 *
 *    Also be aware that if @p ngpios is less than 32 (bit size of DT int type),
 *    then all unused MSBs outside the range defined by @p ngpios will be
 *    marked as reserved too.
 *
 * Example devicetree fragment:
 *
 * @code{.dts}
 *	a {
 *		compatible = "some,gpio-controller";
 *		ngpios = <32>;
 *		gpio-reserved-ranges = <0  4>, <5  3>, <9  5>, <11 2>, <15 2>,
 *					<18 2>, <21 1>, <23 1>, <25 4>, <30 2>;
 *	};
 *
 *	b {
 *		compatible = "some,gpio-controller";
 *		ngpios = <18>;
 *		gpio-reserved-ranges = <3 2>, <10 1>;
 *	};
 *
 * @endcode
 *
 * Example usage:
 *
 * @code{.c}
 *	struct some_config {
 *		uint32_t ngpios;
 *		uint32_t gpios_reserved;
 *	};
 *
 *	static const struct some_config dev_cfg_a = {
 *		.ngpios = DT_PROP_OR(DT_LABEL(a), ngpios, 0),
 *		.gpios_reserved = GPIO_DT_RESERVED_RANGES_NGPIOS(DT_LABEL(a),
 *					DT_PROP(DT_LABEL(a), ngpios)),
 *	};
 *
 *	static const struct some_config dev_cfg_b = {
 *		.ngpios = DT_PROP_OR(DT_LABEL(b), ngpios, 0),
 *		.gpios_reserved = GPIO_DT_RESERVED_RANGES_NGPIOS(DT_LABEL(b),
 *					DT_PROP(DT_LABEL(b), ngpios)),
 *	};
 *@endcode
 *
 * This expands to:
 *
 * @code{.c}
 *	struct some_config {
 *		uint32_t ngpios;
 *		uint32_t gpios_reserved;
 *	};
 *
 *	static const struct some_config dev_cfg_a = {
 *		.ngpios = 32,
 *		.gpios_reserved = 0xdeadbeef,
 *		               // 0b1101 1110 1010 1101 1011 1110 1110 1111
 *	};
 *	static const struct some_config dev_cfg_b = {
 *		.ngpios = 18,
 *		.gpios_reserved = 0xfffc0418,
 *		               // 0b1111 1111 1111 1100 0000 0100 0001 1000
 *		               // unused MSBs were marked as reserved too
 *	};
 * @endcode
 *
 * @param node_id GPIO controller node identifier.
 * @param ngpios number of GPIOs.
 * @return the bitmask of reserved gpios
 */
#define GPIO_DT_RESERVED_RANGES_NGPIOS(node_id, ngpios)			       \
	((gpio_port_pins_t)						       \
	COND_CODE_1(DT_NODE_HAS_PROP(node_id, gpio_reserved_ranges),	       \
		(GENMASK64(BITS_PER_LONG_LONG - 1, ngpios)		       \
		| FOR_EACH_FIXED_ARG(Z_GPIO_GEN_RESERVED_RANGES_COND,	       \
			(|),						       \
			node_id,					       \
			LIST_DROP_EMPTY(Z_SPARSE_LIST_ODD_NUMBERS))),	       \
		(0)))

/**
 * @brief Makes a bitmask of reserved GPIOs from the @p "gpio-reserved-ranges"
 *        and @p "ngpios" DT properties values
 *
 * @param node_id GPIO controller node identifier.
 * @return the bitmask of reserved gpios
 */
#define GPIO_DT_RESERVED_RANGES(node_id)				       \
	GPIO_DT_RESERVED_RANGES_NGPIOS(node_id, DT_PROP(node_id, ngpios))

/**
 * @brief Makes a bitmask of reserved GPIOs from a DT_DRV_COMPAT instance's
 *        @p "gpio-reserved-ranges" property and @p "ngpios" argument
 *
 * @param inst DT_DRV_COMPAT instance number
 * @return the bitmask of reserved gpios
 * @param ngpios  number of GPIOs
 * @see GPIO_DT_RESERVED_RANGES()
 */
#define GPIO_DT_INST_RESERVED_RANGES_NGPIOS(inst, ngpios)		       \
		GPIO_DT_RESERVED_RANGES_NGPIOS(DT_DRV_INST(inst), ngpios)

/**
 * @brief Make a bitmask of reserved GPIOs from a DT_DRV_COMPAT instance's GPIO
 *        @p "gpio-reserved-ranges" and @p "ngpios" properties
 *
 * @param inst DT_DRV_COMPAT instance number
 * @return the bitmask of reserved gpios
 * @see GPIO_DT_RESERVED_RANGES()
 */
#define GPIO_DT_INST_RESERVED_RANGES(inst)				       \
		GPIO_DT_RESERVED_RANGES(DT_DRV_INST(inst))

/**
 * @brief Makes a bitmask of allowed GPIOs from DT @p "gpio-reserved-ranges"
 *        property and @p "ngpios" argument
 *
 * This macro is paired with GPIO_DT_RESERVED_RANGES_NGPIOS(), however unlike
 * the latter, it returns a bitmask of ALLOWED gpios.
 *
 * Example devicetree fragment:
 *
 * @code{.dts}
 *	a {
 *		compatible = "some,gpio-controller";
 *		ngpios = <32>;
 *		gpio-reserved-ranges = <0 8>, <9 5>, <15 16>;
 *	};
 *
 * @endcode
 *
 * Example usage:
 *
 * @code{.c}
 *	struct some_config {
 *		uint32_t port_pin_mask;
 *	};
 *
 *	static const struct some_config dev_cfg = {
 *		.port_pin_mask = GPIO_DT_PORT_PIN_MASK_NGPIOS_EXC(
 *					DT_LABEL(a), 32),
 *	};
 * @endcode
 *
 * This expands to:
 *
 * @code{.c}
 *	struct some_config {
 *		uint32_t port_pin_mask;
 *	};
 *
 *	static const struct some_config dev_cfg = {
 *		.port_pin_mask = 0x80004100,
 *				// 0b1000 0000 0000 0000 0100 0001 00000 000
 *	};
 * @endcode
 *
 * @param node_id GPIO controller node identifier.
 * @param ngpios  number of GPIOs
 * @return the bitmask of allowed gpios
 */
#define GPIO_DT_PORT_PIN_MASK_NGPIOS_EXC(node_id, ngpios)		       \
	((gpio_port_pins_t)						       \
	COND_CODE_0(ngpios,						       \
		(0),							       \
		(COND_CODE_1(DT_NODE_HAS_PROP(node_id, gpio_reserved_ranges),  \
			((GENMASK64(ngpios - 1, 0) &			       \
			~GPIO_DT_RESERVED_RANGES_NGPIOS(node_id, ngpios))),    \
			(GENMASK64(ngpios - 1, 0)))			       \
		)							       \
	))

/**
 * @brief Makes a bitmask of allowed GPIOs from a DT_DRV_COMPAT instance's
 *        @p "gpio-reserved-ranges" property and @p "ngpios" argument
 *
 * @param inst DT_DRV_COMPAT instance number
 * @param ngpios number of GPIOs
 * @return the bitmask of allowed gpios
 * @see GPIO_DT_NGPIOS_PORT_PIN_MASK_EXC()
 */
#define GPIO_DT_INST_PORT_PIN_MASK_NGPIOS_EXC(inst, ngpios)	\
		GPIO_DT_PORT_PIN_MASK_NGPIOS_EXC(DT_DRV_INST(inst), ngpios)

/**
 * @brief Maximum number of pins that are supported by `gpio_port_pins_t`.
 */
#define GPIO_MAX_PINS_PER_PORT (sizeof(gpio_port_pins_t) * __CHAR_BIT__)

#endif /* ZEPHYR_INCLUDE_DRIVERS_GPIO_H_ */
