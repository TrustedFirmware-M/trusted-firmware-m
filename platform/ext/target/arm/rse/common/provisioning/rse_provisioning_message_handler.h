/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_MESSAGE_HANDLER_H__
#define __RSE_PROVISIONING_MESSAGE_HANDLER_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "rse_provisioning_message.h"

#ifdef __cplusplus
extern "C" {
#endif

enum provisioning_message_status_t {
    PROVISIONING_STATUS_SUCCESS_CONTINUE = 0x1,
    PROVISIONING_STATUS_SUCCESS_COMPLETE,
    PROVISIONING_STATUS_ERROR,
    PROVISIONING_STATUS_FORCE_UINT_SIZE = UINT32_MAX,
};

/* High hamming-weight magic values */
enum provisioning_message_report_step_t {
    PROVISIONING_REPORT_STEP_RUN_BLOB = 0x11111111,
    PROVISIONING_REPORT_STEP_SET_TP_MODE_PCI = 0x22221111,
    PROVISIONING_REPORT_STEP_SET_TP_MODE_TCI = 0x22222222,
    PROVISIONING_REPORT_STEP_VALIDATE_BLOB = 0x33333333,
    PROVISIONING_REPORT_STEP_CM_PROVISIONING = 0x44444444,
    PROVISIONING_REPORT_STEP_BL1_2_PROVISIONING = 0x44445555,
    PROVISIONING_REPORT_STEP_MANDATORY_CM_PROVISIONING = 0x55556666,
    PROVISIONING_REPORT_STEP_MANDATORY_EARLY_DM_PROVISIONING = 0x66667777,
    PROVISIONING_REPORT_STEP_OTHER_BLOB_DONE = 0x77778888,
    PROVISIONING_REPORT_STEP_PARSE_PLAIN_DATA = 0x88889999,
    PROVISIONING_REPORT_STEP_UPDATE_ROTPKS = 0x9999AAAA,
    PROVISIONING_REPORT_STEP_GENERATE_CERTIFICATE = 0xBBBBAAAA,
    PROVISIONING_REPORT_STEP_VERIFY_CERTIFICATE = 0xCCCCAAAA,
    PROVISIONING_REPORT_STEP_FORCE_UINT_SIZE = UINT32_MAX,
};

struct provisioning_message_status_report_t {
    enum provisioning_message_status_t type;
    enum provisioning_message_report_step_t report_step;
    uint32_t error_code;
    uint32_t reserved;
};

struct provisioning_message_handler_config {
    enum tfm_plat_err_t (*blob_handler)(const struct rse_provisioning_message_blob_t *, size_t, const void *);
    enum tfm_plat_err_t (*cert_handler)(const struct rse_provisioning_message_cert_t *, size_t, const void *);
    enum tfm_plat_err_t (*plain_data_handler)(const struct rse_provisioning_message_plain_t *, size_t, const void *);
};

enum tfm_plat_err_t handle_provisioning_message(const struct rse_provisioning_message_t *msg, size_t msg_size,
                                                struct provisioning_message_handler_config *config, void *ctx);

enum tfm_plat_err_t
message_handling_status_report_continue(enum provisioning_message_report_step_t step);

enum tfm_plat_err_t
message_handling_status_report_error(enum provisioning_message_report_step_t step, uint32_t error);

enum tfm_plat_err_t message_provisioning_finished(enum provisioning_message_report_step_t step);

static inline bool
rse_provisioning_message_is_valid(const struct rse_provisioning_message_t *message)
{
    const enum rse_provisioning_message_type_t msg_type = message->header.type;

    return (msg_type == RSE_PROVISIONING_MESSAGE_TYPE_BLOB) ||
           (msg_type == RSE_PROVISIONING_MESSAGE_TYPE_CERTIFICATE) ||
           (msg_type == RSE_PROVISIONING_MESSAGE_TYPE_PLAIN_DATA);
}

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_MESSAGE_HANDLER_H__ */
