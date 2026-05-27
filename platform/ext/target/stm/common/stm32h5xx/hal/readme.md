<!--
SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
Copyright (c) 2026 STMicroelectronics. All rights reserved.

SPDX-License-Identifier: BSD-3-Clause
-->


Content from https://github.com/STMicroelectronics/stm32h5xx-hal-driver (HAL version - Tag V1.6.0)

---

# Patch-1

**Files:**

- `Inc/stm32h5xx_hal_flash.h`
- `Src/stm32h5xx_hal_flash.c`

**Object:**
Add HAL functions to specifically lock/unlock the secure or non-secure flash control registers:

- `HAL_FLASH_Unlock_NS()` and `HAL_FLASH_Lock_NS()`
- `HAL_FLASH_Unlock_SEC()` and `HAL_FLASH_Lock_SEC()`

Existing `HAL_FLASH_Unlock()` and `HAL_FLASH_Lock()` behavior is preserved, acting on both non-secure and, if TrustZone is supported, secure internal flash control registers.

