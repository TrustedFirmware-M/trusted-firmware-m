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
        $<$<BOOL:${RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL}>:${CMAKE_CURRENT_SOURCE_DIR}/../rse_comms_psa_handler>
)

target_sources(platform_s
    PRIVATE
        rse_comms_runtime_hal.c
        rse_comms_atu.c
        rse_comms_link_hal.c
        rse_comms.c
        rse_comms_helpers.c
        $<$<BOOL:${RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms_legacy_msg.c>
        # Encryption not currently supported in runtime
        rse_comms_encryption_stub.c
)

target_compile_definitions(platform_s
    PRIVATE
        RSE_COMMS_MAX_CONCURRENT_REQ=2
        $<$<BOOL:${RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL}>:RSE_COMMS_SUPPORT_LEGACY_MSG_PROTOCOL>
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
            rse_comms_link_hal.c
            rse_comms.c
            rse_comms_helpers.c
            $<$<BOOL:${RSE_COMMS_ENABLE_ENCRYPTION}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms_encryption_bl.c>
            $<$<BOOL:${RSE_COMMS_ENABLE_ENCRYPTION}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms_trusted_subnets.c>
            $<$<BOOL:${RSE_COMMS_ENABLE_ENCRYPTION}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms_encryption_handshake.c>
            $<$<NOT:$<BOOL:${RSE_COMMS_ENABLE_ENCRYPTION}>>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms_encryption_stub.c>
    )

    target_include_directories(platform_bl1_2
        PUBLIC
            .
    )
endif()
