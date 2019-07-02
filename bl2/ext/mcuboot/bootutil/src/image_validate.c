/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Original code taken from mcuboot project at:
 * https://github.com/JuulLabs-OSS/mcuboot
 * Git SHA of the original version: 178be54bd6e5f035cc60e98205535682acd26e64
 * Modifications are Copyright (c) 2018-2019 Arm Limited.
 */

#include <assert.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>

#include "flash_map/flash_map.h"
#include "bootutil/image.h"
#include "bootutil/sha256.h"
#include "bootutil/sign_key.h"
#include "security_cnt.h"

#ifdef MCUBOOT_SIGN_RSA
#include "mbedtls/rsa.h"
#endif

#include "mbedtls/asn1.h"

#include "bootutil_priv.h"

/*
 * Compute SHA256 over the image.
 */
static int
bootutil_img_hash(struct image_header *hdr, const struct flash_area *fap,
                  uint8_t *tmp_buf, uint32_t tmp_buf_sz,
                  uint8_t *hash_result, uint8_t *seed, int seed_len)
{
    bootutil_sha256_context sha256_ctx;
    uint32_t blk_sz;
    uint32_t size;
    uint32_t off;

    bootutil_sha256_init(&sha256_ctx);

    /* in some cases (split image) the hash is seeded with data from
     * the loader image */
    if (seed && (seed_len > 0)) {
        bootutil_sha256_update(&sha256_ctx, seed, seed_len);
    }

    /* Hash is computed over image header and image itself. */
    size = hdr->ih_img_size + hdr->ih_hdr_size;

    /* If a security counter TLV is present then the TLV info header and the
     * security counter are also protected and must be included in the hash
     * calculation.
     */
    if (hdr->ih_protect_tlv_size != 0) {
        size += hdr->ih_protect_tlv_size;
    }

    for (off = 0; off < size; off += blk_sz) {
        blk_sz = size - off;
        if (blk_sz > tmp_buf_sz) {
            blk_sz = tmp_buf_sz;
        }

#ifdef MCUBOOT_RAM_LOADING
        if (fap == NULL) { /* The image is in SRAM */
            memcpy(tmp_buf, (uint32_t *)(hdr->ih_load_addr + off), blk_sz);
        } else { /* The image is in flash */
#endif
            if(flash_area_read(fap, off, tmp_buf, blk_sz)) {
                return -1;
            }
#ifdef MCUBOOT_RAM_LOADING
        }
#endif

        bootutil_sha256_update(&sha256_ctx, tmp_buf, blk_sz);
    }
    bootutil_sha256_finish(&sha256_ctx, hash_result);

    return 0;
}

/*
 * Currently, we only support being able to verify one type of
 * signature, because there is a single verification function that we
 * call.  List the type of TLV we are expecting.  If we aren't
 * configured for any signature, don't define this macro.
 */

#if defined(MCUBOOT_SIGN_RSA)
#    if MCUBOOT_SIGN_RSA_LEN == 2048
#        define EXPECTED_SIG_TLV IMAGE_TLV_RSA2048_PSS
#    elif MCUBOOT_SIGN_RSA_LEN == 3072
#        define EXPECTED_SIG_TLV IMAGE_TLV_RSA3072_PSS
#    else
#        error "Unsupported RSA signature length"
#    endif
#    define SIG_BUF_SIZE (MCUBOOT_SIGN_RSA_LEN / 8)
#    define EXPECTED_SIG_LEN(x) ((x) == SIG_BUF_SIZE)
#else
#    define SIG_BUF_SIZE 32 /* no signing, sha256 digest only */
#endif

#ifdef EXPECTED_SIG_TLV
static int
bootutil_find_key(uint8_t *keyhash, uint8_t keyhash_len)
{
    bootutil_sha256_context sha256_ctx;
    int i;
    const struct bootutil_key *key;
    uint8_t hash[32];

    assert(keyhash_len <= 32);

    for (i = 0; i < bootutil_key_cnt; i++) {
        key = &bootutil_keys[i];
        bootutil_sha256_init(&sha256_ctx);
        bootutil_sha256_update(&sha256_ctx, key->key, *key->len);
        bootutil_sha256_finish(&sha256_ctx, hash);
        if (!memcmp(hash, keyhash, keyhash_len)) {
            return i;
        }
    }
    return -1;
}
#endif

#ifdef MCUBOOT_RAM_LOADING
/* Check the hash of an image after it has been copied to SRAM */
int
bootutil_check_hash_after_loading(struct image_header *hdr)
{
    uint32_t off;
    uint32_t end;
    int sha256_valid = 0;
    struct image_tlv_info info;
    struct image_tlv tlv;
    uint8_t tmp_buf[BOOT_TMPBUF_SZ];
    uint8_t hash[32] = {0};
    int rc;
    uint32_t load_address;
    uint32_t tlv_sz;

    rc = bootutil_img_hash(hdr, NULL, tmp_buf, BOOT_TMPBUF_SZ, hash, NULL, 0);

    if (rc) {
        return rc;
    }

    load_address = (uint32_t) hdr->ih_load_addr;

    /* The TLVs come after the image. */
    off = hdr->ih_img_size + hdr->ih_hdr_size;

    info = *((struct image_tlv_info *)(load_address + off));

    if (info.it_magic != IMAGE_TLV_INFO_MAGIC) {
        return BOOT_EBADMAGIC;
    }
    end = off + info.it_tlv_tot;
    off += sizeof(info);

    /*
     * Traverse through all of the TLVs, performing any checks we know
     * and are able to do.
     */
    while (off < end) {
        tlv = *((struct image_tlv *)(load_address + off));
        tlv_sz = sizeof(tlv);

        if (tlv.it_type == IMAGE_TLV_SHA256) {
            /*
             * Verify the SHA256 image hash. This must always be present.
             */
            if (tlv.it_len != sizeof(hash)) {
                return -1;
            }

            if (memcmp(hash, (uint32_t *)(load_address + off + tlv_sz),
                       sizeof(hash))) {
                return -1;
            }

            sha256_valid = 1;
        }

        /* Avoid integer overflow. */
        if ((UINT32_MAX - off) < (sizeof(tlv) + tlv.it_len)) {
            /* Potential overflow. */
            break;
        } else {
            off += sizeof(tlv) + tlv.it_len;
        }
    }

    if (!sha256_valid) {
        return -1;
    }

    return 0;
}
#endif /* MCUBOOT_RAM_LOADING */

/**
 * Reads the value of an image's security counter.
 *
 * @param hdr           Pointer to the image header structure.
 * @param fap           Pointer to a description structure of the image's
 *                      flash area.
 * @param security_cnt  Pointer to store the security counter value.
 *
 * @return              0 on success; nonzero on failure.
 */
int32_t
bootutil_get_img_security_cnt(struct image_header *hdr,
                              const struct flash_area *fap,
                              uint32_t *img_security_cnt)
{
    struct image_tlv_info info;
    struct image_tlv tlv;
    uint32_t off;
    uint32_t end;
    uint32_t found = 0;
    int32_t rc;

    if ((hdr == NULL) ||
        (fap == NULL) ||
        (img_security_cnt == NULL)) {
        /* Invalid parameter. */
        return BOOT_EBADARGS;
    }

    /* The TLVs come after the image. */
    off = hdr->ih_hdr_size + hdr->ih_img_size;

    /* The TLV area always starts with an image_tlv_info structure. */
    rc = flash_area_read(fap, off, &info, sizeof(info));
    if (rc != 0) {
        return BOOT_EFLASH;
    }

    if (info.it_magic != IMAGE_TLV_INFO_MAGIC) {
        return BOOT_EBADMAGIC;
    }

    /* The security counter TLV is in the protected part of the TLV area. */
    if (hdr->ih_protect_tlv_size != 0) {
        end = off + (uint32_t)hdr->ih_protect_tlv_size;
        off += sizeof(info);

        /* Traverse through the protected TLV area to find the
         * security counter TLV.
         */
        while (off < end) {
            rc = flash_area_read(fap, off, &tlv, sizeof(tlv));
            if (rc != 0) {
                return BOOT_EFLASH;
            }

            if (tlv.it_type == IMAGE_TLV_SEC_CNT) {

                if (tlv.it_len != sizeof(*img_security_cnt)) {
                    /* Security counter is not valid. */
                    break;
                }

                rc = flash_area_read(fap, off + sizeof(tlv),
                                     img_security_cnt, tlv.it_len);
                if (rc != 0) {
                    return BOOT_EFLASH;
                }

                /* Security counter has been found. */
                found = 1;
                break;
            }

            /* Avoid integer overflow. */
            if ((UINT32_MAX - off) < (sizeof(tlv) + tlv.it_len)) {
                /* Potential overflow. */
                break;
            } else {
                off += sizeof(tlv) + tlv.it_len;
            }
        }
    }

    if (found) {
        return 0;
    }

    return -1;
}

/*
 * Verify the integrity of the image.
 * Return non-zero if image could not be validated/does not validate.
 */
int
bootutil_img_validate(struct image_header *hdr, const struct flash_area *fap,
                      uint8_t *tmp_buf, uint32_t tmp_buf_sz,
                      uint8_t *seed, int seed_len, uint8_t *out_hash)
{
    uint32_t off;
    uint32_t end;
    int sha256_valid = 0;
    struct image_tlv_info info;
#ifdef EXPECTED_SIG_TLV
    int valid_signature = 0;
    int key_id = -1;
#endif
    struct image_tlv tlv;
    uint8_t buf[SIG_BUF_SIZE];
    uint8_t hash[32] = {0};
    uint32_t security_cnt;
    uint32_t img_security_cnt;
    int32_t security_counter_valid = 0;
    int rc;

    rc = bootutil_img_hash(hdr, fap, tmp_buf, tmp_buf_sz, hash,
                           seed, seed_len);
    if (rc) {
        return rc;
    }

    if (out_hash) {
        memcpy(out_hash, hash, 32);
    }

    /* The TLVs come after the image. */
    off = hdr->ih_img_size + hdr->ih_hdr_size;

    rc = flash_area_read(fap, off, &info, sizeof(info));
    if (rc) {
        return rc;
    }
    if (info.it_magic != IMAGE_TLV_INFO_MAGIC) {
        return BOOT_EBADMAGIC;
    }
    end = off + info.it_tlv_tot;
    off += sizeof(info);

    /*
     * Traverse through all of the TLVs, performing any checks we know
     * and are able to do.
     */
    while (off < end) {
        rc = flash_area_read(fap, off, &tlv, sizeof(tlv));
        if (rc) {
            return rc;
        }

        if (tlv.it_type == IMAGE_TLV_SHA256) {
            /*
             * Verify the SHA256 image hash.  This must always be
             * present.
             */
            if (tlv.it_len != sizeof(hash)) {
                return -1;
            }
            rc = flash_area_read(fap, off + sizeof(tlv), buf, sizeof(hash));
            if (rc) {
                return rc;
            }
            if (memcmp(hash, buf, sizeof(hash))) {
                return -1;
            }

            sha256_valid = 1;
#ifdef EXPECTED_SIG_TLV
        } else if (tlv.it_type == IMAGE_TLV_KEYHASH) {
            /*
             * Determine which key we should be checking.
             */
            if (tlv.it_len > 32) {
                return -1;
            }
            rc = flash_area_read(fap, off + sizeof(tlv), buf, tlv.it_len);
            if (rc) {
                return rc;
            }
            key_id = bootutil_find_key(buf, tlv.it_len);
            /*
             * The key may not be found, which is acceptable.  There
             * can be multiple signatures, each preceded by a key.
             */
        } else if (tlv.it_type == EXPECTED_SIG_TLV) {
            /* Ignore this signature if it is out of bounds. */
            if (key_id < 0 || key_id >= bootutil_key_cnt) {
                key_id = -1;
                continue;
            }
            if (!EXPECTED_SIG_LEN(tlv.it_len) || tlv.it_len > sizeof(buf)) {
                return -1;
            }
            rc = flash_area_read(fap, off + sizeof(tlv), buf, tlv.it_len);
            if (rc) {
                return -1;
            }
            rc = bootutil_verify_sig(hash, sizeof(hash), buf, tlv.it_len,
                                     key_id);
            if (rc == 0) {
                valid_signature = 1;
            }
            key_id = -1;
#endif
        } else if (tlv.it_type == IMAGE_TLV_SEC_CNT) {
            /*
             * Verify the image's security counter.
             * This must always be present.
             */
            if (tlv.it_len != sizeof(img_security_cnt)) {
                /* Security counter is not valid. */
                return -1;
            }

            rc = flash_area_read(fap, off + sizeof(tlv),
                                 &img_security_cnt, tlv.it_len);
            if (rc) {
                return rc;
            }

            rc = boot_nv_security_counter_get(0, &security_cnt);
            if (rc) {
                return rc;
            }

            /* Compare the new image's security counter value against the
             * stored security counter value.
             */
            if (img_security_cnt < security_cnt) {
                /* The image's security counter is not accepted. */
                return -1;
            }

            /* The image's security counter has been successfully verified. */
            security_counter_valid = 1;
        }

        /* Avoid integer overflow. */
        if ((UINT32_MAX - off) < (sizeof(tlv) + tlv.it_len)) {
            /* Potential overflow. */
            break;
        } else {
            off += sizeof(tlv) + tlv.it_len;
        }
    }

    if (!sha256_valid || !security_counter_valid) {
        return -1;
    }

#ifdef EXPECTED_SIG_TLV
    if (!valid_signature) {
        return -1;
    }
#endif

    return 0;
}
