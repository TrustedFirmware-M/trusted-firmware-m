/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "dcsu_drv.h"

#include "dcsu_reg_defs.h"
#include "dcsu_hal.h"
#include "fatal_error.h"

#include "dcsu_config.h"

#include "tfm_log.h"

#include <string.h>
#include <assert.h>

#define MAX_RX_SIZE (sizeof(((struct _dcsu_reg_map_t *)0)->diag_rx_data))
#define MAX_TX_SIZE (sizeof(((struct _dcsu_reg_map_t *)0)->diag_tx_data))

#define DCSU_get_number_of_words(p_dcsu) (((p_dcsu)->diag_rx_command >> 8) & 0b11) + 1
#define DCSU_get_word_offset(p_dcsu) ((p_dcsu)->diag_rx_large_param)
#define DCSU_get_swd_data(p_dcsu) (((p_dcsu)->diag_rx_command >> 10) & 0x3FFF)

static enum dcsu_rx_command get_rx_command(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    return p_dcsu->diag_rx_command & 0xFF;
}

static enum dcsu_error_t tx_msg_err_to_dcsu_err(enum dcsu_tx_msg_response_t msg_err)
{
    return msg_err == DCSU_TX_MSG_RESP_SUCCESS ? DCSU_ERROR_NONE : DCSU_ERROR_TX_MSG_RESP_BASE + msg_err;
}

static enum dcsu_error_t rx_return_send(struct dcsu_dev_t *dev, enum dcsu_rx_msg_response_t msg_rsp)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    assert(msg_rsp != 0);
    assert(msg_rsp < _DCSU_RX_MSG_RESP_MAX);

    p_dcsu->diag_rx_command = (msg_rsp & 0xFF) << 24;
    return DCSU_ERROR_NONE;
}

void dcsu_wait_for_any_rx_command(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    while (!(p_dcsu->diag_cmd_irq_status & (0b1 << 0))) {
#ifdef DCSU_CONFIG_WFI_ENABLE
        __asm volatile("wfi");
#endif
    }
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

enum dcsu_error_t dcsu_poll_for_tx_response(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    if (p_dcsu->diag_cmd_irq_status & (0b1 << 1)) {
        return DCSU_ERROR_NONE;
    }
    return DCSU_ERROR_POLL_NO_COMMAND_PENDING;
}

static void dcsu_wait_for_tx_response(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    while (!(p_dcsu->diag_cmd_irq_status & (0b1 << 1))) {
#ifdef DCSU_CONFIG_WFI_ENABLE
        __asm volatile("wfi");
#endif
    }
}

static void dcsu_clear_pending_tx_interrupt(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    p_dcsu->diag_cmd_irq_clear = 0b1 << 1;
}

static enum dcsu_error_t rx_generate_soc_unique_id(struct dcsu_dev_t *dev,
                                                   enum dcsu_rx_msg_response_t *msg_resp)
{
    return dcsu_hal_generate_soc_unique_id(msg_resp);
}

static enum dcsu_error_t rx_compute_zc_soc_ids(struct dcsu_dev_t *dev,
                                               enum dcsu_rx_msg_response_t *msg_resp)
{
    enum dcsu_error_t msg_err;
    uint32_t zc_field_offset;
    uint32_t fields_offset;
    uint32_t field_family_id_size;
    uint32_t field_ieee_ecid_size;

    msg_err = dcsu_hal_get_field_offset(DCSU_OTP_FIELD_FAMILY_ID, &fields_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_size(DCSU_OTP_FIELD_FAMILY_ID, &field_family_id_size);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_size(DCSU_OTP_FIELD_IEEE_ECID, &field_ieee_ecid_size);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_offset(DCSU_OTP_FIELD_SOC_ID_ZC, &zc_field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_write_zero_count(DCSU_OTP_FIELD_SOC_ID_BASE, zc_field_offset, fields_offset,
                                        field_family_id_size + field_ieee_ecid_size, msg_resp);

    return msg_err;
}

static enum dcsu_error_t rx_read_field(struct dcsu_dev_t *dev, enum dcsu_otp_field_t otp_field,
                                       enum dcsu_rx_msg_response_t *msg_resp)
{
    enum dcsu_error_t msg_err;
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    uint32_t field_offset;
    uint32_t field_size;

    msg_err = dcsu_hal_get_field_offset(otp_field, &field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field to read so command invalid */
        *msg_resp = DCSU_RX_MSG_RESP_INVALID_COMMAND;
    }

    msg_err = dcsu_hal_get_field_size(otp_field, &field_size);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field to read so command invalid */
        *msg_resp = DCSU_RX_MSG_RESP_INVALID_COMMAND;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_read_otp(otp_field, field_offset, (uint32_t *)p_dcsu->diag_tx_data,
                                field_size, msg_resp);

    return msg_err;
}

static enum dcsu_error_t rx_compute_zc_soc_cfg(struct dcsu_dev_t *dev,
                                               enum dcsu_rx_msg_response_t *msg_resp)
{
    enum dcsu_error_t msg_err;
    uint32_t zc_field_offset;
    uint32_t field_offset;
    uint32_t field_size;

    msg_err = dcsu_hal_get_field_offset(DCSU_OTP_FIELD_SOC_CFG_DATA, &field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_size(DCSU_OTP_FIELD_SOC_CFG_DATA, &field_size);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_get_field_offset(DCSU_OTP_FIELD_SOC_CFG_DATA_ZC, &zc_field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }

    msg_err = dcsu_hal_write_zero_count(DCSU_OTP_FIELD_SOC_CFG_BASE, zc_field_offset, field_offset,
                                        field_size, msg_resp);

    return msg_err;
}

static enum dcsu_error_t rx_read_partial_field(struct dcsu_dev_t *dev,
                                               enum dcsu_otp_field_t otp_field,
                                               enum dcsu_rx_msg_response_t *msg_resp)
{
    enum dcsu_error_t msg_err;
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    uint32_t read_num_words = DCSU_get_number_of_words(p_dcsu);
    uint32_t field_offset;

    msg_err = dcsu_hal_get_field_offset(otp_field, &field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_INVALID_COMMAND;
        return DCSU_ERROR_NONE;
    }

    field_offset += DCSU_get_word_offset(p_dcsu);

    msg_err = dcsu_hal_read_otp(otp_field, field_offset, (uint32_t *)p_dcsu->diag_tx_data,
                                read_num_words * sizeof(uint32_t), msg_resp);

    return msg_err;
}

static enum dcsu_error_t rx_write_field(struct dcsu_dev_t *dev, enum dcsu_otp_field_t otp_field,
                                        bool offset_param, enum dcsu_rx_msg_response_t *msg_resp)
{
    enum dcsu_error_t msg_err;
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    uint32_t write_num_words = DCSU_get_number_of_words(p_dcsu);
    uint32_t field_offset;

    msg_err = dcsu_hal_get_field_offset(otp_field, &field_offset);
    if (msg_err != DCSU_ERROR_NONE) {
        /* Couldn't find field so write failed */
        *msg_resp = DCSU_RX_MSG_RESP_OTP_WRITE_FAILED;
        return DCSU_ERROR_NONE;
    }
    if (offset_param) {
        field_offset += DCSU_get_word_offset(p_dcsu);
    }

    msg_err = dcsu_hal_write_otp(otp_field, field_offset, (uint32_t *)p_dcsu->diag_rx_data,
                                 write_num_words * sizeof(uint32_t), msg_resp);

    return msg_err;
}

static enum dcsu_error_t rx_import_data(struct dcsu_dev_t *dev, bool use_checksum,
                                        enum dcsu_rx_msg_response_t *msg_resp)
{
    struct _dcsu_reg_map_t* p_dcsu = (struct _dcsu_reg_map_t*)dev->cfg->base;
    uint32_t write_num_words = DCSU_get_number_of_words(p_dcsu);
    uint32_t write_offset = DCSU_get_word_offset(p_dcsu);
    uint32_t write_size = write_num_words * sizeof(uint32_t);
    uint32_t *receive_buf;
    uint32_t buf_len = dev->rx_buf_len;
    uint32_t idx;
    uint32_t checksum;

    if (buf_len == 0) {
        *msg_resp = DCSU_RX_MSG_RESP_UNEXPECTED_IMPORT;
        return DCSU_ERROR_NONE;
    }
    if (write_offset >= buf_len) {
        *msg_resp = DCSU_RX_MSG_RESP_TOO_LARGE_OFFSET_PARAM;
        return DCSU_ERROR_NONE;
    }
    if (write_offset > buf_len - write_size) {
        *msg_resp = DCSU_RX_MSG_RESP_TOO_LARGE_ACCESS_REQUEST;
        return DCSU_ERROR_NONE;
    }

    if (use_checksum) {
        checksum = dcsu_hal_checksum_data((uint32_t *)p_dcsu->diag_rx_data, write_num_words);
        if (checksum != DCSU_get_swd_data(p_dcsu)) {
            dev->import_checksum_failed = true;
            *msg_resp = DCSU_RX_MSG_RESP_BAD_INTEGRITY_VALUE;
            return DCSU_ERROR_NONE;
        }
    }

    receive_buf = (uint32_t *)((dev->rx_buf + write_offset));

    for (idx = 0; idx < write_num_words; idx++) {
        receive_buf[idx] = p_dcsu->diag_rx_data[idx];
    }

    *msg_resp = DCSU_RX_MSG_RESP_SUCCESS;
    return DCSU_ERROR_NONE;
}

static enum dcsu_error_t rx_complete_import(struct dcsu_dev_t *dev,
                                            enum dcsu_rx_msg_response_t *msg_resp)
{
    if (dev->import_checksum_failed) {
        *msg_resp = DCSU_RX_MSG_RESP_BAD_INTEGRITY_VALUE;
        return DCSU_ERROR_NONE;
    }
    return dcsu_hal_complete_import_data(msg_resp);
}

static enum dcsu_error_t rx_cancel_import(struct dcsu_dev_t *dev,
                                          enum dcsu_rx_msg_response_t *msg_resp)
{
    dev->import_checksum_failed = false;
    return dcsu_hal_cancel_import_data(msg_resp);
}

enum dcsu_error_t dcsu_handle_rx_command(struct dcsu_dev_t *dev)
{
    enum dcsu_error_t err;
    enum dcsu_rx_msg_response_t msg_resp;
    enum dcsu_rx_command cmd;

    err = dcsu_poll_for_any_rx_command(dev);
    if (err != DCSU_ERROR_NONE) {
        return err;
    }

    cmd = get_rx_command(dev);

    INFO("DCSU command %x\r\n", cmd);

    switch(cmd) {
    case DCSU_RX_COMMAND_GENERATE_SOC_UNIQUE_ID:
        err = rx_generate_soc_unique_id(dev, &msg_resp);
        break;
    case DCSU_RX_COMMAND_WRITE_SOC_FAMILY_ID:
        err = rx_write_field(dev, DCSU_OTP_FIELD_FAMILY_ID, false, &msg_resp);
        break;
    case DCSU_RX_COMMAND_WRITE_SOC_IEEE_ECID:
        err = rx_write_field(dev, DCSU_OTP_FIELD_IEEE_ECID, false, &msg_resp);
        break;
    case DCSU_RX_COMMAND_COMPUTE_ZC_SOC_IDS:
        err = rx_compute_zc_soc_ids(dev, &msg_resp);
        break;
    case DCSU_RX_COMMAND_READ_SOC_FAMILY_ID:
        err = rx_read_field(dev, DCSU_OTP_FIELD_FAMILY_ID, &msg_resp);
        break;
    case DCSU_RX_COMMAND_READ_SOC_IEEE_ECID:
        err = rx_read_field(dev, DCSU_OTP_FIELD_IEEE_ECID, &msg_resp);
        break;
    case DCSU_RX_COMMAND_WRITE_SOC_CONFIG_DATA:
        err = rx_write_field(dev, DCSU_OTP_FIELD_SOC_CFG_DATA, true, &msg_resp);
        break;
    case DCSU_RX_COMMAND_COMPUTE_ZC_SOC_CFG:
        err = rx_compute_zc_soc_cfg(dev, &msg_resp);
        break;
    case DCSU_RX_COMMAND_READ_SOC_CONFIG_DATA:
        err = rx_read_partial_field(dev, DCSU_OTP_FIELD_SOC_CFG_DATA, &msg_resp);
    case DCSU_RX_COMMAND_IMPORT_DATA_NO_CHECKSUM:
        err = rx_import_data(dev, false, &msg_resp);
        break;
    case DCSU_RX_COMMAND_IMPORT_DATA_CHECKSUM:
        err = rx_import_data(dev, true, &msg_resp);
        break;
    case DCSU_RX_COMMAND_COMPLETE_IMPORT_DATA:
        err = rx_complete_import(dev, &msg_resp);
        break;
    case DCSU_RX_COMMAND_CANCEL_IMPORT_DATA_WITH_CHECKSUM:
        err = rx_cancel_import(dev, &msg_resp);
        break;
    case DCSU_RX_COMMAND_READ_COD_DATA:
        err = rx_read_partial_field(dev, DCSU_OTP_FIELD_CM_COD, &msg_resp);
        break;
    case DCSU_RX_COMMAND_READ_EC_PARAMS:
        err = rx_read_partial_field(dev, DCSU_OTP_FIELD_EC_PARAMS, &msg_resp);
        break;
    default:
        err = DCSU_ERROR_NONE;
        msg_resp = DCSU_RX_MSG_RESP_INVALID_COMMAND;
    }

    /* Send response unless 0. If zero assume that response will be handled externally */
    INFO("Resp: %x\r\n", msg_resp);
    if (msg_resp != 0) {
        /*
        * Clear interrupt here as after sending response tooling will be able to
        * send more commands.
        */
        dcsu_clear_pending_rx_interupt(dev);

        rx_return_send(dev, msg_resp);
    }

    return err;
}

enum dcsu_error_t dcsu_respond_to_rx_command(struct dcsu_dev_t *dev,
                                             enum dcsu_rx_command command,
                                             enum dcsu_rx_msg_response_t response)
{
    enum dcsu_error_t err;

    err = dcsu_poll_for_rx_command(dev, command);
    if (err != DCSU_ERROR_NONE) {
        return err;
    }

    return rx_return_send(dev, response);
}

enum dcsu_error_t dcsu_handle_tx_response(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    enum dcsu_tx_msg_response_t msg_resp;

    msg_resp = (p_dcsu->diag_tx_command >> 24) & 0xFF;

    dcsu_clear_pending_tx_interrupt(dev);

    p_dcsu->diag_tx_command = 0;

    INFO("Rec: %x\r\n", msg_resp);

    return tx_msg_err_to_dcsu_err(msg_resp);
}

static enum dcsu_error_t tx_command_send(struct dcsu_dev_t *dev, enum dcsu_tx_command tx_command,
                                         uint32_t data_word_size, uint32_t checksum, bool block)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    uint32_t tx_command_word = 0;

    INFO("Sending %x\r\n", tx_command);

    tx_command_word |= ((data_word_size - 1) & 0b11) << 8;
    tx_command_word |= tx_command & 0xFF;
    tx_command_word |= (checksum & 0x3FFF) << 10;

    p_dcsu->diag_tx_command = tx_command_word;

    if (block) {
        /* Now wait for the response */
        dcsu_wait_for_tx_response(dev);

        return dcsu_handle_tx_response(dev);
    } else {
        return DCSU_ERROR_NONE;
    }
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

    return tx_command_send(dev, DCSU_TX_COMMAND_EXPORT_DATA_NO_CHECKSUM, send_num_words, 0, true);
}

enum dcsu_error_t dcsu_send_data(struct dcsu_dev_t *dev, const uint8_t *data, size_t data_size)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;
    size_t current_send_size;
    const size_t max_send_size = MAX_TX_SIZE;
    size_t sent_data_size;
    enum dcsu_error_t err;

    for (sent_data_size = 0; sent_data_size < data_size;) {
        /* Data offset in receive buffer */
        p_dcsu->diag_tx_large_param = sent_data_size;

        current_send_size = (sent_data_size + max_send_size < data_size) ?
                                max_send_size :
                                (data_size - sent_data_size);
        err = tx_export_send(dev, data + sent_data_size, current_send_size);
        if (err != DCSU_ERROR_NONE) {
            return err;
        }

        sent_data_size += current_send_size;
    }

    return tx_command_send(dev, DCSU_TX_COMMAND_COMPLETE_EXPORT_DATA, 0, 0, true);
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

static enum dcsu_error_t __dcsu_import_ready(struct dcsu_dev_t *dev, bool block)
{
    return tx_command_send(dev, DCSU_TX_COMMAND_READY_FOR_IMPORT, 0, 0, block);
}

enum dcsu_error_t dcsu_import_ready(struct dcsu_dev_t *dev)
{
    return __dcsu_import_ready(dev, true);
}

enum dcsu_error_t dcsu_import_ready_non_blocking(struct dcsu_dev_t *dev)
{
    return __dcsu_import_ready(dev, false);
}

enum dcsu_error_t dcsu_report_status(struct dcsu_dev_t *dev, uint32_t *status, uint32_t size)
{
    struct _dcsu_reg_map_t* p_dcsu = (struct _dcsu_reg_map_t*)dev->cfg->base;
    uint32_t idx = 0;
    uint32_t checksum;
    uint32_t send_num_words = (size + (sizeof(uint32_t) - 1)) / sizeof(uint32_t);

    if (send_num_words > 4) {
        return DCSU_ERROR_TX_MSG_PAYLOAD_TOO_LARGE;
    }

    for (idx = 0; idx < send_num_words; idx++) {
        p_dcsu->diag_tx_data[idx] = status[idx];
    }

    checksum = dcsu_hal_checksum_data((uint32_t *)p_dcsu->diag_tx_data, send_num_words);

    return tx_command_send(dev, DCSU_TX_COMMAND_REPORT_STATUS, send_num_words, checksum, true);
}

enum dcsu_error_t dcsu_init(struct dcsu_dev_t *dev, uint8_t *rx_buf, size_t rx_buf_len,
                            dcsu_commit_write_handler_t handler)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    dev->rx_buf = rx_buf;
    dev->rx_buf_len = rx_buf_len;
    dev->handler = handler;
    dev->import_checksum_failed = false;

    p_dcsu->diag_cmd_irq_en = 0b11;

    return DCSU_ERROR_NONE;
}

enum dcsu_error_t dcsu_finish(struct dcsu_dev_t *dev)
{
    struct _dcsu_reg_map_t *p_dcsu = (struct _dcsu_reg_map_t *)dev->cfg->base;

    dev->rx_buf = NULL;
    dev->rx_buf_len = 0;
    dev->rx_buf_offset = 0;
    dev->handler = NULL;

    p_dcsu->diag_cmd_irq_en = 0x0;

    return DCSU_ERROR_NONE;
}
