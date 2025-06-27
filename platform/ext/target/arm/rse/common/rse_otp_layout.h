/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_OTP_LAYOUT_H__
#define __RSE_OTP_LAYOUT_H__

#include <stdint.h>

#include "rse_otp_config.h"
#include "lcm_otp_layout.h"
#include "rse_routing_tables.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __PACKED_STRUCT
#define __PACKED_STRUCT struct __attribute__((packed))
#endif

#ifndef __PACKED_UNION
#define __PACKED_UNION union __attribute__((packed))
#endif

#define ROUND_UP(x, bound) ((((x) + bound - 1) / bound) * bound)
#define ALIGN(x, bound) ROUND_UP(x, bound)

#define COUNTER_BYTES(x) ALIGN((ROUND_UP((x), 8) / 8), 4)

__PACKED_STRUCT rse_otp_area_info_t {
    __PACKED_UNION {
        __PACKED_STRUCT {
            uint16_t offset;
            uint16_t size;
        };
        uint32_t raw_data;
    };
};

__PACKED_STRUCT rse_otp_header_area_t {
    struct lcm_otp_hardware_area_t lcm_hardware_area;

    struct rse_otp_area_info_t cm_area_info;
    uint32_t cm_area_info_zero_count;
    struct rse_otp_area_info_t bl1_2_area_info;
    uint32_t bl1_2_area_info_zero_count;
    struct rse_otp_area_info_t dm_area_info;
    uint32_t dm_area_info_zero_count;
    struct rse_otp_area_info_t dynamic_area_info;
    uint32_t dynamic_area_info_zero_count;
    struct rse_otp_area_info_t soc_area_info;
    uint32_t soc_area_info_zero_count;

#ifdef RSE_OTP_HAS_KRTL_USAGE_COUNTER
    uint8_t krtl_usage_counter[COUNTER_BYTES(RSE_OTP_KRTL_COUNTER_MAX_VALUE)];
#endif
#ifdef RSE_OTP_HAS_LFT_COUNTER
    uint8_t lft_counter[COUNTER_BYTES(RSE_OTP_LFT_COUNTER_MAX_VALUE)];
#endif

    uint32_t device_status;

#ifdef RSE_OTP_HEADER_SUBPLATFORM_ITEMS
    struct rse_otp_subplatform_header_area_t subplatform;
#endif

    uint32_t dma_ics_size;
    uint8_t dma_ics[RSE_OTP_DMA_ICS_SIZE];
};

struct rse_otp_cm_rotpk_area_t {
    uint32_t zero_count;
    uint32_t cm_rotpk_policies;
    uint8_t rotpk[RSE_OTP_CM_ROTPK_AMOUNT][RSE_OTP_CM_ROTPK_SIZE];
};

__PACKED_STRUCT rse_otp_cod_cm_area_t {
    uint8_t cod_cmac[RSE_OTP_COD_CMAC_SIZE];
    uint8_t rak_pub[RSE_OTP_COD_RAK_PUB_SIZE];
};

__PACKED_STRUCT rse_otp_cm_area_t {
    uint32_t zero_count;
    uint32_t provisioning_blob_version;
    uint32_t config_flags;

#ifdef RSE_OTP_HAS_CCA_ITEMS
    uint32_t cca_system_properties;
#endif
#ifdef RSE_OTP_HAS_RSE_ID
    uint32_t rse_id;
#endif

#ifdef RSE_OTP_CM_SUBPLATFORM_ITEMS
    struct rse_otp_subplatform_cm_area_t subplatform;
#endif

    struct rse_otp_cod_cm_area_t cod;

    uint8_t reserved[RSE_OTP_CM_RESERVED_SIZE];
    struct rse_otp_cm_rotpk_area_t rotpk_areas[RSE_OTP_CM_ROTPK_MAX_REVOCATIONS + 1];
};

__PACKED_STRUCT rse_otp_bl1_2_area_t {
    uint32_t zero_count;
    uint32_t bl1_2_size;
    uint32_t version;
    uint8_t bl1_2_hash[RSE_OTP_BL1_2_HASH_SIZE];

#ifdef RSE_OTP_BL1_2_SUBPLATFORM_ITEMS
    struct rse_otp_subplatform_bl1_2_area_t subplatform;
#endif

    uint8_t bl1_2[RSE_OTP_BL1_2_MAX_SIZE];
};

struct rse_otp_dm_rotpk_area_t {
    uint32_t zero_count;
    uint32_t dm_rotpk_policies;
    uint8_t rotpk[RSE_OTP_DM_ROTPK_AMOUNT][RSE_OTP_DM_ROTPK_SIZE];
};

__PACKED_STRUCT rse_otp_dm_area_t {
    uint32_t zero_count;
    uint32_t provisioning_blob_version;
    uint32_t config_flags;

#ifdef RSE_OTP_HAS_ROUTING_TABLES
    struct rse_single_node_routing_tables_t routing_tables;
#endif

#ifdef RSE_OTP_DM_SUBPLATFORM_ITEMS
    struct rse_otp_subplatform_dm_area_t subplatform;
#endif

    uint8_t reserved[RSE_OTP_DM_RESERVED_SIZE];

    struct rse_otp_dm_rotpk_area_t rotpk_areas[RSE_OTP_DM_ROTPK_MAX_REVOCATIONS + 1];
};

__PACKED_STRUCT rse_otp_dynamic_area_t {
    uint8_t cm_reprovisioning[COUNTER_BYTES(RSE_OTP_MAX_REPROVISIONINGS)];
    uint8_t cm_rotpk_revocation[COUNTER_BYTES(RSE_OTP_CM_ROTPK_MAX_REVOCATIONS)];
    uint8_t dm_rotpk_revocation[COUNTER_BYTES(RSE_OTP_DM_ROTPK_MAX_REVOCATIONS)];
    uint8_t reserved_counters[RSE_OTP_RESERVED_COUNTER_BYTES];
    /* 4 banks of NV counters are provided. Each bank must be a fixed size, so
     * there can be up to 4 different sizes of NV counters in the unlocked area,
     * but with unlimited amounts of each size of counter.
     */
    uint8_t security_version_counters_bank_0[RSE_OTP_NV_COUNTERS_BANK_0_AMOUNT][COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_0_MAX_VALUE)];
    uint8_t security_version_counters_bank_1[RSE_OTP_NV_COUNTERS_BANK_1_AMOUNT][COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_1_MAX_VALUE)];
    uint8_t security_version_counters_bank_2[RSE_OTP_NV_COUNTERS_BANK_2_AMOUNT][COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_2_MAX_VALUE)];
    uint8_t security_version_counters_bank_3[RSE_OTP_NV_COUNTERS_BANK_3_AMOUNT][COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_3_MAX_VALUE)];

#ifdef RSE_OTP_HAS_ENDORSEMENT_CERTIFICATE
    uint8_t iak_endorsement_certificate_signature[RSE_OTP_ENDORSEMENT_CERTIFICATE_SIGNATURE_SIZE];
    uint8_t iak_endorsement_certificate_parameters[RSE_OTP_ENDORSEMENT_CERTIFICATE_PARAMETERS_SIZE];
#endif

#ifdef RSE_OTP_DYNAMIC_SUBPLATFORM_ITEMS
    struct rse_otp_subplatform_dynamic_area_t subplatform;
#endif
};

__PACKED_STRUCT rse_otp_soc_area_t {
    __PACKED_STRUCT {
        uint32_t zero_count_unique_id;
        uint8_t unique_id[12];
        uint32_t zero_count_id;
        uint8_t family_id[4];
        uint8_t ieee_ecid[16];
    } soc_id_area;

    __PACKED_STRUCT {
        uint32_t soc_cfg_data_zc;
        uint32_t soc_cfg_data_size;
#ifdef RSE_OTP_SOC_SUBPLATFORM_ITEMS
        struct rse_otp_subplatform_soc_area_t subplatform;
#endif
        uint8_t reserved[RSE_OTP_SOC_RESERVED_SIZE];
    } soc_cfg_area;
};

/* Accessor macros for CM defined policies specified at
 * the CM area (offset: 0x0C, size: 0x04). Each policy
 * is specified through the corresponding bit value
 */
enum rse_otp_cm_policies_t {
    CM_POLICIES_VHUK_AGREEMENT_REQUIRED                = 0x0,
    CM_POLICIES_LFT_COUNTER_MAX_BRICKS_DEVICE          = 0x1,
    CM_POLICIES_DM_PROVISIONING_RTL_KEY_BASED          = 0x2,
    CM_POLICIES_DM_PROVISIONING_PUBLIC_KEY_ENDORSEMENT = 0x3,
    CM_POLICIES_DM_PROVISIONING_NON_ENDORSED_FLOW      = 0x4, /*!< ownership taking in LCS == SE */
    CM_POLICIES_DM_PROVISIONING_RESERVED               = 0x5,

    _CM_POLICIES_MAX_VALUE = UINT32_MAX
};

/**
 * @brief Given the CM policies flags, check the desired policy
 *
 * @param[in] policies_flags  A word containing the CM defined policies
 * @param[in] policy_to_check Policy to be checked
 *
 * @return 1 The corresponding policy is true
 * @return 0 The corresponding policy is false
 */
static inline uint8_t rse_otp_policy_check(uint32_t policies_flags, enum rse_otp_cm_policies_t policy_to_check)
{
    return (((policies_flags >> policy_to_check) & 0b1) == 1) ? 1 : 0;
}

#ifdef __cplusplus
}
#endif

#endif /* __RSE_OTP_LAYOUT_H__ */
