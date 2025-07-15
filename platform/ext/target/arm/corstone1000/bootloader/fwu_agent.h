/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef FWU_AGENT_H
#define FWU_AGENT_H

#include "psa/error.h"
#include "../fip_parser/external/uuid.h"

#ifdef ENABLE_FWU_AGENT_DEBUG_LOGS
    #include "tfm_log.h"
    #define FWU_LOG_MSG(f_, ...) tfm_log(LOG_MARKER_RAW f_, ##__VA_ARGS__)
#else
    #define FWU_LOG_MSG(f_, ...)
#endif

#define FWU_ASSERT(_c_)                                                        \
                if (!(_c_)) {                                                  \
                    FWU_LOG_MSG("%s:%d assert hit\n\r", __func__, __LINE__);   \
                    while(1) {};                                               \
                }                                                              \


/* Version used for the very first image of the device. */
#define FWU_IMAGE_INITIAL_VERSION 0

#define EFI_SYSTEM_RESOURCE_TABLE_FIRMWARE_RESOURCE_VERSION  1
typedef struct {
    uint32_t signature;
    uint32_t header_size;
    uint32_t fw_version;
    uint32_t lowest_supported_version;
} __packed fmp_payload_header_t;

typedef struct {
    fmp_payload_header_t fmp_hdr;
    size_t fmp_hdr_size_recvd;
    size_t image_size_recvd;
} __packed fmp_header_image_info_t;

/* Store image information common for both the banks */
typedef struct {
    /* Total size of the image */
    uint32_t image_size;

    /* Offset of image within a bank */
    uint32_t image_offset;

    /* Image GUID */
    struct efi_guid image_guid;
} __packed fwu_bank_image_info_t;

/* ESRT v1 */
struct __attribute__((__packed__)) efi_system_resource_entry {
    struct   efi_guid fw_class;
    uint32_t fw_type;
    uint32_t fw_version;
    uint32_t lowest_supported_fw_version;
    uint32_t capsule_flags;
    uint32_t last_attempt_version;
    uint32_t last_attempt_status;
};

struct __attribute__((__packed__)) efi_system_resource_table {
    uint32_t fw_resource_count;
    uint32_t fw_resource_count_max;
    uint64_t fw_resource_version;
    struct   efi_system_resource_entry entries[];
};

psa_status_t fwu_metadata_provision(void);
psa_status_t fwu_metadata_init(void);

/* host to secure enclave:
 * firwmare update image is sent accross
 */
psa_status_t corstone1000_fwu_flash_image(void);

/* host to secure enclave:
 * host responds with this api to acknowledge its successful
 * boot.
 */
psa_status_t corstone1000_fwu_host_ack(void);

void bl1_get_active_bl2_image(uint32_t *bank_offset);
uint8_t bl2_get_boot_bank(void);

/* When in trial state, start the timer for host to respond.
 * Diable timer when host responds back either by calling
 * corstone1000_fwu_accept_image or corstone1000_fwu_select_previous.
 * Otherwise, resets the system.
 */
void host_acknowledgement_timer_to_reset(void);

enum fwu_nv_counter_index_t {
    FWU_BL2_NV_COUNTER = 0,
    FWU_TFM_NV_COUNTER,
    FWU_TFA_NV_COUNTER,
    FWU_MAX_NV_COUNTER_INDEX = FWU_TFA_NV_COUNTER
};

/* stage nv counter into private metadata section of the flash.
 * staged nv counters are written to the otp when firmware update
 * is successful
 * the function assumes that the api is called in the boot loading
 * stage
 */
psa_status_t fwu_stage_nv_counter(enum fwu_nv_counter_index_t index,
        uint32_t img_security_cnt);

/*
 * Check if both metadata replica is valid by calculating and comparing crc32.
 * If one of the replica is corrupted then update it with the valid replica.
 * If both of the replicas are corrupted then the correction is not possible.
 */
psa_status_t fwu_metadata_check_and_correct_integrity(void);

#endif /* FWU_AGENT_H */
