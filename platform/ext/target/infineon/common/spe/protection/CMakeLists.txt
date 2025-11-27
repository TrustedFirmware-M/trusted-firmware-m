#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

target_sources(tfm_spm
    PRIVATE
        $<$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V1}>:${CMAKE_CURRENT_LIST_DIR}/protection_mpc_hw_mpc_v1.c>
        $<$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V2}>:${CMAKE_CURRENT_LIST_DIR}/protection_mpc_hw_mpc_v2.c>
        $<$<OR:$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V1}>,$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V2}>>:${CMAKE_CURRENT_LIST_DIR}/protection_mpc_hw_mpc.c>
        $<$<OR:$<STREQUAL:${IFX_SE_IPC_SERVICE_TYPE},FULL>,$<STREQUAL:${IFX_SE_IPC_SERVICE_TYPE},BASE>>:${CMAKE_CURRENT_LIST_DIR}/protection_mpc_sert.c>
        $<$<BOOL:${IFX_MPC_DRIVER_SW_POLICY}>:${CMAKE_CURRENT_LIST_DIR}/protection_mpc_sw_policy.c>
        protection_mpu.c
        protection_msc.c
        $<$<BOOL:${IFX_PPC_DRIVER_V1}>:${CMAKE_CURRENT_LIST_DIR}/protection_ppc_v1.c>
        $<$<BOOL:${IFX_PPC_DRIVER_V2}>:${CMAKE_CURRENT_LIST_DIR}/protection_ppc_v2.c>
        protection_sau.c
        protection_tz.c
        $<$<OR:$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V1}>,$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V2}>>:${CMAKE_CURRENT_LIST_DIR}/protection_utils.c>
        tfm_hal_isolation.c
        $<$<BOOL:${PLATFORM_ARCH_HOOKS}>:${CMAKE_CURRENT_LIST_DIR}/tfm_platform_arch_hooks.c>
        ${IFX_GENERATED_DIR}/secure_fw/ifx/partition_info.c
)

target_include_directories(tfm_spm
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/drivers/protection
        ${IFX_COMMON_SOURCE_DIR}/shared/mailbox
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(tfm_sprt
    PRIVATE
        $<$<BOOL:${IFX_ISOLATION_PC_SWITCHING}>:${CMAKE_CURRENT_LIST_DIR}/protection_pc.c>
)

target_include_directories(tfm_sprt
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(platform_s
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${IFX_SHARED_RO_DATA_TARGET}
    PRIVATE
        protection_shared_data.c
)

target_compile_options(${IFX_SHARED_RO_DATA_TARGET}
    PRIVATE
        ${COMPILER_CP_FLAG}
)
