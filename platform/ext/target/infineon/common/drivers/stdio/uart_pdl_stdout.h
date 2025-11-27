/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef UART_PDL_STDOUT_H
#define UART_PDL_STDOUT_H

#include <stdio.h>
#include <stdint.h>

#ifdef  __cplusplus
extern "C"
{
#endif

/**
 * \brief Output log for SVC.
 *
 * \ref stdio_output_string_raw is intended to be used by Platform service.
 * \ref ifx_platform_log_msg is a client API to print message through Platform
 * service.
 * \ref core_id is a core id
 */
int32_t stdio_output_string_raw(const char *str, uint32_t len, ifx_stdio_core_id_t core_id);

#ifdef  __cplusplus
}
#endif

#endif /* UART_PDL_STDOUT_H */
