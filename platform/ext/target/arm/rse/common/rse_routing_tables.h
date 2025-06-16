/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
*/

#ifndef __RSE_ROUTING_TABLES_H__
#define __RSE_ROUTING_TABLES_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RSE_ROUTING_TABLES_ALIGN(x, bound) ((((x) + bound - 1) / bound) * bound)

struct rse_single_node_routing_tables_t {
    /*
     * The routing tables can be placed in the OTP and therefore
     * must be word aligned
     */
    uint8_t routing_table[RSE_ROUTING_TABLES_ALIGN(RSE_COMMS_NUMBER_NODES, sizeof(uint32_t))];
};

struct rse_whole_system_routing_tables_t {
    struct rse_single_node_routing_tables_t routing_table[RSE_AMOUNT];
};

#ifdef __cplusplus
}
#endif

#endif /* __RSE_ROUTING_TABLES_H__ */
