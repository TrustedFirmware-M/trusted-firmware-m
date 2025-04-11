/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "runtime_provisioning_hal.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_comms.h"
#include "rse_provisioning_rotpk.h"
#include "rse_provisioning_message.h"
#include "rse_persistent_data.h"
#include "tfm_hal_platform.h"
#include "region_defs.h"
#include "lcm_drv.h"
#include "device_definition.h"

/* 2KiB buffer to store provisioned blob, will be passed to
 * BL1_1 via persistent data */
static uint32_t blob_buffer[0x800 / sizeof(uint32_t)];

enum runtime_provisioning_error_t runtime_provisioning_hal_init(void)
{
    enum tfm_plat_err_t err;
    struct rse_persistent_data *persistent_data;
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return RUNTIME_PROVISIONING_GENERIC_ERROR;
    }

    /* TODO: Support other boot states for runtime provisioning */
    if (lcs != LCM_LCS_DM) {
        return RUNTIME_PROVISIONING_INVALID_STATE;
    }

    rse_get_persistent_data(&persistent_data);
    persistent_data->bl1_data.provisioning_blob_buf = blob_buffer;
    persistent_data->bl1_data.provisioning_blob_buf_size = sizeof(blob_buffer);

    err = provisioning_comms_init((struct rse_provisioning_message_t *)blob_buffer,
                                  sizeof(blob_buffer));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return RUNTIME_PROVISIONING_GENERIC_ERROR;
    }

    err = provisioning_comms_signal_ready_non_blocking();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return RUNTIME_PROVISIONING_GENERIC_ERROR;
    }

    return RUNTIME_PROVISIONING_SUCCESS;
}

enum runtime_provisioning_error_t runtime_provisioning_hal_process_message(void)
{
    enum tfm_plat_err_t err;
    bool received_full_message;

    err = provisioning_comms_receive_command_non_blocking(&received_full_message);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return RUNTIME_PROVISIONING_NO_INTERRUPT;
    }

    if (received_full_message) {
        /* Reset and let BL1 provision the blob */
        tfm_hal_system_reset();
    }

    return RUNTIME_PROVISIONING_SUCCESS;
}
