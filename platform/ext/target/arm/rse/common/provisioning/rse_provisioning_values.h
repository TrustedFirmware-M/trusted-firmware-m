/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_VALUES_H__
#define __RSE_PROVISIONING_VALUES_H__

#include "rse_otp_layout.h"
#include "rse_provisioning_config.h"

#ifdef __cplusplus
extern "C" {
#endif

struct __attribute__((__packed__)) rse_non_secret_cm_provisioning_values_t {
    struct rse_otp_area_info_t cm_area_info;
    struct rse_otp_area_info_t bl1_2_area_info;
#ifndef RSE_OTP_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    struct rse_otp_area_info_t dm_area_info;
    struct rse_otp_area_info_t dynamic_area_info;
#endif

    uint8_t otp_dma_ics[RSE_OTP_DMA_ICS_SIZE];
    uint32_t otp_dma_ics_size;

    struct rse_otp_cm_area_t cm;
    struct rse_otp_bl1_2_area_t bl1_2;
};

struct __attribute__((__packed__)) rse_secret_cm_provisioning_values_t {
    uint8_t guk[32];
    uint8_t kp_cm[32];
    uint8_t kce_cm[32];
};

struct __attribute__((__packed__)) rse_non_secret_dm_provisioning_values_t {
#ifdef RSE_OTP_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    struct rse_otp_area_info_t dm_area_info;
    struct rse_otp_area_info_t dynamic_area_info;
#endif

    struct rse_otp_dm_area_t dm;
};

struct __attribute__((__packed__)) rse_secret_dm_provisioning_values_t {
    uint8_t kp_dm[32];
    uint8_t kce_dm[32];
};

#ifdef RSE_COMBINED_PROVISIONING_BUNDLES
struct __attribute__((__packed__)) rse_non_secret_combined_provisioning_values_t {
    struct rse_non_secret_cm_provisioning_values_t cm;
    struct rse_non_secret_dm_provisioning_values_t dm;
};

struct __attribute__((__packed__)) rse_secret_combined_provisioning_values_t {
    struct rse_secret_cm_provisioning_values_t cm;
    struct rse_secret_dm_provisioning_values_t dm;
};
#endif

struct __attribute__((__packed__)) rse_non_endorsed_dm_provisioning_values_t {
    uint32_t non_endorsed_dm_rotpk_policies;
    uint8_t rotpk[RSE_OTP_DM_ROTPK_AMOUNT][RSE_OTP_DM_ROTPK_SIZE];
};

struct __attribute__((packed)) rse_endorsement_certificate_provisioning_values_t {
    uint8_t endorsement_certificate_signature[RSE_OTP_ENDORSEMENT_CERTIFICATE_SIGNATURE_SIZE];
    uint8_t endorsement_certificate_parameters[RSE_OTP_ENDORSEMENT_CERTIFICATE_PARAMETERS_SIZE];
};

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_VALUES_H__ */
