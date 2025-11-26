#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

target_sources(platform_s
    PRIVATE
        sfcp_psa_handler/sfcp_psa_handler.c
        sfcp_psa_handler/sfcp_psa_queue.c
        sfcp_psa_protocol/sfcp_psa_protocol.c
        sfcp_psa_protocol/sfcp_psa_protocol_embed.c
        sfcp_psa_protocol/sfcp_psa_protocol_pointer_access.c
)

target_compile_definitions(platform_s
    PRIVATE
        SFCP_PSA_HANDLER_MAX_CONCURRENT_REQ=2
        SFCP_PROTOCOL_EMBED_ENABLED
        SFCP_PROTOCOL_POINTER_ACCESS_ENABLED
        $<$<BOOL:${CONFIG_TFM_HALT_ON_CORE_PANIC}>:CONFIG_TFM_HALT_ON_CORE_PANIC>
)

target_include_directories(platform_s
    PRIVATE
        sfcp_psa_protocol
)
