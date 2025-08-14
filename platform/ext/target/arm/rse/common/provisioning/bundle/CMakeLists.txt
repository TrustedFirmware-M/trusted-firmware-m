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

function(create_provisioning_code_target target linker_script entry_point
        sources defs)
    set(TARGET_NAME ${target}_provisioning_code)

    add_executable(${TARGET_NAME})

    set_target_properties(${TARGET_NAME}
        PROPERTIES
            SUFFIX ".axf"
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
    )

    target_link_options(${TARGET_NAME}
        PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/bin/${target}_provisioning_code.map>
            $<$<C_COMPILER_ID:ARMClang>:--map>
            $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_CURRENT_BINARY_DIR}/bin/${target}_provisioning_code.map>
    )

    target_sources(${TARGET_NAME}
        PRIVATE
            $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
    )

    target_include_directories(${TARGET_NAME}
        PRIVATE
            ..
    )

    target_link_libraries(${TARGET_NAME}
        PRIVATE
            platform_bl1_1_interface
            bl1_1_shared_lib_interface
    )

    add_dependencies(${TARGET_NAME}
        bl1_1
    )

    # The provisioning code should link the ROM lib from ROM, not from SRAM. This
    # variable set only applies in this file scope
    set(CODE_SHARING_INPUT_FILE_SUFFIX ${CODE_SHARING_OUTPUT_FILE_SUFFIX})
    target_link_shared_code(${TARGET_NAME}
        bl1_1
    )

    target_add_scatter_file(${TARGET_NAME}
        $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/${linker_script}.sct>
        $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/${linker_script}.ld>
    )

    target_link_options(${TARGET_NAME}
        PRIVATE
            --entry=${entry_point}
    )

    target_sources(${TARGET_NAME}
        PRIVATE
            ${sources}
    )

    target_compile_definitions(${TARGET_NAME}
        PRIVATE
            ${defs}
    )
endfunction()

function(generate_provisioning_bundle bundle_type script exe_target blob_version valid_lcses
         symmetric_provisioning signature_config sign_key encrypt_key non_rom_pk_config sign_key_cm_rotpk
         encrypt_code_data encrypt_secret_values
         additional_bundle_args additional_bundle_deps)
    set(GENERATED_FILE_NAME ${CMAKE_BINARY_DIR}/bin/provisioning/${bundle_type}_message.bin)
    set(ELF_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/bin/${exe_target}.axf)
    list(TRANSFORM valid_lcses PREPEND "--valid_lcs=RSE_PROVISIONING_BLOB_VALID_IN_")
    list(TRANSFORM valid_lcses APPEND "_LCS")

    set(CUSTOM_COMMAND_DEPENDENCIES
        ${script}
        ${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
        ${exe_target}
        ${ELF_FILE_NAME}
        ${encrypt_key}
        $<$<NOT:$<BOOL:${symmetric_provisioning}>>:${sign_key}>
        ${additional_bundle_deps}
    )

    set(CREATE_BUNDLE_SCRIPT_ARGS
        --provisioning_message_config=${CMAKE_CURRENT_BINARY_DIR}/config/message_config.pickle
        --provisioning_code_elf=${ELF_FILE_NAME}
        --bundle_output_file ${GENERATED_FILE_NAME}
        --tp_mode=RSE_PROVISIONING_BLOB_REQUIRES_TP_MODE_${RSE_TP_MODE}
        --version=${blob_version}
        --signature_config=RSE_PROVISIONING_BLOB_SIGNATURE_${signature_config}
        ${valid_lcses}
    )

    if (NOT "${additional_bundle_args}" STREQUAL "")
        set(CUSTOM_COMMAND_DEPENDENCIES
            ${CUSTOM_COMMAND_DEPENDENCIES}
            otp_config
            ${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
            ${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
        )

        set(CREATE_BUNDLE_SCRIPT_ARGS
            ${CREATE_BUNDLE_SCRIPT_ARGS}
            --otp_config=${CMAKE_CURRENT_BINARY_DIR}/../../config/otp_config.pickle
            --provisioning_config=${CMAKE_CURRENT_BINARY_DIR}/config/provisioning_config.pickle
        )
    endif()

    if (${signature_config} STREQUAL "ROTPK_NOT_IN_ROM")
        set(CREATE_BUNDLE_SCRIPT_ARGS
            ${CREATE_BUNDLE_SCRIPT_ARGS}
            --non_rom_pk_config=RSE_PROVISIONING_BLOB_DETAILS_NON_ROM_PK_TYPE_${non_rom_pk_config}
        )
        if (${non_rom_pk_config} STREQUAL "CM_ROTPK")
            set(CREATE_BUNDLE_SCRIPT_ARGS
                ${CREATE_BUNDLE_SCRIPT_ARGS}
                --sign_key_cm_rotpk=${sign_key_cm_rotpk}
            )
        endif()
    endif()

    if (${symmetric_provisioning})
        set(CREATE_BUNDLE_SCRIPT_ARGS
            ${CREATE_BUNDLE_SCRIPT_ARGS}
            --sign_and_encrypt_key=${encrypt_key}
            --sign_and_encrypt_alg=${RSE_PROVISIONING_SIGN_ALG}
        )
    else()
        set(CREATE_BUNDLE_SCRIPT_ARGS
            ${CREATE_BUNDLE_SCRIPT_ARGS}
            --sign_key=${sign_key}
            --sign_alg=${RSE_PROVISIONING_SIGN_ALG}
            --sign_hash_alg=${RSE_PROVISIONING_HASH_ALG}
            --encrypt_key=${encrypt_key}
            --encrypt_alg=${RSE_PROVISIONING_ENCRYPTION_ALG}
        )
    endif()

    if (${encrypt_code_data})
        set(CODE_DATA_ENCRYPT_ARG AES)
    else()
        set(CODE_DATA_ENCRYPT_ARG NONE)
    endif()

    if (${encrypt_secret_values})
        set(SECRET_VALUES_ENCRYPT_ARG AES)
    else()
        set(SECRET_VALUES_ENCRYPT_ARG BY_BLOB)
    endif()

    set(CREATE_BUNDLE_SCRIPT_ARGS
        ${CREATE_BUNDLE_SCRIPT_ARGS}
        --encrypt_code_and_data=RSE_PROVISIONING_BLOB_CODE_DATA_DECRYPTION_${CODE_DATA_ENCRYPT_ARG}
        --encrypt_secret_values=RSE_PROVISIONING_BLOB_SECRET_VALUES_DECRYPTION_${SECRET_VALUES_ENCRYPT_ARG}
        --sp_mode RSE_PROVISIONING_BLOB_REQUIRES_SP_MODE_ENABLED
        ${additional_bundle_args}
    )

    add_custom_target(${bundle_type}_message
        ALL
        SOURCES ${GENERATED_FILE_NAME}
    )

    add_custom_command(OUTPUT ${GENERATED_FILE_NAME}
        DEPENDS ${CUSTOM_COMMAND_DEPENDENCIES}
        COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${script}
            ${CREATE_BUNDLE_SCRIPT_ARGS}
    )
endfunction()


create_provisioning_code_target(cm
    provisioning_code # cmake target
    do_provision # entrypoint
    "./cm_provisioning_code.c" # sources
    "" # additional macros
)

create_provisioning_code_target(dm
    provisioning_code # cmake target
    do_provision # entrypoint
    "./dm_provisioning_code.c" # sources
    "" # additional macros
)

create_provisioning_code_target(combined
    provisioning_code # cmake target
    do_provision # entrypoint
    "./combined_provisioning_code.c;./cm_provisioning_code.c;./dm_provisioning_code.c" # sources
    "RSE_COMBINED_PROVISIONING_BUNDLES" # additional macros
)

if (RSE_NON_ENDORSED_DM_PROVISIONING OR RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
    set(PLAIN_DATA_HANDLER_SOURCES
            ./plain_data_handler_provisioning_code.c
            ./../rse_provisioning_plain_data_handler.c
            ./../../rse_rotpk_revocation.c
            ./../../rse_asn1_encoding.c
        )

    create_provisioning_code_target(plain_data_handler
        provisioning_code # cmake target
        do_provision # entrypoint
        "${PLAIN_DATA_HANDLER_SOURCES}" # sources
        "" # additional macros
    )
endif()

if (RSE_DM_CHAINED_PROVISIONING)
    create_provisioning_code_target(dm_chained
        dm_chained_provisioning_code # cmake target
        do_jump # entrypoint
        "./dm_chained_provisioning_code.c;./../rse_provisioning_tci_key.c" # sources
        "" # additional macros
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
        --secret_cm:kce_cm=${TFM_GUK_PATH}

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
    )

    if (${RSE_PROVISIONING_DM_SIGNATURE_CONFIG} STREQUAL "ROTPK_NOT_IN_ROM"
        OR RSE_NON_ENDORSED_DM_PROVISIONING OR RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
        set(CM_BUNDLE_SCRIPT_ARGS
            ${CM_BUNDLE_SCRIPT_ARGS}
            --non_secret_cm:cm.rotpk_areas_0.rotpk_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}=${RSE_CM_PROVISIONING_SIGNING_KEY}
            --non_secret_cm:cm.rotpk_areas_0.rotpk_policy_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX} RSE_ROTPK_POLICY_SIG_REQUIRED
            --non_secret_cm:cm.rotpk_areas_0.rotpk_type_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX} RSE_ROTPK_TYPE_${RSE_PROVISIONING_SIGN_ALG}
            --non_secret_cm:cm.rotpk_areas_0.rotpk_hash_alg_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX} RSE_ROTPK_HASH_ALG_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG}
        )
    endif()

    set(CM_BUNDLE_SCRIPT_DEPS
        bl1_2_padded_bin
        ${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin
        ${CMAKE_BINARY_DIR}/bin/bl1_2_padded.bin
        ${CMAKE_BINARY_DIR}/bin/otp_dma_ics.bin
        ${TFM_BL2_ENCRYPTION_KEY_PATH}
    )

    set(DM_BUNDLE_SCRIPT_DEPS
        $<$<BOOL:${RSE_OTP_HAS_ROUTING_TABLES}>:routing_tables_pickle>
        $<$<BOOL:${RSE_OTP_HAS_ROUTING_TABLES}>:${CMAKE_CURRENT_BINARY_DIR}/../../config/routing_tables.pickle>
    )

    set(DM_BUNDLE_SCRIPT_ARGS
        $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_0=${TFM_BL1_2_DM_SIGNING_KEY_PATH}>
        $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_policy_0=RSE_ROTPK_POLICY_SIG_OPTIONAL>
        $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_type_0=RSE_ROTPK_TYPE_${TFM_BL1_2_DM_SIGNING_ALG}>
        $<$<EQUAL:${TFM_BL1_2_SIGNER_AMOUNT},2>:--non_secret_dm:dm.rotpk_areas_0.rotpk_hash_alg_0=RSE_ROTPK_HASH_ALG_${TFM_BL1_2_ROTPK_HASH_ALG}>

        --non_secret_dm:dm.rotpk_areas_0.rotpk_1=${MCUBOOT_KEY_NS}
        --non_secret_dm:dm.rotpk_areas_0.rotpk_policy_1 RSE_ROTPK_POLICY_SIG_REQUIRED
        --non_secret_dm:dm.rotpk_areas_0.rotpk_type_1 RSE_ROTPK_TYPE_${MCUBOOT_ROTPK_TYPE}
        --non_secret_dm:dm.rotpk_areas_0.rotpk_hash_alg_1 RSE_ROTPK_HASH_ALG_${MCUBOOT_ROTPK_HASH_ALG}
        --secret_dm:kce_dm=${TFM_GUK_PATH}
        $<$<BOOL:${RSE_OTP_HAS_ROUTING_TABLES}>:--routing_tables=${CMAKE_CURRENT_BINARY_DIR}/../../config/routing_tables.pickle>
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

    if (NOT RSE_OTP_HAS_RSE_ID AND NOT RSE_OTP_HAS_ROUTING_TABLES)
        set(RSE_REQUIRES_UNIQUE_BUNDLES OFF)
        set(RSE_AMOUNT_LOOP_RANGE 0)
    else()
        set(RSE_REQUIRES_UNIQUE_BUNDLES ON)
        math(EXPR RSE_AMOUNT_LOOP_RANGE "${RSE_AMOUNT} - 1")
    endif()

    foreach(RSE_ID RANGE ${RSE_AMOUNT_LOOP_RANGE})
        if (RSE_REQUIRES_UNIQUE_BUNDLES)
            set(BUNDLE_SUFFIX "_${RSE_ID}")
        else()
            set(BUNDLE_SUFFIX "")
        endif()
        set(CM_BUNDLE_SCRIPT_ARGS_TEMP
            ${CM_BUNDLE_SCRIPT_ARGS}
            $<$<BOOL:${RSE_OTP_HAS_RSE_ID}>:--non_secret_cm:cm.rse_id=${RSE_ID}>
        )
        set(DM_BUNDLE_SCRIPT_ARGS_TEMP
            ${DM_BUNDLE_SCRIPT_ARGS}
            $<$<BOOL:${RSE_OTP_HAS_ROUTING_TABLES}>:--routing_tables_idx=${RSE_ID}>
        )

        generate_provisioning_bundle(
            "cm_provisioning${BUNDLE_SUFFIX}" # bundle type
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_cm_provisioning_bundle.py # script
            cm_provisioning_code # cmake executable target
            "${RSE_CM_BLOB_VERSION}" # blob version
            "CM" # valid LCS states
            "${RSE_SYMMETRIC_PROVISIONING}" # symmetric provisioning enabled
            "${RSE_PROVISIONING_CM_SIGNATURE_CONFIG}" # signature config
            "${RSE_CM_PROVISIONING_SIGNING_KEY}" # signature key (if asymmetric)
            ${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin # encryption key
            "" # PK not in ROM configuration (not for CM)
            "" # CM ROTPK index if PK not in ROM == CM_ROTPK (not for CM)
            "${RSE_PROVISIONING_CM_ENCRYPT_CODE_DATA}" # encrypt code and data
            ON # encrypt secret values
            "${CM_BUNDLE_SCRIPT_ARGS_TEMP}" # OTP values args
            "${CM_BUNDLE_SCRIPT_DEPS}" # script specific CMake dependencies
        )

        generate_provisioning_bundle(
            "dm_provisioning${BUNDLE_SUFFIX}" # bundle type
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_dm_provisioning_bundle.py # script
            dm_provisioning_code # cmake executable target
            "${RSE_DM_BLOB_VERSION}" # blob version
            "DM" # valid LCS states
            "${RSE_SYMMETRIC_PROVISIONING}" # symmetric provisioning enabled
            "${MAIN_DM_BUNDLE_SIGNATURE_CONFIG}" # signature config
            "${RSE_CM_PROVISIONING_SIGNING_KEY}" # signature key (if asymmetric)
            ${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin # encryption key
            "${MAIN_DM_BUNDLE_NOT_IN_ROM_SIGNATURE_CONFIG}" # PK not in ROM configuration
            "${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}" # CM ROTPK index if PK not in ROM == CM_ROTPK
            "${RSE_PROVISIONING_DM_ENCRYPT_CODE_DATA}" # encrypt code and data
            ON # encrypt secret values
            "${DM_BUNDLE_SCRIPT_ARGS_TEMP}" # OTP values args
            "" # No additional dependencies
        )

        generate_provisioning_bundle(
            "combined_provisioning${BUNDLE_SUFFIX}" # bundle type
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_combined_provisioning_bundle.py # script
            combined_provisioning_code # cmake executable target
            "${RSE_CM_BLOB_VERSION}" # blob version
            "CM;DM" # valid LCS states
            "${RSE_SYMMETRIC_PROVISIONING}" # symmetric provisioning enabled
            "${RSE_PROVISIONING_DM_SIGNATURE_CONFIG}" # signature config
            "${RSE_CM_PROVISIONING_SIGNING_KEY}" # signature key (if asymmetric)
            ${CMAKE_BINARY_DIR}/bin/keys/kprov_cm.bin # encryption key
            "CM_ROTPK" # PK not in ROM configuration
            "${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}" # CM ROTPK index if PK not in ROM == CM_ROTPK
            "${RSE_PROVISIONING_CM_ENCRYPT_CODE_DATA}" # encrypt code and data
            ON # encrypt secret values
            "${CM_BUNDLE_SCRIPT_ARGS_TEMP};${DM_BUNDLE_SCRIPT_ARGS_TEMP}" # OTP values args
            "${CM_BUNDLE_SCRIPT_DEPS}" # script specific CMake dependencies
    )
    endforeach()

    if (RSE_DM_CHAINED_PROVISIONING)
        generate_provisioning_bundle(
            dm_chained_provisioning # bundle type
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_dm_chained_provisioning_bundle.py # script
            dm_chained_provisioning_code # cmake executable target
            "${RSE_DM_BLOB_VERSION}" # blob version
            "DM" # valid LCS states
            "${RSE_SYMMETRIC_PROVISIONING}" # symmetric provisioning enabled
            "${RSE_PROVISIONING_DM_SIGNATURE_CONFIG}" # signature config
            "${RSE_CM_PROVISIONING_SIGNING_KEY}" # signature key (if asymmetric)
            ${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin # encryption key
            "CM_ROTPK" # PK not in ROM configuration
            "${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}" # CM ROTPK index if PK not in ROM == CM_ROTPK
            "${RSE_PROVISIONING_DM_ENCRYPT_CODE_DATA}" # encrypt code and data
            OFF  # No secret values in chained blob to encrypt
            "" # No provisioning values
            "" # No additional dependencies
        )
    endif()

    if (RSE_NON_ENDORSED_DM_PROVISIONING OR RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
        set(VALID_LCS_STATES)
        list(APPEND VALID_LCS_STATES SE)
        if (RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
            list(APPEND VALID_LCS_STATES DM)
        endif()

        generate_provisioning_bundle(
            plain_data_handler_provisioning # bundle type
            ${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/create_plain_data_handler_provisioning_bundle.py # script
            plain_data_handler_provisioning_code # cmake executable target
            "${RSE_CM_BLOB_VERSION}" # blob version
            "${VALID_LCS_STATES}" # valid LCS states
            OFF # symmetric provisioning enabled
            "ROTPK_NOT_IN_ROM" # signature config
            "${RSE_CM_PROVISIONING_SIGNING_KEY}" # signature key (if asymmetric)
            ${CMAKE_BINARY_DIR}/bin/keys/kprov_dm.bin # encryption key
            "CM_ROTPK" # PK not in ROM configuration
            "${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_IDX}" # CM ROTPK index if PK not in ROM == CM_ROTPK
            OFF # encrypt code and data
            OFF # No secret values in blob to ecrypt
            "" # No provisioning values
            "" # No additional dependencies
        )
    endif()
endif()
