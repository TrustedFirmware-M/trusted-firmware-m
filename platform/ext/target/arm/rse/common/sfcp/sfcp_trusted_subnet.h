/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SFCP_TRUSTED_SUBNET_H__
#define __SFCP_TRUSTED_SUBNET_H__

#include <stdint.h>
#include "sfcp_link_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SFCP_INFLIGHT_BITFIELD_SIZE
#define SFCP_INFLIGHT_BITFIELD_SIZE 8
#endif

#define SFCP_TRUSTED_SUBNET_RE_KEY_SEQ_NUM (UINT16_MAX - 16)

enum sfcp_cryptography_mode_t {
    SFCP_CRYPTOGRAPHY_MODE_AES256_CCM = 0,
    SFCP_CRYPTOGRAPHY_MODE_AES256_GCM = 1,
    SFCP_CRYPTOGRAPHY_MODE_SM4_CCM = 2,
    SFCP_CRYPTOGRAPHY_MODE_SM4_GCM = 3,
    _SFCP_CRYPTOGRAPHY_AES256_MODE_PAD = UINT8_MAX,
};

enum sfcp_trusted_subnet_type_t {
    SFCP_TRUSTED_SUBNET_TRUSTED_LINKS,
    SFCP_TRUSTED_SUBNET_INITIALLY_UNTRUSTED_LINKS,
    SFCP_TRUSTED_SUBNET_UNTRUSTED_LINKS,
};

struct sfcp_trusted_subnet_node_t {
    sfcp_node_id_t id;
    uint16_t send_seq_num;
    uint16_t recv_seq_num;
    uint8_t bitfield_start_index;
    uint8_t inflight_bitfield[(SFCP_INFLIGHT_BITFIELD_SIZE + 7) / 8];
};

struct sfcp_trusted_subnet_config_t {
    uint8_t id;
    enum sfcp_trusted_subnet_type_t type;
    uint32_t key_id;
    enum sfcp_cryptography_mode_t mode;
    uint8_t node_amount;
    struct sfcp_trusted_subnet_node_t *nodes;
};

#ifdef __cplusplus
}
#endif

#endif /* __SFCP_TRUSTED_SUBNET_H__ */
