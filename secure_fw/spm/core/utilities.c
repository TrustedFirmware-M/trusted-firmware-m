/*
 * Copyright (c) 2018-2021, Arm Limited. All rights reserved.
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <inttypes.h>
#include "config_spm.h"
#include "fih.h"
#include "utilities.h"
#include "tfm_hal_platform.h"

#ifdef CONFIG_TFM_BACKTRACE_ON_CORE_PANIC
#include "tfm_log.h"
#include "backtrace.h"
#endif

void tfm_core_panic(void)
{
    (void)fih_delay();
#ifdef CONFIG_TFM_BACKTRACE_ON_CORE_PANIC
    tfm_dump_backtrace(__func__, tfm_log);
#endif

/* Suppress Pe111 (statement is unreachable) for IAR as redundant code is needed for FIH */
#if defined(__ICCARM__)
#pragma diag_suppress = Pe111
#endif
#ifdef CONFIG_TFM_HALT_ON_CORE_PANIC
    /*
     * Halt instead of reboot to retain the backtrace that triggered
     * the fault and thereby make it easier to debug.
     */
    tfm_hal_system_halt();
#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    tfm_hal_system_halt();
#endif /* TFM_FIH_PROFILE_ON */
#else /* CONFIG_TFM_HALT_ON_CORE_PANIC */
    /*
     * FixMe: In the first stage, the SPM will restart the entire system when a
     * programmer error is detected in either the SPE or NSPE.
     * In the next stage, the specified error codes are also sent to any NSPE
     * management firmware. The NSPE management firmware can then decide to pass
     * those error codes back to the calling task or to use its own
     * functionality for terminating an execution context.
     */
    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
#ifdef TFM_FIH_PROFILE_ON
    (void)fih_delay();

    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
#endif /* TFM_FIH_PROFILE_ON */
#endif /* CONFIG_TFM_HALT_ON_CORE_PANIC */

#if defined(__ICCARM__)
#pragma diag_default = Pe111
#else
    __builtin_unreachable();
#endif
    while (1) {
      __NOP();
    }
}
