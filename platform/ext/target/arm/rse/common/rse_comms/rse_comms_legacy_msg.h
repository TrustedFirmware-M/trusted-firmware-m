/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_LEGACY_HEADER_H__
#define __RSE_COMMS_LEGACY_HEADER_H__

#include <stdint.h>
#include <cmsis.h>
#include "platform_error_codes.h"
#include "rse_comms_defs.h"
#include "rse_comms_link_defs.h"
#include "config_tfm.h"

#ifdef __cplusplus
extern "C" {
#endif

struct legacy_rse_comms_header_t;
struct legacy_rse_comms_msg_t;
struct legacy_rse_comms_reply_t;

enum tfm_plat_err_t rse_comms_convert_from_legacy_msg(uint8_t *msg_buf, size_t input_msg_len,
                                                      uint8_t *output_msg, size_t output_msg_len,
                                                      size_t *output_msg_size,
                                                      rse_comms_link_id_t link_id,
                                                      rse_comms_node_id_t my_node_id);

enum tfm_plat_err_t rse_comms_convert_from_legacy_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                        uint8_t *output_msg, size_t output_msg_len,
                                                        size_t *output_msg_size,
                                                        rse_comms_link_id_t link_id,
                                                        rse_comms_node_id_t my_node_id);

enum tfm_plat_err_t rse_comms_convert_to_legacy_msg(uint8_t *msg_buf, size_t input_msg_len,
                                                    uint8_t *output_msg, size_t output_msg_len,
                                                    size_t *output_msg_size);

enum tfm_plat_err_t rse_comms_convert_to_legacy_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                      uint8_t *output_msg, size_t output_msg_len,
                                                      size_t *output_msg_size);

enum tfm_plat_err_t rse_comms_convert_to_legacy_error_reply(uint8_t *msg_buf, size_t input_msg_len,
                                                            uint8_t *output_msg,
                                                            size_t output_msg_len,
                                                            size_t msg_buf_len,
                                                            size_t *output_msg_size);

extern uint8_t rse_comms_legacy_conversion_buffer[RSE_COMMS_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) +
                                                  RSE_COMMS_PAYLOAD_MAX_SIZE];

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_LEGACY_HEADER_H__ */
