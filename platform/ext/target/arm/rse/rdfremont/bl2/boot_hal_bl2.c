/*
 * Copyright (c) 2023-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "boot_hal.h"

#include <string.h>

#include "bootutil/bootutil.h"
#include "bootutil/bootutil_log.h"
#include "device_definition.h"
#include "flash_map/flash_map.h"
#include "host_base_address.h"
#include "ni_tower_lib.h"
#include "platform_base_address.h"
#include "platform_regs.h"
#include "rse_expansion_regs.h"
#include "size_defs.h"

#ifdef CRYPTO_HW_ACCELERATOR
#include "crypto_hw.h"
#include "fih.h"
#endif /* CRYPTO_HW_ACCELERATOR */

/*
 * Initializes the ATU region before configuring the NI-Tower. This function
 * maps the physical base address of the NI-Tower instance received as the
 * parameter to a logical address HOST_NI_TOWER_BASE.
 */
static int32_t ni_tower_pre_init(uint64_t ni_tower_phys_address)
{
    enum atu_error_t atu_err;
    enum atu_roba_t roba_value;

    atu_err = atu_initialize_region(
                &ATU_DEV_S,
                HOST_NI_TOWER_ATU_ID,
                HOST_NI_TOWER_BASE,
                ni_tower_phys_address,
                HOST_NI_TOWER_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    roba_value = ATU_ROBA_SET_1;
    atu_err = set_axnsc(&ATU_DEV_S, roba_value, HOST_NI_TOWER_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: Unable to modify AxNSE");
        return -1;
    }

    roba_value = ATU_ROBA_SET_0;
    atu_err = set_axprot1(&ATU_DEV_S, roba_value, HOST_NI_TOWER_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: Unable to modify AxPROT1");
        return -1;
    }

    return 0;
}

/* Un-initializes the ATU region after configuring the NI-Tower */
static int32_t ni_tower_post_init(void)
{
    enum atu_error_t atu_err;

    atu_err = atu_uninitialize_region(&ATU_DEV_S, HOST_NI_TOWER_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    return 0;
}

/*
 * Programs the System control NI-Tower for nodes under Always-On (AON) domain.
 */
static int32_t ni_tower_sysctrl_aon_init(void)
{
    int32_t err;

    err = ni_tower_pre_init(HOST_SYSCTRL_NI_TOWER_PHYS_BASE);
    if (err != 0) {
        return err;
    }

    err = program_sysctrl_ni_tower_aon();
    if (err != 0) {
        BOOT_LOG_ERR("BL2: Unable to configure System Control NI-Tower for "
                        "nodes under AON domain");
        return err;
    }

    err = ni_tower_post_init();
    if (err != 0) {
        return err;
    }

    BOOT_LOG_INF("BL2: System Control NI-Tower configured for node under AON "
                    "domain");

    return 0;
}

/*
 * Programs the System control NI-Tower for nodes under SYSTOP domain.
 */
static int32_t ni_tower_sysctrl_systop_init(void)
{
    int32_t err;

    err = ni_tower_pre_init(HOST_SYSCTRL_NI_TOWER_PHYS_BASE);
    if (err != 0) {
        return err;
    }

    err = program_sysctrl_ni_tower_systop();
    if (err != 0) {
        BOOT_LOG_ERR("BL2: Unable to configure System Control NI-Tower for "
                        "nodes under SYSTOP domain");
        return err;
    }

    err = ni_tower_post_init();
    if (err != 0) {
        return err;
    }

    BOOT_LOG_INF("BL2: System Control NI-Tower configured for node under "
                    "SYSTOP domain");

    return 0;
}

int32_t boot_platform_post_init(void)
{
    int32_t result;

    result = ni_tower_sysctrl_aon_init();
    if (result != 0) {
        return result;
    }

#ifdef CRYPTO_HW_ACCELERATOR
    result = crypto_hw_accelerator_init();
    if (result) {
        return 1;
    }

    (void)fih_delay_init();
#endif /* CRYPTO_HW_ACCELERATOR */

    return 0;
}

/*
 * ================================ Secure ====================================
 */

static int boot_platform_pre_load_secure(void)
{
    return 0;
}

static int boot_platform_post_load_secure(void)
{
    return 0;
}

/*
 * ============================ Non-Secure ====================================
 */

static int boot_platform_pre_load_non_secure(void)
{
    return 0;
}

static int boot_platform_post_load_non_secure(void)
{
    return 0;
}

/*
 * =================================== SCP ====================================
 */

/* Fuction called before SCP firmware is loaded. */
static int boot_platform_pre_load_scp(void)
{
    enum atu_error_t atu_err;

    BOOT_LOG_INF("BL2: SCP pre load start");

    /* Configure ATUs for loading to areas not directly addressable by RSE. */

    /*
     * Configure RSE ATU to access header region for SCP. The header part of
     * the image is loaded at the end of the ITCM to allow the code part of the
     * image to be placed at the start of the ITCM. For this, setup a separate
     * ATU region for the image header.
     */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_HDR_LOAD_ID,
                                    HOST_SCP_HDR_ATU_WINDOW_BASE_S,
                                    HOST_SCP_HDR_PHYS_BASE,
                                    RSE_IMG_HDR_ATU_WINDOW_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access SCP ITCM region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_CODE_LOAD_ID,
                                    HOST_SCP_IMG_CODE_BASE_S,
                                    HOST_SCP_PHYS_BASE,
                                    HOST_SCP_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    BOOT_LOG_INF("BL2: SCP pre load complete");

    return 0;
}

/* Fuction called after SCP firmware is loaded. */
static int boot_platform_post_load_scp(void)
{
    enum atu_error_t atu_err;
    struct rse_integ_t *integ_layer =
            (struct rse_integ_t *)RSE_INTEG_LAYER_BASE_S;
    enum mscp_error_t mscp_err;
    int32_t err;

    BOOT_LOG_INF("BL2: SCP post load start");

    /*
     * Since the measurement are taken at this point, clear the image header
     * part in the ITCM before releasing SCP out of reset.
     */
    memset(HOST_SCP_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    /* Enable SCP's ATU Access Permission (ATU AP) */
    integ_layer->atu_ap |= RSE_INTEG_ATU_AP_SCP_ATU;

    /* Configure RSE ATU to access SCP INIT_CTRL region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    HOST_SCP_INIT_CTRL_ATU_ID,
                                    HOST_SCP_INIT_CTRL_BASE_S,
                                    HOST_SCP_INIT_CTRL_PHYS_BASE,
                                    HOST_SCP_INIT_CTRL_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    mscp_err = mscp_driver_release_cpu(&HOST_SCP_DEV);
    if (mscp_err != MSCP_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SCP release failed");
        return 1;
    }
    BOOT_LOG_INF("BL2: SCP is released out of reset");

    /* Close RSE ATU region configured to access SCP INIT_CTRL region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, HOST_SCP_INIT_CTRL_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access RSE header region for SCP */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access SCP ITCM region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure System Control NI-Tower for nodes under SYSTOP power domain */
    err = ni_tower_sysctrl_systop_init();
    if (err != 0) {
        return 1;
    }

    BOOT_LOG_INF("BL2: SCP post load complete");

    return 0;
}

/*
 * =================================== MCP ====================================
 */

/* Fuction called before MCP firmware is loaded. */
static int boot_platform_pre_load_mcp(void)
{
    enum atu_error_t atu_err;

    BOOT_LOG_INF("BL2: MCP pre load start");

    /* Configure ATUs for loading to areas not directly addressable by RSE. */

    /*
     * Configure RSE ATU to access header region for MCP. The header part of
     * the image is loaded at the end of the ITCM to allow the code part of the
     * image to be placed at the start of the ITCM. For this, setup a separate
     * ATU region for the image header.
     */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_HDR_LOAD_ID,
                                    HOST_MCP_HDR_ATU_WINDOW_BASE_S,
                                    HOST_MCP_HDR_PHYS_BASE,
                                    RSE_IMG_HDR_ATU_WINDOW_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access MCP ITCM region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_CODE_LOAD_ID,
                                    HOST_MCP_IMG_CODE_BASE_S,
                                    HOST_MCP_PHYS_BASE,
                                    HOST_MCP_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    BOOT_LOG_INF("BL2: MCP pre load complete");

    return 0;
}

/* Fuction called after MCP firmware is loaded. */
static int boot_platform_post_load_mcp(void)
{
    enum atu_error_t atu_err;
    enum mscp_error_t mscp_err;

    BOOT_LOG_INF("BL2: MCP post load start");

    /*
     * Since the measurement are taken at this point, clear the image header
     * part in the ITCM before releasing MCP out of reset.
     */
    memset(HOST_MCP_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    /* Configure RSE ATU to access MCP INIT_CTRL region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    HOST_MCP_INIT_CTRL_ATU_ID,
                                    HOST_MCP_INIT_CTRL_BASE_S,
                                    HOST_MCP_INIT_CTRL_PHYS_BASE,
                                    HOST_MCP_INIT_CTRL_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    mscp_err = mscp_driver_release_cpu(&HOST_MCP_DEV);
    if (mscp_err != MSCP_ERR_NONE) {
        BOOT_LOG_ERR("BL2: MCP release failed");
        return 1;
    }
    BOOT_LOG_INF("BL2: MCP is released out of reset");

    /* Close RSE ATU region configured to access MCP INIT_CTRL region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, HOST_MCP_INIT_CTRL_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access RSE header region for MCP */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access MCP ITCM region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    BOOT_LOG_INF("BL2: MCP post load complete");

    return 0;
}

/*
 * =================================== LCP ====================================
 */

/* Fuction called before LCP firmware is loaded. */
static int boot_platform_pre_load_lcp(void)
{
    enum atu_error_t atu_err;

    BOOT_LOG_INF("BL2: LCP pre load start");

    /* Configure ATUs for loading to areas not directly addressable by RSE. */

    /*
     * Configure RSE ATU to access header region for LCP0. The header part of
     * the image is loaded at the end of the ITCM to allow the code part of the
     * image to be placed at the start of the ITCM. For this, setup a separate
     * ATU region for the image header.
     */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_HDR_LOAD_ID,
                                    HOST_LCP_HDR_ATU_WINDOW_BASE_S,
                                    HOST_LCP_0_PHYS_HDR_BASE,
                                    RSE_IMG_HDR_ATU_WINDOW_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: ATU could not init LCP header load region");
        return 1;
    }

    /*
     * Configure RSE ATU region to access the Cluster utility space.
     */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_CODE_LOAD_ID,
                                    HOST_LCP_IMG_CODE_BASE_S,
                                    HOST_LCP_0_PHYS_BASE,
                                    HOST_LCP_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: ATU could not init LCP code load region");
        return 1;
    }

    BOOT_LOG_INF("BL2: LCP pre load complete");

    return 0;
}

/* Fuction called after LCP firmware is loaded. */
static int boot_platform_post_load_lcp(void)
{
    enum atu_error_t atu_err;
    struct boot_rsp rsp;
    int lcp_idx;
    fih_ret fih_rc = FIH_FAILURE;
    fih_ret recovery_succeeded = FIH_FAILURE;

    BOOT_LOG_INF("BL2: LCP post load start");

    /*
     * Since the measurement are taken at this point, clear the image header
     * part in the ITCM before releasing LCP out of reset.
     */
    memset(HOST_LCP_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    /* Close RSE ATU region configured to access LCP ITCM region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: ATU could not uninit LCP code load region");
        return 1;
    }

    /*
     * Load LCP firmware to remaining LCP devices 1 to N
     *
     * MCUBoot currently only supports loading each image to one location.
     * There are multiple LCPs that require the same image so to load the
     * firmware to the remaining LCP devices, call the MCUBoot load function
     * for each device with the ATU destination modified for each LCP.
     */
    for (lcp_idx = 1; lcp_idx < PLAT_LCP_COUNT; lcp_idx++) {
        /*
         * Configure RSE ATU region to access the Cluster utility space and map
         * to the i-th LCP's ITCM
         */
        atu_err = atu_initialize_region(&ATU_DEV_S,
                                        RSE_ATU_IMG_CODE_LOAD_ID,
                                        HOST_LCP_IMG_CODE_BASE_S,
                                        HOST_LCP_N_PHYS_BASE(lcp_idx),
                                        HOST_LCP_ATU_SIZE);
        if (atu_err != ATU_ERR_NONE) {
            BOOT_LOG_ERR("BL2: ATU could not init LCP code load region");
            return 1;
        }

        do {
            /*
             * Cleaning 'rsp' to avoid accidentally loading
             * the NS image in case of a fault injection attack.
             */
            memset(&rsp, 0, sizeof(struct boot_rsp));

            FIH_CALL(boot_go_for_image_id, fih_rc, &rsp, RSE_FIRMWARE_LCP_ID);

            if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
                BOOT_LOG_ERR("BL2: Unable to find bootable LCP image");

                recovery_succeeded = fih_ret_encode_zero_equality(
                            boot_initiate_recovery_mode(RSE_FIRMWARE_LCP_ID));
                if (FIH_NOT_EQ(recovery_succeeded, FIH_SUCCESS)) {
                    FIH_PANIC;
                }
            }
        } while FIH_NOT_EQ(fih_rc, FIH_SUCCESS);

        /*
         * Since the measurement are taken at this point, clear the image
         * header part in the ITCM before releasing LCP out of reset.
         */
        memset(HOST_LCP_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

        /* Close RSE ATU region configured to access LCP ITCM region */
        atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
        if (atu_err != ATU_ERR_NONE) {
            BOOT_LOG_ERR("BL2: ATU could not uninit LCP code load region");
            return 1;
        }
    }

    /* Close RSE ATU region configured to access RSE header region for LCP */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: ATU could not uninit LCP header load region");
        return 1;
    }

    BOOT_LOG_INF("BL2: LCP post load complete");

    return 0;
}

/*
 * ================================= VECTORS ==================================
 */

/*
 * Array of function pointers to call before each image is loaded indexed by
 * image id
 */
static int (*boot_platform_pre_load_vector[RSE_FIRMWARE_COUNT]) (void) = {
    [RSE_FIRMWARE_SECURE_ID]        = boot_platform_pre_load_secure,
#ifdef RSE_LOAD_NS_IMAGE
    [RSE_FIRMWARE_NON_SECURE_ID]    = boot_platform_pre_load_non_secure,
#endif /* RSE_LOAD_NS_IMAGE */
    [RSE_FIRMWARE_SCP_ID]           = boot_platform_pre_load_scp,
    [RSE_FIRMWARE_MCP_ID]           = boot_platform_pre_load_mcp,
    [RSE_FIRMWARE_LCP_ID]           = boot_platform_pre_load_lcp,
};

/*
 * Array of function pointers to call after each image is loaded indexed by
 * image id
 */
static int (*boot_platform_post_load_vector[RSE_FIRMWARE_COUNT]) (void) = {
    [RSE_FIRMWARE_SECURE_ID]        = boot_platform_post_load_secure,
#ifdef RSE_LOAD_NS_IMAGE
    [RSE_FIRMWARE_NON_SECURE_ID]    = boot_platform_post_load_non_secure,
#endif /* RSE_LOAD_NS_IMAGE */
    [RSE_FIRMWARE_SCP_ID]           = boot_platform_post_load_scp,
    [RSE_FIRMWARE_MCP_ID]           = boot_platform_post_load_mcp,
    [RSE_FIRMWARE_LCP_ID]           = boot_platform_post_load_lcp,
};

/*
 * ============================== LOAD FUNCTIONS ==============================
 */

int boot_platform_pre_load(uint32_t image_id)
{
    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: no pre load for image %d", image_id);
        return 0;
    }

    return boot_platform_pre_load_vector[image_id]();
}

int boot_platform_post_load(uint32_t image_id)
{
    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: no post load for image %d", image_id);
        return 0;
    }

    return boot_platform_post_load_vector[image_id]();
}

bool boot_platform_should_load_image(uint32_t image_id)
{
#ifndef RSE_LOAD_NS_IMAGE
    if (image_id == RSE_FIRMWARE_NON_SECURE_ID) {
        return false;
    }
#endif /* RSE_LOAD_NS_IMAGE */

    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: Image %d beyond expected Firmware count: %d",
                image_id, RSE_FIRMWARE_COUNT);
        return false;
    }

    return true;
}
