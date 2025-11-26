/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "sfcp_runtime_hal.h"
#include "sfcp.h"
#include "sfcp_defs.h"
#include "sfcp_handler_buffer.h"
#include "sfcp_interrupt_handler.h"
#include "critical_section.h"
#include "config_tfm.h"

/* Allow message size up to the largest possible PSA message size */
#define SFCP_BUFFER_SIZE (SFCP_PACKET_SIZE_WITHOUT_PAYLOAD(true, true) + SFCP_PAYLOAD_MAX_SIZE)

struct sfcp_buffer_t {
    bool in_use;
    __ALIGNED(4) uint8_t buf[SFCP_BUFFER_SIZE];
    size_t msg_size;
};

static struct sfcp_buffer_t sfcp_buffer[SFCP_MAX_CONCURRENT_REQ];

/* This must be called in the interrupt context so there will be no
 concurrent access from the thread */
enum sfcp_error_t sfcp_allocate_handler_buffer(sfcp_buffer_handle_t *buffer_handle,
                                               size_t message_size)
{
    struct critical_section_t cs_assert = CRITICAL_SECTION_STATIC_INIT;
    bool found_free;

    if (message_size > SFCP_BUFFER_SIZE) {
        return SFCP_ERROR_ALLOCATE_BUFFER_TOO_LARGE;
    }

    /* Prevent potential concurrent access from higher priority interrupts */
    CRITICAL_SECTION_ENTER(cs_assert);
    for (uint8_t i = 0; i < SFCP_MAX_CONCURRENT_REQ; i++) {
        if (!sfcp_buffer[i].in_use) {
            *buffer_handle = i;
            sfcp_buffer[i].in_use = true;
            sfcp_buffer[i].msg_size = message_size;
            found_free = true;
            goto out;
        }
    }

    found_free = false;

out:
    CRITICAL_SECTION_LEAVE(cs_assert);

    if (!found_free) {
        return SFCP_ERROR_ALLOCATE_BUFFER_FAILED;
    }

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_get_handler_buffer(sfcp_buffer_handle_t buffer_handle, uint8_t **buf,
                                          size_t *msg_size)
{
    if ((buffer_handle >= SFCP_MAX_CONCURRENT_REQ) || !sfcp_buffer[buffer_handle].in_use) {
        return SFCP_ERROR_INVALID_BUFFER_HANDLE;
    }

    *buf = sfcp_buffer[buffer_handle].buf;
    *msg_size = sfcp_buffer[buffer_handle].msg_size;

    return SFCP_ERROR_SUCCESS;
}

enum sfcp_error_t sfcp_pop_handler_buffer(sfcp_buffer_handle_t buf_handle)
{
    if (buf_handle >= SFCP_MAX_CONCURRENT_REQ) {
        return SFCP_ERROR_INVALID_BUFFER_HANDLE;
    }

    sfcp_buffer[buf_handle].in_use = false;

    return SFCP_ERROR_SUCCESS;
}

enum tfm_plat_err_t tfm_multi_core_hal_receive(sfcp_link_id_t link_id, uint32_t source)
{
    return (enum tfm_plat_err_t)sfcp_interrupt_handler(link_id);
}

enum tfm_plat_err_t tfm_multi_core_hal_init(void)
{
    enum sfcp_error_t sfcp_err;

    sfcp_err = sfcp_init();
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)sfcp_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
