/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_PLATFORM_CONFIG_H
#define IFX_PLATFORM_CONFIG_H

/* In this file must be placed config options that are individual for EPC2 */

#define IFX_PSE84_EPC2

/* ATTEST_TOKEN_PROFILE_PSA_2_0_0 is used by default for EPC2 */
#undef ATTEST_TOKEN_PROFILE_PSA_IOT_1
#undef ATTEST_TOKEN_PROFILE_PSA_2_0_0
#undef ATTEST_TOKEN_PROFILE_ARM_CCA
#define ATTEST_TOKEN_PROFILE_PSA_2_0_0         1

/*
 * Use default implementation of crypto keys derivation
 * for Protected Storage
 */
#define PS_DEFAULT_CRYPTO_CONFIG               1

#if (IFX_CM33_NS_PRESENT && (IFX_CM55_NS_PRESENT && !IFX_MTB_MAILBOX)) || TEST_NS_IFX_IRQ_TEST_MASKED
/* Run the scheduler after handling a secure interrupt if the NSPE was pre-empted */
#define CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED             1
/* Mask Non-Secure interrupts when executing in secure state.
 * This option reduces latency for TF-M calls from the CM55 NSPE. */
#define CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT          1
#else
/* Do not run the scheduler after handling a secure interrupt if the NSPE was pre-empted */
#define CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED             0
/* Do not mask Non-Secure interrupts when executing in secure state. */
#define CONFIG_TFM_SECURE_THREAD_MASK_NS_INTERRUPT          0
#endif

#endif /* IFX_PLATFORM_CONFIG_H */
