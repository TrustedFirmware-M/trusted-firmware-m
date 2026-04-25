/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * @file a shim layer for the actual contents of cmsis_compiler.h that
 *       are required in this unit test. This avoid pulling the entire
 *       cmsis_compiler.h from CMSIS as that would contain several specific
 *       references to target specific toolchain files that the unity test
 *       does not replicate easily when building on the host
 */
#ifndef CMSIS_COMPILER_H
#define CMSIS_COMPILER_H

#define __PACKED __attribute__((packed))
#define __USED __attribute__((used))

#endif /* CMSIS_COMPILER_H */
