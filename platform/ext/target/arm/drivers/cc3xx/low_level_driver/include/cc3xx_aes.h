/*
 * Copyright (c) 2021-2023, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_AES_H
#define CC3XX_AES_H

#include "cc3xx_error.h"
#include "cc3xx_config.h"
#include "cc3xx_dma.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AES_IV_LEN 16
#define AES_CTR_LEN 16
#define AES_GCM_FIELD_POINT_SIZE 16
#define AES_TAG_MAX_LEN 16

#define AES_BLOCK_SIZE 16
#define AES_MAX_KEY_LEN 32

typedef enum {
    CC3XX_AES_DIRECTION_ENCRYPT = 0b0U,
    CC3XX_AES_DIRECTION_DECRYPT = 0b1U,

    _CC3XX_AES_DIRECTION_PAD    = UINT32_MAX
} cc3xx_aes_direction_t;

typedef enum {
    CC3XX_AES_MODE_ECB      = 0b0000U,
    CC3XX_AES_MODE_CBC      = 0b0001U,
    CC3XX_AES_MODE_CTR      = 0b0010U,
    CC3XX_AES_MODE_GCM      = 0b1010U,
    CC3XX_AES_MODE_CMAC     = 0b0111U,
    CC3XX_AES_MODE_CCM      = 0b1011U,

    _CC3XX_AES_MODE_PAD     = UINT32_MAX
} cc3xx_aes_mode_t;

typedef enum {
    CC3XX_AES_KEYSIZE_128  = 0b00U,
    CC3XX_AES_KEYSIZE_192  = 0b01U,
    CC3XX_AES_KEYSIZE_256  = 0b10U,

    CC3XX_AES_KEYSIZE_INVALID = UINT32_MAX
} cc3xx_aes_keysize_t;

typedef enum {
    CC3XX_AES_KEY_ID_HUK      = 0x0U,  /*!< Hardware unique key. Also referred to as RKEK */
    CC3XX_AES_KEY_ID_KRTL     = 0x1U,  /*!< RTL Key */
    CC3XX_AES_KEY_ID_KCP      = 0x2U,  /*!< DM provisioning key */
    CC3XX_AES_KEY_ID_KCE      = 0x3U,  /*!< DM code encryption key */
    CC3XX_AES_KEY_ID_KPICV    = 0x4U,  /*!< CM provisioning key */
    CC3XX_AES_KEY_ID_KCEICV   = 0x5U,  /*!< CM code encryption key */
    CC3XX_AES_KEY_ID_GUK      = 0xFU,  /*!< Group unique key. See CCA spec for information */
    CC3XX_AES_KEY_ID_USER_KEY = 0xFFU, /*!< Key input into registers manually */

    _CC3XX_AES_KEY_ID_PAD     = UINT32_MAX
} cc3xx_aes_key_id_t;

/* Note that parts of the AES state that can be reconstructed without the data
 * input by the _update functions is not kept at this layer, and must be
 * preserved by the restartable layer.
 */
struct cc3xx_aes_state_t {
    cc3xx_aes_mode_t mode;
    cc3xx_aes_direction_t direction;

    uint32_t iv[AES_IV_LEN / sizeof(uint32_t)];
#if defined(CC3XX_CONFIG_AES_CCM_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE)
    uint32_t tun1_iv[AES_IV_LEN / sizeof(uint32_t)];
#endif /* defined(CC3XX_CONFIG_AES_CCM_ENABLE) && defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE) */
    uint32_t ctr[AES_CTR_LEN / sizeof(uint32_t)];

    size_t crypted_length;
    size_t authed_length;
#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    size_t aes_to_crypt_len;
    size_t aes_to_auth_len;
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */

#ifdef CC3XX_CONFIG_AES_GCM_ENABLE
    uint32_t gcm_field_point[AES_GCM_FIELD_POINT_SIZE / sizeof(uint32_t)];
    uint32_t ghash_key[AES_GCM_FIELD_POINT_SIZE / sizeof(uint32_t)];
#endif /* CC3XX_CONFIG_AES_GCM_ENABLE */
#if defined(CC3XX_CONFIG_AES_GCM_ENABLE) || defined(CC3XX_CONFIG_AES_CCM_ENABLE)
    uint32_t counter_0[AES_CTR_LEN / sizeof(uint32_t)];
#endif /* defined(CC3XX_CONFIG_AES_GCM_ENABLE) || defined(CC3XX_CONFIG_AES_CCM_ENABLE) */

#ifdef CC3XX_CONFIG_AES_CCM_ENABLE
    uint32_t ccm_initial_iv_buf[AES_CTR_LEN / sizeof(uint32_t)];
    size_t ccm_initial_iv_size;
#endif /* CC3XX_CONFIG_AES_CCM_ENABLE */

#if defined(CC3XX_CONFIG_AES_CCM_ENABLE) \
    || defined (CC3XX_CONFIG_AES_GCM_ENABLE) \
    || defined (CC3XX_CONFIG_AES_CMAC_ENABLE)
    size_t aes_tag_len;
#endif

    cc3xx_aes_key_id_t key_id;
    cc3xx_aes_keysize_t key_size;

    struct cc3xx_dma_state_t dma_state;

    bool state_contains_key;
    /* The key buf goes at the end, so that we can copy it in a DPA-resistant
     * manner.
     */
    uint32_t key_buf[AES_MAX_KEY_LEN / sizeof(uint32_t)];
};

/**
 * @brief                        Helper function that validates the length of the
 *                               IV given the mode in which the AES engine is being
 *                               configured
 *
 * @param[in] mode               Mode in which the AES engine would be configured
 * @param[in] iv_len             Length of the IV that would be configured on the AES engine
 * @return cc3xx_err_t           CC3XX_ERR_SUCCESS if the \p iv_len is valid for the
 *                               \p mode selected for AES
 *                               CC3XX_ERR_INVALID_IV_LENGTH if the mode is recognised
 *                               by the implementation but the length is not compatible
 *                               CC3XX_ERR_NOT_IMPLEMENTED if the mode is not supported
 */
cc3xx_err_t cc3xx_lowlevel_aes_valid_iv_length(
    cc3xx_aes_mode_t mode,
    size_t iv_len);

/**
 * @brief                        Initialize an AES operation.

 * @param[in]  direction         Whether the operation should encrypt or decrypt.
 * @param[in]  mode              Which AES mode should be used.
 * @param[in]  key_id            Which user/hardware key should be used.
 * @param[in]  key               If key_id is set to CC3XX_AES_KEY_ID_USER_KEY,
 *                               this buffer contains the key material.
 * @param[in]  key_size          The size of the key being used.
 * @param[in]  iv                The initial IV/CTR value for the mode. For modes
 *                               without an IV/CTR, this may be NULL.
 * @param[in]  iv_len            The size of the IV input.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_aes_init(
    cc3xx_aes_direction_t direction,
    cc3xx_aes_mode_t mode, cc3xx_aes_key_id_t key_id,
    const uint32_t *key, cc3xx_aes_keysize_t key_size,
    const uint32_t *iv, size_t iv_len);

/**
 * @brief                        Get the current state of the AES operation.
 *                               Allows for restartable AES operations.

 * @param[out] state            The cc3xx_aes_state_t to write the state into.
 */
void cc3xx_lowlevel_aes_get_state(struct cc3xx_aes_state_t *state);
/**
 * @brief                        Set the current state of the AES operation.
 *                               Allows for restartable AES operations.
 *
 * @note                         This function initializes the hardware, there is
 *                               no need to separately call cc3xx_aes_init.

 * @param[in]  state            The cc3xx_aes_state_t to read the state from.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_aes_set_state(const struct cc3xx_aes_state_t *state);

/**
 * @brief                        Set the length of the tag produced or verified
 *                               by AEAD/MAC modes.
 *
 * @note                         This function is a no-op in non-AEAD/MAC modes.
 *
 * @param[in]  tag_len           The length of the tag.
 */
void cc3xx_lowlevel_aes_set_tag_len(uint32_t tag_len);

/**
 * @brief                        Set the length of the data that will be input.
 *
 * @note                         This function is a no-op in all but CCM mode.
 *
 * @param[in]  to_crypt_len      How many bytes of data will be encrypted.
 * @param[in]  to_auth_len       How many bytes of data will be authenticated,
 *                               but not encrypted.
 */
void cc3xx_lowlevel_aes_set_data_len(uint32_t to_crypt_len, uint32_t to_auth_len);

/**
 * @brief                        Get the amount of bytes that have been output
 *
 * @return                       Amount of bytes of output that has been written
 *                               (which it not necessarily the same amount of
 *                               input that has been submitted, due to DMA
 *                               buffering)
 */
size_t cc3xx_lowlevel_aes_get_current_output_size(void);

/**
 * @brief                        Set the buffer that the AES engine will output
 *                               into.
 *
 * @param[out] out               The buffer to output into.
 * @param[in]  out_len           The size of the buffer to output into. If this
 *                               is smaller than the size of the data passed to
 *                               cc3xx_aes_update, that function will fail with
 *                               an error.
 */
void cc3xx_lowlevel_aes_set_output_buffer(uint8_t *out, size_t out_len);

/**
 * @brief                        Input data to be encrypted/decrypted into an
 *                               AES operation.

 * @param[in]  in                A pointer to the data to be input.
 * @param[in]  in_len            The size of the data to be input.
 */
cc3xx_err_t cc3xx_lowlevel_aes_update(const uint8_t* in, size_t in_len);

/**
 * @brief                        Input data to be authenticated, but not
 *                               encrypted or decrypted into an AEAD/MAC
 *                               operation.
 *
 * @note                         This function must not be called after
 *                               cc3xx_aes_update has been called, until a new
 *                               operation is started.

 * @param[in]  in                A pointer to the data to be input.
 * @param[in]  in_len            The size of the data to be input.
 *
 * @return                       CC3XX_ERR_SUCCESS on success, another
 *                               cc3xx_err_t on error.
 */
void cc3xx_lowlevel_aes_update_authed_data(const uint8_t* in, size_t in_len);

/**
 * @brief                        Finish an AES operation. Calling this will
 *                               encrypt/decrypt the final data.
 *
 * @param[in,out]  tag           The buffer to write the tag into or read and
 *                               compare the tag from, depending on direction.
 *                               The tag size will be 16 if not explicitly set,
 *                               and the buffer must be sized appropriately. Can
 *                               be NULL if using a non-AEAD/MAC mode.
 *
 * @param[out]     size          The size of the output that has been written.
 *
 * @return                       CC3XX_ERR_SUCCESS on success / tag comparison
 *                               succeeded, another cc3xx_err_t on error.
 */
cc3xx_err_t cc3xx_lowlevel_aes_finish(uint32_t *tag, size_t *size);

/**
 * @brief                       Uninitialize the AES engine.
 *
 * @note                        The AES engine is not implicitly uninitialized
 *                              on an error.
 *
 */
void cc3xx_lowlevel_aes_uninit(void);

#if !defined(CC3XX_CONFIG_AES_TUNNELLING_ENABLE) && defined(CC3XX_CONFIG_AES_CCM_ENABLE)
/**
 * @brief                         Initialize an AES-CCM counter block from the nonce.
 *                                This function sets up the AES-CCM initial counter
 *                                block (CTR) based on the provided nonce.
 *
 * @param[in,out] ctr             Pointer to the 16-byte counter block to initialize.
 * @param[in]     nonce           Pointer to the nonce to use for counter initialization.
 * @param[in]     nonce_size      Size of the nonce in bytes.
 *
 */
void c3xx_lowlevel_aes_ccm_init_ctr(uint8_t *ctr, const uint8_t *nonce, size_t nonce_size);

/**
 * @brief                         Increment the AES-CCM counter block by a specified
                                  amount. The counter field is stored in the least
                                  significant bytes of the block, in big-endian format.
 *
 * @param[in,out] ctr             Pointer to the 16-byte counter block.
 * @param[in]     incr_val        The amount to increment the counter by.
 *
 * @note                          The counter field is up to 8 bytes wide, located at the
 *                                end of the block. The increment is applied in big-endian
 *                                byte order and written back to the correct offset.
 */
void c3xx_lowlevel_aes_ccm_incr_ctr(uint8_t *ctr, const size_t incr_val);


#endif /* !CC3XX_CONFIG_AES_TUNNELLING_ENABLE && CC3XX_CONFIG_AES_CCM_ENABLE */


#ifdef __cplusplus
}
#endif

#endif /* CC3XX_AES_H */
