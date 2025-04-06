/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "bootutil/bootutil_log.h"
#include "host_device_definition.h"
#include "host_base_address.h"
#include "noc_s3_lib.h"

#include <stddef.h>

#define RAM_AXIS_RO_APU_REGION_IDX  (0)
#define RAM_AXIS_RW_APU_REGION_IDX  (1)

/* Peripheral NoC S3 component nodes */
static const struct noc_s3_component_node periph_ram_amni  = {
    .type = NOC_S3_AMNI,
    .id = PERIPH_RAM_AMNI_ID,
};

static const struct noc_s3_component_node periph_nsuart0_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_NSUART0_PMNI_ID,
};

static const struct noc_s3_component_node periph_secuart_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_SECUART_PMNI_ID,
};

static const struct noc_s3_component_node periph_nsuart1_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_NSUART1_PMNI_ID,
};

static const struct noc_s3_component_node periph_nsgenwdog_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_NSGENWDOG_PMNI_ID,
};

static const struct noc_s3_component_node periph_rootgenwdog_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_ROOTGENWDOG_PMNI_ID,
};

static const struct noc_s3_component_node periph_secgenwdog_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_SECGENWDOG_PMNI_ID,
};

static const struct noc_s3_component_node PERIPH_ECCREG_PMNI_APU_DEV_CFG  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_ECCREG_PMNI_ID,
};

static const struct noc_s3_component_node periph_gtimerctrl_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_GTIMERCTRL_PMNI_ID,
};

static const struct noc_s3_component_node periph_secgtimer_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_SECGTIMER_PMNI_ID,
};

static const struct noc_s3_component_node periph_nsgtimer_pmni  = {
    .type = NOC_S3_PMNI,
    .id = PERIPH_NSGTIMER_PMNI_ID,
};

/*
 * Software implementation defined region for SRAM and is accessible by AP,
 * RSE, SCP and MCP. First region (AP BL1 code region) will be changed to Read
 * only access after RSE loads AP BL1 image.
 */
static const struct noc_s3_apu_reg_cfg_info ram_axim_apu[] = {
    [RAM_AXIS_RO_APU_REGION_IDX] =
        INIT_APU_REGION_UNLOCKED(
                        HOST_AP_BL1_RO_SRAM_PHYS_BASE,
                        HOST_AP_BL1_RO_SRAM_PHYS_LIMIT,
                        NOC_S3_ROOT_RW),
    [RAM_AXIS_RW_APU_REGION_IDX] =
        INIT_APU_REGION(HOST_AP_BL1_RW_SRAM_PHYS_BASE,
                        HOST_AP_BL1_RW_SRAM_PHYS_LIMIT,
                        NOC_S3_ROOT_RW),
};

/* AP Non-secure UART */
static const struct noc_s3_apu_reg_cfg_info nsuart0_apbm_apu[] = {
    INIT_APU_REGION(HOST_NS_UART_PHYS_BASE,
                    HOST_NS_UART_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/* AP Secure UART */
static const struct noc_s3_apu_reg_cfg_info secuart_apbm_apu[] = {
    INIT_APU_REGION(HOST_S_UART_PHYS_BASE,
                    HOST_S_UART_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
};

/* AP Non-secure UART for RMM debug */
static const struct noc_s3_apu_reg_cfg_info nsuart1_apbm_apu[] = {
    INIT_APU_REGION(HOST_RMM_NS_UART_PHYS_BASE,
                    HOST_RMM_NS_UART_PHYS_LIMIT,
                    NOC_S3_REALM_RW),
};

/* AP Non-secure WatchDog */
static const struct noc_s3_apu_reg_cfg_info nsgenwdog_apbm_apu[] = {
    INIT_APU_REGION(HOST_AP_NS_WDOG_PHYS_BASE,
                    HOST_AP_NS_WDOG_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/* AP root WatchDog */
static const struct noc_s3_apu_reg_cfg_info rootgenwdog_apbm_apu[] = {
    INIT_APU_REGION(HOST_AP_RT_WDOG_PHYS_BASE,
                    HOST_AP_RT_WDOG_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
};

/* AP Secure WatchDog */
static const struct noc_s3_apu_reg_cfg_info secgenwdog_apbm_apu[] = {
    INIT_APU_REGION(HOST_AP_S_WDOG_PHYS_BASE,
                    HOST_AP_S_WDOG_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
};

/* Secure SRAM Error record block for the shared ARSM SRAM */
static const struct noc_s3_apu_reg_cfg_info eccreg_apbm_apu[] = {
    INIT_APU_REGION(HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_AP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_REALM_RW),
    INIT_APU_REGION(HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_SCP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_SCP_NS_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_SCP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_SCP_RT_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_SCP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_SCP_RL_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_SCP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_REALM_RW),
    INIT_APU_REGION(HOST_MCP_S_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_MCP_S_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_MCP_NS_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_MCP_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_MCP_RT_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_MCP_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_MCP_RL_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_MCP_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_REALM_RW),
    INIT_APU_REGION(HOST_RSE_S_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_RSE_S_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
    INIT_APU_REGION(HOST_RSE_NS_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_RSE_NS_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
    INIT_APU_REGION(HOST_RSE_RT_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_RSE_RT_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_ROOT_RW),
    INIT_APU_REGION(HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_BASE,
                    HOST_RSE_RL_ARSM_RAM_ECC_REC_PHYS_LIMIT,
                    NOC_S3_REALM_RW),
};

/* AP Generic Timer Control Frame */
static const struct noc_s3_apu_reg_cfg_info gtimerctrl_apbm_apu[] = {
    INIT_APU_REGION(HOST_AP_REFCLK_CNTCTL_PHYS_BASE,
                    HOST_AP_REFCLK_CNTCTL_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/* AP Secure Generic Timer Control Base Frame */
static const struct noc_s3_apu_reg_cfg_info secgtimer_apbm_apu[] = {
    INIT_APU_REGION(HOST_AP_S_REFCLK_CNTBASE0_PHYS_BASE,
                    HOST_AP_S_REFCLK_CNTBASE0_PHYS_LIMIT,
                    NOC_S3_ROOT_RW | NOC_S3_SEC_RW),
};

/* AP Non-secure Generic Timer Control Base Frame */
static const struct noc_s3_apu_reg_cfg_info nsgtimer_apbm_apu[] = {
    INIT_APU_REGION(HOST_AP_NS_REFCLK_CNTBASE1_PHYS_BASE,
                    HOST_AP_NS_REFCLK_CNTBASE1_PHYS_LIMIT,
                    NOC_S3_ALL_PERM),
};

/*
 * Configure Access Protection Unit (APU) to setup access permission for each
 * memory region based on its target in Peripheral NoC S3.
 */
static int32_t program_periph_apu(void)
{
    enum noc_s3_err err;

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    noc_s3_print_discovery_tree(&PERIPH_NOC_S3_DEV, "Peripheral NOC_S3");
#endif

    /*
     * Populates all APU entry into a table array to configure and enable
     * desired APUs
     */
    const struct noc_s3_apu_cfgs apu_table[] = {
        {
            .component = &periph_ram_amni,
            .region_count = ARRAY_SIZE(ram_axim_apu),
            .regions = ram_axim_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_nsuart0_pmni,
            .region_count = ARRAY_SIZE(nsuart0_apbm_apu),
            .regions = nsuart0_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_secuart_pmni,
            .region_count = ARRAY_SIZE(secuart_apbm_apu),
            .regions = secuart_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_nsuart1_pmni,
            .region_count = ARRAY_SIZE(nsuart1_apbm_apu),
            .regions = nsuart1_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_nsgenwdog_pmni,
            .region_count = ARRAY_SIZE(nsgenwdog_apbm_apu),
            .regions = nsgenwdog_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_rootgenwdog_pmni,
            .region_count = ARRAY_SIZE(rootgenwdog_apbm_apu),
            .regions = rootgenwdog_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_secgenwdog_pmni,
            .region_count = ARRAY_SIZE(secgenwdog_apbm_apu),
            .regions = secgenwdog_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &PERIPH_ECCREG_PMNI_APU_DEV_CFG,
            .region_count = ARRAY_SIZE(eccreg_apbm_apu),
            .regions = eccreg_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_gtimerctrl_pmni,
            .region_count = ARRAY_SIZE(gtimerctrl_apbm_apu),
            .regions = gtimerctrl_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_secgtimer_pmni,
            .region_count = ARRAY_SIZE(secgtimer_apbm_apu),
            .regions = secgtimer_apbm_apu,
            .add_chip_addr_offset = false,
        },
        {
            .component = &periph_nsgtimer_pmni,
            .region_count = ARRAY_SIZE(nsgtimer_apbm_apu),
            .regions = nsgtimer_apbm_apu,
            .add_chip_addr_offset = false,
        },
    };

    err = noc_s3_program_apu_table(&PERIPH_NOC_S3_DEV, apu_table,
                                                        ARRAY_SIZE(apu_table));
    if (err != NOC_S3_SUCCESS) {
        return -1;
    }

    return 0;
}

int32_t program_periph_noc_s3(void)
{
    return program_periph_apu();
}

int32_t program_periph_noc_s3_post_ap_bl1_load(void)
{
    enum noc_s3_err err;
    struct noc_s3_apu_dev apu_dev = {0};

    /* Make AP_BL1_RO region read only access */
    struct noc_s3_apu_reg_cfg_info ram_axim_region_0 =
            INIT_APU_REGION(HOST_AP_BL1_RO_SRAM_PHYS_BASE,
                            HOST_AP_BL1_RO_SRAM_PHYS_LIMIT,
                            NOC_S3_ROOT_R);

    /* Initialize APU device */
    err = noc_s3_apu_dev_init(&PERIPH_NOC_S3_DEV,
                              &periph_ram_amni,
                              PERIPH_NOC_S3_DEV.chip_addr_offset,
                              &apu_dev);
    if (err != NOC_S3_SUCCESS) {
        return -1;
    }

    if (noc_s3_apu_configure_region(&apu_dev, &ram_axim_region_0,
                                    RAM_AXIS_RO_APU_REGION_IDX) !=
        NOC_S3_SUCCESS) {
        return -1;
    }

    if (noc_s3_apu_enable(&apu_dev) != NOC_S3_SUCCESS) {
        return -1;
    }

    return 0;
}
