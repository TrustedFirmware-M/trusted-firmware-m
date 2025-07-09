/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "provisioning/rse_provisioning_message_handler.h"
#include "tfm_plat_otp.h"
#include "rse_provisioning_plain_data_handler.h"
#include "rse_provisioning_values.h"
#include "rse_rotpk_revocation.h"
#include "rse_asn1_encoding.h"
#include "rse_get_soc_info_reg.h"
#include "lcm_drv.h"
#include "device_definition.h"
#include "rse_otp_dev.h"

#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
static enum tfm_plat_err_t
handle_non_endorsed_dm_rotpks(const struct rse_provisioning_message_plain_t *plain_data,
                              size_t data_size, struct non_endorsed_provisioning_ctx_s *ctx)
{
    enum tfm_plat_err_t plat_err;
    uint32_t policies_flags;
    struct rse_non_endorsed_dm_provisioning_values_t *non_endorsed_values;

    if (data_size != sizeof(struct rse_non_endorsed_dm_provisioning_values_t)) {
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_INVALID_SIZE;
    }

    non_endorsed_values = (struct rse_non_endorsed_dm_provisioning_values_t *)plain_data->data;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_CM_CONFIG_FLAGS, sizeof(policies_flags),
                                 (uint8_t *)&policies_flags);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    if (!rse_otp_policy_check(policies_flags, CM_POLICIES_DM_PROVISIONING_NON_ENDORSED_FLOW)) {
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_INVALID_CM_POLICY;
    }

    plat_err = rse_update_dm_rotpks(non_endorsed_values->non_endorsed_dm_rotpk_policies,
                                    (uint8_t *)non_endorsed_values->rotpk,
                                    sizeof(non_endorsed_values->rotpk));
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    message_provisioning_finished(PROVISIONING_REPORT_STEP_UPDATE_ROTPKS);
    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* RSE_NON_ENDORSED_DM_PROVISIONING */

#ifdef RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING
static enum tfm_plat_err_t
handle_endorsement_certificate(const struct rse_provisioning_message_plain_t *plain_data,
                               size_t data_size,
                               struct endorsement_certificate_provisioning_ctx_s *ctx)
{
    enum tfm_plat_err_t plat_err;
    enum lcm_error_t lcm_err;
    struct rse_endorsement_certificate_provisioning_values_t *endorsement_cert_vals;
    /* Static to avoid large stack usage */
    static struct rse_asn1_iak_endorsement_cert_provisioned_params_s provisioned_params;
    static struct rse_asn1_iak_endorsement_cert_dynamic_params_s dynamic_params;
    static struct rse_asn1_pk_s signing_params;
    static uint32_t soc_uid[sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id) / sizeof(uint32_t)];
    static uint32_t rak_pub[sizeof(P_RSE_OTP_CM->cod.rak_pub) / sizeof(uint32_t)];

    if (data_size < (96 + ENDORSEMENT_CERT_SKI_LENGTH)) {
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_INVALID_SIZE;
    }

    endorsement_cert_vals =
        (struct rse_endorsement_certificate_provisioning_values_t *)plain_data->data;

    /* Assume fixed SKI size */
    provisioned_params.endorsement_cert_ski =
        endorsement_cert_vals->endorsement_certificate_parameters;
    provisioned_params.endorsement_cert_ski_size = ENDORSEMENT_CERT_SKI_LENGTH;

    /* ECDSA384 with SHA384 signature is 96 bytes */
    provisioned_params.signature = endorsement_cert_vals->endorsement_certificate_signature;
    provisioned_params.signature_size = 96;

    plat_err = rse_get_soc_info_reg(&dynamic_params.soc_info_reg_val);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.unique_id),
                           sizeof(soc_uid), (uint8_t *)soc_uid);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    dynamic_params.soc_uid = (uint8_t *)soc_uid;
    dynamic_params.soc_uid_size = sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id);

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->cod.rak_pub), sizeof(rak_pub),
                           (uint8_t *)rak_pub);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    dynamic_params.rak_pub = (uint8_t *)rak_pub;
    dynamic_params.rak_pub_size = sizeof(rak_pub);

    plat_err = rse_asn1_iak_endorsement_cert_generate(&provisioned_params, &dynamic_params);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    message_handling_status_report_continue(PROVISIONING_REPORT_STEP_GENERATE_CERTIFICATE);

    signing_params.public_key_x = ctx->signing_pk.x;
    signing_params.public_key_x_size = ctx->signing_pk.x_size;
    signing_params.public_key_y = ctx->signing_pk.y;
    signing_params.public_key_y_size = ctx->signing_pk.y_size;

    plat_err = rse_asn1_iak_endorsement_cert_verify(&signing_params);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Provisioning values verified, we are good to write them to OTP */
    lcm_err = lcm_otp_write(
        &LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DYNAMIC->iak_endorsement_certificate_signature), 96,
        (const uint8_t *)endorsement_cert_vals->endorsement_certificate_signature);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_otp_write(
        &LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DYNAMIC->iak_endorsement_certificate_parameters),
        ENDORSEMENT_CERT_SKI_LENGTH,
        (const uint8_t *)endorsement_cert_vals->endorsement_certificate_parameters);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    message_provisioning_finished(PROVISIONING_REPORT_STEP_VERIFY_CERTIFICATE);
    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING */

enum tfm_plat_err_t
default_plain_data_handler(const struct rse_provisioning_message_plain_t *plain_data,
                           size_t msg_size, const void *ctx)
{
#if defined(RSE_NON_ENDORSED_DM_PROVISIONING) || defined(RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
    struct default_plain_data_handler_ctx_s *plain_data_ctx =
        (struct default_plain_data_handler_ctx_s *)ctx;
#endif /* RSE_NON_ENDORSED_DM_PROVISIONING || RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING */

    if (msg_size < sizeof(*plain_data)) {
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_NO_TYPE;
    }

    switch (plain_data->plain_metadata) {
#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
    case RSE_PROVISIONING_PLAIN_DATA_TYPE_NON_ENDORSED_DM_ROTPKS:
        return handle_non_endorsed_dm_rotpks(
            plain_data,
            msg_size - sizeof(*plain_data),
            &plain_data_ctx->non_endorsed_provisioning_ctx);
#endif /* RSE_NON_ENDORSED_DM_PROVISIONING */
#ifdef RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING
    case RSE_PROVISIONING_PLAIN_DATA_TYPE_ENDORSEMENT_CERTIFICATE_PACKAGE:
        return handle_endorsement_certificate(
            plain_data,
            msg_size - sizeof(*plain_data),
            &plain_data_ctx->endorsement_certificate_provisioning_ctx);
#endif /* RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING */
    default:
        return TFM_PLAT_ERR_PROVISIONING_PLAIN_DATA_TYPE_INVALID;
    }
}
