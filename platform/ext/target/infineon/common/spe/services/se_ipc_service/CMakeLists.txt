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
            ${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
    )

    target_sources(${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
        PRIVATE
            $<$<BOOL:${IFX_PARTITION_SE_IPC_SERVICE}>:${CMAKE_CURRENT_SOURCE_DIR}/ifx_se_ipc_service_syscall_partition.c>
            $<$<NOT:$<BOOL:${IFX_PARTITION_SE_IPC_SERVICE}>>:${CMAKE_CURRENT_SOURCE_DIR}/ifx_se_ipc_service_syscall_direct.c>
            ifx_se_ipc_service_ipc.c
            ${IFX_SE_RT_SERVICES_UTILS_PATH}/ifx_se_syscall_builtin.c
    )

    target_link_libraries(${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
        PRIVATE
            psa_interface
            tfm_sprt
    )
endif()
