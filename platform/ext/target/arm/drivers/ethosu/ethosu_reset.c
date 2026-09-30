/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "ethosu_reset.h"

#define ETHOSU_STATUS_REG_OFFSET              0x04U
#define ETHOSU_RESET_REG_OFFSET               0x0CU
#define ETHOSU_PROT_REG_OFFSET                0x24U

#define ETHOSU_RESET_NONSECURE_USER           (1U << 1)
#define ETHOSU_STATUS_RESET_IN_PROGRESS       (1U << 3)
#define ETHOSU_PROT_ACCESS_STATE_MASK         0x3U

#define ETHOSU_RESET_TIMEOUT_ITERATIONS       100000U

enum ethosu_reset_error_t ethosu_reset_nonsecure_user(uintptr_t base)
{
    volatile const uint32_t *const status =
        (volatile const uint32_t *)(base + ETHOSU_STATUS_REG_OFFSET);
    volatile uint32_t *const reset =
        (volatile uint32_t *)(base + ETHOSU_RESET_REG_OFFSET);
    volatile const uint32_t *const prot =
        (volatile const uint32_t *)(base + ETHOSU_PROT_REG_OFFSET);
    uint32_t i;

    *reset = ETHOSU_RESET_NONSECURE_USER;

    for (i = 0U;
         (i < ETHOSU_RESET_TIMEOUT_ITERATIONS) &&
         ((*status & ETHOSU_STATUS_RESET_IN_PROGRESS) != 0U);
         ++i) {
    }

    if ((*status & ETHOSU_STATUS_RESET_IN_PROGRESS) != 0U) {
        return ETHOSU_RESET_ERR_TIMEOUT;
    }

    if ((*prot & ETHOSU_PROT_ACCESS_STATE_MASK) != ETHOSU_RESET_NONSECURE_USER) {
        return ETHOSU_RESET_ERR_ACCESS_STATE;
    }

    return ETHOSU_RESET_ERR_NONE;
}
