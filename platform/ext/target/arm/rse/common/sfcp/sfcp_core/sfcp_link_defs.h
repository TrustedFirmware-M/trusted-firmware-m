/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_LINK_DEFS_H__
#define __SFCP_LINK_DEFS_H__

#include <stdint.h>

#if defined(SFCP_NUMBER_NODES) && ((SFCP_NUMBER_NODES < 1) || (SFCP_NUMBER_NODES > 256))
#error "SFCP node IDs support between 1 and 256 nodes"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \typedef sfcp_node_id_t
 * \brief Represents the unique identifier for a node.
 *
 * A node ID is an 8-bit unsigned integer used to identify a node
 * in a network or system.
 */
typedef uint8_t sfcp_node_id_t;

/**
 * \typedef sfcp_link_id_t
 * \brief Represents the unique identifier for a communication link.
 *
 * A link ID is an 8-bit unsigned integer used to identify a communication
 * link between nodes.
 */
typedef uint8_t sfcp_link_id_t;

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_LINK_DEFS_H__ */
