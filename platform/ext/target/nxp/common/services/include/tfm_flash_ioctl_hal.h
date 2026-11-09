/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * S-world flash HAL abstraction header.
 *
 * Selects the correct ROM flash driver header based on the target family macro
 * defined by the board's mcux.cmake:
 *
 *   ROMAPI_PROXY_HAL_MCXL  -- FRDM-MCXL255
 *   ROMAPI_PROXY_HAL_MCXA  -- FRDM-MCXA577, FRDM-MCXA287
 *   ROMAPI_PROXY_HAL_MCXW  -- FRDM-KW43 and other KW/MCXW targets
 *
 * Then exposes a set of static inline hal_flash_*() wrappers with a uniform
 * signature so that tfm_flash_ioctl_hal.c is fully target-agnostic.
 *
 */

#ifndef TFM_FLASH_IOCTL_HAL_H__
#define TFM_FLASH_IOCTL_HAL_H__

#if defined(ROMAPI_PROXY_HAL_MCXL) || defined(ROMAPI_PROXY_HAL_MCXA)
#include "fsl_romapi.h"
#if defined(ROMAPI_PROXY_HAL_MCXA)
#include "fsl_runbootloader.h"
#endif

#elif defined(ROMAPI_PROXY_HAL_MCXW)
#include "fsl_flash_api.h"

#else
#error "tfm_flash_ioctl_hal.h: no target selected. Define ROMAPI_PROXY_HAL_MCXL, ROMAPI_PROXY_HAL_MCXA, or ROMAPI_PROXY_HAL_MCXW."
#endif

/* -------------------------------------------------------------------------
 * HAL_FLASH_ERASE_SECTOR_SIZE
 *
 * The real hardware erase granularity used by the NS-storage IOCTL service.
 * On MCXL/MCXA, FLASH_AREA_IMAGE_SECTOR_SIZE is already the hardware sector
 * size (8 KB), so we can reuse it directly.
 * On MCXW (KW43), FLASH_AREA_IMAGE_SECTOR_SIZE is intentionally set to 512 B
 * to accommodate the RAM-backed ITS/PS, so we must override it here with the
 * real 8 KB hardware sector size.
 * ---------------------------------------------------------------------- */
#if defined(ROMAPI_PROXY_HAL_MCXW)
#define HAL_FLASH_ERASE_SECTOR_SIZE  (8U * 1024U)
#else
#define HAL_FLASH_ERASE_SECTOR_SIZE  FLASH_AREA_IMAGE_SECTOR_SIZE
#endif

/* -------------------------------------------------------------------------
 * Unified wrappers -- called by tfm_flash_ioctl_hal.c
 * ---------------------------------------------------------------------- */

/*
 * hal_flash_erase_sector
 * Erase one or more sectors starting at addr (sector-aligned, 8 KB multiple).
 */
static inline status_t hal_flash_erase_sector(flash_config_t *config,
                                               uint32_t        addr,
                                               uint32_t        size,
                                               uint32_t        key)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    return FLASH_Erase(config, FMU_NS, addr, size, key);
#else
    return FLASH_EraseSector(config, addr, size, key);
#endif
}

/*
 * hal_flash_program_phrase
 * Program data at phrase granularity (16-byte aligned).
 * MCXW is not supporting ProgramPhrase API!
 * src is treated as a byte pointer on all targets.
 */
static inline status_t hal_flash_program_phrase(flash_config_t *config,
                                                 uint32_t        addr,
                                                 const uint8_t  *src,
                                                 uint32_t        size)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    /* KW43 ROM API takes uint32_t* src. */
    return FLASH_Program(config, FMU_NS, addr, (uint32_t *)(uintptr_t)src, size);
#else
    return FLASH_ProgramPhrase(config, addr, (uint8_t *)(uintptr_t)src, size);
#endif
}

/*
 * hal_flash_program_page
 * Program data at page granularity (128-byte aligned).
 * src is treated as a byte pointer on all targets.
 */
static inline status_t hal_flash_program_page(flash_config_t *config,
                                               uint32_t        addr,
                                               const uint8_t  *src,
                                               uint32_t        size)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    return FLASH_ProgramPage(config, FMU_NS, addr, (uint32_t *)(uintptr_t)src, size);
#else
    return FLASH_ProgramPage(config, addr, (uint8_t *)(uintptr_t)src, size);
#endif
}

/*
 * hal_flash_verify_program
 * Verify programmed data. Not supported on MCXW targets.
 */
static inline status_t hal_flash_verify_program(flash_config_t *config,
                                                  uint32_t        addr,
                                                  uint32_t        size,
                                                  const uint8_t  *expected_data,
                                                  uint32_t       *failed_address,
                                                  uint32_t       *failed_data)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    (void)config;
    (void)addr;
    (void)size;
    (void)expected_data;
    (void)failed_address;
    (void)failed_data;
    return (status_t)kStatus_FLASH_CommandNotSupported;
#else
    return FLASH_VerifyProgram(config, addr, size, expected_data,
                               failed_address, failed_data);
#endif
}

/*
 * hal_flash_verify_erase_phrase
 * Verify phrase-granularity erase.
 */
static inline status_t hal_flash_verify_erase_phrase(flash_config_t *config,
                                                       uint32_t        addr,
                                                       uint32_t        size)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    return FLASH_VerifyErasePhrase(config, FMU_NS, addr, size);
#else
    return FLASH_VerifyErasePhrase(config, addr, size);
#endif
}

/*
 * hal_flash_verify_erase_page
 * Verify page-granularity erase.
 */
static inline status_t hal_flash_verify_erase_page(flash_config_t *config,
                                                     uint32_t        addr,
                                                     uint32_t        size)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    return FLASH_VerifyErasePage(config, FMU_NS, addr, size);
#else
    return FLASH_VerifyErasePage(config, addr, size);
#endif
}

/*
 * hal_flash_verify_erase_sector
 * Verify sector-granularity erase.
 */
static inline status_t hal_flash_verify_erase_sector(flash_config_t *config,
                                                       uint32_t        addr,
                                                       uint32_t        size)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    return FLASH_VerifyEraseSector(config, FMU_NS, addr, size);
#else
    return FLASH_VerifyEraseSector(config, addr, size);
#endif
}

/*
 * hal_flash_get_property
 * Read a flash property. Signature is identical on all targets.
 */
static inline status_t hal_flash_get_property(flash_config_t      *config,
                                               flash_property_tag_t which_property,
                                               uint32_t            *value)
{
    return FLASH_GetProperty(config, which_property, value);
}

/*
 * hal_flash_read
 * Read flash bytes into a buffer. Not supported on MCXW targets.
 */
static inline status_t hal_flash_read(flash_config_t *config,
                                       uint32_t        addr,
                                       uint8_t        *dest,
                                       uint32_t        size)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    (void)config;
    (void)addr;
    (void)dest;
    (void)size;
    return (status_t)kStatus_FLASH_CommandNotSupported;
#else
    return FLASH_Read(config, addr, dest, size);
#endif
}

/*
 * hal_flash_verify_erase_all
 * Verify that the entire flash array is erased. MCXW/KW43 only.
 */
static inline status_t hal_flash_verify_erase_all(void)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    return FLASH_VerifyEraseAll(FMU_NS);
#else
    return (status_t)(-1); /* not supported on this target */
#endif
}

/*
 * hal_flash_verify_erase_block
 * Verify that the flash block at blockaddr is erased. MCXW/KW43 only.
 */
static inline status_t hal_flash_verify_erase_block(flash_config_t *config,
                                                      uint32_t        blockaddr)
{
#if defined(ROMAPI_PROXY_HAL_MCXW)
    return FLASH_VerifyEraseBlock(config, FMU_NS, blockaddr);
#else
    (void)config;
    (void)blockaddr;
    return (status_t)(-1); /* not supported on this target */
#endif
}

/* -------------------------------------------------------------------------
 * ROM API wrappers -- MCXL/MCXA only; MCXW returns not-supported
 * ---------------------------------------------------------------------- */

/*
 * hal_romapi_get_version
 * Returns the raw ROM API version word.
 *
 * MCXL: FLASH_API->version.version  (standard_version_t in the MCXL flash vtable)
 * MCXA: FLASH_GetAPIVersion(config).version  (standard_version_t returned by MCXA flash driver)
 */
static inline uint32_t hal_romapi_get_version(flash_config_t *config)
{
#if defined(ROMAPI_PROXY_HAL_MCXL)
    (void)config;
    return FLASH_API->version.version;
#elif defined(ROMAPI_PROXY_HAL_MCXA)
    return FLASH_GetAPIVersion(config).version;
#else
    (void)config;
    return 0U;
#endif
}

/*
 * hal_romapi_run_bootloader
 * Invokes the ROM bootloader with the supplied option word.
 * option is the U member of user_app_boot_invoke_option_t.
 * Returns 0 on success; the function is not expected to return on MCXL/MCXA.
 *
 * MCXL: ROM_API->run_bootloader(arg)
 * MCXA: BOOTLOADER_API_TREE_POINTER->runBootloader(arg)
 */
static inline int32_t hal_romapi_run_bootloader(uint32_t option)
{
#if defined(ROMAPI_PROXY_HAL_MCXA)
    user_app_boot_invoke_option_t invoke_option;
    invoke_option.option.U = option;
    BOOTLOADER_API_TREE_POINTER->runBootloader((void *)&invoke_option);
    return 0;
#elif defined(ROMAPI_PROXY_HAL_MCXL)
    ROM_API->run_bootloader((void *)&option);
    return 0;
#else
    (void)option;
    return -1; /* not supported on this target */
#endif
}

#endif /* TFM_FLASH_IOCTL_HAL_H__ */
