/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef  TFM_PM_H
#define  TFM_PM_H

#include <lib/utils_def.h>

/*
 * Platform hints on targeted power state. Hints are stored in a 32bit
 * unsigned value. Lower bits defines generic resource bit flags. Higher
 * bits stores a platform specific value specific platform driver may
 * understand. Registered callbacks may choose to use or ignore these hints.
 *
 * PM_HINT_CLOCK_STATE - When set clock shall be suspended/restored
 * PM_HINT_POWER_STATE - When set device power shall be suspended/restored
 * PM_HINT_IO_STATE - When set IO pins shall be suspended/restored
 * PM_HINT_CONTEXT_STATE - When set the full context shall be suspended/restored
 * PM_HINT_PLATFORM_STATE_MASK - Bit mask reserved for platform specific hints
 * PM_HINT_PLATFORM_STATE_SHIFT - LSBit position of platform specific hints mask
 */
#define PM_HINT_CLOCK_STATE		BIT(0)
#define PM_HINT_POWER_STATE		BIT(1)
#define PM_HINT_IO_STATE		BIT(2)
#define PM_HINT_CONTEXT_STATE		BIT(3)
#define PM_HINT_PLATFORM_STATE_MASK	GENMASK_32(31, 16)
#define PM_HINT_PLATFORM_STATE_SHIFT	U(16)

#define PM_HINT_STATE(x)		((x) & ~PM_HINT_PLATFORM_STATE_MASK)
#define PM_HINT_PLATFORM_STATE(x) \
	(((x) & PM_HINT_PLATFORM_STATE_MASK) >> PM_HINT_PLATFORM_STATE_SHIFT)

#define PM_HINT_IS_STATE(x, name) (!!((x) & PM_HINT_ ## name ## _STATE))

#endif /* TFM_PM_H */
