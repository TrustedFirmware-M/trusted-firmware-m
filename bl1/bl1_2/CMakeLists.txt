#-------------------------------------------------------------------------------
# Copyright (c) 2021-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

find_package(Python3)

set(CMAKE_BUILD_TYPE ${BL1_2_BUILD_TYPE})

add_subdirectory(lib)

add_executable(bl1_2)

set_target_properties(bl1_2
    PROPERTIES
        SUFFIX ".axf"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_convert_to_bin_target(bl1_2)

target_link_options(bl1_2
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/bl1_2.map>
        $<$<C_COMPILER_ID:ARMClang>:--map>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/bl1_2.map>
)

target_compile_options(bl1_2
    PUBLIC
        ${BL1_COMPILER_CP_FLAG}
)

target_link_options(bl1_2
    PUBLIC
        ${BL1_LINKER_CP_OPTION}
)

target_sources(bl1_2
    PRIVATE
        main.c
        $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
)

target_link_libraries(bl1_2
    PRIVATE
        bl1_1_shared_lib_interface
        bl1_2_lib
        platform_bl1_1_interface
        platform_bl1_2
        $<$<AND:$<BOOL:${TEST_BL1_2}>,$<BOOL:${PLATFORM_DEFAULT_BL1_2_TESTS}>>:bl1_2_tests>
)

target_compile_definitions(bl1_2
    PRIVATE
        $<$<BOOL:${TFM_BL1_MEMORY_MAPPED_FLASH}>:TFM_BL1_MEMORY_MAPPED_FLASH>
        $<$<BOOL:${TEST_BL1_1}>:TEST_BL1_1>
        $<$<BOOL:${TEST_BL1_2}>:TEST_BL1_2>
        $<$<BOOL:${TFM_BL1_PQ_CRYPTO}>:TFM_BL1_PQ_CRYPTO>
        $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:TFM_MEASURED_BOOT_API>
)

if (BL1_2_SHARED_SYMBOLS_PATH)
    target_share_symbols(bl1_2
        ${BL1_2_SHARED_SYMBOLS_PATH}
    )
endif()

target_link_shared_code(bl1_2
    bl1_1
)

add_dependencies(bl1_2
    bl1_1_shared_lib
)

################################################################################

set(FLASH_AREA_NUM ${TFM_BL2_IMAGE_FLASH_AREA_NUM})
configure_file(signing_layout.c.in signing_layout_bl2.c @ONLY)

add_library(signing_layout_bl2 OBJECT ${CMAKE_CURRENT_BINARY_DIR}/signing_layout_bl2.c)
target_compile_options(signing_layout_bl2
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-E\;-xc>
        $<$<C_COMPILER_ID:ARMClang>:-E\;-xc>
        $<$<C_COMPILER_ID:IAR>:--preprocess=ns\;$<TARGET_OBJECTS:signing_layout_bl2>>
)
target_link_libraries(signing_layout_bl2
    PRIVATE
        platform_region_defs
)

################################################################################
get_target_property(bin_dir bl2 RUNTIME_OUTPUT_DIRECTORY)

add_custom_target(bl2_signed_bin
    ALL
    SOURCES bl2_signed.bin
    SOURCES bl2_signed_hash.bin
    SOURCES ${bin_dir}/bl2_signed.bin
    SOURCES ${bin_dir}/bl2_signed_hash.bin
)

add_custom_command(OUTPUT bl2_signed.bin bl2_signed_hash.bin
    OUTPUT ${bin_dir}/bl2_signed.bin ${bin_dir}/bl2_signed_hash.bin
    DEPENDS $<TARGET_FILE_DIR:bl2>/bl2.bin bl2_bin signing_layout_bl2
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_bl2_img.py
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_bl2_img.py
                    --input_file $<TARGET_FILE_DIR:bl2>/bl2.bin
                    --img_output_file bl2_signed.bin
                    --hash_output_file bl2_signed_hash.bin
                    --encrypt_key_file ${TFM_BL2_ENCRYPTION_KEY_PATH}
                    --sign_key_file ${TFM_BL2_SIGNING_KEY_PATH}
                    --signing_layout_file $<TARGET_OBJECTS:signing_layout_bl2>
                    --img_version ${TFM_BL1_IMAGE_VERSION_BL2}
                    --img_security_counter ${TFM_BL1_IMAGE_SECURITY_COUNTER_BL2}
                    --header_size ${BL1_HEADER_SIZE}
                    --kdf_alg $<IF:$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>,hkdf,cmac>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/bl2_signed.bin $<TARGET_FILE_DIR:bl2>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/bl2_signed_hash.bin $<TARGET_FILE_DIR:bl2>
)
