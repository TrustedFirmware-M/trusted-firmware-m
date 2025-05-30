#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

find_package(Python3)

set (ENV{PYTHONPATH} ${CMAKE_SOURCE_DIR}/tools/modules)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/config)

add_custom_target(provisioning_tooling_message_config
    ALL
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
)

add_custom_target(provisioning_tooling_provisioning_config
    ALL
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/modules/provisioning_message_config.py
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../rse_otp_layout.h
    DEPENDS ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}/rse_provisioning_config.h
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/modules/provisioning_message_config.py
        --rse_provisioning_message_h_file=${CMAKE_CURRENT_SOURCE_DIR}/../rse_provisioning_message.h
        --compile_commands_file=${CMAKE_BINARY_DIR}/compile_commands.json
        --provisioning_message_config_output_file=${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/modules/provisioning_config.py
    DEPENDS ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}/rse_provisioning_config.h
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/modules/provisioning_config.py
        --rse_provisioning_layout_h_file=${CMAKE_CURRENT_SOURCE_DIR}/../rse_provisioning_values.h
        --rse_rotpk_policy_h_file=${CMAKE_CURRENT_SOURCE_DIR}/../../rse_rotpk_policy.h
        --compile_commands_file=${CMAKE_BINARY_DIR}/compile_commands.json
        --provisioning_config_output_file=${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
)

install(FILES       ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/provisioning/config)

install(FILES       ${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/provisioning/config)

macro(create_provisioning_code_target target)
    add_executable(${target}_provisioning_code)

    set_target_properties(${target}_provisioning_code
        PROPERTIES
            SUFFIX ".axf"
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
    )

    target_link_options(${target}_provisioning_code
        PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/bin/${target}_provisioning_code.map>
            $<$<C_COMPILER_ID:ARMClang>:--map>
            $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_CURRENT_BINARY_DIR}/bin/${target}_provisioning_code.map>
    )

    target_sources(${target}_provisioning_code
        PRIVATE
            $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
    )

    target_include_directories(${target}_provisioning_code
        PRIVATE
            ..
    )

    target_link_libraries(${target}_provisioning_code
        PRIVATE
            platform_bl1_1_interface
            bl1_1_shared_lib_interface
    )

    add_dependencies(${target}_provisioning_code
        bl1_1
    )

    # The provisioning code should link the ROM lib from ROM, not from SRAM. This
    # variable set only applies in this file scope
    set(CODE_SHARING_INPUT_FILE_SUFFIX ${CODE_SHARING_OUTPUT_FILE_SUFFIX})
    target_link_shared_code(${target}_provisioning_code
        bl1_1
    )
endmacro()

macro(add_default_provisioning_code_link_options target)
    target_add_scatter_file(${target}_provisioning_code
        $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/provisioning_code.sct>
        $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/provisioning_code.ld>
    )

    target_link_options(${target}_provisioning_code
        PRIVATE
            --entry=do_provision
    )
endmacro()

create_provisioning_code_target(cm)
add_default_provisioning_code_link_options(cm)

create_provisioning_code_target(dm)
add_default_provisioning_code_link_options(dm)

create_provisioning_code_target(combined)
add_default_provisioning_code_link_options(combined)

target_sources(cm_provisioning_code
    PRIVATE
        ./cm_provisioning_code.c
)

target_sources(dm_provisioning_code
    PRIVATE
        ./dm_provisioning_code.c
)

target_compile_definitions(combined_provisioning_code
    PRIVATE
        RSE_COMBINED_PROVISIONING_BUNDLES
)

target_sources(combined_provisioning_code
    PRIVATE
        ./combined_provisioning_code.c
        ./cm_provisioning_code.c
        ./dm_provisioning_code.c
)

if (RSE_NON_ENDORSED_DM_PROVISIONING)
    create_provisioning_code_target(plain_data_handler)
    add_default_provisioning_code_link_options(plain_data_handler)

    target_sources(plain_data_handler_provisioning_code
        PRIVATE
            ./plain_data_handler_provisioning_code.c
            ./../rse_provisioning_plain_data_handler.c
            ./../../rse_rotpk_revocation.c
    )
endif()

if (RSE_DM_CHAINED_PROVISIONING)
    create_provisioning_code_target(dm_chained)

    target_add_scatter_file(dm_chained_provisioning_code
        $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/dm_chained_provisioning_code.sct>
        $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/dm_chained_provisioning_code.ld>
    )

    target_link_options(dm_chained_provisioning_code
        PRIVATE
            --entry=do_jump
    )

    target_sources(dm_chained_provisioning_code
        PRIVATE
            ./dm_chained_provisioning_code.c
            ./../rse_provisioning_tci_key.c
    )
endif()

if (TFM_DUMMY_PROVISIONING)

    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin/provisioning)

    STRING(REGEX REPLACE "-.*$" "" MCUBOOT_ROTPK_TYPE ${MCUBOOT_SIGNATURE_TYPE})
    STRING(REGEX REPLACE "EC" "ECDSA" MCUBOOT_ROTPK_TYPE ${MCUBOOT_ROTPK_TYPE})

    set(CM_BUNDLE_SCRIPT_ARGS
            --non_secret_cm:bl1_2.bl1_2=${CMAKE_BINARY_DIR}/bin/bl1_2_padded.bin
            --non_secret_cm:bl1_2.bl1_2_hash=${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin
            --secret_cm:guk=${TFM_GUK_PATH}
            --non_secret_cm:otp_dma_ics=${CMAKE_BINARY_DIR}/bin/otp_dma_ics.bin
            $<$<BOOL:${TFM_BL1_2_IMAGE_ENCRYPTION}>:--secret_cm:kce_cm=${TFM_BL2_ENCRYPTION_KEY_PATH}>

            # Set config flags to 1 << 0x4
            $<$<BOOL:${RSE_NON_ENDORSED_DM_PROVISIONING}>:--non_secret_cm:cm.config_flags=16>

            --non_secret_cm:cm.rotpk_areas_0.rotpk_0=${TFM_BL1_2_CM_SIGNING_KEY_PATH}
            --non_secret_cm:cm.rotpk_areas_0.rotpk_policy_0 RSE_ROTPK_POLICY_SIG_REQUIRED
            --non_secret_cm:cm.rotpk_areas_0.rotpk_type_0 RSE_ROTPK_TYPE_${TFM_BL1_2_CM_SIGNING_ALG}
            --non_secret_cm:cm.rotpk_areas_0.rotpk_hash_alg_0 RSE_ROTPK_HASH_ALG_${TFM_BL1_2_ROTPK_HASH_ALG}

            --non_secret_cm:cm.rotpk_areas_0.rotpk_1=${MCUBOOT_KEY_S}
            --non_secret_cm:cm.rotpk_areas_0.rotpk_policy_1 RSE_ROTPK_POLICY_SIG_REQUIRED
            --non_secret_cm:cm.rotpk_areas_0.rotpk_type_1 RSE_ROTPK_TYPE_${MCUBOOT_ROTPK_TYPE}
            --non_secret_cm:cm.rotpk_areas_0.rotpk_hash_alg_1 RSE_ROTPK_HASH_ALG_${MCUBOOT_ROTPK_HASH_ALG}
            --valid_lcs=RSE_PROVISIONING_BLOB_VALID_IN_CM_LCS
    )

    if (${RSE_PROVISIONING_DM_SIGNATURE_CONFIG} STREQUAL "ROTPK_NOT_IN_ROM" OR RSE_NON_ENDORSED_DM_PROVISIONING)
        set(CM_BUNDLE_SCRIPT_ARGS
                ${CM_BUNDLE_SCRIPT_ARGS}
                --non_secret_cm:cm.rotpk_areas_0.rotpk_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}=${RSE_CM_PROVISIONING_SIGNING_KEY}
                --non_secret_cm:cm.rotpk_areas_0.rotpk_policy_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX} RSE_ROTPK_POLICY_SIG_REQUIRED
                --non_secret_cm:cm.rotpk_areas_0.rotpk_type_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX} RSE_ROTPK_TYPE_${RSE_PROVISIONING_SIGN_ALG}
                --non_secret_cm:cm.rotpk_areas_0.rotpk_hash_alg_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX} RSE_ROTPK_HASH_ALG_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG}
        )
    endif()

    set(DM_BUNDLE_SCRIPT_ARGS
            $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_0=${TFM_BL1_2_DM_SIGNING_KEY_PATH}>
            $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_policy_0=RSE_ROTPK_POLICY_SIG_OPTIONAL>
            $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_type_0=RSE_ROTPK_TYPE_${TFM_BL1_2_DM_SIGNING_ALG}>
            $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_hash_alg_0=RSE_ROTPK_HASH_ALG_${TFM_BL1_2_ROTPK_HASH_ALG}>

            --non_secret_dm:dm.rotpk_areas_0.rotpk_1=${MCUBOOT_KEY_NS}
            --non_secret_dm:dm.rotpk_areas_0.rotpk_policy_1 RSE_ROTPK_POLICY_SIG_REQUIRED
            --non_secret_dm:dm.rotpk_areas_0.rotpk_type_1 RSE_ROTPK_TYPE_${MCUBOOT_ROTPK_TYPE}
            --non_secret_dm:dm.rotpk_areas_0.rotpk_hash_alg_1 RSE_ROTPK_HASH_ALG_${MCUBOOT_ROTPK_HASH_ALG}
            --valid_lcs=RSE_PROVISIONING_BLOB_VALID_IN_DM_LCS
    )

    add_custom_target(cm_provisioning_message
        ALL
        SOURCES ${CMAKE_BINARY_DIR}/bin/provisioning/cm_provisioning_message.bin
    )

    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/bin/provisioning/cm_provisioning_message.bin
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_cm_provisioning_bundle.py
        DEPENDS otp_config
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/bin/cm_provisioning_code.axf
        DEPENDS ${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin
        DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin
        DEPENDS cm_provisioning_code
        DEPENDS cm_provisioning_key
        DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin
        DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded.bin
        DEPENDS bl1_2_padded_bin
        DEPENDS ${CMAKE_BINARY_DIR}/bin/otp_dma_ics.bin
        DEPENDS dma_icses
        DEPENDS ${TFM_BL2_ENCRYPTION_KEY_PATH}
        COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_cm_provisioning_bundle.py
            --otp_config=${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
            --provisioning_message_config=${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
            --provisioning_config=${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
            --provisioning_code_elf=${CMAKE_CURRENT_BINARY_DIR}/bin/cm_provisioning_code.axf
            --bundle_output_file ${CMAKE_BINARY_DIR}/bin/provisioning/cm_provisioning_message.bin

            --tp_mode=RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_${RSE_TP_MODE}
            --version=${RSE_CM_BLOB_VERSION}

            $<$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>:--sign_and_encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin>
            $<$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>:--sign_and_encrypt_alg=${RSE_PROVISIONING_SIGN_ALG}>
            --signature_config=RSE_PROVISIONING_BLOB_SIGNATURE_${RSE_PROVISIONING_CM_SIGNATURE_CONFIG}

            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_key=${RSE_CM_PROVISIONING_SIGNING_KEY}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_alg=${RSE_PROVISIONING_SIGN_ALG}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_hash_alg=${RSE_PROVISIONING_HASH_ALG}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--encrypt_alg=${RSE_PROVISIONING_ENCRYPTION_ALG}>

            $<$<BOOL:${RSE_PROVISIONING_CM_ENCRYPT_CODE_DATA}>:--encrypt_code_and_data=RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES>
            $<$<BOOL:${RSE_PROVISIONING_CM_ENCRYPT_SECRET_VALUES}>:--encrypt_secret_values=RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES>

            --sp_mode RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_ENABLED

            ${CM_BUNDLE_SCRIPT_ARGS}
    )

    add_custom_target(dm_provisioning_message
        ALL
        SOURCES ${CMAKE_BINARY_DIR}/bin/provisioning/dm_provisioning_message.bin
    )

    if (RSE_DM_CHAINED_PROVISIONING)
        set(MAIN_DM_BUNDLE_SIGNATURE_CONFIG ROTPK_NOT_IN_ROM)
        set(MAIN_DM_BUNDLE_NOT_IN_ROM_SIGNATURE_CONFIG PREVIOUS_BLOB)
    else()
        set(MAIN_DM_BUNDLE_SIGNATURE_CONFIG ${RSE_PROVISIONING_DM_SIGNATURE_CONFIG})
        if (MAIN_DM_BUNDLE_SIGNATURE_CONFIG STREQUAL "ROTPK_NOT_IN_ROM")
            set(MAIN_DM_BUNDLE_NOT_IN_ROM_SIGNATURE_CONFIG CM_ROTPK)
        endif()
    endif()

    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/bin/provisioning/dm_provisioning_message.bin
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_dm_provisioning_bundle.py
        DEPENDS otp_config
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/bin/dm_provisioning_code.axf
        DEPENDS ${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin
        DEPENDS dm_provisioning_code
        DEPENDS dm_provisioning_key
        COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_dm_provisioning_bundle.py
            --otp_config=${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
            --provisioning_message_config=${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
            --provisioning_config=${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
            --provisioning_code_elf=${CMAKE_CURRENT_BINARY_DIR}/bin/dm_provisioning_code.axf
            --bundle_output_file ${CMAKE_BINARY_DIR}/bin/provisioning/dm_provisioning_message.bin

            --tp_mode=RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_${RSE_TP_MODE}
            --version=${RSE_CM_BLOB_VERSION}

            $<$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>:--sign_and_encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin>
            $<$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>:--sign_and_encrypt_alg=${RSE_PROVISIONING_SIGN_ALG}>
            --signature_config=RSE_PROVISIONING_BLOB_SIGNATURE_${MAIN_DM_BUNDLE_SIGNATURE_CONFIG}
            $<$<STREQUAL:${MAIN_DM_BUNDLE_NOT_IN_ROM_SIGNATURE_CONFIG},PREVIOUS_BLOB>:--non_rom_pk_config=RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_PREVIOUS_BLOB>

            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_key=${RSE_CM_PROVISIONING_SIGNING_KEY}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_alg=${RSE_PROVISIONING_SIGN_ALG}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_hash_alg=${RSE_PROVISIONING_HASH_ALG}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--encrypt_alg=${RSE_PROVISIONING_ENCRYPTION_ALG}>
            $<$<STREQUAL:${MAIN_DM_BUNDLE_NOT_IN_ROM_SIGNATURE_CONFIG},CM_ROTPK>:--sign_key_cm_rotpk=${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}>

            $<$<BOOL:${RSE_PROVISIONING_DM_ENCRYPT_CODE_DATA}>:--encrypt_code_and_data=RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES>
            $<$<BOOL:${RSE_PROVISIONING_DM_ENCRYPT_SECRET_VALUES}>:--encrypt_secret_values=RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES>

            --sp_mode RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_ENABLED

            ${DM_BUNDLE_SCRIPT_ARGS}
    )

    if (RSE_DM_CHAINED_PROVISIONING)
            add_custom_target(dm_chained_provisioning_message
                ALL
                SOURCES ${CMAKE_BINARY_DIR}/bin/provisioning/dm_chained_provisioning_message.bin
            )

            add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/bin/provisioning/dm_chained_provisioning_message.bin
                DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_dm_chained_provisioning_bundle.py
                DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
                DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/bin/dm_chained_provisioning_code.axf
                DEPENDS ${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin
                DEPENDS dm_chained_provisioning_code
                DEPENDS dm_provisioning_key
                COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
                    ${Python3_EXECUTABLE}
                    ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_dm_chained_provisioning_bundle.py
                    --provisioning_message_config=${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
                    --provisioning_code_elf=${CMAKE_CURRENT_BINARY_DIR}/bin/dm_chained_provisioning_code.axf
                    --bundle_output_file ${CMAKE_BINARY_DIR}/bin/provisioning/dm_chained_provisioning_message.bin

                    --tp_mode=RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_${RSE_TP_MODE}
                    --version=${RSE_CM_BLOB_VERSION}

                    --signature_config=RSE_PROVISIONING_BLOB_SIGNATURE_${RSE_PROVISIONING_DM_SIGNATURE_CONFIG}

                    --sign_key=${RSE_CM_PROVISIONING_SIGNING_KEY}
                    --sign_alg=${RSE_PROVISIONING_SIGN_ALG}
                    --sign_hash_alg=${RSE_PROVISIONING_HASH_ALG}
                    --encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin
                    --encrypt_alg=${RSE_PROVISIONING_ENCRYPTION_ALG}
                    $<$<STREQUAL:${RSE_PROVISIONING_DM_SIGNATURE_CONFIG},ROTPK_NOT_IN_ROM>:--sign_key_cm_rotpk=${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}>

                    $<$<BOOL:${RSE_PROVISIONING_DM_ENCRYPT_CODE_DATA}>:--encrypt_code_and_data=RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES>
                    # No secret values in chained blob to encrypt
                    --encrypt_secret_values=RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_BY_BLOB

                    --sp_mode RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_ENABLED

                    --valid_lcs=RSE_PROVISIONING_BLOB_VALID_IN_DM_LCS
            )
    endif()

    add_custom_target(combined_provisioning_message
        ALL
        SOURCES ${CMAKE_BINARY_DIR}/bin/provisioning/combined_provisioning_message.bin
    )

    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/bin/provisioning/combined_provisioning_message.bin
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_combined_provisioning_bundle.py
        DEPENDS otp_config
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/bin/combined_provisioning_code.axf
        DEPENDS ${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin
        DEPENDS combined_provisioning_code
        DEPENDS cm_provisioning_key
        DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin
        DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded.bin
        DEPENDS bl1_2_padded_bin
        DEPENDS ${CMAKE_BINARY_DIR}/bin/otp_dma_ics.bin
        DEPENDS dma_icses
        COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_combined_provisioning_bundle.py
            --otp_config=${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
            --provisioning_message_config=${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
            --provisioning_config=${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
            --provisioning_code_elf=${CMAKE_CURRENT_BINARY_DIR}/bin/combined_provisioning_code.axf
            --bundle_output_file ${CMAKE_BINARY_DIR}/bin/provisioning/combined_provisioning_message.bin

            --tp_mode=RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_${RSE_TP_MODE}
            --version=${RSE_CM_BLOB_VERSION}

            $<$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>:--sign_and_encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin>
            $<$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>:--sign_and_encrypt_alg=${RSE_PROVISIONING_SIGN_ALG}>
            --signature_config=RSE_PROVISIONING_BLOB_SIGNATURE_${RSE_PROVISIONING_DM_SIGNATURE_CONFIG}

            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_key=${RSE_CM_PROVISIONING_SIGNING_KEY}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_alg=${RSE_PROVISIONING_SIGN_ALG}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--sign_hash_alg=${RSE_PROVISIONING_HASH_ALG}>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin>
            $<$<NOT:$<BOOL:${RSE_SYMMETRIC_PROVISIONING}>>:--encrypt_alg=${RSE_PROVISIONING_ENCRYPTION_ALG}>
            $<$<STREQUAL:${RSE_PROVISIONING_DM_SIGNATURE_CONFIG},ROTPK_NOT_IN_ROM>:--sign_key_cm_rotpk=${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}>

            $<$<BOOL:${RSE_PROVISIONING_CM_ENCRYPT_CODE_DATA}>:--encrypt_code_and_data=RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_AES>
            $<$<BOOL:${RSE_PROVISIONING_CM_ENCRYPT_SECRET_VALUES}>:--encrypt_secret_values=RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_AES>

            --sp_mode RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_ENABLED

            ${CM_BUNDLE_SCRIPT_ARGS}
            ${DM_BUNDLE_SCRIPT_ARGS}
    )

    if (RSE_NON_ENDORSED_DM_PROVISIONING)
        add_custom_target(plain_data_handler_provisioning_message
            ALL
            SOURCES ${CMAKE_BINARY_DIR}/bin/provisioning/plain_data_handler_provisioning_message.bin
        )

        add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/bin/provisioning/plain_data_handler_provisioning_message.bin
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_plain_data_handler_provisioning_bundle.py
            DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
            DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/bin/plain_data_handler_provisioning_code.axf
            DEPENDS plain_data_handler_provisioning_code
            COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
                ${Python3_EXECUTABLE}
                ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_plain_data_handler_provisioning_bundle.py
                --provisioning_message_config=${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
                --provisioning_code_elf=${CMAKE_CURRENT_BINARY_DIR}/bin/plain_data_handler_provisioning_code.axf
                --bundle_output_file ${CMAKE_BINARY_DIR}/bin/provisioning/plain_data_handler_provisioning_message.bin

                --tp_mode=RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_${RSE_TP_MODE}
                --version=${RSE_CM_BLOB_VERSION}

                --signature_config=RSE_PROVISIONING_BLOB_SIGNATURE_ROTPK_NOT_IN_ROM

                --sign_key=${RSE_CM_PROVISIONING_SIGNING_KEY}
                --sign_alg=${RSE_PROVISIONING_SIGN_ALG}
                --sign_hash_alg=${RSE_PROVISIONING_HASH_ALG}
                --sign_key_cm_rotpk=${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}
                --encrypt_key=${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin
                --encrypt_alg=${RSE_PROVISIONING_ENCRYPTION_ALG}

                # No secret encryption
                --encrypt_secret_values=RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_BY_BLOB

                --sp_mode RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_DISABLED

                --valid_lcs=RSE_PROVISIONING_BLOB_VALID_IN_SE_LCS
        )
    endif()
endif()
