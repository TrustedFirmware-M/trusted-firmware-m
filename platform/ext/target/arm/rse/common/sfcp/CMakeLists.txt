#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

target_include_directories(platform_s
    PUBLIC
        .
    PRIVATE
        # Required for legacy message format
        $<$<BOOL:${SFCP_SUPPORT_LEGACY_MSG_PROTOCOL}>:${CMAKE_CURRENT_SOURCE_DIR}/../sfcp_psa_handler>
)

target_sources(platform_s
    PRIVATE
        sfcp_runtime_hal.c
        sfcp_interrupt_handler.c
        sfcp_atu.c
        sfcp_link_hal.c
        sfcp.c
        sfcp_random.c
        sfcp_helpers.c
        $<$<BOOL:${SFCP_SUPPORT_LEGACY_MSG_PROTOCOL}>:${CMAKE_CURRENT_SOURCE_DIR}/sfcp_legacy_msg.c>
        # Encryption not currently supported in runtime
        sfcp_encryption_stub.c
)

target_compile_definitions(platform_s
    PRIVATE
        SFCP_MAX_CONCURRENT_REQ=2
        $<$<BOOL:${SFCP_SUPPORT_LEGACY_MSG_PROTOCOL}>:SFCP_SUPPORT_LEGACY_MSG_PROTOCOL>
        $<$<BOOL:${CONFIG_TFM_HALT_ON_CORE_PANIC}>:CONFIG_TFM_HALT_ON_CORE_PANIC>
)

# For spm_log_msgval
target_link_libraries(platform_s
    PRIVATE
        tfm_spm
        tfm_sprt
)

# Currently only used by RSE handshake
if (RSE_AMOUNT GREATER 1)
    target_include_directories(platform_bl1_1
        PUBLIC
            .
    )

    target_sources(platform_bl1_1
        PRIVATE
            sfcp_link_hal.c
            sfcp.c
            sfcp_random.c
            sfcp_helpers.c
            $<$<BOOL:${SFCP_ENABLE_ENCRYPTION}>:${CMAKE_CURRENT_SOURCE_DIR}/sfcp_encryption.c>
            $<$<BOOL:${SFCP_ENABLE_ENCRYPTION}>:${CMAKE_CURRENT_SOURCE_DIR}/sfcp_trusted_subnets.c>
            $<$<BOOL:${SFCP_ENABLE_ENCRYPTION}>:${CMAKE_CURRENT_SOURCE_DIR}/sfcp_encryption_handshake.c>
            $<$<NOT:$<BOOL:${SFCP_ENABLE_ENCRYPTION}>>:${CMAKE_CURRENT_SOURCE_DIR}/sfcp_encryption_stub.c>
    )

    target_include_directories(platform_bl1_2
        PUBLIC
            .
    )
endif()
