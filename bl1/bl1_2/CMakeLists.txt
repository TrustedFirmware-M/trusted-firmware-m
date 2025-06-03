#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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
        $<$<C_COMPILER_ID:Clang>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/bl1_2.map>
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
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:TFM_BL1_2_ENABLE_LMS>
        $<$<BOOL:${TFM_BL1_2_ENABLE_ECDSA}>:TFM_BL1_2_ENABLE_ECDSA>
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

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/config)

add_custom_target(bl2_image_config
    ALL
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/config/bl2_image_config.pickle
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config/bl2_image_config.pickle
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/modules/bl2_image_config.py
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lib/interface/image_layout_bl1_2.h
    DEPENDS ${BL1_2_CONFIG_DIR}/bl1_2_config.h
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/modules/bl2_image_config.py
        --bl2_image_layout_h_file=${CMAKE_CURRENT_SOURCE_DIR}/lib/interface/image_layout_bl1_2.h
        --compile_commands_file=${CMAKE_BINARY_DIR}/compile_commands.json
        --bl2_image_config_output_file=${CMAKE_CURRENT_BINARY_DIR}/config/bl2_image_config.pickle
)


get_target_property(bin_dir bl2 RUNTIME_OUTPUT_DIRECTORY)

add_custom_target(bl2_signed_bin
    ALL
    SOURCES bl2_signed.bin
    SOURCES ${bin_dir}/bl2_signed.bin
)

add_custom_command(OUTPUT bl2_signed.bin
    OUTPUT ${bin_dir}/bl2_signed.bin
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_bl2_img.py
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/bl2_image_config.pickle
    DEPENDS bl2_bin
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_bl2_img.py
                    --bl2_image_config ${CMAKE_CURRENT_BINARY_DIR}/config/bl2_image_config.pickle
                    --bl2_bin $<TARGET_FILE_DIR:bl2>/bl2.bin
                    --image_output_file bl2_signed.bin
                    --signer_0:sign_alg ${TFM_BL1_2_CM_SIGNING_ALG}
                    --signer_0:sign_key ${TFM_BL1_2_CM_SIGNING_KEY_PATH}
                    --signer_0:sign_hash_alg ${TFM_BL1_2_MEASUREMENT_HASH_ALG}
                    $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--signer_1:sign_alg=${TFM_BL1_2_DM_SIGNING_ALG}>
                    $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--signer_1:sign_key=${TFM_BL1_2_DM_SIGNING_KEY_PATH}>
                    $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--signer_1:sign_hash_alg=${TFM_BL1_2_MEASUREMENT_HASH_ALG}>
                    --image_version ${TFM_BL1_IMAGE_VERSION_BL2}
                    --image_security_counter ${TFM_BL1_IMAGE_SECURITY_COUNTER_BL2}
                    $<$<BOOL:${TFM_BL1_2_IMAGE_ENCRYPTION}>:--encrypt_key=${TFM_BL2_ENCRYPTION_KEY_PATH}>
                    $<$<BOOL:${TFM_BL1_2_IMAGE_ENCRYPTION}>:--encrypt_alg=AES_CTR>
                    $<$<BOOL:${TFM_BL1_2_IMAGE_ENCRYPTION}>:--kdf_alg=$<IF:$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>,hkdf,sp800-108_cmac>>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/bl2_signed.bin $<TARGET_FILE_DIR:bl2>
)
