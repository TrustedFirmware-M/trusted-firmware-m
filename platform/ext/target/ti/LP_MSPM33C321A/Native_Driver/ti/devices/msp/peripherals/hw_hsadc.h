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

#ifndef ti_devices_msp_peripherals_hw_hsadc__include
#define ti_devices_msp_peripherals_hw_hsadc__include

/* Filename: hw_hsadc.h */
/* Revised: 2025-08-26 14:25:21 */
/* Revision: a3c32839a6179063696fb41ed048889ea7fe5cb4 */

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
* HSADC Registers
******************************************************************************/
#define HSADC_ADC_LITE_RESULT_REGS_OFS           ((uint32_t)0x00001000U)
#define HSADC_ADC_LITE_REGS_OFS                  ((uint32_t)0x00001000U)
#define HSADC_GPRCM_OFS                          ((uint32_t)0x00000800U)


/** @addtogroup HSADC_ADC_LITE_RESULT_REGS
  @{
*/

typedef struct {
  __IO uint16_t ADCRESULT0;                        /* !< (@ 0x00001000) ADC Result 0 Register */
  __IO uint16_t ADCRESULT1;                        /* !< (@ 0x00001002) ADC Result 1 Register */
  __IO uint16_t ADCRESULT2;                        /* !< (@ 0x00001004) ADC Result 2 Register */
  __IO uint16_t ADCRESULT3;                        /* !< (@ 0x00001006) ADC Result 3 Register */
  __IO uint16_t ADCRESULT4;                        /* !< (@ 0x00001008) ADC Result 4 Register */
  __IO uint16_t ADCRESULT5;                        /* !< (@ 0x0000100A) ADC Result 5 Register */
  __IO uint16_t ADCRESULT6;                        /* !< (@ 0x0000100C) ADC Result 6 Register */
  __IO uint16_t ADCRESULT7;                        /* !< (@ 0x0000100E) ADC Result 7 Register */
  __IO uint16_t ADCRESULT8;                        /* !< (@ 0x00001010) ADC Result 8 Register */
  __IO uint16_t ADCRESULT9;                        /* !< (@ 0x00001012) ADC Result 9 Register */
  __IO uint16_t ADCRESULT10;                       /* !< (@ 0x00001014) ADC Result 10 Register */
  __IO uint16_t ADCRESULT11;                       /* !< (@ 0x00001016) ADC Result 11 Register */
  __IO uint16_t ADCRESULT12;                       /* !< (@ 0x00001018) ADC Result 12 Register */
  __IO uint16_t ADCRESULT13;                       /* !< (@ 0x0000101A) ADC Result 13 Register */
  __IO uint16_t ADCRESULT14;                       /* !< (@ 0x0000101C) ADC Result 14 Register */
  __IO uint16_t ADCRESULT15;                       /* !< (@ 0x0000101E) ADC Result 15 Register */
       uint32_t RESERVED0[8];
  __IO uint32_t ADCPPB1RESULT;                     /* !< (@ 0x00001040) ADC Post Processing Block 1 Result Register */
  __IO uint32_t ADCPPB2RESULT;                     /* !< (@ 0x00001044) ADC Post Processing Block 2 Result Register */
  __IO uint32_t ADCPPB3RESULT;                     /* !< (@ 0x00001048) ADC Post Processing Block 3 Result Register */
  __IO uint32_t ADCPPB4RESULT;                     /* !< (@ 0x0000104C) ADC Post Processing Block 4 Result Register */
  __IO uint32_t ADCPPB1SUM;                        /* !< (@ 0x00001050) ADC PPB 1 Final Sum Result Register */
  __IO uint16_t ADCPPB1COUNT;                      /* !< (@ 0x00001054) ADC PPB1 Final Conversion Count Register */
       uint16_t RESERVED1;
  __IO uint32_t ADCPPB2SUM;                        /* !< (@ 0x00001058) ADC PPB 2 Final Sum Result Register */
  __IO uint16_t ADCPPB2COUNT;                      /* !< (@ 0x0000105C) ADC PPB2 Final Conversion Count Register */
       uint16_t RESERVED2;
  __IO uint32_t ADCPPB3SUM;                        /* !< (@ 0x00001060) ADC PPB 3 Final Sum Result Register */
  __IO uint16_t ADCPPB3COUNT;                      /* !< (@ 0x00001064) ADC PPB3 Final Conversion Count Register */
       uint16_t RESERVED3;
  __IO uint32_t ADCPPB4SUM;                        /* !< (@ 0x00001068) ADC PPB 4 Final Sum Result Register */
  __IO uint16_t ADCPPB4COUNT;                      /* !< (@ 0x0000106C) ADC PPB4 Final Conversion Count Register */
       uint16_t RESERVED4[41];
  __IO uint32_t ADCSEQ1FIFORESULT;                 /* !< (@ 0x000010C0) ADC Sequence 1 FIFO Result Register */
  __IO uint32_t ADCSEQ2FIFORESULT;                 /* !< (@ 0x000010C4) ADC Sequence 2 FIFO Result Register */
  __IO uint32_t ADCSEQ3FIFORESULT;                 /* !< (@ 0x000010C8) ADC Sequence 3 FIFO Result Register */
  __IO uint32_t ADCSEQ4FIFORESULT;                 /* !< (@ 0x000010CC) ADC Sequence 4 FIFO Result Register */
  __IO uint32_t ADCSEQ1FIFOSTATUS;                 /* !< (@ 0x000010D0) ADC Sequence 1 FIFO Status */
  __IO uint32_t ADCSEQ2FIFOSTATUS;                 /* !< (@ 0x000010D4) ADC Sequence 2 FIFO Status */
  __IO uint32_t ADCSEQ3FIFOSTATUS;                 /* !< (@ 0x000010D8) ADC Sequence 3 FIFO Status */
  __IO uint32_t ADCSEQ4FIFOSTATUS;                 /* !< (@ 0x000010DC) ADC Sequence 4 FIFO Status */
} HSADC_ADC_LITE_RESULT_REGS_Regs;

/*@}*/ /* end of group HSADC_ADC_LITE_RESULT_REGS */

/** @addtogroup hsadc_ADC_LITE_RESULT_REGS
  @{
*/

typedef struct {
       uint32_t RESERVED0[1024];
  HSADC_ADC_LITE_RESULT_REGS_Regs  ADC_LITE_RESULT_REGS;              /* !< (@ 0x00001000) */
} hsadc_ADC_LITE_RESULT_REGS_Regs;

/*@}*/ /* end of group hsadc_ADC_LITE_RESULT_REGS */

/** @addtogroup HSADC_ADC_LITE_REGS
  @{
*/

typedef struct {
  __IO uint32_t ADCCTL1;                           /* !< (@ 0x00001000) ADC Control 1 Register */
  __IO uint32_t ADCCTL2;                           /* !< (@ 0x00001004) ADC Control 2 Register */
       uint32_t RESERVED0;
  __IO uint32_t ADCBURSTCTL;                       /* !< (@ 0x0000100C) ADC Burst Control Register */
  __IO uint32_t ADCINTSEL;                         /* !< (@ 0x00001010) ADC Interrupt 1, 2, 3 and 4 Selection Register */
  __IO uint32_t ADCDMAINTSEL;                      /* !< (@ 0x00001014) ADC DMA Interrupt 1, 2, 3 and 4 Selection Register */
  __IO uint32_t ADCRAWINTFLG;                      /* !< (@ 0x00001018) ADC Raw Interrupt Flag Register */
  __IO uint32_t ADCINTFLG;                         /* !< (@ 0x0000101C) ADC Interrupt Flag Register */
  __IO uint32_t ADCINTFLGFRC;                      /* !< (@ 0x00001020) ADC Interrupt Flag Force Register */
  __IO uint32_t ADCINTFLGCLR;                      /* !< (@ 0x00001024) ADC Interrupt Flag Clear Register */
  __IO uint32_t ADCINTOVF;                         /* !< (@ 0x00001028) ADC Interrupt Overflow Register */
  __IO uint32_t ADCINTOVFCLR;                      /* !< (@ 0x0000102C) ADC Interrupt Overflow Clear Register */
  __IO uint32_t ADCSOCPRICTL;                      /* !< (@ 0x00001030) ADC SOC Priority Control Register */
  __IO uint32_t ADCINTSOCSEL1;                     /* !< (@ 0x00001034) ADC Interrupt SOC Selection 1 Register */
  __IO uint32_t ADCINTSOCSEL2;                     /* !< (@ 0x00001038) ADC Interrupt SOC Selection 2 Register */
  __IO uint32_t ADCSOCFLG1;                        /* !< (@ 0x0000103C) ADC SOC Flag 1 Register */
  __IO uint32_t ADCSOCFRC1;                        /* !< (@ 0x00001040) ADC SOC Force 1 Register */
  __IO uint32_t ADCSOCOVF1;                        /* !< (@ 0x00001044) ADC SOC Overflow 1 Register */
  __IO uint32_t ADCSOCOVFCLR1;                     /* !< (@ 0x00001048) ADC SOC Overflow Clear 1 Register */
  __IO uint32_t ADCSOC0CTL;                        /* !< (@ 0x0000104C) ADC SOC0 Control Register */
  __IO uint32_t ADCSOC1CTL;                        /* !< (@ 0x00001050) ADC SOC1 Control Register */
  __IO uint32_t ADCSOC2CTL;                        /* !< (@ 0x00001054) ADC SOC2 Control Register */
  __IO uint32_t ADCSOC3CTL;                        /* !< (@ 0x00001058) ADC SOC3 Control Register */
  __IO uint32_t ADCSOC4CTL;                        /* !< (@ 0x0000105C) ADC SOC4 Control Register */
  __IO uint32_t ADCSOC5CTL;                        /* !< (@ 0x00001060) ADC SOC5 Control Register */
  __IO uint32_t ADCSOC6CTL;                        /* !< (@ 0x00001064) ADC SOC6 Control Register */
  __IO uint32_t ADCSOC7CTL;                        /* !< (@ 0x00001068) ADC SOC7 Control Register */
  __IO uint32_t ADCSOC8CTL;                        /* !< (@ 0x0000106C) ADC SOC8 Control Register */
  __IO uint32_t ADCSOC9CTL;                        /* !< (@ 0x00001070) ADC SOC9 Control Register */
  __IO uint32_t ADCSOC10CTL;                       /* !< (@ 0x00001074) ADC SOC10 Control Register */
  __IO uint32_t ADCSOC11CTL;                       /* !< (@ 0x00001078) ADC SOC11 Control Register */
  __IO uint32_t ADCSOC12CTL;                       /* !< (@ 0x0000107C) ADC SOC12 Control Register */
  __IO uint32_t ADCSOC13CTL;                       /* !< (@ 0x00001080) ADC SOC13 Control Register */
  __IO uint32_t ADCSOC14CTL;                       /* !< (@ 0x00001084) ADC SOC14 Control Register */
  __IO uint32_t ADCSOC15CTL;                       /* !< (@ 0x00001088) ADC SOC15 Control Register */
       uint32_t RESERVED1[16];
  __IO uint32_t ADCEVTSTAT;                        /* !< (@ 0x000010CC) ADC Event Status Register */
  __IO uint32_t ADCEVTCLR;                         /* !< (@ 0x000010D0) ADC Event Clear Register */
  __IO uint32_t ADCEVTSEL;                         /* !< (@ 0x000010D4) ADC Event Selection Register */
  __IO uint32_t ADCEVTINTSEL;                      /* !< (@ 0x000010D8) ADC Event Interrupt Selection Register */
  __IO uint32_t ADCOSDETECT;                       /* !< (@ 0x000010DC) ADC Open and Shorts Detect Register */
       uint32_t RESERVED2;
  __IO uint32_t ADCREV;                            /* !< (@ 0x000010E4) ADC Revision Register */
  __IO uint32_t ADCOFFTRIM;                        /* !< (@ 0x000010E8) ADC Offset Trim Register 1 */
       uint32_t RESERVED3;
  __IO uint32_t ADCCONFIG;                         /* !< (@ 0x000010F0) ADC Config Register */
       uint32_t RESERVED4[3];
  __IO uint32_t ADCPPB1CONFIG;                     /* !< (@ 0x00001100) ADC PPB1 Config Register */
       uint32_t RESERVED5;
  __IO uint32_t ADCPPB1OFFCAL;                     /* !< (@ 0x00001108) ADC PPB1 Offset Calibration Register */
  __IO uint32_t ADCPPB1OFFREF;                     /* !< (@ 0x0000110C) ADC PPB1 Offset Reference Register */
  __IO uint32_t ADCPPB1TRIPHI;                     /* !< (@ 0x00001110) ADC PPB1 Trip High Register */
  __IO uint32_t ADCPPB1TRIPLO;                     /* !< (@ 0x00001114) ADC PPB1 Trip Low/Trigger Time Stamp Register */
       uint32_t RESERVED6[2];
  __IO uint32_t ADCPPB2CONFIG;                     /* !< (@ 0x00001120) ADC PPB2 Config Register */
       uint32_t RESERVED7;
  __IO uint32_t ADCPPB2OFFCAL;                     /* !< (@ 0x00001128) ADC PPB2 Offset Calibration Register */
  __IO uint32_t ADCPPB2OFFREF;                     /* !< (@ 0x0000112C) ADC PPB2 Offset Reference Register */
  __IO uint32_t ADCPPB2TRIPHI;                     /* !< (@ 0x00001130) ADC PPB2 Trip High Register */
  __IO uint32_t ADCPPB2TRIPLO;                     /* !< (@ 0x00001134) ADC PPB2 Trip Low/Trigger Time Stamp Register */
       uint32_t RESERVED8[2];
  __IO uint32_t ADCPPB3CONFIG;                     /* !< (@ 0x00001140) ADC PPB3 Config Register */
       uint32_t RESERVED9;
  __IO uint32_t ADCPPB3OFFCAL;                     /* !< (@ 0x00001148) ADC PPB3 Offset Calibration Register */
  __IO uint32_t ADCPPB3OFFREF;                     /* !< (@ 0x0000114C) ADC PPB3 Offset Reference Register */
  __IO uint32_t ADCPPB3TRIPHI;                     /* !< (@ 0x00001150) ADC PPB3 Trip High Register */
  __IO uint32_t ADCPPB3TRIPLO;                     /* !< (@ 0x00001154) ADC PPB3 Trip Low/Trigger Time Stamp Register */
       uint32_t RESERVED10[2];
  __IO uint32_t ADCPPB4CONFIG;                     /* !< (@ 0x00001160) ADC PPB4 Config Register */
       uint32_t RESERVED11;
  __IO uint32_t ADCPPB4OFFCAL;                     /* !< (@ 0x00001168) ADC PPB4 Offset Calibration Register */
  __IO uint32_t ADCPPB4OFFREF;                     /* !< (@ 0x0000116C) ADC PPB4 Offset Reference Register */
  __IO uint32_t ADCPPB4TRIPHI;                     /* !< (@ 0x00001170) ADC PPB4 Trip High Register */
  __IO uint32_t ADCPPB4TRIPLO;                     /* !< (@ 0x00001174) ADC PPB4 Trip Low/Trigger Time Stamp Register */
       uint32_t RESERVED12[2];
  __IO uint32_t ADCINTCYCLE;                       /* !< (@ 0x00001180) ADC Early Interrupt Generation Cycle */
  __IO uint32_t ADCINLTRIM1;                       /* !< (@ 0x00001184) ADC Linearity Trim 1 Register */
  __IO uint32_t ADCINLTRIM2;                       /* !< (@ 0x00001188) ADC Linearity Trim 2 Register */
  __IO uint32_t ADCINLTRIM3;                       /* !< (@ 0x0000118C) ADC Linearity Trim 3 Register */
  __IO uint32_t ADCINLTRIM4;                       /* !< (@ 0x00001190) ADC Linearity Trim 4 Register */
  __IO uint32_t ADCINLTRIM5;                       /* !< (@ 0x00001194) ADC Linearity Trim 5 Register */
  __IO uint32_t ADCINLTRIM6;                       /* !< (@ 0x00001198) ADC Linearity Trim 6 Register */
  __IO uint32_t ADCREV2;                           /* !< (@ 0x0000119C) ADC Wrapper Revision Register */
  __IO uint32_t ADCINLTRIMCTL;                     /* !< (@ 0x000011A0) ADC Linearity Trim Control Register */
       uint32_t RESERVED13[7];
  __IO uint32_t REP1CTL;                           /* !< (@ 0x000011C0) ADC Trigger Repeater 1 Control Register */
  __IO uint32_t REP1N;                             /* !< (@ 0x000011C4) ADC Trigger Repeater 1 N Select Register */
       uint32_t RESERVED14[2];
  __IO uint32_t REP1FRC;                           /* !< (@ 0x000011D0) ADC Trigger Repeater 1 Software Force Register */
       uint32_t RESERVED15[3];
  __IO uint32_t REP2CTL;                           /* !< (@ 0x000011E0) ADC Trigger Repeater 2 Control Register */
  __IO uint32_t REP2N;                             /* !< (@ 0x000011E4) ADC Trigger Repeater 2 N Select Register */
       uint32_t RESERVED16[2];
  __IO uint32_t REP2FRC;                           /* !< (@ 0x000011F0) ADC Trigger Repeater 2 Software Force Register */
       uint32_t RESERVED17[3];
  __IO uint32_t ADCPPB1LIMIT;                      /* !< (@ 0x00001200) ADC PPB1Conversion Count Limit Register */
  __IO uint32_t ADCPPB1PCOUNT;                     /* !< (@ 0x00001204) ADC PPB1 Partial Conversion Count Register */
  __IO uint32_t ADCPPB1CONFIG2;                    /* !< (@ 0x00001208) ADC PPB1 Sum Shift Register */
  __IO uint32_t ADCPPB1PSUM;                       /* !< (@ 0x0000120C) ADC PPB1 Partial Sum Register */
       uint32_t RESERVED18[12];
  __IO uint32_t ADCPPB2LIMIT;                      /* !< (@ 0x00001240) ADC PPB2Conversion Count Limit Register */
  __IO uint32_t ADCPPB2PCOUNT;                     /* !< (@ 0x00001244) ADC PPB2 Partial Conversion Count Register */
  __IO uint32_t ADCPPB2CONFIG2;                    /* !< (@ 0x00001248) ADC PPB2 Sum Shift Register */
  __IO uint32_t ADCPPB2PSUM;                       /* !< (@ 0x0000124C) ADC PPB2 Partial Sum Register */
       uint32_t RESERVED19[12];
  __IO uint32_t ADCPPB3LIMIT;                      /* !< (@ 0x00001280) ADC PPB3Conversion Count Limit Register */
  __IO uint32_t ADCPPB3PCOUNT;                     /* !< (@ 0x00001284) ADC PPB3 Partial Conversion Count Register */
  __IO uint32_t ADCPPB3CONFIG2;                    /* !< (@ 0x00001288) ADC PPB3 Sum Shift Register */
  __IO uint32_t ADCPPB3PSUM;                       /* !< (@ 0x0000128C) ADC PPB3 Partial Sum Register */
       uint32_t RESERVED20[12];
  __IO uint32_t ADCPPB4LIMIT;                      /* !< (@ 0x000012C0) ADC PPB4Conversion Count Limit Register */
  __IO uint32_t ADCPPB4PCOUNT;                     /* !< (@ 0x000012C4) ADC PPB4 Partial Conversion Count Register */
  __IO uint32_t ADCPPB4CONFIG2;                    /* !< (@ 0x000012C8) ADC PPB4 Sum Shift Register */
  __IO uint32_t ADCPPB4PSUM;                       /* !< (@ 0x000012CC) ADC PPB4 Partial Sum Register */
       uint32_t RESERVED21[15];
  __IO uint32_t DTB;                               /* !< (@ 0x0000130C) Digital Test Bus */
       uint32_t RESERVED22[4];
  __IO uint32_t ADCSEQCTL;                         /* !< (@ 0x00001320) ADC Sequencer common control Register */
  __IO uint32_t ADCSEQ1CONFIG;                     /* !< (@ 0x00001324) ADC Sequencer 1 Config register */
  __IO uint32_t ADCSEQ2CONFIG;                     /* !< (@ 0x00001328) ADC Sequencer 2 Config register */
  __IO uint32_t ADCSEQ3CONFIG;                     /* !< (@ 0x0000132C) ADC Sequencer 3 Config register */
  __IO uint32_t ADCSEQ4CONFIG;                     /* !< (@ 0x00001330) ADC Sequencer 4 Config register */
} HSADC_ADC_LITE_REGS_Regs;

/*@}*/ /* end of group HSADC_ADC_LITE_REGS */

/** @addtogroup HSADC_GPRCM
  @{
*/

typedef struct {
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED0[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
} HSADC_GPRCM_Regs;

/*@}*/ /* end of group HSADC_GPRCM */

/** @addtogroup hsadc_ADC_LITE_REGS
  @{
*/

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;                            /* !< (@ 0x00000400) Subscriber Port 0 */
  __IO uint32_t FSUB_1;                            /* !< (@ 0x00000404) Subscriber Port 1 */
  __IO uint32_t FSUB_2;                            /* !< (@ 0x00000408) Subscriber Port 2 */
  __IO uint32_t FSUB_3;                            /* !< (@ 0x0000040C) Subscriber Port 3 */
       uint32_t RESERVED1[13];
  __IO uint32_t FPUB_0;                            /* !< (@ 0x00000444) Publisher port 0 */
  __IO uint32_t FPUB_1;                            /* !< (@ 0x00000448) Publisher port 1 */
  __IO uint32_t FPUB_2;                            /* !< (@ 0x0000044C) Publisher port 2 */
  __IO uint32_t FPUB_3;                            /* !< (@ 0x00000450) Publisher port 3 */
       uint32_t RESERVED2[235];
  HSADC_GPRCM_Regs  GPRCM;                             /* !< (@ 0x00000800) */
       uint32_t RESERVED3[506];
  HSADC_ADC_LITE_REGS_Regs  ADC_LITE_REGS;                     /* !< (@ 0x00001000) */
} hsadc_ADC_LITE_REGS_Regs;

/*@}*/ /* end of group hsadc_ADC_LITE_REGS */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* HSADC Register Control Bits
******************************************************************************/

/* HSADC_ADCRESULT0 Bits */
/* HSADC_ADCRESULT0[RESULT] Bits */
#define HSADC_ADCRESULT0_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT0_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 0 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC0, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT1 Bits */
/* HSADC_ADCRESULT1[RESULT] Bits */
#define HSADC_ADCRESULT1_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT1_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 1 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC1, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT2 Bits */
/* HSADC_ADCRESULT2[RESULT] Bits */
#define HSADC_ADCRESULT2_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT2_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 2 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC2, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT3 Bits */
/* HSADC_ADCRESULT3[RESULT] Bits */
#define HSADC_ADCRESULT3_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT3_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 3 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC3, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT4 Bits */
/* HSADC_ADCRESULT4[RESULT] Bits */
#define HSADC_ADCRESULT4_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT4_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 4 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC4, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT5 Bits */
/* HSADC_ADCRESULT5[RESULT] Bits */
#define HSADC_ADCRESULT5_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT5_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 5 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC5, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT6 Bits */
/* HSADC_ADCRESULT6[RESULT] Bits */
#define HSADC_ADCRESULT6_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT6_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 6 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC6, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT7 Bits */
/* HSADC_ADCRESULT7[RESULT] Bits */
#define HSADC_ADCRESULT7_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT7_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 7 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC7, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT8 Bits */
/* HSADC_ADCRESULT8[RESULT] Bits */
#define HSADC_ADCRESULT8_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT8_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 8 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC8, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT9 Bits */
/* HSADC_ADCRESULT9[RESULT] Bits */
#define HSADC_ADCRESULT9_RESULT_OFS              (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT9_RESULT_MASK             ((uint16_t)0x0000FFFFU)         /* !< ADC Result 9 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC9, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT10 Bits */
/* HSADC_ADCRESULT10[RESULT] Bits */
#define HSADC_ADCRESULT10_RESULT_OFS             (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT10_RESULT_MASK            ((uint16_t)0x0000FFFFU)         /* !< ADC Result 10 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC10, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT11 Bits */
/* HSADC_ADCRESULT11[RESULT] Bits */
#define HSADC_ADCRESULT11_RESULT_OFS             (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT11_RESULT_MASK            ((uint16_t)0x0000FFFFU)         /* !< ADC Result 11 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC11, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT12 Bits */
/* HSADC_ADCRESULT12[RESULT] Bits */
#define HSADC_ADCRESULT12_RESULT_OFS             (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT12_RESULT_MASK            ((uint16_t)0x0000FFFFU)         /* !< ADC Result 12 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC12, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT13 Bits */
/* HSADC_ADCRESULT13[RESULT] Bits */
#define HSADC_ADCRESULT13_RESULT_OFS             (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT13_RESULT_MASK            ((uint16_t)0x0000FFFFU)         /* !< ADC Result 13 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC13, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT14 Bits */
/* HSADC_ADCRESULT14[RESULT] Bits */
#define HSADC_ADCRESULT14_RESULT_OFS             (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT14_RESULT_MASK            ((uint16_t)0x0000FFFFU)         /* !< ADC Result 14 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC14, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCRESULT15 Bits */
/* HSADC_ADCRESULT15[RESULT] Bits */
#define HSADC_ADCRESULT15_RESULT_OFS             (0)                             /* !< RESULT Offset */
#define HSADC_ADCRESULT15_RESULT_MASK            ((uint16_t)0x0000FFFFU)         /* !< ADC Result 15 #br# #br#12-bit ADC
                                                                                    result. After the ADC completes a
                                                                                    conversion of SOC15, the digital
                                                                                    result is placed in this bit field.
                                                                                    #br#If oversampling is enabled, Final
                                                                                    SUM (After any Shift if enabled) will
                                                                                    be stored in this register after
                                                                                    completing the specified number of
                                                                                    samples. */

/* HSADC_ADCPPB1RESULT Bits */
/* HSADC_ADCPPB1RESULT[PPBRESULT] Bits */
#define HSADC_ADCPPB1RESULT_PPBRESULT_OFS        (0)                             /* !< PPBRESULT Offset */
#define HSADC_ADCPPB1RESULT_PPBRESULT_MASK       ((uint32_t)0x00001FFFU)         /* !< ADC Post Processing Block Result 1
                                                                                    #br# #br#The result of the
                                                                                    offset/reference subtraction post
                                                                                    conversion processing is stored in
                                                                                    this register.  #br# #br#This result
                                                                                    is available 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT is available,
                                                                                    unless multiple PPBs point to the
                                                                                    same SOC.  In the case of multiple
                                                                                    PPBs associated with the same SOC,
                                                                                    the lowest numbered PPB's result will
                                                                                    be availble 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT and subsequent
                                                                                    results (in order from lowest
                                                                                    numbered PPB to highest) will each
                                                                                    become available every 2-3 SYSCLK
                                                                                    cycles (refer to the TRM for more
                                                                                    detailed timing information).  #br#
                                                                                    #br#If ADCINTFLG is polled to
                                                                                    determine when to read the PPBRESULT,
                                                                                    it may be necessary to add one or
                                                                                    more NOP instructions to ensure that
                                                                                    the updated post conversion
                                                                                    processing result has posted to the
                                                                                    register. #br# #br#NOTE: If the
                                                                                    conversion associated with this Post
                                                                                    Processing Block is a 12-bit
                                                                                    conversion, the PPBRESULT bits are
                                                                                    limited to bits 12:0. */
/* HSADC_ADCPPB1RESULT[SIGN] Bits */
#define HSADC_ADCPPB1RESULT_SIGN_OFS             (13)                            /* !< SIGN Offset */
#define HSADC_ADCPPB1RESULT_SIGN_MASK            ((uint32_t)0xFFFFE000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 12.
                                                                                    #br# #br#NOTE: If the conversion
                                                                                    associated with this Post Processing
                                                                                    Block is a 12-bit conversion, the
                                                                                    SIGN bits extend down to bit 12, and
                                                                                    all reflect the same value as bit 12. */

/* HSADC_ADCPPB2RESULT Bits */
/* HSADC_ADCPPB2RESULT[PPBRESULT] Bits */
#define HSADC_ADCPPB2RESULT_PPBRESULT_OFS        (0)                             /* !< PPBRESULT Offset */
#define HSADC_ADCPPB2RESULT_PPBRESULT_MASK       ((uint32_t)0x00001FFFU)         /* !< ADC Post Processing Block Result 2
                                                                                    #br# #br#The result of the
                                                                                    offset/reference subtraction post
                                                                                    conversion processing is stored in
                                                                                    this register.  #br# #br#This result
                                                                                    is available 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT is available,
                                                                                    unless multiple PPBs point to the
                                                                                    same SOC.  In the case of multiple
                                                                                    PPBs associated with the same SOC,
                                                                                    the lowest numbered PPB's result will
                                                                                    be availble 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT and subsequent
                                                                                    results (in order from lowest
                                                                                    numbered PPB to highest) will each
                                                                                    become available every 2-3 SYSCLK
                                                                                    cycles (refer to the TRM for more
                                                                                    detailed timing information).  #br#
                                                                                    #br#If ADCINTFLG is polled to
                                                                                    determine when to read the PPBRESULT,
                                                                                    it may be necessary to add one or
                                                                                    more NOP instructions to ensure that
                                                                                    the updated post conversion
                                                                                    processing result has posted to the
                                                                                    register. #br# #br#NOTE: If the
                                                                                    conversion associated with this Post
                                                                                    Processing Block is a 12-bit
                                                                                    conversion, the PPBRESULT bits are
                                                                                    limited to bits 12:0. */
/* HSADC_ADCPPB2RESULT[SIGN] Bits */
#define HSADC_ADCPPB2RESULT_SIGN_OFS             (13)                            /* !< SIGN Offset */
#define HSADC_ADCPPB2RESULT_SIGN_MASK            ((uint32_t)0xFFFFE000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 12.
                                                                                    #br# #br#NOTE: If the conversion
                                                                                    associated with this Post Processing
                                                                                    Block is a 12-bit conversion, the
                                                                                    SIGN bits extend down to bit 12, and
                                                                                    all reflect the same value as bit 12. */

/* HSADC_ADCPPB3RESULT Bits */
/* HSADC_ADCPPB3RESULT[PPBRESULT] Bits */
#define HSADC_ADCPPB3RESULT_PPBRESULT_OFS        (0)                             /* !< PPBRESULT Offset */
#define HSADC_ADCPPB3RESULT_PPBRESULT_MASK       ((uint32_t)0x00001FFFU)         /* !< ADC Post Processing Block Result 3
                                                                                    #br# #br#The result of the
                                                                                    offset/reference subtraction post
                                                                                    conversion processing is stored in
                                                                                    this register.  #br# #br#This result
                                                                                    is available 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT is available,
                                                                                    unless multiple PPBs point to the
                                                                                    same SOC.  In the case of multiple
                                                                                    PPBs associated with the same SOC,
                                                                                    the lowest numbered PPB's result will
                                                                                    be availble 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT and subsequent
                                                                                    results (in order from lowest
                                                                                    numbered PPB to highest) will each
                                                                                    become available every 2-3 SYSCLK
                                                                                    cycles (refer to the TRM for more
                                                                                    detailed timing information).  #br#
                                                                                    #br#If ADCINTFLG is polled to
                                                                                    determine when to read the PPBRESULT,
                                                                                    it may be necessary to add one or
                                                                                    more NOP instructions to ensure that
                                                                                    the updated post conversion
                                                                                    processing result has posted to the
                                                                                    register. #br# #br#NOTE: If the
                                                                                    conversion associated with this Post
                                                                                    Processing Block is a 12-bit
                                                                                    conversion, the PPBRESULT bits are
                                                                                    limited to bits 12:0. */
/* HSADC_ADCPPB3RESULT[SIGN] Bits */
#define HSADC_ADCPPB3RESULT_SIGN_OFS             (13)                            /* !< SIGN Offset */
#define HSADC_ADCPPB3RESULT_SIGN_MASK            ((uint32_t)0xFFFFE000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 12.
                                                                                    #br# #br#NOTE: If the conversion
                                                                                    associated with this Post Processing
                                                                                    Block is a 12-bit conversion, the
                                                                                    SIGN bits extend down to bit 12, and
                                                                                    all reflect the same value as bit 12. */

/* HSADC_ADCPPB4RESULT Bits */
/* HSADC_ADCPPB4RESULT[PPBRESULT] Bits */
#define HSADC_ADCPPB4RESULT_PPBRESULT_OFS        (0)                             /* !< PPBRESULT Offset */
#define HSADC_ADCPPB4RESULT_PPBRESULT_MASK       ((uint32_t)0x00001FFFU)         /* !< ADC Post Processing Block Result 4
                                                                                    #br# #br#The result of the
                                                                                    offset/reference subtraction post
                                                                                    conversion processing is stored in
                                                                                    this register.  #br# #br#This result
                                                                                    is available 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT is available,
                                                                                    unless multiple PPBs point to the
                                                                                    same SOC.  In the case of multiple
                                                                                    PPBs associated with the same SOC,
                                                                                    the lowest numbered PPB's result will
                                                                                    be availble 1 SYSCLK cycle after the
                                                                                    associated ADCRESULT and subsequent
                                                                                    results (in order from lowest
                                                                                    numbered PPB to highest) will each
                                                                                    become available every 2-3 SYSCLK
                                                                                    cycles (refer to the TRM for more
                                                                                    detailed timing information).  #br#
                                                                                    #br#If ADCINTFLG is polled to
                                                                                    determine when to read the PPBRESULT,
                                                                                    it may be necessary to add one or
                                                                                    more NOP instructions to ensure that
                                                                                    the updated post conversion
                                                                                    processing result has posted to the
                                                                                    register. #br# #br#NOTE: If the
                                                                                    conversion associated with this Post
                                                                                    Processing Block is a 12-bit
                                                                                    conversion, the PPBRESULT bits are
                                                                                    limited to bits 12:0. */
/* HSADC_ADCPPB4RESULT[SIGN] Bits */
#define HSADC_ADCPPB4RESULT_SIGN_OFS             (13)                            /* !< SIGN Offset */
#define HSADC_ADCPPB4RESULT_SIGN_MASK            ((uint32_t)0xFFFFE000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 12.
                                                                                    #br# #br#NOTE: If the conversion
                                                                                    associated with this Post Processing
                                                                                    Block is a 12-bit conversion, the
                                                                                    SIGN bits extend down to bit 12, and
                                                                                    all reflect the same value as bit 12. */

/* HSADC_ADCPPB1SUM Bits */
/* HSADC_ADCPPB1SUM[SUM] Bits */
#define HSADC_ADCPPB1SUM_SUM_OFS                 (0)                             /* !< SUM Offset */
#define HSADC_ADCPPB1SUM_SUM_MASK                ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 1
                                                                                    Oversampling Final Sum. When either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB1 receives a sync.
                                                                                    event, the value of PSUM is loaded
                                                                                    into this register.  In the case of a
                                                                                    count-match event, the sum loaded
                                                                                    into this register includes the value
                                                                                    from the most recent conversion.
                                                                                    #br# #br#The value from PSUM will be
                                                                                    right shifted by the amount specified
                                                                                    in the SHIFT register before being
                                                                                    loaded into the final SUM result
                                                                                    register. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB1RESULT is available
                                                                                    (only in case of a count-match
                                                                                    event). This will be 2 SYSCLK cycles
                                                                                    after the associated ADCRESULT is
                                                                                    available, unless multiple PPBs point
                                                                                    to the same SOC (refer to the
                                                                                    ADCPPB1RESULT timing information). */
/* HSADC_ADCPPB1SUM[SIGN] Bits */
#define HSADC_ADCPPB1SUM_SIGN_OFS                (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB1SUM_SIGN_MASK               ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_ADCPPB1COUNT Bits */
/* HSADC_ADCPPB1COUNT[COUNT] Bits */
#define HSADC_ADCPPB1COUNT_COUNT_OFS             (0)                             /* !< COUNT Offset */
#define HSADC_ADCPPB1COUNT_COUNT_MASK            ((uint16_t)0x0000000FU)         /* !< Post Processing Block 1
                                                                                    Oversampling Final Count. When either
                                                                                    a count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB1 receives a sync.
                                                                                    event, the value of PCOUNT is loaded
                                                                                    into this register. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB1RESULT is
                                                                                    available (only in case of a
                                                                                    count-match event). This will be 2
                                                                                    SYSCLK cycles after the associated
                                                                                    ADCRESULT is available, unless
                                                                                    multiple PPBs point to the same SOC
                                                                                    (refer to the ADCPPB1RESULT timing
                                                                                    information). */

/* HSADC_ADCPPB2SUM Bits */
/* HSADC_ADCPPB2SUM[SUM] Bits */
#define HSADC_ADCPPB2SUM_SUM_OFS                 (0)                             /* !< SUM Offset */
#define HSADC_ADCPPB2SUM_SUM_MASK                ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 2
                                                                                    Oversampling Final Sum. When either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB2 receives a sync.
                                                                                    event, the value of PSUM is loaded
                                                                                    into this register.  In the case of a
                                                                                    count-match event, the sum loaded
                                                                                    into this register includes the value
                                                                                    from the most recent conversion.
                                                                                    #br# #br#The value from PSUM will be
                                                                                    right shifted by the amount specified
                                                                                    in the SHIFT register before being
                                                                                    loaded into the final SUM result
                                                                                    register. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB2RESULT is available
                                                                                    (only in case of a count-match
                                                                                    event). This will be 2 SYSCLK cycles
                                                                                    after the associated ADCRESULT is
                                                                                    available, unless multiple PPBs point
                                                                                    to the same SOC (refer to the
                                                                                    ADCPPB2RESULT timing information). */
/* HSADC_ADCPPB2SUM[SIGN] Bits */
#define HSADC_ADCPPB2SUM_SIGN_OFS                (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB2SUM_SIGN_MASK               ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_ADCPPB2COUNT Bits */
/* HSADC_ADCPPB2COUNT[COUNT] Bits */
#define HSADC_ADCPPB2COUNT_COUNT_OFS             (0)                             /* !< COUNT Offset */
#define HSADC_ADCPPB2COUNT_COUNT_MASK            ((uint16_t)0x0000000FU)         /* !< Post Processing Block 2
                                                                                    Oversampling Final Count. When either
                                                                                    a count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB2 receives a sync.
                                                                                    event, the value of PCOUNT is loaded
                                                                                    into this register. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB2RESULT is
                                                                                    available (only in case of a
                                                                                    count-match event). This will be 2
                                                                                    SYSCLK cycles after the associated
                                                                                    ADCRESULT is available, unless
                                                                                    multiple PPBs point to the same SOC
                                                                                    (refer to the ADCPPB2RESULT timing
                                                                                    information). */

/* HSADC_ADCPPB3SUM Bits */
/* HSADC_ADCPPB3SUM[SUM] Bits */
#define HSADC_ADCPPB3SUM_SUM_OFS                 (0)                             /* !< SUM Offset */
#define HSADC_ADCPPB3SUM_SUM_MASK                ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 3
                                                                                    Oversampling Final Sum. When either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB3 receives a sync.
                                                                                    event, the value of PSUM is loaded
                                                                                    into this register.  In the case of a
                                                                                    count-match event, the sum loaded
                                                                                    into this register includes the value
                                                                                    from the most recent conversion.
                                                                                    #br# #br#The value from PSUM will be
                                                                                    right shifted by the amount specified
                                                                                    in the SHIFT register before being
                                                                                    loaded into the final SUM result
                                                                                    register. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB3RESULT is available
                                                                                    (only in case of a count-match
                                                                                    event). This will be 2 SYSCLK cycles
                                                                                    after the associated ADCRESULT is
                                                                                    available, unless multiple PPBs point
                                                                                    to the same SOC (refer to the
                                                                                    ADCPPB3RESULT timing information). */
/* HSADC_ADCPPB3SUM[SIGN] Bits */
#define HSADC_ADCPPB3SUM_SIGN_OFS                (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB3SUM_SIGN_MASK               ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_ADCPPB3COUNT Bits */
/* HSADC_ADCPPB3COUNT[COUNT] Bits */
#define HSADC_ADCPPB3COUNT_COUNT_OFS             (0)                             /* !< COUNT Offset */
#define HSADC_ADCPPB3COUNT_COUNT_MASK            ((uint16_t)0x0000000FU)         /* !< Post Processing Block 3
                                                                                    Oversampling Final Count. When either
                                                                                    a count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB3 receives a sync.
                                                                                    event, the value of PCOUNT is loaded
                                                                                    into this register. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB3RESULT is
                                                                                    available (only in case of a
                                                                                    count-match event). This will be 2
                                                                                    SYSCLK cycles after the associated
                                                                                    ADCRESULT is available, unless
                                                                                    multiple PPBs point to the same SOC
                                                                                    (refer to the ADCPPB3RESULT timing
                                                                                    information). */

/* HSADC_ADCPPB4SUM Bits */
/* HSADC_ADCPPB4SUM[SUM] Bits */
#define HSADC_ADCPPB4SUM_SUM_OFS                 (0)                             /* !< SUM Offset */
#define HSADC_ADCPPB4SUM_SUM_MASK                ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 4
                                                                                    Oversampling Final Sum. When either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB4 receives a sync.
                                                                                    event, the value of PSUM is loaded
                                                                                    into this register.  In the case of a
                                                                                    count-match event, the sum loaded
                                                                                    into this register includes the value
                                                                                    from the most recent conversion.
                                                                                    #br# #br#The value from PSUM will be
                                                                                    right shifted by the amount specified
                                                                                    in the SHIFT register before being
                                                                                    loaded into the final SUM result
                                                                                    register. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB4RESULT is available
                                                                                    (only in case of a count-match
                                                                                    event). This will be 2 SYSCLK cycles
                                                                                    after the associated ADCRESULT is
                                                                                    available, unless multiple PPBs point
                                                                                    to the same SOC (refer to the
                                                                                    ADCPPB4RESULT timing information). */
/* HSADC_ADCPPB4SUM[SIGN] Bits */
#define HSADC_ADCPPB4SUM_SIGN_OFS                (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB4SUM_SIGN_MASK               ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_ADCPPB4COUNT Bits */
/* HSADC_ADCPPB4COUNT[COUNT] Bits */
#define HSADC_ADCPPB4COUNT_COUNT_OFS             (0)                             /* !< COUNT Offset */
#define HSADC_ADCPPB4COUNT_COUNT_MASK            ((uint16_t)0x0000000FU)         /* !< Post Processing Block 4
                                                                                    Oversampling Final Count. When either
                                                                                    a count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB4 receives a sync.
                                                                                    event, the value of PCOUNT is loaded
                                                                                    into this register. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB4RESULT is
                                                                                    available (only in case of a
                                                                                    count-match event). This will be 2
                                                                                    SYSCLK cycles after the associated
                                                                                    ADCRESULT is available, unless
                                                                                    multiple PPBs point to the same SOC
                                                                                    (refer to the ADCPPB4RESULT timing
                                                                                    information). */

/* HSADC_ADCSEQ1FIFORESULT Bits */
/* HSADC_ADCSEQ1FIFORESULT[SEQFIFORESULT] Bits */
#define HSADC_ADCSEQ1FIFORESULT_SEQFIFORESULT_OFS (0)                             /* !< SEQFIFORESULT Offset */
#define HSADC_ADCSEQ1FIFORESULT_SEQFIFORESULT_MASK ((uint32_t)0xFFFFFFFFU)         /* !< Sequencer 1 Result in FIFO mode */

/* HSADC_ADCSEQ2FIFORESULT Bits */
/* HSADC_ADCSEQ2FIFORESULT[SEQFIFORESULT] Bits */
#define HSADC_ADCSEQ2FIFORESULT_SEQFIFORESULT_OFS (0)                             /* !< SEQFIFORESULT Offset */
#define HSADC_ADCSEQ2FIFORESULT_SEQFIFORESULT_MASK ((uint32_t)0xFFFFFFFFU)         /* !< Sequencer 2 Result in FIFO mode */

/* HSADC_ADCSEQ3FIFORESULT Bits */
/* HSADC_ADCSEQ3FIFORESULT[SEQFIFORESULT] Bits */
#define HSADC_ADCSEQ3FIFORESULT_SEQFIFORESULT_OFS (0)                             /* !< SEQFIFORESULT Offset */
#define HSADC_ADCSEQ3FIFORESULT_SEQFIFORESULT_MASK ((uint32_t)0xFFFFFFFFU)         /* !< Sequencer 3 Result in FIFO mode */

/* HSADC_ADCSEQ4FIFORESULT Bits */
/* HSADC_ADCSEQ4FIFORESULT[SEQFIFORESULT] Bits */
#define HSADC_ADCSEQ4FIFORESULT_SEQFIFORESULT_OFS (0)                             /* !< SEQFIFORESULT Offset */
#define HSADC_ADCSEQ4FIFORESULT_SEQFIFORESULT_MASK ((uint32_t)0xFFFFFFFFU)         /* !< Sequencer 4 Result in FIFO mode */

/* HSADC_ADCSEQ1FIFOSTATUS Bits */
/* HSADC_ADCSEQ1FIFOSTATUS[SEQFIFOVALID] Bits */
#define HSADC_ADCSEQ1FIFOSTATUS_SEQFIFOVALID_OFS (0)                             /* !< SEQFIFOVALID Offset */
#define HSADC_ADCSEQ1FIFOSTATUS_SEQFIFOVALID_MASK ((uint32_t)0x00000001U)         /* !< Sequencer 1 FIFO Valid #br#0 -  All
                                                                                    Conversions associated with the
                                                                                    current Sequencer are NOT complete.
                                                                                    #br#1 - Conversion from all the SOCs
                                                                                    associated with the Sequencer are
                                                                                    complete and result is available to
                                                                                    be read. */
/* HSADC_ADCSEQ1FIFOSTATUS[SEQFIFOPENDREAD] Bits */
#define HSADC_ADCSEQ1FIFOSTATUS_SEQFIFOPENDREAD_OFS (1)                             /* !< SEQFIFOPENDREAD Offset */
#define HSADC_ADCSEQ1FIFOSTATUS_SEQFIFOPENDREAD_MASK ((uint32_t)0x0000001EU)         /* !< Sequencer 1 FIFO pending reads
                                                                                    #br#Note:  #br#1. This field is only
                                                                                    updated when after the last byte of
                                                                                    ADCSEQ1FIFORESULT is read. #br#2. The
                                                                                    Pending read information will not be
                                                                                    updated for debug reads.  #br#3. Once
                                                                                    all the data in the FIFO has been
                                                                                    read, FIFO will wrap back. Subsequent
                                                                                    reads will read from the beginning of
                                                                                    the FIFO. */

/* HSADC_ADCSEQ2FIFOSTATUS Bits */
/* HSADC_ADCSEQ2FIFOSTATUS[SEQFIFOVALID] Bits */
#define HSADC_ADCSEQ2FIFOSTATUS_SEQFIFOVALID_OFS (0)                             /* !< SEQFIFOVALID Offset */
#define HSADC_ADCSEQ2FIFOSTATUS_SEQFIFOVALID_MASK ((uint32_t)0x00000001U)         /* !< Sequencer 2 FIFO Valid #br#0 -  All
                                                                                    Conversions associated with the
                                                                                    current Sequencer are NOT complete.
                                                                                    #br#1 - Conversion from all the SOCs
                                                                                    associated with the Sequencer are
                                                                                    complete and result is available to
                                                                                    be read. */
/* HSADC_ADCSEQ2FIFOSTATUS[SEQFIFOPENDREAD] Bits */
#define HSADC_ADCSEQ2FIFOSTATUS_SEQFIFOPENDREAD_OFS (1)                             /* !< SEQFIFOPENDREAD Offset */
#define HSADC_ADCSEQ2FIFOSTATUS_SEQFIFOPENDREAD_MASK ((uint32_t)0x0000001EU)         /* !< Sequencer 2 FIFO pending reads
                                                                                    #br#Note:  #br#1. This field is only
                                                                                    updated when after the last byte of
                                                                                    ADCSEQ2FIFORESULT is read. #br#2. The
                                                                                    Pending read information will not be
                                                                                    updated for debug reads.  #br#3. Once
                                                                                    all the data in the FIFO has been
                                                                                    read, FIFO will wrap back. Subsequent
                                                                                    reads will read from the beginning of
                                                                                    the FIFO. */

/* HSADC_ADCSEQ3FIFOSTATUS Bits */
/* HSADC_ADCSEQ3FIFOSTATUS[SEQFIFOVALID] Bits */
#define HSADC_ADCSEQ3FIFOSTATUS_SEQFIFOVALID_OFS (0)                             /* !< SEQFIFOVALID Offset */
#define HSADC_ADCSEQ3FIFOSTATUS_SEQFIFOVALID_MASK ((uint32_t)0x00000001U)         /* !< Sequencer 3 FIFO Valid #br#0 -  All
                                                                                    Conversions associated with the
                                                                                    current Sequencer are NOT complete.
                                                                                    #br#1 - Conversion from all the SOCs
                                                                                    associated with the Sequencer are
                                                                                    complete and result is available to
                                                                                    be read. */
/* HSADC_ADCSEQ3FIFOSTATUS[SEQFIFOPENDREAD] Bits */
#define HSADC_ADCSEQ3FIFOSTATUS_SEQFIFOPENDREAD_OFS (1)                             /* !< SEQFIFOPENDREAD Offset */
#define HSADC_ADCSEQ3FIFOSTATUS_SEQFIFOPENDREAD_MASK ((uint32_t)0x0000001EU)         /* !< Sequencer 3 FIFO pending reads
                                                                                    #br#Note:  #br#1. This field is only
                                                                                    updated when after the last byte of
                                                                                    ADCSEQ3FIFORESULT is read. #br#2. The
                                                                                    Pending read information will not be
                                                                                    updated for debug reads.  #br#3. Once
                                                                                    all the data in the FIFO has been
                                                                                    read, FIFO will wrap back. Subsequent
                                                                                    reads will read from the beginning of
                                                                                    the FIFO. */

/* HSADC_ADCSEQ4FIFOSTATUS Bits */
/* HSADC_ADCSEQ4FIFOSTATUS[SEQFIFOVALID] Bits */
#define HSADC_ADCSEQ4FIFOSTATUS_SEQFIFOVALID_OFS (0)                             /* !< SEQFIFOVALID Offset */
#define HSADC_ADCSEQ4FIFOSTATUS_SEQFIFOVALID_MASK ((uint32_t)0x00000001U)         /* !< Sequencer 4 FIFO Valid #br#0 -  All
                                                                                    Conversions associated with the
                                                                                    current Sequencer are NOT complete.
                                                                                    #br#1 - Conversion from all the SOCs
                                                                                    associated with the Sequencer are
                                                                                    complete and result is available to
                                                                                    be read. */
/* HSADC_ADCSEQ4FIFOSTATUS[SEQFIFOPENDREAD] Bits */
#define HSADC_ADCSEQ4FIFOSTATUS_SEQFIFOPENDREAD_OFS (1)                             /* !< SEQFIFOPENDREAD Offset */
#define HSADC_ADCSEQ4FIFOSTATUS_SEQFIFOPENDREAD_MASK ((uint32_t)0x0000001EU)         /* !< Sequencer 4 FIFO pending reads
                                                                                    #br#Note:  #br#1. This field is only
                                                                                    updated when after the last byte of
                                                                                    ADCSEQ4FIFORESULT is read. #br#2. The
                                                                                    Pending read information will not be
                                                                                    updated for debug reads.  #br#3. Once
                                                                                    all the data in the FIFO has been
                                                                                    read, FIFO will wrap back. Subsequent
                                                                                    reads will read from the beginning of
                                                                                    the FIFO. */

/* HSADC_ADCCTL1 Bits */
/* HSADC_ADCCTL1[INTPULSEPOS] Bits */
#define HSADC_ADCCTL1_INTPULSEPOS_OFS            (2)                             /* !< INTPULSEPOS Offset */
#define HSADC_ADCCTL1_INTPULSEPOS_MASK           ((uint32_t)0x00000004U)         /* !< ADC Interrupt Pulse Position. #br#
                                                                                    #br#  0  Interrupt  pulse generation
                                                                                    occurs when ADC begins conversion (at
                                                                                    the end of the acquisition window)
                                                                                    plus a number of SYSCLK cycles as
                                                                                    specified in the ADCINTCYCLE.OFFSET
                                                                                    register. #br#  1  Interrupt pulse
                                                                                    generation occurs at the end of the
                                                                                    conversion, 1 cycle prior to the ADC
                                                                                    result latching into its result
                                                                                    register */
/* HSADC_ADCCTL1[ADCPWDNZ] Bits */
#define HSADC_ADCCTL1_ADCPWDNZ_OFS               (7)                             /* !< ADCPWDNZ Offset */
#define HSADC_ADCCTL1_ADCPWDNZ_MASK              ((uint32_t)0x00000080U)         /* !< ADC Power Down (active low). This
                                                                                    bit controls the power up and power
                                                                                    down of all the analog circuitry
                                                                                    inside the analog core. #br# #br#  0
                                                                                    All analog circuitry inside the core
                                                                                    is powered down #br#  1  All analog
                                                                                    circuitry inside the core is powered
                                                                                    up */
/* HSADC_ADCCTL1[ADCBSYCHN] Bits */
#define HSADC_ADCCTL1_ADCBSYCHN_OFS              (8)                             /* !< ADCBSYCHN Offset */
#define HSADC_ADCCTL1_ADCBSYCHN_MASK             ((uint32_t)0x00000F00U)         /* !< ADC Busy Channel. Set when an ADC
                                                                                    Start of Conversion (SOC) is
                                                                                    generated. #br#When ADCBSY=0: holds
                                                                                    the value of the last converted SOC
                                                                                    #br#When ADCBSY=1: reflects the SOC
                                                                                    currently being processed #br#  0h
                                                                                    SOC0 is currently processing or was
                                                                                    last SOC converted #br#  1h  SOC1 is
                                                                                    currently processing or was last SOC
                                                                                    converted #br#  2h  SOC2 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  3h  SOC3 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  4h  SOC4 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  5h  SOC5 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  6h  SOC6 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  7h  SOC7 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  8h  SOC8 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  9h  SOC9 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  Ah  SOC10 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  Bh  SOC11 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  Ch  SOC12 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  Dh  SOC13 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  Eh  SOC14 is currently
                                                                                    processing or was last SOC converted
                                                                                    #br#  Fh  SOC15 is currently
                                                                                    processing or was last SOC converted */
/* HSADC_ADCCTL1[ADCBSY] Bits */
#define HSADC_ADCCTL1_ADCBSY_OFS                 (13)                            /* !< ADCBSY Offset */
#define HSADC_ADCCTL1_ADCBSY_MASK                ((uint32_t)0x00002000U)         /* !< ADC Busy. Set when ADC SOC is
                                                                                    generated, cleared by hardware four
                                                                                    ADC clocks after negative edge of S/H
                                                                                    pulse. Used by the ADC state machine
                                                                                    to determine if ADC is available to
                                                                                    sample. #br# #br#  0  ADC is
                                                                                    available to sample next channel #br#
                                                                                    1  ADC is busy and cannot sample
                                                                                    another channel */

/* HSADC_ADCCTL2 Bits */
/* HSADC_ADCCTL2[PRESCALE] Bits */
#define HSADC_ADCCTL2_PRESCALE_OFS               (0)                             /* !< PRESCALE Offset */
#define HSADC_ADCCTL2_PRESCALE_MASK              ((uint32_t)0x0000000FU)         /* !< ADC Clock Prescaler. #br#  0000
                                                                                    ADCCLK = Input Clock / 1.0 #br#  0001
                                                                                    ADCCLK = Input Clock / 1.5 #br#
                                                                                    0010  ADCCLK = Input Clock / 2.0 #br#
                                                                                    0011  ADCCLK = Input Clock / 2.5
                                                                                    #br#  0100  ADCCLK = Input Clock /
                                                                                    3.0 #br#  0101  ADCCLK = Input Clock
                                                                                    / 3.5 #br#  0110  ADCCLK = Input
                                                                                    Clock / 4.0 #br#  0111  ADCCLK =
                                                                                    Input Clock / 4.5 #br#  1000  ADCCLK
                                                                                    = Input Clock / 5.0 #br#  1001
                                                                                    ADCCLK = Input Clock / 5.5 #br#  1010
                                                                                    ADCCLK = Input Clock / 6.0 #br#
                                                                                    1011  ADCCLK = Input Clock / 6.5 #br#
                                                                                    1100  ADCCLK = Input Clock / 7.0
                                                                                    #br#  1101  ADCCLK = Input Clock /
                                                                                    7.5 #br#  1110  ADCCLK = Input Clock
                                                                                    / 8.0 #br#  1111  ADCCLK = Input
                                                                                    Clock / 8.5 */

/* HSADC_ADCBURSTCTL Bits */
/* HSADC_ADCBURSTCTL[BURSTTRIGSEL] Bits */
#define HSADC_ADCBURSTCTL_BURSTTRIGSEL_OFS       (0)                             /* !< BURSTTRIGSEL Offset */
#define HSADC_ADCBURSTCTL_BURSTTRIGSEL_MASK      ((uint32_t)0x0000001FU)         /* !< SOC Burst Trigger Source Select.
                                                                                    Configures which trigger will start a
                                                                                    burst conversion sequence. #br#
                                                                                    #br#Note: SOCFRC1 register can always
                                                                                    be used to software trigger SOCs in
                                                                                    addition to any hardware trigger
                                                                                    configuration. #br#  00h  BURSTTRIG0
                                                                                    - Software only #br#  01h - 3Fh -
                                                                                    Hardware Triggers */
/* HSADC_ADCBURSTCTL[BURSTSIZE] Bits */
#define HSADC_ADCBURSTCTL_BURSTSIZE_OFS          (8)                             /* !< BURSTSIZE Offset */
#define HSADC_ADCBURSTCTL_BURSTSIZE_MASK         ((uint32_t)0x00000F00U)         /* !< SOC Burst Size Select. This bit
                                                                                    field determines how many SOCs are
                                                                                    converted when a burst conversion
                                                                                    sequence is started. The first SOC
                                                                                    converted is defined by the round
                                                                                    robin pointer, which is advanced as
                                                                                    each SOC is converted. #br# #br#  0h
                                                                                    1 SOC converted #br#  1h  2 SOCs
                                                                                    converted #br#  2h  3 SOCs converted
                                                                                    #br#  3h  4 SOCs converted #br#  4h
                                                                                    5 SOCs converted #br#  5h  6 SOCs
                                                                                    converted #br#  6h  7 SOCs converted
                                                                                    #br#  7h  8 SOCs converted #br#  8h
                                                                                    9 SOCs converted #br#  9h  10 SOCs
                                                                                    converted #br#  Ah  11 SOCs converted
                                                                                    #br#  Bh  12 SOCs converted #br#  Ch
                                                                                    13 SOCs converted #br#  Dh  14 SOCs
                                                                                    converted #br#  Eh  15 SOCs converted
                                                                                    #br#  Fh  16 SOCs converted */
/* HSADC_ADCBURSTCTL[BURSTEN] Bits */
#define HSADC_ADCBURSTCTL_BURSTEN_OFS            (15)                            /* !< BURSTEN Offset */
#define HSADC_ADCBURSTCTL_BURSTEN_MASK           ((uint32_t)0x00008000U)         /* !< SOC Burst Mode Enable. This bit
                                                                                    enables the SOC Burst Mode of
                                                                                    operation. #br# #br#  0  Burst mode
                                                                                    is disabled. #br#  1  Burst mode is
                                                                                    enabled. */

/* HSADC_ADCINTSEL Bits */
/* HSADC_ADCINTSEL[INT1SEL] Bits */
#define HSADC_ADCINTSEL_INT1SEL_OFS              (0)                             /* !< INT1SEL Offset */
#define HSADC_ADCINTSEL_INT1SEL_MASK             ((uint32_t)0x0000000FU)         /* !< ADCINT1 EOC Source Select #br#  00h
                                                                                    EOC0 is trigger for ADCINT1 #br#
                                                                                    01h  EOC1 is trigger for ADCINT1 #br#
                                                                                    02h  EOC2 is trigger for ADCINT1
                                                                                    #br#  03h  EOC3 is trigger for
                                                                                    ADCINT1 #br#  04h  EOC4 is trigger
                                                                                    for ADCINT1 #br#  05h  EOC5 is
                                                                                    trigger for ADCINT1 #br#  06h  EOC6
                                                                                    is trigger for ADCINT1 #br#  07h
                                                                                    EOC7 is trigger for ADCINT1 #br#  08h
                                                                                    EOC8 is trigger for ADCINT1 #br#
                                                                                    09h  EOC9 is trigger for ADCINT1 #br#
                                                                                    0Ah  EOC10 is trigger for ADCINT1
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCINT1 #br#  0Ch  EOC12 is trigger
                                                                                    for ADCINT1 #br#  0Dh  EOC13 is
                                                                                    trigger for ADCINT1 #br#  0Eh  EOC14
                                                                                    is trigger for ADCINT1 #br#  0Fh
                                                                                    EOC15 is trigger for ADCINT1 #br#
                                                                                    #br#Note : When oversampling is
                                                                                    enabled, the end of the last
                                                                                    oversampled coversion will trigger
                                                                                    the interrupts #br# */
/* HSADC_ADCINTSEL[INT1CONT] Bits */
#define HSADC_ADCINTSEL_INT1CONT_OFS             (6)                             /* !< INT1CONT Offset */
#define HSADC_ADCINTSEL_INT1CONT_MASK            ((uint32_t)0x00000040U)         /* !< ADCINT1 Continue to Interrupt Mode
                                                                                    #br#  0  No further ADCINT1 pulses
                                                                                    are generated until ADCINT1 flag (in
                                                                                    ADCINTFLG register) is cleared by
                                                                                    user. #br#  1  ADCINT1 pulses are
                                                                                    generated whenever an EOC pulse is
                                                                                    generated irrespective of whether the
                                                                                    flag bit is cleared or not. */
/* HSADC_ADCINTSEL[INT1E] Bits */
#define HSADC_ADCINTSEL_INT1E_OFS                (7)                             /* !< INT1E Offset */
#define HSADC_ADCINTSEL_INT1E_MASK               ((uint32_t)0x00000080U)         /* !< ADCINT1 Interrupt Enable #br#  0
                                                                                    ADCINT1 is disabled #br#  1  ADCINT1
                                                                                    is enabled */
/* HSADC_ADCINTSEL[INT2SEL] Bits */
#define HSADC_ADCINTSEL_INT2SEL_OFS              (8)                             /* !< INT2SEL Offset */
#define HSADC_ADCINTSEL_INT2SEL_MASK             ((uint32_t)0x00000F00U)         /* !< ADCINT2 EOC Source Select #br#  00h
                                                                                    EOC0 is trigger for ADCINT2 #br#
                                                                                    01h  EOC1 is trigger for ADCINT2 #br#
                                                                                    02h  EOC2 is trigger for ADCINT2
                                                                                    #br#  03h  EOC3 is trigger for
                                                                                    ADCINT2 #br#  04h  EOC4 is trigger
                                                                                    for ADCINT2 #br#  05h  EOC5 is
                                                                                    trigger for ADCINT2 #br#  06h  EOC6
                                                                                    is trigger for ADCINT2 #br#  07h
                                                                                    EOC7 is trigger for ADCINT2 #br#  08h
                                                                                    EOC8 is trigger for ADCINT2 #br#
                                                                                    09h  EOC9 is trigger for ADCINT2 #br#
                                                                                    0Ah  EOC10 is trigger for ADCINT2
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCINT2 #br#  0Ch  EOC12 is trigger
                                                                                    for ADCINT2 #br#  0Dh  EOC13 is
                                                                                    trigger for ADCINT2 #br#  0Eh  EOC14
                                                                                    is trigger for ADCINT2 #br#  0Fh
                                                                                    EOC15 is trigger for ADCINT2 #br#
                                                                                    #br#Note : When oversampling is
                                                                                    enabled, the end of the last
                                                                                    oversampled coversion will trigger
                                                                                    the interrupts #br# */
/* HSADC_ADCINTSEL[INT2CONT] Bits */
#define HSADC_ADCINTSEL_INT2CONT_OFS             (14)                            /* !< INT2CONT Offset */
#define HSADC_ADCINTSEL_INT2CONT_MASK            ((uint32_t)0x00004000U)         /* !< ADCINT2 Continue to Interrupt Mode
                                                                                    #br#  0  No further ADCINT2 pulses
                                                                                    are generated until ADCINT2 flag (in
                                                                                    ADCINTFLG register) is cleared by
                                                                                    user. #br#  1  ADCINT2 pulses are
                                                                                    generated whenever an EOC pulse is
                                                                                    generated irrespective of whether the
                                                                                    flag bit is cleared or not. */
/* HSADC_ADCINTSEL[INT2E] Bits */
#define HSADC_ADCINTSEL_INT2E_OFS                (15)                            /* !< INT2E Offset */
#define HSADC_ADCINTSEL_INT2E_MASK               ((uint32_t)0x00008000U)         /* !< ADCINT2 Interrupt Enable #br#  0
                                                                                    ADCINT2 is disabled #br#  1  ADCINT2
                                                                                    is enabled */
/* HSADC_ADCINTSEL[INT3SEL] Bits */
#define HSADC_ADCINTSEL_INT3SEL_OFS              (16)                            /* !< INT3SEL Offset */
#define HSADC_ADCINTSEL_INT3SEL_MASK             ((uint32_t)0x000F0000U)         /* !< ADCINT3 EOC Source Select #br#  00h
                                                                                    EOC0 is trigger for ADCINT3 #br#
                                                                                    01h  EOC1 is trigger for ADCINT3 #br#
                                                                                    02h  EOC2 is trigger for ADCINT3
                                                                                    #br#  03h  EOC3 is trigger for
                                                                                    ADCINT3 #br#  04h  EOC4 is trigger
                                                                                    for ADCINT3 #br#  05h  EOC5 is
                                                                                    trigger for ADCINT3 #br#  06h  EOC6
                                                                                    is trigger for ADCINT3 #br#  07h
                                                                                    EOC7 is trigger for ADCINT3 #br#  08h
                                                                                    EOC8 is trigger for ADCINT3 #br#
                                                                                    09h  EOC9 is trigger for ADCINT3 #br#
                                                                                    0Ah  EOC10 is trigger for ADCINT3
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCINT3 #br#  0Ch  EOC12 is trigger
                                                                                    for ADCINT3 #br#  0Dh  EOC13 is
                                                                                    trigger for ADCINT3 #br#  0Eh  EOC14
                                                                                    is trigger for ADCINT3 #br#  0Fh
                                                                                    EOC15 is trigger for ADCINT3 #br#
                                                                                    #br#Note : When oversampling is
                                                                                    enabled, the end of the last
                                                                                    oversampled coversion will trigger
                                                                                    the interrupts #br# */
/* HSADC_ADCINTSEL[INT3CONT] Bits */
#define HSADC_ADCINTSEL_INT3CONT_OFS             (22)                            /* !< INT3CONT Offset */
#define HSADC_ADCINTSEL_INT3CONT_MASK            ((uint32_t)0x00400000U)         /* !< ADCINT3 Continue to Interrupt Mode
                                                                                    #br#  0  No further ADCINT3 pulses
                                                                                    are generated until ADCINT3 flag (in
                                                                                    ADCINTFLG register) is cleared by
                                                                                    user. #br#  1  ADCINT3 pulses are
                                                                                    generated whenever an EOC pulse is
                                                                                    generated irrespective of whether the
                                                                                    flag bit is cleared or not. */
/* HSADC_ADCINTSEL[INT3E] Bits */
#define HSADC_ADCINTSEL_INT3E_OFS                (23)                            /* !< INT3E Offset */
#define HSADC_ADCINTSEL_INT3E_MASK               ((uint32_t)0x00800000U)         /* !< ADCINT3 Interrupt Enable #br#  0
                                                                                    ADCINT3 is disabled #br#  1  ADCINT3
                                                                                    is enabled */
/* HSADC_ADCINTSEL[INT4SEL] Bits */
#define HSADC_ADCINTSEL_INT4SEL_OFS              (24)                            /* !< INT4SEL Offset */
#define HSADC_ADCINTSEL_INT4SEL_MASK             ((uint32_t)0x0F000000U)         /* !< ADCINT4 EOC Source Select #br#  00h
                                                                                    EOC0 is trigger for ADCINT4 #br#
                                                                                    01h  EOC1 is trigger for ADCINT4 #br#
                                                                                    02h  EOC2 is trigger for ADCINT4
                                                                                    #br#  03h  EOC3 is trigger for
                                                                                    ADCINT4 #br#  04h  EOC4 is trigger
                                                                                    for ADCINT4 #br#  05h  EOC5 is
                                                                                    trigger for ADCINT4 #br#  06h  EOC6
                                                                                    is trigger for ADCINT4 #br#  07h
                                                                                    EOC7 is trigger for ADCINT4 #br#  08h
                                                                                    EOC8 is trigger for ADCINT4 #br#
                                                                                    09h  EOC9 is trigger for ADCINT4 #br#
                                                                                    0Ah  EOC10 is trigger for ADCINT4
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCINT4 #br#  0Ch  EOC12 is trigger
                                                                                    for ADCINT4 #br#  0Dh  EOC13 is
                                                                                    trigger for ADCINT4 #br#  0Eh  EOC14
                                                                                    is trigger for ADCINT4 #br#  0Fh
                                                                                    EOC15 is trigger for ADCINT4 #br#
                                                                                    #br#Note : When oversampling is
                                                                                    enabled, the end of the last
                                                                                    oversampled coversion will trigger
                                                                                    the interrupts #br# */
/* HSADC_ADCINTSEL[INT4CONT] Bits */
#define HSADC_ADCINTSEL_INT4CONT_OFS             (30)                            /* !< INT4CONT Offset */
#define HSADC_ADCINTSEL_INT4CONT_MASK            ((uint32_t)0x40000000U)         /* !< ADCINT4 Continue to Interrupt Mode
                                                                                    #br#  0  No further ADCINT4 pulses
                                                                                    are generated until ADCINT4 flag (in
                                                                                    ADCINTFLG register) is cleared by
                                                                                    user. #br#  1  ADCINT4 pulses are
                                                                                    generated whenever an EOC pulse is
                                                                                    generated irrespective of whether the
                                                                                    flag bit is cleared or not. */
/* HSADC_ADCINTSEL[INT4E] Bits */
#define HSADC_ADCINTSEL_INT4E_OFS                (31)                            /* !< INT4E Offset */
#define HSADC_ADCINTSEL_INT4E_MASK               ((uint32_t)0x80000000U)         /* !< ADCINT4 Interrupt Enable #br#  0
                                                                                    ADCINT4 is disabled #br#  1  ADCINT4
                                                                                    is enabled */

/* HSADC_ADCDMAINTSEL Bits */
/* HSADC_ADCDMAINTSEL[DMAINT1SEL] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT1SEL_OFS        (0)                             /* !< DMAINT1SEL Offset */
#define HSADC_ADCDMAINTSEL_DMAINT1SEL_MASK       ((uint32_t)0x0000000FU)         /* !< ADCDMAINT1 EOC Source Select #br#
                                                                                    00h  EOC0 is trigger for ADCDMAINT1
                                                                                    #br#  01h  EOC1 is trigger for
                                                                                    ADCDMAINT1 #br#  02h  EOC2 is trigger
                                                                                    for ADCDMAINT1 #br#  03h  EOC3 is
                                                                                    trigger for ADCDMAINT1 #br#  04h
                                                                                    EOC4 is trigger for ADCDMAINT1 #br#
                                                                                    05h  EOC5 is trigger for ADCDMAINT1
                                                                                    #br#  06h  EOC6 is trigger for
                                                                                    ADCDMAINT1 #br#  07h  EOC7 is trigger
                                                                                    for ADCDMAINT1 #br#  08h  EOC8 is
                                                                                    trigger for ADCDMAINT1 #br#  09h
                                                                                    EOC9 is trigger for ADCDMAINT1 #br#
                                                                                    0Ah  EOC10 is trigger for ADCDMAINT1
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCDMAINT1 #br#  0Ch  EOC12 is
                                                                                    trigger for ADCDMAINT1 #br#  0Dh
                                                                                    EOC13 is trigger for ADCDMAINT1 #br#
                                                                                    0Eh  EOC14 is trigger for ADCDMAINT1
                                                                                    #br#  0Fh  EOC15 is trigger for
                                                                                    ADCDMAINT1 #br# #br#Note : When
                                                                                    oversampling is enabled, the end of
                                                                                    the last oversampled conversion will
                                                                                    trigger the DMAINTerrupts #br# */
/* HSADC_ADCDMAINTSEL[DMAINT1CONT] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT1CONT_OFS       (6)                             /* !< DMAINT1CONT Offset */
#define HSADC_ADCDMAINTSEL_DMAINT1CONT_MASK      ((uint32_t)0x00000040U)         /* !< ADCDMAINT1 Continue to Interrupt
                                                                                    Mode #br#  0  No further ADCDMAINT1
                                                                                    pulses are generated until ADCDMAINT1
                                                                                    flag (in ADCDMAINTFLG register) is
                                                                                    cleared by user. #br#  1  ADCDMAINT1
                                                                                    pulses are generated whenever an EOC
                                                                                    pulse is generated irrespective of
                                                                                    whether the flag bit is cleared or
                                                                                    not. */
/* HSADC_ADCDMAINTSEL[DMAINT1E] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT1E_OFS          (7)                             /* !< DMAINT1E Offset */
#define HSADC_ADCDMAINTSEL_DMAINT1E_MASK         ((uint32_t)0x00000080U)         /* !< ADCDMAINT1 Interrupt Enable #br#  0
                                                                                    ADCDMAINT1 is disabled #br#  1
                                                                                    ADCDMAINT1 is enabled */
/* HSADC_ADCDMAINTSEL[DMAINT2SEL] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT2SEL_OFS        (8)                             /* !< DMAINT2SEL Offset */
#define HSADC_ADCDMAINTSEL_DMAINT2SEL_MASK       ((uint32_t)0x00000F00U)         /* !< ADCDMAINT2 EOC Source Select #br#
                                                                                    00h  EOC0 is trigger for ADCDMAINT2
                                                                                    #br#  01h  EOC1 is trigger for
                                                                                    ADCDMAINT2 #br#  02h  EOC2 is trigger
                                                                                    for ADCDMAINT2 #br#  03h  EOC3 is
                                                                                    trigger for ADCDMAINT2 #br#  04h
                                                                                    EOC4 is trigger for ADCDMAINT2 #br#
                                                                                    05h  EOC5 is trigger for ADCDMAINT2
                                                                                    #br#  06h  EOC6 is trigger for
                                                                                    ADCDMAINT2 #br#  07h  EOC7 is trigger
                                                                                    for ADCDMAINT2 #br#  08h  EOC8 is
                                                                                    trigger for ADCDMAINT2 #br#  09h
                                                                                    EOC9 is trigger for ADCDMAINT2 #br#
                                                                                    0Ah  EOC10 is trigger for ADCDMAINT2
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCDMAINT2 #br#  0Ch  EOC12 is
                                                                                    trigger for ADCDMAINT2 #br#  0Dh
                                                                                    EOC13 is trigger for ADCDMAINT2 #br#
                                                                                    0Eh  EOC14 is trigger for ADCDMAINT2
                                                                                    #br#  0Fh  EOC15 is trigger for
                                                                                    ADCDMAINT2 #br# #br#Note : When
                                                                                    oversampling is enabled, the end of
                                                                                    the last oversampled coversion will
                                                                                    trigger the DMAINTerrupts #br# */
/* HSADC_ADCDMAINTSEL[DMAINT2CONT] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT2CONT_OFS       (14)                            /* !< DMAINT2CONT Offset */
#define HSADC_ADCDMAINTSEL_DMAINT2CONT_MASK      ((uint32_t)0x00004000U)         /* !< ADCDMAINT2 Continue to Interrupt
                                                                                    Mode #br#  0  No further ADCDMAINT2
                                                                                    pulses are generated until ADCDMAINT2
                                                                                    flag (in ADCDMAINTFLG register) is
                                                                                    cleared by user. #br#  1  ADCDMAINT2
                                                                                    pulses are generated whenever an EOC
                                                                                    pulse is generated irrespective of
                                                                                    whether the flag bit is cleared or
                                                                                    not. */
/* HSADC_ADCDMAINTSEL[DMAINT2E] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT2E_OFS          (15)                            /* !< DMAINT2E Offset */
#define HSADC_ADCDMAINTSEL_DMAINT2E_MASK         ((uint32_t)0x00008000U)         /* !< ADCDMAINT2 Interrupt Enable #br#  0
                                                                                    ADCDMAINT2 is disabled #br#  1
                                                                                    ADCDMAINT2 is enabled */
/* HSADC_ADCDMAINTSEL[DMAINT3SEL] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT3SEL_OFS        (16)                            /* !< DMAINT3SEL Offset */
#define HSADC_ADCDMAINTSEL_DMAINT3SEL_MASK       ((uint32_t)0x000F0000U)         /* !< ADCDMAINT3 EOC Source Select #br#
                                                                                    00h  EOC0 is trigger for ADCDMAINT3
                                                                                    #br#  01h  EOC1 is trigger for
                                                                                    ADCDMAINT3 #br#  02h  EOC2 is trigger
                                                                                    for ADCDMAINT3 #br#  03h  EOC3 is
                                                                                    trigger for ADCDMAINT3 #br#  04h
                                                                                    EOC4 is trigger for ADCDMAINT3 #br#
                                                                                    05h  EOC5 is trigger for ADCDMAINT3
                                                                                    #br#  06h  EOC6 is trigger for
                                                                                    ADCDMAINT3 #br#  07h  EOC7 is trigger
                                                                                    for ADCDMAINT3 #br#  08h  EOC8 is
                                                                                    trigger for ADCDMAINT3 #br#  09h
                                                                                    EOC9 is trigger for ADCDMAINT3 #br#
                                                                                    0Ah  EOC10 is trigger for ADCDMAINT3
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCDMAINT3 #br#  0Ch  EOC12 is
                                                                                    trigger for ADCDMAINT3 #br#  0Dh
                                                                                    EOC13 is trigger for ADCDMAINT3 #br#
                                                                                    0Eh  EOC14 is trigger for ADCDMAINT3
                                                                                    #br#  0Fh  EOC15 is trigger for
                                                                                    ADCDMAINT3 #br# #br#Note : When
                                                                                    oversampling is enabled, the end of
                                                                                    the last oversampled coversion will
                                                                                    trigger the DMAINTerrupts #br# */
/* HSADC_ADCDMAINTSEL[DMAINT3CONT] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT3CONT_OFS       (22)                            /* !< DMAINT3CONT Offset */
#define HSADC_ADCDMAINTSEL_DMAINT3CONT_MASK      ((uint32_t)0x00400000U)         /* !< ADCDMAINT3 Continue to Interrupt
                                                                                    Mode #br#  0  No further ADCDMAINT3
                                                                                    pulses are generated until ADCDMAINT3
                                                                                    flag (in ADCDMAINTFLG register) is
                                                                                    cleared by user. #br#  1  ADCDMAINT3
                                                                                    pulses are generated whenever an EOC
                                                                                    pulse is generated irrespective of
                                                                                    whether the flag bit is cleared or
                                                                                    not. */
/* HSADC_ADCDMAINTSEL[DMAINT3E] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT3E_OFS          (23)                            /* !< DMAINT3E Offset */
#define HSADC_ADCDMAINTSEL_DMAINT3E_MASK         ((uint32_t)0x00800000U)         /* !< ADCDMAINT3 Interrupt Enable #br#  0
                                                                                    ADCDMAINT3 is disabled #br#  1
                                                                                    ADCDMAINT3 is enabled */
/* HSADC_ADCDMAINTSEL[DMAINT4SEL] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT4SEL_OFS        (24)                            /* !< DMAINT4SEL Offset */
#define HSADC_ADCDMAINTSEL_DMAINT4SEL_MASK       ((uint32_t)0x0F000000U)         /* !< ADCDMAINT4 EOC Source Select #br#
                                                                                    00h  EOC0 is trigger for ADCDMAINT4
                                                                                    #br#  01h  EOC1 is trigger for
                                                                                    ADCDMAINT4 #br#  02h  EOC2 is trigger
                                                                                    for ADCDMAINT4 #br#  03h  EOC3 is
                                                                                    trigger for ADCDMAINT4 #br#  04h
                                                                                    EOC4 is trigger for ADCDMAINT4 #br#
                                                                                    05h  EOC5 is trigger for ADCDMAINT4
                                                                                    #br#  06h  EOC6 is trigger for
                                                                                    ADCDMAINT4 #br#  07h  EOC7 is trigger
                                                                                    for ADCDMAINT4 #br#  08h  EOC8 is
                                                                                    trigger for ADCDMAINT4 #br#  09h
                                                                                    EOC9 is trigger for ADCDMAINT4 #br#
                                                                                    0Ah  EOC10 is trigger for ADCDMAINT4
                                                                                    #br#  0Bh  EOC11 is trigger for
                                                                                    ADCDMAINT4 #br#  0Ch  EOC12 is
                                                                                    trigger for ADCDMAINT4 #br#  0Dh
                                                                                    EOC13 is trigger for ADCDMAINT4 #br#
                                                                                    0Eh  EOC14 is trigger for ADCDMAINT4
                                                                                    #br#  0Fh  EOC15 is trigger for
                                                                                    ADCDMAINT4 #br# #br#Note : When
                                                                                    oversampling is enabled, the end of
                                                                                    the last oversampled coversion will
                                                                                    trigger the DMAINTerrupts #br# */
/* HSADC_ADCDMAINTSEL[DMAINT4CONT] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT4CONT_OFS       (30)                            /* !< DMAINT4CONT Offset */
#define HSADC_ADCDMAINTSEL_DMAINT4CONT_MASK      ((uint32_t)0x40000000U)         /* !< ADCDMAINT4 Continue to Interrupt
                                                                                    Mode #br#  0  No further ADCDMAINT4
                                                                                    pulses are generated until ADCDMAINT4
                                                                                    flag (in ADCDMAINTFLG register) is
                                                                                    cleared by user. #br#  1  ADCDMAINT4
                                                                                    pulses are generated whenever an EOC
                                                                                    pulse is generated irrespective of
                                                                                    whether the flag bit is cleared or
                                                                                    not. */
/* HSADC_ADCDMAINTSEL[DMAINT4E] Bits */
#define HSADC_ADCDMAINTSEL_DMAINT4E_OFS          (31)                            /* !< DMAINT4E Offset */
#define HSADC_ADCDMAINTSEL_DMAINT4E_MASK         ((uint32_t)0x80000000U)         /* !< ADCDMAINT4 Interrupt Enable #br#  0
                                                                                    ADCDMAINT4 is disabled #br#  1
                                                                                    ADCDMAINT4 is enabled */

/* HSADC_ADCRAWINTFLG Bits */
/* HSADC_ADCRAWINTFLG[ADCRAWINT1] Bits */
#define HSADC_ADCRAWINTFLG_ADCRAWINT1_OFS        (0)                             /* !< ADCRAWINT1 Offset */
#define HSADC_ADCRAWINTFLG_ADCRAWINT1_MASK       ((uint32_t)0x00000001U)         /* !< ADC RAW Interrupt 1 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated INT condition occurred.
                                                                                    This flag will be set irrespective of
                                                                                    corresponding INTE setting #br# #br#
                                                                                    0  Selected EOC/OSINT event did not
                                                                                    occur #br#  1  Selected EOC/OSINT
                                                                                    event occurred #br# #br#Writing
                                                                                    corresponding INTCLR bit in
                                                                                    ADCINTFLGCLR register will clear this
                                                                                    bit. */
/* HSADC_ADCRAWINTFLG[ADCRAWINT2] Bits */
#define HSADC_ADCRAWINTFLG_ADCRAWINT2_OFS        (1)                             /* !< ADCRAWINT2 Offset */
#define HSADC_ADCRAWINTFLG_ADCRAWINT2_MASK       ((uint32_t)0x00000002U)         /* !< ADC RAW Interrupt 2 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated INT condition occurred.
                                                                                    This flag will be set irrespective of
                                                                                    corresponding INTE setting #br# #br#
                                                                                    0  Selected EOC/OSINT event did not
                                                                                    occur #br#  1  Selected EOC/OSINT
                                                                                    event occured #br# #br#Writing
                                                                                    corresponding INTCLR bit in
                                                                                    ADCINTFLGCLR register will clear this
                                                                                    bit. */
/* HSADC_ADCRAWINTFLG[ADCRAWINT3] Bits */
#define HSADC_ADCRAWINTFLG_ADCRAWINT3_OFS        (2)                             /* !< ADCRAWINT3 Offset */
#define HSADC_ADCRAWINTFLG_ADCRAWINT3_MASK       ((uint32_t)0x00000004U)         /* !< ADC RAW Interrupt 3 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated INT condition occurred.
                                                                                    This flag will be set irrespective of
                                                                                    corresponding INTE setting #br# #br#
                                                                                    0  Selected EOC/OSINT event did not
                                                                                    occur #br#  1  Selected EOC/OSINT
                                                                                    event occured #br# #br#Writing
                                                                                    corresponding INTCLR bit in
                                                                                    ADCINTFLGCLR register will clear this
                                                                                    bit. */
/* HSADC_ADCRAWINTFLG[ADCRAWINT4] Bits */
#define HSADC_ADCRAWINTFLG_ADCRAWINT4_OFS        (3)                             /* !< ADCRAWINT4 Offset */
#define HSADC_ADCRAWINTFLG_ADCRAWINT4_MASK       ((uint32_t)0x00000008U)         /* !< ADC RAW Interrupt 4 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated INT condition occurred.
                                                                                    This flag will be set irrespective of
                                                                                    corresponding INTE setting #br# #br#
                                                                                    0  Selected EOC/OSINT event did not
                                                                                    occur #br#  1  Selected EOC/OSINT
                                                                                    event occured #br# #br#Writing
                                                                                    corresponding INTCLR bit in
                                                                                    ADCINTFLGCLR register will clear this
                                                                                    bit. */
/* HSADC_ADCRAWINTFLG[ADCDMARAWINT1] Bits */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT1_OFS     (16)                            /* !< ADCDMARAWINT1 Offset */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT1_MASK    ((uint32_t)0x00010000U)         /* !< ADC DMA Raw Interrupt 1 Flag.
                                                                                    Reading these flags indicates if the
                                                                                    associated ADCDMAINT condition
                                                                                    occurred. This flag will be set
                                                                                    irrespective of corresponding DMAINTE
                                                                                    setting #br# #br#  0  Selected
                                                                                    EOC/OSINT event did not occur #br#  1
                                                                                    Selected EOC/OSINT event occurred
                                                                                    #br# #br#Writing corresponding INTCLR
                                                                                    bit in ADCINTFLGCLR register will
                                                                                    clear this bit. */
/* HSADC_ADCRAWINTFLG[ADCDMARAWINT2] Bits */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT2_OFS     (17)                            /* !< ADCDMARAWINT2 Offset */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT2_MASK    ((uint32_t)0x00020000U)         /* !< ADC DMA Raw Interrupt 2 Flag.
                                                                                    Reading these flags indicates if the
                                                                                    associated ADCDMAINT condition
                                                                                    occurred. This flag will be set
                                                                                    irrespective of corresponding DMAINTE
                                                                                    setting #br# #br#  0  Selected
                                                                                    EOC/OSINT event did not occur #br#  1
                                                                                    Selected EOC/OSINT event occurred
                                                                                    #br# #br#Writing corresponding INTCLR
                                                                                    bit in ADCINTFLGCLR register will
                                                                                    clear this bit. */
/* HSADC_ADCRAWINTFLG[ADCDMARAWINT3] Bits */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT3_OFS     (18)                            /* !< ADCDMARAWINT3 Offset */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT3_MASK    ((uint32_t)0x00040000U)         /* !< ADC DMA Raw Interrupt 3 Flag.
                                                                                    Reading these flags indicates if the
                                                                                    associated ADCDMAINT condition
                                                                                    occurred. This flag will be set
                                                                                    irrespective of corresponding DMAINTE
                                                                                    setting #br# #br#  0  Selected
                                                                                    EOC/OSINT event did not occur #br#  1
                                                                                    Selected EOC/OSINT event occurred
                                                                                    #br# #br#Writing corresponding INTCLR
                                                                                    bit in ADCINTFLGCLR register will
                                                                                    clear this bit. */
/* HSADC_ADCRAWINTFLG[ADCDMARAWINT4] Bits */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT4_OFS     (19)                            /* !< ADCDMARAWINT4 Offset */
#define HSADC_ADCRAWINTFLG_ADCDMARAWINT4_MASK    ((uint32_t)0x00080000U)         /* !< ADC DMA Raw Interrupt 4 Flag.
                                                                                    Reading these flags indicates if the
                                                                                    associated ADCDMAINT condition
                                                                                    occurred. This flag will be set
                                                                                    irrespective of corresponding DMAINTE
                                                                                    setting #br# #br#  0  Selected
                                                                                    EOC/OSINT event did not occur #br#  1
                                                                                    Selected EOC/OSINT event occurred
                                                                                    #br# #br#Writing corresponding INTCLR
                                                                                    bit in ADCINTFLGCLR register will
                                                                                    clear this bit. */

/* HSADC_ADCINTFLG Bits */
/* HSADC_ADCINTFLG[ADCINT1] Bits */
#define HSADC_ADCINTFLG_ADCINT1_OFS              (0)                             /* !< ADCINT1 Offset */
#define HSADC_ADCINTFLG_ADCINT1_MASK             ((uint32_t)0x00000001U)         /* !< ADC Interrupt 1 Flag. Reading these
                                                                                    flags indicates if the associated
                                                                                    ADCINT pulse was generated since the
                                                                                    last clear. #br# #br#  0  No ADC
                                                                                    interrupt pulse generated #br#  1
                                                                                    ADC interrupt pulse generated #br#
                                                                                    #br#If the ADC interrupt is placed in
                                                                                    continue to interrupt mode (INTSEL
                                                                                    register) then further interrupt
                                                                                    pulses are generated whenever a
                                                                                    selected EOC event occurs even if the
                                                                                    flag bit is set. If the continuous
                                                                                    mode is not enabled, then no further
                                                                                    interrupt pulses are generated until
                                                                                    the user clears this flag bit using
                                                                                    the ADCINTFLGCLR register. Rather, an
                                                                                    ADC interrupt overflow event occurs
                                                                                    in the ADCINTOVF register. */
/* HSADC_ADCINTFLG[ADCINT2] Bits */
#define HSADC_ADCINTFLG_ADCINT2_OFS              (1)                             /* !< ADCINT2 Offset */
#define HSADC_ADCINTFLG_ADCINT2_MASK             ((uint32_t)0x00000002U)         /* !< ADC Interrupt 2 Flag. Reading these
                                                                                    flags indicates if the associated
                                                                                    ADCINT pulse was generated since the
                                                                                    last clear. #br# #br#  0  No ADC
                                                                                    interrupt pulse generated #br#  1
                                                                                    ADC interrupt pulse generated #br#
                                                                                    #br#If the ADC interrupt is placed in
                                                                                    continue to interrupt mode (INTSEL
                                                                                    register) then further interrupt
                                                                                    pulses are generated whenever a
                                                                                    selected EOC event occurs even if the
                                                                                    flag bit is set. If the continuous
                                                                                    mode is not enabled, then no further
                                                                                    interrupt pulses are generated until
                                                                                    the user clears this flag bit using
                                                                                    the ADCINTFLGCLR register. Rather, an
                                                                                    ADC interrupt overflow event occurs
                                                                                    in the ADCINTOVF register. */
/* HSADC_ADCINTFLG[ADCINT3] Bits */
#define HSADC_ADCINTFLG_ADCINT3_OFS              (2)                             /* !< ADCINT3 Offset */
#define HSADC_ADCINTFLG_ADCINT3_MASK             ((uint32_t)0x00000004U)         /* !< ADC Interrupt 3 Flag. Reading these
                                                                                    flags indicates if the associated
                                                                                    ADCINT pulse was generated since the
                                                                                    last clear. #br# #br#  0  No ADC
                                                                                    interrupt pulse generated #br#  1
                                                                                    ADC interrupt pulse generated #br#
                                                                                    #br#If the ADC interrupt is placed in
                                                                                    continue to interrupt mode (INTSEL
                                                                                    register) then further interrupt
                                                                                    pulses are generated whenever a
                                                                                    selected EOC event occurs even if the
                                                                                    flag bit is set. If the continuous
                                                                                    mode is not enabled, then no further
                                                                                    interrupt pulses are generated until
                                                                                    the user clears this flag bit using
                                                                                    the ADCINTFLGCLR register. Rather, an
                                                                                    ADC interrupt overflow event occurs
                                                                                    in the ADCINTOVF register. */
/* HSADC_ADCINTFLG[ADCINT4] Bits */
#define HSADC_ADCINTFLG_ADCINT4_OFS              (3)                             /* !< ADCINT4 Offset */
#define HSADC_ADCINTFLG_ADCINT4_MASK             ((uint32_t)0x00000008U)         /* !< ADC Interrupt 4 Flag. Reading these
                                                                                    flags indicates if the associated
                                                                                    ADCINT pulse was generated since the
                                                                                    last clear. #br# #br#  0  No ADC
                                                                                    interrupt pulse generated #br#  1
                                                                                    ADC interrupt pulse generated #br#
                                                                                    #br#If the ADC interrupt is placed in
                                                                                    continue to interrupt mode (INTSEL
                                                                                    register) then further interrupt
                                                                                    pulses are generated whenever a
                                                                                    selected EOC event occurs even if the
                                                                                    flag bit is set. If the continuous
                                                                                    mode is not enabled, then no further
                                                                                    interrupt pulses are generated until
                                                                                    the user clears this flag bit using
                                                                                    the ADCINFLGCLR register. Rather, an
                                                                                    ADC interrupt overflow event occurs
                                                                                    in the ADCINTOVF register. */
/* HSADC_ADCINTFLG[ADCINT1RESULT] Bits */
#define HSADC_ADCINTFLG_ADCINT1RESULT_OFS        (8)                             /* !< ADCINT1RESULT Offset */
#define HSADC_ADCINTFLG_ADCINT1RESULT_MASK       ((uint32_t)0x00000100U)         /* !< ADC Interrupt 1 Results Ready Flag.
                                                                                    This flag is set when the conversions
                                                                                    results associated with ADCINT1 latch
                                                                                    into the corresponding results
                                                                                    register.   #br# #br#  0  Conversion
                                                                                    results have not latched #br#  1
                                                                                    Conversion results have latched #br#
                                                                                    #br#This flag can be used in an ISR
                                                                                    that is entered in early interrupt
                                                                                    mode to ensure that the corresponding
                                                                                    results are ready before proceeding
                                                                                    to read the result register.   #br#
                                                                                    #br#This flag can be cleared via the
                                                                                    ACK bit in the ADCINTFLGCLR that also
                                                                                    clears the ADCINT1 flag.    #br#
                                                                                    #br#In case results latch and this
                                                                                    flag is already set, the
                                                                                    corresponding flag in ADCINTOVF is
                                                                                    NOT set.  This flag does NOT have to
                                                                                    be cleared in order for ADCINT ISRs
                                                                                    to propagate to the PIE.   #br#
                                                                                    #br#In case the associated SOC is
                                                                                    associated with a PPB or PPBs, the
                                                                                    flag will not be set until all
                                                                                    associated PPB results latch. */
/* HSADC_ADCINTFLG[ADCINT2RESULT] Bits */
#define HSADC_ADCINTFLG_ADCINT2RESULT_OFS        (9)                             /* !< ADCINT2RESULT Offset */
#define HSADC_ADCINTFLG_ADCINT2RESULT_MASK       ((uint32_t)0x00000200U)         /* !< ADC Interrupt 2 Results Ready Flag.
                                                                                    This flag is set when the conversions
                                                                                    results associated with ADCINT2 latch
                                                                                    into the corresponding results
                                                                                    register.   #br# #br#  0  Conversion
                                                                                    results have not latched #br#  1
                                                                                    Conversion results have latched #br#
                                                                                    #br#This flag can be used in an ISR
                                                                                    that is entered in early interrupt
                                                                                    mode to ensure that the corresponding
                                                                                    results are ready before proceeding
                                                                                    to read the result register.   #br#
                                                                                    #br#This flag can be cleared via the
                                                                                    ACK bit in the ADCINTFLGCLR that also
                                                                                    clears the ADCINT2 flag.    #br#
                                                                                    #br#In case results latch and this
                                                                                    flag is already set, the
                                                                                    corresponding flag in ADCINTOVF is
                                                                                    NOT set.  This flag does NOT have to
                                                                                    be cleared in order for ADCINT ISRs
                                                                                    to propagate to the PIE.   #br#
                                                                                    #br#In case the associated SOC is
                                                                                    associated with a PPB or PPBs, the
                                                                                    flag will not be set until all
                                                                                    associated PPB results latch. */
/* HSADC_ADCINTFLG[ADCINT3RESULT] Bits */
#define HSADC_ADCINTFLG_ADCINT3RESULT_OFS        (10)                            /* !< ADCINT3RESULT Offset */
#define HSADC_ADCINTFLG_ADCINT3RESULT_MASK       ((uint32_t)0x00000400U)         /* !< ADC Interrupt 3 Results Ready Flag.
                                                                                    This flag is set when the conversions
                                                                                    results associated with ADCINT3 latch
                                                                                    into the corresponding results
                                                                                    register.   #br# #br#  0  Conversion
                                                                                    results have not latched #br#  1
                                                                                    Conversion results have latched #br#
                                                                                    #br#This flag can be used in an ISR
                                                                                    that is entered in early interrupt
                                                                                    mode to ensure that the corresponding
                                                                                    results are ready before proceeding
                                                                                    to read the result register.   #br#
                                                                                    #br#This flag can be cleared via the
                                                                                    ACK bit in the ADCINTFLGCLR that also
                                                                                    clears the ADCINT3 flag.    #br#
                                                                                    #br#In case results latch and this
                                                                                    flag is already set, the
                                                                                    corresponding flag in ADCINTOVF is
                                                                                    NOT set.  This flag does NOT have to
                                                                                    be cleared in order for ADCINT ISRs
                                                                                    to propagate to the PIE.   #br#
                                                                                    #br#In case the associated SOC is
                                                                                    associated with a PPB or PPBs, the
                                                                                    flag will not be set until all
                                                                                    associated PPB results latch. */
/* HSADC_ADCINTFLG[ADCINT4RESULT] Bits */
#define HSADC_ADCINTFLG_ADCINT4RESULT_OFS        (11)                            /* !< ADCINT4RESULT Offset */
#define HSADC_ADCINTFLG_ADCINT4RESULT_MASK       ((uint32_t)0x00000800U)         /* !< ADC Interrupt 4 Results Ready Flag.
                                                                                    This flag is set when the conversions
                                                                                    results associated with ADCINT4 latch
                                                                                    into the corresponding results
                                                                                    register.   #br# #br#  0  Conversion
                                                                                    results have not latched #br#  1
                                                                                    Conversion results have latched #br#
                                                                                    #br#This flag can be used in an ISR
                                                                                    that is entered in early interrupt
                                                                                    mode to ensure that the corresponding
                                                                                    results are ready before proceeding
                                                                                    to read the result register.   #br#
                                                                                    #br#This flag can be cleared via the
                                                                                    ACK bit in the ADCINTFLGCLR that also
                                                                                    clears the ADCINT4 flag.    #br#
                                                                                    #br#In case results latch and this
                                                                                    flag is already set, the
                                                                                    corresponding flag in ADCINTOVF is
                                                                                    NOT set.  This flag does NOT have to
                                                                                    be cleared in order for ADCINT ISRs
                                                                                    to propagate to the PIE.   #br#
                                                                                    #br#In case the associated SOC is
                                                                                    associated with a PPB or PPBs, the
                                                                                    flag will not be set until all
                                                                                    associated PPB results latch. */
/* HSADC_ADCINTFLG[ADCDMAINT1] Bits */
#define HSADC_ADCINTFLG_ADCDMAINT1_OFS           (16)                            /* !< ADCDMAINT1 Offset */
#define HSADC_ADCINTFLG_ADCDMAINT1_MASK          ((uint32_t)0x00010000U)         /* !< ADC DMA Interrupt 1 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated ADCDMAINT pulse was
                                                                                    generated since the last clear. #br#
                                                                                    #br#  0  No ADC DMA interrupt pulse
                                                                                    generated #br#  1  ADC DMA interrupt
                                                                                    pulse generated #br# #br#If the ADC
                                                                                    interrupt is placed in continue to
                                                                                    interrupt mode (DMAINTSEL register)
                                                                                    then further interrupt pulses are
                                                                                    generated whenever a selected EOC
                                                                                    event occurs even if the flag bit is
                                                                                    set. If the continuous mode is not
                                                                                    enabled, then no further interrupt
                                                                                    pulses are generated until the user
                                                                                    clears this flag bit using the
                                                                                    ADCINTFLGCLR register. Rather, an ADC
                                                                                    interrupt overflow event occurs in
                                                                                    the ADCINTOVF register. */
/* HSADC_ADCINTFLG[ADCDMAINT2] Bits */
#define HSADC_ADCINTFLG_ADCDMAINT2_OFS           (17)                            /* !< ADCDMAINT2 Offset */
#define HSADC_ADCINTFLG_ADCDMAINT2_MASK          ((uint32_t)0x00020000U)         /* !< ADC DMA Interrupt 2 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated ADCDMAINT pulse was
                                                                                    generated since the last clear. #br#
                                                                                    #br#  0  No ADC DMA interrupt pulse
                                                                                    generated #br#  1  ADC DMA interrupt
                                                                                    pulse generated #br# #br#If the ADC
                                                                                    DMA interrupt is placed in continue
                                                                                    to interrupt mode (DMAINTSEL
                                                                                    register) then further interrupt
                                                                                    pulses are generated whenever a
                                                                                    selected EOC event occurs even if the
                                                                                    flag bit is set. If the continuous
                                                                                    mode is not enabled, then no further
                                                                                    interrupt pulses are generated until
                                                                                    the user clears this flag bit using
                                                                                    the ADCINTFLGCLR register. Rather, an
                                                                                    ADC interrupt overflow event occurs
                                                                                    in the ADCINTOVF register. */
/* HSADC_ADCINTFLG[ADCDMAINT3] Bits */
#define HSADC_ADCINTFLG_ADCDMAINT3_OFS           (18)                            /* !< ADCDMAINT3 Offset */
#define HSADC_ADCINTFLG_ADCDMAINT3_MASK          ((uint32_t)0x00040000U)         /* !< ADC DMA Interrupt 3 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated ADCDMAINT pulse was
                                                                                    generated since the last clear. #br#
                                                                                    #br#  0  No ADC DMA interrupt pulse
                                                                                    generated #br#  1  ADC DMA interrupt
                                                                                    pulse generated #br# #br#If the ADC
                                                                                    interrupt is placed in continue to
                                                                                    interrupt mode (DMAINTSEL register)
                                                                                    then further interrupt pulses are
                                                                                    generated whenever a selected EOC
                                                                                    event occurs even if the flag bit is
                                                                                    set. If the continuous mode is not
                                                                                    enabled, then no further interrupt
                                                                                    pulses are generated until the user
                                                                                    clears this flag bit using the
                                                                                    ADCINTFLGCLR register. Rather, an ADC
                                                                                    interrupt overflow event occurs in
                                                                                    the ADCINTOVF register. */
/* HSADC_ADCINTFLG[ADCDMAINT4] Bits */
#define HSADC_ADCINTFLG_ADCDMAINT4_OFS           (19)                            /* !< ADCDMAINT4 Offset */
#define HSADC_ADCINTFLG_ADCDMAINT4_MASK          ((uint32_t)0x00080000U)         /* !< ADC DMA Interrupt 4 Flag. Reading
                                                                                    these flags indicates if the
                                                                                    associated ADCDMAINT pulse was
                                                                                    generated since the last clear. #br#
                                                                                    #br#  0  No ADC DMA interru4pt pulse
                                                                                    generated #br#  1  ADC DMA interrupt
                                                                                    pulse generated #br# #br#If the ADC
                                                                                    interrupt is placed in continue to
                                                                                    interrupt mode (DMAINTSEL register)
                                                                                    then further interrupt pulses are
                                                                                    generated whenever a selected EOC
                                                                                    event occurs even if the flag bit is
                                                                                    set. If the continuous mode is not
                                                                                    enabled, then no further interrupt
                                                                                    pulses are generated until the user
                                                                                    clears this flag bit using the
                                                                                    ADCINTFLGCLR register. Rather, an ADC
                                                                                    interrupt overflow event occurs in
                                                                                    the ADCINTOVF register. */

/* HSADC_ADCINTFLGFRC Bits */
/* HSADC_ADCINTFLGFRC[ADCINT1] Bits */
#define HSADC_ADCINTFLGFRC_ADCINT1_OFS           (0)                             /* !< ADCINT1 Offset */
#define HSADC_ADCINTFLGFRC_ADCINT1_MASK          ((uint32_t)0x00000001U)         /* !< ADC Interrupt 1 Flag Force. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Forces ADCINT1 flags in the
                                                                                    ADCINTFLG and ADCRAWINTFLG registers. */
/* HSADC_ADCINTFLGFRC[ADCINT2] Bits */
#define HSADC_ADCINTFLGFRC_ADCINT2_OFS           (1)                             /* !< ADCINT2 Offset */
#define HSADC_ADCINTFLGFRC_ADCINT2_MASK          ((uint32_t)0x00000002U)         /* !< ADC Interrupt 2 Flag Force. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Forces ADCINT2 flags in the
                                                                                    ADCINTFLG and ADCRAWINTFLG registers. */
/* HSADC_ADCINTFLGFRC[ADCINT3] Bits */
#define HSADC_ADCINTFLGFRC_ADCINT3_OFS           (2)                             /* !< ADCINT3 Offset */
#define HSADC_ADCINTFLGFRC_ADCINT3_MASK          ((uint32_t)0x00000004U)         /* !< ADC Interrupt 3 Flag Force. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Forces ADCINT3 flags in the
                                                                                    ADCINTFLG and ADCRAWINTFLG registers. */
/* HSADC_ADCINTFLGFRC[ADCINT4] Bits */
#define HSADC_ADCINTFLGFRC_ADCINT4_OFS           (3)                             /* !< ADCINT4 Offset */
#define HSADC_ADCINTFLGFRC_ADCINT4_MASK          ((uint32_t)0x00000008U)         /* !< ADC Interrupt 4 Flag Force. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Forces ADCINT4 flags in the
                                                                                    ADCINTFLG and ADCRAWINTFLG registers. */
/* HSADC_ADCINTFLGFRC[ADCDMAINT1] Bits */
#define HSADC_ADCINTFLGFRC_ADCDMAINT1_OFS        (16)                            /* !< ADCDMAINT1 Offset */
#define HSADC_ADCINTFLGFRC_ADCDMAINT1_MASK       ((uint32_t)0x00010000U)         /* !< ADC DMA interrupt 1 Flag Force.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1  Forces ADCDMAINT1
                                                                                    flags in the ADCINTFLG and
                                                                                    ADCRAWINTFLG registers. */
/* HSADC_ADCINTFLGFRC[ADCDMAINT2] Bits */
#define HSADC_ADCINTFLGFRC_ADCDMAINT2_OFS        (17)                            /* !< ADCDMAINT2 Offset */
#define HSADC_ADCINTFLGFRC_ADCDMAINT2_MASK       ((uint32_t)0x00020000U)         /* !< ADC DMA interrupt 2 Flag Force.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1  Forces ADCDMAINT2
                                                                                    flags in the ADCINTFLG and
                                                                                    ADCRAWINTFLG registers. */
/* HSADC_ADCINTFLGFRC[ADCDMAINT3] Bits */
#define HSADC_ADCINTFLGFRC_ADCDMAINT3_OFS        (18)                            /* !< ADCDMAINT3 Offset */
#define HSADC_ADCINTFLGFRC_ADCDMAINT3_MASK       ((uint32_t)0x00040000U)         /* !< ADC DMA interrupt 3 Flag Force.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1  Forces ADCDMAINT3
                                                                                    flags in the ADCINTFLG and
                                                                                    ADCRAWINTFLG registers. */
/* HSADC_ADCINTFLGFRC[ADCDMAINT4] Bits */
#define HSADC_ADCINTFLGFRC_ADCDMAINT4_OFS        (19)                            /* !< ADCDMAINT4 Offset */
#define HSADC_ADCINTFLGFRC_ADCDMAINT4_MASK       ((uint32_t)0x00080000U)         /* !< ADC DMA interrupt 4 Flag Force.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1  Forces ADCDMAINT4
                                                                                    flags in the ADCINTFLG and
                                                                                    ADCRAWINTFLG registers. */

/* HSADC_ADCINTFLGCLR Bits */
/* HSADC_ADCINTFLGCLR[ADCINT1] Bits */
#define HSADC_ADCINTFLGCLR_ADCINT1_OFS           (0)                             /* !< ADCINT1 Offset */
#define HSADC_ADCINTFLGCLR_ADCINT1_MASK          ((uint32_t)0x00000001U)         /* !< ADC Interrupt 1 Flag Clear. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Clears ADCINT1 and
                                                                                    ADCINT1RESULT flags in the ADCINTFLG,
                                                                                    ADCRAWINTFLG registers.  #br#If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority and the overflow bit will
                                                                                    not be set */
/* HSADC_ADCINTFLGCLR[ADCINT2] Bits */
#define HSADC_ADCINTFLGCLR_ADCINT2_OFS           (1)                             /* !< ADCINT2 Offset */
#define HSADC_ADCINTFLGCLR_ADCINT2_MASK          ((uint32_t)0x00000002U)         /* !< ADC Interrupt 2 Flag Clear. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Clears ADCINT2 and
                                                                                    ADCINT2RESULT flags in the ADCINTFLG,
                                                                                    ADCRAWINTFLG registers. If software
                                                                                    sets the clear bit on the same cycle
                                                                                    that hardware is trying to set the
                                                                                    flag bit, then hardware has priority
                                                                                    and the overflow bit will not be set */
/* HSADC_ADCINTFLGCLR[ADCINT3] Bits */
#define HSADC_ADCINTFLGCLR_ADCINT3_OFS           (2)                             /* !< ADCINT3 Offset */
#define HSADC_ADCINTFLGCLR_ADCINT3_MASK          ((uint32_t)0x00000004U)         /* !< ADC Interrupt 3 Flag Clear. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Clears ADCINT3 and
                                                                                    ADCINT3RESULT flags in the ADCINTFLG,
                                                                                    ADCRAWINTFLG registers. #br#  If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority and the overflow bit will
                                                                                    not be set */
/* HSADC_ADCINTFLGCLR[ADCINT4] Bits */
#define HSADC_ADCINTFLGCLR_ADCINT4_OFS           (3)                             /* !< ADCINT4 Offset */
#define HSADC_ADCINTFLGCLR_ADCINT4_MASK          ((uint32_t)0x00000008U)         /* !< ADC Interrupt 4 Flag Clear. Reads
                                                                                    return 0. #br# #br#  0  No action
                                                                                    #br#  1  Clears ADCINT4 and
                                                                                    ADCINT4RESULT flags in the
                                                                                    ADCINTFLG,, ADCRAWINTFLG registers.
                                                                                    #br#If software sets the clear bit on
                                                                                    the same cycle that hardware is
                                                                                    trying to set the flag bit, then
                                                                                    hardware has priority and the
                                                                                    overflow bit will not be set */
/* HSADC_ADCINTFLGCLR[ADCDMAINT1] Bits */
#define HSADC_ADCINTFLGCLR_ADCDMAINT1_OFS        (16)                            /* !< ADCDMAINT1 Offset */
#define HSADC_ADCINTFLGCLR_ADCDMAINT1_MASK       ((uint32_t)0x00010000U)         /* !< ADC DMA Interrupt 1 Flag Clear.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1  Clears ADDMACINT1
                                                                                    flags in the ADCINTFLG ,ADCRAWINTFLG
                                                                                    registers.  #br#If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority and
                                                                                    the overflow bit will not be set */
/* HSADC_ADCINTFLGCLR[ADCDMAINT2] Bits */
#define HSADC_ADCINTFLGCLR_ADCDMAINT2_OFS        (17)                            /* !< ADCDMAINT2 Offset */
#define HSADC_ADCINTFLGCLR_ADCDMAINT2_MASK       ((uint32_t)0x00020000U)         /* !< ADC DMA Interrupt 2 Flag Clear.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1   Clears ADDMACINT2
                                                                                    flags in the ADCINTFLG ,ADCRAWINTFLG
                                                                                    registers.   #br#If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority and
                                                                                    the overflow bit will not be set */
/* HSADC_ADCINTFLGCLR[ADCDMAINT3] Bits */
#define HSADC_ADCINTFLGCLR_ADCDMAINT3_OFS        (18)                            /* !< ADCDMAINT3 Offset */
#define HSADC_ADCINTFLGCLR_ADCDMAINT3_MASK       ((uint32_t)0x00040000U)         /* !< ADC DMA Interrupt 3 Flag Clear.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1   Clears ADDMACINT3
                                                                                    flags in the ADCINTFLG ,ADCRAWINTFLG
                                                                                    registers.  #br#  If software sets
                                                                                    the clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority and
                                                                                    the overflow bit will not be set */
/* HSADC_ADCINTFLGCLR[ADCDMAINT4] Bits */
#define HSADC_ADCINTFLGCLR_ADCDMAINT4_OFS        (19)                            /* !< ADCDMAINT4 Offset */
#define HSADC_ADCINTFLGCLR_ADCDMAINT4_MASK       ((uint32_t)0x00080000U)         /* !< ADC DMA Interrupt 4 Flag Clear.
                                                                                    Reads return 0. #br# #br#  0  No
                                                                                    action #br#  1  Clears ADDMACINT4
                                                                                    flags in the ADCINTFLG ,ADCRAWINTFLG
                                                                                    registers.  #br#If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority and
                                                                                    the overflow bit will not be set */

/* HSADC_ADCINTOVF Bits */
/* HSADC_ADCINTOVF[ADCINT1OVF] Bits */
#define HSADC_ADCINTOVF_ADCINT1OVF_OFS           (0)                             /* !< ADCINT1OVF Offset */
#define HSADC_ADCINTOVF_ADCINT1OVF_MASK          ((uint32_t)0x00000001U)         /* !< ADC Interrupt 1 Overflow Flags #br#
                                                                                    #br#Indicates if an overflow occurred
                                                                                    when generating ADCINT pulses. If the
                                                                                    respective ADCINTFLG bit is set and a
                                                                                    selected additional EOC trigger is
                                                                                    generated, then an overflow condition
                                                                                    occurs. #br# #br#  0  No ADC
                                                                                    interrupt overflow event detected.
                                                                                    #br#  1  ADC Interrupt overflow event
                                                                                    detected. #br# #br#The overflow bit
                                                                                    does not care about the continuous
                                                                                    mode bit state. An overflow condition
                                                                                    is generated irrespective of this
                                                                                    mode selection. */
/* HSADC_ADCINTOVF[ADCINT2OVF] Bits */
#define HSADC_ADCINTOVF_ADCINT2OVF_OFS           (1)                             /* !< ADCINT2OVF Offset */
#define HSADC_ADCINTOVF_ADCINT2OVF_MASK          ((uint32_t)0x00000002U)         /* !< ADC Interrupt 2 Overflow Flags #br#
                                                                                    #br#Indicates if an overflow occurred
                                                                                    when generating ADCINT pulses. If the
                                                                                    respective ADCINTFLG bit is set and a
                                                                                    selected additional EOC trigger is
                                                                                    generated, then an overflow condition
                                                                                    occurs. #br# #br#  0  No ADC
                                                                                    interrupt overflow event detected.
                                                                                    #br#  1  ADC Interrupt overflow event
                                                                                    detected. #br# #br#The overflow bit
                                                                                    does not care about the continuous
                                                                                    mode bit state. An overflow condition
                                                                                    is generated irrespective of this
                                                                                    mode selection. */
/* HSADC_ADCINTOVF[ADCINT3OVF] Bits */
#define HSADC_ADCINTOVF_ADCINT3OVF_OFS           (2)                             /* !< ADCINT3OVF Offset */
#define HSADC_ADCINTOVF_ADCINT3OVF_MASK          ((uint32_t)0x00000004U)         /* !< ADC Interrupt 3 Overflow Flags #br#
                                                                                    #br#Indicates if an overflow occurred
                                                                                    when generating ADCINT pulses. If the
                                                                                    respective ADCINTFLG bit is set and a
                                                                                    selected additional EOC trigger is
                                                                                    generated, then an overflow condition
                                                                                    occurs. #br# #br#  0  No ADC
                                                                                    interrupt overflow event detected.
                                                                                    #br#  1  ADC Interrupt overflow event
                                                                                    detected. #br# #br#The overflow bit
                                                                                    does not care about the continuous
                                                                                    mode bit state. An overflow condition
                                                                                    is generated irrespective of this
                                                                                    mode selection. */
/* HSADC_ADCINTOVF[ADCINT4OVF] Bits */
#define HSADC_ADCINTOVF_ADCINT4OVF_OFS           (3)                             /* !< ADCINT4OVF Offset */
#define HSADC_ADCINTOVF_ADCINT4OVF_MASK          ((uint32_t)0x00000008U)         /* !< ADC Interrupt 4 Overflow Flags #br#
                                                                                    #br#Indicates if an overflow occurred
                                                                                    when generating ADCINT pulses. If the
                                                                                    respective ADCINTFLG bit is set and a
                                                                                    selected additional EOC trigger is
                                                                                    generated, then an overflow condition
                                                                                    occurs. #br# #br#  0  No ADC
                                                                                    interrupt overflow event detected.
                                                                                    #br#  1  ADC Interrupt overflow event
                                                                                    detected. #br# #br#The overflow bit
                                                                                    does not care about the continuous
                                                                                    mode bit state. An overflow condition
                                                                                    is generated irrespective of this
                                                                                    mode selection. */
/* HSADC_ADCINTOVF[ADCDMAINT1OVF] Bits */
#define HSADC_ADCINTOVF_ADCDMAINT1OVF_OFS        (16)                            /* !< ADCDMAINT1OVF Offset */
#define HSADC_ADCINTOVF_ADCDMAINT1OVF_MASK       ((uint32_t)0x00010000U)         /* !< ADC DMA Interrupt 1 Overflow Flags
                                                                                    #br# #br#Indicates if an overflow
                                                                                    occurred when generating ADCINT
                                                                                    pulses. If the respective ADCINTFLG
                                                                                    bit is set and a selected additional
                                                                                    EOC trigger is generated, then an
                                                                                    overflow condition occurs. #br# #br#
                                                                                    0  No ADC DMA Interrupt overflow
                                                                                    event detected. #br#  1  ADC DMA
                                                                                    Interrupt overflow event detected.
                                                                                    #br# #br#The overflow bit does not
                                                                                    care about the continuous mode bit
                                                                                    state. An overflow condition is
                                                                                    generated irrespective of this mode
                                                                                    selection. */
/* HSADC_ADCINTOVF[ADCDMAINT2OVF] Bits */
#define HSADC_ADCINTOVF_ADCDMAINT2OVF_OFS        (17)                            /* !< ADCDMAINT2OVF Offset */
#define HSADC_ADCINTOVF_ADCDMAINT2OVF_MASK       ((uint32_t)0x00020000U)         /* !< ADC DMA Interrupt 2 Overflow Flags
                                                                                    #br# #br#Indicates if an overflow
                                                                                    occurred when generating ADCINT
                                                                                    pulses. If the respective ADCINTFLG
                                                                                    bit is set and a selected additional
                                                                                    EOC trigger is generated, then an
                                                                                    overflow condition occurs. #br# #br#
                                                                                    0  No ADC DMA Interrupt overflow
                                                                                    event detected. #br#  1  ADC DMA
                                                                                    Interrupt overflow event detected.
                                                                                    #br# #br#The overflow bit does not
                                                                                    care about the continuous mode bit
                                                                                    state. An overflow condition is
                                                                                    generated irrespective of this mode
                                                                                    selection. */
/* HSADC_ADCINTOVF[ADCDMAINT3OVF] Bits */
#define HSADC_ADCINTOVF_ADCDMAINT3OVF_OFS        (18)                            /* !< ADCDMAINT3OVF Offset */
#define HSADC_ADCINTOVF_ADCDMAINT3OVF_MASK       ((uint32_t)0x00040000U)         /* !< ADC DMA Interrupt 3 Overflow Flags
                                                                                    #br# #br#Indicates if an overflow
                                                                                    occurred when generating ADCINT
                                                                                    pulses. If the respective ADCINTFLG
                                                                                    bit is set and a selected additional
                                                                                    EOC trigger is generated, then an
                                                                                    overflow condition occurs. #br# #br#
                                                                                    0  No ADC DMA Interrupt overflow
                                                                                    event detected. #br#  1  ADC DMA
                                                                                    Interrupt overflow event detected.
                                                                                    #br# #br#The overflow bit does not
                                                                                    care about the continuous mode bit
                                                                                    state. An overflow condition is
                                                                                    generated irrespective of this mode
                                                                                    selection. */
/* HSADC_ADCINTOVF[ADCDMAINT4OVF] Bits */
#define HSADC_ADCINTOVF_ADCDMAINT4OVF_OFS        (19)                            /* !< ADCDMAINT4OVF Offset */
#define HSADC_ADCINTOVF_ADCDMAINT4OVF_MASK       ((uint32_t)0x00080000U)         /* !< ADC DMA Interrupt 4 Overflow Flags
                                                                                    #br# #br#Indicates if an overflow
                                                                                    occurred when generating ADCINT
                                                                                    pulses. If the respective ADCINTFLG
                                                                                    bit is set and a selected additional
                                                                                    EOC trigger is generated, then an
                                                                                    overflow condition occurs. #br# #br#
                                                                                    0  No ADC DMA Interrupt overflow
                                                                                    event detected. #br#  1  ADC DMA
                                                                                    Interrupt overflow event detected.
                                                                                    #br# #br#The overflow bit does not
                                                                                    care about the continuous mode bit
                                                                                    state. An overflow condition is
                                                                                    generated irrespective of this mode
                                                                                    selection. */

/* HSADC_ADCINTOVFCLR Bits */
/* HSADC_ADCINTOVFCLR[ADCINT1OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCINT1OVF_OFS        (0)                             /* !< ADCINT1OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCINT1OVF_MASK       ((uint32_t)0x00000001U)         /* !< ADC Interrupt 1 Overflow Clear Bits
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit in
                                                                                    the ADCINTOVF register. If software
                                                                                    tries to set this bit on the same
                                                                                    clock cycle that hardware tries to
                                                                                    set the overflow bit in the ADCINTOVF
                                                                                    register, then hardware has priority
                                                                                    and the ADCINTOVF bit will be set. */
/* HSADC_ADCINTOVFCLR[ADCINT2OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCINT2OVF_OFS        (1)                             /* !< ADCINT2OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCINT2OVF_MASK       ((uint32_t)0x00000002U)         /* !< ADC Interrupt 2 Overflow Clear Bits
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit in
                                                                                    the ADCINTOVF register. If software
                                                                                    tries to set this bit on the same
                                                                                    clock cycle that hardware tries to
                                                                                    set the overflow bit in the ADCINTOVF
                                                                                    register, then hardware has priority
                                                                                    and the ADCINTOVF bit will be set. */
/* HSADC_ADCINTOVFCLR[ADCINT3OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCINT3OVF_OFS        (2)                             /* !< ADCINT3OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCINT3OVF_MASK       ((uint32_t)0x00000004U)         /* !< ADC Interrupt 3 Overflow Clear Bits
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit in
                                                                                    the ADCINTOVF register. If software
                                                                                    tries to set this bit on the same
                                                                                    clock cycle that hardware tries to
                                                                                    set the overflow bit in the ADCINTOVF
                                                                                    register, then hardware has priority
                                                                                    and the ADCINTOVF bit will be set. */
/* HSADC_ADCINTOVFCLR[ADCINT4OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCINT4OVF_OFS        (3)                             /* !< ADCINT4OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCINT4OVF_MASK       ((uint32_t)0x00000008U)         /* !< ADC Interrupt 4 Overflow Clear Bits
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit in
                                                                                    the ADCINTOVF register. If software
                                                                                    tries to set this bit on the same
                                                                                    clock cycle that hardware tries to
                                                                                    set the overflow bit in the ADCINTOVF
                                                                                    register, then hardware has priority
                                                                                    and the ADCINTOVF bit will be set. */
/* HSADC_ADCINTOVFCLR[ADCDMAINT1OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCDMAINT1OVF_OFS     (16)                            /* !< ADCDMAINT1OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCDMAINT1OVF_MASK    ((uint32_t)0x00010000U)         /* !< ADC DMA Interrupt 1 Overflow Clear
                                                                                    Bits #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit
                                                                                    in the ADCINTOVF register. If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCINTOVF register, then hardware has
                                                                                    priority and the ADCINTOVF bit will
                                                                                    be set. */
/* HSADC_ADCINTOVFCLR[ADCDMAINT2OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCDMAINT2OVF_OFS     (17)                            /* !< ADCDMAINT2OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCDMAINT2OVF_MASK    ((uint32_t)0x00020000U)         /* !< ADC DMA Interrupt 2 Overflow Clear
                                                                                    Bits #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit
                                                                                    in the ADCINTOVF register. If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCINTOVF register, then hardware has
                                                                                    priority and the ADCINTOVF bit will
                                                                                    be set. */
/* HSADC_ADCINTOVFCLR[ADCDMAINT3OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCDMAINT3OVF_OFS     (18)                            /* !< ADCDMAINT3OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCDMAINT3OVF_MASK    ((uint32_t)0x00040000U)         /* !< ADC DMA Interrupt 3 Overflow Clear
                                                                                    Bits #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit
                                                                                    in the ADCINTOVF register. If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCINTOVF register, then hardware has
                                                                                    priority and the ADCINTOVF bit will
                                                                                    be set. */
/* HSADC_ADCINTOVFCLR[ADCDMAINT4OVF] Bits */
#define HSADC_ADCINTOVFCLR_ADCDMAINT4OVF_OFS     (19)                            /* !< ADCDMAINT4OVF Offset */
#define HSADC_ADCINTOVFCLR_ADCDMAINT4OVF_MASK    ((uint32_t)0x00080000U)         /* !< ADC DMA Interrupt 4 Overflow Clear
                                                                                    Bits #br# #br#  0  No action. #br#  1
                                                                                    Clears the respective overflow bit
                                                                                    in the ADCINTOVF register. If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCINTOVF register, then hardware has
                                                                                    priority and the ADCINTOVF bit will
                                                                                    be set. */

/* HSADC_ADCSOCPRICTL Bits */
/* HSADC_ADCSOCPRICTL[SOCPRIORITY] Bits */
#define HSADC_ADCSOCPRICTL_SOCPRIORITY_OFS       (0)                             /* !< SOCPRIORITY Offset */
#define HSADC_ADCSOCPRICTL_SOCPRIORITY_MASK      ((uint32_t)0x00000003U)         /* !< SOC Priority #br#Determines the
                                                                                    cutoff point for priority mode and
                                                                                    round robin arbitration for SOCx #br#
                                                                                    0h  SOC priority is handled in round
                                                                                    robin mode for all channels. #br#  1h
                                                                                    SOC0 is high priority, rest of
                                                                                    channels are in round robin mode.
                                                                                    #br#  2h  SOC0-SOC1 are high
                                                                                    priority, SOC2-SOC15 are in round
                                                                                    robin mode. #br#  3h  SOC0-SOC2 are
                                                                                    high priority, SOC3-SOC15 are in
                                                                                    round robin mode. */
/* HSADC_ADCSOCPRICTL[RRPOINTER] Bits */
#define HSADC_ADCSOCPRICTL_RRPOINTER_OFS         (6)                             /* !< RRPOINTER Offset */
#define HSADC_ADCSOCPRICTL_RRPOINTER_MASK        ((uint32_t)0x000007C0U)         /* !< Round Robin Pointer. Holds the
                                                                                    value of the last converted round
                                                                                    robin SOCx to be used by the round
                                                                                    robin scheme to determine order of
                                                                                    conversions. #br#  00h  SOC0 was last
                                                                                    round robin SOC to convert, SOC1 is
                                                                                    highest round robin priority. #br#
                                                                                    01h  SOC1 was last round robin SOC to
                                                                                    convert, SOC2 is highest round robin
                                                                                    priority. #br#  02h  SOC2 was last
                                                                                    round robin SOC to convert, SOC3 is
                                                                                    highest round robin priority. #br#
                                                                                    03h  SOC3 was last round robin SOC to
                                                                                    convert, SOC4 is highest round robin
                                                                                    priority. #br#  04h  SOC4 was last
                                                                                    round robin SOC to convert, SOC5 is
                                                                                    highest round robin priority. #br#
                                                                                    05h  SOC5 was last round robin SOC to
                                                                                    convert, SOC6 is highest round robin
                                                                                    priority. #br#  06h  SOC6 was last
                                                                                    round robin SOC to convert, SOC7 is
                                                                                    highest round robin priority. #br#
                                                                                    07h  SOC7 was last round robin SOC to
                                                                                    convert, SOC8 is highest round robin
                                                                                    priority. #br#  08h  SOC8 was last
                                                                                    round robin SOC to convert, SOC9 is
                                                                                    highest round robin priority. #br#
                                                                                    09h  SOC9 was last round robin SOC to
                                                                                    convert, SOC10 is highest round robin
                                                                                    priority. #br#  0Ah  SOC10 was last
                                                                                    round robin SOC to convert, SOC11 is
                                                                                    highest round robin priority. #br#
                                                                                    0Bh  SOC11 was last round robin SOC
                                                                                    to convert, SOC12 is highest round
                                                                                    robin priority. #br#  0Ch  SOC12 was
                                                                                    last round robin SOC to convert,
                                                                                    SOC13 is highest round robin
                                                                                    priority. #br#  0Dh  SOC13 was last
                                                                                    round robin SOC to convert, SOC14 is
                                                                                    highest round robin priority. #br#
                                                                                    0Eh  SOC14 was last round robin SOC
                                                                                    to convert, SOC15 is highest round
                                                                                    robin priority. #br#  0Fh  SOC15 was
                                                                                    last round robin SOC to convert, SOC0
                                                                                    is highest round robin priority. #br#
                                                                                    10h  Reset value to indicate no SOC
                                                                                    has been converted. SOC0 is highest
                                                                                    round robin priority. Set to this
                                                                                    value when the ADC module is reset by
                                                                                    SOFTPRES or when the ADCSOCPRICTL
                                                                                    register is written. In the latter
                                                                                    case, if a conversion is currently in
                                                                                    progress, it will complete and then
                                                                                    the new priority will take effect.
                                                                                    #br#Others  Invalid value. */

/* HSADC_ADCINTSOCSEL1 Bits */
/* HSADC_ADCINTSOCSEL1[SOC0] Bits */
#define HSADC_ADCINTSOCSEL1_SOC0_OFS             (0)                             /* !< SOC0 Offset */
#define HSADC_ADCINTSOCSEL1_SOC0_MASK            ((uint32_t)0x00000003U)         /* !< SOC0 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC0. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC0. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC0. #br#  10
                                                                                    ADCINT2 will trigger SOC0. #br#  11
                                                                                    EOC[N-1] will trigger SOC0. #br#N -
                                                                                    Total number of SOCs supported */
/* HSADC_ADCINTSOCSEL1[SOC1] Bits */
#define HSADC_ADCINTSOCSEL1_SOC1_OFS             (2)                             /* !< SOC1 Offset */
#define HSADC_ADCINTSOCSEL1_SOC1_MASK            ((uint32_t)0x0000000CU)         /* !< SOC1 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC1. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC1. TRIGSEL field alone
                                                                                    determines SOC1 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC1. #br#  10
                                                                                    ADCINT2 will trigger SOC1. #br#  11
                                                                                    EOC0 will trigger SOC1. */
/* HSADC_ADCINTSOCSEL1[SOC2] Bits */
#define HSADC_ADCINTSOCSEL1_SOC2_OFS             (4)                             /* !< SOC2 Offset */
#define HSADC_ADCINTSOCSEL1_SOC2_MASK            ((uint32_t)0x00000030U)         /* !< SOC2 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC2. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC2. TRIGSEL field alone
                                                                                    determines SOC2 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC2. #br#  10
                                                                                    ADCINT2 will trigger SOC2. #br#  11
                                                                                    EOC1 will trigger SOC2. */
/* HSADC_ADCINTSOCSEL1[SOC3] Bits */
#define HSADC_ADCINTSOCSEL1_SOC3_OFS             (6)                             /* !< SOC3 Offset */
#define HSADC_ADCINTSOCSEL1_SOC3_MASK            ((uint32_t)0x000000C0U)         /* !< SOC3 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC3. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC3. TRIGSEL field alone
                                                                                    determines SOC3 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC3. #br#  10
                                                                                    ADCINT2 will trigger SOC3. #br#  11
                                                                                    EOC2 will trigger SOC3. */
/* HSADC_ADCINTSOCSEL1[SOC4] Bits */
#define HSADC_ADCINTSOCSEL1_SOC4_OFS             (8)                             /* !< SOC4 Offset */
#define HSADC_ADCINTSOCSEL1_SOC4_MASK            ((uint32_t)0x00000300U)         /* !< SOC4 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC4. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC4. TRIGSEL field alone
                                                                                    determines SOC4 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC4. #br#  10
                                                                                    ADCINT2 will trigger SOC4. #br#  11
                                                                                    EOC3 will trigger SOC4. */
/* HSADC_ADCINTSOCSEL1[SOC5] Bits */
#define HSADC_ADCINTSOCSEL1_SOC5_OFS             (10)                            /* !< SOC5 Offset */
#define HSADC_ADCINTSOCSEL1_SOC5_MASK            ((uint32_t)0x00000C00U)         /* !< SOC5 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC5. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC5. TRIGSEL field alone
                                                                                    determines SOC5 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC5. #br#  10
                                                                                    ADCINT2 will trigger SOC5. #br#  11
                                                                                    EOC4 will trigger SOC5. */
/* HSADC_ADCINTSOCSEL1[SOC6] Bits */
#define HSADC_ADCINTSOCSEL1_SOC6_OFS             (12)                            /* !< SOC6 Offset */
#define HSADC_ADCINTSOCSEL1_SOC6_MASK            ((uint32_t)0x00003000U)         /* !< SOC6 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC6. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC6. TRIGSEL field alone
                                                                                    determines SOC6 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC6. #br#  10
                                                                                    ADCINT2 will trigger SOC6. #br#  11
                                                                                    EOC5 will trigger SOC6. */
/* HSADC_ADCINTSOCSEL1[SOC7] Bits */
#define HSADC_ADCINTSOCSEL1_SOC7_OFS             (14)                            /* !< SOC7 Offset */
#define HSADC_ADCINTSOCSEL1_SOC7_MASK            ((uint32_t)0x0000C000U)         /* !< SOC7 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC7. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC7. TRIGSEL field alone
                                                                                    determines SOC7 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC7. #br#  10
                                                                                    ADCINT2 will trigger SOC7. #br#  11
                                                                                    EOC6 will trigger SOC7. */
/* HSADC_ADCINTSOCSEL1[SOC8] Bits */
#define HSADC_ADCINTSOCSEL1_SOC8_OFS             (16)                            /* !< SOC8 Offset */
#define HSADC_ADCINTSOCSEL1_SOC8_MASK            ((uint32_t)0x00030000U)         /* !< SOC8 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC8. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC8. TRIGSEL field alone
                                                                                    determines SOC8 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC8. #br#  10
                                                                                    ADCINT2 will trigger SOC8. #br#  11
                                                                                    EOC7 will trigger SOC8. */
/* HSADC_ADCINTSOCSEL1[SOC9] Bits */
#define HSADC_ADCINTSOCSEL1_SOC9_OFS             (18)                            /* !< SOC9 Offset */
#define HSADC_ADCINTSOCSEL1_SOC9_MASK            ((uint32_t)0x000C0000U)         /* !< SOC9 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC9. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC9. TRIGSEL field alone
                                                                                    determines SOC9 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC9. #br#  10
                                                                                    ADCINT2 will trigger SOC1. #br#  11
                                                                                    EOC8 will trigger SOC9. */
/* HSADC_ADCINTSOCSEL1[SOC10] Bits */
#define HSADC_ADCINTSOCSEL1_SOC10_OFS            (20)                            /* !< SOC10 Offset */
#define HSADC_ADCINTSOCSEL1_SOC10_MASK           ((uint32_t)0x00300000U)         /* !< SOC10 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC10. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC10. TRIGSEL field alone
                                                                                    determines SOC10 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC10. #br#  10
                                                                                    ADCINT2 will trigger SOC10. #br#  11
                                                                                    EOC9 will trigger SOC10. */
/* HSADC_ADCINTSOCSEL1[SOC11] Bits */
#define HSADC_ADCINTSOCSEL1_SOC11_OFS            (22)                            /* !< SOC11 Offset */
#define HSADC_ADCINTSOCSEL1_SOC11_MASK           ((uint32_t)0x00C00000U)         /* !< SOC11 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC11. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC11. TRIGSEL field alone
                                                                                    determines SOC11 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC11. #br#  10
                                                                                    ADCINT2 will trigger SOC11. #br#  11
                                                                                    EOC10 will trigger SOC11. */
/* HSADC_ADCINTSOCSEL1[SOC12] Bits */
#define HSADC_ADCINTSOCSEL1_SOC12_OFS            (24)                            /* !< SOC12 Offset */
#define HSADC_ADCINTSOCSEL1_SOC12_MASK           ((uint32_t)0x03000000U)         /* !< SOC12 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC12. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC12. TRIGSEL field alone
                                                                                    determines SOC12 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC12. #br#  10
                                                                                    ADCINT2 will trigger SOC12. #br#  11
                                                                                    EOC11 will trigger SOC12. */
/* HSADC_ADCINTSOCSEL1[SOC13] Bits */
#define HSADC_ADCINTSOCSEL1_SOC13_OFS            (26)                            /* !< SOC13 Offset */
#define HSADC_ADCINTSOCSEL1_SOC13_MASK           ((uint32_t)0x0C000000U)         /* !< SOC13 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC13. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC13. TRIGSEL field alone
                                                                                    determines SOC13 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC13. #br#  10
                                                                                    ADCINT2 will trigger SOC13. #br#  11
                                                                                    EOC12 will trigger SOC13. */
/* HSADC_ADCINTSOCSEL1[SOC14] Bits */
#define HSADC_ADCINTSOCSEL1_SOC14_OFS            (28)                            /* !< SOC14 Offset */
#define HSADC_ADCINTSOCSEL1_SOC14_MASK           ((uint32_t)0x30000000U)         /* !< SOC14 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC14. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC14. TRIGSEL field alone
                                                                                    determines SOC14 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC14. #br#  10
                                                                                    ADCINT2 will trigger SOC14. #br#  11
                                                                                    EOC13 will trigger SOC14. */
/* HSADC_ADCINTSOCSEL1[SOC15] Bits */
#define HSADC_ADCINTSOCSEL1_SOC15_OFS            (30)                            /* !< SOC15 Offset */
#define HSADC_ADCINTSOCSEL1_SOC15_MASK           ((uint32_t)0xC0000000U)         /* !< SOC15 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC15. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC15. TRIGSEL field alone
                                                                                    determines SOC15 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC15. #br#  10
                                                                                    ADCINT2 will trigger SOC15. #br#  11
                                                                                    EOC14 will trigger SOC15. */

/* HSADC_ADCINTSOCSEL2 Bits */
/* HSADC_ADCINTSOCSEL2[SOC16] Bits */
#define HSADC_ADCINTSOCSEL2_SOC16_OFS            (0)                             /* !< SOC16 Offset */
#define HSADC_ADCINTSOCSEL2_SOC16_MASK           ((uint32_t)0x00000003U)         /* !< SOC16 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC16. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC16. TRIGSEL field alone
                                                                                    determines SOC16 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC16. #br#  10
                                                                                    ADCINT2 will trigger SOC16. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC17] Bits */
#define HSADC_ADCINTSOCSEL2_SOC17_OFS            (2)                             /* !< SOC17 Offset */
#define HSADC_ADCINTSOCSEL2_SOC17_MASK           ((uint32_t)0x0000000CU)         /* !< SOC17 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC17. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC17. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC17. #br#  10
                                                                                    ADCINT2 will trigger SOC17. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC18] Bits */
#define HSADC_ADCINTSOCSEL2_SOC18_OFS            (4)                             /* !< SOC18 Offset */
#define HSADC_ADCINTSOCSEL2_SOC18_MASK           ((uint32_t)0x00000030U)         /* !< SOC18 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC18. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC18. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC18. #br#  10
                                                                                    ADCINT2 will trigger SOC18. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC19] Bits */
#define HSADC_ADCINTSOCSEL2_SOC19_OFS            (6)                             /* !< SOC19 Offset */
#define HSADC_ADCINTSOCSEL2_SOC19_MASK           ((uint32_t)0x000000C0U)         /* !< SOC19 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC19. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC19. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC19. #br#  10
                                                                                    ADCINT2 will trigger SOC19. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC20] Bits */
#define HSADC_ADCINTSOCSEL2_SOC20_OFS            (8)                             /* !< SOC20 Offset */
#define HSADC_ADCINTSOCSEL2_SOC20_MASK           ((uint32_t)0x00000300U)         /* !< SOC20 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC20. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC20. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC20. #br#  10
                                                                                    ADCINT2 will trigger SOC20. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC21] Bits */
#define HSADC_ADCINTSOCSEL2_SOC21_OFS            (10)                            /* !< SOC21 Offset */
#define HSADC_ADCINTSOCSEL2_SOC21_MASK           ((uint32_t)0x00000C00U)         /* !< SOC21 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC21. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC21. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC21. #br#  10
                                                                                    ADCINT2 will trigger SOC21. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC22] Bits */
#define HSADC_ADCINTSOCSEL2_SOC22_OFS            (12)                            /* !< SOC22 Offset */
#define HSADC_ADCINTSOCSEL2_SOC22_MASK           ((uint32_t)0x00003000U)         /* !< SOC22 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC22. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC22. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC22. #br#  10
                                                                                    ADCINT2 will trigger SOC22. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC23] Bits */
#define HSADC_ADCINTSOCSEL2_SOC23_OFS            (14)                            /* !< SOC23 Offset */
#define HSADC_ADCINTSOCSEL2_SOC23_MASK           ((uint32_t)0x0000C000U)         /* !< SOC23 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC23. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC23. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC23. #br#  10
                                                                                    ADCINT2 will trigger SOC23. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC24] Bits */
#define HSADC_ADCINTSOCSEL2_SOC24_OFS            (16)                            /* !< SOC24 Offset */
#define HSADC_ADCINTSOCSEL2_SOC24_MASK           ((uint32_t)0x00030000U)         /* !< SOC24 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC24. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC24. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC24. #br#  10
                                                                                    ADCINT2 will trigger SOC24. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC25] Bits */
#define HSADC_ADCINTSOCSEL2_SOC25_OFS            (18)                            /* !< SOC25 Offset */
#define HSADC_ADCINTSOCSEL2_SOC25_MASK           ((uint32_t)0x000C0000U)         /* !< SOC25 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC25. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC25. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC25. #br#  10
                                                                                    ADCINT2 will trigger SOC25. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC26] Bits */
#define HSADC_ADCINTSOCSEL2_SOC26_OFS            (20)                            /* !< SOC26 Offset */
#define HSADC_ADCINTSOCSEL2_SOC26_MASK           ((uint32_t)0x00300000U)         /* !< SOC26 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC26. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC26. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC26. #br#  10
                                                                                    ADCINT2 will trigger SOC26. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC27] Bits */
#define HSADC_ADCINTSOCSEL2_SOC27_OFS            (22)                            /* !< SOC27 Offset */
#define HSADC_ADCINTSOCSEL2_SOC27_MASK           ((uint32_t)0x00C00000U)         /* !< SOC27 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC27. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC27. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC27. #br#  10
                                                                                    ADCINT2 will trigger SOC27. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC28] Bits */
#define HSADC_ADCINTSOCSEL2_SOC28_OFS            (24)                            /* !< SOC28 Offset */
#define HSADC_ADCINTSOCSEL2_SOC28_MASK           ((uint32_t)0x03000000U)         /* !< SOC28 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC28. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC28. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC28. #br#  10
                                                                                    ADCINT2 will trigger SOC28. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC29] Bits */
#define HSADC_ADCINTSOCSEL2_SOC29_OFS            (26)                            /* !< SOC29 Offset */
#define HSADC_ADCINTSOCSEL2_SOC29_MASK           ((uint32_t)0x0C000000U)         /* !< SOC29 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC29. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC29. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC29. #br#  10
                                                                                    ADCINT2 will trigger SOC29. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC30] Bits */
#define HSADC_ADCINTSOCSEL2_SOC30_OFS            (28)                            /* !< SOC30 Offset */
#define HSADC_ADCINTSOCSEL2_SOC30_MASK           ((uint32_t)0x30000000U)         /* !< SOC30 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC30. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC30. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC30. #br#  10
                                                                                    ADCINT2 will trigger SOC30. #br#  11
                                                                                    Invalid selection. */
/* HSADC_ADCINTSOCSEL2[SOC31] Bits */
#define HSADC_ADCINTSOCSEL2_SOC31_OFS            (30)                            /* !< SOC31 Offset */
#define HSADC_ADCINTSOCSEL2_SOC31_MASK           ((uint32_t)0xC0000000U)         /* !< SOC31 ADC Interrupt Trigger Select.
                                                                                    Selects which, if any, ADCINT
                                                                                    triggers SOC31. The trigger selected
                                                                                    in this field is in addition to the
                                                                                    TRIGSEL field in the ADCSOCxCTL
                                                                                    register. #br#  00  No ADCINT will
                                                                                    trigger SOC31. TRIGSEL field alone
                                                                                    determines SOC0 trigger. #br#  01
                                                                                    ADCINT1 will trigger SOC31. #br#  10
                                                                                    ADCINT2 will trigger SOC31. #br#  11
                                                                                    Invalid selection. */

/* HSADC_ADCSOCFLG1 Bits */
/* HSADC_ADCSOCFLG1[SOC0] Bits */
#define HSADC_ADCSOCFLG1_SOC0_OFS                (0)                             /* !< SOC0 Offset */
#define HSADC_ADCSOCFLG1_SOC0_MASK               ((uint32_t)0x00000001U)         /* !< SOC0 Start of Conversion Flag.
                                                                                    Indicates the state of SOC0
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC0. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC0. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC0 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC1] Bits */
#define HSADC_ADCSOCFLG1_SOC1_OFS                (1)                             /* !< SOC1 Offset */
#define HSADC_ADCSOCFLG1_SOC1_MASK               ((uint32_t)0x00000002U)         /* !< SOC1 Start of Conversion Flag.
                                                                                    Indicates the state of SOC1
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC1. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC1. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC1 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC2] Bits */
#define HSADC_ADCSOCFLG1_SOC2_OFS                (2)                             /* !< SOC2 Offset */
#define HSADC_ADCSOCFLG1_SOC2_MASK               ((uint32_t)0x00000004U)         /* !< SOC2 Start of Conversion Flag.
                                                                                    Indicates the state of SOC2
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC2. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC2. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC2 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC3] Bits */
#define HSADC_ADCSOCFLG1_SOC3_OFS                (3)                             /* !< SOC3 Offset */
#define HSADC_ADCSOCFLG1_SOC3_MASK               ((uint32_t)0x00000008U)         /* !< SOC3 Start of Conversion Flag.
                                                                                    Indicates the state of SOC3
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC3. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC3. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC3 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC4] Bits */
#define HSADC_ADCSOCFLG1_SOC4_OFS                (4)                             /* !< SOC4 Offset */
#define HSADC_ADCSOCFLG1_SOC4_MASK               ((uint32_t)0x00000010U)         /* !< SOC4 Start of Conversion Flag.
                                                                                    Indicates the state of SOC4
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC4. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC4. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC4 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC5] Bits */
#define HSADC_ADCSOCFLG1_SOC5_OFS                (5)                             /* !< SOC5 Offset */
#define HSADC_ADCSOCFLG1_SOC5_MASK               ((uint32_t)0x00000020U)         /* !< SOC5 Start of Conversion Flag.
                                                                                    Indicates the state of SOC5
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC5. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC5. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC5 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC6] Bits */
#define HSADC_ADCSOCFLG1_SOC6_OFS                (6)                             /* !< SOC6 Offset */
#define HSADC_ADCSOCFLG1_SOC6_MASK               ((uint32_t)0x00000040U)         /* !< SOC6 Start of Conversion Flag.
                                                                                    Indicates the state of SOC6
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC6. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC6. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC6 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC7] Bits */
#define HSADC_ADCSOCFLG1_SOC7_OFS                (7)                             /* !< SOC7 Offset */
#define HSADC_ADCSOCFLG1_SOC7_MASK               ((uint32_t)0x00000080U)         /* !< SOC7 Start of Conversion Flag.
                                                                                    Indicates the state of SOC7
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC7. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC7. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC7 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC8] Bits */
#define HSADC_ADCSOCFLG1_SOC8_OFS                (8)                             /* !< SOC8 Offset */
#define HSADC_ADCSOCFLG1_SOC8_MASK               ((uint32_t)0x00000100U)         /* !< SOC8 Start of Conversion Flag.
                                                                                    Indicates the state of SOC8
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC8. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC8. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC8 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC9] Bits */
#define HSADC_ADCSOCFLG1_SOC9_OFS                (9)                             /* !< SOC9 Offset */
#define HSADC_ADCSOCFLG1_SOC9_MASK               ((uint32_t)0x00000200U)         /* !< SOC9 Start of Conversion Flag.
                                                                                    Indicates the state of SOC9
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC9. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC9. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC9 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC10] Bits */
#define HSADC_ADCSOCFLG1_SOC10_OFS               (10)                            /* !< SOC10 Offset */
#define HSADC_ADCSOCFLG1_SOC10_MASK              ((uint32_t)0x00000400U)         /* !< SOC10 Start of Conversion Flag.
                                                                                    Indicates the state of SOC10
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC10. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC10. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC10 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC11] Bits */
#define HSADC_ADCSOCFLG1_SOC11_OFS               (11)                            /* !< SOC11 Offset */
#define HSADC_ADCSOCFLG1_SOC11_MASK              ((uint32_t)0x00000800U)         /* !< SOC11 Start of Conversion Flag.
                                                                                    Indicates the state of SOC11
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC11. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC11. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC11 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC12] Bits */
#define HSADC_ADCSOCFLG1_SOC12_OFS               (12)                            /* !< SOC12 Offset */
#define HSADC_ADCSOCFLG1_SOC12_MASK              ((uint32_t)0x00001000U)         /* !< SOC12 Start of Conversion Flag.
                                                                                    Indicates the state of SOC12
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC12. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC12. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC12 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC13] Bits */
#define HSADC_ADCSOCFLG1_SOC13_OFS               (13)                            /* !< SOC13 Offset */
#define HSADC_ADCSOCFLG1_SOC13_MASK              ((uint32_t)0x00002000U)         /* !< SOC13 Start of Conversion Flag.
                                                                                    Indicates the state of SOC13
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC13. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC13. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC13 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC14] Bits */
#define HSADC_ADCSOCFLG1_SOC14_OFS               (14)                            /* !< SOC14 Offset */
#define HSADC_ADCSOCFLG1_SOC14_MASK              ((uint32_t)0x00004000U)         /* !< SOC14 Start of Conversion Flag.
                                                                                    Indicates the state of SOC14
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC14. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC14. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC14 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFLG1[SOC15] Bits */
#define HSADC_ADCSOCFLG1_SOC15_OFS               (15)                            /* !< SOC15 Offset */
#define HSADC_ADCSOCFLG1_SOC15_MASK              ((uint32_t)0x00008000U)         /* !< SOC15 Start of Conversion Flag.
                                                                                    Indicates the state of SOC15
                                                                                    conversions. #br# #br#  0  No sample
                                                                                    pending for SOC15. #br#  1  Trigger
                                                                                    has been received and sample is
                                                                                    pending for SOC15. #br# #br#This bit
                                                                                    will be automatically cleared when
                                                                                    the SOC15 conversion is started. If
                                                                                    contention exists where this bit
                                                                                    receives both a request to set and a
                                                                                    request to clear on the same cycle,
                                                                                    regardless of the source of either,
                                                                                    this bit will be set and the request
                                                                                    to clear will be ignored. In this
                                                                                    case the overflow bit in the
                                                                                    ADCSOCOVF1 register will not be
                                                                                    affected regardless of whether this
                                                                                    bit was previously set or not. */

/* HSADC_ADCSOCFRC1 Bits */
/* HSADC_ADCSOCFRC1[SOC0] Bits */
#define HSADC_ADCSOCFRC1_SOC0_OFS                (0)                             /* !< SOC0 Offset */
#define HSADC_ADCSOCFRC1_SOC0_MASK               ((uint32_t)0x00000001U)         /* !< SOC0 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC0
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC0 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC0. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC0 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC1] Bits */
#define HSADC_ADCSOCFRC1_SOC1_OFS                (1)                             /* !< SOC1 Offset */
#define HSADC_ADCSOCFRC1_SOC1_MASK               ((uint32_t)0x00000002U)         /* !< SOC1 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC1
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC1 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC1. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC1 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC2] Bits */
#define HSADC_ADCSOCFRC1_SOC2_OFS                (2)                             /* !< SOC2 Offset */
#define HSADC_ADCSOCFRC1_SOC2_MASK               ((uint32_t)0x00000004U)         /* !< SOC2 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC2
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC2 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC2. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC2 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC3] Bits */
#define HSADC_ADCSOCFRC1_SOC3_OFS                (3)                             /* !< SOC3 Offset */
#define HSADC_ADCSOCFRC1_SOC3_MASK               ((uint32_t)0x00000008U)         /* !< SOC3 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC3
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC3 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC3. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC3 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC4] Bits */
#define HSADC_ADCSOCFRC1_SOC4_OFS                (4)                             /* !< SOC4 Offset */
#define HSADC_ADCSOCFRC1_SOC4_MASK               ((uint32_t)0x00000010U)         /* !< SOC4 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC4
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC4 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC4. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC4 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC5] Bits */
#define HSADC_ADCSOCFRC1_SOC5_OFS                (5)                             /* !< SOC5 Offset */
#define HSADC_ADCSOCFRC1_SOC5_MASK               ((uint32_t)0x00000020U)         /* !< SOC5 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC5
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC5 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC5. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC5 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC6] Bits */
#define HSADC_ADCSOCFRC1_SOC6_OFS                (6)                             /* !< SOC6 Offset */
#define HSADC_ADCSOCFRC1_SOC6_MASK               ((uint32_t)0x00000040U)         /* !< SOC6 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC6
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC6 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC6. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC6 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC7] Bits */
#define HSADC_ADCSOCFRC1_SOC7_OFS                (7)                             /* !< SOC7 Offset */
#define HSADC_ADCSOCFRC1_SOC7_MASK               ((uint32_t)0x00000080U)         /* !< SOC7 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC7
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC7 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC7. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC7 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC8] Bits */
#define HSADC_ADCSOCFRC1_SOC8_OFS                (8)                             /* !< SOC8 Offset */
#define HSADC_ADCSOCFRC1_SOC8_MASK               ((uint32_t)0x00000100U)         /* !< SOC8 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC8
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC8 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC8. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC8 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC9] Bits */
#define HSADC_ADCSOCFRC1_SOC9_OFS                (9)                             /* !< SOC9 Offset */
#define HSADC_ADCSOCFRC1_SOC9_MASK               ((uint32_t)0x00000200U)         /* !< SOC9 Force Start of Conversion Bit.
                                                                                    Writing a 1 will force to 1 the SOC9
                                                                                    flag in the ADCSOCFLG1 register. This
                                                                                    can be used to initiate a software
                                                                                    initiated conversion. Writes of 0 are
                                                                                    ignored. This bit will always read as
                                                                                    a 0. #br# #br#  0  No action. #br#  1
                                                                                    Force SOC9 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC9. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC9 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC10] Bits */
#define HSADC_ADCSOCFRC1_SOC10_OFS               (10)                            /* !< SOC10 Offset */
#define HSADC_ADCSOCFRC1_SOC10_MASK              ((uint32_t)0x00000400U)         /* !< SOC10 Force Start of Conversion
                                                                                    Bit. Writing a 1 will force to 1 the
                                                                                    SOC10 flag in the ADCSOCFLG1
                                                                                    register. This can be used to
                                                                                    initiate a software initiated
                                                                                    conversion. Writes of 0 are ignored.
                                                                                    This bit will always read as a 0.
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Force SOC10 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC10. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC10 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC11] Bits */
#define HSADC_ADCSOCFRC1_SOC11_OFS               (11)                            /* !< SOC11 Offset */
#define HSADC_ADCSOCFRC1_SOC11_MASK              ((uint32_t)0x00000800U)         /* !< SOC11 Force Start of Conversion
                                                                                    Bit. Writing a 1 will force to 1 the
                                                                                    SOC11 flag in the ADCSOCFLG1
                                                                                    register. This can be used to
                                                                                    initiate a software initiated
                                                                                    conversion. Writes of 0 are ignored.
                                                                                    This bit will always read as a 0.
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Force SOC11 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC11. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC11 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC12] Bits */
#define HSADC_ADCSOCFRC1_SOC12_OFS               (12)                            /* !< SOC12 Offset */
#define HSADC_ADCSOCFRC1_SOC12_MASK              ((uint32_t)0x00001000U)         /* !< SOC12 Force Start of Conversion
                                                                                    Bit. Writing a 1 will force to 1 the
                                                                                    SOC12 flag in the ADCSOCFLG1
                                                                                    register. This can be used to
                                                                                    initiate a software initiated
                                                                                    conversion. Writes of 0 are ignored.
                                                                                    This bit will always read as a 0.
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Force SOC12 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC12. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC12 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC13] Bits */
#define HSADC_ADCSOCFRC1_SOC13_OFS               (13)                            /* !< SOC13 Offset */
#define HSADC_ADCSOCFRC1_SOC13_MASK              ((uint32_t)0x00002000U)         /* !< SOC13 Force Start of Conversion
                                                                                    Bit. Writing a 1 will force to 1 the
                                                                                    SOC13 flag in the ADCSOCFLG1
                                                                                    register. This can be used to
                                                                                    initiate a software initiated
                                                                                    conversion. Writes of 0 are ignored.
                                                                                    This bit will always read as a 0.
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Force SOC13 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC13. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC13 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC14] Bits */
#define HSADC_ADCSOCFRC1_SOC14_OFS               (14)                            /* !< SOC14 Offset */
#define HSADC_ADCSOCFRC1_SOC14_MASK              ((uint32_t)0x00004000U)         /* !< SOC14 Force Start of Conversion
                                                                                    Bit. Writing a 1 will force to 1 the
                                                                                    SOC14 flag in the ADCSOCFLG1
                                                                                    register. This can be used to
                                                                                    initiate a software initiated
                                                                                    conversion. Writes of 0 are ignored.
                                                                                    This bit will always read as a 0.
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Force SOC14 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC14. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC14 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */
/* HSADC_ADCSOCFRC1[SOC15] Bits */
#define HSADC_ADCSOCFRC1_SOC15_OFS               (15)                            /* !< SOC15 Offset */
#define HSADC_ADCSOCFRC1_SOC15_MASK              ((uint32_t)0x00008000U)         /* !< SOC15 Force Start of Conversion
                                                                                    Bit. Writing a 1 will force to 1 the
                                                                                    SOC15 flag in the ADCSOCFLG1
                                                                                    register. This can be used to
                                                                                    initiate a software initiated
                                                                                    conversion. Writes of 0 are ignored.
                                                                                    This bit will always read as a 0.
                                                                                    #br# #br#  0  No action. #br#  1
                                                                                    Force SOC15 flag bit to 1. This will
                                                                                    cause a conversion to start once
                                                                                    priority is given to SOC15. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to clear the SOC15 bit in the
                                                                                    ADCSOCFLG1 register, then software
                                                                                    has priority and the ADCSOCFLG1 bit
                                                                                    will be set. In this case the
                                                                                    overflow bit in the ADCSOCOVF1
                                                                                    register will not be affected
                                                                                    regardless of whether the ADCSOCFLG1
                                                                                    bit was previously set or not. */

/* HSADC_ADCSOCOVF1 Bits */
/* HSADC_ADCSOCOVF1[SOC0OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC0OVF_OFS             (0)                             /* !< SOC0OVF Offset */
#define HSADC_ADCSOCOVF1_SOC0OVF_MASK            ((uint32_t)0x00000001U)         /* !< SOC0 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC0 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC0 event was already
                                                                                    pending. #br# #br#  0  No SOC0 event
                                                                                    overflow. #br#  1  SOC0 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC0 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC1OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC1OVF_OFS             (1)                             /* !< SOC1OVF Offset */
#define HSADC_ADCSOCOVF1_SOC1OVF_MASK            ((uint32_t)0x00000002U)         /* !< SOC1 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC1 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC1 event was already
                                                                                    pending. #br# #br#  0  No SOC1 event
                                                                                    overflow. #br#  1  SOC1 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC1 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC2OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC2OVF_OFS             (2)                             /* !< SOC2OVF Offset */
#define HSADC_ADCSOCOVF1_SOC2OVF_MASK            ((uint32_t)0x00000004U)         /* !< SOC2 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC2 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC2 event was already
                                                                                    pending. #br# #br#  0  No SOC2 event
                                                                                    overflow. #br#  1  SOC2 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC2 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC3OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC3OVF_OFS             (3)                             /* !< SOC3OVF Offset */
#define HSADC_ADCSOCOVF1_SOC3OVF_MASK            ((uint32_t)0x00000008U)         /* !< SOC3 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC3 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC3 event was already
                                                                                    pending. #br# #br#  0  No SOC3 event
                                                                                    overflow. #br#  1  SOC3 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC3 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC4OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC4OVF_OFS             (4)                             /* !< SOC4OVF Offset */
#define HSADC_ADCSOCOVF1_SOC4OVF_MASK            ((uint32_t)0x00000010U)         /* !< SOC4 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC4 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC4 event was already
                                                                                    pending. #br# #br#  0  No SOC4 event
                                                                                    overflow. #br#  1  SOC4 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC4 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC5OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC5OVF_OFS             (5)                             /* !< SOC5OVF Offset */
#define HSADC_ADCSOCOVF1_SOC5OVF_MASK            ((uint32_t)0x00000020U)         /* !< SOC5 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC5 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC5 event was already
                                                                                    pending. #br# #br#  0  No SOC5 event
                                                                                    overflow. #br#  1  SOC5 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC5 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC6OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC6OVF_OFS             (6)                             /* !< SOC6OVF Offset */
#define HSADC_ADCSOCOVF1_SOC6OVF_MASK            ((uint32_t)0x00000040U)         /* !< SOC6 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC6 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC6 event was already
                                                                                    pending. #br# #br#  0  No SOC6 event
                                                                                    overflow. #br#  1  SOC6 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC6 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC7OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC7OVF_OFS             (7)                             /* !< SOC7OVF Offset */
#define HSADC_ADCSOCOVF1_SOC7OVF_MASK            ((uint32_t)0x00000080U)         /* !< SOC7 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC7 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC7 event was already
                                                                                    pending. #br# #br#  0  No SOC7 event
                                                                                    overflow. #br#  1  SOC7 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC7 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC8OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC8OVF_OFS             (8)                             /* !< SOC8OVF Offset */
#define HSADC_ADCSOCOVF1_SOC8OVF_MASK            ((uint32_t)0x00000100U)         /* !< SOC8 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC8 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC8 event was already
                                                                                    pending. #br# #br#  0  No SOC8 event
                                                                                    overflow. #br#  1  SOC8 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC8 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC9OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC9OVF_OFS             (9)                             /* !< SOC9OVF Offset */
#define HSADC_ADCSOCOVF1_SOC9OVF_MASK            ((uint32_t)0x00000200U)         /* !< SOC9 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC9 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC9 event was already
                                                                                    pending. #br# #br#  0  No SOC9 event
                                                                                    overflow. #br#  1  SOC9 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC9 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC10OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC10OVF_OFS            (10)                            /* !< SOC10OVF Offset */
#define HSADC_ADCSOCOVF1_SOC10OVF_MASK           ((uint32_t)0x00000400U)         /* !< SOC10 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC10 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC10 event was already
                                                                                    pending. #br# #br#  0  No SOC10 event
                                                                                    overflow. #br#  1  SOC10 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC10 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC11OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC11OVF_OFS            (11)                            /* !< SOC11OVF Offset */
#define HSADC_ADCSOCOVF1_SOC11OVF_MASK           ((uint32_t)0x00000800U)         /* !< SOC11 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC11 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC11 event was already
                                                                                    pending. #br# #br#  0  No SOC11 event
                                                                                    overflow. #br#  1  SOC11 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC11 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC12OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC12OVF_OFS            (12)                            /* !< SOC12OVF Offset */
#define HSADC_ADCSOCOVF1_SOC12OVF_MASK           ((uint32_t)0x00001000U)         /* !< SOC12 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC12 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC12 event was already
                                                                                    pending. #br# #br#  0  No SOC12 event
                                                                                    overflow. #br#  1  SOC12 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC12 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC13OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC13OVF_OFS            (13)                            /* !< SOC13OVF Offset */
#define HSADC_ADCSOCOVF1_SOC13OVF_MASK           ((uint32_t)0x00002000U)         /* !< SOC13 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC13 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC13 event was already
                                                                                    pending. #br# #br#  0  No SOC13 event
                                                                                    overflow. #br#  1  SOC13 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC13 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC14OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC14OVF_OFS            (14)                            /* !< SOC14OVF Offset */
#define HSADC_ADCSOCOVF1_SOC14OVF_MASK           ((uint32_t)0x00004000U)         /* !< SOC14 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC14 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC14 event was already
                                                                                    pending. #br# #br#  0  No SOC14 event
                                                                                    overflow. #br#  1  SOC14 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC14 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */
/* HSADC_ADCSOCOVF1[SOC15OVF] Bits */
#define HSADC_ADCSOCOVF1_SOC15OVF_OFS            (15)                            /* !< SOC15OVF Offset */
#define HSADC_ADCSOCOVF1_SOC15OVF_MASK           ((uint32_t)0x00008000U)         /* !< SOC15 Start of Conversion Overflow
                                                                                    Flag. Indicates an SOC15 event was
                                                                                    generated in hardware while an
                                                                                    existing SOC15 event was already
                                                                                    pending. #br# #br#  0  No SOC15 event
                                                                                    overflow. #br#  1  SOC15 event
                                                                                    overflow. #br# #br#An overflow
                                                                                    condition does not stop SOC15 events
                                                                                    from being processed. It simply is an
                                                                                    indication that a hardware trigger
                                                                                    was missed. */

/* HSADC_ADCSOCOVFCLR1 Bits */
/* HSADC_ADCSOCOVFCLR1[SOC0OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC0OVF_OFS          (0)                             /* !< SOC0OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC0OVF_MASK         ((uint32_t)0x00000001U)         /* !< SOC0 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC0 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC0 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC1OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC1OVF_OFS          (1)                             /* !< SOC1OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC1OVF_MASK         ((uint32_t)0x00000002U)         /* !< SOC1 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC1 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC1 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC2OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC2OVF_OFS          (2)                             /* !< SOC2OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC2OVF_MASK         ((uint32_t)0x00000004U)         /* !< SOC2 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC2 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC2 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC3OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC3OVF_OFS          (3)                             /* !< SOC3OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC3OVF_MASK         ((uint32_t)0x00000008U)         /* !< SOC3 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC3 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC3 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC4OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC4OVF_OFS          (4)                             /* !< SOC4OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC4OVF_MASK         ((uint32_t)0x00000010U)         /* !< SOC4 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC4 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC4 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC5OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC5OVF_OFS          (5)                             /* !< SOC5OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC5OVF_MASK         ((uint32_t)0x00000020U)         /* !< SOC5 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC5 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC5 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC6OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC6OVF_OFS          (6)                             /* !< SOC6OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC6OVF_MASK         ((uint32_t)0x00000040U)         /* !< SOC6 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC6 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC6 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC7OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC7OVF_OFS          (7)                             /* !< SOC7OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC7OVF_MASK         ((uint32_t)0x00000080U)         /* !< SOC7 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC7 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC7 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC8OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC8OVF_OFS          (8)                             /* !< SOC8OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC8OVF_MASK         ((uint32_t)0x00000100U)         /* !< SOC8 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC8 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC8 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC9OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC9OVF_OFS          (9)                             /* !< SOC9OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC9OVF_MASK         ((uint32_t)0x00000200U)         /* !< SOC9 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC9 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC9 overflow flag. #br# #br#If
                                                                                    software tries to set this bit on the
                                                                                    same clock cycle that hardware tries
                                                                                    to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC10OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC10OVF_OFS         (10)                            /* !< SOC10OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC10OVF_MASK        ((uint32_t)0x00000400U)         /* !< SOC10 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC10 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC10 overflow flag. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC11OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC11OVF_OFS         (11)                            /* !< SOC11OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC11OVF_MASK        ((uint32_t)0x00000800U)         /* !< SOC11 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC11 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC11 overflow flag. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC12OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC12OVF_OFS         (12)                            /* !< SOC12OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC12OVF_MASK        ((uint32_t)0x00001000U)         /* !< SOC12 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC12 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC12 overflow flag. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC13OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC13OVF_OFS         (13)                            /* !< SOC13OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC13OVF_MASK        ((uint32_t)0x00002000U)         /* !< SOC13 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC13 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC13 overflow flag. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC14OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC14OVF_OFS         (14)                            /* !< SOC14OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC14OVF_MASK        ((uint32_t)0x00004000U)         /* !< SOC14 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC14 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC14 overflow flag. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */
/* HSADC_ADCSOCOVFCLR1[SOC15OVF] Bits */
#define HSADC_ADCSOCOVFCLR1_SOC15OVF_OFS         (15)                            /* !< SOC15OVF Offset */
#define HSADC_ADCSOCOVFCLR1_SOC15OVF_MASK        ((uint32_t)0x00008000U)         /* !< SOC15 Clear Start of Conversion
                                                                                    Overflow Bit. Writing a 1 will clear
                                                                                    the SOC15 overflow flag in the
                                                                                    ADCSOCOVF1 register. Writes of 0 are
                                                                                    ignored. Reads will always return a
                                                                                    0. #br# #br#  0  No action. #br#  1
                                                                                    Clear SOC15 overflow flag. #br#
                                                                                    #br#If software tries to set this bit
                                                                                    on the same clock cycle that hardware
                                                                                    tries to set the overflow bit in the
                                                                                    ADCSOCOVF1 register, then hardware
                                                                                    has priority and the ADCSOCOVF1 bit
                                                                                    will be set.. */

/* HSADC_ADCSOC0CTL Bits */
/* HSADC_ADCSOC0CTL[CHSEL] Bits */
#define HSADC_ADCSOC0CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC0CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC0 Channel Select. Selects the
                                                                                    channel to be converted when SOC0 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC0CTL[COMPEN] Bits */
#define HSADC_ADCSOC0CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC0CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC0 Threshold comparator enable. */

/* HSADC_ADCSOC1CTL Bits */
/* HSADC_ADCSOC1CTL[CHSEL] Bits */
#define HSADC_ADCSOC1CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC1CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC1 Channel Select. Selects the
                                                                                    channel to be converted when SOC1 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC1CTL[COMPEN] Bits */
#define HSADC_ADCSOC1CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC1CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC1 Threshold comparator enable. */

/* HSADC_ADCSOC2CTL Bits */
/* HSADC_ADCSOC2CTL[CHSEL] Bits */
#define HSADC_ADCSOC2CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC2CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC2 Channel Select. Selects the
                                                                                    channel to be converted when SOC2 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC2CTL[COMPEN] Bits */
#define HSADC_ADCSOC2CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC2CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC2 Threshold comparator enable. */

/* HSADC_ADCSOC3CTL Bits */
/* HSADC_ADCSOC3CTL[CHSEL] Bits */
#define HSADC_ADCSOC3CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC3CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC3 Channel Select. Selects the
                                                                                    channel to be converted when SOC3 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC3CTL[COMPEN] Bits */
#define HSADC_ADCSOC3CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC3CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC3 Threshold comparator enable. */

/* HSADC_ADCSOC4CTL Bits */
/* HSADC_ADCSOC4CTL[CHSEL] Bits */
#define HSADC_ADCSOC4CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC4CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC4 Channel Select. Selects the
                                                                                    channel to be converted when SOC4 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC4CTL[COMPEN] Bits */
#define HSADC_ADCSOC4CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC4CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC4 Threshold comparator enable. */

/* HSADC_ADCSOC5CTL Bits */
/* HSADC_ADCSOC5CTL[CHSEL] Bits */
#define HSADC_ADCSOC5CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC5CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC5 Channel Select. Selects the
                                                                                    channel to be converted when SOC5 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC5CTL[COMPEN] Bits */
#define HSADC_ADCSOC5CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC5CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC5 Threshold comparator enable. */

/* HSADC_ADCSOC6CTL Bits */
/* HSADC_ADCSOC6CTL[CHSEL] Bits */
#define HSADC_ADCSOC6CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC6CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC6 Channel Select. Selects the
                                                                                    channel to be converted when SOC6 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC6CTL[COMPEN] Bits */
#define HSADC_ADCSOC6CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC6CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC6 Threshold comparator enable. */

/* HSADC_ADCSOC7CTL Bits */
/* HSADC_ADCSOC7CTL[CHSEL] Bits */
#define HSADC_ADCSOC7CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC7CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC7 Channel Select. Selects the
                                                                                    channel to be converted when SOC7 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC7CTL[COMPEN] Bits */
#define HSADC_ADCSOC7CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC7CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC7 Threshold comparator enable. */

/* HSADC_ADCSOC8CTL Bits */
/* HSADC_ADCSOC8CTL[CHSEL] Bits */
#define HSADC_ADCSOC8CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC8CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC8 Channel Select. Selects the
                                                                                    channel to be converted when SOC8 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC8CTL[COMPEN] Bits */
#define HSADC_ADCSOC8CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC8CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC8 Threshold comparator enable. */

/* HSADC_ADCSOC9CTL Bits */
/* HSADC_ADCSOC9CTL[CHSEL] Bits */
#define HSADC_ADCSOC9CTL_CHSEL_OFS               (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC9CTL_CHSEL_MASK              ((uint32_t)0x000F8000U)         /* !< SOC9 Channel Select. Selects the
                                                                                    channel to be converted when SOC9 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC9CTL[COMPEN] Bits */
#define HSADC_ADCSOC9CTL_COMPEN_OFS              (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC9CTL_COMPEN_MASK             ((uint32_t)0x02000000U)         /* !< SOC9 Threshold comparator enable. */

/* HSADC_ADCSOC10CTL Bits */
/* HSADC_ADCSOC10CTL[CHSEL] Bits */
#define HSADC_ADCSOC10CTL_CHSEL_OFS              (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC10CTL_CHSEL_MASK             ((uint32_t)0x000F8000U)         /* !< SOC10 Channel Select. Selects the
                                                                                    channel to be converted when SOC10 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC10CTL[COMPEN] Bits */
#define HSADC_ADCSOC10CTL_COMPEN_OFS             (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC10CTL_COMPEN_MASK            ((uint32_t)0x02000000U)         /* !< SOC10 Threshold comparator enable. */

/* HSADC_ADCSOC11CTL Bits */
/* HSADC_ADCSOC11CTL[CHSEL] Bits */
#define HSADC_ADCSOC11CTL_CHSEL_OFS              (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC11CTL_CHSEL_MASK             ((uint32_t)0x000F8000U)         /* !< SOC11 Channel Select. Selects the
                                                                                    channel to be converted when SOC11 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC11CTL[COMPEN] Bits */
#define HSADC_ADCSOC11CTL_COMPEN_OFS             (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC11CTL_COMPEN_MASK            ((uint32_t)0x02000000U)         /* !< SOC11 Threshold comparator enable. */

/* HSADC_ADCSOC12CTL Bits */
/* HSADC_ADCSOC12CTL[CHSEL] Bits */
#define HSADC_ADCSOC12CTL_CHSEL_OFS              (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC12CTL_CHSEL_MASK             ((uint32_t)0x000F8000U)         /* !< SOC12 Channel Select. Selects the
                                                                                    channel to be converted when SOC12 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC12CTL[COMPEN] Bits */
#define HSADC_ADCSOC12CTL_COMPEN_OFS             (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC12CTL_COMPEN_MASK            ((uint32_t)0x02000000U)         /* !< SOC12 Threshold comparator enable. */

/* HSADC_ADCSOC13CTL Bits */
/* HSADC_ADCSOC13CTL[CHSEL] Bits */
#define HSADC_ADCSOC13CTL_CHSEL_OFS              (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC13CTL_CHSEL_MASK             ((uint32_t)0x000F8000U)         /* !< SOC13 Channel Select. Selects the
                                                                                    channel to be converted when SOC13 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC13CTL[COMPEN] Bits */
#define HSADC_ADCSOC13CTL_COMPEN_OFS             (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC13CTL_COMPEN_MASK            ((uint32_t)0x02000000U)         /* !< SOC13 Threshold comparator enable. */

/* HSADC_ADCSOC14CTL Bits */
/* HSADC_ADCSOC14CTL[CHSEL] Bits */
#define HSADC_ADCSOC14CTL_CHSEL_OFS              (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC14CTL_CHSEL_MASK             ((uint32_t)0x000F8000U)         /* !< SOC14 Channel Select. Selects the
                                                                                    channel to be converted when SOC14 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC14CTL[COMPEN] Bits */
#define HSADC_ADCSOC14CTL_COMPEN_OFS             (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC14CTL_COMPEN_MASK            ((uint32_t)0x02000000U)         /* !< SOC14 Threshold comparator enable. */

/* HSADC_ADCSOC15CTL Bits */
/* HSADC_ADCSOC15CTL[CHSEL] Bits */
#define HSADC_ADCSOC15CTL_CHSEL_OFS              (15)                            /* !< CHSEL Offset */
#define HSADC_ADCSOC15CTL_CHSEL_MASK             ((uint32_t)0x000F8000U)         /* !< SOC15 Channel Select. Selects the
                                                                                    channel to be converted when SOC15 is
                                                                                    received by the ADC. #br#  00h
                                                                                    ADCIN0 #br#  01h  ADCIN1 #br#  02h
                                                                                    ADCIN2 #br#  03h  ADCIN3 #br#  ...
                                                                                    #br#  1Dh  ADCIN29 #br#  1Eh  ADCIN30
                                                                                    #br#  1Fh  ADCIN31 */
/* HSADC_ADCSOC15CTL[COMPEN] Bits */
#define HSADC_ADCSOC15CTL_COMPEN_OFS             (25)                            /* !< COMPEN Offset */
#define HSADC_ADCSOC15CTL_COMPEN_MASK            ((uint32_t)0x02000000U)         /* !< SOC15 Threshold comparator enable. */

/* HSADC_ADCEVTSTAT Bits */
/* HSADC_ADCEVTSTAT[PPB1TRIPHI] Bits */
#define HSADC_ADCEVTSTAT_PPB1TRIPHI_OFS          (0)                             /* !< PPB1TRIPHI Offset */
#define HSADC_ADCEVTSTAT_PPB1TRIPHI_MASK         ((uint32_t)0x00000001U)         /* !< Post Processing Block 1 Trip High
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip high event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB1TRIPLO] Bits */
#define HSADC_ADCEVTSTAT_PPB1TRIPLO_OFS          (1)                             /* !< PPB1TRIPLO Offset */
#define HSADC_ADCEVTSTAT_PPB1TRIPLO_MASK         ((uint32_t)0x00000002U)         /* !< Post Processing Block 1 Trip Low
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip low event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB1ZERO] Bits */
#define HSADC_ADCEVTSTAT_PPB1ZERO_OFS            (2)                             /* !< PPB1ZERO Offset */
#define HSADC_ADCEVTSTAT_PPB1ZERO_MASK           ((uint32_t)0x00000004U)         /* !< Post Processing Block 1 Zero
                                                                                    Crossing Flag. When set indicates the
                                                                                    ADCPPB1RESULT register has changed
                                                                                    sign. This bit is gated by EOC
                                                                                    signal. #br# #br#Note: these bits are
                                                                                    set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTSTAT[PPB1INLIMIT] Bits */
#define HSADC_ADCEVTSTAT_PPB1INLIMIT_OFS         (3)                             /* !< PPB1INLIMIT Offset */
#define HSADC_ADCEVTSTAT_PPB1INLIMIT_MASK        ((uint32_t)0x00000008U)         /* !< Post Processing Block 1 Within trip
                                                                                    limit Flag.  When set indicates a
                                                                                    digital compare within limit event
                                                                                    has occurred. This will be set when
                                                                                    the PPB result is either in between
                                                                                    or equal to the TRIPHI and TRIPLO
                                                                                    thresholds. #br# #br#Note: these bits
                                                                                    are set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTSTAT[PPB2TRIPHI] Bits */
#define HSADC_ADCEVTSTAT_PPB2TRIPHI_OFS          (4)                             /* !< PPB2TRIPHI Offset */
#define HSADC_ADCEVTSTAT_PPB2TRIPHI_MASK         ((uint32_t)0x00000010U)         /* !< Post Processing Block 2 Trip High
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip high event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB2TRIPLO] Bits */
#define HSADC_ADCEVTSTAT_PPB2TRIPLO_OFS          (5)                             /* !< PPB2TRIPLO Offset */
#define HSADC_ADCEVTSTAT_PPB2TRIPLO_MASK         ((uint32_t)0x00000020U)         /* !< Post Processing Block 2 Trip Low
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip low event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB2ZERO] Bits */
#define HSADC_ADCEVTSTAT_PPB2ZERO_OFS            (6)                             /* !< PPB2ZERO Offset */
#define HSADC_ADCEVTSTAT_PPB2ZERO_MASK           ((uint32_t)0x00000040U)         /* !< Post Processing Block 2 Zero
                                                                                    Crossing Flag. When set indicates the
                                                                                    ADCPPB2RESULT register has changed
                                                                                    sign. This bit is gated by EOC
                                                                                    signal. #br# #br#Note: these bits are
                                                                                    set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTSTAT[PPB2INLIMIT] Bits */
#define HSADC_ADCEVTSTAT_PPB2INLIMIT_OFS         (7)                             /* !< PPB2INLIMIT Offset */
#define HSADC_ADCEVTSTAT_PPB2INLIMIT_MASK        ((uint32_t)0x00000080U)         /* !< Post Processing Block 2 Within trip
                                                                                    limit Flag.  When set indicates a
                                                                                    digital compare within limit event
                                                                                    has occurred. This will be set when
                                                                                    the PPB result is either in between
                                                                                    or equal to the TRIPHI and TRIPLO
                                                                                    thresholds. #br# #br#Note: these bits
                                                                                    are set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTSTAT[PPB3TRIPHI] Bits */
#define HSADC_ADCEVTSTAT_PPB3TRIPHI_OFS          (8)                             /* !< PPB3TRIPHI Offset */
#define HSADC_ADCEVTSTAT_PPB3TRIPHI_MASK         ((uint32_t)0x00000100U)         /* !< Post Processing Block 3 Trip High
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip high event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB3TRIPLO] Bits */
#define HSADC_ADCEVTSTAT_PPB3TRIPLO_OFS          (9)                             /* !< PPB3TRIPLO Offset */
#define HSADC_ADCEVTSTAT_PPB3TRIPLO_MASK         ((uint32_t)0x00000200U)         /* !< Post Processing Block 3 Trip Low
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip low event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB3ZERO] Bits */
#define HSADC_ADCEVTSTAT_PPB3ZERO_OFS            (10)                            /* !< PPB3ZERO Offset */
#define HSADC_ADCEVTSTAT_PPB3ZERO_MASK           ((uint32_t)0x00000400U)         /* !< Post Processing Block 3 Zero
                                                                                    Crossing Flag. When set indicates the
                                                                                    ADCPPB3RESULT register has changed
                                                                                    sign. This bit is gated by EOC
                                                                                    signal. #br# #br#Note: these bits are
                                                                                    set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTSTAT[PPB3INLIMIT] Bits */
#define HSADC_ADCEVTSTAT_PPB3INLIMIT_OFS         (11)                            /* !< PPB3INLIMIT Offset */
#define HSADC_ADCEVTSTAT_PPB3INLIMIT_MASK        ((uint32_t)0x00000800U)         /* !< Post Processing Block 3 Within trip
                                                                                    limit Flag.  When set indicates a
                                                                                    digital compare within limit event
                                                                                    has occurred. This will be set when
                                                                                    the PPB result is either in between
                                                                                    or equal to the TRIPHI and TRIPLO
                                                                                    thresholds. #br# #br#Note: these bits
                                                                                    are set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTSTAT[PPB4TRIPHI] Bits */
#define HSADC_ADCEVTSTAT_PPB4TRIPHI_OFS          (12)                            /* !< PPB4TRIPHI Offset */
#define HSADC_ADCEVTSTAT_PPB4TRIPHI_MASK         ((uint32_t)0x00001000U)         /* !< Post Processing Block 4 Trip High
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip high event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB4TRIPLO] Bits */
#define HSADC_ADCEVTSTAT_PPB4TRIPLO_OFS          (13)                            /* !< PPB4TRIPLO Offset */
#define HSADC_ADCEVTSTAT_PPB4TRIPLO_MASK         ((uint32_t)0x00002000U)         /* !< Post Processing Block 4 Trip Low
                                                                                    Flag. When set indicates a digital
                                                                                    compare trip low event has occurred.
                                                                                    #br# #br#Note: these bits are set
                                                                                    even when the corresponding enable in
                                                                                    ADCEVTINTSEL is not set.  Because of
                                                                                    this, an ISR may need to examine both
                                                                                    the ADCEVTSTAT and ADCEVTINTSEL
                                                                                    registers to determine the source of
                                                                                    the interrupt.  #br# #br#Note: If
                                                                                    software sets the clear bit on the
                                                                                    same cycle that hardware is trying to
                                                                                    set the flag bit, then hardware has
                                                                                    priority */
/* HSADC_ADCEVTSTAT[PPB4ZERO] Bits */
#define HSADC_ADCEVTSTAT_PPB4ZERO_OFS            (14)                            /* !< PPB4ZERO Offset */
#define HSADC_ADCEVTSTAT_PPB4ZERO_MASK           ((uint32_t)0x00004000U)         /* !< Post Processing Block 4 Zero
                                                                                    Crossing Flag. When set indicates the
                                                                                    ADCPPB4RESULT register has changed
                                                                                    sign. This bit is gated by EOC
                                                                                    signal. #br# #br#Note: these bits are
                                                                                    set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTSTAT[PPB4INLIMIT] Bits */
#define HSADC_ADCEVTSTAT_PPB4INLIMIT_OFS         (15)                            /* !< PPB4INLIMIT Offset */
#define HSADC_ADCEVTSTAT_PPB4INLIMIT_MASK        ((uint32_t)0x00008000U)         /* !< Post Processing Block 4 Within trip
                                                                                    limit Flag.  When set indicates a
                                                                                    digital compare within limit event
                                                                                    has occurred. This will be set when
                                                                                    the PPB result is either in between
                                                                                    or equal to the TRIPHI and TRIPLO
                                                                                    thresholds. #br# #br#Note: these bits
                                                                                    are set even when the corresponding
                                                                                    enable in ADCEVTINTSEL is not set.
                                                                                    Because of this, an ISR may need to
                                                                                    examine both the ADCEVTSTAT and
                                                                                    ADCEVTINTSEL registers to determine
                                                                                    the source of the interrupt.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */

/* HSADC_ADCEVTCLR Bits */
/* HSADC_ADCEVTCLR[PPB1TRIPHI] Bits */
#define HSADC_ADCEVTCLR_PPB1TRIPHI_OFS           (0)                             /* !< PPB1TRIPHI Offset */
#define HSADC_ADCEVTCLR_PPB1TRIPHI_MASK          ((uint32_t)0x00000001U)         /* !< Post Processing Block 1 Trip High
                                                                                    Clear. Clears the corresponding trip
                                                                                    high flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB1TRIPLO] Bits */
#define HSADC_ADCEVTCLR_PPB1TRIPLO_OFS           (1)                             /* !< PPB1TRIPLO Offset */
#define HSADC_ADCEVTCLR_PPB1TRIPLO_MASK          ((uint32_t)0x00000002U)         /* !< Post Processing Block 1 Trip Low
                                                                                    Clear. Clears the corresponding trip
                                                                                    low flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB1ZERO] Bits */
#define HSADC_ADCEVTCLR_PPB1ZERO_OFS             (2)                             /* !< PPB1ZERO Offset */
#define HSADC_ADCEVTCLR_PPB1ZERO_MASK            ((uint32_t)0x00000004U)         /* !< Post Processing Block 1 Zero
                                                                                    Crossing Clear. Clears the
                                                                                    corresponding zero crossing flag in
                                                                                    the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTCLR[PPB1INLIMIT] Bits */
#define HSADC_ADCEVTCLR_PPB1INLIMIT_OFS          (3)                             /* !< PPB1INLIMIT Offset */
#define HSADC_ADCEVTCLR_PPB1INLIMIT_MASK         ((uint32_t)0x00000008U)         /* !< Post Processing Block 1 Within trip
                                                                                    limit flag Clear, Clears the
                                                                                    corresponding within trip limit flag
                                                                                    in the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTCLR[PPB2TRIPHI] Bits */
#define HSADC_ADCEVTCLR_PPB2TRIPHI_OFS           (4)                             /* !< PPB2TRIPHI Offset */
#define HSADC_ADCEVTCLR_PPB2TRIPHI_MASK          ((uint32_t)0x00000010U)         /* !< Post Processing Block 2 Trip High
                                                                                    Clear. Clears the corresponding trip
                                                                                    high flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB2TRIPLO] Bits */
#define HSADC_ADCEVTCLR_PPB2TRIPLO_OFS           (5)                             /* !< PPB2TRIPLO Offset */
#define HSADC_ADCEVTCLR_PPB2TRIPLO_MASK          ((uint32_t)0x00000020U)         /* !< Post Processing Block 2 Trip Low
                                                                                    Clear. Clears the corresponding trip
                                                                                    low flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB2ZERO] Bits */
#define HSADC_ADCEVTCLR_PPB2ZERO_OFS             (6)                             /* !< PPB2ZERO Offset */
#define HSADC_ADCEVTCLR_PPB2ZERO_MASK            ((uint32_t)0x00000040U)         /* !< Post Processing Block 2 Zero
                                                                                    Crossing Clear. Clears the
                                                                                    corresponding zero crossing flag in
                                                                                    the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTCLR[PPB2INLIMIT] Bits */
#define HSADC_ADCEVTCLR_PPB2INLIMIT_OFS          (7)                             /* !< PPB2INLIMIT Offset */
#define HSADC_ADCEVTCLR_PPB2INLIMIT_MASK         ((uint32_t)0x00000080U)         /* !< Post Processing Block 2 Within trip
                                                                                    limit flag Clear, Clears the
                                                                                    corresponding within trip limit flag
                                                                                    in the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTCLR[PPB3TRIPHI] Bits */
#define HSADC_ADCEVTCLR_PPB3TRIPHI_OFS           (8)                             /* !< PPB3TRIPHI Offset */
#define HSADC_ADCEVTCLR_PPB3TRIPHI_MASK          ((uint32_t)0x00000100U)         /* !< Post Processing Block 3 Trip High
                                                                                    Clear. Clears the corresponding trip
                                                                                    high flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB3TRIPLO] Bits */
#define HSADC_ADCEVTCLR_PPB3TRIPLO_OFS           (9)                             /* !< PPB3TRIPLO Offset */
#define HSADC_ADCEVTCLR_PPB3TRIPLO_MASK          ((uint32_t)0x00000200U)         /* !< Post Processing Block 3 Trip Low
                                                                                    Clear. Clears the corresponding trip
                                                                                    low flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB3ZERO] Bits */
#define HSADC_ADCEVTCLR_PPB3ZERO_OFS             (10)                            /* !< PPB3ZERO Offset */
#define HSADC_ADCEVTCLR_PPB3ZERO_MASK            ((uint32_t)0x00000400U)         /* !< Post Processing Block 3 Zero
                                                                                    Crossing Clear. Clears the
                                                                                    corresponding zero crossing flag in
                                                                                    the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTCLR[PPB3INLIMIT] Bits */
#define HSADC_ADCEVTCLR_PPB3INLIMIT_OFS          (11)                            /* !< PPB3INLIMIT Offset */
#define HSADC_ADCEVTCLR_PPB3INLIMIT_MASK         ((uint32_t)0x00000800U)         /* !< Post Processing Block 3 Within trip
                                                                                    limit flag Clear, Clears the
                                                                                    corresponding within trip limit flag
                                                                                    in the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTCLR[PPB4TRIPHI] Bits */
#define HSADC_ADCEVTCLR_PPB4TRIPHI_OFS           (12)                            /* !< PPB4TRIPHI Offset */
#define HSADC_ADCEVTCLR_PPB4TRIPHI_MASK          ((uint32_t)0x00001000U)         /* !< Post Processing Block 4 Trip High
                                                                                    Clear. Clears the corresponding trip
                                                                                    high flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB4TRIPLO] Bits */
#define HSADC_ADCEVTCLR_PPB4TRIPLO_OFS           (13)                            /* !< PPB4TRIPLO Offset */
#define HSADC_ADCEVTCLR_PPB4TRIPLO_MASK          ((uint32_t)0x00002000U)         /* !< Post Processing Block 4 Trip Low
                                                                                    Clear. Clears the corresponding trip
                                                                                    low flag in the ADCEVTSTAT register.
                                                                                    #br# #br#Note: If software sets the
                                                                                    clear bit on the same cycle that
                                                                                    hardware is trying to set the flag
                                                                                    bit, then hardware has priority */
/* HSADC_ADCEVTCLR[PPB4ZERO] Bits */
#define HSADC_ADCEVTCLR_PPB4ZERO_OFS             (14)                            /* !< PPB4ZERO Offset */
#define HSADC_ADCEVTCLR_PPB4ZERO_MASK            ((uint32_t)0x00004000U)         /* !< Post Processing Block 4 Zero
                                                                                    Crossing Clear. Clears the
                                                                                    corresponding zero crossing flag in
                                                                                    the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */
/* HSADC_ADCEVTCLR[PPB4INLIMIT] Bits */
#define HSADC_ADCEVTCLR_PPB4INLIMIT_OFS          (15)                            /* !< PPB4INLIMIT Offset */
#define HSADC_ADCEVTCLR_PPB4INLIMIT_MASK         ((uint32_t)0x00008000U)         /* !< Post Processing Block 4 Within trip
                                                                                    limit flag Clear, Clears the
                                                                                    corresponding within trip limit flag
                                                                                    in the ADCEVTSTAT register. #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority */

/* HSADC_ADCEVTSEL Bits */
/* HSADC_ADCEVTSEL[PPB1TRIPHI] Bits */
#define HSADC_ADCEVTSEL_PPB1TRIPHI_OFS           (0)                             /* !< PPB1TRIPHI Offset */
#define HSADC_ADCEVTSEL_PPB1TRIPHI_MASK          ((uint32_t)0x00000001U)         /* !< Post Processing Block 1 Trip High
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip high
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB1TRIPLO] Bits */
#define HSADC_ADCEVTSEL_PPB1TRIPLO_OFS           (1)                             /* !< PPB1TRIPLO Offset */
#define HSADC_ADCEVTSEL_PPB1TRIPLO_MASK          ((uint32_t)0x00000002U)         /* !< Post Processing Block 1 Trip Low
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip low
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB1ZERO] Bits */
#define HSADC_ADCEVTSEL_PPB1ZERO_OFS             (2)                             /* !< PPB1ZERO Offset */
#define HSADC_ADCEVTSEL_PPB1ZERO_MASK            ((uint32_t)0x00000004U)         /* !< Post Processing Block 1 Zero
                                                                                    Crossing Event Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event signal to the PWM blocks. The
                                                                                    flag must be cleared before it can
                                                                                    produce additional events to the PWM
                                                                                    blocks. */
/* HSADC_ADCEVTSEL[PPB1INLIMIT] Bits */
#define HSADC_ADCEVTSEL_PPB1INLIMIT_OFS          (3)                             /* !< PPB1INLIMIT Offset */
#define HSADC_ADCEVTSEL_PPB1INLIMIT_MASK         ((uint32_t)0x00000008U)         /* !< Post Processing Block 1 Within trip
                                                                                    limit event enable. Setting this bit
                                                                                    allows the corresponding rising zero
                                                                                    crossing flag to activate the event
                                                                                    signal to the PWM blocks. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB2TRIPHI] Bits */
#define HSADC_ADCEVTSEL_PPB2TRIPHI_OFS           (4)                             /* !< PPB2TRIPHI Offset */
#define HSADC_ADCEVTSEL_PPB2TRIPHI_MASK          ((uint32_t)0x00000010U)         /* !< Post Processing Block 2 Trip High
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip high
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB2TRIPLO] Bits */
#define HSADC_ADCEVTSEL_PPB2TRIPLO_OFS           (5)                             /* !< PPB2TRIPLO Offset */
#define HSADC_ADCEVTSEL_PPB2TRIPLO_MASK          ((uint32_t)0x00000020U)         /* !< Post Processing Block 2 Trip Low
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip low
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB2ZERO] Bits */
#define HSADC_ADCEVTSEL_PPB2ZERO_OFS             (6)                             /* !< PPB2ZERO Offset */
#define HSADC_ADCEVTSEL_PPB2ZERO_MASK            ((uint32_t)0x00000040U)         /* !< Post Processing Block 2 Zero
                                                                                    Crossing Event Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event signal to the PWM blocks. The
                                                                                    flag must be cleared before it can
                                                                                    produce additional events to the PWM
                                                                                    blocks. */
/* HSADC_ADCEVTSEL[PPB2INLIMIT] Bits */
#define HSADC_ADCEVTSEL_PPB2INLIMIT_OFS          (7)                             /* !< PPB2INLIMIT Offset */
#define HSADC_ADCEVTSEL_PPB2INLIMIT_MASK         ((uint32_t)0x00000080U)         /* !< Post Processing Block 2 Within trip
                                                                                    limit event enable. Setting this bit
                                                                                    allows the corresponding rising zero
                                                                                    crossing flag to activate the event
                                                                                    signal to the PWM blocks. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB3TRIPHI] Bits */
#define HSADC_ADCEVTSEL_PPB3TRIPHI_OFS           (8)                             /* !< PPB3TRIPHI Offset */
#define HSADC_ADCEVTSEL_PPB3TRIPHI_MASK          ((uint32_t)0x00000100U)         /* !< Post Processing Block 3 Trip High
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip high
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB3TRIPLO] Bits */
#define HSADC_ADCEVTSEL_PPB3TRIPLO_OFS           (9)                             /* !< PPB3TRIPLO Offset */
#define HSADC_ADCEVTSEL_PPB3TRIPLO_MASK          ((uint32_t)0x00000200U)         /* !< Post Processing Block 3 Trip Low
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip low
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB3ZERO] Bits */
#define HSADC_ADCEVTSEL_PPB3ZERO_OFS             (10)                            /* !< PPB3ZERO Offset */
#define HSADC_ADCEVTSEL_PPB3ZERO_MASK            ((uint32_t)0x00000400U)         /* !< Post Processing Block 3 Zero
                                                                                    Crossing Event Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event signal to the PWM blocks. The
                                                                                    flag must be cleared before it can
                                                                                    produce additional events to the PWM
                                                                                    blocks. */
/* HSADC_ADCEVTSEL[PPB3INLIMIT] Bits */
#define HSADC_ADCEVTSEL_PPB3INLIMIT_OFS          (11)                            /* !< PPB3INLIMIT Offset */
#define HSADC_ADCEVTSEL_PPB3INLIMIT_MASK         ((uint32_t)0x00000800U)         /* !< Post Processing Block 3 Within trip
                                                                                    limit event enable. Setting this bit
                                                                                    allows the corresponding rising zero
                                                                                    crossing flag to activate the event
                                                                                    signal to the PWM blocks. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB4TRIPHI] Bits */
#define HSADC_ADCEVTSEL_PPB4TRIPHI_OFS           (12)                            /* !< PPB4TRIPHI Offset */
#define HSADC_ADCEVTSEL_PPB4TRIPHI_MASK          ((uint32_t)0x00001000U)         /* !< Post Processing Block 4 Trip High
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip high
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB4TRIPLO] Bits */
#define HSADC_ADCEVTSEL_PPB4TRIPLO_OFS           (13)                            /* !< PPB4TRIPLO Offset */
#define HSADC_ADCEVTSEL_PPB4TRIPLO_MASK          ((uint32_t)0x00002000U)         /* !< Post Processing Block 4 Trip Low
                                                                                    Event Enable. Setting this bit allows
                                                                                    the corresponding rising trip low
                                                                                    flag to activate the event signal to
                                                                                    the PWM blocks. The flag must be
                                                                                    cleared before it can produce
                                                                                    additional events to the PWM blocks. */
/* HSADC_ADCEVTSEL[PPB4ZERO] Bits */
#define HSADC_ADCEVTSEL_PPB4ZERO_OFS             (14)                            /* !< PPB4ZERO Offset */
#define HSADC_ADCEVTSEL_PPB4ZERO_MASK            ((uint32_t)0x00004000U)         /* !< Post Processing Block 4 Zero
                                                                                    Crossing Event Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event signal to the PWM blocks. The
                                                                                    flag must be cleared before it can
                                                                                    produce additional events to the PWM
                                                                                    blocks. */
/* HSADC_ADCEVTSEL[PPB4INLIMIT] Bits */
#define HSADC_ADCEVTSEL_PPB4INLIMIT_OFS          (15)                            /* !< PPB4INLIMIT Offset */
#define HSADC_ADCEVTSEL_PPB4INLIMIT_MASK         ((uint32_t)0x00008000U)         /* !< Post Processing Block 4 Within trip
                                                                                    limit event enable. Setting this bit
                                                                                    allows the corresponding rising zero
                                                                                    crossing flag to activate the event
                                                                                    signal to the PWM blocks. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional events to the PWM blocks. */

/* HSADC_ADCEVTINTSEL Bits */
/* HSADC_ADCEVTINTSEL[PPB1TRIPHI] Bits */
#define HSADC_ADCEVTINTSEL_PPB1TRIPHI_OFS        (0)                             /* !< PPB1TRIPHI Offset */
#define HSADC_ADCEVTINTSEL_PPB1TRIPHI_MASK       ((uint32_t)0x00000001U)         /* !< Post Processing Block 1 Trip High
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    high flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB1TRIPLO] Bits */
#define HSADC_ADCEVTINTSEL_PPB1TRIPLO_OFS        (1)                             /* !< PPB1TRIPLO Offset */
#define HSADC_ADCEVTINTSEL_PPB1TRIPLO_MASK       ((uint32_t)0x00000002U)         /* !< Post Processing Block 1 Trip Low
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    low flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB1ZERO] Bits */
#define HSADC_ADCEVTINTSEL_PPB1ZERO_OFS          (2)                             /* !< PPB1ZERO Offset */
#define HSADC_ADCEVTINTSEL_PPB1ZERO_MASK         ((uint32_t)0x00000004U)         /* !< Post Processing Block 1 Zero
                                                                                    Crossing Interrupt Enable. Setting
                                                                                    this bit allows the corresponding
                                                                                    rising zero crossing flag to activate
                                                                                    the event interrupt signal to the
                                                                                    PIE. The flag must be cleared before
                                                                                    it can produce additional interrupts
                                                                                    to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB1INLIMIT] Bits */
#define HSADC_ADCEVTINTSEL_PPB1INLIMIT_OFS       (3)                             /* !< PPB1INLIMIT Offset */
#define HSADC_ADCEVTINTSEL_PPB1INLIMIT_MASK      ((uint32_t)0x00000008U)         /* !< Post Processing Block 1 Within trip
                                                                                    limit Interrupt Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event interrupt signal to the PIE.
                                                                                    The flag must be cleared before it
                                                                                    can produce additional interrupts to
                                                                                    the PIE. */
/* HSADC_ADCEVTINTSEL[PPB2TRIPHI] Bits */
#define HSADC_ADCEVTINTSEL_PPB2TRIPHI_OFS        (4)                             /* !< PPB2TRIPHI Offset */
#define HSADC_ADCEVTINTSEL_PPB2TRIPHI_MASK       ((uint32_t)0x00000010U)         /* !< Post Processing Block 2 Trip High
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    high flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB2TRIPLO] Bits */
#define HSADC_ADCEVTINTSEL_PPB2TRIPLO_OFS        (5)                             /* !< PPB2TRIPLO Offset */
#define HSADC_ADCEVTINTSEL_PPB2TRIPLO_MASK       ((uint32_t)0x00000020U)         /* !< Post Processing Block 2 Trip Low
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    low flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB2ZERO] Bits */
#define HSADC_ADCEVTINTSEL_PPB2ZERO_OFS          (6)                             /* !< PPB2ZERO Offset */
#define HSADC_ADCEVTINTSEL_PPB2ZERO_MASK         ((uint32_t)0x00000040U)         /* !< Post Processing Block 2 Zero
                                                                                    Crossing Interrupt Enable. Setting
                                                                                    this bit allows the corresponding
                                                                                    rising zero crossing flag to activate
                                                                                    the event interrupt signal to the
                                                                                    PIE. The flag must be cleared before
                                                                                    it can produce additional interrupts
                                                                                    to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB2INLIMIT] Bits */
#define HSADC_ADCEVTINTSEL_PPB2INLIMIT_OFS       (7)                             /* !< PPB2INLIMIT Offset */
#define HSADC_ADCEVTINTSEL_PPB2INLIMIT_MASK      ((uint32_t)0x00000080U)         /* !< Post Processing Block 2 Within trip
                                                                                    limit Interrupt Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event interrupt signal to the PIE.
                                                                                    The flag must be cleared before it
                                                                                    can produce additional interrupts to
                                                                                    the PIE. */
/* HSADC_ADCEVTINTSEL[PPB3TRIPHI] Bits */
#define HSADC_ADCEVTINTSEL_PPB3TRIPHI_OFS        (8)                             /* !< PPB3TRIPHI Offset */
#define HSADC_ADCEVTINTSEL_PPB3TRIPHI_MASK       ((uint32_t)0x00000100U)         /* !< Post Processing Block 3 Trip High
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    high flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB3TRIPLO] Bits */
#define HSADC_ADCEVTINTSEL_PPB3TRIPLO_OFS        (9)                             /* !< PPB3TRIPLO Offset */
#define HSADC_ADCEVTINTSEL_PPB3TRIPLO_MASK       ((uint32_t)0x00000200U)         /* !< Post Processing Block 3 Trip Low
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    low flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB3ZERO] Bits */
#define HSADC_ADCEVTINTSEL_PPB3ZERO_OFS          (10)                            /* !< PPB3ZERO Offset */
#define HSADC_ADCEVTINTSEL_PPB3ZERO_MASK         ((uint32_t)0x00000400U)         /* !< Post Processing Block 3 Zero
                                                                                    Crossing Interrupt Enable. Setting
                                                                                    this bit allows the corresponding
                                                                                    rising zero crossing flag to activate
                                                                                    the event interrupt signal to the
                                                                                    PIE. The flag must be cleared before
                                                                                    it can produce additional interrupts
                                                                                    to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB3INLIMIT] Bits */
#define HSADC_ADCEVTINTSEL_PPB3INLIMIT_OFS       (11)                            /* !< PPB3INLIMIT Offset */
#define HSADC_ADCEVTINTSEL_PPB3INLIMIT_MASK      ((uint32_t)0x00000800U)         /* !< Post Processing Block 3 Within trip
                                                                                    limit Interrupt Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event interrupt signal to the PIE.
                                                                                    The flag must be cleared before it
                                                                                    can produce additional interrupts to
                                                                                    the PIE. */
/* HSADC_ADCEVTINTSEL[PPB4TRIPHI] Bits */
#define HSADC_ADCEVTINTSEL_PPB4TRIPHI_OFS        (12)                            /* !< PPB4TRIPHI Offset */
#define HSADC_ADCEVTINTSEL_PPB4TRIPHI_MASK       ((uint32_t)0x00001000U)         /* !< Post Processing Block 4 Trip High
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    high flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB4TRIPLO] Bits */
#define HSADC_ADCEVTINTSEL_PPB4TRIPLO_OFS        (13)                            /* !< PPB4TRIPLO Offset */
#define HSADC_ADCEVTINTSEL_PPB4TRIPLO_MASK       ((uint32_t)0x00002000U)         /* !< Post Processing Block 4 Trip Low
                                                                                    Interrupt Enable. Setting this bit
                                                                                    allows the corresponding rising trip
                                                                                    low flag to activate the event
                                                                                    interrupt signal to the PIE. The flag
                                                                                    must be cleared before it can produce
                                                                                    additional interrupts to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB4ZERO] Bits */
#define HSADC_ADCEVTINTSEL_PPB4ZERO_OFS          (14)                            /* !< PPB4ZERO Offset */
#define HSADC_ADCEVTINTSEL_PPB4ZERO_MASK         ((uint32_t)0x00004000U)         /* !< Post Processing Block 4 Zero
                                                                                    Crossing Interrupt Enable. Setting
                                                                                    this bit allows the corresponding
                                                                                    rising zero crossing flag to activate
                                                                                    the event interrupt signal to the
                                                                                    PIE. The flag must be cleared before
                                                                                    it can produce additional interrupts
                                                                                    to the PIE. */
/* HSADC_ADCEVTINTSEL[PPB4INLIMIT] Bits */
#define HSADC_ADCEVTINTSEL_PPB4INLIMIT_OFS       (15)                            /* !< PPB4INLIMIT Offset */
#define HSADC_ADCEVTINTSEL_PPB4INLIMIT_MASK      ((uint32_t)0x00008000U)         /* !< Post Processing Block 4 Within trip
                                                                                    limit Interrupt Enable. Setting this
                                                                                    bit allows the corresponding rising
                                                                                    zero crossing flag to activate the
                                                                                    event interrupt signal to the PIE.
                                                                                    The flag must be cleared before it
                                                                                    can produce additional interrupts to
                                                                                    the PIE. */

/* HSADC_ADCOSDETECT Bits */
/* HSADC_ADCOSDETECT[DETECTCFG] Bits */
#define HSADC_ADCOSDETECT_DETECTCFG_OFS          (0)                             /* !< DETECTCFG Offset */
#define HSADC_ADCOSDETECT_DETECTCFG_MASK         ((uint32_t)0x00000007U)         /* !< ADC Opens and Shorts Detect
                                                                                    Configuration. This bit field defines
                                                                                    the open/shorts detection circuit
                                                                                    state. #br# #br#  0h  Open/Shorts
                                                                                    detection circuit is disabled. #br#
                                                                                    1h  Open/Shorts detection circuit is
                                                                                    enabled at zero scale. #br#  2h
                                                                                    Open/Shorts detection circuit is
                                                                                    enabled at full scale. #br#  3h
                                                                                    Open/Shorts detection circuit is
                                                                                    enabled at (nominal) 5/12 scale. #br#
                                                                                    4h  Open/Shorts detection circuit is
                                                                                    enabled at (nominal) 7/12 scale. #br#
                                                                                    5h  Open/Shorts detection circuit is
                                                                                    enabled with a (nominal) 5K pulldown
                                                                                    to VSSA. #br#  6h  Open/Shorts
                                                                                    detection circuit is enabled with a
                                                                                    (nominal) 5K pullup to VDDA. #br#  7h
                                                                                    Open/Shorts detection circuit is
                                                                                    enabled with a (nominal) 7K pulldown
                                                                                    to VSSA. */

/* HSADC_ADCREV Bits */
/* HSADC_ADCREV[TYPE] Bits */
#define HSADC_ADCREV_TYPE_OFS                    (0)                             /* !< TYPE Offset */
#define HSADC_ADCREV_TYPE_MASK                   ((uint32_t)0x000000FFU)         /* !< ADC Type. Always set to 6 for this
                                                                                    HSADC-12b. */
/* HSADC_ADCREV[REV] Bits */
#define HSADC_ADCREV_REV_OFS                     (8)                             /* !< REV Offset */
#define HSADC_ADCREV_REV_MASK                    ((uint32_t)0xFFFFFF00U)         /* !< ADC Revision. To allow
                                                                                    documentation of differences between
                                                                                    revisions. First version is labeled
                                                                                    as 00h. */

/* HSADC_ADCOFFTRIM Bits */
/* HSADC_ADCOFFTRIM[OFFTRIM] Bits */
#define HSADC_ADCOFFTRIM_OFFTRIM_OFS             (0)                             /* !< OFFTRIM Offset */
#define HSADC_ADCOFFTRIM_OFFTRIM_MASK            ((uint32_t)0x000000FFU)         /* !< ADC Offset Trim #br# #br#Adjusts
                                                                                    the conversion results of the
                                                                                    converter up #br#or down to account
                                                                                    for offset error in the ADC. A
                                                                                    factory trim setting will be loaded
                                                                                    during device boot. #br# #br#Offset
                                                                                    can be corrected in the range of +7
                                                                                    to -8 LSBs. Value is 16*Offset in
                                                                                    8-bit 2's complement: #br# #br#7 LSB
                                                                                    (16*7) = 112 #br#6 LSB (16*6) = 96
                                                                                    #br#5 LSB (16*5) = 80 #br#4 LSB
                                                                                    (16*4) = 64 #br#3 LSB (16*3) = 48
                                                                                    #br#2 LSB (16*2) = 32 #br#1 LSB
                                                                                    (16*1) = 16 #br#0 LSB (16*0) = 0
                                                                                    #br#-1 LSB (16*(-1)) = 240 #br#:
                                                                                    #br#: #br#-7LSB(16*(-7)) = 144 */

/* HSADC_ADCCONFIG Bits */
/* HSADC_ADCCONFIG[CONFIG] Bits */
#define HSADC_ADCCONFIG_CONFIG_OFS               (0)                             /* !< CONFIG Offset */
#define HSADC_ADCCONFIG_CONFIG_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< ADC Configuration. This bit field
                                                                                    is used for TI internal
                                                                                    testing/debugging. */

/* HSADC_ADCPPB1CONFIG Bits */
/* HSADC_ADCPPB1CONFIG[CBCEN] Bits */
#define HSADC_ADCPPB1CONFIG_CBCEN_OFS            (5)                             /* !< CBCEN Offset */
#define HSADC_ADCPPB1CONFIG_CBCEN_MASK           ((uint32_t)0x00000020U)         /* !< ADC Post Processing Block Cycle By
                                                                                    Cycle Enable. When set, this bit
                                                                                    enables the post conversion hardware
                                                                                    processing circuit to automatically
                                                                                    clear the ADCEVTSTAT on a conversion
                                                                                    if the event condition is no longer
                                                                                    present. */

/* HSADC_ADCPPB1CONFIG[CBCEN] Bits */
#define HSADC_ADCPPB1CONFIG_TWOSCOMPEN_OFS       (7)                             /* !< TWOSCOMPEN Offset */
#define HSADC_ADCPPB1CONFIG_TWOSCOMPEN_MASK      ((uint32_t)0x00000080U)         /* !< ADC Post Processing Block 1 Two's
                                                                                    Complement Enable. When set this bit
                                                                                    enables the post conversion hardware
                                                                                    processing circuit that performs a
                                                                                    two's complement on the output of the
                                                                                    offset/reference subtraction unit
                                                                                    before storing the result in the
                                                                                    ADCPPB1RESULT register. */

/* HSADC_ADCPPB1OFFCAL Bits */
/* HSADC_ADCPPB1OFFCAL[OFFCAL] Bits */
#define HSADC_ADCPPB1OFFCAL_OFFCAL_OFS           (0)                             /* !< OFFCAL Offset */
#define HSADC_ADCPPB1OFFCAL_OFFCAL_MASK          ((uint32_t)0x0000003FU)         /* !< ADC Post Processing Block 1 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to digitally remove any system
                                                                                    level offset inherent in the ADCIN
                                                                                    circuit. This 6-bit signed value is
                                                                                    subtracted from the ADC output before
                                                                                    being stored in the ADCRESULT
                                                                                    register. #br# #br#  00h  No change.
                                                                                    The ADC output is stored directly
                                                                                    into ADCRESULT. #br#  01h  ADC output
                                                                                    - 1 is stored into ADCRESULT. #br#
                                                                                    02h  ADC output - 2 is stored into
                                                                                    ADCRESULT. #br#  ... #br#  20h  ADC
                                                                                    output + 32 is stored into ADCRESULT.
                                                                                    #br#  ... #br#  3Fh  ADC output + 1
                                                                                    is stored into ADCRESULT. #br#
                                                                                    #br#NOTE: The subtraction will
                                                                                    saturate at 0000h and 0FFFh before
                                                                                    being stored into the ADCRESULT
                                                                                    register. #br# #br#Note: in the case
                                                                                    that multiple PPBs point to the same
                                                                                    SOC, only the OFFCAL of the lowest
                                                                                    numbered PPB will be applied. */

/* HSADC_ADCPPB1OFFREF Bits */
/* HSADC_ADCPPB1OFFREF[OFFREF] Bits */
#define HSADC_ADCPPB1OFFREF_OFFREF_OFS           (0)                             /* !< OFFREF Offset */
#define HSADC_ADCPPB1OFFREF_OFFREF_MASK          ((uint32_t)0x00000FFFU)         /* !< ADC Post Processing Block 1 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to either calculate the feedback
                                                                                    error or convert a unipolar signal to
                                                                                    bipolar by subtracting a reference
                                                                                    value. This 12-bit unsigned value is
                                                                                    subtracted from the ADCRESULT
                                                                                    register before being passed through
                                                                                    an optional two's complement function
                                                                                    and stored in the ADCPPB1RESULT
                                                                                    register. This subtraction is not
                                                                                    saturated. #br# #br#  0000h  No
                                                                                    change. The ADCRESULT value is passed
                                                                                    on. #br#  001h  ADCRESULT - 1 is
                                                                                    passed on. #br#  002h  ADCRESULT - 2
                                                                                    is passed on. #br#  ... #br#  800h
                                                                                    ADCRESULT - 2048 is passed on. #br#
                                                                                    ... #br#  FFFh  ADCRESULT - 4096 is
                                                                                    passed on. */

/* HSADC_ADCPPB1TRIPHI Bits */
/* HSADC_ADCPPB1TRIPHI[LIMITHI] Bits */
#define HSADC_ADCPPB1TRIPHI_LIMITHI_OFS          (0)                             /* !< LIMITHI Offset */
#define HSADC_ADCPPB1TRIPHI_LIMITHI_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 1 Trip
                                                                                    High Limit. This value sets the
                                                                                    digital comparator trip high limit.
                                                                                    #br# #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPHI[15:13] will be ignored */

/* HSADC_ADCPPB1TRIPLO Bits */
/* HSADC_ADCPPB1TRIPLO[LIMITLO] Bits */
#define HSADC_ADCPPB1TRIPLO_LIMITLO_OFS          (0)                             /* !< LIMITLO Offset */
#define HSADC_ADCPPB1TRIPLO_LIMITLO_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 1 Trip
                                                                                    High Low Limit. This value sets the
                                                                                    digital comparator trip low limit if
                                                                                    ADCPPB1TRIPLO.LIMITLO2EN = 1.  #br#
                                                                                    #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPLO[15:13] will be ignored in 12
                                                                                    bit mode */

/* HSADC_ADCPPB2CONFIG Bits */
/* HSADC_ADCPPB2CONFIG[CBCEN] Bits */
#define HSADC_ADCPPB2CONFIG_CBCEN_OFS            (5)                             /* !< CBCEN Offset */
#define HSADC_ADCPPB2CONFIG_CBCEN_MASK           ((uint32_t)0x00000020U)         /* !< ADC Post Processing Block Cycle By
                                                                                    Cycle Enable. When set, this bit
                                                                                    enables the post conversion hardware
                                                                                    processing circuit to automatically
                                                                                    clear the ADCEVTSTAT on a conversion
                                                                                    if the event condition is no longer
                                                                                    present. */

/* HSADC_ADCPPB2OFFCAL Bits */
/* HSADC_ADCPPB2OFFCAL[OFFCAL] Bits */
#define HSADC_ADCPPB2OFFCAL_OFFCAL_OFS           (0)                             /* !< OFFCAL Offset */
#define HSADC_ADCPPB2OFFCAL_OFFCAL_MASK          ((uint32_t)0x0000003FU)         /* !< ADC Post Processing Block 2 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to digitally remove any system
                                                                                    level offset inherent in the ADCIN
                                                                                    circuit. This 6-bit signed value is
                                                                                    subtracted from the ADC output before
                                                                                    being stored in the ADCRESULT
                                                                                    register. #br# #br#  00h  No change.
                                                                                    The ADC output is stored directly
                                                                                    into ADCRESULT. #br#  01h  ADC output
                                                                                    - 1 is stored into ADCRESULT. #br#
                                                                                    02h  ADC output - 2 is stored into
                                                                                    ADCRESULT. #br#  ... #br#  20h  ADC
                                                                                    output + 32 is stored into ADCRESULT.
                                                                                    #br#  ... #br#  3Fh  ADC output + 1
                                                                                    is stored into ADCRESULT. #br#
                                                                                    #br#NOTE: The subtraction will
                                                                                    saturate at 0000h and 0FFFh before
                                                                                    being stored into the ADCRESULT
                                                                                    register. #br# #br#Note: in the case
                                                                                    that multiple PPBs point to the same
                                                                                    SOC, only the OFFCAL of the lowest
                                                                                    numbered PPB will be applied. */

/* HSADC_ADCPPB2OFFREF Bits */
/* HSADC_ADCPPB2OFFREF[OFFREF] Bits */
#define HSADC_ADCPPB2OFFREF_OFFREF_OFS           (0)                             /* !< OFFREF Offset */
#define HSADC_ADCPPB2OFFREF_OFFREF_MASK          ((uint32_t)0x00000FFFU)         /* !< ADC Post Processing Block 2 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to either calculate the feedback
                                                                                    error or convert a unipolar signal to
                                                                                    bipolar by subtracting a reference
                                                                                    value. This 12-bit unsigned value is
                                                                                    subtracted from the ADCRESULT
                                                                                    register before being passed through
                                                                                    an optional two's complement function
                                                                                    and stored in the ADCPPB2RESULT
                                                                                    register. This subtraction is not
                                                                                    saturated. #br# #br#  0000h  No
                                                                                    change. The ADCRESULT value is passed
                                                                                    on. #br#  001h  ADCRESULT - 1 is
                                                                                    passed on. #br#  002h  ADCRESULT - 2
                                                                                    is passed on. #br#  ... #br#  800h
                                                                                    ADCRESULT - 2048 is passed on. #br#
                                                                                    ... #br#  FFFh  ADCRESULT - 4096 is
                                                                                    passed on. */

/* HSADC_ADCPPB2TRIPHI Bits */
/* HSADC_ADCPPB2TRIPHI[LIMITHI] Bits */
#define HSADC_ADCPPB2TRIPHI_LIMITHI_OFS          (0)                             /* !< LIMITHI Offset */
#define HSADC_ADCPPB2TRIPHI_LIMITHI_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 2 Trip
                                                                                    High Limit. This value sets the
                                                                                    digital comparator trip high limit.
                                                                                    #br# #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPHI[15:13] will be ignored */

/* HSADC_ADCPPB2TRIPLO Bits */
/* HSADC_ADCPPB2TRIPLO[LIMITLO] Bits */
#define HSADC_ADCPPB2TRIPLO_LIMITLO_OFS          (0)                             /* !< LIMITLO Offset */
#define HSADC_ADCPPB2TRIPLO_LIMITLO_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 2 Trip
                                                                                    High Low Limit. This value sets the
                                                                                    digital comparator trip low limit if
                                                                                    ADCPPB2TRIPLO.LIMITLO2EN = 1.  #br#
                                                                                    #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPLO[15:13] will be ignored in 12
                                                                                    bit mode */

/* HSADC_ADCPPB3CONFIG Bits */
/* HSADC_ADCPPB3CONFIG[CBCEN] Bits */
#define HSADC_ADCPPB3CONFIG_CBCEN_OFS            (5)                             /* !< CBCEN Offset */
#define HSADC_ADCPPB3CONFIG_CBCEN_MASK           ((uint32_t)0x00000020U)         /* !< ADC Post Processing Block Cycle By
                                                                                    Cycle Enable. When set, this bit
                                                                                    enables the post conversion hardware
                                                                                    processing circuit to automatically
                                                                                    clear the ADCEVTSTAT on a conversion
                                                                                    if the event condition is no longer
                                                                                    present. */

/* HSADC_ADCPPB3OFFCAL Bits */
/* HSADC_ADCPPB3OFFCAL[OFFCAL] Bits */
#define HSADC_ADCPPB3OFFCAL_OFFCAL_OFS           (0)                             /* !< OFFCAL Offset */
#define HSADC_ADCPPB3OFFCAL_OFFCAL_MASK          ((uint32_t)0x0000003FU)         /* !< ADC Post Processing Block 3 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to digitally remove any system
                                                                                    level offset inherent in the ADCIN
                                                                                    circuit. This 6-bit signed value is
                                                                                    subtracted from the ADC output before
                                                                                    being stored in the ADCRESULT
                                                                                    register. #br# #br#  00h  No change.
                                                                                    The ADC output is stored directly
                                                                                    into ADCRESULT. #br#  01h  ADC output
                                                                                    - 1 is stored into ADCRESULT. #br#
                                                                                    02h  ADC output - 2 is stored into
                                                                                    ADCRESULT. #br#  ... #br#  20h  ADC
                                                                                    output + 32 is stored into ADCRESULT.
                                                                                    #br#  ... #br#  3Fh  ADC output + 1
                                                                                    is stored into ADCRESULT. #br#
                                                                                    #br#NOTE: The subtraction will
                                                                                    saturate at 0000h and 0FFFh before
                                                                                    being stored into the ADCRESULT
                                                                                    register. #br# #br#Note: in the case
                                                                                    that multiple PPBs point to the same
                                                                                    SOC, only the OFFCAL of the lowest
                                                                                    numbered PPB will be applied. */

/* HSADC_ADCPPB3OFFREF Bits */
/* HSADC_ADCPPB3OFFREF[OFFREF] Bits */
#define HSADC_ADCPPB3OFFREF_OFFREF_OFS           (0)                             /* !< OFFREF Offset */
#define HSADC_ADCPPB3OFFREF_OFFREF_MASK          ((uint32_t)0x00000FFFU)         /* !< ADC Post Processing Block 3 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to either calculate the feedback
                                                                                    error or convert a unipolar signal to
                                                                                    bipolar by subtracting a reference
                                                                                    value. This 12-bit unsigned value is
                                                                                    subtracted from the ADCRESULT
                                                                                    register before being passed through
                                                                                    an optional two's complement function
                                                                                    and stored in the ADCPPB3RESULT
                                                                                    register. This subtraction is not
                                                                                    saturated. #br# #br#  0000h  No
                                                                                    change. The ADCRESULT value is passed
                                                                                    on. #br#  001h  ADCRESULT - 1 is
                                                                                    passed on. #br#  002h  ADCRESULT - 2
                                                                                    is passed on. #br#  ... #br#  800h
                                                                                    ADCRESULT - 2048 is passed on. #br#
                                                                                    ... #br#  FFFh  ADCRESULT - 4096 is
                                                                                    passed on. */

/* HSADC_ADCPPB3TRIPHI Bits */
/* HSADC_ADCPPB3TRIPHI[LIMITHI] Bits */
#define HSADC_ADCPPB3TRIPHI_LIMITHI_OFS          (0)                             /* !< LIMITHI Offset */
#define HSADC_ADCPPB3TRIPHI_LIMITHI_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 3 Trip
                                                                                    High Limit. This value sets the
                                                                                    digital comparator trip high limit.
                                                                                    #br# #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPHI[15:13] will be ignored */

/* HSADC_ADCPPB3TRIPLO Bits */
/* HSADC_ADCPPB3TRIPLO[LIMITLO] Bits */
#define HSADC_ADCPPB3TRIPLO_LIMITLO_OFS          (0)                             /* !< LIMITLO Offset */
#define HSADC_ADCPPB3TRIPLO_LIMITLO_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 3 Trip
                                                                                    High Low Limit. This value sets the
                                                                                    digital comparator trip low limit if
                                                                                    ADCPPB3TRIPLO.LIMITLO2EN = 1.  #br#
                                                                                    #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPLO[15:13] will be ignored in 12
                                                                                    bit mode */

/* HSADC_ADCPPB4CONFIG Bits */
/* HSADC_ADCPPB4CONFIG[CBCEN] Bits */
#define HSADC_ADCPPB4CONFIG_CBCEN_OFS            (5)                             /* !< CBCEN Offset */
#define HSADC_ADCPPB4CONFIG_CBCEN_MASK           ((uint32_t)0x00000020U)         /* !< ADC Post Processing Block Cycle By
                                                                                    Cycle Enable. When set, this bit
                                                                                    enables the post conversion hardware
                                                                                    processing circuit to automatically
                                                                                    clear the ADCEVTSTAT on a conversion
                                                                                    if the event condition is no longer
                                                                                    present. */

/* HSADC_ADCPPB4OFFCAL Bits */
/* HSADC_ADCPPB4OFFCAL[OFFCAL] Bits */
#define HSADC_ADCPPB4OFFCAL_OFFCAL_OFS           (0)                             /* !< OFFCAL Offset */
#define HSADC_ADCPPB4OFFCAL_OFFCAL_MASK          ((uint32_t)0x0000003FU)         /* !< ADC Post Processing Block 4 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to digitally remove any system
                                                                                    level offset inherent in the ADCIN
                                                                                    circuit. This 6-bit signed value is
                                                                                    subtracted from the ADC output before
                                                                                    being stored in the ADCRESULT
                                                                                    register. #br# #br#  00h  No change.
                                                                                    The ADC output is stored directly
                                                                                    into ADCRESULT. #br#  01h  ADC output
                                                                                    - 1 is stored into ADCRESULT. #br#
                                                                                    02h  ADC output - 2 is stored into
                                                                                    ADCRESULT. #br#  ... #br#  20h  ADC
                                                                                    output + 32 is stored into ADCRESULT.
                                                                                    #br#  ... #br#  3Fh  ADC output + 1
                                                                                    is stored into ADCRESULT. #br#
                                                                                    #br#NOTE: The subtraction will
                                                                                    saturate at 0000h and 0FFFh before
                                                                                    being stored into the ADCRESULT
                                                                                    register. #br# #br#Note: in the case
                                                                                    that multiple PPBs point to the same
                                                                                    SOC, only the OFFCAL of the lowest
                                                                                    numbered PPB will be applied. */

/* HSADC_ADCPPB4OFFREF Bits */
/* HSADC_ADCPPB4OFFREF[OFFREF] Bits */
#define HSADC_ADCPPB4OFFREF_OFFREF_OFS           (0)                             /* !< OFFREF Offset */
#define HSADC_ADCPPB4OFFREF_OFFREF_MASK          ((uint32_t)0x00000FFFU)         /* !< ADC Post Processing Block 4 Offset
                                                                                    Correction. This bit field can be
                                                                                    used to either calculate the feedback
                                                                                    error or convert a unipolar signal to
                                                                                    bipolar by subtracting a reference
                                                                                    value. This 12-bit unsigned value is
                                                                                    subtracted from the ADCRESULT
                                                                                    register before being passed through
                                                                                    an optional two's complement function
                                                                                    and stored in the ADCPPB4RESULT
                                                                                    register. This subtraction is not
                                                                                    saturated. #br# #br#  0000h  No
                                                                                    change. The ADCRESULT value is passed
                                                                                    on. #br#  001h  ADCRESULT - 1 is
                                                                                    passed on. #br#  002h  ADCRESULT - 2
                                                                                    is passed on. #br#  ... #br#  800h
                                                                                    ADCRESULT - 2048 is passed on. #br#
                                                                                    ... #br#  FFFh  ADCRESULT - 4096 is
                                                                                    passed on. */

/* HSADC_ADCPPB4TRIPHI Bits */
/* HSADC_ADCPPB4TRIPHI[LIMITHI] Bits */
#define HSADC_ADCPPB4TRIPHI_LIMITHI_OFS          (0)                             /* !< LIMITHI Offset */
#define HSADC_ADCPPB4TRIPHI_LIMITHI_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 4 Trip
                                                                                    High Limit. This value sets the
                                                                                    digital comparator trip high limit.
                                                                                    #br# #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPHI[15:13] will be ignored */

/* HSADC_ADCPPB4TRIPLO Bits */
/* HSADC_ADCPPB4TRIPLO[LIMITLO] Bits */
#define HSADC_ADCPPB4TRIPLO_LIMITLO_OFS          (0)                             /* !< LIMITLO Offset */
#define HSADC_ADCPPB4TRIPLO_LIMITLO_MASK         ((uint32_t)0x0000FFFFU)         /* !< ADC Post Processing Block 4 Trip
                                                                                    High Low Limit. This value sets the
                                                                                    digital comparator trip low limit if
                                                                                    ADCPPB4TRIPLO.LIMITLO2EN = 1.  #br#
                                                                                    #br#When comparing to an
                                                                                    ADCPPBxRESULT register, the upper
                                                                                    bits will be ignored: #br#-
                                                                                    TRIPLO[15:13] will be ignored in 12
                                                                                    bit mode */

/* HSADC_ADCINTCYCLE Bits */
/* HSADC_ADCINTCYCLE[DELAY] Bits */
#define HSADC_ADCINTCYCLE_DELAY_OFS              (0)                             /* !< DELAY Offset */
#define HSADC_ADCINTCYCLE_DELAY_MASK             ((uint32_t)0x0000003FU)         /* !< ADC Early Interrupt Generation
                                                                                    Cycle Delay: Defines the delay from
                                                                                    the fall edge of ADCSOC in terms of
                                                                                    system clock cycles, for the
                                                                                    interrupt to be generated. */

/* HSADC_ADCINLTRIM1 Bits */
/* HSADC_ADCINLTRIM1[INLTRIM31TO0] Bits */
#define HSADC_ADCINLTRIM1_INLTRIM31TO0_OFS       (0)                             /* !< INLTRIM31TO0 Offset */
#define HSADC_ADCINLTRIM1_INLTRIM31TO0_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< ADC Linearity Trim Bits 31-0. #br#
                                                                                    #br#This register should not be
                                                                                    modified unless specifically
                                                                                    indicated by TI Errata or other
                                                                                    documentation.  Modifying the
                                                                                    contents of this register could cause
                                                                                    this module to operate outside of
                                                                                    datasheet specifications. */

/* HSADC_ADCINLTRIM2 Bits */
/* HSADC_ADCINLTRIM2[INLTRIM63TO32] Bits */
#define HSADC_ADCINLTRIM2_INLTRIM63TO32_OFS      (0)                             /* !< INLTRIM63TO32 Offset */
#define HSADC_ADCINLTRIM2_INLTRIM63TO32_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< ADC Linearity Trim Bits 63-32.
                                                                                    #br# #br#This register should not be
                                                                                    modified unless specifically
                                                                                    indicated by TI Errata or other
                                                                                    documentation.  Modifying the
                                                                                    contents of this register could cause
                                                                                    this module to operate outside of
                                                                                    datasheet specifications. */

/* HSADC_ADCINLTRIM3 Bits */
/* HSADC_ADCINLTRIM3[INLTRIM95TO64] Bits */
#define HSADC_ADCINLTRIM3_INLTRIM95TO64_OFS      (0)                             /* !< INLTRIM95TO64 Offset */
#define HSADC_ADCINLTRIM3_INLTRIM95TO64_MASK     ((uint32_t)0xFFFFFFFFU)         /* !< ADC Linearity Trim Bits 95-64.
                                                                                    #br# #br#This register should not be
                                                                                    modified unless specifically
                                                                                    indicated by TI Errata or other
                                                                                    documentation.  Modifying the
                                                                                    contents of this register could cause
                                                                                    this module to operate outside of
                                                                                    datasheet specifications. */

/* HSADC_ADCINLTRIM4 Bits */
/* HSADC_ADCINLTRIM4[INLTRIM127TO96] Bits */
#define HSADC_ADCINLTRIM4_INLTRIM127TO96_OFS     (0)                             /* !< INLTRIM127TO96 Offset */
#define HSADC_ADCINLTRIM4_INLTRIM127TO96_MASK    ((uint32_t)0xFFFFFFFFU)         /* !< ADC Linearity Trim Bits 127-96.
                                                                                    #br# #br#This register should not be
                                                                                    modified unless specifically
                                                                                    indicated by TI Errata or other
                                                                                    documentation.  Modifying the
                                                                                    contents of this register could cause
                                                                                    this module to operate outside of
                                                                                    datasheet specifications. */

/* HSADC_ADCINLTRIM5 Bits */
/* HSADC_ADCINLTRIM5[INLTRIM159TO128] Bits */
#define HSADC_ADCINLTRIM5_INLTRIM159TO128_OFS    (0)                             /* !< INLTRIM159TO128 Offset */
#define HSADC_ADCINLTRIM5_INLTRIM159TO128_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< ADC Linearity Trim Bits 159-128.
                                                                                    #br# #br#This register should not be
                                                                                    modified unless specifically
                                                                                    indicated by TI Errata or other
                                                                                    documentation.  Modifying the
                                                                                    contents of this register could cause
                                                                                    this module to operate outside of
                                                                                    datasheet specifications. */

/* HSADC_ADCINLTRIM6 Bits */
/* HSADC_ADCINLTRIM6[INLTRIM191TO160] Bits */
#define HSADC_ADCINLTRIM6_INLTRIM191TO160_OFS    (0)                             /* !< INLTRIM191TO160 Offset */
#define HSADC_ADCINLTRIM6_INLTRIM191TO160_MASK   ((uint32_t)0xFFFFFFFFU)         /* !< ADC Linearity Trim Bits 191-160.
                                                                                    #br# #br#This register should not be
                                                                                    modified unless specifically
                                                                                    indicated by TI Errata or other
                                                                                    documentation.  Modifying the
                                                                                    contents of this register could cause
                                                                                    this module to operate outside of
                                                                                    datasheet specifications. */

/* HSADC_ADCREV2 Bits */
/* HSADC_ADCREV2[WRAPPERTYPE] Bits */
#define HSADC_ADCREV2_WRAPPERTYPE_OFS            (0)                             /* !< WRAPPERTYPE Offset */
#define HSADC_ADCREV2_WRAPPERTYPE_MASK           ((uint32_t)0x000000FFU)         /* !< ADC Wrapper Type. Always set to 6
                                                                                    for this ADC. */
/* HSADC_ADCREV2[WRAPPERREV] Bits */
#define HSADC_ADCREV2_WRAPPERREV_OFS             (8)                             /* !< WRAPPERREV Offset */
#define HSADC_ADCREV2_WRAPPERREV_MASK            ((uint32_t)0xFFFFFF00U)         /* !< ADC Revision. To allow
                                                                                    documentation of differences between
                                                                                    revisions. First version is labeled
                                                                                    as 00h. */

/* HSADC_ADCINLTRIMCTL Bits */
/* HSADC_ADCINLTRIMCTL[CALIBMODE] Bits */
#define HSADC_ADCINLTRIMCTL_CALIBMODE_OFS        (0)                             /* !< CALIBMODE Offset */
#define HSADC_ADCINLTRIMCTL_CALIBMODE_MASK       ((uint32_t)0x00000001U)         /* !< ADC Linearity Calibration Mode. */
/* HSADC_ADCINLTRIMCTL[CALIBSTEP] Bits */
#define HSADC_ADCINLTRIMCTL_CALIBSTEP_OFS        (1)                             /* !< CALIBSTEP Offset */
#define HSADC_ADCINLTRIMCTL_CALIBSTEP_MASK       ((uint32_t)0x0000003EU)         /* !< ADC Linearity Calibration Step.
                                                                                    Defines which of the 18 steps of
                                                                                    calibration is to be executed. */
/* HSADC_ADCINLTRIMCTL[KEY] Bits */
#define HSADC_ADCINLTRIMCTL_KEY_OFS              (16)                            /* !< KEY Offset */
#define HSADC_ADCINLTRIMCTL_KEY_MASK             ((uint32_t)0xFFFF0000U)         /* !< ADC Linearity Trim Control Write
                                                                                    Key. Any write to this register must
                                                                                    contain the value 0xA5A5 in these bit
                                                                                    locations. If a write request
                                                                                    attempts to load any other value into
                                                                                    these bits, the write for the entire
                                                                                    register is ignored. These bits
                                                                                    always read back a zero. */

/* HSADC_REP1CTL Bits */
/* HSADC_REP1CTL[MODULEBUSY] Bits */
#define HSADC_REP1CTL_MODULEBUSY_OFS             (3)                             /* !< MODULEBUSY Offset */
#define HSADC_REP1CTL_MODULEBUSY_MASK            ((uint32_t)0x00000008U)         /* !< ADC Trigger Repeater 1 Module Busy
                                                                                    indicator.  In oversampling mode:
                                                                                    #br# #br#0 = Repeater 1 is idle and
                                                                                    can accept a new repeated trigger in
                                                                                    oversampling mode #br#1 = Repeater 1
                                                                                    still has repeated triggers remaining
                                                                                    (NCOUNT > 0) or associated SOCs are
                                                                                    still pending (SOCBUSY is 1) #br#
                                                                                    #br#If a new oversampled trigger is
                                                                                    received while the module is still
                                                                                    busy, the TRIGGEROVF bit will be set
                                                                                    and the trigger will be ignored. */
/* HSADC_REP1CTL[TRIGGEROVF] Bits */
#define HSADC_REP1CTL_TRIGGEROVF_OFS             (7)                             /* !< TRIGGEROVF Offset */
#define HSADC_REP1CTL_TRIGGEROVF_MASK            ((uint32_t)0x00000080U)         /* !< ADC Trigger Repeater 1 Oversampled
                                                                                    Trigger Overflow. #br# #br#Indicates
                                                                                    that a trigger was dropped because a
                                                                                    trigger arrived while the repeater
                                                                                    was still generating repeated
                                                                                    oversampled triggers (NCOUNT was not
                                                                                    0 or SOCs associated with Repeater 1
                                                                                    were still pending).   #br#
                                                                                    #br#Writing a 1 will clear this flag.
                                                                                    #br# #br#Note: This flag won't be set
                                                                                    in undersampling mode or when NSEL =
                                                                                    0; if a trigger arrives before the
                                                                                    previous SOCs have completed, the
                                                                                    trigger will be passed and the
                                                                                    overflow flags of the SOCs that were
                                                                                    still pending will be set.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority and the
                                                                                    overflow bit will remain set. */
/* HSADC_REP1CTL[TRIGGER] Bits */
#define HSADC_REP1CTL_TRIGGER_OFS                (8)                             /* !< TRIGGER Offset */
#define HSADC_REP1CTL_TRIGGER_MASK               ((uint32_t)0x00001F00U)         /* !< ADC Trigger Repeater 1 Trigger
                                                                                    Select.  Selects the trigger to
                                                                                    modify via oversampling or
                                                                                    undersampling. #br# #br#  00h
                                                                                    REPTRIG0 - Software only #br#
                                                                                    01h-1FH   Hardware triggers */
/* HSADC_REP1CTL[SYNCINSEL] Bits */
#define HSADC_REP1CTL_SYNCINSEL_OFS              (16)                            /* !< SYNCINSEL Offset */
#define HSADC_REP1CTL_SYNCINSEL_MASK             ((uint32_t)0x00070000U)         /* !< Trigger repeater 1 sync. input
                                                                                    select.  On a sync. event, all
                                                                                    registers in repeater 1 are reset to
                                                                                    a ready and waiting state.  Values of
                                                                                    NSEL, PHASE, and MODE are preserved.
                                                                                    #br# #br#Note: SOCs associated with
                                                                                    repeater 1 are not cleared.   #br#
                                                                                    #br#0h = Disable Syncin to Repeater 1
                                                                                    #br#1h  - 1Fh  = Hardware syncin
                                                                                    sources */
/* HSADC_REP1CTL[SWSYNC] Bits */
#define HSADC_REP1CTL_SWSYNC_OFS                 (23)                            /* !< SWSYNC Offset */
#define HSADC_REP1CTL_SWSYNC_MASK                ((uint32_t)0x00800000U)         /* !< Trigger repeater 1 software force
                                                                                    sync.  On a sync. event, all
                                                                                    registers in repeater 1 are reset to
                                                                                    a ready and waiting state.  Values of
                                                                                    NSEL, PHASE, and MODE are preserved.
                                                                                    #br# #br#Note: SOCs associated with
                                                                                    repeater 1 are not cleared. */

/* HSADC_REP1N Bits */
/* HSADC_REP1N[NSEL] Bits */
#define HSADC_REP1N_NSEL_OFS                     (0)                             /* !< NSEL Offset */
#define HSADC_REP1N_NSEL_MASK                    ((uint32_t)0x00000003U)         /* !< ADC Trigger Repeater 1 selection of
                                                                                    number of triggers. #br# #br#In
                                                                                    oversampling mode, selects the number
                                                                                    of repeated triggers. For each
                                                                                    trigger received corresponding to
                                                                                    REP1CTL.TRIGSEL, 2^NSEL triggers will
                                                                                    be generated.   #br# #br#0 = 1
                                                                                    trigger is generated (pass-through)
                                                                                    #br#1 = 2 triggers are generated
                                                                                    #br#2 = 4 triggers are generated
                                                                                    #br#3 = 8 triggers are generated
                                                                                    #br# #br#In undersampling mode,
                                                                                    selects the number triggers to be
                                                                                    supressed. 1 out NSEL + 1 triggers
                                                                                    received corresponding to
                                                                                    REP1CTL.TRIGSEL will be passed
                                                                                    through (the first trigger will be
                                                                                    passed through and the subsequent
                                                                                    NSEL triggers will be supressed).
                                                                                    #br# #br#0 = all triggers are passed
                                                                                    #br#1 = 1 out of 2 triggers are
                                                                                    passed #br#2 = 1 out of 3 triggers
                                                                                    are passed #br#... #br#127 = 1 out of
                                                                                    128 triggers are passed */
/* HSADC_REP1N[NCOUNT] Bits */
#define HSADC_REP1N_NCOUNT_OFS                   (16)                            /* !< NCOUNT Offset */
#define HSADC_REP1N_NCOUNT_MASK                  ((uint32_t)0x00070000U)         /* !< ADC trigger repeater 1 trigger
                                                                                    count.   #br# #br#Indicates the
                                                                                    number of triggers remaining to be
                                                                                    generated.  If a trigger is received
                                                                                    corresponding to REP1CTL.TRIGSEL
                                                                                    while NCOUNT is not 0 (the repeater
                                                                                    is still busy generating the repeated
                                                                                    triggers) then the trigger will be
                                                                                    ignored and REP1CTL.TRIGOVF will be
                                                                                    set to 1. */

/* HSADC_REP1FRC Bits */
/* HSADC_REP1FRC[SWFRC] Bits */
#define HSADC_REP1FRC_SWFRC_OFS                  (0)                             /* !< SWFRC Offset */
#define HSADC_REP1FRC_SWFRC_MASK                 ((uint32_t)0x00000001U)         /* !< Write 1 to force a trigger to
                                                                                    repeat block 1 input regardless of
                                                                                    the value of TRIGGER. #br# #br#Always
                                                                                    reads 0. */

/* HSADC_REP2CTL Bits */
/* HSADC_REP2CTL[MODULEBUSY] Bits */
#define HSADC_REP2CTL_MODULEBUSY_OFS             (3)                             /* !< MODULEBUSY Offset */
#define HSADC_REP2CTL_MODULEBUSY_MASK            ((uint32_t)0x00000008U)         /* !< ADC Trigger Repeater 2 Module Busy
                                                                                    indicator.  In oversampling mode:
                                                                                    #br# #br#0 = Repeater 2 is idle and
                                                                                    can accept a new repeated trigger in
                                                                                    oversampling mode #br#1 = Repeater 2
                                                                                    still has repeated triggers remaining
                                                                                    (NCOUNT > 0) or associated SOCs are
                                                                                    still pending (SOCBUSY is 1) #br#
                                                                                    #br#If a new oversampled trigger is
                                                                                    received while the module is still
                                                                                    busy, the TRIGGEROVF bit will be set
                                                                                    and the trigger will be ignored. */
/* HSADC_REP2CTL[TRIGGEROVF] Bits */
#define HSADC_REP2CTL_TRIGGEROVF_OFS             (7)                             /* !< TRIGGEROVF Offset */
#define HSADC_REP2CTL_TRIGGEROVF_MASK            ((uint32_t)0x00000080U)         /* !< ADC Trigger Repeater 2 Oversampled
                                                                                    Trigger Overflow. #br# #br#Indicates
                                                                                    that a trigger was dropped because a
                                                                                    trigger arrived while the repeater
                                                                                    was still generating repeated
                                                                                    oversampled triggers (NCOUNT was not
                                                                                    0 or SOCs associated with Repeater 2
                                                                                    were still pending).   #br#
                                                                                    #br#Writing a 1 will clear this flag.
                                                                                    #br# #br#Note: This flag won't be set
                                                                                    in undersampling mode or when NSEL =
                                                                                    0; if a trigger arrives before the
                                                                                    previous SOCs have completed, the
                                                                                    trigger will be passed and the
                                                                                    overflow flags of the SOCs that were
                                                                                    still pending will be set.  #br#
                                                                                    #br#Note: If software sets the clear
                                                                                    bit on the same cycle that hardware
                                                                                    is trying to set the flag bit, then
                                                                                    hardware has priority and the
                                                                                    overflow bit will remain set. */
/* HSADC_REP2CTL[TRIGGER] Bits */
#define HSADC_REP2CTL_TRIGGER_OFS                (8)                             /* !< TRIGGER Offset */
#define HSADC_REP2CTL_TRIGGER_MASK               ((uint32_t)0x00001F00U)         /* !< ADC Trigger Repeater 2 Trigger
                                                                                    Select.  Selects the trigger to
                                                                                    modify via oversampling or
                                                                                    undersampling. #br# #br#  00h
                                                                                    REPTRIG0 - Software only #br#
                                                                                    01h-1FH   Hardware triggers */
/* HSADC_REP2CTL[SYNCINSEL] Bits */
#define HSADC_REP2CTL_SYNCINSEL_OFS              (16)                            /* !< SYNCINSEL Offset */
#define HSADC_REP2CTL_SYNCINSEL_MASK             ((uint32_t)0x00070000U)         /* !< Trigger repeater 2 sync. input
                                                                                    select.  On a sync. event, all
                                                                                    registers in repeater 2 are reset to
                                                                                    a ready and waiting state.  Values of
                                                                                    NSEL, PHASE, and MODE are preserved.
                                                                                    #br# #br#Note: SOCs associated with
                                                                                    repeater 2 are not cleared.   #br#
                                                                                    #br#0h = Disable Syncin to Repeater 2
                                                                                    #br#1h  - 1Fh  = Hardware syncin
                                                                                    sources */
/* HSADC_REP2CTL[SWSYNC] Bits */
#define HSADC_REP2CTL_SWSYNC_OFS                 (23)                            /* !< SWSYNC Offset */
#define HSADC_REP2CTL_SWSYNC_MASK                ((uint32_t)0x00800000U)         /* !< Trigger repeater 2 software force
                                                                                    sync.  On a sync. event, all
                                                                                    registers in repeater 2 are reset to
                                                                                    a ready and waiting state.  Values of
                                                                                    NSEL, PHASE, and MODE are preserved.
                                                                                    #br# #br#Note: SOCs associated with
                                                                                    repeater 2 are not cleared. */

/* HSADC_REP2N Bits */
/* HSADC_REP2N[NSEL] Bits */
#define HSADC_REP2N_NSEL_OFS                     (0)                             /* !< NSEL Offset */
#define HSADC_REP2N_NSEL_MASK                    ((uint32_t)0x00000003U)         /* !< ADC Trigger Repeater 2 selection of
                                                                                    number of triggers. #br# #br#In
                                                                                    oversampling mode, selects the number
                                                                                    of repeated triggers. For each
                                                                                    trigger received corresponding to
                                                                                    REP2CTL.TRIGSEL, 2^NSEL triggers will
                                                                                    be generated.   #br# #br#0 = 1
                                                                                    trigger is generated (pass-through)
                                                                                    #br#1 = 2 triggers are generated
                                                                                    #br#2 = 4 triggers are generated
                                                                                    #br#3 = 8 triggers are generated
                                                                                    #br# #br#In undersampling mode,
                                                                                    selects the number triggers to be
                                                                                    supressed. 1 out NSEL + 1 triggers
                                                                                    received corresponding to
                                                                                    REP2CTL.TRIGSEL will be passed
                                                                                    through (the first trigger will be
                                                                                    passed through and the subsequent
                                                                                    NSEL triggers will be supressed).
                                                                                    #br# #br#0 = all triggers are passed
                                                                                    #br#1 = 1 out of 2 triggers are
                                                                                    passed #br#2 = 1 out of 3 triggers
                                                                                    are passed #br#... #br#127 = 1 out of
                                                                                    128 triggers are passed */
/* HSADC_REP2N[NCOUNT] Bits */
#define HSADC_REP2N_NCOUNT_OFS                   (16)                            /* !< NCOUNT Offset */
#define HSADC_REP2N_NCOUNT_MASK                  ((uint32_t)0x00070000U)         /* !< ADC trigger repeater 2 trigger
                                                                                    count.   #br# #br#Indicates the
                                                                                    number of triggers remaining to be
                                                                                    generated.  If a trigger is received
                                                                                    corresponding to REP2CTL.TRIGSEL
                                                                                    while NCOUNT is not 0 (the repeater
                                                                                    is still busy generating the repeated
                                                                                    triggers) then the trigger will be
                                                                                    ignored and REP2CTL.TRIGOVF will be
                                                                                    set to 1. */

/* HSADC_REP2FRC Bits */
/* HSADC_REP2FRC[SWFRC] Bits */
#define HSADC_REP2FRC_SWFRC_OFS                  (0)                             /* !< SWFRC Offset */
#define HSADC_REP2FRC_SWFRC_MASK                 ((uint32_t)0x00000001U)         /* !< Write 1 to force a trigger to
                                                                                    repeat block 2 input regardless of
                                                                                    the value of TRIGGER. #br# #br#Always
                                                                                    reads 0. */

/* HSADC_ADCPPB1LIMIT Bits */
/* HSADC_ADCPPB1LIMIT[LIMIT] Bits */
#define HSADC_ADCPPB1LIMIT_LIMIT_OFS             (0)                             /* !< LIMIT Offset */
#define HSADC_ADCPPB1LIMIT_LIMIT_MASK            ((uint32_t)0x00000003U)         /* !< Post Processing Block 1
                                                                                    Oversampling Limit.  Defines the
                                                                                    number of conversions to accumulate
                                                                                    before PSUM is automatically loaded
                                                                                    into SUM.   #br# #br#0 = No -
                                                                                    accumulation #br#1 = 2 conversions
                                                                                    are accumulated #br#2 = 4 conversions
                                                                                    are accumulated #br#3 = 8 conversions
                                                                                    are accumulated  #br# */

/* HSADC_ADCPPB1PCOUNT Bits */
/* HSADC_ADCPPB1PCOUNT[PCOUNT] Bits */
#define HSADC_ADCPPB1PCOUNT_PCOUNT_OFS           (0)                             /* !< PCOUNT Offset */
#define HSADC_ADCPPB1PCOUNT_PCOUNT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 1
                                                                                    Oversampling Partial Count.  Each
                                                                                    time a new result propagates through
                                                                                    the PPB signal chain and accumulates
                                                                                    into ADCPPB1PSUM this register is
                                                                                    incremented by 1.   #br# #br#This
                                                                                    register is reset when either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB1 receives a sync.
                                                                                    event. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB1RESULT is
                                                                                    available. This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC (refer to the
                                                                                    ADCPPB1RESULT timing information). */

/* HSADC_ADCPPB1CONFIG2 Bits */
/* HSADC_ADCPPB1CONFIG2[SHIFT] Bits */
#define HSADC_ADCPPB1CONFIG2_SHIFT_OFS           (0)                             /* !< SHIFT Offset */
#define HSADC_ADCPPB1CONFIG2_SHIFT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 1 right
                                                                                    shift.  Defines the number of bits to
                                                                                    right shift PSUM before loading into
                                                                                    the final SUM.   #br# #br#0 : no
                                                                                    right shift #br#1 : SUM = PSUM >> 1
                                                                                    #br#2 : SUM = PSUM >> 2 #br#... #br#7
                                                                                    : SUM = PSUM >> 7 */
/* HSADC_ADCPPB1CONFIG2[SYNCINSEL] Bits */
#define HSADC_ADCPPB1CONFIG2_SYNCINSEL_OFS       (4)                             /* !< SYNCINSEL Offset */
#define HSADC_ADCPPB1CONFIG2_SYNCINSEL_MASK      ((uint32_t)0x00000070U)         /* !< PPB 1 sync. input select.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.   #br#Refer to SOC
                                                                                    spec for details */
/* HSADC_ADCPPB1CONFIG2[SWSYNC] Bits */
#define HSADC_ADCPPB1CONFIG2_SWSYNC_OFS          (11)                            /* !< SWSYNC Offset */
#define HSADC_ADCPPB1CONFIG2_SWSYNC_MASK         ((uint32_t)0x00000800U)         /* !< PPB 1 software force sync.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.  #br# #br#Note: In
                                                                                    the case where the software force
                                                                                    occurs at the same time that a new
                                                                                    sample is added to the PSUM and the
                                                                                    PSUM is being used for a high or low
                                                                                    limit compare, then the comparison
                                                                                    will not occur. */
/* HSADC_ADCPPB1CONFIG2[COMPSEL] Bits */
#define HSADC_ADCPPB1CONFIG2_COMPSEL_OFS         (15)                            /* !< COMPSEL Offset */
#define HSADC_ADCPPB1CONFIG2_COMPSEL_MASK        ((uint32_t)0x00008000U)         /* !< Post Processing Block 1 Compare
                                                                                    Source Select.  This field determines
                                                                                    whether ADCPPB1RESULT or ADCPPB1SUM
                                                                                    is used for the threshold compare.
                                                                                    #br# #br#0 = ADCPPB1RESULT is used
                                                                                    for compare logic #br#1 = ADCPPB1SUM
                                                                                    is used for compare logic */

/* HSADC_ADCPPB1PSUM Bits */
/* HSADC_ADCPPB1PSUM[PSUM] Bits */
#define HSADC_ADCPPB1PSUM_PSUM_OFS               (0)                             /* !< PSUM Offset */
#define HSADC_ADCPPB1PSUM_PSUM_MASK              ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 1
                                                                                    Oversampling Partial Sum.  Each time
                                                                                    a new result propagates through the
                                                                                    PPB signal chain and latches into
                                                                                    ADCPPB1RESULT the result is
                                                                                    subsequently accumulated into this
                                                                                    register.   #br# #br#This register is
                                                                                    reset when either a count-match event
                                                                                    occurs (PCOUNT = LIMIT) or PPB1
                                                                                    receives a sync. event. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB1RESULT is
                                                                                    available.  This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC.  In the case
                                                                                    of multiple PPBs associated with the
                                                                                    same SOC, the lowest numbered PPB's
                                                                                    result will be availble 2 SYSCLK
                                                                                    cycle after the associated ADCRESULT
                                                                                    and subsequent results (in order from
                                                                                    lowest numbered PPB to highest) will
                                                                                    each become available every 2-3
                                                                                    SYSCLK cycles (refer to the TRM for
                                                                                    detailed timing information). */
/* HSADC_ADCPPB1PSUM[SIGN] Bits */
#define HSADC_ADCPPB1PSUM_SIGN_OFS               (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB1PSUM_SIGN_MASK              ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_ADCPPB2LIMIT Bits */
/* HSADC_ADCPPB2LIMIT[LIMIT] Bits */
#define HSADC_ADCPPB2LIMIT_LIMIT_OFS             (0)                             /* !< LIMIT Offset */
#define HSADC_ADCPPB2LIMIT_LIMIT_MASK            ((uint32_t)0x00000003U)         /* !< Post Processing Block 2
                                                                                    Oversampling Limit.  Defines the
                                                                                    number of conversions to accumulate
                                                                                    before PSUM is automatically loaded
                                                                                    into SUM.   #br# #br#0 = No -
                                                                                    accumulation #br#1 = 2 conversions
                                                                                    are accumulated #br#2 = 4 conversions
                                                                                    are accumulated #br#3 = 8 conversions
                                                                                    are accumulated  #br# */

/* HSADC_ADCPPB2PCOUNT Bits */
/* HSADC_ADCPPB2PCOUNT[PCOUNT] Bits */
#define HSADC_ADCPPB2PCOUNT_PCOUNT_OFS           (0)                             /* !< PCOUNT Offset */
#define HSADC_ADCPPB2PCOUNT_PCOUNT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 2
                                                                                    Oversampling Partial Count.  Each
                                                                                    time a new result propagates through
                                                                                    the PPB signal chain and accumulates
                                                                                    into ADCPPB2PSUM this register is
                                                                                    incremented by 1.   #br# #br#This
                                                                                    register is reset when either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB2 receives a sync.
                                                                                    event. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB2RESULT is
                                                                                    available. This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC (refer to the
                                                                                    ADCPPB2RESULT timing information). */

/* HSADC_ADCPPB2CONFIG2 Bits */
/* HSADC_ADCPPB2CONFIG2[SHIFT] Bits */
#define HSADC_ADCPPB2CONFIG2_SHIFT_OFS           (0)                             /* !< SHIFT Offset */
#define HSADC_ADCPPB2CONFIG2_SHIFT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 2 right
                                                                                    shift.  Defines the number of bits to
                                                                                    right shift PSUM before loading into
                                                                                    the final SUM.   #br# #br#0 : no
                                                                                    right shift #br#1 : SUM = PSUM >> 1
                                                                                    #br#2 : SUM = PSUM >> 2 #br#... #br#7
                                                                                    : SUM = PSUM >> 7 */
/* HSADC_ADCPPB2CONFIG2[SYNCINSEL] Bits */
#define HSADC_ADCPPB2CONFIG2_SYNCINSEL_OFS       (4)                             /* !< SYNCINSEL Offset */
#define HSADC_ADCPPB2CONFIG2_SYNCINSEL_MASK      ((uint32_t)0x00000070U)         /* !< PPB 2 sync. input select.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.   #br#Refer to SOC
                                                                                    spec for details */
/* HSADC_ADCPPB2CONFIG2[SWSYNC] Bits */
#define HSADC_ADCPPB2CONFIG2_SWSYNC_OFS          (11)                            /* !< SWSYNC Offset */
#define HSADC_ADCPPB2CONFIG2_SWSYNC_MASK         ((uint32_t)0x00000800U)         /* !< PPB 2 software force sync.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.  #br# #br#Note: In
                                                                                    the case where the software force
                                                                                    occurs at the same time that a new
                                                                                    sample is added to the PSUM and the
                                                                                    PSUM is being used for a high or low
                                                                                    limit compare, then the comparison
                                                                                    will not occur. */
/* HSADC_ADCPPB2CONFIG2[COMPSEL] Bits */
#define HSADC_ADCPPB2CONFIG2_COMPSEL_OFS         (15)                            /* !< COMPSEL Offset */
#define HSADC_ADCPPB2CONFIG2_COMPSEL_MASK        ((uint32_t)0x00008000U)         /* !< Post Processing Block 2 Compare
                                                                                    Source Select.  This field determines
                                                                                    whether ADCPPB2RESULT or ADCPPB2SUM
                                                                                    is used for the threshold compare.
                                                                                    #br# #br#0 = ADCPPB2RESULT is used
                                                                                    for compare logic #br#1 = ADCPPB2SUM
                                                                                    is used for compare logic */

/* HSADC_ADCPPB2PSUM Bits */
/* HSADC_ADCPPB2PSUM[PSUM] Bits */
#define HSADC_ADCPPB2PSUM_PSUM_OFS               (0)                             /* !< PSUM Offset */
#define HSADC_ADCPPB2PSUM_PSUM_MASK              ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 2
                                                                                    Oversampling Partial Sum.  Each time
                                                                                    a new result propagates through the
                                                                                    PPB signal chain and latches into
                                                                                    ADCPPB2RESULT the result is
                                                                                    subsequently accumulated into this
                                                                                    register.   #br# #br#This register is
                                                                                    reset when either a count-match event
                                                                                    occurs (PCOUNT = LIMIT) or PPB2
                                                                                    receives a sync. event. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB2RESULT is
                                                                                    available.  This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC.  In the case
                                                                                    of multiple PPBs associated with the
                                                                                    same SOC, the lowest numbered PPB's
                                                                                    result will be availble 2 SYSCLK
                                                                                    cycle after the associated ADCRESULT
                                                                                    and subsequent results (in order from
                                                                                    lowest numbered PPB to highest) will
                                                                                    each become available every 2-3
                                                                                    SYSCLK cycles (refer to the TRM for
                                                                                    detailed timing information). */
/* HSADC_ADCPPB2PSUM[SIGN] Bits */
#define HSADC_ADCPPB2PSUM_SIGN_OFS               (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB2PSUM_SIGN_MASK              ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_ADCPPB3LIMIT Bits */
/* HSADC_ADCPPB3LIMIT[LIMIT] Bits */
#define HSADC_ADCPPB3LIMIT_LIMIT_OFS             (0)                             /* !< LIMIT Offset */
#define HSADC_ADCPPB3LIMIT_LIMIT_MASK            ((uint32_t)0x00000003U)         /* !< Post Processing Block 3
                                                                                    Oversampling Limit.  Defines the
                                                                                    number of conversions to accumulate
                                                                                    before PSUM is automatically loaded
                                                                                    into SUM.   #br# #br#0 = No -
                                                                                    accumulation #br#1 = 2 conversions
                                                                                    are accumulated #br#2 = 4 conversions
                                                                                    are accumulated #br#3 = 8 conversions
                                                                                    are accumulated  #br# */

/* HSADC_ADCPPB3PCOUNT Bits */
/* HSADC_ADCPPB3PCOUNT[PCOUNT] Bits */
#define HSADC_ADCPPB3PCOUNT_PCOUNT_OFS           (0)                             /* !< PCOUNT Offset */
#define HSADC_ADCPPB3PCOUNT_PCOUNT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 3
                                                                                    Oversampling Partial Count.  Each
                                                                                    time a new result propagates through
                                                                                    the PPB signal chain and accumulates
                                                                                    into ADCPPB3PSUM this register is
                                                                                    incremented by 1.   #br# #br#This
                                                                                    register is reset when either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB3 receives a sync.
                                                                                    event. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB3RESULT is
                                                                                    available. This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC (refer to the
                                                                                    ADCPPB3RESULT timing information). */

/* HSADC_ADCPPB3CONFIG2 Bits */
/* HSADC_ADCPPB3CONFIG2[SHIFT] Bits */
#define HSADC_ADCPPB3CONFIG2_SHIFT_OFS           (0)                             /* !< SHIFT Offset */
#define HSADC_ADCPPB3CONFIG2_SHIFT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 3 right
                                                                                    shift.  Defines the number of bits to
                                                                                    right shift PSUM before loading into
                                                                                    the final SUM.   #br# #br#0 : no
                                                                                    right shift #br#1 : SUM = PSUM >> 1
                                                                                    #br#2 : SUM = PSUM >> 2 #br#... #br#7
                                                                                    : SUM = PSUM >> 7 */
/* HSADC_ADCPPB3CONFIG2[SYNCINSEL] Bits */
#define HSADC_ADCPPB3CONFIG2_SYNCINSEL_OFS       (4)                             /* !< SYNCINSEL Offset */
#define HSADC_ADCPPB3CONFIG2_SYNCINSEL_MASK      ((uint32_t)0x00000070U)         /* !< PPB 3 sync. input select.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.   #br#Refer to SOC
                                                                                    spec for details */
/* HSADC_ADCPPB3CONFIG2[SWSYNC] Bits */
#define HSADC_ADCPPB3CONFIG2_SWSYNC_OFS          (11)                            /* !< SWSYNC Offset */
#define HSADC_ADCPPB3CONFIG2_SWSYNC_MASK         ((uint32_t)0x00000800U)         /* !< PPB 3 software force sync.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.  #br# #br#Note: In
                                                                                    the case where the software force
                                                                                    occurs at the same time that a new
                                                                                    sample is added to the PSUM and the
                                                                                    PSUM is being used for a high or low
                                                                                    limit compare, then the comparison
                                                                                    will not occur. */
/* HSADC_ADCPPB3CONFIG2[COMPSEL] Bits */
#define HSADC_ADCPPB3CONFIG2_COMPSEL_OFS         (15)                            /* !< COMPSEL Offset */
#define HSADC_ADCPPB3CONFIG2_COMPSEL_MASK        ((uint32_t)0x00008000U)         /* !< Post Processing Block 3 Compare
                                                                                    Source Select.  This field determines
                                                                                    whether ADCPPB3RESULT or ADCPPB3SUM
                                                                                    is used for the threshold compare.
                                                                                    #br# #br#0 = ADCPPB3RESULT is used
                                                                                    for compare logic #br#1 = ADCPPB3SUM
                                                                                    is used for compare logic */

/* HSADC_ADCPPB3PSUM Bits */
/* HSADC_ADCPPB3PSUM[PSUM] Bits */
#define HSADC_ADCPPB3PSUM_PSUM_OFS               (0)                             /* !< PSUM Offset */
#define HSADC_ADCPPB3PSUM_PSUM_MASK              ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 3
                                                                                    Oversampling Partial Sum.  Each time
                                                                                    a new result propagates through the
                                                                                    PPB signal chain and latches into
                                                                                    ADCPPB3RESULT the result is
                                                                                    subsequently accumulated into this
                                                                                    register.   #br# #br#This register is
                                                                                    reset when either a count-match event
                                                                                    occurs (PCOUNT = LIMIT) or PPB3
                                                                                    receives a sync. event. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB3RESULT is
                                                                                    available.  This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC.  In the case
                                                                                    of multiple PPBs associated with the
                                                                                    same SOC, the lowest numbered PPB's
                                                                                    result will be availble 2 SYSCLK
                                                                                    cycle after the associated ADCRESULT
                                                                                    and subsequent results (in order from
                                                                                    lowest numbered PPB to highest) will
                                                                                    each become available every 2-3
                                                                                    SYSCLK cycles (refer to the TRM for
                                                                                    detailed timing information). */
/* HSADC_ADCPPB3PSUM[SIGN] Bits */
#define HSADC_ADCPPB3PSUM_SIGN_OFS               (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB3PSUM_SIGN_MASK              ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_ADCPPB4LIMIT Bits */
/* HSADC_ADCPPB4LIMIT[LIMIT] Bits */
#define HSADC_ADCPPB4LIMIT_LIMIT_OFS             (0)                             /* !< LIMIT Offset */
#define HSADC_ADCPPB4LIMIT_LIMIT_MASK            ((uint32_t)0x00000003U)         /* !< Post Processing Block 4
                                                                                    Oversampling Limit.  Defines the
                                                                                    number of conversions to accumulate
                                                                                    before PSUM is automatically loaded
                                                                                    into SUM.   #br# #br#0 = No -
                                                                                    accumulation #br#1 = 2 conversions
                                                                                    are accumulated #br#2 = 4 conversions
                                                                                    are accumulated #br#3 = 8 conversions
                                                                                    are accumulated  #br# */

/* HSADC_ADCPPB4PCOUNT Bits */
/* HSADC_ADCPPB4PCOUNT[PCOUNT] Bits */
#define HSADC_ADCPPB4PCOUNT_PCOUNT_OFS           (0)                             /* !< PCOUNT Offset */
#define HSADC_ADCPPB4PCOUNT_PCOUNT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 4
                                                                                    Oversampling Partial Count.  Each
                                                                                    time a new result propagates through
                                                                                    the PPB signal chain and accumulates
                                                                                    into ADCPPB4PSUM this register is
                                                                                    incremented by 1.   #br# #br#This
                                                                                    register is reset when either a
                                                                                    count-match event occurs (PCOUNT =
                                                                                    LIMIT) or PPB4 receives a sync.
                                                                                    event. #br# #br#This result is
                                                                                    available 1 SYSCLK cycle after the
                                                                                    associated ADCPPB4RESULT is
                                                                                    available. This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC (refer to the
                                                                                    ADCPPB4RESULT timing information). */

/* HSADC_ADCPPB4CONFIG2 Bits */
/* HSADC_ADCPPB4CONFIG2[SHIFT] Bits */
#define HSADC_ADCPPB4CONFIG2_SHIFT_OFS           (0)                             /* !< SHIFT Offset */
#define HSADC_ADCPPB4CONFIG2_SHIFT_MASK          ((uint32_t)0x00000007U)         /* !< Post Processing Block 4 right
                                                                                    shift.  Defines the number of bits to
                                                                                    right shift PSUM before loading into
                                                                                    the final SUM.   #br# #br#0 : no
                                                                                    right shift #br#1 : SUM = PSUM >> 1
                                                                                    #br#2 : SUM = PSUM >> 2 #br#... #br#7
                                                                                    : SUM = PSUM >> 7 */
/* HSADC_ADCPPB4CONFIG2[SYNCINSEL] Bits */
#define HSADC_ADCPPB4CONFIG2_SYNCINSEL_OFS       (4)                             /* !< SYNCINSEL Offset */
#define HSADC_ADCPPB4CONFIG2_SYNCINSEL_MASK      ((uint32_t)0x00000070U)         /* !< PPB 4 sync. input select.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.   #br#Refer to SOC
                                                                                    spec for details */
/* HSADC_ADCPPB4CONFIG2[SWSYNC] Bits */
#define HSADC_ADCPPB4CONFIG2_SWSYNC_OFS          (11)                            /* !< SWSYNC Offset */
#define HSADC_ADCPPB4CONFIG2_SWSYNC_MASK         ((uint32_t)0x00000800U)         /* !< PPB 4 software force sync.  On a
                                                                                    sync. event, all partial registers
                                                                                    transfer to the final registers and
                                                                                    are then reset.  #br# #br#Note: In
                                                                                    the case where the software force
                                                                                    occurs at the same time that a new
                                                                                    sample is added to the PSUM and the
                                                                                    PSUM is being used for a high or low
                                                                                    limit compare, then the comparison
                                                                                    will not occur. */
/* HSADC_ADCPPB4CONFIG2[COMPSEL] Bits */
#define HSADC_ADCPPB4CONFIG2_COMPSEL_OFS         (15)                            /* !< COMPSEL Offset */
#define HSADC_ADCPPB4CONFIG2_COMPSEL_MASK        ((uint32_t)0x00008000U)         /* !< Post Processing Block 4 Compare
                                                                                    Source Select.  This field determines
                                                                                    whether ADCPPB4RESULT or ADCPPB4SUM
                                                                                    is used for the threshold compare.
                                                                                    #br# #br#0 = ADCPPB4RESULT is used
                                                                                    for compare logic #br#1 = ADCPPB4SUM
                                                                                    is used for compare logic */

/* HSADC_ADCPPB4PSUM Bits */
/* HSADC_ADCPPB4PSUM[PSUM] Bits */
#define HSADC_ADCPPB4PSUM_PSUM_OFS               (0)                             /* !< PSUM Offset */
#define HSADC_ADCPPB4PSUM_PSUM_MASK              ((uint32_t)0x0000FFFFU)         /* !< Post Processing Block 4
                                                                                    Oversampling Partial Sum.  Each time
                                                                                    a new result propagates through the
                                                                                    PPB signal chain and latches into
                                                                                    ADCPPB4RESULT the result is
                                                                                    subsequently accumulated into this
                                                                                    register.   #br# #br#This register is
                                                                                    reset when either a count-match event
                                                                                    occurs (PCOUNT = LIMIT) or PPB4
                                                                                    receives a sync. event. #br# #br#This
                                                                                    result is available 1 SYSCLK cycle
                                                                                    after the associated ADCPPB4RESULT is
                                                                                    available.  This will be 2 SYSCLK
                                                                                    cycles after the associated ADCRESULT
                                                                                    is available, unless multiple PPBs
                                                                                    point to the same SOC.  In the case
                                                                                    of multiple PPBs associated with the
                                                                                    same SOC, the lowest numbered PPB's
                                                                                    result will be availble 2 SYSCLK
                                                                                    cycle after the associated ADCRESULT
                                                                                    and subsequent results (in order from
                                                                                    lowest numbered PPB to highest) will
                                                                                    each become available every 2-3
                                                                                    SYSCLK cycles (refer to the TRM for
                                                                                    detailed timing information). */
/* HSADC_ADCPPB4PSUM[SIGN] Bits */
#define HSADC_ADCPPB4PSUM_SIGN_OFS               (16)                            /* !< SIGN Offset */
#define HSADC_ADCPPB4PSUM_SIGN_MASK              ((uint32_t)0xFFFF0000U)         /* !< Sign Extended Bits. These bits
                                                                                    reflect the same value as bit 15. */

/* HSADC_DTB Bits */

/* HSADC_ADCSEQCTL Bits */
/* HSADC_ADCSEQCTL[SEQEND] Bits */
#define HSADC_ADCSEQCTL_SEQEND_OFS               (0)                             /* !< SEQEND Offset */
#define HSADC_ADCSEQCTL_SEQEND_MASK              ((uint32_t)0x0000000FU)         /* !< END SOC of last enabled sequence */
/* HSADC_ADCSEQCTL[SEQPREEMPT] Bits */
#define HSADC_ADCSEQCTL_SEQPREEMPT_OFS           (16)                            /* !< SEQPREEMPT Offset */
#define HSADC_ADCSEQCTL_SEQPREEMPT_MASK          ((uint32_t)0x00030000U)         /* !< SoC Sequence PREEMPT #br#0X:
                                                                                    Pre-empt disabled #br#10: Pre-empt
                                                                                    enabled and will not restart aborted
                                                                                    Sequence #br#11: Pre-empt enabled and
                                                                                    will restart aborted Sequence */

/* HSADC_ADCSEQ1CONFIG Bits */
/* HSADC_ADCSEQ1CONFIG[ACQPS] Bits */
#define HSADC_ADCSEQ1CONFIG_ACQPS_OFS            (0)                             /* !< ACQPS Offset */
#define HSADC_ADCSEQ1CONFIG_ACQPS_MASK           ((uint32_t)0x000000FFU)         /* !< SOC1 Acquisition Prescale. Controls
                                                                                    the sample and hold window for each
                                                                                    SOC in this Seqeunce. The configured
                                                                                    acquisition time must be at least as
                                                                                    long as one ADCCLK cycle for correct
                                                                                    ADC operation.  The device datasheet
                                                                                    will also specify a minimum sample
                                                                                    and hold window duration. #br#S+H
                                                                                    window values is defined based on a
                                                                                    combonation of ACQPS[7:6]  and
                                                                                    ACQPS[5:0] values #br#If ACQPS[7:6]
                                                                                    value is #br#  "00" S+H window =
                                                                                    ACQPS[5:0] + 1 sysclk cycles #br#
                                                                                    "01"  S+H window = 64 + ((ACQPS[5:0]
                                                                                    +1) * 2) sysclk cycles #br#  "10"
                                                                                    S+H window = 192 + ((ACQPS[5:0] +1) *
                                                                                    4) sysclk cycles #br#  "11"  S+H
                                                                                    window = 448 + ((ACQPS[5:0] +1) * 16)
                                                                                    sysclk cycles */
/* HSADC_ADCSEQ1CONFIG[SAMPCAPRESETDISABLE] Bits */
#define HSADC_ADCSEQ1CONFIG_SAMPCAPRESETDISABLE_OFS (9)                             /* !< SAMPCAPRESETDISABLE Offset */
#define HSADC_ADCSEQ1CONFIG_SAMPCAPRESETDISABLE_MASK ((uint32_t)0x00000200U)         /* !< SOC1 Sample Cap Reset enable :
                                                                                    Resets sample cap after conversion.
                                                                                    #br#0 - The sample cap is reset after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is not reset after each
                                                                                    conversion */
/* HSADC_ADCSEQ1CONFIG[SAMPCAPRESETSEL] Bits */
#define HSADC_ADCSEQ1CONFIG_SAMPCAPRESETSEL_OFS  (10)                            /* !< SAMPCAPRESETSEL Offset */
#define HSADC_ADCSEQ1CONFIG_SAMPCAPRESETSEL_MASK ((uint32_t)0x00000400U)         /* !< SOC1 Sample Cap Reset Select :
                                                                                    Resets sample cap after conversion to
                                                                                    either vrefhi/2 or vreflo #br#0 - The
                                                                                    sample cap is reset to Vreflo after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is reset to Vrefhi/2 after each
                                                                                    conversion */
/* HSADC_ADCSEQ1CONFIG[SEQSTART] Bits */
#define HSADC_ADCSEQ1CONFIG_SEQSTART_OFS         (15)                            /* !< SEQSTART Offset */
#define HSADC_ADCSEQ1CONFIG_SEQSTART_MASK        ((uint32_t)0x00078000U)         /* !< Beginning SOC of SEQ1 */
/* HSADC_ADCSEQ1CONFIG[TRIGSEL] Bits */
#define HSADC_ADCSEQ1CONFIG_TRIGSEL_OFS          (20)                            /* !< TRIGSEL Offset */
#define HSADC_ADCSEQ1CONFIG_TRIGSEL_MASK         ((uint32_t)0x00700000U)         /* !< SOC1 Trigger Source Select. Along
                                                                                    with the SOC1 field in the
                                                                                    ADCINTSOCSEL1 register, this bit
                                                                                    field configures which trigger will
                                                                                    set the SOC1 flag in the ADCSOCFLG1
                                                                                    register to initiate a conversion to
                                                                                    start once priority is given to it.
                                                                                    #br# #br#Note: SOCFRC1 register can
                                                                                    always be used to software trigger
                                                                                    SOCs in addition to any hardware
                                                                                    trigger configuration. #br#  0h
                                                                                    ADCTRIG0 - Software only #br#  1h -
                                                                                    7h  Hardware triggers */
/* HSADC_ADCSEQ1CONFIG[SEQSWFRC] Bits */
#define HSADC_ADCSEQ1CONFIG_SEQSWFRC_OFS         (30)                            /* !< SEQSWFRC Offset */
#define HSADC_ADCSEQ1CONFIG_SEQSWFRC_MASK        ((uint32_t)0x40000000U)         /* !< Write 1 to force a trigger to
                                                                                    Sequencer 1 regardless of the value
                                                                                    of Hardware TRIGGER. #br# #br#Always
                                                                                    reads 0. */
/* HSADC_ADCSEQ1CONFIG[SEQENABLE] Bits */
#define HSADC_ADCSEQ1CONFIG_SEQENABLE_OFS        (31)                            /* !< SEQENABLE Offset */
#define HSADC_ADCSEQ1CONFIG_SEQENABLE_MASK       ((uint32_t)0x80000000U)         /* !< SEQ1Enable #br#Indicates whether
                                                                                    the Sequence1 is enabled or not */

/* HSADC_ADCSEQ2CONFIG Bits */
/* HSADC_ADCSEQ2CONFIG[ACQPS] Bits */
#define HSADC_ADCSEQ2CONFIG_ACQPS_OFS            (0)                             /* !< ACQPS Offset */
#define HSADC_ADCSEQ2CONFIG_ACQPS_MASK           ((uint32_t)0x000000FFU)         /* !< SOC2 Acquisition Prescale. Controls
                                                                                    the sample and hold window for each
                                                                                    SOC in this Seqeunce. The configured
                                                                                    acquisition time must be at least as
                                                                                    long as one ADCCLK cycle for correct
                                                                                    ADC operation.  The device datasheet
                                                                                    will also specify a minimum sample
                                                                                    and hold window duration. #br#S+H
                                                                                    window values is defined based on a
                                                                                    combonation of ACQPS[7:6]  and
                                                                                    ACQPS[5:0] values #br#If ACQPS[7:6]
                                                                                    value is #br#  "00" S+H window =
                                                                                    ACQPS[5:0] + 1 sysclk cycles #br#
                                                                                    "01"  S+H window = 64 + ((ACQPS[5:0]
                                                                                    +1) * 2) sysclk cycles #br#  "10"
                                                                                    S+H window = 192 + ((ACQPS[5:0] +1) *
                                                                                    4) sysclk cycles #br#  "11"  S+H
                                                                                    window = 448 + ((ACQPS[5:0] +1) * 16)
                                                                                    sysclk cycles */
/* HSADC_ADCSEQ2CONFIG[SAMPCAPRESETDISABLE] Bits */
#define HSADC_ADCSEQ2CONFIG_SAMPCAPRESETDISABLE_OFS (9)                             /* !< SAMPCAPRESETDISABLE Offset */
#define HSADC_ADCSEQ2CONFIG_SAMPCAPRESETDISABLE_MASK ((uint32_t)0x00000200U)         /* !< SOC2 Sample Cap Reset enable :
                                                                                    Resets sample cap after conversion.
                                                                                    #br#0 - The sample cap is reset after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is not reset after each
                                                                                    conversion */
/* HSADC_ADCSEQ2CONFIG[SAMPCAPRESETSEL] Bits */
#define HSADC_ADCSEQ2CONFIG_SAMPCAPRESETSEL_OFS  (10)                            /* !< SAMPCAPRESETSEL Offset */
#define HSADC_ADCSEQ2CONFIG_SAMPCAPRESETSEL_MASK ((uint32_t)0x00000400U)         /* !< SOC2 Sample Cap Reset Select :
                                                                                    Resets sample cap after conversion to
                                                                                    either vrefhi/2 or vreflo #br#0 - The
                                                                                    sample cap is reset to Vreflo after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is reset to Vrefhi/2 after each
                                                                                    conversion */
/* HSADC_ADCSEQ2CONFIG[SEQSTART] Bits */
#define HSADC_ADCSEQ2CONFIG_SEQSTART_OFS         (15)                            /* !< SEQSTART Offset */
#define HSADC_ADCSEQ2CONFIG_SEQSTART_MASK        ((uint32_t)0x00078000U)         /* !< Beginning SOC of SEQ2 */
/* HSADC_ADCSEQ2CONFIG[TRIGSEL] Bits */
#define HSADC_ADCSEQ2CONFIG_TRIGSEL_OFS          (20)                            /* !< TRIGSEL Offset */
#define HSADC_ADCSEQ2CONFIG_TRIGSEL_MASK         ((uint32_t)0x00700000U)         /* !< SOC2 Trigger Source Select. Along
                                                                                    with the SOC2 field in the
                                                                                    ADCINTSOCSEL1 register, this bit
                                                                                    field configures which trigger will
                                                                                    set the SOC2 flag in the ADCSOCFLG1
                                                                                    register to initiate a conversion to
                                                                                    start once priority is given to it.
                                                                                    #br# #br#Note: SOCFRC1 register can
                                                                                    always be used to software trigger
                                                                                    SOCs in addition to any hardware
                                                                                    trigger configuration. #br#  0h
                                                                                    ADCTRIG0 - Software only #br#  1h -
                                                                                    7h  Hardware triggers */
/* HSADC_ADCSEQ2CONFIG[SEQSWFRC] Bits */
#define HSADC_ADCSEQ2CONFIG_SEQSWFRC_OFS         (30)                            /* !< SEQSWFRC Offset */
#define HSADC_ADCSEQ2CONFIG_SEQSWFRC_MASK        ((uint32_t)0x40000000U)         /* !< Write 1 to force a trigger to
                                                                                    Sequencer 2 regardless of the value
                                                                                    of Hardware TRIGGER. #br# #br#Always
                                                                                    reads 0. */
/* HSADC_ADCSEQ2CONFIG[SEQENABLE] Bits */
#define HSADC_ADCSEQ2CONFIG_SEQENABLE_OFS        (31)                            /* !< SEQENABLE Offset */
#define HSADC_ADCSEQ2CONFIG_SEQENABLE_MASK       ((uint32_t)0x80000000U)         /* !< SEQ2Enable #br#Indicates whether
                                                                                    the Sequence2 is enabled or not */

/* HSADC_ADCSEQ3CONFIG Bits */
/* HSADC_ADCSEQ3CONFIG[ACQPS] Bits */
#define HSADC_ADCSEQ3CONFIG_ACQPS_OFS            (0)                             /* !< ACQPS Offset */
#define HSADC_ADCSEQ3CONFIG_ACQPS_MASK           ((uint32_t)0x000000FFU)         /* !< SOC3 Acquisition Prescale. Controls
                                                                                    the sample and hold window for each
                                                                                    SOC in this Seqeunce. The configured
                                                                                    acquisition time must be at least as
                                                                                    long as one ADCCLK cycle for correct
                                                                                    ADC operation.  The device datasheet
                                                                                    will also specify a minimum sample
                                                                                    and hold window duration. #br#S+H
                                                                                    window values is defined based on a
                                                                                    combonation of ACQPS[7:6]  and
                                                                                    ACQPS[5:0] values #br#If ACQPS[7:6]
                                                                                    value is #br#  "00" S+H window =
                                                                                    ACQPS[5:0] + 1 sysclk cycles #br#
                                                                                    "01"  S+H window = 64 + ((ACQPS[5:0]
                                                                                    +1) * 2) sysclk cycles #br#  "10"
                                                                                    S+H window = 192 + ((ACQPS[5:0] +1) *
                                                                                    4) sysclk cycles #br#  "11"  S+H
                                                                                    window = 448 + ((ACQPS[5:0] +1) * 16)
                                                                                    sysclk cycles */
/* HSADC_ADCSEQ3CONFIG[SAMPCAPRESETDISABLE] Bits */
#define HSADC_ADCSEQ3CONFIG_SAMPCAPRESETDISABLE_OFS (9)                             /* !< SAMPCAPRESETDISABLE Offset */
#define HSADC_ADCSEQ3CONFIG_SAMPCAPRESETDISABLE_MASK ((uint32_t)0x00000200U)         /* !< SOC3 Sample Cap Reset enable :
                                                                                    Resets sample cap after conversion.
                                                                                    #br#0 - The sample cap is reset after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is not reset after each
                                                                                    conversion */
/* HSADC_ADCSEQ3CONFIG[SAMPCAPRESETSEL] Bits */
#define HSADC_ADCSEQ3CONFIG_SAMPCAPRESETSEL_OFS  (10)                            /* !< SAMPCAPRESETSEL Offset */
#define HSADC_ADCSEQ3CONFIG_SAMPCAPRESETSEL_MASK ((uint32_t)0x00000400U)         /* !< SOC3 Sample Cap Reset Select :
                                                                                    Resets sample cap after conversion to
                                                                                    either vrefhi/2 or vreflo #br#0 - The
                                                                                    sample cap is reset to Vreflo after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is reset to Vrefhi/2 after each
                                                                                    conversion */
/* HSADC_ADCSEQ3CONFIG[SEQSTART] Bits */
#define HSADC_ADCSEQ3CONFIG_SEQSTART_OFS         (15)                            /* !< SEQSTART Offset */
#define HSADC_ADCSEQ3CONFIG_SEQSTART_MASK        ((uint32_t)0x00078000U)         /* !< Beginning SOC of SEQ3 */
/* HSADC_ADCSEQ3CONFIG[TRIGSEL] Bits */
#define HSADC_ADCSEQ3CONFIG_TRIGSEL_OFS          (20)                            /* !< TRIGSEL Offset */
#define HSADC_ADCSEQ3CONFIG_TRIGSEL_MASK         ((uint32_t)0x00700000U)         /* !< SOC3 Trigger Source Select. Along
                                                                                    with the SOC3 field in the
                                                                                    ADCINTSOCSEL1 register, this bit
                                                                                    field configures which trigger will
                                                                                    set the SOC3 flag in the ADCSOCFLG1
                                                                                    register to initiate a conversion to
                                                                                    start once priority is given to it.
                                                                                    #br# #br#Note: SOCFRC1 register can
                                                                                    always be used to software trigger
                                                                                    SOCs in addition to any hardware
                                                                                    trigger configuration. #br#  0h
                                                                                    ADCTRIG0 - Software only #br#  1h -
                                                                                    7h  Hardware triggers */
/* HSADC_ADCSEQ3CONFIG[SEQSWFRC] Bits */
#define HSADC_ADCSEQ3CONFIG_SEQSWFRC_OFS         (30)                            /* !< SEQSWFRC Offset */
#define HSADC_ADCSEQ3CONFIG_SEQSWFRC_MASK        ((uint32_t)0x40000000U)         /* !< Write 1 to force a trigger to
                                                                                    Sequencer 3 regardless of the value
                                                                                    of Hardware TRIGGER. #br# #br#Always
                                                                                    reads 0. */
/* HSADC_ADCSEQ3CONFIG[SEQENABLE] Bits */
#define HSADC_ADCSEQ3CONFIG_SEQENABLE_OFS        (31)                            /* !< SEQENABLE Offset */
#define HSADC_ADCSEQ3CONFIG_SEQENABLE_MASK       ((uint32_t)0x80000000U)         /* !< SEQ3Enable #br#Indicates whether
                                                                                    the Sequence3 is enabled or not */

/* HSADC_ADCSEQ4CONFIG Bits */
/* HSADC_ADCSEQ4CONFIG[ACQPS] Bits */
#define HSADC_ADCSEQ4CONFIG_ACQPS_OFS            (0)                             /* !< ACQPS Offset */
#define HSADC_ADCSEQ4CONFIG_ACQPS_MASK           ((uint32_t)0x000000FFU)         /* !< SOC4 Acquisition Prescale. Controls
                                                                                    the sample and hold window for each
                                                                                    SOC in this Seqeunce. The configured
                                                                                    acquisition time must be at least as
                                                                                    long as one ADCCLK cycle for correct
                                                                                    ADC operation.  The device datasheet
                                                                                    will also specify a minimum sample
                                                                                    and hold window duration. #br#S+H
                                                                                    window values is defined based on a
                                                                                    combonation of ACQPS[7:6]  and
                                                                                    ACQPS[5:0] values #br#If ACQPS[7:6]
                                                                                    value is #br#  "00" S+H window =
                                                                                    ACQPS[5:0] + 1 sysclk cycles #br#
                                                                                    "01"  S+H window = 64 + ((ACQPS[5:0]
                                                                                    +1) * 2) sysclk cycles #br#  "10"
                                                                                    S+H window = 192 + ((ACQPS[5:0] +1) *
                                                                                    4) sysclk cycles #br#  "11"  S+H
                                                                                    window = 448 + ((ACQPS[5:0] +1) * 16)
                                                                                    sysclk cycles */
/* HSADC_ADCSEQ4CONFIG[SAMPCAPRESETDISABLE] Bits */
#define HSADC_ADCSEQ4CONFIG_SAMPCAPRESETDISABLE_OFS (9)                             /* !< SAMPCAPRESETDISABLE Offset */
#define HSADC_ADCSEQ4CONFIG_SAMPCAPRESETDISABLE_MASK ((uint32_t)0x00000200U)         /* !< SOC4 Sample Cap Reset enable :
                                                                                    Resets sample cap after conversion.
                                                                                    #br#0 - The sample cap is reset after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is not reset after each
                                                                                    conversion */
/* HSADC_ADCSEQ4CONFIG[SAMPCAPRESETSEL] Bits */
#define HSADC_ADCSEQ4CONFIG_SAMPCAPRESETSEL_OFS  (10)                            /* !< SAMPCAPRESETSEL Offset */
#define HSADC_ADCSEQ4CONFIG_SAMPCAPRESETSEL_MASK ((uint32_t)0x00000400U)         /* !< SOC4 Sample Cap Reset Select :
                                                                                    Resets sample cap after conversion to
                                                                                    either vrefhi/2 or vreflo #br#0 - The
                                                                                    sample cap is reset to Vreflo after
                                                                                    each conversion #br#1 - The sample
                                                                                    cap is reset to Vrefhi/2 after each
                                                                                    conversion */
/* HSADC_ADCSEQ4CONFIG[SEQSTART] Bits */
#define HSADC_ADCSEQ4CONFIG_SEQSTART_OFS         (15)                            /* !< SEQSTART Offset */
#define HSADC_ADCSEQ4CONFIG_SEQSTART_MASK        ((uint32_t)0x00078000U)         /* !< Beginning SOC of SEQ4 */
/* HSADC_ADCSEQ4CONFIG[TRIGSEL] Bits */
#define HSADC_ADCSEQ4CONFIG_TRIGSEL_OFS          (20)                            /* !< TRIGSEL Offset */
#define HSADC_ADCSEQ4CONFIG_TRIGSEL_MASK         ((uint32_t)0x00700000U)         /* !< SOC4 Trigger Source Select. Along
                                                                                    with the SOC4 field in the
                                                                                    ADCINTSOCSEL1 register, this bit
                                                                                    field configures which trigger will
                                                                                    set the SOC4 flag in the ADCSOCFLG1
                                                                                    register to initiate a conversion to
                                                                                    start once priority is given to it.
                                                                                    #br# #br#Note: SOCFRC1 register can
                                                                                    always be used to software trigger
                                                                                    SOCs in addition to any hardware
                                                                                    trigger configuration. #br#  0h
                                                                                    ADCTRIG0 - Software only #br#  1h -
                                                                                    7h  Hardware triggers */
/* HSADC_ADCSEQ4CONFIG[SEQSWFRC] Bits */
#define HSADC_ADCSEQ4CONFIG_SEQSWFRC_OFS         (30)                            /* !< SEQSWFRC Offset */
#define HSADC_ADCSEQ4CONFIG_SEQSWFRC_MASK        ((uint32_t)0x40000000U)         /* !< Write 1 to force a trigger to
                                                                                    Sequencer 4 regardless of the value
                                                                                    of Hardware TRIGGER. #br# #br#Always
                                                                                    reads 0. */
/* HSADC_ADCSEQ4CONFIG[SEQENABLE] Bits */
#define HSADC_ADCSEQ4CONFIG_SEQENABLE_OFS        (31)                            /* !< SEQENABLE Offset */
#define HSADC_ADCSEQ4CONFIG_SEQENABLE_MASK       ((uint32_t)0x80000000U)         /* !< SEQ4Enable #br#Indicates whether
                                                                                    the Sequence4 is enabled or not */

/* HSADC_PWREN Bits */
/* HSADC_PWREN[ENABLE] Bits */
#define HSADC_PWREN_ENABLE_OFS                   (0)                             /* !< ENABLE Offset */
#define HSADC_PWREN_ENABLE_MASK                  ((uint32_t)0x00000001U)         /* !< Enable the power */
#define HSADC_PWREN_ENABLE_DISABLE               ((uint32_t)0x00000000U)         /* !< Disable Power */
#define HSADC_PWREN_ENABLE_ENABLE                ((uint32_t)0x00000001U)         /* !< Enable Power */
/* HSADC_PWREN[KEY] Bits */
#define HSADC_PWREN_KEY_OFS                      (24)                            /* !< KEY Offset */
#define HSADC_PWREN_KEY_MASK                     ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define HSADC_PWREN_KEY_UNLOCK_W                 ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* HSADC_RSTCTL Bits */
/* HSADC_RSTCTL[RESETSTKYCLR] Bits */
#define HSADC_RSTCTL_RESETSTKYCLR_OFS            (1)                             /* !< RESETSTKYCLR Offset */
#define HSADC_RSTCTL_RESETSTKYCLR_MASK           ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define HSADC_RSTCTL_RESETSTKYCLR_NOP            ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define HSADC_RSTCTL_RESETSTKYCLR_CLR            ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* HSADC_RSTCTL[RESETASSERT] Bits */
#define HSADC_RSTCTL_RESETASSERT_OFS             (0)                             /* !< RESETASSERT Offset */
#define HSADC_RSTCTL_RESETASSERT_MASK            ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define HSADC_RSTCTL_RESETASSERT_NOP             ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define HSADC_RSTCTL_RESETASSERT_ASSERT          ((uint32_t)0x00000001U)         /* !< Assert reset */
/* HSADC_RSTCTL[KEY] Bits */
#define HSADC_RSTCTL_KEY_OFS                     (24)                            /* !< KEY Offset */
#define HSADC_RSTCTL_KEY_MASK                    ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define HSADC_RSTCTL_KEY_UNLOCK_W                ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* HSADC_STAT Bits */
/* HSADC_STAT[RESETSTKYCLR] Bits */
#define HSADC_STAT_RESETSTKYCLR_OFS              (16)                            /* !< RESETSTKYCLR Offset */
#define HSADC_STAT_RESETSTKYCLR_MASK             ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define HSADC_STAT_RESETSTKYCLR_NORES            ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define HSADC_STAT_RESETSTKYCLR_RESET            ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* HSADC_FSUB_0 Bits */
/* HSADC_FSUB_0[CHANID] Bits */
#define HSADC_FSUB_0_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FSUB_0_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FSUB_0_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FSUB_0_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FSUB_0_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* HSADC_FSUB_1 Bits */
/* HSADC_FSUB_1[CHANID] Bits */
#define HSADC_FSUB_1_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FSUB_1_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FSUB_1_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FSUB_1_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FSUB_1_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* HSADC_FSUB_2 Bits */
/* HSADC_FSUB_2[CHANID] Bits */
#define HSADC_FSUB_2_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FSUB_2_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FSUB_2_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FSUB_2_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FSUB_2_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* HSADC_FSUB_3 Bits */
/* HSADC_FSUB_3[CHANID] Bits */
#define HSADC_FSUB_3_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FSUB_3_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FSUB_3_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FSUB_3_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FSUB_3_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* HSADC_FPUB_0 Bits */
/* HSADC_FPUB_0[CHANID] Bits */
#define HSADC_FPUB_0_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FPUB_0_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FPUB_0_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FPUB_0_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FPUB_0_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* HSADC_FPUB_1 Bits */
/* HSADC_FPUB_1[CHANID] Bits */
#define HSADC_FPUB_1_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FPUB_1_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FPUB_1_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FPUB_1_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FPUB_1_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* HSADC_FPUB_2 Bits */
/* HSADC_FPUB_2[CHANID] Bits */
#define HSADC_FPUB_2_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FPUB_2_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FPUB_2_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FPUB_2_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FPUB_2_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */

/* HSADC_FPUB_3 Bits */
/* HSADC_FPUB_3[CHANID] Bits */
#define HSADC_FPUB_3_CHANID_OFS                  (0)                             /* !< CHANID Offset */
#define HSADC_FPUB_3_CHANID_MASK                 ((uint32_t)0x0000000FU)         /* !< 0 = disconnected. 1-15 = connected
                                                                                    to channelID = CHANID. */
#define HSADC_FPUB_3_CHANID_MNIMUM               ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define HSADC_FPUB_3_CHANID_UNCONNECTED          ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define HSADC_FPUB_3_CHANID_MAXIMUM              ((uint32_t)0x0000000FU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 15. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_hsadc__include */

