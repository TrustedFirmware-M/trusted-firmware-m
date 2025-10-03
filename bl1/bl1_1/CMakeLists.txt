#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

find_package(Python3)

add_subdirectory(lib)
add_subdirectory(shared_lib)
add_executable(bl1_1)

set_target_properties(bl1_1
    PROPERTIES
        SUFFIX ".axf"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_convert_to_bin_target(bl1_1)

target_link_options(bl1_1
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/bl1_1.map>
        $<$<C_COMPILER_ID:ARMClang>:--map>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/bl1_1.map>
        $<$<C_COMPILER_ID:Clang>:LINKER:-Map=${CMAKE_BINARY_DIR}/bin/bl1_1.map>
)

target_compile_options(bl1_1
    PUBLIC
        ${BL1_COMPILER_CP_FLAG}
)

target_link_options(bl1_1
    PUBLIC
        ${BL1_LINKER_CP_OPTION}
)

target_sources(bl1_1
    PRIVATE
        main.c
        $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
)

target_link_libraries(bl1_1
    PRIVATE
        bl1_1_lib
        bl1_1_shared_lib
        platform_bl1_1
        $<$<AND:$<BOOL:${TEST_BL1_1}>,$<BOOL:${PLATFORM_DEFAULT_BL1_1_TESTS}>>:bl1_1_tests>
)

target_compile_definitions(bl1_1
    PRIVATE
        $<$<BOOL:${TEST_BL1_1}>:TEST_BL1_1>
        $<$<BOOL:${TEST_BL1_2}>:TEST_BL1_2>
        $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:TFM_MEASURED_BOOT_API>
)

if (BL1_1_SHARED_SYMBOLS_PATH)
    target_share_symbols(bl1_1
        ${BL1_1_SHARED_SYMBOLS_PATH}
    )
endif()

################################################################################

add_library(signing_layout_bl1_2 OBJECT signing_layout.c)
target_compile_options(signing_layout_bl1_2
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-E\;-xc>
        $<$<C_COMPILER_ID:ARMClang>:-E\;-xc>
        $<$<C_COMPILER_ID:IAR>:--preprocess=ns\;$<TARGET_OBJECTS:signing_layout_bl1_2>>
        $<$<C_COMPILER_ID:Clang>:-E\;-xc>
)
target_link_libraries(signing_layout_bl1_2
    PRIVATE
        platform_region_defs
)

################################################################################
get_target_property(bin_dir bl1_2 RUNTIME_OUTPUT_DIRECTORY)

add_custom_target(bl1_2_padded_bin
    ALL
    SOURCES bl1_2_padded.bin ${bin_dir}/bl1_2_padded.bin
    SOURCES bl1_2_padded_hash.bin ${bin_dir}/bl1_2_padded_hash.bin
)

add_custom_command(OUTPUT bl1_2_padded.bin bl1_2_padded_hash.bin
    OUTPUT ${bin_dir}/bl1_2_padded.bin ${bin_dir}/bl1_2_padded_hash.bin
    DEPENDS ${bin_dir}/bl1_2.bin bl1_2_bin signing_layout_bl1_2
    COMMAND bl1_1_create_bl1_2_image
                    --input_file ${bin_dir}/bl1_2.bin
                    --img_output_file bl1_2_padded.bin
                    --hash_alg ${TFM_BL1_1_MEASUREMENT_HASH_ALG}
                    --hash_output_file bl1_2_padded_hash.bin
                    --signing_layout_file $<TARGET_OBJECTS:signing_layout_bl1_2>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/bl1_2_padded.bin ${bin_dir}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/bl1_2_padded_hash.bin ${bin_dir}
)

################################################################################

if (TFM_BL1_DEFAULT_PROVISIONING)
    get_target_property(bin_dir bl1_1 RUNTIME_OUTPUT_DIRECTORY)

    add_custom_target(bl1_provisioning_bundle
        ALL
        SOURCES bl1_provisioning_bundle.bin
    )

    add_custom_command(OUTPUT bl1_provisioning_bundle.bin
        OUTPUT ${bin_dir}/bl1_provisioning_bundle.bin
        DEPENDS ${TFM_BL2_ENCRYPTION_KEY_PATH}
        DEPENDS ${TFM_GUK_PATH}
        DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded_hash.bin
        DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded.bin
        bl1_2_padded_bin bl2_signed_bin
        COMMAND bl1_1_create_provisioning_bundle
                        --bl2_encryption_key_input_file ${TFM_BL2_ENCRYPTION_KEY_PATH}
                        --bl2_signing_key_input_file ${TFM_BL1_2_CM_SIGNING_KEY_PATH}
                        --guk_input_file ${TFM_GUK_PATH}
                        --bl1_2_padded_hash_input_file $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded_hash.bin
                        --bl1_2_input_file $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded.bin
                        --bundle_output_file bl1_provisioning_bundle.bin
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/bl1_provisioning_bundle.bin ${bin_dir}
    )

    add_convert_to_offset_hex_target(bl1_provisioning_bundle
        INPUT_FILE          ${bin_dir}/bl1_provisioning_bundle.bin
        OFFSET_MACRO_NAME   PROVISIONING_CODE_START
        INCLUDE_BL2_HEADER  FALSE
        MIRROR_FILE         $<TARGET_PROPERTY:bl1_1,LINK_DEPENDS>
        OUTPUT_FILE         ${bin_dir}/bl1_provisioning_bundle.hex
    )
endif()
