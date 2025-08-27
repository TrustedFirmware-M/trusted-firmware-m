/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_PSA_CLIENT_REQUEST_H__
#define __RSE_COMMS_PSA_CLIENT_REQUEST_H__

#include "psa/client.h"
#include "cmsis_compiler.h"
#include "config_tfm.h"
#include "rse_comms_atu.h"
#include "rse_comms_psa_protocol.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Allocated for each client request.
 *
 * TODO: Sizing of payload_buf, this should be platform dependent:
 * - sum in_vec size
 * - sum out_vec size
 */
struct client_request_t {
    uint8_t remote_id;
    uint8_t protocol_ver;
    uint16_t client_id;
    psa_handle_t handle;
    int32_t type;
    uint32_t in_len;
    uint32_t out_len;
    psa_invec in_vec[PSA_MAX_IOVEC];
    psa_outvec out_vec[PSA_MAX_IOVEC];
    int32_t return_val;
    uint64_t out_vec_host_addr[PSA_MAX_IOVEC];
    uint8_t param_copy_buf[RSE_COMMS_PSA_EMBED_PAYLOAD_MAX_SIZE];
    comms_atu_region_set_t atu_regions;
};

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_PSA_CLIENT_REQUEST_H__ */
