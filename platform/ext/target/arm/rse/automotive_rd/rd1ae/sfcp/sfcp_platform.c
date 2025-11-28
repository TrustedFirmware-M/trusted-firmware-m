/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "device_definition.h"
#include "sfcp_platform.h"
#include "platform_error_codes.h"
#include "rse_get_routing_tables.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static struct sfcp_platform_device_t sender_devices[] = {
    /* Link ID 0 is reserved */
    [0] = { 0 },
    { &MHU_RSE_TO_SCP_DEV, SFCP_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_RSE_TO_AP_MONITOR_DEV, SFCP_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_RSE_TO_AP_S_DEV, SFCP_PLATFORM_DEVICE_TYPE_MHUV3 }
};

struct sfcp_platform_device_t sfcp_platform_get_send_device(sfcp_link_id_t link_id)
{
    assert((link_id >= 1) && (link_id < ARRAY_SIZE(sender_devices)));

    return sender_devices[link_id];
}

static struct sfcp_platform_device_t receiver_devices[] = {
    /* Link ID 0 is reserved */
    [0] = { 0 },
    { &MHU_SCP_TO_RSE_DEV, SFCP_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_AP_MONITOR_TO_RSE_DEV, SFCP_PLATFORM_DEVICE_TYPE_MHUV3 },
    { &MHU_AP_S_TO_RSE_DEV, SFCP_PLATFORM_DEVICE_TYPE_MHUV3 }
};

struct sfcp_platform_device_t sfcp_platform_get_receive_device(sfcp_link_id_t link_id)
{
    assert((link_id >= 1) && (link_id < ARRAY_SIZE(receiver_devices)));

    return receiver_devices[link_id];
}

sfcp_link_id_t sfcp_platform_get_receive_link_id(struct sfcp_platform_device_t device)
{
    for (uint8_t i = 1; i < ARRAY_SIZE(receiver_devices); i++) {
        if ((receiver_devices[i].type == device.type) &&
            (receiver_devices[i].device == device.device)) {
            return i;
        }
    }

    return 0;
}

sfcp_node_id_t sfcp_platform_get_my_node_id(void)
{
    /* Only 1 RSE in the system */
    return 0;
}

void sfcp_platform_get_routing_tables(const uint8_t **routing_tables, size_t *routing_tables_size)
{
    enum tfm_plat_err_t plat_err;

    plat_err =
        rse_get_routing_tables(routing_tables, routing_tables_size, sfcp_platform_get_my_node_id());
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        assert(false);
        *routing_tables = NULL;
        *routing_tables_size = 0;
    }
}
