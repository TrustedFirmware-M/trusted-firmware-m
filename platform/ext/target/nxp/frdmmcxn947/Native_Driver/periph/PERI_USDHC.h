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
**         CMSIS Peripheral Access Layer for USDHC
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
 * @file PERI_USDHC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USDHC
 *
 * CMSIS Peripheral Access Layer for USDHC
 */

#if !defined(PERI_USDHC_H_)
#define PERI_USDHC_H_                            /**< Symbol preventing repeated inclusion */

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
   -- USDHC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USDHC_Peripheral_Access_Layer USDHC Peripheral Access Layer
 * @{
 */

/** USDHC - Register Layout Typedef */
typedef struct {
  __IO uint32_t DS_ADDR;                           /**< DMA System Address, offset: 0x0 */
  __IO uint32_t BLK_ATT;                           /**< Block Attributes, offset: 0x4 */
  __IO uint32_t CMD_ARG;                           /**< Command Argument, offset: 0x8 */
  __IO uint32_t CMD_XFR_TYP;                       /**< Command Transfer Type, offset: 0xC */
  __I  uint32_t CMD_RSP0;                          /**< Command Response0, offset: 0x10 */
  __I  uint32_t CMD_RSP1;                          /**< Command Response1, offset: 0x14 */
  __I  uint32_t CMD_RSP2;                          /**< Command Response2, offset: 0x18 */
  __I  uint32_t CMD_RSP3;                          /**< Command Response3, offset: 0x1C */
  __IO uint32_t DATA_BUFF_ACC_PORT;                /**< Data Buffer Access Port, offset: 0x20 */
  __I  uint32_t PRES_STATE;                        /**< Present State, offset: 0x24 */
  __IO uint32_t PROT_CTRL;                         /**< Protocol Control, offset: 0x28 */
  __IO uint32_t SYS_CTRL;                          /**< System Control, offset: 0x2C */
  __IO uint32_t INT_STATUS;                        /**< Interrupt Status, offset: 0x30 */
  __IO uint32_t INT_STATUS_EN;                     /**< Interrupt Status Enable, offset: 0x34 */
  __IO uint32_t INT_SIGNAL_EN;                     /**< Interrupt Signal Enable, offset: 0x38 */
  __IO uint32_t AUTOCMD12_ERR_STATUS;              /**< Auto CMD12 Error Status, offset: 0x3C */
  __IO uint32_t HOST_CTRL_CAP;                     /**< Host Controller Capabilities, offset: 0x40 */
  __IO uint32_t WTMK_LVL;                          /**< Watermark Level, offset: 0x44 */
  __IO uint32_t MIX_CTRL;                          /**< Mixer Control, offset: 0x48 */
       uint8_t RESERVED_0[4];
  __IO uint32_t FORCE_EVENT;                       /**< Force Event, offset: 0x50 */
  __I  uint32_t ADMA_ERR_STATUS;                   /**< ADMA Error Status, offset: 0x54 */
  __IO uint32_t ADMA_SYS_ADDR;                     /**< ADMA System Address, offset: 0x58 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DLL_CTRL;                          /**< DLL (Delay Line) Control, offset: 0x60 */
  __I  uint32_t DLL_STATUS;                        /**< DLL Status, offset: 0x64 */
  __IO uint32_t CLK_TUNE_CTRL_STATUS;              /**< CLK Tuning Control and Status, offset: 0x68 */
       uint8_t RESERVED_2[84];
  __IO uint32_t VEND_SPEC;                         /**< Vendor Specific Register, offset: 0xC0 */
  __IO uint32_t MMC_BOOT;                          /**< eMMC Boot, offset: 0xC4 */
  __IO uint32_t VEND_SPEC2;                        /**< Vendor Specific 2 Register, offset: 0xC8 */
  __IO uint32_t TUNING_CTRL;                       /**< Tuning Control, offset: 0xCC */
} USDHC_Type;

/* ----------------------------------------------------------------------------
   -- USDHC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USDHC_Register_Masks USDHC Register Masks
 * @{
 */

/*! @name DS_ADDR - DMA System Address */
/*! @{ */

#define USDHC_DS_ADDR_DS_ADDR_MASK               (0xFFFFFFFFU)
#define USDHC_DS_ADDR_DS_ADDR_SHIFT              (0U)
/*! DS_ADDR - System address */
#define USDHC_DS_ADDR_DS_ADDR(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_DS_ADDR_DS_ADDR_SHIFT)) & USDHC_DS_ADDR_DS_ADDR_MASK)
/*! @} */

/*! @name BLK_ATT - Block Attributes */
/*! @{ */

#define USDHC_BLK_ATT_BLKSIZE_MASK               (0x1FFFU)
#define USDHC_BLK_ATT_BLKSIZE_SHIFT              (0U)
/*! BLKSIZE - Transfer block size
 *  0b0000000000000..No data transfer
 *  0b0000000000001..1 byte
 *  0b0000000000010..2 bytes
 *  0b0000000000011..3 bytes
 *  0b0000000000100..4 bytes
 *  0b0000111111111..511 bytes
 *  0b0001000000000..512 bytes
 *  0b0100000000000..2048 bytes
 *  0b1000000000000..4096 bytes
 */
#define USDHC_BLK_ATT_BLKSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_BLK_ATT_BLKSIZE_SHIFT)) & USDHC_BLK_ATT_BLKSIZE_MASK)

#define USDHC_BLK_ATT_BLKCNT_MASK                (0xFFFF0000U)
#define USDHC_BLK_ATT_BLKCNT_SHIFT               (16U)
/*! BLKCNT - Blocks count for current transfer
 *  0b0000000000000000..Stop count
 *  0b0000000000000001..1 block
 *  0b0000000000000010..2 blocks
 *  0b1111111111111111..65535 blocks
 */
#define USDHC_BLK_ATT_BLKCNT(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_BLK_ATT_BLKCNT_SHIFT)) & USDHC_BLK_ATT_BLKCNT_MASK)
/*! @} */

/*! @name CMD_ARG - Command Argument */
/*! @{ */

#define USDHC_CMD_ARG_CMDARG_MASK                (0xFFFFFFFFU)
#define USDHC_CMD_ARG_CMDARG_SHIFT               (0U)
/*! CMDARG - Command argument */
#define USDHC_CMD_ARG_CMDARG(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_ARG_CMDARG_SHIFT)) & USDHC_CMD_ARG_CMDARG_MASK)
/*! @} */

/*! @name CMD_XFR_TYP - Command Transfer Type */
/*! @{ */

#define USDHC_CMD_XFR_TYP_DMAEN_MASK             (0x1U)
#define USDHC_CMD_XFR_TYP_DMAEN_SHIFT            (0U)
/*! DMAEN - DMAEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_DMAEN(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DMAEN_SHIFT)) & USDHC_CMD_XFR_TYP_DMAEN_MASK)

#define USDHC_CMD_XFR_TYP_BCEN_MASK              (0x2U)
#define USDHC_CMD_XFR_TYP_BCEN_SHIFT             (1U)
/*! BCEN - BCEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_BCEN(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_BCEN_SHIFT)) & USDHC_CMD_XFR_TYP_BCEN_MASK)

#define USDHC_CMD_XFR_TYP_AC12EN_MASK            (0x4U)
#define USDHC_CMD_XFR_TYP_AC12EN_SHIFT           (2U)
/*! AC12EN - AC12EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_AC12EN(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_AC12EN_SHIFT)) & USDHC_CMD_XFR_TYP_AC12EN_MASK)

#define USDHC_CMD_XFR_TYP_DDR_EN_MASK            (0x8U)
#define USDHC_CMD_XFR_TYP_DDR_EN_SHIFT           (3U)
/*! DDR_EN - DDR_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_DDR_EN(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DDR_EN_SHIFT)) & USDHC_CMD_XFR_TYP_DDR_EN_MASK)

#define USDHC_CMD_XFR_TYP_DTDSEL_MASK            (0x10U)
#define USDHC_CMD_XFR_TYP_DTDSEL_SHIFT           (4U)
/*! DTDSEL - DTDSEL
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_DTDSEL(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DTDSEL_SHIFT)) & USDHC_CMD_XFR_TYP_DTDSEL_MASK)

#define USDHC_CMD_XFR_TYP_MSBSEL_MASK            (0x20U)
#define USDHC_CMD_XFR_TYP_MSBSEL_SHIFT           (5U)
/*! MSBSEL - MSBSEL
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_MSBSEL(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_MSBSEL_SHIFT)) & USDHC_CMD_XFR_TYP_MSBSEL_MASK)

#define USDHC_CMD_XFR_TYP_NIBBLE_POS_MASK        (0x40U)
#define USDHC_CMD_XFR_TYP_NIBBLE_POS_SHIFT       (6U)
/*! NIBBLE_POS - NIBBLE_POS
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_NIBBLE_POS(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_NIBBLE_POS_SHIFT)) & USDHC_CMD_XFR_TYP_NIBBLE_POS_MASK)

#define USDHC_CMD_XFR_TYP_AC23EN_MASK            (0x80U)
#define USDHC_CMD_XFR_TYP_AC23EN_SHIFT           (7U)
/*! AC23EN - AC23EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_CMD_XFR_TYP_AC23EN(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_AC23EN_SHIFT)) & USDHC_CMD_XFR_TYP_AC23EN_MASK)

#define USDHC_CMD_XFR_TYP_RSPTYP_MASK            (0x30000U)
#define USDHC_CMD_XFR_TYP_RSPTYP_SHIFT           (16U)
/*! RSPTYP - Response type select
 *  0b00..No response
 *  0b01..Response length 136
 *  0b10..Response length 48
 *  0b11..Response length 48, check busy after response
 */
#define USDHC_CMD_XFR_TYP_RSPTYP(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_RSPTYP_SHIFT)) & USDHC_CMD_XFR_TYP_RSPTYP_MASK)

#define USDHC_CMD_XFR_TYP_CCCEN_MASK             (0x80000U)
#define USDHC_CMD_XFR_TYP_CCCEN_SHIFT            (19U)
/*! CCCEN - Command CRC check enable
 *  0b0..Disables command CRC check
 *  0b1..Enables command CRC check
 */
#define USDHC_CMD_XFR_TYP_CCCEN(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CCCEN_SHIFT)) & USDHC_CMD_XFR_TYP_CCCEN_MASK)

#define USDHC_CMD_XFR_TYP_CICEN_MASK             (0x100000U)
#define USDHC_CMD_XFR_TYP_CICEN_SHIFT            (20U)
/*! CICEN - Command index check enable
 *  0b0..Disable command index check
 *  0b1..Enables command index check
 */
#define USDHC_CMD_XFR_TYP_CICEN(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CICEN_SHIFT)) & USDHC_CMD_XFR_TYP_CICEN_MASK)

#define USDHC_CMD_XFR_TYP_DPSEL_MASK             (0x200000U)
#define USDHC_CMD_XFR_TYP_DPSEL_SHIFT            (21U)
/*! DPSEL - Data present select
 *  0b0..No data present
 *  0b1..Data present
 */
#define USDHC_CMD_XFR_TYP_DPSEL(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DPSEL_SHIFT)) & USDHC_CMD_XFR_TYP_DPSEL_MASK)

#define USDHC_CMD_XFR_TYP_CMDTYP_MASK            (0xC00000U)
#define USDHC_CMD_XFR_TYP_CMDTYP_SHIFT           (22U)
/*! CMDTYP - Command type
 *  0b00..Normal other commands
 *  0b01..Suspend CMD52 for writing bus suspend in CCCR
 *  0b10..Resume CMD52 for writing function select in CCCR
 *  0b11..Abort CMD12, CMD52 for writing I/O Abort in CCCR
 */
#define USDHC_CMD_XFR_TYP_CMDTYP(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CMDTYP_SHIFT)) & USDHC_CMD_XFR_TYP_CMDTYP_MASK)

#define USDHC_CMD_XFR_TYP_CMDINX_MASK            (0x3F000000U)
#define USDHC_CMD_XFR_TYP_CMDINX_SHIFT           (24U)
/*! CMDINX - Command index */
#define USDHC_CMD_XFR_TYP_CMDINX(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CMDINX_SHIFT)) & USDHC_CMD_XFR_TYP_CMDINX_MASK)
/*! @} */

/*! @name CMD_RSP0 - Command Response0 */
/*! @{ */

#define USDHC_CMD_RSP0_CMDRSP0_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP0_CMDRSP0_SHIFT             (0U)
/*! CMDRSP0 - Command response 0 */
#define USDHC_CMD_RSP0_CMDRSP0(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP0_CMDRSP0_SHIFT)) & USDHC_CMD_RSP0_CMDRSP0_MASK)
/*! @} */

/*! @name CMD_RSP1 - Command Response1 */
/*! @{ */

#define USDHC_CMD_RSP1_CMDRSP1_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP1_CMDRSP1_SHIFT             (0U)
/*! CMDRSP1 - Command response 1 */
#define USDHC_CMD_RSP1_CMDRSP1(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP1_CMDRSP1_SHIFT)) & USDHC_CMD_RSP1_CMDRSP1_MASK)
/*! @} */

/*! @name CMD_RSP2 - Command Response2 */
/*! @{ */

#define USDHC_CMD_RSP2_CMDRSP2_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP2_CMDRSP2_SHIFT             (0U)
/*! CMDRSP2 - Command response 2 */
#define USDHC_CMD_RSP2_CMDRSP2(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP2_CMDRSP2_SHIFT)) & USDHC_CMD_RSP2_CMDRSP2_MASK)
/*! @} */

/*! @name CMD_RSP3 - Command Response3 */
/*! @{ */

#define USDHC_CMD_RSP3_CMDRSP3_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP3_CMDRSP3_SHIFT             (0U)
/*! CMDRSP3 - Command response 3 */
#define USDHC_CMD_RSP3_CMDRSP3(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP3_CMDRSP3_SHIFT)) & USDHC_CMD_RSP3_CMDRSP3_MASK)
/*! @} */

/*! @name DATA_BUFF_ACC_PORT - Data Buffer Access Port */
/*! @{ */

#define USDHC_DATA_BUFF_ACC_PORT_DATCONT_MASK    (0xFFFFFFFFU)
#define USDHC_DATA_BUFF_ACC_PORT_DATCONT_SHIFT   (0U)
/*! DATCONT - Data content */
#define USDHC_DATA_BUFF_ACC_PORT_DATCONT(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_DATA_BUFF_ACC_PORT_DATCONT_SHIFT)) & USDHC_DATA_BUFF_ACC_PORT_DATCONT_MASK)
/*! @} */

/*! @name PRES_STATE - Present State */
/*! @{ */

#define USDHC_PRES_STATE_CIHB_MASK               (0x1U)
#define USDHC_PRES_STATE_CIHB_SHIFT              (0U)
/*! CIHB - Command inhibit (CMD)
 *  0b0..Can issue command using only CMD line
 *  0b1..Cannot issue command
 */
#define USDHC_PRES_STATE_CIHB(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CIHB_SHIFT)) & USDHC_PRES_STATE_CIHB_MASK)

#define USDHC_PRES_STATE_CDIHB_MASK              (0x2U)
#define USDHC_PRES_STATE_CDIHB_SHIFT             (1U)
/*! CDIHB - Command Inhibit Data (DATA)
 *  0b0..Can issue command that uses the DATA line
 *  0b1..Cannot issue command that uses the DATA line
 */
#define USDHC_PRES_STATE_CDIHB(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CDIHB_SHIFT)) & USDHC_PRES_STATE_CDIHB_MASK)

#define USDHC_PRES_STATE_DLA_MASK                (0x4U)
#define USDHC_PRES_STATE_DLA_SHIFT               (2U)
/*! DLA - Data line active
 *  0b0..DATA line inactive
 *  0b1..DATA line active
 */
#define USDHC_PRES_STATE_DLA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_DLA_SHIFT)) & USDHC_PRES_STATE_DLA_MASK)

#define USDHC_PRES_STATE_SDSTB_MASK              (0x8U)
#define USDHC_PRES_STATE_SDSTB_SHIFT             (3U)
/*! SDSTB - SD clock stable
 *  0b0..Clock is changing frequency and not stable.
 *  0b1..Clock is stable.
 */
#define USDHC_PRES_STATE_SDSTB(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_SDSTB_SHIFT)) & USDHC_PRES_STATE_SDSTB_MASK)

#define USDHC_PRES_STATE_WTA_MASK                (0x100U)
#define USDHC_PRES_STATE_WTA_SHIFT               (8U)
/*! WTA - Write transfer active
 *  0b0..No valid data
 *  0b1..Transferring data
 */
#define USDHC_PRES_STATE_WTA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_WTA_SHIFT)) & USDHC_PRES_STATE_WTA_MASK)

#define USDHC_PRES_STATE_RTA_MASK                (0x200U)
#define USDHC_PRES_STATE_RTA_SHIFT               (9U)
/*! RTA - Read transfer active
 *  0b0..No valid data
 *  0b1..Transferring data
 */
#define USDHC_PRES_STATE_RTA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_RTA_SHIFT)) & USDHC_PRES_STATE_RTA_MASK)

#define USDHC_PRES_STATE_BWEN_MASK               (0x400U)
#define USDHC_PRES_STATE_BWEN_SHIFT              (10U)
/*! BWEN - Buffer write enable
 *  0b0..Write disable
 *  0b1..Write enable
 */
#define USDHC_PRES_STATE_BWEN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_BWEN_SHIFT)) & USDHC_PRES_STATE_BWEN_MASK)

#define USDHC_PRES_STATE_BREN_MASK               (0x800U)
#define USDHC_PRES_STATE_BREN_SHIFT              (11U)
/*! BREN - Buffer read enable
 *  0b0..Read disable
 *  0b1..Read enable
 */
#define USDHC_PRES_STATE_BREN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_BREN_SHIFT)) & USDHC_PRES_STATE_BREN_MASK)

#define USDHC_PRES_STATE_RTR_MASK                (0x1000U)
#define USDHC_PRES_STATE_RTR_SHIFT               (12U)
/*! RTR - Re-Tuning Request (only for SD3.0 SDR104 mode)
 *  0b0..Fixed or well tuned sampling clock
 *  0b1..Sampling clock needs re-tuning
 */
#define USDHC_PRES_STATE_RTR(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_RTR_SHIFT)) & USDHC_PRES_STATE_RTR_MASK)

#define USDHC_PRES_STATE_TSCD_MASK               (0x8000U)
#define USDHC_PRES_STATE_TSCD_SHIFT              (15U)
/*! TSCD - Tap select change done
 *  0b0..Delay cell select change is not finished.
 *  0b1..Delay cell select change is finished.
 */
#define USDHC_PRES_STATE_TSCD(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_TSCD_SHIFT)) & USDHC_PRES_STATE_TSCD_MASK)

#define USDHC_PRES_STATE_CINST_MASK              (0x10000U)
#define USDHC_PRES_STATE_CINST_SHIFT             (16U)
/*! CINST - Card inserted
 *  0b0..Power on reset or no card
 *  0b1..Card inserted
 */
#define USDHC_PRES_STATE_CINST(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CINST_SHIFT)) & USDHC_PRES_STATE_CINST_MASK)

#define USDHC_PRES_STATE_CLSL_MASK               (0x800000U)
#define USDHC_PRES_STATE_CLSL_SHIFT              (23U)
/*! CLSL - CMD line signal level */
#define USDHC_PRES_STATE_CLSL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CLSL_SHIFT)) & USDHC_PRES_STATE_CLSL_MASK)

#define USDHC_PRES_STATE_DLSL_MASK               (0xFF000000U)
#define USDHC_PRES_STATE_DLSL_SHIFT              (24U)
/*! DLSL - DATA[7:0] line signal level
 *  0b00000001..Data 0 line signal level
 *  0b00000010..Data 1 line signal level
 *  0b00000100..Data 2 line signal level
 *  0b00001000..Data 3 line signal level
 *  0b00010000..Data 4 line signal level
 *  0b00100000..Data 5 line signal level
 *  0b01000000..Data 6 line signal level
 *  0b10000000..Data 7 line signal level
 */
#define USDHC_PRES_STATE_DLSL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_DLSL_SHIFT)) & USDHC_PRES_STATE_DLSL_MASK)
/*! @} */

/*! @name PROT_CTRL - Protocol Control */
/*! @{ */

#define USDHC_PROT_CTRL_DTW_MASK                 (0x6U)
#define USDHC_PROT_CTRL_DTW_SHIFT                (1U)
/*! DTW - Data transfer width
 *  0b00..1-bit mode
 *  0b01..4-bit mode
 *  0b10..8-bit mode
 *  0b11..Reserved
 */
#define USDHC_PROT_CTRL_DTW(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_DTW_SHIFT)) & USDHC_PROT_CTRL_DTW_MASK)

#define USDHC_PROT_CTRL_D3CD_MASK                (0x8U)
#define USDHC_PROT_CTRL_D3CD_SHIFT               (3U)
/*! D3CD - DATA3 as card detection pin
 *  0b0..DATA3 does not monitor card insertion
 *  0b1..DATA3 as card detection pin
 */
#define USDHC_PROT_CTRL_D3CD(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_D3CD_SHIFT)) & USDHC_PROT_CTRL_D3CD_MASK)

#define USDHC_PROT_CTRL_EMODE_MASK               (0x30U)
#define USDHC_PROT_CTRL_EMODE_SHIFT              (4U)
/*! EMODE - Endian mode
 *  0b00..Big endian mode
 *  0b01..Half word big endian mode
 *  0b10..Little endian mode
 *  0b11..Reserved
 */
#define USDHC_PROT_CTRL_EMODE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_EMODE_SHIFT)) & USDHC_PROT_CTRL_EMODE_MASK)

#define USDHC_PROT_CTRL_DMASEL_MASK              (0x300U)
#define USDHC_PROT_CTRL_DMASEL_SHIFT             (8U)
/*! DMASEL - DMA select
 *  0b00..No DMA or simple DMA is selected.
 *  0b01..ADMA1 is selected.
 *  0b10..ADMA2 is selected.
 *  0b11..Reserved
 */
#define USDHC_PROT_CTRL_DMASEL(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_DMASEL_SHIFT)) & USDHC_PROT_CTRL_DMASEL_MASK)

#define USDHC_PROT_CTRL_SABGREQ_MASK             (0x10000U)
#define USDHC_PROT_CTRL_SABGREQ_SHIFT            (16U)
/*! SABGREQ - Stop at block gap request
 *  0b0..Transfer
 *  0b1..Stop
 */
#define USDHC_PROT_CTRL_SABGREQ(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_SABGREQ_SHIFT)) & USDHC_PROT_CTRL_SABGREQ_MASK)

#define USDHC_PROT_CTRL_CREQ_MASK                (0x20000U)
#define USDHC_PROT_CTRL_CREQ_SHIFT               (17U)
/*! CREQ - Continue request
 *  0b0..No effect
 *  0b1..Restart
 */
#define USDHC_PROT_CTRL_CREQ(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_CREQ_SHIFT)) & USDHC_PROT_CTRL_CREQ_MASK)

#define USDHC_PROT_CTRL_RWCTL_MASK               (0x40000U)
#define USDHC_PROT_CTRL_RWCTL_SHIFT              (18U)
/*! RWCTL - Read wait control
 *  0b0..Disables read wait control and stop SD clock at block gap when SABGREQ field is set
 *  0b1..Enables read wait control and assert read wait without stopping SD clock at block gap when SABGREQ field is set
 */
#define USDHC_PROT_CTRL_RWCTL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_RWCTL_SHIFT)) & USDHC_PROT_CTRL_RWCTL_MASK)

#define USDHC_PROT_CTRL_IABG_MASK                (0x80000U)
#define USDHC_PROT_CTRL_IABG_SHIFT               (19U)
/*! IABG - Interrupt at block gap
 *  0b0..Disables interrupt at block gap
 *  0b1..Enables interrupt at block gap
 */
#define USDHC_PROT_CTRL_IABG(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_IABG_SHIFT)) & USDHC_PROT_CTRL_IABG_MASK)

#define USDHC_PROT_CTRL_RD_DONE_NO_8CLK_MASK     (0x100000U)
#define USDHC_PROT_CTRL_RD_DONE_NO_8CLK_SHIFT    (20U)
/*! RD_DONE_NO_8CLK - Read performed number 8 clock */
#define USDHC_PROT_CTRL_RD_DONE_NO_8CLK(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_RD_DONE_NO_8CLK_SHIFT)) & USDHC_PROT_CTRL_RD_DONE_NO_8CLK_MASK)

#define USDHC_PROT_CTRL_WECINT_MASK              (0x1000000U)
#define USDHC_PROT_CTRL_WECINT_SHIFT             (24U)
/*! WECINT - Wakeup event enable on card interrupt
 *  0b0..Disables wakeup event enable on card interrupt
 *  0b1..Enables wakeup event enable on card interrupt
 */
#define USDHC_PROT_CTRL_WECINT(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_WECINT_SHIFT)) & USDHC_PROT_CTRL_WECINT_MASK)

#define USDHC_PROT_CTRL_WECINS_MASK              (0x2000000U)
#define USDHC_PROT_CTRL_WECINS_SHIFT             (25U)
/*! WECINS - Wakeup event enable on SD card insertion
 *  0b0..Disable wakeup event enable on SD card insertion
 *  0b1..Enable wakeup event enable on SD card insertion
 */
#define USDHC_PROT_CTRL_WECINS(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_WECINS_SHIFT)) & USDHC_PROT_CTRL_WECINS_MASK)

#define USDHC_PROT_CTRL_WECRM_MASK               (0x4000000U)
#define USDHC_PROT_CTRL_WECRM_SHIFT              (26U)
/*! WECRM - Wakeup event enable on SD card removal
 *  0b0..Disables wakeup event enable on SD card removal
 *  0b1..Enables wakeup event enable on SD card removal
 */
#define USDHC_PROT_CTRL_WECRM(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_WECRM_SHIFT)) & USDHC_PROT_CTRL_WECRM_MASK)

#define USDHC_PROT_CTRL_BURST_LEN_EN_MASK        (0x38000000U)
#define USDHC_PROT_CTRL_BURST_LEN_EN_SHIFT       (27U)
/*! BURST_LEN_EN - BURST length enable for INCR, INCR4 / INCR8 / INCR16, INCR4-WRAP / INCR8-WRAP / INCR16-WRAP
 *  0b1xx..Burst length is enabled for INCR4-WRAP / INCR8-WRAP / INCR16-WRAP.
 *  0bx1x..Burst length is enabled for INCR4 / INCR8 / INCR16.
 *  0bxx1..Burst length is enabled for INCR.
 */
#define USDHC_PROT_CTRL_BURST_LEN_EN(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_BURST_LEN_EN_SHIFT)) & USDHC_PROT_CTRL_BURST_LEN_EN_MASK)

#define USDHC_PROT_CTRL_NON_EXACT_BLK_RD_MASK    (0x40000000U)
#define USDHC_PROT_CTRL_NON_EXACT_BLK_RD_SHIFT   (30U)
/*! NON_EXACT_BLK_RD - Non-exact block read
 *  0b0..The block read is exact block read. Host driver does not need to issue abort command to terminate this multi-block read.
 *  0b1..The block read is non-exact block read. Host driver needs to issue abort command to terminate this multi-block read.
 */
#define USDHC_PROT_CTRL_NON_EXACT_BLK_RD(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_NON_EXACT_BLK_RD_SHIFT)) & USDHC_PROT_CTRL_NON_EXACT_BLK_RD_MASK)
/*! @} */

/*! @name SYS_CTRL - System Control */
/*! @{ */

#define USDHC_SYS_CTRL_DVS_MASK                  (0xF0U)
#define USDHC_SYS_CTRL_DVS_SHIFT                 (4U)
/*! DVS - Divisor
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define USDHC_SYS_CTRL_DVS(x)                    (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_DVS_SHIFT)) & USDHC_SYS_CTRL_DVS_MASK)

#define USDHC_SYS_CTRL_SDCLKFS_MASK              (0xFF00U)
#define USDHC_SYS_CTRL_SDCLKFS_SHIFT             (8U)
/*! SDCLKFS - SDCLK frequency select */
#define USDHC_SYS_CTRL_SDCLKFS(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_SDCLKFS_SHIFT)) & USDHC_SYS_CTRL_SDCLKFS_MASK)

#define USDHC_SYS_CTRL_DTOCV_MASK                (0xF0000U)
#define USDHC_SYS_CTRL_DTOCV_SHIFT               (16U)
/*! DTOCV - Data timeout counter value
 *  0b0000..SDCLK x 2 32
 *  0b0001..SDCLK x 2 33
 *  0b0010..SDCLK x 2 18
 *  0b0011..SDCLK x 2 19
 *  0b1101..SDCLK x 2 29, recommend to use for supported speed modes except SDR104 mode
 *  0b1110..SDCLK x 2 30, recommend to use for SDR104 mode
 */
#define USDHC_SYS_CTRL_DTOCV(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_DTOCV_SHIFT)) & USDHC_SYS_CTRL_DTOCV_MASK)

#define USDHC_SYS_CTRL_RST_FIFO_MASK             (0x400000U)
#define USDHC_SYS_CTRL_RST_FIFO_SHIFT            (22U)
/*! RST_FIFO - Reset the async FIFO */
#define USDHC_SYS_CTRL_RST_FIFO(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RST_FIFO_SHIFT)) & USDHC_SYS_CTRL_RST_FIFO_MASK)

#define USDHC_SYS_CTRL_IPP_RST_N_MASK            (0x800000U)
#define USDHC_SYS_CTRL_IPP_RST_N_SHIFT           (23U)
/*! IPP_RST_N - Hardware reset */
#define USDHC_SYS_CTRL_IPP_RST_N(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_IPP_RST_N_SHIFT)) & USDHC_SYS_CTRL_IPP_RST_N_MASK)

#define USDHC_SYS_CTRL_RSTA_MASK                 (0x1000000U)
#define USDHC_SYS_CTRL_RSTA_SHIFT                (24U)
/*! RSTA - Software reset for all
 *  0b0..No reset
 *  0b1..Reset
 */
#define USDHC_SYS_CTRL_RSTA(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTA_SHIFT)) & USDHC_SYS_CTRL_RSTA_MASK)

#define USDHC_SYS_CTRL_RSTC_MASK                 (0x2000000U)
#define USDHC_SYS_CTRL_RSTC_SHIFT                (25U)
/*! RSTC - Software reset for CMD line
 *  0b0..No reset
 *  0b1..Reset
 */
#define USDHC_SYS_CTRL_RSTC(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTC_SHIFT)) & USDHC_SYS_CTRL_RSTC_MASK)

#define USDHC_SYS_CTRL_RSTD_MASK                 (0x4000000U)
#define USDHC_SYS_CTRL_RSTD_SHIFT                (26U)
/*! RSTD - Software reset for data line
 *  0b0..No reset
 *  0b1..Reset
 */
#define USDHC_SYS_CTRL_RSTD(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTD_SHIFT)) & USDHC_SYS_CTRL_RSTD_MASK)

#define USDHC_SYS_CTRL_INITA_MASK                (0x8000000U)
#define USDHC_SYS_CTRL_INITA_SHIFT               (27U)
/*! INITA - Initialization active */
#define USDHC_SYS_CTRL_INITA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_INITA_SHIFT)) & USDHC_SYS_CTRL_INITA_MASK)

#define USDHC_SYS_CTRL_RSTT_MASK                 (0x10000000U)
#define USDHC_SYS_CTRL_RSTT_SHIFT                (28U)
/*! RSTT - Reset tuning */
#define USDHC_SYS_CTRL_RSTT(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTT_SHIFT)) & USDHC_SYS_CTRL_RSTT_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status */
/*! @{ */

#define USDHC_INT_STATUS_CC_MASK                 (0x1U)
#define USDHC_INT_STATUS_CC_SHIFT                (0U)
/*! CC - Command complete
 *  0b0..Command not complete
 *  0b1..Command complete
 */
#define USDHC_INT_STATUS_CC(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CC_SHIFT)) & USDHC_INT_STATUS_CC_MASK)

#define USDHC_INT_STATUS_TC_MASK                 (0x2U)
#define USDHC_INT_STATUS_TC_SHIFT                (1U)
/*! TC - Transfer complete
 *  0b0..Transfer does not complete
 *  0b1..Transfer complete
 */
#define USDHC_INT_STATUS_TC(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_TC_SHIFT)) & USDHC_INT_STATUS_TC_MASK)

#define USDHC_INT_STATUS_BGE_MASK                (0x4U)
#define USDHC_INT_STATUS_BGE_SHIFT               (2U)
/*! BGE - Block gap event
 *  0b0..No block gap event
 *  0b1..Transaction stopped at block gap
 */
#define USDHC_INT_STATUS_BGE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_BGE_SHIFT)) & USDHC_INT_STATUS_BGE_MASK)

#define USDHC_INT_STATUS_DINT_MASK               (0x8U)
#define USDHC_INT_STATUS_DINT_SHIFT              (3U)
/*! DINT - DMA interrupt
 *  0b0..No DMA interrupt
 *  0b1..DMA interrupt is generated.
 */
#define USDHC_INT_STATUS_DINT(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DINT_SHIFT)) & USDHC_INT_STATUS_DINT_MASK)

#define USDHC_INT_STATUS_BWR_MASK                (0x10U)
#define USDHC_INT_STATUS_BWR_SHIFT               (4U)
/*! BWR - Buffer write ready
 *  0b0..Not ready to write buffer
 *  0b1..Ready to write buffer
 */
#define USDHC_INT_STATUS_BWR(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_BWR_SHIFT)) & USDHC_INT_STATUS_BWR_MASK)

#define USDHC_INT_STATUS_BRR_MASK                (0x20U)
#define USDHC_INT_STATUS_BRR_SHIFT               (5U)
/*! BRR - Buffer read ready
 *  0b0..Not ready to read buffer
 *  0b1..Ready to read buffer
 */
#define USDHC_INT_STATUS_BRR(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_BRR_SHIFT)) & USDHC_INT_STATUS_BRR_MASK)

#define USDHC_INT_STATUS_CINS_MASK               (0x40U)
#define USDHC_INT_STATUS_CINS_SHIFT              (6U)
/*! CINS - Card insertion
 *  0b0..Card state unstable or removed
 *  0b1..Card inserted
 */
#define USDHC_INT_STATUS_CINS(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CINS_SHIFT)) & USDHC_INT_STATUS_CINS_MASK)

#define USDHC_INT_STATUS_CRM_MASK                (0x80U)
#define USDHC_INT_STATUS_CRM_SHIFT               (7U)
/*! CRM - Card removal
 *  0b0..Card state unstable or inserted
 *  0b1..Card removed
 */
#define USDHC_INT_STATUS_CRM(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CRM_SHIFT)) & USDHC_INT_STATUS_CRM_MASK)

#define USDHC_INT_STATUS_CINT_MASK               (0x100U)
#define USDHC_INT_STATUS_CINT_SHIFT              (8U)
/*! CINT - Card interrupt
 *  0b0..No card interrupt
 *  0b1..Generate card interrupt
 */
#define USDHC_INT_STATUS_CINT(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CINT_SHIFT)) & USDHC_INT_STATUS_CINT_MASK)

#define USDHC_INT_STATUS_RTE_MASK                (0x1000U)
#define USDHC_INT_STATUS_RTE_SHIFT               (12U)
/*! RTE - Re-tuning event: (only for SD3.0 SDR104 mode)
 *  0b0..Re-tuning is not required.
 *  0b1..Re-tuning should be performed.
 */
#define USDHC_INT_STATUS_RTE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_RTE_SHIFT)) & USDHC_INT_STATUS_RTE_MASK)

#define USDHC_INT_STATUS_TP_MASK                 (0x4000U)
#define USDHC_INT_STATUS_TP_SHIFT                (14U)
/*! TP - Tuning pass:(only for SD3.0 SDR104 mode) */
#define USDHC_INT_STATUS_TP(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_TP_SHIFT)) & USDHC_INT_STATUS_TP_MASK)

#define USDHC_INT_STATUS_ERR_INT_STATUS_MASK     (0x8000U)
#define USDHC_INT_STATUS_ERR_INT_STATUS_SHIFT    (15U)
/*! ERR_INT_STATUS - Error Interrupt Status */
#define USDHC_INT_STATUS_ERR_INT_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_ERR_INT_STATUS_SHIFT)) & USDHC_INT_STATUS_ERR_INT_STATUS_MASK)

#define USDHC_INT_STATUS_CTOE_MASK               (0x10000U)
#define USDHC_INT_STATUS_CTOE_SHIFT              (16U)
/*! CTOE - Command timeout error
 *  0b0..No error
 *  0b1..Time out
 */
#define USDHC_INT_STATUS_CTOE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CTOE_SHIFT)) & USDHC_INT_STATUS_CTOE_MASK)

#define USDHC_INT_STATUS_CCE_MASK                (0x20000U)
#define USDHC_INT_STATUS_CCE_SHIFT               (17U)
/*! CCE - Command CRC error
 *  0b0..No error
 *  0b1..CRC error generated
 */
#define USDHC_INT_STATUS_CCE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CCE_SHIFT)) & USDHC_INT_STATUS_CCE_MASK)

#define USDHC_INT_STATUS_CEBE_MASK               (0x40000U)
#define USDHC_INT_STATUS_CEBE_SHIFT              (18U)
/*! CEBE - Command end bit error
 *  0b0..No error
 *  0b1..End bit error generated
 */
#define USDHC_INT_STATUS_CEBE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CEBE_SHIFT)) & USDHC_INT_STATUS_CEBE_MASK)

#define USDHC_INT_STATUS_CIE_MASK                (0x80000U)
#define USDHC_INT_STATUS_CIE_SHIFT               (19U)
/*! CIE - Command index error
 *  0b0..No error
 *  0b1..Error
 */
#define USDHC_INT_STATUS_CIE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CIE_SHIFT)) & USDHC_INT_STATUS_CIE_MASK)

#define USDHC_INT_STATUS_DTOE_MASK               (0x100000U)
#define USDHC_INT_STATUS_DTOE_SHIFT              (20U)
/*! DTOE - Data timeout error
 *  0b0..No error
 *  0b1..Time out
 */
#define USDHC_INT_STATUS_DTOE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DTOE_SHIFT)) & USDHC_INT_STATUS_DTOE_MASK)

#define USDHC_INT_STATUS_DCE_MASK                (0x200000U)
#define USDHC_INT_STATUS_DCE_SHIFT               (21U)
/*! DCE - Data CRC error
 *  0b0..No error
 *  0b1..Error
 */
#define USDHC_INT_STATUS_DCE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DCE_SHIFT)) & USDHC_INT_STATUS_DCE_MASK)

#define USDHC_INT_STATUS_DEBE_MASK               (0x400000U)
#define USDHC_INT_STATUS_DEBE_SHIFT              (22U)
/*! DEBE - Data end bit error
 *  0b0..No error
 *  0b1..Error
 */
#define USDHC_INT_STATUS_DEBE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DEBE_SHIFT)) & USDHC_INT_STATUS_DEBE_MASK)

#define USDHC_INT_STATUS_AC12E_MASK              (0x1000000U)
#define USDHC_INT_STATUS_AC12E_SHIFT             (24U)
/*! AC12E - Auto CMD12 error
 *  0b0..No error
 *  0b1..Error
 */
#define USDHC_INT_STATUS_AC12E(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_AC12E_SHIFT)) & USDHC_INT_STATUS_AC12E_MASK)

#define USDHC_INT_STATUS_TNE_MASK                (0x4000000U)
#define USDHC_INT_STATUS_TNE_SHIFT               (26U)
/*! TNE - Tuning error: (only for SD3.0 SDR104 mode) */
#define USDHC_INT_STATUS_TNE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_TNE_SHIFT)) & USDHC_INT_STATUS_TNE_MASK)

#define USDHC_INT_STATUS_DMAE_MASK               (0x10000000U)
#define USDHC_INT_STATUS_DMAE_SHIFT              (28U)
/*! DMAE - DMA error
 *  0b0..No error
 *  0b1..Error
 */
#define USDHC_INT_STATUS_DMAE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DMAE_SHIFT)) & USDHC_INT_STATUS_DMAE_MASK)
/*! @} */

/*! @name INT_STATUS_EN - Interrupt Status Enable */
/*! @{ */

#define USDHC_INT_STATUS_EN_CCSEN_MASK           (0x1U)
#define USDHC_INT_STATUS_EN_CCSEN_SHIFT          (0U)
/*! CCSEN - Command complete status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CCSEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CCSEN_SHIFT)) & USDHC_INT_STATUS_EN_CCSEN_MASK)

#define USDHC_INT_STATUS_EN_TCSEN_MASK           (0x2U)
#define USDHC_INT_STATUS_EN_TCSEN_SHIFT          (1U)
/*! TCSEN - Transfer complete status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_TCSEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_TCSEN_SHIFT)) & USDHC_INT_STATUS_EN_TCSEN_MASK)

#define USDHC_INT_STATUS_EN_BGESEN_MASK          (0x4U)
#define USDHC_INT_STATUS_EN_BGESEN_SHIFT         (2U)
/*! BGESEN - Block gap event status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_BGESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_BGESEN_SHIFT)) & USDHC_INT_STATUS_EN_BGESEN_MASK)

#define USDHC_INT_STATUS_EN_DINTSEN_MASK         (0x8U)
#define USDHC_INT_STATUS_EN_DINTSEN_SHIFT        (3U)
/*! DINTSEN - DMA interrupt status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_DINTSEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DINTSEN_SHIFT)) & USDHC_INT_STATUS_EN_DINTSEN_MASK)

#define USDHC_INT_STATUS_EN_BWRSEN_MASK          (0x10U)
#define USDHC_INT_STATUS_EN_BWRSEN_SHIFT         (4U)
/*! BWRSEN - Buffer write ready status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_BWRSEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_BWRSEN_SHIFT)) & USDHC_INT_STATUS_EN_BWRSEN_MASK)

#define USDHC_INT_STATUS_EN_BRRSEN_MASK          (0x20U)
#define USDHC_INT_STATUS_EN_BRRSEN_SHIFT         (5U)
/*! BRRSEN - Buffer read ready status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_BRRSEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_BRRSEN_SHIFT)) & USDHC_INT_STATUS_EN_BRRSEN_MASK)

#define USDHC_INT_STATUS_EN_CINSSEN_MASK         (0x40U)
#define USDHC_INT_STATUS_EN_CINSSEN_SHIFT        (6U)
/*! CINSSEN - Card insertion status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CINSSEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CINSSEN_SHIFT)) & USDHC_INT_STATUS_EN_CINSSEN_MASK)

#define USDHC_INT_STATUS_EN_CRMSEN_MASK          (0x80U)
#define USDHC_INT_STATUS_EN_CRMSEN_SHIFT         (7U)
/*! CRMSEN - Card removal status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CRMSEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CRMSEN_SHIFT)) & USDHC_INT_STATUS_EN_CRMSEN_MASK)

#define USDHC_INT_STATUS_EN_CINTSEN_MASK         (0x100U)
#define USDHC_INT_STATUS_EN_CINTSEN_SHIFT        (8U)
/*! CINTSEN - Card interrupt status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CINTSEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CINTSEN_SHIFT)) & USDHC_INT_STATUS_EN_CINTSEN_MASK)

#define USDHC_INT_STATUS_EN_RTESEN_MASK          (0x1000U)
#define USDHC_INT_STATUS_EN_RTESEN_SHIFT         (12U)
/*! RTESEN - Re-tuning event status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_RTESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_RTESEN_SHIFT)) & USDHC_INT_STATUS_EN_RTESEN_MASK)

#define USDHC_INT_STATUS_EN_TPSEN_MASK           (0x4000U)
#define USDHC_INT_STATUS_EN_TPSEN_SHIFT          (14U)
/*! TPSEN - Tuning pass status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_TPSEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_TPSEN_SHIFT)) & USDHC_INT_STATUS_EN_TPSEN_MASK)

#define USDHC_INT_STATUS_EN_CTOESEN_MASK         (0x10000U)
#define USDHC_INT_STATUS_EN_CTOESEN_SHIFT        (16U)
/*! CTOESEN - Command timeout error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CTOESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CTOESEN_SHIFT)) & USDHC_INT_STATUS_EN_CTOESEN_MASK)

#define USDHC_INT_STATUS_EN_CCESEN_MASK          (0x20000U)
#define USDHC_INT_STATUS_EN_CCESEN_SHIFT         (17U)
/*! CCESEN - Command CRC error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CCESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CCESEN_SHIFT)) & USDHC_INT_STATUS_EN_CCESEN_MASK)

#define USDHC_INT_STATUS_EN_CEBESEN_MASK         (0x40000U)
#define USDHC_INT_STATUS_EN_CEBESEN_SHIFT        (18U)
/*! CEBESEN - Command end bit error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CEBESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CEBESEN_SHIFT)) & USDHC_INT_STATUS_EN_CEBESEN_MASK)

#define USDHC_INT_STATUS_EN_CIESEN_MASK          (0x80000U)
#define USDHC_INT_STATUS_EN_CIESEN_SHIFT         (19U)
/*! CIESEN - Command index error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_CIESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CIESEN_SHIFT)) & USDHC_INT_STATUS_EN_CIESEN_MASK)

#define USDHC_INT_STATUS_EN_DTOESEN_MASK         (0x100000U)
#define USDHC_INT_STATUS_EN_DTOESEN_SHIFT        (20U)
/*! DTOESEN - Data timeout error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_DTOESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DTOESEN_SHIFT)) & USDHC_INT_STATUS_EN_DTOESEN_MASK)

#define USDHC_INT_STATUS_EN_DCESEN_MASK          (0x200000U)
#define USDHC_INT_STATUS_EN_DCESEN_SHIFT         (21U)
/*! DCESEN - Data CRC error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_DCESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DCESEN_SHIFT)) & USDHC_INT_STATUS_EN_DCESEN_MASK)

#define USDHC_INT_STATUS_EN_DEBESEN_MASK         (0x400000U)
#define USDHC_INT_STATUS_EN_DEBESEN_SHIFT        (22U)
/*! DEBESEN - Data end bit error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_DEBESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DEBESEN_SHIFT)) & USDHC_INT_STATUS_EN_DEBESEN_MASK)

#define USDHC_INT_STATUS_EN_AC12ESEN_MASK        (0x1000000U)
#define USDHC_INT_STATUS_EN_AC12ESEN_SHIFT       (24U)
/*! AC12ESEN - Auto CMD12 error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_AC12ESEN(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_AC12ESEN_SHIFT)) & USDHC_INT_STATUS_EN_AC12ESEN_MASK)

#define USDHC_INT_STATUS_EN_TNESEN_MASK          (0x4000000U)
#define USDHC_INT_STATUS_EN_TNESEN_SHIFT         (26U)
/*! TNESEN - Tuning error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_TNESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_TNESEN_SHIFT)) & USDHC_INT_STATUS_EN_TNESEN_MASK)

#define USDHC_INT_STATUS_EN_DMAESEN_MASK         (0x10000000U)
#define USDHC_INT_STATUS_EN_DMAESEN_SHIFT        (28U)
/*! DMAESEN - DMA error status enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_STATUS_EN_DMAESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DMAESEN_SHIFT)) & USDHC_INT_STATUS_EN_DMAESEN_MASK)
/*! @} */

/*! @name INT_SIGNAL_EN - Interrupt Signal Enable */
/*! @{ */

#define USDHC_INT_SIGNAL_EN_CCIEN_MASK           (0x1U)
#define USDHC_INT_SIGNAL_EN_CCIEN_SHIFT          (0U)
/*! CCIEN - Command complete interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CCIEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CCIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CCIEN_MASK)

#define USDHC_INT_SIGNAL_EN_TCIEN_MASK           (0x2U)
#define USDHC_INT_SIGNAL_EN_TCIEN_SHIFT          (1U)
/*! TCIEN - Transfer complete interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_TCIEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_TCIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_TCIEN_MASK)

#define USDHC_INT_SIGNAL_EN_BGEIEN_MASK          (0x4U)
#define USDHC_INT_SIGNAL_EN_BGEIEN_SHIFT         (2U)
/*! BGEIEN - Block gap event interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_BGEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_BGEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_BGEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DINTIEN_MASK         (0x8U)
#define USDHC_INT_SIGNAL_EN_DINTIEN_SHIFT        (3U)
/*! DINTIEN - DMA interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_DINTIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DINTIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DINTIEN_MASK)

#define USDHC_INT_SIGNAL_EN_BWRIEN_MASK          (0x10U)
#define USDHC_INT_SIGNAL_EN_BWRIEN_SHIFT         (4U)
/*! BWRIEN - Buffer write ready interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_BWRIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_BWRIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_BWRIEN_MASK)

#define USDHC_INT_SIGNAL_EN_BRRIEN_MASK          (0x20U)
#define USDHC_INT_SIGNAL_EN_BRRIEN_SHIFT         (5U)
/*! BRRIEN - Buffer read ready interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_BRRIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_BRRIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_BRRIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CINSIEN_MASK         (0x40U)
#define USDHC_INT_SIGNAL_EN_CINSIEN_SHIFT        (6U)
/*! CINSIEN - Card insertion interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CINSIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CINSIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CINSIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CRMIEN_MASK          (0x80U)
#define USDHC_INT_SIGNAL_EN_CRMIEN_SHIFT         (7U)
/*! CRMIEN - Card removal interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CRMIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CRMIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CRMIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CINTIEN_MASK         (0x100U)
#define USDHC_INT_SIGNAL_EN_CINTIEN_SHIFT        (8U)
/*! CINTIEN - Card interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CINTIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CINTIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CINTIEN_MASK)

#define USDHC_INT_SIGNAL_EN_RTEIEN_MASK          (0x1000U)
#define USDHC_INT_SIGNAL_EN_RTEIEN_SHIFT         (12U)
/*! RTEIEN - Re-tuning event interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_RTEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_RTEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_RTEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_TPIEN_MASK           (0x4000U)
#define USDHC_INT_SIGNAL_EN_TPIEN_SHIFT          (14U)
/*! TPIEN - Tuning Pass interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_TPIEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_TPIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_TPIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CTOEIEN_MASK         (0x10000U)
#define USDHC_INT_SIGNAL_EN_CTOEIEN_SHIFT        (16U)
/*! CTOEIEN - Command timeout error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CTOEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CTOEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CTOEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CCEIEN_MASK          (0x20000U)
#define USDHC_INT_SIGNAL_EN_CCEIEN_SHIFT         (17U)
/*! CCEIEN - Command CRC error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CCEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CCEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CCEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CEBEIEN_MASK         (0x40000U)
#define USDHC_INT_SIGNAL_EN_CEBEIEN_SHIFT        (18U)
/*! CEBEIEN - Command end bit error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CEBEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CEBEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CEBEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CIEIEN_MASK          (0x80000U)
#define USDHC_INT_SIGNAL_EN_CIEIEN_SHIFT         (19U)
/*! CIEIEN - Command index error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_CIEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CIEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CIEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DTOEIEN_MASK         (0x100000U)
#define USDHC_INT_SIGNAL_EN_DTOEIEN_SHIFT        (20U)
/*! DTOEIEN - Data timeout error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_DTOEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DTOEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DTOEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DCEIEN_MASK          (0x200000U)
#define USDHC_INT_SIGNAL_EN_DCEIEN_SHIFT         (21U)
/*! DCEIEN - Data CRC error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_DCEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DCEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DCEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DEBEIEN_MASK         (0x400000U)
#define USDHC_INT_SIGNAL_EN_DEBEIEN_SHIFT        (22U)
/*! DEBEIEN - Data end bit error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_DEBEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DEBEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DEBEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_AC12EIEN_MASK        (0x1000000U)
#define USDHC_INT_SIGNAL_EN_AC12EIEN_SHIFT       (24U)
/*! AC12EIEN - Auto CMD12 error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_AC12EIEN(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_AC12EIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_AC12EIEN_MASK)

#define USDHC_INT_SIGNAL_EN_TNEIEN_MASK          (0x4000000U)
#define USDHC_INT_SIGNAL_EN_TNEIEN_SHIFT         (26U)
/*! TNEIEN - Tuning error interrupt enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define USDHC_INT_SIGNAL_EN_TNEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_TNEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_TNEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DMAEIEN_MASK         (0x10000000U)
#define USDHC_INT_SIGNAL_EN_DMAEIEN_SHIFT        (28U)
/*! DMAEIEN - DMA error interrupt enable
 *  0b0..Masked
 *  0b1..Enable
 */
#define USDHC_INT_SIGNAL_EN_DMAEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DMAEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DMAEIEN_MASK)
/*! @} */

/*! @name AUTOCMD12_ERR_STATUS - Auto CMD12 Error Status */
/*! @{ */

#define USDHC_AUTOCMD12_ERR_STATUS_AC12NE_MASK   (0x1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12NE_SHIFT  (0U)
/*! AC12NE - Auto CMD12 not executed
 *  0b0..Executed
 *  0b1..Not executed
 */
#define USDHC_AUTOCMD12_ERR_STATUS_AC12NE(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12NE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12NE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_MASK  (0x2U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_SHIFT (1U)
/*! AC12TOE - Auto CMD12 / 23 timeout error
 *  0b0..No error
 *  0b1..Time out
 */
#define USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12CE_MASK   (0x4U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12CE_SHIFT  (2U)
/*! AC12CE - Auto CMD12 / 23 CRC error
 *  0b0..No CRC error
 *  0b1..CRC error met in Auto CMD12/23 response
 */
#define USDHC_AUTOCMD12_ERR_STATUS_AC12CE(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12CE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12CE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_MASK  (0x8U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_SHIFT (3U)
/*! AC12EBE - Auto CMD12 / 23 end bit error
 *  0b0..No error
 *  0b1..End bit error generated
 */
#define USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12IE_MASK   (0x10U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12IE_SHIFT  (4U)
/*! AC12IE - Auto CMD12 / 23 index error
 *  0b0..No error
 *  0b1..Error, the CMD index in response is not CMD12/23
 */
#define USDHC_AUTOCMD12_ERR_STATUS_AC12IE(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12IE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12IE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_MASK (0x80U)
#define USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_SHIFT (7U)
/*! CNIBAC12E - Command not issued by Auto CMD12 error
 *  0b0..No error
 *  0b1..Not issued
 */
#define USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(x)  (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_MASK (0x400000U)
#define USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_SHIFT (22U)
/*! EXECUTE_TUNING - Execute tuning
 *  0b0..Tuning procedure is aborted
 *  0b1..Start tuning procedure
 */
#define USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING(x) (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_MASK (0x800000U)
#define USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_SHIFT (23U)
/*! SMP_CLK_SEL - Sample clock select
 *  0b0..Fixed clock is used to sample data
 *  0b1..Tuned clock is used to sample data
 */
#define USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_MASK)
/*! @} */

/*! @name HOST_CTRL_CAP - Host Controller Capabilities */
/*! @{ */

#define USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_MASK   (0x1U)
#define USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_SHIFT  (0U)
/*! SDR50_SUPPORT - SDR50 support */
#define USDHC_HOST_CTRL_CAP_SDR50_SUPPORT(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_SHIFT)) & USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_MASK)

#define USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_MASK  (0x2U)
#define USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_SHIFT (1U)
/*! SDR104_SUPPORT - SDR104 support */
#define USDHC_HOST_CTRL_CAP_SDR104_SUPPORT(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_SHIFT)) & USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_MASK)

#define USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_MASK   (0x4U)
#define USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_SHIFT  (2U)
/*! DDR50_SUPPORT - DDR50 support */
#define USDHC_HOST_CTRL_CAP_DDR50_SUPPORT(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_SHIFT)) & USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_MASK)

#define USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_MASK (0x2000U)
#define USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_SHIFT (13U)
/*! USE_TUNING_SDR50 - Use Tuning for SDR50
 *  0b0..SDR50 does not support tuning
 *  0b1..SDR50 supports tuning
 */
#define USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50(x)  (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_SHIFT)) & USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_MASK)

#define USDHC_HOST_CTRL_CAP_MBL_MASK             (0x70000U)
#define USDHC_HOST_CTRL_CAP_MBL_SHIFT            (16U)
/*! MBL - Max block length
 *  0b000..512 bytes
 *  0b001..1024 bytes
 *  0b010..2048 bytes
 *  0b011..4096 bytes
 */
#define USDHC_HOST_CTRL_CAP_MBL(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_MBL_SHIFT)) & USDHC_HOST_CTRL_CAP_MBL_MASK)

#define USDHC_HOST_CTRL_CAP_ADMAS_MASK           (0x100000U)
#define USDHC_HOST_CTRL_CAP_ADMAS_SHIFT          (20U)
/*! ADMAS - ADMA support
 *  0b0..Advanced DMA not supported
 *  0b1..Advanced DMA supported
 */
#define USDHC_HOST_CTRL_CAP_ADMAS(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_ADMAS_SHIFT)) & USDHC_HOST_CTRL_CAP_ADMAS_MASK)

#define USDHC_HOST_CTRL_CAP_HSS_MASK             (0x200000U)
#define USDHC_HOST_CTRL_CAP_HSS_SHIFT            (21U)
/*! HSS - High speed support
 *  0b0..High speed not supported
 *  0b1..High speed supported
 */
#define USDHC_HOST_CTRL_CAP_HSS(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_HSS_SHIFT)) & USDHC_HOST_CTRL_CAP_HSS_MASK)

#define USDHC_HOST_CTRL_CAP_DMAS_MASK            (0x400000U)
#define USDHC_HOST_CTRL_CAP_DMAS_SHIFT           (22U)
/*! DMAS - DMA support
 *  0b0..DMA not supported
 *  0b1..DMA supported
 */
#define USDHC_HOST_CTRL_CAP_DMAS(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_DMAS_SHIFT)) & USDHC_HOST_CTRL_CAP_DMAS_MASK)

#define USDHC_HOST_CTRL_CAP_SRS_MASK             (0x800000U)
#define USDHC_HOST_CTRL_CAP_SRS_SHIFT            (23U)
/*! SRS - Suspend / resume support
 *  0b0..Not supported
 *  0b1..Supported
 */
#define USDHC_HOST_CTRL_CAP_SRS(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_SRS_SHIFT)) & USDHC_HOST_CTRL_CAP_SRS_MASK)

#define USDHC_HOST_CTRL_CAP_VS33_MASK            (0x1000000U)
#define USDHC_HOST_CTRL_CAP_VS33_SHIFT           (24U)
/*! VS33 - Voltage support 3.3 V
 *  0b0..3.3 V not supported
 *  0b1..3.3 V supported
 */
#define USDHC_HOST_CTRL_CAP_VS33(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_VS33_SHIFT)) & USDHC_HOST_CTRL_CAP_VS33_MASK)

#define USDHC_HOST_CTRL_CAP_VS30_MASK            (0x2000000U)
#define USDHC_HOST_CTRL_CAP_VS30_SHIFT           (25U)
/*! VS30 - Voltage support 3.0 V
 *  0b0..3.0 V not supported
 *  0b1..3.0 V supported
 */
#define USDHC_HOST_CTRL_CAP_VS30(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_VS30_SHIFT)) & USDHC_HOST_CTRL_CAP_VS30_MASK)

#define USDHC_HOST_CTRL_CAP_VS18_MASK            (0x4000000U)
#define USDHC_HOST_CTRL_CAP_VS18_SHIFT           (26U)
/*! VS18 - Voltage support 1.8 V
 *  0b0..1.8 V not supported
 *  0b1..1.8 V supported
 */
#define USDHC_HOST_CTRL_CAP_VS18(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_VS18_SHIFT)) & USDHC_HOST_CTRL_CAP_VS18_MASK)
/*! @} */

/*! @name WTMK_LVL - Watermark Level */
/*! @{ */

#define USDHC_WTMK_LVL_RD_WML_MASK               (0xFFU)
#define USDHC_WTMK_LVL_RD_WML_SHIFT              (0U)
/*! RD_WML - Read watermark level */
#define USDHC_WTMK_LVL_RD_WML(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_WTMK_LVL_RD_WML_SHIFT)) & USDHC_WTMK_LVL_RD_WML_MASK)

#define USDHC_WTMK_LVL_RD_BRST_LEN_MASK          (0x1F00U)
#define USDHC_WTMK_LVL_RD_BRST_LEN_SHIFT         (8U)
/*! RD_BRST_LEN - Read burst length due to system restriction, the actual burst length might not exceed 16 */
#define USDHC_WTMK_LVL_RD_BRST_LEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_WTMK_LVL_RD_BRST_LEN_SHIFT)) & USDHC_WTMK_LVL_RD_BRST_LEN_MASK)

#define USDHC_WTMK_LVL_WR_WML_MASK               (0xFF0000U)
#define USDHC_WTMK_LVL_WR_WML_SHIFT              (16U)
/*! WR_WML - Write watermark level */
#define USDHC_WTMK_LVL_WR_WML(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_WTMK_LVL_WR_WML_SHIFT)) & USDHC_WTMK_LVL_WR_WML_MASK)

#define USDHC_WTMK_LVL_WR_BRST_LEN_MASK          (0x1F000000U)
#define USDHC_WTMK_LVL_WR_BRST_LEN_SHIFT         (24U)
/*! WR_BRST_LEN - Write burst length due to system restriction, the actual burst length might not exceed 16 */
#define USDHC_WTMK_LVL_WR_BRST_LEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_WTMK_LVL_WR_BRST_LEN_SHIFT)) & USDHC_WTMK_LVL_WR_BRST_LEN_MASK)
/*! @} */

/*! @name MIX_CTRL - Mixer Control */
/*! @{ */

#define USDHC_MIX_CTRL_DMAEN_MASK                (0x1U)
#define USDHC_MIX_CTRL_DMAEN_SHIFT               (0U)
/*! DMAEN - DMA enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_MIX_CTRL_DMAEN(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_DMAEN_SHIFT)) & USDHC_MIX_CTRL_DMAEN_MASK)

#define USDHC_MIX_CTRL_BCEN_MASK                 (0x2U)
#define USDHC_MIX_CTRL_BCEN_SHIFT                (1U)
/*! BCEN - Block count enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_MIX_CTRL_BCEN(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_BCEN_SHIFT)) & USDHC_MIX_CTRL_BCEN_MASK)

#define USDHC_MIX_CTRL_AC12EN_MASK               (0x4U)
#define USDHC_MIX_CTRL_AC12EN_SHIFT              (2U)
/*! AC12EN - Auto CMD12 enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USDHC_MIX_CTRL_AC12EN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_AC12EN_SHIFT)) & USDHC_MIX_CTRL_AC12EN_MASK)

#define USDHC_MIX_CTRL_DDR_EN_MASK               (0x8U)
#define USDHC_MIX_CTRL_DDR_EN_SHIFT              (3U)
/*! DDR_EN - Dual data rate mode selection */
#define USDHC_MIX_CTRL_DDR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_DDR_EN_SHIFT)) & USDHC_MIX_CTRL_DDR_EN_MASK)

#define USDHC_MIX_CTRL_DTDSEL_MASK               (0x10U)
#define USDHC_MIX_CTRL_DTDSEL_SHIFT              (4U)
/*! DTDSEL - Data transfer direction select
 *  0b0..Write (Host to card)
 *  0b1..Read (Card to host)
 */
#define USDHC_MIX_CTRL_DTDSEL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_DTDSEL_SHIFT)) & USDHC_MIX_CTRL_DTDSEL_MASK)

#define USDHC_MIX_CTRL_MSBSEL_MASK               (0x20U)
#define USDHC_MIX_CTRL_MSBSEL_SHIFT              (5U)
/*! MSBSEL - Multi / Single block select
 *  0b0..Single block
 *  0b1..Multiple blocks
 */
#define USDHC_MIX_CTRL_MSBSEL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_MSBSEL_SHIFT)) & USDHC_MIX_CTRL_MSBSEL_MASK)

#define USDHC_MIX_CTRL_NIBBLE_POS_MASK           (0x40U)
#define USDHC_MIX_CTRL_NIBBLE_POS_SHIFT          (6U)
/*! NIBBLE_POS - Nibble position indication */
#define USDHC_MIX_CTRL_NIBBLE_POS(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_NIBBLE_POS_SHIFT)) & USDHC_MIX_CTRL_NIBBLE_POS_MASK)

#define USDHC_MIX_CTRL_AC23EN_MASK               (0x80U)
#define USDHC_MIX_CTRL_AC23EN_SHIFT              (7U)
/*! AC23EN - Auto CMD23 enable */
#define USDHC_MIX_CTRL_AC23EN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_AC23EN_SHIFT)) & USDHC_MIX_CTRL_AC23EN_MASK)

#define USDHC_MIX_CTRL_EXE_TUNE_MASK             (0x400000U)
#define USDHC_MIX_CTRL_EXE_TUNE_SHIFT            (22U)
/*! EXE_TUNE - Execute tuning: (Only used for SD3.0, SDR104 mode)
 *  0b0..Not tuned or tuning completed
 *  0b1..Execute tuning
 */
#define USDHC_MIX_CTRL_EXE_TUNE(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_EXE_TUNE_SHIFT)) & USDHC_MIX_CTRL_EXE_TUNE_MASK)

#define USDHC_MIX_CTRL_SMP_CLK_SEL_MASK          (0x800000U)
#define USDHC_MIX_CTRL_SMP_CLK_SEL_SHIFT         (23U)
/*! SMP_CLK_SEL - Clock selection
 *  0b0..Fixed clock is used to sample data / cmd
 *  0b1..Tuned clock is used to sample data / cmd
 */
#define USDHC_MIX_CTRL_SMP_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_SMP_CLK_SEL_SHIFT)) & USDHC_MIX_CTRL_SMP_CLK_SEL_MASK)

#define USDHC_MIX_CTRL_AUTO_TUNE_EN_MASK         (0x1000000U)
#define USDHC_MIX_CTRL_AUTO_TUNE_EN_SHIFT        (24U)
/*! AUTO_TUNE_EN - Auto tuning enable (Only used for SD3.0, SDR104 mode)
 *  0b0..Disable auto tuning
 *  0b1..Enable auto tuning
 */
#define USDHC_MIX_CTRL_AUTO_TUNE_EN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_AUTO_TUNE_EN_SHIFT)) & USDHC_MIX_CTRL_AUTO_TUNE_EN_MASK)

#define USDHC_MIX_CTRL_FBCLK_SEL_MASK            (0x2000000U)
#define USDHC_MIX_CTRL_FBCLK_SEL_SHIFT           (25U)
/*! FBCLK_SEL - Feedback clock source selection (Only used for SD3.0, SDR104 mode)
 *  0b0..Feedback clock comes from the loopback CLK
 *  0b1..Feedback clock comes from the ipp_card_clk_out
 */
#define USDHC_MIX_CTRL_FBCLK_SEL(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_FBCLK_SEL_SHIFT)) & USDHC_MIX_CTRL_FBCLK_SEL_MASK)
/*! @} */

/*! @name FORCE_EVENT - Force Event */
/*! @{ */

#define USDHC_FORCE_EVENT_FEVTAC12NE_MASK        (0x1U)
#define USDHC_FORCE_EVENT_FEVTAC12NE_SHIFT       (0U)
/*! FEVTAC12NE - Force event auto command 12 not executed */
#define USDHC_FORCE_EVENT_FEVTAC12NE(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12NE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12NE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12TOE_MASK       (0x2U)
#define USDHC_FORCE_EVENT_FEVTAC12TOE_SHIFT      (1U)
/*! FEVTAC12TOE - Force event auto command 12 time out error */
#define USDHC_FORCE_EVENT_FEVTAC12TOE(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12TOE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12TOE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12CE_MASK        (0x4U)
#define USDHC_FORCE_EVENT_FEVTAC12CE_SHIFT       (2U)
/*! FEVTAC12CE - Force event auto command 12 CRC error */
#define USDHC_FORCE_EVENT_FEVTAC12CE(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12CE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12CE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12EBE_MASK       (0x8U)
#define USDHC_FORCE_EVENT_FEVTAC12EBE_SHIFT      (3U)
/*! FEVTAC12EBE - Force event Auto Command 12 end bit error */
#define USDHC_FORCE_EVENT_FEVTAC12EBE(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12EBE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12EBE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12IE_MASK        (0x10U)
#define USDHC_FORCE_EVENT_FEVTAC12IE_SHIFT       (4U)
/*! FEVTAC12IE - Force event Auto Command 12 index error */
#define USDHC_FORCE_EVENT_FEVTAC12IE(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12IE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12IE_MASK)

#define USDHC_FORCE_EVENT_FEVTCNIBAC12E_MASK     (0x80U)
#define USDHC_FORCE_EVENT_FEVTCNIBAC12E_SHIFT    (7U)
/*! FEVTCNIBAC12E - Force event command not executed by Auto Command 12 error */
#define USDHC_FORCE_EVENT_FEVTCNIBAC12E(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCNIBAC12E_SHIFT)) & USDHC_FORCE_EVENT_FEVTCNIBAC12E_MASK)

#define USDHC_FORCE_EVENT_FEVTCTOE_MASK          (0x10000U)
#define USDHC_FORCE_EVENT_FEVTCTOE_SHIFT         (16U)
/*! FEVTCTOE - Force event command time out error */
#define USDHC_FORCE_EVENT_FEVTCTOE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCTOE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCTOE_MASK)

#define USDHC_FORCE_EVENT_FEVTCCE_MASK           (0x20000U)
#define USDHC_FORCE_EVENT_FEVTCCE_SHIFT          (17U)
/*! FEVTCCE - Force event command CRC error */
#define USDHC_FORCE_EVENT_FEVTCCE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCCE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCCE_MASK)

#define USDHC_FORCE_EVENT_FEVTCEBE_MASK          (0x40000U)
#define USDHC_FORCE_EVENT_FEVTCEBE_SHIFT         (18U)
/*! FEVTCEBE - Force event command end bit error */
#define USDHC_FORCE_EVENT_FEVTCEBE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCEBE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCEBE_MASK)

#define USDHC_FORCE_EVENT_FEVTCIE_MASK           (0x80000U)
#define USDHC_FORCE_EVENT_FEVTCIE_SHIFT          (19U)
/*! FEVTCIE - Force event command index error */
#define USDHC_FORCE_EVENT_FEVTCIE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCIE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCIE_MASK)

#define USDHC_FORCE_EVENT_FEVTDTOE_MASK          (0x100000U)
#define USDHC_FORCE_EVENT_FEVTDTOE_SHIFT         (20U)
/*! FEVTDTOE - Force event data time out error */
#define USDHC_FORCE_EVENT_FEVTDTOE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDTOE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDTOE_MASK)

#define USDHC_FORCE_EVENT_FEVTDCE_MASK           (0x200000U)
#define USDHC_FORCE_EVENT_FEVTDCE_SHIFT          (21U)
/*! FEVTDCE - Force event data CRC error */
#define USDHC_FORCE_EVENT_FEVTDCE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDCE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDCE_MASK)

#define USDHC_FORCE_EVENT_FEVTDEBE_MASK          (0x400000U)
#define USDHC_FORCE_EVENT_FEVTDEBE_SHIFT         (22U)
/*! FEVTDEBE - Force event data end bit error */
#define USDHC_FORCE_EVENT_FEVTDEBE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDEBE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDEBE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12E_MASK         (0x1000000U)
#define USDHC_FORCE_EVENT_FEVTAC12E_SHIFT        (24U)
/*! FEVTAC12E - Force event Auto Command 12 error */
#define USDHC_FORCE_EVENT_FEVTAC12E(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12E_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12E_MASK)

#define USDHC_FORCE_EVENT_FEVTTNE_MASK           (0x4000000U)
#define USDHC_FORCE_EVENT_FEVTTNE_SHIFT          (26U)
/*! FEVTTNE - Force tuning error */
#define USDHC_FORCE_EVENT_FEVTTNE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTTNE_SHIFT)) & USDHC_FORCE_EVENT_FEVTTNE_MASK)

#define USDHC_FORCE_EVENT_FEVTDMAE_MASK          (0x10000000U)
#define USDHC_FORCE_EVENT_FEVTDMAE_SHIFT         (28U)
/*! FEVTDMAE - Force event DMA error */
#define USDHC_FORCE_EVENT_FEVTDMAE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDMAE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDMAE_MASK)

#define USDHC_FORCE_EVENT_FEVTCINT_MASK          (0x80000000U)
#define USDHC_FORCE_EVENT_FEVTCINT_SHIFT         (31U)
/*! FEVTCINT - Force event card interrupt */
#define USDHC_FORCE_EVENT_FEVTCINT(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCINT_SHIFT)) & USDHC_FORCE_EVENT_FEVTCINT_MASK)
/*! @} */

/*! @name ADMA_ERR_STATUS - ADMA Error Status */
/*! @{ */

#define USDHC_ADMA_ERR_STATUS_ADMAES_MASK        (0x3U)
#define USDHC_ADMA_ERR_STATUS_ADMAES_SHIFT       (0U)
/*! ADMAES - ADMA error state (when ADMA error is occurred) */
#define USDHC_ADMA_ERR_STATUS_ADMAES(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_ERR_STATUS_ADMAES_SHIFT)) & USDHC_ADMA_ERR_STATUS_ADMAES_MASK)

#define USDHC_ADMA_ERR_STATUS_ADMALME_MASK       (0x4U)
#define USDHC_ADMA_ERR_STATUS_ADMALME_SHIFT      (2U)
/*! ADMALME - ADMA length mismatch error
 *  0b0..No error
 *  0b1..Error
 */
#define USDHC_ADMA_ERR_STATUS_ADMALME(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_ERR_STATUS_ADMALME_SHIFT)) & USDHC_ADMA_ERR_STATUS_ADMALME_MASK)

#define USDHC_ADMA_ERR_STATUS_ADMADCE_MASK       (0x8U)
#define USDHC_ADMA_ERR_STATUS_ADMADCE_SHIFT      (3U)
/*! ADMADCE - ADMA descriptor error
 *  0b0..No error
 *  0b1..Error
 */
#define USDHC_ADMA_ERR_STATUS_ADMADCE(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_ERR_STATUS_ADMADCE_SHIFT)) & USDHC_ADMA_ERR_STATUS_ADMADCE_MASK)
/*! @} */

/*! @name ADMA_SYS_ADDR - ADMA System Address */
/*! @{ */

#define USDHC_ADMA_SYS_ADDR_ADS_ADDR_MASK        (0xFFFFFFFCU)
#define USDHC_ADMA_SYS_ADDR_ADS_ADDR_SHIFT       (2U)
/*! ADS_ADDR - ADMA system address */
#define USDHC_ADMA_SYS_ADDR_ADS_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_SYS_ADDR_ADS_ADDR_SHIFT)) & USDHC_ADMA_SYS_ADDR_ADS_ADDR_MASK)
/*! @} */

/*! @name DLL_CTRL - DLL (Delay Line) Control */
/*! @{ */

#define USDHC_DLL_CTRL_DLL_CTRL_ENABLE_MASK      (0x1U)
#define USDHC_DLL_CTRL_DLL_CTRL_ENABLE_SHIFT     (0U)
/*! DLL_CTRL_ENABLE - DLL and delay chain */
#define USDHC_DLL_CTRL_DLL_CTRL_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_ENABLE_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_ENABLE_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_RESET_MASK       (0x2U)
#define USDHC_DLL_CTRL_DLL_CTRL_RESET_SHIFT      (1U)
/*! DLL_CTRL_RESET - DLL reset */
#define USDHC_DLL_CTRL_DLL_CTRL_RESET(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_RESET_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_RESET_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_MASK (0x4U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_SHIFT (2U)
/*! DLL_CTRL_SLV_FORCE_UPD - DLL slave delay line */
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_MASK (0x78U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_SHIFT (3U)
/*! DLL_CTRL_SLV_DLY_TARGET0 - DLL slave delay target0 */
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_MASK (0x80U)
#define USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_SHIFT (7U)
/*! DLL_CTRL_GATE_UPDATE - DLL gate update */
#define USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(x)   (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_MASK (0x100U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_SHIFT (8U)
/*! DLL_CTRL_SLV_OVERRIDE - DLL slave override */
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(x)  (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_MASK (0xFE00U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT (9U)
/*! DLL_CTRL_SLV_OVERRIDE_VAL - DLL slave override val */
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_MASK (0x70000U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_SHIFT (16U)
/*! DLL_CTRL_SLV_DLY_TARGET1 - DLL slave delay target1 */
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_MASK (0xFF00000U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_SHIFT (20U)
/*! DLL_CTRL_SLV_UPDATE_INT - Slave delay line update interval */
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_MASK (0xF0000000U)
#define USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_SHIFT (28U)
/*! DLL_CTRL_REF_UPDATE_INT - DLL control loop update interval */
#define USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_MASK)
/*! @} */

/*! @name DLL_STATUS - DLL Status */
/*! @{ */

#define USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_MASK   (0x1U)
#define USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_SHIFT  (0U)
/*! DLL_STS_SLV_LOCK - Slave delay-line lock status */
#define USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_MASK)

#define USDHC_DLL_STATUS_DLL_STS_REF_LOCK_MASK   (0x2U)
#define USDHC_DLL_STATUS_DLL_STS_REF_LOCK_SHIFT  (1U)
/*! DLL_STS_REF_LOCK - Reference DLL lock status */
#define USDHC_DLL_STATUS_DLL_STS_REF_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_REF_LOCK_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_REF_LOCK_MASK)

#define USDHC_DLL_STATUS_DLL_STS_SLV_SEL_MASK    (0x1FCU)
#define USDHC_DLL_STATUS_DLL_STS_SLV_SEL_SHIFT   (2U)
/*! DLL_STS_SLV_SEL - Slave delay line select status */
#define USDHC_DLL_STATUS_DLL_STS_SLV_SEL(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_SLV_SEL_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_SLV_SEL_MASK)

#define USDHC_DLL_STATUS_DLL_STS_REF_SEL_MASK    (0xFE00U)
#define USDHC_DLL_STATUS_DLL_STS_REF_SEL_SHIFT   (9U)
/*! DLL_STS_REF_SEL - Reference delay line select taps */
#define USDHC_DLL_STATUS_DLL_STS_REF_SEL(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_REF_SEL_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_REF_SEL_MASK)
/*! @} */

/*! @name CLK_TUNE_CTRL_STATUS - CLK Tuning Control and Status */
/*! @{ */

#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_MASK (0xFU)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_SHIFT (0U)
/*! DLY_CELL_SET_POST - Delay cells on the feedback clock between CLK_OUT and CLK_POST */
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_MASK (0xF0U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_SHIFT (4U)
/*! DLY_CELL_SET_OUT - Delay cells on the feedback clock between CLK_PRE and CLK_OUT */
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_MASK (0x7F00U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_SHIFT (8U)
/*! DLY_CELL_SET_PRE - delay cells on the feedback clock between the feedback clock and CLK_PRE */
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_MASK  (0x8000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_SHIFT (15U)
/*! NXT_ERR - NXT error */
#define USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_MASK (0xF0000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_SHIFT (16U)
/*! TAP_SEL_POST - Delay cells added on the feedback clock between CLK_OUT and CLK_POST */
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_MASK (0xF00000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_SHIFT (20U)
/*! TAP_SEL_OUT - Delay cells added on the feedback clock between CLK_PRE and CLK_OUT */
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_MASK (0x7F000000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_SHIFT (24U)
/*! TAP_SEL_PRE - TAP_SEL_PRE */
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_MASK  (0x80000000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_SHIFT (31U)
/*! PRE_ERR - PRE error */
#define USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_MASK)
/*! @} */

/*! @name VEND_SPEC - Vendor Specific Register */
/*! @{ */

#define USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_MASK  (0x8U)
#define USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_SHIFT (3U)
/*! AC12_WR_CHKBUSY_EN - Check busy enable
 *  0b0..Do not check busy after auto CMD12 for write data packet
 *  0b1..Check busy after auto CMD12 for write data packet
 */
#define USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_SHIFT)) & USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_MASK)

#define USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK        (0x100U)
#define USDHC_VEND_SPEC_FRC_SDCLK_ON_SHIFT       (8U)
/*! FRC_SDCLK_ON - Force CLK
 *  0b0..CLK active or inactive is fully controlled by the hardware.
 *  0b1..Force CLK active
 */
#define USDHC_VEND_SPEC_FRC_SDCLK_ON(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_FRC_SDCLK_ON_SHIFT)) & USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK)

#define USDHC_VEND_SPEC_CRC_CHK_DIS_MASK         (0x8000U)
#define USDHC_VEND_SPEC_CRC_CHK_DIS_SHIFT        (15U)
/*! CRC_CHK_DIS - CRC Check Disable
 *  0b0..Check CRC16 for every read data packet and check CRC fields for every write data packet
 *  0b1..Ignore CRC16 check for every read data packet and ignore CRC fields check for every write data packet
 */
#define USDHC_VEND_SPEC_CRC_CHK_DIS(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_CRC_CHK_DIS_SHIFT)) & USDHC_VEND_SPEC_CRC_CHK_DIS_MASK)

#define USDHC_VEND_SPEC_CMD_BYTE_EN_MASK         (0x80000000U)
#define USDHC_VEND_SPEC_CMD_BYTE_EN_SHIFT        (31U)
/*! CMD_BYTE_EN - Register byte access for CMD_XFR_TYP
 *  0b0..Disable. MIX_CTRL[7:0] is read/write and CMD_XFR_TYP[7:0] is read-only.
 *  0b1..Enable. MIX_CTRL[7:0] is read-only and CMD_XFR_TYP[7:0] is read/write.
 */
#define USDHC_VEND_SPEC_CMD_BYTE_EN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_CMD_BYTE_EN_SHIFT)) & USDHC_VEND_SPEC_CMD_BYTE_EN_MASK)
/*! @} */

/*! @name MMC_BOOT - eMMC Boot */
/*! @{ */

#define USDHC_MMC_BOOT_DTOCV_ACK_MASK            (0xFU)
#define USDHC_MMC_BOOT_DTOCV_ACK_SHIFT           (0U)
/*! DTOCV_ACK - Boot ACK time out
 *  0b0000..SDCLK x 2^14
 *  0b0001..SDCLK x 2^15
 *  0b0010..SDCLK x 2^16
 *  0b0011..SDCLK x 2^17
 *  0b0100..SDCLK x 2^18
 *  0b0101..SDCLK x 2^19
 *  0b0110..SDCLK x 2^20
 *  0b0111..SDCLK x 2^21
 *  0b1110..SDCLK x 2^28
 *  0b1111..SDCLK x 2^29
 */
#define USDHC_MMC_BOOT_DTOCV_ACK(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_DTOCV_ACK_SHIFT)) & USDHC_MMC_BOOT_DTOCV_ACK_MASK)

#define USDHC_MMC_BOOT_BOOT_ACK_MASK             (0x10U)
#define USDHC_MMC_BOOT_BOOT_ACK_SHIFT            (4U)
/*! BOOT_ACK - BOOT ACK
 *  0b0..No ack
 *  0b1..Ack
 */
#define USDHC_MMC_BOOT_BOOT_ACK(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_ACK_SHIFT)) & USDHC_MMC_BOOT_BOOT_ACK_MASK)

#define USDHC_MMC_BOOT_BOOT_MODE_MASK            (0x20U)
#define USDHC_MMC_BOOT_BOOT_MODE_SHIFT           (5U)
/*! BOOT_MODE - Boot mode
 *  0b0..Normal boot
 *  0b1..Alternative boot
 */
#define USDHC_MMC_BOOT_BOOT_MODE(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_MODE_SHIFT)) & USDHC_MMC_BOOT_BOOT_MODE_MASK)

#define USDHC_MMC_BOOT_BOOT_EN_MASK              (0x40U)
#define USDHC_MMC_BOOT_BOOT_EN_SHIFT             (6U)
/*! BOOT_EN - Boot enable
 *  0b0..Fast boot disable
 *  0b1..Fast boot enable
 */
#define USDHC_MMC_BOOT_BOOT_EN(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_EN_SHIFT)) & USDHC_MMC_BOOT_BOOT_EN_MASK)

#define USDHC_MMC_BOOT_AUTO_SABG_EN_MASK         (0x80U)
#define USDHC_MMC_BOOT_AUTO_SABG_EN_SHIFT        (7U)
/*! AUTO_SABG_EN - Auto stop at block gap */
#define USDHC_MMC_BOOT_AUTO_SABG_EN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_AUTO_SABG_EN_SHIFT)) & USDHC_MMC_BOOT_AUTO_SABG_EN_MASK)

#define USDHC_MMC_BOOT_DISABLE_TIME_OUT_MASK     (0x100U)
#define USDHC_MMC_BOOT_DISABLE_TIME_OUT_SHIFT    (8U)
/*! DISABLE_TIME_OUT - Time out
 *  0b0..Enable time out
 *  0b1..Disable time out
 */
#define USDHC_MMC_BOOT_DISABLE_TIME_OUT(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_DISABLE_TIME_OUT_SHIFT)) & USDHC_MMC_BOOT_DISABLE_TIME_OUT_MASK)

#define USDHC_MMC_BOOT_BOOT_BLK_CNT_MASK         (0xFFFF0000U)
#define USDHC_MMC_BOOT_BOOT_BLK_CNT_SHIFT        (16U)
/*! BOOT_BLK_CNT - Stop At Block Gap value of automatic mode */
#define USDHC_MMC_BOOT_BOOT_BLK_CNT(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_BLK_CNT_SHIFT)) & USDHC_MMC_BOOT_BOOT_BLK_CNT_MASK)
/*! @} */

/*! @name VEND_SPEC2 - Vendor Specific 2 Register */
/*! @{ */

#define USDHC_VEND_SPEC2_CARD_INT_D3_TEST_MASK   (0x8U)
#define USDHC_VEND_SPEC2_CARD_INT_D3_TEST_SHIFT  (3U)
/*! CARD_INT_D3_TEST - Card interrupt detection test
 *  0b0..Check the card interrupt only when DATA3 is high.
 *  0b1..Check the card interrupt by ignoring the status of DATA3.
 */
#define USDHC_VEND_SPEC2_CARD_INT_D3_TEST(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_CARD_INT_D3_TEST_SHIFT)) & USDHC_VEND_SPEC2_CARD_INT_D3_TEST_MASK)

#define USDHC_VEND_SPEC2_TUNING_BIT_EN_MASK      (0x30U)
#define USDHC_VEND_SPEC2_TUNING_BIT_EN_SHIFT     (4U)
/*! TUNING_BIT_EN - Tuning bit enable
 *  0b00..Enable Tuning circuit for DATA[3:0]
 *  0b01..Enable Tuning circuit for DATA[7:0]
 *  0b10..Enable Tuning circuit for DATA[0]
 *  0b11..Invalid
 */
#define USDHC_VEND_SPEC2_TUNING_BIT_EN(x)        (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_TUNING_BIT_EN_SHIFT)) & USDHC_VEND_SPEC2_TUNING_BIT_EN_MASK)

#define USDHC_VEND_SPEC2_TUNING_CMD_EN_MASK      (0x40U)
#define USDHC_VEND_SPEC2_TUNING_CMD_EN_SHIFT     (6U)
/*! TUNING_CMD_EN - Tuning command enable
 *  0b0..Auto tuning circuit does not check the CMD line.
 *  0b1..Auto tuning circuit checks the CMD line.
 */
#define USDHC_VEND_SPEC2_TUNING_CMD_EN(x)        (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_TUNING_CMD_EN_SHIFT)) & USDHC_VEND_SPEC2_TUNING_CMD_EN_MASK)

#define USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_MASK    (0x1000U)
#define USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_SHIFT   (12U)
/*! ACMD23_ARGU2_EN - Argument2 register enable for ACMD23
 *  0b0..Disable
 *  0b1..Argument2 register enable for ACMD23 sharing with SDMA system address register. Default is enabled.
 */
#define USDHC_VEND_SPEC2_ACMD23_ARGU2_EN(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_SHIFT)) & USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_MASK)

#define USDHC_VEND_SPEC2_EN_32K_CLK_MASK         (0x8000U)
#define USDHC_VEND_SPEC2_EN_32K_CLK_SHIFT        (15U)
/*! EN_32K_CLK - Select the clock source for host card detection.
 *  0b0..Use the peripheral clock (ipg_clk) for card detection.
 *  0b1..Use the low power clock (ipg_clk_lp) for card detection.
 */
#define USDHC_VEND_SPEC2_EN_32K_CLK(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_EN_32K_CLK_SHIFT)) & USDHC_VEND_SPEC2_EN_32K_CLK_MASK)
/*! @} */

/*! @name TUNING_CTRL - Tuning Control */
/*! @{ */

#define USDHC_TUNING_CTRL_TUNING_START_TAP_MASK  (0x7FU)
#define USDHC_TUNING_CTRL_TUNING_START_TAP_SHIFT (0U)
/*! TUNING_START_TAP - Tuning start */
#define USDHC_TUNING_CTRL_TUNING_START_TAP(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_START_TAP_SHIFT)) & USDHC_TUNING_CTRL_TUNING_START_TAP_MASK)

#define USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_MASK (0x80U)
#define USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_SHIFT (7U)
/*! DIS_CMD_CHK_FOR_STD_TUNING - Disable command check for standard tuning */
#define USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING(x) (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_SHIFT)) & USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_MASK)

#define USDHC_TUNING_CTRL_TUNING_COUNTER_MASK    (0xFF00U)
#define USDHC_TUNING_CTRL_TUNING_COUNTER_SHIFT   (8U)
/*! TUNING_COUNTER - Tuning counter */
#define USDHC_TUNING_CTRL_TUNING_COUNTER(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_COUNTER_SHIFT)) & USDHC_TUNING_CTRL_TUNING_COUNTER_MASK)

#define USDHC_TUNING_CTRL_TUNING_STEP_MASK       (0x70000U)
#define USDHC_TUNING_CTRL_TUNING_STEP_SHIFT      (16U)
/*! TUNING_STEP - TUNING_STEP */
#define USDHC_TUNING_CTRL_TUNING_STEP(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_STEP_SHIFT)) & USDHC_TUNING_CTRL_TUNING_STEP_MASK)

#define USDHC_TUNING_CTRL_TUNING_WINDOW_MASK     (0x700000U)
#define USDHC_TUNING_CTRL_TUNING_WINDOW_SHIFT    (20U)
/*! TUNING_WINDOW - Data window */
#define USDHC_TUNING_CTRL_TUNING_WINDOW(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_WINDOW_SHIFT)) & USDHC_TUNING_CTRL_TUNING_WINDOW_MASK)

#define USDHC_TUNING_CTRL_STD_TUNING_EN_MASK     (0x1000000U)
#define USDHC_TUNING_CTRL_STD_TUNING_EN_SHIFT    (24U)
/*! STD_TUNING_EN - Standard tuning circuit and procedure enable */
#define USDHC_TUNING_CTRL_STD_TUNING_EN(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_STD_TUNING_EN_SHIFT)) & USDHC_TUNING_CTRL_STD_TUNING_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USDHC_Register_Masks */


/*!
 * @}
 */ /* end of group USDHC_Peripheral_Access_Layer */


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


#endif  /* PERI_USDHC_H_ */

