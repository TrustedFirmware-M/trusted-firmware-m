/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_BOOT_SELF_TESTS_H__
#define __RSE_BOOT_SELF_TESTS_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Return type for the function that runs the RSE boot
 *        self tests. Each bit conveys which of the self tests
 *        has failed.
 */
typedef uint32_t rse_boot_self_test_ret_t;

#define RSE_BOOT_SELF_TESTS_PASS_VALUE (0UL)

#define RSE_BOOT_SELF_TESTS_CHECK_OK(ret) ((ret) == RSE_BOOT_SELF_TESTS_PASS_VALUE)

typedef enum {
    RSE_BOOT_SELF_TESTS_RET_ECDSA = 0,
    RSE_BOOT_SELF_TESTS_RET_KDF_CMAC,
} rse_boot_self_test_t;

/**
 * @brief Sets the associated bit of the return value to \p val, i.e. meaning that the
 *        corresponding test has been failed if \p val is \a true
 *
 * @param[in] test Identifies which test we want to set the result for
 * @param[in] val  Value of the test that we want to set. Setting to \a true means test failed
 * @return rse_boot_self_test_ret_t
 */
static inline
rse_boot_self_test_ret_t rse_boot_self_tests_set_test(rse_boot_self_test_t test, bool val)
{
    return (val ? 1UL : 0UL) << test;
}

/**
 * @brief Tests the corresponding bit for the desired test to check if it has failed or not
 *
 * @param[in] test Identifies which test we want to check from the provided tests result
 * @param[in] ret  Value of the test results that we want to inspect
 * @return true    The corresponding test had failed
 * @return false   The corresponding test had passed
 */
static inline
bool rse_boot_self_tests_test_failed(rse_boot_self_test_t test, rse_boot_self_test_ret_t ret)
{
    return (ret & (1UL << test)) != 0UL;
}

/**
 * @brief A function that is meant to be run early in the boot process and
 *        will trigger a series of self tests
 *
 * @return rse_boot_self_test_ret_t A non-zero value indicated self tests failed
 */
rse_boot_self_test_ret_t rse_boot_do_boot_self_tests(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_BOOT_SELF_TESTS_H__ */
