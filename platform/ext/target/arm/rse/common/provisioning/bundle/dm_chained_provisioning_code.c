/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <stdint.h>

#include "region_defs.h"
#include "tfm_plat_defs.h"
#include "rse_provisioning_message.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_blob_handler.h"
#include "rse_provisioning_rotpk.h"
#include "rse_provisioning_tci_key.h"
#include "rse_provisioning_message_status.h"
#include "cc3xx_drv.h"
#include "device_definition.h"
#include "tfm_log.h"
#include "rse_kmu_keys.h"
#include "rse_provisioning_get_message.h"
#include "rse_persistent_data.h"

#ifndef TFM_DUMMY_PROVISIONING
extern const uint8_t pci_rotpk_x[];
extern const uint8_t pci_rotpk_y[];

extern const size_t pci_rotpk_x_len;
extern const size_t pci_rotpk_y_len;
#endif /* TFM_DUMMY_PROVISIONING */

/* For now, use the same key as in the main provisioning flow, but
 * note that there is no reason why this has to be the case
 */
static enum tfm_plat_err_t get_rotpk(const struct rse_provisioning_message_blob_t *blob,
                                     uint32_t **public_key_x,
                                     size_t *public_key_x_size,
                                     uint32_t **public_key_y,
                                     size_t *public_key_y_size)
{
#ifdef TFM_DUMMY_PROVISIONING
    *public_key_x = (uint32_t *)tci_rotpk_x;
    *public_key_y = (uint32_t *)tci_rotpk_y;
    *public_key_x_size = tci_rotpk_x_len;
    *public_key_y_size = tci_rotpk_y_len;
#else
    enum lcm_error_t lcm_err;
    enum lcm_tp_mode_t tp_mode;

    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    switch(tp_mode) {
    case LCM_TP_MODE_TCI:
        *public_key_x = (uint32_t *)tci_rotpk_x;
        *public_key_y = (uint32_t *)tci_rotpk_y;
        *public_key_x_size = tci_rotpk_x_len;
        *public_key_y_size = tci_rotpk_y_len;
        break;
    default:
        *public_key_x = (uint32_t *)pci_rotpk_x;
        *public_key_y = (uint32_t *)pci_rotpk_y;
        *public_key_x_size = pci_rotpk_x_len;
        *public_key_y_size = pci_rotpk_y_len;
    }
#endif /* TFM_DUMMY_PROVISIONING */

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t aes_setup_key(const struct rse_provisioning_message_blob_t *blob,
                                         uint32_t *key_id)
{
    /* Key already setup */
    *key_id = RSE_KMU_SLOT_PROVISIONING_KEY;

    return TFM_PLAT_ERR_SUCCESS;
}

__attribute__((section("DO_JUMP")))
__attribute__((naked))
void do_jump(void)
{
    /* No link as want to return straight back to ROM code */
    __asm volatile(
        "b do_provision\n"
    );
}

__attribute__((section("DO_PROVISION"))) enum tfm_plat_err_t do_provision(void) {
    enum tfm_plat_err_t err;
    const struct rse_provisioning_message_t *provisioning_message =
    (const struct rse_provisioning_message_t *)PROVISIONING_MESSAGE_START;

    struct provisioning_message_handler_config config = {
        .blob_handler = &default_blob_handler,
    };

    struct default_blob_handler_ctx_t ctx = {
        .setup_aes_key = aes_setup_key,
#ifdef RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES
        .get_rotpk = get_rotpk,
#endif
        .blob_is_chainloaded = true,
    };

    INFO("Provisioning next blob\n");

    err = rse_provisioning_get_message(provisioning_message, RSE_PROVISIONING_MESSAGE_MAX_SIZE,
                                       PROVISIONING_STAGING_STATUS_DM_CHAINED);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = handle_provisioning_message(provisioning_message,
                                      RSE_PROVISIONING_MESSAGE_MAX_SIZE,
                                      &config, (void *)&ctx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        memset((void *)provisioning_message, 0, RSE_PROVISIONING_MESSAGE_MAX_SIZE);
        rse_set_provisioning_staging_status(PROVISIONING_STAGING_STATUS_NO_MESSAGE);
        message_handling_status_report_error(PROVISIONING_REPORT_STEP_RUN_BLOB, err);
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
