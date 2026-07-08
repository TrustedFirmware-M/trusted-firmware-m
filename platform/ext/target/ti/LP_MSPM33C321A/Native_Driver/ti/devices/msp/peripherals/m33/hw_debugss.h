/*****************************************************************************

  Copyright (C) 2025 Texas Instruments Incorporated - http://www.ti.com/ 

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions 
  are met:

   Redistributions of source code must retain the above copyright 
   notice, this list of conditions and the following disclaimer.

   Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the 
   documentation and/or other materials provided with the   
   distribution.

   Neither the name of Texas Instruments Incorporated nor the names of
   its contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/

#ifndef ti_devices_msp_peripherals_m33_hw_debugss__include
#define ti_devices_msp_peripherals_m33_hw_debugss__include

/* This preliminary header file does not have a version number */
/* Filename: hw_debugss.h */
/* MMR revised: 2025-04-09 14:12:34 */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp65soc/repos/m33c1 */
/* MMR revision: f4602b816b1643a266cc7aae6be755d35f394359 */
/* Generator revision: ee5e56ed8e50e22306abbffa1ce64d23abbf32b9
   (MInT: 1818019a64e181dbbfd48fdc69fea15367af4c13) */

#ifndef __CORTEX_M
  #ifdef __cplusplus
    #define __I  volatile        /*!< Defines 'read only' permissions */
  #else
    #define __I  volatile const  /*!< Defines 'read only' permissions */
  #endif
  #define __O  volatile          /*!< Defines 'write only' permissions */
  #define __IO  volatile         /*!< Defines 'read / write' permissions */

  /* following defines should be used for structure members */
  #define __IM  volatile const   /*! Defines 'read only' structure member permissions */
  #define __OM  volatile         /*! Defines 'write only' structure member permissions */
  #define __IOM  volatile        /*! Defines 'read / write' structure member permissions */
#endif

/* Use standard integer types with explicit width */
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

#if defined ( __CC_ARM )
#pragma anon_unions
#endif

/******************************************************************************
* DEBUGSS Registers
******************************************************************************/
#define DEBUGSS_CPU_INT_OFS                      ((uint32_t)0x00001020U)
#define DEBUGSS_PINCM_OFS                        ((uint32_t)0x00000004U)


/** @addtogroup DEBUGSS_CPU_INT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) Interrupt index */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001028) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001030) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001038) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00001040) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001048) Interrupt clear */
} DEBUGSS_CPU_INT_Regs;

/*@}*/ /* end of group DEBUGSS_CPU_INT */

/** @addtogroup DEBUGSS_PINCM
  @{
*/

typedef struct {
  __IO uint32_t SWCLK;                             /* !< (@ 0x00000004) SWCLK */
  __IO uint32_t SWDIO;                             /* !< (@ 0x00000008) SWDIO */
  __IO uint32_t SWCLK_ALT;                         /* !< (@ 0x0000000C) SWCLK_ALT */
  __IO uint32_t SWDIO_ALT;                         /* !< (@ 0x00000010) SWDIO_ALT */
} DEBUGSS_PINCM_Regs;

/*@}*/ /* end of group DEBUGSS_PINCM */

/** @addtogroup DEBUGSS
  @{
*/

typedef struct {
       uint32_t RESERVED0;
  DEBUGSS_PINCM_Regs  PINCM;                             /* !< (@ 0x00000004) */
       uint32_t RESERVED1[283];
  __IO uint32_t CPU_CONNECT_0;                     /* !< (@ 0x00000480) CPU Connect */
       uint32_t RESERVED2[743];
  DEBUGSS_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED3[37];
  __I  uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED4[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __I  uint32_t TXD;                               /* !< (@ 0x00001100) Transmit data register */
  __I  uint32_t TXCTL;                             /* !< (@ 0x00001104) Transmit control register */
  __IO uint32_t RXD;                               /* !< (@ 0x00001108) Receive data register */
  __IO uint32_t RXCTL;                             /* !< (@ 0x0000110C) Receive control register */
       uint32_t RESERVED5[60];
  __I  uint32_t SPECIAL_AUTH;                      /* !< (@ 0x00001200) Special enable authorization register */
  __O  uint32_t SPECIAL_AUTH_SET;                  /* !< (@ 0x00001204) Special enable authorization set register */
  __O  uint32_t SPECIAL_AUTH_CLR;                  /* !< (@ 0x00001208) Special enable authorization clear register */
       uint32_t RESERVED6;
  __I  uint32_t APP_AUTH;                          /* !< (@ 0x00001210) Application CPU0 authorization register */
  __O  uint32_t APP_AUTH_SET;                      /* !< (@ 0x00001214) Application CPU0 authorization set register */
  __O  uint32_t APP_AUTH_CLR;                      /* !< (@ 0x00001218) Application CPU0 authorization clear register */
       uint32_t RESERVED7[57];
  __I  uint32_t DEVICEID;                          /* !< (@ 0x00001300) Device identification register */
  __I  uint32_t USERID;                            /* !< (@ 0x00001304) User code identification regsiter */
} DEBUGSS_Regs;

/*@}*/ /* end of group DEBUGSS */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* DEBUGSS Register Control Bits
******************************************************************************/

/* DEBUGSS_IIDX Bits */
/* DEBUGSS_IIDX[STAT] Bits */
#define DEBUGSS_IIDX_STAT_OFS                    (0)                             /* !< STAT Offset */
#define DEBUGSS_IIDX_STAT_MASK                   ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define DEBUGSS_IIDX_STAT_NO_INTR                ((uint32_t)0x00000000U)         /* !< No pending interrupt request */
#define DEBUGSS_IIDX_STAT_TXIFG                  ((uint32_t)0x00000001U)         /* !< TX interrupt */
#define DEBUGSS_IIDX_STAT_RXIFG                  ((uint32_t)0x00000002U)         /* !< RX interrupt */
#define DEBUGSS_IIDX_STAT_PWRUP                  ((uint32_t)0x00000003U)         /* !< Power-up interrupt. A debug session
                                                                                    has started. */
#define DEBUGSS_IIDX_STAT_PWRDWN                 ((uint32_t)0x00000004U)         /* !< Power-up interrupt. A debug session
                                                                                    has started. */

/* DEBUGSS_IMASK Bits */
/* DEBUGSS_IMASK[TXIFG] Bits */
#define DEBUGSS_IMASK_TXIFG_OFS                  (0)                             /* !< TXIFG Offset */
#define DEBUGSS_IMASK_TXIFG_MASK                 ((uint32_t)0x00000001U)         /* !< Masks TXIFG in MIS register */
#define DEBUGSS_IMASK_TXIFG_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_TXIFG_SET                  ((uint32_t)0x00000001U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DEBUGSS_IMASK[RXIFG] Bits */
#define DEBUGSS_IMASK_RXIFG_OFS                  (1)                             /* !< RXIFG Offset */
#define DEBUGSS_IMASK_RXIFG_MASK                 ((uint32_t)0x00000002U)         /* !< Masks RXIFG in MIS register */
#define DEBUGSS_IMASK_RXIFG_CLR                  ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_RXIFG_SET                  ((uint32_t)0x00000002U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DEBUGSS_IMASK[PWRUPIFG] Bits */
#define DEBUGSS_IMASK_PWRUPIFG_OFS               (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_IMASK_PWRUPIFG_MASK              ((uint32_t)0x00000004U)         /* !< Masks PWRUPIFG in MIS register */
#define DEBUGSS_IMASK_PWRUPIFG_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_PWRUPIFG_SET               ((uint32_t)0x00000004U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */
/* DEBUGSS_IMASK[PWRDWNIFG] Bits */
#define DEBUGSS_IMASK_PWRDWNIFG_OFS              (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_IMASK_PWRDWNIFG_MASK             ((uint32_t)0x00000008U)         /* !< Masks PWRDWNIFG in MIS register */
#define DEBUGSS_IMASK_PWRDWNIFG_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define DEBUGSS_IMASK_PWRDWNIFG_SET              ((uint32_t)0x00000008U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in MIS will be set */

/* DEBUGSS_RIS Bits */
/* DEBUGSS_RIS[TXIFG] Bits */
#define DEBUGSS_RIS_TXIFG_OFS                    (0)                             /* !< TXIFG Offset */
#define DEBUGSS_RIS_TXIFG_MASK                   ((uint32_t)0x00000001U)         /* !< Raw interrupt status for TXIFG */
#define DEBUGSS_RIS_TXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< TXIFG did not occur */
#define DEBUGSS_RIS_TXIFG_SET                    ((uint32_t)0x00000001U)         /* !< TXIFG occurred */
/* DEBUGSS_RIS[RXIFG] Bits */
#define DEBUGSS_RIS_RXIFG_OFS                    (1)                             /* !< RXIFG Offset */
#define DEBUGSS_RIS_RXIFG_MASK                   ((uint32_t)0x00000002U)         /* !< Raw interrupt status for RXIFG */
#define DEBUGSS_RIS_RXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< RXIFG did not occur */
#define DEBUGSS_RIS_RXIFG_SET                    ((uint32_t)0x00000002U)         /* !< RXIFG occurred */
/* DEBUGSS_RIS[PWRUPIFG] Bits */
#define DEBUGSS_RIS_PWRUPIFG_OFS                 (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_RIS_PWRUPIFG_MASK                ((uint32_t)0x00000004U)         /* !< Raw interrupt status for PWRUPIFG */
#define DEBUGSS_RIS_PWRUPIFG_CLR                 ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not occur */
#define DEBUGSS_RIS_PWRUPIFG_SET                 ((uint32_t)0x00000004U)         /* !< PWRUPIFG occurred */
/* DEBUGSS_RIS[PWRDWNIFG] Bits */
#define DEBUGSS_RIS_PWRDWNIFG_OFS                (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_RIS_PWRDWNIFG_MASK               ((uint32_t)0x00000008U)         /* !< Raw interrupt status for PWRDWNIFG */
#define DEBUGSS_RIS_PWRDWNIFG_CLR                ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not occur */
#define DEBUGSS_RIS_PWRDWNIFG_SET                ((uint32_t)0x00000008U)         /* !< PWRUPIFG occurred */

/* DEBUGSS_MIS Bits */
/* DEBUGSS_MIS[TXIFG] Bits */
#define DEBUGSS_MIS_TXIFG_OFS                    (0)                             /* !< TXIFG Offset */
#define DEBUGSS_MIS_TXIFG_MASK                   ((uint32_t)0x00000001U)         /* !< Masked interrupt status for TXIFG */
#define DEBUGSS_MIS_TXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< TXIFG did not request an interrupt
                                                                                    service routine */
#define DEBUGSS_MIS_TXIFG_SET                    ((uint32_t)0x00000001U)         /* !< TXIFG requests an interrupt service
                                                                                    routine */
/* DEBUGSS_MIS[RXIFG] Bits */
#define DEBUGSS_MIS_RXIFG_OFS                    (1)                             /* !< RXIFG Offset */
#define DEBUGSS_MIS_RXIFG_MASK                   ((uint32_t)0x00000002U)         /* !< Masked interrupt status for RXIFG */
#define DEBUGSS_MIS_RXIFG_CLR                    ((uint32_t)0x00000000U)         /* !< RXIFG did not request an interrupt
                                                                                    service routine */
#define DEBUGSS_MIS_RXIFG_SET                    ((uint32_t)0x00000002U)         /* !< RXIFG requests an interrupt service
                                                                                    routine */
/* DEBUGSS_MIS[PWRUPIFG] Bits */
#define DEBUGSS_MIS_PWRUPIFG_OFS                 (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_MIS_PWRUPIFG_MASK                ((uint32_t)0x00000004U)         /* !< Masked interrupt status for
                                                                                    PWRUPIFG */
#define DEBUGSS_MIS_PWRUPIFG_CLR                 ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not request an
                                                                                    interrupt service routine */
#define DEBUGSS_MIS_PWRUPIFG_SET                 ((uint32_t)0x00000004U)         /* !< PWRUPIFG requests an interrupt
                                                                                    service routine */
/* DEBUGSS_MIS[PWRDWNIFG] Bits */
#define DEBUGSS_MIS_PWRDWNIFG_OFS                (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_MIS_PWRDWNIFG_MASK               ((uint32_t)0x00000008U)         /* !< Masked interrupt status for
                                                                                    PWRDWNIFG */
#define DEBUGSS_MIS_PWRDWNIFG_CLR                ((uint32_t)0x00000000U)         /* !< PWRUPIFG did not request an
                                                                                    interrupt service routine */
#define DEBUGSS_MIS_PWRDWNIFG_SET                ((uint32_t)0x00000008U)         /* !< PWRUPIFG requests an interrupt
                                                                                    service routine */

/* DEBUGSS_ISET Bits */
/* DEBUGSS_ISET[TXIFG] Bits */
#define DEBUGSS_ISET_TXIFG_OFS                   (0)                             /* !< TXIFG Offset */
#define DEBUGSS_ISET_TXIFG_MASK                  ((uint32_t)0x00000001U)         /* !< Sets TXIFG in RIS register */
#define DEBUGSS_ISET_TXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_TXIFG_SET                   ((uint32_t)0x00000001U)         /* !< RIS bit corresponding to TXIFG is
                                                                                    set */
/* DEBUGSS_ISET[RXIFG] Bits */
#define DEBUGSS_ISET_RXIFG_OFS                   (1)                             /* !< RXIFG Offset */
#define DEBUGSS_ISET_RXIFG_MASK                  ((uint32_t)0x00000002U)         /* !< Sets RXIFG in RIS register */
#define DEBUGSS_ISET_RXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_RXIFG_SET                   ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to RXIFG is
                                                                                    set */
/* DEBUGSS_ISET[PWRUPIFG] Bits */
#define DEBUGSS_ISET_PWRUPIFG_OFS                (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_ISET_PWRUPIFG_MASK               ((uint32_t)0x00000004U)         /* !< Sets PWRUPIFG in RIS register */
#define DEBUGSS_ISET_PWRUPIFG_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_PWRUPIFG_SET                ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is set */
/* DEBUGSS_ISET[PWRDWNIFG] Bits */
#define DEBUGSS_ISET_PWRDWNIFG_OFS               (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_ISET_PWRDWNIFG_MASK              ((uint32_t)0x00000008U)         /* !< Sets PWRDWNIFG in RIS register */
#define DEBUGSS_ISET_PWRDWNIFG_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ISET_PWRDWNIFG_SET               ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is set */

/* DEBUGSS_ICLR Bits */
/* DEBUGSS_ICLR[TXIFG] Bits */
#define DEBUGSS_ICLR_TXIFG_OFS                   (0)                             /* !< TXIFG Offset */
#define DEBUGSS_ICLR_TXIFG_MASK                  ((uint32_t)0x00000001U)         /* !< Clears TXIFG in RIS register */
#define DEBUGSS_ICLR_TXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_TXIFG_CLR                   ((uint32_t)0x00000001U)         /* !< RIS bit corresponding to TXIFG is
                                                                                    cleared */
/* DEBUGSS_ICLR[RXIFG] Bits */
#define DEBUGSS_ICLR_RXIFG_OFS                   (1)                             /* !< RXIFG Offset */
#define DEBUGSS_ICLR_RXIFG_MASK                  ((uint32_t)0x00000002U)         /* !< Clears RXIFG in RIS register */
#define DEBUGSS_ICLR_RXIFG_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_RXIFG_CLR                   ((uint32_t)0x00000002U)         /* !< RIS bit corresponding to RXIFG is
                                                                                    cleared */
/* DEBUGSS_ICLR[PWRUPIFG] Bits */
#define DEBUGSS_ICLR_PWRUPIFG_OFS                (2)                             /* !< PWRUPIFG Offset */
#define DEBUGSS_ICLR_PWRUPIFG_MASK               ((uint32_t)0x00000004U)         /* !< Clears PWRUPIFG in RIS register */
#define DEBUGSS_ICLR_PWRUPIFG_NO_EFFECT          ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_PWRUPIFG_CLR                ((uint32_t)0x00000004U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is cleared */
/* DEBUGSS_ICLR[PWRDWNIFG] Bits */
#define DEBUGSS_ICLR_PWRDWNIFG_OFS               (3)                             /* !< PWRDWNIFG Offset */
#define DEBUGSS_ICLR_PWRDWNIFG_MASK              ((uint32_t)0x00000008U)         /* !< Clears PWRDWNIFG in RIS register */
#define DEBUGSS_ICLR_PWRDWNIFG_NO_EFFECT         ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define DEBUGSS_ICLR_PWRDWNIFG_CLR               ((uint32_t)0x00000008U)         /* !< RIS bit corresponding to PWRUPIFG
                                                                                    is cleared */

/* DEBUGSS_SWCLK Bits */
/* DEBUGSS_SWCLK[PSTATE] Bits */
#define DEBUGSS_SWCLK_PSTATE_OFS                 (6)                             /* !< PSTATE Offset */
#define DEBUGSS_SWCLK_PSTATE_MASK                ((uint32_t)0x000000C0U)         /* !< Peripheral-Analog Channel State */
#define DEBUGSS_SWCLK_PSTATE_UNASSIGNED          ((uint32_t)0x00000000U)         /* !< P-Channel is in Unassigned State */
#define DEBUGSS_SWCLK_PSTATE_HANDOVER            ((uint32_t)0x00000040U)         /* !< P-Channel is in Handover State */
#define DEBUGSS_SWCLK_PSTATE_CONC_NOT_LOCKED     ((uint32_t)0x00000080U)         /* !< P-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWCLK_PSTATE_CONC_LOCKED         ((uint32_t)0x000000C0U)         /* !< P-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWCLK[GSTATE] Bits */
#define DEBUGSS_SWCLK_GSTATE_OFS                 (14)                            /* !< GSTATE Offset */
#define DEBUGSS_SWCLK_GSTATE_MASK                ((uint32_t)0x0000C000U)         /* !< GPIO Channel State */
#define DEBUGSS_SWCLK_GSTATE_UNASSIGNED          ((uint32_t)0x00000000U)         /* !< G-Channel is in Unassigned State */
#define DEBUGSS_SWCLK_GSTATE_HANDOVER            ((uint32_t)0x00004000U)         /* !< G-Channel is in Handover State */
#define DEBUGSS_SWCLK_GSTATE_CONC_NOT_LOCKED     ((uint32_t)0x00008000U)         /* !< G-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWCLK_GSTATE_CONC_LOCKED         ((uint32_t)0x0000C000U)         /* !< G-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWCLK[PIPD] Bits */
#define DEBUGSS_SWCLK_PIPD_OFS                   (16)                            /* !< PIPD Offset */
#define DEBUGSS_SWCLK_PIPD_MASK                  ((uint32_t)0x00010000U)         /* !< Pull down enable */
#define DEBUGSS_SWCLK_PIPD_NO_PULL_DOWN          ((uint32_t)0x00000000U)         /* !< No pull down */
#define DEBUGSS_SWCLK_PIPD_PULL_DOWN             ((uint32_t)0x00010000U)         /* !< Pull down */
/* DEBUGSS_SWCLK[PIPU] Bits */
#define DEBUGSS_SWCLK_PIPU_OFS                   (17)                            /* !< PIPU Offset */
#define DEBUGSS_SWCLK_PIPU_MASK                  ((uint32_t)0x00020000U)         /* !< Pull up enable */
#define DEBUGSS_SWCLK_PIPU_NO_PULL_UP            ((uint32_t)0x00000000U)         /* !< No pull up */
#define DEBUGSS_SWCLK_PIPU_PULL_UP               ((uint32_t)0x00020000U)         /* !< Pull up */
/* DEBUGSS_SWCLK[INENA] Bits */
#define DEBUGSS_SWCLK_INENA_OFS                  (18)                            /* !< INENA Offset */
#define DEBUGSS_SWCLK_INENA_MASK                 ((uint32_t)0x00040000U)         /* !< Input enable */
#define DEBUGSS_SWCLK_INENA_INP_DISABLE          ((uint32_t)0x00000000U)         /* !< Inputs 0 to connected core */
#define DEBUGSS_SWCLK_INENA_INP_ENABLE           ((uint32_t)0x00040000U)         /* !< Inputs IO pad value to connected
                                                                                    core */
/* DEBUGSS_SWCLK[HYSTEN] Bits */
#define DEBUGSS_SWCLK_HYSTEN_OFS                 (19)                            /* !< HYSTEN Offset */
#define DEBUGSS_SWCLK_HYSTEN_MASK                ((uint32_t)0x00080000U)         /* !< Hysteresis enable */
#define DEBUGSS_SWCLK_HYSTEN_DIS_HYST            ((uint32_t)0x00000000U)         /* !< No hysteresis */
#define DEBUGSS_SWCLK_HYSTEN_EN_HYST             ((uint32_t)0x00080000U)         /* !< Hysteresis on */
/* DEBUGSS_SWCLK[DRV] Bits */
#define DEBUGSS_SWCLK_DRV_OFS                    (20)                            /* !< DRV Offset */
#define DEBUGSS_SWCLK_DRV_MASK                   ((uint32_t)0x00700000U)         /* !< Drive strength options */
#define DEBUGSS_SWCLK_DRV_STRENGTH_0             ((uint32_t)0x00000000U)         /* !< Lowest drive strength */
#define DEBUGSS_SWCLK_DRV_STRENGTH_1             ((uint32_t)0x00100000U)         /* !< Drive strength 2/8 */
#define DEBUGSS_SWCLK_DRV_STRENGTH_2             ((uint32_t)0x00200000U)         /* !< Drive strength 3/8 */
#define DEBUGSS_SWCLK_DRV_STRENGTH_3             ((uint32_t)0x00300000U)         /* !< Drive strength 4/8 */
#define DEBUGSS_SWCLK_DRV_STRENGTH_4             ((uint32_t)0x00400000U)         /* !< Drive strength 5/8 */
#define DEBUGSS_SWCLK_DRV_STRENGTH_5             ((uint32_t)0x00500000U)         /* !< Drive strength 6/8 */
#define DEBUGSS_SWCLK_DRV_STRENGTH_6             ((uint32_t)0x00600000U)         /* !< Drive strength 7/8 */
#define DEBUGSS_SWCLK_DRV_STRENGTH_7             ((uint32_t)0x00700000U)         /* !< Highest drive strength */
/* DEBUGSS_SWCLK[HIGHZ0] Bits */
#define DEBUGSS_SWCLK_HIGHZ0_OFS                 (24)                            /* !< HIGHZ0 Offset */
#define DEBUGSS_SWCLK_HIGHZ0_MASK                ((uint32_t)0x01000000U)         /* !< High-Z instead of low output */
#define DEBUGSS_SWCLK_HIGHZ0_DRV_LOW             ((uint32_t)0x00000000U)         /* !< Pin can be driven low */
#define DEBUGSS_SWCLK_HIGHZ0_DRV_HIZ             ((uint32_t)0x01000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    low */
/* DEBUGSS_SWCLK[HIGHZ1] Bits */
#define DEBUGSS_SWCLK_HIGHZ1_OFS                 (25)                            /* !< HIGHZ1 Offset */
#define DEBUGSS_SWCLK_HIGHZ1_MASK                ((uint32_t)0x02000000U)         /* !< High-Z instead of high output */
#define DEBUGSS_SWCLK_HIGHZ1_DRV_HIGH            ((uint32_t)0x00000000U)         /* !< Pin can be driven high */
#define DEBUGSS_SWCLK_HIGHZ1_DRV_HIZ             ((uint32_t)0x02000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    high */
/* DEBUGSS_SWCLK[INV] Bits */
#define DEBUGSS_SWCLK_INV_OFS                    (26)                            /* !< INV Offset */
#define DEBUGSS_SWCLK_INV_MASK                   ((uint32_t)0x04000000U)         /* !< Invert digital input/output
                                                                                    relative to peripheral/GPIO */
#define DEBUGSS_SWCLK_INV_NO_CHNG                ((uint32_t)0x00000000U)         /* !< Input and output are non-inverted */
#define DEBUGSS_SWCLK_INV_CHNG                   ((uint32_t)0x04000000U)         /* !< Input and output are inverted */
/* DEBUGSS_SWCLK[WUEN] Bits */
#define DEBUGSS_SWCLK_WUEN_OFS                   (27)                            /* !< WUEN Offset */
#define DEBUGSS_SWCLK_WUEN_MASK                  ((uint32_t)0x08000000U)         /* !< Wake up enable */
#define DEBUGSS_SWCLK_WUEN_NO_WAKEUP             ((uint32_t)0x00000000U)         /* !< Wake up not enabled */
#define DEBUGSS_SWCLK_WUEN_WAKEUP                ((uint32_t)0x08000000U)         /* !< Wake up enabled */
/* DEBUGSS_SWCLK[WCOMP] Bits */
#define DEBUGSS_SWCLK_WCOMP_OFS                  (28)                            /* !< WCOMP Offset */
#define DEBUGSS_SWCLK_WCOMP_MASK                 ((uint32_t)0x10000000U)         /* !< Wake up compare value */
#define DEBUGSS_SWCLK_WCOMP_MATCH_ZERO           ((uint32_t)0x00000000U)         /* !< Match 0 will wake */
#define DEBUGSS_SWCLK_WCOMP_MATCH_ONE            ((uint32_t)0x10000000U)         /* !< Match 1 will wake */

/* DEBUGSS_SWDIO Bits */
/* DEBUGSS_SWDIO[PSTATE] Bits */
#define DEBUGSS_SWDIO_PSTATE_OFS                 (6)                             /* !< PSTATE Offset */
#define DEBUGSS_SWDIO_PSTATE_MASK                ((uint32_t)0x000000C0U)         /* !< Peripheral-Analog Channel State */
#define DEBUGSS_SWDIO_PSTATE_UNASSIGNED          ((uint32_t)0x00000000U)         /* !< P-Channel is in Unassigned State */
#define DEBUGSS_SWDIO_PSTATE_HANDOVER            ((uint32_t)0x00000040U)         /* !< P-Channel is in Handover State */
#define DEBUGSS_SWDIO_PSTATE_CONC_NOT_LOCKED     ((uint32_t)0x00000080U)         /* !< P-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWDIO_PSTATE_CONC_LOCKED         ((uint32_t)0x000000C0U)         /* !< P-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWDIO[GSTATE] Bits */
#define DEBUGSS_SWDIO_GSTATE_OFS                 (14)                            /* !< GSTATE Offset */
#define DEBUGSS_SWDIO_GSTATE_MASK                ((uint32_t)0x0000C000U)         /* !< GPIO Channel State */
#define DEBUGSS_SWDIO_GSTATE_UNASSIGNED          ((uint32_t)0x00000000U)         /* !< G-Channel is in Unassigned State */
#define DEBUGSS_SWDIO_GSTATE_HANDOVER            ((uint32_t)0x00004000U)         /* !< G-Channel is in Handover State */
#define DEBUGSS_SWDIO_GSTATE_CONC_NOT_LOCKED     ((uint32_t)0x00008000U)         /* !< G-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWDIO_GSTATE_CONC_LOCKED         ((uint32_t)0x0000C000U)         /* !< G-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWDIO[PIPD] Bits */
#define DEBUGSS_SWDIO_PIPD_OFS                   (16)                            /* !< PIPD Offset */
#define DEBUGSS_SWDIO_PIPD_MASK                  ((uint32_t)0x00010000U)         /* !< Pull down enable */
#define DEBUGSS_SWDIO_PIPD_NO_PULL_DOWN          ((uint32_t)0x00000000U)         /* !< No pull down */
#define DEBUGSS_SWDIO_PIPD_PULL_DOWN             ((uint32_t)0x00010000U)         /* !< Pull down */
/* DEBUGSS_SWDIO[PIPU] Bits */
#define DEBUGSS_SWDIO_PIPU_OFS                   (17)                            /* !< PIPU Offset */
#define DEBUGSS_SWDIO_PIPU_MASK                  ((uint32_t)0x00020000U)         /* !< Pull up enable */
#define DEBUGSS_SWDIO_PIPU_NO_PULL_UP            ((uint32_t)0x00000000U)         /* !< No pull up */
#define DEBUGSS_SWDIO_PIPU_PULL_UP               ((uint32_t)0x00020000U)         /* !< Pull up */
/* DEBUGSS_SWDIO[INENA] Bits */
#define DEBUGSS_SWDIO_INENA_OFS                  (18)                            /* !< INENA Offset */
#define DEBUGSS_SWDIO_INENA_MASK                 ((uint32_t)0x00040000U)         /* !< Input enable */
#define DEBUGSS_SWDIO_INENA_INP_DISABLE          ((uint32_t)0x00000000U)         /* !< Inputs 0 to connected core */
#define DEBUGSS_SWDIO_INENA_INP_ENABLE           ((uint32_t)0x00040000U)         /* !< Inputs IO pad value to connected
                                                                                    core */
/* DEBUGSS_SWDIO[HYSTEN] Bits */
#define DEBUGSS_SWDIO_HYSTEN_OFS                 (19)                            /* !< HYSTEN Offset */
#define DEBUGSS_SWDIO_HYSTEN_MASK                ((uint32_t)0x00080000U)         /* !< Hysteresis enable */
#define DEBUGSS_SWDIO_HYSTEN_DIS_HYST            ((uint32_t)0x00000000U)         /* !< No hysteresis */
#define DEBUGSS_SWDIO_HYSTEN_EN_HYST             ((uint32_t)0x00080000U)         /* !< Hysteresis on */
/* DEBUGSS_SWDIO[DRV] Bits */
#define DEBUGSS_SWDIO_DRV_OFS                    (20)                            /* !< DRV Offset */
#define DEBUGSS_SWDIO_DRV_MASK                   ((uint32_t)0x00700000U)         /* !< Drive strength options */
#define DEBUGSS_SWDIO_DRV_STRENGTH_0             ((uint32_t)0x00000000U)         /* !< Lowest drive strength */
#define DEBUGSS_SWDIO_DRV_STRENGTH_1             ((uint32_t)0x00100000U)         /* !< Drive strength 2/8 */
#define DEBUGSS_SWDIO_DRV_STRENGTH_2             ((uint32_t)0x00200000U)         /* !< Drive strength 3/8 */
#define DEBUGSS_SWDIO_DRV_STRENGTH_3             ((uint32_t)0x00300000U)         /* !< Drive strength 4/8 */
#define DEBUGSS_SWDIO_DRV_STRENGTH_4             ((uint32_t)0x00400000U)         /* !< Drive strength 5/8 */
#define DEBUGSS_SWDIO_DRV_STRENGTH_5             ((uint32_t)0x00500000U)         /* !< Drive strength 6/8 */
#define DEBUGSS_SWDIO_DRV_STRENGTH_6             ((uint32_t)0x00600000U)         /* !< Drive strength 7/8 */
#define DEBUGSS_SWDIO_DRV_STRENGTH_7             ((uint32_t)0x00700000U)         /* !< Highest drive strength */
/* DEBUGSS_SWDIO[HIGHZ0] Bits */
#define DEBUGSS_SWDIO_HIGHZ0_OFS                 (24)                            /* !< HIGHZ0 Offset */
#define DEBUGSS_SWDIO_HIGHZ0_MASK                ((uint32_t)0x01000000U)         /* !< High-Z instead of low output */
#define DEBUGSS_SWDIO_HIGHZ0_DRV_LOW             ((uint32_t)0x00000000U)         /* !< Pin can be driven low */
#define DEBUGSS_SWDIO_HIGHZ0_DRV_HIZ             ((uint32_t)0x01000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    low */
/* DEBUGSS_SWDIO[HIGHZ1] Bits */
#define DEBUGSS_SWDIO_HIGHZ1_OFS                 (25)                            /* !< HIGHZ1 Offset */
#define DEBUGSS_SWDIO_HIGHZ1_MASK                ((uint32_t)0x02000000U)         /* !< High-Z instead of high output */
#define DEBUGSS_SWDIO_HIGHZ1_DRV_HIGH            ((uint32_t)0x00000000U)         /* !< Pin can be driven high */
#define DEBUGSS_SWDIO_HIGHZ1_DRV_HIZ             ((uint32_t)0x02000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    high */
/* DEBUGSS_SWDIO[INV] Bits */
#define DEBUGSS_SWDIO_INV_OFS                    (26)                            /* !< INV Offset */
#define DEBUGSS_SWDIO_INV_MASK                   ((uint32_t)0x04000000U)         /* !< Invert digital input/output
                                                                                    relative to peripheral/GPIO */
#define DEBUGSS_SWDIO_INV_NO_CHNG                ((uint32_t)0x00000000U)         /* !< Input and output are non-inverted */
#define DEBUGSS_SWDIO_INV_CHNG                   ((uint32_t)0x04000000U)         /* !< Input and output are inverted */
/* DEBUGSS_SWDIO[WUEN] Bits */
#define DEBUGSS_SWDIO_WUEN_OFS                   (27)                            /* !< WUEN Offset */
#define DEBUGSS_SWDIO_WUEN_MASK                  ((uint32_t)0x08000000U)         /* !< Wake up enable */
#define DEBUGSS_SWDIO_WUEN_NO_WAKEUP             ((uint32_t)0x00000000U)         /* !< Wake up not enabled */
#define DEBUGSS_SWDIO_WUEN_WAKEUP                ((uint32_t)0x08000000U)         /* !< Wake up enabled */
/* DEBUGSS_SWDIO[WCOMP] Bits */
#define DEBUGSS_SWDIO_WCOMP_OFS                  (28)                            /* !< WCOMP Offset */
#define DEBUGSS_SWDIO_WCOMP_MASK                 ((uint32_t)0x10000000U)         /* !< Wake up compare value */
#define DEBUGSS_SWDIO_WCOMP_MATCH_ZERO           ((uint32_t)0x00000000U)         /* !< Match 0 will wake */
#define DEBUGSS_SWDIO_WCOMP_MATCH_ONE            ((uint32_t)0x10000000U)         /* !< Match 1 will wake */

/* DEBUGSS_SWCLK_ALT Bits */
/* DEBUGSS_SWCLK_ALT[PSTATE] Bits */
#define DEBUGSS_SWCLK_ALT_PSTATE_OFS             (6)                             /* !< PSTATE Offset */
#define DEBUGSS_SWCLK_ALT_PSTATE_MASK            ((uint32_t)0x000000C0U)         /* !< Peripheral-Analog Channel State */
#define DEBUGSS_SWCLK_ALT_PSTATE_UNASSIGNED      ((uint32_t)0x00000000U)         /* !< P-Channel is in Unassigned State */
#define DEBUGSS_SWCLK_ALT_PSTATE_HANDOVER        ((uint32_t)0x00000040U)         /* !< P-Channel is in Handover State */
#define DEBUGSS_SWCLK_ALT_PSTATE_CONC_NOT_LOCKED ((uint32_t)0x00000080U)         /* !< P-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWCLK_ALT_PSTATE_CONC_LOCKED     ((uint32_t)0x000000C0U)         /* !< P-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWCLK_ALT[GSTATE] Bits */
#define DEBUGSS_SWCLK_ALT_GSTATE_OFS             (14)                            /* !< GSTATE Offset */
#define DEBUGSS_SWCLK_ALT_GSTATE_MASK            ((uint32_t)0x0000C000U)         /* !< GPIO Channel State */
#define DEBUGSS_SWCLK_ALT_GSTATE_UNASSIGNED      ((uint32_t)0x00000000U)         /* !< G-Channel is in Unassigned State */
#define DEBUGSS_SWCLK_ALT_GSTATE_HANDOVER        ((uint32_t)0x00004000U)         /* !< G-Channel is in Handover State */
#define DEBUGSS_SWCLK_ALT_GSTATE_CONC_NOT_LOCKED ((uint32_t)0x00008000U)         /* !< G-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWCLK_ALT_GSTATE_CONC_LOCKED     ((uint32_t)0x0000C000U)         /* !< G-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWCLK_ALT[PIPD] Bits */
#define DEBUGSS_SWCLK_ALT_PIPD_OFS               (16)                            /* !< PIPD Offset */
#define DEBUGSS_SWCLK_ALT_PIPD_MASK              ((uint32_t)0x00010000U)         /* !< Pull down enable */
#define DEBUGSS_SWCLK_ALT_PIPD_NO_PULL_DOWN      ((uint32_t)0x00000000U)         /* !< No pull down */
#define DEBUGSS_SWCLK_ALT_PIPD_PULL_DOWN         ((uint32_t)0x00010000U)         /* !< Pull down */
/* DEBUGSS_SWCLK_ALT[PIPU] Bits */
#define DEBUGSS_SWCLK_ALT_PIPU_OFS               (17)                            /* !< PIPU Offset */
#define DEBUGSS_SWCLK_ALT_PIPU_MASK              ((uint32_t)0x00020000U)         /* !< Pull up enable */
#define DEBUGSS_SWCLK_ALT_PIPU_NO_PULL_UP        ((uint32_t)0x00000000U)         /* !< No pull up */
#define DEBUGSS_SWCLK_ALT_PIPU_PULL_UP           ((uint32_t)0x00020000U)         /* !< Pull up */
/* DEBUGSS_SWCLK_ALT[INENA] Bits */
#define DEBUGSS_SWCLK_ALT_INENA_OFS              (18)                            /* !< INENA Offset */
#define DEBUGSS_SWCLK_ALT_INENA_MASK             ((uint32_t)0x00040000U)         /* !< Input enable */
#define DEBUGSS_SWCLK_ALT_INENA_INP_DISABLE      ((uint32_t)0x00000000U)         /* !< Inputs 0 to connected core */
#define DEBUGSS_SWCLK_ALT_INENA_INP_ENABLE       ((uint32_t)0x00040000U)         /* !< Inputs IO pad value to connected
                                                                                    core */
/* DEBUGSS_SWCLK_ALT[HYSTEN] Bits */
#define DEBUGSS_SWCLK_ALT_HYSTEN_OFS             (19)                            /* !< HYSTEN Offset */
#define DEBUGSS_SWCLK_ALT_HYSTEN_MASK            ((uint32_t)0x00080000U)         /* !< Hysteresis enable */
#define DEBUGSS_SWCLK_ALT_HYSTEN_DIS_HYST        ((uint32_t)0x00000000U)         /* !< No hysteresis */
#define DEBUGSS_SWCLK_ALT_HYSTEN_EN_HYST         ((uint32_t)0x00080000U)         /* !< Hysteresis on */
/* DEBUGSS_SWCLK_ALT[DRV] Bits */
#define DEBUGSS_SWCLK_ALT_DRV_OFS                (20)                            /* !< DRV Offset */
#define DEBUGSS_SWCLK_ALT_DRV_MASK               ((uint32_t)0x00700000U)         /* !< Drive strength options */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_0         ((uint32_t)0x00000000U)         /* !< Lowest drive strength */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_1         ((uint32_t)0x00100000U)         /* !< Drive strength 2/8 */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_2         ((uint32_t)0x00200000U)         /* !< Drive strength 3/8 */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_3         ((uint32_t)0x00300000U)         /* !< Drive strength 4/8 */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_4         ((uint32_t)0x00400000U)         /* !< Drive strength 5/8 */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_5         ((uint32_t)0x00500000U)         /* !< Drive strength 6/8 */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_6         ((uint32_t)0x00600000U)         /* !< Drive strength 7/8 */
#define DEBUGSS_SWCLK_ALT_DRV_STRENGTH_7         ((uint32_t)0x00700000U)         /* !< Highest drive strength */
/* DEBUGSS_SWCLK_ALT[HIGHZ0] Bits */
#define DEBUGSS_SWCLK_ALT_HIGHZ0_OFS             (24)                            /* !< HIGHZ0 Offset */
#define DEBUGSS_SWCLK_ALT_HIGHZ0_MASK            ((uint32_t)0x01000000U)         /* !< High-Z instead of low output */
#define DEBUGSS_SWCLK_ALT_HIGHZ0_DRV_LOW         ((uint32_t)0x00000000U)         /* !< Pin can be driven low */
#define DEBUGSS_SWCLK_ALT_HIGHZ0_DRV_HIZ         ((uint32_t)0x01000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    low */
/* DEBUGSS_SWCLK_ALT[HIGHZ1] Bits */
#define DEBUGSS_SWCLK_ALT_HIGHZ1_OFS             (25)                            /* !< HIGHZ1 Offset */
#define DEBUGSS_SWCLK_ALT_HIGHZ1_MASK            ((uint32_t)0x02000000U)         /* !< High-Z instead of high output */
#define DEBUGSS_SWCLK_ALT_HIGHZ1_DRV_HIGH        ((uint32_t)0x00000000U)         /* !< Pin can be driven high */
#define DEBUGSS_SWCLK_ALT_HIGHZ1_DRV_HIZ         ((uint32_t)0x02000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    high */
/* DEBUGSS_SWCLK_ALT[INV] Bits */
#define DEBUGSS_SWCLK_ALT_INV_OFS                (26)                            /* !< INV Offset */
#define DEBUGSS_SWCLK_ALT_INV_MASK               ((uint32_t)0x04000000U)         /* !< Invert digital input/output
                                                                                    relative to peripheral/GPIO */
#define DEBUGSS_SWCLK_ALT_INV_NO_CHNG            ((uint32_t)0x00000000U)         /* !< Input and output are non-inverted */
#define DEBUGSS_SWCLK_ALT_INV_CHNG               ((uint32_t)0x04000000U)         /* !< Input and output are inverted */
/* DEBUGSS_SWCLK_ALT[WUEN] Bits */
#define DEBUGSS_SWCLK_ALT_WUEN_OFS               (27)                            /* !< WUEN Offset */
#define DEBUGSS_SWCLK_ALT_WUEN_MASK              ((uint32_t)0x08000000U)         /* !< Wake up enable */
#define DEBUGSS_SWCLK_ALT_WUEN_NO_WAKEUP         ((uint32_t)0x00000000U)         /* !< Wake up not enabled */
#define DEBUGSS_SWCLK_ALT_WUEN_WAKEUP            ((uint32_t)0x08000000U)         /* !< Wake up enabled */
/* DEBUGSS_SWCLK_ALT[WCOMP] Bits */
#define DEBUGSS_SWCLK_ALT_WCOMP_OFS              (28)                            /* !< WCOMP Offset */
#define DEBUGSS_SWCLK_ALT_WCOMP_MASK             ((uint32_t)0x10000000U)         /* !< Wake up compare value */
#define DEBUGSS_SWCLK_ALT_WCOMP_MATCH_ZERO       ((uint32_t)0x00000000U)         /* !< Match 0 will wake */
#define DEBUGSS_SWCLK_ALT_WCOMP_MATCH_ONE        ((uint32_t)0x10000000U)         /* !< Match 1 will wake */

/* DEBUGSS_SWDIO_ALT Bits */
/* DEBUGSS_SWDIO_ALT[PSTATE] Bits */
#define DEBUGSS_SWDIO_ALT_PSTATE_OFS             (6)                             /* !< PSTATE Offset */
#define DEBUGSS_SWDIO_ALT_PSTATE_MASK            ((uint32_t)0x000000C0U)         /* !< Peripheral-Analog Channel State */
#define DEBUGSS_SWDIO_ALT_PSTATE_UNASSIGNED      ((uint32_t)0x00000000U)         /* !< P-Channel is in Unassigned State */
#define DEBUGSS_SWDIO_ALT_PSTATE_HANDOVER        ((uint32_t)0x00000040U)         /* !< P-Channel is in Handover State */
#define DEBUGSS_SWDIO_ALT_PSTATE_CONC_NOT_LOCKED ((uint32_t)0x00000080U)         /* !< P-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWDIO_ALT_PSTATE_CONC_LOCKED     ((uint32_t)0x000000C0U)         /* !< P-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWDIO_ALT[GSTATE] Bits */
#define DEBUGSS_SWDIO_ALT_GSTATE_OFS             (14)                            /* !< GSTATE Offset */
#define DEBUGSS_SWDIO_ALT_GSTATE_MASK            ((uint32_t)0x0000C000U)         /* !< GPIO Channel State */
#define DEBUGSS_SWDIO_ALT_GSTATE_UNASSIGNED      ((uint32_t)0x00000000U)         /* !< G-Channel is in Unassigned State */
#define DEBUGSS_SWDIO_ALT_GSTATE_HANDOVER        ((uint32_t)0x00004000U)         /* !< G-Channel is in Handover State */
#define DEBUGSS_SWDIO_ALT_GSTATE_CONC_NOT_LOCKED ((uint32_t)0x00008000U)         /* !< G-Channel is in Connected State and
                                                                                    not Locked (That is F field is
                                                                                    allowed to change without going back
                                                                                    through Unassigned state) */
#define DEBUGSS_SWDIO_ALT_GSTATE_CONC_LOCKED     ((uint32_t)0x0000C000U)         /* !< G-Channel is in Connected State and
                                                                                    Locked (That is F field is not
                                                                                    allowed to change to a different
                                                                                    non-Zero value until both G and P
                                                                                    channels go to Unassigned) */
/* DEBUGSS_SWDIO_ALT[PIPD] Bits */
#define DEBUGSS_SWDIO_ALT_PIPD_OFS               (16)                            /* !< PIPD Offset */
#define DEBUGSS_SWDIO_ALT_PIPD_MASK              ((uint32_t)0x00010000U)         /* !< Pull down enable */
#define DEBUGSS_SWDIO_ALT_PIPD_NO_PULL_DOWN      ((uint32_t)0x00000000U)         /* !< No pull down */
#define DEBUGSS_SWDIO_ALT_PIPD_PULL_DOWN         ((uint32_t)0x00010000U)         /* !< Pull down */
/* DEBUGSS_SWDIO_ALT[PIPU] Bits */
#define DEBUGSS_SWDIO_ALT_PIPU_OFS               (17)                            /* !< PIPU Offset */
#define DEBUGSS_SWDIO_ALT_PIPU_MASK              ((uint32_t)0x00020000U)         /* !< Pull up enable */
#define DEBUGSS_SWDIO_ALT_PIPU_NO_PULL_UP        ((uint32_t)0x00000000U)         /* !< No pull up */
#define DEBUGSS_SWDIO_ALT_PIPU_PULL_UP           ((uint32_t)0x00020000U)         /* !< Pull up */
/* DEBUGSS_SWDIO_ALT[INENA] Bits */
#define DEBUGSS_SWDIO_ALT_INENA_OFS              (18)                            /* !< INENA Offset */
#define DEBUGSS_SWDIO_ALT_INENA_MASK             ((uint32_t)0x00040000U)         /* !< Input enable */
#define DEBUGSS_SWDIO_ALT_INENA_INP_DISABLE      ((uint32_t)0x00000000U)         /* !< Inputs 0 to connected core */
#define DEBUGSS_SWDIO_ALT_INENA_INP_ENABLE       ((uint32_t)0x00040000U)         /* !< Inputs IO pad value to connected
                                                                                    core */
/* DEBUGSS_SWDIO_ALT[HYSTEN] Bits */
#define DEBUGSS_SWDIO_ALT_HYSTEN_OFS             (19)                            /* !< HYSTEN Offset */
#define DEBUGSS_SWDIO_ALT_HYSTEN_MASK            ((uint32_t)0x00080000U)         /* !< Hysteresis enable */
#define DEBUGSS_SWDIO_ALT_HYSTEN_DIS_HYST        ((uint32_t)0x00000000U)         /* !< No hysteresis */
#define DEBUGSS_SWDIO_ALT_HYSTEN_EN_HYST         ((uint32_t)0x00080000U)         /* !< Hysteresis on */
/* DEBUGSS_SWDIO_ALT[DRV] Bits */
#define DEBUGSS_SWDIO_ALT_DRV_OFS                (20)                            /* !< DRV Offset */
#define DEBUGSS_SWDIO_ALT_DRV_MASK               ((uint32_t)0x00700000U)         /* !< Drive strength options */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_0         ((uint32_t)0x00000000U)         /* !< Lowest drive strength */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_1         ((uint32_t)0x00100000U)         /* !< Drive strength 2/8 */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_2         ((uint32_t)0x00200000U)         /* !< Drive strength 3/8 */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_3         ((uint32_t)0x00300000U)         /* !< Drive strength 4/8 */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_4         ((uint32_t)0x00400000U)         /* !< Drive strength 5/8 */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_5         ((uint32_t)0x00500000U)         /* !< Drive strength 6/8 */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_6         ((uint32_t)0x00600000U)         /* !< Drive strength 7/8 */
#define DEBUGSS_SWDIO_ALT_DRV_STRENGTH_7         ((uint32_t)0x00700000U)         /* !< Highest drive strength */
/* DEBUGSS_SWDIO_ALT[HIGHZ0] Bits */
#define DEBUGSS_SWDIO_ALT_HIGHZ0_OFS             (24)                            /* !< HIGHZ0 Offset */
#define DEBUGSS_SWDIO_ALT_HIGHZ0_MASK            ((uint32_t)0x01000000U)         /* !< High-Z instead of low output */
#define DEBUGSS_SWDIO_ALT_HIGHZ0_DRV_LOW         ((uint32_t)0x00000000U)         /* !< Pin can be driven low */
#define DEBUGSS_SWDIO_ALT_HIGHZ0_DRV_HIZ         ((uint32_t)0x01000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    low */
/* DEBUGSS_SWDIO_ALT[HIGHZ1] Bits */
#define DEBUGSS_SWDIO_ALT_HIGHZ1_OFS             (25)                            /* !< HIGHZ1 Offset */
#define DEBUGSS_SWDIO_ALT_HIGHZ1_MASK            ((uint32_t)0x02000000U)         /* !< High-Z instead of high output */
#define DEBUGSS_SWDIO_ALT_HIGHZ1_DRV_HIGH        ((uint32_t)0x00000000U)         /* !< Pin can be driven high */
#define DEBUGSS_SWDIO_ALT_HIGHZ1_DRV_HIZ         ((uint32_t)0x02000000U)         /* !< Pin is tri-stated instead of driven
                                                                                    high */
/* DEBUGSS_SWDIO_ALT[INV] Bits */
#define DEBUGSS_SWDIO_ALT_INV_OFS                (26)                            /* !< INV Offset */
#define DEBUGSS_SWDIO_ALT_INV_MASK               ((uint32_t)0x04000000U)         /* !< Invert digital input/output
                                                                                    relative to peripheral/GPIO */
#define DEBUGSS_SWDIO_ALT_INV_NO_CHNG            ((uint32_t)0x00000000U)         /* !< Input and output are non-inverted */
#define DEBUGSS_SWDIO_ALT_INV_CHNG               ((uint32_t)0x04000000U)         /* !< Input and output are inverted */
/* DEBUGSS_SWDIO_ALT[WUEN] Bits */
#define DEBUGSS_SWDIO_ALT_WUEN_OFS               (27)                            /* !< WUEN Offset */
#define DEBUGSS_SWDIO_ALT_WUEN_MASK              ((uint32_t)0x08000000U)         /* !< Wake up enable */
#define DEBUGSS_SWDIO_ALT_WUEN_NO_WAKEUP         ((uint32_t)0x00000000U)         /* !< Wake up not enabled */
#define DEBUGSS_SWDIO_ALT_WUEN_WAKEUP            ((uint32_t)0x08000000U)         /* !< Wake up enabled */
/* DEBUGSS_SWDIO_ALT[WCOMP] Bits */
#define DEBUGSS_SWDIO_ALT_WCOMP_OFS              (28)                            /* !< WCOMP Offset */
#define DEBUGSS_SWDIO_ALT_WCOMP_MASK             ((uint32_t)0x10000000U)         /* !< Wake up compare value */
#define DEBUGSS_SWDIO_ALT_WCOMP_MATCH_ZERO       ((uint32_t)0x00000000U)         /* !< Match 0 will wake */
#define DEBUGSS_SWDIO_ALT_WCOMP_MATCH_ONE        ((uint32_t)0x10000000U)         /* !< Match 1 will wake */

/* DEBUGSS_CPU_CONNECT_0 Bits */
/* DEBUGSS_CPU_CONNECT_0[CPUSS0_CONN] Bits */
#define DEBUGSS_CPU_CONNECT_0_CPUSS0_CONN_OFS    (1)                             /* !< CPUSS0_CONN Offset */
#define DEBUGSS_CPU_CONNECT_0_CPUSS0_CONN_MASK   ((uint32_t)0x00000002U)         /* !< CPUSS0 connect bit. */
#define DEBUGSS_CPU_CONNECT_0_CPUSS0_CONN_UNCONNECTED ((uint32_t)0x00000000U)         /* !< The CPU is not connected. */
#define DEBUGSS_CPU_CONNECT_0_CPUSS0_CONN_CONNECTED ((uint32_t)0x00000002U)         /* !< The CPU is connected. */

/* DEBUGSS_EVT_MODE Bits */
/* DEBUGSS_EVT_MODE[INT0_CFG] Bits */
#define DEBUGSS_EVT_MODE_INT0_CFG_OFS            (0)                             /* !< INT0_CFG Offset */
#define DEBUGSS_EVT_MODE_INT0_CFG_MASK           ((uint32_t)0x00000003U)         /* !< Event line mode select for
                                                                                    peripheral events */
#define DEBUGSS_EVT_MODE_INT0_CFG_DISABLE        ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define DEBUGSS_EVT_MODE_INT0_CFG_SOFTWARE       ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define DEBUGSS_EVT_MODE_INT0_CFG_HARDWARE       ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* DEBUGSS_DESC Bits */
/* DEBUGSS_DESC[MINREV] Bits */
#define DEBUGSS_DESC_MINREV_OFS                  (0)                             /* !< MINREV Offset */
#define DEBUGSS_DESC_MINREV_MASK                 ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
/* DEBUGSS_DESC[MAJREV] Bits */
#define DEBUGSS_DESC_MAJREV_OFS                  (4)                             /* !< MAJREV Offset */
#define DEBUGSS_DESC_MAJREV_MASK                 ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
/* DEBUGSS_DESC[INSTNUM] Bits */
#define DEBUGSS_DESC_INSTNUM_OFS                 (8)                             /* !< INSTNUM Offset */
#define DEBUGSS_DESC_INSTNUM_MASK                ((uint32_t)0x00000F00U)         /* !< Instance Number within the device.
                                                                                    This will be a parameter to the RTL
                                                                                    for modules that can have multiple
                                                                                    instances */
/* DEBUGSS_DESC[FEATUREVER] Bits */
#define DEBUGSS_DESC_FEATUREVER_OFS              (12)                            /* !< FEATUREVER Offset */
#define DEBUGSS_DESC_FEATUREVER_MASK             ((uint32_t)0x0000F000U)         /* !< Feature Set for the module
                                                                                    *instance* */
/* DEBUGSS_DESC[MODULEID] Bits */
#define DEBUGSS_DESC_MODULEID_OFS                (16)                            /* !< MODULEID Offset */
#define DEBUGSS_DESC_MODULEID_MASK               ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */

/* DEBUGSS_TXD Bits */
/* DEBUGSS_TXD[TX_DATA] Bits */
#define DEBUGSS_TXD_TX_DATA_OFS                  (0)                             /* !< TX_DATA Offset */
#define DEBUGSS_TXD_TX_DATA_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Contains data written by an
                                                                                    external debug tool to the SEC-AP
                                                                                    TXDATA register */

/* DEBUGSS_TXCTL Bits */
/* DEBUGSS_TXCTL[TRANSMIT] Bits */
#define DEBUGSS_TXCTL_TRANSMIT_OFS               (0)                             /* !< TRANSMIT Offset */
#define DEBUGSS_TXCTL_TRANSMIT_MASK              ((uint32_t)0x00000001U)         /* !< Indicates data request in DSSM.TXD,
                                                                                    set on write via Debug AP to
                                                                                    DSSM.TXD.  A read of the DSSM.TXD
                                                                                    register by SW will clear the TX
                                                                                    field. The tool can check that TXD is
                                                                                    empty by reading this field. */
#define DEBUGSS_TXCTL_TRANSMIT_EMPTY             ((uint32_t)0x00000000U)         /* !< TXD is empty */
#define DEBUGSS_TXCTL_TRANSMIT_FULL              ((uint32_t)0x00000001U)         /* !< TXD is full */
/* DEBUGSS_TXCTL[TRANSMIT_FLAGS] Bits */
#define DEBUGSS_TXCTL_TRANSMIT_FLAGS_OFS         (1)                             /* !< TRANSMIT_FLAGS Offset */
#define DEBUGSS_TXCTL_TRANSMIT_FLAGS_MASK        ((uint32_t)0xFFFFFFFEU)         /* !< Generic TX flags that can be set by
                                                                                    external debug tool. Functionality is
                                                                                    defined by SW. */

/* DEBUGSS_RXD Bits */
/* DEBUGSS_RXD[RX_DATA] Bits */
#define DEBUGSS_RXD_RX_DATA_OFS                  (0)                             /* !< RX_DATA Offset */
#define DEBUGSS_RXD_RX_DATA_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< Contains data written by SM/OW. */

/* DEBUGSS_RXCTL Bits */
/* DEBUGSS_RXCTL[RECEIVE] Bits */
#define DEBUGSS_RXCTL_RECEIVE_OFS                (0)                             /* !< RECEIVE Offset */
#define DEBUGSS_RXCTL_RECEIVE_MASK               ((uint32_t)0x00000001U)         /* !< Indicates SW write to the DSSM.RXD
                                                                                    register. A read of the DSSM.RXD
                                                                                    register by SWD Access Port will
                                                                                    clear the RX field. */
#define DEBUGSS_RXCTL_RECEIVE_EMPTY              ((uint32_t)0x00000000U)         /* !< RXD empty */
#define DEBUGSS_RXCTL_RECEIVE_FULL               ((uint32_t)0x00000001U)         /* !< RXD full */
/* DEBUGSS_RXCTL[RECEIVE_FLAGS] Bits */
#define DEBUGSS_RXCTL_RECEIVE_FLAGS_OFS          (1)                             /* !< RECEIVE_FLAGS Offset */
#define DEBUGSS_RXCTL_RECEIVE_FLAGS_MASK         ((uint32_t)0x000000FEU)         /* !< Generic RX flags that can be set by
                                                                                    SW and read by external debug tool.
                                                                                    Functionality is defined by SW. */

/* DEBUGSS_SPECIAL_AUTH Bits */
/* DEBUGSS_SPECIAL_AUTH[SECAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_OFS         (0)                             /* !< SECAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_MASK        ((uint32_t)0x00000001U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can use the
                                                                                    Security-AP to communicate with
                                                                                    security control logic. When
                                                                                    deasserted, a DAPBUS firewall will
                                                                                    isolate the AP and prevent access to
                                                                                    the Security-AP. */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable SEC-AP */
#define DEBUGSS_SPECIAL_AUTH_SECAPEN_ENABLE      ((uint32_t)0x00000001U)         /* !< Enable SEC-AP */
/* DEBUGSS_SPECIAL_AUTH[SWDPORTEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_OFS       (1)                             /* !< SWDPORTEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_MASK      ((uint32_t)0x00000002U)         /* !< When asserted, the SW-DP functions
                                                                                    normally.  When deasserted, the SW-DP
                                                                                    effectively disables all external
                                                                                    debug access. */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_DISABLE   ((uint32_t)0x00000000U)         /* !< Disable SWD port */
#define DEBUGSS_SPECIAL_AUTH_SWDPORTEN_ENABLE    ((uint32_t)0x00000002U)         /* !< Enable SWD port */
/* DEBUGSS_SPECIAL_AUTH[DFTAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_OFS         (2)                             /* !< DFTAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_MASK        ((uint32_t)0x00000004U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can then access the
                                                                                    DFT-AP external to the DebugSS lite.
                                                                                    When deasserted, a DAPBUS firewall
                                                                                    will isolate the AP and prevent
                                                                                    access. */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable DFT-TAP */
#define DEBUGSS_SPECIAL_AUTH_DFTAPEN_ENABLE      ((uint32_t)0x00000004U)         /* !< Enable DFT-TAP */
/* DEBUGSS_SPECIAL_AUTH[ETAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_OFS          (3)                             /* !< ETAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_MASK         ((uint32_t)0x00000008U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can then access an
                                                                                    ET-AP external to the DebugSS lite.
                                                                                    When deasserted, a DAPBUS firewall
                                                                                    will isolate the AP and prevent
                                                                                    access. */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_DISABLE      ((uint32_t)0x00000000U)         /* !< Disable ET+ -AP */
#define DEBUGSS_SPECIAL_AUTH_ETAPEN_ENABLE       ((uint32_t)0x00000008U)         /* !< Enable ET+ -AP */
/* DEBUGSS_SPECIAL_AUTH[CFGAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_OFS         (4)                             /* !< CFGAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_MASK        ((uint32_t)0x00000010U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can use the Config-AP
                                                                                    to read device configuration
                                                                                    information. When deasserted, a
                                                                                    DAPBUS firewall will isolate the AP
                                                                                    and prevent access to the Config-AP. */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable CFG-AP */
#define DEBUGSS_SPECIAL_AUTH_CFGAPEN_ENABLE      ((uint32_t)0x00000010U)         /* !< Enable CFG-AP */
/* DEBUGSS_SPECIAL_AUTH[AHBAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_OFS         (5)                             /* !< AHBAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_MASK        ((uint32_t)0x00000020U)         /* !< Disabling / enabling debug access
                                                                                    to the M0+ Core via the AHB-AP DAP
                                                                                    bus isolation. */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable AHB-AP */
#define DEBUGSS_SPECIAL_AUTH_AHBAPEN_ENABLE      ((uint32_t)0x00000020U)         /* !< Enable AHB-AP */
/* DEBUGSS_SPECIAL_AUTH[PWRAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_OFS         (6)                             /* !< PWRAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_MASK        ((uint32_t)0x00000040U)         /* !< An active high input. When asserted
                                                                                    (and SWD access is also permitted),
                                                                                    the debug tools can then access the
                                                                                    PWR-AP to power and reset state of
                                                                                    the CPU. When deasserted, a DAPBUS
                                                                                    firewall will isolate the AP and
                                                                                    prevent access. */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_DISABLE     ((uint32_t)0x00000000U)         /* !< Disable PWR-AP */
#define DEBUGSS_SPECIAL_AUTH_PWRAPEN_ENABLE      ((uint32_t)0x00000040U)         /* !< Enable PWR-AP */

/* DEBUGSS_SPECIAL_AUTH_SET Bits */
/* DEBUGSS_SPECIAL_AUTH_SET[SET_SECAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SECAPEN_OFS (0)                             /* !< SET_SECAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SECAPEN_MASK ((uint32_t)0x00000001U)         /* !< This bit sets SECAPEN bit in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SECAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SECAPEN_SET ((uint32_t)0x00000001U)         /* !< Set SECAPEN */
/* DEBUGSS_SPECIAL_AUTH_SET[SET_SWDPORTEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SWDPORTEN_OFS (1)                             /* !< SET_SWDPORTEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SWDPORTEN_MASK ((uint32_t)0x00000002U)         /* !< This bit sets SWDPORTEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SWDPORTEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_SWDPORTEN_SET ((uint32_t)0x00000002U)         /* !< Set SWDPORTEN */
/* DEBUGSS_SPECIAL_AUTH_SET[SET_DFTAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_DFTAPEN_OFS (2)                             /* !< SET_DFTAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_DFTAPEN_MASK ((uint32_t)0x00000004U)         /* !< This bit sets DFTAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_DFTAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_DFTAPEN_SET ((uint32_t)0x00000004U)         /* !< Set DFTTAPEN */
/* DEBUGSS_SPECIAL_AUTH_SET[SET_ETAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_ETAPEN_OFS  (3)                             /* !< SET_ETAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_ETAPEN_MASK ((uint32_t)0x00000008U)         /* !< This bit sets ETAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_ETAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_ETAPEN_SET  ((uint32_t)0x00000008U)         /* !< Set ETAPEN */
/* DEBUGSS_SPECIAL_AUTH_SET[KEY] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_KEY_OFS         (24)                            /* !< KEY Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_KEY_MASK        ((uint32_t)0xFF000000U)         /* !< This field must be written with
                                                                                    0xA5 to be able to set any of the
                                                                                    enable bits. */
#define DEBUGSS_SPECIAL_AUTH_SET_KEY_UNLOCK_W    ((uint32_t)0xA5000000U)         /* !< This field must be written with
                                                                                    0xA5 to be able to set any of the
                                                                                    enable bits */
/* DEBUGSS_SPECIAL_AUTH_SET[SET_AHBAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_AHBAPEN_OFS (5)                             /* !< SET_AHBAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_AHBAPEN_MASK ((uint32_t)0x00000020U)         /* !< This bit sets AHBAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_AHBAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_AHBAPEN_SET ((uint32_t)0x00000020U)         /* !< Set AHBAPEN */
/* DEBUGSS_SPECIAL_AUTH_SET[SET_CFGAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_CFGAPEN_OFS (4)                             /* !< SET_CFGAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_CFGAPEN_MASK ((uint32_t)0x00000010U)         /* !< This bit sets CFGAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_CFGAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_CFGAPEN_SET ((uint32_t)0x00000010U)         /* !< Set CFGAPEN */
/* DEBUGSS_SPECIAL_AUTH_SET[SET_PWRAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_PWRAPEN_OFS (6)                             /* !< SET_PWRAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_PWRAPEN_MASK ((uint32_t)0x00000040U)         /* !< This bit sets PWRAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_PWRAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_SET_SET_PWRAPEN_SET ((uint32_t)0x00000040U)         /* !< Set PWRAPEN */

/* DEBUGSS_SPECIAL_AUTH_CLR Bits */
/* DEBUGSS_SPECIAL_AUTH_CLR[CLR_SECAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SECAPEN_OFS (0)                             /* !< CLR_SECAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SECAPEN_MASK ((uint32_t)0x00000001U)         /* !< This bit clears SECAPEN bit in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SECAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SECAPEN_CLR ((uint32_t)0x00000001U)         /* !< Clear SECAPEN */
/* DEBUGSS_SPECIAL_AUTH_CLR[CLR_SWDPORTEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SWDPORTEN_OFS (1)                             /* !< CLR_SWDPORTEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SWDPORTEN_MASK ((uint32_t)0x00000002U)         /* !< This bit clears SWDPORTEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SWDPORTEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_SWDPORTEN_CLR ((uint32_t)0x00000002U)         /* !< Clears SWDPORTEN */
/* DEBUGSS_SPECIAL_AUTH_CLR[CLR_DFTAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_DFTAPEN_OFS (2)                             /* !< CLR_DFTAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_DFTAPEN_MASK ((uint32_t)0x00000004U)         /* !< This bit clears DFTTAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_DFTAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_DFTAPEN_CLR ((uint32_t)0x00000004U)         /* !< Clear DFTTAPEN */
/* DEBUGSS_SPECIAL_AUTH_CLR[CLR_ETAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_ETAPEN_OFS  (3)                             /* !< CLR_ETAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_ETAPEN_MASK ((uint32_t)0x00000008U)         /* !< This bit clears ETAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_ETAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_ETAPEN_CLR  ((uint32_t)0x00000008U)         /* !< Clear ETAPEN */
/* DEBUGSS_SPECIAL_AUTH_CLR[KEY] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_KEY_OFS         (24)                            /* !< KEY Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_KEY_MASK        ((uint32_t)0xFF000000U)         /* !< This field must be written with
                                                                                    0x22 to be able to clear any of the
                                                                                    enable bits. */
#define DEBUGSS_SPECIAL_AUTH_CLR_KEY_UNLOCK_W    ((uint32_t)0x22000000U)         /* !< This field must be written with
                                                                                    0x22 to be able to clear any of the
                                                                                    enable bits */
/* DEBUGSS_SPECIAL_AUTH_CLR[CLR_AHBAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_AHBAPEN_OFS (5)                             /* !< CLR_AHBAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_AHBAPEN_MASK ((uint32_t)0x00000020U)         /* !< This bit clears AHBAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_AHBAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_AHBAPEN_CLR ((uint32_t)0x00000020U)         /* !< Clear AHBAPEN */
/* DEBUGSS_SPECIAL_AUTH_CLR[CLR_CFGAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_CFGAPEN_OFS (4)                             /* !< CLR_CFGAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_CFGAPEN_MASK ((uint32_t)0x00000010U)         /* !< This bit clears CFGAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_CFGAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_CFGAPEN_CLR ((uint32_t)0x00000010U)         /* !< Clear CFGAPEN */
/* DEBUGSS_SPECIAL_AUTH_CLR[CLR_PWRAPEN] Bits */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_PWRAPEN_OFS (6)                             /* !< CLR_PWRAPEN Offset */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_PWRAPEN_MASK ((uint32_t)0x00000040U)         /* !< This bit clears PWRAPEN in
                                                                                    SPECIAL_AUTH register. */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_PWRAPEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_SPECIAL_AUTH_CLR_CLR_PWRAPEN_CLR ((uint32_t)0x00000040U)         /* !< Clear PWRAPEN */

/* DEBUGSS_APP_AUTH Bits */
/* DEBUGSS_APP_AUTH[DBGEN] Bits */
#define DEBUGSS_APP_AUTH_DBGEN_OFS               (0)                             /* !< DBGEN Offset */
#define DEBUGSS_APP_AUTH_DBGEN_MASK              ((uint32_t)0x00000001U)         /* !< Controls invasive debug enable. */
#define DEBUGSS_APP_AUTH_DBGEN_DISABLE           ((uint32_t)0x00000000U)         /* !< Invasive debug disabled */
#define DEBUGSS_APP_AUTH_DBGEN_ENABLE            ((uint32_t)0x00000001U)         /* !< Invasive debug enabled */
/* DEBUGSS_APP_AUTH[NIDEN] Bits */
#define DEBUGSS_APP_AUTH_NIDEN_OFS               (1)                             /* !< NIDEN Offset */
#define DEBUGSS_APP_AUTH_NIDEN_MASK              ((uint32_t)0x00000002U)         /* !< Controls non-invasive debug enable. */
#define DEBUGSS_APP_AUTH_NIDEN_DISABLE           ((uint32_t)0x00000000U)         /* !< Non-invasive debug disabled */
#define DEBUGSS_APP_AUTH_NIDEN_ENABLE            ((uint32_t)0x00000002U)         /* !< Non-invasive debug enabled */
/* DEBUGSS_APP_AUTH[SPIDEN] Bits */
#define DEBUGSS_APP_AUTH_SPIDEN_OFS              (2)                             /* !< SPIDEN Offset */
#define DEBUGSS_APP_AUTH_SPIDEN_MASK             ((uint32_t)0x00000004U)         /* !< Secure invasive debug enable. */
#define DEBUGSS_APP_AUTH_SPIDEN_DISABLE          ((uint32_t)0x00000000U)         /* !< Invasive debug disabled */
#define DEBUGSS_APP_AUTH_SPIDEN_ENABLE           ((uint32_t)0x00000004U)         /* !< Invasive debug enabled */
/* DEBUGSS_APP_AUTH[SPNIDEN] Bits */
#define DEBUGSS_APP_AUTH_SPNIDEN_OFS             (3)                             /* !< SPNIDEN Offset */
#define DEBUGSS_APP_AUTH_SPNIDEN_MASK            ((uint32_t)0x00000008U)         /* !< Secure non-invasive debug enable. */
#define DEBUGSS_APP_AUTH_SPNIDEN_DISABLE         ((uint32_t)0x00000000U)         /* !< Invasive debug disabled */
#define DEBUGSS_APP_AUTH_SPNIDEN_ENABLE          ((uint32_t)0x00000008U)         /* !< Invasive debug enabled */

/* DEBUGSS_APP_AUTH_SET Bits */
/* DEBUGSS_APP_AUTH_SET[SET_DBGEN] Bits */
#define DEBUGSS_APP_AUTH_SET_SET_DBGEN_OFS       (0)                             /* !< SET_DBGEN Offset */
#define DEBUGSS_APP_AUTH_SET_SET_DBGEN_MASK      ((uint32_t)0x00000001U)         /* !< Sets DBGEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_SET_SET_DBGEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_SET_SET_DBGEN_SET       ((uint32_t)0x00000001U)         /* !< Sets DBGEN */
/* DEBUGSS_APP_AUTH_SET[SET_NIDEN] Bits */
#define DEBUGSS_APP_AUTH_SET_SET_NIDEN_OFS       (1)                             /* !< SET_NIDEN Offset */
#define DEBUGSS_APP_AUTH_SET_SET_NIDEN_MASK      ((uint32_t)0x00000002U)         /* !< Sets NIDEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_SET_SET_NIDEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_SET_SET_NIDEN_SET       ((uint32_t)0x00000002U)         /* !< Sets NIDEN */
/* DEBUGSS_APP_AUTH_SET[KEY] Bits */
#define DEBUGSS_APP_AUTH_SET_KEY_OFS             (24)                            /* !< KEY Offset */
#define DEBUGSS_APP_AUTH_SET_KEY_MASK            ((uint32_t)0xFF000000U)         /* !< This field must be written with
                                                                                    0x39 to be able to set any of the
                                                                                    enable bits. */
#define DEBUGSS_APP_AUTH_SET_KEY_UNLOCK_W        ((uint32_t)0x39000000U)         /* !< This field must be written with
                                                                                    0x39 to be able to clear any of the
                                                                                    enable bits */
/* DEBUGSS_APP_AUTH_SET[SET_SPIDEN] Bits */
#define DEBUGSS_APP_AUTH_SET_SET_SPIDEN_OFS      (2)                             /* !< SET_SPIDEN Offset */
#define DEBUGSS_APP_AUTH_SET_SET_SPIDEN_MASK     ((uint32_t)0x00000004U)         /* !< Sets SPIDEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_SET_SET_SPIDEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_SET_SET_SPIDEN_SET      ((uint32_t)0x00000004U)         /* !< Sets NIDEN */
/* DEBUGSS_APP_AUTH_SET[SET_SPNIDEN] Bits */
#define DEBUGSS_APP_AUTH_SET_SET_SPNIDEN_OFS     (3)                             /* !< SET_SPNIDEN Offset */
#define DEBUGSS_APP_AUTH_SET_SET_SPNIDEN_MASK    ((uint32_t)0x00000008U)         /* !< Sets SPNIDEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_SET_SET_SPNIDEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_SET_SET_SPNIDEN_SET     ((uint32_t)0x00000008U)         /* !< Sets NIDEN */

/* DEBUGSS_APP_AUTH_CLR Bits */
/* DEBUGSS_APP_AUTH_CLR[CLR_DBGEN] Bits */
#define DEBUGSS_APP_AUTH_CLR_CLR_DBGEN_OFS       (0)                             /* !< CLR_DBGEN Offset */
#define DEBUGSS_APP_AUTH_CLR_CLR_DBGEN_MASK      ((uint32_t)0x00000001U)         /* !< Clears DBGEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_CLR_CLR_DBGEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_CLR_CLR_DBGEN_CLR       ((uint32_t)0x00000001U)         /* !< Clears DBGEN */
/* DEBUGSS_APP_AUTH_CLR[CLR_NIDEN] Bits */
#define DEBUGSS_APP_AUTH_CLR_CLR_NIDEN_OFS       (1)                             /* !< CLR_NIDEN Offset */
#define DEBUGSS_APP_AUTH_CLR_CLR_NIDEN_MASK      ((uint32_t)0x00000002U)         /* !< Clears NIDEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_CLR_CLR_NIDEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_CLR_CLR_NIDEN_CLR       ((uint32_t)0x00000002U)         /* !< Clears NIDEN */
/* DEBUGSS_APP_AUTH_CLR[KEY] Bits */
#define DEBUGSS_APP_AUTH_CLR_KEY_OFS             (24)                            /* !< KEY Offset */
#define DEBUGSS_APP_AUTH_CLR_KEY_MASK            ((uint32_t)0xFF000000U)         /* !< This field must be written with
                                                                                    0x7D to be able to clear any of the
                                                                                    enable bits. */
#define DEBUGSS_APP_AUTH_CLR_KEY_UNLOCK_W        ((uint32_t)0x7D000000U)         /* !< This field must be written with
                                                                                    0x7d to be able to clear any of the
                                                                                    enable bits */
/* DEBUGSS_APP_AUTH_CLR[CLR_SPIDEN] Bits */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPIDEN_OFS      (2)                             /* !< CLR_SPIDEN Offset */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPIDEN_MASK     ((uint32_t)0x00000004U)         /* !< Clears SPIDEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPIDEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPIDEN_SET      ((uint32_t)0x00000004U)         /* !< Sets NIDEN */
/* DEBUGSS_APP_AUTH_CLR[CLR_SPNIDEN] Bits */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPNIDEN_OFS     (3)                             /* !< CLR_SPNIDEN Offset */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPNIDEN_MASK    ((uint32_t)0x00000008U)         /* !< Clears SPNIDEN bit in APPCPU0_AUTH
                                                                                    register. */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPNIDEN_NO_EFFECT ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DEBUGSS_APP_AUTH_CLR_CLR_SPNIDEN_SET     ((uint32_t)0x00000008U)         /* !< Sets NIDEN */

/* DEBUGSS_DEVICEID Bits */
/* DEBUGSS_DEVICEID[PRESENT] Bits */
#define DEBUGSS_DEVICEID_PRESENT_OFS             (0)                             /* !< PRESENT Offset */
#define DEBUGSS_DEVICEID_PRESENT_MASK            ((uint32_t)0x00000001U)         /* !< The value of 1 in bit 0 of the
                                                                                    device identification register means
                                                                                    the device idetifiaction is present. */
#define DEBUGSS_DEVICEID_PRESENT_NOK             ((uint32_t)0x00000000U)         /* !< Not-Okay. The Device-ID is not
                                                                                    present. */
#define DEBUGSS_DEVICEID_PRESENT_OK              ((uint32_t)0x00000001U)         /* !< Okay. The Device-ID is present. */
/* DEBUGSS_DEVICEID[MANUFACTURER] Bits */
#define DEBUGSS_DEVICEID_MANUFACTURER_OFS        (1)                             /* !< MANUFACTURER Offset */
#define DEBUGSS_DEVICEID_MANUFACTURER_MASK       ((uint32_t)0x00000FFEU)         /* !< TI's JEDEC bank and company code,
                                                                                    which is 00000010111b. */
#define DEBUGSS_DEVICEID_MANUFACTURER_TIJEDEC    ((uint32_t)0x0000002EU)         /* !< TI's JDEC ID */
/* DEBUGSS_DEVICEID[PARTNUM] Bits */
#define DEBUGSS_DEVICEID_PARTNUM_OFS             (12)                            /* !< PARTNUM Offset */
#define DEBUGSS_DEVICEID_PARTNUM_MASK            ((uint32_t)0x0FFFF000U)         /* !< Part number of the device. */
#define DEBUGSS_DEVICEID_PARTNUM_MIN             ((uint32_t)0x00000000U)         /* !< Minimum part number */
#define DEBUGSS_DEVICEID_PARTNUM_MAX             ((uint32_t)0x0FFFF000U)         /* !< Maximum part number */
/* DEBUGSS_DEVICEID[VERSION] Bits */
#define DEBUGSS_DEVICEID_VERSION_OFS             (28)                            /* !< VERSION Offset */
#define DEBUGSS_DEVICEID_VERSION_MASK            ((uint32_t)0xF0000000U)         /* !< Revision of the device. */
#define DEBUGSS_DEVICEID_VERSION_MIN             ((uint32_t)0x00000000U)         /* !< Minimum revision */
#define DEBUGSS_DEVICEID_VERSION_MAX             ((uint32_t)0xF0000000U)         /* !< Maximium revision */

/* DEBUGSS_USERID Bits */
/* DEBUGSS_USERID[PART] Bits */
#define DEBUGSS_USERID_PART_OFS                  (0)                             /* !< PART Offset */
#define DEBUGSS_USERID_PART_MASK                 ((uint32_t)0x0000FFFFU)         /* !< Bit pattern that uniquely
                                                                                    identifies the part. */
#define DEBUGSS_USERID_PART_MIN                  ((uint32_t)0x00000000U)         /* !< Minimum part number */
#define DEBUGSS_USERID_PART_MAX                  ((uint32_t)0x0000FFFFU)         /* !< Maximum part number */
/* DEBUGSS_USERID[VARIANT] Bits */
#define DEBUGSS_USERID_VARIANT_OFS               (16)                            /* !< VARIANT Offset */
#define DEBUGSS_USERID_VARIANT_MASK              ((uint32_t)0x00FF0000U)         /* !< Bit pattern uniqueley identifies
                                                                                    the variant of the part. */
#define DEBUGSS_USERID_VARIANT_MIN               ((uint32_t)0x00000000U)         /* !< Minimum variant */
#define DEBUGSS_USERID_VARIANT_MAX               ((uint32_t)0x00FF0000U)         /* !< Maximum variant */
/* DEBUGSS_USERID[MINORREV] Bits */
#define DEBUGSS_USERID_MINORREV_OFS              (24)                            /* !< MINORREV Offset */
#define DEBUGSS_USERID_MINORREV_MASK             ((uint32_t)0x0F000000U)         /* !< Monotonic increasing value
                                                                                    indicating a new revision of the
                                                                                    device that preservs compatibility
                                                                                    with lesser minorrev values. */
#define DEBUGSS_USERID_MINORREV_MIN              ((uint32_t)0x00000000U)         /* !< Minimum minor revision */
#define DEBUGSS_USERID_MINORREV_MAX              ((uint32_t)0x0F000000U)         /* !< Maximum minor revision */
/* DEBUGSS_USERID[MAJORREV] Bits */
#define DEBUGSS_USERID_MAJORREV_OFS              (28)                            /* !< MAJORREV Offset */
#define DEBUGSS_USERID_MAJORREV_MASK             ((uint32_t)0x70000000U)         /* !< Monotonic increasing value
                                                                                    indicating a new revision of the
                                                                                    device significant enough that users
                                                                                    of the device may have to revise PCB
                                                                                    or software design. */
#define DEBUGSS_USERID_MAJORREV_MIN              ((uint32_t)0x00000000U)         /* !< Minimum major revision */
#define DEBUGSS_USERID_MAJORREV_MAX              ((uint32_t)0x70000000U)         /* !< Maximum major revision */
/* DEBUGSS_USERID[START] Bits */
#define DEBUGSS_USERID_START_OFS                 (31)                            /* !< START Offset */
#define DEBUGSS_USERID_START_MASK                ((uint32_t)0x80000000U)         /* !< Start bit. A value of 1 indicates
                                                                                    the USERID is present. */
#define DEBUGSS_USERID_START_NOK                 ((uint32_t)0x00000000U)         /* !< Not-Okay. The User-ID is not
                                                                                    defined. */
#define DEBUGSS_USERID_START_OK                  ((uint32_t)0x80000000U)         /* !< Okay. Start of the User-ID */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_m33_hw_debugss__include */

