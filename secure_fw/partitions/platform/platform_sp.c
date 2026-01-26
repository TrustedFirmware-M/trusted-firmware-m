/*
 * Copyright (c) 2018-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "config_tfm.h"
#include "platform_sp.h"

#include "tfm_platform_system.h"
#include "load/partition_defs.h"
#include "psa_manifest/pid.h"

#if !PLATFORM_NV_COUNTER_MODULE_DISABLED
#include "tfm_plat_nv_counters.h"
#endif /* !PLATFORM_NV_COUNTER_MODULE_DISABLED */

#include "psa/client.h"
#include "psa/service.h"
#include "region_defs.h"
#include "psa_manifest/tfm_platform.h"
#include "coverity_check.h"

#if !PLATFORM_NV_COUNTER_MODULE_DISABLED
#define NV_COUNTER_ID_SIZE  sizeof(enum tfm_nv_counter_t)
#define NV_COUNTER_SIZE     4
#endif /* !PLATFORM_NV_COUNTER_MODULE_DISABLED */

typedef enum tfm_platform_err_t (*plat_func_t)(const psa_msg_t *msg);

enum tfm_platform_err_t platform_sp_system_reset(void)
{
    /* FIXME: The system reset functionality is only supported in isolation
     *        level 1.
     */

    tfm_platform_hal_system_reset();

    return TFM_PLATFORM_ERR_SUCCESS;
}

static psa_status_t platform_sp_system_reset_psa_api(const psa_msg_t *msg)
{
    (void)msg; /* unused parameter */

    return platform_sp_system_reset();
}

#if !PLATFORM_NV_COUNTER_MODULE_DISABLED
static psa_status_t platform_sp_nv_read_psa_api(const psa_msg_t *msg)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SYSTEM_ERR;
    size_t in_len = PSA_MAX_IOVEC, out_len = PSA_MAX_IOVEC, num = 0;

    enum tfm_nv_counter_t counter_id;
    uint8_t counter_val[NV_COUNTER_SIZE] = {0};

    /* Check the number of in_vec filled */
    while ((in_len > 0) && (msg->in_size[in_len - 1] == 0)) {
        in_len--;
    }

    /* Check the number of out_vec filled */
    while ((out_len > 0) && (msg->out_size[out_len - 1] == 0)) {
        out_len--;
    }

    if ((msg->in_size[0] != NV_COUNTER_ID_SIZE) ||
        (msg->out_size[0] > NV_COUNTER_SIZE) ||
        (in_len != 1) || (out_len != 1)) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    num = psa_read(msg->handle, 0, &counter_id, msg->in_size[0]);
    if (num != NV_COUNTER_ID_SIZE) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    if (msg->client_id < 0) {
        err = tfm_plat_ns_counter_idx_to_nv_counter(counter_id, &counter_id);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return TFM_PLATFORM_ERR_INVALID_PARAM;
        }
    }

    err = tfm_plat_nv_counter_permissions_check(msg->client_id, counter_id, false);
    if (err != TFM_PLAT_ERR_SUCCESS) {
       return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    err = tfm_plat_read_nv_counter(counter_id,  msg->out_size[0],
                                   counter_val);

    if (err != TFM_PLAT_ERR_SUCCESS) {
       return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    psa_write(msg->handle, 0, counter_val, msg->out_size[0]);

    return TFM_PLATFORM_ERR_SUCCESS;
}

static psa_status_t platform_sp_nv_increment_psa_api(const psa_msg_t *msg)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SYSTEM_ERR;
    size_t in_len = PSA_MAX_IOVEC, out_len = PSA_MAX_IOVEC, num = 0;

    enum tfm_nv_counter_t counter_id;

    /* Check the number of in_vec filled */
    while ((in_len > 0) && (msg->in_size[in_len - 1] == 0)) {
        in_len--;
    }

    /* Check the number of out_vec filled */
    while ((out_len > 0) && (msg->out_size[out_len - 1] == 0)) {
        out_len--;
    }

    if ((msg->in_size[0] != NV_COUNTER_ID_SIZE) ||
        (in_len != 1) || (out_len != 0)) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    num = psa_read(msg->handle, 0, &counter_id, msg->in_size[0]);
    if (num != NV_COUNTER_ID_SIZE) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    if (msg->client_id < 0) {
        err = tfm_plat_ns_counter_idx_to_nv_counter(counter_id, &counter_id);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return TFM_PLATFORM_ERR_INVALID_PARAM;
        }
    }

    err = tfm_plat_nv_counter_permissions_check(msg->client_id, counter_id, false);
    if (err != TFM_PLAT_ERR_SUCCESS) {
       return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    err = tfm_plat_increment_nv_counter(counter_id);

    if (err != TFM_PLAT_ERR_SUCCESS) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}
#endif /* !PLATFORM_NV_COUNTER_MODULE_DISABLED*/

static psa_status_t platform_sp_ioctl_psa_api(const psa_msg_t *msg)
{
    void *input = NULL;
    void *output = NULL;
    psa_invec invec = {0};
    psa_outvec outvec = {0};
    uint8_t input_buffer[PLATFORM_SERVICE_INPUT_BUFFER_SIZE] = {0};
    uint8_t output_buffer[PLATFORM_SERVICE_OUTPUT_BUFFER_SIZE] = {0};
    tfm_platform_ioctl_req_t request = 0;
    enum tfm_platform_err_t ret = TFM_PLATFORM_ERR_SYSTEM_ERROR;
    int num = 0;
    uint32_t in_len = PSA_MAX_IOVEC;
    uint32_t out_len = PSA_MAX_IOVEC;
    size_t input_size;

    while ((in_len > 0) && (msg->in_size[in_len - 1] == 0)) {
        in_len--;
    }

    while ((out_len > 0) && (msg->out_size[out_len - 1] == 0)) {
        out_len--;
    }

    if ((in_len < 1) || (in_len > 2) ||
        (out_len > 1)) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    num = psa_read(msg->handle, 0, &request, sizeof(request));
    if (num != sizeof(request)) {
        return (enum tfm_platform_err_t) PSA_ERROR_PROGRAMMER_ERROR;
    }

    if (in_len > 1) {
        input_size = msg->in_size[1];
        if (input_size > PLATFORM_SERVICE_INPUT_BUFFER_SIZE) {
            return (enum tfm_platform_err_t) PSA_ERROR_BUFFER_TOO_SMALL;
        }
        num = psa_read(msg->handle, 1, &input_buffer, msg->in_size[1]);
        if (num != input_size) {
            return (enum tfm_platform_err_t) PSA_ERROR_PROGRAMMER_ERROR;
        }
        invec.base = input_buffer;
        invec.len = input_size;
        input = &invec;
    }

    if (out_len > 0) {
        if (msg->out_size[0] > PLATFORM_SERVICE_OUTPUT_BUFFER_SIZE) {
            return (enum tfm_platform_err_t) PSA_ERROR_PROGRAMMER_ERROR;
        }
        outvec.base = output_buffer;
        outvec.len = msg->out_size[0];
        output = &outvec;
    }

    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_11_5, "It's PSA API design to use pointer to void")
    ret = tfm_platform_hal_ioctl(request, input, output);

    if (output != NULL) {
        psa_write(msg->handle, 0, outvec.base, outvec.len);
    }

    return ret;
}

psa_status_t tfm_platform_service_sfn(const psa_msg_t *msg)
{
    switch (msg->type) {
#if !PLATFORM_NV_COUNTER_MODULE_DISABLED
    case TFM_PLATFORM_API_ID_NV_READ:
        return platform_sp_nv_read_psa_api(msg);
    case TFM_PLATFORM_API_ID_NV_INCREMENT:
        return platform_sp_nv_increment_psa_api(msg);
#endif /* PLATFORM_NV_COUNTER_MODULE_DISABLED */
    case TFM_PLATFORM_API_ID_SYSTEM_RESET:
        return platform_sp_system_reset_psa_api(msg);
    case TFM_PLATFORM_API_ID_IOCTL:
        return platform_sp_ioctl_psa_api(msg);
    default:
        return PSA_ERROR_NOT_SUPPORTED;
    }
}

psa_status_t platform_sp_init(void)
{
#if !PLATFORM_NV_COUNTER_MODULE_DISABLED
    /* Initialise the non-volatile counters */
    enum tfm_plat_err_t err;

    err = tfm_plat_init_nv_counter();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return PSA_ERROR_HARDWARE_FAILURE;
    }
#endif /* PLATFORM_NV_COUNTER_MODULE_DISABLED */

    return PSA_SUCCESS;
}
