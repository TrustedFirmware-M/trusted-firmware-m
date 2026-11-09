# SPI

## [2.4.0]

- New Features
  - Added `kSPI_FrameAssertEachFrame` to deassert PCS at the end of every frame.

## [2.3.2]

- Bug Fixes
  - Fixed the txData from void * to const void * in transmit API

## [2.3.1]

- Improvements
  - Changed SPI_DUMMYDATA to 0x00.

## [2.3.0]

- Update version.

## [2.2.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA 2012 10.4 issue.
  - Added code to clear FIFOs before transfer using DMA.

## [2.2.0]

- Bug Fixes
  - Fixed bug that slave gets stuck during interrupt transfer.

## [2.1.1]

- Improvements
  - Added timeout mechanism when waiting certain states in transfer driver.
- Bug Fixes
  - Fixed MISRA 10.1, 5.7 issues.

## [2.1.0]

- Bug Fixes
  - Fixed Coverity issue of incrementing null pointer in SPI_TransferHandleIRQInternal.
  - Eliminated IAR Pa082 warnings.
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 10.7, 10.8, 11.3, 11.6, 11.8, 11.9, 13.5.
- New Features
  - Modified the definition of SPI_SSELPOL_MASK to support the socs that have only 3 SSEL pins.

## [2.0.4]

- Bug Fixes
  - Fixed the bug of using read only mode in DMA transfer. In DMA transfer mode, if transfer->txData is NULL, code
    attempts to read data from the address of 0x0 for configuring the last frame.
  - Fixed wrong assignment of handle->state. During transfer handle->state should be kSPI_Busy rather than
    kStatus_SPI_Busy.
- Improvements
  - Rounded up the calculated divider value in SPI_MasterSetBaud.

## [2.0.3]

- Improvements
  - Added "SPI_FIFO_DEPTH(base)" with more definition.

## [2.0.2]

- Improvements
  - Unified the component full name to FLEXCOMM SPI(DMA/FREERTOS) driver.

## [2.0.1]

- Changed the data buffer from uint32_t to uint8_t which matches
  the real applications for SPI DMA driver.
- Added dummy data setup API to allow users to configure the dummy data to be transferred.
- Added new APIs for half-duplex transfer function. Users can not only send and receive data by one API in
  polling/interrupt/DMA way, but choose either to transmit first or to receive first. Besides, the PCS pin can be
  configured as assert status in transmission (between transmit and receive) by setting the isPcsAssertInTransfer
  to true.

## [2.0.0]

- Initial version.
