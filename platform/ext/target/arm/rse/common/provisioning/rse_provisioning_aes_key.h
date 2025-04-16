/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_AES_KEY_H__
#define __RSE_PROVISIONING_AES_KEY_H__

#include <stdint.h>
#include "platform_error_codes.h"
#include "rse_provisioning_message.h"

enum tfm_plat_err_t
rse_provisioning_setup_aes_key(const struct rse_provisioning_message_blob_t *blob,
                               uint32_t *key_id);

#endif /* __RSE_PROVISIONING_AES_KEY_H__ */
