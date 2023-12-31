/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rss_provisioning_bundle.h"

const struct cm_provisioning_data data = {
    /* BL1_2_IMAGE_HASH */
    {},
    /* BL1_2_IMAGE */
    {},
    /* DMA ICS */
    {},
    /* SCP data */
    {},
    /* RSS_ID */
    0,
    /* SAM config placeholder */
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x1F,
        0xF9, 0x9F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x1F,
        0x88, 0x88, 0x88, 0x28, 0x88, 0x88, 0x88, 0x88,
        0x80, 0x00, 0x00, 0x88, 0x88, 0x88, 0x80, 0x08,
        0x00, 0x08, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,

        /* This is the integrity check value, it must equal the zero count of
         * the rest of the SAM config.
         */
        0x00, 0x00, 0x02, 0x7C,
    },
    /* GUK */
    {
        0x01, 0x23, 0x45, 0x67, 0x89, 0x01, 0x23, 0x45,
        0x67, 0x89, 0x01, 0x23, 0x45, 0x67, 0x89, 0x01,
        0x23, 0x45, 0x67, 0x89, 0x01, 0x23, 0x45, 0x67,
        0x89, 0x01, 0x23, 0x45, 0x67, 0x89, 0x01, 0x23,
    },
    /* CCA system properties placeholder */
    0xDEADBEEF,
};
