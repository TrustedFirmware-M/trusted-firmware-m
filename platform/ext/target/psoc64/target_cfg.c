/*
 * Copyright (c) 2018 Arm Limited
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <assert.h>
#include <stdio.h> /* for debugging printfs */
#include "cy_prot.h"
#include "device_definition.h"
#include "driver_ppu.h"
#include "driver_smpu.h"
#include "pc_config.h"
#include "platform_description.h"
#include "region_defs.h"
#include "RTE_Device.h"
#include "target_cfg.h"
#include "tfm_plat_defs.h"

/* Macros to pick linker symbols */
#define REGION(a, b, c) a##b##c
#define REGION_NAME(a, b, c) REGION(a, b, c)
#define REGION_DECLARE(a, b, c) extern uint32_t REGION_NAME(a, b, c)

/* The section names come from the scatter file */
REGION_DECLARE(Load$$LR$$, LR_NS_PARTITION, $$Base);
#ifdef BL2
REGION_DECLARE(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base);
#endif /* BL2 */

const struct memory_region_limits memory_regions = {
    .non_secure_code_start =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        BL2_HEADER_SIZE,

    .non_secure_partition_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base),

    .non_secure_partition_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        NS_PARTITION_SIZE - 1,
};


#ifdef BL2
REGION_DECLARE(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base);
#endif /* BL2 */

/* To write into AIRCR register, 0x5FA value must be write to the VECTKEY field,
 * otherwise the processor ignores the write.
 */
#define SCB_AIRCR_WRITE_MASK ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos))

struct tfm_spm_partition_platform_data_t tfm_peripheral_std_uart = {
        SCB5_BASE,
        SCB5_BASE + 0xFFF,
        -1,
        -1
};

void enable_fault_handlers(void)
{
    /* Fault handles enable registers are not present in Cortex-M0+ */
}

void system_reset_cfg(void)
{
    uint32_t reg_value = SCB->AIRCR;

    /* Clear SCB_AIRCR_VECTKEY value */
    reg_value &= ~(uint32_t)(SCB_AIRCR_VECTKEY_Msk);

    /* Set Access Key (0x05FA must be written to this field) */
    reg_value |= (uint32_t)(SCB_AIRCR_WRITE_MASK);

    SCB->AIRCR = reg_value;
}

enum tfm_plat_err_t nvic_interrupt_target_state_cfg(void)
{
    printf("%s()\n", __func__);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t nvic_interrupt_enable(void)
{
    /* PPU and SMPU don't generate interrupts.
     * USART and Flash drivers don't export an EnableInterrupt function.
     * So there's nothing to do here.
     */
    return TFM_PLAT_ERR_SUCCESS;
}

static cy_en_prot_status_t set_bus_master_attr(void)
{
    cy_en_prot_status_t ret;

    printf("%s()\n", __func__);

    /* Cortex-M4 - Unprivileged (ignored?), Non-secure, PC=6 */
    ret = Cy_Prot_ConfigBusMaster(CPUSS_MS_ID_CM4, false, false, HOST_PCS_MASK);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }
    ret = Cy_Prot_SetActivePC(CPUSS_MS_ID_CM4, CY_PROT_HOST_DEFAULT);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }

    /* Test Controller - Unprivileged, Non-secure, PC=7 */
    ret = Cy_Prot_ConfigBusMaster(CPUSS_MS_ID_TC, false, false, TC_PC_MASK);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }
    ret = Cy_Prot_SetActivePC(CPUSS_MS_ID_TC, CY_PROT_TC);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }

    /* Crypto - Privileged, Secure, PC=1 */
    ret = Cy_Prot_ConfigBusMaster(CPUSS_MS_ID_CRYPTO, true, true, SECURE_PCS_MASK);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }
    ret = Cy_Prot_SetActivePC(CPUSS_MS_ID_CRYPTO, CY_PROT_SPM_DEFAULT);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }

    /* Cortex-M0+ - Privileged (ignored?), Secure, PC=1 */
    ret = Cy_Prot_ConfigBusMaster(CPUSS_MS_ID_CM0, true, true, SECURE_PCS_MASK);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }
    ret = Cy_Prot_SetActivePC(CPUSS_MS_ID_CM0, CY_PROT_SPM_DEFAULT);
    if (ret != CY_PROT_SUCCESS) {
        return ret;
    }

    return CY_PROT_SUCCESS;
}

void bus_masters_cfg(void)
{
    cy_en_prot_status_t ret = set_bus_master_attr();
    if (ret) printf("set_bus_master_attr() returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
}

void smpu_init_cfg(void)
{
    cy_en_prot_status_t ret;

    printf("%s()\n", __func__);

    printf("memory_regions.non_secure_code_start = %#x\n", memory_regions.non_secure_code_start);
    printf("memory_regions.non_secure_partition_base = %#x\n", memory_regions.non_secure_partition_base);
    printf("memory_regions.non_secure_partition_limit = %#x\n", memory_regions.non_secure_partition_limit);

#if RTE_SMPU13
    ret = SMPU_Configure(&SMPU13_Resources);
    if (ret) printf("SMPU_Configure(SMPU13) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU12
    ret = SMPU_Configure(&SMPU12_Resources);
    if (ret) printf("SMPU_Configure(SMPU12) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU11
    ret = SMPU_Configure(&SMPU11_Resources);
    if (ret) printf("SMPU_Configure(SMPU11) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU10
    ret = SMPU_Configure(&SMPU10_Resources);
    if (ret) printf("SMPU_Configure(SMPU10) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU9
    ret = SMPU_Configure(&SMPU9_Resources);
    if (ret) printf("SMPU_Configure(SMPU9) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU8
    ret = SMPU_Configure(&SMPU8_Resources);
    if (ret) printf("SMPU_Configure(SMPU8) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU7
    ret = SMPU_Configure(&SMPU7_Resources);
    if (ret) printf("SMPU_Configure(SMPU7) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU6
    ret = SMPU_Configure(&SMPU6_Resources);
    if (ret) printf("SMPU_Configure(SMPU6) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU5
    ret = SMPU_Configure(&SMPU5_Resources);
    if (ret) printf("SMPU_Configure(SMPU5) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU4
    ret = SMPU_Configure(&SMPU4_Resources);
    if (ret) printf("SMPU_Configure(SMPU4) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU3
    ret = SMPU_Configure(&SMPU3_Resources);
    if (ret) printf("SMPU_Configure(SMPU3) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU2
    ret = SMPU_Configure(&SMPU2_Resources);
    if (ret) printf("SMPU_Configure(SMPU2) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU1
    ret = SMPU_Configure(&SMPU1_Resources);
    if (ret) printf("SMPU_Configure(SMPU1) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_SMPU0
    ret = SMPU_Configure(&SMPU0_Resources);
    if (ret) printf("SMPU_Configure(SMPU0) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif

    /* Now protect all unconfigured SMPUs */
    ret = protect_unconfigured_smpus();
    if (ret) printf("protect_unconfigured_smpus() returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);

    __DSB();
    __ISB();
}

void ppu_init_cfg(void)
{
    cy_en_prot_status_t ret;

    printf("%s()\n", __func__);

#if RTE_PPU_PR0
    ret = PPU_Configure(&PR0_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR1
    ret = PPU_Configure(&PR1_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR2
    ret = PPU_Configure(&PR2_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR3
    ret = PPU_Configure(&PR3_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR4
    ret = PPU_Configure(&PR4_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR5
    ret = PPU_Configure(&PR5_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR5_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR6
    ret = PPU_Configure(&PR6_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR6_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR7
    ret = PPU_Configure(&PR7_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR7_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_PR8
    ret = PPU_Configure(&PR8_PPU_Resources);
    if (ret) printf("PPU_Configure(&PR8_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR0
    ret = PPU_Configure(&GR0_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR1
    ret = PPU_Configure(&GR1_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR2
    ret = PPU_Configure(&GR2_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR3
    ret = PPU_Configure(&GR3_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR4
    ret = PPU_Configure(&GR4_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR6
    ret = PPU_Configure(&GR6_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR6_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR9
    ret = PPU_Configure(&GR9_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR9_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR10
    ret = PPU_Configure(&GR10_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR10_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO0
    ret = PPU_Configure(&GR_MMIO0_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO1
    ret = PPU_Configure(&GR_MMIO1_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO2
    ret = PPU_Configure(&GR_MMIO2_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO3
    ret = PPU_Configure(&GR_MMIO3_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO4
    ret = PPU_Configure(&GR_MMIO4_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO6
    ret = PPU_Configure(&GR_MMIO6_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO6_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO9
    ret = PPU_Configure(&GR_MMIO9_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO9_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO10
    ret = PPU_Configure(&GR_MMIO10_PPU_Resources);
    if (ret) printf("PPU_Configure(&GR_MMIO10_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_PPU_GR_MMIO0
    ret = PPU_Configure(&SL_PERI_GR1_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PERI_GR1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_CRYPTO
    ret = PPU_Configure(&SL_CRYPTO_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_CRYPTO_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PERI_GR2
    ret = PPU_Configure(&SL_PERI_GR2_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PERI_GR2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_CPUSS
    ret = PPU_Configure(&SL_CPUSS_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_CPUSS_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_FAULT
    ret = PPU_Configure(&SL_FAULT_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_FAULT_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_IPC
    ret = PPU_Configure(&SL_IPC_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_IPC_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PROT
    ret = PPU_Configure(&SL_PROT_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PROT_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_FLASHC
    ret = PPU_Configure(&SL_FLASHC_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_FLASHC_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SRSS
    ret = PPU_Configure(&SL_SRSS_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SRSS_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_BACKUP
    ret = PPU_Configure(&SL_BACKUP_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_BACKUP_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_DW0
    ret = PPU_Configure(&SL_DW0_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_DW0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_DW1
    ret = PPU_Configure(&SL_DW1_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_DW1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_EFUSE
    ret = PPU_Configure(&SL_EFUSE_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_EFUSE_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PROFILE
    ret = PPU_Configure(&SL_PROFILE_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PROFILE_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT0
    ret = PPU_Configure(&RG_IPC_STRUCT0_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT1
    ret = PPU_Configure(&RG_IPC_STRUCT1_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT2
    ret = PPU_Configure(&RG_IPC_STRUCT2_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT3
    ret = PPU_Configure(&RG_IPC_STRUCT3_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT4
    ret = PPU_Configure(&RG_IPC_STRUCT4_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT5
    ret = PPU_Configure(&RG_IPC_STRUCT5_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT5_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT6
    ret = PPU_Configure(&RG_IPC_STRUCT6_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT6_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_STRUCT7
    ret = PPU_Configure(&RG_IPC_STRUCT7_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_STRUCT7_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT0
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT0_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT1
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT1_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT2
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT2_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT3
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT3_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT4
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT4_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT5
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT5_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT5_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT6
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT6_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT6_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_IPC_INTR_STRUCT7
    ret = PPU_Configure(&RG_IPC_INTR_STRUCT7_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_IPC_INTR_STRUCT7_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW0_DW_CH_STRUCT0
    ret = PPU_Configure(&RG_DW0_DW_CH_STRUCT0_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW0_DW_CH_STRUCT0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW0_DW_CH_STRUCT1
    ret = PPU_Configure(&RG_DW0_DW_CH_STRUCT1_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW0_DW_CH_STRUCT1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW0_DW_CH_STRUCT2
    ret = PPU_Configure(&RG_DW0_DW_CH_STRUCT2_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW0_DW_CH_STRUCT2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW0_DW_CH_STRUCT3
    ret = PPU_Configure(&RG_DW0_DW_CH_STRUCT3_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW0_DW_CH_STRUCT3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW1_DW_CH_STRUCT0
    ret = PPU_Configure(&RG_DW1_DW_CH_STRUCT0_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW1_DW_CH_STRUCT0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW1_DW_CH_STRUCT1
    ret = PPU_Configure(&RG_DW1_DW_CH_STRUCT1_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW1_DW_CH_STRUCT1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW1_DW_CH_STRUCT2
    ret = PPU_Configure(&RG_DW1_DW_CH_STRUCT2_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW1_DW_CH_STRUCT2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_DW1_DW_CH_STRUCT3
    ret = PPU_Configure(&RG_DW1_DW_CH_STRUCT3_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_DW1_DW_CH_STRUCT3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_SMPU
    ret = PPU_Configure(&RG_SMPU_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_SMPU_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_MPU_CM0P
    ret = PPU_Configure(&RG_MPU_CM0P_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_MPU_CM0P_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_MPU_CRYPTO
    ret = PPU_Configure(&RG_MPU_CRYPTO_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_MPU_CRYPTO_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_MPU_CM4
    ret = PPU_Configure(&RG_MPU_CM4_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_MPU_CM4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_RG_MPU_TC
    ret = PPU_Configure(&RG_MPU_TC_PPU_Resources);
    if (ret) printf("PPU_Configure(&RG_MPU_TC_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PERI_GR3
    ret = PPU_Configure(&SL_PERI_GR3_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PERI_GR3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_HSIOM
    ret = PPU_Configure(&SL_HSIOM_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_HSIOM_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_GPIO
    ret = PPU_Configure(&SL_GPIO_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_GPIO_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SMARTIO
    ret = PPU_Configure(&SL_SMARTIO_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SMARTIO_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_UDB
    ret = PPU_Configure(&SL_UDB_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_UDB_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_LPCOMP
    ret = PPU_Configure(&SL_LPCOMP_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_LPCOMP_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_CSD
    ret = PPU_Configure(&SL_CSD_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_CSD_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_TCPWM0
    ret = PPU_Configure(&SL_TCPWM0_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_TCPWM0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_TCPWM1
    ret = PPU_Configure(&SL_TCPWM1_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_TCPWM1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_LCD
    ret = PPU_Configure(&SL_LCD_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_LCD_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_BLE
    ret = PPU_Configure(&SL_BLE_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_BLE_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_USBFS
    ret = PPU_Configure(&SL_USBFS_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_USBFS_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PERI_GR4
    ret = PPU_Configure(&SL_PERI_GR4_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PERI_GR4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SMIF
    ret = PPU_Configure(&SL_SMIF_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SMIF_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PERI_GR6
    ret = PPU_Configure(&SL_PERI_GR6_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PERI_GR6_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB0
    ret = PPU_Configure(&SL_SCB0_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB0_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB1
    ret = PPU_Configure(&SL_SCB1_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB1_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB2
    ret = PPU_Configure(&SL_SCB2_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB2_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB3
    ret = PPU_Configure(&SL_SCB3_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB3_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB4
    ret = PPU_Configure(&SL_SCB4_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB4_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB5
    ret = PPU_Configure(&SL_SCB5_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB5_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB6
    ret = PPU_Configure(&SL_SCB6_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB6_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB7
    ret = PPU_Configure(&SL_SCB7_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB7_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_SCB8
    ret = PPU_Configure(&SL_SCB8_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_SCB8_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PERI_GR9
    ret = PPU_Configure(&SL_PERI_GR9_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PERI_GR9_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PASS
    ret = PPU_Configure(&SL_PASS_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PASS_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PERI_GB10
    ret = PPU_Configure(&SL_PERI_GR10_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PERI_GR10_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_I2S
    ret = PPU_Configure(&SL_I2S_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_I2S_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif
#if RTE_GR_PPU_SL_PDM
    ret = PPU_Configure(&SL_PDM_PPU_Resources);
    if (ret) printf("PPU_Configure(&SL_PDM_PPU_Resources) returned %d\n", ret);
    assert(ret == CY_PROT_SUCCESS);
#endif

    __DSB();
    __ISB();
}
