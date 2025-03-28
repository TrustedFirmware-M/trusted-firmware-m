#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2021-2023 Cypress Semiconductor Corporation (an Infineon
# company) or an affiliate of Cypress Semiconductor Corporation. All rights
# reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

if(PSA_FRAMEWORK_HAS_MM_IOVEC)
    message(NOTICE "\n"
                   "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                   "  MM-IOVEC is enabled for memory and runtime optimizations for larger buffers,\n"
                   "  but reduces mitigation for common security vulnerabilities. Check FF-M v1.1\n"
                   "  https://developer.arm.com/documentation/aes0039/latest   for more details.\n"
                   "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n")
endif()

add_library(tfm_spm STATIC)
add_library(tfm_spm_defs INTERFACE)
add_library(tfm_boot_status INTERFACE)
add_library(tfm_arch INTERFACE)

add_dependencies(tfm_spm manifest_tool)

# Get current time as a timestamp
string(TIMESTAMP BUILD_TIMESTAMP "%a %d %b %Y %H:%M:%S" UTC)

# Generate TF-M version and timestamp strings
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/tfm_version.h.in
               ${CMAKE_BINARY_DIR}/generated/secure_fw/spm/include/tfm_version.h)

target_include_directories(tfm_spm
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/core
    PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/secure_fw/include
        ${CMAKE_SOURCE_DIR}/secure_fw/partitions/lib/runtime
        ${CMAKE_BINARY_DIR}/generated
        ${CMAKE_BINARY_DIR}/generated/secure_fw/spm/include
        ${CMAKE_BINARY_DIR}/generated/secure_fw/spm/core
)

target_sources(tfm_spm
    PRIVATE
        core/tfm_boot_data.c
        core/utilities.c
        core/arch/tfm_arch.c
        core/main.c
        core/spm_ipc.c
        core/rom_loader.c
        core/psa_api.c
        core/psa_call_api.c
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:core/mailbox_agent_api.c>
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:core/tfm_rpc.c>
        core/psa_version_api.c
        core/psa_read_write_skip_api.c
        $<$<BOOL:${PSA_FRAMEWORK_HAS_MM_IOVEC}>:core/psa_mmiovec_api.c>
        $<$<BOOL:${CONFIG_TFM_CONNECTION_BASED_SERVICE_API}>:core/psa_connection_api.c>
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:core/psa_irq_api.c>
        $<$<BOOL:${CONFIG_TFM_SPM_BACKEND_IPC}>:core/backend_ipc.c>
        $<$<BOOL:${CONFIG_TFM_SPM_BACKEND_SFN}>:core/backend_sfn.c>
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:core/interrupt.c>
        $<$<BOOL:${CONFIG_TFM_STACK_WATERMARKS}>:core/stack_watermark.c>
        core/tfm_svcalls.c
        core/tfm_pools.c
        $<$<BOOL:${CONFIG_TFM_SPM_BACKEND_IPC}>:core/thread.c>
        $<$<BOOL:${TFM_NS_MANAGE_NSID}>:ns_client_ext/tfm_ns_ctx.c>
        ns_client_ext/tfm_spm_ns_ctx.c
        $<$<OR:$<BOOL:${CONFIG_TFM_SPM_BACKEND_IPC}>,$<BOOL:${CONFIG_TFM_CONNECTION_BASED_SERVICE_API}>>:core/spm_connection_pool.c>
        $<$<NOT:$<OR:$<BOOL:${CONFIG_TFM_SPM_BACKEND_IPC}>,$<BOOL:${CONFIG_TFM_CONNECTION_BASED_SERVICE_API}>>>:core/spm_local_connection.c>
        #TODO add other arches
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8.1-m.main>:core/arch/tfm_arch_v8m_main.c>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8-m.base>:core/arch/tfm_arch_v8m_base.c>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8-m.main>:core/arch/tfm_arch_v8m_main.c>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv6-m>:core/arch/tfm_arch_v6m_v7m.c>
        $<$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv7-m>:core/arch/tfm_arch_v6m_v7m.c>
        ${CMAKE_SOURCE_DIR}/platform/ext/common/tfm_hal_nvic.c
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_BINARY_DIR}/generated/interface/src/ns_mailbox_client_id.c>
)

target_include_directories(tfm_spm_defs
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/core
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/boot>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/interface>
        ${CMAKE_CURRENT_SOURCE_DIR}/core/arch
)

target_link_libraries(tfm_spm
    PUBLIC
        tfm_arch
        tfm_spm_defs
    PRIVATE
        platform_s
        tfm_boot_status
        tfm_config
        tfm_partitions
        tfm_fih_headers
        tfm_sprt
        $<$<NOT:$<STREQUAL:${TFM_FIH_PROFILE},OFF>>:tfm_fih>
)

target_compile_definitions(tfm_spm
    PRIVATE
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:PLATFORM_SVC_HANDLERS>
        $<$<CONFIG:Debug>:TFM_CORE_DEBUG>
        $<$<AND:$<BOOL:${BL2}>,$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>>:BOOT_DATA_AVAILABLE>
        $<$<BOOL:${CONFIG_TFM_HALT_ON_CORE_PANIC}>:CONFIG_TFM_HALT_ON_CORE_PANIC>
        $<$<BOOL:${TFM_NS_MANAGE_NSID}>:TFM_NS_MANAGE_NSID>
        $<$<STREQUAL:${CONFIG_TFM_FLOAT_ABI},hard>:CONFIG_TFM_FLOAT_ABI=2>
        $<$<STREQUAL:${CONFIG_TFM_FLOAT_ABI},soft>:CONFIG_TFM_FLOAT_ABI=0>
        $<$<BOOL:${CONFIG_TFM_STACK_WATERMARKS}>:CONFIG_TFM_STACK_WATERMARKS>
        $<$<STREQUAL:${CONFIG_TFM_BRANCH_PROTECTION_FEAT},BRANCH_PROTECTION_NONE>:BRANCH_PROTECTION_CONTROL=0>
        $<$<STREQUAL:${CONFIG_TFM_BRANCH_PROTECTION_FEAT},BRANCH_PROTECTION_STANDARD>:BRANCH_PROTECTION_CONTROL=1>
        $<$<STREQUAL:${CONFIG_TFM_BRANCH_PROTECTION_FEAT},BRANCH_PROTECTION_PACRET>:BRANCH_PROTECTION_CONTROL=2>
        $<$<STREQUAL:${CONFIG_TFM_BRANCH_PROTECTION_FEAT},BRANCH_PROTECTION_PACRET_LEAF>:BRANCH_PROTECTION_CONTROL=2>
        $<$<STREQUAL:${CONFIG_TFM_BRANCH_PROTECTION_FEAT},BRANCH_PROTECTION_BTI>:BRANCH_PROTECTION_CONTROL=3>
)

target_compile_options(tfm_spm
    PUBLIC
        ${COMPILER_CP_FLAG}
)

# The veneers give warnings about not being properly declared so they get hidden
# to not overshadow _real_ warnings.
set_source_files_properties(tfm_secure_api.c
    PROPERTIES
        COMPILE_FLAGS
            $<$<C_COMPILER_ID:ARMClang>:-Wno-implicit-function-declaration>
            $<$<C_COMPILER_ID:GNU>:-Wno-implicit-function-declaration>
            $<$<C_COMPILER_ID:IAR>:>
)

target_compile_definitions(tfm_config
    INTERFACE
        $<$<OR:$<BOOL:${CONFIG_TFM_SPM_BACKEND_IPC}>,$<BOOL:${CONFIG_TFM_CONNECTION_BASED_SERVICE_API}>>:CONFIG_TFM_CONNECTION_POOL_ENABLE>
)

############################ TFM arch ##########################################

target_include_directories(tfm_arch
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/core/arch>
)

############################ Boot Status #######################################

target_include_directories(tfm_boot_status
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/boot>
)

############################# Secure veneers ###################################

if(CONFIG_TFM_USE_TRUSTZONE)
    # If this is added to the spm, it is discarded as it is not used. Since the
    # spm is a static library it can't generate veneers under all compilers so
    # instead this single file is added to the tfm_s target.
    target_sources(tfm_s
        PRIVATE
            $<$<BOOL:${TFM_NS_MANAGE_NSID}>:${CMAKE_CURRENT_SOURCE_DIR}/ns_client_ext/tfm_ns_client_ext.c>
    )
endif()
