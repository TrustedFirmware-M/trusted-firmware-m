#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

add_library(tfm_sprt STATIC)
target_include_directories(tfm_sprt
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_SOURCE_DIR}/secure_fw/include
)

target_sources(tfm_sprt
    PUBLIC
        $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
    PRIVATE
        assert.c
        crt_memcmp.c
        crt_memmove.c
        crt_strnlen.c
        $<$<C_COMPILER_ID:Clang>:crt_start.c>
        crt_exit.c
        $<$<C_COMPILER_ID:Clang>:crt_strlen.c>
        crt_vprintf.c
        service_api.c
        ${CMAKE_SOURCE_DIR}/secure_fw/shared/crt_memcpy.c
        ${CMAKE_SOURCE_DIR}/secure_fw/shared/crt_memset.c
        $<$<BOOL:${CONFIG_TFM_PARTITION_META}>:./sprt_partition_metadata_indicator.c>
        $<$<BOOL:${CONFIG_TFM_SPM_BACKEND_IPC}>:./sfn_common_thread.c>
        $<$<BOOL:${CONFIG_TFM_SPM_BACKEND_IPC}>:./psa_api_ipc.c>
        $<$<BOOL:${TFM_SP_LOG_RAW_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/tfm_hal_sp_logdev_periph.c>
)

target_link_libraries(tfm_sprt
    PUBLIC
        psa_interface
        tfm_spm_defs
        tfm_config
        platform_s
        tfm_log_unpriv_headers
    PRIVATE
        tfm_spm
        psa_crypto_config
        tfm_vprintf
        tfm_log_unpriv
)

target_compile_definitions(tfm_config
    INTERFACE
        LOG_LEVEL_UNPRIV=${TFM_PARTITION_LOG_LEVEL}
        $<$<BOOL:${TFM_SP_LOG_RAW_ENABLED}>:TFM_SP_LOG_RAW_ENABLED>
)

target_include_directories(tfm_sprt
    INTERFACE
        $<BUILD_INTERFACE:$<$<BOOL:${CONFIG_TFM_PARTITION_META}>:${CMAKE_CURRENT_SOURCE_DIR}/include>>
)
