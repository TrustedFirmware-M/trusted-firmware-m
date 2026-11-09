# FLEXSPI DMA Driver

## [2.2.3]

- Bug Fixes
  - Fixed CERT INT31-C violations in FLEXSPI_WriteDataDMA and FLEXSPI_ReadDataDMA: moved uint8_t
    cast outside multiplication and added masks before narrowing conversions.
  - Fixed CERT INT30-C violations: added assert guards before power-of-2 checks to prevent
    unsigned wrap on handle->count - 1U.

## [2.2.2]

- Bug Fixes
  - Fixed CERT INT31-C violations: added masks before uint8_t casts and explicit uint32_t casts for division results.

## [2.2.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.1, 10.3, 10.4, 10.8.

## [2.2.0]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.1, 10.3.
- New Features
  - Updated name of FLEXSPI_TransferGetTransferCountDMA API.

## [2.1.1]

- New Features
  - Updated driver to support feature FSL_FEATURE_FLEXSPI_DMA_MULTIPLE_DES.

## [2.1.0]

- Bug Fixes
  - Updated enumaration flexspi_dma_transfer_nsize_t and remove the unsupported items.
- New Features
  - Updated driver for deprecating the multiple linked descriptors inside FLEXSPI_TransferDMA, only up to one linked descriptor is needed according to hardware update.

## [2.0.0]

- Initial version.
