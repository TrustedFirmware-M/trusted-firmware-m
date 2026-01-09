/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "dtpm_client_partition_hal.h"
#include "device_definition.h"
#include "tfm_plat_defs.h"
#include "tfm_log.h"
#include "tfm_utils.h"

#include "tfm_plat_otp.h"
#include "psa/crypto.h"

#define DEVICE_STATUS_FUNCTIONAL_STATUS_OFFSET 15
#define DEVICE_STATUS_FUNCTIONAL_STATUS_DEVICE_FUNCTIONAL 0x0

struct platform_security_config {
    enum tfm_plat_err_t (*security_config_function)(struct security_config_data *security_config);
    event_log_metadata_t evlog_security_config_metadata;
};

/* This implementation is platform-specific. The determination of TCG_INSECURE_LIFECYCLE
 * may depend on additional system attributes not reflected in the implementation below.
 */
static enum tfm_plat_err_t get_tcg_insecure_lifecycle(struct security_config_data *security_config)
{
    enum lcm_error_t lcm_err;
    enum tfm_plat_err_t err;

    enum lcm_lcs_t lcs;
    enum lcm_tp_mode_t mode;
    uint32_t device_status;
    uint16_t functional_status;

    bool tcg_insecure_lifecycle = true;
    const char tcg_insecure_lifecycle_name[] = "TCG_INSECURE_LIFECYCLE";

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    err = tfm_plat_otp_read(PLAT_OTP_ID_DEVICE_STATUS, sizeof(device_status),
                           (uint8_t *)&device_status);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    functional_status = device_status >> DEVICE_STATUS_FUNCTIONAL_STATUS_OFFSET;

    if ((lcs == LCM_LCS_SE) && (mode == LCM_TP_MODE_PCI) &&
        (functional_status == DEVICE_STATUS_FUNCTIONAL_STATUS_DEVICE_FUNCTIONAL)) {
        tcg_insecure_lifecycle = false;
    }

    if (sizeof(tcg_insecure_lifecycle_name) > MAX_SECURITY_CONFIG_NAME_LEN) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    security_config->name_length = sizeof(tcg_insecure_lifecycle_name);
    memcpy(&security_config->name, tcg_insecure_lifecycle_name, security_config->name_length);

    security_config->data_length = sizeof(bool);
    security_config->config_data[0] = (uint8_t)tcg_insecure_lifecycle;

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t get_tcg_debug(struct security_config_data *security_config)
{
    enum lcm_error_t lcm_err;
    int i;
    uint32_t dcu_state[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    bool tcg_debug = false;
    const char tcg_debug_name[] = "TCG_DEBUG";

    lcm_err = lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)&dcu_state);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    for (i = 0; i < sizeof(dcu_state)/sizeof(uint32_t); i++) {
        if (dcu_state[i]) {
            tcg_debug = true;
            break;
        }
    }

    if (sizeof(tcg_debug_name) > MAX_SECURITY_CONFIG_NAME_LEN) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    security_config->name_length = sizeof(tcg_debug_name);
    memcpy(&security_config->name, tcg_debug_name, security_config->name_length);

    security_config->data_length = sizeof(bool);
    security_config->config_data[0] = (uint8_t)tcg_debug;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_get_security_config_data(struct security_config *security_config,
                                                      size_t *security_config_len,
                                                      size_t security_config_max_len)
{
    enum tfm_plat_err_t err;
    size_t arr_index;

    struct platform_security_config platform_sec_config[] = {
        {get_tcg_insecure_lifecycle, {INSECURE_LIFECYCLE_EVENT_ID, "TCG_INSECURE_LIFECYCLE", 1}},
        {get_tcg_debug, {DEBUG_EVENT_ID, "TCG_DEBUG", 1}},
    };

    size_t platform_sec_config_len = ARRAY_SIZE(platform_sec_config);

    if (platform_sec_config_len > security_config_max_len) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    for (arr_index = 0; arr_index < platform_sec_config_len; arr_index++) {
        err = platform_sec_config[arr_index].security_config_function(
                                  &security_config[arr_index].security_config_data);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        security_config[arr_index].hash_type = PSA_ALG_SHA_256;
        security_config[arr_index].pcr_index = 1;

        memcpy(&security_config[arr_index].event_log_metadata,
               &platform_sec_config[arr_index].evlog_security_config_metadata,
               sizeof(event_log_metadata_t));

    }

    *security_config_len = arr_index;

    return TFM_PLAT_ERR_SUCCESS;
}
