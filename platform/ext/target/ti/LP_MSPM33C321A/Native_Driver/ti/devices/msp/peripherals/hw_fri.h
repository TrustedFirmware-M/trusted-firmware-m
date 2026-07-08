/*****************************************************************************

  Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/ 

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

#ifndef ti_devices_msp_peripherals_hw_fri__include
#define ti_devices_msp_peripherals_hw_fri__include

/* This preliminary header file does not have a version number */
/* Filename: hw_fri.h */
/* MMR revised: 2024-11-25 06:21:42 */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp65soc/repos/m33c1 */
/* MMR revision: a0f7dca5d4cf924663986bfa1fdd55dddd7aafe8 */
/* Generator revision: daea8c76dae02d21df5916c27b417fe7c2521b12
   (MInT: 7456bc61ab943d25fa56c4258186ef3874017fc3) */

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
* FRI Registers
******************************************************************************/
#define FRI_FLASH_CTRL_REGS_OFS                  ((uint32_t)0x00000000U)


/** @addtogroup FRI_FLASH_CTRL_REGS
  @{
*/

typedef struct {
  __IO uint32_t Reserved_1[1024];                  /* !< (@ 0x00000000) */
  union {
      __IO uint32_t FRDCNTL_M33;                       /* !< Flash Read Control Register */
      __IO uint32_t FRDCNTL_M33_FRDCNTL_1;             /* !< Flash Read Control Register */
  };
  __IO uint32_t FLPROT;                            /* !< (@ 0x00001004) Flash program/erase protect register */
  __IO uint32_t FLCLKCTL;                          /* !< (@ 0x00001008) Flash NW clock control register. */
  union {
      __IO uint32_t FRD_INTF_CTRL_M33;                 /* !< Flash Read Interface Control Register */
      __IO uint32_t FRD_INTF_CTRL_M33_FRD_INTF_CTRL_1; /* !< Flash Read Interface Control Register */
  };
  union {
      __IO uint32_t DTB_MUXSEL;                        /* !< Flash Read Interface DTB Mux select */
      __IO uint32_t DTB_MUXSEL_DTB_MUXSEL_1;           /* !< Flash Read Interface DTB Mux select */
  };
  __IO uint32_t Reserved_2[59];                    /* !< (@ 0x00001014) */
  __IO uint32_t ECC_ENABLE;                        /* !< (@ 0x00001100) ECC Enable */
  union {
      __IO uint32_t FECC_CTRL_TOPOARIA;                /* !< ECC Control */
      __IO uint32_t FECC_CTRL_TOPOARIA_FECC_CTRL_1;    /* !< ECC Control */
  };
  __IO uint32_t Reserved_3[958];                   /* !< (@ 0x00001108) */
} FRI_FLASH_CTRL_REGS_Regs;

/*@}*/ /* end of group FRI_FLASH_CTRL_REGS */

/** @addtogroup FRI
  @{
*/

typedef struct {
  FRI_FLASH_CTRL_REGS_Regs  FLASH_CTRL_REGS;                   /* !< (@ 0x00000000) */
} FRI_Regs;

/*@}*/ /* end of group FRI */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* FRI Register Control Bits
******************************************************************************/

/* FRI_FRDCNTL_M33 Bits */
/* FRI_FRDCNTL_M33[WS0_MODE] Bits */
#define FRI_FRDCNTL_M33_WS0_MODE_OFS             (0)                             /* !< WS0_MODE Offset */
#define FRI_FRDCNTL_M33_WS0_MODE_MASK            ((uint32_t)0x00000001U)         /* !< When set, waitstate of the flash
                                                                                    will be forced to 0 Waitstate.
                                                                                    #br#When this bit is set, RWAIT and
                                                                                    TRIMENGRRWAIT values will be ignored. */
/* FRI_FRDCNTL_M33[RWAIT] Bits */
#define FRI_FRDCNTL_M33_RWAIT_OFS                (8)                             /* !< RWAIT Offset */
#define FRI_FRDCNTL_M33_RWAIT_MASK               ((uint32_t)0x00000F00U)         /* !< Random read waitstate #br#
                                                                                    #br#These bits indicate how many
                                                                                    waitstates are added to a flash
                                                                                    read/fetch access.  The RWAIT value
                                                                                    can be set anywhere from 0 to 0xF.
                                                                                    For a flash access, data is returned
                                                                                    in RWAIT+1 SYSCLK cycles. #br#Note:
                                                                                    The required wait states for each
                                                                                    SYSCLK frequency can be found in the
                                                                                    device data manual. */
/* FRI_FRDCNTL_M33[TRIMENGRRWAIT] Bits */
#define FRI_FRDCNTL_M33_TRIMENGRRWAIT_OFS        (24)                            /* !< TRIMENGRRWAIT Offset */
#define FRI_FRDCNTL_M33_TRIMENGRRWAIT_MASK       ((uint32_t)0x0F000000U)         /* !< Random read waitstate of Trim and
                                                                                    ENGR sectors #br# #br#These bits
                                                                                    indicate how many waitstates are
                                                                                    added to a flash read/fetch access.
                                                                                    The TRIMENGRRWAIT value can be set
                                                                                    anywhere from 0 to 0xF. For a flash
                                                                                    access from TRIM or ENGR sectors,
                                                                                    data is returned in RWAIT+1 SYSCLK
                                                                                    cycles. #br#Note: The required wait
                                                                                    states for each SYSCLK frequency can
                                                                                    be found in the device data manual. */

/* FRI_FRDCNTL_1 Bits */
/* FRI_FRDCNTL_1[WS0_MODE] Bits */
#define FRI_FRDCNTL_1_WS0_MODE_OFS               (0)                             /* !< WS0_MODE Offset */
#define FRI_FRDCNTL_1_WS0_MODE_MASK              ((uint32_t)0x00000001U)         /* !< When set, waitstate of the flash
                                                                                    will be forced to 0 Waitstate.
                                                                                    #br#When this bit is set, RWAIT and
                                                                                    TRIMENGRRWAIT values will be ignored. */
/* FRI_FRDCNTL_1[RWAIT] Bits */
#define FRI_FRDCNTL_1_RWAIT_OFS                  (8)                             /* !< RWAIT Offset */
#define FRI_FRDCNTL_1_RWAIT_MASK                 ((uint32_t)0x00000F00U)         /* !< Random read waitstate #br#
                                                                                    #br#These bits indicate how many
                                                                                    waitstates are added to a flash
                                                                                    read/fetch access.  The RWAIT value
                                                                                    can be set anywhere from 0 to 0xF.
                                                                                    For a flash access, data is returned
                                                                                    in RWAIT+1 SYSCLK cycles. #br#Note:
                                                                                    The required wait states for each
                                                                                    SYSCLK frequency can be found in the
                                                                                    device data manual. */
/* FRI_FRDCNTL_1[TRIMENGRRWAIT] Bits */
#define FRI_FRDCNTL_1_TRIMENGRRWAIT_OFS          (24)                            /* !< TRIMENGRRWAIT Offset */
#define FRI_FRDCNTL_1_TRIMENGRRWAIT_MASK         ((uint32_t)0x0F000000U)         /* !< Random read waitstate of Trim and
                                                                                    ENGR sectors #br# #br#These bits
                                                                                    indicate how many waitstates are
                                                                                    added to a flash read/fetch access.
                                                                                    The TRIMENGRRWAIT value can be set
                                                                                    anywhere from 0 to 0xF. For a flash
                                                                                    access from TRIM or ENGR sectors,
                                                                                    data is returned in RWAIT+1 SYSCLK
                                                                                    cycles. #br#Note: The required wait
                                                                                    states for each SYSCLK frequency can
                                                                                    be found in the device data manual. */

/* FRI_FLPROT Bits */
/* FRI_FLPROT[FLWEPROT] Bits */
#define FRI_FLPROT_FLWEPROT_OFS                  (0)                             /* !< FLWEPROT Offset */
#define FRI_FLPROT_FLWEPROT_MASK                 ((uint32_t)0x00000001U)         /* !< Flash program/erase protect bit.
                                                                                    #br#0 : Program erase operation
                                                                                    allowed subject to security settings.
                                                                                    #br#1 : Program erase operation
                                                                                    blocked in hardware. */

/* FRI_FLCLKCTL Bits */
/* FRI_FLCLKCTL[KDIV] Bits */
#define FRI_FLCLKCTL_KDIV_OFS                    (0)                             /* !< KDIV Offset */
#define FRI_FLCLKCTL_KDIV_MASK                   ((uint32_t)0x0000000FU)         /* !< FCLKfrequency = (SYSCLKfrequency) /
                                                                                    (KDIV/MDIV) #br#KDIV encoding:
                                                                                    #br#0x0 :  = 1 #br#0x1 :  = 2 #br#0x2
                                                                                    :  = 3 #br#0x3 :  = 4 #br#0x4 :  = 5
                                                                                    #br#0x5 :  = 6 #br#0x6 :  = 10
                                                                                    #br#0x7 :  = 12 #br#0x8 :  = 15
                                                                                    #br#0x9 :  = 20 #br#0xA :  = 30
                                                                                    #br#0xB :  = 60 #br#0xC - 0xF :  = 30
                                                                                    #br# #br#Note: KDIV value should be
                                                                                    less than or equal to KDIV value. */
/* FRI_FLCLKCTL[MDIV] Bits */
#define FRI_FLCLKCTL_MDIV_OFS                    (4)                             /* !< MDIV Offset */
#define FRI_FLCLKCTL_MDIV_MASK                   ((uint32_t)0x000000F0U)         /* !< FCLKfrequency = (SYSCLKfrequency) /
                                                                                    (KDIV/MDIV) #br#MDIV encoding:
                                                                                    #br#0x0 :  = 1 #br#0x1 :  = 2 #br#0x2
                                                                                    :  = 3 #br#0x3 :  = 4 #br#0x4 :  = 5
                                                                                    #br#0x5 - 0xF :  = 6 #br# #br#Note:
                                                                                    MDIV value should be less than or
                                                                                    equal to KDIV value. */

/* FRI_FRD_INTF_CTRL_M33 Bits */
/* FRI_FRD_INTF_CTRL_M33[PREFETCH_EN] Bits */
#define FRI_FRD_INTF_CTRL_M33_PREFETCH_EN_OFS    (0)                             /* !< PREFETCH_EN Offset */
#define FRI_FRD_INTF_CTRL_M33_PREFETCH_EN_MASK   ((uint32_t)0x00000001U)         /* !< Prefetch enable. #br# 0 A value of
                                                                                    0 disables prefetch mechanism. #br#1
                                                                                    A value of 1 enables pre-fetch
                                                                                    mechanism. */

/* FRI_FRD_INTF_CTRL_M33[DATA_CACHE_EN] Bits */
#define FRI_FRD_INTF_CTRL_M33_DATA_CACHE_EN_OFS  (1)                             /* !< DATA_CACHE_EN Offset */
#define FRI_FRD_INTF_CTRL_M33_DATA_CACHE_EN_MASK ((uint32_t)0x00000002U)         /* !< Data cache enable. #br#0 A value of
                                                                                    0 disables the data cache. #br#1 A
                                                                                    value of 1 enables the data cache. */

/* FRI_FRD_INTF_CTRL_M33[CODE_CACHE_EN] Bits */
#define FRI_FRD_INTF_CTRL_M33_CODE_CACHE_EN_OFS  (2)                             /* !< CODE_CACHE_EN Offset */
#define FRI_FRD_INTF_CTRL_M33_CODE_CACHE_EN_MASK ((uint32_t)0x00000004U)         /* !< Code cache enable. #br#0 A value of
                                                                                    0 disables the Code cache. #br#1 A
                                                                                    value of 1 enables the Code cache. */ 

/* FRI_FRD_INTF_CTRL_1 Bits */
/* FRI_FRD_INTF_CTRL_1[PREFETCH_EN] Bits */
#define FRI_FRD_INTF_CTRL_1_PREFETCH_EN_OFS      (0)                             /* !< PREFETCH_EN Offset */
#define FRI_FRD_INTF_CTRL_1_PREFETCH_EN_MASK     ((uint32_t)0x00000001U)         /* !< Prefetch enable. #br# 0 A value of
                                                                                    0 disables prefetch mechanism. #br#1
                                                                                    A value of 1 enables pre-fetch
                                                                                    mechanism. */
/* FRI_FRD_INTF_CTRL_1[DATA_CACHE_EN] Bits */
#define FRI_FRD_INTF_CTRL_1_DATA_CACHE_EN_OFS    (1)                             /* !< DATA_CACHE_EN Offset */
#define FRI_FRD_INTF_CTRL_1_DATA_CACHE_EN_MASK   ((uint32_t)0x00000002U)         /* !< Data cache enable. #br#0 A value of
                                                                                    0 disables the data cache. #br#1 A
                                                                                    value of 1 enables the data cache. */
/* FRI_FRD_INTF_CTRL_1[CODE_CACHE_EN] Bits */
#define FRI_FRD_INTF_CTRL_1_CODE_CACHE_EN_OFS    (2)                             /* !< CODE_CACHE_EN Offset */
#define FRI_FRD_INTF_CTRL_1_CODE_CACHE_EN_MASK   ((uint32_t)0x00000004U)         /* !< Code cache enable. #br#0 A value of
                                                                                    0 disables the Code cache. #br#1 A
                                                                                    value of 1 enables the Code cache. */

/* FRI_DTB_MUXSEL Bits */
/* FRI_DTB_MUXSEL[DTB_MUX_SEL_FRI] Bits */
#define FRI_DTB_MUXSEL_DTB_MUX_SEL_FRI_OFS       (0)                             /* !< DTB_MUX_SEL_FRI Offset */
#define FRI_DTB_MUXSEL_DTB_MUX_SEL_FRI_MASK      ((uint32_t)0x00000003U)         /* !< DTB Mux Select for Flash read
                                                                                    interface signals to be exported out
                                                                                    on DTB bus. Based on the MUXSELECT
                                                                                    value, corresponding banks' DTB
                                                                                    signals will be exported out. #br#00
                                                                                    - Bank0 #br#01 - Bank1 #br#10 - Bank2
                                                                                    #br#11 - Reserved */

/* FRI_DTB_MUXSEL_1 Bits */
/* FRI_DTB_MUXSEL_1[DTB_MUX_SEL_FRI] Bits */
#define FRI_DTB_MUXSEL_1_DTB_MUX_SEL_FRI_OFS     (0)                             /* !< DTB_MUX_SEL_FRI Offset */
#define FRI_DTB_MUXSEL_1_DTB_MUX_SEL_FRI_MASK    ((uint32_t)0x00000003U)         /* !< DTB Mux Select for Flash read
                                                                                    interface signals to be exported out
                                                                                    on DTB bus. Based on the MUXSELECT
                                                                                    value, corresponding banks' DTB
                                                                                    signals will be exported out. #br#00
                                                                                    - Bank0 #br#01 - Bank1 #br#10 - Bank2
                                                                                    #br#11 - Reserved */

/* FRI_ECC_ENABLE Bits */
/* FRI_ECC_ENABLE[ENABLE] Bits */
#define FRI_ECC_ENABLE_ENABLE_OFS                (0)                             /* !< ENABLE Offset */
#define FRI_ECC_ENABLE_ENABLE_MASK               ((uint32_t)0x0000000FU)         /* !< ECC enable. A value of 0xA would
                                                                                    enable ECC. Any other value would
                                                                                    disable ECC. */

/* FRI_FECC_CTRL_TOPOARIA Bits */
/* FRI_FECC_CTRL_TOPOARIA[ECC_TEST_EN] Bits */
#define FRI_FECC_CTRL_TOPOARIA_ECC_TEST_EN_OFS   (0)                             /* !< ECC_TEST_EN Offset */
#define FRI_FECC_CTRL_TOPOARIA_ECC_TEST_EN_MASK  ((uint32_t)0x00000003U)         /* !< ECC test mode enable. #br#00 ECC
                                                                                    test mode disabled #br#01 ECC test
                                                                                    mode enabled, one of the 64 data bits
                                                                                    is flipped and fed to the redundant
                                                                                    ECC logic (on both ECC logic low and
                                                                                    ECC logc high blocks). #br#11 ECC
                                                                                    test mode enabled, Two of the 64 data
                                                                                    bits are flipped and fed to the
                                                                                    redundant ECC logic (on both ECC
                                                                                    logic low and ECC logc high blocks).
                                                                                    #br#10 Reserved */

/* FRI_FECC_CTRL_1 Bits */
/* FRI_FECC_CTRL_1[ECC_TEST_EN] Bits */
#define FRI_FECC_CTRL_1_ECC_TEST_EN_OFS          (0)                             /* !< ECC_TEST_EN Offset */
#define FRI_FECC_CTRL_1_ECC_TEST_EN_MASK         ((uint32_t)0x00000003U)         /* !< ECC test mode enable. #br#00 ECC
                                                                                    test mode disabled #br#01 ECC test
                                                                                    mode enabled, one of the 64 data bits
                                                                                    is flipped and fed to the redundant
                                                                                    ECC logic (on both ECC logic low and
                                                                                    ECC logc high blocks). #br#11 ECC
                                                                                    test mode enabled, Two of the 64 data
                                                                                    bits are flipped and fed to the
                                                                                    redundant ECC logic (on both ECC
                                                                                    logic low and ECC logc high blocks).
                                                                                    #br#10 Reserved */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_fri__include */

