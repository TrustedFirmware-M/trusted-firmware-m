/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "platform_error_codes.h"
#include "rse_routing_tables.h"
#include "rse_get_routing_tables.h"
#include "tfm_plat_otp.h"

#define ROUTING_TABLES_TOTAL_SIZE \
    (sizeof(((struct rse_single_node_routing_tables_t *)0)->routing_table))
#define ROUTING_TABLES_USED_SIZE                                                \
    (sizeof(((struct rse_single_node_routing_tables_t *)0)->routing_table[0]) * \
     RSE_COMMS_NUMBER_NODES)
#define ARRAY_SIZE(_arr) (sizeof(_arr) / sizeof((_arr)[0]))

#ifdef RSE_OTP_HAS_ROUTING_TABLES
/* Cache routing tables for faster lookup. This is the same size as
 * the routing_table field so that it is a multiple of words in size */
static uint8_t routing_tables_from_otp[ROUTING_TABLES_TOTAL_SIZE];
static bool fetched_routing_tables = false;
#else
extern struct rse_whole_system_routing_tables_t rse_system_routing_tables;
#endif

enum tfm_plat_err_t rse_get_routing_tables(const uint8_t **routing_tables,
                                           size_t *routing_tables_size, uint32_t rse_id)
{
#ifdef RSE_OTP_HAS_ROUTING_TABLES
    if (!fetched_routing_tables) {
        enum tfm_plat_err_t plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_TO_RSE_ROUTING_TABLE,
                                                         sizeof(routing_tables_from_otp),
                                                         routing_tables_from_otp);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }

        fetched_routing_tables = true;
    }

    *routing_tables = routing_tables_from_otp;
#else /* RSE_OTP_HAS_ROUTING_TABLES */
    if (rse_id >= (ARRAY_SIZE(rse_system_routing_tables.routing_table))) {
        return TFM_PLAT_ERR_ROUTING_TABLES_INVALID_RSE_ID;
    }

    *routing_tables = rse_system_routing_tables.routing_table[rse_id].routing_table;
#endif /* RSE_OTP_HAS_ROUTING_TABLES */

    /* The routing table field is a multiple of words in size for alignment
     * but some entries maybe unused. Only return the size of the used entries */
    *routing_tables_size = ROUTING_TABLES_USED_SIZE;

    return TFM_PLAT_ERR_SUCCESS;
}
