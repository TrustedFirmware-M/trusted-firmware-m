/*
 * Copyright (c) 2023 Carlo Caione <ccaione@baylibre.com>
 * Copyright 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * forked of zephyr
 */
#ifndef _DT_BINDINGS_MEMORY_ATTR_MEMORY_ATTR_ARM_H_
#define  _DT_BINDINGS_MEMORY_ATTR_MEMORY_ATTR_ARM_H_

#include <dt-bindings/memory-attr/memory-attr.h>
/*
 * dt_memory_attr_architecture Architecture-specific memory attributes
 * Arch bits: 31...|28 |27|26..25|24..23|22..20|
 *      mpu:           |XN|  AP  |  SH  | MAIR |
 *      sau:       |NSC|
 */

#define DT_MEM_ARCH_SHIFT(x)		((x) + DT_MEM_ARCH_ATTR_SHIFT)
#define DT_MEM_ARCH_GENMASK(h, l)	GENMASK_32(DT_MEM_ARCH_SHIFT(h), DT_MEM_ARCH_SHIFT(l))
#define DT_MEM_ARCH_BIT(x)		BIT(DT_MEM_ARCH_SHIFT(x))

#define DT_MEM_ARM_MPU_MAIR_IDX_SHIFT	DT_MEM_ARCH_SHIFT(0)
#define DT_MEM_ARM_MPU_MAIR_IDX_MASK	DT_MEM_ARCH_GENMASK(2, 0)
#define DT_MEM_ARM_MPU_SH_SHIFT		DT_MEM_ARCH_SHIFT(3)
#define DT_MEM_ARM_MPU_SH_MASK		DT_MEM_ARCH_GENMASK(4, 3)
#define DT_MEM_ARM_MPU_AP_SHIFT		DT_MEM_ARCH_SHIFT(5)
#define DT_MEM_ARM_MPU_AP_MASK		DT_MEM_ARCH_GENMASK(6, 5)
#define DT_MEM_ARM_MPU_XN_SHIFT		DT_MEM_ARCH_SHIFT(7)
#define DT_MEM_ARM_MPU_XN_MASK		DT_MEM_ARCH_BIT(7)
#define DT_MEM_ARM_SAU_NSC_SHIFT	DT_MEM_ARCH_SHIFT(8)
#define DT_MEM_ARM_SAU_NSC_MASK		DT_MEM_ARCH_BIT(8)

/* Attribute index */
#define MAIR_ATTR_DEVICE_IDX		0
#define MAIR_ATTR_CODE_IDX		1
#define MAIR_ATTR_DATA_IDX		2

/* Shareability */
#define SH_NONE				(0x0)
#define SH_UNUSED			(0x1)
#define SH_OUTER			(0x2)
#define SH_INNER			(0x3)

/*
 * Access permissions
 * P (privileged): RW (read/write), RO (read-only)
 * U (unprivileged): NA (no access), RW (read/write), RO (read-only)
 */
#define AP_P_RW_U_NA			(0x0)
#define AP_P_RW_U_RW			(0x1)
#define AP_P_RO_U_NA			(0x2)
#define AP_P_RO_U_RO			(0x3)

/* Execute Never */
#define EXEC_OK				(0x0)
#define EXEC_NEVER			(0x1)

#define DT_MEM_ARM_MPU(mair_idx, sh, ap, xn)			\
	(((mair_idx) << DT_MEM_ARM_MPU_MAIR_IDX_SHIFT) |	\
	 ((sh) << DT_MEM_ARM_MPU_SH_SHIFT) |			\
	 ((ap) << DT_MEM_ARM_MPU_AP_SHIFT) |			\
	 ((xn) << DT_MEM_ARM_MPU_XN_SHIFT))

#define NSC_DIS				(0x0)
#define NSC_EN				(0x1)

#define DT_MEM_ARM_SAU(nsc) ((nsc) << DT_MEM_ARM_SAU_NSC_SHIFT)

#endif   /* _DT_BINDINGS_MEMORY_ATTR_MEMORY_ATTR_ARM_H_ */
