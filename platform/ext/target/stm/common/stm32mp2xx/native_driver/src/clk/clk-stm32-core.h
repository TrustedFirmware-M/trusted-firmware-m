/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef CLK_STM32_CORE_H
#define CLK_STM32_CORE_H

#include <clk.h>
#include <stm32_rifsc.h>

struct mux_cfg {
	uint16_t offset;
	uint8_t shift;
	uint8_t width;
	uint8_t ready;
};

struct gate_cfg {
	uint16_t offset;
	uint8_t bit_idx;
	uint8_t set_clr;
};

struct div_table_cfg {
	unsigned int val;
	unsigned int div;
};

struct div_cfg {
	uint16_t offset;
	uint8_t shift;
	uint8_t width;
	uint8_t flags;
	uint8_t ready;
	const struct div_table_cfg *table;
};

struct stm32_rcc_config {
	uintptr_t base;
	const uint32_t c1msrd;
	const struct stm32_osci_dt_cfg *osci;
	const uint32_t nosci;
	const struct stm32_pll_dt_cfg *pll;
	const uint32_t npll;
	const uint32_t *busclk;
	const uint32_t nbusclk;
	const uint32_t *kernelclk;
	const uint32_t nkernelclk;
	const uint32_t *flexgen;
	const uint32_t nflexgen;
	const struct rifprot_controller *rif_ctl;
};

struct clk_stm32_priv {
	const struct stm32_rcc_config *rcc_cfg;
	size_t nb_clk_refs;
	struct clk **clk_refs;
	const struct mux_cfg *muxes;
	const uint32_t nb_muxes;
	const struct gate_cfg *gates;
	uint8_t *gate_cpt;
	const uint32_t nb_gates;
	const struct div_cfg *div;
	const uint32_t nb_div;
	bool clk_ignore_unused;
	bool (*is_ignore_unused)(struct clk *clk);
	bool (*is_critical)(struct clk *clk);
};

static inline uintptr_t clk_stm32_get_rcc_base(struct clk_stm32_priv *priv)
{
	return priv->rcc_cfg->base;
}

struct clk_fixed_rate_cfg {
	unsigned long rate;
};

struct fixed_factor_cfg {
	unsigned int mult;
	unsigned int div;
};

struct clk_gate_cfg {
	uint32_t offset;
	uint8_t bit_idx;
};

struct clk_stm32_mux_cfg {
	int mux_id;
};

struct clk_stm32_gate_cfg {
	int gate_id;
};

struct clk_stm32_div_cfg {
	int div_id;
};

struct clk_stm32_composite_cfg {
	int gate_id;
	int div_id;
	int mux_id;
};

struct clk_stm32_timer_cfg {
	uint32_t apbdiv;
	uint32_t timpre;
};

struct clk_stm32_gate_ready_cfg {
	int gate_id;
	int gate_rdy_id;
};

/* Define for divider clocks */
#define CLK_DIVIDER_ONE_BASED		BIT(0)
#define CLK_DIVIDER_POWER_OF_TWO	BIT(1)
#define CLK_DIVIDER_ALLOW_ZERO		BIT(2)
#define CLK_DIVIDER_HIWORD_MASK		BIT(3)
#define CLK_DIVIDER_ROUND_CLOSEST	BIT(4)
#define CLK_DIVIDER_READ_ONLY		BIT(5)
#define CLK_DIVIDER_MAX_AT_ZERO		BIT(6)
#define CLK_DIVIDER_BIG_ENDIAN		BIT(7)

#define DIV_NO_RDY		UINT8_MAX
#define MUX_NO_RDY		UINT8_MAX

#define MASK_WIDTH_SHIFT(_width, _shift) \
	GENMASK_32(((_width) + (_shift) - 1U), (_shift))

/* Define for composite clocks */
#define NO_MUX		INT32_MAX
#define NO_DIV		INT32_MAX
#define NO_GATE		INT32_MAX

void stm32_gate_endisable(struct clk_stm32_priv *priv,
			  uint16_t gate_id, bool enable);
void stm32_gate_enable(struct clk_stm32_priv *priv,
		       uint16_t gate_id);
void stm32_gate_disable(struct clk_stm32_priv *priv,
			uint16_t gate_id);
bool stm32_gate_is_enabled(struct clk_stm32_priv *priv,
			   uint16_t gate_id);
int stm32_gate_wait_ready(struct clk_stm32_priv *priv,
			  uint16_t gate_id, bool ready_on);
int stm32_gate_rdy_enable(struct clk_stm32_priv *priv,
			  uint16_t gate_id);
int stm32_gate_rdy_disable(struct clk_stm32_priv *priv,
			   uint16_t gate_id);

size_t stm32_mux_get_parent(struct clk *clk, uint32_t mux_id);
int stm32_mux_set_parent(struct clk_stm32_priv *priv,
			 uint32_t mux_id, uint8_t sel);

unsigned long stm32_div_get_rate(struct clk_stm32_priv *priv,
				 int div_id, unsigned long prate);
int stm32_div_set_rate(struct clk_stm32_priv *priv,
		       int div_id, unsigned long rate,
		       unsigned long prate);

uint32_t stm32_div_get_value(struct clk_stm32_priv *priv, int div_id);
int stm32_div_set_value(struct clk_stm32_priv *priv,
			uint32_t div_id, uint32_t value);

int clk_stm32_parse_fdt_by_name(const void *fdt, int node, const char *name,
				uint32_t *tab, uint32_t *nb);

int clk_stm32_gate_ready_enable(struct clk *clk);
void clk_stm32_gate_ready_disable(struct clk *clk);
int clk_stm32_gate_enable(struct clk *clk);
void clk_stm32_gate_disable(struct clk *clk);
bool clk_stm32_gate_is_enabled(struct clk *clk);

unsigned long clk_stm32_divider_get_rate(struct clk *clk,
					 unsigned long parent_rate);

int clk_stm32_divider_set_rate(struct clk *clk,
				      unsigned long rate,
				      unsigned long parent_rate);

size_t clk_stm32_composite_get_parent(struct clk *clk);
int clk_stm32_composite_set_parent(struct clk *clk, size_t pidx);
unsigned long clk_stm32_composite_get_rate(struct clk *clk,
					   unsigned long parent_rate);
int clk_stm32_composite_set_rate(struct clk *clk, unsigned long rate,
					unsigned long parent_rate);
int clk_stm32_composite_gate_enable(struct clk *clk);
void clk_stm32_composite_gate_disable(struct clk *clk);
bool clk_stm32_composite_gate_is_enabled(struct clk *clk);

int clk_stm32_set_parent_by_index(struct clk *clk, size_t pidx);

extern const struct clk_ops clk_fixed_factor_ops;
extern const struct clk_ops clk_fixed_clk_ops;
extern const struct clk_ops clk_stm32_gate_ops;
extern const struct clk_ops clk_stm32_gate_ready_ops;
extern const struct clk_ops clk_stm32_divider_ops;
extern const struct clk_ops clk_stm32_mux_ops;
extern const struct clk_ops clk_stm32_composite_ops;

struct clk *stm32mp_rcc_clock_id_to_clk(struct clk_stm32_priv *priv,
					unsigned long clock_id);

#define PARENT(_parent) ((struct clk *[]) { _parent})
#define PARENTS(_parent...) ((struct clk *[]) { _parent })

#if CLK_MINIMAL_SZ
#define CLOCK_NAME(name)
#else
#define CLOCK_NAME(x) .name = (x),
#endif

#define STM32_FIXED_RATE(_name, _rate)\
	struct clk _name = {\
		.ops = &clk_fixed_clk_ops,\
		.priv = &(struct clk_fixed_rate_cfg) {\
			.rate = (_rate),\
		},\
		CLOCK_NAME(#_name)\
		.flags = 0,\
		.num_parents = 0,\
		.dev = DT_RCC_DEVICE,\
	}

#define STM32_FIXED_FACTOR(_name, _parent, _flags, _mult, _div)\
	struct clk _name = {\
		.ops = &clk_fixed_factor_ops,\
		.priv = &(struct fixed_factor_cfg) {\
			.mult = _mult,\
			.div = _div,\
		},\
		CLOCK_NAME(#_name)\
		.flags = (_flags),\
		.num_parents = 1,\
		.parents = PARENT(_parent),\
		.dev = DT_RCC_DEVICE,\
	}

#define STM32_GATE(_name, _parent, _flags, _gate_id)\
	struct clk _name = {\
		.ops = &clk_stm32_gate_ops,\
		.priv = &(struct clk_stm32_gate_cfg) {\
			.gate_id = _gate_id,\
		},\
		CLOCK_NAME(#_name)\
		.flags = (_flags),\
		.num_parents = 1,\
		.parents = PARENT(_parent),\
		.dev = DT_RCC_DEVICE,\
	}

#define STM32_DIVIDER(_name, _parent, _flags, _div_id)\
	struct clk _name = {\
		.ops = &clk_stm32_divider_ops,\
		.priv = &(struct clk_stm32_div_cfg) {\
			.div_id = (_div_id),\
		},\
		CLOCK_NAME(#_name)\
		.flags = (_flags),\
		.num_parents = 1,\
		.parents = PARENT(_parent),\
		.dev = DT_RCC_DEVICE,\
	}

#define STM32_MUX(_name, _nb_parents, _parents, _flags, _mux_id)\
	struct clk _name = {\
		.ops = &clk_stm32_mux_ops,\
		.priv = &(struct clk_stm32_mux_cfg) {\
			.mux_id = (_mux_id),\
		},\
		CLOCK_NAME(#_name)\
		.flags = (_flags),\
		.num_parents = (_nb_parents),\
		.parents = PARENTS(_parents),\
		.dev = DT_RCC_DEVICE,\
	}

#define STM32_GATE_READY(_name, _parent, _flags, _gate_id)\
	struct clk _name = {\
		.ops = &clk_stm32_gate_ready_ops,\
		.priv = &(struct clk_stm32_gate_cfg) {\
			.gate_id = _gate_id,\
		},\
		CLOCK_NAME(#_name)\
		.flags = (_flags),\
		.num_parents = 1,\
		.parents = PARENT(_parent),\
		.dev = DT_RCC_DEVICE,\
	}

#define STM32_COMPOSITE(_name, _nb_parents, _parents, _flags,\
			_gate_id, _div_id, _mux_id)\
	struct clk _name = {\
		.ops = &clk_stm32_composite_ops,\
		.priv = &(struct clk_stm32_composite_cfg) {\
			.gate_id = (_gate_id),\
			.div_id = (_div_id),\
			.mux_id = (_mux_id),\
		},\
		CLOCK_NAME(#_name)\
		.flags = (_flags),\
		.num_parents = (_nb_parents),\
		.parents = _parents,\
		.dev = DT_RCC_DEVICE,\
	}

#define STM32_DT_OSCI_FREQ_CFG(_node_id, _id)				\
	[_id] = {							\
		.enabled = DT_NODE_HAS_STATUS_OKAY(_node_id),		\
		.freq = DT_PROP(_node_id, clock_frequency),		\
		.bypass = DT_PROP_OR(_node_id, st_bypass, false),	\
		.digbyp = DT_PROP_OR(_node_id, st_digbyp, false),	\
		.css = DT_PROP_OR(_node_id, st_css, false),		\
		.drive = DT_PROP_OR(_node_id, st_drive, UINT32_MAX),	\
	}

#define DT_RCC_CLOCK_OSCI(_inst, _id, _name) \
		STM32_DT_OSCI_FREQ_CFG(DT_CLOCKS_CTLR_BY_NAME(_inst, _name), _id)

#define DT_RCC_DEVICE DEVICE_GET(DEVICE_DT_DEV_ID(DT_DRV_INST(0)))

struct clk *stm32_clk_get(const struct device *dev, clk_subsys_t sys);
void clk_stm32_register_clocks(struct clk_stm32_priv *priv);

#if STM32_CLK_DBG
void clk_stm32_display_clock_summary(struct device *dev);
#endif

#ifdef CONFIG_PM_DEVICE
int clk_stm32_save_context(const struct device *dev);
void clk_stm32_restore_context(const struct device *dev);
#endif

#endif /* CLK_STM32_CORE_H */
