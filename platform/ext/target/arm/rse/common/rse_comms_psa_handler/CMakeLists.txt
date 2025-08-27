#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

target_sources(platform_s
    PRIVATE
        rse_comms_psa_handler.c
        rse_comms_psa_queue.c
        rse_comms_psa_protocol.c
        rse_comms_psa_protocol_embed.c
        rse_comms_psa_protocol_pointer_access.c
)

target_compile_definitions(platform_s
    PRIVATE
        RSE_COMMS_PSA_HANDLER_MAX_CONCURRENT_REQ=2
        RSE_COMMS_PROTOCOL_EMBED_ENABLED
        RSE_COMMS_PROTOCOL_POINTER_ACCESS_ENABLED
        $<$<BOOL:${CONFIG_TFM_HALT_ON_CORE_PANIC}>:CONFIG_TFM_HALT_ON_CORE_PANIC>
)
