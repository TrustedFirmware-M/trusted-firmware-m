/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PLAT_TEST_H
#define PLAT_TEST_H

#include "device_definition.h"
#include "tfm_hal_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(IFX_IRQ_TEST_TIMER_S) || defined(IFX_IRQ_TEST_TIMER_NS) || \
    defined(TEST_NS_FPU)
/**
 * \brief This function initialize timer device for test HAL
 *
 * \param[in] dev   Timer device configuration
 *
 * \return A status code as specified in \ref tfm_hal_status_t
 */
enum tfm_hal_status_t ifx_plat_test_timer_init(const ifx_timer_irq_test_dev_t* dev);

/**
 * \brief This function start timer device for test HAL
 *
 * \param[in] dev   Timer device configuration
 */
void ifx_plat_test_timer_start(const ifx_timer_irq_test_dev_t* dev);

/**
 * \brief This function clear pending timer's interrupt for test HAL
 *
 * \param[in] dev   Timer device configuration
 */
void ifx_plat_test_secure_timer_clear_intr(const ifx_timer_irq_test_dev_t* dev);

/**
 * \brief This function stop timer device for test HAL
 *
 * \param[in] dev   Timer device configuration
 */
void ifx_plat_test_secure_timer_stop(const ifx_timer_irq_test_dev_t* dev);
#endif

#ifdef __cplusplus
}
#endif

#endif /* PLAT_TEST_H */
