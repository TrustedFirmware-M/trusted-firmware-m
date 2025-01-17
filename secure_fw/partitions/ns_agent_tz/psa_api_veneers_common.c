/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stdint.h>

#include "config_impl.h"
#include "security_defs.h"
#include "tfm_arch.h"
#include "tfm_psa_call_pack.h"

#include "psa/client.h"

#include "cmsis_compiler.h"
#include "compiler_ext_defs.h"

#include "tfm_ns_interface.h"

/*
 * Here we assume that the system is set in such way that reentrancy is not
 * configured to generate a SecureFault by the hardware via SCB_CCR_TRD.
 * This is only supported for Armv8.1-M.
 *
 * If the chosen architecture is not Armv8.1-M, then the TRD bit is RES 0.
 *
 * The reentrancy test flag mechanism works as follow:
 * SET:
 * the flag is successfully set if all the following apply:
 *  - not already set
 *  - neither the integrity signature nor the stack seal is found at the top of
 *    the stack, which means that the entry via SG is a genuine attempt from
 *    NSPE.
 * CLEAR:
 * the flag is successfully cleared if the following applies:
 *  - the flag was previously set
 *
 * There are two cases of reentrance to check:
 *  1. Secure State execution, initiated via TZ agent; then attempt to reenter
 *     via TZ.
 *     The stack to be checked is the TZ one, thus should contain the
 *     STACK_SEAL_PATTERN, otherwise we know that secure state was under way
 *     already.
 *  2. Secure State execution, via mailbox for example; then attempt to reenter
 *     via TZ.
 *     The stack to be checked belongs to whatever service was running, thus
 *     will not contain the STACK_SEAL_PATTERN. If there was an exception
 *     causing the stack switch to be saved, then its top will contain the
 *     integrity signature, placed by the v8-M architecture (Armv8.0-M onward).
 */
volatile bool ns_entry_flag_valid;

/*
 * The expected value for Integrity Signature is in the range [31:1], bit 0 is
 * for Stack Frame Type Check (SFTC).
 */
#define S_STACK_INTEGRITY_SIGN 0xFEFA125A

__tz_naked_veneer
int32_t tfm_ns_check_safe_entry_veneer(void)
{
    __ASM volatile(
        SYNTAX_UNIFIED
        " PUSH      {r1,r2}                         \n"

        " LDR       r1,=ns_entry_flag_valid         \n"
        " LDRB      r1,[r1, #0]                     \n"
        " UXTB      r1,r1                           \n"
        " CMP       r1,#1                           \n"
        " BNE       test_for_re_enter               \n"

        "flag_already_set:                          \n"
        " MOVS      r2,#1                           \n" /* flag = true */
        " MVN       r0,#0                           \n" /* -1, BUSY */
        " B exit                                    \n"

        "test_for_re_enter:                         \n" /* case (1) */
        " MRS       r1,PSP                          \n"
        " LDR       r1,[r1,#12]                     \n"
        " LDR       r2,="M2S(STACK_SEAL_PATTERN)"   \n"
        " CMP       r1,r2                           \n"
        " BEQ       valid_enter                     \n"

        /*
         * If the top of the S stack contains the Integrity Signature, then it's
         * an invalid attempt for NS caller to reenter into Secure State.
         */
        "test_for_re_enter2:                        \n" /* case (2) */
        " MRS       r1,PSP                          \n"
        " LDR       r1,[r1,#8]                      \n"

        " BIC       r1,r1,#1                        \n" /* ignore SFTC */
        " LDR       r2,="M2S(S_STACK_INTEGRITY_SIGN)"   \n"
        " EORS      r1,r1,r2                        \n"
        " CMP       r1,#1                           \n"
        " BLS       invalid_enter_attempt           \n"

        "valid_enter:                               \n"
        " MOVS      r2,#1                           \n" /* flag = true */
        " MOVS      r0,#0                           \n"
        " B exit                                    \n"

        "invalid_enter_attempt:                     \n"
        " MOVS      r2,#0                           \n" /* flag = false */
        " MVN       r0,#1                           \n" /* -2, RE_ENTER */

        "exit:                                      \n"
        " LDR       r1,=ns_entry_flag_valid         \n"
        " STRB      r2,[r1,#0]                      \n" /* flag = <t/f> */

        " POP       {r1,r2}                         \n"
        " BXNS      lr                              \n"
    );
}

__tz_c_veneer
int32_t tfm_ns_check_exit_veneer(void)
{
    if (!ns_entry_flag_valid) {
        return TFM_REENTRANCY_CHECK_ERR_FLAG_STATUS;
    }

    ns_entry_flag_valid = false;
    return TFM_REENTRANCY_CHECK_SUCCESS;
}
