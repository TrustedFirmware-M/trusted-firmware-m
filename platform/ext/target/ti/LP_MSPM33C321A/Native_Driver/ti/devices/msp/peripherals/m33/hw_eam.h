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

#ifndef ti_devices_msp_peripherals_hw_eam__include
#define ti_devices_msp_peripherals_hw_eam__include

/* Filename: hw_eam.h */
/* Revised: 2025-09-11 15:56:01 */
/* Revision: 2b5f545717ba26bba18de7a2db1005762df3b518 */

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
* EAM Registers
******************************************************************************/
#define EAM_EAM_REGS_OFS                         ((uint32_t)0x00000000U)


/** @addtogroup EAM_EAM_REGS
  @{
*/

typedef struct {
       uint32_t RESERVED0[1024];
  __IO uint32_t REVISION;                          /* !< (@ 0x00001000) IP revision id register */
       uint32_t RESERVED1[3];
  __IO uint32_t SECURITY_ERR_FLAG;                 /* !< (@ 0x00001010) Security error flag */
  __IO uint32_t SECURITY_ERR_CLR;                  /* !< (@ 0x00001014) Security error clear */
  __IO uint32_t SECURITY_ERR_MSTID;                /* !< (@ 0x00001018) Security error master id */
  __IO uint32_t SECURITY_ERR_ADDR;                 /* !< (@ 0x0000101C) Security error address */
       uint32_t RESERVED2[4];
  __IO uint32_t FRI_SEC_FLAG;                      /* !< (@ 0x00001030) FRI SEC flag */
  __IO uint32_t FRI_SEC_CLR;                       /* !< (@ 0x00001034) FRI SEC clear */
  __IO uint32_t FRI_SEC_ADDR;                      /* !< (@ 0x00001038) FRI SEC address */
  __IO uint32_t FRI_SEC_MSTID;                     /* !< (@ 0x0000103C) FRI SEC master id */
       uint32_t RESERVED3[4];
  __IO uint32_t FRI_DED_FLAG;                      /* !< (@ 0x00001050) FRI DED flag */
  __IO uint32_t FRI_DED_CLR;                       /* !< (@ 0x00001054) FRI DED clear */
  __IO uint32_t FRI_DED_ADDR;                      /* !< (@ 0x00001058) FRI DED address */
  __IO uint32_t FRI_DED_MSTID;                     /* !< (@ 0x0000105C) FRI DED master id */
       uint32_t RESERVED4[4];
  __IO uint32_t SYSMEM_SEC_FLAG;                   /* !< (@ 0x00001070) SYSMEM SEC flag */
  __IO uint32_t SYSMEM_SEC_CLR;                    /* !< (@ 0x00001074) SYSMEM SEC clear */
  __IO uint32_t SYSMEM_SEC_ADDR;                   /* !< (@ 0x00001078) SYSMEM SEC address */
  __IO uint32_t SYSMEM_SEC_MSTID;                  /* !< (@ 0x0000107C) SYSMEM SEC master id */
       uint32_t RESERVED5[4];
  __IO uint32_t SYSMEM_DED_FLAG;                   /* !< (@ 0x00001090) SYSMEM DED flag */
  __IO uint32_t SYSMEM_DED_CLR;                    /* !< (@ 0x00001094) SYSMEM DED clear */
  __IO uint32_t SYSMEM_DED_ADDR;                   /* !< (@ 0x00001098) SYSMEM DED address */
  __IO uint32_t SYSMEM_DED_MSTID;                  /* !< (@ 0x0000109C) SYSMEM DED master id */
} EAM_EAM_REGS_Regs;

/*@}*/ /* end of group EAM_EAM_REGS */

/** @addtogroup EAM
  @{
*/

typedef struct {
  EAM_EAM_REGS_Regs  EAM_REGS;                          /* !< (@ 0x00000000) */
} EAM_Regs;

/*@}*/ /* end of group EAM */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* EAM Register Control Bits
******************************************************************************/

/* EAM_REVISION Bits */
/* EAM_REVISION[REVISION] Bits */
#define EAM_REVISION_REVISION_OFS                (0)                             /* !< REVISION Offset */
#define EAM_REVISION_REVISION_MASK               ((uint32_t)0x00000001U)         /* !< Revisoin register */

/* EAM_SECURITY_ERR_FLAG Bits */
/* EAM_SECURITY_ERR_FLAG[SECURE] Bits */
#define EAM_SECURITY_ERR_FLAG_SECURE_OFS         (0)                             /* !< SECURE Offset */
#define EAM_SECURITY_ERR_FLAG_SECURE_MASK        ((uint32_t)0x00000001U)         /* !< Secure error flag */
/* EAM_SECURITY_ERR_FLAG[PRIV] Bits */
#define EAM_SECURITY_ERR_FLAG_PRIV_OFS           (1)                             /* !< PRIV Offset */
#define EAM_SECURITY_ERR_FLAG_PRIV_MASK          ((uint32_t)0x00000002U)         /* !< Privilege error flag */
/* EAM_SECURITY_ERR_FLAG[HDP] Bits */
#define EAM_SECURITY_ERR_FLAG_HDP_OFS            (2)                             /* !< HDP Offset */
#define EAM_SECURITY_ERR_FLAG_HDP_MASK           ((uint32_t)0x00000004U)         /* !< Hide protection error flag */
/* EAM_SECURITY_ERR_FLAG[FPI_ILLADDR] Bits */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLADDR_OFS    (3)                             /* !< FPI_ILLADDR Offset */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLADDR_MASK   ((uint32_t)0x00000008U)         /* !< FPI ILLADDR flag */
/* EAM_SECURITY_ERR_FLAG[FPI_ILLPROG] Bits */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLPROG_OFS    (4)                             /* !< FPI_ILLPROG Offset */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLPROG_MASK   ((uint32_t)0x00000010U)         /* !< FPI ILLPROG flag */
/* EAM_SECURITY_ERR_FLAG[FPI_ILLERASE] Bits */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLERASE_OFS   (5)                             /* !< FPI_ILLERASE Offset */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLERASE_MASK  ((uint32_t)0x00000020U)         /* !< FPI ILLERASE flag */
/* EAM_SECURITY_ERR_FLAG[FPI_ILLRDVER] Bits */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLRDVER_OFS   (6)                             /* !< FPI_ILLRDVER Offset */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLRDVER_MASK  ((uint32_t)0x00000040U)         /* !< FPI ILLRDVER flag */
/* EAM_SECURITY_ERR_FLAG[FPI_ILLMODECH] Bits */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLMODECH_OFS  (7)                             /* !< FPI_ILLMODECH Offset */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLMODECH_MASK ((uint32_t)0x00000080U)         /* !< FPI ILLMODECH flag */
/* EAM_SECURITY_ERR_FLAG[FPI_ILLCMD] Bits */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLCMD_OFS     (8)                             /* !< FPI_ILLCMD Offset */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLCMD_MASK    ((uint32_t)0x00000100U)         /* !< FPI ILLCMD flag */
/* EAM_SECURITY_ERR_FLAG[FPI_ILLSIZE] Bits */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLSIZE_OFS    (9)                             /* !< FPI_ILLSIZE Offset */
#define EAM_SECURITY_ERR_FLAG_FPI_ILLSIZE_MASK   ((uint32_t)0x00000200U)         /* !< FPI ILLSIZE flag */
/* EAM_SECURITY_ERR_FLAG[FLC_MMR_ACCESS_ERROR] Bits */
#define EAM_SECURITY_ERR_FLAG_FLC_MMR_ACCESS_ERROR_OFS (10)                            /* !< FLC_MMR_ACCESS_ERROR Offset */
#define EAM_SECURITY_ERR_FLAG_FLC_MMR_ACCESS_ERROR_MASK ((uint32_t)0x00000400U)         /* !< FLC MMR ACCESS ERROR flag */
/* EAM_SECURITY_ERR_FLAG[FLSEM_ACCESS_ERROR] Bits */
#define EAM_SECURITY_ERR_FLAG_FLSEM_ACCESS_ERROR_OFS (11)                            /* !< FLSEM_ACCESS_ERROR Offset */
#define EAM_SECURITY_ERR_FLAG_FLSEM_ACCESS_ERROR_MASK ((uint32_t)0x00000800U)         /* !< FLSEM ACCESS ERROR flag */

/* EAM_SECURITY_ERR_CLR Bits */
/* EAM_SECURITY_ERR_CLR[SECURE] Bits */
#define EAM_SECURITY_ERR_CLR_SECURE_OFS          (0)                             /* !< SECURE Offset */
#define EAM_SECURITY_ERR_CLR_SECURE_MASK         ((uint32_t)0x00000001U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[SEC] register. */
/* EAM_SECURITY_ERR_CLR[PRIV] Bits */
#define EAM_SECURITY_ERR_CLR_PRIV_OFS            (1)                             /* !< PRIV Offset */
#define EAM_SECURITY_ERR_CLR_PRIV_MASK           ((uint32_t)0x00000002U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[PRIV] register. */
/* EAM_SECURITY_ERR_CLR[HDP] Bits */
#define EAM_SECURITY_ERR_CLR_HDP_OFS             (2)                             /* !< HDP Offset */
#define EAM_SECURITY_ERR_CLR_HDP_MASK            ((uint32_t)0x00000004U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[HDP] register. */
/* EAM_SECURITY_ERR_CLR[FPI_ILLADDR] Bits */
#define EAM_SECURITY_ERR_CLR_FPI_ILLADDR_OFS     (3)                             /* !< FPI_ILLADDR Offset */
#define EAM_SECURITY_ERR_CLR_FPI_ILLADDR_MASK    ((uint32_t)0x00000008U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FPI_ILLADDR]
                                                                                    register. */
/* EAM_SECURITY_ERR_CLR[FPI_ILLPROG] Bits */
#define EAM_SECURITY_ERR_CLR_FPI_ILLPROG_OFS     (4)                             /* !< FPI_ILLPROG Offset */
#define EAM_SECURITY_ERR_CLR_FPI_ILLPROG_MASK    ((uint32_t)0x00000010U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FPI_ILLPROG]
                                                                                    register. */
/* EAM_SECURITY_ERR_CLR[FPI_ILLERASE] Bits */
#define EAM_SECURITY_ERR_CLR_FPI_ILLERASE_OFS    (5)                             /* !< FPI_ILLERASE Offset */
#define EAM_SECURITY_ERR_CLR_FPI_ILLERASE_MASK   ((uint32_t)0x00000020U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FPI_ILLERASE]
                                                                                    register. */
/* EAM_SECURITY_ERR_CLR[FPI_ILLRDVER] Bits */
#define EAM_SECURITY_ERR_CLR_FPI_ILLRDVER_OFS    (6)                             /* !< FPI_ILLRDVER Offset */
#define EAM_SECURITY_ERR_CLR_FPI_ILLRDVER_MASK   ((uint32_t)0x00000040U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FPI_ILLRDVER]
                                                                                    register. */
/* EAM_SECURITY_ERR_CLR[FPI_ILLMODECH] Bits */
#define EAM_SECURITY_ERR_CLR_FPI_ILLMODECH_OFS   (7)                             /* !< FPI_ILLMODECH Offset */
#define EAM_SECURITY_ERR_CLR_FPI_ILLMODECH_MASK  ((uint32_t)0x00000080U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FPI_ILLMODECH]
                                                                                    register. */
/* EAM_SECURITY_ERR_CLR[FPI_ILLCMD] Bits */
#define EAM_SECURITY_ERR_CLR_FPI_ILLCMD_OFS      (8)                             /* !< FPI_ILLCMD Offset */
#define EAM_SECURITY_ERR_CLR_FPI_ILLCMD_MASK     ((uint32_t)0x00000100U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FPI_ILLCMD]
                                                                                    register. */
/* EAM_SECURITY_ERR_CLR[FPI_ILLSIZE] Bits */
#define EAM_SECURITY_ERR_CLR_FPI_ILLSIZE_OFS     (9)                             /* !< FPI_ILLSIZE Offset */
#define EAM_SECURITY_ERR_CLR_FPI_ILLSIZE_MASK    ((uint32_t)0x00000200U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FPI_ILLSIZE]
                                                                                    register. */
/* EAM_SECURITY_ERR_CLR[FLC_MMR_ACCESS_ERROR] Bits */
#define EAM_SECURITY_ERR_CLR_FLC_MMR_ACCESS_ERROR_OFS (10)                            /* !< FLC_MMR_ACCESS_ERROR Offset */
#define EAM_SECURITY_ERR_CLR_FLC_MMR_ACCESS_ERROR_MASK ((uint32_t)0x00000400U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FLC_MMR_ACCESS
                                                                                    _ERROR] register. */
/* EAM_SECURITY_ERR_CLR[FLSEM_ACCESS_ERROR] Bits */
#define EAM_SECURITY_ERR_CLR_FLSEM_ACCESS_ERROR_OFS (11)                            /* !< FLSEM_ACCESS_ERROR Offset */
#define EAM_SECURITY_ERR_CLR_FLSEM_ACCESS_ERROR_MASK ((uint32_t)0x00000800U)         /* !< writing '1' will clear
                                                                                    SECURITY_ERR_FLAG[FLSEM_ACCESS_ERROR]
                                                                                    register. */

/* EAM_SECURITY_ERR_MSTID Bits */
/* EAM_SECURITY_ERR_MSTID[MSTID] Bits */
#define EAM_SECURITY_ERR_MSTID_MSTID_OFS         (0)                             /* !< MSTID Offset */
#define EAM_SECURITY_ERR_MSTID_MSTID_MASK        ((uint32_t)0x000000FFU)         /* !< Security error master ID. This
                                                                                    field will be cleared along with the
                                                                                    corresponding flag clear. */

/* EAM_SECURITY_ERR_ADDR Bits */
/* EAM_SECURITY_ERR_ADDR[ADDRESS] Bits */
#define EAM_SECURITY_ERR_ADDR_ADDRESS_OFS        (0)                             /* !< ADDRESS Offset */
#define EAM_SECURITY_ERR_ADDR_ADDRESS_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Security error address. This field
                                                                                    will be cleared along with the
                                                                                    corresponding flag clear. */

/* EAM_FRI_SEC_FLAG Bits */
/* EAM_FRI_SEC_FLAG[SEC] Bits */
#define EAM_FRI_SEC_FLAG_SEC_OFS                 (0)                             /* !< SEC Offset */
#define EAM_FRI_SEC_FLAG_SEC_MASK                ((uint32_t)0x00000001U)         /* !< Single error correction error */

/* EAM_FRI_SEC_CLR Bits */
/* EAM_FRI_SEC_CLR[SEC] Bits */
#define EAM_FRI_SEC_CLR_SEC_OFS                  (0)                             /* !< SEC Offset */
#define EAM_FRI_SEC_CLR_SEC_MASK                 ((uint32_t)0x00000001U)         /* !< writing '1' will clear
                                                                                    FRI_SEC_FLAG[SEC] register. */

/* EAM_FRI_SEC_ADDR Bits */
/* EAM_FRI_SEC_ADDR[ADDRESS] Bits */
#define EAM_FRI_SEC_ADDR_ADDRESS_OFS             (0)                             /* !< ADDRESS Offset */
#define EAM_FRI_SEC_ADDR_ADDRESS_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Single error correction error
                                                                                    address. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */

/* EAM_FRI_SEC_MSTID Bits */
/* EAM_FRI_SEC_MSTID[MSTID] Bits */
#define EAM_FRI_SEC_MSTID_MSTID_OFS              (0)                             /* !< MSTID Offset */
#define EAM_FRI_SEC_MSTID_MSTID_MASK             ((uint32_t)0x000000FFU)         /* !< Single error correction error
                                                                                    master ID. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */

/* EAM_FRI_DED_FLAG Bits */
/* EAM_FRI_DED_FLAG[DED] Bits */
#define EAM_FRI_DED_FLAG_DED_OFS                 (0)                             /* !< DED Offset */
#define EAM_FRI_DED_FLAG_DED_MASK                ((uint32_t)0x00000001U)         /* !< Double error detect error */
/* EAM_FRI_DED_FLAG[DIAG_DED] Bits */
#define EAM_FRI_DED_FLAG_DIAG_DED_OFS            (1)                             /* !< DIAG_DED Offset */
#define EAM_FRI_DED_FLAG_DIAG_DED_MASK           ((uint32_t)0x00000002U)         /* !< diagnostic Double error detect
                                                                                    error */

/* EAM_FRI_DED_CLR Bits */
/* EAM_FRI_DED_CLR[SEC] Bits */
#define EAM_FRI_DED_CLR_SEC_OFS                  (0)                             /* !< SEC Offset */
#define EAM_FRI_DED_CLR_SEC_MASK                 ((uint32_t)0x00000001U)         /* !< writing '1' will clear
                                                                                    FRI_DED_FLAG[DED] register. */
/* EAM_FRI_DED_CLR[DIAG_DED] Bits */
#define EAM_FRI_DED_CLR_DIAG_DED_OFS             (1)                             /* !< DIAG_DED Offset */
#define EAM_FRI_DED_CLR_DIAG_DED_MASK            ((uint32_t)0x00000002U)         /* !< writing '1' will clear
                                                                                    FRI_DED_FLAG[DIAG_DED] register. */

/* EAM_FRI_DED_ADDR Bits */
/* EAM_FRI_DED_ADDR[ADDRESS] Bits */
#define EAM_FRI_DED_ADDR_ADDRESS_OFS             (0)                             /* !< ADDRESS Offset */
#define EAM_FRI_DED_ADDR_ADDRESS_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Single error correction error
                                                                                    address. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */

/* EAM_FRI_DED_MSTID Bits */
/* EAM_FRI_DED_MSTID[MSTID] Bits */
#define EAM_FRI_DED_MSTID_MSTID_OFS              (0)                             /* !< MSTID Offset */
#define EAM_FRI_DED_MSTID_MSTID_MASK             ((uint32_t)0x000000FFU)         /* !< Single error correction error
                                                                                    master ID. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */

/* EAM_SYSMEM_SEC_FLAG Bits */
/* EAM_SYSMEM_SEC_FLAG[RD_SEC] Bits */
#define EAM_SYSMEM_SEC_FLAG_RD_SEC_OFS           (0)                             /* !< RD_SEC Offset */
#define EAM_SYSMEM_SEC_FLAG_RD_SEC_MASK          ((uint32_t)0x00000001U)         /* !< Single error correction error
                                                                                    during read */
/* EAM_SYSMEM_SEC_FLAG[WR_SEC] Bits */
#define EAM_SYSMEM_SEC_FLAG_WR_SEC_OFS           (1)                             /* !< WR_SEC Offset */
#define EAM_SYSMEM_SEC_FLAG_WR_SEC_MASK          ((uint32_t)0x00000002U)         /* !< diagnostic single error correction
                                                                                    error during write */

/* EAM_SYSMEM_SEC_CLR Bits */
/* EAM_SYSMEM_SEC_CLR[RD_SEC] Bits */
#define EAM_SYSMEM_SEC_CLR_RD_SEC_OFS            (0)                             /* !< RD_SEC Offset */
#define EAM_SYSMEM_SEC_CLR_RD_SEC_MASK           ((uint32_t)0x00000001U)         /* !< writing '1' will clear
                                                                                    SYSMEM_SEC_FLAG[RD_SEC] register. */
/* EAM_SYSMEM_SEC_CLR[WR_SEC] Bits */
#define EAM_SYSMEM_SEC_CLR_WR_SEC_OFS            (1)                             /* !< WR_SEC Offset */
#define EAM_SYSMEM_SEC_CLR_WR_SEC_MASK           ((uint32_t)0x00000002U)         /* !< writing '1' will clear
                                                                                    SYSMEM_SEC_FLAG[WR_SEC] register. */

/* EAM_SYSMEM_SEC_ADDR Bits */
/* EAM_SYSMEM_SEC_ADDR[ADDRESS] Bits */
#define EAM_SYSMEM_SEC_ADDR_ADDRESS_OFS          (0)                             /* !< ADDRESS Offset */
#define EAM_SYSMEM_SEC_ADDR_ADDRESS_MASK         ((uint32_t)0xFFFFFFFFU)         /* !< Single error correction error
                                                                                    address. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */

/* EAM_SYSMEM_SEC_MSTID Bits */
/* EAM_SYSMEM_SEC_MSTID[MSTID] Bits */
#define EAM_SYSMEM_SEC_MSTID_MSTID_OFS           (0)                             /* !< MSTID Offset */
#define EAM_SYSMEM_SEC_MSTID_MSTID_MASK          ((uint32_t)0x000000FFU)         /* !< Single error correction error
                                                                                    master ID. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */

/* EAM_SYSMEM_DED_FLAG Bits */
/* EAM_SYSMEM_DED_FLAG[RD_DED] Bits */
#define EAM_SYSMEM_DED_FLAG_RD_DED_OFS           (0)                             /* !< RD_DED Offset */
#define EAM_SYSMEM_DED_FLAG_RD_DED_MASK          ((uint32_t)0x00000001U)         /* !< Double error detect error during
                                                                                    read */
/* EAM_SYSMEM_DED_FLAG[WR_DED] Bits */
#define EAM_SYSMEM_DED_FLAG_WR_DED_OFS           (1)                             /* !< WR_DED Offset */
#define EAM_SYSMEM_DED_FLAG_WR_DED_MASK          ((uint32_t)0x00000002U)         /* !< diagnostic Double error detect
                                                                                    error during write */

/* EAM_SYSMEM_DED_CLR Bits */
/* EAM_SYSMEM_DED_CLR[RD_DED] Bits */
#define EAM_SYSMEM_DED_CLR_RD_DED_OFS            (0)                             /* !< RD_DED Offset */
#define EAM_SYSMEM_DED_CLR_RD_DED_MASK           ((uint32_t)0x00000001U)         /* !< writing '1' will clear
                                                                                    SYSMEM_DED_FLAG[RD_DED] register. */
/* EAM_SYSMEM_DED_CLR[WR_DED] Bits */
#define EAM_SYSMEM_DED_CLR_WR_DED_OFS            (1)                             /* !< WR_DED Offset */
#define EAM_SYSMEM_DED_CLR_WR_DED_MASK           ((uint32_t)0x00000002U)         /* !< writing '1' will clear
                                                                                    SYSMEM_DED_FLAG[WR_DED] register. */

/* EAM_SYSMEM_DED_ADDR Bits */
/* EAM_SYSMEM_DED_ADDR[ADDRESS] Bits */
#define EAM_SYSMEM_DED_ADDR_ADDRESS_OFS          (0)                             /* !< ADDRESS Offset */
#define EAM_SYSMEM_DED_ADDR_ADDRESS_MASK         ((uint32_t)0xFFFFFFFFU)         /* !< Single error correction error
                                                                                    address. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */

/* EAM_SYSMEM_DED_MSTID Bits */
/* EAM_SYSMEM_DED_MSTID[MSTID] Bits */
#define EAM_SYSMEM_DED_MSTID_MSTID_OFS           (0)                             /* !< MSTID Offset */
#define EAM_SYSMEM_DED_MSTID_MSTID_MASK          ((uint32_t)0x000000FFU)         /* !< Single error correction error
                                                                                    master ID. This field will be cleared
                                                                                    along with the corresponding flag
                                                                                    clear. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_eam__include */

