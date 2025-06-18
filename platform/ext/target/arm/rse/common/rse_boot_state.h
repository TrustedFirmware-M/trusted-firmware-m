/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_BOOT_STATE_H__
#define __RSE_BOOT_STATE_H__

#include <stdint.h>
#include <stddef.h>
#include "platform_error_codes.h"

#ifdef __cplusplus
extern "C" {
#endif

enum boot_state_include_field {
    RSE_BOOT_STATE_INCLUDE_NONE = 0x0,
    RSE_BOOT_STATE_INCLUDE_TP_MODE = 0x1,
    RSE_BOOT_STATE_INCLUDE_LCS = 0x2,
    RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS = 0x4,
    RSE_BOOT_STATE_INCLUDE_BL1_2_HASH = 0x8,
    RSE_BOOT_STATE_INCLUDE_DCU_STATE = 0x10,
    RSE_BOOT_STATE_INCLUDE_MULTI_RSE_STATE = 0x20,
};

typedef uint32_t boot_state_include_mask;

enum tfm_plat_err_t rse_get_boot_state(uint8_t *state, size_t state_buf_len,
                       size_t *state_size, boot_state_include_mask mask);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_BOOT_STATE_H__ */
