/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_hal_device_header.h"
#include "fih.h"
#include "psa/service.h"

void tfm_idle_thread(void)
{
    while (1) {
        /*
         * There could be other Partitions becoming RUNNABLE after wake up.
         * This is a dummy psa_wait to let SPM check possible scheduling.
         * It does not expect any signals.
         */
        if (psa_wait(PSA_WAIT_ANY, PSA_POLL) == 0) {
#if defined(CONFIG_TFM_FLIH_API) || defined(CONFIG_TFM_SLIH_API) || defined(TFM_MULTI_CORE_TOPOLOGY)
            __DSB();
            __WFI();
#endif
        }
    }

#ifdef TFM_FIH_PROFILE_ON
/* Suppress Pe111 (statement is unreachable) for IAR as redundant code is needed for FIH */
#if defined(__ICCARM__)
#pragma diag_suppress = Pe111
#endif
    (void)fih_delay();

    while (1) {
        /*
         * There could be other Partitions becoming RUNNABLE after wake up.
         * This is a dummy psa_wait to let SPM check possible scheduling.
         * It does not expect any signals.
         */
        if (psa_wait(PSA_WAIT_ANY, PSA_POLL) == 0) {
#if defined(CONFIG_TFM_FLIH_API) || defined(CONFIG_TFM_SLIH_API) || defined(TFM_MULTI_CORE_TOPOLOGY)
            __DSB();
            __WFI();
#endif
        }
    }
#if defined(__ICCARM__)
#pragma diag_default = Pe111
#endif
#endif
}
