/*
 * Copyright (c) 2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** \file cc3xx_misc.c
 *
 * This file contains the implementation of the error translation function from CC
 * to PSA status codes
 */

#include "cc3xx_misc.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

/* Check lowlevel config defines to see if a curve translation function is required */
#if defined(CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE) || \
    defined(CC3XX_CONFIG_ECDSA_VERIFY_ENABLE) || \
    defined(CC3XX_CONFIG_ECDSA_SIGN_ENABLE) || \
    defined(CC3XX_CONFIG_ECDH_ENABLE)

cc3xx_ec_curve_id_t cc3xx_to_curve_id(psa_ecc_family_t psa_ecc_family, psa_key_bits_t key_bits)
{
    /* ToDo: These curves can't be requested yet through the PSA API
     *
     *   CC3XX_EC_CURVE_FRP_256_V1,
     *
     *   CC3XX_EC_CURVE_25519,
     *   CC3XX_EC_CURVE_448,
     *
     *   CC3XX_EC_CURVE_ED25519,
     *   CC3XX_EC_CURVE_ED448,
     *
     */

    switch (psa_ecc_family) {
    case PSA_ECC_FAMILY_SECP_R1:
    {
        switch (key_bits) {
            case 192:
                return CC3XX_EC_CURVE_SECP_192_R1;
            case 224:
                return CC3XX_EC_CURVE_SECP_224_R1;
            case 256:
                return CC3XX_EC_CURVE_SECP_256_R1;
            case 384:
                return CC3XX_EC_CURVE_SECP_384_R1;
            case 521:
                return CC3XX_EC_CURVE_SECP_521_R1;
            default:
                return _CURVE_ID_MAX; /* Use the Maximum value as invalid */
        }
    }
    case PSA_ECC_FAMILY_SECP_K1:
    {
        switch (key_bits) {
            case 192:
                return CC3XX_EC_CURVE_SECP_192_K1;
            case 224:
                return CC3XX_EC_CURVE_SECP_224_K1;
            case 256:
                return CC3XX_EC_CURVE_SECP_256_K1;
            default:
                return _CURVE_ID_MAX; /* Use the Maximum value as invalid */
        }
    }
    case PSA_ECC_FAMILY_BRAINPOOL_P_R1:
    {
        switch (key_bits) {
            case 192:
                return CC3XX_EC_CURVE_BRAINPOOLP_192_R1;
            case 224:
                return CC3XX_EC_CURVE_BRAINPOOLP_224_R1;
            case 256:
                return CC3XX_EC_CURVE_BRAINPOOLP_256_R1;
            case 320:
                return CC3XX_EC_CURVE_BRAINPOOLP_320_R1;
            case 384:
                return CC3XX_EC_CURVE_BRAINPOOLP_384_R1;
            case 512:
                return CC3XX_EC_CURVE_BRAINPOOLP_512_R1;
            default:
                return _CURVE_ID_MAX; /* Use the Maximum value as invalid */
        }
    }
    default:
        return _CURVE_ID_MAX; /* Use the Maximum value as invalid */
    }
}
#endif /* ECDSA_KEYGEN_ENABLE || ECDSA_VERIFY_ENABLE || ECDSA_SIGN_ENABLE || ECDH_ENABLE */

psa_status_t cc3xx_to_psa_err(enum cc3xx_error err)
{
    switch (err) {
    case CC3XX_ERR_SUCCESS:
        return PSA_SUCCESS;
    case CC3XX_ERR_FAULT_DETECTED:
        return PSA_ERROR_CORRUPTION_DETECTED;
    case CC3XX_ERR_BUFFER_OVERFLOW:
        return PSA_ERROR_CORRUPTION_DETECTED;
    case CC3XX_ERR_INVALID_LCS:
        return PSA_ERROR_DATA_INVALID;
    case CC3XX_ERR_INVALID_DATA:
        return PSA_ERROR_DATA_INVALID;
    case CC3XX_ERR_INVALID_STATE:
        return PSA_ERROR_BAD_STATE;
    case CC3XX_ERR_NOT_IMPLEMENTED:
        return PSA_ERROR_NOT_SUPPORTED;
    case CC3XX_ERR_ENGINE_IN_USE:
        return PSA_ERROR_GENERIC_ERROR;
    case CC3XX_ERR_KEY_IMPORT_FAILED:
        return PSA_ERROR_NOT_PERMITTED;
    case CC3XX_ERR_INVALID_REMAP_REGION:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_BUS_ERROR:
        return PSA_ERROR_COMMUNICATION_FAILURE;
    case CC3XX_ERR_RNG_INVALID_RNG:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_RNG_TOO_MANY_ATTEMPTS:
        return PSA_ERROR_GENERIC_ERROR;
    case CC3XX_ERR_VERIFY_FAILED:
        return PSA_ERROR_INVALID_SIGNATURE;
    case CC3XX_ERR_INVALID_TAG:
        return PSA_ERROR_INVALID_SIGNATURE;
    case CC3XX_ERR_DMA_OUTPUT_BUFFER_TOO_SMALL:
        return PSA_ERROR_BUFFER_TOO_SMALL;
    case CC3XX_ERR_INVALID_INPUT_LENGTH:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_INVALID_IV_LENGTH:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_GCM_VARIABLE_IV_NOT_IMPLEMENTED:
        return PSA_ERROR_NOT_SUPPORTED;
    case CC3XX_ERR_CHACHA_IV_SIZE_INCORRECT:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_DFA_VIOLATION:
        return PSA_ERROR_CORRUPTION_DETECTED;
    case CC3XX_ERR_EC_CURVE_NOT_SUPPORTED:
        return PSA_ERROR_NOT_SUPPORTED;
    case CC3XX_ERR_EC_POINT_OUTSIDE_FIELD:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_EC_POINT_IS_INFINITY:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_ECDSA_SIGNATURE_INVALID:
        return PSA_ERROR_INVALID_SIGNATURE;
    case CC3XX_ERR_ECDSA_INVALID_HASH:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_ECDSA_INVALID_KEY:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_DRBG_RESEED_REQUIRED:
        return PSA_ERROR_BAD_STATE;
    case CC3XX_ERR_DRBG_INVALID_ID:
        return PSA_ERROR_INVALID_ARGUMENT;
    case CC3XX_ERR_DCU_LOCKED:
        return PSA_ERROR_NOT_PERMITTED;
    case CC3XX_ERR_DCU_MASK_MISMATCH:
        return PSA_ERROR_NOT_PERMITTED;
    default:
        return PSA_ERROR_HARDWARE_FAILURE;
    }
}
