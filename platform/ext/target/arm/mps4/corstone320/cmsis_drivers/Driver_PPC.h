/*
 * Copyright (c) 2019-2024, Arm Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __DRIVER_PPC_H__
#define __DRIVER_PPC_H__

#include "Driver_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* API version */
#define ARM_PPC_API_VERSION ARM_DRIVER_VERSION_MAJOR_MINOR(1,0)

/* Security attribute used to configure the peripheral */
typedef enum _ARM_PPC_CORSTONE320_SecAttr {
    ARM_PPC_CORSTONE320_SECURE_CONFIG = 0,    /*!< Secure access */
    ARM_PPC_CORSTONE320_NONSECURE_CONFIG,     /*!< Non-secure access */
} ARM_PPC_CORSTONE320_SecAttr;

/* Privilege attribute used to configure the peripheral */
typedef enum _ARM_PPC_CORSTONE320_PrivAttr {
    ARM_PPC_CORSTONE320_PRIV_AND_NONPRIV_CONFIG = 0, /*!< Privilege and non-privilege
                                             * access */
    ARM_PPC_CORSTONE320_PRIV_CONFIG,                 /*!< Privilege only access */
} ARM_PPC_CORSTONE320_PrivAttr;

/* Function descriptions */
/**
  SACFG  - Secure Privilege Control Block
  NSACFG - Non-Secure Privilege Control Block

  \fn          ARM_DRIVER_VERSION PPC_CORSTONE320_GetVersion(void)
  \brief       Get driver version.
  \return      \ref ARM_DRIVER_VERSION

  \fn          int32_t PPC_CORSTONE320_Initialize(void)
  \brief       Initializes PPC Interface.
  \return      Returns Corstone-320 PPC error code.

  \fn          int32_t PPC_CORSTONE320_Uninitialize(void)
  \brief       De-initializes PPC Interface.
  \return      Returns Corstone-320 PPC error code.

  \fn          int32_t PPC_CORSTONE320_ConfigPrivilege(uint32_t periph,
                                                  ARM_PPC_CORSTONE320_SecAttr sec_attr,
                                                  ARM_PPC_CORSTONE320_PrivAttr priv_attr)
  \brief       Configures privilege level with privileged and unprivileged
               access or privileged access only in the given security domain
               for a peripheral controlled by the given PPC.
  \param[in]   periph:     Peripheral mask for SACFG and NSACFG registers.
  \param[in]   sec_attr:   Specifies Secure or Non Secure domain.
  \param[in]   priv_attr:  Privilege attribute value to set.
  \return      Returns Corstone-320 PPC error code.

  \fn          bool PPC_CORSTONE320_IsPeriphPrivOnly (uint32_t periph)
  \brief       Checks if the peripheral is configured to be privilege only
                - with non-secure caller in the non-secure domain
                - with secure caller in the configured security domain
  \param[in]   periph:      Peripheral mask for SACFG and NSACFG registers.
  \return      Returns true if the peripheral is configured as privilege access
               only, false for privilege and unprivilege access mode.

  Secure only functions:

  \fn          int32_t PPC_CORSTONE320_ConfigSecurity(uint32_t periph,
                                                 ARM_PPC_CORSTONE320_SecAttr sec_attr)
  \brief       Configures security level for a peripheral controlled by the
               given PPC with secure or non-secure access only.
  \param[in]   periph:     Peripheral mask for SACFG and NSACFG registers.
  \param[in]   sec_attr:   Secure attribute value to set.
  \return      Returns Corstone-320 PPC error code.

  \fn          bool PPC_CORSTONE320_IsPeriphSecure (uint32_t periph)
  \brief       Checks if the peripheral is configured to be secure.
  \param[in]   periph:      Peripheral mask for SACFG  and NSACFG registers.
  \return      Returns true if the peripheral is configured as secure,
               false for non-secure.

  \fn          int32_t PPC_CORSTONE320_EnableInterrupt (void)
  \brief       Enables PPC interrupt.
  \return      Returns Corstone320 PPC error code.

  \fn          void PPC_CORSTONE320_DisableInterrupt (void)
  \brief       Disables PPC interrupt.

  \fn          void PPC_CORSTONE320_ClearInterrupt (void)
  \brief       Clears PPC interrupt.

  \fn          bool PPC_CORSTONE320_InterruptState (void)
  \brief       Gets PPC interrupt state.
  \return      Returns true if the interrupt is active, false otherwise.
*/

/**
 * \brief Access structure of the PPC Driver.
 */
typedef struct _ARM_DRIVER_PPC_CORSTONE320 {
  ARM_DRIVER_VERSION  (*GetVersion)       (void);            ///< Pointer to \ref ARM_PPC_GetVersion   : Get driver version.
  int32_t             (*Initialize)       (void);            ///< Pointer to \ref ARM_PPC_Initialize   : Initialize the PPC Interface.
  int32_t             (*Uninitialize)     (void);            ///< Pointer to \ref ARM_PPC_Uninitialize : De-initialize the PPC Interface.
  int32_t             (*ConfigPrivilege)  (uint32_t periph, ARM_PPC_CORSTONE320_SecAttr sec_attr, ARM_PPC_CORSTONE320_PrivAttr priv_attr);  ///< Pointer to \ref ARM_PPC_ConfigPeriph : Configure a peripheral controlled by the PPC.
  bool                (*IsPeriphPrivOnly) (uint32_t periph);  ///< Pointer to \ref IsPeriphPrivOnly : Check if the peripheral is configured to be privilege only.
#if (defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
  int32_t             (*ConfigSecurity)   (uint32_t periph, ARM_PPC_CORSTONE320_SecAttr sec_attr);  ///< Pointer to \ref ARM_PPC_ConfigPeriph : Configure a peripheral controlled by the PPC.
  bool                (*IsPeriphSecure)   (uint32_t periph);  ///< Pointer to \ref IsPeriphSecure :   Check if the peripheral is configured to be secure.
  int32_t             (*EnableInterrupt)  (void);            ///< Pointer to \ref ARM_PPC_EnableInterrupt  : Enable PPC interrupt.
  void                (*DisableInterrupt) (void);            ///< Pointer to \ref ARM_PPC_DisableInterrupt : Disable PPC interrupt.
  void                (*ClearInterrupt)   (void);            ///< Pointer to \ref ARM_PPC_ClearInterrupt   : Clear PPC interrupt.
  bool                (*InterruptState)   (void);            ///< Pointer to \ref ARM_PPC_InterruptState   : PPC interrupt State.
#endif /* (defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)) */
} const ARM_DRIVER_PPC_CORSTONE320;

#ifdef __cplusplus
}
#endif
#endif /* __DRIVER_PPC_H__ */
