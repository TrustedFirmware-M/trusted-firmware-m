#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

find_package(Python3)

add_executable(cm_provisioning_bundle)

if(${TFM_DUMMY_PROVISIONING})
    include(${CMAKE_SOURCE_DIR}/platform/ext/target/arm/mps4/common/provisioning/bundle_cm/cm_provisioning_config.cmake)
else()
    include("${CM_PROVISIONING_KEYS_CONFIG}" OPTIONAL RESULT_VARIABLE CM_PROVISIONING_KEYS_CONFIG_PATH)
    if(NOT CM_PROVISIONING_KEYS_CONFIG_PATH)
        message(WARNING "The CM_PROVISIONING_KEYS_CONFIG is not set. If the keys are not passed via the command line then \
                        random numbers will be used for provisioning data. \
                        To create and use a CM_PROVISIONING_KEYS_CONFIG file, \
                        see the example in: \
                        tf-m/platform/ext/target/arm/mps4/common/provisioning/bundle_cm/cm_provisioning_config.cmake")
    endif()
endif()

set_target_properties(cm_provisioning_bundle
    PROPERTIES
        SUFFIX ".axf"
)

target_add_scatter_file(cm_provisioning_bundle
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.icf>
    $<$<C_COMPILER_ID:Clang>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.ldc>
)

target_link_options(cm_provisioning_bundle
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/cm_provisioning_bundle.map>
        $<$<C_COMPILER_ID:ARMClang>:--map --entry=do_provision>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/cm_provisioning_bundle.map>
        $<$<C_COMPILER_ID:Clang>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/cm_provisioning_bundle.map>
)

target_compile_options(cm_provisioning_bundle
    PUBLIC
        ${BL1_COMPILER_CP_FLAG}
        ${COMPILER_CMSE_FLAG}
)

target_link_options(cm_provisioning_bundle
    PUBLIC
        ${BL1_LINKER_CP_OPTION}
)

target_link_options(cm_provisioning_bundle
    PRIVATE
        $<$<NOT:$<C_COMPILER_ID:Clang>>:--entry=do_provision>
)

target_sources(cm_provisioning_bundle
    PRIVATE
        cm_provisioning_code.c
        cm_provisioning_data.c
        $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
)

target_include_directories(cm_provisioning_bundle
    PRIVATE
        ../bundle_common
)

target_link_libraries(cm_provisioning_bundle
    PRIVATE
        platform_bl1_1_interface
        bl1_1_shared_lib_interface
)

target_link_shared_code(cm_provisioning_bundle
    bl1_1
)

add_custom_target(cm_provisioning_bundle_bin
    ALL
    SOURCES cm_provisioning_bundle.bin
)

add_custom_target(cm_provisioning_data
    SOURCES
        cm_provisioning_data.c
)

add_custom_command(OUTPUT cm_provisioning_data.c
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/cm_provisioning_data_template.jinja2
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/cm_create_provisioning_data.py
    WORKING_DIRECTORY ${MCUBOOT_PATH}/scripts
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/cm_create_provisioning_data.py
        ${CMAKE_CURRENT_BINARY_DIR}/cm_provisioning_data.c
        --template_path=${CMAKE_CURRENT_SOURCE_DIR}
        --guk=${GUK}
        --sam_config=${SAM_CONFIG}
)

add_custom_command(OUTPUT cm_provisioning_bundle.bin
    DEPENDS $<TARGET_FILE_DIR:cm_provisioning_bundle>/cm_provisioning_bundle.axf
    DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded_hash.bin
    DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded.bin
    bl1_2_padded_bin bl2_signed_bin cm_provisioning_bundle
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../create_provisioning_bundle.py
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:cm_provisioning_bundle>/cm_provisioning_bundle.axf cm_provisioning_bundle.axf
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../create_provisioning_bundle.py
                    --provisioning_bundle_axf $<TARGET_FILE_DIR:cm_provisioning_bundle>/cm_provisioning_bundle.axf
                    --bl1_2_padded_hash_input_file $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded_hash.bin
                    --bl1_2_input_file $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded.bin
                    --bundle_output_file cm_provisioning_bundle.bin
                    --magic "0xC0DEFEED"
                    --tp_mode ${TP_MODE}
                    --key_file=${RTL_KEY_PATH}
                    --krtl_derivation_label="CM_PROVISIONING"
                    --provisioning_lcs 0
                    --code_pad_size ${PROVISIONING_CODE_PADDED_SIZE}
                    --data_pad_size ${PROVISIONING_DATA_PADDED_SIZE}
                    --values_pad_size ${PROVISIONING_VALUES_PADDED_SIZE}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/cm_provisioning_bundle.bin ${CMAKE_BINARY_DIR}/bin/cm_provisioning_bundle.bin
)
