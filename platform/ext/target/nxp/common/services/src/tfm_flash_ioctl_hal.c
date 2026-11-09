/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_platform_system.h"
#include "platform_description.h"
#include "device_definition.h"
#include "flash_layout.h"
#include "platform_base_address.h"
#include "tfm_ioctl_api.h"
#include <arm_cmse.h>
#include "tfm_flash_ioctl_hal.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

static flash_config_t s_flash_config;
static bool           s_flash_init_done = false;

static enum tfm_platform_err_t ensure_flash_init(void)
{
    if (!s_flash_init_done) {
        (void)memset(&s_flash_config, 0, sizeof(s_flash_config));
        if (FLASH_Init(&s_flash_config) != (status_t)0) {
            return TFM_PLATFORM_ERR_SYSTEM_ERROR;
        }
        s_flash_init_done = true;
    }
    return TFM_PLATFORM_ERR_SUCCESS;
}

static bool ns_storage_range_valid(uint32_t offset, uint32_t size)
{
    if (size == 0U) {
        return false;
    }
    if ((offset + size) < offset) { /* overflow guard */
        return false;
    }
    if (offset < NXP_FLASH_NS_STORAGE_OFFSET) {
        return false;
    }
    if ((offset + size) > (NXP_FLASH_NS_STORAGE_OFFSET + NXP_FLASH_NS_STORAGE_SIZE)) {
        return false;
    }
    return true;
}


static enum tfm_platform_err_t
handle_flash_erase(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_erase_args_t *args;
    struct tfm_flash_op_out_t           *out;
    enum tfm_platform_err_t              init_ret;
    status_t                             status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_erase_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_erase_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    /* Sector-alignment check against the real hardware erase granularity.
     * HAL_FLASH_ERASE_SECTOR_SIZE is always 8 KB. On KW43/MCXW this differs
     * from FLASH_AREA_IMAGE_SECTOR_SIZE (512 B, RAM-backed ITS/PS). */
    if ((args->addr % HAL_FLASH_ERASE_SECTOR_SIZE) != 0U ||
        (args->size % HAL_FLASH_ERASE_SECTOR_SIZE) != 0U) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_erase_sector(&s_flash_config, args->addr, args->size,
                                     (uint32_t)kFLASH_ApiEraseKey);
    if (status != (status_t)0) {
        out->result = (int32_t)status;
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    out->result = 0;
    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_program_phrase(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_program_phrase_args_t *args;
    struct tfm_flash_op_out_t                    *out;
    enum tfm_platform_err_t                       init_ret;
    status_t                                      status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_program_phrase_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_program_phrase_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    if (args->data == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (cmse_check_address_range((void *)args->data, args->size,
                                 CMSE_MPU_NONSECURE | CMSE_MPU_READ) == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    /* Phrase-alignment checks (16 bytes). */
    if ((args->addr % FLASH_AREA_IMAGE_PHRASE_SIZE) != 0U ||
        (args->size % FLASH_AREA_IMAGE_PHRASE_SIZE) != 0U) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_program_phrase(&s_flash_config, args->addr,
                                       args->data, args->size);
    if (status != (status_t)0) {
        out->result = (int32_t)status;
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    out->result = 0;
    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_program_page(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_program_page_args_t *args;
    struct tfm_flash_op_out_t                  *out;
    enum tfm_platform_err_t                     init_ret;
    status_t                                    status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_program_page_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_program_page_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    if (args->data == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (cmse_check_address_range((void *)args->data, args->size,
                                 CMSE_MPU_NONSECURE | CMSE_MPU_READ) == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    /* Page-alignment checks (128 bytes). */
    if ((args->addr % FLASH_AREA_PROGRAM_SIZE) != 0U ||
        (args->size % FLASH_AREA_PROGRAM_SIZE) != 0U) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_program_page(&s_flash_config, args->addr,
                                     args->data, args->size);
    if (status != (status_t)0) {
        out->result = (int32_t)status;
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    out->result = 0;
    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_verify_program(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_verify_program_args_t *args;
    struct tfm_flash_verify_program_out_t        *out;
    enum tfm_platform_err_t                       init_ret;
    status_t                                      status;
    uint32_t                                      failed_address = 0U;
    uint32_t                                      failed_data    = 0U;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_verify_program_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_verify_program_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_verify_program_args_t *)in_vec->base;
    out  = (struct tfm_flash_verify_program_out_t *)out_vec->base;
    out->result         = -1;
    out->failed_address = 0U;
    out->failed_data    = 0U;

    if (args->expected_data == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    /* Verify the expected_data pointer is readable NS RAM. */
    if (cmse_check_address_range((void *)args->expected_data, args->size,
                                 CMSE_MPU_NONSECURE | CMSE_MPU_READ) == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    /* Phrase-alignment checks (16 bytes). */
    if ((args->addr % FLASH_AREA_IMAGE_PHRASE_SIZE) != 0U ||
        (args->size % FLASH_AREA_IMAGE_PHRASE_SIZE) != 0U) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_verify_program(&s_flash_config, args->addr, args->size,
                                       args->expected_data,
                                       &failed_address, &failed_data);
    out->result         = (int32_t)status;
    out->failed_address = failed_address;
    out->failed_data    = failed_data;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_verify_erase_phrase(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_verify_erase_args_t *args;
    struct tfm_flash_op_out_t                  *out;
    enum tfm_platform_err_t                     init_ret;
    status_t                                    status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_verify_erase_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_verify_erase_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_verify_erase_phrase(&s_flash_config, args->addr, args->size);
    out->result = (int32_t)status;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_verify_erase_page(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_verify_erase_args_t *args;
    struct tfm_flash_op_out_t                  *out;
    enum tfm_platform_err_t                     init_ret;
    status_t                                    status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_verify_erase_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_verify_erase_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_verify_erase_page(&s_flash_config, args->addr, args->size);
    out->result = (int32_t)status;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_verify_erase_sector(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_verify_erase_args_t *args;
    struct tfm_flash_op_out_t                  *out;
    enum tfm_platform_err_t                     init_ret;
    status_t                                    status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_verify_erase_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_verify_erase_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    /* Sector-alignment check against the real hardware erase granularity.
     * HAL_FLASH_ERASE_SECTOR_SIZE is always 8 KB. On KW43/MCXW this differs
     * from FLASH_AREA_IMAGE_SECTOR_SIZE (512 B, RAM-backed ITS/PS). */
    if ((args->addr % HAL_FLASH_ERASE_SECTOR_SIZE) != 0U ||
        (args->size % HAL_FLASH_ERASE_SECTOR_SIZE) != 0U) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_verify_erase_sector(&s_flash_config, args->addr, args->size);
    out->result = (int32_t)status;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_get_property(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_get_property_args_t *args;
    struct tfm_flash_get_property_out_t        *out;
    enum tfm_platform_err_t                     init_ret;
    status_t                                    status;
    uint32_t                                    value = 0U;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_get_property_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_get_property_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_get_property_args_t *)in_vec->base;
    out  = (struct tfm_flash_get_property_out_t *)out_vec->base;
    out->result = -1;
    out->value  = 0U;

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_get_property(&s_flash_config,
                                     (flash_property_tag_t)args->which_property,
                                     &value);
    out->result = (int32_t)status;
    out->value  = value;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_read(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_read_args_t *args;
    struct tfm_flash_op_out_t          *out;
    uint8_t                            *dest;
    enum tfm_platform_err_t             init_ret;
    status_t                            status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_read_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_read_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    dest = args->dest;

    if (dest == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    /* Verify the destination is writable NS RAM. */
    if (cmse_check_address_range((void *)dest, args->size,
                                 CMSE_MPU_NONSECURE | CMSE_MPU_READWRITE) == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    if (!ns_storage_range_valid(args->addr, args->size)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_read(&s_flash_config, args->addr, dest, args->size);
    out->result = (int32_t)status;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

/* -------------------------------------------------------------------------
 * MCXW/KW43-only handlers
 * ---------------------------------------------------------------------- */

static enum tfm_platform_err_t
handle_flash_verify_erase_all(psa_outvec *out_vec)
{
    struct tfm_flash_op_out_t *out;
    status_t                   status;

    if (out_vec == NULL || out_vec->len != sizeof(struct tfm_flash_op_out_t)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    out = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    status = hal_flash_verify_erase_all();
    out->result = (int32_t)status;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_flash_verify_erase_block(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_flash_verify_erase_block_args_t *args;
    struct tfm_flash_op_out_t                        *out;
    enum tfm_platform_err_t                           init_ret;
    status_t                                          status;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_flash_verify_erase_block_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_flash_verify_erase_block_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    status = hal_flash_verify_erase_block(&s_flash_config, args->blockaddr);
    out->result = (int32_t)status;

    if (status != (status_t)0) {
        return TFM_PLATFORM_ERR_SYSTEM_ERROR;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

/* -------------------------------------------------------------------------
 * ROM API handlers
 * ---------------------------------------------------------------------- */

static enum tfm_platform_err_t
handle_romapi_get_version(psa_outvec *out_vec)
{
    struct tfm_romapi_get_version_out_t *out;
    enum tfm_platform_err_t              init_ret;

    if (out_vec == NULL || out_vec->len != sizeof(struct tfm_romapi_get_version_out_t)) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    out = (struct tfm_romapi_get_version_out_t *)out_vec->base;
    out->result  = -1;
    out->version = 0U;

    init_ret = ensure_flash_init();
    if (init_ret != TFM_PLATFORM_ERR_SUCCESS) {
        return init_ret;
    }

    out->result  = 0;
    out->version = hal_romapi_get_version(&s_flash_config);

    return TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t
handle_romapi_run_bootloader(const psa_invec *in_vec, psa_outvec *out_vec)
{
    const struct tfm_romapi_run_bootloader_args_t *args;
    struct tfm_flash_op_out_t                     *out;

    if ((in_vec  == NULL) || (in_vec->len  != sizeof(struct tfm_romapi_run_bootloader_args_t)) ||
        (out_vec == NULL) || (out_vec->len != sizeof(struct tfm_flash_op_out_t))) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args = (const struct tfm_romapi_run_bootloader_args_t *)in_vec->base;
    out  = (struct tfm_flash_op_out_t *)out_vec->base;
    out->result = -1;

    out->result = hal_romapi_run_bootloader(args->option);

    if (out->result != 0) {
        return TFM_PLATFORM_ERR_NOT_SUPPORTED;
    }

    return TFM_PLATFORM_ERR_SUCCESS;
}

/* -------------------------------------------------------------------------
 * Board IOCTL hook -- called from common tfm_platform_system.c
 * ---------------------------------------------------------------------- */

enum tfm_platform_err_t
tfm_platform_hal_ioctl_board(tfm_platform_ioctl_req_t request,
                              psa_invec  *in_vec,
                              psa_outvec *out_vec)
{
    switch ((enum tfm_platform_ioctl_nxp_request_t)request) {
    case TFM_PLATFORM_IOCTL_FLASH_ERASE_SECTOR:
        return handle_flash_erase(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PHRASE:
        return handle_flash_program_phrase(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PAGE:
        return handle_flash_program_page(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_VERIFY_PROGRAM:
        return handle_flash_verify_program(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PHRASE:
        return handle_flash_verify_erase_phrase(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PAGE:
        return handle_flash_verify_erase_page(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_SECTOR:
        return handle_flash_verify_erase_sector(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_GET_PROPERTY:
        return handle_flash_get_property(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_READ:
        return handle_flash_read(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_ALL:
        return handle_flash_verify_erase_all(out_vec);

    case TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_BLOCK:
        return handle_flash_verify_erase_block(in_vec, out_vec);

    case TFM_PLATFORM_IOCTL_ROMAPI_GET_VERSION:
        return handle_romapi_get_version(out_vec);

    case TFM_PLATFORM_IOCTL_ROMAPI_RUN_BOOTLOADER:
        return handle_romapi_run_bootloader(in_vec, out_vec);

    default:
        break;
    }

    return TFM_PLATFORM_ERR_NOT_SUPPORTED;
}
