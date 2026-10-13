/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SFCP_PSA_RSE_H
#define SFCP_PSA_RSE_H
#include "sfcp_psa_memory_hal.h"
#include "sfcp_atu.h"
#ifdef TFM_PARTITION_CRYPTO
#include "tfm_crypto_defs.h"
#endif
struct sfcp_psa_rse_request_t {
    comms_atu_region_set_t atu_regions;
#ifdef TFM_PARTITION_CRYPTO
    struct tfm_crypto_pack_iovec crypto_iovec;
#endif
};
#endif
