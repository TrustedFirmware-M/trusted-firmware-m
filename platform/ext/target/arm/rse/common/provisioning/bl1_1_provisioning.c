/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "rse_provisioning_message.h"
#include "tfm_plat_provisioning.h"

#include "region_defs.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_message_status.h"
#include "rse_provisioning_blob_handler.h"
#include "device_definition.h"
#include "tfm_log.h"
#include "tfm_hal_platform.h"
#include "rse_provisioning_aes_key.h"
#include "rse_provisioning_rotpk.h"
#include "rse_persistent_data.h"
#include "rse_provisioning_get_message.h"

#include <assert.h>
#include <string.h>

static inline bool blob_is_in_sram(const struct rse_provisioning_message_t *message, size_t size)
{
    uintptr_t message_ptr = (uintptr_t)message;

    return (message_ptr <= (UINTPTR_MAX - size)) && (message_ptr >= VM0_BASE_S) &&
           ((message_ptr + size) <= (VM0_BASE_S + VM0_SIZE + VM1_SIZE));
}

void tfm_plat_provisioning_check_for_dummy_keys(void)
{
    /* FixMe: Check for dummy key must be implemented */
}

enum tfm_plat_err_t tfm_plat_provisioning_is_required(bool *provisioning_required)
{
    enum lcm_error_t err;
    enum lcm_lcs_t lcs;

    if (provisioning_required == NULL) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    *provisioning_required = (lcs == LCM_LCS_CM || lcs == LCM_LCS_DM);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_provisioning_perform(void)
{
    INFO("Beginning RSE provisioning\n");
    enum tfm_plat_err_t err;
    const struct rse_provisioning_message_t *provisioning_message =
        (const struct rse_provisioning_message_t *)PROVISIONING_MESSAGE_START;
    size_t provisioning_message_size = RSE_PROVISIONING_MESSAGE_MAX_SIZE;
#ifdef RSE_BOOT_IN_DM_LCS
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;
#endif

    struct provisioning_message_handler_config config = {
        .blob_handler = &default_blob_handler,
    };

    struct default_blob_handler_ctx_t ctx = {
        .setup_aes_key = rse_provisioning_setup_aes_key,
#ifdef RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES
        .get_rotpk = provisioning_rotpk_get,
#endif
        .blob_is_chainloaded = false,
    };

#ifdef RSE_BOOT_IN_DM_LCS
    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
#endif /* RSE_BOOT_IN_DM_LCS */

    /*
     * If a blob is present in the SRAM persistent data because it has been
     * stashed there by runtime provisioning comms handling. This could be
     * for DM LCS provisioning and therefore we check this before the LCS
     * state
     */
    if (rse_get_provisioning_staging_status() == PROVISIONING_STAGING_STATUS_RUNTIME_MESSAGE) {
        const struct rse_provisioning_message_t *message =
            (const struct rse_provisioning_message_t *)
                RSE_PERSISTENT_DATA->bl1_data.provisioning_blob_buf;
        size_t size = RSE_PERSISTENT_DATA->bl1_data.provisioning_blob_buf_size;

        /* Blob must be in SRAM */
        if (!blob_is_in_sram(message, size)) {
            return TFM_PLAT_ERR_PROVISIONING_MESSAGE_INVALID_LOCATION;
        }

        provisioning_message = message;
        provisioning_message_size = size;
#ifdef RSE_BOOT_IN_DM_LCS
    } else if (lcs == LCM_LCS_DM) {
        return TFM_PLAT_ERR_SUCCESS;
#endif
    } else {
        err = rse_provisioning_get_message(provisioning_message, provisioning_message_size,
                                           PROVISIONING_STAGING_STATUS_BL1_1_MESSAGE);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    err = handle_provisioning_message(provisioning_message, provisioning_message_size, &config,
                                      (void *)&ctx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        memset((void *)provisioning_message, 0, provisioning_message_size);
        rse_set_provisioning_staging_status(PROVISIONING_STAGING_STATUS_NO_MESSAGE);
        message_handling_status_report_error(PROVISIONING_REPORT_STEP_RUN_BLOB, err);
        return err;
    }

    tfm_hal_system_reset();

    return TFM_PLAT_ERR_SUCCESS;
}
