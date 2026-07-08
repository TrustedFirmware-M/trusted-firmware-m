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

#ifndef ti_devices_msp_peripherals_hw_iomux__include
#define ti_devices_msp_peripherals_hw_iomux__include

/* This preliminary header file does not have a version number */
/* Filename: hw_iomux.h */
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
* IOMUX Registers
******************************************************************************/
#define IOMUX_LMGMT_DFT_ATRT_OFS                 ((uint32_t)0x00001900U)
#define IOMUX_UNASSIGNED_OFS                     ((uint32_t)0x00001000U)
#define IOMUX_SECCFG_OFS                         ((uint32_t)0x00000000U)


/** @addtogroup IOMUX_LMGMT_DFT_ATRT
  @{
*/

typedef struct {
  __IO uint32_t DTBENA;                            /* !< (@ 0x00001900) DTB ENA Register */
       uint32_t RESERVED0[2];
  __IO uint32_t DTBBUSSEL;                         /* !< (@ 0x0000190C) DTBBUSSEL Register */
  __IO uint32_t DTBOUTSEL[32];                     /* !< (@ 0x00001910) DTBOUSEL Register */
  __IO uint32_t DTBDIR[32];                        /* !< (@ 0x00001990) DTBDIR Register */
} IOMUX_LMGMT_DFT_ATRT_Regs;

/*@}*/ /* end of group IOMUX_LMGMT_DFT_ATRT */

/** @addtogroup IOMUX_UNASSIGNED
  @{
*/

typedef struct {
       uint32_t RESERVED0[576];
  IOMUX_LMGMT_DFT_ATRT_Regs  LMGMT_DFT_ATRT;                    /* !< (@ 0x00001900) */
} IOMUX_UNASSIGNED_Regs;

/*@}*/ /* end of group IOMUX_UNASSIGNED */

/** @addtogroup IOMUX_SECCFG
  @{
*/

typedef struct {
       uint32_t RESERVED0;
  __IO uint32_t PINCM[251];                        /* !< (@ 0x00000004) Pin Control Management Register in SECCFG region */
} IOMUX_SECCFG_Regs;

/*@}*/ /* end of group IOMUX_SECCFG */

/** @addtogroup IOMUX
  @{
*/

typedef struct {
  IOMUX_SECCFG_Regs  SECCFG;                            /* !< (@ 0x00000000) SECCFG register region */
       uint32_t RESERVED0[772];
  IOMUX_UNASSIGNED_Regs  UNASSIGNED;                        /* !< (@ 0x00001000) UNASSIGNED register region */
} IOMUX_Regs;

/*@}*/ /* end of group IOMUX */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* IOMUX Register Control Bits
******************************************************************************/

/* IOMUX_DTBENA Bits */
/* IOMUX_DTBENA[ENABLE] Bits */
#define IOMUX_DTBENA_ENABLE_OFS                  (0)                             /* !< ENABLE Offset */
#define IOMUX_DTBENA_ENABLE_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< DTB Enable */
#define IOMUX_DTBENA_ENABLE_DISABLE              ((uint32_t)0x00000000U)         /* !< Disable DTB output */
#define IOMUX_DTBENA_ENABLE_ENABLE               ((uint32_t)0x00000001U)         /* !< Enable DTB output */

/* IOMUX_DTBBUSSEL Bits */
/* IOMUX_DTBBUSSEL[SEL] Bits */
#define IOMUX_DTBBUSSEL_SEL_OFS                  (0)                             /* !< SEL Offset */
#define IOMUX_DTBBUSSEL_SEL_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< DTB bus selector */
#define IOMUX_DTBBUSSEL_SEL_MIN                  ((uint32_t)0x00000000U)         /* !< DTB bus 0 is selected */
#define IOMUX_DTBBUSSEL_SEL_MAX                  ((uint32_t)0xFFFFFFFFU)         /* !< dtb bus 0xffffffff is selected */

/* IOMUX_DTBOUTSEL Bits */
/* IOMUX_DTBOUTSEL[OUTIPSEL] Bits */
#define IOMUX_DTBOUTSEL_OUTIPSEL_OFS             (0)                             /* !< OUTIPSEL Offset */
#define IOMUX_DTBOUTSEL_OUTIPSEL_MASK            ((uint32_t)0x0000007FU)         /* !< Select bits to configure the output
                                                                                    IP for the selected DTB Lane. */
#define IOMUX_DTBOUTSEL_OUTIPSEL_MINIMUM         ((uint32_t)0x00000000U)         /* !< Smallest value */
#define IOMUX_DTBOUTSEL_OUTIPSEL_MAXIMUM         ((uint32_t)0x0000007FU)         /* !< Highest possible value */
/* IOMUX_DTBOUTSEL[PRAIL] Bits */
#define IOMUX_DTBOUTSEL_PRAIL_OFS                (7)                             /* !< PRAIL Offset */
#define IOMUX_DTBOUTSEL_PRAIL_MASK               ((uint32_t)0x00000080U)         /* !< PRAIL bit to identify the Power
                                                                                    Rail of the selected IP. */
#define IOMUX_DTBOUTSEL_PRAIL_SVTSEL             ((uint32_t)0x00000000U)         /* !< Selected IP is SVT */
#define IOMUX_DTBOUTSEL_PRAIL_ULLSEL             ((uint32_t)0x00000080U)         /* !< Selected IP is ULL */

/* IOMUX_DTBDIR Bits */
/* IOMUX_DTBDIR[DIR] Bits */
#define IOMUX_DTBDIR_DIR_OFS                     (0)                             /* !< DIR Offset */
#define IOMUX_DTBDIR_DIR_MASK                    ((uint32_t)0x0000003FU)         /* !< DTB lane direction bit, 0: DTB
                                                                                    OUTPUT enable, 1: DTB INPUT enable */
#define IOMUX_DTBDIR_DIR_OUT                     ((uint32_t)0x00000000U)         /* !< DTN lane direction is output, from
                                                                                    core to PAD */
#define IOMUX_DTBDIR_DIR_IN                      ((uint32_t)0x00000001U)         /* !< DTN lane direction is input, from
                                                                                    PAD to core */

/* IOMUX_PINCM Bits */
/* IOMUX_PINCM[PF] Bits */
#define IOMUX_PINCM_PF_OFS                       (0)                             /* !< PF Offset */
#define IOMUX_PINCM_PF_MASK                      ((uint32_t)0x0000003FU)         /* !< P channel Function selection bits */
#define IOMUX_PINCM_PF_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Reserved as unconnected */
#define IOMUX_PINCM_PF_MAXIMUM                   ((uint32_t)0x0000003FU)         /* !< An encoding per function that can
                                                                                    be connected to this pin. */
/* IOMUX_PINCM[PC] Bits */
#define IOMUX_PINCM_PC_OFS                       (7)                             /* !< PC Offset */
#define IOMUX_PINCM_PC_MASK                      ((uint32_t)0x00000080U)         /* !< Peripheral is Connected */
#define IOMUX_PINCM_PC_UNCONNECTED               ((uint32_t)0x00000000U)         /* !< The output of the peripheral (and
                                                                                    its output enable) will not propagate
                                                                                    to the IOCELL */
#define IOMUX_PINCM_PC_CONNECTED                 ((uint32_t)0x00000080U)         /* !< The output latch of the dataflow
                                                                                    will be transparent */
/* IOMUX_PINCM[WAKESTAT] Bits */
#define IOMUX_PINCM_WAKESTAT_OFS                 (13)                            /* !< WAKESTAT Offset */
#define IOMUX_PINCM_WAKESTAT_MASK                ((uint32_t)0x00002000U)         /* !< This has the IOPAD WAKEUP signal as
                                                                                    status bit. */
#define IOMUX_PINCM_WAKESTAT_DISABLE             ((uint32_t)0x00000000U)         /* !< wakeup source is NOT from this
                                                                                    IOCELL */
#define IOMUX_PINCM_WAKESTAT_ENABLE              ((uint32_t)0x00002000U)         /* !< wakeup source is from this IOCELL */
/* IOMUX_PINCM[PIPD] Bits */
#define IOMUX_PINCM_PIPD_OFS                     (16)                            /* !< PIPD Offset */
#define IOMUX_PINCM_PIPD_MASK                    ((uint32_t)0x00010000U)         /* !< Pull Down control selection */
#define IOMUX_PINCM_PIPD_DISABLE                 ((uint32_t)0x00000000U)         /* !< Pull down is disabled. */
#define IOMUX_PINCM_PIPD_ENABLE                  ((uint32_t)0x00010000U)         /* !< Pull down is enabled */
/* IOMUX_PINCM[PIPU] Bits */
#define IOMUX_PINCM_PIPU_OFS                     (17)                            /* !< PIPU Offset */
#define IOMUX_PINCM_PIPU_MASK                    ((uint32_t)0x00020000U)         /* !< Pull Up control selection */
#define IOMUX_PINCM_PIPU_DISABLE                 ((uint32_t)0x00000000U)         /* !< Pull up is disabled. */
#define IOMUX_PINCM_PIPU_ENABLE                  ((uint32_t)0x00020000U)         /* !< Pull up is enabled */
/* IOMUX_PINCM[INENA] Bits */
#define IOMUX_PINCM_INENA_OFS                    (18)                            /* !< INENA Offset */
#define IOMUX_PINCM_INENA_MASK                   ((uint32_t)0x00040000U)         /* !< Input Enable Control Selection */
#define IOMUX_PINCM_INENA_DISABLE                ((uint32_t)0x00000000U)         /* !< Input enable is disabled. */
#define IOMUX_PINCM_INENA_ENABLE                 ((uint32_t)0x00040000U)         /* !< Input enable is enabled. */
/* IOMUX_PINCM[HYSTEN] Bits */
#define IOMUX_PINCM_HYSTEN_OFS                   (19)                            /* !< HYSTEN Offset */
#define IOMUX_PINCM_HYSTEN_MASK                  ((uint32_t)0x00080000U)         /* !< Hystersis Enable Control Selection */
#define IOMUX_PINCM_HYSTEN_DISABLE               ((uint32_t)0x00000000U)         /* !< hysteresis is disabled. */
#define IOMUX_PINCM_HYSTEN_ENABLE                ((uint32_t)0x00080000U)         /* !< hysteresis is enabled */
/* IOMUX_PINCM[DRV] Bits */
#define IOMUX_PINCM_DRV_OFS                      (20)                            /* !< DRV Offset */
#define IOMUX_PINCM_DRV_MASK                     ((uint32_t)0x00100000U)         /* !< Drive strength control selection,
                                                                                    for HS IOCELL only */
#define IOMUX_PINCM_DRV_DRVVAL0                  ((uint32_t)0x00000000U)         /* !< Drive setting of 0 selected */
#define IOMUX_PINCM_DRV_DRVVAL1                  ((uint32_t)0x00100000U)         /* !< Drive setting of 1 selected */
/* IOMUX_PINCM[HIZ1] Bits */
#define IOMUX_PINCM_HIZ1_OFS                     (25)                            /* !< HIZ1 Offset */
#define IOMUX_PINCM_HIZ1_MASK                    ((uint32_t)0x02000000U)         /* !< High output value will tri-state
                                                                                    the output when this bit is enabled */
#define IOMUX_PINCM_HIZ1_DISABLE                 ((uint32_t)0x00000000U)         /* !< open-drain is disabled. */
#define IOMUX_PINCM_HIZ1_ENABLE                  ((uint32_t)0x02000000U)         /* !< open-drain is enabled. */
/* IOMUX_PINCM[WUEN] Bits */
#define IOMUX_PINCM_WUEN_OFS                     (27)                            /* !< WUEN Offset */
#define IOMUX_PINCM_WUEN_MASK                    ((uint32_t)0x08000000U)         /* !< Wakeup Enable bit */
#define IOMUX_PINCM_WUEN_DISABLE                 ((uint32_t)0x00000000U)         /* !< wakeup is disabled. */
#define IOMUX_PINCM_WUEN_ENABLE                  ((uint32_t)0x08000000U)         /* !< wakeup is enabled */
/* IOMUX_PINCM[WCOMP] Bits */
#define IOMUX_PINCM_WCOMP_OFS                    (28)                            /* !< WCOMP Offset */
#define IOMUX_PINCM_WCOMP_MASK                   ((uint32_t)0x10000000U)         /* !< Wakeup Compare Value bit */
#define IOMUX_PINCM_WCOMP_MATCH0                 ((uint32_t)0x00000000U)         /* !< Wakeup on a match of 0 */
#define IOMUX_PINCM_WCOMP_MATCH1                 ((uint32_t)0x10000000U)         /* !< Wakeup on a match of 1 */
/* IOMUX_PINCM[INV] Bits */
#define IOMUX_PINCM_INV_OFS                      (26)                            /* !< INV Offset */
#define IOMUX_PINCM_INV_MASK                     ((uint32_t)0x04000000U)         /* !< Data inversion selection */
#define IOMUX_PINCM_INV_DISABLE                  ((uint32_t)0x00000000U)         /* !< Data inversion is disabled. */
#define IOMUX_PINCM_INV_ENABLE                   ((uint32_t)0x04000000U)         /* !< Data inversion is enabled */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_iomux__include */

