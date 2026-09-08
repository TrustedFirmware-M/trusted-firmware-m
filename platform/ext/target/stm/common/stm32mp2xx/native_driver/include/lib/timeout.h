/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef  __TIMEOUT_H__
#define  __TIMEOUT_H__

#include <cmsis.h>
#include <stdbool.h>

#define USEC_PER_MSEC	1000L
#define MSEC_PER_SEC	1000L
#define USEC_PER_SEC	1000000L
#define NSEC_PER_SEC	1000000000UL

__WEAK uint64_t timeout_init_us(uint64_t us)
{
	return 0;
}

__WEAK bool timeout_elapsed(uint64_t timeout)
{
	return false;
}
#endif   /* ----- #ifndef __TIMEOUT_H__  ----- */
