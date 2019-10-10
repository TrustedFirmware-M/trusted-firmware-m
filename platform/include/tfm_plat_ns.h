/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PLAT_NS_H__
#define __TFM_PLAT_NS_H__

#include "Driver_USART.h"

#ifdef __cplusplus
extern "C" {
#endif

/* For UART the CMSIS driver is used */
extern ARM_DRIVER_USART NS_DRIVER_STDIO;

#if defined(__ARMCC_VERSION)
/* Struct FILE is implemented in stdio.h. Used to redirect printf to
 * NS_DRIVER_STDIO
 */
FILE __stdout;
/* Redirects armclang printf to NS_DRIVER_STDIO */
int fputc(int ch, FILE *f) {
    /* Send byte to NS_DRIVER_STDIO */
    (void)NS_DRIVER_STDIO.Send((const unsigned char *)&ch, 1);
    /* Return character written */
    return ch;
}
#elif defined(__GNUC__)
/* redirects gcc printf to NS_DRIVER_STDIO */
int _write(int fd, char * str, int len)
{
    (void)NS_DRIVER_STDIO.Send(str, len);

    return len;
}
#elif defined(__ICCARM__)
int putchar(int ch)
{
    /* Send byte to NS_DRIVER_STDIO */
    (void)NS_DRIVER_STDIO.Send((const unsigned char *)&ch, 1);
    /* Return character written */
    return ch;
}
#endif

/**
 * \brief Platform peripherals and devices initialization.
 *        Can be overridden for platform specific initialization.
 *
 * \return  ARM_DRIVER_OK if the initialization succeeds
*/
__WEAK int32_t tfm_ns_platform_init(void)
{
    int32_t status;

    status = NS_DRIVER_STDIO.Initialize(NULL);
    if (status == ARM_DRIVER_OK) {
        status = NS_DRIVER_STDIO.Control(ARM_USART_MODE_ASYNCHRONOUS, 115200);
    }
    return status;
}

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PLAT_NS_H__ */
