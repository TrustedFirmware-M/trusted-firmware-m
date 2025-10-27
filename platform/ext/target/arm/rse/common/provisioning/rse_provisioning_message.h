/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_MESSAGE_H__
#define __RSE_PROVISIONING_MESSAGE_H__

#include "rse_otp_layout.h"
#include "rse_provisioning_config.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum rse_provisioning_message_type_t {
    RSE_PROVISIONING_MESSAGE_TYPE_BLOB                      = 0x1111B10B,
    RSE_PROVISIONING_MESSAGE_TYPE_CERTIFICATE               = 0x2222CE57,
    RSE_PROVISIONING_MESSAGE_TYPE_PLAIN_DATA                = 0x3333DA7A,
    RSE_PROVISIONING_MESSAGE_TYPE_AUTHENTICATED_PLAIN_DATA  = 0x4444DA7A,

    _RSE_PROVISIONING_MESSAGE_TYPE_MAX_VAL = UINT32_MAX,
};

enum rse_provisioning_reply_type_t {
    RSE_PROVISIONING_REPLY_TYPE_CERTIFICATE      = 0x2222CE57,
    RSE_PROVISIONING_REPLY_TYPE_CHIP_OUTPUT_DATA = 0x33330C0D,
    RSE_PROVISIONING_REPLY_TYPE_PLAIN_DATA       = 0x3333DA7A,

    _RSE_PROVISIONING_REPLY_TYPE_MAX_VAL = UINT32_MAX,
};

#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_TYPE_OFFSET 0
#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_TYPE_MASK   0b11111111
enum rse_provisioning_auth_msg_type_t {
    RSE_PROVISIONING_AUTH_MSG_TYPE_SINGLE_LCS_PROVISIONING              = 0x1,
    RSE_PROVISIONING_AUTH_MSG_TYPE_COMBINED_LCS_PROVISIONING            = 0x2,
    RSE_PROVISIONING_AUTH_MSG_TYPE_NEXT_MESSAGE_PUBLIC_KEY_PROVISIONING = 0x3,
    RSE_PROVISIONING_AUTH_MSG_TYPE_ENDORSEMENT_CERTIFICATE_PROVISIONING = 0x4,
    RSE_PROVISIONING_AUTH_MSG_TYPE_DEBUG_ENABLING                       = 0x5,
    RSE_PROVISIONING_AUTH_MSG_TYPE_VIRTUAL_TCI                          = 0x6,
    RSE_PROVISIONING_AUTH_MSG_TYPE_TEST                                 = 0x7,

    _RSE_PROVISIONING_MESSAGE_PURPOSE_MAX_VAL = UINT8_MAX,
};

#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_TP_MODE_OFFSET 9
#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_TP_MODE_MASK   0b11
enum rse_provisioning_auth_msg_required_tp_mode_config_t {
    RSE_PROVISIONING_AUTH_MSG_REQUIRES_TP_MODE_VIRGIN = 0b00,
    RSE_PROVISIONING_AUTH_MSG_REQUIRES_TP_MODE_PCI    = 0b01,
    RSE_PROVISIONING_AUTH_MSG_REQUIRES_TP_MODE_TCI    = 0b10,
};

#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_SP_MODE_OFFSET 11
#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_SP_MODE_MASK   0b1
enum rse_provisioning_auth_msg_required_sp_mode_config_t {
    RSE_PROVISIONING_AUTH_MSG_REQUIRES_SP_MODE_DISABLED = 0b0,
    RSE_PROVISIONING_AUTH_MSG_REQUIRES_SP_MODE_ENABLED  = 0b1,
};

#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_SEQUENCING_OFFSET 27
#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_SEQUENCING_MASK   0b1
enum rse_provisioning_auth_msg_sequencing_config_t {
    RSE_PROVISIONING_AUTH_MSG_NON_CHAINED = 0b0,
    RSE_PROVISIONING_AUTH_MSG_CHAINED     = 0b1,
};

#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_LCS_MASK_OFFSET 28
#define RSE_PROVISIONING_AUTH_MSG_PURPOSE_LCS_MASK_MASK   0b1111
enum rse_provisioning_auth_msg_valid_lcs_mask_t {
    RSE_PROVISIONING_AUTH_MSG_VALID_IN_CM_LCS  = 0b0001,
    RSE_PROVISIONING_AUTH_MSG_VALID_IN_DM_LCS  = 0b0010,
    RSE_PROVISIONING_AUTH_MSG_VALID_IN_SE_LCS  = 0b0100,
    RSE_PROVISIONING_AUTH_MSG_VALID_IN_RMA_LCS = 0b1000,
};

#define RSE_PROVISIONING_AUTH_MSG_DETAILS_CODE_DATA_DECRYPTION_OFFSET 0
#define RSE_PROVISIONING_AUTH_MSG_DETAILS_CODE_DATA_DECRYPTION_MASK   0b11
enum rse_provisioning_auth_msg_code_and_data_decryption_config_t {
    RSE_PROVISIONING_AUTH_MSG_CODE_DATA_DECRYPTION_NONE = 0b00,
    RSE_PROVISIONING_AUTH_MSG_CODE_DATA_DECRYPTION_AES  = 0b01,
};

#define RSE_PROVISIONING_AUTH_MSG_DETAILS_SECRET_VALUES_DECRYPTION_OFFSET 2
#define RSE_PROVISIONING_AUTH_MSG_DETAILS_SECRET_VALUES_DECRYPTION_MASK   0b11
enum rse_provisioning_auth_msg_secret_values_decryption_config_t {
    RSE_PROVISIONING_AUTH_MSG_SECRET_VALUES_DECRYPTION_AES          = 0b01,
    RSE_PROVISIONING_AUTH_MSG_SECRET_VALUES_DECRYPTION_BY_MESSAGE   = 0b10,
};

#define RSE_PROVISIONING_AUTH_MSG_DETAILS_CM_ROTPK_NUMBER_OFFSET 8
#define RSE_PROVISIONING_AUTH_MSG_DETAILS_CM_ROTPK_NUMBER_MASK   0b111111111

#define RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_OFFSET 26
#define RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_MASK   0b11
enum rse_provisioning_auth_msg_non_rom_pk_type_config_t {
    RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_CM_ROTPK          = 0b0,
    RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_PREVIOUS_MESSAGE  = 0b1,
};

#define RSE_PROVISIONING_AUTH_MSG_DETAILS_SIGNATURE_OFFSET 28
#define RSE_PROVISIONING_AUTH_MSG_DETAILS_SIGNATURE_MASK   0b11
enum rse_provisioning_auth_msg_signature_config_t {
    RSE_PROVISIONING_AUTH_MSG_SIGNATURE_NONE             = 0b00,
    RSE_PROVISIONING_AUTH_MSG_SIGNATURE_KRTL_DERIVATIVE  = 0b01,
    RSE_PROVISIONING_AUTH_MSG_SIGNATURE_ROTPK_IN_ROM     = 0b10,
    RSE_PROVISIONING_AUTH_MSG_SIGNATURE_ROTPK_NOT_IN_ROM = 0b11,
};

#define RSE_PROVISIONING_AUTH_MSG_DETAILS_PERSONALIZATION_OFFSET 30
#define RSE_PROVISIONING_AUTH_MSG_DETAILS_PERSONALIZATION_MASK   0b11
enum rse_provisioning_auth_msg_personalization_config_t {
    RSE_PROVISIONING_AUTH_MSG_TYPE_STATIC        = 0b00,
    RSE_PROVISIONING_AUTH_MSG_TYPE_PERSONALIZED  = 0b01,
};

enum rse_provisioning_plain_data_type_t {
    RSE_PROVISIONING_PLAIN_DATA_TYPE_UNSPECIFIED                               = 0x00,
    RSE_PROVISIONING_PLAIN_DATA_TYPE_NON_ENDORSED_DM_ROTPKS                    = 0x01,
    RSE_PROVISIONING_PLAIN_DATA_TYPE_ENDORSEMENT_CERTIFICATE_PACKAGE           = 0x02,
    RSE_PROVISIONING_PLAIN_DATA_TYPE_REQUEST_TO_EXPORT_ENDORSEMENT_CERTIFICATE = 0x03,
    RSE_PROVISIONING_PLAIN_DATA_TYPE_CM_ROTPK_ARRAY_REVOCATION                 = 0x04,
    RSE_PROVISIONING_PLAIN_DATA_TYPE_DM_ROTPK_ARRAY_REVOCATION                 = 0x05,
};

struct __attribute__((__packed__)) rse_provisioning_authentication_header_t {
    uint32_t signature_size;
    uint8_t signature[96]; /*!< In the case of ECDSA signature, this is held as a raw format
                            * (r,s)
                            */
    uint32_t metadata;
    uint32_t purpose;

    uint32_t version;

    uint8_t iv[8];
    uint8_t soc_uid[12];
    uint32_t batch_id;
    uint32_t dm_number;

    uint32_t code_size;
    uint32_t data_size;
    uint32_t secret_values_size;

    uint8_t public_key[96];  /*!< In the case of ECDSA key, this contains the raw key
                              * in uncompressed (x,y) format without the 0x04 prefix
                              * byte
                              */
};

struct __attribute__((__packed__)) rse_provisioning_message_blob_t {
    struct rse_provisioning_authentication_header_t header;

    uint8_t code_and_data_and_secret_values[];
};

struct __attribute__((__packed__)) rse_provisioning_message_plain_t {
    uint32_t plain_metadata;

    uint8_t data[];
};

struct __attribute__((__packed__)) rse_provisioning_message_authenticated_plain_t {
    struct rse_provisioning_authentication_header_t header;

    struct rse_provisioning_message_plain_t plain_data;
};

struct __attribute__((__packed__)) rse_provisioning_message_cert_t {
    uint32_t cert_metadata;

    uint8_t data[];
};

struct __attribute__((__packed__)) rse_provisioning_message_t {
    struct __attribute__((__packed__)) {
        enum rse_provisioning_message_type_t type;
        uint32_t data_length;
    } header;

    union __attribute__((__packed__)) {
        struct rse_provisioning_message_blob_t blob;
        struct rse_provisioning_message_plain_t plain;
        struct rse_provisioning_message_authenticated_plain_t authenticated_plain;
        struct rse_provisioning_message_cert_t cert;
    };
};

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_MESSAGE_H__ */
