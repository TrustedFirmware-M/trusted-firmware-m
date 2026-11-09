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
**         CMSIS Peripheral Access Layer for LTC
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
 * @file PERI_LTC.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for LTC
 *
 * CMSIS Peripheral Access Layer for LTC
 */

#if !defined(PERI_LTC_H_)
#define PERI_LTC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- LTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LTC_Peripheral_Access_Layer LTC Peripheral Access Layer
 * @{
 */

/** LTC - Size of Registers Arrays */
#define LTC_CTXX_I_COUNT                          14u
#define LTC_KEYX_I_COUNT                          4u

/** LTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MD;                                /**< Mode Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __O  uint32_t KS;                                /**< Key Size Register, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DS;                                /**< Data Size Register, offset: 0x10 */
       uint8_t RESERVED_2[4];
  __IO uint32_t ICVS;                              /**< ICV Size Register, offset: 0x18 */
       uint8_t RESERVED_3[20];
  __O  uint32_t COM;                               /**< Command Register, offset: 0x30 */
  __IO uint32_t CTL;                               /**< Control Register, offset: 0x34 */
       uint8_t RESERVED_4[8];
  __O  uint32_t CW;                                /**< Clear Written Register, offset: 0x40 */
       uint8_t RESERVED_5[4];
  __IO uint32_t STA;                               /**< Status Register, offset: 0x48 */
  __I  uint32_t ESTA;                              /**< Error Status Register, offset: 0x4C */
       uint8_t RESERVED_6[8];
  __IO uint32_t AADSZ;                             /**< AAD Size Register, offset: 0x58 */
       uint8_t RESERVED_7[164];
  __IO uint32_t CTX[LTC_CTXX_I_COUNT];             /**< Context Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_8[200];
  __IO uint32_t KEY[LTC_KEYX_I_COUNT];             /**< Key Registers, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_9[736];
  __I  uint32_t VID1;                              /**< Version ID Register, offset: 0x4F0 */
  __I  uint32_t VID2;                              /**< Version ID 2 Register, offset: 0x4F4 */
  __I  uint32_t CHAVID;                            /**< CHA Version ID Register, offset: 0x4F8 */
       uint8_t RESERVED_10[708];
  __I  uint32_t FIFOSTA;                           /**< FIFO Status Register, offset: 0x7C0 */
       uint8_t RESERVED_11[28];
  __O  uint32_t IFIFO;                             /**< Input Data FIFO, offset: 0x7E0 */
       uint8_t RESERVED_12[12];
  __I  uint32_t OFIFO;                             /**< Output Data FIFO, offset: 0x7F0 */
} LTC_Type;

/* ----------------------------------------------------------------------------
   -- LTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LTC_Register_Masks LTC Register Masks
 * @{
 */

/*! @name MD - Mode Register */
/*! @{ */

#define LTC_MD_ENC_MASK                          (0x1U)
#define LTC_MD_ENC_SHIFT                         (0U)
/*! ENC - Encrypt/Decrypt.
 *  0b0..Decrypt.
 *  0b1..Encrypt.
 */
#define LTC_MD_ENC(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_MD_ENC_SHIFT)) & LTC_MD_ENC_MASK)

#define LTC_MD_ICV_TEST_MASK                     (0x2U)
#define LTC_MD_ICV_TEST_SHIFT                    (1U)
/*! ICV_TEST - ICV Checking */
#define LTC_MD_ICV_TEST(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_MD_ICV_TEST_SHIFT)) & LTC_MD_ICV_TEST_MASK)

#define LTC_MD_AS_MASK                           (0xCU)
#define LTC_MD_AS_SHIFT                          (2U)
/*! AS - Algorithm State
 *  0b00..Update
 *  0b01..Initialize
 *  0b10..Finalize
 *  0b11..Initialize/Finalize
 */
#define LTC_MD_AS(x)                             (((uint32_t)(((uint32_t)(x)) << LTC_MD_AS_SHIFT)) & LTC_MD_AS_MASK)

#define LTC_MD_AAI_MASK                          (0x1FF0U)
#define LTC_MD_AAI_SHIFT                         (4U)
/*! AAI - Additional Algorithm information */
#define LTC_MD_AAI(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_MD_AAI_SHIFT)) & LTC_MD_AAI_MASK)

#define LTC_MD_ALG_MASK                          (0xFF0000U)
#define LTC_MD_ALG_SHIFT                         (16U)
/*! ALG - Algorithm
 *  0b00010000..AES
 */
#define LTC_MD_ALG(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_MD_ALG_SHIFT)) & LTC_MD_ALG_MASK)
/*! @} */

/*! @name KS - Key Size Register */
/*! @{ */

#define LTC_KS_KS_MASK                           (0x1FU)
#define LTC_KS_KS_SHIFT                          (0U)
/*! KS - Key Size */
#define LTC_KS_KS(x)                             (((uint32_t)(((uint32_t)(x)) << LTC_KS_KS_SHIFT)) & LTC_KS_KS_MASK)
/*! @} */

/*! @name DS - Data Size Register */
/*! @{ */

#define LTC_DS_DS_MASK                           (0xFFFU)
#define LTC_DS_DS_SHIFT                          (0U)
/*! DS - Data Size */
#define LTC_DS_DS(x)                             (((uint32_t)(((uint32_t)(x)) << LTC_DS_DS_SHIFT)) & LTC_DS_DS_MASK)
/*! @} */

/*! @name ICVS - ICV Size Register */
/*! @{ */

#define LTC_ICVS_ICVS_MASK                       (0x1FU)
#define LTC_ICVS_ICVS_SHIFT                      (0U)
/*! ICVS - ICV Size, in Bytes */
#define LTC_ICVS_ICVS(x)                         (((uint32_t)(((uint32_t)(x)) << LTC_ICVS_ICVS_SHIFT)) & LTC_ICVS_ICVS_MASK)
/*! @} */

/*! @name COM - Command Register */
/*! @{ */

#define LTC_COM_ALL_MASK                         (0x1U)
#define LTC_COM_ALL_SHIFT                        (0U)
/*! ALL - Reset All Internal Logic
 *  0b0..Do Not Reset
 *  0b1..Reset all CHAs in use by this CCB. This should be done at the end of every operation to make sure the
 *       engine is cleared of all data and ready for next command.
 */
#define LTC_COM_ALL(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_COM_ALL_SHIFT)) & LTC_COM_ALL_MASK)

#define LTC_COM_AES_MASK                         (0x2U)
#define LTC_COM_AES_SHIFT                        (1U)
/*! AES - Reset AESA
 *  0b0..Do Not Reset
 *  0b1..Reset AES Accelerator
 */
#define LTC_COM_AES(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_COM_AES_SHIFT)) & LTC_COM_AES_MASK)
/*! @} */

/*! @name CTL - Control Register */
/*! @{ */

#define LTC_CTL_IM_MASK                          (0x1U)
#define LTC_CTL_IM_SHIFT                         (0U)
/*! IM - Interrupt Mask
 *  0b0..Interrupt not masked.
 *  0b1..Interrupt masked
 */
#define LTC_CTL_IM(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_CTL_IM_SHIFT)) & LTC_CTL_IM_MASK)

#define LTC_CTL_IFE_MASK                         (0x100U)
#define LTC_CTL_IFE_SHIFT                        (8U)
/*! IFE - Input FIFO DMA Enable
 *  0b0..DMA Request and Done signals disabled for the Input FIFO.
 *  0b1..DMA Request and Done signals enabled for the Input FIFO.
 */
#define LTC_CTL_IFE(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_IFE_SHIFT)) & LTC_CTL_IFE_MASK)

#define LTC_CTL_IFR_MASK                         (0x200U)
#define LTC_CTL_IFR_SHIFT                        (9U)
/*! IFR - Input FIFO DMA Request Size
 *  0b0..DMA request size is 1 entry. (4 bytes)
 *  0b1..DMA request size is 2 entries. (8 bytes)
 */
#define LTC_CTL_IFR(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_IFR_SHIFT)) & LTC_CTL_IFR_MASK)

#define LTC_CTL_OFE_MASK                         (0x1000U)
#define LTC_CTL_OFE_SHIFT                        (12U)
/*! OFE - Output FIFO DMA Enable
 *  0b0..DMA Request and Done signals disabled for the Output FIFO.
 *  0b1..DMA Request and Done signals enabled for the Output FIFO.
 */
#define LTC_CTL_OFE(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_OFE_SHIFT)) & LTC_CTL_OFE_MASK)

#define LTC_CTL_OFR_MASK                         (0x2000U)
#define LTC_CTL_OFR_SHIFT                        (13U)
/*! OFR - Output FIFO DMA Request Size
 *  0b0..DMA request size is 1 entry.
 *  0b1..DMA request size is 4 entries.
 */
#define LTC_CTL_OFR(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_OFR_SHIFT)) & LTC_CTL_OFR_MASK)

#define LTC_CTL_IFS_MASK                         (0x10000U)
#define LTC_CTL_IFS_SHIFT                        (16U)
/*! IFS - Input FIFO Byte Swap
 *  0b0..Do Not Byte Swap Data.
 *  0b1..Byte Swap Data.
 */
#define LTC_CTL_IFS(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_IFS_SHIFT)) & LTC_CTL_IFS_MASK)

#define LTC_CTL_OFS_MASK                         (0x20000U)
#define LTC_CTL_OFS_SHIFT                        (17U)
/*! OFS - Output FIFO Byte Swap
 *  0b0..Do Not Byte Swap Data.
 *  0b1..Byte Swap Data.
 */
#define LTC_CTL_OFS(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_OFS_SHIFT)) & LTC_CTL_OFS_MASK)

#define LTC_CTL_KIS_MASK                         (0x100000U)
#define LTC_CTL_KIS_SHIFT                        (20U)
/*! KIS - Key Register Input Byte Swap
 *  0b0..Do Not Byte Swap Data.
 *  0b1..Byte Swap Data.
 */
#define LTC_CTL_KIS(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_KIS_SHIFT)) & LTC_CTL_KIS_MASK)

#define LTC_CTL_KOS_MASK                         (0x200000U)
#define LTC_CTL_KOS_SHIFT                        (21U)
/*! KOS - Key Register Output Byte Swap
 *  0b0..Do Not Byte Swap Data.
 *  0b1..Byte Swap Data.
 */
#define LTC_CTL_KOS(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_KOS_SHIFT)) & LTC_CTL_KOS_MASK)

#define LTC_CTL_CIS_MASK                         (0x400000U)
#define LTC_CTL_CIS_SHIFT                        (22U)
/*! CIS - Context Register Input Byte Swap
 *  0b0..Do Not Byte Swap Data.
 *  0b1..Byte Swap Data.
 */
#define LTC_CTL_CIS(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_CIS_SHIFT)) & LTC_CTL_CIS_MASK)

#define LTC_CTL_COS_MASK                         (0x800000U)
#define LTC_CTL_COS_SHIFT                        (23U)
/*! COS - Context Register Output Byte Swap
 *  0b0..Do Not Byte Swap Data.
 *  0b1..Byte Swap Data.
 */
#define LTC_CTL_COS(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_COS_SHIFT)) & LTC_CTL_COS_MASK)

#define LTC_CTL_KAL_MASK                         (0x80000000U)
#define LTC_CTL_KAL_SHIFT                        (31U)
/*! KAL - Key Register Access Lock
 *  0b0..Key Register is readable.
 *  0b1..Key Register is not readable.
 */
#define LTC_CTL_KAL(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTL_KAL_SHIFT)) & LTC_CTL_KAL_MASK)
/*! @} */

/*! @name CW - Clear Written Register */
/*! @{ */

#define LTC_CW_CM_MASK                           (0x1U)
#define LTC_CW_CM_SHIFT                          (0U)
/*! CM - Clear the Mode Register */
#define LTC_CW_CM(x)                             (((uint32_t)(((uint32_t)(x)) << LTC_CW_CM_SHIFT)) & LTC_CW_CM_MASK)

#define LTC_CW_CDS_MASK                          (0x4U)
#define LTC_CW_CDS_SHIFT                         (2U)
/*! CDS - Clear the Data Size Register */
#define LTC_CW_CDS(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_CW_CDS_SHIFT)) & LTC_CW_CDS_MASK)

#define LTC_CW_CICV_MASK                         (0x8U)
#define LTC_CW_CICV_SHIFT                        (3U)
/*! CICV - Clear the ICV Size Register */
#define LTC_CW_CICV(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CW_CICV_SHIFT)) & LTC_CW_CICV_MASK)

#define LTC_CW_CCR_MASK                          (0x20U)
#define LTC_CW_CCR_SHIFT                         (5U)
/*! CCR - Clear the Context Register */
#define LTC_CW_CCR(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_CW_CCR_SHIFT)) & LTC_CW_CCR_MASK)

#define LTC_CW_CKR_MASK                          (0x40U)
#define LTC_CW_CKR_SHIFT                         (6U)
/*! CKR - Clear the Key Register */
#define LTC_CW_CKR(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_CW_CKR_SHIFT)) & LTC_CW_CKR_MASK)

#define LTC_CW_COF_MASK                          (0x40000000U)
#define LTC_CW_COF_SHIFT                         (30U)
/*! COF - Clear Output FIFO */
#define LTC_CW_COF(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_CW_COF_SHIFT)) & LTC_CW_COF_MASK)

#define LTC_CW_CIF_MASK                          (0x80000000U)
#define LTC_CW_CIF_SHIFT                         (31U)
/*! CIF - Clear Input FIFO */
#define LTC_CW_CIF(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_CW_CIF_SHIFT)) & LTC_CW_CIF_MASK)
/*! @} */

/*! @name STA - Status Register */
/*! @{ */

#define LTC_STA_AB_MASK                          (0x2U)
#define LTC_STA_AB_SHIFT                         (1U)
/*! AB - AESA Busy
 *  0b0..AESA Idle
 *  0b1..AESA Busy.
 */
#define LTC_STA_AB(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_STA_AB_SHIFT)) & LTC_STA_AB_MASK)

#define LTC_STA_DI_MASK                          (0x10000U)
#define LTC_STA_DI_SHIFT                         (16U)
/*! DI - LTC Interrupt */
#define LTC_STA_DI(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_STA_DI_SHIFT)) & LTC_STA_DI_MASK)

#define LTC_STA_EI_MASK                          (0x100000U)
#define LTC_STA_EI_SHIFT                         (20U)
/*! EI - Internal Error
 *  0b0..No Error.
 *  0b1..Error Occurred. Details of the Error can be found in the Error Status Register.
 */
#define LTC_STA_EI(x)                            (((uint32_t)(((uint32_t)(x)) << LTC_STA_EI_SHIFT)) & LTC_STA_EI_MASK)
/*! @} */

/*! @name ESTA - Error Status Register */
/*! @{ */

#define LTC_ESTA_ERRID1_MASK                     (0xFU)
#define LTC_ESTA_ERRID1_SHIFT                    (0U)
/*! ERRID1 - Error ID 1
 *  0b0001..Mode Error
 *  0b0010..Data Size Error
 *  0b0011..Key Size Error
 *  0b0110..Data Arrived out of Sequence Error
 *  0b1010..ICV Check Failed
 *  0b1011..Internal Hardware Failure
 *  0b1100..CCM AAD Size Error (either 1. AAD flag in B0 =1 and no AAD type provided, 2. AAD flag in B0 = 0 and
 *          AAD povided, or 3. AAD flag in B0 =1 and not enough AAD provided - expecting more based on AAD size.)
 *  0b1111..Invalid Crypto Engine Selected
 */
#define LTC_ESTA_ERRID1(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_ESTA_ERRID1_SHIFT)) & LTC_ESTA_ERRID1_MASK)

#define LTC_ESTA_CL1_MASK                        (0xF00U)
#define LTC_ESTA_CL1_SHIFT                       (8U)
/*! CL1 - algorithms
 *  0b0000..General Error
 *  0b0001..AES
 */
#define LTC_ESTA_CL1(x)                          (((uint32_t)(((uint32_t)(x)) << LTC_ESTA_CL1_SHIFT)) & LTC_ESTA_CL1_MASK)
/*! @} */

/*! @name AADSZ - AAD Size Register */
/*! @{ */

#define LTC_AADSZ_AADSZ_MASK                     (0xFU)
#define LTC_AADSZ_AADSZ_SHIFT                    (0U)
/*! AADSZ - AAD size in Bytes, mod 16 */
#define LTC_AADSZ_AADSZ(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_AADSZ_AADSZ_SHIFT)) & LTC_AADSZ_AADSZ_MASK)

#define LTC_AADSZ_AL_MASK                        (0x80000000U)
#define LTC_AADSZ_AL_SHIFT                       (31U)
/*! AL - AAD Last */
#define LTC_AADSZ_AL(x)                          (((uint32_t)(((uint32_t)(x)) << LTC_AADSZ_AL_SHIFT)) & LTC_AADSZ_AL_MASK)
/*! @} */

/*! @name CTX - Context Register */
/*! @{ */

#define LTC_CTX_CTX_MASK                         (0xFFFFFFFFU)
#define LTC_CTX_CTX_SHIFT                        (0U)
/*! CTX - CTX */
#define LTC_CTX_CTX(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_CTX_CTX_SHIFT)) & LTC_CTX_CTX_MASK)
/*! @} */

/* The count of LTC_CTX */
#define LTC_CTX_COUNT                            (14U)

/*! @name KEY - Key Registers */
/*! @{ */

#define LTC_KEY_KEY_MASK                         (0xFFFFFFFFU)
#define LTC_KEY_KEY_SHIFT                        (0U)
/*! KEY - KEY */
#define LTC_KEY_KEY(x)                           (((uint32_t)(((uint32_t)(x)) << LTC_KEY_KEY_SHIFT)) & LTC_KEY_KEY_MASK)
/*! @} */

/* The count of LTC_KEY */
#define LTC_KEY_COUNT                            (4U)

/*! @name VID1 - Version ID Register */
/*! @{ */

#define LTC_VID1_MIN_REV_MASK                    (0xFFU)
#define LTC_VID1_MIN_REV_SHIFT                   (0U)
/*! MIN_REV - Minor revision number. */
#define LTC_VID1_MIN_REV(x)                      (((uint32_t)(((uint32_t)(x)) << LTC_VID1_MIN_REV_SHIFT)) & LTC_VID1_MIN_REV_MASK)

#define LTC_VID1_MAJ_REV_MASK                    (0xFF00U)
#define LTC_VID1_MAJ_REV_SHIFT                   (8U)
/*! MAJ_REV - Major revision number. */
#define LTC_VID1_MAJ_REV(x)                      (((uint32_t)(((uint32_t)(x)) << LTC_VID1_MAJ_REV_SHIFT)) & LTC_VID1_MAJ_REV_MASK)

#define LTC_VID1_IP_ID_MASK                      (0xFFFF0000U)
#define LTC_VID1_IP_ID_SHIFT                     (16U)
/*! IP_ID - Unique string used to identify which version of the module is in HW */
#define LTC_VID1_IP_ID(x)                        (((uint32_t)(((uint32_t)(x)) << LTC_VID1_IP_ID_SHIFT)) & LTC_VID1_IP_ID_MASK)
/*! @} */

/*! @name VID2 - Version ID 2 Register */
/*! @{ */

#define LTC_VID2_ECO_REV_MASK                    (0xFFU)
#define LTC_VID2_ECO_REV_SHIFT                   (0U)
/*! ECO_REV - ECO revision number. */
#define LTC_VID2_ECO_REV(x)                      (((uint32_t)(((uint32_t)(x)) << LTC_VID2_ECO_REV_SHIFT)) & LTC_VID2_ECO_REV_MASK)

#define LTC_VID2_ARCH_ERA_MASK                   (0xFF00U)
#define LTC_VID2_ARCH_ERA_SHIFT                  (8U)
/*! ARCH_ERA - Architectural ERA. */
#define LTC_VID2_ARCH_ERA(x)                     (((uint32_t)(((uint32_t)(x)) << LTC_VID2_ARCH_ERA_SHIFT)) & LTC_VID2_ARCH_ERA_MASK)

#define LTC_VID2_FIFO_ENTRIES_MASK               (0xFF0000U)
#define LTC_VID2_FIFO_ENTRIES_SHIFT              (16U)
/*! FIFO_ENTRIES - FIFO Entries */
#define LTC_VID2_FIFO_ENTRIES(x)                 (((uint32_t)(((uint32_t)(x)) << LTC_VID2_FIFO_ENTRIES_SHIFT)) & LTC_VID2_FIFO_ENTRIES_MASK)
/*! @} */

/*! @name CHAVID - CHA Version ID Register */
/*! @{ */

#define LTC_CHAVID_AESREV_MASK                   (0xFU)
#define LTC_CHAVID_AESREV_SHIFT                  (0U)
/*! AESREV - AES Revision Number */
#define LTC_CHAVID_AESREV(x)                     (((uint32_t)(((uint32_t)(x)) << LTC_CHAVID_AESREV_SHIFT)) & LTC_CHAVID_AESREV_MASK)

#define LTC_CHAVID_AESVID_MASK                   (0xF0U)
#define LTC_CHAVID_AESVID_SHIFT                  (4U)
/*! AESVID - AES Version ID */
#define LTC_CHAVID_AESVID(x)                     (((uint32_t)(((uint32_t)(x)) << LTC_CHAVID_AESVID_SHIFT)) & LTC_CHAVID_AESVID_MASK)
/*! @} */

/*! @name FIFOSTA - FIFO Status Register */
/*! @{ */

#define LTC_FIFOSTA_IFL_MASK                     (0x7FU)
#define LTC_FIFOSTA_IFL_SHIFT                    (0U)
/*! IFL - Input FIFO Level */
#define LTC_FIFOSTA_IFL(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_FIFOSTA_IFL_SHIFT)) & LTC_FIFOSTA_IFL_MASK)

#define LTC_FIFOSTA_IFF_MASK                     (0x8000U)
#define LTC_FIFOSTA_IFF_SHIFT                    (15U)
/*! IFF - Input FIFO Full */
#define LTC_FIFOSTA_IFF(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_FIFOSTA_IFF_SHIFT)) & LTC_FIFOSTA_IFF_MASK)

#define LTC_FIFOSTA_OFL_MASK                     (0x7F0000U)
#define LTC_FIFOSTA_OFL_SHIFT                    (16U)
/*! OFL - Output FIFO Level */
#define LTC_FIFOSTA_OFL(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_FIFOSTA_OFL_SHIFT)) & LTC_FIFOSTA_OFL_MASK)

#define LTC_FIFOSTA_OFF_MASK                     (0x80000000U)
#define LTC_FIFOSTA_OFF_SHIFT                    (31U)
/*! OFF - Output FIFO Full */
#define LTC_FIFOSTA_OFF(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_FIFOSTA_OFF_SHIFT)) & LTC_FIFOSTA_OFF_MASK)
/*! @} */

/*! @name IFIFO - Input Data FIFO */
/*! @{ */

#define LTC_IFIFO_IFIFO_MASK                     (0xFFFFFFFFU)
#define LTC_IFIFO_IFIFO_SHIFT                    (0U)
/*! IFIFO - IFIFO */
#define LTC_IFIFO_IFIFO(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_IFIFO_IFIFO_SHIFT)) & LTC_IFIFO_IFIFO_MASK)
/*! @} */

/*! @name OFIFO - Output Data FIFO */
/*! @{ */

#define LTC_OFIFO_OFIFO_MASK                     (0xFFFFFFFFU)
#define LTC_OFIFO_OFIFO_SHIFT                    (0U)
/*! OFIFO - Output FIFO */
#define LTC_OFIFO_OFIFO(x)                       (((uint32_t)(((uint32_t)(x)) << LTC_OFIFO_OFIFO_SHIFT)) & LTC_OFIFO_OFIFO_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LTC_Register_Masks */


/*!
 * @}
 */ /* end of group LTC_Peripheral_Access_Layer */


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


#endif  /* PERI_LTC_H_ */

