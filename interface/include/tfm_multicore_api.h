/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_MULTICORE_API__
#define __TFM_MULTICORE_API__

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Called on the non-secure CPU.
 *        Flags that the non-secure side has completed its initialization.
 *        Waits, if necessary, for the secure CPU to flag that it has completed
 *        its initialization.
 *
 * \return Return 0 if succeeds. Otherwise, return specific error code.
 */
int tfm_ns_wait_for_s_cpu_ready(void);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_MULTICORE_API__ */
