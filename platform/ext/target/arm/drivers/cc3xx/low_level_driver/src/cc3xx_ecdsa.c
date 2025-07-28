/*
 * Copyright (c) 2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "cc3xx_ecdsa.h"

#include "cc3xx_ec.h"
#include "cc3xx_kdf.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include <stdint.h>
#include <stddef.h>

#include "fatal_error.h"

#define BITS_TO_BYTES(bits) (((bits) + 7u) / 8u)
#define ALIGN_CMAC_OUTPUT(bytes) (((bytes) + 15) & ~15)
#define BYTES_TO_BITS(bytes) ((bytes)*8u)

#if defined(CC3XX_CONFIG_ECDSA_SIGN_DETERMINISTIC_ENABLE)
#include "cc3xx_drbg_hmac.h"
/**
 * @brief Generate the value of the parameter k following the procedure described in
 *        RFC 6979 to implement DETERMINISTIC_ECDSA for signing.
 *
 * @param[in]  private_key     Buffer containing the private key
 * @param[in]  private_key_len Size in bytes of the \p private_key buffer
 * @param[in]  hash_len        Size in bytes of the hash
 * @param[in]  order_len       Size in bits of the order \a n associated to the curve
 * @param[in]  reg_hash        Register containing the reduced hash to be less than \a n
 * @param[in]  reg_n           Register containing the order \a n associated to the curve
 * @param[in]  reg_k           Register containing the value of the generated \a k
 *
 * @return                     An error code specified by \a cc3xx_err_t
 */
static cc3xx_err_t gen_deterministic_k(const uint32_t *private_key, size_t private_key_len,
                                       size_t hash_len, size_t order_len, cc3xx_pka_reg_id_t reg_hash,
                                       cc3xx_pka_reg_id_t reg_n, cc3xx_pka_reg_id_t reg_k)
{
    cc3xx_err_t err;
    struct cc3xx_drbg_hmac_state_t hmac_drbg_state;
    bool is_k_greater_than_n = false;

    /* Currently the HMAC_DRBG construct supports only SHA-256 */
    assert(hash_len == SHA256_OUTPUT_SIZE);
    assert(BYTES_TO_BITS(hash_len) <= order_len);

    /* We use this both for the reduced hash and for the k output */
    const size_t scratch_size =
        BYTES_TO_BITS(hash_len) > order_len ?
            hash_len : BITS_TO_BYTES(order_len);

    /* A scratch buffer used to read and write back quantities from the PKA SRAM */
    uint32_t scratch[scratch_size / sizeof(uint32_t)];

    cc3xx_lowlevel_pka_read_reg_swap_endian(reg_hash, scratch, sizeof(scratch));

    err = cc3xx_lowlevel_drbg_hmac_instantiate(
        &hmac_drbg_state, (const uint8_t *)private_key, private_key_len,
                                            (const uint8_t *)scratch, sizeof(scratch), NULL, 0);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    do {
        /* Perform a HMAC_DRBG generation to extract a candidate value for k of size order_len */
        err = cc3xx_lowlevel_drbg_hmac_generate(
            &hmac_drbg_state, order_len, (uint8_t *)scratch, NULL, 0);
        if (err != CC3XX_ERR_SUCCESS) {
            goto out;
        }

        /* Write the generated k into the PKA for the comparison */
        cc3xx_lowlevel_pka_write_reg_swap_endian(reg_k, scratch, BITS_TO_BYTES(order_len));

        is_k_greater_than_n = cc3xx_lowlevel_pka_greater_than(reg_k, reg_n);

    } while (is_k_greater_than_n);

out:
    (void)cc3xx_lowlevel_drbg_hmac_uninit(&hmac_drbg_state);
    memset(scratch, 0, sizeof(scratch));
    return err;
}
#endif /* CC3XX_CONFIG_ECDSA_SIGN_DETERMINISTIC_ENABLE */

#if defined(CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE) || defined(CC3XX_CONFIG_ECDSA_SIGN_ENABLE)
/**
 * @brief Function to load and validate the value of the private key based
 *        on the order of the curve. It uses the PKA for range comparisons based
 *        on the curve parameters loaded after cc3xx_lowlevel_ec_init()
 *
 * @param[in] private_key_reg  Allocated PKA register to hold the private key material
 * @param[in] private_key      Buffer containing the private key bytes
 * @param[in] private_key_len  Size in bytes of the private key
 *
 * @return cc3xx_err_t \a CC3XX_ERR_SUCCESS in case the key is in the valid range and loaded,
 *                     \a CC3XX_ERR_ECDSA_INVALID_KEY in case the key is not in the valid range
 */
static cc3xx_err_t load_validate_private_key(
    cc3xx_pka_reg_id_t private_key_reg,
    const uint32_t *private_key,
    size_t private_key_len)
{
    cc3xx_lowlevel_pka_write_reg_swap_endian(private_key_reg, private_key, private_key_len);
    /* Check that d is less than N */
    if (!cc3xx_lowlevel_pka_less_than(private_key_reg, CC3XX_PKA_REG_N)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_KEY);
        return CC3XX_ERR_ECDSA_INVALID_KEY;
    }
    /* Check that d is not 0 */
    if (cc3xx_lowlevel_pka_are_equal_si(private_key_reg, 0)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_KEY);
        return CC3XX_ERR_ECDSA_INVALID_KEY;
    }

    return CC3XX_ERR_SUCCESS;
}
#endif /* CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE || CC3XX_CONFIG_ECDSA_SIGN_ENABLE */

#ifdef CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE
cc3xx_err_t cc3xx_lowlevel_ecdsa_genkey(cc3xx_ec_curve_id_t curve_id,
                                        uint32_t *private_key,
                                        size_t private_key_len,
                                        size_t *private_key_size)
{
    cc3xx_ec_curve_t curve;
    cc3xx_pka_reg_id_t private_key_reg;
    cc3xx_err_t err;

    /* This sets up various curve parameters into PKA registers */
    err = cc3xx_lowlevel_ec_init(curve_id, &curve);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    if (private_key_len < curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_BUFFER_OVERFLOW);
        err = CC3XX_ERR_BUFFER_OVERFLOW;
        goto out;
    }

    private_key_reg = cc3xx_lowlevel_pka_allocate_reg();

    do {
        err = cc3xx_lowlevel_pka_set_to_random_within_modulus(private_key_reg);
        if (err != CC3XX_ERR_SUCCESS) {
            goto out;
        }
    } while (!cc3xx_lowlevel_pka_greater_than_si(private_key_reg, 0));

    cc3xx_lowlevel_pka_read_reg_swap_endian(private_key_reg, private_key, curve.modulus_size);

    /* Destroy private key register */
    cc3xx_lowlevel_pka_set_to_random(private_key_reg, curve.modulus_size * 8);

    if (private_key_size != NULL) {
        *private_key_size = curve.modulus_size;
    }

out:
    cc3xx_lowlevel_ec_uninit();

    return err;
}

cc3xx_err_t cc3xx_lowlevel_ecdsa_derive_key(
    cc3xx_ec_curve_id_t curve_id,
    cc3xx_aes_key_id_t key_id, const uint32_t *key,
    cc3xx_aes_keysize_t key_size,
    const uint8_t *label, size_t label_length,
    const uint8_t *context, size_t context_length,
    uint32_t *output_key, size_t out_size, size_t *out_length)
{
    cc3xx_err_t err;
    cc3xx_pka_reg_id_t private_key_reg;
    cc3xx_pka_reg_id_t order_reg, barrett_tag;
    const cc3xx_ec_curve_data_t *curve_data = cc3xx_lowlevel_ec_get_curve_data(curve_id);

    if (curve_data == NULL) {
        return CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
    }

    const size_t bytes_required_for_unbiased_key =
        ALIGN_CMAC_OUTPUT(BITS_TO_BYTES(curve_data->recommended_bits_for_generation));
    uint32_t kdf_output[bytes_required_for_unbiased_key / sizeof(uint32_t)];

    if (bytes_required_for_unbiased_key == 0) {
        return CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
    }

    if (out_size < curve_data->modulus_size) {
        return CC3XX_ERR_BUFFER_OVERFLOW;
    }

    err = cc3xx_lowlevel_kdf_cmac(key_id, key, key_size, label, label_length,
        context, context_length, kdf_output, sizeof(kdf_output));
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    cc3xx_lowlevel_pka_init(sizeof(kdf_output));

    private_key_reg = cc3xx_lowlevel_pka_allocate_reg();
    order_reg = cc3xx_lowlevel_pka_allocate_reg();
    barrett_tag = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(
        barrett_tag, curve_data->barrett_tag, curve_data->barrett_tag_size);

    cc3xx_lowlevel_pka_write_reg(
        order_reg, curve_data->order, curve_data->modulus_size);

    /* The derived key is treated as a number hence when storing
     * it in the PKA as LE we need to swap the endianess of the
     * memory buffer that holds the key when writing it
     */
    cc3xx_lowlevel_pka_write_reg_swap_endian(
        private_key_reg, kdf_output, sizeof(kdf_output));

    /* This should never happen in normal operation */
    if (!cc3xx_lowlevel_pka_greater_than_si(private_key_reg, 0)) {
        err = CC3XX_ERR_ECDSA_INVALID_KEY;
        goto out;
    }

    cc3xx_lowlevel_pka_set_modulus(order_reg, false, barrett_tag);

    cc3xx_lowlevel_pka_reduce(private_key_reg);

    cc3xx_lowlevel_pka_read_reg_swap_endian(private_key_reg, output_key, curve_data->modulus_size);

    if (out_length != NULL) {
        *out_length = curve_data->modulus_size;
    }

out:
    cc3xx_lowlevel_pka_uninit();

    return err;
}

cc3xx_err_t cc3xx_lowlevel_ecdsa_getpub(cc3xx_ec_curve_id_t curve_id,
                                        const uint32_t *private_key, size_t private_key_len,
                                        uint32_t *public_key_x, size_t public_key_x_len,
                                        size_t *public_key_x_size,
                                        uint32_t *public_key_y, size_t public_key_y_len,
                                        size_t *public_key_y_size)
{
    cc3xx_ec_curve_t curve;
    cc3xx_pka_reg_id_t private_key_reg;
    cc3xx_ec_point_affine public_key_point;
    cc3xx_err_t err;

    /* This sets up various curve parameters into PKA registers */
    err = cc3xx_lowlevel_ec_init(curve_id, &curve);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    /* This only checks that the private key fits in the allocated register size on PKA engine.
     * The validation of the private key happens in load_validate_private_key using the PKA
     * engine itself
     */
    if (private_key_len > cc3xx_lowlevel_pka_get_register_size()) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_KEY);
        err = CC3XX_ERR_ECDSA_INVALID_KEY;
        goto out;
    }

    if (public_key_x_len < curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_BUFFER_OVERFLOW);
        err = CC3XX_ERR_BUFFER_OVERFLOW;
        goto out;
    }

    if (public_key_y_len < curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_BUFFER_OVERFLOW);
        err = CC3XX_ERR_BUFFER_OVERFLOW;
        goto out;
    }

    public_key_point = cc3xx_lowlevel_ec_allocate_point();
    private_key_reg = cc3xx_lowlevel_pka_allocate_reg();

    /* Load and validate the private key to be in range for the curve */
    err = load_validate_private_key(private_key_reg, private_key, private_key_len);
    if (err != CC3XX_ERR_SUCCESS) {
        /* FATAL_ERR macros are in the load_validate_private_key function already */
        goto out;
    }

    err = cc3xx_lowlevel_ec_multiply_point_by_scalar(&curve, &curve.generator, private_key_reg,
                                           &public_key_point);

    cc3xx_lowlevel_pka_read_reg_swap_endian(public_key_point.x, public_key_x, curve.modulus_size);
    cc3xx_lowlevel_pka_read_reg_swap_endian(public_key_point.y, public_key_y, curve.modulus_size);

    *public_key_x_size = curve.modulus_size;
    *public_key_y_size = curve.modulus_size;

out:
    cc3xx_lowlevel_ec_uninit();

    return err;
}
#endif /* CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE */

#ifdef CC3XX_CONFIG_ECDSA_VERIFY_ENABLE
/* As per NIST FIPS 186-5 section 6.4.2.
 */
cc3xx_err_t cc3xx_lowlevel_ecdsa_verify(cc3xx_ec_curve_id_t curve_id,
                                        const uint32_t *public_key_x,
                                        size_t public_key_x_len,
                                        const uint32_t *public_key_y,
                                        size_t public_key_y_len,
                                        const uint32_t *hash, size_t hash_len,
                                        const uint32_t *sig_r, size_t sig_r_len,
                                        const uint32_t *sig_s, size_t sig_s_len)
{
    cc3xx_ec_curve_t curve;
    cc3xx_ec_point_affine public_key_point;
    cc3xx_ec_point_affine calculated_r_point;
    cc3xx_pka_reg_id_t sig_s_reg;
    cc3xx_pka_reg_id_t sig_r_reg;
    cc3xx_pka_reg_id_t u_reg;
    cc3xx_pka_reg_id_t v_reg;
    cc3xx_pka_reg_id_t hash_reg;
    cc3xx_err_t err;
    struct cc3xx_pka_state_t pka_state;

    /* This sets up various curve parameters into PKA registers */
    err = cc3xx_lowlevel_ec_init(curve_id, &curve);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    if (public_key_x_len > curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_KEY);
        err = CC3XX_ERR_ECDSA_INVALID_KEY;
        goto out;
    }

    if (public_key_y_len > curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_KEY);
        err = CC3XX_ERR_ECDSA_INVALID_KEY;
        goto out;
    }

    if (sig_r_len > curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }

    if (sig_s_len > curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }

    /* The hash _can_ be larger than the modulus, but must still fit into the
     * PKA reg.
     */
    cc3xx_lowlevel_pka_get_state(&pka_state, 0, NULL, NULL, NULL);
    if (hash_len > pka_state.reg_size) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_HASH);
        err = CC3XX_ERR_ECDSA_INVALID_HASH;
        goto out;
    }

    /* Now that PKA is initialized, allocate the registers / points we'll use */
    sig_r_reg = cc3xx_lowlevel_pka_allocate_reg();
    sig_s_reg = cc3xx_lowlevel_pka_allocate_reg();
    u_reg = cc3xx_lowlevel_pka_allocate_reg();
    v_reg = cc3xx_lowlevel_pka_allocate_reg();
    hash_reg = cc3xx_lowlevel_pka_allocate_reg();

    calculated_r_point = cc3xx_lowlevel_ec_allocate_point();


    /* This validates that the public key point lies on the curve, is not the
     * identity element, and that it multiplied by the group order is infinity.
     */
    err = cc3xx_lowlevel_ec_allocate_point_from_data(&curve,
                                            public_key_x, public_key_x_len,
                                            public_key_y, public_key_y_len,
                                            &public_key_point);
    if (err != CC3XX_ERR_SUCCESS) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }

    cc3xx_lowlevel_pka_write_reg_swap_endian(sig_s_reg, sig_s, sig_s_len);
    /* Check that s is less than N */
    if (!cc3xx_lowlevel_pka_less_than(sig_s_reg, CC3XX_PKA_REG_N)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }
    /* Check that s is not 0 */
    if (cc3xx_lowlevel_pka_are_equal_si(sig_s_reg, 0)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }

    /* Check that r is less than N */
    cc3xx_lowlevel_pka_write_reg_swap_endian(sig_r_reg, sig_r, sig_r_len);
    if (!cc3xx_lowlevel_pka_less_than(sig_r_reg, CC3XX_PKA_REG_N)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }
    /* Check that r is not 0 */
    if (cc3xx_lowlevel_pka_are_equal_si(sig_r_reg, 0)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }

    cc3xx_lowlevel_pka_write_reg_swap_endian(hash_reg, hash, hash_len);
    /* Check that hash is not 0 */
    if (cc3xx_lowlevel_pka_are_equal_si(hash_reg, 0)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }
    /* If the size of the hash is greater than the group order, reduce the amount of
     * bits used by shifting.
     */
    if (hash_len > curve.modulus_size) {
        cc3xx_lowlevel_pka_shift_right_fill_0_ui(hash_reg,
                                                 (hash_len - curve.modulus_size) * 8,
                                                 hash_reg);
    }
    /* Then finally a reduction so we can be sure the hash is below N */
    cc3xx_lowlevel_pka_reduce(hash_reg);

    /* u = hash * s^-1. Put s^-1 into v_reg so we can reuse it for calculating v
     * later
     */
    cc3xx_lowlevel_pka_mod_inv_prime_modulus(sig_s_reg, v_reg);
    cc3xx_lowlevel_pka_mod_mul(v_reg, hash_reg, u_reg);

    /* v = r * s^-1 */
    cc3xx_lowlevel_pka_mod_mul(v_reg, sig_r_reg, v_reg);

    /* R1 = [u]G + [v]Q */
    err = cc3xx_lowlevel_ec_shamir_multiply_points_by_scalars_and_add(&curve,
                                                      &curve.generator, u_reg,
                                                      &public_key_point, v_reg,
                                                      &calculated_r_point);
    if (err != CC3XX_ERR_SUCCESS) {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
        goto out;
    }

    /* Accept signature if r == r1 mod N */
    cc3xx_lowlevel_pka_reduce(calculated_r_point.x);

    if (cc3xx_lowlevel_pka_are_equal(sig_r_reg, calculated_r_point.x)) {
        err = CC3XX_ERR_SUCCESS;
    } else {
        FATAL_ERR(CC3XX_ERR_ECDSA_SIGNATURE_INVALID);
        err = CC3XX_ERR_ECDSA_SIGNATURE_INVALID;
    }

out:
    /* This frees all the PKA registers as it will deinit the PKA engine */
    cc3xx_lowlevel_ec_uninit();

    return err;
}
#endif /* CC3XX_CONFIG_ECDSA_VERIFY_ENABLE */

#ifdef CC3XX_CONFIG_ECDSA_SIGN_ENABLE
static cc3xx_err_t ecdsa_sign(bool is_deterministic, cc3xx_ec_curve_id_t curve_id,
                              const uint32_t *private_key, size_t private_key_len,
                              const uint32_t *hash, size_t hash_len,
                              uint32_t *sig_r, size_t sig_r_len, size_t *sig_r_size,
                              uint32_t *sig_s, size_t sig_s_len, size_t *sig_s_size)
{
    cc3xx_ec_curve_t curve;
    cc3xx_ec_point_affine temp_point;
    cc3xx_pka_reg_id_t sig_s_reg;
    cc3xx_pka_reg_id_t sig_r_reg;
    cc3xx_pka_reg_id_t k_reg;
    cc3xx_pka_reg_id_t temp_reg;
    cc3xx_pka_reg_id_t hash_reg;
    cc3xx_pka_reg_id_t private_key_reg;
    cc3xx_err_t err;

#if !defined(CC3XX_CONFIG_ECDSA_SIGN_DETERMINISTIC_ENABLE)
    if (is_deterministic) {
        return CC3XX_ERR_NOT_IMPLEMENTED;
    }
#endif /* CC3XX_CONFIG_ECDSA_SIGN_DETERMINISTIC_ENABLE */

    /* This sets up various curve parameters into PKA registers */
    err = cc3xx_lowlevel_ec_init(curve_id, &curve);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    /* We don't allow curves with orders smaller than the hash size. This is not
     * an issue for the current set of curves, because for example P-521 could be
     * used only with SHA-512. Using mismatched Hash outputs and orders makes the
     * overall security strength equal to the minimum of the two
     */
    assert(hash_len <= curve.modulus_size);

    /* This only checks that the private key fits in the allocated register size on PKA engine.
     * The validation of the private key happens in load_validate_private_key using the PKA
     * engine itself
     */
    if (private_key_len > cc3xx_lowlevel_pka_get_register_size()) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_KEY);
        err = CC3XX_ERR_ECDSA_INVALID_KEY;
        goto out;
    }

    if (sig_r_len < curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_BUFFER_OVERFLOW);
        err = CC3XX_ERR_BUFFER_OVERFLOW;
        goto out;
    }

    if (sig_s_len < curve.modulus_size) {
        FATAL_ERR(CC3XX_ERR_BUFFER_OVERFLOW);
        err = CC3XX_ERR_BUFFER_OVERFLOW;
        goto out;
    }

    /* Now that PKA is initialized, allocate the registers / points we'll use */
    sig_r_reg = cc3xx_lowlevel_pka_allocate_reg();
    sig_s_reg = cc3xx_lowlevel_pka_allocate_reg();
    k_reg = cc3xx_lowlevel_pka_allocate_reg();
    temp_reg = cc3xx_lowlevel_pka_allocate_reg();
    hash_reg = cc3xx_lowlevel_pka_allocate_reg();
    private_key_reg = cc3xx_lowlevel_pka_allocate_reg();

    temp_point = cc3xx_lowlevel_ec_allocate_point();

    /* Load and validate the private key to be in range for the curve */
    err = load_validate_private_key(private_key_reg, private_key, private_key_len);
    if (err != CC3XX_ERR_SUCCESS) {
        /* FATAL_ERR macros are in the load_validate_private_key function already */
        goto out;
    }

    cc3xx_lowlevel_pka_write_reg_swap_endian(hash_reg, hash, hash_len);
    /* Check that hash is not 0 */
    if (cc3xx_lowlevel_pka_are_equal_si(hash_reg, 0)) {
        FATAL_ERR(CC3XX_ERR_ECDSA_INVALID_HASH);
        err = CC3XX_ERR_ECDSA_INVALID_HASH;
        goto out;
    }
    /* If the size of the hash is greater than the group order, reduce the amount of
     * bits used by shifting.
     */
    if (hash_len > curve.modulus_size) {
        cc3xx_lowlevel_pka_shift_right_fill_0_ui(hash_reg,
                                                 (hash_len - curve.modulus_size) * 8,
                                                 hash_reg);
    }
    /* Then finally a reduction so we can be sure the hash is below N */
    cc3xx_lowlevel_pka_reduce(hash_reg);

    do {
        if (is_deterministic == false) {
            err = cc3xx_lowlevel_pka_set_to_random_within_modulus(k_reg);
        } else {
#if defined(CC3XX_CONFIG_ECDSA_SIGN_DETERMINISTIC_ENABLE)
            /* Read the reduced hash back from the PKA SRAM to pass into the HMAC_DRBG */
            uint32_t reduced_hash[curve.modulus_size / sizeof(uint32_t)];
            cc3xx_lowlevel_pka_read_reg_swap_endian(hash_reg, reduced_hash, sizeof(reduced_hash));
            /* Generate k by using a deterministically seeded HMAC_DRBG */
            err = gen_deterministic_k(
                private_key, private_key_len,
                hash_len, BYTES_TO_BITS(curve.modulus_size),
                hash_reg, curve.field_modulus, k_reg);
#endif /* CC3XX_CONFIG_ECDSA_SIGN_DETERMINISTIC_ENABLE */
        }
        if (err != CC3XX_ERR_SUCCESS) {
            goto out;
        }

        cc3xx_lowlevel_ec_multiply_point_by_scalar(&curve, &curve.generator, k_reg,
                                         &temp_point);
        cc3xx_lowlevel_pka_copy(temp_point.x, sig_r_reg);
        cc3xx_lowlevel_pka_reduce(sig_r_reg);

        if (!cc3xx_lowlevel_pka_greater_than_si(sig_r_reg, 0)) {
            continue;
        }

        cc3xx_lowlevel_pka_mod_mul(sig_r_reg, private_key_reg, temp_reg);
        cc3xx_lowlevel_pka_mod_add(temp_reg, hash_reg, temp_reg);
        cc3xx_lowlevel_pka_mod_inv_prime_modulus(k_reg, k_reg);
        cc3xx_lowlevel_pka_mod_mul(k_reg, temp_reg, sig_s_reg);

        /* Destroy K */
        cc3xx_lowlevel_pka_set_to_random(k_reg, curve.modulus_size * 8);
    } while (!cc3xx_lowlevel_pka_greater_than_si(sig_s_reg, 0));

    cc3xx_lowlevel_pka_read_reg_swap_endian(sig_s_reg, sig_s, curve.modulus_size);
    cc3xx_lowlevel_pka_read_reg_swap_endian(sig_r_reg, sig_r, curve.modulus_size);

    /* Destroy private key register */
    cc3xx_lowlevel_pka_set_to_random(private_key_reg, curve.modulus_size * 8);

    *sig_s_size = curve.modulus_size;
    *sig_r_size = curve.modulus_size;

    err = CC3XX_ERR_SUCCESS;
out:
    /* This frees all the PKA registers as it will deinit the PKA engine */
    cc3xx_lowlevel_ec_uninit();

    return err;
}

cc3xx_err_t cc3xx_lowlevel_ecdsa_sign(
    cc3xx_ec_curve_id_t curve_id,
    const uint32_t *private_key, size_t private_key_len,
    const uint32_t *hash, size_t hash_len,
    uint32_t *sig_r, size_t sig_r_len, size_t *sig_r_size,
    uint32_t *sig_s, size_t sig_s_len, size_t *sig_s_size)
{
    return ecdsa_sign(false, curve_id, private_key, private_key_len,
        hash, hash_len,
        sig_r, sig_r_len, sig_r_size,
        sig_s, sig_s_len, sig_s_size);
}

cc3xx_err_t cc3xx_lowlevel_ecdsa_sign_deterministic(
    cc3xx_ec_curve_id_t curve_id,
    const uint32_t *private_key, size_t private_key_len,
    const uint32_t *hash, size_t hash_len,
    uint32_t *sig_r, size_t sig_r_len, size_t *sig_r_size,
    uint32_t *sig_s, size_t sig_s_len, size_t *sig_s_size)
{
    return ecdsa_sign(true, curve_id, private_key, private_key_len,
        hash, hash_len,
        sig_r, sig_r_len, sig_r_size,
        sig_s, sig_s_len, sig_s_size);
}
#endif /* CC3XX_CONFIG_ECDSA_SIGN_ENABLE */
