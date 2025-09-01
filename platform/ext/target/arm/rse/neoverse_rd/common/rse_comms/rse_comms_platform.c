/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "device_definition.h"
#include "rse_comms_platform.h"
#include "rse_kmu_slot_ids.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static struct rse_comms_platform_device_t sender_devices[] = {
    [0] = { 0 },
#ifdef MHU_RSE_TO_RSE_SIDEBAND_SENDER_COUNT
    { &MHU_RSE_TO_RSE_SENDER_DEVS[0], RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2 },
#if MHU_RSE_TO_RSE_SIDEBAND_SENDER_COUNT > 1
    { &MHU_RSE_TO_RSE_SENDER_DEVS[1], RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2 },
#endif
#if MHU_RSE_TO_RSE_SIDEBAND_SENDER_COUNT > 2
    { &MHU_RSE_TO_RSE_SENDER_DEVS[2], RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2 },
#endif
#endif
    { &MHU_RSE_TO_AP_MONITOR_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_RSE_TO_SCP_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 }
};

struct rse_comms_platform_device_t rse_comms_platform_get_send_device(rse_comms_link_id_t link_id)
{
    assert((link_id >= 1) && (link_id < ARRAY_SIZE(sender_devices)));

    return sender_devices[link_id];
}

static struct rse_comms_platform_device_t receiver_devices[] = {
    [0] = { 0 },
#ifdef MHU_RSE_TO_RSE_SIDEBAND_RECEIVER_COUNT
    { &MHU_RSE_TO_RSE_RECEIVER_DEVS[0], RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2 },
#if MHU_RSE_TO_RSE_SIDEBAND_RECEIVER_COUNT > 1
    { &MHU_RSE_TO_RSE_RECEIVER_DEVS[1], RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2 },
#endif
#if MHU_RSE_TO_RSE_SIDEBAND_RECEIVER_COUNT > 2
    { &MHU_RSE_TO_RSE_RECEIVER_DEVS[2], RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2 },
#endif
#endif
    { &MHU_AP_MONITOR_TO_RSE_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_SCP_TO_RSE_DEV, RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3 }
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

static struct rse_comms_trusted_subnet_node_t trusted_subnet_nodes[] = {
    { .id = 0 },
    { .id = 1 },
#if RSE_AMOUNT > 2
    { .id = 2 },
#endif
#if RSE_AMOUNT > 3
    { .id = 3 },
#endif
};

static struct rse_comms_trusted_subnet_config_t trusted_subnet_configs[] = { {
    .id = 0,
    .type = RSE_COMMS_TRUSTED_SUBNET_UNTRUSTED_LINKS,
    .mode = RSE_COMMS_CRYPTOGRAPHY_MODE_AES256_CCM,
    .node_amount = ARRAY_SIZE(trusted_subnet_nodes),
    .nodes = trusted_subnet_nodes,
} };

void rse_comms_platform_get_trusted_subnets(
    struct rse_comms_trusted_subnet_config_t **trusted_subnets, size_t *num_trusted_subnets)
{
    *trusted_subnets = trusted_subnet_configs;
    *num_trusted_subnets = ARRAY_SIZE(trusted_subnet_configs);
}
