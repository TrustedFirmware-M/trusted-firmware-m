/*
 * Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/**
 * \file config.h
 *
 * \brief Configuration options (set of defines)
 *
 *  This set of compile-time options may be used to enable
 *  or disable features selectively, and reduce the global
 *  memory footprint.
 */

#ifndef PROFILE_S_MBEDTLS_CONFIG_H
#define PROFILE_S_MBEDTLS_CONFIG_H

#include "config_tfm.h"

#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
#define _CRT_SECURE_NO_DEPRECATE 1
#endif

/**
 * \name SECTION: System support
 *
 * This section sets system specific settings.
 * \{
 */

/**
 * \def MBEDTLS_HAVE_ASM
 *
 * The compiler has support for asm().
 *
 * Requires support for asm() in compiler.
 *
 * Used in:
 *      library/aria.c
 *      library/timing.c
 *      include/mbedtls/bn_mul.h
 *
 * Required by:
 *      MBEDTLS_AESNI_C
 *      MBEDTLS_PADLOCK_C
 *
 * Comment to disable the use of assembly code.
 */
#define MBEDTLS_HAVE_ASM

/**
 * \def MBEDTLS_PLATFORM_MEMORY
 *
 * Enable the memory allocation layer.
 *
 * By default mbed TLS uses the system-provided calloc() and free().
 * This allows different allocators (self-implemented or provided) to be
 * provided to the platform abstraction layer.
 *
 * Enabling MBEDTLS_PLATFORM_MEMORY without the
 * MBEDTLS_PLATFORM_{FREE,CALLOC}_MACROs will provide
 * "mbedtls_platform_set_calloc_free()" allowing you to set an alternative calloc() and
 * free() function pointer at runtime.
 *
 * Enabling MBEDTLS_PLATFORM_MEMORY and specifying
 * MBEDTLS_PLATFORM_{CALLOC,FREE}_MACROs will allow you to specify the
 * alternate function at compile time.
 *
 * Requires: MBEDTLS_PLATFORM_C
 *
 * Enable this layer to allow use of alternative memory allocators.
 */
#define MBEDTLS_PLATFORM_MEMORY

/* \} name SECTION: System support */

/**
 * \name SECTION: mbed TLS feature support
 *
 * This section sets support for features that are or are not needed
 * within the modules that are enabled.
 * \{
 */

/**
 * \def MBEDTLS_AES_ROM_TABLES
 *
 * Use precomputed AES tables stored in ROM.
 *
 * Uncomment this macro to use precomputed AES tables stored in ROM.
 * Comment this macro to generate AES tables in RAM at runtime.
 *
 * Tradeoff: Using precomputed ROM tables reduces RAM usage by ~8kb
 * (or ~2kb if \c MBEDTLS_AES_FEWER_TABLES is used) and reduces the
 * initialization time before the first AES operation can be performed.
 * It comes at the cost of additional ~8kb ROM use (resp. ~2kb if \c
 * MBEDTLS_AES_FEWER_TABLES below is used), and potentially degraded
 * performance if ROM access is slower than RAM access.
 *
 * This option is independent of \c MBEDTLS_AES_FEWER_TABLES.
 *
 */
#define MBEDTLS_AES_ROM_TABLES

/**
 * \def MBEDTLS_AES_FEWER_TABLES
 *
 * Use less ROM/RAM for AES tables.
 *
 * Uncommenting this macro omits 75% of the AES tables from
 * ROM / RAM (depending on the value of \c MBEDTLS_AES_ROM_TABLES)
 * by computing their values on the fly during operations
 * (the tables are entry-wise rotations of one another).
 *
 * Tradeoff: Uncommenting this reduces the RAM / ROM footprint
 * by ~6kb but at the cost of more arithmetic operations during
 * runtime. Specifically, one has to compare 4 accesses within
 * different tables to 4 accesses with additional arithmetic
 * operations within the same table. The performance gain/loss
 * depends on the system and memory details.
 *
 * This option is independent of \c MBEDTLS_AES_ROM_TABLES.
 *
 */
#define MBEDTLS_AES_FEWER_TABLES

/**
 * \def MBEDTLS_NO_PLATFORM_ENTROPY
 *
 * Do not use built-in platform entropy functions.
 * This is useful if your platform does not support
 * standards like the /dev/urandom or Windows CryptoAPI.
 *
 * Uncomment this macro to disable the built-in platform entropy functions.
 */
#define MBEDTLS_NO_PLATFORM_ENTROPY

/**
 * \def MBEDTLS_ENTROPY_NV_SEED
 *
 * Enable the non-volatile (NV) seed file-based entropy source.
 * (Also enables the NV seed read/write functions in the platform layer)
 *
 * This is crucial (if not required) on systems that do not have a
 * cryptographic entropy source (in hardware or kernel) available.
 *
 * Requires: MBEDTLS_ENTROPY_C, MBEDTLS_PLATFORM_C
 *
 * \note The read/write functions that are used by the entropy source are
 *       determined in the platform layer, and can be modified at runtime and/or
 *       compile-time depending on the flags (MBEDTLS_PLATFORM_NV_SEED_*) used.
 *
 * \note If you use the default implementation functions that read a seedfile
 *       with regular fopen(), please make sure you make a seedfile with the
 *       proper name (defined in MBEDTLS_PLATFORM_STD_NV_SEED_FILE) and at
 *       least MBEDTLS_ENTROPY_BLOCK_SIZE bytes in size that can be read from
 *       and written to or you will get an entropy source error! The default
 *       implementation will only use the first MBEDTLS_ENTROPY_BLOCK_SIZE
 *       bytes from the file.
 *
 * \note The entropy collector will write to the seed file before entropy is
 *       given to an external source, to update it.
 */
#define MBEDTLS_ENTROPY_NV_SEED

/**
 * \def MBEDTLS_SHA256_SMALLER
 *
 * Enable an implementation of SHA-256 that has lower ROM footprint but also
 * lower performance.
 *
 * The default implementation is meant to be a reasonnable compromise between
 * performance and size. This version optimizes more aggressively for size at
 * the expense of performance. Eg on Cortex-M4 it reduces the size of
 * mbedtls_sha256_process() from ~2KB to ~0.5KB for a performance hit of about
 * 30%.
 *
 * Uncomment to enable the smaller implementation of SHA256.
 */
#define MBEDTLS_SHA256_SMALLER

/**
 * \def MBEDTLS_PSA_ASSUME_EXCLUSIVE_BUFFERS
 *
 * Assume all buffers passed to PSA functions are owned exclusively by the
 * PSA function and are not stored in shared memory.
 *
 * This option may be enabled if all buffers passed to any PSA function reside
 * in memory that is accessible only to the PSA function during its execution.
 *
 * This option MUST be disabled whenever buffer arguments are in memory shared
 * with an untrusted party, for example where arguments to PSA calls are passed
 * across a trust boundary.
 *
 * \note Enabling this option reduces memory usage and code size.
 *
 * \note Enabling this option causes overlap of input and output buffers
 *       not to be supported by PSA functions.
 */
#define MBEDTLS_PSA_ASSUME_EXCLUSIVE_BUFFERS

/**
 * \def MBEDTLS_PSA_CRYPTO_CONFIG
 *
 * This setting allows support for cryptographic mechanisms through the PSA
 * API to be configured separately from support through the mbedtls API.
 *
 * When this option is disabled, the PSA API exposes the cryptographic
 * mechanisms that can be implemented on top of the `mbedtls_xxx` API
 * configured with `MBEDTLS_XXX` symbols.
 *
 * When this option is enabled, the PSA API exposes the cryptographic
 * mechanisms requested by the `PSA_WANT_XXX` symbols defined in
 * include/psa/crypto_config.h. The corresponding `MBEDTLS_XXX` settings are
 * automatically enabled if required (i.e. if no PSA driver provides the
 * mechanism). You may still freely enable additional `MBEDTLS_XXX` symbols
 * in mbedtls_config.h.
 *
 * If the symbol #MBEDTLS_PSA_CRYPTO_CONFIG_FILE is defined, it specifies
 * an alternative header to include instead of include/psa/crypto_config.h.
 *
 * This feature is still experimental and is not ready for production since
 * it is not completed.
 */
#define MBEDTLS_PSA_CRYPTO_CONFIG

/* \} name SECTION: mbed TLS feature support */

/**
 * \name SECTION: mbed TLS modules
 *
 * This section enables or disables entire modules in mbed TLS
 * \{
 */

/**
 * \def MBEDTLS_AES_C
 *
 * Enable the AES block cipher.
 *
 * Module:  library/aes.c
 * Caller:  library/cipher.c
 *          library/pem.c
 *          library/ctr_drbg.c
 *
 * This module is required to support the TLS ciphersuites that use the AES
 * cipher.
 *
 * PEM_PARSE uses AES for decrypting encrypted keys.
 */
#define MBEDTLS_AES_C

/**
 * \def MBEDTLS_AES_ONLY_128_BIT_KEY_LENGTH
 *
 * Use only 128-bit keys in AES operations to save ROM.
 *
 * Uncomment this macro to remove support for AES operations that use 192-
 * or 256-bit keys.
 *
 * Uncommenting this macro reduces the size of AES code by ~300 bytes
 * on v8-M/Thumb2.
 *
 * Module:  library/aes.c
 *
 * Requires: MBEDTLS_AES_C
 */
#define MBEDTLS_AES_ONLY_128_BIT_KEY_LENGTH

/**
 * \def MBEDTLS_CIPHER_C
 *
 * Enable the generic cipher layer.
 *
 * Module:  library/cipher.c
 *
 * Uncomment to enable generic cipher wrappers.
 */
#define MBEDTLS_CIPHER_C

/**
 * \def MBEDTLS_CTR_DRBG_C
 *
 * Enable the CTR_DRBG AES-based random generator.
 * The CTR_DRBG generator uses AES-256 by default.
 * To use AES-128 instead, enable MBEDTLS_CTR_DRBG_USE_128_BIT_KEY below.
 *
 * Module:  library/ctr_drbg.c
 * Caller:
 *
 * Requires: MBEDTLS_AES_C
 *
 * This module provides the CTR_DRBG AES random number generator.
 */
#define MBEDTLS_CTR_DRBG_C

/**
 * \def MBEDTLS_ENTROPY_C
 *
 * Enable the platform-specific entropy code.
 *
 * Module:  library/entropy.c
 * Caller:
 *
 * Requires: MBEDTLS_SHA512_C or MBEDTLS_SHA256_C
 *
 * This module provides a generic entropy pool
 */
#define MBEDTLS_ENTROPY_C

/**
 * \def MBEDTLS_HKDF_C
 *
 * Enable the HKDF algorithm (RFC 5869).
 *
 * Module:  library/hkdf.c
 * Caller:
 *
 * Requires: MBEDTLS_MD_C
 *
 * This module adds support for the Hashed Message Authentication Code
 * (HMAC)-based key derivation function (HKDF).
 */
//#define MBEDTLS_HKDF_C /* Used for HUK deriviation */

/**
 * \def MBEDTLS_MD_C
 *
 * Enable the generic message digest layer.
 *
 * Module:  library/md.c
 * Caller:
 *
 * Uncomment to enable generic message digest wrappers.
 */
//#define MBEDTLS_MD_C

/**
 * \def MBEDTLS_MEMORY_BUFFER_ALLOC_C
 *
 * Enable the buffer allocator implementation that makes use of a (stack)
 * based buffer to 'allocate' dynamic memory. (replaces calloc() and free()
 * calls)
 *
 * Module:  library/memory_buffer_alloc.c
 *
 * Requires: MBEDTLS_PLATFORM_C
 *           MBEDTLS_PLATFORM_MEMORY (to use it within mbed TLS)
 *
 * Enable this module to enable the buffer memory allocator.
 */
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C

/**
 * \def MBEDTLS_PLATFORM_C
 *
 * Enable the platform abstraction layer that allows you to re-assign
 * functions like calloc(), free(), snprintf(), printf(), fprintf(), exit().
 *
 * Enabling MBEDTLS_PLATFORM_C enables to use of MBEDTLS_PLATFORM_XXX_ALT
 * or MBEDTLS_PLATFORM_XXX_MACRO directives, allowing the functions mentioned
 * above to be specified at runtime or compile time respectively.
 *
 * \note This abstraction layer must be enabled on Windows (including MSYS2)
 * as other module rely on it for a fixed snprintf implementation.
 *
 * Module:  library/platform.c
 * Caller:  Most other .c files
 *
 * This module enables abstraction of common (libc) functions.
 */
#define MBEDTLS_PLATFORM_C

#define MBEDTLS_PLATFORM_NO_STD_FUNCTIONS
#define MBEDTLS_PLATFORM_STD_MEM_HDR   <stdlib.h>

#include <stdio.h>

#define MBEDTLS_PLATFORM_SNPRINTF_MACRO      snprintf
#define MBEDTLS_PLATFORM_PRINTF_ALT
#define MBEDTLS_PLATFORM_STD_EXIT_SUCCESS  EXIT_SUCCESS
#define MBEDTLS_PLATFORM_STD_EXIT_FAILURE  EXIT_FAILURE

/**
 * \def MBEDTLS_PSA_CRYPTO_C
 *
 * Enable the Platform Security Architecture cryptography API.
 *
 * Module:  library/psa_crypto.c
 *
 * Requires: MBEDTLS_CTR_DRBG_C, MBEDTLS_ENTROPY_C
 *
 */
#define MBEDTLS_PSA_CRYPTO_C

/**
 * \def MBEDTLS_PSA_CRYPTO_STORAGE_C
 *
 * Enable the Platform Security Architecture persistent key storage.
 *
 * Module:  library/psa_crypto_storage.c
 *
 * Requires: MBEDTLS_PSA_CRYPTO_C,
 *           either MBEDTLS_PSA_ITS_FILE_C or a native implementation of
 *           the PSA ITS interface
 */
#define MBEDTLS_PSA_CRYPTO_STORAGE_C

/**
 * \def MBEDTLS_PSA_CRYPTO_SPM
 *
 * When MBEDTLS_PSA_CRYPTO_SPM is defined, the code is built for SPM (Secure
 * Partition Manager) integration which separates the code into two parts: a
 * NSPE (Non-Secure Process Environment) and an SPE (Secure Process
 * Environment).
 *
 * If you enable this option, your build environment must include a header
 * file `"crypto_spe.h"` (either in the `psa` subdirectory of the Mbed TLS
 * header files, or in another directory on the compiler's include search
 * path). Alternatively, your platform may customize the header
 * `psa/crypto_platform.h`, in which case it can skip or replace the
 * inclusion of `"crypto_spe.h"`.
 *
 * Module:  library/psa_crypto.c
 * Requires: MBEDTLS_PSA_CRYPTO_C
 *
 */
#define MBEDTLS_PSA_CRYPTO_SPM

/* MBEDTLS_PSA_CRYPTO_KEY_ID_ENCODES_OWNER
 *
 * Enable key identifiers that encode a key owner identifier.
 *
 * The owner of a key is identified by a value of type ::mbedtls_key_owner_id_t
 * which is currently hard-coded to be int32_t.
 *
 * Note that this option is meant for internal use only and may be removed
 * without notice.
 */
#define MBEDTLS_PSA_CRYPTO_KEY_ID_ENCODES_OWNER

/** \def MBEDTLS_PSA_CRYPTO_BUILTIN_KEYS
 *
 * Enable support for platform built-in keys. If you enable this feature,
 * you must implement the function mbedtls_psa_platform_get_builtin_key().
 * See the documentation of that function for more information.
 *
 * Built-in keys are typically derived from a hardware unique key or
 * stored in a secure element.
 *
 * Requires: MBEDTLS_PSA_CRYPTO_C.
 *
 * \warning This interface is experimental and may change or be removed
 * without notice.
 */
#define MBEDTLS_PSA_CRYPTO_BUILTIN_KEYS

/* \} name SECTION: mbed TLS modules */

/**
 * \name SECTION: General configuration options
 *
 * This section contains Mbed TLS build settings that are not associated
 * with a particular module.
 *
 * \{
 */

/**
 * \def MBEDTLS_CONFIG_FILE
 *
 * If defined, this is a header which will be included instead of
 * `"mbedtls/mbedtls_config.h"`.
 * This header file specifies the compile-time configuration of Mbed TLS.
 * Unlike other configuration options, this one must be defined on the
 * compiler command line: a definition in `mbedtls_config.h` would have
 * no effect.
 *
 * This macro is expanded after an <tt>\#include</tt> directive. This is a popular but
 * non-standard feature of the C language, so this feature is only available
 * with compilers that perform macro expansion on an <tt>\#include</tt> line.
 *
 * The value of this symbol is typically a path in double quotes, either
 * absolute or relative to a directory on the include search path.
 */
//#define MBEDTLS_CONFIG_FILE "mbedtls/mbedtls_config.h"

/**
 * \def MBEDTLS_USER_CONFIG_FILE
 *
 * If defined, this is a header which will be included after
 * `"mbedtls/mbedtls_config.h"` or #MBEDTLS_CONFIG_FILE.
 * This allows you to modify the default configuration, including the ability
 * to undefine options that are enabled by default.
 *
 * This macro is expanded after an <tt>\#include</tt> directive. This is a popular but
 * non-standard feature of the C language, so this feature is only available
 * with compilers that perform macro expansion on an <tt>\#include</tt> line.
 *
 * The value of this symbol is typically a path in double quotes, either
 * absolute or relative to a directory on the include search path.
 */
//#define MBEDTLS_USER_CONFIG_FILE "/dev/null"

/**
 * \def MBEDTLS_PSA_CRYPTO_CONFIG_FILE
 *
 * If defined, this is a header which will be included instead of
 * `"psa/crypto_config.h"`.
 * This header file specifies which cryptographic mechanisms are available
 * through the PSA API when #MBEDTLS_PSA_CRYPTO_CONFIG is enabled, and
 * is not used when #MBEDTLS_PSA_CRYPTO_CONFIG is disabled.
 *
 * This macro is expanded after an <tt>\#include</tt> directive. This is a popular but
 * non-standard feature of the C language, so this feature is only available
 * with compilers that perform macro expansion on an <tt>\#include</tt> line.
 *
 * The value of this symbol is typically a path in double quotes, either
 * absolute or relative to a directory on the include search path.
 */
//#define MBEDTLS_PSA_CRYPTO_CONFIG_FILE "psa/crypto_config.h"

/**
 * \def MBEDTLS_PSA_CRYPTO_USER_CONFIG_FILE
 *
 * If defined, this is a header which will be included after
 * `"psa/crypto_config.h"` or #MBEDTLS_PSA_CRYPTO_CONFIG_FILE.
 * This allows you to modify the default configuration, including the ability
 * to undefine options that are enabled by default.
 *
 * This macro is expanded after an <tt>\#include</tt> directive. This is a popular but
 * non-standard feature of the C language, so this feature is only available
 * with compilers that perform macro expansion on an <tt>\#include</tt> line.
 *
 * The value of this symbol is typically a path in double quotes, either
 * absolute or relative to a directory on the include search path.
 */
//#define MBEDTLS_PSA_CRYPTO_USER_CONFIG_FILE "/dev/null"

/** \} name SECTION: General configuration options */

#if CRYPTO_NV_SEED
#include "tfm_mbedcrypto_config_extra_nv_seed.h"
#endif /* CRYPTO_NV_SEED */

#if !defined(CRYPTO_HW_ACCELERATOR) && defined(MBEDTLS_ENTROPY_NV_SEED)
#include "mbedtls_entropy_nv_seed_config.h"
#endif

#ifdef CRYPTO_HW_ACCELERATOR
#include "mbedtls_accelerator_config.h"
#endif

#endif /* PROFILE_S_MBEDTLS_CONFIG_H */
