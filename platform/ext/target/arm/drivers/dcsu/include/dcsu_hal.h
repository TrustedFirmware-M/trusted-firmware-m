/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __DCSU_HAL_H__
#define __DCSU_HAL_H__

#include "dcsu_drv.h"

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief This function generates and stores the SoC unique ID in OTP
 *
 *
 * \retval DCSU_RX_MSG_ERROR_SUCCESS                The operation has succeeded.
 * \retval DCSU_RX_MSG_ERROR_OTP_ALREADY_WRITTEN    The OTP already contains a
 *                                                  value.
 * \retval DCSU_RX_MSG_ERROR_OTP_WRITE_FAILED       The OTP write failed.
 */
enum dcsu_rx_msg_error_t dcsu_hal_generate_soc_unique_id(void);

/**
 * \brief This function writes a region of the SoC area of OTP
 *
 * \param[in] soc_area_offset   The offset into the SoC area to write
 * \param[in] data              The data to write
 * \param[in] data_size         The size of the data to write
 *
 * \retval DCSU_RX_MSG_ERROR_SUCCESS                The operation has succeeded.
 * \retval DCSU_RX_MSG_ERROR_OTP_ALREADY_WRITTEN    The OTP already contains a
 *                                                  value.
 * \retval DCSU_RX_MSG_ERROR_OTP_WRITE_FAILED       The OTP write failed.
 * \retval DCSU_RX_MSG_ERROR_SOC_UID_NOT_GENERATED  The SoC UID hasn't been
 *                                                  written yet.
 * \retval DCSU_RX_MSG_ERROR_OFFSET_TOO_LARGE       The SoC area offset would
 *                                                  write outside the SoC area.
 * \retval DCSU_RX_MSG_ERROR_OFFSET_INVALID         The SoC area offset would
 *                                                  write the first two words of
 *                                                  the SoC area (reseved for
 *                                                  zero count).
 *
 */
enum dcsu_rx_msg_error_t dcsu_hal_write_soc_area(uint32_t soc_area_offset, const uint32_t *data,
                                                 size_t data_size);

/**
 * \brief This function triggers the integrity value calculate-and-store
 *        operation for the SoC area.
 *
 * \retval DCSU_RX_MSG_ERROR_SUCCESS                The operation has succeeded.
 * \retval DCSU_RX_MSG_ERROR_OTP_ALREADY_WRITTEN    The OTP already contains a
 *                                                  value.
 * \retval DCSU_RX_MSG_ERROR_OTP_WRITE_FAILED       The OTP write failed.
 * \retval DCSU_RX_MSG_ERROR_SOC_UID_NOT_GENERATED  The SoC UID hasn't been
 *                                                  written yet.
 */
enum dcsu_rx_msg_error_t dcsu_hal_compute_integrity_check_soc_area(void);

#ifdef __cplusplus
}
#endif

#endif /* __DCSU_HAL_H__ */
