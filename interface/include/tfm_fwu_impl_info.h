/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_FWU_IMPL_INFO_H__
#define __TFM_FWU_IMPL_INFO_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef FWU_DEVICE_CONFIG_FILE
#include FWU_DEVICE_CONFIG_FILE
#else
#include "psa/fwu_config.h"
#endif

/**
 * @brief The implementation-specific data in the component information
 *        structure.
 */
typedef struct {
    /* The digest of second image when store state is CANDIDATE. */
    uint8_t candidate_digest[TFM_FWU_MAX_DIGEST_SIZE];
} psa_fwu_impl_info_t;

#ifdef __cplusplus
}
#endif

#endif /* TFM_FWU_IMPL_INFO_H */
