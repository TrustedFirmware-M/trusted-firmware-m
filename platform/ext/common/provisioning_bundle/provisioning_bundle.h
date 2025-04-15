/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PROVISIONING_BUNDLE_H__
#define __PROVISIONING_BUNDLE_H__

#include "stdint.h"
#include "region_defs.h"
#include "cmsis_compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUNDLE_MAGIC 0xC0DEFEED

#ifdef MCUBOOT_SIGN_EC384
#define PUB_KEY_HASH_SIZE (48)
#define PUB_KEY_SIZE      (100) /* Size must be aligned to 4 Bytes */
#else
#define PUB_KEY_HASH_SIZE (32)
#define PUB_KEY_SIZE      (68)  /* Size must be aligned to 4 Bytes */
#endif /* MCUBOOT_SIGN_EC384 */

#ifdef MCUBOOT_BUILTIN_KEY
#define PROV_ROTPK_DATA_SIZE    PUB_KEY_SIZE
#else
#define PROV_ROTPK_DATA_SIZE    PUB_KEY_HASH_SIZE
#endif /* MCUBOOT_BUILTIN_KEY */

__PACKED_STRUCT tfm_assembly_and_test_provisioning_data_t {
    uint8_t huk[32];
};

__PACKED_STRUCT tfm_psa_rot_provisioning_data_t {
    uint8_t iak[32];
    uint32_t iak_len;
    uint32_t iak_type;
#if ATTEST_INCLUDE_COSE_KEY_ID
    uint8_t iak_id[32];
#endif /* ATTEST_INCLUDE_COSE_KEY_ID */

    uint8_t boot_seed[32];
    uint8_t implementation_id[32];
    uint8_t cert_ref[32];
    uint8_t verification_service_url[32];
    uint8_t profile_definition[48];

    uint8_t entropy_seed[64];
};

__PACKED_STRUCT bl2_assembly_and_test_provisioning_data_t {
#ifdef MCUBOOT_ROTPK_SIGN_POLICY
    uint32_t bl2_rotpk_policies;
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */
    uint8_t bl2_rotpk_0[PROV_ROTPK_DATA_SIZE];
    uint8_t bl2_rotpk_1[PROV_ROTPK_DATA_SIZE];
#if (MCUBOOT_IMAGE_NUMBER > 2)
    uint8_t bl2_rotpk_2[PROV_ROTPK_DATA_SIZE];
#endif
#if (MCUBOOT_IMAGE_NUMBER > 3)
    uint8_t bl2_rotpk_3[PROV_ROTPK_DATA_SIZE];
#endif

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    uint8_t secure_debug_pk[32];
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */
};

__PACKED_STRUCT provisioning_data_t {
    const struct bl2_assembly_and_test_provisioning_data_t bl2_assembly_and_test_prov_data;
    const struct tfm_assembly_and_test_provisioning_data_t assembly_and_test_prov_data;
    const struct tfm_psa_rot_provisioning_data_t psa_rot_prov_data;
};

struct __attribute__((__packed__)) provisioning_bundle {
    /* This section is authenticated */
    uint32_t magic;

    uint8_t code[PROVISIONING_BUNDLE_CODE_SIZE];
    union __attribute__((__packed__)) {
        const struct provisioning_data_t values;
        const uint8_t _pad[PROVISIONING_BUNDLE_VALUES_SIZE];
    };
    uint8_t data[PROVISIONING_BUNDLE_DATA_SIZE];
    /* This section is metadata */
    uint8_t tag[16];
    uint32_t magic2;
};

#ifdef __cplusplus
}
#endif

#endif /* __PROVISIONING_BUNDLE_H__ */
