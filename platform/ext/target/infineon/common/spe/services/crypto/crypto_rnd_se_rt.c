/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#if defined(MBEDTLS_PSA_CRYPTO_PLATFORM_FILE)
#include MBEDTLS_PSA_CRYPTO_PLATFORM_FILE
#else /* defined(MBEDTLS_PSA_CRYPTO_PLATFORM_FILE) */
#include "crypto_platform.h"
#endif /* defined(MBEDTLS_PSA_CRYPTO_PLATFORM_FILE) */
#include "ifx_se_psacrypto.h"
#include "ifx_utils.h"
#include "psa/crypto.h"
#include "mbedtls/platform.h"
#include <string.h>

#if defined(IFX_PSA_SE_DPA_PRESENT) && defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
psa_status_t mbedtls_psa_external_get_random(
    mbedtls_psa_external_random_context_t *context,
    uint8_t *output, size_t output_size, size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    *output_length = 0;
    IFX_UNUSED(context);

    if (output_size == 0U) {
        return PSA_SUCCESS;
    }

    uint8_t *random_buf = mbedtls_calloc(1, output_size + IFX_CRC32_CRC_SIZE);
    if (random_buf == NULL) {
        return PSA_ERROR_INSUFFICIENT_MEMORY;
    }

    /* Get Random bytes */
    status = ifx_se_get_psa_status( ifx_se_generate_random(
                ifx_se_fih_ptr_encode(random_buf),
                ifx_se_fih_uint_encode(output_size + IFX_CRC32_CRC_SIZE),
                IFX_SE_NULL_CTX) );

    if (status == PSA_SUCCESS) {
        uint32_t crc;
        status = PSA_ERROR_CORRUPTION_DETECTED;

        memcpy((uint8_t*)&crc, random_buf + output_size, IFX_CRC32_CRC_SIZE);
        if (crc == IFX_CRC32_CALC(random_buf, output_size)) {
            memcpy(output, random_buf, output_size);
            *output_length = output_size;
            status = PSA_SUCCESS;
        }
    }

    mbedtls_free(random_buf);

    return status;
}
#endif /* IFX_PSA_SE_DPA_PRESENT && MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */
