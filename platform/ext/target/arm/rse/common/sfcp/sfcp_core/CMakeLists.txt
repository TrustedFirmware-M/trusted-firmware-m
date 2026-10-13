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
        sfcp_interrupt_hal.c
        sfcp_runtime_hal.c
        sfcp_atu.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/prix64.c
        sfcp_link_hal.c
)

target_compile_definitions(platform_s
    PRIVATE
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
            sfcp_interrupt_hal.c
            sfcp_link_hal.c
            $<$<BOOL:${SFCP_ENABLE_ENCRYPTION}>:${CMAKE_CURRENT_SOURCE_DIR}/sfcp_encryption_hal.c>
    )

    target_include_directories(platform_bl1_2
        PUBLIC
            .
    )
endif()

# Function scopes keep runtime and boot feature overrides independent.
function(rse_add_runtime_sfcp)
    set(SFCP_ENABLE_ENCRYPTION OFF)
    set(SFCP_ENABLE_HANDLERS ON)
    set(SFCP_ENABLE_BUFFERS ON)
    set(SFCP_ENABLE_PSA_CLIENT ON)
    set(SFCP_ENABLE_PSA_SERVER ON)
    set(SFCP_ENABLE_PSA_CALL OFF)
    rse_add_sfcp_library(platform_s)
    target_compile_options(sfcp_platform_s PRIVATE ${COMPILER_CP_FLAG})
endfunction()

function(rse_add_boot_sfcp)
    set(SFCP_ENABLE_HANDLERS OFF)
    set(SFCP_ENABLE_BUFFERS OFF)
    set(SFCP_SUPPORT_LEGACY_MSG_PROTOCOL OFF)
    set(SFCP_ENABLE_PSA_CLIENT OFF)
    set(SFCP_ENABLE_PSA_SERVER OFF)
    set(SFCP_ENABLE_PSA_CALL OFF)
    rse_add_sfcp_library(platform_bl1_1)
    target_compile_options(sfcp_platform_bl1_1 PRIVATE ${BL1_COMPILER_CP_FLAG})

    # BL1_2 calls SFCP through the BL1_1 shared symbols. Share the public
    # configuration and headers without linking another copy of the archive.
    target_include_directories(platform_bl1_2 PUBLIC
        $<TARGET_PROPERTY:sfcp_platform_bl1_1,INTERFACE_INCLUDE_DIRECTORIES>)
    target_compile_definitions(platform_bl1_2 PUBLIC
        $<TARGET_PROPERTY:sfcp_platform_bl1_1,INTERFACE_COMPILE_DEFINITIONS>)
endfunction()

rse_add_runtime_sfcp()
if(RSE_AMOUNT GREATER 1)
    rse_add_boot_sfcp()
endif()
