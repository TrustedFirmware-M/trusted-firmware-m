# LPUART

## [2.3.4]

- Bug Fixes
  - Fixed coverity issues.

## [2.3.3]

- Bug Fixes
  - Fixed coverity issues.

## [2.3.2]

- Bug Fix
  - Fixed the bug that LPUART_TransferEnable16Bit controled by wrong feature macro.

## [2.3.1]

- Bug Fix
  - Fixed MISRA C-2012 violations.

## [2.3.0]

- Improvements
  - Added support of DATA register for 9bit or 10bit data transmit in write and read API.
    Such as: LPUART_WriteBlocking16bit, LPUART_ReadBlocking16bit, LPUART_TransferEnable16Bit
    LPUART_WriteNonBlocking16bit, LPUART_ReadNonBlocking16bit.

## [2.2.4]

- Bug Fix
  - Fixed the bug that baud rate calculation overflow when srcClock_Hz is 528MHz.

## [2.2.3]

- Improvements
  - Added atomic in LPUART_EnableInterrupts and LPUART_DisableInterrupts.

## [2.2.2]

- Improvements
  - Added comment on txExtendedTimeoutValue of lpuart_timeout_config_t.

## [2.2.1]

- Bug Fix
  - Fixed the bug that the OSR calculation error when lupart init and lpuart set baud rate.

## [2.2.0]

- Improvements
  - Rename some enumeration variables to be consistent with lpuart driver.

## [2.1.1]

- Improvements
  - Supported to initialize the flexcomm layer outside the peripheral driver initialization function.

## [2.1.0]

- New Features
  - Supported new platform that does not have the feature of MODEM Control,MODEM Status,Receiver Extended Idle,Transmitter Extended Idle,
    Half Duplex Control,Timeout Control,Timeout Status and Timeout N.

## [2.0.0]

- Initial version.
