/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <string.h>

#include "unity.h"

#include "cc3xx_hash.h"
#include "kmu_drv.h"
#include "lcm_drv.h"
#include "rse_boot_state.h"
#include "rse_kmu_keys.h"

#include "mock_cc3xx_kdf.h"
#include "mock_dpa_hardened_word_copy.h"
#include "mock_kmu_drv.h"
#include "mock_lcm_drv.h"
#include "mock_rse_boot_state.h"
#include "mock_tfm_plat_otp.h"
#include "mock_trng.h"

static uint32_t KMU_DEV_BASE;
static struct kmu_dev_cfg_t KMU_DEV_CFG_S = {.base = (uintptr_t)&KMU_DEV_BASE};
struct kmu_dev_t KMU_DEV_S = {.cfg = &(KMU_DEV_CFG_S)};

static uint32_t LCM_DEV_BASE;
static struct lcm_dev_cfg_t LCM_DEV_CFG_S = {.base = (uintptr_t)&LCM_DEV_BASE};
struct lcm_dev_t LCM_DEV_S = {.cfg = &(LCM_DEV_CFG_S)};

void test_setup_key_from_derivation_get_boot_state_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_hardware_keyslot_t key_id;
    uint32_t *key_buf;
    uint8_t label[] = "DERIVATION_LABEL";
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;
    boot_state_include_mask boot_state_config;

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    slot = RSE_KMU_SLOT_IAK_SEED;
    setup_aes_aead_key = true;
    boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_LCS;

    rse_get_boot_state_ExpectAndReturn(NULL, 32, NULL, boot_state_config,
                                       TFM_PLAT_ERR_UNSUPPORTED);
    rse_get_boot_state_IgnoreArg_state();
    rse_get_boot_state_IgnoreArg_state_size();

    /* Act */
    plat_err = setup_key_from_derivation(
        key_id, key_buf, label, sizeof(label), slot, &key0_export_config,
        &key1_export_config, setup_aes_aead_key, boot_state_config);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_UNSUPPORTED);
}

void test_setup_key_from_derivation_get_key_buffer_ptr_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_hardware_keyslot_t key_id;
    uint32_t *key_buf;
    uint8_t label[] = "DERIVATION_LABEL";
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;
    boot_state_include_mask boot_state_config;

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    slot = RSE_KMU_SLOT_IAK_SEED;
    setup_aes_aead_key = true;
    boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_LCS;

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_INVALID_SLOT);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    /* Act */
    plat_err = setup_key_from_derivation(
        key_id, key_buf, label, sizeof(label), slot, &key0_export_config,
        &key1_export_config, setup_aes_aead_key, boot_state_config);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_derivation_cc3xx_kdf_cmac_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_hardware_keyslot_t key_id;
    uint32_t *key_buf;
    uint8_t label[] = "DERIVATION_LABEL";
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;
    boot_state_include_mask boot_state_config;

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    slot = RSE_KMU_SLOT_IAK_SEED;
    setup_aes_aead_key = true;
    boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_LCS;

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);

    cc3xx_lowlevel_kdf_cmac_ExpectAndReturn(
        (cc3xx_aes_key_id_t)key_id, key_buf, CC3XX_AES_KEYSIZE_256, label,
        sizeof(label), NULL, 0, NULL, 32, CC3XX_ERR_FAULT_DETECTED);
    cc3xx_lowlevel_kdf_cmac_IgnoreArg_context();
    cc3xx_lowlevel_kdf_cmac_IgnoreArg_context_length();
    cc3xx_lowlevel_kdf_cmac_IgnoreArg_output_key();

    /* Act */
    plat_err = setup_key_from_derivation(
        key_id, key_buf, label, sizeof(label), slot, &key0_export_config,
        &key1_export_config, setup_aes_aead_key, boot_state_config);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, CC3XX_ERR_FAULT_DETECTED);
}

void test_setup_key_from_derivation_duplicate_into_next_slot_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_hardware_keyslot_t key_id;
    uint32_t *key_buf;
    uint8_t label[] = "DERIVATION_LABEL";
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;
    boot_state_include_mask boot_state_config;

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    slot = RSE_KMU_SLOT_IAK_SEED;
    setup_aes_aead_key = true;
    boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_LCS;

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_ExpectAndReturn(
        &KMU_DEV_S, slot + 1, &key1_export_config, KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = setup_key_from_derivation(
        key_id, key_buf, label, sizeof(label), slot, &key0_export_config,
        &key1_export_config, setup_aes_aead_key, boot_state_config);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_derivation_set_key_export_config_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_hardware_keyslot_t key_id;
    uint32_t *key_buf;
    uint8_t label[] = "DERIVATION_LABEL";
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;
    boot_state_include_mask boot_state_config;

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    slot = RSE_KMU_SLOT_IAK_SEED;
    setup_aes_aead_key = true;
    boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_LCS;

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_ExpectAndReturn(
        &KMU_DEV_S, slot + 1, &key1_export_config, KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1,
                                                     KMU_ERROR_NONE);

    kmu_set_key_export_config_ExpectAndReturn(
        &KMU_DEV_S, slot, &key0_export_config, KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = setup_key_from_derivation(
        key_id, key_buf, label, sizeof(label), slot, &key0_export_config,
        &key1_export_config, setup_aes_aead_key, boot_state_config);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_derivation_set_key_export_config_locked_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_hardware_keyslot_t key_id;
    uint32_t *key_buf;
    uint8_t label[] = "DERIVATION_LABEL";
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;
    boot_state_include_mask boot_state_config;

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    slot = RSE_KMU_SLOT_IAK_SEED;
    setup_aes_aead_key = true;
    boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_LCS;

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_ExpectAndReturn(
        &KMU_DEV_S, slot + 1, &key1_export_config, KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1,
                                                     KMU_ERROR_NONE);

    kmu_set_key_export_config_ExpectAndReturn(
        &KMU_DEV_S, slot, &key0_export_config, KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot,
                                                     KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = setup_key_from_derivation(
        key_id, key_buf, label, sizeof(label), slot, &key0_export_config,
        &key1_export_config, setup_aes_aead_key, boot_state_config);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_derivation_ok(void)
{
    enum tfm_plat_err_t plat_err;
    enum kmu_hardware_keyslot_t key_id;
    uint32_t *key_buf;
    uint8_t label[] = "DERIVATION_LABEL";
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;
    boot_state_include_mask boot_state_config;

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    slot = RSE_KMU_SLOT_IAK_SEED;
    setup_aes_aead_key = true;
    boot_state_config =
        RSE_BOOT_STATE_INCLUDE_TP_MODE | RSE_BOOT_STATE_INCLUDE_LCS;

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    /* Act */
    plat_err = setup_key_from_derivation(
        key_id, key_buf, label, sizeof(label), slot, &key0_export_config,
        &key1_export_config, setup_aes_aead_key, boot_state_config);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_SUCCESS);
}

void test_setup_key_from_otp_get_key_buffer_ptr_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    enum tfm_otp_element_id_t otp_id;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY;
    otp_id = PLAT_OTP_ID_KEY_SECURE_ENCRYPTION;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_INVALID_SLOT);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    /* Act */
    plat_err = setup_key_from_otp(slot, otp_id, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_otp_otp_read_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    enum tfm_otp_element_id_t otp_id;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY;
    otp_id = PLAT_OTP_ID_KEY_SECURE_ENCRYPTION;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);

    tfm_plat_otp_read_ExpectAndReturn(otp_id, 0x0, NULL,
                                      TFM_PLAT_ERR_UNSUPPORTED);
    tfm_plat_otp_read_IgnoreArg_out_len();
    tfm_plat_otp_read_IgnoreArg_out();

    /* Act */
    plat_err = setup_key_from_otp(slot, otp_id, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_UNSUPPORTED);
}

void test_setup_key_from_otp_duplicate_into_next_slot_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    enum tfm_otp_element_id_t otp_id;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY;
    otp_id = PLAT_OTP_ID_KEY_SECURE_ENCRYPTION;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    tfm_plat_otp_read_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_ExpectAndReturn(
        &KMU_DEV_S, slot + 1, &key1_export_config, KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = setup_key_from_otp(slot, otp_id, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_otp_set_export_config_and_lock_key_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    enum tfm_otp_element_id_t otp_id;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY;
    otp_id = PLAT_OTP_ID_KEY_SECURE_ENCRYPTION;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    tfm_plat_otp_read_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1,
                                                     KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot,
                                                     KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = setup_key_from_otp(slot, otp_id, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_otp_ok(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    enum tfm_otp_element_id_t otp_id;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY;
    otp_id = PLAT_OTP_ID_KEY_SECURE_ENCRYPTION;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    tfm_plat_otp_read_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    /* Act */
    plat_err = setup_key_from_otp(slot, otp_id, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}

void test_setup_key_from_rng_get_key_buffer_ptr_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_INVALID_SLOT);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    /* Act */
    plat_err = setup_key_from_rng(slot, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_rng_duplicate_into_next_slot_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    bl1_trng_generate_random_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1,
                                                     KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = setup_key_from_rng(slot, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_rng_set_export_config_and_lock_key_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    bl1_trng_generate_random_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1,
                                                     KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot,
                                                     KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = setup_key_from_rng(slot, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_setup_key_from_rng_ok(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    struct kmu_key_export_config_t key0_export_config;
    struct kmu_key_export_config_t key1_export_config;
    bool setup_aes_aead_key;

    /* Prepare */
    slot = RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY;
    setup_aes_aead_key = true;

    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    bl1_trng_generate_random_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1,
                                                     KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_ExpectAndReturn(&KMU_DEV_S, slot,
                                                     KMU_ERROR_NONE);

    /* Act */
    plat_err = setup_key_from_rng(slot, &key0_export_config,
                                  &key1_export_config, setup_aes_aead_key);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}

void test_rse_setup_iak_seed_ok(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, RSE_KMU_SLOT_IAK_SEED,
                                           NULL, NULL, KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_iak_seed();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_SUCCESS);
}

void test_rse_setup_dak_seed_ok(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, RSE_KMU_SLOT_DAK_SEED,
                                           NULL, NULL, KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_dak_seed();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_SUCCESS);
}

void test_rse_setup_rot_cdi_ok(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, RSE_KMU_SLOT_ROT_CDI,
                                           NULL, NULL, KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_rot_cdi();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_SUCCESS);
}

void test_rse_derive_vhuk_seed_invalid_buf_len(void)
{
    enum tfm_plat_err_t plat_err;
    uint32_t *vhuk_seed;
    size_t vhuk_seed_buf_len;
    size_t vhuk_seed_size;

    /* Prepare */
    vhuk_seed = NULL;
    vhuk_seed_buf_len = 0;

    /* Act */
    plat_err =
        rse_derive_vhuk_seed(vhuk_seed, vhuk_seed_buf_len, &vhuk_seed_size);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, 1);
}

void test_rse_derive_vhuk_seed_cc3xx_kdf_cmac_fails(void)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_aes_key_id_t key_id;
    uint32_t *key_buf;
    uint32_t *vhuk_seed;
    size_t vhuk_seed_buf_len;
    size_t vhuk_seed_size;
    uint8_t vhuk_seed_label[] = "VHUK_SEED_DERIVATION";

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    vhuk_seed = NULL;
    vhuk_seed_buf_len = 32;

    cc3xx_lowlevel_kdf_cmac_ExpectAndReturn(
        key_id, key_buf, CC3XX_AES_KEYSIZE_256, NULL, sizeof(vhuk_seed_label),
        NULL, 0, vhuk_seed, 32, CC3XX_ERR_FAULT_DETECTED);
    cc3xx_lowlevel_kdf_cmac_IgnoreArg_label();
    cc3xx_lowlevel_kdf_cmac_IgnoreArg_output_key();

    /* Act */
    plat_err =
        rse_derive_vhuk_seed(vhuk_seed, vhuk_seed_buf_len, &vhuk_seed_size);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, CC3XX_ERR_FAULT_DETECTED);
}

void test_rse_derive_vhuk_seed_ok(void)
{
    enum tfm_plat_err_t plat_err;
    cc3xx_aes_key_id_t key_id;
    uint32_t *key_buf;
    uint32_t *vhuk_seed;
    size_t vhuk_seed_buf_len;
    size_t vhuk_seed_size;
    uint8_t vhuk_seed_label[] = "VHUK_SEED_DERIVATION";

    /* Prepare */
    key_id = KMU_HW_SLOT_HUK;
    key_buf = NULL;
    vhuk_seed = NULL;
    vhuk_seed_buf_len = 32;

    cc3xx_lowlevel_kdf_cmac_ExpectAndReturn(
        key_id, key_buf, CC3XX_AES_KEYSIZE_256, NULL, sizeof(vhuk_seed_label),
        NULL, 0, vhuk_seed, 32, TFM_PLAT_ERR_SUCCESS);
    cc3xx_lowlevel_kdf_cmac_IgnoreArg_label();
    cc3xx_lowlevel_kdf_cmac_IgnoreArg_output_key();

    /* Act */
    plat_err =
        rse_derive_vhuk_seed(vhuk_seed, vhuk_seed_buf_len, &vhuk_seed_size);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(32, vhuk_seed_size);
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_SUCCESS);
}

void test_rse_setup_vhuk_ok(void)
{
    enum tfm_plat_err_t plat_err;
    uint8_t *vhuk_seeds;
    size_t vhuk_seeds_len;

    /* Prepare */
    vhuk_seeds = NULL;
    vhuk_seeds_len = 0;
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, RSE_KMU_SLOT_VHUK, NULL,
                                           NULL, KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_vhuk(vhuk_seeds, vhuk_seeds_len);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_SUCCESS);
}

void test_rse_setup_session_key_setup_key_from_derivation_fails(void)
{
    enum tfm_plat_err_t plat_err;
    uint8_t *ivs;
    size_t ivs_len;

    /* Prepare */
    ivs = NULL;
    ivs_len = 0;
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_UNSUPPORTED);

    /* Act */
    plat_err = rse_setup_session_key(ivs, ivs_len);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_UNSUPPORTED);
}

void test_rse_setup_session_key_set_key_0_locked_fails(void)
{
    enum tfm_plat_err_t plat_err;
    uint8_t *ivs;
    size_t ivs_len;

    /* Prepare */
    ivs = NULL;
    ivs_len = 0;
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, RSE_KMU_SLOT_SESSION_KEY_0,
                                       KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_session_key(ivs, ivs_len);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_session_key_set_key_1_locked_fails(void)
{
    enum tfm_plat_err_t plat_err;
    uint8_t *ivs;
    size_t ivs_len;

    /* Prepare */
    ivs = NULL;
    ivs_len = 0;
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, RSE_KMU_SLOT_SESSION_KEY_0,
                                       KMU_ERROR_NONE);
    kmu_set_key_locked_ExpectAndReturn(
        &KMU_DEV_S, RSE_KMU_SLOT_SESSION_KEY_0 + 1, KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_session_key(ivs, ivs_len);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_session_key_ok(void)
{
    enum tfm_plat_err_t plat_err;
    uint8_t *ivs;
    size_t ivs_len;

    /* Prepare */
    ivs = NULL;
    ivs_len = 0;
    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(
        &KMU_DEV_S, RSE_KMU_SLOT_SESSION_KEY_0, NULL, NULL, KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(
        &KMU_DEV_S, RSE_KMU_SLOT_SESSION_KEY_0, NULL, NULL, KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    kmu_get_key_buffer_ptr_ExpectAndReturn(
        &KMU_DEV_S, RSE_KMU_SLOT_SESSION_KEY_0 + 1, NULL, NULL, KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    dpa_hardened_word_copy_Ignore();
    kmu_set_key_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_session_key(ivs, ivs_len);

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}

void test_rse_setup_cm_provisioning_key_sp_not_enabled(void)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;

    /* Prepare */
    tp_mode = LCM_TP_MODE_PCI;
    sp_enabled = LCM_FALSE;

    lcm_get_tp_mode_Expect(&LCM_DEV_S, NULL);
    lcm_get_tp_mode_IgnoreArg_mode();
    lcm_get_tp_mode_ReturnMemThruPtr_mode((enum lcm_tp_mode_t *)&tp_mode,
                                          sizeof(enum lcm_tp_mode_t));

    lcm_get_sp_enabled_Expect(&LCM_DEV_S, NULL);
    lcm_get_sp_enabled_IgnoreArg_enabled();
    lcm_get_sp_enabled_ReturnMemThruPtr_enabled((enum lcm_bool_t *)&sp_enabled,
                                                sizeof(enum lcm_bool_t));

    /* Act */
    plat_err = rse_setup_cm_provisioning_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_SYSTEM_ERR);
}

void test_rse_setup_cm_provisioning_key_invalid_tp_mode(void)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;

    /* Prepare */
    tp_mode = LCM_TP_MODE_INVALID;
    sp_enabled = LCM_TRUE;

    lcm_get_tp_mode_Expect(&LCM_DEV_S, NULL);
    lcm_get_tp_mode_IgnoreArg_mode();
    lcm_get_tp_mode_ReturnMemThruPtr_mode((enum lcm_tp_mode_t *)&tp_mode,
                                          sizeof(enum lcm_tp_mode_t));

    lcm_get_sp_enabled_Expect(&LCM_DEV_S, NULL);
    lcm_get_sp_enabled_IgnoreArg_enabled();
    lcm_get_sp_enabled_ReturnMemThruPtr_enabled((enum lcm_bool_t *)&sp_enabled,
                                                sizeof(enum lcm_bool_t));

    /* Act */
    plat_err = rse_setup_cm_provisioning_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_KEY_DERIVATION_INVALID_TP_MODE);
}

void test_rse_setup_cm_provisioning_key_setup_key_from_derivation_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;

    /* Prepare */
    tp_mode = LCM_TP_MODE_PCI;
    sp_enabled = LCM_TRUE;

    lcm_get_tp_mode_Expect(&LCM_DEV_S, NULL);
    lcm_get_tp_mode_IgnoreArg_mode();
    lcm_get_tp_mode_ReturnMemThruPtr_mode((enum lcm_tp_mode_t *)&tp_mode,
                                          sizeof(enum lcm_tp_mode_t));

    lcm_get_sp_enabled_Expect(&LCM_DEV_S, NULL);
    lcm_get_sp_enabled_IgnoreArg_enabled();
    lcm_get_sp_enabled_ReturnMemThruPtr_enabled((enum lcm_bool_t *)&sp_enabled,
                                                sizeof(enum lcm_bool_t));

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_UNSUPPORTED);

    /* Act */
    plat_err = rse_setup_cm_provisioning_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, TFM_PLAT_ERR_UNSUPPORTED);
}

void test_rse_setup_cm_provisioning_key_kmu_set_key_0_locked_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;

    /* Prepare */
    tp_mode = LCM_TP_MODE_PCI;
    sp_enabled = LCM_TRUE;

    lcm_get_tp_mode_Expect(&LCM_DEV_S, NULL);
    lcm_get_tp_mode_IgnoreArg_mode();
    lcm_get_tp_mode_ReturnMemThruPtr_mode((enum lcm_tp_mode_t *)&tp_mode,
                                          sizeof(enum lcm_tp_mode_t));

    lcm_get_sp_enabled_Expect(&LCM_DEV_S, NULL);
    lcm_get_sp_enabled_IgnoreArg_enabled();
    lcm_get_sp_enabled_ReturnMemThruPtr_enabled((enum lcm_bool_t *)&sp_enabled,
                                                sizeof(enum lcm_bool_t));

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_locked_ExpectAndReturn(
        &KMU_DEV_S, RSE_KMU_SLOT_CM_PROVISIONING_KEY, KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_cm_provisioning_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_cm_provisioning_key_kmu_set_key_1_locked_fails(void)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;

    /* Prepare */
    tp_mode = LCM_TP_MODE_PCI;
    sp_enabled = LCM_TRUE;

    lcm_get_tp_mode_Expect(&LCM_DEV_S, NULL);
    lcm_get_tp_mode_IgnoreArg_mode();
    lcm_get_tp_mode_ReturnMemThruPtr_mode((enum lcm_tp_mode_t *)&tp_mode,
                                          sizeof(enum lcm_tp_mode_t));

    lcm_get_sp_enabled_Expect(&LCM_DEV_S, NULL);
    lcm_get_sp_enabled_IgnoreArg_enabled();
    lcm_get_sp_enabled_ReturnMemThruPtr_enabled((enum lcm_bool_t *)&sp_enabled,
                                                sizeof(enum lcm_bool_t));

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    dpa_hardened_word_copy_Ignore();

    kmu_set_key_locked_ExpectAndReturn(
        &KMU_DEV_S, RSE_KMU_SLOT_CM_PROVISIONING_KEY, KMU_ERROR_NONE);
    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S,
                                       RSE_KMU_SLOT_CM_PROVISIONING_KEY + 1,
                                       KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_cm_provisioning_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

TEST_CASE(LCM_TP_MODE_PCI)
TEST_CASE(LCM_TP_MODE_TCI)
void test_rse_setup_cm_provisioning_key_ok(enum lcm_tp_mode_t tp_mode)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_bool_t sp_enabled;
    enum rse_kmu_slot_id_t slot;

    /* Prepare */
    slot = RSE_KMU_SLOT_CM_PROVISIONING_KEY;
    sp_enabled = LCM_TRUE;

    lcm_get_tp_mode_Expect(&LCM_DEV_S, NULL);
    lcm_get_tp_mode_IgnoreArg_mode();
    lcm_get_tp_mode_ReturnMemThruPtr_mode((enum lcm_tp_mode_t *)&tp_mode,
                                          sizeof(enum lcm_tp_mode_t));

    lcm_get_sp_enabled_Expect(&LCM_DEV_S, NULL);
    lcm_get_sp_enabled_IgnoreArg_enabled();
    lcm_get_sp_enabled_ReturnMemThruPtr_enabled((enum lcm_bool_t *)&sp_enabled,
                                                sizeof(enum lcm_bool_t));

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot + 1, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    dpa_hardened_word_copy_Ignore();
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, slot, KMU_ERROR_NONE);
    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1, KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_cm_provisioning_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}

void test_rse_setup_dm_provisioning_key_ok(void)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;
    enum rse_kmu_slot_id_t slot;

    /* Prepare */
    tp_mode = LCM_TP_MODE_PCI;
    sp_enabled = LCM_TRUE;
    slot = RSE_KMU_SLOT_DM_PROVISIONING_KEY;

    lcm_get_tp_mode_Expect(&LCM_DEV_S, NULL);
    lcm_get_tp_mode_IgnoreArg_mode();
    lcm_get_tp_mode_ReturnMemThruPtr_mode((enum lcm_tp_mode_t *)&tp_mode,
                                          sizeof(enum lcm_tp_mode_t));

    lcm_get_sp_enabled_Expect(&LCM_DEV_S, NULL);
    lcm_get_sp_enabled_IgnoreArg_enabled();
    lcm_get_sp_enabled_ReturnMemThruPtr_enabled((enum lcm_bool_t *)&sp_enabled,
                                                sizeof(enum lcm_bool_t));

    rse_get_boot_state_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    cc3xx_lowlevel_kdf_cmac_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot + 1, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    dpa_hardened_word_copy_Ignore();
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, slot, KMU_ERROR_NONE);
    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, slot + 1, KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_dm_provisioning_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}

void test_rse_setup_secure_img_encr_key_setup_key_from_otp_fails(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_runtime_secure_image_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_secure_img_encr_key_kmu_set_key_locked_fails(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    tfm_plat_otp_read_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_locked_IgnoreAndReturn(KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_runtime_secure_image_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_secure_img_encr_key_ok(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    enum tfm_otp_element_id_t otp_id;

    /* Prepare */
    slot = RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY;
    otp_id = PLAT_OTP_ID_KEY_SECURE_ENCRYPTION;

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    tfm_plat_otp_read_ExpectAndReturn(otp_id, 0x0u, NULL, TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_read_IgnoreArg_out_len();
    tfm_plat_otp_read_IgnoreArg_out();

    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, slot, KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_runtime_secure_image_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}

void test_rse_setup_non_secure_img_encr_key_setup_key_from_otp_fails(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_runtime_non_secure_image_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_non_secure_img_encr_key_kmu_set_key_locked_fails(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    tfm_plat_otp_read_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_locked_IgnoreAndReturn(KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_runtime_non_secure_image_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_non_secure_img_encr_key_ok(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;
    enum tfm_otp_element_id_t otp_id;

    /* Prepare */
    slot = RSE_KMU_SLOT_NON_SECURE_ENCRYPTION_KEY;
    otp_id = PLAT_OTP_ID_KEY_NON_SECURE_ENCRYPTION;

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    tfm_plat_otp_read_ExpectAndReturn(otp_id, 0x0u, NULL, TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_read_IgnoreArg_out_len();
    tfm_plat_otp_read_IgnoreArg_out();

    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, slot, KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_runtime_non_secure_image_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}

void test_rse_setup_cc3xx_pka_sram_encryption_key_setup_from_rng_fails(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_cc3xx_pka_sram_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_cc3xx_pka_sram_encryption_key_lock_fails(void)
{
    enum tfm_plat_err_t plat_err;

    /* Prepare */
    kmu_get_key_buffer_ptr_IgnoreAndReturn(KMU_ERROR_NONE);
    bl1_trng_generate_random_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_locked_IgnoreAndReturn(KMU_ERROR_INVALID_SLOT);

    /* Act */
    plat_err = rse_setup_cc3xx_pka_sram_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_INVALID_SLOT);
}

void test_rse_setup_cc3xx_pka_sram_encryption_key_ok(void)
{
    enum tfm_plat_err_t plat_err;
    enum rse_kmu_slot_id_t slot;

    /* Prepare */
    slot = RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY;

    kmu_get_key_buffer_ptr_ExpectAndReturn(&KMU_DEV_S, slot, NULL, NULL,
                                           KMU_ERROR_NONE);
    kmu_get_key_buffer_ptr_IgnoreArg_key_slot();
    kmu_get_key_buffer_ptr_IgnoreArg_slot_size();

    bl1_trng_generate_random_IgnoreAndReturn(TFM_PLAT_ERR_SUCCESS);
    kmu_set_key_export_config_IgnoreAndReturn(KMU_ERROR_NONE);
    kmu_set_key_export_config_locked_IgnoreAndReturn(KMU_ERROR_NONE);

    kmu_set_key_locked_ExpectAndReturn(&KMU_DEV_S, slot, KMU_ERROR_NONE);

    /* Act */
    plat_err = rse_setup_cc3xx_pka_sram_encryption_key();

    /* Assert */
    TEST_ASSERT_EQUAL(plat_err, KMU_ERROR_NONE);
}
