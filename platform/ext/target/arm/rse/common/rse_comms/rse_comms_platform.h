/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_GET_MHU_H__
#define __RSE_COMMS_GET_MHU_H__

#include <stddef.h>
#include "rse_comms_link_defs.h"
#include "rse_comms_trusted_subnet.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \enum rse_comms_platform_device_type_t
 * \brief Enumeration of supported RSE communication platform device types.
 */
enum rse_comms_platform_device_type_t {
    /**
     * \brief Represents an MHUv2 device type.
     */
    RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV2,

    /**
     * \brief Represents an MHUv3 device type.
     */
    RSE_COMMS_PLATFORM_DEVICE_TYPE_MHUV3,
};

/**
 * \struct rse_comms_platform_device_t
 * \brief Represents a platform communication device with its type.
 *
 * This structure is used to abstract the underlying communication hardware.
 * Platform implementations must populate this structure with appropriate values.
 */
struct rse_comms_platform_device_t {
    /**
     * \brief Pointer to the underlying hardware device.
     */
    const void *device;

    /**
     * \brief Type of the device, as defined in rse_comms_platform_device_type_t.
     */
    enum rse_comms_platform_device_type_t type;
};

/**
 * \brief Retrieves the send device associated with a given communication link ID.
 *
 * This function must be implemented by each platform to return the appropriate
 * hardware device used for sending data on the specified link.
 *
 * \param link_id The link ID identifying the communication channel.
 * \return A platform device structure corresponding to the sending device for the specified link ID.
 */
struct rse_comms_platform_device_t rse_comms_platform_get_send_device(rse_comms_link_id_t link_id);

/**
 * \brief Retrieves the receive device associated with a given communication link ID.
 *
 * This function must be implemented by each platform to return the appropriate
 * hardware device used for receiving data on the specified link.
 *
 * \param link_id The link ID identifying the communication channel.
 * \return A platform device structure corresponding to the receiving device for the specified link ID.
 */
struct rse_comms_platform_device_t
rse_comms_platform_get_receive_device(rse_comms_link_id_t link_id);

/**
 * \brief Retrieves the link ID associated with a given receiving platform device.
 *
 * This function must be implemented by each platform to map a receive device
 * back to its corresponding communication link ID.
 *
 * \param device The receive device whose link ID is to be determined.
 * \return The link ID corresponding to the provided receive device.
 */
rse_comms_link_id_t
rse_comms_platform_get_receive_link_id(struct rse_comms_platform_device_t device);

void rse_comms_platform_get_trusted_subnets(
    struct rse_comms_trusted_subnet_config_t **trusted_subnets, size_t *num_trusted_subnets);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_GET_MHU_H__ */
