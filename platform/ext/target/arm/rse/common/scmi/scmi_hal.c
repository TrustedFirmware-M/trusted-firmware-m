/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#include "atu_config.h"
#include "atu_rse_lib.h"
#include "scmi_hal.h"
#include "device_definition.h"
#include "host_base_address.h"

/* TODO: Make these configurable */
#define SCP_MHU_DOORBELL_CHANNEL 2U

#define ALIGN_UP(num, align) (((num) + ((align) - 1)) & ~((align) - 1))

scmi_comms_err_t scmi_hal_shared_memory_init(void)
{
    enum atu_error_t err;

    err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, SCP_SHARED_MEMORY_PHYS_BASE,
                                       SCP_SHARED_MEMORY_BASE, ALIGN_UP(SCP_SHARED_MEMORY_SIZE,
                                       RSE_ATU_PAGE_SIZE), 0);
    if (err != ATU_ERR_NONE) {
        return SCMI_COMMS_HARDWARE_ERROR;
    }

    return SCMI_COMMS_SUCCESS;
}

scmi_comms_err_t scmi_hal_doorbell_init(void)
{
    enum mhu_v3_x_error_t err;
    uint8_t num_ch;
    uint8_t i;

    /* Init sender */
    err = mhu_v3_x_driver_init(&MHU_RSE_TO_SCP_DEV);
    if (err != MHU_V_3_X_ERR_NONE) {
        return SCMI_COMMS_HARDWARE_ERROR;
    }

    /* Init receiver */
    err = mhu_v3_x_driver_init(&MHU_SCP_TO_RSE_DEV);
    if (err != MHU_V_3_X_ERR_NONE) {
        return SCMI_COMMS_HARDWARE_ERROR;
    }

    /* Read the number of doorbell channels implemented in the MHU */
    err = mhu_v3_x_get_num_channel_implemented(&MHU_SCP_TO_RSE_DEV,
                                               MHU_V3_X_CHANNEL_TYPE_DBCH,
                                               &num_ch);
    if ((err != MHU_V_3_X_ERR_NONE) || (num_ch <= SCP_MHU_DOORBELL_CHANNEL)) {
        return SCMI_COMMS_HARDWARE_ERROR;
    }

    /* Mask all channels except the notifying channel */
    for (i = 0; i < num_ch; i++) {
        if (i == SCP_MHU_DOORBELL_CHANNEL) {
            err = mhu_v3_x_doorbell_mask_clear(&MHU_SCP_TO_RSE_DEV, i, UINT32_MAX);
            if (err != MHU_V_3_X_ERR_NONE) {
                return SCMI_COMMS_HARDWARE_ERROR;
            }
        } else {
            err = mhu_v3_x_doorbell_mask_set(&MHU_SCP_TO_RSE_DEV, i, UINT32_MAX);
            if (err != MHU_V_3_X_ERR_NONE) {
                return SCMI_COMMS_HARDWARE_ERROR;
            }
        }
    }

    /* Enable the doorbell channel's contribution to MHU combined interrupt */
    err = mhu_v3_x_channel_interrupt_enable(&MHU_SCP_TO_RSE_DEV,
                                            SCP_MHU_DOORBELL_CHANNEL,
                                            MHU_V3_X_CHANNEL_TYPE_DBCH);
    if (err != MHU_V_3_X_ERR_NONE) {
        return SCMI_COMMS_HARDWARE_ERROR;
    }

    return SCMI_COMMS_SUCCESS;
}

scmi_comms_err_t scmi_hal_doorbell_ring(void)
{
    enum mhu_v3_x_error_t err;

    err = mhu_v3_x_doorbell_write(&MHU_RSE_TO_SCP_DEV, SCP_MHU_DOORBELL_CHANNEL, 1);
    if (err != MHU_V_3_X_ERR_NONE) {
        return SCMI_COMMS_HARDWARE_ERROR;
    }

    return SCMI_COMMS_SUCCESS;
}

scmi_comms_err_t scmi_hal_doorbell_clear(void)
{
    enum mhu_v3_x_error_t err;

    err = mhu_v3_x_doorbell_clear(&MHU_SCP_TO_RSE_DEV, SCP_MHU_DOORBELL_CHANNEL, UINT32_MAX);
    if (err != MHU_V_3_X_ERR_NONE) {
        return SCMI_COMMS_HARDWARE_ERROR;
    }

    return SCMI_COMMS_SUCCESS;
}
