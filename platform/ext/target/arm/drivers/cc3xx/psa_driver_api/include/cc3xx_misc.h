/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file cc3xx_misc.h
 *
 * Contains the definition of the macro for CC3XX_ASSERT(), and the
 * conversion function for error translation. The macro can be configured
 * at build time to behave differently, i.e. asserting, returning an error
 * code, or act transparently.
 */

#ifndef __CC3XX_MISC_H__
#define __CC3XX_MISC_H__

#include <assert.h>
#include "psa/crypto.h"
#include "cc3xx_psa_api_config.h"
#include "cc3xx_error.h"
#include "cc3xx_ec.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Macro to determine the size to allocate \a a bytes to contain an integer
 *        number of \a b sized chunks of memory
 */
#define CEIL_ALLOC_SZ(a,b) (((a) + (b) - 1) / (b))

#if defined(CC3XX_CONFIG_ASSERT_ENABLE)

#define CC3XX_ASSERT(x) \
    do {                                         \
        assert(x);                               \
        if (!(x)) {                              \
            return PSA_ERROR_INVALID_ARGUMENT;   \
        }                                        \
    } while(0)                                   \

#elif defined(CC3XX_CONFIG_ASSERT_CHECK)

#define CC3XX_ASSERT(x)                          \
    do {                                         \
        if (!(x)) {                              \
            return PSA_ERROR_INVALID_ARGUMENT;   \
        }                                        \
    } while(0)                                   \

#elif defined(CC3XX_CONFIG_ASSERT_DISABLE)

#define CC3XX_ASSERT(x) (void)(0)

#else

#error "CC3XX_CONFIG_ASSERT is not configured!"

#endif /* CC3XX_CONFIG_ASSERT_ */

/**
 * @brief Convert from CC3XX specific error codes to generic PSA error codes
 *
 * @param[in] err An error code as specified by the CC3XX lowlevel hardware
 *
 * @return psa_status_t A corresponding PSA error status
 */
psa_status_t cc3xx_to_psa_err(enum cc3xx_error err);

/**
 * @brief Maps a psa_ecc_family_t, psa_key_bits_t pair to a cc3xx_curve_id_t enum,
 *        i.e. PSA to CC3XX EC curve id translation
 *
 * @note  This might need some rework when support for Curve25519 is added
 *
 * @param[in] psa_ecc_family Family of ECC curves as specified by the PSA spec
 * @param[in] key_bits       Size in bits retrieved from the property of the key_type
 *
 * @return cc3xx_curve_id_t Curve ID as specified in cc3xx_ec.h for CC3XX low level driver
 */
cc3xx_ec_curve_id_t cc3xx_to_curve_id(psa_ecc_family_t psa_ecc_family, psa_key_bits_t key_bits);

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_MISC_H__ */
