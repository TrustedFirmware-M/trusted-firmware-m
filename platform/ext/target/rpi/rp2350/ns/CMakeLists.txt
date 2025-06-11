#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
#-------------------------------------------------------------------------------

# initialize pico-sdk from GIT
set(PICO_SDK_FETCH_FROM_GIT on)
set(PICO_PLATFORM rp2350-arm-s)
set(SKIP_BOOT_STAGE2 1)

# initialize the Raspberry Pi Pico SDK
include(${CMAKE_CURRENT_LIST_DIR}/pico_sdk_import.cmake)
pico_sdk_init()

get_target_property(pico_link_options pico_standard_link INTERFACE_LINK_OPTIONS)
list(FILTER pico_link_options EXCLUDE REGEX "LINKER.*--script")
list(APPEND pico_link_options "--entry=_entry_point")
set_target_properties(pico_standard_link PROPERTIES INTERFACE_LINK_OPTIONS "${pico_link_options}")
set_target_properties(pico_runtime PROPERTIES INTERFACE_LINK_OPTIONS "")


cmake_policy(SET CMP0076 NEW)

set(PLATFORM_DIR ${CMAKE_CURRENT_LIST_DIR})
set(STATIC_ASSERT_OVERRIDE_HEADER "${PLATFORM_DIR}/static_assert_override.h")

add_library(static_assert_override INTERFACE)
add_library(device_definition INTERFACE)
add_library(platform_ns STATIC)

# GNU Arm compiler version greater equal than *11.3.Rel1*
# throw warning when linker segments used as rwx
# Adding --no-warn-rwx-segments like the RPi SDK did.
if (CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 11.3.1)
    target_link_options(tfm_ns PRIVATE "LINKER:--no-warn-rwx-segments")
endif()

target_link_options(tfm_ns PRIVATE "LINKER:--entry=_entry_point")

add_library(platform_ns_init INTERFACE)
target_sources(platform_ns_init
    INTERFACE
        extra_init_ns.c
)

target_link_libraries(platform_ns_init
    INTERFACE
        cmsis_core_headers
        pico_runtime_init
        pico_runtime_headers
        static_assert_override
        pico_bootrom_headers
        hardware_clocks
)

target_compile_definitions(platform_ns_init
    INTERFACE
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:TFM_MULTI_CORE_TOPOLOGY>
)

# Note: This should be Private and in tfm_ns_scatter
target_compile_definitions(platform_region_defs
    INTERFACE
        # u modifier in scatter file is not valid
        NO_U_MODIFIER=1
        $<$<BOOL:${TFM_LOAD_NS_IMAGE}>:TFM_LOAD_NS_IMAGE>
)
#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PLATFORM_DIR}/include
        ${PLATFORM_DIR}/device/config
)

target_link_libraries(platform_region_defs
    INTERFACE
        hardware_regs_headers
        static_assert_override
)

target_compile_options(static_assert_override
    INTERFACE
        "$<$<C_COMPILER_ID:Armclang>:SHELL:-include ${STATIC_ASSERT_OVERRIDE_HEADER}>"
        "$<$<C_COMPILER_ID:GNU>:SHELL:-include ${STATIC_ASSERT_OVERRIDE_HEADER}>"
        "$<$<C_COMPILER_ID:IAR>:SHELL:--preinclude ${STATIC_ASSERT_OVERRIDE_HEADER}>"
)

#========================= Device definition lib ===============================#

target_include_directories(device_definition
    INTERFACE
        .
        device/include
        native_drivers
        partition
        libraries
        native_drivers
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m
        ${ETHOS_DRIVER_PATH}/src
        ${ETHOS_DRIVER_PATH}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/device/config
)

#========================= Platform Non-Secure ================================#

target_sources(platform_ns
    PRIVATE
        $<$<BOOL:${TFM_NS_MAILBOX_API}>:platform_ns_mailbox.c>
        cmsis_drivers/Driver_USART_RPI.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
)

target_include_directories(platform_ns
    PUBLIC
        cmsis_drivers
        ${PLATFORM_DIR}/ext/cmsis/Include
        ${PLATFORM_DIR}/ext/cmsis/Include/m-profile
        ${PLATFORM_DIR}/include
        ${PLATFORM_DIR}/ext/common
)

target_link_libraries(platform_ns
    PUBLIC
        cmsis_core_headers
        platform_ns_init
    PRIVATE
        device_definition
        pico_crt0
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:pico_multicore>
        hardware_regs
        hardware_flash
        hardware_uart
        cmsis_core
)

target_compile_definitions(platform_ns
    PUBLIC
        PICO_UART_DEFAULT_CRLF=1
        CMSIS_device_header=<RP2350.h>
        PICO_DEFAULT_TIMER=1
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:TFM_MULTI_CORE_TOPOLOGY>
)

if (TFM_NS_CUSTOM_API)
    target_sources(tfm_api_ns PRIVATE
        ${INTERFACE_SRC_DIR}/os_wrapper/tfm_ns_interface_rtos.c
    )

    add_library(tfm_api_ns_custom INTERFACE)

    target_sources(tfm_api_ns_custom
        INTERFACE
            tfm_custom_psa_ns_api.c
    )

    target_link_libraries(tfm_api_ns_custom
        INTERFACE
            ${INTERFACE_SRC_DIR}/../lib/s_veneers.o
    )

    target_link_libraries(tfm_api_ns
        PRIVATE
            tfm_api_ns_custom
            os_wrapper
    )

    # lib parth
    set(APP_LIB_DIR                  ${CMAKE_CURRENT_LIST_DIR}/../../../../../lib)

    target_sources(RTX_OS
        INTERFACE
            # Provide TZ context management stub to RTOS if protected by Trustzone
            ${APP_LIB_DIR}/nsid_manager/tz_shim_layer.c
    )
endif()
