;/*
; * Copyright (c) 2018-2019 ARM Limited
; *
; * Licensed under the Apache License, Version 2.0 (the "License");
; * you may not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; *     http://www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an "AS IS" BASIS,
; * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
; *
; *
; * This file is derivative of CMSIS V5.00 gcc_arm.ld
; */

/* Linker script to configure memory regions. */
/* This file will be run trough the pre-processor. */

#include "region_defs.h"

MEMORY
{
  FLASH   (rx)  : ORIGIN = S_CODE_START, LENGTH = S_CODE_SIZE
  RAM     (rwx) : ORIGIN = S_DATA_START, LENGTH = S_DATA_SIZE
  VENEERS (rx)  : ORIGIN = CMSE_VENEER_REGION_START, LENGTH = CMSE_VENEER_REGION_SIZE
}

__heap_size__  = S_HEAP_SIZE;
__psp_stack_size__ = S_PSP_STACK_SIZE;
__msp_init_stack_size__ = S_MSP_STACK_SIZE_INIT;

/* Library configurations */
GROUP(libgcc.a libc.a libm.a libnosys.a libc_nano.a)

ENTRY(Reset_Handler)

/*
 * The test service veneers may not be referenced in the secure binary so the
 * veneer objects are explicitly declared here as extern, so the linker includes
 * the veneers in the resulting binary.
 */
EXTERN(sst_test_service_veneer_setup)
EXTERN(tfm_secure_client_service_veneer_run_tests)

SECTIONS
{
    .TFM_VECTORS : ALIGN(4)
    {
        __vectors_start__ = .;
        KEEP(*(.vectors))
        *startup*(.text*)
        . = ALIGN(4);
        __vectors_end__ = .;
    } > FLASH

#if TFM_LVL == 1
    .copy.table : ALIGN(4)
    {
        __copy_table_start__ = .;
        LONG (LOADADDR(.TFM_DATA))
        LONG (ADDR(.TFM_DATA))
        LONG (SIZEOF(.TFM_DATA))
        __copy_table_end__ = .;
    } > FLASH

    .zero.table : ALIGN(4)
    {
        __zero_table_start__ = .;
        LONG (ADDR(.TFM_BSS))
        LONG (SIZEOF(.TFM_BSS))
        LONG (ADDR(.TFM_SECURE_STACK))
        LONG (SIZEOF(.TFM_SECURE_STACK))
        LONG (ADDR(.TFM_UNPRIV_SCRATCH))
        LONG (SIZEOF(.TFM_UNPRIV_SCRATCH))
        __zero_table_end__ = .;
    } > FLASH

#else /* TFM_LVL == 1 */
    .copy.table : ALIGN(4)
    {
        __copy_table_start__ = .;
        LONG (LOADADDR(.TFM_DATA))
        LONG (ADDR(.TFM_DATA))
        LONG (SIZEOF(.TFM_DATA))
        LONG (LOADADDR(.TFM_UNPRIV_RO_DATA))
        LONG (ADDR(.TFM_UNPRIV_RO_DATA))
        LONG (SIZEOF(.TFM_UNPRIV_RO_DATA))
        LONG (LOADADDR(.TFM_SP_STORAGE_DATA))
        LONG (ADDR(.TFM_SP_STORAGE_DATA))
        LONG (SIZEOF(.TFM_SP_STORAGE_DATA))
        LONG (LOADADDR(.TFM_SP_AUDIT_LOG_DATA))
        LONG (ADDR(.TFM_SP_AUDIT_LOG_DATA))
        LONG (SIZEOF(.TFM_SP_AUDIT_LOG_DATA))
        LONG (LOADADDR(.TFM_SP_CRYPTO_DATA))
        LONG (ADDR(.TFM_SP_CRYPTO_DATA))
        LONG (SIZEOF(.TFM_SP_CRYPTO_DATA))
        LONG (LOADADDR(.TFM_SP_PLATFORM_DATA))
        LONG (ADDR(.TFM_SP_PLATFORM_DATA))
        LONG (SIZEOF(.TFM_SP_PLATFORM_DATA))
        LONG (LOADADDR(.TFM_SP_INITIAL_ATTESTATION_DATA))
        LONG (ADDR(.TFM_SP_INITIAL_ATTESTATION_DATA))
        LONG (SIZEOF(.TFM_SP_INITIAL_ATTESTATION_DATA))
#ifdef TFM_PARTITION_TEST_CORE
        LONG (LOADADDR(.TFM_SP_CORE_TEST_DATA))
        LONG (ADDR(.TFM_SP_CORE_TEST_DATA))
        LONG (SIZEOF(.TFM_SP_CORE_TEST_DATA))
#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_CORE
        LONG (LOADADDR(.TFM_SP_CORE_TEST_2_DATA))
        LONG (ADDR(.TFM_SP_CORE_TEST_2_DATA))
        LONG (SIZEOF(.TFM_SP_CORE_TEST_2_DATA))
#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_SST
        LONG (LOADADDR(.TFM_SP_SST_TEST_PARTITION_DATA))
        LONG (ADDR(.TFM_SP_SST_TEST_PARTITION_DATA))
        LONG (SIZEOF(.TFM_SP_SST_TEST_PARTITION_DATA))
#endif /* TFM_PARTITION_TEST_SST */
#ifdef TFM_PARTITION_TEST_SECURE_SERVICES
        LONG (LOADADDR(.TFM_SP_SECURE_TEST_PARTITION_DATA))
        LONG (ADDR(.TFM_SP_SECURE_TEST_PARTITION_DATA))
        LONG (SIZEOF(.TFM_SP_SECURE_TEST_PARTITION_DATA))
#endif /* TFM_PARTITION_TEST_SECURE_SERVICES */
#ifdef TFM_PSA_API
        LONG (LOADADDR(.TFM_SP_IPC_SERVICE_TEST_DATA))
        LONG (ADDR(.TFM_SP_IPC_SERVICE_TEST_DATA))
        LONG (SIZEOF(.TFM_SP_IPC_SERVICE_TEST_DATA))
#endif /* TFM_PSA_API */
#ifdef TFM_PSA_API
        LONG (LOADADDR(.TFM_SP_IPC_CLIENT_TEST_DATA))
        LONG (ADDR(.TFM_SP_IPC_CLIENT_TEST_DATA))
        LONG (SIZEOF(.TFM_SP_IPC_CLIENT_TEST_DATA))
#endif /* TFM_PSA_API */
        __copy_table_end__ = .;
    } > FLASH

    .zero.table : ALIGN(4)
    {
        __zero_table_start__ = .;
        LONG (ADDR(.TFM_BSS))
        LONG (SIZEOF(.TFM_BSS))
        LONG (ADDR(.TFM_UNPRIV_RO_BSS))
        LONG (SIZEOF(.TFM_UNPRIV_RO_BSS))
        LONG (ADDR(.TFM_SP_STORAGE_BSS))
        LONG (SIZEOF(.TFM_SP_STORAGE_BSS))
        LONG (ADDR(.TFM_SP_STORAGE_STACK))
        LONG (SIZEOF(.TFM_SP_STORAGE_STACK))
        LONG (ADDR(.TFM_SP_AUDIT_LOG_BSS))
        LONG (SIZEOF(.TFM_SP_AUDIT_LOG_BSS))
        LONG (ADDR(.TFM_SP_AUDIT_LOG_STACK))
        LONG (SIZEOF(.TFM_SP_AUDIT_LOG_STACK))
        LONG (ADDR(.TFM_SP_CRYPTO_BSS))
        LONG (SIZEOF(.TFM_SP_CRYPTO_BSS))
        LONG (ADDR(.TFM_SP_CRYPTO_STACK))
        LONG (SIZEOF(.TFM_SP_CRYPTO_STACK))
        LONG (ADDR(.TFM_SP_PLATFORM_BSS))
        LONG (SIZEOF(.TFM_SP_PLATFORM_BSS))
        LONG (ADDR(.TFM_SP_PLATFORM_STACK))
        LONG (SIZEOF(.TFM_SP_PLATFORM_STACK))
        LONG (ADDR(.TFM_SP_INITIAL_ATTESTATION_BSS))
        LONG (SIZEOF(.TFM_SP_INITIAL_ATTESTATION_BSS))
        LONG (ADDR(.TFM_SP_INITIAL_ATTESTATION_STACK))
        LONG (SIZEOF(.TFM_SP_INITIAL_ATTESTATION_STACK))
#ifdef TFM_PARTITION_TEST_CORE
        LONG (ADDR(.TFM_SP_CORE_TEST_BSS))
        LONG (SIZEOF(.TFM_SP_CORE_TEST_BSS))
        LONG (ADDR(.TFM_SP_CORE_TEST_STACK))
        LONG (SIZEOF(.TFM_SP_CORE_TEST_STACK))
#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_CORE
        LONG (ADDR(.TFM_SP_CORE_TEST_2_BSS))
        LONG (SIZEOF(.TFM_SP_CORE_TEST_2_BSS))
        LONG (ADDR(.TFM_SP_CORE_TEST_2_STACK))
        LONG (SIZEOF(.TFM_SP_CORE_TEST_2_STACK))
#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_SST
        LONG (ADDR(.TFM_SP_SST_TEST_PARTITION_BSS))
        LONG (SIZEOF(.TFM_SP_SST_TEST_PARTITION_BSS))
        LONG (ADDR(.TFM_SP_SST_TEST_PARTITION_STACK))
        LONG (SIZEOF(.TFM_SP_SST_TEST_PARTITION_STACK))
#endif /* TFM_PARTITION_TEST_SST */
#ifdef TFM_PARTITION_TEST_SECURE_SERVICES
        LONG (ADDR(.TFM_SP_SECURE_TEST_PARTITION_BSS))
        LONG (SIZEOF(.TFM_SP_SECURE_TEST_PARTITION_BSS))
        LONG (ADDR(.TFM_SP_SECURE_TEST_PARTITION_STACK))
        LONG (SIZEOF(.TFM_SP_SECURE_TEST_PARTITION_STACK))
#endif /* TFM_PARTITION_TEST_SECURE_SERVICES */
#ifdef TFM_PSA_API
        LONG (ADDR(.TFM_SP_IPC_SERVICE_TEST_BSS))
        LONG (SIZEOF(.TFM_SP_IPC_SERVICE_TEST_BSS))
        LONG (ADDR(.TFM_SP_IPC_SERVICE_TEST_STACK))
        LONG (SIZEOF(.TFM_SP_IPC_SERVICE_TEST_STACK))
#endif /* TFM_PSA_API */
#ifdef TFM_PSA_API
        LONG (ADDR(.TFM_SP_IPC_CLIENT_TEST_BSS))
        LONG (SIZEOF(.TFM_SP_IPC_CLIENT_TEST_BSS))
        LONG (ADDR(.TFM_SP_IPC_CLIENT_TEST_STACK))
        LONG (SIZEOF(.TFM_SP_IPC_CLIENT_TEST_STACK))
#endif /* TFM_PSA_API */
        LONG (ADDR(.TFM_UNPRIV_SCRATCH))
        LONG (SIZEOF(.TFM_UNPRIV_SCRATCH))
        __zero_table_end__ = .;
    } > FLASH

    .TFM_UNPRIV_CODE : ALIGN(32)
    {
        *libc_nano*:*(.text*)
        *libc_nano*:*(.rodata*)
        *tfm_spm_services.o(.text*)
        *tfm_spm_services.o(.rodata*)
        *dummy_crypto_keys.o(.text*)
        *dummy_crypto_keys.o(.rodata*)
        *dummy_nv_counters.o(.text*)
        *dummy_nv_counters.o(.rodata*)
        *dummy_boot_seed.o(.text*)
        *dummy_boot_seed.o(.rodata*)
        *dummy_device_id.o(.text*)
        *dummy_device_id.o(.rodata*)
        *platform_retarget_dev.o(.text*)
        *platform_retarget_dev.o(.rodata*)
        *(SFN)
        *libgcc*:*(.text*)
        *libgcc*:*(.rodata*)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_UNPRIV_CODE$$RO$$Base = ADDR(.TFM_UNPRIV_CODE);
    Image$$TFM_UNPRIV_CODE$$RO$$Limit = ADDR(.TFM_UNPRIV_CODE) + SIZEOF(.TFM_UNPRIV_CODE);

    .TFM_SP_STORAGE : ALIGN(32)
    {
        *tfm_storage*:*(.text*)
        *tfm_storage*:*(.rodata*)
        *(TFM_SP_STORAGE_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_STORAGE$$RO$$Base = ADDR(.TFM_SP_STORAGE);
    Image$$TFM_SP_STORAGE$$RO$$Limit = ADDR(.TFM_SP_STORAGE) + SIZEOF(.TFM_SP_STORAGE);
    Image$$TFM_SP_STORAGE$$Base = ADDR(.TFM_SP_STORAGE);
    Image$$TFM_SP_STORAGE$$Limit = ADDR(.TFM_SP_STORAGE) + SIZEOF(.TFM_SP_STORAGE);

    .TFM_SP_AUDIT_LOG : ALIGN(32)
    {
        *tfm_audit*:*(.text*)
        *tfm_audit*:*(.rodata*)
        *(TFM_SP_AUDIT_LOG_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_AUDIT_LOG$$RO$$Base = ADDR(.TFM_SP_AUDIT_LOG);
    Image$$TFM_SP_AUDIT_LOG$$RO$$Limit = ADDR(.TFM_SP_AUDIT_LOG) + SIZEOF(.TFM_SP_AUDIT_LOG);
    Image$$TFM_SP_AUDIT_LOG$$Base = ADDR(.TFM_SP_AUDIT_LOG);
    Image$$TFM_SP_AUDIT_LOG$$Limit = ADDR(.TFM_SP_AUDIT_LOG) + SIZEOF(.TFM_SP_AUDIT_LOG);

    .TFM_SP_CRYPTO : ALIGN(32)
    {
        *tfm_crypto*:*(.text*)
        *tfm_crypto*:*(.rodata*)
        *(TFM_SP_CRYPTO_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_CRYPTO$$RO$$Base = ADDR(.TFM_SP_CRYPTO);
    Image$$TFM_SP_CRYPTO$$RO$$Limit = ADDR(.TFM_SP_CRYPTO) + SIZEOF(.TFM_SP_CRYPTO);
    Image$$TFM_SP_CRYPTO$$Base = ADDR(.TFM_SP_CRYPTO);
    Image$$TFM_SP_CRYPTO$$Limit = ADDR(.TFM_SP_CRYPTO) + SIZEOF(.TFM_SP_CRYPTO);

    .TFM_SP_PLATFORM : ALIGN(32)
    {
        *tfm_platform*:*(.text*)
        *tfm_platform*:*(.rodata*)
        *(TFM_SP_PLATFORM_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_PLATFORM$$RO$$Base = ADDR(.TFM_SP_PLATFORM);
    Image$$TFM_SP_PLATFORM$$RO$$Limit = ADDR(.TFM_SP_PLATFORM) + SIZEOF(.TFM_SP_PLATFORM);
    Image$$TFM_SP_PLATFORM$$Base = ADDR(.TFM_SP_PLATFORM);
    Image$$TFM_SP_PLATFORM$$Limit = ADDR(.TFM_SP_PLATFORM) + SIZEOF(.TFM_SP_PLATFORM);

    .TFM_SP_INITIAL_ATTESTATION : ALIGN(32)
    {
        *tfm_attest*:*(.text*)
        *tfm_attest*:*(.rodata*)
        *(TFM_SP_INITIAL_ATTESTATION_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_INITIAL_ATTESTATION$$RO$$Base = ADDR(.TFM_SP_INITIAL_ATTESTATION);
    Image$$TFM_SP_INITIAL_ATTESTATION$$RO$$Limit = ADDR(.TFM_SP_INITIAL_ATTESTATION) + SIZEOF(.TFM_SP_INITIAL_ATTESTATION);
    Image$$TFM_SP_INITIAL_ATTESTATION$$Base = ADDR(.TFM_SP_INITIAL_ATTESTATION);
    Image$$TFM_SP_INITIAL_ATTESTATION$$Limit = ADDR(.TFM_SP_INITIAL_ATTESTATION) + SIZEOF(.TFM_SP_INITIAL_ATTESTATION);

#ifdef TFM_PARTITION_TEST_CORE
    .TFM_SP_CORE_TEST : ALIGN(32)
    {
        *tfm_ss_core_test.*(.text*)
        *tfm_ss_core_test.*(.rodata*)
        *(TFM_SP_CORE_TEST_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_CORE_TEST$$RO$$Base = ADDR(.TFM_SP_CORE_TEST);
    Image$$TFM_SP_CORE_TEST$$RO$$Limit = ADDR(.TFM_SP_CORE_TEST) + SIZEOF(.TFM_SP_CORE_TEST);
    Image$$TFM_SP_CORE_TEST$$Base = ADDR(.TFM_SP_CORE_TEST);
    Image$$TFM_SP_CORE_TEST$$Limit = ADDR(.TFM_SP_CORE_TEST) + SIZEOF(.TFM_SP_CORE_TEST);

#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_CORE
    .TFM_SP_CORE_TEST_2 : ALIGN(32)
    {
        *tfm_ss_core_test_2.*(.text*)
        *tfm_ss_core_test_2.*(.rodata*)
        *(TFM_SP_CORE_TEST_2_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_CORE_TEST_2$$RO$$Base = ADDR(.TFM_SP_CORE_TEST_2);
    Image$$TFM_SP_CORE_TEST_2$$RO$$Limit = ADDR(.TFM_SP_CORE_TEST_2) + SIZEOF(.TFM_SP_CORE_TEST_2);
    Image$$TFM_SP_CORE_TEST_2$$Base = ADDR(.TFM_SP_CORE_TEST_2);
    Image$$TFM_SP_CORE_TEST_2$$Limit = ADDR(.TFM_SP_CORE_TEST_2) + SIZEOF(.TFM_SP_CORE_TEST_2);

#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_SST
    .TFM_SP_SST_TEST_PARTITION : ALIGN(32)
    {
        *sst_test_service.*(.text*)
        *sst_test_service.*(.rodata*)
        *(TFM_SP_SST_TEST_PARTITION_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_SST_TEST_PARTITION$$RO$$Base = ADDR(.TFM_SP_SST_TEST_PARTITION);
    Image$$TFM_SP_SST_TEST_PARTITION$$RO$$Limit = ADDR(.TFM_SP_SST_TEST_PARTITION) + SIZEOF(.TFM_SP_SST_TEST_PARTITION);
    Image$$TFM_SP_SST_TEST_PARTITION$$Base = ADDR(.TFM_SP_SST_TEST_PARTITION);
    Image$$TFM_SP_SST_TEST_PARTITION$$Limit = ADDR(.TFM_SP_SST_TEST_PARTITION) + SIZEOF(.TFM_SP_SST_TEST_PARTITION);

#endif /* TFM_PARTITION_TEST_SST */
#ifdef TFM_PARTITION_TEST_SECURE_SERVICES
    .TFM_SP_SECURE_TEST_PARTITION : ALIGN(32)
    {
        *tfm_secure_client_service.*(.text*)
        *test_framework*(.text*)
        *uart_stdout.*(.text*)
        *Driver_USART.*(.text*)
        *arm_uart_drv.*(.text*)
        *uart_pl011_drv.*(.text*)
        *secure_suites.*(.text*)
        *attestation_s_interface_testsuite.*(.text*)
        *tfm_secure_client_service.*(.rodata*)
        *test_framework*(.rodata*)
        *uart_stdout.*(.rodata*)
        *Driver_USART.*(.rodata*)
        *arm_uart_drv.*(.rodata*)
        *uart_pl011_drv.*(.rodata*)
        *secure_suites.*(.rodata*)
        *attestation_s_interface_testsuite.*(.rodata*)
        *(TFM_SP_SECURE_TEST_PARTITION_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_SECURE_TEST_PARTITION$$RO$$Base = ADDR(.TFM_SP_SECURE_TEST_PARTITION);
    Image$$TFM_SP_SECURE_TEST_PARTITION$$RO$$Limit = ADDR(.TFM_SP_SECURE_TEST_PARTITION) + SIZEOF(.TFM_SP_SECURE_TEST_PARTITION);
    Image$$TFM_SP_SECURE_TEST_PARTITION$$Base = ADDR(.TFM_SP_SECURE_TEST_PARTITION);
    Image$$TFM_SP_SECURE_TEST_PARTITION$$Limit = ADDR(.TFM_SP_SECURE_TEST_PARTITION) + SIZEOF(.TFM_SP_SECURE_TEST_PARTITION);

#endif /* TFM_PARTITION_TEST_SECURE_SERVICES */
#ifdef TFM_PSA_API
    .TFM_SP_IPC_SERVICE_TEST : ALIGN(32)
    {
        *ipc_service_test*:*(.text*)
        *ipc_service_test*:*(.rodata*)
        *(TFM_SP_IPC_SERVICE_TEST_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_IPC_SERVICE_TEST$$RO$$Base = ADDR(.TFM_SP_IPC_SERVICE_TEST);
    Image$$TFM_SP_IPC_SERVICE_TEST$$RO$$Limit = ADDR(.TFM_SP_IPC_SERVICE_TEST) + SIZEOF(.TFM_SP_IPC_SERVICE_TEST);
    Image$$TFM_SP_IPC_SERVICE_TEST$$Base = ADDR(.TFM_SP_IPC_SERVICE_TEST);
    Image$$TFM_SP_IPC_SERVICE_TEST$$Limit = ADDR(.TFM_SP_IPC_SERVICE_TEST) + SIZEOF(.TFM_SP_IPC_SERVICE_TEST);

#endif /* TFM_PSA_API */
#ifdef TFM_PSA_API
    .TFM_SP_IPC_CLIENT_TEST : ALIGN(32)
    {
        *ipc_client_test*:*(.text*)
        *ipc_client_test*:*(.rodata*)
        *(TFM_SP_IPC_CLIENT_TEST_ATTR_FN)
        . = ALIGN(32);
    } > FLASH
    Image$$TFM_SP_IPC_CLIENT_TEST$$RO$$Base = ADDR(.TFM_SP_IPC_CLIENT_TEST);
    Image$$TFM_SP_IPC_CLIENT_TEST$$RO$$Limit = ADDR(.TFM_SP_IPC_CLIENT_TEST) + SIZEOF(.TFM_SP_IPC_CLIENT_TEST);
    Image$$TFM_SP_IPC_CLIENT_TEST$$Base = ADDR(.TFM_SP_IPC_CLIENT_TEST);
    Image$$TFM_SP_IPC_CLIENT_TEST$$Limit = ADDR(.TFM_SP_IPC_CLIENT_TEST) + SIZEOF(.TFM_SP_IPC_CLIENT_TEST);

#endif /* TFM_PSA_API */

    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > FLASH
    __exidx_end = .;

#endif /* TFM_LVL == 1 */

    .ER_TFM_CODE :
    {
        *(.text*)

        KEEP(*(.init))
        KEEP(*(.fini))


        /* .ctors */
        *crtbegin.o(.ctors)
        *crtbegin?.o(.ctors)
        *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
        *(SORT(.ctors.*))
        *(.ctors)

        /* .dtors */
         *crtbegin.o(.dtors)
         *crtbegin?.o(.dtors)
         *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
         *(SORT(.dtors.*))
         *(.dtors)

        *(.rodata*)

        KEEP(*(.eh_frame*))
    } > FLASH

    /* shared_data and msp_stack are overlapping on purpose when
     * msp_stack is extended until the beginning of RAM, when shared_date
     * was read out by partitions
     */
    .tfm_bl2_shared_data : ALIGN(32)
    {
        . += BOOT_TFM_SHARED_DATA_SIZE;
    } > RAM AT> FLASH

    .msp_stack : ALIGN(32)
    {
        . += __msp_init_stack_size__;
    } > RAM AT> FLASH
    Image$$ARM_LIB_STACK_MSP$$ZI$$Limit = ADDR(.msp_stack) + SIZEOF(.msp_stack);

    .psp_stack : ALIGN(32)
    {
        . += __psp_stack_size__;
    } > RAM AT> FLASH
    Image$$ARM_LIB_STACK$$ZI$$Base = ADDR(.psp_stack);
    Image$$ARM_LIB_STACK$$ZI$$Limit = ADDR(.psp_stack) + SIZEOF(.psp_stack);

#if TFM_LVL == 1

    .TFM_SECURE_STACK : ALIGN(128)
    {
        . += 0x2000;
    } > RAM AT> FLASH
    Image$$TFM_SECURE_STACK$$ZI$$Base = ADDR(.TFM_SECURE_STACK);
    Image$$TFM_SECURE_STACK$$ZI$$Limit = ADDR(.TFM_SECURE_STACK) + SIZEOF(.TFM_SECURE_STACK);

    .TFM_UNPRIV_SCRATCH : ALIGN(32)
    {
        . += 0x400;
    } > RAM AT> FLASH
    Image$$TFM_UNPRIV_SCRATCH$$ZI$$Base = ADDR(.TFM_UNPRIV_SCRATCH);
    Image$$TFM_UNPRIV_SCRATCH$$ZI$$Limit = ADDR(.TFM_UNPRIV_SCRATCH) + SIZEOF(.TFM_UNPRIV_SCRATCH);

    .heap : ALIGN(8)
    {
        __end__ = .;
        PROVIDE(end = .);
        __HeapBase = .;
        . += __heap_size__;
        __HeapLimit = .;
        __heap_limit = .; /* Add for _sbrk */
    } > RAM AT> FLASH
#else /* TFM_LVL == 1 */
    .TFM_UNPRIV_RO_DATA :
    {
        */tfm_spm_services.o(.data*)
        */dummy_crypto_keys.o(.data*)
        */dummy_nv_counters.o(.data*)
        */dummy_boot_seed.o(.data*)
        */dummy_device_id.o(.data*)
        */platform_retarget_dev.o(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_UNPRIV_RO_DATA$$RW$$Base = ADDR(.TFM_UNPRIV_RO_DATA);
    Image$$TFM_UNPRIV_RO_DATA$$RW$$Limit = ADDR(.TFM_UNPRIV_RO_DATA) + SIZEOF(.TFM_UNPRIV_RO_DATA);

    .TFM_UNPRIV_RO_BSS : ALIGN(32)
    {
        */tfm_spm_services.o(.bss*)
        */platform_retarget_dev.o(.bss*)
        */dummy_crypto_keys.o(.bss*)
        */dummy_nv_counters.o(.bss*)
        */dummy_boot_seed.o(.bss*)
        */dummy_device_id.o(.bss*)
        */tfm_spm_services.o(COMMON)
        */platform_retarget_dev.o(COMMON)
        */dummy_crypto_keys.o(COMMON)
        */dummy_nv_counters.o(COMMON)
        */dummy_boot_seed.o(COMMON)
        */dummy_device_id.o(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_UNPRIV_RO_DATA$$ZI$$Base = ADDR(.TFM_UNPRIV_RO_BSS);
    Image$$TFM_UNPRIV_RO_DATA$$ZI$$Limit = ADDR(.TFM_UNPRIV_RO_BSS) + SIZEOF(.TFM_UNPRIV_RO_BSS);

    .TFM_UNPRIV_SCRATCH : ALIGN(32)
    {
        . += 0x400;
    } > RAM AT> FLASH
    Image$$TFM_UNPRIV_SCRATCH$$ZI$$Base = ADDR(.TFM_UNPRIV_SCRATCH);
    Image$$TFM_UNPRIV_SCRATCH$$ZI$$Limit = ADDR(.TFM_UNPRIV_SCRATCH) + SIZEOF(.TFM_UNPRIV_SCRATCH);

    .TFM_SP_STORAGE_DATA : ALIGN(32)
    {
        *tfm_storage*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_STORAGE_DATA$$RW$$Base = ADDR(.TFM_SP_STORAGE_DATA);
    Image$$TFM_SP_STORAGE_DATA$$RW$$Limit = ADDR(.TFM_SP_STORAGE_DATA) + SIZEOF(.TFM_SP_STORAGE_DATA);

    .TFM_SP_STORAGE_BSS : ALIGN(32)
    {
        *tfm_storage*:*(.bss*)
        *tfm_storage*:*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_STORAGE_DATA$$ZI$$Base = ADDR(.TFM_SP_STORAGE_BSS);
    Image$$TFM_SP_STORAGE_DATA$$ZI$$Limit = ADDR(.TFM_SP_STORAGE_BSS) + SIZEOF(.TFM_SP_STORAGE_BSS);

    .TFM_SP_STORAGE_STACK : ALIGN(128)
    {
        . += 0x2000;
    } > RAM AT> FLASH
    Image$$TFM_SP_STORAGE_STACK$$ZI$$Base = ADDR(.TFM_SP_STORAGE_STACK);
    Image$$TFM_SP_STORAGE_STACK$$ZI$$Limit = ADDR(.TFM_SP_STORAGE_STACK) + SIZEOF(.TFM_SP_STORAGE_STACK);

    .TFM_SP_AUDIT_LOG_DATA : ALIGN(32)
    {
        *tfm_audit*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_AUDIT_LOG_DATA$$RW$$Base = ADDR(.TFM_SP_AUDIT_LOG_DATA);
    Image$$TFM_SP_AUDIT_LOG_DATA$$RW$$Limit = ADDR(.TFM_SP_AUDIT_LOG_DATA) + SIZEOF(.TFM_SP_AUDIT_LOG_DATA);

    .TFM_SP_AUDIT_LOG_BSS : ALIGN(32)
    {
        *tfm_audit*:*(.bss*)
        *tfm_audit*:*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_AUDIT_LOG_DATA$$ZI$$Base = ADDR(.TFM_SP_AUDIT_LOG_BSS);
    Image$$TFM_SP_AUDIT_LOG_DATA$$ZI$$Limit = ADDR(.TFM_SP_AUDIT_LOG_BSS) + SIZEOF(.TFM_SP_AUDIT_LOG_BSS);

    .TFM_SP_AUDIT_LOG_STACK : ALIGN(128)
    {
        . += 0x1000;
    } > RAM AT> FLASH
    Image$$TFM_SP_AUDIT_LOG_STACK$$ZI$$Base = ADDR(.TFM_SP_AUDIT_LOG_STACK);
    Image$$TFM_SP_AUDIT_LOG_STACK$$ZI$$Limit = ADDR(.TFM_SP_AUDIT_LOG_STACK) + SIZEOF(.TFM_SP_AUDIT_LOG_STACK);

    .TFM_SP_CRYPTO_DATA : ALIGN(32)
    {
        *tfm_crypto*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_CRYPTO_DATA$$RW$$Base = ADDR(.TFM_SP_CRYPTO_DATA);
    Image$$TFM_SP_CRYPTO_DATA$$RW$$Limit = ADDR(.TFM_SP_CRYPTO_DATA) + SIZEOF(.TFM_SP_CRYPTO_DATA);

    .TFM_SP_CRYPTO_BSS : ALIGN(32)
    {
        *tfm_crypto*:*(.bss*)
        *tfm_crypto*:*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_CRYPTO_DATA$$ZI$$Base = ADDR(.TFM_SP_CRYPTO_BSS);
    Image$$TFM_SP_CRYPTO_DATA$$ZI$$Limit = ADDR(.TFM_SP_CRYPTO_BSS) + SIZEOF(.TFM_SP_CRYPTO_BSS);

    .TFM_SP_CRYPTO_STACK : ALIGN(128)
    {
        . += 0x2000;
    } > RAM AT> FLASH
    Image$$TFM_SP_CRYPTO_STACK$$ZI$$Base = ADDR(.TFM_SP_CRYPTO_STACK);
    Image$$TFM_SP_CRYPTO_STACK$$ZI$$Limit = ADDR(.TFM_SP_CRYPTO_STACK) + SIZEOF(.TFM_SP_CRYPTO_STACK);

    .TFM_SP_PLATFORM_DATA : ALIGN(32)
    {
        *tfm_platform*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_PLATFORM_DATA$$RW$$Base = ADDR(.TFM_SP_PLATFORM_DATA);
    Image$$TFM_SP_PLATFORM_DATA$$RW$$Limit = ADDR(.TFM_SP_PLATFORM_DATA) + SIZEOF(.TFM_SP_PLATFORM_DATA);

    .TFM_SP_PLATFORM_BSS : ALIGN(32)
    {
        *tfm_platform*:*(.bss*)
        *tfm_platform*:*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_PLATFORM_DATA$$ZI$$Base = ADDR(.TFM_SP_PLATFORM_BSS);
    Image$$TFM_SP_PLATFORM_DATA$$ZI$$Limit = ADDR(.TFM_SP_PLATFORM_BSS) + SIZEOF(.TFM_SP_PLATFORM_BSS);

    .TFM_SP_PLATFORM_STACK : ALIGN(128)
    {
        . += 0x0400;
    } > RAM AT> FLASH
    Image$$TFM_SP_PLATFORM_STACK$$ZI$$Base = ADDR(.TFM_SP_PLATFORM_STACK);
    Image$$TFM_SP_PLATFORM_STACK$$ZI$$Limit = ADDR(.TFM_SP_PLATFORM_STACK) + SIZEOF(.TFM_SP_PLATFORM_STACK);

    .TFM_SP_INITIAL_ATTESTATION_DATA : ALIGN(32)
    {
        *tfm_attest*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_INITIAL_ATTESTATION_DATA$$RW$$Base = ADDR(.TFM_SP_INITIAL_ATTESTATION_DATA);
    Image$$TFM_SP_INITIAL_ATTESTATION_DATA$$RW$$Limit = ADDR(.TFM_SP_INITIAL_ATTESTATION_DATA) + SIZEOF(.TFM_SP_INITIAL_ATTESTATION_DATA);

    .TFM_SP_INITIAL_ATTESTATION_BSS : ALIGN(32)
    {
        *tfm_attest*:*(.bss*)
        *tfm_attest*:*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_INITIAL_ATTESTATION_DATA$$ZI$$Base = ADDR(.TFM_SP_INITIAL_ATTESTATION_BSS);
    Image$$TFM_SP_INITIAL_ATTESTATION_DATA$$ZI$$Limit = ADDR(.TFM_SP_INITIAL_ATTESTATION_BSS) + SIZEOF(.TFM_SP_INITIAL_ATTESTATION_BSS);

    .TFM_SP_INITIAL_ATTESTATION_STACK : ALIGN(128)
    {
        . += 0x0400;
    } > RAM AT> FLASH
    Image$$TFM_SP_INITIAL_ATTESTATION_STACK$$ZI$$Base = ADDR(.TFM_SP_INITIAL_ATTESTATION_STACK);
    Image$$TFM_SP_INITIAL_ATTESTATION_STACK$$ZI$$Limit = ADDR(.TFM_SP_INITIAL_ATTESTATION_STACK) + SIZEOF(.TFM_SP_INITIAL_ATTESTATION_STACK);

#ifdef TFM_PARTITION_TEST_CORE
    .TFM_SP_CORE_TEST_DATA : ALIGN(32)
    {
        *tfm_ss_core_test.*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_CORE_TEST_DATA$$RW$$Base = ADDR(.TFM_SP_CORE_TEST_DATA);
    Image$$TFM_SP_CORE_TEST_DATA$$RW$$Limit = ADDR(.TFM_SP_CORE_TEST_DATA) + SIZEOF(.TFM_SP_CORE_TEST_DATA);

    .TFM_SP_CORE_TEST_BSS : ALIGN(32)
    {
        *tfm_ss_core_test.*(.bss*)
        *tfm_ss_core_test.*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_CORE_TEST_DATA$$ZI$$Base = ADDR(.TFM_SP_CORE_TEST_BSS);
    Image$$TFM_SP_CORE_TEST_DATA$$ZI$$Limit = ADDR(.TFM_SP_CORE_TEST_BSS) + SIZEOF(.TFM_SP_CORE_TEST_BSS);

    .TFM_SP_CORE_TEST_STACK : ALIGN(128)
    {
        . += 0x0400;
    } > RAM AT> FLASH
    Image$$TFM_SP_CORE_TEST_STACK$$ZI$$Base = ADDR(.TFM_SP_CORE_TEST_STACK);
    Image$$TFM_SP_CORE_TEST_STACK$$ZI$$Limit = ADDR(.TFM_SP_CORE_TEST_STACK) + SIZEOF(.TFM_SP_CORE_TEST_STACK);

#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_CORE
    .TFM_SP_CORE_TEST_2_DATA : ALIGN(32)
    {
        *tfm_ss_core_test_2.*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_CORE_TEST_2_DATA$$RW$$Base = ADDR(.TFM_SP_CORE_TEST_2_DATA);
    Image$$TFM_SP_CORE_TEST_2_DATA$$RW$$Limit = ADDR(.TFM_SP_CORE_TEST_2_DATA) + SIZEOF(.TFM_SP_CORE_TEST_2_DATA);

    .TFM_SP_CORE_TEST_2_BSS : ALIGN(32)
    {
        *tfm_ss_core_test_2.*(.bss*)
        *tfm_ss_core_test_2.*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_CORE_TEST_2_DATA$$ZI$$Base = ADDR(.TFM_SP_CORE_TEST_2_BSS);
    Image$$TFM_SP_CORE_TEST_2_DATA$$ZI$$Limit = ADDR(.TFM_SP_CORE_TEST_2_BSS) + SIZEOF(.TFM_SP_CORE_TEST_2_BSS);

    .TFM_SP_CORE_TEST_2_STACK : ALIGN(128)
    {
        . += 0x0400;
    } > RAM AT> FLASH
    Image$$TFM_SP_CORE_TEST_2_STACK$$ZI$$Base = ADDR(.TFM_SP_CORE_TEST_2_STACK);
    Image$$TFM_SP_CORE_TEST_2_STACK$$ZI$$Limit = ADDR(.TFM_SP_CORE_TEST_2_STACK) + SIZEOF(.TFM_SP_CORE_TEST_2_STACK);

#endif /* TFM_PARTITION_TEST_CORE */
#ifdef TFM_PARTITION_TEST_SST
    .TFM_SP_SST_TEST_PARTITION_DATA : ALIGN(32)
    {
        *sst_test_service.*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_SST_TEST_PARTITION_DATA$$RW$$Base = ADDR(.TFM_SP_SST_TEST_PARTITION_DATA);
    Image$$TFM_SP_SST_TEST_PARTITION_DATA$$RW$$Limit = ADDR(.TFM_SP_SST_TEST_PARTITION_DATA) + SIZEOF(.TFM_SP_SST_TEST_PARTITION_DATA);

    .TFM_SP_SST_TEST_PARTITION_BSS : ALIGN(32)
    {
        *sst_test_service.*(.bss*)
        *sst_test_service.*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_SST_TEST_PARTITION_DATA$$ZI$$Base = ADDR(.TFM_SP_SST_TEST_PARTITION_BSS);
    Image$$TFM_SP_SST_TEST_PARTITION_DATA$$ZI$$Limit = ADDR(.TFM_SP_SST_TEST_PARTITION_BSS) + SIZEOF(.TFM_SP_SST_TEST_PARTITION_BSS);

    .TFM_SP_SST_TEST_PARTITION_STACK : ALIGN(128)
    {
        . += 0x0400;
    } > RAM AT> FLASH
    Image$$TFM_SP_SST_TEST_PARTITION_STACK$$ZI$$Base = ADDR(.TFM_SP_SST_TEST_PARTITION_STACK);
    Image$$TFM_SP_SST_TEST_PARTITION_STACK$$ZI$$Limit = ADDR(.TFM_SP_SST_TEST_PARTITION_STACK) + SIZEOF(.TFM_SP_SST_TEST_PARTITION_STACK);

#endif /* TFM_PARTITION_TEST_SST */
#ifdef TFM_PARTITION_TEST_SECURE_SERVICES
    .TFM_SP_SECURE_TEST_PARTITION_DATA : ALIGN(32)
    {
        *tfm_secure_client_service.*(.data*)
        *test_framework*(.data*)
        *uart_stdout.*(.data*)
        *Driver_USART.*(.data*)
        *arm_uart_drv.*(.data*)
        *uart_pl011_drv.*(.data*)
        *secure_suites.*(.data*)
        *attestation_s_interface_testsuite.*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_SECURE_TEST_PARTITION_DATA$$RW$$Base = ADDR(.TFM_SP_SECURE_TEST_PARTITION_DATA);
    Image$$TFM_SP_SECURE_TEST_PARTITION_DATA$$RW$$Limit = ADDR(.TFM_SP_SECURE_TEST_PARTITION_DATA) + SIZEOF(.TFM_SP_SECURE_TEST_PARTITION_DATA);

    .TFM_SP_SECURE_TEST_PARTITION_BSS : ALIGN(32)
    {
        *tfm_secure_client_service.*(.bss*)
        *test_framework*(.bss*)
        *uart_stdout.*(.bss*)
        *Driver_USART.*(.bss*)
        *arm_uart_drv.*(.bss*)
        *uart_pl011_drv.*(.bss*)
        *secure_suites.*(.bss*)
        *attestation_s_interface_testsuite.*(.bss*)
        *tfm_secure_client_service.*(COMMON)
        *test_framework*(COMMON)
        *uart_stdout.*(COMMON)
        *Driver_USART.*(COMMON)
        *arm_uart_drv.*(COMMON)
        *uart_pl011_drv.*(COMMON)
        *secure_suites.*(COMMON)
        *attestation_s_interface_testsuite.*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_SECURE_TEST_PARTITION_DATA$$ZI$$Base = ADDR(.TFM_SP_SECURE_TEST_PARTITION_BSS);
    Image$$TFM_SP_SECURE_TEST_PARTITION_DATA$$ZI$$Limit = ADDR(.TFM_SP_SECURE_TEST_PARTITION_BSS) + SIZEOF(.TFM_SP_SECURE_TEST_PARTITION_BSS);

    .TFM_SP_SECURE_TEST_PARTITION_STACK : ALIGN(128)
    {
        . += 0x1000;
    } > RAM AT> FLASH
    Image$$TFM_SP_SECURE_TEST_PARTITION_STACK$$ZI$$Base = ADDR(.TFM_SP_SECURE_TEST_PARTITION_STACK);
    Image$$TFM_SP_SECURE_TEST_PARTITION_STACK$$ZI$$Limit = ADDR(.TFM_SP_SECURE_TEST_PARTITION_STACK) + SIZEOF(.TFM_SP_SECURE_TEST_PARTITION_STACK);

#endif /* TFM_PARTITION_TEST_SECURE_SERVICES */
#ifdef TFM_PSA_API
    .TFM_SP_IPC_SERVICE_TEST_DATA : ALIGN(32)
    {
        *ipc_service_test*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_IPC_SERVICE_TEST_DATA$$RW$$Base = ADDR(.TFM_SP_IPC_SERVICE_TEST_DATA);
    Image$$TFM_SP_IPC_SERVICE_TEST_DATA$$RW$$Limit = ADDR(.TFM_SP_IPC_SERVICE_TEST_DATA) + SIZEOF(.TFM_SP_IPC_SERVICE_TEST_DATA);

    .TFM_SP_IPC_SERVICE_TEST_BSS : ALIGN(32)
    {
        *ipc_service_test*:*(.bss*)
        *ipc_service_test*:*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_IPC_SERVICE_TEST_DATA$$ZI$$Base = ADDR(.TFM_SP_IPC_SERVICE_TEST_BSS);
    Image$$TFM_SP_IPC_SERVICE_TEST_DATA$$ZI$$Limit = ADDR(.TFM_SP_IPC_SERVICE_TEST_BSS) + SIZEOF(.TFM_SP_IPC_SERVICE_TEST_BSS);

    .TFM_SP_IPC_SERVICE_TEST_STACK : ALIGN(128)
    {
        . += 0x1000;
    } > RAM AT> FLASH
    Image$$TFM_SP_IPC_SERVICE_TEST_STACK$$ZI$$Base = ADDR(.TFM_SP_IPC_SERVICE_TEST_STACK);
    Image$$TFM_SP_IPC_SERVICE_TEST_STACK$$ZI$$Limit = ADDR(.TFM_SP_IPC_SERVICE_TEST_STACK) + SIZEOF(.TFM_SP_IPC_SERVICE_TEST_STACK);

#endif /* TFM_PSA_API */
#ifdef TFM_PSA_API
    .TFM_SP_IPC_CLIENT_TEST_DATA : ALIGN(32)
    {
        *ipc_client_test*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_IPC_CLIENT_TEST_DATA$$RW$$Base = ADDR(.TFM_SP_IPC_CLIENT_TEST_DATA);
    Image$$TFM_SP_IPC_CLIENT_TEST_DATA$$RW$$Limit = ADDR(.TFM_SP_IPC_CLIENT_TEST_DATA) + SIZEOF(.TFM_SP_IPC_CLIENT_TEST_DATA);

    .TFM_SP_IPC_CLIENT_TEST_BSS : ALIGN(32)
    {
        *ipc_client_test*:*(.bss*)
        *ipc_client_test*:*(COMMON)
        . = ALIGN(32);
    } > RAM AT> FLASH
    Image$$TFM_SP_IPC_CLIENT_TEST_DATA$$ZI$$Base = ADDR(.TFM_SP_IPC_CLIENT_TEST_BSS);
    Image$$TFM_SP_IPC_CLIENT_TEST_DATA$$ZI$$Limit = ADDR(.TFM_SP_IPC_CLIENT_TEST_BSS) + SIZEOF(.TFM_SP_IPC_CLIENT_TEST_BSS);

    .TFM_SP_IPC_CLIENT_TEST_STACK : ALIGN(128)
    {
        . += 0x1000;
    } > RAM AT> FLASH
    Image$$TFM_SP_IPC_CLIENT_TEST_STACK$$ZI$$Base = ADDR(.TFM_SP_IPC_CLIENT_TEST_STACK);
    Image$$TFM_SP_IPC_CLIENT_TEST_STACK$$ZI$$Limit = ADDR(.TFM_SP_IPC_CLIENT_TEST_STACK) + SIZEOF(.TFM_SP_IPC_CLIENT_TEST_STACK);

#endif /* TFM_PSA_API */

    .TFM_SP_SECURE_TEST_PARTITION_DATA : ALIGN(32)
    {
        *libc_nano*:*(.data*)
        . = ALIGN(32);
    } > RAM AT> FLASH

    .TFM_SP_SECURE_TEST_PARTITION_BSS : ALIGN(32)
    {
        /* FixMe:
         * Test framework use printf to print out test result. Implementation of
         * printf in GCC libc use static data and heap as well. To be able to
         * execute test suites with TFM_LVL=3 this workaround is needed to
         * allocate libc static data and heap within the data section of secure
         * test partition. This can be removed if test service will be executed
         * in privileged mode.
         */
        *libc_nano*:*(.bss*)
        *libc_nano*:*(COMMON)

        __end__ = .;
        PROVIDE(end = .);
        __HeapBase = .;
        . += __heap_size__;
        __HeapLimit = .;
        __heap_limit = .; /* Add for _sbrk */

        . = ALIGN(32);
    } > RAM AT> FLASH
#endif /* TFM_LVL == 1 */

    .TFM_DATA :
    {
        *(.data*)

        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP(*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);

        . = ALIGN(4);
        /* init data */
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);

        . = ALIGN(4);
        /* finit data */
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);

        KEEP(*(.jcr*))
        . = ALIGN(4);

    } > RAM AT> FLASH
    Image$$TFM_DATA$$RW$$Base = ADDR(.TFM_DATA);
    Image$$TFM_DATA$$RW$$Limit = ADDR(.TFM_DATA) + SIZEOF(.TFM_DATA);

    .TFM_BSS : ALIGN(4)
    {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM AT> FLASH
    Image$$TFM_DATA$$ZI$$Base = ADDR(.TFM_BSS);
    Image$$TFM_DATA$$ZI$$Limit = ADDR(.TFM_BSS) + SIZEOF(.TFM_BSS);

    Image$$ER_TFM_DATA$$Base = ADDR(.TFM_DATA);
    Image$$ER_TFM_DATA$$Limit = ADDR(.TFM_DATA) + SIZEOF(.TFM_DATA) + SIZEOF(.TFM_BSS);

    /*
     * Place the CMSE Veneers (containing the SG instruction) after the code, in a
     * separate 32 bytes aligned region so that the SAU can programmed to just set
     * this region as Non-Secure Callable.
     */
    .gnu.sgstubs : ALIGN(32)
    {
        *(.gnu.sgstubs*)
        . = ALIGN(32);
    } > VENEERS AT> VENEERS
    Load$$LR$$LR_VENEER$$Base = ADDR(.gnu.sgstubs);
    Load$$LR$$LR_VENEER$$Limit = ADDR(.gnu.sgstubs) + SIZEOF(.gnu.sgstubs);

    Load$$LR$$LR_NS_PARTITION$$Base = NS_PARTITION_START;

#ifdef BL2
    Load$$LR$$LR_SECONDARY_PARTITION$$Base = SECONDARY_PARTITION_START;
#endif /* BL2 */

    PROVIDE(__stack = Image$$ARM_LIB_STACK$$ZI$$Limit);
}
