/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_device_cfg.h
 * \brief This file contains defines of which devices are present in the
 *        platform based on the configurations.
 */

#ifndef __HOST_DEVICE_CFG_H__
#define __HOST_DEVICE_CFG_H__

#ifdef RSE_USE_HOST_UART
/* ARM UART PL011 */
#define DEFAULT_UART_CONTROL 0
#define DEFAULT_UART_BAUDRATE 38400
#endif /* RSE_USE_HOST_UART */

#endif /* __HOST_DEVICE_CFG_H__ */
