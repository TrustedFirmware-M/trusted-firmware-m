/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PSE84_DEVICE_CFG_H
#define PSE84_DEVICE_CFG_H

/**
 * \file device_cfg.h
 * \brief Configuration file native driver re-targeting
 *
 * \details This file can be used to add native driver specific macro
 *          definitions to select which peripherals are available in the build.
 *
 * This is a default device configuration file with all peripherals enabled.
 */

#if (IFX_CORE == IFX_CM33)
/* TCPWM Timers for IRQ tests */
/* IRQ of non-secure timer is used to test interaction between SPE and NSPE
 * on the same core so we need to use it only on CM33
 * and has no sense to use non-secure timer on CM55
 * Now this issue solved by building non-secure part of non-secure timer only
 * for CM33 at nspe\CMakeLists.txt */
#define IFX_IRQ_TEST_TIMER_S
#endif /* (IFX_CORE == IFX_CM33) */

#endif /* PSE84_DEVICE_CFG_H */
