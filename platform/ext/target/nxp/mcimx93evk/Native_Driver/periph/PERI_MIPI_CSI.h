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
**         CMSIS Peripheral Access Layer for MIPI_CSI
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
 * @file PERI_MIPI_CSI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_CSI
 *
 * CMSIS Peripheral Access Layer for MIPI_CSI
 */

#if !defined(PERI_MIPI_CSI_H_)
#define PERI_MIPI_CSI_H_                         /**< Symbol preventing repeated inclusion */

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
   -- MIPI_CSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI_Peripheral_Access_Layer MIPI_CSI Peripheral Access Layer
 * @{
 */

/** MIPI_CSI - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERSION;                           /**< Core Version, offset: 0x0 */
  __IO uint32_t N_LANES;                           /**< Number of Lanes, offset: 0x4 */
  __IO uint32_t CSI2_RESETN;                       /**< Logic Reset, offset: 0x8 */
  __I  uint32_t INT_ST_MAIN;                       /**< Main Interrupt Status, offset: 0xC */
       uint8_t RESERVED_0[48];
  __IO uint32_t PHY_SHUTDOWNZ;                     /**< PHY Shutdown, offset: 0x40 */
  __IO uint32_t DPHY_RSTZ;                         /**< DPHY Reset, offset: 0x44 */
  __I  uint32_t PHY_RX;                            /**< RX PHY Status, offset: 0x48 */
  __I  uint32_t PHY_STOPSTATE;                     /**< STOPSTATE PHY Status, offset: 0x4C */
  __IO uint32_t PHY_TEST_CTRL0;                    /**< D-PHY Test and Control Interface 1, offset: 0x50 */
  __IO uint32_t PHY_TEST_CTRL1;                    /**< D-PHY Test and Control Interface 2, offset: 0x54 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PPI_PG_PATTERN_VRES;               /**< Pattern Generator Vertical Resolution, offset: 0x60 */
  __IO uint32_t PPI_PG_PATTERN_HRES;               /**< Pattern Generator Horizontal Resolution, offset: 0x64 */
  __IO uint32_t PPI_PG_CONFIG;                     /**< Pattern Generator, offset: 0x68 */
  __IO uint32_t PPI_PG_ENABLE;                     /**< Pattern Generator Enable, offset: 0x6C */
  __I  uint32_t PPI_PG_STATUS;                     /**< Pattern Generator Status, offset: 0x70 */
       uint8_t RESERVED_2[12];
  __IO uint32_t IPI_MODE;                          /**< IPI Mode, offset: 0x80 */
  __IO uint32_t IPI_VCID;                          /**< IPI Virtual Channel, offset: 0x84 */
  __IO uint32_t IPI_DATA_TYPE;                     /**< IPI Data Type, offset: 0x88 */
  __IO uint32_t IPI_MEM_FLUSH;                     /**< IPI Flush Memory, offset: 0x8C */
  __IO uint32_t IPI_HSA_TIME;                      /**< IPI HSA, offset: 0x90 */
  __IO uint32_t IPI_HBP_TIME;                      /**< IPI HBP, offset: 0x94 */
  __IO uint32_t IPI_HSD_TIME;                      /**< IPI HSD, offset: 0x98 */
  __IO uint32_t IPI_HLINE_TIME;                    /**< IPI HLINE, offset: 0x9C */
  __IO uint32_t IPI_SOFTRSTN;                      /**< IPI Soft Reset, offset: 0xA0 */
       uint8_t RESERVED_3[8];
  __IO uint32_t IPI_ADV_FEATURES;                  /**< IPI Advanced Features, offset: 0xAC */
  __IO uint32_t IPI_VSA_LINES;                     /**< IPI VSA, offset: 0xB0 */
  __IO uint32_t IPI_VBP_LINES;                     /**< IPI VBP, offset: 0xB4 */
  __IO uint32_t IPI_VFP_LINES;                     /**< IPI VFP, offset: 0xB8 */
  __IO uint32_t IPI_VACTIVE_LINES;                 /**< IPI VACTIVE, offset: 0xBC */
       uint8_t RESERVED_4[32];
  __I  uint32_t INT_ST_PHY_FATAL;                  /**< Fatal Interruption Caused by PHY, offset: 0xE0 */
  __IO uint32_t INT_MSK_PHY_FATAL;                 /**< Mask for Fatal Interruption Caused by PHY, offset: 0xE4 */
  __IO uint32_t INT_FORCE_PHY_FATAL;               /**< Force for Fatal Interruption Caused by PHY, offset: 0xE8 */
       uint8_t RESERVED_5[4];
  __I  uint32_t INT_ST_PKT_FATAL;                  /**< Fatal Interruption Caused During Packet Construction, offset: 0xF0 */
  __IO uint32_t INT_MSK_PKT_FATAL;                 /**< Mask for Fatal Interruption Caused During Packet Construction, offset: 0xF4 */
  __IO uint32_t INT_FORCE_PKT_FATAL;               /**< Force for Fatal Interruption Caused During Packet Construction, offset: 0xF8 */
       uint8_t RESERVED_6[20];
  __I  uint32_t INT_ST_PHY;                        /**< Interruption Caused by PHY, offset: 0x110 */
  __IO uint32_t INT_MSK_PHY;                       /**< Mask for Interruption Caused by PHY, offset: 0x114 */
  __IO uint32_t INT_FORCE_PHY;                     /**< Force for Interruption Caused by PHY, offset: 0x118 */
       uint8_t RESERVED_7[36];
  __I  uint32_t INT_ST_IPI_FATAL;                  /**< Fatal Interruption Caused by IPI Interface, offset: 0x140 */
  __IO uint32_t INT_MSK_IPI_FATAL;                 /**< Mask for Fatal Interruption Caused by IPI Interface, offset: 0x144 */
  __IO uint32_t INT_FORCE_IPI_FATAL;               /**< Force for Fatal Interruption Caused by IPI Interface, offset: 0x148 */
       uint8_t RESERVED_8[436];
  __IO uint32_t SCRAMBLING;                        /**< Data De-Scrambling, offset: 0x300 */
  __IO uint32_t SCRAMBLING_SEED1;                  /**< De-scrambler Seed for Lane 1, offset: 0x304 */
  __IO uint32_t SCRAMBLING_SEED2;                  /**< De-scrambler Seed for Lane 2, offset: 0x308 */
} MIPI_CSI_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_CSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI_Register_Masks MIPI_CSI Register Masks
 * @{
 */

/*! @name VERSION - Core Version */
/*! @{ */

#define MIPI_CSI_VERSION_version_MASK            (0xFFFFFFFFU)
#define MIPI_CSI_VERSION_version_SHIFT           (0U)
/*! version - Indicates the version of the mipi_csi2_host. */
#define MIPI_CSI_VERSION_version(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_VERSION_version_SHIFT)) & MIPI_CSI_VERSION_version_MASK)
/*! @} */

/*! @name N_LANES - Number of Lanes */
/*! @{ */

#define MIPI_CSI_N_LANES_n_lanes_MASK            (0x7U)
#define MIPI_CSI_N_LANES_n_lanes_SHIFT           (0U)
/*! n_lanes - N_LANES can only be updated when the PHY lane is in stop state.
 *  0b000..1 Data Lane
 *  0b001..2 Data Lanes
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MIPI_CSI_N_LANES_n_lanes(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_N_LANES_n_lanes_SHIFT)) & MIPI_CSI_N_LANES_n_lanes_MASK)
/*! @} */

/*! @name CSI2_RESETN - Logic Reset */
/*! @{ */

#define MIPI_CSI_CSI2_RESETN_csi2_resetn_MASK    (0x1U)
#define MIPI_CSI_CSI2_RESETN_csi2_resetn_SHIFT   (0U)
/*! csi2_resetn - mipi_csi2_host reset output. */
#define MIPI_CSI_CSI2_RESETN_csi2_resetn(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSI2_RESETN_csi2_resetn_SHIFT)) & MIPI_CSI_CSI2_RESETN_csi2_resetn_MASK)
/*! @} */

/*! @name INT_ST_MAIN - Main Interrupt Status */
/*! @{ */

#define MIPI_CSI_INT_ST_MAIN_status_int_phy_fatal_MASK (0x1U)
#define MIPI_CSI_INT_ST_MAIN_status_int_phy_fatal_SHIFT (0U)
/*! status_int_phy_fatal - Status of int_st_phy_fatal. */
#define MIPI_CSI_INT_ST_MAIN_status_int_phy_fatal(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_phy_fatal_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_phy_fatal_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_pkt_fatal_MASK (0x2U)
#define MIPI_CSI_INT_ST_MAIN_status_int_pkt_fatal_SHIFT (1U)
/*! status_int_pkt_fatal - Status of int_st_pkt_fatal. */
#define MIPI_CSI_INT_ST_MAIN_status_int_pkt_fatal(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_pkt_fatal_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_pkt_fatal_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_bndry_frame_fatal_MASK (0x4U)
#define MIPI_CSI_INT_ST_MAIN_status_int_bndry_frame_fatal_SHIFT (2U)
/*! status_int_bndry_frame_fatal - Status of int_st_bndry_frame_fatal. */
#define MIPI_CSI_INT_ST_MAIN_status_int_bndry_frame_fatal(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_bndry_frame_fatal_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_bndry_frame_fatal_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_seq_frame_fatal_MASK (0x8U)
#define MIPI_CSI_INT_ST_MAIN_status_int_seq_frame_fatal_SHIFT (3U)
/*! status_int_seq_frame_fatal - Status of status_int_seq_frame_fatal. */
#define MIPI_CSI_INT_ST_MAIN_status_int_seq_frame_fatal(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_seq_frame_fatal_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_seq_frame_fatal_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_crc_frame_fatal_MASK (0x10U)
#define MIPI_CSI_INT_ST_MAIN_status_int_crc_frame_fatal_SHIFT (4U)
/*! status_int_crc_frame_fatal - Status of status_int_crc_frame_fatal. */
#define MIPI_CSI_INT_ST_MAIN_status_int_crc_frame_fatal(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_crc_frame_fatal_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_crc_frame_fatal_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_pld_crc_fatal_MASK (0x20U)
#define MIPI_CSI_INT_ST_MAIN_status_int_pld_crc_fatal_SHIFT (5U)
/*! status_int_pld_crc_fatal - Status of status_int_pld_crc_fatal. */
#define MIPI_CSI_INT_ST_MAIN_status_int_pld_crc_fatal(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_pld_crc_fatal_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_pld_crc_fatal_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_data_id_MASK (0x40U)
#define MIPI_CSI_INT_ST_MAIN_status_int_data_id_SHIFT (6U)
/*! status_int_data_id - Status of status_int_data_id. */
#define MIPI_CSI_INT_ST_MAIN_status_int_data_id(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_data_id_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_data_id_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_ecc_corrected_MASK (0x80U)
#define MIPI_CSI_INT_ST_MAIN_status_int_ecc_corrected_SHIFT (7U)
/*! status_int_ecc_corrected - Status of status_int_ecc_corrected. */
#define MIPI_CSI_INT_ST_MAIN_status_int_ecc_corrected(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_ecc_corrected_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_ecc_corrected_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_phy_MASK (0x10000U)
#define MIPI_CSI_INT_ST_MAIN_status_int_phy_SHIFT (16U)
/*! status_int_phy - Status of int_st_phy. */
#define MIPI_CSI_INT_ST_MAIN_status_int_phy(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_phy_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_phy_MASK)

#define MIPI_CSI_INT_ST_MAIN_status_int_ipi_fatal_MASK (0x40000U)
#define MIPI_CSI_INT_ST_MAIN_status_int_ipi_fatal_SHIFT (18U)
/*! status_int_ipi_fatal - Status of int_st_ipi_fatal */
#define MIPI_CSI_INT_ST_MAIN_status_int_ipi_fatal(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_MAIN_status_int_ipi_fatal_SHIFT)) & MIPI_CSI_INT_ST_MAIN_status_int_ipi_fatal_MASK)
/*! @} */

/*! @name PHY_SHUTDOWNZ - PHY Shutdown */
/*! @{ */

#define MIPI_CSI_PHY_SHUTDOWNZ_phy_shutdownz_MASK (0x1U)
#define MIPI_CSI_PHY_SHUTDOWNZ_phy_shutdownz_SHIFT (0U)
/*! phy_shutdownz - Shutdown input. */
#define MIPI_CSI_PHY_SHUTDOWNZ_phy_shutdownz(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_SHUTDOWNZ_phy_shutdownz_SHIFT)) & MIPI_CSI_PHY_SHUTDOWNZ_phy_shutdownz_MASK)
/*! @} */

/*! @name DPHY_RSTZ - DPHY Reset */
/*! @{ */

#define MIPI_CSI_DPHY_RSTZ_dphy_rstz_MASK        (0x1U)
#define MIPI_CSI_DPHY_RSTZ_dphy_rstz_SHIFT       (0U)
/*! dphy_rstz - PHY reset output. */
#define MIPI_CSI_DPHY_RSTZ_dphy_rstz(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_RSTZ_dphy_rstz_SHIFT)) & MIPI_CSI_DPHY_RSTZ_dphy_rstz_MASK)
/*! @} */

/*! @name PHY_RX - RX PHY Status */
/*! @{ */

#define MIPI_CSI_PHY_RX_phy_rxulpsesc_0_MASK     (0x1U)
#define MIPI_CSI_PHY_RX_phy_rxulpsesc_0_SHIFT    (0U)
/*! phy_rxulpsesc_0 - Lane module 0 has entered the Ultra Low Power mode. */
#define MIPI_CSI_PHY_RX_phy_rxulpsesc_0(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_RX_phy_rxulpsesc_0_SHIFT)) & MIPI_CSI_PHY_RX_phy_rxulpsesc_0_MASK)

#define MIPI_CSI_PHY_RX_phy_rxulpsesc_1_MASK     (0x2U)
#define MIPI_CSI_PHY_RX_phy_rxulpsesc_1_SHIFT    (1U)
/*! phy_rxulpsesc_1 - Lane module 1 has entered the Ultra Low Power mode */
#define MIPI_CSI_PHY_RX_phy_rxulpsesc_1(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_RX_phy_rxulpsesc_1_SHIFT)) & MIPI_CSI_PHY_RX_phy_rxulpsesc_1_MASK)

#define MIPI_CSI_PHY_RX_phy_rxulpsclknot_MASK    (0x10000U)
#define MIPI_CSI_PHY_RX_phy_rxulpsclknot_SHIFT   (16U)
/*! phy_rxulpsclknot - Active Low. */
#define MIPI_CSI_PHY_RX_phy_rxulpsclknot(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_RX_phy_rxulpsclknot_SHIFT)) & MIPI_CSI_PHY_RX_phy_rxulpsclknot_MASK)

#define MIPI_CSI_PHY_RX_phy_rxclkactivehs_MASK   (0x20000U)
#define MIPI_CSI_PHY_RX_phy_rxclkactivehs_SHIFT  (17U)
/*! phy_rxclkactivehs - Indicates that D-PHY clock lane is actively receiving a DDR clock */
#define MIPI_CSI_PHY_RX_phy_rxclkactivehs(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_RX_phy_rxclkactivehs_SHIFT)) & MIPI_CSI_PHY_RX_phy_rxclkactivehs_MASK)
/*! @} */

/*! @name PHY_STOPSTATE - STOPSTATE PHY Status */
/*! @{ */

#define MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_0_MASK (0x1U)
#define MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_0_SHIFT (0U)
/*! phy_stopstatedata_0 - Data lane 0 in Stop state. */
#define MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_0_SHIFT)) & MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_0_MASK)

#define MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_1_MASK (0x2U)
#define MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_1_SHIFT (1U)
/*! phy_stopstatedata_1 - Data lane 1 in Stop state */
#define MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_1_SHIFT)) & MIPI_CSI_PHY_STOPSTATE_phy_stopstatedata_1_MASK)

#define MIPI_CSI_PHY_STOPSTATE_phy_stopstateclk_MASK (0x10000U)
#define MIPI_CSI_PHY_STOPSTATE_phy_stopstateclk_SHIFT (16U)
/*! phy_stopstateclk - D-PHY Clock lane in Stop state */
#define MIPI_CSI_PHY_STOPSTATE_phy_stopstateclk(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_STOPSTATE_phy_stopstateclk_SHIFT)) & MIPI_CSI_PHY_STOPSTATE_phy_stopstateclk_MASK)
/*! @} */

/*! @name PHY_TEST_CTRL0 - D-PHY Test and Control Interface 1 */
/*! @{ */

#define MIPI_CSI_PHY_TEST_CTRL0_phy_testclr_MASK (0x1U)
#define MIPI_CSI_PHY_TEST_CTRL0_phy_testclr_SHIFT (0U)
/*! phy_testclr - When active, performs vendor specific interface initialization. */
#define MIPI_CSI_PHY_TEST_CTRL0_phy_testclr(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_TEST_CTRL0_phy_testclr_SHIFT)) & MIPI_CSI_PHY_TEST_CTRL0_phy_testclr_MASK)

#define MIPI_CSI_PHY_TEST_CTRL0_phy_testclk_MASK (0x2U)
#define MIPI_CSI_PHY_TEST_CTRL0_phy_testclk_SHIFT (1U)
/*! phy_testclk - Clock to capture testdin bus contents into the macro, with testen signal controlling the operation selection. */
#define MIPI_CSI_PHY_TEST_CTRL0_phy_testclk(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_TEST_CTRL0_phy_testclk_SHIFT)) & MIPI_CSI_PHY_TEST_CTRL0_phy_testclk_MASK)
/*! @} */

/*! @name PHY_TEST_CTRL1 - D-PHY Test and Control Interface 2 */
/*! @{ */

#define MIPI_CSI_PHY_TEST_CTRL1_phy_testdin_MASK (0xFFU)
#define MIPI_CSI_PHY_TEST_CTRL1_phy_testdin_SHIFT (0U)
/*! phy_testdin - Test interface 8-bit data input for programming internal registers and accessing test functionalities. */
#define MIPI_CSI_PHY_TEST_CTRL1_phy_testdin(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_TEST_CTRL1_phy_testdin_SHIFT)) & MIPI_CSI_PHY_TEST_CTRL1_phy_testdin_MASK)

#define MIPI_CSI_PHY_TEST_CTRL1_phy_testdout_MASK (0xFF00U)
#define MIPI_CSI_PHY_TEST_CTRL1_phy_testdout_SHIFT (8U)
/*! phy_testdout - Vendor-specific 8-bit data output for reading data and other probing functionalities. */
#define MIPI_CSI_PHY_TEST_CTRL1_phy_testdout(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_TEST_CTRL1_phy_testdout_SHIFT)) & MIPI_CSI_PHY_TEST_CTRL1_phy_testdout_MASK)

#define MIPI_CSI_PHY_TEST_CTRL1_phy_testen_MASK  (0x10000U)
#define MIPI_CSI_PHY_TEST_CTRL1_phy_testen_SHIFT (16U)
/*! phy_testen - PHY test enable */
#define MIPI_CSI_PHY_TEST_CTRL1_phy_testen(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PHY_TEST_CTRL1_phy_testen_SHIFT)) & MIPI_CSI_PHY_TEST_CTRL1_phy_testen_MASK)
/*! @} */

/*! @name PPI_PG_PATTERN_VRES - Pattern Generator Vertical Resolution */
/*! @{ */

#define MIPI_CSI_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_MASK (0xFFFFU)
#define MIPI_CSI_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_SHIFT (0U)
/*! ppi_pg_pattern_vres - Configures the pattern vertical resolution of the PPI Pattern Generator. */
#define MIPI_CSI_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_SHIFT)) & MIPI_CSI_PPI_PG_PATTERN_VRES_ppi_pg_pattern_vres_MASK)
/*! @} */

/*! @name PPI_PG_PATTERN_HRES - Pattern Generator Horizontal Resolution */
/*! @{ */

#define MIPI_CSI_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_MASK (0xFFFFU)
#define MIPI_CSI_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_SHIFT (0U)
/*! ppi_pg_pattern_hres - Configures the pattern horizontal resolution of the PPI Pattern Generator. */
#define MIPI_CSI_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_SHIFT)) & MIPI_CSI_PPI_PG_PATTERN_HRES_ppi_pg_pattern_hres_MASK)
/*! @} */

/*! @name PPI_PG_CONFIG - Pattern Generator */
/*! @{ */

#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_pattern_MASK (0x1U)
#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_pattern_SHIFT (0U)
/*! ppi_pg_pattern - Configures the PPI Pattern Generator's pattern:
 *  0b0..Vertical Pattern
 *  0b1..Horizontal Pattern
 */
#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_pattern(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PPI_PG_CONFIG_ppi_pg_pattern_SHIFT)) & MIPI_CSI_PPI_PG_CONFIG_ppi_pg_pattern_MASK)

#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_datatype_MASK (0x3F00U)
#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_datatype_SHIFT (8U)
/*! ppi_pg_datatype - Configures the PPI Pattern Generator's data type. */
#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_datatype(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PPI_PG_CONFIG_ppi_pg_datatype_SHIFT)) & MIPI_CSI_PPI_PG_CONFIG_ppi_pg_datatype_MASK)

#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_vc_MASK    (0xC000U)
#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_vc_SHIFT   (14U)
/*! ppi_pg_vc - Configures the PPI Pattern Generator's virtual channel. */
#define MIPI_CSI_PPI_PG_CONFIG_ppi_pg_vc(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PPI_PG_CONFIG_ppi_pg_vc_SHIFT)) & MIPI_CSI_PPI_PG_CONFIG_ppi_pg_vc_MASK)
/*! @} */

/*! @name PPI_PG_ENABLE - Pattern Generator Enable */
/*! @{ */

#define MIPI_CSI_PPI_PG_ENABLE_ppi_pg_enable_MASK (0x1U)
#define MIPI_CSI_PPI_PG_ENABLE_ppi_pg_enable_SHIFT (0U)
/*! ppi_pg_enable - Enables the PPI Pattern Generator. */
#define MIPI_CSI_PPI_PG_ENABLE_ppi_pg_enable(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PPI_PG_ENABLE_ppi_pg_enable_SHIFT)) & MIPI_CSI_PPI_PG_ENABLE_ppi_pg_enable_MASK)
/*! @} */

/*! @name PPI_PG_STATUS - Pattern Generator Status */
/*! @{ */

#define MIPI_CSI_PPI_PG_STATUS_ppi_pg_status_MASK (0x1U)
#define MIPI_CSI_PPI_PG_STATUS_ppi_pg_status_SHIFT (0U)
/*! ppi_pg_status - PPI Pattern Generator status:
 *  0b0..PPIPG is inactive
 *  0b1..PPI PG is running
 */
#define MIPI_CSI_PPI_PG_STATUS_ppi_pg_status(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_PPI_PG_STATUS_ppi_pg_status_SHIFT)) & MIPI_CSI_PPI_PG_STATUS_ppi_pg_status_MASK)
/*! @} */

/*! @name IPI_MODE - IPI Mode */
/*! @{ */

#define MIPI_CSI_IPI_MODE_ipi_mode_MASK          (0x1U)
#define MIPI_CSI_IPI_MODE_ipi_mode_SHIFT         (0U)
/*! ipi_mode - Indicates the video mode transmission type as follows:
 *  0b0..Camera timing
 *  0b1..Controller timing
 */
#define MIPI_CSI_IPI_MODE_ipi_mode(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_MODE_ipi_mode_SHIFT)) & MIPI_CSI_IPI_MODE_ipi_mode_MASK)

#define MIPI_CSI_IPI_MODE_ipi_color_com_MASK     (0x100U)
#define MIPI_CSI_IPI_MODE_ipi_color_com_SHIFT    (8U)
/*! ipi_color_com - Indicates how color mode components are delivered as follows:
 *  0b0..48 bits interface
 *  0b1..16 bits interface
 */
#define MIPI_CSI_IPI_MODE_ipi_color_com(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_MODE_ipi_color_com_SHIFT)) & MIPI_CSI_IPI_MODE_ipi_color_com_MASK)

#define MIPI_CSI_IPI_MODE_ipi_cut_through_MASK   (0x10000U)
#define MIPI_CSI_IPI_MODE_ipi_cut_through_SHIFT  (16U)
/*! ipi_cut_through - Indicates cut-through mode state:
 *  0b0..Cut-through mode inactive
 *  0b1..Cut-through mode active
 */
#define MIPI_CSI_IPI_MODE_ipi_cut_through(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_MODE_ipi_cut_through_SHIFT)) & MIPI_CSI_IPI_MODE_ipi_cut_through_MASK)

#define MIPI_CSI_IPI_MODE_ipi_enable_MASK        (0x1000000U)
#define MIPI_CSI_IPI_MODE_ipi_enable_SHIFT       (24U)
/*! ipi_enable - Enables the interface. */
#define MIPI_CSI_IPI_MODE_ipi_enable(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_MODE_ipi_enable_SHIFT)) & MIPI_CSI_IPI_MODE_ipi_enable_MASK)
/*! @} */

/*! @name IPI_VCID - IPI Virtual Channel */
/*! @{ */

#define MIPI_CSI_IPI_VCID_ip_vcid_MASK           (0x3U)
#define MIPI_CSI_IPI_VCID_ip_vcid_SHIFT          (0U)
/*! ip_vcid - Virtual channel of data to be processed by pixel interface. */
#define MIPI_CSI_IPI_VCID_ip_vcid(x)             (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_VCID_ip_vcid_SHIFT)) & MIPI_CSI_IPI_VCID_ip_vcid_MASK)
/*! @} */

/*! @name IPI_DATA_TYPE - IPI Data Type */
/*! @{ */

#define MIPI_CSI_IPI_DATA_TYPE_ipi_data_type_MASK (0x3FU)
#define MIPI_CSI_IPI_DATA_TYPE_ipi_data_type_SHIFT (0U)
/*! ipi_data_type - Data type of data to be processed by pixel interface. */
#define MIPI_CSI_IPI_DATA_TYPE_ipi_data_type(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_DATA_TYPE_ipi_data_type_SHIFT)) & MIPI_CSI_IPI_DATA_TYPE_ipi_data_type_MASK)

#define MIPI_CSI_IPI_DATA_TYPE_embedded_data_MASK (0x100U)
#define MIPI_CSI_IPI_DATA_TYPE_embedded_data_SHIFT (8U)
/*! embedded_data - Enables embedded data processing on IPI interface. */
#define MIPI_CSI_IPI_DATA_TYPE_embedded_data(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_DATA_TYPE_embedded_data_SHIFT)) & MIPI_CSI_IPI_DATA_TYPE_embedded_data_MASK)
/*! @} */

/*! @name IPI_MEM_FLUSH - IPI Flush Memory */
/*! @{ */

#define MIPI_CSI_IPI_MEM_FLUSH_ipi_flush_MASK    (0x1U)
#define MIPI_CSI_IPI_MEM_FLUSH_ipi_flush_SHIFT   (0U)
/*! ipi_flush - Flush IPI memory. */
#define MIPI_CSI_IPI_MEM_FLUSH_ipi_flush(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_MEM_FLUSH_ipi_flush_SHIFT)) & MIPI_CSI_IPI_MEM_FLUSH_ipi_flush_MASK)

#define MIPI_CSI_IPI_MEM_FLUSH_ipi_auto_flush_MASK (0x100U)
#define MIPI_CSI_IPI_MEM_FLUSH_ipi_auto_flush_SHIFT (8U)
/*! ipi_auto_flush - Memory is automatically flushed at each Frame Start. */
#define MIPI_CSI_IPI_MEM_FLUSH_ipi_auto_flush(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_MEM_FLUSH_ipi_auto_flush_SHIFT)) & MIPI_CSI_IPI_MEM_FLUSH_ipi_auto_flush_MASK)
/*! @} */

/*! @name IPI_HSA_TIME - IPI HSA */
/*! @{ */

#define MIPI_CSI_IPI_HSA_TIME_ipi_hsa_time_MASK  (0xFFFU)
#define MIPI_CSI_IPI_HSA_TIME_ipi_hsa_time_SHIFT (0U)
/*! ipi_hsa_time - Configures the Horizontal Synchronism Active period in pixclk cycles. */
#define MIPI_CSI_IPI_HSA_TIME_ipi_hsa_time(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_HSA_TIME_ipi_hsa_time_SHIFT)) & MIPI_CSI_IPI_HSA_TIME_ipi_hsa_time_MASK)
/*! @} */

/*! @name IPI_HBP_TIME - IPI HBP */
/*! @{ */

#define MIPI_CSI_IPI_HBP_TIME_ipi_hbp_time_MASK  (0xFFFU)
#define MIPI_CSI_IPI_HBP_TIME_ipi_hbp_time_SHIFT (0U)
/*! ipi_hbp_time - Configures the Horizontal Back Porch period in pixclk cycles. */
#define MIPI_CSI_IPI_HBP_TIME_ipi_hbp_time(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_HBP_TIME_ipi_hbp_time_SHIFT)) & MIPI_CSI_IPI_HBP_TIME_ipi_hbp_time_MASK)
/*! @} */

/*! @name IPI_HSD_TIME - IPI HSD */
/*! @{ */

#define MIPI_CSI_IPI_HSD_TIME_ipi_hsd_time_MASK  (0xFFFU)
#define MIPI_CSI_IPI_HSD_TIME_ipi_hsd_time_SHIFT (0U)
/*! ipi_hsd_time - Configures the Horizontal Sync Porch delay period in pixclk cycles. */
#define MIPI_CSI_IPI_HSD_TIME_ipi_hsd_time(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_HSD_TIME_ipi_hsd_time_SHIFT)) & MIPI_CSI_IPI_HSD_TIME_ipi_hsd_time_MASK)
/*! @} */

/*! @name IPI_HLINE_TIME - IPI HLINE */
/*! @{ */

#define MIPI_CSI_IPI_HLINE_TIME_ipi_hline_time_MASK (0x7FFFU)
#define MIPI_CSI_IPI_HLINE_TIME_ipi_hline_time_SHIFT (0U)
/*! ipi_hline_time - Configures the size of the line time counted in pixclk cycles. */
#define MIPI_CSI_IPI_HLINE_TIME_ipi_hline_time(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_HLINE_TIME_ipi_hline_time_SHIFT)) & MIPI_CSI_IPI_HLINE_TIME_ipi_hline_time_MASK)
/*! @} */

/*! @name IPI_SOFTRSTN - IPI Soft Reset */
/*! @{ */

#define MIPI_CSI_IPI_SOFTRSTN_ipi_softrstn_MASK  (0x1U)
#define MIPI_CSI_IPI_SOFTRSTN_ipi_softrstn_SHIFT (0U)
/*! ipi_softrstn - Resets IPI one. */
#define MIPI_CSI_IPI_SOFTRSTN_ipi_softrstn(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_SOFTRSTN_ipi_softrstn_SHIFT)) & MIPI_CSI_IPI_SOFTRSTN_ipi_softrstn_MASK)
/*! @} */

/*! @name IPI_ADV_FEATURES - IPI Advanced Features */
/*! @{ */

#define MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_overwrite_MASK (0x1U)
#define MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_overwrite_SHIFT (0U)
/*! ipi_dt_overwrite - Ignore datatype of the header using the programmed datatype for decoding. */
#define MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_overwrite(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_overwrite_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_overwrite_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_MASK    (0x3F00U)
#define MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_SHIFT   (8U)
/*! ipi_dt - Datatype to overwrite. */
#define MIPI_CSI_IPI_ADV_FEATURES_ipi_dt(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_ipi_dt_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_line_event_selection_MASK (0x10000U)
#define MIPI_CSI_IPI_ADV_FEATURES_line_event_selection_SHIFT (16U)
/*! line_event_selection - For Camera Mode, allows manual selection of the Packet for line delimiter as follows:
 *  0b0..Controller selects it automatically
 *  0b1..Select packets from list programmed in [17:21]
 */
#define MIPI_CSI_IPI_ADV_FEATURES_line_event_selection(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_line_event_selection_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_line_event_selection_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_en_video_MASK  (0x20000U)
#define MIPI_CSI_IPI_ADV_FEATURES_en_video_SHIFT (17U)
/*! en_video - Allows the use of video packets for IPI synchronization events. */
#define MIPI_CSI_IPI_ADV_FEATURES_en_video(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_en_video_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_en_video_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_en_line_start_MASK (0x40000U)
#define MIPI_CSI_IPI_ADV_FEATURES_en_line_start_SHIFT (18U)
/*! en_line_start - Allows the use of line start packets for IPI synchronization events. */
#define MIPI_CSI_IPI_ADV_FEATURES_en_line_start(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_en_line_start_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_en_line_start_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_en_null_MASK   (0x80000U)
#define MIPI_CSI_IPI_ADV_FEATURES_en_null_SHIFT  (19U)
/*! en_null - Allows the use of null packets for IPI synchronization events. */
#define MIPI_CSI_IPI_ADV_FEATURES_en_null(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_en_null_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_en_null_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_en_blanking_MASK (0x100000U)
#define MIPI_CSI_IPI_ADV_FEATURES_en_blanking_SHIFT (20U)
/*! en_blanking - Allows the use of blanking packets for IPI synchronization events. */
#define MIPI_CSI_IPI_ADV_FEATURES_en_blanking(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_en_blanking_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_en_blanking_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_en_embedded_MASK (0x200000U)
#define MIPI_CSI_IPI_ADV_FEATURES_en_embedded_SHIFT (21U)
/*! en_embedded - Allows the use of embedded packets for IPI synchronization events. */
#define MIPI_CSI_IPI_ADV_FEATURES_en_embedded(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_en_embedded_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_en_embedded_MASK)

#define MIPI_CSI_IPI_ADV_FEATURES_ipi_sync_event_mode_MASK (0x1000000U)
#define MIPI_CSI_IPI_ADV_FEATURES_ipi_sync_event_mode_SHIFT (24U)
/*! ipi_sync_event_mode - For Camera Mode:
 *  0b0..Frame Start does not trigger any sync event.
 *  0b1..Legacy mode. Frame Start triggers a sync event.
 */
#define MIPI_CSI_IPI_ADV_FEATURES_ipi_sync_event_mode(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_ADV_FEATURES_ipi_sync_event_mode_SHIFT)) & MIPI_CSI_IPI_ADV_FEATURES_ipi_sync_event_mode_MASK)
/*! @} */

/*! @name IPI_VSA_LINES - IPI VSA */
/*! @{ */

#define MIPI_CSI_IPI_VSA_LINES_ipi_vsa_lines_MASK (0x3FFU)
#define MIPI_CSI_IPI_VSA_LINES_ipi_vsa_lines_SHIFT (0U)
/*! ipi_vsa_lines - Configures the Vertical Synchronism Active period measured in number of horizontal lines. */
#define MIPI_CSI_IPI_VSA_LINES_ipi_vsa_lines(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_VSA_LINES_ipi_vsa_lines_SHIFT)) & MIPI_CSI_IPI_VSA_LINES_ipi_vsa_lines_MASK)
/*! @} */

/*! @name IPI_VBP_LINES - IPI VBP */
/*! @{ */

#define MIPI_CSI_IPI_VBP_LINES_ipi_vbp_lines_MASK (0x3FFU)
#define MIPI_CSI_IPI_VBP_LINES_ipi_vbp_lines_SHIFT (0U)
/*! ipi_vbp_lines - Configures the Vertical Back Porch period measured in number of horizontal lines. */
#define MIPI_CSI_IPI_VBP_LINES_ipi_vbp_lines(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_VBP_LINES_ipi_vbp_lines_SHIFT)) & MIPI_CSI_IPI_VBP_LINES_ipi_vbp_lines_MASK)
/*! @} */

/*! @name IPI_VFP_LINES - IPI VFP */
/*! @{ */

#define MIPI_CSI_IPI_VFP_LINES_ipi_vfp_lines_MASK (0x3FFU)
#define MIPI_CSI_IPI_VFP_LINES_ipi_vfp_lines_SHIFT (0U)
/*! ipi_vfp_lines - Configures the Vertical Front Porch period measured in number of horizontal lines. */
#define MIPI_CSI_IPI_VFP_LINES_ipi_vfp_lines(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_VFP_LINES_ipi_vfp_lines_SHIFT)) & MIPI_CSI_IPI_VFP_LINES_ipi_vfp_lines_MASK)
/*! @} */

/*! @name IPI_VACTIVE_LINES - IPI VACTIVE */
/*! @{ */

#define MIPI_CSI_IPI_VACTIVE_LINES_ipi_vactive_lines_MASK (0x3FFFU)
#define MIPI_CSI_IPI_VACTIVE_LINES_ipi_vactive_lines_SHIFT (0U)
/*! ipi_vactive_lines - Configures the Vertical Active period measured in number of horizontal lines. */
#define MIPI_CSI_IPI_VACTIVE_LINES_ipi_vactive_lines(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_IPI_VACTIVE_LINES_ipi_vactive_lines_SHIFT)) & MIPI_CSI_IPI_VACTIVE_LINES_ipi_vactive_lines_MASK)
/*! @} */

/*! @name INT_ST_PHY_FATAL - Fatal Interruption Caused by PHY */
/*! @{ */

#define MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_0_MASK (0x1U)
#define MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_0_SHIFT (0U)
/*! phy_errsotsynchs_0 - Start of transmission error on data lane 0 (no synchronization achieved). */
#define MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_0_SHIFT)) & MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_0_MASK)

#define MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_1_MASK (0x2U)
#define MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_1_SHIFT (1U)
/*! phy_errsotsynchs_1 - Start of transmission error on data lane 1 (no synchronization achieved) */
#define MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_1_SHIFT)) & MIPI_CSI_INT_ST_PHY_FATAL_phy_errsotsynchs_1_MASK)
/*! @} */

/*! @name INT_MSK_PHY_FATAL - Mask for Fatal Interruption Caused by PHY */
/*! @{ */

#define MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_MASK (0x1U)
#define MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_SHIFT (0U)
/*! mask_phy_errsotsynchs_0 - Mask for phy_errsotsynchs_0. */
#define MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_SHIFT)) & MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_0_MASK)

#define MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_MASK (0x2U)
#define MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_SHIFT (1U)
/*! mask_phy_errsotsynchs_1 - Mask for phy_errsotsynchs_1 */
#define MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_SHIFT)) & MIPI_CSI_INT_MSK_PHY_FATAL_mask_phy_errsotsynchs_1_MASK)
/*! @} */

/*! @name INT_FORCE_PHY_FATAL - Force for Fatal Interruption Caused by PHY */
/*! @{ */

#define MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_MASK (0x1U)
#define MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_SHIFT (0U)
/*! force_phy_errsotsynchs_0 - Force phy_errsotsynchs_0. */
#define MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_SHIFT)) & MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_0_MASK)

#define MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_MASK (0x2U)
#define MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_SHIFT (1U)
/*! force_phy_errsotsynchs_1 - Force phy_errsotsynchs_1 */
#define MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_SHIFT)) & MIPI_CSI_INT_FORCE_PHY_FATAL_force_phy_errsotsynchs_1_MASK)
/*! @} */

/*! @name INT_ST_PKT_FATAL - Fatal Interruption Caused During Packet Construction */
/*! @{ */

#define MIPI_CSI_INT_ST_PKT_FATAL_err_ecc_double_MASK (0x1U)
#define MIPI_CSI_INT_ST_PKT_FATAL_err_ecc_double_SHIFT (0U)
/*! err_ecc_double - Header ECC contains at least 2 errors, unrecoverable. */
#define MIPI_CSI_INT_ST_PKT_FATAL_err_ecc_double(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PKT_FATAL_err_ecc_double_SHIFT)) & MIPI_CSI_INT_ST_PKT_FATAL_err_ecc_double_MASK)

#define MIPI_CSI_INT_ST_PKT_FATAL_shorter_payload_MASK (0x2U)
#define MIPI_CSI_INT_ST_PKT_FATAL_shorter_payload_SHIFT (1U)
/*! shorter_payload - Reported greater WC than received, unrecoverable. */
#define MIPI_CSI_INT_ST_PKT_FATAL_shorter_payload(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PKT_FATAL_shorter_payload_SHIFT)) & MIPI_CSI_INT_ST_PKT_FATAL_shorter_payload_MASK)
/*! @} */

/*! @name INT_MSK_PKT_FATAL - Mask for Fatal Interruption Caused During Packet Construction */
/*! @{ */

#define MIPI_CSI_INT_MSK_PKT_FATAL_mask_err_ecc_double_MASK (0x1U)
#define MIPI_CSI_INT_MSK_PKT_FATAL_mask_err_ecc_double_SHIFT (0U)
/*! mask_err_ecc_double - Mask for err_ecc_double. */
#define MIPI_CSI_INT_MSK_PKT_FATAL_mask_err_ecc_double(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PKT_FATAL_mask_err_ecc_double_SHIFT)) & MIPI_CSI_INT_MSK_PKT_FATAL_mask_err_ecc_double_MASK)

#define MIPI_CSI_INT_MSK_PKT_FATAL_mask_shorter_payload_MASK (0x2U)
#define MIPI_CSI_INT_MSK_PKT_FATAL_mask_shorter_payload_SHIFT (1U)
/*! mask_shorter_payload - Mask for shorter_payload. */
#define MIPI_CSI_INT_MSK_PKT_FATAL_mask_shorter_payload(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PKT_FATAL_mask_shorter_payload_SHIFT)) & MIPI_CSI_INT_MSK_PKT_FATAL_mask_shorter_payload_MASK)
/*! @} */

/*! @name INT_FORCE_PKT_FATAL - Force for Fatal Interruption Caused During Packet Construction */
/*! @{ */

#define MIPI_CSI_INT_FORCE_PKT_FATAL_force_err_ecc_double_MASK (0x1U)
#define MIPI_CSI_INT_FORCE_PKT_FATAL_force_err_ecc_double_SHIFT (0U)
/*! force_err_ecc_double - Force err_ecc_double. */
#define MIPI_CSI_INT_FORCE_PKT_FATAL_force_err_ecc_double(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PKT_FATAL_force_err_ecc_double_SHIFT)) & MIPI_CSI_INT_FORCE_PKT_FATAL_force_err_ecc_double_MASK)

#define MIPI_CSI_INT_FORCE_PKT_FATAL_force_shorter_payload_MASK (0x2U)
#define MIPI_CSI_INT_FORCE_PKT_FATAL_force_shorter_payload_SHIFT (1U)
/*! force_shorter_payload - Force shorter_payload. */
#define MIPI_CSI_INT_FORCE_PKT_FATAL_force_shorter_payload(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PKT_FATAL_force_shorter_payload_SHIFT)) & MIPI_CSI_INT_FORCE_PKT_FATAL_force_shorter_payload_MASK)
/*! @} */

/*! @name INT_ST_PHY - Interruption Caused by PHY */
/*! @{ */

#define MIPI_CSI_INT_ST_PHY_phy_errsoths_0_MASK  (0x1U)
#define MIPI_CSI_INT_ST_PHY_phy_errsoths_0_SHIFT (0U)
/*! phy_errsoths_0 - Start of transmission error on data lane 0 (synchronization can still be achieved). */
#define MIPI_CSI_INT_ST_PHY_phy_errsoths_0(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PHY_phy_errsoths_0_SHIFT)) & MIPI_CSI_INT_ST_PHY_phy_errsoths_0_MASK)

#define MIPI_CSI_INT_ST_PHY_phy_errsoths_1_MASK  (0x2U)
#define MIPI_CSI_INT_ST_PHY_phy_errsoths_1_SHIFT (1U)
/*! phy_errsoths_1 - Start of transmission error on data lane 1 (synchronization can still be achieved) */
#define MIPI_CSI_INT_ST_PHY_phy_errsoths_1(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PHY_phy_errsoths_1_SHIFT)) & MIPI_CSI_INT_ST_PHY_phy_errsoths_1_MASK)

#define MIPI_CSI_INT_ST_PHY_phy_erresc_0_MASK    (0x10000U)
#define MIPI_CSI_INT_ST_PHY_phy_erresc_0_SHIFT   (16U)
/*! phy_erresc_0 - Escape Entry Error on data lane 0. */
#define MIPI_CSI_INT_ST_PHY_phy_erresc_0(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PHY_phy_erresc_0_SHIFT)) & MIPI_CSI_INT_ST_PHY_phy_erresc_0_MASK)

#define MIPI_CSI_INT_ST_PHY_phy_erresc_1_MASK    (0x20000U)
#define MIPI_CSI_INT_ST_PHY_phy_erresc_1_SHIFT   (17U)
/*! phy_erresc_1 - Escape Entry Error on data lane 1 */
#define MIPI_CSI_INT_ST_PHY_phy_erresc_1(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_PHY_phy_erresc_1_SHIFT)) & MIPI_CSI_INT_ST_PHY_phy_erresc_1_MASK)
/*! @} */

/*! @name INT_MSK_PHY - Mask for Interruption Caused by PHY */
/*! @{ */

#define MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_0_MASK (0x1U)
#define MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_0_SHIFT (0U)
/*! mask_phy_errsoths_0 - Mask for phy_errsoths_0. */
#define MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_0_SHIFT)) & MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_0_MASK)

#define MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_1_MASK (0x2U)
#define MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_1_SHIFT (1U)
/*! mask_phy_errsoths_1 - Mask for phy_errsoths_1 */
#define MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_1_SHIFT)) & MIPI_CSI_INT_MSK_PHY_mask_phy_errsoths_1_MASK)

#define MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_0_MASK (0x10000U)
#define MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_0_SHIFT (16U)
/*! mask_phy_erresc_0 - Mask for phy_erresc_0. */
#define MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_0_SHIFT)) & MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_0_MASK)

#define MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_1_MASK (0x20000U)
#define MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_1_SHIFT (17U)
/*! mask_phy_erresc_1 - Mask for phy_erresc_1 */
#define MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_1_SHIFT)) & MIPI_CSI_INT_MSK_PHY_mask_phy_erresc_1_MASK)
/*! @} */

/*! @name INT_FORCE_PHY - Force for Interruption Caused by PHY */
/*! @{ */

#define MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_0_MASK (0x1U)
#define MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_0_SHIFT (0U)
/*! force_phy_errsoths_0 - Force phy_errsoths_0. */
#define MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_0_SHIFT)) & MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_0_MASK)

#define MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_1_MASK (0x2U)
#define MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_1_SHIFT (1U)
/*! force_phy_errsoths_1 - Force phy_errsoths_1 */
#define MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_1_SHIFT)) & MIPI_CSI_INT_FORCE_PHY_force_phy_errsoths_1_MASK)

#define MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_0_MASK (0x10000U)
#define MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_0_SHIFT (16U)
/*! force_phy_erresc_0 - Force phy_erresc_0 */
#define MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_0(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_0_SHIFT)) & MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_0_MASK)

#define MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_1_MASK (0x20000U)
#define MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_1_SHIFT (17U)
/*! force_phy_erresc_1 - Force phy_erresc_1 */
#define MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_1_SHIFT)) & MIPI_CSI_INT_FORCE_PHY_force_phy_erresc_1_MASK)
/*! @} */

/*! @name INT_ST_IPI_FATAL - Fatal Interruption Caused by IPI Interface */
/*! @{ */

#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_underflow_MASK (0x1U)
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_underflow_SHIFT (0U)
/*! pixel_if_fifo_underflow - The FIFO has become empty before the expected number of pixels
 *    (calculated from the packet header) could be extracted to the pixel interface.
 */
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_underflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_underflow_SHIFT)) & MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_underflow_MASK)

#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_overflow_MASK (0x2U)
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_overflow_SHIFT (1U)
/*! pixel_if_fifo_overflow - The FIFO of pixel interface has lost information because some data arrived and FIFO is already full. */
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_overflow_SHIFT)) & MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_overflow_MASK)

#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_frame_sync_err_MASK (0x4U)
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_frame_sync_err_SHIFT (2U)
/*! pixel_if_frame_sync_err - Whenever in Controller mode, notifies if a new frame is received but previous has not been completed. */
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_frame_sync_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_frame_sync_err_SHIFT)) & MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_frame_sync_err_MASK)

#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_nempty_fs_MASK (0x8U)
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_nempty_fs_SHIFT (3U)
/*! pixel_if_fifo_nempty_fs - Pixel interface FIFO is not empty */
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_nempty_fs(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_nempty_fs_SHIFT)) & MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_fifo_nempty_fs_MASK)

#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_hline_err_MASK (0x10U)
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_hline_err_SHIFT (4U)
/*! pixel_if_hline_err - Horizontal line time error (only available in controller mode). */
#define MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_hline_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_hline_err_SHIFT)) & MIPI_CSI_INT_ST_IPI_FATAL_pixel_if_hline_err_MASK)

#define MIPI_CSI_INT_ST_IPI_FATAL_int_event_fifo_overflow_MASK (0x20U)
#define MIPI_CSI_INT_ST_IPI_FATAL_int_event_fifo_overflow_SHIFT (5U)
/*! int_event_fifo_overflow - Reporting internal fifo overflow. */
#define MIPI_CSI_INT_ST_IPI_FATAL_int_event_fifo_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_IPI_FATAL_int_event_fifo_overflow_SHIFT)) & MIPI_CSI_INT_ST_IPI_FATAL_int_event_fifo_overflow_MASK)

#define MIPI_CSI_INT_ST_IPI_FATAL_int_pulse_delay_overflow_MASK (0x40U)
#define MIPI_CSI_INT_ST_IPI_FATAL_int_pulse_delay_overflow_SHIFT (6U)
/*! int_pulse_delay_overflow - Reporting internal fifo overflow on pulse delay block. */
#define MIPI_CSI_INT_ST_IPI_FATAL_int_pulse_delay_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_ST_IPI_FATAL_int_pulse_delay_overflow_SHIFT)) & MIPI_CSI_INT_ST_IPI_FATAL_int_pulse_delay_overflow_MASK)
/*! @} */

/*! @name INT_MSK_IPI_FATAL - Mask for Fatal Interruption Caused by IPI Interface */
/*! @{ */

#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_underflow_MASK (0x1U)
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_underflow_SHIFT (0U)
/*! msk_pixel_if_fifo_underflow - Mask for pixel_if_fifo_underflow. */
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_underflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_underflow_SHIFT)) & MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_underflow_MASK)

#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_overflow_MASK (0x2U)
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_overflow_SHIFT (1U)
/*! msk_pixel_if_fifo_overflow - Mask for pixel_if_fifo_overflow. */
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_overflow_SHIFT)) & MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_overflow_MASK)

#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_frame_sync_err_MASK (0x4U)
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_frame_sync_err_SHIFT (2U)
/*! msk_frame_sync_err - Mask for pixel_if_frame_sync_err. */
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_frame_sync_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_IPI_FATAL_msk_frame_sync_err_SHIFT)) & MIPI_CSI_INT_MSK_IPI_FATAL_msk_frame_sync_err_MASK)

#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_nempty_fs_MASK (0x8U)
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_nempty_fs_SHIFT (3U)
/*! msk_pixel_if_fifo_nempty_fs - Mask pixel_if_fifo_nempty_fs. */
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_nempty_fs(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_nempty_fs_SHIFT)) & MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_fifo_nempty_fs_MASK)

#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_hline_err_MASK (0x10U)
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_hline_err_SHIFT (4U)
/*! msk_pixel_if_hline_err - Mask pixel_if_hline_err. */
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_hline_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_hline_err_SHIFT)) & MIPI_CSI_INT_MSK_IPI_FATAL_msk_pixel_if_hline_err_MASK)

#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_event_fifo_overflow_MASK (0x20U)
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_event_fifo_overflow_SHIFT (5U)
/*! msk_int_event_fifo_overflow - Mask int_event_fifo_overflow. */
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_event_fifo_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_event_fifo_overflow_SHIFT)) & MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_event_fifo_overflow_MASK)

#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_pulse_delay_overflow_MASK (0x40U)
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_pulse_delay_overflow_SHIFT (6U)
/*! msk_int_pulse_delay_overflow - Mask int_pulse_delay_overflow. */
#define MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_pulse_delay_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_pulse_delay_overflow_SHIFT)) & MIPI_CSI_INT_MSK_IPI_FATAL_msk_int_pulse_delay_overflow_MASK)
/*! @} */

/*! @name INT_FORCE_IPI_FATAL - Force for Fatal Interruption Caused by IPI Interface */
/*! @{ */

#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_underflow_MASK (0x1U)
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_underflow_SHIFT (0U)
/*! pixel_if_fifo_underflow - Force for pixel_if_fifo_underflow. */
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_underflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_underflow_SHIFT)) & MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_underflow_MASK)

#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_overflow_MASK (0x2U)
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_overflow_SHIFT (1U)
/*! pixel_if_fifo_overflow - Force for pixel_if_fifo_overflow. */
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_overflow_SHIFT)) & MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_overflow_MASK)

#define MIPI_CSI_INT_FORCE_IPI_FATAL_frame_sync_err_MASK (0x4U)
#define MIPI_CSI_INT_FORCE_IPI_FATAL_frame_sync_err_SHIFT (2U)
/*! frame_sync_err - Force for frame_sync_err. */
#define MIPI_CSI_INT_FORCE_IPI_FATAL_frame_sync_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_IPI_FATAL_frame_sync_err_SHIFT)) & MIPI_CSI_INT_FORCE_IPI_FATAL_frame_sync_err_MASK)

#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_nempty_fs_MASK (0x8U)
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_nempty_fs_SHIFT (3U)
/*! pixel_if_fifo_nempty_fs - Force pixel_if_fifo_nempty_fs. */
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_nempty_fs(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_nempty_fs_SHIFT)) & MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_fifo_nempty_fs_MASK)

#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_hline_err_MASK (0x10U)
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_hline_err_SHIFT (4U)
/*! pixel_if_hline_err - Force pixel_if_hline_err. */
#define MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_hline_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_hline_err_SHIFT)) & MIPI_CSI_INT_FORCE_IPI_FATAL_pixel_if_hline_err_MASK)

#define MIPI_CSI_INT_FORCE_IPI_FATAL_int_event_fifo_overflow_MASK (0x20U)
#define MIPI_CSI_INT_FORCE_IPI_FATAL_int_event_fifo_overflow_SHIFT (5U)
/*! int_event_fifo_overflow - Force int_event_fifo_overflow. */
#define MIPI_CSI_INT_FORCE_IPI_FATAL_int_event_fifo_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_IPI_FATAL_int_event_fifo_overflow_SHIFT)) & MIPI_CSI_INT_FORCE_IPI_FATAL_int_event_fifo_overflow_MASK)

#define MIPI_CSI_INT_FORCE_IPI_FATAL_int_pulse_delay_overflow_MASK (0x40U)
#define MIPI_CSI_INT_FORCE_IPI_FATAL_int_pulse_delay_overflow_SHIFT (6U)
/*! int_pulse_delay_overflow - Force int_pulse_delay_overflow. */
#define MIPI_CSI_INT_FORCE_IPI_FATAL_int_pulse_delay_overflow(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INT_FORCE_IPI_FATAL_int_pulse_delay_overflow_SHIFT)) & MIPI_CSI_INT_FORCE_IPI_FATAL_int_pulse_delay_overflow_MASK)
/*! @} */

/*! @name SCRAMBLING - Data De-Scrambling */
/*! @{ */

#define MIPI_CSI_SCRAMBLING_scramble_enable_MASK (0x1U)
#define MIPI_CSI_SCRAMBLING_scramble_enable_SHIFT (0U)
/*! scramble_enable - Enables data de-scrambling on the controller side. */
#define MIPI_CSI_SCRAMBLING_scramble_enable(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SCRAMBLING_scramble_enable_SHIFT)) & MIPI_CSI_SCRAMBLING_scramble_enable_MASK)
/*! @} */

/*! @name SCRAMBLING_SEED1 - De-scrambler Seed for Lane 1 */
/*! @{ */

#define MIPI_CSI_SCRAMBLING_SEED1_scramble_seed_lane1_MASK (0xFFFFU)
#define MIPI_CSI_SCRAMBLING_SEED1_scramble_seed_lane1_SHIFT (0U)
/*! scramble_seed_lane1 - Seed used by De-scrambler block for lane 1 */
#define MIPI_CSI_SCRAMBLING_SEED1_scramble_seed_lane1(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SCRAMBLING_SEED1_scramble_seed_lane1_SHIFT)) & MIPI_CSI_SCRAMBLING_SEED1_scramble_seed_lane1_MASK)
/*! @} */

/*! @name SCRAMBLING_SEED2 - De-scrambler Seed for Lane 2 */
/*! @{ */

#define MIPI_CSI_SCRAMBLING_SEED2_scramble_seed_lane2_MASK (0xFFFFU)
#define MIPI_CSI_SCRAMBLING_SEED2_scramble_seed_lane2_SHIFT (0U)
/*! scramble_seed_lane2 - Seed used by De-scrambler block for lane 2 */
#define MIPI_CSI_SCRAMBLING_SEED2_scramble_seed_lane2(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SCRAMBLING_SEED2_scramble_seed_lane2_SHIFT)) & MIPI_CSI_SCRAMBLING_SEED2_scramble_seed_lane2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_CSI_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_CSI_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_CSI_H_ */
