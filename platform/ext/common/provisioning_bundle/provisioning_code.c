/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_otp.h"
#include "provisioning_bundle.h"
#include "Driver_Flash.h"
/* This is a stub to make the linker happy */
void __Vectors(){}

extern ARM_DRIVER_FLASH FLASH_DEV_NAME;
extern const struct provisioning_data_t data;

enum tfm_plat_err_t __attribute__((section("DO_PROVISION"))) do_provision(void) {
    enum tfm_plat_err_t err;
    uint32_t new_lcs;

    err = (enum tfm_plat_err_t)FLASH_DEV_NAME.Initialize(NULL);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_0,
                             sizeof(data.bl2_assembly_and_test_prov_data.bl2_rotpk_0),
                             data.bl2_assembly_and_test_prov_data.bl2_rotpk_0);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_1,
                             sizeof(data.bl2_assembly_and_test_prov_data.bl2_rotpk_1),
                             data.bl2_assembly_and_test_prov_data.bl2_rotpk_1);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#if (MCUBOOT_IMAGE_NUMBER > 2)
    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_2,
                             sizeof(data.bl2_assembly_and_test_prov_data.bl2_rotpk_2),
                             data.bl2_assembly_and_test_prov_data.bl2_rotpk_2);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* MCUBOOT_IMAGE_NUMBER > 2 */
#if (MCUBOOT_IMAGE_NUMBER > 3)
    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_3,
                             sizeof(data.bl2_assembly_and_test_prov_data.bl2_rotpk_3),
                             data.bl2_assembly_and_test_prov_data.bl2_rotpk_3);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* MCUBOOT_IMAGE_NUMBER > 3 */

#ifdef MCUBOOT_ROTPK_SIGN_POLICY
    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_POLICIES,
                             sizeof(data.psa_rot_prov_data.bl2_rotpk_policies),
                             (uint8_t*)&data.psa_rot_prov_data.bl2_rotpk_policies);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    err = tfm_plat_otp_write(PLAT_OTP_ID_SECURE_DEBUG_PK,
                             sizeof(data.bl2_assembly_and_test_prov_data.secure_debug_pk),
                             data.bl2_assembly_and_test_prov_data.secure_debug_pk);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

    err = tfm_plat_otp_write(PLAT_OTP_ID_HUK, sizeof(data.assembly_and_test_prov_data.huk),
                             data.assembly_and_test_prov_data.huk);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    new_lcs = PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
    err = tfm_plat_otp_write(PLAT_OTP_ID_LCS, sizeof(new_lcs),
                             (uint8_t*)&new_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_IAK,
                             sizeof(data.psa_rot_prov_data.iak),
                             data.psa_rot_prov_data.iak);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    err = tfm_plat_otp_write(PLAT_OTP_ID_IAK_LEN,
                             sizeof(data.psa_rot_prov_data.iak_len),
                             (uint8_t*)&data.psa_rot_prov_data.iak_len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    err = tfm_plat_otp_write(PLAT_OTP_ID_IAK_TYPE,
                             sizeof(data.psa_rot_prov_data.iak_type),
                             (uint8_t*)&data.psa_rot_prov_data.iak_type);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

#if ATTEST_INCLUDE_COSE_KEY_ID
    err = tfm_plat_otp_write(PLAT_OTP_ID_IAK_ID,
                             sizeof(data.psa_rot_prov_data.iak_id),
                             data.psa_rot_prov_data.iak_id);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* ATTEST_INCLUDE_COSE_KEY_ID */

    err = tfm_plat_otp_write(PLAT_OTP_ID_BOOT_SEED,
                             sizeof(data.psa_rot_prov_data.boot_seed),
                             data.psa_rot_prov_data.boot_seed);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    err = tfm_plat_otp_write(PLAT_OTP_ID_IMPLEMENTATION_ID,
                             sizeof(data.psa_rot_prov_data.implementation_id),
                             data.psa_rot_prov_data.implementation_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    err = tfm_plat_otp_write(PLAT_OTP_ID_CERT_REF,
                             sizeof(data.psa_rot_prov_data.cert_ref),
                             data.psa_rot_prov_data.cert_ref);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    err = tfm_plat_otp_write(PLAT_OTP_ID_VERIFICATION_SERVICE_URL,
                             sizeof(data.psa_rot_prov_data.verification_service_url),
                             data.psa_rot_prov_data.verification_service_url);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    err = tfm_plat_otp_write(PLAT_OTP_ID_PROFILE_DEFINITION,
                             sizeof(data.psa_rot_prov_data.profile_definition),
                             data.psa_rot_prov_data.profile_definition);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_ENTROPY_SEED,
                             sizeof(data.psa_rot_prov_data.entropy_seed),
                             data.psa_rot_prov_data.entropy_seed);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }

    new_lcs = PLAT_OTP_LCS_SECURED;
    err = tfm_plat_otp_write(PLAT_OTP_ID_LCS,
                             sizeof(new_lcs),
                             (uint8_t*)&new_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return err;
}
