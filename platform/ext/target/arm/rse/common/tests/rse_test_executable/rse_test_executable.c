/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>

#include "uart_stdout.h"
#include "region_defs.h"

#ifdef TEST_BL1_1
#include "bl1_1_suites.h"
#endif /* TEST_BL1_1 */

#ifdef TEST_BL1_2
#include "bl1_2_suites.h"
#endif /* TEST_BL1_2 */

#ifdef RSE_SUPPORT_ROM_LIB_RELOCATION
static void setup_got_register(void)
{
    __asm volatile(
        "mov r9, %0 \n"
        "mov r2, %1 \n"
        "lsl r9, #16 \n"
        "orr r9, r9, r2 \n"
        : : "I" (BL1_1_DATA_START >> 16), "I" (BL1_1_DATA_START & 0xFFFF) : "r2"
    );
}
#endif /* RSE_SUPPORT_ROM_LIB_RELOCATION */

int main(void)
{
#ifdef RSE_SUPPORT_ROM_LIB_RELOCATION
    setup_got_register();
#endif /* RSE_SUPPORT_ROM_LIB_RELOCATION */
    stdio_init();

#ifdef TEST_BL1_2
    run_bl1_2_testsuite();
#endif /* TEST_BL1_2 */
#ifdef TEST_BL1_1
    run_bl1_1_testsuite();
#endif /* TEST_BL1_1 */

    while(1){
        __asm volatile("wfi");
    }
}
