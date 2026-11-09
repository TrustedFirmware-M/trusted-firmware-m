/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_ioctl_api.h"
#include "tfm_platform_api.h"
#include "flash_layout.h"

#include <stdint.h>
#include <stddef.h>

enum tfm_platform_err_t tfm_platform_flash_erase(uint32_t addr,
                                                  uint32_t size,
                                                  int32_t *result)
{
    enum tfm_platform_err_t ret;
    psa_invec  in_vec;
    psa_outvec out_vec;
    struct tfm_flash_erase_args_t  args;
    struct tfm_flash_op_out_t      out;

    if (result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.addr = addr;
    args.size = size;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    ret = tfm_platform_ioctl((tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_ERASE_SECTOR,
                             &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_verify_erase_all(int32_t *result)
{
    enum tfm_platform_err_t ret;
    psa_outvec              out_vec;
    struct tfm_flash_op_out_t out;

    if (result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    out.result = -1;

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_ALL,
        NULL, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_verify_erase_block(uint32_t blockaddr,
                                                               int32_t *result)
{
    enum tfm_platform_err_t                     ret;
    psa_invec                                   in_vec;
    psa_outvec                                  out_vec;
    struct tfm_flash_verify_erase_block_args_t  args;
    struct tfm_flash_op_out_t                   out;

    if (result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.blockaddr = blockaddr;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    out.result = -1;

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_BLOCK,
        &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_program_phrase(uint32_t       addr,
                                                           const uint8_t *data,
                                                           uint32_t       size,
                                                           int32_t       *result)
{
    enum tfm_platform_err_t ret;
    psa_invec  in_vec;
    psa_outvec out_vec;
    struct tfm_flash_program_phrase_args_t args;
    struct tfm_flash_op_out_t              out;

    if (data == NULL || result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.addr = addr;
    args.data = data;
    args.size = size;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    ret = tfm_platform_ioctl((tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PHRASE,
                             &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_program_page(uint32_t       addr,
                                                         const uint8_t *data,
                                                         uint32_t       size,
                                                         int32_t       *result)
{
    enum tfm_platform_err_t ret;
    psa_invec  in_vec;
    psa_outvec out_vec;
    struct tfm_flash_program_page_args_t args;
    struct tfm_flash_op_out_t            out;

    if (data == NULL || result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.addr = addr;
    args.data = data;
    args.size = size;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    ret = tfm_platform_ioctl((tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PAGE,
                             &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_verify_program(uint32_t        addr,
                                                           uint32_t        size,
                                                           const uint8_t  *expected_data,
                                                           uint32_t       *failed_address,
                                                           uint32_t       *failed_data,
                                                           int32_t        *result)
{
    enum tfm_platform_err_t                 ret;
    psa_invec                               in_vec;
    psa_outvec                              out_vec;
    struct tfm_flash_verify_program_args_t  args;
    struct tfm_flash_verify_program_out_t   out;

    if (expected_data == NULL || result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.addr          = addr;
    args.size          = size;
    args.expected_data = expected_data;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    out.result         = -1;
    out.failed_address = 0U;
    out.failed_data    = 0U;

    ret = tfm_platform_ioctl((tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_VERIFY_PROGRAM,
                             &in_vec, &out_vec);

    *result = out.result;
    if (failed_address != NULL) {
        *failed_address = out.failed_address;
    }
    if (failed_data != NULL) {
        *failed_data = out.failed_data;
    }

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_verify_erase_phrase(uint32_t addr,
                                                                uint32_t size,
                                                                int32_t *result)
{
    enum tfm_platform_err_t             ret;
    psa_invec                           in_vec;
    psa_outvec                          out_vec;
    struct tfm_flash_verify_erase_args_t args;
    struct tfm_flash_op_out_t            out;

    if (result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.addr = addr;
    args.size = size;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PHRASE,
        &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_verify_erase_page(uint32_t addr,
                                                              uint32_t size,
                                                              int32_t *result)
{
    enum tfm_platform_err_t              ret;
    psa_invec                            in_vec;
    psa_outvec                           out_vec;
    struct tfm_flash_verify_erase_args_t args;
    struct tfm_flash_op_out_t            out;

    if (result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.addr = addr;
    args.size = size;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PAGE,
        &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_verify_erase_sector(uint32_t addr,
                                                                uint32_t size,
                                                                int32_t *result)
{
    enum tfm_platform_err_t              ret;
    psa_invec                            in_vec;
    psa_outvec                           out_vec;
    struct tfm_flash_verify_erase_args_t args;
    struct tfm_flash_op_out_t            out;

    if (result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.addr = addr;
    args.size = size;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_SECTOR,
        &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_get_property(uint32_t  which_property,
                                                         uint32_t *value,
                                                         int32_t  *result)
{
    enum tfm_platform_err_t              ret;
    psa_invec                            in_vec;
    psa_outvec                           out_vec;
    struct tfm_flash_get_property_args_t args;
    struct tfm_flash_get_property_out_t  out;

    if (value == NULL || result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.which_property = which_property;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    out.result = -1;
    out.value  = 0U;

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_GET_PROPERTY,
        &in_vec, &out_vec);

    *result = out.result;
    *value  = out.value;

    return ret;
}

enum tfm_platform_err_t tfm_platform_flash_read(uint32_t  addr,
                                                 uint8_t  *dest,
                                                 uint32_t  size,
                                                 int32_t  *result)
{
    enum tfm_platform_err_t      ret;
    psa_invec                    in_vec;
    psa_outvec                   out_vec;
    struct tfm_flash_read_args_t args;
    struct tfm_flash_op_out_t    out;

    if (dest == NULL || result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    /* dest is embedded in the args struct; the S handler CMSE-checks it
     * and writes the flash data directly into the NS buffer. */
    args.addr = addr;
    args.dest = dest;
    args.size = size;

    in_vec.base = (const void *)&args;
    in_vec.len  = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    out.result = -1;

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_FLASH_READ,
        &in_vec, &out_vec);

    *result = out.result;

    return ret;
}

enum tfm_platform_err_t tfm_platform_romapi_get_version(uint32_t *version,
                                                         int32_t  *result)
{
    enum tfm_platform_err_t              ret;
    psa_outvec                           out_vec;
    struct tfm_romapi_get_version_out_t  out;

    if (version == NULL || result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    out.result  = -1;
    out.version = 0U;

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_ROMAPI_GET_VERSION,
        NULL, &out_vec);

    *result  = out.result;
    *version = out.version;

    return ret;
}

enum tfm_platform_err_t tfm_platform_romapi_run_bootloader(uint32_t option,
                                                            int32_t *result)
{
    enum tfm_platform_err_t                  ret;
    psa_invec                                in_vec;
    psa_outvec                               out_vec;
    struct tfm_romapi_run_bootloader_args_t  args;
    struct tfm_flash_op_out_t                out;

    if (result == NULL) {
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    args.option = option;

    in_vec.base  = (const void *)&args;
    in_vec.len   = sizeof(args);

    out_vec.base = (void *)&out;
    out_vec.len  = sizeof(out);

    out.result = -1;

    ret = tfm_platform_ioctl(
        (tfm_platform_ioctl_req_t)TFM_PLATFORM_IOCTL_ROMAPI_RUN_BOOTLOADER,
        &in_vec, &out_vec);

    *result = out.result;

    return ret;
}
