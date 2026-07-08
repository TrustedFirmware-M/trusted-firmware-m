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

#ifndef ti_devices_msp_peripherals_hw_memcfg__include
#define ti_devices_msp_peripherals_hw_memcfg__include

/* Filename: hw_memcfg.h */
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
* MEMCFG Registers
******************************************************************************/
#define MEMCFG_MEM_CFG_REGS_OFS                  ((uint32_t)0x00000000U)


/** @addtogroup MEMCFG_MEM_CFG_REGS
  @{
*/

typedef struct {
       uint32_t RESERVED0[1024];
  __IO uint32_t TEST;                              /* !< (@ 0x00001000) RAM TEST Register */
  __IO uint32_t RAM_CACHE_CONFIG;                  /* !< (@ 0x00001004) RAM CACHE configuration */
  __IO uint32_t RAM_WS_CONFIG;                     /* !< (@ 0x00001008) RAM wait state configuration */
  __IO uint32_t RAM_CACHE_CLEAR;                   /* !< (@ 0x0000100C) RAM cache clear */
  __IO uint32_t ROM_WS_CONFIG;                     /* !< (@ 0x00001010) ROM wait state configuration */
} MEMCFG_MEM_CFG_REGS_Regs;

/*@}*/ /* end of group MEMCFG_MEM_CFG_REGS */

/** @addtogroup MEMCFG
  @{
*/

typedef struct {
  MEMCFG_MEM_CFG_REGS_Regs  MEM_CFG_REGS;                      /* !< (@ 0x00000000) */
} MEMCFG_Regs;

/*@}*/ /* end of group MEMCFG */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* MEMCFG Register Control Bits
******************************************************************************/

/* MEMCFG_TEST Bits */
/* MEMCFG_TEST[TEST_ULL] Bits */
#define MEMCFG_TEST_TEST_ULL_OFS                 (0)                             /* !< TEST_ULL Offset */
#define MEMCFG_TEST_TEST_ULL_MASK                ((uint32_t)0x00000003U)         /* !< Selects the defferent modes for ULL
                                                                                    RAM: #br#    00: Functional Mode.
                                                                                    #br#    01: Writes are allowed to
                                                                                    data bits only. No write to ECC bits.
                                                                                    #br#    10: Writes are allowed to ECC
                                                                                    bits only. No write to data bits.
                                                                                    #br#    11: Same as functional mode */
/* MEMCFG_TEST[TEST_GLXMP_0] Bits */
#define MEMCFG_TEST_TEST_GLXMP_0_OFS             (2)                             /* !< TEST_GLXMP_0 Offset */
#define MEMCFG_TEST_TEST_GLXMP_0_MASK            ((uint32_t)0x0000000CU)         /* !< Selects the defferent modes for
                                                                                    GLXMP_0 RAM: #br#    00: Functional
                                                                                    Mode. #br#    01: Writes are allowed
                                                                                    to data bits only. No write to ECC
                                                                                    bits. #br#    10: Writes are allowed
                                                                                    to ECC bits only. No write to data
                                                                                    bits. #br#    11: Same as functional
                                                                                    mode */
/* MEMCFG_TEST[TEST_GLXMP_1] Bits */
#define MEMCFG_TEST_TEST_GLXMP_1_OFS             (4)                             /* !< TEST_GLXMP_1 Offset */
#define MEMCFG_TEST_TEST_GLXMP_1_MASK            ((uint32_t)0x00000030U)         /* !< Selects the defferent modes for
                                                                                    GLXMP_1 RAM: #br#    00: Functional
                                                                                    Mode. #br#    01: Writes are allowed
                                                                                    to data bits only. No write to ECC
                                                                                    bits. #br#    10: Writes are allowed
                                                                                    to ECC bits only. No write to data
                                                                                    bits. #br#    11: Same as functional
                                                                                    mode */
/* MEMCFG_TEST[TEST_GLXMP_2] Bits */
#define MEMCFG_TEST_TEST_GLXMP_2_OFS             (6)                             /* !< TEST_GLXMP_2 Offset */
#define MEMCFG_TEST_TEST_GLXMP_2_MASK            ((uint32_t)0x000000C0U)         /* !< Selects the defferent modes for
                                                                                    GLXMP_2 RAM: #br#    00: Functional
                                                                                    Mode. #br#    01: Writes are allowed
                                                                                    to data bits only. No write to ECC
                                                                                    bits. #br#    10: Writes are allowed
                                                                                    to ECC bits only. No write to data
                                                                                    bits. #br#    11: Same as functional
                                                                                    mode */

/* MEMCFG_RAM_CACHE_CONFIG Bits */
/* MEMCFG_RAM_CACHE_CONFIG[ULL_CACHE_ENABLE] Bits */
#define MEMCFG_RAM_CACHE_CONFIG_ULL_CACHE_ENABLE_OFS (0)                             /* !< ULL_CACHE_ENABLE Offset */
#define MEMCFG_RAM_CACHE_CONFIG_ULL_CACHE_ENABLE_MASK ((uint32_t)0x00000001U)         /* !< Cache configuration for ULL RAM:
                                                                                    #br#    1: Cache enable. #br#    0:
                                                                                    Cache support disable. */
/* MEMCFG_RAM_CACHE_CONFIG[GLXMP_0_CACHE_ENABLE] Bits */
#define MEMCFG_RAM_CACHE_CONFIG_GLXMP_0_CACHE_ENABLE_OFS (1)                             /* !< GLXMP_0_CACHE_ENABLE Offset */
#define MEMCFG_RAM_CACHE_CONFIG_GLXMP_0_CACHE_ENABLE_MASK ((uint32_t)0x00000002U)         /* !< Cache configuration for GLXMP_0
                                                                                    RAM: #br#    1: Cache enable. #br#
                                                                                    0: Cache support disable. */
/* MEMCFG_RAM_CACHE_CONFIG[GLXMP_1_CACHE_ENABLE] Bits */
#define MEMCFG_RAM_CACHE_CONFIG_GLXMP_1_CACHE_ENABLE_OFS (2)                             /* !< GLXMP_1_CACHE_ENABLE Offset */
#define MEMCFG_RAM_CACHE_CONFIG_GLXMP_1_CACHE_ENABLE_MASK ((uint32_t)0x00000004U)         /* !< Cache configuration for GLXMP_1
                                                                                    RAM: #br#    1: Cache enable. #br#
                                                                                    0: Cache support disable. */
/* MEMCFG_RAM_CACHE_CONFIG[GLXMP_2_CACHE_ENABLE] Bits */
#define MEMCFG_RAM_CACHE_CONFIG_GLXMP_2_CACHE_ENABLE_OFS (3)                             /* !< GLXMP_2_CACHE_ENABLE Offset */
#define MEMCFG_RAM_CACHE_CONFIG_GLXMP_2_CACHE_ENABLE_MASK ((uint32_t)0x00000008U)         /* !< Cache configuration for GLXMP_2
                                                                                    RAM: #br#    1: Cache enable. #br#
                                                                                    0: Cache support disable. */

/* MEMCFG_RAM_WS_CONFIG Bits */
/* MEMCFG_RAM_WS_CONFIG[ULL_WS_ENABLE] Bits */
#define MEMCFG_RAM_WS_CONFIG_ULL_WS_ENABLE_OFS   (0)                             /* !< ULL_WS_ENABLE Offset */
#define MEMCFG_RAM_WS_CONFIG_ULL_WS_ENABLE_MASK  ((uint32_t)0x00000001U)         /* !< Wait state configuration for ULL
                                                                                    RAM: #br#    0: 1wait state disable.
                                                                                    #br#    1: 1 wait enable. */
/* MEMCFG_RAM_WS_CONFIG[GLXMP_0_WS_ENABLE] Bits */
#define MEMCFG_RAM_WS_CONFIG_GLXMP_0_WS_ENABLE_OFS (1)                             /* !< GLXMP_0_WS_ENABLE Offset */
#define MEMCFG_RAM_WS_CONFIG_GLXMP_0_WS_ENABLE_MASK ((uint32_t)0x00000002U)         /* !< Wait state configuration for
                                                                                    GLXMP_0 RAM: #br#    0: 1wait state
                                                                                    disable. #br#    1: 1 wait enable. */
/* MEMCFG_RAM_WS_CONFIG[GLXMP_1_WS_ENABLE] Bits */
#define MEMCFG_RAM_WS_CONFIG_GLXMP_1_WS_ENABLE_OFS (2)                             /* !< GLXMP_1_WS_ENABLE Offset */
#define MEMCFG_RAM_WS_CONFIG_GLXMP_1_WS_ENABLE_MASK ((uint32_t)0x00000004U)         /* !< Wait state configuration for
                                                                                    GLXMP_1 RAM: #br#    0: 1wait state
                                                                                    disable. #br#    1: 1 wait enable. */
/* MEMCFG_RAM_WS_CONFIG[GLXMP_2_WS_ENABLE] Bits */
#define MEMCFG_RAM_WS_CONFIG_GLXMP_2_WS_ENABLE_OFS (3)                             /* !< GLXMP_2_WS_ENABLE Offset */
#define MEMCFG_RAM_WS_CONFIG_GLXMP_2_WS_ENABLE_MASK ((uint32_t)0x00000008U)         /* !< Wait state configuration for
                                                                                    GLXMP_2 RAM: #br#    0: 1wait state
                                                                                    disable. #br#    1: 1 wait enable. */

/* MEMCFG_RAM_CACHE_CLEAR Bits */
/* MEMCFG_RAM_CACHE_CLEAR[ULL_CACHE_CLEAR] Bits */
#define MEMCFG_RAM_CACHE_CLEAR_ULL_CACHE_CLEAR_OFS (0)                             /* !< ULL_CACHE_CLEAR Offset */
#define MEMCFG_RAM_CACHE_CLEAR_ULL_CACHE_CLEAR_MASK ((uint32_t)0x00000001U)         /* !< Cache clear configuration for ULL
                                                                                    RAM: #br#    0: wont clear the cache
                                                                                    valid slots. #br#    1: Clear the all
                                                                                    cache valid slots and write back the
                                                                                    write buffer data to memory macro. */
/* MEMCFG_RAM_CACHE_CLEAR[GLXMP_0_CACHE_CLEAR] Bits */
#define MEMCFG_RAM_CACHE_CLEAR_GLXMP_0_CACHE_CLEAR_OFS (1)                             /* !< GLXMP_0_CACHE_CLEAR Offset */
#define MEMCFG_RAM_CACHE_CLEAR_GLXMP_0_CACHE_CLEAR_MASK ((uint32_t)0x00000002U)         /* !< Cache clear configuration for
                                                                                    GLAMP_0 RAM: #br#    0: wont clear
                                                                                    the cache valid slots. #br#    1:
                                                                                    Clear the all cache valid slots and
                                                                                    write back the write buffer data to
                                                                                    memory macro. */
/* MEMCFG_RAM_CACHE_CLEAR[GLXMP_1_WS_CACHE_CLEAR] Bits */
#define MEMCFG_RAM_CACHE_CLEAR_GLXMP_1_WS_CACHE_CLEAR_OFS (2)                             /* !< GLXMP_1_WS_CACHE_CLEAR Offset */
#define MEMCFG_RAM_CACHE_CLEAR_GLXMP_1_WS_CACHE_CLEAR_MASK ((uint32_t)0x00000004U)         /* !< Cache clear configuration for
                                                                                    GLXMP_1 RAM: #br#    0: wont clear
                                                                                    the cache valid slots. #br#    1:
                                                                                    Clear the all cache valid slots and
                                                                                    write back the write buffer data to
                                                                                    memory macro. */
/* MEMCFG_RAM_CACHE_CLEAR[GLXMP_2_WS_CACHE_CLEAR] Bits */
#define MEMCFG_RAM_CACHE_CLEAR_GLXMP_2_WS_CACHE_CLEAR_OFS (3)                             /* !< GLXMP_2_WS_CACHE_CLEAR Offset */
#define MEMCFG_RAM_CACHE_CLEAR_GLXMP_2_WS_CACHE_CLEAR_MASK ((uint32_t)0x00000008U)         /* !< Cache clear configuration for
                                                                                    GLXMP_2 RAM: #br#    0: wont clear
                                                                                    the cache valid slots. #br#    1:
                                                                                    Clear the all cache valid slots and
                                                                                    write back the write buffer data to
                                                                                    memory macro. */

/* MEMCFG_ROM_WS_CONFIG Bits */
/* MEMCFG_ROM_WS_CONFIG[ROM_WS_ENABLE] Bits */
#define MEMCFG_ROM_WS_CONFIG_ROM_WS_ENABLE_OFS   (0)                             /* !< ROM_WS_ENABLE Offset */
#define MEMCFG_ROM_WS_CONFIG_ROM_WS_ENABLE_MASK  ((uint32_t)0x00000001U)         /* !< Wait state configuration ROM: #br#
                                                                                    0: 1wait state disable. #br#    1:
                                                                                    1 wait enable. */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_memcfg__include */

