/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * \file This file is intended to provide public API for platform specific IOCTL requests
 * and services.
 */

#ifndef IFX_PLATFORM_API
#define IFX_PLATFORM_API

#include "tfm_platform_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Start of application specific platform IOCTL request id.
 */
#define IFX_PLATFORM_IOCTL_APP_MIN      ((tfm_platform_ioctl_req_t)0x40000000)
/**
 * \brief Start of application specific platform IOCTL request id.
 */
#define IFX_PLATFORM_IOCTL_APP_MAX      ((tfm_platform_ioctl_req_t)0x7FFFFFFF)

/**
 * \brief Write message via Platform service to SPM UART
 *
 * \ref IFX_PRINT_CORE_PREFIX optional configuration can be used to provide prefix
 * to the messages. It's useful if system has only one serial port and there is
 * output from multiple cores/images.
 *
 * \param[in]   msg         Message to write
 * \param[in]   msg_size    Number of bytes to write
 *
 * \retval                  Number of bytes written.
 */
uint32_t ifx_platform_log_msg(const char *msg, uint32_t msg_size);

#ifdef __cplusplus
}
#endif

#endif /* IFX_PLATFORM_API */
