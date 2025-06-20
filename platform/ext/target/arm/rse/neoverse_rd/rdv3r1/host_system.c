/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "device_definition.h"
#include "host_base_address.h"
#include "host_system.h"
#include "tfm_hal_device_header.h"
#include "tfm_plat_otp.h"
#include "rse_get_rse_id.h"
#include "atu_rse_lib.h"
#ifdef RD_SYSCTRL_NOC_S3
#include "noc_s3_lib.h"

#define NOC_S3_SYSCTRL_SYSTOP_PARENT_TYPE      NOC_S3_VD
#define NOC_S3_SYSCTRL_SYSTOP_PARENT_ID        (0)
#define NOC_S3_SYSCTRL_SYSTOP_IDX              (1)
#endif

static struct host_system_t host_system_data = {0};

#if defined(RD_SYSCTRL_NOC_S3) || defined(RD_PERIPH_NOC_S3)
/*
 * Initializes the ATU region before configuring the NoC S3. This function
 * maps the physical base address of the NoC S3 instance received as the
 * parameter to a logical address HOST_NOC_S3_BASE.
 */
static int noc_s3_pre_init(uint64_t noc_s3_phys_address)
{
    enum atu_error_t atu_err;

    atu_err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S, noc_s3_phys_address,
                                           HOST_NOC_S3_BASE, HOST_NOC_S3_SIZE,
                                           ATU_ENCODE_ATTRIBUTES_SECURE_PAS |
                                           ATU_ROBA_SET_1 << ATU_ATUROBA_AXNSE_OFF |
                                           ATU_ROBA_SET_0 << ATU_ATUROBA_AXPROT1_OFF);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    return 0;
}

/* Un-initializes the ATU region after configuring the NoC S3 */
static int noc_s3_post_init(void)
{
    enum atu_error_t atu_err;

    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_NOC_S3_BASE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    return 0;
}
#endif

#ifdef RD_SYSCTRL_NOC_S3
/* Voltage domain - 0 is the parent node of SYSTOP Power domain */
static const struct noc_s3_component_node systop_parent_node = {
    .type = NOC_S3_SYSCTRL_SYSTOP_PARENT_TYPE,
    .id = NOC_S3_SYSCTRL_SYSTOP_PARENT_ID,
};

/* List of node data to be skipped during AON discovery */
static const struct noc_s3_skip_component_discovery_node_data
    skip_aon_discovery_data[] = {
    /*
     * Skip discovery of SYSTOP power domain node since the node is
     * undiscoverable unless the SYSTOP power domain in turned on by SCP.
     * CFG_NODE - 0
     *    |
     *    +--> VD - 0
     *            |
     *            +--> PD - 0 (AON) ...
     *            |
     *            +--> PD - 1 (SYSTOP) ...
     *
     */
    {
        .parent_node = &systop_parent_node,
        .node_idx = NOC_S3_SYSCTRL_SYSTOP_IDX,
    },
};

/*
 * Programs the System control NoC S3 for nodes under Always-On (AON) domain.
 */
static int noc_s3_sysctrl_aon_init(void)
{
    int err;

    err = noc_s3_pre_init(host_system_data.info.chip_ap_phys_base +
                            HOST_SYSCTRL_NOC_S3_PHYS_BASE);
    if (err != 0) {
        return err;
    }

    SYSCTRL_NOC_S3_DEV.skip_discovery_list =
        &(struct noc_s3_skip_component_discovery_list ){
            .skip_node_data = skip_aon_discovery_data,
            .skip_node_count = ARRAY_SIZE(skip_aon_discovery_data),
        };

    SYSCTRL_NOC_S3_DEV.chip_addr_offset =
            host_system_data.info.chip_ap_phys_base;
    err = program_sysctrl_noc_s3_aon(host_system_data.info.chip_id);
    if (err != 0) {
        return err;
    }

    SYSCTRL_NOC_S3_DEV.skip_discovery_list = NULL;

    err = noc_s3_post_init();
    if (err != 0) {
        return err;
    }

    return 0;
}

/*
 * Programs the System control NoC S3 for nodes under SYSTOP domain.
 */
static int noc_s3_sysctrl_systop_init(void)
{
    int err;

    err = noc_s3_pre_init(host_system_data.info.chip_ap_phys_base +
                            HOST_SYSCTRL_NOC_S3_PHYS_BASE);
    if (err != 0) {
        return err;
    }

    SYSCTRL_NOC_S3_DEV.chip_addr_offset =
            host_system_data.info.chip_ap_phys_base;
    err = program_sysctrl_noc_s3_systop();
    if (err != 0) {
        return err;
    }

    err = noc_s3_post_init();
    if (err != 0) {
        return err;
    }

    return 0;
}
#endif

#ifdef RD_PERIPH_NOC_S3
/*
 * Programs the Peripheral NoC S3.
 */
static int noc_s3_periph_init(void)
{
    int err;

    err = noc_s3_pre_init(host_system_data.info.chip_ap_phys_base +
                            HOST_PERIPH_NOC_S3_PHYS_BASE);
    if (err != 0) {
        return err;
    }

    PERIPH_NOC_S3_DEV.chip_addr_offset =
        host_system_data.info.chip_ap_phys_base;
    err = program_periph_noc_s3();
    if (err != 0) {
        return err;
    }

    err = noc_s3_post_init();
    if (err != 0) {
        return err;
    }

    return 0;
}

/*
 * Programs the Peripheral NoC S3 for ram_axim AP_BL1_RO region.
 */
static int32_t noc_s3_periph_init_ap_bl1_post_load(void)
{
    int32_t err;

    err = noc_s3_pre_init(host_system_data.info.chip_ap_phys_base +
                            HOST_PERIPH_NOC_S3_PHYS_BASE);
    if (err != 0) {
        return err;
    }

    PERIPH_NOC_S3_DEV.chip_addr_offset =
        host_system_data.info.chip_ap_phys_base;
    err = program_periph_noc_s3_post_ap_bl1_load();
    if (err != 0) {
        return err;
    }

    err = noc_s3_post_init();
    if (err != 0) {
        return err;
    }

    return 0;
}
#endif

#ifdef HOST_SMMU
/*
 * Initialize and bypass Granule Protection Check (GPC) to allow RSE and SCP
 * to access HOST AP peripheral regions.
 */
static int32_t sysctrl_smmu_init(void)
{
    enum atu_error_t atu_err;
    enum smmu_error_t smmu_err;

    atu_err = atu_rse_map_addr_to_log_addr(&ATU_DEV_S,
                                           host_system_data.info.chip_ap_phys_base + HOST_SYSCTRL_SMMU_PHYS_BASE,
                                           HOST_SYSCTRL_SMMU_BASE,
                                           HOST_SYSCTRL_SMMU_SIZE,
                                           ATU_ENCODE_ATTRIBUTES_SECURE_PAS |
                                           ATU_ROBA_SET_1 << ATU_ATUROBA_AXNSE_OFF |
                                           ATU_ROBA_SET_0 << ATU_ATUROBA_AXPROT1_OFF);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    /* Disable GPC */
    smmu_err = smmu_gpc_disable(&HOST_SYSCTRL_SMMU_DEV);
    if (smmu_err != SMMU_ERR_NONE){
        return -1;
    }

    /* Allow Access via SMMU */
    smmu_err = smmu_access_enable(&HOST_SYSCTRL_SMMU_DEV);
    if (smmu_err != SMMU_ERR_NONE){
        return -1;
    }

    atu_err = atu_rse_free_addr(&ATU_DEV_S, HOST_SYSCTRL_SMMU_BASE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }
    return 0;
}
#endif

/* Read Chip ID from OTP */
static int read_chip_id(uint32_t *chip_id)
{
    int err;
    uint32_t otp_chip_id;

    err = rse_get_rse_id(&otp_chip_id);
    if (err != 0)
        return err;

    *chip_id = otp_chip_id;
    return 0;
}

/* Initialize host system by collecting fixed data about the host system */
int host_system_init(void)
{
    int res;

    res = read_chip_id(&host_system_data.info.chip_id);
    if (res != 0) {
        host_system_data.info.chip_id = 0;
        return res;
    }
    host_system_data.info.chip_ap_phys_base =
                    HOST_AP_CHIP_N_PHYS_BASE(host_system_data.info.chip_id);

    host_system_data.initialized = true;
    return 0;
}

/* Get info struct containing fixed data about the host system */
int host_system_get_info(struct host_system_info_t **info)
{
    if (info == NULL) {
        return -1;
    }

    if (host_system_data.initialized == false) {
        return -1;
    }

    *info = &host_system_data.info;
    return 0;
}

int host_system_prepare_mscp_access(void)
{
#ifdef RD_SYSCTRL_NOC_S3
    int res;

    /* Configure System Control NoC S3 for nodes under AON power domain */
    res = noc_s3_sysctrl_aon_init();
    if (res != 0) {
        return res;
    }
#endif
    return 0;
}

int host_system_prepare_ap_access(void)
{
    int res;

    (void)res;

    /*
     * AP cannot be accessed until SCP setup is complete so wait for signal
     * from SCP.
     */
    while (host_system_data.status.scp_systop_ready == false) {
        __WFE();
    }

#ifdef RD_SYSCTRL_NOC_S3
    /* Configure System Control NoC S3 for nodes under SYSTOP power domain */
    res = noc_s3_sysctrl_systop_init();
    if (res != 0) {
        return 1;
    }
#endif

#ifdef HOST_SMMU
    /* Initialize the SYSCTRL SMMU for boot time */
    res = sysctrl_smmu_init();
    if (res != 0) {
        return 1;
    }
#endif

#ifdef RD_PERIPH_NOC_S3
    /* Configure Peripheral NoC S3 */
    res = noc_s3_periph_init();
    if (res != 0) {
        return 1;
    }
#endif

    return 0;
}

void host_system_scp_signal_ap_ready(void)
{
    host_system_data.status.scp_systop_ready = true;
}

int host_system_finish(void)
{
    int res;

    (void)res;

#ifdef RD_PERIPH_NOC_S3
    /* Limit AP BL1 load region to read-only and lock the APU region */
    res = noc_s3_periph_init_ap_bl1_post_load();
    if (res != 0) {
        return 1;
    }
#endif

    return 0;
}
