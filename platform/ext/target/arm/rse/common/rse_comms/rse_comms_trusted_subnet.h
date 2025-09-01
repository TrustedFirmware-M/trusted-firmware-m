/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_TRUSTED_SUBNET_H__
#define __RSE_COMMS_TRUSTED_SUBNET_H__

#include <stdint.h>
#include "rse_comms_link_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RSE_COMMS_INFLIGHT_BITFIELD_SIZE
#define RSE_COMMS_INFLIGHT_BITFIELD_SIZE 8
#endif

enum rse_comms_cryptography_mode_t {
    RSE_COMMS_CRYPTOGRAPHY_MODE_AES256_CCM = 0,
    RSE_COMMS_CRYPTOGRAPHY_MODE_AES256_GCM = 1,
    RSE_COMMS_CRYPTOGRAPHY_MODE_SM4_CCM = 2,
    RSE_COMMS_CRYPTOGRAPHY_MODE_SM4_GCM = 3,
    _RSE_COMMS_CRYPTOGRAPHY_AES256_MODE_PAD = UINT8_MAX,
};

enum rse_comms_trusted_subnet_type_t {
    RSE_COMMS_TRUSTED_SUBNET_TRUSTED_LINKS,
    RSE_COMMS_TRUSTED_SUBNET_INITIALLY_UNTRUSTED_LINKS,
    RSE_COMMS_TRUSTED_SUBNET_UNTRUSTED_LINKS,
};

struct rse_comms_trusted_subnet_node_t {
    rse_comms_node_id_t id;
    uint16_t send_seq_num;
    uint16_t recv_seq_num;
    uint8_t bitfield_start_index;
    uint8_t inflight_bitfield[(RSE_COMMS_INFLIGHT_BITFIELD_SIZE + 7) / 8];
};

struct rse_comms_trusted_subnet_config_t {
    uint8_t id;
    enum rse_comms_trusted_subnet_type_t type;
    uint32_t key_id;
    enum rse_comms_cryptography_mode_t mode;
    uint8_t node_amount;
    struct rse_comms_trusted_subnet_node_t *nodes;
};

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_TRUSTED_SUBNET_H__ */
