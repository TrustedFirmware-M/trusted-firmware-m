#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)
# Set CMP0118: The GENERATED source file property is now visible in all
# directories for all targets created in this file
cmake_policy(SET CMP0118 NEW)

################################ IFX_PDL_LIB_S ################################

# There are two libraries for secure PDL. This is needed to resolve circular dependency between
# BSP and PDL.
# - ifx_pdl_inc_s is used to provide includes and compile definitions for secure PDL.
# - ifx_pdl_s is used to build PDL library for TF-M.
add_library(ifx_pdl_inc_s INTERFACE)
add_library(ifx_pdl_s STATIC EXCLUDE_FROM_ALL)

# Linker scripts have a special case for flash_drivers,
# so anything that needs to run from SRAM goes there
add_library(flash_drivers STATIC)

target_compile_options(ifx_pdl_s
    PRIVATE
        ${COMPILER_CP_FLAG}
)

set(RAMFUNC ".ramfunc")
set(CY_SECTION_RAMFUNC "CY_SECTION(\"${RAMFUNC}\")")

target_compile_definitions(ifx_pdl_s
    PRIVATE
        CY_SECTION_RAMFUNC_BEGIN=${CY_SECTION_RAMFUNC}
        CY_SECTION_SRAM_CODE_BEGIN=${CY_SECTION_RAMFUNC}
)

target_sources(ifx_pdl_s
    PRIVATE
        $<$<STREQUAL:${IFX_MBEDTLS_ACCELERATOR_TYPE},MXCRYPTO>:${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_hw.c>
        $<$<STREQUAL:${IFX_MBEDTLS_ACCELERATOR_TYPE},MXCRYPTO>:${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_mem_v2.c>
        $<$<STREQUAL:${IFX_MBEDTLS_ACCELERATOR_TYPE},MXCRYPTO>:${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_trng.c>
        $<$<STREQUAL:${IFX_MBEDTLS_ACCELERATOR_TYPE},CRYPTOLITE>:${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_trng.c>
        $<$<BOOL:${IFX_FLASH_DRIVER_ENABLED}>:${IFX_PDL_LIB_PATH}/drivers/source/cy_flash.c>
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_gpio.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_ipc_drv.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_ipc_sema.c
        $<$<OR:$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V1}>,$<BOOL:${IFX_MPC_DRIVER_HW_MPC_V2}>>:${IFX_PDL_LIB_PATH}/drivers/source/cy_mpc.c>
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_ms_ctl.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_ppc.c
        $<$<BOOL:${IFX_RRAM_DRIVER_ENABLED}>:${IFX_PDL_LIB_PATH}/drivers/source/cy_rram.c>
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_scb_common.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_scb_uart.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_sysclk_${IFX_PDL_CY_SYSCLK_VERSION}.c
        # IMPROVEMENT: Make unconditional once BSP-7614 is fixed
        $<$<NOT:$<BOOL:${IFX_PDL_EXCLUDE_SYSFAULT}>>:${IFX_PDL_LIB_PATH}/drivers/source/cy_sysfault.c>
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_sysint_v2.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_syspm_${IFX_PDL_CY_SYSPM_VERSION}.c
        # IMPROVEMENT: Make unconditional once BSP-7614 is fixed
        $<$<NOT:$<BOOL:${IFX_PDL_EXCLUDE_SYSPM_PDCM}>>:${IFX_PDL_LIB_PATH}/drivers/source/cy_syspm_pdcm.c>
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_syspm_ppu.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_tcpwm_counter.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_trigmux.c
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_wdt.c
        ${IFX_PDL_LIB_PATH}/drivers/source/ppu_v1.c
)

if(IFX_MTB_SRF) # MTB SRF specific PDL code
    target_sources(ifx_pdl_s
        PRIVATE
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_pdl_srf.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_rtc.c
    )
endif()

target_link_libraries(ifx_pdl_s
    PUBLIC
        ifx_pdl_inc_s
    PRIVATE
        ${IFX_SHARED_RO_DATA_TARGET}
        flash_drivers
)

target_sources(flash_drivers
    PRIVATE
        # ARM CLang uses GNU style assembly files, thus cy_syslib_ext.S from
        # TOOLCHAIN_LLVM_ARM is used. GCC cy_syslib_ext.S can not be used as it
        # contains .func directives which are not supported by ARM Clang assembler.
        $<$<C_COMPILER_ID:ARMClang>:${IFX_PDL_LIB_PATH}/drivers/source/TOOLCHAIN_LLVM_ARM/cy_syslib_ext.S>
        $<$<C_COMPILER_ID:GNU>:${IFX_PDL_LIB_PATH}/drivers/source/TOOLCHAIN_GCC_ARM/cy_syslib_ext.S>
        $<$<C_COMPILER_ID:IAR>:${IFX_PDL_LIB_PATH}/drivers/source/TOOLCHAIN_IAR/cy_syslib_ext.s>
        ${IFX_PDL_LIB_PATH}/drivers/source/cy_syslib.c
)

target_link_libraries(flash_drivers
    PUBLIC
        ifx_pdl_inc_s
)

target_compile_options(flash_drivers
    PRIVATE
        ${COMPILER_CP_FLAG}
)

target_include_directories(ifx_pdl_inc_s
    INTERFACE
        ${IFX_PDL_LIB_PATH}/drivers/include
        ${IFX_PDL_LIB_PATH}/drivers/source
)

target_compile_definitions(ifx_pdl_inc_s
    INTERFACE
        ${IFX_PDL_PART_NUMBER}
        $<$<STREQUAL:${IFX_CORE},${IFX_CM33}>:COMPONENT_CM33>
        $<$<STREQUAL:${IFX_CORE},${IFX_CM33}>:CORE_NAME_CM33_0>
        $<$<STREQUAL:${IFX_CORE},${IFX_CM55}>:COMPONENT_CM55>
        $<$<STREQUAL:${IFX_CORE},${IFX_CM55}>:CORE_NAME_CM55_0>
)

target_compile_options(ifx_pdl_inc_s
    INTERFACE
        $<$<AND:$<C_COMPILER_ID:ARMClang>,$<COMPILE_LANGUAGE:C>>:-Wno-documentation>
)

target_link_libraries(ifx_pdl_inc_s
    INTERFACE
        # Use same CMSIS library for all targets
        cmsis
        ifx_core_lib
        tfm_config
)

if ((DEFINED IFX_DEV_SUPPORT_LIB_PATH) AND (NOT DEFINED IFX_DEVICE_CATEGORY))
    target_sources(ifx_pdl_s
        PRIVATE
            ${IFX_PDL_LIB_PATH}/devices/source/cy_device.c
    )

    target_include_directories(ifx_pdl_inc_s
        INTERFACE
            ${IFX_PDL_LIB_PATH}/devices/include
            ${IFX_PDL_LIB_PATH}/devices/include/ip
    )
else()
    target_sources(ifx_pdl_s
        PRIVATE
            ${IFX_PDL_LIB_PATH}/devices/COMPONENT_${IFX_DEVICE_CATEGORY}/source/cy_device.c
    )

    target_include_directories(ifx_pdl_inc_s
        INTERFACE
            ${IFX_PDL_LIB_PATH}/devices/COMPONENT_${IFX_DEVICE_CATEGORY}/include
            ${IFX_PDL_LIB_PATH}/devices/COMPONENT_${IFX_DEVICE_CATEGORY}/include/ip
    )
endif()

# ifx_pdl_mbedtls_acceleration is used to capture Crypto H/W drivers into library that is linked
# via *mbedtls*acceleration.* pattern into Crypto partition to satisfy data isolation requirements.
# This library is also used by FIH driver to generate TRNG delay for HIGH profile.
add_library(ifx_pdl_mbedtls_acceleration STATIC EXCLUDE_FROM_ALL)

target_compile_options(ifx_pdl_mbedtls_acceleration
    PRIVATE
        ${COMPILER_CP_FLAG}
)

if (IFX_MBEDTLS_ACCELERATOR_TYPE STREQUAL "CRYPTOLITE")
    target_sources(ifx_pdl_mbedtls_acceleration
        PRIVATE
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_aes.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_aes_ccm.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_cmac.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_ecc_key_gen.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_ecdsa.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_hkdf.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_hmac.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_nist_p.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_rsa.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_sha256.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_trng.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_utils.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_cryptolite_vu.c
    )
elseif(IFX_MBEDTLS_ACCELERATOR_TYPE STREQUAL "MXCRYPTO")
    target_sources(ifx_pdl_mbedtls_acceleration
        PRIVATE
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_aes_v2.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_cmac_v2.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_crc_v2.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_ecc_domain_params.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_ecc_ec25519.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_ecc_ecdsa.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_ecc_eddsa.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_ecc_key_gen.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_ecc_nist_p.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_hkdf_v2.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_hmac_v2.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_hw.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_mem_v2.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_poly1305.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_rsa.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_sha_v2.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_core_vu.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto_utils.c
            ${IFX_PDL_LIB_PATH}/drivers/source/cy_crypto.c
    )
endif()

target_link_libraries(ifx_pdl_mbedtls_acceleration
    PRIVATE
        ifx_pdl_inc_s
        ifx_pdl_s
)
