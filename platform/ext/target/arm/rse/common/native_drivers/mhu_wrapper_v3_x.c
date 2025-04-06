/*
 * Copyright (c) 2023 Arm Limited
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
#include "mhu_v3_x.h"

#include <stdint.h>
#include <string.h>

#define MHU_NOTIFY_VALUE    (1234u)

#ifndef ALIGN_UP
#define ALIGN_UP(num, align)    (((num) + ((align) - 1)) & ~((align) - 1))
#endif

/*
 * MHUv3 Wrapper utility macros
 */
#define IS_ALIGNED(val, align) (val == ALIGN_UP(val, align))

enum mhu_error_t signal_and_wait_for_clear(
       void* mhu_sender_dev, uint32_t value)
{
    enum mhu_v3_x_error_t err;
    struct mhu_v3_x_dev_t *dev;
    uint8_t num_channels;
    uint32_t read_val;

    dev = (struct mhu_v3_x_dev_t *)mhu_sender_dev;

    if (dev == NULL || dev->base == 0) {
        return MHU_ERR_SIGNAL_WAIT_CLEAR_INVALID_ARG;
    }

    err = mhu_v3_x_get_num_channel_implemented(dev, MHU_V3_X_CHANNEL_TYPE_DBCH,
            &num_channels);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    /* Wait for any pending acknowledgement from transmitter side */
    do {
        err = mhu_v3_x_doorbell_read(dev, num_channels - 1, &read_val);
        if (err != MHU_V_3_X_ERR_NONE) {
            return err;
        }
    } while ((read_val & value) == value);

    /* Use the last channel to notify that a transfer is ready */
    err = mhu_v3_x_doorbell_write(dev, num_channels - 1, value);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    /* Wait until receiver side acknowledges the transfer */
    do {
        err = mhu_v3_x_doorbell_read(dev, num_channels - 1, &read_val);
        if (err != MHU_V_3_X_ERR_NONE) {
            return err;
        }
    } while ((read_val & value) == value);

    return err;
}

enum mhu_error_t wait_for_signal_and_clear (
    void* mhu_receiver_dev, uint32_t value)
{
    enum mhu_v3_x_error_t err;
    struct mhu_v3_x_dev_t *dev;
    uint8_t num_channels;
    uint32_t read_val;

    dev = (struct mhu_v3_x_dev_t *)mhu_receiver_dev;

    if (dev == NULL || dev->base == 0) {
        return MHU_ERR_WAIT_SIGNAL_CLEAR_INVALID_ARG;
    }

    err = mhu_v3_x_get_num_channel_implemented(dev, MHU_V3_X_CHANNEL_TYPE_DBCH,
            &num_channels);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    /* Wait on status register for transmitter side to send data */
    do {
        err = mhu_v3_x_doorbell_read(dev, num_channels - 1, &read_val);
        if (err != MHU_V_3_X_ERR_NONE) {
            return err;
        }
    } while ((read_val & value) != value);

    /* Acknowledge the transfer and clear the doorbell register */
    err = mhu_v3_x_doorbell_clear(dev, num_channels - 1, value);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t clear_and_wait_for_signal (
    void* mhu_receiver_dev, uint32_t value)
{
    enum mhu_v3_x_error_t err;
    struct mhu_v3_x_dev_t *dev;
    uint8_t num_channels;
    uint32_t read_val;

    dev = (struct mhu_v3_x_dev_t *)mhu_receiver_dev;

    if (dev == NULL || dev->base == 0) {
        return MHU_ERR_CLEAR_WAIT_SIGNAL_INVALID_ARG;
    }

    err = mhu_v3_x_get_num_channel_implemented(dev, MHU_V3_X_CHANNEL_TYPE_DBCH,
            &num_channels);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    /* Clear all channels */
    for (int i = 0; i < num_channels; ++i) {
        err = mhu_v3_x_doorbell_clear(dev, i, UINT32_MAX);
        if (err != MHU_V_3_X_ERR_NONE) {
            return err;
        }
    }

    /* Wait for transmitter side to send data */
    do {
        err = mhu_v3_x_doorbell_read(dev, num_channels - 1, &read_val);
        if (err != MHU_V_3_X_ERR_NONE) {
            return err;
        }
    } while (read_val != value);

    return err;
}

static enum mhu_error_t validate_buffer_params(uintptr_t buf_addr,
                                               size_t buf_size)
{
    if ((buf_addr == 0) || (!IS_ALIGNED(buf_addr, 4))) {
        return MHU_ERR_VALIDATE_BUFFER_PARAMS_INVALID_ARG;
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_init_sender(void *mhu_sender_dev)
{
    enum mhu_v3_x_error_t err;
    struct mhu_v3_x_dev_t *dev;
    uint8_t num_ch;
    uint32_t ch;

    dev = (struct mhu_v3_x_dev_t *)mhu_sender_dev;

    if (dev == NULL || dev->base == 0) {
        return MHU_ERR_INIT_SENDER_INVALID_ARG;
    }

    /* Initialize MHUv3 */
    err = mhu_v3_x_driver_init(dev);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    /* Read the number of doorbell channels implemented in the MHU */
    err = mhu_v3_x_get_num_channel_implemented(
        dev, MHU_V3_X_CHANNEL_TYPE_DBCH, &num_ch);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    } else if (num_ch < 2) {
        /* This wrapper requires at least two channels to be implemented */
        return MHU_ERR_INIT_SENDER_UNSUPPORTED;
    }

    /*
     * The sender polls the postbox doorbell channel window status register to
     * get notified about successful transfer. So, disable the doorbell
     * channel's contribution to postbox combined interrupt.
     *
     * Also, clear and disable the postbox doorbell channel transfer acknowledge
     * interrupt.
     */
    for (ch = 0; ch < num_ch; ++ch) {
        err = mhu_v3_x_channel_interrupt_disable(
            dev, ch, MHU_V3_X_CHANNEL_TYPE_DBCH);
        if (err != MHU_V_3_X_ERR_NONE) {
            return err;
        }
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_init_receiver(void *mhu_receiver_dev)
{
    enum mhu_v3_x_error_t err;
    struct mhu_v3_x_dev_t *dev;
    uint32_t ch;
    uint8_t num_ch;

    dev = (struct mhu_v3_x_dev_t *)mhu_receiver_dev;

    if (dev == NULL || dev->base == 0) {
        return MHU_ERR_INIT_RECEIVER_INVALID_ARG;
    }

    /* Initialize MHUv3 */
    err = mhu_v3_x_driver_init(dev);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    /* Read the number of doorbell channels implemented in the MHU */
    err = mhu_v3_x_get_num_channel_implemented(
        dev, MHU_V3_X_CHANNEL_TYPE_DBCH, &num_ch);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    } else if (num_ch < 2) {
        /* This wrapper requires at least two channels to be implemented */
        return MHU_ERR_INIT_RECEIVER_UNSUPPORTED;
    }

    /* Mask all channels except the notifying channel */
    for (ch = 0; ch < (num_ch - 1); ++ch) {
        err = mhu_v3_x_doorbell_mask_set(dev, ch, UINT32_MAX);
        if (err != MHU_V_3_X_ERR_NONE) {
            return err;
        }
    }

    /* Unmask doorbell notification channel interrupt */
    err = mhu_v3_x_doorbell_mask_clear(dev, (num_ch - 1), UINT32_MAX);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    /*
     * Enable the doorbell channel's contribution to mailbox combined
     * interrupt.
     */
    err = mhu_v3_x_channel_interrupt_enable(dev, (num_ch - 1),
                                                MHU_V3_X_CHANNEL_TYPE_DBCH);
    if (err != MHU_V_3_X_ERR_NONE) {
        return err;
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_send_data(void *mhu_sender_dev, const uint8_t *send_buffer,
                               size_t size)
{
    enum mhu_error_t mhu_err;
    enum mhu_v3_x_error_t mhu_v3_err;
    uint8_t num_channels;
    uint8_t chan;
    uint32_t *buffer;
    struct mhu_v3_x_dev_t *dev;

    if (size == 0) {
        return MHU_ERR_NONE;
    }

    dev = (struct mhu_v3_x_dev_t *)mhu_sender_dev;
    chan = 0;

    if (dev == NULL || dev->base == 0) {
        return MHU_ERR_SEND_DATA_INVALID_ARG;
    }

    mhu_err = validate_buffer_params((uintptr_t)send_buffer, size);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    mhu_v3_err = mhu_v3_x_get_num_channel_implemented(dev, MHU_V3_X_CHANNEL_TYPE_DBCH,
            &num_channels);
    if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
        return mhu_v3_err;
    }

    /* First send over the size of the actual message. */
    mhu_v3_err = mhu_v3_x_doorbell_write(dev, chan, (uint32_t)size);
    if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
        return mhu_v3_err;
    }
    chan++;

    buffer = (uint32_t *)send_buffer;
    for (size_t i = 0; i < size; i += 4) {
        mhu_v3_err = mhu_v3_x_doorbell_write(dev, chan, *buffer++);
        if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
            return mhu_v3_err;
        }
        if (++chan == (num_channels - 1)) {
            /* Using the last channel for notifications */
            mhu_err = signal_and_wait_for_clear(dev, MHU_NOTIFY_VALUE);
            if (mhu_err != MHU_ERR_NONE) {
                return mhu_err;
            }
            chan = 0;
        }
    }

    if (chan != 0) {
        /* Using the last channel for notifications */
        mhu_err = signal_and_wait_for_clear(dev, MHU_NOTIFY_VALUE);
        if (mhu_err != MHU_ERR_NONE) {
            return mhu_err;
        }
    }

    return MHU_ERR_NONE;
}

enum mhu_error_t mhu_wait_data(void *mhu_receiver_dev)
{
    struct mhu_v3_x_dev_t *dev = mhu_receiver_dev;
    enum mhu_v3_x_error_t mhu_v3_err;
    uint8_t num_channels;
    uint32_t read_val;

    mhu_v3_err = mhu_v3_x_get_num_channel_implemented(dev, MHU_V3_X_CHANNEL_TYPE_DBCH,
                                               &num_channels);
    if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
        return mhu_v3_err;
    }

    /* Wait for transmitter side to send data */
    do {
        mhu_v3_err = mhu_v3_x_doorbell_read(dev, num_channels - 1, &read_val);
        if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
            return mhu_v3_err;
        }
    } while (read_val != MHU_NOTIFY_VALUE);

    return mhu_v3_err;
}


enum mhu_error_t mhu_receive_data(void *mhu_receiver_dev,
                                  uint8_t *receive_buffer, size_t *size)
{
    enum mhu_error_t mhu_err;
    enum mhu_v3_x_error_t mhu_v3_err;
    uint32_t msg_len;
    uint8_t num_channels;
    uint8_t chan;
    uint32_t *buffer;
    struct mhu_v3_x_dev_t *dev;

    dev = (struct mhu_v3_x_dev_t *)mhu_receiver_dev;
    chan = 0;

    if (dev == NULL || dev->base == 0) {
        return MHU_ERR_RECEIVE_DATA_INVALID_ARG;
    }

    mhu_err = validate_buffer_params((uintptr_t)receive_buffer, *size);
    if (mhu_err != MHU_ERR_NONE) {
        return mhu_err;
    }

    mhu_v3_err = mhu_v3_x_get_num_channel_implemented(dev, MHU_V3_X_CHANNEL_TYPE_DBCH,
            &num_channels);
    if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
        return mhu_v3_err;
    }

    /* The first word is the length of the actual message. */
    mhu_v3_err = mhu_v3_x_doorbell_read(dev, chan, &msg_len);
    if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
        return mhu_v3_err;
    }
    chan++;

    if (*size < msg_len) {
        /* Message buffer too small */
        *size = msg_len;
        return MHU_ERR_RECEIVE_DATA_BUFFER_TOO_SMALL;
    }

    buffer = (uint32_t *)receive_buffer;
    for (size_t i = 0; i < msg_len; i += 4) {
        mhu_v3_err = mhu_v3_x_doorbell_read(dev, chan, buffer++);
        if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
            return mhu_v3_err;
        }

        /* Only wait for next transfer if there is still missing data. */
        if (++chan == (num_channels - 1) && (msg_len - i) > 4) {
            /* Busy wait for next transfer */
            mhu_err = clear_and_wait_for_signal(dev, MHU_NOTIFY_VALUE);
            if (mhu_err != MHU_ERR_NONE) {
                return mhu_err;
            }
            chan = 0;
        }
    }

    /* Clear all channels */
    for (int i = 0; i < num_channels; ++i) {
        mhu_v3_err = mhu_v3_x_doorbell_clear(dev, i, UINT32_MAX);
        if (mhu_v3_err != MHU_V_3_X_ERR_NONE) {
            return mhu_v3_err;
        }
    }

    *size = msg_len;

    return MHU_ERR_NONE;
}
