/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __NOC_S3_LIB_H__
#define __NOC_S3_LIB_H__

#include "noc_s3_rse_drv.h"

#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

/*
 * Platform specific apu region initialization macro wrapper. This macros
 * returns 'struct noc_s3_apu_reg_cfg_info' definition by providing
 * the base and end address of APU region and the associated access permission.
 */
#define INIT_APU_REGION(base, end, perm)        \
    {                                           \
        .base_addr = base,                      \
        .end_addr = end,                        \
        .background = NOC_S3_FOREGROUND,        \
        .permissions = { perm, 0, 0, 0 },       \
        .entity_ids = { 0, 0, 0, 0 },           \
        .id_valid = NOC_S3_ID_VALID_NONE,       \
        .region_enable = NOC_S3_REGION_ENABLE,  \
        .lock = NOC_S3_LOCK                     \
    }

/*
 * Platform specific apu region initialization macro wrapper with APU ID
 * Filtering. This macro returns 'struct noc_s3_apu_reg_cfg_info' definition
 * by providing the base and end address of APU region and the associated
 * access permission for all four entities.
 */
#define INIT_APU_REGION_WITH_ALL_ID_FILTER(base, end, mcp_perm, scp_perm, \
                                           rse_perm, dap_perm)            \
    {                                                                     \
        .base_addr = base,                                                \
        .end_addr = end,                                                  \
        .background = NOC_S3_FOREGROUND,                                  \
        .permissions = { mcp_perm, scp_perm, rse_perm, dap_perm },        \
        .entity_ids = { SYSCTRL_MCP_APU_ID, SYSCTRL_SCP_APU_ID,           \
                        SYSCTRL_RSE_APU_ID, SYSCTRL_DAP_APU_ID },         \
        .id_valid = NOC_S3_ID_VALID_ALL,                                  \
        .region_enable = NOC_S3_REGION_ENABLE,                            \
        .lock = NOC_S3_LOCK                                               \
    }

/*
 * Platform specific apu region initialization macro wrapper without locking
 * the region. This macros returns 'struct noc_s3_apu_reg_cfg_info'
 * definition by providing the base and end address of APU region and the
 * associated access permission.
 */
#define INIT_APU_REGION_UNLOCKED(base, end, perm)   \
    {                                               \
        .base_addr = base,                          \
        .end_addr = end,                            \
        .background = NOC_S3_FOREGROUND,            \
        .permissions = { perm, 0, 0, 0 },           \
        .entity_ids = { 0, 0, 0, 0 },               \
        .id_valid = NOC_S3_ID_VALID_NONE,           \
        .region_enable = NOC_S3_REGION_ENABLE,      \
        .lock = NOC_S3_UNLOCK                       \
    }

/* Interface ID of xSNI components - completer interfaces */
enum sysctrl_xSNI_ids {
    /* Request from AP */
    SYSCTRL_APP_ASNI_ID = 0x0,
    /* Request from LCP */
    SYSCTRL_LCP_ASNI_ID,
    /* Request from MCP ATU */
    SYSCTRL_MCP_ASNI_ID,
    /* Request from RSE ATU */
    SYSCTRL_RSE_MAIN_ASNI_ID,
    /* Request from RSE and SCP targeting LCP address space */
    SYSCTRL_RSE_SCP_ASNI_ID,
    /* Request from SCP ATU */
    SYSCTRL_SCP_ASNI_ID
};

/* Interface ID of xMNI components - requester interfaces */
enum sysctrl_xMNI_ids {
    /* Targets AP address space */
    SYSCTRL_APP_AMNI_ID = 0x0,
    /* Targets memory map shared between AP and MCP */
    SYSCTRL_APP_MCP_AMNI_ID,
    /* Targets memory map shared between AP and SCP */
    SYSCTRL_APP_SCP_AMNI_ID,
    /* Targets LCP address space */
    SYSCTRL_LCP_AMNI_ID,
    /* Targets memory map shared between LCP and SCP */
    SYSCTRL_LCP_SCP_AMNI_ID,
    /* Targets Shared SRAM between RSE, SCP and MCP */
    SYSCTRL_RSM_AMNI_ID,
    /* Targets MCP address space */
    SYSCTRL_RSE_MCP_AMNI_ID,
    /* Targets SCP address space */
    SYSCTRL_RSE_SCP_AMNI_ID,
    /* Targets CMN GPV registers */
    SYSCTRL_CMN_PMNI_ID,
    /* Targets Shared RAM between RSE/SCP/MCP */
    SYSCTRL_RSM_PMNI_ID,
    /* Targets SYSCTRL SMMU registers */
    SYSCTRL_TCU_PMNI_ID,
    /* Targets the System Control NoC S3 registers (default target) */
    SYSCTRL_CONFIG_SPACE_ID = 0xF
};

/* APU IDs of the initiator for filter access */
enum sysctrl_apu_filter_ids {
    SYSCTRL_MCP_APU_ID = 0x3C,
    SYSCTRL_SCP_APU_ID = 0x3D,
    SYSCTRL_RSE_APU_ID = 0x3E,
    SYSCTRL_DAP_APU_ID = 0x3F,
};

/* Interface ID of Peripheral xMNI components */
enum periph_xMNI_ids {
    /* Targets ARSM SRAM */
    PERIPH_RAM_AMNI_ID = 0x0,
    /* Targets Secure SRAM Error record block for the shared ARSM SRAM */
    PERIPH_ECCREG_PMNI_ID,
    /* Targets AP Generic Timer Control Frame */
    PERIPH_GTIMERCTRL_PMNI_ID,
    /* Targets AP Non-secure WatchDog */
    PERIPH_NSGENWDOG_PMNI_ID,
    /* Targets AP Non-secure Generic Timer Control Base Frame */
    PERIPH_NSGTIMER_PMNI_ID,
    /* Targets AP Non-secure UART */
    PERIPH_NSUART0_PMNI_ID,
    /* Targets AP Non-secure UART for RMM debug */
    PERIPH_NSUART1_PMNI_ID,
    /* Targets AP root WatchDog */
    PERIPH_ROOTGENWDOG_PMNI_ID,
    /* Targets AP Secure WatchDog */
    PERIPH_SECGENWDOG_PMNI_ID,
    /* Targets AP Secure Generic Timer Control Base Frame */
    PERIPH_SECGTIMER_PMNI_ID,
    /* Targets AP Secure UART */
    PERIPH_SECUART_PMNI_ID
};

/**
 * \brief Programs System Control block NoC S3 PSAM and APU for AON domain
 *
 * \param[in] chip_id  Current Chip ID
 *
 * \return Returns -1 if there is an error, else 0.
 */
int32_t program_sysctrl_noc_s3_aon(uint32_t chip_id);

/**
 * \brief Programs System Control block NoC S3 PSAM and APU for SYSTOP domain
 *
 * \return Returns -1 if there is an error, else 0.
 */
int32_t program_sysctrl_noc_s3_systop(void);

/**
 * \brief Program NoC S3 peripheral block APU
 *
 * \return Returns -1 if there is an error, else 0.
 */
int32_t program_periph_noc_s3(void);

/**
 * \brief Program NoC S3 peripheral block APU to lock ram region after
 *        limiting the region as read only.
 *
 * \return Returns -1 if there is an error, else 0.
 */
int32_t program_periph_noc_s3_post_ap_bl1_load(void);

#endif /* __NOC_S3_LIB_H__ */
