/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_NS_MAILBOX_H
#define TFM_NS_MAILBOX_H

#include <stdbool.h>
#include <stdint.h>

#include "tfm_mailbox.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IFX MTB mailbox is used to provide communication layer */
#define tfm_ns_mailbox_client_call ifx_mtb_mailbox_client_call

/**
 * \brief Send PSA client call to on core NSPE via MTB mailbox. Wait and fetch
 *        PSA client call result.
 *
 * \param[in] call_type         PSA client call type
 * \param[in] params            Parameters used for PSA client call
 * \param[in] client_id         Optional client ID of non-secure caller.
 *                              It is required to identify the non-secure caller
 *                              when NSPE OS enforces non-secure task isolation.
 * \param[out] reply            The buffer written with PSA client call result.
 *
 * \retval MAILBOX_SUCCESS      The PSA client call is completed successfully.
 * \retval Other return code    Operation failed with an error code.
 */
int32_t ifx_mtb_mailbox_client_call(uint32_t call_type,
                                    const struct psa_client_params_t *params,
                                    int32_t client_id,
                                    struct mailbox_reply_t *reply);

#ifdef __cplusplus
}
#endif

#endif /* TFM_NS_MAILBOX_H */
