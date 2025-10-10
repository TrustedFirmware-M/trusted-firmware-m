/*
** ###################################################################
**     Processors:          MCXN247VAB
**                          MCXN247VDF
**                          MCXN247VKL
**                          MCXN247VPB
**                          MCXN526VDF_cm33_core0
**                          MCXN526VDF_cm33_core1
**                          MCXN526VKL_cm33_core0
**                          MCXN526VKL_cm33_core1
**                          MCXN527VAB_cm33_core0
**                          MCXN527VAB_cm33_core1
**                          MCXN527VDF_cm33_core0
**                          MCXN527VDF_cm33_core1
**                          MCXN527VKL_cm33_core0
**                          MCXN527VKL_cm33_core1
**                          MCXN536VAB_cm33_core0
**                          MCXN536VAB_cm33_core1
**                          MCXN536VDF_cm33_core0
**                          MCXN536VDF_cm33_core1
**                          MCXN536VKL_cm33_core0
**                          MCXN536VKL_cm33_core1
**                          MCXN536VPB_cm33_core0
**                          MCXN536VPB_cm33_core1
**                          MCXN537VAB_cm33_core0
**                          MCXN537VAB_cm33_core1
**                          MCXN537VDF_cm33_core0
**                          MCXN537VDF_cm33_core1
**                          MCXN537VKL_cm33_core0
**                          MCXN537VKL_cm33_core1
**                          MCXN537VPB_cm33_core0
**                          MCXN537VPB_cm33_core1
**                          MCXN546VAB_cm33_core0
**                          MCXN546VAB_cm33_core1
**                          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VAB_cm33_core0
**                          MCXN547VAB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN556SCDF_cm33_core0
**                          MCXN556SCDF_cm33_core1
**                          MCXN946VAB_cm33_core0
**                          MCXN946VAB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VAB_cm33_core0
**                          MCXN947VAB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250811
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCON.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCON
 *
 * CMSIS Peripheral Access Layer for SYSCON
 */

#if !defined(PERI_SYSCON_H_)
#define PERI_SYSCON_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN247VAB) || defined(CPU_MCXN247VDF) || defined(CPU_MCXN247VKL) || defined(CPU_MCXN247VPB))
#include "MCXN247_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core0) || defined(CPU_MCXN526VKL_cm33_core0))
#include "MCXN526_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN526VDF_cm33_core1) || defined(CPU_MCXN526VKL_cm33_core1))
#include "MCXN526_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core0) || defined(CPU_MCXN527VDF_cm33_core0) || defined(CPU_MCXN527VKL_cm33_core0))
#include "MCXN527_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN527VAB_cm33_core1) || defined(CPU_MCXN527VDF_cm33_core1) || defined(CPU_MCXN527VKL_cm33_core1))
#include "MCXN527_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core0) || defined(CPU_MCXN536VDF_cm33_core0) || defined(CPU_MCXN536VKL_cm33_core0) || defined(CPU_MCXN536VPB_cm33_core0))
#include "MCXN536_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN536VAB_cm33_core1) || defined(CPU_MCXN536VDF_cm33_core1) || defined(CPU_MCXN536VKL_cm33_core1) || defined(CPU_MCXN536VPB_cm33_core1))
#include "MCXN536_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core0) || defined(CPU_MCXN537VDF_cm33_core0) || defined(CPU_MCXN537VKL_cm33_core0) || defined(CPU_MCXN537VPB_cm33_core0))
#include "MCXN537_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN537VAB_cm33_core1) || defined(CPU_MCXN537VDF_cm33_core1) || defined(CPU_MCXN537VKL_cm33_core1) || defined(CPU_MCXN537VPB_cm33_core1))
#include "MCXN537_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core0) || defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VAB_cm33_core1) || defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core0) || defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VAB_cm33_core1) || defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core0))
#include "MCXN556S_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN556SCDF_cm33_core1))
#include "MCXN556S_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core0) || defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VAB_cm33_core1) || defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core0) || defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VAB_cm33_core1) || defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SYSCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Peripheral_Access_Layer SYSCON Peripheral Access Layer
 * @{
 */

/** SYSCON - Size of Registers Arrays */
#define SYSCON_PRESETCTRLSET_COUNT                4u
#define SYSCON_PRESETCTRLCLR_COUNT                4u
#define SYSCON_AHBCLKCTRLSET_COUNT                4u
#define SYSCON_AHBCLKCTRLCLR_COUNT                4u
#define SYSCON_CTIMERCLKSEL_COUNT                 5u
#define SYSCON_FCCLKSEL_COUNT                     10u
#define SYSCON_SYSTICKCLKDIV_COUNT                2u
#define SYSCON_CTIMERXCLKDIV_COUNT                5u
#define SYSCON_DAC_COUNT                          3u
#define SYSCON_FLEXCOMMXCLKDIV_COUNT              10u
#define SYSCON_GDETX_CTRL_COUNT                   2u
#define SYSCON_SWD_ACCESS_CPU_COUNT               2u

/** SYSCON - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t AHBMATPRIO;                        /**< AHB Matrix Priority Control, offset: 0x10 */
       uint8_t RESERVED_1[36];
  __IO uint32_t CPU0STCKCAL;                       /**< Secure CPU0 System Tick Calibration, offset: 0x38 */
  __IO uint32_t CPU0NSTCKCAL;                      /**< Non-Secure CPU0 System Tick Calibration, offset: 0x3C */
  __IO uint32_t CPU1STCKCAL;                       /**< System tick calibration for CPU1, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x48 */
       uint8_t RESERVED_3[180];
  __IO uint32_t PRESETCTRL0;                       /**< Peripheral Reset Control 0, offset: 0x100 */
  __IO uint32_t PRESETCTRL1;                       /**< Peripheral Reset Control 1, offset: 0x104 */
  __IO uint32_t PRESETCTRL2;                       /**< Peripheral Reset Control 2, offset: 0x108 */
  __IO uint32_t PRESETCTRL3;                       /**< Peripheral Reset Control 3, offset: 0x10C */
       uint8_t RESERVED_4[16];
  __O  uint32_t PRESETCTRLSET[SYSCON_PRESETCTRLSET_COUNT]; /**< Peripheral Reset Control Set, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __O  uint32_t PRESETCTRLCLR[SYSCON_PRESETCTRLCLR_COUNT]; /**< Peripheral Reset Control Clear, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_6[176];
  __IO uint32_t AHBCLKCTRL0;                       /**< AHB Clock Control 0, offset: 0x200 */
  __IO uint32_t AHBCLKCTRL1;                       /**< AHB Clock Control 1, offset: 0x204 */
  __IO uint32_t AHBCLKCTRL2;                       /**< AHB Clock Control 2, offset: 0x208 */
  __IO uint32_t AHBCLKCTRL3;                       /**< AHB Clock Control 3, offset: 0x20C */
       uint8_t RESERVED_7[16];
  __O  uint32_t AHBCLKCTRLSET[SYSCON_AHBCLKCTRLSET_COUNT]; /**< AHB Clock Control Set, array offset: 0x220, array step: 0x4 */
       uint8_t RESERVED_8[16];
  __O  uint32_t AHBCLKCTRLCLR[SYSCON_AHBCLKCTRLCLR_COUNT]; /**< AHB Clock Control Clear, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_9[16];
  __IO uint32_t SYSTICKCLKSEL0;                    /**< CPU0 System Tick Timer Source Select, offset: 0x260 */
  __IO uint32_t SYSTICKCLKSEL1;                    /**< CPU1 System Tick Timer Source Select, offset: 0x264 */
  __IO uint32_t TRACECLKSEL;                       /**< Trace Clock Source Select, offset: 0x268 */
  __IO uint32_t CTIMERCLKSEL[SYSCON_CTIMERCLKSEL_COUNT]; /**< CTIMER Clock Source Select, array offset: 0x26C, array step: 0x4 */
       uint8_t RESERVED_10[8];
  __IO uint32_t CLKOUTSEL;                         /**< CLKOUT Clock Source Select, offset: 0x288 */
       uint8_t RESERVED_11[24];
  __IO uint32_t ADC0CLKSEL;                        /**< ADC0 Clock Source Select, offset: 0x2A4 */
  __IO uint32_t USB0CLKSEL;                        /**< USB-FS Clock Source Select, offset: 0x2A8 */
       uint8_t RESERVED_12[4];
  __IO uint32_t FCCLKSEL[SYSCON_FCCLKSEL_COUNT];   /**< LP_FLEXCOMM Clock Source Select for Fractional Rate Divider, array offset: 0x2B0, array step: 0x4 */
       uint8_t RESERVED_13[24];
  __IO uint32_t SCTCLKSEL;                         /**< SCTimer/PWM Clock Source Select, offset: 0x2F0 */
       uint8_t RESERVED_14[12];
  __IO uint32_t SYSTICKCLKDIV[SYSCON_SYSTICKCLKDIV_COUNT]; /**< CPU0 System Tick Timer Divider..CPU1 System Tick Timer Divider, array offset: 0x300, array step: 0x4 */
  __IO uint32_t TRACECLKDIV;                       /**< TRACE Clock Divider, offset: 0x308 */
       uint8_t RESERVED_15[68];
  __IO uint32_t TSICLKSEL;                         /**< TSI Function Clock Source Select, offset: 0x350 */
       uint8_t RESERVED_16[12];
  __IO uint32_t SINCFILTCLKSEL;                    /**< SINC FILTER Function Clock Source Select, offset: 0x360 */
       uint8_t RESERVED_17[20];
  __IO uint32_t SLOWCLKDIV;                        /**< SLOW_CLK Clock Divider, offset: 0x378 */
  __IO uint32_t TSICLKDIV;                         /**< TSI Function Clock Divider, offset: 0x37C */
  __IO uint32_t AHBCLKDIV;                         /**< System Clock Divider, offset: 0x380 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT Clock Divider, offset: 0x384 */
  __IO uint32_t FROHFDIV;                          /**< FRO_HF_DIV Clock Divider, offset: 0x388 */
  __IO uint32_t WDT0CLKDIV;                        /**< WDT0 Clock Divider, offset: 0x38C */
       uint8_t RESERVED_18[4];
  __IO uint32_t ADC0CLKDIV;                        /**< ADC0 Clock Divider, offset: 0x394 */
  __IO uint32_t USB0CLKDIV;                        /**< USB-FS Clock Divider, offset: 0x398 */
       uint8_t RESERVED_19[24];
  __IO uint32_t SCTCLKDIV;                         /**< SCT/PWM Clock Divider, offset: 0x3B4 */
       uint8_t RESERVED_20[12];
  __IO uint32_t PLLCLKDIV;                         /**< PLL Clock Divider, offset: 0x3C4 */
       uint8_t RESERVED_21[8];
  __IO uint32_t CTIMERCLKDIV[SYSCON_CTIMERXCLKDIV_COUNT]; /**< CTimer Clock Divider, array offset: 0x3D0, array step: 0x4 */
  __IO uint32_t PLL1CLK0DIV;                       /**< PLL1 Clock 0 Divider, offset: 0x3E4 */
  __IO uint32_t PLL1CLK1DIV;                       /**< PLL1 Clock 1 Divider, offset: 0x3E8 */
       uint8_t RESERVED_22[4];
  __IO uint32_t UTICKCLKDIV;                       /**< UTICK Clock Divider, offset: 0x3F0 */
  __IO uint32_t CLKOUT_FRGCTRL;                    /**< CLKOUT FRG Control, offset: 0x3F4 */
       uint8_t RESERVED_23[4];
  __IO uint32_t CLKUNLOCK;                         /**< Clock Configuration Unlock, offset: 0x3FC */
  __IO uint32_t NVM_CTRL;                          /**< NVM Control, offset: 0x400 */
  __IO uint32_t ROMCR;                             /**< ROM Wait State, offset: 0x404 */
       uint8_t RESERVED_24[12];
  __IO uint32_t SMARTDMAINT;                       /**< SmartDMA Interrupt Hijack, offset: 0x414 */
       uint8_t RESERVED_25[76];
  __IO uint32_t ADC1CLKSEL;                        /**< ADC1 Clock Source Select, offset: 0x464 */
  __IO uint32_t ADC1CLKDIV;                        /**< ADC1 Clock Divider, offset: 0x468 */
       uint8_t RESERVED_26[4];
  __IO uint32_t RAM_INTERLEAVE;                    /**< Control PKC RAM Interleave Access, offset: 0x470 */
       uint8_t RESERVED_27[28];
  struct {                                         /* offset: 0x490, array step: 0x8 */
    __IO uint32_t CLKSEL;                            /**< DAC0 Functional Clock Selection..DAC2 Functional Clock Selection, array offset: 0x490, array step: 0x8 */
    __IO uint32_t CLKDIV;                            /**< DAC0 functional clock divider..DAC2 functional clock divider, array offset: 0x494, array step: 0x8 */
  } DAC[SYSCON_DAC_COUNT];
  __IO uint32_t FLEXSPICLKSEL;                     /**< FlexSPI Clock Selection, offset: 0x4A8 */
  __IO uint32_t FLEXSPICLKDIV;                     /**< FlexSPI Clock Divider, offset: 0x4AC */
       uint8_t RESERVED_28[124];
  __IO uint32_t PLLCLKDIVSEL;                      /**< PLL Clock Divider Clock Selection, offset: 0x52C */
  __IO uint32_t I3C0FCLKSEL;                       /**< I3C0 Functional Clock Selection, offset: 0x530 */
  __IO uint32_t I3C0FCLKSTCSEL;                    /**< I3C0 FCLK_STC Clock Selection, offset: 0x534 */
  __IO uint32_t I3C0FCLKSTCDIV;                    /**< I3C0 FCLK_STC Clock Divider, offset: 0x538 */
  __IO uint32_t I3C0FCLKSDIV;                      /**< I3C0 FCLK Slow Clock Divider, offset: 0x53C */
  __IO uint32_t I3C0FCLKDIV;                       /**< I3C0 Functional Clock FCLK Divider, offset: 0x540 */
  __IO uint32_t I3C0FCLKSSEL;                      /**< I3C0 FCLK Slow Selection, offset: 0x544 */
  __IO uint32_t MICFILFCLKSEL;                     /**< MICFIL Clock Selection, offset: 0x548 */
  __IO uint32_t MICFILFCLKDIV;                     /**< MICFIL Clock Division, offset: 0x54C */
       uint8_t RESERVED_29[8];
  __IO uint32_t USDHCCLKSEL;                       /**< uSDHC Clock Selection, offset: 0x558 */
  __IO uint32_t USDHCCLKDIV;                       /**< uSDHC Function Clock Divider, offset: 0x55C */
  __IO uint32_t FLEXIOCLKSEL;                      /**< FLEXIO Clock Selection, offset: 0x560 */
  __IO uint32_t FLEXIOCLKDIV;                      /**< FLEXIO Function Clock Divider, offset: 0x564 */
       uint8_t RESERVED_30[56];
  __IO uint32_t FLEXCAN0CLKSEL;                    /**< FLEXCAN0 Clock Selection, offset: 0x5A0 */
  __IO uint32_t FLEXCAN0CLKDIV;                    /**< FLEXCAN0 Function Clock Divider, offset: 0x5A4 */
  __IO uint32_t FLEXCAN1CLKSEL;                    /**< FLEXCAN1 Clock Selection, offset: 0x5A8 */
  __IO uint32_t FLEXCAN1CLKDIV;                    /**< FLEXCAN1 Function Clock Divider, offset: 0x5AC */
  __IO uint32_t ENETRMIICLKSEL;                    /**< Ethernet RMII Clock Selection, offset: 0x5B0 */
  __IO uint32_t ENETRMIICLKDIV;                    /**< Ethernet RMII Function Clock Divider, offset: 0x5B4 */
  __IO uint32_t ENETPTPREFCLKSEL;                  /**< Ethernet PTP REF Clock Selection, offset: 0x5B8 */
  __IO uint32_t ENETPTPREFCLKDIV;                  /**< Ethernet PTP REF Function Clock Divider, offset: 0x5BC */
  __IO uint32_t ENET_PHY_INTF_SEL;                 /**< Ethernet PHY Interface Select, offset: 0x5C0 */
  __IO uint32_t ENET_SBD_FLOW_CTRL;                /**< Sideband Flow Control, offset: 0x5C4 */
       uint8_t RESERVED_31[12];
  __IO uint32_t EWM0CLKSEL;                        /**< EWM0 Clock Selection, offset: 0x5D4 */
  __IO uint32_t WDT1CLKSEL;                        /**< WDT1 Clock Selection, offset: 0x5D8 */
  __IO uint32_t WDT1CLKDIV;                        /**< WDT1 Function Clock Divider, offset: 0x5DC */
  __IO uint32_t OSTIMERCLKSEL;                     /**< OSTIMER Clock Selection, offset: 0x5E0 */
       uint8_t RESERVED_32[12];
  __IO uint32_t CMP0FCLKSEL;                       /**< CMP0 Function Clock Selection, offset: 0x5F0 */
  __IO uint32_t CMP0FCLKDIV;                       /**< CMP0 Function Clock Divider, offset: 0x5F4 */
  __IO uint32_t CMP0RRCLKSEL;                      /**< CMP0 Round Robin Clock Selection, offset: 0x5F8 */
  __IO uint32_t CMP0RRCLKDIV;                      /**< CMP0 Round Robin Clock Divider, offset: 0x5FC */
  __IO uint32_t CMP1FCLKSEL;                       /**< CMP1 Function Clock Selection, offset: 0x600 */
  __IO uint32_t CMP1FCLKDIV;                       /**< CMP1 Function Clock Divider, offset: 0x604 */
  __IO uint32_t CMP1RRCLKSEL;                      /**< CMP1 Round Robin Clock Source Select, offset: 0x608 */
  __IO uint32_t CMP1RRCLKDIV;                      /**< CMP1 Round Robin Clock Division, offset: 0x60C */
  __IO uint32_t CMP2FCLKSEL;                       /**< CMP2 Function Clock Source Select, offset: 0x610 */
  __IO uint32_t CMP2FCLKDIV;                       /**< CMP2 Function Clock Division, offset: 0x614 */
  __IO uint32_t CMP2RRCLKSEL;                      /**< CMP2 Round Robin Clock Source Select, offset: 0x618 */
  __IO uint32_t CMP2RRCLKDIV;                      /**< CMP2 Round Robin Clock Division, offset: 0x61C */
       uint8_t RESERVED_33[480];
  __IO uint32_t CPUCTRL;                           /**< CPU Control for Multiple Processors, offset: 0x800 */
  __IO uint32_t CPBOOT;                            /**< Coprocessor Boot Address, offset: 0x804 */
       uint8_t RESERVED_34[4];
  __I  uint32_t CPUSTAT;                           /**< CPU Status, offset: 0x80C */
       uint8_t RESERVED_35[20];
  __IO uint32_t LPCAC_CTRL;                        /**< LPCAC Control, offset: 0x824 */
       uint8_t RESERVED_36[40];
  __IO uint32_t FLEXCOMMCLKDIV[SYSCON_FLEXCOMMXCLKDIV_COUNT]; /**< LP_FLEXCOMM Clock Divider, array offset: 0x850, array step: 0x4 */
  __IO uint32_t UTICKCLKSEL;                       /**< UTICK Function Clock Source Select, offset: 0x878 */
       uint8_t RESERVED_37[4];
  __IO uint32_t SAI0CLKSEL;                        /**< SAI0 Function Clock Source Select, offset: 0x880 */
  __IO uint32_t SAI1CLKSEL;                        /**< SAI1 Function Clock Source Select, offset: 0x884 */
  __IO uint32_t SAI0CLKDIV;                        /**< SAI0 Function Clock Division, offset: 0x888 */
  __IO uint32_t SAI1CLKDIV;                        /**< SAI1 Function Clock Division, offset: 0x88C */
  __IO uint32_t EMVSIM0CLKSEL;                     /**< EMVSIM0 Clock Source Select, offset: 0x890 */
  __IO uint32_t EMVSIM1CLKSEL;                     /**< EMVSIM1 Clock Source Select, offset: 0x894 */
  __IO uint32_t EMVSIM0CLKDIV;                     /**< EMVSIM0 Function Clock Division, offset: 0x898 */
  __IO uint32_t EMVSIM1CLKDIV;                     /**< EMVSIM1 Function Clock Division, offset: 0x89C */
       uint8_t RESERVED_38[176];
  __IO uint32_t KEY_RETAIN_CTRL;                   /**< Key Retain Control, offset: 0x950 */
       uint8_t RESERVED_39[12];
  __IO uint32_t REF_CLK_CTRL;                      /**< FRO 48MHz Reference Clock Control, offset: 0x960 */
  __O  uint32_t REF_CLK_CTRL_SET;                  /**< FRO 48MHz Reference Clock Control Set, offset: 0x964 */
  __O  uint32_t REF_CLK_CTRL_CLR;                  /**< FRO 48MHz Reference Clock Control Clear, offset: 0x968 */
  __IO uint32_t GDET_CTRL[SYSCON_GDETX_CTRL_COUNT]; /**< GDET Control Register, array offset: 0x96C, array step: 0x4 */
  __IO uint32_t ELS_ASSET_PROT;                    /**< ELS Asset Protection Register, offset: 0x974 */
  __IO uint32_t ELS_LOCK_CTRL;                     /**< ELS Lock Control, offset: 0x978 */
  __IO uint32_t ELS_LOCK_CTRL_DP;                  /**< ELS Lock Control DP, offset: 0x97C */
  __I  uint32_t ELS_OTP_LC_STATE;                  /**< Life Cycle State Register, offset: 0x980 */
  __I  uint32_t ELS_OTP_LC_STATE_DP;               /**< Life Cycle State Register (Duplicate), offset: 0x984 */
  __IO uint32_t ELS_TEMPORAL_STATE;                /**< ELS Temporal State, offset: 0x988 */
  __IO uint32_t ELS_KDF_MASK;                      /**< Key Derivation Function Mask, offset: 0x98C */
       uint8_t RESERVED_40[64];
  __I  uint32_t ELS_AS_CFG0;                       /**< ELS AS Configuration, offset: 0x9D0 */
  __I  uint32_t ELS_AS_CFG1;                       /**< ELS AS Configuration1, offset: 0x9D4 */
  __I  uint32_t ELS_AS_CFG2;                       /**< ELS AS Configuration2, offset: 0x9D8 */
  __I  uint32_t ELS_AS_CFG3;                       /**< ELS AS Configuration3, offset: 0x9DC */
  __I  uint32_t ELS_AS_ST0;                        /**< ELS AS State Register, offset: 0x9E0 */
  __I  uint32_t ELS_AS_ST1;                        /**< ELS AS State1, offset: 0x9E4 */
  __I  uint32_t ELS_AS_BOOT_LOG0;                  /**< Boot state captured during boot: Main ROM log, offset: 0x9E8 */
  __I  uint32_t ELS_AS_BOOT_LOG1;                  /**< Boot state captured during boot: Library log, offset: 0x9EC */
  __I  uint32_t ELS_AS_BOOT_LOG2;                  /**< Boot state captured during boot: Hardware status signals log, offset: 0x9F0 */
  __I  uint32_t ELS_AS_BOOT_LOG3;                  /**< Boot state captured during boot: Security log, offset: 0x9F4 */
  __I  uint32_t ELS_AS_FLAG0;                      /**< ELS AS Flag0, offset: 0x9F8 */
  __I  uint32_t ELS_AS_FLAG1;                      /**< ELS AS Flag1, offset: 0x9FC */
       uint8_t RESERVED_41[24];
  __IO uint32_t CLOCK_CTRL;                        /**< Clock Control, offset: 0xA18 */
       uint8_t RESERVED_42[276];
  __IO uint32_t I3C1FCLKSEL;                       /**< I3C1 Functional Clock Selection, offset: 0xB30 */
  __IO uint32_t I3C1FCLKSTCSEL;                    /**< Selects the I3C1 Time Control clock, offset: 0xB34 */
  __IO uint32_t I3C1FCLKSTCDIV;                    /**< I3C1 FCLK_STC Clock Divider, offset: 0xB38 */
  __IO uint32_t I3C1FCLKSDIV;                      /**< I3C1 FCLK Slow clock Divider, offset: 0xB3C */
  __IO uint32_t I3C1FCLKDIV;                       /**< I3C1 Functional Clock FCLK Divider, offset: 0xB40 */
  __IO uint32_t I3C1FCLKSSEL;                      /**< I3C1 FCLK Slow Selection, offset: 0xB44 */
       uint8_t RESERVED_43[8];
  __IO uint32_t ETB_STATUS;                        /**< ETB Counter Status Register, offset: 0xB50 */
  __IO uint32_t ETB_COUNTER_CTRL;                  /**< ETB Counter Control Register, offset: 0xB54 */
  __IO uint32_t ETB_COUNTER_RELOAD;                /**< ETB Counter Reload Register, offset: 0xB58 */
  __I  uint32_t ETB_COUNTER_VALUE;                 /**< ETB Counter Value Register, offset: 0xB5C */
  __IO uint32_t GRAY_CODE_LSB;                     /**< Gray to Binary Converter Gray code_gray[31:0], offset: 0xB60 */
  __IO uint32_t GRAY_CODE_MSB;                     /**< Gray to Binary Converter Gray code_gray[41:32], offset: 0xB64 */
  __I  uint32_t BINARY_CODE_LSB;                   /**< Gray to Binary Converter Binary Code [31:0], offset: 0xB68 */
  __I  uint32_t BINARY_CODE_MSB;                   /**< Gray to Binary Converter Binary Code [41:32], offset: 0xB6C */
       uint8_t RESERVED_44[660];
  __IO uint32_t AUTOCLKGATEOVERRIDE;               /**< Control Automatic Clock Gating, offset: 0xE04 */
       uint8_t RESERVED_45[36];
  __IO uint32_t AUTOCLKGATEOVERRIDEC;              /**< Control Automatic Clock Gating C, offset: 0xE2C */
       uint8_t RESERVED_46[8];
  __IO uint32_t PWM0SUBCTL;                        /**< PWM0 Submodule Control, offset: 0xE38 */
  __IO uint32_t PWM1SUBCTL;                        /**< PWM1 Submodule Control, offset: 0xE3C */
  __IO uint32_t CTIMERGLOBALSTARTEN;               /**< CTIMER Global Start Enable, offset: 0xE40 */
  __IO uint32_t ECC_ENABLE_CTRL;                   /**< RAM ECC Enable Control, offset: 0xE44 */
       uint8_t RESERVED_47[344];
  __IO uint32_t DEBUG_LOCK_EN;                     /**< Control Write Access to Security, offset: 0xFA0 */
  __IO uint32_t DEBUG_FEATURES;                    /**< Cortex Debug Features Control, offset: 0xFA4 */
  __IO uint32_t DEBUG_FEATURES_DP;                 /**< Cortex Debug Features Control (Duplicate), offset: 0xFA8 */
       uint8_t RESERVED_48[8];
  __IO uint32_t SWD_ACCESS_CPU[SYSCON_SWD_ACCESS_CPU_COUNT]; /**< CPU0 Software Debug Access..CPU1 Software Debug Access, array offset: 0xFB4, array step: 0x4 */
       uint8_t RESERVED_49[4];
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug Authentication BEACON, offset: 0xFC0 */
  __IO uint32_t SWD_ACCESS_DSP;                    /**< DSP Software Debug Access, offset: 0xFC4 */
       uint8_t RESERVED_50[40];
  __I  uint32_t JTAG_ID;                           /**< JTAG Chip ID, offset: 0xFF0 */
  __I  uint32_t DEVICE_TYPE;                       /**< Device Type, offset: 0xFF4 */
  __I  uint32_t DEVICE_ID0;                        /**< Device ID, offset: 0xFF8 */
  __I  uint32_t DIEID;                             /**< Chip Revision ID and Number, offset: 0xFFC */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name AHBMATPRIO - AHB Matrix Priority Control */
/*! @{ */

#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_MASK     (0x3U)
#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_SHIFT    (0U)
/*! PRI_CPU0_CBUS - CPU0 C-AHB bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_MASK)

#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_MASK     (0xCU)
#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_SHIFT    (2U)
/*! PRI_CPU0_SBUS - CPU0 S-AHB bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_MASK)

#define SYSCON_AHBMATPRIO_PRI_CPU1_SBUS_SmartDMA_D_MASK (0x30U)
#define SYSCON_AHBMATPRIO_PRI_CPU1_SBUS_SmartDMA_D_SHIFT (4U)
/*! PRI_CPU1_SBUS_SmartDMA_D - CPU1 S-AHB/SmartDMA-D bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_CPU1_SBUS_SmartDMA_D(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU1_SBUS_SmartDMA_D_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU1_SBUS_SmartDMA_D_MASK)

#define SYSCON_AHBMATPRIO_PRI_CPU1_CBUS_SmartDMA_I_MASK (0xC0U)
#define SYSCON_AHBMATPRIO_PRI_CPU1_CBUS_SmartDMA_I_SHIFT (6U)
/*! PRI_CPU1_CBUS_SmartDMA_I - CPU1 C-AHB/SmartDMA-I bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_CPU1_CBUS_SmartDMA_I(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU1_CBUS_SmartDMA_I_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU1_CBUS_SmartDMA_I_MASK)

#define SYSCON_AHBMATPRIO_DMA0_MASK              (0x300U)
#define SYSCON_AHBMATPRIO_DMA0_SHIFT             (8U)
/*! DMA0 - DMA0 controller bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_DMA0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_DMA0_SHIFT)) & SYSCON_AHBMATPRIO_DMA0_MASK)

#define SYSCON_AHBMATPRIO_DMA1_MASK              (0xC00U)
#define SYSCON_AHBMATPRIO_DMA1_SHIFT             (10U)
/*! DMA1 - DMA1 controller bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_DMA1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_DMA1_SHIFT)) & SYSCON_AHBMATPRIO_DMA1_MASK)

#define SYSCON_AHBMATPRIO_PRI_PKC_ELS_MASK       (0x3000U)
#define SYSCON_AHBMATPRIO_PRI_PKC_ELS_SHIFT      (12U)
/*! PRI_PKC_ELS - PKC and ELS bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_PKC_ELS(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_PKC_ELS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_PKC_ELS_MASK)

#define SYSCON_AHBMATPRIO_PRI_NPU_PQ_MASK        (0xC000U)
#define SYSCON_AHBMATPRIO_PRI_NPU_PQ_SHIFT       (14U)
/*! PRI_NPU_PQ - NPU O bus and Powerquad bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_NPU_PQ(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_NPU_PQ_SHIFT)) & SYSCON_AHBMATPRIO_PRI_NPU_PQ_MASK)

#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_I_MASK    (0x30000U)
#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_I_SHIFT   (16U)
/*! PRI_COOLFLUX_I - CoolFlux I bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_I(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_COOLFLUX_I_SHIFT)) & SYSCON_AHBMATPRIO_PRI_COOLFLUX_I_MASK)

#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_X_MASK    (0xC0000U)
#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_X_SHIFT   (18U)
/*! PRI_COOLFLUX_X - CoolFlux X bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_X(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_COOLFLUX_X_SHIFT)) & SYSCON_AHBMATPRIO_PRI_COOLFLUX_X_MASK)

#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_Y_ESPI_MASK (0x300000U)
#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_Y_ESPI_SHIFT (20U)
/*! PRI_COOLFLUX_Y_ESPI - CoolFlux Y bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_COOLFLUX_Y_ESPI(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_COOLFLUX_Y_ESPI_SHIFT)) & SYSCON_AHBMATPRIO_PRI_COOLFLUX_Y_ESPI_MASK)

#define SYSCON_AHBMATPRIO_PRI_NPU_D_MASK         (0xC00000U)
#define SYSCON_AHBMATPRIO_PRI_NPU_D_SHIFT        (22U)
/*! PRI_NPU_D - NPU D bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_NPU_D(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_NPU_D_SHIFT)) & SYSCON_AHBMATPRIO_PRI_NPU_D_MASK)

#define SYSCON_AHBMATPRIO_PRI_USB_FS_ENET_MASK   (0x3000000U)
#define SYSCON_AHBMATPRIO_PRI_USB_FS_ENET_SHIFT  (24U)
/*! PRI_USB_FS_ENET - USB-FS and ENET bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_USB_FS_ENET(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USB_FS_ENET_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USB_FS_ENET_MASK)

#define SYSCON_AHBMATPRIO_PRI_USB_HS_MASK        (0xC000000U)
#define SYSCON_AHBMATPRIO_PRI_USB_HS_SHIFT       (26U)
/*! PRI_USB_HS - USB-HS bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_USB_HS(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USB_HS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USB_HS_MASK)

#define SYSCON_AHBMATPRIO_PRI_USDHC_MASK         (0x30000000U)
#define SYSCON_AHBMATPRIO_PRI_USDHC_SHIFT        (28U)
/*! PRI_USDHC - USDHC bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_USDHC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USDHC_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USDHC_MASK)
/*! @} */

/*! @name CPU0STCKCAL - Secure CPU0 System Tick Calibration */
/*! @{ */

#define SYSCON_CPU0STCKCAL_TENMS_MASK            (0xFFFFFFU)
#define SYSCON_CPU0STCKCAL_TENMS_SHIFT           (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SYSCON_CPU0STCKCAL_TENMS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0STCKCAL_TENMS_SHIFT)) & SYSCON_CPU0STCKCAL_TENMS_MASK)

#define SYSCON_CPU0STCKCAL_SKEW_MASK             (0x1000000U)
#define SYSCON_CPU0STCKCAL_SKEW_SHIFT            (24U)
/*! SKEW - Whether the TENMS value is exact.
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is not exact or not given
 */
#define SYSCON_CPU0STCKCAL_SKEW(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0STCKCAL_SKEW_SHIFT)) & SYSCON_CPU0STCKCAL_SKEW_MASK)

#define SYSCON_CPU0STCKCAL_NOREF_MASK            (0x2000000U)
#define SYSCON_CPU0STCKCAL_NOREF_SHIFT           (25U)
/*! NOREF - Whether the device provides a reference clock to the processor.
 *  0b0..Reference clock is provided
 *  0b1..No reference clock is provided
 */
#define SYSCON_CPU0STCKCAL_NOREF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0STCKCAL_NOREF_SHIFT)) & SYSCON_CPU0STCKCAL_NOREF_MASK)
/*! @} */

/*! @name CPU0NSTCKCAL - Non-Secure CPU0 System Tick Calibration */
/*! @{ */

#define SYSCON_CPU0NSTCKCAL_TENMS_MASK           (0xFFFFFFU)
#define SYSCON_CPU0NSTCKCAL_TENMS_SHIFT          (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SYSCON_CPU0NSTCKCAL_TENMS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_TENMS_SHIFT)) & SYSCON_CPU0NSTCKCAL_TENMS_MASK)

#define SYSCON_CPU0NSTCKCAL_SKEW_MASK            (0x1000000U)
#define SYSCON_CPU0NSTCKCAL_SKEW_SHIFT           (24U)
/*! SKEW - Indicates whether the TENMS value is exact.
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is not exact or not given
 */
#define SYSCON_CPU0NSTCKCAL_SKEW(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_SKEW_SHIFT)) & SYSCON_CPU0NSTCKCAL_SKEW_MASK)

#define SYSCON_CPU0NSTCKCAL_NOREF_MASK           (0x2000000U)
#define SYSCON_CPU0NSTCKCAL_NOREF_SHIFT          (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor.
 *  0b0..Reference clock is provided
 *  0b1..No reference clock is provided
 */
#define SYSCON_CPU0NSTCKCAL_NOREF(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_NOREF_SHIFT)) & SYSCON_CPU0NSTCKCAL_NOREF_MASK)
/*! @} */

/*! @name CPU1STCKCAL - System tick calibration for CPU1 */
/*! @{ */

#define SYSCON_CPU1STCKCAL_TENMS_MASK            (0xFFFFFFU)
#define SYSCON_CPU1STCKCAL_TENMS_SHIFT           (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SYSCON_CPU1STCKCAL_TENMS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1STCKCAL_TENMS_SHIFT)) & SYSCON_CPU1STCKCAL_TENMS_MASK)

#define SYSCON_CPU1STCKCAL_SKEW_MASK             (0x1000000U)
#define SYSCON_CPU1STCKCAL_SKEW_SHIFT            (24U)
/*! SKEW - Indicates whether the TENMS value is exact.
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is not exact or not given
 */
#define SYSCON_CPU1STCKCAL_SKEW(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1STCKCAL_SKEW_SHIFT)) & SYSCON_CPU1STCKCAL_SKEW_MASK)

#define SYSCON_CPU1STCKCAL_NOREF_MASK            (0x2000000U)
#define SYSCON_CPU1STCKCAL_NOREF_SHIFT           (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor.
 *  0b0..Reference clock is provided
 *  0b1..No reference clock is provided
 */
#define SYSCON_CPU1STCKCAL_NOREF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU1STCKCAL_NOREF_SHIFT)) & SYSCON_CPU1STCKCAL_NOREF_MASK)
/*! @} */

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON_NMISRC_IRQCPU0_MASK               (0xFFU)
#define SYSCON_NMISRC_IRQCPU0_SHIFT              (0U)
/*! IRQCPU0 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for CPU0, if enabled by NMIENCPU0. */
#define SYSCON_NMISRC_IRQCPU0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQCPU0_SHIFT)) & SYSCON_NMISRC_IRQCPU0_MASK)

#define SYSCON_NMISRC_IRQCPU1_MASK               (0xFF00U)
#define SYSCON_NMISRC_IRQCPU1_SHIFT              (8U)
/*! IRQCPU1 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for CPU1, if enabled by NMIENCPU1. */
#define SYSCON_NMISRC_IRQCPU1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQCPU1_SHIFT)) & SYSCON_NMISRC_IRQCPU1_MASK)

#define SYSCON_NMISRC_NMIENCPU1_MASK             (0x40000000U)
#define SYSCON_NMISRC_NMIENCPU1_SHIFT            (30U)
/*! NMIENCPU1 - Enables the Non-Maskable Interrupt (NMI) source selected by IRQCPU1.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_NMISRC_NMIENCPU1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENCPU1_SHIFT)) & SYSCON_NMISRC_NMIENCPU1_MASK)

#define SYSCON_NMISRC_NMIENCPU0_MASK             (0x80000000U)
#define SYSCON_NMISRC_NMIENCPU0_SHIFT            (31U)
/*! NMIENCPU0 - Enables the Non-Maskable Interrupt (NMI) source selected by IRQCPU0.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_NMISRC_NMIENCPU0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENCPU0_SHIFT)) & SYSCON_NMISRC_NMIENCPU0_MASK)
/*! @} */

/*! @name PRESETCTRL0 - Peripheral Reset Control 0 */
/*! @{ */

#define SYSCON_PRESETCTRL0_FMU_RST_MASK          (0x200U)
#define SYSCON_PRESETCTRL0_FMU_RST_SHIFT         (9U)
/*! FMU_RST - Flash management unit reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_FMU_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FMU_RST_SHIFT)) & SYSCON_PRESETCTRL0_FMU_RST_MASK)

#define SYSCON_PRESETCTRL0_FLEXSPI_RST_MASK      (0x800U)
#define SYSCON_PRESETCTRL0_FLEXSPI_RST_SHIFT     (11U)
/*! FLEXSPI_RST - FlexSPI reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_FLEXSPI_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FLEXSPI_RST_SHIFT)) & SYSCON_PRESETCTRL0_FLEXSPI_RST_MASK)

#define SYSCON_PRESETCTRL0_MUX_RST_MASK          (0x1000U)
#define SYSCON_PRESETCTRL0_MUX_RST_SHIFT         (12U)
/*! MUX_RST - INPUTMUX reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_MUX_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_MUX_RST_SHIFT)) & SYSCON_PRESETCTRL0_MUX_RST_MASK)

#define SYSCON_PRESETCTRL0_PORT0_RST_MASK        (0x2000U)
#define SYSCON_PRESETCTRL0_PORT0_RST_SHIFT       (13U)
/*! PORT0_RST - PORT0 controller reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_PORT0_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PORT0_RST_SHIFT)) & SYSCON_PRESETCTRL0_PORT0_RST_MASK)

#define SYSCON_PRESETCTRL0_PORT1_RST_MASK        (0x4000U)
#define SYSCON_PRESETCTRL0_PORT1_RST_SHIFT       (14U)
/*! PORT1_RST - PORT1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_PORT1_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PORT1_RST_SHIFT)) & SYSCON_PRESETCTRL0_PORT1_RST_MASK)

#define SYSCON_PRESETCTRL0_PORT2_RST_MASK        (0x8000U)
#define SYSCON_PRESETCTRL0_PORT2_RST_SHIFT       (15U)
/*! PORT2_RST - PORT2 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_PORT2_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PORT2_RST_SHIFT)) & SYSCON_PRESETCTRL0_PORT2_RST_MASK)

#define SYSCON_PRESETCTRL0_PORT3_RST_MASK        (0x10000U)
#define SYSCON_PRESETCTRL0_PORT3_RST_SHIFT       (16U)
/*! PORT3_RST - PORT3 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_PORT3_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PORT3_RST_SHIFT)) & SYSCON_PRESETCTRL0_PORT3_RST_MASK)

#define SYSCON_PRESETCTRL0_PORT4_RST_MASK        (0x20000U)
#define SYSCON_PRESETCTRL0_PORT4_RST_SHIFT       (17U)
/*! PORT4_RST - PORT4 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_PORT4_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PORT4_RST_SHIFT)) & SYSCON_PRESETCTRL0_PORT4_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO0_RST_MASK        (0x80000U)
#define SYSCON_PRESETCTRL0_GPIO0_RST_SHIFT       (19U)
/*! GPIO0_RST - GPIO0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_GPIO0_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO0_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO0_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO1_RST_MASK        (0x100000U)
#define SYSCON_PRESETCTRL0_GPIO1_RST_SHIFT       (20U)
/*! GPIO1_RST - GPIO1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_GPIO1_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO1_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO1_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO2_RST_MASK        (0x200000U)
#define SYSCON_PRESETCTRL0_GPIO2_RST_SHIFT       (21U)
/*! GPIO2_RST - GPIO2 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_GPIO2_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO2_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO2_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO3_RST_MASK        (0x400000U)
#define SYSCON_PRESETCTRL0_GPIO3_RST_SHIFT       (22U)
/*! GPIO3_RST - GPIO3 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_GPIO3_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO3_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO3_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO4_RST_MASK        (0x800000U)
#define SYSCON_PRESETCTRL0_GPIO4_RST_SHIFT       (23U)
/*! GPIO4_RST - GPIO4 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_GPIO4_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO4_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO4_RST_MASK)

#define SYSCON_PRESETCTRL0_PINT_RST_MASK         (0x2000000U)
#define SYSCON_PRESETCTRL0_PINT_RST_SHIFT        (25U)
/*! PINT_RST - PINT reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_PINT_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PINT_RST_SHIFT)) & SYSCON_PRESETCTRL0_PINT_RST_MASK)

#define SYSCON_PRESETCTRL0_DMA0_RST_MASK         (0x4000000U)
#define SYSCON_PRESETCTRL0_DMA0_RST_SHIFT        (26U)
/*! DMA0_RST - DMA0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_DMA0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_DMA0_RST_SHIFT)) & SYSCON_PRESETCTRL0_DMA0_RST_MASK)

#define SYSCON_PRESETCTRL0_CRC_RST_MASK          (0x8000000U)
#define SYSCON_PRESETCTRL0_CRC_RST_SHIFT         (27U)
/*! CRC_RST - CRC reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_CRC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CRC_RST_SHIFT)) & SYSCON_PRESETCTRL0_CRC_RST_MASK)

#define SYSCON_PRESETCTRL0_MAILBOX_RST_MASK      (0x80000000U)
#define SYSCON_PRESETCTRL0_MAILBOX_RST_SHIFT     (31U)
/*! MAILBOX_RST - Inter-CPU communication Mailbox reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL0_MAILBOX_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_MAILBOX_RST_SHIFT)) & SYSCON_PRESETCTRL0_MAILBOX_RST_MASK)
/*! @} */

/*! @name PRESETCTRL1 - Peripheral Reset Control 1 */
/*! @{ */

#define SYSCON_PRESETCTRL1_MRT_RST_MASK          (0x1U)
#define SYSCON_PRESETCTRL1_MRT_RST_SHIFT         (0U)
/*! MRT_RST - MRT reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_MRT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_MRT_RST_SHIFT)) & SYSCON_PRESETCTRL1_MRT_RST_MASK)

#define SYSCON_PRESETCTRL1_OSTIMER_RST_MASK      (0x2U)
#define SYSCON_PRESETCTRL1_OSTIMER_RST_SHIFT     (1U)
/*! OSTIMER_RST - OS Event Timer reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_OSTIMER_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_OSTIMER_RST_SHIFT)) & SYSCON_PRESETCTRL1_OSTIMER_RST_MASK)

#define SYSCON_PRESETCTRL1_SCT_RST_MASK          (0x4U)
#define SYSCON_PRESETCTRL1_SCT_RST_SHIFT         (2U)
/*! SCT_RST - SCT reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_SCT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_SCT_RST_SHIFT)) & SYSCON_PRESETCTRL1_SCT_RST_MASK)

#define SYSCON_PRESETCTRL1_ADC0_RST_MASK         (0x8U)
#define SYSCON_PRESETCTRL1_ADC0_RST_SHIFT        (3U)
/*! ADC0_RST - ADC0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_ADC0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_ADC0_RST_SHIFT)) & SYSCON_PRESETCTRL1_ADC0_RST_MASK)

#define SYSCON_PRESETCTRL1_ADC1_RST_MASK         (0x10U)
#define SYSCON_PRESETCTRL1_ADC1_RST_SHIFT        (4U)
/*! ADC1_RST - ADC1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_ADC1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_ADC1_RST_SHIFT)) & SYSCON_PRESETCTRL1_ADC1_RST_MASK)

#define SYSCON_PRESETCTRL1_DAC0_RST_MASK         (0x20U)
#define SYSCON_PRESETCTRL1_DAC0_RST_SHIFT        (5U)
/*! DAC0_RST - DAC0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_DAC0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_DAC0_RST_SHIFT)) & SYSCON_PRESETCTRL1_DAC0_RST_MASK)

#define SYSCON_PRESETCTRL1_RTC_RST_MASK          (0x40U)
#define SYSCON_PRESETCTRL1_RTC_RST_SHIFT         (6U)
/*! RTC_RST - RTC reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_RTC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_RTC_RST_SHIFT)) & SYSCON_PRESETCTRL1_RTC_RST_MASK)

#define SYSCON_PRESETCTRL1_EVSIM0_RST_MASK       (0x100U)
#define SYSCON_PRESETCTRL1_EVSIM0_RST_SHIFT      (8U)
/*! EVSIM0_RST - EVSIM0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_EVSIM0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_EVSIM0_RST_SHIFT)) & SYSCON_PRESETCTRL1_EVSIM0_RST_MASK)

#define SYSCON_PRESETCTRL1_EVSIM1_RST_MASK       (0x200U)
#define SYSCON_PRESETCTRL1_EVSIM1_RST_SHIFT      (9U)
/*! EVSIM1_RST - EVSIM1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_EVSIM1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_EVSIM1_RST_SHIFT)) & SYSCON_PRESETCTRL1_EVSIM1_RST_MASK)

#define SYSCON_PRESETCTRL1_UTICK_RST_MASK        (0x400U)
#define SYSCON_PRESETCTRL1_UTICK_RST_SHIFT       (10U)
/*! UTICK_RST - UTICK reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_UTICK_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_UTICK_RST_SHIFT)) & SYSCON_PRESETCTRL1_UTICK_RST_MASK)

#define SYSCON_PRESETCTRL1_FC0_RST_MASK          (0x800U)
#define SYSCON_PRESETCTRL1_FC0_RST_SHIFT         (11U)
/*! FC0_RST - LP_FLEXCOMM0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC0_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC0_RST_MASK)

#define SYSCON_PRESETCTRL1_FC1_RST_MASK          (0x1000U)
#define SYSCON_PRESETCTRL1_FC1_RST_SHIFT         (12U)
/*! FC1_RST - LP_FLEXCOMM1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC1_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC1_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC1_RST_MASK)

#define SYSCON_PRESETCTRL1_FC2_RST_MASK          (0x2000U)
#define SYSCON_PRESETCTRL1_FC2_RST_SHIFT         (13U)
/*! FC2_RST - LP_FLEXCOMM2 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC2_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC2_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC2_RST_MASK)

#define SYSCON_PRESETCTRL1_FC3_RST_MASK          (0x4000U)
#define SYSCON_PRESETCTRL1_FC3_RST_SHIFT         (14U)
/*! FC3_RST - LP_FLEXCOMM3 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC3_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC3_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC3_RST_MASK)

#define SYSCON_PRESETCTRL1_FC4_RST_MASK          (0x8000U)
#define SYSCON_PRESETCTRL1_FC4_RST_SHIFT         (15U)
/*! FC4_RST - LP_FLEXCOMM4 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC4_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC4_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC4_RST_MASK)

#define SYSCON_PRESETCTRL1_FC5_RST_MASK          (0x10000U)
#define SYSCON_PRESETCTRL1_FC5_RST_SHIFT         (16U)
/*! FC5_RST - LP_FLEXCOMM5 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC5_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC5_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC5_RST_MASK)

#define SYSCON_PRESETCTRL1_FC6_RST_MASK          (0x20000U)
#define SYSCON_PRESETCTRL1_FC6_RST_SHIFT         (17U)
/*! FC6_RST - LP_FLEXCOMM6 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC6_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC6_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC6_RST_MASK)

#define SYSCON_PRESETCTRL1_FC7_RST_MASK          (0x40000U)
#define SYSCON_PRESETCTRL1_FC7_RST_SHIFT         (18U)
/*! FC7_RST - LP_FLEXCOMM7 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC7_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC7_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC7_RST_MASK)

#define SYSCON_PRESETCTRL1_FC8_RST_MASK          (0x80000U)
#define SYSCON_PRESETCTRL1_FC8_RST_SHIFT         (19U)
/*! FC8_RST - LP_FLEXCOMM8 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC8_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC8_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC8_RST_MASK)

#define SYSCON_PRESETCTRL1_FC9_RST_MASK          (0x100000U)
#define SYSCON_PRESETCTRL1_FC9_RST_SHIFT         (20U)
/*! FC9_RST - LP_FLEXCOMM9 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_FC9_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC9_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC9_RST_MASK)

#define SYSCON_PRESETCTRL1_MICFIL_RST_MASK       (0x200000U)
#define SYSCON_PRESETCTRL1_MICFIL_RST_SHIFT      (21U)
/*! MICFIL_RST - MICFIL reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_MICFIL_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_MICFIL_RST_SHIFT)) & SYSCON_PRESETCTRL1_MICFIL_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER2_RST_MASK       (0x400000U)
#define SYSCON_PRESETCTRL1_TIMER2_RST_SHIFT      (22U)
/*! TIMER2_RST - CTIMER2 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_TIMER2_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER2_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER2_RST_MASK)

#define SYSCON_PRESETCTRL1_USB0_FS_DCD_RST_MASK  (0x1000000U)
#define SYSCON_PRESETCTRL1_USB0_FS_DCD_RST_SHIFT (24U)
/*! USB0_FS_DCD_RST - USB FS DCD reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_USB0_FS_DCD_RST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_USB0_FS_DCD_RST_SHIFT)) & SYSCON_PRESETCTRL1_USB0_FS_DCD_RST_MASK)

#define SYSCON_PRESETCTRL1_USB0_FS_RST_MASK      (0x2000000U)
#define SYSCON_PRESETCTRL1_USB0_FS_RST_SHIFT     (25U)
/*! USB0_FS_RST - USB FS reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_USB0_FS_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_USB0_FS_RST_SHIFT)) & SYSCON_PRESETCTRL1_USB0_FS_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER0_RST_MASK       (0x4000000U)
#define SYSCON_PRESETCTRL1_TIMER0_RST_SHIFT      (26U)
/*! TIMER0_RST - CTIMER0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_TIMER0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER0_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER0_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER1_RST_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL1_TIMER1_RST_SHIFT      (27U)
/*! TIMER1_RST - CTIMER1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_TIMER1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER1_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER1_RST_MASK)

#define SYSCON_PRESETCTRL1_SmartDMA_RST_MASK     (0x80000000U)
#define SYSCON_PRESETCTRL1_SmartDMA_RST_SHIFT    (31U)
/*! SmartDMA_RST - SmartDMA reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL1_SmartDMA_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_SmartDMA_RST_SHIFT)) & SYSCON_PRESETCTRL1_SmartDMA_RST_MASK)
/*! @} */

/*! @name PRESETCTRL2 - Peripheral Reset Control 2 */
/*! @{ */

#define SYSCON_PRESETCTRL2_DMA1_RST_MASK         (0x2U)
#define SYSCON_PRESETCTRL2_DMA1_RST_SHIFT        (1U)
/*! DMA1_RST - DMA1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_DMA1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_DMA1_RST_SHIFT)) & SYSCON_PRESETCTRL2_DMA1_RST_MASK)

#define SYSCON_PRESETCTRL2_ENET_RST_MASK         (0x4U)
#define SYSCON_PRESETCTRL2_ENET_RST_SHIFT        (2U)
/*! ENET_RST - Ethernet reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_ENET_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_ENET_RST_SHIFT)) & SYSCON_PRESETCTRL2_ENET_RST_MASK)

#define SYSCON_PRESETCTRL2_USDHC_RST_MASK        (0x8U)
#define SYSCON_PRESETCTRL2_USDHC_RST_SHIFT       (3U)
/*! USDHC_RST - uSDHC reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_USDHC_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_USDHC_RST_SHIFT)) & SYSCON_PRESETCTRL2_USDHC_RST_MASK)

#define SYSCON_PRESETCTRL2_FLEXIO_RST_MASK       (0x10U)
#define SYSCON_PRESETCTRL2_FLEXIO_RST_SHIFT      (4U)
/*! FLEXIO_RST - FLEXIO reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_FLEXIO_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_FLEXIO_RST_SHIFT)) & SYSCON_PRESETCTRL2_FLEXIO_RST_MASK)

#define SYSCON_PRESETCTRL2_SAI0_RST_MASK         (0x20U)
#define SYSCON_PRESETCTRL2_SAI0_RST_SHIFT        (5U)
/*! SAI0_RST - SAI0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_SAI0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_SAI0_RST_SHIFT)) & SYSCON_PRESETCTRL2_SAI0_RST_MASK)

#define SYSCON_PRESETCTRL2_SAI1_RST_MASK         (0x40U)
#define SYSCON_PRESETCTRL2_SAI1_RST_SHIFT        (6U)
/*! SAI1_RST - SAI1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_SAI1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_SAI1_RST_SHIFT)) & SYSCON_PRESETCTRL2_SAI1_RST_MASK)

#define SYSCON_PRESETCTRL2_TRO_RST_MASK          (0x80U)
#define SYSCON_PRESETCTRL2_TRO_RST_SHIFT         (7U)
/*! TRO_RST - TRO reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_TRO_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TRO_RST_SHIFT)) & SYSCON_PRESETCTRL2_TRO_RST_MASK)

#define SYSCON_PRESETCTRL2_FREQME_RST_MASK       (0x100U)
#define SYSCON_PRESETCTRL2_FREQME_RST_SHIFT      (8U)
/*! FREQME_RST - FREQME reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_FREQME_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_FREQME_RST_SHIFT)) & SYSCON_PRESETCTRL2_FREQME_RST_MASK)

#define SYSCON_PRESETCTRL2_TRNG_RST_MASK         (0x2000U)
#define SYSCON_PRESETCTRL2_TRNG_RST_SHIFT        (13U)
/*! TRNG_RST - TRNG reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_TRNG_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TRNG_RST_SHIFT)) & SYSCON_PRESETCTRL2_TRNG_RST_MASK)

#define SYSCON_PRESETCTRL2_FLEXCAN0_RST_MASK     (0x4000U)
#define SYSCON_PRESETCTRL2_FLEXCAN0_RST_SHIFT    (14U)
/*! FLEXCAN0_RST - CAN0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_FLEXCAN0_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_FLEXCAN0_RST_SHIFT)) & SYSCON_PRESETCTRL2_FLEXCAN0_RST_MASK)

#define SYSCON_PRESETCTRL2_FLEXCAN1_RST_MASK     (0x8000U)
#define SYSCON_PRESETCTRL2_FLEXCAN1_RST_SHIFT    (15U)
/*! FLEXCAN1_RST - CAN1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_FLEXCAN1_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_FLEXCAN1_RST_SHIFT)) & SYSCON_PRESETCTRL2_FLEXCAN1_RST_MASK)

#define SYSCON_PRESETCTRL2_USB_HS_RST_MASK       (0x10000U)
#define SYSCON_PRESETCTRL2_USB_HS_RST_SHIFT      (16U)
/*! USB_HS_RST - USB HS reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_USB_HS_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_USB_HS_RST_SHIFT)) & SYSCON_PRESETCTRL2_USB_HS_RST_MASK)

#define SYSCON_PRESETCTRL2_USB_HS_PHY_RST_MASK   (0x20000U)
#define SYSCON_PRESETCTRL2_USB_HS_PHY_RST_SHIFT  (17U)
/*! USB_HS_PHY_RST - USB HS PHY reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_USB_HS_PHY_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_USB_HS_PHY_RST_SHIFT)) & SYSCON_PRESETCTRL2_USB_HS_PHY_RST_MASK)

#define SYSCON_PRESETCTRL2_PQ_RST_MASK           (0x80000U)
#define SYSCON_PRESETCTRL2_PQ_RST_SHIFT          (19U)
/*! PQ_RST - PowerQuad reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_PQ_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PQ_RST_SHIFT)) & SYSCON_PRESETCTRL2_PQ_RST_MASK)

#define SYSCON_PRESETCTRL2_PLU_RST_MASK          (0x100000U)
#define SYSCON_PRESETCTRL2_PLU_RST_SHIFT         (20U)
/*! PLU_RST - PLU reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_PLU_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PLU_RST_SHIFT)) & SYSCON_PRESETCTRL2_PLU_RST_MASK)

#define SYSCON_PRESETCTRL2_TIMER3_RST_MASK       (0x200000U)
#define SYSCON_PRESETCTRL2_TIMER3_RST_SHIFT      (21U)
/*! TIMER3_RST - CTIMER3 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_TIMER3_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TIMER3_RST_SHIFT)) & SYSCON_PRESETCTRL2_TIMER3_RST_MASK)

#define SYSCON_PRESETCTRL2_TIMER4_RST_MASK       (0x400000U)
#define SYSCON_PRESETCTRL2_TIMER4_RST_SHIFT      (22U)
/*! TIMER4_RST - CTIMER4 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_TIMER4_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TIMER4_RST_SHIFT)) & SYSCON_PRESETCTRL2_TIMER4_RST_MASK)

#define SYSCON_PRESETCTRL2_PUF_RST_MASK          (0x800000U)
#define SYSCON_PRESETCTRL2_PUF_RST_SHIFT         (23U)
/*! PUF_RST - PUF reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_PUF_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PUF_RST_SHIFT)) & SYSCON_PRESETCTRL2_PUF_RST_MASK)

#define SYSCON_PRESETCTRL2_PKC_RST_MASK          (0x1000000U)
#define SYSCON_PRESETCTRL2_PKC_RST_SHIFT         (24U)
/*! PKC_RST - PKC reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_PKC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PKC_RST_SHIFT)) & SYSCON_PRESETCTRL2_PKC_RST_MASK)

#define SYSCON_PRESETCTRL2_SM3_RST_MASK          (0x40000000U)
#define SYSCON_PRESETCTRL2_SM3_RST_SHIFT         (30U)
/*! SM3_RST - SM3 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL2_SM3_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_SM3_RST_SHIFT)) & SYSCON_PRESETCTRL2_SM3_RST_MASK)
/*! @} */

/*! @name PRESETCTRL3 - Peripheral Reset Control 3 */
/*! @{ */

#define SYSCON_PRESETCTRL3_I3C0_RST_MASK         (0x1U)
#define SYSCON_PRESETCTRL3_I3C0_RST_SHIFT        (0U)
/*! I3C0_RST - I3C0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_I3C0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_I3C0_RST_SHIFT)) & SYSCON_PRESETCTRL3_I3C0_RST_MASK)

#define SYSCON_PRESETCTRL3_I3C1_RST_MASK         (0x2U)
#define SYSCON_PRESETCTRL3_I3C1_RST_SHIFT        (1U)
/*! I3C1_RST - I3C1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_I3C1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_I3C1_RST_SHIFT)) & SYSCON_PRESETCTRL3_I3C1_RST_MASK)

#define SYSCON_PRESETCTRL3_SINC_RST_MASK         (0x4U)
#define SYSCON_PRESETCTRL3_SINC_RST_SHIFT        (2U)
/*! SINC_RST - SINC reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_SINC_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_SINC_RST_SHIFT)) & SYSCON_PRESETCTRL3_SINC_RST_MASK)

#define SYSCON_PRESETCTRL3_COOLFLUX_RST_MASK     (0x8U)
#define SYSCON_PRESETCTRL3_COOLFLUX_RST_SHIFT    (3U)
/*! COOLFLUX_RST - CoolFlux reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_COOLFLUX_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_COOLFLUX_RST_SHIFT)) & SYSCON_PRESETCTRL3_COOLFLUX_RST_MASK)

#define SYSCON_PRESETCTRL3_QDC0_RST_MASK         (0x10U)
#define SYSCON_PRESETCTRL3_QDC0_RST_SHIFT        (4U)
/*! QDC0_RST - QDC0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_QDC0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_QDC0_RST_SHIFT)) & SYSCON_PRESETCTRL3_QDC0_RST_MASK)

#define SYSCON_PRESETCTRL3_QDC1_RST_MASK         (0x20U)
#define SYSCON_PRESETCTRL3_QDC1_RST_SHIFT        (5U)
/*! QDC1_RST - QDC1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_QDC1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_QDC1_RST_SHIFT)) & SYSCON_PRESETCTRL3_QDC1_RST_MASK)

#define SYSCON_PRESETCTRL3_PWM0_RST_MASK         (0x40U)
#define SYSCON_PRESETCTRL3_PWM0_RST_SHIFT        (6U)
/*! PWM0_RST - PWM0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_PWM0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_PWM0_RST_SHIFT)) & SYSCON_PRESETCTRL3_PWM0_RST_MASK)

#define SYSCON_PRESETCTRL3_PWM1_RST_MASK         (0x80U)
#define SYSCON_PRESETCTRL3_PWM1_RST_SHIFT        (7U)
/*! PWM1_RST - PWM1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_PWM1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_PWM1_RST_SHIFT)) & SYSCON_PRESETCTRL3_PWM1_RST_MASK)

#define SYSCON_PRESETCTRL3_AOI0_RST_MASK         (0x100U)
#define SYSCON_PRESETCTRL3_AOI0_RST_SHIFT        (8U)
/*! AOI0_RST - AOI0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_AOI0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_AOI0_RST_SHIFT)) & SYSCON_PRESETCTRL3_AOI0_RST_MASK)

#define SYSCON_PRESETCTRL3_DAC1_RST_MASK         (0x800U)
#define SYSCON_PRESETCTRL3_DAC1_RST_SHIFT        (11U)
/*! DAC1_RST - DAC1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_DAC1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_DAC1_RST_SHIFT)) & SYSCON_PRESETCTRL3_DAC1_RST_MASK)

#define SYSCON_PRESETCTRL3_DAC2_RST_MASK         (0x1000U)
#define SYSCON_PRESETCTRL3_DAC2_RST_SHIFT        (12U)
/*! DAC2_RST - DAC2 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_DAC2_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_DAC2_RST_SHIFT)) & SYSCON_PRESETCTRL3_DAC2_RST_MASK)

#define SYSCON_PRESETCTRL3_OPAMP0_RST_MASK       (0x2000U)
#define SYSCON_PRESETCTRL3_OPAMP0_RST_SHIFT      (13U)
/*! OPAMP0_RST - OPAMP0 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_OPAMP0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_OPAMP0_RST_SHIFT)) & SYSCON_PRESETCTRL3_OPAMP0_RST_MASK)

#define SYSCON_PRESETCTRL3_OPAMP1_RST_MASK       (0x4000U)
#define SYSCON_PRESETCTRL3_OPAMP1_RST_SHIFT      (14U)
/*! OPAMP1_RST - OPAMP1 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_OPAMP1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_OPAMP1_RST_SHIFT)) & SYSCON_PRESETCTRL3_OPAMP1_RST_MASK)

#define SYSCON_PRESETCTRL3_OPAMP2_RST_MASK       (0x8000U)
#define SYSCON_PRESETCTRL3_OPAMP2_RST_SHIFT      (15U)
/*! OPAMP2_RST - OPAMP2 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_OPAMP2_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_OPAMP2_RST_SHIFT)) & SYSCON_PRESETCTRL3_OPAMP2_RST_MASK)

#define SYSCON_PRESETCTRL3_CMP2_RST_MASK         (0x40000U)
#define SYSCON_PRESETCTRL3_CMP2_RST_SHIFT        (18U)
/*! CMP2_RST - CMP2 reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_CMP2_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_CMP2_RST_SHIFT)) & SYSCON_PRESETCTRL3_CMP2_RST_MASK)

#define SYSCON_PRESETCTRL3_VREF_RST_MASK         (0x80000U)
#define SYSCON_PRESETCTRL3_VREF_RST_SHIFT        (19U)
/*! VREF_RST - VREF reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_VREF_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_VREF_RST_SHIFT)) & SYSCON_PRESETCTRL3_VREF_RST_MASK)

#define SYSCON_PRESETCTRL3_COOLFLUX_APB_RST_MASK (0x100000U)
#define SYSCON_PRESETCTRL3_COOLFLUX_APB_RST_SHIFT (20U)
/*! COOLFLUX_APB_RST - CoolFlux APB reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_COOLFLUX_APB_RST(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_COOLFLUX_APB_RST_SHIFT)) & SYSCON_PRESETCTRL3_COOLFLUX_APB_RST_MASK)

#define SYSCON_PRESETCTRL3_NPU_RST_MASK          (0x200000U)
#define SYSCON_PRESETCTRL3_NPU_RST_SHIFT         (21U)
/*! NPU_RST - NPU reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_NPU_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_NPU_RST_SHIFT)) & SYSCON_PRESETCTRL3_NPU_RST_MASK)

#define SYSCON_PRESETCTRL3_TSI_RST_MASK          (0x400000U)
#define SYSCON_PRESETCTRL3_TSI_RST_SHIFT         (22U)
/*! TSI_RST - TSI reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_TSI_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_TSI_RST_SHIFT)) & SYSCON_PRESETCTRL3_TSI_RST_MASK)

#define SYSCON_PRESETCTRL3_EWM_RST_MASK          (0x800000U)
#define SYSCON_PRESETCTRL3_EWM_RST_SHIFT         (23U)
/*! EWM_RST - EWM reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_EWM_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_EWM_RST_SHIFT)) & SYSCON_PRESETCTRL3_EWM_RST_MASK)

#define SYSCON_PRESETCTRL3_EIM_RST_MASK          (0x1000000U)
#define SYSCON_PRESETCTRL3_EIM_RST_SHIFT         (24U)
/*! EIM_RST - EIM reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_EIM_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_EIM_RST_SHIFT)) & SYSCON_PRESETCTRL3_EIM_RST_MASK)

#define SYSCON_PRESETCTRL3_SEMA42_RST_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL3_SEMA42_RST_SHIFT      (27U)
/*! SEMA42_RST - Semaphore reset control
 *  0b0..Block is not reset
 *  0b1..Block is reset
 */
#define SYSCON_PRESETCTRL3_SEMA42_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_SEMA42_RST_SHIFT)) & SYSCON_PRESETCTRL3_SEMA42_RST_MASK)
/*! @} */

/*! @name PRESETCTRLSET - Peripheral Reset Control Set */
/*! @{ */

#define SYSCON_PRESETCTRLSET_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLSET_DATA_SHIFT          (0U)
/*! DATA - Data array value, refer to corresponding position in PRESETCTRLn. */
#define SYSCON_PRESETCTRLSET_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLSET_DATA_SHIFT)) & SYSCON_PRESETCTRLSET_DATA_MASK)
/*! @} */

/*! @name PRESETCTRLCLR - Peripheral Reset Control Clear */
/*! @{ */

#define SYSCON_PRESETCTRLCLR_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLCLR_DATA_SHIFT          (0U)
/*! DATA - Data array value, refer to corresponding position in PRESETCTRLn. */
#define SYSCON_PRESETCTRLCLR_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLCLR_DATA_SHIFT)) & SYSCON_PRESETCTRLCLR_DATA_MASK)
/*! @} */

/*! @name AHBCLKCTRL0 - AHB Clock Control 0 */
/*! @{ */

#define SYSCON_AHBCLKCTRL0_ROM_MASK              (0x2U)
#define SYSCON_AHBCLKCTRL0_ROM_SHIFT             (1U)
/*! ROM - Enables the clock for the ROM
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_ROM(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_ROM_SHIFT)) & SYSCON_AHBCLKCTRL0_ROM_MASK)

#define SYSCON_AHBCLKCTRL0_RAMB_CTRL_MASK        (0x4U)
#define SYSCON_AHBCLKCTRL0_RAMB_CTRL_SHIFT       (2U)
/*! RAMB_CTRL - Enables the clock for the RAMB Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_RAMB_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RAMB_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL0_RAMB_CTRL_MASK)

#define SYSCON_AHBCLKCTRL0_RAMC_CTRL_MASK        (0x8U)
#define SYSCON_AHBCLKCTRL0_RAMC_CTRL_SHIFT       (3U)
/*! RAMC_CTRL - Enables the clock for the RAMC Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_RAMC_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RAMC_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL0_RAMC_CTRL_MASK)

#define SYSCON_AHBCLKCTRL0_RAMD_CTRL_MASK        (0x10U)
#define SYSCON_AHBCLKCTRL0_RAMD_CTRL_SHIFT       (4U)
/*! RAMD_CTRL - Enables the clock for the RAMD Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_RAMD_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RAMD_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL0_RAMD_CTRL_MASK)

#define SYSCON_AHBCLKCTRL0_RAME_CTRL_MASK        (0x20U)
#define SYSCON_AHBCLKCTRL0_RAME_CTRL_SHIFT       (5U)
/*! RAME_CTRL - Enables the clock for the RAME Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_RAME_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RAME_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL0_RAME_CTRL_MASK)

#define SYSCON_AHBCLKCTRL0_RAMF_CTRL_MASK        (0x40U)
#define SYSCON_AHBCLKCTRL0_RAMF_CTRL_SHIFT       (6U)
/*! RAMF_CTRL - Enables the clock for the RAMF Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_RAMF_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RAMF_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL0_RAMF_CTRL_MASK)

#define SYSCON_AHBCLKCTRL0_RAMG_CTRL_MASK        (0x80U)
#define SYSCON_AHBCLKCTRL0_RAMG_CTRL_SHIFT       (7U)
/*! RAMG_CTRL - Enables the clock for the RAMG Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_RAMG_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RAMG_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL0_RAMG_CTRL_MASK)

#define SYSCON_AHBCLKCTRL0_RAMH_CTRL_MASK        (0x100U)
#define SYSCON_AHBCLKCTRL0_RAMH_CTRL_SHIFT       (8U)
/*! RAMH_CTRL - Enables the clock for the RAMH Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_RAMH_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RAMH_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL0_RAMH_CTRL_MASK)

#define SYSCON_AHBCLKCTRL0_FMU_MASK              (0x200U)
#define SYSCON_AHBCLKCTRL0_FMU_SHIFT             (9U)
/*! FMU - Enables the clock for the Flash Management Unit
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_FMU(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_FMU_SHIFT)) & SYSCON_AHBCLKCTRL0_FMU_MASK)

#define SYSCON_AHBCLKCTRL0_FMC_MASK              (0x400U)
#define SYSCON_AHBCLKCTRL0_FMC_SHIFT             (10U)
/*! FMC - Enables the clock for the Flash Memory Controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_FMC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_FMC_SHIFT)) & SYSCON_AHBCLKCTRL0_FMC_MASK)

#define SYSCON_AHBCLKCTRL0_FLEXSPI_MASK          (0x800U)
#define SYSCON_AHBCLKCTRL0_FLEXSPI_SHIFT         (11U)
/*! FLEXSPI - Enables the clock for FlexSPI
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_FLEXSPI(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_FLEXSPI_SHIFT)) & SYSCON_AHBCLKCTRL0_FLEXSPI_MASK)

#define SYSCON_AHBCLKCTRL0_MUX_MASK              (0x1000U)
#define SYSCON_AHBCLKCTRL0_MUX_SHIFT             (12U)
/*! MUX - Enables the clock for INPUTMUX
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_MUX(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_MUX_SHIFT)) & SYSCON_AHBCLKCTRL0_MUX_MASK)

#define SYSCON_AHBCLKCTRL0_PORT0_MASK            (0x2000U)
#define SYSCON_AHBCLKCTRL0_PORT0_SHIFT           (13U)
/*! PORT0 - Enables the clock for PORT0 controller
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_PORT0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_PORT0_SHIFT)) & SYSCON_AHBCLKCTRL0_PORT0_MASK)

#define SYSCON_AHBCLKCTRL0_PORT1_MASK            (0x4000U)
#define SYSCON_AHBCLKCTRL0_PORT1_SHIFT           (14U)
/*! PORT1 - Enables the clock for PORT1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_PORT1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_PORT1_SHIFT)) & SYSCON_AHBCLKCTRL0_PORT1_MASK)

#define SYSCON_AHBCLKCTRL0_PORT2_MASK            (0x8000U)
#define SYSCON_AHBCLKCTRL0_PORT2_SHIFT           (15U)
/*! PORT2 - Enables the clock for PORT2
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_PORT2(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_PORT2_SHIFT)) & SYSCON_AHBCLKCTRL0_PORT2_MASK)

#define SYSCON_AHBCLKCTRL0_PORT3_MASK            (0x10000U)
#define SYSCON_AHBCLKCTRL0_PORT3_SHIFT           (16U)
/*! PORT3 - Enables the clock for PORT3
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_PORT3(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_PORT3_SHIFT)) & SYSCON_AHBCLKCTRL0_PORT3_MASK)

#define SYSCON_AHBCLKCTRL0_PORT4_MASK            (0x20000U)
#define SYSCON_AHBCLKCTRL0_PORT4_SHIFT           (17U)
/*! PORT4 - Enables the clock for PORT4
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_PORT4(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_PORT4_SHIFT)) & SYSCON_AHBCLKCTRL0_PORT4_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO0_MASK            (0x80000U)
#define SYSCON_AHBCLKCTRL0_GPIO0_SHIFT           (19U)
/*! GPIO0 - Enables the clock for GPIO0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_GPIO0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO0_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO0_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO1_MASK            (0x100000U)
#define SYSCON_AHBCLKCTRL0_GPIO1_SHIFT           (20U)
/*! GPIO1 - Enables the clock for GPIO1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_GPIO1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO1_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO1_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO2_MASK            (0x200000U)
#define SYSCON_AHBCLKCTRL0_GPIO2_SHIFT           (21U)
/*! GPIO2 - Enables the clock for GPIO2
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_GPIO2(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO2_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO2_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO3_MASK            (0x400000U)
#define SYSCON_AHBCLKCTRL0_GPIO3_SHIFT           (22U)
/*! GPIO3 - Enables the clock for GPIO3
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_GPIO3(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO3_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO3_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO4_MASK            (0x800000U)
#define SYSCON_AHBCLKCTRL0_GPIO4_SHIFT           (23U)
/*! GPIO4 - Enables the clock for GPIO4
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_GPIO4(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO4_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO4_MASK)

#define SYSCON_AHBCLKCTRL0_PINT_MASK             (0x2000000U)
#define SYSCON_AHBCLKCTRL0_PINT_SHIFT            (25U)
/*! PINT - Enables the clock for PINT
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_PINT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_PINT_SHIFT)) & SYSCON_AHBCLKCTRL0_PINT_MASK)

#define SYSCON_AHBCLKCTRL0_DMA0_MASK             (0x4000000U)
#define SYSCON_AHBCLKCTRL0_DMA0_SHIFT            (26U)
/*! DMA0 - Enables the clock for DMA0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_DMA0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_DMA0_SHIFT)) & SYSCON_AHBCLKCTRL0_DMA0_MASK)

#define SYSCON_AHBCLKCTRL0_CRC_MASK              (0x8000000U)
#define SYSCON_AHBCLKCTRL0_CRC_SHIFT             (27U)
/*! CRC - Enables the clock for CRC
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_CRC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_CRC_SHIFT)) & SYSCON_AHBCLKCTRL0_CRC_MASK)

#define SYSCON_AHBCLKCTRL0_WWDT0_MASK            (0x10000000U)
#define SYSCON_AHBCLKCTRL0_WWDT0_SHIFT           (28U)
/*! WWDT0 - Enables the clock for WWDT0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_WWDT0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_WWDT0_SHIFT)) & SYSCON_AHBCLKCTRL0_WWDT0_MASK)

#define SYSCON_AHBCLKCTRL0_WWDT1_MASK            (0x20000000U)
#define SYSCON_AHBCLKCTRL0_WWDT1_SHIFT           (29U)
/*! WWDT1 - Enables the clock for WWDT1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_WWDT1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_WWDT1_SHIFT)) & SYSCON_AHBCLKCTRL0_WWDT1_MASK)

#define SYSCON_AHBCLKCTRL0_MAILBOX_MASK          (0x80000000U)
#define SYSCON_AHBCLKCTRL0_MAILBOX_SHIFT         (31U)
/*! MAILBOX - Enables the clock for the Inter CPU communication Mailbox.
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL0_MAILBOX(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_MAILBOX_SHIFT)) & SYSCON_AHBCLKCTRL0_MAILBOX_MASK)
/*! @} */

/*! @name AHBCLKCTRL1 - AHB Clock Control 1 */
/*! @{ */

#define SYSCON_AHBCLKCTRL1_MRT_MASK              (0x1U)
#define SYSCON_AHBCLKCTRL1_MRT_SHIFT             (0U)
/*! MRT - Enables the clock for MRT
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_MRT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_MRT_SHIFT)) & SYSCON_AHBCLKCTRL1_MRT_MASK)

#define SYSCON_AHBCLKCTRL1_OSTIMER_MASK          (0x2U)
#define SYSCON_AHBCLKCTRL1_OSTIMER_SHIFT         (1U)
/*! OSTIMER - Enables the clock for the OS Event Timer
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_OSTIMER(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_OSTIMER_SHIFT)) & SYSCON_AHBCLKCTRL1_OSTIMER_MASK)

#define SYSCON_AHBCLKCTRL1_SCT_MASK              (0x4U)
#define SYSCON_AHBCLKCTRL1_SCT_SHIFT             (2U)
/*! SCT - Enables the clock for SCT
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_SCT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_SCT_SHIFT)) & SYSCON_AHBCLKCTRL1_SCT_MASK)

#define SYSCON_AHBCLKCTRL1_ADC0_MASK             (0x8U)
#define SYSCON_AHBCLKCTRL1_ADC0_SHIFT            (3U)
/*! ADC0 - Enables the clock for ADC0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_ADC0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_ADC0_SHIFT)) & SYSCON_AHBCLKCTRL1_ADC0_MASK)

#define SYSCON_AHBCLKCTRL1_ADC1_MASK             (0x10U)
#define SYSCON_AHBCLKCTRL1_ADC1_SHIFT            (4U)
/*! ADC1 - Enables the clock for ADC1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_ADC1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_ADC1_SHIFT)) & SYSCON_AHBCLKCTRL1_ADC1_MASK)

#define SYSCON_AHBCLKCTRL1_DAC0_MASK             (0x20U)
#define SYSCON_AHBCLKCTRL1_DAC0_SHIFT            (5U)
/*! DAC0 - Enables the clock for DAC0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_DAC0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_DAC0_SHIFT)) & SYSCON_AHBCLKCTRL1_DAC0_MASK)

#define SYSCON_AHBCLKCTRL1_RTC_MASK              (0x40U)
#define SYSCON_AHBCLKCTRL1_RTC_SHIFT             (6U)
/*! RTC - Enables the clock for RTC
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_RTC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_RTC_SHIFT)) & SYSCON_AHBCLKCTRL1_RTC_MASK)

#define SYSCON_AHBCLKCTRL1_EVSIM0_MASK           (0x100U)
#define SYSCON_AHBCLKCTRL1_EVSIM0_SHIFT          (8U)
/*! EVSIM0 - Enables the clock for EVSIM0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_EVSIM0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_EVSIM0_SHIFT)) & SYSCON_AHBCLKCTRL1_EVSIM0_MASK)

#define SYSCON_AHBCLKCTRL1_EVSIM1_MASK           (0x200U)
#define SYSCON_AHBCLKCTRL1_EVSIM1_SHIFT          (9U)
/*! EVSIM1 - Enables the clock for EVSIM1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_EVSIM1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_EVSIM1_SHIFT)) & SYSCON_AHBCLKCTRL1_EVSIM1_MASK)

#define SYSCON_AHBCLKCTRL1_UTICK_MASK            (0x400U)
#define SYSCON_AHBCLKCTRL1_UTICK_SHIFT           (10U)
/*! UTICK - Enables the clock for UTICK
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_UTICK(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_UTICK_SHIFT)) & SYSCON_AHBCLKCTRL1_UTICK_MASK)

#define SYSCON_AHBCLKCTRL1_FC0_MASK              (0x800U)
#define SYSCON_AHBCLKCTRL1_FC0_SHIFT             (11U)
/*! FC0 - Enables the clock for LP_FLEXCOMM0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC0_SHIFT)) & SYSCON_AHBCLKCTRL1_FC0_MASK)

#define SYSCON_AHBCLKCTRL1_FC1_MASK              (0x1000U)
#define SYSCON_AHBCLKCTRL1_FC1_SHIFT             (12U)
/*! FC1 - Enables the clock for LP_FLEXCOMM1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC1_SHIFT)) & SYSCON_AHBCLKCTRL1_FC1_MASK)

#define SYSCON_AHBCLKCTRL1_FC2_MASK              (0x2000U)
#define SYSCON_AHBCLKCTRL1_FC2_SHIFT             (13U)
/*! FC2 - Enables the clock for LP_FLEXCOMM2
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC2(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC2_SHIFT)) & SYSCON_AHBCLKCTRL1_FC2_MASK)

#define SYSCON_AHBCLKCTRL1_FC3_MASK              (0x4000U)
#define SYSCON_AHBCLKCTRL1_FC3_SHIFT             (14U)
/*! FC3 - Enables the clock for LP_FLEXCOMM3
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC3_SHIFT)) & SYSCON_AHBCLKCTRL1_FC3_MASK)

#define SYSCON_AHBCLKCTRL1_FC4_MASK              (0x8000U)
#define SYSCON_AHBCLKCTRL1_FC4_SHIFT             (15U)
/*! FC4 - Enables the clock for LP_FLEXCOMM4
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC4(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC4_SHIFT)) & SYSCON_AHBCLKCTRL1_FC4_MASK)

#define SYSCON_AHBCLKCTRL1_FC5_MASK              (0x10000U)
#define SYSCON_AHBCLKCTRL1_FC5_SHIFT             (16U)
/*! FC5 - Enables the clock for LP_FLEXCOMM5
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC5(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC5_SHIFT)) & SYSCON_AHBCLKCTRL1_FC5_MASK)

#define SYSCON_AHBCLKCTRL1_FC6_MASK              (0x20000U)
#define SYSCON_AHBCLKCTRL1_FC6_SHIFT             (17U)
/*! FC6 - Enables the clock for LP_FLEXCOMM6
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC6(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC6_SHIFT)) & SYSCON_AHBCLKCTRL1_FC6_MASK)

#define SYSCON_AHBCLKCTRL1_FC7_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL1_FC7_SHIFT             (18U)
/*! FC7 - Enables the clock for LP_FLEXCOMM7
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC7(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC7_SHIFT)) & SYSCON_AHBCLKCTRL1_FC7_MASK)

#define SYSCON_AHBCLKCTRL1_FC8_MASK              (0x80000U)
#define SYSCON_AHBCLKCTRL1_FC8_SHIFT             (19U)
/*! FC8 - Enables the clock for LP_FLEXCOMM8
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC8(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC8_SHIFT)) & SYSCON_AHBCLKCTRL1_FC8_MASK)

#define SYSCON_AHBCLKCTRL1_FC9_MASK              (0x100000U)
#define SYSCON_AHBCLKCTRL1_FC9_SHIFT             (20U)
/*! FC9 - Enables the clock for LP_FLEXCOMM9
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_FC9(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC9_SHIFT)) & SYSCON_AHBCLKCTRL1_FC9_MASK)

#define SYSCON_AHBCLKCTRL1_MICFIL_MASK           (0x200000U)
#define SYSCON_AHBCLKCTRL1_MICFIL_SHIFT          (21U)
/*! MICFIL - Enables the clock for MICFIL
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_MICFIL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_MICFIL_SHIFT)) & SYSCON_AHBCLKCTRL1_MICFIL_MASK)

#define SYSCON_AHBCLKCTRL1_TIMER2_MASK           (0x400000U)
#define SYSCON_AHBCLKCTRL1_TIMER2_SHIFT          (22U)
/*! TIMER2 - Enables the clock for CTIMER2
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_TIMER2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_TIMER2_SHIFT)) & SYSCON_AHBCLKCTRL1_TIMER2_MASK)

#define SYSCON_AHBCLKCTRL1_USB0_FS_DCD_MASK      (0x1000000U)
#define SYSCON_AHBCLKCTRL1_USB0_FS_DCD_SHIFT     (24U)
/*! USB0_FS_DCD - Enables the clock for USB-FS DCD
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_USB0_FS_DCD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_USB0_FS_DCD_SHIFT)) & SYSCON_AHBCLKCTRL1_USB0_FS_DCD_MASK)

#define SYSCON_AHBCLKCTRL1_USB0_FS_MASK          (0x2000000U)
#define SYSCON_AHBCLKCTRL1_USB0_FS_SHIFT         (25U)
/*! USB0_FS - Enables the clock for USB-FS
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_USB0_FS(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_USB0_FS_SHIFT)) & SYSCON_AHBCLKCTRL1_USB0_FS_MASK)

#define SYSCON_AHBCLKCTRL1_TIMER0_MASK           (0x4000000U)
#define SYSCON_AHBCLKCTRL1_TIMER0_SHIFT          (26U)
/*! TIMER0 - Enables the clock for CTIMER0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_TIMER0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_TIMER0_SHIFT)) & SYSCON_AHBCLKCTRL1_TIMER0_MASK)

#define SYSCON_AHBCLKCTRL1_TIMER1_MASK           (0x8000000U)
#define SYSCON_AHBCLKCTRL1_TIMER1_SHIFT          (27U)
/*! TIMER1 - Enables the clock for CTIMER1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_TIMER1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_TIMER1_SHIFT)) & SYSCON_AHBCLKCTRL1_TIMER1_MASK)

#define SYSCON_AHBCLKCTRL1_PKC_RAM_MASK          (0x20000000U)
#define SYSCON_AHBCLKCTRL1_PKC_RAM_SHIFT         (29U)
/*! PKC_RAM - Enables the clock for PKC RAM
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_PKC_RAM(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_PKC_RAM_SHIFT)) & SYSCON_AHBCLKCTRL1_PKC_RAM_MASK)

#define SYSCON_AHBCLKCTRL1_SmartDMA_MASK         (0x80000000U)
#define SYSCON_AHBCLKCTRL1_SmartDMA_SHIFT        (31U)
/*! SmartDMA - Enables the clock for SmartDMA
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL1_SmartDMA(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_SmartDMA_SHIFT)) & SYSCON_AHBCLKCTRL1_SmartDMA_MASK)
/*! @} */

/*! @name AHBCLKCTRL2 - AHB Clock Control 2 */
/*! @{ */

#define SYSCON_AHBCLKCTRL2_DMA1_MASK             (0x2U)
#define SYSCON_AHBCLKCTRL2_DMA1_SHIFT            (1U)
/*! DMA1 - Enables the clock for DMA1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_DMA1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_DMA1_SHIFT)) & SYSCON_AHBCLKCTRL2_DMA1_MASK)

#define SYSCON_AHBCLKCTRL2_ENET_MASK             (0x4U)
#define SYSCON_AHBCLKCTRL2_ENET_SHIFT            (2U)
/*! ENET - Enables the clock for Ethernet
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_ENET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_ENET_SHIFT)) & SYSCON_AHBCLKCTRL2_ENET_MASK)

#define SYSCON_AHBCLKCTRL2_uSDHC_MASK            (0x8U)
#define SYSCON_AHBCLKCTRL2_uSDHC_SHIFT           (3U)
/*! uSDHC - Enables the clock for uSDHC
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_uSDHC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_uSDHC_SHIFT)) & SYSCON_AHBCLKCTRL2_uSDHC_MASK)

#define SYSCON_AHBCLKCTRL2_FLEXIO_MASK           (0x10U)
#define SYSCON_AHBCLKCTRL2_FLEXIO_SHIFT          (4U)
/*! FLEXIO - Enables the clock for Flexio
 *  0b0..Disables clock
 *  0b1..Enable clock
 */
#define SYSCON_AHBCLKCTRL2_FLEXIO(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_FLEXIO_SHIFT)) & SYSCON_AHBCLKCTRL2_FLEXIO_MASK)

#define SYSCON_AHBCLKCTRL2_SAI0_MASK             (0x20U)
#define SYSCON_AHBCLKCTRL2_SAI0_SHIFT            (5U)
/*! SAI0 - Enables the clock for SAI0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_SAI0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_SAI0_SHIFT)) & SYSCON_AHBCLKCTRL2_SAI0_MASK)

#define SYSCON_AHBCLKCTRL2_SAI1_MASK             (0x40U)
#define SYSCON_AHBCLKCTRL2_SAI1_SHIFT            (6U)
/*! SAI1 - Enables the clock for SAI1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_SAI1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_SAI1_SHIFT)) & SYSCON_AHBCLKCTRL2_SAI1_MASK)

#define SYSCON_AHBCLKCTRL2_TRO_MASK              (0x80U)
#define SYSCON_AHBCLKCTRL2_TRO_SHIFT             (7U)
/*! TRO - Enables the clock for TRO
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_TRO(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_TRO_SHIFT)) & SYSCON_AHBCLKCTRL2_TRO_MASK)

#define SYSCON_AHBCLKCTRL2_FREQME_MASK           (0x100U)
#define SYSCON_AHBCLKCTRL2_FREQME_SHIFT          (8U)
/*! FREQME - Enables the clock for the Frequency meter
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_FREQME(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_FREQME_SHIFT)) & SYSCON_AHBCLKCTRL2_FREQME_MASK)

#define SYSCON_AHBCLKCTRL2_TRNG_MASK             (0x2000U)
#define SYSCON_AHBCLKCTRL2_TRNG_SHIFT            (13U)
/*! TRNG - Enables the clock for TRNG
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_TRNG(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_TRNG_SHIFT)) & SYSCON_AHBCLKCTRL2_TRNG_MASK)

#define SYSCON_AHBCLKCTRL2_FLEXCAN0_MASK         (0x4000U)
#define SYSCON_AHBCLKCTRL2_FLEXCAN0_SHIFT        (14U)
/*! FLEXCAN0 - Enables the clock for FLEXCAN0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_FLEXCAN0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_FLEXCAN0_SHIFT)) & SYSCON_AHBCLKCTRL2_FLEXCAN0_MASK)

#define SYSCON_AHBCLKCTRL2_FLEXCAN1_MASK         (0x8000U)
#define SYSCON_AHBCLKCTRL2_FLEXCAN1_SHIFT        (15U)
/*! FLEXCAN1 - Enables the clock for FLEXCAN1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_FLEXCAN1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_FLEXCAN1_SHIFT)) & SYSCON_AHBCLKCTRL2_FLEXCAN1_MASK)

#define SYSCON_AHBCLKCTRL2_USB_HS_MASK           (0x10000U)
#define SYSCON_AHBCLKCTRL2_USB_HS_SHIFT          (16U)
/*! USB_HS - Enables the clock for USB HS
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_USB_HS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_USB_HS_SHIFT)) & SYSCON_AHBCLKCTRL2_USB_HS_MASK)

#define SYSCON_AHBCLKCTRL2_USB_HS_PHY_MASK       (0x20000U)
#define SYSCON_AHBCLKCTRL2_USB_HS_PHY_SHIFT      (17U)
/*! USB_HS_PHY - Enables the clock for USB HS PHY
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_USB_HS_PHY(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_USB_HS_PHY_SHIFT)) & SYSCON_AHBCLKCTRL2_USB_HS_PHY_MASK)

#define SYSCON_AHBCLKCTRL2_ELS_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL2_ELS_SHIFT             (18U)
/*! ELS - Enables the clock for ELS
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_ELS(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_ELS_SHIFT)) & SYSCON_AHBCLKCTRL2_ELS_MASK)

#define SYSCON_AHBCLKCTRL2_PQ_MASK               (0x80000U)
#define SYSCON_AHBCLKCTRL2_PQ_SHIFT              (19U)
/*! PQ - Enables the clock for Powerquad
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_PQ(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PQ_SHIFT)) & SYSCON_AHBCLKCTRL2_PQ_MASK)

#define SYSCON_AHBCLKCTRL2_PLU_LUT_MASK          (0x100000U)
#define SYSCON_AHBCLKCTRL2_PLU_LUT_SHIFT         (20U)
/*! PLU_LUT - Enables the clock for PLU_LUT
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_PLU_LUT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PLU_LUT_SHIFT)) & SYSCON_AHBCLKCTRL2_PLU_LUT_MASK)

#define SYSCON_AHBCLKCTRL2_TIMER3_MASK           (0x200000U)
#define SYSCON_AHBCLKCTRL2_TIMER3_SHIFT          (21U)
/*! TIMER3 - Enables the clock for CTIMER3
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_TIMER3(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_TIMER3_SHIFT)) & SYSCON_AHBCLKCTRL2_TIMER3_MASK)

#define SYSCON_AHBCLKCTRL2_TIMER4_MASK           (0x400000U)
#define SYSCON_AHBCLKCTRL2_TIMER4_SHIFT          (22U)
/*! TIMER4 - Enables the clock for CTIMER4
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_TIMER4(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_TIMER4_SHIFT)) & SYSCON_AHBCLKCTRL2_TIMER4_MASK)

#define SYSCON_AHBCLKCTRL2_PUF_MASK              (0x800000U)
#define SYSCON_AHBCLKCTRL2_PUF_SHIFT             (23U)
/*! PUF - Enables the clock for PUF
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_PUF(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PUF_SHIFT)) & SYSCON_AHBCLKCTRL2_PUF_MASK)

#define SYSCON_AHBCLKCTRL2_PKC_MASK              (0x1000000U)
#define SYSCON_AHBCLKCTRL2_PKC_SHIFT             (24U)
/*! PKC - Enables the clock for PKC
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_PKC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PKC_SHIFT)) & SYSCON_AHBCLKCTRL2_PKC_MASK)

#define SYSCON_AHBCLKCTRL2_SCG_MASK              (0x4000000U)
#define SYSCON_AHBCLKCTRL2_SCG_SHIFT             (26U)
/*! SCG - Enables the clock for SCG
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_SCG(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_SCG_SHIFT)) & SYSCON_AHBCLKCTRL2_SCG_MASK)

#define SYSCON_AHBCLKCTRL2_GDET_MASK             (0x20000000U)
#define SYSCON_AHBCLKCTRL2_GDET_SHIFT            (29U)
/*! GDET - Enables the clock for GDET0 and GDET1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_GDET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_GDET_SHIFT)) & SYSCON_AHBCLKCTRL2_GDET_MASK)

#define SYSCON_AHBCLKCTRL2_SM3_MASK              (0x40000000U)
#define SYSCON_AHBCLKCTRL2_SM3_SHIFT             (30U)
/*! SM3 - Enables the clock for SM3
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL2_SM3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_SM3_SHIFT)) & SYSCON_AHBCLKCTRL2_SM3_MASK)
/*! @} */

/*! @name AHBCLKCTRL3 - AHB Clock Control 3 */
/*! @{ */

#define SYSCON_AHBCLKCTRL3_I3C0_MASK             (0x1U)
#define SYSCON_AHBCLKCTRL3_I3C0_SHIFT            (0U)
/*! I3C0 - Enables the clock for I3C0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_I3C0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_I3C0_SHIFT)) & SYSCON_AHBCLKCTRL3_I3C0_MASK)

#define SYSCON_AHBCLKCTRL3_I3C1_MASK             (0x2U)
#define SYSCON_AHBCLKCTRL3_I3C1_SHIFT            (1U)
/*! I3C1 - Enables the clock for I3C1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_I3C1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_I3C1_SHIFT)) & SYSCON_AHBCLKCTRL3_I3C1_MASK)

#define SYSCON_AHBCLKCTRL3_SINC_MASK             (0x4U)
#define SYSCON_AHBCLKCTRL3_SINC_SHIFT            (2U)
/*! SINC - Enables the clock for SINC
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_SINC(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_SINC_SHIFT)) & SYSCON_AHBCLKCTRL3_SINC_MASK)

#define SYSCON_AHBCLKCTRL3_COOLFLUX_MASK         (0x8U)
#define SYSCON_AHBCLKCTRL3_COOLFLUX_SHIFT        (3U)
/*! COOLFLUX - Enables the clock for CoolFlux
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_COOLFLUX(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_COOLFLUX_SHIFT)) & SYSCON_AHBCLKCTRL3_COOLFLUX_MASK)

#define SYSCON_AHBCLKCTRL3_QDC0_MASK             (0x10U)
#define SYSCON_AHBCLKCTRL3_QDC0_SHIFT            (4U)
/*! QDC0 - Enables the clock for QDC0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_QDC0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_QDC0_SHIFT)) & SYSCON_AHBCLKCTRL3_QDC0_MASK)

#define SYSCON_AHBCLKCTRL3_QDC1_MASK             (0x20U)
#define SYSCON_AHBCLKCTRL3_QDC1_SHIFT            (5U)
/*! QDC1 - Enables the clock for QDC1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_QDC1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_QDC1_SHIFT)) & SYSCON_AHBCLKCTRL3_QDC1_MASK)

#define SYSCON_AHBCLKCTRL3_PWM0_MASK             (0x40U)
#define SYSCON_AHBCLKCTRL3_PWM0_SHIFT            (6U)
/*! PWM0 - Enables the clock for PWM0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_PWM0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_PWM0_SHIFT)) & SYSCON_AHBCLKCTRL3_PWM0_MASK)

#define SYSCON_AHBCLKCTRL3_PWM1_MASK             (0x80U)
#define SYSCON_AHBCLKCTRL3_PWM1_SHIFT            (7U)
/*! PWM1 - Enables the clock for PWM1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_PWM1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_PWM1_SHIFT)) & SYSCON_AHBCLKCTRL3_PWM1_MASK)

#define SYSCON_AHBCLKCTRL3_EVTG_MASK             (0x100U)
#define SYSCON_AHBCLKCTRL3_EVTG_SHIFT            (8U)
/*! EVTG - Enables the clock for EVTG
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_EVTG(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_EVTG_SHIFT)) & SYSCON_AHBCLKCTRL3_EVTG_MASK)

#define SYSCON_AHBCLKCTRL3_DAC1_MASK             (0x800U)
#define SYSCON_AHBCLKCTRL3_DAC1_SHIFT            (11U)
/*! DAC1 - Enables the clock for DAC1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_DAC1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_DAC1_SHIFT)) & SYSCON_AHBCLKCTRL3_DAC1_MASK)

#define SYSCON_AHBCLKCTRL3_DAC2_MASK             (0x1000U)
#define SYSCON_AHBCLKCTRL3_DAC2_SHIFT            (12U)
/*! DAC2 - Enables the clock for DAC2
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_DAC2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_DAC2_SHIFT)) & SYSCON_AHBCLKCTRL3_DAC2_MASK)

#define SYSCON_AHBCLKCTRL3_OPAMP0_MASK           (0x2000U)
#define SYSCON_AHBCLKCTRL3_OPAMP0_SHIFT          (13U)
/*! OPAMP0 - Enables the clock for OPAMP0
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_OPAMP0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_OPAMP0_SHIFT)) & SYSCON_AHBCLKCTRL3_OPAMP0_MASK)

#define SYSCON_AHBCLKCTRL3_OPAMP1_MASK           (0x4000U)
#define SYSCON_AHBCLKCTRL3_OPAMP1_SHIFT          (14U)
/*! OPAMP1 - Enables the clock for OPAMP1
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_OPAMP1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_OPAMP1_SHIFT)) & SYSCON_AHBCLKCTRL3_OPAMP1_MASK)

#define SYSCON_AHBCLKCTRL3_OPAMP2_MASK           (0x8000U)
#define SYSCON_AHBCLKCTRL3_OPAMP2_SHIFT          (15U)
/*! OPAMP2 - Enables the clock for OPAMP2
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_OPAMP2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_OPAMP2_SHIFT)) & SYSCON_AHBCLKCTRL3_OPAMP2_MASK)

#define SYSCON_AHBCLKCTRL3_CMP2_MASK             (0x40000U)
#define SYSCON_AHBCLKCTRL3_CMP2_SHIFT            (18U)
/*! CMP2 - Enables the clock for CMP2
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_CMP2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_CMP2_SHIFT)) & SYSCON_AHBCLKCTRL3_CMP2_MASK)

#define SYSCON_AHBCLKCTRL3_VREF_MASK             (0x80000U)
#define SYSCON_AHBCLKCTRL3_VREF_SHIFT            (19U)
/*! VREF - Enables the clock for VREF
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_VREF(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_VREF_SHIFT)) & SYSCON_AHBCLKCTRL3_VREF_MASK)

#define SYSCON_AHBCLKCTRL3_COOLFLUX_APB_MASK     (0x100000U)
#define SYSCON_AHBCLKCTRL3_COOLFLUX_APB_SHIFT    (20U)
/*! COOLFLUX_APB - Enables the clock for CoolFlux APB
 *  0b0..Disables clock
 *  0b1..Enables clock (CoolFlux needs to be properly programmed before the clock enabled.)
 */
#define SYSCON_AHBCLKCTRL3_COOLFLUX_APB(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_COOLFLUX_APB_SHIFT)) & SYSCON_AHBCLKCTRL3_COOLFLUX_APB_MASK)

#define SYSCON_AHBCLKCTRL3_NPU_MASK              (0x200000U)
#define SYSCON_AHBCLKCTRL3_NPU_SHIFT             (21U)
/*! NPU - Enables the clock for NPU
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_NPU(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_NPU_SHIFT)) & SYSCON_AHBCLKCTRL3_NPU_MASK)

#define SYSCON_AHBCLKCTRL3_TSI_MASK              (0x400000U)
#define SYSCON_AHBCLKCTRL3_TSI_SHIFT             (22U)
/*! TSI - Enables the clock for TSI
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_TSI(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_TSI_SHIFT)) & SYSCON_AHBCLKCTRL3_TSI_MASK)

#define SYSCON_AHBCLKCTRL3_EWM_MASK              (0x800000U)
#define SYSCON_AHBCLKCTRL3_EWM_SHIFT             (23U)
/*! EWM - Enables the clock for EWM
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_EWM(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_EWM_SHIFT)) & SYSCON_AHBCLKCTRL3_EWM_MASK)

#define SYSCON_AHBCLKCTRL3_EIM_MASK              (0x1000000U)
#define SYSCON_AHBCLKCTRL3_EIM_SHIFT             (24U)
/*! EIM - Enables the clock for EIM
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_EIM(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_EIM_SHIFT)) & SYSCON_AHBCLKCTRL3_EIM_MASK)

#define SYSCON_AHBCLKCTRL3_ERM_MASK              (0x2000000U)
#define SYSCON_AHBCLKCTRL3_ERM_SHIFT             (25U)
/*! ERM - Enables the clock for ERM
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_ERM(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_ERM_SHIFT)) & SYSCON_AHBCLKCTRL3_ERM_MASK)

#define SYSCON_AHBCLKCTRL3_INTM_MASK             (0x4000000U)
#define SYSCON_AHBCLKCTRL3_INTM_SHIFT            (26U)
/*! INTM - Enables the clock for INTM
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_INTM(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_INTM_SHIFT)) & SYSCON_AHBCLKCTRL3_INTM_MASK)

#define SYSCON_AHBCLKCTRL3_SEMA42_MASK           (0x8000000U)
#define SYSCON_AHBCLKCTRL3_SEMA42_SHIFT          (27U)
/*! SEMA42 - Enables the clock for Semaphore
 *  0b0..Disables clock
 *  0b1..Enables clock
 */
#define SYSCON_AHBCLKCTRL3_SEMA42(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_SEMA42_SHIFT)) & SYSCON_AHBCLKCTRL3_SEMA42_MASK)
/*! @} */

/*! @name AHBCLKCTRLSET - AHB Clock Control Set */
/*! @{ */

#define SYSCON_AHBCLKCTRLSET_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLSET_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_AHBCLKCTRLSET_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLSET_DATA_SHIFT)) & SYSCON_AHBCLKCTRLSET_DATA_MASK)
/*! @} */

/*! @name AHBCLKCTRLCLR - AHB Clock Control Clear */
/*! @{ */

#define SYSCON_AHBCLKCTRLCLR_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLCLR_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_AHBCLKCTRLCLR_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLCLR_DATA_SHIFT)) & SYSCON_AHBCLKCTRLCLR_DATA_MASK)
/*! @} */

/*! @name SYSTICKCLKSEL0 - CPU0 System Tick Timer Source Select */
/*! @{ */

#define SYSCON_SYSTICKCLKSEL0_SEL_MASK           (0x7U)
#define SYSCON_SYSTICKCLKSEL0_SEL_SHIFT          (0U)
/*! SEL - Selects the System Tick Timer for CPU0 source
 *  0b000..SYSTICKCLKDIV0 output
 *  0b001..Clk 1 MHz clock
 *  0b010..LP Oscillator clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_SYSTICKCLKSEL0_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKSEL0_SEL_SHIFT)) & SYSCON_SYSTICKCLKSEL0_SEL_MASK)
/*! @} */

/*! @name SYSTICKCLKSEL1 - CPU1 System Tick Timer Source Select */
/*! @{ */

#define SYSCON_SYSTICKCLKSEL1_SEL_MASK           (0x7U)
#define SYSCON_SYSTICKCLKSEL1_SEL_SHIFT          (0U)
/*! SEL - Selects the System Tick Timer for CPU1 source.
 *  0b000..SYSTICKCLKDIV1 output
 *  0b001..Clk 1 MHz clock
 *  0b010..LP Oscillator clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_SYSTICKCLKSEL1_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKSEL1_SEL_SHIFT)) & SYSCON_SYSTICKCLKSEL1_SEL_MASK)
/*! @} */

/*! @name TRACECLKSEL - Trace Clock Source Select */
/*! @{ */

#define SYSCON_TRACECLKSEL_SEL_MASK              (0x7U)
#define SYSCON_TRACECLKSEL_SEL_SHIFT             (0U)
/*! SEL - Selects the trace clock source.
 *  0b000..TRACECLKDIV output
 *  0b001..Clk 1 MHz clock
 *  0b010..LP Oscillator clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_TRACECLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKSEL_SEL_SHIFT)) & SYSCON_TRACECLKSEL_SEL_MASK)
/*! @} */

/*! @name CTIMERCLKSEL - CTIMER Clock Source Select */
/*! @{ */

#define SYSCON_CTIMERCLKSEL_SEL_MASK             (0xFU)
#define SYSCON_CTIMERCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Selects the CTIMER clock source.
 *  0b0000..FRO_1M clock
 *  0b0001..PLL0 clock
 *  0b0010..PLL1_clk0 clock
 *  0b0011..FRO_HF clock
 *  0b0100..FRO 12MHz clock
 *  0b0101..SAI0 MCLK IN clock
 *  0b0110..LP Oscillator clock
 *  0b0111..No clock
 *  0b1000..SAI1 MCLK IN clock
 *  0b1001..SAI0 TX_BCLK clock
 *  0b1010..SAI0 RX_BCLK clock
 *  0b1011..SAI1 TX_BCLK clock
 *  0b1100..SAI1 RX_BCLK clock
 *  0b1101..No clock
 *  0b1110..No clock
 *  0b1111..No clock
 */
#define SYSCON_CTIMERCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSEL_SEL_SHIFT)) & SYSCON_CTIMERCLKSEL_SEL_MASK)
/*! @} */

/*! @name CLKOUTSEL - CLKOUT Clock Source Select */
/*! @{ */

#define SYSCON_CLKOUTSEL_SEL_MASK                (0xFU)
#define SYSCON_CLKOUTSEL_SEL_SHIFT               (0U)
/*! SEL - Selects the CLKOUT clock source.
 *  0b0000..Main clock (main_clk)
 *  0b0001..PLL0 clock (pll0_clk)
 *  0b0010..CLKIN clock (clk_in)
 *  0b0011..FRO_HF clock (fro_hf)
 *  0b0100..FRO 12 MHz clock (fro_12m)
 *  0b0101..PLL1_clk0 clock (pll1_clk)
 *  0b0110..LP Oscillator clock (lp_osc)
 *  0b0111..USB PLL clock (usb_pll_clk)
 *  0b1000..No clock
 *  0b1001..No clock
 *  0b1010..No clock
 *  0b1011..No clock
 *  0b1100..No clock
 *  0b1101..No clock
 *  0b1110..No clock
 *  0b1111..No clock
 */
#define SYSCON_CLKOUTSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSEL_SEL_SHIFT)) & SYSCON_CLKOUTSEL_SEL_MASK)
/*! @} */

/*! @name ADC0CLKSEL - ADC0 Clock Source Select */
/*! @{ */

#define SYSCON_ADC0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_ADC0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the ADC0 clock source.
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO 12 MHz clock
 *  0b100..Clk_in
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_ADC0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKSEL_SEL_SHIFT)) & SYSCON_ADC0CLKSEL_SEL_MASK)
/*! @} */

/*! @name USB0CLKSEL - USB-FS Clock Source Select */
/*! @{ */

#define SYSCON_USB0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_USB0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the USB-FS clock source.
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..No clock
 *  0b011..Clk 48 MHz clock
 *  0b100..Clk_in
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_USB0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKSEL_SEL_SHIFT)) & SYSCON_USB0CLKSEL_SEL_MASK)
/*! @} */

/*! @name FCCLKSEL - LP_FLEXCOMM Clock Source Select for Fractional Rate Divider */
/*! @{ */

#define SYSCON_FCCLKSEL_SEL_MASK                 (0x7U)
#define SYSCON_FCCLKSEL_SEL_SHIFT                (0U)
/*! SEL - Selects the LP_FLEXCOMM clock source for Fractional Rate Divider.
 *  0b000..No clock
 *  0b001..PLL divided clock
 *  0b010..FRO 12 MHz clock
 *  0b011..fro_hf_div clock
 *  0b100..clk_1m clock
 *  0b101..USB PLL clock
 *  0b110..LP Oscillator clock
 *  0b111..No clock
 */
#define SYSCON_FCCLKSEL_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FCCLKSEL_SEL_SHIFT)) & SYSCON_FCCLKSEL_SEL_MASK)
/*! @} */

/*! @name SCTCLKSEL - SCTimer/PWM Clock Source Select */
/*! @{ */

#define SYSCON_SCTCLKSEL_SEL_MASK                (0xFU)
#define SYSCON_SCTCLKSEL_SEL_SHIFT               (0U)
/*! SEL - Selects the SCTimer/PWM clock source.
 *  0b0000..No clock
 *  0b0001..PLL0 clock
 *  0b0010..CLKIN clock
 *  0b0011..FRO_HF clock
 *  0b0100..PLL1_clk0 clock
 *  0b0101..SAI0 MCLK_IN clock
 *  0b0110..USB PLL clock
 *  0b0111..No clock
 *  0b1000..SAI1 MCLK_IN clock
 *  0b1001..No clock
 *  0b1010..No clock
 *  0b1011..No clock
 *  0b1100..No clock
 *  0b1101..No clock
 *  0b1110..No clock
 *  0b1111..No clock
 */
#define SYSCON_SCTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKSEL_SEL_SHIFT)) & SYSCON_SCTCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSTICKCLKDIV - CPU0 System Tick Timer Divider..CPU1 System Tick Timer Divider */
/*! @{ */

#define SYSCON_SYSTICKCLKDIV_DIV_MASK            (0xFFU)
#define SYSCON_SYSTICKCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value */
#define SYSCON_SYSTICKCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_DIV_SHIFT)) & SYSCON_SYSTICKCLKDIV_DIV_MASK)

#define SYSCON_SYSTICKCLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_SYSTICKCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset.
 */
#define SYSCON_SYSTICKCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_RESET_SHIFT)) & SYSCON_SYSTICKCLKDIV_RESET_MASK)

#define SYSCON_SYSTICKCLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_SYSTICKCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_SYSTICKCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_HALT_SHIFT)) & SYSCON_SYSTICKCLKDIV_HALT_MASK)

#define SYSCON_SYSTICKCLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_SYSTICKCLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_SYSTICKCLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_UNSTAB_SHIFT)) & SYSCON_SYSTICKCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name TRACECLKDIV - TRACE Clock Divider */
/*! @{ */

#define SYSCON_TRACECLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_TRACECLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_TRACECLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_DIV_SHIFT)) & SYSCON_TRACECLKDIV_DIV_MASK)

#define SYSCON_TRACECLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_TRACECLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_TRACECLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_RESET_SHIFT)) & SYSCON_TRACECLKDIV_RESET_MASK)

#define SYSCON_TRACECLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_TRACECLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_TRACECLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_HALT_SHIFT)) & SYSCON_TRACECLKDIV_HALT_MASK)

#define SYSCON_TRACECLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_TRACECLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_TRACECLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_UNSTAB_SHIFT)) & SYSCON_TRACECLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name TSICLKSEL - TSI Function Clock Source Select */
/*! @{ */

#define SYSCON_TSICLKSEL_SEL_MASK                (0x7U)
#define SYSCON_TSICLKSEL_SEL_SHIFT               (0U)
/*! SEL - Selects the TSI function clock source.
 *  0b000..No clock
 *  0b001..No clock
 *  0b010..clk_in
 *  0b011..No clock
 *  0b100..FRO_12Mhz clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_TSICLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_TSICLKSEL_SEL_SHIFT)) & SYSCON_TSICLKSEL_SEL_MASK)
/*! @} */

/*! @name SINCFILTCLKSEL - SINC FILTER Function Clock Source Select */
/*! @{ */

#define SYSCON_SINCFILTCLKSEL_SEL_MASK           (0x7U)
#define SYSCON_SINCFILTCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Selects the SINC FILTER function clock source.
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..clk_in
 *  0b011..FRO_HF clock
 *  0b100..FRO_12Mhz clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_SINCFILTCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SINCFILTCLKSEL_SEL_SHIFT)) & SYSCON_SINCFILTCLKSEL_SEL_MASK)
/*! @} */

/*! @name SLOWCLKDIV - SLOW_CLK Clock Divider */
/*! @{ */

#define SYSCON_SLOWCLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_SLOWCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_SLOWCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_RESET_SHIFT)) & SYSCON_SLOWCLKDIV_RESET_MASK)

#define SYSCON_SLOWCLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_SLOWCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_SLOWCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_HALT_SHIFT)) & SYSCON_SLOWCLKDIV_HALT_MASK)

#define SYSCON_SLOWCLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_SLOWCLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_SLOWCLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_UNSTAB_SHIFT)) & SYSCON_SLOWCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name TSICLKDIV - TSI Function Clock Divider */
/*! @{ */

#define SYSCON_TSICLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_TSICLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value: */
#define SYSCON_TSICLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_TSICLKDIV_DIV_SHIFT)) & SYSCON_TSICLKDIV_DIV_MASK)

#define SYSCON_TSICLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_TSICLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_TSICLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_TSICLKDIV_RESET_SHIFT)) & SYSCON_TSICLKDIV_RESET_MASK)

#define SYSCON_TSICLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_TSICLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_TSICLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_TSICLKDIV_HALT_SHIFT)) & SYSCON_TSICLKDIV_HALT_MASK)

#define SYSCON_TSICLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_TSICLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_TSICLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_TSICLKDIV_UNSTAB_SHIFT)) & SYSCON_TSICLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name AHBCLKDIV - System Clock Divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)

#define SYSCON_AHBCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_AHBCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_AHBCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_UNSTAB_SHIFT)) & SYSCON_AHBCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT Clock Divider */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)

#define SYSCON_CLKOUTDIV_RESET_MASK              (0x20000000U)
#define SYSCON_CLKOUTDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CLKOUTDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_RESET_SHIFT)) & SYSCON_CLKOUTDIV_RESET_MASK)

#define SYSCON_CLKOUTDIV_HALT_MASK               (0x40000000U)
#define SYSCON_CLKOUTDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_CLKOUTDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_HALT_SHIFT)) & SYSCON_CLKOUTDIV_HALT_MASK)

#define SYSCON_CLKOUTDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_CLKOUTDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_CLKOUTDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_UNSTAB_SHIFT)) & SYSCON_CLKOUTDIV_UNSTAB_MASK)
/*! @} */

/*! @name FROHFDIV - FRO_HF_DIV Clock Divider */
/*! @{ */

#define SYSCON_FROHFDIV_DIV_MASK                 (0xFFU)
#define SYSCON_FROHFDIV_DIV_SHIFT                (0U)
/*! DIV - Clock divider value */
#define SYSCON_FROHFDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_DIV_SHIFT)) & SYSCON_FROHFDIV_DIV_MASK)

#define SYSCON_FROHFDIV_HALT_MASK                (0x40000000U)
#define SYSCON_FROHFDIV_HALT_SHIFT               (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running, this bit is set to 0 when the register is written.
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FROHFDIV_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_HALT_SHIFT)) & SYSCON_FROHFDIV_HALT_MASK)

#define SYSCON_FROHFDIV_UNSTAB_MASK              (0x80000000U)
#define SYSCON_FROHFDIV_UNSTAB_SHIFT             (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FROHFDIV_UNSTAB(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_UNSTAB_SHIFT)) & SYSCON_FROHFDIV_UNSTAB_MASK)
/*! @} */

/*! @name WDT0CLKDIV - WDT0 Clock Divider */
/*! @{ */

#define SYSCON_WDT0CLKDIV_DIV_MASK               (0x3FU)
#define SYSCON_WDT0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_WDT0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT0CLKDIV_DIV_SHIFT)) & SYSCON_WDT0CLKDIV_DIV_MASK)

#define SYSCON_WDT0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_WDT0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_WDT0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT0CLKDIV_RESET_SHIFT)) & SYSCON_WDT0CLKDIV_RESET_MASK)

#define SYSCON_WDT0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_WDT0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_WDT0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT0CLKDIV_HALT_SHIFT)) & SYSCON_WDT0CLKDIV_HALT_MASK)

#define SYSCON_WDT0CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_WDT0CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_WDT0CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT0CLKDIV_UNSTAB_SHIFT)) & SYSCON_WDT0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name ADC0CLKDIV - ADC0 Clock Divider */
/*! @{ */

#define SYSCON_ADC0CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_ADC0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_ADC0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_DIV_SHIFT)) & SYSCON_ADC0CLKDIV_DIV_MASK)

#define SYSCON_ADC0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_ADC0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_ADC0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_RESET_SHIFT)) & SYSCON_ADC0CLKDIV_RESET_MASK)

#define SYSCON_ADC0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_ADC0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_ADC0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_HALT_SHIFT)) & SYSCON_ADC0CLKDIV_HALT_MASK)

#define SYSCON_ADC0CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_ADC0CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_ADC0CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_UNSTAB_SHIFT)) & SYSCON_ADC0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name USB0CLKDIV - USB-FS Clock Divider */
/*! @{ */

#define SYSCON_USB0CLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_USB0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_USB0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_DIV_SHIFT)) & SYSCON_USB0CLKDIV_DIV_MASK)

#define SYSCON_USB0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_USB0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_USB0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_RESET_SHIFT)) & SYSCON_USB0CLKDIV_RESET_MASK)

#define SYSCON_USB0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_USB0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_USB0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_HALT_SHIFT)) & SYSCON_USB0CLKDIV_HALT_MASK)

#define SYSCON_USB0CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_USB0CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_USB0CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_UNSTAB_SHIFT)) & SYSCON_USB0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name SCTCLKDIV - SCT/PWM Clock Divider */
/*! @{ */

#define SYSCON_SCTCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SCTCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value */
#define SYSCON_SCTCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_DIV_SHIFT)) & SYSCON_SCTCLKDIV_DIV_MASK)

#define SYSCON_SCTCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_SCTCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_SCTCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_RESET_SHIFT)) & SYSCON_SCTCLKDIV_RESET_MASK)

#define SYSCON_SCTCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_SCTCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_SCTCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_HALT_SHIFT)) & SYSCON_SCTCLKDIV_HALT_MASK)

#define SYSCON_SCTCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_SCTCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_SCTCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_UNSTAB_SHIFT)) & SYSCON_SCTCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name PLLCLKDIV - PLL Clock Divider */
/*! @{ */

#define SYSCON_PLLCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_PLLCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value */
#define SYSCON_PLLCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_DIV_SHIFT)) & SYSCON_PLLCLKDIV_DIV_MASK)

#define SYSCON_PLLCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_PLLCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_PLLCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_RESET_SHIFT)) & SYSCON_PLLCLKDIV_RESET_MASK)

#define SYSCON_PLLCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_PLLCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_PLLCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_HALT_SHIFT)) & SYSCON_PLLCLKDIV_HALT_MASK)

#define SYSCON_PLLCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_PLLCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_PLLCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_UNSTAB_SHIFT)) & SYSCON_PLLCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CTIMERXCLKDIV_CTIMERCLKDIV - CTimer Clock Divider */
/*! @{ */

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_MASK (0xFFU)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_SHIFT (0U)
/*! DIV - Clock divider value */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_MASK)

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_MASK (0x20000000U)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_SHIFT (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_MASK)

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_MASK (0x40000000U)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_SHIFT (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock has stopped
 */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_MASK)

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_MASK (0x80000000U)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_SHIFT (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Stable divider clock
 *  0b1..Unstable clock frequency
 */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_MASK)
/*! @} */

/* The count of SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_COUNT  (5U)

/*! @name PLL1CLK0DIV - PLL1 Clock 0 Divider */
/*! @{ */

#define SYSCON_PLL1CLK0DIV_DIV_MASK              (0xFFU)
#define SYSCON_PLL1CLK0DIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_PLL1CLK0DIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK0DIV_DIV_SHIFT)) & SYSCON_PLL1CLK0DIV_DIV_MASK)

#define SYSCON_PLL1CLK0DIV_RESET_MASK            (0x20000000U)
#define SYSCON_PLL1CLK0DIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_PLL1CLK0DIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK0DIV_RESET_SHIFT)) & SYSCON_PLL1CLK0DIV_RESET_MASK)

#define SYSCON_PLL1CLK0DIV_HALT_MASK             (0x40000000U)
#define SYSCON_PLL1CLK0DIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_PLL1CLK0DIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK0DIV_HALT_SHIFT)) & SYSCON_PLL1CLK0DIV_HALT_MASK)

#define SYSCON_PLL1CLK0DIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_PLL1CLK0DIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_PLL1CLK0DIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK0DIV_UNSTAB_SHIFT)) & SYSCON_PLL1CLK0DIV_UNSTAB_MASK)
/*! @} */

/*! @name PLL1CLK1DIV - PLL1 Clock 1 Divider */
/*! @{ */

#define SYSCON_PLL1CLK1DIV_DIV_MASK              (0xFFU)
#define SYSCON_PLL1CLK1DIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_PLL1CLK1DIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK1DIV_DIV_SHIFT)) & SYSCON_PLL1CLK1DIV_DIV_MASK)

#define SYSCON_PLL1CLK1DIV_RESET_MASK            (0x20000000U)
#define SYSCON_PLL1CLK1DIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_PLL1CLK1DIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK1DIV_RESET_SHIFT)) & SYSCON_PLL1CLK1DIV_RESET_MASK)

#define SYSCON_PLL1CLK1DIV_HALT_MASK             (0x40000000U)
#define SYSCON_PLL1CLK1DIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_PLL1CLK1DIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK1DIV_HALT_SHIFT)) & SYSCON_PLL1CLK1DIV_HALT_MASK)

#define SYSCON_PLL1CLK1DIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_PLL1CLK1DIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_PLL1CLK1DIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLK1DIV_UNSTAB_SHIFT)) & SYSCON_PLL1CLK1DIV_UNSTAB_MASK)
/*! @} */

/*! @name UTICKCLKDIV - UTICK Clock Divider */
/*! @{ */

#define SYSCON_UTICKCLKDIV_DIV_MASK              (0x3FU)
#define SYSCON_UTICKCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_UTICKCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_UTICKCLKDIV_DIV_SHIFT)) & SYSCON_UTICKCLKDIV_DIV_MASK)

#define SYSCON_UTICKCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_UTICKCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_UTICKCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_UTICKCLKDIV_RESET_SHIFT)) & SYSCON_UTICKCLKDIV_RESET_MASK)

#define SYSCON_UTICKCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_UTICKCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_UTICKCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_UTICKCLKDIV_HALT_SHIFT)) & SYSCON_UTICKCLKDIV_HALT_MASK)

#define SYSCON_UTICKCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_UTICKCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_UTICKCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_UTICKCLKDIV_UNSTAB_SHIFT)) & SYSCON_UTICKCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CLKOUT_FRGCTRL - CLKOUT FRG Control */
/*! @{ */

#define SYSCON_CLKOUT_FRGCTRL_DIV_MASK           (0xFFU)
#define SYSCON_CLKOUT_FRGCTRL_DIV_SHIFT          (0U)
/*! DIV - Divider value */
#define SYSCON_CLKOUT_FRGCTRL_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUT_FRGCTRL_DIV_SHIFT)) & SYSCON_CLKOUT_FRGCTRL_DIV_MASK)

#define SYSCON_CLKOUT_FRGCTRL_MULT_MASK          (0xFF00U)
#define SYSCON_CLKOUT_FRGCTRL_MULT_SHIFT         (8U)
/*! MULT - Numerator value */
#define SYSCON_CLKOUT_FRGCTRL_MULT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUT_FRGCTRL_MULT_SHIFT)) & SYSCON_CLKOUT_FRGCTRL_MULT_MASK)
/*! @} */

/*! @name CLKUNLOCK - Clock Configuration Unlock */
/*! @{ */

#define SYSCON_CLKUNLOCK_UNLOCK_MASK             (0x1U)
#define SYSCON_CLKUNLOCK_UNLOCK_SHIFT            (0U)
/*! UNLOCK - Controls clock configuration registers access (for example, xxxDIV, xxxSEL)
 *  0b0..Updates are allowed to all clock configuration registers
 *  0b1..Freezes all clock configuration registers update
 */
#define SYSCON_CLKUNLOCK_UNLOCK(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKUNLOCK_UNLOCK_SHIFT)) & SYSCON_CLKUNLOCK_UNLOCK_MASK)
/*! @} */

/*! @name NVM_CTRL - NVM Control */
/*! @{ */

#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC_MASK      (0x1U)
#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC_SHIFT     (0U)
/*! DIS_FLASH_SPEC - Flash speculation control
 *  0b0..Enables flash speculation
 *  0b1..Disables flash speculation
 */
#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_FLASH_SPEC_SHIFT)) & SYSCON_NVM_CTRL_DIS_FLASH_SPEC_MASK)

#define SYSCON_NVM_CTRL_DIS_DATA_SPEC_MASK       (0x2U)
#define SYSCON_NVM_CTRL_DIS_DATA_SPEC_SHIFT      (1U)
/*! DIS_DATA_SPEC - Flash data speculation control
 *  0b0..Enables data speculation
 *  0b1..Disables data speculation
 */
#define SYSCON_NVM_CTRL_DIS_DATA_SPEC(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_DATA_SPEC_SHIFT)) & SYSCON_NVM_CTRL_DIS_DATA_SPEC_MASK)

#define SYSCON_NVM_CTRL_DIS_FLASH_CACHE_MASK     (0x4U)
#define SYSCON_NVM_CTRL_DIS_FLASH_CACHE_SHIFT    (2U)
/*! DIS_FLASH_CACHE - Flash cache control
 *  0b0..Enables flash cache
 *  0b1..Disables flash cache
 */
#define SYSCON_NVM_CTRL_DIS_FLASH_CACHE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_FLASH_CACHE_SHIFT)) & SYSCON_NVM_CTRL_DIS_FLASH_CACHE_MASK)

#define SYSCON_NVM_CTRL_DIS_FLASH_INST_MASK      (0x8U)
#define SYSCON_NVM_CTRL_DIS_FLASH_INST_SHIFT     (3U)
/*! DIS_FLASH_INST - Flash instruction cache control
 *  0b0..Enables flash instruction cache when DIS_FLASH_CACHE=0
 *  0b1..Disables flash instruction cache
 */
#define SYSCON_NVM_CTRL_DIS_FLASH_INST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_FLASH_INST_SHIFT)) & SYSCON_NVM_CTRL_DIS_FLASH_INST_MASK)

#define SYSCON_NVM_CTRL_DIS_FLASH_DATA_MASK      (0x10U)
#define SYSCON_NVM_CTRL_DIS_FLASH_DATA_SHIFT     (4U)
/*! DIS_FLASH_DATA - Flash data cache control
 *  0b0..Enables flash data cache when DIS_FLASH_CACHE=0
 *  0b1..Disables flash data cache
 */
#define SYSCON_NVM_CTRL_DIS_FLASH_DATA(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_FLASH_DATA_SHIFT)) & SYSCON_NVM_CTRL_DIS_FLASH_DATA_MASK)

#define SYSCON_NVM_CTRL_CLR_FLASH_CACHE_MASK     (0x20U)
#define SYSCON_NVM_CTRL_CLR_FLASH_CACHE_SHIFT    (5U)
/*! CLR_FLASH_CACHE - Clear flash cache control
 *  0b0..No clear flash cache
 *  0b1..Clears flash cache
 */
#define SYSCON_NVM_CTRL_CLR_FLASH_CACHE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_CLR_FLASH_CACHE_SHIFT)) & SYSCON_NVM_CTRL_CLR_FLASH_CACHE_MASK)

#define SYSCON_NVM_CTRL_FLASH_STALL_EN_MASK      (0x400U)
#define SYSCON_NVM_CTRL_FLASH_STALL_EN_SHIFT     (10U)
/*! FLASH_STALL_EN - FLASH stall on busy control
 *  0b0..No stall on FLASH busy
 *  0b1..Stall on FLASH busy
 */
#define SYSCON_NVM_CTRL_FLASH_STALL_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_FLASH_STALL_EN_SHIFT)) & SYSCON_NVM_CTRL_FLASH_STALL_EN_MASK)

#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_MASK  (0x10000U)
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_SHIFT (16U)
/*! DIS_MBECC_ERR_INST
 *  0b0..Enables bus error on multi-bit ECC error for instruction
 *  0b1..Disables bus error on multi-bit ECC error for instruction
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_MASK)

#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK  (0x20000U)
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT (17U)
/*! DIS_MBECC_ERR_DATA
 *  0b0..Enables bus error on multi-bit ECC error for data
 *  0b1..Disables bus error on multi-bit ECC error for data
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK)
/*! @} */

/*! @name ROMCR - ROM Wait State */
/*! @{ */

#define SYSCON_ROMCR_ROM_WAIT_MASK               (0x1U)
#define SYSCON_ROMCR_ROM_WAIT_SHIFT              (0U)
/*! ROM_WAIT - ROM waiting Arm core and other masters for one cycle
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ROMCR_ROM_WAIT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ROMCR_ROM_WAIT_SHIFT)) & SYSCON_ROMCR_ROM_WAIT_MASK)
/*! @} */

/*! @name SMARTDMAINT - SmartDMA Interrupt Hijack */
/*! @{ */

#define SYSCON_SMARTDMAINT_INT0_MASK             (0x1U)
#define SYSCON_SMARTDMAINT_INT0_SHIFT            (0U)
/*! INT0 - SmartDMA hijack NVIC IRQ1
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT0_SHIFT)) & SYSCON_SMARTDMAINT_INT0_MASK)

#define SYSCON_SMARTDMAINT_INT1_MASK             (0x2U)
#define SYSCON_SMARTDMAINT_INT1_SHIFT            (1U)
/*! INT1 - SmartDMA hijack NVIC IRQ17
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT1_SHIFT)) & SYSCON_SMARTDMAINT_INT1_MASK)

#define SYSCON_SMARTDMAINT_INT2_MASK             (0x4U)
#define SYSCON_SMARTDMAINT_INT2_SHIFT            (2U)
/*! INT2 - SmartDMA hijack NVIC IRQ18
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT2_SHIFT)) & SYSCON_SMARTDMAINT_INT2_MASK)

#define SYSCON_SMARTDMAINT_INT3_MASK             (0x8U)
#define SYSCON_SMARTDMAINT_INT3_SHIFT            (3U)
/*! INT3 - SmartDMA hijack NVIC IRQ29
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT3_SHIFT)) & SYSCON_SMARTDMAINT_INT3_MASK)

#define SYSCON_SMARTDMAINT_INT4_MASK             (0x10U)
#define SYSCON_SMARTDMAINT_INT4_SHIFT            (4U)
/*! INT4 - SmartDMA hijack NVIC IRQ30
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT4(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT4_SHIFT)) & SYSCON_SMARTDMAINT_INT4_MASK)

#define SYSCON_SMARTDMAINT_INT5_MASK             (0x20U)
#define SYSCON_SMARTDMAINT_INT5_SHIFT            (5U)
/*! INT5 - SmartDMA hijack NVIC IRQ31
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT5(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT5_SHIFT)) & SYSCON_SMARTDMAINT_INT5_MASK)

#define SYSCON_SMARTDMAINT_INT6_MASK             (0x40U)
#define SYSCON_SMARTDMAINT_INT6_SHIFT            (6U)
/*! INT6 - SmartDMA hijack NVIC IRQ32
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT6(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT6_SHIFT)) & SYSCON_SMARTDMAINT_INT6_MASK)

#define SYSCON_SMARTDMAINT_INT7_MASK             (0x80U)
#define SYSCON_SMARTDMAINT_INT7_SHIFT            (7U)
/*! INT7 - SmartDMA hijack NVIC IRQ33
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT7(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT7_SHIFT)) & SYSCON_SMARTDMAINT_INT7_MASK)

#define SYSCON_SMARTDMAINT_INT8_MASK             (0x100U)
#define SYSCON_SMARTDMAINT_INT8_SHIFT            (8U)
/*! INT8 - SmartDMA hijack NVIC IRQ34
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT8(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT8_SHIFT)) & SYSCON_SMARTDMAINT_INT8_MASK)

#define SYSCON_SMARTDMAINT_INT9_MASK             (0x200U)
#define SYSCON_SMARTDMAINT_INT9_SHIFT            (9U)
/*! INT9 - SmartDMA hijack NVIC IRQ35
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT9(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT9_SHIFT)) & SYSCON_SMARTDMAINT_INT9_MASK)

#define SYSCON_SMARTDMAINT_INT10_MASK            (0x400U)
#define SYSCON_SMARTDMAINT_INT10_SHIFT           (10U)
/*! INT10 - SmartDMA hijack NVIC IRQ36
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT10(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT10_SHIFT)) & SYSCON_SMARTDMAINT_INT10_MASK)

#define SYSCON_SMARTDMAINT_INT11_MASK            (0x800U)
#define SYSCON_SMARTDMAINT_INT11_SHIFT           (11U)
/*! INT11 - SmartDMA hijack NVIC IRQ37
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT11(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT11_SHIFT)) & SYSCON_SMARTDMAINT_INT11_MASK)

#define SYSCON_SMARTDMAINT_INT12_MASK            (0x1000U)
#define SYSCON_SMARTDMAINT_INT12_SHIFT           (12U)
/*! INT12 - SmartDMA hijack NVIC IRQ38
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT12(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT12_SHIFT)) & SYSCON_SMARTDMAINT_INT12_MASK)

#define SYSCON_SMARTDMAINT_INT13_MASK            (0x2000U)
#define SYSCON_SMARTDMAINT_INT13_SHIFT           (13U)
/*! INT13 - SmartDMA hijack NVIC IRQ39
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT13(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT13_SHIFT)) & SYSCON_SMARTDMAINT_INT13_MASK)

#define SYSCON_SMARTDMAINT_INT14_MASK            (0x4000U)
#define SYSCON_SMARTDMAINT_INT14_SHIFT           (14U)
/*! INT14 - SmartDMA hijack NVIC IRQ40
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT14(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT14_SHIFT)) & SYSCON_SMARTDMAINT_INT14_MASK)

#define SYSCON_SMARTDMAINT_INT15_MASK            (0x8000U)
#define SYSCON_SMARTDMAINT_INT15_SHIFT           (15U)
/*! INT15 - SmartDMA hijack NVIC IRQ41
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT15(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT15_SHIFT)) & SYSCON_SMARTDMAINT_INT15_MASK)

#define SYSCON_SMARTDMAINT_INT16_MASK            (0x10000U)
#define SYSCON_SMARTDMAINT_INT16_SHIFT           (16U)
/*! INT16 - SmartDMA hijack NVIC IRQ42
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT16(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT16_SHIFT)) & SYSCON_SMARTDMAINT_INT16_MASK)

#define SYSCON_SMARTDMAINT_INT17_MASK            (0x20000U)
#define SYSCON_SMARTDMAINT_INT17_SHIFT           (17U)
/*! INT17 - SmartDMA hijack NVIC IRQ45
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT17(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT17_SHIFT)) & SYSCON_SMARTDMAINT_INT17_MASK)

#define SYSCON_SMARTDMAINT_INT18_MASK            (0x40000U)
#define SYSCON_SMARTDMAINT_INT18_SHIFT           (18U)
/*! INT18 - SmartDMA hijack NVIC IRQ47
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT18(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT18_SHIFT)) & SYSCON_SMARTDMAINT_INT18_MASK)

#define SYSCON_SMARTDMAINT_INT19_MASK            (0x80000U)
#define SYSCON_SMARTDMAINT_INT19_SHIFT           (19U)
/*! INT19 - SmartDMA hijack NVIC IRQ50
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT19(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT19_SHIFT)) & SYSCON_SMARTDMAINT_INT19_MASK)

#define SYSCON_SMARTDMAINT_INT20_MASK            (0x100000U)
#define SYSCON_SMARTDMAINT_INT20_SHIFT           (20U)
/*! INT20 - SmartDMA hijack NVIC IRQ51
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT20(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT20_SHIFT)) & SYSCON_SMARTDMAINT_INT20_MASK)

#define SYSCON_SMARTDMAINT_INT21_MASK            (0x200000U)
#define SYSCON_SMARTDMAINT_INT21_SHIFT           (21U)
/*! INT21 - SmartDMA hijack NVIC IRQ66
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT21(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT21_SHIFT)) & SYSCON_SMARTDMAINT_INT21_MASK)

#define SYSCON_SMARTDMAINT_INT22_MASK            (0x400000U)
#define SYSCON_SMARTDMAINT_INT22_SHIFT           (22U)
/*! INT22 - SmartDMA hijack NVIC IRQ67
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT22(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT22_SHIFT)) & SYSCON_SMARTDMAINT_INT22_MASK)

#define SYSCON_SMARTDMAINT_INT23_MASK            (0x800000U)
#define SYSCON_SMARTDMAINT_INT23_SHIFT           (23U)
/*! INT23 - SmartDMA hijack NVIC IRQ77
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_SMARTDMAINT_INT23(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SMARTDMAINT_INT23_SHIFT)) & SYSCON_SMARTDMAINT_INT23_MASK)
/*! @} */

/*! @name ADC1CLKSEL - ADC1 Clock Source Select */
/*! @{ */

#define SYSCON_ADC1CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_ADC1CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the ADC1 clock source
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO 12 MHz clock
 *  0b100..Clk_in clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_ADC1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKSEL_SEL_SHIFT)) & SYSCON_ADC1CLKSEL_SEL_MASK)
/*! @} */

/*! @name ADC1CLKDIV - ADC1 Clock Divider */
/*! @{ */

#define SYSCON_ADC1CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_ADC1CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_ADC1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_DIV_SHIFT)) & SYSCON_ADC1CLKDIV_DIV_MASK)

#define SYSCON_ADC1CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_ADC1CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_ADC1CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_RESET_SHIFT)) & SYSCON_ADC1CLKDIV_RESET_MASK)

#define SYSCON_ADC1CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_ADC1CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_ADC1CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_HALT_SHIFT)) & SYSCON_ADC1CLKDIV_HALT_MASK)

#define SYSCON_ADC1CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_ADC1CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_ADC1CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_UNSTAB_SHIFT)) & SYSCON_ADC1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name RAM_INTERLEAVE - Control PKC RAM Interleave Access */
/*! @{ */

#define SYSCON_RAM_INTERLEAVE_INTERLEAVE_MASK    (0x1U)
#define SYSCON_RAM_INTERLEAVE_INTERLEAVE_SHIFT   (0U)
/*! INTERLEAVE - Controls PKC RAM access for PKC RAM 0 and PKC RAM 1
 *  0b0..RAM access to PKC RAM 0 and PKC RAM 1 is consecutive.
 *  0b1..RAM access to PKC RAM 0 and PKC RAM 1 is interleaved. This setting is need for PKC L0 memory access.
 */
#define SYSCON_RAM_INTERLEAVE_INTERLEAVE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_INTERLEAVE_INTERLEAVE_SHIFT)) & SYSCON_RAM_INTERLEAVE_INTERLEAVE_MASK)
/*! @} */

/*! @name DAC_CLKSEL - DAC0 Functional Clock Selection..DAC2 Functional Clock Selection */
/*! @{ */

#define SYSCON_DAC_CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_DAC_CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the DAC clock source
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..Clk_in
 *  0b011..FRO_HF
 *  0b100..FRO_12M
 *  0b101..PLL1_clk0 clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_DAC_CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKSEL_SEL_SHIFT)) & SYSCON_DAC_CLKSEL_SEL_MASK)
/*! @} */

/* The count of SYSCON_DAC_CLKSEL */
#define SYSCON_DAC_CLKSEL_COUNT                  (3U)

/*! @name DAC_CLKDIV - DAC0 functional clock divider..DAC2 functional clock divider */
/*! @{ */

#define SYSCON_DAC_CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_DAC_CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_DAC_CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_DIV_SHIFT)) & SYSCON_DAC_CLKDIV_DIV_MASK)

#define SYSCON_DAC_CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_DAC_CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_DAC_CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_RESET_SHIFT)) & SYSCON_DAC_CLKDIV_RESET_MASK)

#define SYSCON_DAC_CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_DAC_CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_DAC_CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_HALT_SHIFT)) & SYSCON_DAC_CLKDIV_HALT_MASK)

#define SYSCON_DAC_CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_DAC_CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_DAC_CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_UNSTAB_SHIFT)) & SYSCON_DAC_CLKDIV_UNSTAB_MASK)
/*! @} */

/* The count of SYSCON_DAC_CLKDIV */
#define SYSCON_DAC_CLKDIV_COUNT                  (3U)

/*! @name FLEXSPICLKSEL - FlexSPI Clock Selection */
/*! @{ */

#define SYSCON_FLEXSPICLKSEL_SEL_MASK            (0xFU)
#define SYSCON_FLEXSPICLKSEL_SEL_SHIFT           (0U)
/*! SEL - Selects the FlexSPI clock
 *  0b0000..No clock
 *  0b0001..PLL0 clock
 *  0b0010..No clock
 *  0b0011..FRO_HF
 *  0b0100..No clock
 *  0b0101..pll1_clock
 *  0b0110..USB PLL clock
 *  0b0111..No clock
 *  0b1000..No clock
 *  0b1001..No clock
 *  0b1010..No clock
 *  0b1011..No clock
 *  0b1100..No clock
 *  0b1101..No clock
 *  0b1110..No clock
 *  0b1111..No clock
 */
#define SYSCON_FLEXSPICLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKSEL_SEL_SHIFT)) & SYSCON_FLEXSPICLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXSPICLKDIV - FlexSPI Clock Divider */
/*! @{ */

#define SYSCON_FLEXSPICLKDIV_DIV_MASK            (0x7U)
#define SYSCON_FLEXSPICLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value */
#define SYSCON_FLEXSPICLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_DIV_SHIFT)) & SYSCON_FLEXSPICLKDIV_DIV_MASK)

#define SYSCON_FLEXSPICLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_FLEXSPICLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FLEXSPICLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_RESET_SHIFT)) & SYSCON_FLEXSPICLKDIV_RESET_MASK)

#define SYSCON_FLEXSPICLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_FLEXSPICLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FLEXSPICLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_HALT_SHIFT)) & SYSCON_FLEXSPICLKDIV_HALT_MASK)

#define SYSCON_FLEXSPICLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_FLEXSPICLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FLEXSPICLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_UNSTAB_SHIFT)) & SYSCON_FLEXSPICLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name PLLCLKDIVSEL - PLL Clock Divider Clock Selection */
/*! @{ */

#define SYSCON_PLLCLKDIVSEL_SEL_MASK             (0x7U)
#define SYSCON_PLLCLKDIVSEL_SEL_SHIFT            (0U)
/*! SEL - Selects the PLL Clock Divider source clock
 *  0b000..PLL0 clock
 *  0b001..pll1_clk0
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_PLLCLKDIVSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIVSEL_SEL_SHIFT)) & SYSCON_PLLCLKDIVSEL_SEL_MASK)
/*! @} */

/*! @name I3C0FCLKSEL - I3C0 Functional Clock Selection */
/*! @{ */

#define SYSCON_I3C0FCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_I3C0FCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Selects the I3C0 clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..No clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_I3C0FCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSEL_SEL_SHIFT)) & SYSCON_I3C0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name I3C0FCLKSTCSEL - I3C0 FCLK_STC Clock Selection */
/*! @{ */

#define SYSCON_I3C0FCLKSTCSEL_SEL_MASK           (0x7U)
#define SYSCON_I3C0FCLKSTCSEL_SEL_SHIFT          (0U)
/*! SEL - Selects the I3C0 Time Control clock
 *  0b000..I3C0 functional clock I3C0FCLK
 *  0b001..FRO_1M clock
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_I3C0FCLKSTCSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSTCSEL_SEL_SHIFT)) & SYSCON_I3C0FCLKSTCSEL_SEL_MASK)
/*! @} */

/*! @name I3C0FCLKSTCDIV - I3C0 FCLK_STC Clock Divider */
/*! @{ */

#define SYSCON_I3C0FCLKSTCDIV_DIV_MASK           (0xFFU)
#define SYSCON_I3C0FCLKSTCDIV_DIV_SHIFT          (0U)
/*! DIV - Clock divider value */
#define SYSCON_I3C0FCLKSTCDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSTCDIV_DIV_SHIFT)) & SYSCON_I3C0FCLKSTCDIV_DIV_MASK)

#define SYSCON_I3C0FCLKSTCDIV_RESET_MASK         (0x20000000U)
#define SYSCON_I3C0FCLKSTCDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_I3C0FCLKSTCDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSTCDIV_RESET_SHIFT)) & SYSCON_I3C0FCLKSTCDIV_RESET_MASK)

#define SYSCON_I3C0FCLKSTCDIV_HALT_MASK          (0x40000000U)
#define SYSCON_I3C0FCLKSTCDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_I3C0FCLKSTCDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSTCDIV_HALT_SHIFT)) & SYSCON_I3C0FCLKSTCDIV_HALT_MASK)

#define SYSCON_I3C0FCLKSTCDIV_UNSTAB_MASK        (0x80000000U)
#define SYSCON_I3C0FCLKSTCDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_I3C0FCLKSTCDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSTCDIV_UNSTAB_SHIFT)) & SYSCON_I3C0FCLKSTCDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3C0FCLKSDIV - I3C0 FCLK Slow Clock Divider */
/*! @{ */

#define SYSCON_I3C0FCLKSDIV_DIV_MASK             (0xFFU)
#define SYSCON_I3C0FCLKSDIV_DIV_SHIFT            (0U)
/*! DIV - Clock divider value */
#define SYSCON_I3C0FCLKSDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSDIV_DIV_SHIFT)) & SYSCON_I3C0FCLKSDIV_DIV_MASK)

#define SYSCON_I3C0FCLKSDIV_RESET_MASK           (0x20000000U)
#define SYSCON_I3C0FCLKSDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_I3C0FCLKSDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSDIV_RESET_SHIFT)) & SYSCON_I3C0FCLKSDIV_RESET_MASK)

#define SYSCON_I3C0FCLKSDIV_HALT_MASK            (0x40000000U)
#define SYSCON_I3C0FCLKSDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_I3C0FCLKSDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSDIV_HALT_SHIFT)) & SYSCON_I3C0FCLKSDIV_HALT_MASK)

#define SYSCON_I3C0FCLKSDIV_UNSTAB_MASK          (0x80000000U)
#define SYSCON_I3C0FCLKSDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_I3C0FCLKSDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSDIV_UNSTAB_SHIFT)) & SYSCON_I3C0FCLKSDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3C0FCLKDIV - I3C0 Functional Clock FCLK Divider */
/*! @{ */

#define SYSCON_I3C0FCLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_I3C0FCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_I3C0FCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKDIV_DIV_SHIFT)) & SYSCON_I3C0FCLKDIV_DIV_MASK)

#define SYSCON_I3C0FCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_I3C0FCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_I3C0FCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKDIV_RESET_SHIFT)) & SYSCON_I3C0FCLKDIV_RESET_MASK)

#define SYSCON_I3C0FCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_I3C0FCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_I3C0FCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKDIV_HALT_SHIFT)) & SYSCON_I3C0FCLKDIV_HALT_MASK)

#define SYSCON_I3C0FCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_I3C0FCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_I3C0FCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKDIV_UNSTAB_SHIFT)) & SYSCON_I3C0FCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3C0FCLKSSEL - I3C0 FCLK Slow Selection */
/*! @{ */

#define SYSCON_I3C0FCLKSSEL_SEL_MASK             (0x7U)
#define SYSCON_I3C0FCLKSSEL_SEL_SHIFT            (0U)
/*! SEL - Selects the I3C FCLK Slow clock
 *  0b000..FRO_1M clock
 *  0b001..No clock
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_I3C0FCLKSSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C0FCLKSSEL_SEL_SHIFT)) & SYSCON_I3C0FCLKSSEL_SEL_MASK)
/*! @} */

/*! @name MICFILFCLKSEL - MICFIL Clock Selection */
/*! @{ */

#define SYSCON_MICFILFCLKSEL_SEL_MASK            (0xFU)
#define SYSCON_MICFILFCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Selects the MICFIL clock
 *  0b0000..FRO_12M clock
 *  0b0001..PLL0 clock
 *  0b0010..CLKIN clock
 *  0b0011..FRO_HF clock
 *  0b0100..PLL1_clk0 clock
 *  0b0101..SAI0_MCLK clock
 *  0b0110..USB PLL clock
 *  0b0111..No clock
 *  0b1000..SAI1_MCLK clock
 *  0b1001..No clock
 *  0b1010..No clock
 *  0b1011..No clock
 *  0b1100..No clock
 *  0b1101..No clock
 *  0b1110..No clock
 *  0b1111..No clock
 */
#define SYSCON_MICFILFCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_MICFILFCLKSEL_SEL_SHIFT)) & SYSCON_MICFILFCLKSEL_SEL_MASK)
/*! @} */

/*! @name MICFILFCLKDIV - MICFIL Clock Division */
/*! @{ */

#define SYSCON_MICFILFCLKDIV_DIV_MASK            (0x7U)
#define SYSCON_MICFILFCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value */
#define SYSCON_MICFILFCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_MICFILFCLKDIV_DIV_SHIFT)) & SYSCON_MICFILFCLKDIV_DIV_MASK)

#define SYSCON_MICFILFCLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_MICFILFCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_MICFILFCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_MICFILFCLKDIV_RESET_SHIFT)) & SYSCON_MICFILFCLKDIV_RESET_MASK)

#define SYSCON_MICFILFCLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_MICFILFCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_MICFILFCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_MICFILFCLKDIV_HALT_SHIFT)) & SYSCON_MICFILFCLKDIV_HALT_MASK)

#define SYSCON_MICFILFCLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_MICFILFCLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_MICFILFCLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_MICFILFCLKDIV_UNSTAB_SHIFT)) & SYSCON_MICFILFCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name USDHCCLKSEL - uSDHC Clock Selection */
/*! @{ */

#define SYSCON_USDHCCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_USDHCCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Selects the uSDHC clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..FRO_12M clock
 *  0b101..pll1_clk1 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_USDHCCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USDHCCLKSEL_SEL_SHIFT)) & SYSCON_USDHCCLKSEL_SEL_MASK)
/*! @} */

/*! @name USDHCCLKDIV - uSDHC Function Clock Divider */
/*! @{ */

#define SYSCON_USDHCCLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_USDHCCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_USDHCCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USDHCCLKDIV_DIV_SHIFT)) & SYSCON_USDHCCLKDIV_DIV_MASK)

#define SYSCON_USDHCCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_USDHCCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_USDHCCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_USDHCCLKDIV_RESET_SHIFT)) & SYSCON_USDHCCLKDIV_RESET_MASK)

#define SYSCON_USDHCCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_USDHCCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_USDHCCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_USDHCCLKDIV_HALT_SHIFT)) & SYSCON_USDHCCLKDIV_HALT_MASK)

#define SYSCON_USDHCCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_USDHCCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_USDHCCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_USDHCCLKDIV_UNSTAB_SHIFT)) & SYSCON_USDHCCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name FLEXIOCLKSEL - FLEXIO Clock Selection */
/*! @{ */

#define SYSCON_FLEXIOCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_FLEXIOCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Selects the FLEXIO clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..FRO_12M clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_FLEXIOCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXIOCLKSEL_SEL_SHIFT)) & SYSCON_FLEXIOCLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXIOCLKDIV - FLEXIO Function Clock Divider */
/*! @{ */

#define SYSCON_FLEXIOCLKDIV_DIV_MASK             (0xFFU)
#define SYSCON_FLEXIOCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock divider value */
#define SYSCON_FLEXIOCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXIOCLKDIV_DIV_SHIFT)) & SYSCON_FLEXIOCLKDIV_DIV_MASK)

#define SYSCON_FLEXIOCLKDIV_RESET_MASK           (0x20000000U)
#define SYSCON_FLEXIOCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FLEXIOCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXIOCLKDIV_RESET_SHIFT)) & SYSCON_FLEXIOCLKDIV_RESET_MASK)

#define SYSCON_FLEXIOCLKDIV_HALT_MASK            (0x40000000U)
#define SYSCON_FLEXIOCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FLEXIOCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXIOCLKDIV_HALT_SHIFT)) & SYSCON_FLEXIOCLKDIV_HALT_MASK)

#define SYSCON_FLEXIOCLKDIV_UNSTAB_MASK          (0x80000000U)
#define SYSCON_FLEXIOCLKDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FLEXIOCLKDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXIOCLKDIV_UNSTAB_SHIFT)) & SYSCON_FLEXIOCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name FLEXCAN0CLKSEL - FLEXCAN0 Clock Selection */
/*! @{ */

#define SYSCON_FLEXCAN0CLKSEL_SEL_MASK           (0x7U)
#define SYSCON_FLEXCAN0CLKSEL_SEL_SHIFT          (0U)
/*! SEL - Selects the FLEXCAN0 clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..No clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_FLEXCAN0CLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN0CLKSEL_SEL_SHIFT)) & SYSCON_FLEXCAN0CLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXCAN0CLKDIV - FLEXCAN0 Function Clock Divider */
/*! @{ */

#define SYSCON_FLEXCAN0CLKDIV_DIV_MASK           (0xFFU)
#define SYSCON_FLEXCAN0CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock divider value */
#define SYSCON_FLEXCAN0CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN0CLKDIV_DIV_SHIFT)) & SYSCON_FLEXCAN0CLKDIV_DIV_MASK)

#define SYSCON_FLEXCAN0CLKDIV_RESET_MASK         (0x20000000U)
#define SYSCON_FLEXCAN0CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FLEXCAN0CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN0CLKDIV_RESET_SHIFT)) & SYSCON_FLEXCAN0CLKDIV_RESET_MASK)

#define SYSCON_FLEXCAN0CLKDIV_HALT_MASK          (0x40000000U)
#define SYSCON_FLEXCAN0CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FLEXCAN0CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN0CLKDIV_HALT_SHIFT)) & SYSCON_FLEXCAN0CLKDIV_HALT_MASK)

#define SYSCON_FLEXCAN0CLKDIV_UNSTAB_MASK        (0x80000000U)
#define SYSCON_FLEXCAN0CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FLEXCAN0CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN0CLKDIV_UNSTAB_SHIFT)) & SYSCON_FLEXCAN0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name FLEXCAN1CLKSEL - FLEXCAN1 Clock Selection */
/*! @{ */

#define SYSCON_FLEXCAN1CLKSEL_SEL_MASK           (0x7U)
#define SYSCON_FLEXCAN1CLKSEL_SEL_SHIFT          (0U)
/*! SEL - Selects the FLEXCAN1 clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..No clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_FLEXCAN1CLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN1CLKSEL_SEL_SHIFT)) & SYSCON_FLEXCAN1CLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXCAN1CLKDIV - FLEXCAN1 Function Clock Divider */
/*! @{ */

#define SYSCON_FLEXCAN1CLKDIV_DIV_MASK           (0xFFU)
#define SYSCON_FLEXCAN1CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock divider value */
#define SYSCON_FLEXCAN1CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN1CLKDIV_DIV_SHIFT)) & SYSCON_FLEXCAN1CLKDIV_DIV_MASK)

#define SYSCON_FLEXCAN1CLKDIV_RESET_MASK         (0x20000000U)
#define SYSCON_FLEXCAN1CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FLEXCAN1CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN1CLKDIV_RESET_SHIFT)) & SYSCON_FLEXCAN1CLKDIV_RESET_MASK)

#define SYSCON_FLEXCAN1CLKDIV_HALT_MASK          (0x40000000U)
#define SYSCON_FLEXCAN1CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FLEXCAN1CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN1CLKDIV_HALT_SHIFT)) & SYSCON_FLEXCAN1CLKDIV_HALT_MASK)

#define SYSCON_FLEXCAN1CLKDIV_UNSTAB_MASK        (0x80000000U)
#define SYSCON_FLEXCAN1CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FLEXCAN1CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCAN1CLKDIV_UNSTAB_SHIFT)) & SYSCON_FLEXCAN1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name ENETRMIICLKSEL - Ethernet RMII Clock Selection */
/*! @{ */

#define SYSCON_ENETRMIICLKSEL_SEL_MASK           (0x7U)
#define SYSCON_ENETRMIICLKSEL_SEL_SHIFT          (0U)
/*! SEL - Selects the Ethernet RMII clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..PLL1_clk0 clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_ENETRMIICLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETRMIICLKSEL_SEL_SHIFT)) & SYSCON_ENETRMIICLKSEL_SEL_MASK)
/*! @} */

/*! @name ENETRMIICLKDIV - Ethernet RMII Function Clock Divider */
/*! @{ */

#define SYSCON_ENETRMIICLKDIV_DIV_MASK           (0xFFU)
#define SYSCON_ENETRMIICLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock divider value */
#define SYSCON_ENETRMIICLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETRMIICLKDIV_DIV_SHIFT)) & SYSCON_ENETRMIICLKDIV_DIV_MASK)

#define SYSCON_ENETRMIICLKDIV_RESET_MASK         (0x20000000U)
#define SYSCON_ENETRMIICLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_ENETRMIICLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETRMIICLKDIV_RESET_SHIFT)) & SYSCON_ENETRMIICLKDIV_RESET_MASK)

#define SYSCON_ENETRMIICLKDIV_HALT_MASK          (0x40000000U)
#define SYSCON_ENETRMIICLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_ENETRMIICLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETRMIICLKDIV_HALT_SHIFT)) & SYSCON_ENETRMIICLKDIV_HALT_MASK)

#define SYSCON_ENETRMIICLKDIV_UNSTAB_MASK        (0x80000000U)
#define SYSCON_ENETRMIICLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_ENETRMIICLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETRMIICLKDIV_UNSTAB_SHIFT)) & SYSCON_ENETRMIICLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name ENETPTPREFCLKSEL - Ethernet PTP REF Clock Selection */
/*! @{ */

#define SYSCON_ENETPTPREFCLKSEL_SEL_MASK         (0x7U)
#define SYSCON_ENETPTPREFCLKSEL_SEL_SHIFT        (0U)
/*! SEL - Selects the Ethernet PTP REF clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..No clock
 *  0b100..enet0_tx_clk clock
 *  0b101..pll1_clk1 clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_ENETPTPREFCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETPTPREFCLKSEL_SEL_SHIFT)) & SYSCON_ENETPTPREFCLKSEL_SEL_MASK)
/*! @} */

/*! @name ENETPTPREFCLKDIV - Ethernet PTP REF Function Clock Divider */
/*! @{ */

#define SYSCON_ENETPTPREFCLKDIV_DIV_MASK         (0xFFU)
#define SYSCON_ENETPTPREFCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock divider value */
#define SYSCON_ENETPTPREFCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETPTPREFCLKDIV_DIV_SHIFT)) & SYSCON_ENETPTPREFCLKDIV_DIV_MASK)

#define SYSCON_ENETPTPREFCLKDIV_RESET_MASK       (0x20000000U)
#define SYSCON_ENETPTPREFCLKDIV_RESET_SHIFT      (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_ENETPTPREFCLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETPTPREFCLKDIV_RESET_SHIFT)) & SYSCON_ENETPTPREFCLKDIV_RESET_MASK)

#define SYSCON_ENETPTPREFCLKDIV_HALT_MASK        (0x40000000U)
#define SYSCON_ENETPTPREFCLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_ENETPTPREFCLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETPTPREFCLKDIV_HALT_SHIFT)) & SYSCON_ENETPTPREFCLKDIV_HALT_MASK)

#define SYSCON_ENETPTPREFCLKDIV_UNSTAB_MASK      (0x80000000U)
#define SYSCON_ENETPTPREFCLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_ENETPTPREFCLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ENETPTPREFCLKDIV_UNSTAB_SHIFT)) & SYSCON_ENETPTPREFCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name ENET_PHY_INTF_SEL - Ethernet PHY Interface Select */
/*! @{ */

#define SYSCON_ENET_PHY_INTF_SEL_PHY_SEL_MASK    (0x4U)
#define SYSCON_ENET_PHY_INTF_SEL_PHY_SEL_SHIFT   (2U)
/*! PHY_SEL - Selects the PHY interface
 *  0b0..Selects MII PHY Interface
 *  0b1..Selects RMII PHY Interface
 */
#define SYSCON_ENET_PHY_INTF_SEL_PHY_SEL(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ENET_PHY_INTF_SEL_PHY_SEL_SHIFT)) & SYSCON_ENET_PHY_INTF_SEL_PHY_SEL_MASK)
/*! @} */

/*! @name ENET_SBD_FLOW_CTRL - Sideband Flow Control */
/*! @{ */

#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch0_MASK   (0x1U)
#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch0_SHIFT  (0U)
/*! SEL_ch0 - Sideband Flow Control for channel0
 *  0b0..No trigger flow control
 *  0b1..Trigger flow control
 */
#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch0_SHIFT)) & SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch0_MASK)

#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch1_MASK   (0x2U)
#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch1_SHIFT  (1U)
/*! SEL_ch1 - Sideband Flow Control for channel1
 *  0b0..No trigger flow control
 *  0b1..Trigger flow control
 */
#define SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch1(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch1_SHIFT)) & SYSCON_ENET_SBD_FLOW_CTRL_SEL_ch1_MASK)
/*! @} */

/*! @name EWM0CLKSEL - EWM0 Clock Selection */
/*! @{ */

#define SYSCON_EWM0CLKSEL_SEL_MASK               (0x1U)
#define SYSCON_EWM0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the EWM0 clock
 *  0b0..clk_16k[2]
 *  0b1..xtal32k[2]
 */
#define SYSCON_EWM0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_EWM0CLKSEL_SEL_SHIFT)) & SYSCON_EWM0CLKSEL_SEL_MASK)
/*! @} */

/*! @name WDT1CLKSEL - WDT1 Clock Selection */
/*! @{ */

#define SYSCON_WDT1CLKSEL_SEL_MASK               (0x3U)
#define SYSCON_WDT1CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the WDT1 clock
 *  0b00..FRO16K clock 2
 *  0b01..fro_hf_div clock
 *  0b10..clk_1m clock
 *  0b11..clk_1m clock
 */
#define SYSCON_WDT1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT1CLKSEL_SEL_SHIFT)) & SYSCON_WDT1CLKSEL_SEL_MASK)
/*! @} */

/*! @name WDT1CLKDIV - WDT1 Function Clock Divider */
/*! @{ */

#define SYSCON_WDT1CLKDIV_DIV_MASK               (0x3FU)
#define SYSCON_WDT1CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_WDT1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT1CLKDIV_DIV_SHIFT)) & SYSCON_WDT1CLKDIV_DIV_MASK)

#define SYSCON_WDT1CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_WDT1CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_WDT1CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT1CLKDIV_RESET_SHIFT)) & SYSCON_WDT1CLKDIV_RESET_MASK)

#define SYSCON_WDT1CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_WDT1CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_WDT1CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT1CLKDIV_HALT_SHIFT)) & SYSCON_WDT1CLKDIV_HALT_MASK)

#define SYSCON_WDT1CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_WDT1CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_WDT1CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_WDT1CLKDIV_UNSTAB_SHIFT)) & SYSCON_WDT1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name OSTIMERCLKSEL - OSTIMER Clock Selection */
/*! @{ */

#define SYSCON_OSTIMERCLKSEL_SEL_MASK            (0x3U)
#define SYSCON_OSTIMERCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Selects the OS Event Timer clock
 *  0b00..clk_16k[2]
 *  0b01..xtal32k[2]
 *  0b10..clk_1m clock
 *  0b11..No clock
 */
#define SYSCON_OSTIMERCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_OSTIMERCLKSEL_SEL_SHIFT)) & SYSCON_OSTIMERCLKSEL_SEL_MASK)
/*! @} */

/*! @name CMP0FCLKSEL - CMP0 Function Clock Selection */
/*! @{ */

#define SYSCON_CMP0FCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_CMP0FCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Selects the CMP0 function clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO_12M clock
 *  0b100..CLKIN clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_CMP0FCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0FCLKSEL_SEL_SHIFT)) & SYSCON_CMP0FCLKSEL_SEL_MASK)
/*! @} */

/*! @name CMP0FCLKDIV - CMP0 Function Clock Divider */
/*! @{ */

#define SYSCON_CMP0FCLKDIV_DIV_MASK              (0xFU)
#define SYSCON_CMP0FCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_CMP0FCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0FCLKDIV_DIV_SHIFT)) & SYSCON_CMP0FCLKDIV_DIV_MASK)

#define SYSCON_CMP0FCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_CMP0FCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CMP0FCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0FCLKDIV_RESET_SHIFT)) & SYSCON_CMP0FCLKDIV_RESET_MASK)

#define SYSCON_CMP0FCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_CMP0FCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_CMP0FCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0FCLKDIV_HALT_SHIFT)) & SYSCON_CMP0FCLKDIV_HALT_MASK)

#define SYSCON_CMP0FCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_CMP0FCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_CMP0FCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0FCLKDIV_UNSTAB_SHIFT)) & SYSCON_CMP0FCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CMP0RRCLKSEL - CMP0 Round Robin Clock Selection */
/*! @{ */

#define SYSCON_CMP0RRCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_CMP0RRCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Selects the CMP0 round robin clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO_12M clock
 *  0b100..CLKIN clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_CMP0RRCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0RRCLKSEL_SEL_SHIFT)) & SYSCON_CMP0RRCLKSEL_SEL_MASK)
/*! @} */

/*! @name CMP0RRCLKDIV - CMP0 Round Robin Clock Divider */
/*! @{ */

#define SYSCON_CMP0RRCLKDIV_DIV_MASK             (0xFU)
#define SYSCON_CMP0RRCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock divider value */
#define SYSCON_CMP0RRCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0RRCLKDIV_DIV_SHIFT)) & SYSCON_CMP0RRCLKDIV_DIV_MASK)

#define SYSCON_CMP0RRCLKDIV_RESET_MASK           (0x20000000U)
#define SYSCON_CMP0RRCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CMP0RRCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0RRCLKDIV_RESET_SHIFT)) & SYSCON_CMP0RRCLKDIV_RESET_MASK)

#define SYSCON_CMP0RRCLKDIV_HALT_MASK            (0x40000000U)
#define SYSCON_CMP0RRCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_CMP0RRCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0RRCLKDIV_HALT_SHIFT)) & SYSCON_CMP0RRCLKDIV_HALT_MASK)

#define SYSCON_CMP0RRCLKDIV_UNSTAB_MASK          (0x80000000U)
#define SYSCON_CMP0RRCLKDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_CMP0RRCLKDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP0RRCLKDIV_UNSTAB_SHIFT)) & SYSCON_CMP0RRCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CMP1FCLKSEL - CMP1 Function Clock Selection */
/*! @{ */

#define SYSCON_CMP1FCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_CMP1FCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Selects the CMP1 function clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO_12M clock
 *  0b100..CLKIN clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_CMP1FCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1FCLKSEL_SEL_SHIFT)) & SYSCON_CMP1FCLKSEL_SEL_MASK)
/*! @} */

/*! @name CMP1FCLKDIV - CMP1 Function Clock Divider */
/*! @{ */

#define SYSCON_CMP1FCLKDIV_DIV_MASK              (0xFU)
#define SYSCON_CMP1FCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_CMP1FCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1FCLKDIV_DIV_SHIFT)) & SYSCON_CMP1FCLKDIV_DIV_MASK)

#define SYSCON_CMP1FCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_CMP1FCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CMP1FCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1FCLKDIV_RESET_SHIFT)) & SYSCON_CMP1FCLKDIV_RESET_MASK)

#define SYSCON_CMP1FCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_CMP1FCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_CMP1FCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1FCLKDIV_HALT_SHIFT)) & SYSCON_CMP1FCLKDIV_HALT_MASK)

#define SYSCON_CMP1FCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_CMP1FCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_CMP1FCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1FCLKDIV_UNSTAB_SHIFT)) & SYSCON_CMP1FCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CMP1RRCLKSEL - CMP1 Round Robin Clock Source Select */
/*! @{ */

#define SYSCON_CMP1RRCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_CMP1RRCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Selects the CMP1 round robin clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO_12M clock
 *  0b100..CLKIN clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_CMP1RRCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1RRCLKSEL_SEL_SHIFT)) & SYSCON_CMP1RRCLKSEL_SEL_MASK)
/*! @} */

/*! @name CMP1RRCLKDIV - CMP1 Round Robin Clock Division */
/*! @{ */

#define SYSCON_CMP1RRCLKDIV_DIV_MASK             (0xFU)
#define SYSCON_CMP1RRCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock divider value */
#define SYSCON_CMP1RRCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1RRCLKDIV_DIV_SHIFT)) & SYSCON_CMP1RRCLKDIV_DIV_MASK)

#define SYSCON_CMP1RRCLKDIV_RESET_MASK           (0x20000000U)
#define SYSCON_CMP1RRCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CMP1RRCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1RRCLKDIV_RESET_SHIFT)) & SYSCON_CMP1RRCLKDIV_RESET_MASK)

#define SYSCON_CMP1RRCLKDIV_HALT_MASK            (0x40000000U)
#define SYSCON_CMP1RRCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_CMP1RRCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1RRCLKDIV_HALT_SHIFT)) & SYSCON_CMP1RRCLKDIV_HALT_MASK)

#define SYSCON_CMP1RRCLKDIV_UNSTAB_MASK          (0x80000000U)
#define SYSCON_CMP1RRCLKDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_CMP1RRCLKDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP1RRCLKDIV_UNSTAB_SHIFT)) & SYSCON_CMP1RRCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CMP2FCLKSEL - CMP2 Function Clock Source Select */
/*! @{ */

#define SYSCON_CMP2FCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_CMP2FCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Selects the CMP2 function clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO_12M clock
 *  0b100..CLKIN clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_CMP2FCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2FCLKSEL_SEL_SHIFT)) & SYSCON_CMP2FCLKSEL_SEL_MASK)
/*! @} */

/*! @name CMP2FCLKDIV - CMP2 Function Clock Division */
/*! @{ */

#define SYSCON_CMP2FCLKDIV_DIV_MASK              (0xFU)
#define SYSCON_CMP2FCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_CMP2FCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2FCLKDIV_DIV_SHIFT)) & SYSCON_CMP2FCLKDIV_DIV_MASK)

#define SYSCON_CMP2FCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_CMP2FCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CMP2FCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2FCLKDIV_RESET_SHIFT)) & SYSCON_CMP2FCLKDIV_RESET_MASK)

#define SYSCON_CMP2FCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_CMP2FCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_CMP2FCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2FCLKDIV_HALT_SHIFT)) & SYSCON_CMP2FCLKDIV_HALT_MASK)

#define SYSCON_CMP2FCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_CMP2FCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_CMP2FCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2FCLKDIV_UNSTAB_SHIFT)) & SYSCON_CMP2FCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CMP2RRCLKSEL - CMP2 Round Robin Clock Source Select */
/*! @{ */

#define SYSCON_CMP2RRCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_CMP2RRCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Selects the CMP2 round robin clock
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..FRO_HF clock
 *  0b011..FRO_12M clock
 *  0b100..CLKIN clock
 *  0b101..PLL1_clk0 clock0
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_CMP2RRCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2RRCLKSEL_SEL_SHIFT)) & SYSCON_CMP2RRCLKSEL_SEL_MASK)
/*! @} */

/*! @name CMP2RRCLKDIV - CMP2 Round Robin Clock Division */
/*! @{ */

#define SYSCON_CMP2RRCLKDIV_DIV_MASK             (0xFU)
#define SYSCON_CMP2RRCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock divider value */
#define SYSCON_CMP2RRCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2RRCLKDIV_DIV_SHIFT)) & SYSCON_CMP2RRCLKDIV_DIV_MASK)

#define SYSCON_CMP2RRCLKDIV_RESET_MASK           (0x20000000U)
#define SYSCON_CMP2RRCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CMP2RRCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2RRCLKDIV_RESET_SHIFT)) & SYSCON_CMP2RRCLKDIV_RESET_MASK)

#define SYSCON_CMP2RRCLKDIV_HALT_MASK            (0x40000000U)
#define SYSCON_CMP2RRCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_CMP2RRCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2RRCLKDIV_HALT_SHIFT)) & SYSCON_CMP2RRCLKDIV_HALT_MASK)

#define SYSCON_CMP2RRCLKDIV_UNSTAB_MASK          (0x80000000U)
#define SYSCON_CMP2RRCLKDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_CMP2RRCLKDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_CMP2RRCLKDIV_UNSTAB_SHIFT)) & SYSCON_CMP2RRCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CPUCTRL - CPU Control for Multiple Processors */
/*! @{ */

#define SYSCON_CPUCTRL_CPU1CLKEN_MASK            (0x8U)
#define SYSCON_CPUCTRL_CPU1CLKEN_SHIFT           (3U)
/*! CPU1CLKEN - Enables the CPU1 clock
 *  0b0..The CPU1 clock is not enabled
 *  0b1..The CPU1 clock is enabled
 */
#define SYSCON_CPUCTRL_CPU1CLKEN(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_CPU1CLKEN_SHIFT)) & SYSCON_CPUCTRL_CPU1CLKEN_MASK)

#define SYSCON_CPUCTRL_CPU1RSTEN_MASK            (0x20U)
#define SYSCON_CPUCTRL_CPU1RSTEN_SHIFT           (5U)
/*! CPU1RSTEN - CPU1 reset
 *  0b0..The CPU1 is not reset.
 *  0b1..The CPU1 is reset.
 */
#define SYSCON_CPUCTRL_CPU1RSTEN(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_CPU1RSTEN_SHIFT)) & SYSCON_CPUCTRL_CPU1RSTEN_MASK)

#define SYSCON_CPUCTRL_PROT_MASK                 (0xFFFF0000U)
#define SYSCON_CPUCTRL_PROT_SHIFT                (16U)
/*! PROT - Write Protect
 *  0b1100000011000100..For write operation to have an effect.
 */
#define SYSCON_CPUCTRL_PROT(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_PROT_SHIFT)) & SYSCON_CPUCTRL_PROT_MASK)
/*! @} */

/*! @name CPBOOT - Coprocessor Boot Address */
/*! @{ */

#define SYSCON_CPBOOT_CPBOOT_MASK                (0xFFFFFF80U)
#define SYSCON_CPBOOT_CPBOOT_SHIFT               (7U)
/*! CPBOOT - Coprocessor Boot VTOR Address [31:7] for CPU1 */
#define SYSCON_CPBOOT_CPBOOT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CPBOOT_CPBOOT_SHIFT)) & SYSCON_CPBOOT_CPBOOT_MASK)
/*! @} */

/*! @name CPUSTAT - CPU Status */
/*! @{ */

#define SYSCON_CPUSTAT_CPU0SLEEPING_MASK         (0x1U)
#define SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT        (0U)
/*! CPU0SLEEPING - CPU0 sleeping state
 *  0b0..CPU is not sleeping
 *  0b1..CPU is sleeping
 */
#define SYSCON_CPUSTAT_CPU0SLEEPING(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT)) & SYSCON_CPUSTAT_CPU0SLEEPING_MASK)

#define SYSCON_CPUSTAT_CPU1SLEEPING_MASK         (0x2U)
#define SYSCON_CPUSTAT_CPU1SLEEPING_SHIFT        (1U)
/*! CPU1SLEEPING - CPU1 sleeping state
 *  0b0..CPU is not sleeping
 *  0b1..CPU is sleeping
 */
#define SYSCON_CPUSTAT_CPU1SLEEPING(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU1SLEEPING_SHIFT)) & SYSCON_CPUSTAT_CPU1SLEEPING_MASK)

#define SYSCON_CPUSTAT_CPU0LOCKUP_MASK           (0x4U)
#define SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT          (2U)
/*! CPU0LOCKUP - CPU0 lockup state
 *  0b0..CPU is not in lockup
 *  0b1..CPU is in lockup
 */
#define SYSCON_CPUSTAT_CPU0LOCKUP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT)) & SYSCON_CPUSTAT_CPU0LOCKUP_MASK)

#define SYSCON_CPUSTAT_CPU1LOCKUP_MASK           (0x8U)
#define SYSCON_CPUSTAT_CPU1LOCKUP_SHIFT          (3U)
/*! CPU1LOCKUP - CPU1 lockup state
 *  0b0..CPU is not in lockup
 *  0b1..CPU is in lockup
 */
#define SYSCON_CPUSTAT_CPU1LOCKUP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU1LOCKUP_SHIFT)) & SYSCON_CPUSTAT_CPU1LOCKUP_MASK)
/*! @} */

/*! @name LPCAC_CTRL - LPCAC Control */
/*! @{ */

#define SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK         (0x1U)
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT        (0U)
/*! DIS_LPCAC - Disables/enables the cache function.
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define SYSCON_LPCAC_CTRL_DIS_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK         (0x2U)
#define SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT        (1U)
/*! CLR_LPCAC - Clears the cache function.
 *  0b0..Unclears the cache
 *  0b1..Clears the cache
 */
#define SYSCON_LPCAC_CTRL_CLR_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK      (0x4U)
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT     (2U)
/*! FRC_NO_ALLOC - Forces no allocation.
 *  0b0..Forces allocation
 *  0b1..Forces no allocation
 */
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT)) & SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK)

#define SYSCON_LPCAC_CTRL_PARITY_MISS_EN_MASK    (0x8U)
#define SYSCON_LPCAC_CTRL_PARITY_MISS_EN_SHIFT   (3U)
/*! PARITY_MISS_EN - Enables parity miss.
 *  0b0..Disabled
 *  0b1..Enables parity, miss on parity error
 */
#define SYSCON_LPCAC_CTRL_PARITY_MISS_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_PARITY_MISS_EN_SHIFT)) & SYSCON_LPCAC_CTRL_PARITY_MISS_EN_MASK)

#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_MASK    (0x10U)
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_SHIFT   (4U)
/*! DIS_LPCAC_WTBF - Disable LPCAC Write Through Buffer.
 *  0b0..Enables write through buffer
 *  0b1..Disables write through buffer
 */
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_SHIFT)) & SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_MASK)

#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_MASK    (0x20U)
#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_SHIFT   (5U)
/*! LIM_LPCAC_WTBF - Limit LPCAC Write Through Buffer.
 *  0b0..Write buffer enabled when transaction is bufferable.
 *  0b1..Write buffer enabled when transaction is cacheable and bufferable
 */
#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_SHIFT)) & SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_MASK)

#define SYSCON_LPCAC_CTRL_PARITY_FAULT_EN_MASK   (0x40U)
#define SYSCON_LPCAC_CTRL_PARITY_FAULT_EN_SHIFT  (6U)
/*! PARITY_FAULT_EN - Enable parity error report.
 *  0b0..Disables parity error report
 *  0b1..Enables parity error report
 */
#define SYSCON_LPCAC_CTRL_PARITY_FAULT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_PARITY_FAULT_EN_SHIFT)) & SYSCON_LPCAC_CTRL_PARITY_FAULT_EN_MASK)

#define SYSCON_LPCAC_CTRL_LPCAC_XOM_MASK         (0x80U)
#define SYSCON_LPCAC_CTRL_LPCAC_XOM_SHIFT        (7U)
/*! LPCAC_XOM - LPCAC XOM(eXecute-Only-Memory) attribute control
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define SYSCON_LPCAC_CTRL_LPCAC_XOM(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_LPCAC_XOM_SHIFT)) & SYSCON_LPCAC_CTRL_LPCAC_XOM_MASK)
/*! @} */

/*! @name FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV - LP_FLEXCOMM Clock Divider */
/*! @{ */

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_MASK (0xFFU)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_SHIFT (0U)
/*! DIV - Clock divider value */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_MASK)

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_MASK (0x20000000U)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_SHIFT (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_MASK)

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_MASK (0x40000000U)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_SHIFT (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_MASK)

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_UNSTAB_MASK (0x80000000U)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_UNSTAB_SHIFT (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_UNSTAB(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_UNSTAB_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_UNSTAB_MASK)
/*! @} */

/* The count of SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_COUNT (10U)

/*! @name UTICKCLKSEL - UTICK Function Clock Source Select */
/*! @{ */

#define SYSCON_UTICKCLKSEL_SEL_MASK              (0x3U)
#define SYSCON_UTICKCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Selects the clock source
 *  0b00..clk_in
 *  0b01..xtal32k[2]
 *  0b10..clk_1m clock
 *  0b11..No clock
 */
#define SYSCON_UTICKCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_UTICKCLKSEL_SEL_SHIFT)) & SYSCON_UTICKCLKSEL_SEL_MASK)
/*! @} */

/*! @name SAI0CLKSEL - SAI0 Function Clock Source Select */
/*! @{ */

#define SYSCON_SAI0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_SAI0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the clock source
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..PLL1_CLK0 clock
 *  0b101..No clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_SAI0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI0CLKSEL_SEL_SHIFT)) & SYSCON_SAI0CLKSEL_SEL_MASK)
/*! @} */

/*! @name SAI1CLKSEL - SAI1 Function Clock Source Select */
/*! @{ */

#define SYSCON_SAI1CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_SAI1CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Selects the clock source
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..PLL1_CLK0 clock
 *  0b101..No clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_SAI1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI1CLKSEL_SEL_SHIFT)) & SYSCON_SAI1CLKSEL_SEL_MASK)
/*! @} */

/*! @name SAI0CLKDIV - SAI0 Function Clock Division */
/*! @{ */

#define SYSCON_SAI0CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_SAI0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_SAI0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI0CLKDIV_DIV_SHIFT)) & SYSCON_SAI0CLKDIV_DIV_MASK)

#define SYSCON_SAI0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_SAI0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_SAI0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI0CLKDIV_RESET_SHIFT)) & SYSCON_SAI0CLKDIV_RESET_MASK)

#define SYSCON_SAI0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_SAI0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_SAI0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI0CLKDIV_HALT_SHIFT)) & SYSCON_SAI0CLKDIV_HALT_MASK)

#define SYSCON_SAI0CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_SAI0CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_SAI0CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI0CLKDIV_UNSTAB_SHIFT)) & SYSCON_SAI0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name SAI1CLKDIV - SAI1 Function Clock Division */
/*! @{ */

#define SYSCON_SAI1CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_SAI1CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_SAI1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI1CLKDIV_DIV_SHIFT)) & SYSCON_SAI1CLKDIV_DIV_MASK)

#define SYSCON_SAI1CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_SAI1CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_SAI1CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI1CLKDIV_RESET_SHIFT)) & SYSCON_SAI1CLKDIV_RESET_MASK)

#define SYSCON_SAI1CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_SAI1CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_SAI1CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI1CLKDIV_HALT_SHIFT)) & SYSCON_SAI1CLKDIV_HALT_MASK)

#define SYSCON_SAI1CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_SAI1CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_SAI1CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SAI1CLKDIV_UNSTAB_SHIFT)) & SYSCON_SAI1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name EMVSIM0CLKSEL - EMVSIM0 Clock Source Select */
/*! @{ */

#define SYSCON_EMVSIM0CLKSEL_SEL_MASK            (0x7U)
#define SYSCON_EMVSIM0CLKSEL_SEL_SHIFT           (0U)
/*! SEL - Selects the EMVSIM0 function clock source
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..FRO_12M clock
 *  0b101..PLL1_clk0 clock0
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_EMVSIM0CLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM0CLKSEL_SEL_SHIFT)) & SYSCON_EMVSIM0CLKSEL_SEL_MASK)
/*! @} */

/*! @name EMVSIM1CLKSEL - EMVSIM1 Clock Source Select */
/*! @{ */

#define SYSCON_EMVSIM1CLKSEL_SEL_MASK            (0x7U)
#define SYSCON_EMVSIM1CLKSEL_SEL_SHIFT           (0U)
/*! SEL - Selects the EMVSIM1 function clock source
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..FRO_12M clock
 *  0b101..PLL1_clk0 clock0
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_EMVSIM1CLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM1CLKSEL_SEL_SHIFT)) & SYSCON_EMVSIM1CLKSEL_SEL_MASK)
/*! @} */

/*! @name EMVSIM0CLKDIV - EMVSIM0 Function Clock Division */
/*! @{ */

#define SYSCON_EMVSIM0CLKDIV_DIV_MASK            (0x7U)
#define SYSCON_EMVSIM0CLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value */
#define SYSCON_EMVSIM0CLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM0CLKDIV_DIV_SHIFT)) & SYSCON_EMVSIM0CLKDIV_DIV_MASK)

#define SYSCON_EMVSIM0CLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_EMVSIM0CLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_EMVSIM0CLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM0CLKDIV_RESET_SHIFT)) & SYSCON_EMVSIM0CLKDIV_RESET_MASK)

#define SYSCON_EMVSIM0CLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_EMVSIM0CLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_EMVSIM0CLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM0CLKDIV_HALT_SHIFT)) & SYSCON_EMVSIM0CLKDIV_HALT_MASK)

#define SYSCON_EMVSIM0CLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_EMVSIM0CLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_EMVSIM0CLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM0CLKDIV_UNSTAB_SHIFT)) & SYSCON_EMVSIM0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name EMVSIM1CLKDIV - EMVSIM1 Function Clock Division */
/*! @{ */

#define SYSCON_EMVSIM1CLKDIV_DIV_MASK            (0x7U)
#define SYSCON_EMVSIM1CLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value */
#define SYSCON_EMVSIM1CLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM1CLKDIV_DIV_SHIFT)) & SYSCON_EMVSIM1CLKDIV_DIV_MASK)

#define SYSCON_EMVSIM1CLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_EMVSIM1CLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_EMVSIM1CLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM1CLKDIV_RESET_SHIFT)) & SYSCON_EMVSIM1CLKDIV_RESET_MASK)

#define SYSCON_EMVSIM1CLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_EMVSIM1CLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_EMVSIM1CLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM1CLKDIV_HALT_SHIFT)) & SYSCON_EMVSIM1CLKDIV_HALT_MASK)

#define SYSCON_EMVSIM1CLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_EMVSIM1CLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_EMVSIM1CLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_EMVSIM1CLKDIV_UNSTAB_SHIFT)) & SYSCON_EMVSIM1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name KEY_RETAIN_CTRL - Key Retain Control */
/*! @{ */

#define SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_VALID_MASK (0x1U)
#define SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_VALID_SHIFT (0U)
/*! KEY_RETAIN_VALID - Indicates if the PUF key has been retained in the VBAT domain and has not
 *    been reset or otherwise invalidated by software.
 *  0b0..PUF key is not retained in VBAT domain.
 *  0b1..PUF key is retained in VBAT domain.
 */
#define SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_VALID(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_VALID_SHIFT)) & SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_VALID_MASK)

#define SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_DONE_MASK (0x2U)
#define SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_DONE_SHIFT (1U)
/*! KEY_RETAIN_DONE - Indicates the successful completion of the key_save or key_load routine. Once
 *    set, to clear the key_retain_done flag, both key_save and key_load should be cleared by
 *    software.
 *  0b0..Key save / load sequence has not completed.
 *  0b1..Key save / load sequence has completed.
 */
#define SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_DONE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_DONE_SHIFT)) & SYSCON_KEY_RETAIN_CTRL_KEY_RETAIN_DONE_MASK)

#define SYSCON_KEY_RETAIN_CTRL_KEY_SAVE_MASK     (0x10000U)
#define SYSCON_KEY_RETAIN_CTRL_KEY_SAVE_SHIFT    (16U)
/*! KEY_SAVE
 *  0b0..Key save sequence is disabled.
 *  0b1..Key save sequence is enabled.
 */
#define SYSCON_KEY_RETAIN_CTRL_KEY_SAVE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_KEY_RETAIN_CTRL_KEY_SAVE_SHIFT)) & SYSCON_KEY_RETAIN_CTRL_KEY_SAVE_MASK)

#define SYSCON_KEY_RETAIN_CTRL_KEY_LOAD_MASK     (0x20000U)
#define SYSCON_KEY_RETAIN_CTRL_KEY_LOAD_SHIFT    (17U)
/*! KEY_LOAD
 *  0b0..Key load sequence is disabled.
 *  0b1..Key load sequence is enabled.
 */
#define SYSCON_KEY_RETAIN_CTRL_KEY_LOAD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_KEY_RETAIN_CTRL_KEY_LOAD_SHIFT)) & SYSCON_KEY_RETAIN_CTRL_KEY_LOAD_MASK)
/*! @} */

/*! @name REF_CLK_CTRL - FRO 48MHz Reference Clock Control */
/*! @{ */

#define SYSCON_REF_CLK_CTRL_GDET_REFCLK_EN_MASK  (0x1U)
#define SYSCON_REF_CLK_CTRL_GDET_REFCLK_EN_SHIFT (0U)
/*! GDET_REFCLK_EN - GDET reference clock enable bit
 *  0b0..Disabled.
 *  0b1..Enabled
 */
#define SYSCON_REF_CLK_CTRL_GDET_REFCLK_EN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_REF_CLK_CTRL_GDET_REFCLK_EN_SHIFT)) & SYSCON_REF_CLK_CTRL_GDET_REFCLK_EN_MASK)

#define SYSCON_REF_CLK_CTRL_TRNG_REFCLK_EN_MASK  (0x2U)
#define SYSCON_REF_CLK_CTRL_TRNG_REFCLK_EN_SHIFT (1U)
/*! TRNG_REFCLK_EN - ELS TRNG reference clock enable bit
 *  0b0..Disabled.
 *  0b1..Enabled
 */
#define SYSCON_REF_CLK_CTRL_TRNG_REFCLK_EN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_REF_CLK_CTRL_TRNG_REFCLK_EN_SHIFT)) & SYSCON_REF_CLK_CTRL_TRNG_REFCLK_EN_MASK)
/*! @} */

/*! @name REF_CLK_CTRL_SET - FRO 48MHz Reference Clock Control Set */
/*! @{ */

#define SYSCON_REF_CLK_CTRL_SET_GDET_REFCLK_EN_SET_MASK (0x1U)
#define SYSCON_REF_CLK_CTRL_SET_GDET_REFCLK_EN_SET_SHIFT (0U)
/*! GDET_REFCLK_EN_SET - GDET reference clock enable set bit
 *  0b0..No effect.
 *  0b1..Set to 1
 */
#define SYSCON_REF_CLK_CTRL_SET_GDET_REFCLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_REF_CLK_CTRL_SET_GDET_REFCLK_EN_SET_SHIFT)) & SYSCON_REF_CLK_CTRL_SET_GDET_REFCLK_EN_SET_MASK)

#define SYSCON_REF_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_MASK (0x2U)
#define SYSCON_REF_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_SHIFT (1U)
/*! TRNG_REFCLK_EN_SET - ELS TRNG reference clock enable set bit
 *  0b0..No effect.
 *  0b1..Set to 1
 */
#define SYSCON_REF_CLK_CTRL_SET_TRNG_REFCLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_REF_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_SHIFT)) & SYSCON_REF_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_MASK)
/*! @} */

/*! @name REF_CLK_CTRL_CLR - FRO 48MHz Reference Clock Control Clear */
/*! @{ */

#define SYSCON_REF_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_MASK (0x1U)
#define SYSCON_REF_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_SHIFT (0U)
/*! GDET_REFCLK_EN_CLR - GDET reference clock enable clear bit
 *  0b0..No effect.
 *  0b1..Set to 0
 */
#define SYSCON_REF_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_REF_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_SHIFT)) & SYSCON_REF_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_MASK)

#define SYSCON_REF_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_MASK (0x2U)
#define SYSCON_REF_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_SHIFT (1U)
/*! TRNG_REFCLK_EN_CLR - ELS TRNG reference clock enable clear bit
 *  0b0..No effect.
 *  0b1..Set to 0
 */
#define SYSCON_REF_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_REF_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_SHIFT)) & SYSCON_REF_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_MASK)
/*! @} */

/*! @name GDET_CTRL - GDET Control Register */
/*! @{ */

#define SYSCON_GDET_CTRL_GDET_EVTCNT_CLR_MASK    (0x1U)
#define SYSCON_GDET_CTRL_GDET_EVTCNT_CLR_SHIFT   (0U)
/*! GDET_EVTCNT_CLR - Controls the GDET clean event counter
 *  0b0..Event counter not cleared
 *  0b1..Clears event counter
 */
#define SYSCON_GDET_CTRL_GDET_EVTCNT_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_GDET_CTRL_GDET_EVTCNT_CLR_SHIFT)) & SYSCON_GDET_CTRL_GDET_EVTCNT_CLR_MASK)

#define SYSCON_GDET_CTRL_GDET_ERR_CLR_MASK       (0x2U)
#define SYSCON_GDET_CTRL_GDET_ERR_CLR_SHIFT      (1U)
/*! GDET_ERR_CLR - Clears GDET error status
 *  0b0..Error status not cleared
 *  0b1..Clears error status
 */
#define SYSCON_GDET_CTRL_GDET_ERR_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_GDET_CTRL_GDET_ERR_CLR_SHIFT)) & SYSCON_GDET_CTRL_GDET_ERR_CLR_MASK)

#define SYSCON_GDET_CTRL_GDET_ISO_SW_MASK        (0xCU)
#define SYSCON_GDET_CTRL_GDET_ISO_SW_SHIFT       (2U)
/*! GDET_ISO_SW - GDET isolation control
 *  0b00..Isolation is disabled
 *  0b01..Isolation is disabled
 *  0b10..Isolation is enabled. When both GDET0_CTRL/GDET1_CTRL GDET_ISO_SW are "10", isolation_on is asserted.
 *  0b11..Isolation is disabled
 */
#define SYSCON_GDET_CTRL_GDET_ISO_SW(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_GDET_CTRL_GDET_ISO_SW_SHIFT)) & SYSCON_GDET_CTRL_GDET_ISO_SW_MASK)

#define SYSCON_GDET_CTRL_EVENT_CNT_MASK          (0xFF00U)
#define SYSCON_GDET_CTRL_EVENT_CNT_SHIFT         (8U)
/*! EVENT_CNT - Event count value */
#define SYSCON_GDET_CTRL_EVENT_CNT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_GDET_CTRL_EVENT_CNT_SHIFT)) & SYSCON_GDET_CTRL_EVENT_CNT_MASK)

#define SYSCON_GDET_CTRL_POS_SYNC_MASK           (0x10000U)
#define SYSCON_GDET_CTRL_POS_SYNC_SHIFT          (16U)
/*! POS_SYNC - Positive glitch detected
 *  0b0..Positive glitch not detected
 *  0b1..Positive glitch detected
 */
#define SYSCON_GDET_CTRL_POS_SYNC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_GDET_CTRL_POS_SYNC_SHIFT)) & SYSCON_GDET_CTRL_POS_SYNC_MASK)

#define SYSCON_GDET_CTRL_NEG_SYNC_MASK           (0x20000U)
#define SYSCON_GDET_CTRL_NEG_SYNC_SHIFT          (17U)
/*! NEG_SYNC - Negative glitch detected
 *  0b0..Negative glitch not detected
 *  0b1..Negative glitch detected
 */
#define SYSCON_GDET_CTRL_NEG_SYNC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_GDET_CTRL_NEG_SYNC_SHIFT)) & SYSCON_GDET_CTRL_NEG_SYNC_MASK)

#define SYSCON_GDET_CTRL_EVENT_CLR_FLAG_MASK     (0x40000U)
#define SYSCON_GDET_CTRL_EVENT_CLR_FLAG_SHIFT    (18U)
/*! EVENT_CLR_FLAG - Event counter cleared
 *  0b0..Event counter not cleared
 *  0b1..Event counter cleared
 */
#define SYSCON_GDET_CTRL_EVENT_CLR_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_GDET_CTRL_EVENT_CLR_FLAG_SHIFT)) & SYSCON_GDET_CTRL_EVENT_CLR_FLAG_MASK)
/*! @} */

/* The count of SYSCON_GDET_CTRL */
#define SYSCON_GDET_CTRL_COUNT                   (2U)

/*! @name ELS_ASSET_PROT - ELS Asset Protection Register */
/*! @{ */

#define SYSCON_ELS_ASSET_PROT_ASSET_PROTECTION_MASK (0x3U)
#define SYSCON_ELS_ASSET_PROT_ASSET_PROTECTION_SHIFT (0U)
/*! ASSET_PROTECTION - ELS asset protection. This field controls the asset protection port to the
 *    ELS module. Refer to the ELS chapter in the SRM for more details.
 *  0b00..ELS asset is protected
 *  0b01..ELS asset is not protected
 *  0b10..ELS asset is protected
 *  0b11..ELS asset is protected
 */
#define SYSCON_ELS_ASSET_PROT_ASSET_PROTECTION(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_ASSET_PROT_ASSET_PROTECTION_SHIFT)) & SYSCON_ELS_ASSET_PROT_ASSET_PROTECTION_MASK)
/*! @} */

/*! @name ELS_LOCK_CTRL - ELS Lock Control */
/*! @{ */

#define SYSCON_ELS_LOCK_CTRL_LOCK_CTRL_MASK      (0x3U)
#define SYSCON_ELS_LOCK_CTRL_LOCK_CTRL_SHIFT     (0U)
/*! LOCK_CTRL - ELS Lock Control */
#define SYSCON_ELS_LOCK_CTRL_LOCK_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_LOCK_CTRL_LOCK_CTRL_SHIFT)) & SYSCON_ELS_LOCK_CTRL_LOCK_CTRL_MASK)
/*! @} */

/*! @name ELS_LOCK_CTRL_DP - ELS Lock Control DP */
/*! @{ */

#define SYSCON_ELS_LOCK_CTRL_DP_LOCK_CTRL_DP_MASK (0x3U)
#define SYSCON_ELS_LOCK_CTRL_DP_LOCK_CTRL_DP_SHIFT (0U)
/*! LOCK_CTRL_DP - Refer to ELS_LOCK_CTRL[1:0] */
#define SYSCON_ELS_LOCK_CTRL_DP_LOCK_CTRL_DP(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_LOCK_CTRL_DP_LOCK_CTRL_DP_SHIFT)) & SYSCON_ELS_LOCK_CTRL_DP_LOCK_CTRL_DP_MASK)
/*! @} */

/*! @name ELS_OTP_LC_STATE - Life Cycle State Register */
/*! @{ */

#define SYSCON_ELS_OTP_LC_STATE_OTP_LC_STATE_MASK (0xFFU)
#define SYSCON_ELS_OTP_LC_STATE_OTP_LC_STATE_SHIFT (0U)
/*! OTP_LC_STATE - OTP life cycle state */
#define SYSCON_ELS_OTP_LC_STATE_OTP_LC_STATE(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_OTP_LC_STATE_OTP_LC_STATE_SHIFT)) & SYSCON_ELS_OTP_LC_STATE_OTP_LC_STATE_MASK)
/*! @} */

/*! @name ELS_OTP_LC_STATE_DP - Life Cycle State Register (Duplicate) */
/*! @{ */

#define SYSCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_MASK (0xFFU)
#define SYSCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_SHIFT (0U)
/*! OTP_LC_STATE_DP - OTP life cycle state */
#define SYSCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_SHIFT)) & SYSCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_MASK)
/*! @} */

/*! @name ELS_TEMPORAL_STATE - ELS Temporal State */
/*! @{ */

#define SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_MASK (0xFU)
#define SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_SHIFT (0U)
/*! TEMPORAL_STATE - Temporal state */
#define SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_SHIFT)) & SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_MASK)
/*! @} */

/*! @name ELS_KDF_MASK - Key Derivation Function Mask */
/*! @{ */

#define SYSCON_ELS_KDF_MASK_KDF_MASK_MASK        (0xFFFFFFFFU)
#define SYSCON_ELS_KDF_MASK_KDF_MASK_SHIFT       (0U)
/*! KDF_MASK - Key derivation function mask */
#define SYSCON_ELS_KDF_MASK_KDF_MASK(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_KDF_MASK_KDF_MASK_SHIFT)) & SYSCON_ELS_KDF_MASK_KDF_MASK_MASK)
/*! @} */

/*! @name ELS_AS_CFG0 - ELS AS Configuration */
/*! @{ */

#define SYSCON_ELS_AS_CFG0_CFG_LC_STATE_MASK     (0xFFU)
#define SYSCON_ELS_AS_CFG0_CFG_LC_STATE_SHIFT    (0U)
/*! CFG_LC_STATE - LC state configuration bit */
#define SYSCON_ELS_AS_CFG0_CFG_LC_STATE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LC_STATE_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LC_STATE_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_RESET_ENABLED_MASK (0x200U)
#define SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_RESET_ENABLED_SHIFT (9U)
/*! CFG_LVD_CORE_RESET_ENABLED - When SPC CORE LVD analog detector are turned on, and CORE LVD reset are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_IRQ_ENABLED_MASK (0x800U)
#define SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_IRQ_ENABLED_SHIFT (11U)
/*! CFG_LVD_CORE_IRQ_ENABLED - When SPC CORE LVD analog detector are turned on, and CORE LVD IRQ are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LVD_CORE_IRQ_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_WDT0_ENABLED_MASK (0x1000U)
#define SYSCON_ELS_AS_CFG0_CFG_WDT0_ENABLED_SHIFT (12U)
/*! CFG_WDT0_ENABLED - When WatchDog Timer 0 is activated, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG0_CFG_WDT0_ENABLED(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_WDT0_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_WDT0_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_CWDT0_ENABLED_MASK (0x2000U)
#define SYSCON_ELS_AS_CFG0_CFG_CWDT0_ENABLED_SHIFT (13U)
/*! CFG_CWDT0_ENABLED - When Code WatchDog Timer 0 is activated, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG0_CFG_CWDT0_ENABLED(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_CWDT0_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_CWDT0_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_MASK (0x4000U)
#define SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_SHIFT (14U)
/*! CFG_ELS_GDET_ENABLED - When either GDET is enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_RESET_ENABLED_MASK (0x8000U)
#define SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_RESET_ENABLED_SHIFT (15U)
/*! CFG_ANA_GDET_RESET_ENABLED - When SPC analog glitch detect reset is enabled, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_IRQ_ENABLED_MASK (0x10000U)
#define SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_IRQ_ENABLED_SHIFT (16U)
/*! CFG_ANA_GDET_IRQ_ENABLED - When SPC analog glitch detect IRQ is enabled, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_ANA_GDET_IRQ_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_MASK (0x20000U)
#define SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_SHIFT (17U)
/*! CFG_TAMPER_DET_ENABLED - When tamper detector is enabled in TDET, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_RESET_ENABLED_MASK (0x40000U)
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_RESET_ENABLED_SHIFT (18U)
/*! CFG_LVD_VSYS_RESET_ENABLED - When SPC VSYS LVD analog detector are turned on and VSYS LVD reset are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_RESET_ENABLED_MASK (0x80000U)
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_RESET_ENABLED_SHIFT (19U)
/*! CFG_LVD_VDDIO_RESET_ENABLED - When SPC VDDIO LVD analog detector are turned on and VDDIO LVD reset are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_IRQ_ENABLED_MASK (0x100000U)
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_IRQ_ENABLED_SHIFT (20U)
/*! CFG_LVD_VSYS_IRQ_ENABLED - When SPC VSYS LVD analog detector are turned on and VSYS LVD irq are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LVD_VSYS_IRQ_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_IRQ_ENABLED_MASK (0x200000U)
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_IRQ_ENABLED_SHIFT (21U)
/*! CFG_LVD_VDDIO_IRQ_ENABLED - When SPC VDDIO LVD analog detector are turned on and VDDIO LVD irq are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LVD_VDDIO_IRQ_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_WDT1_ENABLED_MASK (0x400000U)
#define SYSCON_ELS_AS_CFG0_CFG_WDT1_ENABLED_SHIFT (22U)
/*! CFG_WDT1_ENABLED - When WatchDog Timer 1 is activated, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_WDT1_ENABLED(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_WDT1_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_WDT1_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_CWDT1_ENABLED_MASK (0x800000U)
#define SYSCON_ELS_AS_CFG0_CFG_CWDT1_ENABLED_SHIFT (23U)
/*! CFG_CWDT1_ENABLED - When Code WatchDog Timer 1 is activated, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_CWDT1_ENABLED(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_CWDT1_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_CWDT1_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_TEMPTAMPER_DET_ENABLED_MASK (0x1000000U)
#define SYSCON_ELS_AS_CFG0_CFG_TEMPTAMPER_DET_ENABLED_SHIFT (24U)
/*! CFG_TEMPTAMPER_DET_ENABLED - When temperature tamper detector is enabled in VBAT, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_TEMPTAMPER_DET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_TEMPTAMPER_DET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_TEMPTAMPER_DET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_VOLTAMPER_DET_ENABLED_MASK (0x2000000U)
#define SYSCON_ELS_AS_CFG0_CFG_VOLTAMPER_DET_ENABLED_SHIFT (25U)
/*! CFG_VOLTAMPER_DET_ENABLED - When voltage tamper detector is enabled in VBAT, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_VOLTAMPER_DET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_VOLTAMPER_DET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_VOLTAMPER_DET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_LHTTAMPER_DET_ENABLED_MASK (0x4000000U)
#define SYSCON_ELS_AS_CFG0_CFG_LHTTAMPER_DET_ENABLED_SHIFT (26U)
/*! CFG_LHTTAMPER_DET_ENABLED - When light tamper detector is enabled in VBAT, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_LHTTAMPER_DET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LHTTAMPER_DET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LHTTAMPER_DET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_MASK (0x8000000U)
#define SYSCON_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_SHIFT (27U)
/*! CFG_CLKTAMPER_DET_ENABLED - When clk tamper detector is enabled in VBAT, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_MASK (0x10000000U)
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_SHIFT (28U)
/*! CFG_QK_DISABLE_ENROLL - When QK PUF "qk_disable_enroll" input is driven 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_MASK (0x20000000U)
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_SHIFT (29U)
/*! CFG_QK_DISABLE_WRAP - When QK PUF "qk_disable_wrap" input is driven 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_MASK)
/*! @} */

/*! @name ELS_AS_CFG1 - ELS AS Configuration1 */
/*! @{ */

#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_MASK (0x2U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_SHIFT (1U)
/*! CFG_SEC_DIS_STRICT_MODE - When CFG_SEC_ENA_SEC_CHK indicates state 0 or when DISABLE_STRICT_MODE
 *    bits in MISC_CTRL_REG and MISC_CTRL_DP_REG on the AHB secure controller are equal to 01, this
 *    bit indicates state 1
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_MASK (0x4U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_SHIFT (2U)
/*! CFG_SEC_DIS_VIOL_ABORT - When the DISABLE_VIOLATION_ABORT bits in MISC_CTRL_REG and
 *    MISC_CTRL_DP_REG on the AHB secure controller are not equal to 10, this bit indicates state 1
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_MASK (0x8U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_SHIFT (3U)
/*! CFG_SEC_ENA_NS_PRIV_CHK - When the ENABLE_NS_PRIV_CHECK bits in MISC_CTRL_REG and
 *    MISC_CTRL_DP_REG on the AHB secure controller are not equal to 10, this bit indicates state 1
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_MASK (0x10U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_SHIFT (4U)
/*! CFG_SEC_ENA_S_PRIV_CHK - When the ENABLE_S_PRIV_CHECK bits in MISC_CTRL_REG and MISC_CTRL_DP_REG
 *    on the AHB secure controller are not equal to 10, this bit indicates state 1
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_MASK (0x20U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_SHIFT (5U)
/*! CFG_SEC_ENA_SEC_CHK - When the ENABLE_SECURE_CHECKING bits in MISC_CTRL_REG and MISC_CTRL_DP_REG
 *    on the AHB secure controller are not equal to 10, this bit indicates state 1
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_MASK (0x40U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_SHIFT (6U)
/*! CFG_SEC_IDAU_ALLNS - When the IDAU_ALL_NS bits in MISC_CTRL_REG and MISC_CTRL_DP_REG on the AHB
 *    secure controller are equal to 01, this bit indicates state 1
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_MASK (0x100U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_SHIFT (8U)
/*! CFG_SEC_LOCK_NS_MPU - When the LOCK_NS_MPU bits in CPU0_LOCK_REG on the AHB secure controller are not equal to 10, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_MASK (0x200U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_SHIFT (9U)
/*! CFG_SEC_LOCK_NS_VTOR - When the LOCK_NS_VTOR bits in CPU0_LOCK_REG on the AHB secure controller are not equal to 10, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_MASK (0x400U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_SHIFT (10U)
/*! CFG_SEC_LOCK_S_MPU - When the LOCK_S_MPU bits in CPU0_LOCK_REG on the AHB secure controller are not equal to 10, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_MASK (0x800U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_SHIFT (11U)
/*! CFG_SEC_LOCK_S_VTAIRCR - When the LOCK_S_VTAIRCR bits in CPU0_LOCK_REG on the AHB secure
 *    controller are not equal to 10, this bit indicates state 1
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_MASK (0x1000U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_SHIFT (12U)
/*! CFG_SEC_LOCK_SAU - When the LOCK_SAU bits in CPU0_LOCK_REG on the AHB secure controller are not equal to 10, this bit indicates state 1 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_MASK)

#define SYSCON_ELS_AS_CFG1_METAL_VERSION_MASK    (0x1FE000U)
#define SYSCON_ELS_AS_CFG1_METAL_VERSION_SHIFT   (13U)
/*! METAL_VERSION - metal version */
#define SYSCON_ELS_AS_CFG1_METAL_VERSION(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_METAL_VERSION_SHIFT)) & SYSCON_ELS_AS_CFG1_METAL_VERSION_MASK)

#define SYSCON_ELS_AS_CFG1_ROM_PATCH_VERSION_MASK (0x1E00000U)
#define SYSCON_ELS_AS_CFG1_ROM_PATCH_VERSION_SHIFT (21U)
/*! ROM_PATCH_VERSION - ROM patch version */
#define SYSCON_ELS_AS_CFG1_ROM_PATCH_VERSION(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_ROM_PATCH_VERSION_SHIFT)) & SYSCON_ELS_AS_CFG1_ROM_PATCH_VERSION_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_RESET_ENABLED_MASK (0x4000000U)
#define SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_RESET_ENABLED_SHIFT (26U)
/*! CFG_HVD_CORE_RESET_ENABLED - When SPC CORE HVD analog detector are turned on, and CORE HVD reset are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_IRQ_ENABLED_MASK (0x8000000U)
#define SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_IRQ_ENABLED_SHIFT (27U)
/*! CFG_HVD_CORE_IRQ_ENABLED - When SPC CORE HVD analog detector are turned on, and CORE HVD IRQ are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_HVD_CORE_IRQ_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_RESET_ENABLED_MASK (0x10000000U)
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_RESET_ENABLED_SHIFT (28U)
/*! CFG_HVD_VSYS_RESET_ENABLED - When SPC VSYS HVD analog detector are turned on and VSYS HVD reset are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_RESET_ENABLED_MASK (0x20000000U)
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_RESET_ENABLED_SHIFT (29U)
/*! CFG_HVD_VDDIO_RESET_ENABLED - When SPC VDDIO HVD analog detector are turned on and VDDIO HVD reset are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_IRQ_ENABLED_MASK (0x40000000U)
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_IRQ_ENABLED_SHIFT (30U)
/*! CFG_HVD_VSYS_IRQ_ENABLED - When SPC VSYS HVD analog detector are turned on and VSYS HVD irq are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_HVD_VSYS_IRQ_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_IRQ_ENABLED_MASK (0x80000000U)
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_IRQ_ENABLED_SHIFT (31U)
/*! CFG_HVD_VDDIO_IRQ_ENABLED - When SPC VDDIO HVD analog detector are turned on and VDDIO HVD irq are enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_HVD_VDDIO_IRQ_ENABLED_MASK)
/*! @} */

/*! @name ELS_AS_CFG2 - ELS AS Configuration2 */
/*! @{ */

#define SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_MASK   (0xFFFFFFFFU)
#define SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_SHIFT  (0U)
/*! CFG_ELS_CMD_EN - ELS configuration command enable bit */
#define SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_SHIFT)) & SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_MASK)
/*! @} */

/*! @name ELS_AS_CFG3 - ELS AS Configuration3 */
/*! @{ */

#define SYSCON_ELS_AS_CFG3_DEVICE_TYPE_MASK      (0xFFFFFFFFU)
#define SYSCON_ELS_AS_CFG3_DEVICE_TYPE_SHIFT     (0U)
/*! DEVICE_TYPE - Device type identification data */
#define SYSCON_ELS_AS_CFG3_DEVICE_TYPE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG3_DEVICE_TYPE_SHIFT)) & SYSCON_ELS_AS_CFG3_DEVICE_TYPE_MASK)
/*! @} */

/*! @name ELS_AS_ST0 - ELS AS State Register */
/*! @{ */

#define SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_MASK (0xFU)
#define SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_SHIFT (0U)
/*! ST_TEMPORAL_STATE - TEMPORAL_STATE[3:0] in the ELS_TEMPORAL_STATE register reflects this register */
#define SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_SHIFT)) & SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_MASK     (0x10U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_SHIFT    (4U)
/*! ST_CPU0_DBGEN - When CPU0 (CM33) "deben" input is state 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_MASK     (0x20U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_SHIFT    (5U)
/*! ST_CPU0_NIDEN - When CPU0 (CM33) "niden" input is state 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_MASK    (0x40U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_SHIFT   (6U)
/*! ST_CPU0_SPIDEN - When CPU0 (CM33) "spiden" input is state 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_MASK   (0x80U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_SHIFT  (7U)
/*! ST_CPU0_SPNIDEN - When CPU0 (CM33) "spniden" input is state 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU1_DBGEN_MASK     (0x100U)
#define SYSCON_ELS_AS_ST0_ST_CPU1_DBGEN_SHIFT    (8U)
/*! ST_CPU1_DBGEN - When CPU1 (CM33) "deben" input is state 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_CPU1_DBGEN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU1_DBGEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU1_DBGEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU1_NIDEN_MASK     (0x200U)
#define SYSCON_ELS_AS_ST0_ST_CPU1_NIDEN_SHIFT    (9U)
/*! ST_CPU1_NIDEN - When CPU1 (CM33) "niden" input is state 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_CPU1_NIDEN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU1_NIDEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU1_NIDEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_MASK (0x400U)
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_SHIFT (10U)
/*! ST_DAP_ENABLE_CPU0 - When DAP to AP0 for CPU0 (CM33) debug access is allowed, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_SHIFT)) & SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_MASK)

#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU1_MASK (0x800U)
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU1_SHIFT (11U)
/*! ST_DAP_ENABLE_CPU1 - When DAP to AP1 for CPU1 (CM33) debug access is allowed, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU1_SHIFT)) & SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU1_MASK)

#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_DSP_MASK (0x1000U)
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_DSP_SHIFT (12U)
/*! ST_DAP_ENABLE_DSP - When DAP to AP3 for DSP (CoolFlux) debug access is allowed, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_DSP(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_DSP_SHIFT)) & SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_DSP_MASK)

#define SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_MASK (0x4000U)
#define SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_SHIFT (14U)
/*! ST_ALLOW_TEST_ACCESS - When JTAG TAP access is allowed, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_SHIFT)) & SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_MASK)

#define SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_MASK   (0x8000U)
#define SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_SHIFT  (15U)
/*! ST_XO32K_FAILED - When XO32K oscillation fail flag is state 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_XO32K_FAILED(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_SHIFT)) & SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_MASK)

#define SYSCON_ELS_AS_ST0_ST_XO40M_FAILED_MASK   (0x10000U)
#define SYSCON_ELS_AS_ST0_ST_XO40M_FAILED_SHIFT  (16U)
/*! ST_XO40M_FAILED - When XO40M oscillation fail flag is state 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_XO40M_FAILED(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_XO40M_FAILED_SHIFT)) & SYSCON_ELS_AS_ST0_ST_XO40M_FAILED_MASK)

#define SYSCON_ELS_AS_ST0_ST_IFR_LOAD_FAILED_MASK (0x20000U)
#define SYSCON_ELS_AS_ST0_ST_IFR_LOAD_FAILED_SHIFT (17U)
/*! ST_IFR_LOAD_FAILED - When IFR load fail flag is state 1, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST0_ST_IFR_LOAD_FAILED(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_IFR_LOAD_FAILED_SHIFT)) & SYSCON_ELS_AS_ST0_ST_IFR_LOAD_FAILED_MASK)

#define SYSCON_ELS_AS_ST0_ST_GLITCH_DETECT_FLAG_MASK (0x3C0000U)
#define SYSCON_ELS_AS_ST0_ST_GLITCH_DETECT_FLAG_SHIFT (18U)
/*! ST_GLITCH_DETECT_FLAG - GLITCH_DETECT_FLAG is state of 4-bit Glitch Ripple Counter output. */
#define SYSCON_ELS_AS_ST0_ST_GLITCH_DETECT_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_GLITCH_DETECT_FLAG_SHIFT)) & SYSCON_ELS_AS_ST0_ST_GLITCH_DETECT_FLAG_MASK)
/*! @} */

/*! @name ELS_AS_ST1 - ELS AS State1 */
/*! @{ */

#define SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_MASK   (0xFU)
#define SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_SHIFT  (0U)
/*! ST_QK_PUF_SCORE - These register bits indicate the state of "qk_puf_score[3:0]" outputs from QK PUF block */
#define SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_SHIFT)) & SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_MASK)

#define SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_MASK    (0x10U)
#define SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_SHIFT   (4U)
/*! ST_QK_ZEROIZED - This register bit indicates the state of "qk_zeroized" output from QK PUF block */
#define SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_SHIFT)) & SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_MASK)

#define SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_MASK (0x20U)
#define SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_SHIFT (5U)
/*! ST_MAIN_CLK_IS_EXT - When MAIN_CLK is running from external clock source either XO32M, XO32K or GPIO CLKIN, this bit indicates state 1 */
#define SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_SHIFT)) & SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_MASK)

#define SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_MASK      (0xC0U)
#define SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_SHIFT     (6U)
/*! ST_DCDC_VOUT - VOUT[1:0] setting on DCDC0 register in SPC block will reflect to this register. Default is 1.0V */
#define SYSCON_ELS_AS_ST1_ST_DCDC_VOUT(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_SHIFT)) & SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_MASK)

#define SYSCON_ELS_AS_ST1_ST_DCDC_DS_MASK        (0x300U)
#define SYSCON_ELS_AS_ST1_ST_DCDC_DS_SHIFT       (8U)
/*! ST_DCDC_DS - DCDC drive strength setting. Default is normal drive. */
#define SYSCON_ELS_AS_ST1_ST_DCDC_DS(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_DCDC_DS_SHIFT)) & SYSCON_ELS_AS_ST1_ST_DCDC_DS_MASK)

#define SYSCON_ELS_AS_ST1_ST_BOOT_MODE_MASK      (0xC00U)
#define SYSCON_ELS_AS_ST1_ST_BOOT_MODE_SHIFT     (10U)
/*! ST_BOOT_MODE - ISP pin status during boot. By default ISP pin is pulled up. If want to enter ISP
 *    mode during boot, ISP pin should be pull down when out of reset.
 */
#define SYSCON_ELS_AS_ST1_ST_BOOT_MODE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_BOOT_MODE_SHIFT)) & SYSCON_ELS_AS_ST1_ST_BOOT_MODE_MASK)

#define SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_MASK (0xF000U)
#define SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_SHIFT (12U)
/*! ST_BOOT_RETRY_CNT - BOOT_RETRY_CNT[3:0] in the ELS_BOOT_RETRY_CNT register reflects this register */
#define SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_SHIFT)) & SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_MASK)

#define SYSCON_ELS_AS_ST1_ST_LDO_CORE_VOUT_MASK  (0x30000U)
#define SYSCON_ELS_AS_ST1_ST_LDO_CORE_VOUT_SHIFT (16U)
/*! ST_LDO_CORE_VOUT - VOUT[1:0] setting on LDO Core register in SPC block will reflect to this register. Default is 1.0V */
#define SYSCON_ELS_AS_ST1_ST_LDO_CORE_VOUT(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_LDO_CORE_VOUT_SHIFT)) & SYSCON_ELS_AS_ST1_ST_LDO_CORE_VOUT_MASK)

#define SYSCON_ELS_AS_ST1_ST_LDO_CORE_DS_MASK    (0xC0000U)
#define SYSCON_ELS_AS_ST1_ST_LDO_CORE_DS_SHIFT   (18U)
/*! ST_LDO_CORE_DS - LDO_CORE drive strength setting. Default is normal drive. */
#define SYSCON_ELS_AS_ST1_ST_LDO_CORE_DS(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_LDO_CORE_DS_SHIFT)) & SYSCON_ELS_AS_ST1_ST_LDO_CORE_DS_MASK)
/*! @} */

/*! @name ELS_AS_BOOT_LOG0 - Boot state captured during boot: Main ROM log */
/*! @{ */

#define SYSCON_ELS_AS_BOOT_LOG0_BOOT_IMAGE_MASK  (0xFU)
#define SYSCON_ELS_AS_BOOT_LOG0_BOOT_IMAGE_SHIFT (0U)
/*! BOOT_IMAGE - Boot image source used during this boot.
 *  0b0000..Internal flash image 0
 *  0b0001..Internal flash image 1
 *  0b0010..FlexSPI flash image 0
 *  0b0011..FlexSPI flash image 1
 *  0b0100..Recovery SPI flash image
 *  0b0101..Serial boot image (write-memory and execute ISP command used)
 *  0b0110..Receive SB3 containing SB_JUMP command is used.
 *  0b0111..Customer SBL/recovery image (Bank1 IFR0).
 *  0b1000..NXP MAD recovery image (Bank1 IFR0).
 *  0b1001..NXP ROM extension (NMPA - Bank0 IFR0).
 *  0b1010..Reserved.
 *  0b1011..Reserved.
 *  0b1100..Reserved.
 *  0b1101..Reserved.
 *  0b1110..Reserved.
 *  0b1111..Reserved.
 */
#define SYSCON_ELS_AS_BOOT_LOG0_BOOT_IMAGE(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_BOOT_IMAGE_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_BOOT_IMAGE_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_CMAC_MASK        (0x10U)
#define SYSCON_ELS_AS_BOOT_LOG0_CMAC_SHIFT       (4U)
/*! CMAC - CMAC verify is used instead of ECDSA verify on this boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_CMAC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_CMAC_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_CMAC_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_ECDSA_MASK       (0x40U)
#define SYSCON_ELS_AS_BOOT_LOG0_ECDSA_SHIFT      (6U)
/*! ECDSA - ECDSA P-384 verification is done on this boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_ECDSA(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_ECDSA_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_ECDSA_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_OFF_CHIP_MASK    (0x80U)
#define SYSCON_ELS_AS_BOOT_LOG0_OFF_CHIP_SHIFT   (7U)
/*! OFF_CHIP - Off-chip Prince is enabled during boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_OFF_CHIP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_OFF_CHIP_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_OFF_CHIP_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_ON_CHIP_MASK     (0x100U)
#define SYSCON_ELS_AS_BOOT_LOG0_ON_CHIP_SHIFT    (8U)
/*! ON_CHIP - On-chip Prince is enabled during boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_ON_CHIP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_ON_CHIP_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_ON_CHIP_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_CDI_CSR_MASK     (0x200U)
#define SYSCON_ELS_AS_BOOT_LOG0_CDI_CSR_SHIFT    (9U)
/*! CDI_CSR - CDI based device keys are derived for CSR harvesting on this boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_CDI_CSR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_CDI_CSR_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_CDI_CSR_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_CDI_DICE_MASK    (0x400U)
#define SYSCON_ELS_AS_BOOT_LOG0_CDI_DICE_SHIFT   (10U)
/*! CDI_DICE - CDI per DICE specification is computed on this boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_CDI_DICE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_CDI_DICE_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_CDI_DICE_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_TRUSTZONE_MASK   (0x800U)
#define SYSCON_ELS_AS_BOOT_LOG0_TRUSTZONE_SHIFT  (11U)
/*! TRUSTZONE - TrustZone preset data is loaded during this boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_TRUSTZONE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_TRUSTZONE_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_TRUSTZONE_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_DEBUG_AUTH_MASK  (0x1000U)
#define SYSCON_ELS_AS_BOOT_LOG0_DEBUG_AUTH_SHIFT (12U)
/*! DEBUG_AUTH - Debug authentication done in this session prior to boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_DEBUG_AUTH(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_DEBUG_AUTH_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_DEBUG_AUTH_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_ITRC_MASK        (0x2000U)
#define SYSCON_ELS_AS_BOOT_LOG0_ITRC_SHIFT       (13U)
/*! ITRC - ITRC zeroize event is handled in this session of boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_ITRC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_ITRC_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_ITRC_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_DIG_GDET_MASK    (0x4000U)
#define SYSCON_ELS_AS_BOOT_LOG0_DIG_GDET_SHIFT   (14U)
/*! DIG_GDET - Digital glitch detector is enabled during boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_DIG_GDET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_DIG_GDET_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_DIG_GDET_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_ANA_GDET_MASK    (0x8000U)
#define SYSCON_ELS_AS_BOOT_LOG0_ANA_GDET_SHIFT   (15U)
/*! ANA_GDET - Analog glitch detector is enabled during boot. */
#define SYSCON_ELS_AS_BOOT_LOG0_ANA_GDET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_ANA_GDET_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_ANA_GDET_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_DEEP_PD_MASK     (0x10000U)
#define SYSCON_ELS_AS_BOOT_LOG0_DEEP_PD_SHIFT    (16U)
/*! DEEP_PD - Boot from deep-power down state. */
#define SYSCON_ELS_AS_BOOT_LOG0_DEEP_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_DEEP_PD_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_DEEP_PD_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_LOW_POWER_MASK   (0xF000000U)
#define SYSCON_ELS_AS_BOOT_LOG0_LOW_POWER_SHIFT  (24U)
/*! LOW_POWER - Last low-power mode value. ROM copies SPC_LP_MODE field from SPC->SC[7:4]. */
#define SYSCON_ELS_AS_BOOT_LOG0_LOW_POWER(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_LOW_POWER_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_LOW_POWER_MASK)

#define SYSCON_ELS_AS_BOOT_LOG0_ISP_MASK         (0x80000000U)
#define SYSCON_ELS_AS_BOOT_LOG0_ISP_SHIFT        (31U)
/*! ISP - ISP pin state at boot time. ROM copies CMC->MR0[0]. */
#define SYSCON_ELS_AS_BOOT_LOG0_ISP(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG0_ISP_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG0_ISP_MASK)
/*! @} */

/*! @name ELS_AS_BOOT_LOG1 - Boot state captured during boot: Library log */
/*! @{ */

#define SYSCON_ELS_AS_BOOT_LOG1_RoTK_MASK        (0x3U)
#define SYSCON_ELS_AS_BOOT_LOG1_RoTK_SHIFT       (0U)
/*! RoTK - RoTK index used for this boot. */
#define SYSCON_ELS_AS_BOOT_LOG1_RoTK(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG1_RoTK_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG1_RoTK_MASK)

#define SYSCON_ELS_AS_BOOT_LOG1_FIPS_MASK        (0x3FCU)
#define SYSCON_ELS_AS_BOOT_LOG1_FIPS_SHIFT       (2U)
/*! FIPS - FIPS self-test is executed and PASS during this boot. When a bit is set, means self-test
 *    is executed and it FAILS. When a bit is clear, means corresponding self-test is executed and
 *    PASS or it is not executed.
 */
#define SYSCON_ELS_AS_BOOT_LOG1_FIPS(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG1_FIPS_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG1_FIPS_MASK)

#define SYSCON_ELS_AS_BOOT_LOG1_SB3_MASK         (0xC00U)
#define SYSCON_ELS_AS_BOOT_LOG1_SB3_SHIFT        (10U)
/*! SB3 - SB3 type (valid after nboot_sb3_load_manifest()).
 *  0b00..customer fw load/update file.
 *  0b01..NXP Provisioning FW.
 *  0b10..ELS signed OEM Provisioning FW.
 */
#define SYSCON_ELS_AS_BOOT_LOG1_SB3(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG1_SB3_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG1_SB3_MASK)
/*! @} */

/*! @name ELS_AS_BOOT_LOG2 - Boot state captured during boot: Hardware status signals log */
/*! @{ */

#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS0_MASK    (0x3FU)
#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS0_SHIFT   (0U)
/*! CMC_SRS0 - CMC->SRS[5:0] */
#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS0_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS0_MASK)

#define SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS0_MASK (0xC0U)
#define SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS0_SHIFT (6U)
/*! VBAT_STATUS0 - VBAT->STATUSA[1:0] | ~VBAT->STATUSB[1:0] */
#define SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS0_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS0_MASK)

#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS1_MASK    (0x1FF00U)
#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS1_SHIFT   (8U)
/*! CMC_SRS1 - CMC->SRS[16:8] */
#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS1_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS1_MASK)

#define SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS1_MASK (0xFC0000U)
#define SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS1_SHIFT (18U)
/*! VBAT_STATUS1 - VBAT->STATUSA[11:6] | ~VBAT->STATUSB[11:6] */
#define SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS1_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG2_VBAT_STATUS1_MASK)

#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS2_MASK    (0xFF000000U)
#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS2_SHIFT   (24U)
/*! CMC_SRS2 - CMC->SRS[31:24] */
#define SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS2(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS2_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG2_CMC_SRS2_MASK)
/*! @} */

/*! @name ELS_AS_BOOT_LOG3 - Boot state captured during boot: Security log */
/*! @{ */

#define SYSCON_ELS_AS_BOOT_LOG3_ERR_AUTH_FAIL_COUNT_MASK (0xFFU)
#define SYSCON_ELS_AS_BOOT_LOG3_ERR_AUTH_FAIL_COUNT_SHIFT (0U)
/*! ERR_AUTH_FAIL_COUNT - CFPA->ERR_AUTH_FAIL_COUNT[7:0] */
#define SYSCON_ELS_AS_BOOT_LOG3_ERR_AUTH_FAIL_COUNT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG3_ERR_AUTH_FAIL_COUNT_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG3_ERR_AUTH_FAIL_COUNT_MASK)

#define SYSCON_ELS_AS_BOOT_LOG3_ERR_ITRC_COUNT_MASK (0xFF00U)
#define SYSCON_ELS_AS_BOOT_LOG3_ERR_ITRC_COUNT_SHIFT (8U)
/*! ERR_ITRC_COUNT - CFPA->ERR_ITRC_COUNT[7:0] */
#define SYSCON_ELS_AS_BOOT_LOG3_ERR_ITRC_COUNT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_BOOT_LOG3_ERR_ITRC_COUNT_SHIFT)) & SYSCON_ELS_AS_BOOT_LOG3_ERR_ITRC_COUNT_MASK)
/*! @} */

/*! @name ELS_AS_FLAG0 - ELS AS Flag0 */
/*! @{ */

#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_MASK (0x1U)
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_SHIFT (0U)
/*! FLAG_AP_ENABLE_CPU0 - This flag bit is set as 1 when DAP enables AP0 for CPU0 (CM33) debug
 *    access. The register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_MASK (0x2U)
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_SHIFT (1U)
/*! FLAG_AP_ENABLE_CPU1 - This flag bit is set as 1 when DAP enables AP1 for CPU1 (CM33) debug
 *    access. The register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_DSP_MASK (0x4U)
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_DSP_SHIFT (2U)
/*! FLAG_AP_ENABLE_DSP - This flag bit is set as 1 when DAP enables AP3 for DSP (CoolFlux) debug
 *    access. The register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_DSP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_DSP_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_DSP_MASK)

#define SYSCON_ELS_AS_FLAG0_EFUSE_ATTACK_DETECT_MASK (0x8U)
#define SYSCON_ELS_AS_FLAG0_EFUSE_ATTACK_DETECT_SHIFT (3U)
/*! EFUSE_ATTACK_DETECT - OTPC can output attack_detect signal when it detects attack when load
 *    shadow registers. The output will be cleared by reset. ELS_AS_FLAG is reset by PoR, so the status
 *    can be recorded.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_EFUSE_ATTACK_DETECT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_EFUSE_ATTACK_DETECT_SHIFT)) & SYSCON_ELS_AS_FLAG0_EFUSE_ATTACK_DETECT_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_CORE_OCCURED_MASK (0x20U)
#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_CORE_OCCURED_SHIFT (5U)
/*! FLAG_LVD_CORE_OCCURED - This flag register is set 1 when VDD_CORE LVD event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_CORE_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_LVD_CORE_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_LVD_CORE_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_WDT0_RESET_OCCURED_MASK (0x100U)
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT0_RESET_OCCURED_SHIFT (8U)
/*! FLAG_WDT0_RESET_OCCURED - This flag bit is set as 1 when WatchDog Timer 0 reset is enabled and
 *    reset event is triggered. This register is cleared 0 by AO domain POR.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT0_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_WDT0_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_WDT0_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_RESET_OCCURED_MASK (0x200U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_RESET_OCCURED_SHIFT (9U)
/*! FLAG_CWDT0_RESET_OCCURED - This flag bit is set as 1 when Code WatchDog Timer 0 reset is enabled
 *    and reset event is triggered. This register is cleared 0 by AO domain POR.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_WDT0_IRQ_OCCURED_MASK (0x400U)
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT0_IRQ_OCCURED_SHIFT (10U)
/*! FLAG_WDT0_IRQ_OCCURED - This flag bit is set as 1 when WatchDog Timer 0 IRQ is enabled and IRQ
 *    event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT0_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_WDT0_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_WDT0_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_IRQ_OCCURED_MASK (0x800U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_IRQ_OCCURED_SHIFT (11U)
/*! FLAG_CWDT0_IRQ_OCCURED - This flag bit is set as 1 when Code WatchDog Timer 0 IRQ is enabled and
 *    IRQ event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CWDT0_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_MASK   (0x1000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_SHIFT  (12U)
/*! FLAG_QK_ERROR - This flag bit is set as 1 when QK_ERROR is flagged from QK PUF block. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_MASK (0x2000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_SHIFT (13U)
/*! FLAG_ELS_GLITCH_DETECTED - This flag bit is set as 1 when GDET error is flagged. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_ANA_GLITCH_DETECTED_MASK (0x4000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_ANA_GLITCH_DETECTED_SHIFT (14U)
/*! FLAG_ANA_GLITCH_DETECTED - This flag bit is set as 1 when ANALOG GDET error is flagged in SYSCON
 *    block. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_ANA_GLITCH_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_ANA_GLITCH_DETECTED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_ANA_GLITCH_DETECTED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_MASK (0x8000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_SHIFT (15U)
/*! FLAG_TAMPER_EVENT_DETECTED - This flag bit is set as 1 when tamper event is flagged from TDET.
 *    This register is cleared 0 by AO domain POR or by PMC reset event, if tamper detection event is
 *    cleared by software.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_MASK (0x10000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_SHIFT (16U)
/*! FLAG_FLASH_ECC_INVALID - This flag bit is set as 1 when FLASH controller indicates ECC error. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_MASK (0x20000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_SHIFT (17U)
/*! FLAG_SEC_VIOL_IRQ_OCURRED - This flag bit is set as 1 when security violation is indicated from FLASH sub-system or AHB bus matrix.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_MASK (0x40000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_SHIFT (18U)
/*! FLAG_CPU0_NS_C_ACC_OCCURED - This flag bit is set as 1 when CPU0 (CM33) makes non-secure code
 *    transactions. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_MASK (0x80000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_SHIFT (19U)
/*! FLAG_CPU0_NS_D_ACC_OCCURED - This flag bit is set as 1 when CPU0 (CM33) makes non-secure data
 *    transactions. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_VSYS_OCCURED_MASK (0x100000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_VSYS_OCCURED_SHIFT (20U)
/*! FLAG_LVD_VSYS_OCCURED - This flag register is set 1 when VDD_SYS LVD event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_VSYS_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_LVD_VSYS_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_LVD_VSYS_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_VDDIO_OCCURED_MASK (0x200000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_VDDIO_OCCURED_SHIFT (21U)
/*! FLAG_LVD_VDDIO_OCCURED - This flag register is set 1 when VDD LVD event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_LVD_VDDIO_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_LVD_VDDIO_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_LVD_VDDIO_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_WDT1_RESET_OCCURED_MASK (0x400000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT1_RESET_OCCURED_SHIFT (22U)
/*! FLAG_WDT1_RESET_OCCURED - This flag bit is set as 1 when WatchDog Timer 1 reset is enabled and
 *    reset event is triggered. This register is cleared 0 by AO domain POR.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT1_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_WDT1_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_WDT1_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_RESET_OCCURED_MASK (0x800000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_RESET_OCCURED_SHIFT (23U)
/*! FLAG_CWDT1_RESET_OCCURED - This flag bit is set as 1 when Code WatchDog Timer 1 reset is enabled
 *    and reset event is triggered. This register is cleared 0 by AO domain POR.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_WDT1_IRQ_OCCURED_MASK (0x1000000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT1_IRQ_OCCURED_SHIFT (24U)
/*! FLAG_WDT1_IRQ_OCCURED - This flag bit is set as 1 when WatchDog Timer 1 IRQ is enabled and IRQ
 *    event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT1_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_WDT1_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_WDT1_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_IRQ_OCCURED_MASK (0x2000000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_IRQ_OCCURED_SHIFT (25U)
/*! FLAG_CWDT1_IRQ_OCCURED - This flag bit is set as 1 when Code WatchDog Timer 1 IRQ is enabled and
 *    IRQ event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CWDT1_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_MASK (0x4000000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_SHIFT (26U)
/*! FLAG_TEMPTAMPER_DET_IRQ_OCCURED - This flag bit is set as 1 when temperature temper IRQ is
 *    enabled and IRQ event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_VOLTAMPER_DET_IRQ_OCCURED_MASK (0x8000000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_VOLTAMPER_DET_IRQ_OCCURED_SHIFT (27U)
/*! FLAG_VOLTAMPER_DET_IRQ_OCCURED - This flag bit is set as 1 when voltage temper IRQ is enabled
 *    and IRQ event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_VOLTAMPER_DET_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_VOLTAMPER_DET_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_VOLTAMPER_DET_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_LHTTAMPER_DET_IRQ_OCCURED_MASK (0x10000000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_LHTTAMPER_DET_IRQ_OCCURED_SHIFT (28U)
/*! FLAG_LHTTAMPER_DET_IRQ_OCCURED - This flag bit is set as 1 when light temper IRQ is enabled and
 *    IRQ event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_LHTTAMPER_DET_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_LHTTAMPER_DET_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_LHTTAMPER_DET_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_MASK (0x20000000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_SHIFT (29U)
/*! FLAG_CLKTAMPER_DET_IRQ_OCCURED - This flag bit is set as 1 when clock temper IRQ is enabled and
 *    IRQ event is triggered. This register is cleared 0 by PMC reset event.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_MASK)
/*! @} */

/*! @name ELS_AS_FLAG1 - ELS AS Flag1 */
/*! @{ */

#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_CORE_OCCURED_MASK (0x20000000U)
#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_CORE_OCCURED_SHIFT (29U)
/*! FLAG_HVD_CORE_OCCURED - This flag bit is set as 1 when HVD from VDD_CORE power domain is triggered.
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_CORE_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG1_FLAG_HVD_CORE_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG1_FLAG_HVD_CORE_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_VSYS_OCCURED_MASK (0x40000000U)
#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_VSYS_OCCURED_SHIFT (30U)
/*! FLAG_HVD_VSYS_OCCURED - This flag bit is set as 1 when HVD from VDD_SYS power domain is triggered
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_VSYS_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG1_FLAG_HVD_VSYS_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG1_FLAG_HVD_VSYS_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_VDDIO_OCCURED_MASK (0x80000000U)
#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_VDDIO_OCCURED_SHIFT (31U)
/*! FLAG_HVD_VDDIO_OCCURED - This flag bit is set as 1 when HVD from VDD power domain is triggered
 *  0b0..Not Triggered
 *  0b1..Triggered
 */
#define SYSCON_ELS_AS_FLAG1_FLAG_HVD_VDDIO_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG1_FLAG_HVD_VDDIO_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG1_FLAG_HVD_VDDIO_OCCURED_MASK)
/*! @} */

/*! @name CLOCK_CTRL - Clock Control */
/*! @{ */

#define SYSCON_CLOCK_CTRL_CLKIN_ENA_FM_USBH_LPT_MASK (0x2U)
#define SYSCON_CLOCK_CTRL_CLKIN_ENA_FM_USBH_LPT_SHIFT (1U)
/*! CLKIN_ENA_FM_USBH_LPT - Enables the clk_in clock for the Frequency Measurement, USB HS and LPTMR0/1 modules.
 *  0b0..Clock is not enabled
 *  0b1..Clock is enabled
 */
#define SYSCON_CLOCK_CTRL_CLKIN_ENA_FM_USBH_LPT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_CLKIN_ENA_FM_USBH_LPT_SHIFT)) & SYSCON_CLOCK_CTRL_CLKIN_ENA_FM_USBH_LPT_MASK)

#define SYSCON_CLOCK_CTRL_FRO1MHZ_ENA_MASK       (0x4U)
#define SYSCON_CLOCK_CTRL_FRO1MHZ_ENA_SHIFT      (2U)
/*! FRO1MHZ_ENA - Enables the FRO_1MHz clock for RTC module and for UTICK
 *  0b0..Clock is not enabled
 *  0b1..Clock is enabled
 */
#define SYSCON_CLOCK_CTRL_FRO1MHZ_ENA(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO1MHZ_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO1MHZ_ENA_MASK)

#define SYSCON_CLOCK_CTRL_FRO12MHZ_ENA_MASK      (0x8U)
#define SYSCON_CLOCK_CTRL_FRO12MHZ_ENA_SHIFT     (3U)
/*! FRO12MHZ_ENA - Enables the FRO_12MHz clock for the Flash, LPTMR0/1, and Frequency Measurement modules
 *  0b0..Clock is not enabled
 *  0b1..Clock is enabled
 */
#define SYSCON_CLOCK_CTRL_FRO12MHZ_ENA(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO12MHZ_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO12MHZ_ENA_MASK)

#define SYSCON_CLOCK_CTRL_FRO_HF_ENA_MASK        (0x10U)
#define SYSCON_CLOCK_CTRL_FRO_HF_ENA_SHIFT       (4U)
/*! FRO_HF_ENA - Enables FRO HF clock for the Frequency Measure module
 *  0b0..Clock is not enabled
 *  0b1..Clock is enabled
 */
#define SYSCON_CLOCK_CTRL_FRO_HF_ENA(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO_HF_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO_HF_ENA_MASK)

#define SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK         (0x20U)
#define SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT        (5U)
/*! CLKIN_ENA - Enables clk_in clock for MICFIL, CAN0/1, I3C0/1, SAI0/1, clkout.
 *  0b0..Clock is not enabled
 *  0b1..Clock is enabled
 */
#define SYSCON_CLOCK_CTRL_CLKIN_ENA(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK)

#define SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_MASK   (0x40U)
#define SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_SHIFT  (6U)
/*! FRO1MHZ_CLK_ENA - Enables FRO_1MHz clock for clock muxing in clock gen
 *  0b0..Clock is not enabled
 *  0b1..Clock is enabled
 */
#define SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_MASK)

#define SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_MASK (0x200U)
#define SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_SHIFT (9U)
/*! PLU_DEGLITCH_CLK_ENA - Enables clocks FRO_1MHz and FRO_12MHz for PLU deglitching.
 *  0b0..Clock is not enabled
 *  0b1..Clock is enabled
 */
#define SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_MASK)
/*! @} */

/*! @name I3C1FCLKSEL - I3C1 Functional Clock Selection */
/*! @{ */

#define SYSCON_I3C1FCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_I3C1FCLKSEL_SEL_SHIFT             (0U)
/*! SEL - I3C1 clock select
 *  0b000..No clock
 *  0b001..PLL0 clock
 *  0b010..CLKIN clock
 *  0b011..FRO_HF clock
 *  0b100..No clock
 *  0b101..PLL1_clk0 clock
 *  0b110..USB PLL clock
 *  0b111..No clock
 */
#define SYSCON_I3C1FCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSEL_SEL_SHIFT)) & SYSCON_I3C1FCLKSEL_SEL_MASK)
/*! @} */

/*! @name I3C1FCLKSTCSEL - Selects the I3C1 Time Control clock */
/*! @{ */

#define SYSCON_I3C1FCLKSTCSEL_SEL_MASK           (0x7U)
#define SYSCON_I3C1FCLKSTCSEL_SEL_SHIFT          (0U)
/*! SEL - I3C1 FCLK_STC clock select
 *  0b000..I3C1 functional clock I3C1FCLK
 *  0b001..FRO_1M clock
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_I3C1FCLKSTCSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSTCSEL_SEL_SHIFT)) & SYSCON_I3C1FCLKSTCSEL_SEL_MASK)
/*! @} */

/*! @name I3C1FCLKSTCDIV - I3C1 FCLK_STC Clock Divider */
/*! @{ */

#define SYSCON_I3C1FCLKSTCDIV_DIV_MASK           (0xFFU)
#define SYSCON_I3C1FCLKSTCDIV_DIV_SHIFT          (0U)
/*! DIV - Clock divider value */
#define SYSCON_I3C1FCLKSTCDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSTCDIV_DIV_SHIFT)) & SYSCON_I3C1FCLKSTCDIV_DIV_MASK)

#define SYSCON_I3C1FCLKSTCDIV_RESET_MASK         (0x20000000U)
#define SYSCON_I3C1FCLKSTCDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_I3C1FCLKSTCDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSTCDIV_RESET_SHIFT)) & SYSCON_I3C1FCLKSTCDIV_RESET_MASK)

#define SYSCON_I3C1FCLKSTCDIV_HALT_MASK          (0x40000000U)
#define SYSCON_I3C1FCLKSTCDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_I3C1FCLKSTCDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSTCDIV_HALT_SHIFT)) & SYSCON_I3C1FCLKSTCDIV_HALT_MASK)

#define SYSCON_I3C1FCLKSTCDIV_UNSTAB_MASK        (0x80000000U)
#define SYSCON_I3C1FCLKSTCDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_I3C1FCLKSTCDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSTCDIV_UNSTAB_SHIFT)) & SYSCON_I3C1FCLKSTCDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3C1FCLKSDIV - I3C1 FCLK Slow clock Divider */
/*! @{ */

#define SYSCON_I3C1FCLKSDIV_DIV_MASK             (0xFFU)
#define SYSCON_I3C1FCLKSDIV_DIV_SHIFT            (0U)
/*! DIV - Clock divider value */
#define SYSCON_I3C1FCLKSDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSDIV_DIV_SHIFT)) & SYSCON_I3C1FCLKSDIV_DIV_MASK)

#define SYSCON_I3C1FCLKSDIV_RESET_MASK           (0x20000000U)
#define SYSCON_I3C1FCLKSDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_I3C1FCLKSDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSDIV_RESET_SHIFT)) & SYSCON_I3C1FCLKSDIV_RESET_MASK)

#define SYSCON_I3C1FCLKSDIV_HALT_MASK            (0x40000000U)
#define SYSCON_I3C1FCLKSDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_I3C1FCLKSDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSDIV_HALT_SHIFT)) & SYSCON_I3C1FCLKSDIV_HALT_MASK)

#define SYSCON_I3C1FCLKSDIV_UNSTAB_MASK          (0x80000000U)
#define SYSCON_I3C1FCLKSDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_I3C1FCLKSDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSDIV_UNSTAB_SHIFT)) & SYSCON_I3C1FCLKSDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3C1FCLKDIV - I3C1 Functional Clock FCLK Divider */
/*! @{ */

#define SYSCON_I3C1FCLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_I3C1FCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value */
#define SYSCON_I3C1FCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKDIV_DIV_SHIFT)) & SYSCON_I3C1FCLKDIV_DIV_MASK)

#define SYSCON_I3C1FCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_I3C1FCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_I3C1FCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKDIV_RESET_SHIFT)) & SYSCON_I3C1FCLKDIV_RESET_MASK)

#define SYSCON_I3C1FCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_I3C1FCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_I3C1FCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKDIV_HALT_SHIFT)) & SYSCON_I3C1FCLKDIV_HALT_MASK)

#define SYSCON_I3C1FCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_I3C1FCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_I3C1FCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKDIV_UNSTAB_SHIFT)) & SYSCON_I3C1FCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3C1FCLKSSEL - I3C1 FCLK Slow Selection */
/*! @{ */

#define SYSCON_I3C1FCLKSSEL_SEL_MASK             (0x7U)
#define SYSCON_I3C1FCLKSSEL_SEL_SHIFT            (0U)
/*! SEL - I3C1 FCLK Slow Clock Select
 *  0b000..FRO_1M clock
 *  0b001..No clock
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_I3C1FCLKSSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3C1FCLKSSEL_SEL_SHIFT)) & SYSCON_I3C1FCLKSSEL_SEL_MASK)
/*! @} */

/*! @name ETB_STATUS - ETB Counter Status Register */
/*! @{ */

#define SYSCON_ETB_STATUS_IRQ_MASK               (0x2U)
#define SYSCON_ETB_STATUS_IRQ_SHIFT              (1U)
/*! IRQ - ETB Interrupt
 *  0b0..ETB interrupt is not asserted
 *  0b1..ETB interrupt is asserted when ETB count expires. Write 1 to clear it.
 */
#define SYSCON_ETB_STATUS_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_STATUS_IRQ_SHIFT)) & SYSCON_ETB_STATUS_IRQ_MASK)

#define SYSCON_ETB_STATUS_NMI_MASK               (0x4U)
#define SYSCON_ETB_STATUS_NMI_SHIFT              (2U)
/*! NMI - ETB NMI
 *  0b0..ETB NMI is not asserted
 *  0b1..ETB NMI is asserted. Write 1 to clear it.
 */
#define SYSCON_ETB_STATUS_NMI(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_STATUS_NMI_SHIFT)) & SYSCON_ETB_STATUS_NMI_MASK)

#define SYSCON_ETB_STATUS_DBG_HALT_REQ_MASK      (0x8U)
#define SYSCON_ETB_STATUS_DBG_HALT_REQ_SHIFT     (3U)
/*! DBG_HALT_REQ - Debug halt request
 *  0b0..The debug halt request signal is not asserted
 *  0b1..The debug halt request signal is asserted when the ETB count expires
 */
#define SYSCON_ETB_STATUS_DBG_HALT_REQ(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_STATUS_DBG_HALT_REQ_SHIFT)) & SYSCON_ETB_STATUS_DBG_HALT_REQ_MASK)
/*! @} */

/*! @name ETB_COUNTER_CTRL - ETB Counter Control Register */
/*! @{ */

#define SYSCON_ETB_COUNTER_CTRL_CNTEN_MASK       (0x1U)
#define SYSCON_ETB_COUNTER_CTRL_CNTEN_SHIFT      (0U)
/*! CNTEN - Enables the ETB counter
 *  0b0..ETB counter is disabled
 *  0b1..ETB counter is enabled
 */
#define SYSCON_ETB_COUNTER_CTRL_CNTEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_COUNTER_CTRL_CNTEN_SHIFT)) & SYSCON_ETB_COUNTER_CTRL_CNTEN_MASK)

#define SYSCON_ETB_COUNTER_CTRL_RSPT_MASK        (0x6U)
#define SYSCON_ETB_COUNTER_CTRL_RSPT_SHIFT       (1U)
/*! RSPT - Response Type
 *  0b00..No response when the ETB count expires
 *  0b01..Generates a normal interrupt when the ETB count expires
 *  0b10..Generates an NMI interrupt when the ETB count expires
 *  0b11..Generates a debug halt when the ETB count expires via CPU0 CTICHIN[2]
 */
#define SYSCON_ETB_COUNTER_CTRL_RSPT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_COUNTER_CTRL_RSPT_SHIFT)) & SYSCON_ETB_COUNTER_CTRL_RSPT_MASK)

#define SYSCON_ETB_COUNTER_CTRL_RLRQ_MASK        (0x8U)
#define SYSCON_ETB_COUNTER_CTRL_RLRQ_SHIFT       (3U)
/*! RLRQ - Reload request
 *  0b0..No effect
 *  0b1..Clears pending debug halt, NMI, or IRQ interrupt requests
 */
#define SYSCON_ETB_COUNTER_CTRL_RLRQ(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_COUNTER_CTRL_RLRQ_SHIFT)) & SYSCON_ETB_COUNTER_CTRL_RLRQ_MASK)
/*! @} */

/*! @name ETB_COUNTER_RELOAD - ETB Counter Reload Register */
/*! @{ */

#define SYSCON_ETB_COUNTER_RELOAD_RELOAD_MASK    (0x7FFU)
#define SYSCON_ETB_COUNTER_RELOAD_RELOAD_SHIFT   (0U)
/*! RELOAD - Byte count reload value */
#define SYSCON_ETB_COUNTER_RELOAD_RELOAD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_COUNTER_RELOAD_RELOAD_SHIFT)) & SYSCON_ETB_COUNTER_RELOAD_RELOAD_MASK)
/*! @} */

/*! @name ETB_COUNTER_VALUE - ETB Counter Value Register */
/*! @{ */

#define SYSCON_ETB_COUNTER_VALUE_COUNTER_VALUE_MASK (0x7FFU)
#define SYSCON_ETB_COUNTER_VALUE_COUNTER_VALUE_SHIFT (0U)
/*! COUNTER_VALUE - Byte count counter value */
#define SYSCON_ETB_COUNTER_VALUE_COUNTER_VALUE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ETB_COUNTER_VALUE_COUNTER_VALUE_SHIFT)) & SYSCON_ETB_COUNTER_VALUE_COUNTER_VALUE_MASK)
/*! @} */

/*! @name GRAY_CODE_LSB - Gray to Binary Converter Gray code_gray[31:0] */
/*! @{ */

#define SYSCON_GRAY_CODE_LSB_code_gray_31_0_MASK (0xFFFFFFFFU)
#define SYSCON_GRAY_CODE_LSB_code_gray_31_0_SHIFT (0U)
/*! code_gray_31_0 - Gray code [31:0] */
#define SYSCON_GRAY_CODE_LSB_code_gray_31_0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_GRAY_CODE_LSB_code_gray_31_0_SHIFT)) & SYSCON_GRAY_CODE_LSB_code_gray_31_0_MASK)
/*! @} */

/*! @name GRAY_CODE_MSB - Gray to Binary Converter Gray code_gray[41:32] */
/*! @{ */

#define SYSCON_GRAY_CODE_MSB_code_gray_41_32_MASK (0x3FFU)
#define SYSCON_GRAY_CODE_MSB_code_gray_41_32_SHIFT (0U)
/*! code_gray_41_32 - Gray code [41:32] */
#define SYSCON_GRAY_CODE_MSB_code_gray_41_32(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_GRAY_CODE_MSB_code_gray_41_32_SHIFT)) & SYSCON_GRAY_CODE_MSB_code_gray_41_32_MASK)
/*! @} */

/*! @name BINARY_CODE_LSB - Gray to Binary Converter Binary Code [31:0] */
/*! @{ */

#define SYSCON_BINARY_CODE_LSB_code_bin_31_0_MASK (0xFFFFFFFFU)
#define SYSCON_BINARY_CODE_LSB_code_bin_31_0_SHIFT (0U)
/*! code_bin_31_0 - Binary code [31:0] */
#define SYSCON_BINARY_CODE_LSB_code_bin_31_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BINARY_CODE_LSB_code_bin_31_0_SHIFT)) & SYSCON_BINARY_CODE_LSB_code_bin_31_0_MASK)
/*! @} */

/*! @name BINARY_CODE_MSB - Gray to Binary Converter Binary Code [41:32] */
/*! @{ */

#define SYSCON_BINARY_CODE_MSB_code_bin_41_32_MASK (0x3FFU)
#define SYSCON_BINARY_CODE_MSB_code_bin_41_32_SHIFT (0U)
/*! code_bin_41_32 - Binary code [41:32] */
#define SYSCON_BINARY_CODE_MSB_code_bin_41_32(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_BINARY_CODE_MSB_code_bin_41_32_SHIFT)) & SYSCON_BINARY_CODE_MSB_code_bin_41_32_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE - Control Automatic Clock Gating */
/*! @{ */

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMB_CTRL_MASK (0x4U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMB_CTRL_SHIFT (2U)
/*! RAMB_CTRL - Controls automatic clock gating for the RAMB Controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMB_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMB_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMB_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMC_CTRL_MASK (0x8U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMC_CTRL_SHIFT (3U)
/*! RAMC_CTRL - Controls automatic clock gating for the RAMC Controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMC_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMC_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMC_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMD_CTRL_MASK (0x10U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMD_CTRL_SHIFT (4U)
/*! RAMD_CTRL - Controls automatic clock gating for the RAMD Controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMD_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMD_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMD_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAME_CTRL_MASK (0x20U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAME_CTRL_SHIFT (5U)
/*! RAME_CTRL - Controls automatic clock gating for the RAMD Controller.
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAME_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAME_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAME_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMF_CTRL_MASK (0x40U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMF_CTRL_SHIFT (6U)
/*! RAMF_CTRL - Controls automatic clock gating for the RAMF Controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMF_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMF_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMF_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMG_CTRL_MASK (0x80U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMG_CTRL_SHIFT (7U)
/*! RAMG_CTRL - Controls automatic clock gating for the RAMG Controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMG_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMG_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMG_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMH_CTRL_MASK (0x100U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMH_CTRL_SHIFT (8U)
/*! RAMH_CTRL - Controls automatic clock gating for the RAMG Controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMH_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMH_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMH_CTRL_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDEC - Control Automatic Clock Gating C */
/*! @{ */

#define SYSCON_AUTOCLKGATEOVERRIDEC_RAMX_MASK    (0x40000000U)
#define SYSCON_AUTOCLKGATEOVERRIDEC_RAMX_SHIFT   (30U)
/*! RAMX - Controls automatic clock gating of the RAMX controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDEC_RAMX(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDEC_RAMX_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDEC_RAMX_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDEC_RAMA_MASK    (0x80000000U)
#define SYSCON_AUTOCLKGATEOVERRIDEC_RAMA_SHIFT   (31U)
/*! RAMA - Controls automatic clock gating of the RAMA controller
 *  0b0..Automatic clock gating is not overridden
 *  0b1..Automatic clock gating is overridden (Automatic clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDEC_RAMA(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDEC_RAMA_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDEC_RAMA_MASK)
/*! @} */

/*! @name PWM0SUBCTL - PWM0 Submodule Control */
/*! @{ */

#define SYSCON_PWM0SUBCTL_CLK0_EN_MASK           (0x1U)
#define SYSCON_PWM0SUBCTL_CLK0_EN_SHIFT          (0U)
/*! CLK0_EN - Enables PWM0 SUB Clock0 */
#define SYSCON_PWM0SUBCTL_CLK0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK0_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK0_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK1_EN_MASK           (0x2U)
#define SYSCON_PWM0SUBCTL_CLK1_EN_SHIFT          (1U)
/*! CLK1_EN - Enables PWM0 SUB Clock1 */
#define SYSCON_PWM0SUBCTL_CLK1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK1_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK1_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK2_EN_MASK           (0x4U)
#define SYSCON_PWM0SUBCTL_CLK2_EN_SHIFT          (2U)
/*! CLK2_EN - Enables PWM0 SUB Clock2 */
#define SYSCON_PWM0SUBCTL_CLK2_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK2_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK2_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK3_EN_MASK           (0x8U)
#define SYSCON_PWM0SUBCTL_CLK3_EN_SHIFT          (3U)
/*! CLK3_EN - Enables PWM0 SUB Clock3 */
#define SYSCON_PWM0SUBCTL_CLK3_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK3_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK3_EN_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM0_MASK          (0x1000U)
#define SYSCON_PWM0SUBCTL_DMAVALM0_SHIFT         (12U)
/*! DMAVALM0 - PWM0 submodule 0 DMA compare value done mask */
#define SYSCON_PWM0SUBCTL_DMAVALM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM0_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM0_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM1_MASK          (0x2000U)
#define SYSCON_PWM0SUBCTL_DMAVALM1_SHIFT         (13U)
/*! DMAVALM1 - PWM0 submodule 1 DMA compare value done mask */
#define SYSCON_PWM0SUBCTL_DMAVALM1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM1_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM1_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM2_MASK          (0x4000U)
#define SYSCON_PWM0SUBCTL_DMAVALM2_SHIFT         (14U)
/*! DMAVALM2 - PWM0 submodule 2 DMA compare value done mask */
#define SYSCON_PWM0SUBCTL_DMAVALM2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM2_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM2_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM3_MASK          (0x8000U)
#define SYSCON_PWM0SUBCTL_DMAVALM3_SHIFT         (15U)
/*! DMAVALM3 - PWM0 submodule 3 DMA compare value done mask */
#define SYSCON_PWM0SUBCTL_DMAVALM3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM3_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM3_MASK)
/*! @} */

/*! @name PWM1SUBCTL - PWM1 Submodule Control */
/*! @{ */

#define SYSCON_PWM1SUBCTL_CLK0_EN_MASK           (0x1U)
#define SYSCON_PWM1SUBCTL_CLK0_EN_SHIFT          (0U)
/*! CLK0_EN - Enables PWM1 SUB Clock0 */
#define SYSCON_PWM1SUBCTL_CLK0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK0_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK0_EN_MASK)

#define SYSCON_PWM1SUBCTL_CLK1_EN_MASK           (0x2U)
#define SYSCON_PWM1SUBCTL_CLK1_EN_SHIFT          (1U)
/*! CLK1_EN - Enables PWM1 SUB Clock1 */
#define SYSCON_PWM1SUBCTL_CLK1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK1_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK1_EN_MASK)

#define SYSCON_PWM1SUBCTL_CLK2_EN_MASK           (0x4U)
#define SYSCON_PWM1SUBCTL_CLK2_EN_SHIFT          (2U)
/*! CLK2_EN - Enables PWM1 SUB Clock2 */
#define SYSCON_PWM1SUBCTL_CLK2_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK2_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK2_EN_MASK)

#define SYSCON_PWM1SUBCTL_CLK3_EN_MASK           (0x8U)
#define SYSCON_PWM1SUBCTL_CLK3_EN_SHIFT          (3U)
/*! CLK3_EN - Enables PWM1 SUB Clock3 */
#define SYSCON_PWM1SUBCTL_CLK3_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK3_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK3_EN_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM0_MASK          (0x1000U)
#define SYSCON_PWM1SUBCTL_DMAVALM0_SHIFT         (12U)
/*! DMAVALM0 - PWM1 submodule 0 DMA compare value done mask */
#define SYSCON_PWM1SUBCTL_DMAVALM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM0_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM0_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM1_MASK          (0x2000U)
#define SYSCON_PWM1SUBCTL_DMAVALM1_SHIFT         (13U)
/*! DMAVALM1 - PWM1 submodule 1 DMA compare value done mask */
#define SYSCON_PWM1SUBCTL_DMAVALM1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM1_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM1_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM2_MASK          (0x4000U)
#define SYSCON_PWM1SUBCTL_DMAVALM2_SHIFT         (14U)
/*! DMAVALM2 - PWM1 submodule 2 DMA compare value done mask */
#define SYSCON_PWM1SUBCTL_DMAVALM2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM2_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM2_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM3_MASK          (0x8000U)
#define SYSCON_PWM1SUBCTL_DMAVALM3_SHIFT         (15U)
/*! DMAVALM3 - PWM1 submodule 3 DMA compare value done mask */
#define SYSCON_PWM1SUBCTL_DMAVALM3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM3_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM3_MASK)
/*! @} */

/*! @name CTIMERGLOBALSTARTEN - CTIMER Global Start Enable */
/*! @{ */

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK (0x1U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT (0U)
/*! CTIMER0_CLK_EN - Enables the CTIMER0 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK (0x2U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT (1U)
/*! CTIMER1_CLK_EN - Enables the CTIMER1 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK (0x4U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT (2U)
/*! CTIMER2_CLK_EN - Enables the CTIMER2 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK (0x8U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT (3U)
/*! CTIMER3_CLK_EN - Enables the CTIMER3 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK (0x10U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT (4U)
/*! CTIMER4_CLK_EN - Enables the CTIMER4 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK)
/*! @} */

/*! @name ECC_ENABLE_CTRL - RAM ECC Enable Control */
/*! @{ */

#define SYSCON_ECC_ENABLE_CTRL_RAMA_ECC_ENABLE_MASK (0x1U)
#define SYSCON_ECC_ENABLE_CTRL_RAMA_ECC_ENABLE_SHIFT (0U)
/*! RAMA_ECC_ENABLE - RAMA ECC enable
 *  0b0..ECC is disabled
 *  0b1..ECC is enabled
 */
#define SYSCON_ECC_ENABLE_CTRL_RAMA_ECC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ECC_ENABLE_CTRL_RAMA_ECC_ENABLE_SHIFT)) & SYSCON_ECC_ENABLE_CTRL_RAMA_ECC_ENABLE_MASK)

#define SYSCON_ECC_ENABLE_CTRL_RAMB_RAMX_ECC_ENABLE_MASK (0x2U)
#define SYSCON_ECC_ENABLE_CTRL_RAMB_RAMX_ECC_ENABLE_SHIFT (1U)
/*! RAMB_RAMX_ECC_ENABLE - RAMB and RAMX ECC enable
 *  0b0..ECC is disabled
 *  0b1..ECC is enabled
 */
#define SYSCON_ECC_ENABLE_CTRL_RAMB_RAMX_ECC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ECC_ENABLE_CTRL_RAMB_RAMX_ECC_ENABLE_SHIFT)) & SYSCON_ECC_ENABLE_CTRL_RAMB_RAMX_ECC_ENABLE_MASK)

#define SYSCON_ECC_ENABLE_CTRL_RAMD_RAMC_ECC_ENABLE_MASK (0x4U)
#define SYSCON_ECC_ENABLE_CTRL_RAMD_RAMC_ECC_ENABLE_SHIFT (2U)
/*! RAMD_RAMC_ECC_ENABLE - RAMD and RAMC ECC enable
 *  0b0..ECC is disabled
 *  0b1..ECC is enabled
 */
#define SYSCON_ECC_ENABLE_CTRL_RAMD_RAMC_ECC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ECC_ENABLE_CTRL_RAMD_RAMC_ECC_ENABLE_SHIFT)) & SYSCON_ECC_ENABLE_CTRL_RAMD_RAMC_ECC_ENABLE_MASK)

#define SYSCON_ECC_ENABLE_CTRL_RAMF_RAME_ECC_ENABLE_MASK (0x8U)
#define SYSCON_ECC_ENABLE_CTRL_RAMF_RAME_ECC_ENABLE_SHIFT (3U)
/*! RAMF_RAME_ECC_ENABLE - RAMF and RAME ECC enable
 *  0b0..ECC is disabled
 *  0b1..ECC is enabled
 */
#define SYSCON_ECC_ENABLE_CTRL_RAMF_RAME_ECC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ECC_ENABLE_CTRL_RAMF_RAME_ECC_ENABLE_SHIFT)) & SYSCON_ECC_ENABLE_CTRL_RAMF_RAME_ECC_ENABLE_MASK)
/*! @} */

/*! @name DEBUG_LOCK_EN - Control Write Access to Security */
/*! @{ */

#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK       (0xFU)
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT      (0U)
/*! LOCK_ALL - Controls write access to the security registers
 *  0b0000..Any other value than b1010: disables write access to all registers
 *  0b1010..Enables write access to all registers
 */
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT)) & SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK)
/*! @} */

/*! @name DEBUG_FEATURES - Cortex Debug Features Control */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN_MASK    (0x3U)
#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT   (0U)
/*! CPU0_DBGEN - CPU0 invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN_MASK    (0xCU)
#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT   (2U)
/*! CPU0_NIDEN - CPU0 non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_MASK   (0x30U)
#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT  (4U)
/*! CPU0_SPIDEN - CPU0 secure privileged invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_MASK  (0xC0U)
#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT (6U)
/*! CPU0_SPNIDEN - CPU0 secure privileged non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU1_DBGEN_MASK    (0x300U)
#define SYSCON_DEBUG_FEATURES_CPU1_DBGEN_SHIFT   (8U)
/*! CPU1_DBGEN - CPU1 invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CPU1_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU1_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU1_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU1_NIDEN_MASK    (0xC00U)
#define SYSCON_DEBUG_FEATURES_CPU1_NIDEN_SHIFT   (10U)
/*! CPU1_NIDEN - CPU1 non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CPU1_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU1_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU1_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DSP_DBGDEN_MASK    (0x3000U)
#define SYSCON_DEBUG_FEATURES_DSP_DBGDEN_SHIFT   (12U)
/*! DSP_DBGDEN - DSP invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DSP_DBGDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DSP_DBGDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DSP_DBGDEN_MASK)
/*! @} */

/*! @name DEBUG_FEATURES_DP - Cortex Debug Features Control (Duplicate) */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK (0x3U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT (0U)
/*! CPU0_DBGEN - CPU0 invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK (0xCU)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT (2U)
/*! CPU0_NIDEN - CPU0 non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK (0x30U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT (4U)
/*! CPU0_SPIDEN - CPU0 secure privileged invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK (0xC0U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT (6U)
/*! CPU0_SPNIDEN - CPU0 secure privileged non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU1_DBGEN_MASK (0x300U)
#define SYSCON_DEBUG_FEATURES_DP_CPU1_DBGEN_SHIFT (8U)
/*! CPU1_DBGEN - CPU1 invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU1_DBGEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU1_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU1_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU1_NIDEN_MASK (0xC00U)
#define SYSCON_DEBUG_FEATURES_DP_CPU1_NIDEN_SHIFT (10U)
/*! CPU1_NIDEN - CPU1 non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU1_NIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU1_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU1_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_DSP_DBGEN_MASK  (0x3000U)
#define SYSCON_DEBUG_FEATURES_DP_DSP_DBGEN_SHIFT (12U)
/*! DSP_DBGEN - DSP invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_DSP_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_DSP_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_DSP_DBGEN_MASK)
/*! @} */

/*! @name SWD_ACCESS_CPU - CPU0 Software Debug Access..CPU1 Software Debug Access */
/*! @{ */

#define SYSCON_SWD_ACCESS_CPU_SEC_CODE_MASK      (0xFFFFFFFFU)
#define SYSCON_SWD_ACCESS_CPU_SEC_CODE_SHIFT     (0U)
/*! SEC_CODE - Security code to allow CPU1 DAP: 0x12345678
 *  0b00000000000000000000000000000000..CPU0 DAP is not allowed. Reading back register is read as 0x5.
 *  0b00010010001101000101011001111000..Value to write to enable CPU0 SWD access. Reading back register is read as 0xA.
 */
#define SYSCON_SWD_ACCESS_CPU_SEC_CODE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_SWD_ACCESS_CPU_SEC_CODE_SHIFT)) & SYSCON_SWD_ACCESS_CPU_SEC_CODE_MASK)
/*! @} */

/*! @name DEBUG_AUTH_BEACON - Debug Authentication BEACON */
/*! @{ */

#define SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK     (0xFFFFFFFFU)
#define SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT    (0U)
/*! BEACON - Sets by the debug authentication code in ROM to pass the debug beacons (Credential
 *    Beacon and Authentication Beacon) to the application code.
 */
#define SYSCON_DEBUG_AUTH_BEACON_BEACON(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT)) & SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK)
/*! @} */

/*! @name SWD_ACCESS_DSP - DSP Software Debug Access */
/*! @{ */

#define SYSCON_SWD_ACCESS_DSP_SEC_CODE_MASK      (0xFFFFFFFFU)
#define SYSCON_SWD_ACCESS_DSP_SEC_CODE_SHIFT     (0U)
/*! SEC_CODE - DSP SWD-AP: 0x12345678
 *  0b00000000000000000000000000000000..DSP DAP is not allowed. Reading back register is read as 0x5.
 *  0b00010010001101000101011001111000..Value to write to enable DSP SWD access. Reading back register is read as 0xA.
 */
#define SYSCON_SWD_ACCESS_DSP_SEC_CODE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_SWD_ACCESS_DSP_SEC_CODE_SHIFT)) & SYSCON_SWD_ACCESS_DSP_SEC_CODE_MASK)
/*! @} */

/*! @name JTAG_ID - JTAG Chip ID */
/*! @{ */

#define SYSCON_JTAG_ID_JTAG_ID_MASK              (0xFFFFFFFFU)
#define SYSCON_JTAG_ID_JTAG_ID_SHIFT             (0U)
/*! JTAG_ID - Indicates the device ID */
#define SYSCON_JTAG_ID_JTAG_ID(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_JTAG_ID_JTAG_ID_SHIFT)) & SYSCON_JTAG_ID_JTAG_ID_MASK)
/*! @} */

/*! @name DEVICE_TYPE - Device Type */
/*! @{ */

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_MASK      (0xFFFFFFFFU)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SHIFT     (0U)
/*! DEVICE_TYPE - Indicates DEVICE TYPE. */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_MASK)
/*! @} */

/*! @name DEVICE_ID0 - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK     (0xF00000U)
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT    (20U)
/*! ROM_REV_MINOR - ROM revision. */
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT)) & SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK)
/*! @} */

/*! @name DIEID - Chip Revision ID and Number */
/*! @{ */

#define SYSCON_DIEID_MINOR_REVISION_MASK         (0xFU)
#define SYSCON_DIEID_MINOR_REVISION_SHIFT        (0U)
/*! MINOR_REVISION - Chip minor revision */
#define SYSCON_DIEID_MINOR_REVISION(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_MINOR_REVISION_SHIFT)) & SYSCON_DIEID_MINOR_REVISION_MASK)

#define SYSCON_DIEID_MAJOR_REVISION_MASK         (0xF0U)
#define SYSCON_DIEID_MAJOR_REVISION_SHIFT        (4U)
/*! MAJOR_REVISION - Chip major revision */
#define SYSCON_DIEID_MAJOR_REVISION(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_MAJOR_REVISION_SHIFT)) & SYSCON_DIEID_MAJOR_REVISION_MASK)

#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_MASK      (0xFFFFF00U)
#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_SHIFT     (8U)
/*! MCO_NUM_IN_DIE_ID - Chip number */
#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_MCO_NUM_IN_DIE_ID_SHIFT)) & SYSCON_DIEID_MCO_NUM_IN_DIE_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_Register_Masks */

/* Backward compatibility */
#define SYSCON                               SYSCON0
/*!
 * @brief Get the chip value.
 *
 * @return chip version, 0x0: A0 version chip, 0x1: A1 version chip, 0xFF: invalid version.
 */
static inline uint32_t Chip_GetVersion(void)
{
    uint32_t deviceRevision;

    deviceRevision = SYSCON->DIEID & SYSCON_DIEID_MINOR_REVISION_MASK;

    if(0UL == deviceRevision) /* A0 device revision is 0 */
    {
        return 0x0;
    }
    else if(1UL == deviceRevision) /* A1 device revision is 1 */
    {
        return 0x1;
    }
    else
    {
        return 0xFF;
    }
}


/*!
 * @}
 */ /* end of group SYSCON_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SYSCON_H_ */

