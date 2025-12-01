/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include <string.h>

#include "sfcp_link_hal.h"
#include "sfcp_platform.h"

#define MHU_REQUIRED_NUMBER_CHANNELS (4)
#define MHU_NOTIFY_VALUE (1234u)

/* Platform MHU version can be set to 0, 2, 3. 0 specifies that
 * both of the MHU types are present in the platform and 2/3 specify
 * that a single MHU type is present
 */
#if (PLAT_MHU_VERSION == 2) || (PLAT_MHU_VERSION == 0)
#include "mhu_v2_x.h"
#define MHU_V2_ENABLED
#endif

#if (PLAT_MHU_VERSION == 3) || (PLAT_MHU_VERSION == 0)
#include "mhu_v3_x.h"
#define MHU_V3_ENABLED
#endif

static void get_routing_tables_and_rse_id(const uint8_t **routing_tables,
                                          size_t *routing_tables_size, uint32_t *rse_id)
{
    *rse_id = sfcp_platform_get_my_node_id();

    sfcp_platform_get_routing_tables(routing_tables, routing_tables_size);
}

sfcp_link_id_t sfcp_hal_get_route(sfcp_node_id_t node_id)
{
    uint32_t rse_id;
    const uint8_t *routing_tables;
    size_t routing_tables_size;

    get_routing_tables_and_rse_id(&routing_tables, &routing_tables_size, &rse_id);

    assert(node_id != rse_id);

    if (node_id >= routing_tables_size) {
        return 0;
    }

    return routing_tables[node_id];
}

enum sfcp_hal_error_t sfcp_hal_get_my_node_id(sfcp_node_id_t *node_id)
{
    *node_id = sfcp_platform_get_my_node_id();

    return SFCP_HAL_ERROR_SUCCESS;
}

static uint32_t mhu_driver_init(void *mhu_device, enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_driver_init(mhu_device, MHU_REV_READ_FROM_HW);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_driver_init(mhu_device);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_get_num_mhu_channels(void *mhu_device, enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_get_num_channel_implemented(mhu_device);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3: {
        uint8_t num_ch;
        enum mhu_v3_x_error_t mhu_v3_err;

        mhu_v3_err =
            mhu_v3_x_get_num_channel_implemented(mhu_device, MHU_V3_X_CHANNEL_TYPE_DBCH, &num_ch);
        if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
            assert(false);
            return 0;
        }

        return num_ch;
    }
#endif
    default:
        return 0;
    }
}

static uint32_t mhu_channel_mask_set(void *mhu_device, uint32_t channel, uint32_t mask,
                                     enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_channel_mask_set(mhu_device, channel, mask);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_doorbell_mask_set(mhu_device, channel, mask);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_channel_mask_clear(void *mhu_device, uint32_t channel, uint32_t mask,
                                       enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_channel_mask_clear(mhu_device, channel, mask);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_doorbell_mask_clear(mhu_device, channel, mask);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_channel_interrupt_enable(void *mhu_device, uint32_t channel,
                                             enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        /* Only enable global interrupt for MHUv2 */
        return mhu_v2_x_interrupt_enable(mhu_device, MHU_2_1_INTR_CHCOMB_MASK);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_channel_interrupt_enable(mhu_device, channel, MHU_V3_X_CHANNEL_TYPE_DBCH);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_channel_interrupt_disable(void *mhu_device, uint32_t channel,
                                              enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        /* Only disable global interrupt for MHUv2 */
        return mhu_v2_x_interrupt_disable(mhu_device, MHU_2_1_INTR_CHCOMB_MASK);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_channel_interrupt_disable(mhu_device, channel, MHU_V3_X_CHANNEL_TYPE_DBCH);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_channel_send(void *mhu_device, uint32_t channel, uint32_t value,
                                 enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_channel_send(mhu_device, channel, value);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_doorbell_write(mhu_device, channel, value);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_channel_send_device_receive(void *mhu_device, uint32_t channel, uint32_t *value,
                                                enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_channel_poll(mhu_device, channel, value);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_doorbell_read(mhu_device, channel, value);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_channel_receive_device_receive(void *mhu_device, uint32_t channel,
                                                   uint32_t *value,
                                                   enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_channel_receive(mhu_device, channel, value);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_doorbell_read(mhu_device, channel, value);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_channel_clear(void *mhu_device, uint32_t channel,
                                  enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_channel_clear(mhu_device, channel);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_v3_x_doorbell_clear(mhu_device, channel, UINT32_MAX);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_initiate_transfer(void *mhu_device, enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_initiate_transfer(mhu_device);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        /* Not required in MHUv3 */
        return 0;
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static uint32_t mhu_close_transfer(void *mhu_device, enum sfcp_platform_device_type_t type)
{
    switch (type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_v2_x_close_transfer(mhu_device);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        /* Not required in MHUv3 */
        return 0;
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }
}

static enum sfcp_hal_error_t mhu_send_signal_poll_loop(void *mhu_send_device, void *mhu_recv_device,
                                                       enum sfcp_platform_device_type_t type)
{
    const uint32_t send_num_channels = mhu_get_num_mhu_channels(mhu_send_device, type);
    const uint32_t recv_num_channels = mhu_get_num_mhu_channels(mhu_recv_device, type);
    uint32_t mhu_err;
    uint32_t send_signal;
    uint32_t recv_signal;

    /* Signal using the last channel */
    mhu_err = mhu_channel_send(mhu_send_device, send_num_channels - 1, MHU_NOTIFY_VALUE, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    do {
        mhu_err = mhu_channel_send_device_receive(mhu_send_device, send_num_channels - 1,
                                                  &send_signal, type);
        if (mhu_err != 0) {
            return mhu_err;
        }

        /* Also check the receive device, if we find that a signal is pending
         * for us there, both devices are talking to each other at once. Return
         * an error and let the higher layers decide what to do
         */
        mhu_err = mhu_channel_receive_device_receive(mhu_recv_device, recv_num_channels - 1,
                                                     &recv_signal, type);
        if (mhu_err != 0) {
            return mhu_err;
        }

        if ((recv_signal & MHU_NOTIFY_VALUE) == MHU_NOTIFY_VALUE) {
            return SFCP_HAL_ERROR_SEND_MESSAGE_BUS_BUSY;
        }
    } while ((send_signal & MHU_NOTIFY_VALUE) == MHU_NOTIFY_VALUE);

    return 0;
}

static uint32_t mhu_recv_signal_poll_loop(void *mhu_recv_device,
                                          enum sfcp_platform_device_type_t type)
{
    const uint32_t recv_num_channels = mhu_get_num_mhu_channels(mhu_recv_device, type);
    uint32_t mhu_err;
    uint32_t recv_signal;

    /* ACK current transfer by clearing all channels */
    for (uint32_t i = 0; i < recv_num_channels; ++i) {
        mhu_err = mhu_channel_clear(mhu_recv_device, i, type);
        if (mhu_err != 0) {
            return mhu_err;
        }
    }

    /* Wait for next sender transfer */
    do {
        mhu_err = mhu_channel_receive_device_receive(mhu_recv_device, recv_num_channels - 1,
                                                     &recv_signal, type);
        if (mhu_err != 0) {
            return mhu_err;
        }
    } while ((recv_signal & MHU_NOTIFY_VALUE) != MHU_NOTIFY_VALUE);

    return 0;
}

static enum sfcp_hal_error_t mhu_message_is_available(void *mhu_recv_device, bool *is_available,
                                                      enum sfcp_platform_device_type_t type)
{
    const uint32_t num_channels = mhu_get_num_mhu_channels(mhu_recv_device, type);
    uint32_t mhu_err;
    uint32_t value;

    mhu_err = mhu_channel_receive_device_receive(mhu_recv_device, num_channels - 1, &value, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    *is_available = (value == MHU_NOTIFY_VALUE);

    return SFCP_HAL_ERROR_SUCCESS;
}

static enum sfcp_hal_error_t mhu_check_message_alignment(const uint8_t *message,
                                                         size_t message_size)
{
    if ((message == NULL) || (((uintptr_t)message % sizeof(uint32_t)) != 0)) {
        return SFCP_HAL_ERROR_INVALID_MESSAGE_ARGUMENT;
    }

    if (message_size == 0) {
        return SFCP_HAL_ERROR_INVALID_MESSAGE_SIZE;
    }

    return 0;
}

static enum sfcp_hal_error_t mhu_send_message(void *mhu_send_device, void *mhu_recv_device,
                                              const uint8_t *message, size_t message_size,
                                              enum sfcp_platform_device_type_t type)
{
    const uint32_t num_channels = mhu_get_num_mhu_channels(mhu_send_device, type);
    uint32_t channel;
    uint32_t mhu_err;
    bool is_available;
    const uint32_t *message_ptr;
    uint32_t message_send_buf;
    size_t bytes_left;

    mhu_err = mhu_check_message_alignment(message, message_size);
    if (mhu_err != 0) {
        return mhu_err;
    }

    /* Check for incoming message on receiver device and do not allow sending
     * a message while another is pending
     */
    mhu_err = mhu_message_is_available(mhu_recv_device, &is_available, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    if (is_available) {
        return SFCP_HAL_ERROR_SEND_MESSAGE_BUS_BUSY;
    }

    mhu_err = mhu_initiate_transfer(mhu_send_device, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    /* First send over the size of the actual message */
    channel = 0;
    mhu_err = mhu_channel_send(mhu_send_device, channel, message_size, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    channel++;
    message_ptr = (const uint32_t *)message;
    bytes_left = message_size;
    while (bytes_left > 0) {
        if (bytes_left >= sizeof(uint32_t)) {
            message_send_buf = *message_ptr++;
            bytes_left -= sizeof(uint32_t);
        } else {
            /* A few bytes still to send, pad the remaining bytes */
            message_send_buf = 0;
            memcpy(&message_send_buf, message_ptr, bytes_left);
            bytes_left = 0;
        }

        mhu_err = mhu_channel_send(mhu_send_device, channel, message_send_buf, type);
        if (mhu_err != 0) {
            return mhu_err;
        }

        if (++channel == (num_channels - 1)) {
            mhu_err = mhu_send_signal_poll_loop(mhu_send_device, mhu_recv_device, type);
            if (mhu_err != 0) {
                return mhu_err;
            }

            channel = 0;
        }
    }

    if (channel != 0) {
        mhu_err = mhu_send_signal_poll_loop(mhu_send_device, mhu_recv_device, type);
        if (mhu_err != 0) {
            return mhu_err;
        }
    }

    mhu_err = mhu_close_transfer(mhu_send_device, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

enum sfcp_hal_error_t sfcp_hal_send_message(sfcp_link_id_t link_id, const uint8_t *message,
                                            size_t message_size)
{
    struct sfcp_platform_device_t send_device, recv_device;

    send_device = sfcp_platform_get_send_device(link_id);
    recv_device = sfcp_platform_get_receive_device(link_id);

    switch (send_device.type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_send_message((void *)send_device.device, (void *)recv_device.device, message,
                                message_size, SFCP_PLATFORM_DEVICE_TYPE_MHUV2);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_send_message((void *)send_device.device, (void *)recv_device.device, message,
                                message_size, SFCP_PLATFORM_DEVICE_TYPE_MHUV3);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

enum sfcp_hal_error_t sfcp_hal_is_message_available(sfcp_link_id_t link_id, bool *is_available)
{
    struct sfcp_platform_device_t device;

    device = sfcp_platform_get_receive_device(link_id);

    switch (device.type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_message_is_available((void *)device.device, is_available,
                                        SFCP_PLATFORM_DEVICE_TYPE_MHUV2);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_message_is_available((void *)device.device, is_available,
                                        SFCP_PLATFORM_DEVICE_TYPE_MHUV3);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

static enum sfcp_hal_error_t mhu_get_receive_message_size(void *mhu_recv_device,
                                                          size_t *message_size,
                                                          enum sfcp_platform_device_type_t type)
{
    uint32_t mhu_err;

    mhu_err =
        mhu_channel_receive_device_receive(mhu_recv_device, 0, (uint32_t *)message_size, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

enum sfcp_hal_error_t sfcp_hal_get_receive_message_size(sfcp_link_id_t link_id,
                                                        size_t *message_size)
{
    struct sfcp_platform_device_t device;

    device = sfcp_platform_get_receive_device(link_id);

    switch (device.type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_get_receive_message_size((void *)device.device, message_size,
                                            SFCP_PLATFORM_DEVICE_TYPE_MHUV2);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_get_receive_message_size((void *)device.device, message_size,
                                            SFCP_PLATFORM_DEVICE_TYPE_MHUV3);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

static enum sfcp_hal_error_t mhu_receive_message(void *mhu_recv_device, uint8_t *message,
                                                 size_t total_message_size, size_t already_received,
                                                 size_t size_to_receive,
                                                 enum sfcp_platform_device_type_t type)
{
    const uint32_t num_channels = mhu_get_num_mhu_channels(mhu_recv_device, type);
    uint32_t mhu_err;
    uint32_t channel;
    uint32_t *message_ptr;
    size_t bytes_left;
    size_t already_received_words;
    uint32_t message_recv_buf;

    mhu_err = mhu_check_message_alignment(message, size_to_receive);
    if (mhu_err != 0) {
        return mhu_err;
    }

    /* Must have only already received 4-byte aligned size */
    if ((already_received % sizeof(uint32_t)) != 0) {
        return SFCP_HAL_ERROR_INVALID_MESSAGE_ARGUMENT;
    }

    already_received_words = already_received / sizeof(uint32_t);

    /* First pass only has num_channels - 2 words as 1 word
     * for message size and other for signalling */
    if (already_received_words < (num_channels - 2)) {
        channel = 1 + already_received_words;
    } else {
        channel = (already_received_words - (num_channels - 2)) % (num_channels - 1);
    }

    message_ptr = (uint32_t *)message;
    bytes_left = size_to_receive;
    while (bytes_left > 0) {
        size_t total_received;

        mhu_err =
            mhu_channel_receive_device_receive(mhu_recv_device, channel, &message_recv_buf, type);
        if (mhu_err != 0) {
            return mhu_err;
        }

        if (bytes_left >= sizeof(uint32_t)) {
            *message_ptr++ = message_recv_buf;
            bytes_left -= sizeof(uint32_t);
        } else {
            memcpy(message_ptr, &message_recv_buf, bytes_left);
            bytes_left = 0;
        }

        total_received = (size_to_receive - bytes_left) + already_received;

        /* Only wait for next transfer if there is still missing data */
        if ((++channel == (num_channels - 1)) && (total_message_size > total_received)) {
            /* Busy wait for next transfer */
            mhu_err = mhu_recv_signal_poll_loop(mhu_recv_device, type);
            if (mhu_err != 0) {
                return mhu_err;
            }

            channel = 0;
        }
    }

    /* Only clear channels on exit if we have received the
     * whole message */
    if (total_message_size == (already_received + size_to_receive)) {
        for (uint32_t i = 0; i < num_channels; i++) {
            mhu_err = mhu_channel_clear(mhu_recv_device, i, type);
            if (mhu_err != 0) {
                return mhu_err;
            }
        }
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

enum sfcp_hal_error_t sfcp_hal_receive_message(sfcp_link_id_t link_id, uint8_t *message,
                                               size_t total_message_size, size_t already_received,
                                               size_t size_to_receive)
{
    struct sfcp_platform_device_t device;
    enum sfcp_hal_error_t hal_error;
    bool message_is_available;

    device = sfcp_platform_get_receive_device(link_id);

    /* Cannot receive more than the total message size */
    if ((already_received + size_to_receive) > total_message_size) {
        return SFCP_HAL_ERROR_INVALID_RECEIVE_SIZE;
    }

    hal_error = sfcp_hal_is_message_available(link_id, &message_is_available);
    if (hal_error != SFCP_HAL_ERROR_SUCCESS) {
        return hal_error;
    }

    if (!message_is_available) {
        return SFCP_HAL_ERROR_MESSAGE_NOT_AVAILABLE;
    }

    switch (device.type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        return mhu_receive_message((void *)device.device, message, total_message_size,
                                   already_received, size_to_receive,
                                   SFCP_PLATFORM_DEVICE_TYPE_MHUV2);
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        return mhu_receive_message((void *)device.device, message, total_message_size,
                                   already_received, size_to_receive,
                                   SFCP_PLATFORM_DEVICE_TYPE_MHUV3);
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

static enum sfcp_hal_error_t mhu_init_sender(void *mhu_sender_dev,
                                             enum sfcp_platform_device_type_t type)
{
    uint32_t mhu_err;
    uint32_t num_channels;

    mhu_err = mhu_driver_init(mhu_sender_dev, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    num_channels = mhu_get_num_mhu_channels(mhu_sender_dev, type);
    if (num_channels < MHU_REQUIRED_NUMBER_CHANNELS) {
        return SFCP_HAL_ERROR_DEVICE_UNSUPPORTED;
    }

    /* Sender interrupts are not used */
    for (uint32_t channel = 0; channel < num_channels; channel++) {
        mhu_err = mhu_channel_interrupt_disable(mhu_sender_dev, channel, type);
        if (mhu_err != 0) {
            return mhu_err;
        }
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

static enum sfcp_hal_error_t mhu_init_receiver(void *mhu_receiver_dev,
                                               enum sfcp_platform_device_type_t type)
{
    uint32_t mhu_err;
    uint32_t num_channels;

    /* Initialize MHUv3 */
    mhu_err = mhu_driver_init(mhu_receiver_dev, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    num_channels = mhu_get_num_mhu_channels(mhu_receiver_dev, type);
    if (num_channels < MHU_REQUIRED_NUMBER_CHANNELS) {
        return SFCP_HAL_ERROR_DEVICE_UNSUPPORTED;
    }

    /* Mask all channels except the notifying channel */
    for (uint32_t channel = 0; channel < (num_channels - 1); channel++) {
        mhu_err = mhu_channel_mask_set(mhu_receiver_dev, channel, UINT32_MAX, type);
        if (mhu_err != 0) {
            return mhu_err;
        }
    }

    /* Unmask doorbell notification channel interrupt */
    mhu_err = mhu_channel_mask_clear(mhu_receiver_dev, num_channels - 1, UINT32_MAX, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    /*
     * Enable the doorbell channel's contribution to mailbox combined
     * interrupt.
     */
    mhu_err = mhu_channel_interrupt_enable(mhu_receiver_dev, num_channels - 1, type);
    if (mhu_err != 0) {
        return mhu_err;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

static enum sfcp_hal_error_t init_sender_receiver(struct sfcp_platform_device_t device,
                                                  bool is_sender)
{
    switch (device.type) {
#ifdef MHU_V2_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV2:
        if (is_sender) {
            return mhu_init_sender((void *)device.device, SFCP_PLATFORM_DEVICE_TYPE_MHUV2);
        } else {
            return mhu_init_receiver((void *)device.device, SFCP_PLATFORM_DEVICE_TYPE_MHUV2);
        }
#endif
#ifdef MHU_V3_ENABLED
    case SFCP_PLATFORM_DEVICE_TYPE_MHUV3:
        if (is_sender) {
            return mhu_init_sender((void *)device.device, SFCP_PLATFORM_DEVICE_TYPE_MHUV3);
        } else {
            return mhu_init_receiver((void *)device.device, SFCP_PLATFORM_DEVICE_TYPE_MHUV3);
        }
#endif
    default:
        return SFCP_HAL_ERROR_UNSUPPORTED_DEVICE;
    }

    return SFCP_HAL_ERROR_SUCCESS;
}

enum sfcp_hal_error_t sfcp_hal_init(void)
{
    enum sfcp_hal_error_t hal_err;
    uint32_t rse_id;
    const uint8_t *routing_tables;
    size_t routing_tables_size;
    sfcp_link_id_t link_id;

    get_routing_tables_and_rse_id(&routing_tables, &routing_tables_size, &rse_id);

    for (sfcp_node_id_t node = 0; node < routing_tables_size; node++) {
        if (node == rse_id) {
            continue;
        }

        link_id = routing_tables[node];

        hal_err = init_sender_receiver(sfcp_platform_get_send_device(link_id), true);
        if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
            return hal_err;
        }

        hal_err = init_sender_receiver(sfcp_platform_get_receive_device(link_id), false);
        if (hal_err != SFCP_HAL_ERROR_SUCCESS) {
            return hal_err;
        }
    }

    return SFCP_HAL_ERROR_SUCCESS;
}
