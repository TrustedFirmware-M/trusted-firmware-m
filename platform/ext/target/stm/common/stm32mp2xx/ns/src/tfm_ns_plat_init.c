/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <Driver_Common.h>
#include <fault_info.h>
#include <init.h>
#include <stdio.h>
#include <uart_stdout.h>

int32_t tfm_ns_platform_init (void)
{
	sys_init_run_level(INIT_LEVEL_PRE_CORE);
	sys_init_run_level(INIT_LEVEL_CORE);

	stdio_init();
	fault_init();

	sys_init_run_level(INIT_LEVEL_POST_CORE);

	return ARM_DRIVER_OK;
}
