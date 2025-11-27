/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PLATFORM_SVC_HANDLER_H
#define PLATFORM_SVC_HANDLER_H

#include "config_tfm.h"
#include "svc_num.h"

/* SVC request to write message to SPM UART. Is used to "share" UART with non-secure image. */
#define IFX_SVC_PLATFORM_UART_LOG           TFM_SVC_NUM_PLATFORM_THREAD(0x0U)

/* SVC request to Enable/Disable SysTick */
#define IFX_SVC_PLATFORM_ENABLE_SYSTICK     TFM_SVC_NUM_PLATFORM_THREAD(0x1U)

/* SVC request for system reset to reset the MCU */
#define IFX_SVC_PLATFORM_SYSTEM_RESET       TFM_SVC_NUM_PLATFORM_THREAD(0x2U)

/**
 * \brief Enable/disable SysTick for FLIH/SLIH tf-m-tests
 *
 * \param[in]   enable      0 - disable SysTick IRQ,
 *                          != 0 - enable IRQ
 *
 * \retval                  Platform error code, see \ref tfm_platform_err_t
 */
int32_t ifx_call_platform_enable_systick(uint32_t enable);

/**
 * \brief Write string to SPM UART log
 *
 * \param[in]   str         String to output
 * \param[in]   len         String size
 * \param[in]   core_id     Core prefix id, see \ref ifx_stdio_core_id_t
 *
 * \retval                  Platform error code, see \ref tfm_platform_err_t
 */
int32_t ifx_call_platform_uart_log(const char *str, uint32_t len, uint32_t core_id);

/**
 * \brief Resets the system.
 *
 * \details Requests a system reset to reset the MCU.
 */
void ifx_call_platform_system_reset(void);

#endif /* PLATFORM_SVC_HANDLER_H */
