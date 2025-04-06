/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "rse_provisioning_tests.h"

#include <string.h>

#include "test_framework_helpers.h"
#include "tfm_plat_defs.h"
#include "region_defs.h"
#include "rse_provisioning_message.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_rotpk.h"
#include "rse_rotpk_policy.h"
#include "rse_otp_layout.h"
#include "rse_kmu_keys.h"
#include "cc3xx_aes.h"
#include "device_definition.h"
#include "tfm_plat_provisioning.h"
#include "crypto.h"
#include "cc3xx_drv.h"
#include "lcm_drv.h"

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

#define TEST_ASSERT(cond, msg) \
    if (!(cond)) { \
        TEST_FAIL(msg); \
        return; \
    }

#define TEST_SETUP(x) TEST_ASSERT((x) == 0, "Test setup failed")
#define TEST_TEARDOWN(x) TEST_ASSERT((x) == 0, "Test teardown failed")

#define CODE_DATA_SECRET_VALUES_SIZE (100)

/* Arbitrary IV value */
#define IV_RANDOM_BYTES "\xDE\xAD\xBE\xEF\xEF\xBE\xAD\xDE"

/* Arbitrary distinct values for code, data and values */
#define CODE_RANDOM_BYTES "\x6D\xFF\x9A\x63\x16\x42\x78\xAC\x5E\xD1"
#define DATA_RANDOM_BYTES "\x56\xB6\x03\xD7\xD2\x8F\xA1\x4C\x37\x92"
#define VALUES_RANDOM_BYTES "\xF8\x0C\x28\x38\x38\xDD\x7A\x65\x9B\xC4"

/* These functions are part of the provisioning code. They are usually static
 * functions, but enabling the provisioning tests makes them non-static. Because
 * they're usually static, they are not included in any header, so in order to
 * have the definitions we need to manually define them here.
 */
bool blob_needs_code_data_decryption(const struct rse_provisioning_message_blob_t *blob);

bool blob_needs_secret_decryption(const struct rse_provisioning_message_blob_t *blob);

enum tfm_plat_err_t
validate_and_unpack_blob(const struct rse_provisioning_message_blob_t *blob, size_t msg_size,
                         void *code_output, size_t code_output_size, void *data_output,
                         size_t data_output_size, void *values_output, size_t values_output_size,
                         setup_aes_key_func_t setup_aes_key, get_rotpk_func_t get_rotpk);

enum tfm_plat_err_t get_asn1_from_raw_ec(const uint8_t *x, size_t x_size, const uint8_t *y,
                                         size_t y_size, cc3xx_ec_curve_id_t curve_id,
                                         uint8_t *asn1_key, size_t *len);

struct rse_provisioning_message_blob_with_data_t {
    struct rse_provisioning_message_blob_t blob;
    uint8_t __data[CODE_DATA_SECRET_VALUES_SIZE];
};

struct rse_provisioning_ecdsa_gen_key_data_t {
    union {
        uint32_t private_key[48 / sizeof(uint32_t)];
        uint8_t private_key_bytes[48];
    };
    union {
        uint32_t public_key_x[48 / sizeof(uint32_t)];
        uint8_t public_key_x_bytes[48];
    };
    union {
        uint32_t public_key_y[48 / sizeof(uint32_t)];
        uint8_t public_key_y_bytes[48];
    };
    size_t private_key_len;
    size_t public_key_x_len;
    size_t public_key_y_len;
};

static struct rse_provisioning_message_blob_with_data_t __test_blob_with_data;
static struct rse_provisioning_message_blob_t *const test_blob = &__test_blob_with_data.blob;

static struct rse_provisioning_ecdsa_gen_key_data_t ecdsa_public_key_data;

/* Generated ECDSA P-384 key */
static const struct rse_provisioning_ecdsa_gen_key_data_t ecdsa_key_in_blob_data = {
    .private_key_bytes = { 0xda, 0x77, 0x9c, 0x11, 0x8b, 0x28, 0x68, 0x43, 0xb4, 0x09, 0xae, 0x7e,
                           0x6c, 0x84, 0xcc, 0xa7, 0x41, 0x7e, 0x8e, 0x54, 0xa0, 0x16, 0x11, 0xb7,
                           0xc3, 0x27, 0x3e, 0x9e, 0x8b, 0x53, 0xa0, 0x70, 0x14, 0x40, 0x2b, 0xab,
                           0xbe, 0x15, 0xdf, 0x33, 0x92, 0xc4, 0x08, 0x64, 0x99, 0x5c, 0x62, 0x76 },
    .private_key_len = 48,
    .public_key_x_bytes = { 0xda, 0xce, 0xf5, 0x48, 0xf4, 0xe8, 0x6d, 0x2a, 0xbb, 0x2d, 0xe0, 0xf8,
                            0x0f, 0xb1, 0x18, 0x71, 0xbf, 0x2c, 0xaf, 0x19, 0xde, 0x55, 0x67, 0x7a,
                            0xd5, 0x4d, 0x80, 0xe5, 0x85, 0x8c, 0x45, 0xde, 0x1f, 0x17, 0x2f, 0x54,
                            0xc9, 0x98, 0x32, 0xae, 0xff, 0x84, 0xfa, 0x2b, 0x7f, 0x90, 0xf4, 0x95 },
    .public_key_x_len = 48,
    .public_key_y_bytes = { 0x7f, 0x2c, 0x2c, 0xd1, 0x36, 0x65, 0xe3, 0x7f, 0xdc, 0x16, 0xb2, 0x98,
                            0x41, 0xdc, 0xe2, 0xf6, 0x89, 0xf6, 0x21, 0xf6, 0x92, 0x01, 0xfb, 0x6a,
                            0x6f, 0x9c, 0x08, 0x9a, 0xd2, 0xc4, 0xcf, 0x03, 0xfa, 0x60, 0xf6, 0xd4,
                            0x7c, 0x39, 0x27, 0x42, 0xb9, 0xc5, 0x26, 0x07, 0x36, 0xdc, 0xe5, 0x34 },
    .public_key_y_len = 48,
};

static struct kmu_key_export_config_t aes_key0_export_config = {
    .export_address = CC3XX_BASE_S + 0x400, /* CC3XX AES_KEY_0 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static struct kmu_key_export_config_t aes_key1_export_config = {
    .export_address = CC3XX_BASE_S + 0x420, /* CC3XX AES_KEY_1 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static struct kmu_key_export_config_t aes_128_key0_export_config = {
    .export_address = CC3XX_BASE_S + 0x400, /* CC3XX AES_KEY_0 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_4_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static const struct rse_provisioning_ecdsa_gen_key_data_t ecdsa_rom_private_key = {
    .private_key_bytes = { 0xbc, 0x65, 0x05, 0xa3, 0xa2, 0x80, 0x82, 0x68, 0xb4, 0x09, 0xf4, 0x32,
                           0x4d, 0x28, 0xcc, 0x8f, 0xa1, 0x4a, 0x05, 0x72, 0xa1, 0xa5, 0xb9, 0x71,
                           0xae, 0xd7, 0x76, 0x5f, 0xe7, 0x6e, 0x91, 0x5f, 0xa4, 0xdd, 0x46, 0x19,
                           0xe4, 0x13, 0x1b, 0x4b, 0xd5, 0x3e, 0xdf, 0x0b, 0x5d, 0xe7, 0xdf, 0x60 },
    .private_key_len = 48,
};

static inline size_t get_blob_size(struct rse_provisioning_message_blob_t *blob)
{
    return sizeof(*blob) + blob->code_size + blob->data_size + blob->secret_values_size;
}

static enum tfm_plat_err_t setup_random_key(enum rse_kmu_slot_id_t key)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;

    plat_err = setup_key_from_rng(key, &aes_key0_export_config, &aes_key1_export_config, true);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    kmu_err = kmu_set_key_locked(&KMU_DEV_S, key);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t)kmu_err;
    }

    kmu_err = kmu_set_key_locked(&KMU_DEV_S, key + 1);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t)kmu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t set_tp_mode(void)
{
    volatile enum lcm_tp_mode_t tp_mode = LCM_TP_MODE_VIRGIN;
    enum lcm_error_t lcm_err;

#ifdef TFM_DUMMY_PROVISIONING
    tp_mode = RSE_TP_MODE;
#endif /* TFM_DUMMY_PROVISIONING */
    /* Loop until someone sets this with a debugger. DUMMY_PROVISIONING will
     * have set this to TCI.
     */
    while (tp_mode != LCM_TP_MODE_PCI && tp_mode != LCM_TP_MODE_TCI) {
    }

    lcm_err = lcm_set_tp_mode(&LCM_DEV_S, tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t setup_correct_key(bool is_cm)
{
    enum tfm_plat_err_t err;
    uint8_t *label;
    uint8_t label_len;
    uint8_t context = 0;

    if (is_cm) {
        label = (uint8_t *)"KMASTER_CM";
        label_len = sizeof("KMASTER_CM");
    } else {
        label = (uint8_t *)"KMASTER_DM";
        label_len = sizeof("KMASTER_DM");
    }

    err = rse_setup_master_key(label, label_len, &context, sizeof(context));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (is_cm) {
        label = (uint8_t *)"KPROV_CM";
        label_len = sizeof("KPROV_CM");
    } else {
        label = (uint8_t *)"KPROV_DM";
        label_len = sizeof("KPROV_DM");
    }

    return rse_setup_provisioning_key(label, label_len, NULL, 0);
}

static enum tfm_plat_err_t aes_sign_encrypt_test_image(cc3xx_aes_mode_t mode,
                                                       enum rse_kmu_slot_id_t key,
                                                       struct rse_provisioning_message_blob_t *blob)
{
    enum cc3xx_error cc_err;
    size_t data_size_to_encrypt = 0;
    size_t data_size_to_auth = 0;
    uint8_t iv[AES_IV_LEN] = { 0 };
    const uint32_t authed_header_offset =
        offsetof(struct rse_provisioning_message_blob_t, metadata);
    const size_t authed_header_size =
        offsetof(struct rse_provisioning_message_blob_t, code_and_data_and_secret_values) -
        authed_header_offset;
    const size_t actual_blob_size = get_blob_size(blob);
    bool encrypt_code_data = false, encrypt_secret = false;

    /* All sizes must be multiples of 16 bytes */
    assert(((blob->code_size % 16) == 0) && ((blob->data_size % 16) == 0) &&
           ((blob->secret_values_size % 16) == 0));

    memcpy(iv, (uint8_t *)blob->iv, sizeof(blob->iv));

    if (blob_needs_code_data_decryption(blob)) {
        data_size_to_encrypt += blob->code_size;
        data_size_to_encrypt += blob->data_size;
        encrypt_code_data = true;
    }

    if (blob_needs_secret_decryption(blob)) {
        data_size_to_encrypt += blob->secret_values_size;
        encrypt_secret = true;
    }

    if ((mode == CC3XX_AES_MODE_CCM) || (data_size_to_encrypt != 0)) {
        cc_err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT, mode, (cc3xx_aes_key_id_t)key,
                                         NULL, CC3XX_AES_KEYSIZE_256, (uint32_t *)iv,
                                         mode == CC3XX_AES_MODE_CCM ? 8 : AES_IV_LEN);
        if (cc_err != CC3XX_ERR_SUCCESS) {
            return (enum tfm_plat_err_t)cc_err;
        }
    }

    data_size_to_auth = actual_blob_size - data_size_to_encrypt - authed_header_offset;

    cc3xx_lowlevel_aes_set_tag_len(AES_TAG_MAX_LEN);
    cc3xx_lowlevel_aes_set_data_len(data_size_to_encrypt, data_size_to_auth);

    cc3xx_lowlevel_aes_update_authed_data(((uint8_t *)blob) + authed_header_offset,
                                          authed_header_size);

    if (encrypt_code_data && encrypt_secret) {
        cc3xx_lowlevel_aes_set_output_buffer(blob->code_and_data_and_secret_values,
                                             blob->code_size + blob->data_size +
                                                 blob->secret_values_size);

        cc_err =
            cc3xx_lowlevel_aes_update(blob->code_and_data_and_secret_values,
                                      blob->code_size + blob->data_size + blob->secret_values_size);
        if (cc_err != CC3XX_ERR_SUCCESS) {
            return (enum tfm_plat_err_t)cc_err;
        }
    } else if (!encrypt_code_data && encrypt_secret) {
        cc3xx_lowlevel_aes_update_authed_data(blob->code_and_data_and_secret_values,
                                              blob->code_size + blob->data_size);

        cc3xx_lowlevel_aes_set_output_buffer(blob->code_and_data_and_secret_values +
                                                 blob->code_size + blob->data_size,
                                             blob->secret_values_size);

        cc_err = cc3xx_lowlevel_aes_update(blob->code_and_data_and_secret_values + blob->code_size +
                                               blob->data_size,
                                           blob->secret_values_size);
        if (cc_err != CC3XX_ERR_SUCCESS) {
            return (enum tfm_plat_err_t)cc_err;
        }
    } else if (!encrypt_code_data && !encrypt_secret) {
        cc3xx_lowlevel_aes_update_authed_data(blob->code_and_data_and_secret_values,
                                              blob->code_size + blob->data_size +
                                                  blob->secret_values_size);
    } else {
        return TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_DECRYPTION_CONFIG;
    }

    if ((mode == CC3XX_AES_MODE_CCM) || (data_size_to_encrypt != 0)) {
        cc_err = cc3xx_lowlevel_aes_finish((uint32_t *)blob->signature, NULL);
        if (cc_err != CC3XX_ERR_SUCCESS) {
            return (enum tfm_plat_err_t)cc_err;
        }
    }

    if (mode == CC3XX_AES_MODE_CCM) {
        blob->signature_size = AES_TAG_MAX_LEN;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t hash_test_image(struct rse_provisioning_message_blob_t *blob,
                                           uint8_t *hash, size_t *hash_size)
{
    fih_int fih_rc;
    const uint32_t authed_header_offset =
        offsetof(struct rse_provisioning_message_blob_t, metadata);
    const size_t authed_header_size =
        offsetof(struct rse_provisioning_message_blob_t, code_and_data_and_secret_values) -
        authed_header_offset;

    fih_rc = bl1_hash_compute(RSE_PROVISIONING_HASH_ALG, (uint8_t *)blob + authed_header_offset,
                              authed_header_size + blob->code_size + blob->data_size +
                                  blob->secret_values_size,
                              hash, RSE_PROVISIONING_HASH_SIZE, hash_size);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)fih_rc;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t ecdsa_sign_test_image(struct rse_provisioning_message_blob_t *blob,
                                                 const uint32_t *private_key,
                                                 size_t private_key_size)
{
    enum tfm_plat_err_t err;
    cc3xx_err_t cc_err;
    uint32_t hash[RSE_PROVISIONING_HASH_SIZE / sizeof(uint32_t)];
    size_t hash_size, point_size, r_size, s_size;

    err = hash_test_image(blob, (uint8_t *)hash, &hash_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    point_size = cc3xx_lowlevel_ec_get_modulus_size_from_curve(RSE_PROVISIONING_CURVE);
    blob->signature_size = point_size * 2;

    cc_err = cc3xx_lowlevel_ecdsa_sign(RSE_PROVISIONING_CURVE, private_key, private_key_size, hash,
                                       hash_size, (uint32_t *)blob->signature, point_size, &r_size,
                                       (uint32_t *)(blob->signature + point_size), point_size,
                                       &s_size);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t ecdsa_generate_public_private_key_pair(
    uint32_t *private_key, size_t private_key_len, size_t *private_key_size, uint32_t *public_key_x,
    size_t public_key_x_len, size_t *public_key_x_size, uint32_t *public_key_y,
    size_t public_key_y_len, size_t *public_key_y_size)
{
    cc3xx_err_t cc_err;

    cc_err = cc3xx_lowlevel_ecdsa_genkey(RSE_PROVISIONING_CURVE, private_key, private_key_len,
                                         private_key_size);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc_err;
    }

    cc_err = cc3xx_lowlevel_ecdsa_getpub(RSE_PROVISIONING_CURVE, private_key, private_key_len,
                                         public_key_x, public_key_x_len, public_key_x_size,
                                         public_key_y, public_key_y_len, public_key_y_size);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t
ecdsa_initialise_key_data(struct rse_provisioning_ecdsa_gen_key_data_t *data)
{
    return ecdsa_generate_public_private_key_pair(
        data->private_key, sizeof(data->private_key), &data->private_key_len, data->public_key_x,
        sizeof(data->public_key_x), &data->public_key_x_len, data->public_key_y,
        sizeof(data->public_key_y), &data->public_key_y_len);
}

static enum tfm_plat_err_t
ecdsa_sign_then_encrypt_test_image(const uint32_t *private_key, size_t private_key_len,
                                   enum rse_kmu_slot_id_t key,
                                   struct rse_provisioning_message_blob_t *blob)
{
    enum tfm_plat_err_t err;

    err = ecdsa_sign_test_image(blob, private_key, private_key_len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return aes_sign_encrypt_test_image(CC3XX_AES_MODE_CTR, key, blob);
}

static void init_test_image(struct rse_provisioning_message_blob_t *blob,
                            enum rse_provisioning_blob_signature_config_t signature_config,
                            size_t code_size, size_t data_size, size_t secret_size,
                            bool encrypt_code_data, bool encrypt_secret)
{
    enum rse_provisioning_blob_code_and_data_decryption_config_t code_data_encrypt_config;
    enum rse_provisioning_blob_secret_values_decryption_config_t secret_encrypt_config;

    code_data_encrypt_config = encrypt_code_data ? RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES :
                                                   RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_NONE;
    blob->metadata |=
        (code_data_encrypt_config & RSE_PROVISIONING_BLOB_DETAILS_CODE_DATA_DECRYPTION_MASK)
        << RSE_PROVISIONING_BLOB_DETAILS_CODE_DATA_DECRYPTION_OFFSET;
    secret_encrypt_config = encrypt_secret ? RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES :
                                             RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_BY_BLOB;
    blob->metadata |=
        (secret_encrypt_config & RSE_PROVISIONING_BLOB_DETAILS_SECRET_VALUES_DECRYPTION_MASK)
        << RSE_PROVISIONING_BLOB_DETAILS_SECRET_VALUES_DECRYPTION_OFFSET;

    blob->metadata |= (signature_config & RSE_PROVISIONING_BLOB_DETAILS_SIGNATURE_MASK)
                      << RSE_PROVISIONING_BLOB_DETAILS_SIGNATURE_OFFSET;

    if (signature_config == RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM) {
        /* No need to set CM_ROTPK_NUMBER as always assume we are using 0 */
        blob->metadata |= (RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_CM_ROTPK &
                           RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_MASK)
                          << RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_OFFSET;
    }

    blob->code_size = code_size;
    blob->data_size = data_size;
    blob->secret_values_size = secret_size;

    memcpy(blob->iv, IV_RANDOM_BYTES, sizeof(blob->iv));
}

static enum tfm_plat_err_t test_teardown(enum rse_kmu_slot_id_t key,
                                         struct rse_provisioning_message_blob_t *blob)
{
    enum kmu_error_t kmu_err;

    if (blob != NULL) {
        memset(blob, 0, sizeof(*blob) + CODE_DATA_SECRET_VALUES_SIZE);
    }

    if (key != 0) {
        kmu_err = kmu_set_slot_invalid(&KMU_DEV_S, key);
        if (kmu_err != KMU_ERROR_NONE) {
            return (enum tfm_plat_err_t)kmu_err;
        }

        kmu_err = kmu_set_slot_invalid(&KMU_DEV_S, key + 1);
        if (kmu_err != KMU_ERROR_NONE) {
            return (enum tfm_plat_err_t)kmu_err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t
setup_provisioning_aes_key(const struct rse_provisioning_message_blob_t *blob, uint32_t *key_id)
{
    /* Key setup in setup_random_key */
    *key_id = RSE_KMU_SLOT_PROVISIONING_KEY;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t get_global_public_key(const struct rse_provisioning_message_blob_t *blob,
                                                 uint32_t **public_key_x, size_t *public_key_x_size,
                                                 uint32_t **public_key_y, size_t *public_key_y_size)
{
    *public_key_x = ecdsa_public_key_data.public_key_x;
    *public_key_x_size = ecdsa_public_key_data.public_key_x_len;
    *public_key_y = ecdsa_public_key_data.public_key_y;
    *public_key_y_size = ecdsa_public_key_data.public_key_y_len;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t
init_test_image_sign_random_key(struct rse_provisioning_message_blob_t *blob,
                                struct rse_provisioning_ecdsa_gen_key_data_t *ecdsa_data,
                                enum rse_provisioning_blob_signature_config_t signature_config,
                                size_t code_size, size_t data_size, size_t secret_size,
                                bool encrypt_code_data, bool encrypt_secret)
{
    enum tfm_plat_err_t err;

    init_test_image(blob, signature_config, code_size, data_size, secret_size, encrypt_code_data,
                    encrypt_secret);

    memcpy(blob->code_and_data_and_secret_values, CODE_RANDOM_BYTES, sizeof(CODE_RANDOM_BYTES) - 1);
    memcpy(blob->code_and_data_and_secret_values + blob->code_size, DATA_RANDOM_BYTES,
           sizeof(DATA_RANDOM_BYTES) - 1);
    memcpy(blob->code_and_data_and_secret_values + blob->code_size + blob->data_size,
           VALUES_RANDOM_BYTES, sizeof(VALUES_RANDOM_BYTES) - 1);

    err = setup_random_key(RSE_KMU_SLOT_PROVISIONING_KEY);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    switch (signature_config) {
    case RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE:
        return aes_sign_encrypt_test_image(CC3XX_AES_MODE_CCM, RSE_KMU_SLOT_PROVISIONING_KEY, blob);
    case RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_IN_ROM:
    case RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM:
        return ecdsa_sign_then_encrypt_test_image(ecdsa_data->private_key,
                                                  ecdsa_data->private_key_len,
                                                  RSE_KMU_SLOT_PROVISIONING_KEY, blob);
    default:
        return TFM_PLAT_ERR_PROVISIONING_SIGNATURE_TYPE_NOT_SUPPORTED;
    }
}

void rse_bl1_provisioning_test_0001(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;

    bool code_data_encrypted[] = { false, true };

    enum rse_provisioning_blob_signature_config_t signature_config[] = {
        RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE,
        RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_IN_ROM,
    };

    TEST_SETUP(ecdsa_initialise_key_data(&ecdsa_public_key_data));

    for (int encryption_idx = 0; encryption_idx < ARRAY_SIZE(code_data_encrypted);
         encryption_idx++) {
        for (int signature_idx = 0; signature_idx < ARRAY_SIZE(signature_config); signature_idx++) {
            TEST_LOG(" > signature validation test %s %s: ",
                     signature_config[signature_idx] ==
                             RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE ?
                         "AES" :
                         "ECDSA",
                     code_data_encrypted[encryption_idx] ? "encrypted" : "not encrypted");

            TEST_SETUP(init_test_image_sign_random_key(test_blob, &ecdsa_public_key_data,
                                                       signature_config[signature_idx], 32, 32, 32,
                                                       code_data_encrypted[encryption_idx], true));

            plat_err = validate_and_unpack_blob(
                test_blob, get_blob_size(test_blob), (void *)PROVISIONING_BUNDLE_CODE_START,
                PROVISIONING_BUNDLE_CODE_SIZE, (void *)PROVISIONING_BUNDLE_DATA_START,
                PROVISIONING_BUNDLE_DATA_SIZE, (void *)PROVISIONING_BUNDLE_VALUES_START,
                PROVISIONING_BUNDLE_VALUES_SIZE, setup_provisioning_aes_key, get_global_public_key);

            TEST_LOG("\r");

            TEST_ASSERT(plat_err == TFM_PLAT_ERR_SUCCESS, "\nSignature validation failed");

            TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, test_blob));
        }
    }

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0002(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    const size_t code_size = 32, values_size = 32, secret_size = 32;

    uint8_t *corruption_ptrs[] = {
        (uint8_t *)&test_blob->metadata,
        (uint8_t *)&test_blob->purpose,
        (uint8_t *)&test_blob->version,
        (uint8_t *)&test_blob->iv,
        (uint8_t *)&test_blob->code_size,
        (uint8_t *)&test_blob->data_size,
        (uint8_t *)&test_blob->secret_values_size,
        (uint8_t *)test_blob->code_and_data_and_secret_values,
        (uint8_t *)(test_blob->code_and_data_and_secret_values + code_size),
        (uint8_t *)(test_blob->code_and_data_and_secret_values + code_size + values_size),
    };

    enum rse_provisioning_blob_signature_config_t signature_config[] = {
        RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE,
        RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_IN_ROM,
    };

    TEST_SETUP(ecdsa_initialise_key_data(&ecdsa_public_key_data));

    for (int idx = 0; idx < ARRAY_SIZE(corruption_ptrs); idx++) {
        for (int signature_idx = 0; signature_idx < ARRAY_SIZE(signature_config); signature_idx++) {
            TEST_SETUP(init_test_image_sign_random_key(test_blob, &ecdsa_public_key_data,
                                                       signature_config[signature_idx], code_size,
                                                       values_size, secret_size, false, true));

            *(uint32_t *)corruption_ptrs[idx] ^= 0xDEADBEEF;

            TEST_LOG(" > %s signature: testing corruption at offset %d (%d of %d): ",
                     signature_config[signature_idx] ==
                             RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE ?
                         "AES" :
                         "ECDSA",
                     (uintptr_t)corruption_ptrs[idx] - (uintptr_t)&test_blob, idx + 1,
                     ARRAY_SIZE(corruption_ptrs));

            plat_err = validate_and_unpack_blob(
                test_blob, get_blob_size(test_blob), (void *)PROVISIONING_BUNDLE_CODE_START,
                PROVISIONING_BUNDLE_CODE_SIZE, (void *)PROVISIONING_BUNDLE_DATA_START,
                PROVISIONING_BUNDLE_DATA_SIZE, (void *)PROVISIONING_BUNDLE_VALUES_START,
                PROVISIONING_BUNDLE_VALUES_SIZE, setup_provisioning_aes_key, get_global_public_key);

            TEST_LOG("\r");

            TEST_ASSERT(plat_err != TFM_PLAT_ERR_SUCCESS,
                        "\nSignature validation succeeded when it should have failed");

            TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, test_blob));
        }
    }

    ret->val = TEST_PASSED;
    return;
}

static const enum rse_kmu_slot_id_t invalid_kmu_keys[] = {
    26, /* Size mismatch */
    28, /* Not locked */
    _RSE_KMU_AEAD_RESERVED_SLOT_PROVISIONING_KEY, /* No valid AEAD key in next slot */
    (enum rse_kmu_slot_id_t)KMU_HW_SLOT_GUK, /* Can't use HW keys for AEAD */
    30, /* Not set up at all */
};

static enum tfm_plat_err_t setup_invalid_aes_key(const struct rse_provisioning_message_blob_t *blob,
                                                 uint32_t *key_id)
{
    static size_t counter;

    *key_id = invalid_kmu_keys[counter++];

    return TFM_PLAT_ERR_SUCCESS;
}

void rse_bl1_provisioning_test_0003(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;
    volatile uint32_t *slot_ptr;
    size_t slot_size;

    TEST_SETUP(setup_key_from_rng(invalid_kmu_keys[0], &aes_128_key0_export_config,
                                  &aes_key1_export_config, true));
    TEST_SETUP(kmu_get_key_buffer_ptr(&KMU_DEV_S, invalid_kmu_keys[0], &slot_ptr, &slot_size));
    for (int idx = slot_size / sizeof(uint32_t); idx < 8; idx++) {
        slot_ptr[idx] = 0xDEADBEEF;
    }

    TEST_SETUP(setup_key_from_rng(invalid_kmu_keys[1], &aes_key0_export_config,
                                  &aes_key1_export_config, true));
    TEST_SETUP(kmu_set_key_locked(&KMU_DEV_S, invalid_kmu_keys[1]));

    TEST_SETUP(init_test_image_sign_random_key(
        test_blob, NULL, RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE, 32, 32, 32, false, true));

    for (int idx = 0; idx < ARRAY_SIZE(invalid_kmu_keys); idx++) {
        TEST_LOG(" > testing invalid key %d (%d of %d): ", invalid_kmu_keys[idx], idx + 1,
                 ARRAY_SIZE(invalid_kmu_keys));

        plat_err = validate_and_unpack_blob(
            test_blob, get_blob_size(test_blob), (void *)PROVISIONING_BUNDLE_CODE_START,
            PROVISIONING_BUNDLE_CODE_SIZE, (void *)PROVISIONING_BUNDLE_DATA_START,
            PROVISIONING_BUNDLE_DATA_SIZE, (void *)PROVISIONING_BUNDLE_VALUES_START,
            PROVISIONING_BUNDLE_VALUES_SIZE, setup_invalid_aes_key, NULL);

        TEST_LOG("\r");

        TEST_ASSERT(plat_err == (enum tfm_plat_err_t)CC3XX_ERR_KEY_IMPORT_FAILED,
                    "\nKey loading succeeded when it should have failed");

        TEST_TEARDOWN(test_teardown(invalid_kmu_keys[idx], NULL));
    }

    TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, test_blob));

    ret->val = TEST_PASSED;
    return;
}

static struct rse_provisioning_ecdsa_gen_key_data_t invalid_ecdsa_keys[2];

enum tfm_plat_err_t get_invalid_public_key(const struct rse_provisioning_message_blob_t *blob,
                                           uint32_t **public_key_x, size_t *public_key_x_size,
                                           uint32_t **public_key_y, size_t *public_key_y_size)
{
    static size_t counter;
    struct rse_provisioning_ecdsa_gen_key_data_t *ecdsa_data = &invalid_ecdsa_keys[counter++];

    *public_key_x = ecdsa_data->public_key_x;
    *public_key_x_size = ecdsa_data->public_key_x_len;
    *public_key_y = ecdsa_data->public_key_y;
    *public_key_y_size = ecdsa_data->public_key_y_len;

    return TFM_PLAT_ERR_SUCCESS;
}

void rse_bl1_provisioning_test_0004(struct test_result_t *ret)
{
    enum tfm_plat_err_t plat_err;

    /* Not setup at all */
    memset(&invalid_ecdsa_keys[0], 0, sizeof(invalid_ecdsa_keys[0]));

    /* Setup to valid but different ECDSA key */
    TEST_SETUP(ecdsa_initialise_key_data(&invalid_ecdsa_keys[1]));

    TEST_SETUP(ecdsa_initialise_key_data(&ecdsa_public_key_data));

    TEST_SETUP(init_test_image_sign_random_key(test_blob, &ecdsa_public_key_data,
                                               RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_IN_ROM, 32, 32,
                                               32, false, true));

    for (int idx = 0; idx < ARRAY_SIZE(invalid_ecdsa_keys); idx++) {
        TEST_LOG(" > testing invalid key %d (%d of %d): ", invalid_ecdsa_keys[idx], idx + 1,
                 ARRAY_SIZE(invalid_ecdsa_keys));

        plat_err = validate_and_unpack_blob(
            test_blob, get_blob_size(test_blob), (void *)PROVISIONING_BUNDLE_CODE_START,
            PROVISIONING_BUNDLE_CODE_SIZE, (void *)PROVISIONING_BUNDLE_DATA_START,
            PROVISIONING_BUNDLE_DATA_SIZE, (void *)PROVISIONING_BUNDLE_VALUES_START,
            PROVISIONING_BUNDLE_VALUES_SIZE, setup_provisioning_aes_key, get_invalid_public_key);

        TEST_LOG("\r");

        TEST_ASSERT(plat_err == (enum tfm_plat_err_t)CC3XX_ERR_ECDSA_SIGNATURE_INVALID,
                    "\nSignature check succeeded when it should have failed");
    }

    TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, test_blob));

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0005(struct test_result_t *ret)
{
    bool provisioning_is_required;
    enum lcm_lcs_t lcs;

    TEST_SETUP(lcm_get_lcs(&LCM_DEV_S, &lcs));

    switch(lcs) {
        case LCM_LCS_CM:
            provisioning_is_required = true;
            break;
        case LCM_LCS_DM:
            provisioning_is_required = true;
            break;
        case LCM_LCS_SE:
            provisioning_is_required = false;
            break;
        case LCM_LCS_RMA:
            provisioning_is_required = false;
            break;
        case LCM_LCS_INVALID:
            provisioning_is_required = false;
            break;
        default:
            TEST_FAIL("Invalid LCS");
            return;
    }

    TEST_ASSERT(tfm_plat_provisioning_is_required() == provisioning_is_required,
                "Provisioning requirements check failed");

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0101(struct test_result_t *ret)
{
    TEST_ASSERT(set_tp_mode() != TFM_PLAT_ERR_SUCCESS,
                "TP mode set should fail when not in CM");

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0201(struct test_result_t *ret)
{
    TEST_ASSERT(setup_correct_key(true) == TFM_PLAT_ERR_SUCCESS,
                "CM Key derivation should work in secure provisioning mode");
    TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, NULL));
    TEST_TEARDOWN(kmu_set_slot_invalid(&KMU_DEV_S, RSE_KMU_SLOT_MASTER_KEY))

    TEST_ASSERT(setup_correct_key(false) == TFM_PLAT_ERR_SUCCESS,
                "DM Key derivation should work in secure provisioning mode");
    TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, NULL));
    TEST_TEARDOWN(kmu_set_slot_invalid(&KMU_DEV_S, RSE_KMU_SLOT_MASTER_KEY));

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0202(struct test_result_t *ret)
{
    TEST_ASSERT(setup_correct_key(true) != TFM_PLAT_ERR_SUCCESS,
                "CM Key derivation should not be possible outside of secure provisioning mode");

    TEST_ASSERT(setup_correct_key(false) != TFM_PLAT_ERR_SUCCESS,
                "DM Key derivation should not be possible outside of secure provisioning mode");

    ret->val = TEST_PASSED;
    return;
}

static void setup_blob_with_provisioning_config(struct rse_provisioning_message_blob_t *blob,
                                                enum lcm_tp_mode_t tp_mode,
                                                enum lcm_lcs_t *valid_lcs, size_t num_lcs,
                                                bool sp_required)
{
    enum rse_provisioning_blob_required_tp_mode_config_t tp_mode_config;
    enum rse_provisioning_blob_valid_lcs_mask_t lcs_mask = 0;
    enum rse_provisioning_blob_required_sp_mode_config_t sp_mode_config;

    switch (tp_mode) {
    case LCM_TP_MODE_VIRGIN:
        tp_mode_config = RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_VIRGIN;
        break;
    case LCM_TP_MODE_PCI:
        tp_mode_config = RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_PCI;
        break;
    case LCM_TP_MODE_TCI:
        tp_mode_config = RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_TCI;
        break;
    default:
        tp_mode_config = 0;
        break;
    }

    blob->purpose |= (tp_mode_config & RSE_PROVISIONING_BLOB_PURPOSE_TP_MODE_MASK)
                     << RSE_PROVISIONING_BLOB_PURPOSE_TP_MODE_OFFSET;

    for (unsigned i = 0; i < num_lcs; i++) {
        switch (valid_lcs[i]) {
        case LCM_LCS_CM:
            lcs_mask |= RSE_PROVISIONING_BLOB_VALID_IN_CM_LCS;
            break;
        case LCM_LCS_DM:
            lcs_mask |= RSE_PROVISIONING_BLOB_VALID_IN_DM_LCS;
            break;
        case LCM_LCS_SE:
            lcs_mask |= RSE_PROVISIONING_BLOB_VALID_IN_SE_LCS;
            break;
        case LCM_LCS_RMA:
            lcs_mask |= RSE_PROVISIONING_BLOB_VALID_IN_RMA_LCS;
            break;
        default:
            break;
        }
    }

    blob->purpose |= (lcs_mask & RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_MASK)
                     << RSE_PROVISIONING_BLOB_PURPOSE_LCS_MASK_OFFSET;

    sp_mode_config = sp_required ? RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_ENABLED :
                                   RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_DISABLED;
    blob->purpose |= (sp_mode_config & RSE_PROVISIONING_BLOB_PURPOSE_SP_MODE_MASK)
                     << RSE_PROVISIONING_BLOB_PURPOSE_SP_MODE_OFFSET;
}

static enum tfm_plat_err_t provision_blob(struct rse_provisioning_message_blob_t *blob)
{
    size_t blob_size;
    static struct {
        struct rse_provisioning_message_t message;
        uint8_t __data[CODE_DATA_SECRET_VALUES_SIZE];
    } message_with_data;
    struct default_blob_handler_ctx_t ctx;
    struct provisioning_message_handler_config config;
    struct rse_provisioning_message_t *message = &message_with_data.message;

    blob_size = get_blob_size(blob);

    message->header.type = RSE_PROVISIONING_MESSAGE_TYPE_BLOB;
    message->header.data_length = blob_size;
    memcpy(&message->blob, blob, blob_size);

    ctx.blob_is_chainloaded = false;
    ctx.setup_aes_key = setup_provisioning_aes_key;
    ctx.get_rotpk = provisioning_rotpk_get;

    config.blob_handler = default_blob_handler;

    return handle_provisioning_message(message, sizeof(message->header) + blob_size, &config, &ctx);
}

static void provisioning_test_invalid_lcs(struct test_result_t *ret, enum lcm_lcs_t lcs)
{
    enum tfm_plat_err_t plat_err;

    setup_blob_with_provisioning_config(test_blob, LCM_TP_MODE_PCI, &lcs, 1, true);
    plat_err = provision_blob(test_blob);
    if (plat_err != TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_PURPOSE) {
        TEST_FAIL("PCI blob provisioning should not be possible with invalid LCS");
        return;
    }
    TEST_TEARDOWN(test_teardown(0, test_blob));

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0301(struct test_result_t *ret)
{
    provisioning_test_invalid_lcs(ret, LCM_LCS_DM);
}

void rse_bl1_provisioning_test_0302(struct test_result_t *ret)
{
    provisioning_test_invalid_lcs(ret, LCM_LCS_CM);
}

static void provisioning_test_invalid_image(struct test_result_t *ret, enum lcm_tp_mode_t tp_mode,
                                            enum lcm_lcs_t *valid_lcs, size_t num_lcs,
                                            bool sp_required)
{
    enum tfm_plat_err_t plat_err;

    setup_blob_with_provisioning_config(test_blob, tp_mode, valid_lcs, num_lcs, sp_required);
    plat_err = provision_blob(test_blob);
    if (plat_err != TFM_PLAT_ERR_PROVISIONING_BLOB_ZERO_CODE_SIZE) {
        TEST_FAIL("Blob provisioning should not be possible with invalid image");
        return;
    }
    TEST_TEARDOWN(test_teardown(0, test_blob));

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0401(struct test_result_t *ret)
{
    enum lcm_lcs_t valid_lcs[] = { LCM_LCS_CM, LCM_LCS_DM, LCM_LCS_SE, LCM_LCS_RMA };

    provisioning_test_invalid_image(ret, LCM_TP_MODE_PCI, valid_lcs, ARRAY_SIZE(valid_lcs), true);
}

void rse_bl1_provisioning_test_0402(struct test_result_t *ret)
{
    enum lcm_lcs_t valid_lcs[] = { LCM_LCS_CM, LCM_LCS_DM, LCM_LCS_SE, LCM_LCS_RMA };

    provisioning_test_invalid_image(ret, LCM_TP_MODE_TCI, valid_lcs, ARRAY_SIZE(valid_lcs), true);
}

static int __attribute__((naked)) return_true(void) {
    __ASM volatile(
#if !defined(__ICCARM__)
        ".syntax unified                               \n"
#endif
        "movs    r0, #0xA                              \n"
        "bx lr                                         \n");
}

static int __attribute__((naked)) return_false(void) {
    __ASM volatile(
#if !defined(__ICCARM__)
        ".syntax unified                               \n"
#endif
        "movs    r0, #0xB                              \n"
        "bx lr                                         \n");
}

static enum tfm_plat_err_t
create_complete_signed_blob(struct rse_provisioning_message_blob_t *blob,
                            const struct rse_provisioning_ecdsa_gen_key_data_t *key_data,
                            uintptr_t func_ptr, enum lcm_tp_mode_t tp_mode,
                            enum lcm_lcs_t *valid_lcs, size_t num_lcs, bool sp_required,
                            enum rse_provisioning_blob_signature_config_t signature_config,
                            bool encrypt_code_data, bool encrypt_secret)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;
    const size_t code_size = 16; /* Pad out to 16 bytes */

    setup_blob_with_provisioning_config(blob, tp_mode, valid_lcs, num_lcs, sp_required);

    memcpy(blob->code_and_data_and_secret_values, (void *)(func_ptr & ~0x1),
           sizeof(uint32_t) /* 2 x 2 byte instructions */);

    init_test_image(blob, signature_config, code_size, 32, 32, encrypt_code_data, encrypt_secret);

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    plat_err = setup_correct_key(lcs == LCM_LCS_CM);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    switch (signature_config) {
    case RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE:
        return aes_sign_encrypt_test_image(CC3XX_AES_MODE_CCM, RSE_KMU_SLOT_PROVISIONING_KEY, blob);
    case RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM:
        memcpy(blob->public_key, key_data->public_key_x, key_data->public_key_x_len);
        memcpy(blob->public_key + key_data->public_key_x_len, key_data->public_key_y,
               key_data->public_key_y_len);
        return ecdsa_sign_then_encrypt_test_image(key_data->private_key, key_data->private_key_len,
                                                  RSE_KMU_SLOT_PROVISIONING_KEY, blob);
    case RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_IN_ROM:
        return ecdsa_sign_then_encrypt_test_image(key_data->private_key,
                                                  key_data->private_key_len,
                                                  RSE_KMU_SLOT_PROVISIONING_KEY, blob);
    default:
        return TFM_PLAT_ERR_PROVISIONING_SIGNATURE_TYPE_NOT_SUPPORTED;
    }
}

static void provisioning_test_complete_valid_blob(
    struct test_result_t *ret, enum lcm_tp_mode_t tp_mode,
    const struct rse_provisioning_ecdsa_gen_key_data_t *key_data,
    enum rse_provisioning_blob_signature_config_t *signature_config, size_t signature_config_size)
{
    enum tfm_plat_err_t plat_err;

    uintptr_t test_payload_pointers[] = {
        (uintptr_t)return_true,
        (uintptr_t)return_false
    };

    int test_payload_return_values[] = { 0xA, 0xB };

    bool code_data_encrypted[] = { false, true };

    enum lcm_lcs_t valid_lcs[] = { LCM_LCS_CM, LCM_LCS_DM, LCM_LCS_SE, LCM_LCS_RMA };

    for (int test_payload_idx = 0; test_payload_idx < ARRAY_SIZE(test_payload_pointers);
         test_payload_idx++) {
        for (int encryption_idx = 0; encryption_idx < ARRAY_SIZE(code_data_encrypted);
             encryption_idx++) {
            for (int signature_idx = 0; signature_idx < signature_config_size; signature_idx++) {
                TEST_LOG(" > provisioning blob test %s %s %s payload 0x%x: ",
                         signature_config[signature_idx] ==
                                 RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE ?
                             "AES" :
                             "ECDSA",
                         signature_config[signature_idx] ==
                                 RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM ?
                             "in blob" :
                             "",
                         code_data_encrypted[encryption_idx] ? "encrypted" : "not encrypted",
                         test_payload_return_values[test_payload_idx]);

                TEST_SETUP(create_complete_signed_blob(
                    test_blob, key_data, test_payload_pointers[test_payload_idx], tp_mode,
                    valid_lcs, ARRAY_SIZE(valid_lcs), true, signature_config[signature_idx],
                    code_data_encrypted[encryption_idx], true));

                plat_err = provision_blob(test_blob);

                TEST_LOG("\r");

                TEST_ASSERT(plat_err == test_payload_return_values[test_payload_idx],
                            "\nProvisioning should return with the value the blob returns");

                TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, test_blob));
                TEST_TEARDOWN(kmu_set_slot_invalid(&KMU_DEV_S, RSE_KMU_SLOT_MASTER_KEY));
            }
        }
    }

    ret->val = TEST_PASSED;
    return;
}

static void provisioning_test_public_key_not_in_blob(struct test_result_t *ret,
                                                     enum lcm_tp_mode_t tp_mode)
{
    enum rse_provisioning_blob_signature_config_t signature_config[] = {
        RSE_PROVISIONING_BLOB_SIGNATURE_KRTL_DERIVATIVE,
        RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_IN_ROM,
    };

    provisioning_test_complete_valid_blob(ret, tp_mode, &ecdsa_rom_private_key, signature_config,
                                          ARRAY_SIZE(signature_config));
}

void rse_bl1_provisioning_test_0403(struct test_result_t *ret)
{
    provisioning_test_public_key_not_in_blob(ret, LCM_TP_MODE_PCI);
}

void rse_bl1_provisioning_test_0404(struct test_result_t *ret)
{
    provisioning_test_public_key_not_in_blob(ret, LCM_TP_MODE_TCI);
}

#define DM_SIGN_KEY_CM_ROTPK_HASH_SIZE \
    (RSE_ROTPK_SIZE_FROM_ALG(RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG))
#define DM_SIGN_KEY_CM_ROTPK_BL1_HASH_ALG                                          \
    (RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG == RSE_ROTPK_HASH_ALG_SHA256 ? \
         TFM_BL1_HASH_ALG_SHA256 :                                                 \
     RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG == RSE_ROTPK_HASH_ALG_SHA384 ? \
         TFM_BL1_HASH_ALG_SHA384 :                                                 \
         0)

static enum tfm_plat_err_t
ecdsa_key_write_otp(const struct rse_provisioning_ecdsa_gen_key_data_t *data, uint32_t rotpk_idx)
{
    fih_int fih_rc;
    enum tfm_plat_err_t plat_err;
    enum lcm_error_t lcm_err;
    static uint8_t asn1_key[120];
    static uint8_t key_hash[DM_SIGN_KEY_CM_ROTPK_HASH_SIZE];
    size_t asn1_key_len;
    size_t key_hash_size;
    static struct rse_otp_cm_rotpk_area_t rotpk_area;
    const uint32_t offset =
        sizeof(struct rse_otp_header_area_t) + offsetof(struct rse_otp_cm_area_t, rotpk_areas);
    const uint32_t rotpk_policies =
        ((RSE_ROTPK_TYPE_ECDSA & 0b11) << (2 * rotpk_idx)) |
        ((RSE_ROTPK_POLICY_SIG_REQUIRED & 0b1) << (18 + rotpk_idx)) |
        ((RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG & 0b1) << (12 + rotpk_idx));

    /* No need to write if already written to OTP */
    lcm_err = lcm_otp_read(&LCM_DEV_S, offset, sizeof(rotpk_area), (uint8_t *)&rotpk_area);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
    if (rotpk_area.cm_rotpk_policies == rotpk_policies) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    plat_err = get_asn1_from_raw_ec((const uint8_t *)data->public_key_x, data->public_key_x_len,
                                    (const uint8_t *)data->public_key_y, data->public_key_y_len,
                                    RSE_PROVISIONING_CURVE, asn1_key, &asn1_key_len);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    fih_rc = bl1_hash_compute(DM_SIGN_KEY_CM_ROTPK_BL1_HASH_ALG, asn1_key, asn1_key_len, key_hash,
                              DM_SIGN_KEY_CM_ROTPK_HASH_SIZE, &key_hash_size);
    if (fih_not_eq(fih_rc, FIH_SUCCESS)) {
        return (enum tfm_plat_err_t)fih_rc;
    }

    memcpy(rotpk_area.rotpk[rotpk_idx], key_hash, key_hash_size);
    rotpk_area.cm_rotpk_policies = rotpk_policies;

    lcm_err = lcm_otp_write(&LCM_DEV_S, offset, sizeof(rotpk_area), (uint8_t *)&rotpk_area);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

void rse_bl1_provisioning_test_0405(struct test_result_t *ret)
{
    /* Setup for public key in blob test by writing a generated
     * public key into the OTP in CM mode */
    TEST_SETUP(ecdsa_key_write_otp(&ecdsa_key_in_blob_data, 0));

    ret->val = TEST_PASSED;
    return;
}

static void provisioning_test_public_key_in_blob(struct test_result_t *ret,
                                                 enum lcm_tp_mode_t tp_mode)
{
    enum rse_provisioning_blob_signature_config_t signature_config[] = {
        RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM,
    };

    provisioning_test_complete_valid_blob(ret, tp_mode, &ecdsa_key_in_blob_data, signature_config,
                                          ARRAY_SIZE(signature_config));
}

void rse_bl1_provisioning_test_0406(struct test_result_t *ret)
{
    provisioning_test_public_key_in_blob(ret, LCM_TP_MODE_PCI);
}

void rse_bl1_provisioning_test_0407(struct test_result_t *ret)
{
    provisioning_test_public_key_in_blob(ret, LCM_TP_MODE_TCI);
}

static void provisioning_test_invalid_public_key_in_blob(struct test_result_t *ret,
                                                         enum lcm_tp_mode_t tp_mode)
{
    enum tfm_plat_err_t plat_err;

    enum lcm_lcs_t valid_lcs[] = { LCM_LCS_CM, LCM_LCS_DM, LCM_LCS_SE, LCM_LCS_RMA };

    /* Use different key from what is written to OTP */
    TEST_SETUP(ecdsa_initialise_key_data(&ecdsa_public_key_data));

    TEST_SETUP(create_complete_signed_blob(
        test_blob, &ecdsa_public_key_data, (uintptr_t)return_true, tp_mode, valid_lcs,
        ARRAY_SIZE(valid_lcs), true, RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM, true, true));

    plat_err = provision_blob(test_blob);

    TEST_ASSERT(plat_err == TFM_PLAT_ERR_PROVISIONING_BLOB_INVALID_HASH_VALUE,
                "Provisioning should have failed due to invalid hash value");

    TEST_TEARDOWN(test_teardown(RSE_KMU_SLOT_PROVISIONING_KEY, test_blob));
    TEST_TEARDOWN(kmu_set_slot_invalid(&KMU_DEV_S, RSE_KMU_SLOT_MASTER_KEY));

    ret->val = TEST_PASSED;
    return;
}

void rse_bl1_provisioning_test_0408(struct test_result_t *ret)
{
    provisioning_test_invalid_public_key_in_blob(ret, LCM_TP_MODE_PCI);
}

void rse_bl1_provisioning_test_0409(struct test_result_t *ret)
{
    provisioning_test_invalid_public_key_in_blob(ret, LCM_TP_MODE_TCI);
}
