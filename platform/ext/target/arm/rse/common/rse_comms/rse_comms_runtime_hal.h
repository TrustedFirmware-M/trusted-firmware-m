/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_RUNTIME_HAL_H__
#define __RSE_COMMS_RUNTIME_HAL_H__

#include "rse_comms_link_defs.h"
#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

struct client_request_t;

/**
 * \brief Platform specific initialization of SPE multi-core.
 *
 * \retval TFM_PLAT_ERR_SUCCESS  Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
enum tfm_plat_err_t tfm_multi_core_hal_init(void);

/**
 * \brief Receive PSA client call request from NSPE.
 *        Implemented by platform specific inter-processor communication driver.
 *
 * \param[in] link_id           The link ID that the message was received on.
 * \param[in] source            The number of the IRQ source for this MHU.
 *
 * \retval TFM_PLAT_ERR_SUCCESS  Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
enum tfm_plat_err_t tfm_multi_core_hal_receive(rse_comms_link_id_t link_id, uint32_t source);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_RUNTIME_HAL_H__ */
