/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef FSL_FLASH_NS_PROXY_MCXL_MCXA_H__
#define FSL_FLASH_NS_PROXY_MCXL_MCXA_H__

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
 * FLASH_EraseSector -- NS proxy.
 *
 * Tunnels the erase request to the S partition via IOCTL.
 * start         - NS-alias flash offset (sector-aligned, 8 KB multiple).
 * lengthInBytes - bytes to erase (8 KB multiple).
 * key           - accepted for source compatibility, not forwarded.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_EraseSector(flash_config_t *config,
                                          uint32_t        start,
                                          uint32_t        lengthInBytes,
                                          uint32_t        key)
{
    int32_t result = -1;
    (void)config;
    (void)key;
    (void)tfm_platform_flash_erase(start, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_ProgramPhrase -- NS proxy.
 *
 * Tunnels the program-phrase request to the S partition via IOCTL.
 * start         - NS-alias flash offset (phrase-aligned, 16-byte multiple).
 * src           - pointer to source data in NS RAM.
 * lengthInBytes - bytes to write (16-byte multiple).
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_ProgramPhrase(flash_config_t *config,
                                            uint32_t        start,
                                            uint8_t        *src,
                                            uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)tfm_platform_flash_program_phrase(start, src, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_ProgramPage -- NS proxy.
 *
 * Tunnels the program-page request to the S partition via IOCTL.
 * A page on MCXL/MCXA is 128 bytes; the S side enforces 128-byte alignment.
 * start         - NS-alias flash offset (page-aligned, 128-byte multiple).
 * src           - pointer to source data in NS RAM.
 * lengthInBytes - bytes to write (128-byte multiple).
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_ProgramPage(flash_config_t *config,
                                          uint32_t        start,
                                          uint8_t        *src,
                                          uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)tfm_platform_flash_program_page(start, src, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_VerifyProgram -- NS proxy.
 *
 * Tunnels the verify-program request to the S partition via IOCTL.
 * start         - NS-alias flash offset (phrase-aligned).
 * lengthInBytes - bytes to verify (phrase-aligned).
 * expectedData  - pointer to reference data in NS RAM.
 * failedAddress - receives first failing flash address on mismatch.
 * failedData    - receives data read at the failing address on mismatch.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_VerifyProgram(flash_config_t *config,
                                            uint32_t        start,
                                            uint32_t        lengthInBytes,
                                            const uint8_t  *expectedData,
                                            uint32_t       *failedAddress,
                                            uint32_t       *failedData)
{
    int32_t  result         = -1;
    uint32_t failed_address = 0U;
    uint32_t failed_data    = 0U;
    (void)config;
    (void)tfm_platform_flash_verify_program(start, lengthInBytes, expectedData,
                                             &failed_address, &failed_data,
                                             &result);
    if (failedAddress != NULL)
    {
        *failedAddress = failed_address;
    }
    if (failedData != NULL)
    {
        *failedData = failed_data;
    }
    return (status_t)result;
}

/*
 * FLASH_VerifyErasePhrase -- NS proxy.
 *
 * Tunnels the verify-erase-phrase request to the S partition via IOCTL.
 * start         - NS-alias flash offset.
 * lengthInBytes - bytes to check.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_VerifyErasePhrase(flash_config_t *config,
                                                uint32_t        start,
                                                uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)tfm_platform_flash_verify_erase_phrase(start, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_VerifyErasePage -- NS proxy.
 *
 * Tunnels the verify-erase-page request to the S partition via IOCTL.
 * start         - NS-alias flash offset.
 * lengthInBytes - bytes to check.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_VerifyErasePage(flash_config_t *config,
                                              uint32_t        start,
                                              uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    (void)tfm_platform_flash_verify_erase_page(start, lengthInBytes, &result);
    return (status_t)result;
}

/*
 * FLASH_VerifyEraseSector -- NS proxy.
 *
 * Tunnels the verify-erase-sector request to the S partition via IOCTL.
 * start         - NS-alias flash offset (sector-aligned).
 * lengthInBytes - bytes to check (sector-aligned).
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_VerifyEraseSector(flash_config_t *config,
                                                uint32_t        start,
                                                uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
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
 * FLASH_Read -- NS proxy.
 *
 * Tunnels the flash read request to the S partition via IOCTL.
 * start         - NS-alias flash offset.
 * dest          - destination buffer in NS RAM.
 * lengthInBytes - bytes to read.
 * config        - accepted for source compatibility, not used.
 */
static inline status_t FLASH_Read(flash_config_t *config,
                                   uint32_t        start,
                                   uint8_t        *dest,
                                   uint32_t        lengthInBytes)
{
    int32_t result = -1;
    (void)config;
    /* dest pointer is embedded in the args struct so the S side can
     * CMSE-check it and write directly into the NS buffer. */
    (void)tfm_platform_flash_read(start, dest, lengthInBytes, &result);
    return (status_t)result;
}

#ifdef __cplusplus
}
#endif

#endif /* FSL_FLASH_NS_PROXY_MCXL_MCXA_H__ */
