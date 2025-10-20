/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * Notes:
 * - The AHBM APB registers are gated by the CryptoCell DMA clock. If that clock
 *   is disabled, writes to the AHBM APB registers are silently ignored.
 *
 * - The AHBM can issue single or INCR4 burst transactions. The CryptoCell AHBM
 *   issues INCR4 bursts when the following conditions are met, otherwise,
 *   singles are used:
 *     - Singles not forced:         ahb.ahbm_singles == 0
 *     - Cacheability enabled:       ahb.ahbm_hprot[3] == 1 (CACHEABLE)
 *     - Access aligned to 4 words.
 *
 *   Whether a burst is actually observed on the system bus is platform-specific;
 *   downstream bridges (e.g., AHB<->AHB/AXI) may silently convert bursts to singles.
 */

#ifndef CC3XX_AHBM_H__
#define CC3XX_AHBM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------- */
/* Transaction mode (ahb.ahbm_singles)                                        */
/* -------------------------------------------------------------------------- */

/**
 * @brief Transaction type configured by ahb.ahbm_singles.
 */
#define CC3XX_AHBM_BURST_INCR4_TRANSACTIONS  (0x0u)
#define CC3XX_AHBM_SINGLE_TRANSACTIONS       (0x1u)

/* -------------------------------------------------------------------------- */
/* Security attribute (ahb.ahbm_hwnonsec)                                     */
/* -------------------------------------------------------------------------- */

/**
 * @brief Transaction security attribute controlled by ahb.ahbm_hwnonsec.
 */
#define CC3XX_AHBM_SECURE_TRANSACTIONS       (0x0u)
#define CC3XX_AHBM_NONSECURE_TRANSACTIONS    (0x1u)

/* -------------------------------------------------------------------------- */
/* HPROT attributes (ahb.ahbm_hprot)                                          */
/* -------------------------------------------------------------------------- */
/*
 * Bit meanings per AMBA 5 AHB:
 *   HPROT[0] : 0 = Opcode fetch,       1 = Data Access
 *   HPROT[1] : 0 = User,               1 = Privileged
 *   HPROT[2] : 0 = Non-bufferable,     1 = Bufferable
 *   HPROT[3] : 0 = Non-cacheable,      1 = Cacheable (modifiable)
 */

#define CC3XX_AHBM_HPROT_INSTR               (0u << 0)
#define CC3XX_AHBM_HPROT_DATA                (1u << 0)

#define CC3XX_AHBM_HPROT_USER                (0u << 1)
#define CC3XX_AHBM_HPROT_PRIVILEGED          (1u << 1)

#define CC3XX_AHBM_HPROT_NON_BUFFERABLE      (0u << 2)
#define CC3XX_AHBM_HPROT_BUFFERABLE          (1u << 2)

#define CC3XX_AHBM_HPROT_NON_CACHEABLE       (0u << 3)
#define CC3XX_AHBM_HPROT_CACHEABLE           (1u << 3)

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_AHBM_H__ */
