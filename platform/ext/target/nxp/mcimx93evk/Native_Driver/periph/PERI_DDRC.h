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
**         CMSIS Peripheral Access Layer for DDRC
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
 * @file PERI_DDRC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DDRC
 *
 * CMSIS Peripheral Access Layer for DDRC
 */

#if !defined(PERI_DDRC_H_)
#define PERI_DDRC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- DDRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRC_Peripheral_Access_Layer DDRC Peripheral Access Layer
 * @{
 */

/** DDRC - Size of Registers Arrays */
#define DDRC_CS_BNDS_COUNT                        2u
#define DDRC_CS_CONFIG_COUNT                      2u
#define DDRC_DDR_MTP_COUNT                        10u

/** DDRC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x8 */
    __IO uint32_t CS_BNDS;                           /**< Rank 0 Memory Bounds..Rank 1 Memory Bounds, array offset: 0x0, array step: 0x8 */
         uint8_t RESERVED_0[4];
  } CS_BNDS[DDRC_CS_BNDS_COUNT];
       uint8_t RESERVED_0[16];
  __IO uint32_t REMAP_0A;                          /**< Remap Region 0A Configuration, offset: 0x20 */
  __IO uint32_t REMAP_0B;                          /**< Remap Region 0B Configuration, offset: 0x24 */
  __IO uint32_t REMAP_1A;                          /**< Remap Region 1A Configuration, offset: 0x28 */
  __IO uint32_t REMAP_1B;                          /**< Remap Region 1B Configuration, offset: 0x2C */
  __IO uint32_t REMAP_2A;                          /**< Remap Region 2A Configuration, offset: 0x30 */
  __IO uint32_t REMAP_2B;                          /**< Remap Region 2B Configuration, offset: 0x34 */
  __IO uint32_t REMAP_3A;                          /**< Remap Region 3A Configuration, offset: 0x38 */
  __IO uint32_t REMAP_3B;                          /**< Remap Region 3B Configuration, offset: 0x3C */
  __IO uint32_t DDR_ADDR_DEC_0;                    /**< DDRC Address Decode 0, offset: 0x40 */
  __IO uint32_t DDR_ADDR_DEC_1;                    /**< DDRC Address Decode 1, offset: 0x44 */
  __IO uint32_t DDR_ADDR_DEC_2;                    /**< DDRC Address Decode 2, offset: 0x48 */
  __IO uint32_t DDR_ADDR_DEC_3;                    /**< DDRC Address Decode 3, offset: 0x4C */
  __IO uint32_t DDR_ADDR_DEC_4;                    /**< DDRC Address Decode 4, offset: 0x50 */
  __IO uint32_t DDR_ADDR_DEC_5;                    /**< DDRC Address Decode 5, offset: 0x54 */
  __IO uint32_t DDR_ADDR_DEC_6;                    /**< DDRC Address Decode 6, offset: 0x58 */
  __IO uint32_t DDR_ADDR_DEC_7;                    /**< DDRC Address Decode 7, offset: 0x5C */
  __IO uint32_t DDR_ADDR_DEC_8;                    /**< DDRC Address Decode 8, offset: 0x60 */
  __IO uint32_t DDR_ADDR_DEC_9;                    /**< DDRC Address Decode 9, offset: 0x64 */
       uint8_t RESERVED_1[24];
  __IO uint32_t CS_CONFIG[DDRC_CS_CONFIG_COUNT];   /**< Rank 0 Configuration..Rank 1 Configuration, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_2[120];
  __IO uint32_t TIMING_CFG_3;                      /**< DDR SDRAM Timing Configuration 3, offset: 0x100 */
  __IO uint32_t TIMING_CFG_0;                      /**< DDR SDRAM Timing Configuration 0, offset: 0x104 */
  __IO uint32_t TIMING_CFG_1;                      /**< DDR SDRAM Timing Configuration 1, offset: 0x108 */
  __IO uint32_t TIMING_CFG_2;                      /**< DDR SDRAM Timing Configuration 2, offset: 0x10C */
  __IO uint32_t DDR_SDRAM_CFG;                     /**< DDR SDRAM Control Configuration, offset: 0x110 */
  __IO uint32_t DDR_SDRAM_CFG_2;                   /**< DDR SDRAM Control Configuration 2, offset: 0x114 */
       uint8_t RESERVED_3[8];
  __IO uint32_t DDR_SDRAM_MD_CNTL;                 /**< DDR SDRAM Mode Control, offset: 0x120 */
  __IO uint32_t DDR_SDRAM_INTERVAL;                /**< DDR SDRAM Interval Configuration, offset: 0x124 */
  __IO uint32_t DDR_DATA_INIT;                     /**< DDR SDRAM Data Initialization, offset: 0x128 */
       uint8_t RESERVED_4[52];
  __IO uint32_t TIMING_CFG_4;                      /**< DDR SDRAM Timing Configuration 4, offset: 0x160 */
       uint8_t RESERVED_5[8];
  __IO uint32_t TIMING_CFG_7;                      /**< DDR SDRAM Timing Configuration 7, offset: 0x16C */
  __IO uint32_t DDR_ZQ_CNTL;                       /**< DDR SDRAM ZQ Calibration Control, offset: 0x170 */
       uint8_t RESERVED_6[8];
  __IO uint32_t DDR_SR_CNTR;                       /**< DDR SDRAM Self-Refresh Counter, offset: 0x17C */
       uint8_t RESERVED_7[208];
  __IO uint32_t TIMING_CFG_8;                      /**< DDR SDRAM Timing Configuration 8, offset: 0x250 */
  __IO uint32_t TIMING_CFG_9;                      /**< DDR SDRAM timing configuration 9, offset: 0x254 */
  __IO uint32_t TIMING_CFG_10;                     /**< DDR SDRAM Timing Configuration 10, offset: 0x258 */
  __IO uint32_t TIMING_CFG_11;                     /**< DDR SDRAM Timing Configuration 11, offset: 0x25C */
  __IO uint32_t DDR_SDRAM_CFG_3;                   /**< DDR SDRAM Control Configuration 3, offset: 0x260 */
  __IO uint32_t DDR_SDRAM_CFG_4;                   /**< DDR SDRAM Control Configuration 4, offset: 0x264 */
       uint8_t RESERVED_8[88];
  __I  uint32_t DDR_SDRAM_REF_RATE;                /**< DDR Refresh Rate, offset: 0x2C0 */
       uint8_t RESERVED_9[60];
  __IO uint32_t TIMING_CFG_12;                     /**< DDR SDRAM Timing Configuration 12, offset: 0x300 */
  __IO uint32_t TIMING_CFG_13;                     /**< DDR SDRAM Timing Configuration 13, offset: 0x304 */
  __IO uint32_t TIMING_CFG_14;                     /**< DDR SDRAM Timing Configuration 14, offset: 0x308 */
       uint8_t RESERVED_10[1268];
  __IO uint32_t TX_CFG_1;                          /**< Transaction Configuration Register 1, offset: 0x800 */
       uint8_t RESERVED_11[800];
  __IO uint32_t DDRDSR_2;                          /**< DDR SDRAM Debug Status 2, offset: 0xB24 */
       uint8_t RESERVED_12[208];
  __I  uint32_t DDR_IP_REV1;                       /**< DDRC Revision 1, offset: 0xBF8 */
       uint8_t RESERVED_13[260];
  __IO uint32_t DDR_MTCR;                          /**< DDR SDRAM Memory Test Control, offset: 0xD00 */
       uint8_t RESERVED_14[28];
  __IO uint32_t DDR_MTP[DDRC_DDR_MTP_COUNT];       /**< DDR SDRAM Memory Test Pattern n, array offset: 0xD20, array step: 0x4 */
       uint8_t RESERVED_15[24];
  __IO uint32_t DDR_MT_ST_EXT_ADDR;                /**< DDR SDRAM Memory Test Start Extended Address, offset: 0xD60 */
  __IO uint32_t DDR_MT_ST_ADDR;                    /**< DDR SDRAM Memory Test Start Address, offset: 0xD64 */
  __IO uint32_t DDR_MT_END_EXT_ADDR;               /**< DDR SDRAM Memory Test End Extended Address, offset: 0xD68 */
  __IO uint32_t DDR_MT_END_ADDR;                   /**< DDR SDRAM Memory Test End Address, offset: 0xD6C */
       uint8_t RESERVED_16[144];
  __IO uint32_t PMGC0;                             /**< Performance Monitor Global Control, offset: 0xE00 */
       uint8_t RESERVED_17[12];
  __IO uint32_t PMLCA0;                            /**< Performance Monitor Local Control A0, offset: 0xE10 */
  __IO uint32_t PMLCB0;                            /**< Performance Monitor Local Control B0, offset: 0xE14 */
  __IO uint32_t PMC0A;                             /**< PMC 0a, offset: 0xE18 */
  __IO uint32_t PMC0B;                             /**< PMC 0b, offset: 0xE1C */
  __IO uint32_t PMLCA1;                            /**< Performance Monitor Local Control A, offset: 0xE20 */
  __IO uint32_t PMLCB1;                            /**< Performance Monitor Local Control B, offset: 0xE24 */
  __IO uint32_t PMC1;                              /**< Performance Monitor Counter, offset: 0xE28 */
       uint8_t RESERVED_18[4];
  __IO uint32_t PMLCA2;                            /**< Performance Monitor Local Control A, offset: 0xE30 */
  __IO uint32_t PMLCB2;                            /**< Performance Monitor Local Control B, offset: 0xE34 */
  __IO uint32_t PMC2;                              /**< Performance Monitor Counter, offset: 0xE38 */
       uint8_t RESERVED_19[4];
  __IO uint32_t PMLCA3;                            /**< Performance Monitor Local Control A, offset: 0xE40 */
  __IO uint32_t PMLCB3;                            /**< Performance Monitor Local Control B, offset: 0xE44 */
  __IO uint32_t PMC3;                              /**< Performance Monitor Counter, offset: 0xE48 */
       uint8_t RESERVED_20[4];
  __IO uint32_t PMLCA4;                            /**< Performance Monitor Local Control A, offset: 0xE50 */
  __IO uint32_t PMLCB4;                            /**< Performance Monitor Local Control B, offset: 0xE54 */
  __IO uint32_t PMC4;                              /**< Performance Monitor Counter, offset: 0xE58 */
       uint8_t RESERVED_21[4];
  __IO uint32_t PMLCA5;                            /**< Performance Monitor Local Control A, offset: 0xE60 */
  __IO uint32_t PMLCB5;                            /**< Performance Monitor Local Control B, offset: 0xE64 */
  __IO uint32_t PMC5;                              /**< Performance Monitor Counter, offset: 0xE68 */
       uint8_t RESERVED_22[4];
  __IO uint32_t PMLCA6;                            /**< Performance Monitor Local Control A, offset: 0xE70 */
  __IO uint32_t PMLCB6;                            /**< Performance Monitor Local Control B, offset: 0xE74 */
  __IO uint32_t PMC6;                              /**< Performance Monitor Counter, offset: 0xE78 */
       uint8_t RESERVED_23[4];
  __IO uint32_t PMLCA7;                            /**< Performance Monitor Local Control A, offset: 0xE80 */
  __IO uint32_t PMLCB7;                            /**< Performance Monitor Local Control B, offset: 0xE84 */
  __IO uint32_t PMC7;                              /**< Performance Monitor Counter, offset: 0xE88 */
       uint8_t RESERVED_24[4];
  __IO uint32_t PMLCA8;                            /**< Performance Monitor Local Control A, offset: 0xE90 */
  __IO uint32_t PMLCB8;                            /**< Performance Monitor Local Control B, offset: 0xE94 */
  __IO uint32_t PMC8;                              /**< Performance Monitor Counter, offset: 0xE98 */
       uint8_t RESERVED_25[4];
  __IO uint32_t PMLCA9;                            /**< Performance Monitor Local Control A, offset: 0xEA0 */
  __IO uint32_t PMLCB9;                            /**< Performance Monitor Local Control B, offset: 0xEA4 */
  __IO uint32_t PMC9;                              /**< Performance Monitor Counter, offset: 0xEA8 */
       uint8_t RESERVED_26[4];
  __IO uint32_t PMLCA10;                           /**< Performance Monitor Local Control A, offset: 0xEB0 */
  __IO uint32_t PMLCB10;                           /**< Performance Monitor Local Control B, offset: 0xEB4 */
  __IO uint32_t PMC10;                             /**< Performance Monitor Counter, offset: 0xEB8 */
       uint8_t RESERVED_27[324];
  __IO uint32_t ERR_EN;                            /**< Error Enable, offset: 0x1000 */
       uint8_t RESERVED_28[252];
  __IO uint32_t DATA_ERR_INJECT_HI;                /**< Memory Data Path Error Injection Mask High, offset: 0x1100 */
  __IO uint32_t DATA_ERR_INJECT_LO;                /**< Memory Data Path Error Injection Mask Low, offset: 0x1104 */
  __IO uint32_t ERR_INJECT;                        /**< Memory Data Path Error Injection Mask ECC, offset: 0x1108 */
  __IO uint32_t ADDR_ERR_INJ;                      /**< Address Error Inject, offset: 0x110C */
       uint8_t RESERVED_29[8];
  __IO uint32_t CAPTURE_EXT_DATA_HI;               /**< Memory Extended Data Path Read Capture High, offset: 0x1118 */
  __IO uint32_t CAPTURE_EXT_DATA_LO;               /**< Memory Extended Data Path Read Capture Low, offset: 0x111C */
  __IO uint32_t CAPTURE_DATA_HI;                   /**< Memory Data Path Read Capture High, offset: 0x1120 */
  __IO uint32_t CAPTURE_DATA_LO;                   /**< Memory Data Path Read Capture Low, offset: 0x1124 */
  __IO uint32_t CAPTURE_ECC;                       /**< Memory Data Path Read Capture ECC, offset: 0x1128 */
       uint8_t RESERVED_30[20];
  __IO uint32_t ERR_DETECT;                        /**< Memory Error Detect, offset: 0x1140 */
  __IO uint32_t ERR_DISABLE;                       /**< Memory Error Disable, offset: 0x1144 */
  __IO uint32_t ERR_INT_EN;                        /**< Memory Error Interrupt Enable, offset: 0x1148 */
  __IO uint32_t CAPTURE_ATTRIBUTES;                /**< Memory Error Attributes Capture, offset: 0x114C */
  __IO uint32_t CAPTURE_ADDRESS;                   /**< Memory Error Address Capture, offset: 0x1150 */
  __IO uint32_t CAPTURE_EXT_ADDRESS;               /**< Memory Error Extended Address Capture, offset: 0x1154 */
  __IO uint32_t ERR_SBE;                           /**< Single-Bit ECC Memory Error Management, offset: 0x1158 */
       uint8_t RESERVED_31[228];
  __IO uint32_t ECC_REG_0;                         /**< ECC Region 0 Configuration, offset: 0x1240 */
  __IO uint32_t ECC_REG_1;                         /**< ECC Region 1 Configuration, offset: 0x1244 */
  __IO uint32_t ECC_REG_2;                         /**< ECC Region 2 Configuration, offset: 0x1248 */
  __IO uint32_t ECC_REG_3;                         /**< ECC Region 3 Configuration, offset: 0x124C */
  __IO uint32_t ECC_REG_4;                         /**< ECC Region 4 Configuration, offset: 0x1250 */
  __IO uint32_t ECC_REG_5;                         /**< ECC Region 5 Configuration, offset: 0x1254 */
  __IO uint32_t ECC_REG_6;                         /**< ECC Region 6 Configuration, offset: 0x1258 */
  __IO uint32_t ECC_REG_7;                         /**< ECC Region 7 Configuration, offset: 0x125C */
} DDRC_Type;

/* ----------------------------------------------------------------------------
   -- DDRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRC_Register_Masks DDRC Register Masks
 * @{
 */

/*! @name CS_BNDS - Rank 0 Memory Bounds..Rank 1 Memory Bounds */
/*! @{ */

#define DDRC_CS_BNDS_EA_MASK                     (0xFFFFU)
#define DDRC_CS_BNDS_EA_SHIFT                    (0U)
/*! EA - Ending Address */
#define DDRC_CS_BNDS_EA(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_CS_BNDS_EA_SHIFT)) & DDRC_CS_BNDS_EA_MASK)

#define DDRC_CS_BNDS_SA_MASK                     (0xFFFF0000U)
#define DDRC_CS_BNDS_SA_SHIFT                    (16U)
/*! SA - Starting Address */
#define DDRC_CS_BNDS_SA(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_CS_BNDS_SA_SHIFT)) & DDRC_CS_BNDS_SA_MASK)
/*! @} */

/*! @name REMAP_0A - Remap Region 0A Configuration */
/*! @{ */

#define DDRC_REMAP_0A_REG_0_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_0A_REG_0_REMAP_ADDR_SHIFT     (0U)
/*! REG_0_REMAP_ADDR - Region 0 Remap Starting Address */
#define DDRC_REMAP_0A_REG_0_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0A_REG_0_REMAP_ADDR_SHIFT)) & DDRC_REMAP_0A_REG_0_REMAP_ADDR_MASK)

#define DDRC_REMAP_0A_REG_0_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_0A_REG_0_REMAP_EN_SHIFT       (31U)
/*! REG_0_REMAP_EN - Region 0 Remap Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_REMAP_0A_REG_0_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0A_REG_0_REMAP_EN_SHIFT)) & DDRC_REMAP_0A_REG_0_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_0B - Remap Region 0B Configuration */
/*! @{ */

#define DDRC_REMAP_0B_REG_0_EA_MASK              (0xFFFU)
#define DDRC_REMAP_0B_REG_0_EA_SHIFT             (0U)
/*! REG_0_EA - Region 0 Ending Address */
#define DDRC_REMAP_0B_REG_0_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0B_REG_0_EA_SHIFT)) & DDRC_REMAP_0B_REG_0_EA_MASK)

#define DDRC_REMAP_0B_REG_0_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_0B_REG_0_SA_SHIFT             (16U)
/*! REG_0_SA - Region 0 Starting Address */
#define DDRC_REMAP_0B_REG_0_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_0B_REG_0_SA_SHIFT)) & DDRC_REMAP_0B_REG_0_SA_MASK)
/*! @} */

/*! @name REMAP_1A - Remap Region 1A Configuration */
/*! @{ */

#define DDRC_REMAP_1A_REG_1_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_1A_REG_1_REMAP_ADDR_SHIFT     (0U)
/*! REG_1_REMAP_ADDR - Region 1 Remap Starting Address */
#define DDRC_REMAP_1A_REG_1_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1A_REG_1_REMAP_ADDR_SHIFT)) & DDRC_REMAP_1A_REG_1_REMAP_ADDR_MASK)

#define DDRC_REMAP_1A_REG_1_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_1A_REG_1_REMAP_EN_SHIFT       (31U)
/*! REG_1_REMAP_EN - Region 1 Remap Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_REMAP_1A_REG_1_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1A_REG_1_REMAP_EN_SHIFT)) & DDRC_REMAP_1A_REG_1_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_1B - Remap Region 1B Configuration */
/*! @{ */

#define DDRC_REMAP_1B_REG_1_EA_MASK              (0xFFFU)
#define DDRC_REMAP_1B_REG_1_EA_SHIFT             (0U)
/*! REG_1_EA - Region 1 Ending Address */
#define DDRC_REMAP_1B_REG_1_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1B_REG_1_EA_SHIFT)) & DDRC_REMAP_1B_REG_1_EA_MASK)

#define DDRC_REMAP_1B_REG_1_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_1B_REG_1_SA_SHIFT             (16U)
/*! REG_1_SA - Region 1 Starting Address */
#define DDRC_REMAP_1B_REG_1_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_1B_REG_1_SA_SHIFT)) & DDRC_REMAP_1B_REG_1_SA_MASK)
/*! @} */

/*! @name REMAP_2A - Remap Region 2A Configuration */
/*! @{ */

#define DDRC_REMAP_2A_REG_2_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_2A_REG_2_REMAP_ADDR_SHIFT     (0U)
/*! REG_2_REMAP_ADDR - Region 2 Remap Starting Address */
#define DDRC_REMAP_2A_REG_2_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2A_REG_2_REMAP_ADDR_SHIFT)) & DDRC_REMAP_2A_REG_2_REMAP_ADDR_MASK)

#define DDRC_REMAP_2A_REG_2_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_2A_REG_2_REMAP_EN_SHIFT       (31U)
/*! REG_2_REMAP_EN - Region 2 Remap Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_REMAP_2A_REG_2_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2A_REG_2_REMAP_EN_SHIFT)) & DDRC_REMAP_2A_REG_2_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_2B - Remap Region 2B Configuration */
/*! @{ */

#define DDRC_REMAP_2B_REG_2_EA_MASK              (0xFFFU)
#define DDRC_REMAP_2B_REG_2_EA_SHIFT             (0U)
/*! REG_2_EA - Region 2 Ending Address */
#define DDRC_REMAP_2B_REG_2_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2B_REG_2_EA_SHIFT)) & DDRC_REMAP_2B_REG_2_EA_MASK)

#define DDRC_REMAP_2B_REG_2_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_2B_REG_2_SA_SHIFT             (16U)
/*! REG_2_SA - Region 2 Starting Address */
#define DDRC_REMAP_2B_REG_2_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_2B_REG_2_SA_SHIFT)) & DDRC_REMAP_2B_REG_2_SA_MASK)
/*! @} */

/*! @name REMAP_3A - Remap Region 3A Configuration */
/*! @{ */

#define DDRC_REMAP_3A_REG_3_REMAP_ADDR_MASK      (0xFFFU)
#define DDRC_REMAP_3A_REG_3_REMAP_ADDR_SHIFT     (0U)
/*! REG_3_REMAP_ADDR - Region 3 Remap Starting Address */
#define DDRC_REMAP_3A_REG_3_REMAP_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3A_REG_3_REMAP_ADDR_SHIFT)) & DDRC_REMAP_3A_REG_3_REMAP_ADDR_MASK)

#define DDRC_REMAP_3A_REG_3_REMAP_EN_MASK        (0x80000000U)
#define DDRC_REMAP_3A_REG_3_REMAP_EN_SHIFT       (31U)
/*! REG_3_REMAP_EN - Region 3 Remap Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_REMAP_3A_REG_3_REMAP_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3A_REG_3_REMAP_EN_SHIFT)) & DDRC_REMAP_3A_REG_3_REMAP_EN_MASK)
/*! @} */

/*! @name REMAP_3B - Remap Region 3B Configuration */
/*! @{ */

#define DDRC_REMAP_3B_REG_3_EA_MASK              (0xFFFU)
#define DDRC_REMAP_3B_REG_3_EA_SHIFT             (0U)
/*! REG_3_EA - Region 3 Ending Address */
#define DDRC_REMAP_3B_REG_3_EA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3B_REG_3_EA_SHIFT)) & DDRC_REMAP_3B_REG_3_EA_MASK)

#define DDRC_REMAP_3B_REG_3_SA_MASK              (0xFFF0000U)
#define DDRC_REMAP_3B_REG_3_SA_SHIFT             (16U)
/*! REG_3_SA - Region 3 Starting Address */
#define DDRC_REMAP_3B_REG_3_SA(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_REMAP_3B_REG_3_SA_SHIFT)) & DDRC_REMAP_3B_REG_3_SA_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_0 - DDRC Address Decode 0 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_MASK      (0xFCU)
#define DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_SHIFT     (2U)
/*! ROW14_OVRD - Row 14 Override */
#define DDRC_DDR_ADDR_DEC_0_ROW14_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW14_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_MASK      (0xFC00U)
#define DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_SHIFT     (10U)
/*! ROW15_OVRD - Row 15 Override */
#define DDRC_DDR_ADDR_DEC_0_ROW15_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW15_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_MASK      (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_SHIFT     (18U)
/*! ROW16_OVRD - Row 16 Override */
#define DDRC_DDR_ADDR_DEC_0_ROW16_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW16_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_MASK      (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_SHIFT     (26U)
/*! ROW17_OVRD - Row 17 Override */
#define DDRC_DDR_ADDR_DEC_0_ROW17_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_0_ROW17_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_1 - DDRC Address Decode 1 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_MASK      (0xFCU)
#define DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_SHIFT     (2U)
/*! ROW10_OVRD - Row 10 Override */
#define DDRC_DDR_ADDR_DEC_1_ROW10_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW10_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_MASK      (0xFC00U)
#define DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_SHIFT     (10U)
/*! ROW11_OVRD - Row 11 Override */
#define DDRC_DDR_ADDR_DEC_1_ROW11_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW11_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_MASK      (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_SHIFT     (18U)
/*! ROW12_OVRD - Row 12 Override */
#define DDRC_DDR_ADDR_DEC_1_ROW12_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW12_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_MASK      (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_SHIFT     (26U)
/*! ROW13_OVRD - Row 13 Override */
#define DDRC_DDR_ADDR_DEC_1_ROW13_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_1_ROW13_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_2 - DDRC Address Decode 2 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_SHIFT      (2U)
/*! ROW6_OVRD - Row 6 Override */
#define DDRC_DDR_ADDR_DEC_2_ROW6_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW6_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_SHIFT      (10U)
/*! ROW7_OVRD - Row 7 Override */
#define DDRC_DDR_ADDR_DEC_2_ROW7_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW7_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_SHIFT      (18U)
/*! ROW8_OVRD - Row 8 Override */
#define DDRC_DDR_ADDR_DEC_2_ROW8_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW8_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_SHIFT      (26U)
/*! ROW9_OVRD - Row 9 Override */
#define DDRC_DDR_ADDR_DEC_2_ROW9_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_2_ROW9_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_3 - DDRC Address Decode 3 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_SHIFT      (2U)
/*! ROW2_OVRD - Row 2 Override */
#define DDRC_DDR_ADDR_DEC_3_ROW2_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW2_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_SHIFT      (10U)
/*! ROW3_OVRD - Row 3 Override */
#define DDRC_DDR_ADDR_DEC_3_ROW3_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW3_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_SHIFT      (18U)
/*! ROW4_OVRD - Row 4 Override */
#define DDRC_DDR_ADDR_DEC_3_ROW4_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW4_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_SHIFT      (26U)
/*! ROW5_OVRD - Row 5 Override */
#define DDRC_DDR_ADDR_DEC_3_ROW5_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_3_ROW5_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_4 - DDRC Address Decode 4 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_4_COL9_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_4_COL9_OVRD_SHIFT      (2U)
/*! COL9_OVRD - Col 9 Override */
#define DDRC_DDR_ADDR_DEC_4_COL9_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_COL9_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_COL9_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_4_COL10_OVRD_MASK      (0xFC00U)
#define DDRC_DDR_ADDR_DEC_4_COL10_OVRD_SHIFT     (10U)
/*! COL10_OVRD - Col 10 Override */
#define DDRC_DDR_ADDR_DEC_4_COL10_OVRD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_COL10_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_COL10_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_SHIFT      (18U)
/*! ROW0_OVRD - Row 0 Override */
#define DDRC_DDR_ADDR_DEC_4_ROW0_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_ROW0_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_SHIFT      (26U)
/*! ROW1_OVRD - Row 1 Override */
#define DDRC_DDR_ADDR_DEC_4_ROW1_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_4_ROW1_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_5 - DDRC Address Decode 5 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_5_COL5_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_5_COL5_OVRD_SHIFT      (2U)
/*! COL5_OVRD - Col 5 Override */
#define DDRC_DDR_ADDR_DEC_5_COL5_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL5_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL5_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_5_COL6_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_5_COL6_OVRD_SHIFT      (10U)
/*! COL6_OVRD - Col 6 Override */
#define DDRC_DDR_ADDR_DEC_5_COL6_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL6_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL6_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_5_COL7_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_5_COL7_OVRD_SHIFT      (18U)
/*! COL7_OVRD - Col 7 Override */
#define DDRC_DDR_ADDR_DEC_5_COL7_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL7_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL7_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_5_COL8_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_5_COL8_OVRD_SHIFT      (26U)
/*! COL8_OVRD - Col 8 Override */
#define DDRC_DDR_ADDR_DEC_5_COL8_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_5_COL8_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_5_COL8_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_6 - DDRC Address Decode 6 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_6_COL1_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_6_COL1_OVRD_SHIFT      (2U)
/*! COL1_OVRD - Col 1 Override */
#define DDRC_DDR_ADDR_DEC_6_COL1_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_6_COL2_OVRD_MASK       (0xFC00U)
#define DDRC_DDR_ADDR_DEC_6_COL2_OVRD_SHIFT      (10U)
/*! COL2_OVRD - Col 2 Override */
#define DDRC_DDR_ADDR_DEC_6_COL2_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL2_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL2_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_6_COL3_OVRD_MASK       (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_6_COL3_OVRD_SHIFT      (18U)
/*! COL3_OVRD - Col 3 Override */
#define DDRC_DDR_ADDR_DEC_6_COL3_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL3_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL3_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_6_COL4_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_6_COL4_OVRD_SHIFT      (26U)
/*! COL4_OVRD - Col 4 Override */
#define DDRC_DDR_ADDR_DEC_6_COL4_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_6_COL4_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_6_COL4_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_7 - DDRC Address Decode 7 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_7_CID1_OVRD_MASK       (0xFCU)
#define DDRC_DDR_ADDR_DEC_7_CID1_OVRD_SHIFT      (2U)
/*! CID1_OVRD - CID 1 Override */
#define DDRC_DDR_ADDR_DEC_7_CID1_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_CID1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_CID1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_7_BA0_OVRD_MASK        (0xFC00U)
#define DDRC_DDR_ADDR_DEC_7_BA0_OVRD_SHIFT       (10U)
/*! BA0_OVRD - Bank 0 Override */
#define DDRC_DDR_ADDR_DEC_7_BA0_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_BA0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_BA0_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_7_BA1_OVRD_MASK        (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_7_BA1_OVRD_SHIFT       (18U)
/*! BA1_OVRD - Bank 1 Override */
#define DDRC_DDR_ADDR_DEC_7_BA1_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_BA1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_BA1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_7_COL0_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_7_COL0_OVRD_SHIFT      (26U)
/*! COL0_OVRD - Col 0 Override */
#define DDRC_DDR_ADDR_DEC_7_COL0_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_7_COL0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_7_COL0_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_8 - DDRC Address Decode 8 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_8_BG1_OVRD_MASK        (0xFCU)
#define DDRC_DDR_ADDR_DEC_8_BG1_OVRD_SHIFT       (2U)
/*! BG1_OVRD - Bank Group 1 Override */
#define DDRC_DDR_ADDR_DEC_8_BG1_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_BG1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_BG1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_8_CS0_OVRD_MASK        (0xFC00U)
#define DDRC_DDR_ADDR_DEC_8_CS0_OVRD_SHIFT       (10U)
/*! CS0_OVRD - Interleaved Rank 0 Override */
#define DDRC_DDR_ADDR_DEC_8_CS0_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_CS0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_CS0_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_8_CS1_OVRD_MASK        (0xFC0000U)
#define DDRC_DDR_ADDR_DEC_8_CS1_OVRD_SHIFT       (18U)
/*! CS1_OVRD - Interleaved Rank 1 Override */
#define DDRC_DDR_ADDR_DEC_8_CS1_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_CS1_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_CS1_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_8_CID0_OVRD_MASK       (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_8_CID0_OVRD_SHIFT      (26U)
/*! CID0_OVRD - CID 0 Override */
#define DDRC_DDR_ADDR_DEC_8_CID0_OVRD(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_8_CID0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_8_CID0_OVRD_MASK)
/*! @} */

/*! @name DDR_ADDR_DEC_9 - DDRC Address Decode 9 */
/*! @{ */

#define DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_MASK   (0x1U)
#define DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_SHIFT  (0U)
/*! ADDR_DEC_OVRD - Address Decode Override */
#define DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_9_ADDR_DEC_OVRD_MASK)

#define DDRC_DDR_ADDR_DEC_9_BG0_OVRD_MASK        (0xFC000000U)
#define DDRC_DDR_ADDR_DEC_9_BG0_OVRD_SHIFT       (26U)
/*! BG0_OVRD - Bank Group 0 Override */
#define DDRC_DDR_ADDR_DEC_9_BG0_OVRD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ADDR_DEC_9_BG0_OVRD_SHIFT)) & DDRC_DDR_ADDR_DEC_9_BG0_OVRD_MASK)
/*! @} */

/*! @name CS_CONFIG - Rank 0 Configuration..Rank 1 Configuration */
/*! @{ */

#define DDRC_CS_CONFIG_COL_BITS_CS_MASK          (0x7U)
#define DDRC_CS_CONFIG_COL_BITS_CS_SHIFT         (0U)
/*! COL_BITS_CS - Column Bits
 *  0b000..8
 *  0b001..9
 *  0b010..10
 *  0b011..11
 *  0b111..7
 */
#define DDRC_CS_CONFIG_COL_BITS_CS(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_COL_BITS_CS_SHIFT)) & DDRC_CS_CONFIG_COL_BITS_CS_MASK)

#define DDRC_CS_CONFIG_BG_BITS_CS_MASK           (0x30U)
#define DDRC_CS_CONFIG_BG_BITS_CS_SHIFT          (4U)
/*! BG_BITS_CS - Bank Group Bits
 *  0b00..0
 *  0b01..Must be set to 1 to enable the 3rd bank address bit for LPDDR4 memories.
 *  0b10..Reserved
 *  0b11..
 */
#define DDRC_CS_CONFIG_BG_BITS_CS(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_BG_BITS_CS_SHIFT)) & DDRC_CS_CONFIG_BG_BITS_CS_MASK)

#define DDRC_CS_CONFIG_ROW_BITS_CS_MASK          (0x700U)
#define DDRC_CS_CONFIG_ROW_BITS_CS_SHIFT         (8U)
/*! ROW_BITS_CS - Row Bits
 *  0b000..12
 *  0b001..13
 *  0b010..14
 *  0b011..15
 *  0b100..16
 *  0b101..17
 */
#define DDRC_CS_CONFIG_ROW_BITS_CS(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_ROW_BITS_CS_SHIFT)) & DDRC_CS_CONFIG_ROW_BITS_CS_MASK)

#define DDRC_CS_CONFIG_AP_EN_MASK                (0x800000U)
#define DDRC_CS_CONFIG_AP_EN_SHIFT               (23U)
/*! AP_EN - Auto-Precharge Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_CS_CONFIG_AP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_AP_EN_SHIFT)) & DDRC_CS_CONFIG_AP_EN_MASK)

#define DDRC_CS_CONFIG_CS_EN_MASK                (0x80000000U)
#define DDRC_CS_CONFIG_CS_EN_SHIFT               (31U)
/*! CS_EN - Rank Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_CS_CONFIG_CS_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_CS_CONFIG_CS_EN_SHIFT)) & DDRC_CS_CONFIG_CS_EN_MASK)
/*! @} */

/*! @name TIMING_CFG_3 - DDR SDRAM Timing Configuration 3 */
/*! @{ */

#define DDRC_TIMING_CFG_3_EXT_WRTORD_MASK        (0x1U)
#define DDRC_TIMING_CFG_3_EXT_WRTORD_SHIFT       (0U)
/*! EXT_WRTORD - Extended Write-To-Read Time */
#define DDRC_TIMING_CFG_3_EXT_WRTORD(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_WRTORD_SHIFT)) & DDRC_TIMING_CFG_3_EXT_WRTORD_MASK)

#define DDRC_TIMING_CFG_3_EXT_ACTTOACT_MASK      (0x2U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOACT_SHIFT     (1U)
/*! EXT_ACTTOACT - Extended Activate-To-Activate Time */
#define DDRC_TIMING_CFG_3_EXT_ACTTOACT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_ACTTOACT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_ACTTOACT_MASK)

#define DDRC_TIMING_CFG_3_EXT_FOUR_ACT_MASK      (0x8U)
#define DDRC_TIMING_CFG_3_EXT_FOUR_ACT_SHIFT     (3U)
/*! EXT_FOUR_ACT - Extended Four Activate */
#define DDRC_TIMING_CFG_3_EXT_FOUR_ACT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_FOUR_ACT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_FOUR_ACT_MASK)

#define DDRC_TIMING_CFG_3_EXT_CKE_PLS_MASK       (0x30U)
#define DDRC_TIMING_CFG_3_EXT_CKE_PLS_SHIFT      (4U)
/*! EXT_CKE_PLS - Extended MCKE Pulse */
#define DDRC_TIMING_CFG_3_EXT_CKE_PLS(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_CKE_PLS_SHIFT)) & DDRC_TIMING_CFG_3_EXT_CKE_PLS_MASK)

#define DDRC_TIMING_CFG_3_EXT_WRREC_MASK         (0x300U)
#define DDRC_TIMING_CFG_3_EXT_WRREC_SHIFT        (8U)
/*! EXT_WRREC - Extended Write Recovery
 *  0b11..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_3_EXT_WRREC(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_WRREC_SHIFT)) & DDRC_TIMING_CFG_3_EXT_WRREC_MASK)

#define DDRC_TIMING_CFG_3_EXT_WR_LAT_2_MASK      (0x800U)
#define DDRC_TIMING_CFG_3_EXT_WR_LAT_2_SHIFT     (11U)
/*! EXT_WR_LAT_2 - Extended Write Latency 2 */
#define DDRC_TIMING_CFG_3_EXT_WR_LAT_2(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_WR_LAT_2_SHIFT)) & DDRC_TIMING_CFG_3_EXT_WR_LAT_2_MASK)

#define DDRC_TIMING_CFG_3_EXT_CASLAT_MASK        (0x7000U)
#define DDRC_TIMING_CFG_3_EXT_CASLAT_SHIFT       (12U)
/*! EXT_CASLAT - Extended CAS Latency */
#define DDRC_TIMING_CFG_3_EXT_CASLAT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_CASLAT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_CASLAT_MASK)

#define DDRC_TIMING_CFG_3_EXT_REFREC_MASK        (0x3F0000U)
#define DDRC_TIMING_CFG_3_EXT_REFREC_SHIFT       (16U)
/*! EXT_REFREC - Extended Refresh Recovery */
#define DDRC_TIMING_CFG_3_EXT_REFREC(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_REFREC_SHIFT)) & DDRC_TIMING_CFG_3_EXT_REFREC_MASK)

#define DDRC_TIMING_CFG_3_EXT_ACTTORW_MASK       (0xC00000U)
#define DDRC_TIMING_CFG_3_EXT_ACTTORW_SHIFT      (22U)
/*! EXT_ACTTORW - Extended Activate To Read Or Write Time */
#define DDRC_TIMING_CFG_3_EXT_ACTTORW(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_ACTTORW_SHIFT)) & DDRC_TIMING_CFG_3_EXT_ACTTORW_MASK)

#define DDRC_TIMING_CFG_3_EXT_ACTTOPRE_MASK      (0x7000000U)
#define DDRC_TIMING_CFG_3_EXT_ACTTOPRE_SHIFT     (24U)
/*! EXT_ACTTOPRE - Extended Activate-To-Precharge Time */
#define DDRC_TIMING_CFG_3_EXT_ACTTOPRE(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_ACTTOPRE_SHIFT)) & DDRC_TIMING_CFG_3_EXT_ACTTOPRE_MASK)

#define DDRC_TIMING_CFG_3_EXT_PRETOACT_MASK      (0x30000000U)
#define DDRC_TIMING_CFG_3_EXT_PRETOACT_SHIFT     (28U)
/*! EXT_PRETOACT - Extended Precharge-To-Activate Time */
#define DDRC_TIMING_CFG_3_EXT_PRETOACT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_3_EXT_PRETOACT_SHIFT)) & DDRC_TIMING_CFG_3_EXT_PRETOACT_MASK)
/*! @} */

/*! @name TIMING_CFG_0 - DDR SDRAM Timing Configuration 0 */
/*! @{ */

#define DDRC_TIMING_CFG_0_MRS_CYC_MASK           (0x3FU)
#define DDRC_TIMING_CFG_0_MRS_CYC_SHIFT          (0U)
/*! MRS_CYC - MRW Cycle Time
 *  0b000000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_0_MRS_CYC(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_MRS_CYC_SHIFT)) & DDRC_TIMING_CFG_0_MRS_CYC_MASK)

#define DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_MASK   (0x1000U)
#define DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_SHIFT  (12U)
/*! EXT_ACT_PD_EXIT - Extended Active Power-Down Exit */
#define DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_EXT_ACT_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_MASK   (0xC000U)
#define DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_SHIFT  (14U)
/*! EXT_PRE_PD_EXIT - Extended Precharge Power-Down Exit */
#define DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_EXT_PRE_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_PRE_PD_EXIT_MASK       (0xF0000U)
#define DDRC_TIMING_CFG_0_PRE_PD_EXIT_SHIFT      (16U)
/*! PRE_PD_EXIT - Precharge Power-Down Exit
 *  0b0000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_0_PRE_PD_EXIT(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_PRE_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_PRE_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_ACT_PD_EXIT_MASK       (0xF00000U)
#define DDRC_TIMING_CFG_0_ACT_PD_EXIT_SHIFT      (20U)
/*! ACT_PD_EXIT - Active Powerdown Exit
 *  0b0000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_0_ACT_PD_EXIT(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_ACT_PD_EXIT_SHIFT)) & DDRC_TIMING_CFG_0_ACT_PD_EXIT_MASK)

#define DDRC_TIMING_CFG_0_WWT_MASK               (0x3000000U)
#define DDRC_TIMING_CFG_0_WWT_SHIFT              (24U)
/*! WWT - Write-To-Write Turnaround To Different Ranks */
#define DDRC_TIMING_CFG_0_WWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_WWT_SHIFT)) & DDRC_TIMING_CFG_0_WWT_MASK)

#define DDRC_TIMING_CFG_0_RRT_MASK               (0xC000000U)
#define DDRC_TIMING_CFG_0_RRT_SHIFT              (26U)
/*! RRT - Read-To-Read Turnaround To Different Ranks */
#define DDRC_TIMING_CFG_0_RRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_RRT_SHIFT)) & DDRC_TIMING_CFG_0_RRT_MASK)

#define DDRC_TIMING_CFG_0_WRT_MASK               (0x30000000U)
#define DDRC_TIMING_CFG_0_WRT_SHIFT              (28U)
/*! WRT - Write-To-Read Turnaround To Different Ranks */
#define DDRC_TIMING_CFG_0_WRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_WRT_SHIFT)) & DDRC_TIMING_CFG_0_WRT_MASK)

#define DDRC_TIMING_CFG_0_RWT_MASK               (0xC0000000U)
#define DDRC_TIMING_CFG_0_RWT_SHIFT              (30U)
/*! RWT - Read-To-Write Turnaround To Different Ranks */
#define DDRC_TIMING_CFG_0_RWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_0_RWT_SHIFT)) & DDRC_TIMING_CFG_0_RWT_MASK)
/*! @} */

/*! @name TIMING_CFG_1 - DDR SDRAM Timing Configuration 1 */
/*! @{ */

#define DDRC_TIMING_CFG_1_WRTORD_MASK            (0xFU)
#define DDRC_TIMING_CFG_1_WRTORD_SHIFT           (0U)
/*! WRTORD - Write-To-Read Interval
 *  0b0000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_1_WRTORD(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_WRTORD_SHIFT)) & DDRC_TIMING_CFG_1_WRTORD_MASK)

#define DDRC_TIMING_CFG_1_ACTTOACT_MASK          (0xF0U)
#define DDRC_TIMING_CFG_1_ACTTOACT_SHIFT         (4U)
/*! ACTTOACT - Activate-To-Activate Interval
 *  0b0000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_1_ACTTOACT(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_ACTTOACT_SHIFT)) & DDRC_TIMING_CFG_1_ACTTOACT_MASK)

#define DDRC_TIMING_CFG_1_WRREC_MASK             (0xF00U)
#define DDRC_TIMING_CFG_1_WRREC_SHIFT            (8U)
/*! WRREC - Write Recovery */
#define DDRC_TIMING_CFG_1_WRREC(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_WRREC_SHIFT)) & DDRC_TIMING_CFG_1_WRREC_MASK)

#define DDRC_TIMING_CFG_1_REFREC_MASK            (0xF000U)
#define DDRC_TIMING_CFG_1_REFREC_SHIFT           (12U)
/*! REFREC - Refresh Recovery */
#define DDRC_TIMING_CFG_1_REFREC(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_REFREC_SHIFT)) & DDRC_TIMING_CFG_1_REFREC_MASK)

#define DDRC_TIMING_CFG_1_CASLAT_MASK            (0xE0000U)
#define DDRC_TIMING_CFG_1_CASLAT_SHIFT           (17U)
/*! CASLAT - CAS Latency */
#define DDRC_TIMING_CFG_1_CASLAT(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_CASLAT_SHIFT)) & DDRC_TIMING_CFG_1_CASLAT_MASK)

#define DDRC_TIMING_CFG_1_ACTTORW_MASK           (0xF00000U)
#define DDRC_TIMING_CFG_1_ACTTORW_SHIFT          (20U)
/*! ACTTORW - Activate To Read Or Write
 *  0b0000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_1_ACTTORW(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_ACTTORW_SHIFT)) & DDRC_TIMING_CFG_1_ACTTORW_MASK)

#define DDRC_TIMING_CFG_1_ACTTOPRE_MASK          (0xF000000U)
#define DDRC_TIMING_CFG_1_ACTTOPRE_SHIFT         (24U)
/*! ACTTOPRE - Activate-To-Precharge Time */
#define DDRC_TIMING_CFG_1_ACTTOPRE(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_ACTTOPRE_SHIFT)) & DDRC_TIMING_CFG_1_ACTTOPRE_MASK)

#define DDRC_TIMING_CFG_1_PRETOACT_MASK          (0xF0000000U)
#define DDRC_TIMING_CFG_1_PRETOACT_SHIFT         (28U)
/*! PRETOACT - Precharge-To-Activate Time
 *  0b0000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_1_PRETOACT(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_1_PRETOACT_SHIFT)) & DDRC_TIMING_CFG_1_PRETOACT_MASK)
/*! @} */

/*! @name TIMING_CFG_2 - DDR SDRAM Timing Configuration 2 */
/*! @{ */

#define DDRC_TIMING_CFG_2_FOUR_ACT_MASK          (0x3FU)
#define DDRC_TIMING_CFG_2_FOUR_ACT_SHIFT         (0U)
/*! FOUR_ACT - Four Activate */
#define DDRC_TIMING_CFG_2_FOUR_ACT(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_FOUR_ACT_SHIFT)) & DDRC_TIMING_CFG_2_FOUR_ACT_MASK)

#define DDRC_TIMING_CFG_2_CKE_PLS_MASK           (0x1C0U)
#define DDRC_TIMING_CFG_2_CKE_PLS_SHIFT          (6U)
/*! CKE_PLS - MCKE Pulse */
#define DDRC_TIMING_CFG_2_CKE_PLS(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_CKE_PLS_SHIFT)) & DDRC_TIMING_CFG_2_CKE_PLS_MASK)

#define DDRC_TIMING_CFG_2_RD_TO_PRE_MASK         (0x3E000U)
#define DDRC_TIMING_CFG_2_RD_TO_PRE_SHIFT        (13U)
/*! RD_TO_PRE - Read-To-Precharge Time
 *  0b00000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_2_RD_TO_PRE(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_RD_TO_PRE_SHIFT)) & DDRC_TIMING_CFG_2_RD_TO_PRE_MASK)

#define DDRC_TIMING_CFG_2_EXT_WR_LAT_MASK        (0x40000U)
#define DDRC_TIMING_CFG_2_EXT_WR_LAT_SHIFT       (18U)
/*! EXT_WR_LAT - Extended Write Latency */
#define DDRC_TIMING_CFG_2_EXT_WR_LAT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_EXT_WR_LAT_SHIFT)) & DDRC_TIMING_CFG_2_EXT_WR_LAT_MASK)

#define DDRC_TIMING_CFG_2_WR_LAT_MASK            (0x780000U)
#define DDRC_TIMING_CFG_2_WR_LAT_SHIFT           (19U)
/*! WR_LAT - Write Latency */
#define DDRC_TIMING_CFG_2_WR_LAT(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_WR_LAT_SHIFT)) & DDRC_TIMING_CFG_2_WR_LAT_MASK)

#define DDRC_TIMING_CFG_2_DERATE_VAL_MASK        (0xF0000000U)
#define DDRC_TIMING_CFG_2_DERATE_VAL_SHIFT       (28U)
/*! DERATE_VAL - Derate Value */
#define DDRC_TIMING_CFG_2_DERATE_VAL(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_2_DERATE_VAL_SHIFT)) & DDRC_TIMING_CFG_2_DERATE_VAL_MASK)
/*! @} */

/*! @name DDR_SDRAM_CFG - DDR SDRAM Control Configuration */
/*! @{ */

#define DDRC_DDR_SDRAM_CFG_BI_MASK               (0x1U)
#define DDRC_DDR_SDRAM_CFG_BI_SHIFT              (0U)
/*! BI - Bypass Initialization
 *  0b0..Reserved; do not use
 *  0b1..Initialization routine is bypassed
 */
#define DDRC_DDR_SDRAM_CFG_BI(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_BI_SHIFT)) & DDRC_DDR_SDRAM_CFG_BI_MASK)

#define DDRC_DDR_SDRAM_CFG_MEM_HALT_MASK         (0x2U)
#define DDRC_DDR_SDRAM_CFG_MEM_HALT_SHIFT        (1U)
/*! MEM_HALT - DDRC Halt
 *  0b0..Accepts new transactions
 *  0b1..Completes any remaining transactions and remains halted until you write 0 to this field
 */
#define DDRC_DDR_SDRAM_CFG_MEM_HALT(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_MEM_HALT_SHIFT)) & DDRC_DDR_SDRAM_CFG_MEM_HALT_MASK)

#define DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_MASK     (0x7F00U)
#define DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_SHIFT    (8U)
/*! BA_INTLV_CTL - Rank Interleaving Control
 *  0b0000000..No external ranks are interleaved.
 *  0b1000000..External ranks 0 and 1 are interleaved.
 */
#define DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_SHIFT)) & DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_MASK)

#define DDRC_DDR_SDRAM_CFG_DBW_MASK              (0x180000U)
#define DDRC_DDR_SDRAM_CFG_DBW_SHIFT             (19U)
/*! DBW - DDR SDRAM Data Bus Width
 *  0b10..16 bits
 */
#define DDRC_DDR_SDRAM_CFG_DBW(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_DBW_SHIFT)) & DDRC_DDR_SDRAM_CFG_DBW_MASK)

#define DDRC_DDR_SDRAM_CFG_DYN_PWR_MASK          (0x200000U)
#define DDRC_DDR_SDRAM_CFG_DYN_PWR_SHIFT         (21U)
/*! DYN_PWR - Dynamic Power Management
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_DDR_SDRAM_CFG_DYN_PWR(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_DYN_PWR_SHIFT)) & DDRC_DDR_SDRAM_CFG_DYN_PWR_MASK)

#define DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK       (0x7000000U)
#define DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT      (24U)
/*! SDRAM_TYPE - DDR SDRAM Type
 *  0b100..LPDDR4X SDRAM
 */
#define DDRC_DDR_SDRAM_CFG_SDRAM_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT)) & DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK)

#define DDRC_DDR_SDRAM_CFG_SREN_MASK             (0x40000000U)
#define DDRC_DDR_SDRAM_CFG_SREN_SHIFT            (30U)
/*! SREN - Self-Refresh Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_DDR_SDRAM_CFG_SREN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_SREN_SHIFT)) & DDRC_DDR_SDRAM_CFG_SREN_MASK)

#define DDRC_DDR_SDRAM_CFG_MEM_EN_MASK           (0x80000000U)
#define DDRC_DDR_SDRAM_CFG_MEM_EN_SHIFT          (31U)
/*! MEM_EN - DDRC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_DDR_SDRAM_CFG_MEM_EN(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_MEM_EN_SHIFT)) & DDRC_DDR_SDRAM_CFG_MEM_EN_MASK)
/*! @} */

/*! @name DDR_SDRAM_CFG_2 - DDR SDRAM Control Configuration 2 */
/*! @{ */

#define DDRC_DDR_SDRAM_CFG_2_D_INIT_MASK         (0x10U)
#define DDRC_DDR_SDRAM_CFG_2_D_INIT_SHIFT        (4U)
/*! D_INIT - DDR SDRAM Data Initialization
 *  0b0..No data initialization in progress, and none scheduled
 *  0b1..DDRC to initialize the DDR SDRAM after DDRC is enabled
 */
#define DDRC_DDR_SDRAM_CFG_2_D_INIT(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_D_INIT_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_D_INIT_MASK)

#define DDRC_DDR_SDRAM_CFG_2_NUM_PR_MASK         (0xF000U)
#define DDRC_DDR_SDRAM_CFG_2_NUM_PR_SHIFT        (12U)
/*! NUM_PR - Number Of Posted Refreshes
 *  0b0000, 0b0001..1
 *  0b0010..2
 *  0b0011..3
 *  0b0100..4
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 */
#define DDRC_DDR_SDRAM_CFG_2_NUM_PR(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_NUM_PR_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_NUM_PR_MASK)

#define DDRC_DDR_SDRAM_CFG_2_MCK_DIS_MASK        (0xF000000U)
#define DDRC_DDR_SDRAM_CFG_2_MCK_DIS_SHIFT       (24U)
/*! MCK_DIS - MCK Disable */
#define DDRC_DDR_SDRAM_CFG_2_MCK_DIS(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_MCK_DIS_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_MCK_DIS_MASK)

#define DDRC_DDR_SDRAM_CFG_2_FRC_SR_MASK         (0x80000000U)
#define DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT        (31U)
/*! FRC_SR - Force Self-Refresh
 *  0b0..Normal mode
 *  0b1..Self-Refresh mode
 */
#define DDRC_DDR_SDRAM_CFG_2_FRC_SR(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT)) & DDRC_DDR_SDRAM_CFG_2_FRC_SR_MASK)
/*! @} */

/*! @name DDR_SDRAM_MD_CNTL - DDR SDRAM Mode Control */
/*! @{ */

#define DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_MASK     (0x3FFFFU)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_SHIFT    (0U)
/*! MD_VALUE - Mode Register Value */
#define DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_MD_VALUE_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_MASK     (0x300000U)
#define DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_SHIFT    (20U)
/*! CKE_CNTL - Clock Enable Control
 *  0b00..Not forced
 *  0b01..Forced to a lower value
 *  0b10..Forced to a higher value
 *  0b11..
 */
#define DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_MASK      (0x400000U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_SHIFT     (22U)
/*! SET_PRE - Set Precharge
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_DDR_SDRAM_MD_CNTL_SET_PRE(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_SET_PRE_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_SET_REF_MASK      (0x800000U)
#define DDRC_DDR_SDRAM_MD_CNTL_SET_REF_SHIFT     (23U)
/*! SET_REF - Set Refresh
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_DDR_SDRAM_MD_CNTL_SET_REF(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_SET_REF_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_SET_REF_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_MASK       (0xF000000U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_SHIFT      (24U)
/*! MD_SEL - Mode Register Select
 *  0b0000..MR
 *  0b0001..EMR
 *  0b0010..EMR2
 *  0b0011..EMR3
 */
#define DDRC_DDR_SDRAM_MD_CNTL_MD_SEL(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_MD_SEL_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_MASK       (0x70000000U)
#define DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_SHIFT      (28U)
/*! CS_SEL - Select Rank
 *  0b000..0
 *  0b001..1
 *  0b100..0 and 1
 */
#define DDRC_DDR_SDRAM_MD_CNTL_CS_SEL(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_CS_SEL_MASK)

#define DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK        (0x80000000U)
#define DDRC_DDR_SDRAM_MD_CNTL_MD_EN_SHIFT       (31U)
/*! MD_EN - Mode Enable
 *  0b0..Does not need to be issued
 *  0b1..Valid data contained in the register ready to be issued as an MRW command
 */
#define DDRC_DDR_SDRAM_MD_CNTL_MD_EN(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_MD_CNTL_MD_EN_SHIFT)) & DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK)
/*! @} */

/*! @name DDR_SDRAM_INTERVAL - DDR SDRAM Interval Configuration */
/*! @{ */

#define DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_MASK     (0x3FFFU)
#define DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_SHIFT    (0U)
/*! BSTOPRE - Precharge Interval */
#define DDRC_DDR_SDRAM_INTERVAL_BSTOPRE(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_SHIFT)) & DDRC_DDR_SDRAM_INTERVAL_BSTOPRE_MASK)

#define DDRC_DDR_SDRAM_INTERVAL_REFINT_MASK      (0xFFFF0000U)
#define DDRC_DDR_SDRAM_INTERVAL_REFINT_SHIFT     (16U)
/*! REFINT - Refresh Interval */
#define DDRC_DDR_SDRAM_INTERVAL_REFINT(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_INTERVAL_REFINT_SHIFT)) & DDRC_DDR_SDRAM_INTERVAL_REFINT_MASK)
/*! @} */

/*! @name DDR_DATA_INIT - DDR SDRAM Data Initialization */
/*! @{ */

#define DDRC_DDR_DATA_INIT_INIT_VALUE_MASK       (0xFFFFFFFFU)
#define DDRC_DDR_DATA_INIT_INIT_VALUE_SHIFT      (0U)
/*! INIT_VALUE - Initialization Value */
#define DDRC_DDR_DATA_INIT_INIT_VALUE(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_DATA_INIT_INIT_VALUE_SHIFT)) & DDRC_DDR_DATA_INIT_INIT_VALUE_MASK)
/*! @} */

/*! @name TIMING_CFG_4 - DDR SDRAM Timing Configuration 4 */
/*! @{ */

#define DDRC_TIMING_CFG_4_DLL_LOCK_MASK          (0x3U)
#define DDRC_TIMING_CFG_4_DLL_LOCK_SHIFT         (0U)
/*! DLL_LOCK - DDR SDRAM DLL Lock Time
 *  0b10..1024 clocks
 *  0b11..2048 clocks
 */
#define DDRC_TIMING_CFG_4_DLL_LOCK(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_DLL_LOCK_SHIFT)) & DDRC_TIMING_CFG_4_DLL_LOCK_MASK)

#define DDRC_TIMING_CFG_4_EXT_REFINT_MASK        (0x10U)
#define DDRC_TIMING_CFG_4_EXT_REFINT_SHIFT       (4U)
/*! EXT_REFINT - Extended Refresh Interval
 *  0b0..0
 *  0b1..65,536
 */
#define DDRC_TIMING_CFG_4_EXT_REFINT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_REFINT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_REFINT_MASK)

#define DDRC_TIMING_CFG_4_EXT_WWT_MASK           (0x300U)
#define DDRC_TIMING_CFG_4_EXT_WWT_SHIFT          (8U)
/*! EXT_WWT - Extended Write-To-Write Turnaround */
#define DDRC_TIMING_CFG_4_EXT_WWT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_WWT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_WWT_MASK)

#define DDRC_TIMING_CFG_4_EXT_RRT_MASK           (0xC00U)
#define DDRC_TIMING_CFG_4_EXT_RRT_SHIFT          (10U)
/*! EXT_RRT - Extended Read-To-Read Turnaround */
#define DDRC_TIMING_CFG_4_EXT_RRT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_RRT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_RRT_MASK)

#define DDRC_TIMING_CFG_4_EXT_WRT_MASK           (0x3000U)
#define DDRC_TIMING_CFG_4_EXT_WRT_SHIFT          (12U)
/*! EXT_WRT - Extended Write-To-Read Turnaround */
#define DDRC_TIMING_CFG_4_EXT_WRT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_WRT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_WRT_MASK)

#define DDRC_TIMING_CFG_4_EXT_RWT_MASK           (0xC000U)
#define DDRC_TIMING_CFG_4_EXT_RWT_SHIFT          (14U)
/*! EXT_RWT - Extended Read-To-Write Turnaround */
#define DDRC_TIMING_CFG_4_EXT_RWT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_EXT_RWT_SHIFT)) & DDRC_TIMING_CFG_4_EXT_RWT_MASK)

#define DDRC_TIMING_CFG_4_WWT_MASK               (0xF0000U)
#define DDRC_TIMING_CFG_4_WWT_SHIFT              (16U)
/*! WWT - Write-To-Write Turnaround For Same Rank */
#define DDRC_TIMING_CFG_4_WWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_WWT_SHIFT)) & DDRC_TIMING_CFG_4_WWT_MASK)

#define DDRC_TIMING_CFG_4_RRT_MASK               (0xF00000U)
#define DDRC_TIMING_CFG_4_RRT_SHIFT              (20U)
/*! RRT - Read-To-Read Turnaround For Same Rank */
#define DDRC_TIMING_CFG_4_RRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_RRT_SHIFT)) & DDRC_TIMING_CFG_4_RRT_MASK)

#define DDRC_TIMING_CFG_4_WRT_MASK               (0xF000000U)
#define DDRC_TIMING_CFG_4_WRT_SHIFT              (24U)
/*! WRT - Write-To-Read Turnaround For Same Rank */
#define DDRC_TIMING_CFG_4_WRT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_WRT_SHIFT)) & DDRC_TIMING_CFG_4_WRT_MASK)

#define DDRC_TIMING_CFG_4_RWT_MASK               (0xF0000000U)
#define DDRC_TIMING_CFG_4_RWT_SHIFT              (28U)
/*! RWT - Read-To-Write Turnaround For Same Rank */
#define DDRC_TIMING_CFG_4_RWT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_4_RWT_SHIFT)) & DDRC_TIMING_CFG_4_RWT_MASK)
/*! @} */

/*! @name TIMING_CFG_7 - DDR SDRAM Timing Configuration 7 */
/*! @{ */

#define DDRC_TIMING_CFG_7_CKSRX_MASK             (0xF00000U)
#define DDRC_TIMING_CFG_7_CKSRX_SHIFT            (20U)
/*! CKSRX - Clock After Self-Refresh Exit
 *  0b0000, 0b1010..15
 *  0b0001..6
 *  0b0010..7
 *  0b0011..8
 *  0b0100..9
 *  0b0101..10
 *  0b0110..11
 *  0b0111..12
 *  0b1000..13
 *  0b1001..14
 *  0b1011..16
 *  0b1100..17
 *  0b1101..18
 *  0b1110..19
 *  0b1111..32
 */
#define DDRC_TIMING_CFG_7_CKSRX(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_7_CKSRX_SHIFT)) & DDRC_TIMING_CFG_7_CKSRX_MASK)

#define DDRC_TIMING_CFG_7_CKSRE_MASK             (0xF000000U)
#define DDRC_TIMING_CFG_7_CKSRE_SHIFT            (24U)
/*! CKSRE - Clock After Self-Refresh Entry
 *  0b0000, 0b1010..15
 *  0b0001..6
 *  0b0010..7
 *  0b0011..8
 *  0b0100..9
 *  0b0101..10
 *  0b0110..11
 *  0b0111..12
 *  0b1000..13
 *  0b1001..14
 *  0b1011..16
 *  0b1100..17
 *  0b1101..18
 *  0b1110..19
 *  0b1111..32
 */
#define DDRC_TIMING_CFG_7_CKSRE(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_7_CKSRE_SHIFT)) & DDRC_TIMING_CFG_7_CKSRE_MASK)

#define DDRC_TIMING_CFG_7_CKE_RST_MASK           (0x30000000U)
#define DDRC_TIMING_CFG_7_CKE_RST_SHIFT          (28U)
/*! CKE_RST - MCKE Reset Time
 *  0b00..200
 *  0b01..256
 *  0b10..512
 *  0b11..4096
 */
#define DDRC_TIMING_CFG_7_CKE_RST(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_7_CKE_RST_SHIFT)) & DDRC_TIMING_CFG_7_CKE_RST_MASK)
/*! @} */

/*! @name DDR_ZQ_CNTL - DDR SDRAM ZQ Calibration Control */
/*! @{ */

#define DDRC_DDR_ZQ_CNTL_ZQCS_INT_MASK           (0xFU)
#define DDRC_DDR_ZQ_CNTL_ZQCS_INT_SHIFT          (0U)
/*! ZQCS_INT - ZQCS Interval
 *  0b0000..32
 *  0b0001..64
 *  0b0010..128
 *  0b0011..256
 *  0b0100..512
 *  0b0101..1024
 *  0b0110..2048
 *  0b0111..4096
 *  0b1000..8192
 *  0b1001..16384
 *  0b1010..32768
 *  0b1111..ZQCS calibration disabled
 */
#define DDRC_DDR_ZQ_CNTL_ZQCS_INT(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQCS_INT_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQCS_INT_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQCS_MASK               (0xF00U)
#define DDRC_DDR_ZQ_CNTL_ZQCS_SHIFT              (8U)
/*! ZQCS - ZQ Calibration Short Time
 *  0b0000..1
 *  0b0001..2
 *  0b0010..4
 *  0b0011..8
 *  0b0100..16
 *  0b0101..32
 *  0b0110..64
 *  0b0111..128
 *  0b1000..256
 *  0b1001..512
 */
#define DDRC_DDR_ZQ_CNTL_ZQCS(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQCS_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQCS_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQOPER_MASK             (0xF0000U)
#define DDRC_DDR_ZQ_CNTL_ZQOPER_SHIFT            (16U)
/*! ZQOPER - ZQ Calibration Operation Time
 *  0b0111..128
 *  0b1000..256
 *  0b1001..512
 *  0b1010..1024
 *  0b1011..2048
 */
#define DDRC_DDR_ZQ_CNTL_ZQOPER(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQOPER_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQOPER_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQINIT_MASK             (0xF000000U)
#define DDRC_DDR_ZQ_CNTL_ZQINIT_SHIFT            (24U)
/*! ZQINIT - ZQ Calibration Initialization Time
 *  0b0111..128
 *  0b1000..256
 *  0b1001..512
 *  0b1010..1024
 *  0b1011..2048
 */
#define DDRC_DDR_ZQ_CNTL_ZQINIT(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQINIT_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQINIT_MASK)

#define DDRC_DDR_ZQ_CNTL_ZQ_EN_MASK              (0x80000000U)
#define DDRC_DDR_ZQ_CNTL_ZQ_EN_SHIFT             (31U)
/*! ZQ_EN - ZQ Calibration Enable
 *  0b0..Used
 *  0b1..Not used
 */
#define DDRC_DDR_ZQ_CNTL_ZQ_EN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_ZQ_CNTL_ZQ_EN_SHIFT)) & DDRC_DDR_ZQ_CNTL_ZQ_EN_MASK)
/*! @} */

/*! @name DDR_SR_CNTR - DDR SDRAM Self-Refresh Counter */
/*! @{ */

#define DDRC_DDR_SR_CNTR_SR_IT_MASK              (0xF0000U)
#define DDRC_DDR_SR_CNTR_SR_IT_SHIFT             (16U)
/*! SR_IT - Self-Refresh Idle Threshold */
#define DDRC_DDR_SR_CNTR_SR_IT(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SR_CNTR_SR_IT_SHIFT)) & DDRC_DDR_SR_CNTR_SR_IT_MASK)
/*! @} */

/*! @name TIMING_CFG_8 - DDR SDRAM Timing Configuration 8 */
/*! @{ */

#define DDRC_TIMING_CFG_8_PRE_ALL_REC_MASK       (0x3FU)
#define DDRC_TIMING_CFG_8_PRE_ALL_REC_SHIFT      (0U)
/*! PRE_ALL_REC - Precharge All-To-Activate Interval */
#define DDRC_TIMING_CFG_8_PRE_ALL_REC(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_8_PRE_ALL_REC_SHIFT)) & DDRC_TIMING_CFG_8_PRE_ALL_REC_MASK)
/*! @} */

/*! @name TIMING_CFG_9 - DDR SDRAM timing configuration 9 */
/*! @{ */

#define DDRC_TIMING_CFG_9_REFTOREF_PB_MASK       (0x3FFU)
#define DDRC_TIMING_CFG_9_REFTOREF_PB_SHIFT      (0U)
/*! REFTOREF_PB - Refresh-to-refresh interval for per-bank refresh.
 *  0b0000000000..disable PB refresh
 *  0b0000000001..9 clocks
 *  0b0000000010..10 clocks
 *  0b1011111110..774 clocks
 *  0b1011111111..775 clocks
 */
#define DDRC_TIMING_CFG_9_REFTOREF_PB(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_9_REFTOREF_PB_SHIFT)) & DDRC_TIMING_CFG_9_REFTOREF_PB_MASK)

#define DDRC_TIMING_CFG_9_REFREC_PB_MASK         (0x3FF0000U)
#define DDRC_TIMING_CFG_9_REFREC_PB_SHIFT        (16U)
/*! REFREC_PB - Refresh Recovery Per-Bank Refresh
 *  0b0000000000..8 clocks
 *  0b0000000001..9 clocks
 *  0b0000000010..10 clocks
 *  0b1011111110..774 clocks
 *  0b1011111111..775 clocks
 */
#define DDRC_TIMING_CFG_9_REFREC_PB(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_9_REFREC_PB_SHIFT)) & DDRC_TIMING_CFG_9_REFREC_PB_MASK)
/*! @} */

/*! @name TIMING_CFG_10 - DDR SDRAM Timing Configuration 10 */
/*! @{ */

#define DDRC_TIMING_CFG_10_T_STAB_MASK           (0x7FFFU)
#define DDRC_TIMING_CFG_10_T_STAB_SHIFT          (0U)
/*! T_STAB - Stabilization Wait Time */
#define DDRC_TIMING_CFG_10_T_STAB(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_10_T_STAB_SHIFT)) & DDRC_TIMING_CFG_10_T_STAB_MASK)
/*! @} */

/*! @name TIMING_CFG_11 - DDR SDRAM Timing Configuration 11 */
/*! @{ */

#define DDRC_TIMING_CFG_11_MWWT_MASK             (0xFU)
#define DDRC_TIMING_CFG_11_MWWT_SHIFT            (0U)
/*! MWWT - Masked Write-To-Write Turnaround (tCCDMW) */
#define DDRC_TIMING_CFG_11_MWWT(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_11_MWWT_SHIFT)) & DDRC_TIMING_CFG_11_MWWT_MASK)

#define DDRC_TIMING_CFG_11_PRE_TO_PRE_MASK       (0xF00U)
#define DDRC_TIMING_CFG_11_PRE_TO_PRE_SHIFT      (8U)
/*! PRE_TO_PRE - Precharge-To-Precharge Time
 *  0b0000, 0b0100..4
 *  0b0001..1
 *  0b0010..2
 *  0b0011..3
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 *  0b1001..9
 *  0b1010..10
 *  0b1011..11
 *  0b1100..12
 *  0b1101..13
 *  0b1110..14
 *  0b1111..15
 */
#define DDRC_TIMING_CFG_11_PRE_TO_PRE(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_11_PRE_TO_PRE_SHIFT)) & DDRC_TIMING_CFG_11_PRE_TO_PRE_MASK)
/*! @} */

/*! @name DDR_SDRAM_CFG_3 - DDR SDRAM Control Configuration 3 */
/*! @{ */

#define DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_MASK  (0x2U)
#define DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_SHIFT (1U)
/*! SR_FAST_WK_EN - Self Refresh Fast Wakeup Enable
 *  0b0..Slow
 *  0b1..Fast
 */
#define DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_MASK)

#define DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_MASK      (0x8U)
#define DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_SHIFT     (3U)
/*! NON_PWR_2 - Non Power of 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_DDR_SDRAM_CFG_3_NON_PWR_2(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_NON_PWR_2_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_MASK (0x80U)
#define DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_SHIFT (7U)
/*! DYN_REF_RATE_EN - Dynamic Refresh Rate Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_MASK   (0x800U)
#define DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_SHIFT  (11U)
/*! DRAIN_FOR_SR - Drain Queues For Self-Refresh
 *  0b0..Do not drain
 *  0b1..Drain
 */
#define DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DRAIN_FOR_SR_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DM_CFG_MASK         (0x7000U)
#define DDRC_DDR_SDRAM_CFG_3_DM_CFG_SHIFT        (12U)
/*! DM_CFG - Data Mask Configuration
 *  0b000..Normal data masks based on the settings defined in DDR_SDRAM_CFG[SDRAM_TYPE]
 *  0b010..DBI
 *  0b011..Neither data masks nor DBI
 *  0b100..DBI with data masks
 */
#define DDRC_DDR_SDRAM_CFG_3_DM_CFG(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DM_CFG_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DM_CFG_MASK)

#define DDRC_DDR_SDRAM_CFG_3_DDRC_RST_MASK       (0x80000000U)
#define DDRC_DDR_SDRAM_CFG_3_DDRC_RST_SHIFT      (31U)
/*! DDRC_RST - DDRC Reset
 *  0b0..Operating normally
 *  0b1..Undergoing reset
 */
#define DDRC_DDR_SDRAM_CFG_3_DDRC_RST(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_3_DDRC_RST_SHIFT)) & DDRC_DDR_SDRAM_CFG_3_DDRC_RST_MASK)
/*! @} */

/*! @name DDR_SDRAM_CFG_4 - DDR SDRAM Control Configuration 4 */
/*! @{ */

#define DDRC_DDR_SDRAM_CFG_4_FRQCH_RET_MASK      (0x1F000U)
#define DDRC_DDR_SDRAM_CFG_4_FRQCH_RET_SHIFT     (12U)
/*! FRQCH_RET - Frequency Change and Retention Setup */
#define DDRC_DDR_SDRAM_CFG_4_FRQCH_RET(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_CFG_4_FRQCH_RET_SHIFT)) & DDRC_DDR_SDRAM_CFG_4_FRQCH_RET_MASK)
/*! @} */

/*! @name DDR_SDRAM_REF_RATE - DDR Refresh Rate */
/*! @{ */

#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_MASK (0xFFU)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_SHIFT (0U)
/*! REF_RATE_CS1 - Refresh Rate Rank 1 */
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_SHIFT)) & DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_MASK)

#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_MASK (0xFF00U)
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_SHIFT (8U)
/*! REF_RATE_CS0 - Refresh Rate Rank 0 */
#define DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_SHIFT)) & DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_MASK)
/*! @} */

/*! @name TIMING_CFG_12 - DDR SDRAM Timing Configuration 12 */
/*! @{ */

#define DDRC_TIMING_CFG_12_CASLAT_HS_MASK        (0x3FU)
#define DDRC_TIMING_CFG_12_CASLAT_HS_SHIFT       (0U)
/*! CASLAT_HS - CAS Latency For Half Speed */
#define DDRC_TIMING_CFG_12_CASLAT_HS(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_12_CASLAT_HS_SHIFT)) & DDRC_TIMING_CFG_12_CASLAT_HS_MASK)

#define DDRC_TIMING_CFG_12_ACTTORW_HS_MASK       (0x3F00U)
#define DDRC_TIMING_CFG_12_ACTTORW_HS_SHIFT      (8U)
/*! ACTTORW_HS - Activate To Read Or Write For Half Speed
 *  0b000000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_12_ACTTORW_HS(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_12_ACTTORW_HS_SHIFT)) & DDRC_TIMING_CFG_12_ACTTORW_HS_MASK)

#define DDRC_TIMING_CFG_12_ACTTOPRE_HS_MASK      (0x7F0000U)
#define DDRC_TIMING_CFG_12_ACTTOPRE_HS_SHIFT     (16U)
/*! ACTTOPRE_HS - Activate-To-Precharge Time For Half Speed */
#define DDRC_TIMING_CFG_12_ACTTOPRE_HS(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_12_ACTTOPRE_HS_SHIFT)) & DDRC_TIMING_CFG_12_ACTTOPRE_HS_MASK)

#define DDRC_TIMING_CFG_12_PRETOACT_HS_MASK      (0x3F000000U)
#define DDRC_TIMING_CFG_12_PRETOACT_HS_SHIFT     (24U)
/*! PRETOACT_HS - Precharge-To-Activate Time For Half Speed
 *  0b000000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_12_PRETOACT_HS(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_12_PRETOACT_HS_SHIFT)) & DDRC_TIMING_CFG_12_PRETOACT_HS_MASK)
/*! @} */

/*! @name TIMING_CFG_13 - DDR SDRAM Timing Configuration 13 */
/*! @{ */

#define DDRC_TIMING_CFG_13_ACTTOACT_HS_MASK      (0x1FU)
#define DDRC_TIMING_CFG_13_ACTTOACT_HS_SHIFT     (0U)
/*! ACTTOACT_HS - Activate-To-Activate Interval For Half Speed
 *  0b00000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_13_ACTTOACT_HS(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_13_ACTTOACT_HS_SHIFT)) & DDRC_TIMING_CFG_13_ACTTOACT_HS_MASK)

#define DDRC_TIMING_CFG_13_WRREC_HS_MASK         (0x3F00U)
#define DDRC_TIMING_CFG_13_WRREC_HS_SHIFT        (8U)
/*! WRREC_HS - Write Recovery For Half Speed
 *  0b000000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_13_WRREC_HS(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_13_WRREC_HS_SHIFT)) & DDRC_TIMING_CFG_13_WRREC_HS_MASK)

#define DDRC_TIMING_CFG_13_REFREC_HS_MASK        (0x3FF0000U)
#define DDRC_TIMING_CFG_13_REFREC_HS_SHIFT       (16U)
/*! REFREC_HS - Refresh Recovery For Half Speed */
#define DDRC_TIMING_CFG_13_REFREC_HS(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_13_REFREC_HS_SHIFT)) & DDRC_TIMING_CFG_13_REFREC_HS_MASK)
/*! @} */

/*! @name TIMING_CFG_14 - DDR SDRAM Timing Configuration 14 */
/*! @{ */

#define DDRC_TIMING_CFG_14_REFINT_HS_MASK        (0x1FFFFU)
#define DDRC_TIMING_CFG_14_REFINT_HS_SHIFT       (0U)
/*! REFINT_HS - Refresh Interval For Half Speed */
#define DDRC_TIMING_CFG_14_REFINT_HS(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_14_REFINT_HS_SHIFT)) & DDRC_TIMING_CFG_14_REFINT_HS_MASK)

#define DDRC_TIMING_CFG_14_RD_TO_PRE_HS_MASK     (0x7C0000U)
#define DDRC_TIMING_CFG_14_RD_TO_PRE_HS_SHIFT    (18U)
/*! RD_TO_PRE_HS - Read-To-Precharge Time For Half Speed
 *  0b00000..
 *  *..Clock cycles as defined in the description
 */
#define DDRC_TIMING_CFG_14_RD_TO_PRE_HS(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_14_RD_TO_PRE_HS_SHIFT)) & DDRC_TIMING_CFG_14_RD_TO_PRE_HS_MASK)

#define DDRC_TIMING_CFG_14_WRLAT_HS_MASK         (0x3F000000U)
#define DDRC_TIMING_CFG_14_WRLAT_HS_SHIFT        (24U)
/*! WRLAT_HS - Write Latency For Half Speed */
#define DDRC_TIMING_CFG_14_WRLAT_HS(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_TIMING_CFG_14_WRLAT_HS_SHIFT)) & DDRC_TIMING_CFG_14_WRLAT_HS_MASK)
/*! @} */

/*! @name TX_CFG_1 - Transaction Configuration Register 1 */
/*! @{ */

#define DDRC_TX_CFG_1_WWATER_MASK                (0xFU)
#define DDRC_TX_CFG_1_WWATER_SHIFT               (0U)
/*! WWATER - Write Watermark. */
#define DDRC_TX_CFG_1_WWATER(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_TX_CFG_1_WWATER_SHIFT)) & DDRC_TX_CFG_1_WWATER_MASK)

#define DDRC_TX_CFG_1_TS_DEPTH_MASK              (0xF80U)
#define DDRC_TX_CFG_1_TS_DEPTH_SHIFT             (7U)
/*! TS_DEPTH - Transaction Scheduler Depth */
#define DDRC_TX_CFG_1_TS_DEPTH(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_TX_CFG_1_TS_DEPTH_SHIFT)) & DDRC_TX_CFG_1_TS_DEPTH_MASK)
/*! @} */

/*! @name DDRDSR_2 - DDR SDRAM Debug Status 2 */
/*! @{ */

#define DDRC_DDRDSR_2_RPD_END_MASK               (0x1U)
#define DDRC_DDRDSR_2_RPD_END_SHIFT              (0U)
/*! RPD_END - Rapid Clear Of Memory End
 *  0b0..Not complete
 *  0b1..Complete
 */
#define DDRC_DDRDSR_2_RPD_END(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_RPD_END_SHIFT)) & DDRC_DDRDSR_2_RPD_END_MASK)

#define DDRC_DDRDSR_2_RPD_ST_MASK                (0x2U)
#define DDRC_DDRDSR_2_RPD_ST_SHIFT               (1U)
/*! RPD_ST - Rapid Clear Of Memory Start
 *  0b0..Not started
 *  0b1..Started
 */
#define DDRC_DDRDSR_2_RPD_ST(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_RPD_ST_SHIFT)) & DDRC_DDRDSR_2_RPD_ST_MASK)

#define DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK        (0x4U)
#define DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT       (2U)
/*! PHY_INIT_CMPLT - DDR PHY Initialization Complete
 *  0b0..Not complete
 *  0b1..Complete
 */
#define DDRC_DDRDSR_2_PHY_INIT_CMPLT(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT)) & DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK)

#define DDRC_DDRDSR_2_NML_MASK                   (0x40000000U)
#define DDRC_DDRDSR_2_NML_SHIFT                  (30U)
/*! NML - No Modified Lines
 *  0b0..Exist
 *  0b1..Do not exist
 */
#define DDRC_DDRDSR_2_NML(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_NML_SHIFT)) & DDRC_DDRDSR_2_NML_MASK)

#define DDRC_DDRDSR_2_IDLE_MASK                  (0x80000000U)
#define DDRC_DDRDSR_2_IDLE_SHIFT                 (31U)
/*! IDLE - Memory controller idle (read only).
 *  0b0..Memory controller is busy.
 *  0b1..Memory controller is idle.
 */
#define DDRC_DDRDSR_2_IDLE(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_DDRDSR_2_IDLE_SHIFT)) & DDRC_DDRDSR_2_IDLE_MASK)
/*! @} */

/*! @name DDR_IP_REV1 - DDRC Revision 1 */
/*! @{ */

#define DDRC_DDR_IP_REV1_IP_MN_MASK              (0xFFU)
#define DDRC_DDR_IP_REV1_IP_MN_SHIFT             (0U)
/*! IP_MN - Minor Revision */
#define DDRC_DDR_IP_REV1_IP_MN(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_IP_REV1_IP_MN_SHIFT)) & DDRC_DDR_IP_REV1_IP_MN_MASK)

#define DDRC_DDR_IP_REV1_IP_MJ_MASK              (0xFF00U)
#define DDRC_DDR_IP_REV1_IP_MJ_SHIFT             (8U)
/*! IP_MJ - Major Revision */
#define DDRC_DDR_IP_REV1_IP_MJ(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_IP_REV1_IP_MJ_SHIFT)) & DDRC_DDR_IP_REV1_IP_MJ_MASK)

#define DDRC_DDR_IP_REV1_IP_ID_MASK              (0xFFFF0000U)
#define DDRC_DDR_IP_REV1_IP_ID_SHIFT             (16U)
/*! IP_ID - IP Block ID */
#define DDRC_DDR_IP_REV1_IP_ID(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_IP_REV1_IP_ID_SHIFT)) & DDRC_DDR_IP_REV1_IP_ID_MASK)
/*! @} */

/*! @name DDR_MTCR - DDR SDRAM Memory Test Control */
/*! @{ */

#define DDRC_DDR_MTCR_MT_STAT_MASK               (0x1U)
#define DDRC_DDR_MTCR_MT_STAT_SHIFT              (0U)
/*! MT_STAT - Memory Test Status
 *  0b0..No fail detected
 *  0b1..Data miscompare detected
 */
#define DDRC_DDR_MTCR_MT_STAT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_STAT_SHIFT)) & DDRC_DDR_MTCR_MT_STAT_MASK)

#define DDRC_DDR_MTCR_MT_ADDR_EN_MASK            (0x200U)
#define DDRC_DDR_MTCR_MT_ADDR_EN_SHIFT           (9U)
/*! MT_ADDR_EN - Memory Test Address Range Enable
 *  0b0..Memory range that the CSn_BNDS registers define
 *  0b1..Memory range that the DDR_MT_ST_EXT_ADDR, DDR_MT_ST_ADDR, DDR_MT_END_EXT_ADDR, and DDR_MT_END_ADDR registers define
 */
#define DDRC_DDR_MTCR_MT_ADDR_EN(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_ADDR_EN_SHIFT)) & DDRC_DDR_MTCR_MT_ADDR_EN_MASK)

#define DDRC_DDR_MTCR_MT_TRNARND_MASK            (0xF0000U)
#define DDRC_DDR_MTCR_MT_TRNARND_SHIFT           (16U)
/*! MT_TRNARND - Memory Test Turnaround
 *  0b0000..Entire memory is written to before read transactions are issued.
 *  0b0001..Total write and read streams are one transaction each.
 *  0b0010..Total write and read streams are two transactions each.
 *  0b0011..Total write and read streams are four transactions each.
 */
#define DDRC_DDR_MTCR_MT_TRNARND(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_TRNARND_SHIFT)) & DDRC_DDR_MTCR_MT_TRNARND_MASK)

#define DDRC_DDR_MTCR_MT_TYP_MASK                (0x3000000U)
#define DDRC_DDR_MTCR_MT_TYP_SHIFT               (24U)
/*! MT_TYP - Memory Test Type
 *  0b00..Both writes and reads
 *  0b01..Only writes
 *  0b10..Only reads
 *  0b11..Reserved
 */
#define DDRC_DDR_MTCR_MT_TYP(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_TYP_SHIFT)) & DDRC_DDR_MTCR_MT_TYP_MASK)

#define DDRC_DDR_MTCR_MT_EN_MASK                 (0x80000000U)
#define DDRC_DDR_MTCR_MT_EN_SHIFT                (31U)
/*! MT_EN - Memory Test Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_DDR_MTCR_MT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTCR_MT_EN_SHIFT)) & DDRC_DDR_MTCR_MT_EN_MASK)
/*! @} */

/*! @name DDR_MTP - DDR SDRAM Memory Test Pattern n */
/*! @{ */

#define DDRC_DDR_MTP_DDR_PATT_MASK               (0xFFFFFFFFU)
#define DDRC_DDR_MTP_DDR_PATT_SHIFT              (0U)
/*! DDR_PATT - DDR SDRAM Pattern */
#define DDRC_DDR_MTP_DDR_PATT(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MTP_DDR_PATT_SHIFT)) & DDRC_DDR_MTP_DDR_PATT_MASK)
/*! @} */

/*! @name DDR_MT_ST_EXT_ADDR - DDR SDRAM Memory Test Start Extended Address */
/*! @{ */

#define DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_MASK (0xFFU)
#define DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_SHIFT (0U)
/*! MT_ST_EXT_ADDR - Memory Test Start Extended Address */
#define DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_SHIFT)) & DDRC_DDR_MT_ST_EXT_ADDR_MT_ST_EXT_ADDR_MASK)
/*! @} */

/*! @name DDR_MT_ST_ADDR - DDR SDRAM Memory Test Start Address */
/*! @{ */

#define DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_MASK      (0xFFFFFFFFU)
#define DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_SHIFT     (0U)
/*! MT_ST_ADDR - Memory Test Start Address */
#define DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_SHIFT)) & DDRC_DDR_MT_ST_ADDR_MT_ST_ADDR_MASK)
/*! @} */

/*! @name DDR_MT_END_EXT_ADDR - DDR SDRAM Memory Test End Extended Address */
/*! @{ */

#define DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_MASK (0xFFU)
#define DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_SHIFT (0U)
/*! MT_END_EXT_ADDR - Memory Test End Extended Address */
#define DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_SHIFT)) & DDRC_DDR_MT_END_EXT_ADDR_MT_END_EXT_ADDR_MASK)
/*! @} */

/*! @name DDR_MT_END_ADDR - DDR SDRAM Memory Test End Address */
/*! @{ */

#define DDRC_DDR_MT_END_ADDR_MT_END_ADDR_MASK    (0xFFFFFFFFU)
#define DDRC_DDR_MT_END_ADDR_MT_END_ADDR_SHIFT   (0U)
/*! MT_END_ADDR - Memory Test End Address */
#define DDRC_DDR_MT_END_ADDR_MT_END_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DDR_MT_END_ADDR_MT_END_ADDR_SHIFT)) & DDRC_DDR_MT_END_ADDR_MT_END_ADDR_MASK)
/*! @} */

/*! @name PMGC0 - Performance Monitor Global Control */
/*! @{ */

#define DDRC_PMGC0_FCECE_MASK                    (0x20000000U)
#define DDRC_PMGC0_FCECE_SHIFT                   (29U)
/*! FCECE - Freeze Counters On Enabled Condition Or Event
 *  0b0..Enabled if PMLCAn[CE] = 1, until an event or condition occurs.
 *  0b1..Enabled if PMLCAn[CE] = 1, until an event or condition occurs. At this point, if PMGC0[FAC] = 1, you must write 0 to it.
 */
#define DDRC_PMGC0_FCECE(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_PMGC0_FCECE_SHIFT)) & DDRC_PMGC0_FCECE_MASK)

#define DDRC_PMGC0_PMIE_MASK                     (0x40000000U)
#define DDRC_PMGC0_PMIE_SHIFT                    (30U)
/*! PMIE - Performance Monitor Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_PMGC0_PMIE(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMGC0_PMIE_SHIFT)) & DDRC_PMGC0_PMIE_MASK)

#define DDRC_PMGC0_FAC_MASK                      (0x80000000U)
#define DDRC_PMGC0_FAC_SHIFT                     (31U)
/*! FAC - Freeze All Counters
 *  0b0..Incremented
 *  0b1..Not incremented
 */
#define DDRC_PMGC0_FAC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMGC0_FAC_SHIFT)) & DDRC_PMGC0_FAC_MASK)
/*! @} */

/*! @name PMLCA0 - Performance Monitor Local Control A0 */
/*! @{ */

#define DDRC_PMLCA0_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA0_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions for PMC0n cannot occur (PMC0n cannot cause interrupts or freeze counters)
 *  0b1..Counter overflow conditions occur when the most-significant bit of PMC0n is 1
 */
#define DDRC_PMLCA0_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA0_CE_SHIFT)) & DDRC_PMLCA0_CE_MASK)

#define DDRC_PMLCA0_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA0_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA0_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA0_FC_SHIFT)) & DDRC_PMLCA0_FC_MASK)
/*! @} */

/*! @name PMLCB0 - Performance Monitor Local Control B0 */
/*! @{ */

#define DDRC_PMLCB0_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB0_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB0_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB0_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB0_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB0_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB0_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGONCNTL_SHIFT)) & DDRC_PMLCB0_TRIGONCNTL_MASK)

#define DDRC_PMLCB0_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB0_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB0_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB0_TRIGOFFSEL_MASK)

#define DDRC_PMLCB0_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB0_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB0_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB0_TRIGONSEL_SHIFT)) & DDRC_PMLCB0_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC0A - PMC 0a */
/*! @{ */

#define DDRC_PMC0A_PMC0_MASK                     (0xFFFFFFFFU)
#define DDRC_PMC0A_PMC0_SHIFT                    (0U)
/*! PMC0 - Counter 0 */
#define DDRC_PMC0A_PMC0(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMC0A_PMC0_SHIFT)) & DDRC_PMC0A_PMC0_MASK)
/*! @} */

/*! @name PMC0B - PMC 0b */
/*! @{ */

#define DDRC_PMC0B_PMC0_MASK                     (0xFFFFFFFFU)
#define DDRC_PMC0B_PMC0_SHIFT                    (0U)
/*! PMC0 - Counter 0 */
#define DDRC_PMC0B_PMC0(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMC0B_PMC0_SHIFT)) & DDRC_PMC0B_PMC0_MASK)
/*! @} */

/*! @name PMLCA1 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA1_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA1_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA1_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_BDIST_SHIFT)) & DDRC_PMLCA1_BDIST_MASK)

#define DDRC_PMLCA1_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA1_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA1_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_BGRAN_SHIFT)) & DDRC_PMLCA1_BGRAN_MASK)

#define DDRC_PMLCA1_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA1_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA1_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_BSIZE_SHIFT)) & DDRC_PMLCA1_BSIZE_MASK)

#define DDRC_PMLCA1_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA1_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA1_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_EVENT_SHIFT)) & DDRC_PMLCA1_EVENT_MASK)

#define DDRC_PMLCA1_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA1_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA1_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_CE_SHIFT)) & DDRC_PMLCA1_CE_MASK)

#define DDRC_PMLCA1_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA1_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA1_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA1_FC_SHIFT)) & DDRC_PMLCA1_FC_MASK)
/*! @} */

/*! @name PMLCB1 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB1_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB1_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB1_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_THRESHOLD_SHIFT)) & DDRC_PMLCB1_THRESHOLD_MASK)

#define DDRC_PMLCB1_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB1_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB1_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TBMULT_SHIFT)) & DDRC_PMLCB1_TBMULT_MASK)

#define DDRC_PMLCB1_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB1_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB1_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB1_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB1_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB1_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB1_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGONCNTL_SHIFT)) & DDRC_PMLCB1_TRIGONCNTL_MASK)

#define DDRC_PMLCB1_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB1_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB1_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB1_TRIGOFFSEL_MASK)

#define DDRC_PMLCB1_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB1_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB1_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB1_TRIGONSEL_SHIFT)) & DDRC_PMLCB1_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC1 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC1_PMC1_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC1_PMC1_SHIFT                     (0U)
/*! PMC1 - Event Count */
#define DDRC_PMC1_PMC1(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC1_PMC1_SHIFT)) & DDRC_PMC1_PMC1_MASK)
/*! @} */

/*! @name PMLCA2 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA2_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA2_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA2_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_BDIST_SHIFT)) & DDRC_PMLCA2_BDIST_MASK)

#define DDRC_PMLCA2_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA2_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA2_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_BGRAN_SHIFT)) & DDRC_PMLCA2_BGRAN_MASK)

#define DDRC_PMLCA2_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA2_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA2_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_BSIZE_SHIFT)) & DDRC_PMLCA2_BSIZE_MASK)

#define DDRC_PMLCA2_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA2_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA2_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_EVENT_SHIFT)) & DDRC_PMLCA2_EVENT_MASK)

#define DDRC_PMLCA2_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA2_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA2_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_CE_SHIFT)) & DDRC_PMLCA2_CE_MASK)

#define DDRC_PMLCA2_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA2_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA2_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA2_FC_SHIFT)) & DDRC_PMLCA2_FC_MASK)
/*! @} */

/*! @name PMLCB2 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB2_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB2_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB2_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_THRESHOLD_SHIFT)) & DDRC_PMLCB2_THRESHOLD_MASK)

#define DDRC_PMLCB2_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB2_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB2_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TBMULT_SHIFT)) & DDRC_PMLCB2_TBMULT_MASK)

#define DDRC_PMLCB2_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB2_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB2_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB2_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB2_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB2_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB2_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGONCNTL_SHIFT)) & DDRC_PMLCB2_TRIGONCNTL_MASK)

#define DDRC_PMLCB2_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB2_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB2_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB2_TRIGOFFSEL_MASK)

#define DDRC_PMLCB2_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB2_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB2_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB2_TRIGONSEL_SHIFT)) & DDRC_PMLCB2_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC2 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC2_PMC2_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC2_PMC2_SHIFT                     (0U)
/*! PMC2 - Event Count */
#define DDRC_PMC2_PMC2(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC2_PMC2_SHIFT)) & DDRC_PMC2_PMC2_MASK)
/*! @} */

/*! @name PMLCA3 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA3_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA3_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA3_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_BDIST_SHIFT)) & DDRC_PMLCA3_BDIST_MASK)

#define DDRC_PMLCA3_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA3_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA3_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_BGRAN_SHIFT)) & DDRC_PMLCA3_BGRAN_MASK)

#define DDRC_PMLCA3_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA3_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA3_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_BSIZE_SHIFT)) & DDRC_PMLCA3_BSIZE_MASK)

#define DDRC_PMLCA3_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA3_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA3_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_EVENT_SHIFT)) & DDRC_PMLCA3_EVENT_MASK)

#define DDRC_PMLCA3_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA3_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA3_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_CE_SHIFT)) & DDRC_PMLCA3_CE_MASK)

#define DDRC_PMLCA3_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA3_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA3_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA3_FC_SHIFT)) & DDRC_PMLCA3_FC_MASK)
/*! @} */

/*! @name PMLCB3 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB3_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB3_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB3_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_THRESHOLD_SHIFT)) & DDRC_PMLCB3_THRESHOLD_MASK)

#define DDRC_PMLCB3_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB3_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB3_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TBMULT_SHIFT)) & DDRC_PMLCB3_TBMULT_MASK)

#define DDRC_PMLCB3_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB3_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB3_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB3_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB3_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB3_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB3_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGONCNTL_SHIFT)) & DDRC_PMLCB3_TRIGONCNTL_MASK)

#define DDRC_PMLCB3_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB3_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB3_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB3_TRIGOFFSEL_MASK)

#define DDRC_PMLCB3_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB3_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB3_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB3_TRIGONSEL_SHIFT)) & DDRC_PMLCB3_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC3 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC3_PMC3_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC3_PMC3_SHIFT                     (0U)
/*! PMC3 - Event Count */
#define DDRC_PMC3_PMC3(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC3_PMC3_SHIFT)) & DDRC_PMC3_PMC3_MASK)
/*! @} */

/*! @name PMLCA4 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA4_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA4_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA4_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_BDIST_SHIFT)) & DDRC_PMLCA4_BDIST_MASK)

#define DDRC_PMLCA4_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA4_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA4_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_BGRAN_SHIFT)) & DDRC_PMLCA4_BGRAN_MASK)

#define DDRC_PMLCA4_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA4_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA4_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_BSIZE_SHIFT)) & DDRC_PMLCA4_BSIZE_MASK)

#define DDRC_PMLCA4_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA4_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA4_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_EVENT_SHIFT)) & DDRC_PMLCA4_EVENT_MASK)

#define DDRC_PMLCA4_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA4_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA4_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_CE_SHIFT)) & DDRC_PMLCA4_CE_MASK)

#define DDRC_PMLCA4_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA4_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA4_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA4_FC_SHIFT)) & DDRC_PMLCA4_FC_MASK)
/*! @} */

/*! @name PMLCB4 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB4_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB4_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB4_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_THRESHOLD_SHIFT)) & DDRC_PMLCB4_THRESHOLD_MASK)

#define DDRC_PMLCB4_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB4_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB4_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TBMULT_SHIFT)) & DDRC_PMLCB4_TBMULT_MASK)

#define DDRC_PMLCB4_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB4_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB4_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB4_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB4_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB4_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB4_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGONCNTL_SHIFT)) & DDRC_PMLCB4_TRIGONCNTL_MASK)

#define DDRC_PMLCB4_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB4_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB4_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB4_TRIGOFFSEL_MASK)

#define DDRC_PMLCB4_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB4_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB4_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB4_TRIGONSEL_SHIFT)) & DDRC_PMLCB4_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC4 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC4_PMC4_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC4_PMC4_SHIFT                     (0U)
/*! PMC4 - Event Count */
#define DDRC_PMC4_PMC4(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC4_PMC4_SHIFT)) & DDRC_PMC4_PMC4_MASK)
/*! @} */

/*! @name PMLCA5 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA5_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA5_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA5_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_BDIST_SHIFT)) & DDRC_PMLCA5_BDIST_MASK)

#define DDRC_PMLCA5_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA5_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA5_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_BGRAN_SHIFT)) & DDRC_PMLCA5_BGRAN_MASK)

#define DDRC_PMLCA5_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA5_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA5_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_BSIZE_SHIFT)) & DDRC_PMLCA5_BSIZE_MASK)

#define DDRC_PMLCA5_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA5_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA5_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_EVENT_SHIFT)) & DDRC_PMLCA5_EVENT_MASK)

#define DDRC_PMLCA5_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA5_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA5_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_CE_SHIFT)) & DDRC_PMLCA5_CE_MASK)

#define DDRC_PMLCA5_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA5_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA5_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA5_FC_SHIFT)) & DDRC_PMLCA5_FC_MASK)
/*! @} */

/*! @name PMLCB5 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB5_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB5_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB5_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_THRESHOLD_SHIFT)) & DDRC_PMLCB5_THRESHOLD_MASK)

#define DDRC_PMLCB5_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB5_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB5_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TBMULT_SHIFT)) & DDRC_PMLCB5_TBMULT_MASK)

#define DDRC_PMLCB5_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB5_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB5_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB5_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB5_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB5_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB5_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGONCNTL_SHIFT)) & DDRC_PMLCB5_TRIGONCNTL_MASK)

#define DDRC_PMLCB5_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB5_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB5_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB5_TRIGOFFSEL_MASK)

#define DDRC_PMLCB5_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB5_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB5_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB5_TRIGONSEL_SHIFT)) & DDRC_PMLCB5_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC5 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC5_PMC5_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC5_PMC5_SHIFT                     (0U)
/*! PMC5 - Event Count */
#define DDRC_PMC5_PMC5(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC5_PMC5_SHIFT)) & DDRC_PMC5_PMC5_MASK)
/*! @} */

/*! @name PMLCA6 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA6_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA6_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA6_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_BDIST_SHIFT)) & DDRC_PMLCA6_BDIST_MASK)

#define DDRC_PMLCA6_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA6_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA6_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_BGRAN_SHIFT)) & DDRC_PMLCA6_BGRAN_MASK)

#define DDRC_PMLCA6_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA6_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA6_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_BSIZE_SHIFT)) & DDRC_PMLCA6_BSIZE_MASK)

#define DDRC_PMLCA6_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA6_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA6_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_EVENT_SHIFT)) & DDRC_PMLCA6_EVENT_MASK)

#define DDRC_PMLCA6_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA6_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA6_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_CE_SHIFT)) & DDRC_PMLCA6_CE_MASK)

#define DDRC_PMLCA6_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA6_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA6_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA6_FC_SHIFT)) & DDRC_PMLCA6_FC_MASK)
/*! @} */

/*! @name PMLCB6 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB6_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB6_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB6_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_THRESHOLD_SHIFT)) & DDRC_PMLCB6_THRESHOLD_MASK)

#define DDRC_PMLCB6_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB6_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB6_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TBMULT_SHIFT)) & DDRC_PMLCB6_TBMULT_MASK)

#define DDRC_PMLCB6_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB6_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB6_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB6_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB6_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB6_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB6_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGONCNTL_SHIFT)) & DDRC_PMLCB6_TRIGONCNTL_MASK)

#define DDRC_PMLCB6_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB6_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB6_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB6_TRIGOFFSEL_MASK)

#define DDRC_PMLCB6_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB6_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB6_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB6_TRIGONSEL_SHIFT)) & DDRC_PMLCB6_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC6 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC6_PMC6_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC6_PMC6_SHIFT                     (0U)
/*! PMC6 - Event Count */
#define DDRC_PMC6_PMC6(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC6_PMC6_SHIFT)) & DDRC_PMC6_PMC6_MASK)
/*! @} */

/*! @name PMLCA7 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA7_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA7_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA7_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_BDIST_SHIFT)) & DDRC_PMLCA7_BDIST_MASK)

#define DDRC_PMLCA7_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA7_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA7_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_BGRAN_SHIFT)) & DDRC_PMLCA7_BGRAN_MASK)

#define DDRC_PMLCA7_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA7_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA7_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_BSIZE_SHIFT)) & DDRC_PMLCA7_BSIZE_MASK)

#define DDRC_PMLCA7_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA7_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA7_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_EVENT_SHIFT)) & DDRC_PMLCA7_EVENT_MASK)

#define DDRC_PMLCA7_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA7_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA7_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_CE_SHIFT)) & DDRC_PMLCA7_CE_MASK)

#define DDRC_PMLCA7_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA7_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA7_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA7_FC_SHIFT)) & DDRC_PMLCA7_FC_MASK)
/*! @} */

/*! @name PMLCB7 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB7_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB7_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB7_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_THRESHOLD_SHIFT)) & DDRC_PMLCB7_THRESHOLD_MASK)

#define DDRC_PMLCB7_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB7_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB7_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TBMULT_SHIFT)) & DDRC_PMLCB7_TBMULT_MASK)

#define DDRC_PMLCB7_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB7_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB7_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB7_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB7_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB7_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB7_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGONCNTL_SHIFT)) & DDRC_PMLCB7_TRIGONCNTL_MASK)

#define DDRC_PMLCB7_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB7_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB7_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB7_TRIGOFFSEL_MASK)

#define DDRC_PMLCB7_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB7_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB7_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB7_TRIGONSEL_SHIFT)) & DDRC_PMLCB7_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC7 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC7_PMC7_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC7_PMC7_SHIFT                     (0U)
/*! PMC7 - Event Count */
#define DDRC_PMC7_PMC7(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC7_PMC7_SHIFT)) & DDRC_PMC7_PMC7_MASK)
/*! @} */

/*! @name PMLCA8 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA8_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA8_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA8_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_BDIST_SHIFT)) & DDRC_PMLCA8_BDIST_MASK)

#define DDRC_PMLCA8_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA8_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA8_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_BGRAN_SHIFT)) & DDRC_PMLCA8_BGRAN_MASK)

#define DDRC_PMLCA8_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA8_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA8_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_BSIZE_SHIFT)) & DDRC_PMLCA8_BSIZE_MASK)

#define DDRC_PMLCA8_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA8_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA8_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_EVENT_SHIFT)) & DDRC_PMLCA8_EVENT_MASK)

#define DDRC_PMLCA8_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA8_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA8_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_CE_SHIFT)) & DDRC_PMLCA8_CE_MASK)

#define DDRC_PMLCA8_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA8_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA8_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA8_FC_SHIFT)) & DDRC_PMLCA8_FC_MASK)
/*! @} */

/*! @name PMLCB8 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB8_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB8_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB8_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_THRESHOLD_SHIFT)) & DDRC_PMLCB8_THRESHOLD_MASK)

#define DDRC_PMLCB8_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB8_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB8_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TBMULT_SHIFT)) & DDRC_PMLCB8_TBMULT_MASK)

#define DDRC_PMLCB8_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB8_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB8_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB8_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB8_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB8_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB8_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGONCNTL_SHIFT)) & DDRC_PMLCB8_TRIGONCNTL_MASK)

#define DDRC_PMLCB8_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB8_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB8_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB8_TRIGOFFSEL_MASK)

#define DDRC_PMLCB8_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB8_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB8_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB8_TRIGONSEL_SHIFT)) & DDRC_PMLCB8_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC8 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC8_PMC8_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC8_PMC8_SHIFT                     (0U)
/*! PMC8 - Event Count */
#define DDRC_PMC8_PMC8(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC8_PMC8_SHIFT)) & DDRC_PMC8_PMC8_MASK)
/*! @} */

/*! @name PMLCA9 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA9_BDIST_MASK                   (0x3FU)
#define DDRC_PMLCA9_BDIST_SHIFT                  (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA9_BDIST(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_BDIST_SHIFT)) & DDRC_PMLCA9_BDIST_MASK)

#define DDRC_PMLCA9_BGRAN_MASK                   (0x7C0U)
#define DDRC_PMLCA9_BGRAN_SHIFT                  (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA9_BGRAN(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_BGRAN_SHIFT)) & DDRC_PMLCA9_BGRAN_MASK)

#define DDRC_PMLCA9_BSIZE_MASK                   (0xF800U)
#define DDRC_PMLCA9_BSIZE_SHIFT                  (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA9_BSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_BSIZE_SHIFT)) & DDRC_PMLCA9_BSIZE_MASK)

#define DDRC_PMLCA9_EVENT_MASK                   (0x7F0000U)
#define DDRC_PMLCA9_EVENT_SHIFT                  (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA9_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_EVENT_SHIFT)) & DDRC_PMLCA9_EVENT_MASK)

#define DDRC_PMLCA9_CE_MASK                      (0x4000000U)
#define DDRC_PMLCA9_CE_SHIFT                     (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA9_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_CE_SHIFT)) & DDRC_PMLCA9_CE_MASK)

#define DDRC_PMLCA9_FC_MASK                      (0x80000000U)
#define DDRC_PMLCA9_FC_SHIFT                     (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA9_FC(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA9_FC_SHIFT)) & DDRC_PMLCA9_FC_MASK)
/*! @} */

/*! @name PMLCB9 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB9_THRESHOLD_MASK               (0x3FU)
#define DDRC_PMLCB9_THRESHOLD_SHIFT              (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB9_THRESHOLD(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_THRESHOLD_SHIFT)) & DDRC_PMLCB9_THRESHOLD_MASK)

#define DDRC_PMLCB9_TBMULT_MASK                  (0x700U)
#define DDRC_PMLCB9_TBMULT_SHIFT                 (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB9_TBMULT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TBMULT_SHIFT)) & DDRC_PMLCB9_TBMULT_MASK)

#define DDRC_PMLCB9_TRIGOFFCNTL_MASK             (0x30000U)
#define DDRC_PMLCB9_TRIGOFFCNTL_SHIFT            (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB9_TRIGOFFCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB9_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB9_TRIGONCNTL_MASK              (0xC0000U)
#define DDRC_PMLCB9_TRIGONCNTL_SHIFT             (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB9_TRIGONCNTL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGONCNTL_SHIFT)) & DDRC_PMLCB9_TRIGONCNTL_MASK)

#define DDRC_PMLCB9_TRIGOFFSEL_MASK              (0xF00000U)
#define DDRC_PMLCB9_TRIGOFFSEL_SHIFT             (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB9_TRIGOFFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB9_TRIGOFFSEL_MASK)

#define DDRC_PMLCB9_TRIGONSEL_MASK               (0x3C000000U)
#define DDRC_PMLCB9_TRIGONSEL_SHIFT              (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB9_TRIGONSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB9_TRIGONSEL_SHIFT)) & DDRC_PMLCB9_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC9 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC9_PMC9_MASK                      (0xFFFFFFFFU)
#define DDRC_PMC9_PMC9_SHIFT                     (0U)
/*! PMC9 - Event Count */
#define DDRC_PMC9_PMC9(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_PMC9_PMC9_SHIFT)) & DDRC_PMC9_PMC9_MASK)
/*! @} */

/*! @name PMLCA10 - Performance Monitor Local Control A */
/*! @{ */

#define DDRC_PMLCA10_BDIST_MASK                  (0x3FU)
#define DDRC_PMLCA10_BDIST_SHIFT                 (0U)
/*! BDIST - Burst Distance */
#define DDRC_PMLCA10_BDIST(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_BDIST_SHIFT)) & DDRC_PMLCA10_BDIST_MASK)

#define DDRC_PMLCA10_BGRAN_MASK                  (0x7C0U)
#define DDRC_PMLCA10_BGRAN_SHIFT                 (6U)
/*! BGRAN - Burst Granularity */
#define DDRC_PMLCA10_BGRAN(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_BGRAN_SHIFT)) & DDRC_PMLCA10_BGRAN_MASK)

#define DDRC_PMLCA10_BSIZE_MASK                  (0xF800U)
#define DDRC_PMLCA10_BSIZE_SHIFT                 (11U)
/*! BSIZE - Burst Size */
#define DDRC_PMLCA10_BSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_BSIZE_SHIFT)) & DDRC_PMLCA10_BSIZE_MASK)

#define DDRC_PMLCA10_EVENT_MASK                  (0x7F0000U)
#define DDRC_PMLCA10_EVENT_SHIFT                 (16U)
/*! EVENT - Event Selector */
#define DDRC_PMLCA10_EVENT(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_EVENT_SHIFT)) & DDRC_PMLCA10_EVENT_MASK)

#define DDRC_PMLCA10_CE_MASK                     (0x4000000U)
#define DDRC_PMLCA10_CE_SHIFT                    (26U)
/*! CE - Condition Enable
 *  0b0..Counter overflow conditions cannot occur
 *  0b1..Counter overflow conditions occur
 */
#define DDRC_PMLCA10_CE(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_CE_SHIFT)) & DDRC_PMLCA10_CE_MASK)

#define DDRC_PMLCA10_FC_MASK                     (0x80000000U)
#define DDRC_PMLCA10_FC_SHIFT                    (31U)
/*! FC - Freeze Counter
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DDRC_PMLCA10_FC(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCA10_FC_SHIFT)) & DDRC_PMLCA10_FC_MASK)
/*! @} */

/*! @name PMLCB10 - Performance Monitor Local Control B */
/*! @{ */

#define DDRC_PMLCB10_THRESHOLD_MASK              (0x3FU)
#define DDRC_PMLCB10_THRESHOLD_SHIFT             (0U)
/*! THRESHOLD - Threshold */
#define DDRC_PMLCB10_THRESHOLD(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_THRESHOLD_SHIFT)) & DDRC_PMLCB10_THRESHOLD_MASK)

#define DDRC_PMLCB10_TBMULT_MASK                 (0x700U)
#define DDRC_PMLCB10_TBMULT_SHIFT                (8U)
/*! TBMULT - Threshold And Burstiness Multiplier
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define DDRC_PMLCB10_TBMULT(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TBMULT_SHIFT)) & DDRC_PMLCB10_TBMULT_MASK)

#define DDRC_PMLCB10_TRIGOFFCNTL_MASK            (0x30000U)
#define DDRC_PMLCB10_TRIGOFFCNTL_SHIFT           (16U)
/*! TRIGOFFCNTL - Trigger-Off Control
 *  0b00..Trigger off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB10_TRIGOFFCNTL(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGOFFCNTL_SHIFT)) & DDRC_PMLCB10_TRIGOFFCNTL_MASK)

#define DDRC_PMLCB10_TRIGONCNTL_MASK             (0xC0000U)
#define DDRC_PMLCB10_TRIGONCNTL_SHIFT            (18U)
/*! TRIGONCNTL - Trigger-On Control
 *  0b00..Triggering off (no triggering to start)
 *  0b01..Trigger on change
 *  0b10..Trigger on overflow
 *  0b11..Reserved
 */
#define DDRC_PMLCB10_TRIGONCNTL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGONCNTL_SHIFT)) & DDRC_PMLCB10_TRIGONCNTL_MASK)

#define DDRC_PMLCB10_TRIGOFFSEL_MASK             (0xF00000U)
#define DDRC_PMLCB10_TRIGOFFSEL_SHIFT            (20U)
/*! TRIGOFFSEL - Trigger-Off Select */
#define DDRC_PMLCB10_TRIGOFFSEL(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGOFFSEL_SHIFT)) & DDRC_PMLCB10_TRIGOFFSEL_MASK)

#define DDRC_PMLCB10_TRIGONSEL_MASK              (0x3C000000U)
#define DDRC_PMLCB10_TRIGONSEL_SHIFT             (26U)
/*! TRIGONSEL - Trigger-On Select */
#define DDRC_PMLCB10_TRIGONSEL(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PMLCB10_TRIGONSEL_SHIFT)) & DDRC_PMLCB10_TRIGONSEL_MASK)
/*! @} */

/*! @name PMC10 - Performance Monitor Counter */
/*! @{ */

#define DDRC_PMC10_PMC10_MASK                    (0xFFFFFFFFU)
#define DDRC_PMC10_PMC10_SHIFT                   (0U)
/*! PMC10 - Event Count */
#define DDRC_PMC10_PMC10(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_PMC10_PMC10_SHIFT)) & DDRC_PMC10_PMC10_MASK)
/*! @} */

/*! @name ERR_EN - Error Enable */
/*! @{ */

#define DDRC_ERR_EN_ECC_EN_RAM_2_MASK            (0x40U)
#define DDRC_ERR_EN_ECC_EN_RAM_2_SHIFT           (6U)
/*! ECC_EN_RAM_2 - ECC Enable For On-Chip RAM 2
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_ERR_EN_ECC_EN_RAM_2(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_ECC_EN_RAM_2_SHIFT)) & DDRC_ERR_EN_ECC_EN_RAM_2_MASK)

#define DDRC_ERR_EN_ECC_EN_RAM_1_MASK            (0x80U)
#define DDRC_ERR_EN_ECC_EN_RAM_1_SHIFT           (7U)
/*! ECC_EN_RAM_1 - ECC Enable For On-Chip RAM 1
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_ERR_EN_ECC_EN_RAM_1(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_ECC_EN_RAM_1_SHIFT)) & DDRC_ERR_EN_ECC_EN_RAM_1_MASK)

#define DDRC_ERR_EN_INLINE_ECC_EN_MASK           (0x40000000U)
#define DDRC_ERR_EN_INLINE_ECC_EN_SHIFT          (30U)
/*! INLINE_ECC_EN - Inline ECC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_ERR_EN_INLINE_ECC_EN(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_INLINE_ECC_EN_SHIFT)) & DDRC_ERR_EN_INLINE_ECC_EN_MASK)

#define DDRC_ERR_EN_ECC_EN_MASK                  (0x80000000U)
#define DDRC_ERR_EN_ECC_EN_SHIFT                 (31U)
/*! ECC_EN - ECC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_ERR_EN_ECC_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_EN_ECC_EN_SHIFT)) & DDRC_ERR_EN_ECC_EN_MASK)
/*! @} */

/*! @name DATA_ERR_INJECT_HI - Memory Data Path Error Injection Mask High */
/*! @{ */

#define DDRC_DATA_ERR_INJECT_HI_EIMH_MASK        (0xFFFFFFFFU)
#define DDRC_DATA_ERR_INJECT_HI_EIMH_SHIFT       (0U)
/*! EIMH - Error Injection Mask High Data Path */
#define DDRC_DATA_ERR_INJECT_HI_EIMH(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DATA_ERR_INJECT_HI_EIMH_SHIFT)) & DDRC_DATA_ERR_INJECT_HI_EIMH_MASK)
/*! @} */

/*! @name DATA_ERR_INJECT_LO - Memory Data Path Error Injection Mask Low */
/*! @{ */

#define DDRC_DATA_ERR_INJECT_LO_EIML_MASK        (0xFFFFFFFFU)
#define DDRC_DATA_ERR_INJECT_LO_EIML_SHIFT       (0U)
/*! EIML - Error Injection Mask Low Data Bit */
#define DDRC_DATA_ERR_INJECT_LO_EIML(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DATA_ERR_INJECT_LO_EIML_SHIFT)) & DDRC_DATA_ERR_INJECT_LO_EIML_MASK)
/*! @} */

/*! @name ERR_INJECT - Memory Data Path Error Injection Mask ECC */
/*! @{ */

#define DDRC_ERR_INJECT_EEIM_MASK                (0xFFU)
#define DDRC_ERR_INJECT_EEIM_SHIFT               (0U)
/*! EEIM - ECC Error Injection Mask */
#define DDRC_ERR_INJECT_EEIM(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_EEIM_SHIFT)) & DDRC_ERR_INJECT_EEIM_MASK)

#define DDRC_ERR_INJECT_EIEN_MASK                (0x100U)
#define DDRC_ERR_INJECT_EIEN_SHIFT               (8U)
/*! EIEN - Error Injection Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_ERR_INJECT_EIEN(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_EIEN_SHIFT)) & DDRC_ERR_INJECT_EIEN_MASK)

#define DDRC_ERR_INJECT_NUM_ECC_INJ_MASK         (0xF000U)
#define DDRC_ERR_INJECT_NUM_ECC_INJ_SHIFT        (12U)
/*! NUM_ECC_INJ - Number Of ECC Errors Injected
 *  0b0000..ECC errors are injected until the error injection is disabled
 *  0b0001..4
 *  0b0010..8
 *  0b0011..16
 *  0b0100..20
 *  0b0101..24
 *  0b0110..28
 *  0b0111..32
 *  0b1000..36
 *  0b1001..40
 *  0b1010..44
 *  0b1011..48
 *  0b1100..52
 *  0b1101..56
 *  0b1110..60
 *  0b1111..64
 */
#define DDRC_ERR_INJECT_NUM_ECC_INJ(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_NUM_ECC_INJ_SHIFT)) & DDRC_ERR_INJECT_NUM_ECC_INJ_MASK)

#define DDRC_ERR_INJECT_ECC_INJ_SRC_MASK         (0x600000U)
#define DDRC_ERR_INJECT_ECC_INJ_SRC_SHIFT        (21U)
/*! ECC_INJ_SRC - ECC Injection Source
 *  0b00..DDR SDRAM ECC using programmed data and ECC injection masks
 *  0b01..On-chip RAM ECC 1
 *  0b10..On-chip RAM ECC 2
 *  0b11..DDR SDRAM ECC. This setting forces a 1 or 2-bit ECC syndrome error based on the value of FRC2B
 */
#define DDRC_ERR_INJECT_ECC_INJ_SRC(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_ECC_INJ_SRC_SHIFT)) & DDRC_ERR_INJECT_ECC_INJ_SRC_MASK)

#define DDRC_ERR_INJECT_FRC2B_MASK               (0x800000U)
#define DDRC_ERR_INJECT_FRC2B_SHIFT              (23U)
/*! FRC2B - Force 2-Bit Error
 *  0b0..SBE
 *  0b1..2-bit error
 */
#define DDRC_ERR_INJECT_FRC2B(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_FRC2B_SHIFT)) & DDRC_ERR_INJECT_FRC2B_MASK)

#define DDRC_ERR_INJECT_ADDR_TEN_MASK            (0x80000000U)
#define DDRC_ERR_INJECT_ADDR_TEN_SHIFT           (31U)
/*! ADDR_TEN - Address Trigger Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DDRC_ERR_INJECT_ADDR_TEN(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INJECT_ADDR_TEN_SHIFT)) & DDRC_ERR_INJECT_ADDR_TEN_MASK)
/*! @} */

/*! @name ADDR_ERR_INJ - Address Error Inject */
/*! @{ */

#define DDRC_ADDR_ERR_INJ_ADDR_MASK              (0xFFFFFFFFU)
#define DDRC_ADDR_ERR_INJ_ADDR_SHIFT             (0U)
/*! ADDR - Address */
#define DDRC_ADDR_ERR_INJ_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ADDR_ERR_INJ_ADDR_SHIFT)) & DDRC_ADDR_ERR_INJ_ADDR_MASK)
/*! @} */

/*! @name CAPTURE_EXT_DATA_HI - Memory Extended Data Path Read Capture High */
/*! @{ */

#define DDRC_CAPTURE_EXT_DATA_HI_ECEHD_MASK      (0xFFFFFFFFU)
#define DDRC_CAPTURE_EXT_DATA_HI_ECEHD_SHIFT     (0U)
/*! ECEHD - Error Capture Extended High Data Path */
#define DDRC_CAPTURE_EXT_DATA_HI_ECEHD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_EXT_DATA_HI_ECEHD_SHIFT)) & DDRC_CAPTURE_EXT_DATA_HI_ECEHD_MASK)
/*! @} */

/*! @name CAPTURE_EXT_DATA_LO - Memory Extended Data Path Read Capture Low */
/*! @{ */

#define DDRC_CAPTURE_EXT_DATA_LO_ECELD_MASK      (0xFFFFFFFFU)
#define DDRC_CAPTURE_EXT_DATA_LO_ECELD_SHIFT     (0U)
/*! ECELD - Error Capture Extended Low Data Path */
#define DDRC_CAPTURE_EXT_DATA_LO_ECELD(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_EXT_DATA_LO_ECELD_SHIFT)) & DDRC_CAPTURE_EXT_DATA_LO_ECELD_MASK)
/*! @} */

/*! @name CAPTURE_DATA_HI - Memory Data Path Read Capture High */
/*! @{ */

#define DDRC_CAPTURE_DATA_HI_ECHD_MASK           (0xFFFFFFFFU)
#define DDRC_CAPTURE_DATA_HI_ECHD_SHIFT          (0U)
/*! ECHD - Error Capture High Data Path */
#define DDRC_CAPTURE_DATA_HI_ECHD(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_DATA_HI_ECHD_SHIFT)) & DDRC_CAPTURE_DATA_HI_ECHD_MASK)
/*! @} */

/*! @name CAPTURE_DATA_LO - Memory Data Path Read Capture Low */
/*! @{ */

#define DDRC_CAPTURE_DATA_LO_ECLD_MASK           (0xFFFFFFFFU)
#define DDRC_CAPTURE_DATA_LO_ECLD_SHIFT          (0U)
/*! ECLD - Error Capture Low Data Path */
#define DDRC_CAPTURE_DATA_LO_ECLD(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_DATA_LO_ECLD_SHIFT)) & DDRC_CAPTURE_DATA_LO_ECLD_MASK)
/*! @} */

/*! @name CAPTURE_ECC - Memory Data Path Read Capture ECC */
/*! @{ */

#define DDRC_CAPTURE_ECC_ECE_MASK                (0xFFFFFFFFU)
#define DDRC_CAPTURE_ECC_ECE_SHIFT               (0U)
/*! ECE - Error Capture ECC */
#define DDRC_CAPTURE_ECC_ECE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ECC_ECE_SHIFT)) & DDRC_CAPTURE_ECC_ECE_MASK)
/*! @} */

/*! @name ERR_DETECT - Memory Error Detect */
/*! @{ */

#define DDRC_ERR_DETECT_MSE_MASK                 (0x1U)
#define DDRC_ERR_DETECT_MSE_SHIFT                (0U)
/*! MSE - Memory-Select Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define DDRC_ERR_DETECT_MSE(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_MSE_SHIFT)) & DDRC_ERR_DETECT_MSE_MASK)

#define DDRC_ERR_DETECT_SBE_MASK                 (0x4U)
#define DDRC_ERR_DETECT_SBE_SHIFT                (2U)
/*! SBE - Single-Bit ECC Errors
 *  0b0..Did not cross
 *  0b1..Crossed
 */
#define DDRC_ERR_DETECT_SBE(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SBE_SHIFT)) & DDRC_ERR_DETECT_SBE_MASK)

#define DDRC_ERR_DETECT_MBE_MASK                 (0x8U)
#define DDRC_ERR_DETECT_MBE_SHIFT                (3U)
/*! MBE - Multiple-Bit Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define DDRC_ERR_DETECT_MBE(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_MBE_SHIFT)) & DDRC_ERR_DETECT_MBE_MASK)

#define DDRC_ERR_DETECT_REFRATEE_MASK            (0x80U)
#define DDRC_ERR_DETECT_REFRATEE_SHIFT           (7U)
/*! REFRATEE - Refresh rate error.
 *  0b0..A refresh rate error has not been detected.
 *  0b1..A refresh rate error has been detected.
 */
#define DDRC_ERR_DETECT_REFRATEE(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_REFRATEE_SHIFT)) & DDRC_ERR_DETECT_REFRATEE_MASK)

#define DDRC_ERR_DETECT_PHYE_MASK                (0x10000U)
#define DDRC_ERR_DETECT_PHYE_SHIFT               (16U)
/*! PHYE - PHY error.
 *  0b0..A DDR PHY error has not been detected.
 *  0b1..An error has been detected by the DDR PHY.
 */
#define DDRC_ERR_DETECT_PHYE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_PHYE_SHIFT)) & DDRC_ERR_DETECT_PHYE_MASK)

#define DDRC_ERR_DETECT_UPDTMTE_MASK             (0x100000U)
#define DDRC_ERR_DETECT_UPDTMTE_SHIFT            (20U)
/*! UPDTMTE - Update Timeout Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define DDRC_ERR_DETECT_UPDTMTE(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_UPDTMTE_SHIFT)) & DDRC_ERR_DETECT_UPDTMTE_MASK)

#define DDRC_ERR_DETECT_SMBE2_MASK               (0x400000U)
#define DDRC_ERR_DETECT_SMBE2_SHIFT              (22U)
/*! SMBE2 - SRAM Multi-Bit Error 2
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define DDRC_ERR_DETECT_SMBE2(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SMBE2_SHIFT)) & DDRC_ERR_DETECT_SMBE2_MASK)

#define DDRC_ERR_DETECT_SMBE1_MASK               (0x800000U)
#define DDRC_ERR_DETECT_SMBE1_SHIFT              (23U)
/*! SMBE1 - SRAM Multi-Bit Error 1
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define DDRC_ERR_DETECT_SMBE1(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SMBE1_SHIFT)) & DDRC_ERR_DETECT_SMBE1_MASK)

#define DDRC_ERR_DETECT_SSBE2_MASK               (0x1000000U)
#define DDRC_ERR_DETECT_SSBE2_SHIFT              (24U)
/*! SSBE2 - SRAM SBE 2
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define DDRC_ERR_DETECT_SSBE2(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SSBE2_SHIFT)) & DDRC_ERR_DETECT_SSBE2_MASK)

#define DDRC_ERR_DETECT_SSBE1_MASK               (0x2000000U)
#define DDRC_ERR_DETECT_SSBE1_SHIFT              (25U)
/*! SSBE1 - SRAM SBE 1
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define DDRC_ERR_DETECT_SSBE1(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_SSBE1_SHIFT)) & DDRC_ERR_DETECT_SSBE1_MASK)

#define DDRC_ERR_DETECT_MME_MASK                 (0x80000000U)
#define DDRC_ERR_DETECT_MME_SHIFT                (31U)
/*! MME - Multiple Memory Errors
 *  0b0..Not detected
 *  0b1..Detected
 */
#define DDRC_ERR_DETECT_MME(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DETECT_MME_SHIFT)) & DDRC_ERR_DETECT_MME_MASK)
/*! @} */

/*! @name ERR_DISABLE - Memory Error Disable */
/*! @{ */

#define DDRC_ERR_DISABLE_MSED_MASK               (0x1U)
#define DDRC_ERR_DISABLE_MSED_SHIFT              (0U)
/*! MSED - Memory-Select Error Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DDRC_ERR_DISABLE_MSED(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_MSED_SHIFT)) & DDRC_ERR_DISABLE_MSED_MASK)

#define DDRC_ERR_DISABLE_SBED_MASK               (0x4U)
#define DDRC_ERR_DISABLE_SBED_SHIFT              (2U)
/*! SBED - Single-Bit ECC Error Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DDRC_ERR_DISABLE_SBED(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_SBED_SHIFT)) & DDRC_ERR_DISABLE_SBED_MASK)

#define DDRC_ERR_DISABLE_MBED_MASK               (0x8U)
#define DDRC_ERR_DISABLE_MBED_SHIFT              (3U)
/*! MBED - Multiple-Bit ECC Error Disable
 *  0b0..Detected
 *  0b1..Not detected or reported
 */
#define DDRC_ERR_DISABLE_MBED(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_MBED_SHIFT)) & DDRC_ERR_DISABLE_MBED_MASK)

#define DDRC_ERR_DISABLE_REFRATEED_MASK          (0x80U)
#define DDRC_ERR_DISABLE_REFRATEED_SHIFT         (7U)
/*! REFRATEED - Refresh Rate Error Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DDRC_ERR_DISABLE_REFRATEED(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_REFRATEED_SHIFT)) & DDRC_ERR_DISABLE_REFRATEED_MASK)

#define DDRC_ERR_DISABLE_PHYED_MASK              (0x10000U)
#define DDRC_ERR_DISABLE_PHYED_SHIFT             (16U)
/*! PHYED - PHY Error Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DDRC_ERR_DISABLE_PHYED(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_PHYED_SHIFT)) & DDRC_ERR_DISABLE_PHYED_MASK)

#define DDRC_ERR_DISABLE_UPDTMTED_MASK           (0x100000U)
#define DDRC_ERR_DISABLE_UPDTMTED_SHIFT          (20U)
/*! UPDTMTED - Update Timeout Error Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DDRC_ERR_DISABLE_UPDTMTED(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_DISABLE_UPDTMTED_SHIFT)) & DDRC_ERR_DISABLE_UPDTMTED_MASK)
/*! @} */

/*! @name ERR_INT_EN - Memory Error Interrupt Enable */
/*! @{ */

#define DDRC_ERR_INT_EN_MSEE_MASK                (0x1U)
#define DDRC_ERR_INT_EN_MSEE_SHIFT               (0U)
/*! MSEE - Memory-Select Error Interrupt Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_ERR_INT_EN_MSEE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_MSEE_SHIFT)) & DDRC_ERR_INT_EN_MSEE_MASK)

#define DDRC_ERR_INT_EN_SBEE_MASK                (0x4U)
#define DDRC_ERR_INT_EN_SBEE_SHIFT               (2U)
/*! SBEE - Single-Bit ECC Error Interrupt Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_ERR_INT_EN_SBEE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_SBEE_SHIFT)) & DDRC_ERR_INT_EN_SBEE_MASK)

#define DDRC_ERR_INT_EN_MBEE_MASK                (0x8U)
#define DDRC_ERR_INT_EN_MBEE_SHIFT               (3U)
/*! MBEE - Multiple-Bit ECC Error Interrupt Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_ERR_INT_EN_MBEE(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_MBEE_SHIFT)) & DDRC_ERR_INT_EN_MBEE_MASK)

#define DDRC_ERR_INT_EN_SSBE12E_MASK             (0x10U)
#define DDRC_ERR_INT_EN_SSBE12E_SHIFT            (4U)
/*! SSBE12E - SRAM Single-Bit Error Interrupt Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_ERR_INT_EN_SSBE12E(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_SSBE12E_SHIFT)) & DDRC_ERR_INT_EN_SSBE12E_MASK)

#define DDRC_ERR_INT_EN_REFRATEEE_MASK           (0x80U)
#define DDRC_ERR_INT_EN_REFRATEEE_SHIFT          (7U)
/*! REFRATEEE - Refresh Rate Interrupt Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_ERR_INT_EN_REFRATEEE(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_REFRATEEE_SHIFT)) & DDRC_ERR_INT_EN_REFRATEEE_MASK)

#define DDRC_ERR_INT_EN_PHYEE_MASK               (0x10000U)
#define DDRC_ERR_INT_EN_PHYEE_SHIFT              (16U)
/*! PHYEE - PHY error interrupt enable.
 *  0b0..PHY errors cannot generate interrupts.
 *  0b1..PHY errors generate interrupts.
 */
#define DDRC_ERR_INT_EN_PHYEE(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_PHYEE_SHIFT)) & DDRC_ERR_INT_EN_PHYEE_MASK)

#define DDRC_ERR_INT_EN_UPDTMTEE_MASK            (0x100000U)
#define DDRC_ERR_INT_EN_UPDTMTEE_SHIFT           (20U)
/*! UPDTMTEE - Update Timeout Interrupt Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DDRC_ERR_INT_EN_UPDTMTEE(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_INT_EN_UPDTMTEE_SHIFT)) & DDRC_ERR_INT_EN_UPDTMTEE_MASK)
/*! @} */

/*! @name CAPTURE_ATTRIBUTES - Memory Error Attributes Capture */
/*! @{ */

#define DDRC_CAPTURE_ATTRIBUTES_VLD_MASK         (0x1U)
#define DDRC_CAPTURE_ATTRIBUTES_VLD_SHIFT        (0U)
/*! VLD - Valid */
#define DDRC_CAPTURE_ATTRIBUTES_VLD(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ATTRIBUTES_VLD_SHIFT)) & DDRC_CAPTURE_ATTRIBUTES_VLD_MASK)

#define DDRC_CAPTURE_ATTRIBUTES_TTYP_MASK        (0x3000U)
#define DDRC_CAPTURE_ATTRIBUTES_TTYP_SHIFT       (12U)
/*! TTYP - Error Transaction Type
 *  0b00..Reserved
 *  0b01..Write
 *  0b10..Read
 *  0b11..Read-modify-write
 */
#define DDRC_CAPTURE_ATTRIBUTES_TTYP(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ATTRIBUTES_TTYP_SHIFT)) & DDRC_CAPTURE_ATTRIBUTES_TTYP_MASK)

#define DDRC_CAPTURE_ATTRIBUTES_TSIZ_MASK        (0x7000000U)
#define DDRC_CAPTURE_ATTRIBUTES_TSIZ_SHIFT       (24U)
/*! TSIZ - Error Transaction Size
 *  0b000..8
 *  0b001..1
 *  0b010..2
 *  0b011..3
 *  0b100..4
 *  0b101..5
 *  0b110..6
 *  0b111..7
 */
#define DDRC_CAPTURE_ATTRIBUTES_TSIZ(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ATTRIBUTES_TSIZ_SHIFT)) & DDRC_CAPTURE_ATTRIBUTES_TSIZ_MASK)

#define DDRC_CAPTURE_ATTRIBUTES_BNUM_MASK        (0x70000000U)
#define DDRC_CAPTURE_ATTRIBUTES_BNUM_SHIFT       (28U)
/*! BNUM - Data Beat Number */
#define DDRC_CAPTURE_ATTRIBUTES_BNUM(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ATTRIBUTES_BNUM_SHIFT)) & DDRC_CAPTURE_ATTRIBUTES_BNUM_MASK)
/*! @} */

/*! @name CAPTURE_ADDRESS - Memory Error Address Capture */
/*! @{ */

#define DDRC_CAPTURE_ADDRESS_CADDR_MASK          (0xFFFFFFFFU)
#define DDRC_CAPTURE_ADDRESS_CADDR_SHIFT         (0U)
/*! CADDR - Captured Address */
#define DDRC_CAPTURE_ADDRESS_CADDR(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_ADDRESS_CADDR_SHIFT)) & DDRC_CAPTURE_ADDRESS_CADDR_MASK)
/*! @} */

/*! @name CAPTURE_EXT_ADDRESS - Memory Error Extended Address Capture */
/*! @{ */

#define DDRC_CAPTURE_EXT_ADDRESS_CEADDR_MASK     (0xFFU)
#define DDRC_CAPTURE_EXT_ADDRESS_CEADDR_SHIFT    (0U)
/*! CEADDR - Captured Extended Address */
#define DDRC_CAPTURE_EXT_ADDRESS_CEADDR(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_CAPTURE_EXT_ADDRESS_CEADDR_SHIFT)) & DDRC_CAPTURE_EXT_ADDRESS_CEADDR_MASK)
/*! @} */

/*! @name ERR_SBE - Single-Bit ECC Memory Error Management */
/*! @{ */

#define DDRC_ERR_SBE_SBEC_MASK                   (0xFFU)
#define DDRC_ERR_SBE_SBEC_SHIFT                  (0U)
/*! SBEC - SBE Counter */
#define DDRC_ERR_SBE_SBEC(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_SBE_SBEC_SHIFT)) & DDRC_ERR_SBE_SBEC_MASK)

#define DDRC_ERR_SBE_SBET_MASK                   (0xFF0000U)
#define DDRC_ERR_SBE_SBET_SHIFT                  (16U)
/*! SBET - SBE Threshold */
#define DDRC_ERR_SBE_SBET(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_ERR_SBE_SBET_SHIFT)) & DDRC_ERR_SBE_SBET_MASK)
/*! @} */

/*! @name ECC_REG_0 - ECC Region 0 Configuration */
/*! @{ */

#define DDRC_ECC_REG_0_REG_0_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_0_REG_0_EA_SHIFT            (0U)
/*! REG_0_EA - Region 0 End Address */
#define DDRC_ECC_REG_0_REG_0_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_0_REG_0_EA_SHIFT)) & DDRC_ECC_REG_0_REG_0_EA_MASK)

#define DDRC_ECC_REG_0_REG_0_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_0_REG_0_SA_SHIFT            (16U)
/*! REG_0_SA - Region 0 Start Address */
#define DDRC_ECC_REG_0_REG_0_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_0_REG_0_SA_SHIFT)) & DDRC_ECC_REG_0_REG_0_SA_MASK)

#define DDRC_ECC_REG_0_REG_0_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_0_REG_0_EN_SHIFT            (31U)
/*! REG_0_EN - Region 0 Enable
 *  0b0..Does not use region 0 for ECC enablement
 *  0b1..Protects addresses from region 0 with ECC
 */
#define DDRC_ECC_REG_0_REG_0_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_0_REG_0_EN_SHIFT)) & DDRC_ECC_REG_0_REG_0_EN_MASK)
/*! @} */

/*! @name ECC_REG_1 - ECC Region 1 Configuration */
/*! @{ */

#define DDRC_ECC_REG_1_REG_1_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_1_REG_1_EA_SHIFT            (0U)
/*! REG_1_EA - Region 1 End Address */
#define DDRC_ECC_REG_1_REG_1_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_1_REG_1_EA_SHIFT)) & DDRC_ECC_REG_1_REG_1_EA_MASK)

#define DDRC_ECC_REG_1_REG_1_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_1_REG_1_SA_SHIFT            (16U)
/*! REG_1_SA - Region 1 Start Address */
#define DDRC_ECC_REG_1_REG_1_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_1_REG_1_SA_SHIFT)) & DDRC_ECC_REG_1_REG_1_SA_MASK)

#define DDRC_ECC_REG_1_REG_1_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_1_REG_1_EN_SHIFT            (31U)
/*! REG_1_EN - Region 1 Enable
 *  0b0..Does not use region 1 for ECC enablement
 *  0b1..Protects addresses from region 1 with ECC
 */
#define DDRC_ECC_REG_1_REG_1_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_1_REG_1_EN_SHIFT)) & DDRC_ECC_REG_1_REG_1_EN_MASK)
/*! @} */

/*! @name ECC_REG_2 - ECC Region 2 Configuration */
/*! @{ */

#define DDRC_ECC_REG_2_REG_2_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_2_REG_2_EA_SHIFT            (0U)
/*! REG_2_EA - Region 2 End Address */
#define DDRC_ECC_REG_2_REG_2_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_2_REG_2_EA_SHIFT)) & DDRC_ECC_REG_2_REG_2_EA_MASK)

#define DDRC_ECC_REG_2_REG_2_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_2_REG_2_SA_SHIFT            (16U)
/*! REG_2_SA - Region 2 Start Address */
#define DDRC_ECC_REG_2_REG_2_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_2_REG_2_SA_SHIFT)) & DDRC_ECC_REG_2_REG_2_SA_MASK)

#define DDRC_ECC_REG_2_REG_2_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_2_REG_2_EN_SHIFT            (31U)
/*! REG_2_EN - Region 2 Enable
 *  0b0..Does not use region 2 for ECC enablement
 *  0b1..Protects addresses from region 2 with ECC
 */
#define DDRC_ECC_REG_2_REG_2_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_2_REG_2_EN_SHIFT)) & DDRC_ECC_REG_2_REG_2_EN_MASK)
/*! @} */

/*! @name ECC_REG_3 - ECC Region 3 Configuration */
/*! @{ */

#define DDRC_ECC_REG_3_REG_3_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_3_REG_3_EA_SHIFT            (0U)
/*! REG_3_EA - Region 3 End Address */
#define DDRC_ECC_REG_3_REG_3_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_3_REG_3_EA_SHIFT)) & DDRC_ECC_REG_3_REG_3_EA_MASK)

#define DDRC_ECC_REG_3_REG_3_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_3_REG_3_SA_SHIFT            (16U)
/*! REG_3_SA - Region 3 Start Address */
#define DDRC_ECC_REG_3_REG_3_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_3_REG_3_SA_SHIFT)) & DDRC_ECC_REG_3_REG_3_SA_MASK)

#define DDRC_ECC_REG_3_REG_3_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_3_REG_3_EN_SHIFT            (31U)
/*! REG_3_EN - Region 3 Enable
 *  0b0..Does not use region 3 for ECC enablement
 *  0b1..Protects addresses from region 3 with ECC
 */
#define DDRC_ECC_REG_3_REG_3_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_3_REG_3_EN_SHIFT)) & DDRC_ECC_REG_3_REG_3_EN_MASK)
/*! @} */

/*! @name ECC_REG_4 - ECC Region 4 Configuration */
/*! @{ */

#define DDRC_ECC_REG_4_REG_4_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_4_REG_4_EA_SHIFT            (0U)
/*! REG_4_EA - Region 4 End Address */
#define DDRC_ECC_REG_4_REG_4_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_4_REG_4_EA_SHIFT)) & DDRC_ECC_REG_4_REG_4_EA_MASK)

#define DDRC_ECC_REG_4_REG_4_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_4_REG_4_SA_SHIFT            (16U)
/*! REG_4_SA - Region 4 Start Address */
#define DDRC_ECC_REG_4_REG_4_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_4_REG_4_SA_SHIFT)) & DDRC_ECC_REG_4_REG_4_SA_MASK)

#define DDRC_ECC_REG_4_REG_4_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_4_REG_4_EN_SHIFT            (31U)
/*! REG_4_EN - Region 4 Enable
 *  0b0..Does not use region 4 for ECC enablement
 *  0b1..Protects addresses from region 4 with ECC
 */
#define DDRC_ECC_REG_4_REG_4_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_4_REG_4_EN_SHIFT)) & DDRC_ECC_REG_4_REG_4_EN_MASK)
/*! @} */

/*! @name ECC_REG_5 - ECC Region 5 Configuration */
/*! @{ */

#define DDRC_ECC_REG_5_REG_5_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_5_REG_5_EA_SHIFT            (0U)
/*! REG_5_EA - Region 5 End Address */
#define DDRC_ECC_REG_5_REG_5_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_5_REG_5_EA_SHIFT)) & DDRC_ECC_REG_5_REG_5_EA_MASK)

#define DDRC_ECC_REG_5_REG_5_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_5_REG_5_SA_SHIFT            (16U)
/*! REG_5_SA - Region 5 Start Address */
#define DDRC_ECC_REG_5_REG_5_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_5_REG_5_SA_SHIFT)) & DDRC_ECC_REG_5_REG_5_SA_MASK)

#define DDRC_ECC_REG_5_REG_5_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_5_REG_5_EN_SHIFT            (31U)
/*! REG_5_EN - Region 5 Enable
 *  0b0..Does not use region 5 for ECC enablement
 *  0b1..Protects addresses from region 5 with ECC
 */
#define DDRC_ECC_REG_5_REG_5_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_5_REG_5_EN_SHIFT)) & DDRC_ECC_REG_5_REG_5_EN_MASK)
/*! @} */

/*! @name ECC_REG_6 - ECC Region 6 Configuration */
/*! @{ */

#define DDRC_ECC_REG_6_REG_6_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_6_REG_6_EA_SHIFT            (0U)
/*! REG_6_EA - Region 6 End Address */
#define DDRC_ECC_REG_6_REG_6_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_6_REG_6_EA_SHIFT)) & DDRC_ECC_REG_6_REG_6_EA_MASK)

#define DDRC_ECC_REG_6_REG_6_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_6_REG_6_SA_SHIFT            (16U)
/*! REG_6_SA - Region 6 Start Address */
#define DDRC_ECC_REG_6_REG_6_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_6_REG_6_SA_SHIFT)) & DDRC_ECC_REG_6_REG_6_SA_MASK)

#define DDRC_ECC_REG_6_REG_6_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_6_REG_6_EN_SHIFT            (31U)
/*! REG_6_EN - Region 6 Enable
 *  0b0..Does not use region 6 for ECC enablement
 *  0b1..Protects addresses from region 6 with ECC
 */
#define DDRC_ECC_REG_6_REG_6_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_6_REG_6_EN_SHIFT)) & DDRC_ECC_REG_6_REG_6_EN_MASK)
/*! @} */

/*! @name ECC_REG_7 - ECC Region 7 Configuration */
/*! @{ */

#define DDRC_ECC_REG_7_REG_7_EA_MASK             (0xFFFU)
#define DDRC_ECC_REG_7_REG_7_EA_SHIFT            (0U)
/*! REG_7_EA - Region 7 End Address */
#define DDRC_ECC_REG_7_REG_7_EA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_7_REG_7_EA_SHIFT)) & DDRC_ECC_REG_7_REG_7_EA_MASK)

#define DDRC_ECC_REG_7_REG_7_SA_MASK             (0xFFF0000U)
#define DDRC_ECC_REG_7_REG_7_SA_SHIFT            (16U)
/*! REG_7_SA - Region 7 Start Address */
#define DDRC_ECC_REG_7_REG_7_SA(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_7_REG_7_SA_SHIFT)) & DDRC_ECC_REG_7_REG_7_SA_MASK)

#define DDRC_ECC_REG_7_REG_7_EN_MASK             (0x80000000U)
#define DDRC_ECC_REG_7_REG_7_EN_SHIFT            (31U)
/*! REG_7_EN - Region 7 Enable
 *  0b0..Does not use region 7 for ECC enablement
 *  0b1..Protects addresses from region 7 with ECC
 */
#define DDRC_ECC_REG_7_REG_7_EN(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ECC_REG_7_REG_7_EN_SHIFT)) & DDRC_ECC_REG_7_REG_7_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DDRC_Register_Masks */


/*!
 * @}
 */ /* end of group DDRC_Peripheral_Access_Layer */


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


#endif  /* PERI_DDRC_H_ */
