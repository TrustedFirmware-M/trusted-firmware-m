/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __SCMI_SYSTEM_POWER_H__
#define __SCMI_SYSTEM_POWER_H__

/**
 * @file scmi_system_power.h
 *
 * The definitions in this header follow the SCMI specification for the
 * System Power protocol. They provide the message identifiers, payload
 * layouts, and convenience helpers used by agents to request platform
 * power state transitions or subscribe to power state notifications.
 */

#include "scmi_common.h"
#include "scmi_protocol.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup scmi_system_power_protocol SCMI System Power Protocol
 * @{
 */

/**
 * SCMI system power state messages
 */
#define SCMI_SYS_POWER_STATE_FLAGS_GRACEFUL_POS 0
#define SCMI_SYS_POWER_STATE_FLAGS_GRACEFUL_MASK \
    (UINT32_C(0x1) << SCMI_SYS_POWER_STATE_FLAGS_GRACEFUL_POS)

/**
 * SCMI system power: power states
 */
#define SCMI_SYS_POWER_STATE_SHUTDOWN   UINT32_C(0)
#define SCMI_SYS_POWER_STATE_COLD_RESET UINT32_C(1)
#define SCMI_SYS_POWER_STATE_WARM_RESET UINT32_C(2)
#define SCMI_SYS_POWER_STATE_POWER_UP   UINT32_C(3)
#define SCMI_SYS_POWER_STATE_SUSPEND    UINT32_C(4)

/**
 * SCMI message IDs
 */
#define SCMI_MESSAGE_ID_SYS_POWER_STATE_SET      UINT8_C(0x3)
#define SCMI_MESSAGE_ID_SYS_POWER_STATE_NOTIFY   UINT8_C(0x5)
#define SCMI_MESSAGE_ID_SYS_POWER_STATE_NOTIFIER UINT8_C(0x0)

/**
 * \brief System power state set message payload.
 */
struct scmi_sys_power_state_set_t {
    uint32_t flags;         /*!< Request flags */
    uint32_t system_state;  /*!< Requested power state */
};

/**
 * \brief System power state set response payload.
 */
struct scmi_sys_power_state_set_response_t {
    int32_t status;         /*!< Response status */
};

/**
 * \brief System power state notification subscription message payload.
 */
struct scmi_sys_power_state_notify_t {
    uint32_t notify_enable; /*!< Enable scmi_sys_power_state_notifier_t notifications */
};

/**
 * \brief System power state notification subscription response payload.
 */
struct scmi_sys_power_state_notify_response_t {
    int32_t status;         /*!< Response status */
};

/**
 * \brief System power state notification message payload.
 */
struct scmi_sys_power_state_notifier_t {
    uint32_t agent_id;      /*!< ID of the agent that caused the power state transition */
    uint32_t flags;         /*!< Notification flags */
    uint32_t system_state;  /*!< System power state that the system has transitioned to */
};

/**
 * \brief System power state notification subscription message request.
 *
 * \param[in] msg The message to be built.
 *
 */
scmi_protocol_err_t scmi_message_sys_power_state_notify(struct scmi_message_t *msg);


/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* __SCMI_SYSTEM_POWER_H__ */
