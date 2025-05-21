/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_GET_MESSAGE_H__
#define __RSE_PROVISIONING_GET_MESSAGE_H__

#include <stddef.h>

#include "rse_provisioning_message.h"
#include "platform_error_codes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Gets a provisioning message and places it in the buffer
 *
 * Checks whether or not a valid provisioning message is in the buffer and if not
 * fetches the message over the provisioning comms interface
 *
 * \param[in,out] message_buf       Pointer to the buffer where the message will be stored.
 *                                  Must be a valid pointer to a struct of type
 *                                  rse_provisioning_message_t.
 * \param[in]     message_buf_size  Size of the buffer in bytes. Must be at least
 *                                  the size of the expected message.
 *
 * \return  Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t
rse_provisioning_get_message(const struct rse_provisioning_message_t *message_buf,
                             size_t message_buf_size);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_GET_MESSAGE_H__ */
