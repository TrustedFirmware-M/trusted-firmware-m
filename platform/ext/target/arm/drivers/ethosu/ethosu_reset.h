/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef ETHOSU_RESET_H
#define ETHOSU_RESET_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum ethosu_reset_error_t {
    ETHOSU_RESET_ERR_NONE = 0,
    ETHOSU_RESET_ERR_TIMEOUT = -1,
    ETHOSU_RESET_ERR_ACCESS_STATE = -2,
};

/**
 * \brief Reset an Ethos-U NPU into non-secure, user mode.
 *
 * Requests user privilege and non-secure security states, waits for the NPU to
 * come out of reset, and verifies that the requested states have been applied.
 *
 * \param[in] base Secure base address of the Ethos-U register map.
 *
 * \return ETHOSU_RESET_ERR_NONE on success, otherwise an error from
 *         \ref ethosu_reset_error_t.
 */
enum ethosu_reset_error_t ethosu_reset_nonsecure_user(uintptr_t base);

#ifdef __cplusplus
}
#endif

#endif /* ETHOSU_RESET_H */
