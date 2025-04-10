/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_PERSISTENT_DATA_H__
#define __RSE_PERSISTENT_DATA_H__

/*
 * The persistent data region is for information that is expected to persist
 * resets. This is not expected to have a value on a cold boot. This can be
 * used to communicate between resets such as when debug is enabled or whether
 * the last boot was successful.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* Data in this struct is expected to persist over multiple RSE cold resets */
struct rse_persistent_data {
    /* Data in this part of the struct is used by ROM */
    struct rse_bl1_persistent_data {
        /* Used to verify that the data has been initialized as expected */
        uint32_t initialized_magic;
        /* Provisioning blob buffer pointer */
        uint32_t *provisioning_blob_buf;
        size_t provisioning_blob_buf_size;
    } bl1_data;
    /* Additional data not used by the ROM can be added after this point */
};

void rse_setup_persistent_data(void);

void rse_get_persistent_data(struct rse_persistent_data **persistent_data);

#endif /* __RSE_PERSISTENT_DATA_H__ */
