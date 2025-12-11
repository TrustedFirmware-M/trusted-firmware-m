/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * This file contains the definitions for the IFX MTB Mailbox PSA client
 * interface.
 */

#ifndef IFX_MTB_MAILBOX_H
#define IFX_MTB_MAILBOX_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "psa/client.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IFX_ MTB Mailbox PSA client call type value */
#define IFX_MTB_MAILBOX_PSA_FRAMEWORK_VERSION       (0x1)
#define IFX_MTB_MAILBOX_PSA_VERSION                 (0x2)
#define IFX_MTB_MAILBOX_PSA_CONNECT                 (0x3)
#define IFX_MTB_MAILBOX_PSA_CALL                    (0x4)
#define IFX_MTB_MAILBOX_PSA_CLOSE                   (0x5)

/* Return code of IFX MTB mailbox APIs */
#define IFX_MTB_MAILBOX_SUCCESS                     (0)
#define IFX_MTB_MAILBOX_INVAL_PARAMS                (INT32_MIN + 1)
#define IFX_MTB_MAILBOX_GENERIC_ERROR               (INT32_MIN + 2)

/*
 * This structure holds the parameters used in a MTB Mailbox PSA client call.
 */
typedef struct {
    union {
        struct {
            uint32_t        sid;
        } psa_version_params;

        struct {
            uint32_t        sid;
            uint32_t        version;
        } psa_connect_params;

        struct {
            psa_handle_t    handle;
            int32_t         type;
            psa_invec       in_vec[PSA_MAX_IOVEC];
            size_t          in_len;
            psa_outvec      out_vec[PSA_MAX_IOVEC];
            size_t          out_len;
        } psa_call_params;

        struct {
            psa_handle_t    handle;
        } psa_close_params;
    } psa_params;
} ifx_psa_client_params_t;

/*
 * IFX MTB Mailbox reply structure to hold the IFX MTB PSA client call return
 * result from SPE
 */
typedef struct {
    int32_t    return_val;
    size_t     out_vec_len[PSA_MAX_IOVEC];  /* The size in bytes of the psa_call output vector */
} ifx_mtb_mailbox_reply_t;

/**
 * \brief Send PSA client call to on core NSPE via MTB mailbox. Wait and fetch
 *        PSA client call result.
 *
 * \param[in] call_type         PSA client call type
 * \param[in] params            Parameters used for PSA client call
 * \param[out] reply            The buffer written with PSA client call result.
 *
 * \retval MAILBOX_SUCCESS      The PSA client call is completed successfully.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t ifx_mtb_mailbox_client_call(uint32_t call_type,
                                    const ifx_psa_client_params_t *params,
                                    ifx_mtb_mailbox_reply_t *reply);

#ifdef __cplusplus
}
#endif

#endif /* IFX_MTB_MAILBOX_H */
