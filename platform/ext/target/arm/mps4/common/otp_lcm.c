/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_otp.h"

#include "region_defs.h"
#include "cmsis_compiler.h"
#include "platform_s_device_definition.h"
#include "lcm_drv.h"
#include "lcm_otp_layout.h"
#include "tfm_hal_device_header.h"
#include "uart_stdout.h"
#include "tfm_hal_platform.h"
#include "sam_drv.h"

#ifdef MCUBOOT_SIGN_EC384
/* The sizes are in 4 byte words */
#define BL2_ROTPK_HASH_SIZE (12)
#define BL2_ROTPK_SIZE      (25)
#else
#define BL2_ROTPK_HASH_SIZE (8)
#define BL2_ROTPK_SIZE      (17)
#endif /* MCUBOOT_SIGN_EC384 */

#ifdef MCUBOOT_BUILTIN_KEY
#define PROV_ROTPK_DATA_SIZE    BL2_ROTPK_SIZE
#else
#define PROV_ROTPK_DATA_SIZE    BL2_ROTPK_HASH_SIZE
#endif /* MCUBOOT_BUILTIN_KEY */

#define OTP_OFFSET(x)       (offsetof(struct lcm_otp_layout_t, x))
#define OTP_SIZE(x)         (sizeof(((struct lcm_otp_layout_t *)0)->x))
#define USER_AREA_OFFSET(x) (OTP_OFFSET(user_data) + \
                             offsetof(struct plat_user_area_layout_t, x))
#define USER_AREA_SIZE(x)   (sizeof(((struct plat_user_area_layout_t *)0)->x))

__PACKED_STRUCT plat_user_area_layout_t {
    __PACKED_UNION {
        __PACKED_STRUCT {
            uint32_t cm_locked_size;
            uint32_t cm_locked_size_zero_count;
            uint32_t cm_zero_count;

            uint32_t dm_locked_size;
            uint32_t dm_locked_size_zero_count;
            uint32_t dm_zero_count;

            __PACKED_STRUCT {
                uint32_t bl1_2_image_len;

            /* Things after this point are not touched by BL1_1, and hence are
             * modifiable by new provisioning code.
             */
                uint32_t sam_configuration[OTP_SAM_CONFIGURATION_SIZE_BYTES];
                uint32_t cca_system_properties;

                uint32_t cm_config_flags;
            } cm_locked;

            __PACKED_STRUCT {
                uint32_t bl1_rotpk_0[14];

                uint32_t bl2_rotpk[MCUBOOT_IMAGE_NUMBER][PROV_ROTPK_DATA_SIZE];

                uint32_t iak_len;
                uint32_t iak_type;
                uint32_t iak_id[8];
                uint32_t implementation_id[8];
                uint32_t verification_service_url[8];
                uint32_t profile_definition[12];

                uint32_t secure_debug_pk[8];

                uint32_t host_rotpk_s[24];
                uint32_t host_rotpk_ns[24];
                uint32_t host_rotpk_cca[24];

                uint32_t dm_config_flags;

                __PACKED_STRUCT {
                    uint32_t bl2_encryption_key[8];
                    uint32_t s_image_encryption_key[8];
                    uint32_t ns_image_encryption_key[8];
                } dm_encrypted;
                uint8_t boot_seed[32];
                uint8_t cert_ref[32];
                uint8_t entropy_seed[64];
            } dm_locked;

            __PACKED_STRUCT {
                uint32_t bl1_nv_counter[16];
                uint32_t bl2_nv_counter[MCUBOOT_IMAGE_NUMBER][16];
#ifdef PLATFORM_HAS_PS_NV_OTP_COUNTERS
                uint32_t ps_nv_counter[3][16];
#endif /* PLATFORM_HAS_PS_NV_OTP_COUNTERS */
                uint32_t host_nv_counter[3][16];
                uint32_t reprovisioning_bits;
            } unlocked_area;
        };
        uint8_t _pad[OTP_TOTAL_SIZE - BL1_2_CODE_SIZE -
                     sizeof(struct lcm_otp_layout_t)];
    };

    /* This is aligned to the end of the OTP. The ROM knows the size of the bl1_2_image
     * because of the size field, so it's possible to shrink the bootloader (and
     * use the extra space for CM, DM, or unlocked data) without changing the
     * ROM. Placing the image here means that it doesn't get zero-count checked
     * with the rest of the CM data, since it's far faster to just calculate the
     * hash using the CC DMA.
     */
    uint32_t bl1_2_image[BL1_2_CODE_SIZE / sizeof(uint32_t)];
};

static const uint16_t otp_offsets[PLAT_OTP_ID_MAX] = {
    [PLAT_OTP_ID_HUK] = OTP_OFFSET(huk),
    [PLAT_OTP_ID_GUK] = OTP_OFFSET(guk),

    [PLAT_OTP_ID_IAK_LEN] = USER_AREA_OFFSET(dm_locked.iak_len),
    [PLAT_OTP_ID_IAK_TYPE] = USER_AREA_OFFSET(dm_locked.iak_type),
    [PLAT_OTP_ID_IAK_ID] = USER_AREA_OFFSET(dm_locked.iak_id),

    [PLAT_OTP_ID_IMPLEMENTATION_ID] = USER_AREA_OFFSET(dm_locked.implementation_id),
    [PLAT_OTP_ID_VERIFICATION_SERVICE_URL] = USER_AREA_OFFSET(dm_locked.verification_service_url),
    [PLAT_OTP_ID_PROFILE_DEFINITION] = USER_AREA_OFFSET(dm_locked.profile_definition),

    [PLAT_OTP_ID_BL2_ROTPK_0] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[0]),
#if (MCUBOOT_IMAGE_NUMBER > 1)
    [PLAT_OTP_ID_BL2_ROTPK_1] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[1]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 2)
    [PLAT_OTP_ID_BL2_ROTPK_2] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[2]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 3)
    [PLAT_OTP_ID_BL2_ROTPK_3] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[3]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 4)
    [PLAT_OTP_ID_BL2_ROTPK_4] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[4]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 5)
    [PLAT_OTP_ID_BL2_ROTPK_5] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[5]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 6)
    [PLAT_OTP_ID_BL2_ROTPK_6] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[6]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 7)
    [PLAT_OTP_ID_BL2_ROTPK_7] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[7]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 8)
    [PLAT_OTP_ID_BL2_ROTPK_8] = USER_AREA_OFFSET(dm_locked.bl2_rotpk[8]),
#endif

    [PLAT_OTP_ID_NV_COUNTER_BL2_0] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[0]),
#if (MCUBOOT_IMAGE_NUMBER > 1)
    [PLAT_OTP_ID_NV_COUNTER_BL2_1] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[1]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 2)
    [PLAT_OTP_ID_NV_COUNTER_BL2_2] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[2]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 3)
    [PLAT_OTP_ID_NV_COUNTER_BL2_3] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[3]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 4)
    [PLAT_OTP_ID_NV_COUNTER_BL2_4] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[4]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 5)
    [PLAT_OTP_ID_NV_COUNTER_BL2_5] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[5]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 6)
    [PLAT_OTP_ID_NV_COUNTER_BL2_6] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[6]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 7)
    [PLAT_OTP_ID_NV_COUNTER_BL2_7] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[7]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 8)
    [PLAT_OTP_ID_NV_COUNTER_BL2_8] = USER_AREA_OFFSET(unlocked_area.bl2_nv_counter[8]),
#endif

#ifdef PLATFORM_HAS_PS_NV_OTP_COUNTERS
    [PLAT_OTP_ID_NV_COUNTER_PS_0] = USER_AREA_OFFSET(unlocked_area.ps_nv_counter[0]),
    [PLAT_OTP_ID_NV_COUNTER_PS_1] = USER_AREA_OFFSET(unlocked_area.ps_nv_counter[1]),
    [PLAT_OTP_ID_NV_COUNTER_PS_2] = USER_AREA_OFFSET(unlocked_area.ps_nv_counter[2]),
#endif /* PLATFORM_HAS_PS_NV_OTP_COUNTERS */

    [PLAT_OTP_ID_NV_COUNTER_NS_0] = USER_AREA_OFFSET(unlocked_area.host_nv_counter[0]),
    [PLAT_OTP_ID_NV_COUNTER_NS_1] = USER_AREA_OFFSET(unlocked_area.host_nv_counter[1]),
    [PLAT_OTP_ID_NV_COUNTER_NS_2] = USER_AREA_OFFSET(unlocked_area.host_nv_counter[2]),

    [PLAT_OTP_ID_KEY_BL2_ENCRYPTION] = USER_AREA_OFFSET(dm_locked.dm_encrypted.bl2_encryption_key),

    [PLAT_OTP_ID_BL1_2_IMAGE] = USER_AREA_OFFSET(bl1_2_image),
    [PLAT_OTP_ID_BL1_2_IMAGE_LEN] = USER_AREA_OFFSET(cm_locked.bl1_2_image_len),
    [PLAT_OTP_ID_BL1_2_IMAGE_HASH] = OTP_OFFSET(rotpk),
    [PLAT_OTP_ID_BL1_ROTPK_0] = USER_AREA_OFFSET(dm_locked.bl1_rotpk_0),

    [PLAT_OTP_ID_NV_COUNTER_BL1_0] = USER_AREA_OFFSET(unlocked_area.bl1_nv_counter),

    [PLAT_OTP_ID_REPROVISIONING_BITS] = USER_AREA_OFFSET(unlocked_area.reprovisioning_bits),

    [PLAT_OTP_ID_SAM_CONFIG] = USER_AREA_OFFSET(cm_locked.sam_configuration),

    [PLAT_OTP_ID_CM_CONFIG_FLAGS] = USER_AREA_OFFSET(cm_locked.cm_config_flags),
    [PLAT_OTP_ID_DM_CONFIG_FLAGS] = USER_AREA_OFFSET(dm_locked.dm_config_flags),
    [PLAT_OTP_ID_BOOT_SEED] = USER_AREA_OFFSET(dm_locked.boot_seed),
    [PLAT_OTP_ID_CERT_REF] = USER_AREA_OFFSET(dm_locked.cert_ref),
    [PLAT_OTP_ID_ENTROPY_SEED] = USER_AREA_OFFSET(dm_locked.entropy_seed),
};

static const uint16_t otp_sizes[PLAT_OTP_ID_MAX] = {
    [PLAT_OTP_ID_HUK] = OTP_SIZE(huk),
    [PLAT_OTP_ID_GUK] = OTP_SIZE(guk),

    [PLAT_OTP_ID_LCS] = sizeof(uint32_t),

    [PLAT_OTP_ID_IAK_LEN] = USER_AREA_SIZE(dm_locked.iak_len),
    [PLAT_OTP_ID_IAK_TYPE] = USER_AREA_SIZE(dm_locked.iak_type),
    [PLAT_OTP_ID_IAK_ID] = USER_AREA_SIZE(dm_locked.iak_id),

    [PLAT_OTP_ID_IMPLEMENTATION_ID] = USER_AREA_SIZE(dm_locked.implementation_id),
    [PLAT_OTP_ID_VERIFICATION_SERVICE_URL] = USER_AREA_SIZE(dm_locked.verification_service_url),
    [PLAT_OTP_ID_PROFILE_DEFINITION] = USER_AREA_SIZE(dm_locked.profile_definition),

    [PLAT_OTP_ID_BL2_ROTPK_0] = USER_AREA_SIZE(dm_locked.bl2_rotpk[0]),
#if (MCUBOOT_IMAGE_NUMBER > 1)
    [PLAT_OTP_ID_BL2_ROTPK_1] = USER_AREA_SIZE(dm_locked.bl2_rotpk[1]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 2)
    [PLAT_OTP_ID_BL2_ROTPK_2] = USER_AREA_SIZE(dm_locked.bl2_rotpk[2]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 3)
    [PLAT_OTP_ID_BL2_ROTPK_3] = USER_AREA_SIZE(dm_locked.bl2_rotpk[3]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 4)
    [PLAT_OTP_ID_BL2_ROTPK_4] = USER_AREA_SIZE(dm_locked.bl2_rotpk[4]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 5)
    [PLAT_OTP_ID_BL2_ROTPK_5] = USER_AREA_SIZE(dm_locked.bl2_rotpk[5]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 6)
    [PLAT_OTP_ID_BL2_ROTPK_6] = USER_AREA_SIZE(dm_locked.bl2_rotpk[6]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 7)
    [PLAT_OTP_ID_BL2_ROTPK_7] = USER_AREA_SIZE(dm_locked.bl2_rotpk[7]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 8)
    [PLAT_OTP_ID_BL2_ROTPK_8] = USER_AREA_SIZE(dm_locked.bl2_rotpk[8]),
#endif

    [PLAT_OTP_ID_NV_COUNTER_BL2_0] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[0]),
#if (MCUBOOT_IMAGE_NUMBER > 1)
    [PLAT_OTP_ID_NV_COUNTER_BL2_1] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[1]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 2)
    [PLAT_OTP_ID_NV_COUNTER_BL2_2] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[2]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 3)
    [PLAT_OTP_ID_NV_COUNTER_BL2_3] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[3]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 4)
    [PLAT_OTP_ID_NV_COUNTER_BL2_4] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[4]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 5)
    [PLAT_OTP_ID_NV_COUNTER_BL2_5] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[5]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 6)
    [PLAT_OTP_ID_NV_COUNTER_BL2_6] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[6]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 7)
    [PLAT_OTP_ID_NV_COUNTER_BL2_7] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[7]),
#endif
#if (MCUBOOT_IMAGE_NUMBER > 8)
    [PLAT_OTP_ID_NV_COUNTER_BL2_8] = USER_AREA_SIZE(unlocked_area.bl2_nv_counter[8]),
#endif

#ifdef PLATFORM_HAS_PS_NV_OTP_COUNTERS
    [PLAT_OTP_ID_NV_COUNTER_PS_0] = USER_AREA_SIZE(unlocked_area.ps_nv_counter[0]),
    [PLAT_OTP_ID_NV_COUNTER_PS_1] = USER_AREA_SIZE(unlocked_area.ps_nv_counter[1]),
    [PLAT_OTP_ID_NV_COUNTER_PS_2] = USER_AREA_SIZE(unlocked_area.ps_nv_counter[2]),
#endif /* PLATFORM_HAS_PS_NV_OTP_COUNTERS */

    [PLAT_OTP_ID_NV_COUNTER_NS_0] = USER_AREA_SIZE(unlocked_area.host_nv_counter[0]),
    [PLAT_OTP_ID_NV_COUNTER_NS_1] = USER_AREA_SIZE(unlocked_area.host_nv_counter[1]),
    [PLAT_OTP_ID_NV_COUNTER_NS_2] = USER_AREA_SIZE(unlocked_area.host_nv_counter[2]),

    [PLAT_OTP_ID_KEY_BL2_ENCRYPTION] = USER_AREA_SIZE(dm_locked.dm_encrypted.bl2_encryption_key),

    [PLAT_OTP_ID_BL1_2_IMAGE] = USER_AREA_SIZE(bl1_2_image),
    [PLAT_OTP_ID_BL1_2_IMAGE_LEN] = USER_AREA_SIZE(cm_locked.bl1_2_image_len),
    [PLAT_OTP_ID_BL1_2_IMAGE_HASH] = OTP_SIZE(rotpk),
    [PLAT_OTP_ID_BL1_ROTPK_0] = USER_AREA_SIZE(dm_locked.bl1_rotpk_0),

    [PLAT_OTP_ID_NV_COUNTER_BL1_0] = USER_AREA_SIZE(unlocked_area.bl1_nv_counter),

    [PLAT_OTP_ID_REPROVISIONING_BITS] = USER_AREA_SIZE(unlocked_area.reprovisioning_bits),

    [PLAT_OTP_ID_SAM_CONFIG] = USER_AREA_SIZE(cm_locked.sam_configuration),

    [PLAT_OTP_ID_CM_CONFIG_FLAGS] = USER_AREA_SIZE(cm_locked.cm_config_flags),
    [PLAT_OTP_ID_DM_CONFIG_FLAGS] = USER_AREA_SIZE(dm_locked.dm_config_flags),
    [PLAT_OTP_ID_BOOT_SEED] = USER_AREA_SIZE(dm_locked.boot_seed),
    [PLAT_OTP_ID_CERT_REF] = USER_AREA_SIZE(dm_locked.cert_ref),
    [PLAT_OTP_ID_ENTROPY_SEED] = USER_AREA_SIZE(dm_locked.entropy_seed),

};

static uint32_t count_buffer_zero_bits(const uint8_t* buf, size_t size)
{
    size_t byte_index;
    uint8_t byte;
    uint32_t one_count = 0;

    for (byte_index = 0; byte_index < size; byte_index++) {
        byte = buf[byte_index];
        for (int bit_index = 0; bit_index < 8; bit_index++) {
            one_count += (byte >> bit_index) & 1;
        }
    }

    return (size * 8) - one_count;
}

static enum tfm_plat_err_t otp_read(uint32_t offset, uint32_t len,
                                    uint32_t buf_len, uint8_t *buf)
{
    if (buf_len < len) {
        len = buf_len;
    }

    if (lcm_otp_read(&LCM_DEV_S, offset, len, buf) != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    } else {
        return TFM_PLAT_ERR_SUCCESS;
    }
}

static enum tfm_plat_err_t otp_read_encrypted(uint32_t offset, uint32_t len,
                                              uint32_t buf_len, uint8_t *buf)
{
#ifndef ENCRYPTED_OTP_KEYS
    return otp_read(offset, len, buf_len, buf);
#else
    /* This is designed for keys, so 32 is a sane limit */
    uint32_t tmp_buf[32 / sizeof(uint32_t)];
    uint32_t iv[4] = {offset, 0, 0, 0};
    cc3xx_err_t cc_err;
    enum tfm_plat_err_t plat_err;

    if (len > sizeof(tmp_buf)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    plat_err = otp_read(offset, len, sizeof(tmp_buf), (uint8_t *)tmp_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    cc_err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_DECRYPT, CC3XX_AES_MODE_CTR,
                                     KMU_HW_SLOT_KCE_CM, NULL, CC3XX_AES_KEYSIZE_256,
                                     iv, sizeof(iv));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    cc3xx_lowlevel_aes_set_output_buffer(buf, buf_len);

    cc_err = cc3xx_lowlevel_aes_update((uint8_t *)tmp_buf, len);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        cc3xx_lowlevel_aes_uninit();
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    cc3xx_lowlevel_aes_finish(NULL, NULL);

    return TFM_PLAT_ERR_SUCCESS;
#endif
}

static enum tfm_plat_err_t otp_write(uint32_t offset, uint32_t len,
                                     uint32_t buf_len, const uint8_t *buf)
{
    enum lcm_error_t err;

    if (buf_len > len) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    err = lcm_otp_write(&LCM_DEV_S, offset, buf_len, buf);
    if (err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t otp_write_encrypted(uint32_t offset, uint32_t len,
                                     uint32_t buf_len, const uint8_t *buf)
{
#ifndef ENCRYPTED_OTP_KEYS
    return otp_write(offset, len, buf_len, buf);
#else
    /* This is designed for keys, so 32 is a sane limit */
    uint32_t tmp_buf[32 / sizeof(uint32_t)];
    uint32_t iv[4] = {offset, 0, 0, 0};
    cc3xx_err_t cc_err;
    enum tfm_plat_err_t plat_err;

    if (len > sizeof(tmp_buf)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    cc_err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT, CC3XX_AES_MODE_CTR,
                                     KMU_HW_SLOT_KCE_CM, NULL, CC3XX_AES_KEYSIZE_256,
                                     iv, sizeof(iv));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    cc3xx_lowlevel_aes_set_output_buffer((uint8_t *)tmp_buf, sizeof(tmp_buf));

    cc_err = cc3xx_lowlevel_aes_update(buf, len);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        cc3xx_lowlevel_aes_uninit();
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    cc3xx_lowlevel_aes_finish(NULL, NULL);

    plat_err = otp_write(offset, len, sizeof(tmp_buf), (uint8_t *)tmp_buf);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    cc3xx_secure_erase_buffer((uint8_t *)tmp_buf, sizeof(tmp_buf) / sizeof(uint32_t));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
#endif
}

static uint32_t count_otp_zero_bits(uint32_t offset, uint32_t len)
{
    uint8_t buf[128];
    uint32_t zero_count = 0;

    while (len > sizeof(buf)) {
        otp_read(offset, sizeof(buf), sizeof(buf), buf);
        zero_count += count_buffer_zero_bits(buf, sizeof(buf));
        len -= sizeof(buf);
        offset += sizeof(buf);
    }

    otp_read(offset, len, len, buf);
    zero_count += count_buffer_zero_bits(buf, len);

    return zero_count;
}

static enum tfm_plat_err_t verify_zero_bits_count(uint32_t offset,
                                                  uint32_t len_offset,
                                                  uint32_t len_zero_count_offset,
                                                  uint32_t zero_count_offset)
{
    enum lcm_error_t lcm_err;
    uint32_t zero_count;
    uint32_t len;

    lcm_err = lcm_otp_read(&LCM_DEV_S, len_offset, sizeof(len),
                           (uint8_t*)&len);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, len_zero_count_offset, sizeof(zero_count),
                           (uint8_t*)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (zero_count != count_buffer_zero_bits((uint8_t *)&len, sizeof(len))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, zero_count_offset, sizeof(zero_count),
                           (uint8_t*)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (zero_count != count_otp_zero_bits(offset, len)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t check_keys_for_tampering(enum lcm_lcs_t lcs)
{
    enum lcm_error_t lcm_err;
    enum tfm_plat_err_t err;
    uint32_t cm_locked_size;

    if (lcs == LCM_LCS_DM || lcs == LCM_LCS_SE) {
            err = verify_zero_bits_count(USER_AREA_OFFSET(cm_locked),
                                         USER_AREA_OFFSET(cm_locked_size),
                                         USER_AREA_OFFSET(cm_locked_size_zero_count),
                                         USER_AREA_OFFSET(cm_zero_count));
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }
    }

    if (lcs == LCM_LCS_SE) {
        /* Already been verified, don't need to check the zero-count */
        lcm_err = lcm_otp_read(&LCM_DEV_S, USER_AREA_OFFSET(cm_locked_size),
                               sizeof(cm_locked_size), (uint8_t*)&cm_locked_size);
        if (lcm_err != LCM_ERROR_NONE) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }

        err = verify_zero_bits_count(USER_AREA_OFFSET(cm_locked) + cm_locked_size,
                                     USER_AREA_OFFSET(dm_locked_size),
                                     USER_AREA_OFFSET(dm_locked_size_zero_count),
                                     USER_AREA_OFFSET(dm_zero_count));
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum lcm_lcs_t map_otp_lcs_to_lcm_lcs(enum plat_otp_lcs_t lcs)
{
    switch (lcs) {
    case PLAT_OTP_LCS_ASSEMBLY_AND_TEST:
        return LCM_LCS_CM;
    case PLAT_OTP_LCS_PSA_ROT_PROVISIONING:
        return LCM_LCS_DM;
    case PLAT_OTP_LCS_SECURED:
        return LCM_LCS_SE;
    case PLAT_OTP_LCS_DECOMMISSIONED:
        return LCM_LCS_RMA;
    default:
        return LCM_LCS_INVALID;
    }
}

static enum plat_otp_lcs_t map_lcm_lcs_to_otp_lcs(enum lcm_lcs_t lcs)
{
    switch (lcs) {
    case LCM_LCS_CM:
        return PLAT_OTP_LCS_ASSEMBLY_AND_TEST;
    case LCM_LCS_DM:
        return PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
    case LCM_LCS_SE:
        return PLAT_OTP_LCS_SECURED;
    case LCM_LCS_RMA:
        return PLAT_OTP_LCS_DECOMMISSIONED;
    default:
        return PLAT_OTP_LCS_UNKNOWN;
    }
}

static enum tfm_plat_err_t otp_read_lcs(size_t out_len, uint8_t *out)
{
    enum lcm_lcs_t lcm_lcs;
    enum plat_otp_lcs_t *lcs = (enum plat_otp_lcs_t*) out;

    if (lcm_get_lcs(&LCM_DEV_S, &lcm_lcs)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (out_len != sizeof(uint32_t)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    *lcs = map_lcm_lcs_to_otp_lcs(lcm_lcs);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_init(void)
{
    uint32_t otp_size;
    enum lcm_error_t err;
    enum lcm_lcs_t lcs;

    err = lcm_init(&LCM_DEV_S);
    if (err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    lcm_get_otp_size(&LCM_DEV_S, &otp_size);
    if (otp_size < OTP_OFFSET(user_data) +
                   sizeof(struct plat_user_area_layout_t)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
    if (OTP_TOTAL_SIZE < OTP_OFFSET(user_data) +
                   sizeof(struct plat_user_area_layout_t)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return check_keys_for_tampering(lcs);
}

#define PLAT_OTP_ID_BL2_ROTPK_MAX PLAT_OTP_ID_BL2_ROTPK_0 + MCUBOOT_IMAGE_NUMBER
#define PLAT_OTP_ID_NV_COUNTER_BL2_MAX \
    PLAT_OTP_ID_NV_COUNTER_BL2_0 + MCUBOOT_IMAGE_NUMBER

enum tfm_plat_err_t tfm_plat_otp_read(enum tfm_otp_element_id_t id,
                                      size_t out_len, uint8_t *out)
{
    enum tfm_plat_err_t err;
    size_t size;

    if (id >= PLAT_OTP_ID_MAX) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (id >= PLAT_OTP_ID_BL2_ROTPK_MAX && id <= PLAT_OTP_ID_BL2_ROTPK_8) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
    if (id >= PLAT_OTP_ID_NV_COUNTER_BL2_MAX && id <= PLAT_OTP_ID_NV_COUNTER_BL2_8) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    switch(id) {
    case PLAT_OTP_ID_LCS:
        return otp_read_lcs(out_len, out);
    case PLAT_OTP_ID_KEY_BL2_ENCRYPTION:
        return otp_read_encrypted(otp_offsets[id], otp_sizes[id], out_len, out);
    case PLAT_OTP_ID_BL1_2_IMAGE:
        err = otp_read(USER_AREA_OFFSET(cm_locked.bl1_2_image_len),
                       USER_AREA_SIZE(cm_locked.bl1_2_image_len),
                       sizeof(size), (uint8_t *)&size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        return otp_read(OTP_TOTAL_SIZE - size, size,
                        out_len, out);
    default:
        return otp_read(otp_offsets[id], otp_sizes[id], out_len, out);
    }
}

static enum tfm_plat_err_t otp_write_lcs(size_t in_len, const uint8_t *in)
{
    enum tfm_plat_err_t err;
    uint32_t lcs;
    enum lcm_lcs_t new_lcs = map_otp_lcs_to_lcm_lcs(*(uint32_t*)in);
    enum lcm_error_t lcm_err;
    uint16_t gppc_val = 0;
    uint32_t zero_bit_count;
    size_t region_size;

    if (in_len != sizeof(lcs)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    switch(new_lcs) {
        case LCM_LCS_DM:
            /* Write the size of the CM locked area */
            region_size = USER_AREA_SIZE(cm_locked);
            err = otp_write(USER_AREA_OFFSET(cm_locked_size),
                            USER_AREA_SIZE(cm_locked_size),
                            sizeof(region_size), (uint8_t *)&region_size);
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }

            /* Write the zero-bit count of the CM locked area size */
            zero_bit_count = count_buffer_zero_bits((uint8_t *)&region_size,
                                                    sizeof(region_size));
            err = otp_write(USER_AREA_OFFSET(cm_locked_size_zero_count),
                            USER_AREA_SIZE(cm_locked_size_zero_count),
                            sizeof(zero_bit_count), (uint8_t *)&zero_bit_count);
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }

            /* Write the zero-count of the CM locked area */
            zero_bit_count = count_otp_zero_bits(USER_AREA_OFFSET(cm_locked),
                                                 region_size);
            err = otp_write(USER_AREA_OFFSET(cm_zero_count),
                            USER_AREA_SIZE(cm_zero_count), sizeof(zero_bit_count),
                            (uint8_t *)&zero_bit_count);
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }
            break;
        case LCM_LCS_SE:
            /* Write the size of the DM locked area */
            region_size = USER_AREA_SIZE(dm_locked);
            err = otp_write(USER_AREA_OFFSET(dm_locked_size),
                            USER_AREA_SIZE(dm_locked_size),
                            sizeof(region_size), (uint8_t *)&region_size);
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }

            /* Write the zero-bit count of the DM locked area size */
            zero_bit_count = count_buffer_zero_bits((uint8_t*)&region_size,
                                                    sizeof(region_size));
            err = otp_write(USER_AREA_OFFSET(dm_locked_size_zero_count),
                            USER_AREA_SIZE(dm_locked_size_zero_count),
                            sizeof(zero_bit_count), (uint8_t *)&zero_bit_count);
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }

            /* Write the zero-count of the DM locked area */
            zero_bit_count = count_otp_zero_bits(USER_AREA_OFFSET(dm_locked),
                                                 region_size);
            err = otp_write(USER_AREA_OFFSET(dm_zero_count),
                            USER_AREA_SIZE(dm_zero_count), sizeof(zero_bit_count),
                            (uint8_t *)&zero_bit_count);
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }
            break;
        case LCM_LCS_RMA:
            break;
        case LCM_LCS_CM:
        case LCM_LCS_INVALID:
            return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    lcm_err = lcm_set_lcs(&LCM_DEV_S, new_lcs, gppc_val);
    if (lcm_err != LCM_ERROR_NONE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_write(enum tfm_otp_element_id_t id,
                                       size_t in_len, const uint8_t *in)
{
    if (id >= PLAT_OTP_ID_MAX) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (id >= PLAT_OTP_ID_BL2_ROTPK_MAX && id <= PLAT_OTP_ID_BL2_ROTPK_8) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
    if (id >= PLAT_OTP_ID_NV_COUNTER_BL2_MAX && id <= PLAT_OTP_ID_NV_COUNTER_BL2_8) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    switch (id) {
    case PLAT_OTP_ID_LCS:
        return otp_write_lcs(in_len, in);
    case PLAT_OTP_ID_KEY_BL2_ENCRYPTION:
        return otp_write_encrypted(otp_offsets[id], otp_sizes[id], in_len, in);
    default:
        return otp_write(otp_offsets[id], otp_sizes[id], in_len, in);
    }
}


enum tfm_plat_err_t tfm_plat_otp_get_size(enum tfm_otp_element_id_t id,
                                          size_t *size)
{
    if (id >= PLAT_OTP_ID_MAX) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (id >= PLAT_OTP_ID_BL2_ROTPK_MAX && id <= PLAT_OTP_ID_BL2_ROTPK_8) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
    if (id >= PLAT_OTP_ID_NV_COUNTER_BL2_MAX && id <= PLAT_OTP_ID_NV_COUNTER_BL2_8) {
        return TFM_PLAT_ERR_UNSUPPORTED;
    }

    *size = otp_sizes[id];

    return TFM_PLAT_ERR_SUCCESS;
}
