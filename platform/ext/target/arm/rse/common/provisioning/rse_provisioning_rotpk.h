/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_ROTPK_H__
#define __RSE_PROVISIONING_ROTPK_H__

#include "tfm_plat_defs.h"
#include "rse_provisioning_message.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_plat_err_t provisioning_rotpk_get(const struct rse_provisioning_authentication_header_t *header,
                                           uint32_t **public_key_x,
                                           size_t *public_key_x_size,
                                           uint32_t **public_key_y,
                                           size_t *public_key_y_size);

static inline bool
provisioning_rotpk_is_non_rom(const struct rse_provisioning_authentication_header_t *header)
{
    return ((header->metadata >> RSE_PROVISIONING_AUTH_MSG_DETAILS_SIGNATURE_OFFSET) &
            RSE_PROVISIONING_AUTH_MSG_DETAILS_SIGNATURE_MASK) ==
           RSE_PROVISIONING_AUTH_MSG_SIGNATURE_ROTPK_NOT_IN_ROM;
}

static inline enum rse_provisioning_auth_msg_non_rom_pk_type_config_t
provisioning_rotpk_get_non_rom_rotpk_config(
    const struct rse_provisioning_authentication_header_t *header)
{
    return (header->metadata >> RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_OFFSET) &
           RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_MASK;
}

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_ROTPK_H__ */
