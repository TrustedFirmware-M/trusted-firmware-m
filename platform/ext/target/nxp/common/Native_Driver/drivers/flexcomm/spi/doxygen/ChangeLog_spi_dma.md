# SPI_DMA

## [2.3.0]

- Improvements
  - Added support for `kSPI_FrameAssertEachFrame` so DMA transfers can deassert PCS after each frame.

## [2.2.3]

- Bug Fixes
  - Fixed the bug `SPI_MasterTransferGetCountDMA` and `SPI_SlaveTransferGetCountDMA`
    returns wrong count.

## [2.2.2]

- Bug Fixes
  - Fixed the bug half duplex mode can't be used if data size is larger than 1024 bytes.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA 2012 11.6 issue..

## [2.2.0]

- Improvements
  - Supported dataSize larger than 1024 data transmit.
