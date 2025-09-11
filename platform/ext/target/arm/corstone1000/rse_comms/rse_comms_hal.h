/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_COMMS_HAL_H__
#define __RSE_COMMS_HAL_H__

#include "rse_comms.h"
#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

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
 * \param[in] mhu_receiver_dev  Pointer to MHU receiver device on which to read
 *                              the message.
 * \param[in] mhu_sender_dev    Pointer to MHU sender device on which to write
 *                              the reply.
 * \param[in] source            The number of the IRQ source for this MHU.
 *
 * \retval TFM_PLAT_ERR_SUCCESS  Operation succeeded.
 * \retval Other return code     Operation failed with an error code.
 */
enum tfm_plat_err_t tfm_multi_core_hal_receive(void *mhu_receiver_dev,
                                               void *mhu_sender_dev,
                                               uint32_t source);

/**
 * \brief Notify NSPE that a PSA client call return result is replied.
 *        Implemented by platform specific inter-processor communication driver.
 *
 * \retval TFM_PLAT_ERR_SUCCESS  The notification is successfully sent out.
 * \retval Other return code     Operation failed with an error code.
 */
enum tfm_plat_err_t tfm_multi_core_hal_reply(struct client_request_t *req);

int32_t tfm_hal_client_id_translate(void *owner, int32_t client_id_in);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_COMMS_HAL_H__ */
