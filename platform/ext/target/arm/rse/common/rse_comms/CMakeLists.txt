#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

target_include_directories(platform_s
    PUBLIC
        .
)

target_sources(platform_s
    PRIVATE
        rse_comms_runtime_inter_core_comm.c
        rse_comms_runtime_hal.c
        rse_comms_queue.c
        rse_comms_protocol.c
        rse_comms_protocol_embed.c
        rse_comms_protocol_pointer_access.c
        rse_comms_atu.c
        rse_comms_link_hal.c
        rse_comms.c
        rse_comms_helpers.c
)

target_compile_definitions(platform_s
    PRIVATE
        RSE_COMMS_MAX_CONCURRENT_REQ=2
        RSE_COMMS_PROTOCOL_EMBED_ENABLED
        RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
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
    )

    target_include_directories(platform_bl1_2
        PUBLIC
            .
    )
endif()
