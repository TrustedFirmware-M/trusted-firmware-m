/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "platform_error_codes.h"
#include "rse_routing_tables.h"
#include "rse_get_routing_tables.h"
#include "tfm_plat_otp.h"

#define SENDER_ROUTING_TABLES_SIZE ((NUM_NODES) * sizeof(uint8_t))
#define RECEIVE_ROUTING_TABLES_SIZE ((NUM_NODES) * sizeof(uint8_t))

#ifndef RSE_OTP_HAS_ROUTING_TABLES
extern struct rse_whole_system_routing_tables_t rse_system_routing_tables;
#endif

enum tfm_plat_err_t rse_get_sender_routing_tables(uint8_t *routing_tables_buf, size_t buf_size,
                                                  uint32_t rse_id)
{
    if (buf_size < SENDER_ROUTING_TABLES_SIZE) {
        return TFM_PLAT_ERR_SEND_ROUTING_TABLES_INVALID_SIZE;
    }

#ifdef RSE_OTP_HAS_ROUTING_TABLES
    enum tfm_plat_err_t plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_TO_RSE_SENDER_ROUTING_TABLE,
                                                     buf_size, routing_tables_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }
#else
    memcpy(routing_tables_buf, rse_system_routing_tables.routing_table[rse_id].send,
           SENDER_ROUTING_TABLES_SIZE);
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_get_receiver_routing_tables(uint8_t *routing_tables_buf, size_t buf_size,
                                                    uint32_t rse_id)
{
    if (buf_size < RECEIVE_ROUTING_TABLES_SIZE) {
        return TFM_PLAT_ERR_RECEIVE_ROUTING_TABLES_INVALID_SIZE;
    }

#ifdef RSE_OTP_HAS_ROUTING_TABLES
    enum tfm_plat_err_t plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_TO_RSE_RECEIVER_ROUTING_TABLE,
                                                     buf_size, routing_tables_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }
#else
    memcpy(routing_tables_buf, rse_system_routing_tables.routing_table[rse_id].receive,
           RECEIVE_ROUTING_TABLES_SIZE);
#endif

    return TFM_PLAT_ERR_SUCCESS;
}
