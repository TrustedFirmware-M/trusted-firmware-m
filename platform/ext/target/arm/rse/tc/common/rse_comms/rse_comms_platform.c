/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "device_definition.h"
#include "rse_comms_platform.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static struct rse_comms_platform_device_t sender_devices[] = {
    /* Link ID 0 is reserved */
    [0] = { 0 },
    { &MHU_RSE_TO_SCP_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_RSE_TO_AP_MONITOR_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_RSE_TO_AP_NS_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 }
};

struct rse_comms_platform_device_t rse_comms_platform_get_send_device(rse_comms_link_id_t link_id)
{
    assert((link_id >= 1) && (link_id < ARRAY_SIZE(sender_devices)));

    return sender_devices[link_id];
}

static struct rse_comms_platform_device_t receiver_devices[] = {
    /* Link ID 0 is reserved */
    [0] = { 0 },
    { &MHU_SCP_TO_RSE_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_AP_MONITOR_TO_RSE_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_AP_NS_TO_RSE_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 }
};

struct rse_comms_platform_device_t
rse_comms_platform_get_receive_device(rse_comms_link_id_t link_id)
{
    assert((link_id >= 1) && (link_id < ARRAY_SIZE(receiver_devices)));

    return receiver_devices[link_id];
}

rse_comms_link_id_t
rse_comms_platform_get_receive_link_id(struct rse_comms_platform_device_t device)
{
    for (uint8_t i = 1; i < ARRAY_SIZE(receiver_devices); i++) {
        if ((receiver_devices[i].type == device.type) &&
            (receiver_devices[i].device == device.device)) {
            return i;
        }
    }

    return 0;
}
