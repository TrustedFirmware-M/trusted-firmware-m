#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

########################## STM32 #######################################
# Before Soc config (could be used by soc config)
# Basename of bl2, tfm secure and tfm non secure device tree source
SET(STM32_DTS_BOARD_BASENAME           "stm32mp257f-dk")
set(STM32_BOOT_DEV                     "sdmmc1"                             CACHE STRING    "Set boot device [ospi, sdmmc1, sdmmc2]")

# Set common soc config
if (EXISTS ${STM_SOC_DIR}/config.cmake)
    include(${STM_SOC_DIR}/config.cmake)
endif()

# After soc config
set(DTS_BOARDS_DIR                     ${DT_DTS_DIR}/boards/stm32mp257f_dk  CACHE STRING    "Define board device tree source path" FORCE)
set(STM32_BOARD_MODEL                  "stm32mp257f disco"                  CACHE STRING    "Define board model name" FORCE)
set(STM32_DDR_PHY_FILE                 "lpddr4_pmu_train.bin"               CACHE STRING    "Set ddr phy binary name need for your board" FORCE)
set(TFM_PARTITION_PROTECTED_STORAGE    OFF                                  CACHE BOOL      "Enable Protected Storage partition" FORCE)

