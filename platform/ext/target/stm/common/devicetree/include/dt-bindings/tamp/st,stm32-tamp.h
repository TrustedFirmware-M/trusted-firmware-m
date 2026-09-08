/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

/* Tamper mode */
#define TAMPER_CONFIRMED_MODE		1
#define TAMPER_POTENTIAL_MODE		2

#define _TAMP_RMP_F_MUX_MASK		(0x80)
#define _TAMP_RMP_F_MUX_SHIFT		7
#define _TAMP_RMP_F_VAL_MASK		(0x40)
#define _TAMP_RMP_F_VAL_SHIFT		6

#define _TAMP_RMP_F_BIT_MASK		(0x07)
#define _TAMP_RMP_F_BIT_SHIFT		0

#define _TAMP_MUX(val, bit)						\
	(_TAMP_RMP_F_MUX_MASK |						\
	 ((val << _TAMP_RMP_F_VAL_SHIFT) & _TAMP_RMP_F_VAL_MASK) |	\
	 (((bit) << _TAMP_RMP_F_BIT_SHIFT) & _TAMP_RMP_F_BIT_MASK))

#define _TAMP_NOMUX			0
