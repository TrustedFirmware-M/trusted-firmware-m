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
**         CMSIS Peripheral Access Layer for MIPI_DSI
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
 * @file PERI_MIPI_DSI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_DSI
 *
 * CMSIS Peripheral Access Layer for MIPI_DSI
 */

#if !defined(PERI_MIPI_DSI_H_)
#define PERI_MIPI_DSI_H_                         /**< Symbol preventing repeated inclusion */

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
   -- MIPI_DSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_Peripheral_Access_Layer MIPI_DSI Peripheral Access Layer
 * @{
 */

/** MIPI_DSI - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERSION;                           /**< Core Version, offset: 0x0 */
  __IO uint32_t PWR_UP;                            /**< Power Up, offset: 0x4 */
  __IO uint32_t CLKMGR_CFG;                        /**< Clock Divider Configuration, offset: 0x8 */
  __IO uint32_t DPI_VCID;                          /**< DPI Virtual Channel ID, offset: 0xC */
  __IO uint32_t DPI_COLOR_CODING;                  /**< DPI color coding, offset: 0x10 */
  __IO uint32_t DPI_CFG_POL;                       /**< DPI Signals Polarity Configuration, offset: 0x14 */
  __IO uint32_t DPI_LP_CMD_TIM;                    /**< DPI Low-power Commands Timing, offset: 0x18 */
       uint8_t RESERVED_0[16];
  __IO uint32_t PCKHDL_CFG;                        /**< PCKHDL Configuration, offset: 0x2C */
  __IO uint32_t GEN_VCID;                          /**< Generic Interface Virtual Channel ID, offset: 0x30 */
  __IO uint32_t MODE_CFG;                          /**< Mode Configuration, offset: 0x34 */
  __IO uint32_t VID_MODE_CFG;                      /**< Video Mode Configuration, offset: 0x38 */
  __IO uint32_t VID_PKT_SIZE;                      /**< Video Packet Size, offset: 0x3C */
  __IO uint32_t VID_NUM_CHUNKS;                    /**< Video Number of Chunks, offset: 0x40 */
  __IO uint32_t VID_NULL_SIZE;                     /**< Video Null Packets Size, offset: 0x44 */
  __IO uint32_t VID_HSA_TIME;                      /**< Video HSA Time, offset: 0x48 */
  __IO uint32_t VID_HBP_TIME;                      /**< Video HBP Time, offset: 0x4C */
  __IO uint32_t VID_HLINE_TIME;                    /**< Video Line Time, offset: 0x50 */
  __IO uint32_t VID_VSA_LINES;                     /**< VSA Period, offset: 0x54 */
  __IO uint32_t VID_VBP_LINES;                     /**< VBP Period, offset: 0x58 */
  __IO uint32_t VID_VFP_LINES;                     /**< VFP Period, offset: 0x5C */
  __IO uint32_t VID_VACTIVE_LINES;                 /**< Vertical Resolution of Video, offset: 0x60 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CMD_MODE_CFG;                      /**< Command Mode Configuration, offset: 0x68 */
  __IO uint32_t GEN_HDR;                           /**< Generic Interface Header Packet Configuration, offset: 0x6C */
  __IO uint32_t GEN_PLD_DATA;                      /**< Generic Interface Payload Data, offset: 0x70 */
  __I  uint32_t CMD_PKT_STATUS;                    /**< Command Packet Status, offset: 0x74 */
  __IO uint32_t TO_CNT_CFG;                        /**< Timeout Counter Configuration, offset: 0x78 */
  __IO uint32_t HS_RD_TO_CNT;                      /**< Peripheral Response Timeout after High-speed Read Operations, offset: 0x7C */
  __IO uint32_t LP_RD_TO_CNT;                      /**< Peripheral Response Timeout after Low-power Read Operations, offset: 0x80 */
  __IO uint32_t HS_WR_TO_CNT;                      /**< Peripheral Response Timeout after High-speed Write Operations, offset: 0x84 */
  __IO uint32_t LP_WR_TO_CNT;                      /**< Peripheral Response Timeout after Low-power Write Operations, offset: 0x88 */
  __IO uint32_t BTA_TO_CNT;                        /**< Peripheral Response Timeout after Bus Turnaround Completion, offset: 0x8C */
  __IO uint32_t SDF_3D;                            /**< 3D Control Information for VSS Packets in Video Mode, offset: 0x90 */
  __IO uint32_t LPCLK_CTRL;                        /**< LP Clock Control, offset: 0x94 */
  __IO uint32_t PHY_TMR_LPCLK_CFG;                 /**< D-PHY Clock Lanes LP2HS and HS2LP Time Configuration, offset: 0x98 */
  __IO uint32_t PHY_TMR_CFG;                       /**< D-PHY Data Lanes LP2HS and HS2LP Time Configuration, offset: 0x9C */
  __IO uint32_t PHY_RSTZ;                          /**< D-PHY Reset Control, offset: 0xA0 */
  __IO uint32_t PHY_IF_CFG;                        /**< PHY Interface Configuration, offset: 0xA4 */
  __IO uint32_t PHY_ULPS_CTRL;                     /**< D-PHY ULPS Control, offset: 0xA8 */
  __IO uint32_t PHY_TX_TRIGGERS;                   /**< D-PHY Trigger Transmission Control, offset: 0xAC */
  __I  uint32_t PHY_STATUS;                        /**< D-PHY Status, offset: 0xB0 */
  __IO uint32_t PHY_TST_CTRL0;                     /**< D-PHY Test Control 0, offset: 0xB4 */
  __IO uint32_t PHY_TST_CTRL1;                     /**< D-PHY Test Control 1, offset: 0xB8 */
  __I  uint32_t INT_ST0;                           /**< Interrupt Status 0, offset: 0xBC */
  __I  uint32_t INT_ST1;                           /**< Interrupt Status 1, offset: 0xC0 */
  __IO uint32_t INT_MSK0;                          /**< Interrupt Mask 0, offset: 0xC4 */
  __IO uint32_t INT_MSK1;                          /**< Interrupt Mask 1, offset: 0xC8 */
  __IO uint32_t PHY_CAL;                           /**< D-PHY Skew Calibration, offset: 0xCC */
       uint8_t RESERVED_2[8];
  __IO uint32_t INT_FORCE0;                        /**< Interrupt Force 0, offset: 0xD8 */
  __IO uint32_t INT_FORCE1;                        /**< Interrupt Force Register 1, offset: 0xDC */
       uint8_t RESERVED_3[16];
  __IO uint32_t DSC_PARAMETER;                     /**< Display Stream Compression Configuration, offset: 0xF0 */
  __IO uint32_t PHY_TMR_RD_CFG;                    /**< PHY Read Command Time Configuration, offset: 0xF4 */
       uint8_t RESERVED_4[8];
  __IO uint32_t VID_SHADOW_CTRL;                   /**< Video Shadow Control, offset: 0x100 */
       uint8_t RESERVED_5[8];
  __I  uint32_t DPI_VCID_ACT;                      /**< DPI Virtual Channel ID Value, offset: 0x10C */
  __I  uint32_t DPI_COLOR_CODING_ACT;              /**< DPI Color Coding Value, offset: 0x110 */
       uint8_t RESERVED_6[4];
  __I  uint32_t DPI_LP_CMD_TIM_ACT;                /**< DPI Low-power Commands Timing Value, offset: 0x118 */
       uint8_t RESERVED_7[28];
  __I  uint32_t VID_MODE_CFG_ACT;                  /**< Video Mode Configuration Value, offset: 0x138 */
  __I  uint32_t VID_PKT_SIZE_ACT;                  /**< Video Packet Size Value, offset: 0x13C */
  __I  uint32_t VID_NUM_CHUNKS_ACT;                /**< Video Number Chunks Value, offset: 0x140 */
  __I  uint32_t VID_NULL_SIZE_ACT;                 /**< Video Null Packets Size Value, offset: 0x144 */
  __I  uint32_t VID_HSA_TIME_ACT;                  /**< Video HSA Time Value, offset: 0x148 */
  __I  uint32_t VID_HBP_TIME_ACT;                  /**< Video HBP Time Value, offset: 0x14C */
  __I  uint32_t VID_HLINE_TIME_ACT;                /**< Video Line Time Value, offset: 0x150 */
  __I  uint32_t VID_VSA_LINES_ACT;                 /**< VSA Period Value, offset: 0x154 */
  __I  uint32_t VID_VBP_LINES_ACT;                 /**< VBP Period Value, offset: 0x158 */
  __I  uint32_t VID_VFP_LINES_ACT;                 /**< VFP Period Value, offset: 0x15C */
  __I  uint32_t VID_VACTIVE_LINES_ACT;             /**< Vertical Resolution of Video Value, offset: 0x160 */
       uint8_t RESERVED_8[4];
  __I  uint32_t VID_PKT_STATUS;                    /**< Video Packet Status, offset: 0x168 */
       uint8_t RESERVED_9[36];
  __I  uint32_t SDF_3D_ACT;                        /**< 3D Control Information Value, offset: 0x190 */
} MIPI_DSI_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_DSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_DSI_Register_Masks MIPI_DSI Register Masks
 * @{
 */

/*! @name VERSION - Core Version */
/*! @{ */

#define MIPI_DSI_VERSION_version_MASK            (0xFFFFFFFFU)
#define MIPI_DSI_VERSION_version_SHIFT           (0U)
/*! version - Version */
#define MIPI_DSI_VERSION_version(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VERSION_version_SHIFT)) & MIPI_DSI_VERSION_version_MASK)
/*! @} */

/*! @name PWR_UP - Power Up */
/*! @{ */

#define MIPI_DSI_PWR_UP_shutdownz_MASK           (0x1U)
#define MIPI_DSI_PWR_UP_shutdownz_SHIFT          (0U)
/*! shutdownz - Reset or Power up
 *  0b0..Reset the controller
 *  0b1..Power up the controller
 */
#define MIPI_DSI_PWR_UP_shutdownz(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PWR_UP_shutdownz_SHIFT)) & MIPI_DSI_PWR_UP_shutdownz_MASK)
/*! @} */

/*! @name CLKMGR_CFG - Clock Divider Configuration */
/*! @{ */

#define MIPI_DSI_CLKMGR_CFG_tx_esc_clk_division_MASK (0xFFU)
#define MIPI_DSI_CLKMGR_CFG_tx_esc_clk_division_SHIFT (0U)
/*! tx_esc_clk_division - Transmit Escape Clock Division */
#define MIPI_DSI_CLKMGR_CFG_tx_esc_clk_division(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CLKMGR_CFG_tx_esc_clk_division_SHIFT)) & MIPI_DSI_CLKMGR_CFG_tx_esc_clk_division_MASK)

#define MIPI_DSI_CLKMGR_CFG_to_clk_division_MASK (0xFF00U)
#define MIPI_DSI_CLKMGR_CFG_to_clk_division_SHIFT (8U)
/*! to_clk_division - Time Out Clock Division */
#define MIPI_DSI_CLKMGR_CFG_to_clk_division(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CLKMGR_CFG_to_clk_division_SHIFT)) & MIPI_DSI_CLKMGR_CFG_to_clk_division_MASK)
/*! @} */

/*! @name DPI_VCID - DPI Virtual Channel ID */
/*! @{ */

#define MIPI_DSI_DPI_VCID_dpi_vcid_MASK          (0x3U)
#define MIPI_DSI_DPI_VCID_dpi_vcid_SHIFT         (0U)
/*! dpi_vcid - DPI Virtual Channel ID */
#define MIPI_DSI_DPI_VCID_dpi_vcid(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_VCID_dpi_vcid_SHIFT)) & MIPI_DSI_DPI_VCID_dpi_vcid_MASK)
/*! @} */

/*! @name DPI_COLOR_CODING - DPI color coding */
/*! @{ */

#define MIPI_DSI_DPI_COLOR_CODING_dpi_color_coding_MASK (0xFU)
#define MIPI_DSI_DPI_COLOR_CODING_dpi_color_coding_SHIFT (0U)
/*! dpi_color_coding - DPI Color Coding
 *  0b0000..16-bit configuration 1
 *  0b0001..16-bit configuration 2
 *  0b0010..16-bit configuration 3
 *  0b0011..18-bit configuration 1
 *  0b0100..18-bit configuration 2
 *  0b0101..24-bit
 *  0b0110..20-bit YCbCr 4:2:2 loosely packed / Reserved for eDPI Command Mode
 *  0b0111..24-bit YCbCr 4:2:2 / Reserved for eDPI Command Mode
 *  0b1000..16-bit YCbCr 4:2:2 / Reserved for eDPI Command Mode
 *  0b1001..30-bit - DSC_ENC 10bit / Reserved for eDPI Command Mode
 *  0b1010..36-bit / Reserved for eDPI Command Mode
 *  0b1011..12-bit YCbCr 4:2:0 / Reserved for eDPI Command Mode
 *  0b1100..DSC24 compressed Data
 *  0b1101-0b1111..
 */
#define MIPI_DSI_DPI_COLOR_CODING_dpi_color_coding(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_COLOR_CODING_dpi_color_coding_SHIFT)) & MIPI_DSI_DPI_COLOR_CODING_dpi_color_coding_MASK)

#define MIPI_DSI_DPI_COLOR_CODING_loosely18_en_MASK (0x100U)
#define MIPI_DSI_DPI_COLOR_CODING_loosely18_en_SHIFT (8U)
/*! loosely18_en - Loosely 18 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_DPI_COLOR_CODING_loosely18_en(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_COLOR_CODING_loosely18_en_SHIFT)) & MIPI_DSI_DPI_COLOR_CODING_loosely18_en_MASK)
/*! @} */

/*! @name DPI_CFG_POL - DPI Signals Polarity Configuration */
/*! @{ */

#define MIPI_DSI_DPI_CFG_POL_dataen_active_low_MASK (0x1U)
#define MIPI_DSI_DPI_CFG_POL_dataen_active_low_SHIFT (0U)
/*! dataen_active_low - Data Enable Pin as Active Low
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_DPI_CFG_POL_dataen_active_low(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_CFG_POL_dataen_active_low_SHIFT)) & MIPI_DSI_DPI_CFG_POL_dataen_active_low_MASK)

#define MIPI_DSI_DPI_CFG_POL_vsync_active_low_MASK (0x2U)
#define MIPI_DSI_DPI_CFG_POL_vsync_active_low_SHIFT (1U)
/*! vsync_active_low - VSYNC Enable Pin as Active Low
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_DPI_CFG_POL_vsync_active_low(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_CFG_POL_vsync_active_low_SHIFT)) & MIPI_DSI_DPI_CFG_POL_vsync_active_low_MASK)

#define MIPI_DSI_DPI_CFG_POL_hsync_active_low_MASK (0x4U)
#define MIPI_DSI_DPI_CFG_POL_hsync_active_low_SHIFT (2U)
/*! hsync_active_low - HSYNC Enable Pin as Active Low
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_DPI_CFG_POL_hsync_active_low(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_CFG_POL_hsync_active_low_SHIFT)) & MIPI_DSI_DPI_CFG_POL_hsync_active_low_MASK)

#define MIPI_DSI_DPI_CFG_POL_shutd_active_low_MASK (0x8U)
#define MIPI_DSI_DPI_CFG_POL_shutd_active_low_SHIFT (3U)
/*! shutd_active_low - Shutdown Pin as Active Low
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_DPI_CFG_POL_shutd_active_low(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_CFG_POL_shutd_active_low_SHIFT)) & MIPI_DSI_DPI_CFG_POL_shutd_active_low_MASK)

#define MIPI_DSI_DPI_CFG_POL_colorm_active_low_MASK (0x10U)
#define MIPI_DSI_DPI_CFG_POL_colorm_active_low_SHIFT (4U)
/*! colorm_active_low - Color Mode Pin as Active Low
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_DPI_CFG_POL_colorm_active_low(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_CFG_POL_colorm_active_low_SHIFT)) & MIPI_DSI_DPI_CFG_POL_colorm_active_low_MASK)
/*! @} */

/*! @name DPI_LP_CMD_TIM - DPI Low-power Commands Timing */
/*! @{ */

#define MIPI_DSI_DPI_LP_CMD_TIM_invact_lpcmd_time_MASK (0xFFU)
#define MIPI_DSI_DPI_LP_CMD_TIM_invact_lpcmd_time_SHIFT (0U)
/*! invact_lpcmd_time - In VACT Low-power Command Time */
#define MIPI_DSI_DPI_LP_CMD_TIM_invact_lpcmd_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_LP_CMD_TIM_invact_lpcmd_time_SHIFT)) & MIPI_DSI_DPI_LP_CMD_TIM_invact_lpcmd_time_MASK)

#define MIPI_DSI_DPI_LP_CMD_TIM_outvact_lpcmd_time_MASK (0xFF0000U)
#define MIPI_DSI_DPI_LP_CMD_TIM_outvact_lpcmd_time_SHIFT (16U)
/*! outvact_lpcmd_time - Out VACT Low-power Command Time */
#define MIPI_DSI_DPI_LP_CMD_TIM_outvact_lpcmd_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_LP_CMD_TIM_outvact_lpcmd_time_SHIFT)) & MIPI_DSI_DPI_LP_CMD_TIM_outvact_lpcmd_time_MASK)
/*! @} */

/*! @name PCKHDL_CFG - PCKHDL Configuration */
/*! @{ */

#define MIPI_DSI_PCKHDL_CFG_eotp_tx_en_MASK      (0x1U)
#define MIPI_DSI_PCKHDL_CFG_eotp_tx_en_SHIFT     (0U)
/*! eotp_tx_en - EoTp Transmit Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PCKHDL_CFG_eotp_tx_en(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PCKHDL_CFG_eotp_tx_en_SHIFT)) & MIPI_DSI_PCKHDL_CFG_eotp_tx_en_MASK)

#define MIPI_DSI_PCKHDL_CFG_eotp_rx_en_MASK      (0x2U)
#define MIPI_DSI_PCKHDL_CFG_eotp_rx_en_SHIFT     (1U)
/*! eotp_rx_en - EoTp Receive Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PCKHDL_CFG_eotp_rx_en(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PCKHDL_CFG_eotp_rx_en_SHIFT)) & MIPI_DSI_PCKHDL_CFG_eotp_rx_en_MASK)

#define MIPI_DSI_PCKHDL_CFG_bta_en_MASK          (0x4U)
#define MIPI_DSI_PCKHDL_CFG_bta_en_SHIFT         (2U)
/*! bta_en - BTA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PCKHDL_CFG_bta_en(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PCKHDL_CFG_bta_en_SHIFT)) & MIPI_DSI_PCKHDL_CFG_bta_en_MASK)

#define MIPI_DSI_PCKHDL_CFG_ecc_rx_en_MASK       (0x8U)
#define MIPI_DSI_PCKHDL_CFG_ecc_rx_en_SHIFT      (3U)
/*! ecc_rx_en - ECC Receive Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PCKHDL_CFG_ecc_rx_en(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PCKHDL_CFG_ecc_rx_en_SHIFT)) & MIPI_DSI_PCKHDL_CFG_ecc_rx_en_MASK)

#define MIPI_DSI_PCKHDL_CFG_crc_rx_en_MASK       (0x10U)
#define MIPI_DSI_PCKHDL_CFG_crc_rx_en_SHIFT      (4U)
/*! crc_rx_en - CRC Receive Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PCKHDL_CFG_crc_rx_en(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PCKHDL_CFG_crc_rx_en_SHIFT)) & MIPI_DSI_PCKHDL_CFG_crc_rx_en_MASK)

#define MIPI_DSI_PCKHDL_CFG_eotp_tx_lp_en_MASK   (0x20U)
#define MIPI_DSI_PCKHDL_CFG_eotp_tx_lp_en_SHIFT  (5U)
/*! eotp_tx_lp_en - EoTp Transmit Low-power Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PCKHDL_CFG_eotp_tx_lp_en(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PCKHDL_CFG_eotp_tx_lp_en_SHIFT)) & MIPI_DSI_PCKHDL_CFG_eotp_tx_lp_en_MASK)
/*! @} */

/*! @name GEN_VCID - Generic Interface Virtual Channel ID */
/*! @{ */

#define MIPI_DSI_GEN_VCID_gen_vcid_rx_MASK       (0x3U)
#define MIPI_DSI_GEN_VCID_gen_vcid_rx_SHIFT      (0U)
/*! gen_vcid_rx - Generic Virtual Channel ID Receive */
#define MIPI_DSI_GEN_VCID_gen_vcid_rx(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_VCID_gen_vcid_rx_SHIFT)) & MIPI_DSI_GEN_VCID_gen_vcid_rx_MASK)

#define MIPI_DSI_GEN_VCID_gen_vcid_tear_auto_MASK (0x300U)
#define MIPI_DSI_GEN_VCID_gen_vcid_tear_auto_SHIFT (8U)
/*! gen_vcid_tear_auto - Generic Virtual Channel ID Tear Effect */
#define MIPI_DSI_GEN_VCID_gen_vcid_tear_auto(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_VCID_gen_vcid_tear_auto_SHIFT)) & MIPI_DSI_GEN_VCID_gen_vcid_tear_auto_MASK)

#define MIPI_DSI_GEN_VCID_gen_vcid_tx_auto_MASK  (0x30000U)
#define MIPI_DSI_GEN_VCID_gen_vcid_tx_auto_SHIFT (16U)
/*! gen_vcid_tx_auto - Generic Virtual Channel ID Transmit */
#define MIPI_DSI_GEN_VCID_gen_vcid_tx_auto(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_VCID_gen_vcid_tx_auto_SHIFT)) & MIPI_DSI_GEN_VCID_gen_vcid_tx_auto_MASK)
/*! @} */

/*! @name MODE_CFG - Mode Configuration */
/*! @{ */

#define MIPI_DSI_MODE_CFG_cmd_video_mode_MASK    (0x1U)
#define MIPI_DSI_MODE_CFG_cmd_video_mode_SHIFT   (0U)
/*! cmd_video_mode - Command/Video Mode
 *  0b0..Video mode
 *  0b1..Command mode
 */
#define MIPI_DSI_MODE_CFG_cmd_video_mode(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_MODE_CFG_cmd_video_mode_SHIFT)) & MIPI_DSI_MODE_CFG_cmd_video_mode_MASK)
/*! @} */

/*! @name VID_MODE_CFG - Video Mode Configuration */
/*! @{ */

#define MIPI_DSI_VID_MODE_CFG_vid_mode_type_MASK (0x3U)
#define MIPI_DSI_VID_MODE_CFG_vid_mode_type_SHIFT (0U)
/*! vid_mode_type - Video Mode Type
 *  0b00..Non-burst with sync pulses
 *  0b01..Non-burst with sync events
 *  0b10..Burst mode
 *  0b11..Burst mode
 */
#define MIPI_DSI_VID_MODE_CFG_vid_mode_type(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_vid_mode_type_SHIFT)) & MIPI_DSI_VID_MODE_CFG_vid_mode_type_MASK)

#define MIPI_DSI_VID_MODE_CFG_lp_vsa_en_MASK     (0x100U)
#define MIPI_DSI_VID_MODE_CFG_lp_vsa_en_SHIFT    (8U)
/*! lp_vsa_en - Low-power VSA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_lp_vsa_en(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_lp_vsa_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_lp_vsa_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_lp_vbp_en_MASK     (0x200U)
#define MIPI_DSI_VID_MODE_CFG_lp_vbp_en_SHIFT    (9U)
/*! lp_vbp_en - Low-power VBP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_lp_vbp_en(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_lp_vbp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_lp_vbp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_lp_vfp_en_MASK     (0x400U)
#define MIPI_DSI_VID_MODE_CFG_lp_vfp_en_SHIFT    (10U)
/*! lp_vfp_en - Low-power VFP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_lp_vfp_en(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_lp_vfp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_lp_vfp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_lp_vact_en_MASK    (0x800U)
#define MIPI_DSI_VID_MODE_CFG_lp_vact_en_SHIFT   (11U)
/*! lp_vact_en - Low-power VACT Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_lp_vact_en(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_lp_vact_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_lp_vact_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_lp_hbp_en_MASK     (0x1000U)
#define MIPI_DSI_VID_MODE_CFG_lp_hbp_en_SHIFT    (12U)
/*! lp_hbp_en - Low-power HBP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_lp_hbp_en(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_lp_hbp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_lp_hbp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_lp_hfp_en_MASK     (0x2000U)
#define MIPI_DSI_VID_MODE_CFG_lp_hfp_en_SHIFT    (13U)
/*! lp_hfp_en - Low-power HFP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_lp_hfp_en(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_lp_hfp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_lp_hfp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_frame_bta_ack_en_MASK (0x4000U)
#define MIPI_DSI_VID_MODE_CFG_frame_bta_ack_en_SHIFT (14U)
/*! frame_bta_ack_en - Frame BTA Acknowledge Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_frame_bta_ack_en(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_frame_bta_ack_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_frame_bta_ack_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_lp_cmd_en_MASK     (0x8000U)
#define MIPI_DSI_VID_MODE_CFG_lp_cmd_en_SHIFT    (15U)
/*! lp_cmd_en - Low-power Command Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_lp_cmd_en(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_lp_cmd_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_lp_cmd_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_vpg_en_MASK        (0x10000U)
#define MIPI_DSI_VID_MODE_CFG_vpg_en_SHIFT       (16U)
/*! vpg_en - VPG Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_MODE_CFG_vpg_en(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_vpg_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_vpg_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_vpg_mode_MASK      (0x100000U)
#define MIPI_DSI_VID_MODE_CFG_vpg_mode_SHIFT     (20U)
/*! vpg_mode - VPG Mode
 *  0b0..Horizontal or vertical
 *  0b1..Vertical only
 */
#define MIPI_DSI_VID_MODE_CFG_vpg_mode(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_vpg_mode_SHIFT)) & MIPI_DSI_VID_MODE_CFG_vpg_mode_MASK)

#define MIPI_DSI_VID_MODE_CFG_vpg_orientation_MASK (0x1000000U)
#define MIPI_DSI_VID_MODE_CFG_vpg_orientation_SHIFT (24U)
/*! vpg_orientation - VPG Orientation
 *  0b0..Vertical mode
 *  0b1..Horizontal mode
 */
#define MIPI_DSI_VID_MODE_CFG_vpg_orientation(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_vpg_orientation_SHIFT)) & MIPI_DSI_VID_MODE_CFG_vpg_orientation_MASK)
/*! @} */

/*! @name VID_PKT_SIZE - Video Packet Size */
/*! @{ */

#define MIPI_DSI_VID_PKT_SIZE_vid_pkt_size_MASK  (0x3FFFU)
#define MIPI_DSI_VID_PKT_SIZE_vid_pkt_size_SHIFT (0U)
/*! vid_pkt_size - Video Packet Size */
#define MIPI_DSI_VID_PKT_SIZE_vid_pkt_size(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_SIZE_vid_pkt_size_SHIFT)) & MIPI_DSI_VID_PKT_SIZE_vid_pkt_size_MASK)
/*! @} */

/*! @name VID_NUM_CHUNKS - Video Number of Chunks */
/*! @{ */

#define MIPI_DSI_VID_NUM_CHUNKS_vid_num_chunks_MASK (0x1FFFU)
#define MIPI_DSI_VID_NUM_CHUNKS_vid_num_chunks_SHIFT (0U)
/*! vid_num_chunks - Video Number Chunks */
#define MIPI_DSI_VID_NUM_CHUNKS_vid_num_chunks(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_NUM_CHUNKS_vid_num_chunks_SHIFT)) & MIPI_DSI_VID_NUM_CHUNKS_vid_num_chunks_MASK)
/*! @} */

/*! @name VID_NULL_SIZE - Video Null Packets Size */
/*! @{ */

#define MIPI_DSI_VID_NULL_SIZE_vid_null_size_MASK (0x1FFFU)
#define MIPI_DSI_VID_NULL_SIZE_vid_null_size_SHIFT (0U)
/*! vid_null_size - Video Null Size */
#define MIPI_DSI_VID_NULL_SIZE_vid_null_size(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_NULL_SIZE_vid_null_size_SHIFT)) & MIPI_DSI_VID_NULL_SIZE_vid_null_size_MASK)
/*! @} */

/*! @name VID_HSA_TIME - Video HSA Time */
/*! @{ */

#define MIPI_DSI_VID_HSA_TIME_vid_hsa_time_MASK  (0xFFFU)
#define MIPI_DSI_VID_HSA_TIME_vid_hsa_time_SHIFT (0U)
/*! vid_hsa_time - Video HSA Time */
#define MIPI_DSI_VID_HSA_TIME_vid_hsa_time(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_HSA_TIME_vid_hsa_time_SHIFT)) & MIPI_DSI_VID_HSA_TIME_vid_hsa_time_MASK)
/*! @} */

/*! @name VID_HBP_TIME - Video HBP Time */
/*! @{ */

#define MIPI_DSI_VID_HBP_TIME_vid_hbp_time_MASK  (0xFFFU)
#define MIPI_DSI_VID_HBP_TIME_vid_hbp_time_SHIFT (0U)
/*! vid_hbp_time - Video HBP Time */
#define MIPI_DSI_VID_HBP_TIME_vid_hbp_time(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_HBP_TIME_vid_hbp_time_SHIFT)) & MIPI_DSI_VID_HBP_TIME_vid_hbp_time_MASK)
/*! @} */

/*! @name VID_HLINE_TIME - Video Line Time */
/*! @{ */

#define MIPI_DSI_VID_HLINE_TIME_vid_hline_time_MASK (0x7FFFU)
#define MIPI_DSI_VID_HLINE_TIME_vid_hline_time_SHIFT (0U)
/*! vid_hline_time - Video Total Line Time */
#define MIPI_DSI_VID_HLINE_TIME_vid_hline_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_HLINE_TIME_vid_hline_time_SHIFT)) & MIPI_DSI_VID_HLINE_TIME_vid_hline_time_MASK)
/*! @} */

/*! @name VID_VSA_LINES - VSA Period */
/*! @{ */

#define MIPI_DSI_VID_VSA_LINES_vsa_lines_MASK    (0x3FFU)
#define MIPI_DSI_VID_VSA_LINES_vsa_lines_SHIFT   (0U)
/*! vsa_lines - VSA Lines */
#define MIPI_DSI_VID_VSA_LINES_vsa_lines(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VSA_LINES_vsa_lines_SHIFT)) & MIPI_DSI_VID_VSA_LINES_vsa_lines_MASK)
/*! @} */

/*! @name VID_VBP_LINES - VBP Period */
/*! @{ */

#define MIPI_DSI_VID_VBP_LINES_vbp_lines_MASK    (0x3FFU)
#define MIPI_DSI_VID_VBP_LINES_vbp_lines_SHIFT   (0U)
/*! vbp_lines - VBP Lines */
#define MIPI_DSI_VID_VBP_LINES_vbp_lines(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VBP_LINES_vbp_lines_SHIFT)) & MIPI_DSI_VID_VBP_LINES_vbp_lines_MASK)
/*! @} */

/*! @name VID_VFP_LINES - VFP Period */
/*! @{ */

#define MIPI_DSI_VID_VFP_LINES_vfp_lines_MASK    (0x3FFU)
#define MIPI_DSI_VID_VFP_LINES_vfp_lines_SHIFT   (0U)
/*! vfp_lines - VFP Lines */
#define MIPI_DSI_VID_VFP_LINES_vfp_lines(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VFP_LINES_vfp_lines_SHIFT)) & MIPI_DSI_VID_VFP_LINES_vfp_lines_MASK)
/*! @} */

/*! @name VID_VACTIVE_LINES - Vertical Resolution of Video */
/*! @{ */

#define MIPI_DSI_VID_VACTIVE_LINES_v_active_lines_MASK (0x3FFFU)
#define MIPI_DSI_VID_VACTIVE_LINES_v_active_lines_SHIFT (0U)
/*! v_active_lines - Vertical Active Lines */
#define MIPI_DSI_VID_VACTIVE_LINES_v_active_lines(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VACTIVE_LINES_v_active_lines_SHIFT)) & MIPI_DSI_VID_VACTIVE_LINES_v_active_lines_MASK)
/*! @} */

/*! @name CMD_MODE_CFG - Command Mode Configuration */
/*! @{ */

#define MIPI_DSI_CMD_MODE_CFG_tear_fx_en_MASK    (0x1U)
#define MIPI_DSI_CMD_MODE_CFG_tear_fx_en_SHIFT   (0U)
/*! tear_fx_en - Tearing Effect Acknowledge Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_CMD_MODE_CFG_tear_fx_en(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_tear_fx_en_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_tear_fx_en_MASK)

#define MIPI_DSI_CMD_MODE_CFG_ack_rqst_en_MASK   (0x2U)
#define MIPI_DSI_CMD_MODE_CFG_ack_rqst_en_SHIFT  (1U)
/*! ack_rqst_en - Acknowledge Request Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_CMD_MODE_CFG_ack_rqst_en(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_ack_rqst_en_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_ack_rqst_en_MASK)

#define MIPI_DSI_CMD_MODE_CFG_gen_sw_0p_tx_MASK  (0x100U)
#define MIPI_DSI_CMD_MODE_CFG_gen_sw_0p_tx_SHIFT (8U)
/*! gen_sw_0p_tx - Generic Short Write Zero Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_gen_sw_0p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_gen_sw_0p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_gen_sw_0p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_gen_sw_1p_tx_MASK  (0x200U)
#define MIPI_DSI_CMD_MODE_CFG_gen_sw_1p_tx_SHIFT (9U)
/*! gen_sw_1p_tx - Generic Short Write One Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_gen_sw_1p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_gen_sw_1p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_gen_sw_1p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_gen_sw_2p_tx_MASK  (0x400U)
#define MIPI_DSI_CMD_MODE_CFG_gen_sw_2p_tx_SHIFT (10U)
/*! gen_sw_2p_tx - Generic Short Write Two Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_gen_sw_2p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_gen_sw_2p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_gen_sw_2p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_gen_sr_0p_tx_MASK  (0x800U)
#define MIPI_DSI_CMD_MODE_CFG_gen_sr_0p_tx_SHIFT (11U)
/*! gen_sr_0p_tx - Generic Short Read Zero Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_gen_sr_0p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_gen_sr_0p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_gen_sr_0p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_gen_sr_1p_tx_MASK  (0x1000U)
#define MIPI_DSI_CMD_MODE_CFG_gen_sr_1p_tx_SHIFT (12U)
/*! gen_sr_1p_tx - Generic Short Read One Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_gen_sr_1p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_gen_sr_1p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_gen_sr_1p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_gen_sr_2p_tx_MASK  (0x2000U)
#define MIPI_DSI_CMD_MODE_CFG_gen_sr_2p_tx_SHIFT (13U)
/*! gen_sr_2p_tx - Generic Short Read Two Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_gen_sr_2p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_gen_sr_2p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_gen_sr_2p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_gen_lw_tx_MASK     (0x4000U)
#define MIPI_DSI_CMD_MODE_CFG_gen_lw_tx_SHIFT    (14U)
/*! gen_lw_tx - Generic Long Write Packet Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_gen_lw_tx(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_gen_lw_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_gen_lw_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_dcs_sw_0p_tx_MASK  (0x10000U)
#define MIPI_DSI_CMD_MODE_CFG_dcs_sw_0p_tx_SHIFT (16U)
/*! dcs_sw_0p_tx - DCS Short Write Zero Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_dcs_sw_0p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_dcs_sw_0p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_dcs_sw_0p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_dcs_sw_1p_tx_MASK  (0x20000U)
#define MIPI_DSI_CMD_MODE_CFG_dcs_sw_1p_tx_SHIFT (17U)
/*! dcs_sw_1p_tx - DCS Short Write One Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_dcs_sw_1p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_dcs_sw_1p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_dcs_sw_1p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_dcs_sr_0p_tx_MASK  (0x40000U)
#define MIPI_DSI_CMD_MODE_CFG_dcs_sr_0p_tx_SHIFT (18U)
/*! dcs_sr_0p_tx - DCS Short Read Zero Parameter Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_dcs_sr_0p_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_dcs_sr_0p_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_dcs_sr_0p_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_dcs_lw_tx_MASK     (0x80000U)
#define MIPI_DSI_CMD_MODE_CFG_dcs_lw_tx_SHIFT    (19U)
/*! dcs_lw_tx - DCS Long Write Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_dcs_lw_tx(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_dcs_lw_tx_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_dcs_lw_tx_MASK)

#define MIPI_DSI_CMD_MODE_CFG_max_rd_pkt_size_MASK (0x1000000U)
#define MIPI_DSI_CMD_MODE_CFG_max_rd_pkt_size_SHIFT (24U)
/*! max_rd_pkt_size - Maximum Read Packet Size Command Transmit
 *  0b0..Transition type is high-speed
 *  0b1..Transition type is low-power
 */
#define MIPI_DSI_CMD_MODE_CFG_max_rd_pkt_size(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_MODE_CFG_max_rd_pkt_size_SHIFT)) & MIPI_DSI_CMD_MODE_CFG_max_rd_pkt_size_MASK)
/*! @} */

/*! @name GEN_HDR - Generic Interface Header Packet Configuration */
/*! @{ */

#define MIPI_DSI_GEN_HDR_gen_dt_MASK             (0x3FU)
#define MIPI_DSI_GEN_HDR_gen_dt_SHIFT            (0U)
/*! gen_dt - Generic Data Type */
#define MIPI_DSI_GEN_HDR_gen_dt(x)               (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_HDR_gen_dt_SHIFT)) & MIPI_DSI_GEN_HDR_gen_dt_MASK)

#define MIPI_DSI_GEN_HDR_gen_vc_MASK             (0xC0U)
#define MIPI_DSI_GEN_HDR_gen_vc_SHIFT            (6U)
/*! gen_vc - Generic Virtual Channel ID */
#define MIPI_DSI_GEN_HDR_gen_vc(x)               (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_HDR_gen_vc_SHIFT)) & MIPI_DSI_GEN_HDR_gen_vc_MASK)

#define MIPI_DSI_GEN_HDR_gen_wc_lsbyte_MASK      (0xFF00U)
#define MIPI_DSI_GEN_HDR_gen_wc_lsbyte_SHIFT     (8U)
/*! gen_wc_lsbyte - Generic Word Count LSB */
#define MIPI_DSI_GEN_HDR_gen_wc_lsbyte(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_HDR_gen_wc_lsbyte_SHIFT)) & MIPI_DSI_GEN_HDR_gen_wc_lsbyte_MASK)

#define MIPI_DSI_GEN_HDR_gen_wc_msbyte_MASK      (0xFF0000U)
#define MIPI_DSI_GEN_HDR_gen_wc_msbyte_SHIFT     (16U)
/*! gen_wc_msbyte - Generic Word Count MSB */
#define MIPI_DSI_GEN_HDR_gen_wc_msbyte(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_HDR_gen_wc_msbyte_SHIFT)) & MIPI_DSI_GEN_HDR_gen_wc_msbyte_MASK)
/*! @} */

/*! @name GEN_PLD_DATA - Generic Interface Payload Data */
/*! @{ */

#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b1_MASK    (0xFFU)
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b1_SHIFT   (0U)
/*! gen_pld_b1 - Generic Payload Byte 1 */
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b1(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_PLD_DATA_gen_pld_b1_SHIFT)) & MIPI_DSI_GEN_PLD_DATA_gen_pld_b1_MASK)

#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b2_MASK    (0xFF00U)
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b2_SHIFT   (8U)
/*! gen_pld_b2 - Generic Payload Byte 2 */
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b2(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_PLD_DATA_gen_pld_b2_SHIFT)) & MIPI_DSI_GEN_PLD_DATA_gen_pld_b2_MASK)

#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b3_MASK    (0xFF0000U)
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b3_SHIFT   (16U)
/*! gen_pld_b3 - Generic Payload Byte 3 */
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b3(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_PLD_DATA_gen_pld_b3_SHIFT)) & MIPI_DSI_GEN_PLD_DATA_gen_pld_b3_MASK)

#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b4_MASK    (0xFF000000U)
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b4_SHIFT   (24U)
/*! gen_pld_b4 - Generic Payload Byte 4 */
#define MIPI_DSI_GEN_PLD_DATA_gen_pld_b4(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_GEN_PLD_DATA_gen_pld_b4_SHIFT)) & MIPI_DSI_GEN_PLD_DATA_gen_pld_b4_MASK)
/*! @} */

/*! @name CMD_PKT_STATUS - Command Packet Status */
/*! @{ */

#define MIPI_DSI_CMD_PKT_STATUS_gen_cmd_empty_MASK (0x1U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_cmd_empty_SHIFT (0U)
/*! gen_cmd_empty - Generic Command Empty
 *  0b0..Not Empty
 *  0b1..Empty
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_cmd_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_cmd_empty_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_cmd_empty_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_cmd_full_MASK (0x2U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_cmd_full_SHIFT (1U)
/*! gen_cmd_full - Generic Command Full
 *  0b0..Not Full
 *  0b1..Full
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_cmd_full(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_cmd_full_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_cmd_full_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_empty_MASK (0x4U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_empty_SHIFT (2U)
/*! gen_pld_w_empty - Generic Payload Write Empty
 *  0b0..Not Empty
 *  0b1..Empty
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_empty_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_empty_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_full_MASK (0x8U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_full_SHIFT (3U)
/*! gen_pld_w_full - Generic Payload Write Full
 *  0b0..Not Full
 *  0b1..Full
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_full(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_full_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_pld_w_full_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_empty_MASK (0x10U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_empty_SHIFT (4U)
/*! gen_pld_r_empty - Generic Payload Read Empty
 *  0b0..Not Empty
 *  0b1..Empty
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_empty_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_empty_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_full_MASK (0x20U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_full_SHIFT (5U)
/*! gen_pld_r_full - Generic Payload Read Full
 *  0b0..Not Full
 *  0b1..Full
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_full(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_full_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_pld_r_full_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_rd_cmd_busy_MASK (0x40U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_rd_cmd_busy_SHIFT (6U)
/*! gen_rd_cmd_busy - Generic Read Command Busy
 *  0b0..Not Busy
 *  0b1..Busy
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_rd_cmd_busy(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_rd_cmd_busy_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_rd_cmd_busy_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_empty_MASK (0x10000U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_empty_SHIFT (16U)
/*! gen_buff_cmd_empty - Generic Buffer for Command Empty
 *  0b0..Not Empty
 *  0b1..Empty
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_empty_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_empty_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_full_MASK (0x20000U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_full_SHIFT (17U)
/*! gen_buff_cmd_full - Generic Buffer for Command Full
 *  0b0..Not Full
 *  0b1..Full
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_full(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_full_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_buff_cmd_full_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_empty_MASK (0x40000U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_empty_SHIFT (18U)
/*! gen_buff_pld_empty - Generic Buffer for Payload Empty
 *  0b0..Not Empty
 *  0b1..Empty
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_empty_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_empty_MASK)

#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_full_MASK (0x80000U)
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_full_SHIFT (19U)
/*! gen_buff_pld_full - Generic Buffer for Payload Full
 *  0b0..Not Full
 *  0b1..Full
 */
#define MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_full(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_full_SHIFT)) & MIPI_DSI_CMD_PKT_STATUS_gen_buff_pld_full_MASK)
/*! @} */

/*! @name TO_CNT_CFG - Timeout Counter Configuration */
/*! @{ */

#define MIPI_DSI_TO_CNT_CFG_lprx_to_cnt_MASK     (0xFFFFU)
#define MIPI_DSI_TO_CNT_CFG_lprx_to_cnt_SHIFT    (0U)
/*! lprx_to_cnt - Low-power Timeout Count */
#define MIPI_DSI_TO_CNT_CFG_lprx_to_cnt(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_TO_CNT_CFG_lprx_to_cnt_SHIFT)) & MIPI_DSI_TO_CNT_CFG_lprx_to_cnt_MASK)

#define MIPI_DSI_TO_CNT_CFG_hstx_to_cnt_MASK     (0xFFFF0000U)
#define MIPI_DSI_TO_CNT_CFG_hstx_to_cnt_SHIFT    (16U)
/*! hstx_to_cnt - High-speed Timeout Count */
#define MIPI_DSI_TO_CNT_CFG_hstx_to_cnt(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_TO_CNT_CFG_hstx_to_cnt_SHIFT)) & MIPI_DSI_TO_CNT_CFG_hstx_to_cnt_MASK)
/*! @} */

/*! @name HS_RD_TO_CNT - Peripheral Response Timeout after High-speed Read Operations */
/*! @{ */

#define MIPI_DSI_HS_RD_TO_CNT_hs_rd_to_cnt_MASK  (0xFFFFU)
#define MIPI_DSI_HS_RD_TO_CNT_hs_rd_to_cnt_SHIFT (0U)
/*! hs_rd_to_cnt - High-speed Read Timeout Count */
#define MIPI_DSI_HS_RD_TO_CNT_hs_rd_to_cnt(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HS_RD_TO_CNT_hs_rd_to_cnt_SHIFT)) & MIPI_DSI_HS_RD_TO_CNT_hs_rd_to_cnt_MASK)
/*! @} */

/*! @name LP_RD_TO_CNT - Peripheral Response Timeout after Low-power Read Operations */
/*! @{ */

#define MIPI_DSI_LP_RD_TO_CNT_lp_rd_to_cnt_MASK  (0xFFFFU)
#define MIPI_DSI_LP_RD_TO_CNT_lp_rd_to_cnt_SHIFT (0U)
/*! lp_rd_to_cnt - Low-power Read Timeout Count */
#define MIPI_DSI_LP_RD_TO_CNT_lp_rd_to_cnt(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_LP_RD_TO_CNT_lp_rd_to_cnt_SHIFT)) & MIPI_DSI_LP_RD_TO_CNT_lp_rd_to_cnt_MASK)
/*! @} */

/*! @name HS_WR_TO_CNT - Peripheral Response Timeout after High-speed Write Operations */
/*! @{ */

#define MIPI_DSI_HS_WR_TO_CNT_hs_wr_to_cnt_MASK  (0xFFFFU)
#define MIPI_DSI_HS_WR_TO_CNT_hs_wr_to_cnt_SHIFT (0U)
/*! hs_wr_to_cnt - High-speed Write Timeout Count */
#define MIPI_DSI_HS_WR_TO_CNT_hs_wr_to_cnt(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_HS_WR_TO_CNT_hs_wr_to_cnt_SHIFT)) & MIPI_DSI_HS_WR_TO_CNT_hs_wr_to_cnt_MASK)
/*! @} */

/*! @name LP_WR_TO_CNT - Peripheral Response Timeout after Low-power Write Operations */
/*! @{ */

#define MIPI_DSI_LP_WR_TO_CNT_lp_wr_to_cnt_MASK  (0xFFFFU)
#define MIPI_DSI_LP_WR_TO_CNT_lp_wr_to_cnt_SHIFT (0U)
/*! lp_wr_to_cnt - Low-power Write Timeout Count */
#define MIPI_DSI_LP_WR_TO_CNT_lp_wr_to_cnt(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_LP_WR_TO_CNT_lp_wr_to_cnt_SHIFT)) & MIPI_DSI_LP_WR_TO_CNT_lp_wr_to_cnt_MASK)
/*! @} */

/*! @name BTA_TO_CNT - Peripheral Response Timeout after Bus Turnaround Completion */
/*! @{ */

#define MIPI_DSI_BTA_TO_CNT_bta_to_cnt_MASK      (0xFFFFU)
#define MIPI_DSI_BTA_TO_CNT_bta_to_cnt_SHIFT     (0U)
/*! bta_to_cnt - BTA Timeout Count */
#define MIPI_DSI_BTA_TO_CNT_bta_to_cnt(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_BTA_TO_CNT_bta_to_cnt_SHIFT)) & MIPI_DSI_BTA_TO_CNT_bta_to_cnt_MASK)
/*! @} */

/*! @name SDF_3D - 3D Control Information for VSS Packets in Video Mode */
/*! @{ */

#define MIPI_DSI_SDF_3D_mode_3d_MASK             (0x3U)
#define MIPI_DSI_SDF_3D_mode_3d_SHIFT            (0U)
/*! mode_3d - Mode 3D
 *  0b00..3D Mode Off , 2D Mode On
 *  0b01..3D Mode On, Portrait Orientation
 *  0b10..3D Mode On, Landscape Orientation
 *  0b11..
 */
#define MIPI_DSI_SDF_3D_mode_3d(x)               (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_mode_3d_SHIFT)) & MIPI_DSI_SDF_3D_mode_3d_MASK)

#define MIPI_DSI_SDF_3D_format_3d_MASK           (0xCU)
#define MIPI_DSI_SDF_3D_format_3d_SHIFT          (2U)
/*! format_3d - Format 3D
 *  0b00..Alternating lines of left and right data
 *  0b01..Alternating frames of left and right data
 *  0b10..Alternating pixels of left and right data
 *  0b11..
 */
#define MIPI_DSI_SDF_3D_format_3d(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_format_3d_SHIFT)) & MIPI_DSI_SDF_3D_format_3d_MASK)

#define MIPI_DSI_SDF_3D_second_vsync_MASK        (0x10U)
#define MIPI_DSI_SDF_3D_second_vsync_SHIFT       (4U)
/*! second_vsync - Second VSYNC
 *  0b0..No sync pulses between left and right data
 *  0b1..Sync pulse HSYNC, VSYNC, blanking between left and right data
 */
#define MIPI_DSI_SDF_3D_second_vsync(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_second_vsync_SHIFT)) & MIPI_DSI_SDF_3D_second_vsync_MASK)

#define MIPI_DSI_SDF_3D_right_first_MASK         (0x20U)
#define MIPI_DSI_SDF_3D_right_first_SHIFT        (5U)
/*! right_first - Right First
 *  0b0..Left eye is sent first, then right eye
 *  0b1..Right eye data is sent first, then left eye
 */
#define MIPI_DSI_SDF_3D_right_first(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_right_first_SHIFT)) & MIPI_DSI_SDF_3D_right_first_MASK)

#define MIPI_DSI_SDF_3D_send_3d_cfg_MASK         (0x10000U)
#define MIPI_DSI_SDF_3D_send_3d_cfg_SHIFT        (16U)
/*! send_3d_cfg - Send 3D Control Payload
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_SDF_3D_send_3d_cfg(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_send_3d_cfg_SHIFT)) & MIPI_DSI_SDF_3D_send_3d_cfg_MASK)
/*! @} */

/*! @name LPCLK_CTRL - LP Clock Control */
/*! @{ */

#define MIPI_DSI_LPCLK_CTRL_phy_txrequestclkhs_MASK (0x1U)
#define MIPI_DSI_LPCLK_CTRL_phy_txrequestclkhs_SHIFT (0U)
/*! phy_txrequestclkhs - D-PHY txrequestclkhs Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_LPCLK_CTRL_phy_txrequestclkhs(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_LPCLK_CTRL_phy_txrequestclkhs_SHIFT)) & MIPI_DSI_LPCLK_CTRL_phy_txrequestclkhs_MASK)

#define MIPI_DSI_LPCLK_CTRL_auto_clklane_ctrl_MASK (0x2U)
#define MIPI_DSI_LPCLK_CTRL_auto_clklane_ctrl_SHIFT (1U)
/*! auto_clklane_ctrl - Automatic Clock Lane Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_LPCLK_CTRL_auto_clklane_ctrl(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_LPCLK_CTRL_auto_clklane_ctrl_SHIFT)) & MIPI_DSI_LPCLK_CTRL_auto_clklane_ctrl_MASK)
/*! @} */

/*! @name PHY_TMR_LPCLK_CFG - D-PHY Clock Lanes LP2HS and HS2LP Time Configuration */
/*! @{ */

#define MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clklp2hs_time_MASK (0x3FFU)
#define MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clklp2hs_time_SHIFT (0U)
/*! phy_clklp2hs_time - D-PHY Clock Low Power to High Power Time */
#define MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clklp2hs_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clklp2hs_time_SHIFT)) & MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clklp2hs_time_MASK)

#define MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clkhs2lp_time_MASK (0x3FF0000U)
#define MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clkhs2lp_time_SHIFT (16U)
/*! phy_clkhs2lp_time - D-PHY Clock High Power to Low Power Time */
#define MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clkhs2lp_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clkhs2lp_time_SHIFT)) & MIPI_DSI_PHY_TMR_LPCLK_CFG_phy_clkhs2lp_time_MASK)
/*! @} */

/*! @name PHY_TMR_CFG - D-PHY Data Lanes LP2HS and HS2LP Time Configuration */
/*! @{ */

#define MIPI_DSI_PHY_TMR_CFG_phy_lp2hs_time_MASK (0x3FFU)
#define MIPI_DSI_PHY_TMR_CFG_phy_lp2hs_time_SHIFT (0U)
/*! phy_lp2hs_time - D-PHY Low-power to High-speed Time */
#define MIPI_DSI_PHY_TMR_CFG_phy_lp2hs_time(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TMR_CFG_phy_lp2hs_time_SHIFT)) & MIPI_DSI_PHY_TMR_CFG_phy_lp2hs_time_MASK)

#define MIPI_DSI_PHY_TMR_CFG_phy_hs2lp_time_MASK (0x3FF0000U)
#define MIPI_DSI_PHY_TMR_CFG_phy_hs2lp_time_SHIFT (16U)
/*! phy_hs2lp_time - D-PHY High-speed to Low-power Time */
#define MIPI_DSI_PHY_TMR_CFG_phy_hs2lp_time(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TMR_CFG_phy_hs2lp_time_SHIFT)) & MIPI_DSI_PHY_TMR_CFG_phy_hs2lp_time_MASK)
/*! @} */

/*! @name PHY_RSTZ - D-PHY Reset Control */
/*! @{ */

#define MIPI_DSI_PHY_RSTZ_phy_shutdownz_MASK     (0x1U)
#define MIPI_DSI_PHY_RSTZ_phy_shutdownz_SHIFT    (0U)
/*! phy_shutdownz - D-PHY Power-down State */
#define MIPI_DSI_PHY_RSTZ_phy_shutdownz(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_RSTZ_phy_shutdownz_SHIFT)) & MIPI_DSI_PHY_RSTZ_phy_shutdownz_MASK)

#define MIPI_DSI_PHY_RSTZ_phy_rstz_MASK          (0x2U)
#define MIPI_DSI_PHY_RSTZ_phy_rstz_SHIFT         (1U)
/*! phy_rstz - D-PHY Reset State */
#define MIPI_DSI_PHY_RSTZ_phy_rstz(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_RSTZ_phy_rstz_SHIFT)) & MIPI_DSI_PHY_RSTZ_phy_rstz_MASK)

#define MIPI_DSI_PHY_RSTZ_phy_enableclk_MASK     (0x4U)
#define MIPI_DSI_PHY_RSTZ_phy_enableclk_SHIFT    (2U)
/*! phy_enableclk - D-PHY Enable Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PHY_RSTZ_phy_enableclk(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_RSTZ_phy_enableclk_SHIFT)) & MIPI_DSI_PHY_RSTZ_phy_enableclk_MASK)

#define MIPI_DSI_PHY_RSTZ_phy_forcepll_MASK      (0x8U)
#define MIPI_DSI_PHY_RSTZ_phy_forcepll_SHIFT     (3U)
/*! phy_forcepll - D-PHY Force PLL
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_PHY_RSTZ_phy_forcepll(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_RSTZ_phy_forcepll_SHIFT)) & MIPI_DSI_PHY_RSTZ_phy_forcepll_MASK)
/*! @} */

/*! @name PHY_IF_CFG - PHY Interface Configuration */
/*! @{ */

#define MIPI_DSI_PHY_IF_CFG_n_lanes_MASK         (0x3U)
#define MIPI_DSI_PHY_IF_CFG_n_lanes_SHIFT        (0U)
/*! n_lanes - Number of Lanes
 *  0b00..lane 0
 *  0b01..lanes 0 and 1
 *  0b10..lanes 0, 1, and 2
 *  0b11..lanes 0, 1, 2, and 3
 */
#define MIPI_DSI_PHY_IF_CFG_n_lanes(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_IF_CFG_n_lanes_SHIFT)) & MIPI_DSI_PHY_IF_CFG_n_lanes_MASK)

#define MIPI_DSI_PHY_IF_CFG_phy_stop_wait_time_MASK (0xFF00U)
#define MIPI_DSI_PHY_IF_CFG_phy_stop_wait_time_SHIFT (8U)
/*! phy_stop_wait_time - PHY Stop Wait Time */
#define MIPI_DSI_PHY_IF_CFG_phy_stop_wait_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_IF_CFG_phy_stop_wait_time_SHIFT)) & MIPI_DSI_PHY_IF_CFG_phy_stop_wait_time_MASK)
/*! @} */

/*! @name PHY_ULPS_CTRL - D-PHY ULPS Control */
/*! @{ */

#define MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpsclk_MASK (0x1U)
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpsclk_SHIFT (0U)
/*! phy_txrequlpsclk - ULPS Mode Request on Clock Lane */
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpsclk(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpsclk_SHIFT)) & MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpsclk_MASK)

#define MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpsclk_MASK (0x2U)
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpsclk_SHIFT (1U)
/*! phy_txexitulpsclk - ULPS Mode Exit on Clock Lane */
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpsclk(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpsclk_SHIFT)) & MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpsclk_MASK)

#define MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpslan_MASK (0x4U)
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpslan_SHIFT (2U)
/*! phy_txrequlpslan - ULPS Mode Request on All Active Data Lanes */
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpslan(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpslan_SHIFT)) & MIPI_DSI_PHY_ULPS_CTRL_phy_txrequlpslan_MASK)

#define MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpslan_MASK (0x8U)
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpslan_SHIFT (3U)
/*! phy_txexitulpslan - ULPS Mode Exit on All Active Data Lanes */
#define MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpslan(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpslan_SHIFT)) & MIPI_DSI_PHY_ULPS_CTRL_phy_txexitulpslan_MASK)
/*! @} */

/*! @name PHY_TX_TRIGGERS - D-PHY Trigger Transmission Control */
/*! @{ */

#define MIPI_DSI_PHY_TX_TRIGGERS_phy_tx_triggers_MASK (0xFU)
#define MIPI_DSI_PHY_TX_TRIGGERS_phy_tx_triggers_SHIFT (0U)
/*! phy_tx_triggers - Controls the Trigger Transmissions. */
#define MIPI_DSI_PHY_TX_TRIGGERS_phy_tx_triggers(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TX_TRIGGERS_phy_tx_triggers_SHIFT)) & MIPI_DSI_PHY_TX_TRIGGERS_phy_tx_triggers_MASK)
/*! @} */

/*! @name PHY_STATUS - D-PHY Status */
/*! @{ */

#define MIPI_DSI_PHY_STATUS_phy_lock_MASK        (0x1U)
#define MIPI_DSI_PHY_STATUS_phy_lock_SHIFT       (0U)
/*! phy_lock - D-PHY Lock */
#define MIPI_DSI_PHY_STATUS_phy_lock(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_lock_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_lock_MASK)

#define MIPI_DSI_PHY_STATUS_phy_direction_MASK   (0x2U)
#define MIPI_DSI_PHY_STATUS_phy_direction_SHIFT  (1U)
/*! phy_direction - D-PHY Direction */
#define MIPI_DSI_PHY_STATUS_phy_direction(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_direction_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_direction_MASK)

#define MIPI_DSI_PHY_STATUS_phy_stopstateclklane_MASK (0x4U)
#define MIPI_DSI_PHY_STATUS_phy_stopstateclklane_SHIFT (2U)
/*! phy_stopstateclklane - D-PHY stopstateclklane */
#define MIPI_DSI_PHY_STATUS_phy_stopstateclklane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_stopstateclklane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_stopstateclklane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenotclk_MASK (0x8U)
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenotclk_SHIFT (3U)
/*! phy_ulpsactivenotclk - D-PHY phy_ulpsactivenotclk */
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenotclk(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_ulpsactivenotclk_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_ulpsactivenotclk_MASK)

#define MIPI_DSI_PHY_STATUS_phy_stopstate0lane_MASK (0x10U)
#define MIPI_DSI_PHY_STATUS_phy_stopstate0lane_SHIFT (4U)
/*! phy_stopstate0lane - D-PHY phystopstate0lane */
#define MIPI_DSI_PHY_STATUS_phy_stopstate0lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_stopstate0lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_stopstate0lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot0lane_MASK (0x20U)
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot0lane_SHIFT (5U)
/*! phy_ulpsactivenot0lane - D-PHY ulpsactivenot0lane */
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot0lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_ulpsactivenot0lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_ulpsactivenot0lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_rxulpsesc0lane_MASK (0x40U)
#define MIPI_DSI_PHY_STATUS_phy_rxulpsesc0lane_SHIFT (6U)
/*! phy_rxulpsesc0lane - D-PHY rxulpsesc0lane */
#define MIPI_DSI_PHY_STATUS_phy_rxulpsesc0lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_rxulpsesc0lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_rxulpsesc0lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_stopstate1lane_MASK (0x80U)
#define MIPI_DSI_PHY_STATUS_phy_stopstate1lane_SHIFT (7U)
/*! phy_stopstate1lane - D-PHY phystopstate1lane */
#define MIPI_DSI_PHY_STATUS_phy_stopstate1lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_stopstate1lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_stopstate1lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot1lane_MASK (0x100U)
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot1lane_SHIFT (8U)
/*! phy_ulpsactivenot1lane - D-PHY ulpsactivenot1lane */
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot1lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_ulpsactivenot1lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_ulpsactivenot1lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_stopstate2lane_MASK (0x200U)
#define MIPI_DSI_PHY_STATUS_phy_stopstate2lane_SHIFT (9U)
/*! phy_stopstate2lane - D-PHY phystopstate2lane */
#define MIPI_DSI_PHY_STATUS_phy_stopstate2lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_stopstate2lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_stopstate2lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot2lane_MASK (0x400U)
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot2lane_SHIFT (10U)
/*! phy_ulpsactivenot2lane - D-PHY ulpsactivenot2lane */
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot2lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_ulpsactivenot2lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_ulpsactivenot2lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_stopstate3lane_MASK (0x800U)
#define MIPI_DSI_PHY_STATUS_phy_stopstate3lane_SHIFT (11U)
/*! phy_stopstate3lane - D-PHY phystopstate3lane */
#define MIPI_DSI_PHY_STATUS_phy_stopstate3lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_stopstate3lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_stopstate3lane_MASK)

#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot3lane_MASK (0x1000U)
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot3lane_SHIFT (12U)
/*! phy_ulpsactivenot3lane - D-PHY ulpsactivenot3lane */
#define MIPI_DSI_PHY_STATUS_phy_ulpsactivenot3lane(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_STATUS_phy_ulpsactivenot3lane_SHIFT)) & MIPI_DSI_PHY_STATUS_phy_ulpsactivenot3lane_MASK)
/*! @} */

/*! @name PHY_TST_CTRL0 - D-PHY Test Control 0 */
/*! @{ */

#define MIPI_DSI_PHY_TST_CTRL0_phy_testclr_MASK  (0x1U)
#define MIPI_DSI_PHY_TST_CTRL0_phy_testclr_SHIFT (0U)
/*! phy_testclr - D-PHY Test Interface Clear (active high). */
#define MIPI_DSI_PHY_TST_CTRL0_phy_testclr(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TST_CTRL0_phy_testclr_SHIFT)) & MIPI_DSI_PHY_TST_CTRL0_phy_testclr_MASK)

#define MIPI_DSI_PHY_TST_CTRL0_phy_testclk_MASK  (0x2U)
#define MIPI_DSI_PHY_TST_CTRL0_phy_testclk_SHIFT (1U)
/*! phy_testclk - D-PHY Test Clock */
#define MIPI_DSI_PHY_TST_CTRL0_phy_testclk(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TST_CTRL0_phy_testclk_SHIFT)) & MIPI_DSI_PHY_TST_CTRL0_phy_testclk_MASK)
/*! @} */

/*! @name PHY_TST_CTRL1 - D-PHY Test Control 1 */
/*! @{ */

#define MIPI_DSI_PHY_TST_CTRL1_phy_testdin_MASK  (0xFFU)
#define MIPI_DSI_PHY_TST_CTRL1_phy_testdin_SHIFT (0U)
/*! phy_testdin - PHY Test Data Input */
#define MIPI_DSI_PHY_TST_CTRL1_phy_testdin(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TST_CTRL1_phy_testdin_SHIFT)) & MIPI_DSI_PHY_TST_CTRL1_phy_testdin_MASK)

#define MIPI_DSI_PHY_TST_CTRL1_pht_testdout_MASK (0xFF00U)
#define MIPI_DSI_PHY_TST_CTRL1_pht_testdout_SHIFT (8U)
/*! pht_testdout - PHY Test Data Output */
#define MIPI_DSI_PHY_TST_CTRL1_pht_testdout(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TST_CTRL1_pht_testdout_SHIFT)) & MIPI_DSI_PHY_TST_CTRL1_pht_testdout_MASK)

#define MIPI_DSI_PHY_TST_CTRL1_phy_testen_MASK   (0x10000U)
#define MIPI_DSI_PHY_TST_CTRL1_phy_testen_SHIFT  (16U)
/*! phy_testen - PHY Test Enable
 *  0b0..Data write operation is set on the rising edge of the testclk signal.
 *  0b1..Address write operation is set on the falling edge of the testclk signal.
 */
#define MIPI_DSI_PHY_TST_CTRL1_phy_testen(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TST_CTRL1_phy_testen_SHIFT)) & MIPI_DSI_PHY_TST_CTRL1_phy_testen_MASK)
/*! @} */

/*! @name INT_ST0 - Interrupt Status 0 */
/*! @{ */

#define MIPI_DSI_INT_ST0_ack_with_err_0_MASK     (0x1U)
#define MIPI_DSI_INT_ST0_ack_with_err_0_SHIFT    (0U)
/*! ack_with_err_0 - Acknowledge with Error 0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_0(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_0_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_0_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_1_MASK     (0x2U)
#define MIPI_DSI_INT_ST0_ack_with_err_1_SHIFT    (1U)
/*! ack_with_err_1 - Acknowledge with Error 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_1(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_1_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_1_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_2_MASK     (0x4U)
#define MIPI_DSI_INT_ST0_ack_with_err_2_SHIFT    (2U)
/*! ack_with_err_2 - Acknowledge with Error 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_2(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_2_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_2_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_3_MASK     (0x8U)
#define MIPI_DSI_INT_ST0_ack_with_err_3_SHIFT    (3U)
/*! ack_with_err_3 - Acknowledge with Error 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_3(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_3_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_3_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_4_MASK     (0x10U)
#define MIPI_DSI_INT_ST0_ack_with_err_4_SHIFT    (4U)
/*! ack_with_err_4 - Acknowledge with Error 4
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_4(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_4_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_4_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_5_MASK     (0x20U)
#define MIPI_DSI_INT_ST0_ack_with_err_5_SHIFT    (5U)
/*! ack_with_err_5 - Acknowledge with Error 5
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_5(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_5_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_5_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_6_MASK     (0x40U)
#define MIPI_DSI_INT_ST0_ack_with_err_6_SHIFT    (6U)
/*! ack_with_err_6 - Acknowledge with Error 6
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_6(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_6_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_6_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_7_MASK     (0x80U)
#define MIPI_DSI_INT_ST0_ack_with_err_7_SHIFT    (7U)
/*! ack_with_err_7 - Acknowledge with Error 7
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_7(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_7_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_7_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_8_MASK     (0x100U)
#define MIPI_DSI_INT_ST0_ack_with_err_8_SHIFT    (8U)
/*! ack_with_err_8 - Acknowledge with Error 8
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_8(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_8_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_8_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_9_MASK     (0x200U)
#define MIPI_DSI_INT_ST0_ack_with_err_9_SHIFT    (9U)
/*! ack_with_err_9 - Acknowledge with Error 9
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_9(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_9_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_9_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_10_MASK    (0x400U)
#define MIPI_DSI_INT_ST0_ack_with_err_10_SHIFT   (10U)
/*! ack_with_err_10 - Acknowledge with Error 10
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_10(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_10_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_10_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_11_MASK    (0x800U)
#define MIPI_DSI_INT_ST0_ack_with_err_11_SHIFT   (11U)
/*! ack_with_err_11 - Acknowledge with Error 11
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_11(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_11_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_11_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_12_MASK    (0x1000U)
#define MIPI_DSI_INT_ST0_ack_with_err_12_SHIFT   (12U)
/*! ack_with_err_12 - Acknowledge with Error 12
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_12(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_12_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_12_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_13_MASK    (0x2000U)
#define MIPI_DSI_INT_ST0_ack_with_err_13_SHIFT   (13U)
/*! ack_with_err_13 - Acknowledge with Error 13
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_13(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_13_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_13_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_14_MASK    (0x4000U)
#define MIPI_DSI_INT_ST0_ack_with_err_14_SHIFT   (14U)
/*! ack_with_err_14 - Acknowledge with Error 14
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_14(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_14_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_14_MASK)

#define MIPI_DSI_INT_ST0_ack_with_err_15_MASK    (0x8000U)
#define MIPI_DSI_INT_ST0_ack_with_err_15_SHIFT   (15U)
/*! ack_with_err_15 - Acknowledge with Error 15
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_ack_with_err_15(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_ack_with_err_15_SHIFT)) & MIPI_DSI_INT_ST0_ack_with_err_15_MASK)

#define MIPI_DSI_INT_ST0_dphy_errors_0_MASK      (0x10000U)
#define MIPI_DSI_INT_ST0_dphy_errors_0_SHIFT     (16U)
/*! dphy_errors_0 - D-PHY Error 0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_dphy_errors_0(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_dphy_errors_0_SHIFT)) & MIPI_DSI_INT_ST0_dphy_errors_0_MASK)

#define MIPI_DSI_INT_ST0_dphy_errors_1_MASK      (0x20000U)
#define MIPI_DSI_INT_ST0_dphy_errors_1_SHIFT     (17U)
/*! dphy_errors_1 - D-PHY Errors 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_dphy_errors_1(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_dphy_errors_1_SHIFT)) & MIPI_DSI_INT_ST0_dphy_errors_1_MASK)

#define MIPI_DSI_INT_ST0_dphy_errors_2_MASK      (0x40000U)
#define MIPI_DSI_INT_ST0_dphy_errors_2_SHIFT     (18U)
/*! dphy_errors_2 - D-PHY Errors 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_dphy_errors_2(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_dphy_errors_2_SHIFT)) & MIPI_DSI_INT_ST0_dphy_errors_2_MASK)

#define MIPI_DSI_INT_ST0_dphy_errors_3_MASK      (0x80000U)
#define MIPI_DSI_INT_ST0_dphy_errors_3_SHIFT     (19U)
/*! dphy_errors_3 - D-PHY Errors 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_dphy_errors_3(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_dphy_errors_3_SHIFT)) & MIPI_DSI_INT_ST0_dphy_errors_3_MASK)

#define MIPI_DSI_INT_ST0_dphy_errors_4_MASK      (0x100000U)
#define MIPI_DSI_INT_ST0_dphy_errors_4_SHIFT     (20U)
/*! dphy_errors_4 - D-PHY Errors 4
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST0_dphy_errors_4(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST0_dphy_errors_4_SHIFT)) & MIPI_DSI_INT_ST0_dphy_errors_4_MASK)
/*! @} */

/*! @name INT_ST1 - Interrupt Status 1 */
/*! @{ */

#define MIPI_DSI_INT_ST1_to_hs_tx_MASK           (0x1U)
#define MIPI_DSI_INT_ST1_to_hs_tx_SHIFT          (0U)
/*! to_hs_tx - Timeout High-speed Transmit
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_to_hs_tx(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_to_hs_tx_SHIFT)) & MIPI_DSI_INT_ST1_to_hs_tx_MASK)

#define MIPI_DSI_INT_ST1_to_lp_rx_MASK           (0x2U)
#define MIPI_DSI_INT_ST1_to_lp_rx_SHIFT          (1U)
/*! to_lp_rx - Timeout Low-power Receive
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_to_lp_rx(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_to_lp_rx_SHIFT)) & MIPI_DSI_INT_ST1_to_lp_rx_MASK)

#define MIPI_DSI_INT_ST1_ecc_single_err_MASK     (0x4U)
#define MIPI_DSI_INT_ST1_ecc_single_err_SHIFT    (2U)
/*! ecc_single_err - ECC Single Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_ecc_single_err(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_ecc_single_err_SHIFT)) & MIPI_DSI_INT_ST1_ecc_single_err_MASK)

#define MIPI_DSI_INT_ST1_ecc_milti_err_MASK      (0x8U)
#define MIPI_DSI_INT_ST1_ecc_milti_err_SHIFT     (3U)
/*! ecc_milti_err - ECC Multiple Error */
#define MIPI_DSI_INT_ST1_ecc_milti_err(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_ecc_milti_err_SHIFT)) & MIPI_DSI_INT_ST1_ecc_milti_err_MASK)

#define MIPI_DSI_INT_ST1_crc_err_MASK            (0x10U)
#define MIPI_DSI_INT_ST1_crc_err_SHIFT           (4U)
/*! crc_err - CRC Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_crc_err(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_crc_err_SHIFT)) & MIPI_DSI_INT_ST1_crc_err_MASK)

#define MIPI_DSI_INT_ST1_pkt_size_err_MASK       (0x20U)
#define MIPI_DSI_INT_ST1_pkt_size_err_SHIFT      (5U)
/*! pkt_size_err - Packet Size Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_pkt_size_err(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_pkt_size_err_SHIFT)) & MIPI_DSI_INT_ST1_pkt_size_err_MASK)

#define MIPI_DSI_INT_ST1_eopt_err_MASK           (0x40U)
#define MIPI_DSI_INT_ST1_eopt_err_SHIFT          (6U)
/*! eopt_err - EoTp Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_eopt_err(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_eopt_err_SHIFT)) & MIPI_DSI_INT_ST1_eopt_err_MASK)

#define MIPI_DSI_INT_ST1_dpi_pld_wr_err_MASK     (0x80U)
#define MIPI_DSI_INT_ST1_dpi_pld_wr_err_SHIFT    (7U)
/*! dpi_pld_wr_err - DPI Payload Write Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_dpi_pld_wr_err(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_dpi_pld_wr_err_SHIFT)) & MIPI_DSI_INT_ST1_dpi_pld_wr_err_MASK)

#define MIPI_DSI_INT_ST1_gen_cmd_wr_err_MASK     (0x100U)
#define MIPI_DSI_INT_ST1_gen_cmd_wr_err_SHIFT    (8U)
/*! gen_cmd_wr_err - Generic Command Write Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_gen_cmd_wr_err(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_gen_cmd_wr_err_SHIFT)) & MIPI_DSI_INT_ST1_gen_cmd_wr_err_MASK)

#define MIPI_DSI_INT_ST1_gen_pld_wr_err_MASK     (0x200U)
#define MIPI_DSI_INT_ST1_gen_pld_wr_err_SHIFT    (9U)
/*! gen_pld_wr_err - Generic Payload Write Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_gen_pld_wr_err(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_gen_pld_wr_err_SHIFT)) & MIPI_DSI_INT_ST1_gen_pld_wr_err_MASK)

#define MIPI_DSI_INT_ST1_gen_pld_send_err_MASK   (0x400U)
#define MIPI_DSI_INT_ST1_gen_pld_send_err_SHIFT  (10U)
/*! gen_pld_send_err - DPI Payload Send Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_gen_pld_send_err(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_gen_pld_send_err_SHIFT)) & MIPI_DSI_INT_ST1_gen_pld_send_err_MASK)

#define MIPI_DSI_INT_ST1_gen_pld_rd_err_MASK     (0x800U)
#define MIPI_DSI_INT_ST1_gen_pld_rd_err_SHIFT    (11U)
/*! gen_pld_rd_err - Generic Payload Read Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_gen_pld_rd_err(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_gen_pld_rd_err_SHIFT)) & MIPI_DSI_INT_ST1_gen_pld_rd_err_MASK)

#define MIPI_DSI_INT_ST1_gen_pld_recev_err_MASK  (0x1000U)
#define MIPI_DSI_INT_ST1_gen_pld_recev_err_SHIFT (12U)
/*! gen_pld_recev_err - Generic Payload Receive Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_gen_pld_recev_err(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_gen_pld_recev_err_SHIFT)) & MIPI_DSI_INT_ST1_gen_pld_recev_err_MASK)

#define MIPI_DSI_INT_ST1_dpi_buff_pld_under_MASK (0x80000U)
#define MIPI_DSI_INT_ST1_dpi_buff_pld_under_SHIFT (19U)
/*! dpi_buff_pld_under - DPI Buffer Payload Underflow
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_INT_ST1_dpi_buff_pld_under(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_ST1_dpi_buff_pld_under_SHIFT)) & MIPI_DSI_INT_ST1_dpi_buff_pld_under_MASK)
/*! @} */

/*! @name INT_MSK0 - Interrupt Mask 0 */
/*! @{ */

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_0_MASK (0x1U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_0_SHIFT (0U)
/*! mask_ack_with_err_0 - Mask for ack_with_err_0 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_0_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_0_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_1_MASK (0x2U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_1_SHIFT (1U)
/*! mask_ack_with_err_1 - Mask for ack_with_err_1 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_1_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_1_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_2_MASK (0x4U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_2_SHIFT (2U)
/*! mask_ack_with_err_2 - Mask for ack_with_err_2 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_2_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_2_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_3_MASK (0x8U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_3_SHIFT (3U)
/*! mask_ack_with_err_3 - Mask for ack_with_err_3 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_3(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_3_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_3_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_4_MASK (0x10U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_4_SHIFT (4U)
/*! mask_ack_with_err_4 - Mask for ack_with_err_4 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_4(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_4_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_4_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_5_MASK (0x20U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_5_SHIFT (5U)
/*! mask_ack_with_err_5 - Mask for ack_with_err_5 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_5(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_5_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_5_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_6_MASK (0x40U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_6_SHIFT (6U)
/*! mask_ack_with_err_6 - Mask for ack_with_err_6 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_6(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_6_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_6_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_7_MASK (0x80U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_7_SHIFT (7U)
/*! mask_ack_with_err_7 - Mask for ack_with_err_7 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_7(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_7_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_7_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_8_MASK (0x100U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_8_SHIFT (8U)
/*! mask_ack_with_err_8 - Mask for ack_with_err_8 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_8(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_8_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_8_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_9_MASK (0x200U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_9_SHIFT (9U)
/*! mask_ack_with_err_9 - Mask for ack_with_err_9 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_9(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_9_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_9_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_10_MASK (0x400U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_10_SHIFT (10U)
/*! mask_ack_with_err_10 - Mask for ack_with_err_10 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_10(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_10_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_10_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_11_MASK (0x800U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_11_SHIFT (11U)
/*! mask_ack_with_err_11 - Mask for ack_with_err_11 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_11(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_11_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_11_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_12_MASK (0x1000U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_12_SHIFT (12U)
/*! mask_ack_with_err_12 - Mask for ack_with_err_12 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_12(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_12_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_12_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_13_MASK (0x2000U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_13_SHIFT (13U)
/*! mask_ack_with_err_13 - Mask for ack_with_err_13 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_13(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_13_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_13_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_14_MASK (0x4000U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_14_SHIFT (14U)
/*! mask_ack_with_err_14 - Mask for ack_with_err_14 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_14(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_14_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_14_MASK)

#define MIPI_DSI_INT_MSK0_mask_ack_with_err_15_MASK (0x8000U)
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_15_SHIFT (15U)
/*! mask_ack_with_err_15 - Mask for ack_with_err_15 */
#define MIPI_DSI_INT_MSK0_mask_ack_with_err_15(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_ack_with_err_15_SHIFT)) & MIPI_DSI_INT_MSK0_mask_ack_with_err_15_MASK)

#define MIPI_DSI_INT_MSK0_mask_dphy_errors_0_MASK (0x10000U)
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_0_SHIFT (16U)
/*! mask_dphy_errors_0 - Mask for dphy_errors_0 */
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_0(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_dphy_errors_0_SHIFT)) & MIPI_DSI_INT_MSK0_mask_dphy_errors_0_MASK)

#define MIPI_DSI_INT_MSK0_mask_dphy_errors_1_MASK (0x20000U)
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_1_SHIFT (17U)
/*! mask_dphy_errors_1 - Mask for dphy_errors_1 */
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_1(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_dphy_errors_1_SHIFT)) & MIPI_DSI_INT_MSK0_mask_dphy_errors_1_MASK)

#define MIPI_DSI_INT_MSK0_mask_dphy_errors_2_MASK (0x40000U)
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_2_SHIFT (18U)
/*! mask_dphy_errors_2 - Mask for dphy_errors_2 */
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_2(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_dphy_errors_2_SHIFT)) & MIPI_DSI_INT_MSK0_mask_dphy_errors_2_MASK)

#define MIPI_DSI_INT_MSK0_mask_dphy_errors_3_MASK (0x80000U)
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_3_SHIFT (19U)
/*! mask_dphy_errors_3 - Mask for dphy_errors_3 */
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_3(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_dphy_errors_3_SHIFT)) & MIPI_DSI_INT_MSK0_mask_dphy_errors_3_MASK)

#define MIPI_DSI_INT_MSK0_mask_dphy_errors_4_MASK (0x100000U)
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_4_SHIFT (20U)
/*! mask_dphy_errors_4 - Mask for dphy_errors_4 */
#define MIPI_DSI_INT_MSK0_mask_dphy_errors_4(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK0_mask_dphy_errors_4_SHIFT)) & MIPI_DSI_INT_MSK0_mask_dphy_errors_4_MASK)
/*! @} */

/*! @name INT_MSK1 - Interrupt Mask 1 */
/*! @{ */

#define MIPI_DSI_INT_MSK1_mask_to_hs_tx_MASK     (0x1U)
#define MIPI_DSI_INT_MSK1_mask_to_hs_tx_SHIFT    (0U)
/*! mask_to_hs_tx - Mask for to_hs_tx */
#define MIPI_DSI_INT_MSK1_mask_to_hs_tx(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_to_hs_tx_SHIFT)) & MIPI_DSI_INT_MSK1_mask_to_hs_tx_MASK)

#define MIPI_DSI_INT_MSK1_mask_to_lp_rx_MASK     (0x2U)
#define MIPI_DSI_INT_MSK1_mask_to_lp_rx_SHIFT    (1U)
/*! mask_to_lp_rx - Mask for to_lp_rx */
#define MIPI_DSI_INT_MSK1_mask_to_lp_rx(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_to_lp_rx_SHIFT)) & MIPI_DSI_INT_MSK1_mask_to_lp_rx_MASK)

#define MIPI_DSI_INT_MSK1_mask_ecc_single_err_MASK (0x4U)
#define MIPI_DSI_INT_MSK1_mask_ecc_single_err_SHIFT (2U)
/*! mask_ecc_single_err - Mask for ecc_single_err */
#define MIPI_DSI_INT_MSK1_mask_ecc_single_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_ecc_single_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_ecc_single_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_ecc_milti_err_MASK (0x8U)
#define MIPI_DSI_INT_MSK1_mask_ecc_milti_err_SHIFT (3U)
/*! mask_ecc_milti_err - Mask for ecc_milti_err */
#define MIPI_DSI_INT_MSK1_mask_ecc_milti_err(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_ecc_milti_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_ecc_milti_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_crc_err_MASK      (0x10U)
#define MIPI_DSI_INT_MSK1_mask_crc_err_SHIFT     (4U)
/*! mask_crc_err - Mask for crc_err */
#define MIPI_DSI_INT_MSK1_mask_crc_err(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_crc_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_crc_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_pkt_size_err_MASK (0x20U)
#define MIPI_DSI_INT_MSK1_mask_pkt_size_err_SHIFT (5U)
/*! mask_pkt_size_err - Mask for pkt_size_err */
#define MIPI_DSI_INT_MSK1_mask_pkt_size_err(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_pkt_size_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_pkt_size_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_eopt_err_MASK     (0x40U)
#define MIPI_DSI_INT_MSK1_mask_eopt_err_SHIFT    (6U)
/*! mask_eopt_err - Mask for eopt_err */
#define MIPI_DSI_INT_MSK1_mask_eopt_err(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_eopt_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_eopt_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_dpi_pld_wr_err_MASK (0x80U)
#define MIPI_DSI_INT_MSK1_mask_dpi_pld_wr_err_SHIFT (7U)
/*! mask_dpi_pld_wr_err - Mask for dpi_pld_wr_err */
#define MIPI_DSI_INT_MSK1_mask_dpi_pld_wr_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_dpi_pld_wr_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_dpi_pld_wr_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_gen_cmd_wr_err_MASK (0x100U)
#define MIPI_DSI_INT_MSK1_mask_gen_cmd_wr_err_SHIFT (8U)
/*! mask_gen_cmd_wr_err - Mask for gen_cmd_wr_err */
#define MIPI_DSI_INT_MSK1_mask_gen_cmd_wr_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_gen_cmd_wr_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_gen_cmd_wr_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_gen_pld_wr_err_MASK (0x200U)
#define MIPI_DSI_INT_MSK1_mask_gen_pld_wr_err_SHIFT (9U)
/*! mask_gen_pld_wr_err - Mask for gen_pld_wr_err */
#define MIPI_DSI_INT_MSK1_mask_gen_pld_wr_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_gen_pld_wr_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_gen_pld_wr_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_gen_pld_send_err_MASK (0x400U)
#define MIPI_DSI_INT_MSK1_mask_gen_pld_send_err_SHIFT (10U)
/*! mask_gen_pld_send_err - Mask for gen_pld_send_err */
#define MIPI_DSI_INT_MSK1_mask_gen_pld_send_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_gen_pld_send_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_gen_pld_send_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_gen_pld_rd_err_MASK (0x800U)
#define MIPI_DSI_INT_MSK1_mask_gen_pld_rd_err_SHIFT (11U)
/*! mask_gen_pld_rd_err - Mask for gen_pld_rd_err */
#define MIPI_DSI_INT_MSK1_mask_gen_pld_rd_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_gen_pld_rd_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_gen_pld_rd_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_gen_pld_recev_err_MASK (0x1000U)
#define MIPI_DSI_INT_MSK1_mask_gen_pld_recev_err_SHIFT (12U)
/*! mask_gen_pld_recev_err - Mask for gen_pld_recev_err */
#define MIPI_DSI_INT_MSK1_mask_gen_pld_recev_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_gen_pld_recev_err_SHIFT)) & MIPI_DSI_INT_MSK1_mask_gen_pld_recev_err_MASK)

#define MIPI_DSI_INT_MSK1_mask_dpi_buff_pld_under_MASK (0x80000U)
#define MIPI_DSI_INT_MSK1_mask_dpi_buff_pld_under_SHIFT (19U)
/*! mask_dpi_buff_pld_under - Mask for dpi_buff_pld_under */
#define MIPI_DSI_INT_MSK1_mask_dpi_buff_pld_under(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_MSK1_mask_dpi_buff_pld_under_SHIFT)) & MIPI_DSI_INT_MSK1_mask_dpi_buff_pld_under_MASK)
/*! @} */

/*! @name PHY_CAL - D-PHY Skew Calibration */
/*! @{ */

#define MIPI_DSI_PHY_CAL_txskewcalhs_MASK        (0x1U)
#define MIPI_DSI_PHY_CAL_txskewcalhs_SHIFT       (0U)
/*! txskewcalhs - High-speed skew calibration is started when txskewcalhs is set high (assuming that PHY is in Stop state). */
#define MIPI_DSI_PHY_CAL_txskewcalhs(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_CAL_txskewcalhs_SHIFT)) & MIPI_DSI_PHY_CAL_txskewcalhs_MASK)
/*! @} */

/*! @name INT_FORCE0 - Interrupt Force 0 */
/*! @{ */

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_0_MASK (0x1U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_0_SHIFT (0U)
/*! force_ack_with_err_0 - Force ack_with_err_0 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_0_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_0_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_1_MASK (0x2U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_1_SHIFT (1U)
/*! force_ack_with_err_1 - Force ack_with_err_1 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_1_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_1_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_2_MASK (0x4U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_2_SHIFT (2U)
/*! force_ack_with_err_2 - Force ack_with_err_2 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_2_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_2_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_3_MASK (0x8U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_3_SHIFT (3U)
/*! force_ack_with_err_3 - Force ack_with_err_3 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_3(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_3_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_3_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_4_MASK (0x10U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_4_SHIFT (4U)
/*! force_ack_with_err_4 - Force ack_with_err_4 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_4(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_4_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_4_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_5_MASK (0x20U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_5_SHIFT (5U)
/*! force_ack_with_err_5 - Force ack_with_err_5 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_5(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_5_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_5_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_6_MASK (0x40U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_6_SHIFT (6U)
/*! force_ack_with_err_6 - Force ack_with_err_6 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_6(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_6_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_6_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_7_MASK (0x80U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_7_SHIFT (7U)
/*! force_ack_with_err_7 - Force ack_with_err_7 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_7(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_7_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_7_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_8_MASK (0x100U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_8_SHIFT (8U)
/*! force_ack_with_err_8 - Force ack_with_err_8 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_8(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_8_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_8_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_9_MASK (0x200U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_9_SHIFT (9U)
/*! force_ack_with_err_9 - Force ack_with_err_9 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_9(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_9_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_9_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_10_MASK (0x400U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_10_SHIFT (10U)
/*! force_ack_with_err_10 - Force ack_with_err_10 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_10(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_10_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_10_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_11_MASK (0x800U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_11_SHIFT (11U)
/*! force_ack_with_err_11 - Force ack_with_err_11 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_11(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_11_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_11_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_12_MASK (0x1000U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_12_SHIFT (12U)
/*! force_ack_with_err_12 - Force ack_with_err_12 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_12(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_12_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_12_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_13_MASK (0x2000U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_13_SHIFT (13U)
/*! force_ack_with_err_13 - Force ack_with_err_13 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_13(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_13_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_13_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_14_MASK (0x4000U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_14_SHIFT (14U)
/*! force_ack_with_err_14 - Force ack_with_err_14 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_14(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_14_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_14_MASK)

#define MIPI_DSI_INT_FORCE0_force_ack_with_err_15_MASK (0x8000U)
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_15_SHIFT (15U)
/*! force_ack_with_err_15 - Force ack_with_err_15 */
#define MIPI_DSI_INT_FORCE0_force_ack_with_err_15(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_ack_with_err_15_SHIFT)) & MIPI_DSI_INT_FORCE0_force_ack_with_err_15_MASK)

#define MIPI_DSI_INT_FORCE0_force_dphy_errors_0_MASK (0x10000U)
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_0_SHIFT (16U)
/*! force_dphy_errors_0 - Force dphy_errors_0 */
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_dphy_errors_0_SHIFT)) & MIPI_DSI_INT_FORCE0_force_dphy_errors_0_MASK)

#define MIPI_DSI_INT_FORCE0_force_dphy_errors_1_MASK (0x20000U)
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_1_SHIFT (17U)
/*! force_dphy_errors_1 - Force dphy_errors_1 */
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_dphy_errors_1_SHIFT)) & MIPI_DSI_INT_FORCE0_force_dphy_errors_1_MASK)

#define MIPI_DSI_INT_FORCE0_force_dphy_errors_2_MASK (0x40000U)
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_2_SHIFT (18U)
/*! force_dphy_errors_2 - Force dphy_errors_2 */
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_dphy_errors_2_SHIFT)) & MIPI_DSI_INT_FORCE0_force_dphy_errors_2_MASK)

#define MIPI_DSI_INT_FORCE0_force_dphy_errors_3_MASK (0x80000U)
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_3_SHIFT (19U)
/*! force_dphy_errors_3 - Force dphy_errors_3 */
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_3(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_dphy_errors_3_SHIFT)) & MIPI_DSI_INT_FORCE0_force_dphy_errors_3_MASK)

#define MIPI_DSI_INT_FORCE0_force_dphy_errors_4_MASK (0x100000U)
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_4_SHIFT (20U)
/*! force_dphy_errors_4 - Force dphy_errors_4 */
#define MIPI_DSI_INT_FORCE0_force_dphy_errors_4(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE0_force_dphy_errors_4_SHIFT)) & MIPI_DSI_INT_FORCE0_force_dphy_errors_4_MASK)
/*! @} */

/*! @name INT_FORCE1 - Interrupt Force Register 1 */
/*! @{ */

#define MIPI_DSI_INT_FORCE1_force_to_hs_tx_MASK  (0x1U)
#define MIPI_DSI_INT_FORCE1_force_to_hs_tx_SHIFT (0U)
/*! force_to_hs_tx - Force to_hs_tx */
#define MIPI_DSI_INT_FORCE1_force_to_hs_tx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_to_hs_tx_SHIFT)) & MIPI_DSI_INT_FORCE1_force_to_hs_tx_MASK)

#define MIPI_DSI_INT_FORCE1_force_to_lp_rx_MASK  (0x2U)
#define MIPI_DSI_INT_FORCE1_force_to_lp_rx_SHIFT (1U)
/*! force_to_lp_rx - Force to_lp_rx */
#define MIPI_DSI_INT_FORCE1_force_to_lp_rx(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_to_lp_rx_SHIFT)) & MIPI_DSI_INT_FORCE1_force_to_lp_rx_MASK)

#define MIPI_DSI_INT_FORCE1_force_ecc_single_err_MASK (0x4U)
#define MIPI_DSI_INT_FORCE1_force_ecc_single_err_SHIFT (2U)
/*! force_ecc_single_err - Force ecc_single_err */
#define MIPI_DSI_INT_FORCE1_force_ecc_single_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_ecc_single_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_ecc_single_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_ecc_milti_err_MASK (0x8U)
#define MIPI_DSI_INT_FORCE1_force_ecc_milti_err_SHIFT (3U)
/*! force_ecc_milti_err - Force ecc_milti_err */
#define MIPI_DSI_INT_FORCE1_force_ecc_milti_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_ecc_milti_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_ecc_milti_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_crc_err_MASK   (0x10U)
#define MIPI_DSI_INT_FORCE1_force_crc_err_SHIFT  (4U)
/*! force_crc_err - Force crc_err */
#define MIPI_DSI_INT_FORCE1_force_crc_err(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_crc_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_crc_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_pkt_size_err_MASK (0x20U)
#define MIPI_DSI_INT_FORCE1_force_pkt_size_err_SHIFT (5U)
/*! force_pkt_size_err - Force pkt_size_err */
#define MIPI_DSI_INT_FORCE1_force_pkt_size_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_pkt_size_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_pkt_size_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_eopt_err_MASK  (0x40U)
#define MIPI_DSI_INT_FORCE1_force_eopt_err_SHIFT (6U)
/*! force_eopt_err - Force eopt_err */
#define MIPI_DSI_INT_FORCE1_force_eopt_err(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_eopt_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_eopt_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_dpi_pld_wr_err_MASK (0x80U)
#define MIPI_DSI_INT_FORCE1_force_dpi_pld_wr_err_SHIFT (7U)
/*! force_dpi_pld_wr_err - Force dpi_pld_wr_err */
#define MIPI_DSI_INT_FORCE1_force_dpi_pld_wr_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_dpi_pld_wr_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_dpi_pld_wr_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_gen_cmd_wr_err_MASK (0x100U)
#define MIPI_DSI_INT_FORCE1_force_gen_cmd_wr_err_SHIFT (8U)
/*! force_gen_cmd_wr_err - Force gen_cmd_wr_err */
#define MIPI_DSI_INT_FORCE1_force_gen_cmd_wr_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_gen_cmd_wr_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_gen_cmd_wr_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_gen_pld_wr_err_MASK (0x200U)
#define MIPI_DSI_INT_FORCE1_force_gen_pld_wr_err_SHIFT (9U)
/*! force_gen_pld_wr_err - Force gen_pld_wr_err */
#define MIPI_DSI_INT_FORCE1_force_gen_pld_wr_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_gen_pld_wr_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_gen_pld_wr_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_gen_pld_send_err_MASK (0x400U)
#define MIPI_DSI_INT_FORCE1_force_gen_pld_send_err_SHIFT (10U)
/*! force_gen_pld_send_err - Force gen_pld_send_err */
#define MIPI_DSI_INT_FORCE1_force_gen_pld_send_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_gen_pld_send_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_gen_pld_send_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_gen_pld_rd_err_MASK (0x800U)
#define MIPI_DSI_INT_FORCE1_force_gen_pld_rd_err_SHIFT (11U)
/*! force_gen_pld_rd_err - Force gen_pld_rd_err */
#define MIPI_DSI_INT_FORCE1_force_gen_pld_rd_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_gen_pld_rd_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_gen_pld_rd_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_gen_pld_recev_err_MASK (0x1000U)
#define MIPI_DSI_INT_FORCE1_force_gen_pld_recev_err_SHIFT (12U)
/*! force_gen_pld_recev_err - Force gen_pld_recev_err */
#define MIPI_DSI_INT_FORCE1_force_gen_pld_recev_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_gen_pld_recev_err_SHIFT)) & MIPI_DSI_INT_FORCE1_force_gen_pld_recev_err_MASK)

#define MIPI_DSI_INT_FORCE1_force_dpi_buff_pld_under_MASK (0x80000U)
#define MIPI_DSI_INT_FORCE1_force_dpi_buff_pld_under_SHIFT (19U)
/*! force_dpi_buff_pld_under - Force for dpi_buff_pld_under. */
#define MIPI_DSI_INT_FORCE1_force_dpi_buff_pld_under(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_INT_FORCE1_force_dpi_buff_pld_under_SHIFT)) & MIPI_DSI_INT_FORCE1_force_dpi_buff_pld_under_MASK)
/*! @} */

/*! @name DSC_PARAMETER - Display Stream Compression Configuration */
/*! @{ */

#define MIPI_DSI_DSC_PARAMETER_compression_mode_MASK (0x1U)
#define MIPI_DSI_DSC_PARAMETER_compression_mode_SHIFT (0U)
/*! compression_mode - Compression Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_DSC_PARAMETER_compression_mode(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSC_PARAMETER_compression_mode_SHIFT)) & MIPI_DSI_DSC_PARAMETER_compression_mode_MASK)

#define MIPI_DSI_DSC_PARAMETER_compress_algo_MASK (0x300U)
#define MIPI_DSI_DSC_PARAMETER_compress_algo_SHIFT (8U)
/*! compress_algo - Compression Algorithm
 *  0b00..VESA DSC Standard 1.1
 *  0b01, 0b10..
 *  0b11..Vendor-specific algorithm
 */
#define MIPI_DSI_DSC_PARAMETER_compress_algo(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSC_PARAMETER_compress_algo_SHIFT)) & MIPI_DSI_DSC_PARAMETER_compress_algo_MASK)

#define MIPI_DSI_DSC_PARAMETER_pps_sel_MASK      (0x30000U)
#define MIPI_DSI_DSC_PARAMETER_pps_sel_SHIFT     (16U)
/*! pps_sel - PPS Select
 *  0b00..PPS Table 1
 *  0b01..PPS Table 2
 *  0b10..PPS Table 3
 *  0b11..PPS Table 4
 */
#define MIPI_DSI_DSC_PARAMETER_pps_sel(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DSC_PARAMETER_pps_sel_SHIFT)) & MIPI_DSI_DSC_PARAMETER_pps_sel_MASK)
/*! @} */

/*! @name PHY_TMR_RD_CFG - PHY Read Command Time Configuration */
/*! @{ */

#define MIPI_DSI_PHY_TMR_RD_CFG_max_rd_time_MASK (0x7FFFU)
#define MIPI_DSI_PHY_TMR_RD_CFG_max_rd_time_SHIFT (0U)
/*! max_rd_time - Maximum Read Time */
#define MIPI_DSI_PHY_TMR_RD_CFG_max_rd_time(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_PHY_TMR_RD_CFG_max_rd_time_SHIFT)) & MIPI_DSI_PHY_TMR_RD_CFG_max_rd_time_MASK)
/*! @} */

/*! @name VID_SHADOW_CTRL - Video Shadow Control */
/*! @{ */

#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_en_MASK (0x1U)
#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_en_SHIFT (0U)
/*! vid_shadow_en - Video Shadow Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_en(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_en_SHIFT)) & MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_en_MASK)

#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_req_MASK (0x100U)
#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_req_SHIFT (8U)
/*! vid_shadow_req - Video Shadow Request
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_req(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_req_SHIFT)) & MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_req_MASK)

#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_pin_req_MASK (0x10000U)
#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_pin_req_SHIFT (16U)
/*! vid_shadow_pin_req - Video Shadow Pin Request
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_pin_req(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_pin_req_SHIFT)) & MIPI_DSI_VID_SHADOW_CTRL_vid_shadow_pin_req_MASK)
/*! @} */

/*! @name DPI_VCID_ACT - DPI Virtual Channel ID Value */
/*! @{ */

#define MIPI_DSI_DPI_VCID_ACT_dpi_vcid_MASK      (0x3U)
#define MIPI_DSI_DPI_VCID_ACT_dpi_vcid_SHIFT     (0U)
/*! dpi_vcid - DPI Virtual Channel ID */
#define MIPI_DSI_DPI_VCID_ACT_dpi_vcid(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_VCID_ACT_dpi_vcid_SHIFT)) & MIPI_DSI_DPI_VCID_ACT_dpi_vcid_MASK)
/*! @} */

/*! @name DPI_COLOR_CODING_ACT - DPI Color Coding Value */
/*! @{ */

#define MIPI_DSI_DPI_COLOR_CODING_ACT_dpi_color_coding_MASK (0xFU)
#define MIPI_DSI_DPI_COLOR_CODING_ACT_dpi_color_coding_SHIFT (0U)
/*! dpi_color_coding - DPI Color Coding
 *  0b0000..16-bit configuration 1
 *  0b0001..16-bit configuration 2
 *  0b0010..16-bit configuration 3
 *  0b0011..18-bit configuration 1
 *  0b0100..18-bit configuration 2
 *  0b0101..24-bit
 *  0b0110..20-bit YCbCr 4:2:2 loosely packed / Reserved for eDPI Command Mode
 *  0b0111..24-bit YCbCr 4:2:2 / Reserved for eDPI Command Mode
 *  0b1000..16-bit YCbCr 4:2:2 / Reserved for eDPI Command Mode
 *  0b1001..30-bit - DSC_ENC 10bit / Reserved for eDPI Command Mode
 *  0b1010..36-bit / Reserved for eDPI Command Mode
 *  0b1011..12-bit YCbCr 4:2:0 / Reserved for eDPI Command Mode
 *  0b1100..DSC24 compressed Data
 *  0b1101-0b1111..
 */
#define MIPI_DSI_DPI_COLOR_CODING_ACT_dpi_color_coding(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_COLOR_CODING_ACT_dpi_color_coding_SHIFT)) & MIPI_DSI_DPI_COLOR_CODING_ACT_dpi_color_coding_MASK)

#define MIPI_DSI_DPI_COLOR_CODING_ACT_loosely18_en_MASK (0x100U)
#define MIPI_DSI_DPI_COLOR_CODING_ACT_loosely18_en_SHIFT (8U)
/*! loosely18_en - Loosely 18 Bit Enabled
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_DPI_COLOR_CODING_ACT_loosely18_en(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_COLOR_CODING_ACT_loosely18_en_SHIFT)) & MIPI_DSI_DPI_COLOR_CODING_ACT_loosely18_en_MASK)
/*! @} */

/*! @name DPI_LP_CMD_TIM_ACT - DPI Low-power Commands Timing Value */
/*! @{ */

#define MIPI_DSI_DPI_LP_CMD_TIM_ACT_invact_lpcmd_time_MASK (0xFFU)
#define MIPI_DSI_DPI_LP_CMD_TIM_ACT_invact_lpcmd_time_SHIFT (0U)
/*! invact_lpcmd_time - In VACT Low-power Command Size */
#define MIPI_DSI_DPI_LP_CMD_TIM_ACT_invact_lpcmd_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_LP_CMD_TIM_ACT_invact_lpcmd_time_SHIFT)) & MIPI_DSI_DPI_LP_CMD_TIM_ACT_invact_lpcmd_time_MASK)

#define MIPI_DSI_DPI_LP_CMD_TIM_ACT_outvact_lpcmd_time_MASK (0xFF0000U)
#define MIPI_DSI_DPI_LP_CMD_TIM_ACT_outvact_lpcmd_time_SHIFT (16U)
/*! outvact_lpcmd_time - Out VACT Low-power Command Size */
#define MIPI_DSI_DPI_LP_CMD_TIM_ACT_outvact_lpcmd_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_DPI_LP_CMD_TIM_ACT_outvact_lpcmd_time_SHIFT)) & MIPI_DSI_DPI_LP_CMD_TIM_ACT_outvact_lpcmd_time_MASK)
/*! @} */

/*! @name VID_MODE_CFG_ACT - Video Mode Configuration Value */
/*! @{ */

#define MIPI_DSI_VID_MODE_CFG_ACT_vid_mode_type_MASK (0x3U)
#define MIPI_DSI_VID_MODE_CFG_ACT_vid_mode_type_SHIFT (0U)
/*! vid_mode_type - Video Mode Type
 *  0b00..Non-burst with sync pulses
 *  0b01..Non-burst with sync events
 *  0b10..Burst mode
 *  0b11..Burst mode
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_vid_mode_type(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_vid_mode_type_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_vid_mode_type_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vsa_en_MASK (0x4U)
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vsa_en_SHIFT (2U)
/*! lp_vsa_en - Low-power VSA Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vsa_en(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_lp_vsa_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_lp_vsa_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vbp_en_MASK (0x8U)
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vbp_en_SHIFT (3U)
/*! lp_vbp_en - Low-power VBP Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vbp_en(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_lp_vbp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_lp_vbp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vfp_en_MASK (0x10U)
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vfp_en_SHIFT (4U)
/*! lp_vfp_en - Low-power VFP Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vfp_en(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_lp_vfp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_lp_vfp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vact_en_MASK (0x20U)
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vact_en_SHIFT (5U)
/*! lp_vact_en - Low-power VFP Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_vact_en(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_lp_vact_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_lp_vact_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_lp_hbp_en_MASK (0x40U)
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_hbp_en_SHIFT (6U)
/*! lp_hbp_en - Low-power HBP Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_hbp_en(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_lp_hbp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_lp_hbp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_lp_hfp_en_MASK (0x80U)
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_hfp_en_SHIFT (7U)
/*! lp_hfp_en - Low-power HFP Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_hfp_en(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_lp_hfp_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_lp_hfp_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_frame_bta_ack_en_MASK (0x100U)
#define MIPI_DSI_VID_MODE_CFG_ACT_frame_bta_ack_en_SHIFT (8U)
/*! frame_bta_ack_en - Frame BTA Acknowledge Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_frame_bta_ack_en(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_frame_bta_ack_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_frame_bta_ack_en_MASK)

#define MIPI_DSI_VID_MODE_CFG_ACT_lp_cmd_en_MASK (0x200U)
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_cmd_en_SHIFT (9U)
/*! lp_cmd_en - Low-power Command Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MIPI_DSI_VID_MODE_CFG_ACT_lp_cmd_en(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_MODE_CFG_ACT_lp_cmd_en_SHIFT)) & MIPI_DSI_VID_MODE_CFG_ACT_lp_cmd_en_MASK)
/*! @} */

/*! @name VID_PKT_SIZE_ACT - Video Packet Size Value */
/*! @{ */

#define MIPI_DSI_VID_PKT_SIZE_ACT_vid_pkt_size_MASK (0x3FFFU)
#define MIPI_DSI_VID_PKT_SIZE_ACT_vid_pkt_size_SHIFT (0U)
/*! vid_pkt_size - Video Packet Size */
#define MIPI_DSI_VID_PKT_SIZE_ACT_vid_pkt_size(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_SIZE_ACT_vid_pkt_size_SHIFT)) & MIPI_DSI_VID_PKT_SIZE_ACT_vid_pkt_size_MASK)
/*! @} */

/*! @name VID_NUM_CHUNKS_ACT - Video Number Chunks Value */
/*! @{ */

#define MIPI_DSI_VID_NUM_CHUNKS_ACT_vid_num_chunks_MASK (0x1FFFU)
#define MIPI_DSI_VID_NUM_CHUNKS_ACT_vid_num_chunks_SHIFT (0U)
/*! vid_num_chunks - Video Number Chunks */
#define MIPI_DSI_VID_NUM_CHUNKS_ACT_vid_num_chunks(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_NUM_CHUNKS_ACT_vid_num_chunks_SHIFT)) & MIPI_DSI_VID_NUM_CHUNKS_ACT_vid_num_chunks_MASK)
/*! @} */

/*! @name VID_NULL_SIZE_ACT - Video Null Packets Size Value */
/*! @{ */

#define MIPI_DSI_VID_NULL_SIZE_ACT_vid_null_size_MASK (0x1FFFU)
#define MIPI_DSI_VID_NULL_SIZE_ACT_vid_null_size_SHIFT (0U)
/*! vid_null_size - Video Null Size */
#define MIPI_DSI_VID_NULL_SIZE_ACT_vid_null_size(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_NULL_SIZE_ACT_vid_null_size_SHIFT)) & MIPI_DSI_VID_NULL_SIZE_ACT_vid_null_size_MASK)
/*! @} */

/*! @name VID_HSA_TIME_ACT - Video HSA Time Value */
/*! @{ */

#define MIPI_DSI_VID_HSA_TIME_ACT_vid_hsa_time_MASK (0xFFFU)
#define MIPI_DSI_VID_HSA_TIME_ACT_vid_hsa_time_SHIFT (0U)
/*! vid_hsa_time - Video HSA Time */
#define MIPI_DSI_VID_HSA_TIME_ACT_vid_hsa_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_HSA_TIME_ACT_vid_hsa_time_SHIFT)) & MIPI_DSI_VID_HSA_TIME_ACT_vid_hsa_time_MASK)
/*! @} */

/*! @name VID_HBP_TIME_ACT - Video HBP Time Value */
/*! @{ */

#define MIPI_DSI_VID_HBP_TIME_ACT_vid_hbp_time_MASK (0xFFFU)
#define MIPI_DSI_VID_HBP_TIME_ACT_vid_hbp_time_SHIFT (0U)
/*! vid_hbp_time - Video HBP Time */
#define MIPI_DSI_VID_HBP_TIME_ACT_vid_hbp_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_HBP_TIME_ACT_vid_hbp_time_SHIFT)) & MIPI_DSI_VID_HBP_TIME_ACT_vid_hbp_time_MASK)
/*! @} */

/*! @name VID_HLINE_TIME_ACT - Video Line Time Value */
/*! @{ */

#define MIPI_DSI_VID_HLINE_TIME_ACT_vid_hline_time_MASK (0x7FFFU)
#define MIPI_DSI_VID_HLINE_TIME_ACT_vid_hline_time_SHIFT (0U)
/*! vid_hline_time - Video HLINE Time */
#define MIPI_DSI_VID_HLINE_TIME_ACT_vid_hline_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_HLINE_TIME_ACT_vid_hline_time_SHIFT)) & MIPI_DSI_VID_HLINE_TIME_ACT_vid_hline_time_MASK)
/*! @} */

/*! @name VID_VSA_LINES_ACT - VSA Period Value */
/*! @{ */

#define MIPI_DSI_VID_VSA_LINES_ACT_vsa_lines_MASK (0x3FFU)
#define MIPI_DSI_VID_VSA_LINES_ACT_vsa_lines_SHIFT (0U)
/*! vsa_lines - VSA Lines */
#define MIPI_DSI_VID_VSA_LINES_ACT_vsa_lines(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VSA_LINES_ACT_vsa_lines_SHIFT)) & MIPI_DSI_VID_VSA_LINES_ACT_vsa_lines_MASK)
/*! @} */

/*! @name VID_VBP_LINES_ACT - VBP Period Value */
/*! @{ */

#define MIPI_DSI_VID_VBP_LINES_ACT_vbp_lines_MASK (0x3FFU)
#define MIPI_DSI_VID_VBP_LINES_ACT_vbp_lines_SHIFT (0U)
/*! vbp_lines - VBP Lines */
#define MIPI_DSI_VID_VBP_LINES_ACT_vbp_lines(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VBP_LINES_ACT_vbp_lines_SHIFT)) & MIPI_DSI_VID_VBP_LINES_ACT_vbp_lines_MASK)
/*! @} */

/*! @name VID_VFP_LINES_ACT - VFP Period Value */
/*! @{ */

#define MIPI_DSI_VID_VFP_LINES_ACT_vfp_lines_MASK (0x3FFU)
#define MIPI_DSI_VID_VFP_LINES_ACT_vfp_lines_SHIFT (0U)
/*! vfp_lines - VFP Lines */
#define MIPI_DSI_VID_VFP_LINES_ACT_vfp_lines(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VFP_LINES_ACT_vfp_lines_SHIFT)) & MIPI_DSI_VID_VFP_LINES_ACT_vfp_lines_MASK)
/*! @} */

/*! @name VID_VACTIVE_LINES_ACT - Vertical Resolution of Video Value */
/*! @{ */

#define MIPI_DSI_VID_VACTIVE_LINES_ACT_v_active_lines_MASK (0x3FFFU)
#define MIPI_DSI_VID_VACTIVE_LINES_ACT_v_active_lines_SHIFT (0U)
/*! v_active_lines - Vertical Active Lines */
#define MIPI_DSI_VID_VACTIVE_LINES_ACT_v_active_lines(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_VACTIVE_LINES_ACT_v_active_lines_SHIFT)) & MIPI_DSI_VID_VACTIVE_LINES_ACT_v_active_lines_MASK)
/*! @} */

/*! @name VID_PKT_STATUS - Video Packet Status */
/*! @{ */

#define MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_empty_MASK (0x1U)
#define MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_empty_SHIFT (0U)
/*! dpi_cmd_w_empty - DPI Command Write Empty */
#define MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_empty_SHIFT)) & MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_empty_MASK)

#define MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_full_MASK (0x2U)
#define MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_full_SHIFT (1U)
/*! dpi_cmd_w_full - DPI Command Write Full */
#define MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_full(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_full_SHIFT)) & MIPI_DSI_VID_PKT_STATUS_dpi_cmd_w_full_MASK)

#define MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_empty_MASK (0x4U)
#define MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_empty_SHIFT (2U)
/*! dpi_pld_w_empty - DPI Payload Write Empty */
#define MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_empty_SHIFT)) & MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_empty_MASK)

#define MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_full_MASK (0x8U)
#define MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_full_SHIFT (3U)
/*! dpi_pld_w_full - DPI Payload Write Full */
#define MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_full(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_full_SHIFT)) & MIPI_DSI_VID_PKT_STATUS_dpi_pld_w_full_MASK)

#define MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_empty_MASK (0x10000U)
#define MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_empty_SHIFT (16U)
/*! dpi_buff_pld_empty - DPI Buffer Payload Empty */
#define MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_empty(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_empty_SHIFT)) & MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_empty_MASK)

#define MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_full_MASK (0x20000U)
#define MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_full_SHIFT (17U)
/*! dpi_buff_pld_full - DPI Buffer Payload Full */
#define MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_full(x) (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_full_SHIFT)) & MIPI_DSI_VID_PKT_STATUS_dpi_buff_pld_full_MASK)
/*! @} */

/*! @name SDF_3D_ACT - 3D Control Information Value */
/*! @{ */

#define MIPI_DSI_SDF_3D_ACT_mode_3d_MASK         (0x3U)
#define MIPI_DSI_SDF_3D_ACT_mode_3d_SHIFT        (0U)
/*! mode_3d - Mode 3D
 *  0b00..3D Mode Off, 2D Mode On
 *  0b01..3D Mode On, Portrait Orientation
 *  0b10..3D Mode On, Landscape Orientation
 *  0b11..
 */
#define MIPI_DSI_SDF_3D_ACT_mode_3d(x)           (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_ACT_mode_3d_SHIFT)) & MIPI_DSI_SDF_3D_ACT_mode_3d_MASK)

#define MIPI_DSI_SDF_3D_ACT_format_3d_MASK       (0xCU)
#define MIPI_DSI_SDF_3D_ACT_format_3d_SHIFT      (2U)
/*! format_3d - Format 3D
 *  0b00..Alternating lines of left and right data
 *  0b01..Alternating frames of left and right data
 *  0b10..Alternating pixels of left and right data
 *  0b11..
 */
#define MIPI_DSI_SDF_3D_ACT_format_3d(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_ACT_format_3d_SHIFT)) & MIPI_DSI_SDF_3D_ACT_format_3d_MASK)

#define MIPI_DSI_SDF_3D_ACT_second_vsync_MASK    (0x10U)
#define MIPI_DSI_SDF_3D_ACT_second_vsync_SHIFT   (4U)
/*! second_vsync - Second VSYNC
 *  0b0..No sync pulses between left and right data.
 *  0b1..Sync pulse (HSYNC, VSYNC, blanking) between left and right data.
 */
#define MIPI_DSI_SDF_3D_ACT_second_vsync(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_ACT_second_vsync_SHIFT)) & MIPI_DSI_SDF_3D_ACT_second_vsync_MASK)

#define MIPI_DSI_SDF_3D_ACT_right_first_MASK     (0x20U)
#define MIPI_DSI_SDF_3D_ACT_right_first_SHIFT    (5U)
/*! right_first - Right First
 *  0b0..Left eye is sent first, then right eye
 *  0b1..Right eye data is sent first, then left eye
 */
#define MIPI_DSI_SDF_3D_ACT_right_first(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_ACT_right_first_SHIFT)) & MIPI_DSI_SDF_3D_ACT_right_first_MASK)

#define MIPI_DSI_SDF_3D_ACT_send_3d_cfg_MASK     (0x10000U)
#define MIPI_DSI_SDF_3D_ACT_send_3d_cfg_SHIFT    (16U)
/*! send_3d_cfg - Send 3D Configuration */
#define MIPI_DSI_SDF_3D_ACT_send_3d_cfg(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_DSI_SDF_3D_ACT_send_3d_cfg_SHIFT)) & MIPI_DSI_SDF_3D_ACT_send_3d_cfg_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_DSI_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_DSI_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_DSI_H_ */
