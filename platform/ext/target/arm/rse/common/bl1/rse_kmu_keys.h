/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_KMU_KEYS_H__
#define __RSE_KMU_KEYS_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "tfm_plat_defs.h"
#include "rse_kmu_slot_ids.h"
#include "kmu_drv.h"
#include "rse_boot_state.h"
#include "tfm_plat_otp.h"

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_plat_err_t setup_key_from_derivation(enum kmu_hardware_keyslot_t input_key_id,
                                              uint32_t *key_buf,
                                              const uint8_t *label, size_t label_len,
                                              const uint8_t *context, size_t context_len,
                                              enum rse_kmu_slot_id_t slot,
                                              const struct kmu_key_export_config_t *export_config,
                                              const struct kmu_key_export_config_t *aead_export_config,
                                              bool setup_aes_aead_key, boot_state_include_mask mask);

enum tfm_plat_err_t setup_key_from_otp(enum rse_kmu_slot_id_t slot,
                                       enum tfm_otp_element_id_t otp_id,
                                       const struct kmu_key_export_config_t *export_config,
                                       const struct kmu_key_export_config_t *aead_export_config,
                                       bool setup_aes_aead_key);

enum tfm_plat_err_t setup_key_from_rng(enum rse_kmu_slot_id_t slot,
                                       const struct kmu_key_export_config_t *export_config,
                                       const struct kmu_key_export_config_t *aead_export_config,
                                       bool setup_aes_aead_key);

/**
 * \brief                     Derive a VHUK seed.
 *
 * \param[out] vhuk_seed         The buffer to derive the seed into.
 * \param[in]  vhuk_seed_buf_len The size of the seed buffer.
 * \param[out] vhuk_seed_size    The size of the seed.
 *
 * \return                       TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_derive_vhuk_seed(uint32_t *vhuk_seed, size_t vhuk_seed_buf_len,
                                         size_t *vhuk_seed_size);

/**
 * \brief                     setup the IAK seed, and lock in a KMU slot.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_iak_seed(void);

/**
 * \brief                     setup the DAK seed, and lock in a KMU slot.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_dak_seed(void);

/**
 * \brief                     setup the RoT CDI, and lock in a KMU slot.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_rot_cdi(void);

/**
 * \brief                     setup the VHUK, and lock in a KMU slot.
 *
 * \param[in]  vhuk_seeds     A buffer containing the seed values.
 * \param[in]  vhuk_seeds_len The size of the vhuk_seeds buffer. This must be
 *                            RSE_AMOUNT * 32 in size.
 * \param[in]  slot           The KMU slot to setup and lock the seed into.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_vhuk(const uint8_t *vhuk_seeds, size_t vhuk_seeds_len);

/**
 * \brief                     setup the session key, and lock into two KMU
 *                            slots.
 *
 * \note                      Due to a limitation in KMU key export, keys used
 *                            for AEAD (such as this one) require two slots. The
 *                            slots used will be `slot` and `slot + 1`. It is
 *                            invalid for `slot` to be `KMU_USER_SLOT_MAX`
 *
 * \param[in]  seed           A buffer containing the seed values.
 * \param[in]  seed_len       The size of the seed buffer. This must be
 *                            32 in size.
 * \param[in]  slot           The KMU slot to setup and lock the seed into.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_session_key(const uint8_t *seed, size_t seed_len);

/**
 * \brief                     Setup the master key, and lock into two KMU slots.
 *
 * \note                      Due to a limitation in KMU key export, keys used
 *                            for AEAD (such as this one) require two slots. The
 *                            slots used will be `slot` and `slot + 1`. It is
 *                            invalid for `slot` to be `KMU_USER_SLOT_MAX`
 *
 * \param[in]  slot           The KMU slot to setup and lock the seed into.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_master_key(const uint8_t *label, size_t label_len,
                                         const uint8_t *context, size_t context_len);

/**
 * \brief                     Setup the provisioning key, and lock into two
 *                            KMU slots.
 *
 * \note                      Due to a limitation in KMU key export, keys used
 *                            for AEAD (such as this one) require two slots. The
 *                            slots used will be `slot` and `slot + 1`. It is
 *                            invalid for `slot` to be `KMU_USER_SLOT_MAX`
 *
 * \param[in]  slot           The KMU slot to setup and lock the seed into.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_provisioning_key(const uint8_t *label, size_t label_len,
                                               const uint8_t *context, size_t context_len);

/**
 * \brief                     Setup the runtime secure image decryption key, and
 *                            lock in a KMU slot.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_runtime_secure_image_encryption_key(void);

/**
 * \brief                     Setup the runtime non-secure image decryption key,
 *                            and lock in a KMU slot.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_runtime_non_secure_image_encryption_key(void);

/**
 * \brief                     Setup the CC3XX PKA SRAM encryption key, and lock
 *                            into a KMU slot.
 *
 * \return                    TFM_PLAT_ERR_SUCCESS on success, non-zero on error.
 */
enum tfm_plat_err_t rse_setup_cc3xx_pka_sram_encryption_key(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_KMU_KEYS_H__ */
