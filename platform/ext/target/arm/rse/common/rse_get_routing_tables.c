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

#define ROUTING_TABLES_SIZE (RSE_COMMS_NUMBER_NODES * sizeof(uint8_t))

#ifndef RSE_OTP_HAS_ROUTING_TABLES
extern struct rse_whole_system_routing_tables_t rse_system_routing_tables;
#endif

enum tfm_plat_err_t rse_get_routing_tables(uint8_t *routing_tables_buf, size_t buf_size,
                                           uint32_t rse_id)
{
#ifdef RSE_OTP_HAS_ROUTING_TABLES
    if (buf_size < RSE_ROUTING_TABLES_ALIGN(ROUTING_TABLES_SIZE, sizeof(uint32_t))) {
        return TFM_PLAT_ERR_ROUTING_TABLES_INVALID_SIZE;
    }

    enum tfm_plat_err_t plat_err =
        tfm_plat_otp_read(PLAT_OTP_ID_RSE_TO_RSE_ROUTING_TABLE, buf_size, routing_tables_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }
#else /* RSE_OTP_HAS_ROUTING_TABLES */
    if (buf_size < ROUTING_TABLES_SIZE) {
        return TFM_PLAT_ERR_ROUTING_TABLES_INVALID_SIZE;
    }

    memcpy(routing_tables_buf, rse_system_routing_tables.routing_table[rse_id].routing_table,
           ROUTING_TABLES_SIZE);
#endif /* RSE_OTP_HAS_ROUTING_TABLES */

    return TFM_PLAT_ERR_SUCCESS;
}
