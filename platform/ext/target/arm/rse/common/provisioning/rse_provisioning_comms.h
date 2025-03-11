/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_COMMS_H__
#define __RSE_PROVISIONING_COMMS_H__

#include "rse_provisioning_message.h"
#include "tfm_plat_defs.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief
 *
 * @param msg
 * @param msg_size
 * @param msg_len
 * @return enum tfm_plat_err_t
 */
enum tfm_plat_err_t provisioning_comms_receive(const struct rse_provisioning_message_t *msg,
                                               size_t msg_len, size_t *msg_size);

/**
 * @brief
 *
 * @param msg
 * @param msg_size
 * @return enum tfm_plat_err_t
 */
enum tfm_plat_err_t provisioning_comms_send(const struct rse_provisioning_message_t *msg,
                                            size_t msg_size);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_COMMS_H__ */
