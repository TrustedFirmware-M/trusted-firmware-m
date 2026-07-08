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

#ifndef ti_devices_msp_peripherals_hw_pka__include
#define ti_devices_msp_peripherals_hw_pka__include

/* This preliminary header file does not have a version number */
/* Filename: hw_pka.h */
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
* PKA Registers
******************************************************************************/
#define PKA_GPRCM_OFS                            ((uint32_t)0x00000800U)
#define PKA_PKA_REGS_OFS                         ((uint32_t)0x00000000U)


/** @addtogroup PKA_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} PKA_GPRCM_Regs;

/*@}*/ /* end of group PKA_GPRCM */

/** @addtogroup PKA_PKA_REGS
  @{
*/

typedef struct {
  __IO uint32_t PKA_APTR;                          /* !< (@ 0x00014000) A operand address offset */
  __IO uint32_t PKA_BPTR;                          /* !< (@ 0x00014004) B operand address offset */
  __IO uint32_t PKA_CPTR;                          /* !< (@ 0x00014008) C operand address offset */
  __IO uint32_t PKA_DPTR;                          /* !< (@ 0x0001400C) D operand address offset */
  __IO uint32_t PKA_ALENGTH;                       /* !< (@ 0x00014010) Length of A operand */
  __IO uint32_t PKA_BLENGTH;                       /* !< (@ 0x00014014) Length of B operand */
  __IO uint32_t PKA_SHIFT;                         /* !< (@ 0x00014018) Bits to shift */
  __IO uint32_t PKA_FUNCTION;                      /* !< (@ 0x0001401C) Function code, Run control/status, Stall Result
                                                      control */
  __IO uint32_t PKA_COMPARE;                       /* !< (@ 0x00014020) Result of compare */
  __IO uint32_t PKA_MSW;                           /* !< (@ 0x00014024) MS non-zero word address */
  __IO uint32_t PKA_DIVMSW;                        /* !< (@ 0x00014028) MS non-zero word address for remainder (MOD and
                                                      DIV ops) */
  __IO uint32_t Reserved_2;                        /* !< (@ 0x0001402C) */
  __IO uint32_t PKA_ISTA_CTRL;                     /* !< (@ 0x00014030) Protection logic test/status bits of the PKCP */
  __IO uint32_t Reserved_3[36];                    /* !< (@ 0x00014034) */
  __IO uint32_t PKCP_PRIO_CTRL;                    /* !< (@ 0x000140C4) Sequencer control, status, reset, bank switch
                                                      register */
  __IO uint32_t PKA_SEQ_CTRL;                      /* !< (@ 0x000140C8) Sequencer control, program RAM bank, status, reset */
  __IO uint32_t Reserved_4;                        /* !< (@ 0x000140CC) */
  __IO uint32_t PKA_FW_OPTIONS;                    /* !< (@ 0x000140D0) FW options register */
  __IO uint32_t Reserved_5[8];                     /* !< (@ 0x000140D4) */
  __IO uint32_t PKA_OPTIONS;                       /* !< (@ 0x000140F4) HW configured options */
  __IO uint32_t PKA_SW_REV;                        /* !< (@ 0x000140F8) FW revision numbers, capabilities */
  __IO uint32_t PKA_REVISION;                      /* !< (@ 0x000140FC) PKA HW revision, EIP code */
  __IO uint32_t Reserved_6[1984];                  /* !< (@ 0x00014100) */
  __IO uint32_t PKA_RAM_DATA_0_;                   /* !< (@ 0x00016000) PKA DATA RAM Location 0 */
  __IO uint32_t PKA_RAM_DATA_1_;                   /* !< (@ 0x00016004) PKA DATA RAM Location 1 */
  __IO uint32_t PKA_RAM_DATA_2_;                   /* !< (@ 0x00016008) PKA DATA RAM Location 2 */
  __IO uint32_t PKA_RAM_DATA_3_;                   /* !< (@ 0x0001600C) PKA DATA RAM Location 3 */
  __IO uint32_t PKA_RAM_DATA_4_;                   /* !< (@ 0x00016010) PKA DATA RAM Location 4 */
  __IO uint32_t PKA_RAM_DATA_5_;                   /* !< (@ 0x00016014) PKA DATA RAM Location 5 */
  __IO uint32_t PKA_RAM_DATA_6_;                   /* !< (@ 0x00016018) PKA DATA RAM Location 6 */
  __IO uint32_t PKA_RAM_DATA_7_;                   /* !< (@ 0x0001601C) PKA DATA RAM Location 7 */
  __IO uint32_t PKA_RAM_DATA_8_;                   /* !< (@ 0x00016020) PKA DATA RAM Location 8 */
  __IO uint32_t PKA_RAM_DATA_9_;                   /* !< (@ 0x00016024) PKA DATA RAM Location 9 */
  __IO uint32_t PKA_RAM_DATA_10_;                  /* !< (@ 0x00016028) PKA DATA RAM Location 10 */
  __IO uint32_t PKA_RAM_DATA_11_;                  /* !< (@ 0x0001602C) PKA DATA RAM Location 11 */
  __IO uint32_t PKA_RAM_DATA_12_;                  /* !< (@ 0x00016030) PKA DATA RAM Location 12 */
  __IO uint32_t PKA_RAM_DATA_13_;                  /* !< (@ 0x00016034) PKA DATA RAM Location 13 */
  __IO uint32_t PKA_RAM_DATA_14_;                  /* !< (@ 0x00016038) PKA DATA RAM Location 14 */
  __IO uint32_t PKA_RAM_DATA_15_;                  /* !< (@ 0x0001603C) PKA DATA RAM Location 15 */
  __IO uint32_t PKA_RAM_DATA_16_;                  /* !< (@ 0x00016040) PKA DATA RAM Location 16 */
  __IO uint32_t PKA_RAM_DATA_17_;                  /* !< (@ 0x00016044) PKA DATA RAM Location 17 */
  __IO uint32_t PKA_RAM_DATA_18_;                  /* !< (@ 0x00016048) PKA DATA RAM Location 18 */
  __IO uint32_t PKA_RAM_DATA_19_;                  /* !< (@ 0x0001604C) PKA DATA RAM Location 19 */
  __IO uint32_t PKA_RAM_DATA_20_;                  /* !< (@ 0x00016050) PKA DATA RAM Location 20 */
  __IO uint32_t PKA_RAM_DATA_21_;                  /* !< (@ 0x00016054) PKA DATA RAM Location 21 */
  __IO uint32_t PKA_RAM_DATA_22_;                  /* !< (@ 0x00016058) PKA DATA RAM Location 22 */
  __IO uint32_t PKA_RAM_DATA_23_;                  /* !< (@ 0x0001605C) PKA DATA RAM Location 23 */
  __IO uint32_t PKA_RAM_DATA_24_;                  /* !< (@ 0x00016060) PKA DATA RAM Location 24 */
  __IO uint32_t PKA_RAM_DATA_25_;                  /* !< (@ 0x00016064) PKA DATA RAM Location 25 */
  __IO uint32_t PKA_RAM_DATA_26_;                  /* !< (@ 0x00016068) PKA DATA RAM Location 26 */
  __IO uint32_t PKA_RAM_DATA_27_;                  /* !< (@ 0x0001606C) PKA DATA RAM Location 27 */
  __IO uint32_t PKA_RAM_DATA_28_;                  /* !< (@ 0x00016070) PKA DATA RAM Location 28 */
  __IO uint32_t PKA_RAM_DATA_29_;                  /* !< (@ 0x00016074) PKA DATA RAM Location 29 */
  __IO uint32_t PKA_RAM_DATA_30_;                  /* !< (@ 0x00016078) PKA DATA RAM Location 30 */
  __IO uint32_t PKA_RAM_DATA_31_;                  /* !< (@ 0x0001607C) PKA DATA RAM Location 31 */
  __IO uint32_t PKA_RAM_DATA_32_;                  /* !< (@ 0x00016080) PKA DATA RAM Location 32 */
  __IO uint32_t PKA_RAM_DATA_33_;                  /* !< (@ 0x00016084) PKA DATA RAM Location 33 */
  __IO uint32_t PKA_RAM_DATA_34_;                  /* !< (@ 0x00016088) PKA DATA RAM Location 34 */
  __IO uint32_t PKA_RAM_DATA_35_;                  /* !< (@ 0x0001608C) PKA DATA RAM Location 35 */
  __IO uint32_t PKA_RAM_DATA_36_;                  /* !< (@ 0x00016090) PKA DATA RAM Location 36 */
  __IO uint32_t PKA_RAM_DATA_37_;                  /* !< (@ 0x00016094) PKA DATA RAM Location 37 */
  __IO uint32_t PKA_RAM_DATA_38_;                  /* !< (@ 0x00016098) PKA DATA RAM Location 38 */
  __IO uint32_t PKA_RAM_DATA_39_;                  /* !< (@ 0x0001609C) PKA DATA RAM Location 39 */
  __IO uint32_t PKA_RAM_DATA_40_;                  /* !< (@ 0x000160A0) PKA DATA RAM Location 40 */
  __IO uint32_t PKA_RAM_DATA_41_;                  /* !< (@ 0x000160A4) PKA DATA RAM Location 41 */
  __IO uint32_t PKA_RAM_DATA_42_;                  /* !< (@ 0x000160A8) PKA DATA RAM Location 42 */
  __IO uint32_t PKA_RAM_DATA_43_;                  /* !< (@ 0x000160AC) PKA DATA RAM Location 43 */
  __IO uint32_t PKA_RAM_DATA_44_;                  /* !< (@ 0x000160B0) PKA DATA RAM Location 44 */
  __IO uint32_t PKA_RAM_DATA_45_;                  /* !< (@ 0x000160B4) PKA DATA RAM Location 45 */
  __IO uint32_t PKA_RAM_DATA_46_;                  /* !< (@ 0x000160B8) PKA DATA RAM Location 46 */
  __IO uint32_t PKA_RAM_DATA_47_;                  /* !< (@ 0x000160BC) PKA DATA RAM Location 47 */
  __IO uint32_t PKA_RAM_DATA_48_;                  /* !< (@ 0x000160C0) PKA DATA RAM Location 48 */
  __IO uint32_t PKA_RAM_DATA_49_;                  /* !< (@ 0x000160C4) PKA DATA RAM Location 49 */
  __IO uint32_t PKA_RAM_DATA_50_;                  /* !< (@ 0x000160C8) PKA DATA RAM Location 50 */
  __IO uint32_t PKA_RAM_DATA_51_;                  /* !< (@ 0x000160CC) PKA DATA RAM Location 51 */
  __IO uint32_t PKA_RAM_DATA_52_;                  /* !< (@ 0x000160D0) PKA DATA RAM Location 52 */
  __IO uint32_t PKA_RAM_DATA_53_;                  /* !< (@ 0x000160D4) PKA DATA RAM Location 53 */
  __IO uint32_t PKA_RAM_DATA_54_;                  /* !< (@ 0x000160D8) PKA DATA RAM Location 54 */
  __IO uint32_t PKA_RAM_DATA_55_;                  /* !< (@ 0x000160DC) PKA DATA RAM Location 55 */
  __IO uint32_t PKA_RAM_DATA_56_;                  /* !< (@ 0x000160E0) PKA DATA RAM Location 56 */
  __IO uint32_t PKA_RAM_DATA_57_;                  /* !< (@ 0x000160E4) PKA DATA RAM Location 57 */
  __IO uint32_t PKA_RAM_DATA_58_;                  /* !< (@ 0x000160E8) PKA DATA RAM Location 58 */
  __IO uint32_t PKA_RAM_DATA_59_;                  /* !< (@ 0x000160EC) PKA DATA RAM Location 59 */
  __IO uint32_t PKA_RAM_DATA_60_;                  /* !< (@ 0x000160F0) PKA DATA RAM Location 60 */
  __IO uint32_t PKA_RAM_DATA_61_;                  /* !< (@ 0x000160F4) PKA DATA RAM Location 61 */
  __IO uint32_t PKA_RAM_DATA_62_;                  /* !< (@ 0x000160F8) PKA DATA RAM Location 62 */
  __IO uint32_t PKA_RAM_DATA_63_;                  /* !< (@ 0x000160FC) PKA DATA RAM Location 63 */
  __IO uint32_t PKA_RAM_DATA_64_;                  /* !< (@ 0x00016100) PKA DATA RAM Location 64 */
  __IO uint32_t PKA_RAM_DATA_65_;                  /* !< (@ 0x00016104) PKA DATA RAM Location 65 */
  __IO uint32_t PKA_RAM_DATA_66_;                  /* !< (@ 0x00016108) PKA DATA RAM Location 66 */
  __IO uint32_t PKA_RAM_DATA_67_;                  /* !< (@ 0x0001610C) PKA DATA RAM Location 67 */
  __IO uint32_t PKA_RAM_DATA_68_;                  /* !< (@ 0x00016110) PKA DATA RAM Location 68 */
  __IO uint32_t PKA_RAM_DATA_69_;                  /* !< (@ 0x00016114) PKA DATA RAM Location 69 */
  __IO uint32_t PKA_RAM_DATA_70_;                  /* !< (@ 0x00016118) PKA DATA RAM Location 70 */
  __IO uint32_t PKA_RAM_DATA_71_;                  /* !< (@ 0x0001611C) PKA DATA RAM Location 71 */
  __IO uint32_t PKA_RAM_DATA_72_;                  /* !< (@ 0x00016120) PKA DATA RAM Location 72 */
  __IO uint32_t PKA_RAM_DATA_73_;                  /* !< (@ 0x00016124) PKA DATA RAM Location 73 */
  __IO uint32_t PKA_RAM_DATA_74_;                  /* !< (@ 0x00016128) PKA DATA RAM Location 74 */
  __IO uint32_t PKA_RAM_DATA_75_;                  /* !< (@ 0x0001612C) PKA DATA RAM Location 75 */
  __IO uint32_t PKA_RAM_DATA_76_;                  /* !< (@ 0x00016130) PKA DATA RAM Location 76 */
  __IO uint32_t PKA_RAM_DATA_77_;                  /* !< (@ 0x00016134) PKA DATA RAM Location 77 */
  __IO uint32_t PKA_RAM_DATA_78_;                  /* !< (@ 0x00016138) PKA DATA RAM Location 78 */
  __IO uint32_t PKA_RAM_DATA_79_;                  /* !< (@ 0x0001613C) PKA DATA RAM Location 79 */
  __IO uint32_t PKA_RAM_DATA_80_;                  /* !< (@ 0x00016140) PKA DATA RAM Location 80 */
  __IO uint32_t PKA_RAM_DATA_81_;                  /* !< (@ 0x00016144) PKA DATA RAM Location 81 */
  __IO uint32_t PKA_RAM_DATA_82_;                  /* !< (@ 0x00016148) PKA DATA RAM Location 82 */
  __IO uint32_t PKA_RAM_DATA_83_;                  /* !< (@ 0x0001614C) PKA DATA RAM Location 83 */
  __IO uint32_t PKA_RAM_DATA_84_;                  /* !< (@ 0x00016150) PKA DATA RAM Location 84 */
  __IO uint32_t PKA_RAM_DATA_85_;                  /* !< (@ 0x00016154) PKA DATA RAM Location 85 */
  __IO uint32_t PKA_RAM_DATA_86_;                  /* !< (@ 0x00016158) PKA DATA RAM Location 86 */
  __IO uint32_t PKA_RAM_DATA_87_;                  /* !< (@ 0x0001615C) PKA DATA RAM Location 87 */
  __IO uint32_t PKA_RAM_DATA_88_;                  /* !< (@ 0x00016160) PKA DATA RAM Location 88 */
  __IO uint32_t PKA_RAM_DATA_89_;                  /* !< (@ 0x00016164) PKA DATA RAM Location 89 */
  __IO uint32_t PKA_RAM_DATA_90_;                  /* !< (@ 0x00016168) PKA DATA RAM Location 90 */
  __IO uint32_t PKA_RAM_DATA_91_;                  /* !< (@ 0x0001616C) PKA DATA RAM Location 91 */
  __IO uint32_t PKA_RAM_DATA_92_;                  /* !< (@ 0x00016170) PKA DATA RAM Location 92 */
  __IO uint32_t PKA_RAM_DATA_93_;                  /* !< (@ 0x00016174) PKA DATA RAM Location 93 */
  __IO uint32_t PKA_RAM_DATA_94_;                  /* !< (@ 0x00016178) PKA DATA RAM Location 94 */
  __IO uint32_t PKA_RAM_DATA_95_;                  /* !< (@ 0x0001617C) PKA DATA RAM Location 95 */
  __IO uint32_t PKA_RAM_DATA_96_;                  /* !< (@ 0x00016180) PKA DATA RAM Location 96 */
  __IO uint32_t PKA_RAM_DATA_97_;                  /* !< (@ 0x00016184) PKA DATA RAM Location 97 */
  __IO uint32_t PKA_RAM_DATA_98_;                  /* !< (@ 0x00016188) PKA DATA RAM Location 98 */
  __IO uint32_t PKA_RAM_DATA_99_;                  /* !< (@ 0x0001618C) PKA DATA RAM Location 99 */
  __IO uint32_t PKA_RAM_DATA_100_;                 /* !< (@ 0x00016190) PKA DATA RAM Location 100 */
  __IO uint32_t PKA_RAM_DATA_101_;                 /* !< (@ 0x00016194) PKA DATA RAM Location 101 */
  __IO uint32_t PKA_RAM_DATA_102_;                 /* !< (@ 0x00016198) PKA DATA RAM Location 102 */
  __IO uint32_t PKA_RAM_DATA_103_;                 /* !< (@ 0x0001619C) PKA DATA RAM Location 103 */
  __IO uint32_t PKA_RAM_DATA_104_;                 /* !< (@ 0x000161A0) PKA DATA RAM Location 104 */
  __IO uint32_t PKA_RAM_DATA_105_;                 /* !< (@ 0x000161A4) PKA DATA RAM Location 105 */
  __IO uint32_t PKA_RAM_DATA_106_;                 /* !< (@ 0x000161A8) PKA DATA RAM Location 106 */
  __IO uint32_t PKA_RAM_DATA_107_;                 /* !< (@ 0x000161AC) PKA DATA RAM Location 107 */
  __IO uint32_t PKA_RAM_DATA_108_;                 /* !< (@ 0x000161B0) PKA DATA RAM Location 108 */
  __IO uint32_t PKA_RAM_DATA_109_;                 /* !< (@ 0x000161B4) PKA DATA RAM Location 109 */
  __IO uint32_t PKA_RAM_DATA_110_;                 /* !< (@ 0x000161B8) PKA DATA RAM Location 110 */
  __IO uint32_t PKA_RAM_DATA_111_;                 /* !< (@ 0x000161BC) PKA DATA RAM Location 111 */
  __IO uint32_t PKA_RAM_DATA_112_;                 /* !< (@ 0x000161C0) PKA DATA RAM Location 112 */
  __IO uint32_t PKA_RAM_DATA_113_;                 /* !< (@ 0x000161C4) PKA DATA RAM Location 113 */
  __IO uint32_t PKA_RAM_DATA_114_;                 /* !< (@ 0x000161C8) PKA DATA RAM Location 114 */
  __IO uint32_t PKA_RAM_DATA_115_;                 /* !< (@ 0x000161CC) PKA DATA RAM Location 115 */
  __IO uint32_t PKA_RAM_DATA_116_;                 /* !< (@ 0x000161D0) PKA DATA RAM Location 116 */
  __IO uint32_t PKA_RAM_DATA_117_;                 /* !< (@ 0x000161D4) PKA DATA RAM Location 117 */
  __IO uint32_t PKA_RAM_DATA_118_;                 /* !< (@ 0x000161D8) PKA DATA RAM Location 118 */
  __IO uint32_t PKA_RAM_DATA_119_;                 /* !< (@ 0x000161DC) PKA DATA RAM Location 119 */
  __IO uint32_t PKA_RAM_DATA_120_;                 /* !< (@ 0x000161E0) PKA DATA RAM Location 120 */
  __IO uint32_t PKA_RAM_DATA_121_;                 /* !< (@ 0x000161E4) PKA DATA RAM Location 121 */
  __IO uint32_t PKA_RAM_DATA_122_;                 /* !< (@ 0x000161E8) PKA DATA RAM Location 122 */
  __IO uint32_t PKA_RAM_DATA_123_;                 /* !< (@ 0x000161EC) PKA DATA RAM Location 123 */
  __IO uint32_t PKA_RAM_DATA_124_;                 /* !< (@ 0x000161F0) PKA DATA RAM Location 124 */
  __IO uint32_t PKA_RAM_DATA_125_;                 /* !< (@ 0x000161F4) PKA DATA RAM Location 125 */
  __IO uint32_t PKA_RAM_DATA_126_;                 /* !< (@ 0x000161F8) PKA DATA RAM Location 126 */
  __IO uint32_t PKA_RAM_DATA_127_;                 /* !< (@ 0x000161FC) PKA DATA RAM Location 127 */
  __IO uint32_t PKA_RAM_DATA_128_;                 /* !< (@ 0x00016200) PKA DATA RAM Location 128 */
  __IO uint32_t PKA_RAM_DATA_129_;                 /* !< (@ 0x00016204) PKA DATA RAM Location 129 */
  __IO uint32_t PKA_RAM_DATA_130_;                 /* !< (@ 0x00016208) PKA DATA RAM Location 130 */
  __IO uint32_t PKA_RAM_DATA_131_;                 /* !< (@ 0x0001620C) PKA DATA RAM Location 131 */
  __IO uint32_t PKA_RAM_DATA_132_;                 /* !< (@ 0x00016210) PKA DATA RAM Location 132 */
  __IO uint32_t PKA_RAM_DATA_133_;                 /* !< (@ 0x00016214) PKA DATA RAM Location 133 */
  __IO uint32_t PKA_RAM_DATA_134_;                 /* !< (@ 0x00016218) PKA DATA RAM Location 134 */
  __IO uint32_t PKA_RAM_DATA_135_;                 /* !< (@ 0x0001621C) PKA DATA RAM Location 135 */
  __IO uint32_t PKA_RAM_DATA_136_;                 /* !< (@ 0x00016220) PKA DATA RAM Location 136 */
  __IO uint32_t PKA_RAM_DATA_137_;                 /* !< (@ 0x00016224) PKA DATA RAM Location 137 */
  __IO uint32_t PKA_RAM_DATA_138_;                 /* !< (@ 0x00016228) PKA DATA RAM Location 138 */
  __IO uint32_t PKA_RAM_DATA_139_;                 /* !< (@ 0x0001622C) PKA DATA RAM Location 139 */
  __IO uint32_t PKA_RAM_DATA_140_;                 /* !< (@ 0x00016230) PKA DATA RAM Location 140 */
  __IO uint32_t PKA_RAM_DATA_141_;                 /* !< (@ 0x00016234) PKA DATA RAM Location 141 */
  __IO uint32_t PKA_RAM_DATA_142_;                 /* !< (@ 0x00016238) PKA DATA RAM Location 142 */
  __IO uint32_t PKA_RAM_DATA_143_;                 /* !< (@ 0x0001623C) PKA DATA RAM Location 143 */
  __IO uint32_t PKA_RAM_DATA_144_;                 /* !< (@ 0x00016240) PKA DATA RAM Location 144 */
  __IO uint32_t PKA_RAM_DATA_145_;                 /* !< (@ 0x00016244) PKA DATA RAM Location 145 */
  __IO uint32_t PKA_RAM_DATA_146_;                 /* !< (@ 0x00016248) PKA DATA RAM Location 146 */
  __IO uint32_t PKA_RAM_DATA_147_;                 /* !< (@ 0x0001624C) PKA DATA RAM Location 147 */
  __IO uint32_t PKA_RAM_DATA_148_;                 /* !< (@ 0x00016250) PKA DATA RAM Location 148 */
  __IO uint32_t PKA_RAM_DATA_149_;                 /* !< (@ 0x00016254) PKA DATA RAM Location 149 */
  __IO uint32_t PKA_RAM_DATA_150_;                 /* !< (@ 0x00016258) PKA DATA RAM Location 150 */
  __IO uint32_t PKA_RAM_DATA_151_;                 /* !< (@ 0x0001625C) PKA DATA RAM Location 151 */
  __IO uint32_t PKA_RAM_DATA_152_;                 /* !< (@ 0x00016260) PKA DATA RAM Location 152 */
  __IO uint32_t PKA_RAM_DATA_153_;                 /* !< (@ 0x00016264) PKA DATA RAM Location 153 */
  __IO uint32_t PKA_RAM_DATA_154_;                 /* !< (@ 0x00016268) PKA DATA RAM Location 154 */
  __IO uint32_t PKA_RAM_DATA_155_;                 /* !< (@ 0x0001626C) PKA DATA RAM Location 155 */
  __IO uint32_t PKA_RAM_DATA_156_;                 /* !< (@ 0x00016270) PKA DATA RAM Location 156 */
  __IO uint32_t PKA_RAM_DATA_157_;                 /* !< (@ 0x00016274) PKA DATA RAM Location 157 */
  __IO uint32_t PKA_RAM_DATA_158_;                 /* !< (@ 0x00016278) PKA DATA RAM Location 158 */
  __IO uint32_t PKA_RAM_DATA_159_;                 /* !< (@ 0x0001627C) PKA DATA RAM Location 159 */
  __IO uint32_t PKA_RAM_DATA_160_;                 /* !< (@ 0x00016280) PKA DATA RAM Location 160 */
  __IO uint32_t PKA_RAM_DATA_161_;                 /* !< (@ 0x00016284) PKA DATA RAM Location 161 */
  __IO uint32_t PKA_RAM_DATA_162_;                 /* !< (@ 0x00016288) PKA DATA RAM Location 162 */
  __IO uint32_t PKA_RAM_DATA_163_;                 /* !< (@ 0x0001628C) PKA DATA RAM Location 163 */
  __IO uint32_t PKA_RAM_DATA_164_;                 /* !< (@ 0x00016290) PKA DATA RAM Location 164 */
  __IO uint32_t PKA_RAM_DATA_165_;                 /* !< (@ 0x00016294) PKA DATA RAM Location 165 */
  __IO uint32_t PKA_RAM_DATA_166_;                 /* !< (@ 0x00016298) PKA DATA RAM Location 166 */
  __IO uint32_t PKA_RAM_DATA_167_;                 /* !< (@ 0x0001629C) PKA DATA RAM Location 167 */
  __IO uint32_t PKA_RAM_DATA_168_;                 /* !< (@ 0x000162A0) PKA DATA RAM Location 168 */
  __IO uint32_t PKA_RAM_DATA_169_;                 /* !< (@ 0x000162A4) PKA DATA RAM Location 169 */
  __IO uint32_t PKA_RAM_DATA_170_;                 /* !< (@ 0x000162A8) PKA DATA RAM Location 170 */
  __IO uint32_t PKA_RAM_DATA_171_;                 /* !< (@ 0x000162AC) PKA DATA RAM Location 171 */
  __IO uint32_t PKA_RAM_DATA_172_;                 /* !< (@ 0x000162B0) PKA DATA RAM Location 172 */
  __IO uint32_t PKA_RAM_DATA_173_;                 /* !< (@ 0x000162B4) PKA DATA RAM Location 173 */
  __IO uint32_t PKA_RAM_DATA_174_;                 /* !< (@ 0x000162B8) PKA DATA RAM Location 174 */
  __IO uint32_t PKA_RAM_DATA_175_;                 /* !< (@ 0x000162BC) PKA DATA RAM Location 175 */
  __IO uint32_t PKA_RAM_DATA_176_;                 /* !< (@ 0x000162C0) PKA DATA RAM Location 176 */
  __IO uint32_t PKA_RAM_DATA_177_;                 /* !< (@ 0x000162C4) PKA DATA RAM Location 177 */
  __IO uint32_t PKA_RAM_DATA_178_;                 /* !< (@ 0x000162C8) PKA DATA RAM Location 178 */
  __IO uint32_t PKA_RAM_DATA_179_;                 /* !< (@ 0x000162CC) PKA DATA RAM Location 179 */
  __IO uint32_t PKA_RAM_DATA_180_;                 /* !< (@ 0x000162D0) PKA DATA RAM Location 180 */
  __IO uint32_t PKA_RAM_DATA_181_;                 /* !< (@ 0x000162D4) PKA DATA RAM Location 181 */
  __IO uint32_t PKA_RAM_DATA_182_;                 /* !< (@ 0x000162D8) PKA DATA RAM Location 182 */
  __IO uint32_t PKA_RAM_DATA_183_;                 /* !< (@ 0x000162DC) PKA DATA RAM Location 183 */
  __IO uint32_t PKA_RAM_DATA_184_;                 /* !< (@ 0x000162E0) PKA DATA RAM Location 184 */
  __IO uint32_t PKA_RAM_DATA_185_;                 /* !< (@ 0x000162E4) PKA DATA RAM Location 185 */
  __IO uint32_t PKA_RAM_DATA_186_;                 /* !< (@ 0x000162E8) PKA DATA RAM Location 186 */
  __IO uint32_t PKA_RAM_DATA_187_;                 /* !< (@ 0x000162EC) PKA DATA RAM Location 187 */
  __IO uint32_t PKA_RAM_DATA_188_;                 /* !< (@ 0x000162F0) PKA DATA RAM Location 188 */
  __IO uint32_t PKA_RAM_DATA_189_;                 /* !< (@ 0x000162F4) PKA DATA RAM Location 189 */
  __IO uint32_t PKA_RAM_DATA_190_;                 /* !< (@ 0x000162F8) PKA DATA RAM Location 190 */
  __IO uint32_t PKA_RAM_DATA_191_;                 /* !< (@ 0x000162FC) PKA DATA RAM Location 191 */
  __IO uint32_t PKA_RAM_DATA_192_;                 /* !< (@ 0x00016300) PKA DATA RAM Location 192 */
  __IO uint32_t PKA_RAM_DATA_193_;                 /* !< (@ 0x00016304) PKA DATA RAM Location 193 */
  __IO uint32_t PKA_RAM_DATA_194_;                 /* !< (@ 0x00016308) PKA DATA RAM Location 194 */
  __IO uint32_t PKA_RAM_DATA_195_;                 /* !< (@ 0x0001630C) PKA DATA RAM Location 195 */
  __IO uint32_t PKA_RAM_DATA_196_;                 /* !< (@ 0x00016310) PKA DATA RAM Location 196 */
  __IO uint32_t PKA_RAM_DATA_197_;                 /* !< (@ 0x00016314) PKA DATA RAM Location 197 */
  __IO uint32_t PKA_RAM_DATA_198_;                 /* !< (@ 0x00016318) PKA DATA RAM Location 198 */
  __IO uint32_t PKA_RAM_DATA_199_;                 /* !< (@ 0x0001631C) PKA DATA RAM Location 199 */
  __IO uint32_t PKA_RAM_DATA_200_;                 /* !< (@ 0x00016320) PKA DATA RAM Location 200 */
  __IO uint32_t PKA_RAM_DATA_201_;                 /* !< (@ 0x00016324) PKA DATA RAM Location 201 */
  __IO uint32_t PKA_RAM_DATA_202_;                 /* !< (@ 0x00016328) PKA DATA RAM Location 202 */
  __IO uint32_t PKA_RAM_DATA_203_;                 /* !< (@ 0x0001632C) PKA DATA RAM Location 203 */
  __IO uint32_t PKA_RAM_DATA_204_;                 /* !< (@ 0x00016330) PKA DATA RAM Location 204 */
  __IO uint32_t PKA_RAM_DATA_205_;                 /* !< (@ 0x00016334) PKA DATA RAM Location 205 */
  __IO uint32_t PKA_RAM_DATA_206_;                 /* !< (@ 0x00016338) PKA DATA RAM Location 206 */
  __IO uint32_t PKA_RAM_DATA_207_;                 /* !< (@ 0x0001633C) PKA DATA RAM Location 207 */
  __IO uint32_t PKA_RAM_DATA_208_;                 /* !< (@ 0x00016340) PKA DATA RAM Location 208 */
  __IO uint32_t PKA_RAM_DATA_209_;                 /* !< (@ 0x00016344) PKA DATA RAM Location 209 */
  __IO uint32_t PKA_RAM_DATA_210_;                 /* !< (@ 0x00016348) PKA DATA RAM Location 210 */
  __IO uint32_t PKA_RAM_DATA_211_;                 /* !< (@ 0x0001634C) PKA DATA RAM Location 211 */
  __IO uint32_t PKA_RAM_DATA_212_;                 /* !< (@ 0x00016350) PKA DATA RAM Location 212 */
  __IO uint32_t PKA_RAM_DATA_213_;                 /* !< (@ 0x00016354) PKA DATA RAM Location 213 */
  __IO uint32_t PKA_RAM_DATA_214_;                 /* !< (@ 0x00016358) PKA DATA RAM Location 214 */
  __IO uint32_t PKA_RAM_DATA_215_;                 /* !< (@ 0x0001635C) PKA DATA RAM Location 215 */
  __IO uint32_t PKA_RAM_DATA_216_;                 /* !< (@ 0x00016360) PKA DATA RAM Location 216 */
  __IO uint32_t PKA_RAM_DATA_217_;                 /* !< (@ 0x00016364) PKA DATA RAM Location 217 */
  __IO uint32_t PKA_RAM_DATA_218_;                 /* !< (@ 0x00016368) PKA DATA RAM Location 218 */
  __IO uint32_t PKA_RAM_DATA_219_;                 /* !< (@ 0x0001636C) PKA DATA RAM Location 219 */
  __IO uint32_t PKA_RAM_DATA_220_;                 /* !< (@ 0x00016370) PKA DATA RAM Location 220 */
  __IO uint32_t PKA_RAM_DATA_221_;                 /* !< (@ 0x00016374) PKA DATA RAM Location 221 */
  __IO uint32_t PKA_RAM_DATA_222_;                 /* !< (@ 0x00016378) PKA DATA RAM Location 222 */
  __IO uint32_t PKA_RAM_DATA_223_;                 /* !< (@ 0x0001637C) PKA DATA RAM Location 223 */
  __IO uint32_t PKA_RAM_DATA_224_;                 /* !< (@ 0x00016380) PKA DATA RAM Location 224 */
  __IO uint32_t PKA_RAM_DATA_225_;                 /* !< (@ 0x00016384) PKA DATA RAM Location 225 */
  __IO uint32_t PKA_RAM_DATA_226_;                 /* !< (@ 0x00016388) PKA DATA RAM Location 226 */
  __IO uint32_t PKA_RAM_DATA_227_;                 /* !< (@ 0x0001638C) PKA DATA RAM Location 227 */
  __IO uint32_t PKA_RAM_DATA_228_;                 /* !< (@ 0x00016390) PKA DATA RAM Location 228 */
  __IO uint32_t PKA_RAM_DATA_229_;                 /* !< (@ 0x00016394) PKA DATA RAM Location 229 */
  __IO uint32_t PKA_RAM_DATA_230_;                 /* !< (@ 0x00016398) PKA DATA RAM Location 230 */
  __IO uint32_t PKA_RAM_DATA_231_;                 /* !< (@ 0x0001639C) PKA DATA RAM Location 231 */
  __IO uint32_t PKA_RAM_DATA_232_;                 /* !< (@ 0x000163A0) PKA DATA RAM Location 232 */
  __IO uint32_t PKA_RAM_DATA_233_;                 /* !< (@ 0x000163A4) PKA DATA RAM Location 233 */
  __IO uint32_t PKA_RAM_DATA_234_;                 /* !< (@ 0x000163A8) PKA DATA RAM Location 234 */
  __IO uint32_t PKA_RAM_DATA_235_;                 /* !< (@ 0x000163AC) PKA DATA RAM Location 235 */
  __IO uint32_t PKA_RAM_DATA_236_;                 /* !< (@ 0x000163B0) PKA DATA RAM Location 236 */
  __IO uint32_t PKA_RAM_DATA_237_;                 /* !< (@ 0x000163B4) PKA DATA RAM Location 237 */
  __IO uint32_t PKA_RAM_DATA_238_;                 /* !< (@ 0x000163B8) PKA DATA RAM Location 238 */
  __IO uint32_t PKA_RAM_DATA_239_;                 /* !< (@ 0x000163BC) PKA DATA RAM Location 239 */
  __IO uint32_t PKA_RAM_DATA_240_;                 /* !< (@ 0x000163C0) PKA DATA RAM Location 240 */
  __IO uint32_t PKA_RAM_DATA_241_;                 /* !< (@ 0x000163C4) PKA DATA RAM Location 241 */
  __IO uint32_t PKA_RAM_DATA_242_;                 /* !< (@ 0x000163C8) PKA DATA RAM Location 242 */
  __IO uint32_t PKA_RAM_DATA_243_;                 /* !< (@ 0x000163CC) PKA DATA RAM Location 243 */
  __IO uint32_t PKA_RAM_DATA_244_;                 /* !< (@ 0x000163D0) PKA DATA RAM Location 244 */
  __IO uint32_t PKA_RAM_DATA_245_;                 /* !< (@ 0x000163D4) PKA DATA RAM Location 245 */
  __IO uint32_t PKA_RAM_DATA_246_;                 /* !< (@ 0x000163D8) PKA DATA RAM Location 246 */
  __IO uint32_t PKA_RAM_DATA_247_;                 /* !< (@ 0x000163DC) PKA DATA RAM Location 247 */
  __IO uint32_t PKA_RAM_DATA_248_;                 /* !< (@ 0x000163E0) PKA DATA RAM Location 248 */
  __IO uint32_t PKA_RAM_DATA_249_;                 /* !< (@ 0x000163E4) PKA DATA RAM Location 249 */
  __IO uint32_t PKA_RAM_DATA_250_;                 /* !< (@ 0x000163E8) PKA DATA RAM Location 250 */
  __IO uint32_t PKA_RAM_DATA_251_;                 /* !< (@ 0x000163EC) PKA DATA RAM Location 251 */
  __IO uint32_t PKA_RAM_DATA_252_;                 /* !< (@ 0x000163F0) PKA DATA RAM Location 252 */
  __IO uint32_t PKA_RAM_DATA_253_;                 /* !< (@ 0x000163F4) PKA DATA RAM Location 253 */
  __IO uint32_t PKA_RAM_DATA_254_;                 /* !< (@ 0x000163F8) PKA DATA RAM Location 254 */
  __IO uint32_t PKA_RAM_DATA_255_;                 /* !< (@ 0x000163FC) PKA DATA RAM Location 255 */
  __IO uint32_t PKA_RAM_DATA_256_;                 /* !< (@ 0x00016400) PKA DATA RAM Location 256 */
  __IO uint32_t PKA_RAM_DATA_257_;                 /* !< (@ 0x00016404) PKA DATA RAM Location 257 */
  __IO uint32_t PKA_RAM_DATA_258_;                 /* !< (@ 0x00016408) PKA DATA RAM Location 258 */
  __IO uint32_t PKA_RAM_DATA_259_;                 /* !< (@ 0x0001640C) PKA DATA RAM Location 259 */
  __IO uint32_t PKA_RAM_DATA_260_;                 /* !< (@ 0x00016410) PKA DATA RAM Location 260 */
  __IO uint32_t PKA_RAM_DATA_261_;                 /* !< (@ 0x00016414) PKA DATA RAM Location 261 */
  __IO uint32_t PKA_RAM_DATA_262_;                 /* !< (@ 0x00016418) PKA DATA RAM Location 262 */
  __IO uint32_t PKA_RAM_DATA_263_;                 /* !< (@ 0x0001641C) PKA DATA RAM Location 263 */
  __IO uint32_t PKA_RAM_DATA_264_;                 /* !< (@ 0x00016420) PKA DATA RAM Location 264 */
  __IO uint32_t PKA_RAM_DATA_265_;                 /* !< (@ 0x00016424) PKA DATA RAM Location 265 */
  __IO uint32_t PKA_RAM_DATA_266_;                 /* !< (@ 0x00016428) PKA DATA RAM Location 266 */
  __IO uint32_t PKA_RAM_DATA_267_;                 /* !< (@ 0x0001642C) PKA DATA RAM Location 267 */
  __IO uint32_t PKA_RAM_DATA_268_;                 /* !< (@ 0x00016430) PKA DATA RAM Location 268 */
  __IO uint32_t PKA_RAM_DATA_269_;                 /* !< (@ 0x00016434) PKA DATA RAM Location 269 */
  __IO uint32_t PKA_RAM_DATA_270_;                 /* !< (@ 0x00016438) PKA DATA RAM Location 270 */
  __IO uint32_t PKA_RAM_DATA_271_;                 /* !< (@ 0x0001643C) PKA DATA RAM Location 271 */
  __IO uint32_t PKA_RAM_DATA_272_;                 /* !< (@ 0x00016440) PKA DATA RAM Location 272 */
  __IO uint32_t PKA_RAM_DATA_273_;                 /* !< (@ 0x00016444) PKA DATA RAM Location 273 */
  __IO uint32_t PKA_RAM_DATA_274_;                 /* !< (@ 0x00016448) PKA DATA RAM Location 274 */
  __IO uint32_t PKA_RAM_DATA_275_;                 /* !< (@ 0x0001644C) PKA DATA RAM Location 275 */
  __IO uint32_t PKA_RAM_DATA_276_;                 /* !< (@ 0x00016450) PKA DATA RAM Location 276 */
  __IO uint32_t PKA_RAM_DATA_277_;                 /* !< (@ 0x00016454) PKA DATA RAM Location 277 */
  __IO uint32_t PKA_RAM_DATA_278_;                 /* !< (@ 0x00016458) PKA DATA RAM Location 278 */
  __IO uint32_t PKA_RAM_DATA_279_;                 /* !< (@ 0x0001645C) PKA DATA RAM Location 279 */
  __IO uint32_t PKA_RAM_DATA_280_;                 /* !< (@ 0x00016460) PKA DATA RAM Location 280 */
  __IO uint32_t PKA_RAM_DATA_281_;                 /* !< (@ 0x00016464) PKA DATA RAM Location 281 */
  __IO uint32_t PKA_RAM_DATA_282_;                 /* !< (@ 0x00016468) PKA DATA RAM Location 282 */
  __IO uint32_t PKA_RAM_DATA_283_;                 /* !< (@ 0x0001646C) PKA DATA RAM Location 283 */
  __IO uint32_t PKA_RAM_DATA_284_;                 /* !< (@ 0x00016470) PKA DATA RAM Location 284 */
  __IO uint32_t PKA_RAM_DATA_285_;                 /* !< (@ 0x00016474) PKA DATA RAM Location 285 */
  __IO uint32_t PKA_RAM_DATA_286_;                 /* !< (@ 0x00016478) PKA DATA RAM Location 286 */
  __IO uint32_t PKA_RAM_DATA_287_;                 /* !< (@ 0x0001647C) PKA DATA RAM Location 287 */
  __IO uint32_t PKA_RAM_DATA_288_;                 /* !< (@ 0x00016480) PKA DATA RAM Location 288 */
  __IO uint32_t PKA_RAM_DATA_289_;                 /* !< (@ 0x00016484) PKA DATA RAM Location 289 */
  __IO uint32_t PKA_RAM_DATA_290_;                 /* !< (@ 0x00016488) PKA DATA RAM Location 290 */
  __IO uint32_t PKA_RAM_DATA_291_;                 /* !< (@ 0x0001648C) PKA DATA RAM Location 291 */
  __IO uint32_t PKA_RAM_DATA_292_;                 /* !< (@ 0x00016490) PKA DATA RAM Location 292 */
  __IO uint32_t PKA_RAM_DATA_293_;                 /* !< (@ 0x00016494) PKA DATA RAM Location 293 */
  __IO uint32_t PKA_RAM_DATA_294_;                 /* !< (@ 0x00016498) PKA DATA RAM Location 294 */
  __IO uint32_t PKA_RAM_DATA_295_;                 /* !< (@ 0x0001649C) PKA DATA RAM Location 295 */
  __IO uint32_t PKA_RAM_DATA_296_;                 /* !< (@ 0x000164A0) PKA DATA RAM Location 296 */
  __IO uint32_t PKA_RAM_DATA_297_;                 /* !< (@ 0x000164A4) PKA DATA RAM Location 297 */
  __IO uint32_t PKA_RAM_DATA_298_;                 /* !< (@ 0x000164A8) PKA DATA RAM Location 298 */
  __IO uint32_t PKA_RAM_DATA_299_;                 /* !< (@ 0x000164AC) PKA DATA RAM Location 299 */
  __IO uint32_t PKA_RAM_DATA_300_;                 /* !< (@ 0x000164B0) PKA DATA RAM Location 300 */
  __IO uint32_t PKA_RAM_DATA_301_;                 /* !< (@ 0x000164B4) PKA DATA RAM Location 301 */
  __IO uint32_t PKA_RAM_DATA_302_;                 /* !< (@ 0x000164B8) PKA DATA RAM Location 302 */
  __IO uint32_t PKA_RAM_DATA_303_;                 /* !< (@ 0x000164BC) PKA DATA RAM Location 303 */
  __IO uint32_t PKA_RAM_DATA_304_;                 /* !< (@ 0x000164C0) PKA DATA RAM Location 304 */
  __IO uint32_t PKA_RAM_DATA_305_;                 /* !< (@ 0x000164C4) PKA DATA RAM Location 305 */
  __IO uint32_t PKA_RAM_DATA_306_;                 /* !< (@ 0x000164C8) PKA DATA RAM Location 306 */
  __IO uint32_t PKA_RAM_DATA_307_;                 /* !< (@ 0x000164CC) PKA DATA RAM Location 307 */
  __IO uint32_t PKA_RAM_DATA_308_;                 /* !< (@ 0x000164D0) PKA DATA RAM Location 308 */
  __IO uint32_t PKA_RAM_DATA_309_;                 /* !< (@ 0x000164D4) PKA DATA RAM Location 309 */
  __IO uint32_t PKA_RAM_DATA_310_;                 /* !< (@ 0x000164D8) PKA DATA RAM Location 310 */
  __IO uint32_t PKA_RAM_DATA_311_;                 /* !< (@ 0x000164DC) PKA DATA RAM Location 311 */
  __IO uint32_t PKA_RAM_DATA_312_;                 /* !< (@ 0x000164E0) PKA DATA RAM Location 312 */
  __IO uint32_t PKA_RAM_DATA_313_;                 /* !< (@ 0x000164E4) PKA DATA RAM Location 313 */
  __IO uint32_t PKA_RAM_DATA_314_;                 /* !< (@ 0x000164E8) PKA DATA RAM Location 314 */
  __IO uint32_t PKA_RAM_DATA_315_;                 /* !< (@ 0x000164EC) PKA DATA RAM Location 315 */
  __IO uint32_t PKA_RAM_DATA_316_;                 /* !< (@ 0x000164F0) PKA DATA RAM Location 316 */
  __IO uint32_t PKA_RAM_DATA_317_;                 /* !< (@ 0x000164F4) PKA DATA RAM Location 317 */
  __IO uint32_t PKA_RAM_DATA_318_;                 /* !< (@ 0x000164F8) PKA DATA RAM Location 318 */
  __IO uint32_t PKA_RAM_DATA_319_;                 /* !< (@ 0x000164FC) PKA DATA RAM Location 319 */
  __IO uint32_t PKA_RAM_DATA_320_;                 /* !< (@ 0x00016500) PKA DATA RAM Location 320 */
  __IO uint32_t PKA_RAM_DATA_321_;                 /* !< (@ 0x00016504) PKA DATA RAM Location 321 */
  __IO uint32_t PKA_RAM_DATA_322_;                 /* !< (@ 0x00016508) PKA DATA RAM Location 322 */
  __IO uint32_t PKA_RAM_DATA_323_;                 /* !< (@ 0x0001650C) PKA DATA RAM Location 323 */
  __IO uint32_t PKA_RAM_DATA_324_;                 /* !< (@ 0x00016510) PKA DATA RAM Location 324 */
  __IO uint32_t PKA_RAM_DATA_325_;                 /* !< (@ 0x00016514) PKA DATA RAM Location 325 */
  __IO uint32_t PKA_RAM_DATA_326_;                 /* !< (@ 0x00016518) PKA DATA RAM Location 326 */
  __IO uint32_t PKA_RAM_DATA_327_;                 /* !< (@ 0x0001651C) PKA DATA RAM Location 327 */
  __IO uint32_t PKA_RAM_DATA_328_;                 /* !< (@ 0x00016520) PKA DATA RAM Location 328 */
  __IO uint32_t PKA_RAM_DATA_329_;                 /* !< (@ 0x00016524) PKA DATA RAM Location 329 */
  __IO uint32_t PKA_RAM_DATA_330_;                 /* !< (@ 0x00016528) PKA DATA RAM Location 330 */
  __IO uint32_t PKA_RAM_DATA_331_;                 /* !< (@ 0x0001652C) PKA DATA RAM Location 331 */
  __IO uint32_t PKA_RAM_DATA_332_;                 /* !< (@ 0x00016530) PKA DATA RAM Location 332 */
  __IO uint32_t PKA_RAM_DATA_333_;                 /* !< (@ 0x00016534) PKA DATA RAM Location 333 */
  __IO uint32_t PKA_RAM_DATA_334_;                 /* !< (@ 0x00016538) PKA DATA RAM Location 334 */
  __IO uint32_t PKA_RAM_DATA_335_;                 /* !< (@ 0x0001653C) PKA DATA RAM Location 335 */
  __IO uint32_t PKA_RAM_DATA_336_;                 /* !< (@ 0x00016540) PKA DATA RAM Location 336 */
  __IO uint32_t PKA_RAM_DATA_337_;                 /* !< (@ 0x00016544) PKA DATA RAM Location 337 */
  __IO uint32_t PKA_RAM_DATA_338_;                 /* !< (@ 0x00016548) PKA DATA RAM Location 338 */
  __IO uint32_t PKA_RAM_DATA_339_;                 /* !< (@ 0x0001654C) PKA DATA RAM Location 339 */
  __IO uint32_t PKA_RAM_DATA_340_;                 /* !< (@ 0x00016550) PKA DATA RAM Location 340 */
  __IO uint32_t PKA_RAM_DATA_341_;                 /* !< (@ 0x00016554) PKA DATA RAM Location 341 */
  __IO uint32_t PKA_RAM_DATA_342_;                 /* !< (@ 0x00016558) PKA DATA RAM Location 342 */
  __IO uint32_t PKA_RAM_DATA_343_;                 /* !< (@ 0x0001655C) PKA DATA RAM Location 343 */
  __IO uint32_t PKA_RAM_DATA_344_;                 /* !< (@ 0x00016560) PKA DATA RAM Location 344 */
  __IO uint32_t PKA_RAM_DATA_345_;                 /* !< (@ 0x00016564) PKA DATA RAM Location 345 */
  __IO uint32_t PKA_RAM_DATA_346_;                 /* !< (@ 0x00016568) PKA DATA RAM Location 346 */
  __IO uint32_t PKA_RAM_DATA_347_;                 /* !< (@ 0x0001656C) PKA DATA RAM Location 347 */
  __IO uint32_t PKA_RAM_DATA_348_;                 /* !< (@ 0x00016570) PKA DATA RAM Location 348 */
  __IO uint32_t PKA_RAM_DATA_349_;                 /* !< (@ 0x00016574) PKA DATA RAM Location 349 */
  __IO uint32_t PKA_RAM_DATA_350_;                 /* !< (@ 0x00016578) PKA DATA RAM Location 350 */
  __IO uint32_t PKA_RAM_DATA_351_;                 /* !< (@ 0x0001657C) PKA DATA RAM Location 351 */
  __IO uint32_t PKA_RAM_DATA_352_;                 /* !< (@ 0x00016580) PKA DATA RAM Location 352 */
  __IO uint32_t PKA_RAM_DATA_353_;                 /* !< (@ 0x00016584) PKA DATA RAM Location 353 */
  __IO uint32_t PKA_RAM_DATA_354_;                 /* !< (@ 0x00016588) PKA DATA RAM Location 354 */
  __IO uint32_t PKA_RAM_DATA_355_;                 /* !< (@ 0x0001658C) PKA DATA RAM Location 355 */
  __IO uint32_t PKA_RAM_DATA_356_;                 /* !< (@ 0x00016590) PKA DATA RAM Location 356 */
  __IO uint32_t PKA_RAM_DATA_357_;                 /* !< (@ 0x00016594) PKA DATA RAM Location 357 */
  __IO uint32_t PKA_RAM_DATA_358_;                 /* !< (@ 0x00016598) PKA DATA RAM Location 358 */
  __IO uint32_t PKA_RAM_DATA_359_;                 /* !< (@ 0x0001659C) PKA DATA RAM Location 359 */
  __IO uint32_t PKA_RAM_DATA_360_;                 /* !< (@ 0x000165A0) PKA DATA RAM Location 360 */
  __IO uint32_t PKA_RAM_DATA_361_;                 /* !< (@ 0x000165A4) PKA DATA RAM Location 361 */
  __IO uint32_t PKA_RAM_DATA_362_;                 /* !< (@ 0x000165A8) PKA DATA RAM Location 362 */
  __IO uint32_t PKA_RAM_DATA_363_;                 /* !< (@ 0x000165AC) PKA DATA RAM Location 363 */
  __IO uint32_t PKA_RAM_DATA_364_;                 /* !< (@ 0x000165B0) PKA DATA RAM Location 364 */
  __IO uint32_t PKA_RAM_DATA_365_;                 /* !< (@ 0x000165B4) PKA DATA RAM Location 365 */
  __IO uint32_t PKA_RAM_DATA_366_;                 /* !< (@ 0x000165B8) PKA DATA RAM Location 366 */
  __IO uint32_t PKA_RAM_DATA_367_;                 /* !< (@ 0x000165BC) PKA DATA RAM Location 367 */
  __IO uint32_t PKA_RAM_DATA_368_;                 /* !< (@ 0x000165C0) PKA DATA RAM Location 368 */
  __IO uint32_t PKA_RAM_DATA_369_;                 /* !< (@ 0x000165C4) PKA DATA RAM Location 369 */
  __IO uint32_t PKA_RAM_DATA_370_;                 /* !< (@ 0x000165C8) PKA DATA RAM Location 370 */
  __IO uint32_t PKA_RAM_DATA_371_;                 /* !< (@ 0x000165CC) PKA DATA RAM Location 371 */
  __IO uint32_t PKA_RAM_DATA_372_;                 /* !< (@ 0x000165D0) PKA DATA RAM Location 372 */
  __IO uint32_t PKA_RAM_DATA_373_;                 /* !< (@ 0x000165D4) PKA DATA RAM Location 373 */
  __IO uint32_t PKA_RAM_DATA_374_;                 /* !< (@ 0x000165D8) PKA DATA RAM Location 374 */
  __IO uint32_t PKA_RAM_DATA_375_;                 /* !< (@ 0x000165DC) PKA DATA RAM Location 375 */
  __IO uint32_t PKA_RAM_DATA_376_;                 /* !< (@ 0x000165E0) PKA DATA RAM Location 376 */
  __IO uint32_t PKA_RAM_DATA_377_;                 /* !< (@ 0x000165E4) PKA DATA RAM Location 377 */
  __IO uint32_t PKA_RAM_DATA_378_;                 /* !< (@ 0x000165E8) PKA DATA RAM Location 378 */
  __IO uint32_t PKA_RAM_DATA_379_;                 /* !< (@ 0x000165EC) PKA DATA RAM Location 379 */
  __IO uint32_t PKA_RAM_DATA_380_;                 /* !< (@ 0x000165F0) PKA DATA RAM Location 380 */
  __IO uint32_t PKA_RAM_DATA_381_;                 /* !< (@ 0x000165F4) PKA DATA RAM Location 381 */
  __IO uint32_t PKA_RAM_DATA_382_;                 /* !< (@ 0x000165F8) PKA DATA RAM Location 382 */
  __IO uint32_t PKA_RAM_DATA_383_;                 /* !< (@ 0x000165FC) PKA DATA RAM Location 383 */
  __IO uint32_t PKA_RAM_DATA_384_;                 /* !< (@ 0x00016600) PKA DATA RAM Location 384 */
  __IO uint32_t PKA_RAM_DATA_385_;                 /* !< (@ 0x00016604) PKA DATA RAM Location 385 */
  __IO uint32_t PKA_RAM_DATA_386_;                 /* !< (@ 0x00016608) PKA DATA RAM Location 386 */
  __IO uint32_t PKA_RAM_DATA_387_;                 /* !< (@ 0x0001660C) PKA DATA RAM Location 387 */
  __IO uint32_t PKA_RAM_DATA_388_;                 /* !< (@ 0x00016610) PKA DATA RAM Location 388 */
  __IO uint32_t PKA_RAM_DATA_389_;                 /* !< (@ 0x00016614) PKA DATA RAM Location 389 */
  __IO uint32_t PKA_RAM_DATA_390_;                 /* !< (@ 0x00016618) PKA DATA RAM Location 390 */
  __IO uint32_t PKA_RAM_DATA_391_;                 /* !< (@ 0x0001661C) PKA DATA RAM Location 391 */
  __IO uint32_t PKA_RAM_DATA_392_;                 /* !< (@ 0x00016620) PKA DATA RAM Location 392 */
  __IO uint32_t PKA_RAM_DATA_393_;                 /* !< (@ 0x00016624) PKA DATA RAM Location 393 */
  __IO uint32_t PKA_RAM_DATA_394_;                 /* !< (@ 0x00016628) PKA DATA RAM Location 394 */
  __IO uint32_t PKA_RAM_DATA_395_;                 /* !< (@ 0x0001662C) PKA DATA RAM Location 395 */
  __IO uint32_t PKA_RAM_DATA_396_;                 /* !< (@ 0x00016630) PKA DATA RAM Location 396 */
  __IO uint32_t PKA_RAM_DATA_397_;                 /* !< (@ 0x00016634) PKA DATA RAM Location 397 */
  __IO uint32_t PKA_RAM_DATA_398_;                 /* !< (@ 0x00016638) PKA DATA RAM Location 398 */
  __IO uint32_t PKA_RAM_DATA_399_;                 /* !< (@ 0x0001663C) PKA DATA RAM Location 399 */
  __IO uint32_t PKA_RAM_DATA_400_;                 /* !< (@ 0x00016640) PKA DATA RAM Location 400 */
  __IO uint32_t PKA_RAM_DATA_401_;                 /* !< (@ 0x00016644) PKA DATA RAM Location 401 */
  __IO uint32_t PKA_RAM_DATA_402_;                 /* !< (@ 0x00016648) PKA DATA RAM Location 402 */
  __IO uint32_t PKA_RAM_DATA_403_;                 /* !< (@ 0x0001664C) PKA DATA RAM Location 403 */
  __IO uint32_t PKA_RAM_DATA_404_;                 /* !< (@ 0x00016650) PKA DATA RAM Location 404 */
  __IO uint32_t PKA_RAM_DATA_405_;                 /* !< (@ 0x00016654) PKA DATA RAM Location 405 */
  __IO uint32_t PKA_RAM_DATA_406_;                 /* !< (@ 0x00016658) PKA DATA RAM Location 406 */
  __IO uint32_t PKA_RAM_DATA_407_;                 /* !< (@ 0x0001665C) PKA DATA RAM Location 407 */
  __IO uint32_t PKA_RAM_DATA_408_;                 /* !< (@ 0x00016660) PKA DATA RAM Location 408 */
  __IO uint32_t PKA_RAM_DATA_409_;                 /* !< (@ 0x00016664) PKA DATA RAM Location 409 */
  __IO uint32_t PKA_RAM_DATA_410_;                 /* !< (@ 0x00016668) PKA DATA RAM Location 410 */
  __IO uint32_t PKA_RAM_DATA_411_;                 /* !< (@ 0x0001666C) PKA DATA RAM Location 411 */
  __IO uint32_t PKA_RAM_DATA_412_;                 /* !< (@ 0x00016670) PKA DATA RAM Location 412 */
  __IO uint32_t PKA_RAM_DATA_413_;                 /* !< (@ 0x00016674) PKA DATA RAM Location 413 */
  __IO uint32_t PKA_RAM_DATA_414_;                 /* !< (@ 0x00016678) PKA DATA RAM Location 414 */
  __IO uint32_t PKA_RAM_DATA_415_;                 /* !< (@ 0x0001667C) PKA DATA RAM Location 415 */
  __IO uint32_t PKA_RAM_DATA_416_;                 /* !< (@ 0x00016680) PKA DATA RAM Location 416 */
  __IO uint32_t PKA_RAM_DATA_417_;                 /* !< (@ 0x00016684) PKA DATA RAM Location 417 */
  __IO uint32_t PKA_RAM_DATA_418_;                 /* !< (@ 0x00016688) PKA DATA RAM Location 418 */
  __IO uint32_t PKA_RAM_DATA_419_;                 /* !< (@ 0x0001668C) PKA DATA RAM Location 419 */
  __IO uint32_t PKA_RAM_DATA_420_;                 /* !< (@ 0x00016690) PKA DATA RAM Location 420 */
  __IO uint32_t PKA_RAM_DATA_421_;                 /* !< (@ 0x00016694) PKA DATA RAM Location 421 */
  __IO uint32_t PKA_RAM_DATA_422_;                 /* !< (@ 0x00016698) PKA DATA RAM Location 422 */
  __IO uint32_t PKA_RAM_DATA_423_;                 /* !< (@ 0x0001669C) PKA DATA RAM Location 423 */
  __IO uint32_t PKA_RAM_DATA_424_;                 /* !< (@ 0x000166A0) PKA DATA RAM Location 424 */
  __IO uint32_t PKA_RAM_DATA_425_;                 /* !< (@ 0x000166A4) PKA DATA RAM Location 425 */
  __IO uint32_t PKA_RAM_DATA_426_;                 /* !< (@ 0x000166A8) PKA DATA RAM Location 426 */
  __IO uint32_t PKA_RAM_DATA_427_;                 /* !< (@ 0x000166AC) PKA DATA RAM Location 427 */
  __IO uint32_t PKA_RAM_DATA_428_;                 /* !< (@ 0x000166B0) PKA DATA RAM Location 428 */
  __IO uint32_t PKA_RAM_DATA_429_;                 /* !< (@ 0x000166B4) PKA DATA RAM Location 429 */
  __IO uint32_t PKA_RAM_DATA_430_;                 /* !< (@ 0x000166B8) PKA DATA RAM Location 430 */
  __IO uint32_t PKA_RAM_DATA_431_;                 /* !< (@ 0x000166BC) PKA DATA RAM Location 431 */
  __IO uint32_t PKA_RAM_DATA_432_;                 /* !< (@ 0x000166C0) PKA DATA RAM Location 432 */
  __IO uint32_t PKA_RAM_DATA_433_;                 /* !< (@ 0x000166C4) PKA DATA RAM Location 433 */
  __IO uint32_t PKA_RAM_DATA_434_;                 /* !< (@ 0x000166C8) PKA DATA RAM Location 434 */
  __IO uint32_t PKA_RAM_DATA_435_;                 /* !< (@ 0x000166CC) PKA DATA RAM Location 435 */
  __IO uint32_t PKA_RAM_DATA_436_;                 /* !< (@ 0x000166D0) PKA DATA RAM Location 436 */
  __IO uint32_t PKA_RAM_DATA_437_;                 /* !< (@ 0x000166D4) PKA DATA RAM Location 437 */
  __IO uint32_t PKA_RAM_DATA_438_;                 /* !< (@ 0x000166D8) PKA DATA RAM Location 438 */
  __IO uint32_t PKA_RAM_DATA_439_;                 /* !< (@ 0x000166DC) PKA DATA RAM Location 439 */
  __IO uint32_t PKA_RAM_DATA_440_;                 /* !< (@ 0x000166E0) PKA DATA RAM Location 440 */
  __IO uint32_t PKA_RAM_DATA_441_;                 /* !< (@ 0x000166E4) PKA DATA RAM Location 441 */
  __IO uint32_t PKA_RAM_DATA_442_;                 /* !< (@ 0x000166E8) PKA DATA RAM Location 442 */
  __IO uint32_t PKA_RAM_DATA_443_;                 /* !< (@ 0x000166EC) PKA DATA RAM Location 443 */
  __IO uint32_t PKA_RAM_DATA_444_;                 /* !< (@ 0x000166F0) PKA DATA RAM Location 444 */
  __IO uint32_t PKA_RAM_DATA_445_;                 /* !< (@ 0x000166F4) PKA DATA RAM Location 445 */
  __IO uint32_t PKA_RAM_DATA_446_;                 /* !< (@ 0x000166F8) PKA DATA RAM Location 446 */
  __IO uint32_t PKA_RAM_DATA_447_;                 /* !< (@ 0x000166FC) PKA DATA RAM Location 447 */
  __IO uint32_t PKA_RAM_DATA_448_;                 /* !< (@ 0x00016700) PKA DATA RAM Location 448 */
  __IO uint32_t PKA_RAM_DATA_449_;                 /* !< (@ 0x00016704) PKA DATA RAM Location 449 */
  __IO uint32_t PKA_RAM_DATA_450_;                 /* !< (@ 0x00016708) PKA DATA RAM Location 450 */
  __IO uint32_t PKA_RAM_DATA_451_;                 /* !< (@ 0x0001670C) PKA DATA RAM Location 451 */
  __IO uint32_t PKA_RAM_DATA_452_;                 /* !< (@ 0x00016710) PKA DATA RAM Location 452 */
  __IO uint32_t PKA_RAM_DATA_453_;                 /* !< (@ 0x00016714) PKA DATA RAM Location 453 */
  __IO uint32_t PKA_RAM_DATA_454_;                 /* !< (@ 0x00016718) PKA DATA RAM Location 454 */
  __IO uint32_t PKA_RAM_DATA_455_;                 /* !< (@ 0x0001671C) PKA DATA RAM Location 455 */
  __IO uint32_t PKA_RAM_DATA_456_;                 /* !< (@ 0x00016720) PKA DATA RAM Location 456 */
  __IO uint32_t PKA_RAM_DATA_457_;                 /* !< (@ 0x00016724) PKA DATA RAM Location 457 */
  __IO uint32_t PKA_RAM_DATA_458_;                 /* !< (@ 0x00016728) PKA DATA RAM Location 458 */
  __IO uint32_t PKA_RAM_DATA_459_;                 /* !< (@ 0x0001672C) PKA DATA RAM Location 459 */
  __IO uint32_t PKA_RAM_DATA_460_;                 /* !< (@ 0x00016730) PKA DATA RAM Location 460 */
  __IO uint32_t PKA_RAM_DATA_461_;                 /* !< (@ 0x00016734) PKA DATA RAM Location 461 */
  __IO uint32_t PKA_RAM_DATA_462_;                 /* !< (@ 0x00016738) PKA DATA RAM Location 462 */
  __IO uint32_t PKA_RAM_DATA_463_;                 /* !< (@ 0x0001673C) PKA DATA RAM Location 463 */
  __IO uint32_t PKA_RAM_DATA_464_;                 /* !< (@ 0x00016740) PKA DATA RAM Location 464 */
  __IO uint32_t PKA_RAM_DATA_465_;                 /* !< (@ 0x00016744) PKA DATA RAM Location 465 */
  __IO uint32_t PKA_RAM_DATA_466_;                 /* !< (@ 0x00016748) PKA DATA RAM Location 466 */
  __IO uint32_t PKA_RAM_DATA_467_;                 /* !< (@ 0x0001674C) PKA DATA RAM Location 467 */
  __IO uint32_t PKA_RAM_DATA_468_;                 /* !< (@ 0x00016750) PKA DATA RAM Location 468 */
  __IO uint32_t PKA_RAM_DATA_469_;                 /* !< (@ 0x00016754) PKA DATA RAM Location 469 */
  __IO uint32_t PKA_RAM_DATA_470_;                 /* !< (@ 0x00016758) PKA DATA RAM Location 470 */
  __IO uint32_t PKA_RAM_DATA_471_;                 /* !< (@ 0x0001675C) PKA DATA RAM Location 471 */
  __IO uint32_t PKA_RAM_DATA_472_;                 /* !< (@ 0x00016760) PKA DATA RAM Location 472 */
  __IO uint32_t PKA_RAM_DATA_473_;                 /* !< (@ 0x00016764) PKA DATA RAM Location 473 */
  __IO uint32_t PKA_RAM_DATA_474_;                 /* !< (@ 0x00016768) PKA DATA RAM Location 474 */
  __IO uint32_t PKA_RAM_DATA_475_;                 /* !< (@ 0x0001676C) PKA DATA RAM Location 475 */
  __IO uint32_t PKA_RAM_DATA_476_;                 /* !< (@ 0x00016770) PKA DATA RAM Location 476 */
  __IO uint32_t PKA_RAM_DATA_477_;                 /* !< (@ 0x00016774) PKA DATA RAM Location 477 */
  __IO uint32_t PKA_RAM_DATA_478_;                 /* !< (@ 0x00016778) PKA DATA RAM Location 478 */
  __IO uint32_t PKA_RAM_DATA_479_;                 /* !< (@ 0x0001677C) PKA DATA RAM Location 479 */
  __IO uint32_t PKA_RAM_DATA_480_;                 /* !< (@ 0x00016780) PKA DATA RAM Location 480 */
  __IO uint32_t PKA_RAM_DATA_481_;                 /* !< (@ 0x00016784) PKA DATA RAM Location 481 */
  __IO uint32_t PKA_RAM_DATA_482_;                 /* !< (@ 0x00016788) PKA DATA RAM Location 482 */
  __IO uint32_t PKA_RAM_DATA_483_;                 /* !< (@ 0x0001678C) PKA DATA RAM Location 483 */
  __IO uint32_t PKA_RAM_DATA_484_;                 /* !< (@ 0x00016790) PKA DATA RAM Location 484 */
  __IO uint32_t PKA_RAM_DATA_485_;                 /* !< (@ 0x00016794) PKA DATA RAM Location 485 */
  __IO uint32_t PKA_RAM_DATA_486_;                 /* !< (@ 0x00016798) PKA DATA RAM Location 486 */
  __IO uint32_t PKA_RAM_DATA_487_;                 /* !< (@ 0x0001679C) PKA DATA RAM Location 487 */
  __IO uint32_t PKA_RAM_DATA_488_;                 /* !< (@ 0x000167A0) PKA DATA RAM Location 488 */
  __IO uint32_t PKA_RAM_DATA_489_;                 /* !< (@ 0x000167A4) PKA DATA RAM Location 489 */
  __IO uint32_t PKA_RAM_DATA_490_;                 /* !< (@ 0x000167A8) PKA DATA RAM Location 490 */
  __IO uint32_t PKA_RAM_DATA_491_;                 /* !< (@ 0x000167AC) PKA DATA RAM Location 491 */
  __IO uint32_t PKA_RAM_DATA_492_;                 /* !< (@ 0x000167B0) PKA DATA RAM Location 492 */
  __IO uint32_t PKA_RAM_DATA_493_;                 /* !< (@ 0x000167B4) PKA DATA RAM Location 493 */
  __IO uint32_t PKA_RAM_DATA_494_;                 /* !< (@ 0x000167B8) PKA DATA RAM Location 494 */
  __IO uint32_t PKA_RAM_DATA_495_;                 /* !< (@ 0x000167BC) PKA DATA RAM Location 495 */
  __IO uint32_t PKA_RAM_DATA_496_;                 /* !< (@ 0x000167C0) PKA DATA RAM Location 496 */
  __IO uint32_t PKA_RAM_DATA_497_;                 /* !< (@ 0x000167C4) PKA DATA RAM Location 497 */
  __IO uint32_t PKA_RAM_DATA_498_;                 /* !< (@ 0x000167C8) PKA DATA RAM Location 498 */
  __IO uint32_t PKA_RAM_DATA_499_;                 /* !< (@ 0x000167CC) PKA DATA RAM Location 499 */
  __IO uint32_t PKA_RAM_DATA_500_;                 /* !< (@ 0x000167D0) PKA DATA RAM Location 500 */
  __IO uint32_t PKA_RAM_DATA_501_;                 /* !< (@ 0x000167D4) PKA DATA RAM Location 501 */
  __IO uint32_t PKA_RAM_DATA_502_;                 /* !< (@ 0x000167D8) PKA DATA RAM Location 502 */
  __IO uint32_t PKA_RAM_DATA_503_;                 /* !< (@ 0x000167DC) PKA DATA RAM Location 503 */
  __IO uint32_t PKA_RAM_DATA_504_;                 /* !< (@ 0x000167E0) PKA DATA RAM Location 504 */
  __IO uint32_t PKA_RAM_DATA_505_;                 /* !< (@ 0x000167E4) PKA DATA RAM Location 505 */
  __IO uint32_t PKA_RAM_DATA_506_;                 /* !< (@ 0x000167E8) PKA DATA RAM Location 506 */
  __IO uint32_t PKA_RAM_DATA_507_;                 /* !< (@ 0x000167EC) PKA DATA RAM Location 507 */
  __IO uint32_t PKA_RAM_DATA_508_;                 /* !< (@ 0x000167F0) PKA DATA RAM Location 508 */
  __IO uint32_t PKA_RAM_DATA_509_;                 /* !< (@ 0x000167F4) PKA DATA RAM Location 509 */
  __IO uint32_t PKA_RAM_DATA_510_;                 /* !< (@ 0x000167F8) PKA DATA RAM Location 510 */
  __IO uint32_t PKA_RAM_DATA_511_;                 /* !< (@ 0x000167FC) PKA DATA RAM Location 511 */
  __IO uint32_t Reserved_7[1536];                  /* !< (@ 0x00016800) */
  __IO uint32_t AIC_POL_CTRL;                      /* !< (@ 0x00018000) Input Polarity Control Register */
  __IO uint32_t AIC_TYPE_CTRL;                     /* !< (@ 0x00018004) Input Type Control Register */
  __IO uint32_t AIC_ENABLE_CTRL;                   /* !< (@ 0x00018008) Interrupt Enable Control Register */
  __IO uint32_t AIC_RAW_STAT;                      /* !< (@ 0x0001800C) Raw Interrupt Pending Status Register */
       uint32_t RESERVED1;
  __IO uint32_t AIC_ENABLE_SET;                    /* !< (@ 0x0001800C) Interrupt Enable Register */
  __IO uint32_t AIC_ENABLED_STAT;                  /* !< (@ 0x00018010) Masked Interrupt Pending Status Register */
       uint32_t RESERVED2;
  __IO uint32_t AIC_ACK;                           /* !< (@ 0x00018010) Interrupt Acknowledge Register */
  __IO uint32_t AIC_ENABLE_CLR;                    /* !< (@ 0x00018014) Interrupt Disable Register */
  __IO uint32_t AIC_OPTIONS;                       /* !< (@ 0x00018018) AIC Configuration Register */
  __IO uint32_t AIC_VERSION;                       /* !< (@ 0x0001801C) AIC HW revision, EIP code */
  __IO uint32_t Reserved_8[4086];                  /* !< (@ 0x00018020) */
  __IO uint32_t EIP150_OPTIONS;                    /* !< (@ 0x0001BFF8) PKP Configuration Register */
  __IO uint32_t EIP150_REVISION;                   /* !< (@ 0x0001BFFC) PKP HW revision, EIP code */
  __IO uint32_t Reserved_9[4096];                  /* !< (@ 0x0001C000) */
} PKA_PKA_REGS_Regs;

/*@}*/ /* end of group PKA_PKA_REGS */

/** @addtogroup PKA
  @{
*/

typedef struct {
    uint32_t RESERVED0[512];                     /* Reserved space to reach GPRCM at 0x800 */
    PKA_GPRCM_Regs  GPRCM;                       /* !< (@ 0x00000800) */
    uint32_t RESERVED1[19962];                   /* Reserved space to reach PKA_REGS at 0x14000 */
    PKA_PKA_REGS_Regs  PKA_REGS;                /* !< (@ 0x00014000) */
} PKA_Regs;

/*@}*/ /* end of group PKA */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* PKA Register Control Bits
******************************************************************************/

/* PKA_PWREN Bits */
/* PKA_PWREN[ENABLE] Bits */
#define PKA_PWREN_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define PKA_PWREN_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< Enable the power */
#define PKA_PWREN_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable Power */
#define PKA_PWREN_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable Power */
/* PKA_PWREN[KEY] Bits */
#define PKA_PWREN_KEY_OFS                        (24)                            /* !< KEY Offset */
#define PKA_PWREN_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define PKA_PWREN_KEY_UNLOCK_W                   ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* PKA_RSTCTL Bits */
/* PKA_RSTCTL[RESETSTKYCLR] Bits */
#define PKA_RSTCTL_RESETSTKYCLR_OFS              (1)                             /* !< RESETSTKYCLR Offset */
#define PKA_RSTCTL_RESETSTKYCLR_MASK             ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define PKA_RSTCTL_RESETSTKYCLR_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define PKA_RSTCTL_RESETSTKYCLR_CLR              ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* PKA_RSTCTL[RESETASSERT] Bits */
#define PKA_RSTCTL_RESETASSERT_OFS               (0)                             /* !< RESETASSERT Offset */
#define PKA_RSTCTL_RESETASSERT_MASK              ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define PKA_RSTCTL_RESETASSERT_NOP               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define PKA_RSTCTL_RESETASSERT_ASSERT            ((uint32_t)0x00000001U)         /* !< Assert reset */
/* PKA_RSTCTL[KEY] Bits */
#define PKA_RSTCTL_KEY_OFS                       (24)                            /* !< KEY Offset */
#define PKA_RSTCTL_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define PKA_RSTCTL_KEY_UNLOCK_W                  ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* PKA_STAT Bits */
/* PKA_STAT[RESETSTKY] Bits */
#define PKA_STAT_RESETSTKY_OFS                   (16)                            /* !< RESETSTKY Offset */
#define PKA_STAT_RESETSTKY_MASK                  ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define PKA_STAT_RESETSTKY_NORES                 ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define PKA_STAT_RESETSTKY_RESET                 ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* PKA_PKA_APTR Bits */
/* PKA_PKA_APTR[PKA_APTR] Bits */
#define PKA_PKA_APTR_PKA_APTR_OFS                (0)                             /* !< PKA_APTR Offset */
#define PKA_PKA_APTR_PKA_APTR_MASK               ((uint32_t)0x000007FFU)         /* !< offset of vector A in words, from
                                                                                    start of PKA Data RAM */

/* PKA_PKA_BPTR Bits */
/* PKA_PKA_BPTR[PKA_BPTR] Bits */
#define PKA_PKA_BPTR_PKA_BPTR_OFS                (0)                             /* !< PKA_BPTR Offset */
#define PKA_PKA_BPTR_PKA_BPTR_MASK               ((uint32_t)0x000007FFU)         /* !< offset of vector B in words, from
                                                                                    start of PKA Data RAM */

/* PKA_PKA_CPTR Bits */
/* PKA_PKA_CPTR[PKA_CPTR] Bits */
#define PKA_PKA_CPTR_PKA_CPTR_OFS                (0)                             /* !< PKA_CPTR Offset */
#define PKA_PKA_CPTR_PKA_CPTR_MASK               ((uint32_t)0x000007FFU)         /* !< offset of vector C in words, from
                                                                                    start of PKA Data RAM */

/* PKA_PKA_DPTR Bits */
/* PKA_PKA_DPTR[PKA_DPTR] Bits */
#define PKA_PKA_DPTR_PKA_DPTR_OFS                (0)                             /* !< PKA_DPTR Offset */
#define PKA_PKA_DPTR_PKA_DPTR_MASK               ((uint32_t)0x000007FFU)         /* !< offset of vector D in words, from
                                                                                    start of PKA Data RAM */

/* PKA_PKA_ALENGTH Bits */
/* PKA_PKA_ALENGTH[PKA_ALENGTH] Bits */
#define PKA_PKA_ALENGTH_PKA_ALENGTH_OFS          (0)                             /* !< PKA_ALENGTH Offset */
#define PKA_PKA_ALENGTH_PKA_ALENGTH_MASK         ((uint32_t)0x000003FFU)         /* !< Length of Vector A in words */

/* PKA_PKA_BLENGTH Bits */
/* PKA_PKA_BLENGTH[PKA_BLENGTH] Bits */
#define PKA_PKA_BLENGTH_PKA_BLENGTH_OFS          (0)                             /* !< PKA_BLENGTH Offset */
#define PKA_PKA_BLENGTH_PKA_BLENGTH_MASK         ((uint32_t)0x000003FFU)         /* !< Length of vector B in words */

/* PKA_PKA_SHIFT Bits */
/* PKA_PKA_SHIFT[PKA_SHIFT] Bits */
#define PKA_PKA_SHIFT_PKA_SHIFT_OFS              (0)                             /* !< PKA_SHIFT Offset */
#define PKA_PKA_SHIFT_PKA_SHIFT_MASK             ((uint32_t)0x0000001FU)         /* !< This register specifies the number
                                                                                    of bits to shift the input vector in
                                                                                    the range 0 to 31 during a Rshift or
                                                                                    Lshift operation */

/* PKA_PKA_FUNCTION Bits */
/* PKA_PKA_FUNCTION[MULTIPLY] Bits */
#define PKA_PKA_FUNCTION_MULTIPLY_OFS            (0)                             /* !< MULTIPLY Offset */
#define PKA_PKA_FUNCTION_MULTIPLY_MASK           ((uint32_t)0x00000001U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[ADDSUB] Bits */
#define PKA_PKA_FUNCTION_ADDSUB_OFS              (1)                             /* !< ADDSUB Offset */
#define PKA_PKA_FUNCTION_ADDSUB_MASK             ((uint32_t)0x00000002U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[MSONEBIT] Bits */
#define PKA_PKA_FUNCTION_MSONEBIT_OFS            (3)                             /* !< MSONEBIT Offset */
#define PKA_PKA_FUNCTION_MSONEBIT_MASK           ((uint32_t)0x00000008U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[ADD] Bits */
#define PKA_PKA_FUNCTION_ADD_OFS                 (4)                             /* !< ADD Offset */
#define PKA_PKA_FUNCTION_ADD_MASK                ((uint32_t)0x00000010U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[SUBTRACT] Bits */
#define PKA_PKA_FUNCTION_SUBTRACT_OFS            (5)                             /* !< SUBTRACT Offset */
#define PKA_PKA_FUNCTION_SUBTRACT_MASK           ((uint32_t)0x00000020U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[RSHIFT] Bits */
#define PKA_PKA_FUNCTION_RSHIFT_OFS              (6)                             /* !< RSHIFT Offset */
#define PKA_PKA_FUNCTION_RSHIFT_MASK             ((uint32_t)0x00000040U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[LSHIFT] Bits */
#define PKA_PKA_FUNCTION_LSHIFT_OFS              (7)                             /* !< LSHIFT Offset */
#define PKA_PKA_FUNCTION_LSHIFT_MASK             ((uint32_t)0x00000080U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[DIVIDE] Bits */
#define PKA_PKA_FUNCTION_DIVIDE_OFS              (8)                             /* !< DIVIDE Offset */
#define PKA_PKA_FUNCTION_DIVIDE_MASK             ((uint32_t)0x00000100U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[MODULO] Bits */
#define PKA_PKA_FUNCTION_MODULO_OFS              (9)                             /* !< MODULO Offset */
#define PKA_PKA_FUNCTION_MODULO_MASK             ((uint32_t)0x00000200U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[COMPARE] Bits */
#define PKA_PKA_FUNCTION_COMPARE_OFS             (10)                            /* !< COMPARE Offset */
#define PKA_PKA_FUNCTION_COMPARE_MASK            ((uint32_t)0x00000400U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[COPY] Bits */
#define PKA_PKA_FUNCTION_COPY_OFS                (11)                            /* !< COPY Offset */
#define PKA_PKA_FUNCTION_COPY_MASK               ((uint32_t)0x00000800U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[SEQOP] Bits */
#define PKA_PKA_FUNCTION_SEQOP_OFS               (12)                            /* !< SEQOP Offset */
#define PKA_PKA_FUNCTION_SEQOP_MASK              ((uint32_t)0x00007000U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[RUNFUNC] Bits */
#define PKA_PKA_FUNCTION_RUNFUNC_OFS             (15)                            /* !< RUNFUNC Offset */
#define PKA_PKA_FUNCTION_RUNFUNC_MASK            ((uint32_t)0x00008000U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[SEQOPEXT] Bits */
#define PKA_PKA_FUNCTION_SEQOPEXT_OFS            (16)                            /* !< SEQOPEXT Offset */
#define PKA_PKA_FUNCTION_SEQOPEXT_MASK           ((uint32_t)0x00070000U)         /* !< Operation, basic or complex, busy
                                                                                    indication */
/* PKA_PKA_FUNCTION[STALLRESULT] Bits */
#define PKA_PKA_FUNCTION_STALLRESULT_OFS         (24)                            /* !< STALLRESULT Offset */
#define PKA_PKA_FUNCTION_STALLRESULT_MASK        ((uint32_t)0x01000000U)         /* !< Operation, basic or complex, busy
                                                                                    indication */

/* PKA_PKA_COMPARE Bits */
/* PKA_PKA_COMPARE[AEQB] Bits */
#define PKA_PKA_COMPARE_AEQB_OFS                 (0)                             /* !< AEQB Offset */
#define PKA_PKA_COMPARE_AEQB_MASK                ((uint32_t)0x00000001U)         /* !< Vector A = Vector B */
/* PKA_PKA_COMPARE[ALTB] Bits */
#define PKA_PKA_COMPARE_ALTB_OFS                 (1)                             /* !< ALTB Offset */
#define PKA_PKA_COMPARE_ALTB_MASK                ((uint32_t)0x00000002U)         /* !< Vector A < Vector B */
/* PKA_PKA_COMPARE[AGTB] Bits */
#define PKA_PKA_COMPARE_AGTB_OFS                 (2)                             /* !< AGTB Offset */
#define PKA_PKA_COMPARE_AGTB_MASK                ((uint32_t)0x00000004U)         /* !< Vector A > Vector B */

/* PKA_PKA_MSW Bits */
/* PKA_PKA_MSW[ADDRESS] Bits */
#define PKA_PKA_MSW_ADDRESS_OFS                  (0)                             /* !< ADDRESS Offset */
#define PKA_PKA_MSW_ADDRESS_MASK                 ((uint32_t)0x000007FFU)         /* !< Address of the most significant non
                                                                                    zero 32 bit word of the result vector
                                                                                    in PKA Data RAM */
/* PKA_PKA_MSW[ZERO_RESULT_VECTOR] Bits */
#define PKA_PKA_MSW_ZERO_RESULT_VECTOR_OFS       (15)                            /* !< ZERO_RESULT_VECTOR Offset */
#define PKA_PKA_MSW_ZERO_RESULT_VECTOR_MASK      ((uint32_t)0x00008000U)         /* !< The result vector is all zeroes,
                                                                                    ignore the address returned in bits
                                                                                    10 to 0 */

/* PKA_PKA_DIVMSW Bits */
/* PKA_PKA_DIVMSW[MSW_ADDRESS] Bits */
#define PKA_PKA_DIVMSW_MSW_ADDRESS_OFS           (0)                             /* !< MSW_ADDRESS Offset */
#define PKA_PKA_DIVMSW_MSW_ADDRESS_MASK          ((uint32_t)0x000007FFU)         /* !< Address of the most significant
                                                                                    nonzero 32 bit word of the Remainder
                                                                                    result vector in PKA Data RAM */
/* PKA_PKA_DIVMSW[ZERO_REMAINDER_VECTOR] Bits */
#define PKA_PKA_DIVMSW_ZERO_REMAINDER_VECTOR_OFS (15)                            /* !< ZERO_REMAINDER_VECTOR Offset */
#define PKA_PKA_DIVMSW_ZERO_REMAINDER_VECTOR_MASK ((uint32_t)0x00008000U)         /* !< The remainder result vector is all
                                                                                    zeroes, ignore the address returned
                                                                                    in bits 10 to 0 */

/* PKA_PKA_ISTA_CTRL Bits */
/* PKA_PKA_ISTA_CTRL[DUMMY_CORR] Bits */
#define PKA_PKA_ISTA_CTRL_DUMMY_CORR_OFS         (0)                             /* !< DUMMY_CORR Offset */
#define PKA_PKA_ISTA_CTRL_DUMMY_CORR_MASK        ((uint32_t)0x00000001U)         /* !< 1b = enable dummy correction cycles
                                                                                    in the basic PKCP DIV and MOD
                                                                                    operations. These dummy cycles remove
                                                                                    the variability of these operations
                                                                                    at the cost of a running time that
                                                                                    can be up to around 70 percent
                                                                                    longer */
/* PKA_PKA_ISTA_CTRL[FORCE_ERROR] Bits */
#define PKA_PKA_ISTA_CTRL_FORCE_ERROR_OFS        (1)                             /* !< FORCE_ERROR Offset */
#define PKA_PKA_ISTA_CTRL_FORCE_ERROR_MASK       ((uint32_t)0x00000002U)         /* !< 1b = force FSM errors,  eg jump to
                                                                                    an illegal state, when starting basic
                                                                                    PKCP operations, these should
                                                                                    activate the fsm_error bit in this
                                                                                    register */
/* PKA_PKA_ISTA_CTRL[PARAM_ERROR] Bits */
#define PKA_PKA_ISTA_CTRL_PARAM_ERROR_OFS        (30)                            /* !< PARAM_ERROR Offset */
#define PKA_PKA_ISTA_CTRL_PARAM_ERROR_MASK       ((uint32_t)0x40000000U)         /* !< This bit is set to 1b when an
                                                                                    illegal operation code selecting more
                                                                                    than 1 operation at a time is written
                                                                                    to the PKA_FUNCTION registe */
/* PKA_PKA_ISTA_CTRL[FSM_ERROR] Bits */
#define PKA_PKA_ISTA_CTRL_FSM_ERROR_OFS          (31)                            /* !< FSM_ERROR Offset */
#define PKA_PKA_ISTA_CTRL_FSM_ERROR_MASK         ((uint32_t)0x80000000U)         /* !< This bit is set to 1b when one of
                                                                                    the PKCP control FSMs enters an
                                                                                    illegal state */

/* PKA_PKCP_PRIO_CTRL Bits */
/* PKA_PKCP_PRIO_CTRL[PKCP_RAM_PRIO] Bits */
#define PKA_PKCP_PRIO_CTRL_PKCP_RAM_PRIO_OFS     (0)                             /* !< PKCP_RAM_PRIO Offset */
#define PKA_PKCP_PRIO_CTRL_PKCP_RAM_PRIO_MASK    ((uint32_t)0x00000001U)         /* !< 0b = Sequencer has priority for
                                                                                    accessing data RAM. 1b = PKCP has
                                                                                    priority for accessing data RAM. */
/* PKA_PKCP_PRIO_CTRL[RAM_ECC_B0] Bits */
#define PKA_PKCP_PRIO_CTRL_RAM_ECC_B0_OFS        (8)                             /* !< RAM_ECC_B0 Offset */
#define PKA_PKCP_PRIO_CTRL_RAM_ECC_B0_MASK       ((uint32_t)0x00000700U)         /* !< Bit number for bit to flip in Bytes
                                                                                    selected in field ram_ecc_test_0 */
/* PKA_PKCP_PRIO_CTRL[RAM_TEST_DUAL] Bits */
#define PKA_PKCP_PRIO_CTRL_RAM_TEST_DUAL_OFS     (11)                            /* !< RAM_TEST_DUAL Offset */
#define PKA_PKCP_PRIO_CTRL_RAM_TEST_DUAL_MASK    ((uint32_t)0x00000800U)         /* !< Set this bit to 1b to produce dual
                                                                                    errors, prior to setting
                                                                                    ram_ecc_test. When this bit is
                                                                                    enabled the next write to
                                                                                    ram_ecc_test will set internal
                                                                                    registers ram_ecc_test_0 and
                                                                                    ram_ecc_test_1, When set to 0b, only
                                                                                    ram_ecc_test_0 will be set */
/* PKA_PKCP_PRIO_CTRL[RAM_ECC_B1] Bits */
#define PKA_PKCP_PRIO_CTRL_RAM_ECC_B1_OFS        (12)                            /* !< RAM_ECC_B1 Offset */
#define PKA_PKCP_PRIO_CTRL_RAM_ECC_B1_MASK       ((uint32_t)0x00007000U)         /* !< Bit number for bit to flip in Bytes
                                                                                    selected in field ram_ecc_test_1 */
/* PKA_PKCP_PRIO_CTRL[RAM_TEST_ONCE] Bits */
#define PKA_PKCP_PRIO_CTRL_RAM_TEST_ONCE_OFS     (15)                            /* !< RAM_TEST_ONCE Offset */
#define PKA_PKCP_PRIO_CTRL_RAM_TEST_ONCE_MASK    ((uint32_t)0x00008000U)         /* !< Writing 1b inserts errors only
                                                                                    once, on the next write to the PKA
                                                                                    Data RAM, all the ram_ecc_test bits
                                                                                    will be reset to zero to prevent
                                                                                    further error insertions */
/* PKA_PKCP_PRIO_CTRL[RAM_ECC_TEST] Bits */
#define PKA_PKCP_PRIO_CTRL_RAM_ECC_TEST_OFS      (16)                            /* !< RAM_ECC_TEST Offset */
#define PKA_PKCP_PRIO_CTRL_RAM_ECC_TEST_MASK     ((uint32_t)0xFFFF0000U)         /* !< Depending on ram_test_dual,
                                                                                    internal registers ram_ecc_test_0 and
                                                                                    ram_ecc_test_1 will be set, or only
                                                                                    ram_ecc_test_0 */

/* PKA_PKA_SEQ_CTRL Bits */
/* PKA_PKA_SEQ_CTRL[BEGIN_SEQUENCER] Bits */
#define PKA_PKA_SEQ_CTRL_BEGIN_SEQUENCER_OFS     (0)                             /* !< BEGIN_SEQUENCER Offset */
#define PKA_PKA_SEQ_CTRL_BEGIN_SEQUENCER_MASK    ((uint32_t)0x000000FFU)         /* !< These bits can be used by software
                                                                                    to trigger Sequencer operations */
/* PKA_PKA_SEQ_CTRL[SEQUENCER_STATUS] Bits */
#define PKA_PKA_SEQ_CTRL_SEQUENCER_STATUS_OFS    (8)                             /* !< SEQUENCER_STATUS Offset */
#define PKA_PKA_SEQ_CTRL_SEQUENCER_STATUS_MASK   ((uint32_t)0x0000FF00U)         /* !< These read only bits are used by
                                                                                    the Sequencer to communicate status
                                                                                    to the outside world. Bit 8 is also
                                                                                    used as Sequencer interrupt, with the
                                                                                    complement of this bit OR-ed into the
                                                                                    Run bit in PKA_FUNCTION */
/* PKA_PKA_SEQ_CTRL[HAMMING_ERROR] Bits */
#define PKA_PKA_SEQ_CTRL_HAMMING_ERROR_OFS       (16)                            /* !< HAMMING_ERROR Offset */
#define PKA_PKA_SEQ_CTRL_HAMMING_ERROR_MASK      ((uint32_t)0x00010000U)         /* !< A 1b indicates a mismatch was
                                                                                    detected between bits 28:24 of a
                                                                                    Sequencer instruction word and the
                                                                                    Hamming protection code calculated
                                                                                    from bits 23:0 of that same
                                                                                    instruction word. This Hamming code
                                                                                    detects at least 2 bit errors in bits
                                                                                    23:0. The state of this bit is OR-ed
                                                                                    into the protection_int output of the
                                                                                    engine */
/* PKA_PKA_SEQ_CTRL[PARITY_ERROR] Bits */
#define PKA_PKA_SEQ_CTRL_PARITY_ERROR_OFS        (17)                            /* !< PARITY_ERROR Offset */
#define PKA_PKA_SEQ_CTRL_PARITY_ERROR_MASK       ((uint32_t)0x00020000U)         /* !< A 1b indicates parity error was
                                                                                    detected */
/* PKA_PKA_SEQ_CTRL[LOGIC_BUSY] Bits */
#define PKA_PKA_SEQ_CTRL_LOGIC_BUSY_OFS          (18)                            /* !< LOGIC_BUSY Offset */
#define PKA_PKA_SEQ_CTRL_LOGIC_BUSY_MASK         ((uint32_t)0x00040000U)         /* !< When 1b is returned this read only
                                                                                    bit indicates that the zeroization
                                                                                    logic is busy. During zeroization the
                                                                                    PKA cannot be used */
/* PKA_PKA_SEQ_CTRL[RAM_ECC_ERROR] Bits */
#define PKA_PKA_SEQ_CTRL_RAM_ECC_ERROR_OFS       (19)                            /* !< RAM_ECC_ERROR Offset */
#define PKA_PKA_SEQ_CTRL_RAM_ECC_ERROR_MASK      ((uint32_t)0x00080000U)         /* !< Overall uncorrectable RAM SECDED
                                                                                    EDC error status bit,This bit reads
                                                                                    1b when one or more uncorrectable
                                                                                    error(s) occurred on the PKA
                                                                                    #br#Data RAM */
/* PKA_PKA_SEQ_CTRL[SEQ_ECC_ERROR] Bits */
#define PKA_PKA_SEQ_CTRL_SEQ_ECC_ERROR_OFS       (20)                            /* !< SEQ_ECC_ERROR Offset */
#define PKA_PKA_SEQ_CTRL_SEQ_ECC_ERROR_MASK      ((uint32_t)0x00100000U)         /* !< Sequencer uncorrectable RAM SECDED
                                                                                    EDC error. This bit reads 1b when an
                                                                                    uncorrectable error occurred while
                                                                                    the Sequencer reads the PKA Data RAM */
/* PKA_PKA_SEQ_CTRL[SEQUENCER_UNLOCKED] Bits */
#define PKA_PKA_SEQ_CTRL_SEQUENCER_UNLOCKED_OFS  (22)                            /* !< SEQUENCER_UNLOCKED Offset */
#define PKA_PKA_SEQ_CTRL_SEQUENCER_UNLOCKED_MASK ((uint32_t)0x00400000U)         /* !< This bit is set to 1b when the main
                                                                                    Sequencer receives a SW reset during
                                                                                    a complex operation, thereby
                                                                                    unlocking the Sequencer. The bit is
                                                                                    sticky: It can be cleared again by
                                                                                    writing a 1b to this location.
                                                                                    Writing a 0b has no effect */
/* PKA_PKA_SEQ_CTRL[RAM_ECC_CORR] Bits */
#define PKA_PKA_SEQ_CTRL_RAM_ECC_CORR_OFS        (23)                            /* !< RAM_ECC_CORR Offset */
#define PKA_PKA_SEQ_CTRL_RAM_ECC_CORR_MASK       ((uint32_t)0x00800000U)         /* !< Overall correctable RAM SECDED EDC
                                                                                    error detected status bit. */
/* PKA_PKA_SEQ_CTRL[PROGRAM_PAGE] Bits */
#define PKA_PKA_SEQ_CTRL_PROGRAM_PAGE_OFS        (29)                            /* !< PROGRAM_PAGE Offset */
#define PKA_PKA_SEQ_CTRL_PROGRAM_PAGE_MASK       ((uint32_t)0x60000000U)         /* !< This field provides two page select
                                                                                    bits for accessing the Sequencer
                                                                                    program RAM through the Host
                                                                                    interface when that is larger than 2K
                                                                                    words. Value 00b selects page 0, the
                                                                                    lowest page, value 01b selects page
                                                                                    1, etcetera */
/* PKA_PKA_SEQ_CTRL[RESET_FOR_SEQUENCER] Bits */
#define PKA_PKA_SEQ_CTRL_RESET_FOR_SEQUENCER_OFS (31)                            /* !< RESET_FOR_SEQUENCER Offset */
#define PKA_PKA_SEQ_CTRL_RESET_FOR_SEQUENCER_MASK ((uint32_t)0x80000000U)         /* !< reset for sequencer */

/* PKA_PKA_FW_OPTIONS Bits */
/* PKA_PKA_FW_OPTIONS[RSA_SUPPORT] Bits */
#define PKA_PKA_FW_OPTIONS_RSA_SUPPORT_OFS       (0)                             /* !< RSA_SUPPORT Offset */
#define PKA_PKA_FW_OPTIONS_RSA_SUPPORT_MASK      ((uint32_t)0x0000003FU)         /* !< RSA_support */
/* PKA_PKA_FW_OPTIONS[NIST_CURVE_SUPPORT] Bits */
#define PKA_PKA_FW_OPTIONS_NIST_CURVE_SUPPORT_OFS (6)                             /* !< NIST_CURVE_SUPPORT Offset */
#define PKA_PKA_FW_OPTIONS_NIST_CURVE_SUPPORT_MASK ((uint32_t)0x00003FC0U)         /* !< NIST_curve_support */
/* PKA_PKA_FW_OPTIONS[MONT_CURVE_SUPPORT] Bits */
#define PKA_PKA_FW_OPTIONS_MONT_CURVE_SUPPORT_OFS (14)                            /* !< MONT_CURVE_SUPPORT Offset */
#define PKA_PKA_FW_OPTIONS_MONT_CURVE_SUPPORT_MASK ((uint32_t)0x0003C000U)         /* !< MONT_curve_support */
/* PKA_PKA_FW_OPTIONS[DIGITAL_SIGNATURE_SUPPORT] Bits */
#define PKA_PKA_FW_OPTIONS_DIGITAL_SIGNATURE_SUPPORT_OFS (18)                            /* !< DIGITAL_SIGNATURE_SUPPORT Offset */
#define PKA_PKA_FW_OPTIONS_DIGITAL_SIGNATURE_SUPPORT_MASK ((uint32_t)0x0FFC0000U)         /* !< Digital_signature_support */
/* PKA_PKA_FW_OPTIONS[MISCELLANEOUS] Bits */
#define PKA_PKA_FW_OPTIONS_MISCELLANEOUS_OFS     (28)                            /* !< MISCELLANEOUS Offset */
#define PKA_PKA_FW_OPTIONS_MISCELLANEOUS_MASK    ((uint32_t)0xF0000000U)         /* !< Miscellaneous */

/* PKA_PKA_OPTIONS Bits */
/* PKA_PKA_OPTIONS[PKCP_CONFIGURATION] Bits */
#define PKA_PKA_OPTIONS_PKCP_CONFIGURATION_OFS   (0)                             /* !< PKCP_CONFIGURATION Offset */
#define PKA_PKA_OPTIONS_PKCP_CONFIGURATION_MASK  ((uint32_t)0x00000003U)         /* !< PKCP_Configuration */
/* PKA_PKA_OPTIONS[LNME_CONFIGURATION] Bits */
#define PKA_PKA_OPTIONS_LNME_CONFIGURATION_OFS   (2)                             /* !< LNME_CONFIGURATION Offset */
#define PKA_PKA_OPTIONS_LNME_CONFIGURATION_MASK  ((uint32_t)0x0000001CU)         /* !< LNME_configuration */
/* PKA_PKA_OPTIONS[SEQUENCER_CONFIGURATION] Bits */
#define PKA_PKA_OPTIONS_SEQUENCER_CONFIGURATION_OFS (5)                             /* !< SEQUENCER_CONFIGURATION Offset */
#define PKA_PKA_OPTIONS_SEQUENCER_CONFIGURATION_MASK ((uint32_t)0x00000060U)         /* !< Sequencer_Configuration */
/* PKA_PKA_OPTIONS[PROGRAM_RAM] Bits */
#define PKA_PKA_OPTIONS_PROGRAM_RAM_OFS          (7)                             /* !< PROGRAM_RAM Offset */
#define PKA_PKA_OPTIONS_PROGRAM_RAM_MASK         ((uint32_t)0x00000080U)         /* !< Program_RAM */
/* PKA_PKA_OPTIONS[PROTECTION_OPTION] Bits */
#define PKA_PKA_OPTIONS_PROTECTION_OPTION_OFS    (8)                             /* !< PROTECTION_OPTION Offset */
#define PKA_PKA_OPTIONS_PROTECTION_OPTION_MASK   ((uint32_t)0x00000700U)         /* !< Protection_option */
/* PKA_PKA_OPTIONS[INT_MASKING] Bits */
#define PKA_PKA_OPTIONS_INT_MASKING_OFS          (11)                            /* !< INT_MASKING Offset */
#define PKA_PKA_OPTIONS_INT_MASKING_MASK         ((uint32_t)0x00000800U)         /* !< Int_masking */
/* PKA_PKA_OPTIONS[MMM3A] Bits */
#define PKA_PKA_OPTIONS_MMM3A_OFS                (12)                            /* !< MMM3A Offset */
#define PKA_PKA_OPTIONS_MMM3A_MASK               ((uint32_t)0x00001000U)         /* !< MMM3A */
/* PKA_PKA_OPTIONS[ZEROIZATION] Bits */
#define PKA_PKA_OPTIONS_ZEROIZATION_OFS          (13)                            /* !< ZEROIZATION Offset */
#define PKA_PKA_OPTIONS_ZEROIZATION_MASK         ((uint32_t)0x00002000U)         /* !< Zeroization */

/* PKA_PKA_SW_REV Bits */
/* PKA_PKA_SW_REV[BASIC_EIP_NUMBER] Bits */
#define PKA_PKA_SW_REV_BASIC_EIP_NUMBER_OFS      (0)                             /* !< BASIC_EIP_NUMBER Offset */
#define PKA_PKA_SW_REV_BASIC_EIP_NUMBER_MASK     ((uint32_t)0x000000FFU)         /* !< Input Data on which hash is
                                                                                    computed */
/* PKA_PKA_SW_REV[COMPLEMENT_OF_BASIC_EIP_NUMBER] Bits */
#define PKA_PKA_SW_REV_COMPLEMENT_OF_BASIC_EIP_NUMBER_OFS (8)                             /* !< COMPLEMENT_OF_BASIC_EIP_NUMBER
                                                                                    Offset */
#define PKA_PKA_SW_REV_COMPLEMENT_OF_BASIC_EIP_NUMBER_MASK ((uint32_t)0x0000FF00U)         /* !< Write 1 to indicate data is
                                                                                    available */
/* PKA_PKA_SW_REV[FW_PATCH_LEVEL] Bits */
#define PKA_PKA_SW_REV_FW_PATCH_LEVEL_OFS        (16)                            /* !< FW_PATCH_LEVEL Offset */
#define PKA_PKA_SW_REV_FW_PATCH_LEVEL_MASK       ((uint32_t)0x000F0000U)         /* !< Write 1 to indicate length is
                                                                                    available */
/* PKA_PKA_SW_REV[MAJOR_FW_REVISION] Bits */
#define PKA_PKA_SW_REV_MAJOR_FW_REVISION_OFS     (20)                            /* !< MAJOR_FW_REVISION Offset */
#define PKA_PKA_SW_REV_MAJOR_FW_REVISION_MASK    ((uint32_t)0x00F00000U)
/* PKA_PKA_SW_REV[MINOR_FW_REVISION] Bits */
#define PKA_PKA_SW_REV_MINOR_FW_REVISION_OFS     (24)                            /* !< MINOR_FW_REVISION Offset */
#define PKA_PKA_SW_REV_MINOR_FW_REVISION_MASK    ((uint32_t)0x0F000000U)         /* !< Write 1 to indicate mode is
                                                                                    available */
/* PKA_PKA_SW_REV[FIRMWARE_CAPABILITIES] Bits */
#define PKA_PKA_SW_REV_FIRMWARE_CAPABILITIES_OFS (28)                            /* !< FIRMWARE_CAPABILITIES Offset */
#define PKA_PKA_SW_REV_FIRMWARE_CAPABILITIES_MASK ((uint32_t)0xF0000000U)

/* PKA_PKA_REVISION Bits */
/* PKA_PKA_REVISION[BASIC_EIP_NUMBER] Bits */
#define PKA_PKA_REVISION_BASIC_EIP_NUMBER_OFS    (0)                             /* !< BASIC_EIP_NUMBER Offset */
#define PKA_PKA_REVISION_BASIC_EIP_NUMBER_MASK   ((uint32_t)0x000000FFU)         /* !< Basic_EIP_number */
/* PKA_PKA_REVISION[COMPLEMENT_OF_BASIC_EIP_NUMBER] Bits */
#define PKA_PKA_REVISION_COMPLEMENT_OF_BASIC_EIP_NUMBER_OFS (8)                             /* !< COMPLEMENT_OF_BASIC_EIP_NUMBER
                                                                                    Offset */
#define PKA_PKA_REVISION_COMPLEMENT_OF_BASIC_EIP_NUMBER_MASK ((uint32_t)0x0000FF00U)         /* !< Complement_of_Basic_EIP_number */
/* PKA_PKA_REVISION[HW_PATCH_LEVEL] Bits */
#define PKA_PKA_REVISION_HW_PATCH_LEVEL_OFS      (16)                            /* !< HW_PATCH_LEVEL Offset */
#define PKA_PKA_REVISION_HW_PATCH_LEVEL_MASK     ((uint32_t)0x000F0000U)         /* !< HW_patch_level */
/* PKA_PKA_REVISION[MAJOR_HW_REVISION] Bits */
#define PKA_PKA_REVISION_MAJOR_HW_REVISION_OFS   (20)                            /* !< MAJOR_HW_REVISION Offset */
#define PKA_PKA_REVISION_MAJOR_HW_REVISION_MASK  ((uint32_t)0x00F00000U)         /* !< Major_HW_Revision */
/* PKA_PKA_REVISION[MINOR_HW_REVISION] Bits */
#define PKA_PKA_REVISION_MINOR_HW_REVISION_OFS   (24)                            /* !< MINOR_HW_REVISION Offset */
#define PKA_PKA_REVISION_MINOR_HW_REVISION_MASK  ((uint32_t)0x0F000000U)         /* !< Minor_HW_Revision */

/* PKA_PKA_RAM_DATA_0_ Bits */
/* PKA_PKA_RAM_DATA_0_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_0__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_0__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_1_ Bits */
/* PKA_PKA_RAM_DATA_1_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_1__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_1__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_2_ Bits */
/* PKA_PKA_RAM_DATA_2_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_2__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_2__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_3_ Bits */
/* PKA_PKA_RAM_DATA_3_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_3__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_3__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_4_ Bits */
/* PKA_PKA_RAM_DATA_4_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_4__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_4__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_5_ Bits */
/* PKA_PKA_RAM_DATA_5_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_5__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_5__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_6_ Bits */
/* PKA_PKA_RAM_DATA_6_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_6__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_6__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_7_ Bits */
/* PKA_PKA_RAM_DATA_7_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_7__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_7__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_8_ Bits */
/* PKA_PKA_RAM_DATA_8_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_8__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_8__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_9_ Bits */
/* PKA_PKA_RAM_DATA_9_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_9__VECTOR_DATA_OFS      (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_9__VECTOR_DATA_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_10_ Bits */
/* PKA_PKA_RAM_DATA_10_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_10__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_10__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_11_ Bits */
/* PKA_PKA_RAM_DATA_11_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_11__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_11__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_12_ Bits */
/* PKA_PKA_RAM_DATA_12_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_12__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_12__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_13_ Bits */
/* PKA_PKA_RAM_DATA_13_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_13__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_13__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_14_ Bits */
/* PKA_PKA_RAM_DATA_14_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_14__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_14__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_15_ Bits */
/* PKA_PKA_RAM_DATA_15_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_15__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_15__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_16_ Bits */
/* PKA_PKA_RAM_DATA_16_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_16__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_16__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_17_ Bits */
/* PKA_PKA_RAM_DATA_17_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_17__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_17__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_18_ Bits */
/* PKA_PKA_RAM_DATA_18_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_18__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_18__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_19_ Bits */
/* PKA_PKA_RAM_DATA_19_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_19__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_19__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_20_ Bits */
/* PKA_PKA_RAM_DATA_20_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_20__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_20__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_21_ Bits */
/* PKA_PKA_RAM_DATA_21_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_21__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_21__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_22_ Bits */
/* PKA_PKA_RAM_DATA_22_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_22__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_22__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_23_ Bits */
/* PKA_PKA_RAM_DATA_23_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_23__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_23__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_24_ Bits */
/* PKA_PKA_RAM_DATA_24_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_24__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_24__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_25_ Bits */
/* PKA_PKA_RAM_DATA_25_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_25__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_25__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_26_ Bits */
/* PKA_PKA_RAM_DATA_26_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_26__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_26__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_27_ Bits */
/* PKA_PKA_RAM_DATA_27_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_27__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_27__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_28_ Bits */
/* PKA_PKA_RAM_DATA_28_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_28__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_28__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_29_ Bits */
/* PKA_PKA_RAM_DATA_29_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_29__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_29__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_30_ Bits */
/* PKA_PKA_RAM_DATA_30_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_30__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_30__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_31_ Bits */
/* PKA_PKA_RAM_DATA_31_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_31__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_31__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_32_ Bits */
/* PKA_PKA_RAM_DATA_32_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_32__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_32__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_33_ Bits */
/* PKA_PKA_RAM_DATA_33_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_33__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_33__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_34_ Bits */
/* PKA_PKA_RAM_DATA_34_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_34__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_34__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_35_ Bits */
/* PKA_PKA_RAM_DATA_35_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_35__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_35__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_36_ Bits */
/* PKA_PKA_RAM_DATA_36_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_36__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_36__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_37_ Bits */
/* PKA_PKA_RAM_DATA_37_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_37__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_37__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_38_ Bits */
/* PKA_PKA_RAM_DATA_38_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_38__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_38__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_39_ Bits */
/* PKA_PKA_RAM_DATA_39_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_39__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_39__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_40_ Bits */
/* PKA_PKA_RAM_DATA_40_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_40__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_40__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_41_ Bits */
/* PKA_PKA_RAM_DATA_41_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_41__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_41__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_42_ Bits */
/* PKA_PKA_RAM_DATA_42_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_42__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_42__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_43_ Bits */
/* PKA_PKA_RAM_DATA_43_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_43__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_43__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_44_ Bits */
/* PKA_PKA_RAM_DATA_44_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_44__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_44__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_45_ Bits */
/* PKA_PKA_RAM_DATA_45_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_45__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_45__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_46_ Bits */
/* PKA_PKA_RAM_DATA_46_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_46__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_46__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_47_ Bits */
/* PKA_PKA_RAM_DATA_47_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_47__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_47__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_48_ Bits */
/* PKA_PKA_RAM_DATA_48_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_48__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_48__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_49_ Bits */
/* PKA_PKA_RAM_DATA_49_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_49__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_49__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_50_ Bits */
/* PKA_PKA_RAM_DATA_50_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_50__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_50__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_51_ Bits */
/* PKA_PKA_RAM_DATA_51_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_51__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_51__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_52_ Bits */
/* PKA_PKA_RAM_DATA_52_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_52__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_52__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_53_ Bits */
/* PKA_PKA_RAM_DATA_53_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_53__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_53__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_54_ Bits */
/* PKA_PKA_RAM_DATA_54_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_54__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_54__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_55_ Bits */
/* PKA_PKA_RAM_DATA_55_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_55__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_55__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_56_ Bits */
/* PKA_PKA_RAM_DATA_56_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_56__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_56__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_57_ Bits */
/* PKA_PKA_RAM_DATA_57_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_57__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_57__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_58_ Bits */
/* PKA_PKA_RAM_DATA_58_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_58__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_58__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_59_ Bits */
/* PKA_PKA_RAM_DATA_59_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_59__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_59__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_60_ Bits */
/* PKA_PKA_RAM_DATA_60_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_60__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_60__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_61_ Bits */
/* PKA_PKA_RAM_DATA_61_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_61__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_61__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_62_ Bits */
/* PKA_PKA_RAM_DATA_62_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_62__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_62__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_63_ Bits */
/* PKA_PKA_RAM_DATA_63_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_63__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_63__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_64_ Bits */
/* PKA_PKA_RAM_DATA_64_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_64__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_64__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_65_ Bits */
/* PKA_PKA_RAM_DATA_65_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_65__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_65__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_66_ Bits */
/* PKA_PKA_RAM_DATA_66_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_66__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_66__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_67_ Bits */
/* PKA_PKA_RAM_DATA_67_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_67__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_67__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_68_ Bits */
/* PKA_PKA_RAM_DATA_68_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_68__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_68__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_69_ Bits */
/* PKA_PKA_RAM_DATA_69_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_69__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_69__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_70_ Bits */
/* PKA_PKA_RAM_DATA_70_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_70__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_70__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_71_ Bits */
/* PKA_PKA_RAM_DATA_71_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_71__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_71__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_72_ Bits */
/* PKA_PKA_RAM_DATA_72_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_72__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_72__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_73_ Bits */
/* PKA_PKA_RAM_DATA_73_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_73__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_73__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_74_ Bits */
/* PKA_PKA_RAM_DATA_74_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_74__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_74__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_75_ Bits */
/* PKA_PKA_RAM_DATA_75_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_75__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_75__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_76_ Bits */
/* PKA_PKA_RAM_DATA_76_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_76__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_76__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_77_ Bits */
/* PKA_PKA_RAM_DATA_77_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_77__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_77__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_78_ Bits */
/* PKA_PKA_RAM_DATA_78_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_78__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_78__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_79_ Bits */
/* PKA_PKA_RAM_DATA_79_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_79__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_79__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_80_ Bits */
/* PKA_PKA_RAM_DATA_80_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_80__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_80__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_81_ Bits */
/* PKA_PKA_RAM_DATA_81_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_81__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_81__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_82_ Bits */
/* PKA_PKA_RAM_DATA_82_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_82__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_82__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_83_ Bits */
/* PKA_PKA_RAM_DATA_83_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_83__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_83__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_84_ Bits */
/* PKA_PKA_RAM_DATA_84_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_84__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_84__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_85_ Bits */
/* PKA_PKA_RAM_DATA_85_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_85__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_85__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_86_ Bits */
/* PKA_PKA_RAM_DATA_86_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_86__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_86__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_87_ Bits */
/* PKA_PKA_RAM_DATA_87_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_87__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_87__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_88_ Bits */
/* PKA_PKA_RAM_DATA_88_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_88__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_88__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_89_ Bits */
/* PKA_PKA_RAM_DATA_89_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_89__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_89__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_90_ Bits */
/* PKA_PKA_RAM_DATA_90_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_90__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_90__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_91_ Bits */
/* PKA_PKA_RAM_DATA_91_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_91__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_91__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_92_ Bits */
/* PKA_PKA_RAM_DATA_92_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_92__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_92__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_93_ Bits */
/* PKA_PKA_RAM_DATA_93_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_93__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_93__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_94_ Bits */
/* PKA_PKA_RAM_DATA_94_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_94__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_94__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_95_ Bits */
/* PKA_PKA_RAM_DATA_95_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_95__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_95__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_96_ Bits */
/* PKA_PKA_RAM_DATA_96_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_96__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_96__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_97_ Bits */
/* PKA_PKA_RAM_DATA_97_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_97__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_97__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_98_ Bits */
/* PKA_PKA_RAM_DATA_98_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_98__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_98__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_99_ Bits */
/* PKA_PKA_RAM_DATA_99_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_99__VECTOR_DATA_OFS     (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_99__VECTOR_DATA_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_100_ Bits */
/* PKA_PKA_RAM_DATA_100_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_100__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_100__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_101_ Bits */
/* PKA_PKA_RAM_DATA_101_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_101__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_101__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_102_ Bits */
/* PKA_PKA_RAM_DATA_102_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_102__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_102__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_103_ Bits */
/* PKA_PKA_RAM_DATA_103_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_103__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_103__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_104_ Bits */
/* PKA_PKA_RAM_DATA_104_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_104__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_104__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_105_ Bits */
/* PKA_PKA_RAM_DATA_105_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_105__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_105__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_106_ Bits */
/* PKA_PKA_RAM_DATA_106_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_106__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_106__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_107_ Bits */
/* PKA_PKA_RAM_DATA_107_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_107__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_107__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_108_ Bits */
/* PKA_PKA_RAM_DATA_108_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_108__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_108__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_109_ Bits */
/* PKA_PKA_RAM_DATA_109_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_109__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_109__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_110_ Bits */
/* PKA_PKA_RAM_DATA_110_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_110__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_110__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_111_ Bits */
/* PKA_PKA_RAM_DATA_111_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_111__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_111__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_112_ Bits */
/* PKA_PKA_RAM_DATA_112_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_112__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_112__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_113_ Bits */
/* PKA_PKA_RAM_DATA_113_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_113__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_113__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_114_ Bits */
/* PKA_PKA_RAM_DATA_114_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_114__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_114__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_115_ Bits */
/* PKA_PKA_RAM_DATA_115_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_115__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_115__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_116_ Bits */
/* PKA_PKA_RAM_DATA_116_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_116__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_116__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_117_ Bits */
/* PKA_PKA_RAM_DATA_117_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_117__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_117__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_118_ Bits */
/* PKA_PKA_RAM_DATA_118_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_118__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_118__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_119_ Bits */
/* PKA_PKA_RAM_DATA_119_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_119__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_119__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_120_ Bits */
/* PKA_PKA_RAM_DATA_120_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_120__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_120__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_121_ Bits */
/* PKA_PKA_RAM_DATA_121_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_121__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_121__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_122_ Bits */
/* PKA_PKA_RAM_DATA_122_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_122__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_122__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_123_ Bits */
/* PKA_PKA_RAM_DATA_123_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_123__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_123__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_124_ Bits */
/* PKA_PKA_RAM_DATA_124_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_124__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_124__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_125_ Bits */
/* PKA_PKA_RAM_DATA_125_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_125__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_125__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_126_ Bits */
/* PKA_PKA_RAM_DATA_126_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_126__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_126__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_127_ Bits */
/* PKA_PKA_RAM_DATA_127_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_127__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_127__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_128_ Bits */
/* PKA_PKA_RAM_DATA_128_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_128__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_128__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_129_ Bits */
/* PKA_PKA_RAM_DATA_129_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_129__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_129__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_130_ Bits */
/* PKA_PKA_RAM_DATA_130_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_130__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_130__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_131_ Bits */
/* PKA_PKA_RAM_DATA_131_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_131__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_131__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_132_ Bits */
/* PKA_PKA_RAM_DATA_132_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_132__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_132__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_133_ Bits */
/* PKA_PKA_RAM_DATA_133_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_133__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_133__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_134_ Bits */
/* PKA_PKA_RAM_DATA_134_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_134__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_134__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_135_ Bits */
/* PKA_PKA_RAM_DATA_135_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_135__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_135__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_136_ Bits */
/* PKA_PKA_RAM_DATA_136_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_136__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_136__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_137_ Bits */
/* PKA_PKA_RAM_DATA_137_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_137__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_137__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_138_ Bits */
/* PKA_PKA_RAM_DATA_138_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_138__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_138__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_139_ Bits */
/* PKA_PKA_RAM_DATA_139_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_139__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_139__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_140_ Bits */
/* PKA_PKA_RAM_DATA_140_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_140__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_140__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_141_ Bits */
/* PKA_PKA_RAM_DATA_141_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_141__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_141__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_142_ Bits */
/* PKA_PKA_RAM_DATA_142_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_142__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_142__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_143_ Bits */
/* PKA_PKA_RAM_DATA_143_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_143__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_143__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_144_ Bits */
/* PKA_PKA_RAM_DATA_144_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_144__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_144__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_145_ Bits */
/* PKA_PKA_RAM_DATA_145_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_145__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_145__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_146_ Bits */
/* PKA_PKA_RAM_DATA_146_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_146__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_146__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_147_ Bits */
/* PKA_PKA_RAM_DATA_147_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_147__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_147__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_148_ Bits */
/* PKA_PKA_RAM_DATA_148_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_148__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_148__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_149_ Bits */
/* PKA_PKA_RAM_DATA_149_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_149__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_149__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_150_ Bits */
/* PKA_PKA_RAM_DATA_150_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_150__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_150__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_151_ Bits */
/* PKA_PKA_RAM_DATA_151_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_151__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_151__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_152_ Bits */
/* PKA_PKA_RAM_DATA_152_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_152__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_152__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_153_ Bits */
/* PKA_PKA_RAM_DATA_153_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_153__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_153__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_154_ Bits */
/* PKA_PKA_RAM_DATA_154_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_154__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_154__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_155_ Bits */
/* PKA_PKA_RAM_DATA_155_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_155__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_155__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_156_ Bits */
/* PKA_PKA_RAM_DATA_156_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_156__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_156__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_157_ Bits */
/* PKA_PKA_RAM_DATA_157_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_157__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_157__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_158_ Bits */
/* PKA_PKA_RAM_DATA_158_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_158__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_158__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_159_ Bits */
/* PKA_PKA_RAM_DATA_159_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_159__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_159__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_160_ Bits */
/* PKA_PKA_RAM_DATA_160_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_160__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_160__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_161_ Bits */
/* PKA_PKA_RAM_DATA_161_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_161__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_161__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_162_ Bits */
/* PKA_PKA_RAM_DATA_162_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_162__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_162__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_163_ Bits */
/* PKA_PKA_RAM_DATA_163_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_163__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_163__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_164_ Bits */
/* PKA_PKA_RAM_DATA_164_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_164__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_164__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_165_ Bits */
/* PKA_PKA_RAM_DATA_165_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_165__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_165__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_166_ Bits */
/* PKA_PKA_RAM_DATA_166_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_166__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_166__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_167_ Bits */
/* PKA_PKA_RAM_DATA_167_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_167__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_167__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_168_ Bits */
/* PKA_PKA_RAM_DATA_168_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_168__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_168__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_169_ Bits */
/* PKA_PKA_RAM_DATA_169_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_169__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_169__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_170_ Bits */
/* PKA_PKA_RAM_DATA_170_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_170__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_170__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_171_ Bits */
/* PKA_PKA_RAM_DATA_171_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_171__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_171__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_172_ Bits */
/* PKA_PKA_RAM_DATA_172_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_172__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_172__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_173_ Bits */
/* PKA_PKA_RAM_DATA_173_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_173__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_173__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_174_ Bits */
/* PKA_PKA_RAM_DATA_174_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_174__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_174__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_175_ Bits */
/* PKA_PKA_RAM_DATA_175_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_175__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_175__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_176_ Bits */
/* PKA_PKA_RAM_DATA_176_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_176__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_176__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_177_ Bits */
/* PKA_PKA_RAM_DATA_177_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_177__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_177__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_178_ Bits */
/* PKA_PKA_RAM_DATA_178_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_178__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_178__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_179_ Bits */
/* PKA_PKA_RAM_DATA_179_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_179__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_179__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_180_ Bits */
/* PKA_PKA_RAM_DATA_180_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_180__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_180__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_181_ Bits */
/* PKA_PKA_RAM_DATA_181_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_181__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_181__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_182_ Bits */
/* PKA_PKA_RAM_DATA_182_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_182__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_182__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_183_ Bits */
/* PKA_PKA_RAM_DATA_183_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_183__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_183__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_184_ Bits */
/* PKA_PKA_RAM_DATA_184_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_184__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_184__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_185_ Bits */
/* PKA_PKA_RAM_DATA_185_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_185__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_185__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_186_ Bits */
/* PKA_PKA_RAM_DATA_186_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_186__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_186__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_187_ Bits */
/* PKA_PKA_RAM_DATA_187_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_187__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_187__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_188_ Bits */
/* PKA_PKA_RAM_DATA_188_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_188__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_188__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_189_ Bits */
/* PKA_PKA_RAM_DATA_189_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_189__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_189__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_190_ Bits */
/* PKA_PKA_RAM_DATA_190_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_190__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_190__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_191_ Bits */
/* PKA_PKA_RAM_DATA_191_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_191__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_191__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_192_ Bits */
/* PKA_PKA_RAM_DATA_192_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_192__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_192__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_193_ Bits */
/* PKA_PKA_RAM_DATA_193_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_193__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_193__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_194_ Bits */
/* PKA_PKA_RAM_DATA_194_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_194__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_194__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_195_ Bits */
/* PKA_PKA_RAM_DATA_195_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_195__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_195__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_196_ Bits */
/* PKA_PKA_RAM_DATA_196_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_196__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_196__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_197_ Bits */
/* PKA_PKA_RAM_DATA_197_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_197__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_197__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_198_ Bits */
/* PKA_PKA_RAM_DATA_198_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_198__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_198__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_199_ Bits */
/* PKA_PKA_RAM_DATA_199_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_199__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_199__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_200_ Bits */
/* PKA_PKA_RAM_DATA_200_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_200__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_200__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_201_ Bits */
/* PKA_PKA_RAM_DATA_201_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_201__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_201__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_202_ Bits */
/* PKA_PKA_RAM_DATA_202_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_202__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_202__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_203_ Bits */
/* PKA_PKA_RAM_DATA_203_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_203__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_203__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_204_ Bits */
/* PKA_PKA_RAM_DATA_204_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_204__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_204__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_205_ Bits */
/* PKA_PKA_RAM_DATA_205_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_205__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_205__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_206_ Bits */
/* PKA_PKA_RAM_DATA_206_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_206__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_206__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_207_ Bits */
/* PKA_PKA_RAM_DATA_207_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_207__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_207__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_208_ Bits */
/* PKA_PKA_RAM_DATA_208_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_208__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_208__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_209_ Bits */
/* PKA_PKA_RAM_DATA_209_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_209__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_209__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_210_ Bits */
/* PKA_PKA_RAM_DATA_210_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_210__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_210__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_211_ Bits */
/* PKA_PKA_RAM_DATA_211_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_211__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_211__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_212_ Bits */
/* PKA_PKA_RAM_DATA_212_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_212__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_212__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_213_ Bits */
/* PKA_PKA_RAM_DATA_213_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_213__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_213__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_214_ Bits */
/* PKA_PKA_RAM_DATA_214_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_214__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_214__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_215_ Bits */
/* PKA_PKA_RAM_DATA_215_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_215__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_215__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_216_ Bits */
/* PKA_PKA_RAM_DATA_216_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_216__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_216__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_217_ Bits */
/* PKA_PKA_RAM_DATA_217_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_217__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_217__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_218_ Bits */
/* PKA_PKA_RAM_DATA_218_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_218__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_218__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_219_ Bits */
/* PKA_PKA_RAM_DATA_219_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_219__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_219__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_220_ Bits */
/* PKA_PKA_RAM_DATA_220_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_220__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_220__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_221_ Bits */
/* PKA_PKA_RAM_DATA_221_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_221__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_221__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_222_ Bits */
/* PKA_PKA_RAM_DATA_222_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_222__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_222__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_223_ Bits */
/* PKA_PKA_RAM_DATA_223_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_223__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_223__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_224_ Bits */
/* PKA_PKA_RAM_DATA_224_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_224__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_224__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_225_ Bits */
/* PKA_PKA_RAM_DATA_225_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_225__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_225__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_226_ Bits */
/* PKA_PKA_RAM_DATA_226_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_226__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_226__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_227_ Bits */
/* PKA_PKA_RAM_DATA_227_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_227__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_227__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_228_ Bits */
/* PKA_PKA_RAM_DATA_228_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_228__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_228__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_229_ Bits */
/* PKA_PKA_RAM_DATA_229_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_229__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_229__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_230_ Bits */
/* PKA_PKA_RAM_DATA_230_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_230__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_230__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_231_ Bits */
/* PKA_PKA_RAM_DATA_231_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_231__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_231__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_232_ Bits */
/* PKA_PKA_RAM_DATA_232_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_232__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_232__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_233_ Bits */
/* PKA_PKA_RAM_DATA_233_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_233__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_233__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_234_ Bits */
/* PKA_PKA_RAM_DATA_234_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_234__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_234__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_235_ Bits */
/* PKA_PKA_RAM_DATA_235_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_235__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_235__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_236_ Bits */
/* PKA_PKA_RAM_DATA_236_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_236__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_236__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_237_ Bits */
/* PKA_PKA_RAM_DATA_237_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_237__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_237__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_238_ Bits */
/* PKA_PKA_RAM_DATA_238_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_238__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_238__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_239_ Bits */
/* PKA_PKA_RAM_DATA_239_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_239__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_239__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_240_ Bits */
/* PKA_PKA_RAM_DATA_240_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_240__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_240__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_241_ Bits */
/* PKA_PKA_RAM_DATA_241_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_241__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_241__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_242_ Bits */
/* PKA_PKA_RAM_DATA_242_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_242__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_242__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_243_ Bits */
/* PKA_PKA_RAM_DATA_243_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_243__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_243__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_244_ Bits */
/* PKA_PKA_RAM_DATA_244_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_244__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_244__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_245_ Bits */
/* PKA_PKA_RAM_DATA_245_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_245__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_245__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_246_ Bits */
/* PKA_PKA_RAM_DATA_246_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_246__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_246__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_247_ Bits */
/* PKA_PKA_RAM_DATA_247_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_247__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_247__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_248_ Bits */
/* PKA_PKA_RAM_DATA_248_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_248__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_248__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_249_ Bits */
/* PKA_PKA_RAM_DATA_249_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_249__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_249__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_250_ Bits */
/* PKA_PKA_RAM_DATA_250_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_250__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_250__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_251_ Bits */
/* PKA_PKA_RAM_DATA_251_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_251__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_251__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_252_ Bits */
/* PKA_PKA_RAM_DATA_252_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_252__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_252__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_253_ Bits */
/* PKA_PKA_RAM_DATA_253_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_253__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_253__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_254_ Bits */
/* PKA_PKA_RAM_DATA_254_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_254__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_254__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_255_ Bits */
/* PKA_PKA_RAM_DATA_255_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_255__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_255__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_256_ Bits */
/* PKA_PKA_RAM_DATA_256_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_256__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_256__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_257_ Bits */
/* PKA_PKA_RAM_DATA_257_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_257__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_257__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_258_ Bits */
/* PKA_PKA_RAM_DATA_258_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_258__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_258__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_259_ Bits */
/* PKA_PKA_RAM_DATA_259_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_259__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_259__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_260_ Bits */
/* PKA_PKA_RAM_DATA_260_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_260__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_260__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_261_ Bits */
/* PKA_PKA_RAM_DATA_261_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_261__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_261__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_262_ Bits */
/* PKA_PKA_RAM_DATA_262_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_262__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_262__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_263_ Bits */
/* PKA_PKA_RAM_DATA_263_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_263__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_263__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_264_ Bits */
/* PKA_PKA_RAM_DATA_264_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_264__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_264__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_265_ Bits */
/* PKA_PKA_RAM_DATA_265_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_265__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_265__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_266_ Bits */
/* PKA_PKA_RAM_DATA_266_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_266__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_266__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_267_ Bits */
/* PKA_PKA_RAM_DATA_267_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_267__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_267__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_268_ Bits */
/* PKA_PKA_RAM_DATA_268_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_268__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_268__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_269_ Bits */
/* PKA_PKA_RAM_DATA_269_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_269__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_269__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_270_ Bits */
/* PKA_PKA_RAM_DATA_270_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_270__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_270__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_271_ Bits */
/* PKA_PKA_RAM_DATA_271_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_271__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_271__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_272_ Bits */
/* PKA_PKA_RAM_DATA_272_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_272__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_272__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_273_ Bits */
/* PKA_PKA_RAM_DATA_273_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_273__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_273__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_274_ Bits */
/* PKA_PKA_RAM_DATA_274_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_274__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_274__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_275_ Bits */
/* PKA_PKA_RAM_DATA_275_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_275__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_275__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_276_ Bits */
/* PKA_PKA_RAM_DATA_276_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_276__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_276__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_277_ Bits */
/* PKA_PKA_RAM_DATA_277_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_277__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_277__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_278_ Bits */
/* PKA_PKA_RAM_DATA_278_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_278__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_278__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_279_ Bits */
/* PKA_PKA_RAM_DATA_279_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_279__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_279__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_280_ Bits */
/* PKA_PKA_RAM_DATA_280_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_280__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_280__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_281_ Bits */
/* PKA_PKA_RAM_DATA_281_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_281__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_281__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_282_ Bits */
/* PKA_PKA_RAM_DATA_282_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_282__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_282__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_283_ Bits */
/* PKA_PKA_RAM_DATA_283_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_283__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_283__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_284_ Bits */
/* PKA_PKA_RAM_DATA_284_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_284__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_284__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_285_ Bits */
/* PKA_PKA_RAM_DATA_285_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_285__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_285__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_286_ Bits */
/* PKA_PKA_RAM_DATA_286_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_286__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_286__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_287_ Bits */
/* PKA_PKA_RAM_DATA_287_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_287__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_287__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_288_ Bits */
/* PKA_PKA_RAM_DATA_288_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_288__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_288__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_289_ Bits */
/* PKA_PKA_RAM_DATA_289_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_289__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_289__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_290_ Bits */
/* PKA_PKA_RAM_DATA_290_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_290__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_290__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_291_ Bits */
/* PKA_PKA_RAM_DATA_291_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_291__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_291__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_292_ Bits */
/* PKA_PKA_RAM_DATA_292_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_292__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_292__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_293_ Bits */
/* PKA_PKA_RAM_DATA_293_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_293__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_293__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_294_ Bits */
/* PKA_PKA_RAM_DATA_294_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_294__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_294__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_295_ Bits */
/* PKA_PKA_RAM_DATA_295_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_295__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_295__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_296_ Bits */
/* PKA_PKA_RAM_DATA_296_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_296__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_296__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_297_ Bits */
/* PKA_PKA_RAM_DATA_297_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_297__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_297__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_298_ Bits */
/* PKA_PKA_RAM_DATA_298_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_298__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_298__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_299_ Bits */
/* PKA_PKA_RAM_DATA_299_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_299__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_299__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_300_ Bits */
/* PKA_PKA_RAM_DATA_300_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_300__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_300__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_301_ Bits */
/* PKA_PKA_RAM_DATA_301_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_301__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_301__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_302_ Bits */
/* PKA_PKA_RAM_DATA_302_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_302__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_302__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_303_ Bits */
/* PKA_PKA_RAM_DATA_303_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_303__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_303__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_304_ Bits */
/* PKA_PKA_RAM_DATA_304_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_304__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_304__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_305_ Bits */
/* PKA_PKA_RAM_DATA_305_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_305__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_305__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_306_ Bits */
/* PKA_PKA_RAM_DATA_306_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_306__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_306__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_307_ Bits */
/* PKA_PKA_RAM_DATA_307_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_307__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_307__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_308_ Bits */
/* PKA_PKA_RAM_DATA_308_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_308__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_308__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_309_ Bits */
/* PKA_PKA_RAM_DATA_309_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_309__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_309__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_310_ Bits */
/* PKA_PKA_RAM_DATA_310_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_310__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_310__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_311_ Bits */
/* PKA_PKA_RAM_DATA_311_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_311__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_311__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_312_ Bits */
/* PKA_PKA_RAM_DATA_312_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_312__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_312__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_313_ Bits */
/* PKA_PKA_RAM_DATA_313_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_313__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_313__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_314_ Bits */
/* PKA_PKA_RAM_DATA_314_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_314__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_314__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_315_ Bits */
/* PKA_PKA_RAM_DATA_315_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_315__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_315__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_316_ Bits */
/* PKA_PKA_RAM_DATA_316_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_316__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_316__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_317_ Bits */
/* PKA_PKA_RAM_DATA_317_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_317__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_317__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_318_ Bits */
/* PKA_PKA_RAM_DATA_318_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_318__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_318__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_319_ Bits */
/* PKA_PKA_RAM_DATA_319_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_319__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_319__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_320_ Bits */
/* PKA_PKA_RAM_DATA_320_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_320__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_320__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_321_ Bits */
/* PKA_PKA_RAM_DATA_321_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_321__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_321__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_322_ Bits */
/* PKA_PKA_RAM_DATA_322_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_322__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_322__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_323_ Bits */
/* PKA_PKA_RAM_DATA_323_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_323__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_323__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_324_ Bits */
/* PKA_PKA_RAM_DATA_324_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_324__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_324__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_325_ Bits */
/* PKA_PKA_RAM_DATA_325_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_325__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_325__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_326_ Bits */
/* PKA_PKA_RAM_DATA_326_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_326__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_326__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_327_ Bits */
/* PKA_PKA_RAM_DATA_327_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_327__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_327__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_328_ Bits */
/* PKA_PKA_RAM_DATA_328_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_328__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_328__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_329_ Bits */
/* PKA_PKA_RAM_DATA_329_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_329__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_329__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_330_ Bits */
/* PKA_PKA_RAM_DATA_330_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_330__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_330__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_331_ Bits */
/* PKA_PKA_RAM_DATA_331_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_331__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_331__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_332_ Bits */
/* PKA_PKA_RAM_DATA_332_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_332__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_332__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_333_ Bits */
/* PKA_PKA_RAM_DATA_333_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_333__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_333__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_334_ Bits */
/* PKA_PKA_RAM_DATA_334_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_334__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_334__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_335_ Bits */
/* PKA_PKA_RAM_DATA_335_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_335__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_335__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_336_ Bits */
/* PKA_PKA_RAM_DATA_336_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_336__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_336__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_337_ Bits */
/* PKA_PKA_RAM_DATA_337_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_337__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_337__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_338_ Bits */
/* PKA_PKA_RAM_DATA_338_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_338__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_338__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_339_ Bits */
/* PKA_PKA_RAM_DATA_339_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_339__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_339__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_340_ Bits */
/* PKA_PKA_RAM_DATA_340_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_340__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_340__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_341_ Bits */
/* PKA_PKA_RAM_DATA_341_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_341__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_341__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_342_ Bits */
/* PKA_PKA_RAM_DATA_342_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_342__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_342__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_343_ Bits */
/* PKA_PKA_RAM_DATA_343_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_343__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_343__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_344_ Bits */
/* PKA_PKA_RAM_DATA_344_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_344__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_344__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_345_ Bits */
/* PKA_PKA_RAM_DATA_345_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_345__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_345__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_346_ Bits */
/* PKA_PKA_RAM_DATA_346_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_346__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_346__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_347_ Bits */
/* PKA_PKA_RAM_DATA_347_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_347__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_347__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_348_ Bits */
/* PKA_PKA_RAM_DATA_348_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_348__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_348__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_349_ Bits */
/* PKA_PKA_RAM_DATA_349_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_349__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_349__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_350_ Bits */
/* PKA_PKA_RAM_DATA_350_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_350__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_350__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_351_ Bits */
/* PKA_PKA_RAM_DATA_351_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_351__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_351__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_352_ Bits */
/* PKA_PKA_RAM_DATA_352_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_352__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_352__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_353_ Bits */
/* PKA_PKA_RAM_DATA_353_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_353__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_353__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_354_ Bits */
/* PKA_PKA_RAM_DATA_354_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_354__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_354__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_355_ Bits */
/* PKA_PKA_RAM_DATA_355_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_355__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_355__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_356_ Bits */
/* PKA_PKA_RAM_DATA_356_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_356__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_356__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_357_ Bits */
/* PKA_PKA_RAM_DATA_357_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_357__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_357__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_358_ Bits */
/* PKA_PKA_RAM_DATA_358_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_358__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_358__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_359_ Bits */
/* PKA_PKA_RAM_DATA_359_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_359__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_359__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_360_ Bits */
/* PKA_PKA_RAM_DATA_360_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_360__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_360__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_361_ Bits */
/* PKA_PKA_RAM_DATA_361_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_361__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_361__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_362_ Bits */
/* PKA_PKA_RAM_DATA_362_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_362__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_362__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_363_ Bits */
/* PKA_PKA_RAM_DATA_363_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_363__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_363__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_364_ Bits */
/* PKA_PKA_RAM_DATA_364_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_364__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_364__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_365_ Bits */
/* PKA_PKA_RAM_DATA_365_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_365__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_365__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_366_ Bits */
/* PKA_PKA_RAM_DATA_366_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_366__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_366__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_367_ Bits */
/* PKA_PKA_RAM_DATA_367_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_367__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_367__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_368_ Bits */
/* PKA_PKA_RAM_DATA_368_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_368__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_368__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_369_ Bits */
/* PKA_PKA_RAM_DATA_369_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_369__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_369__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_370_ Bits */
/* PKA_PKA_RAM_DATA_370_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_370__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_370__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_371_ Bits */
/* PKA_PKA_RAM_DATA_371_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_371__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_371__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_372_ Bits */
/* PKA_PKA_RAM_DATA_372_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_372__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_372__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_373_ Bits */
/* PKA_PKA_RAM_DATA_373_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_373__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_373__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_374_ Bits */
/* PKA_PKA_RAM_DATA_374_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_374__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_374__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_375_ Bits */
/* PKA_PKA_RAM_DATA_375_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_375__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_375__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_376_ Bits */
/* PKA_PKA_RAM_DATA_376_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_376__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_376__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_377_ Bits */
/* PKA_PKA_RAM_DATA_377_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_377__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_377__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_378_ Bits */
/* PKA_PKA_RAM_DATA_378_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_378__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_378__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_379_ Bits */
/* PKA_PKA_RAM_DATA_379_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_379__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_379__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_380_ Bits */
/* PKA_PKA_RAM_DATA_380_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_380__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_380__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_381_ Bits */
/* PKA_PKA_RAM_DATA_381_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_381__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_381__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_382_ Bits */
/* PKA_PKA_RAM_DATA_382_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_382__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_382__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_383_ Bits */
/* PKA_PKA_RAM_DATA_383_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_383__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_383__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_384_ Bits */
/* PKA_PKA_RAM_DATA_384_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_384__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_384__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_385_ Bits */
/* PKA_PKA_RAM_DATA_385_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_385__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_385__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_386_ Bits */
/* PKA_PKA_RAM_DATA_386_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_386__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_386__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_387_ Bits */
/* PKA_PKA_RAM_DATA_387_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_387__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_387__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_388_ Bits */
/* PKA_PKA_RAM_DATA_388_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_388__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_388__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_389_ Bits */
/* PKA_PKA_RAM_DATA_389_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_389__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_389__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_390_ Bits */
/* PKA_PKA_RAM_DATA_390_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_390__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_390__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_391_ Bits */
/* PKA_PKA_RAM_DATA_391_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_391__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_391__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_392_ Bits */
/* PKA_PKA_RAM_DATA_392_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_392__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_392__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_393_ Bits */
/* PKA_PKA_RAM_DATA_393_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_393__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_393__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_394_ Bits */
/* PKA_PKA_RAM_DATA_394_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_394__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_394__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_395_ Bits */
/* PKA_PKA_RAM_DATA_395_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_395__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_395__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_396_ Bits */
/* PKA_PKA_RAM_DATA_396_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_396__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_396__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_397_ Bits */
/* PKA_PKA_RAM_DATA_397_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_397__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_397__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_398_ Bits */
/* PKA_PKA_RAM_DATA_398_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_398__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_398__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_399_ Bits */
/* PKA_PKA_RAM_DATA_399_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_399__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_399__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_400_ Bits */
/* PKA_PKA_RAM_DATA_400_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_400__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_400__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_401_ Bits */
/* PKA_PKA_RAM_DATA_401_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_401__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_401__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_402_ Bits */
/* PKA_PKA_RAM_DATA_402_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_402__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_402__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_403_ Bits */
/* PKA_PKA_RAM_DATA_403_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_403__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_403__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_404_ Bits */
/* PKA_PKA_RAM_DATA_404_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_404__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_404__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_405_ Bits */
/* PKA_PKA_RAM_DATA_405_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_405__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_405__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_406_ Bits */
/* PKA_PKA_RAM_DATA_406_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_406__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_406__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_407_ Bits */
/* PKA_PKA_RAM_DATA_407_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_407__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_407__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_408_ Bits */
/* PKA_PKA_RAM_DATA_408_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_408__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_408__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_409_ Bits */
/* PKA_PKA_RAM_DATA_409_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_409__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_409__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_410_ Bits */
/* PKA_PKA_RAM_DATA_410_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_410__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_410__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_411_ Bits */
/* PKA_PKA_RAM_DATA_411_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_411__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_411__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_412_ Bits */
/* PKA_PKA_RAM_DATA_412_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_412__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_412__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_413_ Bits */
/* PKA_PKA_RAM_DATA_413_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_413__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_413__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_414_ Bits */
/* PKA_PKA_RAM_DATA_414_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_414__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_414__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_415_ Bits */
/* PKA_PKA_RAM_DATA_415_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_415__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_415__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_416_ Bits */
/* PKA_PKA_RAM_DATA_416_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_416__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_416__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_417_ Bits */
/* PKA_PKA_RAM_DATA_417_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_417__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_417__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_418_ Bits */
/* PKA_PKA_RAM_DATA_418_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_418__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_418__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_419_ Bits */
/* PKA_PKA_RAM_DATA_419_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_419__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_419__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_420_ Bits */
/* PKA_PKA_RAM_DATA_420_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_420__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_420__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_421_ Bits */
/* PKA_PKA_RAM_DATA_421_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_421__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_421__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_422_ Bits */
/* PKA_PKA_RAM_DATA_422_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_422__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_422__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_423_ Bits */
/* PKA_PKA_RAM_DATA_423_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_423__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_423__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_424_ Bits */
/* PKA_PKA_RAM_DATA_424_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_424__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_424__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_425_ Bits */
/* PKA_PKA_RAM_DATA_425_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_425__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_425__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_426_ Bits */
/* PKA_PKA_RAM_DATA_426_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_426__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_426__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_427_ Bits */
/* PKA_PKA_RAM_DATA_427_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_427__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_427__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_428_ Bits */
/* PKA_PKA_RAM_DATA_428_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_428__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_428__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_429_ Bits */
/* PKA_PKA_RAM_DATA_429_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_429__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_429__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_430_ Bits */
/* PKA_PKA_RAM_DATA_430_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_430__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_430__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_431_ Bits */
/* PKA_PKA_RAM_DATA_431_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_431__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_431__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_432_ Bits */
/* PKA_PKA_RAM_DATA_432_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_432__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_432__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_433_ Bits */
/* PKA_PKA_RAM_DATA_433_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_433__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_433__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_434_ Bits */
/* PKA_PKA_RAM_DATA_434_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_434__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_434__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_435_ Bits */
/* PKA_PKA_RAM_DATA_435_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_435__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_435__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_436_ Bits */
/* PKA_PKA_RAM_DATA_436_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_436__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_436__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_437_ Bits */
/* PKA_PKA_RAM_DATA_437_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_437__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_437__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_438_ Bits */
/* PKA_PKA_RAM_DATA_438_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_438__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_438__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_439_ Bits */
/* PKA_PKA_RAM_DATA_439_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_439__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_439__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_440_ Bits */
/* PKA_PKA_RAM_DATA_440_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_440__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_440__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_441_ Bits */
/* PKA_PKA_RAM_DATA_441_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_441__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_441__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_442_ Bits */
/* PKA_PKA_RAM_DATA_442_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_442__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_442__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_443_ Bits */
/* PKA_PKA_RAM_DATA_443_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_443__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_443__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_444_ Bits */
/* PKA_PKA_RAM_DATA_444_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_444__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_444__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_445_ Bits */
/* PKA_PKA_RAM_DATA_445_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_445__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_445__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_446_ Bits */
/* PKA_PKA_RAM_DATA_446_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_446__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_446__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_447_ Bits */
/* PKA_PKA_RAM_DATA_447_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_447__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_447__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_448_ Bits */
/* PKA_PKA_RAM_DATA_448_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_448__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_448__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_449_ Bits */
/* PKA_PKA_RAM_DATA_449_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_449__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_449__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_450_ Bits */
/* PKA_PKA_RAM_DATA_450_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_450__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_450__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_451_ Bits */
/* PKA_PKA_RAM_DATA_451_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_451__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_451__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_452_ Bits */
/* PKA_PKA_RAM_DATA_452_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_452__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_452__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_453_ Bits */
/* PKA_PKA_RAM_DATA_453_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_453__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_453__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_454_ Bits */
/* PKA_PKA_RAM_DATA_454_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_454__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_454__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_455_ Bits */
/* PKA_PKA_RAM_DATA_455_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_455__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_455__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_456_ Bits */
/* PKA_PKA_RAM_DATA_456_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_456__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_456__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_457_ Bits */
/* PKA_PKA_RAM_DATA_457_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_457__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_457__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_458_ Bits */
/* PKA_PKA_RAM_DATA_458_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_458__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_458__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_459_ Bits */
/* PKA_PKA_RAM_DATA_459_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_459__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_459__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_460_ Bits */
/* PKA_PKA_RAM_DATA_460_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_460__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_460__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_461_ Bits */
/* PKA_PKA_RAM_DATA_461_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_461__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_461__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_462_ Bits */
/* PKA_PKA_RAM_DATA_462_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_462__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_462__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_463_ Bits */
/* PKA_PKA_RAM_DATA_463_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_463__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_463__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_464_ Bits */
/* PKA_PKA_RAM_DATA_464_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_464__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_464__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_465_ Bits */
/* PKA_PKA_RAM_DATA_465_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_465__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_465__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_466_ Bits */
/* PKA_PKA_RAM_DATA_466_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_466__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_466__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_467_ Bits */
/* PKA_PKA_RAM_DATA_467_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_467__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_467__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_468_ Bits */
/* PKA_PKA_RAM_DATA_468_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_468__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_468__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_469_ Bits */
/* PKA_PKA_RAM_DATA_469_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_469__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_469__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_470_ Bits */
/* PKA_PKA_RAM_DATA_470_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_470__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_470__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_471_ Bits */
/* PKA_PKA_RAM_DATA_471_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_471__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_471__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_472_ Bits */
/* PKA_PKA_RAM_DATA_472_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_472__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_472__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_473_ Bits */
/* PKA_PKA_RAM_DATA_473_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_473__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_473__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_474_ Bits */
/* PKA_PKA_RAM_DATA_474_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_474__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_474__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_475_ Bits */
/* PKA_PKA_RAM_DATA_475_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_475__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_475__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_476_ Bits */
/* PKA_PKA_RAM_DATA_476_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_476__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_476__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_477_ Bits */
/* PKA_PKA_RAM_DATA_477_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_477__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_477__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_478_ Bits */
/* PKA_PKA_RAM_DATA_478_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_478__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_478__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_479_ Bits */
/* PKA_PKA_RAM_DATA_479_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_479__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_479__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_480_ Bits */
/* PKA_PKA_RAM_DATA_480_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_480__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_480__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_481_ Bits */
/* PKA_PKA_RAM_DATA_481_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_481__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_481__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_482_ Bits */
/* PKA_PKA_RAM_DATA_482_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_482__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_482__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_483_ Bits */
/* PKA_PKA_RAM_DATA_483_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_483__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_483__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_484_ Bits */
/* PKA_PKA_RAM_DATA_484_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_484__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_484__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_485_ Bits */
/* PKA_PKA_RAM_DATA_485_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_485__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_485__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_486_ Bits */
/* PKA_PKA_RAM_DATA_486_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_486__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_486__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_487_ Bits */
/* PKA_PKA_RAM_DATA_487_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_487__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_487__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_488_ Bits */
/* PKA_PKA_RAM_DATA_488_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_488__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_488__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_489_ Bits */
/* PKA_PKA_RAM_DATA_489_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_489__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_489__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_490_ Bits */
/* PKA_PKA_RAM_DATA_490_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_490__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_490__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_491_ Bits */
/* PKA_PKA_RAM_DATA_491_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_491__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_491__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_492_ Bits */
/* PKA_PKA_RAM_DATA_492_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_492__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_492__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_493_ Bits */
/* PKA_PKA_RAM_DATA_493_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_493__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_493__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_494_ Bits */
/* PKA_PKA_RAM_DATA_494_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_494__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_494__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_495_ Bits */
/* PKA_PKA_RAM_DATA_495_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_495__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_495__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_496_ Bits */
/* PKA_PKA_RAM_DATA_496_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_496__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_496__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_497_ Bits */
/* PKA_PKA_RAM_DATA_497_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_497__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_497__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_498_ Bits */
/* PKA_PKA_RAM_DATA_498_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_498__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_498__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_499_ Bits */
/* PKA_PKA_RAM_DATA_499_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_499__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_499__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_500_ Bits */
/* PKA_PKA_RAM_DATA_500_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_500__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_500__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_501_ Bits */
/* PKA_PKA_RAM_DATA_501_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_501__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_501__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_502_ Bits */
/* PKA_PKA_RAM_DATA_502_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_502__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_502__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_503_ Bits */
/* PKA_PKA_RAM_DATA_503_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_503__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_503__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_504_ Bits */
/* PKA_PKA_RAM_DATA_504_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_504__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_504__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_505_ Bits */
/* PKA_PKA_RAM_DATA_505_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_505__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_505__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_506_ Bits */
/* PKA_PKA_RAM_DATA_506_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_506__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_506__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_507_ Bits */
/* PKA_PKA_RAM_DATA_507_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_507__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_507__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_508_ Bits */
/* PKA_PKA_RAM_DATA_508_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_508__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_508__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_509_ Bits */
/* PKA_PKA_RAM_DATA_509_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_509__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_509__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_510_ Bits */
/* PKA_PKA_RAM_DATA_510_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_510__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_510__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_PKA_RAM_DATA_511_ Bits */
/* PKA_PKA_RAM_DATA_511_[VECTOR_DATA] Bits */
#define PKA_PKA_RAM_DATA_511__VECTOR_DATA_OFS    (0)                             /* !< VECTOR_DATA Offset */
#define PKA_PKA_RAM_DATA_511__VECTOR_DATA_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< Vector DATA in RAM */

/* PKA_AIC_POL_CTRL Bits */
/* PKA_AIC_POL_CTRL[PKA_INT_0] Bits */
#define PKA_AIC_POL_CTRL_PKA_INT_0_OFS           (0)                             /* !< PKA_INT_0 Offset */
#define PKA_AIC_POL_CTRL_PKA_INT_0_MASK          ((uint32_t)0x00000001U)         /* !< Individual polarity (high
                                                                                    level/rising edge or low
                                                                                    level/falling edge) control bits per
                                                                                    interrupt input. The signal is as
                                                                                    follows: 0=Low level/falling edge
                                                                                    1=High level/rising edge Note: The
                                                                                    PolarityControl must be set to 1 for
                                                                                    all interrupts during the
                                                                                    initialization phase of the EIP-150. */
/* PKA_AIC_POL_CTRL[PKA_INT_1] Bits */
#define PKA_AIC_POL_CTRL_PKA_INT_1_OFS           (1)                             /* !< PKA_INT_1 Offset */
#define PKA_AIC_POL_CTRL_PKA_INT_1_MASK          ((uint32_t)0x00000002U)
/* PKA_AIC_POL_CTRL[PKA_INT_2] Bits */
#define PKA_AIC_POL_CTRL_PKA_INT_2_OFS           (2)                             /* !< PKA_INT_2 Offset */
#define PKA_AIC_POL_CTRL_PKA_INT_2_MASK          ((uint32_t)0x00000004U)
/* PKA_AIC_POL_CTRL[TRNG_IRQ] Bits */
#define PKA_AIC_POL_CTRL_TRNG_IRQ_OFS            (3)                             /* !< TRNG_IRQ Offset */
#define PKA_AIC_POL_CTRL_TRNG_IRQ_MASK           ((uint32_t)0x00000008U)
/* PKA_AIC_POL_CTRL[SL_ERR_INT] Bits */
#define PKA_AIC_POL_CTRL_SL_ERR_INT_OFS          (5)                             /* !< SL_ERR_INT Offset */
#define PKA_AIC_POL_CTRL_SL_ERR_INT_MASK         ((uint32_t)0x00000020U)
/* PKA_AIC_POL_CTRL[PROTECTION_INT] Bits */
#define PKA_AIC_POL_CTRL_PROTECTION_INT_OFS      (6)                             /* !< PROTECTION_INT Offset */
#define PKA_AIC_POL_CTRL_PROTECTION_INT_MASK     ((uint32_t)0x00000040U)

/* PKA_AIC_TYPE_CTRL Bits */
/* PKA_AIC_TYPE_CTRL[PKA_INT_0] Bits */
#define PKA_AIC_TYPE_CTRL_PKA_INT_0_OFS          (0)                             /* !< PKA_INT_0 Offset */
#define PKA_AIC_TYPE_CTRL_PKA_INT_0_MASK         ((uint32_t)0x00000001U)         /* !< Signal type (level or edge) control
                                                                                    bits for each interrupt input.
                                                                                    #br#0=level (the interrupt source
                                                                                    level determines the raw status)
                                                                                    #br#1=edge (the interrupt source is
                                                                                    connected to edge detector and output
                                                                                    of edge detector #br#determines the
                                                                                    raw status ) */
/* PKA_AIC_TYPE_CTRL[PKA_INT_1] Bits */
#define PKA_AIC_TYPE_CTRL_PKA_INT_1_OFS          (1)                             /* !< PKA_INT_1 Offset */
#define PKA_AIC_TYPE_CTRL_PKA_INT_1_MASK         ((uint32_t)0x00000002U)         /* !< Individual int level edge control */
/* PKA_AIC_TYPE_CTRL[PKA_INT_2] Bits */
#define PKA_AIC_TYPE_CTRL_PKA_INT_2_OFS          (2)                             /* !< PKA_INT_2 Offset */
#define PKA_AIC_TYPE_CTRL_PKA_INT_2_MASK         ((uint32_t)0x00000004U)         /* !< Individual int level edge control */
/* PKA_AIC_TYPE_CTRL[TRNG_IRQ] Bits */
#define PKA_AIC_TYPE_CTRL_TRNG_IRQ_OFS           (3)                             /* !< TRNG_IRQ Offset */
#define PKA_AIC_TYPE_CTRL_TRNG_IRQ_MASK          ((uint32_t)0x00000008U)         /* !< Individual int level edge control */
/* PKA_AIC_TYPE_CTRL[SL_ERR_INT] Bits */
#define PKA_AIC_TYPE_CTRL_SL_ERR_INT_OFS         (5)                             /* !< SL_ERR_INT Offset */
#define PKA_AIC_TYPE_CTRL_SL_ERR_INT_MASK        ((uint32_t)0x00000020U)         /* !< Individual int level edge control */
/* PKA_AIC_TYPE_CTRL[PROTECTION_INT] Bits */
#define PKA_AIC_TYPE_CTRL_PROTECTION_INT_OFS     (6)                             /* !< PROTECTION_INT Offset */
#define PKA_AIC_TYPE_CTRL_PROTECTION_INT_MASK    ((uint32_t)0x00000040U)         /* !< Individual int level edge control */

/* PKA_AIC_ENABLE_CTRL Bits */
/* PKA_AIC_ENABLE_CTRL[ENABLECONTROL] Bits */
#define PKA_AIC_ENABLE_CTRL_ENABLECONTROL_OFS    (0)                             /* !< ENABLECONTROL Offset */
#define PKA_AIC_ENABLE_CTRL_ENABLECONTROL_MASK   ((uint32_t)0x0000000FU)         /* !< Individual enable control bits per
                                                                                    interrupt input */
/* PKA_AIC_ENABLE_CTRL[ENABLECONTROL] Bits */

/* PKA_AIC_RAW_STAT Bits */
/* PKA_AIC_RAW_STAT[RAWSTATUS] Bits */
#define PKA_AIC_RAW_STAT_RAWSTATUS_OFS           (0)                             /* !< RAWSTATUS Offset */
#define PKA_AIC_RAW_STAT_RAWSTATUS_MASK          ((uint32_t)0x0000000FU)         /* !< Interrupt status */
/* PKA_AIC_RAW_STAT[RAWSTATUS] Bits */

/* PKA_AIC_ENABLE_SET Bits */
/* PKA_AIC_ENABLE_SET[ENABLESET] Bits */
#define PKA_AIC_ENABLE_SET_ENABLESET_OFS         (0)                             /* !< ENABLESET Offset */
#define PKA_AIC_ENABLE_SET_ENABLESET_MASK        ((uint32_t)0x0000000FU)         /* !< Individual interrupt enable bits
                                                                                    per interrupt input 0 = No effect. 1
                                                                                    = Sets the corresponding bit in the
                                                                                    AIC_ENABLE_CTRL register to '1', i.e.
                                                                                    enables that interrupt. The activated
                                                                                    bit of EnableSet will be cleared
                                                                                    internally */
/* PKA_AIC_ENABLE_SET[ENABLESET] Bits */

/* PKA_AIC_ENABLED_STAT Bits */
/* PKA_AIC_ENABLED_STAT[ENABLESTATUS] Bits */
#define PKA_AIC_ENABLED_STAT_ENABLESTATUS_OFS    (0)                             /* !< ENABLESTATUS Offset */
#define PKA_AIC_ENABLED_STAT_ENABLESTATUS_MASK   ((uint32_t)0x0000000FU)         /* !< EnableStatus */
/* PKA_AIC_ENABLED_STAT[ENABLESTATUS] Bits */

/* PKA_AIC_ACK Bits */
/* PKA_AIC_ACK[ACKNOWLEDGE] Bits */
#define PKA_AIC_ACK_ACKNOWLEDGE_OFS              (0)                             /* !< ACKNOWLEDGE Offset */
#define PKA_AIC_ACK_ACKNOWLEDGE_MASK             ((uint32_t)0x0000000FU)         /* !< Acknowledge interrupt */
/* PKA_AIC_ACK[ENABLESTATUS] Bits */
#define PKA_AIC_ACK_ENABLESTATUS_OFS             (5)                             /* !< ENABLESTATUS Offset */
#define PKA_AIC_ACK_ENABLESTATUS_MASK            ((uint32_t)0x00000020U)         /* !< Acknowledge interrupt */

/* PKA_AIC_ENABLE_CLR Bits */
/* PKA_AIC_ENABLE_CLR[ENABLECLEAR] Bits */
#define PKA_AIC_ENABLE_CLR_ENABLECLEAR_OFS       (0)                             /* !< ENABLECLEAR Offset */
#define PKA_AIC_ENABLE_CLR_ENABLECLEAR_MASK      ((uint32_t)0x0000000FU)         /* !< Individual interrupt disable bits
                                                                                    per interrupt input 0 = No effect. 1
                                                                                    = Resets the corresponding bit in the
                                                                                    AIC_ENABLE_CTRL register to '0', i.e.
                                                                                    disables that interrupt. The
                                                                                    activated bit of EnableClear will be
                                                                                    cleared internally */
/* PKA_AIC_ENABLE_CLR[ENABLECLEAR] Bits */

/* PKA_AIC_OPTIONS Bits */
/* PKA_AIC_OPTIONS[NUMBER_OF_INPUTS] Bits */
#define PKA_AIC_OPTIONS_NUMBER_OF_INPUTS_OFS     (0)                             /* !< NUMBER_OF_INPUTS Offset */
#define PKA_AIC_OPTIONS_NUMBER_OF_INPUTS_MASK    ((uint32_t)0x0000003FU)         /* !< Fixed to 0x06 */

/* PKA_AIC_VERSION Bits */
/* PKA_AIC_VERSION[BASIC_EIP_NUMBER] Bits */
#define PKA_AIC_VERSION_BASIC_EIP_NUMBER_OFS     (0)                             /* !< BASIC_EIP_NUMBER Offset */
#define PKA_AIC_VERSION_BASIC_EIP_NUMBER_MASK    ((uint32_t)0x000000FFU)         /* !< EIP number for the AIC, this field
                                                                                    contains the value 201  or hC9 */
/* PKA_AIC_VERSION[COMPLEMENT_OF_BASIC_EIP_NUMBER] Bits */
#define PKA_AIC_VERSION_COMPLEMENT_OF_BASIC_EIP_NUMBER_OFS (8)                             /* !< COMPLEMENT_OF_BASIC_EIP_NUMBER
                                                                                    Offset */
#define PKA_AIC_VERSION_COMPLEMENT_OF_BASIC_EIP_NUMBER_MASK ((uint32_t)0x0000FF00U)
/* PKA_AIC_VERSION[PATCH_LEVEL] Bits */
#define PKA_AIC_VERSION_PATCH_LEVEL_OFS          (16)                            /* !< PATCH_LEVEL Offset */
#define PKA_AIC_VERSION_PATCH_LEVEL_MASK         ((uint32_t)0x000F0000U)
/* PKA_AIC_VERSION[MAJOR_REVISION] Bits */
#define PKA_AIC_VERSION_MAJOR_REVISION_OFS       (20)                            /* !< MAJOR_REVISION Offset */
#define PKA_AIC_VERSION_MAJOR_REVISION_MASK      ((uint32_t)0x00F00000U)
/* PKA_AIC_VERSION[MINOR_REVISION] Bits */
#define PKA_AIC_VERSION_MINOR_REVISION_OFS       (24)                            /* !< MINOR_REVISION Offset */
#define PKA_AIC_VERSION_MINOR_REVISION_MASK      ((uint32_t)0x0F000000U)

/* PKA_EIP150_OPTIONS Bits */
/* PKA_EIP150_OPTIONS[PLB_INTERFACE] Bits */
#define PKA_EIP150_OPTIONS_PLB_INTERFACE_OFS     (0)                             /* !< PLB_INTERFACE Offset */
#define PKA_EIP150_OPTIONS_PLB_INTERFACE_MASK    ((uint32_t)0x00000001U)         /* !< Not available, set to zero for the
                                                                                    EIP 150ap AHB */
/* PKA_EIP150_OPTIONS[AHB_INTERFACE] Bits */
#define PKA_EIP150_OPTIONS_AHB_INTERFACE_OFS     (1)                             /* !< AHB_INTERFACE Offset */
#define PKA_EIP150_OPTIONS_AHB_INTERFACE_MASK    ((uint32_t)0x00000002U)         /* !< Set to 1: indicates the EIP 150ap
                                                                                    AHB configuration has a (synchronous)
                                                                                    AHB interface */
/* PKA_EIP150_OPTIONS[AHB_IS_ASYNCHRONOUS] Bits */
#define PKA_EIP150_OPTIONS_AHB_IS_ASYNCHRONOUS_OFS (2)                             /* !< AHB_IS_ASYNCHRONOUS Offset */
#define PKA_EIP150_OPTIONS_AHB_IS_ASYNCHRONOUS_MASK ((uint32_t)0x00000004U)         /* !< Not available, set to zero for the
                                                                                    EIP 150ap AHB */
/* PKA_EIP150_OPTIONS[AXI_INTERFACE] Bits */
#define PKA_EIP150_OPTIONS_AXI_INTERFACE_OFS     (3)                             /* !< AXI_INTERFACE Offset */
#define PKA_EIP150_OPTIONS_AXI_INTERFACE_MASK    ((uint32_t)0x00000008U)         /* !< Not available, set to zero for the
                                                                                    EIP 150ap AHB */
/* PKA_EIP150_OPTIONS[EIP28_PRESENT] Bits */
#define PKA_EIP150_OPTIONS_EIP28_PRESENT_OFS     (8)                             /* !< EIP28_PRESENT Offset */
#define PKA_EIP150_OPTIONS_EIP28_PRESENT_MASK    ((uint32_t)0x00000100U)         /* !< Set to 1: indicates the EIP 150ap
                                                                                    AHB configuration has an EIP-28 PKA
                                                                                    embedded */
/* PKA_EIP150_OPTIONS[EIP76_PRESENT] Bits */
#define PKA_EIP150_OPTIONS_EIP76_PRESENT_OFS     (9)                             /* !< EIP76_PRESENT Offset */
#define PKA_EIP150_OPTIONS_EIP76_PRESENT_MASK    ((uint32_t)0x00000200U)         /* !< Not available, set to zero for the
                                                                                    EIP 150ap AHB */
/* PKA_EIP150_OPTIONS[AIC_PRESENT] Bits */
#define PKA_EIP150_OPTIONS_AIC_PRESENT_OFS       (10)                            /* !< AIC_PRESENT Offset */
#define PKA_EIP150_OPTIONS_AIC_PRESENT_MASK      ((uint32_t)0x00000400U)         /* !< Not available, set to zero for the
                                                                                    EIP 150ap AHB */
/* PKA_EIP150_OPTIONS[RAM_ZEROIZE] Bits */
#define PKA_EIP150_OPTIONS_RAM_ZEROIZE_OFS       (11)                            /* !< RAM_ZEROIZE Offset */
#define PKA_EIP150_OPTIONS_RAM_ZEROIZE_MASK      ((uint32_t)0x00000800U)         /* !< Set to 1: indicates the EIP 150ap
                                                                                    AHB configuration has zeroize logic
                                                                                    for the PKA RAM */

/* PKA_EIP150_REVISION Bits */
/* PKA_EIP150_REVISION[EIP_NUMBER] Bits */
#define PKA_EIP150_REVISION_EIP_NUMBER_OFS       (0)                             /* !< EIP_NUMBER Offset */
#define PKA_EIP150_REVISION_EIP_NUMBER_MASK      ((uint32_t)0x000000FFU)         /* !< EIP number for the EIP 150ap AHB */
/* PKA_EIP150_REVISION[BIT_BY_BIT_COMPLEMENT_OF_EIP_NUMBER] Bits */
#define PKA_EIP150_REVISION_BIT_BY_BIT_COMPLEMENT_OF_EIP_NUMBER_OFS (8)                             /* !< BIT_BY_BIT_COMPLEMENT_OF_EIP_NUMBER
                                                                                    Offset */
#define PKA_EIP150_REVISION_BIT_BY_BIT_COMPLEMENT_OF_EIP_NUMBER_MASK ((uint32_t)0x0000FF00U)         /* !< These bits simply contain the
                                                                                    complement of bits 7 down to 0 used
                                                                                    by a driver to ascertain that the
                                                                                    EIP150_REVISION register is indeed
                                                                                    read */
/* PKA_EIP150_REVISION[PATCH_LEVEL] Bits */
#define PKA_EIP150_REVISION_PATCH_LEVEL_OFS      (16)                            /* !< PATCH_LEVEL Offset */
#define PKA_EIP150_REVISION_PATCH_LEVEL_MASK     ((uint32_t)0x000F0000U)         /* !< encoding for hardware patch level */
/* PKA_EIP150_REVISION[MINOR_REVISION] Bits */
#define PKA_EIP150_REVISION_MINOR_REVISION_OFS   (20)                            /* !< MINOR_REVISION Offset */
#define PKA_EIP150_REVISION_MINOR_REVISION_MASK  ((uint32_t)0x00F00000U)         /* !< These bits encode the minor version
                                                                                    number for this module */
/* PKA_EIP150_REVISION[MAJOR_REVISION] Bits */
#define PKA_EIP150_REVISION_MAJOR_REVISION_OFS   (24)                            /* !< MAJOR_REVISION Offset */
#define PKA_EIP150_REVISION_MAJOR_REVISION_MASK  ((uint32_t)0x0F000000U)         /* !< These bits encode the major version
                                                                                    number for this module */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_pka__include */

