/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef BL1_2_IMAGE_H
#define BL1_2_IMAGE_H

#include <stddef.h>
#include <stdint.h>
#include "cmsis_compiler.h"
#include "mbedtls/lms.h"
#include "fih.h"
#include "image_layout_bl1_2.h"
#include "Driver_Flash.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BL1_2_HEADER_SIZE (offsetof(struct bl1_2_image_t, protected_values.encrypted_data.data))

#if defined(TFM_BL1_2_IMAGE_BINDING) && defined(TFM_BL1_2_IMAGE_ENCRYPTION)

#define FLASH_PAGE_SIZE      1024U
#define FLASH_SECTOR_SIZE    (4U * 1024U)
#define FLASH_ERASE_BLOCK    (64U * 1024U)

typedef struct {
    uintptr_t region_base;   /* flash start of protected_values */
    size_t    region_len;    /* total bytes to rewrite */
    uintptr_t erased_to;     /* [region_base, erased_to) already erased (block aligned) */
} flash_bind_ctx_t;
#endif

/**
 *
 * @param image_id
 * @return uint32_t
 */
uint32_t bl1_image_get_flash_offset(uint32_t image_id);

/**
 * @brief
 *
 * @param image_id
 * @param out
 * @return fih_int
 */
fih_ret bl1_image_copy_to_sram(uint32_t image_id, uint8_t *out);

/**
 * @brief BL1_2 selects the active BL2 image
 *
 * @note This function must call FIH_PANIC if no active image is available.
 *       It must NOT return an invalid image index.
 *
 * @return The active image index in fih_init type
 */
fih_int bl1_2_select_image(void);

/**
 * @brief BL1_2 rolls back to the previous BL2 image
 *
 * @note This function must call FIH_PANIC if it failed to roll back images.
 *       It must NOT return an invalid image index.
 *
 * @return The image index in fih_init type
 */
fih_int bl1_2_rollback_image(void);

#if defined(TFM_BL1_2_IMAGE_BINDING)

/**
 * @brief Store the image binding tag for a BL2 image.
 *
 * This function persists a 16-byte binding tag for the BL2 image identified
 * by image_id. The tag is used to bind BL1_2 to a particular BL2 image and
 * must be stored in non-volatile storage (for example, flash) so it survives
 * resets and firmware updates.
 *
 * @param image_id  Image index identifying the BL2 image
 * @param image     Pointer to the BL2 image structure associated with image_id
 * @param tag       16-byte image binding tag to store
 * @return FIH_SUCCESS on success; FIH_FAILURE on error
 */
fih_ret bl1_2_store_image_binding_tag(uint32_t image_id,
                                      struct bl1_2_image_t *image,
                                      const uint8_t tag[16]);

#ifdef TFM_BL1_2_IMAGE_ENCRYPTION
typedef struct {
    ARM_DRIVER_FLASH *flash;
    uintptr_t region_base;    /* start of flash region to overwrite */
    size_t    region_len;     /* total bytes to overwrite */
    uintptr_t cur;            /* current write cursor */
    uintptr_t region_end;     /* region_base + region_len */
    uint32_t  sector_size;    /* flash sector_size */
    uint32_t  prog_unit;      /* flash program_unit */
    uint8_t  *sector_buf;     /* RAM buffer of size sector_size */
} bl1_2_image_flash_bind_ctx_t;

/**
 * @brief Begins the binding process for a flash image region.
 *
 * Initializes the context for binding a flash image region, preparing it for subsequent operations.
 * The function sets up the working context with the specified region base address, region length,
 * and a buffer for sector operations.
 *
 * @param w                Pointer to the flash bind context structure to initialize.
 * @param region_base      Base address of the flash region to bind.
 * @param region_len       Length of the flash region to bind.
 * @param sector_buf       Pointer to the buffer used for sector operations.
 * @param sector_buf_len   Length of the sector buffer.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int bl1_2_image_flash_bind_begin(bl1_2_image_flash_bind_ctx_t *w,
                                 uintptr_t region_base,
                                 size_t    region_len,
                                 uint8_t  *sector_buf,
                                 size_t    sector_buf_len);

/**
 * @brief Writes data to the flash image using the provided context.
 *
 * This function writes a buffer of data to the flash image associated with the
 * given write context. The context maintains the state required for the write
 * operation. The function attempts to write 'len' bytes from 'buf' to the flash.
 *
 * @param w   Pointer to the flash bind write context.
 * @param buf Pointer to the buffer containing data to be written.
 * @param len Number of bytes to write from the buffer.
 *
 * @return 0 on success, or a negative error code on failure.
 */
int bl1_2_image_flash_bind_write(bl1_2_image_flash_bind_ctx_t *w,
                                 const uint8_t *buf,
                                 size_t len);

/**
 * @brief Copies the header of the specified image into the provided image structure.
 *
 * This function retrieves the header information for the image identified by
 * `image_id` and copies it into the memory pointed to by `image`. The function
 * returns a status code indicating the success or failure of the operation.
 *
 * @param[in]  image_id  Identifier of the image whose header is to be copied.
 * @param[out] image     Pointer to a bl1_2_image_t structure where the image header will be stored.
 *
 * @return fih_ret       Status code indicating the result of the copy operation.
 */
fih_ret bl1_2_copy_image_header(uint32_t image_id, struct bl1_2_image_t *image);

#endif /* TFM_BL1_2_IMAGE_ENCRYPTION */
#endif /* TFM_BL1_2_IMAGE_BINDING */

#ifdef __cplusplus
}
#endif

#endif /* BL1_2_IMAGE_H */
