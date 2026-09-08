/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef __MPU_ARMV8M_DRV_H__
#define __MPU_ARMV8M_DRV_H__

#include <stdint.h>
#include <dt-bindings/memory-attr/memory-attr-arm.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAIR_ATTR_DEVICE		0x04
#define MAIR_ATTR_CODE			0xAA
#define MAIR_ATTR_DATA			0xFF

#define MAIR_ATTR_MASK(type)					\
	(MAIR_ATTR_##type << (MAIR_ATTR_##type##_IDX * 8))

#define MPU_MAIR_ATTRS						\
	MAIR_ATTR_MASK(DEVICE) |				\
	MAIR_ATTR_MASK(CODE) |					\
	MAIR_ATTR_MASK(DATA)

struct mpu_region {
	uint32_t base;
	uint32_t limit;
	uint32_t mem_attr;
};

#define MPU_REGION(_base, _limit, _attr)						\
{											\
	.base = _base,									\
	.limit = _limit,								\
	.mem_attr = _attr,								\
}

#ifdef __cplusplus
}
#endif

#endif /* __MPU_ARMV8M_DRV_H__ */
