/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PLATFORM_BUILTIN_KEY_LOADER_IDS_H__
#define __PLATFORM_BUILTIN_KEY_LOADER_IDS_H__

#include "rse_rotpk_config.h"
#include "rse_otp_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ECC key pair size for IAK is the largest builtin key,
 * dictated by `ATTEST_KEY_BITS` and is set to `384` (i.e 48 bytes)
 */
#define TFM_BUILTIN_MAX_KEY_LEN 48

enum psa_drv_slot_number_t {
    TFM_BUILTIN_KEY_SLOT_HUK = 0,
    TFM_BUILTIN_KEY_SLOT_IAK,
#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
    TFM_BUILTIN_KEY_SLOT_DAK_SEED,
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */
#ifdef TFM_PARTITION_DPE
    TFM_BUILTIN_KEY_SLOT_ROT_CDI,
#endif /* TFM_PARTITION_DPE */
    TFM_BUILTIN_KEY_SLOT_HOST_CM_MIN,
    TFM_BUILTIN_KEY_SLOT_HOST_CM_MAX = TFM_BUILTIN_KEY_SLOT_HOST_CM_MIN + RSE_ROTPK_CM_HOST_AMOUNT,
    TFM_BUILTIN_KEY_SLOT_HOST_DM_MIN,
    TFM_BUILTIN_KEY_SLOT_HOST_DM_MAX = TFM_BUILTIN_KEY_SLOT_HOST_DM_MIN + RSE_ROTPK_DM_HOST_AMOUNT,
    TFM_BUILTIN_KEY_SLOT_MAX,
};

#ifdef __cplusplus
}
#endif

#endif /* __PLATFORM_BUILTIN_KEY_LOADER_IDS_H__ */
