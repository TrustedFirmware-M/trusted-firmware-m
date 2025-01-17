/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PSA_API_VENEERS_COMMON_H__
#define __PSA_API_VENEERS_COMMON_H__

#if TFM_TZ_REENTRANCY_CHECK == 1
extern volatile bool ns_entry_flag_valid;

/*
 * This function 'tfm_psa_test_reentrancy_flag' ensures that NSPE has
 * successfully carried out a preventative step to avoid unexpected reentrancy
 * by calling tfm_ns_check_safe_entry & tfm_ns_check_exit.
 */
static inline void tfm_psa_test_reentrancy_flag(void)
{
    if (!ns_entry_flag_valid) {
        psa_panic();
    }
}

#define TFM_PSA_TEST_REENTRANCY_FLAG_v80 \
    " PUSH      {r1}                            \n" \
    " LDR       r1,=ns_entry_flag_valid         \n" \
    " LDRB      r1,[r1, #0]                     \n" \
    " UXTB      r1,r1                           \n" \
    " CMP       r1,#0                           \n" \
    " BEQ       psa_panic                       \n" \
    " POP       {r1}                            \n"

#endif

#endif /* __PSA_API_VENEERS_COMMON_H__ */
