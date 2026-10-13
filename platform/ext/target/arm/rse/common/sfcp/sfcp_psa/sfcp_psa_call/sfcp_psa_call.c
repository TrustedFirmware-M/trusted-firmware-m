/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sfcp_psa_call.h"

static struct sfcp_psa_call_context_t context;
static const struct sfcp_psa_client_config_t config = {
    .node_id = 0,
    .application_id = 0,
    .client_id = 1,
    .embed_limit = (16 - 2) * sizeof(uint32_t),
};

psa_status_t psa_call(psa_handle_t handle, int32_t type, const psa_invec *in_vec, size_t in_len,
                      psa_outvec *out_vec, size_t out_len)
{
    return sfcp_psa_call(&context, &config, handle, type, in_vec, in_len, out_vec, out_len);
}
