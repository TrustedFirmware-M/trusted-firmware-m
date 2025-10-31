/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fatal_error.h"
#include "lcm_drv.h"
#include "rse_provisioning_aes_key.h"
#include "rse_kmu_keys.h"
#include "device_definition.h"

static inline bool message_is_combined(const struct rse_provisioning_authentication_header_t *header)
{
    return (((header->purpose >> RSE_PROVISIONING_AUTH_MSG_PURPOSE_TYPE_OFFSET) &
             RSE_PROVISIONING_AUTH_MSG_PURPOSE_TYPE_MASK) ==
            RSE_PROVISIONING_AUTH_MSG_TYPE_COMBINED_LCS_PROVISIONING);
}

enum tfm_plat_err_t
rse_provisioning_setup_aes_key(const struct rse_provisioning_authentication_header_t *header, uint32_t *key_id)
{
    enum lcm_error_t lcm_err;
    enum tfm_plat_err_t err;
    enum lcm_lcs_t lcs;
    uint8_t *label;
    uint8_t label_len = 0;
    uint8_t *context;
    size_t context_len = 0;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    switch (lcs) {
#if defined(RSE_NON_ENDORSED_DM_PROVISIONING) || \
    defined(RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING) || \
    defined(RSE_ROTPK_REVOCATION)
    case LCM_LCS_SE:
        /* Blob not encrypted so key not required */
        *key_id = 0;
        return TFM_PLAT_ERR_SUCCESS;
#endif
    case LCM_LCS_CM:
    case LCM_LCS_DM:
        break;
    default:
        FATAL_ERR(TFM_PLAT_ERR_PROVISIONING_DERIVATION_INVALID_LCS);
        return TFM_PLAT_ERR_PROVISIONING_DERIVATION_INVALID_LCS;
    }

    if (lcs == LCM_LCS_CM || message_is_combined(header)) {
        label = (uint8_t *)"KMASTER_CM";
        label_len = sizeof("KMASTER_CM");
        context = (uint8_t *)&header->batch_id;
        context_len = sizeof(header->batch_id);
    } else {
        label = (uint8_t *)"KMASTER_DM";
        label_len = sizeof("KMASTER_DM");
        context = (uint8_t *)&header->dm_number;
        context_len = sizeof(header->dm_number);
    }

    err = rse_setup_master_key(label, label_len, context, context_len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *key_id = RSE_KMU_SLOT_PROVISIONING_KEY;

    if (lcs == LCM_LCS_CM || message_is_combined(header)) {
        label = (uint8_t *)"KPROV_CM";
        label_len = sizeof("KPROV_CM");
    } else {
        label = (uint8_t *)"KPROV_DM";
        label_len = sizeof("KPROV_DM");
    }

    return rse_setup_provisioning_key(label, label_len, NULL, 0);
}
