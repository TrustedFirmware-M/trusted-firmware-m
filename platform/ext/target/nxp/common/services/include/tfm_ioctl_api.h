/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_IOCTL_API_H__
#define TFM_IOCTL_API_H__

#include <stdint.h>
#include <stddef.h>
#include "tfm_platform_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * IOCTL request type identifiers.
 */
enum tfm_platform_ioctl_nxp_request_t {
    TFM_PLATFORM_IOCTL_FLASH_ERASE_SECTOR        = 1, /* erase one or more 8 KB sectors */
    TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PHRASE      = 2, /* program data (16-byte phrase aligned) */
    TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PAGE        = 3, /* program data (128-byte page aligned) */
    TFM_PLATFORM_IOCTL_FLASH_VERIFY_PROGRAM      = 4, /* verify programmed data */
    TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PHRASE = 5, /* verify 16-byte phrases are erased */
    TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PAGE   = 6, /* verify 128-byte pages are erased */
    TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_SECTOR = 7, /* verify 8 KB sectors are erased */
    TFM_PLATFORM_IOCTL_FLASH_GET_PROPERTY        = 8,  /* read a flash property value */
    TFM_PLATFORM_IOCTL_FLASH_READ                = 9,  /* read flash bytes into NS buffer */
    TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_ALL    = 10, /* verify entire flash array is erased (MCXW only) */
    TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_BLOCK  = 11, /* verify one flash block is erased (MCXW only) */
    TFM_PLATFORM_IOCTL_ROMAPI_GET_VERSION         = 12, /* read ROM API version word via FLASH_API->version.version */
    TFM_PLATFORM_IOCTL_ROMAPI_RUN_BOOTLOADER      = 13, /* invoke ROM bootloader with a caller-supplied option word */
};

/* -----------------------------------------------------------------------
 * Erase
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_ERASE_SECTOR.
 * addr  - flash offset (NS alias, i.e. no S base added), must be sector-aligned (8 KB).
 * size  - number of bytes to erase, must be a multiple of the sector size (8 KB).
 */
struct tfm_flash_erase_args_t {
    uint32_t addr;
    uint32_t size;
};

/* -----------------------------------------------------------------------
 * Program (phrase)
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PHRASE.
 * addr  - flash offset (NS alias), must be phrase-aligned (16 bytes).
 * data  - pointer to source data buffer in NS RAM.
 * size  - number of bytes to write, must be phrase-aligned (16 bytes).
 */
struct tfm_flash_program_phrase_args_t {
    uint32_t       addr;
    const uint8_t *data;
    uint32_t       size;
};

/* -----------------------------------------------------------------------
 * Program (page)
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PAGE.
 * addr  - flash offset (NS alias), must be page-aligned (128 bytes).
 * data  - pointer to source data buffer in NS RAM.
 * size  - number of bytes to write, must be page-aligned (128 bytes).
 */
struct tfm_flash_program_page_args_t {
    uint32_t       addr;
    const uint8_t *data;
    uint32_t       size;
};

/* -----------------------------------------------------------------------
 * Verify program
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_VERIFY_PROGRAM.
 * addr          - flash offset (NS alias), must be phrase-aligned.
 * size          - number of bytes to verify, must be phrase-aligned.
 * expected_data - pointer to reference data buffer in NS RAM (CMSE-checked S-side).
 */
struct tfm_flash_verify_program_args_t {
    uint32_t        addr;
    uint32_t        size;
    const uint8_t  *expected_data;
};

/*
 * Output struct for TFM_PLATFORM_IOCTL_FLASH_VERIFY_PROGRAM.
 * result         - 0 on success, negative IAP status on failure.
 * failed_address - first failing flash address (valid only on failure).
 * failed_data    - data read at the failing address (valid only on failure).
 */
struct tfm_flash_verify_program_out_t {
    int32_t  result;
    uint32_t failed_address;
    uint32_t failed_data;
};

/* -----------------------------------------------------------------------
 * Verify erase (phrase / page / sector share one arg struct)
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PHRASE,
 * TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PAGE and
 * TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_SECTOR.
 * addr  - flash offset (NS alias).
 * size  - number of bytes to check.
 */
struct tfm_flash_verify_erase_args_t {
    uint32_t addr;
    uint32_t size;
};

/* -----------------------------------------------------------------------
 * Get property
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_GET_PROPERTY.
 * which_property - flash_property_tag_t value cast to uint32_t.
 */
struct tfm_flash_get_property_args_t {
    uint32_t which_property;
};

/*
 * Output struct for TFM_PLATFORM_IOCTL_FLASH_GET_PROPERTY.
 * result - 0 on success, negative IAP status on failure.
 * value  - property value returned by the ROM driver.
 */
struct tfm_flash_get_property_out_t {
    int32_t  result;
    uint32_t value;
};

/* -----------------------------------------------------------------------
 * Read
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_READ.
 * addr  - flash offset (NS alias).
 * dest  - destination buffer in NS RAM (CMSE write-checked S-side).
 * size  - number of bytes to read.
 */
struct tfm_flash_read_args_t {
    uint32_t  addr;
    uint8_t  *dest;
    uint32_t  size;
};

/*
 * Output struct shared by simple status operations.
 * result == 0  on success, negative IAP status code on failure.
 */
struct tfm_flash_op_out_t {
    int32_t result;
};

/* -----------------------------------------------------------------------
 * Verify erase all / erase block  (MCXW/KW43 only)
 * -------------------------------------------------------------------- */

/*
 * TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_ALL has no input args.
 * Use tfm_flash_op_out_t as the output struct.
 */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_BLOCK.
 * blockaddr - start address of the flash block to verify (block-aligned).
 */
struct tfm_flash_verify_erase_block_args_t {
    uint32_t blockaddr;
};

/* -----------------------------------------------------------------------
 * ROM API get version
 * -------------------------------------------------------------------- */

/*
 * TFM_PLATFORM_IOCTL_ROMAPI_GET_VERSION has no input args.
 * Output: tfm_romapi_get_version_out_t.
 */

/*
 * Output struct for TFM_PLATFORM_IOCTL_ROMAPI_GET_VERSION.
 * result  - 0 on success, negative on error.
 * version - raw ROM API version word from FLASH_API->version.version.
 */
struct tfm_romapi_get_version_out_t {
    int32_t  result;
    uint32_t version;
};

/* -----------------------------------------------------------------------
 * ROM API run bootloader
 * -------------------------------------------------------------------- */

/*
 * Input argument struct for TFM_PLATFORM_IOCTL_ROMAPI_RUN_BOOTLOADER.
 * option - user_app_boot_invoke_option_t.option.U value passed to the
 *          ROM run_bootloader entry point.
 */
struct tfm_romapi_run_bootloader_args_t {
    uint32_t option;
};

/* -----------------------------------------------------------------------
 * NS-callable helper functions
 * -------------------------------------------------------------------- */

/**
 * @brief Erase flash sectors within the NXP_NS_STORAGE region.
 *
 * @param[in]  addr    Flash offset to erase (NS alias, sector-aligned, multiple of 8 KB).
 * @param[in]  size    Number of bytes to erase (multiple of 8 KB).
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_erase(uint32_t addr,
                                                  uint32_t size,
                                                  int32_t *result);

/**
 * @brief Program data into the NXP_NS_STORAGE region (phrase granularity, 16 bytes).
 *
 * @param[in]  addr    Flash offset to write (NS alias, phrase-aligned, multiple of 16 bytes).
 * @param[in]  data    Pointer to data buffer in NS RAM.
 * @param[in]  size    Number of bytes to write (multiple of 16 bytes).
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_program_phrase(uint32_t       addr,
                                                           const uint8_t *data,
                                                           uint32_t       size,
                                                           int32_t       *result);

/**
 * @brief Program data into the NXP_NS_STORAGE region (page granularity, 128 bytes).
 *
 * @param[in]  addr    Flash offset to write (NS alias, page-aligned, multiple of 128 bytes).
 * @param[in]  data    Pointer to data buffer in NS RAM.
 * @param[in]  size    Number of bytes to write (multiple of 128 bytes).
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_program_page(uint32_t       addr,
                                                         const uint8_t *data,
                                                         uint32_t       size,
                                                         int32_t       *result);

/**
 * @brief Verify data programmed in the NXP_NS_STORAGE region.
 *
 * @param[in]  addr           Flash offset (NS alias, phrase-aligned).
 * @param[in]  size           Number of bytes to verify (phrase-aligned).
 * @param[in]  expected_data  Pointer to reference data buffer in NS RAM.
 * @param[out] failed_address First failing flash address (valid on mismatch).
 * @param[out] failed_data    Data read at the failing address (valid on mismatch).
 * @param[out] result         IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_verify_program(uint32_t        addr,
                                                           uint32_t        size,
                                                           const uint8_t  *expected_data,
                                                           uint32_t       *failed_address,
                                                           uint32_t       *failed_data,
                                                           int32_t        *result);

/**
 * @brief Verify that flash phrases (16-byte) in the NXP_NS_STORAGE region are erased.
 *
 * @param[in]  addr    Flash offset (NS alias).
 * @param[in]  size    Number of bytes to check.
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_verify_erase_phrase(uint32_t addr,
                                                                uint32_t size,
                                                                int32_t *result);

/**
 * @brief Verify that flash pages (128-byte) in the NXP_NS_STORAGE region are erased.
 *
 * @param[in]  addr    Flash offset (NS alias).
 * @param[in]  size    Number of bytes to check.
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_verify_erase_page(uint32_t addr,
                                                              uint32_t size,
                                                              int32_t *result);

/**
 * @brief Verify that flash sectors (8 KB) in the NXP_NS_STORAGE region are erased.
 *
 * @param[in]  addr    Flash offset (NS alias).
 * @param[in]  size    Number of bytes to check.
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_verify_erase_sector(uint32_t addr,
                                                                uint32_t size,
                                                                int32_t *result);

/**
 * @brief Read a flash property via the S-world ROM driver.
 *
 * @param[in]  which_property  flash_property_tag_t value cast to uint32_t.
 * @param[out] value           Property value returned by the ROM driver.
 * @param[out] result          IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_get_property(uint32_t  which_property,
                                                         uint32_t *value,
                                                         int32_t  *result);

/**
 * @brief Read flash bytes from the NXP_NS_STORAGE region into a NS buffer.
 *
 * @param[in]  addr    Flash offset (NS alias).
 * @param[out] dest    Destination buffer in NS RAM.
 * @param[in]  size    Number of bytes to read.
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_read(uint32_t  addr,
                                                 uint8_t  *dest,
                                                 uint32_t  size,
                                                 int32_t  *result);

/**
 * @brief Verify that the entire flash array is erased.
 *
 * @param[out] result  IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_verify_erase_all(int32_t *result);

/**
 * @brief Verify that a flash block is erased.
 *
 * @param[in]  blockaddr  Start address of the flash block (block-aligned).
 * @param[out] result     IAP status: 0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_flash_verify_erase_block(uint32_t blockaddr,
                                                               int32_t *result);

/**
 * @brief Read the ROM API version word via the S-world ROM driver.
 *
 * @param[out] version  Raw version word from FLASH_API->version.version.
 * @param[out] result   0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_romapi_get_version(uint32_t *version,
                                                         int32_t  *result);

/**
 * @brief Invoke the ROM bootloader from S-world.
 *
 * @param[in]  option  user_app_boot_invoke_option_t.option.U value.
 * @param[out] result  0 on success, negative on error.
 *
 * @return TFM_PLATFORM_ERR_SUCCESS or TFM_PLATFORM_ERR_INVALID_PARAM.
 */
enum tfm_platform_err_t tfm_platform_romapi_run_bootloader(uint32_t option,
                                                            int32_t *result);

#ifdef __cplusplus
}
#endif

#endif /* TFM_IOCTL_API_H__ */
