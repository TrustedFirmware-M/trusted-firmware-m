/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "thread.h"
#include "psa/client.h"
#include "psa/service.h"
#include "internal_status_code.h"
#include "cmsis_compiler.h"
#include "utilities.h"
#include "lists.h"
#include "tfm_pools.h"

/* Magic value that indicates a pool chunk has been allocated */
#define POOL_MAGIC_ALLOCATED UINT32_C(0xF0F0CCAA)

psa_status_t tfm_pool_init(struct tfm_pool_instance_t *pool, size_t poolsz,
                           size_t chunksz, size_t num)
{
    struct tfm_pool_chunk_t *pchunk;
    size_t i;

    if (!pool || (num == 0)) {
        return SPM_ERROR_BAD_PARAMETERS;
    }

    /* Ensure buffer is large enough */
    if (poolsz != (((chunksz + sizeof(struct tfm_pool_chunk_t)) * num) +
        sizeof(struct tfm_pool_instance_t))) {
        return SPM_ERROR_BAD_PARAMETERS;
    }

    /* Buffer should be BSS cleared but clear it again */
    spm_memset(pool, 0, poolsz);

    /* Chain pool chunks */
    UNI_LIST_INIT_NODE(pool, next);

    pchunk = (struct tfm_pool_chunk_t *)pool->chunks;
    for (i = 0; i < num; i++) {
        UNI_LIST_INSERT_AFTER(pool, pchunk, next);
        pchunk = (struct tfm_pool_chunk_t *)&pchunk->data[chunksz];
    }

    /* Prepare instance and insert to pool list */
    pool->chunksz = chunksz;
    pool->pool_sz = poolsz;

    return PSA_SUCCESS;
}

void *tfm_pool_alloc(struct tfm_pool_instance_t *pool)
{
    struct tfm_pool_chunk_t *node;

    if (!pool) {
        return NULL;
    }

    if (UNI_LIST_IS_EMPTY(pool, next)) {
        return NULL;
    }

    node = UNI_LIST_NEXT_NODE(pool, next);
    UNI_LIST_REMOVE_NODE(pool, node, next);

    node->magic = POOL_MAGIC_ALLOCATED;

    return &(node->data);
}

void tfm_pool_free(struct tfm_pool_instance_t *pool, void *ptr)
{
    struct tfm_pool_chunk_t *pchunk;

    /* In debug builds, trap invalid frees. */
    assert(is_valid_chunk_data_in_pool(pool, ptr));

    pchunk = TO_CONTAINER(ptr, struct tfm_pool_chunk_t, data);

    pchunk->magic = 0;

    UNI_LIST_INSERT_AFTER(pool, pchunk, next);

    /* In debug builds, overwrite the data to catch use-after-free bugs. */
#ifndef NDEBUG
    spm_memset(pchunk->data, 0xFF, pool->chunksz);
#endif
}

bool is_valid_chunk_data_in_pool(struct tfm_pool_instance_t *pool,
                                 uint8_t *data)
{
    const uintptr_t chunks_start = (uintptr_t)(pool->chunks);
    const size_t chunks_offset = (uintptr_t)data - chunks_start;
    struct tfm_pool_chunk_t *pchunk;

    /* Check that the message was allocated from the pool. */
    if (((uintptr_t)data < chunks_start) || (chunks_offset >= pool->pool_sz)) {
        return false;
    }

    if ((chunks_offset % (pool->chunksz + sizeof(struct tfm_pool_chunk_t)))
        != offsetof(struct tfm_pool_chunk_t, data)) {
        return false;
    }

    pchunk = TO_CONTAINER(data, struct tfm_pool_chunk_t, data);

    if (pchunk->magic != POOL_MAGIC_ALLOCATED) {
        return false;
    }

    return true;
}
