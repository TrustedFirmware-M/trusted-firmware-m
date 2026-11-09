<!--
SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
Copyright 2026 NXP

SPDX-License-Identifier: BSD-3-Clause
-->

# NXP Platform IOCTL Services for TF-M

## Overview

The NXP Platform IOCTL Services provide a secure gateway that allows Non-Secure (NS) world
applications to perform flash operations and ROM API calls through the TF-M Platform partition.
All operations are dispatched via `tfm_platform_ioctl()` and execute entirely in the Secure (S)
world, ensuring that NS code never has direct write access to flash.

Currently supported targets: **FRDM-MCXA577**.

---

## Feature Description

### NS Storage (NXP_NS_STORAGE)

When `NXP_NS_STORAGE` is defined, a dedicated region of internal flash is reserved for
Non-Secure application use. The S-world exposes a set of IOCTL operations so the NS world
can erase, program, verify, and read that region without requiring direct flash access.

Available IOCTL operations (defined in `tfm_ioctl_api.h`):

| Request ID                                       | Operation                             |
| ------------------------------------------------ | ------------------------------------- |
| `TFM_PLATFORM_IOCTL_FLASH_ERASE_SECTOR`        | Erase one or more 8 KB sectors        |
| `TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PHRASE`      | Program data (16-byte phrase aligned) |
| `TFM_PLATFORM_IOCTL_FLASH_PROGRAM_PAGE`        | Program data (128-byte page aligned)  |
| `TFM_PLATFORM_IOCTL_FLASH_VERIFY_PROGRAM`      | Verify programmed data                |
| `TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PHRASE` | Verify 16-byte phrases are erased     |
| `TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_PAGE`   | Verify 128-byte pages are erased      |
| `TFM_PLATFORM_IOCTL_FLASH_VERIFY_ERASE_SECTOR` | Verify 8 KB sectors are erased        |
| `TFM_PLATFORM_IOCTL_FLASH_GET_PROPERTY`        | Read a flash property value           |
| `TFM_PLATFORM_IOCTL_FLASH_READ`                | Read flash bytes into NS buffer       |

---

## How to Enable

### 1. Kconfig (prj.conf)

Enable the Kconfig options for the side(s) you need:

**Secure side only** (S-world flash HAL, defines `-DNXP_NS_STORAGE`):

```
CONFIG_MCUX_COMPONENT_middleware.tfm.s.romapi=y
```

**Non-Secure side** (NS-world API wrappers, defines `-DNXP_NS_STORAGE` and `-DFLASH_PROXY_HAL_<TARGET>`):

```
CONFIG_MCUX_COMPONENT_middleware.tfm.ns.romapi=y
```

Both options are found in the **Platform IOCTL Services** menu inside the TF-M Kconfig menu
tree. Each option automatically selects `driver.romapi` so the ROM API driver is pulled in.

### 2. What the options enable

| Kconfig option               | Preprocessor macros                                 | Effect                                                                               |
| ---------------------------- | --------------------------------------------------- | ------------------------------------------------------------------------------------ |
| `middleware.tfm.s.romapi`  | `-DNXP_NS_STORAGE`                                | Compiles`tfm_flash_ioctl_hal.c` into the S image; enables the flash storage region |
| `middleware.tfm.ns.romapi` | `-DNXP_NS_STORAGE` `-DFLASH_PROXY_HAL_<TARGET>` | Compiles`tfm_ioctl_ns_api.c` and the proxy headers into the NS image               |

The `FLASH_PROXY_HAL_<TARGET>` macro is defined automatically by the board's `mcux.cmake` when
`middleware.tfm.ns.romapi` is enabled.  The macro drives `fsl_flash_tfm_ns.h` and `fsl_romapi_tfm_ns.h` to pull in the
correct target-specific NS proxy header:

| Macro                     | Target family            | Proxy header                       |
| ------------------------- | ------------------------ | ---------------------------------- |
| `ROMAPI_PROXY_HAL_MCXA` | MCXA (e.g. FRDM-MCXA577) | `fsl_*_ns_proxy_mcxl_mcxa.h` |

`*` is a placeholder for the specific module name (e.g., `flash`, `romapi`)

---

## Security Notes

- The S-world HAL validates all NS pointers using CMSE checks before accessing them.
- The NS world has no direct write path to flash; all mutations go through the S-world
  `tfm_platform_ioctl()` gate.
- The `NXP_NS_STORAGE` region boundaries are enforced on the S side; requests outside the
  designated region are rejected.
