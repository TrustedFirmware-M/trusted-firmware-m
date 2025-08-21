/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM55.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */
#include "platform_base_address.h"
#include "sam_interrupts.h"
#include "tfm_hal_device_header.h"
#include "region_defs.h"
#include "rse_gretreg.h"

#include <stdint.h>

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exception handler that blocks execution. */
__NO_RETURN void exception_handler(void)
{
    while (1);
}

/* No IRQs are enabled in BL1, so this handler should be unreachable. In case it
 * is ever reached, disable the IRQ that was triggered and return. In debug
 * builds, block execution to catch the bug.
 */
void invalid_irq_handler(void)
{
#ifndef NDEBUG
    while (1);
#else
    NVIC_DisableIRQ((IRQn_Type)((int32_t)__get_IPSR() - 16));
#endif
}

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
       const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP), /*     Initial Stack Pointer */
  Reset_Handler,                     /*      Reset Handler */
  NMI_Handler,                       /* -14: NMI Handler */
  exception_handler,                 /* -13: Hard Fault Handler */
  exception_handler,                 /* -12: MPU Fault Handler */
  exception_handler,                 /* -11: Bus Fault Handler */
  exception_handler,                 /* -10: Usage Fault Handler */
  exception_handler,                 /*  -9: Secure Fault Handler */
  0,                                 /*      Reserved */
  0,                                 /*      Reserved */
  0,                                 /*      Reserved */
  exception_handler,                 /*  -5: SVCall Handler */
  exception_handler,                 /*  -4: Debug Monitor Handler */
  0,                                 /*      Reserved */
  exception_handler,                 /*  -2: PendSV Handler */
  exception_handler,                 /*  -1: SysTick Handler */

  invalid_irq_handler,               /*   0: Non-Secure Watchdog Reset Request Handler */
  invalid_irq_handler,               /*   1: Non-Secure Watchdog Handler */
  invalid_irq_handler,               /*   2: SLOWCLK Timer Handler */
  invalid_irq_handler,               /*   3: TIMER 0 Handler */
  invalid_irq_handler,               /*   4: TIMER 1 Handler */
  invalid_irq_handler,               /*   5: TIMER 2 Handler */
  0,                                 /*   6: Reserved */
  0,                                 /*   7: Reserved */
  0,                                 /*   8: Reserved */
  invalid_irq_handler,               /*   9: MPC Combined (Secure) Handler */
  invalid_irq_handler,               /*  10: PPC Combined (Secure) Handler */
  invalid_irq_handler,               /*  11: MSC Combined (Secure) Handler */
  invalid_irq_handler,               /*  12: Bridge Error (Secure) Handler */
  0,                                 /*  13: Reserved */
  invalid_irq_handler,               /*  14: PPU Combined (Secure) Handler */
  0,                                 /*  15: Reserved */
  invalid_irq_handler,               /*  16: NPU0 Handler */
  invalid_irq_handler,               /*  17: NPU1 Handler */
  invalid_irq_handler,               /*  18: NPU2 Handler */
  invalid_irq_handler,               /*  19: NPU3 Handler */
  invalid_irq_handler,               /*  20: KMU (Secure) Handler */
  0,                                 /*  21: Reserved */
  0,                                 /*  22: Reserved */
  0,                                 /*  23: Reserved */
  invalid_irq_handler,               /*  24: DMA350 Combined (Secure) Handler */
  invalid_irq_handler,               /*  25: DMA350 Combined (Non-Secure) Handler */
  invalid_irq_handler,               /*  26: DMA350 Security Violation Handler */
  invalid_irq_handler,               /*  27: TIMER 3 AON Handler */
  invalid_irq_handler,               /*  28: CPU0 CTI IRQ 0 Handler */
  invalid_irq_handler,               /*  29: CPU0 CTI IRQ 1 Handler */
  0,                                 /*  30: Reserved */
  0,                                 /*  31: Reserved */

  /* External interrupts */
  SAM_Critical_Sec_Fault_S_Handler,  /*  32: SAM Critical Security Fault (Secure) Handler */
  SAM_Sec_Fault_S_Handler,           /*  33: SAM Security Fault (Secure) Handler */
  invalid_irq_handler,               /*  34: GPIO Combined (Secure) Handler */
  invalid_irq_handler,               /*  35: Secure Debug Channel Handler */
  invalid_irq_handler,               /*  36: FPU Exception Handler */
  SRAM_TRAM_ECC_Err_S_Handler,       /*  37: SRAM or TRAM Corrected ECC Error (Secure) Handler */
  invalid_irq_handler,               /*  38: Secure I-Cache (Secure) Handler */
  invalid_irq_handler,               /*  39: ATU (Secure) Handler */
  invalid_irq_handler,               /*  40: CMU MHU 0 Sender Handler */
  invalid_irq_handler,               /*  41: CMU MHU 0 Receiver Handler */
  invalid_irq_handler,               /*  42: CMU MHU 1 Sender Handler */
  invalid_irq_handler,               /*  43: CMU MHU 1 Receiver Handler */
  invalid_irq_handler,               /*  44: CMU MHU 2 Sender Handler */
  invalid_irq_handler,               /*  45: CMU MHU 2 Receiver Handler */
  invalid_irq_handler,               /*  46: CMU MHU 3 Sender Handler */
  invalid_irq_handler,               /*  47: CMU MHU 3 Receiver Handler */
  invalid_irq_handler,               /*  48: CMU MHU 4 Sender Handler */
  invalid_irq_handler,               /*  49: CMU MHU 4 Receiver Handler */
  invalid_irq_handler,               /*  50: CMU MHU 5 Sender Handler */
  invalid_irq_handler,               /*  51: CMU MHU 5 Receiver Handler */
  invalid_irq_handler,               /*  52: CMU MHU 6 Sender Handler */
  invalid_irq_handler,               /*  53: CMU MHU 6 Receiver Handler */
  invalid_irq_handler,               /*  54: CMU MHU 7 Sender Handler */
  invalid_irq_handler,               /*  55: CMU MHU 7 Receiver Handler */
  invalid_irq_handler,               /*  56: CMU MHU 8 Sender Handler */
  invalid_irq_handler,               /*  57: CMU MHU 8 Receiver Handler */
  invalid_irq_handler,               /*  58: Crypto Engine (Secure) Handler */
  invalid_irq_handler,               /*  59: SoC System Timer 0 AON Handler */
  invalid_irq_handler,               /*  60: SoC System Timer 1 AON Handler */
  SRAM_ECC_Partial_Write_S_Handler,  /*  61: SRAM ECC Detected Partial Write (Secure) Handler */
  invalid_irq_handler,               /*  62: Integrity Checker Handler */
  0,                                 /*  63: Reserved */
  0,                                 /*  64: Reserved */
  0,                                 /*  65: Reserved */
  0,                                 /*  66: Reserved */
  0,                                 /*  67: Reserved */
  0,                                 /*  68: Reserved */
  0,                                 /*  69: Reserved */
  0,                                 /*  70: Reserved */
  0,                                 /*  71: Reserved */
  0,                                 /*  72: Reserved */
  0,                                 /*  73: Reserved */
  0,                                 /*  74: Reserved */
  0,                                 /*  75: Reserved */
  0,                                 /*  76: Reserved */
  0,                                 /*  77: Reserved */
  0,                                 /*  78: Reserved */
  0,                                 /*  79: Reserved */
  0,                                 /*  80: Reserved */
  0,                                 /*  81: Reserved */
  0,                                 /*  82: Reserved */
  0,                                 /*  83: Reserved */
  0,                                 /*  84: Reserved */
  0,                                 /*  85: Reserved */
  0,                                 /*  86: Reserved */
  0,                                 /*  87: Reserved */
  0,                                 /*  88: Reserved */
  0,                                 /*  89: Reserved */
  0,                                 /*  90: Reserved */
  0,                                 /*  91: Reserved */
  0,                                 /*  92: Reserved */
  0,                                 /*  93: Reserved */
  0,                                 /*  94: Reserved */
  0,                                 /*  95: Reserved */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

static uint32_t tram_key_prefill_value;
static uint32_t tram_erase_value;
static uint32_t tram_key[8];

static inline void __attribute__ ((always_inline)) setup_tram_encryption(void)
{
    register uint32_t tram_key_erase_value __asm("r0");

    /* Set up cryptocell TRNG */
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x1c4) = 0x00000001;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x140) = 0x00000001;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x1c4) = 0x00000001;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x130) = 0x000001f4;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x12c) = 0x00000000;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x108) = 0x0000003f;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x100) = 0x0000001e;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x10c) = 0x00000004;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x10c) = 0x00000004;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x138) = 0x00000000;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x12c) = 0x00000001;
    while (*((volatile uint32_t *)(CC3XX_BASE_S + 0x104)) != 0x1){}
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x1bc) = 0x00000001;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x108) = 0xffffffff;

    /* Randomly initialize the TRAM key words */
    tram_key_prefill_value = *((volatile uint32_t *)(CC3XX_BASE_S + 0x114));
    for (register uint32_t idx __asm("r1") = 0; idx < 8; idx++) {
        tram_key[idx] = tram_key_prefill_value;
    }

    /* Generate the random word which is used to erase the tram key */
    tram_key_erase_value = *((volatile uint32_t *)(CC3XX_BASE_S + 0x118));

    /* Generate the TRAM key and shut down the cryptocell trng */
    tram_key[0] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x11c));
    tram_key[1] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x120));
    tram_key[2] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x124));
    tram_key[3] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x128));
    while (*((volatile uint32_t *)(CC3XX_BASE_S + 0x104)) != 0x1){}
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x1bc) = 0x00000001;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x108) = 0xffffffff;
    tram_key[4] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x114));
    tram_key[5] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x118));
    tram_key[6] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x11c));
    tram_key[7] = *((volatile uint32_t *)(CC3XX_BASE_S + 0x120));

    /* Write the TRAM keyslot */
    for (register uint32_t idx __asm("r1") = 0; idx < 8; idx ++) {
        *(volatile uint32_t *)(KMU_BASE_S + 0x210 + idx * sizeof(uint32_t)) = tram_key[idx];
    }

    /* configure and lock the TRAM keyslot */
    *(volatile uint32_t *)(KMU_BASE_S + 0x0cc) = (TRAM_BASE_S + 0x008);
    *(volatile uint32_t *)(KMU_BASE_S + 0x04c) = 0x00d60100;

    /* Set the TRAM key */
    for (register uint32_t idx __asm("r1") = 0; idx < 8; idx ++) {
        *(volatile uint32_t *)(TRAM_BASE_S + 0x008 + idx * sizeof(uint32_t)) = tram_key[idx];
    }

    /* Erase the TRAM key */
    for (register uint32_t idx __asm("r1") = 0; idx < 8; idx++) {
        tram_key[idx] = tram_key_erase_value;
    }

    /* Enable the TRAM */
    *(volatile uint32_t *)(TRAM_BASE_S + 0x004) = 0x00000001;

    /* Generate the TRAM erase random value */
    tram_erase_value = *((volatile uint32_t *)(CC3XX_BASE_S + 0x124));

    /* Work out how many DMA channels exist */
    register uint32_t dma_channel_amount __asm("r2") =
        (*((volatile uint32_t *)(DMA_350_BASE_S + 0xfb0)) >> 4 & 0xF) + 1;

    /* Configure all DMA channels to wipe the DTCM with the random value in
     * parallel.
     */
    for (register uint32_t idx __asm("r1") = 0; idx < dma_channel_amount; idx++) {
        /* Clear the DMA channel before use */
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000) = 0x00000002;
        while ((*((volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000)) & 0x2) != 0) {}

        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x038) = tram_erase_value;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x02c) = 0x000F0044;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x018) =
            DTCM_CPU0_BASE_S + (DTCM_SIZE / dma_channel_amount * idx);

        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x030) = 0x00010000;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x020) =
            (DTCM_SIZE / sizeof(uint64_t) / dma_channel_amount) << 16;

        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x024) = 0x00000000;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x00c) = 0x1200603;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x008) = 0x00000000;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000) = 0x00000001;
    }

    /* Wait for all the DMA channels to finish */
    for (register uint32_t idx __asm("r1") = 0; idx < dma_channel_amount; idx++) {
        while ((*((volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000)) & 0x1) != 0) {}
    }

    /* Shut down the cryptocell TRNG */
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x12c) = 0x00000000;
    *(volatile uint32_t *)(CC3XX_BASE_S + 0x1c4) = 0x00000000;
};

#if !(defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_SRAM))
static inline void __attribute__ ((always_inline)) erase_vm0_and_vm1(void)
{
    register uint32_t vm_erase_size __asm("r0");
    register uint32_t dma_channel_amount __asm("r1");

    if ((*(volatile uint32_t *)(RSE_SYSCTRL_BASE_S + 0x10c) >>
         RSE_GRETREG_BIT_OFFSET_PERSISTENT_DATA_VALID) & 0b1) {
        vm_erase_size = (VM0_SIZE + VM1_SIZE - VM_COLD_RESET_RETAINED_SIZE);
    } else {
        vm_erase_size = (VM0_SIZE + VM1_SIZE);
    }

    if (vm_erase_size == 0) {
        return;
    }

    dma_channel_amount = (*((volatile uint32_t *)(DMA_350_BASE_S + 0xfb0)) >> 4 & 0xF) + 1;

    /* Start the VM erase in the background */
    for (register uint32_t idx __asm("r2") = 0; idx < dma_channel_amount; idx++) {
        /* Clear the DMA channel before use */
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000) = 0x00000002;
        while ((*((volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000)) & 0x2) != 0) {}

        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x038) = 0x00000000;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x02c) = 0x000F0044;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x018) =
            VM0_BASE_S + (vm_erase_size / dma_channel_amount * idx);

        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x030) = 0x00010000;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x020) =
            (vm_erase_size / sizeof(uint64_t) / dma_channel_amount) << 16;

        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x024) = 0x00000000;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x00c) = 0x1200603;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x008) = 0x00000000;
        *(volatile uint32_t *)(DMA_350_BASE_S + 0x1000 + (0x100 * idx) + 0x000) = 0x00000001;
    }
}
#endif /* !(RSE_BL1_TEST_BINARY && RSE_TEST_BINARY_IN_SRAM) */

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void __NO_RETURN Reset_Handler(void)
{
#ifdef RSE_SUPPORT_ROM_LIB_RELOCATION
    /*
     * Use the GOT table from ROM at this point. This saves copying it into
     * SRAM.
     */
    __asm volatile("ldr    r9, =__etext \n");
#endif /* RSE_SUPPORT_ROM_LIB_RELOCATION */

    /* Disable No-Write Allocate mode for the DCache to avoid DCache being
     * bypassed when streaming mode is detected, e.g. during memset()
     */
    ICB->ACTLR |= ICB_ACTLR_DISNWAMODE_Msk;

    setup_tram_encryption();

#if !(defined(RSE_BL1_TEST_BINARY) && defined(RSE_TEST_BINARY_IN_SRAM))
    erase_vm0_and_vm1();
#endif

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));

    SystemInit();                    /* CMSIS System Initialization */
    __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}
