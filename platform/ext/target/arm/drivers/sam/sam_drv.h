/*
 * Copyright (c) 2023-2024, Arm Limited. All rights reserved.
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

/**
 * \file sam_drv.h
 * \brief Driver for Arm Security Alarm Manager (SAM).
 */

#ifndef __SAM_DRV_H__
#define __SAM_DRV_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#if TFM_UNIQUE_ERROR_CODES == 1
#include "error_codes_mapping.h"
#else
#define SAM_ERROR_BASE 0x1u
#endif /* TFM_UNIQUE_ERROR_CODES */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief SAM Event IDs.
 */
enum sam_event_id_t {
    SAM_EVENT_CONFIG_INTEGRITY_ERROR = 0UL,
    SAM_EVENT_WATCHDOG_TIMER,
    SAM_EVENT_DUPLICATION_ERROR,
    SAM_EVENT_USECASE_SPECIFIC_START,

    SAM_EVENT_ID_MAX = 63,
};

/**
 * \brief SAM response action IDs.
 */
enum sam_response_t {
    SAM_RESPONSE_NONE = 0UL,
    SAM_RESPONSE_COLD_RESET = 1UL,
    SAM_RESPONSE_WARM_RESET = 1UL << 1,
    SAM_RESPONSE_NMI = 1UL << 2,
    SAM_RESPONSE_CRITICAL_FAULT_INTERRUPT = 1UL << 3,
    SAM_RESPONSE_FAULT_INTERRUPT = 1UL << 4,
    SAM_RESPONSE_ACTION_5 = 1UL << 5,
    SAM_RESPONSE_ACTION_6 = 1UL << 6,
    SAM_RESPONSE_ACTION_7 = 1UL << 7,

    SAM_RESPONSE_ACTION_MAX = SAM_RESPONSE_ACTION_7,
};

/**
 * \brief SAM error type.
 */
enum sam_error_t {
    SAM_ERROR_NONE = 0,
    SAM_ERROR_INVALID_ARGUMENT = SAM_ERROR_BASE,
    SAM_ERROR_GENERIC_ERROR,
};

/**
 * \brief SAM event handler function type.
 */
typedef void (*sam_event_handler_t)(enum sam_event_id_t);

/* SAM has a maximum of 8 event counters */
#define SAM_EVENT_COUNTER_AMOUNT_MAX 8

/* SAM has a maximum of 8 response actions */
#define SAM_RESPONSE_ACTION_AMOUNT_MAX 8

/**
 * \brief SAM device configuration structure.
 */
struct sam_dev_cfg_t {
    const uintptr_t base; /**< SAM base address */
};

/**
 * \brief SAM device structure.
 */
struct sam_dev_t {
    const struct sam_dev_cfg_t *const cfg; /**< SAM configuration */
    sam_event_handler_t event_handlers[SAM_EVENT_ID_MAX + 1]; /**< SAM event handlers */
};

/**
 * \brief Initialize SAM device.
 *
 * \param[in] dev  Pointer to SAM device struct.
 *
 * \return Error code of enum sam_error_t type.
 */
enum sam_error_t sam_init(const struct sam_dev_t *dev);

/**
 * \brief Enable a SAM event.
 *
 * \param[in] dev       Pointer to SAM device struct.
 * \param[in] event_id  Event ID to enable.
 *
 * \return Error code of enum sam_error_t type.
 */
enum sam_error_t sam_enable_event(const struct sam_dev_t *dev,
                                  enum sam_event_id_t event_id);

/**
 * \brief Disable a SAM event.
 *
 * \param[in] dev       Pointer to SAM device struct.
 * \param[in] event_id  Event ID to disable.
 *
 * \return Error code of enum sam_error_t type.
 */
enum sam_error_t sam_disable_event(const struct sam_dev_t *dev,
                                   enum sam_event_id_t event_id);

/**
 * \brief Set the response action for a SAM event.
 *
 * \param[in] dev              Pointer to SAM device struct.
 * \param[in] event_id         Event ID for which to set response.
 * \param[in] response         Response action to set.
 *
 * \return Error code of enum sam_error_t type.
 */
enum sam_error_t sam_set_event_response(const struct sam_dev_t *dev,
                                        enum sam_event_id_t event_id,
                                        enum sam_response_t response);

/**
 * \brief Set the SAM watchdog counter initial value.
 *
 * \param[in] dev          Pointer to SAM device struct.
 * \param[in] count_value  Number of cycles to count after a SAM event before
 *                         asserting the watchdog event:
 *                         0: watchdog count down disabled,
 *                         1 to (2^26)-1: valid initial count values.
 * \param[in] responses    Bitwise OR of response actions that trigger the
 *                         watchdog counter. SAM_RESPONSE_COLD_RESET and
 *                         SAM_RESPONSE_WARM_RESET are ignored.
 */
void sam_set_watchdog_counter_initial_value(const struct sam_dev_t *dev,
                                            uint32_t count_value,
                                            enum sam_response_t responses);

/**
 * \brief Register a handler function for a SAM event.
 *
 * \param[in] dev            Pointer to SAM device struct.
 * \param[in] event_id       Event ID to handle.
 * \param[in] event_handler  Pointer to event handler function.
 *
 * \return Error code of enum sam_error_t type.
 */
enum sam_error_t sam_register_event_handler(struct sam_dev_t *dev,
                                            enum sam_event_id_t event_id,
                                            sam_event_handler_t event_handler);

/**
 * \brief Check if a particular SAM event is pending.
 *
 * \param[in] dev  Pointer to SAM device struct.
 * \param[in] event_id  Event ID to check.
 *
 * \return True if the event is pending, False otherwise.
 */
bool sam_is_event_pending(const struct sam_dev_t *dev,
                          enum sam_event_id_t event_id);

/**
 * \brief Clear a particular pending SAM events without calling the event
 *        corresponding handler.
 *
 * \param[in] dev  Pointer to SAM device struct.
 * \param[in] event_id  Event ID to clear.
 *
 * \return Error code of enum sam_error_t type.
 */
enum sam_error_t sam_clear_event(const struct sam_dev_t *dev,
                                 enum sam_event_id_t event_id);

/**
 * \brief Clear all pending SAM events without calling the event corresponding
 *        handler.
 *
 * \param[in] dev  Pointer to SAM device struct.
 */
void sam_clear_all_events(const struct sam_dev_t *dev);

/**
 * \brief Handle a particular pending SAM events by calling the
 *        corresponding registered event handler functions and then clearing the
 *        event.
 *
 * \param[in] dev  Pointer to SAM device struct.
 * \param[in] event_id  Event ID to handle.
 *
 * \return Error code of enum sam_error_t type.
 */
enum sam_error_t sam_handle_event(const struct sam_dev_t *dev,
                                  enum sam_event_id_t event_id);

/**
 * \brief Handle all pending SAM events by calling the corresponding
 *        registered event handler functions and then clearing the events.
 *
 * \note This function is intended to be called from an interrupt handler.
 *
 * \param[in] dev  Pointer to SAM device struct.
 */
void sam_handle_all_events(const struct sam_dev_t *dev);

/**
 * \brief Get the address of the last partial write for a particular VM.
 *
 * \param[in] dev   Pointer to SAM device struct.
 * \param[in] vm_id ID of the VM to get the address for.
 *
 * \return The required address.
 */
uintptr_t sam_get_vm_partial_write_addr(const struct sam_dev_t *dev,
                                        uint32_t vm_id);

/**
 * \brief Get the address of the last single (corrected) ECC error for a
 *        particular VM.
 *
 * \param[in] dev   Pointer to SAM device struct.
 * \param[in] vm_id ID of the VM to get the address for.
 *
 * \return The required address.
 */
uintptr_t sam_get_vm_single_corrected_err_addr(const struct sam_dev_t *dev,
                                               uint32_t vm_id);

/**
 * \brief Get the address of the last double (uncorrected) ECC error for a
 *        particular VM.
 *
 * \param[in] dev   Pointer to SAM device struct.
 * \param[in] vm_id ID of the VM to get the address for.
 *
 * \return The required address.
 */
uintptr_t sam_get_vm_double_uncorrected_err_addr(const struct sam_dev_t *dev,
                                                 uint32_t vm_id);

/**
 * \brief Get the address of the last single (corrected) ECC error for the TRAM
 *
 * \param[in] dev   Pointer to SAM device struct.
 *
 * \return The required address.
 */
uintptr_t sam_get_tram_single_corrected_err_addr(const struct sam_dev_t *dev);

/**
 * \brief Get the address of the last double (uncorrected) ECC error for the
 *        TRAM.
 *
 * \param[in] dev   Pointer to SAM device struct.
 *
 * \return The required address.
 */
uintptr_t sam_get_tram_double_uncorrected_err_addr(const struct sam_dev_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* __SAM_DRV_H__ */
