/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_FIH_H__
#define __TFM_FIH_H__

#include <stddef.h>
#include <stdint.h>
#include "fatal_error.h"

/* Fault injection mitigation library.
 *
 * Has support for different measures, which can either be enabled/disabled
 * separately or by defining one of the TFM_FIH_PROFILEs.
 *
 * NOTE: These constructs against fault injection attacks are not guaranteed to
 *       be secure for all compilers, but execution is going to be correct and
 *       including them will certainly help to harden the code.
 *
 * FIH_ENABLE_DOUBLE_VARS makes critical variables into a tuple (x, x ^ msk).
 * Then the correctness of x can be checked by XORing the two tuple values
 * together. This also means that comparisons between fih_ints can be verified
 * by doing x == y && x_msk == y_msk.
 *
 * FIH_ENABLE_GLOBAL_FAIL makes all while(1) failure loops redirect to a global
 * failure loop. This loop has mitigations against loop escapes / unlooping.
 * This also means that any unlooping won't immediately continue executing the
 * function that was executing before the failure.
 *
 * FIH_ENABLE_CFI (Control Flow Integrity) creates a global counter that is
 * incremented before every FIH_CALL of vulnerable functions. On the function
 * return the counter is decremented, and after the return it is verified that
 * the counter has the same value as before this process. This can be used to
 * verify that the function has actually been called. This protection is
 * intended to discover that important functions are called in an expected
 * sequence and neither of them is missed due to an instruction skip which could
 * be a result of glitching attack. It does not provide protection against ROP
 * or JOP attacks.
 *
 * FIH_ENABLE_DELAY causes random delays. This makes it hard to cause faults
 * precisely. It requires an RNG. A simple example using SysTick as entropy
 * source is provided in tfm_fih_platform.c, but any RNG that has an entropy
 * source can be used by implementing the fih_delay_random function.
 *
 * The basic call pattern is:
 *
 * FIH_DECLARE(fih_rc, FIH_FAILURE);
 * FIH_CALL(vulnerable_function, fih_rc, arg1, arg2);
 * if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
 *     FIH_PANIC;
 * }
 *
 * Note that any function called by FIH_CALL must only return using FIH_RET,
 * as otherwise the CFI counter will not be decremented and the CFI check will
 * fail causing a panic.
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef TFM_FIH_PROFILE_ON

/* Undefine the options as they are set through profiles */
#undef FIH_ENABLE_GLOBAL_FAIL
#undef FIH_ENABLE_CFI
#undef FIH_ENABLE_DOUBLE_VARS
#undef FIH_ENABLE_DELAY

#if defined(TFM_FIH_PROFILE_HIGH)

#define FIH_ENABLE_DELAY         /* Requires an entropy source */
#define FIH_ENABLE_DOUBLE_VARS
#define FIH_ENABLE_GLOBAL_FAIL
#define FIH_ENABLE_CFI

#elif defined(TFM_FIH_PROFILE_MEDIUM)

#define FIH_ENABLE_DOUBLE_VARS
#define FIH_ENABLE_GLOBAL_FAIL
#define FIH_ENABLE_CFI

#elif defined(TFM_FIH_PROFILE_LOW)

#define FIH_ENABLE_GLOBAL_FAIL
#define FIH_ENABLE_CFI

#else

#include TFM_FIH_PROFILE_CUSTOM_FILE

#endif /* TFM_FIH_PROFILE */
#define FIH_POSITIVE_VALUE 0x1AAA555A
#define FIH_NEGATIVE_VALUE 0x15555555
#define FIH_CONST1 0x1FCDEA88
#define FIH_CONST2 0x19C1F6E1

/* Label for interacting with FIH testing tool. Can be parsed from the elf file
 * after compilation. Does not require debug symbols.
 */
#if defined(__ICCARM__)
#define FIH_LABEL(str, lin, cnt) __asm volatile ("FIH_LABEL_" str "_" #lin "_" #cnt "::" ::);
#elif defined(__APPLE__)
#define FIH_LABEL(str) do {} while (0)
#else
#define FIH_LABEL(str) __asm volatile ("FIH_LABEL_" str "_%=:" ::);
#endif

#define FIH_LABEL_CRITICAL_POINT() FIH_LABEL("FIH_CRITICAL_POINT")

/*
 * FIH return type macro changes the function return types to fih_ret.
 * All functions that need to be protected by FIH and called via FIH_CALL must
 * return a fih_ret type.
 */
#define FIH_RET_TYPE(type)    fih_ret

#else

#define FIH_POSITIVE_VALUE 0
#define FIH_NEGATIVE_VALUE -1
#define FIH_CONST1 1
#define FIH_CONST2 1
#define FIH_LABEL_CRITICAL_POINT()
#define FIH_LABEL(str) do {} while (0)
#define FIH_RET_TYPE(type)    type

#endif /* TFM_FIH_PROFILE_ON */

#ifdef FIH_ENABLE_DOUBLE_VARS

/* All ints are replaced with two int - the normal one and a backup which is
 * XORed with the mask.
 */
extern volatile int _fih_mask;
typedef struct {
    volatile int val;
    volatile int msk;
} fih_int;
typedef volatile int fih_ret;

#else

typedef int fih_int;
typedef int fih_ret;

#endif /* FIH_ENABLE_DOUBLE_VARS */

extern fih_ret FIH_SUCCESS;
extern fih_ret FIH_FAILURE;
extern fih_ret FIH_NO_BOOTABLE_IMAGE;
extern fih_ret FIH_BOOT_HOOK_REGULAR;
extern volatile int _fih_ret_mask;

#ifdef FIH_ENABLE_GLOBAL_FAIL
/* Global failure handler - more resistant to unlooping. noinline and used are
 * used to prevent optimization
 */
__attribute__((noinline)) __attribute__((used))
void fih_panic_loop(void);
#define FIH_PANIC fih_panic_loop()
#else
#define FIH_PANIC while (1) {}
#endif  /* FIH_ENABLE_GLOBAL_FAIL */

/* NOTE: For functions to be inlined outside their compilation unit they have to
 * have the body in the header file. This is required as function calls are easy
 * to skip.
 */
#ifdef FIH_ENABLE_DELAY

/**
 * @brief Set up the RNG for use with random delays. Called once at startup.
 * @return 0 on success, negative error code on failure.
 */
int fih_delay_init(void);

#ifdef FIH_ENABLE_DELAY_PLATFORM

/**
 * @brief when @def FIH_ENABLE_DELAY_PLATFORM is set, the platform must provide
 *        its own implementation of the \a fih_delay function implementing a
 *        \a fih_delay_platform with the same prototype
 */
int fih_delay_platform(void);
__attribute__((always_inline)) inline
int fih_delay(void)
{
    return fih_delay_platform();
}

#else

/**
 * Get a random uint8_t value from an RNG seeded with an entropy source.
 *
 * NOTE
 * Do not directly call this function.
 */
uint8_t fih_delay_random(void);

/* Delaying logic, with randomness from a CSPRNG */
__attribute__((always_inline)) inline
int fih_delay(void)
{
    unsigned char delay;
    int foo = 0;
    volatile int rc;

    delay = fih_delay_random();

    for (volatile int i = 0; i < delay; i++) {
        foo++;
    }

    rc = 1;

    /* rc is volatile so if it is the return value then the function cannot be
     * optimized
     */
    return rc;
}
#endif /* FIH_ENABLE_DELAY_PLATFORM */

#else /* FIH_ENABLE_DELAY */

__attribute__((always_inline)) inline
int fih_delay_init(void)
{
    return 1;
}

__attribute__((always_inline)) inline
int fih_delay(void)
{
    return 1;
}
#endif /* FIH_ENABLE_DELAY */

#ifdef FIH_ENABLE_DOUBLE_VARS

__attribute__((always_inline)) inline
void fih_int_validate(fih_int x)
{
    if (x.val != (x.msk ^ _fih_mask)) {
        FIH_PANIC;
    }
}

/* Convert a fih_int to an int. Validate for tampering. */
__attribute__((always_inline)) inline
int fih_int_decode(fih_int x)
{
    fih_int_validate(x);
    return x.val;
}

/* Convert an int to a fih_int, can be used to encode specific error codes. */
__attribute__((always_inline)) inline
fih_int fih_int_encode(int x)
{
    fih_int ret = (fih_int){x, x ^ _fih_mask};
    return ret;
}

/* Standard equality. If A == B then 1, else 0 */
#define FIH_EQ(x, y) ((x == y) && fih_delay() && !(y != x))
#define FIH_NOT_EQ(x, y) ((x != y) || !fih_delay() || !(y == x))
#define FIH_SET(x, y) x = y; if(fih_delay() && (x != y)) FIH_PANIC

#else /* FIH_ENABLE_DOUBLE_VARS */

/* NOOP */
__attribute__((always_inline)) inline
void fih_int_validate(fih_int x)
{
    (void) x;
    return;
}

/* NOOP */
__attribute__((always_inline)) inline
int fih_int_decode(fih_int x)
{
    return x;
}

/* NOOP */
__attribute__((always_inline)) inline
fih_int fih_int_encode(int x)
{
    return x;
}

#define FIH_EQ(x, y) (x == y)
#define FIH_NOT_EQ(x, y) (x != y)
#define FIH_SET(x, y) x = y

#endif /* FIH_ENABLE_DOUBLE_VARS */

#define FIH_DECLARE(var, val) \
    fih_ret FIH_SET(var, val)

/* C has a common return pattern where 0 is a correct value and all others are
 * errors. This function converts 0 to FIH_SUCCESS and any other number to a
 * value that is not FIH_SUCCESS
 */
__attribute__((always_inline)) inline
fih_ret fih_ret_encode_zero_equality(int x)
{
    // cppcheck-suppress knownConditionTrueFalse
    if (x == 0 && fih_delay() && x == 0) {
        return FIH_SUCCESS;
    } else {
        return (fih_ret)(x ^ _fih_ret_mask);
    }
}

__attribute__((always_inline)) inline
int fih_ret_decode_zero_equality(fih_ret x)
{
    // cppcheck-suppress knownConditionTrueFalse
    if (x == FIH_SUCCESS && fih_delay() && x == FIH_SUCCESS) {
        return 0;
    } else {
        return (fih_ret)(x ^ _fih_ret_mask);
    }
}
__attribute__((always_inline)) inline
uint32_t fih_cond_panic() {
    FIH_PANIC;
    /* Should never get here but needs a return to call in a condition. */
    return 0;
}

/*
 * Guard a condition against tampering by trying 3 times and entering an error
 * state if there is any inconsistency.
 */
#define FIH_COND_CHECK(cond)                                  \
    (((cond) &&                                               \
      (((fih_delay() && (!(!(cond)))) || fih_cond_panic()) && \
       ((fih_delay() && (cond)) || fih_cond_panic()))         \
           ) ||                                               \
      (((fih_delay() && (!(!(cond)))) && fih_cond_panic()) || \
       ((fih_delay() && (cond)) && fih_cond_panic())))


#define FIH_COND_CHECK_SAFE_SKIP(cond) \
    ((cond) &&                         \
     fih_delay() &&                    \
     (!(!(cond))) &&                   \
     fih_delay() &&                    \
     (cond))

/*
 * Guard entering a condition against tampering
 * This assumes it is dangerous to skip the condition when false, but safe to
 * enter if true.
 */
#define FIH_COND_CHECK_SAFE_ENTER(cond) \
    !FIH_COND_CHECK_SAFE_SKIP(!(cond))

fih_int fih_cfi_get_and_increment(void);
void fih_cfi_validate(fih_int saved);
void fih_cfi_decrement(void);

/* Main FIH calling macro. return variable is second argument. Does some setup
 * before and validation afterwards. Inserts labels for use with testing script.
 *
 * First perform the precall step - this gets the current value of the CFI
 * counter and saves it to a local variable, and then increments the counter.
 *
 * Then set the return variable to FIH_FAILURE as a base case.
 *
 * Then perform the function call. As part of the funtion FIH_RET must be called
 * which will decrement the counter.
 *
 * The postcall step gets the value of the counter and compares it to the
 * previously saved value. If this is equal then the function call and all child
 * function calls were performed.
 */
#if defined(__ICCARM__)
#define FIH_CALL(f, ret, ...) FIH_CALL2(f, ret, __LINE__, __COUNTER__, __VA_ARGS__)

#define FIH_CALL2(f, ret, l, c, ...) \
    do { \
        FIH_LABEL("FIH_CALL_START", l, c);        \
        FIH_CFI_PRECALL_BLOCK; \
        ret = FIH_FAILURE; \
        if (fih_delay()) { \
            ret = f(__VA_ARGS__); \
        } \
        FIH_CFI_POSTCALL_BLOCK; \
        FIH_LABEL("FIH_CALL_END", l, c);          \
    } while (0)

#else

#define FIH_CALL(f, ret, ...) \
    do { \
        FIH_LABEL("FIH_CALL_START"); \
        FIH_CFI_PRECALL_BLOCK; \
        ret = FIH_FAILURE; \
        if (fih_delay()) { \
            ret = f(__VA_ARGS__); \
        } \
        FIH_CFI_POSTCALL_BLOCK; \
        FIH_LABEL("FIH_CALL_END"); \
    } while (0)
#endif

/* FIH return changes the state of the internal state machine. If you do a
 * FIH_CALL then you need to do a FIH_RET else the state machine will detect
 * tampering and panic.
 */
#define FIH_RET(ret) \
    do { \
        FIH_CFI_PRERET; \
        return ret; \
    } while (0)


#ifdef FIH_ENABLE_CFI
/* Macro wrappers for functions - Even when the functions have zero body this
 * saves a few bytes on noop functions as it doesn't generate the call/ret
 *
 * CFI precall function saves the CFI counter and then increments it - the
 * postcall then checks if the counter is equal to the saved value. In order for
 * this to be the case a FIH_RET must have been performed inside the called
 * function in order to decrement the counter, so the function must have been
 * called.
 */
#define FIH_CFI_PRECALL_BLOCK \
    fih_int _fih_cfi_saved_value = fih_cfi_get_and_increment()

#define FIH_CFI_POSTCALL_BLOCK \
        fih_cfi_validate(_fih_cfi_saved_value)

#define FIH_CFI_PRERET \
        fih_cfi_decrement()
#else
#define FIH_CFI_PRECALL_BLOCK
#define FIH_CFI_POSTCALL_BLOCK
#define FIH_CFI_PRERET
#endif  /* FIH_ENABLE_CFI */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TFM_FIH_H__ */
