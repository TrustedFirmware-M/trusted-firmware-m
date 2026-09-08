/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef  __SYSTICK_H__
#define  __SYSTICK_H__

#include <stdint.h>
#include <cmsis.h>

/*
 * In a implementation with Security Extension, there are two 24-bit system timers,
 * a Non-secure SysTick timer and a Secure SysTick timer.
 * The Non-secure registers can be accessed in Secure state by using an aliased
 * address at offset 0x00020000 from the normal register address.
 * In Non-Secure state, only the NS systick is accessible and not by aliased address.
 */
#if (__DOMAIN_NS == 1)
#define systick_NS SysTick
#else
#define systick_S  SysTick
#define systick_NS SysTick_NS
#endif



#endif   /* ----- #ifndef __SYSTICK_H__  ----- */
