#-------------------------------------------------------------------------------
# Portions Copyright (C) 2024 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

################################################################################

# Fetch hal_adi repository
fetch_remote_library(
    LIB_NAME                hal_adi
    LIB_SOURCE_PATH_VAR     HAL_ADI_PATH
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://github.com/analogdevicesinc/hal_adi
        GIT_TAG             ${HAL_ADI_VERSION}
        GIT_PROGRESS        TRUE
)

set(TARGET_LC "max32657")
string(TOUPPER ${TARGET_LC} TARGET_UC)

set(HAL_ADI_LIBRARY_DIR     ${HAL_ADI_PATH}/MAX/Libraries)

set(HAL_ADI_CMSIS_DIR       ${HAL_ADI_LIBRARY_DIR}/CMSIS/Device/Maxim/${TARGET_UC})
set(HAL_ADI_CMSIS_INC_DIR   ${HAL_ADI_CMSIS_DIR}/Include)
set(HAL_ADI_CMSIS_SRC_DIR   ${HAL_ADI_CMSIS_DIR}/Source)

set(HAL_ADI_PERIPH_DIR      ${HAL_ADI_LIBRARY_DIR}/PeriphDrivers)
set(HAL_ADI_PERIPH_INC_DIR  ${HAL_ADI_PERIPH_DIR}/Include/${TARGET_UC})
set(HAL_ADI_PERIPH_SRC_DIR  ${HAL_ADI_PERIPH_DIR}/Source)
