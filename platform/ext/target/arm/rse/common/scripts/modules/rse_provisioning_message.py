#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
from c_struct import C_enum
from secrets import token_bytes

import sign_then_encrypt_data

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

from provisioning_message_config import Provisioning_message_config

