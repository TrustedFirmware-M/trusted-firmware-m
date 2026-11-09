/*
** ###################################################################
**     Processors:          KW43B43ZC2MFT
**                          KW43B43ZC3MFT
**                          KW43B43ZC6MFT
**                          KW43B43ZC7MFT
**                          KW43L43Z92MFT
**                          KW43L43Z93MFT
**                          KW43L43Z96MFT
**                          KW43L43Z97MFT
**
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b260316
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ATX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_ATX.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for ATX
 *
 * CMSIS Peripheral Access Layer for ATX
 */

#if !defined(PERI_ATX_H_)
#define PERI_ATX_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW43B43ZC2MFT))
#include "KW43B43ZC2_COMMON.h"
#elif (defined(CPU_KW43B43ZC3MFT))
#include "KW43B43ZC3_COMMON.h"
#elif (defined(CPU_KW43B43ZC6MFT))
#include "KW43B43ZC6_COMMON.h"
#elif (defined(CPU_KW43B43ZC7MFT))
#include "KW43B43ZC7_COMMON.h"
#elif (defined(CPU_KW43L43Z92MFT))
#include "KW43L43Z92_COMMON.h"
#elif (defined(CPU_KW43L43Z93MFT))
#include "KW43L43Z93_COMMON.h"
#elif (defined(CPU_KW43L43Z96MFT))
#include "KW43L43Z96_COMMON.h"
#elif (defined(CPU_KW43L43Z97MFT))
#include "KW43L43Z97_COMMON.h"
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
   -- ATX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ATX_Peripheral_Access_Layer ATX Peripheral Access Layer
 * @{
 */

/** ATX - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< ATX Version ID, offset: 0x0 */
       uint32_t PARAM;                             /**< ATX Parameter, offset: 0x4 */
  __IO uint32_t TEST_UNLOCK;                       /**< TEST_UNLOCK register, offset: 0x8 */
  __IO uint32_t CTRL;                              /**< ATX Control Regs, offset: 0xC */
  __IO uint32_t CMP_CTRL;                          /**< ATX Cmp Control Regs, offset: 0x10 */
  __IO uint32_t NVM_CTRL;                          /**< select NVM test channels connecting to ATX buses, offset: 0x14 */
  __IO uint32_t CRACK_DETECT_TRANSMIT_L;           /**< Crack Detect Transmit Low, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __I  uint32_t CRACK_DETECT_RECEIVE_L;            /**< Crack Detect Receive Low, offset: 0x20 */
} ATX_Type;

/* ----------------------------------------------------------------------------
   -- ATX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ATX_Register_Masks ATX Register Masks
 * @{
 */

/*! @name VERID - ATX Version ID */
/*! @{ */

#define ATX_VERID_FEATURE_MASK                   (0xFFFFU)
#define ATX_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - FEATURE */
#define ATX_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << ATX_VERID_FEATURE_SHIFT)) & ATX_VERID_FEATURE_MASK)

#define ATX_VERID_MINOR_MASK                     (0xFF0000U)
#define ATX_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - MINOR */
#define ATX_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << ATX_VERID_MINOR_SHIFT)) & ATX_VERID_MINOR_MASK)

#define ATX_VERID_MAJOR_MASK                     (0xFF000000U)
#define ATX_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - MAJOR */
#define ATX_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << ATX_VERID_MAJOR_SHIFT)) & ATX_VERID_MAJOR_MASK)
/*! @} */

/*! @name TEST_UNLOCK - TEST_UNLOCK register */
/*! @{ */

#define ATX_TEST_UNLOCK_TEST_UNLOCK_MASK         (0x1U)
#define ATX_TEST_UNLOCK_TEST_UNLOCK_SHIFT        (0U)
/*! TEST_UNLOCK
 *  0b0..lock read/write into test register
 *  0b1..unlock read/write into test register
 */
#define ATX_TEST_UNLOCK_TEST_UNLOCK(x)           (((uint32_t)(((uint32_t)(x)) << ATX_TEST_UNLOCK_TEST_UNLOCK_SHIFT)) & ATX_TEST_UNLOCK_TEST_UNLOCK_MASK)

#define ATX_TEST_UNLOCK_TEST_UNLOCK_VALUE_MASK   (0xFFFEU)
#define ATX_TEST_UNLOCK_TEST_UNLOCK_VALUE_SHIFT  (1U)
#define ATX_TEST_UNLOCK_TEST_UNLOCK_VALUE(x)     (((uint32_t)(((uint32_t)(x)) << ATX_TEST_UNLOCK_TEST_UNLOCK_VALUE_SHIFT)) & ATX_TEST_UNLOCK_TEST_UNLOCK_VALUE_MASK)
/*! @} */

/*! @name CTRL - ATX Control Regs */
/*! @{ */

#define ATX_CTRL_CDAC_DATA_MASK                  (0x7FU)
#define ATX_CTRL_CDAC_DATA_SHIFT                 (0U)
/*! CDAC_DATA - 7-bit control word for IDAC input
 *  0b0000000..default value, output 0.5ua
 *  0b0000001..max 1ua
 *  0b1111111..max 64ua
 */
#define ATX_CTRL_CDAC_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_CDAC_DATA_SHIFT)) & ATX_CTRL_CDAC_DATA_MASK)

#define ATX_CTRL_IDAC_BUS_SEL_MASK               (0x30000U)
#define ATX_CTRL_IDAC_BUS_SEL_SHIFT              (16U)
/*! IDAC_BUS_SEL - Test bus selection for IDAC current output,this bits only valid when IDAC_EN is set to 1
 *  0b00..select test bus 0
 *  0b01..select test bus 1
 *  0b10..select test bus 2, In this mode,idac_code_lv is restricted within 7'b0000000 to 7'b0000011 and the
 *        output current of IDAC is restricted within 0.5uA to 2uA
 *  0b11..Enabled but no test bus is selected.This is forbidden
 */
#define ATX_CTRL_IDAC_BUS_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_IDAC_BUS_SEL_SHIFT)) & ATX_CTRL_IDAC_BUS_SEL_MASK)

#define ATX_CTRL_IDAC_EN_MASK                    (0x40000U)
#define ATX_CTRL_IDAC_EN_SHIFT                   (18U)
/*! IDAC_EN - This bit is used to enable IDAC
 *  0b0..IDAC is disabled
 *  0b1..IDAC is enabled
 */
#define ATX_CTRL_IDAC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_IDAC_EN_SHIFT)) & ATX_CTRL_IDAC_EN_MASK)

#define ATX_CTRL_I2V_BUS_SEL_MASK                (0x3000000U)
#define ATX_CTRL_I2V_BUS_SEL_SHIFT               (24U)
/*! I2V_BUS_SEL - Test bus selection for I2V voltage output, these 2 bits is only effective when i2v_en_lv is set to "1"
 *  0b00..default value
 *  0b01..forbidden
 *  0b10..forbidden
 *  0b11..select test bus 2
 */
#define ATX_CTRL_I2V_BUS_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_I2V_BUS_SEL_SHIFT)) & ATX_CTRL_I2V_BUS_SEL_MASK)

#define ATX_CTRL_I2V_EN_MASK                     (0x4000000U)
#define ATX_CTRL_I2V_EN_SHIFT                    (26U)
/*! I2V_EN - current to voltage converter enable
 *  0b0..current to voltage converter disabled
 *  0b1..current to voltage converter enabled
 */
#define ATX_CTRL_I2V_EN(x)                       (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_I2V_EN_SHIFT)) & ATX_CTRL_I2V_EN_MASK)

#define ATX_CTRL_I2V_25K_ITYPE_MASK              (0x40000000U)
#define ATX_CTRL_I2V_25K_ITYPE_SHIFT             (30U)
/*! I2V_25K_ITYPE - I2V resistor connection selection
 *  0b0..default value,connect i2v resistor to ground
 *  0b1..connect i2v resistor to power
 */
#define ATX_CTRL_I2V_25K_ITYPE(x)                (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_I2V_25K_ITYPE_SHIFT)) & ATX_CTRL_I2V_25K_ITYPE_MASK)

#define ATX_CTRL_ATX_EN_MASK                     (0x80000000U)
#define ATX_CTRL_ATX_EN_SHIFT                    (31U)
#define ATX_CTRL_ATX_EN(x)                       (((uint32_t)(((uint32_t)(x)) << ATX_CTRL_ATX_EN_SHIFT)) & ATX_CTRL_ATX_EN_MASK)
/*! @} */

/*! @name CMP_CTRL - ATX Cmp Control Regs */
/*! @{ */

#define ATX_CMP_CTRL_ATX_TO_CH6_EN_MASK          (0x1U)
#define ATX_CMP_CTRL_ATX_TO_CH6_EN_SHIFT         (0U)
/*! ATX_TO_CH6_EN - Channel 6 of CMP connect to ATX switch control */
#define ATX_CMP_CTRL_ATX_TO_CH6_EN(x)            (((uint32_t)(((uint32_t)(x)) << ATX_CMP_CTRL_ATX_TO_CH6_EN_SHIFT)) & ATX_CMP_CTRL_ATX_TO_CH6_EN_MASK)

#define ATX_CMP_CTRL_ATX_TO_PAD_CH0P_EN_MASK     (0x100U)
#define ATX_CMP_CTRL_ATX_TO_PAD_CH0P_EN_SHIFT    (8U)
/*! ATX_TO_PAD_CH0P_EN - PAD and channel 0 of CMP connect to ATX switch control */
#define ATX_CMP_CTRL_ATX_TO_PAD_CH0P_EN(x)       (((uint32_t)(((uint32_t)(x)) << ATX_CMP_CTRL_ATX_TO_PAD_CH0P_EN_SHIFT)) & ATX_CMP_CTRL_ATX_TO_PAD_CH0P_EN_MASK)

#define ATX_CMP_CTRL_ATX_TO_DAC8B_CH7_EN_MASK    (0x10000U)
#define ATX_CMP_CTRL_ATX_TO_DAC8B_CH7_EN_SHIFT   (16U)
/*! ATX_TO_DAC8B_CH7_EN - dac8b and channel 7 of CMP connect to ATX switch control */
#define ATX_CMP_CTRL_ATX_TO_DAC8B_CH7_EN(x)      (((uint32_t)(((uint32_t)(x)) << ATX_CMP_CTRL_ATX_TO_DAC8B_CH7_EN_SHIFT)) & ATX_CMP_CTRL_ATX_TO_DAC8B_CH7_EN_MASK)
/*! @} */

/*! @name NVM_CTRL - select NVM test channels connecting to ATX buses */
/*! @{ */

#define ATX_NVM_CTRL_FLASH_TO_ATX_EN_LV_MASK     (0xFFU)
#define ATX_NVM_CTRL_FLASH_TO_ATX_EN_LV_SHIFT    (0U)
/*! FLASH_TO_ATX_EN_LV
 *  0b00000000..no connection
 *  0b00000001..flash_to_atx_tm_nvm_3v[0] connect to ipt_test_ana_atx3v[0]; no connection on ipt_test_ana_atx3v[1]
 *  0b00000010..flash_to_atx_tm_nvm_3v[1] connect to ipt_test_ana_atx3v[0]; no connection on ipt_test_ana_atx3v[1]
 *  0b00000100..flash_to_atx_tm_nvm_3v[2] connect to ipt_test_ana_atx3v[0]; no connection on ipt_test_ana_atx3v[1]
 *  0b00001000..flash_to_atx_tm_nvm_3v[3] connect to ipt_test_ana_atx3v[0]; no connection on ipt_test_ana_atx3v[1]
 *  0b00010000..no connection to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[0] on ipt_test_ana_atx3v[1]
 *  0b00010010..flash_to_atx_tm_nvm_3v[1] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[0] connect to ipt_test_ana_atx3v[1]
 *  0b00010100..flash_to_atx_tm_nvm_3v[2] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[0] connect to ipt_test_ana_atx3v[1]
 *  0b00011000..flash_to_atx_tm_nvm_3v[3] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[0] connect to ipt_test_ana_atx3v[1]
 *  0b00100000..no connection to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[1] on ipt_test_ana_atx3v[1]
 *  0b00100001..flash_to_atx_tm_nvm_3v[0] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[1] connect to ipt_test_ana_atx3v[1]
 *  0b00100100..flash_to_atx_tm_nvm_3v[2] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[1] connect to ipt_test_ana_atx3v[1]
 *  0b00101000..flash_to_atx_tm_nvm_3v[3] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[1] connect to ipt_test_ana_atx3v[1]
 *  0b01000000..no connection to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[2] on ipt_test_ana_atx3v[1]
 *  0b01000001..flash_to_atx_tm_nvm_3v[0] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[2] connect to ipt_test_ana_atx3v[1]
 *  0b01000010..flash_to_atx_tm_nvm_3v[1] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[2] connect to ipt_test_ana_atx3v[1]
 *  0b01001000..flash_to_atx_tm_nvm_3v[3] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[2] connect to ipt_test_ana_atx3v[1]
 *  0b10000000..no connection to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[3] on ipt_test_ana_atx3v[1]
 *  0b10000001..flash_to_atx_tm_nvm_3v[0] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[3] connect to ipt_test_ana_atx3v[1]
 *  0b10000010..flash_to_atx_tm_nvm_3v[1] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[3] connect to ipt_test_ana_atx3v[1]
 *  0b10000100..flash_to_atx_tm_nvm_3v[2] connect to ipt_test_ana_atx3v[0]; flash_to_atx_tm_nvm_3v[3] connect to ipt_test_ana_atx3v[1]
 */
#define ATX_NVM_CTRL_FLASH_TO_ATX_EN_LV(x)       (((uint32_t)(((uint32_t)(x)) << ATX_NVM_CTRL_FLASH_TO_ATX_EN_LV_SHIFT)) & ATX_NVM_CTRL_FLASH_TO_ATX_EN_LV_MASK)
/*! @} */

/*! @name CRACK_DETECT_TRANSMIT_L - Crack Detect Transmit Low */
/*! @{ */

#define ATX_CRACK_DETECT_TRANSMIT_L_CRACK_DETECT_TRANSMIT_L_MASK (0x1FU)
#define ATX_CRACK_DETECT_TRANSMIT_L_CRACK_DETECT_TRANSMIT_L_SHIFT (0U)
/*! CRACK_DETECT_TRANSMIT_L - Crack Detect transmit register */
#define ATX_CRACK_DETECT_TRANSMIT_L_CRACK_DETECT_TRANSMIT_L(x) (((uint32_t)(((uint32_t)(x)) << ATX_CRACK_DETECT_TRANSMIT_L_CRACK_DETECT_TRANSMIT_L_SHIFT)) & ATX_CRACK_DETECT_TRANSMIT_L_CRACK_DETECT_TRANSMIT_L_MASK)
/*! @} */

/*! @name CRACK_DETECT_RECEIVE_L - Crack Detect Receive Low */
/*! @{ */

#define ATX_CRACK_DETECT_RECEIVE_L_CRACK_DETECT_RECEIVE_L_MASK (0x1FU)
#define ATX_CRACK_DETECT_RECEIVE_L_CRACK_DETECT_RECEIVE_L_SHIFT (0U)
/*! CRACK_DETECT_RECEIVE_L - Crack Detect receive register Low */
#define ATX_CRACK_DETECT_RECEIVE_L_CRACK_DETECT_RECEIVE_L(x) (((uint32_t)(((uint32_t)(x)) << ATX_CRACK_DETECT_RECEIVE_L_CRACK_DETECT_RECEIVE_L_SHIFT)) & ATX_CRACK_DETECT_RECEIVE_L_CRACK_DETECT_RECEIVE_L_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ATX_Register_Masks */


/*!
 * @}
 */ /* end of group ATX_Peripheral_Access_Layer */


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


#endif  /* PERI_ATX_H_ */

