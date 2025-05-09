/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __PSA_API_BROKER_DEFS_H__
#define __PSA_API_BROKER_DEFS_H__

#include <stddef.h>
#include <stdint.h>

#include "psa/client.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Forward declarations for API functions for TrustZone Interface
 */
uint32_t psa_framework_version_tz(void);
uint32_t psa_version_tz(uint32_t sid);
psa_status_t psa_call_tz(
    psa_handle_t handle,
    int32_t type,
    const psa_invec *in_vec,
    size_t in_len,
    psa_outvec *out_vec,
    size_t out_len);
psa_handle_t psa_connect_tz(uint32_t sid, uint32_t version);
void psa_close_tz(psa_handle_t handle);

/*
 * Forward declarations for API functions for Multi Core Interface
 */
uint32_t psa_framework_version_multicore(void);
uint32_t psa_version_multicore(uint32_t sid);
psa_status_t psa_call_multicore(
    psa_handle_t handle,
    int32_t type,
    const psa_invec *in_vec,
    size_t in_len,
    psa_outvec *out_vec,
    size_t out_len);
void psa_close_multicore(psa_handle_t handle);
psa_handle_t psa_connect_multicore(uint32_t sid, uint32_t version);

#ifdef __cplusplus
}
#endif

#endif /* __PSA_API_BROKER_DEFS_H__ */
