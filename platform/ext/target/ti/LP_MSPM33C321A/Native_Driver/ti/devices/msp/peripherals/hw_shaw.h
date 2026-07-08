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

#ifndef ti_devices_msp_peripherals_hw_shaw__include
#define ti_devices_msp_peripherals_hw_shaw__include

/* This preliminary header file does not have a version number */
/* Filename: hw_shaw.h */
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
* SHAW Registers
******************************************************************************/
#define SHAW_SHAW_OFS                            ((uint32_t)0x00001000U)
#define SHAW_GPRCM_OFS                           ((uint32_t)0x00000800U)


/** @addtogroup SHAW_SHAW
  @{
*/

typedef struct {
       uint32_t RESERVED0[8];
  union {
      __IO uint32_t SHAW_PUB0_IIDX;                    /* !< PUB0 IIDX register */
      __IO uint32_t SHAW_PUB0_IIDX_SHAW_PUB0_IIDX_1;   /* !< PUB0 IIDX register */
  };
  union {
      __IO uint32_t Reserved_2;
      __IO uint32_t Reserved_2_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB0_IMASK;                   /* !< PUB0 IMASK register */
      __IO uint32_t SHAW_PUB0_IMASK_SHAW_PUB0_IMASK_1; /* !< PUB0 IMASK register */
  };
  union {
      __IO uint32_t Reserved_3;
      __IO uint32_t Reserved_3_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB0_RIS;                     /* !< PUB0 RIS register */
      __IO uint32_t SHAW_PUB0_RIS_SHAW_PUB0_RIS_1;     /* !< PUB0 RIS register */
  };
  union {
      __IO uint32_t Reserved_4;
      __IO uint32_t Reserved_4_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB0_MIS;                     /* !< PUB0 MIS register */
      __IO uint32_t SHAW_PUB0_MIS_SHAW_PUB0_MIS_1;     /* !< PUB0 MIS register */
  };
  union {
      __IO uint32_t Reserved_5;
      __IO uint32_t Reserved_5_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB0_ISET;                    /* !< PUB0 ISET register */
      __IO uint32_t SHAW_PUB0_ISET_SHAW_PUB0_ISET_1;   /* !< PUB0 ISET register */
  };
  union {
      __IO uint32_t Reserved_6;
      __IO uint32_t Reserved_6_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB0_ICLR;                    /* !< PUB0 ICLR register */
      __IO uint32_t SHAW_PUB0_ICLR_SHAW_PUB0_ICLR_1;   /* !< PUB0 ICLR register */
  };
  union {
      __IO uint32_t Reserved_7;
      __IO uint32_t Reserved_7_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB1_IIDX;                    /* !< PUB1 IIDX register */
      __IO uint32_t SHAW_PUB1_IIDX_SHAW_PUB1_IIDX_1;   /* !< PUB1 IIDX register */
  };
  union {
      __IO uint32_t Reserved_8;
      __IO uint32_t Reserved_8_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB1_IMASK;                   /* !< PUB1 IIDX register */
      __IO uint32_t SHAW_PUB1_IMASK_SHAW_PUB1_IMASK_1; /* !< PUB1 IIDX register */
  };
  union {
      __IO uint32_t Reserved_9;
      __IO uint32_t Reserved_9_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB1_RIS;                     /* !< PUB1 RIS register */
      __IO uint32_t SHAW_PUB1_RIS_SHAW_PUB1_RIS_1;     /* !< PUB1 RIS register */
  };
  union {
      __IO uint32_t Reserved_10;
      __IO uint32_t Reserved_10_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB1_MIS;                     /* !< PUB1 MIS register */
      __IO uint32_t SHAW_PUB1_MIS_SHAW_PUB1_MIS_1;     /* !< PUB1 MIS register */
  };
  union {
      __IO uint32_t Reserved_11;
      __IO uint32_t Reserved_11_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_PUB1_ISET;                    /* !< PUB1 ISET register */
      __IO uint32_t SHAW_PUB1_ISET_SHAW_PUB1_ISET_1;   /* !< PUB1 ISET register */
  };
  union {
      __IO uint32_t Reserved_12;
      __IO uint32_t Reserved_12_SHAW_PUB1_ISET_1;
  };
  union {
      __IO uint32_t SHAW_PUB1_ICLR;                    /* !< PUB1 ICLR register */
      __IO uint32_t SHAW_PUB1_ICLR_SHAW_PUB1_ICLR_1;   /* !< PUB1 ICLR register */
  };
  union {
      __IO uint32_t Reserved_13;
      __IO uint32_t Reserved_13_Reserved_1;
  };
  union {
      __IO uint32_t SHAW_DMA_START_TRIGGER;            /* !< DMA Start Trigger Register */
      __IO uint32_t SHAW_DMA_START_TRIGGER_SHAW_DMA_START_TRIGGER_1;/* !< DMA Start Trigger Register */
  };
  union {
      __IO uint32_t Reserved_14[31];
      __IO uint32_t Reserved_14_Reserved_1[31];
  };
  union {
      __IO uint32_t SHAW_DATA_FIXED;                   /* !< Fixed Address Wrie Register */
      __IO uint32_t SHAW_DATA_FIXED_SHAW_DATA_FIXED_1; /* !< Fixed Address Wrie Register */
  };
  union {
      __IO uint32_t Reserved_15[63];
      __IO uint32_t Reserved_15_Reserved_1[63];
  };
  union {
      __IO uint32_t EIP59_DATA_IN0_;                   /* !< SHA Data IN 0 register */
      __IO uint32_t EIP59_DATA_IN0__EIP59_DATA_IN0_1;  /* !< SHA Data IN 0 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN1_;                   /* !< SHA Data IN 1 register */
      __IO uint32_t EIP59_DATA_IN1__EIP59_DATA_IN1_1;  /* !< SHA Data IN 1 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN2_;                   /* !< SHA Data IN 2 register */
      __IO uint32_t EIP59_DATA_IN2__EIP59_DATA_IN2_1;  /* !< SHA Data IN 2 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN3_;                   /* !< SHA Data IN 3 register */
      __IO uint32_t EIP59_DATA_IN3__EIP59_DATA_IN3_1;  /* !< SHA Data IN 3 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN4_;                   /* !< SHA Data IN 4 register */
      __IO uint32_t EIP59_DATA_IN4__EIP59_DATA_IN4_1;  /* !< SHA Data IN 4 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN5_;                   /* !< SHA Data IN 5 register */
      __IO uint32_t EIP59_DATA_IN5__EIP59_DATA_IN5_1;  /* !< SHA Data IN 5 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN6_;                   /* !< SHA Data IN 6 register */
      __IO uint32_t EIP59_DATA_IN6__EIP59_DATA_IN6_1;  /* !< SHA Data IN 6 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN7_;                   /* !< SHA Data IN 7 register */
      __IO uint32_t EIP59_DATA_IN7__EIP59_DATA_IN7_1;  /* !< SHA Data IN 7 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN8_;                   /* !< SHA Data IN 8 register */
      __IO uint32_t EIP59_DATA_IN8__EIP59_DATA_IN8_1;  /* !< SHA Data IN 8 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN9_;                   /* !< SHA Data IN 9 register */
      __IO uint32_t EIP59_DATA_IN9__EIP59_DATA_IN9_1;  /* !< SHA Data IN 9 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN10_;                  /* !< SHA Data IN 10 register */
      __IO uint32_t EIP59_DATA_IN10__EIP59_DATA_IN10_1;/* !< SHA Data IN 10 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN11_;                  /* !< SHA Data IN 11 register */
      __IO uint32_t EIP59_DATA_IN11__EIP59_DATA_IN11_1;/* !< SHA Data IN 11 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN12_;                  /* !< SHA Data IN 12 register */
      __IO uint32_t EIP59_DATA_IN12__EIP59_DATA_IN12_1;/* !< SHA Data IN 12 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN13_;                  /* !< SHA Data IN 13 register */
      __IO uint32_t EIP59_DATA_IN13__EIP59_DATA_IN13_1;/* !< SHA Data IN 13 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN14_;                  /* !< SHA Data IN 14 register */
      __IO uint32_t EIP59_DATA_IN14__EIP59_DATA_IN14_1;/* !< SHA Data IN 14 register */
  };
  union {
      __IO uint32_t EIP59_DATA_IN15_;                  /* !< SHA Data IN 15 register */
      __IO uint32_t EIP59_DATA_IN15__EIP59_DATA_IN15_1;/* !< SHA Data IN 15 register */
  };
  union {
      __IO uint32_t EIP59_IO_BUF_CTRL_STAT;            /* !< SHA Status Register */
      __IO uint32_t EIP59_IO_BUF_CTRL_STAT_EIP59_IOBUF_CTRL_STAT_1;/* !< SHA Status Register */
  };
  union {
      __IO uint32_t EIP59_MODE_IN;                     /* !< SHA Mode Register */
      __IO uint32_t EIP59_MODE_IN_EIP59_MODE_IN_1;     /* !< SHA Mode Register */
  };
  union {
      __IO uint32_t EIP59_LENGTH_IN_L;                 /* !< Data Length Register LSB */
      __IO uint32_t EIP59_LENGTH_IN_L_EIP59_LENGTH_IN_L_1;/* !< Data Length Register LSB */
  };
  union {
      __IO uint32_t EIP59_LENGTH_IN_H;                 /* !< Data Length Register MSB */
      __IO uint32_t EIP59_LENGTH_IN_H_EIP59_LENGTH_IN_H_1;/* !< Data Length Register MSB */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_A;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_A_EIP59_IDIGEST_A_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_B;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_B_EIP59_IDIGEST_B_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_C;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_C_EIP59_IDIGEST_C_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_D;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_D_EIP59_IDIGEST_D_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_E;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_E_EIP59_IDIGEST_E_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_F;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_F_EIP59_IDIGEST_F_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_G;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_G_EIP59_IDIGEST_G_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_IDIGEST_H;                   /* !< SHA IDIGEST Register */
      __IO uint32_t EIP59_IDIGEST_H_EIP59_IDIGEST_H_1; /* !< SHA IDIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_A;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_A_EIP59_ODIGEST_A_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_B;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_B_EIP59_ODIGEST_B_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_C;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_C_EIP59_ODIGEST_C_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_D;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_D_EIP59_ODIGEST_D_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_E;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_E_EIP59_ODIGEST_E_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_F;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_F_EIP59_ODIGEST_F_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_G;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_G_EIP59_ODIGEST_G_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_ODIGEST_H;                   /* !< SHA ODIGEST Register */
      __IO uint32_t EIP59_ODIGEST_H_EIP59_ODIGEST_H_1; /* !< SHA ODIGEST Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_A;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_A_EIP59_DIGEST_A_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_B;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_B_EIP59_DIGEST_B_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_C;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_C_EIP59_DIGEST_C_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_D;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_D_EIP59_DIGEST_D_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_E;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_E_EIP59_DIGEST_E_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_F;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_F_EIP59_DIGEST_F_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_G;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_G_EIP59_DIGEST_G_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t EIP59_DIGEST_H;                    /* !< SHA DIGEST OUT Result Register */
      __IO uint32_t EIP59_DIGEST_H_EIP59_DIGEST_H_1;   /* !< SHA DIGEST OUT Result Register */
  };
  union {
      __IO uint32_t Reserved_16[18];
      __IO uint32_t Reserved_16_Reserved_1[18];
  };
  union {
      __IO uint32_t EIP59_CONFIG;                      /* !< SHA Configuration Register */
      __IO uint32_t EIP59_CONFIG_EIP59_CONFIG_1;       /* !< SHA Configuration Register */
  };
  union {
      __IO uint32_t EIP59_VERSION;                     /* !< SHA Version Register */
      __IO uint32_t EIP59_VERSION_EIP59_VERSION_1;     /* !< SHA Version Register */
  };
  union {
      __IO uint32_t Reserved_17[832];
      __IO uint32_t Reserved_17_Reserved_1[832];
  };
} SHAW_SHAW_Regs;

/*@}*/ /* end of group SHAW_SHAW */

/** @addtogroup SHAW_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} SHAW_GPRCM_Regs;

/*@}*/ /* end of group SHAW_GPRCM */

/** @addtogroup SHAW
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  SHAW_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED1[506];
  SHAW_SHAW_Regs  SHAW;                              /* !< (@ 0x00001000) */
} SHAW_Regs;

/*@}*/ /* end of group SHAW */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* SHAW Register Control Bits
******************************************************************************/

/* SHAW_SHAW_PUB0_IIDX Bits */
/* SHAW_SHAW_PUB0_IIDX[STAT] Bits */
#define SHAW_SHAW_PUB0_IIDX_STAT_OFS             (0)                             /* !< STAT Offset */
#define SHAW_SHAW_PUB0_IIDX_STAT_MASK            ((uint32_t)0x00000001U)         /* !< This register provides the highest
                                                                                    priority enabled interrupt index.
                                                                                    Value 0x00 means no event pending.
                                                                                    Interrupt 1 is the highest priority,
                                                                                    IIDX next highest, 4, 8, ... IIDX^31
                                                                                    is the least priority. That is, the
                                                                                    least bit position that is set to 1
                                                                                    denotes the highest priority pending
                                                                                    interrupt. The priority order is
                                                                                    fixed. However, users can implement
                                                                                    their own prioritization schemes
                                                                                    using other registers that expose the
                                                                                    full set of interrupts that have
                                                                                    occurred. On each read, only one
                                                                                    interrupt is indicated. On a read,
                                                                                    the current interrupt (highest
                                                                                    priority) is automatically cleared by
                                                                                    the hardware and the corresponding
                                                                                    interrupt flag in [RIS] and [MIS] are
                                                                                    cleared as well. After a read from
                                                                                    the CPU (not from the debug
                                                                                    interface), the register is updated
                                                                                    with the next highest priority
                                                                                    interrupt, if none are pending, then
                                                                                    it should display 0x0. */

/* SHAW_SHAW_PUB0_IIDX_1 Bits */
/* SHAW_SHAW_PUB0_IIDX_1[STAT] Bits */
#define SHAW_SHAW_PUB0_IIDX_1_STAT_OFS           (0)                             /* !< STAT Offset */
#define SHAW_SHAW_PUB0_IIDX_1_STAT_MASK          ((uint32_t)0x00000001U)         /* !< This register provides the highest
                                                                                    priority enabled interrupt index.
                                                                                    Value 0x00 means no event pending.
                                                                                    Interrupt 1 is the highest priority,
                                                                                    IIDX next highest, 4, 8, ... IIDX^31
                                                                                    is the least priority. That is, the
                                                                                    least bit position that is set to 1
                                                                                    denotes the highest priority pending
                                                                                    interrupt. The priority order is
                                                                                    fixed. However, users can implement
                                                                                    their own prioritization schemes
                                                                                    using other registers that expose the
                                                                                    full set of interrupts that have
                                                                                    occurred. On each read, only one
                                                                                    interrupt is indicated. On a read,
                                                                                    the current interrupt (highest
                                                                                    priority) is automatically cleared by
                                                                                    the hardware and the corresponding
                                                                                    interrupt flag in [RIS] and [MIS] are
                                                                                    cleared as well. After a read from
                                                                                    the CPU (not from the debug
                                                                                    interface), the register is updated
                                                                                    with the next highest priority
                                                                                    interrupt, if none are pending, then
                                                                                    it should display 0x0. */

/* SHAW_SHAW_PUB0_IMASK Bits */
/* SHAW_SHAW_PUB0_IMASK[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_IMASK_OUTPUTRDY_OFS       (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_IMASK_OUTPUTRDY_MASK      ((uint32_t)0x00000001U)         /* !< Interrupt Mask. If a bit is set,
                                                                                    then corresponding interrupt is
                                                                                    un-masked. Un-masking the interrupt
                                                                                    causes the raw interrupt to be
                                                                                    visible in IIDX, as well as MIS. */

/* SHAW_SHAW_PUB0_IMASK_1 Bits */
/* SHAW_SHAW_PUB0_IMASK_1[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_IMASK_1_OUTPUTRDY_OFS     (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_IMASK_1_OUTPUTRDY_MASK    ((uint32_t)0x00000001U)         /* !< Interrupt Mask. If a bit is set,
                                                                                    then corresponding interrupt is
                                                                                    un-masked. Un-masking the interrupt
                                                                                    causes the raw interrupt to be
                                                                                    visible in IIDX, as well as MIS. */

/* SHAW_SHAW_PUB0_RIS Bits */
/* SHAW_SHAW_PUB0_RIS[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_RIS_OUTPUTRDY_OFS         (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_RIS_OUTPUTRDY_MASK        ((uint32_t)0x00000001U)         /* !< Raw interrupt status. Reflects all
                                                                                    pending interrupts, regardless of
                                                                                    masking. The RIS register allows the
                                                                                    user to implement a poll scheme. A
                                                                                    flag set in this register can be
                                                                                    cleared by writing 1 to the ICLR
                                                                                    register bit even if the
                                                                                    corresponding IMASK bit is not
                                                                                    enabled. */

/* SHAW_SHAW_PUB0_RIS_1 Bits */
/* SHAW_SHAW_PUB0_RIS_1[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_RIS_1_OUTPUTRDY_OFS       (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_RIS_1_OUTPUTRDY_MASK      ((uint32_t)0x00000001U)         /* !< Raw interrupt status. Reflects all
                                                                                    pending interrupts, regardless of
                                                                                    masking. The RIS register allows the
                                                                                    user to implement a poll scheme. A
                                                                                    flag set in this register can be
                                                                                    cleared by writing 1 to the ICLR
                                                                                    register bit even if the
                                                                                    corresponding IMASK bit is not
                                                                                    enabled. */

/* SHAW_SHAW_PUB0_MIS Bits */
/* SHAW_SHAW_PUB0_MIS[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_MIS_OUTPUTRDY_OFS         (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_MIS_OUTPUTRDY_MASK        ((uint32_t)0x00000001U)         /* !< Masked interrupt status. This is an
                                                                                    AND of the IMASK and RIS registers. */

/* SHAW_SHAW_PUB0_MIS_1 Bits */
/* SHAW_SHAW_PUB0_MIS_1[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_MIS_1_OUTPUTRDY_OFS       (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_MIS_1_OUTPUTRDY_MASK      ((uint32_t)0x00000001U)         /* !< Masked interrupt status. This is an
                                                                                    AND of the IMASK and RIS registers. */

/* SHAW_SHAW_PUB0_ISET Bits */
/* SHAW_SHAW_PUB0_ISET[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_ISET_OUTPUTRDY_OFS        (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_ISET_OUTPUTRDY_MASK       ((uint32_t)0x00000001U)         /* !< Interrupt set. Allows interrupts to
                                                                                    be set by software (useful in
                                                                                    diagnostics and safety checks).
                                                                                    Writing a 1 to a bit in ISET will set
                                                                                    the event and therefore the related
                                                                                    RIS bit also gets set. If the
                                                                                    interrupt is enabled through the
                                                                                    mask, then the corresponding MIS bit
                                                                                    is also set. */

/* SHAW_SHAW_PUB0_ISET_1 Bits */
/* SHAW_SHAW_PUB0_ISET_1[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_ISET_1_OUTPUTRDY_OFS      (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_ISET_1_OUTPUTRDY_MASK     ((uint32_t)0x00000001U)         /* !< Interrupt set. Allows interrupts to
                                                                                    be set by software (useful in
                                                                                    diagnostics and safety checks).
                                                                                    Writing a 1 to a bit in ISET will set
                                                                                    the event and therefore the related
                                                                                    RIS bit also gets set. If the
                                                                                    interrupt is enabled through the
                                                                                    mask, then the corresponding MIS bit
                                                                                    is also set. */

/* SHAW_SHAW_PUB0_ICLR Bits */
/* SHAW_SHAW_PUB0_ICLR[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_ICLR_OUTPUTRDY_OFS        (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_ICLR_OUTPUTRDY_MASK       ((uint32_t)0x00000001U)         /* !< Interrupt clear. Write a 1 to clear
                                                                                    corresponding Interrupt. */

/* SHAW_SHAW_PUB0_ICLR_1 Bits */
/* SHAW_SHAW_PUB0_ICLR_1[OUTPUTRDY] Bits */
#define SHAW_SHAW_PUB0_ICLR_1_OUTPUTRDY_OFS      (0)                             /* !< OUTPUTRDY Offset */
#define SHAW_SHAW_PUB0_ICLR_1_OUTPUTRDY_MASK     ((uint32_t)0x00000001U)         /* !< Interrupt clear. Write a 1 to clear
                                                                                    corresponding Interrupt. */

/* SHAW_SHAW_PUB1_IIDX Bits */
/* SHAW_SHAW_PUB1_IIDX[STAT] Bits */
#define SHAW_SHAW_PUB1_IIDX_STAT_OFS             (0)                             /* !< STAT Offset */
#define SHAW_SHAW_PUB1_IIDX_STAT_MASK            ((uint32_t)0x00000001U)         /* !< This register provides the highest
                                                                                    priority enabled interrupt index.
                                                                                    Value 0x00 means no event pending.
                                                                                    Interrupt 1 is the highest priority,
                                                                                    IIDX next highest, 4, 8, ... IIDX^31
                                                                                    is the least priority. That is, the
                                                                                    least bit position that is set to 1
                                                                                    denotes the highest priority pending
                                                                                    interrupt. The priority order is
                                                                                    fixed. However, users can implement
                                                                                    their own prioritization schemes
                                                                                    using other registers that expose the
                                                                                    full set of interrupts that have
                                                                                    occurred. On each read, only one
                                                                                    interrupt is indicated. On a read,
                                                                                    the current interrupt (highest
                                                                                    priority) is automatically cleared by
                                                                                    the hardware and the corresponding
                                                                                    interrupt flag in [RIS] and [MIS] are
                                                                                    cleared as well. After a read from
                                                                                    the CPU (not from the debug
                                                                                    interface), the register is updated
                                                                                    with the next highest priority
                                                                                    interrupt, if none are pending, then
                                                                                    it should display 0x0. */

/* SHAW_SHAW_PUB1_IIDX_1 Bits */
/* SHAW_SHAW_PUB1_IIDX_1[STAT] Bits */
#define SHAW_SHAW_PUB1_IIDX_1_STAT_OFS           (0)                             /* !< STAT Offset */
#define SHAW_SHAW_PUB1_IIDX_1_STAT_MASK          ((uint32_t)0x00000001U)         /* !< This register provides the highest
                                                                                    priority enabled interrupt index.
                                                                                    Value 0x00 means no event pending.
                                                                                    Interrupt 1 is the highest priority,
                                                                                    IIDX next highest, 4, 8, ... IIDX^31
                                                                                    is the least priority. That is, the
                                                                                    least bit position that is set to 1
                                                                                    denotes the highest priority pending
                                                                                    interrupt. The priority order is
                                                                                    fixed. However, users can implement
                                                                                    their own prioritization schemes
                                                                                    using other registers that expose the
                                                                                    full set of interrupts that have
                                                                                    occurred. On each read, only one
                                                                                    interrupt is indicated. On a read,
                                                                                    the current interrupt (highest
                                                                                    priority) is automatically cleared by
                                                                                    the hardware and the corresponding
                                                                                    interrupt flag in [RIS] and [MIS] are
                                                                                    cleared as well. After a read from
                                                                                    the CPU (not from the debug
                                                                                    interface), the register is updated
                                                                                    with the next highest priority
                                                                                    interrupt, if none are pending, then
                                                                                    it should display 0x0. */

/* SHAW_SHAW_PUB1_IMASK Bits */
/* SHAW_SHAW_PUB1_IMASK[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_IMASK_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_IMASK_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Interrupt Mask. If a bit is set,
                                                                                    then corresponding interrupt is
                                                                                    un-masked. Un-masking the interrupt
                                                                                    causes the raw interrupt to be
                                                                                    visible in IIDX, as well as MIS. */

/* SHAW_SHAW_PUB1_IMASK_1 Bits */
/* SHAW_SHAW_PUB1_IMASK_1[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_IMASK_1_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_IMASK_1_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Interrupt Mask. If a bit is set,
                                                                                    then corresponding interrupt is
                                                                                    un-masked. Un-masking the interrupt
                                                                                    causes the raw interrupt to be
                                                                                    visible in IIDX, as well as MIS. */

/* SHAW_SHAW_PUB1_RIS Bits */
/* SHAW_SHAW_PUB1_RIS[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_RIS_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_RIS_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Raw interrupt status. Reflects all
                                                                                    pending interrupts, regardless of
                                                                                    masking. The RIS register allows the
                                                                                    user to implement a poll scheme. A
                                                                                    flag set in this register can be
                                                                                    cleared by writing 1 to the ICLR
                                                                                    register bit even if the
                                                                                    corresponding IMASK bit is not
                                                                                    enabled. */

/* SHAW_SHAW_PUB1_RIS_1 Bits */
/* SHAW_SHAW_PUB1_RIS_1[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_RIS_1_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_RIS_1_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Raw interrupt status. Reflects all
                                                                                    pending interrupts, regardless of
                                                                                    masking. The RIS register allows the
                                                                                    user to implement a poll scheme. A
                                                                                    flag set in this register can be
                                                                                    cleared by writing 1 to the ICLR
                                                                                    register bit even if the
                                                                                    corresponding IMASK bit is not
                                                                                    enabled. */

/* SHAW_SHAW_PUB1_MIS Bits */
/* SHAW_SHAW_PUB1_MIS[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_MIS_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_MIS_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Masked interrupt status. This is an
                                                                                    AND of the IMASK and RIS registers. */

/* SHAW_SHAW_PUB1_MIS_1 Bits */
/* SHAW_SHAW_PUB1_MIS_1[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_MIS_1_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_MIS_1_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Masked interrupt status. This is an
                                                                                    AND of the IMASK and RIS registers. */

/* SHAW_SHAW_PUB1_ISET Bits */
/* SHAW_SHAW_PUB1_ISET[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_ISET_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_ISET_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Interrupt set. Allows interrupts to
                                                                                    be set by software (useful in
                                                                                    diagnostics and safety checks).
                                                                                    Writing a 1 to a bit in ISET will set
                                                                                    the event and therefore the related
                                                                                    RIS bit also gets set. If the
                                                                                    interrupt is enabled through the
                                                                                    mask, then the corresponding MIS bit
                                                                                    is also set. */

/* SHAW_SHAW_PUB1_ISET_1 Bits */
/* SHAW_SHAW_PUB1_ISET_1[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_ISET_1_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_ISET_1_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Interrupt set. Allows interrupts to
                                                                                    be set by software (useful in
                                                                                    diagnostics and safety checks).
                                                                                    Writing a 1 to a bit in ISET will set
                                                                                    the event and therefore the related
                                                                                    RIS bit also gets set. If the
                                                                                    interrupt is enabled through the
                                                                                    mask, then the corresponding MIS bit
                                                                                    is also set. */

/* SHAW_SHAW_PUB1_ICLR Bits */
/* SHAW_SHAW_PUB1_ICLR[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_ICLR_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_ICLR_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Interrupt clear. Write a 1 to clear
                                                                                    corresponding Interrupt. */

/* SHAW_SHAW_PUB1_ICLR_1 Bits */
/* SHAW_SHAW_PUB1_ICLR_1[DMA_START_TRIGGER] Bits */
#define SHAW_SHAW_PUB1_ICLR_1_DMA_START_TRIGGER_OFS (0)                             /* !< DMA_START_TRIGGER Offset */
#define SHAW_SHAW_PUB1_ICLR_1_DMA_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Interrupt clear. Write a 1 to clear
                                                                                    corresponding Interrupt. */

/* SHAW_SHAW_DMA_START_TRIGGER Bits */
/* SHAW_SHAW_DMA_START_TRIGGER[START_TRIGGER] Bits */
#define SHAW_SHAW_DMA_START_TRIGGER_START_TRIGGER_OFS (0)                             /* !< START_TRIGGER Offset */
#define SHAW_SHAW_DMA_START_TRIGGER_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Trigger to start DMA */

/* SHAW_SHAW_DMA_START_TRIGGER_1 Bits */
/* SHAW_SHAW_DMA_START_TRIGGER_1[START_TRIGGER] Bits */
#define SHAW_SHAW_DMA_START_TRIGGER_1_START_TRIGGER_OFS (0)                             /* !< START_TRIGGER Offset */
#define SHAW_SHAW_DMA_START_TRIGGER_1_START_TRIGGER_MASK ((uint32_t)0x00000001U)         /* !< Trigger to start DMA */

/* SHAW_SHAW_DATA_FIXED Bits */
/* SHAW_SHAW_DATA_FIXED[DATA_IN] Bits */
#define SHAW_SHAW_DATA_FIXED_DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_SHAW_DATA_FIXED_DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_SHAW_DATA_FIXED_1 Bits */
/* SHAW_SHAW_DATA_FIXED_1[DATA_IN] Bits */
#define SHAW_SHAW_DATA_FIXED_1_DATA_IN_OFS       (0)                             /* !< DATA_IN Offset */
#define SHAW_SHAW_DATA_FIXED_1_DATA_IN_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN0_ Bits */
/* SHAW_EIP59_DATA_IN0_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN0__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN0__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN0_1 Bits */
/* SHAW_EIP59_DATA_IN0_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN0_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN0_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN1_ Bits */
/* SHAW_EIP59_DATA_IN1_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN1__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN1__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN1_1 Bits */
/* SHAW_EIP59_DATA_IN1_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN1_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN1_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN2_ Bits */
/* SHAW_EIP59_DATA_IN2_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN2__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN2__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN2_1 Bits */
/* SHAW_EIP59_DATA_IN2_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN2_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN2_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN3_ Bits */
/* SHAW_EIP59_DATA_IN3_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN3__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN3__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN3_1 Bits */
/* SHAW_EIP59_DATA_IN3_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN3_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN3_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN4_ Bits */
/* SHAW_EIP59_DATA_IN4_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN4__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN4__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN4_1 Bits */
/* SHAW_EIP59_DATA_IN4_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN4_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN4_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN5_ Bits */
/* SHAW_EIP59_DATA_IN5_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN5__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN5__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN5_1 Bits */
/* SHAW_EIP59_DATA_IN5_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN5_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN5_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN6_ Bits */
/* SHAW_EIP59_DATA_IN6_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN6__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN6__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN6_1 Bits */
/* SHAW_EIP59_DATA_IN6_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN6_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN6_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN7_ Bits */
/* SHAW_EIP59_DATA_IN7_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN7__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN7__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN7_1 Bits */
/* SHAW_EIP59_DATA_IN7_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN7_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN7_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN8_ Bits */
/* SHAW_EIP59_DATA_IN8_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN8__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN8__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN8_1 Bits */
/* SHAW_EIP59_DATA_IN8_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN8_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN8_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN9_ Bits */
/* SHAW_EIP59_DATA_IN9_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN9__DATA_IN_OFS         (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN9__DATA_IN_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN9_1 Bits */
/* SHAW_EIP59_DATA_IN9_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN9_1_DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN9_1_DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN10_ Bits */
/* SHAW_EIP59_DATA_IN10_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN10__DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN10__DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN10_1 Bits */
/* SHAW_EIP59_DATA_IN10_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN10_1_DATA_IN_OFS       (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN10_1_DATA_IN_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN11_ Bits */
/* SHAW_EIP59_DATA_IN11_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN11__DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN11__DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN11_1 Bits */
/* SHAW_EIP59_DATA_IN11_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN11_1_DATA_IN_OFS       (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN11_1_DATA_IN_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN12_ Bits */
/* SHAW_EIP59_DATA_IN12_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN12__DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN12__DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN12_1 Bits */
/* SHAW_EIP59_DATA_IN12_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN12_1_DATA_IN_OFS       (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN12_1_DATA_IN_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN13_ Bits */
/* SHAW_EIP59_DATA_IN13_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN13__DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN13__DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN13_1 Bits */
/* SHAW_EIP59_DATA_IN13_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN13_1_DATA_IN_OFS       (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN13_1_DATA_IN_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN14_ Bits */
/* SHAW_EIP59_DATA_IN14_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN14__DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN14__DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN14_1 Bits */
/* SHAW_EIP59_DATA_IN14_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN14_1_DATA_IN_OFS       (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN14_1_DATA_IN_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN15_ Bits */
/* SHAW_EIP59_DATA_IN15_[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN15__DATA_IN_OFS        (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN15__DATA_IN_MASK       ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_DATA_IN15_1 Bits */
/* SHAW_EIP59_DATA_IN15_1[DATA_IN] Bits */
#define SHAW_EIP59_DATA_IN15_1_DATA_IN_OFS       (0)                             /* !< DATA_IN Offset */
#define SHAW_EIP59_DATA_IN15_1_DATA_IN_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Input Data on which hash is
                                                                                    computed */

/* SHAW_EIP59_IO_BUF_CTRL_STAT Bits */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[OUTBUF_FULL] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_OUTBUF_FULL_OFS (0)                             /* !< OUTBUF_FULL Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_OUTBUF_FULL_MASK ((uint32_t)0x00000001U)         /* !< Indicates output is available,
                                                                                    needs to be written 1 to clear this
                                                                                    bit before starting new hash */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[DATA_IN_AV] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_DATA_IN_AV_OFS (1)                             /* !< DATA_IN_AV Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_DATA_IN_AV_MASK ((uint32_t)0x00000002U)         /* !< Indicates that the EIP59_DATA_IN_x
                                                                                    registers contain a new input data
                                                                                    block for processing. #br#The Host
                                                                                    must write a 1b to this bit to start
                                                                                    an operation on the data in
                                                                                    EIP59_DATA_IN_x as soon as the EIP-59
                                                                                    engine is ready to process new input
                                                                                    data. #br#Alternatively, when DMA is
                                                                                    selected, asserting input signal
                                                                                    dma_in_clear to 1b must be used
                                                                                    instead to start processing new input
                                                                                    data. As an exception, the data_in_av
                                                                                    bit must only be used to start
                                                                                    processing a zero length message.
                                                                                    #br#Writing a '0' to the data_in_av
                                                                                    bit has no effect. #br#This bit is
                                                                                    automatically cleared (i.e. reads 0b)
                                                                                    when the Wide bus EIP-59 engine has
                                                                                    copied the EIP59_DATA_IN_x contents.
                                                                                    This bit reads as 1b between the time
                                                                                    it was set by the Host and the Wide
                                                                                    bus EIP-59 engine has started
                                                                                    processing the new input block. */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[LENGTH_IN_AV] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_LENGTH_IN_AV_OFS (2)                             /* !< LENGTH_IN_AV Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_LENGTH_IN_AV_MASK ((uint32_t)0x00000004U)         /* !< Write 1 to indicate length is
                                                                                    available */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[MODE_IN_AV] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_MODE_IN_AV_OFS (3)                             /* !< MODE_IN_AV Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_MODE_IN_AV_MASK ((uint32_t)0x00000008U)         /* !< Write 1 to indicate mode is
                                                                                    available */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[IDIGEST_IN_AV] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_IDIGEST_IN_AV_OFS (4)                             /* !< IDIGEST_IN_AV Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_IDIGEST_IN_AV_MASK ((uint32_t)0x00000010U)         /* !< Write 1 to indicate idigest is
                                                                                    available */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[ODIGEST_IN_AV] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_ODIGEST_IN_AV_OFS (5)                             /* !< ODIGEST_IN_AV Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_ODIGEST_IN_AV_MASK ((uint32_t)0x00000020U)         /* !< Write 1 to indicate odigest is
                                                                                    available */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[PAD_MESSAGE] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_PAD_MESSAGE_OFS (6)                             /* !< PAD_MESSAGE Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_PAD_MESSAGE_MASK ((uint32_t)0x00000040U)         /* !< Write 1 to pad the message */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[GET_DIGEST] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_GET_DIGEST_OFS (7)                             /* !< GET_DIGEST Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_GET_DIGEST_MASK ((uint32_t)0x00000080U)         /* !< Write 1 to get the digest on the
                                                                                    digest out registers */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[IDIGEST_OUT_AV] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_IDIGEST_OUT_AV_OFS (12)                            /* !< IDIGEST_OUT_AV Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_IDIGEST_OUT_AV_MASK ((uint32_t)0x00001000U)         /* !< Status to indicate idigest out is
                                                                                    available */
/* SHAW_EIP59_IO_BUF_CTRL_STAT[ODIGEST_OUT_AV] Bits */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_ODIGEST_OUT_AV_OFS (13)                            /* !< ODIGEST_OUT_AV Offset */
#define SHAW_EIP59_IO_BUF_CTRL_STAT_ODIGEST_OUT_AV_MASK ((uint32_t)0x00002000U)         /* !< Status to indicate odigest out is
                                                                                    available */

/* SHAW_EIP59_IOBUF_CTRL_STAT_1 Bits */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[OUTBUF_FULL] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_OUTBUF_FULL_OFS (0)                             /* !< OUTBUF_FULL Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_OUTBUF_FULL_MASK ((uint32_t)0x00000001U)         /* !< Indicates output is available,
                                                                                    needs to be written 1 to clear this
                                                                                    bit before starting new hash */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[DATA_IN_AV] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_DATA_IN_AV_OFS (1)                             /* !< DATA_IN_AV Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_DATA_IN_AV_MASK ((uint32_t)0x00000002U)         /* !< Indicates that the EIP59_DATA_IN_x
                                                                                    registers contain a new input data
                                                                                    block for processing. #br#The Host
                                                                                    must write a 1b to this bit to start
                                                                                    an operation on the data in
                                                                                    EIP59_DATA_IN_x as soon as the EIP-59
                                                                                    engine is ready to process new input
                                                                                    data. #br#Alternatively, when DMA is
                                                                                    selected, asserting input signal
                                                                                    dma_in_clear to 1b must be used
                                                                                    instead to start processing new input
                                                                                    data. As an exception, the data_in_av
                                                                                    bit must only be used to start
                                                                                    processing a zero length message.
                                                                                    #br#Writing a '0' to the data_in_av
                                                                                    bit has no effect. #br#This bit is
                                                                                    automatically cleared (i.e. reads 0b)
                                                                                    when the Wide bus EIP-59 engine has
                                                                                    copied the EIP59_DATA_IN_x contents.
                                                                                    This bit reads as 1b between the time
                                                                                    it was set by the Host and the Wide
                                                                                    bus EIP-59 engine has started
                                                                                    processing the new input block. */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[LENGTH_IN_AV] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_LENGTH_IN_AV_OFS (2)                             /* !< LENGTH_IN_AV Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_LENGTH_IN_AV_MASK ((uint32_t)0x00000004U)         /* !< Write 1 to indicate length is
                                                                                    available */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[MODE_IN_AV] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_MODE_IN_AV_OFS (3)                             /* !< MODE_IN_AV Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_MODE_IN_AV_MASK ((uint32_t)0x00000008U)         /* !< Write 1 to indicate mode is
                                                                                    available */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[IDIGEST_IN_AV] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_IDIGEST_IN_AV_OFS (4)                             /* !< IDIGEST_IN_AV Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_IDIGEST_IN_AV_MASK ((uint32_t)0x00000010U)         /* !< Write 1 to indicate idigest is
                                                                                    available */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[ODIGEST_IN_AV] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_ODIGEST_IN_AV_OFS (5)                             /* !< ODIGEST_IN_AV Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_ODIGEST_IN_AV_MASK ((uint32_t)0x00000020U)         /* !< Write 1 to indicate odigest is
                                                                                    available */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[PAD_MESSAGE] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_PAD_MESSAGE_OFS (6)                             /* !< PAD_MESSAGE Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_PAD_MESSAGE_MASK ((uint32_t)0x00000040U)         /* !< Write 1 to pad the message */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[GET_DIGEST] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_GET_DIGEST_OFS (7)                             /* !< GET_DIGEST Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_GET_DIGEST_MASK ((uint32_t)0x00000080U)         /* !< Write 1 to get the digest on the
                                                                                    digest out registers */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[IDIGEST_OUT_AV] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_IDIGEST_OUT_AV_OFS (12)                            /* !< IDIGEST_OUT_AV Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_IDIGEST_OUT_AV_MASK ((uint32_t)0x00001000U)         /* !< Status to indicate idigest out is
                                                                                    available */
/* SHAW_EIP59_IOBUF_CTRL_STAT_1[ODIGEST_OUT_AV] Bits */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_ODIGEST_OUT_AV_OFS (13)                            /* !< ODIGEST_OUT_AV Offset */
#define SHAW_EIP59_IOBUF_CTRL_STAT_1_ODIGEST_OUT_AV_MASK ((uint32_t)0x00002000U)         /* !< Status to indicate odigest out is
                                                                                    available */

/* SHAW_EIP59_MODE_IN Bits */
/* SHAW_EIP59_MODE_IN[HASH_HMAC] Bits */
#define SHAW_EIP59_MODE_IN_HASH_HMAC_OFS         (0)                             /* !< HASH_HMAC Offset */
#define SHAW_EIP59_MODE_IN_HASH_HMAC_MASK        ((uint32_t)0x00000001U)         /* !< Write 1 to indicate if it is hmac
                                                                                    operation */
/* SHAW_EIP59_MODE_IN[MAC_KEY] Bits */
#define SHAW_EIP59_MODE_IN_MAC_KEY_OFS           (1)                             /* !< MAC_KEY Offset */
#define SHAW_EIP59_MODE_IN_MAC_KEY_MASK          ((uint32_t)0x00000002U)         /* !< Write 1 to indicate mac key
                                                                                    computation */
/* SHAW_EIP59_MODE_IN[NEW_HASH] Bits */
#define SHAW_EIP59_MODE_IN_NEW_HASH_OFS          (2)                             /* !< NEW_HASH Offset */
#define SHAW_EIP59_MODE_IN_NEW_HASH_MASK         ((uint32_t)0x00000004U)         /* !< Write 1 to indicate new hash
                                                                                    computation */
/* SHAW_EIP59_MODE_IN[SHA_256] Bits */
#define SHAW_EIP59_MODE_IN_SHA_256_OFS           (5)                             /* !< SHA_256 Offset */
#define SHAW_EIP59_MODE_IN_SHA_256_MASK          ((uint32_t)0x00000020U)         /* !< Write 1 to compute hash in sha 256
                                                                                    mode, while reading back this
                                                                                    information will be available in 3rd
                                                                                    bit instead of 5th bit and 5th bit
                                                                                    remains reserved */
/* SHAW_EIP59_MODE_IN[SHA_224] Bits */
#define SHAW_EIP59_MODE_IN_SHA_224_OFS           (6)                             /* !< SHA_224 Offset */
#define SHAW_EIP59_MODE_IN_SHA_224_MASK          ((uint32_t)0x00000040U)         /* !< Write 1 to compute hash in sha 224
                                                                                    mode, while reading back this
                                                                                    information will be available in 4rd
                                                                                    bit instead of 6th bit and 6th bit
                                                                                    remains reserved */

/* SHAW_EIP59_MODE_IN_1 Bits */
/* SHAW_EIP59_MODE_IN_1[HASH_HMAC] Bits */
#define SHAW_EIP59_MODE_IN_1_HASH_HMAC_OFS       (0)                             /* !< HASH_HMAC Offset */
#define SHAW_EIP59_MODE_IN_1_HASH_HMAC_MASK      ((uint32_t)0x00000001U)         /* !< Write 1 to indicate if it is hmac
                                                                                    operation */
/* SHAW_EIP59_MODE_IN_1[MAC_KEY] Bits */
#define SHAW_EIP59_MODE_IN_1_MAC_KEY_OFS         (1)                             /* !< MAC_KEY Offset */
#define SHAW_EIP59_MODE_IN_1_MAC_KEY_MASK        ((uint32_t)0x00000002U)         /* !< Write 1 to indicate mac key
                                                                                    computation */
/* SHAW_EIP59_MODE_IN_1[NEW_HASH] Bits */
#define SHAW_EIP59_MODE_IN_1_NEW_HASH_OFS        (2)                             /* !< NEW_HASH Offset */
#define SHAW_EIP59_MODE_IN_1_NEW_HASH_MASK       ((uint32_t)0x00000004U)         /* !< Write 1 to indicate new hash
                                                                                    computation */
/* SHAW_EIP59_MODE_IN_1[SHA_256] Bits */
#define SHAW_EIP59_MODE_IN_1_SHA_256_OFS         (5)                             /* !< SHA_256 Offset */
#define SHAW_EIP59_MODE_IN_1_SHA_256_MASK        ((uint32_t)0x00000020U)         /* !< Write 1 to compute hash in sha 256
                                                                                    mode, while reading back this
                                                                                    information will be available in 3rd
                                                                                    bit instead of 5th bit and 5th bit
                                                                                    remains reserved */
/* SHAW_EIP59_MODE_IN_1[SHA_224] Bits */
#define SHAW_EIP59_MODE_IN_1_SHA_224_OFS         (6)                             /* !< SHA_224 Offset */
#define SHAW_EIP59_MODE_IN_1_SHA_224_MASK        ((uint32_t)0x00000040U)         /* !< Write 1 to compute hash in sha 224
                                                                                    mode, while reading back this
                                                                                    information will be available in 4rd
                                                                                    bit instead of 6th bit and 6th bit
                                                                                    remains reserved */

/* SHAW_EIP59_LENGTH_IN_L Bits */
/* SHAW_EIP59_LENGTH_IN_L[LENGTH_LSB] Bits */
#define SHAW_EIP59_LENGTH_IN_L_LENGTH_LSB_OFS    (0)                             /* !< LENGTH_LSB Offset */
#define SHAW_EIP59_LENGTH_IN_L_LENGTH_LSB_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Data Length LSB */

/* SHAW_EIP59_LENGTH_IN_L_1 Bits */
/* SHAW_EIP59_LENGTH_IN_L_1[LENGTH_LSB] Bits */
#define SHAW_EIP59_LENGTH_IN_L_1_LENGTH_LSB_OFS  (0)                             /* !< LENGTH_LSB Offset */
#define SHAW_EIP59_LENGTH_IN_L_1_LENGTH_LSB_MASK ((uint32_t)0xFFFFFFFFU)         /* !< Data Length LSB */

/* SHAW_EIP59_LENGTH_IN_H Bits */
/* SHAW_EIP59_LENGTH_IN_H[LENGTH_MSB] Bits */
#define SHAW_EIP59_LENGTH_IN_H_LENGTH_MSB_OFS    (0)                             /* !< LENGTH_MSB Offset */
#define SHAW_EIP59_LENGTH_IN_H_LENGTH_MSB_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Data Length MSB */

/* SHAW_EIP59_LENGTH_IN_H_1 Bits */
/* SHAW_EIP59_LENGTH_IN_H_1[LENGTH_MSB] Bits */
#define SHAW_EIP59_LENGTH_IN_H_1_LENGTH_MSB_OFS  (0)                             /* !< LENGTH_MSB Offset */
#define SHAW_EIP59_LENGTH_IN_H_1_LENGTH_MSB_MASK ((uint32_t)0xFFFFFFFFU)         /* !< Data Length MSB */

/* SHAW_EIP59_IDIGEST_A Bits */
/* SHAW_EIP59_IDIGEST_A[IDIGEST_A] Bits */
#define SHAW_EIP59_IDIGEST_A_IDIGEST_A_OFS       (0)                             /* !< IDIGEST_A Offset */
#define SHAW_EIP59_IDIGEST_A_IDIGEST_A_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest A */

/* SHAW_EIP59_IDIGEST_A_1 Bits */
/* SHAW_EIP59_IDIGEST_A_1[IDIGEST_A] Bits */
#define SHAW_EIP59_IDIGEST_A_1_IDIGEST_A_OFS     (0)                             /* !< IDIGEST_A Offset */
#define SHAW_EIP59_IDIGEST_A_1_IDIGEST_A_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest A */

/* SHAW_EIP59_IDIGEST_B Bits */
/* SHAW_EIP59_IDIGEST_B[IDIGEST_B] Bits */
#define SHAW_EIP59_IDIGEST_B_IDIGEST_B_OFS       (0)                             /* !< IDIGEST_B Offset */
#define SHAW_EIP59_IDIGEST_B_IDIGEST_B_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest B */

/* SHAW_EIP59_IDIGEST_B_1 Bits */
/* SHAW_EIP59_IDIGEST_B_1[IDIGEST_B] Bits */
#define SHAW_EIP59_IDIGEST_B_1_IDIGEST_B_OFS     (0)                             /* !< IDIGEST_B Offset */
#define SHAW_EIP59_IDIGEST_B_1_IDIGEST_B_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest B */

/* SHAW_EIP59_IDIGEST_C Bits */
/* SHAW_EIP59_IDIGEST_C[IDIGEST_C] Bits */
#define SHAW_EIP59_IDIGEST_C_IDIGEST_C_OFS       (0)                             /* !< IDIGEST_C Offset */
#define SHAW_EIP59_IDIGEST_C_IDIGEST_C_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest C */

/* SHAW_EIP59_IDIGEST_C_1 Bits */
/* SHAW_EIP59_IDIGEST_C_1[IDIGEST_C] Bits */
#define SHAW_EIP59_IDIGEST_C_1_IDIGEST_C_OFS     (0)                             /* !< IDIGEST_C Offset */
#define SHAW_EIP59_IDIGEST_C_1_IDIGEST_C_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest C */

/* SHAW_EIP59_IDIGEST_D Bits */
/* SHAW_EIP59_IDIGEST_D[IDIGEST_D] Bits */
#define SHAW_EIP59_IDIGEST_D_IDIGEST_D_OFS       (0)                             /* !< IDIGEST_D Offset */
#define SHAW_EIP59_IDIGEST_D_IDIGEST_D_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest D */

/* SHAW_EIP59_IDIGEST_D_1 Bits */
/* SHAW_EIP59_IDIGEST_D_1[IDIGEST_D] Bits */
#define SHAW_EIP59_IDIGEST_D_1_IDIGEST_D_OFS     (0)                             /* !< IDIGEST_D Offset */
#define SHAW_EIP59_IDIGEST_D_1_IDIGEST_D_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest D */

/* SHAW_EIP59_IDIGEST_E Bits */
/* SHAW_EIP59_IDIGEST_E[IDIGEST_E] Bits */
#define SHAW_EIP59_IDIGEST_E_IDIGEST_E_OFS       (0)                             /* !< IDIGEST_E Offset */
#define SHAW_EIP59_IDIGEST_E_IDIGEST_E_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest E */

/* SHAW_EIP59_IDIGEST_E_1 Bits */
/* SHAW_EIP59_IDIGEST_E_1[IDIGEST_E] Bits */
#define SHAW_EIP59_IDIGEST_E_1_IDIGEST_E_OFS     (0)                             /* !< IDIGEST_E Offset */
#define SHAW_EIP59_IDIGEST_E_1_IDIGEST_E_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest E */

/* SHAW_EIP59_IDIGEST_F Bits */
/* SHAW_EIP59_IDIGEST_F[IDIGEST_F] Bits */
#define SHAW_EIP59_IDIGEST_F_IDIGEST_F_OFS       (0)                             /* !< IDIGEST_F Offset */
#define SHAW_EIP59_IDIGEST_F_IDIGEST_F_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest F */

/* SHAW_EIP59_IDIGEST_F_1 Bits */
/* SHAW_EIP59_IDIGEST_F_1[IDIGEST_F] Bits */
#define SHAW_EIP59_IDIGEST_F_1_IDIGEST_F_OFS     (0)                             /* !< IDIGEST_F Offset */
#define SHAW_EIP59_IDIGEST_F_1_IDIGEST_F_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest F */

/* SHAW_EIP59_IDIGEST_G Bits */
/* SHAW_EIP59_IDIGEST_G[IDIGEST_G] Bits */
#define SHAW_EIP59_IDIGEST_G_IDIGEST_G_OFS       (0)                             /* !< IDIGEST_G Offset */
#define SHAW_EIP59_IDIGEST_G_IDIGEST_G_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest G */

/* SHAW_EIP59_IDIGEST_G_1 Bits */
/* SHAW_EIP59_IDIGEST_G_1[IDIGEST_G] Bits */
#define SHAW_EIP59_IDIGEST_G_1_IDIGEST_G_OFS     (0)                             /* !< IDIGEST_G Offset */
#define SHAW_EIP59_IDIGEST_G_1_IDIGEST_G_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest G */

/* SHAW_EIP59_IDIGEST_H Bits */
/* SHAW_EIP59_IDIGEST_H[IDIGEST_H] Bits */
#define SHAW_EIP59_IDIGEST_H_IDIGEST_H_OFS       (0)                             /* !< IDIGEST_H Offset */
#define SHAW_EIP59_IDIGEST_H_IDIGEST_H_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest H */

/* SHAW_EIP59_IDIGEST_H_1 Bits */
/* SHAW_EIP59_IDIGEST_H_1[IDIGEST_H] Bits */
#define SHAW_EIP59_IDIGEST_H_1_IDIGEST_H_OFS     (0)                             /* !< IDIGEST_H Offset */
#define SHAW_EIP59_IDIGEST_H_1_IDIGEST_H_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Inner Digest H */

/* SHAW_EIP59_ODIGEST_A Bits */
/* SHAW_EIP59_ODIGEST_A[ODIGEST_A] Bits */
#define SHAW_EIP59_ODIGEST_A_ODIGEST_A_OFS       (0)                             /* !< ODIGEST_A Offset */
#define SHAW_EIP59_ODIGEST_A_ODIGEST_A_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest A */

/* SHAW_EIP59_ODIGEST_A_1 Bits */
/* SHAW_EIP59_ODIGEST_A_1[ODIGEST_A] Bits */
#define SHAW_EIP59_ODIGEST_A_1_ODIGEST_A_OFS     (0)                             /* !< ODIGEST_A Offset */
#define SHAW_EIP59_ODIGEST_A_1_ODIGEST_A_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest A */

/* SHAW_EIP59_ODIGEST_B Bits */
/* SHAW_EIP59_ODIGEST_B[ODIGEST_B] Bits */
#define SHAW_EIP59_ODIGEST_B_ODIGEST_B_OFS       (0)                             /* !< ODIGEST_B Offset */
#define SHAW_EIP59_ODIGEST_B_ODIGEST_B_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest B */

/* SHAW_EIP59_ODIGEST_B_1 Bits */
/* SHAW_EIP59_ODIGEST_B_1[ODIGEST_B] Bits */
#define SHAW_EIP59_ODIGEST_B_1_ODIGEST_B_OFS     (0)                             /* !< ODIGEST_B Offset */
#define SHAW_EIP59_ODIGEST_B_1_ODIGEST_B_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest B */

/* SHAW_EIP59_ODIGEST_C Bits */
/* SHAW_EIP59_ODIGEST_C[ODIGEST_C] Bits */
#define SHAW_EIP59_ODIGEST_C_ODIGEST_C_OFS       (0)                             /* !< ODIGEST_C Offset */
#define SHAW_EIP59_ODIGEST_C_ODIGEST_C_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest C */

/* SHAW_EIP59_ODIGEST_C_1 Bits */
/* SHAW_EIP59_ODIGEST_C_1[ODIGEST_C] Bits */
#define SHAW_EIP59_ODIGEST_C_1_ODIGEST_C_OFS     (0)                             /* !< ODIGEST_C Offset */
#define SHAW_EIP59_ODIGEST_C_1_ODIGEST_C_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest C */

/* SHAW_EIP59_ODIGEST_D Bits */
/* SHAW_EIP59_ODIGEST_D[ODIGEST_D] Bits */
#define SHAW_EIP59_ODIGEST_D_ODIGEST_D_OFS       (0)                             /* !< ODIGEST_D Offset */
#define SHAW_EIP59_ODIGEST_D_ODIGEST_D_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest D */

/* SHAW_EIP59_ODIGEST_D_1 Bits */
/* SHAW_EIP59_ODIGEST_D_1[ODIGEST_D] Bits */
#define SHAW_EIP59_ODIGEST_D_1_ODIGEST_D_OFS     (0)                             /* !< ODIGEST_D Offset */
#define SHAW_EIP59_ODIGEST_D_1_ODIGEST_D_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest D */

/* SHAW_EIP59_ODIGEST_E Bits */
/* SHAW_EIP59_ODIGEST_E[ODIGEST_E] Bits */
#define SHAW_EIP59_ODIGEST_E_ODIGEST_E_OFS       (0)                             /* !< ODIGEST_E Offset */
#define SHAW_EIP59_ODIGEST_E_ODIGEST_E_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest E */

/* SHAW_EIP59_ODIGEST_E_1 Bits */
/* SHAW_EIP59_ODIGEST_E_1[ODIGEST_E] Bits */
#define SHAW_EIP59_ODIGEST_E_1_ODIGEST_E_OFS     (0)                             /* !< ODIGEST_E Offset */
#define SHAW_EIP59_ODIGEST_E_1_ODIGEST_E_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest E */

/* SHAW_EIP59_ODIGEST_F Bits */
/* SHAW_EIP59_ODIGEST_F[ODIGEST_F] Bits */
#define SHAW_EIP59_ODIGEST_F_ODIGEST_F_OFS       (0)                             /* !< ODIGEST_F Offset */
#define SHAW_EIP59_ODIGEST_F_ODIGEST_F_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest F */

/* SHAW_EIP59_ODIGEST_F_1 Bits */
/* SHAW_EIP59_ODIGEST_F_1[ODIGEST_F] Bits */
#define SHAW_EIP59_ODIGEST_F_1_ODIGEST_F_OFS     (0)                             /* !< ODIGEST_F Offset */
#define SHAW_EIP59_ODIGEST_F_1_ODIGEST_F_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest F */

/* SHAW_EIP59_ODIGEST_G Bits */
/* SHAW_EIP59_ODIGEST_G[ODIGEST_G] Bits */
#define SHAW_EIP59_ODIGEST_G_ODIGEST_G_OFS       (0)                             /* !< ODIGEST_G Offset */
#define SHAW_EIP59_ODIGEST_G_ODIGEST_G_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest G */

/* SHAW_EIP59_ODIGEST_G_1 Bits */
/* SHAW_EIP59_ODIGEST_G_1[ODIGEST_G] Bits */
#define SHAW_EIP59_ODIGEST_G_1_ODIGEST_G_OFS     (0)                             /* !< ODIGEST_G Offset */
#define SHAW_EIP59_ODIGEST_G_1_ODIGEST_G_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest G */

/* SHAW_EIP59_ODIGEST_H Bits */
/* SHAW_EIP59_ODIGEST_H[ODIGEST_H] Bits */
#define SHAW_EIP59_ODIGEST_H_ODIGEST_H_OFS       (0)                             /* !< ODIGEST_H Offset */
#define SHAW_EIP59_ODIGEST_H_ODIGEST_H_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest H */

/* SHAW_EIP59_ODIGEST_H_1 Bits */
/* SHAW_EIP59_ODIGEST_H_1[ODIGEST_H] Bits */
#define SHAW_EIP59_ODIGEST_H_1_ODIGEST_H_OFS     (0)                             /* !< ODIGEST_H Offset */
#define SHAW_EIP59_ODIGEST_H_1_ODIGEST_H_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Outer Digest H */

/* SHAW_EIP59_DIGEST_A Bits */
/* SHAW_EIP59_DIGEST_A[DIGEST_A] Bits */
#define SHAW_EIP59_DIGEST_A_DIGEST_A_OFS         (0)                             /* !< DIGEST_A Offset */
#define SHAW_EIP59_DIGEST_A_DIGEST_A_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output A */

/* SHAW_EIP59_DIGEST_A_1 Bits */
/* SHAW_EIP59_DIGEST_A_1[DIGEST_A] Bits */
#define SHAW_EIP59_DIGEST_A_1_DIGEST_A_OFS       (0)                             /* !< DIGEST_A Offset */
#define SHAW_EIP59_DIGEST_A_1_DIGEST_A_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output A */

/* SHAW_EIP59_DIGEST_B Bits */
/* SHAW_EIP59_DIGEST_B[DIGEST_B] Bits */
#define SHAW_EIP59_DIGEST_B_DIGEST_B_OFS         (0)                             /* !< DIGEST_B Offset */
#define SHAW_EIP59_DIGEST_B_DIGEST_B_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output B */

/* SHAW_EIP59_DIGEST_B_1 Bits */
/* SHAW_EIP59_DIGEST_B_1[DIGEST_B] Bits */
#define SHAW_EIP59_DIGEST_B_1_DIGEST_B_OFS       (0)                             /* !< DIGEST_B Offset */
#define SHAW_EIP59_DIGEST_B_1_DIGEST_B_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output B */

/* SHAW_EIP59_DIGEST_C Bits */
/* SHAW_EIP59_DIGEST_C[DIGEST_C] Bits */
#define SHAW_EIP59_DIGEST_C_DIGEST_C_OFS         (0)                             /* !< DIGEST_C Offset */
#define SHAW_EIP59_DIGEST_C_DIGEST_C_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output C */

/* SHAW_EIP59_DIGEST_C_1 Bits */
/* SHAW_EIP59_DIGEST_C_1[DIGEST_C] Bits */
#define SHAW_EIP59_DIGEST_C_1_DIGEST_C_OFS       (0)                             /* !< DIGEST_C Offset */
#define SHAW_EIP59_DIGEST_C_1_DIGEST_C_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output C */

/* SHAW_EIP59_DIGEST_D Bits */
/* SHAW_EIP59_DIGEST_D[DIGEST_D] Bits */
#define SHAW_EIP59_DIGEST_D_DIGEST_D_OFS         (0)                             /* !< DIGEST_D Offset */
#define SHAW_EIP59_DIGEST_D_DIGEST_D_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output D */

/* SHAW_EIP59_DIGEST_D_1 Bits */
/* SHAW_EIP59_DIGEST_D_1[DIGEST_D] Bits */
#define SHAW_EIP59_DIGEST_D_1_DIGEST_D_OFS       (0)                             /* !< DIGEST_D Offset */
#define SHAW_EIP59_DIGEST_D_1_DIGEST_D_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output D */

/* SHAW_EIP59_DIGEST_E Bits */
/* SHAW_EIP59_DIGEST_E[DIGEST_E] Bits */
#define SHAW_EIP59_DIGEST_E_DIGEST_E_OFS         (0)                             /* !< DIGEST_E Offset */
#define SHAW_EIP59_DIGEST_E_DIGEST_E_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output E */

/* SHAW_EIP59_DIGEST_E_1 Bits */
/* SHAW_EIP59_DIGEST_E_1[DIGEST_E] Bits */
#define SHAW_EIP59_DIGEST_E_1_DIGEST_E_OFS       (0)                             /* !< DIGEST_E Offset */
#define SHAW_EIP59_DIGEST_E_1_DIGEST_E_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output E */

/* SHAW_EIP59_DIGEST_F Bits */
/* SHAW_EIP59_DIGEST_F[DIGEST_F] Bits */
#define SHAW_EIP59_DIGEST_F_DIGEST_F_OFS         (0)                             /* !< DIGEST_F Offset */
#define SHAW_EIP59_DIGEST_F_DIGEST_F_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output F */

/* SHAW_EIP59_DIGEST_F_1 Bits */
/* SHAW_EIP59_DIGEST_F_1[DIGEST_F] Bits */
#define SHAW_EIP59_DIGEST_F_1_DIGEST_F_OFS       (0)                             /* !< DIGEST_F Offset */
#define SHAW_EIP59_DIGEST_F_1_DIGEST_F_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output F */

/* SHAW_EIP59_DIGEST_G Bits */
/* SHAW_EIP59_DIGEST_G[DIGEST_G] Bits */
#define SHAW_EIP59_DIGEST_G_DIGEST_G_OFS         (0)                             /* !< DIGEST_G Offset */
#define SHAW_EIP59_DIGEST_G_DIGEST_G_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output G */

/* SHAW_EIP59_DIGEST_G_1 Bits */
/* SHAW_EIP59_DIGEST_G_1[DIGEST_G] Bits */
#define SHAW_EIP59_DIGEST_G_1_DIGEST_G_OFS       (0)                             /* !< DIGEST_G Offset */
#define SHAW_EIP59_DIGEST_G_1_DIGEST_G_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output G */

/* SHAW_EIP59_DIGEST_H Bits */
/* SHAW_EIP59_DIGEST_H[DIGEST_H] Bits */
#define SHAW_EIP59_DIGEST_H_DIGEST_H_OFS         (0)                             /* !< DIGEST_H Offset */
#define SHAW_EIP59_DIGEST_H_DIGEST_H_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output H */

/* SHAW_EIP59_DIGEST_H_1 Bits */
/* SHAW_EIP59_DIGEST_H_1[DIGEST_H] Bits */
#define SHAW_EIP59_DIGEST_H_1_DIGEST_H_OFS       (0)                             /* !< DIGEST_H Offset */
#define SHAW_EIP59_DIGEST_H_1_DIGEST_H_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Digest Output H */

/* SHAW_EIP59_CONFIG Bits */
/* SHAW_EIP59_CONFIG[CONFIG] Bits */
#define SHAW_EIP59_CONFIG_CONFIG_OFS             (0)                             /* !< CONFIG Offset */
#define SHAW_EIP59_CONFIG_CONFIG_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Configuration Register = 0x01400019 */

/* SHAW_EIP59_CONFIG_1 Bits */
/* SHAW_EIP59_CONFIG_1[CONFIG] Bits */
#define SHAW_EIP59_CONFIG_1_CONFIG_OFS           (0)                             /* !< CONFIG Offset */
#define SHAW_EIP59_CONFIG_1_CONFIG_MASK          ((uint32_t)0xFFFFFFFFU)         /* !< Configuration Register = 0x01400019 */

/* SHAW_EIP59_VERSION Bits */
/* SHAW_EIP59_VERSION[VERSION] Bits */
#define SHAW_EIP59_VERSION_VERSION_OFS           (0)                             /* !< VERSION Offset */
#define SHAW_EIP59_VERSION_VERSION_MASK          ((uint32_t)0xFFFFFFFFU)         /* !< Version Register = 0x2240C43B */

/* SHAW_EIP59_VERSION_1 Bits */
/* SHAW_EIP59_VERSION_1[VERSION] Bits */
#define SHAW_EIP59_VERSION_1_VERSION_OFS         (0)                             /* !< VERSION Offset */
#define SHAW_EIP59_VERSION_1_VERSION_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Version Register = 0x2240C43B */

/* SHAW_PWREN Bits */
/* SHAW_PWREN[ENABLE] Bits */
#define SHAW_PWREN_ENABLE_OFS                    (0)                             /* !< ENABLE Offset */
#define SHAW_PWREN_ENABLE_MASK                   ((uint32_t)0x00000001U)         /* !< Enable the power */
#define SHAW_PWREN_ENABLE_DISABLE                ((uint32_t)0x00000000U)         /* !< Disable Power */
#define SHAW_PWREN_ENABLE_ENABLE                 ((uint32_t)0x00000001U)         /* !< Enable Power */
/* SHAW_PWREN[KEY] Bits */
#define SHAW_PWREN_KEY_OFS                       (24)                            /* !< KEY Offset */
#define SHAW_PWREN_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define SHAW_PWREN_KEY_UNLOCK_W                  ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* SHAW_RSTCTL Bits */
/* SHAW_RSTCTL[RESETSTKYCLR] Bits */
#define SHAW_RSTCTL_RESETSTKYCLR_OFS             (1)                             /* !< RESETSTKYCLR Offset */
#define SHAW_RSTCTL_RESETSTKYCLR_MASK            ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define SHAW_RSTCTL_RESETSTKYCLR_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SHAW_RSTCTL_RESETSTKYCLR_CLR             ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* SHAW_RSTCTL[RESETASSERT] Bits */
#define SHAW_RSTCTL_RESETASSERT_OFS              (0)                             /* !< RESETASSERT Offset */
#define SHAW_RSTCTL_RESETASSERT_MASK             ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define SHAW_RSTCTL_RESETASSERT_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define SHAW_RSTCTL_RESETASSERT_ASSERT           ((uint32_t)0x00000001U)         /* !< Assert reset */
/* SHAW_RSTCTL[KEY] Bits */
#define SHAW_RSTCTL_KEY_OFS                      (24)                            /* !< KEY Offset */
#define SHAW_RSTCTL_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define SHAW_RSTCTL_KEY_UNLOCK_W                 ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* SHAW_STAT Bits */
/* SHAW_STAT[RESETSTKY] Bits */
#define SHAW_STAT_RESETSTKY_OFS                  (16)                            /* !< RESETSTKY Offset */
#define SHAW_STAT_RESETSTKY_MASK                 ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define SHAW_STAT_RESETSTKY_NORES                ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define SHAW_STAT_RESETSTKY_RESET                ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_shaw__include */

