/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_provisioning.h"

#include "cmsis_compiler.h"
#include "tfm_plat_otp.h"
#include "tfm_attest_hal.h"
#include "psa/crypto.h"
#include "bootutil/bootutil_log.h"

#include <string.h>

#define ASSEMBLY_AND_TEST_PROV_DATA_MAGIC 0xC0DEFEED

#ifdef MCUBOOT_ROTPK_SIGN_POLICY
/* Key policy for each ROTPK
 * bit 0 corresponds to bl2_rotpk_0,
 * bit 1 coresponds to bl2_rotpk_1,
 * ...
 * If bit set, key is compulsory else optional
 */
#define BL2_ROTPK_POLICIES 0b00000111
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

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

__PACKED_STRUCT bl2_assembly_and_test_provisioning_data_t {
    uint32_t magic;
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

#ifdef TFM_DUMMY_PROVISIONING

#if !defined(MCUBOOT_BUILTIN_KEY)
/* List of BL2 Root of Trust public key hashes */
#if defined(MCUBOOT_SIGN_RSA)
#if (MCUBOOT_SIGN_RSA_LEN == 2048)
/* SHA-256 hashes of RSA-2048 public keys (in PKCS#1 format)
 *    DATA_KIND_0: hash of PK(bl2/ext/mcuboot/root-RSA-2048.pem)
 *    DATA_KIND_1: hash of PK(bl2/ext/mcuboot/root-RSA-2048_1.pem)
 */
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_0 {            \
        0xfc, 0x57, 0x01, 0xdc, 0x61, 0x35, 0xe1, 0x32, \
        0x38, 0x47, 0xbd, 0xc4, 0x0f, 0x04, 0xd2, 0xe5, \
        0xbe, 0xe5, 0x83, 0x3b, 0x23, 0xc2, 0x9f, 0x93, \
        0x59, 0x3d, 0x00, 0x01, 0x8c, 0xfa, 0x99, 0x94, \
    }
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_1 {            \
        0xe1, 0x80, 0x15, 0x99, 0x3d, 0x6d, 0x27, 0x60, \
        0xb4, 0x99, 0x27, 0x4b, 0xae, 0xf2, 0x64, 0xb8, \
        0x3a, 0xf2, 0x29, 0xe9, 0xa7, 0x85, 0xf3, 0xd5, \
        0xbf, 0x00, 0xb9, 0xd3, 0x2c, 0x1f, 0x03, 0x96, \
    }
#elif (MCUBOOT_SIGN_RSA_LEN == 3072)
/* SHA-256 hashes of RSA-3072 public keys (in PKCS#1 format)
 *    DATA_KIND_0: hash of PK(bl2/ext/mcuboot/root-RSA-3072.pem)
 *    DATA_KIND_1: hash of PK(bl2/ext/mcuboot/root-RSA-3072_1.pem)
 */
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_0 {            \
        0xbf, 0xe6, 0xd8, 0x6f, 0x88, 0x26, 0xf4, 0xff, \
        0x97, 0xfb, 0x96, 0xc4, 0xe6, 0xfb, 0xc4, 0x99, \
        0x3e, 0x46, 0x19, 0xfc, 0x56, 0x5d, 0xa2, 0x6a, \
        0xdf, 0x34, 0xc3, 0x29, 0x48, 0x9a, 0xdc, 0x38, \
    }
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_1 {            \
        0xb3, 0x60, 0xca, 0xf5, 0xc9, 0x8c, 0x6b, 0x94, \
        0x2a, 0x48, 0x82, 0xfa, 0x9d, 0x48, 0x23, 0xef, \
        0xb1, 0x66, 0xa9, 0xef, 0x6a, 0x6e, 0x4a, 0xa3, \
        0x7c, 0x19, 0x19, 0xed, 0x1f, 0xcc, 0xc0, 0x49, \
    }
#endif /* MCUBOOT_SIGN_RSA_LEN */
#elif defined(MCUBOOT_SIGN_EC256)
/* SHA-256 hashes of EC-P256 public keys
 * (in SubjectPublicKeyInfo format, see RFC5480)
 *    DATA_KIND_0: hash of PK(bl2/ext/mcuboot/root-EC-P256.pem)
 *    DATA_KIND_1: hash of PK(bl2/ext/mcuboot/root-EC-P256_1.pem)
 */
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_0 {            \
        0xe3, 0x04, 0x66, 0xf6, 0xb8, 0x47, 0x0c, 0x1f, \
        0x29, 0x07, 0x0b, 0x17, 0xf1, 0xe2, 0xd3, 0xe9, \
        0x4d, 0x44, 0x5e, 0x3f, 0x60, 0x80, 0x87, 0xfd, \
        0xc7, 0x11, 0xe4, 0x38, 0x2b, 0xb5, 0x38, 0xb6, \
    }
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_1 {            \
        0x82, 0xa5, 0xb4, 0x43, 0x59, 0x48, 0x53, 0xd4, \
        0xbf, 0x0f, 0xdd, 0x89, 0xa9, 0x14, 0xa5, 0xdc, \
        0x16, 0xf8, 0x67, 0x54, 0x82, 0x07, 0xd7, 0x07, \
        0x7e, 0x74, 0xd8, 0x0c, 0x06, 0x3e, 0xfd, 0xa9, \
    }
#elif defined(MCUBOOT_SIGN_EC384)
/* SHA-384 hashes of EC-P384 public keys
 * (in SubjectPublicKeyInfo format, see RFC5480)
 *    DATA_KIND_0: hash of PK(bl2/ext/mcuboot/root-EC-P384.pem)
 *    DATA_KIND_1: hash of PK(bl2/ext/mcuboot/root-EC-P384_1.pem)
 */
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_0 {            \
        0x85, 0xb7, 0xbd, 0x5f, 0x5d, 0xff, 0x9a, 0x03, \
        0xa9, 0x99, 0x27, 0xad, 0xaf, 0x6c, 0xa6, 0xfe, \
        0xbd, 0xe8, 0x22, 0xc1, 0xa4, 0x80, 0x92, 0x83, \
        0x24, 0xa8, 0xe6, 0x03, 0x23, 0x71, 0x5c, 0x57, \
        0x79, 0x46, 0x1c, 0x49, 0x6a, 0x95, 0xae, 0xe8, \
        0xc4, 0xf9, 0x0b, 0x99, 0x77, 0x9f, 0x84, 0x8a, \
    }
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_1 {            \
        0xae, 0x13, 0xb7, 0x1d, 0xae, 0x49, 0xa7, 0xb8, \
        0x9d, 0x4d, 0x8e, 0xe5, 0x09, 0x5c, 0xb8, 0xd4, \
        0x5a, 0x32, 0xbd, 0x9c, 0x7d, 0x50, 0x1c, 0xd3, \
        0xb8, 0xf8, 0x6c, 0xbc, 0x8b, 0x41, 0x43, 0x9b, \
        0x1b, 0x22, 0x5c, 0xc3, 0x6a, 0x5b, 0xa8, 0x08, \
        0x1d, 0xf0, 0x71, 0xe0, 0xcb, 0xbc, 0x61, 0x92, \
    }
#endif /* MCUBOOT_SIGN_RSA */

#else /* !MCUBOOT_BUILTIN_KEY */
/* List of BL2 Root of Trust public keys */
#if defined(MCUBOOT_SIGN_EC256)
/* EC-P256 public keys
 * (raw keys as subjectPublicKey (bit string), see RFC5480)
 *    DATA_KIND_0: PK(bl2/ext/mcuboot/root-EC-P256.pem)
 *    DATA_KIND_1: PK(bl2/ext/mcuboot/root-EC-P256_1.pem)
 */
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_0 {            \
        0x04, 0x2a, 0xcb, 0x40, 0x3c, 0xe8, 0xfe, 0xed, \
        0x5b, 0xa4, 0x49, 0x95, 0xa1, 0xa9, 0x1d, 0xae, \
        0xe8, 0xdb, 0xbe, 0x19, 0x37, 0xcd, 0x14, 0xfb, \
        0x2f, 0x24, 0x57, 0x37, 0xe5, 0x95, 0x39, 0x88, \
        0xd9, 0x94, 0xb9, 0xd6, 0x5a, 0xeb, 0xd7, 0xcd, \
        0xd5, 0x30, 0x8a, 0xd6, 0xfe, 0x48, 0xb2, 0x4a, \
        0x6a, 0x81, 0x0e, 0xe5, 0xf0, 0x7d, 0x8b, 0x68, \
        0x34, 0xcc, 0x3a, 0x6a, 0xfc, 0x53, 0x8e, 0xfa, \
        0xc1,                                           \
    }
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_1 {            \
        0x04, 0xe8, 0x09, 0x08, 0x12, 0x3a, 0x0f, 0xad, \
        0x40, 0xe0, 0x33, 0x8a, 0xa6, 0x54, 0xf8, 0x83, \
        0x95, 0x41, 0x8e, 0x44, 0x99, 0xa2, 0x0f, 0xae, \
        0x85, 0x69, 0x2b, 0xf9, 0x26, 0xb5, 0xe9, 0x9e, \
        0x16, 0x2c, 0x87, 0x76, 0x62, 0x7f, 0x32, 0x6c, \
        0x9b, 0x70, 0x78, 0x06, 0x52, 0x52, 0x52, 0xca, \
        0x2b, 0xd2, 0xb7, 0xc7, 0x50, 0x07, 0x66, 0x3b, \
        0x3b, 0xdf, 0xe1, 0x99, 0x69, 0x00, 0x26, 0x2c, \
        0x33,                                           \
    }
#elif defined(MCUBOOT_SIGN_EC384)
/* EC-P384 public keys
 * (raw keys as subjectPublicKey (bit string), see RFC5480)
 *    DATA_KIND_0: PK(bl2/ext/mcuboot/root-EC-P384.pem)
 *    DATA_KIND_1: PK(bl2/ext/mcuboot/root-EC-P384_1.pem)
 */
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_0 {      0x04, \
        0x0c, 0x76, 0xca, 0xae, 0x72, 0x3a, 0xa5, 0xe8, \
        0xf0, 0xd4, 0xf1, 0x16, 0xb5, 0x02, 0xef, 0x77, \
        0xa1, 0x1b, 0x93, 0x61, 0x78, 0xc0, 0x09, 0x26, \
        0x7b, 0x3b, 0x40, 0x9c, 0xee, 0x49, 0x85, 0xe0, \
        0xc9, 0x4f, 0xe7, 0xf2, 0xba, 0x97, 0x6c, 0xf3, \
        0x82, 0x65, 0x14, 0x2c, 0xf5, 0x0c, 0x73, 0x33, \
        0x4d, 0x32, 0xe7, 0x9b, 0xd3, 0x42, 0xcc, 0x95, \
        0x5a, 0xe5, 0xe2, 0xf5, 0xf4, 0x6e, 0x45, 0xe0, \
        0xed, 0x20, 0x35, 0x5c, 0xaf, 0x52, 0x35, 0x81, \
        0xd4, 0xdc, 0x9c, 0xe3, 0x9e, 0x22, 0x3e, 0xfb, \
        0x3f, 0x22, 0x10, 0xda, 0x70, 0x03, 0x37, 0xad, \
        0xa8, 0xf2, 0x48, 0xfe, 0x3a, 0x60, 0x69, 0xa5, \
    }
#define ASSEMBLY_AND_TEST_PROV_DATA_KIND_1 {      0x04, \
        0x34, 0x43, 0xad, 0x59, 0x83, 0xd9, 0x41, 0x65, \
        0xdc, 0x20, 0xb8, 0x62, 0x35, 0xf8, 0x7d, 0x94, \
        0x13, 0x5e, 0x75, 0xe6, 0xa8, 0x79, 0xe9, 0xcb, \
        0xfd, 0xa7, 0x2e, 0x92, 0x95, 0x82, 0xa6, 0xc5, \
        0xdd, 0x53, 0xc7, 0x3d, 0x46, 0xed, 0x75, 0xd5, \
        0x20, 0xb5, 0xbe, 0x74, 0x2a, 0x6d, 0x30, 0xe2, \
        0x31, 0x50, 0x1c, 0x7f, 0xc7, 0x7b, 0x4a, 0x73, \
        0x55, 0xf8, 0x92, 0x60, 0xff, 0x2f, 0x18, 0x04, \
        0xbc, 0xc7, 0xd9, 0xce, 0xda, 0xa6, 0x36, 0x52, \
        0xec, 0x2b, 0x64, 0x6e, 0x7a, 0x97, 0x60, 0x9d, \
        0x8c, 0xba, 0xfe, 0xec, 0x9a, 0xb0, 0xc2, 0x6e, \
        0x3d, 0x75, 0x2a, 0x98, 0xb2, 0xa3, 0x09, 0x84, \
    }
#endif /* MCUBOOT_SIGN_EC256 */
#endif /* !MCUBOOT_BUILTIN_KEY */

static const struct bl2_assembly_and_test_provisioning_data_t bl2_assembly_and_test_prov_data = {
    ASSEMBLY_AND_TEST_PROV_DATA_MAGIC,
#ifdef MCUBOOT_ROTPK_SIGN_POLICY
    BL2_ROTPK_POLICIES,
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

#if defined(MCUBOOT_SIGN_RSA)
#if (MCUBOOT_SIGN_RSA_LEN == 2048)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 0 */
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_1, /* bl2 rotpk 1 */
#if (MCUBOOT_IMAGE_NUMBER > 2)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 2 */
#endif
#if (MCUBOOT_IMAGE_NUMBER > 3)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 3 */
#endif

#elif (MCUBOOT_SIGN_RSA_LEN == 3072)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 0 */
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_1, /* bl2 rotpk 1 */
#if (MCUBOOT_IMAGE_NUMBER > 2)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 2 */
#endif
#if (MCUBOOT_IMAGE_NUMBER > 3)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 3 */
#endif
#endif /* MCUBOOT_SIGN_RSA_LEN */

#elif defined(MCUBOOT_SIGN_EC256)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 0 */
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_1, /* bl2 rotpk 1 */
#if MCUBOOT_IMAGE_NUMBER > 2
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 2 */
#endif
#if MCUBOOT_IMAGE_NUMBER > 3
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 3 */
#endif

#elif defined(MCUBOOT_SIGN_EC384)
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 0 */
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_1, /* bl2 rotpk 1 */
#if MCUBOOT_IMAGE_NUMBER > 2
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 2 */
#endif
#if MCUBOOT_IMAGE_NUMBER > 3
    ASSEMBLY_AND_TEST_PROV_DATA_KIND_0, /* bl2 rotpk 3 */
#endif
#else
#error "No public key available for given signing algorithm."
#endif /* MCUBOOT_SIGN_RSA */

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    {
        0xf4, 0x0c, 0x8f, 0xbf, 0x12, 0xdb, 0x78, 0x2a,
        0xfd, 0xf4, 0x75, 0x96, 0x6a, 0x06, 0x82, 0x36,
        0xe0, 0x32, 0xab, 0x80, 0xd1, 0xb7, 0xf1, 0xbc,
        0x9f, 0xe7, 0xd8, 0x7a, 0x88, 0xcb, 0x26, 0xd0,
    },
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */
};
#else
static const struct bl2_assembly_and_test_provisioning_data_t bl2_assembly_and_test_prov_data;
#endif /* TFM_DUMMY_PROVISIONING */

void tfm_plat_provisioning_check_for_dummy_keys(void)
{
    uint64_t iak_start;

    tfm_plat_otp_read(PLAT_OTP_ID_IAK, sizeof(iak_start), (uint8_t*)&iak_start);

    if(iak_start == 0xA4906F6DB254B4A9) {
        BOOT_LOG_WRN("%s%s%s%s",
                     "\033[1;31m",
                     "This device was provisioned with dummy keys. ",
                     "This device is \033[1;1mNOT SECURE",
                     "\033[0m");
    }

    memset(&iak_start, 0, sizeof(iak_start));
}

enum tfm_plat_err_t tfm_plat_provisioning_is_required(bool *provisioning_required)
{
    enum tfm_plat_err_t err;
    enum plat_otp_lcs_t lcs;

    if (provisioning_required == NULL) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(lcs), (uint8_t*)&lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *provisioning_required = (lcs == PLAT_OTP_LCS_ASSEMBLY_AND_TEST)
                          || (lcs == PLAT_OTP_LCS_PSA_ROT_PROVISIONING);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t provision_assembly_and_test(void)
{
    enum tfm_plat_err_t err;

    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_0,
                             sizeof(bl2_assembly_and_test_prov_data.bl2_rotpk_0),
                             bl2_assembly_and_test_prov_data.bl2_rotpk_0);
    if ((err != TFM_PLAT_ERR_SUCCESS) && (err != TFM_PLAT_ERR_UNSUPPORTED)) {
        return err;
    }
    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_1,
                             sizeof(bl2_assembly_and_test_prov_data.bl2_rotpk_1),
                             bl2_assembly_and_test_prov_data.bl2_rotpk_1);
    if ((err != TFM_PLAT_ERR_SUCCESS) && (err != TFM_PLAT_ERR_UNSUPPORTED)) {
        return err;
    }
#if (MCUBOOT_IMAGE_NUMBER > 2)
    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_2,
                             sizeof(bl2_assembly_and_test_prov_data.bl2_rotpk_2),
                             bl2_assembly_and_test_prov_data.bl2_rotpk_2);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* MCUBOOT_IMAGE_NUMBER > 2 */
#if (MCUBOOT_IMAGE_NUMBER > 3)
    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_3,
                             sizeof(bl2_assembly_and_test_prov_data.bl2_rotpk_3),
                             bl2_assembly_and_test_prov_data.bl2_rotpk_3);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* MCUBOOT_IMAGE_NUMBER > 3 */

#ifdef MCUBOOT_ROTPK_SIGN_POLICY
    /* Write the ROTPK policies */
    err = tfm_plat_otp_write(PLAT_OTP_ID_BL2_ROTPK_POLICIES,
                             sizeof(bl2_assembly_and_test_prov_data.bl2_rotpk_policies),
                             (uint8_t *)&bl2_assembly_and_test_prov_data.bl2_rotpk_policies);
    if ((err != TFM_PLAT_ERR_SUCCESS) && (err != TFM_PLAT_ERR_UNSUPPORTED)) {
        return err;
    }
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    err = tfm_plat_otp_write(PLAT_OTP_ID_SECURE_DEBUG_PK,
                             sizeof(bl2_assembly_and_test_prov_data.secure_debug_pk),
                             bl2_assembly_and_test_prov_data.secure_debug_pk);
    if (err != TFM_PLAT_ERR_SUCCESS && err != TFM_PLAT_ERR_UNSUPPORTED) {
        return err;
    }
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

    return err;
}

enum tfm_plat_err_t tfm_plat_provisioning_perform(void)
{
    enum tfm_plat_err_t err;
    enum plat_otp_lcs_t lcs;

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(lcs), (uint8_t*)&lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    BOOT_LOG_INF("Beginning BL2 provisioning");

#ifdef TFM_DUMMY_PROVISIONING
    BOOT_LOG_WRN("%s%s%s%s",
                 "\033[1;31m",
                 "TFM_DUMMY_PROVISIONING is not suitable for production! ",
                 "This device is \033[1;1mNOT SECURE",
                 "\033[0m");
#endif /* TFM_DUMMY_PROVISIONING */

    if (lcs == PLAT_OTP_LCS_ASSEMBLY_AND_TEST) {
        if (bl2_assembly_and_test_prov_data.magic != ASSEMBLY_AND_TEST_PROV_DATA_MAGIC) {
            BOOT_LOG_ERR("No valid ASSEMBLY_AND_TEST provisioning data found");
            return TFM_PLAT_ERR_INVALID_INPUT;
        }

        err = tfm_plat_otp_secure_provisioning_start();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        err = provision_assembly_and_test();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        err = tfm_plat_otp_secure_provisioning_finish();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}
