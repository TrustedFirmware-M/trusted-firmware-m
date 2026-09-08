/*
 * Copyright (c) 2021 Intel Corporation
 * Copyright (C) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * inspired by Zephyr
 */
#ifndef _INCLUDE_ILOG2_H_
#define _INCLUDE_ILOG2_H_

#include <lib/utils_def.h>

/**
 * _ilog2_const_u32 - integer base 2 logarithm of a 32-bit constant value
 * @n: unsigned 32-bit value
 *
 * Computes log2(@n) by testing the bits of @n from bit 31 down to
 * bit 2. It only uses constant operators, so the result is an integer
 * constant expression when @n is a constant: it can be used in static
 * initializers, array sizes... Prefer ilog2() which
 * selects this macro automatically for constant values.
 *
 * @warning Will return 0 if input value is 0, which is invalid for log2.
 *
 * return: index of the most significant bit set in @n (0 to 31), as an int.
 *	   0 if @n is 0 or 1.
 */
#define _ilog2_const_u32(n)				\
	(						\
		((n) < 2) ? 0 :				\
		(((n) & BIT(31)) == BIT(31)) ? 31 :	\
		(((n) & BIT(30)) == BIT(30)) ? 30 :	\
		(((n) & BIT(29)) == BIT(29)) ? 29 :	\
		(((n) & BIT(28)) == BIT(28)) ? 28 :	\
		(((n) & BIT(27)) == BIT(27)) ? 27 :	\
		(((n) & BIT(26)) == BIT(26)) ? 26 :	\
		(((n) & BIT(25)) == BIT(25)) ? 25 :	\
		(((n) & BIT(24)) == BIT(24)) ? 24 :	\
		(((n) & BIT(23)) == BIT(23)) ? 23 :	\
		(((n) & BIT(22)) == BIT(22)) ? 22 :	\
		(((n) & BIT(21)) == BIT(21)) ? 21 :	\
		(((n) & BIT(20)) == BIT(20)) ? 20 :	\
		(((n) & BIT(19)) == BIT(19)) ? 19 :	\
		(((n) & BIT(18)) == BIT(18)) ? 18 :	\
		(((n) & BIT(17)) == BIT(17)) ? 17 :	\
		(((n) & BIT(16)) == BIT(16)) ? 16 :	\
		(((n) & BIT(15)) == BIT(15)) ? 15 :	\
		(((n) & BIT(14)) == BIT(14)) ? 14 :	\
		(((n) & BIT(13)) == BIT(13)) ? 13 :	\
		(((n) & BIT(12)) == BIT(12)) ? 12 :	\
		(((n) & BIT(11)) == BIT(11)) ? 11 :	\
		(((n) & BIT(10)) == BIT(10)) ? 10 :	\
		(((n) & BIT(9)) == BIT(9)) ? 9 :	\
		(((n) & BIT(8)) == BIT(8)) ? 8 :	\
		(((n) & BIT(7)) == BIT(7)) ? 7 :	\
		(((n) & BIT(6)) == BIT(6)) ? 6 :	\
		(((n) & BIT(5)) == BIT(5)) ? 5 :	\
		(((n) & BIT(4)) == BIT(4)) ? 4 :	\
		(((n) & BIT(3)) == BIT(3)) ? 3 :	\
		(((n) & BIT(2)) == BIT(2)) ? 2 :	\
		1					\
	)

/**
 * ilog2 - integer base 2 logarithm of a 32-bit value
 * @n: unsigned 32-bit value
 *
 * Computes log2(@n). When @n is a compile-time constant, the
 * result is computed by _ilog2_const_u32() and is an integer constant
 * expression. Otherwise, it is computed at runtime with __builtin_clz()
 *
 * @warning Will return 0 if input value is 0, which is invalid for log2.
 *
 * return: index of the most significant bit set in @n (0 to 31), as an int.
 *	   0 if @n is 0 or 1.
 */
#define ilog2(n)			\
(					\
	__builtin_constant_p(n) ?	\
	_ilog2_const_u32(n) :		\
	((n) < 2 ? 0 :			\
	 (31 - __builtin_clz(n)))	\
)

#endif /* _INCLUDE_ILOG2_H_ */
