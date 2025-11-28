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
**         CMSIS Peripheral Access Layer for SRC_MEM_SLICE
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
 * @file PERI_SRC_MEM_SLICE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SRC_MEM_SLICE
 *
 * CMSIS Peripheral Access Layer for SRC_MEM_SLICE
 */

#if !defined(PERI_SRC_MEM_SLICE_H_)
#define PERI_SRC_MEM_SLICE_H_                    /**< Symbol preventing repeated inclusion */

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
   -- SRC_MEM_SLICE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MEM_SLICE_Peripheral_Access_Layer SRC_MEM_SLICE Peripheral Access Layer
 * @{
 */

/** SRC_MEM_SLICE - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t MEM_CTRL;                          /**< MEM Low Power Control, offset: 0x4 */
  __IO uint32_t MEMLP_CTRL_0;                      /**< MEM Low Power Control_0, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MEMLP_CTRL_1;                      /**< MEM Low Power Control_1, offset: 0x10 */
  __IO uint32_t MEMLP_CTRL_2;                      /**< MEM Low Power Control_2, offset: 0x14 */
  __I  uint32_t MEM_STAT;                          /**< MEM Status, offset: 0x18 */
} SRC_MEM_SLICE_Type;

/* ----------------------------------------------------------------------------
   -- SRC_MEM_SLICE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MEM_SLICE_Register_Masks SRC_MEM_SLICE Register Masks
 * @{
 */

/*! @name MEM_CTRL - MEM Low Power Control */
/*! @{ */

#define SRC_MEM_SLICE_MEM_CTRL_SW_MEM_CTRL_MASK  (0x1U)
#define SRC_MEM_SLICE_MEM_CTRL_SW_MEM_CTRL_SHIFT (0U)
/*! SW_MEM_CTRL - Software control MEM low power
 *  0b0..software control MEM to exit low power
 *  0b1..software control MEM to enter low power
 */
#define SRC_MEM_SLICE_MEM_CTRL_SW_MEM_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_CTRL_SW_MEM_CTRL_SHIFT)) & SRC_MEM_SLICE_MEM_CTRL_SW_MEM_CTRL_MASK)

#define SRC_MEM_SLICE_MEM_CTRL_MEM_LP_MODE_MASK  (0x2U)
#define SRC_MEM_SLICE_MEM_CTRL_MEM_LP_MODE_SHIFT (1U)
/*! MEM_LP_MODE - MEM low power mode. Locked by LOCK_CFG field.
 *  0b0..Power down mode
 *  0b1..Retention mode
 */
#define SRC_MEM_SLICE_MEM_CTRL_MEM_LP_MODE(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_CTRL_MEM_LP_MODE_SHIFT)) & SRC_MEM_SLICE_MEM_CTRL_MEM_LP_MODE_MASK)

#define SRC_MEM_SLICE_MEM_CTRL_MEM_LP_EN_MASK    (0x4U)
#define SRC_MEM_SLICE_MEM_CTRL_MEM_LP_EN_SHIFT   (2U)
/*! MEM_LP_EN - Enable MEM low power control. Locked by LOCK_CFG field */
#define SRC_MEM_SLICE_MEM_CTRL_MEM_LP_EN(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_CTRL_MEM_LP_EN_SHIFT)) & SRC_MEM_SLICE_MEM_CTRL_MEM_LP_EN_MASK)

#define SRC_MEM_SLICE_MEM_CTRL_MEM_LF_CNT_CFG_MASK (0xFF00U)
#define SRC_MEM_SLICE_MEM_CTRL_MEM_LF_CNT_CFG_SHIFT (8U)
/*! MEM_LF_CNT_CFG - MEM power up counter */
#define SRC_MEM_SLICE_MEM_CTRL_MEM_LF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_CTRL_MEM_LF_CNT_CFG_SHIFT)) & SRC_MEM_SLICE_MEM_CTRL_MEM_LF_CNT_CFG_MASK)

#define SRC_MEM_SLICE_MEM_CTRL_MEM_HF_CNT_CFG_MASK (0xFF0000U)
#define SRC_MEM_SLICE_MEM_CTRL_MEM_HF_CNT_CFG_SHIFT (16U)
/*! MEM_HF_CNT_CFG - MEM power up counter */
#define SRC_MEM_SLICE_MEM_CTRL_MEM_HF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_CTRL_MEM_HF_CNT_CFG_SHIFT)) & SRC_MEM_SLICE_MEM_CTRL_MEM_HF_CNT_CFG_MASK)

#define SRC_MEM_SLICE_MEM_CTRL_LOCK_CFG_MASK     (0x1000000U)
#define SRC_MEM_SLICE_MEM_CTRL_LOCK_CFG_SHIFT    (24U)
/*! LOCK_CFG - Configuration lock
 *  0b0..Not locked.
 *  0b1..Locked.
 */
#define SRC_MEM_SLICE_MEM_CTRL_LOCK_CFG(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_CTRL_LOCK_CFG_SHIFT)) & SRC_MEM_SLICE_MEM_CTRL_LOCK_CFG_MASK)
/*! @} */

/*! @name MEMLP_CTRL_0 - MEM Low Power Control_0 */
/*! @{ */

#define SRC_MEM_SLICE_MEMLP_CTRL_0_MEMLP_ENT_CNT_MASK (0xFFFFFFFFU)
#define SRC_MEM_SLICE_MEMLP_CTRL_0_MEMLP_ENT_CNT_SHIFT (0U)
/*! MEMLP_ENT_CNT - Delay counter to start entering to memory low power mode. Locked by LOCK_CFG field */
#define SRC_MEM_SLICE_MEMLP_CTRL_0_MEMLP_ENT_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEMLP_CTRL_0_MEMLP_ENT_CNT_SHIFT)) & SRC_MEM_SLICE_MEMLP_CTRL_0_MEMLP_ENT_CNT_MASK)
/*! @} */

/*! @name MEMLP_CTRL_1 - MEM Low Power Control_1 */
/*! @{ */

#define SRC_MEM_SLICE_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_MASK (0xFFFFFFFFU)
#define SRC_MEM_SLICE_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_SHIFT (0U)
/*! MEMLP_RET_PGEN_CNT - Delay counter to interval for retn to pgen. Locked by LOCK_CFG field */
#define SRC_MEM_SLICE_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_SHIFT)) & SRC_MEM_SLICE_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_MASK)
/*! @} */

/*! @name MEMLP_CTRL_2 - MEM Low Power Control_2 */
/*! @{ */

#define SRC_MEM_SLICE_MEMLP_CTRL_2_MEMLP_EXT_CNT_MASK (0xFFFFFFFFU)
#define SRC_MEM_SLICE_MEMLP_CTRL_2_MEMLP_EXT_CNT_SHIFT (0U)
/*! MEMLP_EXT_CNT - Delay counter to start exiting from memory low power mode. Locked by LOCK_CFG field */
#define SRC_MEM_SLICE_MEMLP_CTRL_2_MEMLP_EXT_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEMLP_CTRL_2_MEMLP_EXT_CNT_SHIFT)) & SRC_MEM_SLICE_MEMLP_CTRL_2_MEMLP_EXT_CNT_MASK)
/*! @} */

/*! @name MEM_STAT - MEM Status */
/*! @{ */

#define SRC_MEM_SLICE_MEM_STAT_MEM_FSM_STAT_MASK (0xFU)
#define SRC_MEM_SLICE_MEM_STAT_MEM_FSM_STAT_SHIFT (0U)
/*! MEM_FSM_STAT - MEM FSM status */
#define SRC_MEM_SLICE_MEM_STAT_MEM_FSM_STAT(x)   (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_STAT_MEM_FSM_STAT_SHIFT)) & SRC_MEM_SLICE_MEM_STAT_MEM_FSM_STAT_MASK)

#define SRC_MEM_SLICE_MEM_STAT_RET2N_STAT_MASK   (0x10U)
#define SRC_MEM_SLICE_MEM_STAT_RET2N_STAT_SHIFT  (4U)
/*! RET2N_STAT - RET2N status */
#define SRC_MEM_SLICE_MEM_STAT_RET2N_STAT(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_STAT_RET2N_STAT_SHIFT)) & SRC_MEM_SLICE_MEM_STAT_RET2N_STAT_MASK)

#define SRC_MEM_SLICE_MEM_STAT_RET1N_STAT_MASK   (0x20U)
#define SRC_MEM_SLICE_MEM_STAT_RET1N_STAT_SHIFT  (5U)
/*! RET1N_STAT - RET1N status */
#define SRC_MEM_SLICE_MEM_STAT_RET1N_STAT(x)     (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_STAT_RET1N_STAT_SHIFT)) & SRC_MEM_SLICE_MEM_STAT_RET1N_STAT_MASK)

#define SRC_MEM_SLICE_MEM_STAT_PGEN_STAT_MASK    (0x40U)
#define SRC_MEM_SLICE_MEM_STAT_PGEN_STAT_SHIFT   (6U)
/*! PGEN_STAT - PGEN status */
#define SRC_MEM_SLICE_MEM_STAT_PGEN_STAT(x)      (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_STAT_PGEN_STAT_SHIFT)) & SRC_MEM_SLICE_MEM_STAT_PGEN_STAT_MASK)

#define SRC_MEM_SLICE_MEM_STAT_MEM_STAT_MASK     (0x100U)
#define SRC_MEM_SLICE_MEM_STAT_MEM_STAT_SHIFT    (8U)
/*! MEM_STAT - MEM status
 *  0b0..MEM exit low power
 *  0b1..MEM enter low power - rentention1 mode or power down mode
 */
#define SRC_MEM_SLICE_MEM_STAT_MEM_STAT(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MEM_SLICE_MEM_STAT_MEM_STAT_SHIFT)) & SRC_MEM_SLICE_MEM_STAT_MEM_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_MEM_SLICE_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_MEM_SLICE_Peripheral_Access_Layer */


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


#endif  /* PERI_SRC_MEM_SLICE_H_ */
