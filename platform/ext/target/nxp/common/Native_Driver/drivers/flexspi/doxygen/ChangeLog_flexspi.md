# FLEXSPI

## [2.9.3]

- Bug Fixes
  - Fixed CERT INT30-C violations in FLEXSPI_TransferBlocking: added assert guards before unsigned
    arithmetic on flashAddress to prevent wrap-around.
  - Fixed CERT INT31-C violations in FLEXSPI_Init and FLEXSPI_UpdateAhbBuffersSettings: added
    assert to verify FSL_FEATURE_FLEXSPI_AHB_RX_BUFFER_SIZEn returns a non-negative value before
    casting to uint32_t.

## [2.9.2]

- New Features
  - Added common IRQ handler entry FLEXSPI_CommonDriverIRQHandler.

## [2.9.1]

- Bug Fixes
  - Fixed CERT INT31-C violations: added masks before uint8_t casts and replaced bool fields with ternary expressions.
- Improvements
  - Modified FLEXSPI_WriteBlocking() to trigger IP command after TX FIFO is filled
    or when all data has been written, preventing premature command execution
  - Updated `FLEXSPI_TransferBlocking()` to distinguish between Write and Read operation flows according to FlexSPI IP command specification.
    - For Write/Program operations: Fill IP transmit FIFO with data before triggering the IP command.
    - For Read operations: Trigger IP command first, then read data from IP receive FIFO.
    - Added detailed flow comments for both Write and Read operations.

## [2.9.0]

- New Features
  - Added FlexSPI root clock divider configuration.

- Bug Fixes
  - Add explicit boolean to integer conversions (? 1U : 0U) for all enable flags
  - Add assertions to prevent unsigned integer overflow in buffer size calculations
  - Add assertions to prevent unsigned integer underflow in watermark calculations
  - Add safe type conversion for uint32_t to uint8_t operations
  - Add bounds checking assertion for LUT index operations
  - Follow INT30-C and INT31-C CERT coding standards

## [2.8.1]

- Improvements
  - Updated the LUT configuration parameter checking with flexible way to adapt different Socs.

## [2.8.0]
- Bug Fixes
  - Introduced the **disableAhbReadResume** field in the flexspi_config_t structure to provide control over
    the AHBCR[RESUMEDISABLE] register bit.
  - Implemented a workaround for hardware erratum ERR052733 by setting the default value of
    **disableAhbReadResume** to **true**.
  - Fixed issue in `FLEXSPI_TransferHandleIRQ` where the transfer completion was incorrectly signaled
    despite pending read/write operations.

- New Features
  - Introduced a new function(`FLEXSPI_UpdateAhbBuffersSettings`) that allows users to update the AHB buffer configuration after the FLEXSPI module has been initialized

## [2.7.0]

- New Features
  - Added new API to support address remapping.

## [2.6.4]

- Improvements
  - Added new macro "FSL_SDK_ENABLE_FLEXSPI_RESET_CONTROL" to support driver level reset control.

## [2.6.3]

- Bug Fixes
  - Fixed an issue which cause IPCR1[IPAREN] cleared by mistake.

## [2.6.2]

- Bug Fixes
  - Wait Bus IDLE before operation of FLEXSPI_SoftwareReset(), FLEXSPI_TransferBlocking() and
    FLEXSPI_TransferNonBlocking().

## [2.6.1]

- Bug Fixes
  - Updated code of reset peripheral.
  - Updated FLEXSPI_UpdateLUT() to check if input lut address is not in Flexspi AMBA region.
  - Updated FLEXSPI_Init() to check if input AHB buffer size exceeded maximum AHB size.

## [2.6.0]

- New Features
  - Added new API to set AHB memory-mapped flash base address.
  - Added support of DLLxCR[REFPHASEGAP] bit field, it is recommended to set it as 0x2 if DLL
    calibration is enabled.

## [2.5.1]

- Bugfixes
  - Fixed handling of W1C bits in the INTR register
  - Removed FIFO resets from FLEXSPI_CheckAndClearError
  - FLEXSPI_TransferBlocking is observing IPCMDDONE and then fetches the final status of the transfer
  - Fixed issue that FLEXSPI2_DriverIRQHandler not defined.

## [2.5.0]

- Improvements
  - Supported word un-aligned access for write/read blocking/non-blocking API functions.
  - Fixed dead loop issue in DLL update function when using FRO clock source.
  - Fixed violations of the MISRA C-2012 Rule 10.3.

## [2.4.0]

- Improvements
  - Isolated IP command parallel mode and AHB command parallel mode using feature MACRO.
  - Supported new column address shift feature for external memory.

## [2.3.5]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 14.2.

## [2.3.4]

- Bug Fixes
  - Updated flexspi_config_t structure and FlexSPI_Init to support new feature FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_CONBINATION.

## [2.3.3]

- Bug Fixes
  - Removed feature FSL_FEATURE_FLEXSPI_DQS_DELAY_PS for DLL delay setting. Changed to use feature FSL_FEATURE_FLEXSPI_DQS_DELAY_MIN to set slave delay target as 0 for DLL enable and clock frequency higher than 100MHz.

## [2.3.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 8.4, 8.5, 10.1, 10.3, 10.4, 11.6 and 14.4.

## [2.3.1]

- Bug Fixes
  - Wait for bus to be idle before using it as access to external flash with new setting in FLEXSPI_SetFlashConfig() API.
  - Fixed the potential buffer overread and Tx FIFO overwrite issue in FLEXSPI_WriteBlocking.

## [2.3.0]

- New Features
  - Added new API FLEXSPI_UpdateDllValue for users to update DLL value after updating flexspi root clock.
  - Corrected grammatical issues for comments.
  - Added support for new feature FSL_FEATURE_FLEXSPI_DQS_DELAY_PS in DLL configuration.

## [2.2.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.1, 10.3 and 10.4.
  - Updated _flexspi_command from named enumerator into anonymous enumerator.

## [2.2.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.1, 10.3, 10.4, 10.8, 11.9, 14.4, 15.7, 16.4, 17.7, 7.3.
  - Fixed IAR build warning Pe167.
  - Fixed the potential buffer overwrite and Rx FIFO overread issue in FLEXSPI_ReadBlocking.

## [2.2.0]

- Bug Fixes
  - Fixed flag name typos: kFLEXSPI_IpTxFifoWatermarkEmpltyFlag to kFLEXSPI_IpTxFifoWatermarkEmptyFlag;
    kFLEXSPI_IpCommandExcutionDoneFlag to kFLEXSPI_IpCommandExecutionDoneFlag.
  - Fixed comments typos such as sequencen->sequence, levle->level.
  - Fixed FLSHCR2[ARDSEQID] field clean issue.
  - Updated flexspi_config_t structure and FlexSPI_Init to support new feature FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_ATDFEN
    and FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_ARDFEN.
  - Updated flexspi_flags_t structure to support new feature FSL_FEATURE_FLEXSPI_HAS_INTEN_AHBBUSERROREN.

## [2.1.1]

- Improvements
  - Defaulted enable prefetch for AHB RX buffer configuration in FLEXSPI_GetDefaultConfig, which is align with the
    reset value in AHBRXBUFxCR0.
  - Added software workaround for ERR011377 in FLEXSPI_SetFlashConfig; added some delay after DLL lock status set
    to ensure correct data read/write.

## [2.1.0]

- New Features
  - Added new API FLEXSPI_UpdateRxSampleClock for users to update read sample clock source after initialization.
  - Added reset peripheral operation in FLEXSPI_Init if required.

## [2.0.5]

- Bug Fixes
  - Fixed FLEXSPI_UpdateLUT cannot do partial update issue.

## [2.0.4]

- Bug Fixes
  - Reset flash size to zero for all ports in FLEXSPI_Init; fixed the possible out-of-range flash access with no
    error reported.

## [2.0.3]

- Bug Fixes
  - Fixed AHB receive buffer size configuration issue. The FLEXSPI_AHBRXBUFCR0_BUFSZ field should configure 64 bits
    size, and currently the AHB receive buffer size is in bytes which means 8-bit, so the correct configuration
    should be config->ahbConfig.buffer[i].bufferSize / 8.

## [2.0.2]

- New Features
  - Supported DQS write mask enable/disable feature during set FLEXSPI configuration.
  - Provided new API FLEXSPI_TransferUpdateSizeEDMA for users to update eDMA transfer size(SSIZE/DSIZE) per DMA
    transfer.
- Bug Fixes
  - Fixed invalid operation of FLEXSPI_Init to enable AHB bus Read Access to IP RX FIFO.
  - Fixed incorrect operation of FLEXSPI_Init to configure IP TX FIFO watermark.

## [2.0.1]

- Bug Fixes
  - Fixed the flag clear issue and AHB read Command index configuration issue in FLEXSPI_SetFlashConfig.
  - Updated FLEXSPI_UpdateLUT function to update LUT table from any index instead of previous command index.
  - Added bus idle wait in FLEXSPI_SetFlashConfig and FLEXSPI_UpdateLUT to ensure bus is idle before any
    change to FlexSPI controller.
  - Updated interrupt API FLEXSPI_TransferNonBlocking and interrupt handle flow FLEXSPI_TransferHandleIRQ.
  - Updated eDMA API FLEXSPI_TransferEDMA.

## [2.0.0]

- Initial version.
