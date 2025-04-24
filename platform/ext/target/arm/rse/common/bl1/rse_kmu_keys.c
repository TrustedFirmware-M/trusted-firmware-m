/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_kmu_keys.h"

#include <stdint.h>
#include <string.h>

#include "device_definition.h"
#include "dpa_hardened_word_copy.h"
#include "cc3xx_drv.h"
#include "trng.h"
#include "fatal_error.h"

static const struct kmu_key_export_config_t aes_key0_export_config = {
    .export_address = CC3XX_BASE_S + 0x400, /* CC3XX AES_KEY_0 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static const struct kmu_key_export_config_t aes_key1_export_config = {
    .export_address = CC3XX_BASE_S + 0x420, /* CC3XX AES_KEY_1 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static const struct kmu_key_export_config_t sic_dr0_export_config = {
    .export_address = SIC_BASE_S + 0x120, /* CC3XX DR0_KEY_WORD0 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static const struct kmu_key_export_config_t sic_dr1_export_config = {
    .export_address = SIC_BASE_S + 0x220, /* SIC DR1_KEY_WORD0 register */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_8_WRITES, /* Perform 8 writes (total 256 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static const struct kmu_key_export_config_t cc3xx_pka_sram_key_config = {
    .export_address = CC3XX_BASE_S + 0xFD0, /* CC3XX keystore mux. This address is reused from the
                                             * CC3XX register map and redirected to the PKA SRAM
                                             * keystore.
                                             */
    .destination_port_write_delay = 0, /* No delay */
    .destination_port_address_increment = 0x01, /* Increment by 4 bytes with each write */
    .destination_port_data_width_code = KMU_DESTINATION_PORT_WIDTH_32_BITS, /* Write 32 bits with each write */
    .destination_port_data_writes_code = KMU_DESTINATION_PORT_WIDTH_4_WRITES, /* Perform 4 writes (total 128 bits) */
    .new_mask_for_next_key_writes = true,  /* refresh the masking */
    .write_mask_disable = false, /* Don't disable the masking */
};

static enum tfm_plat_err_t set_export_config_and_lock_key(enum rse_kmu_slot_id_t slot,
                                                          const struct kmu_key_export_config_t *config)
{
    enum kmu_error_t kmu_err;
    /* TODO lock keyslots once the runtime CC3XX driver supports locked KMU
     * keyslots
     */
    /* kmu_err = kmu_set_key_locked(&KMU_DEV_S, slot); */
    /* if (kmu_err != KMU_ERROR_NONE) { */
    /*     return (enum tfm_plat_err_t) kmu_err; */
    /* } */


    kmu_err = kmu_set_key_export_config(&KMU_DEV_S, slot, config);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    kmu_err = kmu_set_key_export_config_locked(&KMU_DEV_S, slot);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t duplicate_into_next_slot(enum rse_kmu_slot_id_t slot,
                                                    const struct kmu_key_export_config_t *config)
{
    enum kmu_error_t kmu_err;
    volatile uint32_t *p_kmu_slot_buf;
    volatile uint32_t *p_kmu_secondary_slot_buf;
    size_t kmu_slot_size;
    enum tfm_plat_err_t plat_err;

    /* kmu_get_key_buffer_ptr validates whether slot and slot + 1 are valid slots */

    kmu_err = kmu_get_key_buffer_ptr(&KMU_DEV_S, slot,
                                     &p_kmu_slot_buf, &kmu_slot_size);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    kmu_err = kmu_get_key_buffer_ptr(&KMU_DEV_S, slot + 1,
                                     &p_kmu_secondary_slot_buf,
                                     &kmu_slot_size);

    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    dpa_hardened_word_copy(p_kmu_secondary_slot_buf, p_kmu_slot_buf,
                        kmu_slot_size / sizeof(uint32_t));

    plat_err = set_export_config_and_lock_key(slot + 1, config);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

/**
 * @brief Computes the size of key from the relevant configuration values
 *        of the KMUKSC<n> register, e.g. Destination Port Data Width (DPDW)
 *        and Num Destination Port Writes (NDPW)
 *
 * @note  DPDW 00b -> 8 bits, 01b -> 16 bits, 10b -> 32 bits
 *        NDPW 00b -> 4 writes, 01b -> 8 writes, 10b -> 16 writes, 11b -> 32 writes
 *        key size in bytes is then: 2^(DPDW) * 2^(2 + NDPW)
 *
 * @param[in] cfg  Pointer to the configuration structure holding DPDW and NDPW
 *
 * @return size_t  Size in bytes of the configured key
 */
static inline size_t key_size_from_export_config(const struct kmu_key_export_config_t *cfg)
{
    const uint32_t DPDW = cfg->destination_port_data_width_code;
    const uint32_t NDPW = cfg->destination_port_data_writes_code;

    return ((1 << DPDW) * (1 << (2 + NDPW)));
}

enum tfm_plat_err_t setup_key_from_derivation(enum kmu_hardware_keyslot_t input_key_id,
                                              uint32_t *key_buf,
                                              const uint8_t *label, size_t label_len,
                                              const uint8_t *context, size_t context_len,
                                              enum rse_kmu_slot_id_t slot,
                                              const struct kmu_key_export_config_t *export_config,
                                              const struct kmu_key_export_config_t *aead_export_config,
                                              bool setup_aes_aead_key, boot_state_include_mask mask)
{
    enum tfm_plat_err_t plat_err;
    uint8_t boot_state_context[32] = {0};
    enum kmu_error_t kmu_err;
    volatile uint32_t *p_kmu_slot_buf;
    const size_t key_size = key_size_from_export_config(export_config);
    size_t kmu_slot_size;
    uint8_t *context_ptr =  NULL;
    size_t context_ptr_len = 0;

    if (context != NULL && mask != RSE_BOOT_STATE_INCLUDE_NONE) {
        return TFM_PLAT_ERR_KEY_DERIVATION_INVALID_BOOT_STATE_WITH_CONTEXT;
    }

    if (context != NULL) {
        context_ptr = (uint8_t *)context;
        context_ptr_len = context_len;
    } else {
        plat_err = rse_get_boot_state(boot_state_context, sizeof(boot_state_context), &context_ptr_len, mask);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }

        context_ptr = (uint8_t *)boot_state_context;
    }

    kmu_err = kmu_get_key_buffer_ptr(&KMU_DEV_S, slot, &p_kmu_slot_buf, &kmu_slot_size);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    if (key_size > kmu_slot_size) {
        return TFM_PLAT_ERR_KEY_DERIVATION_DERIVATION_SLOT_TOO_SMALL;
    }

    plat_err = cc3xx_lowlevel_kdf_cmac((cc3xx_aes_key_id_t)input_key_id,
                                 key_buf, CC3XX_AES_KEYSIZE_256, label,
                                 label_len, context_ptr, context_ptr_len,
                                 (uint32_t *)p_kmu_slot_buf, 32);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Due to limitations in CryptoCell, any key that needs to be used for
     * AES-CCM needs to be duplicated into a second slot.
     */
    if (setup_aes_aead_key) {
        plat_err = duplicate_into_next_slot(slot, aead_export_config);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    plat_err = set_export_config_and_lock_key(slot, export_config);

    return plat_err;
}

enum tfm_plat_err_t setup_key_from_otp(enum rse_kmu_slot_id_t slot,
                                       enum tfm_otp_element_id_t otp_id,
                                       const struct kmu_key_export_config_t *export_config,
                                       const struct kmu_key_export_config_t *aead_export_config,
                                       bool setup_aes_aead_key)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;
    volatile uint32_t *p_kmu_slot_buf;
    const size_t key_size = key_size_from_export_config(export_config);
    size_t kmu_slot_size;

    kmu_err = kmu_get_key_buffer_ptr(&KMU_DEV_S, slot, &p_kmu_slot_buf, &kmu_slot_size);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t)kmu_err;
    }

    if (key_size > kmu_slot_size) {
        return TFM_PLAT_ERR_KEY_DERIVATION_OTP_SLOT_TOO_SMALL;
    }

    plat_err = tfm_plat_otp_read(otp_id, key_size, (uint8_t *)p_kmu_slot_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Due to limitations in CryptoCell, any key that needs to be used for
     * AES-CCM needs to be duplicated into a second slot.
     */
    if (setup_aes_aead_key) {
        plat_err = duplicate_into_next_slot(slot, aead_export_config);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    plat_err = set_export_config_and_lock_key(slot, export_config);

    return plat_err;
}

enum tfm_plat_err_t setup_key_from_rng(enum rse_kmu_slot_id_t slot,
                                       const struct kmu_key_export_config_t *export_config,
                                       const struct kmu_key_export_config_t *aead_export_config,
                                       bool setup_aes_aead_key)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;
    volatile uint32_t *p_kmu_slot_buf;
    const size_t key_size = key_size_from_export_config(export_config);
    size_t kmu_slot_size;

    kmu_err = kmu_get_key_buffer_ptr(&KMU_DEV_S, slot, &p_kmu_slot_buf, &kmu_slot_size);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t)kmu_err;
    }

    if (key_size > kmu_slot_size) {
        return TFM_PLAT_ERR_KEY_DERIVATION_RNG_SLOT_TOO_SMALL;
    }

    bl1_trng_generate_random((uint8_t *)p_kmu_slot_buf, key_size);

    /* Due to limitations in CryptoCell, any key that needs to be used for
     * AES-CCM needs to be duplicated into a second slot.
     */
    if (setup_aes_aead_key) {
        plat_err = duplicate_into_next_slot(slot, aead_export_config);
        if (plat_err != TFM_PLAT_ERR_SUCCESS) {
            return plat_err;
        }
    }

    plat_err = set_export_config_and_lock_key(slot, export_config);

    return plat_err;
}

enum tfm_plat_err_t rse_setup_iak_seed(void)
{
    const uint8_t iak_seed_label[] = "BL1_IAK_SEED_DERIVATION";

    /* FixMe: updated spec removes the context and simplifies the procedure */
#if defined(RSE_BOOT_KEYS_CCA ) || defined(RSE_BOOT_KEYS_DPE)

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS |
        RSE_BOOT_STATE_INCLUDE_DCU_STATE;
#else
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS;
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

#else

    const boot_state_include_mask boot_state_config = RSE_BOOT_STATE_INCLUDE_NONE;

#endif /* RSE_BOOT_KEYS_CCA || RSE_BOOT_KEYS_DPE */

    /* This derives from HUK, there is a typo in the spec, not from GUK.
     * FixMe: this should be configurable per platform
     */
    return setup_key_from_derivation(KMU_HW_SLOT_HUK, NULL, iak_seed_label,
                                     sizeof(iak_seed_label), NULL, 0,
                                     RSE_KMU_SLOT_IAK_SEED,
                                     &aes_key0_export_config, NULL, false,
                                     boot_state_config);
}

#ifdef RSE_BOOT_KEYS_CCA
enum tfm_plat_err_t rse_setup_dak_seed(void)
{
    const uint8_t dak_seed_label[]  = "BL1_DAK_SEED_DERIVATION";
#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS |
        RSE_BOOT_STATE_INCLUDE_DCU_STATE;
#else
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS;
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

    return setup_key_from_derivation(KMU_HW_SLOT_GUK, NULL, dak_seed_label,
                                     sizeof(dak_seed_label), NULL, 0,
                                     RSE_KMU_SLOT_DAK_SEED,
                                     &aes_key0_export_config, NULL, false,
                                     boot_state_config);
}
#endif /* RSE_BOOT_KEYS_CCA */

#ifdef RSE_BOOT_KEYS_DPE
enum tfm_plat_err_t rse_setup_rot_cdi(void)
{
    const uint8_t rot_cdi_label[] = "BL1_ROT_CDI_DERIVATION";
#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS |
        RSE_BOOT_STATE_INCLUDE_DCU_STATE;
#else
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS;
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

    return setup_key_from_derivation(KMU_HW_SLOT_HUK, NULL, rot_cdi_label,
                                     sizeof(rot_cdi_label), NULL, 0, RSE_KMU_SLOT_ROT_CDI,
                                     &aes_key0_export_config, NULL, false,
                                     boot_state_config);
}
#endif /* RSE_BOOT_KEYS_DPE */

enum tfm_plat_err_t rse_derive_vhuk_seed(uint32_t *vhuk_seed, size_t vhuk_seed_buf_len,
                         size_t *vhuk_seed_size)
{
    const uint8_t vhuk_seed_label[]  = "VHUK_SEED_DERIVATION";
    enum tfm_plat_err_t plat_err;

    if (vhuk_seed_buf_len < 32) {
        return 1;
    }

    plat_err = cc3xx_lowlevel_kdf_cmac((cc3xx_aes_key_id_t)KMU_HW_SLOT_HUK,
                                 NULL, CC3XX_AES_KEYSIZE_256, vhuk_seed_label,
                                 sizeof(vhuk_seed_label), NULL, 0, vhuk_seed, 32);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    *vhuk_seed_size = 32;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_setup_vhuk(const uint8_t *vhuk_seeds, size_t vhuk_seeds_len)
{
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS;

    return setup_key_from_derivation(KMU_HW_SLOT_GUK, NULL, vhuk_seeds,
                                     vhuk_seeds_len, NULL, 0, RSE_KMU_SLOT_VHUK,
                                     &aes_key0_export_config, NULL, false,
                                     boot_state_config);
}

enum tfm_plat_err_t rse_setup_session_key(const uint8_t *ivs, size_t ivs_len)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_LCS | RSE_BOOT_STATE_INCLUDE_TP_MODE |
        RSE_BOOT_STATE_INCLUDE_BL1_2_HASH | RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS;


    plat_err = setup_key_from_derivation(KMU_HW_SLOT_GUK, NULL, ivs, ivs_len, NULL, 0,
                                   RSE_KMU_SLOT_SESSION_KEY_0,
                                     &aes_key0_export_config,
                                     &aes_key1_export_config, true,
                                   boot_state_config);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* TODO: Should be removed once setup_key properly locks KMU slots */
    kmu_err = kmu_set_key_locked(&KMU_DEV_S, RSE_KMU_SLOT_SESSION_KEY_0);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    kmu_err = kmu_set_key_locked(&KMU_DEV_S,  RSE_KMU_SLOT_SESSION_KEY_0 + 1);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t derive_using_krtl_or_zero_key(const uint8_t *label,
                                                         size_t label_len,
                                                         const uint8_t *context,
                                                         size_t context_len,
                                                         enum rse_kmu_slot_id_t output_slot,
                                                         boot_state_include_mask mask)
{
    enum tfm_plat_err_t plat_err;
    uint32_t zero_key[8] = {0};
    enum kmu_error_t kmu_err;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;
    enum rse_kmu_slot_id_t input_slot;
    enum lcm_error_t lcm_err;
    uint32_t *key_buf;

    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_get_sp_enabled(&LCM_DEV_S, &sp_enabled);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (sp_enabled != LCM_TRUE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    switch(tp_mode) {
    case LCM_TP_MODE_PCI:
        input_slot = (enum rse_kmu_slot_id_t)KMU_HW_SLOT_KRTL;
        key_buf = NULL;
        break;
    case LCM_TP_MODE_TCI:
        input_slot = (enum rse_kmu_slot_id_t)0;
        key_buf = zero_key;
        break;
    default:
        FATAL_ERR(TFM_PLAT_ERR_KEY_DERIVATION_INVALID_TP_MODE);
        return (enum tfm_plat_err_t) TFM_PLAT_ERR_KEY_DERIVATION_INVALID_TP_MODE;
    }

    plat_err = setup_key_from_derivation((enum kmu_hardware_keyslot_t)input_slot,
                                   key_buf, label, label_len, context, context_len, output_slot,
                                   &aes_key0_export_config, NULL, false, mask);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Until we can lock all the keys, just lock the ones only used in
     * BL1/provisioning.
     */
    kmu_err = kmu_set_key_locked(&KMU_DEV_S, output_slot);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_setup_master_key(const uint8_t *label, size_t label_len,
                                         const uint8_t *context, size_t context_len)
{
    return derive_using_krtl_or_zero_key(label, label_len,
                                         context, context_len,
                                         RSE_KMU_SLOT_MASTER_KEY,
                                         RSE_BOOT_STATE_INCLUDE_NONE);
}

enum tfm_plat_err_t rse_setup_provisioning_key(const uint8_t *label, size_t label_len,
                                               const uint8_t *context, size_t context_len)
{
    enum tfm_plat_err_t err;
    enum kmu_error_t kmu_err;

    err = setup_key_from_derivation((enum kmu_hardware_keyslot_t)RSE_KMU_SLOT_MASTER_KEY,
                                     NULL, label, label_len,
                                     context, context_len,
                                     RSE_KMU_SLOT_PROVISIONING_KEY,
                                     &aes_key0_export_config,
                                     &aes_key1_export_config,
                                     true, RSE_BOOT_STATE_INCLUDE_NONE);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* Until we can lock all the keys, just lock the ones only used in
     * BL1/provisioning.
     */
    kmu_err = kmu_set_key_locked(&KMU_DEV_S, RSE_KMU_SLOT_PROVISIONING_KEY);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    kmu_err = kmu_set_key_locked(&KMU_DEV_S, RSE_KMU_SLOT_PROVISIONING_KEY + 1);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_setup_runtime_secure_image_encryption_key(void)
{
#ifdef RSE_XIP
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;
    const uint8_t label[] = "RUNTIME_SECURE_ENCRYPTION_KEY";
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_BL1_2_HASH |
        RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS;

    plat_err = setup_key_from_derivation(KMU_HW_SLOT_KCE_CM, NULL,
                                         label, sizeof(label), NULL, 0,
                                         RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY,
                                         &sic_dr0_export_config, NULL, false,
                                         boot_state_config);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    kmu_err = kmu_set_key_locked(&KMU_DEV_S, RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }
#endif /* RSE_XIP */

    /* TODO FIXME Allow Mcuboot to decrypt using on-device keys */
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_setup_runtime_non_secure_image_encryption_key(void)
{
#ifdef RSE_XIP
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;
    const uint8_t label[] = "RUNTIME_NON_SECURE_ENCRYPTION_KEY";
    const boot_state_include_mask boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_BL1_2_HASH |
        RSE_BOOT_STATE_INCLUDE_REPROVISIONING_BITS;

    plat_err = setup_key_from_derivation(KMU_HW_SLOT_KCE_DM, NULL,
                                         label, sizeof(label), NULL, 0,
                                         RSE_KMU_SLOT_NON_SECURE_ENCRYPTION_KEY,
                                         &sic_dr1_export_config, NULL, false,
                                         boot_state_config);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    kmu_err = kmu_set_key_locked(&KMU_DEV_S, RSE_KMU_SLOT_NON_SECURE_ENCRYPTION_KEY);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t) kmu_err;
    }
#endif /* RSE_XIP */

    /* TODO FIXME Allow Mcuboot to decrypt using on-device keys */
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t rse_setup_cc3xx_pka_sram_encryption_key(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_error_t kmu_err;

    plat_err = setup_key_from_rng(RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY,
                            &cc3xx_pka_sram_key_config, NULL, false);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* TODO FIXME remove this when all keys can be locked. */
    kmu_err = kmu_set_key_locked(&KMU_DEV_S, RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY);
    if (kmu_err != KMU_ERROR_NONE) {
        return (enum tfm_plat_err_t)kmu_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
