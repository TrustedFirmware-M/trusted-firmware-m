/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file host_css_memory_map.h
 * \brief This file contains addresses that are defined in the compute
 *        subsystem (CSS) memory map.
 */

#ifndef __HOST_CSS_MEMORY_MAP_H__
#define __HOST_CSS_MEMORY_MAP_H__

#include "host_css_io_block_memory_map.h"

/* AP Shared (ARSM) SRAM base address */
#define HOST_AP_SHARED_SRAM_PHYS_BASE               0x000000000ULL
/* AP Shared (ARSM) SRAM end address */
#define HOST_AP_SHARED_SRAM_PHYS_LIMIT              0x0000FFFFFULL

/* AP Memory Expansion region 1 base address */
#define HOST_AP_MEM_EXP_1_PHYS_BASE                 0x008000000ULL
/* AP Memory Expansion region 1 end address */
#define HOST_AP_MEM_EXP_1_PHYS_LIMIT                0x00FFFFFFFULL

/* System Control block NoC S3 base address */
#define HOST_SYSCTRL_NOC_S3_PHYS_BASE               0x010000000ULL
/* System Control block NoC S3 end address */
#define HOST_SYSCTRL_NOC_S3_PHYS_LIMIT              0x010FFFFFFULL
/* System Fabric NoC S3 (NCI in interconnect block) base address */
#define HOST_FABRIC_NOC_S3_PHYS_BASE                0x011000000ULL
/* System Fabric NoC S3 (NCI in interconnect block) end address */
#define HOST_FABRIC_NOC_S3_PHYS_LIMIT               0x011FFFFFFULL
/* Peripheral block NoC S3 base address */
#define HOST_PERIPH_NOC_S3_PHYS_BASE                0x012000000ULL
/* Peripheral block NoC S3 end address */
#define HOST_PERIPH_NOC_S3_PHYS_LIMIT               0x012FFFFFFULL

/* Non-secure Uart peripheral base address */
#define HOST_NS_UART_PHYS_BASE                      0x01A400000ULL
/* Non-secure Uart peripheral end address */
#define HOST_NS_UART_PHYS_LIMIT                     0x01A40FFFFULL
/* Secure Uart peripheral base address */
#define HOST_S_UART_PHYS_BASE                       0x01A410000ULL
/* Secure Uart peripheral end address */
#define HOST_S_UART_PHYS_LIMIT                      0x01A41FFFFULL
/* RMM Uart peripheral base address */
#define HOST_RMM_NS_UART_PHYS_BASE                  0x01A420000ULL
/* RMM Uart peripheral end address */
#define HOST_RMM_NS_UART_PHYS_LIMIT                 0x01A42FFFFULL

/* Generic refclk cntcontrol register base address */
#define HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_BASE    0x01A430000ULL
/* Generic refclk cntcontrol register end address */
#define HOST_GENERIC_REFCLK_CNTCONTROL_PHYS_LIMIT   0x01A43FFFFULL
/* Non-secure AP watchdog base address */
#define HOST_AP_NS_WDOG_PHYS_BASE                   0x01A440000ULL
/* Non-secure AP watchdog end address */
#define HOST_AP_NS_WDOG_PHYS_LIMIT                  0x01A45FFFFULL
/* Root AP watchdog base address */
#define HOST_AP_RT_WDOG_PHYS_BASE                   0x01A460000ULL
/* Root AP watchdog end address */
#define HOST_AP_RT_WDOG_PHYS_LIMIT                  0x01A47FFFFULL
/* Secure AP watchdog base address */
#define HOST_AP_S_WDOG_PHYS_BASE                    0x01A480000ULL
/* Secure AP watchdog end address */
#define HOST_AP_S_WDOG_PHYS_LIMIT                   0x01A49FFFFULL
/* System ID (SID) register base address */
#define HOST_SID_PHYS_BASE                          0x01A4A0000ULL
/* System ID (SID) register end address */
#define HOST_SID_PHYS_LIMIT                         0x01A4AFFFFULL

/* Secure AP ECC error record register base address */
#define HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_BASE        0x01A4B0000ULL
/* Secure AP ECC error record register end address */
#define HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT       0x01A4BFFFFULL
/* Non-Secure AP ECC error record register base address */
#define HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_BASE       0x01A4C0000ULL
/* Non-Secure AP ECC error record register end address */
#define HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x01A4CFFFFULL
/* Root AP ECC error record register base address */
#define HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_BASE       0x01A4D0000ULL
/* Root AP ECC error record register end address */
#define HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x01A4DFFFFULL
/* Realm AP ECC error record register base address */
#define HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_BASE       0x01A4E0000ULL
/* Realm AP ECC error record register end address */
#define HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x01A4EFFFFULL
/* Secure SCP ECC error record register base address */
#define HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_BASE       0x01A4F0000ULL
/* Secure SCP ECC error record register end address */
#define HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x01A4FFFFFULL
/* Non-secure SCP ECC error record register base address */
#define HOST_SCP_NS_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A500000ULL
/* Non-secure SCP ECC error record register end address */
#define HOST_SCP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A50FFFFULL
/* Root SCP ECC error record register base address */
#define HOST_SCP_RT_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A510000ULL
/* Root SCP ECC error record register end address */
#define HOST_SCP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A51FFFFULL
/* Realm SCP ECC error record register base address */
#define HOST_SCP_RL_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A520000ULL
/* Realm SCP ECC error record register end address */
#define HOST_SCP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A52FFFFULL
/* Secure MCP ECC error record register base address */
#define HOST_MCP_S_ARSM_RAM_ECC_REC_PHYS_BASE       0x01A530000ULL
/* Secure MCP ECC error record register end address */
#define HOST_MCP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x01A53FFFFULL
/* Non-secure MCP ECC error record register base address */
#define HOST_MCP_NS_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A540000ULL
/* Non-secure MCP ECC error record register end address */
#define HOST_MCP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A54FFFFULL
/* Root MCP ECC error record register base address */
#define HOST_MCP_RT_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A550000ULL
/* Root MCP ECC error record register end address */
#define HOST_MCP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A55FFFFULL
/* Realm MCP ECC error record register base address */
#define HOST_MCP_RL_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A560000ULL
/* Realm MCP ECC error record register end address */
#define HOST_MCP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A56FFFFULL
/* Secure RSE ECC error record register base address */
#define HOST_RSE_S_ARSM_RAM_ECC_REC_PHYS_BASE       0x01A570000ULL
/* Secure RSE ECC error record register end address */
#define HOST_RSE_S_ARSM_RAM_ECC_REC_PHYS_LIMIT      0x01A57FFFFULL
/* Non-secure RSE ECC error record register base address */
#define HOST_RSE_NS_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A580000ULL
/* Non-secure RSE ECC error record register end address */
#define HOST_RSE_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A58FFFFULL
/* Root RSE ECC error record register base address */
#define HOST_RSE_RT_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A590000ULL
/* Root RSE ECC error record register end address */
#define HOST_RSE_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A59FFFFULL
/* Realm RSE ECC error record register base address */
#define HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_BASE      0x01A5A0000ULL
/* Realm RSE ECC error record register end address */
#define HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT     0x01A5AFFFFULL

/* Secure RSE ECC error record register for RSM base address */
#define HOST_RSE_S_RSM_RAM_ECC_REC_PHYS_BASE        0x01A5B0000ULL
/* Secure RSE ECC error record register for RSM end address */
#define HOST_RSE_S_RSM_RAM_ECC_REC_PHYS_LIMIT       0x01A5BFFFFULL
/* Non-secure RSE ECC error record register for RSM base address */
#define HOST_RSE_NS_RSM_RAM_ECC_REC_PHYS_BASE       0x01A5C0000ULL
/* Non-secure RSE ECC error record register for RSM end address */
#define HOST_RSE_NS_RSM_RAM_ECC_REC_PHYS_LIMIT      0x01A5CFFFFULL
/* Secure SCP ECC error record register for RSM base address */
#define HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_BASE        0x01A5D0000ULL
/* Secure SCP ECC error record register for RSM end address */
#define HOST_SCP_S_RSM_RAM_ECC_REC_PHYS_LIMIT       0x01A5DFFFFULL
/* Non-secure SCP ECC error record register for RSM base address */
#define HOST_SCP_NS_RSM_RAM_ECC_REC_PHYS_BASE       0x01A5E0000ULL
/* Non-secure SCP ECC error record register for RSM end address */
#define HOST_SCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT      0x01A5EFFFFULL
/* Secure MCP ECC error record register for RSM base address */
#define HOST_MCP_S_RSM_RAM_ECC_REC_PHYS_BASE        0x01A5F0000ULL
/* Secure MCP ECC error record register for RSM end address */
#define HOST_MCP_S_RSM_RAM_ECC_REC_PHYS_LIMIT       0x01A5FFFFFULL
/* Non-secure MCP ECC error record register for RSM base address */
#define HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_BASE       0x01A600000ULL
/* Non-secure MCP ECC error record register for RSM end address */
#define HOST_MCP_NS_RSM_RAM_ECC_REC_PHYS_LIMIT      0x01A60FFFFULL

/* Generic refclk cntread register base address */
#define HOST_GENERIC_REFCLK_CNTREAD_PHYS_BASE       0x01A800000ULL
/* Generic refclk cntread register end address */
#define HOST_GENERIC_REFCLK_CNTREAD_PHYS_LIMIT      0x01A80FFFFULL
/* AP refclk cntctl register base address */
#define HOST_AP_REFCLK_CNTCTL_PHYS_BASE             0x01A810000ULL
/* AP refclk cntctl register end address */
#define HOST_AP_REFCLK_CNTCTL_PHYS_LIMIT            0x01A81FFFFULL
/* AP refclk cntbase0 register base address */
#define HOST_AP_S_REFCLK_CNTBASE0_PHYS_BASE         0x01A820000ULL
/* AP refclk cntbase0 register end address */
#define HOST_AP_S_REFCLK_CNTBASE0_PHYS_LIMIT        0x01A82FFFFULL
/* AP refclk cntbase1 register base address */
#define HOST_AP_NS_REFCLK_CNTBASE1_PHYS_BASE        0x01A830000ULL
/* AP refclk cntbase1 register end address */
#define HOST_AP_NS_REFCLK_CNTBASE1_PHYS_LIMIT       0x01A83FFFFULL

/* Non-secure AP<->SCP MHUv3 Send and receive registers base address */
#define HOST_AP_NS_SCP_MHUV3_PHYS_BASE              0x01A900000ULL
/* Non-secure AP<->SCP MHUv3 Send and receive registers end address */
#define HOST_AP_NS_SCP_MHUV3_PHYS_LIMIT             0x01A91FFFFULL
/* Secure AP<->SCP MHUv3 Send and receive registers base address */
#define HOST_AP_S_SCP_MHUV3_PHYS_BASE               0x01A920000ULL
/* Secure AP<->SCP MHUv3 Send and receive registers end address */
#define HOST_AP_S_SCP_MHUV3_PHYS_LIMIT              0x01A93FFFFULL
/* Root AP<->SCP MHUv3 Send and receive registers base address */
#define HOST_AP_RT_SCP_MHUV3_PHYS_BASE              0x01A940000ULL
/* Root AP<->SCP MHUv3 Send and receive registers end address */
#define HOST_AP_RT_SCP_MHUV3_PHYS_LIMIT             0x01A95FFFFULL

/* Non-secure AP<->MCP MHUv3 Send and receive registers base address */
#define HOST_AP_NS_MCP_MHUV3_SEND_BASE              0x01AA00000ULL
/* Non-secure AP<->MCP MHUv3 Send and receive registers end address */
#define HOST_AP_NS_MCP_MHUV3_SEND_LIMIT             0x01AA1FFFFULL
/* Secure AP<->MCP MHUv3 Send and receive registers base address */
#define HOST_AP_S_MCP_MHUV3_PHYS_BASE               0x01AA20000ULL
/* Secure AP<->MCP MHUv3 Send and receive registers end address */
#define HOST_AP_S_MCP_MHUV3_PHYS_LIMIT              0x01AA3FFFFULL
/* Root AP<->MCP MHUv3 Send and receive registers base address */
#define HOST_AP_RT_MCP_MHUV3_PHYS_BASE              0x01AA40000ULL
/* Root AP<->MCP MHUv3 Send and receive registers end address */
#define HOST_AP_RT_MCP_MHUV3_PHYS_LIMIT             0x01AA5FFFFULL

/* Non-secure AP<->RSE MHUv3 Send and receive registers base address */
#define HOST_AP_NS_RSE_MHUV3_PHYS_BASE              0x01AB00000ULL
/* Non-secure AP<->RSE MHUv3 Send and receive registers end address */
#define HOST_AP_NS_RSE_MHUV3_PHYS_LIMIT             0x01AB1FFFFULL
/* Secure AP<->RSE MHUv3 Send and receive registers base address */
#define HOST_AP_S_RSE_MHUV3_PHYS_BASE               0x01AB20000ULL
/* Secure AP<->RSE MHUv3 Send and receive registers end address */
#define HOST_AP_S_RSE_MHUV3_PHYS_LIMIT              0x01AB3FFFFULL
/* Root AP<->RSE MHUv3 Send and receive registers base address */
#define HOST_AP_RT_RSE_MHUV3_PHYS_BASE              0x01AB40000ULL
/* Root AP<->RSE MHUv3 Send and receive registers end address */
#define HOST_AP_RT_RSE_MHUV3_PHYS_LIMIT             0x01AB5FFFFULL
/* Realm AP<->RSE MHUv3 Send and receive registers base address */
#define HOST_AP_RL_RSE_MHUV3_PHYS_BASE              0x01AB60000ULL
/* Realm AP<->RSE MHUv3 Send and receive registers end address */
#define HOST_AP_RL_RSE_MHUV3_PHYS_LIMIT             0x01AB7FFFFULL

/* SCP<->SCP MHU Send registers base address */
#define HOST_SCP_TO_SCP_MHU_PHYS_BASE               0x01AC00000ULL
/* SCP<->SCP MHU Send registers end address */
#define HOST_SCP_TO_SCP_MHU_PHYS_LIMIT              0x01AC7FFFFULL
/* MCP<->MCP MHU Send registers base address */
#define HOST_MCP_TO_MCP_MHU_PHYS_BASE               0x01AD00000ULL
/* MCP<->MCP MHU Send registers end address */
#define HOST_MCP_TO_MCP_MHU_PHYS_LIMIT              0x01AD7FFFFULL
/* RSE<->RSE MHU Send registers base address */
#define HOST_RSE_TO_RSE_MHU_PHYS_BASE               0x01AE00000ULL
/* RSE<->RSE MHU Send registers end address */
#define HOST_RSE_TO_RSE_MHU_PHYS_LIMIT              0x01AE7FFFFULL

/* Macro wrappers for MHU physical address for cross chip send frames */
#define HOST_RSE_N_TO_RSE_N_MHU_PHYS_BASE(chip_id_a, chip_id_b)     \
        HOST_RSE_##chip_id_a##_TO_RSE_##chip_id_b##_MHU_FRAME_PHYS_BASE
#define HOST_RSE_N_TO_RSE_N_MHU_PHYS_LIMIT(chip_id_a, chip_id_b)    \
        HOST_RSE_##chip_id_a##_TO_RSE_##chip_id_b##_MHU_FRAME_PHYS_LIMIT
#define HOST_SCP_N_TO_SCP_N_MHU_PHYS_BASE(chip_id_a, chip_id_b)     \
        HOST_SCP_##chip_id_a##_TO_SCP_##chip_id_b##_MHU_FRAME_PHYS_BASE
#define HOST_SCP_N_TO_SCP_N_MHU_PHYS_LIMIT(chip_id_a, chip_id_b)    \
        HOST_SCP_##chip_id_a##_TO_SCP_##chip_id_b##_MHU_FRAME_PHYS_LIMIT
#define HOST_MCP_N_TO_MCP_N_MHU_PHYS_BASE(chip_id_a, chip_id_b)     \
        HOST_MCP_##chip_id_a##_TO_MCP_##chip_id_b##_MHU_FRAME_PHYS_BASE
#define HOST_MCP_N_TO_MCP_N_MHU_PHYS_LIMIT(chip_id_a, chip_id_b)    \
        HOST_MCP_##chip_id_a##_TO_MCP_##chip_id_b##_MHU_FRAME_PHYS_LIMIT

#define HOST_RSE_0_TO_RSE_1_MHU_FRAME_PHYS_BASE     0x101AE00000ULL
#define HOST_RSE_0_TO_RSE_1_MHU_FRAME_PHYS_LIMIT    0x101AE0FFFFULL
#define HOST_RSE_0_TO_RSE_2_MHU_FRAME_PHYS_BASE     0x201AE00000ULL
#define HOST_RSE_0_TO_RSE_2_MHU_FRAME_PHYS_LIMIT    0x201AE0FFFFULL
#define HOST_RSE_0_TO_RSE_3_MHU_FRAME_PHYS_BASE     0x301AE00000ULL
#define HOST_RSE_0_TO_RSE_3_MHU_FRAME_PHYS_LIMIT    0x301AE0FFFFULL
#define HOST_RSE_1_TO_RSE_0_MHU_FRAME_PHYS_BASE     0x001AE00000ULL
#define HOST_RSE_1_TO_RSE_0_MHU_FRAME_PHYS_LIMIT    0x001AE0FFFFULL
#define HOST_RSE_1_TO_RSE_2_MHU_FRAME_PHYS_BASE     0x201AE10000ULL
#define HOST_RSE_1_TO_RSE_2_MHU_FRAME_PHYS_LIMIT    0x201AE1FFFFULL
#define HOST_RSE_1_TO_RSE_3_MHU_FRAME_PHYS_BASE     0x301AE10000ULL
#define HOST_RSE_1_TO_RSE_3_MHU_FRAME_PHYS_LIMIT    0x301AE1FFFFULL
#define HOST_RSE_2_TO_RSE_0_MHU_FRAME_PHYS_BASE     0x001AE10000ULL
#define HOST_RSE_2_TO_RSE_0_MHU_FRAME_PHYS_LIMIT    0x001AE1FFFFULL
#define HOST_RSE_2_TO_RSE_1_MHU_FRAME_PHYS_BASE     0x101AE10000ULL
#define HOST_RSE_2_TO_RSE_1_MHU_FRAME_PHYS_LIMIT    0x101AE1FFFFULL
#define HOST_RSE_2_TO_RSE_3_MHU_FRAME_PHYS_BASE     0x301AE20000ULL
#define HOST_RSE_2_TO_RSE_3_MHU_FRAME_PHYS_LIMIT    0x301AE2FFFFULL
#define HOST_RSE_3_TO_RSE_0_MHU_FRAME_PHYS_BASE     0x001AE20000ULL
#define HOST_RSE_3_TO_RSE_0_MHU_FRAME_PHYS_LIMIT    0x001AE2FFFFULL
#define HOST_RSE_3_TO_RSE_1_MHU_FRAME_PHYS_BASE     0x101AE20000ULL
#define HOST_RSE_3_TO_RSE_1_MHU_FRAME_PHYS_LIMIT    0x101AE2FFFFULL
#define HOST_RSE_3_TO_RSE_2_MHU_FRAME_PHYS_BASE     0x201AE20000ULL
#define HOST_RSE_3_TO_RSE_2_MHU_FRAME_PHYS_LIMIT    0x201AE2FFFFULL
#define HOST_SCP_0_TO_SCP_1_MHU_FRAME_PHYS_BASE     0x101AC00000ULL
#define HOST_SCP_0_TO_SCP_1_MHU_FRAME_PHYS_LIMIT    0x101AC0FFFFULL
#define HOST_SCP_0_TO_SCP_2_MHU_FRAME_PHYS_BASE     0x201AC00000ULL
#define HOST_SCP_0_TO_SCP_2_MHU_FRAME_PHYS_LIMIT    0x201AC0FFFFULL
#define HOST_SCP_0_TO_SCP_3_MHU_FRAME_PHYS_BASE     0x301AC00000ULL
#define HOST_SCP_0_TO_SCP_3_MHU_FRAME_PHYS_LIMIT    0x301AC0FFFFULL
#define HOST_SCP_1_TO_SCP_0_MHU_FRAME_PHYS_BASE     0x001AC00000ULL
#define HOST_SCP_1_TO_SCP_0_MHU_FRAME_PHYS_LIMIT    0x001AC0FFFFULL
#define HOST_SCP_1_TO_SCP_2_MHU_FRAME_PHYS_BASE     0x201AC10000ULL
#define HOST_SCP_1_TO_SCP_2_MHU_FRAME_PHYS_LIMIT    0x201AC1FFFFULL
#define HOST_SCP_1_TO_SCP_3_MHU_FRAME_PHYS_BASE     0x301AC10000ULL
#define HOST_SCP_1_TO_SCP_3_MHU_FRAME_PHYS_LIMIT    0x301AC1FFFFULL
#define HOST_SCP_2_TO_SCP_0_MHU_FRAME_PHYS_BASE     0x001AC10000ULL
#define HOST_SCP_2_TO_SCP_0_MHU_FRAME_PHYS_LIMIT    0x001AC1FFFFULL
#define HOST_SCP_2_TO_SCP_1_MHU_FRAME_PHYS_BASE     0x101AC10000ULL
#define HOST_SCP_2_TO_SCP_1_MHU_FRAME_PHYS_LIMIT    0x101AC1FFFFULL
#define HOST_SCP_2_TO_SCP_3_MHU_FRAME_PHYS_BASE     0x301AC20000ULL
#define HOST_SCP_2_TO_SCP_3_MHU_FRAME_PHYS_LIMIT    0x301AC2FFFFULL
#define HOST_SCP_3_TO_SCP_0_MHU_FRAME_PHYS_BASE     0x001AC20000ULL
#define HOST_SCP_3_TO_SCP_0_MHU_FRAME_PHYS_LIMIT    0x001AC2FFFFULL
#define HOST_SCP_3_TO_SCP_1_MHU_FRAME_PHYS_BASE     0x101AC20000ULL
#define HOST_SCP_3_TO_SCP_1_MHU_FRAME_PHYS_LIMIT    0x101AC2FFFFULL
#define HOST_SCP_3_TO_SCP_2_MHU_FRAME_PHYS_BASE     0x201AC20000ULL
#define HOST_SCP_3_TO_SCP_2_MHU_FRAME_PHYS_LIMIT    0x201AC2FFFFULL
#define HOST_MCP_0_TO_MCP_1_MHU_FRAME_PHYS_BASE     0x101AD00000ULL
#define HOST_MCP_0_TO_MCP_1_MHU_FRAME_PHYS_LIMIT    0x101AD0FFFFULL
#define HOST_MCP_0_TO_MCP_2_MHU_FRAME_PHYS_BASE     0x201AD00000ULL
#define HOST_MCP_0_TO_MCP_2_MHU_FRAME_PHYS_LIMIT    0x201AD0FFFFULL
#define HOST_MCP_0_TO_MCP_3_MHU_FRAME_PHYS_BASE     0x301AD00000ULL
#define HOST_MCP_0_TO_MCP_3_MHU_FRAME_PHYS_LIMIT    0x301AD0FFFFULL
#define HOST_MCP_1_TO_MCP_0_MHU_FRAME_PHYS_BASE     0x001AD00000ULL
#define HOST_MCP_1_TO_MCP_0_MHU_FRAME_PHYS_LIMIT    0x001AD0FFFFULL
#define HOST_MCP_1_TO_MCP_2_MHU_FRAME_PHYS_BASE     0x201AD10000ULL
#define HOST_MCP_1_TO_MCP_2_MHU_FRAME_PHYS_LIMIT    0x201AD1FFFFULL
#define HOST_MCP_1_TO_MCP_3_MHU_FRAME_PHYS_BASE     0x301AD10000ULL
#define HOST_MCP_1_TO_MCP_3_MHU_FRAME_PHYS_LIMIT    0x301AD1FFFFULL
#define HOST_MCP_2_TO_MCP_0_MHU_FRAME_PHYS_BASE     0x001AD10000ULL
#define HOST_MCP_2_TO_MCP_0_MHU_FRAME_PHYS_LIMIT    0x001AD1FFFFULL
#define HOST_MCP_2_TO_MCP_1_MHU_FRAME_PHYS_BASE     0x101AD10000ULL
#define HOST_MCP_2_TO_MCP_1_MHU_FRAME_PHYS_LIMIT    0x101AD1FFFFULL
#define HOST_MCP_2_TO_MCP_3_MHU_FRAME_PHYS_BASE     0x301AD20000ULL
#define HOST_MCP_2_TO_MCP_3_MHU_FRAME_PHYS_LIMIT    0x301AD2FFFFULL
#define HOST_MCP_3_TO_MCP_0_MHU_FRAME_PHYS_BASE     0x001AD20000ULL
#define HOST_MCP_3_TO_MCP_0_MHU_FRAME_PHYS_LIMIT    0x001AD2FFFFULL
#define HOST_MCP_3_TO_MCP_1_MHU_FRAME_PHYS_BASE     0x101AD20000ULL
#define HOST_MCP_3_TO_MCP_1_MHU_FRAME_PHYS_LIMIT    0x101AD2FFFFULL
#define HOST_MCP_3_TO_MCP_2_MHU_FRAME_PHYS_BASE     0x201AD20000ULL
#define HOST_MCP_3_TO_MCP_2_MHU_FRAME_PHYS_LIMIT    0x201AD2FFFFULL

/* Timer synchronization register base address */
#define HOST_SYNCNT_MSTUPDTVAL_ADDR_PHYS_BASE       0x01AF00000ULL
/* Timer synchronization register end address */
#define HOST_SYNCNT_MSTUPDTVAL_ADDR_PHYS_LIMIT      0x01AF7FFFFULL

/* STM base address */
#define HOST_STM_PHYS_BASE                          0x01E000000ULL
/* STM end address */
#define HOST_STM_PHYS_LIMIT                         0x01EFFFFFFULL

/* Shared SRAM for RSM base address */
#define HOST_RSM_SRAM_PHYS_BASE                     0x01F000000ULL
/* Shared SRAM for RSM end address */
#define HOST_RSM_SRAM_PHYS_LIMIT                    0x01F3FFFFFULL

/* GIC-700 base address */
#define HOST_GIC_700_PHYS_BASE                      0x020000000ULL
/* GIC-700 end address */
#define HOST_GIC_700_PHYS_LIMIT                     0x027FFFFFFULL

/* PCIe NCI Memory space 1 base address */
#define HOST_PCIE_NCI_1_PHYS_BASE                   0x060000000ULL
/* PCIe NCI Memory space 1 end address */
#define HOST_PCIE_NCI_1_PHYS_LIMIT                  0x07FFFFFFFULL

/* DRAM base address */
#define HOST_DRAM_PHYS_BASE                         0x080000000ULL
/* DRAM end address */
#define HOST_DRAM_PHYS_LIMIT                        0x0FFFFFFFFULL

/* CMN GPV base address */
#define HOST_CMN_GPV_PHYS_BASE                      0x100000000ULL
/* CMN GPV end address */
#define HOST_CMN_GPV_PHYS_LIMIT                     0x13FFFFFFFULL

/* LCP peripherals + Cluster utility memory region base address */
#define HOST_CLUST_UTIL_PHYS_BASE                   0x140000000ULL
/* LCP peripherals + Cluster utility memory region end address */
#define HOST_CLUST_UTIL_PHYS_LIMIT                  0x17FFFFFFFULL

/* Memory controller + MPE register region base address */
#define HOST_MPE_PHYS_BASE                          0x180000000ULL
/* Memory controller + MPE register region end address */
#define HOST_MPE_PHYS_LIMIT                         0x1BFFFFFFFULL

/* Base address for IO Block memory region */
#define HOST_IO_BLOCK_PHYS_BASE             HOST_IO_TCU_PHYS_BASE(0)
/* End address for IO Block memory region */
#define HOST_IO_BLOCK_PHYS_LIMIT            HOST_IO_PCIE_CTRL_EXP_PHYS_LIMIT(11)

/* SYSCTRL SMMU base address */
#define HOST_SYSCTRL_SMMU_PHYS_BASE                 0x240000000ULL
/* SYSCTRL SMMU end address */
#define HOST_SYSCTRL_SMMU_PHYS_LIMIT                0x247FFFFFFULL

/* AP Memory Expansion region 2 base address */
#define HOST_AP_MEM_EXP_2_PHYS_BASE                 0x600000000ULL
/* AP Memory Expansion region 2 end address */
#define HOST_AP_MEM_EXP_2_PHYS_LIMIT                0x7FFFFFFFFULL

/* Debug Memory map base address */
#define HOST_DEBUG_MMAP_PHYS_BASE                   0x800000000ULL
/* Debug Memory map end address */
#define HOST_DEBUG_MMAP_PHYS_LIMIT                  0xDFFFFFFFFULL

/* Address offset of AP region of different chips */
#define HOST_AP_CHIP_OFFSET                         0x1000000000ULL
/* Base address of the AP region of the nth chip */
#define HOST_AP_CHIP_N_PHYS_BASE(n)                 (0x0ULL  +                \
                                                     HOST_AP_CHIP_OFFSET * (n))
/* End address of the AP region of the nth chip */
#define HOST_AP_CHIP_N_PHYS_LIMIT(n)                (0xFFFFFFFFFULL +         \
                                                     HOST_AP_CHIP_OFFSET * (n))

/* PCIe NCI Memory space 2 base address */
#define HOST_PCIE_NCI_2_PHYS_BASE                   0x10000000000ULL
/* PCIe NCI Memory space 2 end address */
#define HOST_PCIE_NCI_2_PHYS_LIMIT                  0x100FFFFFFFFULL
/* PCIe NCI Memory space 3 base address */
#define HOST_PCIE_NCI_3_PHYS_BASE                   0x10100000000ULL
/* PCIe NCI Memory space 3 end address */
#define HOST_PCIE_NCI_3_PHYS_LIMIT                  0x1FFFFFFFFFFULL

/* AP Memory Expansion region 3 base address */
#define HOST_AP_MEM_EXP_3_PHYS_BASE                 0xC00000000000ULL
/* AP Memory Expansion region 3 end address */
#define HOST_AP_MEM_EXP_3_PHYS_LIMIT                0xFFFFFFFFFFFFULL

#endif /* __HOST_CSS_MEMORY_MAP_H__ */
