#!/usr/bin/env python3
#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

import argparse
import sys
import os

import arg_utils

import logging
logger = logging.getLogger("TF-M.{}".format(__name__))

sys.path.append(os.path.join(sys.path[0], 'modules'))

import otp_config as oc
from otp_config import OTP_config

import provisioning_message_config as pmc
from provisioning_message_config import Provisioning_message_config

import provisioning_config as pc
from provisioning_config import Provisioning_config


def add_arguments(parser : argparse.ArgumentParser,
                  prefix : str = "",
                  required : bool = True,
                  ) -> None:
    pmc.add_arguments(parser, prefix, required,
                      message_type="RSE_PROVISIONING_MESSAGE_TYPE_BLOB")

    arg_utils.add_prefixed_argument(parser, "provisioning_code_elf", prefix, help="provisioning code image elf file",
                                            type=arg_utils.arg_type_elf_section(["CODE", "DATA"]), required=True)

def parse_args(args : argparse.Namespace,
               prefix : str = "",
               default_field_owner : str = "dm"
               ) -> dict:
    out = {}
    out |= dict(zip(["code", "data"], arg_utils.get_arg(args, "provisioning_code_elf", prefix)))

    out |= pmc.parse_args(args, prefix=prefix)

    return out


script_description = """
This script takes as various config files, and produces from them and input
arguments corresponding to the fields of the DM provisioning bundle, and
produces a signed DM provisioning bundle which can be input into the RSE for
provisioning DM data
"""
if __name__ == "__main__":
    from provisioning_message_config import create_blob_message

    parser = argparse.ArgumentParser(allow_abbrev=False,
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter,
                                     description=script_description)

    add_arguments(parser)

    parser.add_argument("--bundle_output_file",    help="bundle output file", required=True)
    parser.add_argument("--log_level", help="log level", required=False, default="ERROR", choices=logging._levelToName.values())

    args = parser.parse_args()
    logger.setLevel(args.log_level)
    logger.addHandler(logging.StreamHandler())

    kwargs = parse_args(args)

    blob_type = kwargs['provisioning_message_config'].RSE_PROVISIONING_BLOB_TYPE_SINGLE_LCS_PROVISIONING

    with open(args.bundle_output_file, "wb") as f:
        message = create_blob_message(blob_type=blob_type, **kwargs)
        f.write(message)
