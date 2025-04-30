/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_MESSAGE_STATUS_H__
#define __RSE_PROVISIONING_MESSAGE_STATUS_H__

#include <assert.h>
#include <stdint.h>
#include "rse_persistent_data.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum provisioning_staging_status
 * @brief Represents the type of blob currently staged.
 *
 * This enumeration defines the type of blob which is currently
 * staged in the standard SRAM staging area. This flag is not
 * secure and therefore its value being set to a specific
 * component is not an indication that there is a valid blob
 * present. Blobs must still be parsed and their signitures
 * verified prior to running.
 *
 * @var PROVISIONING_STAGING_STATUS_NO_MESSAGE
 * Indicates that there is no message present.
 *
 * @var PROVISIONING_STAGING_STATUS_BL1_1_MESSAGE
 * Indicates a message staged by BL1_1.
 *
 * @var PROVISIONING_STAGING_STATUS_BL1_2_MESSAGE
 * Indicates a message staged by BL1_2.
 *
 * @var PROVISIONING_STAGING_STATUS_RUNTIME_MESSAGE
 * Indicates a message staged by the runtime.
 *
 * @var PROVISIONING_STAGING_STATUS_DM_CHAINED
 * Indicates a message staged by a DM chained provisioning blob.
 *
 * @var PROVISIONING_STAGING_STATUS_PLAIN_DATA_MESSAGE
 * Indicates a message staged by a plain data provisioning blob.
 */
enum provisioning_staging_status {
    PROVISIONING_STAGING_STATUS_NO_MESSAGE,
    PROVISIONING_STAGING_STATUS_BL1_1_MESSAGE,
    PROVISIONING_STAGING_STATUS_BL1_2_MESSAGE,
    PROVISIONING_STAGING_STATUS_RUNTIME_MESSAGE,
    PROVISIONING_STAGING_STATUS_DM_CHAINED,
    PROVISIONING_STAGING_STATUS_PLAIN_DATA_MESSAGE,
    PROVISIONING_STAGING_STATUS_MAX,
};

static inline enum provisioning_staging_status rse_get_provisioning_staging_status(void)
{
    return (enum provisioning_staging_status)
        RSE_PERSISTENT_DATA->bl1_data.provisioning_staging_status;
}

static inline void rse_set_provisioning_staging_status(enum provisioning_staging_status value)
{
    RSE_PERSISTENT_DATA->bl1_data.provisioning_staging_status = (uint8_t)value;
}

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_MESSAGE_STATUS_H__ */
