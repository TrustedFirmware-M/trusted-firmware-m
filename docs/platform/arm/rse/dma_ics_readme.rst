DMA ICS
#######

ICS Assembly
************

At build time, the following Python script generates the ICS binaries:

```
<TFM_PATH>/platform/ext/target/arm/rse/common/bl1/scripts/create_bl1_1_dma_bin.py
```

Inputs
======

- Config File

  `dma_config.yaml`
  Describes the included ICS commands, memory layout, base addresses, and trigger IDs.
  For a custom ICS, the ``RSE_DMA_ICS_CONFIG_PATH`` cmake variable should be set to the path
  of the corresponding custom `dma_config.yaml` file. If this variable is not overridden with
  a custom path then the common one will be used at :
  `<TFM_PATH>/platform/ext/target/arm/rse/common/bl1/scripts/dma_config.yaml`


- Common Definitions

  `dma_common.yaml`
  Location:
  `<TFM_PATH>/platform/ext/target/arm/rse/common/bl1/scripts/`
  Defines register offsets and bitfield masks.

- ICS Commands

  Each DMA command is specified in the `dma_config.yaml` file. For readability,
  it is recommended to create a new .yaml file for each command which can be
  included in the `dma_config.yaml` file.

  Eg. For the common ICS, commands exist as seperate yaml files
  in the following directory:

  `<TFM_PATH>/platform/ext/target/arm/rse/common/bl1/scripts/include/`

Outputs
=======

Generated binaries are located in:

```
<TFM_PATH>/cmake_build/<plat_dir>/bin/
```

- `rom_dma_ics.bin`
- `rom_dma_ics.hex`
- `otp_dma_ics.bin`
- `otp_dma_ics.hex`
- `rom_dma_ics.csv`
- `rom_dma_ics.csv`

Understanding the `include/` YAML Files
=======================================

Each YAML file defines a **DMA descriptor**, which specifies the channel configuration registers
to update as part of that descriptor and with what values. For example, there is a ``LINKADDR``
register which when configured, enables the DMA to fetch a subsequent desciptor from this address,
allowing a sequence of commands to be executed.

Specific register details can be found at:
https://developer.arm.com/documentation/102482/0000/Programmers-model/Register-summary/DMACH-n--summary

Integration
***********

- `rom_dma_ics.bin` should be concatenated with `rom.bin` at build time at the predefined ROM offset `0x1F000`.
- `otp_dma_ics.bin` should be bundled into cm provisioning blobs eg. `cm_provisioning_blob.bin` for OTP provisioning.

Debugging
*********

Each DMA descriptor has a corresponding ``GPO`` value output which is transferred to the DCSU ``STATUS8``
register in HW. The progression of the DMA ICS can be monitored by reading the DCSU ``STATUS8`` register
via JTAG.

--------------

*SPDX-License-Identifier: BSD-3-Clause*

*SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors*
