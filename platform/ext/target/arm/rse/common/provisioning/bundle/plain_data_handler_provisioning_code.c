/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <string.h>

#include "platform_error_codes.h"
#include "region_defs.h"
#include "rse_provisioning_message.h"
#include "rse_provisioning_message_handler.h"
#include "rse_provisioning_plain_data_handler.h"
#include "rse_provisioning_get_message.h"
#include "tfm_log.h"

#ifdef RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING
/* Dummy keys, these will be replaced by the public key required to verify the
 * signature of the generated certificate */
static const uint8_t __attribute__((aligned(sizeof(uint32_t)))) public_key_x[48] = {
    [0 ... 47] = 0xAB,
};

static const uint8_t __attribute__((aligned(sizeof(uint32_t)))) public_key_y[48] = {
    [0 ... 47] = 0xCD,
};
#endif

__attribute__((section("DO_PROVISION"))) enum tfm_plat_err_t do_provision(void) {
    enum tfm_plat_err_t err;
    const struct rse_provisioning_message_t *provisioning_message =
    (const struct rse_provisioning_message_t *)PROVISIONING_MESSAGE_START;

    struct provisioning_message_handler_config config = {
        .plain_data_handler = &default_plain_data_handler,
    };

    struct default_plain_data_handler_ctx_s ctx = {
#ifdef RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING
        .endorsement_certificate_provisioning_ctx = {
            .signing_pk = {
                .x = (uint32_t *)public_key_x,
                .x_size = sizeof(public_key_x),
                .y = (uint32_t *)public_key_y,
                .y_size = sizeof(public_key_y)
            },
        },
#endif /* RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING */
    };

    INFO("Provisioning plain data message\n");

    err = rse_provisioning_get_message(provisioning_message, RSE_PROVISIONING_MESSAGE_MAX_SIZE,
                                       PROVISIONING_STAGING_STATUS_PLAIN_DATA_MESSAGE);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = handle_provisioning_message(provisioning_message, RSE_PROVISIONING_MESSAGE_MAX_SIZE,
                                      &config, &ctx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        memset((void *)provisioning_message, 0, RSE_PROVISIONING_MESSAGE_MAX_SIZE);
        rse_set_provisioning_staging_status(PROVISIONING_STAGING_STATUS_NO_MESSAGE);
        message_handling_status_report_error(PROVISIONING_REPORT_STEP_PARSE_PLAIN_DATA, err);
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
