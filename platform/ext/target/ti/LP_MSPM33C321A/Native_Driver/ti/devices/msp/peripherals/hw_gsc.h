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

#ifndef ti_devices_msp_peripherals_hw_gsc__include
#define ti_devices_msp_peripherals_hw_gsc__include

/* This preliminary header file does not have a version number */
/* Filename: hw_gsc.h */
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
* GSC Registers
******************************************************************************/


/** @addtogroup GSC
  @{
*/

typedef struct {
  __IO uint32_t Reserved_1[1024];                  /* !< (@ 0x00000000) */
  __IO uint32_t SPC_ATTRIBVIOLS_CONFIG;            /* !< (@ 0x00001000) SRAM Secure Access Attribute Violation
                                                      Configuration Register */
  __IO uint32_t SPC_ATTRIBVIOLP_CONFIG;            /* !< (@ 0x00001004) SRAM Privilege Access Attribute Violation
                                                      Configuration Register */
  __IO uint32_t Reserved_2[2];                     /* !< (@ 0x00001008) */
  __IO uint32_t PPC_ATTRIBVIOLS_CONFIG;            /* !< (@ 0x00001010) Peripheral Secure Access Attribute Violation
                                                      Configuration Register */
  __IO uint32_t PPC_ATTRIBVIOLP_CONFIG;            /* !< (@ 0x00001014) Peripheral Privilege Access Attribute Violation
                                                      Configuration Register */
  __IO uint32_t Reserved_3[2];                     /* !< (@ 0x00001018) */
  __IO uint32_t FPC_ATTRIBVIOLS_CONFIG;            /* !< (@ 0x00001020) Flash Secure Access Attribute Violation
                                                      Configuration Register */
  __IO uint32_t FPC_ATTRIBVIOLP_CONFIG;            /* !< (@ 0x00001024) Flash Privilege Access Attribute Violation
                                                      Configuration Register */
  __IO uint32_t Reserved_4[6];                     /* !< (@ 0x00001028) */
  __IO uint32_t FPC_HDPPROT0_CONFIG;               /* !< (@ 0x00001040) Flash Hide Protection for Bank0 Configuration
                                                      Register */
  __IO uint32_t FPC_HDPPROT1_CONFIG;               /* !< (@ 0x00001044) Flash Hide Protection for Bank1 Configuration
                                                      Register */
  __IO uint32_t Reserved_5;                        /* !< (@ 0x00001048) */
  __IO uint32_t FPC_HDPPROT_CONTROL;               /* !< (@ 0x0000104C) Flash Hide Protection Control Register */
  __IO uint32_t FPC_HDPEN_CONTROL;                 /* !< (@ 0x00001050) Flash Hide Protection Enable Control Register */
  __IO uint32_t FPC_NONMAIN0_HDPPROT_CONTROL;      /* !< (@ 0x00001054) Flash NONMAIN Bank0 Hide Protection Control
                                                      Register */
  __IO uint32_t FPC_NONMAIN1_HDPPROT_CONTROL;      /* !< (@ 0x00001058) Flash NONMAIN Bank1 Hide Protection Control
                                                      Register */
  __IO uint32_t FPC_TRIM0_HDPPROT_CONTROL;         /* !< (@ 0x0000105C) Flash TRIM Bank0 Hide Protection Control Register */
  __IO uint32_t FPC_TRIM1_HDPPROT_CONTROL;         /* !< (@ 0x00001060) Flash TRIM Bank1 Hide Protection Control Register */
  __IO uint32_t FPC_ENGR0_HDPPROT_CONTROL;         /* !< (@ 0x00001064) Flash ENGR Bank0 Hide Protection Control Register */
  __IO uint32_t FPC_ENGR1_HDPPROT_CONTROL;         /* !< (@ 0x00001068) Flash ENGR Bank1 Hide Protection Control Register */
  __IO uint32_t Reserved_6[5];                     /* !< (@ 0x0000106C) */
  __IO uint32_t FPC_HDPPROT_DBANK_CONFIG;          /* !< (@ 0x00001080) Data Flash Hide Protection Configuration Register */
  __IO uint32_t FPC_HDPPROT_DBANK_CONTROL;         /* !< (@ 0x00001084) Data Flash Hide Protection Control Register */
  __IO uint32_t FPC_HDPEN_DBANK_CONTROL;           /* !< (@ 0x00001088) Data Flash Hide Protection Enable Control Register */
  __IO uint32_t FPC_NONMAIN_HDPPROT_DBANK_CONTROL; /* !< (@ 0x0000108C) Data Flash NONMAIN Hide Protection Control
                                                      Register */
  __IO uint32_t FPC_TRIM_HDPPROT_DBANK_CONTROL;    /* !< (@ 0x00001090) Data Flash TRIM Hide Protection Control Register */
  __IO uint32_t FPC_ENGR_HDPPROT_DBANK_CONTROL;    /* !< (@ 0x00001094) Data Flash ENGR Hide Protection Control Register */
  __IO uint32_t Reserved_7[26];                    /* !< (@ 0x00001098) */
  __IO uint32_t PPC_SECATTRIB_ADC;                 /* !< (@ 0x00001100) Peripheral Secure Access ADC */
  __IO uint32_t Reserved_8;                        /* !< (@ 0x00001104) */
  __IO uint32_t PPC_SECATTRIB_TIMER;               /* !< (@ 0x00001108) Peripheral Secure Access Timer */
  __IO uint32_t Reserved_9;                        /* !< (@ 0x0000110C) */
  __IO uint32_t PPC_SECATTRIB_UNICOMM;             /* !< (@ 0x00001110) Peripheral Secure Access UniComm */
  __IO uint32_t Reserved_10;                       /* !< (@ 0x00001114) */
  __IO uint32_t PPC_SECATTRIB_GPIO;                /* !< (@ 0x00001118) Peripheral Secure Access GPIO */
  __IO uint32_t Reserved_11;                       /* !< (@ 0x0000111C) */
  __IO uint32_t PPC_SECATTRIB_MCAN;                /* !< (@ 0x00001120) Peripheral Secure Access CAN */
  __IO uint32_t Reserved_12;                       /* !< (@ 0x00001124) */
  __IO uint32_t PPC_SECATTRIB_I2S;                 /* !< (@ 0x00001128) Peripheral Secure Access I2S */
  __IO uint32_t Reserved_13;                       /* !< (@ 0x0000112C) */
  __IO uint32_t PPC_SECATTRIB_ACOMP;               /* !< (@ 0x00001130) Peripheral Secure Access Analog Comp */
  __IO uint32_t Reserved_14;                       /* !< (@ 0x00001134) */
  __IO uint32_t PPC_SECATTRIB_WDT;                 /* !< (@ 0x00001138) Peripheral Secure Access Watchdog */
  __IO uint32_t Reserved_15;                       /* !< (@ 0x0000113C) */
  __IO uint32_t PPC_SECATTRIB_LFSS;                /* !< (@ 0x00001140) Peripheral Secure Access LFSS */
  __IO uint32_t Reserved_16;                       /* !< (@ 0x00001144) */
  __IO uint32_t PPC_SECATTRIB_CRC;                 /* !< (@ 0x00001148) Peripheral Secure Access CRC */
  __IO uint32_t Reserved_17;                       /* !< (@ 0x0000114C) */
  __IO uint32_t PPC_SECATTRIB_AES;                 /* !< (@ 0x00001150) Peripheral Secure Access AES */
  __IO uint32_t Reserved_18;                       /* !< (@ 0x00001154) */
  __IO uint32_t PPC_SECATTRIB_SHA;                 /* !< (@ 0x00001158) Peripheral Secure Access SHA */
  __IO uint32_t Reserved_19;                       /* !< (@ 0x0000115C) */
  __IO uint32_t PPC_SECATTRIB_PKA;                 /* !< (@ 0x00001160) Peripheral Secure Access PKA */
  __IO uint32_t Reserved_20;                       /* !< (@ 0x00001164) */
  __IO uint32_t PPC_SECATTRIB_IOMUX;               /* !< (@ 0x00001168) Peripheral Secure Access IOMUX */
  __IO uint32_t Reserved_21;                       /* !< (@ 0x0000116C) */
  __IO uint32_t PPC_SECATTRIB_QSPI;                /* !< (@ 0x00001170) Peripheral Secure Access QSPI */
  __IO uint32_t Reserved_22;                       /* !< (@ 0x00001174) */
  __IO uint32_t PPC_SECATTRIB_TRNG;                /* !< (@ 0x00001178) Peripheral Secure Access TRNG */
  __IO uint32_t Reserved_23;                       /* !< (@ 0x0000117C) */
  __IO uint32_t PPC_SECATTRIB_DEBUGSS;             /* !< (@ 0x00001180) Peripheral Secure Access DEBUGSS */
  __IO uint32_t Reserved_24;                       /* !< (@ 0x00001184) */
  __IO uint32_t PPC_SECATTRIB_VREF;                /* !< (@ 0x00001188) Peripheral Secure Access VREF */
  __IO uint32_t Reserved_25;                       /* !< (@ 0x0000118C) */
  __IO uint32_t PPC_SECATTRIB_KEYSTORECTL;         /* !< (@ 0x00001190) Peripheral Secure Access KEYSTORECTL */
  __IO uint32_t Reserved_26;                       /* !< (@ 0x00001194) */
  __IO uint32_t PPC_SECATTRIB_EAM;                 /* !< (@ 0x00001198) Peripheral Secure Access EAM */
  __IO uint32_t Reserved_27;                       /* !< (@ 0x0000119C) */
  __IO uint32_t PPC_SECATTRIB_WUC;                 /* !< (@ 0x000011A0) Peripheral Secure Access WUC */
  __IO uint32_t Reserved_28;                       /* !< (@ 0x000011A4) */
  __IO uint32_t PPC_SECATTRIB_FRIREGS;             /* !< (@ 0x000011A8) Peripheral Secure Access FRIREGS */
  __IO uint32_t Reserved_29;                       /* !< (@ 0x000011AC) */
  __IO uint32_t PPC_SECATTRIB_MEMCFG;              /* !< (@ 0x000011B0) Peripheral Secure Access MEMCFG */
  __IO uint32_t Reserved_30[21];                   /* !< (@ 0x000011B4) */
  __IO uint32_t PPC_SECATTRIB_SYSCTL;              /* !< (@ 0x00001208) Peripheral Secure Access System Control */
  __IO uint32_t PPC_PRIVATTRIB_SYSCTL;             /* !< (@ 0x0000120C) Peripheral Privilege Access System Control */
  __IO uint32_t PPC_SECATTRIB_DMA;                 /* !< (@ 0x00001210) Peripheral Secure Access DMA */
  __IO uint32_t PPC_PRIVATTRIB_DMA;                /* !< (@ 0x00001214) Peripheral Privilege Access DMA */
  __IO uint32_t PPC_SECATTRIB_GSC;                 /* !< (@ 0x00001218) Peripheral Secure Access GSC */
  __IO uint32_t PPC_PRIVATTRIB_GSC;                /* !< (@ 0x0000121C) Peripheral Privilege Access GSC */
  __IO uint32_t PPC_SPARERW_GSC;                   /* !< (@ 0x00001220) Peripheral Spare RW Register */
  __IO uint32_t PPC_SPARERW1S_GSC;                 /* !< (@ 0x00001224) Peripheral Spare RW1S Register */
  __IO uint32_t Reserved_31[22];                   /* !< (@ 0x00001228) */
  __IO uint32_t SPC_SECATTRIB0;                    /* !< (@ 0x00001280) SRAM Secure Attribute-0 Register */
  __IO uint32_t SPC_SECATTRIB1;                    /* !< (@ 0x00001284) SRAM Secure Attribute-1 Register */
  __IO uint32_t SPC_SECATTRIB2;                    /* !< (@ 0x00001288) SRAM Secure Attribute-2 Register */
  __IO uint32_t SPC_SECATTRIB3;                    /* !< (@ 0x0000128C) SRAM Secure Attribute-3 Register */
  __IO uint32_t Reserved_32[12];                   /* !< (@ 0x00001290) */
  __IO uint32_t SPC_PRIVATTRIB0;                   /* !< (@ 0x000012C0) SRAM Privilege Attribute-0 Register */
  __IO uint32_t SPC_PRIVATTRIB1;                   /* !< (@ 0x000012C4) SRAM Privilege Attribute-1 Register */
  __IO uint32_t SPC_PRIVATTRIB2;                   /* !< (@ 0x000012C8) SRAM Privilege Attribute-2 Register */
  __IO uint32_t SPC_PRIVATTRIB3;                   /* !< (@ 0x000012CC) SRAM Privilege Attribute-3 Register */
  __IO uint32_t Reserved_33[12];                   /* !< (@ 0x000012D0) */
  __IO uint32_t FPC_SECATTRIBA0;                   /* !< (@ 0x00001300) Flash Secure Attribute Register A0 */
  __IO uint32_t FPC_SECATTRIBA1;                   /* !< (@ 0x00001304) Flash Secure Attribute Register A1 */
  __IO uint32_t FPC_SECATTRIBB0;                   /* !< (@ 0x00001308) Flash Secure Attribute Register B0 */
  __IO uint32_t FPC_SECATTRIBB1;                   /* !< (@ 0x0000130C) Flash Secure Attribute Register B1 */
  __IO uint32_t FPC_NONMAIN_SECATTRIB0;            /* !< (@ 0x00001310) Flash Non-Main Secure Attribute Register 0 */
  __IO uint32_t FPC_NONMAIN_SECATTRIB1;            /* !< (@ 0x00001314) Flash Non-Main Secure Attribute Register 1 */
  __IO uint32_t FPC_TRIM_SECATTRIB0;               /* !< (@ 0x00001318) Flash Trim Secure Attribute Register 0 */
  __IO uint32_t FPC_TRIM_SECATTRIB1;               /* !< (@ 0x0000131C) Flash Trim Secure Attribute Register 1 */
  __IO uint32_t FPC_ENGR_SECATTRIB0;               /* !< (@ 0x00001320) Flash Engr Secure Attribute Register 0 */
  __IO uint32_t FPC_ENGR_SECATTRIB1;               /* !< (@ 0x00001324) Flash Engr Secure Attribute Register 1 */
  __IO uint32_t Reserved_34[22];                   /* !< (@ 0x00001328) */
  __IO uint32_t FPC_SECATTRIBA_DFLASH;             /* !< (@ 0x00001380) Data Flash Secure Attribute Register A */
  __IO uint32_t FPC_ENGR_SECATTRIB_DFLASH;         /* !< (@ 0x00001384) Data Flash ENGR Secure Attribute Register */
  __IO uint32_t FPC_NONMAIN_SECATTRIB_DFLASH;      /* !< (@ 0x00001388) Data Flash Non-Main Secure Attribute Register */
  __IO uint32_t Reserved_35[29];                   /* !< (@ 0x0000138C) */
  __IO uint32_t FPC_PRIVATTRIBA0;                  /* !< (@ 0x00001400) Flash Privilege Attribute Register A0 */
  __IO uint32_t FPC_PRIVATTRIBA1;                  /* !< (@ 0x00001404) Flash Privilege Attribute Register A1 */
  __IO uint32_t FPC_PRIVATTRIBB0;                  /* !< (@ 0x00001408) Flash Privilege Attribute Register B0 */
  __IO uint32_t FPC_PRIVATTRIBB1;                  /* !< (@ 0x0000140C) Flash Privilege Attribute Register B1 */
  __IO uint32_t FPC_NONMAIN_PRIVATTRIB0;           /* !< (@ 0x00001410) Flash Non-Main Privilege Attribute Register B0 */
  __IO uint32_t FPC_NONMAIN_PRIVATTRIB1;           /* !< (@ 0x00001414) Flash Non-Main Privilege Attribute Register B1 */
  __IO uint32_t FPC_TRIM_PRIVATTRIB0;              /* !< (@ 0x00001418) Flash Trim Privilege Attribute Register B0 */
  __IO uint32_t FPC_TRIM_PRIVATTRIB1;              /* !< (@ 0x0000141C) Flash Trim Privilege Attribute Register B1 */
  __IO uint32_t FPC_ENGR_PRIVATTRIB0;              /* !< (@ 0x00001420) Flash Engr Privilege Attribute Register B0 */
  __IO uint32_t FPC_ENGR_PRIVATTRIB1;              /* !< (@ 0x00001424) Flash Engr Privilege Attribute Register B1 */
  __IO uint32_t Reserved_36[22];                   /* !< (@ 0x00001428) */
  __IO uint32_t FPC_PRIVATTRIBA_DFLASH;            /* !< (@ 0x00001480) Data Flash Privilege Attribute Register */
  __IO uint32_t FPC_NONMAIN_PRIVATTRIB_DFLASH;     /* !< (@ 0x00001484) Data Flash NONMAIN Privilege Attribute Register */
  __IO uint32_t FPC_ENGR_PRIVATTRIB_DFLASH;        /* !< (@ 0x00001488) Data Flash ENGR Privilege Attribute Register */
  __IO uint32_t Reserved_37[93];                   /* !< (@ 0x0000148C) */
  __IO uint32_t FPC_WEPROTA0;                      /* !< (@ 0x00001600) Flash Write Protect Attribute Register A0 */
  __IO uint32_t FPC_WEPROTA1;                      /* !< (@ 0x00001604) Flash Write Protect Attribute Register A1 */
  __IO uint32_t FPC_WEPROTB0;                      /* !< (@ 0x00001608) Flash Write Protect Attribute Register B0 */
  __IO uint32_t FPC_WEPROTB1;                      /* !< (@ 0x0000160C) Flash Write Protect Attribute Register B1 */
  __IO uint32_t FPC_WEPROTNONMAIN0;                /* !< (@ 0x00001610) Flash Non-Main Write Protect Attribute Register B0 */
  __IO uint32_t FPC_WEPROTNONMAIN1;                /* !< (@ 0x00001614) Flash Non-Main Write Protect Attribute Register B1 */
  __IO uint32_t FPC_WEPROTTRIM0;                   /* !< (@ 0x00001618) Flash Trim Write Protect Attribute Register B0 */
  __IO uint32_t FPC_WEPROTTRIM1;                   /* !< (@ 0x0000161C) Flash Trim Write Protect Attribute Register B1 */
  __IO uint32_t FPC_WEPROTENGR0;                   /* !< (@ 0x00001620) Flash Engr Write Protect Attribute Register B0 */
  __IO uint32_t FPC_WEPROTENGR1;                   /* !< (@ 0x00001624) Flash Engr Write Protect Attribute Register B1 */
  __IO uint32_t Reserved_38[54];                   /* !< (@ 0x00001628) */
  __IO uint32_t FPC_WEPROTA_DFLASH;                /* !< (@ 0x00001700) Data Flash Write Protect Attribute Register A */
  __IO uint32_t FPC_WEPROT_NONMAIN_DFLASH;         /* !< (@ 0x00001704) DATA Flash Non- Main Write Protect Attribute
                                                      Register */
  __IO uint32_t FPC_WEPROT_ENGR_DFLASH;            /* !< (@ 0x00001708) DATA Flash ENGR Write Protect Attribute Register */
  __IO uint32_t Reserved_39[61];                   /* !< (@ 0x0000170C) */
  __IO uint32_t FPC_FLSEMREQ;                      /* !< (@ 0x00001800) Flash semaphore request register */
  __IO uint32_t FPC_FLSEMCLR;                      /* !< (@ 0x00001804) Flash semaphore release register */
  __IO uint32_t FPC_FLSEMSTAT;                     /* !< (@ 0x00001808) Flash semaphore statys registers */
  __IO uint32_t Reserved_40[157];                  /* !< (@ 0x0000180C) */
  __IO uint32_t DMA_TRIG_SEL;                      /* !< (@ 0x00001A80) DMA Trigger Selection register */
  __IO uint32_t DMA_FIX_TRIG_SEL;                  /* !< (@ 0x00001A84) DMA Fixed Trigger Selection register */
  __IO uint32_t Reserved_41[62];                   /* !< (@ 0x00001A88) */
  __IO uint32_t VTOR_S;                            /* !< (@ 0x00001B80) Secure Vector Table Offset Register */
  __IO uint32_t VTOR_NS;                           /* !< (@ 0x00001B84) Non - Secure Vector Table Offset Register */
  __IO uint32_t Reserved_42[62];                   /* !< (@ 0x00001B88) */
  __IO uint32_t DTB_MUXSEL;                        /* !< (@ 0x00001C80) Digital Test Bus MUX Selection */
  __IO uint32_t Reserved_43[31];                   /* !< (@ 0x00001C84) */
  __IO uint32_t DICE_CHECKSUM0;                    /* !< (@ 0x00001D00) DICE checksum data register-0 */
  __IO uint32_t DICE_CHECKSUM1;                    /* !< (@ 0x00001D04) DICE checksum data register-1 */
  __IO uint32_t DICE_CHECKSUM2;                    /* !< (@ 0x00001D08) DICE checksum data register-2 */
  __IO uint32_t DICE_CHECKSUM3;                    /* !< (@ 0x00001D0C) DICE checksum data register-3 */
  __IO uint32_t DICE_CHECKSUM4;                    /* !< (@ 0x00001D10) DICE checksum data register-4 */
  __IO uint32_t DICE_CHECKSUM5;                    /* !< (@ 0x00001D14) DICE checksum data register-5 */
  __IO uint32_t DICE_CHECKSUM6;                    /* !< (@ 0x00001D18) DICE checksum data register-6 */
  __IO uint32_t DICE_CHECKSUM7;                    /* !< (@ 0x00001D1C) DICE checksum data register-7 */
  __IO uint32_t Reserved_44[24];                   /* !< (@ 0x00001D20) */
  __IO uint32_t GSC_LOCK;                          /* !< (@ 0x00001D80) GSC Lock configuration register */
  __IO uint32_t GSC_COMMIT;                        /* !< (@ 0x00001D84) GSC commit configuration register */
  __IO uint32_t Reserved_45[157];                  /* !< (@ 0x00001D88) */
  __IO uint32_t GSC_REVISION;                      /* !< (@ 0x00001FFC) GSC Revision register */
} GSC_Regs;

/*@}*/ /* end of group GSC */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* GSC Register Control Bits
******************************************************************************/

/* GSC_SPC_ATTRIBVIOLS_CONFIG Bits */
/* GSC_SPC_ATTRIBVIOLS_CONFIG[SECVIOL] Bits */
#define GSC_SPC_ATTRIBVIOLS_CONFIG_SECVIOL_OFS   (0)                             /* !< SECVIOL Offset */
#define GSC_SPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK  ((uint32_t)0x00000001U)         /* !< Controls the behavior of secure
                                                                                    access to non-secure SRAM #br#0:
                                                                                    Access is allowed #br#1: Access
                                                                                    generates bus-fault and NMI */

/* GSC_SPC_ATTRIBVIOLP_CONFIG Bits */
/* GSC_SPC_ATTRIBVIOLP_CONFIG[PRIVVIOL] Bits */
#define GSC_SPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_OFS  (0)                             /* !< PRIVVIOL Offset */
#define GSC_SPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK ((uint32_t)0x00000001U)         /* !< Controls the behavior of privilege
                                                                                    access to non-privilege SRAM #br#0:
                                                                                    Access is allowed #br#1: Access
                                                                                    generates bus-fault and NMI */

/* GSC_PPC_ATTRIBVIOLS_CONFIG Bits */
/* GSC_PPC_ATTRIBVIOLS_CONFIG[SECVIOL] Bits */
#define GSC_PPC_ATTRIBVIOLS_CONFIG_SECVIOL_OFS   (0)                             /* !< SECVIOL Offset */
#define GSC_PPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK  ((uint32_t)0x00000001U)         /* !< Controls the behavior of secure
                                                                                    access to non-secure peripheral
                                                                                    #br#0: Access is allowed #br#1:
                                                                                    Access generates bus-fault and NMI */

/* GSC_PPC_ATTRIBVIOLP_CONFIG Bits */
/* GSC_PPC_ATTRIBVIOLP_CONFIG[PRIVVIOL] Bits */
#define GSC_PPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_OFS  (0)                             /* !< PRIVVIOL Offset */
#define GSC_PPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK ((uint32_t)0x00000001U)         /* !< Controls the behavior of privilege
                                                                                    access to non-privilege peripherals
                                                                                    #br#0: Access is allowed #br#1:
                                                                                    Access generates bus-fault and NMI */

/* GSC_FPC_ATTRIBVIOLS_CONFIG Bits */
/* GSC_FPC_ATTRIBVIOLS_CONFIG[SECVIOL] Bits */
#define GSC_FPC_ATTRIBVIOLS_CONFIG_SECVIOL_OFS   (0)                             /* !< SECVIOL Offset */
#define GSC_FPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK  ((uint32_t)0x00000001U)         /* !< Controls the behavior of secure
                                                                                    access to non-secure Flash #br#0:
                                                                                    Access is allowed #br#1: Access
                                                                                    generates bus-fault and NMI */

/* GSC_FPC_ATTRIBVIOLP_CONFIG Bits */
/* GSC_FPC_ATTRIBVIOLP_CONFIG[PRIVVIOL] Bits */
#define GSC_FPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_OFS  (0)                             /* !< PRIVVIOL Offset */
#define GSC_FPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK ((uint32_t)0x00000001U)         /* !< Controls the behavior of privilege
                                                                                    access to non-privilege Flash #br#0:
                                                                                    Access is allowed #br#1: Access
                                                                                    generates bus-fault and NMI */

/* GSC_FPC_HDPPROT0_CONFIG Bits */
/* GSC_FPC_HDPPROT0_CONFIG[HDPEND] Bits */
#define GSC_FPC_HDPPROT0_CONFIG_HDPEND_OFS       (0)                             /* !< HDPEND Offset */
#define GSC_FPC_HDPPROT0_CONFIG_HDPEND_MASK      ((uint32_t)0x000000FFU)         /* !< Sector number where hide protection
                                                                                    ends */
/* GSC_FPC_HDPPROT0_CONFIG[HDPSTART] Bits */
#define GSC_FPC_HDPPROT0_CONFIG_HDPSTART_OFS     (16)                            /* !< HDPSTART Offset */
#define GSC_FPC_HDPPROT0_CONFIG_HDPSTART_MASK    ((uint32_t)0x00FF0000U)         /* !< Sector number where hide protection
                                                                                    starts */

/* GSC_FPC_HDPPROT1_CONFIG Bits */
/* GSC_FPC_HDPPROT1_CONFIG[HDPEND] Bits */
#define GSC_FPC_HDPPROT1_CONFIG_HDPEND_OFS       (0)                             /* !< HDPEND Offset */
#define GSC_FPC_HDPPROT1_CONFIG_HDPEND_MASK      ((uint32_t)0x000000FFU)         /* !< Sector number where hide protection
                                                                                    ends */
/* GSC_FPC_HDPPROT1_CONFIG[HDPSTART] Bits */
#define GSC_FPC_HDPPROT1_CONFIG_HDPSTART_OFS     (16)                            /* !< HDPSTART Offset */
#define GSC_FPC_HDPPROT1_CONFIG_HDPSTART_MASK    ((uint32_t)0x00FF0000U)         /* !< Sector number where hide protection
                                                                                    starts */

/* GSC_FPC_HDPPROT_CONTROL Bits */
/* GSC_FPC_HDPPROT_CONTROL[HDPPROT0ACCDIS] Bits */
#define GSC_FPC_HDPPROT_CONTROL_HDPPROT0ACCDIS_OFS (0)                             /* !< HDPPROT0ACCDIS Offset */
#define GSC_FPC_HDPPROT_CONTROL_HDPPROT0ACCDIS_MASK ((uint32_t)0x00000001U)         /* !< Enables the FPC_HDPPROT0_CONFIG to
                                                                                    take effect. #br#0: HDP region access
                                                                                    is enabled #br#1: HDP region access
                                                                                    is disabled */
/* GSC_FPC_HDPPROT_CONTROL[HDPPROT1ACCDIS] Bits */
#define GSC_FPC_HDPPROT_CONTROL_HDPPROT1ACCDIS_OFS (1)                             /* !< HDPPROT1ACCDIS Offset */
#define GSC_FPC_HDPPROT_CONTROL_HDPPROT1ACCDIS_MASK ((uint32_t)0x00000002U)         /* !< Enables the FPC_HDPPROT1_CONFIG to
                                                                                    take effect. #br#0: HDP region access
                                                                                    is enabled #br#1: HDP region access
                                                                                    is disabled */

/* GSC_FPC_HDPEN_CONTROL Bits */
/* GSC_FPC_HDPEN_CONTROL[HDPEN] Bits */
#define GSC_FPC_HDPEN_CONTROL_HDPEN_OFS          (0)                             /* !< HDPEN Offset */
#define GSC_FPC_HDPEN_CONTROL_HDPEN_MASK         ((uint32_t)0x00000001U)         /* !< HDP mode enable. This bit is set in
                                                                                    the OTP during provisioning.  #br#0:
                                                                                    HDP mode is not used #br#1: HDP mode
                                                                                    is enabled */

/* GSC_FPC_NONMAIN0_HDPPROT_CONTROL Bits */
/* GSC_FPC_NONMAIN0_HDPPROT_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_NONMAIN0_HDPPROT_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_NONMAIN0_HDPPROT_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x0000000FU)         /* !< Enable HDP access to NONMAIN region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */

/* GSC_FPC_NONMAIN1_HDPPROT_CONTROL Bits */
/* GSC_FPC_NONMAIN1_HDPPROT_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_NONMAIN1_HDPPROT_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_NONMAIN1_HDPPROT_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x0000000FU)         /* !< Enable HDP access to NONMAIN region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */

/* GSC_FPC_TRIM0_HDPPROT_CONTROL Bits */
/* GSC_FPC_TRIM0_HDPPROT_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_TRIM0_HDPPROT_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_TRIM0_HDPPROT_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x00000001U)         /* !< Enable HDP access to TRIM region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */
/* GSC_FPC_TRIM0_HDPPROT_CONTROL[HDPROTACCDIS1] Bits */
#define GSC_FPC_TRIM0_HDPPROT_CONTROL_HDPROTACCDIS1_OFS (1)                             /* !< HDPROTACCDIS1 Offset */
#define GSC_FPC_TRIM0_HDPPROT_CONTROL_HDPROTACCDIS1_MASK ((uint32_t)0x00000002U)         /* !< No functionality implemented for
                                                                                    this bit */

/* GSC_FPC_TRIM1_HDPPROT_CONTROL Bits */
/* GSC_FPC_TRIM1_HDPPROT_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_TRIM1_HDPPROT_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_TRIM1_HDPPROT_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x00000001U)         /* !< Enable HDP access to TRIM region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */
/* GSC_FPC_TRIM1_HDPPROT_CONTROL[HDPROTACCDIS1] Bits */
#define GSC_FPC_TRIM1_HDPPROT_CONTROL_HDPROTACCDIS1_OFS (1)                             /* !< HDPROTACCDIS1 Offset */
#define GSC_FPC_TRIM1_HDPPROT_CONTROL_HDPROTACCDIS1_MASK ((uint32_t)0x00000002U)         /* !< No functionality implemented for
                                                                                    this bit */

/* GSC_FPC_ENGR0_HDPPROT_CONTROL Bits */
/* GSC_FPC_ENGR0_HDPPROT_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_ENGR0_HDPPROT_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_ENGR0_HDPPROT_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x00000001U)         /* !< Enable HDP access to ENGR region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */
/* GSC_FPC_ENGR0_HDPPROT_CONTROL[HDPROTACCDIS1] Bits */
#define GSC_FPC_ENGR0_HDPPROT_CONTROL_HDPROTACCDIS1_OFS (1)                             /* !< HDPROTACCDIS1 Offset */
#define GSC_FPC_ENGR0_HDPPROT_CONTROL_HDPROTACCDIS1_MASK ((uint32_t)0x00000002U)         /* !< No functionality implemented for
                                                                                    this bit */

/* GSC_FPC_ENGR1_HDPPROT_CONTROL Bits */
/* GSC_FPC_ENGR1_HDPPROT_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_ENGR1_HDPPROT_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_ENGR1_HDPPROT_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x00000001U)         /* !< Enable HDP access to ENGR region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */
/* GSC_FPC_ENGR1_HDPPROT_CONTROL[HDPROTACCDIS1] Bits */
#define GSC_FPC_ENGR1_HDPPROT_CONTROL_HDPROTACCDIS1_OFS (1)                             /* !< HDPROTACCDIS1 Offset */
#define GSC_FPC_ENGR1_HDPPROT_CONTROL_HDPROTACCDIS1_MASK ((uint32_t)0x00000002U)         /* !< No functionality implemented for
                                                                                    this bit */

/* GSC_FPC_HDPPROT_DBANK_CONFIG Bits */
/* GSC_FPC_HDPPROT_DBANK_CONFIG[HDPEND] Bits */
#define GSC_FPC_HDPPROT_DBANK_CONFIG_HDPEND_OFS  (0)                             /* !< HDPEND Offset */
#define GSC_FPC_HDPPROT_DBANK_CONFIG_HDPEND_MASK ((uint32_t)0x0000000FU)         /* !< Sector number where hide protection
                                                                                    ends */
/* GSC_FPC_HDPPROT_DBANK_CONFIG[HDPSTART] Bits */
#define GSC_FPC_HDPPROT_DBANK_CONFIG_HDPSTART_OFS (16)                            /* !< HDPSTART Offset */
#define GSC_FPC_HDPPROT_DBANK_CONFIG_HDPSTART_MASK ((uint32_t)0x000F0000U)         /* !< Sector number where hide protection
                                                                                    starts */

/* GSC_FPC_HDPPROT_DBANK_CONTROL Bits */
/* GSC_FPC_HDPPROT_DBANK_CONTROL[HDPPROTACCDIS] Bits */
#define GSC_FPC_HDPPROT_DBANK_CONTROL_HDPPROTACCDIS_OFS (0)                             /* !< HDPPROTACCDIS Offset */
#define GSC_FPC_HDPPROT_DBANK_CONTROL_HDPPROTACCDIS_MASK ((uint32_t)0x00000001U)         /* !< Enables the HDP register to take
                                                                                    effect for Databank #br#0: HDP region
                                                                                    access is enabled #br#1: HDP region
                                                                                    access is disabled */

/* GSC_FPC_HDPEN_DBANK_CONTROL Bits */
/* GSC_FPC_HDPEN_DBANK_CONTROL[HDPEN] Bits */
#define GSC_FPC_HDPEN_DBANK_CONTROL_HDPEN_OFS    (0)                             /* !< HDPEN Offset */
#define GSC_FPC_HDPEN_DBANK_CONTROL_HDPEN_MASK   ((uint32_t)0x00000001U)         /* !< HDP mode enable. This bit is set in
                                                                                    the OTP during provisioning and
                                                                                    copied from the OTP memory during
                                                                                    boot by BOOTROM.  #br#0: HDP mode is
                                                                                    not used #br#1: HDP mode is enabled */

/* GSC_FPC_NONMAIN_HDPPROT_DBANK_CONTROL Bits */
/* GSC_FPC_NONMAIN_HDPPROT_DBANK_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_NONMAIN_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_NONMAIN_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x0000000FU)         /* !< Enable HDP access to NONMAIN region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */

/* GSC_FPC_TRIM_HDPPROT_DBANK_CONTROL Bits */
/* GSC_FPC_TRIM_HDPPROT_DBANK_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_TRIM_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_TRIM_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x00000003U)         /* !< Enable HDP access to TRIM region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */

/* GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL Bits */
/* GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL[HDPROTACCDIS] Bits */
#define GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_OFS (0)                             /* !< HDPROTACCDIS Offset */
#define GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK ((uint32_t)0x00000001U)         /* !< Enable HDP access to ENGR region
                                                                                    #br#0: HDP region access is enabled
                                                                                    #br#1: HDP region access is disabled */
/* GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL[HDPROTACCDIS1] Bits */
#define GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL_HDPROTACCDIS1_OFS (1)                             /* !< HDPROTACCDIS1 Offset */
#define GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL_HDPROTACCDIS1_MASK ((uint32_t)0x00000002U)         /* !< No functionality implemented for
                                                                                    this bit */

/* GSC_PPC_SECATTRIB_ADC Bits */
/* GSC_PPC_SECATTRIB_ADC[SEC_ADC0] Bits */
#define GSC_PPC_SECATTRIB_ADC_SEC_ADC0_OFS       (0)                             /* !< SEC_ADC0 Offset */
#define GSC_PPC_SECATTRIB_ADC_SEC_ADC0_MASK      ((uint32_t)0x00000001U)         /* !< Secure access enabled to ADC0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_ADC[SEC_ADC1] Bits */
#define GSC_PPC_SECATTRIB_ADC_SEC_ADC1_OFS       (1)                             /* !< SEC_ADC1 Offset */
#define GSC_PPC_SECATTRIB_ADC_SEC_ADC1_MASK      ((uint32_t)0x00000002U)         /* !< Secure access enabled to ADC1
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_TIMER Bits */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMA0_0] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_0_OFS  (0)                             /* !< SEC_TIMA0_0 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_0_MASK ((uint32_t)0x00000001U)         /* !< Secure access enabled to TIMA0_0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMA0_1] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_1_OFS  (1)                             /* !< SEC_TIMA0_1 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_1_MASK ((uint32_t)0x00000002U)         /* !< Secure access enabled to TIMA0_1
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMG4_0] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_0_OFS  (8)                             /* !< SEC_TIMG4_0 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_0_MASK ((uint32_t)0x00000100U)         /* !< Secure access enabled to TIMG4_0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMG4_1] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_1_OFS  (9)                             /* !< SEC_TIMG4_1 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_1_MASK ((uint32_t)0x00000200U)         /* !< Secure access enabled to TIMG4_1
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMG4_2] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_2_OFS  (10)                            /* !< SEC_TIMG4_2 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_2_MASK ((uint32_t)0x00000400U)         /* !< Secure access enabled to TIMG4_2
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMG4_3] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_3_OFS  (11)                            /* !< SEC_TIMG4_3 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_3_MASK ((uint32_t)0x00000800U)         /* !< Secure access enabled to TIMG4_3
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMG12_0] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG12_0_OFS (16)                            /* !< SEC_TIMG12_0 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG12_0_MASK ((uint32_t)0x00010000U)         /* !< Secure access enabled to TIMG12_0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMG8_0] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_0_OFS  (24)                            /* !< SEC_TIMG8_0 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_0_MASK ((uint32_t)0x01000000U)         /* !< Secure access enabled to TIMG8_0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_TIMER[SEC_TIMG8_1] Bits */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_1_OFS  (25)                            /* !< SEC_TIMG8_1 Offset */
#define GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_1_MASK ((uint32_t)0x02000000U)         /* !< Secure access enabled to TIMG8_1
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_UNICOMM Bits */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC1_0] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_0_OFS   (0)                             /* !< SEC_UC1_0 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_0_MASK  ((uint32_t)0x00000001U)         /* !< Secure access enabled to UniComm
                                                                                    UC1_0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC1_1] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_1_OFS   (1)                             /* !< SEC_UC1_1 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_1_MASK  ((uint32_t)0x00000002U)         /* !< Secure access enabled to UniComm
                                                                                    UC1_1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC2] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC2_OFS   (2)                             /* !< SEC_UC2 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC2_MASK  ((uint32_t)0x00000004U)         /* !< Secure access enabled to UniComm
                                                                                    UC2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC15_0] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_0_OFS   (3)                             /* !< SEC_UC15_0 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_0_MASK  ((uint32_t)0x00000008U)         /* !< Secure access enabled to UniComm
                                                                                    UC15_0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC15_1] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_1_OFS   (4)                             /* !< SEC_UC15_1 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_1_MASK  ((uint32_t)0x00000010U)         /* !< Secure access enabled to UniComm
                                                                                    UC15_1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC12] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC12_OFS   (5)                             /* !< SEC_UC12 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC12_MASK  ((uint32_t)0x00000020U)         /* !< Secure access enabled to UniComm
                                                                                    UC12 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC13_0] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_0_OFS   (6)                             /* !< SEC_UC13_0 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_0_MASK  ((uint32_t)0x00000040U)         /* !< Secure access enabled to UniComm
                                                                                    UC13_0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC13_1] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_1_OFS   (7)                             /* !< SEC_UC13_1 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_1_MASK  ((uint32_t)0x00000080U)         /* !< Secure access enabled to UniComm
                                                                                    UC13_1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC13_2] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_2_OFS   (8)                             /* !< SEC_UC13_2 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_2_MASK  ((uint32_t)0x00000100U)         /* !< Secure access enabled to UniComm
                                                                                    UC13_2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC13_3] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_3_OFS   (9)                             /* !< SEC_UC13_3 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_3_MASK  ((uint32_t)0x00000200U)         /* !< Secure access enabled to UniComm
                                                                                    UC13_3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_PPC_SECATTRIB_UNICOMM[SEC_UC14] Bits */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC14_OFS   (10)                            /* !< SEC_UC14 Offset */
#define GSC_PPC_SECATTRIB_UNICOMM_SEC_UC14_MASK  ((uint32_t)0x00000400U)         /* !< Secure access enabled to UniComm
                                                                                    UC14 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_PPC_SECATTRIB_GPIO Bits */
/* GSC_PPC_SECATTRIB_GPIO[SEC_GPIOA] Bits */
#define GSC_PPC_SECATTRIB_GPIO_SEC_GPIOA_OFS     (0)                             /* !< SEC_GPIOA Offset */
#define GSC_PPC_SECATTRIB_GPIO_SEC_GPIOA_MASK    ((uint32_t)0x00000001U)         /* !< Secure access enabled to GPIO A
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_GPIO[SEC_GPIOB] Bits */
#define GSC_PPC_SECATTRIB_GPIO_SEC_GPIOB_OFS     (1)                             /* !< SEC_GPIOB Offset */
#define GSC_PPC_SECATTRIB_GPIO_SEC_GPIOB_MASK    ((uint32_t)0x00000002U)         /* !< Secure access enabled to GPIO B
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_GPIO[SEC_GPIOC] Bits */
#define GSC_PPC_SECATTRIB_GPIO_SEC_GPIOC_OFS     (2)                             /* !< SEC_GPIOC Offset */
#define GSC_PPC_SECATTRIB_GPIO_SEC_GPIOC_MASK    ((uint32_t)0x00000004U)         /* !< Secure access enabled to GPIO C
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_MCAN Bits */
/* GSC_PPC_SECATTRIB_MCAN[SEC_MCAN0] Bits */
#define GSC_PPC_SECATTRIB_MCAN_SEC_MCAN0_OFS     (0)                             /* !< SEC_MCAN0 Offset */
#define GSC_PPC_SECATTRIB_MCAN_SEC_MCAN0_MASK    ((uint32_t)0x00000001U)         /* !< Secure access enabled to MCAN 0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_MCAN[SEC_MCAN1] Bits */
#define GSC_PPC_SECATTRIB_MCAN_SEC_MCAN1_OFS     (1)                             /* !< SEC_MCAN1 Offset */
#define GSC_PPC_SECATTRIB_MCAN_SEC_MCAN1_MASK    ((uint32_t)0x00000002U)         /* !< Secure access enabled to MCAN 1
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_I2S Bits */
/* GSC_PPC_SECATTRIB_I2S[SEC_I2S0] Bits */
#define GSC_PPC_SECATTRIB_I2S_SEC_I2S0_OFS       (0)                             /* !< SEC_I2S0 Offset */
#define GSC_PPC_SECATTRIB_I2S_SEC_I2S0_MASK      ((uint32_t)0x00000001U)         /* !< Secure access enabled to I2S 0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_I2S[SEC_I2S1] Bits */
#define GSC_PPC_SECATTRIB_I2S_SEC_I2S1_OFS       (1)                             /* !< SEC_I2S1 Offset */
#define GSC_PPC_SECATTRIB_I2S_SEC_I2S1_MASK      ((uint32_t)0x00000002U)         /* !< Secure access enabled to I2S 1
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_ACOMP Bits */
/* GSC_PPC_SECATTRIB_ACOMP[SEC_ACOMP0] Bits */
#define GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP0_OFS   (0)                             /* !< SEC_ACOMP0 Offset */
#define GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP0_MASK  ((uint32_t)0x00000001U)         /* !< Secure access enabled to Comparator
                                                                                    0 #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_ACOMP[SEC_ACOMP1] Bits */
#define GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP1_OFS   (1)                             /* !< SEC_ACOMP1 Offset */
#define GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP1_MASK  ((uint32_t)0x00000002U)         /* !< Secure access enabled to Comparator
                                                                                    1 #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_WDT Bits */
/* GSC_PPC_SECATTRIB_WDT[SEC_WWDT] Bits */
#define GSC_PPC_SECATTRIB_WDT_SEC_WWDT_OFS       (0)                             /* !< SEC_WWDT Offset */
#define GSC_PPC_SECATTRIB_WDT_SEC_WWDT_MASK      ((uint32_t)0x00000001U)         /* !< Secure access enabled to Windowed
                                                                                    Watchdog #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_PPC_SECATTRIB_LFSS Bits */
/* GSC_PPC_SECATTRIB_LFSS[SEC_LFSS] Bits */
#define GSC_PPC_SECATTRIB_LFSS_SEC_LFSS_OFS      (0)                             /* !< SEC_LFSS Offset */
#define GSC_PPC_SECATTRIB_LFSS_SEC_LFSS_MASK     ((uint32_t)0x00000001U)         /* !< Secure access enabled to LFSS
                                                                                    (including peripherals inside LFSS
                                                                                    e.g. IWDT) #br#0: Non-secure access
                                                                                    is enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_PPC_SECATTRIB_CRC Bits */
/* GSC_PPC_SECATTRIB_CRC[SEC_CRC] Bits */
#define GSC_PPC_SECATTRIB_CRC_SEC_CRC_OFS        (0)                             /* !< SEC_CRC Offset */
#define GSC_PPC_SECATTRIB_CRC_SEC_CRC_MASK       ((uint32_t)0x00000001U)         /* !< Secure access enabled to CRC #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_PPC_SECATTRIB_AES Bits */
/* GSC_PPC_SECATTRIB_AES[SEC_AES] Bits */
#define GSC_PPC_SECATTRIB_AES_SEC_AES_OFS        (0)                             /* !< SEC_AES Offset */
#define GSC_PPC_SECATTRIB_AES_SEC_AES_MASK       ((uint32_t)0x00000001U)         /* !< Secure access enabled to AES #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_PPC_SECATTRIB_SHA Bits */
/* GSC_PPC_SECATTRIB_SHA[SEC_SHA] Bits */
#define GSC_PPC_SECATTRIB_SHA_SEC_SHA_OFS        (0)                             /* !< SEC_SHA Offset */
#define GSC_PPC_SECATTRIB_SHA_SEC_SHA_MASK       ((uint32_t)0x00000001U)         /* !< Secure access enabled to SHA #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_PPC_SECATTRIB_PKA Bits */
/* GSC_PPC_SECATTRIB_PKA[SEC_PKA] Bits */
#define GSC_PPC_SECATTRIB_PKA_SEC_PKA_OFS        (0)                             /* !< SEC_PKA Offset */
#define GSC_PPC_SECATTRIB_PKA_SEC_PKA_MASK       ((uint32_t)0x00000001U)         /* !< Secure access enabled to PKA #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_PPC_SECATTRIB_IOMUX Bits */
/* GSC_PPC_SECATTRIB_IOMUX[SEC_IOMUX] Bits */
#define GSC_PPC_SECATTRIB_IOMUX_SEC_IOMUX_OFS    (0)                             /* !< SEC_IOMUX Offset */
#define GSC_PPC_SECATTRIB_IOMUX_SEC_IOMUX_MASK   ((uint32_t)0x00000001U)         /* !< Secure access enabled to IOMUX
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_QSPI Bits */
/* GSC_PPC_SECATTRIB_QSPI[SEC_QSPI] Bits */
#define GSC_PPC_SECATTRIB_QSPI_SEC_QSPI_OFS      (0)                             /* !< SEC_QSPI Offset */
#define GSC_PPC_SECATTRIB_QSPI_SEC_QSPI_MASK     ((uint32_t)0x00000001U)         /* !< Secure access enabled to QSPI
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_TRNG Bits */
/* GSC_PPC_SECATTRIB_TRNG[SEC_TRNG] Bits */
#define GSC_PPC_SECATTRIB_TRNG_SEC_TRNG_OFS      (0)                             /* !< SEC_TRNG Offset */
#define GSC_PPC_SECATTRIB_TRNG_SEC_TRNG_MASK     ((uint32_t)0x00000001U)         /* !< Secure access enabled to TRNG
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_DEBUGSS Bits */
/* GSC_PPC_SECATTRIB_DEBUGSS[SEC_DEBUGSS] Bits */
#define GSC_PPC_SECATTRIB_DEBUGSS_SEC_DEBUGSS_OFS (0)                             /* !< SEC_DEBUGSS Offset */
#define GSC_PPC_SECATTRIB_DEBUGSS_SEC_DEBUGSS_MASK ((uint32_t)0x00000001U)         /* !< Secure access enabled to DEBUGSS
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_VREF Bits */
/* GSC_PPC_SECATTRIB_VREF[SEC_VREF] Bits */
#define GSC_PPC_SECATTRIB_VREF_SEC_VREF_OFS      (0)                             /* !< SEC_VREF Offset */
#define GSC_PPC_SECATTRIB_VREF_SEC_VREF_MASK     ((uint32_t)0x00000001U)         /* !< Secure access enabled to VREF
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_KEYSTORECTL Bits */
/* GSC_PPC_SECATTRIB_KEYSTORECTL[SEC_KEYSTORECTL] Bits */
#define GSC_PPC_SECATTRIB_KEYSTORECTL_SEC_KEYSTORECTL_OFS (0)                             /* !< SEC_KEYSTORECTL Offset */
#define GSC_PPC_SECATTRIB_KEYSTORECTL_SEC_KEYSTORECTL_MASK ((uint32_t)0x00000001U)         /* !< Secure access enabled to
                                                                                    KEYSTORECTL #br#0: Non-secure access
                                                                                    is enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_PPC_SECATTRIB_EAM Bits */
/* GSC_PPC_SECATTRIB_EAM[SEC_EAM] Bits */
#define GSC_PPC_SECATTRIB_EAM_SEC_EAM_OFS        (0)                             /* !< SEC_EAM Offset */
#define GSC_PPC_SECATTRIB_EAM_SEC_EAM_MASK       ((uint32_t)0x00000001U)         /* !< Secure access enabled to EAM #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_PPC_SECATTRIB_WUC Bits */
/* GSC_PPC_SECATTRIB_WUC[SEC_WUC] Bits */
#define GSC_PPC_SECATTRIB_WUC_SEC_WUC_OFS        (0)                             /* !< SEC_WUC Offset */
#define GSC_PPC_SECATTRIB_WUC_SEC_WUC_MASK       ((uint32_t)0x00000001U)         /* !< Secure access enabled to WUC #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_PPC_SECATTRIB_FRIREGS Bits */
/* GSC_PPC_SECATTRIB_FRIREGS[SEC_FRIREGS] Bits */
#define GSC_PPC_SECATTRIB_FRIREGS_SEC_FRIREGS_OFS (0)                             /* !< SEC_FRIREGS Offset */
#define GSC_PPC_SECATTRIB_FRIREGS_SEC_FRIREGS_MASK ((uint32_t)0x00000001U)         /* !< Secure access enabled to FRIREGS
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_MEMCFG Bits */
/* GSC_PPC_SECATTRIB_MEMCFG[SEC_MEMCFG] Bits */
#define GSC_PPC_SECATTRIB_MEMCFG_SEC_MEMCFG_OFS  (0)                             /* !< SEC_MEMCFG Offset */
#define GSC_PPC_SECATTRIB_MEMCFG_SEC_MEMCFG_MASK ((uint32_t)0x00000001U)         /* !< Secure access enabled to MEMCFG
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_SECATTRIB_SYSCTL Bits */
/* GSC_PPC_SECATTRIB_SYSCTL[SEC_SYSCTL] Bits */
#define GSC_PPC_SECATTRIB_SYSCTL_SEC_SYSCTL_OFS  (0)                             /* !< SEC_SYSCTL Offset */
#define GSC_PPC_SECATTRIB_SYSCTL_SEC_SYSCTL_MASK ((uint32_t)0x00000001U)         /* !< Secure access enabled to SYSCTL
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_PRIVATTRIB_SYSCTL Bits */
/* GSC_PPC_PRIVATTRIB_SYSCTL[PRIV_SYSCTL] Bits */
#define GSC_PPC_PRIVATTRIB_SYSCTL_PRIV_SYSCTL_OFS (0)                             /* !< PRIV_SYSCTL Offset */
#define GSC_PPC_PRIVATTRIB_SYSCTL_PRIV_SYSCTL_MASK ((uint32_t)0x00000001U)         /* !< Privilege access enabled to SYSCTL
                                                                                    #br#0: Non-Privilege access is
                                                                                    enabled #br#1: Privilege access is
                                                                                    enabled */

/* GSC_PPC_SECATTRIB_DMA Bits */
/* GSC_PPC_SECATTRIB_DMA[SEC_DMA0] Bits */
#define GSC_PPC_SECATTRIB_DMA_SEC_DMA0_OFS       (0)                             /* !< SEC_DMA0 Offset */
#define GSC_PPC_SECATTRIB_DMA_SEC_DMA0_MASK      ((uint32_t)0x00000001U)         /* !< Secure access enabled to DMA0
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */
/* GSC_PPC_SECATTRIB_DMA[SEC_DMA1] Bits */
#define GSC_PPC_SECATTRIB_DMA_SEC_DMA1_OFS       (1)                             /* !< SEC_DMA1 Offset */
#define GSC_PPC_SECATTRIB_DMA_SEC_DMA1_MASK      ((uint32_t)0x00000002U)         /* !< Secure access enabled to DMA1
                                                                                    #br#0: Non-secure access is enabled
                                                                                    #br#1: Secure access is enabled */

/* GSC_PPC_PRIVATTRIB_DMA Bits */
/* GSC_PPC_PRIVATTRIB_DMA[PRIV_DMA0] Bits */
#define GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA0_OFS     (0)                             /* !< PRIV_DMA0 Offset */
#define GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA0_MASK    ((uint32_t)0x00000001U)         /* !< Privilege access enabled to DMA0
                                                                                    #br#0: Non-Privilege access is
                                                                                    enabled #br#1: Privilege access is
                                                                                    enabled */
/* GSC_PPC_PRIVATTRIB_DMA[PRIV_DMA1] Bits */
#define GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA1_OFS     (1)                             /* !< PRIV_DMA1 Offset */
#define GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA1_MASK    ((uint32_t)0x00000002U)         /* !< Privilege access enabled to DMA1
                                                                                    #br#0: Non-Privilege access is
                                                                                    enabled #br#1: Privilege access is
                                                                                    enabled */

/* GSC_PPC_SECATTRIB_GSC Bits */
/* GSC_PPC_SECATTRIB_GSC[SEC_GSC] Bits */
#define GSC_PPC_SECATTRIB_GSC_SEC_GSC_OFS        (0)                             /* !< SEC_GSC Offset */
#define GSC_PPC_SECATTRIB_GSC_SEC_GSC_MASK       ((uint32_t)0x00000001U)         /* !< Secure access enabled to GSC #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_PPC_PRIVATTRIB_GSC Bits */
/* GSC_PPC_PRIVATTRIB_GSC[PRIV_GSC] Bits */
#define GSC_PPC_PRIVATTRIB_GSC_PRIV_GSC_OFS      (0)                             /* !< PRIV_GSC Offset */
#define GSC_PPC_PRIVATTRIB_GSC_PRIV_GSC_MASK     ((uint32_t)0x00000001U)         /* !< Privilege access enabled to GSC
                                                                                    #br#0: Non-Privilege access is
                                                                                    enabled #br#1: Privilege access is
                                                                                    enabled */

/* GSC_PPC_SPARERW_GSC Bits */
/* GSC_PPC_SPARERW_GSC[ZERO_PKASRAM] Bits */
#define GSC_PPC_SPARERW_GSC_ZERO_PKASRAM_OFS     (0)                             /* !< ZERO_PKASRAM Offset */
#define GSC_PPC_SPARERW_GSC_ZERO_PKASRAM_MASK    ((uint32_t)0x00000001U)         /* !< Controls the zeroization of PKA
                                                                                    SRAM #br#0: PKA SRAM zeroization is
                                                                                    enabled #br#1: PKA SRAM zeroization
                                                                                    is disabled */

/* GSC_PPC_SPARERW1S_GSC Bits */
/* GSC_PPC_SPARERW1S_GSC[SPARE] Bits */
#define GSC_PPC_SPARERW1S_GSC_SPARE_OFS          (0)                             /* !< SPARE Offset */
#define GSC_PPC_SPARERW1S_GSC_SPARE_MASK         ((uint32_t)0xFFFFFFFFU)         /* !< Spare reserved */

/* GSC_SPC_SECATTRIB0 Bits */
/* GSC_SPC_SECATTRIB0[C0B0_512B] Bits */
#define GSC_SPC_SECATTRIB0_C0B0_512B_OFS         (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_SECATTRIB0_C0B0_512B_MASK        ((uint32_t)0x00000001U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C0B1_512B] Bits */
#define GSC_SPC_SECATTRIB0_C0B1_512B_OFS         (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_SECATTRIB0_C0B1_512B_MASK        ((uint32_t)0x00000002U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C0B0_1KB] Bits */
#define GSC_SPC_SECATTRIB0_C0B0_1KB_OFS          (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_SECATTRIB0_C0B0_1KB_MASK         ((uint32_t)0x00000004U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C0B0_2KB] Bits */
#define GSC_SPC_SECATTRIB0_C0B0_2KB_OFS          (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_SECATTRIB0_C0B0_2KB_MASK         ((uint32_t)0x00000008U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C0B0_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C0B0_4KB_OFS          (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_SECATTRIB0_C0B0_4KB_MASK         ((uint32_t)0x00000010U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C0B1_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C0B1_4KB_OFS          (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_SECATTRIB0_C0B1_4KB_MASK         ((uint32_t)0x00000020U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C0B2_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C0B2_4KB_OFS          (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_SECATTRIB0_C0B2_4KB_MASK         ((uint32_t)0x00000040U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C1B0_512B] Bits */
#define GSC_SPC_SECATTRIB0_C1B0_512B_OFS         (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_SECATTRIB0_C1B0_512B_MASK        ((uint32_t)0x00000100U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C1B1_512B] Bits */
#define GSC_SPC_SECATTRIB0_C1B1_512B_OFS         (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_SECATTRIB0_C1B1_512B_MASK        ((uint32_t)0x00000200U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C1B0_1KB] Bits */
#define GSC_SPC_SECATTRIB0_C1B0_1KB_OFS          (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_SECATTRIB0_C1B0_1KB_MASK         ((uint32_t)0x00000400U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C1B0_2KB] Bits */
#define GSC_SPC_SECATTRIB0_C1B0_2KB_OFS          (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_SECATTRIB0_C1B0_2KB_MASK         ((uint32_t)0x00000800U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C1B0_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C1B0_4KB_OFS          (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_SECATTRIB0_C1B0_4KB_MASK         ((uint32_t)0x00001000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C1B1_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C1B1_4KB_OFS          (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_SECATTRIB0_C1B1_4KB_MASK         ((uint32_t)0x00002000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C1B2_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C1B2_4KB_OFS          (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_SECATTRIB0_C1B2_4KB_MASK         ((uint32_t)0x00004000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C2B0_512B] Bits */
#define GSC_SPC_SECATTRIB0_C2B0_512B_OFS         (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_SECATTRIB0_C2B0_512B_MASK        ((uint32_t)0x00010000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C2B1_512B] Bits */
#define GSC_SPC_SECATTRIB0_C2B1_512B_OFS         (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_SECATTRIB0_C2B1_512B_MASK        ((uint32_t)0x00020000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C2B0_1KB] Bits */
#define GSC_SPC_SECATTRIB0_C2B0_1KB_OFS          (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_SECATTRIB0_C2B0_1KB_MASK         ((uint32_t)0x00040000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C2B0_2KB] Bits */
#define GSC_SPC_SECATTRIB0_C2B0_2KB_OFS          (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_SECATTRIB0_C2B0_2KB_MASK         ((uint32_t)0x00080000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C2B0_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C2B0_4KB_OFS          (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_SECATTRIB0_C2B0_4KB_MASK         ((uint32_t)0x00100000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C2B1_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C2B1_4KB_OFS          (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_SECATTRIB0_C2B1_4KB_MASK         ((uint32_t)0x00200000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C2B2_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C2B2_4KB_OFS          (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_SECATTRIB0_C2B2_4KB_MASK         ((uint32_t)0x00400000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C3B0_512B] Bits */
#define GSC_SPC_SECATTRIB0_C3B0_512B_OFS         (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_SECATTRIB0_C3B0_512B_MASK        ((uint32_t)0x01000000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C3B1_512B] Bits */
#define GSC_SPC_SECATTRIB0_C3B1_512B_OFS         (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_SECATTRIB0_C3B1_512B_MASK        ((uint32_t)0x02000000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB0[C3B0_1KB] Bits */
#define GSC_SPC_SECATTRIB0_C3B0_1KB_OFS          (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_SECATTRIB0_C3B0_1KB_MASK         ((uint32_t)0x04000000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C3B0_2KB] Bits */
#define GSC_SPC_SECATTRIB0_C3B0_2KB_OFS          (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_SECATTRIB0_C3B0_2KB_MASK         ((uint32_t)0x08000000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C3B0_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C3B0_4KB_OFS          (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_SECATTRIB0_C3B0_4KB_MASK         ((uint32_t)0x10000000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C3B1_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C3B1_4KB_OFS          (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_SECATTRIB0_C3B1_4KB_MASK         ((uint32_t)0x20000000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB0[C3B2_4KB] Bits */
#define GSC_SPC_SECATTRIB0_C3B2_4KB_OFS          (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_SECATTRIB0_C3B2_4KB_MASK         ((uint32_t)0x40000000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_SPC_SECATTRIB1 Bits */
/* GSC_SPC_SECATTRIB1[C0B0_512B] Bits */
#define GSC_SPC_SECATTRIB1_C0B0_512B_OFS         (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_SECATTRIB1_C0B0_512B_MASK        ((uint32_t)0x00000001U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C0B1_512B] Bits */
#define GSC_SPC_SECATTRIB1_C0B1_512B_OFS         (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_SECATTRIB1_C0B1_512B_MASK        ((uint32_t)0x00000002U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C0B0_1KB] Bits */
#define GSC_SPC_SECATTRIB1_C0B0_1KB_OFS          (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_SECATTRIB1_C0B0_1KB_MASK         ((uint32_t)0x00000004U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C0B0_2KB] Bits */
#define GSC_SPC_SECATTRIB1_C0B0_2KB_OFS          (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_SECATTRIB1_C0B0_2KB_MASK         ((uint32_t)0x00000008U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C0B0_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C0B0_4KB_OFS          (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_SECATTRIB1_C0B0_4KB_MASK         ((uint32_t)0x00000010U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C0B1_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C0B1_4KB_OFS          (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_SECATTRIB1_C0B1_4KB_MASK         ((uint32_t)0x00000020U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C0B2_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C0B2_4KB_OFS          (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_SECATTRIB1_C0B2_4KB_MASK         ((uint32_t)0x00000040U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C1B0_512B] Bits */
#define GSC_SPC_SECATTRIB1_C1B0_512B_OFS         (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_SECATTRIB1_C1B0_512B_MASK        ((uint32_t)0x00000100U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C1B1_512B] Bits */
#define GSC_SPC_SECATTRIB1_C1B1_512B_OFS         (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_SECATTRIB1_C1B1_512B_MASK        ((uint32_t)0x00000200U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C1B0_1KB] Bits */
#define GSC_SPC_SECATTRIB1_C1B0_1KB_OFS          (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_SECATTRIB1_C1B0_1KB_MASK         ((uint32_t)0x00000400U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C1B0_2KB] Bits */
#define GSC_SPC_SECATTRIB1_C1B0_2KB_OFS          (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_SECATTRIB1_C1B0_2KB_MASK         ((uint32_t)0x00000800U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C1B0_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C1B0_4KB_OFS          (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_SECATTRIB1_C1B0_4KB_MASK         ((uint32_t)0x00001000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C1B1_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C1B1_4KB_OFS          (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_SECATTRIB1_C1B1_4KB_MASK         ((uint32_t)0x00002000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C1B2_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C1B2_4KB_OFS          (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_SECATTRIB1_C1B2_4KB_MASK         ((uint32_t)0x00004000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C2B0_512B] Bits */
#define GSC_SPC_SECATTRIB1_C2B0_512B_OFS         (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_SECATTRIB1_C2B0_512B_MASK        ((uint32_t)0x00010000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C2B1_512B] Bits */
#define GSC_SPC_SECATTRIB1_C2B1_512B_OFS         (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_SECATTRIB1_C2B1_512B_MASK        ((uint32_t)0x00020000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C2B0_1KB] Bits */
#define GSC_SPC_SECATTRIB1_C2B0_1KB_OFS          (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_SECATTRIB1_C2B0_1KB_MASK         ((uint32_t)0x00040000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C2B0_2KB] Bits */
#define GSC_SPC_SECATTRIB1_C2B0_2KB_OFS          (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_SECATTRIB1_C2B0_2KB_MASK         ((uint32_t)0x00080000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C2B0_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C2B0_4KB_OFS          (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_SECATTRIB1_C2B0_4KB_MASK         ((uint32_t)0x00100000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C2B1_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C2B1_4KB_OFS          (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_SECATTRIB1_C2B1_4KB_MASK         ((uint32_t)0x00200000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C2B2_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C2B2_4KB_OFS          (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_SECATTRIB1_C2B2_4KB_MASK         ((uint32_t)0x00400000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C3B0_512B] Bits */
#define GSC_SPC_SECATTRIB1_C3B0_512B_OFS         (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_SECATTRIB1_C3B0_512B_MASK        ((uint32_t)0x01000000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C3B1_512B] Bits */
#define GSC_SPC_SECATTRIB1_C3B1_512B_OFS         (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_SECATTRIB1_C3B1_512B_MASK        ((uint32_t)0x02000000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB1[C3B0_1KB] Bits */
#define GSC_SPC_SECATTRIB1_C3B0_1KB_OFS          (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_SECATTRIB1_C3B0_1KB_MASK         ((uint32_t)0x04000000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C3B0_2KB] Bits */
#define GSC_SPC_SECATTRIB1_C3B0_2KB_OFS          (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_SECATTRIB1_C3B0_2KB_MASK         ((uint32_t)0x08000000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C3B0_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C3B0_4KB_OFS          (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_SECATTRIB1_C3B0_4KB_MASK         ((uint32_t)0x10000000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C3B1_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C3B1_4KB_OFS          (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_SECATTRIB1_C3B1_4KB_MASK         ((uint32_t)0x20000000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB1[C3B2_4KB] Bits */
#define GSC_SPC_SECATTRIB1_C3B2_4KB_OFS          (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_SECATTRIB1_C3B2_4KB_MASK         ((uint32_t)0x40000000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_SPC_SECATTRIB2 Bits */
/* GSC_SPC_SECATTRIB2[C0B0_512B] Bits */
#define GSC_SPC_SECATTRIB2_C0B0_512B_OFS         (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_SECATTRIB2_C0B0_512B_MASK        ((uint32_t)0x00000001U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C0B1_512B] Bits */
#define GSC_SPC_SECATTRIB2_C0B1_512B_OFS         (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_SECATTRIB2_C0B1_512B_MASK        ((uint32_t)0x00000002U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C0B0_1KB] Bits */
#define GSC_SPC_SECATTRIB2_C0B0_1KB_OFS          (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_SECATTRIB2_C0B0_1KB_MASK         ((uint32_t)0x00000004U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C0B0_2KB] Bits */
#define GSC_SPC_SECATTRIB2_C0B0_2KB_OFS          (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_SECATTRIB2_C0B0_2KB_MASK         ((uint32_t)0x00000008U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C0B0_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C0B0_4KB_OFS          (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_SECATTRIB2_C0B0_4KB_MASK         ((uint32_t)0x00000010U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C0B1_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C0B1_4KB_OFS          (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_SECATTRIB2_C0B1_4KB_MASK         ((uint32_t)0x00000020U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C0B2_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C0B2_4KB_OFS          (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_SECATTRIB2_C0B2_4KB_MASK         ((uint32_t)0x00000040U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C1B0_512B] Bits */
#define GSC_SPC_SECATTRIB2_C1B0_512B_OFS         (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_SECATTRIB2_C1B0_512B_MASK        ((uint32_t)0x00000100U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C1B1_512B] Bits */
#define GSC_SPC_SECATTRIB2_C1B1_512B_OFS         (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_SECATTRIB2_C1B1_512B_MASK        ((uint32_t)0x00000200U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C1B0_1KB] Bits */
#define GSC_SPC_SECATTRIB2_C1B0_1KB_OFS          (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_SECATTRIB2_C1B0_1KB_MASK         ((uint32_t)0x00000400U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C1B0_2KB] Bits */
#define GSC_SPC_SECATTRIB2_C1B0_2KB_OFS          (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_SECATTRIB2_C1B0_2KB_MASK         ((uint32_t)0x00000800U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C1B0_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C1B0_4KB_OFS          (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_SECATTRIB2_C1B0_4KB_MASK         ((uint32_t)0x00001000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C1B1_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C1B1_4KB_OFS          (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_SECATTRIB2_C1B1_4KB_MASK         ((uint32_t)0x00002000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C1B2_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C1B2_4KB_OFS          (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_SECATTRIB2_C1B2_4KB_MASK         ((uint32_t)0x00004000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C2B0_512B] Bits */
#define GSC_SPC_SECATTRIB2_C2B0_512B_OFS         (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_SECATTRIB2_C2B0_512B_MASK        ((uint32_t)0x00010000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C2B1_512B] Bits */
#define GSC_SPC_SECATTRIB2_C2B1_512B_OFS         (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_SECATTRIB2_C2B1_512B_MASK        ((uint32_t)0x00020000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C2B0_1KB] Bits */
#define GSC_SPC_SECATTRIB2_C2B0_1KB_OFS          (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_SECATTRIB2_C2B0_1KB_MASK         ((uint32_t)0x00040000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C2B0_2KB] Bits */
#define GSC_SPC_SECATTRIB2_C2B0_2KB_OFS          (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_SECATTRIB2_C2B0_2KB_MASK         ((uint32_t)0x00080000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C2B0_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C2B0_4KB_OFS          (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_SECATTRIB2_C2B0_4KB_MASK         ((uint32_t)0x00100000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C2B1_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C2B1_4KB_OFS          (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_SECATTRIB2_C2B1_4KB_MASK         ((uint32_t)0x00200000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C2B2_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C2B2_4KB_OFS          (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_SECATTRIB2_C2B2_4KB_MASK         ((uint32_t)0x00400000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C3B0_512B] Bits */
#define GSC_SPC_SECATTRIB2_C3B0_512B_OFS         (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_SECATTRIB2_C3B0_512B_MASK        ((uint32_t)0x01000000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C3B1_512B] Bits */
#define GSC_SPC_SECATTRIB2_C3B1_512B_OFS         (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_SECATTRIB2_C3B1_512B_MASK        ((uint32_t)0x02000000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB2[C3B0_1KB] Bits */
#define GSC_SPC_SECATTRIB2_C3B0_1KB_OFS          (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_SECATTRIB2_C3B0_1KB_MASK         ((uint32_t)0x04000000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C3B0_2KB] Bits */
#define GSC_SPC_SECATTRIB2_C3B0_2KB_OFS          (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_SECATTRIB2_C3B0_2KB_MASK         ((uint32_t)0x08000000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C3B0_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C3B0_4KB_OFS          (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_SECATTRIB2_C3B0_4KB_MASK         ((uint32_t)0x10000000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C3B1_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C3B1_4KB_OFS          (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_SECATTRIB2_C3B1_4KB_MASK         ((uint32_t)0x20000000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB2[C3B2_4KB] Bits */
#define GSC_SPC_SECATTRIB2_C3B2_4KB_OFS          (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_SECATTRIB2_C3B2_4KB_MASK         ((uint32_t)0x40000000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_SPC_SECATTRIB3 Bits */
/* GSC_SPC_SECATTRIB3[C0B0_512B] Bits */
#define GSC_SPC_SECATTRIB3_C0B0_512B_OFS         (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_SECATTRIB3_C0B0_512B_MASK        ((uint32_t)0x00000001U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C0B1_512B] Bits */
#define GSC_SPC_SECATTRIB3_C0B1_512B_OFS         (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_SECATTRIB3_C0B1_512B_MASK        ((uint32_t)0x00000002U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C0B0_1KB] Bits */
#define GSC_SPC_SECATTRIB3_C0B0_1KB_OFS          (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_SECATTRIB3_C0B0_1KB_MASK         ((uint32_t)0x00000004U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C0B0_2KB] Bits */
#define GSC_SPC_SECATTRIB3_C0B0_2KB_OFS          (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_SECATTRIB3_C0B0_2KB_MASK         ((uint32_t)0x00000008U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C0B0_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C0B0_4KB_OFS          (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_SECATTRIB3_C0B0_4KB_MASK         ((uint32_t)0x00000010U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C0B1_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C0B1_4KB_OFS          (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_SECATTRIB3_C0B1_4KB_MASK         ((uint32_t)0x00000020U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C0B2_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C0B2_4KB_OFS          (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_SECATTRIB3_C0B2_4KB_MASK         ((uint32_t)0x00000040U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-0 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C1B0_512B] Bits */
#define GSC_SPC_SECATTRIB3_C1B0_512B_OFS         (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_SECATTRIB3_C1B0_512B_MASK        ((uint32_t)0x00000100U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C1B1_512B] Bits */
#define GSC_SPC_SECATTRIB3_C1B1_512B_OFS         (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_SECATTRIB3_C1B1_512B_MASK        ((uint32_t)0x00000200U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C1B0_1KB] Bits */
#define GSC_SPC_SECATTRIB3_C1B0_1KB_OFS          (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_SECATTRIB3_C1B0_1KB_MASK         ((uint32_t)0x00000400U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C1B0_2KB] Bits */
#define GSC_SPC_SECATTRIB3_C1B0_2KB_OFS          (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_SECATTRIB3_C1B0_2KB_MASK         ((uint32_t)0x00000800U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C1B0_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C1B0_4KB_OFS          (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_SECATTRIB3_C1B0_4KB_MASK         ((uint32_t)0x00001000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C1B1_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C1B1_4KB_OFS          (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_SECATTRIB3_C1B1_4KB_MASK         ((uint32_t)0x00002000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C1B2_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C1B2_4KB_OFS          (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_SECATTRIB3_C1B2_4KB_MASK         ((uint32_t)0x00004000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-1 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C2B0_512B] Bits */
#define GSC_SPC_SECATTRIB3_C2B0_512B_OFS         (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_SECATTRIB3_C2B0_512B_MASK        ((uint32_t)0x00010000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C2B1_512B] Bits */
#define GSC_SPC_SECATTRIB3_C2B1_512B_OFS         (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_SECATTRIB3_C2B1_512B_MASK        ((uint32_t)0x00020000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C2B0_1KB] Bits */
#define GSC_SPC_SECATTRIB3_C2B0_1KB_OFS          (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_SECATTRIB3_C2B0_1KB_MASK         ((uint32_t)0x00040000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C2B0_2KB] Bits */
#define GSC_SPC_SECATTRIB3_C2B0_2KB_OFS          (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_SECATTRIB3_C2B0_2KB_MASK         ((uint32_t)0x00080000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C2B0_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C2B0_4KB_OFS          (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_SECATTRIB3_C2B0_4KB_MASK         ((uint32_t)0x00100000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C2B1_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C2B1_4KB_OFS          (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_SECATTRIB3_C2B1_4KB_MASK         ((uint32_t)0x00200000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C2B2_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C2B2_4KB_OFS          (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_SECATTRIB3_C2B2_4KB_MASK         ((uint32_t)0x00400000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-2 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C3B0_512B] Bits */
#define GSC_SPC_SECATTRIB3_C3B0_512B_OFS         (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_SECATTRIB3_C3B0_512B_MASK        ((uint32_t)0x01000000U)         /* !< Secure access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C3B1_512B] Bits */
#define GSC_SPC_SECATTRIB3_C3B1_512B_OFS         (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_SECATTRIB3_C3B1_512B_MASK        ((uint32_t)0x02000000U)         /* !< Secure access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */
/* GSC_SPC_SECATTRIB3[C3B0_1KB] Bits */
#define GSC_SPC_SECATTRIB3_C3B0_1KB_OFS          (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_SECATTRIB3_C3B0_1KB_MASK         ((uint32_t)0x04000000U)         /* !< Secure access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C3B0_2KB] Bits */
#define GSC_SPC_SECATTRIB3_C3B0_2KB_OFS          (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_SECATTRIB3_C3B0_2KB_MASK         ((uint32_t)0x08000000U)         /* !< Secure access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C3B0_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C3B0_4KB_OFS          (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_SECATTRIB3_C3B0_4KB_MASK         ((uint32_t)0x10000000U)         /* !< Secure access enabled to 1st 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C3B1_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C3B1_4KB_OFS          (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_SECATTRIB3_C3B1_4KB_MASK         ((uint32_t)0x20000000U)         /* !< Secure access enabled to 2nd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */
/* GSC_SPC_SECATTRIB3[C3B2_4KB] Bits */
#define GSC_SPC_SECATTRIB3_C3B2_4KB_OFS          (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_SECATTRIB3_C3B2_4KB_MASK         ((uint32_t)0x40000000U)         /* !< Secure access enabled to 3rd 4KB in
                                                                                    chunk-3 #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_SPC_PRIVATTRIB0 Bits */
/* GSC_SPC_PRIVATTRIB0[C0B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C0B0_512B_OFS        (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C0B0_512B_MASK       ((uint32_t)0x00000001U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C0B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C0B1_512B_OFS        (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C0B1_512B_MASK       ((uint32_t)0x00000002U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C0B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C0B0_1KB_OFS         (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB0_C0B0_1KB_MASK        ((uint32_t)0x00000004U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C0B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C0B0_2KB_OFS         (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB0_C0B0_2KB_MASK        ((uint32_t)0x00000008U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C0B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C0B0_4KB_OFS         (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C0B0_4KB_MASK        ((uint32_t)0x00000010U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C0B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C0B1_4KB_OFS         (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C0B1_4KB_MASK        ((uint32_t)0x00000020U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C0B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C0B2_4KB_OFS         (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C0B2_4KB_MASK        ((uint32_t)0x00000040U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C1B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C1B0_512B_OFS        (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C1B0_512B_MASK       ((uint32_t)0x00000100U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C1B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C1B1_512B_OFS        (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C1B1_512B_MASK       ((uint32_t)0x00000200U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C1B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C1B0_1KB_OFS         (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB0_C1B0_1KB_MASK        ((uint32_t)0x00000400U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C1B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C1B0_2KB_OFS         (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB0_C1B0_2KB_MASK        ((uint32_t)0x00000800U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C1B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C1B0_4KB_OFS         (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C1B0_4KB_MASK        ((uint32_t)0x00001000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C1B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C1B1_4KB_OFS         (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C1B1_4KB_MASK        ((uint32_t)0x00002000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C1B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C1B2_4KB_OFS         (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C1B2_4KB_MASK        ((uint32_t)0x00004000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C2B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C2B0_512B_OFS        (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C2B0_512B_MASK       ((uint32_t)0x00010000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C2B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C2B1_512B_OFS        (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C2B1_512B_MASK       ((uint32_t)0x00020000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C2B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C2B0_1KB_OFS         (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB0_C2B0_1KB_MASK        ((uint32_t)0x00040000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C2B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C2B0_2KB_OFS         (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB0_C2B0_2KB_MASK        ((uint32_t)0x00080000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C2B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C2B0_4KB_OFS         (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C2B0_4KB_MASK        ((uint32_t)0x00100000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C2B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C2B1_4KB_OFS         (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C2B1_4KB_MASK        ((uint32_t)0x00200000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C2B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C2B2_4KB_OFS         (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C2B2_4KB_MASK        ((uint32_t)0x00400000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C3B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C3B0_512B_OFS        (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C3B0_512B_MASK       ((uint32_t)0x01000000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C3B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB0_C3B1_512B_OFS        (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_PRIVATTRIB0_C3B1_512B_MASK       ((uint32_t)0x02000000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C3B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C3B0_1KB_OFS         (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB0_C3B0_1KB_MASK        ((uint32_t)0x04000000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C3B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C3B0_2KB_OFS         (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB0_C3B0_2KB_MASK        ((uint32_t)0x08000000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB0[C3B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C3B0_4KB_OFS         (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C3B0_4KB_MASK        ((uint32_t)0x10000000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C3B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C3B1_4KB_OFS         (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C3B1_4KB_MASK        ((uint32_t)0x20000000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB0[C3B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB0_C3B2_4KB_OFS         (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB0_C3B2_4KB_MASK        ((uint32_t)0x40000000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */

/* GSC_SPC_PRIVATTRIB1 Bits */
/* GSC_SPC_PRIVATTRIB1[C0B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C0B0_512B_OFS        (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C0B0_512B_MASK       ((uint32_t)0x00000001U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C0B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C0B1_512B_OFS        (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C0B1_512B_MASK       ((uint32_t)0x00000002U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C0B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C0B0_1KB_OFS         (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB1_C0B0_1KB_MASK        ((uint32_t)0x00000004U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C0B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C0B0_2KB_OFS         (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB1_C0B0_2KB_MASK        ((uint32_t)0x00000008U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C0B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C0B0_4KB_OFS         (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C0B0_4KB_MASK        ((uint32_t)0x00000010U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C0B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C0B1_4KB_OFS         (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C0B1_4KB_MASK        ((uint32_t)0x00000020U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C0B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C0B2_4KB_OFS         (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C0B2_4KB_MASK        ((uint32_t)0x00000040U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C1B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C1B0_512B_OFS        (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C1B0_512B_MASK       ((uint32_t)0x00000100U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C1B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C1B1_512B_OFS        (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C1B1_512B_MASK       ((uint32_t)0x00000200U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C1B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C1B0_1KB_OFS         (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB1_C1B0_1KB_MASK        ((uint32_t)0x00000400U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C1B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C1B0_2KB_OFS         (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB1_C1B0_2KB_MASK        ((uint32_t)0x00000800U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C1B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C1B0_4KB_OFS         (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C1B0_4KB_MASK        ((uint32_t)0x00001000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C1B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C1B1_4KB_OFS         (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C1B1_4KB_MASK        ((uint32_t)0x00002000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C1B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C1B2_4KB_OFS         (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C1B2_4KB_MASK        ((uint32_t)0x00004000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C2B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C2B0_512B_OFS        (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C2B0_512B_MASK       ((uint32_t)0x00010000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C2B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C2B1_512B_OFS        (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C2B1_512B_MASK       ((uint32_t)0x00020000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C2B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C2B0_1KB_OFS         (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB1_C2B0_1KB_MASK        ((uint32_t)0x00040000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C2B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C2B0_2KB_OFS         (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB1_C2B0_2KB_MASK        ((uint32_t)0x00080000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C2B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C2B0_4KB_OFS         (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C2B0_4KB_MASK        ((uint32_t)0x00100000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C2B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C2B1_4KB_OFS         (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C2B1_4KB_MASK        ((uint32_t)0x00200000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C2B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C2B2_4KB_OFS         (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C2B2_4KB_MASK        ((uint32_t)0x00400000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C3B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C3B0_512B_OFS        (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C3B0_512B_MASK       ((uint32_t)0x01000000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C3B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB1_C3B1_512B_OFS        (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_PRIVATTRIB1_C3B1_512B_MASK       ((uint32_t)0x02000000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C3B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C3B0_1KB_OFS         (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB1_C3B0_1KB_MASK        ((uint32_t)0x04000000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C3B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C3B0_2KB_OFS         (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB1_C3B0_2KB_MASK        ((uint32_t)0x08000000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB1[C3B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C3B0_4KB_OFS         (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C3B0_4KB_MASK        ((uint32_t)0x10000000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C3B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C3B1_4KB_OFS         (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C3B1_4KB_MASK        ((uint32_t)0x20000000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB1[C3B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB1_C3B2_4KB_OFS         (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB1_C3B2_4KB_MASK        ((uint32_t)0x40000000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */

/* GSC_SPC_PRIVATTRIB2 Bits */
/* GSC_SPC_PRIVATTRIB2[C0B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C0B0_512B_OFS        (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C0B0_512B_MASK       ((uint32_t)0x00000001U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C0B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C0B1_512B_OFS        (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C0B1_512B_MASK       ((uint32_t)0x00000002U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C0B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C0B0_1KB_OFS         (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB2_C0B0_1KB_MASK        ((uint32_t)0x00000004U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C0B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C0B0_2KB_OFS         (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB2_C0B0_2KB_MASK        ((uint32_t)0x00000008U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C0B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C0B0_4KB_OFS         (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C0B0_4KB_MASK        ((uint32_t)0x00000010U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C0B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C0B1_4KB_OFS         (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C0B1_4KB_MASK        ((uint32_t)0x00000020U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C0B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C0B2_4KB_OFS         (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C0B2_4KB_MASK        ((uint32_t)0x00000040U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C1B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C1B0_512B_OFS        (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C1B0_512B_MASK       ((uint32_t)0x00000100U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C1B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C1B1_512B_OFS        (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C1B1_512B_MASK       ((uint32_t)0x00000200U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C1B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C1B0_1KB_OFS         (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB2_C1B0_1KB_MASK        ((uint32_t)0x00000400U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C1B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C1B0_2KB_OFS         (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB2_C1B0_2KB_MASK        ((uint32_t)0x00000800U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C1B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C1B0_4KB_OFS         (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C1B0_4KB_MASK        ((uint32_t)0x00001000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C1B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C1B1_4KB_OFS         (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C1B1_4KB_MASK        ((uint32_t)0x00002000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C1B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C1B2_4KB_OFS         (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C1B2_4KB_MASK        ((uint32_t)0x00004000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C2B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C2B0_512B_OFS        (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C2B0_512B_MASK       ((uint32_t)0x00010000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C2B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C2B1_512B_OFS        (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C2B1_512B_MASK       ((uint32_t)0x00020000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C2B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C2B0_1KB_OFS         (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB2_C2B0_1KB_MASK        ((uint32_t)0x00040000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C2B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C2B0_2KB_OFS         (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB2_C2B0_2KB_MASK        ((uint32_t)0x00080000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C2B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C2B0_4KB_OFS         (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C2B0_4KB_MASK        ((uint32_t)0x00100000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C2B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C2B1_4KB_OFS         (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C2B1_4KB_MASK        ((uint32_t)0x00200000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C2B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C2B2_4KB_OFS         (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C2B2_4KB_MASK        ((uint32_t)0x00400000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C3B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C3B0_512B_OFS        (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C3B0_512B_MASK       ((uint32_t)0x01000000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C3B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB2_C3B1_512B_OFS        (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_PRIVATTRIB2_C3B1_512B_MASK       ((uint32_t)0x02000000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C3B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C3B0_1KB_OFS         (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB2_C3B0_1KB_MASK        ((uint32_t)0x04000000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C3B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C3B0_2KB_OFS         (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB2_C3B0_2KB_MASK        ((uint32_t)0x08000000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB2[C3B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C3B0_4KB_OFS         (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C3B0_4KB_MASK        ((uint32_t)0x10000000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C3B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C3B1_4KB_OFS         (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C3B1_4KB_MASK        ((uint32_t)0x20000000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB2[C3B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB2_C3B2_4KB_OFS         (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB2_C3B2_4KB_MASK        ((uint32_t)0x40000000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */

/* GSC_SPC_PRIVATTRIB3 Bits */
/* GSC_SPC_PRIVATTRIB3[C0B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C0B0_512B_OFS        (0)                             /* !< C0B0_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C0B0_512B_MASK       ((uint32_t)0x00000001U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C0B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C0B1_512B_OFS        (1)                             /* !< C0B1_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C0B1_512B_MASK       ((uint32_t)0x00000002U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C0B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C0B0_1KB_OFS         (2)                             /* !< C0B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB3_C0B0_1KB_MASK        ((uint32_t)0x00000004U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C0B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C0B0_2KB_OFS         (3)                             /* !< C0B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB3_C0B0_2KB_MASK        ((uint32_t)0x00000008U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-0 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C0B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C0B0_4KB_OFS         (4)                             /* !< C0B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C0B0_4KB_MASK        ((uint32_t)0x00000010U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C0B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C0B1_4KB_OFS         (5)                             /* !< C0B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C0B1_4KB_MASK        ((uint32_t)0x00000020U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C0B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C0B2_4KB_OFS         (6)                             /* !< C0B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C0B2_4KB_MASK        ((uint32_t)0x00000040U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-0 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C1B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C1B0_512B_OFS        (8)                             /* !< C1B0_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C1B0_512B_MASK       ((uint32_t)0x00000100U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C1B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C1B1_512B_OFS        (9)                             /* !< C1B1_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C1B1_512B_MASK       ((uint32_t)0x00000200U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C1B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C1B0_1KB_OFS         (10)                            /* !< C1B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB3_C1B0_1KB_MASK        ((uint32_t)0x00000400U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C1B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C1B0_2KB_OFS         (11)                            /* !< C1B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB3_C1B0_2KB_MASK        ((uint32_t)0x00000800U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-1 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C1B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C1B0_4KB_OFS         (12)                            /* !< C1B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C1B0_4KB_MASK        ((uint32_t)0x00001000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C1B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C1B1_4KB_OFS         (13)                            /* !< C1B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C1B1_4KB_MASK        ((uint32_t)0x00002000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C1B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C1B2_4KB_OFS         (14)                            /* !< C1B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C1B2_4KB_MASK        ((uint32_t)0x00004000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-1 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C2B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C2B0_512B_OFS        (16)                            /* !< C2B0_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C2B0_512B_MASK       ((uint32_t)0x00010000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C2B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C2B1_512B_OFS        (17)                            /* !< C2B1_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C2B1_512B_MASK       ((uint32_t)0x00020000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C2B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C2B0_1KB_OFS         (18)                            /* !< C2B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB3_C2B0_1KB_MASK        ((uint32_t)0x00040000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C2B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C2B0_2KB_OFS         (19)                            /* !< C2B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB3_C2B0_2KB_MASK        ((uint32_t)0x00080000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-2 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C2B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C2B0_4KB_OFS         (20)                            /* !< C2B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C2B0_4KB_MASK        ((uint32_t)0x00100000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C2B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C2B1_4KB_OFS         (21)                            /* !< C2B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C2B1_4KB_MASK        ((uint32_t)0x00200000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C2B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C2B2_4KB_OFS         (22)                            /* !< C2B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C2B2_4KB_MASK        ((uint32_t)0x00400000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-2 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C3B0_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C3B0_512B_OFS        (24)                            /* !< C3B0_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C3B0_512B_MASK       ((uint32_t)0x01000000U)         /* !< privilege access enabled to 1st 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C3B1_512B] Bits */
#define GSC_SPC_PRIVATTRIB3_C3B1_512B_OFS        (25)                            /* !< C3B1_512B Offset */
#define GSC_SPC_PRIVATTRIB3_C3B1_512B_MASK       ((uint32_t)0x02000000U)         /* !< privilege access enabled to 2nd 512
                                                                                    byte in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C3B0_1KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C3B0_1KB_OFS         (26)                            /* !< C3B0_1KB Offset */
#define GSC_SPC_PRIVATTRIB3_C3B0_1KB_MASK        ((uint32_t)0x04000000U)         /* !< privilege access enabled to 1KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C3B0_2KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C3B0_2KB_OFS         (27)                            /* !< C3B0_2KB Offset */
#define GSC_SPC_PRIVATTRIB3_C3B0_2KB_MASK        ((uint32_t)0x08000000U)         /* !< privilege access enabled to 2KB in
                                                                                    chunk-3 #br#0: Non-privilege access
                                                                                    is enabled #br#1: privilege access is
                                                                                    enabled */
/* GSC_SPC_PRIVATTRIB3[C3B0_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C3B0_4KB_OFS         (28)                            /* !< C3B0_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C3B0_4KB_MASK        ((uint32_t)0x10000000U)         /* !< privilege access enabled to 1st 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C3B1_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C3B1_4KB_OFS         (29)                            /* !< C3B1_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C3B1_4KB_MASK        ((uint32_t)0x20000000U)         /* !< privilege access enabled to 2nd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */
/* GSC_SPC_PRIVATTRIB3[C3B2_4KB] Bits */
#define GSC_SPC_PRIVATTRIB3_C3B2_4KB_OFS         (30)                            /* !< C3B2_4KB Offset */
#define GSC_SPC_PRIVATTRIB3_C3B2_4KB_MASK        ((uint32_t)0x40000000U)         /* !< privilege access enabled to 3rd 4KB
                                                                                    in chunk-3 #br#0: Non-privilege
                                                                                    access is enabled #br#1: privilege
                                                                                    access is enabled */

/* GSC_FPC_SECATTRIBA0 Bits */
/* GSC_FPC_SECATTRIBA0[SEC_PAGE] Bits */
#define GSC_FPC_SECATTRIBA0_SEC_PAGE_OFS         (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_SECATTRIBA0_SEC_PAGE_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Secure access enable for first 32
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_FPC_SECATTRIBA1 Bits */
/* GSC_FPC_SECATTRIBA1[SEC_PAGE] Bits */
#define GSC_FPC_SECATTRIBA1_SEC_PAGE_OFS         (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_SECATTRIBA1_SEC_PAGE_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Secure access enable for first 32
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_FPC_SECATTRIBB0 Bits */
/* GSC_FPC_SECATTRIBB0[SEC_PAGE] Bits */
#define GSC_FPC_SECATTRIBB0_SEC_PAGE_OFS         (4)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_SECATTRIBB0_SEC_PAGE_MASK        ((uint32_t)0xFFFFFFF0U)         /* !< Secure access enable for 64KB-512KB
                                                                                    flash with each bit representing 8
                                                                                    sectors of 2KB #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */

/* GSC_FPC_SECATTRIBB1 Bits */
/* GSC_FPC_SECATTRIBB1[SEC_PAGE] Bits */
#define GSC_FPC_SECATTRIBB1_SEC_PAGE_OFS         (4)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_SECATTRIBB1_SEC_PAGE_MASK        ((uint32_t)0xFFFFFFF0U)         /* !< Secure access enable for 64KB-512KB
                                                                                    flash with each bit representing 8
                                                                                    sectors of 2KB #br#0: Non-secure
                                                                                    access is enabled #br#1: Secure
                                                                                    access is enabled */

/* GSC_FPC_NONMAIN_SECATTRIB0 Bits */
/* GSC_FPC_NONMAIN_SECATTRIB0[SEC_PAGE] Bits */
#define GSC_FPC_NONMAIN_SECATTRIB0_SEC_PAGE_OFS  (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_NONMAIN_SECATTRIB0_SEC_PAGE_MASK ((uint32_t)0x0000000FU)         /* !< Secure access enable for first 4
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_FPC_NONMAIN_SECATTRIB1 Bits */
/* GSC_FPC_NONMAIN_SECATTRIB1[SEC_PAGE] Bits */
#define GSC_FPC_NONMAIN_SECATTRIB1_SEC_PAGE_OFS  (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_NONMAIN_SECATTRIB1_SEC_PAGE_MASK ((uint32_t)0x0000000FU)         /* !< Secure access enable for first 4
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_FPC_TRIM_SECATTRIB0 Bits */
/* GSC_FPC_TRIM_SECATTRIB0[SEC_PAGE] Bits */
#define GSC_FPC_TRIM_SECATTRIB0_SEC_PAGE_OFS     (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_TRIM_SECATTRIB0_SEC_PAGE_MASK    ((uint32_t)0x00000001U)         /* !< Secure access enable for the flash
                                                                                    with each bit representing 1 sector
                                                                                    of 2KB #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_FPC_TRIM_SECATTRIB1 Bits */
/* GSC_FPC_TRIM_SECATTRIB1[SEC_PAGE] Bits */
#define GSC_FPC_TRIM_SECATTRIB1_SEC_PAGE_OFS     (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_TRIM_SECATTRIB1_SEC_PAGE_MASK    ((uint32_t)0x00000001U)         /* !< Secure access enable for the flash
                                                                                    with each bit representing 1 sector
                                                                                    of 2KB #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_FPC_ENGR_SECATTRIB0 Bits */
/* GSC_FPC_ENGR_SECATTRIB0[SEC_PAGE] Bits */
#define GSC_FPC_ENGR_SECATTRIB0_SEC_PAGE_OFS     (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_ENGR_SECATTRIB0_SEC_PAGE_MASK    ((uint32_t)0x00000001U)         /* !< Secure access enable for the flash
                                                                                    with each bit representing 1 sector
                                                                                    of 2KB #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_FPC_ENGR_SECATTRIB1 Bits */
/* GSC_FPC_ENGR_SECATTRIB1[SEC_PAGE] Bits */
#define GSC_FPC_ENGR_SECATTRIB1_SEC_PAGE_OFS     (0)                             /* !< SEC_PAGE Offset */
#define GSC_FPC_ENGR_SECATTRIB1_SEC_PAGE_MASK    ((uint32_t)0x00000001U)         /* !< Secure access enable for the flash
                                                                                    with each bit representing 1 sector
                                                                                    of 2KB #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_FPC_SECATTRIBA_DFLASH Bits */
/* GSC_FPC_SECATTRIBA_DFLASH[SEC_PAGE_DFLASH] Bits */
#define GSC_FPC_SECATTRIBA_DFLASH_SEC_PAGE_DFLASH_OFS (0)                             /* !< SEC_PAGE_DFLASH Offset */
#define GSC_FPC_SECATTRIBA_DFLASH_SEC_PAGE_DFLASH_MASK ((uint32_t)0x0000FFFFU)         /* !< Secure access enable for first 16
                                                                                    sectors data flash page with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-secure access is enabled #br#1:
                                                                                    Secure access is enabled */

/* GSC_FPC_ENGR_SECATTRIB_DFLASH Bits */
/* GSC_FPC_ENGR_SECATTRIB_DFLASH[SEC_PAGE_DFLASH] Bits */
#define GSC_FPC_ENGR_SECATTRIB_DFLASH_SEC_PAGE_DFLASH_OFS (0)                             /* !< SEC_PAGE_DFLASH Offset */
#define GSC_FPC_ENGR_SECATTRIB_DFLASH_SEC_PAGE_DFLASH_MASK ((uint32_t)0x00000001U)         /* !< Secure access enable for 1 sector
                                                                                    of 2KB  #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_FPC_NONMAIN_SECATTRIB_DFLASH Bits */
/* GSC_FPC_NONMAIN_SECATTRIB_DFLASH[SEC_PAGE_DFLASH] Bits */
#define GSC_FPC_NONMAIN_SECATTRIB_DFLASH_SEC_PAGE_DFLASH_OFS (0)                             /* !< SEC_PAGE_DFLASH Offset */
#define GSC_FPC_NONMAIN_SECATTRIB_DFLASH_SEC_PAGE_DFLASH_MASK ((uint32_t)0x0000000FU)         /* !< Secure access enable for 4 sector
                                                                                    with each bit representing 1 sector
                                                                                    of 2KB #br#0: Non-secure access is
                                                                                    enabled #br#1: Secure access is
                                                                                    enabled */

/* GSC_FPC_PRIVATTRIBA0 Bits */
/* GSC_FPC_PRIVATTRIBA0[PRIV_PAGE] Bits */
#define GSC_FPC_PRIVATTRIBA0_PRIV_PAGE_OFS       (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_PRIVATTRIBA0_PRIV_PAGE_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Privilege access enable for first
                                                                                    32 sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-Privilege access is enabled
                                                                                    #br#1: Privilege access is enabled */

/* GSC_FPC_PRIVATTRIBA1 Bits */
/* GSC_FPC_PRIVATTRIBA1[PRIV_PAGE] Bits */
#define GSC_FPC_PRIVATTRIBA1_PRIV_PAGE_OFS       (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_PRIVATTRIBA1_PRIV_PAGE_MASK      ((uint32_t)0xFFFFFFFFU)         /* !< Privilege access enable for first
                                                                                    32 sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-Privilege access is enabled
                                                                                    #br#1: Privilege access is enabled */

/* GSC_FPC_PRIVATTRIBB0 Bits */
/* GSC_FPC_PRIVATTRIBB0[PRIV_PAGE] Bits */
#define GSC_FPC_PRIVATTRIBB0_PRIV_PAGE_OFS       (4)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_PRIVATTRIBB0_PRIV_PAGE_MASK      ((uint32_t)0xFFFFFFF0U)         /* !< Privilege access enable for
                                                                                    64KB-512KB flash with each bit
                                                                                    representing 8 sectors of 2KB #br#0:
                                                                                    Non-privilege access is enabled
                                                                                    #br#1: privilege access is enabled */

/* GSC_FPC_PRIVATTRIBB1 Bits */
/* GSC_FPC_PRIVATTRIBB1[PRIV_PAGE] Bits */
#define GSC_FPC_PRIVATTRIBB1_PRIV_PAGE_OFS       (4)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_PRIVATTRIBB1_PRIV_PAGE_MASK      ((uint32_t)0xFFFFFFF0U)         /* !< Privilege access enable for
                                                                                    64KB-512KB flash with each bit
                                                                                    representing 8 sectors of 2KB #br#0:
                                                                                    Non-privilege access is enabled
                                                                                    #br#1: privilege access is enabled */

/* GSC_FPC_NONMAIN_PRIVATTRIB0 Bits */
/* GSC_FPC_NONMAIN_PRIVATTRIB0[PRIV_PAGE] Bits */
#define GSC_FPC_NONMAIN_PRIVATTRIB0_PRIV_PAGE_OFS (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_NONMAIN_PRIVATTRIB0_PRIV_PAGE_MASK ((uint32_t)0x0000000FU)         /* !< Privilege access enable for first 4
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-Privilege access is enabled
                                                                                    #br#1: Privilege access is enabled */

/* GSC_FPC_NONMAIN_PRIVATTRIB1 Bits */
/* GSC_FPC_NONMAIN_PRIVATTRIB1[PRIV_PAGE] Bits */
#define GSC_FPC_NONMAIN_PRIVATTRIB1_PRIV_PAGE_OFS (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_NONMAIN_PRIVATTRIB1_PRIV_PAGE_MASK ((uint32_t)0x0000000FU)         /* !< Privilege access enable for first 4
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Non-Privilege access is enabled
                                                                                    #br#1: Privilege access is enabled */

/* GSC_FPC_TRIM_PRIVATTRIB0 Bits */
/* GSC_FPC_TRIM_PRIVATTRIB0[PRIV_PAGE] Bits */
#define GSC_FPC_TRIM_PRIVATTRIB0_PRIV_PAGE_OFS   (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_TRIM_PRIVATTRIB0_PRIV_PAGE_MASK  ((uint32_t)0x00000001U)         /* !< Privilege access enable for the
                                                                                    flash with each bit representing 1
                                                                                    sector of 2KB #br#0: Non-Privilege
                                                                                    access is enabled #br#1: Privilege
                                                                                    access is enabled */

/* GSC_FPC_TRIM_PRIVATTRIB1 Bits */
/* GSC_FPC_TRIM_PRIVATTRIB1[PRIV_PAGE] Bits */
#define GSC_FPC_TRIM_PRIVATTRIB1_PRIV_PAGE_OFS   (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_TRIM_PRIVATTRIB1_PRIV_PAGE_MASK  ((uint32_t)0x00000001U)         /* !< Privilege access enable for the
                                                                                    flash with each bit representing 1
                                                                                    sector of 2KB #br#0: Non-Privilege
                                                                                    access is enabled #br#1: Privilege
                                                                                    access is enabled */

/* GSC_FPC_ENGR_PRIVATTRIB0 Bits */
/* GSC_FPC_ENGR_PRIVATTRIB0[PRIV_PAGE] Bits */
#define GSC_FPC_ENGR_PRIVATTRIB0_PRIV_PAGE_OFS   (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_ENGR_PRIVATTRIB0_PRIV_PAGE_MASK  ((uint32_t)0x00000001U)         /* !< Privilege access enable for the
                                                                                    flash with each bit representing 1
                                                                                    sector of 2KB #br#0: Non-Privilege
                                                                                    access is enabled #br#1: Privilege
                                                                                    access is enabled */

/* GSC_FPC_ENGR_PRIVATTRIB1 Bits */
/* GSC_FPC_ENGR_PRIVATTRIB1[PRIV_PAGE] Bits */
#define GSC_FPC_ENGR_PRIVATTRIB1_PRIV_PAGE_OFS   (0)                             /* !< PRIV_PAGE Offset */
#define GSC_FPC_ENGR_PRIVATTRIB1_PRIV_PAGE_MASK  ((uint32_t)0x00000001U)         /* !< Privilege access enable for the
                                                                                    flash with each bit representing 1
                                                                                    sector of 2KB #br#0: Non-Privilege
                                                                                    access is enabled #br#1: Privilege
                                                                                    access is enabled */

/* GSC_FPC_PRIVATTRIBA_DFLASH Bits */
/* GSC_FPC_PRIVATTRIBA_DFLASH[PRIV_PAGE_DFLASH] Bits */
#define GSC_FPC_PRIVATTRIBA_DFLASH_PRIV_PAGE_DFLASH_OFS (0)                             /* !< PRIV_PAGE_DFLASH Offset */
#define GSC_FPC_PRIVATTRIBA_DFLASH_PRIV_PAGE_DFLASH_MASK ((uint32_t)0x0000FFFFU)         /* !< Privilege access enable for first
                                                                                    16 sectors data flash page with each
                                                                                    bit representing 1 sector of 2KB
                                                                                    #br#0: Non-Privilege access is
                                                                                    enabled #br#1: Privilege access is
                                                                                    enabled */

/* GSC_FPC_NONMAIN_PRIVATTRIB_DFLASH Bits */
/* GSC_FPC_NONMAIN_PRIVATTRIB_DFLASH[PRIV_PAGE_DFLASH] Bits */
#define GSC_FPC_NONMAIN_PRIVATTRIB_DFLASH_PRIV_PAGE_DFLASH_OFS (0)                             /* !< PRIV_PAGE_DFLASH Offset */
#define GSC_FPC_NONMAIN_PRIVATTRIB_DFLASH_PRIV_PAGE_DFLASH_MASK ((uint32_t)0x0000000FU)         /* !< Privilege access enable for 4
                                                                                    sectors each of 2KB #br#0:
                                                                                    Non-Privilege access is enabled
                                                                                    #br#1: Privilege access is enabled */

/* GSC_FPC_ENGR_PRIVATTRIB_DFLASH Bits */
/* GSC_FPC_ENGR_PRIVATTRIB_DFLASH[PRIV_PAGE_DFLASH] Bits */
#define GSC_FPC_ENGR_PRIVATTRIB_DFLASH_PRIV_PAGE_DFLASH_OFS (0)                             /* !< PRIV_PAGE_DFLASH Offset */
#define GSC_FPC_ENGR_PRIVATTRIB_DFLASH_PRIV_PAGE_DFLASH_MASK ((uint32_t)0x00000001U)         /* !< Privilege access enable for 1
                                                                                    sector of 2KB #br#0: Non-Privilege
                                                                                    access is enabled #br#1: Privilege
                                                                                    access is enabled */

/* GSC_FPC_WEPROTA0 Bits */
/* GSC_FPC_WEPROTA0[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTA0_WEPROT_PAGE_OFS         (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTA0_WEPROT_PAGE_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Write protection enable for first
                                                                                    32 sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTA1 Bits */
/* GSC_FPC_WEPROTA1[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTA1_WEPROT_PAGE_OFS         (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTA1_WEPROT_PAGE_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Write protection enable for first
                                                                                    32 sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTB0 Bits */
/* GSC_FPC_WEPROTB0[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTB0_WEPROT_PAGE_OFS         (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTB0_WEPROT_PAGE_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Write Protection enable for
                                                                                    512KB-1024KB flash with each bit
                                                                                    representing 8 sectors of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTB1 Bits */
/* GSC_FPC_WEPROTB1[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTB1_WEPROT_PAGE_OFS         (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTB1_WEPROT_PAGE_MASK        ((uint32_t)0xFFFFFFFFU)         /* !< Write Protection enable for
                                                                                    512KB-1024KB flash with each bit
                                                                                    representing 8 sectors of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTNONMAIN0 Bits */
/* GSC_FPC_WEPROTNONMAIN0[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTNONMAIN0_WEPROT_PAGE_OFS   (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTNONMAIN0_WEPROT_PAGE_MASK  ((uint32_t)0x0000000FU)         /* !< Write protection enable for first 4
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTNONMAIN1 Bits */
/* GSC_FPC_WEPROTNONMAIN1[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTNONMAIN1_WEPROT_PAGE_OFS   (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTNONMAIN1_WEPROT_PAGE_MASK  ((uint32_t)0x0000000FU)         /* !< Write protection enable for first 4
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTTRIM0 Bits */
/* GSC_FPC_WEPROTTRIM0[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTTRIM0_WEPROT_PAGE_OFS      (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTTRIM0_WEPROT_PAGE_MASK     ((uint32_t)0x00000003U)         /* !< Write protection enable for first 2
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTTRIM1 Bits */
/* GSC_FPC_WEPROTTRIM1[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTTRIM1_WEPROT_PAGE_OFS      (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTTRIM1_WEPROT_PAGE_MASK     ((uint32_t)0x00000003U)         /* !< Write protection enable for first 2
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTENGR0 Bits */
/* GSC_FPC_WEPROTENGR0[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTENGR0_WEPROT_PAGE_OFS      (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTENGR0_WEPROT_PAGE_MASK     ((uint32_t)0x00000003U)         /* !< Write protection enable for first 2
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTENGR1 Bits */
/* GSC_FPC_WEPROTENGR1[WEPROT_PAGE] Bits */
#define GSC_FPC_WEPROTENGR1_WEPROT_PAGE_OFS      (0)                             /* !< WEPROT_PAGE Offset */
#define GSC_FPC_WEPROTENGR1_WEPROT_PAGE_MASK     ((uint32_t)0x00000003U)         /* !< Write protection enable for first 2
                                                                                    sectors of flash with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROTA_DFLASH Bits */
/* GSC_FPC_WEPROTA_DFLASH[WEPROT_PAGE_DFLASH] Bits */
#define GSC_FPC_WEPROTA_DFLASH_WEPROT_PAGE_DFLASH_OFS (0)                             /* !< WEPROT_PAGE_DFLASH Offset */
#define GSC_FPC_WEPROTA_DFLASH_WEPROT_PAGE_DFLASH_MASK ((uint32_t)0x0000FFFFU)         /* !< Write protection enable for first
                                                                                    16 sectors data flash page with each
                                                                                    bit representing 1 sector of 2KB
                                                                                    #br#0: Page is not erase/program
                                                                                    protected #br#1: Page is
                                                                                    erase/program protected */
/* GSC_FPC_WEPROTA_DFLASH[WEPROT_PAGE_DFLASH] Bits */

/* GSC_FPC_WEPROT_NONMAIN_DFLASH Bits */
/* GSC_FPC_WEPROT_NONMAIN_DFLASH[WEPROT_PAGE_DFLASH] Bits */
#define GSC_FPC_WEPROT_NONMAIN_DFLASH_WEPROT_PAGE_DFLASH_OFS (0)                             /* !< WEPROT_PAGE_DFLASH Offset */
#define GSC_FPC_WEPROT_NONMAIN_DFLASH_WEPROT_PAGE_DFLASH_MASK ((uint32_t)0x0000000FU)         /* !< Write protection enable for NONMAIN
                                                                                    sectors data flash page with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_WEPROT_ENGR_DFLASH Bits */
/* GSC_FPC_WEPROT_ENGR_DFLASH[WEPROT_PAGE_DFLASH] Bits */
#define GSC_FPC_WEPROT_ENGR_DFLASH_WEPROT_PAGE_DFLASH_OFS (0)                             /* !< WEPROT_PAGE_DFLASH Offset */
#define GSC_FPC_WEPROT_ENGR_DFLASH_WEPROT_PAGE_DFLASH_MASK ((uint32_t)0x00000003U)         /* !< Write protection enable for ENGR
                                                                                    data flash page with each bit
                                                                                    representing 1 sector of 2KB #br#0:
                                                                                    Page is not erase/program protected
                                                                                    #br#1: Page is erase/program
                                                                                    protected */

/* GSC_FPC_FLSEMREQ Bits */
/* GSC_FPC_FLSEMREQ[REQ] Bits */
#define GSC_FPC_FLSEMREQ_REQ_OFS                 (0)                             /* !< REQ Offset */
#define GSC_FPC_FLSEMREQ_REQ_MASK                ((uint32_t)0x00000001U)         /* !< If the FLSEMSTAT.ASSIGNED bit is
                                                                                    cleared, writing a '1' to this bit
                                                                                    causes: #br#  1) Load the SECURE
                                                                                    attribute  of the code performing the
                                                                                    write into the FLSEMSTAT.SEC bit
                                                                                    field, and #br#  2) Load the
                                                                                    Privilage attribute of the code
                                                                                    performing the write into the
                                                                                    FLSEMSTAT.PRIV bit field, and #br# 3)
                                                                                    Set the FLSEMSTAT.ASSIGNED bit.
                                                                                    #br#If the FLSEMSTAT.ASSIGNED is
                                                                                    already set when a write to this bit
                                                                                    occurs, the write will be ignored.
                                                                                    #br# #br#If the above conditions are
                                                                                    not met during the write, the write
                                                                                    will be ignored with no error
                                                                                    indicator. It is advised that the
                                                                                    writing code perform a read of the
                                                                                    FLSEMSTAT register  to ensure it was
                                                                                    set after writing to this bit. */

/* GSC_FPC_FLSEMCLR Bits */
/* GSC_FPC_FLSEMCLR[CLR] Bits */
#define GSC_FPC_FLSEMCLR_CLR_OFS                 (0)                             /* !< CLR Offset */
#define GSC_FPC_FLSEMCLR_CLR_MASK                ((uint32_t)0x00000001U)         /* !< If the following conditions are
                                                                                    met, a write of '1' to this bit
                                                                                    causes the FLSEMSTAT register to its
                                                                                    reset state: #br#  1) The
                                                                                    FLSEMSTAT.SEC  of the code performing
                                                                                    the write is 0x1 and FLSEMSTAT.PRIV
                                                                                    of the code performing the write is
                                                                                    0x1 (i.e. secure privilage code can
                                                                                    force relinquishing of the semaphore)
                                                                                    or #br#  2) FLSEMSTAT.ASSIGNED bit is
                                                                                    set, and #br#      a) FLSEMSTAT.SEC
                                                                                    matches security attribute of the
                                                                                    code performing the write, and #br#
                                                                                    b) FLSEMSTAT.PRIV  matches
                                                                                    privilege attribute code performing
                                                                                    the write. #br# #br#If the above
                                                                                    conditions are not met during the
                                                                                    write, the write will be ignored with
                                                                                    no error indicated. It is advised
                                                                                    that the writing code perform a read
                                                                                    of the FLSEMSTAT register  to ensure
                                                                                    it was cleared after writing to this
                                                                                    bit. */

/* GSC_FPC_FLSEMSTAT Bits */
/* GSC_FPC_FLSEMSTAT[SEC] Bits */
#define GSC_FPC_FLSEMSTAT_SEC_OFS                (0)                             /* !< SEC Offset */
#define GSC_FPC_FLSEMSTAT_SEC_MASK               ((uint32_t)0x00000001U)         /* !< Defines the flash controller
                                                                                    semaphore owners security attribute
                                                                                    #br#  0x0 : non-secure #br#  0x1
                                                                                    :secure */
/* GSC_FPC_FLSEMSTAT[PRIV] Bits */
#define GSC_FPC_FLSEMSTAT_PRIV_OFS               (8)                             /* !< PRIV Offset */
#define GSC_FPC_FLSEMSTAT_PRIV_MASK              ((uint32_t)0x00000100U)         /* !< Defines the flash controller
                                                                                    semaphore owners privilage attribute
                                                                                    #br#  0x0 : non-privilage #br#  0x1
                                                                                    :prvilage */
/* GSC_FPC_FLSEMSTAT[DBGACC] Bits */
#define GSC_FPC_FLSEMSTAT_DBGACC_OFS             (16)                            /* !< DBGACC Offset */
#define GSC_FPC_FLSEMSTAT_DBGACC_MASK            ((uint32_t)0x00010000U)         /* !< Defines the flash controller
                                                                                    semaphore owners debug access
                                                                                    indication #br#  0x0 : functional
                                                                                    access #br#  0x1 :Debug access */
/* GSC_FPC_FLSEMSTAT[MATCH] Bits */
#define GSC_FPC_FLSEMSTAT_MATCH_OFS              (30)                            /* !< MATCH Offset */
#define GSC_FPC_FLSEMSTAT_MATCH_MASK             ((uint32_t)0x40000000U)         /* !< On a read, this bit will reflect
                                                                                    whether the reader's SEC and PRIV
                                                                                    matches the ownership of the flash
                                                                                    controller. #br#  0 : Code performing
                                                                                    read does not own the flash
                                                                                    controller semaphore #br#  1 : Code
                                                                                    performing read owns the flash
                                                                                    controller semphore. #br#This avoids
                                                                                    code from being required to know
                                                                                    whether the current code segment owns
                                                                                    the flash  controller configuration. */
/* GSC_FPC_FLSEMSTAT[ASSIGNED] Bits */
#define GSC_FPC_FLSEMSTAT_ASSIGNED_OFS           (31)                            /* !< ASSIGNED Offset */
#define GSC_FPC_FLSEMSTAT_ASSIGNED_MASK          ((uint32_t)0x80000000U)         /* !< SEC  and PRIV fields are valid when
                                                                                    this bit is set. #br#  0 : SEC  and
                                                                                    PRIV are unassigned and flash
                                                                                    controller is not accessible #br#  1
                                                                                    : SEC and PRIV values are valid and
                                                                                    the flash controller is currently
                                                                                    assigned to them */

/* GSC_DMA_TRIG_SEL Bits */
/* GSC_DMA_TRIG_SEL[SEL_TRIG] Bits */
#define GSC_DMA_TRIG_SEL_SEL_TRIG_OFS            (0)                             /* !< SEL_TRIG Offset */
#define GSC_DMA_TRIG_SEL_SEL_TRIG_MASK           ((uint32_t)0x0FFFFFFFU)         /* !< Select signal for DMA triggers to
                                                                                    be routed to DMA0/DMA1 #br#0: DMA0
                                                                                    will be selected #br#1: DMA1 will be
                                                                                    selected #br#Note: SEL_TRIG[9:6] is
                                                                                    not used. #br#If a specific DMA is
                                                                                    selected, the triggers should only go
                                                                                    to that DMA */

/* GSC_DMA_FIX_TRIG_SEL Bits */
/* GSC_DMA_FIX_TRIG_SEL[SEL_TRIG] Bits */
#define GSC_DMA_FIX_TRIG_SEL_SEL_TRIG_OFS        (0)                             /* !< SEL_TRIG Offset */
#define GSC_DMA_FIX_TRIG_SEL_SEL_TRIG_MASK       ((uint32_t)0x000007FFU)         /* !< Select signal for Fixed DMA
                                                                                    triggers to be routed to DMA0/DMA1
                                                                                    #br#0: DMA0 will be selected #br#1:
                                                                                    DMA1 will be selected #br# #br#If a
                                                                                    specific DMA is selected, the
                                                                                    triggers should only go to that DMA */

/* GSC_VTOR_S Bits */
/* GSC_VTOR_S[VTOR_S] Bits */
#define GSC_VTOR_S_VTOR_S_OFS                    (0)                             /* !< VTOR_S Offset */
#define GSC_VTOR_S_VTOR_S_MASK                   ((uint32_t)0xFFFFFFFFU)         /* !< value of INITSVTOR port at CPUSS
                                                                                    boundary */

/* GSC_VTOR_NS Bits */
/* GSC_VTOR_NS[VTOR_NS] Bits */
#define GSC_VTOR_NS_VTOR_NS_OFS                  (0)                             /* !< VTOR_NS Offset */
#define GSC_VTOR_NS_VTOR_NS_MASK                 ((uint32_t)0xFFFFFFFFU)         /* !< value of INITNSVTOR port at CPUSS
                                                                                    boundary */

/* GSC_DTB_MUXSEL Bits */
/* GSC_DTB_MUXSEL[DTB_MUX_SEL_CPU] Bits */
#define GSC_DTB_MUXSEL_DTB_MUX_SEL_CPU_OFS       (0)                             /* !< DTB_MUX_SEL_CPU Offset */
#define GSC_DTB_MUXSEL_DTB_MUX_SEL_CPU_MASK      ((uint32_t)0x00000007U)         /* !< DTB Mux Sel for CPU signals to be
                                                                                    brought out on DTB. Refer to
                                                                                    implementaion spec for mux selection
                                                                                    table. */
/* GSC_DTB_MUXSEL[DTB_MUX_SEL_WUC] Bits */
#define GSC_DTB_MUXSEL_DTB_MUX_SEL_WUC_OFS       (5)                             /* !< DTB_MUX_SEL_WUC Offset */
#define GSC_DTB_MUXSEL_DTB_MUX_SEL_WUC_MASK      ((uint32_t)0x000003E0U)         /* !< DTB Mux Sel for WUC signals to be
                                                                                    brought out on DTB. Refer to
                                                                                    implementaion spec for mux selection
                                                                                    table. */

/* GSC_DICE_CHECKSUM0 Bits */
/* GSC_DICE_CHECKSUM0[CID] Bits */
#define GSC_DICE_CHECKSUM0_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM0_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_DICE_CHECKSUM1 Bits */
/* GSC_DICE_CHECKSUM1[CID] Bits */
#define GSC_DICE_CHECKSUM1_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM1_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_DICE_CHECKSUM2 Bits */
/* GSC_DICE_CHECKSUM2[CID] Bits */
#define GSC_DICE_CHECKSUM2_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM2_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_DICE_CHECKSUM3 Bits */
/* GSC_DICE_CHECKSUM3[CID] Bits */
#define GSC_DICE_CHECKSUM3_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM3_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_DICE_CHECKSUM4 Bits */
/* GSC_DICE_CHECKSUM4[CID] Bits */
#define GSC_DICE_CHECKSUM4_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM4_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_DICE_CHECKSUM5 Bits */
/* GSC_DICE_CHECKSUM5[CID] Bits */
#define GSC_DICE_CHECKSUM5_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM5_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_DICE_CHECKSUM6 Bits */
/* GSC_DICE_CHECKSUM6[CID] Bits */
#define GSC_DICE_CHECKSUM6_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM6_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_DICE_CHECKSUM7 Bits */
/* GSC_DICE_CHECKSUM7[CID] Bits */
#define GSC_DICE_CHECKSUM7_CID_OFS               (0)                             /* !< CID Offset */
#define GSC_DICE_CHECKSUM7_CID_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< The register stores the 32-byte
                                                                                    DICE Composite Device Identifier
                                                                                    (CDI) value */

/* GSC_GSC_LOCK Bits */
/* GSC_GSC_LOCK[ATTRIBVIOL_CONFIG] Bits */
#define GSC_GSC_LOCK_ATTRIBVIOL_CONFIG_OFS       (0)                             /* !< ATTRIBVIOL_CONFIG Offset */
#define GSC_GSC_LOCK_ATTRIBVIOL_CONFIG_MASK      ((uint32_t)0x00000001U)         /* !< Configuration impacts registers
                                                                                    SPC_ATTRIBVIOLS_CONFIG,
                                                                                    SPC_ATTRIBVIOLP_CONFIG,
                                                                                    PPC_ATTRIBVIOLS_CONFIG,
                                                                                    PPC_ATTRIBVIOLP_CONFIG,
                                                                                    FPC_ATTRIBVIOLS_CONFIG,
                                                                                    FPC_ATTRIBVIOLP_CONFIG	 #br#0:
                                                                                    Register configuration is not locked.
                                                                                    #br#1: Register configuration is
                                                                                    locked. #br# #br#Once register is
                                                                                    locked - reads give the MMR data and
                                                                                    writes are ignored */
/* GSC_GSC_LOCK[PPC_AATRIB] Bits */
#define GSC_GSC_LOCK_PPC_AATRIB_OFS              (1)                             /* !< PPC_AATRIB Offset */
#define GSC_GSC_LOCK_PPC_AATRIB_MASK             ((uint32_t)0x00000002U)         /* !< Configuration impacts registers
                                                                                    PPC_SECATTRIB_* and PPC_PRIVATTRIB_*
                                                                                    #br#0: Register configuration is not
                                                                                    locked. #br#1: Register configuration
                                                                                    is locked. #br# #br#Once register is
                                                                                    locked - reads give the MMR data and
                                                                                    writes are ignored */
/* GSC_GSC_LOCK[SPC_AATRIB] Bits */
#define GSC_GSC_LOCK_SPC_AATRIB_OFS              (2)                             /* !< SPC_AATRIB Offset */
#define GSC_GSC_LOCK_SPC_AATRIB_MASK             ((uint32_t)0x00000004U)         /* !< Configuration impacts registers
                                                                                    SPC_SECATTRIB_* and SPC_PRIVATTRIB_*
                                                                                    #br#0: Register configuration is not
                                                                                    locked. #br#1: Register configuration
                                                                                    is locked. #br# #br#Once register is
                                                                                    locked - reads give the MMR data and
                                                                                    writes are ignored */
/* GSC_GSC_LOCK[FPPC_AATRIB] Bits */
#define GSC_GSC_LOCK_FPPC_AATRIB_OFS             (3)                             /* !< FPPC_AATRIB Offset */
#define GSC_GSC_LOCK_FPPC_AATRIB_MASK            ((uint32_t)0x00000008U)         /* !< Configuration impacts registers
                                                                                    FPC_SECATTRIB_* and FPC_PRIVATTRIB_*
                                                                                    #br#0: Register configuration is not
                                                                                    locked. #br#1: Register configuration
                                                                                    is locked. #br# #br#Once register is
                                                                                    locked - reads give the MMR data and
                                                                                    writes are ignored */
/* GSC_GSC_LOCK[VTOR] Bits */
#define GSC_GSC_LOCK_VTOR_OFS                    (5)                             /* !< VTOR Offset */
#define GSC_GSC_LOCK_VTOR_MASK                   ((uint32_t)0x00000020U)         /* !< Configuration impacts registers
                                                                                    VTOR_* #br#0: Register configuration
                                                                                    is not locked. #br#1: Register
                                                                                    configuration is locked. #br#
                                                                                    #br#Once register is locked - reads
                                                                                    give the MMR data and writes are
                                                                                    ignored */
/* GSC_GSC_LOCK[DMA_TRIG_SEL] Bits */
#define GSC_GSC_LOCK_DMA_TRIG_SEL_OFS            (6)                             /* !< DMA_TRIG_SEL Offset */
#define GSC_GSC_LOCK_DMA_TRIG_SEL_MASK           ((uint32_t)0x00000040U)         /* !< Configuration impacts registers
                                                                                    DMA_TRIG_SEL* #br#0: Register
                                                                                    configuration is not locked. #br#1:
                                                                                    Register configuration is locked.
                                                                                    #br# #br#Once register is locked -
                                                                                    reads give the MMR data and writes
                                                                                    are ignored */
/* GSC_GSC_LOCK[DTB_MUXSEL] Bits */
#define GSC_GSC_LOCK_DTB_MUXSEL_OFS              (7)                             /* !< DTB_MUXSEL Offset */
#define GSC_GSC_LOCK_DTB_MUXSEL_MASK             ((uint32_t)0x00000080U)         /* !< Configuration impacts registers
                                                                                    DTB_MUX_SEL #br#0: Register
                                                                                    configuration is not locked. #br#1:
                                                                                    Register configuration is locked.
                                                                                    #br# #br#Once register is locked -
                                                                                    reads give the MMR data and writes
                                                                                    are ignored */
/* GSC_GSC_LOCK[KEY] Bits */
#define GSC_GSC_LOCK_KEY_OFS                     (16)                            /* !< KEY Offset */
#define GSC_GSC_LOCK_KEY_MASK                    ((uint32_t)0xFFFF0000U)         /* !< Write 0xA551 to update the register */

/* GSC_GSC_COMMIT Bits */
/* GSC_GSC_COMMIT[ATTRIBVIOL_CONFIG] Bits */
#define GSC_GSC_COMMIT_ATTRIBVIOL_CONFIG_OFS     (0)                             /* !< ATTRIBVIOL_CONFIG Offset */
#define GSC_GSC_COMMIT_ATTRIBVIOL_CONFIG_MASK    ((uint32_t)0x00000001U)         /* !< 0: Register lock configuration is
                                                                                    not committed. #br#1: Register
                                                                                    configuration is committed.
                                                                                    #br#Commit configuration blocks the
                                                                                    writes going to the lock register.
                                                                                    Once configuration is committed, only
                                                                                    reset can change the configuration. */
/* GSC_GSC_COMMIT[PPC_AATRIB] Bits */
#define GSC_GSC_COMMIT_PPC_AATRIB_OFS            (1)                             /* !< PPC_AATRIB Offset */
#define GSC_GSC_COMMIT_PPC_AATRIB_MASK           ((uint32_t)0x00000002U)         /* !< 0: Register lock configuration is
                                                                                    not committed. #br#1: Register
                                                                                    configuration is committed.
                                                                                    #br#Commit configuration blocks the
                                                                                    writes going to the lock register.
                                                                                    Once configuration is committed, only
                                                                                    reset can change the configuration. */
/* GSC_GSC_COMMIT[SPC_AATRIB] Bits */
#define GSC_GSC_COMMIT_SPC_AATRIB_OFS            (2)                             /* !< SPC_AATRIB Offset */
#define GSC_GSC_COMMIT_SPC_AATRIB_MASK           ((uint32_t)0x00000004U)         /* !< 0: Register lock configuration is
                                                                                    not committed. #br#1: Register
                                                                                    configuration is committed.
                                                                                    #br#Commit configuration blocks the
                                                                                    writes going to the lock register.
                                                                                    Once configuration is committed, only
                                                                                    reset can change the configuration. */
/* GSC_GSC_COMMIT[FPPC_AATRIB] Bits */
#define GSC_GSC_COMMIT_FPPC_AATRIB_OFS           (3)                             /* !< FPPC_AATRIB Offset */
#define GSC_GSC_COMMIT_FPPC_AATRIB_MASK          ((uint32_t)0x00000008U)         /* !< 0: Register lock configuration is
                                                                                    not committed. #br#1: Register
                                                                                    configuration is committed.
                                                                                    #br#Commit configuration blocks the
                                                                                    writes going to the lock register.
                                                                                    Once configuration is committed, only
                                                                                    reset can change the configuration. */
/* GSC_GSC_COMMIT[VTOR] Bits */
#define GSC_GSC_COMMIT_VTOR_OFS                  (5)                             /* !< VTOR Offset */
#define GSC_GSC_COMMIT_VTOR_MASK                 ((uint32_t)0x00000020U)         /* !< 0: Register lock configuration is
                                                                                    not committed. #br#1: Register
                                                                                    configuration is committed.
                                                                                    #br#Commit configuration blocks the
                                                                                    writes going to the lock register.
                                                                                    Once configuration is committed, only
                                                                                    reset can change the configuration. */
/* GSC_GSC_COMMIT[DMA_TRIG_SEL] Bits */
#define GSC_GSC_COMMIT_DMA_TRIG_SEL_OFS          (6)                             /* !< DMA_TRIG_SEL Offset */
#define GSC_GSC_COMMIT_DMA_TRIG_SEL_MASK         ((uint32_t)0x00000040U)         /* !< 0: Register lock configuration is
                                                                                    not committed. #br#1: Register
                                                                                    configuration is committed.
                                                                                    #br#Commit configuration blocks the
                                                                                    writes going to the lock register.
                                                                                    Once configuration is committed, only
                                                                                    reset can change the configuration. */
/* GSC_GSC_COMMIT[DTB_MUXSEL] Bits */
#define GSC_GSC_COMMIT_DTB_MUXSEL_OFS            (7)                             /* !< DTB_MUXSEL Offset */
#define GSC_GSC_COMMIT_DTB_MUXSEL_MASK           ((uint32_t)0x00000080U)         /* !< 0: Register lock configuration is
                                                                                    not committed. #br#1: Register
                                                                                    configuration is committed. #br#Once
                                                                                    configuration is committed, only
                                                                                    reset can change the configuration. */
/* GSC_GSC_COMMIT[KEY] Bits */
#define GSC_GSC_COMMIT_KEY_OFS                   (16)                            /* !< KEY Offset */
#define GSC_GSC_COMMIT_KEY_MASK                  ((uint32_t)0xFFFF0000U)         /* !< Write 0xA442 to update the register */

/* GSC_GSC_REVISION Bits */
/* GSC_GSC_REVISION[MINREV] Bits */
#define GSC_GSC_REVISION_MINREV_OFS              (0)                             /* !< MINREV Offset */
#define GSC_GSC_REVISION_MINREV_MASK             ((uint32_t)0x000000FFU)         /* !< This hardcoded field defines the
                                                                                    minor revision of the IP. */
/* GSC_GSC_REVISION[MAJREV] Bits */
#define GSC_GSC_REVISION_MAJREV_OFS              (8)                             /* !< MAJREV Offset */
#define GSC_GSC_REVISION_MAJREV_MASK             ((uint32_t)0x0000FF00U)         /* !< This hardcoded field defines the
                                                                                    major revision of the IP. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_gsc__include */

