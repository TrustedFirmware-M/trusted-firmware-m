/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TEST_LOWLEVEL_HASH_H
#define TEST_LOWLEVEL_HASH_H

#include "cc3xx_test_hash.h"

#ifdef __cplusplus
extern "C" {
#endif

int hash_test_lowlevel_mixed_xoring(struct hash_test_data_t *data,
                                    cc3xx_hash_alg_t alg);

int hash_test_lowlevel_xored_oneshot(struct hash_test_data_t *data,
                                     cc3xx_hash_alg_t alg);

int hash_test_lowlevel_oneshot(struct hash_test_data_t *data,
                               cc3xx_hash_alg_t alg);

int hash_test_lowlevel_multipart(struct hash_test_data_t *data,
                                 cc3xx_hash_alg_t alg,
                                 size_t chunk_size);

int hash_test_lowlevel_reinit(struct hash_test_data_t *data,
                              cc3xx_hash_alg_t alg);

int hash_test_lowlevel_saveload_multipart(struct hash_test_data_t *data,
                                          cc3xx_hash_alg_t alg,
                                          size_t chunk_size);

#ifdef __cplusplus
}
#endif

#endif /* TEST_LOWLEVEL_HASH_H */
