/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_LEGACY_HEADER_H__
#define __SFCP_LEGACY_HEADER_H__

#include <stdint.h>
#include <cmsis.h>
#include "sfcp_defs.h"
#include "sfcp_link_defs.h"
#include "sfcp.h"
#include "config_tfm.h"

#ifdef __cplusplus
extern "C" {
#endif

struct legacy_sfcp_header_t;
struct legacy_sfcp_msg_t;
struct legacy_sfcp_reply_t;

enum sfcp_error_t sfcp_convert_from_legacy_msg(uint8_t *msg_buf, size_t input_msg_len,
                                               uint8_t *output_msg, size_t output_msg_len,
                                               size_t *output_msg_size, sfcp_link_id_t link_id,
                                               sfcp_node_id_t my_node_id);

enum sfcp_error_t sfcp_convert_from_legacy_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                 uint8_t *output_msg, size_t output_msg_len,
                                                 size_t *output_msg_size, sfcp_link_id_t link_id,
                                                 sfcp_node_id_t my_node_id);

enum sfcp_error_t sfcp_convert_to_legacy_msg(uint8_t *msg_buf, size_t input_msg_len,
                                             uint8_t *output_msg, size_t output_msg_len,
                                             size_t *output_msg_size);

enum sfcp_error_t sfcp_convert_to_legacy_reply(uint8_t *msg_buf, size_t input_msg_len,
                                               uint8_t *output_msg, size_t output_msg_len,
                                               size_t *output_msg_size);

enum sfcp_error_t sfcp_convert_to_legacy_error_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                     uint8_t *output_msg, size_t output_msg_len,
                                                     size_t msg_buf_len, size_t *output_msg_size);

extern uint8_t sfcp_legacy_conversion_buffer[SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) +
                                             SFCP_PAYLOAD_MAX_SIZE];

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_LEGACY_HEADER_H__ */
