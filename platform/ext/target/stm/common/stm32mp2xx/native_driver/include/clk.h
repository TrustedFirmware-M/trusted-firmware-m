/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (c) 2021, Bootlin
 */

#ifndef __DRIVERS_CLK_H
#define __DRIVERS_CLK_H

#include <stdbool.h>
#include <limits.h>
#include <stddef.h>
#include <errno.h>

#include <device.h>
#include <config_tfm.h>

#define CLK_UNDEF	ULONG_MAX

/* Flags for clock */
#define CLK_SET_RATE_GATE	BIT(0) /* must be gated across rate change */
#define CLK_SET_PARENT_GATE	BIT(1) /* must be gated across re-parent */
#define CLK_OPS_PARENT_ENABLE	BIT(2) /* parent need enable during re-parent */
#define CLK_SET_RATE_PARENT	BIT(3) /* propagate rate change up one level */
#define CLK_SET_RATE_UNGATE	BIT(4) /* clock needs to run to set rate */
#define CLK_DUTY_CYCLE_PARENT	BIT(5) /* forward duty cycle call to parent */

/**
 * struct clk - Clock structure
 *
 * @name: Clock name
 * @dev: reference on device
 * @priv: Private data for the clock provider
 * @ops: Clock operations
 * @parent: Current parent
 * @rate: Current clock rate (cached after init or rate change)
 * @flags: Specific clock flags
 * @enabled_count: Enable/disable reference counter
 * @num_parents: Number of parents
 * @parents: Array of possible parents of the clock
 */
struct clk {
#if !CLK_MINIMAL_SZ
	const char *name;
#endif
	const struct device *dev;
	void *priv;
	const struct clk_ops *ops;
	struct clk *parent;
	unsigned long rate;
	unsigned int flags;
	uint16_t enabled_count;
	uint8_t num_parents;
	struct clk **parents;
};

static inline const struct device * clk_get_dev(struct clk *clk)
{
	return clk->dev;
}

/**
 * struct clk_rate_request
 *
 * @rate:		Requested clock rate. This field will be adjusted by
 *			clock drivers according to hardware capabilities.
 * @best_parent_rate:	The best parent rate a parent can provide to fulfill the
 *			requested constraints.
 * @best_parent:	The most appropriate parent clock that fulfills the
 *			requested constraints.
 *
 */
struct clk_rate_request {
	unsigned long rate;
	unsigned long best_parent_rate;
	struct clk *best_parent;
};

/**
 * struct clk_duty - Struture encoding the duty cycle ratio of a clock
 *
 * @num:	Numerator of the duty cycle ratio
 * @den:	Denominator of the duty cycle ratio
 */
struct clk_duty {
	unsigned int num;
	unsigned int den;
};

/**
 * struct clk_ops
 *
 * @is_enabled: Get status of the clock (on / off)
 * @enable: Enable the clock
 * @disable: Disable the clock
 * @set_parent: Set the clock parent based on index
 * @get_parent: Get the current parent index of the clock
 * @set_rate: Set the clock rate
 * @get_rate: Get the clock rate
 * @save_context: Save the clock context
 * @restore_context: Restore the clock context
 */
struct clk_ops {
	bool (*is_enabled)(struct clk *clk);
	int (*enable)(struct clk *clk);
	void (*disable)(struct clk *clk);
	int (*set_parent)(struct clk *clk, size_t index);
	size_t (*get_parent)(struct clk *clk);
	int (*set_rate)(struct clk *clk, unsigned long rate,
			unsigned long parent_rate);
	unsigned long (*get_rate)(struct clk *clk,
				  unsigned long parent_rate);
	int (*get_rates_array)(struct clk *clk, size_t start_index,
			       unsigned long *rates, size_t *nb_elts);
	int (*get_rates_steps)(struct clk *clk, unsigned long *min,
			       unsigned long *max, unsigned long *step);
	int (*determine_rate)(struct clk *clk,
			      struct clk_rate_request *req);

	int (*get_duty_cycle)(struct clk *clk,
			      struct clk_duty *duty);
	unsigned long (*round_rate)(struct clk *clk,
				    unsigned long rate,
				    unsigned long parent_rate);
	int (*save_context)(struct clk *clk);
	void (*restore_context)(struct clk *clk);
};

/**
 * Return the clock name
 *
 * @clk: Clock for which the name is needed
 * Return a const char * pointing to the clock name or NULL if CLK_MINIMAL_SZ
 */
static inline const char *clk_get_name(struct clk *clk)
{
#if CLK_MINIMAL_SZ
	return NULL;
#else
	return clk->name;
#endif
}

/**
 * clk_alloc - Allocate a clock structure
 *
 * @name: Clock name
 * @ops: Clock operations
 * @parent_clks: Parents of the clock
 * @parent_count: Number of parents of the clock
 *
 * Return a clock struct properly initialized or NULL if allocation failed
 */
struct clk *clk_alloc(const char *name, const struct clk_ops *ops,
		      struct clk **parent_clks, size_t parent_count);

/**
 * clk_free - Free a clock structure
 *
 * @clk: Clock to be freed or NULL
 */
void clk_free(struct clk *clk);

/**
 * clk_register - Register a clock within the clock framework
 *
 * @clk: Clock struct to be registered
 * Return a int compliant value
 */
int clk_register(struct clk *clk);

/**
 * clk_get_rate - Get clock rate
 *
 * @clk: Clock for which the rate is needed
 * Return the clock rate in Hz
 */
unsigned long clk_get_rate(struct clk *clk);

/**
 * clk_set_rate - Set a clock rate
 *
 * @clk: Clock to be set with the rate
 * @rate: Rate to set in Hz
 * Return a int compliant value
 */
int clk_set_rate(struct clk *clk, unsigned long rate);

/**
 * clk_enable - Enable a clock and its ascendance
 *
 * @clk: Clock to be enabled
 * Return a int compliant value
 */
int clk_enable(struct clk *clk);

/**
 * clk_disable - Disable a clock
 *
 * @clk: Clock to be disabled
 */
void clk_disable(struct clk *clk);

/**
 * clk_is_enabled - Informative state on the clock
 *
 * This function is useful during specific system sequences where core
 * executes atomically (primary core boot, some low power sequences).
 *
 * @clk: Clock refernece
 */
bool clk_is_enabled(struct clk *clk);

/**
 * clk_get_parent - Get the current clock parent
 *
 * @clk: Clock for which the parent is needed
 * Return the clock parent or NULL if there is no parent
 */
struct clk *clk_get_parent(struct clk *clk);

/**
 * clk_get_num_parents - Get the number of parents for a clock
 *
 * @clk: Clock for which the number of parents is needed
 * Return the number of parents
 */
static inline size_t clk_get_num_parents(struct clk *clk)
{
	return clk->num_parents;
}

/**
 * Get a clock parent by its index
 *
 * @clk: Clock for which the parent is needed
 * @pidx: Parent index for the clock
 * Return the clock parent at index @pidx or NULL if out of bound
 */
struct clk *clk_get_parent_by_index(struct clk *clk, size_t pidx);

int clk_get_parent_idx(struct clk *clk, struct clk *parent, size_t *pidx);

/**
 * clk_set_parent - Set the current clock parent
 *
 * @clk: Clock for which the parent should be set
 * @parent: Parent clock to set
 * Return a int compliant value
 */
int clk_set_parent(struct clk *clk, struct clk *parent);

/**
 * clk_reparent - Update clock parent under spinlock
 *
 * @clk: Clock for which the parent should be set
 * @parent: Parent clock to set
 * Return a int compliant value
 */
int clk_reparent(struct clk *clk, struct clk *parent);

/**
 * clk_get_duty_cycle - Get clock duty cycle
 *
 * @clk: Clock for which the duty cycle is needed
 * Returns the duty cycle structure
 */
int clk_get_duty_cycle(struct clk *clk, struct clk_duty *duty);

/**
 * clk_round_rate - Round the given rate for a clock
 * @clk: Clock for which the round rate is need
 * @rate: The rate which is to be rounded
 * Returns the closest rate actually supported by the clock.
 */
unsigned long clk_round_rate(struct clk *clk, unsigned long rate);

/**
 * clk_get_rates_array - Get supported rates as an increasing frequencies array
 *
 * @clk: Clock for which the rates are requested
 * @start_index: start index of requested rates
 * @rates: Array of rates allocated by caller or NULL to query count of rates
 * @nb_elts: Max number of elements that the array can hold as input. Contains
 * the number of elements that was added in the array as output.
 * Returns a int compliant value
 */
int clk_get_rates_array(struct clk *clk, size_t start_index,
			       unsigned long *rates, size_t *nb_elts);

/* clock controller */

/**
 * clk_subsys_t is a type to identify a clock sub-system.
 * Such data pointed is opaque and relevant only to the clock controller
 * driver instance being used.
 */
typedef void *clk_subsys_t;

struct clk_controller_api {
	struct clk *(*get)(const struct device *dev, clk_subsys_t sys);
};

/**
 * clk_get - Return clock struct identified by device and clk_subsys_t
 * @dev Device structure whose driver controls the clock.
 * @sys Opaque data representing the clock.
 *
 * Return Null if error else clock reference
 */
struct clk *clk_get(const struct device *dev, clk_subsys_t sys);

/**
 * clk_get_rates_steps - Get supported rates as min/max/step triplet
 *
 * @clk: Clock for which the rates are requested
 * @min: Output min supported rate in Hz
 * @max: Output max supported rate in Hz
 * Return a int compliant value
 */
int clk_get_rates_steps(struct clk *clk, unsigned long *min,
                        unsigned long *max, unsigned long *step);

/**
 * clk_save_context - save clock context for a clock
 *
 * Saves the context of the clock register for powerstates in which the
 * contents of the registers will be lost. Occurs deep within the suspend
 * code.
 */
int clk_save_context(struct clk *clk);

/**
 * clk_restore_context - restore context of a clock after poweroff
 *
 * Restore the saved clock context upon resume.
 *
 */
void clk_restore_context(struct clk *clk);

#endif /* __DRIVERS_CLK_H */
