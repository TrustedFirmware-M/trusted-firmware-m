/*
 * Copyright (c) 2022-2024, Arm Limited. All rights reserved.
 * Portions Copyright (C) 2024 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM33.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */
//FIXME: check if following includes are needed
#include "tfm_hal_device_header.h"
#if defined(TEST_NS_FPU) || defined(TEST_S_FPU)
#include "test_interrupt.h"
#endif

#include "system_max32657.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
#define DEFAULT_IRQ_HANDLER(handler_name)       \
    __NO_RETURN void __WEAK handler_name(void); \
    void handler_name(void)                     \
    {                                           \
        while (1)                               \
            ;                                   \
    }

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
DEFAULT_IRQ_HANDLER(Default_Handler)

/* Device-specific Interrupts                                                     */
    /*                                               CMSIS Interrupt Number           */
    /*                                               ||||          ||                 */
    /*                                               ||||  Offset  ||                 */
    /*                                               vvvv  vvvvvv  vv                 */

DEFAULT_IRQ_HANDLER(ICE_IRQHandler)                /* 0x10  0x0040  16: ICE Unlock */
DEFAULT_IRQ_HANDLER(WDT_IRQHandler)                /* 0x11  0x0044  17: Watchdog Timer */
DEFAULT_IRQ_HANDLER(RTC_IRQHandler)                /* 0x12  0x0048  18: RTC */
DEFAULT_IRQ_HANDLER(TRNG_IRQHandler)               /* 0x13  0x004C  19: True Random Number Generator */
DEFAULT_IRQ_HANDLER(TMR0_IRQHandler)               /* 0x14  0x0050  20: Timer 0 */
DEFAULT_IRQ_HANDLER(TMR1_IRQHandler)               /* 0x15  0x0054  21: Timer 1 */
DEFAULT_IRQ_HANDLER(TMR2_IRQHandler)               /* 0x16  0x0058  22: Timer 2 */
DEFAULT_IRQ_HANDLER(TMR3_IRQHandler)               /* 0x17  0x005C  23: Timer 3 */
DEFAULT_IRQ_HANDLER(TMR4_IRQHandler)               /* 0x18  0x0060  24: Timer 4 */
DEFAULT_IRQ_HANDLER(TMR5_IRQHandler)               /* 0x19  0x0064  25: Timer 5 */
DEFAULT_IRQ_HANDLER(I3C_IRQHandler)                /* 0x1A  0x0068  26: I3C */
DEFAULT_IRQ_HANDLER(UART_IRQHandler)               /* 0x1B  0x006C  27: UART */
DEFAULT_IRQ_HANDLER(SPI_IRQHandler)                /* 0x1C  0x0070  28: SPI */
DEFAULT_IRQ_HANDLER(FLC_IRQHandler)                /* 0x1D  0x0074  29: FLC */
DEFAULT_IRQ_HANDLER(GPIO0_IRQHandler)              /* 0x1E  0x0078  30: GPIO0 */
DEFAULT_IRQ_HANDLER(RSV15_IRQHandler)              /* 0x1F  0x007C  31: Reserved */
DEFAULT_IRQ_HANDLER(DMA0_CH0_IRQHandler)           /* 0x20  0x0080  32: DMA0 Channel 0 */
DEFAULT_IRQ_HANDLER(DMA0_CH1_IRQHandler)           /* 0x21  0x0084  33: DMA0 Channel 1 */
DEFAULT_IRQ_HANDLER(DMA0_CH2_IRQHandler)           /* 0x22  0x0088  34: DMA0 Channel 2 */
DEFAULT_IRQ_HANDLER(DMA0_CH3_IRQHandler)           /* 0x23  0x008C  35: DMA0 Channel 3 */
DEFAULT_IRQ_HANDLER(DMA1_CH0_IRQHandler)           /* 0x24  0x0090  36: DMA1 Channel 0 */
DEFAULT_IRQ_HANDLER(DMA1_CH1_IRQHandler)           /* 0x25  0x0094  37: DMA1 Channel 1 */
DEFAULT_IRQ_HANDLER(DMA1_CH2_IRQHandler)           /* 0x26  0x0098  38: DMA1 Channel 2 */
DEFAULT_IRQ_HANDLER(DMA1_CH3_IRQHandler)           /* 0x27  0x009C  39: DMA1 Channel 3 */
DEFAULT_IRQ_HANDLER(WUT0_IRQHandler)               /* 0x28  0x00A0  40: Wakeup Timer 0 */
DEFAULT_IRQ_HANDLER(WUT1_IRQHandler)               /* 0x29  0x00A4  41: Wakeup Timer 1 */
DEFAULT_IRQ_HANDLER(GPIOWAKE_IRQHandler)           /* 0x2A  0x00A8  42: GPIO Wakeup */
DEFAULT_IRQ_HANDLER(CRC_IRQHandler)                /* 0x2B  0x00AC  43: CRC */
DEFAULT_IRQ_HANDLER(AES_IRQHandler)                /* 0x2C  0x00B0  44: AES */
DEFAULT_IRQ_HANDLER(ERFO_IRQHandler)               /* 0x2D  0x00B4  45: ERFO Ready */
DEFAULT_IRQ_HANDLER(BOOST_IRQHandler)              /* 0x2E  0x00B8  46: Boost Controller */
DEFAULT_IRQ_HANDLER(ECC_IRQHandler)                /* 0x2F  0x00BC  47: ECC */
/* TODO(Bluetooth): Confirm BTLE IRQ Handler Names */
DEFAULT_IRQ_HANDLER(BTLE_XXXX0_IRQHandler)         /* 0x30  0x00C0  48: BTLE XXXX0 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX1_IRQHandler)         /* 0x31  0x00C4  49: BTLE XXXX1 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX2_IRQHandler)         /* 0x32  0x00C8  50: BTLE XXXX2 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX3_IRQHandler)         /* 0x33  0x00CC  51: BTLE XXXX3 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX4_IRQHandler)         /* 0x34  0x00D0  52: BTLE XXXX4 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX5_IRQHandler)         /* 0x35  0x00D4  53: BTLE XXXX5 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX6_IRQHandler)         /* 0x36  0x00D8  54: BTLE XXXX6 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX7_IRQHandler)         /* 0x37  0x00DC  55: BTLE XXXX7 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX8_IRQHandler)         /* 0x38  0x00E0  56: BTLE XXXX8 */
DEFAULT_IRQ_HANDLER(BTLE_XXXX9_IRQHandler)         /* 0x39  0x00E4  57: BTLE XXXX9 */
DEFAULT_IRQ_HANDLER(BTLE_XXXXA_IRQHandler)         /* 0x3A  0x00E8  58: BTLE XXXXA */
DEFAULT_IRQ_HANDLER(BTLE_XXXXB_IRQHandler)         /* 0x3B  0x00EC  59: BTLE XXXXB */
DEFAULT_IRQ_HANDLER(BTLE_XXXXC_IRQHandler)         /* 0x3C  0x00F0  60: BTLE XXXXC */
DEFAULT_IRQ_HANDLER(BTLE_XXXXD_IRQHandler)         /* 0x3D  0x00F4  61: BTLE XXXXD */
DEFAULT_IRQ_HANDLER(BTLE_XXXXE_IRQHandler)         /* 0x3E  0x00F8  62: BTLE XXXXE */
DEFAULT_IRQ_HANDLER(RSV47_IRQHandler)              /* 0x3F  0x00FC  63: Reserved */
DEFAULT_IRQ_HANDLER(MPC_IRQHandler)                /* 0x40  0x0100  64: MPC Combined (Secure) */
DEFAULT_IRQ_HANDLER(PPC_IRQHandler)                /* 0x44  0x0104  65: PPC Combined (Secure) */
DEFAULT_IRQ_HANDLER(RSV50_IRQHandler)              /* 0x48  0x0108  66: Reserved */
DEFAULT_IRQ_HANDLER(RSV51_IRQHandler)              /* 0x49  0x010C  67: Reserved */
DEFAULT_IRQ_HANDLER(RSV52_IRQHandler)              /* 0x4A  0x0110  68: Reserved */
DEFAULT_IRQ_HANDLER(RSV53_IRQHandler)              /* 0x4B  0x0114  69: Reserved */

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/**
  \brief Exception / Interrupt Handler Function Prototype
*/
typedef void (*VECTOR_TABLE_Type)(void);

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
    (VECTOR_TABLE_Type)(&__INITIAL_SP), /*      Initial Stack Pointer */
    Reset_Handler,                      /* Reset Handler */
    NMI_Handler,                        /* NMI Handler */
    HardFault_Handler,                  /* Hard Fault Handler */
    MemManage_Handler,                  /* MPU Fault Handler */
    BusFault_Handler,                   /* Bus Fault Handler */
    UsageFault_Handler,                 /* Usage Fault Handler */
    SecureFault_Handler,                /* Secure Fault Handler */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    0,                                  /* Reserved */
    SVC_Handler,                        /* SVCall Handler */
    DebugMon_Handler,                   /* Debug Monitor Handler */
    0,                                  /* Reserved */
    PendSV_Handler,                     /* PendSV Handler */
    SysTick_Handler,                    /* SysTick Handler */
    ICE_IRQHandler,                     /* 0x10  0x0040  16: ICE Unlock */
    WDT_IRQHandler,                     /* 0x11  0x0044  17: Watchdog Timer */
    RTC_IRQHandler,                     /* 0x12  0x0048  18: RTC */
    TRNG_IRQHandler,                    /* 0x13  0x004C  19: True Random Number Generator */
    TMR0_IRQHandler,                    /* 0x14  0x0050  20: Timer 0 */
    TMR1_IRQHandler,                    /* 0x15  0x0054  21: Timer 1 */
    TMR2_IRQHandler,                    /* 0x16  0x0058  22: Timer 2 */
    TMR3_IRQHandler,                    /* 0x17  0x005C  23: Timer 3 */
    TMR4_IRQHandler,                    /* 0x18  0x0060  24: Timer 4 */
    TMR5_IRQHandler,                    /* 0x19  0x0064  25: Timer 5 */
    I3C_IRQHandler,                     /* 0x1A  0x0068  26: I3C */
    UART_IRQHandler,                    /* 0x1B  0x006C  27: UART */
    SPI_IRQHandler,                     /* 0x1C  0x0070  28: SPI */
    FLC_IRQHandler,                     /* 0x1D  0x0074  29: FLC */
    GPIO0_IRQHandler,                   /* 0x1E  0x0078  30: GPIO0 */
    RSV15_IRQHandler,                   /* 0x1F  0x007C  31: Reserved */
    DMA0_CH0_IRQHandler,                /* 0x20  0x0080  32: DMA0 Channel 0 */
    DMA0_CH1_IRQHandler,                /* 0x21  0x0084  33: DMA0 Channel 1 */
    DMA0_CH2_IRQHandler,                /* 0x22  0x0088  34: DMA0 Channel 2 */
    DMA0_CH3_IRQHandler,                /* 0x23  0x008C  35: DMA0 Channel 3 */
    DMA1_CH0_IRQHandler,                /* 0x24  0x0090  36: DMA1 Channel 0 */
    DMA1_CH1_IRQHandler,                /* 0x25  0x0094  37: DMA1 Channel 1 */
    DMA1_CH2_IRQHandler,                /* 0x26  0x0098  38: DMA1 Channel 2 */
    DMA1_CH3_IRQHandler,                /* 0x27  0x009C  39: DMA1 Channel 3 */
    WUT0_IRQHandler,                    /* 0x28  0x00A0  40: Wakeup Timer 0 */
    WUT1_IRQHandler,                    /* 0x29  0x00A4  41: Wakeup Timer 1 */
    GPIOWAKE_IRQHandler,                /* 0x2A  0x00A8  42: GPIO Wakeup */
    CRC_IRQHandler,                     /* 0x2B  0x00AC  43: CRC */
    AES_IRQHandler,                     /* 0x2C  0x00B0  44: AES */
    ERFO_IRQHandler,                    /* 0x2D  0x00B4  45: ERFO Ready */
    BOOST_IRQHandler,                   /* 0x2E  0x00B8  46: Boost Controller */
    ECC_IRQHandler,                     /* 0x2F  0x00BC  47: ECC */
                                        /* TODO(Bluetooth): Confirm BTLE IRQ Handler Names */
    BTLE_XXXX0_IRQHandler,              /* 0x30  0x00C0  48: BTLE XXXX0 */
    BTLE_XXXX1_IRQHandler,              /* 0x31  0x00C4  49: BTLE XXXX1 */
    BTLE_XXXX2_IRQHandler,              /* 0x32  0x00C8  50: BTLE XXXX2 */
    BTLE_XXXX3_IRQHandler,              /* 0x33  0x00CC  51: BTLE XXXX3 */
    BTLE_XXXX4_IRQHandler,              /* 0x34  0x00D0  52: BTLE XXXX4 */
    BTLE_XXXX5_IRQHandler,              /* 0x35  0x00D4  53: BTLE XXXX5 */
    BTLE_XXXX6_IRQHandler,              /* 0x36  0x00D8  54: BTLE XXXX6 */
    BTLE_XXXX7_IRQHandler,              /* 0x37  0x00DC  55: BTLE XXXX7 */
    BTLE_XXXX8_IRQHandler,              /* 0x38  0x00E0  56: BTLE XXXX8 */
    BTLE_XXXX9_IRQHandler,              /* 0x39  0x00E4  57: BTLE XXXX9 */
    BTLE_XXXXA_IRQHandler,              /* 0x3A  0x00E8  58: BTLE XXXXA */
    BTLE_XXXXB_IRQHandler,              /* 0x3B  0x00EC  59: BTLE XXXXB */
    BTLE_XXXXC_IRQHandler,              /* 0x3C  0x00F0  60: BTLE XXXXC */
    BTLE_XXXXD_IRQHandler,              /* 0x3D  0x00F4  61: BTLE XXXXD */
    BTLE_XXXXE_IRQHandler,              /* 0x3E  0x00F8  62: BTLE XXXXE */
    RSV47_IRQHandler,                   /* 0x3F  0x00FC  63: Reserved */
    MPC_IRQHandler,                     /* 0x40  0x0100  64: MPC Combined (Secure) */
    PPC_IRQHandler,                     /* 0x44  0x0104  65: PPC Combined (Secure) */
    RSV50_IRQHandler,                   /* 0x48  0x0108  66: Reserved */
    RSV51_IRQHandler,                   /* 0x49  0x010C  67: Reserved */
    RSV52_IRQHandler,                   /* 0x4A  0x0110  68: Reserved */
    RSV53_IRQHandler,                   /* 0x4B  0x0114  69: Reserved */
};

// FIXME: if we want to have __isr_vector in system_max32657.c, uncomment below line
// extern const VECTOR_TABLE_Type __VECTOR_TABLE __attribute__((alias("__isr_vector")));

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();      /* CMSIS System Initialization */
    __PROGRAM_START(); /* Enter PreMain (C library entry point) */
}
