/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include "platform_error_codes.h"
#include "rse_comms_link_hal.h"
#include "rse_get_routing_tables.h"
#include "rse_get_rse_id.h"
#include "rse_comms_platform.h"
#include "mhu.h"

static enum rse_comms_hal_error_t get_routing_tables_for_rse_id(const uint8_t **routing_tables,
                                                                size_t *routing_tables_size,
                                                                uint32_t *rse_id)
{
    enum tfm_plat_err_t plat_err;

    plat_err = rse_get_rse_id(rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return RSE_COMMS_HAL_ERROR_CANNOT_GET_ID;
    }

    plat_err = rse_get_routing_tables(routing_tables, routing_tables_size, *rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return RSE_COMMS_HAL_ERROR_CANNOT_GET_ROUTING_TABLES;
    }

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}

rse_comms_link_id_t rse_comms_hal_get_route(rse_comms_node_id_t node_id)
{
    enum rse_comms_hal_error_t comms_err;
    uint32_t rse_id;
    const uint8_t *routing_tables;
    size_t routing_tables_size;

    comms_err = get_routing_tables_for_rse_id(&routing_tables, &routing_tables_size, &rse_id);
    if (comms_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return 0;
    }

    assert(node_id != rse_id);

    if (node_id >= routing_tables_size) {
        return 0;
    }

    return routing_tables[node_id];
}

enum rse_comms_hal_error_t rse_comms_hal_get_my_node_id(rse_comms_node_id_t *node_id)
{
    uint32_t rse_id;
    enum tfm_plat_err_t plat_err;

    plat_err = rse_get_rse_id(&rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return RSE_COMMS_HAL_ERROR_CANNOT_GET_ID;
    }

    *node_id = rse_id;

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}

enum rse_comms_hal_error_t rse_comms_hal_send_message(rse_comms_link_id_t link_id,
                                                      const uint8_t *message, size_t message_size)
{
    struct rse_comms_platform_device_t device;

    device = rse_comms_platform_get_send_device(link_id);

    switch (device.type) {
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2:
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3: {
        enum mhu_error_t mhu_err = mhu_send_data((void *)device.device, message, message_size);
        if (mhu_err != MHU_ERR_NONE) {
            return RSE_COMMS_HAL_ERROR_DEVICE_SEND_FAIL;
        }

        break;
    }
    default:
        return RSE_COMMS_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}

enum rse_comms_hal_error_t rse_comms_hal_is_message_available(rse_comms_link_id_t link_id,
                                                              bool *is_available)
{
    struct rse_comms_platform_device_t device;

    device = rse_comms_platform_get_receive_device(link_id);

    switch (device.type) {
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2:
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3: {
        enum mhu_error_t mhu_err = mhu_data_is_available((void *)device.device, is_available);

        /* In some platforms, there is a mixture of MHU versions, but the current MHU API
         * only allows support for single version to be compiled in. Different components
         * use different MHU devices (and only one type) but the routing tables are shared
         * and therefore we could try and initialise an MHU device with a different version
         * to what the compiled in driver supports. Allow that to happen here without error,
         * as we may want to poll all of the devices in the system, and just say that no message
         * is available
         */
        if (mhu_err == MHU_ERR_INVALID_VERSION) {
            *is_available = false;
            return RSE_COMMS_HAL_ERROR_SUCCESS;
        } else if (mhu_err != MHU_ERR_NONE) {
            return RSE_COMMS_HAL_ERROR_DEVICE_IS_AVAILABLE_FAIL;
        }

        break;
    }
    default:
        return RSE_COMMS_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}

enum rse_comms_hal_error_t rse_comms_hal_get_receive_message_size(rse_comms_link_id_t link_id,
                                                                  size_t *message_size)
{
    struct rse_comms_platform_device_t device;

    device = rse_comms_platform_get_receive_device(link_id);

    switch (device.type) {
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2:
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3: {
        enum mhu_error_t mhu_err = mhu_get_receive_msg_len((void *)device.device, message_size);
        if (mhu_err != MHU_ERR_NONE) {
            return RSE_COMMS_HAL_ERROR_DEVICE_GET_MSG_LEN_FAIL;
        }

        break;
    }
    default:
        return RSE_COMMS_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}

enum rse_comms_hal_error_t rse_comms_hal_receive_message(rse_comms_link_id_t link_id,
                                                         uint8_t *message, size_t message_size)
{
    struct rse_comms_platform_device_t device;

    device = rse_comms_platform_get_receive_device(link_id);

    switch (device.type) {
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2:
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3: {
        enum mhu_error_t mhu_err = mhu_receive_data((void *)device.device, message, message_size);
        if (mhu_err != MHU_ERR_NONE) {
            return RSE_COMMS_HAL_ERROR_DEVICE_RECEIVE_FAIL;
        }

        break;
    }
    default:
        return RSE_COMMS_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}

static enum rse_comms_hal_error_t init_sender_receiver(struct rse_comms_platform_device_t device,
                                                       bool is_sender)
{
    switch (device.type) {
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2:
    case RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3: {
        enum mhu_error_t mhu_err;

        if (is_sender) {
            mhu_err = mhu_init_sender((void *)device.device);
        } else {
            mhu_err = mhu_init_receiver((void *)device.device);
        }

        /* In some platforms, there is a mixture of MHU versions, but the current MHU API
         * only allows support for single version to be compiled in. Different components
         * use different MHU devices (and only one type) but the routing tables are shared
         * and therefore we could try and initialise an MHU device with a different version
         * to what the compiled in driver supports. Allow that to happen here without error,
         * if we try and actually use the device we will fail with an incorrect version
         * then */
        if ((mhu_err != MHU_ERR_NONE) && (mhu_err != MHU_ERR_INVALID_VERSION)) {
            return RSE_COMMS_HAL_ERROR_DEVICE_INIT_FAIL;
        }

        break;
    }
    default:
        return RSE_COMMS_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}

enum rse_comms_hal_error_t rse_comms_hal_init(void)
{
    enum rse_comms_hal_error_t comms_err;
    uint32_t rse_id;
    const uint8_t *routing_tables;
    size_t routing_tables_size;
    rse_comms_link_id_t link_id;

    comms_err = get_routing_tables_for_rse_id(&routing_tables, &routing_tables_size, &rse_id);
    if (comms_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
        return comms_err;
    }

    for (rse_comms_node_id_t node = 0; node < routing_tables_size; node++) {
        if (node == rse_id) {
            continue;
        }

        link_id = routing_tables[node];

        comms_err = init_sender_receiver(rse_comms_platform_get_send_device(link_id), true);
        if (comms_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
            return comms_err;
        }

        comms_err = init_sender_receiver(rse_comms_platform_get_receive_device(link_id), false);
        if (comms_err != RSE_COMMS_HAL_ERROR_SUCCESS) {
            return comms_err;
        }
    }

    return RSE_COMMS_HAL_ERROR_SUCCESS;
}
