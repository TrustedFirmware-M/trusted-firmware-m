/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file cc3xx_psa_key_agreement.c
 *
 * This file contains the implementation of the entry points associated to the
 * raw key agreement (i.e. ECDH) as described by the PSA Cryptoprocessor Driver
 * interface specification
 *
 */

#include <string.h>

#include "cc3xx_psa_key_agreement.h"
#include "cc3xx_misc.h"

#include "cc3xx_stdlib.h"
#include "cc3xx_ecdh.h"
#include "cc3xx_ec_curve_data.h"

/* ToDo: This needs to be sorted out at TF-M level
 * To be able to include the PSA style configuration
 */
#include "tf-psa-crypto/build_info.h"

/** @defgroup psa_key_agreement PSA driver entry points for raw key agreement
 *
 *  Entry points for raw key agreement as described by the PSA Cryptoprocessor
 *  Driver interface specification
 *
 *  @{
 */
psa_status_t cc3xx_key_agreement(
        const psa_key_attributes_t *attributes,
        const uint8_t *priv_key, size_t priv_key_size,
        const uint8_t *publ_key, size_t publ_key_size,
        uint8_t *output, size_t output_size, size_t *output_length,
        psa_algorithm_t alg)
{
    CC3XX_ASSERT(attributes != NULL);
    CC3XX_ASSERT(priv_key != NULL);
    CC3XX_ASSERT(publ_key != NULL);
    CC3XX_ASSERT(output != NULL);
    CC3XX_ASSERT(output_length != NULL);

    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Initialize output_length */
    *output_length = 0;

    switch (alg) {
#if defined(PSA_WANT_ALG_ECDH)
    case PSA_ALG_ECDH:
    {
        cc3xx_err_t err;
        psa_key_type_t key_type = psa_get_key_type(attributes);
        psa_key_bits_t key_bits = psa_get_key_bits(attributes);
        /* Translate from PSA curve ID to CC3XX curve ID*/
        const cc3xx_ec_curve_id_t curve_id =
            cc3xx_to_curve_id(PSA_KEY_TYPE_ECC_GET_FAMILY(key_type), key_bits);

        if (CC3XX_IS_CURVE_ID_INVALID(curve_id)) {
            return PSA_ERROR_NOT_SUPPORTED;
        }

        const size_t modulus_sz = cc3xx_lowlevel_ec_get_modulus_size_from_curve(curve_id);

        /* Scratch aligned to 32 bits and big enough for the worst case scenario */
        uint32_t shared_secret_local[modulus_sz / sizeof(uint32_t)];
        size_t shared_secret_sz;
        uint32_t priv_key_local[
            CEIL_ALLOC_SZ(PSA_KEY_EXPORT_ECC_KEY_PAIR_MAX_SIZE(key_bits), sizeof(uint32_t))];
        uint32_t pub_key_x_local[modulus_sz / sizeof(uint32_t)];
        uint32_t pub_key_y_local[modulus_sz / sizeof(uint32_t)];
        const size_t pub_key_x_sz = (publ_key_size - 1) / 2;
        const size_t pub_key_y_sz = (publ_key_size - 1) / 2;

        assert(publ_key[0] == 0x04);
        memcpy(pub_key_x_local, &publ_key[1], pub_key_x_sz);
        memcpy(pub_key_y_local, &publ_key[1 + pub_key_x_sz], pub_key_y_sz);

        cc3xx_dpa_hardened_word_copy(
            priv_key_local,
            (const uint32_t *)priv_key,
            sizeof(priv_key_local) / sizeof(uint32_t));

        err = cc3xx_lowlevel_ecdh(curve_id, priv_key_local, priv_key_size,
                    pub_key_x_local, pub_key_x_sz,
                    pub_key_y_local, pub_key_y_sz,
                    shared_secret_local, sizeof(shared_secret_local), &shared_secret_sz);

        cc3xx_secure_erase_buffer(priv_key_local, sizeof(priv_key_local) / sizeof(uint32_t));

        if (err != CC3XX_ERR_SUCCESS) {
            return cc3xx_to_psa_err(err);
        }

        if (output_size < shared_secret_sz) {
            status = PSA_ERROR_BUFFER_TOO_SMALL;
        } else {
            cc3xx_dpa_hardened_word_copy(
                (uint32_t *)output, shared_secret_local, shared_secret_sz / sizeof(uint32_t));
            *output_length = shared_secret_sz;
            status = PSA_SUCCESS;
        }

        cc3xx_secure_erase_buffer(shared_secret_local, shared_secret_sz / sizeof(uint32_t));

        return status;
    }
#endif /* PSA_WANT_ALG_ECDH */
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }

    return status;
}
/** @} */ // end of psa_key_agreement
