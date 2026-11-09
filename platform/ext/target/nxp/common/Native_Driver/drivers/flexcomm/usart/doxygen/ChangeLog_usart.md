# USART

## [2.9.0]

- New Features
  - Added support for RS-485 (configuration of OESEL, OEPOL, OETA in CFG register).
  - Added handling when a start is detected on the receiver input in USART_TransferHandleIRQ().

## [2.8.5]

- Bug Fixes
  - Fixed race condition during call of USART_EnableTxDMA and USART_EnableRxDMA.

## [2.8.4]

- Bug Fixes
  - Fixed exclusive access in USART_TransferReceiveNonBlocking and USART_TransferSendNonBlocking.

## [2.8.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.3, 11.8.

## [2.8.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 14.2.

## [2.8.1]

- Bug Fixes
  - Fixed the Baud Rate Generator(BRG) configuration in 32kHz mode.

## [2.8.0]

- New Features
  - Added the rx timeout interrupts and status flags of bus status.
  - Added new rx timeout configuration item in usart_config_t.
  - Added API USART_SetRxTimeoutConfig for rx timeout configuration.
- Improvements
  - When the calculated baudrate cannot meet user's configuration, lower OSR value is allewed to use.

## [2.7.0]

- New Features
  - Added the missing interrupts and status flags of bus status.
  - Added the check of tx error, noise error framing error and parity error in interrupt handler.

## [2.6.0]

- Improvements
  - Used separate data for TX and RX in usart_transfer_t.
- Bug Fixes
  - Fixed bug that when ring buffer is used, if some data is received in ring buffer first before calling
    USART_TransferReceiveNonBlocking, the received data count returned by USART_TransferGetReceiveCount is wrong.
- New Features
  - Added missing API USART_TransferGetSendCountDMA get send count using DMA.

## [2.5.0]

- New Features
  - Added APIs USART_GetRxFifoCount/USART_GetTxFifoCount to get rx/tx FIFO data count.
  - Added APIs USART_SetRxFifoWatermark/USART_SetTxFifoWatermark to set rx/tx FIFO water mark.
- Bug Fixes
  - Fixed DMA transfer blocking issue by enabling tx idle interrupt after DMA transmission finishes.

## [2.4.0]

- New Features
  - Modified usart_config_t, USART_Init and USART_GetDefaultConfig APIs so that the hardware flow control can be
    enabled during module initialization.
- Bug Fixes
  - Fixed MISRA 10.4 violation.

## [2.3.1]

- Bug Fixes
  - Fixed bug that operation on INTENSET, INTENCLR, FIFOINTENSET and FIFOINTENCLR should use bitwise operation not
    'or' operation.
  - Fixed bug that if rx interrupt occurrs before TX interrupt is enabled and after txDataSize is configured, the
    data will be sent early by mistake, thus TX interrupt will be enabled after data is sent out.
- Improvements
  - Added check for baud rate's accuracy that returns kStatus_USART_BaudrateNotSupport when the best achieved baud
    rate is not within 3% error of configured baud rate.

## [2.3.0]

- New Features
  - Added APIs to configure 9-bit data mode, set slave address and send address.
  - Modified USART_TransferReceiveNonBlocking and USART_TransferHandleIRQ to use 9-bit mode in multi-slave system.

## [2.2.0]

- New Features
  - Added the feature of supporting USART working at 32 kHz clocking mode.
- Improvements
  - Modified USART_TransferHandleIRQ so that txState will be set to idle only when all data has been sent out to bus.
  - Modified USART_TransferGetSendCount so that this API returns the real byte count that USART has sent out rather
    than the software buffer status.
  - Added timeout mechanism when waiting for certain states in transfer driver.
- Bug Fixes
  - Fixed MISRA 10.1 issues.
  - Fixed bug that operation on INTENSET, INTENCLR, FIFOINTENSET and FIFOINTENCLR should use bitwise operation not
    'or' operation.
  - Fixed bug that if rx interrupt occurrs before TX interrupt is enabled and after txDataSize is configured, the
    data will be sent early by mistake, thus TX interrupt will be enabled after data is sent out.

## [2.1.1]

- Improvements
  - Added check for transmitter idle in USART_TransferHandleIRQ and USART_TransferSendDMACallback to ensure all
    the data would be sent out to bus.
  - Modified USART_ReadBlocking so that if more than one receiver errors occur, all status flags will be cleared
    and the most severe error status will be returned.
- Bug Fixes
  - Eliminated IAR Pa082 warnings.
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 10.7, 10.8, 11.3, 11.6, 11.8, 11.9, 13.5.

## [2.1.0]

- New Features
  - Added features to allow users to configure the USART to synchronous transfer(master and slave) mode.
- Bug Fixes
  - Modified USART_SetBaudRate to get more acurate configuration.

## [2.0.3]

- New Features
  - Added new APIs to allow users to enable the CTS which determines whether CTS is used for flow control.

## [2.0.2]

- Bug Fixes
  - Fixed the bug where transfer abort APIs could not disable the interrupts. The FIFOINTENSET register should not be
    used to disable the interrupts, so use the FIFOINTENCLR register instead.

## [2.0.1]

- Improvements
  - Unified the component full name to FLEXCOMM USART (DMA/FREERTOS) driver.

## [2.0.0]

- Initial version.
