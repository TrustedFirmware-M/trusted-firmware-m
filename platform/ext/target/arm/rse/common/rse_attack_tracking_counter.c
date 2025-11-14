/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "rse_attack_tracking_counter.h"

#include "device_definition.h"
#include "tfm_hal_platform.h"
#include "rse_otp_dev.h"

#define MINOR_ATTACK_TRACKING_COUNTER_MAX 128
#define MAJOR_LFT_COUNTER_WORD_SIZE (sizeof(P_RSE_OTP_HEADER->lft_counter) / sizeof(uint32_t))

void increment_attack_tracking_counter_major(void)
{
    /* Explict cast from uint8_t[] to uint32_t * so that we can iterate word-by-word */
    volatile uint32_t *ctr = (volatile uint32_t *)P_RSE_OTP_HEADER->lft_counter;

#ifndef NDEBUG
    /* In debug modes, catch this error to see if it is a programmer error */
    tfm_hal_system_halt();
#endif

    for (uint32_t idx = 0; idx < MAJOR_LFT_COUNTER_WORD_SIZE; idx++) {
        uint32_t tmp = ctr[idx] + 1;

        if (tmp > 0) {
            ctr[idx] = tmp;
            break;
        }
    }
}

void increment_attack_tracking_counter_minor(void)
{
    /* Use the gretexreg so that the counter persists between boot stages */
    volatile uint32_t *tracking_counter = &((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->gretexreg;

#ifndef NDEBUG
    /* In debug modes, catch this error to see if it is a programmer error */
    tfm_hal_system_halt();
#endif

    *tracking_counter += 1;

    if (*tracking_counter >= MINOR_ATTACK_TRACKING_COUNTER_MAX) {
        increment_attack_tracking_counter_major();
        *tracking_counter = 0;
    }
}

