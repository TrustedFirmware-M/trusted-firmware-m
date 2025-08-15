#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import sys

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

import rse.provisioning_message_config as pmc
from rse.provisioning_message_config import Provisioning_message_config
from tfm_tools import arg_utils
import argparse

script_description = """
Create a blob message
"""
def main():
    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())
    arg_utils.add_prefixed_argument(parser, "provisioning_code_elf", "", help="provisioning code image elf file",
                                            type=arg_utils.arg_type_elf_section(["CODE", "DATA"]), required=True)
    pmc.add_arguments(parser, "", required=True, message_type="RSE_PROVISIONING_MESSAGE_TYPE_BLOB")
    parser.add_argument("--output_file", help="file to output to", type=arg_utils.arg_type_bytes_output_file, required=True)

    args = parser.parse_args()
    logging.basicConfig(level=args.log_level)

    kwargs = pmc.parse_args(args, prefix="")
    kwargs |= dict(zip(["code", "data"], arg_utils.get_arg(args, "provisioning_code_elf", "")))

    out = pmc.create_blob_message(**kwargs)
    args.output_file.write(out)

if __name__ == "__main__":
    sys.exit(main())
