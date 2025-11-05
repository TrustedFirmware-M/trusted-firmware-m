/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 */

#ifndef __SCMI_PROTOCOL_H__
#define __SCMI_PROTOCOL_H__

#include <stdint.h>

/**
 * SCMI status definitions
 */
#define SCMI_STATUS_SUCCESS            INT32_C(0)
#define SCMI_STATUS_NOT_SUPPORTED      INT32_C(-1)
#define SCMI_STATUS_INVALID_PARAMETERS INT32_C(-2)
#define SCMI_STATUS_DENIED             INT32_C(-3)
#define SCMI_STATUS_NOT_FOUND          INT32_C(-4)
#define SCMI_STATUS_OUT_OF_RANGE       INT32_C(-5)
#define SCMI_STATUS_BUSY               INT32_C(-6)
#define SCMI_STATUS_COMMS_ERROR        INT32_C(-7)
#define SCMI_STATUS_GENERIC_ERROR      INT32_C(-8)
#define SCMI_STATUS_HARDWARE_ERROR     INT32_C(-9)
#define SCMI_STATUS_PROTOCOL_ERROR     INT32_C(-10)


#endif /* __SCMI_PROTOCOL_H__ */
