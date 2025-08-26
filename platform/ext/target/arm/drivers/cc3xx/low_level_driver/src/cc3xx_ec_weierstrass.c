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

/* Using dbl-2007-bl via
 * https://www.hyperelliptic.org/EFD/g1p/auto-shortw-jacobian.html#doubling-dbl-2007-bl
 */
static void double_point(cc3xx_ec_curve_t *curve, cc3xx_ec_point_projective *p,
                         cc3xx_ec_point_projective *res)
{
    const bool p_is_infinity = cc3xx_lowlevel_ec_projective_point_is_infinity(p);

    if (p_is_infinity) {
        return cc3xx_lowlevel_ec_projective_point_make_infinity(res);
    }

    cc3xx_pka_reg_id_t t0 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t1 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t2 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t3 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_pka_reg_id_t X1 = p->x;
    cc3xx_pka_reg_id_t Y1 = p->y;
    cc3xx_pka_reg_id_t Z1 = p->z;

    cc3xx_pka_reg_id_t X3 = res->x;
    cc3xx_pka_reg_id_t Y3 = res->y;
    cc3xx_pka_reg_id_t Z3 = res->z;

    /* t0 = Y1*Y1 */
    cc3xx_lowlevel_pka_mod_mul(Y1, Y1, t0);

    /* t1 = Z1*Z1 */
    cc3xx_lowlevel_pka_mod_mul(Z1, Z1, t1);

    /* t2 = X1*X1 */
    cc3xx_lowlevel_pka_mod_mul(X1, X1, t2);

    /* t3 = t0*t0 */
    cc3xx_lowlevel_pka_mod_mul(t0, t0, t3);

    /* Z3 = Y1+Z1 */
    cc3xx_lowlevel_pka_mod_add(Y1, Z1, Z3);

    /* Z3 = Z3*Z3 */
    cc3xx_lowlevel_pka_mod_mul(Z3, Z3, Z3);

    /* Z3 = Z3-t0 */
    cc3xx_lowlevel_pka_mod_sub(Z3, t0, Z3);

    /* Z3 = Z3-t1 */
    cc3xx_lowlevel_pka_mod_sub(Z3, t1, Z3);

    /* t0 = X1+t0 */
    cc3xx_lowlevel_pka_mod_add(X1, t0, t0);

    /* t0 = t0*t0 */
    cc3xx_lowlevel_pka_mod_mul(t0, t0, t0);

    /* t0 = t0-t2 */
    cc3xx_lowlevel_pka_mod_sub(t0, t2, t0);

    /* t0 = t0-t3 */
    cc3xx_lowlevel_pka_mod_sub(t0, t3, t0);

    /* t0 = t0+t0 */
    cc3xx_lowlevel_pka_mod_add(t0, t0, t0);

    /* t1 = t1*t1 */
    cc3xx_lowlevel_pka_mod_mul(t1, t1, t1);

    /* t1 = a*t1  */
    cc3xx_lowlevel_pka_mod_mul(curve->param_a, t1, t1);

    /* t1 = t1+t2 */
    cc3xx_lowlevel_pka_mod_add(t1, t2, t1);

    /* t1 = t1+t2 */
    cc3xx_lowlevel_pka_mod_add(t1, t2, t1);

    /* t1 = t1+t2 */
    cc3xx_lowlevel_pka_mod_add(t1, t2, t1);

    /* X3 = t1*t1 */
    cc3xx_lowlevel_pka_mod_mul(t1, t1, X3);

    /* X3 = X3-t0 */
    cc3xx_lowlevel_pka_mod_sub(X3, t0, X3);

    /* X3 = X3-t0 */
    cc3xx_lowlevel_pka_mod_sub(X3, t0, X3);

    /* Y3 = t0-X3 */
    cc3xx_lowlevel_pka_mod_sub(t0, X3, Y3);

    /* Y3 = t1*Y3 */
    cc3xx_lowlevel_pka_mod_mul(t1, Y3, Y3);

    /* t2 = 8 */
    cc3xx_lowlevel_pka_clear(t2);
    cc3xx_lowlevel_pka_add_si(t2, 8, t2);

    /* t3 = t2*t3 */
    cc3xx_lowlevel_pka_mod_mul(t2, t3, t3);

    /* Y3 = Y3-t4 */
    cc3xx_lowlevel_pka_mod_sub(Y3, t3, Y3);

    cc3xx_lowlevel_pka_free_reg(t3);
    cc3xx_lowlevel_pka_free_reg(t2);
    cc3xx_lowlevel_pka_free_reg(t1);
    cc3xx_lowlevel_pka_free_reg(t0);
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

#if defined(CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE)
/* using mmadd-2007-bl via
 * https://www.hyperelliptic.org/EFD/g1p/auto-shortw-jacobian.html#addition-mmadd-2007-bl
 *
 * note that input points p and q must be affine points, Zp=Zq=1
 */
static void mmadd_points(cc3xx_ec_curve_t *curve, cc3xx_ec_point_projective *p,
                       cc3xx_ec_point_projective *q, cc3xx_ec_point_projective *res)
{
    cc3xx_pka_reg_id_t t0 = cc3xx_lowlevel_pka_allocate_reg();

    if (cc3xx_lowlevel_pka_are_equal(p->x, q->x)) {
        /* Check if P = Q */
        if (cc3xx_lowlevel_pka_are_equal(p->y, q->y)) {
            return double_point(curve, p, res);
        }

        /* Check if P = -Q */
        cc3xx_lowlevel_pka_mod_neg(p->y, t0);
        if (cc3xx_lowlevel_pka_are_equal(t0, q->y)) {
            cc3xx_lowlevel_pka_free_reg(t0);
            return cc3xx_lowlevel_ec_projective_point_make_infinity(res);
        }

        cc3xx_lowlevel_pka_free_reg(t0);

        /**
         * @note If P and Q have the same "x" affine coordinate, the "y"
         *       affine coordinates are either equal or opposite of each
         *       other. Therefore, this point should never be reached.
         *
         */
        assert(false);
    }

    cc3xx_pka_reg_id_t t1 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t2 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_pka_reg_id_t X1 = p->x;
    cc3xx_pka_reg_id_t Y1 = p->y;

    cc3xx_pka_reg_id_t X2 = q->x;
    cc3xx_pka_reg_id_t Y2 = q->y;

    cc3xx_pka_reg_id_t X3 = res->x;
    cc3xx_pka_reg_id_t Y3 = res->y;
    cc3xx_pka_reg_id_t Z3 = res->z;

    /* t0 = X2-X1 */
    cc3xx_lowlevel_pka_mod_sub(X2, X1, t0);

    /* t1 = t0*t0 */
    cc3xx_lowlevel_pka_mod_mul(t0, t0, t1);

    /* t2 = t1+t1 */
    cc3xx_lowlevel_pka_mod_add(t1, t1, t2);

    /* t2 = t2+t1 */
    cc3xx_lowlevel_pka_mod_add(t2, t1, t2);

    /* t2 = t2+t1 */
    cc3xx_lowlevel_pka_mod_add(t2, t1, t2);

    /* Z3 = t0+t0 */
    cc3xx_lowlevel_pka_mod_add(t0, t0, Z3);

    /* t0 = t0*t2 */
    cc3xx_lowlevel_pka_mod_mul(t0, t2, t0);

    /* t1 = X1*t2 */
    cc3xx_lowlevel_pka_mod_mul(X1, t2, t1);

    /* t2 = Y2-Y1 */
    cc3xx_lowlevel_pka_mod_sub(Y2, Y1, t2);

    /* t2 = t2+t2 */
    cc3xx_lowlevel_pka_mod_add(t2, t2, t2);

    /* X3 = t2*t2 */
    cc3xx_lowlevel_pka_mod_mul(t2, t2, X3);

    /* X3 = X3-t0 */
    cc3xx_lowlevel_pka_mod_sub(X3, t0, X3);

    /* X3 = X3-t1 */
    cc3xx_lowlevel_pka_mod_sub(X3, t1, X3);

    /* X3 = X3-t1 */
    cc3xx_lowlevel_pka_mod_sub(X3, t1, X3);

    /* t0 = Y1*t0 */
    cc3xx_lowlevel_pka_mod_mul(Y1, t0, t0);

    /* t0 = t0+t0 */
    cc3xx_lowlevel_pka_mod_add(t0, t0, t0);

    /* Y3 = t1-X3 */
    cc3xx_lowlevel_pka_mod_sub(t1, X3, Y3);

    /* Y3 = t2*Y3 */
    cc3xx_lowlevel_pka_mod_mul(t2, Y3, Y3);

    /* Y3 = Y3-t0 */
    cc3xx_lowlevel_pka_mod_sub(Y3, t0, Y3);

    cc3xx_lowlevel_pka_free_reg(t2);
    cc3xx_lowlevel_pka_free_reg(t1);
    cc3xx_lowlevel_pka_free_reg(t0);
}

/* using madd-2007-bl via
 * https://www.hyperelliptic.org/EFD/g1p/auto-shortw-jacobian.html#addition-madd-2007-bl
 *
 * note that input point Q must be an affine point, Zq=1
 */
static void madd_points(cc3xx_ec_curve_t *curve, cc3xx_ec_point_projective *p,
                       cc3xx_ec_point_projective *q, cc3xx_ec_point_projective *res)
{
    const bool p_is_infinity = cc3xx_lowlevel_ec_projective_point_is_infinity(p);

    /* if P == 0, P + Q = Q */
    if (p_is_infinity) {
        return cc3xx_lowlevel_ec_copy_projective_point(q, res);
    }

    cc3xx_pka_reg_id_t t0 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t1 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t2 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t3 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_pka_reg_id_t X1 = p->x;
    cc3xx_pka_reg_id_t Y1 = p->y;
    cc3xx_pka_reg_id_t Z1 = p->z;

    cc3xx_pka_reg_id_t X2 = q->x;
    cc3xx_pka_reg_id_t Y2 = q->y;

    cc3xx_pka_reg_id_t X3 = res->x;
    cc3xx_pka_reg_id_t Y3 = res->y;
    cc3xx_pka_reg_id_t Z3 = res->z;

    cc3xx_pka_reg_id_t U1 = X1;
    cc3xx_pka_reg_id_t U2 = t1;
    cc3xx_pka_reg_id_t S1 = Y1;
    cc3xx_pka_reg_id_t S2 = t2;

    /* t0 = Z1*Z1 */
    cc3xx_lowlevel_pka_mod_mul(Z1, Z1, t0);

    /* t1 = X2*t0 */
    cc3xx_lowlevel_pka_mod_mul(X2, t0, t1);

    /* t2 = Y2*Z1 */
    cc3xx_lowlevel_pka_mod_mul(Y2, Z1, t2);

    /* Compare U1 to U2 */
    if (cc3xx_lowlevel_pka_are_equal(U1, U2)) {
        /* P == Q iff U1 == U2 && S1 == S2 */
        if (cc3xx_lowlevel_pka_are_equal(S1, S2)) {
            cc3xx_lowlevel_pka_free_reg(t3);
            cc3xx_lowlevel_pka_free_reg(t2);
            cc3xx_lowlevel_pka_free_reg(t1);
            cc3xx_lowlevel_pka_free_reg(t0);

            /* If P == Q, P + Q = 2P */
            return double_point(curve, p, res);
        }
        /* P == -Q iff U1 == U2 && S1 == -S2*/
        cc3xx_lowlevel_pka_mod_neg(S2, S2);
        if (cc3xx_lowlevel_pka_are_equal(S1, S2)) {
            cc3xx_lowlevel_pka_free_reg(t3);
            cc3xx_lowlevel_pka_free_reg(t2);
            cc3xx_lowlevel_pka_free_reg(t1);
            cc3xx_lowlevel_pka_free_reg(t0);

            /* if P == -Q, P + Q = 0, i.e. the infinity point */
            return cc3xx_lowlevel_ec_projective_point_make_infinity(res);
        }

        /**
         * @note If P and Q have the same "x" affine coordinate, the "y"
         *       affine coordinates are either equal or opposite of each
         *       other. Therefore, this point should never be reached.
         *
         */
        assert(false);
    }

    /* t1 = t1-X1 */
    cc3xx_lowlevel_pka_mod_sub(t1, X1, t1);

    /* t3 = t1*t1 */
    cc3xx_lowlevel_pka_mod_mul(t1, t1, t3);

    /* Z3 = Z1+t1 */
    cc3xx_lowlevel_pka_mod_add(Z1, t1, Z3);

    /* Z3 = Z3*Z3 */
    cc3xx_lowlevel_pka_mod_mul(Z3, Z3, Z3);

    /* Z3 = Z3-t0 */
    cc3xx_lowlevel_pka_mod_sub(Z3, t0, Z3);

    /* Z3 = Z3-t3 */
    cc3xx_lowlevel_pka_mod_sub(Z3, t3, Z3);

    /* t2 = t2*t0 */
    cc3xx_lowlevel_pka_mod_mul(t2, t0, t2);

    /* t2 = t2-Y1 */
    cc3xx_lowlevel_pka_mod_sub(t2, Y1, t2);

    /* t2 = t2+t2 */
    cc3xx_lowlevel_pka_mod_add(t2, t2, t2);

    /* t0 = t3+t3 */
    cc3xx_lowlevel_pka_mod_add(t3, t3, t0);

    /* t0 = t0+t3 */
    cc3xx_lowlevel_pka_mod_add(t0, t3, t0);

    /* t0 = t0+t3 */
    cc3xx_lowlevel_pka_mod_add(t0, t3, t0);

    /* t1 = t1*t0 */
    cc3xx_lowlevel_pka_mod_mul(t1, t0, t1);

    /* t0 = X1*t0 */
    cc3xx_lowlevel_pka_mod_mul(X1, t0, t0);

    /* X3 = t2*t2 */
    cc3xx_lowlevel_pka_mod_mul(t2, t2, X3);

    /* X3 = X3-t1 */
    cc3xx_lowlevel_pka_mod_sub(X3, t1, X3);

    /* X3 = X3-t0 */
    cc3xx_lowlevel_pka_mod_sub(X3, t0, X3);

    /* X3 = X3-t0 */
    cc3xx_lowlevel_pka_mod_sub(X3, t0, X3);

    /* t3 = t0-X3 */
    cc3xx_lowlevel_pka_mod_sub(t0, X3, t3);

    /* t3 = t2*t3 */
    cc3xx_lowlevel_pka_mod_mul(t2, t3, t3);

    /* t2 = Y1*t1 */
    cc3xx_lowlevel_pka_mod_mul(Y1, t1, t2);

    /* t2 = t2+t2 */
    cc3xx_lowlevel_pka_mod_add(t2, t2, t2);

    /* Y3 = t3-t2 */
    cc3xx_lowlevel_pka_mod_sub(t3, t2, Y3);

    cc3xx_lowlevel_pka_free_reg(t3);
    cc3xx_lowlevel_pka_free_reg(t2);
    cc3xx_lowlevel_pka_free_reg(t1);
    cc3xx_lowlevel_pka_free_reg(t0);
}
#endif /* CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE */

/* Using add-2007-bl via
 * https://www.hyperelliptic.org/EFD/g1p/auto-shortw-jacobian.html#addition-add-2007-bl
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

    cc3xx_pka_reg_id_t t0 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t1 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t2 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t3 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t4 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_pka_reg_id_t t5 = cc3xx_lowlevel_pka_allocate_reg();

    /* Aliases to make the code more readable */
    cc3xx_pka_reg_id_t X1 = p->x;
    cc3xx_pka_reg_id_t Y1 = p->y;
    cc3xx_pka_reg_id_t Z1 = p->z;

    cc3xx_pka_reg_id_t X2 = q->x;
    cc3xx_pka_reg_id_t Y2 = q->y;
    cc3xx_pka_reg_id_t Z2 = q->z;

    cc3xx_pka_reg_id_t X3 = res->x;
    cc3xx_pka_reg_id_t Y3 = res->y;
    cc3xx_pka_reg_id_t Z3 = res->z;

    cc3xx_pka_reg_id_t U1 = t2;
    cc3xx_pka_reg_id_t U2 = t3;
    cc3xx_pka_reg_id_t S1 = t4;
    cc3xx_pka_reg_id_t S2 = t5;

    /* t0 = Z1^2  */
    cc3xx_lowlevel_pka_mod_mul(Z1, Z1, t0);

    /* t1 = Z2^2  */
    cc3xx_lowlevel_pka_mod_mul(Z2, Z2, t1);

    /* t2 (U1) = X1*t1 */
    cc3xx_lowlevel_pka_mod_mul(X1, t1, t2);

    /* t3 (U2) = X2*t0 */
    cc3xx_lowlevel_pka_mod_mul(X2, t0, t3);

    /* t4 = Y1*Z2 */
    cc3xx_lowlevel_pka_mod_mul(Y1, Z2, t4);

    /* t4 (S1) = t4*t1 */
    cc3xx_lowlevel_pka_mod_mul(t4, t1, t4);

    /* t5 = Y2*Z1 */
    cc3xx_lowlevel_pka_mod_mul(Y2, Z1, t5);

    /* t5 (S2) = t5*t0 */
    cc3xx_lowlevel_pka_mod_mul(t5, t0, t5);

    /* Compare U1 to U2 */
    if (cc3xx_lowlevel_pka_are_equal(U1, U2)) {
        /* P == Q iff U1 == U2 && S1 == S2 */
        if (cc3xx_lowlevel_pka_are_equal(S1, S2)) {
            cc3xx_lowlevel_pka_free_reg(t5);
            cc3xx_lowlevel_pka_free_reg(t4);
            cc3xx_lowlevel_pka_free_reg(t3);
            cc3xx_lowlevel_pka_free_reg(t2);
            cc3xx_lowlevel_pka_free_reg(t1);
            cc3xx_lowlevel_pka_free_reg(t0);

            /* If P == Q, P + Q = 2P */
            return double_point(curve, p, res);
        }
        /* P == -Q iff U1 == U2 && S1 == -S2*/
        cc3xx_lowlevel_pka_mod_neg(S2, S2);
        if (cc3xx_lowlevel_pka_are_equal(S1, S2)) {
            cc3xx_lowlevel_pka_free_reg(t5);
            cc3xx_lowlevel_pka_free_reg(t4);
            cc3xx_lowlevel_pka_free_reg(t3);
            cc3xx_lowlevel_pka_free_reg(t2);
            cc3xx_lowlevel_pka_free_reg(t1);
            cc3xx_lowlevel_pka_free_reg(t0);

            /* if P == -Q, P + Q = 0, i.e. the infinity point */
            return cc3xx_lowlevel_ec_projective_point_make_infinity(res);
        }

        /**
         * @note If P and Q have the same "x" affine coordinate, the "y"
         *       affine coordinates are either equal or opposite of each
         *       other. Therefore, this point should never be reached.
         *
         */
        assert(false);

        /* Restore the original value of S2 */
        cc3xx_lowlevel_pka_mod_neg(S2, S2);
    }

    /* t3 = t3-t2 */
    cc3xx_lowlevel_pka_mod_sub(t3, t2, t3);

    /* Z3 = Z1+Z2 */
    cc3xx_lowlevel_pka_mod_add(Z1, Z2, Z3);

    /* Z3 = Z3^2  */
    cc3xx_lowlevel_pka_mod_mul(Z3, Z3, Z3);

    /* Z3 = Z3-t0 */
    cc3xx_lowlevel_pka_mod_sub(Z3, t0, Z3);

    /* Z3 = Z3-t1 */
    cc3xx_lowlevel_pka_mod_sub(Z3, t1, Z3);

    /* Z3 = Z3*t3 */
    cc3xx_lowlevel_pka_mod_mul(Z3, t3, Z3);

    /* t1 = t3+t3 */
    cc3xx_lowlevel_pka_mod_add(t3, t3, t1);

    /* t1 = t1^2  */
    cc3xx_lowlevel_pka_mod_mul(t1, t1, t1);

    /* t2 = t2*t1 */
    cc3xx_lowlevel_pka_mod_mul(t2, t1, t2);

    /* t1 = t3*t1 */
    cc3xx_lowlevel_pka_mod_mul(t3, t1, t1);

    /* t3 = t5-t4 */
    cc3xx_lowlevel_pka_mod_sub(t5, t4, t3);

    /* t3 = t3+t3 */
    cc3xx_lowlevel_pka_mod_add(t3, t3, t3);

    /* X3 = t3^2  */
    cc3xx_lowlevel_pka_mod_mul(t3, t3, X3);

    /* X3 = X3-t1 */
    cc3xx_lowlevel_pka_mod_sub(X3, t1, X3);

    /* X3 = X3-t2 */
    cc3xx_lowlevel_pka_mod_sub(X3, t2, X3);

    /* X3 = X3-t2 */
    cc3xx_lowlevel_pka_mod_sub(X3, t2, X3);

    /* t1 = t1*t4 */
    cc3xx_lowlevel_pka_mod_mul(t1, t4, t1);

    /* t1 = t1+t1 */
    cc3xx_lowlevel_pka_mod_add(t1, t1, t1);

    /* Y3 = t2-X3 */
    cc3xx_lowlevel_pka_mod_sub(t2, X3, Y3);

    /* Y3 = Y3*t3 */
    cc3xx_lowlevel_pka_mod_mul(Y3, t3, Y3);

    /* Y3 = Y3-t1 */
    cc3xx_lowlevel_pka_mod_sub(Y3, t1, Y3);

    cc3xx_lowlevel_pka_free_reg(t5);
    cc3xx_lowlevel_pka_free_reg(t4);
    cc3xx_lowlevel_pka_free_reg(t3);
    cc3xx_lowlevel_pka_free_reg(t2);
    cc3xx_lowlevel_pka_free_reg(t1);
    cc3xx_lowlevel_pka_free_reg(t0);
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
        cc3xx_lowlevel_pka_unmap_physical_registers();

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

    mmadd_points(curve, &proj_p1, &proj_p2, &p1_plus_p2);

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
            madd_points(curve, &accumulator, &proj_p2, &accumulator);
            break;
        case 2:
            madd_points(curve, &accumulator, &proj_p1, &accumulator);
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
