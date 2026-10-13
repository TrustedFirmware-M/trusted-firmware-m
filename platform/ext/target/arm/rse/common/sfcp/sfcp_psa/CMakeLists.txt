# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# SPDX-License-Identifier: BSD-3-Clause

target_sources(platform_s PRIVATE sfcp_psa_handler/sfcp_psa_handler.c
    sfcp_psa_handler/sfcp_psa_memory_hal.c
    sfcp_psa_handler/sfcp_psa_queue.c)
target_compile_definitions(platform_s PRIVATE
    SFCP_PSA_HANDLER_MAX_CONCURRENT_REQ=2
    $<$<BOOL:${CONFIG_TFM_HALT_ON_CORE_PANIC}>:CONFIG_TFM_HALT_ON_CORE_PANIC>)
target_include_directories(platform_s PRIVATE sfcp_psa_handler)
