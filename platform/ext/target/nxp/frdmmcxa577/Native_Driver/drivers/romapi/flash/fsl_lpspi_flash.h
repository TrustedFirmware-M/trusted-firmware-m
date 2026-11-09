/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _FSL_LPSPI_EepromH__
#define _FSL_LPSPI_EepromH__

#include "fsl_common.h"

/*!
 * @addtogroup flash_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define kROM_StatusGroup_LPSPI 4 /*!< ROM Group number for LPSPI status codes. */

/*! @brief LPSPI Flash status codes */
enum
{
    kStatus_ROM_LPSPI_Busy       = MAKE_STATUS(kROM_StatusGroup_LPSPI, 0), /*!< LPSPI transfer is busy.*/
    kStatus_ROM_LPSPI_Error      = MAKE_STATUS(kROM_StatusGroup_LPSPI, 1), /*!< LPSPI driver error. */
    kStatus_ROM_LPSPI_Idle       = MAKE_STATUS(kROM_StatusGroup_LPSPI, 2), /*!< LPSPI is idle.*/
    kStatus_ROM_LPSPI_OutOfRange = MAKE_STATUS(kROM_StatusGroup_LPSPI, 3)  /*!< LPSPI transfer out Of range. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name LPSPI Flash Operations
 * @{
 */

/*!
 * @brief Initialize SPI NOR/EEPROM
 *
 * @param baudRate Config baudrate for SPI.
 *
 * @retval #kStatus_Fail EEPROM initialization failed.
 * @retval #kStatus_InvalidArgument Invalid input parameter.
 * @retval #kStatus_ROM_LPSPI_Busy LPSPI transfer is busy.
 * @retval #kStatus_Success The eeprom is initialized successfully.
 */
status_t LPSPI_EepromInit(void);

/*!
 * @brief Read data via SPI NOR/EEPROM
 *
 * @param dest A pointer to the buffer of data that is to be read from eeprom.
 * @param length The length, given in bytes to be read.
 * @param address The start address of the desired eeprom memory to be read.
 * @param requestFastRead The type of Read eeprom command.
 *        FALSE: Use the general Read command to read eeprom
 *        TRUE: Use Fast Read command to read data from eeprom.
 *
 * @retval #kStatus_Fail Failed to read data from eeprom.
 * @retval #kStatus_Success Read data from eeprom successfully.
 * @retval #kStatus_InvalidArgument Invalid input parameter.
 * @retval #kStatus_ROM_LPSPI_Busy LPSPI transfer is busy.
 */
status_t LPSPI_EepromRead(uint32_t address, uint32_t NoOfBytes, uint8_t *restrict buffer);

/*!
 * @brief Write data via SPI NOR/EEPROM
 *
 * @param data A pointer to the source buffer of data that is to be programmed into the eeprom.
 * @param length The length, given in bytes to be programmed.
 * @param address The start address of the desired eeprom memory to be programed.
 *
 * @retval #kStatus_Fail Failed to write data to eeprom.
 * @retval #kStatus_Success Successfully write data to eeprom.
 * @retval #kStatus_InvalidArgument Invalid input parameter.
 * @retval #kStatus_ROM_LPSPI_Busy LPSPI transfer is busy.
 */
status_t LPSPI_EepromWrite(uint32_t address, uint32_t NoOfBytes, const uint8_t *buffer);

/*!
 * @brief Erase data via SPI NOR/EEPROM
 *
 * @param address The start address of the desired eeprom memory to be erased.
 * @param option The length, given in bytes to be erased.
 *
 * @retval #kStatus_Fail Failed to erase data frome the eeprom.
 * @retval #kStatus_Success Erase data from eeprom successfully.
 * @retval #kStatus_InvalidArgument Invalid input parameter.
 * @retval #kStatus_ROM_LPSPI_Busy LPSPI transfer is busy.
 */
status_t LPSPI_EepromErase(uint32_t address, uint32_t length);

/*!
 * @brief Configure SPI EEPROM.
 *
 * This function configures the SPI EEPROM with the given configuration parameters.
 *
 * @param config A pointer to the configuration parameters.
 *               The specific format depends on the EEPROM device type.
 *
 * @retval #kStatus_Fail Failed to erase data frome the eeprom.
 * @retval #kStatus_Success Erase data from eeprom successfully.
 * @retval #kStatus_InvalidArgument Invalid input parameter.
 * @retval #kStatus_ROM_LPSPI_Busy LPSPI transfer is busy.
 */
status_t LPSPI_EepromConfig(uint32_t *config);

/*!
 * @brief Flush SPI EEPROM.
 *
 * This function flushes any pending operations and ensures all data
 * is written to the SPI EEPROM.
 *
 * @retval #kStatus_Fail Failed to erase data frome the eeprom.
 * @retval #kStatus_Success Erase data from eeprom successfully.
 * @retval #kStatus_InvalidArgument Invalid input parameter.
 * @retval #kStatus_ROM_LPSPI_Busy LPSPI transfer is busy.
 */
status_t LPSPI_EepromFlush(void);

/*!
 * @brief Erase all SPI EEPROM.
 *
 * This function erases the entire SPI EEPROM device.
 *
 * @retval #kStatus_Fail Failed to erase data frome the eeprom.
 * @retval #kStatus_Success Erase data from eeprom successfully.
 * @retval #kStatus_InvalidArgument Invalid input parameter.
 * @retval #kStatus_ROM_LPSPI_Busy LPSPI transfer is busy.
 */
status_t LPSPI_EepromEraseAll(void);

/*! @} */

#ifdef __cplusplus
}
#endif

/*! @} */

#endif /* _FSL_LPSPI_EepromH__ */