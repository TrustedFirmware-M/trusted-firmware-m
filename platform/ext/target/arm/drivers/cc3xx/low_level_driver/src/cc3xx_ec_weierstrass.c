/*
 * Copyright (c) 2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "cc3xx_ec_weierstrass.h"

#include "cc3xx_ec_projective_point.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include <assert.h>

#include "fatal_error.h"

#if defined(CC3XX_CONFIG_ECDSA_VERIFY_ENABLE)     \
    && !defined(CC3XX_CONFIG_ECDSA_SIGN_ENABLE)   \
    && !defined(CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE) \
    && !defined(CC3XX_CONFIG_ECDH_ENABLE)
/**
 * @brief When it is defined, the driver is configured in such
 *        a way that the scalar multiplication does not operate
 *        on a secret, i.e. on a private key. In this case, we
 *        can use an unprotected way for performing the scalar
 *        multiplication, i.e. the Shamir trick
 */
#define SCALAR_MULT_NO_SECRET
#endif
bool cc3xx_lowlevel_ec_weierstrass_validate_point(cc3xx_ec_curve_t *curve,
                                                  cc3xx_ec_point_affine *p)
{
    cc3xx_err_t err;
    bool validate_succeeded = false;
    cc3xx_pka_reg_id_t equation_left_side = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t equation_right_side = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t temp = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_ec_point_affine foo = cc3xx_lowlevel_ec_allocate_point();

    /* Y^2 */
    cc3xx_lowlevel_pka_mod_exp_si(p->y, 2, equation_left_side);

    /* X^3 + aX + b */
    cc3xx_lowlevel_pka_mod_exp_si(p->x, 3, equation_right_side);
    cc3xx_lowlevel_pka_mod_mul(p->x, curve->param_a, temp);
    cc3xx_lowlevel_pka_mod_add(equation_right_side, temp, equation_right_side);
    cc3xx_lowlevel_pka_mod_add(equation_right_side, curve->param_b,
                               equation_right_side);

    validate_succeeded = cc3xx_lowlevel_pka_are_equal(equation_left_side,
                                                      equation_right_side);

    /* If the curve has a cofactor different than 1, it means that it has multiple
     * subgroups hence we need to also check that nP = 0 to confirm that P belongs
     * to the subgroup of order n
     */
    if (curve->cofactor != 1) {

        /* This performs affine-to-projective conversion, which includes a check
         * that that nP != infinity in the corresponding projective to affine
         * conversion. The result of the multiplication isn't used.
         */
        err = cc3xx_lowlevel_ec_weierstrass_multiply_point_by_scalar(curve, p,
                                                                     curve->order,
                                                                     &foo);
        if (err != CC3XX_ERR_EC_POINT_IS_INFINITY) {
            FATAL_ERR(false);
            validate_succeeded = false;
        }
    }

    cc3xx_lowlevel_ec_free_point(&foo);
    cc3xx_lowlevel_pka_free_reg(temp);
    cc3xx_lowlevel_pka_free_reg(equation_right_side);
    cc3xx_lowlevel_pka_free_reg(equation_left_side);

    return validate_succeeded;
}

void cc3xx_lowlevel_ec_weierstrass_negate_point(cc3xx_ec_point_affine *p,
                                                cc3xx_ec_point_affine *res)
{
    /* No need to perform affine-to-projective conversion, since we can just
     * negate the affine point */
    if (p != res) {
        cc3xx_lowlevel_pka_copy(p->x, res->x);
    }

    cc3xx_lowlevel_pka_mod_neg(p->y, res->y);
}

/* Using dbl-1998-cmo via https://www.hyperelliptic.org/EFD/g1p/auto-shortw-jacobian.html#doubling-dbl-1998-cmo */
static void double_point(cc3xx_ec_curve_t *curve, cc3xx_ec_point_projective *p,
                         cc3xx_ec_point_projective *res)
{
    cc3xx_pka_reg_id_t tmp_s = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t tmp_m = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t tmp = cc3xx_lowlevel_pka_allocate_reg();

    /* S = 4 * p->x * p->y^2 */
    cc3xx_lowlevel_pka_mod_mul(p->y, p->y, tmp_s);
    cc3xx_lowlevel_pka_mod_mul(tmp_s, p->x, tmp_s);
    cc3xx_lowlevel_pka_mod_mul_si(tmp_s, 4, tmp_s);

    /* M = 3 * p->x^2 + a * p->z^4. Use tmp for a temporary variable. */
    cc3xx_lowlevel_pka_mod_mul(p->x, p->x, tmp);
    cc3xx_lowlevel_pka_mod_mul_si(tmp, 3, tmp);
    cc3xx_lowlevel_pka_mod_mul(p->z, p->z, tmp_m);
    cc3xx_lowlevel_pka_mod_mul(tmp_m, tmp_m, tmp_m);
    cc3xx_lowlevel_pka_mod_mul(tmp_m, curve->param_a, tmp_m);
    cc3xx_lowlevel_pka_mod_add(tmp_m, tmp, tmp_m);

    /* T = res->x = M^2 - 2 * S. Use tmp for a temporary variable. */
    cc3xx_lowlevel_pka_mod_mul(tmp_m, tmp_m, res->x);
    cc3xx_lowlevel_pka_mod_mul_si(tmp_s, 2, tmp);
    cc3xx_lowlevel_pka_mod_sub(res->x, tmp, res->x);

    /* res->z = 2 * p->y * p->z This is done before res->y in
     * case p == res, in which case setting res->y clobbers p->y which is needed
     * in this step
     */
    cc3xx_lowlevel_pka_mod_mul(p->y, p->z, res->z);
    cc3xx_lowlevel_pka_mod_mul_si(res->z, 2, res->z);

    /*
     * res->y = M * (S - res->x) - 8 * p->y^4. Use tmp for a temporary variable.
     */
    cc3xx_lowlevel_pka_mod_mul(p->y, p->y, res->y);
    cc3xx_lowlevel_pka_mod_mul(res->y, res->y, res->y);
    cc3xx_lowlevel_pka_mod_mul_si(res->y, 8, res->y);

    cc3xx_lowlevel_pka_mod_sub(tmp_s, res->x, tmp);
    cc3xx_lowlevel_pka_mod_mul(tmp_m, tmp, tmp);
    cc3xx_lowlevel_pka_mod_sub(tmp, res->y, res->y);

    cc3xx_lowlevel_pka_free_reg(tmp);
    cc3xx_lowlevel_pka_free_reg(tmp_m);
    cc3xx_lowlevel_pka_free_reg(tmp_s);
}

cc3xx_err_t cc3xx_lowlevel_ec_weierstrass_double_point(cc3xx_ec_curve_t *curve,
                                                       cc3xx_ec_point_affine *p,
                                                       cc3xx_ec_point_affine *res)
{
    cc3xx_err_t err;

    cc3xx_ec_point_projective proj_p = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_res = cc3xx_lowlevel_ec_allocate_projective_point();

    cc3xx_lowlevel_ec_affine_to_jacobian(curve, p, &proj_p);

    double_point(curve, &proj_p, &proj_res);

    err = cc3xx_lowlevel_ec_jacobian_to_affine(curve, &proj_res, res);

    cc3xx_lowlevel_ec_free_projective_point(&proj_res);
    cc3xx_lowlevel_ec_free_projective_point(&proj_p);

    return err;
}

/* Using add-1998-cmo via https://www.hyperelliptic.org/EFD/g1p/auto-shortw-jacobian.html#addition-add-1998-cmo
 * It uses an older algorithm as it can be made more register-efficient.
 */
static void add_points(cc3xx_ec_curve_t *curve, cc3xx_ec_point_projective *p,
                       cc3xx_ec_point_projective *q, cc3xx_ec_point_projective *res)
{
    const bool p_is_infinity = cc3xx_lowlevel_ec_projective_point_is_infinity(p);
    const bool q_is_infinity = cc3xx_lowlevel_ec_projective_point_is_infinity(q);

    /* if P == 0, P + Q = Q */
    if (p_is_infinity) {
        return cc3xx_lowlevel_ec_copy_projective_point(q, res);
    }

    /* if Q == 0, P + Q = P */
    if (q_is_infinity) {
        return cc3xx_lowlevel_ec_copy_projective_point(p, res);
    }

    cc3xx_pka_reg_id_t tmp_u1 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t tmp_u2 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t tmp_s1 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t tmp_s2 = cc3xx_lowlevel_pka_allocate_reg();

    /* This is just an alias, to make the maths match the reference */
    cc3xx_pka_reg_id_t tmp_r;
    cc3xx_pka_reg_id_t tmp_h;

    /* U1 = p->x * q->z^2 */
    cc3xx_lowlevel_pka_mod_mul(q->z, q->z, tmp_u1);
    cc3xx_lowlevel_pka_mod_mul(p->x, tmp_u1, tmp_u1);
    /* U2 = q->x * p->z^2 */
    cc3xx_lowlevel_pka_mod_mul(p->z, p->z, tmp_u2);
    cc3xx_lowlevel_pka_mod_mul(q->x, tmp_u2, tmp_u2);

    /* S1 = p->y * q->z^3 */
    cc3xx_lowlevel_pka_mod_mul(q->z, q->z, tmp_s1);
    cc3xx_lowlevel_pka_mod_mul(tmp_s1, q->z, tmp_s1);
    cc3xx_lowlevel_pka_mod_mul(tmp_s1, p->y, tmp_s1);
    /* S2 = q->y * p->z^3 */
    cc3xx_lowlevel_pka_mod_mul(p->z, p->z, tmp_s2);
    cc3xx_lowlevel_pka_mod_mul(tmp_s2, p->z, tmp_s2);
    cc3xx_lowlevel_pka_mod_mul(tmp_s2, q->y, tmp_s2);

    if (cc3xx_lowlevel_pka_are_equal(tmp_u1, tmp_u2)) {
        /* P == Q iff U1 == U2 && S1 == S2 */
        if (cc3xx_lowlevel_pka_are_equal(tmp_s1, tmp_s2)) {

            cc3xx_lowlevel_pka_free_reg(tmp_s2);
            cc3xx_lowlevel_pka_free_reg(tmp_s1);
            cc3xx_lowlevel_pka_free_reg(tmp_u2);
            cc3xx_lowlevel_pka_free_reg(tmp_u1);

            /* If P == Q, P + Q = 2P */
            return double_point(curve, p, res);
        }
        /* P == -Q iff U1 == U2 && S1 == -S2*/
        cc3xx_lowlevel_pka_mod_neg(tmp_s2, tmp_s2);
        if (cc3xx_lowlevel_pka_are_equal(tmp_s1, tmp_s2)) {

            cc3xx_lowlevel_pka_free_reg(tmp_s2);
            cc3xx_lowlevel_pka_free_reg(tmp_s1);
            cc3xx_lowlevel_pka_free_reg(tmp_u2);
            cc3xx_lowlevel_pka_free_reg(tmp_u1);

            /* if P == -Q, P + Q = 0, i.e. the infinity point */
            return cc3xx_lowlevel_ec_projective_point_make_infinity(res);
        }
        /* Restore the original value of S2 */
        cc3xx_lowlevel_pka_mod_neg(tmp_s2, tmp_s2);
    }

    /* tmp_u2 is never used after this point, so we can use it to store the h
     * intermediate value
     */
    tmp_h = tmp_u2;

    /* H = U2 - U1 */
    cc3xx_lowlevel_pka_mod_sub(tmp_u2, tmp_u1, tmp_h);

    /* tmp_s2 is never used after this point, so we can use it to store the r
     * intermediate value
     */
    tmp_r = tmp_s2;

    /* R = S2 - S1 */
    cc3xx_lowlevel_pka_mod_sub(tmp_s2, tmp_s1, tmp_r);

    /* res->x = R^2 - H^3 - 2 * U1 * H^2. Uses res->y as scratch space */
    cc3xx_lowlevel_pka_shift_left_fill_0_ui(tmp_u1, 1, res->y);
    cc3xx_lowlevel_pka_reduce(res->y);
    cc3xx_lowlevel_pka_mod_mul(res->y, tmp_h, res->y);
    cc3xx_lowlevel_pka_mod_mul(res->y, tmp_h, res->y);
    cc3xx_lowlevel_pka_mod_mul(tmp_r, tmp_r, res->x);
    cc3xx_lowlevel_pka_mod_sub(res->x, res->y, res->x);
    cc3xx_lowlevel_pka_mod_mul(tmp_h, tmp_h, res->y);
    cc3xx_lowlevel_pka_mod_mul(res->y, tmp_h, res->y);
    cc3xx_lowlevel_pka_mod_sub(res->x, res->y, res->x);

    /* res->y = R * (U1 * H^2 - res->x) - S1 * H^3. Uses S1 as scratch space */
    cc3xx_lowlevel_pka_mod_mul(tmp_h, tmp_h, res->y);
    cc3xx_lowlevel_pka_mod_mul(res->y, tmp_u1, res->y);
    cc3xx_lowlevel_pka_mod_sub(res->y, res->x, res->y);
    cc3xx_lowlevel_pka_mod_mul(res->y, tmp_r, res->y);
    /* res->z already contains H^3 */
    cc3xx_lowlevel_pka_mod_mul(tmp_s1, tmp_h, tmp_s1);
    cc3xx_lowlevel_pka_mod_mul(tmp_s1, tmp_h, tmp_s1);
    cc3xx_lowlevel_pka_mod_mul(tmp_s1, tmp_h, tmp_s1);
    cc3xx_lowlevel_pka_mod_sub(res->y, tmp_s1, res->y);

    /* res->z = p->z * q->z * H */
    cc3xx_lowlevel_pka_mod_mul(p->z, q->z, res->z);
    cc3xx_lowlevel_pka_mod_mul(res->z, tmp_h, res->z);

    cc3xx_lowlevel_pka_free_reg(tmp_s2);
    cc3xx_lowlevel_pka_free_reg(tmp_s1);
    cc3xx_lowlevel_pka_free_reg(tmp_u2);
    cc3xx_lowlevel_pka_free_reg(tmp_u1);
}

cc3xx_err_t cc3xx_lowlevel_ec_weierstrass_add_points(cc3xx_ec_curve_t *curve,
                                                     cc3xx_ec_point_affine *p,
                                                     cc3xx_ec_point_affine *q,
                                                     cc3xx_ec_point_affine *res)
{
    cc3xx_err_t err;

    cc3xx_ec_point_projective proj_p = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_q = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_res = cc3xx_lowlevel_ec_allocate_projective_point();

    cc3xx_lowlevel_ec_affine_to_jacobian(curve, p, &proj_p);
    cc3xx_lowlevel_ec_affine_to_jacobian(curve, q, &proj_q);

    add_points(curve, &proj_p, &proj_q, &proj_res);

    err = cc3xx_lowlevel_ec_jacobian_to_affine(curve, &proj_res, res);

    cc3xx_lowlevel_ec_free_projective_point(&proj_res);
    cc3xx_lowlevel_ec_free_projective_point(&proj_q);
    cc3xx_lowlevel_ec_free_projective_point(&proj_p);

    return err;
}

#if !defined(CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE) || !defined(SCALAR_MULT_NO_SECRET)
static void negate_point(cc3xx_ec_point_projective *p,
                         cc3xx_ec_point_projective *res)
{
    if (p != res) {
        cc3xx_lowlevel_pka_copy(p->x, res->x);
        cc3xx_lowlevel_pka_copy(p->z, res->z);
    }

    cc3xx_lowlevel_pka_mod_neg(p->y, res->y);
}

static cc3xx_err_t multiply_point_by_scalar_side_channel_protected(
                                             cc3xx_ec_curve_t *curve,
                                             cc3xx_ec_point_affine *p,
                                             cc3xx_pka_reg_id_t scalar,
                                             cc3xx_ec_point_affine *res)
{
    int32_t idx;
    uint8_t bit_pair;
    int32_t carry;
    uint32_t table_select;
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;

    cc3xx_ec_point_projective accumulator = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective final_carry_accumulator;

    cc3xx_ec_point_projective proj_p = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_neg_p = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_2p = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_neg_2p = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_4p = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_neg_4p = cc3xx_lowlevel_ec_allocate_projective_point();

    /* The index in the point add table plus the index in the carry table is
     * equal to p * index. For example, at index 1, we take proj_neg_2p with a
     * -1 carry to make -3 * p. This allows all point multiples from -4 * p to
     *  3 * p to be constructed only from the even multiples, and crucially
     *  allows the inner loop to avoid any branching. This would be possible
     *  with a smaller table as well, but would be much less efficient. We can't
     *  precalculate a larger even-multiple table (or a full even/odd multiple
     *  table) because we'd run out of physical PKA registers, which would cause
     *  a _huge_ performance hit with a register flush/remap in the inner loop.
     */
    cc3xx_ec_point_projective point_add_table[8] = {
        proj_neg_4p, proj_neg_2p, proj_neg_2p, proj_neg_p,
        proj_p,      proj_p,      proj_2p,     proj_4p,
    };
    int32_t carry_table[8] = { 0, -1, 0, 0, -1, 0, 0, -1, };

    /* This must be done before the unmap, so that p isn't mapped for the main
     * part of this function.
     */
    cc3xx_lowlevel_ec_affine_to_jacobian_with_random_z(curve, p, &proj_p);
    cc3xx_lowlevel_pka_unmap_physical_registers();

    /* calculate the necessary multiples */
    negate_point(&proj_p, &proj_neg_p);
    double_point(curve, &proj_p, &proj_2p);
    double_point(curve, &proj_p, &proj_2p);
    double_point(curve, &proj_p, &proj_2p);
    double_point(curve, &proj_p, &proj_2p);
    double_point(curve, &proj_p, &proj_2p);
    double_point(curve, &proj_p, &proj_2p);
    double_point(curve, &proj_p, &proj_2p);
    negate_point(&proj_2p, &proj_neg_2p);
    double_point(curve, &proj_2p, &proj_4p);
    negate_point(&proj_4p, &proj_neg_4p);

    /* This needs to be two-aligned for the two-sized window to work. The upper
     * bits are zero, so this is fine
     */
    idx = cc3xx_lowlevel_pka_get_bit_size(scalar);
    if (idx & 1) {
        idx += 1;
    }

    idx -= 2;
    bit_pair = cc3xx_lowlevel_pka_test_bits_ui(scalar, idx, 2);
    /* This should never happen */
    assert(bit_pair != 0);
    idx -= 2;

    table_select = bit_pair + 4;
    cc3xx_lowlevel_ec_copy_projective_point(&point_add_table[table_select], &accumulator);
    carry = carry_table[table_select];

    for (; idx >= 0; idx -= 2) {
        /* Multiple accumulator by 4, performing two doubles */
        double_point(curve, &accumulator, &accumulator);
        double_point(curve, &accumulator, &accumulator);

        /* Select which multiple will be added based on the value of the
         * bit-pair and the carry. This also determines the new carry value.
         */
        bit_pair = cc3xx_lowlevel_pka_test_bits_ui(scalar, idx, 2);
        table_select = (carry * 4) + bit_pair + 4;

        add_points(curve, &accumulator, &point_add_table[table_select], &accumulator);
        carry = carry_table[table_select];

        if (idx > 0) {
            if (cc3xx_lowlevel_ec_projective_point_is_infinity(&accumulator)) {
                FATAL_ERR(CC3XX_ERR_EC_POINT_IS_INFINITY);
                err |= CC3XX_ERR_EC_POINT_IS_INFINITY;
            }
        } else {
            if (cc3xx_lowlevel_ec_projective_point_is_infinity(&proj_p)) {
                FATAL_ERR(CC3XX_ERR_EC_POINT_IS_INFINITY);
                err |= CC3XX_ERR_EC_POINT_IS_INFINITY;
            }
        }
    }

    /* Free some of the points that aren't used from now on, to get physical
     * registers back to map the final_carry_accumulator.
     */
    cc3xx_lowlevel_ec_free_projective_point(&proj_neg_4p);
    cc3xx_lowlevel_ec_free_projective_point(&proj_4p);
    cc3xx_lowlevel_ec_free_projective_point(&proj_neg_2p);
    cc3xx_lowlevel_ec_free_projective_point(&proj_2p);

    cc3xx_lowlevel_pka_unmap_physical_registers();

    final_carry_accumulator = cc3xx_lowlevel_ec_allocate_projective_point();

    add_points(curve, &accumulator, &proj_neg_p, &final_carry_accumulator);

    if (carry == -1) {
        if (cc3xx_lowlevel_ec_projective_point_is_infinity(&final_carry_accumulator)) {
            FATAL_ERR(CC3XX_ERR_EC_POINT_IS_INFINITY);
            err |= CC3XX_ERR_EC_POINT_IS_INFINITY;
        }

        err |= cc3xx_lowlevel_ec_jacobian_to_affine(curve, &final_carry_accumulator,
                                                    res);
    } else {
        if (cc3xx_lowlevel_ec_projective_point_is_infinity(&accumulator)) {
            FATAL_ERR(CC3XX_ERR_EC_POINT_IS_INFINITY);
            err |= CC3XX_ERR_EC_POINT_IS_INFINITY;
        }

        err |= cc3xx_lowlevel_ec_jacobian_to_affine(curve, &accumulator, res);
    }

    if (err != CC3XX_ERR_SUCCESS) {
        cc3xx_lowlevel_pka_clear(res->x);
        cc3xx_lowlevel_pka_clear(res->y);
    }

    cc3xx_lowlevel_ec_free_projective_point(&final_carry_accumulator);
    cc3xx_lowlevel_ec_free_projective_point(&proj_neg_p);
    cc3xx_lowlevel_ec_free_projective_point(&proj_p);
    cc3xx_lowlevel_ec_free_projective_point(&accumulator);

    cc3xx_lowlevel_pka_unmap_physical_registers();

    return err;
}
#endif /* !CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE */

#if defined(CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE)
static cc3xx_err_t shamir_multiply_points_by_scalars_and_add(
                                             cc3xx_ec_curve_t *curve,
                                             cc3xx_ec_point_affine *p1,
                                             cc3xx_pka_reg_id_t    scalar1,
                                             cc3xx_ec_point_affine *p2,
                                             cc3xx_pka_reg_id_t    scalar2,
                                             cc3xx_ec_point_affine *res)
{
    int32_t idx;
    uint32_t bitsize1;
    uint32_t bitsize2;
    uint32_t bit1;
    uint32_t bit2;
    uint32_t bit_pair;
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;
    cc3xx_ec_point_projective proj_p1 = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective proj_p2 = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective p1_plus_p2 = cc3xx_lowlevel_ec_allocate_projective_point();
    cc3xx_ec_point_projective accumulator = cc3xx_lowlevel_ec_allocate_projective_point();

    assert(cc3xx_lowlevel_pka_greater_than_si(scalar1, 0)
           || cc3xx_lowlevel_pka_greater_than_si(scalar2, 0));

    bitsize1 = cc3xx_lowlevel_pka_get_bit_size(scalar1);
    bitsize2 = cc3xx_lowlevel_pka_get_bit_size(scalar2);

    cc3xx_lowlevel_pka_unmap_physical_registers();

    cc3xx_lowlevel_ec_affine_to_jacobian(curve, p1, &proj_p1);
    cc3xx_lowlevel_ec_affine_to_jacobian(curve, p2, &proj_p2);

    add_points(curve, &proj_p1, &proj_p2, &p1_plus_p2);

    if (bitsize1 > bitsize2) {
        cc3xx_lowlevel_ec_copy_projective_point(&proj_p1, &accumulator);
        idx = bitsize1;
    } else if (bitsize2 > bitsize1) {
        cc3xx_lowlevel_ec_copy_projective_point(&proj_p2, &accumulator);
        idx = bitsize2;
    } else {
        cc3xx_lowlevel_ec_copy_projective_point(&p1_plus_p2, &accumulator);
        idx = bitsize2;
    }

    idx -= 2;

    for (; idx >= 0; idx--) {
        double_point(curve, &accumulator, &accumulator);

        bit1 = cc3xx_lowlevel_pka_test_bits_ui(scalar1, idx, 1);
        bit2 = cc3xx_lowlevel_pka_test_bits_ui(scalar2, idx, 1);
        bit_pair = (bit1 << 1) + bit2;

        switch (bit_pair) {
        case 1:
            add_points(curve, &accumulator, &proj_p2, &accumulator);
            break;
        case 2:
            add_points(curve, &accumulator, &proj_p1, &accumulator);
            break;
        case 3:
            add_points(curve, &accumulator, &p1_plus_p2, &accumulator);
            break;
        }

        if (cc3xx_lowlevel_ec_projective_point_is_infinity(&accumulator)) {
            FATAL_ERR(CC3XX_ERR_EC_POINT_IS_INFINITY);
            err |= CC3XX_ERR_EC_POINT_IS_INFINITY;
        }
    }

    err |= cc3xx_lowlevel_ec_jacobian_to_affine(curve, &accumulator, res);

    cc3xx_lowlevel_ec_free_projective_point(&accumulator);
    cc3xx_lowlevel_ec_free_projective_point(&p1_plus_p2);
    cc3xx_lowlevel_ec_free_projective_point(&proj_p2);
    cc3xx_lowlevel_ec_free_projective_point(&proj_p1);

    cc3xx_lowlevel_pka_unmap_physical_registers();

    return err;
}
#endif /* CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE */

cc3xx_err_t cc3xx_lowlevel_ec_weierstrass_multiply_point_by_scalar(
                                             cc3xx_ec_curve_t *curve,
                                             cc3xx_ec_point_affine *p,
                                             cc3xx_pka_reg_id_t scalar,
                                             cc3xx_ec_point_affine *res)
{
    /* If we only ever handle non-secret data, we can save some code size by
     * using the Shamir trick exponentiation with a zero as the second scalar
     */
#if defined(CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE) && defined(SCALAR_MULT_NO_SECRET)
    cc3xx_pka_reg_id_t zero_reg = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_clear(zero_reg);
    cc3xx_err_t err = shamir_multiply_points_by_scalars_and_add(curve, p, scalar,
                                                               p, zero_reg, res);

    cc3xx_lowlevel_pka_free_reg(zero_reg);
    return err;
#else
    return multiply_point_by_scalar_side_channel_protected(curve, p, scalar, res);
#endif
}

cc3xx_err_t cc3xx_lowlevel_ec_weierstrass_shamir_multiply_points_by_scalars_and_add(
                                             cc3xx_ec_curve_t *curve,
                                             cc3xx_ec_point_affine *p1,
                                             cc3xx_pka_reg_id_t    scalar1,
                                             cc3xx_ec_point_affine *p2,
                                             cc3xx_pka_reg_id_t    scalar2,
                                             cc3xx_ec_point_affine *res)
{
#if defined(CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE)
    return shamir_multiply_points_by_scalars_and_add(curve,
                                                     p1, scalar1,
                                                     p2, scalar2, res);
#else
    cc3xx_err_t err = CC3XX_ERR_SUCCESS;
    cc3xx_ec_point_affine temp_point = cc3xx_lowlevel_ec_allocate_point();

    err |= multiply_point_by_scalar_side_channel_protected(curve, p1, scalar1,
                                                           &temp_point);
    err |= multiply_point_by_scalar_side_channel_protected(curve, p2, scalar2,
                                                           res);
    err |= cc3xx_lowlevel_ec_add_points(curve, &temp_point, res, res);

    cc3xx_lowlevel_ec_free_point(&temp_point);

    return err;
#endif /* CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE */
}
