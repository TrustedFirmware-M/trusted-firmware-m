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
**         CMSIS Peripheral Access Layer for NPU
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
 * @file PERI_NPU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NPU
 *
 * CMSIS Peripheral Access Layer for NPU
 */

#if !defined(PERI_NPU_H_)
#define PERI_NPU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- NPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_Peripheral_Access_Layer NPU Peripheral Access Layer
 * @{
 */

/** NPU - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID;                                /**< ID, offset: 0x0 */
  __I  uint32_t STATUS;                            /**< STATUS, offset: 0x4 */
  __IO uint32_t CMD;                               /**< CMD, offset: 0x8 */
  __IO uint32_t RESET;                             /**< RESET, offset: 0xC */
  __IO uint32_t QBASE0;                            /**< QBASE0, offset: 0x10 */
  __IO uint32_t QBASE1;                            /**< QBASE1, offset: 0x14 */
  __I  uint32_t QREAD;                             /**< QREAD, offset: 0x18 */
  __IO uint32_t QCONFIG;                           /**< QCONFIG, offset: 0x1C */
  __IO uint32_t QSIZE;                             /**< QSIZE, offset: 0x20 */
  __I  uint32_t PROT;                              /**< PROT, offset: 0x24 */
  __I  uint32_t CONFIG;                            /**< CONFIG, offset: 0x28 */
  __IO uint32_t LOCK;                              /**< LOCK, offset: 0x2C */
       uint8_t RESERVED_0[12];
  __IO uint32_t REGIONCFG;                         /**< REGIONCFG, offset: 0x3C */
  __IO uint32_t AXI_LIMIT0;                        /**< AXI_LIMIT0, offset: 0x40 */
  __IO uint32_t AXI_LIMIT1;                        /**< AXI_LIMIT1, offset: 0x44 */
  __IO uint32_t AXI_LIMIT2;                        /**< AXI_LIMIT2, offset: 0x48 */
  __IO uint32_t AXI_LIMIT3;                        /**< AXI_LIMIT3, offset: 0x4C */
       uint8_t RESERVED_1[48];
  __IO uint32_t BASEP0;                            /**< BASEP0, offset: 0x80 */
  __IO uint32_t BASEP1;                            /**< BASEP1, offset: 0x84 */
  __IO uint32_t BASEP2;                            /**< BASEP2, offset: 0x88 */
  __IO uint32_t BASEP3;                            /**< BASEP3, offset: 0x8C */
  __IO uint32_t BASEP4;                            /**< BASEP4, offset: 0x90 */
  __IO uint32_t BASEP5;                            /**< BASEP5, offset: 0x94 */
  __IO uint32_t BASEP6;                            /**< BASEP6, offset: 0x98 */
  __IO uint32_t BASEP7;                            /**< BASEP7, offset: 0x9C */
  __IO uint32_t BASEP8;                            /**< BASEP8, offset: 0xA0 */
  __IO uint32_t BASEP9;                            /**< BASEP9, offset: 0xA4 */
  __IO uint32_t BASEP10;                           /**< BASEP10, offset: 0xA8 */
  __IO uint32_t BASEP11;                           /**< BASEP11, offset: 0xAC */
  __IO uint32_t BASEP12;                           /**< BASEP12, offset: 0xB0 */
  __IO uint32_t BASEP13;                           /**< BASEP13, offset: 0xB4 */
  __IO uint32_t BASEP14;                           /**< BASEP14, offset: 0xB8 */
  __IO uint32_t BASEP15;                           /**< BASEP15, offset: 0xBC */
       uint8_t RESERVED_2[192];
  __IO uint32_t PMCR;                              /**< PMCR, offset: 0x180 */
  __IO uint32_t PMCNTENSET;                        /**< PMCNTENSET, offset: 0x184 */
  __IO uint32_t PMCNTENCLR;                        /**< PMCNTENCLR, offset: 0x188 */
  __IO uint32_t PMOVSSET;                          /**< PMOVSSET, offset: 0x18C */
  __IO uint32_t PMOVSCLR;                          /**< PMOVSCLR, offset: 0x190 */
  __IO uint32_t PMINTSET;                          /**< PMINTSET, offset: 0x194 */
  __IO uint32_t PMINTCLR;                          /**< PMINTCLR, offset: 0x198 */
       uint8_t RESERVED_3[4];
  __IO uint32_t PMCCNTR_LO;                        /**< PMCCNTR_LO, offset: 0x1A0 */
  __IO uint32_t PMCCNTR_HI;                        /**< PMCCNTR_HI, offset: 0x1A4 */
       uint8_t RESERVED_4[4];
  __IO uint32_t PMCAXI_CHAN;                       /**< PMCAXI_CHAN, offset: 0x1AC */
       uint8_t RESERVED_5[336];
  __IO uint32_t PMEVCNTR0;                         /**< PMEVCNTR0, offset: 0x300 */
  __IO uint32_t PMEVCNTR1;                         /**< PMEVCNTR1, offset: 0x304 */
  __IO uint32_t PMEVCNTR2;                         /**< PMEVCNTR2, offset: 0x308 */
  __IO uint32_t PMEVCNTR3;                         /**< PMEVCNTR3, offset: 0x30C */
       uint8_t RESERVED_6[112];
  __IO uint32_t PMEVTYPER0;                        /**< PMEVTYPER0, offset: 0x380 */
  __IO uint32_t PMEVTYPER1;                        /**< PMEVTYPER1, offset: 0x384 */
  __IO uint32_t PMEVTYPER2;                        /**< PMEVTYPER2, offset: 0x388 */
  __IO uint32_t PMEVTYPER3;                        /**< PMEVTYPER3, offset: 0x38C */
       uint8_t RESERVED_7[3136];
  __I  uint32_t PID4;                              /**< PID4, offset: 0xFD0 */
  __I  uint32_t PID5;                              /**< PID5, offset: 0xFD4 */
  __I  uint32_t PID6;                              /**< PID6, offset: 0xFD8 */
  __I  uint32_t PID7;                              /**< PID7, offset: 0xFDC */
  __I  uint32_t PID0;                              /**< PID0, offset: 0xFE0 */
  __I  uint32_t PID1;                              /**< PID1, offset: 0xFE4 */
  __I  uint32_t PID2;                              /**< PID2, offset: 0xFE8 */
  __I  uint32_t PID3;                              /**< PID3, offset: 0xFEC */
  __I  uint32_t CID0;                              /**< CID0, offset: 0xFF0 */
  __I  uint32_t CID1;                              /**< CID1, offset: 0xFF4 */
  __I  uint32_t CID2;                              /**< CID2, offset: 0xFF8 */
  __I  uint32_t CID3;                              /**< CID3, offset: 0xFFC */
} NPU_Type;

/* ----------------------------------------------------------------------------
   -- NPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_Register_Masks NPU Register Masks
 * @{
 */

/*! @name ID - ID */
/*! @{ */

#define NPU_ID_version_status_MASK               (0xFU)
#define NPU_ID_version_status_SHIFT              (0U)
/*! version_status - version_status */
#define NPU_ID_version_status(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_ID_version_status_SHIFT)) & NPU_ID_version_status_MASK)

#define NPU_ID_version_minor_MASK                (0xF0U)
#define NPU_ID_version_minor_SHIFT               (4U)
/*! version_minor - version_minor */
#define NPU_ID_version_minor(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_ID_version_minor_SHIFT)) & NPU_ID_version_minor_MASK)

#define NPU_ID_version_major_MASK                (0xF00U)
#define NPU_ID_version_major_SHIFT               (8U)
/*! version_major - version_major */
#define NPU_ID_version_major(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_ID_version_major_SHIFT)) & NPU_ID_version_major_MASK)

#define NPU_ID_product_major_MASK                (0xF000U)
#define NPU_ID_product_major_SHIFT               (12U)
/*! product_major - product_major */
#define NPU_ID_product_major(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_ID_product_major_SHIFT)) & NPU_ID_product_major_MASK)

#define NPU_ID_arch_patch_rev_MASK               (0xF0000U)
#define NPU_ID_arch_patch_rev_SHIFT              (16U)
/*! arch_patch_rev - arch_patch_rev */
#define NPU_ID_arch_patch_rev(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_ID_arch_patch_rev_SHIFT)) & NPU_ID_arch_patch_rev_MASK)

#define NPU_ID_arch_minor_rev_MASK               (0xFF00000U)
#define NPU_ID_arch_minor_rev_SHIFT              (20U)
/*! arch_minor_rev - arch_minor_rev */
#define NPU_ID_arch_minor_rev(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_ID_arch_minor_rev_SHIFT)) & NPU_ID_arch_minor_rev_MASK)

#define NPU_ID_arch_major_rev_MASK               (0xF0000000U)
#define NPU_ID_arch_major_rev_SHIFT              (28U)
/*! arch_major_rev - arch_major_rev */
#define NPU_ID_arch_major_rev(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_ID_arch_major_rev_SHIFT)) & NPU_ID_arch_major_rev_MASK)
/*! @} */

/*! @name STATUS - STATUS */
/*! @{ */

#define NPU_STATUS_state_MASK                    (0x1U)
#define NPU_STATUS_state_SHIFT                   (0U)
/*! state - state */
#define NPU_STATUS_state(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_state_SHIFT)) & NPU_STATUS_state_MASK)

#define NPU_STATUS_irq_raised_MASK               (0x2U)
#define NPU_STATUS_irq_raised_SHIFT              (1U)
/*! irq_raised - irq_raised */
#define NPU_STATUS_irq_raised(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_irq_raised_SHIFT)) & NPU_STATUS_irq_raised_MASK)

#define NPU_STATUS_bus_status_MASK               (0x4U)
#define NPU_STATUS_bus_status_SHIFT              (2U)
/*! bus_status - bus_status */
#define NPU_STATUS_bus_status(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_bus_status_SHIFT)) & NPU_STATUS_bus_status_MASK)

#define NPU_STATUS_reset_status_MASK             (0x8U)
#define NPU_STATUS_reset_status_SHIFT            (3U)
/*! reset_status - reset_status */
#define NPU_STATUS_reset_status(x)               (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_reset_status_SHIFT)) & NPU_STATUS_reset_status_MASK)

#define NPU_STATUS_cmd_parse_error_MASK          (0x10U)
#define NPU_STATUS_cmd_parse_error_SHIFT         (4U)
/*! cmd_parse_error - cmd_parse_error */
#define NPU_STATUS_cmd_parse_error(x)            (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_cmd_parse_error_SHIFT)) & NPU_STATUS_cmd_parse_error_MASK)

#define NPU_STATUS_cmd_end_reached_MASK          (0x20U)
#define NPU_STATUS_cmd_end_reached_SHIFT         (5U)
/*! cmd_end_reached - cmd_end_reached */
#define NPU_STATUS_cmd_end_reached(x)            (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_cmd_end_reached_SHIFT)) & NPU_STATUS_cmd_end_reached_MASK)

#define NPU_STATUS_pmu_irq_raised_MASK           (0x40U)
#define NPU_STATUS_pmu_irq_raised_SHIFT          (6U)
/*! pmu_irq_raised - pmu_irq_raised */
#define NPU_STATUS_pmu_irq_raised(x)             (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_pmu_irq_raised_SHIFT)) & NPU_STATUS_pmu_irq_raised_MASK)

#define NPU_STATUS_wd_fault_MASK                 (0x80U)
#define NPU_STATUS_wd_fault_SHIFT                (7U)
/*! wd_fault - wd_fault */
#define NPU_STATUS_wd_fault(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_wd_fault_SHIFT)) & NPU_STATUS_wd_fault_MASK)

#define NPU_STATUS_ecc_fault_MASK                (0x100U)
#define NPU_STATUS_ecc_fault_SHIFT               (8U)
/*! ecc_fault - ecc_fault */
#define NPU_STATUS_ecc_fault(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_ecc_fault_SHIFT)) & NPU_STATUS_ecc_fault_MASK)

#define NPU_STATUS_RES0_MASK                     (0x600U)
#define NPU_STATUS_RES0_SHIFT                    (9U)
/*! RES0 - Reserved */
#define NPU_STATUS_RES0(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_RES0_SHIFT)) & NPU_STATUS_RES0_MASK)

#define NPU_STATUS_faulting_interface_MASK       (0x800U)
#define NPU_STATUS_faulting_interface_SHIFT      (11U)
/*! faulting_interface - faulting_interface */
#define NPU_STATUS_faulting_interface(x)         (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_faulting_interface_SHIFT)) & NPU_STATUS_faulting_interface_MASK)

#define NPU_STATUS_faulting_channel_MASK         (0xF000U)
#define NPU_STATUS_faulting_channel_SHIFT        (12U)
/*! faulting_channel - faulting_channel */
#define NPU_STATUS_faulting_channel(x)           (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_faulting_channel_SHIFT)) & NPU_STATUS_faulting_channel_MASK)

#define NPU_STATUS_irq_history_mask_MASK         (0xFFFF0000U)
#define NPU_STATUS_irq_history_mask_SHIFT        (16U)
/*! irq_history_mask - irq_history_mask */
#define NPU_STATUS_irq_history_mask(x)           (((uint32_t)(((uint32_t)(x)) << NPU_STATUS_irq_history_mask_SHIFT)) & NPU_STATUS_irq_history_mask_MASK)
/*! @} */

/*! @name CMD - CMD */
/*! @{ */

#define NPU_CMD_transition_to_running_state_MASK (0x1U)
#define NPU_CMD_transition_to_running_state_SHIFT (0U)
/*! transition_to_running_state - transition_to_running_state */
#define NPU_CMD_transition_to_running_state(x)   (((uint32_t)(((uint32_t)(x)) << NPU_CMD_transition_to_running_state_SHIFT)) & NPU_CMD_transition_to_running_state_MASK)

#define NPU_CMD_clear_irq_MASK                   (0x2U)
#define NPU_CMD_clear_irq_SHIFT                  (1U)
/*! clear_irq - clear_irq */
#define NPU_CMD_clear_irq(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_CMD_clear_irq_SHIFT)) & NPU_CMD_clear_irq_MASK)

#define NPU_CMD_clock_q_enable_MASK              (0x4U)
#define NPU_CMD_clock_q_enable_SHIFT             (2U)
/*! clock_q_enable - clock_q_enable */
#define NPU_CMD_clock_q_enable(x)                (((uint32_t)(((uint32_t)(x)) << NPU_CMD_clock_q_enable_SHIFT)) & NPU_CMD_clock_q_enable_MASK)

#define NPU_CMD_power_q_enable_MASK              (0x8U)
#define NPU_CMD_power_q_enable_SHIFT             (3U)
/*! power_q_enable - power_q_enable */
#define NPU_CMD_power_q_enable(x)                (((uint32_t)(((uint32_t)(x)) << NPU_CMD_power_q_enable_SHIFT)) & NPU_CMD_power_q_enable_MASK)

#define NPU_CMD_stop_request_MASK                (0x10U)
#define NPU_CMD_stop_request_SHIFT               (4U)
/*! stop_request - stop_request */
#define NPU_CMD_stop_request(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_CMD_stop_request_SHIFT)) & NPU_CMD_stop_request_MASK)

#define NPU_CMD_RES0_MASK                        (0xFFE0U)
#define NPU_CMD_RES0_SHIFT                       (5U)
/*! RES0 - Reserved */
#define NPU_CMD_RES0(x)                          (((uint32_t)(((uint32_t)(x)) << NPU_CMD_RES0_SHIFT)) & NPU_CMD_RES0_MASK)

#define NPU_CMD_clear_irq_history_MASK           (0xFFFF0000U)
#define NPU_CMD_clear_irq_history_SHIFT          (16U)
/*! clear_irq_history - clear_irq_history */
#define NPU_CMD_clear_irq_history(x)             (((uint32_t)(((uint32_t)(x)) << NPU_CMD_clear_irq_history_SHIFT)) & NPU_CMD_clear_irq_history_MASK)
/*! @} */

/*! @name RESET - RESET */
/*! @{ */

#define NPU_RESET_pending_CPL_MASK               (0x1U)
#define NPU_RESET_pending_CPL_SHIFT              (0U)
/*! pending_CPL - pending_CPL */
#define NPU_RESET_pending_CPL(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_RESET_pending_CPL_SHIFT)) & NPU_RESET_pending_CPL_MASK)

#define NPU_RESET_pending_CSL_MASK               (0x2U)
#define NPU_RESET_pending_CSL_SHIFT              (1U)
/*! pending_CSL - pending_CSL */
#define NPU_RESET_pending_CSL(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_RESET_pending_CSL_SHIFT)) & NPU_RESET_pending_CSL_MASK)

#define NPU_RESET_RES0_MASK                      (0xFFFFFFFCU)
#define NPU_RESET_RES0_SHIFT                     (2U)
/*! RES0 - Reserved */
#define NPU_RESET_RES0(x)                        (((uint32_t)(((uint32_t)(x)) << NPU_RESET_RES0_SHIFT)) & NPU_RESET_RES0_MASK)
/*! @} */

/*! @name QBASE0 - QBASE0 */
/*! @{ */

#define NPU_QBASE0_QBASE0_MASK                   (0xFFFFFFFFU)
#define NPU_QBASE0_QBASE0_SHIFT                  (0U)
/*! QBASE0 - QBASE0 */
#define NPU_QBASE0_QBASE0(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_QBASE0_QBASE0_SHIFT)) & NPU_QBASE0_QBASE0_MASK)
/*! @} */

/*! @name QBASE1 - QBASE1 */
/*! @{ */

#define NPU_QBASE1_QBASE1_MASK                   (0xFFFFFFFFU)
#define NPU_QBASE1_QBASE1_SHIFT                  (0U)
/*! QBASE1 - QBASE1 */
#define NPU_QBASE1_QBASE1(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_QBASE1_QBASE1_SHIFT)) & NPU_QBASE1_QBASE1_MASK)
/*! @} */

/*! @name QREAD - QREAD */
/*! @{ */

#define NPU_QREAD_QREAD_MASK                     (0xFFFFFFFFU)
#define NPU_QREAD_QREAD_SHIFT                    (0U)
/*! QREAD - QREAD */
#define NPU_QREAD_QREAD(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_QREAD_QREAD_SHIFT)) & NPU_QREAD_QREAD_MASK)
/*! @} */

/*! @name QCONFIG - QCONFIG */
/*! @{ */

#define NPU_QCONFIG_QCONFIG_MASK                 (0xFFFFFFFFU)
#define NPU_QCONFIG_QCONFIG_SHIFT                (0U)
/*! QCONFIG - QCONFIG */
#define NPU_QCONFIG_QCONFIG(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_QCONFIG_QCONFIG_SHIFT)) & NPU_QCONFIG_QCONFIG_MASK)
/*! @} */

/*! @name QSIZE - QSIZE */
/*! @{ */

#define NPU_QSIZE_QSIZE_MASK                     (0xFFFFFFFFU)
#define NPU_QSIZE_QSIZE_SHIFT                    (0U)
/*! QSIZE - QSIZE */
#define NPU_QSIZE_QSIZE(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_QSIZE_QSIZE_SHIFT)) & NPU_QSIZE_QSIZE_MASK)
/*! @} */

/*! @name PROT - PROT */
/*! @{ */

#define NPU_PROT_active_CPL_MASK                 (0x1U)
#define NPU_PROT_active_CPL_SHIFT                (0U)
/*! active_CPL - active_CPL */
#define NPU_PROT_active_CPL(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PROT_active_CPL_SHIFT)) & NPU_PROT_active_CPL_MASK)

#define NPU_PROT_active_CSL_MASK                 (0x2U)
#define NPU_PROT_active_CSL_SHIFT                (1U)
/*! active_CSL - active_CSL */
#define NPU_PROT_active_CSL(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PROT_active_CSL_SHIFT)) & NPU_PROT_active_CSL_MASK)

#define NPU_PROT_RES0_MASK                       (0xFFFFFFFCU)
#define NPU_PROT_RES0_SHIFT                      (2U)
/*! RES0 - Reserved */
#define NPU_PROT_RES0(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PROT_RES0_SHIFT)) & NPU_PROT_RES0_MASK)
/*! @} */

/*! @name CONFIG - CONFIG */
/*! @{ */

#define NPU_CONFIG_macs_per_cc_MASK              (0xFU)
#define NPU_CONFIG_macs_per_cc_SHIFT             (0U)
/*! macs_per_cc - macs_per_cc */
#define NPU_CONFIG_macs_per_cc(x)                (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_macs_per_cc_SHIFT)) & NPU_CONFIG_macs_per_cc_MASK)

#define NPU_CONFIG_cmd_stream_version_MASK       (0xF0U)
#define NPU_CONFIG_cmd_stream_version_SHIFT      (4U)
/*! cmd_stream_version - cmd_stream_version */
#define NPU_CONFIG_cmd_stream_version(x)         (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_cmd_stream_version_SHIFT)) & NPU_CONFIG_cmd_stream_version_MASK)

#define NPU_CONFIG_shram_size_MASK               (0xFF00U)
#define NPU_CONFIG_shram_size_SHIFT              (8U)
/*! shram_size - shram_size */
#define NPU_CONFIG_shram_size(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_shram_size_SHIFT)) & NPU_CONFIG_shram_size_MASK)

#define NPU_CONFIG_RES0_MASK                     (0xFFF0000U)
#define NPU_CONFIG_RES0_SHIFT                    (16U)
/*! RES0 - Reserved */
#define NPU_CONFIG_RES0(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_RES0_SHIFT)) & NPU_CONFIG_RES0_MASK)

#define NPU_CONFIG_product_MASK                  (0xF0000000U)
#define NPU_CONFIG_product_SHIFT                 (28U)
/*! product - product */
#define NPU_CONFIG_product(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_CONFIG_product_SHIFT)) & NPU_CONFIG_product_MASK)
/*! @} */

/*! @name LOCK - LOCK */
/*! @{ */

#define NPU_LOCK_LOCK_MASK                       (0xFFFFFFFFU)
#define NPU_LOCK_LOCK_SHIFT                      (0U)
/*! LOCK - LOCK */
#define NPU_LOCK_LOCK(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_LOCK_LOCK_SHIFT)) & NPU_LOCK_LOCK_MASK)
/*! @} */

/*! @name REGIONCFG - REGIONCFG */
/*! @{ */

#define NPU_REGIONCFG_region0_MASK               (0x3U)
#define NPU_REGIONCFG_region0_SHIFT              (0U)
/*! region0 - region0 */
#define NPU_REGIONCFG_region0(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region0_SHIFT)) & NPU_REGIONCFG_region0_MASK)

#define NPU_REGIONCFG_region1_MASK               (0xCU)
#define NPU_REGIONCFG_region1_SHIFT              (2U)
/*! region1 - region1 */
#define NPU_REGIONCFG_region1(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region1_SHIFT)) & NPU_REGIONCFG_region1_MASK)

#define NPU_REGIONCFG_region2_MASK               (0x30U)
#define NPU_REGIONCFG_region2_SHIFT              (4U)
/*! region2 - region2 */
#define NPU_REGIONCFG_region2(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region2_SHIFT)) & NPU_REGIONCFG_region2_MASK)

#define NPU_REGIONCFG_region3_MASK               (0xC0U)
#define NPU_REGIONCFG_region3_SHIFT              (6U)
/*! region3 - region3 */
#define NPU_REGIONCFG_region3(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region3_SHIFT)) & NPU_REGIONCFG_region3_MASK)

#define NPU_REGIONCFG_region4_MASK               (0x300U)
#define NPU_REGIONCFG_region4_SHIFT              (8U)
/*! region4 - region4 */
#define NPU_REGIONCFG_region4(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region4_SHIFT)) & NPU_REGIONCFG_region4_MASK)

#define NPU_REGIONCFG_region5_MASK               (0xC00U)
#define NPU_REGIONCFG_region5_SHIFT              (10U)
/*! region5 - region5 */
#define NPU_REGIONCFG_region5(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region5_SHIFT)) & NPU_REGIONCFG_region5_MASK)

#define NPU_REGIONCFG_region6_MASK               (0x3000U)
#define NPU_REGIONCFG_region6_SHIFT              (12U)
/*! region6 - region6 */
#define NPU_REGIONCFG_region6(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region6_SHIFT)) & NPU_REGIONCFG_region6_MASK)

#define NPU_REGIONCFG_region7_MASK               (0xC000U)
#define NPU_REGIONCFG_region7_SHIFT              (14U)
/*! region7 - region7 */
#define NPU_REGIONCFG_region7(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_region7_SHIFT)) & NPU_REGIONCFG_region7_MASK)

#define NPU_REGIONCFG_RES0_MASK                  (0xFFFF0000U)
#define NPU_REGIONCFG_RES0_SHIFT                 (16U)
/*! RES0 - Reserved */
#define NPU_REGIONCFG_RES0(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_REGIONCFG_RES0_SHIFT)) & NPU_REGIONCFG_RES0_MASK)
/*! @} */

/*! @name AXI_LIMIT0 - AXI_LIMIT0 */
/*! @{ */

#define NPU_AXI_LIMIT0_max_beats_MASK            (0x3U)
#define NPU_AXI_LIMIT0_max_beats_SHIFT           (0U)
/*! max_beats - max_beats */
#define NPU_AXI_LIMIT0_max_beats(x)              (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT0_max_beats_SHIFT)) & NPU_AXI_LIMIT0_max_beats_MASK)

#define NPU_AXI_LIMIT0_RES0_MASK                 (0xCU)
#define NPU_AXI_LIMIT0_RES0_SHIFT                (2U)
/*! RES0 - Reserved */
#define NPU_AXI_LIMIT0_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT0_RES0_SHIFT)) & NPU_AXI_LIMIT0_RES0_MASK)

#define NPU_AXI_LIMIT0_memtype_MASK              (0xF0U)
#define NPU_AXI_LIMIT0_memtype_SHIFT             (4U)
/*! memtype - memtype */
#define NPU_AXI_LIMIT0_memtype(x)                (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT0_memtype_SHIFT)) & NPU_AXI_LIMIT0_memtype_MASK)

#define NPU_AXI_LIMIT0_RES1_MASK                 (0xFF00U)
#define NPU_AXI_LIMIT0_RES1_SHIFT                (8U)
/*! RES1 - Reserved */
#define NPU_AXI_LIMIT0_RES1(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT0_RES1_SHIFT)) & NPU_AXI_LIMIT0_RES1_MASK)

#define NPU_AXI_LIMIT0_max_outstanding_read_m1_MASK (0xFF0000U)
#define NPU_AXI_LIMIT0_max_outstanding_read_m1_SHIFT (16U)
/*! max_outstanding_read_m1 - max_outstanding_read_m1 */
#define NPU_AXI_LIMIT0_max_outstanding_read_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT0_max_outstanding_read_m1_SHIFT)) & NPU_AXI_LIMIT0_max_outstanding_read_m1_MASK)

#define NPU_AXI_LIMIT0_max_outstanding_write_m1_MASK (0xFF000000U)
#define NPU_AXI_LIMIT0_max_outstanding_write_m1_SHIFT (24U)
/*! max_outstanding_write_m1 - max_outstanding_write_m1 */
#define NPU_AXI_LIMIT0_max_outstanding_write_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT0_max_outstanding_write_m1_SHIFT)) & NPU_AXI_LIMIT0_max_outstanding_write_m1_MASK)
/*! @} */

/*! @name AXI_LIMIT1 - AXI_LIMIT1 */
/*! @{ */

#define NPU_AXI_LIMIT1_max_beats_MASK            (0x3U)
#define NPU_AXI_LIMIT1_max_beats_SHIFT           (0U)
/*! max_beats - max_beats */
#define NPU_AXI_LIMIT1_max_beats(x)              (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT1_max_beats_SHIFT)) & NPU_AXI_LIMIT1_max_beats_MASK)

#define NPU_AXI_LIMIT1_RES0_MASK                 (0xCU)
#define NPU_AXI_LIMIT1_RES0_SHIFT                (2U)
/*! RES0 - Reserved */
#define NPU_AXI_LIMIT1_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT1_RES0_SHIFT)) & NPU_AXI_LIMIT1_RES0_MASK)

#define NPU_AXI_LIMIT1_memtype_MASK              (0xF0U)
#define NPU_AXI_LIMIT1_memtype_SHIFT             (4U)
/*! memtype - memtype */
#define NPU_AXI_LIMIT1_memtype(x)                (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT1_memtype_SHIFT)) & NPU_AXI_LIMIT1_memtype_MASK)

#define NPU_AXI_LIMIT1_RES1_MASK                 (0xFF00U)
#define NPU_AXI_LIMIT1_RES1_SHIFT                (8U)
/*! RES1 - Reserved */
#define NPU_AXI_LIMIT1_RES1(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT1_RES1_SHIFT)) & NPU_AXI_LIMIT1_RES1_MASK)

#define NPU_AXI_LIMIT1_max_outstanding_read_m1_MASK (0xFF0000U)
#define NPU_AXI_LIMIT1_max_outstanding_read_m1_SHIFT (16U)
/*! max_outstanding_read_m1 - max_outstanding_read_m1 */
#define NPU_AXI_LIMIT1_max_outstanding_read_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT1_max_outstanding_read_m1_SHIFT)) & NPU_AXI_LIMIT1_max_outstanding_read_m1_MASK)

#define NPU_AXI_LIMIT1_max_outstanding_write_m1_MASK (0xFF000000U)
#define NPU_AXI_LIMIT1_max_outstanding_write_m1_SHIFT (24U)
/*! max_outstanding_write_m1 - max_outstanding_write_m1 */
#define NPU_AXI_LIMIT1_max_outstanding_write_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT1_max_outstanding_write_m1_SHIFT)) & NPU_AXI_LIMIT1_max_outstanding_write_m1_MASK)
/*! @} */

/*! @name AXI_LIMIT2 - AXI_LIMIT2 */
/*! @{ */

#define NPU_AXI_LIMIT2_max_beats_MASK            (0x3U)
#define NPU_AXI_LIMIT2_max_beats_SHIFT           (0U)
/*! max_beats - max_beats */
#define NPU_AXI_LIMIT2_max_beats(x)              (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT2_max_beats_SHIFT)) & NPU_AXI_LIMIT2_max_beats_MASK)

#define NPU_AXI_LIMIT2_RES0_MASK                 (0xCU)
#define NPU_AXI_LIMIT2_RES0_SHIFT                (2U)
/*! RES0 - Reserved */
#define NPU_AXI_LIMIT2_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT2_RES0_SHIFT)) & NPU_AXI_LIMIT2_RES0_MASK)

#define NPU_AXI_LIMIT2_memtype_MASK              (0xF0U)
#define NPU_AXI_LIMIT2_memtype_SHIFT             (4U)
/*! memtype - memtype */
#define NPU_AXI_LIMIT2_memtype(x)                (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT2_memtype_SHIFT)) & NPU_AXI_LIMIT2_memtype_MASK)

#define NPU_AXI_LIMIT2_RES1_MASK                 (0xFF00U)
#define NPU_AXI_LIMIT2_RES1_SHIFT                (8U)
/*! RES1 - Reserved */
#define NPU_AXI_LIMIT2_RES1(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT2_RES1_SHIFT)) & NPU_AXI_LIMIT2_RES1_MASK)

#define NPU_AXI_LIMIT2_max_outstanding_read_m1_MASK (0xFF0000U)
#define NPU_AXI_LIMIT2_max_outstanding_read_m1_SHIFT (16U)
/*! max_outstanding_read_m1 - max_outstanding_read_m1 */
#define NPU_AXI_LIMIT2_max_outstanding_read_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT2_max_outstanding_read_m1_SHIFT)) & NPU_AXI_LIMIT2_max_outstanding_read_m1_MASK)

#define NPU_AXI_LIMIT2_max_outstanding_write_m1_MASK (0xFF000000U)
#define NPU_AXI_LIMIT2_max_outstanding_write_m1_SHIFT (24U)
/*! max_outstanding_write_m1 - max_outstanding_write_m1 */
#define NPU_AXI_LIMIT2_max_outstanding_write_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT2_max_outstanding_write_m1_SHIFT)) & NPU_AXI_LIMIT2_max_outstanding_write_m1_MASK)
/*! @} */

/*! @name AXI_LIMIT3 - AXI_LIMIT3 */
/*! @{ */

#define NPU_AXI_LIMIT3_max_beats_MASK            (0x3U)
#define NPU_AXI_LIMIT3_max_beats_SHIFT           (0U)
/*! max_beats - max_beats */
#define NPU_AXI_LIMIT3_max_beats(x)              (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT3_max_beats_SHIFT)) & NPU_AXI_LIMIT3_max_beats_MASK)

#define NPU_AXI_LIMIT3_RES0_MASK                 (0xCU)
#define NPU_AXI_LIMIT3_RES0_SHIFT                (2U)
/*! RES0 - Reserved */
#define NPU_AXI_LIMIT3_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT3_RES0_SHIFT)) & NPU_AXI_LIMIT3_RES0_MASK)

#define NPU_AXI_LIMIT3_memtype_MASK              (0xF0U)
#define NPU_AXI_LIMIT3_memtype_SHIFT             (4U)
/*! memtype - memtype */
#define NPU_AXI_LIMIT3_memtype(x)                (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT3_memtype_SHIFT)) & NPU_AXI_LIMIT3_memtype_MASK)

#define NPU_AXI_LIMIT3_RES1_MASK                 (0xFF00U)
#define NPU_AXI_LIMIT3_RES1_SHIFT                (8U)
/*! RES1 - Reserved */
#define NPU_AXI_LIMIT3_RES1(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT3_RES1_SHIFT)) & NPU_AXI_LIMIT3_RES1_MASK)

#define NPU_AXI_LIMIT3_max_outstanding_read_m1_MASK (0xFF0000U)
#define NPU_AXI_LIMIT3_max_outstanding_read_m1_SHIFT (16U)
/*! max_outstanding_read_m1 - max_outstanding_read_m1 */
#define NPU_AXI_LIMIT3_max_outstanding_read_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT3_max_outstanding_read_m1_SHIFT)) & NPU_AXI_LIMIT3_max_outstanding_read_m1_MASK)

#define NPU_AXI_LIMIT3_max_outstanding_write_m1_MASK (0xFF000000U)
#define NPU_AXI_LIMIT3_max_outstanding_write_m1_SHIFT (24U)
/*! max_outstanding_write_m1 - max_outstanding_write_m1 */
#define NPU_AXI_LIMIT3_max_outstanding_write_m1(x) (((uint32_t)(((uint32_t)(x)) << NPU_AXI_LIMIT3_max_outstanding_write_m1_SHIFT)) & NPU_AXI_LIMIT3_max_outstanding_write_m1_MASK)
/*! @} */

/*! @name BASEP0 - BASEP0 */
/*! @{ */

#define NPU_BASEP0_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP0_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP0_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP0_addr_word_SHIFT)) & NPU_BASEP0_addr_word_MASK)
/*! @} */

/*! @name BASEP1 - BASEP1 */
/*! @{ */

#define NPU_BASEP1_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP1_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP1_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP1_addr_word_SHIFT)) & NPU_BASEP1_addr_word_MASK)
/*! @} */

/*! @name BASEP2 - BASEP2 */
/*! @{ */

#define NPU_BASEP2_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP2_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP2_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP2_addr_word_SHIFT)) & NPU_BASEP2_addr_word_MASK)
/*! @} */

/*! @name BASEP3 - BASEP3 */
/*! @{ */

#define NPU_BASEP3_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP3_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP3_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP3_addr_word_SHIFT)) & NPU_BASEP3_addr_word_MASK)
/*! @} */

/*! @name BASEP4 - BASEP4 */
/*! @{ */

#define NPU_BASEP4_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP4_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP4_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP4_addr_word_SHIFT)) & NPU_BASEP4_addr_word_MASK)
/*! @} */

/*! @name BASEP5 - BASEP5 */
/*! @{ */

#define NPU_BASEP5_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP5_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP5_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP5_addr_word_SHIFT)) & NPU_BASEP5_addr_word_MASK)
/*! @} */

/*! @name BASEP6 - BASEP6 */
/*! @{ */

#define NPU_BASEP6_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP6_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP6_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP6_addr_word_SHIFT)) & NPU_BASEP6_addr_word_MASK)
/*! @} */

/*! @name BASEP7 - BASEP7 */
/*! @{ */

#define NPU_BASEP7_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP7_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP7_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP7_addr_word_SHIFT)) & NPU_BASEP7_addr_word_MASK)
/*! @} */

/*! @name BASEP8 - BASEP8 */
/*! @{ */

#define NPU_BASEP8_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP8_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP8_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP8_addr_word_SHIFT)) & NPU_BASEP8_addr_word_MASK)
/*! @} */

/*! @name BASEP9 - BASEP9 */
/*! @{ */

#define NPU_BASEP9_addr_word_MASK                (0xFFFFFFFFU)
#define NPU_BASEP9_addr_word_SHIFT               (0U)
/*! addr_word - addr_word */
#define NPU_BASEP9_addr_word(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_BASEP9_addr_word_SHIFT)) & NPU_BASEP9_addr_word_MASK)
/*! @} */

/*! @name BASEP10 - BASEP10 */
/*! @{ */

#define NPU_BASEP10_addr_word_MASK               (0xFFFFFFFFU)
#define NPU_BASEP10_addr_word_SHIFT              (0U)
/*! addr_word - addr_word */
#define NPU_BASEP10_addr_word(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_BASEP10_addr_word_SHIFT)) & NPU_BASEP10_addr_word_MASK)
/*! @} */

/*! @name BASEP11 - BASEP11 */
/*! @{ */

#define NPU_BASEP11_addr_word_MASK               (0xFFFFFFFFU)
#define NPU_BASEP11_addr_word_SHIFT              (0U)
/*! addr_word - addr_word */
#define NPU_BASEP11_addr_word(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_BASEP11_addr_word_SHIFT)) & NPU_BASEP11_addr_word_MASK)
/*! @} */

/*! @name BASEP12 - BASEP12 */
/*! @{ */

#define NPU_BASEP12_addr_word_MASK               (0xFFFFFFFFU)
#define NPU_BASEP12_addr_word_SHIFT              (0U)
/*! addr_word - addr_word */
#define NPU_BASEP12_addr_word(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_BASEP12_addr_word_SHIFT)) & NPU_BASEP12_addr_word_MASK)
/*! @} */

/*! @name BASEP13 - BASEP13 */
/*! @{ */

#define NPU_BASEP13_addr_word_MASK               (0xFFFFFFFFU)
#define NPU_BASEP13_addr_word_SHIFT              (0U)
/*! addr_word - addr_word */
#define NPU_BASEP13_addr_word(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_BASEP13_addr_word_SHIFT)) & NPU_BASEP13_addr_word_MASK)
/*! @} */

/*! @name BASEP14 - BASEP14 */
/*! @{ */

#define NPU_BASEP14_addr_word_MASK               (0xFFFFFFFFU)
#define NPU_BASEP14_addr_word_SHIFT              (0U)
/*! addr_word - addr_word */
#define NPU_BASEP14_addr_word(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_BASEP14_addr_word_SHIFT)) & NPU_BASEP14_addr_word_MASK)
/*! @} */

/*! @name BASEP15 - BASEP15 */
/*! @{ */

#define NPU_BASEP15_addr_word_MASK               (0xFFFFFFFFU)
#define NPU_BASEP15_addr_word_SHIFT              (0U)
/*! addr_word - addr_word */
#define NPU_BASEP15_addr_word(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_BASEP15_addr_word_SHIFT)) & NPU_BASEP15_addr_word_MASK)
/*! @} */

/*! @name PMCR - PMCR */
/*! @{ */

#define NPU_PMCR_cnt_en_MASK                     (0x1U)
#define NPU_PMCR_cnt_en_SHIFT                    (0U)
/*! cnt_en - cnt_en */
#define NPU_PMCR_cnt_en(x)                       (((uint32_t)(((uint32_t)(x)) << NPU_PMCR_cnt_en_SHIFT)) & NPU_PMCR_cnt_en_MASK)

#define NPU_PMCR_event_cnt_rst_MASK              (0x2U)
#define NPU_PMCR_event_cnt_rst_SHIFT             (1U)
/*! event_cnt_rst - event_cnt_rst */
#define NPU_PMCR_event_cnt_rst(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMCR_event_cnt_rst_SHIFT)) & NPU_PMCR_event_cnt_rst_MASK)

#define NPU_PMCR_cycle_cnt_rst_MASK              (0x4U)
#define NPU_PMCR_cycle_cnt_rst_SHIFT             (2U)
/*! cycle_cnt_rst - cycle_cnt_rst */
#define NPU_PMCR_cycle_cnt_rst(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMCR_cycle_cnt_rst_SHIFT)) & NPU_PMCR_cycle_cnt_rst_MASK)

#define NPU_PMCR_mask_en_MASK                    (0x8U)
#define NPU_PMCR_mask_en_SHIFT                   (3U)
/*! mask_en - mask_en */
#define NPU_PMCR_mask_en(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_PMCR_mask_en_SHIFT)) & NPU_PMCR_mask_en_MASK)

#define NPU_PMCR_RES0_MASK                       (0x7F0U)
#define NPU_PMCR_RES0_SHIFT                      (4U)
/*! RES0 - Reserved */
#define NPU_PMCR_RES0(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PMCR_RES0_SHIFT)) & NPU_PMCR_RES0_MASK)

#define NPU_PMCR_num_event_cnt_MASK              (0xF800U)
#define NPU_PMCR_num_event_cnt_SHIFT             (11U)
/*! num_event_cnt - num_event_cnt */
#define NPU_PMCR_num_event_cnt(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMCR_num_event_cnt_SHIFT)) & NPU_PMCR_num_event_cnt_MASK)

#define NPU_PMCR_RES1_MASK                       (0xFFFF0000U)
#define NPU_PMCR_RES1_SHIFT                      (16U)
/*! RES1 - Reserved */
#define NPU_PMCR_RES1(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PMCR_RES1_SHIFT)) & NPU_PMCR_RES1_MASK)
/*! @} */

/*! @name PMCNTENSET - PMCNTENSET */
/*! @{ */

#define NPU_PMCNTENSET_EVENT_CNT_0_MASK          (0x1U)
#define NPU_PMCNTENSET_EVENT_CNT_0_SHIFT         (0U)
/*! EVENT_CNT_0 - EVENT_CNT_0 */
#define NPU_PMCNTENSET_EVENT_CNT_0(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENSET_EVENT_CNT_0_SHIFT)) & NPU_PMCNTENSET_EVENT_CNT_0_MASK)

#define NPU_PMCNTENSET_EVENT_CNT_1_MASK          (0x2U)
#define NPU_PMCNTENSET_EVENT_CNT_1_SHIFT         (1U)
/*! EVENT_CNT_1 - EVENT_CNT_1 */
#define NPU_PMCNTENSET_EVENT_CNT_1(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENSET_EVENT_CNT_1_SHIFT)) & NPU_PMCNTENSET_EVENT_CNT_1_MASK)

#define NPU_PMCNTENSET_EVENT_CNT_2_MASK          (0x4U)
#define NPU_PMCNTENSET_EVENT_CNT_2_SHIFT         (2U)
/*! EVENT_CNT_2 - EVENT_CNT_2 */
#define NPU_PMCNTENSET_EVENT_CNT_2(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENSET_EVENT_CNT_2_SHIFT)) & NPU_PMCNTENSET_EVENT_CNT_2_MASK)

#define NPU_PMCNTENSET_EVENT_CNT_3_MASK          (0x8U)
#define NPU_PMCNTENSET_EVENT_CNT_3_SHIFT         (3U)
/*! EVENT_CNT_3 - EVENT_CNT_3 */
#define NPU_PMCNTENSET_EVENT_CNT_3(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENSET_EVENT_CNT_3_SHIFT)) & NPU_PMCNTENSET_EVENT_CNT_3_MASK)

#define NPU_PMCNTENSET_RES0_MASK                 (0x7FFFFFF0U)
#define NPU_PMCNTENSET_RES0_SHIFT                (4U)
/*! RES0 - Reserved */
#define NPU_PMCNTENSET_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENSET_RES0_SHIFT)) & NPU_PMCNTENSET_RES0_MASK)

#define NPU_PMCNTENSET_CYCLE_CNT_MASK            (0x80000000U)
#define NPU_PMCNTENSET_CYCLE_CNT_SHIFT           (31U)
/*! CYCLE_CNT - CYCLE_CNT */
#define NPU_PMCNTENSET_CYCLE_CNT(x)              (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENSET_CYCLE_CNT_SHIFT)) & NPU_PMCNTENSET_CYCLE_CNT_MASK)
/*! @} */

/*! @name PMCNTENCLR - PMCNTENCLR */
/*! @{ */

#define NPU_PMCNTENCLR_EVENT_CNT_0_MASK          (0x1U)
#define NPU_PMCNTENCLR_EVENT_CNT_0_SHIFT         (0U)
/*! EVENT_CNT_0 - EVENT_CNT_0 */
#define NPU_PMCNTENCLR_EVENT_CNT_0(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENCLR_EVENT_CNT_0_SHIFT)) & NPU_PMCNTENCLR_EVENT_CNT_0_MASK)

#define NPU_PMCNTENCLR_EVENT_CNT_1_MASK          (0x2U)
#define NPU_PMCNTENCLR_EVENT_CNT_1_SHIFT         (1U)
/*! EVENT_CNT_1 - EVENT_CNT_1 */
#define NPU_PMCNTENCLR_EVENT_CNT_1(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENCLR_EVENT_CNT_1_SHIFT)) & NPU_PMCNTENCLR_EVENT_CNT_1_MASK)

#define NPU_PMCNTENCLR_EVENT_CNT_2_MASK          (0x4U)
#define NPU_PMCNTENCLR_EVENT_CNT_2_SHIFT         (2U)
/*! EVENT_CNT_2 - EVENT_CNT_2 */
#define NPU_PMCNTENCLR_EVENT_CNT_2(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENCLR_EVENT_CNT_2_SHIFT)) & NPU_PMCNTENCLR_EVENT_CNT_2_MASK)

#define NPU_PMCNTENCLR_EVENT_CNT_3_MASK          (0x8U)
#define NPU_PMCNTENCLR_EVENT_CNT_3_SHIFT         (3U)
/*! EVENT_CNT_3 - EVENT_CNT_3 */
#define NPU_PMCNTENCLR_EVENT_CNT_3(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENCLR_EVENT_CNT_3_SHIFT)) & NPU_PMCNTENCLR_EVENT_CNT_3_MASK)

#define NPU_PMCNTENCLR_RES0_MASK                 (0x7FFFFFF0U)
#define NPU_PMCNTENCLR_RES0_SHIFT                (4U)
/*! RES0 - Reserved */
#define NPU_PMCNTENCLR_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENCLR_RES0_SHIFT)) & NPU_PMCNTENCLR_RES0_MASK)

#define NPU_PMCNTENCLR_CYCLE_CNT_MASK            (0x80000000U)
#define NPU_PMCNTENCLR_CYCLE_CNT_SHIFT           (31U)
/*! CYCLE_CNT - CYCLE_CNT */
#define NPU_PMCNTENCLR_CYCLE_CNT(x)              (((uint32_t)(((uint32_t)(x)) << NPU_PMCNTENCLR_CYCLE_CNT_SHIFT)) & NPU_PMCNTENCLR_CYCLE_CNT_MASK)
/*! @} */

/*! @name PMOVSSET - PMOVSSET */
/*! @{ */

#define NPU_PMOVSSET_EVENT_CNT_0_OVF_MASK        (0x1U)
#define NPU_PMOVSSET_EVENT_CNT_0_OVF_SHIFT       (0U)
/*! EVENT_CNT_0_OVF - EVENT_CNT_0_OVF */
#define NPU_PMOVSSET_EVENT_CNT_0_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSSET_EVENT_CNT_0_OVF_SHIFT)) & NPU_PMOVSSET_EVENT_CNT_0_OVF_MASK)

#define NPU_PMOVSSET_EVENT_CNT_1_OVF_MASK        (0x2U)
#define NPU_PMOVSSET_EVENT_CNT_1_OVF_SHIFT       (1U)
/*! EVENT_CNT_1_OVF - EVENT_CNT_1_OVF */
#define NPU_PMOVSSET_EVENT_CNT_1_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSSET_EVENT_CNT_1_OVF_SHIFT)) & NPU_PMOVSSET_EVENT_CNT_1_OVF_MASK)

#define NPU_PMOVSSET_EVENT_CNT_2_OVF_MASK        (0x4U)
#define NPU_PMOVSSET_EVENT_CNT_2_OVF_SHIFT       (2U)
/*! EVENT_CNT_2_OVF - EVENT_CNT_2_OVF */
#define NPU_PMOVSSET_EVENT_CNT_2_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSSET_EVENT_CNT_2_OVF_SHIFT)) & NPU_PMOVSSET_EVENT_CNT_2_OVF_MASK)

#define NPU_PMOVSSET_EVENT_CNT_3_OVF_MASK        (0x8U)
#define NPU_PMOVSSET_EVENT_CNT_3_OVF_SHIFT       (3U)
/*! EVENT_CNT_3_OVF - EVENT_CNT_3_OVF */
#define NPU_PMOVSSET_EVENT_CNT_3_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSSET_EVENT_CNT_3_OVF_SHIFT)) & NPU_PMOVSSET_EVENT_CNT_3_OVF_MASK)

#define NPU_PMOVSSET_RES0_MASK                   (0x7FFFFFF0U)
#define NPU_PMOVSSET_RES0_SHIFT                  (4U)
/*! RES0 - Reserved */
#define NPU_PMOVSSET_RES0(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSSET_RES0_SHIFT)) & NPU_PMOVSSET_RES0_MASK)

#define NPU_PMOVSSET_CYCLE_CNT_OVF_MASK          (0x80000000U)
#define NPU_PMOVSSET_CYCLE_CNT_OVF_SHIFT         (31U)
/*! CYCLE_CNT_OVF - CYCLE_CNT_OVF */
#define NPU_PMOVSSET_CYCLE_CNT_OVF(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSSET_CYCLE_CNT_OVF_SHIFT)) & NPU_PMOVSSET_CYCLE_CNT_OVF_MASK)
/*! @} */

/*! @name PMOVSCLR - PMOVSCLR */
/*! @{ */

#define NPU_PMOVSCLR_EVENT_CNT_0_OVF_MASK        (0x1U)
#define NPU_PMOVSCLR_EVENT_CNT_0_OVF_SHIFT       (0U)
/*! EVENT_CNT_0_OVF - EVENT_CNT_0_OVF */
#define NPU_PMOVSCLR_EVENT_CNT_0_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSCLR_EVENT_CNT_0_OVF_SHIFT)) & NPU_PMOVSCLR_EVENT_CNT_0_OVF_MASK)

#define NPU_PMOVSCLR_EVENT_CNT_1_OVF_MASK        (0x2U)
#define NPU_PMOVSCLR_EVENT_CNT_1_OVF_SHIFT       (1U)
/*! EVENT_CNT_1_OVF - EVENT_CNT_1_OVF */
#define NPU_PMOVSCLR_EVENT_CNT_1_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSCLR_EVENT_CNT_1_OVF_SHIFT)) & NPU_PMOVSCLR_EVENT_CNT_1_OVF_MASK)

#define NPU_PMOVSCLR_EVENT_CNT_2_OVF_MASK        (0x4U)
#define NPU_PMOVSCLR_EVENT_CNT_2_OVF_SHIFT       (2U)
/*! EVENT_CNT_2_OVF - EVENT_CNT_2_OVF */
#define NPU_PMOVSCLR_EVENT_CNT_2_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSCLR_EVENT_CNT_2_OVF_SHIFT)) & NPU_PMOVSCLR_EVENT_CNT_2_OVF_MASK)

#define NPU_PMOVSCLR_EVENT_CNT_3_OVF_MASK        (0x8U)
#define NPU_PMOVSCLR_EVENT_CNT_3_OVF_SHIFT       (3U)
/*! EVENT_CNT_3_OVF - EVENT_CNT_3_OVF */
#define NPU_PMOVSCLR_EVENT_CNT_3_OVF(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSCLR_EVENT_CNT_3_OVF_SHIFT)) & NPU_PMOVSCLR_EVENT_CNT_3_OVF_MASK)

#define NPU_PMOVSCLR_RES0_MASK                   (0x7FFFFFF0U)
#define NPU_PMOVSCLR_RES0_SHIFT                  (4U)
/*! RES0 - Reserved */
#define NPU_PMOVSCLR_RES0(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSCLR_RES0_SHIFT)) & NPU_PMOVSCLR_RES0_MASK)

#define NPU_PMOVSCLR_CYCLE_CNT_OVF_MASK          (0x80000000U)
#define NPU_PMOVSCLR_CYCLE_CNT_OVF_SHIFT         (31U)
/*! CYCLE_CNT_OVF - CYCLE_CNT_OVF */
#define NPU_PMOVSCLR_CYCLE_CNT_OVF(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMOVSCLR_CYCLE_CNT_OVF_SHIFT)) & NPU_PMOVSCLR_CYCLE_CNT_OVF_MASK)
/*! @} */

/*! @name PMINTSET - PMINTSET */
/*! @{ */

#define NPU_PMINTSET_EVENT_CNT_0_INT_MASK        (0x1U)
#define NPU_PMINTSET_EVENT_CNT_0_INT_SHIFT       (0U)
/*! EVENT_CNT_0_INT - EVENT_CNT_0_INT */
#define NPU_PMINTSET_EVENT_CNT_0_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTSET_EVENT_CNT_0_INT_SHIFT)) & NPU_PMINTSET_EVENT_CNT_0_INT_MASK)

#define NPU_PMINTSET_EVENT_CNT_1_INT_MASK        (0x2U)
#define NPU_PMINTSET_EVENT_CNT_1_INT_SHIFT       (1U)
/*! EVENT_CNT_1_INT - EVENT_CNT_1_INT */
#define NPU_PMINTSET_EVENT_CNT_1_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTSET_EVENT_CNT_1_INT_SHIFT)) & NPU_PMINTSET_EVENT_CNT_1_INT_MASK)

#define NPU_PMINTSET_EVENT_CNT_2_INT_MASK        (0x4U)
#define NPU_PMINTSET_EVENT_CNT_2_INT_SHIFT       (2U)
/*! EVENT_CNT_2_INT - EVENT_CNT_2_INT */
#define NPU_PMINTSET_EVENT_CNT_2_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTSET_EVENT_CNT_2_INT_SHIFT)) & NPU_PMINTSET_EVENT_CNT_2_INT_MASK)

#define NPU_PMINTSET_EVENT_CNT_3_INT_MASK        (0x8U)
#define NPU_PMINTSET_EVENT_CNT_3_INT_SHIFT       (3U)
/*! EVENT_CNT_3_INT - EVENT_CNT_3_INT */
#define NPU_PMINTSET_EVENT_CNT_3_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTSET_EVENT_CNT_3_INT_SHIFT)) & NPU_PMINTSET_EVENT_CNT_3_INT_MASK)

#define NPU_PMINTSET_RES0_MASK                   (0x7FFFFFF0U)
#define NPU_PMINTSET_RES0_SHIFT                  (4U)
/*! RES0 - Reserved */
#define NPU_PMINTSET_RES0(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_PMINTSET_RES0_SHIFT)) & NPU_PMINTSET_RES0_MASK)

#define NPU_PMINTSET_CYCLE_CNT_INT_MASK          (0x80000000U)
#define NPU_PMINTSET_CYCLE_CNT_INT_SHIFT         (31U)
/*! CYCLE_CNT_INT - CYCLE_CNT_INT */
#define NPU_PMINTSET_CYCLE_CNT_INT(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMINTSET_CYCLE_CNT_INT_SHIFT)) & NPU_PMINTSET_CYCLE_CNT_INT_MASK)
/*! @} */

/*! @name PMINTCLR - PMINTCLR */
/*! @{ */

#define NPU_PMINTCLR_EVENT_CNT_0_INT_MASK        (0x1U)
#define NPU_PMINTCLR_EVENT_CNT_0_INT_SHIFT       (0U)
/*! EVENT_CNT_0_INT - EVENT_CNT_0_INT */
#define NPU_PMINTCLR_EVENT_CNT_0_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTCLR_EVENT_CNT_0_INT_SHIFT)) & NPU_PMINTCLR_EVENT_CNT_0_INT_MASK)

#define NPU_PMINTCLR_EVENT_CNT_1_INT_MASK        (0x2U)
#define NPU_PMINTCLR_EVENT_CNT_1_INT_SHIFT       (1U)
/*! EVENT_CNT_1_INT - EVENT_CNT_1_INT */
#define NPU_PMINTCLR_EVENT_CNT_1_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTCLR_EVENT_CNT_1_INT_SHIFT)) & NPU_PMINTCLR_EVENT_CNT_1_INT_MASK)

#define NPU_PMINTCLR_EVENT_CNT_2_INT_MASK        (0x4U)
#define NPU_PMINTCLR_EVENT_CNT_2_INT_SHIFT       (2U)
/*! EVENT_CNT_2_INT - EVENT_CNT_2_INT */
#define NPU_PMINTCLR_EVENT_CNT_2_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTCLR_EVENT_CNT_2_INT_SHIFT)) & NPU_PMINTCLR_EVENT_CNT_2_INT_MASK)

#define NPU_PMINTCLR_EVENT_CNT_3_INT_MASK        (0x8U)
#define NPU_PMINTCLR_EVENT_CNT_3_INT_SHIFT       (3U)
/*! EVENT_CNT_3_INT - EVENT_CNT_3_INT */
#define NPU_PMINTCLR_EVENT_CNT_3_INT(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMINTCLR_EVENT_CNT_3_INT_SHIFT)) & NPU_PMINTCLR_EVENT_CNT_3_INT_MASK)

#define NPU_PMINTCLR_RES0_MASK                   (0x7FFFFFF0U)
#define NPU_PMINTCLR_RES0_SHIFT                  (4U)
/*! RES0 - Reserved */
#define NPU_PMINTCLR_RES0(x)                     (((uint32_t)(((uint32_t)(x)) << NPU_PMINTCLR_RES0_SHIFT)) & NPU_PMINTCLR_RES0_MASK)

#define NPU_PMINTCLR_CYCLE_CNT_INT_MASK          (0x80000000U)
#define NPU_PMINTCLR_CYCLE_CNT_INT_SHIFT         (31U)
/*! CYCLE_CNT_INT - CYCLE_CNT_INT */
#define NPU_PMINTCLR_CYCLE_CNT_INT(x)            (((uint32_t)(((uint32_t)(x)) << NPU_PMINTCLR_CYCLE_CNT_INT_SHIFT)) & NPU_PMINTCLR_CYCLE_CNT_INT_MASK)
/*! @} */

/*! @name PMCCNTR_LO - PMCCNTR_LO */
/*! @{ */

#define NPU_PMCCNTR_LO_CYCLE_CNT_LO_MASK         (0xFFFFFFFFU)
#define NPU_PMCCNTR_LO_CYCLE_CNT_LO_SHIFT        (0U)
/*! CYCLE_CNT_LO - CYCLE_CNT_LO */
#define NPU_PMCCNTR_LO_CYCLE_CNT_LO(x)           (((uint32_t)(((uint32_t)(x)) << NPU_PMCCNTR_LO_CYCLE_CNT_LO_SHIFT)) & NPU_PMCCNTR_LO_CYCLE_CNT_LO_MASK)
/*! @} */

/*! @name PMCCNTR_HI - PMCCNTR_HI */
/*! @{ */

#define NPU_PMCCNTR_HI_CYCLE_CNT_HI_MASK         (0xFFFFU)
#define NPU_PMCCNTR_HI_CYCLE_CNT_HI_SHIFT        (0U)
/*! CYCLE_CNT_HI - CYCLE_CNT_HI */
#define NPU_PMCCNTR_HI_CYCLE_CNT_HI(x)           (((uint32_t)(((uint32_t)(x)) << NPU_PMCCNTR_HI_CYCLE_CNT_HI_SHIFT)) & NPU_PMCCNTR_HI_CYCLE_CNT_HI_MASK)

#define NPU_PMCCNTR_HI_RES0_MASK                 (0xFFFF0000U)
#define NPU_PMCCNTR_HI_RES0_SHIFT                (16U)
/*! RES0 - Reserved */
#define NPU_PMCCNTR_HI_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PMCCNTR_HI_RES0_SHIFT)) & NPU_PMCCNTR_HI_RES0_MASK)
/*! @} */

/*! @name PMCAXI_CHAN - PMCAXI_CHAN */
/*! @{ */

#define NPU_PMCAXI_CHAN_CH_SEL_MASK              (0xFU)
#define NPU_PMCAXI_CHAN_CH_SEL_SHIFT             (0U)
/*! CH_SEL - CH_SEL */
#define NPU_PMCAXI_CHAN_CH_SEL(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMCAXI_CHAN_CH_SEL_SHIFT)) & NPU_PMCAXI_CHAN_CH_SEL_MASK)

#define NPU_PMCAXI_CHAN_RES0_MASK                (0xF0U)
#define NPU_PMCAXI_CHAN_RES0_SHIFT               (4U)
/*! RES0 - Reserved */
#define NPU_PMCAXI_CHAN_RES0(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_PMCAXI_CHAN_RES0_SHIFT)) & NPU_PMCAXI_CHAN_RES0_MASK)

#define NPU_PMCAXI_CHAN_AXI_CNT_SEL_MASK         (0x300U)
#define NPU_PMCAXI_CHAN_AXI_CNT_SEL_SHIFT        (8U)
/*! AXI_CNT_SEL - AXI_CNT_SEL */
#define NPU_PMCAXI_CHAN_AXI_CNT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << NPU_PMCAXI_CHAN_AXI_CNT_SEL_SHIFT)) & NPU_PMCAXI_CHAN_AXI_CNT_SEL_MASK)

#define NPU_PMCAXI_CHAN_BW_CH_SEL_EN_MASK        (0x400U)
#define NPU_PMCAXI_CHAN_BW_CH_SEL_EN_SHIFT       (10U)
/*! BW_CH_SEL_EN - BW_CH_SEL_EN */
#define NPU_PMCAXI_CHAN_BW_CH_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << NPU_PMCAXI_CHAN_BW_CH_SEL_EN_SHIFT)) & NPU_PMCAXI_CHAN_BW_CH_SEL_EN_MASK)

#define NPU_PMCAXI_CHAN_RES1_MASK                (0xFFFFF800U)
#define NPU_PMCAXI_CHAN_RES1_SHIFT               (11U)
/*! RES1 - Reserved */
#define NPU_PMCAXI_CHAN_RES1(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_PMCAXI_CHAN_RES1_SHIFT)) & NPU_PMCAXI_CHAN_RES1_MASK)
/*! @} */

/*! @name PMEVCNTR0 - PMEVCNTR0 */
/*! @{ */

#define NPU_PMEVCNTR0_PMEVCNTR0_MASK             (0xFFFFFFFFU)
#define NPU_PMEVCNTR0_PMEVCNTR0_SHIFT            (0U)
/*! PMEVCNTR0 - Performance monitor event 0 count bitfield */
#define NPU_PMEVCNTR0_PMEVCNTR0(x)               (((uint32_t)(((uint32_t)(x)) << NPU_PMEVCNTR0_PMEVCNTR0_SHIFT)) & NPU_PMEVCNTR0_PMEVCNTR0_MASK)
/*! @} */

/*! @name PMEVCNTR1 - PMEVCNTR1 */
/*! @{ */

#define NPU_PMEVCNTR1_PMEVCNTR1_MASK             (0xFFFFFFFFU)
#define NPU_PMEVCNTR1_PMEVCNTR1_SHIFT            (0U)
/*! PMEVCNTR1 - Performance monitor event 1 count bitfield */
#define NPU_PMEVCNTR1_PMEVCNTR1(x)               (((uint32_t)(((uint32_t)(x)) << NPU_PMEVCNTR1_PMEVCNTR1_SHIFT)) & NPU_PMEVCNTR1_PMEVCNTR1_MASK)
/*! @} */

/*! @name PMEVCNTR2 - PMEVCNTR2 */
/*! @{ */

#define NPU_PMEVCNTR2_PMEVCNTR2_MASK             (0xFFFFFFFFU)
#define NPU_PMEVCNTR2_PMEVCNTR2_SHIFT            (0U)
/*! PMEVCNTR2 - Performance monitor event 2 count bitfield */
#define NPU_PMEVCNTR2_PMEVCNTR2(x)               (((uint32_t)(((uint32_t)(x)) << NPU_PMEVCNTR2_PMEVCNTR2_SHIFT)) & NPU_PMEVCNTR2_PMEVCNTR2_MASK)
/*! @} */

/*! @name PMEVCNTR3 - PMEVCNTR3 */
/*! @{ */

#define NPU_PMEVCNTR3_PMEVCNTR3_MASK             (0xFFFFFFFFU)
#define NPU_PMEVCNTR3_PMEVCNTR3_SHIFT            (0U)
/*! PMEVCNTR3 - Performance monitor event 3 count bitfield */
#define NPU_PMEVCNTR3_PMEVCNTR3(x)               (((uint32_t)(((uint32_t)(x)) << NPU_PMEVCNTR3_PMEVCNTR3_SHIFT)) & NPU_PMEVCNTR3_PMEVCNTR3_MASK)
/*! @} */

/*! @name PMEVTYPER0 - PMEVTYPER0 */
/*! @{ */

#define NPU_PMEVTYPER0_EV_TYPE_MASK              (0x3FFU)
#define NPU_PMEVTYPER0_EV_TYPE_SHIFT             (0U)
/*! EV_TYPE - EV_TYPE */
#define NPU_PMEVTYPER0_EV_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER0_EV_TYPE_SHIFT)) & NPU_PMEVTYPER0_EV_TYPE_MASK)

#define NPU_PMEVTYPER0_RES0_MASK                 (0xFFFFFC00U)
#define NPU_PMEVTYPER0_RES0_SHIFT                (10U)
/*! RES0 - Reserved */
#define NPU_PMEVTYPER0_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER0_RES0_SHIFT)) & NPU_PMEVTYPER0_RES0_MASK)
/*! @} */

/*! @name PMEVTYPER1 - PMEVTYPER1 */
/*! @{ */

#define NPU_PMEVTYPER1_EV_TYPE_MASK              (0x3FFU)
#define NPU_PMEVTYPER1_EV_TYPE_SHIFT             (0U)
/*! EV_TYPE - EV_TYPE */
#define NPU_PMEVTYPER1_EV_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER1_EV_TYPE_SHIFT)) & NPU_PMEVTYPER1_EV_TYPE_MASK)

#define NPU_PMEVTYPER1_RES0_MASK                 (0xFFFFFC00U)
#define NPU_PMEVTYPER1_RES0_SHIFT                (10U)
/*! RES0 - Reserved */
#define NPU_PMEVTYPER1_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER1_RES0_SHIFT)) & NPU_PMEVTYPER1_RES0_MASK)
/*! @} */

/*! @name PMEVTYPER2 - PMEVTYPER2 */
/*! @{ */

#define NPU_PMEVTYPER2_EV_TYPE_MASK              (0x3FFU)
#define NPU_PMEVTYPER2_EV_TYPE_SHIFT             (0U)
/*! EV_TYPE - EV_TYPE */
#define NPU_PMEVTYPER2_EV_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER2_EV_TYPE_SHIFT)) & NPU_PMEVTYPER2_EV_TYPE_MASK)

#define NPU_PMEVTYPER2_RES0_MASK                 (0xFFFFFC00U)
#define NPU_PMEVTYPER2_RES0_SHIFT                (10U)
/*! RES0 - Reserved */
#define NPU_PMEVTYPER2_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER2_RES0_SHIFT)) & NPU_PMEVTYPER2_RES0_MASK)
/*! @} */

/*! @name PMEVTYPER3 - PMEVTYPER3 */
/*! @{ */

#define NPU_PMEVTYPER3_EV_TYPE_MASK              (0x3FFU)
#define NPU_PMEVTYPER3_EV_TYPE_SHIFT             (0U)
/*! EV_TYPE - EV_TYPE */
#define NPU_PMEVTYPER3_EV_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER3_EV_TYPE_SHIFT)) & NPU_PMEVTYPER3_EV_TYPE_MASK)

#define NPU_PMEVTYPER3_RES0_MASK                 (0xFFFFFC00U)
#define NPU_PMEVTYPER3_RES0_SHIFT                (10U)
/*! RES0 - Reserved */
#define NPU_PMEVTYPER3_RES0(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_PMEVTYPER3_RES0_SHIFT)) & NPU_PMEVTYPER3_RES0_MASK)
/*! @} */

/*! @name PID4 - PID4 */
/*! @{ */

#define NPU_PID4_PID4_MASK                       (0xFFFFFFFFU)
#define NPU_PID4_PID4_SHIFT                      (0U)
/*! PID4 - PID4 */
#define NPU_PID4_PID4(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID4_PID4_SHIFT)) & NPU_PID4_PID4_MASK)
/*! @} */

/*! @name PID5 - PID5 */
/*! @{ */

#define NPU_PID5_PID5_MASK                       (0xFFFFFFFFU)
#define NPU_PID5_PID5_SHIFT                      (0U)
/*! PID5 - PID5 */
#define NPU_PID5_PID5(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID5_PID5_SHIFT)) & NPU_PID5_PID5_MASK)
/*! @} */

/*! @name PID6 - PID6 */
/*! @{ */

#define NPU_PID6_PID6_MASK                       (0xFFFFFFFFU)
#define NPU_PID6_PID6_SHIFT                      (0U)
/*! PID6 - PID6 */
#define NPU_PID6_PID6(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID6_PID6_SHIFT)) & NPU_PID6_PID6_MASK)
/*! @} */

/*! @name PID7 - PID7 */
/*! @{ */

#define NPU_PID7_PID7_MASK                       (0xFFFFFFFFU)
#define NPU_PID7_PID7_SHIFT                      (0U)
/*! PID7 - PID7 */
#define NPU_PID7_PID7(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID7_PID7_SHIFT)) & NPU_PID7_PID7_MASK)
/*! @} */

/*! @name PID0 - PID0 */
/*! @{ */

#define NPU_PID0_PID0_MASK                       (0xFFFFFFFFU)
#define NPU_PID0_PID0_SHIFT                      (0U)
/*! PID0 - PID0 */
#define NPU_PID0_PID0(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID0_PID0_SHIFT)) & NPU_PID0_PID0_MASK)
/*! @} */

/*! @name PID1 - PID1 */
/*! @{ */

#define NPU_PID1_PID1_MASK                       (0xFFFFFFFFU)
#define NPU_PID1_PID1_SHIFT                      (0U)
/*! PID1 - PID1 */
#define NPU_PID1_PID1(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID1_PID1_SHIFT)) & NPU_PID1_PID1_MASK)
/*! @} */

/*! @name PID2 - PID2 */
/*! @{ */

#define NPU_PID2_PID2_MASK                       (0xFFFFFFFFU)
#define NPU_PID2_PID2_SHIFT                      (0U)
/*! PID2 - PID2 */
#define NPU_PID2_PID2(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID2_PID2_SHIFT)) & NPU_PID2_PID2_MASK)
/*! @} */

/*! @name PID3 - PID3 */
/*! @{ */

#define NPU_PID3_PID3_MASK                       (0xFFFFFFFFU)
#define NPU_PID3_PID3_SHIFT                      (0U)
/*! PID3 - PID3 */
#define NPU_PID3_PID3(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_PID3_PID3_SHIFT)) & NPU_PID3_PID3_MASK)
/*! @} */

/*! @name CID0 - CID0 */
/*! @{ */

#define NPU_CID0_CID0_MASK                       (0xFFFFFFFFU)
#define NPU_CID0_CID0_SHIFT                      (0U)
/*! CID0 - CID0 */
#define NPU_CID0_CID0(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_CID0_CID0_SHIFT)) & NPU_CID0_CID0_MASK)
/*! @} */

/*! @name CID1 - CID1 */
/*! @{ */

#define NPU_CID1_CID1_MASK                       (0xFFFFFFFFU)
#define NPU_CID1_CID1_SHIFT                      (0U)
/*! CID1 - CID1 */
#define NPU_CID1_CID1(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_CID1_CID1_SHIFT)) & NPU_CID1_CID1_MASK)
/*! @} */

/*! @name CID2 - CID2 */
/*! @{ */

#define NPU_CID2_CID2_MASK                       (0xFFFFFFFFU)
#define NPU_CID2_CID2_SHIFT                      (0U)
/*! CID2 - CID2 */
#define NPU_CID2_CID2(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_CID2_CID2_SHIFT)) & NPU_CID2_CID2_MASK)
/*! @} */

/*! @name CID3 - CID3 */
/*! @{ */

#define NPU_CID3_CID3_MASK                       (0xFFFFFFFFU)
#define NPU_CID3_CID3_SHIFT                      (0U)
/*! CID3 - CID3 */
#define NPU_CID3_CID3(x)                         (((uint32_t)(((uint32_t)(x)) << NPU_CID3_CID3_SHIFT)) & NPU_CID3_CID3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NPU_Register_Masks */


/*!
 * @}
 */ /* end of group NPU_Peripheral_Access_Layer */


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


#endif  /* PERI_NPU_H_ */
