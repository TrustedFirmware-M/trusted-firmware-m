#-------------------------------------------------------------------------------
# Copyright (c) 2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------


find_package(Python3)

add_executable(provisioning_bundle)

if(${TFM_DUMMY_PROVISIONING})
    include(${CMAKE_SOURCE_DIR}/platform/ext/target/arm/mps3/common/provisioning/provisioning_config.cmake)
else()
    include("${PROVISIONING_KEYS_CONFIG}" OPTIONAL RESULT_VARIABLE PROVISIONING_KEYS_CONFIG_PATH)
    if(NOT PROVISIONING_KEYS_CONFIG_PATH)
        message(WARNING "The PROVISIONING_KEYS_CONFIG is not set. If the keys are not passed via the command line then \
                        random numbers will be used for HUK/IAK etc. \
                        To create and use a PROVISIONING_KEYS_CONFIG file, \
                        see the example in: tf-m/platform/ext/target/arm/mps3/common/provisioning/provisioning_config.cmake")
    endif()
endif()

set_target_properties(provisioning_bundle
    PROPERTIES
        SUFFIX ".axf"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_add_scatter_file(provisioning_bundle
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/provisioning_bundle.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/provisioning_bundle.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_CURRENT_SOURCE_DIR}/provisioning_bundle.icf>
)

target_link_options(provisioning_bundle
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/provisioning_bundle.map>
        $<$<C_COMPILER_ID:ARMClang>:--map>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/provisioning_bundle.map>
)

target_link_options(provisioning_bundle
    PRIVATE
        $<$<C_COMPILER_ID:ARMClang,IAR>:LINKER:--entry=do_provision>
)

target_sources(provisioning_bundle
    PRIVATE
        ./provisioning_code.c
        ./provisioning_data.c
        $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
)

target_include_directories(provisioning_bundle
    PRIVATE
        .
)

target_link_libraries(provisioning_bundle
    platform_s
    psa_interface
)

target_compile_definitions(provisioning_bundle
    PRIVATE
        $<$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>:PLATFORM_DEFAULT_CRYPTO_KEYS>
        $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:PLATFORM_DEFAULT_OTP>
        $<$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>:SYMMETRIC_INITIAL_ATTESTATION>
        $<$<BOOL:${TFM_DUMMY_PROVISIONING}>:TFM_DUMMY_PROVISIONING>
        $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:PLATFORM_DEFAULT_NV_COUNTERS>
        $<$<BOOL:${PLATFORM_DEFAULT_OTP_WRITEABLE}>:OTP_WRITEABLE>
)

add_custom_target(encrypted_provisioning_bundle
    ALL
    SOURCES encrypted_provisioning_bundle.bin
)

add_custom_command(OUTPUT encrypted_provisioning_bundle.bin
    DEPENDS $<TARGET_FILE_DIR:provisioning_bundle>/provisioning_bundle.axf
    DEPENDS provisioning_bundle
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/create_provisioning_bundle.py
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/create_provisioning_bundle.py
                    --provisioning_bundle_axf ${CMAKE_BINARY_DIR}/bin/provisioning_bundle.axf
                    --bundle_output_file encrypted_provisioning_bundle.bin
                    --code_pad_size ${PROVISIONING_CODE_PADDED_SIZE}
                    --data_pad_size ${PROVISIONING_DATA_PADDED_SIZE}
                    --values_pad_size ${PROVISIONING_VALUES_PADDED_SIZE}
                    --magic "0xC0DEFEED"
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/encrypted_provisioning_bundle.bin ${CMAKE_BINARY_DIR}/bin/encrypted_provisioning_bundle.bin
)

target_sources(platform_s
    PRIVATE
        ./runtime_stub_provisioning.c
)

target_sources(platform_bl2
    PRIVATE
        ./bl2_provisioning.c
)

target_include_directories(platform_bl2
    INTERFACE
        .
)

add_custom_target(provisioning_data
    SOURCES
        provisioning_data.c
)

add_custom_command(OUTPUT provisioning_data.c
    DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,${MCUBOOT_KEY_S}>
    DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,${MCUBOOT_KEY_NS}>
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/provisioning_data_template.jinja2
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/create_provisioning_data.py
    WORKING_DIRECTORY ${MCUBOOT_PATH}/scripts
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/create_provisioning_data.py
        ${CMAKE_CURRENT_BINARY_DIR}/provisioning_data.c
        --bl2_rot_priv_key_0=${MCUBOOT_KEY_S}
        --bl2_rot_priv_key_1=${MCUBOOT_KEY_NS}
        --template_path=${CMAKE_CURRENT_SOURCE_DIR}
        --secure_debug_pk=${SECURE_DEBUG_PK}
        --huk=${HUK}
        --iak=${IAK}
        --boot_seed=${BOOT_SEED}
        --implementation_id=${IMPLEMENTATION_ID}
        --certification_reference=${CERTIFICATION_REFERENCE}
        --verification_service_url=${VERIFICATION_SERVICE_URL}
        --entropy_seed=${ENTROPY_SEED}

)
