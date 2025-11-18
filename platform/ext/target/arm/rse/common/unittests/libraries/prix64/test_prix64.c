/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "prix64.h"

#include "unity.h"

void test_prix64a_null(void)
{
    char *s;

    s = prix64a(NULL, 0u, UINT64_C(0));
    TEST_ASSERT_EQUAL(s, NULL);
}

void test_prix64a_buffer_sizes(void)
{
    size_t size;

    /*
     * The following loop covers buffer sizes 0 through (PRIX64_SIZE + 1)
     * *inclusive*, meaning (PRIX64_SIZE + 2) test cases.
     */
    for (size = 0u; size < (PRIX64_SIZE + 2u); size++) {
        char buffer[PRIX64_SIZE + 1u];
        int cmp;
        static const char expected[PRIX64_SIZE + 2u][PRIX64_SIZE + 1u] = {
            ".......................",  /* 0: no characters written */
            "\0......................", /* 1: truncated */
            "0\0.....................",
            "0x\0....................",
            "0xF\0...................",
            "0xFE\0..................",
            "0xFED\0.................",
            "0xFEDC\0................",
            "0xFEDC_\0...............",
            "0xFEDC_B\0..............",
            "0xFEDC_BA\0.............",
            "0xFEDC_BA9\0............",
            "0xFEDC_BA98\0...........",
            "0xFEDC_BA98_\0..........",
            "0xFEDC_BA98_7\0.........",
            "0xFEDC_BA98_76\0........",
            "0xFEDC_BA98_765\0.......",
            "0xFEDC_BA98_7654\0......",
            "0xFEDC_BA98_7654_\0.....",
            "0xFEDC_BA98_7654_3\0....",
            "0xFEDC_BA98_7654_32\0...",
            "0xFEDC_BA98_7654_321\0..", /* PRIX64_SIZE - 1: truncated */
            "0xFEDC_BA98_7654_3210\0.", /* PRIX64_SIZE    : exact size match */
            "0xFEDC_BA98_7654_3210\0.", /* PRIX64_SIZE + 1: room left over */
        };

        memset(buffer, '.', PRIX64_SIZE + 1u);
        cmp = memcmp(prix64a(buffer, size, UINT64_C(0xFEDCBA9876543210)),
                     expected[size], PRIX64_SIZE + 1u);
        TEST_ASSERT_EQUAL(cmp, 0);
    }
}

void test_prix64_0123456789ABCDEF(void)
{
    prix64_t buffer;
    int cmp;

    cmp = strcmp(prix64(&buffer, UINT64_C(0x0123456789ABCDEF)),
                 "0x0123_4567_89AB_CDEF");
    TEST_ASSERT_EQUAL(cmp, 0);
}

void test_prix64_00030007000B000F(void)
{
    prix64_t buffer;
    int cmp;

    cmp = strcmp(prix64(&buffer, UINT64_C(0x00030007000B000F)),
                 "0x0003_0007_000B_000F");
    TEST_ASSERT_EQUAL(cmp, 0);
}
