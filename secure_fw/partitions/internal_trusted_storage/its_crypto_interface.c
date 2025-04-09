/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>

#include "flash_fs/its_flash_fs.h"
#include "flash/its_flash.h"
#include "its_utils.h"
#include "psa_manifest/pid.h"
#include "tfm_hal_its_encryption.h"
#include "tfm_hal_ps.h"
#include "tfm_internal_trusted_storage.h"
#include "tfm_its_defs.h"

/**
 * \brief Fills the AEAD additional data used for the encryption/decryption
 *
 * \details The additional data is not encrypted but its integrity is checked.
 *          For the ITS encryption we use the file id, the file flags and the
 *          data size of the file as additional data.
 *
 * \param[out]  aad       Additional authenticated data
 * \param[in]   aad_size  Additional authenticated data size in bytes
 * \param[in]   fid       Identifier of the file
 * \param[in]   fid_size  Identifier of the file size in bytes
 * \param[in]   flags     Flags of the file
 * \param[in]   data_size Data size in bytes
 *
 * \retval PSA_SUCCESS                On success
 * \retval PSA_ERROR_INVALID_ARGUMENT When the additional data buffer does not
 *                                    have the correct size or the aad/fid
 *                                    buffers are NULL
 *
 */
static psa_status_t tfm_its_fill_enc_add(uint8_t *aad,
                                         const size_t aad_size,
                                         const uint8_t *fid,
                                         const size_t fid_size,
                                         const uint32_t flags,
                                         const size_t data_size)

{
    /* Only the user flags are populated in the function which
     * gets the file info from ITS (see its_flash_fs_file_get_info).
     * We use the same flags for conformity.
     */
    const uint32_t user_flags = flags & ITS_FLASH_FS_USER_FLAGS_MASK;

    /* The additional data consist of the file id, the flags and the
     * data size of the file.
     */
    const size_t aad_expected_size =
      ITS_FILE_ID_SIZE + sizeof(user_flags) + sizeof(data_size);

    if ((aad_size != aad_expected_size) || (aad == NULL) || (fid == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    memcpy(aad, fid, fid_size);
    memcpy(aad + fid_size, &user_flags, sizeof(user_flags));
    memcpy(aad + fid_size + sizeof(user_flags),
               &data_size,
               sizeof(data_size));

    return PSA_SUCCESS;
}

static psa_status_t tfm_hal_to_psa_error(enum tfm_hal_status_t tfm_hal_err)
{
    switch (tfm_hal_err) {
    case TFM_HAL_SUCCESS:
        return PSA_SUCCESS;
    case TFM_HAL_ERROR_INVALID_INPUT:
        return PSA_ERROR_INVALID_ARGUMENT;
    default:
        return PSA_ERROR_GENERIC_ERROR;
    }
}

psa_status_t tfm_its_crypt_file(struct its_flash_fs_file_info_t *finfo,
                                uint8_t *fid,
                                const size_t fid_size,
                                const uint8_t *input,
                                const size_t input_size,
                                uint8_t *output,
                                const size_t output_size,
                                const bool is_encrypt)
{
    struct tfm_hal_its_auth_crypt_ctx aead_ctx = {0};
    enum tfm_hal_status_t err;
    size_t file_size;

    if (finfo == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* The file size is not known yet when encrypting */
    if (is_encrypt) {
        file_size = input_size;
    } else {
        file_size = finfo->size_current;
    }

    err =  tfm_its_fill_enc_add(finfo->aad,
                                sizeof(finfo->aad),
                                fid,
                                fid_size,
                                finfo->flags,
                                file_size);
    if (err != TFM_HAL_SUCCESS) {
        return tfm_hal_to_psa_error(err);
    }

    if (is_encrypt) {
        err = tfm_hal_its_aead_generate_nonce(finfo->nonce,
                                              sizeof(finfo->nonce));

        if (err != TFM_HAL_SUCCESS) {
            return tfm_hal_to_psa_error(err);
        }
    }

    /* Set all required parameters for the aead operation context */
    aead_ctx.nonce = finfo->nonce;
    aead_ctx.nonce_size = sizeof(finfo->nonce);
    aead_ctx.deriv_label = fid;
    aead_ctx.deriv_label_size = fid_size;
    aead_ctx.aad = finfo->aad;
    aead_ctx.aad_size = sizeof(finfo->aad);


    if (is_encrypt) {
        err = tfm_hal_its_aead_encrypt(&aead_ctx,
                                       input,
                                       input_size,
                                       output,
                                       output_size,
                                       finfo->tag,
                                       sizeof(finfo->tag));
    } else {
        err = tfm_hal_its_aead_decrypt(&aead_ctx,
                                       input,
                                       input_size,
                                       finfo->tag,
                                       sizeof(finfo->tag),
                                       output,
                                       output_size);
    }

    if (err != TFM_HAL_SUCCESS) {
        return tfm_hal_to_psa_error(err);
    }

    if (is_encrypt) {
        finfo->size_max = input_size;
    }

    return PSA_SUCCESS;
}
