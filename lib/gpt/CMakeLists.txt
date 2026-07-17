#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

# Full GPT library, with read and write functionality
add_library(tfm_gpt STATIC EXCLUDE_FROM_ALL)

include(./config.cmake)

if(NOT DEFINED TFM_GPT_BLOCK_SIZE OR NOT DEFINED GPT_LOG_LEVEL)
    message(FATAL_ERROR "TFM_GPT_BLOCK_SIZE and GPT_LOG_LEVEL must be defined to use GPT library")
endif()

#-------------------------------------------------------------------------------
# Full GPT library
#-------------------------------------------------------------------------------

target_sources(tfm_gpt
    PRIVATE
        src/gpt_defs.c
        src/gpt_modify.c
        src/gpt_parse.c
        src/io/gpt_io.c
        src/io/gpt_io_read.c
        src/io/gpt_io_write.c
)

target_include_directories(tfm_gpt
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:inc>
    PRIVATE
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
        psa_interface
        tfm_efi_guid
        tfm_log_headers
    PRIVATE
        cmsis
        tfm_efi_soft_crc
)
