/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "atu_config.h"
#include "atu_rse_lib.h"
#include "boot_hal.h"
#include "bootutil/bootutil_log.h"
#include "crypto_hw.h"
#include "device_definition.h"
#include "fih.h"
#include "fip_parser.h"
#include "flash_map/flash_map.h"
#include "gic_720ae_lib.h"
#include "host_base_address.h"
#include "interrupts_bl2.h"
#include "bl2_image_id.h"
#include "host_system.h"
#include "flash_layout.h"
#include "mhu_v3_x.h"
#include "noc_s3_lib.h"
#include "platform_base_address.h"
#include "platform_regs.h"
#include "rse_expansion_regs.h"
#include "tfm_plat_defs.h"
#include "rse_sam_config.h"

#include <string.h>

#define MHU_SCP_AP_READY_SIGNAL_CHANNEL 0
#define MHU_SCP_AP_READY_SIGNAL_PAYLOAD 0x1

#define MHU_SCP_SI_READY_SIGNAL_CHANNEL     2
#define MHU_SCP_SI_CL0_READY_SIGNAL_PAYLOAD 0x1
#define MHU_SCP_SI_CL1_READY_SIGNAL_PAYLOAD 0x2
#define MHU_SCP_SI_CL2_READY_SIGNAL_PAYLOAD 0x4

extern struct flash_area flash_map[];
extern const int flash_map_entry_num;
extern ARM_DRIVER_FLASH AP_FLASH_DEV_NAME;

static int32_t gic_multiple_view_init(void)
{
    enum atu_error_t atu_err;
    uint32_t err;
    uint32_t log_addr;
    uint32_t size;

    atu_err = atu_rse_map_addr_automatically(&ATU_DEV_S, HOST_SI_GIC_VIEW_0_PHYS_BASE,
                                             HOST_SI_GIC_VIEW_SIZE,
                                             ATU_ENCODE_ATTRIBUTES_SECURE_PAS, &log_addr, &size);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    err = gic_multiple_view_probe(log_addr);
    if (err != 0) {
        BOOT_LOG_ERR("BL2: Error probing GIC Multiple Views device");
        goto free_atu;
    }

    err = gic_multiple_view_programming();
    if (err != 0) {
        BOOT_LOG_ERR("BL2: Error programming GIC Multiple Views");
        goto free_atu;
    }

free_atu:
    atu_err = atu_rse_free_addr(&ATU_DEV_S, log_addr);
    if (atu_err != ATU_ERR_NONE) {
        return 1;
    }

    return err;
}

static int32_t fill_secure_flash_map_with_data(void) {
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

        if(id == flash_id) {
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
    int32_t result;
    enum atu_error_t atu_err;

    result = rse_sam_init(RSE_SAM_INIT_SETUP_FULL);
    if (result != 0) {
        return result;
    }

    atu_err = atu_rse_drv_init(&ATU_DEV_S, ATU_DOMAIN_ROOT, atu_regions_static, atu_stat_count);
    if (atu_err != ATU_ERR_NONE) {
            return result;
    }

    result = AP_FLASH_DEV_NAME.Initialize(NULL);
    if (result != 0) {
        return result;
    }

    result = interrupts_bl2_init();
    if (result != 0) {
        return result;
    }

    result = crypto_hw_accelerator_init();
    if (result) {
        return 1;
    }

    fih_delay_init();

    return 0;
}

/*
 * Last function called before jumping to runtime. Used for final setup and
 * cleanup.
 */
static int boot_platform_finish(void)
{
    enum mhu_v3_x_error_t mhu_error;

    /*
     * Send doorbell to SCP to indicate that the RSE initialization is
     * complete and that the SCP can turn on the Safety Island clusters.
     */
    mhu_error = mhu_v3_x_doorbell_write(&MHU_RSE_TO_SCP_DEV,
                                        MHU_SCP_SI_READY_SIGNAL_CHANNEL,
                                        MHU_SCP_SI_CL0_READY_SIGNAL_PAYLOAD);

    if (mhu_error != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP (SI CL0) doorbell failed to send: %d",
                     mhu_error);
        return 1;
    }
    BOOT_LOG_INF("BL2: RSE to SCP (SI CL0) doorbell set!");

    mhu_error = mhu_v3_x_doorbell_write(&MHU_RSE_TO_SCP_DEV,
                                        MHU_SCP_SI_READY_SIGNAL_CHANNEL,
                                        MHU_SCP_SI_CL1_READY_SIGNAL_PAYLOAD);

    if (mhu_error != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP (SI CL1) doorbell failed to send: %d",
                     mhu_error);
        return 1;
    }
    BOOT_LOG_INF("BL2: RSE to SCP (SI CL1) doorbell set!");

    mhu_error = mhu_v3_x_doorbell_write(&MHU_RSE_TO_SCP_DEV,
                                        MHU_SCP_SI_READY_SIGNAL_CHANNEL,
                                        MHU_SCP_SI_CL2_READY_SIGNAL_PAYLOAD);

    if (mhu_error != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP (SI CL2) doorbell failed to send: %d",
                     mhu_error);
        return 1;
    }
    BOOT_LOG_INF("BL2: RSE to SCP (SI CL2) doorbell set!");

    /*
     * Send doorbell to SCP to indicate that the RSE initialization is
     * complete and that the SCP can turn on the primary AP core.
     */
    mhu_error = mhu_v3_x_doorbell_write(&MHU_RSE_TO_SCP_DEV,
                                        MHU_SCP_AP_READY_SIGNAL_CHANNEL,
                                        MHU_SCP_AP_READY_SIGNAL_PAYLOAD);

    if (mhu_error != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP doorbell failed to send: %d",
                     mhu_error);
        return 1;
    }
    BOOT_LOG_INF("BL2: RSE to SCP doorbell set!");

    rse_sam_finish();

    /*
     * Disable SCP to RSE MHUv3 Interrupt to ensure interrupt doesn't trigger
     * while switching to runtime.
     */
    NVIC_DisableIRQ(CMU_MHU4_Receiver_IRQn);
    return 0;
}

/*
 * ========================= SECURE LOAD FUNCTIONS =============================
 */

static int boot_platform_pre_load_secure(void)
{
    return 0;
}

static int boot_platform_post_load_secure(void)
{
    return boot_platform_finish();
}

/*
 * ============================ SCP LOAD FUNCTIONS =============================
 */

static int initialize_rse_scp_mhu(void)
{
    enum mhu_v3_x_error_t mhuv3_err;
    uint8_t ch;
    uint8_t num_ch;

    /* Setup RSE to SCP MHU Sender */

    /* Initialize the RSE to SCP Sender MHU */
    mhuv3_err = mhu_v3_x_driver_init(&MHU_RSE_TO_SCP_DEV);
    if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP MHU driver init failed: %d", mhuv3_err);
        return 1;
    }

    /* Get number of channels for sender */
    mhuv3_err = mhu_v3_x_get_num_channel_implemented(
                &MHU_RSE_TO_SCP_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, &num_ch);
    if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP MHU get channels failed: %d", mhuv3_err);
        return 1;
    }

    /* Disable interrupts for sender */
    for (ch = 0; ch < num_ch; ++ch) {
        mhuv3_err = mhu_v3_x_channel_interrupt_disable(
                    &MHU_RSE_TO_SCP_DEV, ch, MHU_V3_X_CHANNEL_TYPE_DBCH);
        if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
            BOOT_LOG_ERR("BL2: RSE to SCP MHU interrupt disable failed: %d",
                         mhuv3_err);
            return 1;
        }
    }

    /* Setup SCP to RSE MHU Receiver */

    /* Initialize the SCP to RSE Receiver MHU */
    mhuv3_err = mhu_v3_x_driver_init(&MHU_SCP_TO_RSE_DEV);
    if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SCP to RSE MHU driver init failed: %d", mhuv3_err);
        return 1;
    }

    /* Get number of channels of receiver */
    mhuv3_err = mhu_v3_x_get_num_channel_implemented(&MHU_SCP_TO_RSE_DEV,
            MHU_V3_X_CHANNEL_TYPE_DBCH, &num_ch);
    if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SCP to RSE MHU get channels failed: %d", mhuv3_err);
        return 1;
    }

    /*
     * Clear receiver interrupt mask on all channels and enable interrupts for
     * all channels so interrupts are triggered when data is received on any
     * channel.
     */
    for (ch = 0; ch < num_ch; ch++) {
        mhuv3_err = mhu_v3_x_channel_interrupt_enable(&MHU_SCP_TO_RSE_DEV, ch,
                                                MHU_V3_X_CHANNEL_TYPE_DBCH);
        if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
            BOOT_LOG_ERR("BL2: RSE to SCP MHU interrupt enable failed: %d",
                         mhuv3_err);
            return 1;
        }
        mhuv3_err = mhu_v3_x_doorbell_mask_clear(&MHU_SCP_TO_RSE_DEV, ch,
                                                 UINT32_MAX);
        if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
            BOOT_LOG_ERR("BL2: RSE to SCP MHU mask clear failed: %d",
                         mhuv3_err);
            return 1;
        }
    }

    /* Enable SCP to RSE MHUv3 Interrupt */
    NVIC_ClearPendingIRQ(CMU_MHU4_Receiver_IRQn);
    NVIC_EnableIRQ(CMU_MHU4_Receiver_IRQn);

    BOOT_LOG_INF("BL2: RSE to SCP and SCP to RSE MHUs initialized");
    return 0;
}

/* Function called before SCP firmware is loaded. */
static int boot_platform_pre_load_scp(void)
{
    int mhu_err;

    BOOT_LOG_INF("BL2: SCP pre load start");

    /*
     * Setup everything needed for access to the SCP subsystem.
     */
    if (host_system_prepare_scp_access() != 0) {
        BOOT_LOG_ERR("BL2: Could not setup access to SCP systems.");
        return 1;
    }

    /* Initialize RSE to SCP and SCP to RSE MHUs */
    mhu_err = initialize_rse_scp_mhu();
    if (mhu_err) {
        return mhu_err;
    }

    BOOT_LOG_INF("BL2: SCP pre load complete");

    return 0;
}

/* Function called after SCP firmware is loaded. */
static int boot_platform_post_load_scp(void)
{
    struct rse_integ_t *integ_layer =
            (struct rse_integ_t *)RSE_INTEG_LAYER_BASE_S;
    enum mscp_error_t mscp_err;

    BOOT_LOG_INF("BL2: SCP post load start");

    /*
     * Since the measurement are taken at this point, clear the image header
     * part in the ITCM before releasing SCP out of reset.
     */
    memset((void*)HOST_SCP_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    /* Enable SCP's ATU Access Permission (ATU AP) */
    integ_layer->atu_ap |= RSE_INTEG_ATU_AP_SCP_ATU;

    mscp_err = mscp_driver_release_cpu(&HOST_SCP_DEV);
    if (mscp_err != MSCP_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SCP release failed");
        return 1;
    }
    BOOT_LOG_INF("BL2: SCP is released out of reset");

    return 0;
}

/*
 * =========================== AP BL2 LOAD FUNCTIONS ===========================
 */

/* Function called before AP BL2 firmware is loaded. */
static int boot_platform_pre_load_ap_bl2(void)
{
    BOOT_LOG_INF("BL2: AP BL2 pre load start");

    BOOT_LOG_INF("BL2: Wait for doorbell from SCP before loading AP BL2...");

    /*
     * Ensure SCP has notified it is ready and setup anything needed for access
     * to the application processor subsystem.
     */
    if (host_system_prepare_ap_access() != 0) {
        BOOT_LOG_ERR("BL2: Could not setup access to AP systems.");
        return 1;
    }

    BOOT_LOG_INF("BL2: Doorbell received from SCP!");

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
    BOOT_LOG_INF("BL2: AP BL2 post load start");

    /*
     * Executes final preparations before starting the AP core.
     */
    if (host_system_finish() != 0) {
        BOOT_LOG_ERR("BL2: Could not finish host system preparations");
        return 1;
    }

    /*
     * Since the measurement are taken at this point, clear the image
     * header part in the Shared SRAM before releasing AP BL2 out of reset.
     */
    memset((void*)HOST_AP_BL2_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    BOOT_LOG_INF("BL2: AP BL2 post load complete");

    return 0;
}

/*
 * =========================== SI CL0 LOAD FUNCTIONS ===========================
 */

/* Function called before SI CL0 firmware is loaded. */
static int boot_platform_pre_load_si_cl0(void)
{
    int32_t result;

    BOOT_LOG_INF("BL2: SI CL0 pre load start");

    result = gic_multiple_view_init();
    if (result != 0) {
        return result;
    }

    BOOT_LOG_INF("BL2: SI CL0 pre load complete");

    return 0;
}

/* Function called after SI CL0 firmware is loaded. */
static int boot_platform_post_load_si_cl0(void)
{
    BOOT_LOG_INF("BL2: SI CL0 post load start");

    /*
     * Since the measurement are taken at this point, clear the image
     * header part in the Shared SRAM before releasing SI CL0 out of reset.
     */
    memset((void*)HOST_SI_CL0_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    BOOT_LOG_INF("BL2: SI CL0 post load complete");

    return 0;
}

/*
 * =========================== SI CL1 LOAD FUNCTIONS ===========================
 */

/* Function called before SI CL1 firmware is loaded. */
static int boot_platform_pre_load_si_cl1(void)
{
    BOOT_LOG_INF("BL2: SI CL1 pre load start");
    BOOT_LOG_INF("BL2: SI CL1 pre load complete");

    return 0;
}

/* Function called after SI CL1 firmware is loaded. */
static int boot_platform_post_load_si_cl1(void)
{
    BOOT_LOG_INF("BL2: SI CL1 post load start");

    /*
     * Since the measurement are taken at this point, clear the image
     * header part in the Shared SRAM before releasing SI CL1 out of reset.
     */
    memset((void*)HOST_SI_CL1_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    BOOT_LOG_INF("BL2: SI CL1 post load complete");

    return 0;
}

/*
 * =========================== SI CL2 LOAD FUNCTIONS ===========================
 */

/* Function called before SI CL2 firmware is loaded. */
static int boot_platform_pre_load_si_cl2(void)
{
    BOOT_LOG_INF("BL2: SI CL2 pre load start");
    BOOT_LOG_INF("BL2: SI CL2 pre load complete");

    return 0;
}

/* Function called after SI CL2 firmware is loaded. */
static int boot_platform_post_load_si_cl2(void)
{
    BOOT_LOG_INF("BL2: SI CL2 post load start");

    /*
     * Since the measurement are taken at this point, clear the image
     * header part in the Shared SRAM before releasing SI CL2 out of reset.
     */
    memset((void*)HOST_SI_CL2_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    BOOT_LOG_INF("BL2: SI CL2 post load complete");

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
    [RSE_FIRMWARE_SCP_ID]           = boot_platform_pre_load_scp,
    [RSE_FIRMWARE_SI_CL0_ID]        = boot_platform_pre_load_si_cl0,
    [RSE_FIRMWARE_SI_CL1_ID]        = boot_platform_pre_load_si_cl1,
    [RSE_FIRMWARE_SI_CL2_ID]        = boot_platform_pre_load_si_cl2,
    [RSE_FIRMWARE_AP_BL2_ID]        = boot_platform_pre_load_ap_bl2,
};

/*
 * Array of function pointers to call after each image is loaded indexed by
 * image id
 */
static int (*boot_platform_post_load_vector[RSE_FIRMWARE_COUNT]) (void) = {
    [RSE_FIRMWARE_SECURE_ID]        = boot_platform_post_load_secure,
    [RSE_FIRMWARE_SCP_ID]           = boot_platform_post_load_scp,
    [RSE_FIRMWARE_SI_CL0_ID]        = boot_platform_post_load_si_cl0,
    [RSE_FIRMWARE_SI_CL1_ID]        = boot_platform_post_load_si_cl1,
    [RSE_FIRMWARE_SI_CL2_ID]        = boot_platform_post_load_si_cl2,
    [RSE_FIRMWARE_AP_BL2_ID]        = boot_platform_post_load_ap_bl2,
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
    if (image_id == RSE_FIRMWARE_NON_SECURE_ID) {
        return false;
    }

    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: Image %d beyond expected Firmware count: %d",
                image_id, RSE_FIRMWARE_COUNT);
        return false;
    }

    return true;
}
