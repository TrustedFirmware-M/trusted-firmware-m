#------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

include(hex_generator)

fetch_remote_library(
    LIB_NAME                mcuboot
    LIB_SOURCE_PATH_VAR     MCUBOOT_PATH
    LIB_PATCH_DIR           ${CMAKE_SOURCE_DIR}/lib/ext/mcuboot
    LIB_FORCE_PATCH         ${MCUBOOT_FORCE_PATCH}
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://github.com/mcu-tools/mcuboot.git
        GIT_TAG             ${MCUBOOT_VERSION}
        GIT_PROGRESS        TRUE
        GIT_SUBMODULES      "${MCUBOOT_SUBMODULES}"
)

add_library(mcuboot_config INTERFACE)

if (MCUBOOT_ENCRYPT_KW)
    set(MCUBOOT_KEY_ENC "${MCUBOOT_PATH}/enc-aeskw-128.b64" CACHE FILEPATH "Path to key with which to encrypt Secure firmware")
    set(MCUBOOT_KEY_ENC_NS "${MCUBOOT_PATH}/enc-aeskw-128_ns.b64" CACHE FILEPATH "Path to key with which to encrypt non secure firmware")
else()
    set(MCUBOOT_KEY_ENC "${MCUBOOT_PATH}/enc-rsa2048-pub.pem" CACHE FILEPATH "Path to key with which to encrypt binary")
    set(MCUBOOT_KEY_ENC_NS "${MCUBOOT_PATH}/enc-rsa2048-pub.pem" CACHE FILEPATH "Path to key with which to encrypt non secure firmware")
endif()

# Add/process CBOR encoded measured boot data (MCUBOOT_MEASURED_BOOT) only if
# the store encoded measurements config is enabled. Otherwise, unencoded
# measurements are stored in the shared data area and must be processed at
# runtime.
if (CONFIG_TFM_BOOT_STORE_MEASUREMENTS AND CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS)
    set(MCUBOOT_MEASURED_BOOT ON)
endif()

add_subdirectory("${MCUBOOT_PATH}/boot/bootutil" bootutil)

target_include_directories(bootutil
    PUBLIC
        include
        config
)

target_link_libraries(bootutil
    PUBLIC
        mcuboot_config
        platform_bl2
        bl2_crypto
)

target_compile_options(bootutil
    PRIVATE
        ${BL2_COMPILER_CP_FLAG}
)

target_compile_definitions(bootutil
    PRIVATE
        $<$<BOOL:${DEFAULT_MCUBOOT_FLASH_MAP}>:DEFAULT_MCUBOOT_FLASH_MAP>
)

target_include_directories(mcuboot_config
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for mcuboot_config.h only
)

target_include_directories(bl2
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set(BL2_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/bl2_main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/flash_map_extended.c
    ${CMAKE_CURRENT_SOURCE_DIR}/flash_map_legacy.c
)

if(PLATFORM_DEFAULT_IMAGE_ENCRYPTION)
list(APPEND BL2_SOURCES $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:${CMAKE_CURRENT_SOURCE_DIR}/keys_enc.c>)
endif()

if(PLATFORM_DEFAULT_ROTPK)
    if(MCUBOOT_BUILTIN_KEY)
        list(APPEND BL2_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/keys_builtin.c)
    elseif(MCUBOOT_HW_KEY)
        list(APPEND BL2_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/keys_hw.c)
    else()
        list(APPEND BL2_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/keys.c)
    endif()
endif()

target_sources(bl2 PRIVATE ${BL2_SOURCES})

target_compile_definitions(bl2
    PRIVATE
        MCUBOOT_SIGNATURE_TYPE=${MCUBOOT_SIGNATURE_TYPE}
        $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:TFM_S_KEY_ID=${TFM_S_KEY_ID}>
        $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:TFM_NS_KEY_ID=${TFM_NS_KEY_ID}>
        MCUBOOT_ROTPK_MAX_KEYS_PER_IMAGE=${MCUBOOT_ROTPK_MAX_KEYS_PER_IMAGE}
        $<$<BOOL:${MCUBOOT_IMAGE_MULTI_SIG_SUPPORT}>:MCUBOOT_IMAGE_MULTI_SIG_SUPPORT>
        $<$<BOOL:${MCUBOOT_ROTPK_SIGN_POLICY}>:MCUBOOT_ROTPK_SIGN_POLICY>
)

target_link_libraries(bl2
    PUBLIC
        bootutil
)

if (MCUBOOT_ALIGN_VAL GREATER 8)
set (MCUBOOT_BOOT_MAX_ALIGN ${MCUBOOT_ALIGN_VAL})
else()
set (MCUBOOT_BOOT_MAX_ALIGN 8)
endif()

configure_file(include/mcuboot_config/mcuboot_config.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/mcuboot_config/mcuboot_config.h
               @ONLY)

############################### IMAGE SIGNING ##################################

if (PLATFORM_DEFAULT_IMAGE_SIGNING)
    find_package(Python3)
    if(MCUBOOT_GENERATE_SIGNING_KEYPAIR)
        string(REGEX MATCH "[0-9]*$" SIG_LEN ${MCUBOOT_SIGNATURE_TYPE})
        string(REGEX MATCH "^[A-Z]*" SIG_TYPE ${MCUBOOT_SIGNATURE_TYPE})
        add_custom_target(generated_private_key
            SOURCES
                generated_private_key_s.pem
                generated_private_key_ns.pem
        )

        # The imgtool.py has different name styles for the keys
        # so we have to use that.
        if(${SIG_TYPE} STREQUAL RSA)
            set(MCUBOOT_KEY_TYPE_NAME rsa-${SIG_LEN})
        elseif(${SIG_TYPE} STREQUAL EC)
            set(MCUBOOT_KEY_TYPE_NAME ecdsa-p${SIG_LEN})
        endif()

        add_custom_command(OUTPUT generated_private_key_s.pem
            COMMAND ${Python3_EXECUTABLE} ${MCUBOOT_PATH}/scripts/imgtool.py
                keygen
                -k generated_private_key_s.pem
                -t ${MCUBOOT_KEY_TYPE_NAME}
            COMMAND ${CMAKE_COMMAND} -E copy generated_private_key_s.pem $<TARGET_FILE_DIR:bl2>
        )
        add_custom_command(OUTPUT generated_private_key_ns.pem
            COMMAND ${Python3_EXECUTABLE} ${MCUBOOT_PATH}/scripts/imgtool.py
                keygen
                -k generated_private_key_ns.pem
                -t ${MCUBOOT_KEY_TYPE_NAME}
            COMMAND ${CMAKE_COMMAND} -E copy generated_private_key_ns.pem $<TARGET_FILE_DIR:bl2>
        )
        set(MCUBOOT_KEY_S $<TARGET_FILE_DIR:bl2>/generated_private_key_s.pem CACHE FILEPATH "" FORCE)
        set(MCUBOOT_KEY_NS $<TARGET_FILE_DIR:bl2>/generated_private_key_ns.pem CACHE FILEPATH "" FORCE)
    endif()

    add_custom_target(public_key ALL
        SOURCES
            image_s_signing_public_key.pem
            image_ns_signing_public_key.pem
    )
    add_custom_command(OUTPUT image_s_signing_public_key.pem
        # If MCUBOOT_GENERATE_SIGNING_KEYPAIR=ON then the command should depend on that
        # to make sure that the key is generated and copied to the MCUBOOT_KEY_S path.
        DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,>
        COMMAND ${Python3_EXECUTABLE} ${MCUBOOT_PATH}/scripts/imgtool.py
            getpub
            -k ${MCUBOOT_KEY_S}
            -e pem
            -o image_s_signing_public_key.pem
        COMMAND ${CMAKE_COMMAND} -E copy image_s_signing_public_key.pem $<TARGET_FILE_DIR:bl2>
    )
    add_custom_command(OUTPUT image_ns_signing_public_key.pem
        # If MCUBOOT_GENERATE_SIGNING_KEYPAIR=ON then the command should depend on that
        # to make sure that the key is generated and copied to the MCUBOOT_KEY_NS path.
        DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,>
        COMMAND ${Python3_EXECUTABLE} ${MCUBOOT_PATH}/scripts/imgtool.py
            getpub
            -k ${MCUBOOT_KEY_NS}
            -e pem
            -o image_ns_signing_public_key.pem
        COMMAND ${CMAKE_COMMAND} -E copy image_ns_signing_public_key.pem $<TARGET_FILE_DIR:bl2>
    )

    set(IMAGE_TYPE "S_IMAGE")
    set(FLASH_AREA_NUM ${MCUBOOT_S_IMAGE_FLASH_AREA_NUM})
    if (MCUBOOT_IMAGE_NUMBER GREATER 1)
        configure_file(signing_layout.c.in signing_layout_s.c @ONLY)
        add_library(signing_layout_s OBJECT ${CMAKE_CURRENT_BINARY_DIR}/signing_layout_s.c)
    else()
        # Imgtool script requires the s_ns sufix. Since only one sigining layout is
        # used in this mode the signing_layout_s target's source file is renamed.
        configure_file(signing_layout.c.in signing_layout_s_ns.c @ONLY)
        add_library(signing_layout_s OBJECT ${CMAKE_CURRENT_BINARY_DIR}/signing_layout_s_ns.c)
    endif()

    target_compile_options(signing_layout_s
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-E\;-xc>
            $<$<C_COMPILER_ID:ARMClang>:-E\;-xc>
            $<$<C_COMPILER_ID:IAR>:--preprocess=ns\;$<TARGET_OBJECTS:signing_layout_s>>
            $<$<C_COMPILER_ID:Clang>:-E\;-xc>
    )
    target_compile_definitions(signing_layout_s
        PRIVATE
            $<$<BOOL:${BL2}>:BL2>
            $<$<BOOL:${MCUBOOT_IMAGE_NUMBER}>:MCUBOOT_IMAGE_NUMBER=${MCUBOOT_IMAGE_NUMBER}>
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},DIRECT_XIP>:IMAGE_ROM_FIXED>
    )
    target_link_libraries(signing_layout_s
        PRIVATE
            platform_bl2
    )

    add_custom_target(tfm_s_signed_bin
        SOURCES tfm_s_signed.bin
    )

    set(wrapper_args
        -v ${MCUBOOT_IMAGE_VERSION_S}
        --layout $<TARGET_OBJECTS:signing_layout_s>
        -k ${MCUBOOT_KEY_S}
        --public-key-format $<IF:$<BOOL:${MCUBOOT_HW_KEY}>,full,hash>
        --align ${MCUBOOT_ALIGN_VAL}
        --pad
        --pad-header
        -H ${BL2_HEADER_SIZE}
        -s ${MCUBOOT_SECURITY_COUNTER_S}
        -L ${MCUBOOT_ENC_KEY_LEN}
        -d \"\(1,${MCUBOOT_NS_IMAGE_MIN_VER}\)\"
        $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},OVERWRITE_ONLY>:--overwrite-only>
        $<$<BOOL:${MCUBOOT_CONFIRM_IMAGE}>:--confirm>
        $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:-E${MCUBOOT_KEY_ENC}>
        $<$<BOOL:${MCUBOOT_MEASURED_BOOT}>:--measured-boot-record>
        $<TARGET_FILE_DIR:tfm_s>/tfm_s.bin
        ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_signed.bin
    )

    if(MCUBOOT_BUILTIN_KEY)
        set(wrapper_args ${wrapper_args} --psa-key-ids ${TFM_S_KEY_ID})
        if(MCUBOOT_IMAGE_MULTI_SIG_SUPPORT AND PLATFORM_DEFAULT_ROTPK)
            set(wrapper_args ${wrapper_args} --psa-key-ids ${TFM_NS_KEY_ID})
        endif()
    endif()

    if(MCUBOOT_IMAGE_MULTI_SIG_SUPPORT)
        set(wrapper_args ${wrapper_args} -k ${MCUBOOT_KEY_NS})
    endif()

    get_target_property(bin_dir bl2 RUNTIME_OUTPUT_DIRECTORY)

    add_custom_command(OUTPUT tfm_s_signed.bin
        OUTPUT ${bin_dir}/tfm_s_signed.bin
        DEPENDS tfm_s_bin signing_layout_s
        DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,>
        DEPENDS $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:${MCUBOOT_KEY_ENC_NS}>
        WORKING_DIRECTORY ${MCUBOOT_PATH}/scripts

        #Sign secure binary image with provided secret key
        COMMAND  mcuboot_imagesign_wrapper ${wrapper_args}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_signed.bin ${bin_dir}
    )

    set(IMAGE_TYPE "NS_IMAGE")
    set(FLASH_AREA_NUM ${MCUBOOT_NS_IMAGE_FLASH_AREA_NUM})
    configure_file(signing_layout.c.in signing_layout_ns.c @ONLY)

    add_library(signing_layout_ns OBJECT ${CMAKE_CURRENT_BINARY_DIR}/signing_layout_ns.c)
    target_compile_options(signing_layout_ns
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-E\;-xc>
            $<$<C_COMPILER_ID:ARMClang>:-E\;-xc>
            $<$<C_COMPILER_ID:IAR>:--preprocess=ns\;$<TARGET_OBJECTS:signing_layout_ns>>
            $<$<C_COMPILER_ID:Clang>:-E\;-xc>
    )
    target_compile_definitions(signing_layout_ns
        PRIVATE
            $<$<BOOL:${BL2}>:BL2>
            $<$<BOOL:${MCUBOOT_IMAGE_NUMBER}>:MCUBOOT_IMAGE_NUMBER=${MCUBOOT_IMAGE_NUMBER}>
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},DIRECT_XIP>:IMAGE_ROM_FIXED>
    )
    target_link_libraries(signing_layout_ns
        PRIVATE
            platform_bl2
    )

    add_custom_target(signed_images
        ALL
        DEPENDS tfm_s_signed_bin
    )

    add_convert_to_offset_hex_target(tfm_s_signed
        INPUT_FILE          ${bin_dir}/tfm_s_signed.bin
        OFFSET_MACRO_NAME   S_CODE_START
        INCLUDE_BL2_HEADER  TRUE
        MIRROR_FILE         $<TARGET_PROPERTY:tfm_s,LINK_DEPENDS>
        OUTPUT_FILE         ${bin_dir}/tfm_s_signed.hex
    )
endif()
