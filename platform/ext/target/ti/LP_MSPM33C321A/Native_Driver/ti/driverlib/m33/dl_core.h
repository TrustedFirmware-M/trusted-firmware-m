/*
 * Copyright (c) 2025, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_core.h
 *  @brief      CPU Core Driver Library
 *  @defgroup   CORE M33 Core
 *
 *  @anchor ti_dl_m33p_dl_core_Overview
 *  # Overview
 *
 *  The Core module enables software to read from core registers of the CPU to
 *  get more information about the device at runtime.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup CORE
 * @{
 */
#ifndef ti_dl_m33_dl_core__include
#define ti_dl_m33_dl_core__include

#include <stdint.h>

#include <ti/devices/msp/msp.h>

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */


/** @addtogroup DL_CORE_DATA_CACHE
 *  @{
 */

/*!
 * @brief Enables DATA caching on flash access
 */
#define DL_CORE_DATA_CACHE_ENABLED                                   ((uint32_t)0x00000002U)

/*
 * @brief Disables DATA caching on flash access
 */
#define DL_CORE_DATA_CACHE_DISABLED                                  ((uint32_t)0x00000000U)

/** @}*/


/** @addtogroup DL_CORE_CODE_CACHE
 *  @{
 */

/*!
 * @brief Enables CODE caching.
 */
#define DL_CORE_CODE_CACHE_ENABLED                                   ((uint32_t)0x00000004U)

/*!
 * @brief Disables CODE caching.
 */
#define DL_CORE_CODE_CACHE_DISABLED                                  ((uint32_t)0x00000000U)

/** @}*/

/*!
 * @brief Enables ECC
 */
#define FRI_ECC_ENABLE_ENABLE                                        ((uint32_t)0x0000000AU)

/*!
 * @brief Disables ECC
 */
#define FRI_ECC_ENABLE_DISABLE                                       ((uint32_t)0x00000000U)

/*!
 * @brief Disables TEST MODE FOR ECC
 */
#define DL_CORE_ECC_TEST_MODE_DISABLE                                ((uint32_t)0x00000000U)

/*!
 * @brief Enables TEST MODE FOR ECC with 1 bit error
 */
#define DL_CORE_ECC_TEST_MODE_ENABLE_1_BIT                           ((uint32_t)0x00000001U)

/*!
 * @brief Enables TEST MODE FOR ECC with 2 bits error
 */
#define DL_CORE_ECC_TEST_MODE_ENABLE_2_BIT                           ((uint32_t)0x00000003U)

/**
 * @brief Alias for DL_Common_delayCycles
 */
#define delay_cycles(cycles) DL_Common_delayCycles(cycles)

/** @}*/

/* clang-format on  */


/**
 *  @brief   Get the implementer code for the processor
 *
 *  @return  The implementer code
 *
 *  @retval  0x41 for ARM
 */
__STATIC_INLINE uint32_t DL_CORE_getImplementer(void)
{
    return (
        (SCB->CPUID & SCB_CPUID_IMPLEMENTER_Msk) >> SCB_CPUID_IMPLEMENTER_Pos);
}

/**
 *  @brief   Get the major revision number 'n' in the 'npm' revision status
 *
 *  @return  The major revision number
 *
 *  @retval  0x01 for revision 1
 */
__STATIC_INLINE uint32_t DL_CORE_getVariant(void)
{
    return ((SCB->CPUID & SCB_CPUID_VARIANT_Msk) >> SCB_CPUID_VARIANT_Pos);
}

/**
 *  @brief   Get the architecture of the processor
 *
 *  @return  Value that defines the architecture of the processor
 *
 *  @retval  0x0F for ARMv7-M architecture
 */
__STATIC_INLINE uint32_t DL_CORE_getArchitecture(void)
{
    return ((SCB->CPUID & SCB_CPUID_ARCHITECTURE_Msk) >>
            SCB_CPUID_ARCHITECTURE_Pos);
}

/**
 *  @brief   Get part number of the processor (not the device)
 *
 *  @return  Value that defines the processor
 *
 *  @retval  0x0D21 
 */
__STATIC_INLINE uint32_t DL_CORE_getPartNumber(void)
{
    return ((SCB->CPUID & SCB_CPUID_PARTNO_Msk) >> SCB_CPUID_PARTNO_Pos);
}

/**
 *  @brief   Get the minor revision number 'm' in the 'npm' revision status
 *
 *  @return  The minor revision number
 *
 *  @retval  0x00 for patch 0
 */
__STATIC_INLINE uint32_t DL_CORE_getRevision(void)
{
    return ((SCB->CPUID & (uint32_t)SCB_CPUID_REVISION_Msk) >> (uint32_t)SCB_CPUID_REVISION_Pos);
}

/**
 * @brief Configures instruction caching in flash accesses and instruction
 *
 * @param datacache [in]  data cache option @ref DL_CORE_DATA_CACHE
 * @param codecache [in]  code cache option @ref DL_CORE_CODE_CACHE
 *
 */
__STATIC_INLINE void DL_CORE_configInstruction(uint32_t dataCache, uint32_t codeCache)
{
    FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 = (dataCache | codeCache);
}

/*
 * @brief Returns instruction data cache and code cache configuration
 *
 * @return Bitwise OR of @ref DL_CORE_DATA_CACHE and @ref DL_CORE_CODE_CACHE
 */

__STATIC_INLINE uint32_t DL_CORE_getInstructionConfig(void)
{
    return(FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 & (FRI_FRD_INTF_CTRL_M33_DATA_CACHE_EN_MASK | FRI_FRD_INTF_CTRL_M33_CODE_CACHE_EN_MASK));
}


/* Enable Data Cache */
__STATIC_INLINE void DL_CORE_enableDataCache(void)
{
    FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 = (FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 | FRI_FRD_INTF_CTRL_M33_DATA_CACHE_EN_MASK);
}

/* Disable Data Cache */
__STATIC_INLINE void DL_CORE_disableDataCache(void)
{
    FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 = (FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 & (~FRI_FRD_INTF_CTRL_M33_DATA_CACHE_EN_MASK));
}

/* Enable Code Cache */
__STATIC_INLINE void DL_CORE_enableCodeCache(void)
{
    FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 = (FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 | FRI_FRD_INTF_CTRL_M33_CODE_CACHE_EN_MASK);
}

/* Disable Code Cache */
__STATIC_INLINE void DL_CORE_disableCodeCache(void)
{
    FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 = (FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 & (~FRI_FRD_INTF_CTRL_M33_CODE_CACHE_EN_MASK));
}

/* Enable ECC */
__STATIC_INLINE void DL_CORE_enableECC(void)
{
    uint32_t ctlTemp = DL_CORE_getInstructionConfig();
    DL_CORE_configInstruction(DL_CORE_DATA_CACHE_DISABLED,DL_CORE_CODE_CACHE_DISABLED);

    FRI->FLASH_CTRL_REGS.ECC_ENABLE = (FRI_ECC_ENABLE_ENABLE_MASK & FRI_ECC_ENABLE_ENABLE);

    delay_cycles(100);
    FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 = ctlTemp;
}

/* Disable ECC */
__STATIC_INLINE void DL_CORE_disableECC(void)
{
    uint32_t ctlTemp = DL_CORE_getInstructionConfig();
    DL_CORE_configInstruction(DL_CORE_DATA_CACHE_DISABLED,DL_CORE_CODE_CACHE_DISABLED);

    FRI->FLASH_CTRL_REGS.ECC_ENABLE = (FRI_ECC_ENABLE_ENABLE_MASK & FRI_ECC_ENABLE_DISABLE);

    delay_cycles(100);
    FRI->FLASH_CTRL_REGS.FRD_INTF_CTRL_M33 = ctlTemp;
}

/* Set ECC test mode */
__STATIC_INLINE void DL_CORE_setECCTestMode(uint32_t mode)
{
    FRI->FLASH_CTRL_REGS.FECC_CTRL_TOPOARIA = ((FRI_FECC_CTRL_TOPOARIA_ECC_TEST_EN_MASK) & mode);
}

/* Enable 'WS0_Mode' for flash read/fetch. It will force zero waitstates for flash read/fetch and ignore the 
   RWAIT and TRIMENGR waitstates values */
__STATIC_INLINE void DL_CORE_enableWS0_MODE(void)
{
    FRI->FLASH_CTRL_REGS.FRDCNTL_M33 = ((FRI->FLASH_CTRL_REGS.FRDCNTL_M33) | FRI_FRDCNTL_M33_WS0_MODE_MASK);
}

/* Disable 'WS0_Mode' for flash read/fetch */
__STATIC_INLINE void DL_CORE_disableWS0_MODE(void)
{
    FRI->FLASH_CTRL_REGS.FRDCNTL_M33 = (FRI->FLASH_CTRL_REGS.FRDCNTL_M33) & (~FRI_FRDCNTL_M33_WS0_MODE_MASK);
}

/* Set waitstates for flash read/fetch. NOTE: It will disable 'WS0_MODE' for non-zero waitstates. */
__STATIC_INLINE void DL_CORE_setReadWaitStates(uint32_t states)
{
    if (states == 0U){
        FRI->FLASH_CTRL_REGS.FRDCNTL_M33 = ((FRI->FLASH_CTRL_REGS.FRDCNTL_M33) | FRI_FRDCNTL_M33_WS0_MODE_MASK);
    }
    else {
        uint32_t value = ((FRI->FLASH_CTRL_REGS.FRDCNTL_M33 & (~FRI_FRDCNTL_M33_RWAIT_MASK)) | ((states << FRI_FRDCNTL_M33_RWAIT_OFS) & FRI_FRDCNTL_M33_RWAIT_MASK));
        value = value & (~FRI_FRDCNTL_M33_WS0_MODE_MASK);
        FRI->FLASH_CTRL_REGS.FRDCNTL_M33 = value;
    }
}

/* Set waitstates for flash read/fetch flash for TRIM/ENGR. NOTE: It will disable 'WS0_MODE' for non-zero waitstates. */
__STATIC_INLINE void DL_CORE_setReadWaitStatesTRIMENGR(uint32_t states)
{
    if (states == 0U){
        FRI->FLASH_CTRL_REGS.FRDCNTL_M33 = ((FRI->FLASH_CTRL_REGS.FRDCNTL_M33) | FRI_FRDCNTL_M33_WS0_MODE_MASK);
    }
    else {
        uint32_t value = ((FRI->FLASH_CTRL_REGS.FRDCNTL_M33 & (~FRI_FRDCNTL_M33_TRIMENGRRWAIT_MASK)) | ((states << FRI_FRDCNTL_M33_TRIMENGRRWAIT_OFS) & FRI_FRDCNTL_M33_TRIMENGRRWAIT_MASK));
        value = value & (~FRI_FRDCNTL_M33_WS0_MODE_MASK);
        FRI->FLASH_CTRL_REGS.FRDCNTL_M33 = value;
    }
}

/*enable SRAM ULL wait state configuration*/
__STATIC_INLINE void DL_CORE_enableSRAMULLWaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG | MEMCFG_RAM_WS_CONFIG_ULL_WS_ENABLE_MASK);
}

/*disable SRAM ULL wait state configuration*/
__STATIC_INLINE void DL_CORE_disableSRAMULLWaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG & (~MEMCFG_RAM_WS_CONFIG_ULL_WS_ENABLE_MASK));
}

/*enable SRAM GLXMP0 wait state configuration*/
__STATIC_INLINE void DL_CORE_enableSRAMGLXMP0WaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG | MEMCFG_RAM_WS_CONFIG_GLXMP_0_WS_ENABLE_MASK);
}

/*disable SRAM GLXMP0 wait state configuration*/
__STATIC_INLINE void DL_CORE_disableSRAMGLXMP0WaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG & (~MEMCFG_RAM_WS_CONFIG_GLXMP_0_WS_ENABLE_MASK));
}

/*enable SRAM GLXMP1 wait state configuration*/
__STATIC_INLINE void DL_CORE_enableSRAMGLXMP1WaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG | MEMCFG_RAM_WS_CONFIG_GLXMP_1_WS_ENABLE_MASK);
}

/*disable SRAM GLXMP1 wait state configuration*/
__STATIC_INLINE void DL_CORE_disableSRAMGLXMP1WaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG & (~MEMCFG_RAM_WS_CONFIG_GLXMP_1_WS_ENABLE_MASK));
}

/*enable SRAM GLXMP2 wait state configuration*/
__STATIC_INLINE void DL_CORE_enableSRAMGLXMP2WaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG | MEMCFG_RAM_WS_CONFIG_GLXMP_2_WS_ENABLE_MASK);
}

/*disable SRAM GLXMP2 wait state configuration*/
__STATIC_INLINE void DL_CORE_disableSRAMGLXMP2WaitState(void)
{
    MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.RAM_WS_CONFIG & (~MEMCFG_RAM_WS_CONFIG_GLXMP_2_WS_ENABLE_MASK));
}

/*enable ROM wait state configuration*/
__STATIC_INLINE void DL_CORE_enableROMWaitState(void)
{
    MEMCFG->MEM_CFG_REGS.ROM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.ROM_WS_CONFIG | MEMCFG_ROM_WS_CONFIG_ROM_WS_ENABLE_MASK);
}

/*disable ROM wait state configuration*/
__STATIC_INLINE void DL_CORE_disableROMWaitState(void)
{
    MEMCFG->MEM_CFG_REGS.ROM_WS_CONFIG = (MEMCFG->MEM_CFG_REGS.ROM_WS_CONFIG & (~MEMCFG_ROM_WS_CONFIG_ROM_WS_ENABLE_MASK));
}

#ifdef __cplusplus
}

#endif

#endif /* ti_dl_m33_dl_core__include */
/** @}*/
