/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "compiler_ext_defs.h"
#include "internal_status_code.h"
#include "spm.h"
#include "tfm_arch.h"

#ifdef CONFIG_TFM_CONN_HANDLE_MAX_NUM
#pragma message("CONFIG_TFM_CONN_HANDLE_MAX_NUM is not used in SFN model without connection-based services.")
#endif

/*
 * Bits [2:0] of PSPLIM are reserved in v8m,
 * so PSPLIM has to be 8 bytes aligned when allocating space for connection.
 */
#define CONNECTION_SIZE        ((sizeof(struct connection_t) + 7) & ~0x7)
#define FIXED_STATIC_HANDLE    ((psa_handle_t)0x1000)

static inline struct connection_t *alloc_conn_from_stack_top(void)
{
    uint32_t stack_top = tfm_arch_get_psplim();

    tfm_arch_set_psplim(stack_top + CONNECTION_SIZE);

    return (struct connection_t *)stack_top;
}

static inline void free_conn_from_stack_top(void)
{
    uint32_t stack_top = tfm_arch_get_psplim();

    tfm_arch_set_psplim(stack_top - CONNECTION_SIZE);
}

/*********************** Connection handle conversion APIs *******************/

/*
 * A connection instance connection_t allocated inside SPM is actually a memory
 * address in PSP stack. Return this connection to the client directly
 * exposes information of secure memory address. In this case, converting the
 * connection into another handle value does not represent the memory address
 * to avoid exposing secure memory directly to clients.
 * Since the current connection can always be calculated from the address of
 * PSP stack top, it is good enough to return a fixed static handle value to client.
 */
psa_handle_t connection_to_handle(struct connection_t *p_connection)
{
    (void)p_connection;

    return FIXED_STATIC_HANDLE;
}

struct connection_t *handle_to_connection(psa_handle_t handle)
{
    struct connection_t *p_connection;

    if (handle != FIXED_STATIC_HANDLE) {
        return NULL;
    }

    p_connection = (struct connection_t *)
                   (tfm_arch_get_psplim() - CONNECTION_SIZE);

    return p_connection;
}

/* Service handle management functions */
void spm_init_connection_space(void)
{
    /*
     * No initialization is required for local handle,
     * because space for connection will be directly allocated
     * from stack when calling spm_allocate_connection.
     */
}

struct connection_t *spm_allocate_connection(void)
{
    return alloc_conn_from_stack_top();
}

psa_status_t spm_validate_connection(const struct connection_t *p_connection)
{
    /* Connection address is always calculated from PSPLIM. No need to validate here. */
    return PSA_SUCCESS;
}

void spm_free_connection(struct connection_t *p_connection)
{
    /* In debug builds, overwrite the status to catch use-after-free bugs */
#ifndef NDEBUG
    assert(p_connection != NULL);

    p_connection->status = TFM_HANDLE_STATUS_MAX;
#else
    (void)p_connection;
#endif

    free_conn_from_stack_top();
}
