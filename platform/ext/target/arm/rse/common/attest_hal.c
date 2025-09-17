/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "config_tfm.h"
#include "tfm_attest_hal.h"
#include "tfm_plat_boot_seed.h"
#include "tfm_plat_device_id.h"
#include "tfm_plat_otp.h"

static enum tfm_security_lifecycle_t map_otp_lcs_to_tfm_slc(enum plat_otp_lcs_t lcs)
{
    switch (lcs) {
    case PLAT_OTP_LCS_ASSEMBLY_AND_TEST:
        return TFM_SLC_ASSEMBLY_AND_TEST;
    case PLAT_OTP_LCS_PSA_ROT_PROVISIONING:
        return TFM_SLC_PSA_ROT_PROVISIONING;
    case PLAT_OTP_LCS_SECURED:
        return TFM_SLC_SECURED;
    case PLAT_OTP_LCS_DECOMMISSIONED:
        return TFM_SLC_DECOMMISSIONED;
    case PLAT_OTP_LCS_UNKNOWN:
    default:
        return TFM_SLC_UNKNOWN;
    }
}

enum tfm_security_lifecycle_t tfm_attest_hal_get_security_lifecycle(void)
{
    enum plat_otp_lcs_t otp_lcs;
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(otp_lcs), (uint8_t*)&otp_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_SLC_UNKNOWN;
    }

    return map_otp_lcs_to_tfm_slc(otp_lcs);
}

enum tfm_plat_err_t
tfm_attest_hal_get_verification_service(uint32_t *size, uint8_t *buf)
{
    /* TODO: Put some sensible URL here */
    const char verification_service [] = "none";

    if (*size < sizeof(verification_service) - 1) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Not including the null-terminator. */
     memcpy(buf, verification_service, sizeof(verification_service) - 1);
    *size = sizeof(verification_service) - 1;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t
tfm_attest_hal_get_profile_definition(uint32_t *size, uint8_t *buf)
{
#if ATTEST_TOKEN_PROFILE_ARM_CCA
    const char profile [] = "tag:arm.com,2023:cca_platform#1.0.0";
#elif ATTEST_TOKEN_PROFILE_PSA_2_0_0
    const char profile [] = "tag:psacertified.org,2023:psa#tfm";
#else
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
   #error "Attestation token profile is incorrect"
#endif
#endif

    if (*size < sizeof(profile) - 1) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Not including the null-terminator. */
    memcpy(buf, profile, sizeof(profile) - 1);
    *size = sizeof(profile) - 1;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_get_boot_seed(uint32_t size, uint8_t *buf)
{
    return TFM_PLAT_ERR_UNSUPPORTED;
}

enum tfm_plat_err_t tfm_plat_get_implementation_id(uint32_t *size,
                                                   uint8_t  *buf)
{
    /* TODO: Read SoC Family ID from SoC Identification Area */
    uint32_t dummy_implementation_id = 0xACDCABBA;

    if (*size < sizeof(dummy_implementation_id)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

     memcpy(buf, &dummy_implementation_id, sizeof(dummy_implementation_id));
     *size = sizeof(dummy_implementation_id);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_get_cert_ref(uint32_t *size, uint8_t *buf)
{
    return TFM_PLAT_ERR_UNSUPPORTED;
}

enum tfm_plat_err_t tfm_attest_hal_get_platform_config(uint32_t *size,
                                                       uint8_t  *buf)
{
    uint32_t dummy_plat_config = 0xDEADBEEF;

    if (*size < sizeof(dummy_plat_config)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

     memcpy(buf, &dummy_plat_config, sizeof(dummy_plat_config));
     *size = sizeof(dummy_plat_config);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_attest_hal_get_platform_hash_algo(uint32_t *size,
                                                          const char **buf)
{
#ifdef MEASUREMENT_HASH_ALGO_NAME
    static const char hash_algo[] = MEASUREMENT_HASH_ALGO_NAME;
#else
    static const char hash_algo[] = "not-hash-extended";
#endif

    /* Not including the null-terminator. */
    *size = (uint32_t)sizeof(hash_algo) - 1;
    *buf = hash_algo;

    return TFM_PLAT_ERR_SUCCESS;
}
