/*
 * Copyright (c) 2025 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef NRFX_CONFIG_NRF7120_ENGA_APPLICATION_H__
#define NRFX_CONFIG_NRF7120_ENGA_APPLICATION_H__

#ifndef NRFX_CONFIG_H__
#error "This file should not be included directly. Include nrfx_config.h instead."
#endif

/**
 * @brief NRFX_DEFAULT_IRQ_PRIORITY
 *
 * Integer value. Minimum: 0 Maximum: 7
 */
#ifndef NRFX_DEFAULT_IRQ_PRIORITY
#define NRFX_DEFAULT_IRQ_PRIORITY 7
#endif

/**
 * @brief NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY
 *
 * Integer value. Minimum: 0 Maximum: 7
 */
#ifndef NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY
#define NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY NRFX_DEFAULT_IRQ_PRIORITY
#endif

/**
 * @brief NRFX_MRAMC_ENABLED
 *
 * Boolean. Accepted values: 0 and 1.
 */
#ifndef NRFX_MRAMC_ENABLED
#define NRFX_MRAMC_ENABLED 0
#endif

/**
 * @brief NRFX_MRAMC_DEFAULT_CONFIG_IRQ_PRIORITY
 *
 * Integer value. Minimum: 0. Maximum: 7.
 */
#ifndef NRFX_MRAMC_DEFAULT_CONFIG_IRQ_PRIORITY
#define NRFX_MRAMC_DEFAULT_CONFIG_IRQ_PRIORITY NRFX_DEFAULT_IRQ_PRIORITY
#endif

/**
 * @brief NRFX_MRAMC_CONFIG_LOG_ENABLED
 *
 * Boolean. Accepted values: 0 and 1.
 */
#ifndef NRFX_MRAMC_CONFIG_LOG_ENABLED
#define NRFX_MRAMC_CONFIG_LOG_ENABLED 0
#endif

/**
 * @brief NRFX_MRAMC_CONFIG_LOG_LEVEL
 *
 * Integer value.
 * Supported values:
 * - Off     = 0
 * - Error   = 1
 * - Warning = 2
 * - Info    = 3
 * - Debug   = 4
 */
#ifndef NRFX_MRAMC_CONFIG_LOG_LEVEL
#define NRFX_MRAMC_CONFIG_LOG_LEVEL 3
#endif

#endif // NRFX_CONFIG_NRF7120_ENGA_APPLICATION_H__
