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
**         CMSIS Peripheral Access Layer for USB
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
 * @file PERI_USB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USB
 *
 * CMSIS Peripheral Access Layer for USB
 */

#if !defined(PERI_USB_H_)
#define PERI_USB_H_                              /**< Symbol preventing repeated inclusion */

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
   -- USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Peripheral_Access_Layer USB Peripheral Access Layer
 * @{
 */

/** USB - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID;                                /**< Identification, offset: 0x0 */
  __I  uint32_t HWGENERAL;                         /**< Hardware General, offset: 0x4 */
  __I  uint32_t HWHOST;                            /**< Host Hardware Parameters, offset: 0x8 */
  __I  uint32_t HWDEVICE;                          /**< Device Hardware Parameters, offset: 0xC */
  __I  uint32_t HWTXBUF;                           /**< TX Buffer Hardware Parameters, offset: 0x10 */
  __I  uint32_t HWRXBUF;                           /**< RX Buffer Hardware Parameters, offset: 0x14 */
       uint8_t RESERVED_0[104];
  __IO uint32_t GPTIMER0LD;                        /**< General Purpose Timer #0 Load, offset: 0x80 */
  __IO uint32_t GPTIMER0CTRL;                      /**< General Purpose Timer #0 Controller, offset: 0x84 */
  __IO uint32_t GPTIMER1LD;                        /**< General Purpose Timer #1 Load, offset: 0x88 */
  __IO uint32_t GPTIMER1CTRL;                      /**< General Purpose Timer #1 Controller, offset: 0x8C */
  __IO uint32_t SBUSCFG;                           /**< System Bus Config, offset: 0x90 */
       uint8_t RESERVED_1[108];
  __I  uint8_t CAPLENGTH;                          /**< Capability Registers Length, offset: 0x100 */
       uint8_t RESERVED_2[1];
  __I  uint16_t HCIVERSION;                        /**< Host Controller Interface Version, offset: 0x102 */
  __I  uint32_t HCSPARAMS;                         /**< Host Controller Structural Parameters, offset: 0x104 */
  __I  uint32_t HCCPARAMS;                         /**< Host Controller Capability Parameters, offset: 0x108 */
       uint8_t RESERVED_3[20];
  __I  uint16_t DCIVERSION;                        /**< Device Controller Interface Version, offset: 0x120 */
       uint8_t RESERVED_4[2];
  __I  uint32_t DCCPARAMS;                         /**< Device Controller Capability Parameters, offset: 0x124 */
       uint8_t RESERVED_5[24];
  __IO uint32_t USBCMD;                            /**< USB Command, offset: 0x140 */
  __IO uint32_t USBSTS;                            /**< USB Status, offset: 0x144 */
  __IO uint32_t USBINTR;                           /**< Interrupt Enable, offset: 0x148 */
  __IO uint32_t FRINDEX;                           /**< USB Frame Index, offset: 0x14C */
       uint8_t RESERVED_6[4];
  union {                                          /* offset: 0x154 */
    struct {                                         /* offset: 0x154 */
      __IO uint32_t DEVICEADDR;                        /**< Device Address, offset: 0x154 */
      __IO uint32_t ENDPTLISTADDR;                     /**< Endpoint List Address, offset: 0x158 */
    } DEVICE;
    struct {                                         /* offset: 0x154 */
      __IO uint32_t PERIODICLISTBASE;                  /**< Frame List Base Address, offset: 0x154 */
      __IO uint32_t ASYNCLISTADDR;                     /**< Next Asynch. Address, offset: 0x158 */
    } HOST;
  };
       uint8_t RESERVED_7[4];
  __IO uint32_t BURSTSIZE;                         /**< Programmable Burst Size, offset: 0x160 */
  __IO uint32_t TXFILLTUNING;                      /**< TX FIFO Fill Tuning, offset: 0x164 */
       uint8_t RESERVED_8[16];
  __IO uint32_t ENDPTNAK;                          /**< Endpoint NAK, offset: 0x178 */
  __IO uint32_t ENDPTNAKEN;                        /**< Endpoint NAK Enable, offset: 0x17C */
  __I  uint32_t CONFIGFLAG;                        /**< Configure Flag, offset: 0x180 */
  __IO uint32_t PORTSC1;                           /**< Port Status & Control, offset: 0x184 */
       uint8_t RESERVED_9[28];
  __IO uint32_t OTGSC;                             /**< On-The-Go Status & control, offset: 0x1A4 */
  __IO uint32_t USBMODE;                           /**< USB Device Mode, offset: 0x1A8 */
  __IO uint32_t ENDPTSETUPSTAT;                    /**< Endpoint Setup Status, offset: 0x1AC */
  __IO uint32_t ENDPTPRIME;                        /**< Endpoint Prime, offset: 0x1B0 */
  __IO uint32_t ENDPTFLUSH;                        /**< Endpoint Flush, offset: 0x1B4 */
  __I  uint32_t ENDPTSTAT;                         /**< Endpoint Status, offset: 0x1B8 */
  __IO uint32_t ENDPTCOMPLETE;                     /**< Endpoint Complete, offset: 0x1BC */
  __IO uint32_t ENDPTCTRL0;                        /**< Endpoint Control0, offset: 0x1C0 */
  __IO uint32_t ENDPTCTRL1;                        /**< Endpoint Control 1, offset: 0x1C4 */
  __IO uint32_t ENDPTCTRL2;                        /**< Endpoint Control 2, offset: 0x1C8 */
  __IO uint32_t ENDPTCTRL3;                        /**< Endpoint Control 3, offset: 0x1CC */
  __IO uint32_t ENDPTCTRL4;                        /**< Endpoint Control 4, offset: 0x1D0 */
  __IO uint32_t ENDPTCTRL5;                        /**< Endpoint Control 5, offset: 0x1D4 */
  __IO uint32_t ENDPTCTRL6;                        /**< Endpoint Control 6, offset: 0x1D8 */
  __IO uint32_t ENDPTCTRL7;                        /**< Endpoint Control 7, offset: 0x1DC */
} USB_Type;

/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/*! @name ID - Identification */
/*! @{ */

#define USB_ID_ID_MASK                           (0x3FU)
#define USB_ID_ID_SHIFT                          (0U)
/*! ID - ID */
#define USB_ID_ID(x)                             (((uint32_t)(((uint32_t)(x)) << USB_ID_ID_SHIFT)) & USB_ID_ID_MASK)

#define USB_ID_NID_MASK                          (0x3F00U)
#define USB_ID_NID_SHIFT                         (8U)
/*! NID - NID */
#define USB_ID_NID(x)                            (((uint32_t)(((uint32_t)(x)) << USB_ID_NID_SHIFT)) & USB_ID_NID_MASK)

#define USB_ID_REVISION_MASK                     (0xFF0000U)
#define USB_ID_REVISION_SHIFT                    (16U)
/*! REVISION - REVISION */
#define USB_ID_REVISION(x)                       (((uint32_t)(((uint32_t)(x)) << USB_ID_REVISION_SHIFT)) & USB_ID_REVISION_MASK)
/*! @} */

/*! @name HWGENERAL - Hardware General */
/*! @{ */

#define USB_HWGENERAL_PHYW_MASK                  (0x30U)
#define USB_HWGENERAL_PHYW_SHIFT                 (4U)
/*! PHYW - PHYW
 *  0b00..8 bit wide data bus (Software non-programmable)
 *  0b01..16 bit wide data bus (Software non-programmable)
 *  0b10..Reset to 8 bit wide data bus (Software programmable)
 *  0b11..Reset to 16 bit wide data bus (Software programmable)
 */
#define USB_HWGENERAL_PHYW(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HWGENERAL_PHYW_SHIFT)) & USB_HWGENERAL_PHYW_MASK)

#define USB_HWGENERAL_PHYM_MASK                  (0x1C0U)
#define USB_HWGENERAL_PHYM_SHIFT                 (6U)
/*! PHYM - PHYM
 *  0b000..UTMI/UMTI+
 *  0b001..ULPI DDR
 *  0b010..ULPI
 *  0b011..Serial Only
 *  0b100..Software programmable - reset to UTMI/UTMI+
 *  0b101..Software programmable - reset to ULPI DDR
 *  0b110..Software programmable - reset to ULPI
 *  0b111..Software programmable - reset to Serial
 */
#define USB_HWGENERAL_PHYM(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HWGENERAL_PHYM_SHIFT)) & USB_HWGENERAL_PHYM_MASK)

#define USB_HWGENERAL_SM_MASK                    (0x600U)
#define USB_HWGENERAL_SM_SHIFT                   (9U)
/*! SM - SM
 *  0b00..No Serial Engine, always use parallel signalling.
 *  0b01..Serial Engine present, always use serial signalling for FS/LS.
 *  0b10..Software programmable - Reset to use parallel signalling for FS/LS
 *  0b11..Software programmable - Reset to use serial signalling for FS/LS
 */
#define USB_HWGENERAL_SM(x)                      (((uint32_t)(((uint32_t)(x)) << USB_HWGENERAL_SM_SHIFT)) & USB_HWGENERAL_SM_MASK)
/*! @} */

/*! @name HWHOST - Host Hardware Parameters */
/*! @{ */

#define USB_HWHOST_HC_MASK                       (0x1U)
#define USB_HWHOST_HC_SHIFT                      (0U)
/*! HC - HC
 *  0b0..Not supported
 *  0b1..Supported
 */
#define USB_HWHOST_HC(x)                         (((uint32_t)(((uint32_t)(x)) << USB_HWHOST_HC_SHIFT)) & USB_HWHOST_HC_MASK)

#define USB_HWHOST_NPORT_MASK                    (0xEU)
#define USB_HWHOST_NPORT_SHIFT                   (1U)
/*! NPORT - NPORT */
#define USB_HWHOST_NPORT(x)                      (((uint32_t)(((uint32_t)(x)) << USB_HWHOST_NPORT_SHIFT)) & USB_HWHOST_NPORT_MASK)
/*! @} */

/*! @name HWDEVICE - Device Hardware Parameters */
/*! @{ */

#define USB_HWDEVICE_DC_MASK                     (0x1U)
#define USB_HWDEVICE_DC_SHIFT                    (0U)
/*! DC - DC
 *  0b0..Not supported
 *  0b1..Supported
 */
#define USB_HWDEVICE_DC(x)                       (((uint32_t)(((uint32_t)(x)) << USB_HWDEVICE_DC_SHIFT)) & USB_HWDEVICE_DC_MASK)

#define USB_HWDEVICE_DEVEP_MASK                  (0x3EU)
#define USB_HWDEVICE_DEVEP_SHIFT                 (1U)
/*! DEVEP - DEVEP */
#define USB_HWDEVICE_DEVEP(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HWDEVICE_DEVEP_SHIFT)) & USB_HWDEVICE_DEVEP_MASK)
/*! @} */

/*! @name HWTXBUF - TX Buffer Hardware Parameters */
/*! @{ */

#define USB_HWTXBUF_TXBURST_MASK                 (0xFFU)
#define USB_HWTXBUF_TXBURST_SHIFT                (0U)
/*! TXBURST - TXBURST */
#define USB_HWTXBUF_TXBURST(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HWTXBUF_TXBURST_SHIFT)) & USB_HWTXBUF_TXBURST_MASK)

#define USB_HWTXBUF_TXCHANADD_MASK               (0xFF0000U)
#define USB_HWTXBUF_TXCHANADD_SHIFT              (16U)
/*! TXCHANADD - TXCHANADD */
#define USB_HWTXBUF_TXCHANADD(x)                 (((uint32_t)(((uint32_t)(x)) << USB_HWTXBUF_TXCHANADD_SHIFT)) & USB_HWTXBUF_TXCHANADD_MASK)
/*! @} */

/*! @name HWRXBUF - RX Buffer Hardware Parameters */
/*! @{ */

#define USB_HWRXBUF_RXBURST_MASK                 (0xFFU)
#define USB_HWRXBUF_RXBURST_SHIFT                (0U)
/*! RXBURST - RXBURST */
#define USB_HWRXBUF_RXBURST(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HWRXBUF_RXBURST_SHIFT)) & USB_HWRXBUF_RXBURST_MASK)

#define USB_HWRXBUF_RXADD_MASK                   (0xFF00U)
#define USB_HWRXBUF_RXADD_SHIFT                  (8U)
/*! RXADD - RXADD */
#define USB_HWRXBUF_RXADD(x)                     (((uint32_t)(((uint32_t)(x)) << USB_HWRXBUF_RXADD_SHIFT)) & USB_HWRXBUF_RXADD_MASK)
/*! @} */

/*! @name GPTIMER0LD - General Purpose Timer #0 Load */
/*! @{ */

#define USB_GPTIMER0LD_GPTLD_MASK                (0xFFFFFFU)
#define USB_GPTIMER0LD_GPTLD_SHIFT               (0U)
/*! GPTLD - GPTLD */
#define USB_GPTIMER0LD_GPTLD(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER0LD_GPTLD_SHIFT)) & USB_GPTIMER0LD_GPTLD_MASK)
/*! @} */

/*! @name GPTIMER0CTRL - General Purpose Timer #0 Controller */
/*! @{ */

#define USB_GPTIMER0CTRL_GPTCNT_MASK             (0xFFFFFFU)
#define USB_GPTIMER0CTRL_GPTCNT_SHIFT            (0U)
/*! GPTCNT - GPTCNT */
#define USB_GPTIMER0CTRL_GPTCNT(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER0CTRL_GPTCNT_SHIFT)) & USB_GPTIMER0CTRL_GPTCNT_MASK)

#define USB_GPTIMER0CTRL_GPTMODE_MASK            (0x1000000U)
#define USB_GPTIMER0CTRL_GPTMODE_SHIFT           (24U)
/*! GPTMODE - GPTMODE
 *  0b0..One Shot Mode
 *  0b1..Repeat Mode
 */
#define USB_GPTIMER0CTRL_GPTMODE(x)              (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER0CTRL_GPTMODE_SHIFT)) & USB_GPTIMER0CTRL_GPTMODE_MASK)

#define USB_GPTIMER0CTRL_GPTRST_MASK             (0x40000000U)
#define USB_GPTIMER0CTRL_GPTRST_SHIFT            (30U)
/*! GPTRST - GPTRST
 *  0b0..No action
 *  0b1..Load counter value from GPTLD bits in n_GPTIMER0LD
 */
#define USB_GPTIMER0CTRL_GPTRST(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER0CTRL_GPTRST_SHIFT)) & USB_GPTIMER0CTRL_GPTRST_MASK)

#define USB_GPTIMER0CTRL_GPTRUN_MASK             (0x80000000U)
#define USB_GPTIMER0CTRL_GPTRUN_SHIFT            (31U)
/*! GPTRUN - GPTRUN
 *  0b0..Stop counting
 *  0b1..Run
 */
#define USB_GPTIMER0CTRL_GPTRUN(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER0CTRL_GPTRUN_SHIFT)) & USB_GPTIMER0CTRL_GPTRUN_MASK)
/*! @} */

/*! @name GPTIMER1LD - General Purpose Timer #1 Load */
/*! @{ */

#define USB_GPTIMER1LD_GPTLD_MASK                (0xFFFFFFU)
#define USB_GPTIMER1LD_GPTLD_SHIFT               (0U)
/*! GPTLD - GPTLD */
#define USB_GPTIMER1LD_GPTLD(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER1LD_GPTLD_SHIFT)) & USB_GPTIMER1LD_GPTLD_MASK)
/*! @} */

/*! @name GPTIMER1CTRL - General Purpose Timer #1 Controller */
/*! @{ */

#define USB_GPTIMER1CTRL_GPTCNT_MASK             (0xFFFFFFU)
#define USB_GPTIMER1CTRL_GPTCNT_SHIFT            (0U)
/*! GPTCNT - GPTCNT */
#define USB_GPTIMER1CTRL_GPTCNT(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER1CTRL_GPTCNT_SHIFT)) & USB_GPTIMER1CTRL_GPTCNT_MASK)

#define USB_GPTIMER1CTRL_GPTMODE_MASK            (0x1000000U)
#define USB_GPTIMER1CTRL_GPTMODE_SHIFT           (24U)
/*! GPTMODE - GPTMODE
 *  0b0..One Shot Mode
 *  0b1..Repeat Mode
 */
#define USB_GPTIMER1CTRL_GPTMODE(x)              (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER1CTRL_GPTMODE_SHIFT)) & USB_GPTIMER1CTRL_GPTMODE_MASK)

#define USB_GPTIMER1CTRL_GPTRST_MASK             (0x40000000U)
#define USB_GPTIMER1CTRL_GPTRST_SHIFT            (30U)
/*! GPTRST - GPTRST
 *  0b0..No action
 *  0b1..Load counter value from GPTLD bits in USB_n_GPTIMER0LD
 */
#define USB_GPTIMER1CTRL_GPTRST(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER1CTRL_GPTRST_SHIFT)) & USB_GPTIMER1CTRL_GPTRST_MASK)

#define USB_GPTIMER1CTRL_GPTRUN_MASK             (0x80000000U)
#define USB_GPTIMER1CTRL_GPTRUN_SHIFT            (31U)
/*! GPTRUN - GPTRUN
 *  0b0..Stop counting
 *  0b1..Run
 */
#define USB_GPTIMER1CTRL_GPTRUN(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPTIMER1CTRL_GPTRUN_SHIFT)) & USB_GPTIMER1CTRL_GPTRUN_MASK)
/*! @} */

/*! @name SBUSCFG - System Bus Config */
/*! @{ */

#define USB_SBUSCFG_AHBBRST_MASK                 (0x7U)
#define USB_SBUSCFG_AHBBRST_SHIFT                (0U)
/*! AHBBRST - AHBBRST
 *  0b000..Incremental burst of unspecified length only
 *  0b001..INCR4 burst, then single transfer
 *  0b010..INCR8 burst, INCR4 burst, then single transfer
 *  0b011..INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
 *  0b100..Reserved, don't use
 *  0b101..INCR4 burst, then incremental burst of unspecified length
 *  0b110..INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 *  0b111..INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 */
#define USB_SBUSCFG_AHBBRST(x)                   (((uint32_t)(((uint32_t)(x)) << USB_SBUSCFG_AHBBRST_SHIFT)) & USB_SBUSCFG_AHBBRST_MASK)
/*! @} */

/*! @name CAPLENGTH - Capability Registers Length */
/*! @{ */

#define USB_CAPLENGTH_CAPLENGTH_MASK             (0xFFU)
#define USB_CAPLENGTH_CAPLENGTH_SHIFT            (0U)
/*! CAPLENGTH - CAPLENGTH */
#define USB_CAPLENGTH_CAPLENGTH(x)               (((uint8_t)(((uint8_t)(x)) << USB_CAPLENGTH_CAPLENGTH_SHIFT)) & USB_CAPLENGTH_CAPLENGTH_MASK)
/*! @} */

/*! @name HCIVERSION - Host Controller Interface Version */
/*! @{ */

#define USB_HCIVERSION_HCIVERSION_MASK           (0xFFFFU)
#define USB_HCIVERSION_HCIVERSION_SHIFT          (0U)
/*! HCIVERSION - HCIVERSION */
#define USB_HCIVERSION_HCIVERSION(x)             (((uint16_t)(((uint16_t)(x)) << USB_HCIVERSION_HCIVERSION_SHIFT)) & USB_HCIVERSION_HCIVERSION_MASK)
/*! @} */

/*! @name HCSPARAMS - Host Controller Structural Parameters */
/*! @{ */

#define USB_HCSPARAMS_N_PORTS_MASK               (0xFU)
#define USB_HCSPARAMS_N_PORTS_SHIFT              (0U)
/*! N_PORTS - N_PORTS */
#define USB_HCSPARAMS_N_PORTS(x)                 (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS_N_PORTS_SHIFT)) & USB_HCSPARAMS_N_PORTS_MASK)

#define USB_HCSPARAMS_PPC_MASK                   (0x10U)
#define USB_HCSPARAMS_PPC_SHIFT                  (4U)
/*! PPC - PPC */
#define USB_HCSPARAMS_PPC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS_PPC_SHIFT)) & USB_HCSPARAMS_PPC_MASK)

#define USB_HCSPARAMS_N_PCC_MASK                 (0xF00U)
#define USB_HCSPARAMS_N_PCC_SHIFT                (8U)
/*! N_PCC - N_PCC */
#define USB_HCSPARAMS_N_PCC(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS_N_PCC_SHIFT)) & USB_HCSPARAMS_N_PCC_MASK)

#define USB_HCSPARAMS_N_CC_MASK                  (0xF000U)
#define USB_HCSPARAMS_N_CC_SHIFT                 (12U)
/*! N_CC - N_CC
 *  0b0000..There is no internal Companion Controller and port-ownership hand-off is not supported.
 *  0b0001..There are internal companion controller(s) and port-ownership hand-offs is supported.
 */
#define USB_HCSPARAMS_N_CC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS_N_CC_SHIFT)) & USB_HCSPARAMS_N_CC_MASK)

#define USB_HCSPARAMS_PI_MASK                    (0x10000U)
#define USB_HCSPARAMS_PI_SHIFT                   (16U)
/*! PI - PI */
#define USB_HCSPARAMS_PI(x)                      (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS_PI_SHIFT)) & USB_HCSPARAMS_PI_MASK)

#define USB_HCSPARAMS_N_PTT_MASK                 (0xF00000U)
#define USB_HCSPARAMS_N_PTT_SHIFT                (20U)
/*! N_PTT - N_PTT */
#define USB_HCSPARAMS_N_PTT(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS_N_PTT_SHIFT)) & USB_HCSPARAMS_N_PTT_MASK)

#define USB_HCSPARAMS_N_TT_MASK                  (0xF000000U)
#define USB_HCSPARAMS_N_TT_SHIFT                 (24U)
/*! N_TT - N_TT */
#define USB_HCSPARAMS_N_TT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS_N_TT_SHIFT)) & USB_HCSPARAMS_N_TT_MASK)
/*! @} */

/*! @name HCCPARAMS - Host Controller Capability Parameters */
/*! @{ */

#define USB_HCCPARAMS_ADC_MASK                   (0x1U)
#define USB_HCCPARAMS_ADC_SHIFT                  (0U)
/*! ADC - ADC */
#define USB_HCCPARAMS_ADC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS_ADC_SHIFT)) & USB_HCCPARAMS_ADC_MASK)

#define USB_HCCPARAMS_PFL_MASK                   (0x2U)
#define USB_HCCPARAMS_PFL_SHIFT                  (1U)
/*! PFL - PFL */
#define USB_HCCPARAMS_PFL(x)                     (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS_PFL_SHIFT)) & USB_HCCPARAMS_PFL_MASK)

#define USB_HCCPARAMS_ASP_MASK                   (0x4U)
#define USB_HCCPARAMS_ASP_SHIFT                  (2U)
/*! ASP - ASP */
#define USB_HCCPARAMS_ASP(x)                     (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS_ASP_SHIFT)) & USB_HCCPARAMS_ASP_MASK)

#define USB_HCCPARAMS_IST_MASK                   (0xF0U)
#define USB_HCCPARAMS_IST_SHIFT                  (4U)
/*! IST - IST */
#define USB_HCCPARAMS_IST(x)                     (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS_IST_SHIFT)) & USB_HCCPARAMS_IST_MASK)

#define USB_HCCPARAMS_EECP_MASK                  (0xFF00U)
#define USB_HCCPARAMS_EECP_SHIFT                 (8U)
/*! EECP - EECP */
#define USB_HCCPARAMS_EECP(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS_EECP_SHIFT)) & USB_HCCPARAMS_EECP_MASK)
/*! @} */

/*! @name DCIVERSION - Device Controller Interface Version */
/*! @{ */

#define USB_DCIVERSION_DCIVERSION_MASK           (0xFFFFU)
#define USB_DCIVERSION_DCIVERSION_SHIFT          (0U)
/*! DCIVERSION - DCIVERSION */
#define USB_DCIVERSION_DCIVERSION(x)             (((uint16_t)(((uint16_t)(x)) << USB_DCIVERSION_DCIVERSION_SHIFT)) & USB_DCIVERSION_DCIVERSION_MASK)
/*! @} */

/*! @name DCCPARAMS - Device Controller Capability Parameters */
/*! @{ */

#define USB_DCCPARAMS_DEN_MASK                   (0x1FU)
#define USB_DCCPARAMS_DEN_SHIFT                  (0U)
/*! DEN - DEN */
#define USB_DCCPARAMS_DEN(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DCCPARAMS_DEN_SHIFT)) & USB_DCCPARAMS_DEN_MASK)

#define USB_DCCPARAMS_DC_MASK                    (0x80U)
#define USB_DCCPARAMS_DC_SHIFT                   (7U)
/*! DC - DC */
#define USB_DCCPARAMS_DC(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DCCPARAMS_DC_SHIFT)) & USB_DCCPARAMS_DC_MASK)

#define USB_DCCPARAMS_HC_MASK                    (0x100U)
#define USB_DCCPARAMS_HC_SHIFT                   (8U)
/*! HC - HC */
#define USB_DCCPARAMS_HC(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DCCPARAMS_HC_SHIFT)) & USB_DCCPARAMS_HC_MASK)
/*! @} */

/*! @name USBCMD - USB Command */
/*! @{ */

#define USB_USBCMD_RS_MASK                       (0x1U)
#define USB_USBCMD_RS_SHIFT                      (0U)
/*! RS - RS */
#define USB_USBCMD_RS(x)                         (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_RS_SHIFT)) & USB_USBCMD_RS_MASK)

#define USB_USBCMD_RST_MASK                      (0x2U)
#define USB_USBCMD_RST_SHIFT                     (1U)
/*! RST - RST */
#define USB_USBCMD_RST(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_RST_SHIFT)) & USB_USBCMD_RST_MASK)

#define USB_USBCMD_FS_1_MASK                     (0xCU)
#define USB_USBCMD_FS_1_SHIFT                    (2U)
/*! FS_1 - FS_1 */
#define USB_USBCMD_FS_1(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_FS_1_SHIFT)) & USB_USBCMD_FS_1_MASK)

#define USB_USBCMD_PSE_MASK                      (0x10U)
#define USB_USBCMD_PSE_SHIFT                     (4U)
/*! PSE - PSE
 *  0b0..Do not process the Periodic Schedule
 *  0b1..Use the PERIODICLISTBASE register to access the Periodic Schedule.
 */
#define USB_USBCMD_PSE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_PSE_SHIFT)) & USB_USBCMD_PSE_MASK)

#define USB_USBCMD_ASE_MASK                      (0x20U)
#define USB_USBCMD_ASE_SHIFT                     (5U)
/*! ASE - ASE
 *  0b0..Do not process the Asynchronous Schedule.
 *  0b1..Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
 */
#define USB_USBCMD_ASE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_ASE_SHIFT)) & USB_USBCMD_ASE_MASK)

#define USB_USBCMD_IAA_MASK                      (0x40U)
#define USB_USBCMD_IAA_SHIFT                     (6U)
/*! IAA - IAA */
#define USB_USBCMD_IAA(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_IAA_SHIFT)) & USB_USBCMD_IAA_MASK)

#define USB_USBCMD_ASP_MASK                      (0x300U)
#define USB_USBCMD_ASP_SHIFT                     (8U)
/*! ASP - ASP */
#define USB_USBCMD_ASP(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_ASP_SHIFT)) & USB_USBCMD_ASP_MASK)

#define USB_USBCMD_ASPE_MASK                     (0x800U)
#define USB_USBCMD_ASPE_SHIFT                    (11U)
/*! ASPE - ASPE */
#define USB_USBCMD_ASPE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_ASPE_SHIFT)) & USB_USBCMD_ASPE_MASK)

#define USB_USBCMD_SUTW_MASK                     (0x2000U)
#define USB_USBCMD_SUTW_SHIFT                    (13U)
/*! SUTW - SUTW */
#define USB_USBCMD_SUTW(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_SUTW_SHIFT)) & USB_USBCMD_SUTW_MASK)

#define USB_USBCMD_ATDTW_MASK                    (0x4000U)
#define USB_USBCMD_ATDTW_SHIFT                   (14U)
/*! ATDTW - ATDTW */
#define USB_USBCMD_ATDTW(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_ATDTW_SHIFT)) & USB_USBCMD_ATDTW_MASK)

#define USB_USBCMD_FS_2_MASK                     (0x8000U)
#define USB_USBCMD_FS_2_SHIFT                    (15U)
/*! FS_2 - FS_2 */
#define USB_USBCMD_FS_2(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_FS_2_SHIFT)) & USB_USBCMD_FS_2_MASK)

#define USB_USBCMD_ITC_MASK                      (0xFF0000U)
#define USB_USBCMD_ITC_SHIFT                     (16U)
/*! ITC - ITC
 *  0b00000000..Immediate (no threshold)
 *  0b00000001..1 micro-frame
 *  0b00000010..2 micro-frames
 *  0b00000100..4 micro-frames
 *  0b00001000..8 micro-frames
 *  0b00010000..16 micro-frames
 *  0b00100000..32 micro-frames
 *  0b01000000..64 micro-frames
 */
#define USB_USBCMD_ITC(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_ITC_SHIFT)) & USB_USBCMD_ITC_MASK)
/*! @} */

/*! @name USBSTS - USB Status */
/*! @{ */

#define USB_USBSTS_UI_MASK                       (0x1U)
#define USB_USBSTS_UI_SHIFT                      (0U)
/*! UI - UI */
#define USB_USBSTS_UI(x)                         (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_UI_SHIFT)) & USB_USBSTS_UI_MASK)

#define USB_USBSTS_UEI_MASK                      (0x2U)
#define USB_USBSTS_UEI_SHIFT                     (1U)
/*! UEI - UEI */
#define USB_USBSTS_UEI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_UEI_SHIFT)) & USB_USBSTS_UEI_MASK)

#define USB_USBSTS_PCI_MASK                      (0x4U)
#define USB_USBSTS_PCI_SHIFT                     (2U)
/*! PCI - PCI */
#define USB_USBSTS_PCI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_PCI_SHIFT)) & USB_USBSTS_PCI_MASK)

#define USB_USBSTS_FRI_MASK                      (0x8U)
#define USB_USBSTS_FRI_SHIFT                     (3U)
/*! FRI - FRI */
#define USB_USBSTS_FRI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_FRI_SHIFT)) & USB_USBSTS_FRI_MASK)

#define USB_USBSTS_SEI_MASK                      (0x10U)
#define USB_USBSTS_SEI_SHIFT                     (4U)
/*! SEI - SEI */
#define USB_USBSTS_SEI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_SEI_SHIFT)) & USB_USBSTS_SEI_MASK)

#define USB_USBSTS_AAI_MASK                      (0x20U)
#define USB_USBSTS_AAI_SHIFT                     (5U)
/*! AAI - AAI */
#define USB_USBSTS_AAI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_AAI_SHIFT)) & USB_USBSTS_AAI_MASK)

#define USB_USBSTS_URI_MASK                      (0x40U)
#define USB_USBSTS_URI_SHIFT                     (6U)
/*! URI - URI */
#define USB_USBSTS_URI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_URI_SHIFT)) & USB_USBSTS_URI_MASK)

#define USB_USBSTS_SRI_MASK                      (0x80U)
#define USB_USBSTS_SRI_SHIFT                     (7U)
/*! SRI - SRI */
#define USB_USBSTS_SRI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_SRI_SHIFT)) & USB_USBSTS_SRI_MASK)

#define USB_USBSTS_SLI_MASK                      (0x100U)
#define USB_USBSTS_SLI_SHIFT                     (8U)
/*! SLI - SLI */
#define USB_USBSTS_SLI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_SLI_SHIFT)) & USB_USBSTS_SLI_MASK)

#define USB_USBSTS_ULPII_MASK                    (0x400U)
#define USB_USBSTS_ULPII_SHIFT                   (10U)
/*! ULPII - ULPII */
#define USB_USBSTS_ULPII(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_ULPII_SHIFT)) & USB_USBSTS_ULPII_MASK)

#define USB_USBSTS_HCH_MASK                      (0x1000U)
#define USB_USBSTS_HCH_SHIFT                     (12U)
/*! HCH - HCH */
#define USB_USBSTS_HCH(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_HCH_SHIFT)) & USB_USBSTS_HCH_MASK)

#define USB_USBSTS_RCL_MASK                      (0x2000U)
#define USB_USBSTS_RCL_SHIFT                     (13U)
/*! RCL - RCL */
#define USB_USBSTS_RCL(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_RCL_SHIFT)) & USB_USBSTS_RCL_MASK)

#define USB_USBSTS_PS_MASK                       (0x4000U)
#define USB_USBSTS_PS_SHIFT                      (14U)
/*! PS - PS */
#define USB_USBSTS_PS(x)                         (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_PS_SHIFT)) & USB_USBSTS_PS_MASK)

#define USB_USBSTS_AS_MASK                       (0x8000U)
#define USB_USBSTS_AS_SHIFT                      (15U)
/*! AS - AS */
#define USB_USBSTS_AS(x)                         (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_AS_SHIFT)) & USB_USBSTS_AS_MASK)

#define USB_USBSTS_NAKI_MASK                     (0x10000U)
#define USB_USBSTS_NAKI_SHIFT                    (16U)
/*! NAKI - NAKI */
#define USB_USBSTS_NAKI(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_NAKI_SHIFT)) & USB_USBSTS_NAKI_MASK)

#define USB_USBSTS_TI0_MASK                      (0x1000000U)
#define USB_USBSTS_TI0_SHIFT                     (24U)
/*! TI0 - TI0 */
#define USB_USBSTS_TI0(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_TI0_SHIFT)) & USB_USBSTS_TI0_MASK)

#define USB_USBSTS_TI1_MASK                      (0x2000000U)
#define USB_USBSTS_TI1_SHIFT                     (25U)
/*! TI1 - TI1 */
#define USB_USBSTS_TI1(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_TI1_SHIFT)) & USB_USBSTS_TI1_MASK)
/*! @} */

/*! @name USBINTR - Interrupt Enable */
/*! @{ */

#define USB_USBINTR_UE_MASK                      (0x1U)
#define USB_USBINTR_UE_SHIFT                     (0U)
/*! UE - UE */
#define USB_USBINTR_UE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_UE_SHIFT)) & USB_USBINTR_UE_MASK)

#define USB_USBINTR_UEE_MASK                     (0x2U)
#define USB_USBINTR_UEE_SHIFT                    (1U)
/*! UEE - UEE */
#define USB_USBINTR_UEE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_UEE_SHIFT)) & USB_USBINTR_UEE_MASK)

#define USB_USBINTR_PCE_MASK                     (0x4U)
#define USB_USBINTR_PCE_SHIFT                    (2U)
/*! PCE - PCE */
#define USB_USBINTR_PCE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_PCE_SHIFT)) & USB_USBINTR_PCE_MASK)

#define USB_USBINTR_FRE_MASK                     (0x8U)
#define USB_USBINTR_FRE_SHIFT                    (3U)
/*! FRE - FRE */
#define USB_USBINTR_FRE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_FRE_SHIFT)) & USB_USBINTR_FRE_MASK)

#define USB_USBINTR_SEE_MASK                     (0x10U)
#define USB_USBINTR_SEE_SHIFT                    (4U)
/*! SEE - SEE */
#define USB_USBINTR_SEE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_SEE_SHIFT)) & USB_USBINTR_SEE_MASK)

#define USB_USBINTR_AAE_MASK                     (0x20U)
#define USB_USBINTR_AAE_SHIFT                    (5U)
/*! AAE - AAE */
#define USB_USBINTR_AAE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_AAE_SHIFT)) & USB_USBINTR_AAE_MASK)

#define USB_USBINTR_URE_MASK                     (0x40U)
#define USB_USBINTR_URE_SHIFT                    (6U)
/*! URE - URE */
#define USB_USBINTR_URE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_URE_SHIFT)) & USB_USBINTR_URE_MASK)

#define USB_USBINTR_SRE_MASK                     (0x80U)
#define USB_USBINTR_SRE_SHIFT                    (7U)
/*! SRE - SRE */
#define USB_USBINTR_SRE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_SRE_SHIFT)) & USB_USBINTR_SRE_MASK)

#define USB_USBINTR_SLE_MASK                     (0x100U)
#define USB_USBINTR_SLE_SHIFT                    (8U)
/*! SLE - SLE */
#define USB_USBINTR_SLE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_SLE_SHIFT)) & USB_USBINTR_SLE_MASK)

#define USB_USBINTR_ULPIE_MASK                   (0x400U)
#define USB_USBINTR_ULPIE_SHIFT                  (10U)
/*! ULPIE - ULPIE */
#define USB_USBINTR_ULPIE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_ULPIE_SHIFT)) & USB_USBINTR_ULPIE_MASK)

#define USB_USBINTR_NAKE_MASK                    (0x10000U)
#define USB_USBINTR_NAKE_SHIFT                   (16U)
/*! NAKE - NAKE */
#define USB_USBINTR_NAKE(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_NAKE_SHIFT)) & USB_USBINTR_NAKE_MASK)

#define USB_USBINTR_UAIE_MASK                    (0x40000U)
#define USB_USBINTR_UAIE_SHIFT                   (18U)
/*! UAIE - UAIE */
#define USB_USBINTR_UAIE(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_UAIE_SHIFT)) & USB_USBINTR_UAIE_MASK)

#define USB_USBINTR_UPIE_MASK                    (0x80000U)
#define USB_USBINTR_UPIE_SHIFT                   (19U)
/*! UPIE - UPIE */
#define USB_USBINTR_UPIE(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_UPIE_SHIFT)) & USB_USBINTR_UPIE_MASK)

#define USB_USBINTR_TIE0_MASK                    (0x1000000U)
#define USB_USBINTR_TIE0_SHIFT                   (24U)
/*! TIE0 - TIE0 */
#define USB_USBINTR_TIE0(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_TIE0_SHIFT)) & USB_USBINTR_TIE0_MASK)

#define USB_USBINTR_TIE1_MASK                    (0x2000000U)
#define USB_USBINTR_TIE1_SHIFT                   (25U)
/*! TIE1 - TIE1 */
#define USB_USBINTR_TIE1(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBINTR_TIE1_SHIFT)) & USB_USBINTR_TIE1_MASK)
/*! @} */

/*! @name FRINDEX - USB Frame Index */
/*! @{ */

#define USB_FRINDEX_FRINDEX_MASK                 (0x3FFFU)
#define USB_FRINDEX_FRINDEX_SHIFT                (0U)
/*! FRINDEX - FRINDEX
 *  0b00000000000000..(1024) 12
 *  0b00000000000001..(512) 11
 *  0b00000000000010..(256) 10
 *  0b00000000000011..(128) 9
 *  0b00000000000100..(64) 8
 *  0b00000000000101..(32) 7
 *  0b00000000000110..(16) 6
 *  0b00000000000111..(8) 5
 */
#define USB_FRINDEX_FRINDEX(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FRINDEX_FRINDEX_SHIFT)) & USB_FRINDEX_FRINDEX_MASK)
/*! @} */

/*! @name DEVICEADDR - Device Address */
/*! @{ */

#define USB_DEVICEADDR_USBADRA_MASK              (0x1000000U)
#define USB_DEVICEADDR_USBADRA_SHIFT             (24U)
/*! USBADRA - USBADRA */
#define USB_DEVICEADDR_USBADRA(x)                (((uint32_t)(((uint32_t)(x)) << USB_DEVICEADDR_USBADRA_SHIFT)) & USB_DEVICEADDR_USBADRA_MASK)

#define USB_DEVICEADDR_USBADR_MASK               (0xFE000000U)
#define USB_DEVICEADDR_USBADR_SHIFT              (25U)
/*! USBADR - USBADR */
#define USB_DEVICEADDR_USBADR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_DEVICEADDR_USBADR_SHIFT)) & USB_DEVICEADDR_USBADR_MASK)
/*! @} */

/*! @name ENDPTLISTADDR - Endpoint List Address */
/*! @{ */

#define USB_ENDPTLISTADDR_EPBASE_MASK            (0xFFFFF800U)
#define USB_ENDPTLISTADDR_EPBASE_SHIFT           (11U)
/*! EPBASE - EPBASE */
#define USB_ENDPTLISTADDR_EPBASE(x)              (((uint32_t)(((uint32_t)(x)) << USB_ENDPTLISTADDR_EPBASE_SHIFT)) & USB_ENDPTLISTADDR_EPBASE_MASK)
/*! @} */

/*! @name PERIODICLISTBASE - Frame List Base Address */
/*! @{ */

#define USB_PERIODICLISTBASE_BASEADR_MASK        (0xFFFFF000U)
#define USB_PERIODICLISTBASE_BASEADR_SHIFT       (12U)
/*! BASEADR - BASEADR */
#define USB_PERIODICLISTBASE_BASEADR(x)          (((uint32_t)(((uint32_t)(x)) << USB_PERIODICLISTBASE_BASEADR_SHIFT)) & USB_PERIODICLISTBASE_BASEADR_MASK)
/*! @} */

/*! @name ASYNCLISTADDR - Next Asynch. Address */
/*! @{ */

#define USB_ASYNCLISTADDR_ASYBASE_MASK           (0xFFFFFFE0U)
#define USB_ASYNCLISTADDR_ASYBASE_SHIFT          (5U)
/*! ASYBASE - ASYBASE */
#define USB_ASYNCLISTADDR_ASYBASE(x)             (((uint32_t)(((uint32_t)(x)) << USB_ASYNCLISTADDR_ASYBASE_SHIFT)) & USB_ASYNCLISTADDR_ASYBASE_MASK)
/*! @} */

/*! @name BURSTSIZE - Programmable Burst Size */
/*! @{ */

#define USB_BURSTSIZE_RXPBURST_MASK              (0xFFU)
#define USB_BURSTSIZE_RXPBURST_SHIFT             (0U)
/*! RXPBURST - RXPBURST */
#define USB_BURSTSIZE_RXPBURST(x)                (((uint32_t)(((uint32_t)(x)) << USB_BURSTSIZE_RXPBURST_SHIFT)) & USB_BURSTSIZE_RXPBURST_MASK)

#define USB_BURSTSIZE_TXPBURST_MASK              (0x1FF00U)
#define USB_BURSTSIZE_TXPBURST_SHIFT             (8U)
/*! TXPBURST - TXPBURST */
#define USB_BURSTSIZE_TXPBURST(x)                (((uint32_t)(((uint32_t)(x)) << USB_BURSTSIZE_TXPBURST_SHIFT)) & USB_BURSTSIZE_TXPBURST_MASK)
/*! @} */

/*! @name TXFILLTUNING - TX FIFO Fill Tuning */
/*! @{ */

#define USB_TXFILLTUNING_TXSCHOH_MASK            (0xFFU)
#define USB_TXFILLTUNING_TXSCHOH_SHIFT           (0U)
/*! TXSCHOH - TXSCHOH */
#define USB_TXFILLTUNING_TXSCHOH(x)              (((uint32_t)(((uint32_t)(x)) << USB_TXFILLTUNING_TXSCHOH_SHIFT)) & USB_TXFILLTUNING_TXSCHOH_MASK)

#define USB_TXFILLTUNING_TXSCHHEALTH_MASK        (0x1F00U)
#define USB_TXFILLTUNING_TXSCHHEALTH_SHIFT       (8U)
/*! TXSCHHEALTH - TXSCHHEALTH */
#define USB_TXFILLTUNING_TXSCHHEALTH(x)          (((uint32_t)(((uint32_t)(x)) << USB_TXFILLTUNING_TXSCHHEALTH_SHIFT)) & USB_TXFILLTUNING_TXSCHHEALTH_MASK)

#define USB_TXFILLTUNING_TXFIFOTHRES_MASK        (0x3F0000U)
#define USB_TXFILLTUNING_TXFIFOTHRES_SHIFT       (16U)
/*! TXFIFOTHRES - TXFIFOTHRES */
#define USB_TXFILLTUNING_TXFIFOTHRES(x)          (((uint32_t)(((uint32_t)(x)) << USB_TXFILLTUNING_TXFIFOTHRES_SHIFT)) & USB_TXFILLTUNING_TXFIFOTHRES_MASK)
/*! @} */

/*! @name ENDPTNAK - Endpoint NAK */
/*! @{ */

#define USB_ENDPTNAK_EPRN_MASK                   (0xFFU)
#define USB_ENDPTNAK_EPRN_SHIFT                  (0U)
/*! EPRN - EPRN */
#define USB_ENDPTNAK_EPRN(x)                     (((uint32_t)(((uint32_t)(x)) << USB_ENDPTNAK_EPRN_SHIFT)) & USB_ENDPTNAK_EPRN_MASK)

#define USB_ENDPTNAK_EPTN_MASK                   (0xFF0000U)
#define USB_ENDPTNAK_EPTN_SHIFT                  (16U)
/*! EPTN - EPTN */
#define USB_ENDPTNAK_EPTN(x)                     (((uint32_t)(((uint32_t)(x)) << USB_ENDPTNAK_EPTN_SHIFT)) & USB_ENDPTNAK_EPTN_MASK)
/*! @} */

/*! @name ENDPTNAKEN - Endpoint NAK Enable */
/*! @{ */

#define USB_ENDPTNAKEN_EPRNE_MASK                (0xFFU)
#define USB_ENDPTNAKEN_EPRNE_SHIFT               (0U)
/*! EPRNE - EPRNE */
#define USB_ENDPTNAKEN_EPRNE(x)                  (((uint32_t)(((uint32_t)(x)) << USB_ENDPTNAKEN_EPRNE_SHIFT)) & USB_ENDPTNAKEN_EPRNE_MASK)

#define USB_ENDPTNAKEN_EPTNE_MASK                (0xFF0000U)
#define USB_ENDPTNAKEN_EPTNE_SHIFT               (16U)
/*! EPTNE - EPTNE */
#define USB_ENDPTNAKEN_EPTNE(x)                  (((uint32_t)(((uint32_t)(x)) << USB_ENDPTNAKEN_EPTNE_SHIFT)) & USB_ENDPTNAKEN_EPTNE_MASK)
/*! @} */

/*! @name CONFIGFLAG - Configure Flag */
/*! @{ */

#define USB_CONFIGFLAG_CF_MASK                   (0x1U)
#define USB_CONFIGFLAG_CF_SHIFT                  (0U)
/*! CF - CF
 *  0b0..Port routing control logic default-routes each port to an implementation dependent classic host controller.
 *  0b1..Port routing control logic default-routes all ports to this host controller.
 */
#define USB_CONFIGFLAG_CF(x)                     (((uint32_t)(((uint32_t)(x)) << USB_CONFIGFLAG_CF_SHIFT)) & USB_CONFIGFLAG_CF_MASK)
/*! @} */

/*! @name PORTSC1 - Port Status & Control */
/*! @{ */

#define USB_PORTSC1_CCS_MASK                     (0x1U)
#define USB_PORTSC1_CCS_SHIFT                    (0U)
/*! CCS - CCS */
#define USB_PORTSC1_CCS(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_CCS_SHIFT)) & USB_PORTSC1_CCS_MASK)

#define USB_PORTSC1_CSC_MASK                     (0x2U)
#define USB_PORTSC1_CSC_SHIFT                    (1U)
/*! CSC - CSC */
#define USB_PORTSC1_CSC(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_CSC_SHIFT)) & USB_PORTSC1_CSC_MASK)

#define USB_PORTSC1_PE_MASK                      (0x4U)
#define USB_PORTSC1_PE_SHIFT                     (2U)
/*! PE - PE */
#define USB_PORTSC1_PE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PE_SHIFT)) & USB_PORTSC1_PE_MASK)

#define USB_PORTSC1_PEC_MASK                     (0x8U)
#define USB_PORTSC1_PEC_SHIFT                    (3U)
/*! PEC - PEC */
#define USB_PORTSC1_PEC(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PEC_SHIFT)) & USB_PORTSC1_PEC_MASK)

#define USB_PORTSC1_OCA_MASK                     (0x10U)
#define USB_PORTSC1_OCA_SHIFT                    (4U)
/*! OCA - OCA
 *  0b0..This port does not have an over-current condition.
 *  0b1..This port currently has an over-current condition
 */
#define USB_PORTSC1_OCA(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_OCA_SHIFT)) & USB_PORTSC1_OCA_MASK)

#define USB_PORTSC1_OCC_MASK                     (0x20U)
#define USB_PORTSC1_OCC_SHIFT                    (5U)
/*! OCC - OCC */
#define USB_PORTSC1_OCC(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_OCC_SHIFT)) & USB_PORTSC1_OCC_MASK)

#define USB_PORTSC1_FPR_MASK                     (0x40U)
#define USB_PORTSC1_FPR_SHIFT                    (6U)
/*! FPR - FPR */
#define USB_PORTSC1_FPR(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_FPR_SHIFT)) & USB_PORTSC1_FPR_MASK)

#define USB_PORTSC1_SUSP_MASK                    (0x80U)
#define USB_PORTSC1_SUSP_SHIFT                   (7U)
/*! SUSP - SUSP */
#define USB_PORTSC1_SUSP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_SUSP_SHIFT)) & USB_PORTSC1_SUSP_MASK)

#define USB_PORTSC1_PR_MASK                      (0x100U)
#define USB_PORTSC1_PR_SHIFT                     (8U)
/*! PR - PR */
#define USB_PORTSC1_PR(x)                        (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PR_SHIFT)) & USB_PORTSC1_PR_MASK)

#define USB_PORTSC1_HSP_MASK                     (0x200U)
#define USB_PORTSC1_HSP_SHIFT                    (9U)
/*! HSP - HSP */
#define USB_PORTSC1_HSP(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_HSP_SHIFT)) & USB_PORTSC1_HSP_MASK)

#define USB_PORTSC1_LS_MASK                      (0xC00U)
#define USB_PORTSC1_LS_SHIFT                     (10U)
/*! LS - LS
 *  0b00..SE0
 *  0b01..K-state
 *  0b10..J-state
 *  0b11..Undefined
 */
#define USB_PORTSC1_LS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_LS_SHIFT)) & USB_PORTSC1_LS_MASK)

#define USB_PORTSC1_PP_MASK                      (0x1000U)
#define USB_PORTSC1_PP_SHIFT                     (12U)
/*! PP - PP */
#define USB_PORTSC1_PP(x)                        (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PP_SHIFT)) & USB_PORTSC1_PP_MASK)

#define USB_PORTSC1_PO_MASK                      (0x2000U)
#define USB_PORTSC1_PO_SHIFT                     (13U)
/*! PO - PO */
#define USB_PORTSC1_PO(x)                        (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PO_SHIFT)) & USB_PORTSC1_PO_MASK)

#define USB_PORTSC1_PIC_MASK                     (0xC000U)
#define USB_PORTSC1_PIC_SHIFT                    (14U)
/*! PIC - PIC
 *  0b00..Port indicators are off
 *  0b01..Amber
 *  0b10..Green
 *  0b11..Undefined
 */
#define USB_PORTSC1_PIC(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PIC_SHIFT)) & USB_PORTSC1_PIC_MASK)

#define USB_PORTSC1_PTC_MASK                     (0xF0000U)
#define USB_PORTSC1_PTC_SHIFT                    (16U)
/*! PTC - PTC
 *  0b0000..TEST_MODE_DISABLE
 *  0b0001..J_STATE
 *  0b0010..K_STATE
 *  0b0011..SE0 (host) / NAK (device)
 *  0b0100..Packet
 *  0b0101..FORCE_ENABLE_HS
 *  0b0110..FORCE_ENABLE_FS
 *  0b0111..FORCE_ENABLE_LS
 *  0b1000-0b1111..Reserved
 */
#define USB_PORTSC1_PTC(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PTC_SHIFT)) & USB_PORTSC1_PTC_MASK)

#define USB_PORTSC1_WKCN_MASK                    (0x100000U)
#define USB_PORTSC1_WKCN_SHIFT                   (20U)
/*! WKCN - WKCN */
#define USB_PORTSC1_WKCN(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_WKCN_SHIFT)) & USB_PORTSC1_WKCN_MASK)

#define USB_PORTSC1_WKDC_MASK                    (0x200000U)
#define USB_PORTSC1_WKDC_SHIFT                   (21U)
/*! WKDC - WKDC */
#define USB_PORTSC1_WKDC(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_WKDC_SHIFT)) & USB_PORTSC1_WKDC_MASK)

#define USB_PORTSC1_WKOC_MASK                    (0x400000U)
#define USB_PORTSC1_WKOC_SHIFT                   (22U)
/*! WKOC - WKOC */
#define USB_PORTSC1_WKOC(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_WKOC_SHIFT)) & USB_PORTSC1_WKOC_MASK)

#define USB_PORTSC1_PHCD_MASK                    (0x800000U)
#define USB_PORTSC1_PHCD_SHIFT                   (23U)
/*! PHCD - PHCD
 *  0b0..Enable PHY clock
 *  0b1..Disable PHY clock
 */
#define USB_PORTSC1_PHCD(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PHCD_SHIFT)) & USB_PORTSC1_PHCD_MASK)

#define USB_PORTSC1_PFSC_MASK                    (0x1000000U)
#define USB_PORTSC1_PFSC_SHIFT                   (24U)
/*! PFSC - PFSC
 *  0b0..Normal operation
 *  0b1..Forced to full speed
 */
#define USB_PORTSC1_PFSC(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PFSC_SHIFT)) & USB_PORTSC1_PFSC_MASK)

#define USB_PORTSC1_PTS_2_MASK                   (0x2000000U)
#define USB_PORTSC1_PTS_2_SHIFT                  (25U)
/*! PTS_2 - PTS_2 */
#define USB_PORTSC1_PTS_2(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PTS_2_SHIFT)) & USB_PORTSC1_PTS_2_MASK)

#define USB_PORTSC1_PSPD_MASK                    (0xC000000U)
#define USB_PORTSC1_PSPD_SHIFT                   (26U)
/*! PSPD - PSPD
 *  0b00..Full Speed
 *  0b01..Low Speed
 *  0b10..High Speed
 *  0b11..Undefined
 */
#define USB_PORTSC1_PSPD(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PSPD_SHIFT)) & USB_PORTSC1_PSPD_MASK)

#define USB_PORTSC1_PTW_MASK                     (0x10000000U)
#define USB_PORTSC1_PTW_SHIFT                    (28U)
/*! PTW - PTW
 *  0b0..Select the 8-bit UTMI interface [60MHz]
 *  0b1..Select the 16-bit UTMI interface [30MHz]
 */
#define USB_PORTSC1_PTW(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PTW_SHIFT)) & USB_PORTSC1_PTW_MASK)

#define USB_PORTSC1_STS_MASK                     (0x20000000U)
#define USB_PORTSC1_STS_SHIFT                    (29U)
/*! STS - STS */
#define USB_PORTSC1_STS(x)                       (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_STS_SHIFT)) & USB_PORTSC1_STS_MASK)

#define USB_PORTSC1_PTS_1_MASK                   (0xC0000000U)
#define USB_PORTSC1_PTS_1_SHIFT                  (30U)
/*! PTS_1 - PTS_1 */
#define USB_PORTSC1_PTS_1(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC1_PTS_1_SHIFT)) & USB_PORTSC1_PTS_1_MASK)
/*! @} */

/*! @name OTGSC - On-The-Go Status & control */
/*! @{ */

#define USB_OTGSC_VD_MASK                        (0x1U)
#define USB_OTGSC_VD_SHIFT                       (0U)
/*! VD - VD */
#define USB_OTGSC_VD(x)                          (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_VD_SHIFT)) & USB_OTGSC_VD_MASK)

#define USB_OTGSC_VC_MASK                        (0x2U)
#define USB_OTGSC_VC_SHIFT                       (1U)
/*! VC - VC */
#define USB_OTGSC_VC(x)                          (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_VC_SHIFT)) & USB_OTGSC_VC_MASK)

#define USB_OTGSC_OT_MASK                        (0x8U)
#define USB_OTGSC_OT_SHIFT                       (3U)
/*! OT - OT */
#define USB_OTGSC_OT(x)                          (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_OT_SHIFT)) & USB_OTGSC_OT_MASK)

#define USB_OTGSC_DP_MASK                        (0x10U)
#define USB_OTGSC_DP_SHIFT                       (4U)
/*! DP - DP */
#define USB_OTGSC_DP(x)                          (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_DP_SHIFT)) & USB_OTGSC_DP_MASK)

#define USB_OTGSC_IDPU_MASK                      (0x20U)
#define USB_OTGSC_IDPU_SHIFT                     (5U)
/*! IDPU - IDPU */
#define USB_OTGSC_IDPU(x)                        (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_IDPU_SHIFT)) & USB_OTGSC_IDPU_MASK)

#define USB_OTGSC_ID_MASK                        (0x100U)
#define USB_OTGSC_ID_SHIFT                       (8U)
/*! ID - ID */
#define USB_OTGSC_ID(x)                          (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_ID_SHIFT)) & USB_OTGSC_ID_MASK)

#define USB_OTGSC_AVV_MASK                       (0x200U)
#define USB_OTGSC_AVV_SHIFT                      (9U)
/*! AVV - AVV */
#define USB_OTGSC_AVV(x)                         (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_AVV_SHIFT)) & USB_OTGSC_AVV_MASK)

#define USB_OTGSC_ASV_MASK                       (0x400U)
#define USB_OTGSC_ASV_SHIFT                      (10U)
/*! ASV - ASV */
#define USB_OTGSC_ASV(x)                         (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_ASV_SHIFT)) & USB_OTGSC_ASV_MASK)

#define USB_OTGSC_BSV_MASK                       (0x800U)
#define USB_OTGSC_BSV_SHIFT                      (11U)
/*! BSV - BSV */
#define USB_OTGSC_BSV(x)                         (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_BSV_SHIFT)) & USB_OTGSC_BSV_MASK)

#define USB_OTGSC_BSE_MASK                       (0x1000U)
#define USB_OTGSC_BSE_SHIFT                      (12U)
/*! BSE - BSE */
#define USB_OTGSC_BSE(x)                         (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_BSE_SHIFT)) & USB_OTGSC_BSE_MASK)

#define USB_OTGSC_TOG_1MS_MASK                   (0x2000U)
#define USB_OTGSC_TOG_1MS_SHIFT                  (13U)
/*! TOG_1MS - TOG_1MS */
#define USB_OTGSC_TOG_1MS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_TOG_1MS_SHIFT)) & USB_OTGSC_TOG_1MS_MASK)

#define USB_OTGSC_DPS_MASK                       (0x4000U)
#define USB_OTGSC_DPS_SHIFT                      (14U)
/*! DPS - DPS */
#define USB_OTGSC_DPS(x)                         (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_DPS_SHIFT)) & USB_OTGSC_DPS_MASK)

#define USB_OTGSC_IDIS_MASK                      (0x10000U)
#define USB_OTGSC_IDIS_SHIFT                     (16U)
/*! IDIS - IDIS */
#define USB_OTGSC_IDIS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_IDIS_SHIFT)) & USB_OTGSC_IDIS_MASK)

#define USB_OTGSC_AVVIS_MASK                     (0x20000U)
#define USB_OTGSC_AVVIS_SHIFT                    (17U)
/*! AVVIS - AVVIS */
#define USB_OTGSC_AVVIS(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_AVVIS_SHIFT)) & USB_OTGSC_AVVIS_MASK)

#define USB_OTGSC_ASVIS_MASK                     (0x40000U)
#define USB_OTGSC_ASVIS_SHIFT                    (18U)
/*! ASVIS - ASVIS */
#define USB_OTGSC_ASVIS(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_ASVIS_SHIFT)) & USB_OTGSC_ASVIS_MASK)

#define USB_OTGSC_BSVIS_MASK                     (0x80000U)
#define USB_OTGSC_BSVIS_SHIFT                    (19U)
/*! BSVIS - BSVIS */
#define USB_OTGSC_BSVIS(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_BSVIS_SHIFT)) & USB_OTGSC_BSVIS_MASK)

#define USB_OTGSC_BSEIS_MASK                     (0x100000U)
#define USB_OTGSC_BSEIS_SHIFT                    (20U)
/*! BSEIS - BSEIS */
#define USB_OTGSC_BSEIS(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_BSEIS_SHIFT)) & USB_OTGSC_BSEIS_MASK)

#define USB_OTGSC_STATUS_1MS_MASK                (0x200000U)
#define USB_OTGSC_STATUS_1MS_SHIFT               (21U)
/*! STATUS_1MS - STATUS_1MS */
#define USB_OTGSC_STATUS_1MS(x)                  (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_STATUS_1MS_SHIFT)) & USB_OTGSC_STATUS_1MS_MASK)

#define USB_OTGSC_DPIS_MASK                      (0x400000U)
#define USB_OTGSC_DPIS_SHIFT                     (22U)
/*! DPIS - DPIS */
#define USB_OTGSC_DPIS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_DPIS_SHIFT)) & USB_OTGSC_DPIS_MASK)

#define USB_OTGSC_IDIE_MASK                      (0x1000000U)
#define USB_OTGSC_IDIE_SHIFT                     (24U)
/*! IDIE - IDIE */
#define USB_OTGSC_IDIE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_IDIE_SHIFT)) & USB_OTGSC_IDIE_MASK)

#define USB_OTGSC_AVVIE_MASK                     (0x2000000U)
#define USB_OTGSC_AVVIE_SHIFT                    (25U)
/*! AVVIE - AVVIE */
#define USB_OTGSC_AVVIE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_AVVIE_SHIFT)) & USB_OTGSC_AVVIE_MASK)

#define USB_OTGSC_ASVIE_MASK                     (0x4000000U)
#define USB_OTGSC_ASVIE_SHIFT                    (26U)
/*! ASVIE - ASVIE */
#define USB_OTGSC_ASVIE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_ASVIE_SHIFT)) & USB_OTGSC_ASVIE_MASK)

#define USB_OTGSC_BSVIE_MASK                     (0x8000000U)
#define USB_OTGSC_BSVIE_SHIFT                    (27U)
/*! BSVIE - BSVIE */
#define USB_OTGSC_BSVIE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_BSVIE_SHIFT)) & USB_OTGSC_BSVIE_MASK)

#define USB_OTGSC_BSEIE_MASK                     (0x10000000U)
#define USB_OTGSC_BSEIE_SHIFT                    (28U)
/*! BSEIE - BSEIE */
#define USB_OTGSC_BSEIE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_BSEIE_SHIFT)) & USB_OTGSC_BSEIE_MASK)

#define USB_OTGSC_EN_1MS_MASK                    (0x20000000U)
#define USB_OTGSC_EN_1MS_SHIFT                   (29U)
/*! EN_1MS - EN_1MS */
#define USB_OTGSC_EN_1MS(x)                      (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_EN_1MS_SHIFT)) & USB_OTGSC_EN_1MS_MASK)

#define USB_OTGSC_DPIE_MASK                      (0x40000000U)
#define USB_OTGSC_DPIE_SHIFT                     (30U)
/*! DPIE - DPIE */
#define USB_OTGSC_DPIE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_OTGSC_DPIE_SHIFT)) & USB_OTGSC_DPIE_MASK)
/*! @} */

/*! @name USBMODE - USB Device Mode */
/*! @{ */

#define USB_USBMODE_CM_MASK                      (0x3U)
#define USB_USBMODE_CM_SHIFT                     (0U)
/*! CM - CM
 *  0b00..Idle [Default for combination host/device]
 *  0b01..Reserved
 *  0b10..Device Controller [Default for device only controller]
 *  0b11..Host Controller [Default for host only controller]
 */
#define USB_USBMODE_CM(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBMODE_CM_SHIFT)) & USB_USBMODE_CM_MASK)

#define USB_USBMODE_ES_MASK                      (0x4U)
#define USB_USBMODE_ES_SHIFT                     (2U)
/*! ES - ES
 *  0b0..Little Endian [Default]
 *  0b1..Big Endian
 */
#define USB_USBMODE_ES(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBMODE_ES_SHIFT)) & USB_USBMODE_ES_MASK)

#define USB_USBMODE_SLOM_MASK                    (0x8U)
#define USB_USBMODE_SLOM_SHIFT                   (3U)
/*! SLOM - SLOM
 *  0b0..Setup Lockouts On (default);
 *  0b1..Setup Lockouts Off
 */
#define USB_USBMODE_SLOM(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBMODE_SLOM_SHIFT)) & USB_USBMODE_SLOM_MASK)

#define USB_USBMODE_SDIS_MASK                    (0x10U)
#define USB_USBMODE_SDIS_SHIFT                   (4U)
/*! SDIS - SDIS */
#define USB_USBMODE_SDIS(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBMODE_SDIS_SHIFT)) & USB_USBMODE_SDIS_MASK)
/*! @} */

/*! @name ENDPTSETUPSTAT - Endpoint Setup Status */
/*! @{ */

#define USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK   (0xFFFFU)
#define USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT  (0U)
/*! ENDPTSETUPSTAT - ENDPTSETUPSTAT */
#define USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)     (((uint32_t)(((uint32_t)(x)) << USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT)) & USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK)
/*! @} */

/*! @name ENDPTPRIME - Endpoint Prime */
/*! @{ */

#define USB_ENDPTPRIME_PERB_MASK                 (0xFFU)
#define USB_ENDPTPRIME_PERB_SHIFT                (0U)
/*! PERB - PERB */
#define USB_ENDPTPRIME_PERB(x)                   (((uint32_t)(((uint32_t)(x)) << USB_ENDPTPRIME_PERB_SHIFT)) & USB_ENDPTPRIME_PERB_MASK)

#define USB_ENDPTPRIME_PETB_MASK                 (0xFF0000U)
#define USB_ENDPTPRIME_PETB_SHIFT                (16U)
/*! PETB - PETB */
#define USB_ENDPTPRIME_PETB(x)                   (((uint32_t)(((uint32_t)(x)) << USB_ENDPTPRIME_PETB_SHIFT)) & USB_ENDPTPRIME_PETB_MASK)
/*! @} */

/*! @name ENDPTFLUSH - Endpoint Flush */
/*! @{ */

#define USB_ENDPTFLUSH_FERB_MASK                 (0xFFU)
#define USB_ENDPTFLUSH_FERB_SHIFT                (0U)
/*! FERB - FERB */
#define USB_ENDPTFLUSH_FERB(x)                   (((uint32_t)(((uint32_t)(x)) << USB_ENDPTFLUSH_FERB_SHIFT)) & USB_ENDPTFLUSH_FERB_MASK)

#define USB_ENDPTFLUSH_FETB_MASK                 (0xFF0000U)
#define USB_ENDPTFLUSH_FETB_SHIFT                (16U)
/*! FETB - FETB */
#define USB_ENDPTFLUSH_FETB(x)                   (((uint32_t)(((uint32_t)(x)) << USB_ENDPTFLUSH_FETB_SHIFT)) & USB_ENDPTFLUSH_FETB_MASK)
/*! @} */

/*! @name ENDPTSTAT - Endpoint Status */
/*! @{ */

#define USB_ENDPTSTAT_ERBR_MASK                  (0xFFU)
#define USB_ENDPTSTAT_ERBR_SHIFT                 (0U)
/*! ERBR - ERBR */
#define USB_ENDPTSTAT_ERBR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTSTAT_ERBR_SHIFT)) & USB_ENDPTSTAT_ERBR_MASK)

#define USB_ENDPTSTAT_ETBR_MASK                  (0xFF0000U)
#define USB_ENDPTSTAT_ETBR_SHIFT                 (16U)
/*! ETBR - ETBR */
#define USB_ENDPTSTAT_ETBR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTSTAT_ETBR_SHIFT)) & USB_ENDPTSTAT_ETBR_MASK)
/*! @} */

/*! @name ENDPTCOMPLETE - Endpoint Complete */
/*! @{ */

#define USB_ENDPTCOMPLETE_ERCE_MASK              (0xFFU)
#define USB_ENDPTCOMPLETE_ERCE_SHIFT             (0U)
/*! ERCE - ERCE */
#define USB_ENDPTCOMPLETE_ERCE(x)                (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCOMPLETE_ERCE_SHIFT)) & USB_ENDPTCOMPLETE_ERCE_MASK)

#define USB_ENDPTCOMPLETE_ETCE_MASK              (0xFF0000U)
#define USB_ENDPTCOMPLETE_ETCE_SHIFT             (16U)
/*! ETCE - ETCE */
#define USB_ENDPTCOMPLETE_ETCE(x)                (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCOMPLETE_ETCE_SHIFT)) & USB_ENDPTCOMPLETE_ETCE_MASK)
/*! @} */

/*! @name ENDPTCTRL0 - Endpoint Control0 */
/*! @{ */

#define USB_ENDPTCTRL0_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL0_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL0_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL0_RXS_SHIFT)) & USB_ENDPTCTRL0_RXS_MASK)

#define USB_ENDPTCTRL0_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL0_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL0_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL0_RXT_SHIFT)) & USB_ENDPTCTRL0_RXT_MASK)

#define USB_ENDPTCTRL0_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL0_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL0_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL0_RXE_SHIFT)) & USB_ENDPTCTRL0_RXE_MASK)

#define USB_ENDPTCTRL0_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL0_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL0_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL0_TXS_SHIFT)) & USB_ENDPTCTRL0_TXS_MASK)

#define USB_ENDPTCTRL0_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL0_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL0_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL0_TXT_SHIFT)) & USB_ENDPTCTRL0_TXT_MASK)

#define USB_ENDPTCTRL0_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL0_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL0_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL0_TXE_SHIFT)) & USB_ENDPTCTRL0_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL1 - Endpoint Control 1 */
/*! @{ */

#define USB_ENDPTCTRL1_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL1_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL1_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_RXS_SHIFT)) & USB_ENDPTCTRL1_RXS_MASK)

#define USB_ENDPTCTRL1_RXD_MASK                  (0x2U)
#define USB_ENDPTCTRL1_RXD_SHIFT                 (1U)
/*! RXD - RXD */
#define USB_ENDPTCTRL1_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_RXD_SHIFT)) & USB_ENDPTCTRL1_RXD_MASK)

#define USB_ENDPTCTRL1_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL1_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL1_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_RXT_SHIFT)) & USB_ENDPTCTRL1_RXT_MASK)

#define USB_ENDPTCTRL1_RXI_MASK                  (0x20U)
#define USB_ENDPTCTRL1_RXI_SHIFT                 (5U)
/*! RXI - RXI */
#define USB_ENDPTCTRL1_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_RXI_SHIFT)) & USB_ENDPTCTRL1_RXI_MASK)

#define USB_ENDPTCTRL1_RXR_MASK                  (0x40U)
#define USB_ENDPTCTRL1_RXR_SHIFT                 (6U)
/*! RXR - RXR */
#define USB_ENDPTCTRL1_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_RXR_SHIFT)) & USB_ENDPTCTRL1_RXR_MASK)

#define USB_ENDPTCTRL1_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL1_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL1_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_RXE_SHIFT)) & USB_ENDPTCTRL1_RXE_MASK)

#define USB_ENDPTCTRL1_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL1_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL1_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_TXS_SHIFT)) & USB_ENDPTCTRL1_TXS_MASK)

#define USB_ENDPTCTRL1_TXD_MASK                  (0x20000U)
#define USB_ENDPTCTRL1_TXD_SHIFT                 (17U)
/*! TXD - TXD */
#define USB_ENDPTCTRL1_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_TXD_SHIFT)) & USB_ENDPTCTRL1_TXD_MASK)

#define USB_ENDPTCTRL1_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL1_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL1_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_TXT_SHIFT)) & USB_ENDPTCTRL1_TXT_MASK)

#define USB_ENDPTCTRL1_TXI_MASK                  (0x200000U)
#define USB_ENDPTCTRL1_TXI_SHIFT                 (21U)
/*! TXI - TXI */
#define USB_ENDPTCTRL1_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_TXI_SHIFT)) & USB_ENDPTCTRL1_TXI_MASK)

#define USB_ENDPTCTRL1_TXR_MASK                  (0x400000U)
#define USB_ENDPTCTRL1_TXR_SHIFT                 (22U)
/*! TXR - TXR */
#define USB_ENDPTCTRL1_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_TXR_SHIFT)) & USB_ENDPTCTRL1_TXR_MASK)

#define USB_ENDPTCTRL1_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL1_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL1_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL1_TXE_SHIFT)) & USB_ENDPTCTRL1_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL2 - Endpoint Control 2 */
/*! @{ */

#define USB_ENDPTCTRL2_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL2_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL2_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_RXS_SHIFT)) & USB_ENDPTCTRL2_RXS_MASK)

#define USB_ENDPTCTRL2_RXD_MASK                  (0x2U)
#define USB_ENDPTCTRL2_RXD_SHIFT                 (1U)
/*! RXD - RXD */
#define USB_ENDPTCTRL2_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_RXD_SHIFT)) & USB_ENDPTCTRL2_RXD_MASK)

#define USB_ENDPTCTRL2_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL2_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL2_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_RXT_SHIFT)) & USB_ENDPTCTRL2_RXT_MASK)

#define USB_ENDPTCTRL2_RXI_MASK                  (0x20U)
#define USB_ENDPTCTRL2_RXI_SHIFT                 (5U)
/*! RXI - RXI */
#define USB_ENDPTCTRL2_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_RXI_SHIFT)) & USB_ENDPTCTRL2_RXI_MASK)

#define USB_ENDPTCTRL2_RXR_MASK                  (0x40U)
#define USB_ENDPTCTRL2_RXR_SHIFT                 (6U)
/*! RXR - RXR */
#define USB_ENDPTCTRL2_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_RXR_SHIFT)) & USB_ENDPTCTRL2_RXR_MASK)

#define USB_ENDPTCTRL2_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL2_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL2_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_RXE_SHIFT)) & USB_ENDPTCTRL2_RXE_MASK)

#define USB_ENDPTCTRL2_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL2_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL2_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_TXS_SHIFT)) & USB_ENDPTCTRL2_TXS_MASK)

#define USB_ENDPTCTRL2_TXD_MASK                  (0x20000U)
#define USB_ENDPTCTRL2_TXD_SHIFT                 (17U)
/*! TXD - TXD */
#define USB_ENDPTCTRL2_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_TXD_SHIFT)) & USB_ENDPTCTRL2_TXD_MASK)

#define USB_ENDPTCTRL2_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL2_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL2_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_TXT_SHIFT)) & USB_ENDPTCTRL2_TXT_MASK)

#define USB_ENDPTCTRL2_TXI_MASK                  (0x200000U)
#define USB_ENDPTCTRL2_TXI_SHIFT                 (21U)
/*! TXI - TXI */
#define USB_ENDPTCTRL2_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_TXI_SHIFT)) & USB_ENDPTCTRL2_TXI_MASK)

#define USB_ENDPTCTRL2_TXR_MASK                  (0x400000U)
#define USB_ENDPTCTRL2_TXR_SHIFT                 (22U)
/*! TXR - TXR */
#define USB_ENDPTCTRL2_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_TXR_SHIFT)) & USB_ENDPTCTRL2_TXR_MASK)

#define USB_ENDPTCTRL2_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL2_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL2_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL2_TXE_SHIFT)) & USB_ENDPTCTRL2_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL3 - Endpoint Control 3 */
/*! @{ */

#define USB_ENDPTCTRL3_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL3_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL3_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_RXS_SHIFT)) & USB_ENDPTCTRL3_RXS_MASK)

#define USB_ENDPTCTRL3_RXD_MASK                  (0x2U)
#define USB_ENDPTCTRL3_RXD_SHIFT                 (1U)
/*! RXD - RXD */
#define USB_ENDPTCTRL3_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_RXD_SHIFT)) & USB_ENDPTCTRL3_RXD_MASK)

#define USB_ENDPTCTRL3_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL3_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL3_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_RXT_SHIFT)) & USB_ENDPTCTRL3_RXT_MASK)

#define USB_ENDPTCTRL3_RXI_MASK                  (0x20U)
#define USB_ENDPTCTRL3_RXI_SHIFT                 (5U)
/*! RXI - RXI */
#define USB_ENDPTCTRL3_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_RXI_SHIFT)) & USB_ENDPTCTRL3_RXI_MASK)

#define USB_ENDPTCTRL3_RXR_MASK                  (0x40U)
#define USB_ENDPTCTRL3_RXR_SHIFT                 (6U)
/*! RXR - RXR */
#define USB_ENDPTCTRL3_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_RXR_SHIFT)) & USB_ENDPTCTRL3_RXR_MASK)

#define USB_ENDPTCTRL3_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL3_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL3_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_RXE_SHIFT)) & USB_ENDPTCTRL3_RXE_MASK)

#define USB_ENDPTCTRL3_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL3_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL3_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_TXS_SHIFT)) & USB_ENDPTCTRL3_TXS_MASK)

#define USB_ENDPTCTRL3_TXD_MASK                  (0x20000U)
#define USB_ENDPTCTRL3_TXD_SHIFT                 (17U)
/*! TXD - TXD */
#define USB_ENDPTCTRL3_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_TXD_SHIFT)) & USB_ENDPTCTRL3_TXD_MASK)

#define USB_ENDPTCTRL3_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL3_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL3_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_TXT_SHIFT)) & USB_ENDPTCTRL3_TXT_MASK)

#define USB_ENDPTCTRL3_TXI_MASK                  (0x200000U)
#define USB_ENDPTCTRL3_TXI_SHIFT                 (21U)
/*! TXI - TXI */
#define USB_ENDPTCTRL3_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_TXI_SHIFT)) & USB_ENDPTCTRL3_TXI_MASK)

#define USB_ENDPTCTRL3_TXR_MASK                  (0x400000U)
#define USB_ENDPTCTRL3_TXR_SHIFT                 (22U)
/*! TXR - TXR */
#define USB_ENDPTCTRL3_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_TXR_SHIFT)) & USB_ENDPTCTRL3_TXR_MASK)

#define USB_ENDPTCTRL3_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL3_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL3_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL3_TXE_SHIFT)) & USB_ENDPTCTRL3_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL4 - Endpoint Control 4 */
/*! @{ */

#define USB_ENDPTCTRL4_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL4_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL4_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_RXS_SHIFT)) & USB_ENDPTCTRL4_RXS_MASK)

#define USB_ENDPTCTRL4_RXD_MASK                  (0x2U)
#define USB_ENDPTCTRL4_RXD_SHIFT                 (1U)
/*! RXD - RXD */
#define USB_ENDPTCTRL4_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_RXD_SHIFT)) & USB_ENDPTCTRL4_RXD_MASK)

#define USB_ENDPTCTRL4_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL4_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL4_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_RXT_SHIFT)) & USB_ENDPTCTRL4_RXT_MASK)

#define USB_ENDPTCTRL4_RXI_MASK                  (0x20U)
#define USB_ENDPTCTRL4_RXI_SHIFT                 (5U)
/*! RXI - RXI */
#define USB_ENDPTCTRL4_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_RXI_SHIFT)) & USB_ENDPTCTRL4_RXI_MASK)

#define USB_ENDPTCTRL4_RXR_MASK                  (0x40U)
#define USB_ENDPTCTRL4_RXR_SHIFT                 (6U)
/*! RXR - RXR */
#define USB_ENDPTCTRL4_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_RXR_SHIFT)) & USB_ENDPTCTRL4_RXR_MASK)

#define USB_ENDPTCTRL4_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL4_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL4_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_RXE_SHIFT)) & USB_ENDPTCTRL4_RXE_MASK)

#define USB_ENDPTCTRL4_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL4_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL4_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_TXS_SHIFT)) & USB_ENDPTCTRL4_TXS_MASK)

#define USB_ENDPTCTRL4_TXD_MASK                  (0x20000U)
#define USB_ENDPTCTRL4_TXD_SHIFT                 (17U)
/*! TXD - TXD */
#define USB_ENDPTCTRL4_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_TXD_SHIFT)) & USB_ENDPTCTRL4_TXD_MASK)

#define USB_ENDPTCTRL4_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL4_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL4_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_TXT_SHIFT)) & USB_ENDPTCTRL4_TXT_MASK)

#define USB_ENDPTCTRL4_TXI_MASK                  (0x200000U)
#define USB_ENDPTCTRL4_TXI_SHIFT                 (21U)
/*! TXI - TXI */
#define USB_ENDPTCTRL4_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_TXI_SHIFT)) & USB_ENDPTCTRL4_TXI_MASK)

#define USB_ENDPTCTRL4_TXR_MASK                  (0x400000U)
#define USB_ENDPTCTRL4_TXR_SHIFT                 (22U)
/*! TXR - TXR */
#define USB_ENDPTCTRL4_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_TXR_SHIFT)) & USB_ENDPTCTRL4_TXR_MASK)

#define USB_ENDPTCTRL4_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL4_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL4_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL4_TXE_SHIFT)) & USB_ENDPTCTRL4_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL5 - Endpoint Control 5 */
/*! @{ */

#define USB_ENDPTCTRL5_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL5_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL5_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_RXS_SHIFT)) & USB_ENDPTCTRL5_RXS_MASK)

#define USB_ENDPTCTRL5_RXD_MASK                  (0x2U)
#define USB_ENDPTCTRL5_RXD_SHIFT                 (1U)
/*! RXD - RXD */
#define USB_ENDPTCTRL5_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_RXD_SHIFT)) & USB_ENDPTCTRL5_RXD_MASK)

#define USB_ENDPTCTRL5_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL5_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL5_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_RXT_SHIFT)) & USB_ENDPTCTRL5_RXT_MASK)

#define USB_ENDPTCTRL5_RXI_MASK                  (0x20U)
#define USB_ENDPTCTRL5_RXI_SHIFT                 (5U)
/*! RXI - RXI */
#define USB_ENDPTCTRL5_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_RXI_SHIFT)) & USB_ENDPTCTRL5_RXI_MASK)

#define USB_ENDPTCTRL5_RXR_MASK                  (0x40U)
#define USB_ENDPTCTRL5_RXR_SHIFT                 (6U)
/*! RXR - RXR */
#define USB_ENDPTCTRL5_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_RXR_SHIFT)) & USB_ENDPTCTRL5_RXR_MASK)

#define USB_ENDPTCTRL5_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL5_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL5_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_RXE_SHIFT)) & USB_ENDPTCTRL5_RXE_MASK)

#define USB_ENDPTCTRL5_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL5_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL5_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_TXS_SHIFT)) & USB_ENDPTCTRL5_TXS_MASK)

#define USB_ENDPTCTRL5_TXD_MASK                  (0x20000U)
#define USB_ENDPTCTRL5_TXD_SHIFT                 (17U)
/*! TXD - TXD */
#define USB_ENDPTCTRL5_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_TXD_SHIFT)) & USB_ENDPTCTRL5_TXD_MASK)

#define USB_ENDPTCTRL5_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL5_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL5_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_TXT_SHIFT)) & USB_ENDPTCTRL5_TXT_MASK)

#define USB_ENDPTCTRL5_TXI_MASK                  (0x200000U)
#define USB_ENDPTCTRL5_TXI_SHIFT                 (21U)
/*! TXI - TXI */
#define USB_ENDPTCTRL5_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_TXI_SHIFT)) & USB_ENDPTCTRL5_TXI_MASK)

#define USB_ENDPTCTRL5_TXR_MASK                  (0x400000U)
#define USB_ENDPTCTRL5_TXR_SHIFT                 (22U)
/*! TXR - TXR */
#define USB_ENDPTCTRL5_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_TXR_SHIFT)) & USB_ENDPTCTRL5_TXR_MASK)

#define USB_ENDPTCTRL5_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL5_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL5_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL5_TXE_SHIFT)) & USB_ENDPTCTRL5_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL6 - Endpoint Control 6 */
/*! @{ */

#define USB_ENDPTCTRL6_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL6_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL6_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_RXS_SHIFT)) & USB_ENDPTCTRL6_RXS_MASK)

#define USB_ENDPTCTRL6_RXD_MASK                  (0x2U)
#define USB_ENDPTCTRL6_RXD_SHIFT                 (1U)
/*! RXD - RXD */
#define USB_ENDPTCTRL6_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_RXD_SHIFT)) & USB_ENDPTCTRL6_RXD_MASK)

#define USB_ENDPTCTRL6_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL6_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL6_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_RXT_SHIFT)) & USB_ENDPTCTRL6_RXT_MASK)

#define USB_ENDPTCTRL6_RXI_MASK                  (0x20U)
#define USB_ENDPTCTRL6_RXI_SHIFT                 (5U)
/*! RXI - RXI */
#define USB_ENDPTCTRL6_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_RXI_SHIFT)) & USB_ENDPTCTRL6_RXI_MASK)

#define USB_ENDPTCTRL6_RXR_MASK                  (0x40U)
#define USB_ENDPTCTRL6_RXR_SHIFT                 (6U)
/*! RXR - RXR */
#define USB_ENDPTCTRL6_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_RXR_SHIFT)) & USB_ENDPTCTRL6_RXR_MASK)

#define USB_ENDPTCTRL6_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL6_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL6_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_RXE_SHIFT)) & USB_ENDPTCTRL6_RXE_MASK)

#define USB_ENDPTCTRL6_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL6_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL6_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_TXS_SHIFT)) & USB_ENDPTCTRL6_TXS_MASK)

#define USB_ENDPTCTRL6_TXD_MASK                  (0x20000U)
#define USB_ENDPTCTRL6_TXD_SHIFT                 (17U)
/*! TXD - TXD */
#define USB_ENDPTCTRL6_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_TXD_SHIFT)) & USB_ENDPTCTRL6_TXD_MASK)

#define USB_ENDPTCTRL6_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL6_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL6_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_TXT_SHIFT)) & USB_ENDPTCTRL6_TXT_MASK)

#define USB_ENDPTCTRL6_TXI_MASK                  (0x200000U)
#define USB_ENDPTCTRL6_TXI_SHIFT                 (21U)
/*! TXI - TXI */
#define USB_ENDPTCTRL6_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_TXI_SHIFT)) & USB_ENDPTCTRL6_TXI_MASK)

#define USB_ENDPTCTRL6_TXR_MASK                  (0x400000U)
#define USB_ENDPTCTRL6_TXR_SHIFT                 (22U)
/*! TXR - TXR */
#define USB_ENDPTCTRL6_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_TXR_SHIFT)) & USB_ENDPTCTRL6_TXR_MASK)

#define USB_ENDPTCTRL6_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL6_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL6_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL6_TXE_SHIFT)) & USB_ENDPTCTRL6_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL7 - Endpoint Control 7 */
/*! @{ */

#define USB_ENDPTCTRL7_RXS_MASK                  (0x1U)
#define USB_ENDPTCTRL7_RXS_SHIFT                 (0U)
/*! RXS - RXS */
#define USB_ENDPTCTRL7_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_RXS_SHIFT)) & USB_ENDPTCTRL7_RXS_MASK)

#define USB_ENDPTCTRL7_RXD_MASK                  (0x2U)
#define USB_ENDPTCTRL7_RXD_SHIFT                 (1U)
/*! RXD - RXD */
#define USB_ENDPTCTRL7_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_RXD_SHIFT)) & USB_ENDPTCTRL7_RXD_MASK)

#define USB_ENDPTCTRL7_RXT_MASK                  (0xCU)
#define USB_ENDPTCTRL7_RXT_SHIFT                 (2U)
/*! RXT - RXT */
#define USB_ENDPTCTRL7_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_RXT_SHIFT)) & USB_ENDPTCTRL7_RXT_MASK)

#define USB_ENDPTCTRL7_RXI_MASK                  (0x20U)
#define USB_ENDPTCTRL7_RXI_SHIFT                 (5U)
/*! RXI - RXI */
#define USB_ENDPTCTRL7_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_RXI_SHIFT)) & USB_ENDPTCTRL7_RXI_MASK)

#define USB_ENDPTCTRL7_RXR_MASK                  (0x40U)
#define USB_ENDPTCTRL7_RXR_SHIFT                 (6U)
/*! RXR - RXR */
#define USB_ENDPTCTRL7_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_RXR_SHIFT)) & USB_ENDPTCTRL7_RXR_MASK)

#define USB_ENDPTCTRL7_RXE_MASK                  (0x80U)
#define USB_ENDPTCTRL7_RXE_SHIFT                 (7U)
/*! RXE - RXE */
#define USB_ENDPTCTRL7_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_RXE_SHIFT)) & USB_ENDPTCTRL7_RXE_MASK)

#define USB_ENDPTCTRL7_TXS_MASK                  (0x10000U)
#define USB_ENDPTCTRL7_TXS_SHIFT                 (16U)
/*! TXS - TXS */
#define USB_ENDPTCTRL7_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_TXS_SHIFT)) & USB_ENDPTCTRL7_TXS_MASK)

#define USB_ENDPTCTRL7_TXD_MASK                  (0x20000U)
#define USB_ENDPTCTRL7_TXD_SHIFT                 (17U)
/*! TXD - TXD */
#define USB_ENDPTCTRL7_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_TXD_SHIFT)) & USB_ENDPTCTRL7_TXD_MASK)

#define USB_ENDPTCTRL7_TXT_MASK                  (0xC0000U)
#define USB_ENDPTCTRL7_TXT_SHIFT                 (18U)
/*! TXT - TXT */
#define USB_ENDPTCTRL7_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_TXT_SHIFT)) & USB_ENDPTCTRL7_TXT_MASK)

#define USB_ENDPTCTRL7_TXI_MASK                  (0x200000U)
#define USB_ENDPTCTRL7_TXI_SHIFT                 (21U)
/*! TXI - TXI */
#define USB_ENDPTCTRL7_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_TXI_SHIFT)) & USB_ENDPTCTRL7_TXI_MASK)

#define USB_ENDPTCTRL7_TXR_MASK                  (0x400000U)
#define USB_ENDPTCTRL7_TXR_SHIFT                 (22U)
/*! TXR - TXR */
#define USB_ENDPTCTRL7_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_TXR_SHIFT)) & USB_ENDPTCTRL7_TXR_MASK)

#define USB_ENDPTCTRL7_TXE_MASK                  (0x800000U)
#define USB_ENDPTCTRL7_TXE_SHIFT                 (23U)
/*! TXE - TXE */
#define USB_ENDPTCTRL7_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_ENDPTCTRL7_TXE_SHIFT)) & USB_ENDPTCTRL7_TXE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USB_Register_Masks */


/*!
 * @}
 */ /* end of group USB_Peripheral_Access_Layer */


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


#endif  /* PERI_USB_H_ */
