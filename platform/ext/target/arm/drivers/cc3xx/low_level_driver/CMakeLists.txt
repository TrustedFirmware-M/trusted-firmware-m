#-------------------------------------------------------------------------------
# Copyright (c) 2021-2024, The TrustedFirmware-M Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_library(${CC3XX_TARGET_NAME} STATIC)

if (NOT DEFINED CC3XX_PLATFORM_INTERFACE)
    message(FATAL "When building cc3xx_lowlevel, the platform dependency must be specified")
endif()

target_sources(${CC3XX_TARGET_NAME}
    PRIVATE
        src/cc3xx_lcs.c
        src/cc3xx_otp.c
        src/cc3xx_rng.c
        src/cc3xx_hash.c
        src/cc3xx_aes.c
        src/cc3xx_dma.c
        src/cc3xx_init.c
        src/cc3xx_engine_state.c
        src/cc3xx_chacha.c
        src/cc3xx_kdf.c
        src/cc3xx_pka.c
        src/cc3xx_poly1305.c
        src/cc3xx_hmac.c
        src/cc3xx_drbg_ctr.c
        src/cc3xx_drbg_hash.c
        src/cc3xx_drbg_hmac.c
        src/cc3xx_drbg.c
        src/cc3xx_ecdsa.c
        src/cc3xx_ec.c
        src/cc3xx_ec_curve_data.c
        src/cc3xx_ec_weierstrass.c
        src/cc3xx_ec_projective_point.c
        src/cc3xx_ecdh.c
        src/cc3xx_dcu.c
        src/cc3xx_noise_source.c
        src/cc3xx_entropy.c
        ../common/cc3xx_stdlib.c
)

# This file is the performance-limit for ECDSA, so should be compiled with the
# highest possible optimizations for speed, even when we are optimizing for
# code size.
string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_LOWER)
if (${BUILD_TYPE_LOWER} STREQUAL "release" OR ${BUILD_TYPE_LOWER} STREQUAL "minsizerel")
    set_source_files_properties(src/cc3xx_pka.c
        PROPERTIES COMPILE_FLAGS -Ofast
    )
endif()

target_include_directories(${CC3XX_TARGET_NAME}
    PUBLIC
        include
        ../common
    PRIVATE
        src
)

target_link_libraries(${CC3XX_TARGET_NAME}
    PRIVATE
        ${CC3XX_PLATFORM_INTERFACE}
)
