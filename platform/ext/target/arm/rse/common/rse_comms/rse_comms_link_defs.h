/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_LINK_DEFS_H__
#define __RSE_COMMS_LINK_DEFS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \typedef rse_comms_node_id_t
 * \brief Represents the unique identifier for a node.
 *
 * A node ID is an 8-bit unsigned integer used to identify a node
 * in a network or system.
 */
typedef uint8_t rse_comms_node_id_t;

/**
 * \typedef rse_comms_link_id_t
 * \brief Represents the unique identifier for a communication link.
 *
 * A link ID is an 8-bit unsigned integer used to identify a communication
 * link between nodes.
 */
typedef uint8_t rse_comms_link_id_t;

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_LINK_DEFS_H__ */
