#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

import os
import sys
sys.path.append(os.path.join(sys.path[0], 'modules'))

import provisioning_message_config as pmc
from provisioning_message_config import Provisioning_message_config
import argparse
import arg_utils

script_description = """
Create a plain data message
"""
if __name__ == "__main__":
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())
    arg_utils.add_prefixed_argument(parser, "data", "", help="data payload for message",
                                            type=arg_utils.arg_type_bytes, required=True)
    pmc.add_arguments(parser, "", required=True, message_type="RSE_PROVISIONING_MESSAGE_TYPE_PLAIN_DATA")
    parser.add_argument("--output_file", help="file to output to", type=arg_utils.arg_type_bytes_output_file, required=True)

    args = parser.parse_args()
    logging.basicConfig(level=args.log_level)

    kwargs = pmc.parse_args(args, prefix="")

    out = pmc.create_plain_data_message(**kwargs, data=args.data)
    args.output_file.write(out)
