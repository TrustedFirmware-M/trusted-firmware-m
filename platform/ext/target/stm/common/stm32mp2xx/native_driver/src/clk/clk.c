// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2021, Bootlin
 * Copyright (c) 2023, STMicroelectronics
 *
 * Inspired from OP-TEE
 */

#include <assert.h>
#include <clk.h>
#include <debug.h>

static bool clk_check(struct clk *clk)
{
	if (!clk->ops)
		return false;

	if (clk->ops->set_parent && !clk->ops->get_parent)
		return false;

	if (clk->num_parents > 1 && !clk->ops->get_parent)
		return false;

	return true;
}

static void clk_compute_rate_no_lock(struct clk *clk)
{
	unsigned long parent_rate = 0;

	if (clk->parent)
		parent_rate = clk->parent->rate;

	if (clk->ops->get_rate)
		clk->rate = clk->ops->get_rate(clk, parent_rate);
	else
		clk->rate = parent_rate;
}

struct clk *clk_get_parent_by_index(struct clk *clk, size_t pidx)
{
	if (pidx >= clk->num_parents)
		return NULL;

	return clk->parents[pidx];
}

static void clk_init_parent(struct clk *clk)
{
	size_t pidx = 0;

	switch (clk->num_parents) {
	case 0:
		break;
	case 1:
		clk->parent = clk->parents[0];
		break;
	default:
		pidx = clk->ops->get_parent(clk);

		_ASSERT(pidx < clk->num_parents);

		clk->parent = clk->parents[pidx];
		break;
	}
}

int clk_reparent(struct clk *clk, struct clk *parent)
{
	size_t i = 0;

	if (clk->parent == parent)
		return 0;

	for (i = 0; i < clk_get_num_parents(clk); i++) {
		if (clk_get_parent_by_index(clk, i) == parent) {
			clk->parent = parent;
			return 0;
		}
	}
#if !CLK_MINIMAL_SZ
	EMSG("Clock %s is not a parent of clock %s\n", parent->name, clk->name);
#endif

	return -1;
}

int clk_register(struct clk *clk)
{
	_ASSERT(clk_check(clk));

	clk_init_parent(clk);
	clk_compute_rate_no_lock(clk);
#if !CLK_MINIMAL_SZ
	DMSG("Registered clock %s, freq %lu\n", clk->name, clk_get_rate(clk));
#endif
	return 0;
}

static bool clk_is_enabled_no_lock(struct clk *clk)
{
	return clk->enabled_count != 0;
}

bool clk_is_enabled(struct clk *clk)
{
	return clk_is_enabled_no_lock(clk);
}

static void clk_disable_no_lock(struct clk *clk)
{
	struct clk *parent = NULL;

	_ASSERT(clk->enabled_count);

	if (--clk->enabled_count)
		return;

	if (clk->ops->disable)
		clk->ops->disable(clk);

	parent = clk_get_parent(clk);
	if (parent)
		clk_disable_no_lock(parent);
}

static int clk_enable_no_lock(struct clk *clk)
{
	int res = -1;
	struct clk *parent = NULL;

	if (clk->enabled_count++)
		return 0;

	parent = clk_get_parent(clk);
	if (parent) {
		res = clk_enable_no_lock(parent);
		if (res)
			return res;
	}

	if (clk->ops->enable) {
		res = clk->ops->enable(clk);
		if (res) {
			if (parent)
				clk_disable_no_lock(parent);

			return res;
		}
	}

	return 0;
}

int clk_enable(struct clk *clk)
{
	int res = -1;

	res = clk_enable_no_lock(clk);

	return res;
}

void clk_disable(struct clk *clk)
{
	clk_disable_no_lock(clk);
}

unsigned long clk_get_rate(struct clk *clk)
{
	unsigned long rate = clk->rate;

	if (clk->ops->get_rate) {
		unsigned long parent_rate =  0UL;

		if (clk->parent)
			parent_rate = clk_get_rate(clk->parent);

		return clk->ops->get_rate(clk, parent_rate);
	}

	if (clk->parent)
		rate = clk_get_rate(clk->parent);

	return rate;
}

struct clk *clk_get_parent(struct clk *clk)
{
	return clk->parent;
}

int clk_get_parent_idx(struct clk *clk, struct clk *parent,
				     size_t *pidx)
{
	size_t i = 0;

	for (i = 0; i < clk_get_num_parents(clk); i++) {
		if (clk_get_parent_by_index(clk, i) == parent) {
			*pidx = i;
			return 0;
		}
	}
#if !CLK_MINIMAL_SZ
	EMSG("Clock %s is not a parent of clock %s\n", parent->name, clk->name);
#endif
	return -1;
}

static int clk_set_parent_no_lock(struct clk *clk, struct clk *parent,
					 size_t pidx)
{
	struct clk *old_parent = clk->parent;
	int res = -1;
	bool was_enabled = false;

	/* Requested parent is already the one set */
	if (clk->parent == parent)
		return 0;

	was_enabled = clk_is_enabled_no_lock(clk);

	if (clk->flags & CLK_OPS_PARENT_ENABLE) {
		res = clk_enable_no_lock(parent);
		if (res) {
			EMSG("Failed to re-enable clock after setting parent\n");
			panic();
		}

		res = clk_enable_no_lock(old_parent);
		if (res) {
			EMSG("Failed to re-enable clock after setting parent\n");
			panic();
		}
	}

	res = clk->ops->set_parent(clk, pidx);
	if (res)
		goto out;

	clk->parent = parent;

	/* The parent changed and the rate might also have changed */
	clk_compute_rate_no_lock(clk);

	/* Call is needed to decrement refcount on current parent tree */
	if (was_enabled) {
		res = clk_enable_no_lock(parent);
		if (res) {
			EMSG("Failed to re-enable clock after setting parent\n");
			panic();
		}

		clk_disable_no_lock(old_parent);
	}
out:
	if (clk->flags & CLK_OPS_PARENT_ENABLE) {
		clk_disable_no_lock(old_parent);
		clk_disable_no_lock(parent);
	}

	return res;
}

int clk_set_parent(struct clk *clk, struct clk *parent)
{
	size_t pidx = 0;
	int res = -1;

	if (clk_get_parent_idx(clk, parent, &pidx) || !clk->ops->set_parent)
		return -1;

	if (clk->flags & CLK_SET_PARENT_GATE && clk_is_enabled_no_lock(clk)) {
		res = -1;
		goto out;
	}

	res = clk_set_parent_no_lock(clk, parent, pidx);
out:

	return res;
}

static void clk_init_rate_req(struct clk *clk,
			      struct clk_rate_request *req)
{
	struct clk *parent = clk->parent;

	if (parent) {
		req->best_parent = parent;
		req->best_parent_rate = parent->rate;
	} else {
		req->best_parent = NULL;
		req->best_parent_rate = 0;
	}
}

static int clk_set_rate_no_lock(struct clk *clk, unsigned long rate)
{
	int res = 0;
	unsigned long parent_rate = 0;
	unsigned long new_rate = rate;
	struct clk *parent = clk->parent;

	if (parent)
		parent_rate = parent->rate;

	/* find the closest rate and parent clk/rate */
	if (clk->ops->determine_rate) {
		struct clk_rate_request req;
		struct clk *old_parent = clk->parent;

		req.rate = rate;

		clk_init_rate_req(clk, &req);

		res = clk->ops->determine_rate(clk, &req);
		if (res)
			return res;

		parent_rate = req.best_parent_rate;
		new_rate = req.rate;
		parent = req.best_parent;

		res = clk_set_rate_no_lock(parent, parent_rate);

		if (parent && parent != old_parent) {
			if (parent && clk->num_parents > 1) {
				size_t pidx = 0;

				if (clk_get_parent_idx(clk, parent, &pidx))
					return -1;

				res = clk_set_parent_no_lock(clk, parent, pidx);
				if (res)
					return res;
				clk->parent = parent;
			}
		}
	} else if (!parent || !(clk->flags & CLK_SET_RATE_PARENT)) {
		/* pass-through clock without adjustable parent */
		new_rate  = rate;
	} else {
		/* pass-through clock with adjustable parent */
		res = clk_set_rate_no_lock(parent, rate);
		if (res)
			return res;
		new_rate = parent->rate;
	}

	if (clk->ops->set_rate) {
		if (clk->flags & CLK_SET_RATE_UNGATE)
			clk_enable_no_lock(clk);

		res = clk->ops->set_rate(clk, new_rate, parent_rate);

		if (clk->flags & CLK_SET_RATE_UNGATE)
			clk_disable_no_lock(clk);

		if (res)
			return res;
	}

	clk_compute_rate_no_lock(clk);

	return res;
}

int clk_set_rate(struct clk *clk, unsigned long rate)
{
	int res = -1;

	/* bail early if nothing to do */
	if (rate == clk_get_rate(clk))
		return 0;

	if (clk->flags & CLK_SET_RATE_GATE && clk_is_enabled_no_lock(clk))
		res = -1;
	else
		res = clk_set_rate_no_lock(clk, rate);

	return res;
}

int clk_get_duty_cycle(struct clk *clk, struct clk_duty *duty)
{
	if (clk->ops->get_duty_cycle)
		return clk->ops->get_duty_cycle(clk, duty);

	if (clk->parent && (clk->flags & CLK_DUTY_CYCLE_PARENT))
		return clk_get_duty_cycle(clk->parent, duty);

	return -1;
}

unsigned long clk_round_rate(struct clk *clk, unsigned long rate)
{
	if (clk->ops->round_rate)
		return clk->ops->round_rate(clk, rate, clk->parent->rate);

	return -1;
}

struct clk *clk_get(const struct device *dev, clk_subsys_t sys)
{
	const struct clk_controller_api *api = dev->api;

	return api->get(dev, sys);
}

int clk_get_rates_array(struct clk *clk, size_t start_index,
			       unsigned long *rates, size_t *nb_elts)
{
	if (!clk->ops->get_rates_array)
		return -ENOENT;

	return clk->ops->get_rates_array(clk, start_index, rates, nb_elts);
}

int  clk_get_rates_steps(struct clk *clk, unsigned long *min,
			       unsigned long *max, unsigned long *step)
{
	if (!clk->ops->get_rates_steps)
		return -ENOENT;

	return clk->ops->get_rates_steps(clk, min, max, step);
}

int clk_save_context(struct clk *clk)
{
	if (clk->ops->save_context)
		return clk->ops->save_context(clk);

	return 0;
}

void clk_restore_context(struct clk *clk)
{
	if (clk->ops->restore_context)
		clk->ops->restore_context(clk);
}
