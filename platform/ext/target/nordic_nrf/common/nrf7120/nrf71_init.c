/*
 * Copyright (c) 2025 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <stdint.h>
#include <nrfx.h>
#include <nrf_erratas.h>

#ifndef BIT_MASK
/* Use Zephyr BIT_MASK for unasigned integers */
#define BIT_MASK(n) ((1UL << (n)) - 1UL)
#endif

/* This handler needs to be ported to the upstream TF-M project when Cracen is supported there.
 * The implementation of this is currently in sdk-nrf. We define it to avoid warnings when we build
 * the target_cfg.c file which is the same for both upsteam TF-M and sdk-nrf.
 * It is defined as weak to allow the sdk-nrf version to be used when available. */
void __attribute__((weak)) CRACEN_IRQHandler(void){};

int  __attribute__((weak)) soc_early_init_hook(void){
	/* Update the SystemCoreClock global variable with current core clock
	 * retrieved from hardware state.
	 */
#if !defined(CONFIG_TRUSTED_EXECUTION_NONSECURE) || defined(__NRF_TFM__)
	/* Currently not supported for non-secure */
	SystemCoreClockUpdate();
#endif
	return 0;
}
