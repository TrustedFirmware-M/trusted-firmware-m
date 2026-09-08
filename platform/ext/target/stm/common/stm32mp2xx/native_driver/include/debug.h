/*
 * Copyright (c) 2013-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef  DEBUG_H
#define  DEBUG_H

#include <lib/utils_def.h>
#include <stdio.h>
#include <stdint.h>

#if STM32_NSEC
#include <test_log.h>

#define EMSG(_fmt, ...)    LOG_MSG("[ERR] "_fmt, ##__VA_ARGS__)
#define WMSG(_fmt, ...)    LOG_MSG("[WAR] "_fmt, ##__VA_ARGS__)
#define IMSG(_fmt, ...)    LOG_MSG("[INF] "_fmt, ##__VA_ARGS__)
#define DMSG(_fmt, ...)    LOG_MSG("[DBG] "_fmt, ##__VA_ARGS__)

#define panic() while (1)
#elif STM32_SEC
#include <tfm_hal_platform.h>
#include <tfm_log.h>

/* map on tfm_log library */
#define EMSG(...)       ERROR(__VA_ARGS__)
#define WMSG(...)       WARN(__VA_ARGS__)
#define IMSG(...)       INFO(__VA_ARGS__)
#define DMSG(...)       VERBOSE(__VA_ARGS__)

/* map on tfm_utilities */
#ifdef CONFIG_TFM_HALT_ON_CORE_PANIC
#define PANIC_FUNC tfm_hal_system_halt()
#else
#define PANIC_FUNC tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT)
#endif

#define panic() \
	do { \
		EMSG("Panic in %s, line %d\n", __func__, __LINE__); \
		PANIC_FUNC; \
	} while (0)

#elif STM32_BL2
#include <bootutil/bootutil_log.h>

#define EMSG(...)       BOOT_LOG_ERR(__VA_ARGS__)
#define WMSG(...)       BOOT_LOG_WRN(__VA_ARGS__)
#define IMSG(...)       BOOT_LOG_INF(__VA_ARGS__)
#define DMSG(...)       BOOT_LOG_DBG(__VA_ARGS__)

#define panic() while (1)
#else
#error "debug not supported in this component"
#endif

#ifndef ERROR
#define ERROR   EMSG
#endif

#ifndef WARN
#define WARN    WMSG
#endif

#ifndef INFO
#define INFO    IMSG
#endif

#ifndef VERBOSE
#define VERBOSE DMSG
#endif

#define _ASSERT(_test)				\
	do {					\
		if (!(_test))			\
			panic();		\
	} while (false)
#endif /* DEBUG_H */

