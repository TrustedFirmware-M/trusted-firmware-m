/*
 * Copyright (c) 2017-2023 ARM Limited
 *
 * Licensed under the Apace License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apace.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Driver_USART.h"
#include "target_cfg.h"
#include "device_cfg.h"

/* Imports USART driver */
#if DOMAIN_NS == 1U
extern ARM_DRIVER_USART NS_DRIVER_STDIO;
#define STDIO_DRIVER    NS_DRIVER_STDIO
#else
extern ARM_DRIVER_USART TFM_DRIVER_STDIO;
#define STDIO_DRIVER    TFM_DRIVER_STDIO
#endif

static bool is_initialized = false;

int stdio_output_string(const char *str, uint32_t len)
{
    int32_t ret;

    if (!is_initialized) {
        return 0;
    }

    ret = STDIO_DRIVER.Send(str, len);
    if (ret != ARM_DRIVER_OK) {
        return 0;
    }

    /* Busy wait after Send(). CMSIS mandates the Send() to be non-blocking,
     * while TF-M's current implementation expects to block on Send(), i.e.
     * polling the tx_busy itself in driver code. For this reason the below
     * busy wait does not have any practical effect, but we keep it in place
     * for those platforms which might decide to implement IRQ-based UART
     */
    while (STDIO_DRIVER.GetStatus().tx_busy);

    return STDIO_DRIVER.GetTxCount();
}

void stdio_is_initialized_reset(void)
{
    is_initialized = false;
}

bool stdio_is_initialized(void)
{
    return is_initialized;
}

/* Redirects printf to STDIO_DRIVER in case of ARMCLANG*/
#if defined(__ARMCC_VERSION)
/* Struct FILE is implemented in stdio.h. Used to redirect printf to
 * STDIO_DRIVER
 */
FILE __stdout;
FILE __stderr;
/* __ARMCC_VERSION is only defined starting from Arm compiler version 6 */
int fputc(int ch, FILE *f)
{
    (void)f;

    /* Send byte to USART */
    (void)stdio_output_string((const char *)&ch, 1);

    /* Return character written */
    return ch;
}

/* Redirect sdtio for PicoLib in LLVM toolchain
   as per https://github.com/picolibc/picolibc/blob/main/doc/os.md
   'fputch()' named intentionally different from 'fputc()' from picolib */
#elif defined(__clang_major__)

int fputch(char ch, struct __file *f)
{
    (void)f;

    /* Send byte to USART */
    (void)stdio_output_string((const char *)&ch, 1);

    /* Return character written */
    return ch;
}

static FILE __stdio = FDEV_SETUP_STREAM(fputch, NULL, NULL, _FDEV_SETUP_WRITE);
FILE *const stdin = &__stdio;
__strong_reference(stdin, stdout);
__strong_reference(stdin, stderr);

#elif defined(__GNUC__)
/* Redirects printf to STDIO_DRIVER in case of GNUARM */
int _write(int fd, char *str, int len)
{
    (void)fd;

    /* Send string and return the number of characters written */
    return stdio_output_string(str, (uint32_t)len);
}
#elif defined(__ICCARM__)
int putchar(int ch)
{
    /* Send byte to USART */
    (void)stdio_output_string((const char *)&ch, 1);

    /* Return character written */
    return ch;
}
#endif

void stdio_init(void)
{
    int32_t ret = ARM_DRIVER_ERROR;

    ret = STDIO_DRIVER.Initialize(NULL);
    if (ret != ARM_DRIVER_OK) {
        assert(0);
        return;
    }

    ret = STDIO_DRIVER.PowerControl(ARM_POWER_FULL);
    if (ret != ARM_DRIVER_OK) {
        assert(0);
        return;
    }

    ret = STDIO_DRIVER.Control(DEFAULT_UART_CONTROL | ARM_USART_MODE_ASYNCHRONOUS, DEFAULT_UART_BAUDRATE);
    if (ret != ARM_DRIVER_OK) {
        assert(0);
        return;
    }

    ret = STDIO_DRIVER.Control(ARM_USART_CONTROL_TX, 1);
    if (ret != ARM_DRIVER_OK) {
        assert(0);
        return;
    }

    is_initialized = true;
}

void stdio_uninit(void)
{
    int32_t ret = ARM_DRIVER_ERROR;

    ret = STDIO_DRIVER.PowerControl(ARM_POWER_OFF);
    /* FixMe: Still allow this function not to be implemented as in blocking
     *        mode there is not much that needs to be done when powering off
     */
    if ((ret != ARM_DRIVER_OK) && (ret != ARM_DRIVER_ERROR_UNSUPPORTED)) {
        assert(0);
        return;
    }

    ret = STDIO_DRIVER.Uninitialize();
    if (ret != ARM_DRIVER_OK) {
        assert(0);
        return;
    }

    is_initialized = false;
}
