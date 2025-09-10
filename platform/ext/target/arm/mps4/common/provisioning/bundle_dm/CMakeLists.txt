#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

find_package(Python3)

add_executable(dm_provisioning_bundle)

if(${TFM_DUMMY_PROVISIONING})
    include(${CMAKE_SOURCE_DIR}/platform/ext/target/arm/mps4/common/provisioning/bundle_dm/dm_provisioning_config.cmake)
else()
    include("${DM_PROVISIONING_KEYS_CONFIG}" OPTIONAL RESULT_VARIABLE DM_PROVISIONING_KEYS_CONFIG_PATH)
    if(NOT DM_PROVISIONING_KEYS_CONFIG_PATH)
        message(WARNING "The DM_PROVISIONING_KEYS_CONFIG is not set. If the keys are not passed via the command line then \
                        random/dummy numbers will be used for keys and seeds or default values will be used (for attestation). \
                        To create and use a DM_PROVISIONING_KEYS_CONFIG file, \
                        see the example in: \
                        tf-m/platform/ext/target/arm/mps4/common/provisioning/bundle_dm/dm_provisioning_config.cmake")
    endif()
    # mps4 only supports LMS, so only the relevant dummy key is checked
    if(TFM_BL1_2_CM_SIGNING_KEY_PATH STREQUAL "${CMAKE_SOURCE_DIR}/bl1/bl1_2/bl1_dummy_rotpk.pub")
        message(WARNING "TFM_DUMMY_PROVISIONING is OFF but TFM_BL1_2_CM_SIGNING_KEY_PATH is set to the dummy signing key.")
    endif()
    if(TFM_BL2_ENCRYPTION_KEY_PATH STREQUAL ${CMAKE_SOURCE_DIR}/bl1/bl1_2/bl2_dummy_encryption_key.bin)
        message(WARNING "TFM_DUMMY_PROVISIONING is OFF but TFM_BL2_ENCRYPTION_KEY_PATH is set to the dummy encryption key.")
    endif()
endif()

set_target_properties(dm_provisioning_bundle
    PROPERTIES
        SUFFIX ".axf"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_add_scatter_file(dm_provisioning_bundle
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.icf>
    $<$<C_COMPILER_ID:Clang>:${CMAKE_CURRENT_SOURCE_DIR}/../bundle_common/provisioning_bundle.ldc>
)

target_link_options(dm_provisioning_bundle
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/dm_provisioning_bundle.map>
        $<$<C_COMPILER_ID:ARMClang>:--map>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/dm_provisioning_bundle.map>
        $<$<C_COMPILER_ID:Clang>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/dm_provisioning_bundle.map>
)

target_link_options(dm_provisioning_bundle
    PRIVATE
        $<$<C_COMPILER_ID:ARMClang,IAR>:LINKER:--entry=do_provision>
)

target_compile_options(dm_provisioning_bundle
    PUBLIC
        ${BL1_COMPILER_CP_FLAG}
        ${COMPILER_CMSE_FLAG}
)

target_link_options(dm_provisioning_bundle
    PUBLIC
        ${BL1_LINKER_CP_OPTION}
)

target_sources(dm_provisioning_bundle
    PRIVATE
        dm_provisioning_code.c
        dm_provisioning_data.c
        $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
)

target_include_directories(dm_provisioning_bundle
    PRIVATE
        ../bundle_common
        ../../native_drivers
)

target_link_libraries(dm_provisioning_bundle
    PRIVATE
        platform_bl1_1_interface
        bl1_1_shared_lib_interface
)

target_link_shared_code(dm_provisioning_bundle
    bl1_1
)

add_custom_target(dm_provisioning_bundle_bin
    ALL
    SOURCES dm_provisioning_bundle.bin
)

add_custom_target(dm_provisioning_data
    SOURCES
        dm_provisioning_data.c
)

add_custom_command(OUTPUT dm_provisioning_data.c
    DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,${MCUBOOT_KEY_S}>
    DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,${MCUBOOT_KEY_NS}>
    DEPENDS $<IF:$<BOOL:${TFM_GENERATE_BL1_2_CM_SIGNING_KEY}>,bl1_generated_cm_signing_key,${TFM_BL1_2_CM_SIGNING_KEY_PATH}>
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/dm_provisioning_data_template.jinja2
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/dm_create_provisioning_data.py
    WORKING_DIRECTORY ${MCUBOOT_PATH}/scripts
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/dm_create_provisioning_data.py
        ${CMAKE_CURRENT_BINARY_DIR}/dm_provisioning_data.c
        --template_path=${CMAKE_CURRENT_SOURCE_DIR}
        --bl1_rotpk_0_path=${TFM_BL1_2_CM_SIGNING_KEY_PATH} # this key is used when only a single key signs bl2
        --bl2_encryption_key_path=${TFM_BL2_ENCRYPTION_KEY_PATH}
        --bl2_mcuboot_hw_key=${MCUBOOT_HW_KEY}
        --bl2_rot_priv_key_0=${MCUBOOT_KEY_S}
        --bl2_rot_priv_key_1=${MCUBOOT_KEY_NS}
        --implementation_id=${IMPLEMENTATION_ID}
        --verification_service_url=${VERIFICATION_SERVICE_URL}
        --attestation_profile_definition=${ATTESTATION_PROFILE_DEFINITION}
        --secure_debug_pk=${SECURE_DEBUG_PK}
        --boot_seed=${BOOT_SEED}
        --certification_reference=${CERTIFICATION_REFERENCE}
        --entropy_seed=${ENTROPY_SEED}
)

set(bin_dir ${CMAKE_BINARY_DIR}/bin)

add_custom_command(OUTPUT dm_provisioning_bundle.bin
    OUTPUT ${bin_dir}/dm_provisioning_bundle.bin
    DEPENDS $<TARGET_FILE_DIR:dm_provisioning_bundle>/dm_provisioning_bundle.axf
    DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded_hash.bin
    DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded.bin
    bl1_2_padded_bin bl2_signed_bin dm_provisioning_bundle
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../create_provisioning_bundle.py
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../create_provisioning_bundle.py
                    --provisioning_bundle_axf $<TARGET_FILE_DIR:dm_provisioning_bundle>/dm_provisioning_bundle.axf
                    --bundle_output_file dm_provisioning_bundle.bin
                    --magic "0xBEEFFEED"
                    --tp_mode ${TP_MODE}
                    --key_file=${RTL_KEY_PATH}
                    --krtl_derivation_label="DM_PROVISIONING"
                    --provisioning_lcs 1
                    --code_pad_size ${PROVISIONING_CODE_PADDED_SIZE}
                    --data_pad_size ${PROVISIONING_DATA_PADDED_SIZE}
                    --values_pad_size ${PROVISIONING_VALUES_PADDED_SIZE}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/dm_provisioning_bundle.bin ${bin_dir}/dm_provisioning_bundle.bin
)

add_convert_to_offset_hex_target(dm_provisioning_bundle
        INPUT_FILE          ${bin_dir}/dm_provisioning_bundle.bin
        OFFSET_MACRO_NAME   DM_PROVISIONING_BUNDLE_START
        INCLUDE_BL2_HEADER  FALSE
        MIRROR_FILE         $<TARGET_PROPERTY:dm_provisioning_bundle,LINK_DEPENDS>
        OUTPUT_FILE         ${bin_dir}/dm_provisioning_bundle.hex
)
