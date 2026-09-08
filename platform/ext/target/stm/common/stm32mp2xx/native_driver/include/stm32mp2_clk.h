/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef STM32MP2_CLK_H
#define STM32MP2_CLK_H

#include <stdbool.h>

int stm32mp2_clk_init(void);

#define MAX_OPP 2

enum stm32_osc {
	OSC_HSI,
	OSC_HSE,
	OSC_MSI,
	OSC_LSI,
	OSC_LSE,
	NB_OSCILLATOR
};

enum stm32_pll_id {
	PLL1_ID,
	PLL2_ID,
	PLL3_ID,
	PLL4_ID,
	PLL5_ID,
	PLL6_ID,
	PLL7_ID,
	PLL8_ID,
	PLL_NB
};

enum pll_cfg {
	FBDIV,
	REFDIV,
	POSTDIV1,
	POSTDIV2,
	PLLCFG_NB
};

enum pll_csg {
	DIVVAL,
	SPREAD,
	DOWNSPREAD,
	PLLCSG_NB
};

struct stm32_pll_dt_cfg {
	bool enabled;
	uint32_t cfg[PLLCFG_NB];
	uint32_t csg[PLLCSG_NB];
	uint32_t frac;
	bool csg_enabled;
	uint32_t src;
};

struct stm32_osci_dt_cfg {
	bool enabled;
	unsigned long freq;
	bool bypass;
	bool digbyp;
	bool css;
	uint32_t drive;
};

struct stm32_clk_opp_cfg {
	uint32_t frq;
	uint32_t src;
	struct stm32_pll_dt_cfg pll_cfg;
};

struct stm32_clk_opp_dt_cfg {
	struct stm32_clk_opp_cfg cpu1_opp[MAX_OPP];
};

#define STM32_OSCI_CFG(_id, _freq, _bypass, _digbyp, css, _drive)	\
	[_id] = {							\
		 .enabled = true,					\
		.freq = _freq,						\
		.bypass = _bypass,					\
		.digbyp = _digbyp,					\
		.drive = _drive,					\
	}

#define STM32_PLL_CFG_CSG(_id, _cfg, _frac, _csg) \
	[_id] = {                                     \
		.enabled = true,                          \
		.cfg = _cfg,                              \
		.frac = _frac,                            \
		.csg = _csg,                              \
		.csg_enabled = true,                      \
	}

#define STM32_PLL_CFG(_id, _src, _cfg, _frac)	\
	[_id] = {				\
		.enabled = true,		\
		.cfg = _cfg,			\
		.frac = _frac,			\
		.csg = {},			\
		.csg_enabled = false,		\
	}

#define INITLEVEL_RCC PRE_CORE
#define PRIORITY_RCC 5

#endif /* STM32MP2_CLK_H */
