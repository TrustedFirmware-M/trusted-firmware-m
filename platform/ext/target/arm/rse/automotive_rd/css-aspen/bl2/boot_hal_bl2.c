/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "atu_config.h"
#include "atu_rse_lib.h"
#include "bl2_image_id.h"
#include "boot_hal.h"
#include "bootutil/bootutil_log.h"
#include "crypto_hw.h"
#include "device_definition.h"
#include "fih.h"
#include "fip_parser.h"
#include "flash_layout.h"
#include "flash_map/flash_map.h"
#include "host_base_address.h"
#include "platform_base_address.h"
#include "platform_regs.h"
#include "tfm_plat_defs.h"

#include <string.h>

extern struct flash_area flash_map[];
extern const int flash_map_entry_num;
extern ARM_DRIVER_FLASH AP_FLASH_DEV_NAME;

static int32_t fill_secure_flash_map_with_data(void)
{
    uint64_t tfa_offset = 0;
    size_t tfa_size = 0;
    enum tfm_plat_err_t result;
    uint8_t i, id, flash_id;

    result = fip_get_entry_by_uuid(&AP_FLASH_DEV_NAME,
                AP_FLASH_FIP_OFFSET, AP_FLASH_FIP_SIZE,
                UUID_TRUSTED_BOOT_FIRMWARE_BL2, &tfa_offset, &tfa_size);
    if (result != TFM_PLAT_ERR_SUCCESS) {
        return 1;
    }

    flash_id = FLASH_AREA_IMAGE_PRIMARY(RSE_FIRMWARE_AP_BL2_ID);

    for (i = 0; i < flash_map_entry_num; i++) {
        id = flash_map[i].fa_id;

        if (id == flash_id) {
            flash_map[i].fa_off = AP_FLASH_FIP_OFFSET + tfa_offset;
            flash_map[i].fa_size = tfa_size;
        }
    }

    return 0;
}

/*
 * ============================ INIT FUNCTIONS =================================
 */

int32_t boot_platform_post_init(void)
{
    enum atu_error_t atu_err;
    int32_t result;

    atu_err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_SECURE, atu_regions_static, atu_stat_count);
    if (atu_err != ATU_ERR_NONE) {
        return result;
    }

    result = AP_FLASH_DEV_NAME.Initialize(NULL);
    if (result != 0) {
        return result;
    }

    result = crypto_hw_accelerator_init();
    if (result) {
        return 1;
    }

    (void)fih_delay_init();

    return 0;
}

static enum atu_error_t initialise_atu_regions(struct atu_dev_t *dev,
                                               uint8_t region_count,
                                               const struct atu_map *regions,
                                               const char *name)
{
    enum atu_error_t atu_err;

    for (uint8_t idx = 0; idx < region_count; idx++) {
        const struct atu_map *reg = &regions[idx];
        enum atu_roba_t axnse, axprot1;

        atu_err = atu_rse_initialize_region(dev, idx, reg->log_addr, reg->phy_addr, reg->size);
        if (atu_err != ATU_ERR_NONE) {
            BOOT_LOG_ERR("BL2: ERROR! %s ATU region %u init status: %d", name,
                         idx, (int)atu_err);
            return atu_err;
        }

        atu_err = atu_rse_set_bus_attributes(dev, idx, reg->bus_attr);
        if (atu_err != ATU_ERR_NONE) {
            BOOT_LOG_ERR("BL2: Unable to modify bus attributes for %s ATU region %u\n",
                         name, idx);
            return atu_err;
        }

        /* No support for "long long" prints, work around with more arguments */
        BOOT_LOG_INF("BL2: %s ATU region %u: [0x%lx - 0x%lx]->[0x%lx_%08lx - 0x%lx_%08lx]",
                     name, idx,
                     (unsigned long)reg->log_addr,
                     (unsigned long)(reg->log_addr + reg->size - 1),
                     (unsigned long)(reg->phy_addr >> 32),
                     (unsigned long)reg->phy_addr,
                     (unsigned long)((reg->phy_addr + reg->size - 1) >> 32),
                     (unsigned long)(reg->phy_addr + reg->size - 1));
    }

    return ATU_ERR_NONE;
}

/*
 * ========================= SECURE LOAD FUNCTIONS =============================
 */

static int boot_platform_pre_load_secure(void)
{
    BOOT_LOG_WRN("There is an known issue in RSE platform css-aspen: Internal \
        Trusted Storage (ITS) does not meet the required security expectations \
        with respect to Confidentiality, Integrity, and Rollback Protection\n");
    return 0;
}

static int boot_platform_post_load_secure(void)
{
    return 0;
}

/*
 * =========================== AP BL2 LOAD FUNCTIONS ===========================
 */

static enum atu_error_t initialize_ap_atu(void)
{
    enum atu_error_t atu_err;

    /* Configure RSE ATU to access the AP ATU */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        RSE_ATU_AP_ATU_ID,
                                        HOST_AP_ATU_BASE_S,
                                        HOST_AP_ATU_PHYS_BASE,
                                        HOST_AP_ATU_GPV_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    /* Initialize the translation regions of the AP ATU */
    atu_err = initialise_atu_regions(&HOST_AP_ATU_DEV, AP_ATU_REGION_COUNT,
                                     ap_atu_regions, "AP");
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    /* Close RSE ATU region configured to access the AP ATU */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, RSE_ATU_AP_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    return ATU_ERR_NONE;
}

/* Function called before AP BL2 firmware is loaded. */
static int boot_platform_pre_load_ap_bl2(void)
{
    enum atu_error_t atu_err;

    BOOT_LOG_INF("BL2: AP BL2 pre load start");

    /* Configure RSE ATU to access AP Secure Flash for AP BL2 */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        HOST_AP_FLASH_ATU_ID,
                                        HOST_AP_FLASH_BASE,
                                        HOST_AP_FLASH_PHY_BASE,
                                        HOST_AP_FLASH_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access RSE header region for AP BL2 */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        RSE_ATU_IMG_HDR_LOAD_ID,
                                        HOST_AP_BL2_HDR_ATU_WINDOW_BASE_S,
                                        HOST_AP_BL2_HDR_PHYS_BASE,
                                        RSE_IMG_HDR_ATU_WINDOW_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access AP BL2 Shared SRAM region */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        RSE_ATU_IMG_CODE_LOAD_ID,
                                        HOST_AP_BL2_IMG_CODE_BASE_S,
                                        HOST_AP_BL2_PHYS_BASE,
                                        HOST_AP_BL2_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    if (fill_secure_flash_map_with_data() != 0) {
        BOOT_LOG_ERR("BL2: Unable to extract AP BL2 from FIP");
        return 1;
    }

    BOOT_LOG_INF("BL2: AP BL2 pre load complete");

    return 0;
}

/* Function called after AP BL2 firmware is loaded. */
static int boot_platform_post_load_ap_bl2(void)
{
    enum atu_error_t atu_err;

    BOOT_LOG_INF("BL2: AP BL2 post load start");

    /*
     * Since the measurement are taken at this point, clear the image
     * header part in the Shared SRAM before releasing AP BL2 out of reset.
     */
    memset((void *)HOST_AP_BL2_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    /* Close RSE ATU to access AP Secure Flash for AP BL2 */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, HOST_AP_FLASH_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access RSE header region for AP BL2 */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access AP BL2 Shared SRAM region */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure the AP ATU */
    atu_err = initialize_ap_atu();
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    BOOT_LOG_INF("BL2: AP BL2 post load complete");

    return 0;
}

/*
 * =========================== SI CL0 LOAD FUNCTIONS ===========================
 */

static enum atu_error_t initialize_si_atu(void)
{
    enum atu_error_t atu_err;

    /* Configure RSE ATU to access the SI ATU */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        HOST_SI_ATU_ID,
                                        HOST_SI_ATU_BASE_S,
                                        HOST_SI_ATU_PHYS_BASE,
                                        HOST_SI_ATU_GPV_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    /* Initialize the translation regions of the SI ATU */
    atu_err = initialise_atu_regions(&HOST_SI_ATU_DEV, SI_ATU_REGION_COUNT,
                                     si_atu_regions, "SI");
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    /* Close RSE ATU region configured to access the SI ATU */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, HOST_SI_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return atu_err;
    }

    return ATU_ERR_NONE;
}

/* Function called before SI CL0 firmware is loaded. */
static int boot_platform_pre_load_si_cl0(void)
{
    enum atu_error_t atu_err;
    enum ppu_error_t ppu_err;

    BOOT_LOG_INF("BL2: SI CL0 pre load start");

    /* Configure RSE ATU to access SI PIK */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        HOST_SI_PIK_ATU_ID,
                                        HOST_SI_PIK_ATU_WINDOW_BASE_S,
                                        HOST_SI_PIK_PHYS_BASE,
                                        HOST_SI_PIK_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Power up SI power domain */
    ppu_err = ppu_driver_power_on(&HOST_SI_SYSTOP_PPU_DEV);
    if (ppu_err != PPU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SI SYSTOP release failed: %d", (int)ppu_err);
        return 1;
    }

    /* Close RSE ATU region configured to access SI PIK */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, HOST_SI_PIK_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access SI CL0 Cluster Utility Bus */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        HOST_SI_CL0_CUB_ATU_ID,
                                        HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S,
                                        HOST_SI_CL0_CUB_BASE,
                                        HOST_SI_CL0_CUB_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Power up SI CL0 */
    ppu_err = ppu_driver_power_on(&HOST_SI_CL0_CLUS_PPU_DEV);
    if (ppu_err != PPU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SI CL0 CLUS release failed: %d", (int)ppu_err);
        return 1;
    }

    /* Close RSE ATU region configured to access SI CL0 Cluster Utility Bus */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, HOST_SI_CL0_CUB_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access RSE header region for SI CL0 */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        RSE_ATU_IMG_HDR_LOAD_ID,
                                        HOST_SI_CL0_HDR_ATU_WINDOW_BASE_S,
                                        HOST_SI_CL0_HDR_PHYS_BASE,
                                        RSE_IMG_HDR_ATU_WINDOW_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access SI CL0 Shared SRAM region */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        RSE_ATU_IMG_CODE_LOAD_ID,
                                        HOST_SI_CL0_IMG_CODE_BASE_S,
                                        HOST_SI_CL0_PHYS_BASE,
                                        HOST_SI_CL0_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    BOOT_LOG_INF("BL2: SI CL0 pre load complete");

    return 0;
}

/* Function called after SI CL0 firmware is loaded. */
static int boot_platform_post_load_si_cl0(void)
{
    enum atu_error_t atu_err;
    enum ppu_error_t si_cl0_err;

    BOOT_LOG_INF("BL2: SI CL0 post load start");

    /*
     * Since the measurement are taken at this point, clear the image
     * header part in the Shared SRAM before releasing SI CL0 out of reset.
     */
    memset((void *)HOST_SI_CL0_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    /* Configure the SI ATU before starting the SI CL0 */
    atu_err = initialize_si_atu();
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Configure RSE ATU to access SI CL0 Cluster Utility Bus */
    atu_err = atu_rse_initialize_region(&ATU_DEV_S,
                                        HOST_SI_CL0_CUB_ATU_ID,
                                        HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S,
                                        HOST_SI_CL0_CUB_BASE,
                                        HOST_SI_CL0_CUB_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    si_cl0_err = ppu_driver_power_on(&HOST_SI_CL0_CORE0_PPU_DEV);
    if (si_cl0_err != PPU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SI CL0 CORE0 release failed: %d", (int)si_cl0_err);
        return 1;
    }
    BOOT_LOG_INF("BL2: SI CL0 is released out of reset");

    /* Close RSE ATU region configured to access SI CL0 Cluster Utility Bus */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, HOST_SI_CL0_CUB_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access RSE header region for SI CL0 */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    /* Close RSE ATU region configured to access SI CL0 Shared SRAM region */
    atu_err = atu_rse_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    BOOT_LOG_INF("BL2: SI CL0 post load complete");

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
    [RSE_FIRMWARE_SI_CL0_ID]        = boot_platform_pre_load_si_cl0,
    [RSE_FIRMWARE_AP_BL2_ID]        = boot_platform_pre_load_ap_bl2,
};

/*
 * Array of function pointers to call after each image is loaded indexed by
 * image id
 */
static int (*boot_platform_post_load_vector[RSE_FIRMWARE_COUNT]) (void) = {
    [RSE_FIRMWARE_SECURE_ID]        = boot_platform_post_load_secure,
    [RSE_FIRMWARE_SI_CL0_ID]        = boot_platform_post_load_si_cl0,
    [RSE_FIRMWARE_AP_BL2_ID]        = boot_platform_post_load_ap_bl2,
};

/*
 * ============================== LOAD FUNCTIONS ==============================
 */

int boot_platform_pre_load(uint32_t image_id)
{
    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: no pre load for image %u", image_id);
        return 0;
    }

    return boot_platform_pre_load_vector[image_id]();
}

int boot_platform_post_load(uint32_t image_id)
{
    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: no post load for image %u", image_id);
        return 0;
    }

    return boot_platform_post_load_vector[image_id]();
}

bool boot_platform_should_load_image(uint32_t image_id)
{
    if (image_id == RSE_FIRMWARE_NON_SECURE_ID) {
        return false;
    }

    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: Image %u beyond expected Firmware count: %d",
                image_id, RSE_FIRMWARE_COUNT);
        return false;
    }

    return true;
}
