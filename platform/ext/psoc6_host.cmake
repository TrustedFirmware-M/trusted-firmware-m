#-------------------------------------------------------------------------------
# Copyright (c) 2018-2019, Arm Limited. All rights reserved.
# Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#This file gathers all Cypress PSoC 6 CM4 specific files in the application.
# PsoC 6 has a Cortex-M4 on the host side

include("Common/CpuM4")

set(TFM_MULTI_CORE_TOPOLOGY ON)

add_definitions(-DCY8C6247BZI_D54=1 -DCY_IPC_DEFAULT_CFG_DISABLE=1)
add_definitions(-DCY_FLASH_RWW_DRV_SUPPORT_DISABLED=1 -DCY_ARM_FAULT_DEBUG=0 -DNDEBUG=1)
add_definitions(-DTFM_CORE_DEBUG)

set(PLATFORM_DIR ${CMAKE_CURRENT_LIST_DIR})

#Specify the location of platform specific build dependencies.
if(COMPILER STREQUAL "ARMCLANG")
    set (BL2_SCATTER_FILE_NAME "${PLATFORM_DIR}/target/psoc6/Device/Source/armclang/psoc6_bl2.sct")
    set (S_SCATTER_FILE_NAME   "${PLATFORM_DIR}/target/psoc6/Device/Source/armclang/psoc6_s.sct")
    set (NS_SCATTER_FILE_NAME  "${PLATFORM_DIR}/target/psoc6/Device/Source/armclang/psoc6_ns.sct")
    if (DEFINED CMSIS_5_DIR)
      # not all project defines CMSIS_5_DIR, only the ones that use it.
      set (RTX_LIB_PATH "${CMSIS_5_DIR}/CMSIS/RTOS2/RTX/Library/ARM/RTX_CM4F.lib")
      #set (RTX_LIB_PATH "${CMSIS_5_DIR}/CMSIS/RTOS/RTX/LIB/ARM/RTX_CM4.lib")
    endif()
elseif(COMPILER STREQUAL "GNUARM")
    set (BL2_SCATTER_FILE_NAME "${PLATFORM_DIR}/target/psoc6/Device/Source/gcc/psoc6_bl2.ld")
    set (S_SCATTER_FILE_NAME   "${PLATFORM_DIR}/target/psoc6/Device/Source/gcc/psoc6_s.ld")
    set (NS_SCATTER_FILE_NAME  "${PLATFORM_DIR}/target/psoc6/Device/Source/gcc/psoc6_ns.ld")
    if (DEFINED CMSIS_5_DIR)
      # not all project defines CMSIS_5_DIR, only the ones that use it.
      set (RTX_LIB_PATH "${CMSIS_5_DIR}/CMSIS/RTOS2/RTX/Library/GCC/libRTX_CM4F.a")
    endif()
else()
    message(FATAL_ERROR "No startup file is available for compiler '${CMAKE_C_COMPILER_ID}'.")
endif()
set (FLASH_LAYOUT          "${PLATFORM_DIR}/target/psoc6/partition/flash_layout.h")
set (PLATFORM_LINK_INCLUDES "${PLATFORM_DIR}/target/psoc6/partition")
# AINH: FLASH AREA size
set (SIGN_BIN_SIZE         0x46000)

if (BL2)
  set (BL2_LINKER_CONFIG ${BL2_SCATTER_FILE_NAME})
  #set (MCUBOOT_NO_SWAP True)
endif()

embedded_include_directories(PATH "${PLATFORM_DIR}/cmsis" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/CMSIS_Driver/Config" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/Device/Config" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/Device/Include" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/Native_Driver/include" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/mailbox" ABSOLUTE)
embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/partition" ABSOLUTE)
embedded_include_directories(PATH "${TFM_ROOT_DIR}/interface/include" ABSOLUTE)
embedded_include_directories(PATH "${TFM_ROOT_DIR}/secure_fw/core/ipc/include" ABSOLUTE)

#Gather all source files we need.
list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/mailbox/platform_multicore.c")
list(APPEND ALL_SRC_C_NS "${PLATFORM_DIR}/target/psoc6/mailbox/platform_ns_mailbox.c")
list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc6/mailbox/platform_spe_mailbox.c")

if (NOT DEFINED BUILD_CMSIS_CORE)
  message(FATAL_ERROR "Configuration variable BUILD_CMSIS_CORE (true|false) is undefined!")
elseif(BUILD_CMSIS_CORE)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Device/Source/system_psoc6_cm4.c")
endif()

if (NOT DEFINED BUILD_RETARGET)
  message(FATAL_ERROR "Configuration variable BUILD_RETARGET (true|false) is undefined!")
elseif(BUILD_RETARGET)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Device/Source/device_definition.c")
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
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_device.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_flash.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_gpio.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_prot.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_ipc_drv.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_ipc_pipe.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_ipc_sema.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_scb_common.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_scb_uart.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_sysclk.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_sysint.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_syslib.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_syspm.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_systick.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_trigmux.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/source/cy_wdt.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source/cycfg.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source/cycfg_clocks.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source/cycfg_dmas.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source/cycfg_peripherals.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source/cycfg_pins.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source/cycfg_platform.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/Native_Driver/generated_source/cycfg_routing.c")
  if(CMAKE_C_COMPILER_ID STREQUAL "ARMCLANG")
    list(APPEND ALL_SRC_ASM "${PLATFORM_DIR}/target/psoc6/Device/Source/armclang/cy_syslib_mdk.s")
  elseif(CMAKE_C_COMPILER_ID STREQUAL "GNUARM")
    list(APPEND ALL_SRC_ASM "${PLATFORM_DIR}/target/psoc6/Device/Source/gcc/cy_syslib_gcc.S")
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
    list(APPEND ALL_SRC_ASM_S "${PLATFORM_DIR}/target/psoc6/Device/Source/armclang/startup_ARMCM0P.s")
    list(APPEND ALL_SRC_ASM_NS "${PLATFORM_DIR}/target/psoc6/Device/Source/armclang/startup_ARMCM4.s")
    list(APPEND ALL_SRC_ASM_BL2 "${PLATFORM_DIR}/target/psoc6/Device/Source/armclang/startup_psoc6_bl2.s")
  elseif(CMAKE_C_COMPILER_ID STREQUAL "GNUARM")
    list(APPEND ALL_SRC_ASM_S "${PLATFORM_DIR}/target/psoc6/Device/Source/gcc/startup_ARMCM0P.S")
    list(APPEND ALL_SRC_ASM_NS "${PLATFORM_DIR}/target/psoc6/Device/Source/gcc/startup_ARMCM4.S")
    list(APPEND ALL_SRC_ASM_BL2 "${PLATFORM_DIR}/target/psoc6/Device/Source/gcc/startup_psoc6_bl2.S")
    set_property(SOURCE "${ALL_SRC_ASM_S}" "${ALL_SRC_ASM_NS}" "${ALL_SRC_ASM_BL2}" APPEND
      PROPERTY COMPILE_DEFINITIONS "__STARTUP_CLEAR_BSS_MULTIPLE" "__STARTUP_COPY_MULTIPLE")
  else()
    message(FATAL_ERROR "No startup file is available for compiler '${CMAKE_C_COMPILER_ID}'.")
  endif()
endif()

if (NOT DEFINED BUILD_TARGET_CFG)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_CFG (true|false) is undefined!")
elseif(BUILD_TARGET_CFG)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/target_cfg.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc6/spm_hal.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc6/attest_hal.c")
  list(APPEND ALL_SRC_C_S "${PLATFORM_DIR}/target/psoc6/tfm_platform_system.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/common" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_TARGET_HARDWARE_KEYS)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_HARDWARE_KEYS (true|false) is undefined!")
elseif(BUILD_TARGET_HARDWARE_KEYS)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/common/tfm_initial_attestation_key_material.c")
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/dummy_crypto_keys.c")
endif()

if (NOT DEFINED BUILD_TARGET_NV_COUNTERS)
  message(FATAL_ERROR "Configuration variable BUILD_TARGET_NV_COUNTERS (true|false) is undefined!")
elseif(BUILD_TARGET_NV_COUNTERS)
  # NOTE: This non-volatile counters implementation is a dummy
  #       implementation. Platform vendors have to implement the
  #       API ONLY if the target has non-volatile counters.
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/dummy_nv_counters.c")
  set(TARGET_NV_COUNTERS_ENABLE ON)
  # Sets SST_ROLLBACK_PROTECTION flag to compile in the SST services
  # rollback protection code as the target supports nv counters.
  set (SST_ROLLBACK_PROTECTION ON)
endif()

if (NOT DEFINED BUILD_CMSIS_DRIVERS)
  message(FATAL_ERROR "Configuration variable BUILD_CMSIS_DRIVERS (true|false) is undefined!")
elseif(BUILD_CMSIS_DRIVERS)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/CMSIS_Driver/Driver_USART.c")
  embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/CMSIS_Driver" ABSOLUTE)
  embedded_include_directories(PATH "${PLATFORM_DIR}/driver" ABSOLUTE)
endif()

if (NOT DEFINED BUILD_FLASH)
  message(FATAL_ERROR "Configuration variable BUILD_FLASH (true|false) is undefined!")
elseif(BUILD_FLASH)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/CMSIS_Driver/Driver_Flash.c")
  # As the SST area is going to be in RAM, it is required to set SST_CREATE_FLASH_LAYOUT
  # to be sure the SST service knows that when it starts the SST area does not contain any
  # valid SST flash layout and it needs to create one.
  set(SST_CREATE_FLASH_LAYOUT ON)
  embedded_include_directories(PATH "${PLATFORM_DIR}/target/psoc6/CMSIS_Driver" ABSOLUTE)
  embedded_include_directories(PATH "${PLATFORM_DIR}/driver" ABSOLUTE)
endif()

if (NOT BL2)
	message(STATUS "WARNING: BL2 is mandatory on target \"${TARGET_PLATFORM}\" Your choice was override.")
	set(BL2 True)
endif()

if (MCUBOOT_NO_SWAP)
	message (FATAL_ERROR "MCUBOOT_NO_SWAP configuration is not supported on " ${TARGET_PLATFORM})
endif()

if (NOT DEFINED BUILD_BOOT_SEED)
  message(FATAL_ERROR "Configuration variable BUILD_BOOT_SEED (true|false) is undefined!")
elseif(BUILD_BOOT_SEED)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/dummy_boot_seed.c")
endif()

if (NOT DEFINED BUILD_DEVICE_ID)
  message(FATAL_ERROR "Configuration variable BUILD_DEVICE_ID (true|false) is undefined!")
elseif(BUILD_DEVICE_ID)
  list(APPEND ALL_SRC_C "${PLATFORM_DIR}/target/psoc6/dummy_device_id.c")
endif()
