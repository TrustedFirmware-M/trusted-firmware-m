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

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_ROTPK_H__ */
