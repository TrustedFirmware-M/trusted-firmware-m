/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "rse_provisioning_rotpk.h"

#include "device_definition.h"
#include "rse_provisioning_config.h"
#include "rse_provisioning_tci_key.h"
#include "bl1_crypto.h"
#include "cc3xx_drv.h"
#include "rse_rotpk_policy.h"
#include "rse_rotpk_mapping.h"
#include "rse_asn1_encoding.h"

#ifdef RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES

#ifndef TFM_DUMMY_PROVISIONING
extern const uint8_t pci_rotpk_x[];
extern const uint8_t pci_rotpk_y[];

extern const size_t pci_rotpk_x_len;
extern const size_t pci_rotpk_y_len;
#endif /* TFM_DUMMY_PROVISIONING */

#ifdef TEST_BL1_1
#define TEST_STATIC
#else
#define TEST_STATIC static
#endif

static bool message_check_cm_rotpk_lcs(enum lcm_lcs_t lcs)
{
    switch (lcs) {
    case LCM_LCS_DM:
        return true;
#if defined(RSE_NON_ENDORSED_DM_PROVISIONING) || \
    defined(RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING) || \
    defined(RSE_ROTPK_REVOCATION)
    case LCM_LCS_SE:
        return true;
#endif
    default:
        return false;
    }
}

static bool message_check_dm_rotpk_lcs(enum lcm_lcs_t lcs)
{
    switch (lcs) {
#if defined(RSE_ROTPK_REVOCATION)
    case LCM_LCS_SE:
        return true;
#endif
    default:
        return false;
    }
}

static enum tfm_plat_err_t get_key_hash_from_otp(enum tfm_otp_element_id_t id, uint8_t *rotpk_hash,
                                                 enum rse_rotpk_hash_alg *alg)
{
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_read(id, RSE_ROTPK_MAX_SIZE, rotpk_hash);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = rse_rotpk_get_hash_alg(id, alg);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return err;
}

TEST_STATIC
enum tfm_plat_err_t get_asn1_from_raw_ec(const uint8_t *x, size_t x_size, const uint8_t *y,
                                         size_t y_size, enum tfm_bl1_ecdsa_curve_t curve_id,
                                         uint8_t *asn1_key, size_t asn1_key_size, size_t *len)
{
    enum rse_asn1_ecdsa_public_key_curve asn1_curve;
    struct rse_asn1_pk_s asn1_pk;

    switch (curve_id) {
    case TFM_BL1_CURVE_P256:
        asn1_curve = RSE_ASN1_ECDSA_PUBLIC_KEY_CURVE_SECP256R1;
        break;
    case TFM_BL1_CURVE_P384:
        asn1_curve = RSE_ASN1_ECDSA_PUBLIC_KEY_CURVE_SECP384R1;
        break;
    default:
        return TFM_PLAT_ERR_PROVISIONING_AUTH_MSG_INVALID_CURVE;
    }

    asn1_pk = (struct rse_asn1_pk_s) {
        .public_key_x = (uint32_t *)x,
        .public_key_x_size = x_size,
        .public_key_y = (uint32_t *)y,
        .public_key_y_size = y_size,
    };

    return rse_asn1_ecdsa_public_key_get(asn1_key, asn1_key_size, asn1_curve, &asn1_pk, len);
}

static enum tfm_plat_err_t
calc_key_hash_from_header(const struct rse_provisioning_authentication_header_t *header,
                          uint8_t *key_hash, enum rse_rotpk_hash_alg alg, size_t point_size)
{
    enum tfm_plat_err_t err;
    /* Max size is 120 bytes */
    uint8_t asn1_key[120];
    size_t len;
    psa_algorithm_t hash_alg;
    psa_status_t status;

    /* Currently keys stored in CM ROTPK are in the form of hashed DER encoded,
     * ASN.1 format keys. Therefore we need to convert the key we have found
     * in the blob to this format, before hashing it */
    err = get_asn1_from_raw_ec(header->public_key, point_size,
                               header->public_key + point_size,
                               point_size, RSE_PROVISIONING_CURVE, asn1_key, sizeof(asn1_key),
                               &len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    switch (alg) {
    case RSE_ROTPK_HASH_ALG_SHA256:
        hash_alg = PSA_ALG_SHA_256;
        break;
    case RSE_ROTPK_HASH_ALG_SHA384:
        hash_alg = PSA_ALG_SHA_384;
        break;
    default:
        return TFM_PLAT_ERR_PROVISIONING_AUTH_MSG_INVALID_HASH_ALG;
    }

    status = psa_hash_compute(hash_alg, asn1_key, len,
                              key_hash, RSE_ROTPK_MAX_SIZE, &len);
    if (status != PSA_SUCCESS) {
        return (enum tfm_plat_err_t)status;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

/**
 * @brief Convert from BL1 curve to CC3XX curve (driver_specific)
 *
 * @param[in] bl1_curve BL1 curve to translate to a CC3XX curve
 *
 * @return cc3xx_ec_curve_id_t Converted curve as interpreted by CC3XX driver
 */
TEST_STATIC
cc3xx_ec_curve_id_t bl1_curve_to_cc3xx_curve(enum tfm_bl1_ecdsa_curve_t bl1_curve)
{
    switch(bl1_curve) {
    case TFM_BL1_CURVE_P256:
        return CC3XX_EC_CURVE_SECP_256_R1;
    case TFM_BL1_CURVE_P384:
        return CC3XX_EC_CURVE_SECP_384_R1;
    default:
        return _CURVE_ID_MAX;
    };
}

static enum tfm_plat_err_t
get_check_hash_cm_dm_rotpk(const struct rse_provisioning_authentication_header_t *header,
                           uint32_t **public_key_x, size_t *public_key_x_size,
                           uint32_t **public_key_y, size_t *public_key_y_size, bool cm_rotpk)
{
    uint16_t rotpk_num;
    enum tfm_otp_element_id_t id;
    enum tfm_plat_err_t err;
    uint8_t key_hash_from_otp[RSE_ROTPK_MAX_SIZE];
    uint8_t key_hash_from_blob[RSE_ROTPK_MAX_SIZE];
    uint32_t point_size;
    enum rse_rotpk_hash_alg hash_alg;

    rotpk_num = (header->metadata >> RSE_PROVISIONING_AUTH_MSG_DETAILS_CM_ROTPK_NUMBER_OFFSET) &
                RSE_PROVISIONING_AUTH_MSG_DETAILS_CM_ROTPK_NUMBER_MASK;
    id = (cm_rotpk ? PLAT_OTP_ID_CM_ROTPK : PLAT_OTP_ID_DM_ROTPK) + rotpk_num;

    if (id >= (cm_rotpk ? PLAT_OTP_ID_CM_ROTPK_MAX : PLAT_OTP_ID_DM_ROTPK_MAX)) {
        return TFM_PLAT_ERR_PROVISIONING_AUTH_MSG_INVALID_CM_ROTPK;
    }

    point_size = cc3xx_lowlevel_ec_get_modulus_size_from_curve(
                            bl1_curve_to_cc3xx_curve(RSE_PROVISIONING_CURVE));

    err = get_key_hash_from_otp(id, key_hash_from_otp, &hash_alg);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = calc_key_hash_from_header(header, key_hash_from_blob, hash_alg, point_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (memcmp(key_hash_from_otp, key_hash_from_blob, RSE_ROTPK_SIZE_FROM_ALG(hash_alg))) {
        return TFM_PLAT_ERR_PROVISIONING_AUTH_MSG_INVALID_HASH_VALUE;
    }

    *public_key_x = (uint32_t *)header->public_key;
    *public_key_x_size = point_size;
    *public_key_y = (uint32_t *)(header->public_key + point_size);
    *public_key_y_size = point_size;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t
get_non_rom_rotpk(const struct rse_provisioning_authentication_header_t *header,
                  uint32_t **public_key_x, size_t *public_key_x_size, uint32_t **public_key_y,
                  size_t *public_key_y_size)
{
    enum lcm_lcs_t lcs;
    enum lcm_error_t lcm_err;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    switch (provisioning_rotpk_get_non_rom_rotpk_config(header)) {
    case RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_CM_ROTPK:
        if (!message_check_cm_rotpk_lcs(lcs)) {
            return TFM_PLAT_ERR_PROVISIONING_AUTH_MSG_INVALID_CM_ROTPK_LCS;
        }

        return get_check_hash_cm_dm_rotpk(header, public_key_x, public_key_x_size, public_key_y,
                                          public_key_y_size, true);
    case RSE_PROVISIONING_AUTH_MSG_DETAILS_NON_ROM_PK_TYPE_DM_ROTPK:
        if (!message_check_dm_rotpk_lcs(lcs)) {
            return TFM_PLAT_ERR_PROVISIONING_AUTH_MSG_INVALID_DM_ROTPK_LCS;
        }

        return get_check_hash_cm_dm_rotpk(header, public_key_x, public_key_x_size, public_key_y,
                                          public_key_y_size, false);
    default:
        return TFM_PLAT_ERR_PROVISIONING_AUTH_MSG_INVALID_NOT_IN_ROM_ROTPK_CONFIG;
    }
}

static enum tfm_plat_err_t get_rom_rotpk(uint32_t **public_key_x,
                                        size_t *public_key_x_size,
                                        uint32_t **public_key_y,
                                        size_t *public_key_y_size)
{
#ifdef TFM_DUMMY_PROVISIONING
    *public_key_x = (uint32_t *)tci_rotpk_x;
    *public_key_y = (uint32_t *)tci_rotpk_y;
    *public_key_x_size = tci_rotpk_x_len;
    *public_key_y_size = tci_rotpk_y_len;
#else
    enum lcm_error_t lcm_err;
    enum lcm_tp_mode_t tp_mode;

    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    switch(tp_mode) {
    case LCM_TP_MODE_TCI:
        *public_key_x = (uint32_t *)tci_rotpk_x;
        *public_key_y = (uint32_t *)tci_rotpk_y;
        *public_key_x_size = tci_rotpk_x_len;
        *public_key_y_size = tci_rotpk_y_len;
        break;
    default:
        *public_key_x = (uint32_t *)pci_rotpk_x;
        *public_key_y = (uint32_t *)pci_rotpk_y;
        *public_key_x_size = pci_rotpk_x_len;
        *public_key_y_size = pci_rotpk_y_len;
    }
#endif /* TFM_DUMMY_PROVISIONING */

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provisioning_rotpk_get(const struct rse_provisioning_authentication_header_t *header,
                                           uint32_t **public_key_x,
                                           size_t *public_key_x_size,
                                           uint32_t **public_key_y,
                                           size_t *public_key_y_size)
{
    if (provisioning_rotpk_is_non_rom(header)) {
        return get_non_rom_rotpk(header, public_key_x, public_key_x_size, public_key_y,
                                 public_key_y_size);
    }

    return get_rom_rotpk(public_key_x, public_key_x_size, public_key_y, public_key_y_size);
}
#endif
