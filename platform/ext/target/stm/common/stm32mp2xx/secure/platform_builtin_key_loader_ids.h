/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PLATFORM_BUILTIN_KEY_LOADER_IDS_H__
#define __PLATFORM_BUILTIN_KEY_LOADER_IDS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_BUILTIN_MAX_KEY_LEN 96

enum psa_drv_slot_number_t {
	TFM_BUILTIN_KEY_SLOT_HUK = 0,
	TFM_BUILTIN_KEY_SLOT_IAK,
	TFM_BUILTIN_KEY_SLOT_MAX,
};

#ifdef __cplusplus
}
#endif

#endif /* __PLATFORM_BUILTIN_KEY_LOADER_IDS_H__ */
