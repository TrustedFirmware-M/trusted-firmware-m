/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PSA_CRYPTO_OPAQUE_KEY_IDS_H
#define __PSA_CRYPTO_OPAQUE_KEY_IDS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "kmu_drv.h"

enum opaque_key_id_t {
    PSA_OPAQUE_KEY_ID_MIN = 0x7FFF810B,
    PSA_OPAQUE_KEY_ID_KRTL,
    PSA_OPAQUE_KEY_ID_HUK,
    PSA_OPAQUE_KEY_ID_GUK,
    PSA_OPAQUE_KEY_ID_KP_CM,
    PSA_OPAQUE_KEY_ID_KCE_CM,
    PSA_OPAQUE_KEY_ID_KP_DM,
    PSA_OPAQUE_KEY_ID_KCE_DM,
    PSA_OPAQUE_KEY_ID_USER_SLOT_MIN,
    PSA_OPAQUE_KEY_ID_USER_SLOT_MAX = PSA_OPAQUE_KEY_ID_USER_SLOT_MIN +
                                        (KMU_USER_SLOT_MAX - KMU_USER_SLOT_MIN),

    PSA_OPAQUE_KEY_ID_MAX = 0x7FFF812B,
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PSA_CRYPTO_OPAQUE_KEY_IDS_H */
