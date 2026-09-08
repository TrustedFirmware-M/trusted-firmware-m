/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef STM32MP2_DDR_REGS_H
#define STM32MP2_DDR_REGS_H

#include <stm32mp_ddrctrl_regs.h>
#include <lib/utils_def.h>

/* DDR Physical Interface Control (DDRPHYC) registers*/
struct stm32mp_ddrphy {
	uint32_t dummy;
} __packed;

/* DDRDBG registers offsets */
#define DDRDBG_LP_DISABLE			U(0x0)
#define DDRDBG_BYPASS_PCLKEN			U(0x4)

/* DDRDBG registers fields */
#define _DDRDBG_LP_DISABLE_LPI_XPI_DISABLE	BIT(0)
#define _DDRDBG_LP_DISABLE_LPI_DDRC_DISABLE	BIT(8)

#endif /* STM32MP2_DDR_REGS_H */
