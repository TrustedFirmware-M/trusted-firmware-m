/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_tests.h"

#include "cc3xx_test_hash.h"
#include "cc3xx_test_aes.h"
#include "cc3xx_test_chacha.h"
#include "cc3xx_test_pka.h"
#include "cc3xx_test_ecc.h"
#include "cc3xx_test_ecdsa.h"
#include "cc3xx_test_dpa.h"
#include "cc3xx_test_rng.h"

void add_cc3xx_tests_to_testsuite(struct test_suite_t *p_ts, uint32_t ts_size)
{
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_HASH)
    add_cc3xx_hash_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_AES)
    add_cc3xx_aes_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_CHACHA)
    add_cc3xx_chacha_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_PKA)
    add_cc3xx_pka_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_ECC)
    add_cc3xx_ecc_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_ECDSA)
    add_cc3xx_ecdsa_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_DRBG)
    add_cc3xx_drbg_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_DPA)
    add_cc3xx_dpa_tests_to_testsuite(p_ts, ts_size);
#endif
#if defined(TEST_CC3XX) && defined(TEST_CC3XX_RNG)
    add_cc3xx_rng_tests_to_testsuite(p_ts, ts_size);
#endif
}
