/*****************************************************************************

  Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

   Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the
   distribution.

   Neither the name of Texas Instruments Incorporated nor the names of
   its contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/

#ifndef ti_devices_msp_m0p_mspm33c321x__include
#define ti_devices_msp_m0p_mspm33c321x__include

/* Filename: m33c1.h */
/* Revised: 2024-09-20 11:27:33*/

/* Use standard integer types with explicit width */
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup M33C1_Definitions M33C1 Definitions
  This file defines all structures and symbols for M33C1
  @{
*/

/** @addtogroup M33C1_CMSIS Device CMSIS Definitions
  Configuration of the Processor and Core Peripherals
  @{
*/
/******************************************************************************
 * Interrupt Definitions                                                       *
 ******************************************************************************/
typedef enum IRQn {
    NonMaskableInt_IRQn        = -14, /* 2  Non Maskable Interrupt */
    HardFault_IRQn             = -13, /* 3  Hard Fault Interrupt */
    MemoryManagement_IRQn      = -12, /* 4  Memory Management Interrupt */
    BusFault_IRQn              = -11, /* 5  Bus Fault Intertupt */
    UsageFault_IRQn            = -10, /* 6  Usage Fault Interrupt */
    SecureFault_IRQn           = -9,  /* 7  Secure Fault Interrupt */
    SVCall_IRQn                = -5,  /* 11 SV Call Interrupt */
    PendSV_IRQn                = -2,  /* 14 Pend SV Interrupt */
    SysTick_IRQn               = -1,  /* 15 System Tick Interrupt */
    SYSCTL_INT_IRQn            = 0,   /* 16 SYSCTL_INT Interrupt */
    DEBUGSS_INT_IRQn           = 1,   /* 17 DEBUGSS_INT Interrupt */
    FLASHCTL_INT_IRQn          = 2,   /* 18 FLASHCTL_INT Interrupt */
    WWDT0_INT_IRQn             = 3,   /* 19 WWDT0_INT Interrupt */
    GPIOA_INT_IRQn             = 6,   /* 22 GPIOA_INT Interrupt */
    GPIOB_INT_IRQn             = 7,   /* 23 GPIOB_INT Interrupt */
    GPIOC_INT_IRQn             = 8,   /* 24 GPIOC_INT Interrupt */
    ADC0_INT_PUB1_INT_IRQn     = 9,   /* 25 ADC0_INT_PUB1_INT Interrupt */
    ADC0_INT_PUB2_INT_IRQn     = 10,  /* 26 ADC0_INT_PUB2_INT Interrupt */
    ADC0_INT_PUB3_INT_IRQn     = 11,  /* 27 ADC0_INT_PUB3_INT Interrupt */
    ADC0_INT_PUB4_INT_IRQn     = 12,  /* 28 ADC0_INT_PUB4_INT Interrupt */
    ADC0_EVT_INT_PUB1_INT_IRQn = 13,  /* 29 ADC0_EVT_INT_PUB1_INT Interrupt */
    ADC1_INT_PUB1_INT_IRQn     = 14,  /* 30 ADC1_INT_PUB1_INT Interrupt */
    ADC1_INT_PUB2_INT_IRQn     = 15,  /* 31 ADC1_INT_PUB2_INT Interrupt */
    ADC1_INT_PUB3_INT_IRQn     = 16,  /* 32 ADC1_INT_PUB3_INT Interrupt */
    ADC1_INT_PUB4_INT_IRQn     = 17,  /* 33 ADC1_INT_PUB4_INT Interrupt */
    ADC1_EVT_INT_PUB1_INT_IRQn = 18,  /* 34 ADC1_EVT_INT_PUB1_INT Interrupt */
    CANFD0_INT_IRQn            = 19,  /* 35 CANFD0_INT Interrupt */
    TIMA0_0_INT_IRQn           = 20,  /* 36 TIMA0_0_INT Interrupt */
    TIMG4_0_INT_IRQn           = 21,  /* 37 TIMG4_0_INT Interrupt */
    TIMG4_1_INT_IRQn           = 22,  /* 38 TIMG4_1_INT Interrupt */
    TIMG8_0_INT_IRQn           = 23,  /* 39 TIMG8_0_INT Interrupt */
    TIMG12_0_INT_IRQn          = 24,  /* 40 TIMG12_0_INT Interrupt */
    UC1_0_INT_IRQn             = 25,  /* 41 UC1_0_INT Interrupt */
    UC1_1_INT_IRQn             = 26,  /* 42 UC1_1_INT Interrupt */
    UC2_INT_IRQn               = 27,  /* 43 UC2_INT Interrupt */
    UC15_0_INT_IRQn            = 28,  /* 44 UC15_0_INT Interrupt */
    UC15_1_INT_IRQn            = 29,  /* 45 UC15_1_INT Interrupt */
    UC12_INT_IRQn              = 30,  /* 46 UC12_INT Interrupt */
    UC13_0_INT_IRQn            = 31,  /* 47 UC13_0_INT Interrupt */
    UC14_INT_IRQn              = 32,  /* 48 UC14_INT Interrupt */
    CANFD1_INT_IRQn            = 33,  /* 49 CANFD1_INT Interrupt */
    TIMA0_1_INT_IRQn           = 34,  /* 50 TIMA0_1_INT Interrupt */
    TIMG4_2_INT_IRQn           = 35,  /* 51 TIMG4_2_INT Interrupt */
    TIMG4_3_INT_IRQn           = 36,  /* 52 TIMG4_3_INT Interrupt */
    TIMG8_1_INT_IRQn           = 37,  /* 53 TIMG8_1_INT Interrupt */
    COMP0_INT_IRQn             = 38,  /* 54 COMP0_INT Interrupt */
    COMP1_INT_IRQn             = 39,  /* 55 COMP1_INT Interrupt */
    TRNG_INT_IRQn              = 40,  /* 56 TRNG_INT Interrupt */
    AESADV_INT_IRQn            = 41,  /* 57 AESADV_INT Interrupt */
    LFSS_INT_IRQn              = 42,  /* 58 LFSS_INT Interrupt */
    DMA0_INT_IRQn              = 43,  /* 59 DMA0_INT Interrupt */
    DMA1_INT_IRQn              = 44,  /* 60 DMA1_INT Interrupt */
    I2S0_INT_IRQn              = 45,  /* 61 I2S0_INT Interrupt */
    I2S1_INT_IRQn              = 46,  /* 62 I2S1_INT Interrupt */
    QSPI_INT_IRQn              = 47,  /* 63 QSPI_INT Interrupt */
    SHAW_INT_IRQn              = 48,  /* 64 SHAW_INT Interrupt */
    PKA_INT_IRQn               = 49,  /* 65 PKA_INT Interrupt */
  UC13_1_INT_IRQn              = 50,     /* 66 UC13_1_INT Interrupt */
  UC13_2_INT_IRQn              = 51,     /* 67 UC13_2_INT Interrupt */
  UC13_3_INT_IRQn              = 52,     /* 68 UC13_3_INT Interrupt */
} IRQn_Type;

#define NonMaskableInt_VECn        2  /* Non Maskable Interrupt */
#define HardFault_VECn             3  /* Hard Fault Interrupt */
#define SVCall_VECn                11 /* SV Call Interrupt */
#define PendSV_VECn                14 /* Pend SV Interrupt */
#define SysTick_VECn               15 /* System Tick Interrupt */
#define SYSCTL_INT_VECn            16 /* SYSCTL_INT Interrupt */
#define DEBUGSS_INT_VECn           17 /* DEBUGSS_INT Interrupt */
#define FLASHCTL_INT_VECn          18 /* FLASHCTL_INT Interrupt */
#define WWDT0_INT_VECn             19 /* WWDT0_INT Interrupt */
#define GPIOA_INT_VECn             22 /* GPIOA_INT Interrupt */
#define GPIOB_INT_VECn             23 /* GPIOB_INT Interrupt */
#define GPIOC_INT_VECn             24 /* GPIOC_INT Interrupt */
#define ADC0_INT_PUB1_INT_VECn     25 /* ADC0_INT_PUB1_INT Interrupt */
#define ADC0_INT_PUB2_INT_VECn     26 /* ADC0_INT_PUB2_INT Interrupt */
#define ADC0_INT_PUB3_INT_VECn     27 /* ADC0_INT_PUB3_INT Interrupt */
#define ADC0_INT_PUB4_INT_VECn     28 /* ADC0_INT_PUB4_INT Interrupt */
#define ADC0_EVT_INT_PUB1_INT_VECn 29 /* ADC0_EVT_INT_PUB1_INT Interrupt */
#define ADC1_INT_PUB1_INT_VECn     30 /* ADC1_INT_PUB1_INT Interrupt */
#define ADC1_INT_PUB2_INT_VECn     31 /* ADC1_INT_PUB2_INT Interrupt */
#define ADC1_INT_PUB3_INT_VECn     32 /* ADC1_INT_PUB3_INT Interrupt */
#define ADC1_INT_PUB4_INT_VECn     33 /* ADC1_INT_PUB4_INT Interrupt */
#define ADC1_EVT_INT_PUB1_INT_VECn 34 /* ADC1_EVT_INT_PUB1_INT Interrupt */
#define CANFD0_INT_VECn            35 /* CANFD0_INT Interrupt */
#define TIMA0_0_INT_VECn           36 /* TIMA0_0_INT Interrupt */
#define TIMG4_0_INT_VECn           37 /* TIMG4_0_INT Interrupt */
#define TIMG4_1_INT_VECn           38 /* TIMG4_1_INT Interrupt */
#define TIMG8_0_INT_VECn           39 /* TIMG8_0_INT Interrupt */
#define TIMG12_0_INT_VECn          40 /* TIMG12_0_INT Interrupt */
#define UC1_0_INT_VECn             41 /* UC1_0_INT Interrupt */
#define UC1_1_INT_VECn             42 /* UC1_1_INT Interrupt */
#define UC2_INT_VECn               43 /* UC2_INT Interrupt */
#define UC15_0_INT_VECn            44 /* UC15_0_INT Interrupt */
#define UC15_1_INT_VECn            45 /* UC15_1_INT Interrupt */
#define UC12_INT_VECn              46 /* UC12_INT Interrupt */
#define UC13_0_INT_VECn            47 /* UC13_0_INT Interrupt */
#define UC14_INT_VECn              48 /* UC14_INT Interrupt */
#define CANFD1_INT_VECn            49 /* CANFD1_INT Interrupt */
#define TIMA0_1_INT_VECn           50 /* TIMA0_1_INT Interrupt */
#define TIMG4_2_INT_VECn           51 /* TIMG4_2_INT Interrupt */
#define TIMG4_3_INT_VECn           52 /* TIMG4_3_INT Interrupt */
#define TIMG8_1_INT_VECn           53 /* TIMG8_1_INT Interrupt */
#define COMP0_INT_VECn             54 /* COMP0_INT Interrupt */
#define COMP1_INT_VECn             55 /* COMP1_INT Interrupt */
#define TRNG_INT_VECn              56 /* TRNG_INT Interrupt */
#define AESADV_INT_VECn            57 /* AESADV_INT Interrupt */
#define LFSS_INT_VECn              58 /* LFSS_INT Interrupt */
#define DMA0_INT_VECn              59 /* DMA0_INT Interrupt */
#define DMA1_INT_VECn              60 /* DMA1_INT Interrupt */
#define I2S0_INT_VECn              61 /* I2S0_INT Interrupt */
#define I2S1_INT_VECn              62 /* I2S1_INT Interrupt */
#define QSPI_INT_VECn              63 /* QSPI_INT Interrupt */
#define SHAW_INT_VECn              64 /* SHAW_INT Interrupt */
#define PKA_INT_VECn               65 /* PKA_INT Interrupt */
#define UC13_1_INT_VECn            66 /* UC13_1_INT Interrupt */
#define UC13_2_INT_VECn            67 /* UC13_2_INT Interrupt */
#define UC13_3_INT_VECn            68 /* UC13_3_INT Interrupt */

/******************************************************************************
 * Ignore unused variables                                                     *
 ******************************************************************************/

#if defined(__CC_ARM)
#pragma push
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language = extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#pragma warning 586
#elif defined(__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/******************************************************************************
 * Processor and Core Peripheral Section                                       *
 ******************************************************************************/

#define __CM33_REV             0x0001U /* Core revision r0p1 */
#define __MPU_PRESENT          0x0001U /* MPU present */
#define __FPU_PRESENT          0x0001U /* FPU present */
#define __DSP_PRESENT          0x0001U /* DSP present */
#define __VTOR_PRESENT         0x0001U /* VTOR present */
#define __NVIC_PRIO_BITS       0x0006U /* Number of bits used for Priority Levels */
#define __Vendor_SysTickConfig 0x0000U /* Set to 1 if different SysTick Config is used */

#include "core_cm33.h" /* Processor and core peripherals */

/******************************************************************************
 * Peripheral headers                                                          *
 ******************************************************************************/
/** @addtogroup M33C1_Peripherals M33C1 Peripherals
  M33C1 Peripheral registers structures
  @{
*/

#include <ti/devices/msp/peripherals/hw_aesadv.h>
#include <ti/devices/msp/peripherals/hw_comp.h>
#include <ti/devices/msp/peripherals/hw_crcp.h>
#include <ti/devices/msp/peripherals/hw_dma.h>
#include <ti/devices/msp/peripherals/hw_flashctl.h>
#include <ti/devices/msp/peripherals/hw_fri.h>
#include <ti/devices/msp/peripherals/hw_gpio.h>
#include <ti/devices/msp/peripherals/hw_gptimer.h>
#include <ti/devices/msp/peripherals/hw_gsc.h>
#include <ti/devices/msp/peripherals/hw_hsadc.h>
#include <ti/devices/msp/peripherals/hw_i2s.h>
#include <ti/devices/msp/peripherals/hw_iomux.h>
#include <ti/devices/msp/peripherals/hw_keystorectl.h>
#include <ti/devices/msp/peripherals/hw_lfss.h>
#include <ti/devices/msp/peripherals/hw_mcan.h>
#include <ti/devices/msp/peripherals/hw_memcfg.h>
#include <ti/devices/msp/peripherals/hw_pka.h>
#include <ti/devices/msp/peripherals/hw_qspi.h>
#include <ti/devices/msp/peripherals/hw_rtc.h>
#include <ti/devices/msp/peripherals/hw_shaw.h>
#include <ti/devices/msp/peripherals/hw_spgss.h>
// #include <ti/devices/msp/peripherals/hw_spgss0.h>
#include <ti/devices/msp/peripherals/hw_trng.h>
#include <ti/devices/msp/peripherals/hw_unicomm.h>
#include <ti/devices/msp/peripherals/hw_unicommi2cc.h>
#include <ti/devices/msp/peripherals/hw_unicommi2ct.h>
#include <ti/devices/msp/peripherals/hw_unicommspi.h>
#include <ti/devices/msp/peripherals/hw_unicommuart.h>
#include <ti/devices/msp/peripherals/hw_vref.h>
#include <ti/devices/msp/peripherals/hw_wuc.h>
#include <ti/devices/msp/peripherals/hw_wwdt.h>
#include <ti/devices/msp/peripherals/m33/hw_debugss.h>
#include <ti/devices/msp/peripherals/m33/hw_factoryregion.h>
#include <ti/devices/msp/peripherals/m33/hw_sysctl.h>
#include <ti/devices/msp/peripherals/m33/hw_eam.h>

/*@}*/ /* end of group M33C1_Peripherals */

/******************************************************************************
 * Device and peripheral memory map for Non-Secure Space.                                         *
 ******************************************************************************/
/** @addtogroup M33C1_MemoryMap M33C1 Memory Mapping
  @{
*/

#define TRNG_BASE                      (0x40044000U) /*!< Base address of module TRNG */
#define WWDT0_BASE                     (0x400D0000U) /*!< Base address of module WWDT0 */
#define CRCP0_BASE                     (0x401B2000U) /*!< Base address of module CRCP0 */
#define LFSS_BASE                      (0x400D8000U) /*!< Base address of module LFSS */
#define RTC_A_BASE                     (0x400D8000U) /*!< Base address of module RTC_A */
#define GPIOA_BASE                     (0x400F0000U) /*!< Base address of module GPIOA */
#define GPIOB_BASE                     (0x400F2000U) /*!< Base address of module GPIOB */
#define GPIOC_BASE                     (0x400F4000U) /*!< Base address of module GPIOC */
#define DEBUGSS_BASE                   (0x400C7000U) /*!< Base address of module DEBUGSS */
#define AESADV_BASE                    (0x401B0000U) /*!< Base address of module AESADV */
#define WUC_BASE                       (0x40424000U) /*!< Base address of module WUC */
#define KEYSTORECTL_BASE               (0x401B6000U) /*!< Base address of module KEYSTORECTL */
#define I2S0_BASE                      (0x401A0000U) /*!< Base address of module I2S0 */
#define I2S1_BASE                      (0x401A2000U) /*!< Base address of module I2S1 */
#define TIMA0_1_BASE                   (0x40012000U) /*!< Base address of module TIMA0_1 */
#define TIMA0_0_BASE                   (0x40010000U) /*!< Base address of module TIMA0_0 */
#define TIMG4_0_BASE                   (0x400C0000U) /*!< Base address of module TIMG4_0 */
#define TIMG4_1_BASE                   (0x400C2000U) /*!< Base address of module TIMG4_1 */
#define TIMG4_2_BASE                   (0x40180000U) /*!< Base address of module TIMG4_2 */
#define TIMG4_3_BASE                   (0x40182000U) /*!< Base address of module TIMG4_3 */
#define TIMG8_0_BASE                   (0x40184000U) /*!< Base address of module TIMG8_0 */
#define TIMG8_1_BASE                   (0x40186000U) /*!< Base address of module TIMG8_1 */
#define TIMG12_0_BASE                  (0x40188000U) /*!< Base address of module TIMG12_0 */
#define FLASHCTL_BASE                  (0x40042000U) /*!< Base address of module FLASHCTL */
#define IOMUX_BASE                     (0x400CC000U) /*!< Base address of module IOMUX */
#define QSPI_BASE                      (0x40032000U) /*!< Base address of module QSPI */
#define SYSCTL_BASE                    (0x400AF000U) /*!< Base address of module SYSCTL */
#define COMP0_BASE                     (0x400E0000U) /*!< Base address of module COMP0 */
#define UC1_0_UART_BASE                (0x40502000U) /*!< Base address of module UC1_0_UART */
#define UC1_1_UART_BASE                (0x40504000U) /*!< Base address of module UC1_1_UART */
#define UC1_0_I2CC_BASE                (0x40522000U) /*!< Base address of module UC1_0_I2CC */
#define UC1_1_I2CC_BASE                (0x40524000U) /*!< Base address of module UC1_1_I2CC */
#define UC1_0_I2CT_BASE                (0x40542000U) /*!< Base address of module UC1_0_I2CT */
#define UC1_1_I2CT_BASE                (0x40544000U) /*!< Base address of module UC1_1_I2CT */
#define UC1_0_BASE                     (0x40582000U) /*!< Base address of module UC1_0 */
#define UC1_1_BASE                     (0x40584000U) /*!< Base address of module UC1_1 */
#define SPG0_BASE                      (0x4059F000U) /*!< Base address of module SPG0 */
#define UC12_UART_BASE                 (0x40608000U) /*!< Base address of module UC12_UART */
#define UC13_0_UART_BASE               (0x4060A000U) /*!< Base address of module UC13_0_UART */
#define UC15_0_I2CC_BASE               (0x40624000U) /*!< Base address of module UC15_0_I2CC */
#define UC15_1_I2CC_BASE               (0x40626000U) /*!< Base address of module UC15_1_I2CC */
#define UC13_0_I2CC_BASE               (0x4062A000U) /*!< Base address of module UC13_0_I2CC */
#define UC15_0_I2CT_BASE               (0x40644000U) /*!< Base address of module UC15_0_I2CT */
#define UC15_1_I2CT_BASE               (0x40646000U) /*!< Base address of module UC15_1_I2CT */
#define UC13_0_I2CT_BASE               (0x4064A000U) /*!< Base address of module UC13_0_I2CT */
#define UC2_SPI_BASE                   (0x40660000U) /*!< Base address of module UC2_SPI */
#define UC13_0_SPI_BASE                (0x4066A000U) /*!< Base address of module UC13_0_SPI */
#define UC2_BASE                       (0x40680000U) /*!< Base address of module UC2 */
#define UC15_0_BASE                    (0x40684000U) /*!< Base address of module UC15_0 */
#define UC15_1_BASE                    (0x40686000U) /*!< Base address of module UC15_1 */
#define UC12_BASE                      (0x40688000U) /*!< Base address of module UC12 */
#define UC13_0_BASE                    (0x4068A000U) /*!< Base address of module UC13_0 */
#define SPG1_BASE                      (0x4069F000U) /*!< Base address of module SPG1 */
#define UC13_1_UART_BASE               (0x40700000U) /*!< Base address of module UC13_1_UART */
#define UC13_2_UART_BASE               (0x40702000U) /*!< Base address of module UC13_2_UART */
#define UC13_3_UART_BASE               (0x40704000U) /*!< Base address of module UC13_3_UART */
#define UC14_UART_BASE                 (0x40706000U) /*!< Base address of module UC14_UART */
#define UC13_1_I2CC_BASE               (0x40720000U) /*!< Base address of module UC13_1_I2CC */
#define UC13_2_I2CC_BASE               (0x40722000U) /*!< Base address of module UC13_2_I2CC */
#define UC13_3_I2CC_BASE               (0x40724000U) /*!< Base address of module UC13_3_I2CC */
#define UC14_I2CC_BASE                 (0x40726000U) /*!< Base address of module UC14_I2CC */
#define UC13_1_I2CT_BASE               (0x40740000U) /*!< Base address of module UC13_1_I2CT */
#define UC13_2_I2CT_BASE               (0x40742000U) /*!< Base address of module UC13_2_I2CT */
#define UC13_3_I2CT_BASE               (0x40744000U) /*!< Base address of module UC13_3_I2CT */
#define UC14_I2CT_BASE                 (0x40746000U) /*!< Base address of module UC14_I2CT */
#define UC13_1_SPI_BASE                (0x40760000U) /*!< Base address of module UC13_1_SPI */
#define UC13_2_SPI_BASE                (0x40762000U) /*!< Base address of module UC13_2_SPI */
#define UC13_3_SPI_BASE                (0x40764000U) /*!< Base address of module UC13_3_SPI */
#define UC13_1_BASE                    (0x40780000U) /*!< Base address of module UC13_1 */
#define UC13_2_BASE                    (0x40782000U) /*!< Base address of module UC13_2 */
#define UC13_3_BASE                    (0x40784000U) /*!< Base address of module UC13_3 */
#define UC14_BASE                      (0x40786000U) /*!< Base address of module UC14 */
#define SPG2_BASE                      (0x4079F000U) /*!< Base address of module SPG2 */
#define GSC_BASE                       (0x50046000U) /*!< Base address of module GSC */
#define FACTORYREGION_BASE             (0x80111000U) /*!< Base address of module FACTORYREGION */
#define EAM_BASE                       (0x4002C000U) /*!< Base address of module EAM */
#define CANFD0_BASE                    (0x40110000U) /*!< Base address of module CANFD0 */
#define CANFD1_BASE                    (0x40118000U) /*!< Base address of module CANFD1 */
#define MEMCFG_BASE                    (0x4002A000U) /*!< Base address of module MEMCFG */
#define DMA0_BASE                      (0x40020000U) /*!< Base address of module DMA0 */
#define DMA1_BASE                      (0x40022000U) /*!< Base address of module DMA1 */
#define PKA_BASE                       (0x401C0000U) /*!< Base address of module PKA */
#define VREF_BASE                      (0x400E8000U) /*!< Base address of module VREF */
#define ADC0_ADC_LITE_REGS_BASE        (0x40000000U) /*!< Base address of module ADC0_ADC_LITE_REGS */
#define ADC0_ADC_LITE_RESULT_REGS_BASE (0x40004000U) /*!< Base address of module ADC0_ADC_LITE_RESULT_REGS */
#define ADC1_ADC_LITE_REGS_BASE        (0x40002000U) /*!< Base address of module ADC1_ADC_LITE_REGS */
#define ADC1_ADC_LITE_RESULT_REGS_BASE (0x40006000U) /*!< Base address of module ADC1_ADC_LITE_RESULT_REGS */
#define COMP1_BASE                     (0x400E2000U) /*!< Base address of module COMP1 */
#define FRI_BASE                       (0x40028000U) /*!< Base address of module FRI */
#define SHAW_BASE                      (0x401B4000U) /*!< Base address of module SHAW */
#define DFTSS_BASE                     (0x40034000U) /*!< Base address of module DFTSS */

typedef struct {
    UNICOMM_Regs         * const inst;
    UNICOMMUART_Regs     * const uart;
    UNICOMMI2CC_Regs     * const i2cc;
    UNICOMMI2CT_Regs     * const i2ct;
    UNICOMMSPI_Regs      * const spi;
    bool                   const fixedMode;
} UNICOMM_Inst_Regs;

static const UNICOMM_Inst_Regs UC1_0_Inst = {
    .inst      = (UNICOMM_Regs *) UC1_0_BASE,
    .uart      = (UNICOMMUART_Regs *) UC1_0_UART_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC1_0_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC1_0_I2CT_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC1_1_Inst = {
    .inst      = (UNICOMM_Regs *) UC1_1_BASE,
    .uart      = (UNICOMMUART_Regs *) UC1_1_UART_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC1_1_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC1_1_I2CT_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC2_Inst = {
    .inst      = (UNICOMM_Regs *) UC2_BASE,
    .spi       = (UNICOMMSPI_Regs *) UC2_SPI_BASE,
    .fixedMode = true
};
static const UNICOMM_Inst_Regs UC15_0_Inst = {
    .inst      = (UNICOMM_Regs *) UC15_0_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC15_0_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC15_0_I2CT_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC15_1_Inst = {
    .inst      = (UNICOMM_Regs *) UC15_1_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC15_1_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC15_1_I2CT_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC12_Inst = {
    .inst      = (UNICOMM_Regs *) UC12_BASE,
    .uart      = (UNICOMMUART_Regs *) UC12_UART_BASE,
    .fixedMode = true
};
static const UNICOMM_Inst_Regs UC13_0_Inst = {
    .inst      = (UNICOMM_Regs *) UC13_0_BASE,
    .uart      = (UNICOMMUART_Regs *) UC13_0_UART_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_0_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_0_I2CT_BASE,
    .spi       = (UNICOMMSPI_Regs *) UC13_0_SPI_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC13_1_Inst = {
    .inst      = (UNICOMM_Regs *) UC13_1_BASE,
    .uart      = (UNICOMMUART_Regs *) UC13_1_UART_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_1_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_1_I2CT_BASE,
    .spi       = (UNICOMMSPI_Regs *) UC13_1_SPI_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC13_2_Inst = {
    .inst      = (UNICOMM_Regs *) UC13_2_BASE,
    .uart      = (UNICOMMUART_Regs *) UC13_2_UART_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_2_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_2_I2CT_BASE,
    .spi       = (UNICOMMSPI_Regs *) UC13_2_SPI_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC13_3_Inst = {
    .inst      = (UNICOMM_Regs *) UC13_3_BASE,
    .uart      = (UNICOMMUART_Regs *) UC13_3_UART_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_3_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_3_I2CT_BASE,
    .spi       = (UNICOMMSPI_Regs *) UC13_3_SPI_BASE,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC14_Inst = {
    .inst      = (UNICOMM_Regs *) UC14_BASE,
    .uart      = (UNICOMMUART_Regs *) UC14_UART_BASE,
    .i2cc      = (UNICOMMI2CC_Regs *) UC14_I2CC_BASE,
    .i2ct      = (UNICOMMI2CT_Regs *) UC14_I2CT_BASE,
    .fixedMode = false
};
/******************************************************************************
 * Device and peripheral memory map for Secure Space.                                         *
 ******************************************************************************/
/** @addtogroup M33C1_MemoryMap M33C1 Memory Mapping
  @{
*/

#define TRNG_BASE_S                      (0x50044000U) /*!< Base address of module TRNG */
#define WWDT0_BASE_S                     (0x500D0000U) /*!< Base address of module WWDT0 */
#define CRCP0_BASE_S                     (0x501B2000U) /*!< Base address of module CRCP0 */
#define LFSS_BASE_S                      (0x500D8000U) /*!< Base address of module LFSS */
#define RTC_A_BASE_S                     (0x500D8000U) /*!< Base address of module RTC_A */
#define GPIOA_BASE_S                     (0x500F0000U) /*!< Base address of module GPIOA */
#define GPIOB_BASE_S                     (0x500F2000U) /*!< Base address of module GPIOB */
#define GPIOC_BASE_S                     (0x500F4000U) /*!< Base address of module GPIOC */
#define DEBUGSS_BASE_S                   (0x500C7000U) /*!< Base address of module DEBUGSS */
#define AESADV_BASE_S                    (0x501B0000U) /*!< Base address of module AESADV */
#define WUC_BASE_S                       (0x50424000U) /*!< Base address of module WUC */
#define KEYSTORECTL_BASE_S               (0x501B6000U) /*!< Base address of module KEYSTORECTL */
#define I2S0_BASE_S                      (0x501A0000U) /*!< Base address of module I2S0 */
#define I2S1_BASE_S                      (0x501A2000U) /*!< Base address of module I2S1 */
#define TIMA0_1_BASE_S                   (0x50012000U) /*!< Base address of module TIMA0_1 */
#define TIMA0_0_BASE_S                   (0x50010000U) /*!< Base address of module TIMA0_0 */
#define TIMG4_0_BASE_S                   (0x500C0000U) /*!< Base address of module TIMG4_0 */
#define TIMG4_1_BASE_S                   (0x500C2000U) /*!< Base address of module TIMG4_1 */
#define TIMG4_2_BASE_S                   (0x50180000U) /*!< Base address of module TIMG4_2 */
#define TIMG4_3_BASE_S                   (0x50182000U) /*!< Base address of module TIMG4_3 */
#define TIMG8_0_BASE_S                   (0x50184000U) /*!< Base address of module TIMG8_0 */
#define TIMG8_1_BASE_S                   (0x50186000U) /*!< Base address of module TIMG8_1 */
#define TIMG12_0_BASE_S                  (0x50188000U) /*!< Base address of module TIMG12_0 */
#define FLASHCTL_BASE_S                  (0x50042000U) /*!< Base address of module FLASHCTL */
#define IOMUX_BASE_S                     (0x500CC000U) /*!< Base address of module IOMUX */
#define QSPI_BASE_S                      (0x50032000U) /*!< Base address of module QSPI */
#define SYSCTL_BASE_S                    (0x500AF000U) /*!< Base address of module SYSCTL */
#define COMP0_BASE_S                     (0x500E0000U) /*!< Base address of module COMP0 */
#define UC1_0_UART_BASE_S                (0x50502000U) /*!< Base address of module UC1_0_UART */
#define UC1_1_UART_BASE_S                (0x50504000U) /*!< Base address of module UC1_1_UART */
#define UC1_0_I2CC_BASE_S                (0x50522000U) /*!< Base address of module UC1_0_I2CC */
#define UC1_1_I2CC_BASE_S                (0x50524000U) /*!< Base address of module UC1_1_I2CC */
#define UC1_0_I2CT_BASE_S                (0x50542000U) /*!< Base address of module UC1_0_I2CT */
#define UC1_1_I2CT_BASE_S                (0x50544000U) /*!< Base address of module UC1_1_I2CT */
#define UC1_0_BASE_S                     (0x50582000U) /*!< Base address of module UC1_0 */
#define UC1_1_BASE_S                     (0x50584000U) /*!< Base address of module UC1_1 */
#define SPG0_BASE_S                      (0x5059F000U) /*!< Base address of module SPG0 */
#define UC12_UART_BASE_S                 (0x50608000U) /*!< Base address of module UC12_UART */
#define UC13_0_UART_BASE_S               (0x5060A000U) /*!< Base address of module UC13_0_UART */
#define UC15_0_I2CC_BASE_S               (0x50624000U) /*!< Base address of module UC15_0_I2CC */
#define UC15_1_I2CC_BASE_S               (0x50626000U) /*!< Base address of module UC15_1_I2CC */
#define UC13_0_I2CC_BASE_S               (0x5062A000U) /*!< Base address of module UC13_0_I2CC */
#define UC15_0_I2CT_BASE_S               (0x50644000U) /*!< Base address of module UC15_0_I2CT */
#define UC15_1_I2CT_BASE_S               (0x50646000U) /*!< Base address of module UC15_1_I2CT */
#define UC13_0_I2CT_BASE_S               (0x5064A000U) /*!< Base address of module UC13_0_I2CT */
#define UC2_SPI_BASE_S                   (0x50660000U) /*!< Base address of module UC2_SPI */
#define UC13_0_SPI_BASE_S                (0x5066A000U) /*!< Base address of module UC13_0_SPI */
#define UC2_BASE_S                       (0x50680000U) /*!< Base address of module UC2 */
#define UC15_0_BASE_S                    (0x50684000U) /*!< Base address of module UC15_0 */
#define UC15_1_BASE_S                    (0x50686000U) /*!< Base address of module UC15_1 */
#define UC12_BASE_S                      (0x50688000U) /*!< Base address of module UC12 */
#define UC13_0_BASE_S                    (0x5068A000U) /*!< Base address of module UC13_0 */
#define SPG1_BASE_S                      (0x5069F000U) /*!< Base address of module SPG1 */
#define UC13_1_UART_BASE_S               (0x50700000U) /*!< Base address of module UC13_1_UART */
#define UC13_2_UART_BASE_S               (0x50702000U) /*!< Base address of module UC13_2_UART */
#define UC13_3_UART_BASE_S               (0x50704000U) /*!< Base address of module UC13_3_UART */
#define UC14_UART_BASE_S                 (0x50706000U) /*!< Base address of module UC14_UART */
#define UC13_1_I2CC_BASE_S               (0x50720000U) /*!< Base address of module UC13_1_I2CC */
#define UC13_2_I2CC_BASE_S               (0x50722000U) /*!< Base address of module UC13_2_I2CC */
#define UC13_3_I2CC_BASE_S               (0x50724000U) /*!< Base address of module UC13_3_I2CC */
#define UC14_I2CC_BASE_S                 (0x50726000U) /*!< Base address of module UC14_I2CC */
#define UC13_1_I2CT_BASE_S               (0x50740000U) /*!< Base address of module UC13_1_I2CT */
#define UC13_2_I2CT_BASE_S               (0x50742000U) /*!< Base address of module UC13_2_I2CT */
#define UC13_3_I2CT_BASE_S               (0x50744000U) /*!< Base address of module UC13_3_I2CT */
#define UC14_I2CT_BASE_S                 (0x50746000U) /*!< Base address of module UC14_I2CT */
#define UC13_1_SPI_BASE_S                (0x50760000U) /*!< Base address of module UC13_1_SPI */
#define UC13_2_SPI_BASE_S                (0x50762000U) /*!< Base address of module UC13_2_SPI */
#define UC13_3_SPI_BASE_S                (0x50764000U) /*!< Base address of module UC13_3_SPI */
#define UC13_1_BASE_S                    (0x50780000U) /*!< Base address of module UC13_1 */
#define UC13_2_BASE_S                    (0x50782000U) /*!< Base address of module UC13_2 */
#define UC13_3_BASE_S                    (0x50784000U) /*!< Base address of module UC13_3 */
#define UC14_BASE_S                      (0x50786000U) /*!< Base address of module UC14 */
#define SPG2_BASE_S                      (0x5079F000U) /*!< Base address of module SPG2 */
#define GSC_BASE_S                       (0x50046000U) /*!< Base address of module GSC */
#define FACTORYREGION_BASE_S             (0x90111000U) /*!< Base address of module FACTORYREGION */
#define EAM_BASE_S                       (0x5002C000U) /*!< Base address of module EAM */
#define CANFD0_BASE_S                    (0x50110000U) /*!< Base address of module CANFD0 */
#define CANFD1_BASE_S                    (0x50118000U) /*!< Base address of module CANFD1 */
#define MEMCFG_BASE_S                    (0x5002A000U) /*!< Base address of module MEMCFG */
#define DMA0_BASE_S                      (0x50020000U) /*!< Base address of module DMA0 */
#define DMA1_BASE_S                      (0x50022000U) /*!< Base address of module DMA1 */
#define PKA_BASE_S                       (0x501C0000U) /*!< Base address of module PKA */
#define VREF_BASE_S                      (0x500E8000U) /*!< Base address of module VREF */
#define ADC0_ADC_LITE_REGS_BASE_S        (0x50000000U) /*!< Base address of module ADC0_ADC_LITE_REGS */
#define ADC0_ADC_LITE_RESULT_REGS_BASE_S (0x50004000U) /*!< Base address of module ADC0_ADC_LITE_RESULT_REGS */
#define ADC1_ADC_LITE_REGS_BASE_S        (0x50002000U) /*!< Base address of module ADC1_ADC_LITE_REGS */
#define ADC1_ADC_LITE_RESULT_REGS_BASE_S (0x50006000U) /*!< Base address of module ADC1_ADC_LITE_RESULT_REGS */
#define COMP1_BASE_S                     (0x500E2000U) /*!< Base address of module COMP1 */
#define FRI_BASE_S                       (0x50028000U) /*!< Base address of module FRI */
#define SHAW_BASE_S                      (0x501B4000U) /*!< Base address of module SHAW */
#define DFTSS_BASE_S                     (0x50034000U) /*!< Base address of module DFTSS */

static const UNICOMM_Inst_Regs UC1_0_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC1_0_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC1_0_UART_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC1_0_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC1_0_I2CT_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC1_1_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC1_1_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC1_1_UART_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC1_1_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC1_1_I2CT_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC2_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC2_BASE_S,
    .spi       = (UNICOMMSPI_Regs *) UC2_SPI_BASE_S,
    .fixedMode = true
};
static const UNICOMM_Inst_Regs UC15_0_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC15_0_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC15_0_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC15_0_I2CT_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC15_1_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC15_1_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC15_1_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC15_1_I2CT_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC12_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC12_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC12_UART_BASE_S,
    .fixedMode = true
};
static const UNICOMM_Inst_Regs UC13_0_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC13_0_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC13_0_UART_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_0_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_0_I2CT_BASE_S,
    .spi       = (UNICOMMSPI_Regs *) UC13_0_SPI_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC13_1_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC13_1_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC13_1_UART_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_1_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_1_I2CT_BASE_S,
    .spi       = (UNICOMMSPI_Regs *) UC13_1_SPI_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC13_2_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC13_2_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC13_2_UART_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_2_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_2_I2CT_BASE_S,
    .spi       = (UNICOMMSPI_Regs *) UC13_2_SPI_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC13_3_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC13_3_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC13_3_UART_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC13_3_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC13_3_I2CT_BASE_S,
    .spi       = (UNICOMMSPI_Regs *) UC13_3_SPI_BASE_S,
    .fixedMode = false
};
static const UNICOMM_Inst_Regs UC14_Inst_S = {
    .inst      = (UNICOMM_Regs *) UC14_BASE_S,
    .uart      = (UNICOMMUART_Regs *) UC14_UART_BASE_S,
    .i2cc      = (UNICOMMI2CC_Regs *) UC14_I2CC_BASE_S,
    .i2ct      = (UNICOMMI2CT_Regs *) UC14_I2CT_BASE_S,
    .fixedMode = false
};
// #define __MSP_HAS_AESADVHP__
#define __MSP_HAS_AESADV__
#define __MSP_HAS_COMP__
#define __MSP_HAS_CRCP__
#define __MSP_HAS_GPIO__
#define __MSP_HAS_TIMER_A__
#define __MSP_HAS_TIMER_G__
#define __MSP_HAS_I2C__
#define __MSP_HAS_KEYSTORE_CTL__
#define __MSP_HAS_MCAN__
#define __MSP_HAS_LFSS__
#define __MSP_HAS_SPI__
#define __MSP_HAS_TRNG__
#define __MSP_HAS_VREF__
#define __MSP_HAS_WWDT__
#define __MSP_HAS_IWDT__
#define __MSP_HAS_TIO__
#define __MSP_HAS_RTC_A__
#define __MSP_HAS_SCRATCHPAD__
#define __MSP_HAS_QSPI__
#define __MSP_HAS_I2S__
#define __MSP_HAS_HSADC__

#define __MCU_HAS_SPGSS__
#define __MCU_HAS_UNICOMM__
#define __MCU_HAS_UNICOMMUART__
#define __MCU_HAS_UNICOMMI2CC__
#define __MCU_HAS_UNICOMMI2CT__
#define __MCU_HAS_UNICOMMSPI__
#define __MSP_HAS_EAM__

#define __MSPM33_HAS_ECC__

/*@}*/ /* end of group M33C1_MemoryMap */

/******************************************************************************
 * Peripheral declarations                                                     *
 ******************************************************************************/
/** @addtogroup M33C1_PeripheralDecl M33C1 Peripheral Declaration
  @{
*/

static TRNG_Regs                                      *const TRNG                                        = ((TRNG_Regs *)TRNG_BASE); 
static WWDT_Regs                                      *const WWDT0                                       = ((WWDT_Regs *)WWDT0_BASE); 
static CRCP_Regs                                      *const CRCP0                                       = ((CRCP_Regs *)CRCP0_BASE); 
static LFSS_Regs                                      *const LFSS                                        = ((LFSS_Regs *)LFSS_BASE); 
static GPIO_Regs                                      *const GPIOA                                       = ((GPIO_Regs *)GPIOA_BASE); 
static GPIO_Regs                                      *const GPIOB                                       = ((GPIO_Regs *)GPIOB_BASE); 
static GPIO_Regs                                      *const GPIOC                                       = ((GPIO_Regs *)GPIOC_BASE); 
static DEBUGSS_Regs                                   *const DEBUGSS                                     = ((DEBUGSS_Regs *)DEBUGSS_BASE); 
static AESADV_Regs                                  *const AESADV                                      = ((AESADV_Regs *)AESADV_BASE); 
static WUC_Regs                                       *const WUC                                         = ((WUC_Regs *)WUC_BASE); 
static KEYSTORECTL_Regs                               *const KEYSTORECTL                                 = ((KEYSTORECTL_Regs *)KEYSTORECTL_BASE); 
static I2S_Regs                                       *const I2S0                                        = ((I2S_Regs *)I2S0_BASE); 
static I2S_Regs                                       *const I2S1                                        = ((I2S_Regs *)I2S1_BASE); 
static GPTIMER_Regs                                   *const TIMA0_1                                     = ((GPTIMER_Regs *)TIMA0_1_BASE); 
static GPTIMER_Regs                                   *const TIMA0_0                                     = ((GPTIMER_Regs *)TIMA0_0_BASE); 
static GPTIMER_Regs                                   *const TIMG4_0                                     = ((GPTIMER_Regs *)TIMG4_0_BASE); 
static GPTIMER_Regs                                   *const TIMG4_1                                     = ((GPTIMER_Regs *)TIMG4_1_BASE); 
static GPTIMER_Regs                                   *const TIMG4_2                                     = ((GPTIMER_Regs *)TIMG4_2_BASE); 
static GPTIMER_Regs                                   *const TIMG4_3                                     = ((GPTIMER_Regs *)TIMG4_3_BASE); 
static GPTIMER_Regs                                   *const TIMG8_0                                     = ((GPTIMER_Regs *)TIMG8_0_BASE); 
static GPTIMER_Regs                                   *const TIMG8_1                                     = ((GPTIMER_Regs *)TIMG8_1_BASE); 
static GPTIMER_Regs                                   *const TIMG12_0                                    = ((GPTIMER_Regs *)TIMG12_0_BASE); 
static FLASHCTL_Regs                                  *const FLASHCTL                                    = ((FLASHCTL_Regs *)FLASHCTL_BASE); 
static IOMUX_Regs                                     *const IOMUX                                       = ((IOMUX_Regs *)IOMUX_BASE); 
static SHAW_Regs                                      *const SHAW                                        = ((SHAW_Regs *)SHAW_BASE); 
static QSPI_Regs                                      *const QSPI                                        = ((QSPI_Regs *)QSPI_BASE); 
static SYSCTL_Regs                                    *const SYSCTL                                      = ((SYSCTL_Regs *)SYSCTL_BASE); 
static COMP_Regs                                      *const COMP0                                       = ((COMP_Regs *) COMP0_BASE);
static GSC_Regs                                       *const GSC                                         = ((GSC_Regs *)GSC_BASE); 
static FACTORYREGION_OPEN_Regs                        *const FACTORYREGION                               = ((FACTORYREGION_OPEN_Regs *)FACTORYREGION_BASE); 
static FRI_Regs                                       *const FRI                                         = ((FRI_Regs *)FRI_BASE); 
static EAM_Regs                                       *const EAM                                         = ((EAM_Regs *) EAM_BASE);
static MCAN_Regs                                      *const CANFD0                                      = ((MCAN_Regs *)CANFD0_BASE); 
static MCAN_Regs                                      *const CANFD1                                      = ((MCAN_Regs *)CANFD1_BASE); 
static MEMCFG_Regs                                    *const MEMCFG                                      = ((MEMCFG_Regs *)MEMCFG_BASE); 
static DMA_Regs                                       *const DMA0                                        = ((DMA_Regs *)DMA0_BASE); 
static DMA_Regs                                       *const DMA1                                        = ((DMA_Regs *)DMA1_BASE); 
static PKA_Regs                                       *const PKA                                         = ((PKA_Regs *)PKA_BASE); 
static VREF_Regs                                      *const VREF                                        = ((VREF_Regs *)VREF_BASE); 
static hsadc_ADC_LITE_REGS_Regs                       *const ADC0_ADC_LITE_REGS                          = ((hsadc_ADC_LITE_REGS_Regs *)ADC0_ADC_LITE_REGS_BASE); 
static hsadc_ADC_LITE_RESULT_REGS_Regs                *const ADC0_ADC_LITE_RESULT_REGS                   = ((hsadc_ADC_LITE_RESULT_REGS_Regs *)ADC0_ADC_LITE_RESULT_REGS_BASE); 
static hsadc_ADC_LITE_REGS_Regs                       *const ADC1_ADC_LITE_REGS                          = ((hsadc_ADC_LITE_REGS_Regs *)ADC1_ADC_LITE_REGS_BASE); 
static hsadc_ADC_LITE_RESULT_REGS_Regs                *const ADC1_ADC_LITE_RESULT_REGS                   = ((hsadc_ADC_LITE_RESULT_REGS_Regs *)ADC1_ADC_LITE_RESULT_REGS_BASE); 
static COMP_Regs                                      *const COMP1                                       = ((COMP_Regs *)COMP1_BASE); 
static RTC_Regs                                       *const RTC_A                                       = ((RTC_Regs *)RTC_A_BASE); 
static UNICOMMUART_Regs                               *const UC1_0_UART                                  = ((UNICOMMUART_Regs *) UC1_0_UART_BASE);
static UNICOMMUART_Regs                               *const UC1_1_UART                                  = ((UNICOMMUART_Regs *) UC1_1_UART_BASE);
static UNICOMMI2CC_Regs                               *const UC1_0_I2CC                                  = ((UNICOMMI2CC_Regs *) UC1_0_I2CC_BASE);
static UNICOMMI2CC_Regs                               *const UC1_1_I2CC                                  = ((UNICOMMI2CC_Regs *) UC1_1_I2CC_BASE);
static UNICOMMI2CT_Regs                               *const UC1_0_I2CT                                  = ((UNICOMMI2CT_Regs *) UC1_0_I2CT_BASE);
static UNICOMMI2CT_Regs                               *const UC1_1_I2CT                                  = ((UNICOMMI2CT_Regs *) UC1_1_I2CT_BASE);
static UNICOMM_Inst_Regs                              *const UC1_0                                       = ((UNICOMM_Inst_Regs *) &UC1_0_Inst);
static UNICOMM_Inst_Regs                              *const UC1_1                                       = ((UNICOMM_Inst_Regs *) &UC1_1_Inst);
static SPGSS_Regs                                     *const SPG0                                        = ((SPGSS_Regs *) SPG0_BASE);
static UNICOMMUART_Regs                               *const UC12_UART                                   = ((UNICOMMUART_Regs *) UC12_UART_BASE);
static UNICOMMUART_Regs                               *const UC13_0_UART                                 = ((UNICOMMUART_Regs *) UC13_0_UART_BASE);
static UNICOMMI2CC_Regs                               *const UC15_0_I2CC                                 = ((UNICOMMI2CC_Regs *) UC15_0_I2CC_BASE);
static UNICOMMI2CC_Regs                               *const UC15_1_I2CC                                 = ((UNICOMMI2CC_Regs *) UC15_1_I2CC_BASE);
static UNICOMMI2CC_Regs                               *const UC13_0_I2CC                                 = ((UNICOMMI2CC_Regs *) UC13_0_I2CC_BASE);
static UNICOMMI2CT_Regs                               *const UC15_0_I2CT                                 = ((UNICOMMI2CT_Regs *) UC15_0_I2CT_BASE);
static UNICOMMI2CT_Regs                               *const UC15_1_I2CT                                 = ((UNICOMMI2CT_Regs *) UC15_1_I2CT_BASE);
static UNICOMMI2CT_Regs                               *const UC13_0_I2CT                                 = ((UNICOMMI2CT_Regs *) UC13_0_I2CT_BASE);
static UNICOMMSPI_Regs                                *const UC2_SPI                                     = ((UNICOMMSPI_Regs *) UC2_SPI_BASE);
static UNICOMMSPI_Regs                                *const UC13_0_SPI                                  = ((UNICOMMSPI_Regs *) UC13_0_SPI_BASE);
static UNICOMM_Inst_Regs                              *const UC2                                         = ((UNICOMM_Inst_Regs *) &UC2_Inst);
static UNICOMM_Inst_Regs                              *const UC15_0                                      = ((UNICOMM_Inst_Regs *) &UC15_0_Inst);
static UNICOMM_Inst_Regs                              *const UC15_1                                      = ((UNICOMM_Inst_Regs *) &UC15_1_Inst);
static UNICOMM_Inst_Regs                              *const UC12                                        = ((UNICOMM_Inst_Regs *) &UC12_Inst);
static UNICOMM_Inst_Regs                              *const UC13_0                                      = ((UNICOMM_Inst_Regs *) &UC13_0_Inst);
static SPGSS_Regs                                     *const SPG1                                        = ((SPGSS_Regs *) SPG1_BASE);
static UNICOMMUART_Regs                               *const UC13_1_UART                                 = ((UNICOMMUART_Regs *) UC13_1_UART_BASE);
static UNICOMMUART_Regs                               *const UC13_2_UART                                 = ((UNICOMMUART_Regs *) UC13_2_UART_BASE);
static UNICOMMUART_Regs                               *const UC13_3_UART                                 = ((UNICOMMUART_Regs *) UC13_3_UART_BASE);
static UNICOMMUART_Regs                               *const UC14_UART                                   = ((UNICOMMUART_Regs *) UC14_UART_BASE);
static UNICOMMI2CC_Regs                               *const UC13_1_I2CC                                 = ((UNICOMMI2CC_Regs *) UC13_1_I2CC_BASE);
static UNICOMMI2CC_Regs                               *const UC13_2_I2CC                                 = ((UNICOMMI2CC_Regs *) UC13_2_I2CC_BASE);
static UNICOMMI2CC_Regs                               *const UC13_3_I2CC                                 = ((UNICOMMI2CC_Regs *) UC13_3_I2CC_BASE);
static UNICOMMI2CC_Regs                               *const UC14_I2CC                                   = ((UNICOMMI2CC_Regs *) UC14_I2CC_BASE);
static UNICOMMI2CT_Regs                               *const UC13_1_I2CT                                 = ((UNICOMMI2CT_Regs *) UC13_1_I2CT_BASE);
static UNICOMMI2CT_Regs                               *const UC13_2_I2CT                                 = ((UNICOMMI2CT_Regs *) UC13_2_I2CT_BASE);
static UNICOMMI2CT_Regs                               *const UC13_3_I2CT                                 = ((UNICOMMI2CT_Regs *) UC13_3_I2CT_BASE);
static UNICOMMI2CT_Regs                               *const UC14_I2CT                                   = ((UNICOMMI2CT_Regs *) UC14_I2CT_BASE);
static UNICOMMSPI_Regs                                *const UC13_1_SPI                                  = ((UNICOMMSPI_Regs *) UC13_1_SPI_BASE);
static UNICOMMSPI_Regs                                *const UC13_2_SPI                                  = ((UNICOMMSPI_Regs *) UC13_2_SPI_BASE);
static UNICOMMSPI_Regs                                *const UC13_3_SPI                                  = ((UNICOMMSPI_Regs *) UC13_3_SPI_BASE);
static UNICOMM_Inst_Regs                              *const UC13_1                                      = ((UNICOMM_Inst_Regs *) &UC13_1_Inst);
static UNICOMM_Inst_Regs                              *const UC13_2                                      = ((UNICOMM_Inst_Regs *) &UC13_2_Inst);
static UNICOMM_Inst_Regs                              *const UC13_3                                      = ((UNICOMM_Inst_Regs *) &UC13_3_Inst);
static UNICOMM_Inst_Regs                              *const UC14                                        = ((UNICOMM_Inst_Regs *) &UC14_Inst);
static SPGSS_Regs                                     *const SPG2                                        = ((SPGSS_Regs *) SPG2_BASE);
static TRNG_Regs                                      *const TRNG_S                                      = ((TRNG_Regs *)TRNG_BASE_S); 
static WWDT_Regs                                      *const WWDT0_S                                     = ((WWDT_Regs *)WWDT0_BASE_S); 
static CRCP_Regs                                      *const CRCP0_S                                     = ((CRCP_Regs *)CRCP0_BASE_S); 
static LFSS_Regs                                      *const LFSS_S                                      = ((LFSS_Regs *)LFSS_BASE_S); 
static GPIO_Regs                                      *const GPIOA_S                                     = ((GPIO_Regs *)GPIOA_BASE_S); 
static GPIO_Regs                                      *const GPIOB_S                                     = ((GPIO_Regs *)GPIOB_BASE_S); 
static GPIO_Regs                                      *const GPIOC_S                                     = ((GPIO_Regs *)GPIOC_BASE_S); 
static DEBUGSS_Regs                                   *const DEBUGSS_S                                   = ((DEBUGSS_Regs *)DEBUGSS_BASE_S); 
static AESADV_Regs                                  *const AESADV_S                                    = ((AESADV_Regs *)AESADV_BASE_S); 
static WUC_Regs                                       *const WUC_S                                       = ((WUC_Regs *)WUC_BASE_S); 
static KEYSTORECTL_Regs                               *const KEYSTORECTL_S                               = ((KEYSTORECTL_Regs *)KEYSTORECTL_BASE_S); 
static I2S_Regs                                       *const I2S0_S                                      = ((I2S_Regs *) I2S0_BASE_S);
static I2S_Regs                                       *const I2S1_S                                      = ((I2S_Regs *) I2S1_BASE_S);
static GPTIMER_Regs                                   *const TIMA0_1_S                                   = ((GPTIMER_Regs *)TIMA0_1_BASE_S); 
static GPTIMER_Regs                                   *const TIMA0_0_S                                   = ((GPTIMER_Regs *)TIMA0_0_BASE_S); 
static GPTIMER_Regs                                   *const TIMG4_0_S                                   = ((GPTIMER_Regs *)TIMG4_0_BASE_S); 
static GPTIMER_Regs                                   *const TIMG4_1_S                                   = ((GPTIMER_Regs *)TIMG4_1_BASE_S); 
static GPTIMER_Regs                                   *const TIMG4_2_S                                   = ((GPTIMER_Regs *)TIMG4_2_BASE_S); 
static GPTIMER_Regs                                   *const TIMG4_3_S                                   = ((GPTIMER_Regs *)TIMG4_3_BASE_S); 
static GPTIMER_Regs                                   *const TIMG8_0_S                                   = ((GPTIMER_Regs *)TIMG8_0_BASE_S); 
static GPTIMER_Regs                                   *const TIMG8_1_S                                   = ((GPTIMER_Regs *)TIMG8_1_BASE_S); 
static GPTIMER_Regs                                   *const TIMG12_0_S                                  = ((GPTIMER_Regs *)TIMG12_0_BASE_S); 
static FLASHCTL_Regs                                  *const FLASHCTL_S                                  = ((FLASHCTL_Regs *)FLASHCTL_BASE_S); 
static IOMUX_Regs                                     *const IOMUX_S                                     = ((IOMUX_Regs *)IOMUX_BASE_S); 
static SHAW_Regs                                      *const SHAW_S                                      = ((SHAW_Regs *)SHAW_BASE_S); 
static QSPI_Regs                                      *const QSPI_S                                      = ((QSPI_Regs *)QSPI_BASE_S); 
static SYSCTL_Regs                                    *const SYSCTL_S                                    = ((SYSCTL_Regs *)SYSCTL_BASE_S); 
static COMP_Regs                                      *const COMP0_S                                     = ((COMP_Regs *) COMP0_BASE_S);
static GSC_Regs                                       *const GSC_S                                       = ((GSC_Regs *)GSC_BASE_S); 
static FACTORYREGION_OPEN_Regs                        *const FACTORYREGION_S                             = ((FACTORYREGION_OPEN_Regs *)FACTORYREGION_BASE_S); 
static FRI_Regs                                       *const FRI_S                                       = ((FRI_Regs *)FRI_BASE_S); 
static EAM_Regs                                       *const EAM_S                                       = ((EAM_Regs *) EAM_BASE_S);
static MCAN_Regs                                      *const CANFD0_S                                    = ((MCAN_Regs *)CANFD0_BASE_S); 
static MCAN_Regs                                      *const CANFD1_S                                    = ((MCAN_Regs *)CANFD1_BASE_S); 
static MEMCFG_Regs                                    *const MEMCFG_S                                    = ((MEMCFG_Regs *)MEMCFG_BASE_S); 
static DMA_Regs                                       *const DMA0_S                                      = ((DMA_Regs *)DMA0_BASE_S); 
static DMA_Regs                                       *const DMA1_S                                      = ((DMA_Regs *)DMA1_BASE_S); 
static PKA_Regs                                       *const PKA_S                                       = ((PKA_Regs *)PKA_BASE_S); 
static VREF_Regs                                      *const VREF_S                                      = ((VREF_Regs *)VREF_BASE_S); 
static hsadc_ADC_LITE_REGS_Regs                       *const ADC0_ADC_LITE_REGS_S                        = ((hsadc_ADC_LITE_REGS_Regs *)ADC0_ADC_LITE_REGS_BASE_S); 
static hsadc_ADC_LITE_RESULT_REGS_Regs                *const ADC0_ADC_LITE_RESULT_REGS_S                   = ((hsadc_ADC_LITE_RESULT_REGS_Regs *)ADC0_ADC_LITE_RESULT_REGS_BASE_S); 
static hsadc_ADC_LITE_REGS_Regs                       *const ADC1_ADC_LITE_REGS_S                        = ((hsadc_ADC_LITE_REGS_Regs *)ADC1_ADC_LITE_REGS_BASE_S); 
static hsadc_ADC_LITE_RESULT_REGS_Regs                *const ADC1_ADC_LITE_RESULT_REGS_S                   = ((hsadc_ADC_LITE_RESULT_REGS_Regs *)ADC1_ADC_LITE_RESULT_REGS_BASE_S); 
static COMP_Regs                                      *const COMP1_S                                     = ((COMP_Regs *)COMP1_BASE_S); 
static RTC_Regs                                       *const RTC_A_S                                     = ((RTC_Regs *)RTC_A_BASE_S); 
static UNICOMMUART_Regs                               *const UC1_0_UART_S                                = ((UNICOMMUART_Regs *) UC1_0_UART_BASE_S);
static UNICOMMUART_Regs                               *const UC1_1_UART_S                                = ((UNICOMMUART_Regs *) UC1_1_UART_BASE_S);
static UNICOMMI2CC_Regs                               *const UC1_0_I2CC_S                                = ((UNICOMMI2CC_Regs *) UC1_0_I2CC_BASE_S);
static UNICOMMI2CC_Regs                               *const UC1_1_I2CC_S                                = ((UNICOMMI2CC_Regs *) UC1_1_I2CC_BASE_S);
static UNICOMMI2CT_Regs                               *const UC1_0_I2CT_S                                = ((UNICOMMI2CT_Regs *) UC1_0_I2CT_BASE_S);
static UNICOMMI2CT_Regs                               *const UC1_1_I2CT_S                                = ((UNICOMMI2CT_Regs *) UC1_1_I2CT_BASE_S);
static UNICOMM_Inst_Regs                              *const UC1_0_S                                     = ((UNICOMM_Inst_Regs *) &UC1_0_Inst_S);
static UNICOMM_Inst_Regs                              *const UC1_1_S                                     = ((UNICOMM_Inst_Regs *) &UC1_1_Inst_S);
static SPGSS_Regs                                     *const SPG0_S                                      = ((SPGSS_Regs *) SPG0_BASE_S);
static UNICOMMUART_Regs                               *const UC12_UART_S                                 = ((UNICOMMUART_Regs *) UC12_UART_BASE_S);
static UNICOMMUART_Regs                               *const UC13_0_UART_S                               = ((UNICOMMUART_Regs *) UC13_0_UART_BASE_S);
static UNICOMMI2CC_Regs                               *const UC15_0_I2CC_S                               = ((UNICOMMI2CC_Regs *) UC15_0_I2CC_BASE_S);
static UNICOMMI2CC_Regs                               *const UC15_1_I2CC_S                               = ((UNICOMMI2CC_Regs *) UC15_1_I2CC_BASE_S);
static UNICOMMI2CC_Regs                               *const UC13_0_I2CC_S                               = ((UNICOMMI2CC_Regs *) UC13_0_I2CC_BASE_S);
static UNICOMMI2CT_Regs                               *const UC15_0_I2CT_S                               = ((UNICOMMI2CT_Regs *) UC15_0_I2CT_BASE_S);
static UNICOMMI2CT_Regs                               *const UC15_1_I2CT_S                               = ((UNICOMMI2CT_Regs *) UC15_1_I2CT_BASE_S);
static UNICOMMI2CT_Regs                               *const UC13_0_I2CT_S                               = ((UNICOMMI2CT_Regs *) UC13_0_I2CT_BASE_S);
static UNICOMMSPI_Regs                                *const UC2_SPI_S                                   = ((UNICOMMSPI_Regs *) UC2_SPI_BASE_S);
static UNICOMMSPI_Regs                                *const UC13_0_SPI_S                                = ((UNICOMMSPI_Regs *) UC13_0_SPI_BASE_S);
static UNICOMM_Inst_Regs                              *const UC2_S                                       = ((UNICOMM_Inst_Regs *) &UC2_Inst_S);
static UNICOMM_Inst_Regs                              *const UC15_0_S                                    = ((UNICOMM_Inst_Regs *) &UC15_0_Inst_S);
static UNICOMM_Inst_Regs                              *const UC15_1_S                                    = ((UNICOMM_Inst_Regs *) &UC15_1_Inst_S);
static UNICOMM_Inst_Regs                              *const UC12_S                                      = ((UNICOMM_Inst_Regs *) &UC12_Inst_S);
static UNICOMM_Inst_Regs                              *const UC13_0_S                                    = ((UNICOMM_Inst_Regs *) &UC13_0_Inst_S);
static SPGSS_Regs                                     *const SPG1_S                                      = ((SPGSS_Regs *) SPG1_BASE_S);
static UNICOMMUART_Regs                               *const UC13_1_UART_S                               = ((UNICOMMUART_Regs *) UC13_1_UART_BASE_S);
static UNICOMMUART_Regs                               *const UC13_2_UART_S                               = ((UNICOMMUART_Regs *) UC13_2_UART_BASE_S);
static UNICOMMUART_Regs                               *const UC13_3_UART_S                               = ((UNICOMMUART_Regs *) UC13_3_UART_BASE_S);
static UNICOMMUART_Regs                               *const UC14_UART_S                                 = ((UNICOMMUART_Regs *) UC14_UART_BASE_S);
static UNICOMMI2CC_Regs                               *const UC13_1_I2CC_S                               = ((UNICOMMI2CC_Regs *) UC13_1_I2CC_BASE_S);
static UNICOMMI2CC_Regs                               *const UC13_2_I2CC_S                               = ((UNICOMMI2CC_Regs *) UC13_2_I2CC_BASE_S);
static UNICOMMI2CC_Regs                               *const UC13_3_I2CC_S                               = ((UNICOMMI2CC_Regs *) UC13_3_I2CC_BASE_S);
static UNICOMMI2CC_Regs                               *const UC14_I2CC_S                                 = ((UNICOMMI2CC_Regs *) UC14_I2CC_BASE_S);
static UNICOMMI2CT_Regs                               *const UC13_1_I2CT_S                               = ((UNICOMMI2CT_Regs *) UC13_1_I2CT_BASE_S);
static UNICOMMI2CT_Regs                               *const UC13_2_I2CT_S                               = ((UNICOMMI2CT_Regs *) UC13_2_I2CT_BASE_S);
static UNICOMMI2CT_Regs                               *const UC13_3_I2CT_S                               = ((UNICOMMI2CT_Regs *) UC13_3_I2CT_BASE_S);
static UNICOMMI2CT_Regs                               *const UC14_I2CT_S                                 = ((UNICOMMI2CT_Regs *) UC14_I2CT_BASE_S);
static UNICOMMSPI_Regs                                *const UC13_1_SPI_S                                = ((UNICOMMSPI_Regs *) UC13_1_SPI_BASE_S);
static UNICOMMSPI_Regs                                *const UC13_2_SPI_S                                = ((UNICOMMSPI_Regs *) UC13_2_SPI_BASE_S);
static UNICOMMSPI_Regs                                *const UC13_3_SPI_S                                = ((UNICOMMSPI_Regs *) UC13_3_SPI_BASE_S);
static UNICOMM_Inst_Regs                              *const UC13_1_S                                    = ((UNICOMM_Inst_Regs *) &UC13_1_Inst_S);
static UNICOMM_Inst_Regs                              *const UC13_2_S                                    = ((UNICOMM_Inst_Regs *) &UC13_2_Inst_S);
static UNICOMM_Inst_Regs                              *const UC13_3_S                                    = ((UNICOMM_Inst_Regs *) &UC13_3_Inst_S);
static UNICOMM_Inst_Regs                              *const UC14_S                                      = ((UNICOMM_Inst_Regs *) &UC14_Inst_S);
static SPGSS_Regs                                     *const SPG2_S                                      = ((SPGSS_Regs *) SPG2_BASE_S);

/******************************************************************************
 * SYS parameters                                                              *
 ******************************************************************************/
#define CRCP0_SYS_CRC32_ENABLE (1)        /* !< Parameter to exclude or include 32-bit CRC. This is added for      \
                                                Lego_N1 products where 32-bit CRC can be excluded in order to save \
                                                gates. */
#define I2S0_SYS_FENTRIES           (4)   /* !< Number of FIFO entries */
#define I2S0_SYS_SINGLE_PIN         (0)   /* !< Boolean for if enable single Data Pin configuration. */
#define I2S1_SYS_FENTRIES           (4)   /* !< Number of FIFO entries */
#define I2S1_SYS_SINGLE_PIN         (0)   /* !< Boolean for if enable single Data Pin configuration. */
#define FLASHCTL_SYS_DATAWIDTH      (128) /* !< Data bit width of a single flash word:    Minimum: 64    Maximum: 128 */
#define FLASHCTL_SYS_WEPROTBWIDTH   (28)  /* !< Bit width of WEPROTB register. */
#define FLASHCTL_SYS_WEPROTAWIDTH   (32)  /* !< Bit width of WEPROTA register. */
#define FLASHCTL_SYS_WEPROTCWIDTH   (0)   /* !< Bit width of WEPROTC register. */
#define QSPI_SYS_FENTRIES           (4)   /* !< The number of entries in RX and TX FIFO */
#define DMA0_SYS_N_DMA_CHANNEL      (4)   /* !< Number of DMA channels implemented in DMA. */
#define DMA0_SYS_N_DMA_FULL_CHANNEL (2)   /* !< Number of FULL-DMA channels implemented in DMA. If           \
                                                SYS_N_DMA_CHANNEL is larger than SYS_N_DMA_FULL_CHANNEL, the \
                                                remaining channel will be BASIC channel with limited functionality. */
#define DMA1_SYS_N_DMA_CHANNEL      (12)  /* !< Number of DMA channels implemented in DMA. */
#define DMA1_SYS_N_DMA_FULL_CHANNEL (6)   /* !< Number of FULL-DMA channels implemented in DMA. If           \
                                                SYS_N_DMA_CHANNEL is larger than SYS_N_DMA_FULL_CHANNEL, the \
                                                remaining channel will be BASIC channel with limited functionality.*/

#define DMA_SYS_N_DMA_CHANNEL      (4) /* !< Number of DMA channels implemented in DMA. */
#define DMA_SYS_N_DMA_FULL_CHANNEL (2) /* !< Number of FULL-DMA channels implemented in DMA. */
#define DMA_SYS_MMR_LLONG          (1) /* !< Boolean for if channels implemented in DMA with 128-bit access. */
#define COMP_ANALOG_WAKEUP_ENABLE  (1) /* !< Boolean for if COMP has Analog Wakeup Feature available or not */

#define UC1_0_UART_SYS_GLITCH_FILTER                     (0)
#define UC1_0_UART_SYS_HW_FLOW_CONTROL                   (1)
#define UC1_0_UART_SYS_9_BIT                             (1)
#define UC1_0_UART_SYS_RS485                             (1)
#define UC1_0_UART_SYS_LIN                               (1)
#define UC1_0_UART_SYS_DALI                              (0)
#define UC1_0_UART_SYS_IRDA                              (0)
#define UC1_0_UART_SYS_SMART_CARD                        (0)
#define UC1_0_UART_SYS_IDLE_LINE                         (1)
#define UC1_0_UART_SYS_MANCHESTER_ENCODING               (0)
#define UC1_0_UART_SYS_FIFO_LENGTH                       (16)
#define UC1_0_UART_SYS_RX_TIMEOUT                        (1)
#define UC1_0_UART_SYS_DMA                               (1)
#define UC1_0_UART_SYS_EXTERNAL_DIRECTION                (0)

#define UC1_1_UART_SYS_GLITCH_FILTER                     (0)
#define UC1_1_UART_SYS_HW_FLOW_CONTROL                   (1)
#define UC1_1_UART_SYS_9_BIT                             (1)
#define UC1_1_UART_SYS_RS485                             (1)
#define UC1_1_UART_SYS_LIN                               (1)
#define UC1_1_UART_SYS_DALI                              (0)
#define UC1_1_UART_SYS_IRDA                              (0)
#define UC1_1_UART_SYS_SMART_CARD                        (0)
#define UC1_1_UART_SYS_IDLE_LINE                         (1)
#define UC1_1_UART_SYS_MANCHESTER_ENCODING               (0)
#define UC1_1_UART_SYS_FIFO_LENGTH                       (16)
#define UC1_1_UART_SYS_RX_TIMEOUT                        (1)
#define UC1_1_UART_SYS_DMA                               (1)
#define UC1_1_UART_SYS_EXTERNAL_DIRECTION                (1)

#define UC12_UART_SYS_GLITCH_FILTER                      (0)
#define UC12_UART_SYS_HW_FLOW_CONTROL                    (1)
#define UC12_UART_SYS_9_BIT                              (1)
#define UC12_UART_SYS_RS485                              (1)
#define UC12_UART_SYS_LIN                                (1)
#define UC12_UART_SYS_DALI                               (1)
#define UC12_UART_SYS_IRDA                               (1)
#define UC12_UART_SYS_SMART_CARD                         (1)
#define UC12_UART_SYS_IDLE_LINE                          (1)
#define UC12_UART_SYS_MANCHESTER_ENCODING                (1)
#define UC12_UART_SYS_FIFO_LENGTH                        (4)
#define UC12_UART_SYS_RX_TIMEOUT                         (1)
#define UC12_UART_SYS_DMA                                (1)
#define UC12_UART_SYS_EXTERNAL_DIRECTION                 (1)

#define UC13_0_UART_SYS_GLITCH_FILTER                    (0)
#define UC13_0_UART_SYS_HW_FLOW_CONTROL                  (1)
#define UC13_0_UART_SYS_9_BIT                            (1)
#define UC13_0_UART_SYS_RS485                            (1)
#define UC13_0_UART_SYS_LIN                              (0)
#define UC13_0_UART_SYS_DALI                             (1)
#define UC13_0_UART_SYS_IRDA                             (0)
#define UC13_0_UART_SYS_SMART_CARD                       (1)
#define UC13_0_UART_SYS_IDLE_LINE                        (1)
#define UC13_0_UART_SYS_MANCHESTER_ENCODING              (0)
#define UC13_0_UART_SYS_FIFO_LENGTH                      (4)
#define UC13_0_UART_SYS_RX_TIMEOUT                       (1)
#define UC13_0_UART_SYS_DMA                              (1)
#define UC13_0_UART_SYS_EXTERNAL_DIRECTION               (1)

#define UC13_1_UART_SYS_GLITCH_FILTER                    (0)
#define UC13_1_UART_SYS_HW_FLOW_CONTROL                  (1)
#define UC13_1_UART_SYS_9_BIT                            (1)
#define UC13_1_UART_SYS_RS485                            (1)
#define UC13_1_UART_SYS_LIN                              (0)
#define UC13_1_UART_SYS_DALI                             (0)
#define UC13_1_UART_SYS_IRDA                             (0)
#define UC13_1_UART_SYS_SMART_CARD                       (1)
#define UC13_1_UART_SYS_IDLE_LINE                        (1)
#define UC13_1_UART_SYS_MANCHESTER_ENCODING              (0)
#define UC13_1_UART_SYS_FIFO_LENGTH                      (4)
#define UC13_1_UART_SYS_RX_TIMEOUT                       (1)
#define UC13_1_UART_SYS_DMA                              (1)
#define UC13_1_UART_SYS_EXTERNAL_DIRECTION               (1)

#define UC13_2_UART_SYS_GLITCH_FILTER                    (0)
#define UC13_2_UART_SYS_HW_FLOW_CONTROL                  (1)
#define UC13_2_UART_SYS_9_BIT                            (1)
#define UC13_2_UART_SYS_RS485                            (1)
#define UC13_2_UART_SYS_LIN                              (0)
#define UC13_2_UART_SYS_DALI                             (0)
#define UC13_2_UART_SYS_IRDA                             (0)
#define UC13_2_UART_SYS_SMART_CARD                       (1)
#define UC13_2_UART_SYS_IDLE_LINE                        (1)
#define UC13_2_UART_SYS_MANCHESTER_ENCODING              (0)
#define UC13_2_UART_SYS_FIFO_LENGTH                      (4)
#define UC13_2_UART_SYS_RX_TIMEOUT                       (1)
#define UC13_2_UART_SYS_DMA                              (1)
#define UC13_2_UART_SYS_EXTERNAL_DIRECTION               (1)

#define UC13_3_UART_SYS_GLITCH_FILTER                    (0)
#define UC13_3_UART_SYS_HW_FLOW_CONTROL                  (1)
#define UC13_3_UART_SYS_9_BIT                            (1)
#define UC13_3_UART_SYS_RS485                            (1)
#define UC13_3_UART_SYS_LIN                              (0)
#define UC13_3_UART_SYS_DALI                             (0)
#define UC13_3_UART_SYS_IRDA                             (0)
#define UC13_3_UART_SYS_SMART_CARD                       (1)
#define UC13_3_UART_SYS_IDLE_LINE                        (1)
#define UC13_3_UART_SYS_MANCHESTER_ENCODING              (0)
#define UC13_3_UART_SYS_FIFO_LENGTH                      (4)
#define UC13_3_UART_SYS_RX_TIMEOUT                       (1)
#define UC13_3_UART_SYS_DMA                              (1)
#define UC13_3_UART_SYS_EXTERNAL_DIRECTION               (1)

#define UC14_UART_SYS_GLITCH_FILTER                      (0)
#define UC14_UART_SYS_HW_FLOW_CONTROL                    (1)
#define UC14_UART_SYS_9_BIT                              (1)
#define UC14_UART_SYS_RS485                              (1)
#define UC14_UART_SYS_LIN                                (1)
#define UC14_UART_SYS_DALI                               (0)
#define UC14_UART_SYS_IRDA                               (0)
#define UC14_UART_SYS_SMART_CARD                         (0)
#define UC14_UART_SYS_IDLE_LINE                          (1)
#define UC14_UART_SYS_MANCHESTER_ENCODING                (0)
#define UC14_UART_SYS_FIFO_LENGTH                        (4)
#define UC14_UART_SYS_RX_TIMEOUT                         (1)
#define UC14_UART_SYS_DMA                                (1)
#define UC14_UART_SYS_EXTERNAL_DIRECTION                 (1)

#define UC2_SPI_SYS_EN_REPEAT                            (1)
#define UC2_SPI_SYS_EN_RTOUT                             (1)
#define UC2_SPI_SYS_EN_COMMAND_DATA                      (1)
#define UC2_SPI_SYS_EN_CS_CTL                            (1)
#define UC2_SPI_SYS_EN_PACKING                           (1)
#define UC2_SPI_SYS_EN_FENTRIES                          (1)
#define UC2_SPI_SYS_EN_DMA                               (1)
#define UC2_SPI_SYS_EN_CLKDIV                            (1)

#define UC13_0_SPI_SYS_EN_REPEAT                         (0)
#define UC13_0_SPI_SYS_EN_RTOUT                          (0)
#define UC13_0_SPI_SYS_EN_COMMAND_DATA                   (0)
#define UC13_0_SPI_SYS_EN_CS_CTL                         (0)
#define UC13_0_SPI_SYS_EN_PACKING                        (1)
#define UC13_0_SPI_SYS_EN_FENTRIES                       (1)
#define UC13_0_SPI_SYS_EN_DMA                            (1)
#define UC13_0_SPI_SYS_EN_CLKDIV                         (1)

#define UC13_1_SPI_SYS_EN_REPEAT                         (0)
#define UC13_1_SPI_SYS_EN_RTOUT                          (0)
#define UC13_1_SPI_SYS_EN_COMMAND_DATA                   (0)
#define UC13_1_SPI_SYS_EN_CS_CTL                         (0)
#define UC13_1_SPI_SYS_EN_PACKING                        (1)
#define UC13_1_SPI_SYS_EN_FENTRIES                       (1)
#define UC13_1_SPI_SYS_EN_DMA                            (1)
#define UC13_1_SPI_SYS_EN_CLKDIV                         (1)

#define UC13_2_SPI_SYS_EN_REPEAT                         (0)
#define UC13_2_SPI_SYS_EN_RTOUT                          (0)
#define UC13_2_SPI_SYS_EN_COMMAND_DATA                   (0)
#define UC13_2_SPI_SYS_EN_CS_CTL                         (0)
#define UC13_2_SPI_SYS_EN_PACKING                        (1)
#define UC13_2_SPI_SYS_EN_FENTRIES                       (1)
#define UC13_2_SPI_SYS_EN_DMA                            (1)
#define UC13_2_SPI_SYS_EN_CLKDIV                         (1)

#define UC13_3_SPI_SYS_EN_REPEAT                         (0)
#define UC13_3_SPI_SYS_EN_RTOUT                          (0)
#define UC13_3_SPI_SYS_EN_COMMAND_DATA                   (0)
#define UC13_3_SPI_SYS_EN_CS_CTL                         (0)
#define UC13_3_SPI_SYS_EN_PACKING                        (1)
#define UC13_3_SPI_SYS_EN_FENTRIES                       (1)
#define UC13_3_SPI_SYS_EN_DMA                            (1)
#define UC13_3_SPI_SYS_EN_CLKDIV                         (1)

/* ── I2CC per-instance capability macros ─────────────────────────────────── */

#define UC1_0_I2CC_SYS_ANALOG_GLITCH_FILTER             (1)
#define UC1_0_I2CC_SYS_DIGITAL_GLITCH_FILTER            (0)
#define UC1_0_I2CC_SYS_BURST_MODE                       (1)
#define UC1_0_I2CC_SYS_SMBUS                            (1)

#define UC1_1_I2CC_SYS_ANALOG_GLITCH_FILTER             (1)
#define UC1_1_I2CC_SYS_DIGITAL_GLITCH_FILTER            (0)
#define UC1_1_I2CC_SYS_BURST_MODE                       (1)
#define UC1_1_I2CC_SYS_SMBUS                            (1)

#define UC15_0_I2CC_SYS_ANALOG_GLITCH_FILTER            (1)
#define UC15_0_I2CC_SYS_DIGITAL_GLITCH_FILTER           (0)
#define UC15_0_I2CC_SYS_BURST_MODE                      (1)
#define UC15_0_I2CC_SYS_SMBUS                           (1)

#define UC15_1_I2CC_SYS_ANALOG_GLITCH_FILTER            (1)
#define UC15_1_I2CC_SYS_DIGITAL_GLITCH_FILTER           (0)
#define UC15_1_I2CC_SYS_BURST_MODE                      (1)
#define UC15_1_I2CC_SYS_SMBUS                           (1)

#define UC13_0_I2CC_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_0_I2CC_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_0_I2CC_SYS_BURST_MODE                      (0)
#define UC13_0_I2CC_SYS_SMBUS                           (0)

#define UC13_1_I2CC_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_1_I2CC_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_1_I2CC_SYS_BURST_MODE                      (0)
#define UC13_1_I2CC_SYS_SMBUS                           (0)

#define UC13_2_I2CC_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_2_I2CC_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_2_I2CC_SYS_BURST_MODE                      (0)
#define UC13_2_I2CC_SYS_SMBUS                           (0)

#define UC13_3_I2CC_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_3_I2CC_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_3_I2CC_SYS_BURST_MODE                      (0)
#define UC13_3_I2CC_SYS_SMBUS                           (0)

#define UC14_I2CC_SYS_ANALOG_GLITCH_FILTER              (1)
#define UC14_I2CC_SYS_DIGITAL_GLITCH_FILTER             (0)
#define UC14_I2CC_SYS_BURST_MODE                        (1)
#define UC14_I2CC_SYS_SMBUS                             (1)

/* ── I2CT per-instance capability macros ─────────────────────────────────── */

#define UC1_0_I2CT_SYS_ANALOG_GLITCH_FILTER             (1)
#define UC1_0_I2CT_SYS_DIGITAL_GLITCH_FILTER            (0)
#define UC1_0_I2CT_SYS_OAR2                             (1)
#define UC1_0_I2CT_SYS_SMBUS                            (1)
#define UC1_0_I2CT_SYS_WAKEUP                           (1)

#define UC1_1_I2CT_SYS_ANALOG_GLITCH_FILTER             (1)
#define UC1_1_I2CT_SYS_DIGITAL_GLITCH_FILTER            (0)
#define UC1_1_I2CT_SYS_OAR2                             (1)
#define UC1_1_I2CT_SYS_SMBUS                            (1)
#define UC1_1_I2CT_SYS_WAKEUP                           (1)

#define UC15_0_I2CT_SYS_ANALOG_GLITCH_FILTER            (1)
#define UC15_0_I2CT_SYS_DIGITAL_GLITCH_FILTER           (0)
#define UC15_0_I2CT_SYS_OAR2                            (1)
#define UC15_0_I2CT_SYS_SMBUS                           (1)
#define UC15_0_I2CT_SYS_WAKEUP                          (0)

#define UC15_1_I2CT_SYS_ANALOG_GLITCH_FILTER            (1)
#define UC15_1_I2CT_SYS_DIGITAL_GLITCH_FILTER           (0)
#define UC15_1_I2CT_SYS_OAR2                            (1)
#define UC15_1_I2CT_SYS_SMBUS                           (1)
#define UC15_1_I2CT_SYS_WAKEUP                          (0)

#define UC13_0_I2CT_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_0_I2CT_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_0_I2CT_SYS_OAR2                            (0)
#define UC13_0_I2CT_SYS_SMBUS                           (0)
#define UC13_0_I2CT_SYS_WAKEUP                          (1)

#define UC13_1_I2CT_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_1_I2CT_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_1_I2CT_SYS_OAR2                            (0)
#define UC13_1_I2CT_SYS_SMBUS                           (0)
#define UC13_1_I2CT_SYS_WAKEUP                          (1)

#define UC13_2_I2CT_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_2_I2CT_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_2_I2CT_SYS_OAR2                            (0)
#define UC13_2_I2CT_SYS_SMBUS                           (0)
#define UC13_2_I2CT_SYS_WAKEUP                          (1)

#define UC13_3_I2CT_SYS_ANALOG_GLITCH_FILTER            (0)
#define UC13_3_I2CT_SYS_DIGITAL_GLITCH_FILTER           (1)
#define UC13_3_I2CT_SYS_OAR2                            (0)
#define UC13_3_I2CT_SYS_SMBUS                           (0)
#define UC13_3_I2CT_SYS_WAKEUP                          (1)

#define UC14_I2CT_SYS_ANALOG_GLITCH_FILTER              (1)
#define UC14_I2CT_SYS_DIGITAL_GLITCH_FILTER             (0)
#define UC14_I2CT_SYS_OAR2                              (1)
#define UC14_I2CT_SYS_SMBUS                             (1)
#define UC14_I2CT_SYS_WAKEUP                            (0)

/******************************************************************************
 * DMA Triggers                                                                *
 ******************************************************************************/

/* External DMA0 Triggers */
#define DMA0_SOFTWARE_TRIG       (0)
#define DMA0_GENERIC_SUB0_TRIG   (1)
#define DMA0_GENERIC_SUB1_TRIG   (2)
#define DMA0_AESADV_AES_0_TRIG (3)
#define DMA0_AESADV_AES_1_TRIG (4)
#define DMA0_ADC0_TRIG1          (5)
#define DMA0_ADC0_TRIG2          (6)
#define DMA0_ADC0_TRIG3          (7)
#define DMA0_ADC0_TRIG4          (8)
#define DMA0_ADC1_TRIG1          (9)
#define DMA0_ADC1_TRIG2          (10)
#define DMA0_ADC1_TRIG3          (11)
#define DMA0_ADC1_TRIG4          (12)
#define DMA0_SHAW_TRIG           (13)
#define DMA0_I2S0_RX_TRIG        (14)
#define DMA0_I2S0_TX_TRIG        (15)
#define DMA0_I2S1_RX_TRIG        (16)
#define DMA0_I2S1_TX_TRIG        (17)
#define DMA0_QSPI_RX_TRIG        (18)
#define DMA0_QSPI_TX_TRIG        (19)
#define DMA0_UC1_0_TX_TRIG         (20)
#define DMA0_UC1_0_RX_TRIG         (21)
#define DMA0_UC1_1_TX_TRIG         (22)
#define DMA0_UC1_1_RX_TRIG         (23)
#define DMA0_UC2_TX_TRIG         (24)
#define DMA0_UC2_RX_TRIG         (25)
#define DMA0_UC15_0_TX_TRIG         (26)
#define DMA0_UC15_0_RX_TRIG         (27)
#define DMA0_UC15_1_TX_TRIG         (28)
#define DMA0_UC15_1_RX_TRIG         (29)
#define DMA0_UC12_TX_TRIG         (30)
#define DMA0_UC12_RX_TRIG         (31)
#define DMA0_UC13_0_TX_TRIG         (32)
#define DMA0_UC13_0_RX_TRIG         (33)
#define DMA0_UC13_1_TX_TRIG         (34)
#define DMA0_UC13_1_RX_TRIG         (35)
#define DMA0_UC13_2_TX_TRIG         (36)
#define DMA0_UC13_2_RX_TRIG         (37)
#define DMA0_UC13_3_TX_TRIG         (38)
#define DMA0_UC13_3_RX_TRIG         (39)
#define DMA0_UC14_TX_TRIG        (40)
#define DMA0_UC14_RX_TRIG        (41)

/* External DMA1 Triggers */
#define DMA1_SOFTWARE_TRIG       (0)
#define DMA1_GENERIC_SUB0_TRIG   (1)
#define DMA1_GENERIC_SUB1_TRIG   (2)
#define DMA1_AESADV_AES_0_TRIG (3)
#define DMA1_AESADV_AES_1_TRIG (4)
#define DMA1_ADC0_TRIG1          (5)
#define DMA1_ADC0_TRIG2          (6)
#define DMA1_ADC0_TRIG3          (7)
#define DMA1_ADC0_TRIG4          (8)
#define DMA1_ADC1_TRIG1          (9)
#define DMA1_ADC1_TRIG2          (10)
#define DMA1_ADC1_TRIG3          (11)
#define DMA1_ADC1_TRIG4          (12)
#define DMA1_SHAW_TRIG           (13)
#define DMA1_I2S0_RX_TRIG        (14)
#define DMA1_I2S0_TX_TRIG        (15)
#define DMA1_I2S1_RX_TRIG        (16)
#define DMA1_I2S1_TX_TRIG        (17)
#define DMA1_QSPI_RX_TRIG        (18)
#define DMA1_QSPI_TX_TRIG        (19)
#define DMA1_UC1_0_TX_TRIG         (20)
#define DMA1_UC1_0_RX_TRIG         (21)
#define DMA1_UC1_1_TX_TRIG         (22)
#define DMA1_UC1_1_RX_TRIG         (23)
#define DMA1_UC2_TX_TRIG         (24)
#define DMA1_UC2_RX_TRIG         (25)
#define DMA1_UC15_0_TX_TRIG         (26)
#define DMA1_UC15_0_RX_TRIG         (27)
#define DMA1_UC15_1_TX_TRIG         (28)
#define DMA1_UC15_1_RX_TRIG         (29)
#define DMA1_UC12_TX_TRIG         (30)
#define DMA1_UC12_RX_TRIG         (31)
#define DMA1_UC13_0_TX_TRIG         (32)
#define DMA1_UC13_0_RX_TRIG         (33)
#define DMA1_UC13_1_TX_TRIG         (34)
#define DMA1_UC13_1_RX_TRIG         (35)
#define DMA1_UC13_2_TX_TRIG         (36)
#define DMA1_UC13_2_RX_TRIG         (37)
#define DMA1_UC13_3_TX_TRIG         (38)
#define DMA1_UC13_3_RX_TRIG         (39)
#define DMA1_UC14_TX_TRIG        (40)
#define DMA1_UC14_RX_TRIG        (41)
/* Internal DMA0 Triggers */
#define DMA0_CH_0_TRIG (0)
#define DMA0_CH_1_TRIG (1)
#define DMA0_CH_2_TRIG (2)
#define DMA0_CH_3_TRIG (3)

/* Internal DMA1 Triggers */
#define DMA1_CH_0_TRIG  (0)
#define DMA1_CH_1_TRIG  (1)
#define DMA1_CH_2_TRIG  (2)
#define DMA1_CH_3_TRIG  (3)
#define DMA1_CH_4_TRIG  (4)
#define DMA1_CH_5_TRIG  (5)
#define DMA1_CH_6_TRIG  (6)
#define DMA1_CH_7_TRIG  (7)
#define DMA1_CH_8_TRIG  (8)
#define DMA1_CH_9_TRIG  (9)
#define DMA1_CH_10_TRIG (10)
#define DMA1_CH_11_TRIG (11)

/******************************************************************************
 * IOMUX Pin Definitions                                                       *
 ******************************************************************************/

typedef enum IOMUX_PINCM {
    IOMUX_PINCM1  = (0),
    IOMUX_PINCM2  = (1),
    IOMUX_PINCM3  = (2),
    IOMUX_PINCM4  = (3),
    IOMUX_PINCM5  = (4),
    IOMUX_PINCM7  = (6),
    IOMUX_PINCM8  = (7),
    IOMUX_PINCM9  = (8),
    IOMUX_PINCM10 = (9),
    IOMUX_PINCM11 = (10),
    IOMUX_PINCM12 = (11),
    IOMUX_PINCM13 = (12),
    IOMUX_PINCM14 = (13),
    IOMUX_PINCM15 = (14),
    IOMUX_PINCM16 = (15),
    IOMUX_PINCM17 = (16),
    IOMUX_PINCM18 = (17),
    IOMUX_PINCM19 = (18),
    IOMUX_PINCM20 = (19),
    IOMUX_PINCM21 = (20),
    IOMUX_PINCM22 = (21),
    IOMUX_PINCM23 = (22),
    IOMUX_PINCM24 = (23),
    IOMUX_PINCM25 = (24),
    IOMUX_PINCM26 = (25),
    IOMUX_PINCM27 = (26),
    IOMUX_PINCM28 = (27),
    IOMUX_PINCM29 = (28),
    IOMUX_PINCM30 = (29),
    IOMUX_PINCM31 = (30),
    IOMUX_PINCM32 = (31),
    IOMUX_PINCM33 = (32),
    IOMUX_PINCM34 = (33),
    IOMUX_PINCM35 = (34),
    IOMUX_PINCM36 = (35),
    IOMUX_PINCM37 = (36),
    IOMUX_PINCM38 = (37),
    IOMUX_PINCM39 = (38),
    IOMUX_PINCM40 = (39),
    IOMUX_PINCM41 = (40),
    IOMUX_PINCM42 = (41),
    IOMUX_PINCM43 = (42),
    IOMUX_PINCM44 = (43),
    IOMUX_PINCM45 = (44),
    IOMUX_PINCM46 = (45),
    IOMUX_PINCM47 = (46),
    IOMUX_PINCM48 = (47),
    IOMUX_PINCM49 = (48),
    IOMUX_PINCM50 = (49),
    IOMUX_PINCM51 = (50),
    IOMUX_PINCM52 = (51),
    IOMUX_PINCM53 = (52),
    IOMUX_PINCM54 = (53),
    IOMUX_PINCM55 = (54),
    IOMUX_PINCM56 = (55),
    IOMUX_PINCM57 = (56),
    IOMUX_PINCM58 = (57),
    IOMUX_PINCM59 = (58),
    IOMUX_PINCM60 = (59),
    IOMUX_PINCM61 = (60),
    IOMUX_PINCM62 = (61),
    IOMUX_PINCM63 = (62),
    IOMUX_PINCM64 = (63),
    IOMUX_PINCM65 = (64),
    IOMUX_PINCM66 = (65),
    IOMUX_PINCM67 = (66),
    IOMUX_PINCM68 = (67),
    IOMUX_PINCM69 = (68),
    IOMUX_PINCM70 = (69),
    IOMUX_PINCM71 = (70),
    IOMUX_PINCM72 = (71),
    IOMUX_PINCM73 = (72),
    IOMUX_PINCM74 = (73),
    IOMUX_PINCM75 = (74),
    IOMUX_PINCM76 = (75),
    IOMUX_PINCM77 = (76),
    IOMUX_PINCM78 = (77),
    IOMUX_PINCM79 = (78),
    IOMUX_PINCM80 = (79),
    IOMUX_PINCM81 = (80),
    IOMUX_PINCM82 = (81),
    IOMUX_PINCM83 = (82),
    IOMUX_PINCM84 = (83),
    IOMUX_PINCM85 = (84),
    IOMUX_PINCM86 = (85),
    IOMUX_PINCM87 = (86),
    IOMUX_PINCM88 = (87),
    IOMUX_PINCM89 = (88),
    IOMUX_PINCM90 = (89),
    IOMUX_PINCM91 = (90),
    IOMUX_PINCM92 = (91),
    IOMUX_PINCM93 = (92),
    IOMUX_PINCM94 = (93),
} IOMUX_PINCM;

/* IOMUX_PINCM1[PF] Bits */
#define IOMUX_PINCM1_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM1_PF_GPIOA_DIO00                   ((uint32_t)0X00000001)
#define IOMUX_PINCM1_PF_TIMA_0_FAULT1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM1_PF_UC1_0_SDA                     ((uint32_t)0X00000003)
#define IOMUX_PINCM1_PF_UC1_0_TX                      ((uint32_t)0X00000003)
#define IOMUX_PINCM1_PF_UC13_3_SCLK                   ((uint32_t)0X00000004)
#define IOMUX_PINCM1_PF_UC13_3_SCL                    ((uint32_t)0X00000004)
#define IOMUX_PINCM1_PF_UC13_3_RX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM1_PF_UC12_TX                       ((uint32_t)0X00000005)
#define IOMUX_PINCM1_PF_UC15_0_SDA                    ((uint32_t)0X00000006)

/* IOMUX_PINCM2[PF] Bits */
#define IOMUX_PINCM2_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM2_PF_GPIOA_DIO01                   ((uint32_t)0X00000001)
#define IOMUX_PINCM2_PF_TIMA_1_FAULT0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM2_PF_UC1_0_SCL                     ((uint32_t)0X00000003)
#define IOMUX_PINCM2_PF_UC1_0_RX                      ((uint32_t)0X00000003)
#define IOMUX_PINCM2_PF_UC13_3_PICO                   ((uint32_t)0X00000004)
#define IOMUX_PINCM2_PF_UC13_3_SDA                    ((uint32_t)0X00000004)
#define IOMUX_PINCM2_PF_UC13_3_TX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM2_PF_UC12_RX                       ((uint32_t)0X00000005)
#define IOMUX_PINCM2_PF_UC15_0_SCL                    ((uint32_t)0X00000006)
#define IOMUX_PINCM2_PF_TIMG8_0_IDX                   ((uint32_t)0X00000007)
#define IOMUX_PINCM2_PF_TIMA0_0_CCP1                  ((uint32_t)0X00000008)

/* IOMUX_PINCM3[PF] Bits */
#define IOMUX_PINCM3_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM3_PF_GPIOA_DIO28                   ((uint32_t)0X00000001)
#define IOMUX_PINCM3_PF_TIMA_0_FAULT0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM3_PF_UC1_0_SDA                     ((uint32_t)0X00000003)
#define IOMUX_PINCM3_PF_UC1_0_TX                      ((uint32_t)0X00000003)
#define IOMUX_PINCM3_PF_UC13_3_CS0                    ((uint32_t)0X00000004)
#define IOMUX_PINCM3_PF_UC13_3_CTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM3_PF_UC12_TX                       ((uint32_t)0X00000005)
#define IOMUX_PINCM3_PF_UC15_0_SDA                    ((uint32_t)0X00000006)

/* IOMUX_PINCM4[PF] Bits */
#define IOMUX_PINCM4_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM4_PF_GPIOA_DIO29                   ((uint32_t)0X00000001)
#define IOMUX_PINCM4_PF_TIMG4_2_CCP0                  ((uint32_t)0X00000002)
#define IOMUX_PINCM4_PF_TIMA_1_FAULT1                 ((uint32_t)0X00000003)
#define IOMUX_PINCM4_PF_UC13_3_POCI                   ((uint32_t)0X00000004)
#define IOMUX_PINCM4_PF_UC13_3_RTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM4_PF_UC12_RTS                      ((uint32_t)0X00000005)
#define IOMUX_PINCM4_PF_UC1_1_SCL                     ((uint32_t)0X00000006)
#define IOMUX_PINCM4_PF_UC1_1_RX                      ((uint32_t)0X00000006)
#define IOMUX_PINCM4_PF_UC15_1_SCL                    ((uint32_t)0X00000007)

/* IOMUX_PINCM5[PF] Bits */
#define IOMUX_PINCM5_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM5_PF_GPIOA_DIO30                   ((uint32_t)0X00000001)
#define IOMUX_PINCM5_PF_TIMG4_2_CCP1                  ((uint32_t)0X00000002)
#define IOMUX_PINCM5_PF_TIMA_0_FAULT2                 ((uint32_t)0X00000003)
#define IOMUX_PINCM5_PF_UC12_CTS                      ((uint32_t)0X00000005)
#define IOMUX_PINCM5_PF_UC1_1_SDA                     ((uint32_t)0X00000006)
#define IOMUX_PINCM5_PF_UC1_1_TX                      ((uint32_t)0X00000006)
#define IOMUX_PINCM5_PF_UC15_1_SDA                    ((uint32_t)0X00000007)

/* IOMUX_PINCM7[PF] Bits */
#define IOMUX_PINCM7_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM7_PF_GPIOA_DIO02                   ((uint32_t)0X00000001)
#define IOMUX_PINCM7_PF_TIMG8_0_CCP1                  ((uint32_t)0X00000002)
#define IOMUX_PINCM7_PF_TIMA0_0_CCP1                  ((uint32_t)0X00000003)
#define IOMUX_PINCM7_PF_UC12_RX                       ((uint32_t)0X00000004)
#define IOMUX_PINCM7_PF_UC2_CS0                       ((uint32_t)0X00000005)
#define IOMUX_PINCM7_PF_UC13_1_POCI                   ((uint32_t)0X00000006)
#define IOMUX_PINCM7_PF_UC13_1_RTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM7_PF_UC13_3_POCI                   ((uint32_t)0X00000007)
#define IOMUX_PINCM7_PF_UC13_3_RTS                    ((uint32_t)0X00000007)

/* IOMUX_PINCM8[PF] Bits */
#define IOMUX_PINCM8_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM8_PF_GPIOA_DIO03                   ((uint32_t)0X00000001)
#define IOMUX_PINCM8_PF_TIMG8_0_CCP0                  ((uint32_t)0X00000002)
#define IOMUX_PINCM8_PF_TIMA0_0_CCP1                  ((uint32_t)0X00000003)
#define IOMUX_PINCM8_PF_UC1_1_SDA                     ((uint32_t)0X00000004)
#define IOMUX_PINCM8_PF_UC1_1_TX                      ((uint32_t)0X00000004)
#define IOMUX_PINCM8_PF_UC2_CS1                       ((uint32_t)0X00000005)
#define IOMUX_PINCM8_PF_COMP1_OUT                     ((uint32_t)0X00000006)
#define IOMUX_PINCM8_PF_UC15_1_SDA                    ((uint32_t)0X00000007)

/* IOMUX_PINCM9[PF] Bits */
#define IOMUX_PINCM9_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM9_PF_GPIOA_DIO04                   ((uint32_t)0X00000001)
#define IOMUX_PINCM9_PF_SYSCTL_LFCLKIN                ((uint32_t)0X00000002)
#define IOMUX_PINCM9_PF_TIMA0_0_CCP1_CMPL             ((uint32_t)0X00000003)
#define IOMUX_PINCM9_PF_UC1_1_SCL                     ((uint32_t)0X00000004)
#define IOMUX_PINCM9_PF_UC1_1_RX                      ((uint32_t)0X00000004)
#define IOMUX_PINCM9_PF_UC2_POCI                      ((uint32_t)0X00000005)
#define IOMUX_PINCM9_PF_UC13_1_CS0                    ((uint32_t)0X00000006)
#define IOMUX_PINCM9_PF_UC13_1_CTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM9_PF_UC15_1_SCL                    ((uint32_t)0X00000007)

/* IOMUX_PINCM10[PF] Bits */
#define IOMUX_PINCM10_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM10_PF_GPIOA_DIO05                  ((uint32_t)0X00000001)
#define IOMUX_PINCM10_PF_TIMG4_2_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM10_PF_TIMG4_0_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM10_PF_UC2_PICO                     ((uint32_t)0X00000005)

/* IOMUX_PINCM11[PF] Bits */
#define IOMUX_PINCM11_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM11_PF_GPIOA_DIO06                  ((uint32_t)0X00000001)
#define IOMUX_PINCM11_PF_TIMG4_2_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM11_PF_SYSCTL_HFCLKIN               ((uint32_t)0X00000003)
#define IOMUX_PINCM11_PF_TIMA0_0_CCP2_CMPL            ((uint32_t)0X00000004)
#define IOMUX_PINCM11_PF_UC2_SCLK                     ((uint32_t)0X00000005)
#define IOMUX_PINCM11_PF_TIMG4_0_CCP1                 ((uint32_t)0X00000006)

/* IOMUX_PINCM12[PF] Bits */
#define IOMUX_PINCM12_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM12_PF_GPIOB_DIO00                  ((uint32_t)0X00000001)
#define IOMUX_PINCM12_PF_UC1_0_SDA                    ((uint32_t)0X00000002)
#define IOMUX_PINCM12_PF_UC1_0_TX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM12_PF_TIMG4_1_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM12_PF_UC12_TX                      ((uint32_t)0X00000004)
#define IOMUX_PINCM12_PF_TIMA0_1_CCP2                 ((uint32_t)0X00000005)

/* IOMUX_PINCM13[PF] Bits */
#define IOMUX_PINCM13_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM13_PF_GPIOB_DIO01                  ((uint32_t)0X00000001)
#define IOMUX_PINCM13_PF_UC1_0_SCL                    ((uint32_t)0X00000002)
#define IOMUX_PINCM13_PF_UC1_0_RX                     ((uint32_t)0X00000002)
#define IOMUX_PINCM13_PF_TIMG4_1_CCP1                 ((uint32_t)0X00000003)
#define IOMUX_PINCM13_PF_UC12_RX                      ((uint32_t)0X00000004)
#define IOMUX_PINCM13_PF_TIMA0_1_CCP2_CMPL            ((uint32_t)0X00000005)

/* IOMUX_PINCM14[PF] Bits */
#define IOMUX_PINCM14_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM14_PF_GPIOA_DIO07                  ((uint32_t)0X00000001)
#define IOMUX_PINCM14_PF_TIMG4_3_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM14_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000003)
#define IOMUX_PINCM14_PF_COMP0_OUT                    ((uint32_t)0X00000004)
#define IOMUX_PINCM14_PF_TIMA0_0_CCP2                 ((uint32_t)0X00000005)
#define IOMUX_PINCM14_PF_I2S0_WCLK                    ((uint32_t)0X00000006)

/* IOMUX_PINCM15[PF] Bits */
#define IOMUX_PINCM15_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM15_PF_GPIOB_DIO02                  ((uint32_t)0X00000001)
#define IOMUX_PINCM15_PF_TIMG4_2_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM15_PF_TIMA0_0_CCP3                 ((uint32_t)0X00000003)
#define IOMUX_PINCM15_PF_UC13_1_CS0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM15_PF_UC13_1_CTS                   ((uint32_t)0X00000004)
#define IOMUX_PINCM15_PF_UC1_1_SCL                    ((uint32_t)0X00000005)
#define IOMUX_PINCM15_PF_UC1_1_RX                     ((uint32_t)0X00000005)
#define IOMUX_PINCM15_PF_UC15_1_SCL                   ((uint32_t)0X00000006)

/* IOMUX_PINCM16[PF] Bits */
#define IOMUX_PINCM16_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM16_PF_GPIOB_DIO03                  ((uint32_t)0X00000001)
#define IOMUX_PINCM16_PF_TIMG4_2_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM16_PF_TIMA0_0_CCP3_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM16_PF_UC13_1_POCI                  ((uint32_t)0X00000004)
#define IOMUX_PINCM16_PF_UC13_1_RTS                   ((uint32_t)0X00000004)
#define IOMUX_PINCM16_PF_UC1_1_SDA                    ((uint32_t)0X00000005)
#define IOMUX_PINCM16_PF_UC1_1_TX                     ((uint32_t)0X00000005)
#define IOMUX_PINCM16_PF_UC15_1_SDA                   ((uint32_t)0X00000006)

/* IOMUX_PINCM17[PF] Bits */
#define IOMUX_PINCM17_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM17_PF_GPIOB_DIO04                  ((uint32_t)0X00000001)
#define IOMUX_PINCM17_PF_TIMA0_0_CCP2                 ((uint32_t)0X00000002)
#define IOMUX_PINCM17_PF_UC1_1_SDA                    ((uint32_t)0X00000003)
#define IOMUX_PINCM17_PF_UC1_1_TX                     ((uint32_t)0X00000003)
#define IOMUX_PINCM17_PF_UC13_0_CS0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM17_PF_UC13_0_CTS                   ((uint32_t)0X00000004)
#define IOMUX_PINCM17_PF_UC13_1_PICO                  ((uint32_t)0X00000005)
#define IOMUX_PINCM17_PF_UC13_1_SDA                   ((uint32_t)0X00000005)
#define IOMUX_PINCM17_PF_UC13_1_TX                    ((uint32_t)0X00000005)

/* IOMUX_PINCM18[PF] Bits */
#define IOMUX_PINCM18_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM18_PF_GPIOB_DIO05                  ((uint32_t)0X00000001)
#define IOMUX_PINCM18_PF_TIMA0_0_CCP2_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM18_PF_UC1_1_SCL                    ((uint32_t)0X00000003)
#define IOMUX_PINCM18_PF_UC1_1_RX                     ((uint32_t)0X00000003)
#define IOMUX_PINCM18_PF_UC13_0_POCI                  ((uint32_t)0X00000004)
#define IOMUX_PINCM18_PF_UC13_0_RTS                   ((uint32_t)0X00000004)
#define IOMUX_PINCM18_PF_UC13_1_POCI                  ((uint32_t)0X00000005)
#define IOMUX_PINCM18_PF_UC13_1_RTS                   ((uint32_t)0X00000005)
#define IOMUX_PINCM18_PF_UC2_POCI                     ((uint32_t)0X00000006)

/* IOMUX_PINCM19[PF] Bits */
#define IOMUX_PINCM19_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM19_PF_GPIOA_DIO08                  ((uint32_t)0X00000001)
#define IOMUX_PINCM19_PF_TIMA0_0_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM19_PF_TIMA0_1_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM19_PF_UC1_0_RTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM19_PF_UC1_1_SDA                    ((uint32_t)0X00000005)
#define IOMUX_PINCM19_PF_UC1_1_TX                     ((uint32_t)0X00000005)
#define IOMUX_PINCM19_PF_UC2_SCLK                     ((uint32_t)0X00000006)
#define IOMUX_PINCM19_PF_UC12_RTS                     ((uint32_t)0X00000007)
#define IOMUX_PINCM19_PF_I2S0_WCLK                    ((uint32_t)0X00000008)

/* IOMUX_PINCM20[PF] Bits */
#define IOMUX_PINCM20_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM20_PF_GPIOA_DIO09                  ((uint32_t)0X00000001)
#define IOMUX_PINCM20_PF_TIMA0_0_CCP0_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM20_PF_LFSS_RTC_OUT                 ((uint32_t)0X00000003)
#define IOMUX_PINCM20_PF_UC1_0_CTS                    ((uint32_t)0X00000004)
#define IOMUX_PINCM20_PF_UC1_1_SCL                    ((uint32_t)0X00000005)
#define IOMUX_PINCM20_PF_UC1_1_RX                     ((uint32_t)0X00000005)
#define IOMUX_PINCM20_PF_UC2_PICO                     ((uint32_t)0X00000006)
#define IOMUX_PINCM20_PF_UC12_CTS                     ((uint32_t)0X00000007)
#define IOMUX_PINCM20_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000008)
#define IOMUX_PINCM20_PF_I2S0_MCLK                    ((uint32_t)0X00000009)
#define IOMUX_PINCM20_PF_DFTSS_TDO                    ((uint32_t)0X0000000A)

/* IOMUX_PINCM21[PF] Bits */
#define IOMUX_PINCM21_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM21_PF_GPIOA_DIO10                  ((uint32_t)0X00000001)
#define IOMUX_PINCM21_PF_TIMG12_0_CCP0                ((uint32_t)0X00000002)
#define IOMUX_PINCM21_PF_TIMA0_0_CCP2                 ((uint32_t)0X00000003)
#define IOMUX_PINCM21_PF_UC1_0_SDA                    ((uint32_t)0X00000004)
#define IOMUX_PINCM21_PF_UC1_0_TX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM21_PF_UC2_POCI                     ((uint32_t)0X00000005)
#define IOMUX_PINCM21_PF_UC15_0_SDA                   ((uint32_t)0X00000006)
#define IOMUX_PINCM21_PF_UC12_TX                      ((uint32_t)0X00000007)
#define IOMUX_PINCM21_PF_UC13_1_SCLK                  ((uint32_t)0X00000008)
#define IOMUX_PINCM21_PF_UC13_1_SCL                   ((uint32_t)0X00000008)
#define IOMUX_PINCM21_PF_UC13_1_RX                    ((uint32_t)0X00000008)

/* IOMUX_PINCM22[PF] Bits */
#define IOMUX_PINCM22_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM22_PF_GPIOA_DIO11                  ((uint32_t)0X00000001)
#define IOMUX_PINCM22_PF_TIMA0_1_CCP0_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM22_PF_TIMA0_0_CCP2_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM22_PF_UC1_0_SCL                    ((uint32_t)0X00000004)
#define IOMUX_PINCM22_PF_UC1_0_RX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM22_PF_UC2_SCLK                     ((uint32_t)0X00000005)
#define IOMUX_PINCM22_PF_UC15_0_SCL                   ((uint32_t)0X00000006)
#define IOMUX_PINCM22_PF_UC12_RX                      ((uint32_t)0X00000007)
#define IOMUX_PINCM22_PF_COMP0_OUT                    ((uint32_t)0X00000008)

/* IOMUX_PINCM23[PF] Bits */
#define IOMUX_PINCM23_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM23_PF_GPIOB_DIO06                  ((uint32_t)0X00000001)
#define IOMUX_PINCM23_PF_TIMG4_2_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM23_PF_TIMA0_1_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM23_PF_I2S1_AD0                     ((uint32_t)0X00000004)
#define IOMUX_PINCM23_PF_UC1_1_SDA                    ((uint32_t)0X00000005)
#define IOMUX_PINCM23_PF_UC1_1_TX                     ((uint32_t)0X00000005)
#define IOMUX_PINCM23_PF_UC12_CTS                     ((uint32_t)0X00000006)
#define IOMUX_PINCM23_PF_UC2_CS1                      ((uint32_t)0X00000007)
#define IOMUX_PINCM23_PF_CANFD1_CANRX                 ((uint32_t)0X00000009)

/* IOMUX_PINCM24[PF] Bits */
#define IOMUX_PINCM24_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM24_PF_GPIOB_DIO07                  ((uint32_t)0X00000001)
#define IOMUX_PINCM24_PF_TIMG4_2_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM24_PF_TIMG8_1_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM24_PF_TIMA0_1_CCP0_CMPL            ((uint32_t)0X00000004)
#define IOMUX_PINCM24_PF_I2S1_AD1                     ((uint32_t)0X00000005)
#define IOMUX_PINCM24_PF_UC1_1_SCL                    ((uint32_t)0X00000006)
#define IOMUX_PINCM24_PF_UC1_1_RX                     ((uint32_t)0X00000006)
#define IOMUX_PINCM24_PF_UC12_RTS                     ((uint32_t)0X00000007)
#define IOMUX_PINCM24_PF_UC13_0_POCI                  ((uint32_t)0X00000008)
#define IOMUX_PINCM24_PF_UC13_0_RTS                   ((uint32_t)0X00000008)
#define IOMUX_PINCM24_PF_CANFD1_CANTX                 ((uint32_t)0X00000009)

/* IOMUX_PINCM25[PF] Bits */
#define IOMUX_PINCM25_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM25_PF_GPIOB_DIO08                  ((uint32_t)0X00000001)
#define IOMUX_PINCM25_PF_TIMG8_1_IDX                  ((uint32_t)0X00000002)
#define IOMUX_PINCM25_PF_COMP1_OUT                    ((uint32_t)0X00000003)
#define IOMUX_PINCM25_PF_TIMA_1_FAULT1                ((uint32_t)0X00000004)
#define IOMUX_PINCM25_PF_I2S1_WCLK                    ((uint32_t)0X00000005)
#define IOMUX_PINCM25_PF_UC1_1_CTS                    ((uint32_t)0X00000006)
#define IOMUX_PINCM25_PF_UC13_0_SCLK                  ((uint32_t)0X00000007)
#define IOMUX_PINCM25_PF_UC13_0_SCL                   ((uint32_t)0X00000007)
#define IOMUX_PINCM25_PF_UC13_0_RX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM25_PF_UC13_0_PICO                  ((uint32_t)0X00000008)
#define IOMUX_PINCM25_PF_UC13_0_SDA                   ((uint32_t)0X00000008)
#define IOMUX_PINCM25_PF_UC13_0_TX                    ((uint32_t)0X00000008)

/* IOMUX_PINCM26[PF] Bits */
#define IOMUX_PINCM26_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM26_PF_GPIOB_DIO09                  ((uint32_t)0X00000001)
#define IOMUX_PINCM26_PF_TIMG8_1_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM26_PF_TIMA0_0_CCP0_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM26_PF_I2S1_BCLK                    ((uint32_t)0X00000004)
#define IOMUX_PINCM26_PF_UC1_1_RTS                    ((uint32_t)0X00000005)
#define IOMUX_PINCM26_PF_UC13_0_PICO                  ((uint32_t)0X00000006)
#define IOMUX_PINCM26_PF_UC13_0_SDA                   ((uint32_t)0X00000006)
#define IOMUX_PINCM26_PF_UC13_0_TX                    ((uint32_t)0X00000006)
#define IOMUX_PINCM26_PF_UC13_0_SCLK                  ((uint32_t)0X00000007)
#define IOMUX_PINCM26_PF_UC13_0_SCL                   ((uint32_t)0X00000007)
#define IOMUX_PINCM26_PF_UC13_0_RX                    ((uint32_t)0X00000007)

/* IOMUX_PINCM27[PF] Bits */
#define IOMUX_PINCM27_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM27_PF_GPIOB_DIO10                  ((uint32_t)0X00000001)
#define IOMUX_PINCM27_PF_TIMG4_2_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM27_PF_TIMG4_0_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM27_PF_I2S1_MCLK                    ((uint32_t)0X00000004)
#define IOMUX_PINCM27_PF_UC13_2_PICO                  ((uint32_t)0X00000005)
#define IOMUX_PINCM27_PF_UC13_2_SDA                   ((uint32_t)0X00000005)
#define IOMUX_PINCM27_PF_UC13_2_TX                    ((uint32_t)0X00000005)
#define IOMUX_PINCM27_PF_TIMA0_1_CCP1                 ((uint32_t)0X00000006)
#define IOMUX_PINCM27_PF_I2S0_WCLK                    ((uint32_t)0X00000008)

/* IOMUX_PINCM28[PF] Bits */
#define IOMUX_PINCM28_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM28_PF_GPIOB_DIO11                  ((uint32_t)0X00000001)
#define IOMUX_PINCM28_PF_TIMG4_2_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM28_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000003)
#define IOMUX_PINCM28_PF_TIMG4_0_CCP1                 ((uint32_t)0X00000004)
#define IOMUX_PINCM28_PF_UC13_2_SCLK                  ((uint32_t)0X00000005)
#define IOMUX_PINCM28_PF_UC13_2_SCL                   ((uint32_t)0X00000005)
#define IOMUX_PINCM28_PF_UC13_2_RX                    ((uint32_t)0X00000005)
#define IOMUX_PINCM28_PF_TIMA0_1_CCP1_CMPL            ((uint32_t)0X00000006)
#define IOMUX_PINCM28_PF_I2S0_BCLK                    ((uint32_t)0X00000008)

/* IOMUX_PINCM29[PF] Bits */
#define IOMUX_PINCM29_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM29_PF_GPIOB_DIO12                  ((uint32_t)0X00000001)
#define IOMUX_PINCM29_PF_TIMA_0_FAULT1                ((uint32_t)0X00000002)
#define IOMUX_PINCM29_PF_UC13_0_PICO                  ((uint32_t)0X00000003)
#define IOMUX_PINCM29_PF_UC13_0_SDA                   ((uint32_t)0X00000003)
#define IOMUX_PINCM29_PF_UC13_0_TX                    ((uint32_t)0X00000003)
#define IOMUX_PINCM29_PF_UC13_2_CS0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM29_PF_UC13_2_CTS                   ((uint32_t)0X00000004)
#define IOMUX_PINCM29_PF_I2S0_AD0                     ((uint32_t)0X00000008)

/* IOMUX_PINCM30[PF] Bits */
#define IOMUX_PINCM30_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM30_PF_GPIOB_DIO13                  ((uint32_t)0X00000001)
#define IOMUX_PINCM30_PF_TIMG12_0_CCP0                ((uint32_t)0X00000002)
#define IOMUX_PINCM30_PF_TIMA0_0_CCP1_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM30_PF_UC13_0_SCLK                  ((uint32_t)0X00000004)
#define IOMUX_PINCM30_PF_UC13_0_SCL                   ((uint32_t)0X00000004)
#define IOMUX_PINCM30_PF_UC13_0_RX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM30_PF_UC13_2_POCI                  ((uint32_t)0X00000005)
#define IOMUX_PINCM30_PF_UC13_2_RTS                   ((uint32_t)0X00000005)
#define IOMUX_PINCM30_PF_QSPI_CS2_POCI2               ((uint32_t)0X00000006)
#define IOMUX_PINCM30_PF_I2S0_AD1                     ((uint32_t)0X00000008)

/* IOMUX_PINCM31[PF] Bits */
#define IOMUX_PINCM31_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM31_PF_GPIOB_DIO14                  ((uint32_t)0X00000001)
#define IOMUX_PINCM31_PF_TIMG8_0_IDX                  ((uint32_t)0X00000002)
#define IOMUX_PINCM31_PF_TIMG12_0_CCP1                ((uint32_t)0X00000003)
#define IOMUX_PINCM31_PF_TIMA0_0_CCP0                 ((uint32_t)0X00000004)
#define IOMUX_PINCM31_PF_QSPI_CS0                     ((uint32_t)0X00000006)
#define IOMUX_PINCM31_PF_UC13_0_POCI                  ((uint32_t)0X00000007)
#define IOMUX_PINCM31_PF_UC13_0_RTS                   ((uint32_t)0X00000007)
#define IOMUX_PINCM31_PF_I2S0_MCLK                    ((uint32_t)0X00000008)

/* IOMUX_PINCM32[PF] Bits */
#define IOMUX_PINCM32_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM32_PF_GPIOB_DIO15                  ((uint32_t)0X00000001)
#define IOMUX_PINCM32_PF_TIMG4_3_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM32_PF_TIMG8_0_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM32_PF_TIMA0_1_CCP3                 ((uint32_t)0X00000004)
#define IOMUX_PINCM32_PF_I2S0_MCLK                    ((uint32_t)0X00000005)
#define IOMUX_PINCM32_PF_QSPI_IO3                     ((uint32_t)0X00000006)
#define IOMUX_PINCM32_PF_UC13_1_PICO                  ((uint32_t)0X00000007)
#define IOMUX_PINCM32_PF_UC13_1_SDA                   ((uint32_t)0X00000007)
#define IOMUX_PINCM32_PF_UC13_1_TX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM32_PF_UC12_TX                      ((uint32_t)0X00000008)

/* IOMUX_PINCM33[PF] Bits */
#define IOMUX_PINCM33_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM33_PF_GPIOB_DIO16                  ((uint32_t)0X00000001)
#define IOMUX_PINCM33_PF_TIMG4_3_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM33_PF_TIMG8_0_CCP1                 ((uint32_t)0X00000003)
#define IOMUX_PINCM33_PF_TIMA0_1_CCP3_CMPL            ((uint32_t)0X00000004)
#define IOMUX_PINCM33_PF_I2S0_WCLK                    ((uint32_t)0X00000005)
#define IOMUX_PINCM33_PF_QSPI_SCLK                    ((uint32_t)0X00000006)
#define IOMUX_PINCM33_PF_UC13_1_SCLK                  ((uint32_t)0X00000007)
#define IOMUX_PINCM33_PF_UC13_1_SCL                   ((uint32_t)0X00000007)
#define IOMUX_PINCM33_PF_UC13_1_RX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM33_PF_UC12_RX                      ((uint32_t)0X00000008)

/* IOMUX_PINCM34[PF] Bits */
#define IOMUX_PINCM34_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM34_PF_GPIOA_DIO12                  ((uint32_t)0X00000001)
#define IOMUX_PINCM34_PF_CANFD0_CANTX                 ((uint32_t)0X00000002)
#define IOMUX_PINCM34_PF_TIMG4_0_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM34_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000004)
#define IOMUX_PINCM34_PF_I2S0_BCLK                    ((uint32_t)0X00000005)
#define IOMUX_PINCM34_PF_QSPI_PICO                    ((uint32_t)0X00000006)
#define IOMUX_PINCM34_PF_UC13_0_CS0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM34_PF_UC13_0_CTS                   ((uint32_t)0X00000007)
#define IOMUX_PINCM34_PF_TIMA0_1_CCP1                 ((uint32_t)0X00000008)

/* IOMUX_PINCM35[PF] Bits */
#define IOMUX_PINCM35_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM35_PF_GPIOA_DIO13                  ((uint32_t)0X00000001)
#define IOMUX_PINCM35_PF_CANFD0_CANRX                 ((uint32_t)0X00000002)
#define IOMUX_PINCM35_PF_TIMG4_0_CCP1                 ((uint32_t)0X00000003)
#define IOMUX_PINCM35_PF_TIMA_1_FAULT1                ((uint32_t)0X00000004)
#define IOMUX_PINCM35_PF_I2S0_AD0                     ((uint32_t)0X00000005)
#define IOMUX_PINCM35_PF_QSPI_IO2                     ((uint32_t)0X00000006)
#define IOMUX_PINCM35_PF_UC13_0_SCLK                  ((uint32_t)0X00000007)
#define IOMUX_PINCM35_PF_UC13_0_SCL                   ((uint32_t)0X00000007)
#define IOMUX_PINCM35_PF_UC13_0_RX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM35_PF_UC13_0_POCI                  ((uint32_t)0X00000008)
#define IOMUX_PINCM35_PF_UC13_0_RTS                   ((uint32_t)0X00000008)
#define IOMUX_PINCM35_PF_UC12_TX                      ((uint32_t)0X00000009)

/* IOMUX_PINCM36[PF] Bits */
#define IOMUX_PINCM36_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM36_PF_GPIOA_DIO14                  ((uint32_t)0X00000001)
#define IOMUX_PINCM36_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000002)
#define IOMUX_PINCM36_PF_TIMA0_1_CCP1_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM36_PF_TIMA0_0_CCP3                 ((uint32_t)0X00000004)
#define IOMUX_PINCM36_PF_I2S0_AD1                     ((uint32_t)0X00000005)
#define IOMUX_PINCM36_PF_QSPI_POCI                    ((uint32_t)0X00000006)
#define IOMUX_PINCM36_PF_UC1_0_CTS                    ((uint32_t)0X00000007)
#define IOMUX_PINCM36_PF_UC13_0_PICO                  ((uint32_t)0X00000008)
#define IOMUX_PINCM36_PF_UC13_0_SDA                   ((uint32_t)0X00000008)
#define IOMUX_PINCM36_PF_UC13_0_TX                    ((uint32_t)0X00000008)
#define IOMUX_PINCM36_PF_UC12_RX                      ((uint32_t)0X00000009)

/* IOMUX_PINCM37[PF] Bits */
#define IOMUX_PINCM37_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM37_PF_GPIOA_DIO15                  ((uint32_t)0X00000001)
#define IOMUX_PINCM37_PF_TIMG8_0_IDX                  ((uint32_t)0X00000002)
#define IOMUX_PINCM37_PF_TIMA0_0_CCP2                 ((uint32_t)0X00000003)
#define IOMUX_PINCM37_PF_UC1_1_SCL                    ((uint32_t)0X00000004)
#define IOMUX_PINCM37_PF_UC1_1_RX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM37_PF_UC15_1_SCL                   ((uint32_t)0X00000006)
#define IOMUX_PINCM37_PF_UC1_0_RTS                    ((uint32_t)0X00000007)
#define IOMUX_PINCM37_PF_I2S0_WCLK                    ((uint32_t)0X00000008)

/* IOMUX_PINCM38[PF] Bits */
#define IOMUX_PINCM38_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM38_PF_GPIOA_DIO16                  ((uint32_t)0X00000001)
#define IOMUX_PINCM38_PF_TIMA0_0_CCP2_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM38_PF_SYSCTL_FCC_IN                ((uint32_t)0X00000003)
#define IOMUX_PINCM38_PF_UC1_1_SDA                    ((uint32_t)0X00000004)
#define IOMUX_PINCM38_PF_UC1_1_TX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM38_PF_UC13_0_POCI                  ((uint32_t)0X00000005)
#define IOMUX_PINCM38_PF_UC13_0_RTS                   ((uint32_t)0X00000005)
#define IOMUX_PINCM38_PF_UC15_1_SDA                   ((uint32_t)0X00000006)
#define IOMUX_PINCM38_PF_QSPI_CS3_CD_POCI3            ((uint32_t)0X00000007)

/* IOMUX_PINCM39[PF] Bits */
#define IOMUX_PINCM39_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM39_PF_GPIOA_DIO17                  ((uint32_t)0X00000001)
#define IOMUX_PINCM39_PF_TIMG4_3_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM39_PF_TIMA0_0_CCP3                 ((uint32_t)0X00000003)
#define IOMUX_PINCM39_PF_UC1_1_SDA                    ((uint32_t)0X00000004)
#define IOMUX_PINCM39_PF_UC1_1_TX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM39_PF_UC13_0_SCLK                  ((uint32_t)0X00000005)
#define IOMUX_PINCM39_PF_UC13_0_SCL                   ((uint32_t)0X00000005)
#define IOMUX_PINCM39_PF_UC13_0_RX                    ((uint32_t)0X00000005)

/* IOMUX_PINCM40[PF] Bits */
#define IOMUX_PINCM40_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM40_PF_GPIOA_DIO18                  ((uint32_t)0X00000001)
#define IOMUX_PINCM40_PF_TIMA0_0_CCP3_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM40_PF_I2S0_WCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM40_PF_UC1_1_SCL                    ((uint32_t)0X00000004)
#define IOMUX_PINCM40_PF_UC1_1_RX                     ((uint32_t)0X00000004)
#define IOMUX_PINCM40_PF_UC13_0_PICO                  ((uint32_t)0X00000005)
#define IOMUX_PINCM40_PF_UC13_0_SDA                   ((uint32_t)0X00000005)
#define IOMUX_PINCM40_PF_UC13_0_TX                    ((uint32_t)0X00000005)
#define IOMUX_PINCM40_PF_UC13_1_CS0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM40_PF_UC13_1_CTS                   ((uint32_t)0X00000006)
#define IOMUX_PINCM40_PF_QSPI_CS1_POCI1               ((uint32_t)0X00000007)

/* IOMUX_PINCM41[PF] Bits */
#define IOMUX_PINCM41_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM41_PF_GPIOA_DIO19                  ((uint32_t)0X00000001)
#define IOMUX_PINCM41_PF_DEBUGSS_SWDIO                ((uint32_t)0X00000002)
#define IOMUX_PINCM41_PF_UC15_0_SDA                   ((uint32_t)0X00000003)
#define IOMUX_PINCM41_PF_UC12_TX                      ((uint32_t)0X00000004)

/* IOMUX_PINCM42[PF] Bits */
#define IOMUX_PINCM42_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM42_PF_GPIOA_DIO20                  ((uint32_t)0X00000001)
#define IOMUX_PINCM42_PF_DEBUGSS_SWCLK                ((uint32_t)0X00000002)
#define IOMUX_PINCM42_PF_UC15_0_SCL                   ((uint32_t)0X00000003)
#define IOMUX_PINCM42_PF_UC12_RX                      ((uint32_t)0X00000004)

/* IOMUX_PINCM43[PF] Bits */
#define IOMUX_PINCM43_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM43_PF_GPIOB_DIO17                  ((uint32_t)0X00000001)
#define IOMUX_PINCM43_PF_TIMA0_0_CCP2                 ((uint32_t)0X00000002)
#define IOMUX_PINCM43_PF_UC13_1_PICO                  ((uint32_t)0X00000003)
#define IOMUX_PINCM43_PF_UC13_1_SDA                   ((uint32_t)0X00000003)
#define IOMUX_PINCM43_PF_UC13_1_TX                    ((uint32_t)0X00000003)
#define IOMUX_PINCM43_PF_UC2_PICO                     ((uint32_t)0X00000004)

/* IOMUX_PINCM44[PF] Bits */
#define IOMUX_PINCM44_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM44_PF_GPIOB_DIO18                  ((uint32_t)0X00000001)
#define IOMUX_PINCM44_PF_TIMA0_0_CCP2_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM44_PF_UC13_1_SCLK                  ((uint32_t)0X00000003)
#define IOMUX_PINCM44_PF_UC13_1_SCL                   ((uint32_t)0X00000003)
#define IOMUX_PINCM44_PF_UC13_1_RX                    ((uint32_t)0X00000003)
#define IOMUX_PINCM44_PF_UC2_SCLK                     ((uint32_t)0X00000004)

/* IOMUX_PINCM45[PF] Bits */
#define IOMUX_PINCM45_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM45_PF_GPIOB_DIO19                  ((uint32_t)0X00000001)
#define IOMUX_PINCM45_PF_TIMG4_3_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM45_PF_TIMA0_1_CCP2                 ((uint32_t)0X00000003)
#define IOMUX_PINCM45_PF_UC2_POCI                     ((uint32_t)0X00000004)
#define IOMUX_PINCM45_PF_UC1_0_CTS                    ((uint32_t)0X00000005)

/* IOMUX_PINCM46[PF] Bits */
#define IOMUX_PINCM46_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM46_PF_GPIOA_DIO21                  ((uint32_t)0X00000001)
#define IOMUX_PINCM46_PF_TIMG4_2_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM46_PF_TIMA0_0_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM46_PF_I2S0_AD0                     ((uint32_t)0X00000004)
#define IOMUX_PINCM46_PF_UC1_1_CTS                    ((uint32_t)0X00000005)
#define IOMUX_PINCM46_PF_UC13_1_PICO                  ((uint32_t)0X00000006)
#define IOMUX_PINCM46_PF_UC13_1_SDA                   ((uint32_t)0X00000006)
#define IOMUX_PINCM46_PF_UC13_1_TX                    ((uint32_t)0X00000006)
#define IOMUX_PINCM46_PF_UC13_2_CS0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM46_PF_UC13_2_CTS                   ((uint32_t)0X00000007)

/* IOMUX_PINCM47[PF] Bits */
#define IOMUX_PINCM47_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM47_PF_GPIOA_DIO22                  ((uint32_t)0X00000001)
#define IOMUX_PINCM47_PF_TIMG4_2_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM47_PF_TIMA0_0_CCP0_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM47_PF_I2S0_BCLK                    ((uint32_t)0X00000004)
#define IOMUX_PINCM47_PF_SYSCTL_CLK_OUT               ((uint32_t)0X00000005)
#define IOMUX_PINCM47_PF_UC13_1_SCLK                  ((uint32_t)0X00000006)
#define IOMUX_PINCM47_PF_UC13_1_SCL                   ((uint32_t)0X00000006)
#define IOMUX_PINCM47_PF_UC13_1_RX                    ((uint32_t)0X00000006)
#define IOMUX_PINCM47_PF_UC13_2_POCI                  ((uint32_t)0X00000007)
#define IOMUX_PINCM47_PF_UC13_2_RTS                   ((uint32_t)0X00000007)
#define IOMUX_PINCM47_PF_UC1_1_RTS                    ((uint32_t)0X00000008)
#define IOMUX_PINCM47_PF_DFTSS_TDI                    ((uint32_t)0X00000009)

/* IOMUX_PINCM48[PF] Bits */
#define IOMUX_PINCM48_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM48_PF_GPIOB_DIO20                  ((uint32_t)0X00000001)
#define IOMUX_PINCM48_PF_TIMG12_0_CCP0                ((uint32_t)0X00000002)
#define IOMUX_PINCM48_PF_TIMA0_0_CCP1                 ((uint32_t)0X00000003)
#define IOMUX_PINCM48_PF_TIMA0_1_CCP2_CMPL            ((uint32_t)0X00000004)
#define IOMUX_PINCM48_PF_I2S1_AD0                     ((uint32_t)0X00000005)
#define IOMUX_PINCM48_PF_UC2_CS2                      ((uint32_t)0X00000006)

/* IOMUX_PINCM49[PF] Bits */
#define IOMUX_PINCM49_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM49_PF_GPIOB_DIO21                  ((uint32_t)0X00000001)
#define IOMUX_PINCM49_PF_TIMG8_0_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM49_PF_CANFD1_CANTX                 ((uint32_t)0X00000003)
#define IOMUX_PINCM49_PF_TIMA0_1_CCP3                 ((uint32_t)0X00000004)
#define IOMUX_PINCM49_PF_I2S1_AD1                     ((uint32_t)0X00000005)
#define IOMUX_PINCM49_PF_UC14_SCL                     ((uint32_t)0X00000006)
#define IOMUX_PINCM49_PF_UC14_RX                      ((uint32_t)0X00000006)

/* IOMUX_PINCM50[PF] Bits */
#define IOMUX_PINCM50_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM50_PF_GPIOB_DIO22                  ((uint32_t)0X00000001)
#define IOMUX_PINCM50_PF_TIMG8_0_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM50_PF_CANFD1_CANRX                 ((uint32_t)0X00000003)
#define IOMUX_PINCM50_PF_TIMA0_1_CCP3_CMPL            ((uint32_t)0X00000004)
#define IOMUX_PINCM50_PF_I2S1_WCLK                    ((uint32_t)0X00000005)
#define IOMUX_PINCM50_PF_UC14_SDA                     ((uint32_t)0X00000006)
#define IOMUX_PINCM50_PF_UC14_TX                      ((uint32_t)0X00000006)
#define IOMUX_PINCM50_PF_UC13_0_PICO                  ((uint32_t)0X00000007)
#define IOMUX_PINCM50_PF_UC13_0_SDA                   ((uint32_t)0X00000007)
#define IOMUX_PINCM50_PF_UC13_0_TX                    ((uint32_t)0X00000007)

/* IOMUX_PINCM51[PF] Bits */
#define IOMUX_PINCM51_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM51_PF_GPIOB_DIO23                  ((uint32_t)0X00000001)
#define IOMUX_PINCM51_PF_TIMG4_1_CCP0                 ((uint32_t)0X00000004)
#define IOMUX_PINCM51_PF_I2S1_BCLK                    ((uint32_t)0X00000005)
#define IOMUX_PINCM51_PF_UC14_CTS                     ((uint32_t)0X00000006)
#define IOMUX_PINCM51_PF_UC13_0_SCLK                  ((uint32_t)0X00000007)
#define IOMUX_PINCM51_PF_UC13_0_SCL                   ((uint32_t)0X00000007)
#define IOMUX_PINCM51_PF_UC13_0_RX                    ((uint32_t)0X00000007)

/* IOMUX_PINCM52[PF] Bits */
#define IOMUX_PINCM52_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM52_PF_GPIOB_DIO24                  ((uint32_t)0X00000001)
#define IOMUX_PINCM52_PF_TIMG12_0_CCP1                ((uint32_t)0X00000002)
#define IOMUX_PINCM52_PF_TIMA_1_FAULT2                ((uint32_t)0X00000003)
#define IOMUX_PINCM52_PF_TIMG4_1_CCP1                 ((uint32_t)0X00000004)
#define IOMUX_PINCM52_PF_I2S1_MCLK                    ((uint32_t)0X00000005)
#define IOMUX_PINCM52_PF_UC14_RTS                     ((uint32_t)0X00000006)
#define IOMUX_PINCM52_PF_UC2_CS3                      ((uint32_t)0X00000007)

/* IOMUX_PINCM53[PF] Bits */
#define IOMUX_PINCM53_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM53_PF_GPIOA_DIO23                  ((uint32_t)0X00000001)
#define IOMUX_PINCM53_PF_TIMA0_0_CCP3                 ((uint32_t)0X00000002)
#define IOMUX_PINCM53_PF_I2S0_WCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM53_PF_UC13_1_PICO                  ((uint32_t)0X00000004)
#define IOMUX_PINCM53_PF_UC13_1_SDA                   ((uint32_t)0X00000004)
#define IOMUX_PINCM53_PF_UC13_1_TX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM53_PF_UC13_0_CS0                   ((uint32_t)0X00000005)
#define IOMUX_PINCM53_PF_UC13_0_CTS                   ((uint32_t)0X00000005)
#define IOMUX_PINCM53_PF_UC2_CS3                      ((uint32_t)0X00000006)
#define IOMUX_PINCM53_PF_UC13_2_SCLK                  ((uint32_t)0X00000007)
#define IOMUX_PINCM53_PF_UC13_2_SCL                   ((uint32_t)0X00000007)
#define IOMUX_PINCM53_PF_UC13_2_RX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM53_PF_TIMG4_0_CCP0                 ((uint32_t)0X00000009)

/* IOMUX_PINCM54[PF] Bits */
#define IOMUX_PINCM54_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM54_PF_GPIOA_DIO24                  ((uint32_t)0X00000001)
#define IOMUX_PINCM54_PF_TIMA0_0_CCP3_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM54_PF_I2S0_AD1                     ((uint32_t)0X00000003)
#define IOMUX_PINCM54_PF_UC13_1_SCLK                  ((uint32_t)0X00000004)
#define IOMUX_PINCM54_PF_UC13_1_SCL                   ((uint32_t)0X00000004)
#define IOMUX_PINCM54_PF_UC13_1_RX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM54_PF_UC13_0_POCI                  ((uint32_t)0X00000005)
#define IOMUX_PINCM54_PF_UC13_0_RTS                   ((uint32_t)0X00000005)
#define IOMUX_PINCM54_PF_UC2_CS2                      ((uint32_t)0X00000006)
#define IOMUX_PINCM54_PF_UC13_2_PICO                  ((uint32_t)0X00000007)
#define IOMUX_PINCM54_PF_UC13_2_SDA                   ((uint32_t)0X00000007)
#define IOMUX_PINCM54_PF_UC13_2_TX                    ((uint32_t)0X00000007)
#define IOMUX_PINCM54_PF_TIMG12_0_CCP1                ((uint32_t)0X00000008)
#define IOMUX_PINCM54_PF_TIMG4_0_CCP1                 ((uint32_t)0X00000009)

/* IOMUX_PINCM55[PF] Bits */
#define IOMUX_PINCM55_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM55_PF_GPIOA_DIO25                  ((uint32_t)0X00000001)
#define IOMUX_PINCM55_PF_TIMA0_0_CCP1_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM55_PF_I2S0_AD0                     ((uint32_t)0X00000003)
#define IOMUX_PINCM55_PF_UC13_0_SCLK                  ((uint32_t)0X00000004)
#define IOMUX_PINCM55_PF_UC13_0_SCL                   ((uint32_t)0X00000004)
#define IOMUX_PINCM55_PF_UC13_0_RX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM55_PF_UC13_3_SCLK                  ((uint32_t)0X00000005)
#define IOMUX_PINCM55_PF_UC13_3_SCL                   ((uint32_t)0X00000005)
#define IOMUX_PINCM55_PF_UC13_3_RX                    ((uint32_t)0X00000005)
#define IOMUX_PINCM55_PF_UC13_1_POCI                  ((uint32_t)0X00000006)
#define IOMUX_PINCM55_PF_UC13_1_RTS                   ((uint32_t)0X00000006)

/* IOMUX_PINCM56[PF] Bits */
#define IOMUX_PINCM56_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM56_PF_GPIOB_DIO25                  ((uint32_t)0X00000001)
#define IOMUX_PINCM56_PF_TIMA_0_FAULT2                ((uint32_t)0X00000002)
#define IOMUX_PINCM56_PF_I2S0_BCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM56_PF_UC1_0_CTS                    ((uint32_t)0X00000004)

/* IOMUX_PINCM57[PF] Bits */
#define IOMUX_PINCM57_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM57_PF_GPIOB_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM57_PF_TIMG4_2_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM57_PF_I2S0_MCLK                    ((uint32_t)0X00000003)
#define IOMUX_PINCM57_PF_UC1_0_RTS                    ((uint32_t)0X00000004)

/* IOMUX_PINCM58[PF] Bits */
#define IOMUX_PINCM58_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM58_PF_GPIOB_DIO27                  ((uint32_t)0X00000001)
#define IOMUX_PINCM58_PF_TIMG4_2_CCP1                 ((uint32_t)0X00000002)

/* IOMUX_PINCM59[PF] Bits */
#define IOMUX_PINCM59_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM59_PF_GPIOA_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM59_PF_TIMG4_3_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM59_PF_TIMA_0_FAULT0                ((uint32_t)0X00000003)
#define IOMUX_PINCM59_PF_CANFD0_CANTX                 ((uint32_t)0X00000004)
#define IOMUX_PINCM59_PF_UC13_0_PICO                  ((uint32_t)0X00000005)
#define IOMUX_PINCM59_PF_UC13_0_SDA                   ((uint32_t)0X00000005)
#define IOMUX_PINCM59_PF_UC13_0_TX                    ((uint32_t)0X00000005)
#define IOMUX_PINCM59_PF_UC13_0_CS0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM59_PF_UC13_0_CTS                   ((uint32_t)0X00000006)
#define IOMUX_PINCM59_PF_UC13_3_PICO                  ((uint32_t)0X00000007)
#define IOMUX_PINCM59_PF_UC13_3_SDA                   ((uint32_t)0X00000007)
#define IOMUX_PINCM59_PF_UC13_3_TX                    ((uint32_t)0X00000007)

/* IOMUX_PINCM60[PF] Bits */
#define IOMUX_PINCM60_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM60_PF_GPIOA_DIO27                  ((uint32_t)0X00000001)
#define IOMUX_PINCM60_PF_TIMG4_3_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM60_PF_LFSS_RTC_OUT                 ((uint32_t)0X00000003)
#define IOMUX_PINCM60_PF_CANFD0_CANRX                 ((uint32_t)0X00000004)
#define IOMUX_PINCM60_PF_TIMG4_1_CCP0                 ((uint32_t)0X00000005)
#define IOMUX_PINCM60_PF_TIMA_0_FAULT2                ((uint32_t)0X00000006)
#define IOMUX_PINCM60_PF_UC13_3_POCI                  ((uint32_t)0X00000007)
#define IOMUX_PINCM60_PF_UC13_3_RTS                   ((uint32_t)0X00000007)
#define IOMUX_PINCM60_PF_UC2_CS1                      ((uint32_t)0X00000008)

/* IOMUX_PINCM61[PF] Bits */
#define IOMUX_PINCM61_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM61_PF_GPIOC_DIO12                  ((uint32_t)0X00000001)
#define IOMUX_PINCM61_PF_TIMA0_1_CCP0                 ((uint32_t)0X00000002)

/* IOMUX_PINCM62[PF] Bits */
#define IOMUX_PINCM62_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM62_PF_GPIOC_DIO13                  ((uint32_t)0X00000001)
#define IOMUX_PINCM62_PF_TIMG4_1_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM62_PF_UC13_1_PICO                  ((uint32_t)0X00000003)
#define IOMUX_PINCM62_PF_UC13_1_SDA                   ((uint32_t)0X00000003)
#define IOMUX_PINCM62_PF_UC13_1_TX                    ((uint32_t)0X00000003)
#define IOMUX_PINCM62_PF_UC12_RTS                     ((uint32_t)0X00000004)

/* IOMUX_PINCM63[PF] Bits */
#define IOMUX_PINCM63_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM63_PF_GPIOC_DIO14                  ((uint32_t)0X00000001)
#define IOMUX_PINCM63_PF_TIMG4_1_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM63_PF_UC13_1_SCLK                  ((uint32_t)0X00000003)
#define IOMUX_PINCM63_PF_UC13_1_SCL                   ((uint32_t)0X00000003)
#define IOMUX_PINCM63_PF_UC13_1_RX                    ((uint32_t)0X00000003)
#define IOMUX_PINCM63_PF_UC12_CTS                     ((uint32_t)0X00000004)

/* IOMUX_PINCM64[PF] Bits */
#define IOMUX_PINCM64_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM64_PF_GPIOC_DIO15                  ((uint32_t)0X00000001)
#define IOMUX_PINCM64_PF_TIMA0_1_CCP0_CMPL            ((uint32_t)0X00000002)

/* IOMUX_PINCM65[PF] Bits */
#define IOMUX_PINCM65_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM65_PF_GPIOB_DIO28                  ((uint32_t)0X00000001)
#define IOMUX_PINCM65_PF_TIMA0_0_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM65_PF_UC13_3_SCLK                  ((uint32_t)0X00000003)
#define IOMUX_PINCM65_PF_UC13_3_SCL                   ((uint32_t)0X00000003)
#define IOMUX_PINCM65_PF_UC13_3_RX                    ((uint32_t)0X00000003)
#define IOMUX_PINCM65_PF_UC13_0_CS0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM65_PF_UC13_0_CTS                   ((uint32_t)0X00000004)

/* IOMUX_PINCM66[PF] Bits */
#define IOMUX_PINCM66_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM66_PF_GPIOB_DIO29                  ((uint32_t)0X00000001)
#define IOMUX_PINCM66_PF_TIMA0_0_CCP0_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM66_PF_TIMG8_1_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM66_PF_UC13_3_PICO                  ((uint32_t)0X00000004)
#define IOMUX_PINCM66_PF_UC13_3_SDA                   ((uint32_t)0X00000004)
#define IOMUX_PINCM66_PF_UC13_3_TX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM66_PF_UC13_0_POCI                  ((uint32_t)0X00000005)
#define IOMUX_PINCM66_PF_UC13_0_RTS                   ((uint32_t)0X00000005)

/* IOMUX_PINCM67[PF] Bits */
#define IOMUX_PINCM67_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM67_PF_GPIOB_DIO30                  ((uint32_t)0X00000001)
#define IOMUX_PINCM67_PF_TIMA0_0_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM67_PF_TIMG8_1_CCP1                 ((uint32_t)0X00000003)
#define IOMUX_PINCM67_PF_UC13_3_CS0                   ((uint32_t)0X00000004)
#define IOMUX_PINCM67_PF_UC13_3_CTS                   ((uint32_t)0X00000004)
#define IOMUX_PINCM67_PF_UC13_0_PICO                  ((uint32_t)0X00000005)
#define IOMUX_PINCM67_PF_UC13_0_SDA                   ((uint32_t)0X00000005)
#define IOMUX_PINCM67_PF_UC13_0_TX                    ((uint32_t)0X00000005)

/* IOMUX_PINCM68[PF] Bits */
#define IOMUX_PINCM68_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM68_PF_GPIOB_DIO31                  ((uint32_t)0X00000001)
#define IOMUX_PINCM68_PF_TIMG8_0_IDX                  ((uint32_t)0X00000002)
#define IOMUX_PINCM68_PF_TIMA0_0_CCP1_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM68_PF_UC13_3_POCI                  ((uint32_t)0X00000004)
#define IOMUX_PINCM68_PF_UC13_3_RTS                   ((uint32_t)0X00000004)
#define IOMUX_PINCM68_PF_UC13_0_SCLK                  ((uint32_t)0X00000005)
#define IOMUX_PINCM68_PF_UC13_0_SCL                   ((uint32_t)0X00000005)
#define IOMUX_PINCM68_PF_UC13_0_RX                    ((uint32_t)0X00000005)
#define IOMUX_PINCM68_PF_TIMG8_1_IDX                  ((uint32_t)0X00000006)

/* IOMUX_PINCM69[PF] Bits */
#define IOMUX_PINCM69_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM69_PF_GPIOC_DIO16                  ((uint32_t)0X00000001)

/* IOMUX_PINCM70[PF] Bits */
#define IOMUX_PINCM70_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM70_PF_GPIOC_DIO17                  ((uint32_t)0X00000001)
#define IOMUX_PINCM70_PF_TIMA0_1_CCP1                 ((uint32_t)0X00000002)

/* IOMUX_PINCM71[PF] Bits */
#define IOMUX_PINCM71_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM71_PF_GPIOC_DIO18                  ((uint32_t)0X00000001)
#define IOMUX_PINCM71_PF_TIMA0_1_CCP3                 ((uint32_t)0X00000002)

/* IOMUX_PINCM72[PF] Bits */
#define IOMUX_PINCM72_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM72_PF_GPIOC_DIO19                  ((uint32_t)0X00000001)
#define IOMUX_PINCM72_PF_TIMA0_1_CCP3_CMPL            ((uint32_t)0X00000002)

/* IOMUX_PINCM73[PF] Bits */
#define IOMUX_PINCM73_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM73_PF_GPIOC_DIO20                  ((uint32_t)0X00000001)
#define IOMUX_PINCM73_PF_TIMA_1_FAULT2                ((uint32_t)0X00000002)

/* IOMUX_PINCM74[PF] Bits */
#define IOMUX_PINCM74_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM74_PF_GPIOC_DIO00                  ((uint32_t)0X00000001)
#define IOMUX_PINCM74_PF_TIMG8_0_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM74_PF_TIMA0_0_CCP2                 ((uint32_t)0X00000003)
#define IOMUX_PINCM74_PF_QSPI_CS0                     ((uint32_t)0X00000007)

/* IOMUX_PINCM75[PF] Bits */
#define IOMUX_PINCM75_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM75_PF_GPIOC_DIO01                  ((uint32_t)0X00000001)
#define IOMUX_PINCM75_PF_TIMG8_0_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM75_PF_TIMA0_0_CCP2_CMPL            ((uint32_t)0X00000003)

/* IOMUX_PINCM76[PF] Bits */
#define IOMUX_PINCM76_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM76_PF_GPIOC_DIO02                  ((uint32_t)0X00000001)
#define IOMUX_PINCM76_PF_TIMA0_0_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM76_PF_TIMA_1_FAULT0                ((uint32_t)0X00000003)
#define IOMUX_PINCM76_PF_UC13_0_SCLK                  ((uint32_t)0X00000004)
#define IOMUX_PINCM76_PF_UC13_0_SCL                   ((uint32_t)0X00000004)
#define IOMUX_PINCM76_PF_UC13_0_RX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM76_PF_TIMG4_1_CCP1                 ((uint32_t)0X00000005)
#define IOMUX_PINCM76_PF_UC13_0_CS0                   ((uint32_t)0X00000006)
#define IOMUX_PINCM76_PF_UC13_0_CTS                   ((uint32_t)0X00000006)
#define IOMUX_PINCM76_PF_UC13_3_CS0                   ((uint32_t)0X00000007)
#define IOMUX_PINCM76_PF_UC13_3_CTS                   ((uint32_t)0X00000007)
#define IOMUX_PINCM76_PF_UC2_CS0                      ((uint32_t)0X00000008)

/* IOMUX_PINCM77[PF] Bits */
#define IOMUX_PINCM77_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM77_PF_GPIOC_DIO03                  ((uint32_t)0X00000001)
#define IOMUX_PINCM77_PF_TIMG4_3_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM77_PF_TIMA0_0_CCP0_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM77_PF_UC13_0_PICO                  ((uint32_t)0X00000004)
#define IOMUX_PINCM77_PF_UC13_0_SDA                   ((uint32_t)0X00000004)
#define IOMUX_PINCM77_PF_UC13_0_TX                    ((uint32_t)0X00000004)

/* IOMUX_PINCM78[PF] Bits */
#define IOMUX_PINCM78_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM78_PF_GPIOC_DIO04                  ((uint32_t)0X00000001)
#define IOMUX_PINCM78_PF_TIMA0_0_CCP1                 ((uint32_t)0X00000002)

/* IOMUX_PINCM79[PF] Bits */
#define IOMUX_PINCM79_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM79_PF_GPIOC_DIO05                  ((uint32_t)0X00000001)
#define IOMUX_PINCM79_PF_TIMA0_0_CCP1_CMPL            ((uint32_t)0X00000002)

/* IOMUX_PINCM80[PF] Bits */
#define IOMUX_PINCM80_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM80_PF_GPIOC_DIO21                  ((uint32_t)0X00000001)
#define IOMUX_PINCM80_PF_CANFD1_CANTX                 ((uint32_t)0X00000002)

/* IOMUX_PINCM81[PF] Bits */
#define IOMUX_PINCM81_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM81_PF_GPIOC_DIO22                  ((uint32_t)0X00000001)
#define IOMUX_PINCM81_PF_CANFD1_CANRX                 ((uint32_t)0X00000002)

/* IOMUX_PINCM82[PF] Bits */
#define IOMUX_PINCM82_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM82_PF_GPIOC_DIO23                  ((uint32_t)0X00000001)
#define IOMUX_PINCM82_PF_TIMA0_1_CCP2                 ((uint32_t)0X00000002)

/* IOMUX_PINCM83[PF] Bits */
#define IOMUX_PINCM83_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM83_PF_GPIOC_DIO24                  ((uint32_t)0X00000001)
#define IOMUX_PINCM83_PF_TIMA0_1_CCP2_CMPL            ((uint32_t)0X00000002)

/* IOMUX_PINCM84[PF] Bits */
#define IOMUX_PINCM84_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM84_PF_GPIOC_DIO06                  ((uint32_t)0X00000001)
#define IOMUX_PINCM84_PF_TIMG4_2_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM84_PF_TIMA0_0_CCP0                 ((uint32_t)0X00000003)
#define IOMUX_PINCM84_PF_UC13_0_PICO                  ((uint32_t)0X00000004)
#define IOMUX_PINCM84_PF_UC13_0_SDA                   ((uint32_t)0X00000004)
#define IOMUX_PINCM84_PF_UC13_0_TX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM84_PF_UC2_CS1                      ((uint32_t)0X00000005)

/* IOMUX_PINCM85[PF] Bits */
#define IOMUX_PINCM85_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM85_PF_GPIOC_DIO07                  ((uint32_t)0X00000001)
#define IOMUX_PINCM85_PF_TIMG4_2_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM85_PF_TIMA0_0_CCP0_CMPL            ((uint32_t)0X00000003)
#define IOMUX_PINCM85_PF_UC13_0_SCLK                  ((uint32_t)0X00000004)
#define IOMUX_PINCM85_PF_UC13_0_SCL                   ((uint32_t)0X00000004)
#define IOMUX_PINCM85_PF_UC13_0_RX                    ((uint32_t)0X00000004)
#define IOMUX_PINCM85_PF_UC2_CS0                      ((uint32_t)0X00000005)

/* IOMUX_PINCM86[PF] Bits */
#define IOMUX_PINCM86_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM86_PF_GPIOC_DIO08                  ((uint32_t)0X00000001)
#define IOMUX_PINCM86_PF_TIMA0_0_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM86_PF_UC13_0_CS0                   ((uint32_t)0X00000003)
#define IOMUX_PINCM86_PF_UC13_0_CTS                   ((uint32_t)0X00000003)

/* IOMUX_PINCM87[PF] Bits */
#define IOMUX_PINCM87_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM87_PF_GPIOC_DIO09                  ((uint32_t)0X00000001)
#define IOMUX_PINCM87_PF_TIMA0_0_CCP1_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM87_PF_UC13_0_POCI                  ((uint32_t)0X00000003)
#define IOMUX_PINCM87_PF_UC13_0_RTS                   ((uint32_t)0X00000003)

/* IOMUX_PINCM88[PF] Bits */
#define IOMUX_PINCM88_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM88_PF_GPIOC_DIO10                  ((uint32_t)0X00000001)
#define IOMUX_PINCM88_PF_TIMG8_1_CCP0                 ((uint32_t)0X00000002)
#define IOMUX_PINCM88_PF_UC14_SCL                     ((uint32_t)0X00000003)
#define IOMUX_PINCM88_PF_UC14_RX                      ((uint32_t)0X00000003)

/* IOMUX_PINCM89[PF] Bits */
#define IOMUX_PINCM89_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM89_PF_GPIOC_DIO11                  ((uint32_t)0X00000001)
#define IOMUX_PINCM89_PF_TIMG8_1_CCP1                 ((uint32_t)0X00000002)
#define IOMUX_PINCM89_PF_UC14_SDA                     ((uint32_t)0X00000003)
#define IOMUX_PINCM89_PF_UC14_TX                      ((uint32_t)0X00000003)

/* IOMUX_PINCM90[PF] Bits */
#define IOMUX_PINCM90_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM90_PF_GPIOC_DIO25                  ((uint32_t)0X00000001)
#define IOMUX_PINCM90_PF_TIMG8_1_IDX                  ((uint32_t)0X00000002)
#define IOMUX_PINCM90_PF_UC14_CTS                     ((uint32_t)0X00000003)

/* IOMUX_PINCM91[PF] Bits */
#define IOMUX_PINCM91_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM91_PF_GPIOC_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM91_PF_CANFD1_CANTX                 ((uint32_t)0X00000002)
#define IOMUX_PINCM91_PF_UC14_RTS                     ((uint32_t)0X00000003)

/* IOMUX_PINCM92[PF] Bits */
#define IOMUX_PINCM92_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM92_PF_GPIOC_DIO27                  ((uint32_t)0X00000001)
#define IOMUX_PINCM92_PF_CANFD1_CANRX                 ((uint32_t)0X00000002)

/* IOMUX_PINCM93[PF] Bits */
#define IOMUX_PINCM93_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM93_PF_GPIOC_DIO28                  ((uint32_t)0X00000001)
#define IOMUX_PINCM93_PF_UC13_3_SCLK                  ((uint32_t)0X00000002)
#define IOMUX_PINCM93_PF_UC13_3_SCL                   ((uint32_t)0X00000002)
#define IOMUX_PINCM93_PF_UC13_3_RX                    ((uint32_t)0X00000002)
#define IOMUX_PINCM93_PF_UC12_TX                      ((uint32_t)0X00000004)

/* IOMUX_PINCM94[PF] Bits */
#define IOMUX_PINCM94_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM94_PF_GPIOC_DIO29                  ((uint32_t)0X00000001)
#define IOMUX_PINCM94_PF_TIMA0_1_CCP1_CMPL            ((uint32_t)0X00000002)
#define IOMUX_PINCM94_PF_UC13_3_PICO                  ((uint32_t)0X00000003)
#define IOMUX_PINCM94_PF_UC13_3_SDA                   ((uint32_t)0X00000003)
#define IOMUX_PINCM94_PF_UC13_3_TX                    ((uint32_t)0X00000003)


#if defined(__CC_ARM)
#pragma pop
#elif defined(__ICCARM__)
/* leave anonymous unions enabled */
#elif(defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
#pragma clang diagnostic pop
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#pragma warning restore
#elif defined(__CSMC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/*@}*/ /* end of group M33C1_PeripheralDecl */

/*@}*/ /* end of group M33C1_Definitions */

#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_m0p_m33c1__include */
