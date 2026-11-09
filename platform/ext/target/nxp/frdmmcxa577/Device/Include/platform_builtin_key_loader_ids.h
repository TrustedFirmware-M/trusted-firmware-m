/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_BUILTIN_KEY_LOADER_IDS_H
#define TFM_BUILTIN_KEY_LOADER_IDS_H

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_BUILTIN_MAX_KEY_LEN 96

enum psa_drv_slot_number_t {
    TFM_BUILTIN_KEY_SLOT_HUK = 0,
    TFM_BUILTIN_KEY_SLOT_IAK,
#ifdef TFM_PARTITION_DELEGATED_ATTESTATION
    TFM_BUILTIN_KEY_SLOT_DAK_SEED,
#endif /* TFM_PARTITION_DELEGATED_ATTESTATION */
    TFM_BUILTIN_KEY_SLOT_MAX,
};

#ifdef __cplusplus
}
#endif

#endif /* TFM_BUILTIN_KEY_LOADER_IDS_H */
