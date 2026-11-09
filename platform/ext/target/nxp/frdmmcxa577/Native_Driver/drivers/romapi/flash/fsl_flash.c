/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MCUX_ROMAPI_TFM_INTERFACE

#include "fsl_flash.h"
#include "fsl_flexspi_nor_flash.h"
#include "fsl_lpspi_flash.h"
#include "fsl_romapi_tree.h"

/*! @brief Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.romapi_flashiap"
#endif

/*!
 * @name flash,ifr
 * @{
 */

/*!
 * @brief Structure of version property.
 *
 * @ingroup flash_driver
 */

/*! @brief FLEXSPI Flash driver API Interface */
typedef struct
{
    uint32_t version;
    status_t (*init)(uint32_t instance, flexspi_nor_config_t *config);
    status_t (*page_program)(uint32_t instance, flexspi_nor_config_t *config, uint32_t dstAddr, const uint32_t *src);
    status_t (*erase_all)(uint32_t instance, flexspi_nor_config_t *config);
    status_t (*erase)(uint32_t instance, flexspi_nor_config_t *config, uint32_t start, uint32_t length);
    status_t (*erase_sector)(uint32_t instance, flexspi_nor_config_t *config, uint32_t address);
    status_t (*erase_block)(uint32_t instance, flexspi_nor_config_t *config, uint32_t address);
    status_t (*get_config)(uint32_t instance, flexspi_nor_config_t *config, serial_nor_config_option_t *option);
    status_t (*read)(uint32_t instance, flexspi_nor_config_t *config, uint32_t *dst, uint32_t start, uint32_t bytes);
    status_t (*xfer)(uint32_t instance, flexspi_xfer_t *xfer);
    status_t (*update_lut)(uint32_t instance, uint32_t seqIndex, const uint32_t *lutBase, uint32_t numberOfSeq);
    status_t (*set_clock_source)(uint32_t clockSrc);
    void (*config_clock)(uint32_t instance, uint32_t freqOption, uint32_t sampleClkMode);
    status_t (*partial_program)(
        uint32_t instance, flexspi_nor_config_t *config, uint32_t dstAddr, const uint32_t *src, uint32_t length);
} flexspi_nor_flash_driver_t;

/*! @brief Interface for the external SPI flash driver via SPI NOR/EEPROM */
typedef struct LpspiFlashDriverInterface
{
    status_t (*spi_eeprom_init)(void);
    status_t (*spi_eeprom_read)(uint32_t address, uint32_t NoOfBytes, uint8_t *restrict buffer);
    status_t (*spi_eeprom_write)(uint32_t address, uint32_t NoOfBytes, const uint8_t *buffer);
    status_t (*spi_eeprom_erase)(uint32_t address, uint32_t length);
    status_t (*spi_eeprom_config)(uint32_t *config);
    status_t (*spi_eeprom_flush)(void);
    void *reserved0;
    status_t (*spi_eeprom_erase_all)(void);
} LPSPI_EEPROM_driver_interface_t;

/*! @brief Interface for the flash driver.*/
typedef struct FlashDriverInterface
{
    /* Flash driver */
    status_t (*flash_init)(flash_config_t *config);
    status_t (*flash_erase_sector)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key);
    status_t (*flash_program_phrase)(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes);
    status_t (*flash_program_page)(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes);
    status_t (*flash_verify_program)(flash_config_t *config,
                                     uint32_t start,
                                     uint32_t lengthInBytes,
                                     const uint8_t *expectedData,
                                     uint32_t *failedAddress,
                                     uint32_t *failedData);
    status_t (*flash_verify_erase_phrase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_page)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_sector)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_get_property)(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);
    /* IFR driver */
    status_t (*ifr_verify_erase_phrase)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*ifr_verify_erase_page)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*ifr_verify_erase_sector)(flash_config_t *config, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_read)(flash_config_t *config, uint32_t start, uint8_t *dest, uint32_t lengthInBytes);
    /* version */
    standard_version_t version;
} flash_driver_interface_t;

/*! @}*/

#define FLASH_DRIVER        ((const flash_driver_interface_t *)BOOTLOADER_API_TREE_POINTER->flashDriver)
#define FLEXSPI_NOR_DRIVER  ((const flexspi_nor_flash_driver_t *)BOOTLOADER_API_TREE_POINTER->flexspiNorDriver)
#define LPSPI_EEPROM_DRIVER ((const LPSPI_EEPROM_driver_interface_t *)BOOTLOADER_API_TREE_POINTER->lpspiFlashDriver)

/*******************************************************************************
 * Code
 ******************************************************************************/

/********************************************************************************
 * Internal Flash driver API
 *******************************************************************************/
/*!
 * @brief Initializes the global flash properties structure members.
 *
 * This function checks and initializes the Flash module for the other Flash APIs.
 */
status_t FLASH_Init(flash_config_t *config)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_init(config);
}

/*!
 * @brief Erases the flash sectors encompassed by parameters passed into function.
 *
 * This function erases the appropriate number of flash sectors based on the
 * desired start address and length.
 */
status_t FLASH_EraseSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_erase_sector(config, start, lengthInBytes, key);
}

/*!
 * @brief Programs flash with data at locations passed in through parameters.
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and the length.
 */
status_t FLASH_ProgramPhrase(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_program_phrase(config, start, src, lengthInBytes);
}

/*!
 * @brief Programs flash with data at locations passed in through parameters.
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and the length.
 */
status_t FLASH_ProgramPage(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_program_page(config, start, src, lengthInBytes);
}

/*!
 * @brief Verifies programming of the desired flash area at a specified margin level.
 *
 * This function verifies the data programed in the flash memory using the
 * Flash Program Check Command and compares it to the expected data for a given
 * flash area as determined by the start address and length.
 */
status_t FLASH_VerifyProgram(flash_config_t *config,
                             uint32_t start,
                             uint32_t lengthInBytes,
                             const uint8_t *expectedData,
                             uint32_t *failedAddress,
                             uint32_t *failedData)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_verify_program(config, start, lengthInBytes, expectedData, failedAddress, failedData);
}

/*!
 * @brief Verifies an erasure of the desired flash area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the flash is erased
 * to the specified read margin level.
 */
status_t FLASH_VerifyErasePhrase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_verify_erase_phrase(config, start, lengthInBytes);
}

/*!
 * @brief Verifies an erasure of the desired flash area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the flash is erased
 * to the specified read margin level.
 */
status_t FLASH_VerifyErasePage(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_verify_erase_page(config, start, lengthInBytes);
}

/*!
 * @brief Verifies an erasure of the desired flash area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the flash is erased
 * to the specified read margin level.
 */
status_t FLASH_VerifyEraseSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_verify_erase_sector(config, start, lengthInBytes);
}

/*!
 * @brief Returns the desired flash property.
 */
status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_get_property(config, whichProperty, value);
}

/*!
 * @brief Reads data from the desired flash area.
 *
 * This function reads data from the flash memory for a given flash area as
 * determined by the start address and the length.
 */
status_t FLASH_Read(flash_config_t *config, uint32_t start, uint8_t *dest, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->flash_read(config, start, dest, lengthInBytes);
}

/*!
 * @brief Verifies an erasure of the desired IFR area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the IFR is erased
 * to the specified read margin level.
 */
status_t IFR_VerifyErasePhrase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->ifr_verify_erase_phrase(config, start, lengthInBytes);
}

/*!
 * @brief Verifies an erasure of the desired IFR area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the IFR is erased
 * to the specified read margin level.
 */
status_t IFR_VerifyErasePage(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->ifr_verify_erase_page(config, start, lengthInBytes);
}

/*!
 * @brief Verifies an erasure of the desired IFR area at a specified margin level.
 *
 * This function checks the appropriate number of flash sectors based on
 * the desired start address and length to check whether the IFR is erased
 * to the specified read margin level.
 */
status_t IFR_VerifyEraseSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->ifr_verify_erase_sector(config, start, lengthInBytes);
}

/*!
 * @brief Gets the flash driver version.
 *
 * This function returns the version information of the flash driver.
 */
standard_version_t FLASH_GetAPIVersion(flash_config_t *config)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLASH_DRIVER->version;
}

/********************************************************************************
 * FlexSPI Nor driver API
 *******************************************************************************/

/*!
 * @brief Initialize FlexSPI NOR flash.
 *
 * This function initializes the FlexSPI NOR flash with the given configuration.
 */
status_t FLEXSPI_NorFlash_Init(uint32_t instance, flexspi_nor_config_t *config)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->init(instance, config);
}

/*!
 * @brief Program page data to FlexSPI NOR flash.
 *
 * This function programs data to the FlexSPI NOR flash at the specified address.
 */
status_t FLEXSPI_NorFlash_ProgramPage(uint32_t instance,
                                      flexspi_nor_config_t *config,
                                      uint32_t dstAddr,
                                      const uint32_t *src)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->page_program(instance, config, dstAddr, src);
}

/*!
 * @brief Erase all FlexSPI NOR flash.
 *
 * This function erases the entire FlexSPI NOR flash.
 */
status_t FLEXSPI_NorFlash_EraseAll(uint32_t instance, flexspi_nor_config_t *config)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->erase_all(instance, config);
}

/*!
 * @brief Erase FlexSPI NOR flash region.
 *
 * This function erases the specified region of FlexSPI NOR flash.
 */
status_t FLEXSPI_NorFlash_Erase(uint32_t instance, flexspi_nor_config_t *config, uint32_t start, uint32_t length)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->erase(instance, config, start, length);
}

/*!
 * @brief Erase FlexSPI NOR flash sector.
 *
 * This function erases a sector of FlexSPI NOR flash at the specified address.
 */
status_t FLEXSPI_NorFlash_EraseSector(uint32_t instance, flexspi_nor_config_t *config, uint32_t address)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->erase_sector(instance, config, address);
}

/*!
 * @brief Erase FlexSPI NOR flash block.
 *
 * This function erases a block of FlexSPI NOR flash at the specified address.
 */
status_t FLEXSPI_NorFlash_EraseBlock(uint32_t instance, flexspi_nor_config_t *config, uint32_t address)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->erase_block(instance, config, address);
}

/*!
 * @brief Get FlexSPI NOR flash configuration.
 *
 * This function gets the configuration of FlexSPI NOR flash.
 */
status_t FLEXSPI_NorFlash_GetConfig(uint32_t instance, flexspi_nor_config_t *config, serial_nor_config_option_t *option)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->get_config(instance, config, option);
}

/*!
 * @brief Read data from FlexSPI NOR flash.
 *
 * This function reads data from FlexSPI NOR flash at the specified address.
 */
status_t FLEXSPI_NorFlash_Read(
    uint32_t instance, flexspi_nor_config_t *config, uint32_t *dst, uint32_t start, uint32_t bytes)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->read(instance, config, dst, start, bytes);
}

/*!
 * @brief Perform FlexSPI transfer.
 *
 * This function performs a FlexSPI transfer operation.
 */
status_t FLEXSPI_NorFlash_Xfer(uint32_t instance, flexspi_xfer_t *xfer)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->xfer(instance, xfer);
}

/*!
 * @brief Update FlexSPI LUT.
 *
 * This function updates the FlexSPI Look-Up Table.
 */
status_t FLEXSPI_NorFlash_UpdateLut(uint32_t instance, uint32_t seqIndex, const uint32_t *lutBase, uint32_t numberOfSeq)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->update_lut(instance, seqIndex, lutBase, numberOfSeq);
}

/*!
 * @brief Set FlexSPI clock source.
 *
 * This function sets the clock source for FlexSPI.
 */
status_t FLEXSPI_NorFlash_SetClockSource(uint32_t clockSrc)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->set_clock_source(clockSrc);
}

/*!
 * @brief Configure FlexSPI clock.
 *
 * This function configures the FlexSPI clock settings.
 */
void FLEXSPI_NorFlash_ConfigClock(uint32_t instance, uint32_t freqOption, uint32_t sampleClkMode)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    FLEXSPI_NOR_DRIVER->config_clock(instance, freqOption, sampleClkMode);
}

/*!
 * @brief Partial program data to FlexSPI NOR flash.
 *
 * This function performs partial programming of data to FlexSPI NOR flash.
 */
status_t FLEXSPI_NorFlash_PartialProgram(
    uint32_t instance, flexspi_nor_config_t *config, uint32_t dstAddr, const uint32_t *src, uint32_t length)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return FLEXSPI_NOR_DRIVER->partial_program(instance, config, dstAddr, src, length);
}

/********************************************************************************
 * LPSPI Flash driver API
 *******************************************************************************/

/*!
 * @brief Initialize SPI EEPROM.
 *
 * This function initializes the SPI EEPROM.
 */
status_t LPSPI_EepromInit(void)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return LPSPI_EEPROM_DRIVER->spi_eeprom_init();
}

/*!
 * @brief Read data from SPI EEPROM.
 *
 * This function reads data from SPI EEPROM at the specified address.
 */
status_t LPSPI_EepromRead(uint32_t address, uint32_t NoOfBytes, uint8_t *restrict buffer)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return LPSPI_EEPROM_DRIVER->spi_eeprom_read(address, NoOfBytes, buffer);
}

/*!
 * @brief Write data to SPI EEPROM.
 *
 * This function writes data to SPI EEPROM at the specified address.
 */
status_t LPSPI_EepromWrite(uint32_t address, uint32_t NoOfBytes, const uint8_t *buffer)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return LPSPI_EEPROM_DRIVER->spi_eeprom_write(address, NoOfBytes, buffer);
}

/*!
 * @brief Erase SPI EEPROM region.
 *
 * This function erases the specified region of SPI EEPROM.
 */
status_t LPSPI_EepromErase(uint32_t address, uint32_t length)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return LPSPI_EEPROM_DRIVER->spi_eeprom_erase(address, length);
}

/*!
 * @brief Configure SPI EEPROM.
 *
 * This function configures the SPI EEPROM with the given configuration.
 */
status_t LPSPI_EepromConfig(uint32_t *config)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return LPSPI_EEPROM_DRIVER->spi_eeprom_config(config);
}

/*!
 * @brief Flush SPI EEPROM.
 *
 * This function flushes the SPI EEPROM.
 */
status_t LPSPI_EepromFlush(void)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return LPSPI_EEPROM_DRIVER->spi_eeprom_flush();
}

/*!
 * @brief Erase all SPI EEPROM.
 *
 * This function erases the entire SPI EEPROM.
 */
status_t LPSPI_EepromEraseAll(void)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return LPSPI_EEPROM_DRIVER->spi_eeprom_erase_all();
}

#endif /* MCUX_ROMAPI_TFM_INTERFACE */