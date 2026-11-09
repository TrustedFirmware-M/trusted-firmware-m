/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef FSL_FLASH_NS_PROXY_MCXW_H__
#define FSL_FLASH_NS_PROXY_MCXW_H__

#include "tfm_ioctl_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * FLASH_Init -- NS proxy.
 *
 * The S side initialises its own flash_config_t on first use.  The NS proxy
 * only zeroes the caller's struct so fields read back as valid (e.g. zero
 * sector size will not confuse size-check code).  Returns kStatus_Success (0).
 */
static inline status_t FLASH_Init(flash_config_t *config)
{
    if (config != NULL)
    {
        uint32_t i;
        for (i = 0U; i < (sizeof(flash_config_t) / sizeof(uint32_t)); i++)
        {
            ((uint32_t *)config)[i] = 0U;
        }
    }
    return (status_t)0; /* kStatus_Success */
}

/*
 * FLASH_Erase -- NS proxy.
 *
 * Tunnels the erase request to the S partition via IOCTL.
 * start         - NS-alias flash offset (sector-aligned, 8 KB multiple).
 * lengthInBytes - bytes to erase (8 KB multiple).
 * key           - accepted for source compatibility, not forwarded.
 * base          - accepted for source compatibility, not forwarded (S side uses FMU0).
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_Erase(flash_config_t *config,
                                    FMU_Type       *base,
                                    uint32_t        start,
                                    uint32_t        lengthInBytes,
                                    uint32_t        key)
{
    int32_t result = -1;
    (void)config;
    (void)base;
    (void)key;
    (void)tfm_platform_flash_erase(start, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_Program -- NS proxy.
 *
 * Tunnels the program-phrase request to the S partition via IOCTL.
 * The KW43 ROM API uses FLASH_Program (not FLASH_ProgramPhrase) for phrase-
 * granularity writes; the IOCTL maps to TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PHRASE.
 * start         - NS-alias flash offset (phrase-aligned, 16-byte multiple).
 * src           - pointer to source data in NS RAM (word-aligned uint32_t*).
 * lengthInBytes - bytes to write (16-byte multiple).
 * base          - accepted for source compatibility, not forwarded.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_Program(flash_config_t *config,
                                      FMU_Type       *base,
                                      uint32_t        start,
                                      uint32_t       *src,
                                      uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)base;
    (void)tfm_platform_flash_program_phrase(start, (uint8_t *)src, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_ProgramPage -- NS proxy.
 *
 * Tunnels the program-page request to the S partition via IOCTL.
 * A page on KW43 is 128 bytes; the S side enforces 128-byte alignment.
 * start         - NS-alias flash offset (page-aligned, 128-byte multiple).
 * src           - pointer to source data in NS RAM (word-aligned uint32_t*).
 * lengthInBytes - bytes to write (128-byte multiple).
 * base          - accepted for source compatibility, not forwarded.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_ProgramPage(flash_config_t *config,
                                          FMU_Type       *base,
                                          uint32_t        start,
                                          uint32_t       *src,
                                          uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)base;
    (void)tfm_platform_flash_program_page(start, (uint8_t *)src, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_VerifyErasePhrase -- NS proxy.
 *
 * Tunnels the verify-erase-phrase request to the S partition via IOCTL.
 * start         - NS-alias flash offset.
 * lengthInBytes - bytes to check.
 * base          - accepted for source compatibility, not forwarded.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_VerifyErasePhrase(flash_config_t *config,
                                                FMU_Type       *base,
                                                uint32_t        start,
                                                uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)base;
    (void)tfm_platform_flash_verify_erase_phrase(start, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_VerifyErasePage -- NS proxy.
 *
 * Tunnels the verify-erase-page request to the S partition via IOCTL.
 * start         - NS-alias flash offset.
 * lengthInBytes - bytes to check.
 * base          - accepted for source compatibility, not forwarded.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_VerifyErasePage(flash_config_t *config,
                                              FMU_Type       *base,
                                              uint32_t        start,
                                              uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)base;
    (void)tfm_platform_flash_verify_erase_page(start, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_VerifyEraseSector -- NS proxy.
 *
 * Tunnels the verify-erase-sector request to the S partition via IOCTL.
 * start         - NS-alias flash offset (sector-aligned).
 * lengthInBytes - bytes to check (sector-aligned).
 * base          - accepted for source compatibility, not forwarded.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_VerifyEraseSector(flash_config_t *config,
                                                FMU_Type       *base,
                                                uint32_t        start,
                                                uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)base;
    (void)tfm_platform_flash_verify_erase_sector(start, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_GetProperty -- NS proxy.
 *
 * Tunnels the get-property request to the S partition via IOCTL.
 * whichProperty - flash_property_tag_t value.
 * value         - receives the property value on success.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_GetProperty(flash_config_t      *config,
                                          flash_property_tag_t whichProperty,
                                          uint32_t            *value)
{
    int32_t result = -1;
    (void)config;
    (void)tfm_platform_flash_get_property((uint32_t)whichProperty, value, &result);
    return (status_t)result;
}

/*
 * FLASH_VerifyEraseAll -- NS proxy (MCXW/KW43 only).
 *
 * Verifies that the entire flash array is erased.
 * base is accepted for source compatibility but not forwarded;
 * the S side always operates on FMU0.
 */
static inline status_t FLASH_VerifyEraseAll(FMU_Type *base)
{
    int32_t result = -1;
    (void)base;
    (void)tfm_platform_flash_verify_erase_all(&result);
    return (status_t)result;
}

/*
 * FLASH_VerifyEraseBlock -- NS proxy (MCXW/KW43 only).
 *
 * Verifies that the flash block starting at blockaddr is erased.
 * config and base are accepted for source compatibility but not forwarded.
 */
static inline status_t FLASH_VerifyEraseBlock(flash_config_t *config,
                                               FMU_Type       *base,
                                               uint32_t        blockaddr)
{
    int32_t result = -1;
    (void)config;
    (void)base;
    (void)tfm_platform_flash_verify_erase_block(blockaddr, &result);
    return (status_t)result;
}

#ifdef __cplusplus
}
#endif

#endif /* FSL_FLASH_NS_PROXY_MCXW_H__ */
