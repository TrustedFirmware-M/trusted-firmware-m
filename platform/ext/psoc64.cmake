#-------------------------------------------------------------------------------
# Copyright (c) 2018-2019, Arm Limited. All rights reserved.
# Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#This file gathers all Cypress PSoC 6 specific files in the application.

include("Common/MultiCore")

# Select configuration of multi-core topology
enable_multi_core_topology_config()

set(TFM_NS_CLIENT_IDENTIFICATION OFF)

add_definitions(-DCYB06447BZI_D54=1)
add_definitions(-DNDEBUG=1)
add_definitions(-DTFM_CORE_DEBUG)

# Skip Core Test temporarily
set(CORE_TEST OFF)
# Skip peripheral access test
set(TFM_ENABLE_PERIPH_ACCESS_TEST OFF)

# Set Cortex-M0plus as secure core
set_secure_cpu_type("CpuM0p")
# Set Cortex-M4 as non-secure core
set_ns_cpu_type("CpuM4")

# Set PSoC62 specific secure definitions
add_platform_secure_definitions(CY_PSOC6_CM0P=1)

set(PLATFORM_DIR ${CMAKE_CURRENT_LIST_DIR})

#Specify the location of platform specific build dependencies.
if(COMPILER STREQUAL "ARMCLANG")
    set (BL2_SCATTER_FILE_NAME "${PLATFORM_DIR}/target/psoc64/Device/Source/armclang/psoc6_bl2.sct")
    set (S_SCATTER_FILE_NAME   "${PLATFORM_DIR}/common/armclang/tfm_common_s.sct")
    set (NS_SCATTER_FILE_NAME  "${PLATFORM_DIR}/target/psoc64/Device/Source/armclang/psoc6_ns.sct")
    if (DEFINED CMSIS_5_DIR)
      # not all project defines CMSIS_5_DIR, only the ones that use it.
      set (RTX_LIB_PATH "${CMSIS_5_DIR}/CMSIS/RTOS2/RTX/Library/ARM/RTX_CM4F.lib")
    endif()
elseif(COMPILER STREQUAL "GNUARM")
    set (BL2_SCATTER_FILE_NAME "${PLATFORM_DIR}/target/psoc64/Device/Source/gcc/psoc6_bl2.ld")
    set (S_SCATTER_FILE_NAME   "${PLATFORM_DIR}/common/gcc/tfm_common_s.ld")
    set (NS_SCATTER_FILE_NAME  "${PLATFORM_DIR}/target/psoc64/Device/Source/gcc/psoc6_ns.ld")
    if (DEFINED CMSIS_5_DIR)
      # not all project defines CMSIS_5_DIR, only the ones that use it.
      # [libRTX_CM3.a should be used for CM4 without FPU]
      set (RTX_LIB_PATH "${CMSIS_5_DIR}/CMSIS/RTOS2/RTX/Library/GCC/libRTX_CM3.a")
    endif()
else()
    message(FATAL_ERROR "No startup file is available for compiler '${CMAKE_C_COMPILER_ID}'.")
endif()
set (FLASH_LAYOUT          "${PLATFORM_DIR}/target/psoc64/partition/flash_layout.h")
set (PLATFORM_LINK_INCLUDES "${PLATFORM_DIR}/target/psoc64/partition")

if (BL2)
    set (BL2_LINKER_CONFIG ${BL2_SCATTER_FILE_NAME})

    # Turn off hardware key feature to work around the issue that booting is
    # stuck in mbed-crypto RSA operations. Wait for further debugging.
    set (MCUBOOT_HW_KEY OFF)

    #FixMe: MCUBOOT_SIGN_RSA_LEN can be removed when ROTPK won't be hard coded in platform/ext/common/tfm_rotpk.c
    #       instead independently loaded from secure code as a blob.
    if (${MCUBOOT_SIGNATURE_TYPE} STREQUAL "RSA-2048")
        add_definitions(-DMCUBOOT_SIGN_RSA_LEN=2048)
    endif()
    if (${MCUBOOT_SIGNATURE_TYPE} STREQUAL "RSA-3072")
        add_definitions(-DMCUBOOT_SIGN_RSA_LEN=3072)
    endif()
endif()

embedded_include_directories(PATH "${PLATFORM_DIR}/cmsis" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/CMSIS_Driver/Config" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/Device/Config" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/Device/Include" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/Native_Driver/include" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/mailbox" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/partition" ABSOLUTE)
embedded_include_directories(PATH "${TFM_ROOT_DIR}/interface/include" ABSOLUTE)
embedded_include_directories(PATH "${TFM_ROOT_DIR}/platform/include" ABSOLUTE)
embedded_include_directories(PATH "${TFM_ROOT_DIR}/secure_fw/core/arch/include" ABSOLUTE)
embedded_include_directories(PATH "${TFM_ROOT_DIR}/secure_fw/core/ipc/include" ABSOLUTE)

#Gather all source files we need.
list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/mailbox/platform_multicore.c")
list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc64/mailbox/mailbox_ipc_intr.c")
list(APPEND ALL_SRC_C_NS "${PLATFORM_DIR}/target/psoc64/mailbox/platform_ns_mailbox.c")
list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc64/mailbox/mailbox_ipc_intr.c")
list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc64/mailbox/platform_spe_mailbox.c")

install(FILES ${PLATFORM_DIR}/target/psoc64/mailbox/ns_ipc_config.h
        ${PLATFORM_DIR}/target/psoc64/mailbox/platform_multicore.h
        DESTINATION export/tfm/inc)

install(FILES ${PLATFORM_DIR}/target/psoc64/mailbox/platform_multicore.c
        ${PLATFORM_DIR}/target/psoc64/mailbox/platform_ns_mailbox.c
        DESTINATION export/tfm/src)

if (NOT DEFINED BUILD_CMSIS_CORE)
  message(FATAL_ERROR "Configuration variable BUILD_CMSIS_CORE (true|false) is undefined!")
elseif(BUILD_CMSIS_CORE)
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc64/Device/Source/system_psoc6_cm0plus.c")
  list(APPEND ALL_SRC_C_NS "${PLATFORM_DIR}/target/psoc64/Device/Source/system_psoc6_cm4.c")
  list(APPEND ALL_SRC_C_BL2 "${PLATFORM_DIR}/target/psoc64/Device/Source/system_psoc6_cm0plus.c")
endif()

if (NOT DEFINED BUILD_RETARGET)
  message(FATAL_ERROR "Configuration variable BUILD_RETARGET (true|false) is undefined!")
elseif(BUILD_RETARGET)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Device/Source/device_definition.c")
endif()

if (NOT DEFINED BUILD_UART_STDOUT)
  message(FATAL_ERROR "Configuration variable BUILD_UART_STDOUT (true|false) is undefined!")
elseif(BUILD_UART_STDOUT)
  if (NOT DEFINED SECURE_UART1)
    message(FATAL_ERROR "Configuration variable SECURE_UART1 (true|false) is undefined!")
  elseif(SECURE_UART1)
    message(FATAL_ERROR "Configuration SECURE_UART1 TRUE is invalid for this target!")
  endif()
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/common/uart_stdout.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/common" ABSOLUTE)
  set(BUILD_NATIVE_DRIVERS true)
  set(BUILD_CMSIS_DRIVERS true)
endif()

if (NOT DEFINED BUILD_NATIVE_DRIVERS)
  message(FATAL_ERROR "Configuration variable BUILD_NATIVE_DRIVERS (true|false) is undefined!")
elseif(BUILD_NATIVE_DRIVERS)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_device.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_flash.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_gpio.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_prot.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_ipc_drv.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_ipc_pipe.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_ipc_sema.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_scb_common.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_scb_uart.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_sysclk.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_sysint.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_syslib.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_syspm.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_systick.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_trigmux.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/source/cy_wdt.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source/cycfg.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source/cycfg_clocks.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source/cycfg_dmas.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source/cycfg_peripherals.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source/cycfg_pins.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source/cycfg_platform.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/Native_Driver/generated_source/cycfg_routing.c")
  if(CMAKE_C_COMPILER_ID STREQUAL "ARMCLANG")
	  list(APPEND ALL_SRC_ASM "${PLATFORM_DIR}/target/psoc64/Device/Source/armclang/cy_syslib_mdk.s")
  elseif(CMAKE_C_COMPILER_ID STREQUAL "GNUARM")
	  list(APPEND ALL_SRC_ASM "${PLATFORM_DIR}/target/psoc64/Device/Source/gcc/cy_syslib_gcc.S")
  else()
    message(FATAL_ERROR "No cy_syslib is available for compiler '${CMAKE_C_COMPILER_ID}'.")
  endif()
endif()

if (NOT DEFINED BUILD_TIME)
  message(FATAL_ERROR "Configuration variable BUILD_TIME (true|false) is undefined!")
elseif(BUILD_TIME)
endif()

if (NOT DEFINED BUILD_STARTUP)
  message(FATAL_ERROR "Configuration variable BUILD_STARTUP (true|false) is undefined!")
elseif(BUILD_STARTUP)
  if(CMAKE_C_COMPILER_ID STREQUAL "ARMCLANG")
    list(APPEND ALL_SRC_ASM_S "${PLATFORM_DIR}/target/psoc64/Device/Source/armclang/startup_psoc6_s.s")
    list(APPEND ALL_SRC_ASM_NS "${PLATFORM_DIR}/target/psoc64/Device/Source/armclang/startup_psoc6_ns.s")
    list(APPEND ALL_SRC_ASM_BL2 "${PLATFORM_DIR}/target/psoc64/Device/Source/armclang/startup_psoc6_bl2.s")
  elseif(CMAKE_C_COMPILER_ID STREQUAL "GNUARM")
    list(APPEND ALL_SRC_ASM_S "${PLATFORM_DIR}/target/psoc64/Device/Source/gcc/startup_psoc6_s.S")
    list(APPEND ALL_SRC_ASM_NS "${PLATFORM_DIR}/target/psoc64/Device/Source/gcc/startup_psoc6_ns.S")
    list(APPEND ALL_SRC_ASM_BL2 "${PLATFORM_DIR}/target/psoc64/Device/Source/gcc/startup_psoc6_bl2.S")
    set_property(SOURCE "${ALL_SRC_ASM_S}" "${ALL_SRC_ASM_NS}" "${ALL_SRC_ASM_BL2}" APPEND
      PROPERTY COMPILE_DEFINITIONS "__STARTUP_CLEAR_BSS_MULTIPLE" "__STARTUP_COPY_MULTIPLE")
  else()
    message(FATAL_ERROR "No startup file is available for compiler '${CMAKE_C_COMPILER_ID}'.")
  endif()
endif()

if (NOT DEFINED BUILD_TARGET_CFG)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_CFG (true|false) is undefined!")
elseif(BUILD_TARGET_CFG)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/target_cfg.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc64/spm_hal.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc64/attest_hal.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc64/tfm_platform_system.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/common/tfm_platform.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/common" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_TARGET_HARDWARE_KEYS)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_HARDWARE_KEYS (true|false) is undefined!")
elseif(BUILD_TARGET_HARDWARE_KEYS)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/common/tfm_initial_attestation_key_material.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/common/tfm_rotpk.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/dummy_crypto_keys.c")
endif()

if (NOT DEFINED BUILD_TARGET_NV_COUNTERS)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_NV_COUNTERS (true|false) is undefined!")
elseif(BUILD_TARGET_NV_COUNTERS)
  # NOTE: This non-volatile counters implementation is a dummy
  #       implementation. Platform vendors have to implement the
  #       API ONLY if the target has non-volatile counters.
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/dummy_nv_counters.c")
  set(TARGET_NV_COUNTERS_ENABLE ON)
  # Sets SST_ROLLBACK_PROTECTION flag to compile in the SST services
  # rollback protection code as the target supports nv counters.
  set (SST_ROLLBACK_PROTECTION ON)
endif()

if (NOT DEFINED BUILD_CMSIS_DRIVERS)
  message(FATAL_ERROR "Configuration variable BUILD_CMSIS_DRIVERS (true|false) is undefined!")
elseif(BUILD_CMSIS_DRIVERS)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/driver_smpu.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/driver_ppu.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/driver_dap.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/CMSIS_Driver/Driver_USART.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/CMSIS_Driver" ABSOLUTE)
  embedded_include_directories(PATH "${PLATFORM_DIR}/driver" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_FLASH)
  message(FATAL_ERROR "Configuration variable BUILD_FLASH (true|false) is undefined!")
elseif(BUILD_FLASH)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/CMSIS_Driver/Driver_Flash.c")
  # As the SST area is going to be in RAM, it is required to set SST_CREATE_FLASH_LAYOUT
  # to be sure the SST service knows that when it starts the SST area does not contain any
  # valid SST flash layout and it needs to create one.
  set(SST_CREATE_FLASH_LAYOUT ON)
  embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc64/CMSIS_Driver" ABSOLUTE)
  embedded_include_directories(PATH "${PLATFORM_DIR}/driver" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_BOOT_SEED)
  message(FATAL_ERROR "Configuration variable BUILD_BOOT_SEED (true|false) is undefined!")
elseif(BUILD_BOOT_SEED)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/dummy_boot_seed.c")
endif()

if (NOT DEFINED BUILD_DEVICE_ID)
  message(FATAL_ERROR "Configuration variable BUILD_DEVICE_ID (true|false) is undefined!")
elseif(BUILD_DEVICE_ID)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc64/dummy_device_id.c")
endif()
