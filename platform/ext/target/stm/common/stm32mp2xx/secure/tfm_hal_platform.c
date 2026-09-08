/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <assert.h>
#include <cmsis.h>
#include <device.h>
#include <psa_manifest/pid.h>
#include <tfm_hal_platform.h>
#include <tfm_plat_defs.h>
#include <target_cfg.h>
#include <region.h>
#include <init.h>
#include <lib/mmio.h>

#include <uart_stdout.h>
#include <stm32_dcache.h>
#include <debug.h>
#include <stm_version.h>

enum tfm_hal_status_t tfm_hal_platform_init(void)
{
	enum tfm_plat_err_t plat_err = TFM_PLAT_ERR_SYSTEM_ERR;

	plat_err = system_reset_cfg();
	if (plat_err != TFM_PLAT_ERR_SUCCESS) {
		return TFM_HAL_ERROR_GENERIC;
	}

	sys_init_run_level(INIT_LEVEL_PRE_CORE);

	if (IS_ENABLED(STM32_CACHE_ENABLED)) {
		if (stm32_dcache_enable(true, true))
			return TFM_HAL_ERROR_GENERIC;
	}

	sys_init_run_level(INIT_LEVEL_CORE);

	stdio_init();

	INFO("welcome to TF-M: "MODEL_VERSION"\n");
	INFO("board: "MODEL_BOARD"\n");
	INFO("dts: "MODEL_S_DTS"\n");

	sys_init_run_level(INIT_LEVEL_POST_CORE);
	sys_init_run_level(INIT_LEVEL_REST);

	return TFM_HAL_SUCCESS;
}

/* Get address of non secure code start */
REGION_DECLARE(Load$$LR$$, LR_NS_PARTITION, $$Base);
#define NS_SECURE_BASE (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base)

uint32_t tfm_hal_get_ns_VTOR(void)
{
    return NS_SECURE_BASE;
}

uint32_t tfm_hal_get_ns_MSP(void)
{
    return *((uint32_t *)NS_SECURE_BASE);
}

uint32_t tfm_hal_get_ns_entry_point(void)
{
    return *((uint32_t *)(NS_SECURE_BASE + 4));
}

uint32_t tfm_hal_raise_notify_ns(void)
{
	TZ_NVIC_SetPendingIRQ_NS(RESERVED_9);
	return TFM_HAL_SUCCESS;
}

uint32_t tfm_hal_notify_ns_init(void)
{
	return TFM_HAL_SUCCESS;
}

uint32_t tfm_hal_check_boot_data_access_policy(int32_t partition_id)
{
#ifdef TFM_PARTITION_PM
	if (partition_id == TFM_SP_PM)
		return TFM_HAL_SUCCESS;
#endif

	return TFM_HAL_ERROR_GENERIC;
}

/* Resets the system with RCC when TDCID or reset only cortex M33. */
#define RCC_GRSTCSETR		0x400
#define _RCC_GRSTCSETR_SYSRST	BIT(0)
__NO_RETURN void tfm_hal_system_reset(uint32_t sw_reset_syn_value)
{
	assert(sw_reset_syn_value == TFM_PLAT_SWSYN_DEFAULT);
	__disable_irq();

	if (IS_ENABLED(STM32_M33TDCID)) {
		uintptr_t base = DT_REG_ADDR(DT_NODELABEL(rcc));

		IMSG("System reset\n");
		io_write32(base + RCC_GRSTCSETR, _RCC_GRSTCSETR_SYSRST);
	} else {
		IMSG("Cortex-M33 reset\n");
		NVIC_SystemReset();
	}

	while(1) {
		__NOP();
	}
}

__NO_RETURN void tfm_hal_system_halt(void)
{
	/*
	 * Disable IRQs to stop all threads, not just the thread that
	 * halted the system.
	 */
	__disable_irq();

	/*
	 * Enter sleep to reduce power consumption and do it in a loop in
	 * case a signal wakes up the CPU.
	 */
	while (1) {
		__WFE();
	}
}
