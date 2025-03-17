/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include "internal_status_code.h"
#include "spm.h"
#include "tfm_pools.h"
#include "load/service_defs.h"

#if !(defined CONFIG_TFM_CONN_HANDLE_MAX_NUM) || (CONFIG_TFM_CONN_HANDLE_MAX_NUM == 0)
#error "CONFIG_TFM_CONN_HANDLE_MAX_NUM must be defined and not zero."
#endif

/* Pools */
TFM_POOL_DECLARE(connection_pool, sizeof(struct connection_t),
                 CONFIG_TFM_CONN_HANDLE_MAX_NUM);

/*********************** Connection handle conversion APIs *******************/

#define CONVERSION_FACTOR_BITOFFSET    3
#define CONVERSION_FACTOR_VALUE        (1 << CONVERSION_FACTOR_BITOFFSET)
/* Set 32 as the maximum */
#define CONVERSION_FACTOR_VALUE_MAX    0x20

#if CONVERSION_FACTOR_VALUE > CONVERSION_FACTOR_VALUE_MAX
#error "CONVERSION FACTOR OUT OF RANGE"
#endif

static uint32_t loop_index;

/*
 * A connection instance connection_t allocated inside SPM is actually a memory
 * address among the connection pool. Return this connection to the client directly
 * exposes information of secure memory address. In this case, converting the
 * connection into another handle value does not represent the memory address
 * to avoid exposing secure memory directly to clients.
 *
 * This function converts the connection instance into another value by scaling
 * the connection in pool offset, the converted value is named as a user handle.
 *
 * The formula:
 *  handle =      (p_connection - POOL_START) * CONVERSION_FACTOR_VALUE +
 *                CLIENT_HANDLE_VALUE_MIN + loop_index
 * where:
 *  CONVERSION_FACTOR_VALUE = 1 << CONVERSION_FACTOR_BITOFFSET, and should not
 *  exceed CONVERSION_FACTOR_VALUE_MAX.
 *
 *  p_connection    in RANGE[POOL_START, POOL_END]
 *  handle          in RANGE[CLIENT_HANDLE_VALUE_MIN, 0x3FFFFFFF]
 *  loop_index      in RANGE[0, CONVERSION_FACTOR_VALUE - 1]
 *
 *  note:
 *  loop_index is used to promise same connection instance is converted into
 *  different user handles in short time.
 */
psa_handle_t connection_to_handle(struct connection_t *p_connection)
{
    psa_handle_t handle;

    loop_index = (loop_index + 1) % CONVERSION_FACTOR_VALUE;
    handle = (psa_handle_t)((((uintptr_t)p_connection -
                  (uintptr_t)connection_pool) << CONVERSION_FACTOR_BITOFFSET) +
                  CLIENT_HANDLE_VALUE_MIN + loop_index);

    return handle;
}

/*
 * This function converts a user handle into a corresponded connection instance.
 * The converted value is validated before returning, an invalid handle instance
 * is returned as NULL.
 *
 * The formula:
 *  p_connection =    ((handle - CLIENT_HANDLE_VALUE_MIN) /
 *                    CONVERSION_FACTOR_VALUE) + POOL_START
 * where:
 *  CONVERSION_FACTOR_VALUE = 1 << CONVERSION_FACTOR_BITOFFSET, and should not
 *  exceed CONVERSION_FACTOR_VALUE_MAX.
 *
 *  p_connection    in RANGE[POOL_START, POOL_END]
 *  handle          in RANGE[CLIENT_HANDLE_VALUE_MIN, 0x3FFFFFFF]
 *  loop_index      in RANGE[0, CONVERSION_FACTOR_VALUE - 1]
 */
struct connection_t *handle_to_connection(psa_handle_t handle)
{
    struct connection_t *p_connection;

    if (handle == PSA_NULL_HANDLE) {
        return NULL;
    }

    p_connection = (struct connection_t *)((((uintptr_t)handle -
                    CLIENT_HANDLE_VALUE_MIN) >> CONVERSION_FACTOR_BITOFFSET) +
                    (uintptr_t)connection_pool);

    return p_connection;
}

/* Service handle management functions */
void spm_init_connection_space(void)
{
    if (tfm_pool_init(connection_pool,
                      POOL_BUFFER_SIZE(connection_pool),
                      sizeof(struct connection_t),
                      CONFIG_TFM_CONN_HANDLE_MAX_NUM) != PSA_SUCCESS) {
        tfm_core_panic();
    }
}

struct connection_t *spm_allocate_connection(void)
{
    return (struct connection_t *)tfm_pool_alloc(connection_pool);
}

psa_status_t spm_validate_connection(const struct connection_t *p_connection)
{
    /* Check the handle address is valid */
    if (is_valid_chunk_data_in_pool(connection_pool,
                                    (uint8_t *)p_connection) != true) {
        return SPM_ERROR_GENERIC;
    }

    return PSA_SUCCESS;
}

void spm_free_connection(struct connection_t *p_connection)
{
    assert(p_connection != NULL);

    /* Return handle buffer to pool */
    tfm_pool_free(connection_pool, p_connection);
}
