#-------------------------------------------------------------------------------
# Copyright (c) 2020-2021, Arm Limited. All rights reserved.
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0079 NEW)

target_compile_definitions(tfm_config
    INTERFACE
        $<$<BOOL:${IFX_PARTITION_SE_IPC_SERVICE}>:IFX_PARTITION_SE_IPC_SERVICE>
        IFX_SE_IPC_SERVICE_FULL=$<STREQUAL:${IFX_SE_IPC_SERVICE_TYPE},FULL>
        IFX_SE_IPC_SERVICE_BASE=$<STREQUAL:${IFX_SE_IPC_SERVICE_TYPE},BASE>
)

################################ SE IPC Service ################################

if (IFX_PARTITION_SE_IPC_SERVICE)
    add_library(tfm_psa_rot_partition_ifx_se_ipc_service STATIC EXCLUDE_FROM_ALL)

    add_dependencies(tfm_psa_rot_partition_ifx_se_ipc_service manifest_tool)

    target_include_directories(tfm_psa_rot_partition_ifx_se_ipc_service
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
        PRIVATE
            ${IFX_GENERATED_DIR}/secure_fw/partitions/ifx_se_ipc_service
    )
    target_include_directories(tfm_partitions
        INTERFACE
            ${IFX_GENERATED_DIR}/secure_fw/partitions/ifx_se_ipc_service
    )

    target_sources(tfm_psa_rot_partition_ifx_se_ipc_service
        PRIVATE
            ifx_se_ipc_service_req_mngr.c
    )

    # The generated sources
    target_sources(tfm_psa_rot_partition_ifx_se_ipc_service
        PRIVATE
            ${IFX_GENERATED_DIR}/secure_fw/partitions/ifx_se_ipc_service/auto_generated/intermedia_ifx_se_ipc_service.c
    )
    target_sources(tfm_partitions
        INTERFACE
            ${IFX_GENERATED_DIR}/secure_fw/partitions/ifx_se_ipc_service/auto_generated/load_info_ifx_se_ipc_service.c
    )

    target_link_libraries(tfm_psa_rot_partition_ifx_se_ipc_service
        PRIVATE
            platform_s
            tfm_sprt
            ifx_se_rt_services_utils_s
    )

    ############################ Secure API ########################################

    # The veneers give warnings about not being properly declared so they get hidden
    # to not overshadow _real_ warnings.
    set_source_files_properties(ifx_se_ipc_service_secure_api.c
        PROPERTIES
            COMPILE_FLAGS
                $<$<C_COMPILER_ID:ARMClang>:-Wno-implicit-function-declaration>
                $<$<C_COMPILER_ID:GNU>:-Wno-implicit-function-declaration>
                $<$<C_COMPILER_ID:IAR>:>
    )

    ############################ Partition Defs ####################################

    target_link_libraries(tfm_partitions
        INTERFACE
            tfm_psa_rot_partition_ifx_se_ipc_service
    )
endif()

############################# SPM Interface ####################################

if (IFX_SE_IPC_SERVICE_TYPE STREQUAL "FULL" OR IFX_SE_IPC_SERVICE_TYPE STREQUAL "BASE")
    target_sources(tfm_spm
        PRIVATE
            ifx_se_ipc_service_spm.c
    )

    target_include_directories(tfm_spm
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

    target_link_libraries(tfm_spm
        PRIVATE
            ifx_se_rt_services_utils_s
    )

    target_sources(ifx_se_rt_services_utils_s
        PRIVATE
            $<$<BOOL:${IFX_PARTITION_SE_IPC_SERVICE}>:${CMAKE_CURRENT_SOURCE_DIR}/ifx_se_ipc_service_syscall_partition.c>
            $<$<NOT:$<BOOL:${IFX_PARTITION_SE_IPC_SERVICE}>>:${CMAKE_CURRENT_SOURCE_DIR}/ifx_se_ipc_service_syscall_direct.c>
            ifx_se_ipc_service_ipc.c
            ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_syscall_builtin.c
    )

    target_link_libraries(ifx_se_rt_services_utils_s
        PRIVATE
            psa_interface
            tfm_sprt
    )
endif()
