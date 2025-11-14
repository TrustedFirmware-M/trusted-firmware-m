/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_BUILTIN_KEY_IDS_H__
#define __TFM_BUILTIN_KEY_IDS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "rse_rotpk_config.h"

/**
 * \brief The persistent key identifiers for TF-M builtin keys.
 *
 * The value of TFM_BUILTIN_KEY_ID_MIN (and therefore of the whole range) is
 * completely arbitrary except for being inside the PSA builtin keys range.
 *
 */
enum tfm_key_id_builtin_t {
    TFM_BUILTIN_KEY_ID_MIN = 0x7FFF815Bu,
    TFM_BUILTIN_KEY_ID_HUK,
    TFM_BUILTIN_KEY_ID_IAK,
#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
    TFM_BUILTIN_KEY_ID_DAK_SEED,
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */
#ifdef TFM_PARTITION_DPE
    TFM_BUILTIN_KEY_ID_ROT_CDI,
#endif /* TFM_PARTITION_DPE */
#ifdef TEST_S_RSE_IMAGE_VERIFICATION
    TFM_BUILTIN_RIV_TEST_KEY,
#endif /* TEST_S_RSE_IMAGE_VERIFICATION */
    TFM_BUILTIN_KEY_ID_PLAT_SPECIFIC_MIN = 0x7FFF816Bu,
    TFM_BUILTIN_KEY_HOST_CM_MIN,
    TFM_BUILTIN_KEY_HOST_CM_MAX = TFM_BUILTIN_KEY_HOST_CM_MIN + RSE_ROTPK_CM_HOST_AMOUNT,
    TFM_BUILTIN_KEY_HOST_DM_MIN,
    TFM_BUILTIN_KEY_HOST_DM_MAX = TFM_BUILTIN_KEY_HOST_DM_MIN + RSE_ROTPK_DM_HOST_AMOUNT,
    TFM_BUILTIN_KEY_ID_MAX = 0x7FFF817Bu,
};

#ifdef __cplusplus
}
#endif
#endif /* __TFM_BUILTIN_KEY_IDS_H__ */
