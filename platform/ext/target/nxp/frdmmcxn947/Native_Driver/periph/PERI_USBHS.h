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
**         CMSIS Peripheral Access Layer for USBHS
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
 * @file PERI_USBHS.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBHS
 *
 * CMSIS Peripheral Access Layer for USBHS
 */

#if !defined(PERI_USBHS_H_)
#define PERI_USBHS_H_                            /**< Symbol preventing repeated inclusion */

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
   -- USBHS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHS_Peripheral_Access_Layer USBHS Peripheral Access Layer
 * @{
 */

/** USBHS - Size of Registers Arrays */
#define USBHS_ENDPTCTRL_COUNT                     7u

/** USBHS - Register Layout Typedef */
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
    __IO uint32_t DEVICEADDR;                        /**< Device Address, offset: 0x154 */
    __IO uint32_t PERIODICLISTBASE;                  /**< Frame List Base Address, offset: 0x154 */
  };
  union {                                          /* offset: 0x158 */
    __IO uint32_t ASYNCLISTADDR;                     /**< Next Asynch. Address, offset: 0x158 */
    __IO uint32_t ENDPTLISTADDR;                     /**< Endpoint List Address, offset: 0x158 */
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
  __IO uint32_t OTGSC;                             /**< On-The-Go Status & Control, offset: 0x1A4 */
  __IO uint32_t USBMODE;                           /**< USB Device Mode, offset: 0x1A8 */
  __IO uint32_t ENDPTSETUPSTAT;                    /**< Endpoint Setup Status, offset: 0x1AC */
  __IO uint32_t ENDPTPRIME;                        /**< Endpoint Prime, offset: 0x1B0 */
  __IO uint32_t ENDPTFLUSH;                        /**< Endpoint Flush, offset: 0x1B4 */
  __I  uint32_t ENDPTSTAT;                         /**< Endpoint Status, offset: 0x1B8 */
  __IO uint32_t ENDPTCOMPLETE;                     /**< Endpoint Complete, offset: 0x1BC */
  __IO uint32_t ENDPTCTRL0;                        /**< Endpoint Control 0, offset: 0x1C0 */
  __IO uint32_t ENDPTCTRL[USBHS_ENDPTCTRL_COUNT];  /**< Endpoint Control 1..Endpoint Control 7, array offset: 0x1C4, array step: 0x4 */
} USBHS_Type;

/* ----------------------------------------------------------------------------
   -- USBHS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHS_Register_Masks USBHS Register Masks
 * @{
 */

/*! @name ID - Identification */
/*! @{ */

#define USBHS_ID_ID_MASK                         (0x3FU)
#define USBHS_ID_ID_SHIFT                        (0U)
/*! ID - Configuration Number */
#define USBHS_ID_ID(x)                           (((uint32_t)(((uint32_t)(x)) << USBHS_ID_ID_SHIFT)) & USBHS_ID_ID_MASK)

#define USBHS_ID_NID_MASK                        (0x3F00U)
#define USBHS_ID_NID_SHIFT                       (8U)
/*! NID - Complement Version of ID */
#define USBHS_ID_NID(x)                          (((uint32_t)(((uint32_t)(x)) << USBHS_ID_NID_SHIFT)) & USBHS_ID_NID_MASK)

#define USBHS_ID_REVISION_MASK                   (0xFF0000U)
#define USBHS_ID_REVISION_SHIFT                  (16U)
/*! REVISION - Revision Number of the Controller Core */
#define USBHS_ID_REVISION(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_ID_REVISION_SHIFT)) & USBHS_ID_REVISION_MASK)
/*! @} */

/*! @name HWGENERAL - Hardware General */
/*! @{ */

#define USBHS_HWGENERAL_PHYW_MASK                (0x30U)
#define USBHS_HWGENERAL_PHYW_SHIFT               (4U)
/*! PHYW - Data width of the transceiver connected to the controller core
 *  0b00..8 bit wide data bus (Software non-programmable)
 *  0b01..16 bit wide data bus (Software non-programmable)
 *  0b10..Reset to 8 bit wide data bus (Software programmable)
 *  0b11..Reset to 16 bit wide data bus (Software programmable)
 */
#define USBHS_HWGENERAL_PHYW(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_HWGENERAL_PHYW_SHIFT)) & USBHS_HWGENERAL_PHYW_MASK)

#define USBHS_HWGENERAL_PHYM_MASK                (0x1C0U)
#define USBHS_HWGENERAL_PHYM_SHIFT               (6U)
/*! PHYM - Transceiver Type
 *  0b000..UTMI/UMTI+
 *  0b001..ULPI DDR
 *  0b010..ULPI
 *  0b011..Serial Only
 *  0b100..Software programmable - reset to UTMI/UTMI+
 *  0b101..Software programmable - reset to ULPI DDR
 *  0b110..Software programmable - reset to ULPI
 *  0b111..Software programmable - reset to Serial
 */
#define USBHS_HWGENERAL_PHYM(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_HWGENERAL_PHYM_SHIFT)) & USBHS_HWGENERAL_PHYM_MASK)

#define USBHS_HWGENERAL_SM_MASK                  (0x600U)
#define USBHS_HWGENERAL_SM_SHIFT                 (9U)
/*! SM - Serial interface mode capability
 *  0b00..No Serial Engine, always use parallel signalling
 *  0b01..Serial Engine present, always use serial signalling for FS/LS
 *  0b10..Software programmable - Reset to use parallel signalling for FS/LS
 *  0b11..Software programmable - Reset to use serial signalling for FS/LS
 */
#define USBHS_HWGENERAL_SM(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_HWGENERAL_SM_SHIFT)) & USBHS_HWGENERAL_SM_MASK)
/*! @} */

/*! @name HWHOST - Host Hardware Parameters */
/*! @{ */

#define USBHS_HWHOST_HC_MASK                     (0x1U)
#define USBHS_HWHOST_HC_SHIFT                    (0U)
/*! HC - Host Capable
 *  0b0..Not supported
 *  0b1..Supported
 */
#define USBHS_HWHOST_HC(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_HWHOST_HC_SHIFT)) & USBHS_HWHOST_HC_MASK)

#define USBHS_HWHOST_NPORT_MASK                  (0xEU)
#define USBHS_HWHOST_NPORT_SHIFT                 (1U)
/*! NPORT - The Number of downstream ports supported by the host controller is (NPORT+1) */
#define USBHS_HWHOST_NPORT(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_HWHOST_NPORT_SHIFT)) & USBHS_HWHOST_NPORT_MASK)
/*! @} */

/*! @name HWDEVICE - Device Hardware Parameters */
/*! @{ */

#define USBHS_HWDEVICE_DC_MASK                   (0x1U)
#define USBHS_HWDEVICE_DC_SHIFT                  (0U)
/*! DC - Device Capable
 *  0b0..Not supported
 *  0b1..Supported
 */
#define USBHS_HWDEVICE_DC(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_HWDEVICE_DC_SHIFT)) & USBHS_HWDEVICE_DC_MASK)

#define USBHS_HWDEVICE_DEVEP_MASK                (0x3EU)
#define USBHS_HWDEVICE_DEVEP_SHIFT               (1U)
/*! DEVEP - Device Endpoint Number */
#define USBHS_HWDEVICE_DEVEP(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_HWDEVICE_DEVEP_SHIFT)) & USBHS_HWDEVICE_DEVEP_MASK)
/*! @} */

/*! @name HWTXBUF - TX Buffer Hardware Parameters */
/*! @{ */

#define USBHS_HWTXBUF_TXBURST_MASK               (0xFFU)
#define USBHS_HWTXBUF_TXBURST_SHIFT              (0U)
/*! TXBURST - Default burst size for memory to TX buffer transfer */
#define USBHS_HWTXBUF_TXBURST(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_HWTXBUF_TXBURST_SHIFT)) & USBHS_HWTXBUF_TXBURST_MASK)

#define USBHS_HWTXBUF_TXCHANADD_MASK             (0xFF0000U)
#define USBHS_HWTXBUF_TXCHANADD_SHIFT            (16U)
/*! TXCHANADD - TX FIFO Buffer size is: (2^TXCHANADD) * 4 Bytes */
#define USBHS_HWTXBUF_TXCHANADD(x)               (((uint32_t)(((uint32_t)(x)) << USBHS_HWTXBUF_TXCHANADD_SHIFT)) & USBHS_HWTXBUF_TXCHANADD_MASK)
/*! @} */

/*! @name HWRXBUF - RX Buffer Hardware Parameters */
/*! @{ */

#define USBHS_HWRXBUF_RXBURST_MASK               (0xFFU)
#define USBHS_HWRXBUF_RXBURST_SHIFT              (0U)
/*! RXBURST - Default burst size for memory to RX buffer transfer */
#define USBHS_HWRXBUF_RXBURST(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_HWRXBUF_RXBURST_SHIFT)) & USBHS_HWRXBUF_RXBURST_MASK)

#define USBHS_HWRXBUF_RXADD_MASK                 (0xFF00U)
#define USBHS_HWRXBUF_RXADD_SHIFT                (8U)
/*! RXADD - Buffer total size for all receive endpoints is (2^RXADD) */
#define USBHS_HWRXBUF_RXADD(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_HWRXBUF_RXADD_SHIFT)) & USBHS_HWRXBUF_RXADD_MASK)
/*! @} */

/*! @name GPTIMER0LD - General Purpose Timer #0 Load */
/*! @{ */

#define USBHS_GPTIMER0LD_GPTLD_MASK              (0xFFFFFFU)
#define USBHS_GPTIMER0LD_GPTLD_SHIFT             (0U)
/*! GPTLD - General Purpose Timer Load Value */
#define USBHS_GPTIMER0LD_GPTLD(x)                (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER0LD_GPTLD_SHIFT)) & USBHS_GPTIMER0LD_GPTLD_MASK)
/*! @} */

/*! @name GPTIMER0CTRL - General Purpose Timer #0 Controller */
/*! @{ */

#define USBHS_GPTIMER0CTRL_GPTCNT_MASK           (0xFFFFFFU)
#define USBHS_GPTIMER0CTRL_GPTCNT_SHIFT          (0U)
/*! GPTCNT - General Purpose Timer Counter */
#define USBHS_GPTIMER0CTRL_GPTCNT(x)             (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER0CTRL_GPTCNT_SHIFT)) & USBHS_GPTIMER0CTRL_GPTCNT_MASK)

#define USBHS_GPTIMER0CTRL_GPTMODE_MASK          (0x1000000U)
#define USBHS_GPTIMER0CTRL_GPTMODE_SHIFT         (24U)
/*! GPTMODE - General Purpose Timer Mode
 *  0b0..One Shot Mode
 *  0b1..Repeat Mode
 */
#define USBHS_GPTIMER0CTRL_GPTMODE(x)            (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER0CTRL_GPTMODE_SHIFT)) & USBHS_GPTIMER0CTRL_GPTMODE_MASK)

#define USBHS_GPTIMER0CTRL_GPTRST_MASK           (0x40000000U)
#define USBHS_GPTIMER0CTRL_GPTRST_SHIFT          (30U)
/*! GPTRST - General Purpose Timer Reset
 *  0b0..No action
 *  0b1..Load counter value from GPTLD bits in n_GPTIMER0LD
 */
#define USBHS_GPTIMER0CTRL_GPTRST(x)             (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER0CTRL_GPTRST_SHIFT)) & USBHS_GPTIMER0CTRL_GPTRST_MASK)

#define USBHS_GPTIMER0CTRL_GPTRUN_MASK           (0x80000000U)
#define USBHS_GPTIMER0CTRL_GPTRUN_SHIFT          (31U)
/*! GPTRUN - General Purpose Timer Run
 *  0b0..Stop counting
 *  0b1..Run
 */
#define USBHS_GPTIMER0CTRL_GPTRUN(x)             (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER0CTRL_GPTRUN_SHIFT)) & USBHS_GPTIMER0CTRL_GPTRUN_MASK)
/*! @} */

/*! @name GPTIMER1LD - General Purpose Timer #1 Load */
/*! @{ */

#define USBHS_GPTIMER1LD_GPTLD_MASK              (0xFFFFFFU)
#define USBHS_GPTIMER1LD_GPTLD_SHIFT             (0U)
/*! GPTLD - General Purpose Timer Load Value */
#define USBHS_GPTIMER1LD_GPTLD(x)                (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER1LD_GPTLD_SHIFT)) & USBHS_GPTIMER1LD_GPTLD_MASK)
/*! @} */

/*! @name GPTIMER1CTRL - General Purpose Timer #1 Controller */
/*! @{ */

#define USBHS_GPTIMER1CTRL_GPTCNT_MASK           (0xFFFFFFU)
#define USBHS_GPTIMER1CTRL_GPTCNT_SHIFT          (0U)
/*! GPTCNT - General Purpose Timer Counter */
#define USBHS_GPTIMER1CTRL_GPTCNT(x)             (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER1CTRL_GPTCNT_SHIFT)) & USBHS_GPTIMER1CTRL_GPTCNT_MASK)

#define USBHS_GPTIMER1CTRL_GPTMODE_MASK          (0x1000000U)
#define USBHS_GPTIMER1CTRL_GPTMODE_SHIFT         (24U)
/*! GPTMODE - General Purpose Timer Mode
 *  0b0..One Shot Mode
 *  0b1..Repeat Mode
 */
#define USBHS_GPTIMER1CTRL_GPTMODE(x)            (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER1CTRL_GPTMODE_SHIFT)) & USBHS_GPTIMER1CTRL_GPTMODE_MASK)

#define USBHS_GPTIMER1CTRL_GPTRST_MASK           (0x40000000U)
#define USBHS_GPTIMER1CTRL_GPTRST_SHIFT          (30U)
/*! GPTRST - General Purpose Timer Reset
 *  0b0..No action
 *  0b1..Load counter value from GPTLD bits in USB_n_GPTIMER0LD
 */
#define USBHS_GPTIMER1CTRL_GPTRST(x)             (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER1CTRL_GPTRST_SHIFT)) & USBHS_GPTIMER1CTRL_GPTRST_MASK)

#define USBHS_GPTIMER1CTRL_GPTRUN_MASK           (0x80000000U)
#define USBHS_GPTIMER1CTRL_GPTRUN_SHIFT          (31U)
/*! GPTRUN - General Purpose Timer Run
 *  0b0..Stop counting
 *  0b1..Run
 */
#define USBHS_GPTIMER1CTRL_GPTRUN(x)             (((uint32_t)(((uint32_t)(x)) << USBHS_GPTIMER1CTRL_GPTRUN_SHIFT)) & USBHS_GPTIMER1CTRL_GPTRUN_MASK)
/*! @} */

/*! @name SBUSCFG - System Bus Config */
/*! @{ */

#define USBHS_SBUSCFG_AHBBRST_MASK               (0x7U)
#define USBHS_SBUSCFG_AHBBRST_SHIFT              (0U)
/*! AHBBRST - AHB master interface Burst configuration
 *  0b000..Incremental burst of unspecified length only
 *  0b001..INCR4 burst, then single transfer
 *  0b010..INCR8 burst, INCR4 burst, then single transfer
 *  0b011..INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
 *  0b100..Reserved, don't use
 *  0b101..INCR4 burst, then incremental burst of unspecified length
 *  0b110..INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 *  0b111..INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 */
#define USBHS_SBUSCFG_AHBBRST(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_SBUSCFG_AHBBRST_SHIFT)) & USBHS_SBUSCFG_AHBBRST_MASK)
/*! @} */

/*! @name CAPLENGTH - Capability Registers Length */
/*! @{ */

#define USBHS_CAPLENGTH_CAPLENGTH_MASK           (0xFFU)
#define USBHS_CAPLENGTH_CAPLENGTH_SHIFT          (0U)
/*! CAPLENGTH - These bits are used as an offset to add to register base to find the beginning of
 *    the Operational Register. Default value is '40h'.
 */
#define USBHS_CAPLENGTH_CAPLENGTH(x)             (((uint8_t)(((uint8_t)(x)) << USBHS_CAPLENGTH_CAPLENGTH_SHIFT)) & USBHS_CAPLENGTH_CAPLENGTH_MASK)
/*! @} */

/*! @name HCIVERSION - Host Controller Interface Version */
/*! @{ */

#define USBHS_HCIVERSION_HCIVERSION_MASK         (0xFFFFU)
#define USBHS_HCIVERSION_HCIVERSION_SHIFT        (0U)
/*! HCIVERSION - Host Controller Interface Version Number */
#define USBHS_HCIVERSION_HCIVERSION(x)           (((uint16_t)(((uint16_t)(x)) << USBHS_HCIVERSION_HCIVERSION_SHIFT)) & USBHS_HCIVERSION_HCIVERSION_MASK)
/*! @} */

/*! @name HCSPARAMS - Host Controller Structural Parameters */
/*! @{ */

#define USBHS_HCSPARAMS_N_PORTS_MASK             (0xFU)
#define USBHS_HCSPARAMS_N_PORTS_SHIFT            (0U)
/*! N_PORTS - Number of Downstream Ports */
#define USBHS_HCSPARAMS_N_PORTS(x)               (((uint32_t)(((uint32_t)(x)) << USBHS_HCSPARAMS_N_PORTS_SHIFT)) & USBHS_HCSPARAMS_N_PORTS_MASK)

#define USBHS_HCSPARAMS_PPC_MASK                 (0x10U)
#define USBHS_HCSPARAMS_PPC_SHIFT                (4U)
/*! PPC - Port Power Control */
#define USBHS_HCSPARAMS_PPC(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_HCSPARAMS_PPC_SHIFT)) & USBHS_HCSPARAMS_PPC_MASK)

#define USBHS_HCSPARAMS_N_PCC_MASK               (0xF00U)
#define USBHS_HCSPARAMS_N_PCC_SHIFT              (8U)
/*! N_PCC - Number of Ports per Companion Controller */
#define USBHS_HCSPARAMS_N_PCC(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_HCSPARAMS_N_PCC_SHIFT)) & USBHS_HCSPARAMS_N_PCC_MASK)

#define USBHS_HCSPARAMS_N_CC_MASK                (0xF000U)
#define USBHS_HCSPARAMS_N_CC_SHIFT               (12U)
/*! N_CC - Number of Companion Controller
 *  0b0000..There is no internal Companion Controller and port-ownership hand-off is not supported
 *  0b0001..There are internal companion controller(s) and port-ownership hand-offs is supported
 */
#define USBHS_HCSPARAMS_N_CC(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_HCSPARAMS_N_CC_SHIFT)) & USBHS_HCSPARAMS_N_CC_MASK)

#define USBHS_HCSPARAMS_PI_MASK                  (0x10000U)
#define USBHS_HCSPARAMS_PI_SHIFT                 (16U)
/*! PI - Port Indicators (P INDICATOR) */
#define USBHS_HCSPARAMS_PI(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_HCSPARAMS_PI_SHIFT)) & USBHS_HCSPARAMS_PI_MASK)

#define USBHS_HCSPARAMS_N_PTT_MASK               (0xF00000U)
#define USBHS_HCSPARAMS_N_PTT_SHIFT              (20U)
/*! N_PTT - Number of Ports per Transaction Translator */
#define USBHS_HCSPARAMS_N_PTT(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_HCSPARAMS_N_PTT_SHIFT)) & USBHS_HCSPARAMS_N_PTT_MASK)

#define USBHS_HCSPARAMS_N_TT_MASK                (0xF000000U)
#define USBHS_HCSPARAMS_N_TT_SHIFT               (24U)
/*! N_TT - Number of Transaction Translators */
#define USBHS_HCSPARAMS_N_TT(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_HCSPARAMS_N_TT_SHIFT)) & USBHS_HCSPARAMS_N_TT_MASK)
/*! @} */

/*! @name HCCPARAMS - Host Controller Capability Parameters */
/*! @{ */

#define USBHS_HCCPARAMS_ADC_MASK                 (0x1U)
#define USBHS_HCCPARAMS_ADC_SHIFT                (0U)
/*! ADC - 64-bit Addressing Capability */
#define USBHS_HCCPARAMS_ADC(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_HCCPARAMS_ADC_SHIFT)) & USBHS_HCCPARAMS_ADC_MASK)

#define USBHS_HCCPARAMS_PFL_MASK                 (0x2U)
#define USBHS_HCCPARAMS_PFL_SHIFT                (1U)
/*! PFL - Programmable Frame List Flag */
#define USBHS_HCCPARAMS_PFL(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_HCCPARAMS_PFL_SHIFT)) & USBHS_HCCPARAMS_PFL_MASK)

#define USBHS_HCCPARAMS_ASP_MASK                 (0x4U)
#define USBHS_HCCPARAMS_ASP_SHIFT                (2U)
/*! ASP - Asynchronous Schedule Park Capability */
#define USBHS_HCCPARAMS_ASP(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_HCCPARAMS_ASP_SHIFT)) & USBHS_HCCPARAMS_ASP_MASK)

#define USBHS_HCCPARAMS_IST_MASK                 (0xF0U)
#define USBHS_HCCPARAMS_IST_SHIFT                (4U)
/*! IST - Isochronous Scheduling Threshold */
#define USBHS_HCCPARAMS_IST(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_HCCPARAMS_IST_SHIFT)) & USBHS_HCCPARAMS_IST_MASK)

#define USBHS_HCCPARAMS_EECP_MASK                (0xFF00U)
#define USBHS_HCCPARAMS_EECP_SHIFT               (8U)
/*! EECP - EHCI Extended Capabilities Pointer */
#define USBHS_HCCPARAMS_EECP(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_HCCPARAMS_EECP_SHIFT)) & USBHS_HCCPARAMS_EECP_MASK)
/*! @} */

/*! @name DCIVERSION - Device Controller Interface Version */
/*! @{ */

#define USBHS_DCIVERSION_DCIVERSION_MASK         (0xFFFFU)
#define USBHS_DCIVERSION_DCIVERSION_SHIFT        (0U)
/*! DCIVERSION - Device Controller Interface Version Number */
#define USBHS_DCIVERSION_DCIVERSION(x)           (((uint16_t)(((uint16_t)(x)) << USBHS_DCIVERSION_DCIVERSION_SHIFT)) & USBHS_DCIVERSION_DCIVERSION_MASK)
/*! @} */

/*! @name DCCPARAMS - Device Controller Capability Parameters */
/*! @{ */

#define USBHS_DCCPARAMS_DEN_MASK                 (0x1FU)
#define USBHS_DCCPARAMS_DEN_SHIFT                (0U)
/*! DEN - Device Endpoint Number */
#define USBHS_DCCPARAMS_DEN(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_DCCPARAMS_DEN_SHIFT)) & USBHS_DCCPARAMS_DEN_MASK)

#define USBHS_DCCPARAMS_DC_MASK                  (0x80U)
#define USBHS_DCCPARAMS_DC_SHIFT                 (7U)
/*! DC - Device Capable */
#define USBHS_DCCPARAMS_DC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_DCCPARAMS_DC_SHIFT)) & USBHS_DCCPARAMS_DC_MASK)

#define USBHS_DCCPARAMS_HC_MASK                  (0x100U)
#define USBHS_DCCPARAMS_HC_SHIFT                 (8U)
/*! HC - Host Capable */
#define USBHS_DCCPARAMS_HC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_DCCPARAMS_HC_SHIFT)) & USBHS_DCCPARAMS_HC_MASK)
/*! @} */

/*! @name USBCMD - USB Command */
/*! @{ */

#define USBHS_USBCMD_RS_MASK                     (0x1U)
#define USBHS_USBCMD_RS_SHIFT                    (0U)
/*! RS - Run/Stop
 *  0b0..Stop
 *  0b1..Run
 */
#define USBHS_USBCMD_RS(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_RS_SHIFT)) & USBHS_USBCMD_RS_MASK)

#define USBHS_USBCMD_RST_MASK                    (0x2U)
#define USBHS_USBCMD_RST_SHIFT                   (1U)
/*! RST - Controller Reset */
#define USBHS_USBCMD_RST(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_RST_SHIFT)) & USBHS_USBCMD_RST_MASK)

#define USBHS_USBCMD_FS_1_MASK                   (0xCU)
#define USBHS_USBCMD_FS_1_SHIFT                  (2U)
/*! FS_1 - Frame List Size */
#define USBHS_USBCMD_FS_1(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_FS_1_SHIFT)) & USBHS_USBCMD_FS_1_MASK)

#define USBHS_USBCMD_PSE_MASK                    (0x10U)
#define USBHS_USBCMD_PSE_SHIFT                   (4U)
/*! PSE - Periodic Schedule Enable
 *  0b0..Do not process the Periodic Schedule
 *  0b1..Use the PERIODICLISTBASE register to access the Periodic Schedule
 */
#define USBHS_USBCMD_PSE(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_PSE_SHIFT)) & USBHS_USBCMD_PSE_MASK)

#define USBHS_USBCMD_ASE_MASK                    (0x20U)
#define USBHS_USBCMD_ASE_SHIFT                   (5U)
/*! ASE - Asynchronous Schedule Enable
 *  0b0..Do not process the Asynchronous Schedule
 *  0b1..Use the ASYNCLISTADDR register to access the Asynchronous Schedule
 */
#define USBHS_USBCMD_ASE(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_ASE_SHIFT)) & USBHS_USBCMD_ASE_MASK)

#define USBHS_USBCMD_IAA_MASK                    (0x40U)
#define USBHS_USBCMD_IAA_SHIFT                   (6U)
/*! IAA - Interrupt on Async Advance Doorbell */
#define USBHS_USBCMD_IAA(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_IAA_SHIFT)) & USBHS_USBCMD_IAA_MASK)

#define USBHS_USBCMD_ASP_MASK                    (0x300U)
#define USBHS_USBCMD_ASP_SHIFT                   (8U)
/*! ASP - Asynchronous Schedule Park Mode Count */
#define USBHS_USBCMD_ASP(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_ASP_SHIFT)) & USBHS_USBCMD_ASP_MASK)

#define USBHS_USBCMD_ASPE_MASK                   (0x800U)
#define USBHS_USBCMD_ASPE_SHIFT                  (11U)
/*! ASPE - Asynchronous Schedule Park Mode Enable */
#define USBHS_USBCMD_ASPE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_ASPE_SHIFT)) & USBHS_USBCMD_ASPE_MASK)

#define USBHS_USBCMD_SUTW_MASK                   (0x2000U)
#define USBHS_USBCMD_SUTW_SHIFT                  (13U)
/*! SUTW - Setup TripWire [device mode only] */
#define USBHS_USBCMD_SUTW(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_SUTW_SHIFT)) & USBHS_USBCMD_SUTW_MASK)

#define USBHS_USBCMD_ATDTW_MASK                  (0x4000U)
#define USBHS_USBCMD_ATDTW_SHIFT                 (14U)
/*! ATDTW - Add dTD TripWire[device mode only] */
#define USBHS_USBCMD_ATDTW(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_ATDTW_SHIFT)) & USBHS_USBCMD_ATDTW_MASK)

#define USBHS_USBCMD_FS_2_MASK                   (0x8000U)
#define USBHS_USBCMD_FS_2_SHIFT                  (15U)
/*! FS_2 - Frame List Size [host mode only] */
#define USBHS_USBCMD_FS_2(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_FS_2_SHIFT)) & USBHS_USBCMD_FS_2_MASK)

#define USBHS_USBCMD_ITC_MASK                    (0xFF0000U)
#define USBHS_USBCMD_ITC_SHIFT                   (16U)
/*! ITC - Interrupt Threshold Control
 *  0b00000000..Immediate (no threshold)
 *  0b00000001..1 micro-frame
 *  0b00000010..2 micro-frames
 *  0b00000100..4 micro-frames
 *  0b00001000..8 micro-frames
 *  0b00010000..16 micro-frames
 *  0b00100000..32 micro-frames
 *  0b01000000..64 micro-frames
 */
#define USBHS_USBCMD_ITC(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBCMD_ITC_SHIFT)) & USBHS_USBCMD_ITC_MASK)
/*! @} */

/*! @name USBSTS - USB Status */
/*! @{ */

#define USBHS_USBSTS_UI_MASK                     (0x1U)
#define USBHS_USBSTS_UI_SHIFT                    (0U)
/*! UI - USB Interrupt (USBINT) */
#define USBHS_USBSTS_UI(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_UI_SHIFT)) & USBHS_USBSTS_UI_MASK)

#define USBHS_USBSTS_UEI_MASK                    (0x2U)
#define USBHS_USBSTS_UEI_SHIFT                   (1U)
/*! UEI - USB Error Interrupt (USBERRINT) */
#define USBHS_USBSTS_UEI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_UEI_SHIFT)) & USBHS_USBSTS_UEI_MASK)

#define USBHS_USBSTS_PCI_MASK                    (0x4U)
#define USBHS_USBSTS_PCI_SHIFT                   (2U)
/*! PCI - Port Change Detect */
#define USBHS_USBSTS_PCI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_PCI_SHIFT)) & USBHS_USBSTS_PCI_MASK)

#define USBHS_USBSTS_FRI_MASK                    (0x8U)
#define USBHS_USBSTS_FRI_SHIFT                   (3U)
/*! FRI - Frame List Rollover */
#define USBHS_USBSTS_FRI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_FRI_SHIFT)) & USBHS_USBSTS_FRI_MASK)

#define USBHS_USBSTS_SEI_MASK                    (0x10U)
#define USBHS_USBSTS_SEI_SHIFT                   (4U)
/*! SEI - System Error */
#define USBHS_USBSTS_SEI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_SEI_SHIFT)) & USBHS_USBSTS_SEI_MASK)

#define USBHS_USBSTS_AAI_MASK                    (0x20U)
#define USBHS_USBSTS_AAI_SHIFT                   (5U)
/*! AAI - Interrupt on Async Advance */
#define USBHS_USBSTS_AAI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_AAI_SHIFT)) & USBHS_USBSTS_AAI_MASK)

#define USBHS_USBSTS_URI_MASK                    (0x40U)
#define USBHS_USBSTS_URI_SHIFT                   (6U)
/*! URI - USB Reset Received */
#define USBHS_USBSTS_URI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_URI_SHIFT)) & USBHS_USBSTS_URI_MASK)

#define USBHS_USBSTS_SRI_MASK                    (0x80U)
#define USBHS_USBSTS_SRI_SHIFT                   (7U)
/*! SRI - SOF Received */
#define USBHS_USBSTS_SRI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_SRI_SHIFT)) & USBHS_USBSTS_SRI_MASK)

#define USBHS_USBSTS_SLI_MASK                    (0x100U)
#define USBHS_USBSTS_SLI_SHIFT                   (8U)
/*! SLI - DCSuspend */
#define USBHS_USBSTS_SLI(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_SLI_SHIFT)) & USBHS_USBSTS_SLI_MASK)

#define USBHS_USBSTS_ULPII_MASK                  (0x400U)
#define USBHS_USBSTS_ULPII_SHIFT                 (10U)
/*! ULPII - ULPI Interrupt */
#define USBHS_USBSTS_ULPII(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_ULPII_SHIFT)) & USBHS_USBSTS_ULPII_MASK)

#define USBHS_USBSTS_HCH_MASK                    (0x1000U)
#define USBHS_USBSTS_HCH_SHIFT                   (12U)
/*! HCH - HCHaIted */
#define USBHS_USBSTS_HCH(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_HCH_SHIFT)) & USBHS_USBSTS_HCH_MASK)

#define USBHS_USBSTS_RCL_MASK                    (0x2000U)
#define USBHS_USBSTS_RCL_SHIFT                   (13U)
/*! RCL - Reclamation */
#define USBHS_USBSTS_RCL(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_RCL_SHIFT)) & USBHS_USBSTS_RCL_MASK)

#define USBHS_USBSTS_PS_MASK                     (0x4000U)
#define USBHS_USBSTS_PS_SHIFT                    (14U)
/*! PS - Periodic Schedule Status */
#define USBHS_USBSTS_PS(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_PS_SHIFT)) & USBHS_USBSTS_PS_MASK)

#define USBHS_USBSTS_AS_MASK                     (0x8000U)
#define USBHS_USBSTS_AS_SHIFT                    (15U)
/*! AS - Asynchronous Schedule Status */
#define USBHS_USBSTS_AS(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_AS_SHIFT)) & USBHS_USBSTS_AS_MASK)

#define USBHS_USBSTS_NAKI_MASK                   (0x10000U)
#define USBHS_USBSTS_NAKI_SHIFT                  (16U)
/*! NAKI - NAK Interrupt Bit */
#define USBHS_USBSTS_NAKI(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_NAKI_SHIFT)) & USBHS_USBSTS_NAKI_MASK)

#define USBHS_USBSTS_TI0_MASK                    (0x1000000U)
#define USBHS_USBSTS_TI0_SHIFT                   (24U)
/*! TI0 - General Purpose Timer Interrupt 0 (GPTINT0) */
#define USBHS_USBSTS_TI0(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_TI0_SHIFT)) & USBHS_USBSTS_TI0_MASK)

#define USBHS_USBSTS_TI1_MASK                    (0x2000000U)
#define USBHS_USBSTS_TI1_SHIFT                   (25U)
/*! TI1 - General Purpose Timer Interrupt 1 (GPTINT1) */
#define USBHS_USBSTS_TI1(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBSTS_TI1_SHIFT)) & USBHS_USBSTS_TI1_MASK)
/*! @} */

/*! @name USBINTR - Interrupt Enable */
/*! @{ */

#define USBHS_USBINTR_UE_MASK                    (0x1U)
#define USBHS_USBINTR_UE_SHIFT                   (0U)
/*! UE - USB Interrupt Enable */
#define USBHS_USBINTR_UE(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_UE_SHIFT)) & USBHS_USBINTR_UE_MASK)

#define USBHS_USBINTR_UEE_MASK                   (0x2U)
#define USBHS_USBINTR_UEE_SHIFT                  (1U)
/*! UEE - USB Error Interrupt Enable */
#define USBHS_USBINTR_UEE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_UEE_SHIFT)) & USBHS_USBINTR_UEE_MASK)

#define USBHS_USBINTR_PCE_MASK                   (0x4U)
#define USBHS_USBINTR_PCE_SHIFT                  (2U)
/*! PCE - Port Change Detect Interrupt Enable */
#define USBHS_USBINTR_PCE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_PCE_SHIFT)) & USBHS_USBINTR_PCE_MASK)

#define USBHS_USBINTR_FRE_MASK                   (0x8U)
#define USBHS_USBINTR_FRE_SHIFT                  (3U)
/*! FRE - Frame List Rollover Interrupt Enable */
#define USBHS_USBINTR_FRE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_FRE_SHIFT)) & USBHS_USBINTR_FRE_MASK)

#define USBHS_USBINTR_SEE_MASK                   (0x10U)
#define USBHS_USBINTR_SEE_SHIFT                  (4U)
/*! SEE - System Error Interrupt Enable */
#define USBHS_USBINTR_SEE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_SEE_SHIFT)) & USBHS_USBINTR_SEE_MASK)

#define USBHS_USBINTR_AAE_MASK                   (0x20U)
#define USBHS_USBINTR_AAE_SHIFT                  (5U)
/*! AAE - Async Advance Interrupt Enable */
#define USBHS_USBINTR_AAE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_AAE_SHIFT)) & USBHS_USBINTR_AAE_MASK)

#define USBHS_USBINTR_URE_MASK                   (0x40U)
#define USBHS_USBINTR_URE_SHIFT                  (6U)
/*! URE - USB Reset Interrupt Enable */
#define USBHS_USBINTR_URE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_URE_SHIFT)) & USBHS_USBINTR_URE_MASK)

#define USBHS_USBINTR_SRE_MASK                   (0x80U)
#define USBHS_USBINTR_SRE_SHIFT                  (7U)
/*! SRE - SOF Received Interrupt Enable */
#define USBHS_USBINTR_SRE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_SRE_SHIFT)) & USBHS_USBINTR_SRE_MASK)

#define USBHS_USBINTR_SLE_MASK                   (0x100U)
#define USBHS_USBINTR_SLE_SHIFT                  (8U)
/*! SLE - Sleep Interrupt Enable */
#define USBHS_USBINTR_SLE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_SLE_SHIFT)) & USBHS_USBINTR_SLE_MASK)

#define USBHS_USBINTR_NAKE_MASK                  (0x10000U)
#define USBHS_USBINTR_NAKE_SHIFT                 (16U)
/*! NAKE - NAK Interrupt Enable */
#define USBHS_USBINTR_NAKE(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_NAKE_SHIFT)) & USBHS_USBINTR_NAKE_MASK)

#define USBHS_USBINTR_UAIE_MASK                  (0x40000U)
#define USBHS_USBINTR_UAIE_SHIFT                 (18U)
/*! UAIE - USB Host Asynchronous Interrupt Enable */
#define USBHS_USBINTR_UAIE(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_UAIE_SHIFT)) & USBHS_USBINTR_UAIE_MASK)

#define USBHS_USBINTR_UPIE_MASK                  (0x80000U)
#define USBHS_USBINTR_UPIE_SHIFT                 (19U)
/*! UPIE - USB Host Periodic Interrupt Enable */
#define USBHS_USBINTR_UPIE(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_UPIE_SHIFT)) & USBHS_USBINTR_UPIE_MASK)

#define USBHS_USBINTR_TIE0_MASK                  (0x1000000U)
#define USBHS_USBINTR_TIE0_SHIFT                 (24U)
/*! TIE0 - General Purpose Timer #0 Interrupt Enable */
#define USBHS_USBINTR_TIE0(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_TIE0_SHIFT)) & USBHS_USBINTR_TIE0_MASK)

#define USBHS_USBINTR_TIE1_MASK                  (0x2000000U)
#define USBHS_USBINTR_TIE1_SHIFT                 (25U)
/*! TIE1 - General Purpose Timer #1 Interrupt Enable */
#define USBHS_USBINTR_TIE1(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBINTR_TIE1_SHIFT)) & USBHS_USBINTR_TIE1_MASK)
/*! @} */

/*! @name FRINDEX - USB Frame Index */
/*! @{ */

#define USBHS_FRINDEX_FRINDEX_MASK               (0x3FFFU)
#define USBHS_FRINDEX_FRINDEX_SHIFT              (0U)
/*! FRINDEX - Frame Index
 *  0b00000000000000..(1024) 12
 *  0b00000000000001..(512) 11
 *  0b00000000000010..(256) 10
 *  0b00000000000011..(128) 9
 *  0b00000000000100..(64) 8
 *  0b00000000000101..(32) 7
 *  0b00000000000110..(16) 6
 *  0b00000000000111..(8) 5
 */
#define USBHS_FRINDEX_FRINDEX(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_FRINDEX_FRINDEX_SHIFT)) & USBHS_FRINDEX_FRINDEX_MASK)
/*! @} */

/*! @name DEVICEADDR - Device Address */
/*! @{ */

#define USBHS_DEVICEADDR_USBADRA_MASK            (0x1000000U)
#define USBHS_DEVICEADDR_USBADRA_SHIFT           (24U)
/*! USBADRA - Device Address Advance */
#define USBHS_DEVICEADDR_USBADRA(x)              (((uint32_t)(((uint32_t)(x)) << USBHS_DEVICEADDR_USBADRA_SHIFT)) & USBHS_DEVICEADDR_USBADRA_MASK)

#define USBHS_DEVICEADDR_USBADR_MASK             (0xFE000000U)
#define USBHS_DEVICEADDR_USBADR_SHIFT            (25U)
/*! USBADR - Device Address */
#define USBHS_DEVICEADDR_USBADR(x)               (((uint32_t)(((uint32_t)(x)) << USBHS_DEVICEADDR_USBADR_SHIFT)) & USBHS_DEVICEADDR_USBADR_MASK)
/*! @} */

/*! @name PERIODICLISTBASE - Frame List Base Address */
/*! @{ */

#define USBHS_PERIODICLISTBASE_BASEADR_MASK      (0xFFFFF000U)
#define USBHS_PERIODICLISTBASE_BASEADR_SHIFT     (12U)
/*! BASEADR - Base Address (Low) */
#define USBHS_PERIODICLISTBASE_BASEADR(x)        (((uint32_t)(((uint32_t)(x)) << USBHS_PERIODICLISTBASE_BASEADR_SHIFT)) & USBHS_PERIODICLISTBASE_BASEADR_MASK)
/*! @} */

/*! @name ASYNCLISTADDR - Next Asynch. Address */
/*! @{ */

#define USBHS_ASYNCLISTADDR_ASYBASE_MASK         (0xFFFFFFE0U)
#define USBHS_ASYNCLISTADDR_ASYBASE_SHIFT        (5U)
/*! ASYBASE - Link Pointer Low (LPL) */
#define USBHS_ASYNCLISTADDR_ASYBASE(x)           (((uint32_t)(((uint32_t)(x)) << USBHS_ASYNCLISTADDR_ASYBASE_SHIFT)) & USBHS_ASYNCLISTADDR_ASYBASE_MASK)
/*! @} */

/*! @name ENDPTLISTADDR - Endpoint List Address */
/*! @{ */

#define USBHS_ENDPTLISTADDR_EPBASE_MASK          (0xFFFFF800U)
#define USBHS_ENDPTLISTADDR_EPBASE_SHIFT         (11U)
/*! EPBASE - Endpoint List Pointer (Low) */
#define USBHS_ENDPTLISTADDR_EPBASE(x)            (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTLISTADDR_EPBASE_SHIFT)) & USBHS_ENDPTLISTADDR_EPBASE_MASK)
/*! @} */

/*! @name BURSTSIZE - Programmable Burst Size */
/*! @{ */

#define USBHS_BURSTSIZE_RXPBURST_MASK            (0xFFU)
#define USBHS_BURSTSIZE_RXPBURST_SHIFT           (0U)
/*! RXPBURST - Programmable RX Burst Size */
#define USBHS_BURSTSIZE_RXPBURST(x)              (((uint32_t)(((uint32_t)(x)) << USBHS_BURSTSIZE_RXPBURST_SHIFT)) & USBHS_BURSTSIZE_RXPBURST_MASK)

#define USBHS_BURSTSIZE_TXPBURST_MASK            (0xFF00U)
#define USBHS_BURSTSIZE_TXPBURST_SHIFT           (8U)
/*! TXPBURST - Programmable TX Burst Size */
#define USBHS_BURSTSIZE_TXPBURST(x)              (((uint32_t)(((uint32_t)(x)) << USBHS_BURSTSIZE_TXPBURST_SHIFT)) & USBHS_BURSTSIZE_TXPBURST_MASK)
/*! @} */

/*! @name TXFILLTUNING - TX FIFO Fill Tuning */
/*! @{ */

#define USBHS_TXFILLTUNING_TXSCHOH_MASK          (0x7FU)
#define USBHS_TXFILLTUNING_TXSCHOH_SHIFT         (0U)
/*! TXSCHOH - Scheduler Overhead */
#define USBHS_TXFILLTUNING_TXSCHOH(x)            (((uint32_t)(((uint32_t)(x)) << USBHS_TXFILLTUNING_TXSCHOH_SHIFT)) & USBHS_TXFILLTUNING_TXSCHOH_MASK)

#define USBHS_TXFILLTUNING_TXSCHHEALTH_MASK      (0x1F00U)
#define USBHS_TXFILLTUNING_TXSCHHEALTH_SHIFT     (8U)
/*! TXSCHHEALTH - Scheduler Health Counter */
#define USBHS_TXFILLTUNING_TXSCHHEALTH(x)        (((uint32_t)(((uint32_t)(x)) << USBHS_TXFILLTUNING_TXSCHHEALTH_SHIFT)) & USBHS_TXFILLTUNING_TXSCHHEALTH_MASK)

#define USBHS_TXFILLTUNING_TXFIFOTHRES_MASK      (0x3F0000U)
#define USBHS_TXFILLTUNING_TXFIFOTHRES_SHIFT     (16U)
/*! TXFIFOTHRES - FIFO Burst Threshold */
#define USBHS_TXFILLTUNING_TXFIFOTHRES(x)        (((uint32_t)(((uint32_t)(x)) << USBHS_TXFILLTUNING_TXFIFOTHRES_SHIFT)) & USBHS_TXFILLTUNING_TXFIFOTHRES_MASK)
/*! @} */

/*! @name ENDPTNAK - Endpoint NAK */
/*! @{ */

#define USBHS_ENDPTNAK_EPRN_MASK                 (0xFFU)
#define USBHS_ENDPTNAK_EPRN_SHIFT                (0U)
/*! EPRN - RX Endpoint NAK */
#define USBHS_ENDPTNAK_EPRN(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTNAK_EPRN_SHIFT)) & USBHS_ENDPTNAK_EPRN_MASK)

#define USBHS_ENDPTNAK_EPTN_MASK                 (0xFF0000U)
#define USBHS_ENDPTNAK_EPTN_SHIFT                (16U)
/*! EPTN - TX Endpoint NAK */
#define USBHS_ENDPTNAK_EPTN(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTNAK_EPTN_SHIFT)) & USBHS_ENDPTNAK_EPTN_MASK)
/*! @} */

/*! @name ENDPTNAKEN - Endpoint NAK Enable */
/*! @{ */

#define USBHS_ENDPTNAKEN_EPRNE_MASK              (0xFFU)
#define USBHS_ENDPTNAKEN_EPRNE_SHIFT             (0U)
/*! EPRNE - RX Endpoint NAK Enable */
#define USBHS_ENDPTNAKEN_EPRNE(x)                (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTNAKEN_EPRNE_SHIFT)) & USBHS_ENDPTNAKEN_EPRNE_MASK)

#define USBHS_ENDPTNAKEN_EPTNE_MASK              (0xFF0000U)
#define USBHS_ENDPTNAKEN_EPTNE_SHIFT             (16U)
/*! EPTNE - TX Endpoint NAK Enable */
#define USBHS_ENDPTNAKEN_EPTNE(x)                (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTNAKEN_EPTNE_SHIFT)) & USBHS_ENDPTNAKEN_EPTNE_MASK)
/*! @} */

/*! @name CONFIGFLAG - Configure Flag */
/*! @{ */

#define USBHS_CONFIGFLAG_CF_MASK                 (0x1U)
#define USBHS_CONFIGFLAG_CF_SHIFT                (0U)
/*! CF - Configure Flag
 *  0b0..Port routing control logic default-routes each port to an implementation dependent classic host controller
 *  0b1..Port routing control logic default-routes all ports to this host controller
 */
#define USBHS_CONFIGFLAG_CF(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_CONFIGFLAG_CF_SHIFT)) & USBHS_CONFIGFLAG_CF_MASK)
/*! @} */

/*! @name PORTSC1 - Port Status & Control */
/*! @{ */

#define USBHS_PORTSC1_CCS_MASK                   (0x1U)
#define USBHS_PORTSC1_CCS_SHIFT                  (0U)
/*! CCS - Current Connect Status
 *  0b0..In Host mode: No device is present. In Device mode: Not attached
 *  0b1..In Host mode: Device is present on port. In Device mode: Attached
 */
#define USBHS_PORTSC1_CCS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_CCS_SHIFT)) & USBHS_PORTSC1_CCS_MASK)

#define USBHS_PORTSC1_CSC_MASK                   (0x2U)
#define USBHS_PORTSC1_CSC_SHIFT                  (1U)
/*! CSC - Connect Status Change
 *  0b0..No change
 *  0b1..Change in current connect status
 */
#define USBHS_PORTSC1_CSC(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_CSC_SHIFT)) & USBHS_PORTSC1_CSC_MASK)

#define USBHS_PORTSC1_PE_MASK                    (0x4U)
#define USBHS_PORTSC1_PE_SHIFT                   (2U)
/*! PE - Port Enabled/Disabled
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBHS_PORTSC1_PE(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PE_SHIFT)) & USBHS_PORTSC1_PE_MASK)

#define USBHS_PORTSC1_PEC_MASK                   (0x8U)
#define USBHS_PORTSC1_PEC_SHIFT                  (3U)
/*! PEC - Port Enable/Disable Change
 *  0b0..No change
 *  0b1..Port enabled/disabled status has changed
 */
#define USBHS_PORTSC1_PEC(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PEC_SHIFT)) & USBHS_PORTSC1_PEC_MASK)

#define USBHS_PORTSC1_OCA_MASK                   (0x10U)
#define USBHS_PORTSC1_OCA_SHIFT                  (4U)
/*! OCA - Over-Current Active
 *  0b0..This port does not have an over-current condition
 *  0b1..This port currently has an over-current condition
 */
#define USBHS_PORTSC1_OCA(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_OCA_SHIFT)) & USBHS_PORTSC1_OCA_MASK)

#define USBHS_PORTSC1_OCC_MASK                   (0x20U)
#define USBHS_PORTSC1_OCC_SHIFT                  (5U)
/*! OCC - Over-current Change */
#define USBHS_PORTSC1_OCC(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_OCC_SHIFT)) & USBHS_PORTSC1_OCC_MASK)

#define USBHS_PORTSC1_FPR_MASK                   (0x40U)
#define USBHS_PORTSC1_FPR_SHIFT                  (6U)
/*! FPR - Force Port Resume
 *  0b0..No resume (K-state) detected/driven on port
 *  0b1..Resume detected/driven on port
 */
#define USBHS_PORTSC1_FPR(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_FPR_SHIFT)) & USBHS_PORTSC1_FPR_MASK)

#define USBHS_PORTSC1_SUSP_MASK                  (0x80U)
#define USBHS_PORTSC1_SUSP_SHIFT                 (7U)
/*! SUSP - Suspend
 *  0b0..Port not in suspend state
 *  0b1..Port in suspend state
 */
#define USBHS_PORTSC1_SUSP(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_SUSP_SHIFT)) & USBHS_PORTSC1_SUSP_MASK)

#define USBHS_PORTSC1_PR_MASK                    (0x100U)
#define USBHS_PORTSC1_PR_SHIFT                   (8U)
/*! PR - Port Reset
 *  0b0..Port is not in reset
 *  0b1..Port is in reset
 */
#define USBHS_PORTSC1_PR(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PR_SHIFT)) & USBHS_PORTSC1_PR_MASK)

#define USBHS_PORTSC1_HSP_MASK                   (0x200U)
#define USBHS_PORTSC1_HSP_SHIFT                  (9U)
/*! HSP - High-Speed Port */
#define USBHS_PORTSC1_HSP(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_HSP_SHIFT)) & USBHS_PORTSC1_HSP_MASK)

#define USBHS_PORTSC1_LS_MASK                    (0xC00U)
#define USBHS_PORTSC1_LS_SHIFT                   (10U)
/*! LS - Line Status
 *  0b00..SE0
 *  0b01..K-state
 *  0b10..J-state
 *  0b11..Undefined
 */
#define USBHS_PORTSC1_LS(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_LS_SHIFT)) & USBHS_PORTSC1_LS_MASK)

#define USBHS_PORTSC1_PP_MASK                    (0x1000U)
#define USBHS_PORTSC1_PP_SHIFT                   (12U)
/*! PP - Port Power */
#define USBHS_PORTSC1_PP(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PP_SHIFT)) & USBHS_PORTSC1_PP_MASK)

#define USBHS_PORTSC1_PO_MASK                    (0x2000U)
#define USBHS_PORTSC1_PO_SHIFT                   (13U)
/*! PO - Port Owner */
#define USBHS_PORTSC1_PO(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PO_SHIFT)) & USBHS_PORTSC1_PO_MASK)

#define USBHS_PORTSC1_PIC_MASK                   (0xC000U)
#define USBHS_PORTSC1_PIC_SHIFT                  (14U)
/*! PIC - Port Indicator Control
 *  0b00..Port indicators are off
 *  0b01..Amber
 *  0b10..Green
 *  0b11..Undefined
 */
#define USBHS_PORTSC1_PIC(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PIC_SHIFT)) & USBHS_PORTSC1_PIC_MASK)

#define USBHS_PORTSC1_PTC_MASK                   (0xF0000U)
#define USBHS_PORTSC1_PTC_SHIFT                  (16U)
/*! PTC - Port Test Control
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
#define USBHS_PORTSC1_PTC(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PTC_SHIFT)) & USBHS_PORTSC1_PTC_MASK)

#define USBHS_PORTSC1_WKCN_MASK                  (0x100000U)
#define USBHS_PORTSC1_WKCN_SHIFT                 (20U)
/*! WKCN - Wake on Connect Enable (WKCNNT_E) */
#define USBHS_PORTSC1_WKCN(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_WKCN_SHIFT)) & USBHS_PORTSC1_WKCN_MASK)

#define USBHS_PORTSC1_WKDC_MASK                  (0x200000U)
#define USBHS_PORTSC1_WKDC_SHIFT                 (21U)
/*! WKDC - Wake on Disconnect Enable (WKDSCNNT_E) */
#define USBHS_PORTSC1_WKDC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_WKDC_SHIFT)) & USBHS_PORTSC1_WKDC_MASK)

#define USBHS_PORTSC1_WKOC_MASK                  (0x400000U)
#define USBHS_PORTSC1_WKOC_SHIFT                 (22U)
/*! WKOC - Wake on Over-current Enable (WKOC_E) */
#define USBHS_PORTSC1_WKOC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_WKOC_SHIFT)) & USBHS_PORTSC1_WKOC_MASK)

#define USBHS_PORTSC1_PHCD_MASK                  (0x800000U)
#define USBHS_PORTSC1_PHCD_SHIFT                 (23U)
/*! PHCD - PHY Low Power Suspend - Clock Disable (PLPSCD)
 *  0b0..Enable PHY clock
 *  0b1..Disable PHY clock
 */
#define USBHS_PORTSC1_PHCD(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PHCD_SHIFT)) & USBHS_PORTSC1_PHCD_MASK)

#define USBHS_PORTSC1_PFSC_MASK                  (0x1000000U)
#define USBHS_PORTSC1_PFSC_SHIFT                 (24U)
/*! PFSC - Port Force Full Speed Connect
 *  0b0..Normal operation
 *  0b1..Forced to full speed
 */
#define USBHS_PORTSC1_PFSC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PFSC_SHIFT)) & USBHS_PORTSC1_PFSC_MASK)

#define USBHS_PORTSC1_PTS_2_MASK                 (0x2000000U)
#define USBHS_PORTSC1_PTS_2_SHIFT                (25U)
/*! PTS_2 - Parallel Transceiver Select */
#define USBHS_PORTSC1_PTS_2(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PTS_2_SHIFT)) & USBHS_PORTSC1_PTS_2_MASK)

#define USBHS_PORTSC1_PSPD_MASK                  (0xC000000U)
#define USBHS_PORTSC1_PSPD_SHIFT                 (26U)
/*! PSPD - Port Speed
 *  0b00..Full Speed
 *  0b01..Low Speed
 *  0b10..High Speed
 *  0b11..Undefined
 */
#define USBHS_PORTSC1_PSPD(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PSPD_SHIFT)) & USBHS_PORTSC1_PSPD_MASK)

#define USBHS_PORTSC1_PTW_MASK                   (0x10000000U)
#define USBHS_PORTSC1_PTW_SHIFT                  (28U)
/*! PTW - Parallel Transceiver Width - Read/Write
 *  0b0..Select the 8-bit UTMI interface [60 MHz]
 *  0b1..Select the 16-bit UTMI interface [30 MHz]
 */
#define USBHS_PORTSC1_PTW(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PTW_SHIFT)) & USBHS_PORTSC1_PTW_MASK)

#define USBHS_PORTSC1_STS_MASK                   (0x20000000U)
#define USBHS_PORTSC1_STS_SHIFT                  (29U)
/*! STS - Serial Transceiver Select
 *  0b0..Parallel Interface signals is selected
 *  0b1..Serial Interface Engine is selected
 */
#define USBHS_PORTSC1_STS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_STS_SHIFT)) & USBHS_PORTSC1_STS_MASK)

#define USBHS_PORTSC1_PTS_1_MASK                 (0xC0000000U)
#define USBHS_PORTSC1_PTS_1_SHIFT                (30U)
/*! PTS_1 - Parallel Transceiver Select */
#define USBHS_PORTSC1_PTS_1(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_PORTSC1_PTS_1_SHIFT)) & USBHS_PORTSC1_PTS_1_MASK)
/*! @} */

/*! @name OTGSC - On-The-Go Status & Control */
/*! @{ */

#define USBHS_OTGSC_VD_MASK                      (0x1U)
#define USBHS_OTGSC_VD_SHIFT                     (0U)
/*! VD - VBUS Discharge */
#define USBHS_OTGSC_VD(x)                        (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_VD_SHIFT)) & USBHS_OTGSC_VD_MASK)

#define USBHS_OTGSC_VC_MASK                      (0x2U)
#define USBHS_OTGSC_VC_SHIFT                     (1U)
/*! VC - VBUS Charge */
#define USBHS_OTGSC_VC(x)                        (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_VC_SHIFT)) & USBHS_OTGSC_VC_MASK)

#define USBHS_OTGSC_OT_MASK                      (0x8U)
#define USBHS_OTGSC_OT_SHIFT                     (3U)
/*! OT - OTG Termination */
#define USBHS_OTGSC_OT(x)                        (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_OT_SHIFT)) & USBHS_OTGSC_OT_MASK)

#define USBHS_OTGSC_DP_MASK                      (0x10U)
#define USBHS_OTGSC_DP_SHIFT                     (4U)
/*! DP - Data Pulsing */
#define USBHS_OTGSC_DP(x)                        (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_DP_SHIFT)) & USBHS_OTGSC_DP_MASK)

#define USBHS_OTGSC_IDPU_MASK                    (0x20U)
#define USBHS_OTGSC_IDPU_SHIFT                   (5U)
/*! IDPU - ID Pullup
 *  0b0..Off
 *  0b1..On
 */
#define USBHS_OTGSC_IDPU(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_IDPU_SHIFT)) & USBHS_OTGSC_IDPU_MASK)

#define USBHS_OTGSC_ID_MASK                      (0x100U)
#define USBHS_OTGSC_ID_SHIFT                     (8U)
/*! ID - USB ID
 *  0b0..A device
 *  0b1..B device
 */
#define USBHS_OTGSC_ID(x)                        (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_ID_SHIFT)) & USBHS_OTGSC_ID_MASK)

#define USBHS_OTGSC_AVV_MASK                     (0x200U)
#define USBHS_OTGSC_AVV_SHIFT                    (9U)
/*! AVV - A VBus Valid */
#define USBHS_OTGSC_AVV(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_AVV_SHIFT)) & USBHS_OTGSC_AVV_MASK)

#define USBHS_OTGSC_ASV_MASK                     (0x400U)
#define USBHS_OTGSC_ASV_SHIFT                    (10U)
/*! ASV - A Session Valid */
#define USBHS_OTGSC_ASV(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_ASV_SHIFT)) & USBHS_OTGSC_ASV_MASK)

#define USBHS_OTGSC_BSV_MASK                     (0x800U)
#define USBHS_OTGSC_BSV_SHIFT                    (11U)
/*! BSV - B Session Valid */
#define USBHS_OTGSC_BSV(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_BSV_SHIFT)) & USBHS_OTGSC_BSV_MASK)

#define USBHS_OTGSC_BSE_MASK                     (0x1000U)
#define USBHS_OTGSC_BSE_SHIFT                    (12U)
/*! BSE - B Session End */
#define USBHS_OTGSC_BSE(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_BSE_SHIFT)) & USBHS_OTGSC_BSE_MASK)

#define USBHS_OTGSC_TOG_1MS_MASK                 (0x2000U)
#define USBHS_OTGSC_TOG_1MS_SHIFT                (13U)
/*! TOG_1MS - 1 Millisecond Timer Toggle */
#define USBHS_OTGSC_TOG_1MS(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_TOG_1MS_SHIFT)) & USBHS_OTGSC_TOG_1MS_MASK)

#define USBHS_OTGSC_DPS_MASK                     (0x4000U)
#define USBHS_OTGSC_DPS_SHIFT                    (14U)
/*! DPS - Data Bus Pulsing Status */
#define USBHS_OTGSC_DPS(x)                       (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_DPS_SHIFT)) & USBHS_OTGSC_DPS_MASK)

#define USBHS_OTGSC_IDIS_MASK                    (0x10000U)
#define USBHS_OTGSC_IDIS_SHIFT                   (16U)
/*! IDIS - USB ID Interrupt Status */
#define USBHS_OTGSC_IDIS(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_IDIS_SHIFT)) & USBHS_OTGSC_IDIS_MASK)

#define USBHS_OTGSC_AVVIS_MASK                   (0x20000U)
#define USBHS_OTGSC_AVVIS_SHIFT                  (17U)
/*! AVVIS - A VBus Valid Interrupt Status */
#define USBHS_OTGSC_AVVIS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_AVVIS_SHIFT)) & USBHS_OTGSC_AVVIS_MASK)

#define USBHS_OTGSC_ASVIS_MASK                   (0x40000U)
#define USBHS_OTGSC_ASVIS_SHIFT                  (18U)
/*! ASVIS - A Session Valid Interrupt Status */
#define USBHS_OTGSC_ASVIS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_ASVIS_SHIFT)) & USBHS_OTGSC_ASVIS_MASK)

#define USBHS_OTGSC_BSVIS_MASK                   (0x80000U)
#define USBHS_OTGSC_BSVIS_SHIFT                  (19U)
/*! BSVIS - B Session Valid Interrupt Status */
#define USBHS_OTGSC_BSVIS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_BSVIS_SHIFT)) & USBHS_OTGSC_BSVIS_MASK)

#define USBHS_OTGSC_BSEIS_MASK                   (0x100000U)
#define USBHS_OTGSC_BSEIS_SHIFT                  (20U)
/*! BSEIS - B Session End Interrupt Status */
#define USBHS_OTGSC_BSEIS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_BSEIS_SHIFT)) & USBHS_OTGSC_BSEIS_MASK)

#define USBHS_OTGSC_STATUS_1MS_MASK              (0x200000U)
#define USBHS_OTGSC_STATUS_1MS_SHIFT             (21U)
/*! STATUS_1MS - 1 Millisecond Timer Interrupt Status */
#define USBHS_OTGSC_STATUS_1MS(x)                (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_STATUS_1MS_SHIFT)) & USBHS_OTGSC_STATUS_1MS_MASK)

#define USBHS_OTGSC_DPIS_MASK                    (0x400000U)
#define USBHS_OTGSC_DPIS_SHIFT                   (22U)
/*! DPIS - Data Pulse Interrupt Status */
#define USBHS_OTGSC_DPIS(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_DPIS_SHIFT)) & USBHS_OTGSC_DPIS_MASK)

#define USBHS_OTGSC_IDIE_MASK                    (0x1000000U)
#define USBHS_OTGSC_IDIE_SHIFT                   (24U)
/*! IDIE - USB ID Interrupt Enable */
#define USBHS_OTGSC_IDIE(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_IDIE_SHIFT)) & USBHS_OTGSC_IDIE_MASK)

#define USBHS_OTGSC_AVVIE_MASK                   (0x2000000U)
#define USBHS_OTGSC_AVVIE_SHIFT                  (25U)
/*! AVVIE - A VBus Valid Interrupt Enable */
#define USBHS_OTGSC_AVVIE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_AVVIE_SHIFT)) & USBHS_OTGSC_AVVIE_MASK)

#define USBHS_OTGSC_ASVIE_MASK                   (0x4000000U)
#define USBHS_OTGSC_ASVIE_SHIFT                  (26U)
/*! ASVIE - A Session Valid Interrupt Enable */
#define USBHS_OTGSC_ASVIE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_ASVIE_SHIFT)) & USBHS_OTGSC_ASVIE_MASK)

#define USBHS_OTGSC_BSVIE_MASK                   (0x8000000U)
#define USBHS_OTGSC_BSVIE_SHIFT                  (27U)
/*! BSVIE - B Session Valid Interrupt Enable */
#define USBHS_OTGSC_BSVIE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_BSVIE_SHIFT)) & USBHS_OTGSC_BSVIE_MASK)

#define USBHS_OTGSC_BSEIE_MASK                   (0x10000000U)
#define USBHS_OTGSC_BSEIE_SHIFT                  (28U)
/*! BSEIE - B Session End Interrupt Enable */
#define USBHS_OTGSC_BSEIE(x)                     (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_BSEIE_SHIFT)) & USBHS_OTGSC_BSEIE_MASK)

#define USBHS_OTGSC_EN_1MS_MASK                  (0x20000000U)
#define USBHS_OTGSC_EN_1MS_SHIFT                 (29U)
/*! EN_1MS - 1 Millisecond Timer Interrupt Enable */
#define USBHS_OTGSC_EN_1MS(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_EN_1MS_SHIFT)) & USBHS_OTGSC_EN_1MS_MASK)

#define USBHS_OTGSC_DPIE_MASK                    (0x40000000U)
#define USBHS_OTGSC_DPIE_SHIFT                   (30U)
/*! DPIE - Data Pulse Interrupt Enable */
#define USBHS_OTGSC_DPIE(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_OTGSC_DPIE_SHIFT)) & USBHS_OTGSC_DPIE_MASK)
/*! @} */

/*! @name USBMODE - USB Device Mode */
/*! @{ */

#define USBHS_USBMODE_CM_MASK                    (0x3U)
#define USBHS_USBMODE_CM_SHIFT                   (0U)
/*! CM - Controller Mode
 *  0b00..Idle [Default for combination host/device]
 *  0b01..Reserved
 *  0b10..Device Controller [Default for device only controller]
 *  0b11..Host Controller [Default for host only controller]
 */
#define USBHS_USBMODE_CM(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBMODE_CM_SHIFT)) & USBHS_USBMODE_CM_MASK)

#define USBHS_USBMODE_ES_MASK                    (0x4U)
#define USBHS_USBMODE_ES_SHIFT                   (2U)
/*! ES - Endian Select
 *  0b0..Little Endian
 *  0b1..Big Endian
 */
#define USBHS_USBMODE_ES(x)                      (((uint32_t)(((uint32_t)(x)) << USBHS_USBMODE_ES_SHIFT)) & USBHS_USBMODE_ES_MASK)

#define USBHS_USBMODE_SLOM_MASK                  (0x8U)
#define USBHS_USBMODE_SLOM_SHIFT                 (3U)
/*! SLOM - Setup Lockout Mode
 *  0b0..Setup Lockouts On (default);
 *  0b1..Setup Lockouts Off
 */
#define USBHS_USBMODE_SLOM(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBMODE_SLOM_SHIFT)) & USBHS_USBMODE_SLOM_MASK)

#define USBHS_USBMODE_SDIS_MASK                  (0x10U)
#define USBHS_USBMODE_SDIS_SHIFT                 (4U)
/*! SDIS - Stream Disable Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define USBHS_USBMODE_SDIS(x)                    (((uint32_t)(((uint32_t)(x)) << USBHS_USBMODE_SDIS_SHIFT)) & USBHS_USBMODE_SDIS_MASK)
/*! @} */

/*! @name ENDPTSETUPSTAT - Endpoint Setup Status */
/*! @{ */

#define USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK (0xFFFFU)
#define USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT (0U)
/*! ENDPTSETUPSTAT - Setup Endpoint Status */
#define USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT)) & USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK)
/*! @} */

/*! @name ENDPTPRIME - Endpoint Prime */
/*! @{ */

#define USBHS_ENDPTPRIME_PERB_MASK               (0xFFU)
#define USBHS_ENDPTPRIME_PERB_SHIFT              (0U)
/*! PERB - Prime Endpoint Receive Buffer */
#define USBHS_ENDPTPRIME_PERB(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTPRIME_PERB_SHIFT)) & USBHS_ENDPTPRIME_PERB_MASK)

#define USBHS_ENDPTPRIME_PETB_MASK               (0xFF0000U)
#define USBHS_ENDPTPRIME_PETB_SHIFT              (16U)
/*! PETB - Prime Endpoint Transmit Buffer */
#define USBHS_ENDPTPRIME_PETB(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTPRIME_PETB_SHIFT)) & USBHS_ENDPTPRIME_PETB_MASK)
/*! @} */

/*! @name ENDPTFLUSH - Endpoint Flush */
/*! @{ */

#define USBHS_ENDPTFLUSH_FERB_MASK               (0xFFU)
#define USBHS_ENDPTFLUSH_FERB_SHIFT              (0U)
/*! FERB - Flush Endpoint Receive Buffer */
#define USBHS_ENDPTFLUSH_FERB(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTFLUSH_FERB_SHIFT)) & USBHS_ENDPTFLUSH_FERB_MASK)

#define USBHS_ENDPTFLUSH_FETB_MASK               (0xFF0000U)
#define USBHS_ENDPTFLUSH_FETB_SHIFT              (16U)
/*! FETB - Flush Endpoint Transmit Buffer */
#define USBHS_ENDPTFLUSH_FETB(x)                 (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTFLUSH_FETB_SHIFT)) & USBHS_ENDPTFLUSH_FETB_MASK)
/*! @} */

/*! @name ENDPTSTAT - Endpoint Status */
/*! @{ */

#define USBHS_ENDPTSTAT_ERBR_MASK                (0xFFU)
#define USBHS_ENDPTSTAT_ERBR_SHIFT               (0U)
/*! ERBR - Endpoint Receive Buffer Ready */
#define USBHS_ENDPTSTAT_ERBR(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTSTAT_ERBR_SHIFT)) & USBHS_ENDPTSTAT_ERBR_MASK)

#define USBHS_ENDPTSTAT_ETBR_MASK                (0xFF0000U)
#define USBHS_ENDPTSTAT_ETBR_SHIFT               (16U)
/*! ETBR - Endpoint Transmit Buffer Ready */
#define USBHS_ENDPTSTAT_ETBR(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTSTAT_ETBR_SHIFT)) & USBHS_ENDPTSTAT_ETBR_MASK)
/*! @} */

/*! @name ENDPTCOMPLETE - Endpoint Complete */
/*! @{ */

#define USBHS_ENDPTCOMPLETE_ERCE_MASK            (0xFFU)
#define USBHS_ENDPTCOMPLETE_ERCE_SHIFT           (0U)
/*! ERCE - Endpoint Receive Complete Event */
#define USBHS_ENDPTCOMPLETE_ERCE(x)              (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCOMPLETE_ERCE_SHIFT)) & USBHS_ENDPTCOMPLETE_ERCE_MASK)

#define USBHS_ENDPTCOMPLETE_ETCE_MASK            (0xFF0000U)
#define USBHS_ENDPTCOMPLETE_ETCE_SHIFT           (16U)
/*! ETCE - Endpoint Transmit Complete Event */
#define USBHS_ENDPTCOMPLETE_ETCE(x)              (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCOMPLETE_ETCE_SHIFT)) & USBHS_ENDPTCOMPLETE_ETCE_MASK)
/*! @} */

/*! @name ENDPTCTRL0 - Endpoint Control 0 */
/*! @{ */

#define USBHS_ENDPTCTRL0_RXS_MASK                (0x1U)
#define USBHS_ENDPTCTRL0_RXS_SHIFT               (0U)
/*! RXS - RX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBHS_ENDPTCTRL0_RXS(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL0_RXS_SHIFT)) & USBHS_ENDPTCTRL0_RXS_MASK)

#define USBHS_ENDPTCTRL0_RXT_MASK                (0xCU)
#define USBHS_ENDPTCTRL0_RXT_SHIFT               (2U)
/*! RXT - RX Endpoint Type
 *  0b00..Control
 */
#define USBHS_ENDPTCTRL0_RXT(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL0_RXT_SHIFT)) & USBHS_ENDPTCTRL0_RXT_MASK)

#define USBHS_ENDPTCTRL0_RXE_MASK                (0x80U)
#define USBHS_ENDPTCTRL0_RXE_SHIFT               (7U)
/*! RXE - RX Endpoint Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBHS_ENDPTCTRL0_RXE(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL0_RXE_SHIFT)) & USBHS_ENDPTCTRL0_RXE_MASK)

#define USBHS_ENDPTCTRL0_TXS_MASK                (0x10000U)
#define USBHS_ENDPTCTRL0_TXS_SHIFT               (16U)
/*! TXS - TX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBHS_ENDPTCTRL0_TXS(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL0_TXS_SHIFT)) & USBHS_ENDPTCTRL0_TXS_MASK)

#define USBHS_ENDPTCTRL0_TXT_MASK                (0xC0000U)
#define USBHS_ENDPTCTRL0_TXT_SHIFT               (18U)
/*! TXT - TX Endpoint Type
 *  0b00..Control
 */
#define USBHS_ENDPTCTRL0_TXT(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL0_TXT_SHIFT)) & USBHS_ENDPTCTRL0_TXT_MASK)

#define USBHS_ENDPTCTRL0_TXE_MASK                (0x800000U)
#define USBHS_ENDPTCTRL0_TXE_SHIFT               (23U)
/*! TXE - TX Endpoint Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBHS_ENDPTCTRL0_TXE(x)                  (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL0_TXE_SHIFT)) & USBHS_ENDPTCTRL0_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL - Endpoint Control 1..Endpoint Control 7 */
/*! @{ */

#define USBHS_ENDPTCTRL_RXS_MASK                 (0x1U)
#define USBHS_ENDPTCTRL_RXS_SHIFT                (0U)
/*! RXS - RX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBHS_ENDPTCTRL_RXS(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_RXS_SHIFT)) & USBHS_ENDPTCTRL_RXS_MASK)

#define USBHS_ENDPTCTRL_RXD_MASK                 (0x2U)
#define USBHS_ENDPTCTRL_RXD_SHIFT                (1U)
/*! RXD - RX Endpoint Data Sink
 *  0b0..Dual Port Memory Buffer/DMA Engine
 */
#define USBHS_ENDPTCTRL_RXD(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_RXD_SHIFT)) & USBHS_ENDPTCTRL_RXD_MASK)

#define USBHS_ENDPTCTRL_RXT_MASK                 (0xCU)
#define USBHS_ENDPTCTRL_RXT_SHIFT                (2U)
/*! RXT - RX Endpoint Type
 *  0b00..Control
 *  0b01..Isochronous
 *  0b10..Bulk
 *  0b11..Interrupt
 */
#define USBHS_ENDPTCTRL_RXT(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_RXT_SHIFT)) & USBHS_ENDPTCTRL_RXT_MASK)

#define USBHS_ENDPTCTRL_RXI_MASK                 (0x20U)
#define USBHS_ENDPTCTRL_RXI_SHIFT                (5U)
/*! RXI - RX Data Toggle Inhibit
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBHS_ENDPTCTRL_RXI(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_RXI_SHIFT)) & USBHS_ENDPTCTRL_RXI_MASK)

#define USBHS_ENDPTCTRL_RXR_MASK                 (0x40U)
#define USBHS_ENDPTCTRL_RXR_SHIFT                (6U)
/*! RXR - RX Data Toggle Reset (WS)
 *  0b1..Reset PID sequence
 */
#define USBHS_ENDPTCTRL_RXR(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_RXR_SHIFT)) & USBHS_ENDPTCTRL_RXR_MASK)

#define USBHS_ENDPTCTRL_RXE_MASK                 (0x80U)
#define USBHS_ENDPTCTRL_RXE_SHIFT                (7U)
/*! RXE - RX Endpoint Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBHS_ENDPTCTRL_RXE(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_RXE_SHIFT)) & USBHS_ENDPTCTRL_RXE_MASK)

#define USBHS_ENDPTCTRL_TXS_MASK                 (0x10000U)
#define USBHS_ENDPTCTRL_TXS_SHIFT                (16U)
/*! TXS - TX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBHS_ENDPTCTRL_TXS(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_TXS_SHIFT)) & USBHS_ENDPTCTRL_TXS_MASK)

#define USBHS_ENDPTCTRL_TXD_MASK                 (0x20000U)
#define USBHS_ENDPTCTRL_TXD_SHIFT                (17U)
/*! TXD - TX Endpoint Data Source
 *  0b0..Dual Port Memory Buffer/DMA Engine
 */
#define USBHS_ENDPTCTRL_TXD(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_TXD_SHIFT)) & USBHS_ENDPTCTRL_TXD_MASK)

#define USBHS_ENDPTCTRL_TXT_MASK                 (0xC0000U)
#define USBHS_ENDPTCTRL_TXT_SHIFT                (18U)
/*! TXT - TX Endpoint Type
 *  0b00..Control
 *  0b01..Isochronous
 *  0b10..Bulk
 *  0b11..Interrupt
 */
#define USBHS_ENDPTCTRL_TXT(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_TXT_SHIFT)) & USBHS_ENDPTCTRL_TXT_MASK)

#define USBHS_ENDPTCTRL_TXI_MASK                 (0x200000U)
#define USBHS_ENDPTCTRL_TXI_SHIFT                (21U)
/*! TXI - TX Data Toggle Inhibit
 *  0b0..PID sequencing enabled
 *  0b1..PID sequencing disabled
 */
#define USBHS_ENDPTCTRL_TXI(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_TXI_SHIFT)) & USBHS_ENDPTCTRL_TXI_MASK)

#define USBHS_ENDPTCTRL_TXR_MASK                 (0x400000U)
#define USBHS_ENDPTCTRL_TXR_SHIFT                (22U)
/*! TXR - TX Data Toggle Reset (WS)
 *  0b1..Reset PID sequence
 */
#define USBHS_ENDPTCTRL_TXR(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_TXR_SHIFT)) & USBHS_ENDPTCTRL_TXR_MASK)

#define USBHS_ENDPTCTRL_TXE_MASK                 (0x800000U)
#define USBHS_ENDPTCTRL_TXE_SHIFT                (23U)
/*! TXE - TX Endpoint Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBHS_ENDPTCTRL_TXE(x)                   (((uint32_t)(((uint32_t)(x)) << USBHS_ENDPTCTRL_TXE_SHIFT)) & USBHS_ENDPTCTRL_TXE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBHS_Register_Masks */

/* Backward compatibility */
#define GPTIMER0CTL                              GPTIMER0CTRL
#define GPTIMER1CTL                              GPTIMER1CTRL
#define USB_SBUSCFG                              SBUSCFG
#define EPLISTADDR                               ENDPTLISTADDR
#define EPSETUPSR                                ENDPTSETUPSTAT
#define EPPRIME                                  ENDPTPRIME
#define EPFLUSH                                  ENDPTFLUSH
#define EPSR                                     ENDPTSTAT
#define EPCOMPLETE                               ENDPTCOMPLETE
#define EPCR                                     ENDPTCTRL
#define EPCR0                                    ENDPTCTRL0
#define USBHS_GPTIMER0CTL_GPTCNT_MASK            USBHS_GPTIMER0CTRL_GPTCNT_MASK
#define USBHS_GPTIMER0CTL_GPTCNT_SHIFT           USBHS_GPTIMER0CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER0CTL_GPTCNT(x)              USBHS_GPTIMER0CTRL_GPTCNT(x)
#define USBHS_GPTIMER0CTL_MODE_MASK              USBHS_GPTIMER0CTRL_GPTMODE_MASK
#define USBHS_GPTIMER0CTL_MODE_SHIFT             USBHS_GPTIMER0CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER0CTL_MODE(x)                USBHS_GPTIMER0CTRL_GPTMODE(x)
#define USBHS_GPTIMER0CTL_RST_MASK               USBHS_GPTIMER0CTRL_GPTRST_MASK
#define USBHS_GPTIMER0CTL_RST_SHIFT              USBHS_GPTIMER0CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER0CTL_RST(x)                 USBHS_GPTIMER0CTRL_GPTRST(x)
#define USBHS_GPTIMER0CTL_RUN_MASK               USBHS_GPTIMER0CTRL_GPTRUN_MASK
#define USBHS_GPTIMER0CTL_RUN_SHIFT              USBHS_GPTIMER0CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER0CTL_RUN(x)                 USBHS_GPTIMER0CTRL_GPTRUN(x)
#define USBHS_GPTIMER1CTL_GPTCNT_MASK            USBHS_GPTIMER1CTRL_GPTCNT_MASK
#define USBHS_GPTIMER1CTL_GPTCNT_SHIFT           USBHS_GPTIMER1CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER1CTL_GPTCNT(x)              USBHS_GPTIMER1CTRL_GPTCNT(x)
#define USBHS_GPTIMER1CTL_MODE_MASK              USBHS_GPTIMER1CTRL_GPTMODE_MASK
#define USBHS_GPTIMER1CTL_MODE_SHIFT             USBHS_GPTIMER1CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER1CTL_MODE(x)                USBHS_GPTIMER1CTRL_GPTMODE(x)
#define USBHS_GPTIMER1CTL_RST_MASK               USBHS_GPTIMER1CTRL_GPTRST_MASK
#define USBHS_GPTIMER1CTL_RST_SHIFT              USBHS_GPTIMER1CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER1CTL_RST(x)                 USBHS_GPTIMER1CTRL_GPTRST(x)
#define USBHS_GPTIMER1CTL_RUN_MASK               USBHS_GPTIMER1CTRL_GPTRUN_MASK
#define USBHS_GPTIMER1CTL_RUN_SHIFT              USBHS_GPTIMER1CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER1CTL_RUN(x)                 USBHS_GPTIMER1CTRL_GPTRUN(x)
#define USBHS_USB_SBUSCFG_BURSTMODE_MASK         USBHS_SBUSCFG_AHBBRST_MASK
#define USBHS_USB_SBUSCFG_BURSTMODE_SHIFT        USBHS_SBUSCFG_AHBBRST_SHIFT
#define USBHS_USB_SBUSCFG_BURSTMODE(x)           USBHS_SBUSCFG_AHBBRST(x)
#define USBHS_USBCMD_FS_MASK                     USBHS_USBCMD_FS_1_MASK
#define USBHS_USBCMD_FS_SHIFT                    USBHS_USBCMD_FS_1_SHIFT
#define USBHS_USBCMD_FS(x)                       USBHS_USBCMD_FS_1(x)
#define USBHS_EPLISTADDR_EPBASE_MASK             USBHS_ENDPTLISTADDR_EPBASE_MASK
#define USBHS_EPLISTADDR_EPBASE_SHIFT            USBHS_ENDPTLISTADDR_EPBASE_SHIFT
#define USBHS_EPLISTADDR_EPBASE(x)               USBHS_ENDPTLISTADDR_EPBASE(x)
#define USBHS_EPSETUPSR_EPSETUPSTAT_MASK         USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK
#define USBHS_EPSETUPSR_EPSETUPSTAT_SHIFT        USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT
#define USBHS_EPSETUPSR_EPSETUPSTAT(x)           USBHS_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)
#define USBHS_EPPRIME_PERB_MASK                  USBHS_ENDPTPRIME_PERB_MASK
#define USBHS_EPPRIME_PERB_SHIFT                 USBHS_ENDPTPRIME_PERB_SHIFT
#define USBHS_EPPRIME_PERB(x)                    USBHS_ENDPTPRIME_PERB(x)
#define USBHS_EPPRIME_PETB_MASK                  USBHS_ENDPTPRIME_PETB_MASK
#define USBHS_EPPRIME_PETB_SHIFT                 USBHS_ENDPTPRIME_PETB_SHIFT
#define USBHS_EPPRIME_PETB(x)                    USBHS_ENDPTPRIME_PETB(x)
#define USBHS_EPFLUSH_FERB_MASK                  USBHS_ENDPTFLUSH_FERB_MASK
#define USBHS_EPFLUSH_FERB_SHIFT                 USBHS_ENDPTFLUSH_FERB_SHIFT
#define USBHS_EPFLUSH_FERB(x)                    USBHS_ENDPTFLUSH_FERB(x)
#define USBHS_EPFLUSH_FETB_MASK                  USBHS_ENDPTFLUSH_FETB_MASK
#define USBHS_EPFLUSH_FETB_SHIFT                 USBHS_ENDPTFLUSH_FETB_SHIFT
#define USBHS_EPFLUSH_FETB(x)                    USBHS_ENDPTFLUSH_FETB(x)
#define USBHS_EPSR_ERBR_MASK                     USBHS_ENDPTSTAT_ERBR_MASK
#define USBHS_EPSR_ERBR_SHIFT                    USBHS_ENDPTSTAT_ERBR_SHIFT
#define USBHS_EPSR_ERBR(x)                       USBHS_ENDPTSTAT_ERBR(x)
#define USBHS_EPSR_ETBR_MASK                     USBHS_ENDPTSTAT_ETBR_MASK
#define USBHS_EPSR_ETBR_SHIFT                    USBHS_ENDPTSTAT_ETBR_SHIFT
#define USBHS_EPSR_ETBR(x)                       USBHS_ENDPTSTAT_ETBR(x)
#define USBHS_EPCOMPLETE_ERCE_MASK               USBHS_ENDPTCOMPLETE_ERCE_MASK
#define USBHS_EPCOMPLETE_ERCE_SHIFT              USBHS_ENDPTCOMPLETE_ERCE_SHIFT
#define USBHS_EPCOMPLETE_ERCE(x)                 USBHS_ENDPTCOMPLETE_ERCE(x)
#define USBHS_EPCOMPLETE_ETCE_MASK               USBHS_ENDPTCOMPLETE_ETCE_MASK
#define USBHS_EPCOMPLETE_ETCE_SHIFT              USBHS_ENDPTCOMPLETE_ETCE_SHIFT
#define USBHS_EPCOMPLETE_ETCE(x)                 USBHS_ENDPTCOMPLETE_ETCE(x)
#define USBHS_EPCR0_RXS_MASK                     USBHS_ENDPTCTRL0_RXS_MASK
#define USBHS_EPCR0_RXS_SHIFT                    USBHS_ENDPTCTRL0_RXS_SHIFT
#define USBHS_EPCR0_RXS(x)                       USBHS_ENDPTCTRL0_RXS(x)
#define USBHS_EPCR0_RXT_MASK                     USBHS_ENDPTCTRL0_RXT_MASK
#define USBHS_EPCR0_RXT_SHIFT                    USBHS_ENDPTCTRL0_RXT_SHIFT
#define USBHS_EPCR0_RXT(x)                       USBHS_ENDPTCTRL0_RXT(x)
#define USBHS_EPCR0_RXE_MASK                     USBHS_ENDPTCTRL0_RXE_MASK
#define USBHS_EPCR0_RXE_SHIFT                    USBHS_ENDPTCTRL0_RXE_SHIFT
#define USBHS_EPCR0_RXE(x)                       USBHS_ENDPTCTRL0_RXE(x)
#define USBHS_EPCR0_TXS_MASK                     USBHS_ENDPTCTRL0_TXS_MASK
#define USBHS_EPCR0_TXS_SHIFT                    USBHS_ENDPTCTRL0_TXS_SHIFT
#define USBHS_EPCR0_TXS(x)                       USBHS_ENDPTCTRL0_TXS(x)
#define USBHS_EPCR0_TXT_MASK                     USBHS_ENDPTCTRL0_TXT_MASK
#define USBHS_EPCR0_TXT_SHIFT                    USBHS_ENDPTCTRL0_TXT_SHIFT
#define USBHS_EPCR0_TXT(x)                       USBHS_ENDPTCTRL0_TXT(x)
#define USBHS_EPCR0_TXE_MASK                     USBHS_ENDPTCTRL0_TXE_MASK
#define USBHS_EPCR0_TXE_SHIFT                    USBHS_ENDPTCTRL0_TXE_SHIFT
#define USBHS_EPCR0_TXE(x)                       USBHS_ENDPTCTRL0_TXE(x)
#define USBHS_EPCR_RXS_MASK                      USBHS_ENDPTCTRL_RXS_MASK
#define USBHS_EPCR_RXS_SHIFT                     USBHS_ENDPTCTRL_RXS_SHIFT
#define USBHS_EPCR_RXS(x)                        USBHS_ENDPTCTRL_RXS(x)
#define USBHS_EPCR_RXD_MASK                      USBHS_ENDPTCTRL_RXD_MASK
#define USBHS_EPCR_RXD_SHIFT                     USBHS_ENDPTCTRL_RXD_SHIFT
#define USBHS_EPCR_RXD(x)                        USBHS_ENDPTCTRL_RXD(x)
#define USBHS_EPCR_RXT_MASK                      USBHS_ENDPTCTRL_RXT_MASK
#define USBHS_EPCR_RXT_SHIFT                     USBHS_ENDPTCTRL_RXT_SHIFT
#define USBHS_EPCR_RXT(x)                        USBHS_ENDPTCTRL_RXT(x)
#define USBHS_EPCR_RXI_MASK                      USBHS_ENDPTCTRL_RXI_MASK
#define USBHS_EPCR_RXI_SHIFT                     USBHS_ENDPTCTRL_RXI_SHIFT
#define USBHS_EPCR_RXI(x)                        USBHS_ENDPTCTRL_RXI(x)
#define USBHS_EPCR_RXR_MASK                      USBHS_ENDPTCTRL_RXR_MASK
#define USBHS_EPCR_RXR_SHIFT                     USBHS_ENDPTCTRL_RXR_SHIFT
#define USBHS_EPCR_RXR(x)                        USBHS_ENDPTCTRL_RXR(x)
#define USBHS_EPCR_RXE_MASK                      USBHS_ENDPTCTRL_RXE_MASK
#define USBHS_EPCR_RXE_SHIFT                     USBHS_ENDPTCTRL_RXE_SHIFT
#define USBHS_EPCR_RXE(x)                        USBHS_ENDPTCTRL_RXE(x)
#define USBHS_EPCR_TXS_MASK                      USBHS_ENDPTCTRL_TXS_MASK
#define USBHS_EPCR_TXS_SHIFT                     USBHS_ENDPTCTRL_TXS_SHIFT
#define USBHS_EPCR_TXS(x)                        USBHS_ENDPTCTRL_TXS(x)
#define USBHS_EPCR_TXD_MASK                      USBHS_ENDPTCTRL_TXD_MASK
#define USBHS_EPCR_TXD_SHIFT                     USBHS_ENDPTCTRL_TXD_SHIFT
#define USBHS_EPCR_TXD(x)                        USBHS_ENDPTCTRL_TXD(x)
#define USBHS_EPCR_TXT_MASK                      USBHS_ENDPTCTRL_TXT_MASK
#define USBHS_EPCR_TXT_SHIFT                     USBHS_ENDPTCTRL_TXT_SHIFT
#define USBHS_EPCR_TXT(x)                        USBHS_ENDPTCTRL_TXT(x)
#define USBHS_EPCR_TXI_MASK                      USBHS_ENDPTCTRL_TXI_MASK
#define USBHS_EPCR_TXI_SHIFT                     USBHS_ENDPTCTRL_TXI_SHIFT
#define USBHS_EPCR_TXI(x)                        USBHS_ENDPTCTRL_TXI(x)
#define USBHS_EPCR_TXR_MASK                      USBHS_ENDPTCTRL_TXR_MASK
#define USBHS_EPCR_TXR_SHIFT                     USBHS_ENDPTCTRL_TXR_SHIFT
#define USBHS_EPCR_TXR(x)                        USBHS_ENDPTCTRL_TXR(x)
#define USBHS_EPCR_TXE_MASK                      USBHS_ENDPTCTRL_TXE_MASK
#define USBHS_EPCR_TXE_SHIFT                     USBHS_ENDPTCTRL_TXE_SHIFT
#define USBHS_EPCR_TXE(x)                        USBHS_ENDPTCTRL_TXE(x)
#define USBHS_EPCR_COUNT                         USBHS_ENDPTCTRL_COUNT
#define USBHS_PORTSC1_WKDS_MASK                  USBHS_PORTSC1_WKDC_MASK
#define USBHS_PORTSC1_WKDS_SHIFT                 USBHS_PORTSC1_WKDC_SHIFT
#define USBHS_PORTSC1_WKDS(x)                    USBHS_PORTSC1_WKDC(x)
#define USBHS_IRQHandler                         USB1_HS_IRQHandler


/*!
 * @}
 */ /* end of group USBHS_Peripheral_Access_Layer */


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


#endif  /* PERI_USBHS_H_ */

