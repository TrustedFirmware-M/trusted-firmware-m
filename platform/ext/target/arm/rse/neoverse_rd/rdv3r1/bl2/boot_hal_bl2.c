/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "boot_hal.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "boot_measurement.h"
#include "bootutil/bootutil.h"
#include "bootutil/bootutil_log.h"
#include "bootutil/fault_injection_hardening.h"
#include "device_definition.h"
#include "flash_map/flash_map.h"
#include "host_base_address.h"
#include "host_system.h"
#include "interrupts_bl2.h"
#include "bl2_image_id.h"
#include "mhu_v3_x.h"
#include "noc_s3_lib.h"
#include "platform_base_address.h"
#include "platform_regs.h"
#include "psa/crypto.h"
#include "rse_expansion_regs.h"
#include "size_defs.h"
#include "tfm_boot_status.h"
#include "tfm_plat_defs.h"

#ifdef CRYPTO_HW_ACCELERATOR
#include "crypto_hw.h"
#include "fih.h"
#endif /* CRYPTO_HW_ACCELERATOR */

#define MHU_SCP_READY_SIGNAL_CHANNEL 1
#define MHU_SCP_READY_SIGNAL_PAYLOAD 0x1

static uint8_t lcp_measurement[PSA_HASH_LENGTH(MEASURED_BOOT_HASH_ALG)];
static struct boot_measurement_metadata lcp_measurement_metadata = {0};

static struct host_system_info_t *host_system_info;

/*
 * Store an entry of data in the shared area of memory so it can be used by the
 * runtime firmware. The shared memory has a standard format see
 * 'secure_fw/spm/include/boot/tfm_boot_status.h' for details.
 */
static int boot_add_data_to_shared_area(uint8_t major_type,
                                        uint16_t minor_type,
                                        size_t size,
                                        const uint8_t *data)
{
    struct shared_data_tlv_entry tlv_entry = {0};
    struct tfm_boot_data *boot_data;
    uintptr_t tlv_end, offset;
    const uintptr_t data_base = tfm_plat_get_shared_measurement_data_base();
    const size_t data_size = tfm_plat_get_shared_measurement_data_size();

    if (data == NULL) {
        return -1;
    }

    boot_data = (struct tfm_boot_data *)data_base;

    /* Check whether the shared area needs to be initialized. */
    if ((boot_data->header.tlv_magic != SHARED_DATA_TLV_INFO_MAGIC) ||
        (boot_data->header.tlv_tot_len > data_size)) {
        memset((void *)data_base, 0, data_size);
        boot_data->header.tlv_magic   = SHARED_DATA_TLV_INFO_MAGIC;
        boot_data->header.tlv_tot_len = SHARED_DATA_HEADER_SIZE;
    }

    /* Get the boundaries of TLV section. */
    tlv_end = data_base + boot_data->header.tlv_tot_len;
    offset = data_base + SHARED_DATA_HEADER_SIZE;

    /*
     * Check whether TLV entry is already added. Iterates over the TLV section
     * looks for the same entry if found then returns with error.
     */
    while (offset < tlv_end) {
        /* Create local copy to avoid unaligned access */
        memcpy(&tlv_entry, (const void *)offset, SHARED_DATA_ENTRY_HEADER_SIZE);
        if (GET_MAJOR(tlv_entry.tlv_type) == major_type &&
            GET_MINOR(tlv_entry.tlv_type) == minor_type) {

            return -1;
        }

        offset += SHARED_DATA_ENTRY_SIZE(tlv_entry.tlv_len);
    }

    /* Add TLV entry. */
    tlv_entry.tlv_type = SET_TLV_TYPE(major_type, minor_type);
    tlv_entry.tlv_len  = size;

    /* Check integer overflow and overflow of shared data area. */
    if (SHARED_DATA_ENTRY_SIZE(size) >
                (UINT16_MAX - boot_data->header.tlv_tot_len)) {
        return -1;
    } else if ((SHARED_DATA_ENTRY_SIZE(size) + boot_data->header.tlv_tot_len) > data_size) {
        return -1;
    }

    offset = tlv_end;
    memcpy((void *)offset, &tlv_entry, SHARED_DATA_ENTRY_HEADER_SIZE);

    offset += SHARED_DATA_ENTRY_HEADER_SIZE;
    memcpy((void *)offset, data, size);

    boot_data->header.tlv_tot_len += SHARED_DATA_ENTRY_SIZE(size);

    return 0;
}

/*
 * Store a boot measurement in shared memory based on common
 * boot_store_measurement see 'platform/ext/common/boot_hal_bl2.c'
 */
static int store_measurement(uint8_t index,
                             const uint8_t *measurement,
                             size_t measurement_size,
                             const struct boot_measurement_metadata *metadata,
                             bool lock_measurement)
{
    uint16_t minor_type;
    uint8_t claim;
    int rc;

    minor_type = SET_MBS_MINOR(index, SW_MEASURE_METADATA);
    rc = boot_add_data_to_shared_area(TLV_MAJOR_MBS,
                                      minor_type,
                                      sizeof(struct boot_measurement_metadata),
                                      (const uint8_t *)metadata);
    if (rc) {
        BOOT_LOG_ERR("BL2: Unable to store measurement");
        return rc;
    }

    claim = lock_measurement ? SW_MEASURE_VALUE_NON_EXTENDABLE
                             : SW_MEASURE_VALUE;
    minor_type = SET_MBS_MINOR(index, claim);
    rc = boot_add_data_to_shared_area(TLV_MAJOR_MBS,
                                      minor_type,
                                      measurement_size,
                                      measurement);

    return rc;
}

/*
 * Store a boot measurement in shared memory.
 *
 * There is an special handling for LCP which is loading multiple instances
 * of the same image so requires multiple measurements but only one store as
 * measurements should be identical.
 */
int boot_store_measurement(uint8_t index,
                           const uint8_t *measurement,
                           size_t measurement_size,
                           const struct boot_measurement_metadata *metadata,
                           bool lock_measurement)
{
    static bool lcp_measurement_created = false;

    if (index >= BOOT_MEASUREMENT_SLOT_MAX) {
        return -1;
    }

    /*
     * LCP image requires multiple loads. If slot index is for LCP, then don't
     * add data to the shared area.
     */
    if(index == BOOT_MEASUREMENT_SLOT_RT_0 + RSE_FIRMWARE_LCP_ID) {
        if (measurement_size != PSA_HASH_LENGTH(MEASURED_BOOT_HASH_ALG)) {
            BOOT_LOG_ERR("BL2: LCP measurements different lengths");
            return -1;
        }

        /*
         * If LCP measurements are not stored, store the input measurements.
         * Else, check if the store measurements matches with the input
         * measurements. If those doesn't match, then return -1.
         */
        if (lcp_measurement_created == false) {
            memcpy(lcp_measurement, measurement,
                   measurement_size * sizeof(uint8_t));
            memcpy(&lcp_measurement_metadata, metadata,
                   sizeof(struct boot_measurement_metadata));
            lcp_measurement_created = true;
        } else {
            if ((memcmp(measurement, lcp_measurement,
                        measurement_size * sizeof(uint8_t)) != 0) ||
                (memcmp(metadata, &lcp_measurement_metadata,
                        sizeof(struct boot_measurement_metadata)) != 0)) {
                BOOT_LOG_ERR("BL2: LCP measurements different");
                return -1;
            }
        }
        return 0;
    }

    return store_measurement(index,
                             measurement,
                             measurement_size,
                             metadata,
                             lock_measurement);
}

int32_t boot_platform_post_init(void)
{
    int32_t result;

    result = host_system_init();
    if (result != 0) {
        return result;
    }

    result = host_system_get_info(&host_system_info);
    if (result != 0) {
        return result;
    }

    BOOT_LOG_INF("CHIP ID: %d", host_system_info->chip_id);

    result = interrupts_bl2_init();
    if (result != 0) {
        return result;
    }

#ifdef CRYPTO_HW_ACCELERATOR
    result = crypto_hw_accelerator_init();
    if (result) {
        return -1;
    }

    (void)fih_delay_init();
#endif /* CRYPTO_HW_ACCELERATOR */

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
     * complete and that the SCP can release the LCPs and turn on the
     * primary AP core.
     */
    mhu_error = mhu_v3_x_doorbell_write(&MHU_RSE_TO_SCP_DEV,
                                        MHU_SCP_READY_SIGNAL_CHANNEL,
                                        MHU_SCP_READY_SIGNAL_PAYLOAD);

    if (mhu_error != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP doorbell failed to send: %d",
                     mhu_error);
        return -1;
    }
    BOOT_LOG_INF("BL2: RSE to SCP doorbell set!");

    /*
     * Disable SCP to RSE MHUv3 Interrupt to ensure interrupt doesn't trigger
     * while switching to runtime.
     */
    NVIC_DisableIRQ(CMU_MHU4_Receiver_IRQn);
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
    return boot_platform_finish();
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
        return -1;
    }

    /* Get number of channels for sender */
    mhuv3_err = mhu_v3_x_get_num_channel_implemented(
                &MHU_RSE_TO_SCP_DEV, MHU_V3_X_CHANNEL_TYPE_DBCH, &num_ch);
    if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: RSE to SCP MHU get channels failed: %d", mhuv3_err);
        return -1;
    }

    /* Disable interrupts for sender */
    for (ch = 0; ch < num_ch; ++ch) {
        mhuv3_err = mhu_v3_x_channel_interrupt_disable(
                    &MHU_RSE_TO_SCP_DEV, ch, MHU_V3_X_CHANNEL_TYPE_DBCH);
        if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
            BOOT_LOG_ERR("BL2: RSE to SCP MHU interrupt disable failed: %d",
                         mhuv3_err);
            return -1;
        }
    }

    /* Setup SCP to RSE MHU Receiver */

    /* Initialize the SCP to RSE Receiver MHU */
    mhuv3_err = mhu_v3_x_driver_init(&MHU_SCP_TO_RSE_DEV);
    if (mhuv3_err != MHU_V_3_X_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SCP to RSE MHU driver init failed: %d", mhuv3_err);
        return -1;
    }

    /* Get number of channels of receiver */
    mhuv3_err = mhu_v3_x_get_num_channel_implemented(&MHU_SCP_TO_RSE_DEV,
            MHU_V3_X_CHANNEL_TYPE_DBCH, &num_ch);
    if (mhuv3_err != MHU_V_3_X_ERR_NONE){
        BOOT_LOG_ERR("BL2: SCP to RSE MHU get channels failed: %d", mhuv3_err);
        return -1;
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
            return -1;
        }
        mhuv3_err = mhu_v3_x_doorbell_mask_clear(&MHU_SCP_TO_RSE_DEV, ch,
                                                 UINT32_MAX);
        if (mhuv3_err != MHU_V_3_X_ERR_NONE){
            BOOT_LOG_ERR("BL2: RSE to SCP MHU mask clear failed: %d",
                         mhuv3_err);
            return -1;
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
    enum atu_error_t atu_err;
    int mhu_err;

    BOOT_LOG_INF("BL2: SCP pre load start");

    /*
     * Setup everything needed for access to the MSCP subsystem.
     */
    if (host_system_prepare_mscp_access() != 0) {
        BOOT_LOG_ERR("BL2: Could not setup access to MSCP systems.");
        return -1;
    }

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
        return -1;
    }

    /* Configure RSE ATU to access SCP ITCM region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_CODE_LOAD_ID,
                                    HOST_SCP_IMG_CODE_BASE_S,
                                    HOST_SCP_PHYS_BASE,
                                    HOST_SCP_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
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
    enum atu_error_t atu_err;
    struct rse_integ_t *integ_layer =
            (struct rse_integ_t *)RSE_INTEG_LAYER_BASE_S;
    enum mscp_error_t mscp_err;

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
        return -1;
    }

    mscp_err = mscp_driver_release_cpu(&HOST_SCP_DEV);
    if (mscp_err != MSCP_ERR_NONE) {
        BOOT_LOG_ERR("BL2: SCP release failed");
        return -1;
    }
    BOOT_LOG_INF("BL2: SCP is released out of reset");

    /* Close RSE ATU region configured to access SCP INIT_CTRL region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, HOST_SCP_INIT_CTRL_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    /* Close RSE ATU region configured to access RSE header region for SCP */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    /* Close RSE ATU region configured to access SCP ITCM region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    BOOT_LOG_INF("BL2: SCP post load complete");

    return 0;
}

/*
 * =================================== MCP ====================================
 */

/* Function called before MCP firmware is loaded. */
static int boot_platform_pre_load_mcp(void)
{
    enum atu_error_t atu_err;
    struct rse_integ_t *integ_layer =
            (struct rse_integ_t *)RSE_INTEG_LAYER_BASE_S;

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
        return -1;
    }

    /* Configure RSE ATU to access MCP ITCM region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_CODE_LOAD_ID,
                                    HOST_MCP_IMG_CODE_BASE_S,
                                    HOST_MCP_PHYS_BASE,
                                    HOST_MCP_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    BOOT_LOG_INF("BL2: MCP pre load complete");

    /* Enable MCP's ATU Access Permission (ATU AP) */
    integ_layer->atu_ap |= RSE_INTEG_ATU_AP_MCP_ATU;

    return 0;
}

/* Function called after MCP firmware is loaded. */
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
        return -1;
    }

    mscp_err = mscp_driver_release_cpu(&HOST_MCP_DEV);
    if (mscp_err != MSCP_ERR_NONE) {
        BOOT_LOG_ERR("BL2: MCP release failed");
        return -1;
    }
    BOOT_LOG_INF("BL2: MCP is released out of reset");

    /* Close RSE ATU region configured to access MCP INIT_CTRL region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, HOST_MCP_INIT_CTRL_ATU_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    /* Close RSE ATU region configured to access RSE header region for MCP */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    /* Close RSE ATU region configured to access MCP ITCM region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    BOOT_LOG_INF("BL2: MCP post load complete");

    return 0;
}

/*
 * =================================== LCP ====================================
 */

/* Function called before LCP firmware is loaded. */
static int boot_platform_pre_load_lcp(void)
{
    enum atu_error_t atu_err;

    BOOT_LOG_INF("BL2: LCP pre load start");

    BOOT_LOG_INF("BL2: Wait for doorbell from SCP before loading LCP...");

    /*
     * Ensure SCP has notified it is ready and setup anything needed for access
     * to the application processor subsystem where LCP is located.
     */
    if (host_system_prepare_ap_access() != 0) {
        BOOT_LOG_ERR("BL2: Could not setup access to AP systems.");
        return -1;
    }

    BOOT_LOG_INF("BL2: Doorbell received from SCP!");

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
                                    (host_system_info->chip_ap_phys_base +
                                        HOST_LCP_0_HDR_PHYS_BASE),
                                    RSE_IMG_HDR_ATU_WINDOW_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: ATU could not init LCP header load region");
        return -1;
    }

    /*
     * Configure RSE ATU region to access the Cluster utility space.
     */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_CODE_LOAD_ID,
                                    HOST_LCP_IMG_CODE_BASE_S,
                                    (host_system_info->chip_ap_phys_base +
                                        HOST_LCP_N_CODE_PHYS_BASE(0)),
                                    HOST_LCP_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: ATU could not init LCP code load region");
        return -1;
    }

    BOOT_LOG_INF("BL2: LCP pre load complete");

    return 0;
}

/* Function called after LCP firmware is loaded. */
static int boot_platform_post_load_lcp(void)
{
    enum atu_error_t atu_err;
    struct boot_rsp rsp;
    int lcp_idx, rc;
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
        return -1;
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
                                        (host_system_info->chip_ap_phys_base +
                                            HOST_LCP_N_CODE_PHYS_BASE(lcp_idx)),
                                        HOST_LCP_ATU_SIZE);
        if (atu_err != ATU_ERR_NONE) {
            BOOT_LOG_ERR("BL2: ATU could not init LCP code load region");
            return -1;
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
            return -1;
        }
    }

    /*
     * Save the boot measurement after LCP images are loaded.
     */
    rc = store_measurement(
        (uint8_t)BOOT_MEASUREMENT_SLOT_RT_0 + RSE_FIRMWARE_LCP_ID,
        lcp_measurement,
        PSA_HASH_LENGTH(MEASURED_BOOT_HASH_ALG) * sizeof(uint8_t),
        &lcp_measurement_metadata, false);
    if (rc) {
        BOOT_LOG_ERR("BL2: Could not store LCP measurement");
        return -1;
    }

    /* Close RSE ATU region configured to access RSE header region for LCP */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_ERR("BL2: ATU could not uninit LCP header load region");
        return -1;
    }

    BOOT_LOG_INF("BL2: LCP post load complete");

    return 0;
}

/*
 * ================================== AP BL1 ==================================
 */

/* Function called before AP BL1 firmware is loaded. */
static int boot_platform_pre_load_ap_bl1(void)
{
    enum atu_error_t atu_err;
    enum atu_roba_t roba_value;

    BOOT_LOG_INF("BL2: AP BL1 pre load start");

    /* Configure RSE ATU to access RSE header region for AP BL1 */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_HDR_LOAD_ID,
                                    HOST_AP_BL1_HDR_ATU_WINDOW_BASE_S,
                                    HOST_AP_BL1_HDR_PHYS_BASE,
                                    RSE_IMG_HDR_ATU_WINDOW_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    roba_value = ATU_ROBA_SET_1;
    atu_err = set_axnsc(&ATU_DEV_S, roba_value, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_INF("BL2: Unable to modify AxNSE");
        return -1;
    }

    roba_value = ATU_ROBA_SET_0;
    atu_err = set_axprot1(&ATU_DEV_S, roba_value, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_INF("BL2: Unable to modify AxPROT1");
        return -1;
    }

    /* Configure RSE ATU to access AP BL1 Shared SRAM region */
    atu_err = atu_initialize_region(&ATU_DEV_S,
                                    RSE_ATU_IMG_CODE_LOAD_ID,
                                    HOST_AP_BL1_IMG_CODE_BASE_S,
                                    HOST_AP_BL1_PHYS_BASE,
                                    HOST_AP_BL1_ATU_SIZE);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    roba_value = ATU_ROBA_SET_1;
    atu_err = set_axnsc(&ATU_DEV_S, roba_value, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_INF("BL2: Unable to modify AxNSE");
        return -1;
    }

    roba_value = ATU_ROBA_SET_0;
    atu_err = set_axprot1(&ATU_DEV_S, roba_value, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        BOOT_LOG_INF("BL2: Unable to modify AxPROT1");
        return -1;
    }

    BOOT_LOG_INF("BL2: AP BL1 pre load complete");

    return 0;
}

/* Function called after AP BL1 firmware is loaded. */
static int boot_platform_post_load_ap_bl1(void)
{
    enum atu_error_t atu_err;

    BOOT_LOG_INF("BL2: AP BL1 post load start");

    /*
     * Executes final preparations before starting the AP core.
     */
    if (host_system_finish() != 0) {
        BOOT_LOG_ERR("BL2: Could not finish host system preparations");
        return -1;
    }

    /*
     * Since the measurement are taken at this point, clear the image
     * header part in the Shared SRAM before releasing AP BL1 out of reset.
     */
    memset(HOST_AP_BL1_IMG_HDR_BASE_S, 0, BL2_HEADER_SIZE);

    /* Close RSE ATU region configured to access RSE header region for AP BL1 */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_HDR_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    /* Close RSE ATU region configured to access AP BL1 Shared SRAM region */
    atu_err = atu_uninitialize_region(&ATU_DEV_S, RSE_ATU_IMG_CODE_LOAD_ID);
    if (atu_err != ATU_ERR_NONE) {
        return -1;
    }

    BOOT_LOG_INF("BL2: AP BL1 post load complete");

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
#ifndef TFM_S_REG_TEST
    [RSE_FIRMWARE_SCP_ID]           = boot_platform_pre_load_scp,
    [RSE_FIRMWARE_MCP_ID]           = boot_platform_pre_load_mcp,
    [RSE_FIRMWARE_LCP_ID]           = boot_platform_pre_load_lcp,
    [RSE_FIRMWARE_AP_BL1_ID]        = boot_platform_pre_load_ap_bl1,
#endif
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
#ifndef TFM_S_REG_TEST
    [RSE_FIRMWARE_SCP_ID]           = boot_platform_post_load_scp,
    [RSE_FIRMWARE_MCP_ID]           = boot_platform_post_load_mcp,
    [RSE_FIRMWARE_LCP_ID]           = boot_platform_post_load_lcp,
    [RSE_FIRMWARE_AP_BL1_ID]        = boot_platform_post_load_ap_bl1,
#endif
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

    if ((image_id == RSE_FIRMWARE_AP_BL1_ID) &&
                (host_system_info->chip_id > 0)) {
        /* Skip AP-BL1 image loading for remote chips */
        return false;
    }

    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: Image %d beyond expected Firmware count: %d",
                image_id, RSE_FIRMWARE_COUNT);
        return false;
    }

    return true;
}
