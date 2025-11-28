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
**         CMSIS Peripheral Access Layer for DDRMIX_BLK_CTRL
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
 * @file PERI_DDRMIX_BLK_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DDRMIX_BLK_CTRL
 *
 * CMSIS Peripheral Access Layer for DDRMIX_BLK_CTRL
 */

#if !defined(PERI_DDRMIX_BLK_CTRL_H_)
#define PERI_DDRMIX_BLK_CTRL_H_                  /**< Symbol preventing repeated inclusion */

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
   -- DDRMIX_BLK_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRMIX_BLK_CTRL_Peripheral_Access_Layer DDRMIX_BLK_CTRL Peripheral Access Layer
 * @{
 */

/** DDRMIX_BLK_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t HWFFC_CTRL;                        /**< DDRPHY DfiClk, DflCtlClk HWFFC Control, offset: 0x0 */
  __IO uint32_t CA55_SEL_CTRL;                     /**< CA55 Arm PLL Observe Select, offset: 0x4 */
  __IO uint32_t VREF_PSW_CTRL;                     /**< DRAM_VREF power switch, offset: 0x8 */
  __IO uint32_t DDRC_STOP_CTRL;                    /**< DDR Controller ipg_stop SW control, offset: 0xC */
  __IO uint32_t AUTO_CG_CTRL;                      /**< DDR Controller automatic clock gating, offset: 0x10 */
} DDRMIX_BLK_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- DDRMIX_BLK_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRMIX_BLK_CTRL_Register_Masks DDRMIX_BLK_CTRL Register Masks
 * @{
 */

/*! @name HWFFC_CTRL - DDRPHY DfiClk, DflCtlClk HWFFC Control */
/*! @{ */

#define DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_EN_MASK (0x1U)
#define DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_EN_SHIFT (0U)
/*! HWFFC_EN - DDRPHY DfiClk, DfiCtlClk HWFFC Enable
 *  0b0..DDRPHY HWFFC is disabled
 *  0b1..DDRPHY HWFFC is enabled
 */
#define DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_EN(x)   (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_EN_SHIFT)) & DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_EN_MASK)

#define DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_SEL_MASK (0x2U)
#define DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_SEL_SHIFT (1U)
/*! HWFFC_SEL - DDRPHY DfiClk, DfiCtlClk HWFFC Select
 *  0b0..Normal clock is selected
 *  0b1..Div2 frequency clock is selected
 */
#define DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_SEL(x)  (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_SEL_SHIFT)) & DDRMIX_BLK_CTRL_HWFFC_CTRL_HWFFC_SEL_MASK)
/*! @} */

/*! @name CA55_SEL_CTRL - CA55 Arm PLL Observe Select */
/*! @{ */

#define DDRMIX_BLK_CTRL_CA55_SEL_CTRL_CA55_SEL_MASK (0x1U)
#define DDRMIX_BLK_CTRL_CA55_SEL_CTRL_CA55_SEL_SHIFT (0U)
/*! CA55_SEL - CA55 Arm PLL select into DDRPHY
 *  0b0..Normal DfiClk from DRAM PLL is selected
 *  0b1..CA55mix Arm PLL is selected
 */
#define DDRMIX_BLK_CTRL_CA55_SEL_CTRL_CA55_SEL(x) (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_CA55_SEL_CTRL_CA55_SEL_SHIFT)) & DDRMIX_BLK_CTRL_CA55_SEL_CTRL_CA55_SEL_MASK)
/*! @} */

/*! @name VREF_PSW_CTRL - DRAM_VREF power switch */
/*! @{ */

#define DDRMIX_BLK_CTRL_VREF_PSW_CTRL_VREF_PSW_MASK (0x1U)
#define DDRMIX_BLK_CTRL_VREF_PSW_CTRL_VREF_PSW_SHIFT (0U)
/*! VREF_PSW - DDRPHY DRAM_VREF Power Switch
 *  0b0..Power switch is closed to prevent leakage
 *  0b1..Power switch is opened and is set together with DDRPHY[VrefInGlobal]
 */
#define DDRMIX_BLK_CTRL_VREF_PSW_CTRL_VREF_PSW(x) (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_VREF_PSW_CTRL_VREF_PSW_SHIFT)) & DDRMIX_BLK_CTRL_VREF_PSW_CTRL_VREF_PSW_MASK)
/*! @} */

/*! @name DDRC_STOP_CTRL - DDR Controller ipg_stop SW control */
/*! @{ */

#define DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_MASK (0x1U)
#define DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_SHIFT (0U)
/*! DDRC_STOP - DDR Controller ipg_stop
 *  0b0..Clear DDR Controller ipg_stop signal
 *  0b1..Set DDR Controller ipg_stop signal
 */
#define DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP(x) (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_SHIFT)) & DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_MASK)

#define DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK (0x2U)
#define DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT (1U)
/*! DDRC_STOP_ACK - DDR Controller ipg_stop_ack
 *  0b0..DDR Controller ipg_stop_ack is a 0
 *  0b1..DDR Controller ipg_stop_ack is a 1
 */
#define DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT)) & DDRMIX_BLK_CTRL_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK)
/*! @} */

/*! @name AUTO_CG_CTRL - DDR Controller automatic clock gating */
/*! @{ */

#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK (0xFFFFU)
#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT (0U)
/*! SSI_IDLE_STRAP - SSI Idle Strap */
#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_SSI_IDLE_STRAP(x) (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT)) & DDRMIX_BLK_CTRL_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK)

#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_AUTO_CG_ENA_MASK (0x10000U)
#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT (16U)
/*! AUTO_CG_ENA - DDR Controller automatic clock gating enable
 *  0b0..DDR Controller automatic clock gating is disabled
 *  0b1..DDR Controller automatic clock gating is enabled
 */
#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_AUTO_CG_ENA(x) (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT)) & DDRMIX_BLK_CTRL_AUTO_CG_CTRL_AUTO_CG_ENA_MASK)

#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK (0x20000U)
#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT (17U)
/*! HWFFC_ACG_FORCE_B - DDR Controller hwffc and auto CG send ipg_stop allow
 *  0b0..DDR Controller hwffc and auto CG cannot send ipg_stop
 *  0b1..DDR Controller hwffc and auto CG can send ipg_stop
 */
#define DDRMIX_BLK_CTRL_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B(x) (((uint32_t)(((uint32_t)(x)) << DDRMIX_BLK_CTRL_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT)) & DDRMIX_BLK_CTRL_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DDRMIX_BLK_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group DDRMIX_BLK_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_DDRMIX_BLK_CTRL_H_ */
