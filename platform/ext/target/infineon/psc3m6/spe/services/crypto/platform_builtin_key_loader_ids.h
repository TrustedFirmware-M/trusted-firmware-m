/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PLATFORM_BUILTIN_KEY_LOADER_IDS_H
#define PLATFORM_BUILTIN_KEY_LOADER_IDS_H

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_BUILTIN_MAX_KEY_LEN 66 /* the largest key size in bytes, that we can import */

enum psa_drv_slot_number_t {
    TFM_BUILTIN_KEY_SLOT_HUK = 0,
    TFM_BUILTIN_KEY_SLOT_IAK, /* IAK private */
    TFM_BUILTIN_KEY_SLOT_MAX,
};

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_BUILTIN_KEY_LOADER_IDS_H */
