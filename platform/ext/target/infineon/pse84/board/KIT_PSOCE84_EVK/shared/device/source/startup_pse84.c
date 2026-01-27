/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "startup_pse84.h"
#include "pse84_core_interrupts.h"
#include "coverity_check.h"
#if DOMAIN_S
#include "fih.h"
#endif

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_8_5, "Double declaration due to project architecture")
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_8_5)

TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_8_8, "External linkage follows CMSIS template")
extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);


#ifdef RAM_VECTORS_SUPPORT
    VECTOR_TABLE_Type __vector_table_rw[VECTORTABLE_SIZE] __IFX_RAM_VECTOR_TABLE_ATTRIBUTE;
#endif

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_8_5, "PendSV_Handler, SVC_Handler, SysTick_Handler are defined in CMSIS libraries")
IFX_CORE_DEFINE_EXCEPTIONS_LIST

/* Interrupts */
IFX_CORE_DEFINE_INTERRUPTS_LIST

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined( __GNUC__ )
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wpedantic"
#endif

const VECTOR_TABLE_Type __vector_table[VECTORTABLE_SIZE] IFX_VECTOR_TABLE_ATTRIBUTE = {
    /* Exceptions */
    IFX_CORE_EXCEPTIONS_LIST
    /* Interrupts */
    IFX_CORE_INTERRUPTS_LIST
};

#if defined( __GNUC__ )
    #pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
#if (IFX_CORE == IFX_CM55) && defined(IFX_HALT_CM55)
    __BKPT(0);
#endif /* (IFX_CORE == IFX_CM55) && defined(IFX_HALT_CM55) */

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif

#if defined(CONFIG_TFM_ENABLE_CP10CP11)
    /* Compiler may use FPU related assembler commands before FPU is enabled
     * in tfm_arch_config_extensions which will cause a Fault.
     * To avoid this, FPU is additionally enabled for SPE at startup.
     */
    SCB->CPACR |= (3UL << (10U*2U))     /* enable CP10 full access for SPE */
               |  (3UL << (11U*2U));    /* enable CP11 full access for SPE */
#endif

    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#ifdef TFM_FIH_PROFILE_ON
    if ((__get_MSPLIM() != (uint32_t)(&__STACK_LIMIT)) ||
        (__get_PSPLIM() != (uint32_t)(&__STACK_LIMIT))) {
        FIH_PANIC;
    }
#endif /* FIH_ENABLE_DOUBLE_VARS */

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_11_3, "Intentional pointer type conversion")
    TFM_COVERITY_DEVIATE_LINE(incompatible_cast, "__TZ_set_STACKSEAL_S does necessary type casts, thus suppressing the violation")
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
    TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_11_3);
#endif

#ifdef RAM_VECTORS_SUPPORT
    /* GCC copies vector table automatically, but Clang and IAR doesn`t.
     * Copying of vector table is done for all compilers, even tho it is
     * redundant for GCC. This is done to have common way of handling RAM vector
     * table. */
    for (size_t count = 0; count < VECTORTABLE_SIZE; count++)
    {
        __vector_table_rw[count] = __vector_table[count];
    }
    SCB->VTOR = (uint32_t)__vector_table_rw;
#else
    SCB->VTOR = (uint32_t)__vector_table;
#endif

    SystemInit();                             /* CMSIS System Initialization */

    __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
__NO_RETURN void Default_Handler(void)
{
    while(true) {
        ;
    }
}
