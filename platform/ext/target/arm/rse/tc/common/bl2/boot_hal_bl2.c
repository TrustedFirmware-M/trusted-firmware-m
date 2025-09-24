/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "boot_hal.h"

#include <string.h>

#ifdef PLATFORM_HAS_BOOT_DMA
#include "boot_dma.h"
#endif /* PLATFORM_HAS_BOOT_DMA */
#include "flash_layout.h"
#include "bootutil/bootutil_log.h"
#include "bootutil/bootutil.h"
#include "device_definition.h"
#include "host_base_address.h"
#include "platform_base_address.h"
#include "platform_error_codes.h"
#include "platform_regs.h"
#include "host_device_definition.h"
#include "rse_platform_defs.h"

#ifdef CRYPTO_HW_ACCELERATOR
#include "crypto_hw.h"
#endif /* CRYPTO_HW_ACCELERATOR */
#include "fih.h"
#include "bl2_image_id.h"
#include "Driver_Flash.h"
#include "host_flash_atu.h"
#include "atu_config.h"
#include "atu_rse_lib.h"
#include "sic_boot.h"
#include "plat_def_fip_uuid.h"
#include "flash_map/flash_map.h"
#include "mhu.h"
#include "rse_sam_config.h"

#ifdef RSE_BL2_ENABLE_IMAGE_STAGING
#include "staged_boot.h"
#endif /* RSE_BL2_ENABLE_IMAGE_STAGING */

#ifdef FLASH_DEV_NAME
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;
#endif /* FLASH_DEV_NAME */

extern struct boot_rsp rsp;
extern struct flash_area flash_map[];
extern const int flash_map_entry_num;

#ifdef RSE_USE_SDS_LIB
static int clear_ap_sds_region(void)
{
    enum atu_error_t err;
    uint32_t log_addr;
    uint32_t size;

    err = atu_rse_map_addr_automatically(&ATU_DEV_S, PLAT_RSE_AP_SDS_ATU_MAPPING_BASE,
                                         PLAT_RSE_AP_SDS_ATU_MAPPING_SIZE,
                                         ATU_ENCODE_ATTRIBUTES_SECURE_PAS, &log_addr, &size);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    memset((void *)(log_addr +
            (PLAT_RSE_AP_SDS_BASE - PLAT_RSE_AP_SDS_ATU_MAPPING_BASE)),
            0, PLAT_RSE_AP_SDS_SIZE);

    err = atu_rse_free_addr(&ATU_DEV_S, log_addr);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    return 0;
}
#endif

int32_t boot_platform_post_init(void)
{
    enum mhu_error_t status;
#ifdef PLATFORM_HAS_BOOT_DMA
    enum tfm_plat_err_t plat_err;
#endif /* PLATFORM_HAS_BOOT_DMA */
    int32_t result;
    enum atu_error_t atu_err;

    result = rse_sam_init(RSE_SAM_INIT_SETUP_FULL);
    if (result != 0) {
        return result;
    }

#ifdef CRYPTO_HW_ACCELERATOR
    result = crypto_hw_accelerator_init();
    if (result) {
        return 1;
    }

    fih_delay_init();
#endif /* CRYPTO_HW_ACCELERATOR */

    status = mhu_init_receiver(&MHU_SCP_TO_RSE_DEV);
    if (status != MHU_ERR_NONE) {
        BOOT_LOG_ERR("SCP->RSE MHU driver initialization failed");
        return 1;
    }
    BOOT_LOG_INF("SCP->RSE MHU driver initialized successfully");

    status = mhu_init_sender(&MHU_RSE_TO_SCP_DEV);
    if (status != MHU_ERR_NONE) {
        BOOT_LOG_ERR("RSE->SCP MHU driver initialization failed");
        return 1;
    }
    BOOT_LOG_INF("RSE->SCP MHU driver initialized successfully");

#ifdef PLATFORM_HAS_BOOT_DMA
    plat_err = boot_dma_init_cfg();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        BOOT_LOG_ERR("DMA driver initialization failed: ", plat_err);
        return 1;
    }
    BOOT_LOG_INF("DMA350 driver initialized successfully.");
#endif /* PLATFORM_HAS_BOOT_DMA */

#ifdef RSE_XIP
    result = sic_boot_init();
    if (result) {
        return result;
    }
#endif /* RSE_XIP */

    atu_err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static, atu_stat_count);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("Failed to initialize ATU");
        return 1;
    }

#ifdef RSE_USE_SDS_LIB
    result = clear_ap_sds_region();
    if (result) {
        return result;
    }
#endif /* RSE_USE_SDS_LIB */

#ifdef RSE_BL2_ENABLE_IMAGE_STAGING
    result = run_staged_boot();
    if (result) {
        BOOT_LOG_ERR("Staged boot init failed: %d", result);
        return result;
    }
#endif /* RSE_BL2_ENABLE_IMAGE_STAGING */

    return 0;
}

static struct flash_area *flash_map_slot_from_flash_area_id(uint32_t area_id)
{
    uint32_t idx;
    for (idx = 0; idx < flash_map_entry_num; idx++) {
        if (area_id == flash_map[idx].fa_id) {
            return &flash_map[idx];
        }
    }
    return NULL;
}

int boot_platform_pre_load(uint32_t image_id)
{
    uuid_t uuid;
    uint64_t image_load_phy_addr = 0;
    uint32_t image_load_logical_addr = 0;
    uint32_t image_max_size = 0;
    uint64_t header_phy_addr = 0;
    uint32_t offsets[2];
    struct flash_area *flash_area_primary =
        flash_map_slot_from_flash_area_id(FLASH_AREA_IMAGE_PRIMARY(image_id));
    struct flash_area *flash_area_secondary =
        flash_map_slot_from_flash_area_id(FLASH_AREA_IMAGE_SECONDARY(image_id));
    int rc;

    fih_delay();

    if (flash_area_primary == NULL || flash_area_secondary == NULL) {
        return TFM_PLAT_ERR_PRE_LOAD_IMG_BY_BL2_FAIL;
    }

    switch(image_id) {
    case RSE_BL2_IMAGE_SCP:
        uuid = UUID_RSE_FIRMWARE_SCP_BL1;

        image_load_phy_addr = SCP_BOOT_SRAM_BASE;
        image_max_size = SCP_BOOT_SRAM_SIZE;
        header_phy_addr = SCP_BOOT_SRAM_BASE + SCP_BOOT_SRAM_SIZE
                                        - HOST_IMAGE_HEADER_SIZE;
        image_load_logical_addr = HOST_BOOT_IMAGE1_LOAD_BASE_S;
        host_flash_atu_setup_image_output_slots(image_load_phy_addr,
                                                image_load_logical_addr,
                                                image_max_size,
                                                header_phy_addr);
        break;
    case RSE_BL2_IMAGE_AP:
        uuid = UUID_RSE_FIRMWARE_AP_BL1;

        image_load_phy_addr = AP_BOOT_SRAM_BASE;
        image_max_size = AP_BOOT_SRAM_SIZE;
        header_phy_addr = AP_BOOT_SRAM_BASE + AP_BOOT_SRAM_SIZE
                                        - HOST_IMAGE_HEADER_SIZE;
        image_load_logical_addr = HOST_BOOT_IMAGE0_LOAD_BASE_S;
        host_flash_atu_setup_image_output_slots(image_load_phy_addr,
                                                image_load_logical_addr,
                                                image_max_size,
                                                header_phy_addr);
        break;
    case RSE_BL2_IMAGE_NS:
        /*
         * The IMAGE_NS's output slot can be accessed without ATU so the
         * host_flash_atu_setup_image_output_slots doesn't have to be called.
         */
#ifndef RSE_XIP
        uuid = UUID_RSE_FIRMWARE_NS;
#else
        uuid = UUID_RSE_SIC_TABLES_NS;
#endif /* RSE_XIP */
        break;
    case RSE_BL2_IMAGE_S:
        /*
         * The IMAGE_S's output slot can be accessed without ATU so the
         * host_flash_atu_setup_image_output_slots doesn't have to be called.
         */
#ifndef RSE_XIP
        uuid = UUID_RSE_FIRMWARE_S;
#else
        uuid = UUID_RSE_SIC_TABLES_S;
#endif /* RSE_XIP */
        break;
    default:
        return TFM_PLAT_ERR_PRE_LOAD_IMG_BY_BL2_FAIL;
    }

    rc = host_flash_atu_setup_image_input_slots(uuid, offsets);
    if (rc) {
        return TFM_PLAT_ERR_PRE_LOAD_IMG_BY_BL2_FAIL;
    }

    flash_area_primary->fa_off += offsets[0];
    flash_area_secondary->fa_off += offsets[1];

    return 0;
}

static int tc_scp_release_reset(void)
{
    struct rse_sysctrl_t *sysctrl;
    int err;
    uint32_t log_addr;
    uint32_t size;

    err = atu_rse_map_addr_automatically(&ATU_DEV_S, SCP_SYSTEM_CONTROL_REGS_PHYS_BASE,
                                         SCP_SYSTEM_CONTROL_REGS_SIZE,
                                         ATU_ENCODE_ATTRIBUTES_SECURE_PAS, &log_addr, &size);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    /* SCP SSE-310 System Control Block same as RSE System Control
     * Registers */
    sysctrl = (struct rse_sysctrl_t *)(log_addr +
        SCP_SYSTEM_CONTROL_BLOCK_OFFSET);
    sysctrl->cpuwait = 0;

    err = atu_rse_free_addr(&ATU_DEV_S, log_addr);
    if (err != ATU_ERR_NONE) {
        return err;
    }

    return 0;
}

int boot_platform_post_load(uint32_t image_id)
{
    int err;

#ifdef RSE_XIP
    if (sic_boot_post_load(image_id, rsp.br_image_off) != SIC_BOOT_SUCCESS) {
        return TFM_PLAT_ERR_POST_LOAD_IMG_BY_BL2_FAIL;
    }
#endif /* RSE_XIP */

#ifndef TC_NO_RELEASE_RESET
    if (image_id == RSE_BL2_IMAGE_SCP) {
        memset((void *)HOST_BOOT_IMAGE1_LOAD_BASE_S, 0, HOST_IMAGE_HEADER_SIZE);

        err = tc_scp_release_reset();
        if (err) {
            return err;
        }

        /* Wait for SCP to finish its startup */
        BOOT_LOG_INF("Waiting for SCP BL1 started event");
        err = wait_for_signal_and_clear(&MHU_SCP_TO_RSE_DEV, MHU_PBX_DBCH_FLAG_SCP_COMMS);
        if (err) {
            return TFM_PLAT_ERR_POST_LOAD_IMG_BY_BL2_FAIL;
        }
        BOOT_LOG_INF("Got SCP BL1 started event");

        err = atu_rse_free_addr(&ATU_DEV_S, HOST_BOOT_IMAGE1_LOAD_BASE_S);
        if (err != ATU_ERR_NONE) {
            return err;
        }

        err = atu_rse_free_addr(&ATU_DEV_S, HOST_BOOT_IMAGE1_LOAD_BASE_S + HOST_IMAGE_HEADER_SIZE);
        if (err != ATU_ERR_NONE) {
            return err;
        }

    } else if (image_id == RSE_BL2_IMAGE_AP) {
        memset((void *)HOST_BOOT_IMAGE0_LOAD_BASE_S, 0, HOST_IMAGE_HEADER_SIZE);
        BOOT_LOG_INF("Telling SCP to start AP cores");
        err = signal_and_wait_for_clear(&MHU_RSE_TO_SCP_DEV, MHU_PBX_DBCH_FLAG_SCP_COMMS);
        if (err) {
            return TFM_PLAT_ERR_POST_LOAD_IMG_BY_BL2_FAIL;
        }
        BOOT_LOG_INF("Sent the signal to SCP");

        err = atu_rse_free_addr(&ATU_DEV_S, HOST_BOOT_IMAGE0_LOAD_BASE_S);
        if (err != ATU_ERR_NONE) {
            return err;
        }

        err = atu_rse_free_addr(&ATU_DEV_S, HOST_BOOT_IMAGE0_LOAD_BASE_S + HOST_IMAGE_HEADER_SIZE);
        if (err != ATU_ERR_NONE) {
            return err;
        }
    }
#else
    BOOT_LOG_INF("Skipping SCP signaling as TC_NO_RELEASE_RESET is defined");
#endif /* TC_NO_RELEASE_RESET */


    err = host_flash_atu_free_input_image_regions();
    if (err) {
        return TFM_PLAT_ERR_POST_LOAD_IMG_BY_BL2_FAIL;
    }

    return 0;
}

bool boot_platform_should_load_image(uint32_t image_id)
{
#ifndef TFM_LOAD_NS_IMAGE
    if (image_id == RSE_BL2_IMAGE_NS) {
        return false;
    }
#endif /* TFM_LOAD_NS_IMAGE */

    return true;
}

#ifdef RSE_GPT_SUPPORT
int boot_initiate_recovery_mode(uint32_t image_id)
{
    (void)image_id;

    /* Mark as failed boot attempt and reboot */
    tfm_hal_system_reset(RSE_SWSYN_FAILED_BOOT_MASK);

    return 0;
}

void boot_platform_error_state(uint32_t error)
{
    if ((error == TFM_PLAT_ERR_PRE_LOAD_IMG_BY_BL2_FAIL) ||
        (error == TFM_PLAT_ERR_POST_LOAD_IMG_BY_BL2_FAIL)) {

        /* Initiate recovery mode. Argument image_id is not applicable
         * as it is ignored in boot_initiate_recovery_mode()
         */
        boot_initiate_recovery_mode(0);
    }

    FIH_PANIC;
}
#endif /* RSE_GPT_SUPPORT */

void boot_platform_start_next_image(struct boot_arm_vector_table *vt)
{
    /* Clang at O0, stores variables on the stack with SP relative addressing.
     * When manually set the SP then the place of reset vector is lost.
     * Static variables are stored in 'data' or 'bss' section, change of SP has
     * no effect on them.
     */
    static struct boot_arm_vector_table *vt_cpy;
    int32_t result;

    vt_cpy = vt;

#ifdef RSE_XIP
    if (sic_boot_pre_quit(&vt_cpy) != SIC_BOOT_SUCCESS) {
        FIH_PANIC;
    }
#endif /* RSE_XIP */

#ifdef CRYPTO_HW_ACCELERATOR
    result = crypto_hw_accelerator_finish();
    if (result) {
        while(1){}
    }
#endif /* CRYPTO_HW_ACCELERATOR */

#ifdef FLASH_DEV_NAME
    result = FLASH_DEV_NAME.Uninitialize();
    if (result != ARM_DRIVER_OK) {
        while(1){}
    }
#endif /* FLASH_DEV_NAME */
#ifdef FLASH_DEV_NAME_2
    result = FLASH_DEV_NAME_2.Uninitialize();
    if (result != ARM_DRIVER_OK) {
        while(1){}
    }
#endif /* FLASH_DEV_NAME_2 */
#ifdef FLASH_DEV_NAME_3
    result = FLASH_DEV_NAME_3.Uninitialize();
    if (result != ARM_DRIVER_OK) {
        while(1){}
    }
#endif /* FLASH_DEV_NAME_3 */
#ifdef FLASH_DEV_NAME_SCRATCH
    result = FLASH_DEV_NAME_SCRATCH.Uninitialize();
    if (result != ARM_DRIVER_OK) {
        while(1){}
    }
#endif /* FLASH_DEV_NAME_SCRATCH */

    rse_sam_finish();

    fih_delay();

#if defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
 || defined(__ARM_ARCH_8_1M_MAIN__)
    /* Restore the Main Stack Pointer Limit register's reset value
     * before passing execution to runtime firmware to make the
     * bootloader transparent to it.
     */
    __set_MSPLIM(0);
#endif /* defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
       || defined(__ARM_ARCH_8_1M_MAIN__) */

    __set_MSP(vt_cpy->msp);
    __DSB();
    __ISB();

    boot_jump_to_next_image(vt_cpy->reset);
}
