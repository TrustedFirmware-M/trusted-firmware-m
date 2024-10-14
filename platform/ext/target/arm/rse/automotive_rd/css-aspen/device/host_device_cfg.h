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

/* MHU */
#define MHU0_S
#define MHU2_S

#define MHU_RSE_TO_AP_MONITOR_DEV MHU0_SENDER_DEV_S
#define MHU_AP_MONITOR_TO_RSE_DEV MHU0_RECEIVER_DEV_S
#define MHU_RSE_TO_AP_S_DEV       MHU2_SENDER_DEV_S
#define MHU_AP_S_TO_RSE_DEV       MHU2_RECEIVER_DEV_S

#endif /* __HOST_DEVICE_CFG_H__ */
