/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <errno.h>
#include <limits.h>
#include <lib/mmio.h>

#include <lib/timeout.h>
#include <debug.h>
#include <lib/utils_def.h>

#include "clk-stm32-core.h"

#define RCC_MP_ENCLRR_OFFSET	0x4

#define TIMEOUT_US_200MS	U(200000)
#define TIMEOUT_US_1S		U(1000000)

/* STM32 MUX API */
size_t stm32_mux_get_parent(struct clk *clk, uint32_t mux_id)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	uintptr_t rcc_base = clk_stm32_get_rcc_base(priv);
	const struct mux_cfg *mux = &priv->muxes[mux_id];
	uint32_t mask = MASK_WIDTH_SHIFT(mux->width, mux->shift);

	return (io_read32(rcc_base + mux->offset) & mask) >> mux->shift;
}

int stm32_mux_set_parent(struct clk_stm32_priv *priv, uint32_t mux_id, uint8_t sel)
{
	uintptr_t rcc_base = clk_stm32_get_rcc_base(priv);
	const struct mux_cfg *mux = &priv->muxes[mux_id];
	uint32_t mask = MASK_WIDTH_SHIFT(mux->width, mux->shift);
	uintptr_t address = rcc_base + mux->offset;

	io_clrsetbits32(address, mask, (sel << mux->shift) & mask);

	if (mux->ready != MUX_NO_RDY)
		return stm32_gate_wait_ready(priv, (uint16_t)mux->ready, true);

	return 0;
}

/* STM32 GATE API */
void stm32_gate_endisable(struct clk_stm32_priv *priv,
			  uint16_t gate_id, bool enable)
{
	uintptr_t rcc_base = clk_stm32_get_rcc_base(priv);
	const struct gate_cfg *gate = &priv->gates[gate_id];
	uintptr_t addr = rcc_base + gate->offset;

	if (enable) {
		if (gate->set_clr)
			io_write32(addr, BIT(gate->bit_idx));
		else
			mmio_setbits_32(addr, BIT(gate->bit_idx));
	} else {
		if (gate->set_clr)
			io_write32(addr + RCC_MP_ENCLRR_OFFSET,
				   BIT(gate->bit_idx));
		else
			mmio_clrbits_32(addr, BIT(gate->bit_idx));
	}
	__ISB();
}

void stm32_gate_disable(struct clk_stm32_priv *priv, uint16_t gate_id)
{
	uint8_t *gate_cpt = priv->gate_cpt;

	if (--gate_cpt[gate_id] > 0)
		return;

	stm32_gate_endisable(priv, gate_id, false);
}

void stm32_gate_enable(struct clk_stm32_priv *priv, uint16_t gate_id)
{
	uint8_t *gate_cpt = priv->gate_cpt;

	if (gate_cpt[gate_id]++ > 0)
		return;

	stm32_gate_endisable(priv, gate_id, true);
}

bool stm32_gate_is_enabled(struct clk_stm32_priv *priv, uint16_t gate_id)
{
	const struct gate_cfg *gate = &priv->gates[gate_id];
	uintptr_t addr = clk_stm32_get_rcc_base(priv) + gate->offset;

	return (io_read32(addr) & BIT(gate->bit_idx)) != 0U;
}

int stm32_gate_wait_ready(struct clk_stm32_priv *priv,
			  uint16_t gate_id, bool ready_on)
{
	const struct gate_cfg *gate = &priv->gates[gate_id];
	uintptr_t address = clk_stm32_get_rcc_base(priv) + gate->offset;
	uint32_t mask_rdy = BIT(gate->bit_idx);
	uint64_t timeout = timeout_init_us(TIMEOUT_US_1S);
	uint32_t mask = 0U;

	if (ready_on)
		mask = BIT(gate->bit_idx);

	while ((io_read32(address) & mask_rdy) != mask)
		if (timeout_elapsed(timeout))
			break;

	if ((io_read32(address) & mask_rdy) != mask)
		return -1;

	return 0;
}

/* STM32 GATE READY clock operators */
int stm32_gate_ready_endisable(struct clk_stm32_priv *priv,
			       uint16_t gate_id, bool enable,
			       bool wait_rdy)
{
	stm32_gate_endisable(priv, gate_id, enable);

	if (wait_rdy)
		return stm32_gate_wait_ready(priv, gate_id + 1, enable);

	return 0;
}

int stm32_gate_rdy_enable(struct clk_stm32_priv *priv, uint16_t gate_id)
{
	return stm32_gate_ready_endisable(priv, gate_id, true, true);
}

int stm32_gate_rdy_disable(struct clk_stm32_priv *priv, uint16_t gate_id)
{
	return stm32_gate_ready_endisable(priv, gate_id, false, true);
}

/* STM32 DIV API */
static unsigned int _get_table_div(const struct div_table_cfg *table,
				   unsigned int val)
{
	const struct div_table_cfg *clkt = NULL;

	for (clkt = table; clkt->div; clkt++)
		if (clkt->val == val)
			return clkt->div;

	return 0;
}

static unsigned int _get_table_val(const struct div_table_cfg *table,
				   unsigned int div)
{
	const struct div_table_cfg *clkt = NULL;

	for (clkt = table; clkt->div; clkt++)
		if (clkt->div == div)
			return clkt->val;

	return 0;
}

static unsigned int _get_div(const struct div_table_cfg *table,
			     unsigned int val, unsigned long flags,
			     uint8_t width)
{
	if (flags & CLK_DIVIDER_ONE_BASED)
		return val;

	if (flags & CLK_DIVIDER_POWER_OF_TWO)
		return BIT(val);

	if (flags & CLK_DIVIDER_MAX_AT_ZERO)
		return (val != 0U) ? val : BIT(width);

	if (table)
		return _get_table_div(table, val);

	return val + 1U;
}

static unsigned int _get_val(const struct div_table_cfg *table,
			     unsigned int div, unsigned long flags,
			     uint8_t width)
{
	if (flags & CLK_DIVIDER_ONE_BASED)
		return div;

	if (flags & CLK_DIVIDER_POWER_OF_TWO)
		return __builtin_ffs(div) - 1;

	if (flags & CLK_DIVIDER_MAX_AT_ZERO)
		return (div != 0U) ? div : BIT(width);

	if (table)
		return _get_table_val(table, div);

	return div - 1U;
}

static bool _is_valid_table_div(const struct div_table_cfg *table,
				unsigned int div)
{
	const struct div_table_cfg *clkt = NULL;

	for (clkt = table; clkt->div; clkt++)
		if (clkt->div == div)
			return true;

	return false;
}

static bool _is_valid_div(const struct div_table_cfg *table,
			  unsigned int div, unsigned long flags)
{
	if (flags & CLK_DIVIDER_POWER_OF_TWO)
		return IS_POWER_OF_TWO(div);

	if (table)
		return _is_valid_table_div(table, div);

	return true;
}

static int divider_get_val(unsigned long rate, unsigned long parent_rate,
			   const struct div_table_cfg *table, uint8_t width,
			   unsigned long flags)
{
	unsigned int div = 0U;
	unsigned int value = 0U;

	div =  div_round_up((uint64_t)parent_rate, rate);

	if (!_is_valid_div(table, div, flags))
		return -1;

	value = _get_val(table, div, flags, width);

	return MIN(value, (unsigned int)MASK_WIDTH_SHIFT(width, 0));
}

uint32_t stm32_div_get_value(struct clk_stm32_priv *priv, int div_id)
{
	const struct div_cfg *divider = &priv->div[div_id];
	uint32_t val = 0;

	val = io_read32(clk_stm32_get_rcc_base(priv) + divider->offset) >> divider->shift;
	val &= MASK_WIDTH_SHIFT(divider->width, 0);

	return val;
}

int stm32_div_set_value(struct clk_stm32_priv *priv,
			uint32_t div_id, uint32_t value)
{
	const struct div_cfg *divider = NULL;
	uintptr_t address = 0;
	uint32_t mask = 0;

	if (div_id >= priv->nb_div)
		panic();

	divider = &priv->div[div_id];
	address = clk_stm32_get_rcc_base(priv) + divider->offset;

	mask = MASK_WIDTH_SHIFT(divider->width, divider->shift);
	io_clrsetbits32(address, mask, (value << divider->shift) & mask);

	if (divider->ready == DIV_NO_RDY)
		return 0;

	return stm32_gate_wait_ready(priv, (uint16_t)divider->ready, true);
}

unsigned long stm32_div_get_rate(struct clk_stm32_priv *priv,
				 int div_id, unsigned long prate)
{
	const struct div_cfg *divider = &priv->div[div_id];
	uint32_t val = stm32_div_get_value(priv, div_id);
	unsigned int div = 0U;

	div = _get_div(divider->table, val, divider->flags, divider->width);
	if (!div)
		return prate;

	return div_round_up((uint64_t)prate, div);
}

int stm32_div_set_rate(struct clk_stm32_priv *priv,
		       int div_id, unsigned long rate, unsigned long prate)
{
	const struct div_cfg *divider = &priv->div[div_id];
	int value = 0;

	value = divider_get_val(rate, prate, divider->table,
				divider->width, divider->flags);

	if (value < 0)
		return -1;

	return stm32_div_set_value(priv, div_id, value);
}

/* STM32 MUX clock operators */
static size_t clk_stm32_mux_get_parent(struct clk *clk)
{
	struct clk_stm32_mux_cfg *cfg = clk->priv;

	return stm32_mux_get_parent(clk, cfg->mux_id);
}

static int clk_stm32_mux_set_parent(struct clk *clk, size_t pidx)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_mux_cfg *cfg = clk->priv;

	return stm32_mux_set_parent(priv, cfg->mux_id, pidx);
}

struct clk *stm32_clk_get(const struct device *dev, clk_subsys_t sys)
{
	struct clk_stm32_priv *priv = dev_get_data(dev);
	uint32_t clock_id = (uint32_t)sys;

	if (clock_id > priv->nb_clk_refs)
		return NULL;

	return priv->clk_refs[clock_id];
}

const struct clk_ops clk_stm32_mux_ops = {
	.get_parent	= clk_stm32_mux_get_parent,
	.set_parent	= clk_stm32_mux_set_parent,
};

const struct clk_ops clk_stm32_mux_ro_ops = {
	.get_parent	= clk_stm32_mux_get_parent,
};

/* STM32 GATE clock operators */
int clk_stm32_gate_enable(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_gate_cfg *cfg = clk->priv;

	stm32_gate_enable(priv, cfg->gate_id);

	return 0;
}

void clk_stm32_gate_disable(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_gate_cfg *cfg = clk->priv;

	stm32_gate_disable(priv, cfg->gate_id);
}

bool clk_stm32_gate_is_enabled(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_gate_cfg *cfg = clk->priv;

	return stm32_gate_is_enabled(priv, cfg->gate_id);
}

const struct clk_ops clk_stm32_gate_ops = {
	.enable		= clk_stm32_gate_enable,
	.disable	= clk_stm32_gate_disable,
	.is_enabled	= clk_stm32_gate_is_enabled,
};

int clk_stm32_gate_ready_enable(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_gate_cfg *cfg = clk->priv;

	return stm32_gate_rdy_enable(priv, cfg->gate_id);
}

void clk_stm32_gate_ready_disable(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_gate_cfg *cfg = clk->priv;

	if (stm32_gate_rdy_disable(priv, cfg->gate_id))
		panic();
}

const struct clk_ops clk_stm32_gate_ready_ops = {
	.enable		= clk_stm32_gate_ready_enable,
	.disable	= clk_stm32_gate_ready_disable,
	.is_enabled	= clk_stm32_gate_is_enabled,
};

/* STM32 DIV clock operators */
unsigned long clk_stm32_divider_get_rate(struct clk *clk,
					 unsigned long parent_rate)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_div_cfg *cfg = clk->priv;

	return stm32_div_get_rate(priv, cfg->div_id, parent_rate);
}

int clk_stm32_divider_set_rate(struct clk *clk,
				      unsigned long rate,
				      unsigned long parent_rate)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_div_cfg *cfg = clk->priv;

	return stm32_div_set_rate(priv, cfg->div_id, rate, parent_rate);
}

const struct clk_ops clk_stm32_divider_ops = {
	.get_rate	= clk_stm32_divider_get_rate,
	.set_rate	= clk_stm32_divider_set_rate,
};

/* STM32 COMPOSITE clock operators */
size_t clk_stm32_composite_get_parent(struct clk *clk)
{
	struct clk_stm32_composite_cfg *cfg = clk->priv;

	if (cfg->mux_id == NO_MUX) {
		/* It could be a normal case */
		return 0;
	}

	return stm32_mux_get_parent(clk, cfg->mux_id);
}

int clk_stm32_composite_set_parent(struct clk *clk, size_t pidx)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_composite_cfg *cfg = clk->priv;

	if (cfg->mux_id == NO_MUX)
		panic();

	return stm32_mux_set_parent(priv, cfg->mux_id, pidx);
}

unsigned long clk_stm32_composite_get_rate(struct clk *clk,
					   unsigned long parent_rate)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_composite_cfg *cfg = clk->priv;

	if (cfg->div_id == NO_DIV)
		return parent_rate;

	return stm32_div_get_rate(priv, cfg->div_id, parent_rate);
}

int clk_stm32_composite_set_rate(struct clk *clk, unsigned long rate,
					unsigned long parent_rate)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_composite_cfg *cfg = clk->priv;

	if (cfg->div_id == NO_DIV)
		return 0;

	return stm32_div_set_rate(priv, cfg->div_id, rate, parent_rate);
}

int clk_stm32_composite_gate_enable(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_composite_cfg *cfg = clk->priv;

	stm32_gate_enable(priv, cfg->gate_id);

	return 0;
}

void clk_stm32_composite_gate_disable(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_composite_cfg *cfg = clk->priv;

	stm32_gate_disable(priv, cfg->gate_id);
}

bool clk_stm32_composite_gate_is_enabled(struct clk *clk)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk));
	struct clk_stm32_composite_cfg *cfg = clk->priv;

	return stm32_gate_is_enabled(priv, cfg->gate_id);
}

const struct clk_ops clk_stm32_composite_ops = {
	.get_parent	= clk_stm32_composite_get_parent,
	.set_parent	= clk_stm32_composite_set_parent,
	.get_rate	= clk_stm32_composite_get_rate,
	.set_rate	= clk_stm32_composite_set_rate,
	.enable		= clk_stm32_composite_gate_enable,
	.disable	= clk_stm32_composite_gate_disable,
	.is_enabled	= clk_stm32_composite_gate_is_enabled,
};

int clk_stm32_set_parent_by_index(struct clk *clk, size_t pidx)
{
	struct clk *parent = clk_get_parent_by_index(clk, pidx);
	int res = -1;

	if (parent)
		res = clk_set_parent(clk, parent);

	return res;
}

static unsigned long fixed_factor_get_rate(struct clk *clk,
					   unsigned long parent_rate)
{
	struct fixed_factor_cfg *d = clk->priv;

	unsigned long long rate = (unsigned long long)parent_rate * d->mult;

	if (d->div == 0U) {
		EMSG("error division by zero\n");
		panic();
	}

	return (unsigned long)(rate / d->div);
};

const struct clk_ops clk_fixed_factor_ops = {
	.get_rate	= fixed_factor_get_rate,
};

static unsigned long clk_fixed_get_rate(struct clk *clk,
					unsigned long parent_rate __unused)
{
	struct clk_fixed_rate_cfg *cfg = clk->priv;

	return cfg->rate;
}

const struct clk_ops clk_fixed_clk_ops = {
	.get_rate	= clk_fixed_get_rate,
};

#if STM32_CLK_DBG
static void clk_stm32_display_tree(struct clk *clk, int indent)
{
	unsigned long rate;
	const char *name;
	int counter = clk->enabled_count;
	int i;
	int state;

	name = clk_get_name(clk);
	rate = clk_get_rate(clk);

	state = clk->ops->is_enabled ? clk->ops->is_enabled(clk) : (counter > 0);

	printf("%d %s ", counter, state ? "Y" : "N");

	for (i = 0; i < indent * 4; i++) {
		if ((i % 4) != 0)
			printf("-");
		else
			printf("|");
	}

	if (i != 0)
		printf(" ");

	printf("%s (%d)\n\r", name ? name : "noname", rate);
}

static void clk_stm32_tree(struct clk *clk_root, int indent)
{
	struct clk_stm32_priv *priv = dev_get_data(clk_get_dev(clk_root));
	unsigned int i = 0;

	for (i = 0; i < priv->nb_clk_refs; i++) {
		struct clk *clk = priv->clk_refs[i];

		if (!clk)
			continue;
		if (clk_get_parent(clk) == clk_root) {
			clk_stm32_display_tree(clk, indent + 1);
			clk_stm32_tree(clk, indent + 1);
		}
	}
}

void clk_stm32_display_clock_summary(struct device *dev)
{
	struct clk_stm32_priv *priv = dev_get_data(dev);
	unsigned int i = 0;

	for (i = 0; i < priv->nb_clk_refs; i++) {
		struct clk *clk = priv->clk_refs[i];

		if (!clk)
			continue;

		if (clk_get_parent(clk))
			continue;

		clk_stm32_display_tree(clk, 0);

		clk_stm32_tree(clk, 0);
	}
}
#endif

#ifdef CONFIG_PM_DEVICE
int clk_stm32_save_context(const struct device *dev)
{
	struct clk_stm32_priv *priv = (struct clk_stm32_priv *)dev_get_data(dev);
	unsigned int i = 0;
	int err = 0;

	for (i = 0; i < priv->nb_clk_refs; i++) {
		struct clk *clk = priv->clk_refs[i];

		if (!clk)
			continue;

		err = clk_save_context(clk);
		if (err) {
			EMSG("[%s] failed to save context of clock %d\n",
			     __func__, i);
			return err;
		}
	}

	return 0;
}

void clk_stm32_restore_context(const struct device *dev)
{
	struct clk_stm32_priv *priv = (struct clk_stm32_priv *)dev_get_data(dev);
	unsigned int i = 0;

	for (i = 0; i < priv->nb_clk_refs; i++) {
		struct clk *clk = priv->clk_refs[i];

		if (!clk)
			continue;

		clk_restore_context(clk);
	}
}
#endif

struct clk *stm32mp_rcc_clock_id_to_clk(struct clk_stm32_priv *priv, unsigned long clock_id)
{
	if (clock_id > priv->nb_clk_refs)
		return NULL;

	return priv->clk_refs[clock_id];
}

void clk_stm32_register_clocks(struct clk_stm32_priv *priv)
{
	unsigned int i = 0;

	for (i = 0; i < priv->nb_clk_refs; i++) {
		struct clk *clk = priv->clk_refs[i];

		if (!clk)
			continue;

		clk->enabled_count = 0;

		if (clk_register(clk))
			panic();
	}

	for (i = 0; i < priv->nb_clk_refs; i++) {
		struct clk *clk = priv->clk_refs[i];

		if (!clk)
			continue;

		if (priv->is_critical && priv->is_critical(clk))
			clk_enable(clk);
	}
}
