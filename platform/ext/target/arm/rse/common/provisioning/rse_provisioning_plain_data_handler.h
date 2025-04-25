/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_PLAIN_DATA_HANDLER_H__
#define __RSE_PROVISIONING_PLAIN_DATA_HANDLER_H__

#include <stddef.h>
#include "rse_provisioning_message.h"

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_plat_err_t
default_plain_data_handler(const struct rse_provisioning_message_plain_t *plain_data,
                           size_t msg_size, const void *ctx);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_PLAIN_DATA_HANDLER_H__ */
