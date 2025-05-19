/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fih.h"

#ifdef FIH_ENABLE_DELAY
#include "kmu_drv.h"
#include "device_definition.h"
#endif /* FIH_ENABLE_DELAY */

#ifdef TFM_FIH_PROFILE_ON
fih_int FIH_SUCCESS = FIH_INT_INIT(FIH_POSITIVE_VALUE);
fih_int FIH_FAILURE = FIH_INT_INIT(FIH_NEGATIVE_VALUE);
#endif

#ifdef FIH_ENABLE_CFI
fih_int _fih_cfi_ctr = FIH_INT_INIT(0);

fih_int fih_cfi_get_and_increment(uint8_t cnt)
{
    fih_int saved_ctr = _fih_cfi_ctr;

    if (fih_int_decode(_fih_cfi_ctr) < 0) {
        FIH_PANIC;
    }

    /* Overflow */
    if (fih_int_decode(_fih_cfi_ctr) > (fih_int_decode(_fih_cfi_ctr) + cnt)) {
        FIH_PANIC;
    }

    _fih_cfi_ctr = fih_int_encode(fih_int_decode(_fih_cfi_ctr) + cnt);

    (void)fih_int_validate(_fih_cfi_ctr);
    (void)fih_int_validate(saved_ctr);

    return saved_ctr;
}

void fih_cfi_validate(fih_int saved)
{
    if (fih_not_eq(saved, _fih_cfi_ctr)) {
        FIH_PANIC;
    }
}

void fih_cfi_decrement(void)
{
    if (fih_int_decode(_fih_cfi_ctr) < 1) {
        FIH_PANIC;
    }

    _fih_cfi_ctr = fih_int_encode(fih_int_decode(_fih_cfi_ctr) - 1);

    (void)fih_int_validate(_fih_cfi_ctr);
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
    while(1) {
    };
}
#endif /* FIH_ENABLE_GLOBAL_FAIL */

#if defined(FIH_ENABLE_DELAY) && defined(FIH_ENABLE_DELAY_PLATFORM)
void fih_delay_init(void)
{
    /* Nothing to init, random delays through HW KMU */
    return;
}

int fih_delay_platform(void)
{
    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);
    /* No SW based delay */
    return 1;
}
#endif /* FIH_ENABLE_DELAY && FIH_ENABLE_DELAY_PLATFORM */
