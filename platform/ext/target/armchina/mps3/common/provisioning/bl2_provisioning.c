/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_provisioning.h"
#include "tfm_plat_otp.h"
#include "tfm_attest_hal.h"
#include "region_defs.h"
#include "bootutil/bootutil_log.h"
#include "string.h"
#include "provisioning_bundle.h"

static const volatile struct provisioning_bundle *encrypted_bundle =
(const struct provisioning_bundle *)PROVISIONING_BUNDLE_START;

static enum tfm_plat_err_t provision_assembly_and_test(void);

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

enum tfm_plat_err_t tfm_plat_provisioning_perform(void)
{
    enum tfm_plat_err_t err;
    enum plat_otp_lcs_t lcs;

    err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(lcs), (uint8_t*)&lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    BOOT_LOG_INF("Beginning provisioning");
#ifdef TFM_DUMMY_PROVISIONING
    BOOT_LOG_WRN("%s%s%s%s",
                 "\033[1;31m",
                 "TFM_DUMMY_PROVISIONING is not suitable for production! ",
                 "This device is \033[1;1mNOT SECURE",
                 "\033[0m");
#endif /* TFM_DUMMY_PROVISIONING */

    if (lcs == PLAT_OTP_LCS_ASSEMBLY_AND_TEST) {

        BOOT_LOG_INF("Waiting for provisioning bundle");
        while (encrypted_bundle->magic != BUNDLE_MAGIC ||
               encrypted_bundle->magic2 != BUNDLE_MAGIC) {
        }

        err = provision_assembly_and_test();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t provision_assembly_and_test(void)
{
    enum tfm_plat_err_t err;

    /* TODO replace this with decrypt and auth */
    memcpy((void*)PROVISIONING_BUNDLE_CODE_START,
           (void *)encrypted_bundle->code,
           PROVISIONING_BUNDLE_CODE_SIZE);
    memcpy((void*)PROVISIONING_BUNDLE_DATA_START,
           (void *)&encrypted_bundle->data,
           PROVISIONING_BUNDLE_DATA_SIZE);
    memcpy((void*)PROVISIONING_BUNDLE_VALUES_START,
           (void *)&encrypted_bundle->values,
           PROVISIONING_BUNDLE_VALUES_SIZE);

    BOOT_LOG_INF("Running provisioning bundle");
    err = ((enum tfm_plat_err_t (*)(void))(PROVISIONING_BUNDLE_CODE_START | 0b1))();

    memset((void *)PROVISIONING_BUNDLE_CODE_START, 0,
           PROVISIONING_BUNDLE_CODE_SIZE);
    memset((void *)PROVISIONING_BUNDLE_DATA_START, 0,
           PROVISIONING_BUNDLE_DATA_SIZE);
    memset((void *)PROVISIONING_BUNDLE_VALUES_START, 0,
           PROVISIONING_BUNDLE_VALUES_SIZE);

    return err;
}
