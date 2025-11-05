/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __SCMI_POWER_DOMAIN_H__
#define __SCMI_POWER_DOMAIN_H__

#include "scmi_common.h"
#include "scmi_protocol.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup scmi_power_domain_protocol SCMI Power Domain Protocol
 * @{
 */

/**
 * SCMI power domain message IDs
 */
#define SCMI_MESSAGE_ID_SYS_POWER_DOMAIN_PROTOCOL_VERSION      UINT8_C(0x0)
#define SCMI_MESSAGE_ID_PD_POWER_DOMAIN_ATTRIBUTES             UINT8_C(0x3)
#define SCMI_MESSAGE_ID_PD_POWER_STATE_SET                     UINT8_C(0x4)
#define SCMI_MESSAGE_ID_PD_POWER_STATE_GET                     UINT8_C(0x5)
#define SCMI_MESSAGE_ID_PD_POWER_STATE_NOTIFY                  UINT8_C(0x6)
#define SCMI_MESSAGE_ID_PD_POWER_STATE_CHANGE_REQUESTED_NOTIFY UINT8_C(0x7)

/**
 * SCMI power domain state messages
 */
#define SCMI_PD_DEVICE_STATE_ID_OFF  0U
#define SCMI_PD_DEVICE_STATE_ID_ON   0U
#define SCMI_PD_DEVICE_STATE_ID      0U
#define SCMI_PD_DEVICE_STATE_ID_MASK 0xFFFFFFFU
#define SCMI_PD_DEVICE_STATE_TYPE    (1U << 30)

#define SCMI_POWER_DOMAIN_NAME_LEN               (16)

/**
 * \brief power domain PROTOCOL_VERSION response payload
 */
struct scmi_pd_protocol_version_response_t {
    int32_t status;         /*!< Response status */
    uint32_t version;       /*!< Protocol version */
};

/*
 * POWER_DOMAIN_ATTRIBUTES
 */

/**
 * \brief power domain POWER_DOMAIN_ATTRIBUTES request parameters
 */
struct scmi_pd_power_domain_attributes_t {
    uint32_t domain_id;     /*!< Domain ID */
};

/**
 * \brief power domain POWER_DOMAIN_ATTRIBUTES response payload
 */
struct scmi_pd_power_domain_attributes_response_t {
    int32_t status;                             /*!< Response status */
    uint32_t attributes;                        /*!< Attributes */
    uint8_t name[SCMI_POWER_DOMAIN_NAME_LEN];   /*!< The power domain name */
};

/*
 * POWER_STATE_SET
 */

#define SCMI_PD_POWER_STATE_SET_ASYNC_FLAG_MASK  (1U << 0)
#define SCMI_PD_POWER_STATE_SET_FLAGS_MASK       (1U << 0)

/**
 * \brief power domain POWER_STATE_SET request parameters
 */
struct scmi_pd_power_state_set_t {
    uint32_t flags;         /*!< Response status */
    uint32_t domain_id;     /*!< Response status */
    uint32_t power_state;   /*!< Response status */
};

/**
 * \brief power domain POWER_STATE_SET response payload
 */
struct scmi_pd_power_state_set_response_t {
    int32_t status;     /*!< Response status */
};

/*
 * POWER_STATE_GET
 */

/**
 * \brief power domain POWER_STATE_GET request parameters
 */
struct scmi_pd_power_state_get_t {
    uint32_t domain_id;     /*!< Domain id */
};

/**
 * \brief power domain POWER_STATE_GET response payload
 */
struct scmi_pd_power_state_get_response_t {
    int32_t status;         /*!< Response status */
    uint32_t power_state;   /*!< Returned power state */
};

/**
 * \brief Create a SCMI power domain PROTOCOL_VERSION message.
 *
 * \param[out] msg  SCMI message.
 *
 * \return Returns one of the standard SCMI error codes.
 */
scmi_protocol_err_t scmi_message_power_domain_protocol_version(
    struct scmi_message_t *msg);

/**
 * \brief Create a SCMI power domain PROTOCOL_ATTRIBUTES message.
 *
 * \param[out] msg  SCMI message
 *
 * \return Returns SCMI_PROTOCOL_NOT_SUPPORTED.
 */
scmi_protocol_err_t scmi_message_power_domain_protocol_attributes(
    struct scmi_message_t *msg);

/**
 * \brief Create a SCMI power domain PROTOCOL_MESSAGE_ATTRIBUTES message.
 *
 * \param[in]  message_id   message_id of the message.
 *
 * \param[out] msg          SCMI message
 *
 * \return Returns SCMI_PROTOCOL_NOT_SUPPORTED.
 */
scmi_protocol_err_t scmi_message_power_domain_message_attributes(
    struct scmi_message_t *msg,
    uint32_t message_id);

/**
 * \brief Create a SCMI power domain POWER_DOMAIN_ATTRIBUTES message.
 *
 * \param[in,out]   domain_id Identifier for the power domain
 *
 * \param[out]      msg  SCMI message
 *
 * \return Returns one of the standard SCMI error codes.
 */
scmi_protocol_err_t scmi_message_power_domain_attributes(
    struct scmi_message_t *msg,
    uint32_t domain_id);

/**
 * \brief Create a SCMI power domain POWER_STATE_SET message.
 *
 * \param[in]   flags               0: Async flag.
 * \param[in]   domain_id           Identifier for the power domain.
 * \param[in]   power_domain_state  Platform-specific parameter identifying the
 *                                  power state of the domain.
 *
 * \param[out]  msg                 SCMI message
 *
 * \return Returns one of the standard SCMI error codes.
 */
scmi_protocol_err_t scmi_message_power_domain_state_set(
    struct scmi_message_t *msg,
    uint32_t flags,
    uint32_t domain_id,
    uint32_t power_domain_state);

/**
 * \brief Create a SCMI power domain POWER_STATE_GET message.
 *
 * \param[in,out] domain_id Identifier for the power domain
 *
 * \param[out] msg SCMI message
 *
 * \return Returns one of the standard SCMI error codes.
 */
scmi_protocol_err_t scmi_message_power_domain_state_get(
    struct scmi_message_t *msg,
    uint32_t domain_id);

/**
 * \brief Create a SCMI power domain POWER_STATE_NOTIFY message.
 *
 * \param[in]  domain_id        Identifier for the power domain.
 * \param[in]  notify_enable    Indicates whether the platform sends any
 *                              POWER_STATE_CHANGED messages to the calling
 *                              agent.
 * \param[out] msg              SCMI message
 *
 * \return Returns SCMI_PROTOCOL_NOT_SUPPORTED.
 */
scmi_protocol_err_t scmi_message_power_domain_state_notify(
    struct scmi_message_t *msg,
    uint32_t domain_id,
    uint32_t notify_enable);

/**
 * \brief Create a SCMI power domain POWER_STATE_CHANGE_REQUESTED_NOTIFY
 *        message.
 *
 * \param[in]  domain_id        Identifier for the power domain.
 * \param[in]  notify_enable    Indicates whether the platform sends any
 *                              POWER_STATE_CHANGE_REQUESTED messages to the
 *                              calling agent.
 * \param[out] msg              SCMI message
 *
 * \return Returns SCMI_PROTOCOL_NOT_SUPPORTED.
 */
scmi_protocol_err_t scmi_message_power_domain_state_change_requested_notify(
    struct scmi_message_t *msg,
    uint32_t domain_id,
    uint32_t notify_enable);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* __SCMI_POWER_DOMAIN_H__ */
