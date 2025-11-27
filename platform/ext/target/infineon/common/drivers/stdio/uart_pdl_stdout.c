/*
 * Copyright (c) 2023-2025 ARM Limited
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cy_device.h"
#include "cy_scb_uart.h"

#include "config_tfm.h"
#if DOMAIN_S
#include "cmsis.h"
#include "platform_svc_api.h"
#endif
#include "uart_stdout.h"
#include "uart_pdl_stdout.h"


#include <stdio.h>
#include <limits.h>

#if (IFX_CORE == IFX_CM33) && DOMAIN_S
#include "tfm_peripherals_def.h"

#define IFX_UART_PDL_SCB                IFX_TFM_SPM_UART
#define IFX_UART_PDL_SCB_CONFIG         IFX_TFM_SPM_UART_config
#ifdef IFX_TFM_SPM_UART_FLUSH
#define IFX_UART_PDL_SCB_FLUSH          IFX_TFM_SPM_UART_FLUSH
#endif

#elif (IFX_CORE == IFX_CM33) && DOMAIN_NS

#if !IFX_UART_USE_SPM_LOG_MSG
#include "cycfg_peripherals.h"
#define IFX_UART_PDL_SCB                IFX_TFM_CM33_NSPE_UART
#endif

#elif (IFX_CORE == IFX_CM55) && DOMAIN_NS

#if !IFX_UART_USE_SPM_LOG_MSG
#include "cycfg_peripherals.h"
#define IFX_UART_PDL_SCB                IFX_TFM_CM55_NSPE_UART
#endif
#endif /* (IFX_CORE == IFX_CM33) && DOMAIN_S */

#ifndef IFX_UART_USE_SPM_LOG_MSG
#define IFX_UART_USE_SPM_LOG_MSG        1
#endif

#if IFX_UART_USE_SPM_LOG_MSG
#include "ifx_platform_api.h"
#if DOMAIN_S
#include <string.h>
#include "protection_shared_data.h"
#endif /* DOMAIN_S */
#endif /* IFX_UART_USE_SPM_LOG_MSG */

static bool is_stdio_initialized = false;

#if DOMAIN_S

#if IFX_PRINT_CORE_PREFIX
#ifndef IFX_PRINT_CORE_PREFIX_LIMIT
/* How much bytes is printed without adding a core prefix */
#define IFX_PRINT_CORE_PREFIX_LIMIT         512
#endif /* IFX_PRINT_CORE_PREFIX_LIMIT */

/* Last core id used to optimize core prefix output */
static ifx_stdio_core_id_t ifx_stdio_core_id = (ifx_stdio_core_id_t)-1;
/* How much bytes stdio_output_string_raw processed for active core id */
static uint32_t ifx_stdio_core_out_len = 0;
#endif /* IFX_PRINT_CORE_PREFIX */

int32_t stdio_output_string_raw(const char *str, uint32_t len, ifx_stdio_core_id_t core_id)
{
#if IFX_UART_ENABLED
#if IFX_PRINT_CORE_PREFIX
    if ((ifx_stdio_core_id != core_id) || (ifx_stdio_core_out_len >= IFX_PRINT_CORE_PREFIX_LIMIT)) {
        /* Get core prefix for core_id */
        const char *core_prefix = IFX_STDIO_CORE_STR(core_id);
        size_t core_prefix_len = strlen(core_prefix);
        ifx_stdio_core_id = core_id;
        ifx_stdio_core_out_len = 0;

        /* Add prefix */
        Cy_SCB_UART_PutArrayBlocking(IFX_UART_PDL_SCB,
                                     (uint8_t *)core_prefix,
                                     core_prefix_len);
    }

    ifx_stdio_core_out_len += len;
#endif /* IFX_PRINT_CORE_PREFIX */

    Cy_SCB_UART_PutArrayBlocking(IFX_UART_PDL_SCB, (uint8_t *)str, len);

#if IFX_UART_PDL_SCB_FLUSH
    /* Wait while UART is transmitting */
    while (!Cy_SCB_UART_IsTxComplete(IFX_UART_PDL_SCB)) {}
#endif
#endif /* IFX_UART_ENABLED */

    return (len < (uint32_t)INT_MAX) ? (int32_t)len : INT_MAX;
}
#endif /* DOMAIN_S */

/**
 * \note Current implementation doesn't work if access to UART is done
 *      by multiple threads.
 *
 * \ref IFX_PRINT_CORE_PREFIX optional configuration can be used to provide prefix
 * to the messages. It's useful if system has only one serial port and there is
 * output from multiple cores/images.
 */
int stdio_output_string(const char *str, uint32_t len)
{
#if IFX_UART_USE_SPM_LOG_MSG
#if DOMAIN_S
    /* Check if running in exception handler */
    if (IFX_IS_SPM_INITILIZING() || (__get_IPSR() != 0U)) {
        /* In exception handler (SPM privileges) or SPM is not initialzed.
         * It's safe to access SCB directly */
        return stdio_output_string_raw(str, len, IFX_STDIO_CORE_S_ID);
    } else {
        /* ifx_call_platform_uart_log calls SPM to print message via SVC request.
         * Finally it will be handled by \ref stdio_output_string_raw.*/
        return ifx_call_platform_uart_log(str, len, IFX_STDIO_CORE_S_ID);
    }
#else
    /* ifx_platform_log_msg calls Platform service to print message, while
     * Platform service redirects this message to SPM through SVC request.
     * Finally it will be handled by \ref stdio_output_string_raw. */
    return (int32_t)ifx_platform_log_msg(str, len);
#endif
#else

#if IFX_UART_ENABLED
#if defined(IFX_STDIO_PREFIX)
    /* Validate that IFX_STDIO_PREFIX is a string not a pointer */
    const char check_prefix[] = IFX_STDIO_PREFIX; (void)check_prefix;
    /* Add prefix */
    Cy_SCB_UART_PutArrayBlocking(IFX_UART_PDL_SCB,
                                 IFX_STDIO_PREFIX,
                                 sizeof(IFX_STDIO_PREFIX) - 1U);
#endif
    /* Consider to use synchronization if there is need to share
     * UART between multiple partitions/threads/cores.
     * Cy_SCB_UART_PutArrayBlocking has problems if there is more than
     * one thread/core which access UART at the same time. */
     Cy_SCB_UART_PutArrayBlocking(IFX_UART_PDL_SCB, (void *)str, len);

#if IFX_UART_PDL_SCB_FLUSH
    /* Wait while UART is transmitting */
    while (!Cy_SCB_UART_IsTxComplete(IFX_UART_PDL_SCB)) {}
#endif
#endif /* IFX_UART_ENABLED */

    return (len < (uint32_t)INT_MAX) ? (int)len : INT_MAX;
#endif /* IFX_UART_USE_SPM_LOG_MSG */
}

/* __ARMCC_VERSION is only defined starting from Arm compiler version 6 */
#if defined(__ARMCC_VERSION)
/* Struct FILE is implemented in stdio.h. Used to redirect printf to
 * STDIO_DRIVER
 */
FILE __stdout;
/* Redirects printf to STDIO_DRIVER in case of ARMCLANG */
int fputc(int ch, FILE *f)
{
    (void)f;

    /* Send byte to USART */
    (void)stdio_output_string((const uint8_t *)&ch, 1);

    /* Return character written */
    return ch;
}
#elif defined(__GNUC__)
/* Redirects printf to STDIO_DRIVER in case of GNUARM */
int _write(int fd, char *str, int len)
{
    (void)fd;

    /* Send string and return the number of characters written */
    return (int)stdio_output_string(str, (uint32_t)len);
}
#elif defined(__ICCARM__)
int putchar(int ch)
{
    /* Send byte to USART */
    (void)stdio_output_string((const uint8_t *)&ch, 1);

    /* Return character written */
    return ch;
}
#endif

void stdio_init(void)
{
#if defined(IFX_UART_PDL_INITIALIZE_UART) && IFX_UART_ENABLED
    cy_en_scb_uart_status_t retval;

    retval = Cy_SCB_UART_Init(IFX_UART_PDL_SCB, &IFX_UART_PDL_SCB_CONFIG, NULL);

    Cy_SCB_UART_ClearRxFifo(IFX_UART_PDL_SCB);
    Cy_SCB_UART_ClearTxFifo(IFX_UART_PDL_SCB);

    if (CY_SCB_UART_SUCCESS == retval) {
        Cy_SCB_UART_Enable(IFX_UART_PDL_SCB);
    }
#endif

    is_stdio_initialized = true;
}

void stdio_is_initialized_reset(void)
{
    is_stdio_initialized = false;
}

bool stdio_is_initialized(void)
{
    return is_stdio_initialized;
}

void stdio_uninit(void)
{
#if defined(IFX_UART_PDL_INITIALIZE_UART) && IFX_UART_ENABLED
    Cy_SCB_UART_Disable(IFX_UART_PDL_SCB, NULL);

    Cy_SCB_UART_DeInit(IFX_UART_PDL_SCB);
#endif

    is_stdio_initialized = false;
}
