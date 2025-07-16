/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fih.h"
#include "tfm_hal_defs.h"
#include "tfm_hal_platform.h"
#ifdef FIH_ENABLE_DELAY
#include "tfm_fih_platform.h"
#endif

#ifdef FIH_ENABLE_DOUBLE_VARS

/* A volatile mask is used to prevent compiler optimization - the mask is xored
 * with the variable to create the backup and the integrity can be checked with
 * another xor. The mask value doesn't _really_ matter that much, as long as
 * it has reasonably high hamming weight.
 */
#define _FIH_MASK_VALUE 0xBEEF

/* Variable that could be (but isn't) changed at runtime to force the compiler
 * not to optimize the double check. Value doesn't matter.
 */
volatile int _fih_mask = _FIH_MASK_VALUE;
#endif /* FIH_ENABLE_DOUBLE_VARS */

#define _FIH_RET_MASK_VALUE 0xA5A5A5A5
volatile int _fih_ret_mask = _FIH_RET_MASK_VALUE;

fih_ret FIH_SUCCESS = FIH_POSITIVE_VALUE;
fih_ret FIH_FAILURE = FIH_NEGATIVE_VALUE;
fih_ret FIH_NO_BOOTABLE_IMAGE = FIH_CONST1;
fih_ret FIH_BOOT_HOOK_REGULAR = FIH_CONST2;

#ifdef FIH_ENABLE_CFI

#ifdef FIH_ENABLE_DOUBLE_VARS
fih_int _fih_cfi_ctr = {0, 0 ^ _FIH_MASK_VALUE};
#else
fih_int _fih_cfi_ctr = {0};
#endif /* FIH_ENABLE_DOUBLE_VARS */

/* Increment the CFI counter by one, and return the value before the increment.
 */
fih_int fih_cfi_get_and_increment(void)
{
    fih_int saved = _fih_cfi_ctr;
    _fih_cfi_ctr = fih_int_encode(fih_int_decode(saved) + 1);
    return saved;
}

/* Validate that the saved precall value is the same as the value of the global
 * counter. For this to be the case, a fih_ret must have been called between
 * these functions being executed. If the values aren't the same then panic.
 */
void fih_cfi_validate(fih_int saved)
{
    if (fih_int_decode(saved) != fih_int_decode(_fih_cfi_ctr)) {
        FIH_PANIC;
    }
}

/* Decrement the global CFI counter by one, so that it has the same value as
 * before the cfi_precall
 */
void fih_cfi_decrement(void)
{
    _fih_cfi_ctr = fih_int_encode(fih_int_decode(_fih_cfi_ctr) - 1);
}

#endif /* FIH_ENABLE_CFI */

#ifdef FIH_ENABLE_GLOBAL_FAIL
/* Global failure loop for bootloader code. Uses attribute used to prevent
 * compiler removing due to non-standard calling procedure. Multiple loop jumps
 * used to make unlooping difficult.
 */
__attribute__((used, noinline, noreturn))
void fih_panic_loop(void)
{
    FIH_LABEL("FAILURE_LOOP");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");
    __asm volatile ("b fih_panic_loop");

    /* An infinite loop to suppress compiler warnings
     * about the return of a noreturn function
     */
    while(1) {}
}
#endif /* FIH_ENABLE_GLOBAL_FAIL */