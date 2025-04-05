/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_test_hash.h"

#include "cc3xx_hash.h"
#include "cc3xx_test_assert.h"

#include <string.h>

int hash_test_lowlevel_mixed_xoring(struct hash_test_data_t *data,
                                    cc3xx_hash_alg_t alg)
{
    uint32_t output[SHA256_OUTPUT_SIZE / sizeof(uint32_t)];
    cc3xx_err_t err;
    int rc;

    err = cc3xx_lowlevel_hash_init(alg);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_set_xor_input(0x36363636);
    err = cc3xx_lowlevel_hash_update(data->input, 64);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_reset_xor_input();
    err = cc3xx_lowlevel_hash_update(&data->input[64], data->input_size - 64);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_finish(output, hash_size_from_alg(alg));

    cc3xx_test_assert(memcmp(output, output_from_alg_and_data(alg, data),
                      hash_size_from_alg(alg)) == 0);

    rc = 0;
cleanup:
    cc3xx_lowlevel_hash_uninit();

    return rc;
}

int hash_test_lowlevel_oneshot(struct hash_test_data_t *data,
                               cc3xx_hash_alg_t alg)
{
    uint32_t output[SHA256_OUTPUT_SIZE / sizeof(uint32_t)];
    cc3xx_err_t err;
    int rc;

    err = cc3xx_lowlevel_hash_init(alg);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    err = cc3xx_lowlevel_hash_update(data->input, data->input_size);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_finish(output, hash_size_from_alg(alg));

    cc3xx_test_assert(memcmp(output, output_from_alg_and_data(alg, data),
                      hash_size_from_alg(alg)) == 0);

    rc = 0;
cleanup:
    cc3xx_lowlevel_hash_uninit();

    return rc;
}

int hash_test_lowlevel_xored_oneshot(struct hash_test_data_t *data,
                                     cc3xx_hash_alg_t alg)
{
    uint32_t output[SHA256_OUTPUT_SIZE / sizeof(uint32_t)];
    cc3xx_err_t err;
    int rc;

    err = cc3xx_lowlevel_hash_init(alg);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_set_xor_input(0xDEADBEEF);

    err = cc3xx_lowlevel_hash_update(data->input, data->input_size);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_finish(output, hash_size_from_alg(alg));

    cc3xx_test_assert(memcmp(output, output_from_alg_and_data(alg, data),
                      hash_size_from_alg(alg)) == 0);

    rc = 0;
cleanup:
    cc3xx_lowlevel_hash_uninit();

    return rc;
}

int hash_test_lowlevel_multipart(struct hash_test_data_t *data,
                                 cc3xx_hash_alg_t alg,
                                 size_t chunk_size)
{
    uint32_t output[SHA256_OUTPUT_SIZE / sizeof(uint32_t)] = {0};
    cc3xx_err_t err;
    size_t idx;
    int rc;

    err = cc3xx_lowlevel_hash_init(alg);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    for (idx = 0; idx < data->input_size; idx += chunk_size) {
        err = cc3xx_lowlevel_hash_update(data->input + idx,
                                       data->input_size - idx < chunk_size ?
                                       data->input_size - idx : chunk_size);
        cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);
    }

    cc3xx_lowlevel_hash_finish(output, hash_size_from_alg(alg));

    cc3xx_test_assert(memcmp(output, output_from_alg_and_data(alg, data),
                             hash_size_from_alg(alg)) == 0);

    rc = 0;
cleanup:
    cc3xx_lowlevel_hash_uninit();

    return rc;
}

int hash_test_lowlevel_reinit(struct hash_test_data_t *data,
                              cc3xx_hash_alg_t alg)
{
    cc3xx_err_t err;
    int rc;

    err = cc3xx_lowlevel_hash_init(alg);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_uninit();

    hash_test_lowlevel_oneshot(data, alg);

    rc = 0;
cleanup:
    cc3xx_lowlevel_hash_uninit();

    return rc;
}


int hash_test_lowlevel_saveload_multipart(struct hash_test_data_t *data,
                                          cc3xx_hash_alg_t alg,
                                          size_t chunk_size)
{
    uint32_t output[SHA256_OUTPUT_SIZE / sizeof(uint32_t)] = {0};
    cc3xx_err_t err;
    size_t idx;
    struct cc3xx_hash_state_t state = {0};
    int rc;

    err = cc3xx_lowlevel_hash_init(alg);
    cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

    cc3xx_lowlevel_hash_get_state(&state);
    cc3xx_lowlevel_hash_uninit();

    for (idx = 0; idx < data->input_size; idx += chunk_size) {
        cc3xx_lowlevel_hash_set_state(&state);

        err = cc3xx_lowlevel_hash_update(data->input + idx,
                                data->input_size - idx < chunk_size ?
                                data->input_size - idx : chunk_size);
        cc3xx_test_assert(err == CC3XX_ERR_SUCCESS);

        cc3xx_lowlevel_hash_get_state(&state);
        cc3xx_lowlevel_hash_uninit();
    }

    cc3xx_lowlevel_hash_set_state(&state);
    cc3xx_lowlevel_hash_finish(output, hash_size_from_alg(alg));

    cc3xx_test_assert(memcmp(output, output_from_alg_and_data(alg, data),
                             hash_size_from_alg(alg)) == 0);

    rc = 0;
cleanup:
    cc3xx_lowlevel_hash_uninit();

    return rc;
}
