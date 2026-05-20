/*
 * Copyright (c) 2023-2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "coverity_check.h"
#include "ifx_core_interrupts.h"
#include "ifx_platform_startup.h"

#if DOMAIN_S && defined(TFM_FIH_PROFILE_ON)
#include "fih.h"
#endif /* DOMAIN_S && defined(TFM_FIH_PROFILE_ON) */

#if defined(IFX_SET_PC3) && DOMAIN_S
#include "cy_ms_ctl.h"
#include "ifx_spe_config.h"
#define IFX_CM33_PC3                 (3U)
#endif /* defined(IFX_SET_PC3) && DOMAIN_S */

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_8_5, "Double declaration due to project architecture")
TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_8_6, "Extern values are defined externally in linker file")
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_8_6)
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_8_5)

TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_21_2, "__cmsis_start is named this way by cmsis")
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_8_8, "Static storage modifier is not missing here")
extern __NO_RETURN void __PROGRAM_START(void);
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_21_2)

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);

#ifdef RAM_VECTORS_SUPPORT
    VECTOR_TABLE_Type __vector_table_rw[VECTORTABLE_SIZE] __IFX_RAM_VECTOR_TABLE_ATTRIBUTE;
#endif /* RAM_VECTORS_SUPPORT */

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_8_5, "PendSV_Handler, SVC_Handler, SysTick_Handler are defined in CMSIS libraries")
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_8_6, "DebugMon_Handler and NMI_Handler are defined in CMSIS libraries")
DEFAULT_IRQ_HANDLER(NMI_Handler)
DEFAULT_IRQ_HANDLER(HardFault_Handler)
DEFAULT_IRQ_HANDLER(MemManage_Handler)
DEFAULT_IRQ_HANDLER(BusFault_Handler)
DEFAULT_IRQ_HANDLER(UsageFault_Handler)
DEFAULT_IRQ_HANDLER(SecureFault_Handler)
DEFAULT_IRQ_HANDLER(SVC_Handler)
DEFAULT_IRQ_HANDLER(DebugMon_Handler)
DEFAULT_IRQ_HANDLER(PendSV_Handler)
DEFAULT_IRQ_HANDLER(SysTick_Handler)
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_8_5)

/* Interrupts */
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_8_6, "IRQn Handlers are defined in MCU libraries")
IFX_CORE_DEFINE_INTERRUPTS_LIST

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wpedantic"
#endif

TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_12_1, "VECTORTABLE_ALIGN and __VECTOR_TABLE_ATTRIBUTE are defined externally, cannot change them")
TFM_COVERITY_DEVIATE_BLOCK(MISRA_C_2023_Rule_11_1, "uint32_t * to VECTOR_TABLE_Type, this cast is acceptable as functions are local.")
TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_21_2, "__vector_table is used as is in startup")
const VECTOR_TABLE_Type __vector_table[VECTORTABLE_SIZE] IFX_VECTOR_TABLE_ATTRIBUTE = {
    /* Exceptions */
    (VECTOR_TABLE_Type)(&__INITIAL_SP),         /*       Initial Stack Pointer */
    Reset_Handler,                              /*   -15 Reset Handler */
#if IFX_SE_IPC_SERVICE_BASE && defined(IFX_SE_SYSCALL_HANDLER_ADDR)
    /* On some platforms base SERT services are handled by custom NMI handler
     * located at IFX_SE_SYSCALL_HANDLER_ADDR, thus default NMI handler in
     * vector table is replaced with SERT handler */
    (VECTOR_TABLE_Type)IFX_SE_SYSCALL_HANDLER_ADDR, /* SE RT syscall handler */
#else /* IFX_SE_IPC_SERVICE_BASE && defined(IFX_SE_SYSCALL_HANDLER_ADDR) */
    NMI_Handler,                                /*   -14 NMI Handler */
#endif /* IFX_SE_IPC_SERVICE_BASE && defined(IFX_SE_SYSCALL_HANDLER_ADDR) */
    HardFault_Handler,                          /*   -13 Hard Fault Handler */
    MemManage_Handler,                          /*   -12 MPU Fault Handler */
    BusFault_Handler,                           /*   -11 Bus Fault Handler */
    UsageFault_Handler,                         /*   -10 Usage Fault Handler */
    SecureFault_Handler,                        /*    -9 Secure Fault Handler */
    0,                                          /*    -8 Reserved */
    0,                                          /*    -7 Reserved */
    0,                                          /*    -6 Reserved */
    SVC_Handler,                                /*    -5 SVCall Handler */
    DebugMon_Handler,                           /*    -4 Debug Monitor Handler */
    0,                                          /*    -3 Reserved */
    PendSV_Handler,                             /*    -2 PendSV Handler */
    SysTick_Handler,                            /*    -1 SysTick Handler */
    /* Interrupts */
    IFX_CORE_INTERRUPTS_LIST
};
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_11_1)
TFM_COVERITY_BLOCK_END(MISRA_C_2023_Rule_12_1)

#if defined(__GNUC__)
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

#if defined(IFX_SET_PC3) && DOMAIN_S
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_VX(IFX_MSC_TFM_CORE_BUS_MASTER_ID), MS_PC_PC_PC, IFX_CM33_PC3);
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_VX(IFX_MSC_TFM_CORE_BUS_MASTER_ID), MS_PC_PC_PC_SAVED , IFX_CM33_PC3);
#endif /* defined(IFX_SET_PC3) && DOMAIN_S */

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif

#if defined(CONFIG_TFM_ENABLE_CP10CP11)
    /* Compiler may use FPU related assembler commands before FPU is enabled
     * in tfm_arch_config_extensions which will cause a Fault.
     * To avoid this, FPU is additionally enabled for SPE at startup.
     */
    SCB->CPACR |= (3UL << (10U * 2U))     /* enable CP10 full access for SPE */
               |  (3UL << (11U * 2U));    /* enable CP11 full access for SPE */
#endif

    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if DOMAIN_S && defined(TFM_FIH_PROFILE_ON)
    if ((__get_MSPLIM() != (uint32_t)(&__STACK_LIMIT)) ||
        (__get_PSPLIM() != (uint32_t)(&__STACK_LIMIT))) {
        FIH_PANIC;
    }
#endif /* DOMAIN_S && defined(TFM_FIH_PROFILE_ON) */

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
    for (size_t count = 0; count < VECTORTABLE_SIZE; count++) {
        __vector_table_rw[count] = __vector_table[count];
    }
    SCB->VTOR = (uint32_t)__vector_table_rw;
#else
    SCB->VTOR = (uint32_t)__vector_table;
#endif

    /* SystemInit accesses protected resources (e.g. clocks, power, etc.), thus:
     * - In SPE it is always called as SPE has access to those resources.
     * - In NSPE, it must be called only when IFX_MTB_SRF is enabled, because
     *   NSPE can access protected resources only if IFX_MTB_SRF is enabled
     */
#if DOMAIN_S || defined(IFX_MTB_SRF)
    SystemInit();                             /* CMSIS System Initialization */
#endif /* DOMAIN_S || defined(IFX_MTB_SRF) */

    __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
__NO_RETURN void Default_Handler(void)
{
    while (true) {
        ;
    }
}
