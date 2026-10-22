#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_policy(SET CMP0076 NEW)

include(${STM_FAMILY_DIR}/ns/CMakeLists.txt)

target_sources(dt_tfm_ns_libs
    PRIVATE
        ${STM_FAMILY_DIR}/native_driver/src/clk/clk-stm32mp25.c
)

target_sources(tfm_ns
    PRIVATE
        ${STM_SOC_DIR}/src/startup_stm32mp2_ns.c
)
