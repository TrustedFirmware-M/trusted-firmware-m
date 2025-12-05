/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_BL2_BINDING_H__
#define __RSE_BL2_BINDING_H__

#include <stdint.h>
#include <stdbool.h>
#include "psa/crypto.h"
#include "bootutil/image.h"
#include "fih.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 16-byte metadata and 16-byte tag TLVs */
#define RSE_TLV_BIND_META_TYPE   IMAGE_TLV_BIND_METADATA
#define RSE_TLV_BIND_TAG_TYPE    IMAGE_TLV_BIND_TAG
#define RSE_TLV_BIND_LEN         16

/*
 * First byte of meta represents that bind sate
 * possible values of meta[0]:
 * 0xFF → unset (no binding yet)
 * 0x7F → in progress
 * 0x01 → Bound
 */
#define RSE_META_BIND_STATE_OFFSET  0
#define RSE_BIND_STATE_UNSET        0xFF
#define RSE_BIND_STATE_IN_PROG      0x7F
#define RSE_BIND_STATE_BOUND        0x01

/* Second byte represents binding method used
 * possible values of meta[1]:
 * 0x01 → CMAC
 * 0x02 → CCM
 */
#define RSE_META_BIND_ALG_OFFSET  1
#define RSE_BIND_CMAC_BOUND   0x1
#define RSE_BIND_CCM_BOUND    0x2

/* Third byte reprsents iv length for CCM */
#define RSE_META_BIND_CCM_IV_LEN_OFFSET 2
#define RSE_BIND_CCM_IV_LEN             12 /* CCM L=3 → max payload len ~ 16MB */

/* Fourth byte represents tag length for CCM */
#define RSE_META_BIND_CCM_TAG_LEN_OFFSET 3
#define RSE_BIND_CCM_TAG_LEN             16

/* Byte 5 - 16 represents nonce / ctr_iv */
#define RSE_META_BIND_CCM_NONCE_OFFSET 4

struct rse_bind_ctx {
    bool    has_tag;                 /*!< TLVs present */
    bool    is_authenticated;        /*!< binding verified */
    uint8_t meta[RSE_TLV_BIND_LEN];  /*!< UNPROT TLV */
    uint8_t bind_state;              /*!< from meta[0] */
    uint8_t tag [RSE_TLV_BIND_LEN];  /*!< UNPROT TLV */
    uint32_t sec_cnt;                /*!< security_counter  */
    const uint8_t *body_base;        /*!< load address */
    size_t   body_len;               /*!< image size */
#ifdef MCUBOOT_ENC_IMAGES
    psa_aead_operation_t aead_op;    /*!< AEAD operation context */
    uint8_t  nonce[RSE_BIND_CCM_IV_LEN];  /*!< CCM nonce / ctr_iv */
#endif
};

/**
 * @brief Retrieves the CMAC key identifier for a specific image index.
 *
 * This function returns the PSA key ID associated with the CMAC (Cipher-based
 * Message Authentication Code) key that corresponds to the provided image index.
 * The key is used for image authentication during the boot process.
 *
 * @param[in] img_index  The index of the image for which to retrieve the CMAC key.
 *
 * @return psa_key_id_t  The PSA key identifier for the CMAC key associated with
 *                       the specified image index.
 */
psa_key_id_t rse_get_cmac_key_for_image(int img_index);

/**
 * @brief Reads binding data for a specified image from flash memory.
 *
 * This function retrieves binding data associated with a given image ID,
 * using the provided flash area and image header information.
 *
 * @param image_id   The identifier of the image whose binding data is to be read.
 * @param fa         Pointer to the flash_area structure representing the flash region.
 * @param hdr        Pointer to the image_header structure containing image metadata.
 *
 * @return           0 on success, or a negative error code on failure.
 */
int rse_read_binding_data(uint8_t image_id,
                          const struct flash_area *fa,
                          const struct image_header *hdr);

/**
 * @brief Performs the binding process for a specified image.
 *
 * This function handles the binding operation for a given image, identified by its image ID.
 * It utilizes the provided flash area and image header to complete the binding process.
 *
 * @param image_id   Identifier for the image to be bound.
 * @param fa         Pointer to the flash area structure associated with the image.
 * @param hdr        Pointer to the image header structure containing metadata about the image.
 * @return           Status code indicating the result of the binding operation.
 */
int rse_do_binding(uint8_t image_id,
                   const struct flash_area *fa,
                   const struct image_header *hdr);

/**
 * @brief Sets the RAM window for a specified image.
 *
 * This function configures the RAM window for the given image by specifying
 * the image identifier, the base address of the image body, and the length
 * of the image body in bytes.
 *
 * @param image_id   Identifier of the image to set the RAM window for.
 * @param body_base  Pointer to the base address of the image body in memory.
 * @param body_len   Length of the image body in bytes.
 */
void rse_bind_set_ram_window(uint8_t image_id,
                             const uint8_t *body_base, size_t body_len);

/**
 * @brief Verifies the binding of a given image.
 *
 * This function checks the integrity and authenticity of the specified image
 * by verifying its binding information using the provided image header.
 *
 * @param image_id   Identifier of the image to verify.
 * @param hdr        Pointer to the image header structure containing metadata.
 *
 * @return fih_ret   Returns a fault injection hardened result indicating
 *                   success or failure of the verification process.
 */
fih_ret rse_verify_binding(uint8_t image_id, const struct image_header *hdr);

/**
 * @brief Decrypts and authenticates an encrypted boot image in SRAM
 *
 * This function performs decryption and authentication of an encrypted boot image
 * that has been loaded into SRAM. It uses the provided image ID and header information
 * to locate and verify the image data.
 *
 * @param[in] image_id    The identifier of the boot image to decrypt and authenticate
 * @param[in] hdr         Pointer to the image header structure containing metadata
 *                        about the image (size, version, encryption parameters, etc.)
 *
 * @return fih_ret        Fault injection hardened return value indicating:
 *                        - Success if decryption and authentication complete successfully
 *                        - Error code if decryption fails, authentication fails, or
 *                          other errors occur during processing
 */
fih_ret boot_enc_decrypt_and_auth_in_sram(uint8_t img_index,
                                          const struct image_header *hdr);

/* Optional tiny getters if you want visibility without exposing the struct */
/**
 * @brief Checks if the specified image has an associated binding tag.
 *
 * This function determines whether a binding tag exists for the image
 * identified by the given image ID.
 *
 * @param image_id The identifier of the image to check for a binding tag.
 * @return fih_ret Returns a fault injection hardened result indicating
 *         whether the binding tag is present.
 */
fih_ret rse_bind_has_tag(uint8_t image_id);

/**
 * @brief Check if an image has been authenticated during binding
 *
 * \param[in] image_id  The image identifier to check
 *
 * \return Returns a fault injection hardened (FIH) return code indicating
 *         whether the image is authenticated or not
 */
fih_ret rse_bind_is_authenticated(uint8_t image_id);

/**
 * @brief Enforces rollback protection for a specified image.
 *
 * This function checks and enforces rollback protection for the image identified
 * by the given image_id. It ensures that only images with a version equal to or
 * greater than the currently stored version are allowed, preventing downgrades
 * to older, potentially vulnerable images.
 *
 * @param image_id The identifier of the image to check for rollback protection.
 * @return fih_ret Returns a fault injection hardened result indicating success or failure.
 */
fih_ret rse_enforce_rollback(uint8_t image_id);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_BL2_BINDING_H__ */
