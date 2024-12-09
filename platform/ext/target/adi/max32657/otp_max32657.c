/******************************************************************************
 *
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ******************************************************************************/

#include "config_tfm.h"
#include "tfm_plat_otp.h"

#include "region_defs.h"
#include "tfm_hal_device_header.h"
#include "platform_retarget.h"
#include "flc.h"

#include "cmsis_compiler.h"

#define INFOBLOCK_LINE_SIZE 8
#define OTP_KEY_OFFSET  (FLASH_INFO_BASE + 0x3000)


#ifdef BL2
#if defined(MCUBOOT_SIGN_EC384)
#define BL2_ROTPK_HASH_SIZE     (48)
#define BL2_ROTPK_KEY_SIZE      (100) /* Aligned to 4 bytes */
#else
#define BL2_ROTPK_HASH_SIZE     (32)
#endif /* MCUBOOT_SIGN_EC384 */
#if defined(MCUBOOT_SIGN_EC256)
#define BL2_ROTPK_KEY_SIZE      (68)  /* Aligned to 4 bytes */
#endif /* MCUBOOT_SIGN_EC256 */

#ifdef MCUBOOT_BUILTIN_KEY
#define BL2_ROTPK_SIZE    BL2_ROTPK_KEY_SIZE
#else
#define BL2_ROTPK_SIZE    BL2_ROTPK_HASH_SIZE
#endif /* MCUBOOT_BUILTIN_KEY */
#endif /* BL2 */


__PACKED_STRUCT max32657_otp_nv_counters_region_t {
    uint8_t huk[32];
    uint8_t iak[32];
    uint8_t iak_len[4];
    uint8_t iak_type[4];
    uint8_t iak_id[32];

    uint8_t boot_seed[32];
    uint8_t lcs[4];
    uint8_t implementation_id[32];
    uint8_t cert_ref[32];
    uint8_t verification_service_url[32];
    uint8_t profile_definition[32];

    uint8_t bl2_rotpk_0[100];
    uint8_t bl2_rotpk_1[100];
    uint8_t bl2_rotpk_2[100];
    uint8_t bl2_rotpk_3[100];

    uint8_t bl2_nv_counter_0[64];
    uint8_t bl2_nv_counter_1[64];
    uint8_t bl2_nv_counter_2[64];
    uint8_t bl2_nv_counter_3[64];

    uint8_t ns_nv_counter_0[64];
    uint8_t ns_nv_counter_1[64];
    uint8_t ns_nv_counter_2[64];

    uint8_t entropy_seed[64];
    uint8_t secure_debug_pk[32];
};

#define GET_OFFSET(item)  (OTP_KEY_OFFSET + offsetof(struct max32657_otp_nv_counters_region_t, item))
#define GET_SIZE(item) sizeof(((struct max32657_otp_nv_counters_region_t*)0)->item)

struct max32657_otp_element_t {
    uint32_t offset;
    uint8_t len;
};

static const struct max32657_otp_element_t otp_map[] = {
    [PLAT_OTP_ID_HUK] =                      {.offset = GET_OFFSET(huk) ,       .len = GET_SIZE(huk) },
    [PLAT_OTP_ID_IAK] =                      {.offset = GET_OFFSET(iak) ,       .len = GET_SIZE(iak) },
    [PLAT_OTP_ID_IAK_LEN] =                  {.offset = GET_OFFSET(iak_len) ,   .len = GET_SIZE(iak_len) },
    [PLAT_OTP_ID_IAK_TYPE] =                 {.offset = GET_OFFSET(iak_type) ,  .len = GET_SIZE(iak_type) },
    [PLAT_OTP_ID_IAK_ID] =                   {.offset = GET_OFFSET(iak_id) ,    .len = GET_SIZE(iak_id) },
    [PLAT_OTP_ID_BOOT_SEED] =                {.offset = GET_OFFSET(boot_seed) , .len = GET_SIZE(boot_seed) },
    [PLAT_OTP_ID_LCS] =                      {.offset = GET_OFFSET(lcs) ,       .len = GET_SIZE(lcs) },
    [PLAT_OTP_ID_IMPLEMENTATION_ID] =        {.offset = GET_OFFSET(implementation_id) , .len = GET_SIZE(implementation_id) },
    [PLAT_OTP_ID_CERT_REF] =                 {.offset = GET_OFFSET(cert_ref) ,  .len = GET_SIZE(cert_ref) },
    [PLAT_OTP_ID_VERIFICATION_SERVICE_URL] = {.offset = GET_OFFSET(verification_service_url) , .len = GET_SIZE(verification_service_url) },
    [PLAT_OTP_ID_PROFILE_DEFINITION] =       {.offset = GET_OFFSET(profile_definition) , .len = GET_SIZE(profile_definition) },
    [PLAT_OTP_ID_BL2_ROTPK_0] =              {.offset = GET_OFFSET(bl2_rotpk_0) ,       .len = BL2_ROTPK_SIZE },
    [PLAT_OTP_ID_BL2_ROTPK_1] =              {.offset = GET_OFFSET(bl2_rotpk_1) ,       .len = BL2_ROTPK_SIZE },
    [PLAT_OTP_ID_BL2_ROTPK_2] =              {.offset = GET_OFFSET(bl2_rotpk_2) ,       .len = BL2_ROTPK_SIZE },
    [PLAT_OTP_ID_BL2_ROTPK_3] =              {.offset = GET_OFFSET(bl2_rotpk_3) ,       .len = BL2_ROTPK_SIZE },
    [PLAT_OTP_ID_NV_COUNTER_BL2_0] =         {.offset = GET_OFFSET(bl2_nv_counter_0) ,  .len = GET_SIZE(bl2_nv_counter_0) },
    [PLAT_OTP_ID_NV_COUNTER_BL2_1] =         {.offset = GET_OFFSET(bl2_nv_counter_1) ,  .len = GET_SIZE(bl2_nv_counter_1) },
    [PLAT_OTP_ID_NV_COUNTER_BL2_2] =         {.offset = GET_OFFSET(bl2_nv_counter_2) ,  .len = GET_SIZE(bl2_nv_counter_2) },
    [PLAT_OTP_ID_NV_COUNTER_BL2_3] =         {.offset = GET_OFFSET(bl2_nv_counter_3) ,  .len = GET_SIZE(bl2_nv_counter_3) },

    [PLAT_OTP_ID_NV_COUNTER_NS_0] =          {.offset = GET_OFFSET(ns_nv_counter_0) ,   .len = GET_SIZE(ns_nv_counter_0) },
    [PLAT_OTP_ID_NV_COUNTER_NS_1] =          {.offset = GET_OFFSET(ns_nv_counter_1) ,   .len = GET_SIZE(ns_nv_counter_1) },
    [PLAT_OTP_ID_NV_COUNTER_NS_2] =          {.offset = GET_OFFSET(ns_nv_counter_2) ,   .len = GET_SIZE(ns_nv_counter_2) },

    [PLAT_OTP_ID_ENTROPY_SEED] =             {.offset = GET_OFFSET(entropy_seed) ,      .len = GET_SIZE(entropy_seed) },
    [PLAT_OTP_ID_SECURE_DEBUG_PK] =          {.offset = GET_OFFSET(secure_debug_pk) ,   .len = GET_SIZE(secure_debug_pk) },
};


enum tfm_plat_err_t tfm_plat_otp_init(void)
{
    /* Do nothing */
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_read(enum tfm_otp_element_id_t id,
                                      size_t out_len, uint8_t *out)
{
    int i;
    size_t copy_len;

    if (id >= PLAT_OTP_ID_MAX) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    copy_len = (out_len < otp_map[id].len) ? out_len : otp_map[id].len;

    MXC_FLC_Read(otp_map[id].offset, out, copy_len);
    /*
     * TF-M project expect default OTP value be 0x00 and
     * OTP bits able to be transceive from 0 to 1.
     * But MAX32657 OTP default value is 0xff and it transceive from 1 to 0.
     * So that after reading OTP, the bits are reversed.
     */
    for(i = 0; i < copy_len; i++) {
        /* Reverse bits, 1 to 0, 0 to 1 */
        out[i] ^= 0xff;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_write(enum tfm_otp_element_id_t id,
                                       size_t in_len, const uint8_t *in)
{
    enum tfm_plat_err_t ret = TFM_PLAT_ERR_SUCCESS;
    unsigned char buf[INFOBLOCK_LINE_SIZE];
    size_t copy_len;
    int addr;
    int i;

    if (id >= PLAT_OTP_ID_MAX) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (in_len > otp_map[id].len) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    MXC_FLC_UnlockInfoBlock(MXC_INFO_MEM_BASE);

    addr = otp_map[id].offset;
    while( in_len )  {
        copy_len = (in_len < INFOBLOCK_LINE_SIZE) ? in_len: INFOBLOCK_LINE_SIZE;

        /*
         * TF-M project expect default OTP value be 0x00 and
         * OTP bits able to be transceive from 0 to 1.
         * But MAX32657 OTP default value is 0xff and it transceive from 1 to 0.
         * So that Before writing bits are reversed.
         */
        for (i = 0; i < copy_len; i++) {
            /* Reverse bits, 1 to 0, 0 to 1 */
            buf[i] = *in ^ 0xff;
            in++;
        }

        if (MXC_FLC_Write(addr, copy_len, (uint32_t *)buf) != E_NO_ERROR) {
            ret = TFM_PLAT_ERR_SYSTEM_ERR;
            break;
        }

        in_len -= copy_len;
        addr += copy_len;
    }

    MXC_FLC_LockInfoBlock(MXC_INFO_MEM_BASE);

    return ret;
}

enum tfm_plat_err_t tfm_plat_otp_get_size(enum tfm_otp_element_id_t id,
                                          size_t *size)
{
    if (id >= PLAT_OTP_ID_MAX) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    *size = otp_map[id].len;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_secure_provisioning_start(void)
{
    /* Do nothing */
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_secure_provisioning_finish(void)
{
    /* Do nothing */
    return TFM_PLAT_ERR_SUCCESS;
}
