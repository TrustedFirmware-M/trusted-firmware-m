/*
 * Copyright (c) 2023 Carlo Caione <ccaione@baylibre.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * forked of zephyr
 */

#ifndef _DT_BINDINGS_MEMORY_ATTR_MEMORY_ATTR_H_
#define  _DT_BINDINGS_MEMORY_ATTR_MEMORY_ATTR_H_

/** Shift & Mask for architecture-specific memory attribute bits. */
#define DT_MEM_ARCH_ATTR_MASK		GENMASK_32(31, 20)
#define DT_MEM_ARCH_ATTR_SHIFT		(20)

/**
 * Extract architecture-specific memory attribute bits from a full
 * <tt>tfm,memory-attr</tt> value.
 *
 * @param x Value to extract architecture-specific memory attribute bits from.
 *
 * @return Architecture-specific memory attribute bits.
 */
#define DT_MEM_ARCH_ATTR_GET(x)		((x) & DT_MEM_ARCH_ATTR_MASK)

/** Architecture-specific memory attributes are unknown. */
#define DT_MEM_ARCH_ATTR_UNKNOWN	BIT_32(31)

#endif   /* _DT_BINDINGS_MEMORY_ATTR_MEMORY_ARM_H_ */
