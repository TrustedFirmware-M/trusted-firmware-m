#-------------------------------------------------------------------------------
# Copyright (c) 2019-2020, Arm Limited. All rights reserved.
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

if(POLICY CMP0115)
    cmake_policy(SET CMP0115 OLD)
endif()
set(B_U585I_IOT02A_DIR ${CMAKE_CURRENT_LIST_DIR})
set(STM_COMMON_DIR ${B_U585I_IOT02A_DIR}/../common)

#def for stm32u5xx
include(${STM_COMMON_DIR}/stm32u5xx/CMakeLists.txt)
#========================= Platform defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${STM_COMMON_DIR}/stm32u5xx/Device/Source/startup_stm32u5xx_s.c
        ${STM_COMMON_DIR}/stm32u5xx/bl2/low_level_ospi_device.c
        ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_ospi_flash.c
        ${STM_COMMON_DIR}/hal/Components/mx25lm51245g/mx25lm51245g.c
        ${B_U585I_IOT02A_DIR}/src/b_u585i_iot02a_ospi.c
)

if(STSAFEA)
    set(STSAFEA_INTERFACE_SRC_DIR ${B_U585I_IOT02A_DIR}/src/)
    include(${STM_COMMON_DIR}/secure_element/CMakeLists.txt)
endif()

# cpuarch.cmake is used to set things that related to the platform that are both
install(FILES
    ${TARGET_PLATFORM_PATH}/cpuarch.cmake
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(FILES
    ${STM_COMMON_DIR}/stm32u5xx/Device/Source/startup_stm32u5xx_ns.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source
)

install(DIRECTORY
    ${TARGET_PLATFORM_PATH}/ns/
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY
    ${TARGET_PLATFORM_PATH}/include
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY
    ${STM_COMMON_DIR}/hal/accelerator/
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
    FILES_MATCHING PATTERN "*.h"
)

install(FILES
    ${B_U585I_IOT02A_DIR}/partition/flash_layout.h
    ${B_U585I_IOT02A_DIR}/partition/region_defs.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/partition
)

install(FILES
    ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_ospi_flash.c
    ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_ospi_flash.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/CMSIS_Driver
)

install(FILES
    ${STM_COMMON_DIR}/hal/Components/mx25lm51245g/mx25lm51245g.c
    ${STM_COMMON_DIR}/hal/Components/mx25lm51245g/mx25lm51245g.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Components/mx25lm51245g
)

install(FILES
    ${STM_COMMON_DIR}/stm32u5xx/bl2/low_level_ospi_device.c
    ${B_U585I_IOT02A_DIR}/src/b_u585i_iot02a_ospi.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/src
)

if(BL2)
    set(provision_script_dir ${CMAKE_CURRENT_LIST_DIR}/provision)
    set(provision_output_dir ${CMAKE_BINARY_DIR}/platform/target)
    set(provision_file ${provision_output_dir}/otp_provision.c)

    # Required arguments
    set(prov_args
        --template_path=${provision_script_dir}
        --bl2_mcuboot_hw_key=${MCUBOOT_HW_KEY}
    )

    # Optional arguments - Replaced by default values if not provided
    foreach(opt IN ITEMS
        BL2_ROT_PRIV_KEY_0
        BL2_ROT_PRIV_KEY_1
        BL2_ROT_PRIV_KEY_2
        SECURE_DEBUG_PK
        HUK
        IAK
        IAK_ID
        CERT_REF
        BOOT_SEED
        IMPLEMENTATION_ID
        CERTIFICATION_REFERENCE
        VERIFICATION_SERVICE_URL
        ENTROPY_SEED
    )
        if(DEFINED ${opt} AND NOT "${${opt}}" STREQUAL "")
            string(TOLOWER ${opt} opt_lower)
            list(APPEND prov_args --${opt_lower}=${${opt}})
        else()
            list(APPEND prov_dummy_values ${opt})
        endif()
    endforeach()

    if(prov_dummy_values)
        string(REPLACE ";" ", " prov_dummy_str "${prov_dummy_values}")
        message(WARNING
            "OTP provisioning: the following values are not set and will use "
            "insecure development defaults: ${prov_dummy_str}. "
            "Do NOT use these values in production."
        )
    endif()

    add_custom_command(
        OUTPUT ${provision_file}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${provision_output_dir}
        COMMAND ${Python3_EXECUTABLE}
            ${provision_script_dir}/otp_provision.py
            ${provision_file}
            ${prov_args}
        DEPENDS
            ${provision_script_dir}/otp_provision.py
            ${provision_script_dir}/provisioning_data_template.jinja2
            ${MCUBOOT_KEY_S}
            ${MCUBOOT_KEY_NS}
        COMMAND_EXPAND_LISTS
        VERBATIM
        COMMENT "Generating OTP provisioning data"
    )

    set_source_files_properties(${provision_file} PROPERTIES GENERATED TRUE)

    add_custom_target(gen_otp_provision DEPENDS ${provision_file})
    add_dependencies(bl2 gen_otp_provision)

    target_sources(bl2
        PRIVATE
            ${STM_COMMON_DIR}/stm32u5xx/Device/Source/startup_stm32u5xx_bl2.c
            ${STM_COMMON_DIR}/stm32u5xx/bl2/low_level_ospi_device.c
            ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_ospi_flash.c
            ${STM_COMMON_DIR}/hal/Components/mx25lm51245g/mx25lm51245g.c
            ${provision_file}
            ${STM_COMMON_DIR}/hal/provision/nvm_init.c
            ${STM_COMMON_DIR}/hal/provision/nvmcnt_init.c
            ${B_U585I_IOT02A_DIR}/src/b_u585i_iot02a_ospi.c
    )
endif()

#install flash layout for postbuild.sh
install(FILES
    ${B_U585I_IOT02A_DIR}/partition/flash_layout.h
    ${B_U585I_IOT02A_DIR}/partition/region_defs.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
set (BL2_FILE_TO_PREPROCESS ${CMAKE_CURRENT_BINARY_DIR}/image_macros_to_preprocess_bl2.c)
file(WRITE ${BL2_FILE_TO_PREPROCESS} ${BL2_PREPROCESSING})

install(FILES
    ${BL2_FILE_TO_PREPROCESS}
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
