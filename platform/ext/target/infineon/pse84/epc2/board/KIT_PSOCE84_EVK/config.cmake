#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Individual board config options for EPC2

set(IFX_PDL_PART_NUMBER           "PSE846GPS2DBZC4A"    CACHE STRING    "Part number, see PDL for more details")
set(IFX_BOARD_NAME                "TARGET_APP_KIT_PSE84_EVAL_EPC2" CACHE STRING    "Board name, used to customize configuration")

set(IFX_BSP_LIB_PATH              "DOWNLOAD"            CACHE PATH      "Path to target BSP library (or DOWNLOAD to fetch automatically)")
set(IFX_BSP_LIB_GIT_REMOTE        "https://github.com/Infineon/TARGET_KIT_PSE84_EVAL_EPC2.git" CACHE STRING "Target BSP library repo URL")
set(IFX_BSP_LIB_VERSION           "release-v1.1.0"      CACHE STRING    "The version of target BSP library to use")
set(IFX_BSP_LIB_PATCH_DIR         "${IFX_FAMILY_SOURCE_DIR}/libs/ifx_bsp/patch" CACHE STRING "Path to ifx-bsp patches")

set(IFX_DEVICE_DB_LIB_PATH        "DOWNLOAD"         CACHE PATH      "Path to target Device DB library (or DOWNLOAD to fetch automatically)")
set(IFX_DEVICE_DB_LIB_GIT_REMOTE  "https://github.com/Infineon/device-db.git" CACHE STRING "Target Device DB library repo URL")
set(IFX_DEVICE_DB_LIB_VERSION     "release-v4.31.0"      CACHE STRING    "The version of target Device DB library to use")

# PS_TEST_NV_COUNTERS=ON disables real NV counters, and instead replaces them
# with mock RAM NV counters implementation. This allows to perform rollback
# tests on PS. But these rollback tests does not test any platform specific
# functionality thus PS_TEST_NV_COUNTERS is set to OFF to ensure that real NV
# counters are used when PS tests are run. This way tests will test flow used
# by customers.
set(PS_TEST_NV_COUNTERS           OFF          CACHE BOOL      "Use the test NV counters to test Protected Storage rollback scenarios")

set(IFX_BSP_DESIGN_FILE_PATH        "${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/design.modus"  CACHE FILEPATH "Path to design.modus file to use for BSP code generation by Device Configurator.")
set(IFX_BSP_QSPI_DESIGN_FILE_PATH   "${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/design.cyqspi" CACHE FILEPATH "Path to design.cyqspi file to use for BSP code generation by QSPI Configurator.")
set(IFX_BSP_QSPI_FLASH_LOADERS_DIR_PATH "${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/FlashLoaders" CACHE FILEPATH "Path to FlashLoaders directory for BSP.")
