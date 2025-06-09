#-------------------------------------------------------------------------------
# Copyright (c) 2020-2024, Arm Limited. All rights reserved.
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

install(FILES       ${TARGET_PLATFORM_PATH}/Device/Config/device_cfg.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(FILES       ${TARGET_PLATFORM_PATH}/security/policy/policy_multi_CM0_CM4_tfm_dev_certs.json
        DESTINATION ${INSTALL_IMAGE_SIGNING_DIR})

install(FILES       ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/armclang/psoc6_ns.sct
                    ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/gcc/psoc6_ns.ld
                    ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/iar/psoc6_ns.icf
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

install(FILES       ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/armclang/startup_psoc64_ns.s
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source/armclang)

install(FILES       ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/gcc/startup_psoc64_ns.S
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source/gcc)

install(FILES       ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/iar/startup_psoc64_ns.s
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source/iar)

install(FILES       ${TARGET_PLATFORM_PATH}/ns/cpuarch_ns.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
        RENAME      cpuarch.cmake)

install(FILES       ${TARGET_PLATFORM_PATH}/ns/CMakeLists.txt
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/mailbox/platform_ns_mailbox.c
                    ${TARGET_PLATFORM_PATH}/mailbox/platform_multicore.c
                    ${TARGET_PLATFORM_PATH}/mailbox/ns_ipc_config.h
                    ${TARGET_PLATFORM_PATH}/mailbox/platform_multicore.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../interface/src/multi_core)

install(FILES       ${TARGET_PLATFORM_PATH}/Device/Source/system_psoc6_cm4.c
                    ${TARGET_PLATFORM_PATH}/Device/Source/psoc6_system_init_cm4.c
                    ${TARGET_PLATFORM_PATH}/Device/Source/device_definition.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source)

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/Device/Config
                    ${TARGET_PLATFORM_PATH}/Device/Include
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device)

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/partition
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   $<BUILD_INTERFACE:${CMSIS_PATH}/CMSIS/Core/Include>
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext/cmsis)

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/Native_Driver/generated_source
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Native_Driver)

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/CMSIS_Driver
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/target_cfg.h
                    ${TARGET_PLATFORM_PATH}/tfm_peripherals_def.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

if(TFM_PARTITION_PLATFORM)
install(FILES       ${TARGET_PLATFORM_PATH}/plat_test.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
endif()

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/libs
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Install test configs
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
