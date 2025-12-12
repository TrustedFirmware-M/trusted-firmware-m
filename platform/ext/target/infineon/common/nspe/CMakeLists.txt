#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

############################# Platform Non-Secure #############################

add_library(platform_ns)

target_include_directories(platform_ns
    PRIVATE
        ${IFX_COMMON_SOURCE_DIR}/interface/src
    PUBLIC
        ${IFX_COMMON_SOURCE_DIR}/device/include
        $<$<BOOL:${TEST_NS_FPU}>:${IFX_COMMON_SOURCE_DIR}/tests>
)

target_sources(platform_ns
    PRIVATE
        $<$<OR:$<BOOL:${TFM_NS_REG_TEST}>,$<BOOL:${TEST_PSA_API}>>:${IFX_COMMON_SOURCE_DIR}/tests/plat_test_ns.c>

        ${IFX_COMMON_SOURCE_DIR}/device/src/device_definition.c
        $<$<BOOL:${IFX_UART_ENABLED}>:${IFX_COMMON_SOURCE_DIR}/drivers/stdio/uart_pdl_stdout.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${INTERFACE_SRC_DIR}/ifx_platform_api.c>

        $<$<BOOL:${TEST_NS_FPU}>:${IFX_COMMON_SOURCE_DIR}/tests/ifx_fpu_ns.c>
        $<$<BOOL:${TEST_NS_FPU}>:${IFX_COMMON_SOURCE_DIR}/tests/test_interrupt.c>

        ${IFX_COMMON_SOURCE_DIR}/tfm_ns_platform_init.c

        ${IFX_COMMON_SOURCE_DIR}/utils/ifx_regions.c
)

if(IFX_NS_INTERFACE_MAILBOX)
    if(IFX_MTB_MAILBOX)
        add_library(ifx_mtb_mailbox STATIC EXCLUDE_FROM_ALL)

        target_sources(ifx_mtb_mailbox
            PRIVATE
                ${INTERFACE_SRC_DIR}/multi_core/tfm_multi_core_psa_ns_api.c
                ${INTERFACE_SRC_DIR}/multi_core/ifx_mtb_mailbox.c
        )

        target_link_libraries(ifx_mtb_mailbox
            PRIVATE
                ifx_bsp
                ifx_cmsis_lib
                ifx_mtb_hal
                ifx_mtb_srf_ns
                psa_interface
        )

        target_include_directories(ifx_mtb_mailbox
            PUBLIC
                ${INTERFACE_INC_DIR}/multi_core
        )

        target_link_libraries(tfm_api_ns
            PUBLIC
                ifx_mtb_mailbox
        )
    else()
        target_sources(platform_ns
            PRIVATE
                ${INTERFACE_SRC_DIR}/multi_core/platform_ns_mailbox.c
                ${INTERFACE_SRC_DIR}/multi_core/platform_multicore.c
        )
    endif()
endif()

if(IFX_MTB_MAILBOX AND IFX_NS_INTERFACE_TZ)
    # When IFX_MTB_MAILBOX is enabled - on core NSPE acts like a proxy for off
    # core NSPE requests. Thus multi_core is added to on core NSPE include
    # directories so that on core NSPE can work with off core NSPE request types.
    target_include_directories(tfm_api_ns
        PUBLIC
            ${INTERFACE_INC_DIR}/multi_core
    )
endif()

target_compile_definitions(platform_ns
    PUBLIC
        $<$<BOOL:${IFX_UART_ENABLED}>:IFX_UART_ENABLED=1>
        $<$<BOOL:${TEST_NS_FPU}>:TEST_NS_FPU=1>
)

target_link_libraries(platform_ns
    PUBLIC
        ifx_pdl_ns
        psa_interface
        tfm_api_ns
)

target_compile_definitions(tfm_config
    INTERFACE
        ${IFX_PDL_PART_NUMBER}
        # Infineon platforms use custom version of tfm_ns_platform_init function
        # provided in tfm_ns_platform_init.c
        TFM_CUSTOM_NS_PLATFORM_INIT
        $<$<BOOL:${RAM_VECTORS_SUPPORT}>:RAM_VECTORS_SUPPORT>
)

target_include_directories(tfm_config
    INTERFACE
        ${IFX_COMMON_SOURCE_DIR}/utils
)
