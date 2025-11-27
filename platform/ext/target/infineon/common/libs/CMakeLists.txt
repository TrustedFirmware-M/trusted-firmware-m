#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/cmsis)
    add_subdirectory(cmsis "${CMAKE_BINARY_DIR}/ifx_cmsis")
endif()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/core-lib)
    add_subdirectory(core-lib "${CMAKE_BINARY_DIR}/ifx_core")
endif()

if(DEFINED IFX_DEV_SUPPORT_LIB_PATH AND EXISTS ${CMAKE_CURRENT_LIST_DIR}/ifx_dev_support)
    add_subdirectory(ifx_dev_support "${CMAKE_BINARY_DIR}/ifx_sup")
endif()

if(DEFINED IFX_ABSTRACTION_RTOS_LIB_PATH AND EXISTS ${CMAKE_CURRENT_LIST_DIR}/ifx_abs_rtos)
    add_subdirectory(ifx_abs_rtos "${CMAKE_BINARY_DIR}/ifx_abs_rtos")
endif()

if(DEFINED IFX_MTB_IPC_LIB_PATH AND EXISTS ${CMAKE_CURRENT_LIST_DIR}/ifx_mtb_ipc)
    add_subdirectory(ifx_mtb_ipc "${CMAKE_BINARY_DIR}/ifx_mtb_ipc")
endif()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/ifx_pdl)
    add_subdirectory(ifx_pdl "${CMAKE_BINARY_DIR}/ifx_pdl")
endif()

if (IFX_MTB_SRF)
    add_subdirectory(ifx_mtb_srf "${CMAKE_BINARY_DIR}/ifx_srf")
endif()

# Device DB is only used for sources generation and sources generation is only
# done in non-MTB builds thus Device DB is only needed for non-MTB builds
if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/ifx_device_db AND NOT IFX_MTB_BUILD)
    add_subdirectory(ifx_device_db "${CMAKE_BINARY_DIR}/ifx_db")
endif()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/ifx_gcov_lib)
    add_subdirectory(ifx_gcov_lib)
endif()

if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/ifx_se_rt_services_utils
   AND S_BUILD AND IFX_SE_RT_SERVICES_UTILS_ENABLED)
    # SE RT Services is used by TF-M secure code only
    add_subdirectory(ifx_se_rt_services_utils "${CMAKE_BINARY_DIR}/ifx_srt")
endif()
