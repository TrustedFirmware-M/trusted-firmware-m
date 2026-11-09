# I2C

## [2.3.4]

- Bug Fixes
  - Added internal reset of master function after arbitration lost in I2C_MasterTransferHandleIRQ(), otherwise the STAT[MSTARBLOSS] is not set in next transfer.

## [2.3.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.1.
  - Fixed issue that if master only sends address without data during I2C interrupt transfer, address nack cannot
    be detected.

## [2.3.2]

- Improvement
  - Enable or disable timeout option according to enableTimeout.
- Bug Fixes
  - Fixed timeout value calculation error.
  - Fixed bug that the interrupt transfer cannot recover from the timeout error.

## [2.3.1]

- Improvement
  - Before master transfer with transactional APIs, enable master function while disable slave function and
    vise versa for slave transfer to avoid the one affecting the other.
- Bug Fixes
  - Fixed bug in I2C_SlaveEnable that the slave enable/disable should not affect the other register bits.

## [2.3.0]

- Improvement
  - Added new return codes kStatus_I2C_EventTimeout and kStatus_I2C_SclLowTimeout, and added the check for event
    timeout and SCL timeout in I2C master transfer.
  - Fixed bug in slave transfer that the address match event should be invoked before not after slave
    transmit/receive event.

## [2.2.0]

- New Features
  - Added enumeration _i2c_status_flags to include all previous master and slave status flags, and added missing
    status flags.
  - Modified I2C_GetStatusFlags to get all I2C flags.
  - Added API I2C_ClearStatusFlags to clear all clearable flags not just master flags.
  - Modified master transactional APIs to enable bus event timeout interrupt during transfer, to avoid glitch on bus
    causing transfer hangs indefinitely.
- Bug Fixes
  - Fixed bug that status flags and interrupt enable masks share the same enumerations by adding enumeration
    _i2c_interrupt_enable for all master and slave interrupt sources.

## [2.1.0]

- Bug Fixes
  - Fixed bug that during master transfer, when master is nacked during slave probing or sending subaddress, the
    return status should be kStatus_I2C_Addr_Nak rather than kStatus_I2C_Nak.
- Bug Fixes
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.4, 13.5.
- New Features
  - Added macro I2C_MASTER_TRANSMIT_IGNORE_LAST_NACK, so that user can configure whether to ignore the last byte
    being nacked by slave during master transfer.

## [2.0.8]

- Bug Fixes
  - Fixed I2C_MasterSetBaudRate issue that MSTSCLLOW and MSTSCLHIGH are incorrect when MSTTIME is odd.

## [2.0.7]

- Bug Fixes
  - Two dividers, CLKDIV and MSTTIME are used to configure baudrate. According to reference manual,
    in order to generate 400kHz baudrate, the clock frequency after CLKDIV must be less than 2mHz.
    Fixed the bug that, the clock frequency after CLKDIV may be larger than 2mHz using the previous
    calculation method.
  - Fixed MISRA 10.1 issues.
  - Fixed wrong baudrate calculation when feature FSL_FEATURE_I2C_PREPCLKFRG_8MHZ is enabled.

## [2.0.6]

- New Features
  - Added master timeout self-recovery support for feature FSL_FEATURE_I2C_TIMEOUT_RECOVERY.
- Bug Fixes
  - Eliminated IAR Pa082 warning.
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 10.7, 10.8, 11.3, 11.6, 11.8, 11.9, 13.5.

## [2.0.5]

- Bug Fixes
  - Fixed wrong assignment for datasize in I2C_InitTransferStateMachineDMA.
  - Fixed wrong working flow in I2C_RunTransferStateMachineDMA to ensure master can work in no start flag and no
    stop flag mode.
  - Fixed wrong working flow in I2C_RunTransferStateMachine and added kReceiveDataBeginState
    in _i2c_transfer_states to ensure master can work in no start flag and no stop flag mode.
  - Fixed wrong handle state in I2C_MasterTransferDMAHandleIRQ. After all the data has been transfered or nak is
    returned, handle state should be changed to idle.
- Improvements
  - Rounded up the calculated divider value in I2C_MasterSetBaudRate.

## [2.0.4]

- Improvements
  - Updated the I2C_WATI_TIMEOUT macro to unified name I2C_RETRY_TIMES
  - Updated the "I2C_MasterSetBaudRate" API to support baudrate configuration for feature QN9090.
- Bug Fixes
  - Fixed build warnning caused by uninitialized variable.
  - Fixed COVERITY issue of unchecked return value in I2C_RTOS_Transfer.

## [2.0.3]

- Improvements
  - Unified the component full name to FLEXCOMM I2C(DMA/FREERTOS) driver.

## [2.0.2]

- Improvements
  - In slave IRQ:
    1. Changed slave receive process to first set the I2C_SLVCTL_SLVCONTINUE_MASK to acknowledge the received data,
       then do data receive.
    2. Improved slave transmit process to set the I2C_SLVCTL_SLVCONTINUE_MASK immediately after writing the data.

## [2.0.1]

- Improvements
  - Added I2C_WATI_TIMEOUT macro to allow users to specify the timeout times for waiting flags in functional API
    and blocking transfer API.

## [2.0.0]

- Initial version.
