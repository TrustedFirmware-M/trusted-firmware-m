/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "dcsu_drv.h"

#include "dcsu_reg_defs.h"
#include "dcsu_hal.h"
#include "fatal_error.h"

#include "dcsu_config.h"

#include <string.h>
#include <assert.h>

#define MAX_RX_SIZE (sizeof(((struct _dcsu_reg_map_t *)0)->diag_rx_data))
#define MAX_TX_SIZE (sizeof(((struct _dcsu_reg_map_t *)0)->diag_tx_data))

static enum dcsu_rx_command get_rx_command(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    return p_dcsu->diag_rx_command & 0xFF;
}

static enum dcsu_error_t rx_msg_err_to_dcsu_err(enum dcsu_rx_msg_error_t msg_err)
{
    return msg_err == DCSU_RX_MSG_ERROR_SUCCESS ? DCSU_ERROR_NONE :
                                                  DCSU_ERROR_RX_MSG_BASE + msg_err;
}

static enum dcsu_error_t tx_msg_err_to_dcsu_err(enum dcsu_tx_msg_error_t msg_err)
{
    return msg_err == DCSU_TX_MSG_ERROR_SUCCESS ? DCSU_ERROR_NONE :
                                                  DCSU_ERROR_TX_MSG_BASE + msg_err;
}

static enum dcsu_error_t rx_return_send(struct dcsu_dev_t *dev, enum dcsu_rx_msg_error_t msg_err)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    assert(msg_err != 0);
    assert(msg_err < _DCSU_RX_MSG_ERROR_MAX);

    p_dcsu->diag_rx_command = (msg_err & 0xFF) << 24;

    return rx_msg_err_to_dcsu_err(msg_err);
}

void dcsu_wait_for_any_rx_command(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    while (!(p_dcsu->diag_cmd_irq_status & (0b1 << 0))) {
#ifdef DCSU_CONFIG_WFI_ENABLE
        __asm volatile("wfi");
#endif
    }
    p_dcsu->diag_cmd_irq_clear = 0b1 << 0;
}

enum dcsu_error_t dcsu_wait_for_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command)
{
    dcsu_wait_for_any_rx_command(dev);

    if (get_rx_command(dev) != command) {
        return DCSU_ERROR_WAIT_UNEXPECTED_COMMAND;
    }

    return DCSU_ERROR_NONE;
}

static void dcsu_clear_pending_rx_interupt(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    p_dcsu->diag_cmd_irq_clear = 0b1 << 0;
}

enum dcsu_error_t dcsu_poll_for_any_rx_command(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    if (p_dcsu->diag_cmd_irq_status & (0b1 << 0)) {
        return DCSU_ERROR_NONE;
    }
    return DCSU_ERROR_POLL_NO_COMMAND_PENDING;
}

enum dcsu_error_t dcsu_poll_for_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command)
{
    enum dcsu_error_t err;

    err = dcsu_poll_for_any_rx_command(dev);
    if (err != DCSU_ERROR_NONE) {
        return err;
    }

    if (get_rx_command(dev) != command) {
        return DCSU_ERROR_POLL_NO_COMMAND_PENDING;
    }

    return DCSU_ERROR_NONE;
}

void dcsu_wait_for_tx_response(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    while (!(p_dcsu->diag_cmd_irq_status & (0b1 << 1))) {
#ifdef DCSU_CONFIG_WFI_ENABLE
        __asm volatile("wfi");
#endif
    }
    p_dcsu->diag_cmd_irq_clear = 0b1 << 1;
}

static enum dcsu_error_t rx_generate_soc_unique_id(struct dcsu_dev_t *dev)
{
    enum dcsu_rx_msg_error_t msg_err;

    msg_err = dcsu_hal_generate_soc_unique_id();

    return rx_return_send(dev, msg_err);
}

static enum dcsu_error_t rx_write_soc_area(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    enum dcsu_rx_msg_error_t msg_err;
    uint32_t write_num_words = ((p_dcsu->diag_rx_command >> 8) & 0b11) + 1;

    msg_err = dcsu_hal_write_soc_area(p_dcsu->diag_rx_large_param, (uint32_t *)p_dcsu->diag_rx_data,
                                      write_num_words * sizeof(uint32_t));

    return rx_return_send(dev, msg_err);
}

static enum dcsu_error_t rx_compute_integrity_check_soc_area(struct dcsu_dev_t *dev)
{
    enum dcsu_rx_msg_error_t msg_err;

    msg_err = dcsu_hal_compute_integrity_check_soc_area();

    return rx_return_send(dev, msg_err);
}

static enum dcsu_error_t rx_commit_write(struct dcsu_dev_t *dev)
{
    enum dcsu_rx_msg_error_t msg_err;

    if (dev->handler == NULL) {
        msg_err = DCSU_RX_MSG_ERROR_COMMIT_HANDLER_NOT_SET_UP;
        goto out;
    }

    msg_err = dev->handler(dev->rx_buf, dev->rx_buf_len);

out:
    dev->rx_buf_offset = 0;

    return rx_return_send(dev, msg_err);
}

enum dcsu_error_t dcsu_handle_rx_command(struct dcsu_dev_t *dev)
{
    enum dcsu_error_t err;
    size_t size_written;

    err = dcsu_poll_for_any_rx_command(dev);
    if (err != DCSU_ERROR_NONE) {
        return err;
    }

    switch (get_rx_command(dev)) {
    case DCSU_RX_COMMAND_GENERATE_SOC_UNIQUE_ID:
        err = rx_generate_soc_unique_id(dev);
        break;
    case DCSU_RX_COMMAND_WRITE_SOC_AREA:
        err = rx_write_soc_area(dev);
        break;
    case DCSU_RX_COMMAND_COMPUTE_INTEGRITY_CHECK_SOC_AREA:
        err = rx_compute_integrity_check_soc_area(dev);
        break;
    case DCSU_RX_COMMAND_WRITE_DATA:
        err = dcsu_receive_data(dev, dev->rx_buf + dev->rx_buf_offset,
                                dev->rx_buf_len - dev->rx_buf_offset, &size_written);
        dev->rx_buf_offset += size_written;
        break;
    case DCSU_RX_COMMAND_COMMIT_WRITE:
        err = rx_commit_write(dev);
        break;
    default:
        FATAL_ERR(DCSU_ERROR_RX_MSG_BASE + DCSU_RX_MSG_ERROR_INVALID_COMMAND);
        err = rx_return_send(dev, DCSU_RX_MSG_ERROR_INVALID_COMMAND);
    }

    dcsu_clear_pending_rx_interupt(dev);
    return err;
}

enum dcsu_error_t dcsu_respond_to_rx_command(struct dcsu_dev_t *dev, enum dcsu_rx_command command,
                                             enum dcsu_rx_msg_error_t response)
{
    enum dcsu_error_t err;

    err = dcsu_poll_for_rx_command(dev, command);
    if (err != DCSU_ERROR_NONE) {
        return err;
    }

    return rx_return_send(dev, response);
}

static enum dcsu_error_t rx_write_receive(struct dcsu_dev_t *dev, uint8_t *data, size_t data_len,
                                          size_t *data_size)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    uint32_t recv_num_words = ((p_dcsu->diag_rx_command >> 8) & 0b11) + 1;
    uint32_t recv_buf[MAX_RX_SIZE / sizeof(uint32_t)];
    enum dcsu_rx_msg_error_t msg_err;
    enum dcsu_error_t err;

    assert(data_len <= MAX_RX_SIZE);

    err = dcsu_wait_for_rx_command(dev, DCSU_RX_COMMAND_WRITE_DATA);
    if (err != DCSU_ERROR_NONE) {
        msg_err = DCSU_RX_MSG_ERROR_UNEXPECTED_COMMAND;
        goto out;
    }

    if (data_len > recv_num_words * sizeof(uint32_t)) {
        data_len = recv_num_words * sizeof(uint32_t);
    }

    for (uint32_t idx = 0; idx < recv_num_words; idx++) {
        recv_buf[idx] = p_dcsu->diag_rx_data[idx];
    }

    memcpy(data, recv_buf, data_len);

    *data_size = data_len;

    dcsu_clear_pending_rx_interupt(dev);

    msg_err = DCSU_RX_MSG_ERROR_SUCCESS;

out:
    return rx_return_send(dev, msg_err);
}

enum dcsu_error_t dcsu_receive_data(struct dcsu_dev_t *dev, uint8_t *data, size_t data_len,
                                    size_t *data_size)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    size_t total_data_size;
    size_t current_recv_size;
    size_t current_recv_actual_size;
    const size_t max_recv_size = MAX_RX_SIZE;
    size_t data_recv_size;
    enum dcsu_error_t err;

    err = dcsu_wait_for_rx_command(dev, DCSU_RX_COMMAND_WRITE_DATA);
    if (err != DCSU_ERROR_NONE) {
        return err;
    }

    total_data_size = p_dcsu->diag_rx_large_param;

    if (data == NULL) {
        dcsu_clear_pending_rx_interupt(dev);
        return rx_return_send(dev, DCSU_RX_MSG_ERROR_BUFFER_NOT_SET_UP);
    }

    if (total_data_size > data_len) {
        dcsu_clear_pending_rx_interupt(dev);
        return rx_return_send(dev, DCSU_RX_MSG_ERROR_SIZE_TOO_LARGE);
    }

    for (data_recv_size = 0; data_recv_size < total_data_size;) {
        current_recv_size = (data_recv_size + max_recv_size < data_len) ?
                                max_recv_size :
                                (data_len - data_recv_size);
        err = rx_write_receive(dev, data + data_recv_size, current_recv_size,
                               &current_recv_actual_size);
        if (err != DCSU_ERROR_NONE) {
            return err;
        }

        data_recv_size += current_recv_actual_size;
    }

    if (data_size != NULL) {
        *data_size = data_recv_size;
    }

    return DCSU_ERROR_NONE;
}

static enum dcsu_error_t tx_command_send(struct dcsu_dev_t *dev, enum dcsu_tx_command tx_command,
                                         uint32_t data_word_size)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    enum dcsu_tx_msg_error_t msg_err;
    uint32_t tx_command_word = 0;

    tx_command_word |= (data_word_size - 1) << 8;
    tx_command_word |= tx_command & 0xFF;

    p_dcsu->diag_tx_command = tx_command_word;

    /* Now wait for the response */
    dcsu_wait_for_tx_response(dev);

    msg_err = (p_dcsu->diag_tx_command >> 24) & 0xFF;

    return tx_msg_err_to_dcsu_err(msg_err);
}

static enum dcsu_error_t tx_export_send(struct dcsu_dev_t *dev, const uint8_t *data,
                                        size_t data_size)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    uint32_t send_num_words = (data_size + (sizeof(uint32_t) - 1)) / sizeof(uint32_t);
    uint32_t send_buf[MAX_TX_SIZE / sizeof(uint32_t)];

    if (data_size == 0) {
        return DCSU_ERROR_NONE;
    }

    assert(data_size <= sizeof(send_buf));

    memcpy(send_buf, data, data_size);

    for (uint32_t idx = 0; idx < send_num_words; idx++) {
        p_dcsu->diag_tx_data[idx] = send_buf[idx];
    }

    return tx_command_send(dev, DCSU_TX_COMMAND_EXPORT_DATA, send_num_words);
}

enum dcsu_error_t dcsu_send_data(struct dcsu_dev_t *dev, const uint8_t *data, size_t data_size)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    size_t current_send_size;
    const size_t max_send_size = MAX_TX_SIZE;
    size_t sent_data_size;
    enum dcsu_error_t err;

    p_dcsu->diag_tx_large_param = data_size;

    for (sent_data_size = 0; sent_data_size < data_size;) {
        current_send_size = (sent_data_size + max_send_size < data_size) ?
                                max_send_size :
                                (data_size - sent_data_size);
        err = tx_export_send(dev, data + sent_data_size, current_send_size);
        if (err != DCSU_ERROR_NONE) {
            return err;
        }

        sent_data_size += current_send_size;
    }

    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_write_sw_status(struct dcsu_dev_t *dev, uint32_t status,
                                       uint32_t status_reg_idx)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    if (status_reg_idx >= sizeof(p_dcsu->sw_defined) / sizeof(uint32_t)) {
        FATAL_ERR(DCSU_ERROR_SW_STATUS_INVALID_IDX);
        return DCSU_ERROR_SW_STATUS_INVALID_IDX;
    }

    p_dcsu->sw_defined[status_reg_idx] = status;

    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_init(struct dcsu_dev_t *dev, uint8_t *rx_buf, size_t rx_buf_len,
                            dcsu_commit_write_handler_t handler)
{
#ifdef DCSU_CONFIG_WFI_ENABLE
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
#endif

    dev->rx_buf = rx_buf;
    dev->rx_buf_len = rx_buf_len;
    dev->handler = handler;

#ifdef DCSU_CONFIG_WFI_ENABLE
    p_dcsu->diag_cmd_irq_en = 0b11;
#endif

    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_finish(struct dcsu_dev_t *dev)
{
#ifdef DCSU_CONFIG_WFI_ENABLE
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
#endif

    dev->rx_buf = NULL;
    dev->rx_buf_len = 0;
    dev->rx_buf_offset = 0;
    dev->handler = NULL;

#ifdef DCSU_CONFIG_WFI_ENABLE
    p_dcsu->diag_cmd_irq_en = 0x0;
#endif

    return DCSU_ERROR_NONE;
}
