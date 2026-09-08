/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef __STM32_DCACHE_H
#define __STM32_DCACHE_H

#include <errno.h>
#include <stdbool.h>

struct stm32_dcache_mon {
	uint32_t rmiss;
	uint32_t rhit;
	uint32_t wmiss;
	uint32_t whit;
};

#define DCACHE_CMD_CLR		0x1
#define DCACHE_CMD_INV		0x2
#define DCACHE_CMD_CLRINV	0x3

#define stm32_dcache_clean(s, e)	stm32_dcache_maintenance(DCACHE_CMD_CLR, s, e)
#define stm32_dcache_inv(s, e)		stm32_dcache_maintenance(DCACHE_CMD_INV, s, e)
#define stm32_dcache_clean_inv(s, e)	stm32_dcache_maintenance(DCACHE_CMD_CLRINV, s, e)

#if defined(STM32_CACHE_ENABLED)
int stm32_dcache_monitor_reset(void);
int stm32_dcache_monitor_start(void);
int stm32_dcache_monitor_stop(void);
int stm32_dcache_monitor_get(struct stm32_dcache_mon *mon);
int stm32_dcache_full_inv(void);
int stm32_dcache_maintenance(int cmd, uintptr_t start, uintptr_t end);
int stm32_dcache_disable(void);
int stm32_dcache_enable(bool monitor, bool inv);
#else
static inline int stm32_dcache_monitor_reset(void)
{
	return -ENOTSUP;
}
static inline int stm32_dcache_monitor_start(void)
{
	return -ENOTSUP;
}
static inline int stm32_dcache_monitor_stop(void)
{
	return -ENOTSUP;
}
static inline int stm32_dcache_monitor_get(struct stm32_dcache_mon *mon __unused)
{
	return -ENOTSUP;
}
static inline int stm32_dcache_full_inv(void)
{
	return -ENOTSUP;
}
static inline int stm32_dcache_maintenance(int cmd __unused, uintptr_t start __unused,
					   uintptr_t end __unused)
{
	return -ENOTSUP;
}
static inline int stm32_dcache_disable(void)
{
	return -ENOTSUP;
}
static inline int stm32_dcache_enable(bool monitor __unused, bool inv __unused)
{
	return -ENOTSUP;
}
#endif
#endif /* __STM32_DCACHE_H */
