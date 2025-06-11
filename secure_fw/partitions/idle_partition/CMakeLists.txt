#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2021-2023 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if (TFM_LOAD_NS_IMAGE AND NOT CONFIG_TFM_FLIH_API AND NOT CONFIG_TFM_SLIH_API AND
NOT TFM_MULTI_CORE_TOPOLOGY)
    return()
endif()

cmake_minimum_required(VERSION 3.21)

target_sources(tfm_spm
    PRIVATE
        idle_partition.c
)

target_sources(tfm_partitions
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/load_info_idle_sp.c
)

target_compile_definitions(tfm_config
    INTERFACE
        TFM_PARTITION_IDLE
)
