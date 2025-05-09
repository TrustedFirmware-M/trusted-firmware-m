/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>

#include "cc3xx_test_pka.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif
#include "cc3xx_test_assert.h"
#include "cc3xx_dev.h"
#include "cc3xx_rng.h"

#include "cc3xx_test_utils.h"

void pka_test_write_read(struct test_result_t *ret)
{
    uint32_t r0;
    uint64_t val = 0xFEFEFEFE0EFEFEFE;
    uint64_t readback = 0;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val, sizeof(val));
    cc3xx_lowlevel_pka_read_reg(r0, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(memcmp(&val, &readback, sizeof(val)) == 0, "readback not equal to expected val");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_write_partial_read(struct test_result_t *ret)
{
    uint32_t r0;
    uint64_t val = 0xFEFEFEFE0EFEFEFE;
    uint64_t readback = 0;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val, sizeof(val));
    cc3xx_lowlevel_pka_read_reg(r0, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(memcmp(&val, &readback, sizeof(val)) == 0, "readback not equal to expected val");

    val = 0xBEEFBEEF;

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val, sizeof(val));
    cc3xx_lowlevel_pka_read_reg(r0, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(memcmp(&val, &readback, sizeof(val)) == 0, "readback not equal to expected val");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_add(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 16;
    uint32_t val1 = 32;
    uint32_t readback;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, (uint32_t *)&val1, sizeof(val1));

    cc3xx_lowlevel_pka_add(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == val0 + val1, "readback not equal to val0 + val1");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_add_si(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 16;
    int32_t val1 = 15;
    uint32_t readback;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_add_si(r0, val1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == val0 + val1, "readback not equal to val0 + val1");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_add_si_neg(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 16;
    int32_t val1 = -15;
    uint32_t readback;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_add_si(r0, val1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == val0 + val1, "readback not equal to val0 + val1");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_add_unaligned(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    const uint32_t val0[] = {0xefff9cd3, 0x7f85739e, 0xf1ff20a0, 0x639ab327,
                             0xcd187f};
    const uint32_t val1[] = {0x40b6abae, 0x8466b5f5, 0xc929521c, 0xab512b42,
                             0x16e09b};
    const uint32_t expected[] = {0x30b64881, 0x03ec2994, 0xbb2872bd,
                                 0x0eebde6a, 0x00e3f91b};
    uint32_t readback[sizeof(expected) / 4] = {0};

    const size_t aligned_bytes = sizeof(val0) - sizeof(uint32_t);
    const size_t n_unaligned_bytes = 3; /* Tweakable from 1 to 3 */
    const size_t operand_size = aligned_bytes + n_unaligned_bytes;

    cc3xx_lowlevel_pka_init(sizeof(val0) * 8);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (const uint32_t *) val0, operand_size);
    cc3xx_lowlevel_pka_write_reg(r1, (const uint32_t *) val1, operand_size);

    cc3xx_lowlevel_pka_add(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg(res, readback, sizeof(readback));

    TEST_ASSERT(memcmp(&expected, &readback, sizeof(expected)) == 0,
            "readback not equal to expected val");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();
}

void pka_test_add_unaligned_be(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    const uint32_t val0[] = {0xefff9cd3, 0x7f85739e, 0xf1ff20a0, 0x639ab327,
                             0xcd187f};
    const uint32_t val1[] = {0x40b6abae, 0x8466b5f5, 0xc929521c, 0xab512b42,
                             0x16e09b};
    const uint32_t expected[] = {0xb6488201, 0xec289430, 0x2973bc03,
                                 0xecde69ba, 0xe3f81a0f};
    uint32_t readback[sizeof(expected) / 4] = {0};

    const size_t aligned_bytes = sizeof(val0) - sizeof(uint32_t);
    const size_t n_unaligned_bytes = 3; /* Tweakable from 1 to 3 */
    const size_t operand_size = aligned_bytes + n_unaligned_bytes;

    cc3xx_lowlevel_pka_init(sizeof(val0) * 8);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg_swap_endian(r0, (const uint32_t *) val0,
                                operand_size);
    cc3xx_lowlevel_pka_write_reg_swap_endian(r1, (const uint32_t *) val1,
                                operand_size);

    cc3xx_lowlevel_pka_add(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg_swap_endian(res, readback, sizeof(readback));

    TEST_ASSERT(memcmp(&expected, &readback, sizeof(expected)) == 0,
            "readback not equal to expected val");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();
}

void pka_test_sub(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 16;
    uint32_t val1 = 32;
    int32_t readback;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, (uint32_t *)&val1, sizeof(val1));

    cc3xx_lowlevel_pka_sub(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == val0 - val1, "readback not equal to val0 - val1");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_sub_si(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 16;
    int32_t val1 = 6;
    uint32_t readback;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_sub_si(r0, val1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == val0 - val1, "readback not equal to val0 - val1");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_sub_si_neg(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 16;
    int32_t val1 = -6;
    uint32_t readback;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_sub_si(r0, val1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == val0 - val1, "readback not equal to val0 - val1");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_neg(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 16;
    int32_t readback;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_neg(r0, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == val0 * -1, "readback not equal to val0 * -1");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_get_bitsize(struct test_result_t *ret)
{
    uint64_t val0 = 0x00FFFFFF0000FFFF;
    cc3xx_pka_reg_id_t r0;
    uint32_t bitsize;

    cc3xx_lowlevel_pka_init(16);
    r0 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, &val0, sizeof(val0));

    bitsize = cc3xx_lowlevel_pka_get_bit_size(r0);

    assert(bitsize == 56);

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_mod_add(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint64_t val0 = 0x1600000000000000;
    uint64_t val1 = 0x3200000000000000;
    uint64_t valN = 0x4100000000000000;
    uint64_t readback;

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, (uint32_t *)&val1, sizeof(val1));

    cc3xx_lowlevel_pka_mod_add(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == ((val0 + val1) % valN), "readback not equal to (val0 + val1) % valN");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_mod_add_si(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0 = 15;
    int32_t val1 = 14;
    uint32_t valN = 16;
    uint32_t readback;

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_mod_add_si(r0, val1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == ((val0 + val1) % valN), "readback not equal to (val0 + val1) % valN");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_mod_sub(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    int32_t val0 = 32;
    int32_t val1 = 16;
    uint32_t valN = 40;
    int32_t readback;
    int32_t expected = pmod(val0 - val1, valN);

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, (uint32_t *)&val1, sizeof(val1));

    cc3xx_lowlevel_pka_mod_sub(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == expected, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();
    /* while(1){} */

    return;
}

void pka_test_mod_sub_si(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t res;
    uint32_t val0 = 6;
    uint32_t val1 = 15;
    uint32_t valN = 20;
    uint32_t readback;
    uint32_t expected = pmod((int32_t)(val0 - val1), valN);

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_mod_sub_si(r0, val1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == expected, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_shift_left(struct test_result_t *ret)
{
    uint32_t end_val[] = {0xA0000000, 0x00000000, 0x00000000, 0x00000000,
                          0x00000000, 0x00000000, 0x00000000, 0x00000000};
    int32_t readback;
    cc3xx_pka_reg_id_t r0;
    cc3xx_pka_reg_id_t expected;
    cc3xx_pka_reg_id_t end;
    cc3xx_pka_reg_id_t reg_2;

    cc3xx_lowlevel_pka_init(sizeof(end_val) * 4);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    expected = cc3xx_lowlevel_pka_allocate_reg();
    end = cc3xx_lowlevel_pka_allocate_reg();
    reg_2 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_clear(r0);
    cc3xx_lowlevel_pka_add_si(r0, 0xA, r0);

    cc3xx_lowlevel_pka_clear(reg_2);
    cc3xx_lowlevel_pka_add_si(reg_2, 0x2, reg_2);

    cc3xx_lowlevel_pka_write_reg_swap_endian(end, (uint32_t *)end_val, sizeof(end_val));

    do {
        cc3xx_lowlevel_pka_mul_low_half(r0, reg_2, expected);
        cc3xx_lowlevel_pka_shift_left_fill_0_ui(r0, 1, r0);
        TEST_ASSERT(cc3xx_lowlevel_pka_are_equal(r0, expected), "value in r0 not equal to expected value");
    } while (!cc3xx_lowlevel_pka_are_equal(r0, end));

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_shift_right(struct test_result_t *ret)
{
    uint32_t start_val[] = {0xA0000000, 0x00000000, 0x00000000, 0x00000000,
                            0x00000000, 0x00000000, 0x00000000, 0x00000000};
    int32_t readback;
    cc3xx_pka_reg_id_t r0;
    cc3xx_pka_reg_id_t expected;
    cc3xx_pka_reg_id_t end;
    cc3xx_pka_reg_id_t reg_2;
    cc3xx_pka_reg_id_t remainder;

    cc3xx_lowlevel_pka_init(sizeof(start_val));

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    expected = cc3xx_lowlevel_pka_allocate_reg();
    end = cc3xx_lowlevel_pka_allocate_reg();
    reg_2 = cc3xx_lowlevel_pka_allocate_reg();
    remainder = cc3xx_lowlevel_pka_allocate_reg();


    cc3xx_lowlevel_pka_write_reg_swap_endian(r0, (uint32_t *)start_val, sizeof(start_val));

    cc3xx_lowlevel_pka_clear(reg_2);
    cc3xx_lowlevel_pka_add_si(reg_2, 0x2, reg_2);

    cc3xx_lowlevel_pka_clear(end);
    cc3xx_lowlevel_pka_add_si(end, 0xA, end);

    do {
        cc3xx_lowlevel_pka_div(r0, reg_2, expected, remainder);
        cc3xx_lowlevel_pka_shift_right_fill_0_ui(r0, 1, r0);
        TEST_ASSERT(cc3xx_lowlevel_pka_are_equal(r0, expected), "value in r0 not equal to expected");
    } while (!cc3xx_lowlevel_pka_are_equal(r0, end));

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}
void pka_test_mod_neg(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t res;
    uint32_t reg_expected;
    uint32_t val0[] = {0x1d5b43a0, 0xca6284ce, 0x6d8cc430, 0xa828321d, 0xf8ba3c0a, 0x44fa2cd6, 0x5d0f4b6f, 0x86d7e925};
    uint32_t valN[] = {0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0xffffffff,};
    uint32_t expected[] = {0xe2a4bc5f, 0x359d7b31, 0x92733bcf, 0x57d7cde3, 0x0745c3f5, 0xbb05d329, 0xa2f0b491, 0x792816d9,};
    uint32_t readback[8];

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    reg_expected = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(reg_expected, (uint32_t *)&expected, sizeof(expected));

    cc3xx_lowlevel_pka_mod_neg(r0, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(memcmp(readback, expected, sizeof(readback)) == 0, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_div(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t quotient;
    uint32_t remainder;

    uint32_t val0[4]     = {0x00000000, 0x00000000, 0x00000000, 0x10000000};
    uint32_t val1[4]     = {0xFFFFFFFF, 0x001FFFFF};
    uint32_t expected[4] = {0x00040000, 0x00000000, 0x00000080};
    uint32_t readback[4];

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    quotient = cc3xx_lowlevel_pka_allocate_reg();
    remainder = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, val1, sizeof(val1));

    cc3xx_lowlevel_pka_div(r0, r1, quotient, remainder);

    cc3xx_lowlevel_pka_read_reg(quotient, readback, sizeof(readback));

    TEST_ASSERT(memcmp(readback, expected, sizeof(expected)) == 0, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_mod_mul(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint64_t val0 = 0x1600000000000000;
    uint64_t val1 = 0x3200000000000000;
    uint64_t valN = 0xFFFFFFFFFFFFFFFF;
    uint64_t readback;

    while(valN > 2) {
        cc3xx_lowlevel_pka_init(16);
        cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
        cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
        cc3xx_lowlevel_pka_set_modulus(N, true, 0);

        r0 = cc3xx_lowlevel_pka_allocate_reg();
        r1 = cc3xx_lowlevel_pka_allocate_reg();
        res = cc3xx_lowlevel_pka_allocate_reg();

        val0 = (valN - 1);
        val1 = 2;
        cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
        cc3xx_lowlevel_pka_write_reg(r1, (uint32_t *)&val1, sizeof(val1));

        cc3xx_lowlevel_pka_mod_mul(r0, r1, res);

        cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

        uint64_t expected = valN - 2;
        TEST_ASSERT(readback == expected, "readback not equal to expected");

        valN >>= 1;
    }

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

uint64_t part_pow(uint64_t x, uint64_t pow, uint64_t N)
{
    uint64_t temp = 1;
    for (int I = 0; I < pow; I++) {
        temp *= x;
        temp = temp % N;
    }

    return temp;
}

void pka_test_mod_exp(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    int32_t val0 = 32;
    int32_t val1 = 6;
    uint32_t valN = 39;
    uint64_t readback;
    int32_t expected = part_pow(val0, val1, valN);

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, (uint32_t *)&val1, sizeof(val1));

    cc3xx_lowlevel_pka_mod_exp(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == expected, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_mod_exp_si(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t res;
    int32_t val0 = 32;
    uint32_t val1 = 5;
    uint32_t valN = 39;
    uint64_t readback;
    int32_t expected = part_pow(val0, val1, valN);

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_mod_exp_si(r0, val1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == expected, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_mod_inv(struct test_result_t *ret)
{
    cc3xx_pka_reg_id_t r0;
    cc3xx_pka_reg_id_t res;
    uint32_t val0 = 32;
    uint32_t valN = 35;
    uint32_t expected = 23;
    uint64_t readback;

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_mod_inv(r0, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == expected, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_mod_inv_prime_modulus(struct test_result_t *ret)
{
    cc3xx_pka_reg_id_t r0;
    cc3xx_pka_reg_id_t res;
    uint32_t val0 = 32;
    uint32_t valN = 37;
    uint32_t expected = 22;
    uint64_t readback;

    cc3xx_lowlevel_pka_init(16);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    cc3xx_lowlevel_pka_mod_inv_prime_modulus(r0, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(readback == expected, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_virtual_registers(struct test_result_t *ret)
{
    cc3xx_pka_reg_id_t r[CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT - 4];
    cc3xx_pka_reg_id_t res;
    uint64_t readback;
    uint32_t idx;
    uint32_t rand_0;
    uint32_t rand_1;

    cc3xx_lowlevel_pka_init(4);
    res = cc3xx_lowlevel_pka_allocate_reg();

    for (idx = 0; idx < sizeof(r); idx++) {
        r[idx] = cc3xx_lowlevel_pka_allocate_reg();
        cc3xx_lowlevel_pka_write_reg(r[idx], &idx, sizeof(idx));
    }

    for (idx = 0; idx < 128; idx++) {
        cc3xx_lowlevel_rng_get_random_uint(sizeof(r), &rand_0, CC3XX_RNG_LFSR);
        cc3xx_lowlevel_rng_get_random_uint(sizeof(r), &rand_1, CC3XX_RNG_LFSR);

        cc3xx_lowlevel_pka_add(r[rand_0], r[rand_1], res);
        cc3xx_lowlevel_pka_read_reg(res, &readback, sizeof(readback));
        TEST_ASSERT(readback == rand_0 + rand_1, "readback not equal to expected");
    }

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_large_exponentiation(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t r1;
    uint32_t res;
    uint32_t val0[64] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10000000};
    uint32_t val1 = 0x2;
    uint32_t valN[64] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
    uint32_t expected[64] =
                        {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                         0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1000000};
    uint32_t readback[64];

    cc3xx_lowlevel_pka_init(256);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(N, (uint32_t*)&valN, sizeof(valN));
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    res = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, (uint32_t *)&val1, sizeof(val1));

    cc3xx_lowlevel_pka_mod_exp(r0, r1, res);

    cc3xx_lowlevel_pka_read_reg(res, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(memcmp(readback, expected, sizeof(expected)) == 0, "readback not equal to expected");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;

}

void pka_test_endian_swap(struct test_result_t *ret)
{
    uint32_t r0;
    uint64_t val = 0x0102030405060708;
    uint8_t val_be[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    uint64_t readback = 0;

    cc3xx_lowlevel_pka_init(16);

    r0 = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg_swap_endian(r0, (uint32_t *)&val, sizeof(val));
    cc3xx_lowlevel_pka_read_reg(r0, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(memcmp(val_be, &readback, sizeof(val)) == 0, "endianness swap produced wrong result");

    cc3xx_lowlevel_pka_write_reg_swap_endian(r0, (uint32_t *)val_be, sizeof(val));
    cc3xx_lowlevel_pka_read_reg(r0, (uint32_t *)&readback, sizeof(readback));

    TEST_ASSERT(memcmp(&val, &readback, sizeof(val)) == 0, "swap back to original endianness produced wrong result");

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

void pka_test_cycle_counts(struct test_result_t *ret)
{
    cc3xx_pka_reg_id_t r0;
    cc3xx_pka_reg_id_t r1;
    cc3xx_pka_reg_id_t foo;
    uint32_t res;
    int32_t val0 = 32;
    int32_t val1 = 6;
    uint32_t imm = 4;
    uint32_t simm = 4;

    void (*unary_functions[])(cc3xx_pka_reg_id_t) = {
        cc3xx_lowlevel_pka_clear,
        cc3xx_lowlevel_pka_reduce,
    };

    char *unary_function_names[] = {
        "cc3xx_lowlevel_pka_clear",
        "cc3xx_lowlevel_pka_reduce",
    };

    void (*binary_functions[])(cc3xx_pka_reg_id_t, cc3xx_pka_reg_id_t) = {
        cc3xx_lowlevel_pka_neg,
        cc3xx_lowlevel_pka_mod_neg,
        cc3xx_lowlevel_pka_copy,
        cc3xx_lowlevel_pka_are_equal,
        cc3xx_lowlevel_pka_less_than,
        cc3xx_lowlevel_pka_greater_than,
        cc3xx_lowlevel_pka_mod_inv,
    };

    char *binary_function_names[] = {
        "cc3xx_lowlevel_pka_neg",
        "cc3xx_lowlevel_pka_mod_neg",
        "cc3xx_lowlevel_pka_copy",
        "cc3xx_lowlevel_pka_are_equal",
        "cc3xx_lowlevel_pka_less_than",
        "cc3xx_lowlevel_pka_greater_than",
        "cc3xx_lowlevel_pka_mod_inv",
    };

    void (*binary_uimm_functions[])(cc3xx_pka_reg_id_t, uint32_t) = {
        cc3xx_lowlevel_pka_set_to_power_of_two,
        cc3xx_lowlevel_pka_set_to_random,
    };

    char *binary_uimm_function_names[] = {
        "cc3xx_lowlevel_pka_set_to_power_of_two",
        "cc3xx_lowlevel_pka_set_to_random",
    };

    void (*binary_imm_functions[])(cc3xx_pka_reg_id_t, int32_t) = {
        cc3xx_lowlevel_pka_are_equal_si,
        cc3xx_lowlevel_pka_less_than_si,
        cc3xx_lowlevel_pka_greater_than_si,
        cc3xx_lowlevel_pka_test_bits_ui,
    };

    char *binary_imm_function_names[] = {
        "cc3xx_lowlevel_pka_are_equal_si",
        "cc3xx_lowlevel_pka_less_than_si",
        "cc3xx_lowlevel_pka_greater_than_si",
        "cc3xx_lowlevel_pka_test_bits_ui",
    };

    void (*trinary_functions[])(cc3xx_pka_reg_id_t, cc3xx_pka_reg_id_t, cc3xx_pka_reg_id_t) = {
        cc3xx_lowlevel_pka_add,
        cc3xx_lowlevel_pka_sub,
        cc3xx_lowlevel_pka_mod_add,
        cc3xx_lowlevel_pka_mod_sub,
        cc3xx_lowlevel_pka_and,
        cc3xx_lowlevel_pka_or,
        cc3xx_lowlevel_pka_xor,
        cc3xx_lowlevel_pka_mul_low_half,
        cc3xx_lowlevel_pka_mul_high_half,
        cc3xx_lowlevel_pka_mod_mul,
        cc3xx_lowlevel_pka_mod_exp,
    };

    char *trinary_function_names[] = {
        "cc3xx_lowlevel_pka_add",
        "cc3xx_lowlevel_pka_sub",
        "cc3xx_lowlevel_pka_mod_add",
        "cc3xx_lowlevel_pka_mod_sub",
        "cc3xx_lowlevel_pka_and",
        "cc3xx_lowlevel_pka_or",
        "cc3xx_lowlevel_pka_xor",
        "cc3xx_lowlevel_pka_mul_low_half",
        "cc3xx_lowlevel_pka_mul_high_half",
        "cc3xx_lowlevel_pka_mod_mul",
        "cc3xx_lowlevel_pka_mod_exp",
    };

    void (*trinary_imm_functions[])(cc3xx_pka_reg_id_t, int32_t, cc3xx_pka_reg_id_t) = {
        cc3xx_lowlevel_pka_add_si,
        cc3xx_lowlevel_pka_sub_si,
        cc3xx_lowlevel_pka_mod_add_si,
        cc3xx_lowlevel_pka_mod_sub_si,
        cc3xx_lowlevel_pka_mod_mul_si,
        cc3xx_lowlevel_pka_mod_exp_si,
    };

    char *trinary_imm_function_names[] = {
        "cc3xx_lowlevel_pka_add_si",
        "cc3xx_lowlevel_pka_sub_si",
        "cc3xx_lowlevel_pka_mod_add_si",
        "cc3xx_lowlevel_pka_mod_sub_si",
        "cc3xx_lowlevel_pka_mod_mul_si",
        "cc3xx_lowlevel_pka_mod_exp_si",
    };

    void (*trinary_uimm_functions[])(cc3xx_pka_reg_id_t, uint32_t, cc3xx_pka_reg_id_t) = {
        cc3xx_lowlevel_pka_and_si,
        cc3xx_lowlevel_pka_or_si,
        cc3xx_lowlevel_pka_xor_si,
        cc3xx_lowlevel_pka_clear_bit,
        cc3xx_lowlevel_pka_set_bit,
        cc3xx_lowlevel_pka_flip_bit,
        cc3xx_lowlevel_pka_shift_right_fill_0_ui,
        cc3xx_lowlevel_pka_shift_right_fill_1_ui,
        cc3xx_lowlevel_pka_shift_left_fill_0_ui,
        cc3xx_lowlevel_pka_shift_left_fill_1_ui,
    };

    char *trinary_uimm_function_names[] = {
        "cc3xx_lowlevel_pka_and_si",
        "cc3xx_lowlevel_pka_or_si",
        "cc3xx_lowlevel_pka_xor_si",
        "cc3xx_lowlevel_pka_clear_bit",
        "cc3xx_lowlevel_pka_set_bit",
        "cc3xx_lowlevel_pka_flip_bit",
        "cc3xx_lowlevel_pka_shift_right_fill_0_ui",
        "cc3xx_lowlevel_pka_shift_right_fill_1_ui",
        "cc3xx_lowlevel_pka_shift_left_fill_0_ui",
        "cc3xx_lowlevel_pka_shift_left_fill_1_ui",
    };

    void (*trinary_dual_uimm_functions[])(cc3xx_pka_reg_id_t, uint32_t, uint32_t) = {
        cc3xx_lowlevel_pka_test_bits_ui,
    };

    char *trinary_dual_uimm_function_names[] = {
        "cc3xx_lowlevel_pka_test_bits_ui",
    };

    cc3xx_lowlevel_pka_init(32);
    cc3xx_pka_reg_id_t N = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_set_to_power_of_two(N, 32 * 8);
    cc3xx_lowlevel_pka_set_modulus(N, true, 0);

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    r1 = cc3xx_lowlevel_pka_allocate_reg();
    foo = cc3xx_lowlevel_pka_allocate_reg();

    cc3xx_lowlevel_pka_write_reg(r0, &val0, sizeof(val0));
    cc3xx_lowlevel_pka_write_reg(r1, &val1, sizeof(val1));

    uint32_t cyccnt_start = 0;
    uint32_t cyccnt_end = 0;

    printf_set_color(MAGENTA);

    for (int I = 0; I < sizeof(unary_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        unary_functions[I](foo);
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", unary_function_names[I],
                                    cyccnt_end - cyccnt_start);
    }

    for (int I = 0; I < sizeof(binary_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        binary_functions[I](r0, foo);
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", binary_function_names[I],
                                    cyccnt_end - cyccnt_start);
    }

    for (int I = 0; I < sizeof(binary_uimm_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        binary_uimm_functions[I](foo, imm);
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", binary_uimm_function_names[I],
                                    cyccnt_end - cyccnt_start);
    }

    for (int I = 0; I < sizeof(binary_imm_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        binary_imm_functions[I](foo, simm);
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", binary_imm_function_names[I],
                                    cyccnt_end - cyccnt_start);
    }

    for (int I = 0; I < sizeof(trinary_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        trinary_functions[I](r0, r1, foo);
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", trinary_function_names[I],
                                    cyccnt_end - cyccnt_start);
    }

    for (int I = 0; I < sizeof(trinary_imm_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        trinary_uimm_functions[I](r0, simm, foo);
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", trinary_uimm_function_names[I],
                                    cyccnt_end - cyccnt_start);
    }

    for (int I = 0; I < sizeof(trinary_imm_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        trinary_uimm_functions[I](r0, simm, foo);
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", trinary_uimm_function_names[I],
                                    cyccnt_end - cyccnt_start);
    }

    for (int I = 0; I < sizeof(trinary_dual_uimm_functions) / 4; I++) {
        cyccnt_start = get_cycle_count();
        for (int J = 0; J < 100; J++) {
            trinary_dual_uimm_functions[I](r0, imm, imm);
            while(!P_CC3XX->pka.pka_done){}
        }
        cyccnt_end = get_cycle_count();
        TEST_LOG("%s: %d cycles\r\n", trinary_dual_uimm_function_names[I],
                                    (cyccnt_end - cyccnt_start) / 100);
    }

    printf_set_color(DEFAULT);

    ret->val = TEST_PASSED;
    return;
}

void pka_test_test_bits_ui(struct test_result_t *ret)
{
    uint32_t r0;
    uint32_t val0[] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, };
    uint32_t readback;
    uint32_t expected;

    cc3xx_lowlevel_pka_init(sizeof(val0));

    r0 = cc3xx_lowlevel_pka_allocate_reg();
    cc3xx_lowlevel_pka_write_reg(r0, (uint32_t *)&val0, sizeof(val0));

    for (int idx = 0; idx < sizeof(val0) * 8; idx += 2) {
        readback = cc3xx_lowlevel_pka_test_bits_ui(r0, idx, 2);

        expected = 0x3;
        TEST_ASSERT(readback == expected, "");
    }

    ret->val = TEST_PASSED;
cleanup:
    cc3xx_lowlevel_pka_uninit();

    return;
}

static struct test_t pka_tests[] = {
    {
        &pka_test_write_read,
        "CC3XX_PKA_TEST_WRITE_READ",
        "CC3XX PKA write then read test",
    },
    {
        &pka_test_write_partial_read,
        "CC3XX_PKA_TEST_WRITE_PARTIAL_READ",
        "CC3XX PKA write then partial read test",
    },
    {
        &pka_test_add,
        "CC3XX_PKA_TEST_ADD",
        "CC3XX PKA addition test",
    },
    {
        &pka_test_add_unaligned,
        "CC3XX_PKA_TEST_ADD_UNALIGNED",
        "CC3XX PKA addition test unaligned",
    },
    {
        &pka_test_add_unaligned_be,
        "CC3XX_PKA_TEST_ADD_UNALIGNED_BE",
        "CC3XX PKA addition test unaligned Big Endian",
    },
    {
        &pka_test_sub,
        "CC3XX_PKA_TEST_SUB",
        "CC3XX PKA subtraction test",
    },
    {
        &pka_test_add_si,
        "CC3XX_PKA_TEST_ADD_SI",
        "CC3XX PKA addition (signed immediate) test",
    },
    {
        &pka_test_add_si_neg,
        "CC3XX_PKA_TEST_ADD_SI_NEG",
        "CC3XX PKA addition (signed negative immediate) test",
    },
    {
        &pka_test_sub_si,
        "CC3XX_PKA_TEST_SUB_SI",
        "CC3XX PKA subtraction (signed immediate) test",
    },
    {
        &pka_test_sub_si_neg,
        "CC3XX_PKA_TEST_SUB_SI_NEG",
        "CC3XX PKA subtraction (signed negative immediate) test",
    },
    {
        &pka_test_neg,
        "CC3XX_PKA_TEST_NEG",
        "CC3XX PKA negation test",
    },
    {
        &pka_test_get_bitsize,
        "CC3XX_PKA_TEST_GET_BITSIZE",
        "CC3XX PKA bit-size calculation test",
    },
    {
        &pka_test_mod_add,
        "CC3XX_PKA_TEST_MOD_ADD",
        "CC3XX PKA modular addition test",
    },
    {
        &pka_test_mod_sub,
        "CC3XX_PKA_TEST_MOD_SUB",
        "CC3XX PKA modular_subtraction test",
    },
    {
        &pka_test_mod_add_si,
        "CC3XX_PKA_TEST_MOD_ADD_SI",
        "CC3XX PKA modular_addition (signed immediate) test",
    },
    {
        &pka_test_mod_sub_si,
        "CC3XX_PKA_TEST_MOD_SUB_SI",
        "CC3XX PKA modular subtraction (signed immediate) test",
    },
    {
        &pka_test_mod_neg,
        "CC3XX_PKA_TEST_MOD_NEG",
        "CC3XX PKA modular negation test",
    },
    {
        &pka_test_shift_left,
        "CC3XX_PKA_TEST_SHIFT_LEFT",
        "CC3XX PKA left shift test",
    },
    {
        &pka_test_shift_right,
        "CC3XX_PKA_TEST_SHIFT_RIGHT",
        "CC3XX PKA right shift test",
    },
    {
        &pka_test_div,
        "CC3XX_PKA_TEST_DIV",
        "CC3XX PKA division test",
    },
    {
        &pka_test_mod_mul,
        "CC3XX_PKA_TEST_MOD_MUL",
        "CC3XX PKA modular multiplication test",
    },
    {
        &pka_test_mod_exp,
        "CC3XX_PKA_TEST_MOD_EXP",
        "CC3XX PKA modular exponentiation test",
    },
    {
        &pka_test_mod_exp_si,
        "CC3XX_PKA_TEST_MOD_EXP_SI",
        "CC3XX PKA modular exponentiation (signed immediate) test",
    },
    {
        &pka_test_mod_inv,
        "CC3XX_PKA_TEST_MOD_INV",
        "CC3XX PKA modular inversion test",
    },
    {
        &pka_test_mod_inv_prime_modulus,
        "CC3XX_PKA_TEST_MOD_INV_PRIME",
        "CC3XX PKA modular inversion (prime modulus) test",
    },
    {
        &pka_test_test_bits_ui,
        "CC3XX_PKA_TEST_TEST_BITS_UI",
        "CC3XX PKA bit-test (unsigned immediate) test",
    },
    /* { */
    /*     &pka_test_virtual_registers, */
    /*     "CC3XX_PKA_TEST_VIRTUAL_REGISTERS", */
    /*     "CC3XX PKA virtual register test", */
    /* }, */
    {
        &pka_test_large_exponentiation,
        "CC3XX_PKA_TEST_LARGE_EXPONENTIATION",
        "CC3XX PKA large exponentiation test",
    },
    {
        &pka_test_endian_swap,
        "CC3XX_PKA_TEST_ENDIAN_SWAP",
        "CC3XX PKA endianness swap test",
    },
    {
        &pka_test_cycle_counts,
        "CC3XX_PKA_TEST_CYCLE_COUNTS",
        "CC3XX PKA operation cycle counts benchmark",
    },
};

void add_cc3xx_pka_tests_to_testsuite(struct test_suite_t *p_ts, uint32_t ts_size)
{
#if defined(CC3XX_CONFIG_CHACHA_POLY1305_ENABLE) \
 || defined(CC3XX_CONFIG_DRBG_CTR_ENABLE) \
 || defined(CC3XX_CONFIG_DRBG_HASH_ENABLE) \
 || defined(CC3XX_CONFIG_ECDSA_SIGN_ENABLE) \
 || defined(CC3XX_CONFIG_ECDSA_SIGN_ENABLE) \
 || defined(CC3XX_CONFIG_ECDSA_VERIFY_ENABLE) \
 || defined(CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE) \
 || defined(CC3XX_CONFIG_ECDH_ENABLE)
    enable_cycle_counter();
    cc3xx_add_tests_to_testsuite(pka_tests, ARRAY_SIZE(pka_tests), p_ts, ts_size);
#endif
}
