/*
** ###################################################################
**     Processors:          MIMX9301CVVXD_ca55
**                          MIMX9301CVVXD_cm33
**                          MIMX9301DVVXD_ca55
**                          MIMX9301DVVXD_cm33
**                          MIMX9302CVVXD_ca55
**                          MIMX9302CVVXD_cm33
**                          MIMX9302DVVXD_ca55
**                          MIMX9302DVVXD_cm33
**                          MIMX9311CVXXM_ca55
**                          MIMX9311CVXXM_cm33
**                          MIMX9311DVXXM_ca55
**                          MIMX9311DVXXM_cm33
**                          MIMX9311XVXXM_ca55
**                          MIMX9311XVXXM_cm33
**                          MIMX9312CVXXM_ca55
**                          MIMX9312CVXXM_cm33
**                          MIMX9312DVXXM_ca55
**                          MIMX9312DVXXM_cm33
**                          MIMX9312XVXXM_ca55
**                          MIMX9312XVXXM_cm33
**                          MIMX9321CVXXM_ca55
**                          MIMX9321CVXXM_cm33
**                          MIMX9321DVXXM_ca55
**                          MIMX9321DVXXM_cm33
**                          MIMX9321XVXXM_ca55
**                          MIMX9321XVXXM_cm33
**                          MIMX9322CVXXM_ca55
**                          MIMX9322CVXXM_cm33
**                          MIMX9322DVXXM_ca55
**                          MIMX9322DVXXM_cm33
**                          MIMX9322XVXXM_ca55
**                          MIMX9322XVXXM_cm33
**                          MIMX9331AVTXM_ca55
**                          MIMX9331AVTXM_cm33
**                          MIMX9331CVVXM_ca55
**                          MIMX9331CVVXM_cm33
**                          MIMX9331DVVXM_ca55
**                          MIMX9331DVVXM_cm33
**                          MIMX9331XVVXM_ca55
**                          MIMX9331XVVXM_cm33
**                          MIMX9332AVTXM_ca55
**                          MIMX9332AVTXM_cm33
**                          MIMX9332CVVXM_ca55
**                          MIMX9332CVVXM_cm33
**                          MIMX9332DVVXM_ca55
**                          MIMX9332DVVXM_cm33
**                          MIMX9332XVVXM_ca55
**                          MIMX9332XVVXM_cm33
**                          MIMX9351AVTXM_ca55
**                          MIMX9351AVTXM_cm33
**                          MIMX9351CVVXM_ca55
**                          MIMX9351CVVXM_cm33
**                          MIMX9351DVVXM_ca55
**                          MIMX9351DVVXM_cm33
**                          MIMX9351XVVXM_ca55
**                          MIMX9351XVVXM_cm33
**                          MIMX9352AVTXM_ca55
**                          MIMX9352AVTXM_cm33
**                          MIMX9352CVVXM_ca55
**                          MIMX9352CVVXM_cm33
**                          MIMX9352DVVXM_ca55
**                          MIMX9352DVVXM_cm33
**                          MIMX9352XVVXM_ca55
**                          MIMX9352XVVXM_cm33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PXP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PXP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PXP
 *
 * CMSIS Peripheral Access Layer for PXP
 */

#if !defined(PERI_PXP_H_)
#define PERI_PXP_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9301CVVXD_ca55) || defined(CPU_MIMX9301DVVXD_ca55))
#include "MIMX9301_ca55_COMMON.h"
#elif (defined(CPU_MIMX9301CVVXD_cm33) || defined(CPU_MIMX9301DVVXD_cm33))
#include "MIMX9301_cm33_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_ca55) || defined(CPU_MIMX9302DVVXD_ca55))
#include "MIMX9302_ca55_COMMON.h"
#elif (defined(CPU_MIMX9302CVVXD_cm33) || defined(CPU_MIMX9302DVVXD_cm33))
#include "MIMX9302_cm33_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_ca55) || defined(CPU_MIMX9311DVXXM_ca55) || defined(CPU_MIMX9311XVXXM_ca55))
#include "MIMX9311_ca55_COMMON.h"
#elif (defined(CPU_MIMX9311CVXXM_cm33) || defined(CPU_MIMX9311DVXXM_cm33) || defined(CPU_MIMX9311XVXXM_cm33))
#include "MIMX9311_cm33_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_ca55) || defined(CPU_MIMX9312DVXXM_ca55) || defined(CPU_MIMX9312XVXXM_ca55))
#include "MIMX9312_ca55_COMMON.h"
#elif (defined(CPU_MIMX9312CVXXM_cm33) || defined(CPU_MIMX9312DVXXM_cm33) || defined(CPU_MIMX9312XVXXM_cm33))
#include "MIMX9312_cm33_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_ca55) || defined(CPU_MIMX9321DVXXM_ca55) || defined(CPU_MIMX9321XVXXM_ca55))
#include "MIMX9321_ca55_COMMON.h"
#elif (defined(CPU_MIMX9321CVXXM_cm33) || defined(CPU_MIMX9321DVXXM_cm33) || defined(CPU_MIMX9321XVXXM_cm33))
#include "MIMX9321_cm33_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_ca55) || defined(CPU_MIMX9322DVXXM_ca55) || defined(CPU_MIMX9322XVXXM_ca55))
#include "MIMX9322_ca55_COMMON.h"
#elif (defined(CPU_MIMX9322CVXXM_cm33) || defined(CPU_MIMX9322DVXXM_cm33) || defined(CPU_MIMX9322XVXXM_cm33))
#include "MIMX9322_cm33_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_ca55) || defined(CPU_MIMX9331CVVXM_ca55) || defined(CPU_MIMX9331DVVXM_ca55) || defined(CPU_MIMX9331XVVXM_ca55))
#include "MIMX9331_ca55_COMMON.h"
#elif (defined(CPU_MIMX9331AVTXM_cm33) || defined(CPU_MIMX9331CVVXM_cm33) || defined(CPU_MIMX9331DVVXM_cm33) || defined(CPU_MIMX9331XVVXM_cm33))
#include "MIMX9331_cm33_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_ca55) || defined(CPU_MIMX9332CVVXM_ca55) || defined(CPU_MIMX9332DVVXM_ca55) || defined(CPU_MIMX9332XVVXM_ca55))
#include "MIMX9332_ca55_COMMON.h"
#elif (defined(CPU_MIMX9332AVTXM_cm33) || defined(CPU_MIMX9332CVVXM_cm33) || defined(CPU_MIMX9332DVVXM_cm33) || defined(CPU_MIMX9332XVVXM_cm33))
#include "MIMX9332_cm33_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_ca55) || defined(CPU_MIMX9351CVVXM_ca55) || defined(CPU_MIMX9351DVVXM_ca55) || defined(CPU_MIMX9351XVVXM_ca55))
#include "MIMX9351_ca55_COMMON.h"
#elif (defined(CPU_MIMX9351AVTXM_cm33) || defined(CPU_MIMX9351CVVXM_cm33) || defined(CPU_MIMX9351DVVXM_cm33) || defined(CPU_MIMX9351XVVXM_cm33))
#include "MIMX9351_cm33_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_ca55) || defined(CPU_MIMX9352CVVXM_ca55) || defined(CPU_MIMX9352DVVXM_ca55) || defined(CPU_MIMX9352XVVXM_ca55))
#include "MIMX9352_ca55_COMMON.h"
#elif (defined(CPU_MIMX9352AVTXM_cm33) || defined(CPU_MIMX9352CVVXM_cm33) || defined(CPU_MIMX9352DVVXM_cm33) || defined(CPU_MIMX9352XVVXM_cm33))
#include "MIMX9352_cm33_COMMON.h"
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
   -- PXP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PXP_Peripheral_Access_Layer PXP Peripheral Access Layer
 * @{
 */

/** PXP - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Control Register 0, offset: 0x0 */
    __IO uint32_t SET;                               /**< Control Register 0, offset: 0x4 */
    __IO uint32_t CLR;                               /**< Control Register 0, offset: 0x8 */
    __IO uint32_t TOG;                               /**< Control Register 0, offset: 0xC */
  } CTRL;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Status Register, offset: 0x10 */
    __IO uint32_t SET;                               /**< Status Register, offset: 0x14 */
    __IO uint32_t CLR;                               /**< Status Register, offset: 0x18 */
    __IO uint32_t TOG;                               /**< Status Register, offset: 0x1C */
  } STAT;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< Output Buffer Control Register, offset: 0x20 */
    __IO uint32_t SET;                               /**< Output Buffer Control Register, offset: 0x24 */
    __IO uint32_t CLR;                               /**< Output Buffer Control Register, offset: 0x28 */
    __IO uint32_t TOG;                               /**< Output Buffer Control Register, offset: 0x2C */
  } OUT_CTRL;
  __IO uint32_t OUT_BUF;                           /**< Output Frame Buffer Pointer Register, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __IO uint32_t OUT_BUF2;                          /**< Output Frame Buffer Pointer #2 Register, offset: 0x40 */
       uint8_t RESERVED_1[12];
  __IO uint32_t OUT_PITCH;                         /**< Output Buffer Pitch Register, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t OUT_LRC;                           /**< Output Surface Lower Right Coordinate Register, offset: 0x60 */
       uint8_t RESERVED_3[12];
  __IO uint32_t OUT_PS_ULC;                        /**< Processed Surface Upper Left Coordinate Register, offset: 0x70 */
       uint8_t RESERVED_4[12];
  __IO uint32_t OUT_PS_LRC;                        /**< Processed Surface Lower Right Coordinate Register, offset: 0x80 */
       uint8_t RESERVED_5[12];
  __IO uint32_t OUT_AS_ULC;                        /**< Alpha Surface Upper Left Coordinate Register, offset: 0x90 */
       uint8_t RESERVED_6[12];
  __IO uint32_t OUT_AS_LRC;                        /**< Alpha Surface Lower Right Coordinate Register, offset: 0xA0 */
       uint8_t RESERVED_7[12];
  struct {                                         /* offset: 0xB0 */
    __IO uint32_t RW;                                /**< Processed Surface (PS) Control Register, offset: 0xB0 */
    __IO uint32_t SET;                               /**< Processed Surface (PS) Control Register, offset: 0xB4 */
    __IO uint32_t CLR;                               /**< Processed Surface (PS) Control Register, offset: 0xB8 */
    __IO uint32_t TOG;                               /**< Processed Surface (PS) Control Register, offset: 0xBC */
  } PS_CTRL;
  __IO uint32_t PS_BUF;                            /**< PS Input Buffer Address Register, offset: 0xC0 */
       uint8_t RESERVED_8[12];
  __IO uint32_t PS_UBUF;                           /**< PS U/Cb or 2 Plane UV Input Buffer Address Register, offset: 0xD0 */
       uint8_t RESERVED_9[12];
  __IO uint32_t PS_VBUF;                           /**< PS V/Cr Input Buffer Address Register, offset: 0xE0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t PS_PITCH;                          /**< Processed Surface Pitch Register, offset: 0xF0 */
       uint8_t RESERVED_11[12];
  __IO uint32_t PS_BACKGROUND_0;                   /**< PS Background Color Register, offset: 0x100 */
       uint8_t RESERVED_12[12];
  __IO uint32_t PS_SCALE;                          /**< PS Scale Factor Register, offset: 0x110 */
       uint8_t RESERVED_13[12];
  __IO uint32_t PS_OFFSET;                         /**< PS Scale Offset Register, offset: 0x120 */
       uint8_t RESERVED_14[12];
  __IO uint32_t PS_CLRKEYLOW_0;                    /**< PS Color Key Low Register, offset: 0x130 */
       uint8_t RESERVED_15[12];
  __IO uint32_t PS_CLRKEYHIGH_0;                   /**< PS Color Key High Register, offset: 0x140 */
       uint8_t RESERVED_16[12];
  __IO uint32_t AS_CTRL;                           /**< Alpha Surface Control Register, offset: 0x150 */
       uint8_t RESERVED_17[12];
  __IO uint32_t AS_BUF;                            /**< Alpha Surface Buffer Pointer Register, offset: 0x160 */
       uint8_t RESERVED_18[12];
  __IO uint32_t AS_PITCH;                          /**< Alpha Surface Pitch Register, offset: 0x170 */
       uint8_t RESERVED_19[12];
  __IO uint32_t AS_CLRKEYLOW_0;                    /**< Overlay Color Key Low Register, offset: 0x180 */
       uint8_t RESERVED_20[12];
  __IO uint32_t AS_CLRKEYHIGH_0;                   /**< Overlay Color Key High Register, offset: 0x190 */
       uint8_t RESERVED_21[12];
  __IO uint32_t CSC1_COEF0;                        /**< Color Space Conversion 1 Coefficient 0 Register, offset: 0x1A0 */
       uint8_t RESERVED_22[12];
  __IO uint32_t CSC1_COEF1;                        /**< Color Space Conversion 1 Coefficient 1 Register, offset: 0x1B0 */
       uint8_t RESERVED_23[12];
  __IO uint32_t CSC1_COEF2;                        /**< Color Space Conversion 1 Coefficient 2 Register, offset: 0x1C0 */
       uint8_t RESERVED_24[12];
  __IO uint32_t CSC2_CTRL;                         /**< Color Space Conversion 2 Control Register, offset: 0x1D0 */
       uint8_t RESERVED_25[12];
  __IO uint32_t CSC2_COEF0;                        /**< Color Space Conversion 2 Coefficient 0 Register, offset: 0x1E0 */
       uint8_t RESERVED_26[12];
  __IO uint32_t CSC2_COEF1;                        /**< Color Space Conversion 2 Coefficient 1 Register, offset: 0x1F0 */
       uint8_t RESERVED_27[12];
  __IO uint32_t CSC2_COEF2;                        /**< Color Space Conversion 2 Coefficient 2 Register, offset: 0x200 */
       uint8_t RESERVED_28[12];
  __IO uint32_t CSC2_COEF3;                        /**< Color Space Conversion 2 Coefficient 3 Register, offset: 0x210 */
       uint8_t RESERVED_29[12];
  __IO uint32_t CSC2_COEF4;                        /**< Color Space Conversion 2 Coefficient 4 Register, offset: 0x220 */
       uint8_t RESERVED_30[12];
  __IO uint32_t CSC2_COEF5;                        /**< Color Space Conversion 2 Coefficient 5 Register, offset: 0x230 */
       uint8_t RESERVED_31[92];
  __IO uint32_t ALPHA_A_CTRL;                      /**< Alpha Engine A Control Register, offset: 0x290 */
       uint8_t RESERVED_32[12];
  __IO uint32_t ALPHA_B_CTRL;                      /**< Alpha Engine B Control Register, offset: 0x2A0 */
       uint8_t RESERVED_33[12];
  __IO uint32_t ALPHA_B_CTRL_1;                    /**< Alpha Engine B Control 1 Register, offset: 0x2B0 */
       uint8_t RESERVED_34[12];
  __IO uint32_t PS_BACKGROUND_1;                   /**< PS Background Color 1 Register, offset: 0x2C0 */
       uint8_t RESERVED_35[12];
  __IO uint32_t PS_CLRKEYLOW_1;                    /**< PS Color Key Low Register, offset: 0x2D0 */
       uint8_t RESERVED_36[12];
  __IO uint32_t PS_CLRKEYHIGH_1;                   /**< PS Color Key High Register, offset: 0x2E0 */
       uint8_t RESERVED_37[12];
  __IO uint32_t AS_CLRKEYLOW_1;                    /**< Overlay Color Key Low Register, offset: 0x2F0 */
       uint8_t RESERVED_38[12];
  __IO uint32_t AS_CLRKEYHIGH_1;                   /**< Overlay Color Key High Register, offset: 0x300 */
       uint8_t RESERVED_39[12];
  struct {                                         /* offset: 0x310 */
    __IO uint32_t RW;                                /**< Control Register 2, offset: 0x310 */
    __IO uint32_t SET;                               /**< Control Register 2, offset: 0x314 */
    __IO uint32_t CLR;                               /**< Control Register 2, offset: 0x318 */
    __IO uint32_t TOG;                               /**< Control Register 2, offset: 0x31C */
  } CTRL2;
  __IO uint32_t POWER_REG0;                        /**< Power Control Register 0, offset: 0x320 */
       uint8_t RESERVED_40[12];
  __IO uint32_t POWER_REG1;                        /**< Power Control Register 1, offset: 0x330 */
       uint8_t RESERVED_41[12];
  struct {                                         /* offset: 0x340 */
    __IO uint32_t RW;                                /**< Data Path Control 0 Register, offset: 0x340 */
    __IO uint32_t SET;                               /**< Data Path Control 0 Register, offset: 0x344 */
    __IO uint32_t CLR;                               /**< Data Path Control 0 Register, offset: 0x348 */
    __IO uint32_t TOG;                               /**< Data Path Control 0 Register, offset: 0x34C */
  } DATA_PATH_CTRL0;
       uint8_t RESERVED_42[64];
  struct {                                         /* offset: 0x390 */
    __IO uint32_t RW;                                /**< IRQ Mask Register, offset: 0x390 */
    __IO uint32_t SET;                               /**< IRQ Mask Register, offset: 0x394 */
    __IO uint32_t CLR;                               /**< IRQ Mask Register, offset: 0x398 */
    __IO uint32_t TOG;                               /**< IRQ Mask Register, offset: 0x39C */
  } IRQ_MASK;
  struct {                                         /* offset: 0x3A0 */
    __IO uint32_t RW;                                /**< Interrupt Register, offset: 0x3A0 */
    __IO uint32_t SET;                               /**< Interrupt Register, offset: 0x3A4 */
    __IO uint32_t CLR;                               /**< Interrupt Register, offset: 0x3A8 */
    __IO uint32_t TOG;                               /**< Interrupt Register, offset: 0x3AC */
  } IRQ;
       uint8_t RESERVED_43[80];
  __IO uint32_t NEXT;                              /**< Next Frame Pointer Register, offset: 0x400 */
       uint8_t RESERVED_44[76];
  struct {                                         /* offset: 0x450 */
    __IO uint32_t RW;                                /**< Input Fetch Control Channel 0 Register, offset: 0x450 */
    __IO uint32_t SET;                               /**< Input Fetch Control Channel 0 Register, offset: 0x454 */
    __IO uint32_t CLR;                               /**< Input Fetch Control Channel 0 Register, offset: 0x458 */
    __IO uint32_t TOG;                               /**< Input Fetch Control Channel 0 Register, offset: 0x45C */
  } INPUT_FETCH_CTRL_CH0;
  struct {                                         /* offset: 0x460 */
    __IO uint32_t RW;                                /**< Input Fetch Control Channel 1 Register, offset: 0x460 */
    __IO uint32_t SET;                               /**< Input Fetch Control Channel 1 Register, offset: 0x464 */
    __IO uint32_t CLR;                               /**< Input Fetch Control Channel 1 Register, offset: 0x468 */
    __IO uint32_t TOG;                               /**< Input Fetch Control Channel 1 Register, offset: 0x46C */
  } INPUT_FETCH_CTRL_CH1;
  __I  uint32_t INPUT_FETCH_STATUS_CH0;            /**< Input Fetch Status Channel 0 Register, offset: 0x470 */
       uint8_t RESERVED_45[12];
  __I  uint32_t INPUT_FETCH_STATUS_CH1;            /**< Input Fetch Status Channel 1 Register, offset: 0x480 */
       uint8_t RESERVED_46[12];
  __IO uint32_t INPUT_FETCH_ACTIVE_SIZE_ULC_CH0;   /**< Input Fetch Active Size ULC Channel 0 Register, offset: 0x490 */
       uint8_t RESERVED_47[12];
  __IO uint32_t INPUT_FETCH_ACTIVE_SIZE_LRC_CH0;   /**< Input Fetch Active Size LRC Channel 0 Register, offset: 0x4A0 */
       uint8_t RESERVED_48[12];
  __IO uint32_t INPUT_FETCH_ACTIVE_SIZE_ULC_CH1;   /**< Input Fetch Active Size ULC Channel 1 Register, offset: 0x4B0 */
       uint8_t RESERVED_49[12];
  __IO uint32_t INPUT_FETCH_ACTIVE_SIZE_LRC_CH1;   /**< Input Fetch Active Size LRC Channel 1 Register, offset: 0x4C0 */
       uint8_t RESERVED_50[12];
  __IO uint32_t INPUT_FETCH_SIZE_CH0;              /**< Input Fetch Size Channel 0 Register, offset: 0x4D0 */
       uint8_t RESERVED_51[12];
  __IO uint32_t INPUT_FETCH_SIZE_CH1;              /**< Input Fetch Size Channel 1 Register, offset: 0x4E0 */
       uint8_t RESERVED_52[12];
  __IO uint32_t INPUT_FETCH_BACKGROUND_COLOR_CH0;  /**< Input Fetch Background Color Channel 0 Register, offset: 0x4F0 */
       uint8_t RESERVED_53[12];
  __IO uint32_t INPUT_FETCH_BACKGROUND_COLOR_CH1;  /**< Input Fetch Background Color Channel 1 Register, offset: 0x500 */
       uint8_t RESERVED_54[12];
  __IO uint32_t INPUT_FETCH_PITCH;                 /**< Input Fetch Pitch Register, offset: 0x510 */
       uint8_t RESERVED_55[12];
  struct {                                         /* offset: 0x520 */
    __IO uint32_t RW;                                /**< Input Fetch Shift Control Channel 0 Register, offset: 0x520 */
    __IO uint32_t SET;                               /**< Input Fetch Shift Control Channel 0 Register, offset: 0x524 */
    __IO uint32_t CLR;                               /**< Input Fetch Shift Control Channel 0 Register, offset: 0x528 */
    __IO uint32_t TOG;                               /**< Input Fetch Shift Control Channel 0 Register, offset: 0x52C */
  } INPUT_FETCH_SHIFT_CTRL_CH0;
  struct {                                         /* offset: 0x530 */
    __IO uint32_t RW;                                /**< Input Fetch Shift Control Channel 1 Register, offset: 0x530 */
    __IO uint32_t SET;                               /**< Input Fetch Shift Control Channel 1 Register, offset: 0x534 */
    __IO uint32_t CLR;                               /**< Input Fetch Shift Control Channel 1 Register, offset: 0x538 */
    __IO uint32_t TOG;                               /**< Input Fetch Shift Control Channel 1 Register, offset: 0x53C */
  } INPUT_FETCH_SHIFT_CTRL_CH1;
  struct {                                         /* offset: 0x540 */
    __IO uint32_t RW;                                /**< Input Fetch Shift Offset Channel 0 Register, offset: 0x540 */
    __IO uint32_t SET;                               /**< Input Fetch Shift Offset Channel 0 Register, offset: 0x544 */
    __IO uint32_t CLR;                               /**< Input Fetch Shift Offset Channel 0 Register, offset: 0x548 */
    __IO uint32_t TOG;                               /**< Input Fetch Shift Offset Channel 0 Register, offset: 0x54C */
  } INPUT_FETCH_SHIFT_OFFSET_CH0;
  struct {                                         /* offset: 0x550 */
    __IO uint32_t RW;                                /**< Input Fetch Shift Offset Channel 1 Register, offset: 0x550 */
    __IO uint32_t SET;                               /**< Input Fetch Shift Offset Channel 1 Register, offset: 0x554 */
    __IO uint32_t CLR;                               /**< Input Fetch Shift Offset Channel 1 Register, offset: 0x558 */
    __IO uint32_t TOG;                               /**< Input Fetch Shift Offset Channel 1 Register, offset: 0x55C */
  } INPUT_FETCH_SHIFT_OFFSET_CH1;
  struct {                                         /* offset: 0x560 */
    __IO uint32_t RW;                                /**< Input Fetch Shift Width Channel 0 Register, offset: 0x560 */
    __IO uint32_t SET;                               /**< Input Fetch Shift Width Channel 0 Register, offset: 0x564 */
    __IO uint32_t CLR;                               /**< Input Fetch Shift Width Channel 0 Register, offset: 0x568 */
    __IO uint32_t TOG;                               /**< Input Fetch Shift Width Channel 0 Register, offset: 0x56C */
  } INPUT_FETCH_SHIFT_WIDTH_CH0;
  struct {                                         /* offset: 0x570 */
    __IO uint32_t RW;                                /**< Input Fetch Shift Width Channel 1 Register, offset: 0x570 */
    __IO uint32_t SET;                               /**< Input Fetch Shift Width Channel 1 Register, offset: 0x574 */
    __IO uint32_t CLR;                               /**< Input Fetch Shift Width Channel 1 Register, offset: 0x578 */
    __IO uint32_t TOG;                               /**< Input Fetch Shift Width Channel 1 Register, offset: 0x57C */
  } INPUT_FETCH_SHIFT_WIDTH_CH1;
  __IO uint32_t INPUT_FETCH_ADDR_0_CH0;            /**< Input Fetch Address 0 Channel 0 Register, offset: 0x580 */
       uint8_t RESERVED_56[12];
  __IO uint32_t INPUT_FETCH_ADDR_1_CH0;            /**< Input Fetch Address 1 Channel 0 Register, offset: 0x590 */
       uint8_t RESERVED_57[12];
  __IO uint32_t INPUT_FETCH_ADDR_0_CH1;            /**< Input Fetch Address 0 Channel 1 Register, offset: 0x5A0 */
       uint8_t RESERVED_58[12];
  __IO uint32_t INPUT_FETCH_ADDR_1_CH1;            /**< Input Fetch Address 1 Channel 1 Register, offset: 0x5B0 */
       uint8_t RESERVED_59[12];
  struct {                                         /* offset: 0x5C0 */
    __IO uint32_t RW;                                /**< Input Store Control Channel 0 Register, offset: 0x5C0 */
    __IO uint32_t SET;                               /**< Input Store Control Channel 0 Register, offset: 0x5C4 */
    __IO uint32_t CLR;                               /**< Input Store Control Channel 0 Register, offset: 0x5C8 */
    __IO uint32_t TOG;                               /**< Input Store Control Channel 0 Register, offset: 0x5CC */
  } INPUT_STORE_CTRL_CH0;
  struct {                                         /* offset: 0x5D0 */
    __IO uint32_t RW;                                /**< Input Store Control Channel 1 Register, offset: 0x5D0 */
    __IO uint32_t SET;                               /**< Input Store Control Channel 1 Register, offset: 0x5D4 */
    __IO uint32_t CLR;                               /**< Input Store Control Channel 1 Register, offset: 0x5D8 */
    __IO uint32_t TOG;                               /**< Input Store Control Channel 1 Register, offset: 0x5DC */
  } INPUT_STORE_CTRL_CH1;
  __I  uint32_t INPUT_STORE_STATUS_CH0;            /**< Input Store Status Channel 0 Register, offset: 0x5E0 */
       uint8_t RESERVED_60[12];
  __I  uint32_t INPUT_STORE_STATUS_CH1;            /**< Input Store Status Channel 1 Register, offset: 0x5F0 */
       uint8_t RESERVED_61[12];
  __IO uint32_t INPUT_STORE_SIZE_CH0;              /**< Input Store Size Channel 0 Register, offset: 0x600 */
       uint8_t RESERVED_62[12];
  __IO uint32_t INPUT_STORE_SIZE_CH1;              /**< Input Store Size Channel 1 Register, offset: 0x610 */
       uint8_t RESERVED_63[12];
  __IO uint32_t INPUT_STORE_PITCH;                 /**< Input Store Pitch Register, offset: 0x620 */
       uint8_t RESERVED_64[12];
  struct {                                         /* offset: 0x630 */
    __IO uint32_t RW;                                /**< Input Store Shift Control Channel 0 Register, offset: 0x630 */
    __IO uint32_t SET;                               /**< Input Store Shift Control Channel 0 Register, offset: 0x634 */
    __IO uint32_t CLR;                               /**< Input Store Shift Control Channel 0 Register, offset: 0x638 */
    __IO uint32_t TOG;                               /**< Input Store Shift Control Channel 0 Register, offset: 0x63C */
  } INPUT_STORE_SHIFT_CTRL_CH0;
  struct {                                         /* offset: 0x640 */
    __IO uint32_t RW;                                /**< Input Store Shift Control Channel 1 Register, offset: 0x640 */
    __IO uint32_t SET;                               /**< Input Store Shift Control Channel 1 Register, offset: 0x644 */
    __IO uint32_t CLR;                               /**< Input Store Shift Control Channel 1 Register, offset: 0x648 */
    __IO uint32_t TOG;                               /**< Input Store Shift Control Channel 1 Register, offset: 0x64C */
  } INPUT_STORE_SHIFT_CTRL_CH1;
       uint8_t RESERVED_65[64];
  __IO uint32_t INPUT_STORE_ADDR_0_CH0;            /**< Input Store Address 0 Channel 0 Register, offset: 0x690 */
       uint8_t RESERVED_66[12];
  __IO uint32_t INPUT_STORE_ADDR_1_CH0;            /**< Input Store Address 1 Channel 0 Register, offset: 0x6A0 */
       uint8_t RESERVED_67[12];
  __IO uint32_t INPUT_STORE_FILL_DATA_CH0;         /**< Input Store Fill Data Channel 0 Register, offset: 0x6B0 */
       uint8_t RESERVED_68[12];
  __IO uint32_t INPUT_STORE_ADDR_0_CH1;            /**< Input Store Address 0 Channel 1 Register, offset: 0x6C0 */
       uint8_t RESERVED_69[12];
  __IO uint32_t INPUT_STORE_ADDR_1_CH1;            /**< Input Store Address 1 Channel 1 Register, offset: 0x6D0 */
       uint8_t RESERVED_70[12];
  __IO uint32_t INPUT_STORE_D_MASK0_H_CH0;         /**< Input Store Data Mask 0 High Byte Channel 0 Register, offset: 0x6E0 */
       uint8_t RESERVED_71[12];
  __IO uint32_t INPUT_STORE_D_MASK0_L_CH0;         /**< Input Store Data Mask 0 Low Byte Channel 0 Register, offset: 0x6F0 */
       uint8_t RESERVED_72[12];
  __IO uint32_t INPUT_STORE_D_MASK1_H_CH0;         /**< Input Store Data Mask 1 High Byte Channel 0 Register, offset: 0x700 */
       uint8_t RESERVED_73[12];
  __IO uint32_t INPUT_STORE_D_MASK1_L_CH0;         /**< Input Store Data Mask 1 Low Byte Channel 0 Register, offset: 0x710 */
       uint8_t RESERVED_74[12];
  __IO uint32_t INPUT_STORE_D_MASK2_H_CH0;         /**< Input Store Data Mask 2 High Byte Channel 0 Register, offset: 0x720 */
       uint8_t RESERVED_75[12];
  __IO uint32_t INPUT_STORE_D_MASK2_L_CH0;         /**< Input Store Data Mask 2 Low Byte Channel 0 Register, offset: 0x730 */
       uint8_t RESERVED_76[12];
  __IO uint32_t INPUT_STORE_D_MASK3_H_CH0;         /**< Input Store Data Mask 3 High Byte Channel 0 Register, offset: 0x740 */
       uint8_t RESERVED_77[12];
  __IO uint32_t INPUT_STORE_D_MASK3_L_CH0;         /**< Input Store Data Mask 3 Low Byte Channel 0 Register, offset: 0x750 */
       uint8_t RESERVED_78[12];
  __IO uint32_t INPUT_STORE_D_MASK4_H_CH0;         /**< Input Store Data Mask 4 High Byte Channel 0 Register, offset: 0x760 */
       uint8_t RESERVED_79[12];
  __IO uint32_t INPUT_STORE_D_MASK4_L_CH0;         /**< Input Store Data Mask 4 Low Byte Channel 0 Register, offset: 0x770 */
       uint8_t RESERVED_80[12];
  __IO uint32_t INPUT_STORE_D_MASK5_H_CH0;         /**< Input Store Data Mask 5 High Byte Channel 0 Register, offset: 0x780 */
       uint8_t RESERVED_81[12];
  __IO uint32_t INPUT_STORE_D_MASK5_L_CH0;         /**< Input Store Data Mask 5 Low Byte Channel 0 Register, offset: 0x790 */
       uint8_t RESERVED_82[12];
  __IO uint32_t INPUT_STORE_D_MASK6_H_CH0;         /**< Input Store Data Mask 6 High Byte Channel 0 Register, offset: 0x7A0 */
       uint8_t RESERVED_83[12];
  __IO uint32_t INPUT_STORE_D_MASK6_L_CH0;         /**< Input Store Data Mask 6 Low Byte Channel 0 Register, offset: 0x7B0 */
       uint8_t RESERVED_84[12];
  __IO uint32_t INPUT_STORE_D_MASK7_H_CH0;         /**< Input Store Data Mask 7 High Byte Channel 0 Register, offset: 0x7C0 */
       uint8_t RESERVED_85[28];
  __IO uint32_t INPUT_STORE_D_MASK7_L_CH0;         /**< Input Store Data Mask 7 Low Byte Channel 0 Register, offset: 0x7E0 */
       uint8_t RESERVED_86[12];
  __IO uint32_t INPUT_STORE_D_SHIFT_L_CH0;         /**< Input Store Data Shift Low Channel 0 Register, offset: 0x7F0 */
       uint8_t RESERVED_87[12];
  __IO uint32_t INPUT_STORE_D_SHIFT_H_CH0;         /**< Input Store Data Shift High Channel 0 Register, offset: 0x800 */
       uint8_t RESERVED_88[12];
  __IO uint32_t INPUT_STORE_F_SHIFT_L_CH0;         /**< Input Store Flag Shift Low Channel 0 Register, offset: 0x810 */
       uint8_t RESERVED_89[12];
  __IO uint32_t INPUT_STORE_F_SHIFT_H_CH0;         /**< Input Store Flag Shift High Channel 0 Register, offset: 0x820 */
       uint8_t RESERVED_90[12];
  __IO uint32_t INPUT_STORE_F_MASK_L_CH0;          /**< Input Store Flag Mask Low Channel 0 Register, offset: 0x830 */
       uint8_t RESERVED_91[12];
  __IO uint32_t INPUT_STORE_F_MASK_H_CH0;          /**< Input Store Flag Mask High Channel 0 Register, offset: 0x840 */
       uint8_t RESERVED_92[9372];
  __IO uint32_t BUS_MUX;                           /**< Bus MUX Register, offset: 0x2CE0 */
       uint8_t RESERVED_93[12];
  __IO uint32_t HANDSHAKE_READY_MUX0;              /**< Handshake Ready MUX 0 Register, offset: 0x2CF0 */
       uint8_t RESERVED_94[12];
  __IO uint32_t HANDSHAKE_READY_MUX1;              /**< Handshake Ready MUX 1 Register, offset: 0x2D00 */
       uint8_t RESERVED_95[12];
  __IO uint32_t HANDSHAKE_DONE_MUX0;               /**< Handshake Done MUX 0 Register, offset: 0x2D10 */
       uint8_t RESERVED_96[12];
  __IO uint32_t HANDSHAKE_DONE_MUX1;               /**< Handshake Done MUX 1 Register, offset: 0x2D20 */
       uint8_t RESERVED_97[12];
  struct {                                         /* offset: 0x2D30 */
    __IO uint32_t RW;                                /**< Handshake CPU Fetch Register, offset: 0x2D30 */
    __IO uint32_t SET;                               /**< Handshake CPU Fetch Register, offset: 0x2D34 */
    __IO uint32_t CLR;                               /**< Handshake CPU Fetch Register, offset: 0x2D38 */
    __IO uint32_t TOG;                               /**< Handshake CPU Fetch Register, offset: 0x2D3C */
  } HANDSHAKE_CPU_FETCH;
  struct {                                         /* offset: 0x2D40 */
    __IO uint32_t RW;                                /**< Handshake CPU Store Register, offset: 0x2D40 */
    __IO uint32_t SET;                               /**< Handshake CPU Store Register, offset: 0x2D44 */
    __IO uint32_t CLR;                               /**< Handshake CPU Store Register, offset: 0x2D48 */
    __IO uint32_t TOG;                               /**< Handshake CPU Store Register, offset: 0x2D4C */
  } HANDSHAKE_CPU_STORE;
} PXP_Type;

/* ----------------------------------------------------------------------------
   -- PXP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PXP_Register_Masks PXP Register Masks
 * @{
 */

/*! @name CTRL - Control Register 0 */
/*! @{ */

#define PXP_CTRL_ENABLE_MASK                     (0x1U)
#define PXP_CTRL_ENABLE_SHIFT                    (0U)
/*! ENABLE - ENABLE */
#define PXP_CTRL_ENABLE(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ENABLE_SHIFT)) & PXP_CTRL_ENABLE_MASK)

#define PXP_CTRL_IRQ_ENABLE_MASK                 (0x2U)
#define PXP_CTRL_IRQ_ENABLE_SHIFT                (1U)
/*! IRQ_ENABLE - IRQ_ENABLE */
#define PXP_CTRL_IRQ_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_IRQ_ENABLE_SHIFT)) & PXP_CTRL_IRQ_ENABLE_MASK)

#define PXP_CTRL_NEXT_IRQ_ENABLE_MASK            (0x4U)
#define PXP_CTRL_NEXT_IRQ_ENABLE_SHIFT           (2U)
/*! NEXT_IRQ_ENABLE - NEXT_IRQ_ENABLE */
#define PXP_CTRL_NEXT_IRQ_ENABLE(x)              (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_NEXT_IRQ_ENABLE_SHIFT)) & PXP_CTRL_NEXT_IRQ_ENABLE_MASK)

#define PXP_CTRL_RSVD0_MASK                      (0xF8U)
#define PXP_CTRL_RSVD0_SHIFT                     (3U)
/*! RSVD0 - RSVD0 */
#define PXP_CTRL_RSVD0(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_RSVD0_SHIFT)) & PXP_CTRL_RSVD0_MASK)

#define PXP_CTRL_ROTATE0_MASK                    (0x300U)
#define PXP_CTRL_ROTATE0_SHIFT                   (8U)
/*! ROTATE0 - ROTATE0
 *  0b00..ROT_0 : rotate 0 degrees
 *  0b01..ROT_90 : rotate 90 degrees
 *  0b10..ROT_180 : rotate 180 degrees
 *  0b11..ROT_270 : rotate 270 degrees
 */
#define PXP_CTRL_ROTATE0(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ROTATE0_SHIFT)) & PXP_CTRL_ROTATE0_MASK)

#define PXP_CTRL_HFLIP0_MASK                     (0x400U)
#define PXP_CTRL_HFLIP0_SHIFT                    (10U)
/*! HFLIP0 - HFLIP0 */
#define PXP_CTRL_HFLIP0(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_HFLIP0_SHIFT)) & PXP_CTRL_HFLIP0_MASK)

#define PXP_CTRL_VFLIP0_MASK                     (0x800U)
#define PXP_CTRL_VFLIP0_SHIFT                    (11U)
/*! VFLIP0 - VFLIP0 */
#define PXP_CTRL_VFLIP0(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_VFLIP0_SHIFT)) & PXP_CTRL_VFLIP0_MASK)

#define PXP_CTRL_ROTATE1_MASK                    (0x3000U)
#define PXP_CTRL_ROTATE1_SHIFT                   (12U)
/*! ROTATE1 - ROTATE1
 *  0b00..ROT_0 : rotate 0 degrees
 *  0b01..ROT_90 : rotate 90 degrees
 *  0b10..ROT_180 : rotate 180 degrees
 *  0b11..ROT_270 : rotate 270 degrees
 */
#define PXP_CTRL_ROTATE1(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ROTATE1_SHIFT)) & PXP_CTRL_ROTATE1_MASK)

#define PXP_CTRL_HFLIP1_MASK                     (0x4000U)
#define PXP_CTRL_HFLIP1_SHIFT                    (14U)
/*! HFLIP1 - HFLIP1 */
#define PXP_CTRL_HFLIP1(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_HFLIP1_SHIFT)) & PXP_CTRL_HFLIP1_MASK)

#define PXP_CTRL_VFLIP1_MASK                     (0x8000U)
#define PXP_CTRL_VFLIP1_SHIFT                    (15U)
/*! VFLIP1 - VFLIP1 */
#define PXP_CTRL_VFLIP1(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_VFLIP1_SHIFT)) & PXP_CTRL_VFLIP1_MASK)

#define PXP_CTRL_ENABLE_PS_AS_OUT_MASK           (0x10000U)
#define PXP_CTRL_ENABLE_PS_AS_OUT_SHIFT          (16U)
/*! ENABLE_PS_AS_OUT - ENABLE_PS_AS_OUT */
#define PXP_CTRL_ENABLE_PS_AS_OUT(x)             (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ENABLE_PS_AS_OUT_SHIFT)) & PXP_CTRL_ENABLE_PS_AS_OUT_MASK)

#define PXP_CTRL_RSVD6_MASK                      (0xE0000U)
#define PXP_CTRL_RSVD6_SHIFT                     (17U)
/*! RSVD6 - RSVD6 */
#define PXP_CTRL_RSVD6(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_RSVD6_SHIFT)) & PXP_CTRL_RSVD6_MASK)

#define PXP_CTRL_ENABLE_INPUT_FETCH_STORE_MASK   (0x100000U)
#define PXP_CTRL_ENABLE_INPUT_FETCH_STORE_SHIFT  (20U)
/*! ENABLE_INPUT_FETCH_STORE - ENABLE_INPUT_FETCH_STORE */
#define PXP_CTRL_ENABLE_INPUT_FETCH_STORE(x)     (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ENABLE_INPUT_FETCH_STORE_SHIFT)) & PXP_CTRL_ENABLE_INPUT_FETCH_STORE_MASK)

#define PXP_CTRL_ENABLE_ALPHA_B_MASK             (0x200000U)
#define PXP_CTRL_ENABLE_ALPHA_B_SHIFT            (21U)
/*! ENABLE_ALPHA_B - ENABLE_ALPHA_B */
#define PXP_CTRL_ENABLE_ALPHA_B(x)               (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ENABLE_ALPHA_B_SHIFT)) & PXP_CTRL_ENABLE_ALPHA_B_MASK)

#define PXP_CTRL_RSVD1_MASK                      (0x400000U)
#define PXP_CTRL_RSVD1_SHIFT                     (22U)
/*! RSVD1 - RSVD1 */
#define PXP_CTRL_RSVD1(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_RSVD1_SHIFT)) & PXP_CTRL_RSVD1_MASK)

#define PXP_CTRL_BLOCK_SIZE_MASK                 (0x800000U)
#define PXP_CTRL_BLOCK_SIZE_SHIFT                (23U)
/*! BLOCK_SIZE - BLOCK_SIZE
 *  0b0..BLK_SIZE_8X8 : Process 8x8 pixel blocks.
 *  0b1..BLK_SIZE_16X16 : Process 16x16 pixel blocks.
 */
#define PXP_CTRL_BLOCK_SIZE(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_BLOCK_SIZE_SHIFT)) & PXP_CTRL_BLOCK_SIZE_MASK)

#define PXP_CTRL_ENABLE_CSC2_MASK                (0x1000000U)
#define PXP_CTRL_ENABLE_CSC2_SHIFT               (24U)
/*! ENABLE_CSC2 - ENABLE_CSC2 */
#define PXP_CTRL_ENABLE_CSC2(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ENABLE_CSC2_SHIFT)) & PXP_CTRL_ENABLE_CSC2_MASK)

#define PXP_CTRL_RSVD5_MASK                      (0x2000000U)
#define PXP_CTRL_RSVD5_SHIFT                     (25U)
/*! RSVD5 - RSVD5 */
#define PXP_CTRL_RSVD5(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_RSVD5_SHIFT)) & PXP_CTRL_RSVD5_MASK)

#define PXP_CTRL_ENABLE_ROTATE0_MASK             (0x4000000U)
#define PXP_CTRL_ENABLE_ROTATE0_SHIFT            (26U)
/*! ENABLE_ROTATE0 - ENABLE_ROTATE0 */
#define PXP_CTRL_ENABLE_ROTATE0(x)               (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ENABLE_ROTATE0_SHIFT)) & PXP_CTRL_ENABLE_ROTATE0_MASK)

#define PXP_CTRL_ENABLE_ROTATE1_MASK             (0x8000000U)
#define PXP_CTRL_ENABLE_ROTATE1_SHIFT            (27U)
/*! ENABLE_ROTATE1 - ENABLE_ROTATE1 */
#define PXP_CTRL_ENABLE_ROTATE1(x)               (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_ENABLE_ROTATE1_SHIFT)) & PXP_CTRL_ENABLE_ROTATE1_MASK)

#define PXP_CTRL_RSVD2_MASK                      (0x10000000U)
#define PXP_CTRL_RSVD2_SHIFT                     (28U)
/*! RSVD2 - RSVD2 */
#define PXP_CTRL_RSVD2(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_RSVD2_SHIFT)) & PXP_CTRL_RSVD2_MASK)

#define PXP_CTRL_RSVD4_MASK                      (0x20000000U)
#define PXP_CTRL_RSVD4_SHIFT                     (29U)
/*! RSVD4 - RSVD4 */
#define PXP_CTRL_RSVD4(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_RSVD4_SHIFT)) & PXP_CTRL_RSVD4_MASK)

#define PXP_CTRL_CLKGATE_MASK                    (0x40000000U)
#define PXP_CTRL_CLKGATE_SHIFT                   (30U)
/*! CLKGATE - CLKGATE */
#define PXP_CTRL_CLKGATE(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_CLKGATE_SHIFT)) & PXP_CTRL_CLKGATE_MASK)

#define PXP_CTRL_SFTRST_MASK                     (0x80000000U)
#define PXP_CTRL_SFTRST_SHIFT                    (31U)
/*! SFTRST - SFTRST */
#define PXP_CTRL_SFTRST(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL_SFTRST_SHIFT)) & PXP_CTRL_SFTRST_MASK)
/*! @} */

/*! @name STAT - Status Register */
/*! @{ */

#define PXP_STAT_IRQ0_MASK                       (0x1U)
#define PXP_STAT_IRQ0_SHIFT                      (0U)
/*! IRQ0 - IRQ0 */
#define PXP_STAT_IRQ0(x)                         (((uint32_t)(((uint32_t)(x)) << PXP_STAT_IRQ0_SHIFT)) & PXP_STAT_IRQ0_MASK)

#define PXP_STAT_AXI_WRITE_ERROR_0_MASK          (0x2U)
#define PXP_STAT_AXI_WRITE_ERROR_0_SHIFT         (1U)
/*! AXI_WRITE_ERROR_0 - AXI_WRITE_ERROR_0 */
#define PXP_STAT_AXI_WRITE_ERROR_0(x)            (((uint32_t)(((uint32_t)(x)) << PXP_STAT_AXI_WRITE_ERROR_0_SHIFT)) & PXP_STAT_AXI_WRITE_ERROR_0_MASK)

#define PXP_STAT_AXI_READ_ERROR_0_MASK           (0x4U)
#define PXP_STAT_AXI_READ_ERROR_0_SHIFT          (2U)
/*! AXI_READ_ERROR_0 - AXI_READ_ERROR_0 */
#define PXP_STAT_AXI_READ_ERROR_0(x)             (((uint32_t)(((uint32_t)(x)) << PXP_STAT_AXI_READ_ERROR_0_SHIFT)) & PXP_STAT_AXI_READ_ERROR_0_MASK)

#define PXP_STAT_NEXT_IRQ_MASK                   (0x8U)
#define PXP_STAT_NEXT_IRQ_SHIFT                  (3U)
/*! NEXT_IRQ - NEXT_IRQ */
#define PXP_STAT_NEXT_IRQ(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_STAT_NEXT_IRQ_SHIFT)) & PXP_STAT_NEXT_IRQ_MASK)

#define PXP_STAT_AXI_ERROR_ID_0_MASK             (0xF0U)
#define PXP_STAT_AXI_ERROR_ID_0_SHIFT            (4U)
/*! AXI_ERROR_ID_0 - AXI_ERROR_ID_0 */
#define PXP_STAT_AXI_ERROR_ID_0(x)               (((uint32_t)(((uint32_t)(x)) << PXP_STAT_AXI_ERROR_ID_0_SHIFT)) & PXP_STAT_AXI_ERROR_ID_0_MASK)

#define PXP_STAT_RSVD1_MASK                      (0x100U)
#define PXP_STAT_RSVD1_SHIFT                     (8U)
/*! RSVD1 - RSVD1 */
#define PXP_STAT_RSVD1(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_STAT_RSVD1_SHIFT)) & PXP_STAT_RSVD1_MASK)

#define PXP_STAT_AXI_WRITE_ERROR_1_MASK          (0x200U)
#define PXP_STAT_AXI_WRITE_ERROR_1_SHIFT         (9U)
/*! AXI_WRITE_ERROR_1 - AXI_WRITE_ERROR_1 */
#define PXP_STAT_AXI_WRITE_ERROR_1(x)            (((uint32_t)(((uint32_t)(x)) << PXP_STAT_AXI_WRITE_ERROR_1_SHIFT)) & PXP_STAT_AXI_WRITE_ERROR_1_MASK)

#define PXP_STAT_AXI_READ_ERROR_1_MASK           (0x400U)
#define PXP_STAT_AXI_READ_ERROR_1_SHIFT          (10U)
/*! AXI_READ_ERROR_1 - AXI_READ_ERROR_1 */
#define PXP_STAT_AXI_READ_ERROR_1(x)             (((uint32_t)(((uint32_t)(x)) << PXP_STAT_AXI_READ_ERROR_1_SHIFT)) & PXP_STAT_AXI_READ_ERROR_1_MASK)

#define PXP_STAT_RSVD2_MASK                      (0x800U)
#define PXP_STAT_RSVD2_SHIFT                     (11U)
/*! RSVD2 - RSVD2 */
#define PXP_STAT_RSVD2(x)                        (((uint32_t)(((uint32_t)(x)) << PXP_STAT_RSVD2_SHIFT)) & PXP_STAT_RSVD2_MASK)

#define PXP_STAT_AXI_ERROR_ID_1_MASK             (0xF000U)
#define PXP_STAT_AXI_ERROR_ID_1_SHIFT            (12U)
/*! AXI_ERROR_ID_1 - AXI_ERROR_ID_1 */
#define PXP_STAT_AXI_ERROR_ID_1(x)               (((uint32_t)(((uint32_t)(x)) << PXP_STAT_AXI_ERROR_ID_1_SHIFT)) & PXP_STAT_AXI_ERROR_ID_1_MASK)

#define PXP_STAT_BLOCKY_MASK                     (0xFF0000U)
#define PXP_STAT_BLOCKY_SHIFT                    (16U)
/*! BLOCKY - BLOCKY */
#define PXP_STAT_BLOCKY(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_STAT_BLOCKY_SHIFT)) & PXP_STAT_BLOCKY_MASK)

#define PXP_STAT_BLOCKX_MASK                     (0xFF000000U)
#define PXP_STAT_BLOCKX_SHIFT                    (24U)
/*! BLOCKX - BLOCKX */
#define PXP_STAT_BLOCKX(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_STAT_BLOCKX_SHIFT)) & PXP_STAT_BLOCKX_MASK)
/*! @} */

/*! @name OUT_CTRL - Output Buffer Control Register */
/*! @{ */

#define PXP_OUT_CTRL_FORMAT_MASK                 (0x1FU)
#define PXP_OUT_CTRL_FORMAT_SHIFT                (0U)
/*! FORMAT - FORMAT
 *  0b00000..ARGB8888 : 32-bit pixels
 *  0b00100..RGB888 : 32-bit pixels (unpacked 24-bit pixel in 32 bit DWORD.)
 *  0b00101..RGB888P : 24-bit pixels (packed 24-bit format)
 *  0b01000..ARGB1555 : 16-bit pixels
 *  0b01001..ARGB4444 : 16-bit pixels
 *  0b01100..RGB555 : 16-bit pixels
 *  0b01101..RGB444 : 16-bit pixels
 *  0b01110..RGB565 : 16-bit pixels
 *  0b10000..YUV1P444 : 32-bit pixels (1-plane XYUV unpacked)
 *  0b10010..UYVY1P422 : 16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
 *  0b10011..VYUY1P422 : 16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
 *  0b10100..Y8 : 8-bit monochrome pixels (1-plane Y luma output)
 *  0b10101..Y4 : 4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
 *  0b11000..YUV2P422 : 16-bit pixels (2-plane UV interleaved bytes)
 *  0b11001..YUV2P420 : 16-bit pixels (2-plane UV)
 *  0b11010..YVU2P422 : 16-bit pixels (2-plane VU interleaved bytes)
 *  0b11011..YVU2P420 : 16-bit pixels (2-plane VU)
 */
#define PXP_OUT_CTRL_FORMAT(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_OUT_CTRL_FORMAT_SHIFT)) & PXP_OUT_CTRL_FORMAT_MASK)

#define PXP_OUT_CTRL_RSVD0_MASK                  (0xE0U)
#define PXP_OUT_CTRL_RSVD0_SHIFT                 (5U)
/*! RSVD0 - RSVD0 */
#define PXP_OUT_CTRL_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_OUT_CTRL_RSVD0_SHIFT)) & PXP_OUT_CTRL_RSVD0_MASK)

#define PXP_OUT_CTRL_INTERLACED_OUTPUT_MASK      (0x300U)
#define PXP_OUT_CTRL_INTERLACED_OUTPUT_SHIFT     (8U)
/*! INTERLACED_OUTPUT - INTERLACED_OUTPUT
 *  0b00..PROGRESSIVE : All data written in progressive format to the OUTBUF Pointer.
 *  0b01..FIELD0 : Interlaced output: only data for field 0 is written to the OUTBUF Pointer.
 *  0b10..FIELD1 : Interlaced output: only data for field 1 is written to the OUTBUF2 Pointer.
 *  0b11..INTERLACED : Interlaced output: data for field 0 is written to OUTBUF and data for field 1 is written to OUTBUF2.
 */
#define PXP_OUT_CTRL_INTERLACED_OUTPUT(x)        (((uint32_t)(((uint32_t)(x)) << PXP_OUT_CTRL_INTERLACED_OUTPUT_SHIFT)) & PXP_OUT_CTRL_INTERLACED_OUTPUT_MASK)

#define PXP_OUT_CTRL_RSVD1_MASK                  (0x7FFC00U)
#define PXP_OUT_CTRL_RSVD1_SHIFT                 (10U)
/*! RSVD1 - RSVD1 */
#define PXP_OUT_CTRL_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_OUT_CTRL_RSVD1_SHIFT)) & PXP_OUT_CTRL_RSVD1_MASK)

#define PXP_OUT_CTRL_ALPHA_OUTPUT_MASK           (0x800000U)
#define PXP_OUT_CTRL_ALPHA_OUTPUT_SHIFT          (23U)
/*! ALPHA_OUTPUT - ALPHA_OUTPUT */
#define PXP_OUT_CTRL_ALPHA_OUTPUT(x)             (((uint32_t)(((uint32_t)(x)) << PXP_OUT_CTRL_ALPHA_OUTPUT_SHIFT)) & PXP_OUT_CTRL_ALPHA_OUTPUT_MASK)

#define PXP_OUT_CTRL_ALPHA_MASK                  (0xFF000000U)
#define PXP_OUT_CTRL_ALPHA_SHIFT                 (24U)
/*! ALPHA - ALPHA */
#define PXP_OUT_CTRL_ALPHA(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_OUT_CTRL_ALPHA_SHIFT)) & PXP_OUT_CTRL_ALPHA_MASK)
/*! @} */

/*! @name OUT_BUF - Output Frame Buffer Pointer Register */
/*! @{ */

#define PXP_OUT_BUF_ADDR_MASK                    (0xFFFFFFFFU)
#define PXP_OUT_BUF_ADDR_SHIFT                   (0U)
/*! ADDR - ADDR */
#define PXP_OUT_BUF_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_BUF_ADDR_SHIFT)) & PXP_OUT_BUF_ADDR_MASK)
/*! @} */

/*! @name OUT_BUF2 - Output Frame Buffer Pointer #2 Register */
/*! @{ */

#define PXP_OUT_BUF2_ADDR_MASK                   (0xFFFFFFFFU)
#define PXP_OUT_BUF2_ADDR_SHIFT                  (0U)
/*! ADDR - ADDR */
#define PXP_OUT_BUF2_ADDR(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_OUT_BUF2_ADDR_SHIFT)) & PXP_OUT_BUF2_ADDR_MASK)
/*! @} */

/*! @name OUT_PITCH - Output Buffer Pitch Register */
/*! @{ */

#define PXP_OUT_PITCH_PITCH_MASK                 (0xFFFFU)
#define PXP_OUT_PITCH_PITCH_SHIFT                (0U)
/*! PITCH - PITCH */
#define PXP_OUT_PITCH_PITCH(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PITCH_PITCH_SHIFT)) & PXP_OUT_PITCH_PITCH_MASK)

#define PXP_OUT_PITCH_RSVD_MASK                  (0xFFFF0000U)
#define PXP_OUT_PITCH_RSVD_SHIFT                 (16U)
/*! RSVD - RSVD */
#define PXP_OUT_PITCH_RSVD(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PITCH_RSVD_SHIFT)) & PXP_OUT_PITCH_RSVD_MASK)
/*! @} */

/*! @name OUT_LRC - Output Surface Lower Right Coordinate Register */
/*! @{ */

#define PXP_OUT_LRC_Y_MASK                       (0x3FFFU)
#define PXP_OUT_LRC_Y_SHIFT                      (0U)
/*! Y - Y */
#define PXP_OUT_LRC_Y(x)                         (((uint32_t)(((uint32_t)(x)) << PXP_OUT_LRC_Y_SHIFT)) & PXP_OUT_LRC_Y_MASK)

#define PXP_OUT_LRC_RSVD0_MASK                   (0xC000U)
#define PXP_OUT_LRC_RSVD0_SHIFT                  (14U)
/*! RSVD0 - RSVD0 */
#define PXP_OUT_LRC_RSVD0(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_OUT_LRC_RSVD0_SHIFT)) & PXP_OUT_LRC_RSVD0_MASK)

#define PXP_OUT_LRC_X_MASK                       (0x3FFF0000U)
#define PXP_OUT_LRC_X_SHIFT                      (16U)
/*! X - X */
#define PXP_OUT_LRC_X(x)                         (((uint32_t)(((uint32_t)(x)) << PXP_OUT_LRC_X_SHIFT)) & PXP_OUT_LRC_X_MASK)

#define PXP_OUT_LRC_RSVD1_MASK                   (0xC0000000U)
#define PXP_OUT_LRC_RSVD1_SHIFT                  (30U)
/*! RSVD1 - RSVD1 */
#define PXP_OUT_LRC_RSVD1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_OUT_LRC_RSVD1_SHIFT)) & PXP_OUT_LRC_RSVD1_MASK)
/*! @} */

/*! @name OUT_PS_ULC - Processed Surface Upper Left Coordinate Register */
/*! @{ */

#define PXP_OUT_PS_ULC_Y_MASK                    (0x3FFFU)
#define PXP_OUT_PS_ULC_Y_SHIFT                   (0U)
/*! Y - Y */
#define PXP_OUT_PS_ULC_Y(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_ULC_Y_SHIFT)) & PXP_OUT_PS_ULC_Y_MASK)

#define PXP_OUT_PS_ULC_RSVD0_MASK                (0xC000U)
#define PXP_OUT_PS_ULC_RSVD0_SHIFT               (14U)
/*! RSVD0 - RSVD0 */
#define PXP_OUT_PS_ULC_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_ULC_RSVD0_SHIFT)) & PXP_OUT_PS_ULC_RSVD0_MASK)

#define PXP_OUT_PS_ULC_X_MASK                    (0x3FFF0000U)
#define PXP_OUT_PS_ULC_X_SHIFT                   (16U)
/*! X - X */
#define PXP_OUT_PS_ULC_X(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_ULC_X_SHIFT)) & PXP_OUT_PS_ULC_X_MASK)

#define PXP_OUT_PS_ULC_RSVD1_MASK                (0xC0000000U)
#define PXP_OUT_PS_ULC_RSVD1_SHIFT               (30U)
/*! RSVD1 - RSVD1 */
#define PXP_OUT_PS_ULC_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_ULC_RSVD1_SHIFT)) & PXP_OUT_PS_ULC_RSVD1_MASK)
/*! @} */

/*! @name OUT_PS_LRC - Processed Surface Lower Right Coordinate Register */
/*! @{ */

#define PXP_OUT_PS_LRC_Y_MASK                    (0x3FFFU)
#define PXP_OUT_PS_LRC_Y_SHIFT                   (0U)
/*! Y - Y */
#define PXP_OUT_PS_LRC_Y(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_LRC_Y_SHIFT)) & PXP_OUT_PS_LRC_Y_MASK)

#define PXP_OUT_PS_LRC_RSVD0_MASK                (0xC000U)
#define PXP_OUT_PS_LRC_RSVD0_SHIFT               (14U)
/*! RSVD0 - RSVD0 */
#define PXP_OUT_PS_LRC_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_LRC_RSVD0_SHIFT)) & PXP_OUT_PS_LRC_RSVD0_MASK)

#define PXP_OUT_PS_LRC_X_MASK                    (0x3FFF0000U)
#define PXP_OUT_PS_LRC_X_SHIFT                   (16U)
/*! X - X */
#define PXP_OUT_PS_LRC_X(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_LRC_X_SHIFT)) & PXP_OUT_PS_LRC_X_MASK)

#define PXP_OUT_PS_LRC_RSVD1_MASK                (0xC0000000U)
#define PXP_OUT_PS_LRC_RSVD1_SHIFT               (30U)
/*! RSVD1 - RSVD1 */
#define PXP_OUT_PS_LRC_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_PS_LRC_RSVD1_SHIFT)) & PXP_OUT_PS_LRC_RSVD1_MASK)
/*! @} */

/*! @name OUT_AS_ULC - Alpha Surface Upper Left Coordinate Register */
/*! @{ */

#define PXP_OUT_AS_ULC_Y_MASK                    (0x3FFFU)
#define PXP_OUT_AS_ULC_Y_SHIFT                   (0U)
/*! Y - Y */
#define PXP_OUT_AS_ULC_Y(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_ULC_Y_SHIFT)) & PXP_OUT_AS_ULC_Y_MASK)

#define PXP_OUT_AS_ULC_RSVD0_MASK                (0xC000U)
#define PXP_OUT_AS_ULC_RSVD0_SHIFT               (14U)
/*! RSVD0 - RSVD0 */
#define PXP_OUT_AS_ULC_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_ULC_RSVD0_SHIFT)) & PXP_OUT_AS_ULC_RSVD0_MASK)

#define PXP_OUT_AS_ULC_X_MASK                    (0x3FFF0000U)
#define PXP_OUT_AS_ULC_X_SHIFT                   (16U)
/*! X - X */
#define PXP_OUT_AS_ULC_X(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_ULC_X_SHIFT)) & PXP_OUT_AS_ULC_X_MASK)

#define PXP_OUT_AS_ULC_RSVD1_MASK                (0xC0000000U)
#define PXP_OUT_AS_ULC_RSVD1_SHIFT               (30U)
/*! RSVD1 - RSVD1 */
#define PXP_OUT_AS_ULC_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_ULC_RSVD1_SHIFT)) & PXP_OUT_AS_ULC_RSVD1_MASK)
/*! @} */

/*! @name OUT_AS_LRC - Alpha Surface Lower Right Coordinate Register */
/*! @{ */

#define PXP_OUT_AS_LRC_Y_MASK                    (0x3FFFU)
#define PXP_OUT_AS_LRC_Y_SHIFT                   (0U)
/*! Y - Y */
#define PXP_OUT_AS_LRC_Y(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_LRC_Y_SHIFT)) & PXP_OUT_AS_LRC_Y_MASK)

#define PXP_OUT_AS_LRC_RSVD0_MASK                (0xC000U)
#define PXP_OUT_AS_LRC_RSVD0_SHIFT               (14U)
/*! RSVD0 - RSVD0 */
#define PXP_OUT_AS_LRC_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_LRC_RSVD0_SHIFT)) & PXP_OUT_AS_LRC_RSVD0_MASK)

#define PXP_OUT_AS_LRC_X_MASK                    (0x3FFF0000U)
#define PXP_OUT_AS_LRC_X_SHIFT                   (16U)
/*! X - X */
#define PXP_OUT_AS_LRC_X(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_LRC_X_SHIFT)) & PXP_OUT_AS_LRC_X_MASK)

#define PXP_OUT_AS_LRC_RSVD1_MASK                (0xC0000000U)
#define PXP_OUT_AS_LRC_RSVD1_SHIFT               (30U)
/*! RSVD1 - RSVD1 */
#define PXP_OUT_AS_LRC_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_OUT_AS_LRC_RSVD1_SHIFT)) & PXP_OUT_AS_LRC_RSVD1_MASK)
/*! @} */

/*! @name PS_CTRL - Processed Surface (PS) Control Register */
/*! @{ */

#define PXP_PS_CTRL_FORMAT_MASK                  (0x3FU)
#define PXP_PS_CTRL_FORMAT_SHIFT                 (0U)
/*! FORMAT - FORMAT
 *  0b000100..RGB888 : 32-bit pixels (unpacked 24-bit format)
 *  0b001100..RGB555 : 16-bit pixels
 *  0b001101..RGB444 : 16-bit pixels
 *  0b001110..RGB565 : 16-bit pixels
 *  0b010000..YUV1P444 : 32-bit pixels (1-plane XYUV unpacked)
 *  0b010010..UYVY1P422 : 16-bit pixels (1-plane U0,Y0,V0,Y1 interleaved bytes)
 *  0b010011..VYUY1P422 : 16-bit pixels (1-plane V0,Y0,U0,Y1 interleaved bytes)
 *  0b010100..Y8 : 8-bit monochrome pixels (1-plane Y luma output)
 *  0b010101..Y4 : 4-bit monochrome pixels (1-plane Y luma, 4 bit truncation)
 *  0b011000..YUV2P422 : 16-bit pixels (2-plane UV interleaved bytes)
 *  0b011001..YUV2P420 : 16-bit pixels (2-plane UV)
 *  0b011010..YVU2P422 : 16-bit pixels (2-plane VU interleaved bytes)
 *  0b011011..YVU2P420 : 16-bit pixels (2-plane VU)
 *  0b011110..YUV422 : 16-bit pixels (3-plane format)
 *  0b011111..YUV420 : 16-bit pixels (3-plane format)
 */
#define PXP_PS_CTRL_FORMAT(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_PS_CTRL_FORMAT_SHIFT)) & PXP_PS_CTRL_FORMAT_MASK)

#define PXP_PS_CTRL_WB_SWAP_MASK                 (0x40U)
#define PXP_PS_CTRL_WB_SWAP_SHIFT                (6U)
/*! WB_SWAP - WB_SWAP */
#define PXP_PS_CTRL_WB_SWAP(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_PS_CTRL_WB_SWAP_SHIFT)) & PXP_PS_CTRL_WB_SWAP_MASK)

#define PXP_PS_CTRL_RSVD0_MASK                   (0x80U)
#define PXP_PS_CTRL_RSVD0_SHIFT                  (7U)
/*! RSVD0 - RSVD0 */
#define PXP_PS_CTRL_RSVD0(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_PS_CTRL_RSVD0_SHIFT)) & PXP_PS_CTRL_RSVD0_MASK)

#define PXP_PS_CTRL_DECY_MASK                    (0x300U)
#define PXP_PS_CTRL_DECY_SHIFT                   (8U)
/*! DECY - DECY
 *  0b00..DISABLE : Disable pre-decimation filter.
 *  0b01..DECY2 : Decimate PS by 2.
 *  0b10..DECY4 : Decimate PS by 4.
 *  0b11..DECY8 : Decimate PS by 8.
 */
#define PXP_PS_CTRL_DECY(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_PS_CTRL_DECY_SHIFT)) & PXP_PS_CTRL_DECY_MASK)

#define PXP_PS_CTRL_DECX_MASK                    (0xC00U)
#define PXP_PS_CTRL_DECX_SHIFT                   (10U)
/*! DECX - DECX
 *  0b00..DISABLE : Disable pre-decimation filter.
 *  0b01..DECX2 : Decimate PS by 2.
 *  0b10..DECX4 : Decimate PS by 4.
 *  0b11..DECX8 : Decimate PS by 8.
 */
#define PXP_PS_CTRL_DECX(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_PS_CTRL_DECX_SHIFT)) & PXP_PS_CTRL_DECX_MASK)

#define PXP_PS_CTRL_RSVD1_MASK                   (0xFFFFF000U)
#define PXP_PS_CTRL_RSVD1_SHIFT                  (12U)
/*! RSVD1 - RSVD1 */
#define PXP_PS_CTRL_RSVD1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_PS_CTRL_RSVD1_SHIFT)) & PXP_PS_CTRL_RSVD1_MASK)
/*! @} */

/*! @name PS_BUF - PS Input Buffer Address Register */
/*! @{ */

#define PXP_PS_BUF_ADDR_MASK                     (0xFFFFFFFFU)
#define PXP_PS_BUF_ADDR_SHIFT                    (0U)
/*! ADDR - ADDR */
#define PXP_PS_BUF_ADDR(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_PS_BUF_ADDR_SHIFT)) & PXP_PS_BUF_ADDR_MASK)
/*! @} */

/*! @name PS_UBUF - PS U/Cb or 2 Plane UV Input Buffer Address Register */
/*! @{ */

#define PXP_PS_UBUF_ADDR_MASK                    (0xFFFFFFFFU)
#define PXP_PS_UBUF_ADDR_SHIFT                   (0U)
/*! ADDR - ADDR */
#define PXP_PS_UBUF_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_PS_UBUF_ADDR_SHIFT)) & PXP_PS_UBUF_ADDR_MASK)
/*! @} */

/*! @name PS_VBUF - PS V/Cr Input Buffer Address Register */
/*! @{ */

#define PXP_PS_VBUF_ADDR_MASK                    (0xFFFFFFFFU)
#define PXP_PS_VBUF_ADDR_SHIFT                   (0U)
/*! ADDR - ADDR */
#define PXP_PS_VBUF_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_PS_VBUF_ADDR_SHIFT)) & PXP_PS_VBUF_ADDR_MASK)
/*! @} */

/*! @name PS_PITCH - Processed Surface Pitch Register */
/*! @{ */

#define PXP_PS_PITCH_PITCH_MASK                  (0xFFFFU)
#define PXP_PS_PITCH_PITCH_SHIFT                 (0U)
/*! PITCH - PITCH */
#define PXP_PS_PITCH_PITCH(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_PS_PITCH_PITCH_SHIFT)) & PXP_PS_PITCH_PITCH_MASK)

#define PXP_PS_PITCH_RSVD_MASK                   (0xFFFF0000U)
#define PXP_PS_PITCH_RSVD_SHIFT                  (16U)
/*! RSVD - RSVD */
#define PXP_PS_PITCH_RSVD(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_PS_PITCH_RSVD_SHIFT)) & PXP_PS_PITCH_RSVD_MASK)
/*! @} */

/*! @name PS_BACKGROUND_0 - PS Background Color Register */
/*! @{ */

#define PXP_PS_BACKGROUND_0_COLOR_MASK           (0xFFFFFFU)
#define PXP_PS_BACKGROUND_0_COLOR_SHIFT          (0U)
/*! COLOR - COLOR */
#define PXP_PS_BACKGROUND_0_COLOR(x)             (((uint32_t)(((uint32_t)(x)) << PXP_PS_BACKGROUND_0_COLOR_SHIFT)) & PXP_PS_BACKGROUND_0_COLOR_MASK)

#define PXP_PS_BACKGROUND_0_RSVD_MASK            (0xFF000000U)
#define PXP_PS_BACKGROUND_0_RSVD_SHIFT           (24U)
/*! RSVD - RSVD */
#define PXP_PS_BACKGROUND_0_RSVD(x)              (((uint32_t)(((uint32_t)(x)) << PXP_PS_BACKGROUND_0_RSVD_SHIFT)) & PXP_PS_BACKGROUND_0_RSVD_MASK)
/*! @} */

/*! @name PS_SCALE - PS Scale Factor Register */
/*! @{ */

#define PXP_PS_SCALE_XSCALE_MASK                 (0x7FFFU)
#define PXP_PS_SCALE_XSCALE_SHIFT                (0U)
/*! XSCALE - XSCALE */
#define PXP_PS_SCALE_XSCALE(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_PS_SCALE_XSCALE_SHIFT)) & PXP_PS_SCALE_XSCALE_MASK)

#define PXP_PS_SCALE_RSVD1_MASK                  (0x8000U)
#define PXP_PS_SCALE_RSVD1_SHIFT                 (15U)
/*! RSVD1 - RSVD1 */
#define PXP_PS_SCALE_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_PS_SCALE_RSVD1_SHIFT)) & PXP_PS_SCALE_RSVD1_MASK)

#define PXP_PS_SCALE_YSCALE_MASK                 (0x7FFF0000U)
#define PXP_PS_SCALE_YSCALE_SHIFT                (16U)
/*! YSCALE - YSCALE */
#define PXP_PS_SCALE_YSCALE(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_PS_SCALE_YSCALE_SHIFT)) & PXP_PS_SCALE_YSCALE_MASK)

#define PXP_PS_SCALE_RSVD2_MASK                  (0x80000000U)
#define PXP_PS_SCALE_RSVD2_SHIFT                 (31U)
/*! RSVD2 - RSVD2 */
#define PXP_PS_SCALE_RSVD2(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_PS_SCALE_RSVD2_SHIFT)) & PXP_PS_SCALE_RSVD2_MASK)
/*! @} */

/*! @name PS_OFFSET - PS Scale Offset Register */
/*! @{ */

#define PXP_PS_OFFSET_XOFFSET_MASK               (0xFFFU)
#define PXP_PS_OFFSET_XOFFSET_SHIFT              (0U)
/*! XOFFSET - XOFFSET */
#define PXP_PS_OFFSET_XOFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << PXP_PS_OFFSET_XOFFSET_SHIFT)) & PXP_PS_OFFSET_XOFFSET_MASK)

#define PXP_PS_OFFSET_RSVD1_MASK                 (0xF000U)
#define PXP_PS_OFFSET_RSVD1_SHIFT                (12U)
/*! RSVD1 - RSVD1 */
#define PXP_PS_OFFSET_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_PS_OFFSET_RSVD1_SHIFT)) & PXP_PS_OFFSET_RSVD1_MASK)

#define PXP_PS_OFFSET_YOFFSET_MASK               (0xFFF0000U)
#define PXP_PS_OFFSET_YOFFSET_SHIFT              (16U)
/*! YOFFSET - YOFFSET */
#define PXP_PS_OFFSET_YOFFSET(x)                 (((uint32_t)(((uint32_t)(x)) << PXP_PS_OFFSET_YOFFSET_SHIFT)) & PXP_PS_OFFSET_YOFFSET_MASK)

#define PXP_PS_OFFSET_RSVD2_MASK                 (0xF0000000U)
#define PXP_PS_OFFSET_RSVD2_SHIFT                (28U)
/*! RSVD2 - RSVD2 */
#define PXP_PS_OFFSET_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_PS_OFFSET_RSVD2_SHIFT)) & PXP_PS_OFFSET_RSVD2_MASK)
/*! @} */

/*! @name PS_CLRKEYLOW_0 - PS Color Key Low Register */
/*! @{ */

#define PXP_PS_CLRKEYLOW_0_PIXEL_MASK            (0xFFFFFFU)
#define PXP_PS_CLRKEYLOW_0_PIXEL_SHIFT           (0U)
/*! PIXEL - PIXEL */
#define PXP_PS_CLRKEYLOW_0_PIXEL(x)              (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYLOW_0_PIXEL_SHIFT)) & PXP_PS_CLRKEYLOW_0_PIXEL_MASK)

#define PXP_PS_CLRKEYLOW_0_RSVD1_MASK            (0xFF000000U)
#define PXP_PS_CLRKEYLOW_0_RSVD1_SHIFT           (24U)
/*! RSVD1 - RSVD1 */
#define PXP_PS_CLRKEYLOW_0_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYLOW_0_RSVD1_SHIFT)) & PXP_PS_CLRKEYLOW_0_RSVD1_MASK)
/*! @} */

/*! @name PS_CLRKEYHIGH_0 - PS Color Key High Register */
/*! @{ */

#define PXP_PS_CLRKEYHIGH_0_PIXEL_MASK           (0xFFFFFFU)
#define PXP_PS_CLRKEYHIGH_0_PIXEL_SHIFT          (0U)
/*! PIXEL - PIXEL */
#define PXP_PS_CLRKEYHIGH_0_PIXEL(x)             (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYHIGH_0_PIXEL_SHIFT)) & PXP_PS_CLRKEYHIGH_0_PIXEL_MASK)

#define PXP_PS_CLRKEYHIGH_0_RSVD1_MASK           (0xFF000000U)
#define PXP_PS_CLRKEYHIGH_0_RSVD1_SHIFT          (24U)
/*! RSVD1 - RSVD1 */
#define PXP_PS_CLRKEYHIGH_0_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYHIGH_0_RSVD1_SHIFT)) & PXP_PS_CLRKEYHIGH_0_RSVD1_MASK)
/*! @} */

/*! @name AS_CTRL - Alpha Surface Control Register */
/*! @{ */

#define PXP_AS_CTRL_RSVD0_MASK                   (0x1U)
#define PXP_AS_CTRL_RSVD0_SHIFT                  (0U)
/*! RSVD0 - RSVD0 */
#define PXP_AS_CTRL_RSVD0(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_RSVD0_SHIFT)) & PXP_AS_CTRL_RSVD0_MASK)

#define PXP_AS_CTRL_ALPHA_CTRL_MASK              (0x6U)
#define PXP_AS_CTRL_ALPHA_CTRL_SHIFT             (1U)
/*! ALPHA_CTRL - ALPHA_CTRL
 *  0b00..Embedded : Indicates that the AS pixel alpha value will be used to blend the AS with PS. The ALPHA field is ignored.
 *  0b01..Override : Indicates that the value in the ALPHA field should be used instead of the alpha values present in the input pixels.
 *  0b10..Multiply : Indicates that the value in the ALPHA field should be used to scale all pixel alpha values.
 *        Each pixel alpha is multiplied by the value in the ALPHA field.
 *  0b11..ROPs : Enable ROPs. The ROP field indicates an operation to be performed on the alpha surface and PS pixels.
 */
#define PXP_AS_CTRL_ALPHA_CTRL(x)                (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_ALPHA_CTRL_SHIFT)) & PXP_AS_CTRL_ALPHA_CTRL_MASK)

#define PXP_AS_CTRL_ENABLE_COLORKEY_MASK         (0x8U)
#define PXP_AS_CTRL_ENABLE_COLORKEY_SHIFT        (3U)
/*! ENABLE_COLORKEY - ENABLE_COLORKEY */
#define PXP_AS_CTRL_ENABLE_COLORKEY(x)           (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_ENABLE_COLORKEY_SHIFT)) & PXP_AS_CTRL_ENABLE_COLORKEY_MASK)

#define PXP_AS_CTRL_FORMAT_MASK                  (0xF0U)
#define PXP_AS_CTRL_FORMAT_SHIFT                 (4U)
/*! FORMAT - FORMAT
 *  0b0000..ARGB8888 : 32-bit pixels with alpha
 *  0b0001..RGBA8888 : 32-bit pixels with alpha
 *  0b0100..RGB888 : 32-bit pixels without alpha (unpacked 24-bit format)
 *  0b1000..ARGB1555 : 16-bit pixels with alpha
 *  0b1001..ARGB4444 : 16-bit pixels with alpha
 *  0b1100..RGB555 : 16-bit pixels without alpha
 *  0b1101..RGB444 : 16-bit pixels without alpha
 *  0b1110..RGB565 : 16-bit pixels without alpha
 */
#define PXP_AS_CTRL_FORMAT(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_FORMAT_SHIFT)) & PXP_AS_CTRL_FORMAT_MASK)

#define PXP_AS_CTRL_ALPHA_MASK                   (0xFF00U)
#define PXP_AS_CTRL_ALPHA_SHIFT                  (8U)
/*! ALPHA - ALPHA */
#define PXP_AS_CTRL_ALPHA(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_ALPHA_SHIFT)) & PXP_AS_CTRL_ALPHA_MASK)

#define PXP_AS_CTRL_ROP_MASK                     (0xF0000U)
#define PXP_AS_CTRL_ROP_SHIFT                    (16U)
/*! ROP - ROP
 *  0b0000..MASKAS : AS AND PS
 *  0b0001..MASKNOTAS : nAS AND PS
 *  0b0010..MASKASNOT : AS AND nPS
 *  0b0011..MERGEAS : AS OR PS
 *  0b0100..MERGENOTAS : nAS OR PS
 *  0b0101..MERGEASNOT : AS OR nPS
 *  0b0110..NOTCOPYAS : nAS
 *  0b0111..NOT : nPS
 *  0b1000..NOTMASKAS : AS NAND PS
 *  0b1001..NOTMERGEAS : AS NOR PS
 *  0b1010..XORAS : AS XOR PS
 *  0b1011..NOTXORAS : AS XNOR PS
 */
#define PXP_AS_CTRL_ROP(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_ROP_SHIFT)) & PXP_AS_CTRL_ROP_MASK)

#define PXP_AS_CTRL_ALPHA0_INVERT_MASK           (0x100000U)
#define PXP_AS_CTRL_ALPHA0_INVERT_SHIFT          (20U)
/*! ALPHA0_INVERT - ALPHA0_INVERT */
#define PXP_AS_CTRL_ALPHA0_INVERT(x)             (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_ALPHA0_INVERT_SHIFT)) & PXP_AS_CTRL_ALPHA0_INVERT_MASK)

#define PXP_AS_CTRL_ALPHA1_INVERT_MASK           (0x200000U)
#define PXP_AS_CTRL_ALPHA1_INVERT_SHIFT          (21U)
/*! ALPHA1_INVERT - ALPHA1_INVERT */
#define PXP_AS_CTRL_ALPHA1_INVERT(x)             (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_ALPHA1_INVERT_SHIFT)) & PXP_AS_CTRL_ALPHA1_INVERT_MASK)

#define PXP_AS_CTRL_RSVD1_MASK                   (0xFFC00000U)
#define PXP_AS_CTRL_RSVD1_SHIFT                  (22U)
/*! RSVD1 - RSVD1 */
#define PXP_AS_CTRL_RSVD1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_AS_CTRL_RSVD1_SHIFT)) & PXP_AS_CTRL_RSVD1_MASK)
/*! @} */

/*! @name AS_BUF - Alpha Surface Buffer Pointer Register */
/*! @{ */

#define PXP_AS_BUF_ADDR_MASK                     (0xFFFFFFFFU)
#define PXP_AS_BUF_ADDR_SHIFT                    (0U)
/*! ADDR - ADDR */
#define PXP_AS_BUF_ADDR(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_AS_BUF_ADDR_SHIFT)) & PXP_AS_BUF_ADDR_MASK)
/*! @} */

/*! @name AS_PITCH - Alpha Surface Pitch Register */
/*! @{ */

#define PXP_AS_PITCH_PITCH_MASK                  (0xFFFFU)
#define PXP_AS_PITCH_PITCH_SHIFT                 (0U)
/*! PITCH - PITCH */
#define PXP_AS_PITCH_PITCH(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_AS_PITCH_PITCH_SHIFT)) & PXP_AS_PITCH_PITCH_MASK)

#define PXP_AS_PITCH_RSVD_MASK                   (0xFFFF0000U)
#define PXP_AS_PITCH_RSVD_SHIFT                  (16U)
/*! RSVD - RSVD */
#define PXP_AS_PITCH_RSVD(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_AS_PITCH_RSVD_SHIFT)) & PXP_AS_PITCH_RSVD_MASK)
/*! @} */

/*! @name AS_CLRKEYLOW_0 - Overlay Color Key Low Register */
/*! @{ */

#define PXP_AS_CLRKEYLOW_0_PIXEL_MASK            (0xFFFFFFU)
#define PXP_AS_CLRKEYLOW_0_PIXEL_SHIFT           (0U)
/*! PIXEL - PIXEL */
#define PXP_AS_CLRKEYLOW_0_PIXEL(x)              (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYLOW_0_PIXEL_SHIFT)) & PXP_AS_CLRKEYLOW_0_PIXEL_MASK)

#define PXP_AS_CLRKEYLOW_0_RSVD1_MASK            (0xFF000000U)
#define PXP_AS_CLRKEYLOW_0_RSVD1_SHIFT           (24U)
/*! RSVD1 - RSVD1 */
#define PXP_AS_CLRKEYLOW_0_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYLOW_0_RSVD1_SHIFT)) & PXP_AS_CLRKEYLOW_0_RSVD1_MASK)
/*! @} */

/*! @name AS_CLRKEYHIGH_0 - Overlay Color Key High Register */
/*! @{ */

#define PXP_AS_CLRKEYHIGH_0_PIXEL_MASK           (0xFFFFFFU)
#define PXP_AS_CLRKEYHIGH_0_PIXEL_SHIFT          (0U)
/*! PIXEL - PIXEL */
#define PXP_AS_CLRKEYHIGH_0_PIXEL(x)             (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYHIGH_0_PIXEL_SHIFT)) & PXP_AS_CLRKEYHIGH_0_PIXEL_MASK)

#define PXP_AS_CLRKEYHIGH_0_RSVD1_MASK           (0xFF000000U)
#define PXP_AS_CLRKEYHIGH_0_RSVD1_SHIFT          (24U)
/*! RSVD1 - RSVD1 */
#define PXP_AS_CLRKEYHIGH_0_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYHIGH_0_RSVD1_SHIFT)) & PXP_AS_CLRKEYHIGH_0_RSVD1_MASK)
/*! @} */

/*! @name CSC1_COEF0 - Color Space Conversion 1 Coefficient 0 Register */
/*! @{ */

#define PXP_CSC1_COEF0_Y_OFFSET_MASK             (0x1FFU)
#define PXP_CSC1_COEF0_Y_OFFSET_SHIFT            (0U)
/*! Y_OFFSET - Y_OFFSET */
#define PXP_CSC1_COEF0_Y_OFFSET(x)               (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF0_Y_OFFSET_SHIFT)) & PXP_CSC1_COEF0_Y_OFFSET_MASK)

#define PXP_CSC1_COEF0_UV_OFFSET_MASK            (0x3FE00U)
#define PXP_CSC1_COEF0_UV_OFFSET_SHIFT           (9U)
/*! UV_OFFSET - UV_OFFSET */
#define PXP_CSC1_COEF0_UV_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF0_UV_OFFSET_SHIFT)) & PXP_CSC1_COEF0_UV_OFFSET_MASK)

#define PXP_CSC1_COEF0_C0_MASK                   (0x1FFC0000U)
#define PXP_CSC1_COEF0_C0_SHIFT                  (18U)
/*! C0 - C0 */
#define PXP_CSC1_COEF0_C0(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF0_C0_SHIFT)) & PXP_CSC1_COEF0_C0_MASK)

#define PXP_CSC1_COEF0_RSVD1_MASK                (0x20000000U)
#define PXP_CSC1_COEF0_RSVD1_SHIFT               (29U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC1_COEF0_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF0_RSVD1_SHIFT)) & PXP_CSC1_COEF0_RSVD1_MASK)

#define PXP_CSC1_COEF0_BYPASS_MASK               (0x40000000U)
#define PXP_CSC1_COEF0_BYPASS_SHIFT              (30U)
/*! BYPASS - BYPASS */
#define PXP_CSC1_COEF0_BYPASS(x)                 (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF0_BYPASS_SHIFT)) & PXP_CSC1_COEF0_BYPASS_MASK)

#define PXP_CSC1_COEF0_YCBCR_MODE_MASK           (0x80000000U)
#define PXP_CSC1_COEF0_YCBCR_MODE_SHIFT          (31U)
/*! YCBCR_MODE - YCBCR_MODE */
#define PXP_CSC1_COEF0_YCBCR_MODE(x)             (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF0_YCBCR_MODE_SHIFT)) & PXP_CSC1_COEF0_YCBCR_MODE_MASK)
/*! @} */

/*! @name CSC1_COEF1 - Color Space Conversion 1 Coefficient 1 Register */
/*! @{ */

#define PXP_CSC1_COEF1_C4_MASK                   (0x7FFU)
#define PXP_CSC1_COEF1_C4_SHIFT                  (0U)
/*! C4 - C4 */
#define PXP_CSC1_COEF1_C4(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF1_C4_SHIFT)) & PXP_CSC1_COEF1_C4_MASK)

#define PXP_CSC1_COEF1_RSVD0_MASK                (0xF800U)
#define PXP_CSC1_COEF1_RSVD0_SHIFT               (11U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC1_COEF1_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF1_RSVD0_SHIFT)) & PXP_CSC1_COEF1_RSVD0_MASK)

#define PXP_CSC1_COEF1_C1_MASK                   (0x7FF0000U)
#define PXP_CSC1_COEF1_C1_SHIFT                  (16U)
/*! C1 - C1 */
#define PXP_CSC1_COEF1_C1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF1_C1_SHIFT)) & PXP_CSC1_COEF1_C1_MASK)

#define PXP_CSC1_COEF1_RSVD1_MASK                (0xF8000000U)
#define PXP_CSC1_COEF1_RSVD1_SHIFT               (27U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC1_COEF1_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF1_RSVD1_SHIFT)) & PXP_CSC1_COEF1_RSVD1_MASK)
/*! @} */

/*! @name CSC1_COEF2 - Color Space Conversion 1 Coefficient 2 Register */
/*! @{ */

#define PXP_CSC1_COEF2_C3_MASK                   (0x7FFU)
#define PXP_CSC1_COEF2_C3_SHIFT                  (0U)
/*! C3 - C3 */
#define PXP_CSC1_COEF2_C3(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF2_C3_SHIFT)) & PXP_CSC1_COEF2_C3_MASK)

#define PXP_CSC1_COEF2_RSVD0_MASK                (0xF800U)
#define PXP_CSC1_COEF2_RSVD0_SHIFT               (11U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC1_COEF2_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF2_RSVD0_SHIFT)) & PXP_CSC1_COEF2_RSVD0_MASK)

#define PXP_CSC1_COEF2_C2_MASK                   (0x7FF0000U)
#define PXP_CSC1_COEF2_C2_SHIFT                  (16U)
/*! C2 - C2 */
#define PXP_CSC1_COEF2_C2(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF2_C2_SHIFT)) & PXP_CSC1_COEF2_C2_MASK)

#define PXP_CSC1_COEF2_RSVD1_MASK                (0xF8000000U)
#define PXP_CSC1_COEF2_RSVD1_SHIFT               (27U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC1_COEF2_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC1_COEF2_RSVD1_SHIFT)) & PXP_CSC1_COEF2_RSVD1_MASK)
/*! @} */

/*! @name CSC2_CTRL - Color Space Conversion 2 Control Register */
/*! @{ */

#define PXP_CSC2_CTRL_BYPASS_MASK                (0x1U)
#define PXP_CSC2_CTRL_BYPASS_SHIFT               (0U)
/*! BYPASS - BYPASS */
#define PXP_CSC2_CTRL_BYPASS(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_CTRL_BYPASS_SHIFT)) & PXP_CSC2_CTRL_BYPASS_MASK)

#define PXP_CSC2_CTRL_CSC_MODE_MASK              (0x6U)
#define PXP_CSC2_CTRL_CSC_MODE_SHIFT             (1U)
/*! CSC_MODE - CSC_MODE
 *  0b00..YUV2RGB : Convert from YUV to RGB.
 *  0b01..YCbCr2RGB : Convert from YCbCr to RGB.
 *  0b10..RGB2YUV : Convert from RGB to YUV.
 *  0b11..RGB2YCbCr : Convert from RGB to YCbCr.
 */
#define PXP_CSC2_CTRL_CSC_MODE(x)                (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_CTRL_CSC_MODE_SHIFT)) & PXP_CSC2_CTRL_CSC_MODE_MASK)

#define PXP_CSC2_CTRL_RSVD_MASK                  (0xFFFFFFF8U)
#define PXP_CSC2_CTRL_RSVD_SHIFT                 (3U)
/*! RSVD - RSVD */
#define PXP_CSC2_CTRL_RSVD(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_CTRL_RSVD_SHIFT)) & PXP_CSC2_CTRL_RSVD_MASK)
/*! @} */

/*! @name CSC2_COEF0 - Color Space Conversion 2 Coefficient 0 Register */
/*! @{ */

#define PXP_CSC2_COEF0_A1_MASK                   (0x7FFU)
#define PXP_CSC2_COEF0_A1_SHIFT                  (0U)
/*! A1 - A1 */
#define PXP_CSC2_COEF0_A1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF0_A1_SHIFT)) & PXP_CSC2_COEF0_A1_MASK)

#define PXP_CSC2_COEF0_RSVD0_MASK                (0xF800U)
#define PXP_CSC2_COEF0_RSVD0_SHIFT               (11U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC2_COEF0_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF0_RSVD0_SHIFT)) & PXP_CSC2_COEF0_RSVD0_MASK)

#define PXP_CSC2_COEF0_A2_MASK                   (0x7FF0000U)
#define PXP_CSC2_COEF0_A2_SHIFT                  (16U)
/*! A2 - A2 */
#define PXP_CSC2_COEF0_A2(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF0_A2_SHIFT)) & PXP_CSC2_COEF0_A2_MASK)

#define PXP_CSC2_COEF0_RSVD1_MASK                (0xF8000000U)
#define PXP_CSC2_COEF0_RSVD1_SHIFT               (27U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC2_COEF0_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF0_RSVD1_SHIFT)) & PXP_CSC2_COEF0_RSVD1_MASK)
/*! @} */

/*! @name CSC2_COEF1 - Color Space Conversion 2 Coefficient 1 Register */
/*! @{ */

#define PXP_CSC2_COEF1_A3_MASK                   (0x7FFU)
#define PXP_CSC2_COEF1_A3_SHIFT                  (0U)
/*! A3 - A3 */
#define PXP_CSC2_COEF1_A3(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF1_A3_SHIFT)) & PXP_CSC2_COEF1_A3_MASK)

#define PXP_CSC2_COEF1_RSVD0_MASK                (0xF800U)
#define PXP_CSC2_COEF1_RSVD0_SHIFT               (11U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC2_COEF1_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF1_RSVD0_SHIFT)) & PXP_CSC2_COEF1_RSVD0_MASK)

#define PXP_CSC2_COEF1_B1_MASK                   (0x7FF0000U)
#define PXP_CSC2_COEF1_B1_SHIFT                  (16U)
/*! B1 - B1 */
#define PXP_CSC2_COEF1_B1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF1_B1_SHIFT)) & PXP_CSC2_COEF1_B1_MASK)

#define PXP_CSC2_COEF1_RSVD1_MASK                (0xF8000000U)
#define PXP_CSC2_COEF1_RSVD1_SHIFT               (27U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC2_COEF1_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF1_RSVD1_SHIFT)) & PXP_CSC2_COEF1_RSVD1_MASK)
/*! @} */

/*! @name CSC2_COEF2 - Color Space Conversion 2 Coefficient 2 Register */
/*! @{ */

#define PXP_CSC2_COEF2_B2_MASK                   (0x7FFU)
#define PXP_CSC2_COEF2_B2_SHIFT                  (0U)
/*! B2 - B2 */
#define PXP_CSC2_COEF2_B2(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF2_B2_SHIFT)) & PXP_CSC2_COEF2_B2_MASK)

#define PXP_CSC2_COEF2_RSVD0_MASK                (0xF800U)
#define PXP_CSC2_COEF2_RSVD0_SHIFT               (11U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC2_COEF2_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF2_RSVD0_SHIFT)) & PXP_CSC2_COEF2_RSVD0_MASK)

#define PXP_CSC2_COEF2_B3_MASK                   (0x7FF0000U)
#define PXP_CSC2_COEF2_B3_SHIFT                  (16U)
/*! B3 - B3 */
#define PXP_CSC2_COEF2_B3(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF2_B3_SHIFT)) & PXP_CSC2_COEF2_B3_MASK)

#define PXP_CSC2_COEF2_RSVD1_MASK                (0xF8000000U)
#define PXP_CSC2_COEF2_RSVD1_SHIFT               (27U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC2_COEF2_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF2_RSVD1_SHIFT)) & PXP_CSC2_COEF2_RSVD1_MASK)
/*! @} */

/*! @name CSC2_COEF3 - Color Space Conversion 2 Coefficient 3 Register */
/*! @{ */

#define PXP_CSC2_COEF3_C1_MASK                   (0x7FFU)
#define PXP_CSC2_COEF3_C1_SHIFT                  (0U)
/*! C1 - C1 */
#define PXP_CSC2_COEF3_C1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF3_C1_SHIFT)) & PXP_CSC2_COEF3_C1_MASK)

#define PXP_CSC2_COEF3_RSVD0_MASK                (0xF800U)
#define PXP_CSC2_COEF3_RSVD0_SHIFT               (11U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC2_COEF3_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF3_RSVD0_SHIFT)) & PXP_CSC2_COEF3_RSVD0_MASK)

#define PXP_CSC2_COEF3_C2_MASK                   (0x7FF0000U)
#define PXP_CSC2_COEF3_C2_SHIFT                  (16U)
/*! C2 - C2 */
#define PXP_CSC2_COEF3_C2(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF3_C2_SHIFT)) & PXP_CSC2_COEF3_C2_MASK)

#define PXP_CSC2_COEF3_RSVD1_MASK                (0xF8000000U)
#define PXP_CSC2_COEF3_RSVD1_SHIFT               (27U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC2_COEF3_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF3_RSVD1_SHIFT)) & PXP_CSC2_COEF3_RSVD1_MASK)
/*! @} */

/*! @name CSC2_COEF4 - Color Space Conversion 2 Coefficient 4 Register */
/*! @{ */

#define PXP_CSC2_COEF4_C3_MASK                   (0x7FFU)
#define PXP_CSC2_COEF4_C3_SHIFT                  (0U)
/*! C3 - C3 */
#define PXP_CSC2_COEF4_C3(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF4_C3_SHIFT)) & PXP_CSC2_COEF4_C3_MASK)

#define PXP_CSC2_COEF4_RSVD0_MASK                (0xF800U)
#define PXP_CSC2_COEF4_RSVD0_SHIFT               (11U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC2_COEF4_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF4_RSVD0_SHIFT)) & PXP_CSC2_COEF4_RSVD0_MASK)

#define PXP_CSC2_COEF4_D1_MASK                   (0x1FF0000U)
#define PXP_CSC2_COEF4_D1_SHIFT                  (16U)
/*! D1 - D1 */
#define PXP_CSC2_COEF4_D1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF4_D1_SHIFT)) & PXP_CSC2_COEF4_D1_MASK)

#define PXP_CSC2_COEF4_RSVD1_MASK                (0xFE000000U)
#define PXP_CSC2_COEF4_RSVD1_SHIFT               (25U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC2_COEF4_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF4_RSVD1_SHIFT)) & PXP_CSC2_COEF4_RSVD1_MASK)
/*! @} */

/*! @name CSC2_COEF5 - Color Space Conversion 2 Coefficient 5 Register */
/*! @{ */

#define PXP_CSC2_COEF5_D2_MASK                   (0x1FFU)
#define PXP_CSC2_COEF5_D2_SHIFT                  (0U)
/*! D2 - D2 */
#define PXP_CSC2_COEF5_D2(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF5_D2_SHIFT)) & PXP_CSC2_COEF5_D2_MASK)

#define PXP_CSC2_COEF5_RSVD0_MASK                (0xFE00U)
#define PXP_CSC2_COEF5_RSVD0_SHIFT               (9U)
/*! RSVD0 - RSVD0 */
#define PXP_CSC2_COEF5_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF5_RSVD0_SHIFT)) & PXP_CSC2_COEF5_RSVD0_MASK)

#define PXP_CSC2_COEF5_D3_MASK                   (0x1FF0000U)
#define PXP_CSC2_COEF5_D3_SHIFT                  (16U)
/*! D3 - D3 */
#define PXP_CSC2_COEF5_D3(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF5_D3_SHIFT)) & PXP_CSC2_COEF5_D3_MASK)

#define PXP_CSC2_COEF5_RSVD1_MASK                (0xFE000000U)
#define PXP_CSC2_COEF5_RSVD1_SHIFT               (25U)
/*! RSVD1 - RSVD1 */
#define PXP_CSC2_COEF5_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CSC2_COEF5_RSVD1_SHIFT)) & PXP_CSC2_COEF5_RSVD1_MASK)
/*! @} */

/*! @name ALPHA_A_CTRL - Alpha Engine A Control Register */
/*! @{ */

#define PXP_ALPHA_A_CTRL_PORTER_DUFF_ENABLE_MASK (0x1U)
#define PXP_ALPHA_A_CTRL_PORTER_DUFF_ENABLE_SHIFT (0U)
/*! PORTER_DUFF_ENABLE - PORTER_DUFF_ENABLE
 *  0b0..porter duff disable.
 *  0b1..porter duff enable.
 */
#define PXP_ALPHA_A_CTRL_PORTER_DUFF_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_PORTER_DUFF_ENABLE_SHIFT)) & PXP_ALPHA_A_CTRL_PORTER_DUFF_ENABLE_MASK)

#define PXP_ALPHA_A_CTRL_S0_S1_FACTOR_MODE_MASK  (0x6U)
#define PXP_ALPHA_A_CTRL_S0_S1_FACTOR_MODE_SHIFT (1U)
/*! S0_S1_FACTOR_MODE - S0_S1_FACTOR_MODE
 *  0b00..using 1.
 *  0b01..using 0.
 *  0b10..using straight alpha.
 *  0b11..using inverse alpha.
 */
#define PXP_ALPHA_A_CTRL_S0_S1_FACTOR_MODE(x)    (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S0_S1_FACTOR_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S0_S1_FACTOR_MODE_MASK)

#define PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_MODE_MASK (0x18U)
#define PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_MODE_SHIFT (3U)
/*! S0_GLOBAL_ALPHA_MODE - S0_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha.
 *  0b01..using local alpha.
 *  0b10..using scaled alpha.
 *  0b11..using scaled alpha.
 */
#define PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_MODE_MASK)

#define PXP_ALPHA_A_CTRL_S0_ALPHA_MODE_MASK      (0x20U)
#define PXP_ALPHA_A_CTRL_S0_ALPHA_MODE_SHIFT     (5U)
/*! S0_ALPHA_MODE - S0_ALPHA_MODE
 *  0b0..straight mode for s0 alpha
 *  0b1..inversed mode for s0 alpha
 */
#define PXP_ALPHA_A_CTRL_S0_ALPHA_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S0_ALPHA_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S0_ALPHA_MODE_MASK)

#define PXP_ALPHA_A_CTRL_S0_COLOR_MODE_MASK      (0x40U)
#define PXP_ALPHA_A_CTRL_S0_COLOR_MODE_SHIFT     (6U)
/*! S0_COLOR_MODE - S0_COLOR_MODE
 *  0b0..straight mode for s0 color
 *  0b1..multiply mode for s0 color
 */
#define PXP_ALPHA_A_CTRL_S0_COLOR_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S0_COLOR_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S0_COLOR_MODE_MASK)

#define PXP_ALPHA_A_CTRL_RSVD1_MASK              (0x80U)
#define PXP_ALPHA_A_CTRL_RSVD1_SHIFT             (7U)
/*! RSVD1 - RSVD1 */
#define PXP_ALPHA_A_CTRL_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_RSVD1_SHIFT)) & PXP_ALPHA_A_CTRL_RSVD1_MASK)

#define PXP_ALPHA_A_CTRL_S1_S0_FACTOR_MODE_MASK  (0x300U)
#define PXP_ALPHA_A_CTRL_S1_S0_FACTOR_MODE_SHIFT (8U)
/*! S1_S0_FACTOR_MODE - S1_S0_FACTOR_MODE
 *  0b00..using 1.
 *  0b01..using 0.
 *  0b10..using straight alpha.
 *  0b11..using inverse alpha.
 */
#define PXP_ALPHA_A_CTRL_S1_S0_FACTOR_MODE(x)    (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S1_S0_FACTOR_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S1_S0_FACTOR_MODE_MASK)

#define PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_MODE_MASK (0xC00U)
#define PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_MODE_SHIFT (10U)
/*! S1_GLOBAL_ALPHA_MODE - S1_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha.
 *  0b01..using local alpha.
 *  0b10..using scaled alpha.
 *  0b11..using scaled alpha.
 */
#define PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_MODE_MASK)

#define PXP_ALPHA_A_CTRL_S1_ALPHA_MODE_MASK      (0x1000U)
#define PXP_ALPHA_A_CTRL_S1_ALPHA_MODE_SHIFT     (12U)
/*! S1_ALPHA_MODE - S1_ALPHA_MODE
 *  0b0..straight mode for s1 alpha
 *  0b1..inversed mode for s1 alpha
 */
#define PXP_ALPHA_A_CTRL_S1_ALPHA_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S1_ALPHA_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S1_ALPHA_MODE_MASK)

#define PXP_ALPHA_A_CTRL_S1_COLOR_MODE_MASK      (0x2000U)
#define PXP_ALPHA_A_CTRL_S1_COLOR_MODE_SHIFT     (13U)
/*! S1_COLOR_MODE - S1_COLOR_MODE
 *  0b0..straight mode for s1 color
 *  0b1..multiply mode for s1 color
 */
#define PXP_ALPHA_A_CTRL_S1_COLOR_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S1_COLOR_MODE_SHIFT)) & PXP_ALPHA_A_CTRL_S1_COLOR_MODE_MASK)

#define PXP_ALPHA_A_CTRL_RSVD0_MASK              (0xC000U)
#define PXP_ALPHA_A_CTRL_RSVD0_SHIFT             (14U)
/*! RSVD0 - RSVD0 */
#define PXP_ALPHA_A_CTRL_RSVD0(x)                (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_RSVD0_SHIFT)) & PXP_ALPHA_A_CTRL_RSVD0_MASK)

#define PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_MASK    (0xFF0000U)
#define PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_SHIFT   (16U)
/*! S0_GLOBAL_ALPHA - S0_GLOBAL_ALPHA */
#define PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_SHIFT)) & PXP_ALPHA_A_CTRL_S0_GLOBAL_ALPHA_MASK)

#define PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_MASK    (0xFF000000U)
#define PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_SHIFT   (24U)
/*! S1_GLOBAL_ALPHA - S1_GLOBAL_ALPHA */
#define PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_SHIFT)) & PXP_ALPHA_A_CTRL_S1_GLOBAL_ALPHA_MASK)
/*! @} */

/*! @name ALPHA_B_CTRL - Alpha Engine B Control Register */
/*! @{ */

#define PXP_ALPHA_B_CTRL_PORTER_DUFF_ENABLE_MASK (0x1U)
#define PXP_ALPHA_B_CTRL_PORTER_DUFF_ENABLE_SHIFT (0U)
/*! PORTER_DUFF_ENABLE - PORTER_DUFF_ENABLE
 *  0b0..porter duff disable.
 *  0b1..porter duff enable.
 */
#define PXP_ALPHA_B_CTRL_PORTER_DUFF_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_PORTER_DUFF_ENABLE_SHIFT)) & PXP_ALPHA_B_CTRL_PORTER_DUFF_ENABLE_MASK)

#define PXP_ALPHA_B_CTRL_S0_S1_FACTOR_MODE_MASK  (0x6U)
#define PXP_ALPHA_B_CTRL_S0_S1_FACTOR_MODE_SHIFT (1U)
/*! S0_S1_FACTOR_MODE - S0_S1_FACTOR_MODE
 *  0b00..using 1.
 *  0b01..using 0.
 *  0b10..using straight alpha.
 *  0b11..using inverse alpha.
 */
#define PXP_ALPHA_B_CTRL_S0_S1_FACTOR_MODE(x)    (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S0_S1_FACTOR_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S0_S1_FACTOR_MODE_MASK)

#define PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_MODE_MASK (0x18U)
#define PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_MODE_SHIFT (3U)
/*! S0_GLOBAL_ALPHA_MODE - S0_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha.
 *  0b01..using local alpha.
 *  0b10..using scaled alpha.
 *  0b11..using scaled alpha.
 */
#define PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_MODE_MASK)

#define PXP_ALPHA_B_CTRL_S0_ALPHA_MODE_MASK      (0x20U)
#define PXP_ALPHA_B_CTRL_S0_ALPHA_MODE_SHIFT     (5U)
/*! S0_ALPHA_MODE - S0_ALPHA_MODE
 *  0b0..straight mode for s0 alpha
 *  0b1..inversed mode for s0 alpha
 */
#define PXP_ALPHA_B_CTRL_S0_ALPHA_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S0_ALPHA_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S0_ALPHA_MODE_MASK)

#define PXP_ALPHA_B_CTRL_S0_COLOR_MODE_MASK      (0x40U)
#define PXP_ALPHA_B_CTRL_S0_COLOR_MODE_SHIFT     (6U)
/*! S0_COLOR_MODE - S0_COLOR_MODE
 *  0b0..straight mode for s0 color
 *  0b1..multiply mode for s0 color
 */
#define PXP_ALPHA_B_CTRL_S0_COLOR_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S0_COLOR_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S0_COLOR_MODE_MASK)

#define PXP_ALPHA_B_CTRL_RSVD1_MASK              (0x80U)
#define PXP_ALPHA_B_CTRL_RSVD1_SHIFT             (7U)
/*! RSVD1 - RSVD1 */
#define PXP_ALPHA_B_CTRL_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_RSVD1_SHIFT)) & PXP_ALPHA_B_CTRL_RSVD1_MASK)

#define PXP_ALPHA_B_CTRL_S1_S0_FACTOR_MODE_MASK  (0x300U)
#define PXP_ALPHA_B_CTRL_S1_S0_FACTOR_MODE_SHIFT (8U)
/*! S1_S0_FACTOR_MODE - S1_S0_FACTOR_MODE
 *  0b00..using 1.
 *  0b01..using 0.
 *  0b10..using straight alpha.
 *  0b11..using inverse alpha.
 */
#define PXP_ALPHA_B_CTRL_S1_S0_FACTOR_MODE(x)    (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S1_S0_FACTOR_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S1_S0_FACTOR_MODE_MASK)

#define PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_MODE_MASK (0xC00U)
#define PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_MODE_SHIFT (10U)
/*! S1_GLOBAL_ALPHA_MODE - S1_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha.
 *  0b01..using local alpha.
 *  0b10..using scaled alpha.
 *  0b11..using scaled alpha.
 */
#define PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_MODE_MASK)

#define PXP_ALPHA_B_CTRL_S1_ALPHA_MODE_MASK      (0x1000U)
#define PXP_ALPHA_B_CTRL_S1_ALPHA_MODE_SHIFT     (12U)
/*! S1_ALPHA_MODE - S1_ALPHA_MODE
 *  0b0..straight mode for s1 alpha
 *  0b1..inversed mode for s1 alpha
 */
#define PXP_ALPHA_B_CTRL_S1_ALPHA_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S1_ALPHA_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S1_ALPHA_MODE_MASK)

#define PXP_ALPHA_B_CTRL_S1_COLOR_MODE_MASK      (0x2000U)
#define PXP_ALPHA_B_CTRL_S1_COLOR_MODE_SHIFT     (13U)
/*! S1_COLOR_MODE - S1_COLOR_MODE
 *  0b0..straight mode for s1 color
 *  0b1..multiply mode for s1 color
 */
#define PXP_ALPHA_B_CTRL_S1_COLOR_MODE(x)        (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S1_COLOR_MODE_SHIFT)) & PXP_ALPHA_B_CTRL_S1_COLOR_MODE_MASK)

#define PXP_ALPHA_B_CTRL_RSVD0_MASK              (0xC000U)
#define PXP_ALPHA_B_CTRL_RSVD0_SHIFT             (14U)
/*! RSVD0 - RSVD0 */
#define PXP_ALPHA_B_CTRL_RSVD0(x)                (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_RSVD0_SHIFT)) & PXP_ALPHA_B_CTRL_RSVD0_MASK)

#define PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_MASK    (0xFF0000U)
#define PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_SHIFT   (16U)
/*! S0_GLOBAL_ALPHA - S0_GLOBAL_ALPHA */
#define PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_SHIFT)) & PXP_ALPHA_B_CTRL_S0_GLOBAL_ALPHA_MASK)

#define PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_MASK    (0xFF000000U)
#define PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_SHIFT   (24U)
/*! S1_GLOBAL_ALPHA - S1_GLOBAL_ALPHA */
#define PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_SHIFT)) & PXP_ALPHA_B_CTRL_S1_GLOBAL_ALPHA_MASK)
/*! @} */

/*! @name ALPHA_B_CTRL_1 - Alpha Engine B Control 1 Register */
/*! @{ */

#define PXP_ALPHA_B_CTRL_1_ROP_ENABLE_MASK       (0x1U)
#define PXP_ALPHA_B_CTRL_1_ROP_ENABLE_SHIFT      (0U)
/*! ROP_ENABLE - ROP_ENABLE */
#define PXP_ALPHA_B_CTRL_1_ROP_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_1_ROP_ENABLE_SHIFT)) & PXP_ALPHA_B_CTRL_1_ROP_ENABLE_MASK)

#define PXP_ALPHA_B_CTRL_1_OL_CLRKEY_ENABLE_MASK (0x2U)
#define PXP_ALPHA_B_CTRL_1_OL_CLRKEY_ENABLE_SHIFT (1U)
/*! OL_CLRKEY_ENABLE - OL_CLRKEY_ENABLE */
#define PXP_ALPHA_B_CTRL_1_OL_CLRKEY_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_1_OL_CLRKEY_ENABLE_SHIFT)) & PXP_ALPHA_B_CTRL_1_OL_CLRKEY_ENABLE_MASK)

#define PXP_ALPHA_B_CTRL_1_RSVD1_MASK            (0xCU)
#define PXP_ALPHA_B_CTRL_1_RSVD1_SHIFT           (2U)
/*! RSVD1 - RSVD1 */
#define PXP_ALPHA_B_CTRL_1_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_1_RSVD1_SHIFT)) & PXP_ALPHA_B_CTRL_1_RSVD1_MASK)

#define PXP_ALPHA_B_CTRL_1_ROP_MASK              (0xF0U)
#define PXP_ALPHA_B_CTRL_1_ROP_SHIFT             (4U)
/*! ROP - ROP
 *  0b0000..MASKAS : AS AND PS
 *  0b0001..MASKNOTAS : nAS AND PS
 *  0b0010..MASKASNOT : AS AND nPS
 *  0b0011..MERGEAS : AS OR PS
 *  0b0100..MERGENOTAS : nAS OR PS
 *  0b0101..MERGEASNOT : AS OR nPS
 *  0b0110..NOTCOPYAS : nAS
 *  0b0111..NOT : nPS
 *  0b1000..NOTMASKAS : AS NAND PS
 *  0b1001..NOTMERGEAS : AS NOR PS
 *  0b1010..XORAS : AS XOR PS
 *  0b1011..NOTXORAS : AS XNOR PS
 */
#define PXP_ALPHA_B_CTRL_1_ROP(x)                (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_1_ROP_SHIFT)) & PXP_ALPHA_B_CTRL_1_ROP_MASK)

#define PXP_ALPHA_B_CTRL_1_RSVD0_MASK            (0xFFFFFF00U)
#define PXP_ALPHA_B_CTRL_1_RSVD0_SHIFT           (8U)
/*! RSVD0 - RSVD0 */
#define PXP_ALPHA_B_CTRL_1_RSVD0(x)              (((uint32_t)(((uint32_t)(x)) << PXP_ALPHA_B_CTRL_1_RSVD0_SHIFT)) & PXP_ALPHA_B_CTRL_1_RSVD0_MASK)
/*! @} */

/*! @name PS_BACKGROUND_1 - PS Background Color 1 Register */
/*! @{ */

#define PXP_PS_BACKGROUND_1_COLOR_MASK           (0xFFFFFFU)
#define PXP_PS_BACKGROUND_1_COLOR_SHIFT          (0U)
/*! COLOR - COLOR */
#define PXP_PS_BACKGROUND_1_COLOR(x)             (((uint32_t)(((uint32_t)(x)) << PXP_PS_BACKGROUND_1_COLOR_SHIFT)) & PXP_PS_BACKGROUND_1_COLOR_MASK)

#define PXP_PS_BACKGROUND_1_RSVD_MASK            (0xFF000000U)
#define PXP_PS_BACKGROUND_1_RSVD_SHIFT           (24U)
/*! RSVD - RSVD */
#define PXP_PS_BACKGROUND_1_RSVD(x)              (((uint32_t)(((uint32_t)(x)) << PXP_PS_BACKGROUND_1_RSVD_SHIFT)) & PXP_PS_BACKGROUND_1_RSVD_MASK)
/*! @} */

/*! @name PS_CLRKEYLOW_1 - PS Color Key Low Register */
/*! @{ */

#define PXP_PS_CLRKEYLOW_1_PIXEL_MASK            (0xFFFFFFU)
#define PXP_PS_CLRKEYLOW_1_PIXEL_SHIFT           (0U)
/*! PIXEL - PIXEL */
#define PXP_PS_CLRKEYLOW_1_PIXEL(x)              (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYLOW_1_PIXEL_SHIFT)) & PXP_PS_CLRKEYLOW_1_PIXEL_MASK)

#define PXP_PS_CLRKEYLOW_1_RSVD1_MASK            (0xFF000000U)
#define PXP_PS_CLRKEYLOW_1_RSVD1_SHIFT           (24U)
/*! RSVD1 - RSVD1 */
#define PXP_PS_CLRKEYLOW_1_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYLOW_1_RSVD1_SHIFT)) & PXP_PS_CLRKEYLOW_1_RSVD1_MASK)
/*! @} */

/*! @name PS_CLRKEYHIGH_1 - PS Color Key High Register */
/*! @{ */

#define PXP_PS_CLRKEYHIGH_1_PIXEL_MASK           (0xFFFFFFU)
#define PXP_PS_CLRKEYHIGH_1_PIXEL_SHIFT          (0U)
/*! PIXEL - PIXEL */
#define PXP_PS_CLRKEYHIGH_1_PIXEL(x)             (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYHIGH_1_PIXEL_SHIFT)) & PXP_PS_CLRKEYHIGH_1_PIXEL_MASK)

#define PXP_PS_CLRKEYHIGH_1_RSVD1_MASK           (0xFF000000U)
#define PXP_PS_CLRKEYHIGH_1_RSVD1_SHIFT          (24U)
/*! RSVD1 - RSVD1 */
#define PXP_PS_CLRKEYHIGH_1_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << PXP_PS_CLRKEYHIGH_1_RSVD1_SHIFT)) & PXP_PS_CLRKEYHIGH_1_RSVD1_MASK)
/*! @} */

/*! @name AS_CLRKEYLOW_1 - Overlay Color Key Low Register */
/*! @{ */

#define PXP_AS_CLRKEYLOW_1_PIXEL_MASK            (0xFFFFFFU)
#define PXP_AS_CLRKEYLOW_1_PIXEL_SHIFT           (0U)
/*! PIXEL - PIXEL */
#define PXP_AS_CLRKEYLOW_1_PIXEL(x)              (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYLOW_1_PIXEL_SHIFT)) & PXP_AS_CLRKEYLOW_1_PIXEL_MASK)

#define PXP_AS_CLRKEYLOW_1_RSVD1_MASK            (0xFF000000U)
#define PXP_AS_CLRKEYLOW_1_RSVD1_SHIFT           (24U)
/*! RSVD1 - RSVD1 */
#define PXP_AS_CLRKEYLOW_1_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYLOW_1_RSVD1_SHIFT)) & PXP_AS_CLRKEYLOW_1_RSVD1_MASK)
/*! @} */

/*! @name AS_CLRKEYHIGH_1 - Overlay Color Key High Register */
/*! @{ */

#define PXP_AS_CLRKEYHIGH_1_PIXEL_MASK           (0xFFFFFFU)
#define PXP_AS_CLRKEYHIGH_1_PIXEL_SHIFT          (0U)
/*! PIXEL - PIXEL */
#define PXP_AS_CLRKEYHIGH_1_PIXEL(x)             (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYHIGH_1_PIXEL_SHIFT)) & PXP_AS_CLRKEYHIGH_1_PIXEL_MASK)

#define PXP_AS_CLRKEYHIGH_1_RSVD1_MASK           (0xFF000000U)
#define PXP_AS_CLRKEYHIGH_1_RSVD1_SHIFT          (24U)
/*! RSVD1 - RSVD1 */
#define PXP_AS_CLRKEYHIGH_1_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << PXP_AS_CLRKEYHIGH_1_RSVD1_SHIFT)) & PXP_AS_CLRKEYHIGH_1_RSVD1_MASK)
/*! @} */

/*! @name CTRL2 - Control Register 2 */
/*! @{ */

#define PXP_CTRL2_ENABLE_MASK                    (0x1U)
#define PXP_CTRL2_ENABLE_SHIFT                   (0U)
/*! ENABLE - ENABLE */
#define PXP_CTRL2_ENABLE(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ENABLE_SHIFT)) & PXP_CTRL2_ENABLE_MASK)

#define PXP_CTRL2_RSVD0_MASK                     (0xFEU)
#define PXP_CTRL2_RSVD0_SHIFT                    (1U)
/*! RSVD0 - RSVD0 */
#define PXP_CTRL2_RSVD0(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_RSVD0_SHIFT)) & PXP_CTRL2_RSVD0_MASK)

#define PXP_CTRL2_ROTATE0_MASK                   (0x300U)
#define PXP_CTRL2_ROTATE0_SHIFT                  (8U)
/*! ROTATE0 - ROTATE0
 *  0b00..ROT_0 : rotate 0 degrees
 *  0b01..ROT_90 : rotate 90 degrees
 *  0b10..ROT_180 : rotate 180 degrees
 *  0b11..ROT_270 : rotate 270 degrees
 */
#define PXP_CTRL2_ROTATE0(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ROTATE0_SHIFT)) & PXP_CTRL2_ROTATE0_MASK)

#define PXP_CTRL2_HFLIP0_MASK                    (0x400U)
#define PXP_CTRL2_HFLIP0_SHIFT                   (10U)
/*! HFLIP0 - HFLIP0 */
#define PXP_CTRL2_HFLIP0(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_HFLIP0_SHIFT)) & PXP_CTRL2_HFLIP0_MASK)

#define PXP_CTRL2_VFLIP0_MASK                    (0x800U)
#define PXP_CTRL2_VFLIP0_SHIFT                   (11U)
/*! VFLIP0 - VFLIP0 */
#define PXP_CTRL2_VFLIP0(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_VFLIP0_SHIFT)) & PXP_CTRL2_VFLIP0_MASK)

#define PXP_CTRL2_ROTATE1_MASK                   (0x3000U)
#define PXP_CTRL2_ROTATE1_SHIFT                  (12U)
/*! ROTATE1 - ROTATE1
 *  0b00..ROT_0 : rotate 0 degrees
 *  0b01..ROT_90 : rotate 90 degrees
 *  0b10..ROT_180 : rotate 180 degrees
 *  0b11..ROT_270 : rotate 270 degrees
 */
#define PXP_CTRL2_ROTATE1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ROTATE1_SHIFT)) & PXP_CTRL2_ROTATE1_MASK)

#define PXP_CTRL2_HFLIP1_MASK                    (0x4000U)
#define PXP_CTRL2_HFLIP1_SHIFT                   (14U)
/*! HFLIP1 - HFLIP1 */
#define PXP_CTRL2_HFLIP1(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_HFLIP1_SHIFT)) & PXP_CTRL2_HFLIP1_MASK)

#define PXP_CTRL2_VFLIP1_MASK                    (0x8000U)
#define PXP_CTRL2_VFLIP1_SHIFT                   (15U)
/*! VFLIP1 - VFLIP1 */
#define PXP_CTRL2_VFLIP1(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_VFLIP1_SHIFT)) & PXP_CTRL2_VFLIP1_MASK)

#define PXP_CTRL2_RSVD1_MASK                     (0xF0000U)
#define PXP_CTRL2_RSVD1_SHIFT                    (16U)
/*! RSVD1 - RSVD1 */
#define PXP_CTRL2_RSVD1(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_RSVD1_SHIFT)) & PXP_CTRL2_RSVD1_MASK)

#define PXP_CTRL2_ENABLE_INPUT_FETCH_STORE_MASK  (0x100000U)
#define PXP_CTRL2_ENABLE_INPUT_FETCH_STORE_SHIFT (20U)
/*! ENABLE_INPUT_FETCH_STORE - ENABLE_INPUT_FETCH_STORE */
#define PXP_CTRL2_ENABLE_INPUT_FETCH_STORE(x)    (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ENABLE_INPUT_FETCH_STORE_SHIFT)) & PXP_CTRL2_ENABLE_INPUT_FETCH_STORE_MASK)

#define PXP_CTRL2_ENABLE_ALPHA_B_MASK            (0x200000U)
#define PXP_CTRL2_ENABLE_ALPHA_B_SHIFT           (21U)
/*! ENABLE_ALPHA_B - ENABLE_ALPHA_B */
#define PXP_CTRL2_ENABLE_ALPHA_B(x)              (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ENABLE_ALPHA_B_SHIFT)) & PXP_CTRL2_ENABLE_ALPHA_B_MASK)

#define PXP_CTRL2_RSVD2_MASK                     (0x400000U)
#define PXP_CTRL2_RSVD2_SHIFT                    (22U)
/*! RSVD2 - RSVD2 */
#define PXP_CTRL2_RSVD2(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_RSVD2_SHIFT)) & PXP_CTRL2_RSVD2_MASK)

#define PXP_CTRL2_BLOCK_SIZE_MASK                (0x800000U)
#define PXP_CTRL2_BLOCK_SIZE_SHIFT               (23U)
/*! BLOCK_SIZE - BLOCK_SIZE
 *  0b0..BLK_SIZE_8X8 : Process 8x8 pixel blocks.
 *  0b1..BLK_SIZE_16X16 : Process 16x16 pixel blocks.
 */
#define PXP_CTRL2_BLOCK_SIZE(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_BLOCK_SIZE_SHIFT)) & PXP_CTRL2_BLOCK_SIZE_MASK)

#define PXP_CTRL2_ENABLE_CSC2_MASK               (0x1000000U)
#define PXP_CTRL2_ENABLE_CSC2_SHIFT              (24U)
/*! ENABLE_CSC2 - ENABLE_CSC2 */
#define PXP_CTRL2_ENABLE_CSC2(x)                 (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ENABLE_CSC2_SHIFT)) & PXP_CTRL2_ENABLE_CSC2_MASK)

#define PXP_CTRL2_RSVD4_MASK                     (0x2000000U)
#define PXP_CTRL2_RSVD4_SHIFT                    (25U)
/*! RSVD4 - RSVD4 */
#define PXP_CTRL2_RSVD4(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_RSVD4_SHIFT)) & PXP_CTRL2_RSVD4_MASK)

#define PXP_CTRL2_ENABLE_ROTATE0_MASK            (0x4000000U)
#define PXP_CTRL2_ENABLE_ROTATE0_SHIFT           (26U)
/*! ENABLE_ROTATE0 - ENABLE_ROTATE0 */
#define PXP_CTRL2_ENABLE_ROTATE0(x)              (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ENABLE_ROTATE0_SHIFT)) & PXP_CTRL2_ENABLE_ROTATE0_MASK)

#define PXP_CTRL2_ENABLE_ROTATE1_MASK            (0x8000000U)
#define PXP_CTRL2_ENABLE_ROTATE1_SHIFT           (27U)
/*! ENABLE_ROTATE1 - ENABLE_ROTATE1 */
#define PXP_CTRL2_ENABLE_ROTATE1(x)              (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_ENABLE_ROTATE1_SHIFT)) & PXP_CTRL2_ENABLE_ROTATE1_MASK)

#define PXP_CTRL2_RSVD3_MASK                     (0xF0000000U)
#define PXP_CTRL2_RSVD3_SHIFT                    (28U)
/*! RSVD3 - RSVD3 */
#define PXP_CTRL2_RSVD3(x)                       (((uint32_t)(((uint32_t)(x)) << PXP_CTRL2_RSVD3_SHIFT)) & PXP_CTRL2_RSVD3_MASK)
/*! @} */

/*! @name POWER_REG0 - Power Control Register 0 */
/*! @{ */

#define PXP_POWER_REG0_RSVD0_MASK                (0x1FFU)
#define PXP_POWER_REG0_RSVD0_SHIFT               (0U)
/*! RSVD0 - RSVD0 */
#define PXP_POWER_REG0_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_POWER_REG0_RSVD0_SHIFT)) & PXP_POWER_REG0_RSVD0_MASK)

#define PXP_POWER_REG0_ROT0_MEM_LP_STATE_MASK    (0xE00U)
#define PXP_POWER_REG0_ROT0_MEM_LP_STATE_SHIFT   (9U)
/*! ROT0_MEM_LP_STATE - ROT0_MEM_LP_STATE
 *  0b000..NONE : Memory is not in low power state.
 *  0b001..LS : Light Sleep Mode. Low leakage mode, maintain memory contents.
 *  0b010..DS : Deep Sleep Mode. Low leakage mode, maintain memory contents.
 *  0b100..SD : Shut Down Mode. Shut Down periphery and core, no memory retention.
 */
#define PXP_POWER_REG0_ROT0_MEM_LP_STATE(x)      (((uint32_t)(((uint32_t)(x)) << PXP_POWER_REG0_ROT0_MEM_LP_STATE_SHIFT)) & PXP_POWER_REG0_ROT0_MEM_LP_STATE_MASK)

#define PXP_POWER_REG0_CTRL_MASK                 (0xFFFFF000U)
#define PXP_POWER_REG0_CTRL_SHIFT                (12U)
/*! CTRL - CTRL */
#define PXP_POWER_REG0_CTRL(x)                   (((uint32_t)(((uint32_t)(x)) << PXP_POWER_REG0_CTRL_SHIFT)) & PXP_POWER_REG0_CTRL_MASK)
/*! @} */

/*! @name POWER_REG1 - Power Control Register 1 */
/*! @{ */

#define PXP_POWER_REG1_ROT1_MEM_LP_STATE_MASK    (0x7U)
#define PXP_POWER_REG1_ROT1_MEM_LP_STATE_SHIFT   (0U)
/*! ROT1_MEM_LP_STATE - ROT1_MEM_LP_STATE
 *  0b000..NONE : Memory is not in low power state.
 *  0b001..LS : Light Sleep Mode. Low leakage mode, maintain memory contents.
 *  0b010..DS : Deep Sleep Mode. Low leakage mode, maintain memory contents.
 *  0b100..SD : Shut Down Mode. Shut Down periphery and core, no memory retention.
 */
#define PXP_POWER_REG1_ROT1_MEM_LP_STATE(x)      (((uint32_t)(((uint32_t)(x)) << PXP_POWER_REG1_ROT1_MEM_LP_STATE_SHIFT)) & PXP_POWER_REG1_ROT1_MEM_LP_STATE_MASK)

#define PXP_POWER_REG1_RSVD0_MASK                (0xFFFFFFF8U)
#define PXP_POWER_REG1_RSVD0_SHIFT               (3U)
/*! RSVD0 - RSVD0 */
#define PXP_POWER_REG1_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << PXP_POWER_REG1_RSVD0_SHIFT)) & PXP_POWER_REG1_RSVD0_MASK)
/*! @} */

/*! @name DATA_PATH_CTRL0 - Data Path Control 0 Register */
/*! @{ */

#define PXP_DATA_PATH_CTRL0_MUX0_SEL_MASK        (0x3U)
#define PXP_DATA_PATH_CTRL0_MUX0_SEL_SHIFT       (0U)
/*! MUX0_SEL - MUX0_SEL
 *  0b00..Input from Process Surface engine.
 *  0b01..Input stage Fetch engine, Channel 0
 *  0b10..Input stage Fetch engine, Channel 1
 *  0b11..No output
 */
#define PXP_DATA_PATH_CTRL0_MUX0_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX0_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX0_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX1_SEL_MASK        (0xCU)
#define PXP_DATA_PATH_CTRL0_MUX1_SEL_SHIFT       (2U)
/*! MUX1_SEL - MUX1_SEL
 *  0b00..Input stage Fetch engine, Channel 0
 *  0b01..Output of the Rotation1 engine
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX1_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX1_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX1_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX2_SEL_MASK        (0x30U)
#define PXP_DATA_PATH_CTRL0_MUX2_SEL_SHIFT       (4U)
/*! MUX2_SEL - MUX2_SEL
 *  0b00..Input stage Fetch engine, Channel 1
 *  0b01..Output of the Rotation1 engine
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX2_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX2_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX2_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX3_SEL_MASK        (0xC0U)
#define PXP_DATA_PATH_CTRL0_MUX3_SEL_SHIFT       (6U)
/*! MUX3_SEL - MUX3_SEL
 *  0b00..Output of the CSC1 engine
 *  0b01..Output of the Rotation1 engine
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX3_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX3_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX3_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX4_SEL_MASK        (0x300U)
#define PXP_DATA_PATH_CTRL0_MUX4_SEL_SHIFT       (8U)
/*! MUX4_SEL - MUX4_SEL */
#define PXP_DATA_PATH_CTRL0_MUX4_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX4_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX4_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX5_SEL_MASK        (0xC00U)
#define PXP_DATA_PATH_CTRL0_MUX5_SEL_SHIFT       (10U)
/*! MUX5_SEL - MUX5_SEL
 *  0b00..Output of MUX1
 *  0b01..Output of alpha blending / color key 1
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX5_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX5_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX5_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX6_SEL_MASK        (0x3000U)
#define PXP_DATA_PATH_CTRL0_MUX6_SEL_SHIFT       (12U)
/*! MUX6_SEL - MUX6_SEL
 *  0b00..Output of alpha blending / color key 1
 *  0b01..Output of alpha blending / color key 0
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX6_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX6_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX6_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX7_SEL_MASK        (0xC000U)
#define PXP_DATA_PATH_CTRL0_MUX7_SEL_SHIFT       (14U)
/*! MUX7_SEL - MUX7_SEL
 *  0b00..Output of MUX 5
 *  0b01..Output of CSC2
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX7_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX7_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX7_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX8_SEL_MASK        (0x30000U)
#define PXP_DATA_PATH_CTRL0_MUX8_SEL_SHIFT       (16U)
/*! MUX8_SEL - MUX8_SEL
 *  0b00..Output of CSC2
 *  0b01..Output of alpha blending / color key 0
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX8_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX8_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX8_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX9_SEL_MASK        (0xC0000U)
#define PXP_DATA_PATH_CTRL0_MUX9_SEL_SHIFT       (18U)
/*! MUX9_SEL - MUX9_SEL */
#define PXP_DATA_PATH_CTRL0_MUX9_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX9_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX9_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX10_SEL_MASK       (0x300000U)
#define PXP_DATA_PATH_CTRL0_MUX10_SEL_SHIFT      (20U)
/*! MUX10_SEL - MUX10_SEL
 *  0b00..Output of MUX 7
 *  0b01..No output
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX10_SEL(x)         (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX10_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX10_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX11_SEL_MASK       (0xC00000U)
#define PXP_DATA_PATH_CTRL0_MUX11_SEL_SHIFT      (22U)
/*! MUX11_SEL - MUX11_SEL
 *  0b00..No output
 *  0b01..Output of MUX 8
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX11_SEL(x)         (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX11_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX11_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX12_SEL_MASK       (0x3000000U)
#define PXP_DATA_PATH_CTRL0_MUX12_SEL_SHIFT      (24U)
/*! MUX12_SEL - MUX12_SEL
 *  0b00..Output of MUX 10
 *  0b01..Output of MUX 11
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX12_SEL(x)         (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX12_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX12_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX13_SEL_MASK       (0xC000000U)
#define PXP_DATA_PATH_CTRL0_MUX13_SEL_SHIFT      (26U)
/*! MUX13_SEL - MUX13_SEL
 *  0b00..No output
 *  0b01..Input stage Fetch engine, Channel 1
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX13_SEL(x)         (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX13_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX13_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX14_SEL_MASK       (0x30000000U)
#define PXP_DATA_PATH_CTRL0_MUX14_SEL_SHIFT      (28U)
/*! MUX14_SEL - MUX14_SEL
 *  0b00..Output of Rotation 0.
 *  0b01..Output of MUX 11
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX14_SEL(x)         (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX14_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX14_SEL_MASK)

#define PXP_DATA_PATH_CTRL0_MUX15_SEL_MASK       (0xC0000000U)
#define PXP_DATA_PATH_CTRL0_MUX15_SEL_SHIFT      (30U)
/*! MUX15_SEL - MUX15_SEL
 *  0b00..Output of Input fetch, Channel 0
 *  0b01..Output of MUX 10
 *  0b10..No output
 *  0b11..No Output
 */
#define PXP_DATA_PATH_CTRL0_MUX15_SEL(x)         (((uint32_t)(((uint32_t)(x)) << PXP_DATA_PATH_CTRL0_MUX15_SEL_SHIFT)) & PXP_DATA_PATH_CTRL0_MUX15_SEL_MASK)
/*! @} */

/*! @name IRQ_MASK - IRQ Mask Register */
/*! @{ */

#define PXP_IRQ_MASK_FIRST_CH0_PREFETCH_IRQ_EN_MASK (0x1U)
#define PXP_IRQ_MASK_FIRST_CH0_PREFETCH_IRQ_EN_SHIFT (0U)
/*! FIRST_CH0_PREFETCH_IRQ_EN - FIRST_CH0_PREFETCH_IRQ_EN */
#define PXP_IRQ_MASK_FIRST_CH0_PREFETCH_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_MASK_FIRST_CH0_PREFETCH_IRQ_EN_SHIFT)) & PXP_IRQ_MASK_FIRST_CH0_PREFETCH_IRQ_EN_MASK)

#define PXP_IRQ_MASK_FIRST_CH1_PREFETCH_IRQ_EN_MASK (0x2U)
#define PXP_IRQ_MASK_FIRST_CH1_PREFETCH_IRQ_EN_SHIFT (1U)
/*! FIRST_CH1_PREFETCH_IRQ_EN - FIRST_CH1_PREFETCH_IRQ_EN */
#define PXP_IRQ_MASK_FIRST_CH1_PREFETCH_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_MASK_FIRST_CH1_PREFETCH_IRQ_EN_SHIFT)) & PXP_IRQ_MASK_FIRST_CH1_PREFETCH_IRQ_EN_MASK)

#define PXP_IRQ_MASK_FIRST_CH0_STORE_IRQ_EN_MASK (0x4U)
#define PXP_IRQ_MASK_FIRST_CH0_STORE_IRQ_EN_SHIFT (2U)
/*! FIRST_CH0_STORE_IRQ_EN - FIRST_CH0_STORE_IRQ_EN */
#define PXP_IRQ_MASK_FIRST_CH0_STORE_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_MASK_FIRST_CH0_STORE_IRQ_EN_SHIFT)) & PXP_IRQ_MASK_FIRST_CH0_STORE_IRQ_EN_MASK)

#define PXP_IRQ_MASK_FIRST_CH1_STORE_IRQ_EN_MASK (0x8U)
#define PXP_IRQ_MASK_FIRST_CH1_STORE_IRQ_EN_SHIFT (3U)
/*! FIRST_CH1_STORE_IRQ_EN - FIRST_CH1_STORE_IRQ_EN */
#define PXP_IRQ_MASK_FIRST_CH1_STORE_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_MASK_FIRST_CH1_STORE_IRQ_EN_SHIFT)) & PXP_IRQ_MASK_FIRST_CH1_STORE_IRQ_EN_MASK)

#define PXP_IRQ_MASK_RSVD0_MASK                  (0xFF0U)
#define PXP_IRQ_MASK_RSVD0_SHIFT                 (4U)
/*! RSVD0 - RSVD0 */
#define PXP_IRQ_MASK_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_MASK_RSVD0_SHIFT)) & PXP_IRQ_MASK_RSVD0_MASK)

#define PXP_IRQ_MASK_FIRST_STORE_IRQ_EN_MASK     (0x1000U)
#define PXP_IRQ_MASK_FIRST_STORE_IRQ_EN_SHIFT    (12U)
/*! FIRST_STORE_IRQ_EN - FIRST_STORE_IRQ_EN */
#define PXP_IRQ_MASK_FIRST_STORE_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_MASK_FIRST_STORE_IRQ_EN_SHIFT)) & PXP_IRQ_MASK_FIRST_STORE_IRQ_EN_MASK)

#define PXP_IRQ_MASK_RSVD1_MASK                  (0xFFFFE000U)
#define PXP_IRQ_MASK_RSVD1_SHIFT                 (13U)
/*! RSVD1 - RSVD1 */
#define PXP_IRQ_MASK_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_MASK_RSVD1_SHIFT)) & PXP_IRQ_MASK_RSVD1_MASK)
/*! @} */

/*! @name IRQ - Interrupt Register */
/*! @{ */

#define PXP_IRQ_FIRST_CH0_PREFETCH_IRQ_MASK      (0x1U)
#define PXP_IRQ_FIRST_CH0_PREFETCH_IRQ_SHIFT     (0U)
/*! FIRST_CH0_PREFETCH_IRQ - FIRST_CH0_PREFETCH_IRQ */
#define PXP_IRQ_FIRST_CH0_PREFETCH_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_FIRST_CH0_PREFETCH_IRQ_SHIFT)) & PXP_IRQ_FIRST_CH0_PREFETCH_IRQ_MASK)

#define PXP_IRQ_FIRST_CH1_PREFETCH_IRQ_MASK      (0x2U)
#define PXP_IRQ_FIRST_CH1_PREFETCH_IRQ_SHIFT     (1U)
/*! FIRST_CH1_PREFETCH_IRQ - FIRST_CH1_PREFETCH_IRQ */
#define PXP_IRQ_FIRST_CH1_PREFETCH_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_FIRST_CH1_PREFETCH_IRQ_SHIFT)) & PXP_IRQ_FIRST_CH1_PREFETCH_IRQ_MASK)

#define PXP_IRQ_FIRST_CH0_STORE_IRQ_MASK         (0x4U)
#define PXP_IRQ_FIRST_CH0_STORE_IRQ_SHIFT        (2U)
/*! FIRST_CH0_STORE_IRQ - FIRST_CH0_STORE_IRQ */
#define PXP_IRQ_FIRST_CH0_STORE_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_FIRST_CH0_STORE_IRQ_SHIFT)) & PXP_IRQ_FIRST_CH0_STORE_IRQ_MASK)

#define PXP_IRQ_FIRST_CH1_STORE_IRQ_MASK         (0x8U)
#define PXP_IRQ_FIRST_CH1_STORE_IRQ_SHIFT        (3U)
/*! FIRST_CH1_STORE_IRQ - FIRST_CH1_STORE_IRQ */
#define PXP_IRQ_FIRST_CH1_STORE_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_FIRST_CH1_STORE_IRQ_SHIFT)) & PXP_IRQ_FIRST_CH1_STORE_IRQ_MASK)

#define PXP_IRQ_RSVD0_MASK                       (0xFF0U)
#define PXP_IRQ_RSVD0_SHIFT                      (4U)
/*! RSVD0 - RSVD0 */
#define PXP_IRQ_RSVD0(x)                         (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_RSVD0_SHIFT)) & PXP_IRQ_RSVD0_MASK)

#define PXP_IRQ_FIRST_STORE_IRQ_MASK             (0x1000U)
#define PXP_IRQ_FIRST_STORE_IRQ_SHIFT            (12U)
/*! FIRST_STORE_IRQ - FIRST_STORE_IRQ */
#define PXP_IRQ_FIRST_STORE_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_FIRST_STORE_IRQ_SHIFT)) & PXP_IRQ_FIRST_STORE_IRQ_MASK)

#define PXP_IRQ_RSVD1_MASK                       (0xFFFFE000U)
#define PXP_IRQ_RSVD1_SHIFT                      (13U)
/*! RSVD1 - RSVD1 */
#define PXP_IRQ_RSVD1(x)                         (((uint32_t)(((uint32_t)(x)) << PXP_IRQ_RSVD1_SHIFT)) & PXP_IRQ_RSVD1_MASK)
/*! @} */

/*! @name NEXT - Next Frame Pointer Register */
/*! @{ */

#define PXP_NEXT_ENABLED_MASK                    (0x1U)
#define PXP_NEXT_ENABLED_SHIFT                   (0U)
/*! ENABLED - ENABLED */
#define PXP_NEXT_ENABLED(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_NEXT_ENABLED_SHIFT)) & PXP_NEXT_ENABLED_MASK)

#define PXP_NEXT_RSVD_MASK                       (0x2U)
#define PXP_NEXT_RSVD_SHIFT                      (1U)
/*! RSVD - RSVD */
#define PXP_NEXT_RSVD(x)                         (((uint32_t)(((uint32_t)(x)) << PXP_NEXT_RSVD_SHIFT)) & PXP_NEXT_RSVD_MASK)

#define PXP_NEXT_POINTER_MASK                    (0xFFFFFFFCU)
#define PXP_NEXT_POINTER_SHIFT                   (2U)
/*! POINTER - POINTER */
#define PXP_NEXT_POINTER(x)                      (((uint32_t)(((uint32_t)(x)) << PXP_NEXT_POINTER_SHIFT)) & PXP_NEXT_POINTER_MASK)
/*! @} */

/*! @name INPUT_FETCH_CTRL_CH0 - Input Fetch Control Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_CTRL_CH0_CH_EN_MASK      (0x1U)
#define PXP_INPUT_FETCH_CTRL_CH0_CH_EN_SHIFT     (0U)
/*! CH_EN - CH_EN
 *  0b0..Prefetch function is disable
 *  0b1..Prefetch function is enable
 */
#define PXP_INPUT_FETCH_CTRL_CH0_CH_EN(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_CH_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_CH_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_BLOCK_EN_MASK   (0x2U)
#define PXP_INPUT_FETCH_CTRL_CH0_BLOCK_EN_SHIFT  (1U)
/*! BLOCK_EN - BLOCK_EN
 *  0b0..Prefetch in scan mode
 *  0b1..Prefetch in block mode
 */
#define PXP_INPUT_FETCH_CTRL_CH0_BLOCK_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_BLOCK_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_BLOCK_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_BLOCK_16_MASK   (0x4U)
#define PXP_INPUT_FETCH_CTRL_CH0_BLOCK_16_SHIFT  (2U)
/*! BLOCK_16 - BLOCK_16
 *  0b0..BLK_SIZE_8x8 : Block size is 8x8
 *  0b1..BLK_SIZE_16x16 : Block size is 16x16
 */
#define PXP_INPUT_FETCH_CTRL_CH0_BLOCK_16(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_BLOCK_16_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_BLOCK_16_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_EN_MASK (0x8U)
#define PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_EN_SHIFT (3U)
/*! HANDSHAKE_EN - HANDSHAKE_EN
 *  0b0..Handshake with the store engine is disabled
 *  0b1..Handshake with the store engine is enabled
 */
#define PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_BYPASS_PIXEL_EN_MASK (0x10U)
#define PXP_INPUT_FETCH_CTRL_CH0_BYPASS_PIXEL_EN_SHIFT (4U)
/*! BYPASS_PIXEL_EN - BYPASS_PIXEL_EN
 *  0b0..Channel 0 is from memory
 *  0b1..Channel 0 is from previous process engine
 */
#define PXP_INPUT_FETCH_CTRL_CH0_BYPASS_PIXEL_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_BYPASS_PIXEL_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_BYPASS_PIXEL_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_HIGH_BYTE_MASK  (0x20U)
#define PXP_INPUT_FETCH_CTRL_CH0_HIGH_BYTE_SHIFT (5U)
/*! HIGH_BYTE - HIGH_BYTE
 *  0b0..In 64 bit mode, the output high byte will use channel1.
 *  0b1..In 64 bit mode, the output high byte will use channel0
 */
#define PXP_INPUT_FETCH_CTRL_CH0_HIGH_BYTE(x)    (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_HIGH_BYTE_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_HIGH_BYTE_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_RSVD4_MASK      (0x1C0U)
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD4_SHIFT     (6U)
/*! RSVD4 - RSVD4 */
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD4(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_RSVD4_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_RSVD4_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_HFLIP_MASK      (0x200U)
#define PXP_INPUT_FETCH_CTRL_CH0_HFLIP_SHIFT     (9U)
/*! HFLIP - HFLIP
 *  0b0..HFLIP disable
 *  0b1..VFLIP enable
 */
#define PXP_INPUT_FETCH_CTRL_CH0_HFLIP(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_HFLIP_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_HFLIP_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_VFLIP_MASK      (0x400U)
#define PXP_INPUT_FETCH_CTRL_CH0_VFLIP_SHIFT     (10U)
/*! VFLIP - VFLIP
 *  0b0..VFLIP disable
 *  0b1..VFLIP enable
 */
#define PXP_INPUT_FETCH_CTRL_CH0_VFLIP(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_VFLIP_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_VFLIP_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_RSVD3_MASK      (0x800U)
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD3_SHIFT     (11U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD3(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_RSVD3_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_RSVD3_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_ROTATION_ANGLE_MASK (0x3000U)
#define PXP_INPUT_FETCH_CTRL_CH0_ROTATION_ANGLE_SHIFT (12U)
/*! ROTATION_ANGLE - ROTATION_ANGLE
 *  0b00..ROT_0 : Rotate image by 0 degrees.
 *  0b01..ROT_90 : Rotate image by 90 degrees.
 *  0b10..ROT_180 : Rotate image by 180 degrees.
 *  0b11..ROT_270 : Rotate image by 270 degrees.
 */
#define PXP_INPUT_FETCH_CTRL_CH0_ROTATION_ANGLE(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_ROTATION_ANGLE_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_ROTATION_ANGLE_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_RSVD2_MASK      (0xC000U)
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD2_SHIFT     (14U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD2(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_RSVD2_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_RSVD2_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_RD_NUM_BYTES_MASK (0x30000U)
#define PXP_INPUT_FETCH_CTRL_CH0_RD_NUM_BYTES_SHIFT (16U)
/*! RD_NUM_BYTES - RD_NUM_BYTES
 *  0b00..NUM_8_BYTES : 8 bytes.
 *  0b01..NUM_16_BYTES : 16 bytes.
 *  0b10..NUM_32_BYTES : 32 bytes.
 *  0b11..NUM_64_BYTES : 64 bytes.
 */
#define PXP_INPUT_FETCH_CTRL_CH0_RD_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_RD_NUM_BYTES_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_RD_NUM_BYTES_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_RSVD1_MASK      (0xFC0000U)
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD1_SHIFT     (18U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD1(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_RSVD1_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_RSVD1_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_SCAN_LINE_NUM_MASK (0x3000000U)
#define PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_SCAN_LINE_NUM_SHIFT (24U)
/*! HANDSHAKE_SCAN_LINE_NUM - HANDSHAKE_SCAN_LINE_NUM
 *  0b00..1 line.
 *  0b01..8 lines
 *  0b10..16 lines
 *  0b11..16 lines
 */
#define PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_SCAN_LINE_NUM(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_SCAN_LINE_NUM_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_HANDSHAKE_SCAN_LINE_NUM_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_RSVD0_MASK      (0x7C000000U)
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD0_SHIFT     (26U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_CTRL_CH0_RSVD0(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_RSVD0_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_RSVD0_MASK)

#define PXP_INPUT_FETCH_CTRL_CH0_ARBIT_EN_MASK   (0x80000000U)
#define PXP_INPUT_FETCH_CTRL_CH0_ARBIT_EN_SHIFT  (31U)
/*! ARBIT_EN - ARBIT_EN
 *  0b0..Arbitration disable. If using 2 channels, will output 2 axi bus sets.
 *  0b1..Arbitration enable. If using 2 channel, will only output 1 axi bus sets
 */
#define PXP_INPUT_FETCH_CTRL_CH0_ARBIT_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH0_ARBIT_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH0_ARBIT_EN_MASK)
/*! @} */

/*! @name INPUT_FETCH_CTRL_CH1 - Input Fetch Control Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_CTRL_CH1_CH_EN_MASK      (0x1U)
#define PXP_INPUT_FETCH_CTRL_CH1_CH_EN_SHIFT     (0U)
/*! CH_EN - CH_EN
 *  0b0..prefetch function is disable
 *  0b1..prefetch function is enable
 */
#define PXP_INPUT_FETCH_CTRL_CH1_CH_EN(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_CH_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_CH_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_BLOCK_EN_MASK   (0x2U)
#define PXP_INPUT_FETCH_CTRL_CH1_BLOCK_EN_SHIFT  (1U)
/*! BLOCK_EN - BLOCK_EN
 *  0b0..Prefetch in scan mode
 *  0b1..Prefetch in block mode
 */
#define PXP_INPUT_FETCH_CTRL_CH1_BLOCK_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_BLOCK_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_BLOCK_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_BLOCK_16_MASK   (0x4U)
#define PXP_INPUT_FETCH_CTRL_CH1_BLOCK_16_SHIFT  (2U)
/*! BLOCK_16 - BLOCK_16
 *  0b0..BLK_SIZE_8x8 : Block size is 8x8
 *  0b1..BLK_SIZE_16x16 : Block size is 16x16
 */
#define PXP_INPUT_FETCH_CTRL_CH1_BLOCK_16(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_BLOCK_16_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_BLOCK_16_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_EN_MASK (0x8U)
#define PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_EN_SHIFT (3U)
/*! HANDSHAKE_EN - HANDSHAKE_EN
 *  0b0..Handshake with the store engine is disabled
 *  0b1..Handshake with the store engine is enabled
 */
#define PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_BYPASS_PIXEL_EN_MASK (0x10U)
#define PXP_INPUT_FETCH_CTRL_CH1_BYPASS_PIXEL_EN_SHIFT (4U)
/*! BYPASS_PIXEL_EN - BYPASS_PIXEL_EN
 *  0b0..Channel 1 is from memory
 *  0b1..Channel 1 is from previous process engine
 */
#define PXP_INPUT_FETCH_CTRL_CH1_BYPASS_PIXEL_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_BYPASS_PIXEL_EN_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_BYPASS_PIXEL_EN_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_RSVD4_MASK      (0x1E0U)
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD4_SHIFT     (5U)
/*! RSVD4 - RSVD4 */
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD4(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_RSVD4_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_RSVD4_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_HFLIP_MASK      (0x200U)
#define PXP_INPUT_FETCH_CTRL_CH1_HFLIP_SHIFT     (9U)
/*! HFLIP - HFLIP
 *  0b0..HFLIP disable
 *  0b1..VFLIP enable
 */
#define PXP_INPUT_FETCH_CTRL_CH1_HFLIP(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_HFLIP_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_HFLIP_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_VFLIP_MASK      (0x400U)
#define PXP_INPUT_FETCH_CTRL_CH1_VFLIP_SHIFT     (10U)
/*! VFLIP - VFLIP
 *  0b0..VFLIP disable
 *  0b1..VFLIP enable
 */
#define PXP_INPUT_FETCH_CTRL_CH1_VFLIP(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_VFLIP_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_VFLIP_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_RSVD3_MASK      (0x800U)
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD3_SHIFT     (11U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD3(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_RSVD3_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_RSVD3_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_ROTATION_ANGLE_MASK (0x3000U)
#define PXP_INPUT_FETCH_CTRL_CH1_ROTATION_ANGLE_SHIFT (12U)
/*! ROTATION_ANGLE - ROTATION_ANGLE
 *  0b00..ROT_0 : Rotate image by 0 degrees.
 *  0b01..ROT_90 : Rotate image by 90 degrees.
 *  0b10..ROT_180 : Rotate image by 180 degrees.
 *  0b11..ROT_270 : Rotate image by 270 degrees.
 */
#define PXP_INPUT_FETCH_CTRL_CH1_ROTATION_ANGLE(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_ROTATION_ANGLE_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_ROTATION_ANGLE_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_RSVD2_MASK      (0xC000U)
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD2_SHIFT     (14U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD2(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_RSVD2_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_RSVD2_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_RD_NUM_BYTES_MASK (0x30000U)
#define PXP_INPUT_FETCH_CTRL_CH1_RD_NUM_BYTES_SHIFT (16U)
/*! RD_NUM_BYTES - RD_NUM_BYTES
 *  0b00..NUM_8_BYTES : 8 bytes.
 *  0b01..NUM_16_BYTES : 16 bytes.
 *  0b10..NUM_32_BYTES : 32 bytes.
 *  0b11..NUM_64_BYTES : 64 bytes.
 */
#define PXP_INPUT_FETCH_CTRL_CH1_RD_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_RD_NUM_BYTES_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_RD_NUM_BYTES_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_RSVD1_MASK      (0xFC0000U)
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD1_SHIFT     (18U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD1(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_RSVD1_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_RSVD1_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_SCAN_LINE_NUM_MASK (0x3000000U)
#define PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_SCAN_LINE_NUM_SHIFT (24U)
/*! HANDSHAKE_SCAN_LINE_NUM - HANDSHAKE_SCAN_LINE_NUM
 *  0b00..1 line.
 *  0b01..8 lines
 *  0b10..16 lines
 *  0b11..16 lines
 */
#define PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_SCAN_LINE_NUM(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_SCAN_LINE_NUM_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_HANDSHAKE_SCAN_LINE_NUM_MASK)

#define PXP_INPUT_FETCH_CTRL_CH1_RSVD0_MASK      (0xFC000000U)
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD0_SHIFT     (26U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_CTRL_CH1_RSVD0(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_CTRL_CH1_RSVD0_SHIFT)) & PXP_INPUT_FETCH_CTRL_CH1_RSVD0_MASK)
/*! @} */

/*! @name INPUT_FETCH_STATUS_CH0 - Input Fetch Status Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_X_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_X_SHIFT (0U)
/*! PREFETCH_BLOCK_X - PREFETCH_BLOCK_X */
#define PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_X_SHIFT)) & PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_X_MASK)

#define PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_Y_SHIFT (16U)
/*! PREFETCH_BLOCK_Y - PREFETCH_BLOCK_Y */
#define PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_Y_SHIFT)) & PXP_INPUT_FETCH_STATUS_CH0_PREFETCH_BLOCK_Y_MASK)
/*! @} */

/*! @name INPUT_FETCH_STATUS_CH1 - Input Fetch Status Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_X_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_X_SHIFT (0U)
/*! PREFETCH_BLOCK_X - PREFETCH_BLOCK_X */
#define PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_X_SHIFT)) & PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_X_MASK)

#define PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_Y_SHIFT (16U)
/*! PREFETCH_BLOCK_Y - PREFETCH_BLOCK_Y */
#define PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_Y_SHIFT)) & PXP_INPUT_FETCH_STATUS_CH1_PREFETCH_BLOCK_Y_MASK)
/*! @} */

/*! @name INPUT_FETCH_ACTIVE_SIZE_ULC_CH0 - Input Fetch Active Size ULC Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_X_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_X_SHIFT (0U)
/*! ACTIVE_SIZE_ULC_X - ACTIVE_SIZE_ULC_X */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_X_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_X_MASK)

#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_Y_SHIFT (16U)
/*! ACTIVE_SIZE_ULC_Y - ACTIVE_SIZE_ULC_Y */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_Y_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH0_ACTIVE_SIZE_ULC_Y_MASK)
/*! @} */

/*! @name INPUT_FETCH_ACTIVE_SIZE_LRC_CH0 - Input Fetch Active Size LRC Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_X_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_X_SHIFT (0U)
/*! ACTIVE_SIZE_LRC_X - ACTIVE_SIZE_LRC_X */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_X_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_X_MASK)

#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_Y_SHIFT (16U)
/*! ACTIVE_SIZE_LRC_Y - ACTIVE_SIZE_LRC_Y */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_Y_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH0_ACTIVE_SIZE_LRC_Y_MASK)
/*! @} */

/*! @name INPUT_FETCH_ACTIVE_SIZE_ULC_CH1 - Input Fetch Active Size ULC Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_X_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_X_SHIFT (0U)
/*! ACTIVE_SIZE_ULC_X - ACTIVE_SIZE_ULC_X */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_X_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_X_MASK)

#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_Y_SHIFT (16U)
/*! ACTIVE_SIZE_ULC_Y - ACTIVE_SIZE_ULC_Y */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_Y_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_ULC_CH1_ACTIVE_SIZE_ULC_Y_MASK)
/*! @} */

/*! @name INPUT_FETCH_ACTIVE_SIZE_LRC_CH1 - Input Fetch Active Size LRC Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_X_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_X_SHIFT (0U)
/*! ACTIVE_SIZE_LRC_X - ACTIVE_SIZE_LRC_X */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_X_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_X_MASK)

#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_Y_SHIFT (16U)
/*! ACTIVE_SIZE_LRC_Y - ACTIVE_SIZE_LRC_Y */
#define PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_Y_SHIFT)) & PXP_INPUT_FETCH_ACTIVE_SIZE_LRC_CH1_ACTIVE_SIZE_LRC_Y_MASK)
/*! @} */

/*! @name INPUT_FETCH_SIZE_CH0 - Input Fetch Size Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_WIDTH_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_WIDTH_SHIFT (0U)
/*! INPUT_TOTAL_WIDTH - INPUT_TOTAL_WIDTH */
#define PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_WIDTH_SHIFT)) & PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_WIDTH_MASK)

#define PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_HEIGHT_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_HEIGHT_SHIFT (16U)
/*! INPUT_TOTAL_HEIGHT - INPUT_TOTAL_HEIGHT */
#define PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_HEIGHT_SHIFT)) & PXP_INPUT_FETCH_SIZE_CH0_INPUT_TOTAL_HEIGHT_MASK)
/*! @} */

/*! @name INPUT_FETCH_SIZE_CH1 - Input Fetch Size Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_WIDTH_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_WIDTH_SHIFT (0U)
/*! INPUT_TOTAL_WIDTH - INPUT_TOTAL_WIDTH */
#define PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_WIDTH_SHIFT)) & PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_WIDTH_MASK)

#define PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_HEIGHT_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_HEIGHT_SHIFT (16U)
/*! INPUT_TOTAL_HEIGHT - INPUT_TOTAL_HEIGHT */
#define PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_HEIGHT_SHIFT)) & PXP_INPUT_FETCH_SIZE_CH1_INPUT_TOTAL_HEIGHT_MASK)
/*! @} */

/*! @name INPUT_FETCH_BACKGROUND_COLOR_CH0 - Input Fetch Background Color Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_BACKGROUND_COLOR_CH0_BACKGROUND_COLOR_MASK (0xFFFFFFFFU)
#define PXP_INPUT_FETCH_BACKGROUND_COLOR_CH0_BACKGROUND_COLOR_SHIFT (0U)
/*! BACKGROUND_COLOR - BACKGROUND_COLOR */
#define PXP_INPUT_FETCH_BACKGROUND_COLOR_CH0_BACKGROUND_COLOR(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_BACKGROUND_COLOR_CH0_BACKGROUND_COLOR_SHIFT)) & PXP_INPUT_FETCH_BACKGROUND_COLOR_CH0_BACKGROUND_COLOR_MASK)
/*! @} */

/*! @name INPUT_FETCH_BACKGROUND_COLOR_CH1 - Input Fetch Background Color Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_BACKGROUND_COLOR_CH1_BACKGROUND_COLOR_MASK (0xFFFFFFFFU)
#define PXP_INPUT_FETCH_BACKGROUND_COLOR_CH1_BACKGROUND_COLOR_SHIFT (0U)
/*! BACKGROUND_COLOR - BACKGROUND_COLOR */
#define PXP_INPUT_FETCH_BACKGROUND_COLOR_CH1_BACKGROUND_COLOR(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_BACKGROUND_COLOR_CH1_BACKGROUND_COLOR_SHIFT)) & PXP_INPUT_FETCH_BACKGROUND_COLOR_CH1_BACKGROUND_COLOR_MASK)
/*! @} */

/*! @name INPUT_FETCH_PITCH - Input Fetch Pitch Register */
/*! @{ */

#define PXP_INPUT_FETCH_PITCH_CH0_INPUT_PITCH_MASK (0xFFFFU)
#define PXP_INPUT_FETCH_PITCH_CH0_INPUT_PITCH_SHIFT (0U)
/*! CH0_INPUT_PITCH - CH0_INPUT_PITCH */
#define PXP_INPUT_FETCH_PITCH_CH0_INPUT_PITCH(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_PITCH_CH0_INPUT_PITCH_SHIFT)) & PXP_INPUT_FETCH_PITCH_CH0_INPUT_PITCH_MASK)

#define PXP_INPUT_FETCH_PITCH_CH1_INPUT_PITCH_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_PITCH_CH1_INPUT_PITCH_SHIFT (16U)
/*! CH1_INPUT_PITCH - CH1_INPUT_PITCH */
#define PXP_INPUT_FETCH_PITCH_CH1_INPUT_PITCH(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_PITCH_CH1_INPUT_PITCH_SHIFT)) & PXP_INPUT_FETCH_PITCH_CH1_INPUT_PITCH_MASK)
/*! @} */

/*! @name INPUT_FETCH_SHIFT_CTRL_CH0 - Input Fetch Shift Control Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_INPUT_ACTIVE_BPP_MASK (0x3U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_INPUT_ACTIVE_BPP_SHIFT (0U)
/*! INPUT_ACTIVE_BPP - INPUT_ACTIVE_BPP
 *  0b00..8 bits
 *  0b01..16 bits
 *  0b10..32 bits
 *  0b11..64 bits
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_INPUT_ACTIVE_BPP(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH0_INPUT_ACTIVE_BPP_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH0_INPUT_ACTIVE_BPP_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD1_MASK (0xFCU)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD1_SHIFT (2U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD1(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD1_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_FORMAT_MASK (0x700U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_FORMAT_SHIFT (8U)
/*! EXPAND_FORMAT - EXPAND_FORMAT
 *  0b000..RGB 565
 *  0b001..RGB 555
 *  0b010..ARGB 1555
 *  0b011..RGB 444
 *  0b100..ARGB 4444
 *  0b101..YUYV/YVYU
 *  0b110..UYVY/VYUY
 *  0b111..YUV422_2P
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_FORMAT_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_FORMAT_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_EN_MASK (0x800U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_EN_SHIFT (11U)
/*! EXPAND_EN - EXPAND_EN
 *  0b0..channel0 format expanding disable
 *  0b1..channel0 format expanding enable
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_EN_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH0_EXPAND_EN_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_SHIFT_BYPASS_MASK (0x1000U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_SHIFT_BYPASS_SHIFT (12U)
/*! SHIFT_BYPASS - SHIFT_BYPASS
 *  0b0..channel0 data will do shift function
 *  0b1..channel0 will bypass shift function
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_SHIFT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH0_SHIFT_BYPASS_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH0_SHIFT_BYPASS_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD0_MASK (0xFFFFE000U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD0_SHIFT (13U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD0(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH0_RSVD0_MASK)
/*! @} */

/*! @name INPUT_FETCH_SHIFT_CTRL_CH1 - Input Fetch Shift Control Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_INPUT_ACTIVE_BPP_MASK (0x3U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_INPUT_ACTIVE_BPP_SHIFT (0U)
/*! INPUT_ACTIVE_BPP - INPUT_ACTIVE_BPP
 *  0b00..8 bits
 *  0b01..16 bits
 *  0b10..32 bits
 *  0b11..32 bits
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_INPUT_ACTIVE_BPP(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH1_INPUT_ACTIVE_BPP_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH1_INPUT_ACTIVE_BPP_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD1_MASK (0xFCU)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD1_SHIFT (2U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD1(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD1_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_FORMAT_MASK (0x700U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_FORMAT_SHIFT (8U)
/*! EXPAND_FORMAT - EXPAND_FORMAT
 *  0b000..RGB 565
 *  0b001..RGB 555
 *  0b010..ARGB 1555
 *  0b011..RGB 444
 *  0b100..ARGB 4444
 *  0b101..YUYV/YVYU
 *  0b110..UYVY/VYUY
 *  0b111..YUV422_2P
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_FORMAT_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_FORMAT_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_EN_MASK (0x800U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_EN_SHIFT (11U)
/*! EXPAND_EN - EXPAND_EN
 *  0b0..channel1 format expanding disable
 *  0b1..channel1 format expanding enable
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_EN_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH1_EXPAND_EN_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_SHIFT_BYPASS_MASK (0x1000U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_SHIFT_BYPASS_SHIFT (12U)
/*! SHIFT_BYPASS - SHIFT_BYPASS
 *  0b0..channel1 data will do shift function
 *  0b1..channel1 will bypass shift function
 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_SHIFT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH1_SHIFT_BYPASS_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH1_SHIFT_BYPASS_MASK)

#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD0_MASK (0xFFFFE000U)
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD0_SHIFT (13U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD0(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_CTRL_CH1_RSVD0_MASK)
/*! @} */

/*! @name INPUT_FETCH_SHIFT_OFFSET_CH0 - Input Fetch Shift Offset Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET0_MASK (0x1FU)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET0_SHIFT (0U)
/*! OFFSET0 - OFFSET0 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET0_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD3_MASK (0xE0U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD3_SHIFT (5U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD3_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD3_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET1_MASK (0x1F00U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET1_SHIFT (8U)
/*! OFFSET1 - OFFSET1 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET1_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD2_MASK (0xE000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD2_SHIFT (13U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD2_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD2_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET2_MASK (0x1F0000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET2_SHIFT (16U)
/*! OFFSET2 - OFFSET2 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET2_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET2_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD1_MASK (0xE00000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD1_SHIFT (21U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD1_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET3_MASK (0x1F000000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET3_SHIFT (24U)
/*! OFFSET3 - OFFSET3 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET3_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_OFFSET3_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD0_MASK (0xE0000000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD0_SHIFT (29U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH0_RSVD0_MASK)
/*! @} */

/*! @name INPUT_FETCH_SHIFT_OFFSET_CH1 - Input Fetch Shift Offset Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET0_MASK (0x1FU)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET0_SHIFT (0U)
/*! OFFSET0 - OFFSET0 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET0_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD3_MASK (0xE0U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD3_SHIFT (5U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD3_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD3_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET1_MASK (0x1F00U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET1_SHIFT (8U)
/*! OFFSET1 - OFFSET1 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET1_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD2_MASK (0xE000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD2_SHIFT (13U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD2_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD2_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET2_MASK (0x1F0000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET2_SHIFT (16U)
/*! OFFSET2 - OFFSET2 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET2_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET2_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD1_MASK (0xE00000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD1_SHIFT (21U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD1_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET3_MASK (0x1F000000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET3_SHIFT (24U)
/*! OFFSET3 - OFFSET3 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET3_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_OFFSET3_MASK)

#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD0_MASK (0xE0000000U)
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD0_SHIFT (29U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_OFFSET_CH1_RSVD0_MASK)
/*! @} */

/*! @name INPUT_FETCH_SHIFT_WIDTH_CH0 - Input Fetch Shift Width Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH0_MASK (0xFU)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH0_SHIFT (0U)
/*! WIDTH0 - WIDTH0 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH0_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH1_MASK (0xF0U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH1_SHIFT (4U)
/*! WIDTH1 - WIDTH1 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH1_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH2_MASK (0xF00U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH2_SHIFT (8U)
/*! WIDTH2 - WIDTH2 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH2_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH2_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH3_MASK (0xF000U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH3_SHIFT (12U)
/*! WIDTH3 - WIDTH3 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH3_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_WIDTH3_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_RSVD0_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_RSVD0_SHIFT (16U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_RSVD0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH0_RSVD0_MASK)
/*! @} */

/*! @name INPUT_FETCH_SHIFT_WIDTH_CH1 - Input Fetch Shift Width Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH0_MASK (0xFU)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH0_SHIFT (0U)
/*! WIDTH0 - WIDTH0 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH0_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH1_MASK (0xF0U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH1_SHIFT (4U)
/*! WIDTH1 - WIDTH1 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH1_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH1_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH2_MASK (0xF00U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH2_SHIFT (8U)
/*! WIDTH2 - WIDTH2 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH2_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH2_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH3_MASK (0xF000U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH3_SHIFT (12U)
/*! WIDTH3 - WIDTH3 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH3_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_WIDTH3_MASK)

#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_RSVD0_MASK (0xFFFF0000U)
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_RSVD0_SHIFT (16U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_RSVD0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_RSVD0_SHIFT)) & PXP_INPUT_FETCH_SHIFT_WIDTH_CH1_RSVD0_MASK)
/*! @} */

/*! @name INPUT_FETCH_ADDR_0_CH0 - Input Fetch Address 0 Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ADDR_0_CH0_INPUT_BASE_ADDR0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_FETCH_ADDR_0_CH0_INPUT_BASE_ADDR0_SHIFT (0U)
/*! INPUT_BASE_ADDR0 - INPUT_BASE_ADDR0 */
#define PXP_INPUT_FETCH_ADDR_0_CH0_INPUT_BASE_ADDR0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ADDR_0_CH0_INPUT_BASE_ADDR0_SHIFT)) & PXP_INPUT_FETCH_ADDR_0_CH0_INPUT_BASE_ADDR0_MASK)
/*! @} */

/*! @name INPUT_FETCH_ADDR_1_CH0 - Input Fetch Address 1 Channel 0 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ADDR_1_CH0_INPUT_BASE_ADDR1_MASK (0xFFFFFFFFU)
#define PXP_INPUT_FETCH_ADDR_1_CH0_INPUT_BASE_ADDR1_SHIFT (0U)
/*! INPUT_BASE_ADDR1 - INPUT_BASE_ADDR1 */
#define PXP_INPUT_FETCH_ADDR_1_CH0_INPUT_BASE_ADDR1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ADDR_1_CH0_INPUT_BASE_ADDR1_SHIFT)) & PXP_INPUT_FETCH_ADDR_1_CH0_INPUT_BASE_ADDR1_MASK)
/*! @} */

/*! @name INPUT_FETCH_ADDR_0_CH1 - Input Fetch Address 0 Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ADDR_0_CH1_INPUT_BASE_ADDR0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_FETCH_ADDR_0_CH1_INPUT_BASE_ADDR0_SHIFT (0U)
/*! INPUT_BASE_ADDR0 - INPUT_BASE_ADDR0 */
#define PXP_INPUT_FETCH_ADDR_0_CH1_INPUT_BASE_ADDR0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ADDR_0_CH1_INPUT_BASE_ADDR0_SHIFT)) & PXP_INPUT_FETCH_ADDR_0_CH1_INPUT_BASE_ADDR0_MASK)
/*! @} */

/*! @name INPUT_FETCH_ADDR_1_CH1 - Input Fetch Address 1 Channel 1 Register */
/*! @{ */

#define PXP_INPUT_FETCH_ADDR_1_CH1_INPUT_BASE_ADDR1_MASK (0xFFFFFFFFU)
#define PXP_INPUT_FETCH_ADDR_1_CH1_INPUT_BASE_ADDR1_SHIFT (0U)
/*! INPUT_BASE_ADDR1 - INPUT_BASE_ADDR1 */
#define PXP_INPUT_FETCH_ADDR_1_CH1_INPUT_BASE_ADDR1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_FETCH_ADDR_1_CH1_INPUT_BASE_ADDR1_SHIFT)) & PXP_INPUT_FETCH_ADDR_1_CH1_INPUT_BASE_ADDR1_MASK)
/*! @} */

/*! @name INPUT_STORE_CTRL_CH0 - Input Store Control Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_CTRL_CH0_CH_EN_MASK      (0x1U)
#define PXP_INPUT_STORE_CTRL_CH0_CH_EN_SHIFT     (0U)
/*! CH_EN - CH_EN
 *  0b0..Store function is disable
 *  0b1..Store function is enable
 */
#define PXP_INPUT_STORE_CTRL_CH0_CH_EN(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_CH_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_CH_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_BLOCK_EN_MASK   (0x2U)
#define PXP_INPUT_STORE_CTRL_CH0_BLOCK_EN_SHIFT  (1U)
/*! BLOCK_EN - BLOCK_EN
 *  0b0..Store in scan mode
 *  0b1..Store in block mode
 */
#define PXP_INPUT_STORE_CTRL_CH0_BLOCK_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_BLOCK_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_BLOCK_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_BLOCK_16_MASK   (0x4U)
#define PXP_INPUT_STORE_CTRL_CH0_BLOCK_16_SHIFT  (2U)
/*! BLOCK_16 - BLOCK_16
 *  0b0..BLK_SIZE_8x8 : Block size is 8x8
 *  0b1..BLK_SIZE_16x16 : Block size is 16x16
 */
#define PXP_INPUT_STORE_CTRL_CH0_BLOCK_16(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_BLOCK_16_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_BLOCK_16_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_HANDSHAKE_EN_MASK (0x8U)
#define PXP_INPUT_STORE_CTRL_CH0_HANDSHAKE_EN_SHIFT (3U)
/*! HANDSHAKE_EN - HANDSHAKE_EN
 *  0b0..Handshake with the prefetch engine is disabled
 *  0b1..Handshake with the prefetch engine is enabled
 */
#define PXP_INPUT_STORE_CTRL_CH0_HANDSHAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_HANDSHAKE_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_HANDSHAKE_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_ARRAY_EN_MASK   (0x10U)
#define PXP_INPUT_STORE_CTRL_CH0_ARRAY_EN_SHIFT  (4U)
/*! ARRAY_EN - ARRAY_EN
 *  0b0..Array Handshake Disabled
 *  0b1..Array Handshake Enabled
 */
#define PXP_INPUT_STORE_CTRL_CH0_ARRAY_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_ARRAY_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_ARRAY_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_ARRAY_LINE_NUM_MASK (0x60U)
#define PXP_INPUT_STORE_CTRL_CH0_ARRAY_LINE_NUM_SHIFT (5U)
/*! ARRAY_LINE_NUM - ARRAY_LINE_NUM
 *  0b00..Using 1x1 Array
 *  0b01..Using 3x3 Array
 *  0b10..Using 5x5 Array
 *  0b11..Using 5x5 Array
 */
#define PXP_INPUT_STORE_CTRL_CH0_ARRAY_LINE_NUM(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_ARRAY_LINE_NUM_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_ARRAY_LINE_NUM_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_RSVD3_MASK      (0x80U)
#define PXP_INPUT_STORE_CTRL_CH0_RSVD3_SHIFT     (7U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_STORE_CTRL_CH0_RSVD3(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_RSVD3_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_RSVD3_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_STORE_BYPASS_EN_MASK (0x100U)
#define PXP_INPUT_STORE_CTRL_CH0_STORE_BYPASS_EN_SHIFT (8U)
/*! STORE_BYPASS_EN - STORE_BYPASS_EN
 *  0b0..store bypass mode disable.
 *  0b1..store bypass mode enable. Data will bypass to store output.
 */
#define PXP_INPUT_STORE_CTRL_CH0_STORE_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_STORE_BYPASS_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_STORE_BYPASS_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_STORE_MEMORY_EN_MASK (0x200U)
#define PXP_INPUT_STORE_CTRL_CH0_STORE_MEMORY_EN_SHIFT (9U)
/*! STORE_MEMORY_EN - STORE_MEMORY_EN
 *  0b0..store memory mode disable.
 *  0b1..store memory mode enable. Data will store to memory
 */
#define PXP_INPUT_STORE_CTRL_CH0_STORE_MEMORY_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_STORE_MEMORY_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_STORE_MEMORY_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_PACK_IN_SEL_MASK (0x400U)
#define PXP_INPUT_STORE_CTRL_CH0_PACK_IN_SEL_SHIFT (10U)
/*! PACK_IN_SEL - PACK_IN_SEL
 *  0b0..select 64 shift out data to pack
 *  0b1..select low 32 bit shift out data to pack
 */
#define PXP_INPUT_STORE_CTRL_CH0_PACK_IN_SEL(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_PACK_IN_SEL_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_PACK_IN_SEL_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_FILL_DATA_EN_MASK (0x800U)
#define PXP_INPUT_STORE_CTRL_CH0_FILL_DATA_EN_SHIFT (11U)
/*! FILL_DATA_EN - FILL_DATA_EN
 *  0b0..Fill data mode disable.
 *  0b1..Fill data mode enable. When using fill_data mode, store_engine will store fixed data defined in fill_data register
 */
#define PXP_INPUT_STORE_CTRL_CH0_FILL_DATA_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_FILL_DATA_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_FILL_DATA_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_RSVD2_MASK      (0xF000U)
#define PXP_INPUT_STORE_CTRL_CH0_RSVD2_SHIFT     (12U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_STORE_CTRL_CH0_RSVD2(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_RSVD2_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_RSVD2_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_WR_NUM_BYTES_MASK (0x30000U)
#define PXP_INPUT_STORE_CTRL_CH0_WR_NUM_BYTES_SHIFT (16U)
/*! WR_NUM_BYTES - WR_NUM_BYTES
 *  0b00..NUM_8_BYTES : 8 bytes
 *  0b01..NUM_16_BYTES : 16 bytes
 *  0b10..NUM_32_BYTES : 32 bytes
 *  0b11..NUM_64_BYTES : 64 bytes
 */
#define PXP_INPUT_STORE_CTRL_CH0_WR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_WR_NUM_BYTES_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_WR_NUM_BYTES_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_RSVD1_MASK      (0xFC0000U)
#define PXP_INPUT_STORE_CTRL_CH0_RSVD1_SHIFT     (18U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_STORE_CTRL_CH0_RSVD1(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_RSVD1_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_RSVD1_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_COMBINE_2CHANNEL_MASK (0x1000000U)
#define PXP_INPUT_STORE_CTRL_CH0_COMBINE_2CHANNEL_SHIFT (24U)
/*! COMBINE_2CHANNEL - COMBINE_2CHANNEL
 *  0b0..combine 2 channel disable
 *  0b1..combine 2 channel enable
 */
#define PXP_INPUT_STORE_CTRL_CH0_COMBINE_2CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_COMBINE_2CHANNEL_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_COMBINE_2CHANNEL_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_RSVD0_MASK      (0x7E000000U)
#define PXP_INPUT_STORE_CTRL_CH0_RSVD0_SHIFT     (25U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_CTRL_CH0_RSVD0(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_RSVD0_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_RSVD0_MASK)

#define PXP_INPUT_STORE_CTRL_CH0_ARBIT_EN_MASK   (0x80000000U)
#define PXP_INPUT_STORE_CTRL_CH0_ARBIT_EN_SHIFT  (31U)
/*! ARBIT_EN - ARBIT_EN
 *  0b0..Arbitration disable. If using 2 channels, will output 2 axi bus sets
 *  0b1..Arbitration enable. If using 2 channel, will only output 1 axi bus sets
 */
#define PXP_INPUT_STORE_CTRL_CH0_ARBIT_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH0_ARBIT_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH0_ARBIT_EN_MASK)
/*! @} */

/*! @name INPUT_STORE_CTRL_CH1 - Input Store Control Channel 1 Register */
/*! @{ */

#define PXP_INPUT_STORE_CTRL_CH1_CH_EN_MASK      (0x1U)
#define PXP_INPUT_STORE_CTRL_CH1_CH_EN_SHIFT     (0U)
/*! CH_EN - CH_EN
 *  0b0..Store function is disable
 *  0b1..Store function is enable
 */
#define PXP_INPUT_STORE_CTRL_CH1_CH_EN(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_CH_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_CH_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_BLOCK_EN_MASK   (0x2U)
#define PXP_INPUT_STORE_CTRL_CH1_BLOCK_EN_SHIFT  (1U)
/*! BLOCK_EN - BLOCK_EN
 *  0b0..Store in scan mode
 *  0b1..Store in block mode
 */
#define PXP_INPUT_STORE_CTRL_CH1_BLOCK_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_BLOCK_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_BLOCK_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_BLOCK_16_MASK   (0x4U)
#define PXP_INPUT_STORE_CTRL_CH1_BLOCK_16_SHIFT  (2U)
/*! BLOCK_16 - BLOCK_16
 *  0b0..BLK_SIZE_8x8 : Block size is 8x8
 *  0b1..BLK_SIZE_16x16 : Block size is 16x16
 */
#define PXP_INPUT_STORE_CTRL_CH1_BLOCK_16(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_BLOCK_16_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_BLOCK_16_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_HANDSHAKE_EN_MASK (0x8U)
#define PXP_INPUT_STORE_CTRL_CH1_HANDSHAKE_EN_SHIFT (3U)
/*! HANDSHAKE_EN - HANDSHAKE_EN
 *  0b0..Handshake with the fetch engine is disabled
 *  0b1..Handshake with the fetch engine is enabled
 */
#define PXP_INPUT_STORE_CTRL_CH1_HANDSHAKE_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_HANDSHAKE_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_HANDSHAKE_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_ARRAY_EN_MASK   (0x10U)
#define PXP_INPUT_STORE_CTRL_CH1_ARRAY_EN_SHIFT  (4U)
/*! ARRAY_EN - ARRAY_EN
 *  0b0..Array Handshake Disabled
 *  0b1..Array Handshake Enabled
 */
#define PXP_INPUT_STORE_CTRL_CH1_ARRAY_EN(x)     (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_ARRAY_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_ARRAY_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_ARRAY_LINE_NUM_MASK (0x60U)
#define PXP_INPUT_STORE_CTRL_CH1_ARRAY_LINE_NUM_SHIFT (5U)
/*! ARRAY_LINE_NUM - ARRAY_LINE_NUM
 *  0b00..Using 1x1 Array
 *  0b01..Using 3x3 Array
 *  0b10..Using 5x5 Array
 *  0b11..Using 5x5 Array
 */
#define PXP_INPUT_STORE_CTRL_CH1_ARRAY_LINE_NUM(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_ARRAY_LINE_NUM_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_ARRAY_LINE_NUM_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_RSVD3_MASK      (0x80U)
#define PXP_INPUT_STORE_CTRL_CH1_RSVD3_SHIFT     (7U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_STORE_CTRL_CH1_RSVD3(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_RSVD3_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_RSVD3_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_STORE_BYPASS_EN_MASK (0x100U)
#define PXP_INPUT_STORE_CTRL_CH1_STORE_BYPASS_EN_SHIFT (8U)
/*! STORE_BYPASS_EN - STORE_BYPASS_EN
 *  0b0..store bypass mode disable.
 *  0b1..store bypass mode enable. Data will bypass to store output.
 */
#define PXP_INPUT_STORE_CTRL_CH1_STORE_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_STORE_BYPASS_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_STORE_BYPASS_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_STORE_MEMORY_EN_MASK (0x200U)
#define PXP_INPUT_STORE_CTRL_CH1_STORE_MEMORY_EN_SHIFT (9U)
/*! STORE_MEMORY_EN - STORE_MEMORY_EN
 *  0b0..store memory mode disable.
 *  0b1..store memory mode enable. Data will store to memory.
 */
#define PXP_INPUT_STORE_CTRL_CH1_STORE_MEMORY_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_STORE_MEMORY_EN_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_STORE_MEMORY_EN_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_PACK_IN_SEL_MASK (0x400U)
#define PXP_INPUT_STORE_CTRL_CH1_PACK_IN_SEL_SHIFT (10U)
/*! PACK_IN_SEL - PACK_IN_SEL
 *  0b0..select 64 shift out data to pack
 *  0b1..select channel 0 high 32 bit shift out data to pack
 */
#define PXP_INPUT_STORE_CTRL_CH1_PACK_IN_SEL(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_PACK_IN_SEL_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_PACK_IN_SEL_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_RSVD1_MASK      (0xF800U)
#define PXP_INPUT_STORE_CTRL_CH1_RSVD1_SHIFT     (11U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_STORE_CTRL_CH1_RSVD1(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_RSVD1_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_RSVD1_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_WR_NUM_BYTES_MASK (0x30000U)
#define PXP_INPUT_STORE_CTRL_CH1_WR_NUM_BYTES_SHIFT (16U)
/*! WR_NUM_BYTES - WR_NUM_BYTES
 *  0b00..NUM_8_BYTES : 8 bytes
 *  0b01..NUM_16_BYTES : 16 bytes
 *  0b10..NUM_32_BYTES : 32 bytes
 *  0b11..NUM_64_BYTES : 64 bytes
 */
#define PXP_INPUT_STORE_CTRL_CH1_WR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_WR_NUM_BYTES_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_WR_NUM_BYTES_MASK)

#define PXP_INPUT_STORE_CTRL_CH1_RSVD0_MASK      (0xFFFC0000U)
#define PXP_INPUT_STORE_CTRL_CH1_RSVD0_SHIFT     (18U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_CTRL_CH1_RSVD0(x)        (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_CTRL_CH1_RSVD0_SHIFT)) & PXP_INPUT_STORE_CTRL_CH1_RSVD0_MASK)
/*! @} */

/*! @name INPUT_STORE_STATUS_CH0 - Input Store Status Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_X_MASK (0xFFFFU)
#define PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_X_SHIFT (0U)
/*! STORE_BLOCK_X - STORE_BLOCK_X */
#define PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_X_SHIFT)) & PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_X_MASK)

#define PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_Y_SHIFT (16U)
/*! STORE_BLOCK_Y - STORE_BLOCK_Y */
#define PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_Y_SHIFT)) & PXP_INPUT_STORE_STATUS_CH0_STORE_BLOCK_Y_MASK)
/*! @} */

/*! @name INPUT_STORE_STATUS_CH1 - Input Store Status Channel 1 Register */
/*! @{ */

#define PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_X_MASK (0xFFFFU)
#define PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_X_SHIFT (0U)
/*! STORE_BLOCK_X - STORE_BLOCK_X */
#define PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_X(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_X_SHIFT)) & PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_X_MASK)

#define PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_Y_MASK (0xFFFF0000U)
#define PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_Y_SHIFT (16U)
/*! STORE_BLOCK_Y - STORE_BLOCK_Y */
#define PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_Y(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_Y_SHIFT)) & PXP_INPUT_STORE_STATUS_CH1_STORE_BLOCK_Y_MASK)
/*! @} */

/*! @name INPUT_STORE_SIZE_CH0 - Input Store Size Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_SIZE_CH0_OUT_WIDTH_MASK  (0xFFFFU)
#define PXP_INPUT_STORE_SIZE_CH0_OUT_WIDTH_SHIFT (0U)
/*! OUT_WIDTH - OUT_WIDTH */
#define PXP_INPUT_STORE_SIZE_CH0_OUT_WIDTH(x)    (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SIZE_CH0_OUT_WIDTH_SHIFT)) & PXP_INPUT_STORE_SIZE_CH0_OUT_WIDTH_MASK)

#define PXP_INPUT_STORE_SIZE_CH0_OUT_HEIGHT_MASK (0xFFFF0000U)
#define PXP_INPUT_STORE_SIZE_CH0_OUT_HEIGHT_SHIFT (16U)
/*! OUT_HEIGHT - OUT_HEIGHT */
#define PXP_INPUT_STORE_SIZE_CH0_OUT_HEIGHT(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SIZE_CH0_OUT_HEIGHT_SHIFT)) & PXP_INPUT_STORE_SIZE_CH0_OUT_HEIGHT_MASK)
/*! @} */

/*! @name INPUT_STORE_SIZE_CH1 - Input Store Size Channel 1 Register */
/*! @{ */

#define PXP_INPUT_STORE_SIZE_CH1_OUT_WIDTH_MASK  (0xFFFFU)
#define PXP_INPUT_STORE_SIZE_CH1_OUT_WIDTH_SHIFT (0U)
/*! OUT_WIDTH - OUT_WIDTH */
#define PXP_INPUT_STORE_SIZE_CH1_OUT_WIDTH(x)    (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SIZE_CH1_OUT_WIDTH_SHIFT)) & PXP_INPUT_STORE_SIZE_CH1_OUT_WIDTH_MASK)

#define PXP_INPUT_STORE_SIZE_CH1_OUT_HEIGHT_MASK (0xFFFF0000U)
#define PXP_INPUT_STORE_SIZE_CH1_OUT_HEIGHT_SHIFT (16U)
/*! OUT_HEIGHT - OUT_HEIGHT */
#define PXP_INPUT_STORE_SIZE_CH1_OUT_HEIGHT(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SIZE_CH1_OUT_HEIGHT_SHIFT)) & PXP_INPUT_STORE_SIZE_CH1_OUT_HEIGHT_MASK)
/*! @} */

/*! @name INPUT_STORE_PITCH - Input Store Pitch Register */
/*! @{ */

#define PXP_INPUT_STORE_PITCH_CH0_OUT_PITCH_MASK (0xFFFFU)
#define PXP_INPUT_STORE_PITCH_CH0_OUT_PITCH_SHIFT (0U)
/*! CH0_OUT_PITCH - CH0_OUT_PITCH */
#define PXP_INPUT_STORE_PITCH_CH0_OUT_PITCH(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_PITCH_CH0_OUT_PITCH_SHIFT)) & PXP_INPUT_STORE_PITCH_CH0_OUT_PITCH_MASK)

#define PXP_INPUT_STORE_PITCH_CH1_OUT_PITCH_MASK (0xFFFF0000U)
#define PXP_INPUT_STORE_PITCH_CH1_OUT_PITCH_SHIFT (16U)
/*! CH1_OUT_PITCH - CH1_OUT_PITCH */
#define PXP_INPUT_STORE_PITCH_CH1_OUT_PITCH(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_PITCH_CH1_OUT_PITCH_SHIFT)) & PXP_INPUT_STORE_PITCH_CH1_OUT_PITCH_MASK)
/*! @} */

/*! @name INPUT_STORE_SHIFT_CTRL_CH0 - Input Store Shift Control Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD2_MASK (0x3U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD2_SHIFT (0U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD2(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD2_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD2_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUTPUT_ACTIVE_BPP_MASK (0xCU)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUTPUT_ACTIVE_BPP_SHIFT (2U)
/*! OUTPUT_ACTIVE_BPP - OUTPUT_ACTIVE_BPP
 *  0b00..8 bits
 *  0b01..16 bits
 *  0b10..32 bits
 *  0b11..64 bits
 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUTPUT_ACTIVE_BPP(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUTPUT_ACTIVE_BPP_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUTPUT_ACTIVE_BPP_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_1P_EN_MASK (0x10U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_1P_EN_SHIFT (4U)
/*! OUT_YUV422_1P_EN - OUT_YUV422_1P_EN
 *  0b0..YUYV422 2 plane disabled.
 *  0b1..YUYV422 2 plane enabled.
 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_1P_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_1P_EN_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_1P_EN_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_2P_EN_MASK (0x20U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_2P_EN_SHIFT (5U)
/*! OUT_YUV422_2P_EN - OUT_YUV422_2P_EN
 *  0b0..YUYV422 2 plane disabled.
 *  0b1..YUYV422 2 plane enabled.
 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_2P_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_2P_EN_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH0_OUT_YUV422_2P_EN_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD1_MASK (0x40U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD1_SHIFT (6U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD1(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD1_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD1_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_SHIFT_BYPASS_MASK (0x80U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_SHIFT_BYPASS_SHIFT (7U)
/*! SHIFT_BYPASS - SHIFT_BYPASS
 *  0b0..data will do shift processing.
 *  0b1..data will bypass shift module.
 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_SHIFT_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH0_SHIFT_BYPASS_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH0_SHIFT_BYPASS_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD0_MASK (0xFFFFFF00U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD0_SHIFT (8U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD0(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD0_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH0_RSVD0_MASK)
/*! @} */

/*! @name INPUT_STORE_SHIFT_CTRL_CH1 - Input Store Shift Control Channel 1 Register */
/*! @{ */

#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD2_MASK (0x3U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD2_SHIFT (0U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD2(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD2_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD2_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUTPUT_ACTIVE_BPP_MASK (0xCU)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUTPUT_ACTIVE_BPP_SHIFT (2U)
/*! OUTPUT_ACTIVE_BPP - OUTPUT_ACTIVE_BPP
 *  0b00..8 bits
 *  0b01..16 bits
 *  0b10..32 bits
 *  0b11..32 bits
 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUTPUT_ACTIVE_BPP(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUTPUT_ACTIVE_BPP_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUTPUT_ACTIVE_BPP_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_1P_EN_MASK (0x10U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_1P_EN_SHIFT (4U)
/*! OUT_YUV422_1P_EN - OUT_YUV422_1P_EN
 *  0b0..YUYV422 2 plane disabled.
 *  0b1..YUYV422 2 plane enabled.
 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_1P_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_1P_EN_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_1P_EN_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_2P_EN_MASK (0x20U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_2P_EN_SHIFT (5U)
/*! OUT_YUV422_2P_EN - OUT_YUV422_2P_EN
 *  0b0..YUYV422 2 plane disabled.
 *  0b1..YUYV422 2 plane enabled.
 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_2P_EN(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_2P_EN_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH1_OUT_YUV422_2P_EN_MASK)

#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD0_MASK (0xFFFFFFC0U)
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD0_SHIFT (6U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD0(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD0_SHIFT)) & PXP_INPUT_STORE_SHIFT_CTRL_CH1_RSVD0_MASK)
/*! @} */

/*! @name INPUT_STORE_ADDR_0_CH0 - Input Store Address 0 Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_ADDR_0_CH0_OUT_BASE_ADDR0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_ADDR_0_CH0_OUT_BASE_ADDR0_SHIFT (0U)
/*! OUT_BASE_ADDR0 - OUT_BASE_ADDR0 */
#define PXP_INPUT_STORE_ADDR_0_CH0_OUT_BASE_ADDR0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_ADDR_0_CH0_OUT_BASE_ADDR0_SHIFT)) & PXP_INPUT_STORE_ADDR_0_CH0_OUT_BASE_ADDR0_MASK)
/*! @} */

/*! @name INPUT_STORE_ADDR_1_CH0 - Input Store Address 1 Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_ADDR_1_CH0_OUT_BASE_ADDR1_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_ADDR_1_CH0_OUT_BASE_ADDR1_SHIFT (0U)
/*! OUT_BASE_ADDR1 - OUT_BASE_ADDR1 */
#define PXP_INPUT_STORE_ADDR_1_CH0_OUT_BASE_ADDR1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_ADDR_1_CH0_OUT_BASE_ADDR1_SHIFT)) & PXP_INPUT_STORE_ADDR_1_CH0_OUT_BASE_ADDR1_MASK)
/*! @} */

/*! @name INPUT_STORE_FILL_DATA_CH0 - Input Store Fill Data Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_FILL_DATA_CH0_FILL_DATA_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_FILL_DATA_CH0_FILL_DATA_CH0_SHIFT (0U)
/*! FILL_DATA_CH0 - FILL_DATA_CH0 */
#define PXP_INPUT_STORE_FILL_DATA_CH0_FILL_DATA_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_FILL_DATA_CH0_FILL_DATA_CH0_SHIFT)) & PXP_INPUT_STORE_FILL_DATA_CH0_FILL_DATA_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_ADDR_0_CH1 - Input Store Address 0 Channel 1 Register */
/*! @{ */

#define PXP_INPUT_STORE_ADDR_0_CH1_OUT_BASE_ADDR0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_ADDR_0_CH1_OUT_BASE_ADDR0_SHIFT (0U)
/*! OUT_BASE_ADDR0 - OUT_BASE_ADDR0 */
#define PXP_INPUT_STORE_ADDR_0_CH1_OUT_BASE_ADDR0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_ADDR_0_CH1_OUT_BASE_ADDR0_SHIFT)) & PXP_INPUT_STORE_ADDR_0_CH1_OUT_BASE_ADDR0_MASK)
/*! @} */

/*! @name INPUT_STORE_ADDR_1_CH1 - Input Store Address 1 Channel 1 Register */
/*! @{ */

#define PXP_INPUT_STORE_ADDR_1_CH1_OUT_BASE_ADDR1_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_ADDR_1_CH1_OUT_BASE_ADDR1_SHIFT (0U)
/*! OUT_BASE_ADDR1 - OUT_BASE_ADDR1 */
#define PXP_INPUT_STORE_ADDR_1_CH1_OUT_BASE_ADDR1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_ADDR_1_CH1_OUT_BASE_ADDR1_SHIFT)) & PXP_INPUT_STORE_ADDR_1_CH1_OUT_BASE_ADDR1_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK0_H_CH0 - Input Store Data Mask 0 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK0_H_CH0_D_MASK0_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK0_H_CH0_D_MASK0_H_CH0_SHIFT (0U)
/*! D_MASK0_H_CH0 - D_MASK0_H_CH0 */
#define PXP_INPUT_STORE_D_MASK0_H_CH0_D_MASK0_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK0_H_CH0_D_MASK0_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK0_H_CH0_D_MASK0_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK0_L_CH0 - Input Store Data Mask 0 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK0_L_CH0_D_MASK0_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK0_L_CH0_D_MASK0_L_CH0_SHIFT (0U)
/*! D_MASK0_L_CH0 - D_MASK0_L_CH0 */
#define PXP_INPUT_STORE_D_MASK0_L_CH0_D_MASK0_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK0_L_CH0_D_MASK0_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK0_L_CH0_D_MASK0_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK1_H_CH0 - Input Store Data Mask 1 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK1_H_CH0_D_MASK1_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK1_H_CH0_D_MASK1_H_CH0_SHIFT (0U)
/*! D_MASK1_H_CH0 - D_MASK1_H_CH0 */
#define PXP_INPUT_STORE_D_MASK1_H_CH0_D_MASK1_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK1_H_CH0_D_MASK1_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK1_H_CH0_D_MASK1_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK1_L_CH0 - Input Store Data Mask 1 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK1_L_CH0_D_MASK1_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK1_L_CH0_D_MASK1_L_CH0_SHIFT (0U)
/*! D_MASK1_L_CH0 - D_MASK1_L_CH0 */
#define PXP_INPUT_STORE_D_MASK1_L_CH0_D_MASK1_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK1_L_CH0_D_MASK1_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK1_L_CH0_D_MASK1_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK2_H_CH0 - Input Store Data Mask 2 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK2_H_CH0_D_MASK2_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK2_H_CH0_D_MASK2_H_CH0_SHIFT (0U)
/*! D_MASK2_H_CH0 - D_MASK2_H_CH0 */
#define PXP_INPUT_STORE_D_MASK2_H_CH0_D_MASK2_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK2_H_CH0_D_MASK2_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK2_H_CH0_D_MASK2_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK2_L_CH0 - Input Store Data Mask 2 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK2_L_CH0_D_MASK2_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK2_L_CH0_D_MASK2_L_CH0_SHIFT (0U)
/*! D_MASK2_L_CH0 - D_MASK2_L_CH0 */
#define PXP_INPUT_STORE_D_MASK2_L_CH0_D_MASK2_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK2_L_CH0_D_MASK2_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK2_L_CH0_D_MASK2_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK3_H_CH0 - Input Store Data Mask 3 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK3_H_CH0_D_MASK3_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK3_H_CH0_D_MASK3_H_CH0_SHIFT (0U)
/*! D_MASK3_H_CH0 - D_MASK3_H_CH0 */
#define PXP_INPUT_STORE_D_MASK3_H_CH0_D_MASK3_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK3_H_CH0_D_MASK3_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK3_H_CH0_D_MASK3_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK3_L_CH0 - Input Store Data Mask 3 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK3_L_CH0_D_MASK3_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK3_L_CH0_D_MASK3_L_CH0_SHIFT (0U)
/*! D_MASK3_L_CH0 - D_MASK3_L_CH0 */
#define PXP_INPUT_STORE_D_MASK3_L_CH0_D_MASK3_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK3_L_CH0_D_MASK3_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK3_L_CH0_D_MASK3_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK4_H_CH0 - Input Store Data Mask 4 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK4_H_CH0_D_MASK4_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK4_H_CH0_D_MASK4_H_CH0_SHIFT (0U)
/*! D_MASK4_H_CH0 - D_MASK4_H_CH0 */
#define PXP_INPUT_STORE_D_MASK4_H_CH0_D_MASK4_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK4_H_CH0_D_MASK4_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK4_H_CH0_D_MASK4_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK4_L_CH0 - Input Store Data Mask 4 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK4_L_CH0_D_MASK4_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK4_L_CH0_D_MASK4_L_CH0_SHIFT (0U)
/*! D_MASK4_L_CH0 - D_MASK4_L_CH0 */
#define PXP_INPUT_STORE_D_MASK4_L_CH0_D_MASK4_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK4_L_CH0_D_MASK4_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK4_L_CH0_D_MASK4_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK5_H_CH0 - Input Store Data Mask 5 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK5_H_CH0_D_MASK5_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK5_H_CH0_D_MASK5_H_CH0_SHIFT (0U)
/*! D_MASK5_H_CH0 - D_MASK5_H_CH0 */
#define PXP_INPUT_STORE_D_MASK5_H_CH0_D_MASK5_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK5_H_CH0_D_MASK5_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK5_H_CH0_D_MASK5_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK5_L_CH0 - Input Store Data Mask 5 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK5_L_CH0_D_MASK5_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK5_L_CH0_D_MASK5_L_CH0_SHIFT (0U)
/*! D_MASK5_L_CH0 - D_MASK5_L_CH0 */
#define PXP_INPUT_STORE_D_MASK5_L_CH0_D_MASK5_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK5_L_CH0_D_MASK5_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK5_L_CH0_D_MASK5_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK6_H_CH0 - Input Store Data Mask 6 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK6_H_CH0_D_MASK6_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK6_H_CH0_D_MASK6_H_CH0_SHIFT (0U)
/*! D_MASK6_H_CH0 - D_MASK6_H_CH0 */
#define PXP_INPUT_STORE_D_MASK6_H_CH0_D_MASK6_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK6_H_CH0_D_MASK6_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK6_H_CH0_D_MASK6_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK6_L_CH0 - Input Store Data Mask 6 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK6_L_CH0_D_MASK6_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK6_L_CH0_D_MASK6_L_CH0_SHIFT (0U)
/*! D_MASK6_L_CH0 - D_MASK6_L_CH0 */
#define PXP_INPUT_STORE_D_MASK6_L_CH0_D_MASK6_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK6_L_CH0_D_MASK6_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK6_L_CH0_D_MASK6_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK7_H_CH0 - Input Store Data Mask 7 High Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK7_H_CH0_D_MASK7_H_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK7_H_CH0_D_MASK7_H_CH0_SHIFT (0U)
/*! D_MASK7_H_CH0 - D_MASK7_H_CH0 */
#define PXP_INPUT_STORE_D_MASK7_H_CH0_D_MASK7_H_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK7_H_CH0_D_MASK7_H_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK7_H_CH0_D_MASK7_H_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_MASK7_L_CH0 - Input Store Data Mask 7 Low Byte Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_MASK7_L_CH0_D_MASK7_L_CH0_MASK (0xFFFFFFFFU)
#define PXP_INPUT_STORE_D_MASK7_L_CH0_D_MASK7_L_CH0_SHIFT (0U)
/*! D_MASK7_L_CH0 - D_MASK7_L_CH0 */
#define PXP_INPUT_STORE_D_MASK7_L_CH0_D_MASK7_L_CH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_MASK7_L_CH0_D_MASK7_L_CH0_SHIFT)) & PXP_INPUT_STORE_D_MASK7_L_CH0_D_MASK7_L_CH0_MASK)
/*! @} */

/*! @name INPUT_STORE_D_SHIFT_L_CH0 - Input Store Data Shift Low Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH0_MASK (0x3FU)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH0_SHIFT (0U)
/*! D_SHIFT_WIDTH0 - D_SHIFT_WIDTH0 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH0_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH0_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD3_MASK (0x40U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD3_SHIFT (6U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD3(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD3_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD3_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG0_MASK (0x80U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG0_SHIFT (7U)
/*! D_SHIFT_FLAG0 - D_SHIFT_FLAG0 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG0_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG0_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH1_MASK (0x3F00U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH1_SHIFT (8U)
/*! D_SHIFT_WIDTH1 - D_SHIFT_WIDTH1 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH1_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH1_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD2_MASK (0x4000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD2_SHIFT (14U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD2(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD2_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD2_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG1_MASK (0x8000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG1_SHIFT (15U)
/*! D_SHIFT_FLAG1 - D_SHIFT_FLAG1 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG1_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG1_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH2_MASK (0x3F0000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH2_SHIFT (16U)
/*! D_SHIFT_WIDTH2 - D_SHIFT_WIDTH2 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH2_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH2_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD1_MASK (0x400000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD1_SHIFT (22U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD1_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD1_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG2_MASK (0x800000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG2_SHIFT (23U)
/*! D_SHIFT_FLAG2 - D_SHIFT_FLAG2 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG2_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG2_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH3_MASK (0x3F000000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH3_SHIFT (24U)
/*! D_SHIFT_WIDTH3 - D_SHIFT_WIDTH3 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH3_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_WIDTH3_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD0_MASK (0x40000000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD0_SHIFT (30U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD0_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_RSVD0_MASK)

#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG3_MASK (0x80000000U)
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG3_SHIFT (31U)
/*! D_SHIFT_FLAG3 - D_SHIFT_FLAG3 */
#define PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG3_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_L_CH0_D_SHIFT_FLAG3_MASK)
/*! @} */

/*! @name INPUT_STORE_D_SHIFT_H_CH0 - Input Store Data Shift High Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH4_MASK (0x3FU)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH4_SHIFT (0U)
/*! D_SHIFT_WIDTH4 - D_SHIFT_WIDTH4 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH4(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH4_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH4_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD3_MASK (0x40U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD3_SHIFT (6U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD3(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD3_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD3_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG4_MASK (0x80U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG4_SHIFT (7U)
/*! D_SHIFT_FLAG4 - D_SHIFT_FLAG4 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG4(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG4_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG4_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH5_MASK (0x3F00U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH5_SHIFT (8U)
/*! D_SHIFT_WIDTH5 - D_SHIFT_WIDTH5 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH5(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH5_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH5_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD2_MASK (0x4000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD2_SHIFT (14U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD2(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD2_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD2_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG5_MASK (0x8000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG5_SHIFT (15U)
/*! D_SHIFT_FLAG5 - D_SHIFT_FLAG5 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG5(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG5_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG5_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH6_MASK (0x3F0000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH6_SHIFT (16U)
/*! D_SHIFT_WIDTH6 - D_SHIFT_WIDTH6 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH6(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH6_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH6_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD1_MASK (0x400000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD1_SHIFT (22U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD1_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD1_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG6_MASK (0x800000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG6_SHIFT (23U)
/*! D_SHIFT_FLAG6 - D_SHIFT_FLAG6 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG6(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG6_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG6_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH7_MASK (0x3F000000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH7_SHIFT (24U)
/*! D_SHIFT_WIDTH7 - D_SHIFT_WIDTH7 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH7(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH7_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_WIDTH7_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD0_MASK (0x40000000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD0_SHIFT (30U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD0_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_RSVD0_MASK)

#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG7_MASK (0x80000000U)
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG7_SHIFT (31U)
/*! D_SHIFT_FLAG7 - D_SHIFT_FLAG7 */
#define PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG7(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG7_SHIFT)) & PXP_INPUT_STORE_D_SHIFT_H_CH0_D_SHIFT_FLAG7_MASK)
/*! @} */

/*! @name INPUT_STORE_F_SHIFT_L_CH0 - Input Store Flag Shift Low Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH0_MASK (0x3FU)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH0_SHIFT (0U)
/*! F_SHIFT_WIDTH0 - F_SHIFT_WIDTH0 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH0_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH0_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG0_MASK (0x40U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG0_SHIFT (6U)
/*! F_SHIFT_FLAG0 - F_SHIFT_FLAG0 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG0(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG0_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG0_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD3_MASK (0x80U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD3_SHIFT (7U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD3(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD3_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD3_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH1_MASK (0x3F00U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH1_SHIFT (8U)
/*! F_SHIFT_WIDTH1 - F_SHIFT_WIDTH1 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH1_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH1_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG1_MASK (0x4000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG1_SHIFT (14U)
/*! F_SHIFT_FLAG1 - F_SHIFT_FLAG1 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG1(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG1_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG1_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD2_MASK (0x8000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD2_SHIFT (15U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD2(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD2_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD2_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH2_MASK (0x3F0000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH2_SHIFT (16U)
/*! F_SHIFT_WIDTH2 - F_SHIFT_WIDTH2 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH2_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH2_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG2_MASK (0x400000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG2_SHIFT (22U)
/*! F_SHIFT_FLAG2 - F_SHIFT_FLAG2 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG2(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG2_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG2_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD1_MASK (0x800000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD1_SHIFT (23U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD1_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD1_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH3_MASK (0x3F000000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH3_SHIFT (24U)
/*! F_SHIFT_WIDTH3 - F_SHIFT_WIDTH3 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH3_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_WIDTH3_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG3_MASK (0x40000000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG3_SHIFT (30U)
/*! F_SHIFT_FLAG3 - F_SHIFT_FLAG3 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG3(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG3_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_F_SHIFT_FLAG3_MASK)

#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD0_MASK (0x80000000U)
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD0_SHIFT (31U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD0_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_L_CH0_RSVD0_MASK)
/*! @} */

/*! @name INPUT_STORE_F_SHIFT_H_CH0 - Input Store Flag Shift High Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH4_MASK (0x3FU)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH4_SHIFT (0U)
/*! F_SHIFT_WIDTH4 - F_SHIFT_WIDTH4 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH4(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH4_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH4_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG4_MASK (0x40U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG4_SHIFT (6U)
/*! F_SHIFT_FLAG4 - F_SHIFT_FLAG4 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG4(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG4_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG4_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD3_MASK (0x80U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD3_SHIFT (7U)
/*! RSVD3 - RSVD3 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD3(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD3_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD3_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH5_MASK (0x3F00U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH5_SHIFT (8U)
/*! F_SHIFT_WIDTH5 - F_SHIFT_WIDTH5 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH5(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH5_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH5_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG5_MASK (0x4000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG5_SHIFT (14U)
/*! F_SHIFT_FLAG5 - F_SHIFT_FLAG5 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG5(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG5_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG5_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD2_MASK (0x8000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD2_SHIFT (15U)
/*! RSVD2 - RSVD2 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD2(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD2_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD2_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH6_MASK (0x3F0000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH6_SHIFT (16U)
/*! F_SHIFT_WIDTH6 - F_SHIFT_WIDTH6 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH6(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH6_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH6_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG6_MASK (0x400000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG6_SHIFT (22U)
/*! F_SHIFT_FLAG6 - F_SHIFT_FLAG6 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG6(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG6_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG6_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD1_MASK (0x800000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD1_SHIFT (23U)
/*! RSVD1 - RSVD1 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD1(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD1_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD1_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH7_MASK (0x3F000000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH7_SHIFT (24U)
/*! F_SHIFT_WIDTH7 - F_SHIFT_WIDTH7 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH7(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH7_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_WIDTH7_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG7_MASK (0x40000000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG7_SHIFT (30U)
/*! F_SHIFT_FLAG7 - F_SHIFT_FLAG7 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG7(x) (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG7_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_F_SHIFT_FLAG7_MASK)

#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD0_MASK (0x80000000U)
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD0_SHIFT (31U)
/*! RSVD0 - RSVD0 */
#define PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD0(x)   (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD0_SHIFT)) & PXP_INPUT_STORE_F_SHIFT_H_CH0_RSVD0_MASK)
/*! @} */

/*! @name INPUT_STORE_F_MASK_L_CH0 - Input Store Flag Mask Low Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK0_MASK (0xFFU)
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK0_SHIFT (0U)
/*! F_MASK0 - F_MASK0 */
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK0(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK0_SHIFT)) & PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK0_MASK)

#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK1_MASK (0xFF00U)
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK1_SHIFT (8U)
/*! F_MASK1 - F_MASK1 */
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK1(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK1_SHIFT)) & PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK1_MASK)

#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK2_MASK (0xFF0000U)
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK2_SHIFT (16U)
/*! F_MASK2 - F_MASK2 */
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK2(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK2_SHIFT)) & PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK2_MASK)

#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK3_MASK (0xFF000000U)
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK3_SHIFT (24U)
/*! F_MASK3 - F_MASK3 */
#define PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK3(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK3_SHIFT)) & PXP_INPUT_STORE_F_MASK_L_CH0_F_MASK3_MASK)
/*! @} */

/*! @name INPUT_STORE_F_MASK_H_CH0 - Input Store Flag Mask High Channel 0 Register */
/*! @{ */

#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK4_MASK (0xFFU)
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK4_SHIFT (0U)
/*! F_MASK4 - F_MASK4 */
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK4(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK4_SHIFT)) & PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK4_MASK)

#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK5_MASK (0xFF00U)
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK5_SHIFT (8U)
/*! F_MASK5 - F_MASK5 */
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK5(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK5_SHIFT)) & PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK5_MASK)

#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK6_MASK (0xFF0000U)
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK6_SHIFT (16U)
/*! F_MASK6 - F_MASK6 */
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK6(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK6_SHIFT)) & PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK6_MASK)

#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK7_MASK (0xFF000000U)
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK7_SHIFT (24U)
/*! F_MASK7 - F_MASK7 */
#define PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK7(x)  (((uint32_t)(((uint32_t)(x)) << PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK7_SHIFT)) & PXP_INPUT_STORE_F_MASK_H_CH0_F_MASK7_MASK)
/*! @} */

/*! @name BUS_MUX - Bus MUX Register */
/*! @{ */

#define PXP_BUS_MUX_RD_SEL_MASK                  (0xFFU)
#define PXP_BUS_MUX_RD_SEL_SHIFT                 (0U)
/*! RD_SEL - RD_SEL */
#define PXP_BUS_MUX_RD_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_BUS_MUX_RD_SEL_SHIFT)) & PXP_BUS_MUX_RD_SEL_MASK)

#define PXP_BUS_MUX_RSVD0_MASK                   (0xFF00U)
#define PXP_BUS_MUX_RSVD0_SHIFT                  (8U)
/*! RSVD0 - RSVD0 */
#define PXP_BUS_MUX_RSVD0(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_BUS_MUX_RSVD0_SHIFT)) & PXP_BUS_MUX_RSVD0_MASK)

#define PXP_BUS_MUX_WR_SEL_MASK                  (0xFF0000U)
#define PXP_BUS_MUX_WR_SEL_SHIFT                 (16U)
/*! WR_SEL - WR_SEL */
#define PXP_BUS_MUX_WR_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << PXP_BUS_MUX_WR_SEL_SHIFT)) & PXP_BUS_MUX_WR_SEL_MASK)

#define PXP_BUS_MUX_RSVD1_MASK                   (0xFF000000U)
#define PXP_BUS_MUX_RSVD1_SHIFT                  (24U)
/*! RSVD1 - RSVD1 */
#define PXP_BUS_MUX_RSVD1(x)                     (((uint32_t)(((uint32_t)(x)) << PXP_BUS_MUX_RSVD1_SHIFT)) & PXP_BUS_MUX_RSVD1_MASK)
/*! @} */

/*! @name HANDSHAKE_READY_MUX0 - Handshake Ready MUX 0 Register */
/*! @{ */

#define PXP_HANDSHAKE_READY_MUX0_HSK0_MASK       (0xFU)
#define PXP_HANDSHAKE_READY_MUX0_HSK0_SHIFT      (0U)
/*! HSK0 - HSK0 */
#define PXP_HANDSHAKE_READY_MUX0_HSK0(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK0_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK0_MASK)

#define PXP_HANDSHAKE_READY_MUX0_HSK1_MASK       (0xF0U)
#define PXP_HANDSHAKE_READY_MUX0_HSK1_SHIFT      (4U)
/*! HSK1 - HSK1 */
#define PXP_HANDSHAKE_READY_MUX0_HSK1(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK1_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK1_MASK)

#define PXP_HANDSHAKE_READY_MUX0_HSK2_MASK       (0xF00U)
#define PXP_HANDSHAKE_READY_MUX0_HSK2_SHIFT      (8U)
/*! HSK2 - HSK2 */
#define PXP_HANDSHAKE_READY_MUX0_HSK2(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK2_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK2_MASK)

#define PXP_HANDSHAKE_READY_MUX0_HSK3_MASK       (0xF000U)
#define PXP_HANDSHAKE_READY_MUX0_HSK3_SHIFT      (12U)
/*! HSK3 - HSK3 */
#define PXP_HANDSHAKE_READY_MUX0_HSK3(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK3_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK3_MASK)

#define PXP_HANDSHAKE_READY_MUX0_HSK4_MASK       (0xF0000U)
#define PXP_HANDSHAKE_READY_MUX0_HSK4_SHIFT      (16U)
/*! HSK4 - HSK4 */
#define PXP_HANDSHAKE_READY_MUX0_HSK4(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK4_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK4_MASK)

#define PXP_HANDSHAKE_READY_MUX0_HSK5_MASK       (0xF00000U)
#define PXP_HANDSHAKE_READY_MUX0_HSK5_SHIFT      (20U)
/*! HSK5 - HSK5 */
#define PXP_HANDSHAKE_READY_MUX0_HSK5(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK5_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK5_MASK)

#define PXP_HANDSHAKE_READY_MUX0_HSK6_MASK       (0xF000000U)
#define PXP_HANDSHAKE_READY_MUX0_HSK6_SHIFT      (24U)
/*! HSK6 - HSK6 */
#define PXP_HANDSHAKE_READY_MUX0_HSK6(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK6_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK6_MASK)

#define PXP_HANDSHAKE_READY_MUX0_HSK7_MASK       (0xF0000000U)
#define PXP_HANDSHAKE_READY_MUX0_HSK7_SHIFT      (28U)
/*! HSK7 - HSK7 */
#define PXP_HANDSHAKE_READY_MUX0_HSK7(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX0_HSK7_SHIFT)) & PXP_HANDSHAKE_READY_MUX0_HSK7_MASK)
/*! @} */

/*! @name HANDSHAKE_READY_MUX1 - Handshake Ready MUX 1 Register */
/*! @{ */

#define PXP_HANDSHAKE_READY_MUX1_HSK8_MASK       (0xFU)
#define PXP_HANDSHAKE_READY_MUX1_HSK8_SHIFT      (0U)
/*! HSK8 - HSK8 */
#define PXP_HANDSHAKE_READY_MUX1_HSK8(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK8_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK8_MASK)

#define PXP_HANDSHAKE_READY_MUX1_HSK9_MASK       (0xF0U)
#define PXP_HANDSHAKE_READY_MUX1_HSK9_SHIFT      (4U)
/*! HSK9 - HSK9 */
#define PXP_HANDSHAKE_READY_MUX1_HSK9(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK9_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK9_MASK)

#define PXP_HANDSHAKE_READY_MUX1_HSK10_MASK      (0xF00U)
#define PXP_HANDSHAKE_READY_MUX1_HSK10_SHIFT     (8U)
/*! HSK10 - HSK10 */
#define PXP_HANDSHAKE_READY_MUX1_HSK10(x)        (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK10_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK10_MASK)

#define PXP_HANDSHAKE_READY_MUX1_HSK11_MASK      (0xF000U)
#define PXP_HANDSHAKE_READY_MUX1_HSK11_SHIFT     (12U)
/*! HSK11 - HSK11 */
#define PXP_HANDSHAKE_READY_MUX1_HSK11(x)        (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK11_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK11_MASK)

#define PXP_HANDSHAKE_READY_MUX1_HSK12_MASK      (0xF0000U)
#define PXP_HANDSHAKE_READY_MUX1_HSK12_SHIFT     (16U)
/*! HSK12 - HSK12 */
#define PXP_HANDSHAKE_READY_MUX1_HSK12(x)        (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK12_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK12_MASK)

#define PXP_HANDSHAKE_READY_MUX1_HSK13_MASK      (0xF00000U)
#define PXP_HANDSHAKE_READY_MUX1_HSK13_SHIFT     (20U)
/*! HSK13 - HSK13 */
#define PXP_HANDSHAKE_READY_MUX1_HSK13(x)        (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK13_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK13_MASK)

#define PXP_HANDSHAKE_READY_MUX1_HSK14_MASK      (0xF000000U)
#define PXP_HANDSHAKE_READY_MUX1_HSK14_SHIFT     (24U)
/*! HSK14 - HSK14 */
#define PXP_HANDSHAKE_READY_MUX1_HSK14(x)        (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK14_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK14_MASK)

#define PXP_HANDSHAKE_READY_MUX1_HSK15_MASK      (0xF0000000U)
#define PXP_HANDSHAKE_READY_MUX1_HSK15_SHIFT     (28U)
/*! HSK15 - HSK15 */
#define PXP_HANDSHAKE_READY_MUX1_HSK15(x)        (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_READY_MUX1_HSK15_SHIFT)) & PXP_HANDSHAKE_READY_MUX1_HSK15_MASK)
/*! @} */

/*! @name HANDSHAKE_DONE_MUX0 - Handshake Done MUX 0 Register */
/*! @{ */

#define PXP_HANDSHAKE_DONE_MUX0_HSK0_MASK        (0xFU)
#define PXP_HANDSHAKE_DONE_MUX0_HSK0_SHIFT       (0U)
/*! HSK0 - HSK0 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK0(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK0_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK0_MASK)

#define PXP_HANDSHAKE_DONE_MUX0_HSK1_MASK        (0xF0U)
#define PXP_HANDSHAKE_DONE_MUX0_HSK1_SHIFT       (4U)
/*! HSK1 - HSK1 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK1(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK1_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK1_MASK)

#define PXP_HANDSHAKE_DONE_MUX0_HSK2_MASK        (0xF00U)
#define PXP_HANDSHAKE_DONE_MUX0_HSK2_SHIFT       (8U)
/*! HSK2 - HSK2 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK2(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK2_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK2_MASK)

#define PXP_HANDSHAKE_DONE_MUX0_HSK3_MASK        (0xF000U)
#define PXP_HANDSHAKE_DONE_MUX0_HSK3_SHIFT       (12U)
/*! HSK3 - HSK3 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK3(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK3_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK3_MASK)

#define PXP_HANDSHAKE_DONE_MUX0_HSK4_MASK        (0xF0000U)
#define PXP_HANDSHAKE_DONE_MUX0_HSK4_SHIFT       (16U)
/*! HSK4 - HSK4 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK4(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK4_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK4_MASK)

#define PXP_HANDSHAKE_DONE_MUX0_HSK5_MASK        (0xF00000U)
#define PXP_HANDSHAKE_DONE_MUX0_HSK5_SHIFT       (20U)
/*! HSK5 - HSK5 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK5(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK5_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK5_MASK)

#define PXP_HANDSHAKE_DONE_MUX0_HSK6_MASK        (0xF000000U)
#define PXP_HANDSHAKE_DONE_MUX0_HSK6_SHIFT       (24U)
/*! HSK6 - HSK6 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK6(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK6_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK6_MASK)

#define PXP_HANDSHAKE_DONE_MUX0_HSK7_MASK        (0xF0000000U)
#define PXP_HANDSHAKE_DONE_MUX0_HSK7_SHIFT       (28U)
/*! HSK7 - HSK7 */
#define PXP_HANDSHAKE_DONE_MUX0_HSK7(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX0_HSK7_SHIFT)) & PXP_HANDSHAKE_DONE_MUX0_HSK7_MASK)
/*! @} */

/*! @name HANDSHAKE_DONE_MUX1 - Handshake Done MUX 1 Register */
/*! @{ */

#define PXP_HANDSHAKE_DONE_MUX1_HSK8_MASK        (0xFU)
#define PXP_HANDSHAKE_DONE_MUX1_HSK8_SHIFT       (0U)
/*! HSK8 - HSK8 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK8(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK8_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK8_MASK)

#define PXP_HANDSHAKE_DONE_MUX1_HSK9_MASK        (0xF0U)
#define PXP_HANDSHAKE_DONE_MUX1_HSK9_SHIFT       (4U)
/*! HSK9 - HSK9 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK9(x)          (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK9_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK9_MASK)

#define PXP_HANDSHAKE_DONE_MUX1_HSK10_MASK       (0xF00U)
#define PXP_HANDSHAKE_DONE_MUX1_HSK10_SHIFT      (8U)
/*! HSK10 - HSK10 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK10(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK10_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK10_MASK)

#define PXP_HANDSHAKE_DONE_MUX1_HSK11_MASK       (0xF000U)
#define PXP_HANDSHAKE_DONE_MUX1_HSK11_SHIFT      (12U)
/*! HSK11 - HSK11 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK11(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK11_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK11_MASK)

#define PXP_HANDSHAKE_DONE_MUX1_HSK12_MASK       (0xF0000U)
#define PXP_HANDSHAKE_DONE_MUX1_HSK12_SHIFT      (16U)
/*! HSK12 - HSK12 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK12(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK12_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK12_MASK)

#define PXP_HANDSHAKE_DONE_MUX1_HSK13_MASK       (0xF00000U)
#define PXP_HANDSHAKE_DONE_MUX1_HSK13_SHIFT      (20U)
/*! HSK13 - HSK13 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK13(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK13_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK13_MASK)

#define PXP_HANDSHAKE_DONE_MUX1_HSK14_MASK       (0xF000000U)
#define PXP_HANDSHAKE_DONE_MUX1_HSK14_SHIFT      (24U)
/*! HSK14 - HSK14 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK14(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK14_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK14_MASK)

#define PXP_HANDSHAKE_DONE_MUX1_HSK15_MASK       (0xF0000000U)
#define PXP_HANDSHAKE_DONE_MUX1_HSK15_SHIFT      (28U)
/*! HSK15 - HSK15 */
#define PXP_HANDSHAKE_DONE_MUX1_HSK15(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_DONE_MUX1_HSK15_SHIFT)) & PXP_HANDSHAKE_DONE_MUX1_HSK15_MASK)
/*! @} */

/*! @name HANDSHAKE_CPU_FETCH - Handshake CPU Fetch Register */
/*! @{ */

#define PXP_HANDSHAKE_CPU_FETCH_SW0_B0_READY_MASK (0x1U)
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B0_READY_SHIFT (0U)
/*! SW0_B0_READY - SW0_B0_READY */
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B0_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW0_B0_READY_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW0_B0_READY_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW0_B1_READY_MASK (0x2U)
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B1_READY_SHIFT (1U)
/*! SW0_B1_READY - SW0_B1_READY */
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B1_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW0_B1_READY_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW0_B1_READY_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW0_B0_DONE_MASK (0x4U)
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B0_DONE_SHIFT (2U)
/*! SW0_B0_DONE - SW0_B0_DONE */
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B0_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW0_B0_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW0_B0_DONE_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW0_B1_DONE_MASK (0x8U)
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B1_DONE_SHIFT (3U)
/*! SW0_B1_DONE - SW0_B1_DONE */
#define PXP_HANDSHAKE_CPU_FETCH_SW0_B1_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW0_B1_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW0_B1_DONE_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW0_BUF_LINES_MASK (0x30U)
#define PXP_HANDSHAKE_CPU_FETCH_SW0_BUF_LINES_SHIFT (4U)
/*! SW0_BUF_LINES - SW0_BUF_LINES
 *  0b00..LINE_4 : Buffer lines is 4 lines.
 *  0b01..LINE_8 : Buffer lines is 8 lines.
 *  0b10..LINE_16 : Buffer lines is 16 lines.
 */
#define PXP_HANDSHAKE_CPU_FETCH_SW0_BUF_LINES(x) (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW0_BUF_LINES_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW0_BUF_LINES_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_RSVD0_MASK       (0x7FC0U)
#define PXP_HANDSHAKE_CPU_FETCH_RSVD0_SHIFT      (6U)
/*! RSVD0 - RSVD0 */
#define PXP_HANDSHAKE_CPU_FETCH_RSVD0(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_RSVD0_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_RSVD0_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW0_HSK_EN_MASK  (0x8000U)
#define PXP_HANDSHAKE_CPU_FETCH_SW0_HSK_EN_SHIFT (15U)
/*! SW0_HSK_EN - SW0_HSK_EN */
#define PXP_HANDSHAKE_CPU_FETCH_SW0_HSK_EN(x)    (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW0_HSK_EN_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW0_HSK_EN_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW1_B0_READY_MASK (0x10000U)
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B0_READY_SHIFT (16U)
/*! SW1_B0_READY - SW1_B0_READY */
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B0_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW1_B0_READY_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW1_B0_READY_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW1_B1_READY_MASK (0x20000U)
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B1_READY_SHIFT (17U)
/*! SW1_B1_READY - SW1_B1_READY */
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B1_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW1_B1_READY_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW1_B1_READY_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW1_B0_DONE_MASK (0x40000U)
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B0_DONE_SHIFT (18U)
/*! SW1_B0_DONE - SW1_B0_DONE */
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B0_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW1_B0_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW1_B0_DONE_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW1_B1_DONE_MASK (0x80000U)
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B1_DONE_SHIFT (19U)
/*! SW1_B1_DONE - SW1_B1_DONE */
#define PXP_HANDSHAKE_CPU_FETCH_SW1_B1_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW1_B1_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW1_B1_DONE_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW1_BUF_LINES_MASK (0x300000U)
#define PXP_HANDSHAKE_CPU_FETCH_SW1_BUF_LINES_SHIFT (20U)
/*! SW1_BUF_LINES - SW1_BUF_LINES
 *  0b00..LINE_4 : Buffer lines is 4 lines.
 *  0b01..LINE_8 : Buffer lines is 8 lines.
 *  0b10..LINE_16 : Buffer lines is 16 lines.
 */
#define PXP_HANDSHAKE_CPU_FETCH_SW1_BUF_LINES(x) (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW1_BUF_LINES_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW1_BUF_LINES_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_RSVD1_MASK       (0x7FC00000U)
#define PXP_HANDSHAKE_CPU_FETCH_RSVD1_SHIFT      (22U)
/*! RSVD1 - RSVD1 */
#define PXP_HANDSHAKE_CPU_FETCH_RSVD1(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_RSVD1_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_RSVD1_MASK)

#define PXP_HANDSHAKE_CPU_FETCH_SW1_HSK_EN_MASK  (0x80000000U)
#define PXP_HANDSHAKE_CPU_FETCH_SW1_HSK_EN_SHIFT (31U)
/*! SW1_HSK_EN - SW1_HSK_EN */
#define PXP_HANDSHAKE_CPU_FETCH_SW1_HSK_EN(x)    (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_FETCH_SW1_HSK_EN_SHIFT)) & PXP_HANDSHAKE_CPU_FETCH_SW1_HSK_EN_MASK)
/*! @} */

/*! @name HANDSHAKE_CPU_STORE - Handshake CPU Store Register */
/*! @{ */

#define PXP_HANDSHAKE_CPU_STORE_SW0_B0_READY_MASK (0x1U)
#define PXP_HANDSHAKE_CPU_STORE_SW0_B0_READY_SHIFT (0U)
/*! SW0_B0_READY - SW0_B0_READY */
#define PXP_HANDSHAKE_CPU_STORE_SW0_B0_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW0_B0_READY_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW0_B0_READY_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW0_B1_READY_MASK (0x2U)
#define PXP_HANDSHAKE_CPU_STORE_SW0_B1_READY_SHIFT (1U)
/*! SW0_B1_READY - SW0_B1_READY */
#define PXP_HANDSHAKE_CPU_STORE_SW0_B1_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW0_B1_READY_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW0_B1_READY_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW0_B0_DONE_MASK (0x4U)
#define PXP_HANDSHAKE_CPU_STORE_SW0_B0_DONE_SHIFT (2U)
/*! SW0_B0_DONE - SW0_B0_DONE */
#define PXP_HANDSHAKE_CPU_STORE_SW0_B0_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW0_B0_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW0_B0_DONE_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW0_B1_DONE_MASK (0x8U)
#define PXP_HANDSHAKE_CPU_STORE_SW0_B1_DONE_SHIFT (3U)
/*! SW0_B1_DONE - SW0_B1_DONE */
#define PXP_HANDSHAKE_CPU_STORE_SW0_B1_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW0_B1_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW0_B1_DONE_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW0_BUF_LINES_MASK (0x30U)
#define PXP_HANDSHAKE_CPU_STORE_SW0_BUF_LINES_SHIFT (4U)
/*! SW0_BUF_LINES - SW0_BUF_LINES
 *  0b00..LINE_4 : Buffer lines is 4 lines.
 *  0b01..LINE_8 : Buffer lines is 8 lines.
 *  0b10..LINE_16 : Buffer lines is 16 lines.
 */
#define PXP_HANDSHAKE_CPU_STORE_SW0_BUF_LINES(x) (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW0_BUF_LINES_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW0_BUF_LINES_MASK)

#define PXP_HANDSHAKE_CPU_STORE_RSVD0_MASK       (0x7FC0U)
#define PXP_HANDSHAKE_CPU_STORE_RSVD0_SHIFT      (6U)
/*! RSVD0 - RSVD0 */
#define PXP_HANDSHAKE_CPU_STORE_RSVD0(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_RSVD0_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_RSVD0_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW0_HSK_EN_MASK  (0x8000U)
#define PXP_HANDSHAKE_CPU_STORE_SW0_HSK_EN_SHIFT (15U)
/*! SW0_HSK_EN - SW0_HSK_EN */
#define PXP_HANDSHAKE_CPU_STORE_SW0_HSK_EN(x)    (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW0_HSK_EN_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW0_HSK_EN_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW1_B0_READY_MASK (0x10000U)
#define PXP_HANDSHAKE_CPU_STORE_SW1_B0_READY_SHIFT (16U)
/*! SW1_B0_READY - SW1_B0_READY */
#define PXP_HANDSHAKE_CPU_STORE_SW1_B0_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW1_B0_READY_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW1_B0_READY_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW1_B1_READY_MASK (0x20000U)
#define PXP_HANDSHAKE_CPU_STORE_SW1_B1_READY_SHIFT (17U)
/*! SW1_B1_READY - SW1_B1_READY */
#define PXP_HANDSHAKE_CPU_STORE_SW1_B1_READY(x)  (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW1_B1_READY_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW1_B1_READY_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW1_B0_DONE_MASK (0x40000U)
#define PXP_HANDSHAKE_CPU_STORE_SW1_B0_DONE_SHIFT (18U)
/*! SW1_B0_DONE - SW1_B0_DONE */
#define PXP_HANDSHAKE_CPU_STORE_SW1_B0_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW1_B0_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW1_B0_DONE_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW1_B1_DONE_MASK (0x80000U)
#define PXP_HANDSHAKE_CPU_STORE_SW1_B1_DONE_SHIFT (19U)
/*! SW1_B1_DONE - SW1_B1_DONE */
#define PXP_HANDSHAKE_CPU_STORE_SW1_B1_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW1_B1_DONE_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW1_B1_DONE_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW1_BUF_LINES_MASK (0x300000U)
#define PXP_HANDSHAKE_CPU_STORE_SW1_BUF_LINES_SHIFT (20U)
/*! SW1_BUF_LINES - SW1_BUF_LINES
 *  0b00..LINE_4 : Buffer lines is 4 lines.
 *  0b01..LINE_8 : Buffer lines is 8 lines.
 *  0b10..LINE_16 : Buffer lines is 16 lines.
 */
#define PXP_HANDSHAKE_CPU_STORE_SW1_BUF_LINES(x) (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW1_BUF_LINES_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW1_BUF_LINES_MASK)

#define PXP_HANDSHAKE_CPU_STORE_RSVD1_MASK       (0x7FC00000U)
#define PXP_HANDSHAKE_CPU_STORE_RSVD1_SHIFT      (22U)
/*! RSVD1 - RSVD1 */
#define PXP_HANDSHAKE_CPU_STORE_RSVD1(x)         (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_RSVD1_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_RSVD1_MASK)

#define PXP_HANDSHAKE_CPU_STORE_SW1_HSK_EN_MASK  (0x80000000U)
#define PXP_HANDSHAKE_CPU_STORE_SW1_HSK_EN_SHIFT (31U)
/*! SW1_HSK_EN - SW1_HSK_EN */
#define PXP_HANDSHAKE_CPU_STORE_SW1_HSK_EN(x)    (((uint32_t)(((uint32_t)(x)) << PXP_HANDSHAKE_CPU_STORE_SW1_HSK_EN_SHIFT)) & PXP_HANDSHAKE_CPU_STORE_SW1_HSK_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PXP_Register_Masks */


/*!
 * @}
 */ /* end of group PXP_Peripheral_Access_Layer */


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


#endif  /* PERI_PXP_H_ */
