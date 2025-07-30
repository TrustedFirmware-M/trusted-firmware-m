/*
 * Copyright (c) 2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "cc3xx_ec.h"

#include "cc3xx_error.h"
#include "cc3xx_ec_curve_data.h"
#include "cc3xx_ec_projective_point.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
#include "cc3xx_rng.h"
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
#include "cc3xx_ec_weierstrass.h"
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */

#include "fatal_error.h"

#include <string.h>

/* To be called on entry to every public function in this module */
static void set_modulus_to_curve_modulus(cc3xx_ec_curve_t *curve)
{
    cc3xx_lowlevel_pka_set_modulus(curve->field_modulus, false, CC3XX_PKA_REG_NP);
}

/* To be called on exit of every public function in this module */
static void set_modulus_to_curve_order(cc3xx_ec_curve_t *curve)
{
    cc3xx_lowlevel_pka_set_modulus(curve->order, false, CC3XX_PKA_REG_NP);
}

/**
 * @brief Checks if modulus needs to switch to curve_modulus, and switch it then
 *
 * @param[in] curve Structure containing the parameters of the curve being used
 *
 * @return    true  The modulus has been switched to the prime field
 * @return    false The modulus already contained the prime field
 *
 */
static bool check_and_set_modulus_to_curve_modulus(cc3xx_ec_curve_t *curve)
{
    const bool modulus_already_set =
        cc3xx_lowlevel_pka_are_equal(curve->field_modulus, CC3XX_PKA_REG_NP);

    if (!modulus_already_set) {
        set_modulus_to_curve_modulus(curve);
    }

    return !modulus_already_set;
}

/* Using the procedure from appendix D.1 of NIST SP800-186 */
static bool validate_point(cc3xx_ec_curve_t *curve,
                           cc3xx_ec_point_affine *p)
{
    if (!cc3xx_lowlevel_pka_less_than(p->x, CC3XX_PKA_REG_N)) {
        return false;
    }

    if (!cc3xx_lowlevel_pka_less_than(p->y, CC3XX_PKA_REG_N)) {
        return false;
    }

    if (cc3xx_lowlevel_pka_are_equal_si(p->x, 0)) {
        return false;
    }

    if (cc3xx_lowlevel_pka_are_equal_si(p->y, 0)) {
        return false;
    }

    switch (curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
    case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
    {
        const bool restore_previous = check_and_set_modulus_to_curve_modulus(curve);
        /* Procedure described in NIST SP800-186 D.1, uses prime_field size as modulus */
        const bool ret = cc3xx_lowlevel_ec_weierstrass_validate_point(curve, p);
        if (restore_previous) {
            set_modulus_to_curve_order(curve);
        }

        return ret;
    }
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
    default:
        return false;
    }
}

static cc3xx_err_t allocate_point_from_data(cc3xx_ec_curve_t *curve,
                                            const uint32_t *x,
                                            size_t x_len,
                                            const uint32_t *y,
                                            size_t y_len,
                                            cc3xx_ec_point_affine *res)
{
    *res = cc3xx_lowlevel_ec_allocate_point();

    cc3xx_lowlevel_pka_write_reg_swap_endian(res->x, x, x_len);
    cc3xx_lowlevel_pka_write_reg_swap_endian(res->y, y, y_len);

    return validate_point(curve, res) ? CC3XX_ERR_SUCCESS
                                      : CC3XX_ERR_EC_POINT_OUTSIDE_FIELD;
}

cc3xx_err_t cc3xx_lowlevel_ec_allocate_point_from_data(cc3xx_ec_curve_t *curve,
                                                       const uint32_t *x,
                                                       size_t x_len,
                                                       const uint32_t *y,
                                                       size_t y_len,
                                                       cc3xx_ec_point_affine *res)
{
    cc3xx_err_t err;

    /* Because this function is part of the external interface, first swap the
     * modulus to use the curve modulus
     */
    set_modulus_to_curve_modulus(curve);

    err = allocate_point_from_data(curve, x, x_len, y, y_len, res);

    /* Then reset the modulus */
    set_modulus_to_curve_order(curve);

    return err;
}

cc3xx_ec_point_affine cc3xx_lowlevel_ec_allocate_point(void)
{
    cc3xx_ec_point_affine res;

    res.x = cc3xx_lowlevel_pka_allocate_reg();
    res.y = cc3xx_lowlevel_pka_allocate_reg();

    return res;
}

void cc3xx_lowlevel_ec_free_point(cc3xx_ec_point_affine *p)
{
    cc3xx_lowlevel_pka_free_reg(p->y);
    cc3xx_lowlevel_pka_free_reg(p->x);
}

static const cc3xx_ec_curve_data_t *curve_data_map[_CURVE_ID_MAX] = {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
#ifdef CC3XX_CONFIG_EC_CURVE_SECP_192_R1_ENABLE
    [CC3XX_EC_CURVE_SECP_192_R1] = &secp_192_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_SECP_224_R1_ENABLE
    [CC3XX_EC_CURVE_SECP_224_R1] = &secp_224_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_SECP_256_R1_ENABLE
    [CC3XX_EC_CURVE_SECP_256_R1] = &secp_256_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_SECP_384_R1_ENABLE
    [CC3XX_EC_CURVE_SECP_384_R1] = &secp_384_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_SECP_521_R1_ENABLE
    [CC3XX_EC_CURVE_SECP_521_R1] = &secp_521_r1,
#endif

#ifdef CC3XX_CONFIG_EC_CURVE_SECP_192_K1_ENABLE
    [CC3XX_EC_CURVE_SECP_192_K1] = &secp_192_k1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_SECP_224_K1_ENABLE
    [CC3XX_EC_CURVE_SECP_224_K1] = &secp_224_k1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_SECP_256_K1_ENABLE
    [CC3XX_EC_CURVE_SECP_256_K1] = &secp_256_k1,
#endif

#ifdef CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_192_R1_ENABLE
    [CC3XX_EC_CURVE_BRAINPOOLP_192_R1] = &brainpoolp_192_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_224_R1_ENABLE
    [CC3XX_EC_CURVE_BRAINPOOLP_224_R1] = &brainpoolp_224_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_256_R1_ENABLE
    [CC3XX_EC_CURVE_BRAINPOOLP_256_R1] = &brainpoolp_256_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_320_R1_ENABLE
    [CC3XX_EC_CURVE_BRAINPOOLP_320_R1] = &brainpoolp_320_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_384_R1_ENABLE
    [CC3XX_EC_CURVE_BRAINPOOLP_384_R1] = &brainpoolp_384_r1,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_512_R1_ENABLE
    [CC3XX_EC_CURVE_BRAINPOOLP_512_R1] = &brainpoolp_512_r1,
#endif

#ifdef CC3XX_CONFIG_EC_CURVE_FRP_256_V1_ENABLE
    [CC3XX_EC_CURVE_FRP_256_V1] = &frp_256_v1,
#endif
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */

#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_MONTGOMERY_ENABLE
#ifdef CC3XX_CONFIG_EC_CURVE_25519_ENABLE
    [CC3XX_EC_CURVE_25519] = &curve_25519,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_448_ENABLE
    [CC3XX_EC_CURVE_448] = &curve_448,
#endif
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_MONTGOMERY_ENABLE */

#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_TWISTED_EDWARDS_ENABLE
#ifdef CC3XX_CONFIG_EC_CURVE_ED25519_ENABLE
    [CC3XX_EC_CURVE_ED25519] = &ed25519,
#endif
#ifdef CC3XX_CONFIG_EC_CURVE_ED448_ENABLE
    [CC3XX_EC_CURVE_ED448] = &ed448,
#endif
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_TWISTED_EDWARDS_ENABLE */
};

const cc3xx_ec_curve_data_t *cc3xx_lowlevel_ec_get_curve_data(cc3xx_ec_curve_id_t curve_id) {
    return (curve_id < _CURVE_ID_MAX) ? curve_data_map[curve_id] : NULL;
}

size_t cc3xx_lowlevel_ec_get_modulus_size_from_curve(cc3xx_ec_curve_id_t curve_id) {
    /* The data is NULL when the support for the curve has not been compiled in */
    if (curve_id >= _CURVE_ID_MAX || curve_data_map[curve_id] == NULL) {
        return 0;
    }
    return (curve_data_map[curve_id])->modulus_size;
}

#ifdef CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE
static bool validate_reg_is_equal_to_buf(cc3xx_pka_reg_id_t reg, const uint32_t *buf,
                                         size_t len)
{
    uint32_t validate_buf[CC3XX_EC_MAX_POINT_SIZE / sizeof(uint32_t)];

    cc3xx_lowlevel_pka_read_reg(reg, validate_buf, len);
    return memcmp(validate_buf, buf, len) == 0;
}

static bool validate_curve(cc3xx_ec_curve_t *curve)
{
    const cc3xx_ec_curve_data_t *curve_data = curve_data_map[curve->id];
    bool result = true;

    result &= validate_reg_is_equal_to_buf(curve->param_a,
                                           curve_data->field_param_a,
                                           curve->modulus_size);

    result &= validate_reg_is_equal_to_buf(curve->param_b,
                                           curve_data->field_param_b,
                                           curve->modulus_size);

    result &= validate_reg_is_equal_to_buf(curve->order,
                                           curve_data->order,
                                           curve->modulus_size);

    result &= validate_reg_is_equal_to_buf(curve->field_modulus,
                                           curve_data->field_modulus,
                                           curve->modulus_size);

    result &= validate_point(curve, &curve->generator);

    return result;
}
#endif /* CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE */

cc3xx_err_t cc3xx_lowlevel_ec_init(cc3xx_ec_curve_id_t id,
                          cc3xx_ec_curve_t *curve)
{
    cc3xx_pka_reg_id_t barrett_tag;

    if (id >= _CURVE_ID_MAX) {
        FATAL_ERR(CC3XX_ERR_EC_CURVE_NOT_SUPPORTED);
        return CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
    }

    const cc3xx_ec_curve_data_t *curve_data = curve_data_map[id];

    if (curve_data == NULL) {
        FATAL_ERR(CC3XX_ERR_EC_CURVE_NOT_SUPPORTED);
        return CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
    }

    cc3xx_lowlevel_pka_init(curve_data->register_size);

    curve->field_modulus = cc3xx_lowlevel_pka_allocate_reg();
    curve->param_a = cc3xx_lowlevel_pka_allocate_reg();
    curve->param_b = cc3xx_lowlevel_pka_allocate_reg();
    curve->order = cc3xx_lowlevel_pka_allocate_reg();

    barrett_tag = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(curve->field_modulus, curve_data->field_modulus,
                                 curve_data->modulus_size);

    cc3xx_lowlevel_pka_write_reg(barrett_tag, curve_data->barrett_tag,
                                 curve_data->barrett_tag_size);

    cc3xx_lowlevel_pka_write_reg(curve->param_a, curve_data->field_param_a,
                                 curve_data->modulus_size);

    cc3xx_lowlevel_pka_write_reg(curve->param_b, curve_data->field_param_b,
                                 curve_data->modulus_size);

    cc3xx_lowlevel_pka_write_reg(curve->order, curve_data->order,
                                 curve_data->modulus_size);

    curve->id = id;
    curve->type = curve_data->type;
    curve->modulus_size = curve_data->modulus_size;
    curve->cofactor = curve_data->cofactor;

    cc3xx_lowlevel_pka_set_modulus(curve->field_modulus, false, barrett_tag);

    cc3xx_lowlevel_pka_free_reg(barrett_tag);

    /* Now that a and b parameters have been set up, we can create and verify a
     * point on the curve. This is done manually, since having the coordinates
     * in LE form is faster to load.
     */
    curve->generator.x = cc3xx_lowlevel_pka_allocate_reg();
    curve->generator.y = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(curve->generator.x, curve_data->generator_x,
                                 curve_data->modulus_size);
    cc3xx_lowlevel_pka_write_reg(curve->generator.y, curve_data->generator_y,
                                 curve_data->modulus_size);

#ifdef CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE
    if (!validate_curve(curve)) {
        cc3xx_lowlevel_pka_uninit();
        FATAL_ERR(CC3XX_ERR_FAULT_DETECTED);
        return CC3XX_ERR_FAULT_DETECTED;
    }
#endif /* CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE */

    set_modulus_to_curve_order(curve);

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_lowlevel_ec_add_points(cc3xx_ec_curve_t *curve,
                                         cc3xx_ec_point_affine *p,
                                         cc3xx_ec_point_affine *q,
                                         cc3xx_ec_point_affine *res)
{
    cc3xx_err_t err;

    set_modulus_to_curve_modulus(curve);

    switch (curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
    case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
        err = cc3xx_lowlevel_ec_weierstrass_add_points(curve, p, q, res);
        break;
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
    default:
        err = CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
        break;
    }

    set_modulus_to_curve_order(curve);

    return err;
}

cc3xx_err_t cc3xx_lowlevel_ec_double_point(cc3xx_ec_curve_t *curve,
                                           cc3xx_ec_point_affine *p,
                                           cc3xx_ec_point_affine *res)
{
    cc3xx_err_t err;

    set_modulus_to_curve_modulus(curve);

    switch (curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
    case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
        err = cc3xx_lowlevel_ec_weierstrass_double_point(curve, p, res);
        break;
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
    default:
        err = CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
        break;
    }

    set_modulus_to_curve_order(curve);

    return err;
}

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
static cc3xx_err_t blind_scalar(cc3xx_ec_curve_t *curve, cc3xx_pka_reg_id_t scalar,
                                cc3xx_pka_reg_id_t res)
{
    cc3xx_err_t err;
    uint32_t rand;
    uint32_t idx;
    cc3xx_pka_reg_id_t zero_reg = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_clear(zero_reg);

    err = cc3xx_lowlevel_rng_get_random_uint(CC3XX_CONFIG_EC_DPA_MAX_BLIND_MULTIPLE,
                                             &rand, CC3XX_RNG_DRBG);
    /* res = scalar + n * rand */
    cc3xx_lowlevel_pka_add(scalar, curve->order, res);
    for (idx = 1; idx < CC3XX_CONFIG_EC_DPA_MAX_BLIND_MULTIPLE; idx++) {
        if (idx < rand) {
            cc3xx_lowlevel_pka_add(res, curve->order, res);
        } else {
            /* This is a no-op to keep time constant */
            cc3xx_lowlevel_pka_add(res, zero_reg, res);
        }
    }

    cc3xx_lowlevel_pka_free_reg(zero_reg);
    return err;
}
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

static bool pad_scalar(cc3xx_ec_curve_t *curve, cc3xx_pka_reg_id_t scalar,
                       cc3xx_pka_reg_id_t res)
{
    bool negate_at_end = false;

    /* If the size of the scalar isn't the same as of the modulus (i.e. we have
     * leading zeroes), then instead we perform -(-s * P). This is done modulo
     * the group order, so must be done before selecting the curve modulus
     */
    if (cc3xx_lowlevel_pka_get_bit_size(scalar)
        != cc3xx_lowlevel_pka_get_bit_size(CC3XX_PKA_REG_N)) {
        cc3xx_lowlevel_pka_mod_neg(scalar, res);
        negate_at_end = true;
    } else {
        /* This should take the same time as mod_neg, while being a no-op */
        cc3xx_lowlevel_pka_mod_sub_si(scalar, 0, res);
        negate_at_end = false;
    }

    return negate_at_end;
}

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
static bool split_scalar(cc3xx_ec_curve_t *curve, cc3xx_pka_reg_id_t scalar,
                         cc3xx_pka_reg_id_t random, cc3xx_pka_reg_id_t quotient,
                         cc3xx_pka_reg_id_t remainder)
{
    cc3xx_err_t err;

    do {
        /* Roughly half of the size of the scalar */
        err = cc3xx_lowlevel_pka_set_to_random(random, curve->modulus_size * 8 / 2);
        cc3xx_lowlevel_pka_div(scalar, random, quotient, remainder);
    } while (cc3xx_lowlevel_pka_are_equal_si(quotient, 0)
             || cc3xx_lowlevel_pka_are_equal_si(remainder, 0));

    return err;
}
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

cc3xx_err_t cc3xx_lowlevel_ec_multiply_point_by_scalar(cc3xx_ec_curve_t *curve,
                                                       cc3xx_ec_point_affine *p,
                                                       cc3xx_pka_reg_id_t scalar,
                                                       cc3xx_ec_point_affine *res)
{
    cc3xx_pka_reg_id_t padded_scalar = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t scalar_to_input = padded_scalar;
    cc3xx_ec_point_affine temp_point = cc3xx_lowlevel_ec_allocate_point();
#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    cc3xx_pka_reg_id_t split_scalar_quotient = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t split_scalar_remainder = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t split_scalar_random = cc3xx_lowlevel_pka_allocate_reg();
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;
    bool negate_at_end = false;

    cc3xx_lowlevel_pka_clear(temp_point.x);
    cc3xx_lowlevel_pka_clear(temp_point.y);

    negate_at_end = pad_scalar(curve, scalar, padded_scalar);

    set_modulus_to_curve_modulus(curve);

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    err = blind_scalar(curve, padded_scalar, padded_scalar);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    err = split_scalar(curve, padded_scalar, split_scalar_random,
                       split_scalar_quotient, split_scalar_remainder);
    if (err != CC3XX_ERR_SUCCESS) {
        goto out;
    }

    scalar_to_input = split_scalar_quotient;
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

    switch(curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
    case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
        err |= cc3xx_lowlevel_ec_weierstrass_multiply_point_by_scalar(curve, p,
                                                                      scalar_to_input,
                                                                      res);
        break;
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
    default:
        err = CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
    }

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    switch(curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
    case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
        err |= cc3xx_lowlevel_ec_weierstrass_multiply_point_by_scalar(curve, res,
                                                                      split_scalar_random,
                                                                      res);

        err |= cc3xx_lowlevel_ec_weierstrass_multiply_point_by_scalar(curve, p,
                                                                      split_scalar_remainder,
                                                                      &temp_point);

        err |= cc3xx_lowlevel_ec_weierstrass_add_points(curve, res, &temp_point,
                                                        res);
        break;
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
    default:
        err = CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
    }
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */

    /* If we negated the scalar to pad the length, then it must be undone now */
    if (negate_at_end) {
        switch(curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
        case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
           cc3xx_lowlevel_ec_weierstrass_negate_point(res, res);
        break;
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
        default:
            err = CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
        }
    } else {
        switch(curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
        case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
           cc3xx_lowlevel_ec_weierstrass_negate_point(&temp_point, &temp_point);
        break;
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
        default:
            err = CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
        }
    }

#ifdef CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE
    /* Validate the curve after the operation, to see if any of the parameters
     * have been faulted. If so, then don't return a result.
     */
    if (!validate_curve(curve)) {
        err = CC3XX_ERR_DFA_VIOLATION;
    }

    if (!validate_point(curve, p)) {
        err = CC3XX_ERR_DFA_VIOLATION;
    }

    if (!validate_point(curve, res)) {
        err = CC3XX_ERR_DFA_VIOLATION;
    }
#endif /* CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE */

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
out:
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */
    if (err != CC3XX_ERR_SUCCESS) {
        /* If an error has occurred, then scrub the result */
        cc3xx_lowlevel_pka_set_to_random(res->x, curve->modulus_size * 8);
        cc3xx_lowlevel_pka_set_to_random(res->y, curve->modulus_size * 8);
    }

    set_modulus_to_curve_order(curve);

#ifdef CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE
    cc3xx_lowlevel_pka_free_reg(split_scalar_random);
    cc3xx_lowlevel_pka_free_reg(split_scalar_remainder);
    cc3xx_lowlevel_pka_free_reg(split_scalar_quotient);
#endif /* CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE */
    cc3xx_lowlevel_ec_free_point(&temp_point);
    cc3xx_lowlevel_pka_free_reg(padded_scalar);

    cc3xx_lowlevel_pka_unmap_physical_registers();

    return err;
}

/* Despite the name, this might or might not use the Shamir trick, as that
 * is controlled eventually by CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE
 */
cc3xx_err_t cc3xx_lowlevel_ec_shamir_multiply_points_by_scalars_and_add(
                                             cc3xx_ec_curve_t *curve,
                                             cc3xx_ec_point_affine *p1,
                                             cc3xx_pka_reg_id_t    scalar1,
                                             cc3xx_ec_point_affine *p2,
                                             cc3xx_pka_reg_id_t    scalar2,
                                             cc3xx_ec_point_affine *res)
{
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;

    set_modulus_to_curve_modulus(curve);

    switch(curve->type) {
#ifdef CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
    case CC3XX_EC_CURVE_TYPE_WEIERSTRASS:
        err = cc3xx_lowlevel_ec_weierstrass_shamir_multiply_points_by_scalars_and_add(curve,
                                                                                    p1,
                                                                                    scalar1,
                                                                                    p2,
                                                                                    scalar2,
                                                                                    res);
    break;
#endif /* CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE */
    default:
        err = CC3XX_ERR_EC_CURVE_NOT_SUPPORTED;
    }

#ifdef CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE
    /* Validate the curve after the operation, to see if any of the parameters
     * have been faulted. If so, then don't return a result.
     */
    if (!validate_curve(curve)) {
        err = CC3XX_ERR_DFA_VIOLATION;
    }

    if (!validate_point(curve, p1)) {
        err = CC3XX_ERR_DFA_VIOLATION;
    }

    if (!validate_point(curve, p2)) {
        err = CC3XX_ERR_DFA_VIOLATION;
    }

    if (!validate_point(curve, res)) {
        err = CC3XX_ERR_DFA_VIOLATION;
    }
#endif /* CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE */

    if (err != CC3XX_ERR_SUCCESS) {
        /* If an error has occurred, then scrub the result */
        cc3xx_lowlevel_pka_set_to_random(res->x, curve->modulus_size * 8);
        cc3xx_lowlevel_pka_set_to_random(res->y, curve->modulus_size * 8);
    }

    set_modulus_to_curve_order(curve);

    return err;
}

void cc3xx_lowlevel_ec_uninit(void)
{
    cc3xx_lowlevel_pka_uninit();
}
