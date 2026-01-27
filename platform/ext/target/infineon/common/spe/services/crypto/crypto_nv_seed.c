/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cy_device.h"
#if defined(CY_IP_MXCRYPTO)
#include "cy_crypto_core_trng.h"
#elif defined(CY_IP_MXCRYPTOLITE)
#include "cy_cryptolite_trng.h"
#endif
#include "tfm_plat_crypto_nv_seed.h"
#include <string.h>
#include "coverity_check.h"

TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Directive_4_6, "Writing functions as in ARM templates, so we keep numerical types")
int tfm_plat_crypto_provision_entropy_seed(void)
{
    /* This function is used in tfm_crypto_engine_init and should returns success value */
    return TFM_CRYPTO_NV_SEED_SUCCESS;
}

int tfm_plat_crypto_nv_seed_read(unsigned char *buf, size_t buf_len)
{
    (void)buf;
    (void)buf_len;

#if defined(CY_IP_MXCRYPTO)
    cy_en_crypto_status_t status;
    uint32_t random;

    /* Crypto core can be disabled without acceleration */
    bool is_crypto_enabled = Cy_Crypto_Core_IsEnabled(CRYPTO);
    if (!is_crypto_enabled) {
        status = Cy_Crypto_Core_Enable(CRYPTO);
        if (status != CY_CRYPTO_SUCCESS) {
            return TFM_CRYPTO_NV_SEED_FAILED;
        }
    }

    while (buf_len > 0U) {
        /* Use TRNG to generate a single random 32-bit number */
        status = Cy_Crypto_Core_Trng_Ext(CRYPTO, 32, &random);
        if (status != CY_CRYPTO_SUCCESS) {
            (void)Cy_Crypto_Core_Trng_DeInit(CRYPTO);
            if (!is_crypto_enabled) {
                (void)Cy_Crypto_Core_Disable(CRYPTO);
            }
            return TFM_CRYPTO_NV_SEED_FAILED;
        }

        size_t chunk_size = (buf_len > 4U) ? 4U : buf_len;
        (void)memcpy(buf, &random, chunk_size);
        buf_len -= chunk_size;
        buf += chunk_size;
    }

    /* We're done with the TRNG */
    (void)Cy_Crypto_Core_Trng_DeInit(CRYPTO);
    if (!is_crypto_enabled) {
        (void)Cy_Crypto_Core_Disable(CRYPTO);
    }
    return TFM_CRYPTO_NV_SEED_SUCCESS;
#elif defined(CY_IP_MXCRYPTOLITE)
    cy_en_cryptolite_status_t status;
    uint32_t random_u32;

    status = Cy_Cryptolite_Trng_Init(CRYPTOLITE, NULL);
    if (status != CY_CRYPTOLITE_SUCCESS)
    {
        return TFM_CRYPTO_NV_SEED_FAILED;
    }

    status = Cy_Cryptolite_Trng_Enable(CRYPTOLITE);
    if (status != CY_CRYPTOLITE_SUCCESS)
    {
        (void)Cy_Cryptolite_Trng_DeInit(CRYPTOLITE);
        return TFM_CRYPTO_NV_SEED_FAILED;
    }

    while (buf_len > 0u) {
        /* Use TRNG to generate a single random 32-bit number */
        status = Cy_Cryptolite_Trng_ReadData(CRYPTOLITE, &random_u32);
        if (status != CY_CRYPTOLITE_SUCCESS) {
            (void)Cy_Cryptolite_Trng_Disable(CRYPTOLITE);
            (void)Cy_Cryptolite_Trng_DeInit(CRYPTOLITE);
            return TFM_CRYPTO_NV_SEED_FAILED;
        }

        size_t chunk_size = (buf_len > 4u) ? 4u : buf_len;
        (void)memcpy(buf, &random_u32, chunk_size);
        buf_len -= chunk_size;
        buf += chunk_size;
    }

    (void)Cy_Cryptolite_Trng_Disable(CRYPTOLITE);
    (void)Cy_Cryptolite_Trng_DeInit(CRYPTOLITE);
    return TFM_CRYPTO_NV_SEED_SUCCESS;
#else
    return TFM_CRYPTO_NV_SEED_FAILED;
#endif
}

int tfm_plat_crypto_nv_seed_write(const unsigned char *buf, size_t buf_len)
{
    (void)buf;
    (void)buf_len;

    /* This function is used in mbedtls_entropy_update_nv_seed and should returns success value */
    return TFM_CRYPTO_NV_SEED_SUCCESS;
}
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Directive_4_6)
