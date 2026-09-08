/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef __SAU_ARMV8M_DRV_H__
#define __SAU_ARMV8M_DRV_H__

#include <stdint.h>
#include <dt-bindings/memory-attr/memory-attr-arm.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sau_region {
	uint32_t base;
	uint32_t limit;
	uint32_t mem_attr;
};

#define SAU_REGION(_base, _limit, _attr)						\
{											\
	.base = _base,									\
	.limit = _limit,								\
	.mem_attr = _attr,								\
}

#ifdef __cplusplus
}
#endif

#endif /* __SAU_ARMV8M_DRV_H__ */
