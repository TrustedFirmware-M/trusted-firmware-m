/*
 * Copyright (c) 2017 - 2020, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRFX_GLUE_H__
#define NRFX_GLUE_H__

/* Include the spm utilities for the assert symbol */
#include <assert.h>

#include <soc/nrfx_coredep.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrfx_glue nrfx_glue.h
 * @{
 * @ingroup nrfx
 *
 * @brief This file contains macros that should be implemented according to
 *        the needs of the host environment into which @em nrfx is integrated.
 */

//------------------------------------------------------------------------------

/**
 * @brief Macro for placing a runtime assertion.
 *
 * @param expression Expression to be evaluated.
 */
#if defined(NDEBUG)
#define NRFX_ASSERT(expression)  if (0 && (expression)) {}
#else
#define NRFX_ASSERT(expression)  assert(expression)
#endif

/**
 * @brief Macro for placing a compile time assertion.
 *
 * @param expression Expression to be evaluated.
 */
#define NRFX_STATIC_ASSERT(expression)  _Static_assert(expression, "")

//------------------------------------------------------------------------------

/**
 * @brief Macro for setting the priority of a specific IRQ.
 *
 * @param irq_number IRQ number.
 * @param priority   Priority to be set.
 */
#define NRFX_IRQ_PRIORITY_SET(irq_number, priority) \
    NVIC_SetPriority(irq_number, priority)

/**
 * @brief Macro for enabling a specific IRQ.
 *
 * @param irq_number IRQ number.
 */
#define NRFX_IRQ_ENABLE(irq_number)  NVIC_EnableIRQ(irq_number)

/**
 * @brief Macro for checking if a specific IRQ is enabled.
 *
 * @param irq_number IRQ number.
 *
 * @retval true  If the IRQ is enabled.
 * @retval false Otherwise.
 */
#define NRFX_IRQ_IS_ENABLED(irq_number)  NVIC_GetEnableIRQ(irq_number)

/**
 * @brief Macro for disabling a specific IRQ.
 *
 * @param irq_number IRQ number.
 */
#define NRFX_IRQ_DISABLE(irq_number)  NVIC_DisableIRQ(irq_number)

/**
 * @brief Macro for setting a specific IRQ as pending.
 *
 * @param irq_number IRQ number.
 */
#define NRFX_IRQ_PENDING_SET(irq_number)  NVIC_SetPendingIRQ(irq_number)

/**
 * @brief Macro for clearing the pending status of a specific IRQ.
 *
 * @param irq_number IRQ number.
 */
#define NRFX_IRQ_PENDING_CLEAR(irq_number)  NVIC_ClearPendingIRQ(irq_number)

/**
 * @brief Macro for checking the pending status of a specific IRQ.
 *
 * @retval true  If the IRQ is pending.
 * @retval false Otherwise.
 */
#define NRFX_IRQ_IS_PENDING(irq_number)  NVIC_GetPendingIRQ(irq_number)

/** @brief Macro for entering into a critical section. */
#define NRFX_CRITICAL_SECTION_ENTER()  nrfx_critical_section_enter()
void  nrfx_critical_section_enter(void);

/** @brief Macro for exiting from a critical section. */
#define NRFX_CRITICAL_SECTION_EXIT()  nrfx_critical_section_exit()
void nrfx_critical_section_exit(void);

//------------------------------------------------------------------------------

/**
 * @brief When set to a non-zero value, this macro specifies that
 *        @ref nrfx_coredep_delay_us uses a precise DWT-based solution.
 *        A compilation error is generated if the DWT unit is not present
 *        in the SoC used.
 */
#define NRFX_DELAY_DWT_BASED    0

/**
 * @brief Macro for delaying the code execution for at least the specified time.
 *
 * @param us_time Number of microseconds to wait.
 */
#define NRFX_DELAY_US(us_time)  nrfx_coredep_delay_us(us_time)

//------------------------------------------------------------------------------

/** @brief Atomic 32-bit unsigned type. */
#define nrfx_atomic_t  long

/**
 * @brief Macro for storing a value to an atomic object and returning its previous value.
 *
 * @param[in] p_data Atomic memory pointer.
 * @param[in] value  Value to store.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_STORE(p_data, value)  __atomic_exchange_n(p_data, value, __ATOMIC_SEQ_CST)

/**
 * @brief Macro for running a bitwise OR operation on an atomic object and returning its previous value.
 *
 * @param[in] p_data Atomic memory pointer.
 * @param[in] value  Value of the second operand in the OR operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_OR(p_data, value)  __atomic_fetch_or(p_data, value, __ATOMIC_SEQ_CST)

/**
 * @brief Macro for running a bitwise AND operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data Atomic memory pointer.
 * @param[in] value  Value of the second operand in the AND operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_AND(p_data, value)  __atomic_fetch_and(p_data, value, __ATOMIC_SEQ_CST)

/**
 * @brief Macro for running a bitwise XOR operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data Atomic memory pointer.
 * @param[in] value  Value of the second operand in the XOR operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_XOR(p_data, value)  __atomic_fetch_xor(p_data, value, __ATOMIC_SEQ_CST)

/**
 * @brief Macro for running an addition operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data Atomic memory pointer.
 * @param[in] value  Value of the second operand in the ADD operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_ADD(p_data, value)  __atomic_fetch_add(p_data, value, __ATOMIC_SEQ_CST)

/**
 * @brief Macro for running a subtraction operation on an atomic object
 *        and returning its previous value.
 *
 * @param[in] p_data Atomic memory pointer.
 * @param[in] value  Value of the second operand in the SUB operation.
 *
 * @return Previous value of the atomic object.
 */
#define NRFX_ATOMIC_FETCH_SUB(p_data, value)  __atomic_fetch_sub(p_data, value, __ATOMIC_SEQ_CST)

//------------------------------------------------------------------------------

/**
 * @brief When set to a non-zero value, this macro specifies that the
 *        @ref nrfx_error_codes and the @ref nrfx_err_t type itself are defined
 *        in a customized way and the default definitions from @c <nrfx_error.h>
 *        should not be used.
 */
#define NRFX_CUSTOM_ERROR_CODES 0

//------------------------------------------------------------------------------

/**
 * @brief When set to a non-zero value, this macro specifies that inside HALs
 *        the event registers are read back after clearing, on devices that
 *        otherwise could defer the actual register modification.
 */
#define NRFX_EVENT_READBACK_ENABLED 1

//------------------------------------------------------------------------------

/**
 * @brief Macro for writing back cache lines associated with the specified buffer.
 *
 * @param[in] p_buffer Pointer to the buffer.
 * @param[in] size     Size of the buffer.
 */
#define NRFY_CACHE_WB(p_buffer, size) \
    do {                              \
        (void)p_buffer;               \
        (void)size;                   \
    } while (0)

/**
 * @brief Macro for invalidating cache lines associated with the specified buffer.
 *
 * @param[in] p_buffer Pointer to the buffer.
 * @param[in] size     Size of the buffer.
 */
#define NRFY_CACHE_INV(p_buffer, size) \
    do {                               \
        (void)p_buffer;                \
        (void)size;                    \
    } while (0)

/**
 * @brief Macro for writing back and invalidating cache lines associated with
 *        the specified buffer.
 *
 * @param[in] p_buffer Pointer to the buffer.
 * @param[in] size     Size of the buffer.
 */
#define NRFY_CACHE_WBINV(p_buffer, size) \
    do {                                 \
        (void)p_buffer;                  \
        (void)size;                      \
    } while (0)

//------------------------------------------------------------------------------

/** @brief Bitmask that defines DPPI channels that are reserved for use outside of the nrfx library. */
#define NRFX_DPPI_CHANNELS_USED   0

/** @brief Bitmask that defines DPPI groups that are reserved for use outside of the nrfx library. */
#define NRFX_DPPI_GROUPS_USED     0

/** @brief Bitmask that defines PPI channels that are reserved for use outside of the nrfx library. */
#define NRFX_PPI_CHANNELS_USED    0

/** @brief Bitmask that defines PPI groups that are reserved for use outside of the nrfx library. */
#define NRFX_PPI_GROUPS_USED      0

/** @brief Bitmask that defines GPIOTE channels that are reserved for use outside of the nrfx library. */
#define NRFX_GPIOTE_CHANNELS_USED 0

/** @brief Bitmask that defines EGU instances that are reserved for use outside of the nrfx library. */
#define NRFX_EGUS_USED            0

/** @brief Bitmask that defines TIMER instances that are reserved for use outside of the nrfx library. */
#define NRFX_TIMERS_USED          0

/** @} */

#ifdef __cplusplus
}
#endif

#endif // NRFX_GLUE_H__
