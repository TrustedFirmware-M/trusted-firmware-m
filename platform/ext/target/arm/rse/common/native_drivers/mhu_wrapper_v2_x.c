/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mhu.h"

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#include "mhu_v2_x.h"

#define MHU_NOTIFY_VALUE    (1234u)

#ifndef ALIGN_UP
#define ALIGN_UP(num, align)    (((num) + ((align) - 1)) & ~((align) - 1))
#endif

/*
 * MHUv2 Wrapper utility macros
 */
#define IS_ALIGNED(val, align) (val == ALIGN_UP(val, align))

enum mhu_error_t
signal_and_wait_for_clear(void *mhu_sender_dev, uint32_t value)
{
    enum mhu_v2_x_error_t err;
    struct mhu_v2_x_dev_t *dev;
    uint32_t channel_notify;
    uint32_t wait_val;

    dev = (struct mhu_v2_x_dev_t *)mhu_sender_dev;

    if (dev == NULL) {
        return MHU_ERR_SIGNAL_WAIT_CLEAR_INVALID_ARG;
    }

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    if (dev->base == 0) {
        return MHU_ERR_SIGNAL_WAIT_CLEAR_INVALID_ARG;
    }

    /* Use the last channel for notifications */
    channel_notify = mhu_v2_x_get_num_channel_implemented(dev) - 1;

    /* FIXME: Avoid wasting a whole channel for notifying */
    err = mhu_v2_x_channel_send(dev, channel_notify, value);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    do {
        err = mhu_v2_x_channel_poll(dev, channel_notify, &wait_val);
        if (err != MHU_V_2_X_ERR_NONE) {
            break;
        }
    } while (wait_val != 0);

    return err;
}

enum mhu_error_t
wait_for_signal_and_clear(void *mhu_receiver_dev, uint32_t value)
{
    enum mhu_v2_x_error_t err;
    struct mhu_v2_x_dev_t *dev;
    uint32_t channel_notify;
    uint32_t wait_val;

    dev = (struct mhu_v2_x_dev_t *)mhu_receiver_dev;

    if (dev == NULL) {
        return MHU_ERR_WAIT_SIGNAL_CLEAR_INVALID_ARG;
    }

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    if (dev->base == 0) {
        return MHU_ERR_WAIT_SIGNAL_CLEAR_INVALID_ARG;
    }


    /* Use the last channel for notifications */
    channel_notify = mhu_v2_x_get_num_channel_implemented(dev) - 1;

    do {
        /* Using the last channel for notifications */
        err = mhu_v2_x_channel_receive(dev, channel_notify, &wait_val);
        if (err != MHU_V_2_X_ERR_NONE) {
            return err;
        }
    } while (wait_val != value);

    /* Clear the last channel */
    err = mhu_v2_x_channel_clear(dev, channel_notify);

    return err;
}

static enum mhu_v2_x_error_t
clear_and_wait_for_signal(struct mhu_v2_x_dev_t *dev)
{
    enum mhu_v2_x_error_t err;
    uint32_t num_channels = mhu_v2_x_get_num_channel_implemented(dev);
    uint32_t val, i;

    /* Clear all channels */
    for (i = 0; i < num_channels; ++i) {
        err = mhu_v2_x_channel_clear(dev, i);
        if (err != MHU_V_2_X_ERR_NONE) {
            return err;
        }
    }

    do {
        /* Using the last channel for notifications */
        err = mhu_v2_x_channel_receive(dev, num_channels - 1, &val);
        if (err != MHU_V_2_X_ERR_NONE) {
            break;
        }
    } while (val != MHU_NOTIFY_VALUE);

    return err;
}

/**
 * @brief For simplicity, require:
 *          - the buffer address to be 4-byte aligned.
 *          - the buffer size to be a multiple of 4.
 */
static enum mhu_error_t validate_buffer_params(uintptr_t buf_addr,
                                               size_t buf_size)
{
    if ((buf_addr == 0) ||
        (!IS_ALIGNED(buf_addr, 4)) ||
        (!IS_ALIGNED(buf_size, 4)) ||
        (buf_size == 0)) {
        return MHU_ERR_VALIDATE_BUFFER_PARAMS_INVALID_ARG;
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_init_sender(void *mhu_sender_dev)
{
    enum mhu_v2_x_error_t err;
    struct mhu_v2_x_dev_t *dev = mhu_sender_dev;

    if (dev == NULL) {
        return MHU_ERR_INIT_SENDER_INVALID_ARG;
    }

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    if (dev->base == 0) {
        return MHU_ERR_INIT_SENDER_INVALID_ARG;
    }

    err = mhu_v2_x_driver_init(dev, MHU_REV_READ_FROM_HW);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    /* This wrapper requires at least two channels to be implemented */
    if (mhu_v2_x_get_num_channel_implemented(dev) < 2) {
        return MHU_ERR_INIT_SENDER_UNSUPPORTED;
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_init_receiver(void *mhu_receiver_dev)
{
    enum mhu_v2_x_error_t err;
    struct mhu_v2_x_dev_t *dev = mhu_receiver_dev;
    uint32_t num_channels, i;

    if (dev == NULL) {
        return MHU_ERR_INIT_RECEIVER_INVALID_ARG;
    }

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    if (dev->base == 0) {
        return MHU_ERR_INIT_RECEIVER_INVALID_ARG;
    }

    err = mhu_v2_x_driver_init(dev, MHU_REV_READ_FROM_HW);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    num_channels = mhu_v2_x_get_num_channel_implemented(dev);

    /* This wrapper requires at least two channels to be implemented */
    if (num_channels < 2) {
        return MHU_ERR_INIT_RECEIVER_UNSUPPORTED;
    }

    /* Mask all channels except the notifying channel */
    for (i = 0; i < (num_channels - 1); ++i) {
        err = mhu_v2_x_channel_mask_set(dev, i, UINT32_MAX);
        if (err != MHU_V_2_X_ERR_NONE) {
            return err;
        }
    }

    /* The last channel is used for notifications */
    err = mhu_v2_x_channel_mask_clear(dev, (num_channels - 1), UINT32_MAX);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    err = mhu_v2_x_interrupt_enable(dev, MHU_2_1_INTR_CHCOMB_MASK);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_send_data(void *mhu_sender_dev,
                               const uint8_t *send_buffer,
                               size_t size)
{
    enum mhu_v2_x_error_t err;
    enum mhu_error_t mhu_err;
    struct mhu_v2_x_dev_t *dev = (struct mhu_v2_x_dev_t *)mhu_sender_dev;
    uint32_t num_channels = mhu_v2_x_get_num_channel_implemented(dev);
    uint32_t chan = 0;
    uint32_t i;
    uint32_t *p;

    assert(dev != NULL);

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    assert(dev->base != (uintptr_t)NULL);

    mhu_err = validate_buffer_params((uintptr_t)send_buffer, size);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    err = mhu_v2_x_initiate_transfer(dev);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    /* First send over the size of the actual message. */
    err = mhu_v2_x_channel_send(dev, chan, (uint32_t)size);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }
    chan++;

    p = (uint32_t *)send_buffer;
    for (i = 0; i < size; i += 4) {
        err = mhu_v2_x_channel_send(dev, chan, *p++);
        if (err != MHU_V_2_X_ERR_NONE) {
            return err;
        }
        if (++chan == (num_channels - 1)) {
            mhu_err = signal_and_wait_for_clear(dev, MHU_NOTIFY_VALUE);
            if (mhu_err != MHU_ERR_NONE) {
                return mhu_err;
            }
            chan = 0;
        }
    }

    /* Signal the end of transfer.
     *   It's not required to send a signal when the message was
     *   perfectly-aligned ((num_channels - 1) channels were used in the last
     *   round) preventing it from signaling twice at the end of transfer.
     */
    if (chan != 0) {
        mhu_err = signal_and_wait_for_clear(dev, MHU_NOTIFY_VALUE);
        if (mhu_err != MHU_ERR_NONE) {
            return mhu_err;
        }
    }

    err = mhu_v2_x_close_transfer(dev);
    return err;
}

enum mhu_error_t mhu_data_is_available(void *mhu_receiver_dev, bool *is_available)
{
    enum mhu_v2_x_error_t err;
    struct mhu_v2_x_dev_t *dev = mhu_receiver_dev;
    const uint32_t num_channels = mhu_v2_x_get_num_channel_implemented(dev);
    uint32_t val;

    assert(dev != NULL);

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    assert(dev->base != (uintptr_t)NULL);

    /* Using the last channel for notifications */
    err = mhu_v2_x_channel_receive(dev, num_channels - 1, &val);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    *is_available = (val == MHU_NOTIFY_VALUE);

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_wait_data(void *mhu_receiver_dev)
{
    enum mhu_error_t mhu_err;
    bool is_available;

    do {
        mhu_err = mhu_data_is_available(mhu_receiver_dev, &is_available);
        if (mhu_err != MHU_ERR_NONE) {
            return mhu_err;
        }
    } while (!is_available);

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_get_receive_msg_len(void *mhu_receiver_dev, size_t *msg_len)
{
    enum mhu_v2_x_error_t err;
    struct mhu_v2_x_dev_t *dev = (struct mhu_v2_x_dev_t *)mhu_receiver_dev;

    assert(dev != NULL);

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    assert(dev->base != (uintptr_t)NULL);

    /* The first word is the length of the actual message. */
    err = mhu_v2_x_channel_receive(dev, 0, (uint32_t *)msg_len);
    if (err != MHU_V_2_X_ERR_NONE) {
        return err;
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_receive_data(void *mhu_receiver_dev, uint8_t *receive_buffer, size_t msg_len)
{
    enum mhu_error_t mhu_err;
    enum mhu_v2_x_error_t err;
    struct mhu_v2_x_dev_t *dev = mhu_receiver_dev;
    uint32_t num_channels = mhu_v2_x_get_num_channel_implemented(dev);
    uint32_t chan;
    uint32_t i;
    uint32_t *p;

    assert(dev != NULL);

    if (dev->version != 2) {
        return MHU_ERR_INVALID_VERSION;
    }

    assert(dev->base != (uintptr_t)NULL);

    mhu_err = validate_buffer_params((uintptr_t)receive_buffer, msg_len);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    /* Chan 0 is initially used for the message length so start with chan 1 */
    chan = 1;
    p = (uint32_t *)receive_buffer;
    for (i = 0; i < msg_len; i += 4) {
        err = mhu_v2_x_channel_receive(dev, chan, p++);
        if (err != MHU_V_2_X_ERR_NONE) {
            return err;
        }

        /* Only wait for next transfer if there is still missing data. */
        if (++chan == (num_channels - 1) && (msg_len - i) > 4) {
            /* Busy wait for next transfer */
            err = clear_and_wait_for_signal(dev);
            if (err != MHU_V_2_X_ERR_NONE) {
                return err;
            }
            chan = 0;
        }
    }

    /* Clear all channels */
    for (i = 0; i < num_channels; ++i) {
        err = mhu_v2_x_channel_clear(dev, i);
        if (err != MHU_V_2_X_ERR_NONE) {
            return err;
        }
    }

    return MHU_ERR_NONE;
}
