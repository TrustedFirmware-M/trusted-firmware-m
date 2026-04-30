#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

add_library(tfm_gpt STATIC EXCLUDE_FROM_ALL)

set(GPT_LOG_LEVEL LOG_LEVEL_INFO CACHE STRING "Set default log level for the GPT library")

if(NOT DEFINED TFM_GPT_BLOCK_SIZE)
    message(FATAL_ERROR "TFM_GPT_BLOCK_SIZE must be defined to use GPT library")
endif()

target_sources(tfm_gpt
    PRIVATE
        src/gpt.c
        src/gpt_defs.c
        src/io/gpt_io.c
        src/io/gpt_io_read.c
        src/io/gpt_io_read_rw.c
        src/io/gpt_io_write.c
)

target_include_directories(tfm_gpt
    PUBLIC
        inc
        $<INSTALL_INTERFACE:inc>
    PRIVATE
        $<BUILD_INTERFACE:${CMSIS_PATH}/CMSIS/Core/Include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_compile_definitions(tfm_gpt
    PUBLIC
        TFM_GPT_BLOCK_SIZE=${TFM_GPT_BLOCK_SIZE}
    PRIVATE
        LOG_LEVEL=${GPT_LOG_LEVEL}
)

target_link_libraries(tfm_gpt
    PUBLIC
        tfm_log_headers
        tfm_vprintf_headers
    PRIVATE
        tfm_efi_guid
        tfm_efi_soft_crc
        cmsis
)
