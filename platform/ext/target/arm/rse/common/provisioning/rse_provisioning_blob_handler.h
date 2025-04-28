/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_BLOB_HANDLER_H__
#define __RSE_PROVISIONING_BLOB_HANDLER_H__

#include "rse_provisioning_message.h"
#include "tfm_plat_defs.h"
#include "rse_kmu_slot_ids.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum tfm_plat_err_t (*setup_aes_key_func_t)(const struct rse_provisioning_message_blob_t *, uint32_t *);
typedef enum tfm_plat_err_t (*get_rotpk_func_t)(const struct rse_provisioning_message_blob_t *,
                             uint32_t **, size_t *, uint32_t **, size_t *);

struct default_blob_handler_ctx_t {
    setup_aes_key_func_t setup_aes_key;
    get_rotpk_func_t get_rotpk;
    bool blob_is_chainloaded;
};

enum tfm_plat_err_t default_blob_handler(const struct rse_provisioning_message_blob_t *blob,
                                         size_t msg_size, const void *ctx);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_BLOB_HANDLER_H__ */
