#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

install(FILES       ${PLATFORM_DIR}/ext/common/uart_stdout.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext/common)

install(DIRECTORY   ${CMAKE_CURRENT_LIST_DIR}/device
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx
        PATTERN     src/armclang EXCLUDE
        PATTERN     src/gcc EXCLUDE
        PATTERN     src/iar EXCLUDE)

# Non-secure build uses platform/linker_scripts folder to lookup for linker script.
install(FILES       ${IFX_COMMON_SOURCE_DIR}/device/src/armclang/ifx_common_ns.sct
                    ${IFX_COMMON_SOURCE_DIR}/device/src/gcc/ifx_common_ns.ld
                    ${IFX_COMMON_SOURCE_DIR}/device/src/iar/ifx_common_ns.icf
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

install(DIRECTORY   ${CMAKE_CURRENT_LIST_DIR}/drivers/stdio
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx/drivers)

install(DIRECTORY   ${CMAKE_CURRENT_LIST_DIR}/cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx)

install(DIRECTORY   ${CMAKE_CURRENT_LIST_DIR}/libs
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx
        PATTERN     libs/ifx_gcov_lib EXCLUDE
        PATTERN     libs/ifx_mbedtls_acceleration EXCLUDE
        PATTERN     libs/ifx_se_rt_services_utils EXCLUDE
        PATTERN     spe EXCLUDE)

install(FILES       ${CMAKE_CURRENT_LIST_DIR}/nspe/tfm_ns_platform_init.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx
        OPTIONAL)

install(FILES       ${CMAKE_CURRENT_LIST_DIR}/nspe/CMakeLists.txt
                    ${CMAKE_CURRENT_LIST_DIR}/nspe/config.cmake
                    ${CMAKE_CURRENT_LIST_DIR}/post_config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx)

configure_file(${IFX_COMMON_SOURCE_DIR}/nspe/spe_config.cmake.in
               ${CMAKE_BINARY_DIR}/generated/platform/cmake/ifx/spe_config.cmake @ONLY)
install(FILES       ${CMAKE_BINARY_DIR}/generated/platform/cmake/ifx/spe_config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx)

install(FILES       ${CMAKE_CURRENT_LIST_DIR}/nspe/os_wrapper/semaphore.h
                    ${CMAKE_CURRENT_LIST_DIR}/nspe/os_wrapper/thread.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR}/os_wrapper)

install(FILES       ${CMAKE_CURRENT_LIST_DIR}/nspe/os_wrapper/os_wrapper_cyabs_rtos.c
        DESTINATION ${INSTALL_INTERFACE_SRC_DIR}/os_wrapper)

install(DIRECTORY   ${CMAKE_CURRENT_LIST_DIR}/shared
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx
        PATTERN     mailbox EXCLUDE)

install(DIRECTORY   ${CMAKE_CURRENT_LIST_DIR}/utils
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx)

#################################### Board #####################################

install(FILES       ${IFX_COMMON_SOURCE_DIR}/board/CMakeLists.txt
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx/board)

install(DIRECTORY   ${IFX_COMMON_SOURCE_DIR}/board/nspe
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx/board)

install(FILES       ${IFX_CONFIG_BSP_PATH}/config_bsp.h
                    ${IFX_CONFIG_BSP_PATH}/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/board)

install(DIRECTORY   ${IFX_BOARD_PATH}/nspe
                    ${IFX_BOARD_PATH}/shared
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/board)

################################## Partitions ##################################

if (TFM_PARTITION_CRYPTO)
    # Install Crypto configuration for MTB non-secure interface
    install(FILES       ${TFM_MBEDCRYPTO_CONFIG_CLIENT_PATH}
            RENAME      tfm_mbedcrypto_config_client.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
    install(FILES       ${TFM_MBEDCRYPTO_PSA_CRYPTO_CONFIG_PATH}
            RENAME      tfm_psa_crypto_config_client.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
    if (MBEDTLS_PSA_CRYPTO_PLATFORM_FILE)
        install(FILES       ${MBEDTLS_PSA_CRYPTO_PLATFORM_FILE}
                RENAME      tfm_mbedtls_psa_crypto_platform.h
                DESTINATION ${INSTALL_INTERFACE_INC_DIR})
    endif()
endif()

if (TFM_PARTITION_NS_AGENT_MAILBOX)
    install(FILES       ${CMAKE_CURRENT_LIST_DIR}/shared/mailbox/platform_multicore.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}/multi_core)

    install(FILES       ${CMAKE_CURRENT_LIST_DIR}/nspe/mailbox/platform_ns_mailbox.c
                        ${CMAKE_CURRENT_LIST_DIR}/nspe/mailbox/tfm_ns_mailbox_rtos_api.c
                        ${CMAKE_CURRENT_LIST_DIR}/shared/mailbox/platform_multicore.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR}/multi_core)
endif()

if (IFX_MTB_MAILBOX)
    install(FILES       ${CMAKE_CURRENT_LIST_DIR}/interface/include/ifx_mtb_mailbox/ifx_mtb_mailbox.h
                        ${CMAKE_CURRENT_LIST_DIR}/shared/mailbox/ifx_platform_mailbox.h
                        DESTINATION ${INSTALL_INTERFACE_INC_DIR}/ifx_mtb_mailbox)


    install(FILES       ${CMAKE_CURRENT_LIST_DIR}/interface/src/ifx_mtb_mailbox/ifx_mtb_mailbox_psa_ns_api.c
                        ${CMAKE_CURRENT_LIST_DIR}/interface/src/ifx_mtb_mailbox/ifx_mtb_mailbox.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR}/ifx_mtb_mailbox)

    if (IFX_MULTICORE_CM55)
        install(FILES       ${IFX_COMMON_SOURCE_DIR}/spe/services/mailbox/platform_hal_multi_core_cm55.c
                DESTINATION ${INSTALL_INTERFACE_SRC_DIR}/ifx_mtb_mailbox)
    endif()
endif()

if (TFM_PARTITION_PLATFORM)
    # Platform service headers
    install(FILES       ${CMAKE_CURRENT_LIST_DIR}/interface/include/ifx_platform_api.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})

    # Platform service sources
    install(FILES       ${CMAKE_CURRENT_LIST_DIR}/interface/src/ifx_platform_private.h
                        ${CMAKE_CURRENT_LIST_DIR}/interface/src/ifx_platform_api.c
            DESTINATION ${INSTALL_INTERFACE_SRC_DIR})
endif()

# IMPROVEMENT: Ideally Driver_* Files should be used from upstream CMSIS folder
# as they are installed there any way.
install(FILES       ${CMSIS_PATH}/CMSIS/Driver/Include/Driver_Common.h
                    ${CMSIS_PATH}/CMSIS/Driver/Include/Driver_USART.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

#################################### Tests #####################################

include(${IFX_COMMON_SOURCE_DIR}/tests/install.cmake OPTIONAL)
