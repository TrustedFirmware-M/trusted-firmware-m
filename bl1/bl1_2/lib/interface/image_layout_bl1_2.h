/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __IMAGE_LAYOUT_H__
#define __IMAGE_LAYOUT_H__

#include "region_defs.h"
#include <stdint.h>
#include "bl1_2_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_BL1_2_IMAGE_DECRYPT_MAGIC_EXPECTED 0xDEADBEEF

#ifndef __PACKED_STRUCT
#define __PACKED_STRUCT struct __attribute__((packed))
#endif /* __PACKED_STRUCT */

#ifndef __PACKED_UNION
#define __PACKED_UNION union __attribute__((packed))
#endif /* __PACKED_UNION */

__PACKED_STRUCT tfm_bl1_image_version_t {
    uint8_t  major;
    uint8_t  minor;
    uint16_t revision;
    uint32_t build_num;
};

__PACKED_STRUCT tfm_bl1_image_signature_t{
#ifdef TFM_BL1_2_EMBED_ROTPK_IN_IMAGE
    uint8_t rotpk[TFM_BL1_2_ROTPK_MAX_SIZE];
    uint32_t rotpk_len;
#endif
    uint8_t sig[TFM_BL1_2_SIG_MAX_SIZE];
    uint32_t sig_len;
};

__PACKED_STRUCT bl1_2_image_t {
    __PACKED_UNION {
        __PACKED_STRUCT {
            __PACKED_STRUCT  {
#ifdef TFM_BL1_2_IMAGE_ENCRYPTION
                uint8_t ctr_iv[16];
#endif
#ifdef TFM_BL1_2_IMAGE_BINDING
                uint8_t binding_tag[16];
#endif /* TFM_BL1_2_IMAGE_BINDING */
                struct tfm_bl1_image_signature_t sigs[TFM_BL1_2_SIGNER_AMOUNT];
            } header;
            __PACKED_STRUCT {
                struct tfm_bl1_image_version_t version;
                uint32_t security_counter;

                __PACKED_STRUCT {
#ifdef TFM_BL1_2_IMAGE_ENCRYPTION
                    uint32_t decrypt_magic;
#endif
                    uint8_t data[IMAGE_BL2_CODE_SIZE];
                } encrypted_data;
            } protected_values;
        };
        uint8_t raw[IMAGE_BL2_CODE_SIZE + TFM_BL1_2_HEADER_MAX_SIZE];
    };
};


#ifdef __cplusplus
}
#endif

#endif /* __IMAGE_LAYOUT_H__ */
